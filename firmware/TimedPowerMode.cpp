#include <MutilaDebug.h>
#include "TimedPowerMode.h"
#include "TimedPowerWaitMode.h"
#include "TimedPowerCountdownMode.h"
#include "TimedPowerRaceMode.h"
#include "TimedPowerVictoryMode.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "MemDebug.h"

TimedPowerMode_ TimedPowerMode;

TimedPowerMode_::TimedPowerMode_() 
{
}

void TimedPowerMode_::begin()
{
    DBLN(F("TimedPowerMode::begin()"));
    TimedPowerWaitMode.begin();
    TimedPowerCountdownMode.begin();
    TimedPowerRaceMode.begin();
    TimedPowerVictoryMode.begin();
}

void TimedPowerMode_::modeStart()
{
    DBLN(F("TimedPowerMode::start()"));
    // we start waiting for a button to press
    switchMode(&TimedPowerWaitMode);
}

void TimedPowerMode_::modeStop()
{
    DBLN(F("TimedPowerMode::stop()"));
}

void TimedPowerMode_::modeUpdate()
{
    MEMDB();
    if (mode->isFinished()) {
        if (mode == &TimedPowerWaitMode) {
            switchMode(&TimedPowerCountdownMode);
        } else if (mode == &TimedPowerCountdownMode) {
            switchMode(&TimedPowerRaceMode);
        } else if (mode == &TimedPowerRaceMode) {
            switchMode(&TimedPowerVictoryMode);
        } else {
            switchMode(&TimedPowerWaitMode);
        }
    } else {
        mode->update();
    }
}


