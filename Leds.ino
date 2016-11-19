long time1 = 100, time2 = 150, time3 = 300;
long prev_millis1 = 0;
int led_counter = 0;

//Led blinking effects, changeable via Android app
 
void led_enable() 
{
  switch (effect) {
    case 1:
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, B00011110);
      digitalWrite(latchPin, HIGH); 
      break;
    case 2:
      //-------------------------------------------
      if (millis()- prev_millis1 >= time1)
      {
        led_counter++;
        prev_millis1 = millis();
        if (led_counter >= 6)
          led_counter = 0;

        if (led_counter == 1)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00010000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 2)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00001000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 3)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000100);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 4)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000010);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 5)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }
      }
      //-------------------------------------------
      break;
    case 3:
      //-------------------------------------------
      if (millis()- prev_millis1 >= time1)
      {
        led_counter++;
        prev_millis1 = millis();
        if (led_counter >= 6)
          led_counter = 0;

        if (led_counter == 1)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000010);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 2)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000100);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 3)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00001000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 4)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00010000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 5)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }
      }
      //-------------------------------------------
      break;
    case 4:
      //-------------------------------------------
      if (millis()- prev_millis1 >= time2)
      {
        led_counter++;
        prev_millis1 = millis();
        if (led_counter >= 9)
          led_counter = 0;

        if (led_counter == 1)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00011000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 2)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 3)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00001100);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 4)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 5)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000110);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 6)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 7)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00010010);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 8)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }
      }
      //-------------------------------------------
      break;
    case 5:
      //-------------------------------------------
      if (millis()- prev_millis1 >= time3)
      {
        led_counter++;
        prev_millis1 = millis();
        if (led_counter >= 7)
          led_counter = 0;

        if (led_counter == 1)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00010100);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 2)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 3)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00001010);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 4)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 5)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00011110);
          digitalWrite(latchPin, HIGH); 
        }

        if (led_counter == 6)
        {
          digitalWrite(latchPin, LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
          digitalWrite(latchPin, HIGH); 
        }
      }
      //-------------------------------------------
      break;
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
}

void setBrightness(byte brightness) 
{
  analogWrite(brt_pin, 255-brightness);
}

