CPPFLAGS += -Wno-unused-variable -Wno-deprecated-declarations -Wno-cpp -Wno-write-strings
# This is necessary to fix out of memory conditions
CPPFLAGS += -DSERIAL_TX_BUFFER_SIZE=8
CPPFLAGS += -DSERIAL_RX_BUFFER_SIZE=8
#CPPFLAGS += -DMUTILADEBUG
#CPPFLAGS += -DDEBUG
#CPPFLAGS += -DMEMDEBUG
ARDUINO_LIBS = Mutila Adafruit_NeoPixel EEPROM MemoryFree
BOARD_TAG = nano
BOARD_SUB = atmega328

include ../arduino.mk

