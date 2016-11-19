long sound_time1 = 100, sound_time2 = 100;
long sound_prev_millis = 0;
int sound_counter = 0;

void LowVoltageSound()
{
  if (millis()- sound_prev_millis >= sound_time1)
      {
        sound_counter++;
        sound_prev_millis = millis();
        if (sound_counter >= 8)
          sound_counter = 0;

        //Low battery sound
        if (sound_counter == 1)
        {
          tone(buzzer_pin, 5000); 
        }

        if (sound_counter == 2)
        {
          tone(buzzer_pin, 13000); 
        }

        if (sound_counter == 3)
        {
          tone(buzzer_pin, 5000); 
        }

        if (sound_counter == 4)
        {
          tone(buzzer_pin, 13000); 
        }

        if (sound_counter == 5)
        {
          tone(buzzer_pin, 5000); 
        }

        if (sound_counter == 6)
        {
          tone(buzzer_pin, 13000); 
        }

        if (sound_counter == 7)
        {
          noTone(buzzer_pin); 
        }
      }
}

