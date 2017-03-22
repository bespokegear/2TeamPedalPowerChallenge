#include <MutilaDebug.h>
#include <Millis.h>
#include "TimedEnergyWaitMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "LED1.h"
#include "LED2.h"
#include "Display.h"

TimedEnergyWaitMode_ TimedEnergyWaitMode;

TimedEnergyWaitMode_::TimedEnergyWaitMode_() 
{
}

void TimedEnergyWaitMode_::begin()
{
    DBLN(F("TimedEnergyWaitMode::begin()"));
}

void TimedEnergyWaitMode_::modeStart()
{
    DBLN(F("TimedEnergyWaitMode::start()"));
    wipeRow = LED1.numRows();
    lastWipe = Millis();
    Display.say("Timed Energy");
}

void TimedEnergyWaitMode_::modeStop()
{
    DBLN(F("TimedEnergyWaitMode::stop()"));
    LED1.setBrightness(255);
    LED2.setBrightness(255);
}

void TimedEnergyWaitMode_::modeUpdate()
{
    if (Millis() >= lastWipe + 35 && wipeRow >= 0) {
        LED1.setRowColor(wipeRow, 0, true);
        LED2.setRowColor(wipeRow, 0, true);
        lastWipe = Millis();
        wipeRow--;
    }
}

bool TimedEnergyWaitMode_::isFinished()
{
    return SWRed.tapped();
}

