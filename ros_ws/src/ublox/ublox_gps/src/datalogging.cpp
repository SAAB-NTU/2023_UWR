#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <experimental/filesystem>
#include <mutex>
#include <fstream>

    std::ofstream myfile; //Create a filestream variable to write data into
    std::mutex mtx;  // For multi-threading performance--> speed, for multiple functions to use one CSV file

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

        // Format the date and time components as a string  ---> Easy data-logging names
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

class data_logger
{
    public:

        data_logger()
        {
            

            gps_sub=nh_.subscribe("/ublox/fix",1,&data_logger::gps_callback,this);
            
        };


        void gps_callback(const sensor_msgs::NavSatFixConstPtr& msg)
        {
          
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
            csv_writer(ss1.str()+ ","+ ss2.str()+","+ss3.str()+","+ss4.str()+"\n");
           
        }

        
   
        
    private:
        ros::NodeHandle nh_;
        
        ros::Subscriber gps_sub;

        bool start = false;
};

int main(int argc,char* argv[])
{
    ros::init(argc,argv,"data_logger");
    ros::NodeHandle nodeHandle;
    std::string path_param;
    if(ros::param::get("~csv_path",path_param))
    {
        std::string file_path = csv_create_file(path_param);
        myfile.open(file_path);
        myfile << "time,gps_long,gps_lat,gps_status\n";

     
    data_logger logger_object; //To try using one filter per DOF
    ros::spin();
    }
    else
    {
        ROS_INFO("No csv path param!");
    }
 
    return 0; 
}