#include <MutilaDebug.h>
#include "EnergyFillWaitMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "CorrectedMillis.h"
#include "LED1.h"
#include "LED2.h"
#include "Display.h"

EnergyFillWaitMode_ EnergyFillWaitMode;

EnergyFillWaitMode_::EnergyFillWaitMode_() 
{
}

void EnergyFillWaitMode_::begin()
{
    DBLN(F("EnergyFillWaitMode::begin()"));
}

void EnergyFillWaitMode_::modeStart()
{
    DBLN(F("EnergyFillWaitMode::start()"));
    wipeRow = LED1.numRows();
    lastWipe = millis();
    Display.say("Energy Mode");
}

void EnergyFillWaitMode_::modeStop()
{
    DBLN(F("EnergyFillWaitMode::stop()"));
    LED1.setBrightness(255);
    LED2.setBrightness(255);
}

void EnergyFillWaitMode_::modeUpdate()
{
    if (millis() >= lastWipe + 35 && wipeRow >= 0) {
        LED1.setRowColor(wipeRow, 0);
        LED2.setRowColor(wipeRow, 0);
        lastWipe = millis();
        wipeRow--;
    }
}

bool EnergyFillWaitMode_::isFinished()
{
    return SWRed.tapped();
}

