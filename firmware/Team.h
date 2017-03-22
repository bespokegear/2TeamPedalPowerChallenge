#pragma once

#include <EMAVDivSampler.h>
#include <stdint.h>
#include "Player.h"

class Team {
public:
    Team(uint8_t adultPin, float childPin);
    void begin();
    void update();

    //! Reset Joules (also unfreezes player stats)
    void reset();

    //! Get Instantaneous Power in Watts
    float watts();
    float maxWatts();

    //! Get Energy in joules since last reset
    float joules();

    //! Freeze or unfreeze player stats
    void setFreeze(bool b);

private:
    Player _adultPlayer;
    Player _childPlayer;
    float _maxWatts;

};

