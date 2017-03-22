#include <MutilaDebug.h>
#include "TimedPowerCountdownMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include <Millis.h>
#include "LED1.h"
#include "LED2.h"

TimedPowerCountdownMode_ TimedPowerCountdownMode;

TimedPowerCountdownMode_::TimedPowerCountdownMode_() 
{
}

void TimedPowerCountdownMode_::begin()
{
    DBLN(F("TimedPowerCountdownMode::begin()"));
}

void TimedPowerCountdownMode_::modeStart()
{
    DBLN(F("TimedPowerCountdownMode::start()"));
    setCount(COUNTDOWN_START);
    LED1.clear(true);
    LED2.clear(true);
}

void TimedPowerCountdownMode_::modeStop()
{
    DBLN(F("TimedPowerCountdownMode::stop()"));
}

void TimedPowerCountdownMode_::modeUpdate()
{
    if (SWRed.tapped()) {
        setCount(0);
        return;
    }

    if (Millis() > lastCount + 1000 && count > 0) {
        setCount(count - 1);
    }
}

void TimedPowerCountdownMode_::setCount(uint8_t c)
{
    count = c;
    lastCount = Millis();
    Display.countdown(c);
}

bool TimedPowerCountdownMode_::isFinished()
{
    return count == 0;
}

