#pragma once

#include <Mode.h>
#include <stdint.h>

class TimedPowerWaitMode_ : public Mode {
public:
    TimedPowerWaitMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();

private:
    int16_t wipeRow;
    unsigned long lastWipe;

};

extern TimedPowerWaitMode_ TimedPowerWaitMode;
