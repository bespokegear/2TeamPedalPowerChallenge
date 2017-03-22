#include <MutilaDebug.h>
#include "TimedEnergyCountdownMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include <Millis.h>
#include "LED1.h"
#include "LED2.h"

TimedEnergyCountdownMode_ TimedEnergyCountdownMode;

TimedEnergyCountdownMode_::TimedEnergyCountdownMode_() 
{
}

void TimedEnergyCountdownMode_::begin()
{
    DBLN(F("TimedEnergyCountdownMode::begin()"));
}

void TimedEnergyCountdownMode_::modeStart()
{
    DBLN(F("TimedEnergyCountdownMode::start()"));
    setCount(COUNTDOWN_START);
    LED1.clear(true);
    LED2.clear(true);
}

void TimedEnergyCountdownMode_::modeStop()
{
    DBLN(F("TimedEnergyCountdownMode::stop()"));
}

void TimedEnergyCountdownMode_::modeUpdate()
{
    if (SWRed.tapped()) {
        setCount(0);
        return;
    }

    if (Millis() > lastCount + 1000 && count > 0) {
        setCount(count - 1);
    }
}

void TimedEnergyCountdownMode_::setCount(uint8_t c)
{
    count = c;
    lastCount = Millis();
    Display.countdown(c);
}

bool TimedEnergyCountdownMode_::isFinished()
{
    return count == 0;
}

