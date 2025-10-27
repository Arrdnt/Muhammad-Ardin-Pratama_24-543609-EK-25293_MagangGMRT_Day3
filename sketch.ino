#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

Servo myServos[5];

int servoPins[5] = {12, 14, 27, 26, 13};

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
    
    delay(100);
}
