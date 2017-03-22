#include <math.h>
#include <MutilaDebug.h>
#include <Millis.h>
#include "TimedPowerVictoryMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "Team1.h"
#include "Team2.h"
#include "LED1.h"
#include "LED2.h"

TimedPowerVictoryMode_ TimedPowerVictoryMode;

TimedPowerVictoryMode_::TimedPowerVictoryMode_() 
{
}

void TimedPowerVictoryMode_::begin()
{
    DBLN(F("TimedPowerVictoryMode::begin()"));
    setUpdatePeriod(50);
}

void TimedPowerVictoryMode_::modeStart()
{
    DBLN(F("TimedPowerVictoryMode::start()"));
    DB(F("Power T1="));
    DB(Team1.maxWatts());
    DB(F(" T2="));
    DBLN(Team2.maxWatts());
    startMillis = Millis();
    float diff = Team2.maxWatts() - Team1.maxWatts();
    if (diff<0) diff*=-1;
    if (diff <= TIMED_POWER_TIE_DIFF_W) {
        winner = 0;
    } else if (Team1.maxWatts() > Team2.maxWatts()) {
        winner = 1;
    } else {
        winner = 2;
    }
    Display.winner(winner);
    setUpdatePeriod(50);
}

void TimedPowerVictoryMode_::modeStop()
{
    DBLN(F("TimedPowerVictoryMode::stop()"));
}

void TimedPowerVictoryMode_::modeUpdate()
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

bool TimedPowerVictoryMode_::isFinished()
{
    return SWRed.tapped();
}

void TimedPowerVictoryMode_::throb(RIBargraphDisplay* led)
{
    double dim = sinf(((Millis()-startMillis+1571)%3142)/1000.);
    dim *= 0.85;
    dim += 0.15;
    led->setBrightness(dim*255);
}

void TimedPowerVictoryMode_::fade(RIBargraphDisplay* led)
{
    float dim = (Millis() - startMillis)/1500.0;
    if (dim>1) dim=1;
    dim = 1.-dim;
    dim *= 0.85;
    dim += 0.15;
    led->setBrightness(dim*255);
}

