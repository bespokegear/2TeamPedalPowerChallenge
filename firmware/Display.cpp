#include <Arduino.h>
#include <MutilaDebug.h>
#include "Config.h"
#include "Display.h"
#include "LED1.h"
#include "LED2.h"
#include "Settings.h"

char buf[DISPLAY_BUF_LEN];

void clearBuf()
{
    memset(buf, 0, DISPLAY_BUF_LEN);
}

void sendBuf(uint8_t len, char pad)
{
    for(uint8_t i=len; i<DISPLAY_BUF_LEN; i++) {
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
        // Also want to display on the LED a 3 2 1 countdown
        // TO DO
        // Value is 0-1 from base to fill for LEDs
        float cd = float(n)*(1.0/(PanelsPerBargraph.get()*30.0));
        LED1.graph(cd, COUNTDOWN_COLOUR, false);
        LED2.graph(cd, COUNTDOWN_COLOUR, false); 
        //Serial.println(cd);   //debug
               
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
    snprintf(buf, DISPLAY_BUF_LEN-1, "aAAST%s", str);
    clearBuf();
    delay(100);
    snprintf(buf, DISPLAY_BUF_LEN-1, "aAAST%s", str);
    sendBuf(17, '#');
}

void Display_::timer(uint16_t tenthsSec)
{
    DB(F("DISPLAY [timer]: "));
    DBLN(tenthsSec);
    clearBuf();
    snprintf(buf, 12, "aAATI%04d", tenthsSec);
    sendBuf(12, '-');
}

void Display_::winner(uint8_t n)
{
    DB(F("DISPLAY [winner]: "));
    DBLN(n);
    clearBuf();
    delay(50);    // Added to stop overwrite on serial
    snprintf(buf, 12, "aAAWN%d", n);
    sendBuf(12, '-');
}
