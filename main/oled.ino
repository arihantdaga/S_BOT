#ifdef OLED_SUPPORT
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
SSD1306  display(0x3c, 21, 22);
char my_name[30] = "Manan";
unsigned long last_displayed = 0;

void oled_setup(){
  display.init();
  display.setContrast(255);
}

void oled_loop(){
    Serial.println("Coming to O - LED LOOP");
if(millis() - last_displayed > 2000){
    Serial.println("Came here also");
    clear_display();
    delay(500);
    show_name();
    last_displayed = millis();
}
}

void show_name(){
    display.clear();
    display.print("Hello ");
    display.println(my_name);
    display.display();
}

void set_name(const char * name){
    snprintf(my_name, 29, "%s", name);
    my_name[29] = '\0'; // Safety
}

void clear_display(){
    display.clear();
}

#endif
