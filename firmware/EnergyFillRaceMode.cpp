#include <MutilaDebug.h>
#include "EnergyFillRaceMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "CorrectedMillis.h"
#include "Team1.h"
#include "Team2.h"

EnergyFillRaceMode_ EnergyFillRaceMode;

EnergyFillRaceMode_::EnergyFillRaceMode_() 
{
}

void EnergyFillRaceMode_::begin()
{
    DBLN(F("EnergyFillRaceMode::begin()"));
    // We'll only update the LED displays once every 100 ms
    //
    setUpdatePeriod(ENERGY_FILL_LED_UPDATE_MS);
}

void EnergyFillRaceMode_::modeStart()
{
    DBLN(F("EnergyFillRaceMode::start()"));
    raceOver = false;
    Team1.reset();
    Team2.reset();
    updateLEDs();
}

void EnergyFillRaceMode_::modeStop()
{
    DBLN(F("EnergyFillRaceMode::stop()"));
}

void EnergyFillRaceMode_::modeUpdate()
{
    if (SWRed.tapped()) {
        //raceOver = true;
    }

    if (Team1.joules() >= ENERGY_FILL_GOAL_JOULES || 
        Team2.joules() >= ENERGY_FILL_GOAL_JOULES) {
        raceOver = true;
    }

    updateLEDs();
}

bool EnergyFillRaceMode_::isFinished()
{
    return raceOver;
}

void EnergyFillRaceMode_::updateLEDs()
{
    DB(F("updateLEDs t1="));
    // Expressed as 0.0 - 1.0
    float t1Complete = Team1.joules() / ENERGY_FILL_GOAL_JOULES;
    float t2Complete = Team2.joules() / ENERGY_FILL_GOAL_JOULES;
    DB(t1Complete*100);
    DB(F("% t2="));
    DB(t2Complete*100);
    DBLN('%');
}

