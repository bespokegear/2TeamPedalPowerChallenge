#include <MutilaDebug.h>
#include "EnergyFillWaitMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "CorrectedMillis.h"
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
    Display.say("Hai!");
    clearTime = millis() + 1500;
}

void EnergyFillWaitMode_::modeStop()
{
    DBLN(F("EnergyFillWaitMode::stop()"));
}

void EnergyFillWaitMode_::modeUpdate()
{
    if (clearTime > 0 && millis() >= clearTime) {
        Display.clear();
        clearTime = 0;
    }
}

bool EnergyFillWaitMode_::isFinished()
{
    return SWRed.tapped();
}

