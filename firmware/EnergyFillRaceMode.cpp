#include <MutilaDebug.h>
#include <Millis.h>
#include "EnergyFillRaceMode.h"
#include "Display.h"
#include "SWGreen.h"
#include "Config.h"
#include "Team1.h"
#include "Team2.h"
#include "LED1.h"
#include "LED2.h"
#include "Settings.h"

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
  raceStart = Millis();
  shutdown_timer = millis();
  raceOver = false;
  Team1.reset();
  Team2.reset();
  updateLEDs();
}

void EnergyFillRaceMode_::modeStop()
{
  DBLN(F("EnergyFillRaceMode::stop()"));
  Team1.setFreeze(true);
  Team2.setFreeze(true);
}

void EnergyFillRaceMode_::modeUpdate()
{

  if (SWGreen.tapped()) {
    raceOver = true;
  }

  if (Team1.joules() >= EnergyRaceGoalJoules.get() ||
      Team2.joules() >= EnergyRaceGoalJoules.get()) {
    raceOver = true;
  }

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

bool EnergyFillRaceMode_::isFinished()
{
  return raceOver;
}

uint32_t getColor(float n)
{
  float rp, bp;
  rp = n - (5.0 / 6.0);
  if (rp < 0) rp = 0;
  rp *= 6;
  if (rp > 1) rp = 1;

  bp = n - (2.0 / 3.0);
  if (bp < 0) bp = 0;
  bp *= 4;
  if (bp > 1) bp = 1;
  bp = 1 - bp;

  uint8_t r = rp * 255;
  uint8_t g = 0;
  uint8_t b = bp * 255;
  uint32_t rgb = r;

  rgb <<= 8;
  rgb += g;
  rgb <<= 8;
  rgb += b;
  return rgb;
}

void EnergyFillRaceMode_::updateLEDs()
{
  // Expressed as 0.0 - 1.0
  float t1Complete = Team1.joules() / EnergyRaceGoalJoules.get();
  float t2Complete = Team2.joules() / EnergyRaceGoalJoules.get();
  /*
    DB(F("updateLEDs T1:"));
    DB(Team1.watts());
    DB(F("W/"));
    DB(Team1.joules());
    DB(F("J/"));
    DB(EnergyRaceGoalJoules.get());
    DB('=');
    DB(t1Complete);
    DB(F(" T2:"));
    DB(Team2.watts());
    DB(F("W/"));
    DB(Team2.joules());
    DB(F("J/"));
    DB(EnergyRaceGoalJoules.get());
    DB('=');
    DB(t2Complete);
    DB(F(" elapsed="));
    DBLN((Millis()-raceStart)/1000);
  */
  LED1.graph(t1Complete, getColor(t1Complete), false);
  LED2.graph(t2Complete, getColor(t2Complete), false);
}
