#if MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <iostream>
#include <cmath>
#include "BlackLib/v2_0/BlackPWM.h"
#include "BlackLib/v2_0/BlackGPIO.h"
#include "encoders/api/c++/eqep.h"
#include <chrono>

// PID Parameters for the specific motor
float Kp_vel, Ki_vel, Kd_vel;
float Kp_pos, Ki_pos, Kd_pos;
float time_step;
float min_vel_output, max_vel_output;
float min_pos_output, max_pos_output;

// motor parameters
float wheel_radius;
float ticks_per_rev;

// control variables
bool POSE_CONTROL;
bool VEL_CONTROL;

// desired control 
float desVel;
float desPos;

// current control
float curVel = 0.0;
float curPos = 0.0;

#endif
