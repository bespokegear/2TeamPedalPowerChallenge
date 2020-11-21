#pragma once

#include <Mode.h>
#include <stdint.h>
#include "RIBargraphDisplay.h"

class EnergyFillVictoryMode_ : public Mode {
public:
    EnergyFillVictoryMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();
    void fade(RIBargraphDisplay* led);
    void throb(RIBargraphDisplay* led);

private:
    bool counting;
    uint8_t count;
    unsigned long startMillis;
    uint8_t winner;
    float bright1;
    float bright2;
    unsigned long int shutdown_timer;

};

extern EnergyFillVictoryMode_ EnergyFillVictoryMode;
