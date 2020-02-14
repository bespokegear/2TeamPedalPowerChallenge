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
    void updateCounter();
    void updateLEDs();
    void plot(float p1, float p2);

private:
    unsigned long raceStart;
    unsigned long nextCounter;
    unsigned long nextLED;
    unsigned long int shutdown_timer;
    
};

extern TimedPowerRaceMode_ TimedPowerRaceMode;
