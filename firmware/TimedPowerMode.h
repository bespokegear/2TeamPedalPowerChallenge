#pragma once

#include "ParentMode.h"

class TimedPowerMode_ : public ParentMode {
public:
    TimedPowerMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    void announce();

};

extern TimedPowerMode_ TimedPowerMode;

