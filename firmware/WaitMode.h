#pragma once

#include <Mode.h>
#include <stdint.h>

class WaitMode_ : public Mode {
public:
    WaitMode_();
    void begin();
    void modeStart();
    void modeStop();
    void modeUpdate();
    bool isFinished();

private:
    int16_t wipeRow;
    unsigned long lastWipe;

};

extern WaitMode_ WaitMode;
