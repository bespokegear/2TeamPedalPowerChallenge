#include <Arduino.h>
#include <MutilaDebug.h>
#include "Display.h"

Display_ Display;

void Display_::begin()
{
    DBLN(F("Display_.begin()"));
}

void Display_::countdown(uint8_t n)
{
    if (n>0) {
        DB(F("DISPLAY [countdown]: "));
        DBLN(n);
    } else {
        DBLN(F("DISPLAY [countdown]: GO!"));
    }
}

void Display_::say(const char* str)
{
    DB(F("DISPLAY [string]: "));
    DBLN(str);
}

