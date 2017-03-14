#include <Arduino.h>
#include <Mutila.h>
#include <MutilaDebug.h>

#include "Heartbeat.h"
#include "Config.h"
#include "SWA.h"
#include "SWB.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "Player.h"

Player Team1Adult(A0, 4.4);

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
    Team1Adult.begin();

}

void loop()
{
    Heartbeat.update();
    SWA.update();
    SWB.update();
    SWRed.update();
    SWGreen.update();
    Team1Adult.update();

    DB(F("SWABRG:"));
    DB(SWA.on());
    DB(SWB.on());
    DB(SWRed.on());
    DB(SWGreen.on());
    DB(F(" T1A v="));
    DB(Team1Adult.averageVolts());
    DB(F(" T1A p="));
    DB(Team1Adult.averageWatts());
    DB(F(" T1A j="));
    DBLN(Team1Adult.joules());
}


