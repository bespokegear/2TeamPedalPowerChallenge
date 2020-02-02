#include <Arduino.h>
#include <EEPROM.h>
#include <Mutila.h>
#include <MutilaDebug.h>
#include <Adafruit_NeoPixel.h>
#include <MemoryFree.h>
#include <stdint.h>

#include "MemDebug.h"
#include "Config.h"
#include "SWA.h"
//#include "SWB.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "Team1.h"
#include "Team2.h"
#include "EnergyFillMode.h"
#include "TimedPowerMode.h"
#include "TimedEnergyMode.h"
#include "SettingsMode.h"
#include "Display.h"
#include "LED1.h"
#include "LED2.h"

int8_t modeIdx = -1;
uint8_t idx = START_MODE;   // Sets the starting mode
Mode* modes[] = { &EnergyFillMode, &TimedPowerMode, &TimedEnergyMode, &SettingsMode };
Mode* mode = NULL;

// Added these for entering change_mode
bool       change_mode_flag = false;
long int   change_mode_timer;

void switchMode(Mode* newMode)
{
  // Clear buttons
  SWRed.tapped();
  SWGreen.tapped();
  if (mode != NULL) {
    mode->stop();
  }
  mode = newMode;
  mode->start();
}

void modeCheck()
{
  // Want to update this using SWA on pin 11 - scroll through the settings
  // cycle through mode 0-3 (modeIdx)?
  // SWB and SWA gave 2 bit digital 00, 01, 10,11
  // Giving four modes.
  // From here: Mode* modes[] = { &EnergyFillMode, &TimedPowerMode, &TimedEnergyMode, &SettingsMode };
  // This line is NOT used
  //uint8_t idx = (SWB.on() << 1) + SWA.on();
  // This line sets the mode (0-3) to set the mode
  //uint8_t idx = 0;
  
  if(SWA.tapped()) {
    // Want to go to change the mode here:
    // Scroll through the list
    idx = idx+1;
    if(idx>=SETTINGS_COUNT)
    {
      idx=0;  // Reset the idx
    }      
  }

  if (idx != modeIdx) {
    modeIdx = idx;
    DB(F("Switch mode IDX="));
    DBLN(modeIdx);
    switchMode(modes[modeIdx]);
  }
}

void setup()
{
  Serial.begin(115200);
  delay(300);

  // Use external reference voltage for analog reads
  analogReference(EXTERNAL);

  MEMDB();    // Memory debug output
  SWA.begin();
  //SWB.begin();
  SWRed.begin();
  SWGreen.begin();
  Team1.begin();
  Team2.begin();
  Display.begin();
  MEMDB();
  LED1.begin();
  LED2.begin();
  MEMDB();

  // Init modes.  Modes with child modes are responsible for calling
  // begin() for their children
  TimedPowerMode.begin();
  EnergyFillMode.begin();
  TimedEnergyMode.begin();
  SettingsMode.begin();
  MEMDB();

  // Set the mode based on the position of SWA and SWB
  // This sets modeIdx
  modeCheck();

  DBLN(F("setup:E"));
}

void loop()
{
  SWA.update();
  //SWB.update();
  SWRed.update();
  SWGreen.update();
  Team1.update();
  Team2.update();
  mode->update();

  modeCheck();
  // Set the mode based on the position of SWA and SWB
  // This sets modeIdx

  return;
  DB(F("SWARG:"));
  DB(SWA.on());
  // DB(SWB.on());
  DB(SWRed.on());
  DB(SWGreen.on());
  DB(F(" Team1 P="));
  DB(Team1.watts());
  DB(F(" E="));
  DB(Team1.joules());
  DB(F(" Team2 P="));
  DB(Team2.watts());
  DB(F(" E="));
  DBLN(Team2.joules());
}
