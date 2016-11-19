//create PID object and set parameters
PID PID_Pitch(&Input_Pitch, &Output_Pitch, &Setpoint_Pitch, Kp,   Ki  , Kd, REVERSE);//1.9,0.8,0.8
PID PID_Roll(&Input_Roll, &Output_Roll, &Setpoint_Roll,     Kp,   Ki  , Kd, REVERSE);

void PID_initialize() 
{
  PID_Pitch.SetOutputLimits(PID_PITCH_MIN, PID_PITCH_MAX);
  PID_Pitch.SetMode(AUTOMATIC);
  PID_Pitch.SetSampleTime(10);

  PID_Roll.SetOutputLimits(PID_ROLL_MIN, PID_ROLL_MAX);
  PID_Roll.SetMode(AUTOMATIC);
  PID_Roll.SetSampleTime(10);
}

void PID_input_update()
{
  Input_Pitch = kalAngleX;
  Input_Roll  = kalAngleY;
}

void PID_Compute() 
{
  PID_Pitch.Compute(); //Computer PID output
  PID_Roll.Compute();
}

