#include "Team.h"
#include "Config.h"

Team::Team(uint8_t adultPin, float childPin) :
    _adultPlayer(adultPin, PLAYER_ADULT_LOAD_OHM),
    _childPlayer(childPin, PLAYER_CHILD_LOAD_OHM)
{
}

void Team::begin()
{
    _adultPlayer.begin();
    _childPlayer.begin();
}

void Team::update()
{
    _adultPlayer.update();
    _childPlayer.update();
}

//! Reset Joules & unfreeze
void Team::reset()
{
    _adultPlayer.resetJoules();
    _childPlayer.resetJoules();
}

//! Get Instantaneous Power in Watts
float Team::watts()
{
    return _adultPlayer.averageWatts() + _childPlayer.averageWatts();
}

//! Get Energy in joules since last reset
float Team::joules()
{
    return _adultPlayer.joules() + _childPlayer.joules();
}

void Team::setFreeze(bool b)
{
    _adultPlayer.setFreeze(b);
    _childPlayer.setFreeze(b);
}

