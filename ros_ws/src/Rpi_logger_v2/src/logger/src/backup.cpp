#include <ros/ros.h>
#include <string>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>
#include <sonar/TwoSonar.h>
#include <sensor_msgs/Imu.h>
//#include <nlink_parser/TofsenseFrame0.h>
#include <experimental/filesystem>
#include <mutex>
#include <fstream>
#include <tf/tf.h>

std::ofstream myfile;
std::mutex mtx;

std::string csv_create_file(std::string path_param) 
{
    //check for file name to use
    int n = 0;
    std::string file_path = path_param;
    std::string file_format = ".csv";
    while(true)
    {
        if (std::experimental::filesystem::exists(file_path + std::to_string(n) + file_format) == false)
        {
            file_path = file_path + std::to_string(n) + file_format;
            break;
        }
        n += 1;
    }
    return file_path;
}

void csv_writer(const std::string &data) 
{
    // thread lock to avoid two callbacks from accessing file at the same time
    mtx.lock();
    myfile << data;
    mtx.unlock();
}

void callback(const sonar::TwoSonarConstPtr& sonar, const nlink_parser::TofsenseFrame0ConstPtr &tof)
{
    // std::stringstream to preserve full precision of sensor measurements
    ros::Time time = ros::Time::now();
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;
    std::stringstream ss4;
    std::stringstream ss5;
    std::stringstream ss6;
    ss2.precision(15);
    ss3.precision(15);
    ss4.precision(15);
    ss5.precision(15);
    ss6.precision(15);
    ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
    ss2 << sonar->distance_1;
    ss3 << sonar->confidence_1;
    ss4 << sonar->distance_2;
    ss5 << sonar->confidence_2;
    ss6 << tof->dis;
    //ROS_INFO("sonar_distance: %f",sonar->distance_1);
    //ROS_INFO("confidence: %f",sonar->confidence_1);
    csv_writer(ss1.str()+","+"tof_sonar" + "," + ss6.str() + "," + ss2.str()+ "," + ss3.str()+"," + ss4.str()+ "," + ss5.str() + "\n");
}

void imu_callback(const sensor_msgs::ImuConstPtr &imu)
{
    // std::stringstream to preserve full precision of sensor measurements
    ros::Time time = ros::Time::now();
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;
    std::stringstream ss4;
    std::stringstream ss5;
    std::stringstream ss6;
    std::stringstream ss7;
    std::stringstream ss8;
    std::stringstream ss9;
    std::stringstream ss10;
    ss2.precision(15);
    ss3.precision(15);
    ss4.precision(15);
    ss5.precision(15);
    ss6.precision(15);
    ss7.precision(15);

    //orientation
    //ss8.precision(15);
    //ss9.precision(15);
    //ss10.precision(15);

    ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
    ss2 << imu->linear_acceleration.x;
    ss3 << imu->linear_acceleration.y;
    ss4 << imu->linear_acceleration.z;
    ss5 << imu->angular_velocity.x;
    ss6 << imu->angular_velocity.y;
    ss7 << imu->angular_velocity.z;

    //orientation
    /*
    tf::Quaternion q (imu->orientation.x,imu->orientation.y,imu->orientation.z,imu->orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    ss8 << roll;
    ss9 << pitch;
    ss10 << yaw;
    */

    /*
    ROS_INFO("linear_x: %f",imu->linear_acceleration.x);
    ROS_INFO("linear_y: %f",imu->linear_acceleration.y);
    ROS_INFO("linear_z: %f",imu->linear_acceleration.z);
    ROS_INFO("angular_x: %f",imu->angular_velocity.x);
    ROS_INFO("angular_y: %f",imu->angular_velocity.y);
    ROS_INFO("angular_z: %f",imu->angular_velocity.z);
    ROS_INFO("roll: %f",roll);
    ROS_INFO("pitch: %f",pitch);
    ROS_INFO("yaw: %f",yaw);
    */
    csv_writer(ss1.str()+ ",imu,,,,,,"+ ss2.str() + "," + ss3.str()+"," + ss4.str()+ ","+ ss5.str() + "," + ss6.str() + "," + ss7.str()+"\n");
}

int main(int argc, char* argv[])
{
    ros::init(argc,argv,"logger");
    ros::NodeHandle nodeHandle;
    std::string path_param;
    if(ros::param::get("~csv_path",path_param))
    {
        std::string file_path = csv_create_file(path_param);
        myfile.open(file_path);
        myfile << "time,sensor,tof_distance, sonar_distance_1,sonar_confidence_1,sonar_distance_2,sonar_confidence_2,accel x,accel y,accel z,angular_vel x,angular_vel y,angular_vel z\n";
        ros::Subscriber imu_sub = nodeHandle.subscribe("/imu/data_raw",1,imu_callback);

        // code below is to synchronize sonar and tofsensor measurements
        message_filters::Subscriber<sonar::TwoSonar> sonar_sub(nodeHandle, "/sonar", 1);
        message_filters::Subscriber<nlink_parser::TofsenseFrame0> tof_sub(nodeHandle, "/nlink_tofsense_frame0", 1);
        typedef message_filters::sync_policies::ApproximateTime<sonar::TwoSonar, nlink_parser::TofsenseFrame0> MySyncPolicy;
        message_filters::Synchronizer<MySyncPolicy> sync(MySyncPolicy(1), sonar_sub, tof_sub);
        sync.registerCallback(boost::bind(&callback, _1, _2));
        ros::spin();
        myfile.close();
    }
    else
    {
        ROS_INFO("No csv path param!");
    }
    return 0;
}