#pragma once

#include <Mode.h>
#include "Settings.h"

#define SETTINGS_COUNT 3

class SettingsMode_ : public Mode {
public:
    SettingsMode_();
    void modeStart();
    void modeStop();
    void modeUpdate();
    void display();

private:
    int8_t _idx;

};

extern SettingsMode_ SettingsMode;
