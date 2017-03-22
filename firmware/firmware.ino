#include <Arduino.h>
#include <Mutila.h>
#include <MutilaDebug.h>
#include <Adafruit_NeoPixel.h>
#include <MemoryFree.h>
#include <stdint.h>

#include "MemDebug.h"
#include "Heartbeat.h"
#include "Config.h"
#include "SWA.h"
#include "SWB.h"
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
Mode* modes[] = { &EnergyFillMode, &TimedPowerMode, &TimedEnergyMode, &SettingsMode };
Mode* mode = NULL;

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
    uint8_t idx = (SWB.on() << 1) + SWA.on();
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

    MEMDB();
    Heartbeat.begin();
    SWA.begin();
    SWB.begin();
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
    modeCheck();

    DBLN(F("setup:E"));
}

void loop()
{
    Heartbeat.update();
    SWA.update();
    SWB.update();
    SWRed.update();
    SWGreen.update();
    Team1.update();
    Team2.update();
    mode->update();

    modeCheck();
    return;
    DB(F("SWABRG:"));
    DB(SWA.on());
    DB(SWB.on());
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


