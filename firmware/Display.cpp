#include <Arduino.h>
#include <MutilaDebug.h>
#include "Display.h"

char buf[18];

void clearBuf()
{
    memset(buf, 0, 18);
}

void sendBuf(uint8_t len, char pad)
{
    for(uint8_t i=len; i<18; i++) {
        buf[i] = pad;
    }
    Serial.println(buf);
}

Display_ Display;

void Display_::begin()
{
    DBLN(F("Display.begin()"));
}

void Display_::clear()
{
    DBLN(F("Display.clear()"));
    clearBuf();
    snprintf(buf, 12, "aAACL");
    sendBuf(12, '-');
}

void Display_::countdown(uint8_t n)
{
    if (n>0) {
        DB(F("DISPLAY [countdown]: "));
        DBLN(n);
    } else {
        DBLN(F("DISPLAY [countdown]: GO!"));
    }
    clearBuf();
    snprintf(buf, 12, "aAACD%d", n);
    sendBuf(12, '-');
}

void Display_::say(const char* str)
{
    DB(F("DISPLAY [str - TODO]: "));
    DBLN(str);
    snprintf(buf, 17, "aAAST%s", str);
    clearBuf();
    snprintf(buf, 17, "aAAST%s", str);
    sendBuf(17, '#');
}

void Display_::countdown(uint16_t tenthsSec)
{
    DB(F("DISPLAY [countdown]: "));
    DBLN(tenthsSec);
    clearBuf();
    snprintf(buf, 12, "aAACD%04d", tenthsSec);
    sendBuf(12, '-');
}

void Display_::winner(uint8_t n)
{
    DB(F("DISPLAY [winner]: "));
    DBLN(n);
    clearBuf();
    snprintf(buf, 12, "aAAWN%d", n);
    sendBuf(12, '-');
}

