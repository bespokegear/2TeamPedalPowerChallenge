#pragma once

/*! \class RIBargraphDisplay
 *  One meter LED Bargraph display units from Re-innovation. 
 *  Each display unit has 60 rows of two neopixel LEDs. Multiple
 *  units can be daisy-chained together to form longer displays.
 *
 *  This class allows one or more of these units to be used as a 
 *  bar graph or other display where each row is illuminated in 
 *  full rather than each LED used individually.
 */

#include <Adafruit_NeoPixel.h>
#include <stdint.h>

#define RI_BARGRAPH_PANEL_LEDS 60

class RIBargraphDisplay : public Adafruit_NeoPixel {
public:
    //! \brief Constructor
    //! \param LEDType Hardware options to be passed to Adafruit library
    //! \param dataPin The pin the data is sent on
    //! \param numPanels The number of panels daisy-chained together
    RIBargraphDisplay(neoPixelType LEDType, uint8_t dataPin);

    //! \brief Set the number of panels in the display
    //! \param panels - the number of panels (can be 1 or 2)
    void setNumberPanels(uint8_t panels);

    //! \brief Initializtion
    //! Typically called from the setup() routine in the main program
    void begin();

    //! \brief Clear display
    //! \param immediate If true, changes are sent to LEDs straight away, else
    //!        show() must be called explicitly
    void clear(bool immediate=false);

    //! \brief Send data to LEDs
    //! Sends current programmed state of LEDs to the actual hardware - think
    //! of it like a "git push"
    void show();

    //! \brief Number of display rows
    uint16_t numRows();

    //! \brief Set row color
    void setRowColor(uint16_t row, uint32_t rgb, bool immediate=false);

    //! \brief Get row color
    //! \return 32-bit RGB encoded color value, i.e. 0xrrggbbUL
    //! Note that this just returns the color of the first pixel on the row.
    //! If the second pixel is a different color, this will not be reflected 
    //! in the return of this function.
    uint32_t getRowColor(uint16_t row);

    //! \brief Plot bar graph
    //! \param percent How much to fill, expressed as 0.0 - 1.0
    //! \param barColor The RGB color of the colored-in parts of the graph
    //! \param peak Use peak marker
    //! \param peakColor Color of peak marker, if used
    //! Bars will be filled only when the percent value exceeds the "top" of a segment
    //! i.e. if there are three rows, the first row will only become illuminated if
    //! percent is higher than 0.3333, and the top row will only illuminate when the
    //! percent is 1.0 or more.
    //
    //! Note: the peak marker is reset by calling clearPeak()
    void graph(float percent, uint32_t barColor, bool peak, uint32_t peakColor=0);

    //! \brief Get row of current peak marker
    uint16_t getPeak();

    //! \brief Clear the peak marker
    void clearPeak();

    //! \brief Set brightness
    //! \param b brightness in range 0-255, where 0 is off, and 255 is 100%
    void setBrightness(uint8_t b);

private:
    neoPixelType _type; 
    uint8_t _pin;
    int16_t peakRow;

};

