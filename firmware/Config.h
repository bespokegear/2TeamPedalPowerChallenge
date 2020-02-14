#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

//#define DEBUG                       true

#define LED1_NUM_PANELS             2
#define LED1_DATA_PIN               5
#define LED1_NEOPIXEL_TYPE          (NEO_RGB + NEO_KHZ800)
#define LED2_NUM_PANELS             2
#define LED2_DATA_PIN               6
#define LED2_NEOPIXEL_TYPE          (NEO_RBG + NEO_KHZ800)
#define LED_CLOCK_CORRECTION        24.5

#define DISPLAY_BUF_LEN             18

#define HEARTBEAT_LED_PIN           13
#define SWA_PIN                     11  
#define SWB_PIN                     8   // Do not have these on the energy Jan 2020 units
#define SWRED_WIRED_PIN             3
//#define SWRED_REMOTE_PIN            4 // Do not have these on the energy Jan 2020 units
#define SWGREEN_WIRED_PIN           2
#define SWGREEN_REMOTE_PIN          4  

#define PLAYER_VIN_R1_KOHM          330
#define PLAYER_VIN_R2_KOHM          10
#define PLAYER_VIN_VREF             3.3
#define PLAYER_VIN_PERIOD_MS        200
#define PLAYER_VIN_ALPHA            0.9
#define PLAYER_VIN_FACTOR           1.25
#define PLAYER_ADULT_LOAD_OHM       4.4
//#define PLAYER_CHILD_LOAD_OHM       6.6

#define TEAM1_ADULT_PIN             A0  
//#define TEAM1_CHILD_PIN             A0  // Do not have these on the energy Jan 2020 units
#define TEAM2_ADULT_PIN             A1
//#define TEAM2_CHILD_PIN             A1  // Do not have these on the energy Jan 2020 units

#define COUNTDOWN_START             3

#define ENERGY_FILL_LED_UPDATE_MS   35
#define ENERGY_FILL_VICTORY_SECONDS 10
#define ENERGY_RACE_TIE_DIFF_J      1

#define TIMED_POWER_TEAM1_COLOR     0xFF0000UL
#define TIMED_POWER_TEAM1_PEAKCOLOR 0xFFFFFFUL
#define TIMED_POWER_TEAM2_COLOR     0x00FF00UL
#define TIMED_POWER_TEAM2_PEAKCOLOR 0xFFFFFFUL
#define TIMED_POWER_LED_UPDATE_MS   50
#define TIMED_POWER_TIE_DIFF_W      1
#define TIMED_POWER_COUNTER_MS      100
#define TIMED_POWER_LED_MS          100

#define TIMED_ENERGY_TIE_DIFF_J     1

#define SETTING_REPEAT_INITIAL_MS   500
#define SETTING_REPEAT_MS           120

#define COUNTER_ONSET_DELAY_MS      1000

#define LED_TIMER_DELAY_MS          5000            // Timer mS - how long to hold the LEDs on after voltage dropped OR victory display
#define COUNTDOWN_COLOUR            0xFFFFFFFF      // Colour of countdown LEDS
