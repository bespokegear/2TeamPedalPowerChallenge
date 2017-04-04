#include <MutilaDebug.h>
#include "TimedEnergyMode.h"
#include "TimedEnergyWaitMode.h"
#include "CountdownMode.h"
#include "TimedEnergyRaceMode.h"
#include "TimedEnergyVictoryMode.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "MemDebug.h"

TimedEnergyMode_ TimedEnergyMode;

TimedEnergyMode_::TimedEnergyMode_() 
{
}

void TimedEnergyMode_::begin()
{
    DBLN(F("TimedEnergyMode::begin()"));
    TimedEnergyWaitMode.begin();
    CountdownMode.begin();
    TimedEnergyRaceMode.begin();
    TimedEnergyVictoryMode.begin();
}

void TimedEnergyMode_::modeStart()
{
    DBLN(F("TimedEnergyMode::start()"));
    // we start waiting for a button to press
    switchMode(&TimedEnergyWaitMode);
}

void TimedEnergyMode_::modeStop()
{
    DBLN(F("TimedEnergyMode::stop()"));
}

void TimedEnergyMode_::modeUpdate()
{
    MEMDB();
    if (mode->isFinished()) {
        if (mode == &TimedEnergyWaitMode) {
            switchMode(&CountdownMode);
        } else if (mode == &CountdownMode) {
            switchMode(&TimedEnergyRaceMode);
        } else if (mode == &TimedEnergyRaceMode) {
            switchMode(&TimedEnergyVictoryMode);
        } else {
            switchMode(&TimedEnergyWaitMode);
        }
    } else {
        mode->update();
    }
}


