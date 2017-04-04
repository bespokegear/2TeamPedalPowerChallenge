#include <MutilaDebug.h>
#include <Millis.h>
#include "WaitMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "LED1.h"
#include "LED2.h"
#include "Display.h"

WaitMode_ WaitMode;

WaitMode_::WaitMode_() 
{
}

void WaitMode_::begin()
{
    DBLN(F("WaitMode::begin()"));
}

void WaitMode_::modeStart()
{
    DBLN(F("WaitMode::start()"));
    wipeRow = LED1.numRows();
    lastWipe = Millis();
    Display.say("Energy Mode");
}

void WaitMode_::modeStop()
{
    DBLN(F("WaitMode::stop()"));
    LED1.setBrightness(255);
    LED2.setBrightness(255);
}

void WaitMode_::modeUpdate()
{
    if (Millis() >= lastWipe + 35 && wipeRow >= 0) {
        LED1.setRowColor(wipeRow, 0, true);
        LED2.setRowColor(wipeRow, 0, true);
        lastWipe = Millis();
        wipeRow--;
    }
}

bool WaitMode_::isFinished()
{
    return SWRed.tapped();
}

