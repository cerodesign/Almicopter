void debug()
{
  
  //vypis uhlov
  Serial.print("Angle x: ");
  Serial.print(kalAngleX);
  Serial.print("\tAngle y: ");
  Serial.print(kalAngleY);

  //vypis motorov + konfiguracia
  Serial.print("\t\tM1: ");
  Serial.print(m1);
  
  Serial.print("\t\tM2: ");
  Serial.print(m2);
  
  Serial.print("\t\tM3: ");
  Serial.print(m3);
  
  Serial.print("\t\tM4: ");
  Serial.print(m4);

  /*//vypis PID konstant
  Serial.print("\t\tKp: ");
  Serial.print(Kp);
  
  Serial.print("\t\tKi: ");
  Serial.print(Ki);
  
  Serial.print("\t\tKd: ");
  Serial.print(Kd);
  Serial.println();*/

  
  //vypis napetia
  Serial.print("\t\tVoltage: ");
  Serial.print(filtered_voltage);
  //Serial.println();
  
  /*//vypis setpointov
  Serial.print("\t\tYaw:");
  Serial.print(Setpoint_Yaw);
  Serial.print("\tPitch:");
  Serial.print(Setpoint_Pitch);
  Serial.print("\tRoll:");
  Serial.print(Setpoint_Roll);*/
  
  //vypis vykonu
  Serial.print("\t\tThrottle:");
  Serial.print(throttle);
  Serial.println();
}

void sendAndroidValues()
{/*
    //puts # before the values so our app knows what to do with the data
    Serial.print('#');
    //for loop cycles through 4 sensors and sends values via serial
    Serial.print(filtered_voltage);
    //Serial.print('+');
    
    Serial.print('~'); //used as an end of transmission character - used in app for string length
    Serial.println();
    delay(18);*/
}
