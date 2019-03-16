#define LEFT_SENS 35
#define RIGHT_SENS 34
void setup_follow_line(){
    pinMode(LEFT_SENS, INPUT_PULLUP);
    pinMode(RIGHT_SENS, INPUT);
}
void run_follow_line(){
    Serial.println("Line Follower Starting now");
    while(1){
        if(lon() && ron())
        {
            GoFrwrd();
        }
        else if(lon() && !ron())
        {
            TurnRight();
        }
        else if(ron() && !lon())
        {
            TurnLeft();
        }
        else if(!ron() && !lon())
        {
            Serial.println("Stopping Now");
            
            Serial.print(digitalRead(LEFT_SENS));
            Serial.print(",");
            Serial.println(digitalRead(RIGHT_SENS));

            Stop(); 
            return;
        }
        delay(10);
    }
    Serial.println("Shouldnt come here so easy");
}

bool lon(){
    return !digitalRead(LEFT_SENS);
}
bool ron(){
    return !digitalRead(RIGHT_SENS);
}