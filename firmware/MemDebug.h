#pragma once

#include <Arduino.h>
#include <MemoryFree.h>

#ifdef MEMDEBUG
#define MEMDEBUG 1
#else
#define MEMDEBUG 0
#endif

#define MEMDB() do { if (MEMDEBUG) { Serial.print(F("Mem=")); Serial.println(freeMemory()); } } while (0)


