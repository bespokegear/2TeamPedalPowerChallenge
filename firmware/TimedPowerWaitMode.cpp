#include <MutilaDebug.h>
#include <Millis.h>
#include "TimedPowerWaitMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "LED1.h"
#include "LED2.h"
#include "Display.h"

TimedPowerWaitMode_ TimedPowerWaitMode;

TimedPowerWaitMode_::TimedPowerWaitMode_() 
{
}

void TimedPowerWaitMode_::begin()
{
    DBLN(F("TimedPowerWaitMode::begin()"));
}

void TimedPowerWaitMode_::modeStart()
{
    DBLN(F("TimedPowerWaitMode::start()"));
    wipeRow = LED1.numRows();
    lastWipe = Millis();
    Display.say("Timed Power");
}

void TimedPowerWaitMode_::modeStop()
{
    DBLN(F("TimedPowerWaitMode::stop()"));
    LED1.setBrightness(255);
    LED2.setBrightness(255);
}

void TimedPowerWaitMode_::modeUpdate()
{
    if (Millis() >= lastWipe + 35 && wipeRow >= 0) {
        LED1.setRowColor(wipeRow, 0, true);
        LED2.setRowColor(wipeRow, 0, true);
        lastWipe = Millis();
        wipeRow--;
    }
}

bool TimedPowerWaitMode_::isFinished()
{
    return SWRed.tapped();
}

