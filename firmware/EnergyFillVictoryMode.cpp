#include <math.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "EnergyFillVictoryMode.h"
#include "Display.h"
#include "SWGreen.h"
#include "Config.h"
#include "Team1.h"
#include "Team2.h"
#include "LED1.h"
#include "LED2.h"

EnergyFillVictoryMode_ EnergyFillVictoryMode;

EnergyFillVictoryMode_::EnergyFillVictoryMode_() 
{
}

void EnergyFillVictoryMode_::begin()
{
    DBLN(F("EnergyFillVictoryMode::begin()"));
    setUpdatePeriod(50);
}

void EnergyFillVictoryMode_::modeStart()
{
    DBLN(F("EnergyFillVictoryMode::start()"));
    DB(F("Energy T1="));
    DB(Team1.joules());
    DB(F(" T2="));
    DBLN(Team2.joules());
    startMillis = Millis();
    float diff = Team2.joules() - Team1.joules();
    if (diff<0) diff*=-1;
    if (diff <= ENERGY_RACE_TIE_DIFF_J) {
        winner = 0;
    } else if (Team1.joules() > Team2.joules()) {
        winner = 1;
    } else {
        winner = 2;
    }
    Display.winner(winner);
    setUpdatePeriod(50);
}

void EnergyFillVictoryMode_::modeStop()
{
    DBLN(F("EnergyFillVictoryMode::stop()"));
}

void EnergyFillVictoryMode_::modeUpdate()
{
    if (winner == 1) {
        throb(&LED1);
        fade(&LED2);
    } else if (winner == 2) {
        throb(&LED2);
        fade(&LED1);
    } else {
        throb(&LED1);
        throb(&LED2);
    }
    // Here want to shutdown the LEDs if been longer than a certain time.
    // If timer > max time then victorymode is finished....
}

bool EnergyFillVictoryMode_::isFinished()
{
    return SWGreen.tapped();
}

void EnergyFillVictoryMode_::throb(RIBargraphDisplay* led)
{
    double dim = sinf(((Millis()-startMillis+1571)%3142)/1000.);
    dim *= 0.85;
    dim += 0.15;
    led->setBrightness(dim*255);
}

void EnergyFillVictoryMode_::fade(RIBargraphDisplay* led)
{
    float dim = (Millis() - startMillis)/1500.0;
    if (dim>1) dim=1;
    dim = 1.-dim;
    dim *= 0.85;
    dim += 0.15;
    led->setBrightness(dim*255);
}
