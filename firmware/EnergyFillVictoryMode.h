#pragma once

#include <Mode.h>
#include <stdint.h>

class EnergyFillVictoryMode_ : public Mode {
public:
    EnergyFillVictoryMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();

private:
    bool counting;
    uint8_t count;
    unsigned long startMillis;

};

extern EnergyFillVictoryMode_ EnergyFillVictoryMode;
