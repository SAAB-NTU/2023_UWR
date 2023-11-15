#include <ros/ros.h>
#include "../include/kalman_filter.h"
#include "../include/sonar_processing.h"
#include <sensor_msgs/Imu.h>
#include <sonar/Sonar.h>
//Include three SONAR depth header file
#include <sonar/ThreeSonarDepth.h>
#include<sensor_msgs/NavSatFix.h>
#include <sensor_msgs/NavSatStatus.h>

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
    filename_stream << std::setw(4) << std::setfill('0') << year<<"_"
                    << std::setw(2) << std::setfill('0') << month<<"_"
                    << std::setw(2) << std::setfill('0') << day<<"_"
                    << std::setw(2) << std::setfill('0') << hour<<"_"
                    << std::setw(2) << std::setfill('0') << minute<<"_"
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

class DiscreteKalmanFilter:public KalmanFilter_6dof
{
    public:

        DiscreteKalmanFilter():KalmanFilter_6dof()
        {
            
            this->pub = nh_.advertise<geometry_msgs::PoseStamped>("/pose",1);
            //this->ground_truth = nh_.advertise<geometry_msgs::PoseStamped>("/ground_truth",1);

            //To change to advanced navigation spatial imu  

            imu_sub = nh_.subscribe("/imu/data",1,&DiscreteKalmanFilter::imu_callback,this);
            
            //Included Sonar depth message
            sonar_sub = nh_.subscribe("/ThreeSonarDepth",1,&DiscreteKalmanFilter::sonar_callback,this);
            
            //sonar_sub = nh_.subscribe("/sonar",1,&DiscreteKalmanFilter::sonar_callback,this);
            
            
            //gps_sub=nh_.subscribe("/an_device/NavSatFix",1,&DiscreteKalmanFilter::gps_callback,this);
            
            SonarProcess sonar_filter(3); 
            ROS_INFO("Initialization done, waiting to subscribe to topics");
        };

        void imu_callback(const sensor_msgs::ImuConstPtr& msg)
        {
            ros::Time time = ros::Time::now();
            try
            {
                
                float accel_x = msg->linear_acceleration.x;
                
                //Included y and z acceleration 
                float accel_y = msg->linear_acceleration.y;
                float accel_z = msg->linear_acceleration.z;
                //start=true;
                if(start == true)
                {
                    
                    if(previous_state_time > 0)
                    {
                        //Check time assignment
                        float dt = time.toSec() - previous_state_time;
                        //Added y and z acceleration
                        float u_x = previous_accel_x,u_y = previous_accel_y,u_z = previous_accel_z;
                        Eigen::Matrix<double,3,1> u_final;
                        u_final<<u_x,u_y,u_z;
                        this->prediction(u_final,dt);
                        ROS_INFO("linear_x_a: %f",this->x(0));
                        ROS_INFO("linear_y_a: %f",this->x(2));
                        ROS_INFO("linear_z_a: %f",this->x(4));
                            std::ostringstream stream;
                            stream << this->K;

    // Get the string representation of the Eigen matrix
                    std::string eigenMatrixString = stream.str();

    // Print the string with ROS_INFO
                 ROS_INFO("Eigen Matrix:\n%s", eigenMatrixString.c_str());

                    }
                    	 this->previous_state_time = time.toSec();
                        this->previous_accel_x = accel_x;
                        this->previous_accel_y = accel_y;
                        this->previous_accel_z = accel_z;
                	}
            }
            catch (const std::exception& e)
            {
                ROS_ERROR("error in imu-callback: %s", e.what());
            }


            // std::stringstream to preserve full precision of sensor measurements
    //ros::Time time = ros::Time::now();
    std::stringstream ss1;
    std::stringstream ss2;
    ss2.precision(15);
    ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
    ss2 << msg->linear_acceleration.x<<","<<msg->linear_acceleration.y<<","<<msg->linear_acceleration.z;

    //ROS_INFO("linear_x: %f",msg->linear_acceleration.x);
   // ROS_INFO("linear_y: %f",msg->linear_acceleration.y);
    //ROS_INFO("linear_z: %f",msg->linear_acceleration.z);
    csv_writer(ss1.str()+ ",imu,,,,"+ ss2.str()+"\n");
           
        }

