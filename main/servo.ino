#ifdef SERVO_SUPPORT
#include <Servo.h>

#define SERVO_PIN 13

Servo servo1;

void servo_setup(){
    servo1.attach(
            SERVO_PIN, 
            Servo::CHANNEL_NOT_ATTACHED, 
            45,
            120
    );
}

void servo_loop(){
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
            servo1.write(posDegrees);
            // Serial.println(posDegrees);
            delay(10);
        }

        for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
            servo1.write(posDegrees);
            // Serial.println(posDegrees);
            delay(10);
    }
}
#endif
