

#include "app.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len);


//HIGH white
//LOW black
// #include <Wire.h>
// #include "SSD1306.h" 
// SSD1306  display(0x3c, 21, 22);

void setup()
{
        Serial.begin(115200);
        // SerialBT.begin("ESP32test"); //Bluetooth device name
        motor_setup();
        // audio_setup();
        delay(1000);
        #ifdef BLE_SUPPORT
        bt_setup();
        #endif

        #ifdef WS_SUPPORT
        server_setup();
        #endif

        //pinMode(6,INPUT);
        //pinMode(7,INPUT);
        // display.init();
        // display.drawString(0, 0, "Hello World");
        // display.display();
        // proximity_sensor_setup();
        #ifdef COLOR_SENSOR_SUPPORT
        color_sensor_setup();
        #endif
        #ifdef ULTRASONIC_SENSOR_SUPPORT
        ultrasonic_sensor_setup();
        #endif
        #ifdef LED_SUPPORT
        led_setup();
        #endif
        #ifdef OLED_SUPPORT
        oled_setup();
        #endif

        #ifdef SERVO_SUPPORT
        servo_setup();
        #endif
}
void loop()
{
        // dynamic line follower code
        // if the sensor is on white it returns LOW value to the Arduino
        // if it is on black it returns a HIGH value to the Arduino

        // audio_loop();
        #ifdef BLE_SUPPORT
        bt_serial_loop();
        #endif

        #ifdef WS_SUPPORT
        server_loop();
        #endif
        #ifdef COLOR_SENSOR_SUPPORT
        color_sensor_loop();
        #endif

        #ifdef ULTRASONIC_SENSOR_SUPPORT
        ultrasonic_sensor_loop();
        #endif

        #ifdef LED_SUPPORT
        led_loop();
        #endif

        #ifdef OLED_SUPPORT
        oled_loop();
        #endif

        #ifdef SERVO_SUPPORT
        servo_loop();
        #endif

        //  display.drawString(0, 0, "Hello World");
        // display.drawString(0, 0, "Hello World");
        // display.display();
        // proximity_sensor_loop();
        // ultrasonic_sensor_loop();
        // GoFrwrd();
        // delay(2000);
        // TurnRight();
        // delay(2000);
        // TurnLeft();
        // delay(2000);
        // GoBack();
        // delay(2000);
        // Stop();
        // delay(2000);

}
