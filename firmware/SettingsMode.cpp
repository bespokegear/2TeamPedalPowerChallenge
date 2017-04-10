#include <Arduino.h>
#include <MutilaDebug.h>
#include <EEPROM.h>
#include <string.h>
#include <stdio.h>
#include "SettingsMode.h"
#include "SWRed.h"
#include "SWGreen.h"
#include "Display.h"
#include "Settings.h"
#include "LED1.h"
#include "LED2.h"
#include "Config.h"

SettingsMode_ SettingsMode;

SettingsMode_::SettingsMode_() :
    _idx(0)
{
}

void SettingsMode_::modeStart()
{
    DBLN(F("SettingsMode::modeStart()"));
    // Clear pressed buttons
    SWRed.tapped();
    SWGreen.tapped();
    display();
}

void SettingsMode_::modeStop()
{
    DBLN(F("SettingsMode::modeStop()"));
    EnergyRaceGoalJoules.save();
    MaxPowerWatts.save();
    RaceTimeSeconds.save();
    PanelsPerBargraph.save();
}

void SettingsMode_::modeUpdate()
{
    if (SWGreen.tapped()) {
        _idx = (_idx+1) % (SETTINGS_COUNT);
        display();
    }

    if (SWRed.repeat(SETTING_REPEAT_INITIAL_MS, SETTING_REPEAT_MS)) {
        switch(_idx) {
        case 0:
            EnergyRaceGoalJoules.increment();
            break;
        case 1:
            MaxPowerWatts.increment();
            break;
        case 2:
            RaceTimeSeconds.increment();
            break;
        case 3:
            PanelsPerBargraph.increment();
            LED1.setNumberPanels(PanelsPerBargraph.get());
            LED2.setNumberPanels(PanelsPerBargraph.get());
            break;
        default:
            break;
        }
        display();
    }
}

void SettingsMode_::display()
{
    char buf[13];
    memset(buf,0,13);
    switch(_idx) {
    case 0:
        snprintf(buf, 12, "MaxE|%dkJ", EnergyRaceGoalJoules.get()/1000);
        Display.say(buf);
        break;
    case 1:
        snprintf(buf, 12, "MaxP|%dW", MaxPowerWatts.get());
        Display.say(buf);
        break;
    case 2:
        snprintf(buf, 12, "Race T|%ds", RaceTimeSeconds.get());
        Display.say(buf);
        break;
    case 3:
        snprintf(buf, 12, "Panels|%d", PanelsPerBargraph.get());
        Display.say(buf);
        break;
    default:
        Display.say("Err");
        break;
    }
}


