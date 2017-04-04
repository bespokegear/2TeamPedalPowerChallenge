#include <MutilaDebug.h>
#include <Millis.h>
#include "RIBargraphDisplay.h"
#include "Config.h"
#include "Settings.h"

RIBargraphDisplay::RIBargraphDisplay(neoPixelType LEDType, uint8_t dataPin) :
    _type(LEDType),
    _pin(dataPin)
{
}

void RIBargraphDisplay::begin()
{
    Adafruit_NeoPixel::begin();
    updateType(_type);
    setPin(_pin);
    setNumberPanels(PanelsPerBargraph.get());
    clear(true);
    clearPeak();
}

void RIBargraphDisplay::setNumberPanels(uint8_t panels)
{
    clear(true);
    updateLength(panels*RI_BARGRAPH_PANEL_LEDS);
    clear(true);
    DB(F("Panels="));
    DB(panels);
    DB(F(" rows="));
    DBLN(numRows());
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

void RIBargraphDisplay::graph(float percent, uint32_t barColor, bool peak, uint32_t peakColor)
{
    int16_t topLit = -1;
    for (int16_t i=0; i<numRows(); i++) {
        bool lit = percent >= (float)(i+1)/numRows();
        if (lit) {
            setRowColor(i, barColor, false);
            topLit = i;
        } else {
            setRowColor(i, 0, false);
        }
    }
    if (peak) {
        if (topLit > peakRow) {
            peakRow = topLit;
        }
        setRowColor(peakRow, peakColor, false);
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


