#include <Arduino.h>
#include <Mutila.h>
#include <MutilaDebug.h>

#include "Heartbeat.h"
#include "Config.h"
#include "SWA.h"
#include "SWB.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "Team1.h"
#include "Team2.h"

void setup()
{
    Serial.begin(115200);
    delay(300);

    // Use external reference voltage for analog reads
    analogReference(EXTERNAL);

    Heartbeat.begin();
    SWA.begin();
    SWB.begin();
    SWRed.begin();
    SWGreen.begin();
    Team1.begin();
    Team2.begin();

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

    if (SWRed.tapped()) {
        DBLN(F("RESET ENERGY"));
        Team1.reset();
    }

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


