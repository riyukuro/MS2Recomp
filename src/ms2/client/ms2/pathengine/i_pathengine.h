// Include shim (ours, not an SDK file): the PathEngine SDK's i_pathengine.h, used in place from third_party.
// The SDK sources compiled in place say #include "i_pathengine.h" from the snippet directory; MSVC/clang-cl then search
// the directories of the including files, which finds this shim next to the wrapper units. The SDK may not be
// redistributed: never copy its files into src/.
#pragma once
#include "../third_party/src/pathengine-sigmaco/code/externalAPI/i_pathengine.h"
