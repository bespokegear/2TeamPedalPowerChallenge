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
    wipeRow = LED1.numRows();
    lastWipe = millis();
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

    if (millis() >= lastWipe + 35 && wipeRow >= 0) {
        LED1.setRowColor(wipeRow, 0);
        LED2.setRowColor(wipeRow, 0);
        lastWipe = millis();
        wipeRow--;
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

