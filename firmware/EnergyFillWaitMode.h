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
    int16_t wipeRow;
    unsigned long lastWipe;

};

extern EnergyFillWaitMode_ EnergyFillWaitMode;
