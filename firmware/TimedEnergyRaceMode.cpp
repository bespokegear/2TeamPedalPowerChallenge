#include <MutilaDebug.h>
#include <Millis.h>
#include "TimedEnergyRaceMode.h"
#include "Display.h"
#include "SWGreen.h"
#include "Config.h"
#include "Team1.h"
#include "Team2.h"
#include "LED1.h"
#include "LED2.h"
#include "Settings.h"

TimedEnergyRaceMode_ TimedEnergyRaceMode;

TimedEnergyRaceMode_::TimedEnergyRaceMode_() 
{
}

void TimedEnergyRaceMode_::begin()
{
    DBLN(F("TimedEnergyRaceMode::begin()"));
}

void TimedEnergyRaceMode_::modeStart()
{
    DBLN(F("TimedEnergyRaceMode::start()"));
    raceStart = Millis();
    nextCounter = raceStart + COUNTER_ONSET_DELAY_MS;
    nextLED = raceStart;
    Team1.reset();
    Team2.reset();
    LED1.clearPeak();
    LED2.clearPeak();
    updateLEDs();
}

void TimedEnergyRaceMode_::modeStop()
{
    DBLN(F("TimedEnergyRaceMode::stop()"));
    Team1.setFreeze(true);
    Team2.setFreeze(true);
}

void TimedEnergyRaceMode_::modeUpdate()
{
  updateCounter();
  
  // Timed reset mode.
  // Need to have Team1 and Team2 at 0 for a certain length of time (LED_TIMER_DELAY_MS)
  if (Team1.watts() > 1 || Team2.watts() > 1)
  {
    // Reset the timer
    shutdown_timer = millis();
  }
  if ( millis() >= (shutdown_timer + LED_TIMER_DELAY_MS) )
  {
    // Only get here is team1 and team2 are zero
    // reset otherwise...
    // Here want to blank the LEDs
    LED1.clear(true);
    LED2.clear(true);
    //Serial.println("Blank LEDs"); DEBUG Line
  }
  else
  {
    updateLEDs();   // Want to move this to only happen if LEDs NOT blanked...
  }
  

}

bool TimedEnergyRaceMode_::isFinished()
{
    return SWGreen.tapped() || Millis() > raceStart + (1000*RaceTimeSeconds.get());
}

void TimedEnergyRaceMode_::updateCounter()
{
    if (Millis() > nextCounter) {
        nextCounter = Millis() + TIMED_POWER_COUNTER_MS;
        uint16_t tenths = (Millis()-raceStart)/ 100;
        Display.timer((uint16_t)((RaceTimeSeconds.get()*10)-tenths));
    }
}

void TimedEnergyRaceMode_::updateLEDs()
{
    if (Millis() > nextLED) {
        nextLED = Millis() + TIMED_POWER_LED_MS;
        // Expressed as 0.0 - 1.0
        float j1 = Team1.joules() / EnergyRaceGoalJoules.get();
        float j2 = Team2.joules() / EnergyRaceGoalJoules.get();
        DB(("TimedEnergy j1="));
        DB(j1);
        DB((" j2="));
        DBLN(j2);
        LED1.graph(j1, TIMED_POWER_TEAM1_COLOR, false);
        LED2.graph(j2, TIMED_POWER_TEAM2_COLOR, false);
    }
}
