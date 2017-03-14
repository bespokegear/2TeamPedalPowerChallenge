#include <Arduino.h>
#include <Mutila.h>
#include <MutilaDebug.h>

#include "Heartbeat.h"
#include "Config.h"
#include "SWA.h"
#include "SWB.h"

void setup()
{
    Serial.begin(115200);
    delay(300);

    Heartbeat.begin();
    SWA.begin();
    SWB.begin();
}

void loop()
{
    SWA.update();
    SWB.update();
    DB(F("SWAB12:"));
    DB(SWA.on());
    DBLN(SWB.on());
    //DBLN(SW1.on());
    //DBLN(SW2.on());
}


