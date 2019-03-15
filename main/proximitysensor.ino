#define IR_OBSTACLE_PIN     22
void proximity_sensor_setup(){
    pinMode(IR_OBSTACLE_PIN, INPUT);
}

void proximity_sensor_loop(){
    bool close = digitalRead(IR_OBSTACLE_PIN) == HIGH;
    if(close){
        Serial.println("Far");
    }else{
        Serial.println("Close");
    }
    delay(500);
}