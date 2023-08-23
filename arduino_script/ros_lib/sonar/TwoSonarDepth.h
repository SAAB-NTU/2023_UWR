#ifndef _ROS_sonar_TwoSonarDepth_h
#define _ROS_sonar_TwoSonarDepth_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sonar
{

  class TwoSonarDepth : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _distance_1_type;
      _distance_1_type distance_1;
      typedef float _confidence_1_type;
      _confidence_1_type confidence_1;
      typedef float _distance_2_type;
      _distance_2_type distance_2;
      typedef float _confidence_2_type;
      _confidence_2_type confidence_2;
      typedef float _depth_type;
      _depth_type depth;
      typedef float _altitude_type;
      _altitude_type altitude;
      typedef float _pressure_type;
      _pressure_type pressure;

    TwoSonarDepth():
      header(),
      distance_1(0),
      confidence_1(0),
      distance_2(0),
      confidence_2(0),
      depth(0),
      altitude(0),
      pressure(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_1;
      u_distance_1.real = this->distance_1;
      *(outbuffer + offset + 0) = (u_distance_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_1);
      union {
        float real;
        uint32_t base;
      } u_confidence_1;
      u_confidence_1.real = this->confidence_1;
      *(outbuffer + offset + 0) = (u_confidence_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence_1);
      union {
        float real;
        uint32_t base;
      } u_distance_2;
      u_distance_2.real = this->distance_2;
      *(outbuffer + offset + 0) = (u_distance_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_2);
      union {
        float real;
        uint32_t base;
      } u_confidence_2;
      u_confidence_2.real = this->confidence_2;
      *(outbuffer + offset + 0) = (u_confidence_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence_2);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.real = this->depth;
      *(outbuffer + offset + 0) = (u_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_depth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->depth);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_pressure;
      u_pressure.real = this->pressure;
      *(outbuffer + offset + 0) = (u_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_distance_1;
      u_distance_1.base = 0;
      u_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_1 = u_distance_1.real;
      offset += sizeof(this->distance_1);
      union {
        float real;
        uint32_t base;
      } u_confidence_1;
      u_confidence_1.base = 0;
      u_confidence_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence_1 = u_confidence_1.real;
      offset += sizeof(this->confidence_1);
      union {
        float real;
        uint32_t base;
      } u_distance_2;
      u_distance_2.base = 0;
      u_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_2 = u_distance_2.real;
      offset += sizeof(this->distance_2);
      union {
        float real;
        uint32_t base;
      } u_confidence_2;
      u_confidence_2.base = 0;
      u_confidence_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence_2 = u_confidence_2.real;
      offset += sizeof(this->confidence_2);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.base = 0;
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->depth = u_depth.real;
      offset += sizeof(this->depth);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_pressure;
      u_pressure.base = 0;
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure = u_pressure.real;
      offset += sizeof(this->pressure);
     return offset;
    }

    virtual const char * getType() override { return "sonar/TwoSonarDepth"; };
    virtual const char * getMD5() override { return "facf9d4c6b34b990b26468acb341d2ba"; };

  };

}
#endif
