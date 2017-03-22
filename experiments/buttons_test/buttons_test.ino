#include <Arduino.h>
#include <MutilaDebug.h>
#include <stdint.h>

#include "SWA.h"
#include "SWB.h"
#include "SWRed.h"
#include "SWGreen.h"

void setup()
{
    Serial.begin(115200);
    delay(300);

    SWA.begin();
    SWB.begin();
    SWRed.begin();
    SWGreen.begin();
}

void loop()
{
    SWA.update();
    SWB.update();
    SWRed.update();
    SWGreen.update();

    DB("SW A=");
    DB(SWA.on());
    DB(" SW B=");
    DB(SWB.on());
    DB(" SW Red=");
    DB(SWRed.on());
    DB(" SW Green=");
    DBLN(SWGreen.on());
}


