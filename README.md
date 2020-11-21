# Two Team Pedal Power Challenge Firmware

## Important note about memory usage

This sketch is *very* tight on SRAM.  When using two panels per display, there will not be enough memory to run reliably unless the system serial buffer size is reduced.  To do this is automatic when building using the Makefile method, but when building using the Arduino IDE you should edit your boards.txt file adding the following line to the nano build flags:

    nano.build.extra_flags=-DSERIAL_TX_BUFFER_SIZE=8 -DSERIAL_RX_BUFFER_SIZE=8

It goes just after the line starting ''nano.build.variant=eightanaloginputs''.

If you do not do this, the sketch may behave poorly - crashing after some runtime, or exhibiting corruption of the LED displays, or failing to initialize the LED displays.

## Pre-requisites

* Install the Arduino IDE 1.6.6 or later
* Windows & Mac users may find a download link here: https://www.arduino.cc/en/Main/Software
* Major Linux distros carry it in their software repositories, or the link above may be used
* Install ''Mutila'' library from the library folder in this project to your Arduino library folder
* Install the ''Adafruit_NeoPixel'' library, link: https://github.com/adafruit/Adafruit_NeoPixel

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

## Updates

This has been altered to work with the new version of the energy bike.

This uses an ultra capacitor to store the energy and display the LEDs when there is no mains power available.

New features to implement include:

* Monitor capacitor voltage
* Change display mode if capacitor voltage drops
* If capacitor voltage drops < 12V DC then
** Reduce brightness of LEDs (both strings)
** After 30 seconds of lower than 12V DC switch OFF LEDs
* Change pins for new wiring
* Config change for new version

