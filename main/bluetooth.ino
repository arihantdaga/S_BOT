#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

void bt_setup(){
     SerialBT.begin("S_BOT");
     Serial.println("The device started, now you can pair it with bluetooth!");
}

void bt_serial_loop(){
        if (SerialBT.available())
        {
                String DIR = SerialBT.readStringUntil('\n');

                if (DIR.length())
                {
                        Serial.print("Command Arrived : ");
                        DIR.trim();
                        Serial.println(DIR);
                }

                if (DIR.equals("RI"))
                {
                        Serial.println("Going RIGHT");
                        TurnRight();
                }
                else if (DIR.equals("LF"))
                {       Serial.println("Going Left");
                        TurnLeft();
                }
                else if (DIR.equals("FW"))
                {
                        Serial.println("Going FW");
                        GoFrwrd();
                }
                else if (DIR.equals("BW"))
                {
                        Serial.println("Going Back");
                        GoBack();
                }
                else if (DIR.equals("STOP"))
                {       Serial.println("Stopping");
                        Stop();
                }else if(DIR.equals("LINE")){
                        Serial.println("Will Follow Line Now");
                        delay(2000);
                        setup_follow_line();
                        run_follow_line();
                        Serial.println("Line Follower Ended");
                }
        }
}