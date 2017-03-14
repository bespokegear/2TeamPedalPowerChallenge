#include "Player.h"

Player::Player(const uint8_t pin, const float loadOhms) :
    EMAVDivSampler(pin, PLAYER_VIN_R1_KOHM, PLAYER_VIN_R2_KOHM, PLAYER_VIN_VREF, PLAYER_VIN_PERIOD_MS, PLAYER_VIN_ALPHA),
    _loadOhms(loadOhms)
{
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

