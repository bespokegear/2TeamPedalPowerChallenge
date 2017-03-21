#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "Config.h"
#include "LEDPanel1.h"
#include "LEDPanel2.h"

void display(const char* name, int r, int g, int b)
{
    Serial.println(name);
    for(int i=0; i<LED1_NUM_LEDS; i++) {
        LEDPanel1.setPixelColor(i, r, g, b);
        LEDPanel2.setPixelColor(i, r, g, b);
    }
    LEDPanel1.show();
    LEDPanel2.show();
    delay(1000);
}

void setup()
{
    Serial.begin(115200);
    delay(300);
    LEDPanel1.begin();
    LEDPanel1.clear();
    LEDPanel1.show();
    LEDPanel2.begin();
    LEDPanel2.clear();
    LEDPanel2.show();
}

void loop()
{
    display("red", 100, 0, 0);
    display("green", 0, 100, 0);
    display("blue", 0, 0, 100);
    delay(2500);
}
