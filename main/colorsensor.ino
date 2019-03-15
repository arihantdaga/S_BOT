#define COLOR_SENSOR_PIN     33
void color_sensor_setup(){
    pinMode(COLOR_SENSOR_PIN, INPUT);
}

void color_sensor_loop(){
    int val = analogRead(COLOR_SENSOR_PIN);
    Serial.println(val);
    delay(100);
}