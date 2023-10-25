#include <ros/ros.h>
#include "../include/kalman_filter.h"
#include "../include/sonar_processing.h"
#include <sensor_msgs/Imu.h>
#include <sonar/Sonar.h>
#include <sonar/TwoSonarDepth.h>
#include<sensor_msgs/NavSatFix.h>
#include <sensor_msgs/NavSatStatus.h>
//#include <nlink_parser/TofsenseFrame0.h>
#include <eigen3/Eigen/Dense>
#include <string>
#include <geometry_msgs/PoseStamped.h>
#include <experimental/filesystem>
#include <mutex>
#include <fstream>

    std::ofstream myfile;
        std::mutex mtx;

        std::string csv_create_file(std::string path_param) 
        {
            //check for file name to use
                // Get the current time
    ros::Time current_time = ros::Time::now();

    // Extract the date and time components from the current time
    int year = current_time.toBoost().date().year();
    int month = current_time.toBoost().date().month();
    int day = current_time.toBoost().date().day();
    int hour = current_time.toBoost().time_of_day().hours();
    int minute = current_time.toBoost().time_of_day().minutes();
    int second = current_time.toBoost().time_of_day().seconds();

    // Format the date and time components as a string
    std::stringstream filename_stream;
    filename_stream << std::setw(4) << std::setfill('0') << year
                    << std::setw(2) << std::setfill('0') << month
                    << std::setw(2) << std::setfill('0') << day
                    << std::setw(2) << std::setfill('0') << hour
                    << std::setw(2) << std::setfill('0') << minute
                    << std::setw(2) << std::setfill('0') << second;
    std::string filename = filename_stream.str();
            std::string file_path = path_param;
            std::string file_format = ".csv";
            //while(true)
            ///{
              //  if (std::experimental::filesystem::exists(file_path + std::to_string(n) + file_format) == false)
                //{
                  //  file_path = file_path + std::to_string(n) + file_format;
                    //break;
                //}
               // n += 1;
            //}
            file_path = file_path + filename + file_format;
            return file_path;
        }

        void csv_writer(const std::string &data) 
        {
            // thread lock to avoid two callbacks from accessing file at the same time
            mtx.lock();
            myfile << data;
            mtx.unlock();
        }

class DiscreteKalmanFilter:public KalmanFilter
{
    public:

        DiscreteKalmanFilter():KalmanFilter()
        {
            this->pub = nh_.advertise<geometry_msgs::PoseStamped>("/pose",1);
            //this->ground_truth = nh_.advertise<geometry_msgs::PoseStamped>("/ground_truth",1);

            //To change to advanced navigation spatial imu  

            imu_sub = nh_.subscribe("/camera/accel/sample",1,&DiscreteKalmanFilter::imu_callback,this);
            sonar_sub = nh_.subscribe("/sonar",1,&DiscreteKalmanFilter::sonar_callback,this);
            //gps_sub=nh_.subscribe("/an_device/NavSatFix",1,&DiscreteKalmanFilter::gps_callback,this);
            //tof_sub = nh_.subscribe("/nlink_tofsense_frame0",1,&DiscreteKalmanFilter::tof_callback,this);
            SonarProcess sonar_filter(3);
        };

        void imu_callback(const sensor_msgs::ImuConstPtr& msg)
        {
            ros::Time time = ros::Time::now();
            float accel = msg->linear_acceleration.x;
            if(start == true)
            {
                if(previous_accel == 0)
                {
                    this->previous_state_time = time.toSec();
                    this->previous_accel = accel;
                }
                else
                {
                    //Check time assignment
                    float dt = time.toSec() - previous_state_time;
                    float u = previous_accel;
                    this->prediction(u,dt);
                    this->previous_accel = accel;
                    this->previous_state_time = time.toSec();
                }
            }

            // std::stringstream to preserve full precision of sensor measurements
    //ros::Time time = ros::Time::now();
    std::stringstream ss1;
    std::stringstream ss2;
    ss2.precision(15);
    ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
    ss2 << msg->linear_acceleration.x;

    ROS_INFO("linear_x: %f",msg->linear_acceleration.x);
    
    csv_writer(ss1.str()+ ",imu,,,,"+ ss2.str()+"\n");
           
        }

