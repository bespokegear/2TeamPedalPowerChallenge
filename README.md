# Two Team Pedal Power Challenge Firmware

## Pre-requisites

* Install the Arduino IDE 1.6.6 or later
** Windows & Mac users may find a download link here: https://www.arduino.cc/en/Main/Software
** Major Linux distros carry it in their software repositories, or the link above may be used
** Install ''Mutila'' library, link: https://github.com/matthewg42/Mutila 

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
