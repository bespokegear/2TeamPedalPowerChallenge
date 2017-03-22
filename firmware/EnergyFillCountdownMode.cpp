#include <MutilaDebug.h>
#include "EnergyFillCountdownMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include <Millis.h>
#include "LED1.h"
#include "LED2.h"

EnergyFillCountdownMode_ EnergyFillCountdownMode;

EnergyFillCountdownMode_::EnergyFillCountdownMode_() 
{
}

void EnergyFillCountdownMode_::begin()
{
    DBLN(F("EnergyFillCountdownMode::begin()"));
}

void EnergyFillCountdownMode_::modeStart()
{
    DBLN(F("EnergyFillCountdownMode::start()"));
    setCount(COUNTDOWN_START);
    LED1.clear(true);
    LED2.clear(true);
}

void EnergyFillCountdownMode_::modeStop()
{
    DBLN(F("EnergyFillCountdownMode::stop()"));
}

void EnergyFillCountdownMode_::modeUpdate()
{
    if (SWRed.tapped()) {
        setCount(0);
        return;
    }

    if (Millis() > lastCount + 1000 && count > 0) {
        setCount(count - 1);
    }
}

void EnergyFillCountdownMode_::setCount(uint8_t c)
{
    count = c;
    lastCount = Millis();
    Display.countdown(c);
}

bool EnergyFillCountdownMode_::isFinished()
{
    return count == 0;
}

