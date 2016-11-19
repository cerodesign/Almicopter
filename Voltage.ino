void Read_Voltage()
{
  sucet = sucet - voltage[index];
  
  analog_voltage = analogRead(0);
  volt = (5.28 / 1023.0) * analog_voltage; 
  voltage[index] = volt / (R2/(R1+R2));

  sucet = sucet + voltage[index];
  index++;

  if (index >= 20)
    index = 0;

  filtered_voltage =(float) sucet / 20;
}