        void gps_callback(const sensor_msgs::NavSatFixConstPtr& msg)
        {
           // if(msg->status!=sensor_msgs::NavSatStatus::STATUS_NO_FIX)
           // {
                ros::Time time = ros::Time::now();
                int gps_status = static_cast<int>(msg->status.status);
            std::stringstream ss1;
            std::stringstream ss2;
            std::stringstream ss3;
            std::stringstream ss4;
            ss2.precision(15);
            ss3.precision(15);
            ss2<<msg->longitude;
            ss3<<msg->latitude;
            ss4<<gps_status;
            ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
            ROS_INFO("gps_long: %f",msg->longitude);
            ROS_INFO("gps_lat: %f",msg->latitude);
            ROS_INFO("GPS status %d",gps_status);
            csv_writer(ss1.str()+ ",gps,,,,,"+ ss2.str()+","+ss3.str()+","+ss4.str()+"\n");
            //}
            //else
            //{
              //  ROS_INFO("No gps fix");
            //}
            //To check if the IMU directly filters GPS fix readings
           
        }

        void sonar_callback(const sonar::SonarConstPtr& msg)  //Can substitute with Measurement Callback
        {
            ros::Time time = ros::Time::now();
            float distance = sonar_filter.MovingAvg(msg->distance);
            if(start == false && msg->confidence == 100.0)
            {
                this->first_sonar_distance = distance;
                this->previous_sonar_distance = 0;
                //Check time assignment
                this->previous_sonar_time = time.toSec();
                this->start = true;
            }
            else
            {
                float z = first_sonar_distance - distance;
                float v_x = (z-previous_sonar_distance)/(time.toSec()-previous_sonar_time);
                Eigen::Vector2f measurement (z,v_x);
                Eigen::Vector2f y = this->residual(measurement);
                if(v_x>-0.01 && v_x < 0.1)
                {
                    if(y(0,0) < 0.5)
                    {
                        this->R << 0.01,0,0,0.01;
                        this->update(measurement);
                    }
                    else
                    {
                        this->R << 10,0,0,0.01;
                        measurement(0,0) = this->x(0,0);
                        this->update(measurement);
                    }
                }
                this->update(measurement);
                this->previous_sonar_distance = z;
                this->previous_sonar_time = time.toSec();

                ROS_INFO("KF pose: %f",this->x(0,0));
                //ROS_INFO("RMS Error: %f",this->ground_truth_pose-this->x(0,0));
                geometry_msgs::PoseStamped pose_msg;
                pose_msg.header.frame_id = "odom";
                pose_msg.header.stamp = ros::Time::now();
                pose_msg.pose.position.x = this->x(0,0);
                pub.publish(pose_msg);
            }

                //ros::Time time = ros::Time::now();
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;
    std::stringstream ss4;
    ss2.precision(15);
    ss3.precision(15);
    ss4.precision(15);
    ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
    ss2<<this->x(0,0);
    ss3 << msg->distance;
    ss4 << msg->confidence;
    ROS_INFO("sonar_distance: %f",msg->distance);
    ROS_INFO("confidence: %f",msg->confidence);
    //ROS_INFO("sonar_time: %s",ss0.str().c_str());
    //ROS_INFO("tof_tim: %s",ss6.str().c_str());
    csv_writer(ss1.str()+","+"sonar" + ","+ss2.str()+"," + ss3.str()+"," + ss4.str()+"\n");
            
        }
   
        
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub;
        ros::Publisher ground_truth;
        ros::Subscriber imu_sub,sonar_sub,gps_sub;
        SonarProcess sonar_filter = SonarProcess(3);
        double first_sonar_distance=0, previous_sonar_distance=0, previous_sonar_time=0, previous_state_time=0, previous_accel=0, ground_truth_pose=0;
        bool start = false;
};

int main(int argc,char* argv[])
{
    ros::init(argc,argv,"kalman_filter");
    ros::NodeHandle nodeHandle;
    std::string path_param;
    if(ros::param::get("~csv_path",path_param))
    {
        std::string file_path = csv_create_file(path_param);
        myfile.open(file_path);
        myfile << "time,sensor,KF_pose,sonar_distance,sonar_confidence,accel x,gps_long,gps_lat,gps_status\n";
        //ros::Subscriber imu_sub = nodeHandle.subscribe("/an_device/Imu",1,imu_callback);
	//ros::Subscriber sonar_sub = nodeHandle.subscribe("/sonar",1,sonar_callback);

     
    DiscreteKalmanFilter dkf; //To try using one filter per DOF
    ros::spin();
    }
    else
    {
        ROS_INFO("No csv path param!");
    }
 
    return 0; 
}