#include <MutilaDebug.h>
#include "EnergyFillMode.h"
#include "WaitMode.h"
#include "CountdownMode.h"
#include "EnergyFillRaceMode.h"
#include "EnergyFillVictoryMode.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "MemDebug.h"
#include "Display.h"

EnergyFillMode_ EnergyFillMode;

EnergyFillMode_::EnergyFillMode_() 
{
}

void EnergyFillMode_::begin()
{
    DBLN(F("EnergyFillMode::begin()"));
    WaitMode.begin();
    CountdownMode.begin();
    EnergyFillRaceMode.begin();
    EnergyFillVictoryMode.begin();
}

void EnergyFillMode_::modeStart()
{
    DBLN(F("EnergyFillMode::start()"));
    // we start waiting for a button to press
    switchMode(&WaitMode);
    announce();
}

void EnergyFillMode_::modeStop()
{
    DBLN(F("EnergyFillMode::stop()"));
}

void EnergyFillMode_::modeUpdate()
{
    MEMDB();
    if (mode->isFinished()) {
        if (mode == &WaitMode) {
            switchMode(&CountdownMode);
        } else if (mode == &CountdownMode) {
            switchMode(&EnergyFillRaceMode);
        } else if (mode == &EnergyFillRaceMode) {
            switchMode(&EnergyFillVictoryMode);
        } else {
            switchMode(&WaitMode);
            announce();
        }
    } else {
        mode->update();
    }
}

void EnergyFillMode_::announce()
{
    Display.say("Energy Fill");
}


