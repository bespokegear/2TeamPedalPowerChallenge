#pragma once

#include <Mode.h>
#include <stdint.h>

class TimedEnergyCountdownMode_ : public Mode {
public:
    TimedEnergyCountdownMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    void setCount(uint8_t c);
    bool isFinished();

private:
    bool counting;
    uint8_t count;
    int16_t wipeRow;
    unsigned long lastCount;
    unsigned long lastWipe;

};

extern TimedEnergyCountdownMode_ TimedEnergyCountdownMode;
