#include <MutilaDebug.h>
#include "EnergyFillMode.h"
#include "EnergyFillWaitMode.h"
#include "EnergyFillCountdownMode.h"
#include "EnergyFillRaceMode.h"
#include "EnergyFillVictoryMode.h"
#include "SWRed.h"
#include "SWGreen.h"

EnergyFillMode_ EnergyFillMode;

EnergyFillMode_::EnergyFillMode_() 
{
}

void EnergyFillMode_::begin()
{
    DBLN(F("EnergyFillMode::begin()"));
    EnergyFillWaitMode.begin();
    EnergyFillCountdownMode.begin();
    EnergyFillRaceMode.begin();
    EnergyFillVictoryMode.begin();
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
            switchMode(&EnergyFillCountdownMode);
        } else if (mode == &EnergyFillCountdownMode) {
            switchMode(&EnergyFillRaceMode);
        } else if (mode == &EnergyFillRaceMode) {
            switchMode(&EnergyFillVictoryMode);
        } else {
            switchMode(&EnergyFillWaitMode);
        }
    } else {
        mode->update();
    }
}


