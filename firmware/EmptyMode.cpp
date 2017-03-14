#include <MutilaDebug.h>
#include "EmptyMode.h"

EmptyMode_ EmptyMode;

EmptyMode_::EmptyMode_() 
{
}

void EmptyMode_::modeStart()
{
    DBLN(F("EmptyMode::start()"));
}

void EmptyMode_::modeStop()
{
    DBLN(F("EmptyMode::stop()"));
}


