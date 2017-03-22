#pragma once

#include "ParentMode.h"

class TimedEnergyMode_ : public ParentMode {
public:
    TimedEnergyMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();

};

extern TimedEnergyMode_ TimedEnergyMode;

