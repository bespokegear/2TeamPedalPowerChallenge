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

#define TIMED_POWER_TEAM1_COLOR     0xFFEE00UL
#define TIMED_POWER_TEAM1_PEAKCOLOR 0xFFFFFFUL
#define TIMED_POWER_TEAM2_COLOR     0x0099FFUL
#define TIMED_POWER_TEAM2_PEAKCOLOR 0xFFFFFFUL
#define TIMED_POWER_LED_UPDATE_MS   50
#define TIMED_POWER_TIE_DIFF_W      1
#define TIMED_POWER_COUNTER_MS      100
#define TIMED_POWER_LED_MS          100

#define TIMED_ENERGY_TIE_DIFF_J     1

#define SETTING_REPEAT_INITIAL_MS   500
#define SETTING_REPEAT_MS           120

#define COUNTER_ONSET_DELAY_MS      1000

#define ENTER_SETTINGS_DELAY_MS     3000  // 3 seconds hold SWRed and SWGreen to enter setings mode.

#define START_MODE                  0     // Energy Fill
// To DO:
// Sort out voltage measurement infofrom mouse:
//In the Mar 2017 code, the calculation is like this:
//   (value*vRef*(r1KOhm+r2KOhm)) / (1024*r1KOhm);
//In the v1.1.0 (Dec 2017) release of Mutila, it's like this:
//   (value*vRef*(r1KOhm+r2KOhm)) / (1024.0*r1KOhm);
//The first term in the denominator changed from an integer literal
//"1024" to a float literal "1024.0".
//
//r1KOhm is a uint16_t with the value 330. In the Mar 2017 code we have
//an integer overflow, causing the denominator to be much lower than it
//should be!  We would expect the denominator to be:
//  1024 * 330 = 337920
//...but C++ being like it is, this value is evaluated as a uint16_t,
//and we get the value of
//
//  337920 % 65536 = 10240
//
//The result is that the calculated value for the voltage is much higher
//with the Mar 2017 code. For example, when the analog pins read 50 or
//200:
//
//value=50
//  Mar 2017 volts: 5.48
//  Dec 2017 volts: 0.17
//
//value=200
//  Mar 2017 volts: 21.91
//  Dec 2017 volts: 0.66
//
//Then the power calculation is performed:
//
//  power = (volts * volts) / load-resistance
//
//The squaring of the volt term means the difference is further exacerbated.
//
//I think the v1.1.0 voltage calculation is correct. I think that fixing
//that bug revealed a bug in the power calculation in the code for this
//project which we have yet to locate.
//
//So, what to do?
//
//I propose:
//
//1. Find the voltage calculation bug which I suspect lurks in the code
//for this firmware and fix it
//
//2. Build the project against the latest Mutila release which can be
//used (turns out that is actually v1.1.7 of Mutila from Oct 2019) & do
//some testing with the hardware.
//
//3. Remove the library/Mutila folder from this firmware project, and
//replace it with an instruction in the README to build against the
//specific version of Mutila from the Arduino library manager.
//
//Finding the bug will probably be easier if I can have access to
//hardware, and you can help me be metering the various values with your
//good meters. I think this process can also help to validate the
//calculation is OK in official release of Mutila, which is something I
//want to be sure of.
