#include <DebouncedButton.h>
#include <DualButton.h>
#include "Config.h"

DebouncedButton SWGreenWired(SWGREEN_WIRED_PIN, true);
DebouncedButton SWGreenRemote(SWGREEN_REMOTE_PIN, true);

DualButton SWGreen(&SWGreenWired, &SWGreenRemote);
