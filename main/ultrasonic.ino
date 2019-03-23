#ifdef ULTRASONIC_SENSOR_SUPPORT
#include <Ultrasonic.h>

#define USS_PING_PIN 33
#define USS_ECHO_PIN 32

Ultrasonic ultrasonic(USS_PING_PIN, USS_ECHO_PIN);
int distance;

void ultrasonic_sensor_setup(){
    pinMode(USS_PING_PIN, OUTPUT);
    pinMode(USS_ECHO_PIN, INPUT);
}
void ultrasonic_sensor_loop(){
    calculateDistance();
    delay(500);
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void calculateDistance(){
    // long duration, inches, cm;
    
    // digitalWrite(USS_PING_PIN, LOW);
    // delayMicroseconds(2);
    // digitalWrite(USS_PING_PIN, HIGH);
    // delayMicroseconds(10);
    // digitalWrite(USS_PING_PIN, LOW);
    
    // duration = pulseIn(USS_ECHO_PIN, HIGH);
    // inches = microsecondsToInches(duration);
    // cm = microsecondsToCentimeters(duration);
    // Serial.print(inches);
    // Serial.print("in, ");
    // Serial.print(cm);
    // Serial.print("cm");
    // Serial.println();
    distance = ultrasonic.read();
  
    Serial.print("Distance in CM: ");
    Serial.println(distance);
    delay(1000);
}

#endif