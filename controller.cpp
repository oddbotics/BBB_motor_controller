#include "controller.h"

int main(int argv, char * argc[])
{  
  //read in global variables for the specific motor based on the command line input 

  // velocity and or position control
  POSE_CONTROL = false;
  VEL_CONTROL = true;  

  // PID loops
  vel_PID(Kp_vel, Ki_vel, Kd_vel, min_vel_output, max_vel_output);
  pos_PID(Kp_pos, Ki_pos, Kd_vel, min_pos_output, max_pos_output);
  
  // get the current time to calculate dt
    high_resolution_clock::time_point prevTime = high_resolution_clock::now();

  //gives current motor speed, motor current, temperature, wheel position
  while(/*everything okay*/)
  {
    // get the encoder count
  
    // calculate the position
    float deltaPosition = (deltaEncoder / ticks_per_rev) * (2 * M_PI * wheel_radius); 

    // calculate the velocity
    float curVel = deltaPosition/time_step;     

	//calculate dt
	high_resolution_clock::time_point curTime = high_resolution_clock::now();  
	auto dt = std::chrono::duration_cast<std::chrono::microseconds>( curTime - prevTime ).count();
	
    // calculate the appropriate  PID value
    if(VEL_CONTORL == true)
    {
	  //calculate dt
	  high_resolution_clock::time_point curTime = high_resolution_clock::now();  
	  auto dt = std::chrono::duration_cast<std::chrono::microseconds>( curTime - prevTime ).count();
      
      //calcuate PID output
      vel_PID.getValue(curVel,desVel,dt);
      
      //set the Motor Speed
      
      // set the previous calculation time
      prevTime = curTime;
    } else if(POSE_CONTROL == true)
    {
	  //calculate dt
	  high_resolution_clock::time_point curTime = high_resolution_clock::now();  
	  auto dt = std::chrono::duration_cast<std::chrono::microseconds>( curTime - prevTime ).count();
      
      //calcuate PID output
      pos_PID.getValue(curPos,desPos,dt);
      
      //set the Motor Speed
      
      // set the previous calculation time
      prevTime = curTime;
    }
    
  }
}

// 100 times per second ge tthe encoder count
// calculate the PID value 
// update the feedback
