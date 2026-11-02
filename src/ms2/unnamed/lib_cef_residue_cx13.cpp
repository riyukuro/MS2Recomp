// Executable-derived cleanup for a CEF UTF-16 string transfer temporary.
// MS2-UNIT: lib_cef_residue_cx13
// MS2-RANGE: 0x14278a560-0x14278a5ef .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include <cstddef>
#include <cstdint>

typedef struct _cef_string_utf16_t
{
    unsigned short* str;
    std::size_t length;
    void (*dtor)(unsigned short* str);
} cef_string_utf16_t;
static_assert(sizeof(cef_string_utf16_t) == 0x18, "cef_string_utf16_t size");

extern "C" void cef_string_utf16_clear(cef_string_utf16_t* string);

// include/internal/cef_string_wrappers.h, the parts the destructor uses.
struct CefStringTraitsUTF16
{
    typedef cef_string_utf16_t struct_type;
    static inline void clear(struct_type* s) { cef_string_utf16_clear(s); }
};

template <class traits>
class CefStringBase
{
public:
    typedef typename traits::struct_type struct_type;

    virtual ~CefStringBase() { ClearAndFree(); }

    void clear()
    {
        if (string_ != NULL)
            traits::clear(string_);
    }

    void ClearAndFree()
    {
        if (!string_)
            return;
        if (owner_)
        {
            clear();
            delete string_;
        }
        string_ = NULL;
        owner_ = false;
    }

    struct_type* string_;
    bool owner_;
};
typedef CefStringBase<CefStringTraitsUTF16> CefStringUTF16;
static_assert(sizeof(CefStringUTF16) == 0x18, "CEF string wrapper size");

struct CefStringTransferCx13
{
    std::uint8_t head[0x20];
    CefStringUTF16 first;
    CefStringUTF16 second;
};
static_assert(sizeof(CefStringTransferCx13) == 0x50, "transfer temporary size");

// Deletes the transfer temporary; its two string members are destroyed in reverse order.
// @0x14278a560
void FUN_14278a560(void*, void* temporary)
{
    auto* transfer = static_cast<CefStringTransferCx13*>(temporary);
    transfer->~CefStringTransferCx13();
    ::operator delete(transfer, sizeof(CefStringTransferCx13));
}
