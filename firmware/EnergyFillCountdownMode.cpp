#include <MutilaDebug.h>
#include "EnergyFillCountdownMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "CorrectedMillis.h"
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
    LED1.clear();
    LED2.clear();
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

    if (millis() > lastCount + 1000 && count > 0) {
        setCount(count - 1);
    }
}

void EnergyFillCountdownMode_::setCount(uint8_t c)
{
    count = c;
    lastCount = millis();
    Display.countdown(c);
}

bool EnergyFillCountdownMode_::isFinished()
{
    return count == 0;
}

