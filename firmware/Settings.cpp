#include "Settings.h"

//                                                 EEROM,  Min,    Max,                Default,    Incremenet
PersistentSetting<uint32_t> EnergyRaceGoalJoules(  0,      1000,   100000,             2000,       1000);
PersistentSetting<uint32_t> MaxPowerWatts(         4,      50,     1000,               200,        50);
PersistentSetting<uint32_t> RaceTimeSeconds(       8,      10,     300,                30,         10);
PersistentSetting<uint8_t> PanelsPerBargraph(      12,     1,      2,                  2,          1);
PersistentSetting<uint8_t> InitialMode(            16,     0,      3,                  0,          1);
