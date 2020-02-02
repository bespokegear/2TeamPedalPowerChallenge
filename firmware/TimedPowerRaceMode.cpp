#include <MutilaDebug.h>
#include <Millis.h>
#include "TimedPowerRaceMode.h"
#include "Display.h"
#include "SWGreen.h"
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
}

void TimedPowerRaceMode_::modeStart()
{
    DBLN(F("TimedPowerRaceMode::start()"));
    raceStart = Millis();
    nextCounter = raceStart + COUNTER_ONSET_DELAY_MS;
    nextLED = raceStart;
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
    plot(Team1.maxWatts() / MaxPowerWatts.get(), Team2.maxWatts() / MaxPowerWatts.get());
}

void TimedPowerRaceMode_::modeUpdate()
{
    updateCounter();
    updateLEDs();
}

bool TimedPowerRaceMode_::isFinished()
{
    return SWGreen.tapped() || Millis() > raceStart + (1000*RaceTimeSeconds.get());
}

void TimedPowerRaceMode_::updateCounter()
{
    if (Millis() > nextCounter) {
        nextCounter = Millis() + TIMED_POWER_COUNTER_MS;
        uint16_t tenths = (Millis()-raceStart)/ 100;
        Display.timer((uint16_t)((RaceTimeSeconds.get()*10)-tenths));
    }
}

void TimedPowerRaceMode_::updateLEDs()
{
    if (Millis() > nextLED) {
        nextLED = Millis() + TIMED_POWER_LED_MS;
        // Expressed as 0.0 - 1.0
        float p1 = Team1.watts() / MaxPowerWatts.get();
        float p2 = Team2.watts() / MaxPowerWatts.get();
        plot(Team1.watts() / MaxPowerWatts.get(), Team2.watts() / MaxPowerWatts.get());
    }
}

void TimedPowerRaceMode_::plot(float p1, float p2) {
    LED1.graph(p1, TIMED_POWER_TEAM1_COLOR, true, TIMED_POWER_TEAM1_PEAKCOLOR);
    LED2.graph(p2, TIMED_POWER_TEAM2_COLOR, true, TIMED_POWER_TEAM2_PEAKCOLOR);
}
