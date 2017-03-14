#pragma once

#include <EMAVDivSampler.h>
#include <stdint.h>

#include "Config.h"

//! \class Player
// A Player is a person on a bike.
// A Player's bike's generator is hooked up to an analog input via a potential divider. 
// A Player has a load associated with them (in ohms)
// All players have the same vdiv resistances (from Config.h)
// All players have the same vref value (from Config.h)
// All players sampling is done at the same rate (from Config.h)
// All players sampler use the same alpha (smoothing) value (from Config.h)
// From this we can measure: instantaneous voltage, V, power = V*V / load
class Player : public EMAVDivSampler {
public:
    Player(const uint8_t pin, const float loadOhms);
    void begin();
    float averageVolts();
    float lastVolts();
    float averageWatts();
    float lastWatts();
    void resetJoules();
    float joules();
    void update();

private:
    float _loadOhms;
    float _joules;

};

