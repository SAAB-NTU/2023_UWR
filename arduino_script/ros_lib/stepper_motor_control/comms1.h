#ifndef _ROS_SERVICE_comms1_h
#define _ROS_SERVICE_comms1_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace stepper_motor_control
{

static const char COMMS1[] = "stepper_motor_control/comms1";

  class comms1Request : public ros::Msg
  {
    public:
      typedef bool _dir_type;
      _dir_type dir;
      typedef int32_t _distance_type;
      _distance_type distance;
      typedef float _delay_type;
      _delay_type delay;
      typedef int32_t _stops_type;
      _stops_type stops;
      typedef int32_t _stop_duration_type;
      _stop_duration_type stop_duration;

    comms1Request():
      dir(0),
      distance(0),
      delay(0),
      stops(0),
      stop_duration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_dir;
      u_dir.real = this->dir;
      *(outbuffer + offset + 0) = (u_dir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dir);
      union {
        int32_t real;
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
      } u_delay;
      u_delay.real = this->delay;
      *(outbuffer + offset + 0) = (u_delay.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delay.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delay.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delay.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delay);
      union {
        int32_t real;
        uint32_t base;
      } u_stops;
      u_stops.real = this->stops;
      *(outbuffer + offset + 0) = (u_stops.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stops.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stops.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stops.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stops);
      union {
        int32_t real;
        uint32_t base;
      } u_stop_duration;
      u_stop_duration.real = this->stop_duration;
      *(outbuffer + offset + 0) = (u_stop_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stop_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stop_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stop_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_duration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_dir;
      u_dir.base = 0;
      u_dir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dir = u_dir.real;
      offset += sizeof(this->dir);
      union {
        int32_t real;
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
      } u_delay;
      u_delay.base = 0;
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delay.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delay = u_delay.real;
      offset += sizeof(this->delay);
      union {
        int32_t real;
        uint32_t base;
      } u_stops;
      u_stops.base = 0;
      u_stops.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stops.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stops.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stops.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stops = u_stops.real;
      offset += sizeof(this->stops);
      union {
        int32_t real;
        uint32_t base;
      } u_stop_duration;
      u_stop_duration.base = 0;
      u_stop_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stop_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stop_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stop_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stop_duration = u_stop_duration.real;
      offset += sizeof(this->stop_duration);
     return offset;
    }

    virtual const char * getType() override { return COMMS1; };
    virtual const char * getMD5() override { return "e830558e2a405ce1cd5a6fc338536cbf"; };

  };

  class comms1Response : public ros::Msg
  {
    public:
      typedef int32_t _steps_type;
      _steps_type steps;

    comms1Response():
      steps(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_steps;
      u_steps.real = this->steps;
      *(outbuffer + offset + 0) = (u_steps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steps);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_steps;
      u_steps.base = 0;
      u_steps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steps = u_steps.real;
      offset += sizeof(this->steps);
     return offset;
    }

    virtual const char * getType() override { return COMMS1; };
    virtual const char * getMD5() override { return "7201236d5304b355a086cd082e7b14d5"; };

  };

  class comms1 {
    public:
    typedef comms1Request Request;
    typedef comms1Response Response;
  };

}
#endif
