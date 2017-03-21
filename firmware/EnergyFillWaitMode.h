#pragma once

#include <Mode.h>
#include <stdint.h>

class EnergyFillWaitMode_ : public Mode {
public:
    EnergyFillWaitMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();

private:
    unsigned long clearTime;

};

extern EnergyFillWaitMode_ EnergyFillWaitMode;
