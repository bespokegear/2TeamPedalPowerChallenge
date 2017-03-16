#include <MutilaDebug.h>
#include "EnergyFillMode.h"
#include "EnergyFillWaitMode.h"
#include "EnergyFillRaceMode.h"

EnergyFillMode_ EnergyFillMode;

EnergyFillMode_::EnergyFillMode_() 
{
}

void EnergyFillMode_::begin()
{
    DBLN(F("EnergyFillMode::begin()"));
    EnergyFillWaitMode.begin();
}

void EnergyFillMode_::modeStart()
{
    DBLN(F("EnergyFillMode::start()"));
    // we start waiting for a button to press
    switchMode(&EnergyFillWaitMode);
}

void EnergyFillMode_::modeStop()
{
    DBLN(F("EnergyFillMode::stop()"));
}

void EnergyFillMode_::modeUpdate()
{
    if (mode->isFinished()) {
        if (mode == &EnergyFillWaitMode) {
            DBLN(F("End Count"));
            switchMode(&EnergyFillRaceMode);
        } else if (mode == &EnergyFillRaceMode) {
            DBLN(F("End Race"));
            switchMode(&EnergyFillWaitMode);
        }
    }

    // calls mode->update as long as mode isn't NULL
    mode->update();
}


