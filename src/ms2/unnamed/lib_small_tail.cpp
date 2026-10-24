// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Single functions of the small third-party libraries that the
// engine-stage TUs leave as stubs: Lua 5.1 luaopen_debug, expat xmltok scanDecl, libjpeg jpeg_idct helpers (the JPEG
// marker-name char test), libpng png_zstream_error.
// MS2-UNIT: lib_small_tail
// MS2-RANGE: 0x14225bf20-0x14225bf40 .text$mn
// MS2-RANGE: 0x1423c5740-0x1423c5808 .text$mn
// MS2-RANGE: 0x142703c80-0x142703cd7 .text$mn
// MS2-RANGE: 0x142703ce0-0x142703d0c .text$mn
// MS2-RANGE: 0x142707ce0-0x142707da5 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

struct lua_State;
struct luaL_Reg;
extern const luaL_Reg DAT_1430fe2b0[];                                          // debug library function table
extern const char DAT_1430f5f38[];                                              // "debug"
void FUN_1421e5c10(lua_State* L, const char* libname, const luaL_Reg* l);       // luaL_register

// @0x14225bf20  luaopen_debug
int FUN_14225bf20(lua_State* L)
{
    FUN_1421e5c10(L, DAT_1430f5f38, DAT_1430fe2b0);
    return 1;
}

// expat xmltok: the normal_encoding type table sits 0x90 bytes into ENCODING-derived struct
struct ExpatNormalEncoding
{
    char enc[0x90];
    unsigned char type[256];
};
int FUN_1423c55a0(const ExpatNormalEncoding* enc, const char* ptr, const char* end, const char** nextTokPtr); // scanComment

enum { BT_LSQB = 20, BT_S = 21, BT_NMSTRT = 22, BT_HEX = 24, BT_MINUS = 27, BT_CR = 9, BT_LF = 10, BT_PERCNT = 30 };

// @0x1423c5740  expat normal_scanDecl
int FUN_1423c5740(const ExpatNormalEncoding* enc, const char* ptr, const char* end, const char** nextTokPtr)
{
    if (ptr == end)
        return -1;
    switch (enc->type[(unsigned char)*ptr])
    {
    case BT_LSQB:
        *nextTokPtr = ptr + 1;
        return 33;
    case BT_MINUS:
        return FUN_1423c55a0(enc, ptr + 1, end, nextTokPtr);
    case BT_NMSTRT:
    case BT_HEX:
        ++ptr;
        break;
    default:
        *nextTokPtr = ptr;
        return 0;
    }
    while (ptr != end)
    {
        switch (enc->type[(unsigned char)*ptr])
        {
        case BT_PERCNT:
            if (ptr + 1 == end)
                return -1;
            switch (enc->type[(unsigned char)ptr[1]])
            {
            case BT_S:
            case BT_CR:
            case BT_LF:
            case BT_PERCNT:
                *nextTokPtr = ptr;
                return 0;
            }
            // fall through
        case BT_S:
        case BT_CR:
        case BT_LF:
            *nextTokPtr = ptr;
            return 16;
        case BT_NMSTRT:
        case BT_HEX:
            ++ptr;
            break;
        default:
            *nextTokPtr = ptr;
            return 0;
        }
    }
    return -1;
}

// @0x142703ce0  printable-name character test (space, punctuation set, a-z)
__declspec(noinline) int FUN_142703ce0(unsigned long long c)
{
    unsigned long long k = c - 0x20;
    if (!(k <= 0x3a && ((1ULL << k) & 0x7fffffe03ff0001ULL)) && c - 0x61 > 0x19)
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: same four calls; the exe keeps the tag in volatile r8 across calls (whole-program register allocation, the callee preserves it), we use rbx
// @0x142703c80  all four bytes of a 32-bit tag pass the name-character test
int FUN_142703c80(unsigned long long tag)
{
    return FUN_142703ce0(tag >> 24) && FUN_142703ce0((unsigned char)(tag >> 16)) && FUN_142703ce0((unsigned char)(tag >> 8)) &&
           FUN_142703ce0((unsigned char)tag);
}

// libpng: png_structrp fields we touch
struct PngStructLite
{
    char pad[0x198];
    const char* zlib_msg;
};
extern const char DAT_143196858[];  // "unexpected zlib return code"
extern const char DAT_143196878[];  // "unexpected end of LZ stream"
extern const char DAT_143196898[];  // "missing LZ dictionary"
extern const char DAT_1431968b0[];  // "zlib IO error"
extern const char DAT_1431968c0[];  // "bad parameters to zlib"
extern const char DAT_1431968d8[];  // "damaged LZ stream"
extern const char DAT_1431968f0[];  // "insufficient memory"
extern const char DAT_143196908[];  // "truncated"
extern const char DAT_143196918[];  // "unsupported zlib version"
extern const char DAT_143196938[];  // "unexpected zlib return"

#ifdef __clang__
// Keep the exe message strings referenced in code, not in an absolute-address lookup table.
#pragma clang optimize off
#endif
// @0x142707ce0  png_zstream_error
void FUN_142707ce0(PngStructLite* png, int ret)
{
    if (png->zlib_msg != nullptr)
        return;
    switch (ret)
    {
    case 1: png->zlib_msg = DAT_143196878; break;
    case 2: png->zlib_msg = DAT_143196898; break;
    case -1: png->zlib_msg = DAT_1431968b0; break;
    case -2: png->zlib_msg = DAT_1431968c0; break;
    case -3: png->zlib_msg = DAT_1431968d8; break;
    case -4: png->zlib_msg = DAT_1431968f0; break;
    case -5: png->zlib_msg = DAT_143196908; break;
    case -6: png->zlib_msg = DAT_143196918; break;
    case -7: png->zlib_msg = DAT_143196938; break;
    default: png->zlib_msg = DAT_143196858; break;
    }
}
#ifdef __clang__
#pragma clang optimize on
#endif
