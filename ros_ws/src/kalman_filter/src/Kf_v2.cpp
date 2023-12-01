/*

Upgrades summary:

-> Using ros-bag instead of csv storage
-> Possible use of time-synchronizer message filter (at least to include imu gyro data)
-> Addition of accelerometer bias


*/


#include <ros/ros.h>
#include "../include/kalman_filter.h"
#include "../include/sonar_processing.h"
#include <sensor_msgs/Imu.h>
#include <sonar/Sonar.h>
//Include three SONAR depth header file
#include <sonar/ThreeSonarDepth.h>
#include<sensor_msgs/NavSatFix.h>
#include <sensor_msgs/NavSatStatus.h>

#include<geometry_msgs/Vector3.h>

#include <eigen3/Eigen/Dense>
#include <string>
#include <geometry_msgs/PoseStamped.h>
#include<fstream>
#include <rosbag/bag.h>

#include "Iir.h" //NEW






	// Butterworth lowpass




        std::string bag_create_file(std::string path_param) 
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
            std::string file_format = ".bag";
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


    // init filter NEW


class DiscreteKalmanFilter:public KalmanFilter_6dof
{
    //variables
    private: 
        //Ros variables 
        ros::NodeHandle nh_; //Node handle

        ros::Publisher pub; //Publisher
        ros::Publisher ground_truth; //Publisher

        ros::Subscriber imu_sub,sonar_sub,gps_sub; //subscribers

        //Sonar pre-filter (Moving average)
        SonarProcess sonar_filter = SonarProcess(3);

        //IMU pre-filter (band-pass butterworth filter)
        const float samplingrate = 1000;
        const double cutoff_frequency=100;
        const int order = 4;
        Iir::Butterworth::LowPass<4> bw_filter;

        //Initial times
        double previous_sonar_time=0, previous_state_time=0;
        
        //Initial sonar distances
        double first_sonar_distance_x=0,first_sonar_distance_y=0,first_depth_distance_z=0;

        //Iterative sonar distances
        double previous_sonar_distance_x=0,previous_sonar_distance_y=0,previous_depth_distance_z=0;
        
        double previous_accel_x=0,previous_accel_y=0,previous_accel_z=0; 
        
        //To start filtering
        bool start = false;
   
        rosbag::Bag bag;
        
    
   
    public:

        //Constructor (to be used to subscribe or publish)

        DiscreteKalmanFilter():KalmanFilter_6dof()
        {
            
            //IMU messages (accelerometer)
            imu_sub = nh_.subscribe("/imu/data",1,&DiscreteKalmanFilter::imu_callback,this);
            
            //Sonar messages as one topic
            sonar_sub = nh_.subscribe("/ThreeSonarDepth",1,&DiscreteKalmanFilter::sonar_callback,this);
            
            //Multiple single Sonar topics
            //sonar_sub = nh_.subscribe("/sonar",1,&DiscreteKalmanFilter::sonar_callback,this);
            
            //If using GPS receiver for ground-truth

            //gps_sub=nh_.subscribe("/an_device/NavSatFix",1,&DiscreteKalmanFilter::gps_callback,this);
            //this->pub = nh_.advertise<geometry_msgs::PoseStamped>("/pose",1);
            //this->ground_truth = nh_.advertise<geometry_msgs::PoseStamped>("/ground_truth",1);
            ROS_INFO("Initialization done, waiting to subscribe to topics");

            //Initializing filters

            SonarProcess sonar_filter(3); 
            
	        bw_filter.setup(samplingrate, cutoff_frequency);

            //Create bag
            bag.open(bag_create_file(), rosbag::bagmode::Write);
        };

        void imu_callback(const sensor_msgs::ImuConstPtr& msg)
        {
            ros::Time time = ros::Time::now();
            try
            {
                        
	           //Raw data
                
                float accel_x = msg->linear_acceleration.x;
                float accel_y = msg->linear_acceleration.y;
                float accel_z = msg->linear_acceleration.z;
                
                //filter accleration data in 3 directions
                float filtered_accel_x = bw_filter.filter(accel_x); //NEW
                float filtered_accel_y = bw_filter.filter(accel_y); //NEW
                float filtered_accel_z = bw_filter.filter(accel_z); //NEW
                
             
                if(start == true)
                {
                    
                    if(previous_state_time > 0)
                    {
                        //Check time assignment
                        float dt = time.toSec() - previous_state_time;


                        float u_x = filtered_accel_x; 
                        float u_y = filtered_accel_y; 
                        float u_z = filtered_accel_z; 

                        Eigen::Matrix<double,3,1> u_final;
                        u_final<<u_x,u_y,u_z;

                        this->prediction(u_final,dt); //prediction     --> X=F*X_1 + B*U, updates P matrix

                        //Debugging code
                        //ROS_INFO("linear_x_a: %f",this->x(0));
                        //ROS_INFO("linear_y_a: %f",this->x(2));
                        //ROS_INFO("linear_z_a: %f",this->x(4));

                        // Debugging to check Kalman gain value
                        //std::ostringstream stream;
                        //stream << this->K;
                        //std::string eigenMatrixString = stream.str();
                        //ROS_INFO("Eigen Matrix:\n%s", eigenMatrixString.c_str());



                    }
                    	this->previous_state_time = time.toSec();
                        this->previous_accel_x = filtered_accel_x; 
                        this->previous_accel_y = filtered_accel_y; 
                        this->previous_accel_z = filtered_accel_z; 

                        geometry_msgs::Vector3 vector3_msg;

                        vector3_msg.x = imu_msg->filtered_accel_x;
                        vector3_msg.y = imu_msg->filtered_accel_y;
                        vector3_msg.z = imu_msg->filtered_accel_z;

                        bag.write("IMU_raw",time,*msg);
                        bag.write("IMU_filtered",time,*vector3_msg);

                        //Put in predicted pose values
                	}

                    
            }
            catch (const std::exception& e)
            {
                ROS_ERROR("error in imu-callback: %s", e.what());
            }


            // std::stringstream to preserve full precision of sensor measurements
    //ros::Time time = ros::Time::now();
            
           
        }

        void gps_callback(const sensor_msgs::NavSatFixConstPtr& msg)  // To incorporate rosbag
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
            //Based on IMU position
            float distance_y = sonar_filter.MovingAvg(msg->depth);
            float distance_z = sonar_filter.MovingAvg(msg->distance_2);

            if(start == false) //Setting initial distance values
            {   
                if(msg->confidence_1 == 100.0)
                {
                    this->first_sonar_distance_x = distance_x;
                    this->previous_sonar_distance_x = 0;
                }
                //Depth sensor doesn't need this
                //if(msg->confidence_2 == 100.0) 
                //{
                this->first_sonar_distance_y = distance_y;
                this->previous_sonar_distance_y = 0;
                //}
                if(msg->confidence_3 == 100.0) 
                {
                this->first_depth_distance_z = distance_z;
                this->previous_depth_distance_z = 0;
                }
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
            
   	ss_time<< time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
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
       	// myfile<<"Hello";
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
