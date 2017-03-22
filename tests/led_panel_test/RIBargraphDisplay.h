#pragma once

/*! \class RIBargraphDisplay
 *  One meter LED Bargraph display units from Re-innovation
 */

#include <Adafruit_NeoPixel.h>
#include <stdint.h>

class RIBargraphDisplay {
public:
    RIBargraphDisplay(neoPixelType LEDType, uint8_t numPanels, uint8_t dataPin);
    void begin();
    void clear(bool immediate=true);
    uint16_t numRows();
    void setRowColor(uint16_t row, uint32_t rgb, bool immediate=true);
    uint32_t getRowColor(uint16_t row);

    void graph(uint16_t n, uint32_t barColor, bool peak, uint32_t peakColor=0);
    uint16_t getPeak();
    void clearPeak();

private:
    Adafruit_NeoPixel LEDs;
    uint16_t peakRow;

};

