#include <Arduino.h>
#include <stdio.h>

char buf[14];

void setup()
{
    Serial.begin(115200);
    delay(300);
}

void loop()
{
    Serial.println(F("aAACD3------")); delay(1000);
    Serial.println(F("aAACD2------")); delay(1000);
    Serial.println(F("aAACD1------")); delay(1000);
    Serial.println(F("aAACD0------")); delay(1000);
    for (int i=50; i>0; i--) {
        memset(buf, 0, 14);
        snprintf(buf, 13, "aAAT%04d----", i);
        Serial.println(buf);
        delay(100);
    }
    Serial.println(F("aAAWN2------"));
    delay(3000);
}
