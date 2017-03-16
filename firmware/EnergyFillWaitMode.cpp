#include <MutilaDebug.h>
#include "EnergyFillWaitMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "CorrectedMillis.h"

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
}

void EnergyFillWaitMode_::modeStop()
{
    DBLN(F("EnergyFillWaitMode::stop()"));
}

bool EnergyFillWaitMode_::isFinished()
{
    return SWRed.tapped();
}

