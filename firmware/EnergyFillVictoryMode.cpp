#include <MutilaDebug.h>
#include "EnergyFillVictoryMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "CorrectedMillis.h"
#include "Team1.h"
#include "Team2.h"

EnergyFillVictoryMode_ EnergyFillVictoryMode;

EnergyFillVictoryMode_::EnergyFillVictoryMode_() 
{
}

void EnergyFillVictoryMode_::begin()
{
    DBLN(F("EnergyFillVictoryMode::begin()"));
    setUpdatePeriod(500);
}

void EnergyFillVictoryMode_::modeStart()
{
    DBLN(F("EnergyFillVictoryMode::start()"));
    startMillis = millis();
    if (Team1.joules() > Team2.joules()) {
        Display.winner(1);
    } else if (Team1.joules() < Team2.joules()) {
        Display.winner(2);
    } else {
        // It's a tie
        Display.winner(0);
    }
}

void EnergyFillVictoryMode_::modeStop()
{
    DBLN(F("EnergyFillVictoryMode::stop()"));
}

void EnergyFillVictoryMode_::modeUpdate()
{
    // TODO: animate victory
    DB(F("Energy Victory T1="));
    DB(Team1.joules());
    DB(F(" T2="));
    DBLN(Team2.joules());
}

bool EnergyFillVictoryMode_::isFinished()
{
    return SWRed.tapped() || millis() > startMillis + (ENERGY_FILL_VICTORY_SECONDS*1000);
}

