#include <MutilaDebug.h>
#include "CountdownMode.h"
#include "Display.h"
#include "SWRed.h"
#include "Config.h"
#include <Millis.h>
#include "LED1.h"
#include "LED2.h"

CountdownMode_ CountdownMode;

CountdownMode_::CountdownMode_() 
{
}

void CountdownMode_::begin()
{
    DBLN(F("CountdownMode::begin()"));
}

void CountdownMode_::modeStart()
{
    DBLN(F("CountdownMode::start()"));
    setCount(COUNTDOWN_START);
    LED1.clear(true);
    LED2.clear(true);
}

void CountdownMode_::modeStop()
{
    DBLN(F("CountdownMode::stop()"));
}

void CountdownMode_::modeUpdate()
{
    if (SWRed.tapped()) {
        setCount(0);
        return;
    }

    if (Millis() > lastCount + 1000 && count > 0) {
        setCount(count - 1);
    }
}

void CountdownMode_::setCount(uint8_t c)
{
    count = c;
    lastCount = Millis();
    Display.countdown(c);
}

bool CountdownMode_::isFinished()
{
    return count == 0;
}

