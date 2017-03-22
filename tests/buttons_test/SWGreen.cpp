#include <DebouncedButton.h>
#include <DualButton.h>
#include "Config.h"

DebouncedButton SWGreenWired(SWGREEN_WIRED_PIN);
DebouncedButton SWGreenRemote(SWGREEN_REMOTE_PIN, false);

DualButton SWGreen(&SWGreenWired, &SWGreenRemote);

