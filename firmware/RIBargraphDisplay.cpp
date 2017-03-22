#include <MutilaDebug.h>
#include "RIBargraphDisplay.h"
#include "OffsetMillis.h"
#include "Config.h"

RIBargraphDisplay::RIBargraphDisplay(neoPixelType LEDType, uint8_t dataPin, uint8_t numPanels) :
    Adafruit_NeoPixel(numPanels*60, dataPin, LEDType)
{
}

void RIBargraphDisplay::begin()
{
    Adafruit_NeoPixel::begin();
    clear(true);
    clearPeak();
}

void RIBargraphDisplay::clear(bool immediate)
{
    DBLN(F("RIBargraphDisplay::clear"));
    Adafruit_NeoPixel::clear();
    if (immediate) { 
        show(); 
    }
}

void RIBargraphDisplay::show()
{
    addMillisOffset(LED_CLOCK_CORRECTION*numRows()*2/1000.);
    Adafruit_NeoPixel::show();
}

uint16_t RIBargraphDisplay::numRows() 
{ 
    return Adafruit_NeoPixel::numPixels() / 2; 
}

void RIBargraphDisplay::setRowColor(uint16_t row, uint32_t rgb, bool immediate)
{
    Adafruit_NeoPixel::setPixelColor(row*2, rgb);
    Adafruit_NeoPixel::setPixelColor((row*2)+1, rgb);
    if (immediate) { 
        show(); 
    }
}

uint32_t RIBargraphDisplay::getRowColor(uint16_t row)
{
    return Adafruit_NeoPixel::getPixelColor(row*2);
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
    show();
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
    Adafruit_NeoPixel::setBrightness(b);
    show();
}