        void gps_callback(const sensor_msgs::NavSatFixConstPtr& msg)
        {
            try
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
            catch (const std::exception& e)
            {
                ROS_ERROR("error in GPS-callback: %s", e.what());
            }
        }

        void sonar_callback(const sonar::ThreeSonarDepthConstPtr& msg)  //Can substitute with Measurement Callback
        {
            try
            {
            ros::Time time = ros::Time::now();
            float distance_x = sonar_filter.MovingAvg(msg->distance_1);
            //To improve sway precision with two SONARs
            float distance_y = sonar_filter.MovingAvg(msg->distance_2);
            float distance_z = sonar_filter.MovingAvg(msg->depth);
            if(start == false && msg->confidence_1 == 100.0&& msg->confidence_2 == 100.0&& msg->confidence_3 == 100.0)
            {
                this->first_sonar_distance_x = distance_x;
                this->previous_sonar_distance_x = 0;
                this->first_sonar_distance_y = distance_y;
                this->previous_sonar_distance_y = 0;
                this->first_depth_distance_z = distance_z;
                this->previous_depth_distance_z = 0;
                //Check time assignment
                this->previous_sonar_time = time.toSec();
                this->start = true;
                ROS_INFO("Entered Sonar_callback initially");
            }
            else
            {
                float measurement_x = first_sonar_distance_x - distance_x;
                float v_x = (measurement_x-previous_sonar_distance_x)/(time.toSec()-previous_sonar_time);
                
                
                float measurement_y = first_sonar_distance_y - distance_y;
                float v_y = (measurement_y-previous_sonar_distance_y)/(time.toSec()-previous_sonar_time);
                
                float measurement_z = first_depth_distance_z - distance_z;
                float v_z = (measurement_z-previous_depth_distance_z)/(time.toSec()-previous_sonar_time);
                
                ROS_INFO("first measurements");
                Eigen::Matrix<double,6,1> measurement_residual; // Assuming you want a 6-dimensional vector

                measurement_residual << measurement_x, v_x, measurement_y, v_y, measurement_z, v_z;

                Eigen::Matrix<double,6,1> measurement_final = this->residual(measurement_residual);
                ROS_INFO("matrix initialization");

                
                if(v_x>-1 && v_x < 1) //x-axis
                {
                    if(measurement_final(0) < 0.5)
                    {  
                        ROS_INFO("condtn1");
                        this->R(0,0)=0.001;//Distance is more accurate than velocity
                        this->R(1,1)=0.01;
                        
                    }
                    else
                    {
                        ROS_INFO("condtn2");
                        this->R(0,0)=10;//Distance is more accurate than velocity
                        this->R(1,1)=20;
                        measurement_final(0) = this->x(0);  //KF distance taken if too inaccurate
                        
                    }
                }
                if(v_y>-1 && v_y < 1) //y-axis
                {
                    if(measurement_final(2) < 0.5)
                    {
                        this->R(2,2)=0.001;//Distance is more accurate than velocity
                        this->R(3,3)=0.01;
                        
                    }
                    else
                    {
                        this->R(2,2)=20;//Distance is more accurate than velocity
                        this->R(3,3)=10;
                        measurement_final(2) = this->x(2);  //KF distance taken if too inaccurate
                    }
                }
                 if(v_z>-1 && v_z < 1) //z-axis
                {
                    if(measurement_final(5) < 0.5)
                    {
                        this->R(4,4)=0.001;//Distance is more accurate than velocity
                        this->R(5,5)=0.01;
                    }
                    else
                    {
                        this->R(5,5)=20;//Distance is more accurate than velocity
                        this->R(5,5)=10;
                        measurement_final(4) = this->x(4);  //KF distance taken if too inaccurate
                    }
                }
                ROS_INFO("here");
     
                this->update(measurement_residual);
                this->previous_sonar_distance_x = measurement_x;
                this->previous_sonar_distance_y = measurement_y;
                this->previous_depth_distance_z = measurement_z;
                this->previous_sonar_time = time.toSec();
                ROS_INFO("KF pose: %f",this->x(0));

                geometry_msgs::PoseStamped pose_msg;
                pose_msg.header.frame_id = "odom";
                pose_msg.header.stamp = ros::Time::now();
                pose_msg.pose.position.x = this->x(0);
                pose_msg.pose.position.y = this->x(2);
                pose_msg.pose.position.z = this->x(4);
               pub.publish(pose_msg);

                            //ros::Time time = ros::Time::now();
            std::stringstream ss_time;
            
            ss_time << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
            
            std::stringstream ss_x_KF;
            std::stringstream ss_x_dist;
            std::stringstream ss_x_conf;

            std::stringstream ss_y_KF;
            std::stringstream ss_y_dist;
            std::stringstream ss_y_conf;
            
            std::stringstream depth_z_KF;
            std::stringstream depth_z_dist;
            
            ss_x_KF.precision(15);
            ss_x_dist.precision(15);
            ss_x_conf.precision(15);
            
            
            ss_y_KF.precision(15);
            ss_y_dist.precision(15);
            ss_y_conf.precision(15);
            
            depth_z_KF.precision(15);
            depth_z_dist.precision(15);
            ss_x_KF<<this->x(0);
            ss_x_dist << msg->distance_1;
            ss_x_conf << msg->confidence_1;
            
            
            //TO put average distance to improve Sway
            ss_y_KF<<this->x(2);
            ss_y_dist << msg->distance_2;
            ss_y_conf << msg->confidence_2;
            
            depth_z_KF<<this->x(4);
            depth_z_dist << msg->depth;
            
   
            //ROS_INFO("sonar_time: %s",ss0.str().c_str());
            //ROS_INFO("tof_tim: %s",ss6.str().c_str());
            csv_writer(ss_time.str()+","+"sonar_depth" + ","+ss_x_KF.str()+"," + ss_y_KF.str()+"," + depth_z_KF.str()+ ","+ss_x_dist.str()+"," + ss_y_dist.str()+"," + depth_z_dist.str()+"," + ss_x_conf.str()+"," + ss_y_conf.str()+"\n");
            
            ss_time << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;

               /*
                
                //ROS_INFO("RMS Error: %f",this->ground_truth_pose-this->x(0,0));

            
            
            */
            }


            }
            catch (const std::exception& e)
            {
                ROS_ERROR("error in sonar-callback: %s", e.what());
            }

        }
  
        
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub;
        ros::Publisher ground_truth;
        ros::Subscriber imu_sub,sonar_sub,gps_sub;
        SonarProcess sonar_filter = SonarProcess(3);
        double previous_sonar_time=0, previous_state_time=0;
        
        //Included initial sonar distances
        double first_sonar_distance_x=0,first_sonar_distance_y=0,first_depth_distance_z=0;
        double previous_sonar_distance_x=0,previous_sonar_distance_y=0,previous_depth_distance_z=0;
        //double first_sonar_distance=0, previous_sonar_distance=0; 
        double previous_accel_x=0,previous_accel_y=0,previous_accel_z=0; 
        //double ground_truth_pose=0;
        bool start = false;
};

int main(int argc,char* argv[])
{
    ros::init(argc,argv,"kalman_filter_6dof");
    ros::NodeHandle nodeHandle;
    std::string path_param;
    if(ros::param::get("~csv_path",path_param))
    {
        
        std::string file_path = csv_create_file(path_param);
        myfile.open(file_path);
        //myfile<<"Hello";
        myfile << "time,sensor,KF_pose_x,KF_pose_y,KF_pose_z,sonar_distance_x,sonar_distance_y,depth_z,sonar_confidence_x,sonar_confidence_y,accel_x,accel_y,accel_z,gps_long,gps_lat,gps_status\n";
        ROS_INFO("Got path");
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
