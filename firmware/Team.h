#pragma once

#include <EMAVDivSampler.h>
#include <stdint.h>
#include "Player.h"

class Team {
public:
    Team(uint8_t adultPin, float childPin);
    void begin();
    void update();

    //! Reset Joules
    void reset();

    //! Get Instantaneous Power in Watts
    float watts();

    //! Get Energy in joules since last reset
    float joules();

private:
    Player _adultPlayer;
    Player _childPlayer;

};

