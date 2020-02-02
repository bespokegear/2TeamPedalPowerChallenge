#include "Team.h"
#include "Config.h"

//Team::Team(uint8_t adultPin, float childPin) :
//    _adultPlayer(adultPin, PLAYER_ADULT_LOAD_OHM),
//    _childPlayer(childPin, PLAYER_CHILD_LOAD_OHM),
//    _maxWatts(0)

Team::Team(uint8_t adultPin) :
    _adultPlayer(adultPin, PLAYER_ADULT_LOAD_OHM),
    _maxWatts(0)
{
}

void Team::begin()
{
    _adultPlayer.begin();
    //_childPlayer.begin();
}

void Team::update()
{
    _adultPlayer.update();
    //_childPlayer.update();
}

//! Reset Joules & unfreeze
void Team::reset()
{
    _adultPlayer.resetJoules();
    //_childPlayer.resetJoules();
    _maxWatts = 0;
}

//! Get Instantaneous Power in Watts
float Team::watts()
{
    // float w = _adultPlayer.averageWatts() + _childPlayer.averageWatts();
    // Just want to have one player watts
    float w = _adultPlayer.averageWatts(); // + _childPlayer.averageWatts(); 
    if (w > _maxWatts) {
        _maxWatts = w;
    }
    return w;
}

float Team::maxWatts()
{
    return _maxWatts;
}

//! Get Energy in joules since last reset
float Team::joules()
{
    // Just return adult joules
    //return _adultPlayer.joules() + _childPlayer.joules();
    return _adultPlayer.joules(); // + _childPlayer.joules();
}

void Team::setFreeze(bool b)
{
    _adultPlayer.setFreeze(b);
    //_childPlayer.setFreeze(b);
}
