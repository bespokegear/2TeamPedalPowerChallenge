#include <Arduino.h>
#include <MutilaDebug.h>
#include "Display.h"

char buf[13];

Display_ Display;

void Display_::begin()
{
    DBLN(F("Display.begin()"));
}

void Display_::clear()
{
    DBLN(F("Display.clear()"));
    Serial.println(F("aAACL-------"));
}

void Display_::countdown(uint8_t n)
{
    if (n>0) {
        DB(F("DISPLAY [countdown]: "));
        DBLN(n);
    } else {
        DBLN(F("DISPLAY [countdown]: GO!"));
    }
    memset(buf,0,13);   
    snprintf(buf, 12, "aAACD%d------", n);
    Serial.println(buf);
}

void Display_::say(const char* str)
{
    DB(F("DISPLAY [str - TODO]: "));
    DBLN(str);
    Serial.print("aAAST");
    Serial.println(str);
}

void Display_::countdown(uint16_t tenthsSec)
{
    DB(F("DISPLAY [countdown]: "));
    DBLN(tenthsSec);
    memset(buf,0,13);   
    snprintf(buf, 12, "aAACD%04d---", tenthsSec);
    Serial.println(buf);
}

void Display_::winner(uint8_t n)
{
    DB(F("DISPLAY [winner]: "));
    DBLN(n);
    memset(buf,0,13);   
    snprintf(buf, 12, "aAAWN%d------", n);
    Serial.println(buf);
}

