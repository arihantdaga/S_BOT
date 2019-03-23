#ifdef LED_SUPPORT
#include <Adafruit_NeoPixel.h>
#define LED_PIN     26
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, LED_PIN, NEO_RGB + NEO_KHZ800);
uint8_t current_colors[3] = {0,0,50};
bool lights_off = false;
void led_setup(){
     pixels.begin();
}

void led_loop(){
    Serial.println("Coming to LED LOOP");
    if(!lights_off){
        pixels.setPixelColor(0, pixels.Color(current_colors[0], current_colors[1], current_colors[2])); 
        pixels.show(); // This sends the updated pixel color to the hardware.
    }else{
        pixels.clear();
    }
}

void set_color(uint8_t r, uint8_t g, uint8_t b){
    current_colors[0] = r;
    current_colors[0] = g;
    current_colors[0] = b;
}

void turn_off_light(bool f){
    lights_off = f;
}

#endif

