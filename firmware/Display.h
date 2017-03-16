#pragma once

#include <stdint.h>

/*! \class Display
 * Placeholder for actual display code
 */
class Display_ {
public:
    Display_() {;}
    void begin();
    //! Display a number, 0 displays "Go!"
    void countdown(uint8_t n);
    //! with NULL terminated string
    void say(const char* str);

};

extern Display_ Display;
