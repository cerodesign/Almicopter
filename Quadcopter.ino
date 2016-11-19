#include "I2Cdev.h"
#include "MPU6050.h"
#include "Configuration.h"
#include <SoftwareSerial.h>  
#include <SerialCommand.h>
#include <PID_v1.h>
#include <Servo.h>
#include <Wire.h>
#include <Kalman.h> 
#include <LEDFader.h>

// Create new LED Fader on pin 3
LEDFader led = LEDFader(3);

Kalman kalmanX; // Create the Kalman instances
Kalman kalmanY;

/* IMU Data */
double accX, accY, accZ;
double gyroX, gyroY, gyroZ;
int16_t tempRaw;

double gyroXangle, gyroYangle; // Angle calculate using the gyro only
double kalAngleX, kalAngleY; // Calculated angle using a Kalman filter

uint32_t timer;
uint8_t i2cData[14]; // Buffer for I2C data

double roll, pitch;

SerialCommand SCmd; 

//LED blinking effect variable
int effect = 1;

//Throttle variable
int throttle = 700;

//premenne pre PID
double Setpoint_Yaw,   Input_Yaw,   Output_Yaw;
double Setpoint_Pitch, Input_Pitch, Output_Pitch;
double Setpoint_Roll,  Input_Roll,  Output_Roll;

float Kp = 1.9, Ki = 0.8, Kd = 0.6;

// Motory
int m1, m2, m3, m4; // Predny, Pravy, Zadny, Lavy

//Premenne pre meranie napätia
int analog_voltage = 0, index = 0;
double volt;
float R1=10000.0;
float R2=5550.0;
float filtered_voltage = 0, sucet = 0, voltage[20], min_voltage = 10;

//Buzzer
int buzzer_pin = 2;

//Start variable
int On = 0;

//Shift-register for LEDs variables
int latchPin = 5, clockPin = 4, dataPin = 12, brt_pin = 3;
int brightnes = 0;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
    pinMode(brt_pin, OUTPUT);
    pinMode(2, OUTPUT);

    PID_initialize(); //Inicializacia PID
    motors_initialize(); //Inicializacia motorov
    mpu_initialize();

    //Control commands
    SCmd.addCommand("ON",TurnOn);       
    SCmd.addCommand("OFF",TurnOff);       
    SCmd.addCommand("P",P_set);
    SCmd.addCommand("I",I_set);
    SCmd.addCommand("D",D_set);
    SCmd.addCommand("PID",PID_setpoints);
    SCmd.addCommand("BR",Led_brightness);  
    SCmd.addCommand("THR",setThrottle); 
    SCmd.addCommand("EFF",setEffect);   
    SCmd.addDefaultHandler(error);  
    Serial.println("Serial listening..."); 

    delay(5000);//delay for sensors stabilization
}

void loop() {
  SCmd.readSerial(); 
  PID_input_update();
  debug(); 
  Read_Voltage();
  get_angles();
  led_enable();
  sendAndroidValues();
  led.update();

  //Beeping when battery is too low + LED fade effect
  /*if (filtered_voltage <= min_voltage)
  {
  LowVoltageSound();
  if (led.is_fading() == false) {

    // Fade from 255 - 0
    if (led.get_value() == 255) {
      led.fade(0, 200);
    }
    // Fade from 0 - 255
    else {
      led.fade(255, 200);
    }
  }
  }
  else
    noTone(buzzer_pin); */

  if (On == 1)
  {
    motor_control();
    PID_Compute();
  }
  else  
    motors_initialize();
}

void TurnOn()
{
  On = 1;
  throttle = 900;
}

void TurnOff()
{
  On = 0;
  throttle = 700;
}

void P_set()
{
    char *arg;

    arg = SCmd.next(); 
    if (arg != NULL) 
    {
      Kp = atof(arg);
    }
}

void I_set()
{
    char *arg;

    arg = SCmd.next(); 
    if (arg != NULL) 
    {
      Ki = atof(arg);
    }
}

void D_set()
{
    char *arg;

    arg = SCmd.next(); 
    if (arg != NULL) 
    {
      Kd = atof(arg);
    }
}

void PID_setpoints()    
{
  char *arg; 
  int angle = 0;

  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    angle = atoi(arg);   
    Setpoint_Roll = map(angle, -9, 9, ROLL_MIN_ANGLE, ROLL_MAX_ANGLE);
  } 

  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    angle = atoi(arg);   
    Setpoint_Pitch = map(angle, 9, -9, PITCH_MIN_ANGLE, PITCH_MAX_ANGLE);
  } 

  arg = SCmd.next(); 
  if (arg != NULL) 
  {
    angle = atoi(arg);   
    Setpoint_Yaw = map(angle, 9, -9, YAW_MIN_ANGLE, YAW_MAX_ANGLE); 
  }
}

void Led_brightness()
{
    char *arg;
    int brt = 0; 

    arg = SCmd.next(); 
    if (arg != NULL) 
    {
      brt = atoi(arg);
      brightnes = map(brt, 0, 100, 0, 230);
    } 
    if (filtered_voltage >= min_voltage)
      setBrightness(brightnes);
}

void setThrottle()
{
    char *arg;
    int thr = 0; 

    arg = SCmd.next(); 
    if (arg != NULL) 
    {
      thr = atoi(arg);
      throttle = map(thr, 0, 100, 750, 1900);
    } 
}

void setEffect()
{
    char *arg; 
    arg = SCmd.next(); 
    if (arg != NULL) 
    {
      effect = atoi(arg);
    } 
}

void error()
{
  Serial.println("Nezadefinovany prikaz...");//Unknown command
}


