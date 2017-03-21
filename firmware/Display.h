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
    //! countdown in tenths of a sec (e.g. to display "30", tenthsSec=300)
    void countdown(uint16_t tenthsSec);
    //! say who won. if n == 0 it means a tie
    void winner(uint8_t n);

};

extern Display_ Display;
