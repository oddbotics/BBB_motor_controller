PID::PID()
{
  this.Kp = 1.0;
  this.Ki = 1.0;
  this.Kd = 1.0;
  this.time_step = 1.0;
  this.min_output = 0.0;
  this.max_output = 100.0;
}

PID::PID(float Kp, float Ki, float Kd)
{
  this.Kp = Kp;
  this.Ki = Ki;
  this.Kd = Kd;
  this.time_step = 1.0;
  this.min_output = 0.0;
  this.max_output = 100.0;
}

PID::PID(float Kp, float Ki, float Kd, float time_step)
{
  this.Kp = Kp;
  this.Ki = Ki;
  this.Kd = Kd;
  this.time_step = time_step;
  this.min_output = 0.0;
  this.max_output = 100.0;
}

PID::PID(float Kp, float Ki, float Kd, float time_step, float min_output, float max_output)
{
  this.Kp = Kp;
  this.Ki = Ki;
  this.Kd = Kd;
  this.time_step = time_step;
  this.min_output = min_output;
  this.max_output = max_output;
}

float PID::getValue(int curValue, int desValue)
{
  static float sumError = 0;
  static float prevError = 0;

  int error = desValue - curValue;

  // calc potential term
  float potentialTerm = Kp * Error;  

  // calc integral term
  sumError += error;
  float integralTerm = Ki *  sumError; 

  // calc differential term
  float diffError = (error - prevError) / time_step;
  float differentialTerm = Kd * diffError;

  // calculate the PID value
  float pidValue = potentialTerm + integralTerm + differentialTerm;

  //bound the output
  if(pidValue > max_output)
  {
    pidValue = max_output;
  } 
  
  if(pidValue < min_output)
  {
    pidValue = min_output;     
  }

  return pidValue;   
}



