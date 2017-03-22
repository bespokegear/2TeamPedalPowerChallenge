#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED1_NUM_PANELS             2
#define LED1_DATA_PIN               5
#define LED1_NEOPIXEL_TYPE          (NEO_RGB + NEO_KHZ800)
#define LED2_NUM_PANELS             2
#define LED2_DATA_PIN               6
#define LED2_NEOPIXEL_TYPE          (NEO_RBG + NEO_KHZ800)
#define LED_CLOCK_CORRECTION        24.5

#define HEARTBEAT_LED_PIN           13
#define SWA_PIN                     4
#define SWB_PIN                     7
#define SWRED_WIRED_PIN             2
#define SWRED_REMOTE_PIN            A4
#define SWGREEN_WIRED_PIN           3
#define SWGREEN_REMOTE_PIN          A5

#define PLAYER_VIN_R1_KOHM          330
#define PLAYER_VIN_R2_KOHM          10
#define PLAYER_VIN_VREF             3.3
#define PLAYER_VIN_PERIOD_MS        20
#define PLAYER_VIN_ALPHA            0.9
#define PLAYER_VIN_FACTOR           1.25
#define PLAYER_ADULT_LOAD_OHM       4.4
#define PLAYER_CHILD_LOAD_OHM       6.6

#define TEAM1_ADULT_PIN             A0
#define TEAM1_CHILD_PIN             A1
#define TEAM2_ADULT_PIN             A2
#define TEAM2_CHILD_PIN             A3

#define COUNTDOWN_START             3

#define ENERGY_FILL_LED_UPDATE_MS   100
#define ENERGY_FILL_VICTORY_SECONDS 10

#define SETTING_REPEAT_INITIAL_MS   500
#define SETTING_REPEAT_MS           120
