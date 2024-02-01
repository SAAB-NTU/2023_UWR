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

#include<geometry_msgs/Vector3Stamped.h>

#include <eigen3/Eigen/Dense>
#include <string>
#include <geometry_msgs/PoseStamped.h>
#include<fstream>
#include <rosbag/bag.h>

#include "Iir.h" //NEW






	// Butterworth lowpass




        std::string bag_create_file(std::string path_param,ros::Time current_time) 
        {
            //check for file name to use
                // Get the current time
    

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


class DiscreteKalmanFilter:public KalmanFilter_6dof_FLS
{
    //variables
    private: 
        //Ros variables 
        ros::NodeHandle nh_; //Node handle

        ros::Publisher pub; //Publisher
        ros::Publisher ground_truth; //Publisher
        ros::Time current_time = ros::Time::now();
        double bias_x,bias_y,bias_z;

        ros::Subscriber imu_sub,sonar_sub,gps_sub,FLS_sub; //subscribers

        //Sonar pre-filter (Moving average)
        SonarProcess sonar_filter_x = SonarProcess(3),sonar_filter_y = SonarProcess(3),sonar_filter_z = SonarProcess(3);

        //IMU pre-filter (band-pass butterworth filter)
        const float samplingrate = 1000;
        const double cutoff_frequency=100;
        const int order = 4;
        Iir::Butterworth::LowPass<4> bw_filter1,bw_filter2,bw_filter3;

        //Initial times
        double previous_sonar_time=0, previous_state_time=0,previous_FLS_time=0;
        
        //Initial sonar distances
        double first_sonar_distance_x=0,first_sonar_distance_y=0,first_depth_distance_z=0;

        //Iterative sonar distances
        double previous_sonar_distance_x=0,previous_sonar_distance_y=0,previous_depth_distance_z=0;
        
        double first_FLS_distance_x=0,first_FLS_distance_z=0;

        //Iterative sonar distances
        double previous_FLS_distance_x=0,previous_FLS_distance_z=0;
        
        double previous_accel_x=0,previous_accel_y=0,previous_accel_z=0; 
        
        //To start filtering
        bool start = false,bias_taken=false;
   
        rosbag::Bag bag;
        
    
   
    public:

        //Constructor (to be used to subscribe or publish)

        DiscreteKalmanFilter():KalmanFilter_6dof_FLS()
        {
            
            //IMU messages (accelerometer)
            imu_sub = nh_.subscribe("/IMU_raw",10,&DiscreteKalmanFilter::imu_callback,this);
            
            //Sonar messages as one topic
            sonar_sub = nh_.subscribe("/SONAR_raw",1,&DiscreteKalmanFilter::sonar_callback,this);

            FLS_sub = nh_.subscribe("/FLS_data",1,&DiscreteKalmanFilter::FLS_callback,this);
            
            //Multiple single Sonar topics
            //sonar_sub = nh_.subscribe("/sonar",1,&DiscreteKalmanFilter::sonar_callback,this);
            
            //If using GPS receiver for ground-truth

            //gps_sub=nh_.subscribe("/an_device/NavSatFix",1,&DiscreteKalmanFilter::gps_callback,this);
            //this->pub = nh_.advertise<geometry_msgs::PoseStamped>("/pose",1);
            //this->ground_truth = nh_.advertise<geometry_msgs::PoseStamped>("/ground_truth",1);
            ROS_INFO("Initialization done, waiting to subscribe to topics");

            //Initializing filters

            SonarProcess sonar_filter1(3),sonar_filter2(3),sonar_filter3(3); 
            
	        bw_filter1.setup(samplingrate, cutoff_frequency);
            bw_filter2.setup(samplingrate, cutoff_frequency);
            bw_filter3.setup(samplingrate, cutoff_frequency);
            std::string path_param;
            ros::param::get("~csv_path",path_param);
            //Create bag
            bag.open(bag_create_file(path_param,current_time), rosbag::bagmode::Write);
        };

        void imu_callback(const sensor_msgs::ImuConstPtr& imu_msg)
        {
            ros::Time time = ros::Time::now();
            try
            {
                if(bias_taken==false)
                {
                bias_x = imu_msg->linear_acceleration.x;
                bias_y = imu_msg->linear_acceleration.y;
                bias_z = imu_msg->linear_acceleration.z;
                bias_taken=true;
                }
	           //Raw data
                
                float accel_x = imu_msg->linear_acceleration.x-bias_x;
                float accel_y = imu_msg->linear_acceleration.y-bias_y;
                float accel_z = imu_msg->linear_acceleration.z-bias_z;
                
                //filter accleration data in 3 directions
                float filtered_accel_x = bw_filter1.filter(accel_x); //NEW
                float filtered_accel_y = bw_filter2.filter(accel_y); //NEW
                float filtered_accel_z = bw_filter3.filter(accel_z); //NEW
                
             
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

                        geometry_msgs::Vector3Stamped vector3_msg,pose_msg;
                                                // Calculate the time difference in seconds
                  

                        vector3_msg.header.stamp=imu_msg->header.stamp;

                        vector3_msg.vector.x = filtered_accel_x;
                        vector3_msg.vector.y = filtered_accel_y;
                        vector3_msg.vector.z = filtered_accel_z;
                        

                        pose_msg.header.stamp=imu_msg->header.stamp;
                        
                        pose_msg.vector.x = this->x(0);
                        pose_msg.vector.y = this->x(2);
                        pose_msg.vector.z = this->x(4);

                        bag.write("IMU_raw",time,imu_msg);
                        bag.write("IMU_filtered",time,vector3_msg);
                        bag.write("Pose",time,pose_msg);

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
                /*
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
                */
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
        void FLS_callback(const sonar::ThreeSonarDepthConstPtr& msg)  //Can substitute with Measurement Callback
        {
            try
            {
            ros::Time time = ros::Time::now();
            float distance_x = (msg->distance_1);
            //Based on IMU position
            float distance_y = 0;
            float distance_z = (msg->distance_2);

            if(start == false) //Setting initial distance values
            {   
                
                    this->first_FLS_distance_x = distance_x;
                    this->previous_FLS_distance_x = 0;
              
                this->first_FLS_distance_z = distance_z;
                this->previous_FLS_distance_z = 0;
                //}

                
                //Check time assignment
                this->previous_FLS_time = time.toSec();
                this->start = true;
                ROS_INFO("Entered FLS_callback initially");
            }
            else
            {
                float measurement_x = (distance_x)*0.75/first_FLS_distance_x;
                            
                
                float measurement_z = (distance_z)*1/first_FLS_distance_z;

                R2(0,0)=msg->confidence_1;
                R2(4,4)=msg->confidence_2;
                
                
                ROS_INFO("first measurements");
                Eigen::Matrix<double,6,1> measurement_residual; // Assuming you want a 6-dimensional vector

                measurement_residual << measurement_x, 0, 0,0, measurement_z,0;

                Eigen::Matrix<double,6,1> measurement_final = this->residual(measurement_residual,this->H2);
                ROS_INFO("matrix initialization");

                
     
                this->update(measurement_residual,this->H2,this->R2);
                this->previous_FLS_distance_x = measurement_x;
                this->previous_FLS_distance_z = measurement_z;
                this->previous_FLS_time = time.toSec();
                ROS_INFO("KF pose: %f",this->x(0));

                geometry_msgs::Vector3Stamped pose_msg;
                
        

                pose_msg.header.stamp=msg->header.stamp;
                pose_msg.vector.x = this->x(0);
                pose_msg.vector.y = this->x(2);
                pose_msg.vector.z = this->x(4);
                
               pub.publish(pose_msg);
                
                geometry_msgs::Vector3Stamped vector3_msg;
                vector3_msg.header.stamp=msg->header.stamp;
                vector3_msg.vector.x =distance_x;
                vector3_msg.vector.y = distance_y;
                vector3_msg.vector.z = distance_z;
                

                bag.write("FLS_raw",time,msg);
                bag.write("FLS_filtered",time,vector3_msg);
                bag.write("Pose",time,pose_msg);

                            //ros::Time time = ros::Time::now();
            

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
        void sonar_callback(const sonar::ThreeSonarDepthConstPtr& msg)  //Can substitute with Measurement Callback
        {
            try
            {
            ros::Time time = ros::Time::now();
            float distance_x = sonar_filter_x.MovingAvg(msg->distance_1/1000);
            //Based on IMU position
            float distance_y = sonar_filter_y.MovingAvg(msg->depth);
            float distance_z = sonar_filter_z.MovingAvg(msg->distance_2/1000);

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

                Eigen::Matrix<double,6,1> measurement_final = this->residual(measurement_residual,this->H1);
                ROS_INFO("matrix initialization");

                
                if(v_x>-1 && v_x < 1) //x-axis
                {
                    if(measurement_final(0) < 0.5)
                    {  
                        ROS_INFO("condtn1");
                        this->R1(0,0)=0.001;//Distance is more accurate than velocity
                        this->R1(1,1)=0.01;
                        
                    }
                    else
                    {
                        ROS_INFO("condtn2");
                        this->R1(0,0)=10;//Distance is more accurate than velocity
                        this->R1(1,1)=20;
                        measurement_final(0) = this->x(0);  //KF distance taken if too inaccurate
                        
                    }
                }
                if(v_y>-1 && v_y < 1) //y-axis
                {
                    if(measurement_final(2) < 0.5)
                    {
                        this->R1(2,2)=0.001;//Distance is more accurate than velocity
                        this->R1(3,3)=0.01;
                        
                    }
                    else
                    {
                        this->R1(2,2)=10;//Distance is more accurate than velocity
                        this->R1(3,3)=20;
                       // measurement_final(2) = this->x(2);  //KF distance taken if too inaccurate
                    }
                }
                 if(v_z>-1 && v_z < 1) //z-axis
                {
                    if(measurement_final(4) < 0.5)
                    {
                        this->R1(4,4)=0.001;//Distance is more accurate than velocity
                        this->R1(5,5)=0.01;
                    }
                    else
                    {
                        this->R1(4,4)=10;//Distance is more accurate than velocity
                        this->R1(5,5)=20;
                        //measurement_final(4) = this->x(4);  //KF distance taken if too inaccurate
                    }
                }
                ROS_INFO("here");
     
                this->update(measurement_residual,this->H1,this->R1);
                this->previous_sonar_distance_x = measurement_x;
                this->previous_sonar_distance_y = measurement_y;
                this->previous_depth_distance_z = measurement_z;
                this->previous_sonar_time = time.toSec();
                ROS_INFO("KF pose: %f",this->x(0));

                geometry_msgs::Vector3Stamped pose_msg;
                
        

                pose_msg.header.stamp=msg->header.stamp;
                pose_msg.vector.x = this->x(0);
                pose_msg.vector.y = this->x(2);
                pose_msg.vector.z = this->x(4);
                
               pub.publish(pose_msg);
                
                geometry_msgs::Vector3Stamped vector3_msg;
                vector3_msg.header.stamp=msg->header.stamp;
                vector3_msg.vector.x =distance_x;
                vector3_msg.vector.y = distance_y;
                vector3_msg.vector.z = distance_z;
                

                bag.write("SONAR_raw",time,msg);
                bag.write("SONAR_filtered",time,vector3_msg);
                bag.write("Pose",time,pose_msg);

                            //ros::Time time = ros::Time::now();
            

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
    	

    ros::init(argc,argv,"kf_v2_FLS");
    ros::NodeHandle nodeHandle;

        //ros::Subscriber imu_sub = nodeHandle.subscribe("/an_device/Imu",1,imu_callback);
	//ros::Subscriber sonar_sub = nodeHandle.subscribe("/sonar",1,sonar_callback);

     
    DiscreteKalmanFilter dkf; //To try using one filter per DOF
    ros::spin();

 
    return 0; 
}
