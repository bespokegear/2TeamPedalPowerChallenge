#include <MutilaDebug.h>
#include <Millis.h>
#include "TimedPowerRaceMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include "Team1.h"
#include "Team2.h"
#include "LED1.h"
#include "LED2.h"
#include "Settings.h"

TimedPowerRaceMode_ TimedPowerRaceMode;

TimedPowerRaceMode_::TimedPowerRaceMode_() 
{
}

void TimedPowerRaceMode_::begin()
{
    DBLN(F("TimedPowerRaceMode::begin()"));
    // We'll only update the LED displays once every 100 ms
    //
    setUpdatePeriod(TIMED_POWER_LED_UPDATE_MS);
}

void TimedPowerRaceMode_::modeStart()
{
    DBLN(F("TimedPowerRaceMode::start()"));
    raceStart = Millis();
    raceOver = false;
    Team1.reset();
    Team2.reset();
    LED1.clearPeak();
    LED2.clearPeak();
    updateLEDs();
}

void TimedPowerRaceMode_::modeStop()
{
    DBLN(F("TimedPowerRaceMode::stop()"));
    Team1.setFreeze(true);
    Team2.setFreeze(true);
}

void TimedPowerRaceMode_::modeUpdate()
{
    if (SWRed.tapped()) {
        raceOver = true;
    }

    if (Millis() > raceStart + (1000*RaceTimeSeconds.get())) {
        raceOver = true;
    }

    updateLEDs();
}

bool TimedPowerRaceMode_::isFinished()
{
    return raceOver;
}

void TimedPowerRaceMode_::updateLEDs()
{
    // Expressed as 0.0 - 1.0
    float p1 = Team1.watts() / MaxPowerWatts.get();
    float p2 = Team2.watts() / MaxPowerWatts.get();
    DB(("TimedPower p1="));
    DB(p1);
    DB((" p2="));
    DBLN(p2);
    LED1.graph(p1, TIMED_POWER_TEAM1_COLOR, true, TIMED_POWER_TEAM1_PEAKCOLOR);
    LED2.graph(p2, TIMED_POWER_TEAM2_COLOR, true, TIMED_POWER_TEAM2_PEAKCOLOR);
}

