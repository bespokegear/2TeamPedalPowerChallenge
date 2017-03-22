#pragma once

#include <Mode.h>
#include <stdint.h>

class EnergyFillRaceMode_ : public Mode {
public:
    EnergyFillRaceMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();
    void updateLEDs();

private:
    unsigned long raceStart;
    bool raceOver;

};

extern EnergyFillRaceMode_ EnergyFillRaceMode;
