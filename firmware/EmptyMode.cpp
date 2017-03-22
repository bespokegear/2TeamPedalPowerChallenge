#include <MutilaDebug.h>
#include "EmptyMode.h"
#include "Display.h"
#include "Config.h"

EmptyMode_ EmptyMode;

EmptyMode_::EmptyMode_() 
{
}

void EmptyMode_::modeStart()
{
    DBLN(F("EmptyMode::start()"));
    delay(DISPLAY_FUDGE_MS);
    Display.say("Empty Mode");
}

void EmptyMode_::modeStop()
{
    DBLN(F("EmptyMode::stop()"));
}


