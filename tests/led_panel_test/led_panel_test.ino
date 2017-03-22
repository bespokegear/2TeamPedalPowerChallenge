#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <MutilaDebug.h>
#include "Config.h"
#include "RIBargraphDisplay.h"

RIBargraphDisplay Bar1(LED1_NEOPIXEL_TYPE, 2, LED1_DATA_PIN);
RIBargraphDisplay Bar2(LED2_NEOPIXEL_TYPE, 2, LED2_DATA_PIN);
unsigned long lastReset = 0;

void setup()
{
    Serial.begin(115200);
    delay(300);
    Bar1.begin();
    Bar2.begin();
    DB("number of rows=");
    DBLN(Bar1.numRows());
}

void loop()
{
    if (millis() > lastReset + 1000) {
        Bar1.clearPeak();
        Bar2.clearPeak();
        lastReset = millis();
    }
    Bar1.graph(random() % Bar1.numRows(), 0x660066UL, true, 0x888888UL);
    Bar2.graph(random() % Bar2.numRows(), 0x004400UL, true, 0x888888UL);
    delay(100);
}
