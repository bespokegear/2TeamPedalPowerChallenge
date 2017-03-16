#include <MutilaDebug.h>
#include "EnergyFillWaitMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "CorrectedMillis.h"

EnergyFillWaitMode_ EnergyFillWaitMode;

EnergyFillWaitMode_::EnergyFillWaitMode_() 
{
}

void EnergyFillWaitMode_::begin()
{
    DBLN(F("EnergyFillWaitMode::begin()"));
}

void EnergyFillWaitMode_::modeStart()
{
    DBLN(F("EnergyFillWaitMode::start()"));
    Display.say("Hai!");
    counting = false;
    lastUpdate = 0;
}

void EnergyFillWaitMode_::modeStop()
{
    DBLN(F("EnergyFillWaitMode::stop()"));
}

void EnergyFillWaitMode_::modeUpdate()
{
    if (SWRed.tapped()) {
        if (!counting) {
            setCount(COUNTDOWN_START);
        } else {
            setCount(0);
            return;
        }
    }

    if (counting && millis() > lastUpdate + 1000 && count > 0) {
        setCount(count - 1);
    }

    // TODO: clear LED displays
}

void EnergyFillWaitMode_::setCount(uint8_t c)
{
    counting = true;
    count = c;
    lastUpdate = millis();
    Display.countdown(c);
}

bool EnergyFillWaitMode_::isFinished()
{
    return counting && count == 0;
}

