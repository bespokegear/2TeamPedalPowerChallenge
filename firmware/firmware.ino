#include <Arduino.h>
#include <Mutila.h>
#include <MutilaDebug.h>

#include "Heartbeat.h"
#include "Config.h"
#include "SWA.h"
#include "SWB.h"
#include "SWRed.h"
#include "SWGreen.h"

void setup()
{
    Serial.begin(115200);
    delay(300);

    Heartbeat.begin();
    SWA.begin();
    SWB.begin();
    SWRed.begin();
    SWGreen.begin();
}

void loop()
{
    Heartbeat.update();
    SWA.update();
    SWB.update();
    SWRed.update();
    SWGreen.update();
    DB(F("SWABRG:"));
    DB(SWA.on());
    DB(SWB.on());
    DB(SWRed.on());
    DBLN(SWGreen.on());
}


