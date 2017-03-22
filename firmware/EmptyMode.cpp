#include <MutilaDebug.h>
#include "EmptyMode.h"
#include "Display.h"
#include "MemDebug.h"
#include "Config.h"

EmptyMode_ EmptyMode;

EmptyMode_::EmptyMode_() 
{
}

void EmptyMode_::modeStart()
{
    DBLN(F("EmptyMode::start()"));
    Display.say("Empty Mode");
}

void EmptyMode_::modeStop()
{
    DBLN(F("EmptyMode::stop()"));
}

void EmptyMode_::modeUpdate()
{
    MEMDB();
}

