#pragma once

#include "ParentMode.h"

class EnergyFillMode_ : public ParentMode {
public:
    EnergyFillMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    void announce();

};

extern EnergyFillMode_ EnergyFillMode;

