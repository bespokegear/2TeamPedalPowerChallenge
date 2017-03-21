#include <MutilaDebug.h>
#include "RIBargraphDisplay.h"

RIBargraphDisplay::RIBargraphDisplay(neoPixelType LEDType, uint8_t numPanels, uint8_t dataPin) :
    LEDs(numPanels*60, dataPin, LEDType)
{
}

void RIBargraphDisplay::begin()
{
    LEDs.begin();
    clear();
    clearPeak();
}

void RIBargraphDisplay::clear(bool immediate)
{
    LEDs.clear();
    if (immediate) { 
        LEDs.show(); 
    }
}


uint16_t RIBargraphDisplay::numRows() 
{ 
    return LEDs.numPixels() / 2; 
}

void RIBargraphDisplay::setRowColor(uint16_t row, uint32_t rgb, bool immediate)
{
    LEDs.setPixelColor(row*2, rgb);
    LEDs.setPixelColor((row*2)+1, rgb);
    if (immediate) { 
        LEDs.show(); 
    }
}

uint32_t RIBargraphDisplay::getRowColor(uint16_t row)
{
    return LEDs.getPixelColor(row*2);
}

void RIBargraphDisplay::graph(uint16_t n, uint32_t barColor, bool peak, uint32_t peakColor)
{
    if (peak) {
        if (n > peakRow) {
            peakRow = n;
        }
    }
    for (uint16_t i=0; i<=numRows(); i++) {
        if (!peak) {
            setRowColor(i, i<=n ? barColor : 0, false); 
        } else {
            if (i<n) {
                setRowColor(i, barColor, false);
            } else if (i==n) {
                if (peakRow>n) {
                    setRowColor(i, barColor, false);
                } else {
                    setRowColor(i, peakColor, false);
                }
            } else {
                if (i == peakRow) {
                    setRowColor(i, peakColor, false);
                } else { 
                    setRowColor(i, 0, false);
                }
            }
        }
    }
    LEDs.show();
}

uint16_t RIBargraphDisplay::getPeak()
{
    return peakRow;
}

void RIBargraphDisplay::clearPeak()
{
    peakRow = 0;
}

void RIBargraphDisplay::setBrightness(uint8_t b)
{
    LEDs.setBrightness(b);
    LEDs.show();
}


