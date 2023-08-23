#ifndef _ROS_sonar_Sonar_h
#define _ROS_sonar_Sonar_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sonar
{

  class Sonar : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef float _transmit_duration_type;
      _transmit_duration_type transmit_duration;
      typedef float _ping_number_type;
      _ping_number_type ping_number;
      typedef float _scan_start_type;
      _scan_start_type scan_start;
      typedef float _scan_length_type;
      _scan_length_type scan_length;
      typedef float _gain_setting_type;
      _gain_setting_type gain_setting;
      uint32_t profile_data_length;
      typedef uint8_t _profile_data_type;
      _profile_data_type st_profile_data;
      _profile_data_type * profile_data;

    Sonar():
      header(),
      distance(0),
      confidence(0),
      transmit_duration(0),
      ping_number(0),
      scan_start(0),
      scan_length(0),
      gain_setting(0),
      profile_data_length(0), st_profile_data(), profile_data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      union {
        float real;
        uint32_t base;
      } u_transmit_duration;
      u_transmit_duration.real = this->transmit_duration;
      *(outbuffer + offset + 0) = (u_transmit_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transmit_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transmit_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transmit_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transmit_duration);
      union {
        float real;
        uint32_t base;
      } u_ping_number;
      u_ping_number.real = this->ping_number;
      *(outbuffer + offset + 0) = (u_ping_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ping_number.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ping_number.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ping_number.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ping_number);
      union {
        float real;
        uint32_t base;
      } u_scan_start;
      u_scan_start.real = this->scan_start;
      *(outbuffer + offset + 0) = (u_scan_start.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scan_start.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scan_start.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scan_start.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_start);
      union {
        float real;
        uint32_t base;
      } u_scan_length;
      u_scan_length.real = this->scan_length;
      *(outbuffer + offset + 0) = (u_scan_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scan_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scan_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scan_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_length);
      union {
        float real;
        uint32_t base;
      } u_gain_setting;
      u_gain_setting.real = this->gain_setting;
      *(outbuffer + offset + 0) = (u_gain_setting.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gain_setting.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gain_setting.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gain_setting.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gain_setting);
      *(outbuffer + offset + 0) = (this->profile_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->profile_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->profile_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->profile_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->profile_data_length);
      for( uint32_t i = 0; i < profile_data_length; i++){
      *(outbuffer + offset + 0) = (this->profile_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->profile_data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      union {
        float real;
        uint32_t base;
      } u_transmit_duration;
      u_transmit_duration.base = 0;
      u_transmit_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transmit_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transmit_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transmit_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transmit_duration = u_transmit_duration.real;
      offset += sizeof(this->transmit_duration);
      union {
        float real;
        uint32_t base;
      } u_ping_number;
      u_ping_number.base = 0;
      u_ping_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ping_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ping_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ping_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ping_number = u_ping_number.real;
      offset += sizeof(this->ping_number);
      union {
        float real;
        uint32_t base;
      } u_scan_start;
      u_scan_start.base = 0;
      u_scan_start.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scan_start.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scan_start.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scan_start.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scan_start = u_scan_start.real;
      offset += sizeof(this->scan_start);
      union {
        float real;
        uint32_t base;
      } u_scan_length;
      u_scan_length.base = 0;
      u_scan_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scan_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scan_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scan_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scan_length = u_scan_length.real;
      offset += sizeof(this->scan_length);
      union {
        float real;
        uint32_t base;
      } u_gain_setting;
      u_gain_setting.base = 0;
      u_gain_setting.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gain_setting.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gain_setting.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gain_setting.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gain_setting = u_gain_setting.real;
      offset += sizeof(this->gain_setting);
      uint32_t profile_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      profile_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      profile_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      profile_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->profile_data_length);
      if(profile_data_lengthT > profile_data_length)
        this->profile_data = (uint8_t*)realloc(this->profile_data, profile_data_lengthT * sizeof(uint8_t));
      profile_data_length = profile_data_lengthT;
      for( uint32_t i = 0; i < profile_data_length; i++){
      this->st_profile_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_profile_data);
        memcpy( &(this->profile_data[i]), &(this->st_profile_data), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "sonar/Sonar"; };
    virtual const char * getMD5() override { return "9e4a4d737f58de7be4dcffacf14f18c8"; };

  };

}
#endif
