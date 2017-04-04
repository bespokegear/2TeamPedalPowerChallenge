#include <MutilaDebug.h>
#include "TimedPowerMode.h"
#include "WaitMode.h"
#include "CountdownMode.h"
#include "TimedPowerRaceMode.h"
#include "TimedPowerVictoryMode.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "MemDebug.h"
#include "Display.h"

TimedPowerMode_ TimedPowerMode;

TimedPowerMode_::TimedPowerMode_() 
{
}

void TimedPowerMode_::begin()
{
    DBLN(F("TimedPowerMode::begin()"));
    WaitMode.begin();
    CountdownMode.begin();
    TimedPowerRaceMode.begin();
    TimedPowerVictoryMode.begin();
}

void TimedPowerMode_::modeStart()
{
    DBLN(F("TimedPowerMode::start()"));
    // we start waiting for a button to press
    switchMode(&WaitMode);
    announce();
}

void TimedPowerMode_::modeStop()
{
    DBLN(F("TimedPowerMode::stop()"));
}

void TimedPowerMode_::modeUpdate()
{
    MEMDB();
    if (mode->isFinished()) {
        if (mode == &WaitMode) {
            switchMode(&CountdownMode);
        } else if (mode == &CountdownMode) {
            switchMode(&TimedPowerRaceMode);
        } else if (mode == &TimedPowerRaceMode) {
            switchMode(&TimedPowerVictoryMode);
        } else {
            switchMode(&WaitMode);
            announce();
        }
    } else {
        mode->update();
    }
}

void TimedPowerMode_::announce()
{
    Display.say("Power Race");
}

