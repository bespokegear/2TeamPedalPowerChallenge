#pragma once

#include <Mode.h>

class EmptyMode_ : public Mode {
public:
    EmptyMode_();
    void modeStart();
    void modeStop();
    void modeUpdate();

};

extern EmptyMode_ EmptyMode;
