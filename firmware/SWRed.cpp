#include <DebouncedButton.h>
#include <DualButton.h>
#include "Config.h"

DebouncedButton SWRedWired(SWRED_WIRED_PIN);
DebouncedButton SWRedRemote(SWRED_REMOTE_PIN, false);

DualButton SWRed(&SWRedWired, &SWRedRemote);

