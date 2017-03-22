#pragma once

#include <Mode.h>
#include <stdint.h>

class TimedEnergyRaceMode_ : public Mode {
public:
    TimedEnergyRaceMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();
    void updateCounter();
    void updateLEDs();

private:
    unsigned long raceStart;
    unsigned long nextCounter;
    unsigned long nextLED;

};

extern TimedEnergyRaceMode_ TimedEnergyRaceMode;
