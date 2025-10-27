#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

Servo myServos[5];
Adafruit_MPU6050 mpu;
int servoPins[5] = {12, 27, 14, 26, 13};
float rollpitchsense = 0.5;
float yawsense = 0.5;

void setup() {
    Serial.begin(115200);

    for (int i = 0; i < 5; i++) {
        myServos[i].attach(servoPins[i]);
        myServos[i].write(90);
    }
    
    pinMode(18, INPUT);
}

void loop() {
    int gerakanManusia = digitalRead(18);
    while (!mpu.begin()) {
    Serial.println("Failed to find a valid MPU6050 sensor, please check the wiring!");
    delay(500);
    }

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    if(gerakanManusia == HIGH) {
        
        for(int i = 0; i < 5; i++) {
            myServos[i].write(45);
        }
        delay(1000);
        
        for(int i = 0; i < 5; i++) {
            myServos[i].write(90);
        }
        delay(3000);
    }
    else if (gerakanManusia != HIGH) {
      float roll = a.acceleration.x;
      float pitch = a.acceleration.y;
      float yaw = g.gyro.z;

      if (roll > rollpitchsense) {
        myServos[0].write(0);
        myServos[1].write(0);
      }else if(roll < rollpitchsense) {
        myServos[0].write(180);
        myServos[1].write(180); 
      }
    }
    delay(100);
}
