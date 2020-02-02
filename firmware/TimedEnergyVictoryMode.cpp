#include <math.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "TimedEnergyVictoryMode.h"
#include "Display.h"
#include "SWGreen.h"
#include "Config.h"
#include "Team1.h"
#include "Team2.h"
#include "LED1.h"
#include "LED2.h"

TimedEnergyVictoryMode_ TimedEnergyVictoryMode;

TimedEnergyVictoryMode_::TimedEnergyVictoryMode_() 
{
}

void TimedEnergyVictoryMode_::begin()
{
    DBLN(F("TimedEnergyVictoryMode::begin()"));
    setUpdatePeriod(50);
}

void TimedEnergyVictoryMode_::modeStart()
{
    DBLN(F("TimedEnergyVictoryMode::start()"));
    DB(F("Energy T1="));
    DB(Team1.joules());
    DB(F(" T2="));
    DBLN(Team2.joules());
    startMillis = Millis();
    float diff = Team2.joules() - Team1.joules();
    if (diff<0) diff*=-1;
    if (diff <= TIMED_ENERGY_TIE_DIFF_J) {
        winner = 0;
    } else if (Team1.joules() > Team2.joules()) {
        winner = 1;
    } else {
        winner = 2;
    }
    Display.winner(winner);
    setUpdatePeriod(50);
}

void TimedEnergyVictoryMode_::modeStop()
{
    DBLN(F("TimedEnergyVictoryMode::stop()"));
}

void TimedEnergyVictoryMode_::modeUpdate()
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
}

bool TimedEnergyVictoryMode_::isFinished()
{
    return SWGreen.tapped();
}

void TimedEnergyVictoryMode_::throb(RIBargraphDisplay* led)
{
    double dim = sinf(((Millis()-startMillis+1571)%3142)/1000.);
    dim *= 0.85;
    dim += 0.15;
    led->setBrightness(dim*255);
}

void TimedEnergyVictoryMode_::fade(RIBargraphDisplay* led)
{
    float dim = (Millis() - startMillis)/1500.0;
    if (dim>1) dim=1;
    dim = 1.-dim;
    dim *= 0.85;
    dim += 0.15;
    led->setBrightness(dim*255);
}
