Servo ESC1, ESC2, ESC3, ESC4; 

void motors_initialize()
{
  ESC1.attach(6); 
  ESC2.attach(11);  
  ESC3.attach(9);  
  ESC4.attach(10);  
  
  ESC1.writeMicroseconds(MOTOR_ZERO_LEVEL); // Set "0" Throttle
  ESC2.writeMicroseconds(MOTOR_ZERO_LEVEL);
  ESC3.writeMicroseconds(MOTOR_ZERO_LEVEL);
  ESC4.writeMicroseconds(MOTOR_ZERO_LEVEL);
}

void motors_set_speed(int esc1, int esc2, int esc3, int esc4)
{
  ESC1.writeMicroseconds(esc1);
  ESC2.writeMicroseconds(esc2);
  ESC3.writeMicroseconds(esc3);
  ESC4.writeMicroseconds(esc4);
}

void motor_control()
{
  m1 = throttle + Output_Roll + Output_Pitch + Output_Yaw; 
  m2 = throttle - Output_Roll + Output_Pitch - Output_Yaw;
  m3 = throttle + Output_Roll - Output_Pitch - Output_Yaw;
  m4 = throttle - Output_Roll - Output_Pitch + Output_Yaw;

  motors_set_speed(m1, m2, m3, m4);
}

