// fmodwrap.h - PLACEHOLDER: pulls in the FMOD Ex 4.44.64 low-level and event headers (third_party/fmod44464, the exact
// version of MapleStory2.exe: fmodex64.dll / fmod_event64.dll). NOT an original header. The exe calls FMOD through
// import thunks (jmp [IAT]) at 0x142303xxx, bound with symbols-manual `func` rows named after the DLL export.
#pragma once

#include "fmod44464/api/inc/fmod.hpp"
#include "fmod44464/fmoddesignerapi/api/inc/fmod_event.hpp"
