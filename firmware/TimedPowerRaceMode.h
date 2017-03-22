#pragma once

#include <Mode.h>
#include <stdint.h>

class TimedPowerRaceMode_ : public Mode {
public:
    TimedPowerRaceMode_();
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

extern TimedPowerRaceMode_ TimedPowerRaceMode;
