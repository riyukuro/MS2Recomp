// Executable-derived cleanup for a CEF UTF-16 string transfer temporary.
// MS2-UNIT: lib_cef_residue_cx13
// MS2-RANGE: 0x14278a560-0x14278a5ef .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>

struct CefUtf16StringCx13
{
    void* vtable;
    void* string;
    bool ownsString;
    std::uint8_t padding[7];
};
static_assert(sizeof(CefUtf16StringCx13) == 0x18, "CEF string wrapper size");

extern "C" void cef_string_utf16_clear(void* string);

// MS2-FUNCTIONAL: restores both embedded string wrappers, clears owned UTF-16 data, then frees the temporary; the executable uses compiler-generated wrapper destructors.
// @0x14278a560
void FUN_14278a560(void*, void* temporary)
{
    auto* bytes = static_cast<std::uint8_t*>(temporary);
    auto* first = reinterpret_cast<CefUtf16StringCx13*>(bytes + 0x20);
    auto* second = reinterpret_cast<CefUtf16StringCx13*>(bytes + 0x38);
    for (CefUtf16StringCx13* value : {first, second})
    {
        if (value->string)
        {
            if (value->ownsString)
            {
                cef_string_utf16_clear(value->string);
                ::operator delete(value->string);
            }
            value->string = nullptr;
            value->ownsString = false;
        }
    }
    ::operator delete(temporary);
}
