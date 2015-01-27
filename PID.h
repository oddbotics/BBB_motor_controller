
#if PID_H
#define PID_H

class PID
{
  public:
    PID();
    PID(float Kp, float Ki, float Kd);
    PID(float Kp, float Ki, float Kd, float time_step);
    PID(float Kp, float Ki, float Kd, float time_step, float min_output, float min_output);
    getValue(int curValue, int prevValue);

  private:
    float Kp;
    float Ki;
    float Kd;
    float time_step; //seconds
    float min_output;
    float max_output;
}

#endif
