#include <ros/ros.h>
#include <string>
#include <sonar/Sonar.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>
#include <experimental/filesystem>
#include <mutex>
#include <fstream>

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

void sonar_callback(const sonar::SonarConstPtr& sonar)
{
    // std::stringstream to preserve full precision of sensor measurements
    ros::Time time = ros::Time::now();
    std::stringstream ss1;
    std::stringstream ss3;
    std::stringstream ss4;
    ss3.precision(15);
    ss4.precision(15);
    ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
    ss3 << sonar->distance;
    ss4 << sonar->confidence;
    ROS_INFO("sonar_distance: %f",sonar->distance);
    ROS_INFO("confidence: %f",sonar->confidence);
    //ROS_INFO("sonar_time: %s",ss0.str().c_str());
    //ROS_INFO("tof_tim: %s",ss6.str().c_str());
    csv_writer(ss1.str()+","+"sonar" + "," + ss3.str()+"," + ss4.str()+"\n");
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
    ss2.precision(15);
    ss3.precision(15);
    ss4.precision(15);
    ss5.precision(15);
    ss6.precision(15);
    ss7.precision(15);
    ss1 << time.sec << "." << std::setw(9) << std::setfill('0') << time.nsec;
    ss2 << imu->linear_acceleration.x;
    ss3 << imu->linear_acceleration.y;
    ss4 << imu->linear_acceleration.z;
    ss5 << imu->angular_velocity.x;
    ss6 << imu->angular_velocity.y;
    ss7 << imu->angular_velocity.z;
    ROS_INFO("linear_x: %f",imu->linear_acceleration.x);
    ROS_INFO("linear_y: %f",imu->linear_acceleration.y);
    ROS_INFO("linear_z: %f",imu->linear_acceleration.z);
    ROS_INFO("angular_x: %f",imu->angular_velocity.x);
    ROS_INFO("angular_y: %f",imu->angular_velocity.y);
    ROS_INFO("angular_z: %f",imu->angular_velocity.z);
    csv_writer(ss1.str()+ ",imu,,,"+ ss2.str() + "," + ss3.str()+"," + ss4.str()+ ","+ ss5.str() + "," + ss6.str() + "," + ss7.str()+"\n");
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
        myfile << "time,sensor,sonar_distance,sonar_confidence,accel x,accel y,accel z,angular_vel x,angular_vel y,angular_vel z\n";
        ros::Subscriber imu_sub = nodeHandle.subscribe("/an_device/Imu",1,imu_callback);
	ros::Subscriber sonar_sub = nodeHandle.subscribe("/sonar",1,sonar_callback);

        ros::spin();
        myfile.close();
    }
    else
    {
        ROS_INFO("No csv path param!");
    }
    return 0;
}
