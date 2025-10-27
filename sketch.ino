#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

// penjelasn objek yang dipakai
Adafruit_MPU6050 mpu;
Servo servo1, servo2, servo3, servo4, servo5;

// penjelasan pin masing-masing servo
#define SERVO1_PIN 12
#define SERVO2_PIN 14
#define SERVO3_PIN 27
#define SERVO4_PIN 26 
#define SERVO5_PIN 13
#define PIR_PIN 33
