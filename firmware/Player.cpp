#include <MutilaDebug.h>
#include <Millis.h>
#include "Player.h"

Player::Player(const uint8_t pin, const float loadOhms) :
    EMAVDivSampler(pin, PLAYER_VIN_R1_KOHM, PLAYER_VIN_R2_KOHM, PLAYER_VIN_VREF, PLAYER_VIN_PERIOD_MS, PLAYER_VIN_ALPHA),
    _loadOhms(loadOhms)
{
    resetJoules();
}

void Player::begin()
{
    EMAVDivSampler::begin();
    resetJoules();
}

float Player::averageVolts()
{
    return EMAVDivSampler::averageVolts() * PLAYER_VIN_FACTOR;
}

float Player::lastVolts()
{
    return EMAVDivSampler::lastVolts() * PLAYER_VIN_FACTOR;
}

float Player::averageWatts()
{
    float v = averageVolts();
    return (v*v)/_loadOhms;
}

float Player::lastWatts()
{
    float v = lastVolts();
    return (v*v)/_loadOhms;
}

void Player::resetJoules()
{
    _joules = 0.;
    _frozen = false;
    _lastUpdated = Millis();
}

float Player::joules()
{
    return _joules;
}

void Player::update()
{
    unsigned long elapsed = Millis()-_lastUpdated;
    if (_periodMs == 0 || elapsed >= _periodMs || _lastUpdated == 0) {
        if (!_frozen) {
            _lastUpdated = Millis();
            _lastSample = analogRead(_pin);
            _movingAverage = (_alpha*_lastSample) + ((1-_alpha)*_movingAverage);
            _joules += averageWatts() * elapsed/1000.;
            //DB(F("Player::update elapsed="));
            //DB(elapsed);
            //DB(F(" _av.watts="));
            //DB(averageWatts());
            //DB(F(" _joules="));
            //DBLN(_joules);
        }
    }   
}

void Player::setFreeze(bool b) 
{
    _frozen = b;
    if (!_frozen) {
        // reset averaging to instant value to prevent 
        // histroical values perverting the current reading
        EMAVDivSampler::begin();       
    }
}


