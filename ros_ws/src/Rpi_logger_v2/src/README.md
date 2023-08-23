# RPi Data Logger

ROS packages for SAAB UWR localisation experiments

## Basic Info
Directory Structure

~/trial/src/ <br>
|--imu_complementary (currently not used) <br>
|-- logger <br>
|-- nlink_parser(tofsensor) <br>
|-- sonar <br>
|-- witmotion_IMU_ros <br>

### Logging Launch File
logger/launch/logger.launch will launch all the sensor nodes. 

### IMU Calibration
There is some delay between running the imu node and logger node. This is to wait until imu finish calibrating <br>

The imu calibration script can be found in witmotion_IMU_ros/scripts/calibration.py <br>

### Logging Script
Values recorded:

![Alt text](cpp_logger.png?raw=true "Sample File")

There are two types of logger scripts that can be used:<br>
1.) logger/scripts/logger.py (python)
- supports reading different sensor combinations
- change mode param in launch file -> all/imu_tof/imu/sonar/tof

2.) logger/src/logger_node.cpp (c++)
- runs faster so it can record more sensor measurements
- **have to catkin build after modifying script**

Use either one of the two scripts by commenting out the other one in logger.launch

## Setup
1.) Connect to rpi access point
- Username: Raspberry
- Password: kong12345

2.) SSH into RPi
```bash
ssh ubuntu@10.42.0.1
```
- Password: kong12345

3.) Connect sensors to serial ports <br>
** Very IMPORTANT to follow the sequence below when connecting sensors** <br>
**1.) /dev/ttyUSB0 -> imu** <br>
**2.) /dev/ttyUSB1 -> sonar** <br>
**3.) /dev/ttyACM0 -> tofsensor** <br>

Ensure that the sensors are using these ports <br>
If there are any changes to the serial ports, modify the serial port values in these files: <br>
- logger/launch/logger.launch
- witmotion_IMU_ros/scripts/calibration.py

## Usage

```bash
roslaunch logger logger.launch
```

Terminal will print sensor measurements if there is no issue. <br>

CSV files are all saved as "all_log_(n).csv" by default in "/home/ubuntu/data/" directory. Logger scripts will automatically check for existing names and update (n). Modify the csv_path param in logger.launch to change this. Remove all content of this directory before starting experiment. <br>

Transfer files to host device using scp 
```bash
scp [FILE NAME] [HOST USERNAME]@[HOST IP]:[HOST DESTINATION PATH]
```

Shutdown RPi
```bash
sudo shutdown now
```

