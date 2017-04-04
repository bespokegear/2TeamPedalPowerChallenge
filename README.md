# Two Team Pedal Power Challenge Firmware

## Important note about memory usage

This sketch is VERY tight on SRAM.  When using two panels per display, there will not be
enough memory to run reliably unless the system serial buffer size is reduced.  To do this
is automatic when building using the Makefile method, but when building using the Arduino IDE
it is vital that you use version 1.7.9 or later so the buildprefs.txt file is used.

## Pre-requisites

* Install the Arduino IDE 1.7.9 or later
** Windows & Mac users may find a download link here: https://www.arduino.cc/en/Main/Software
** Major Linux distros carry it in their software repositories, or the link above may be used
** Install ''Mutila'' library, link: https://github.com/matthewg42/Mutila 
** Install the ''Adafruit_NeoPixel'' library, link: https://github.com/adafruit/Adafruit_NeoPixel

## Building Using the Arduino IDE

This method is preferred on Windows and for casual users who just want to build and use the project.

* Open Arduino IDE 
* Open firmware/firmware.ino
* Set the board to "Arduino Nano" (under the Tools -> Board menu)
* Connect Nano 
* Click the Upload button on the tool bar

## Using make on Linux

This alternative build system may also be used. It is an alternative to using the Arduino IDE and may be preferred by some users. 

* Intall the Arduino-Makefile system: https://github.com/sudar/Arduino-Makefile
* Edit the arduino.mk file and set the include line to point at where you installed Arduino-Makefile (or set the ARDUINO_MAKEFILE environment variable)
* In a shell, from the ''firmware'' directory, use the command "make upload" to build and install the code

