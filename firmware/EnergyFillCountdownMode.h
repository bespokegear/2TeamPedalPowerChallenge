#pragma once

#include <Mode.h>
#include <stdint.h>

class EnergyFillCountdownMode_ : public Mode {
public:
    EnergyFillCountdownMode_();
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

extern EnergyFillCountdownMode_ EnergyFillCountdownMode;
