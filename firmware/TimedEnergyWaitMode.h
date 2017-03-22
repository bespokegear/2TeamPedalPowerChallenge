#pragma once

#include <Mode.h>
#include <stdint.h>

class TimedEnergyWaitMode_ : public Mode {
public:
    TimedEnergyWaitMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();

private:
    int16_t wipeRow;
    unsigned long lastWipe;

};

extern TimedEnergyWaitMode_ TimedEnergyWaitMode;
