// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Single functions of the small third-party libraries that the
// engine-stage TUs leave as stubs: expat xmltok scanComment/scanDecl, libjpeg jpeg_idct helpers (the JPEG
// marker-name char test), libpng png_zstream_error.
// MS2-UNIT: lib_small_tail
// MS2-RANGE: 0x1423c55a0-0x1423c5740 .text$mn
// MS2-RANGE: 0x1423c5740-0x1423c5808 .text$mn
// MS2-RANGE: 0x142702350-0x142702fa9 .text$mn
// MS2-RANGE: 0x142703c80-0x142703cd7 .text$mn
// MS2-RANGE: 0x142703ce0-0x142703d0c .text$mn
// MS2-RANGE: 0x142707ce0-0x142707da5 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// expat xmltok: the normal_encoding type table sits 0x90 bytes into ENCODING-derived struct
struct ExpatNormalEncoding
{
    char enc[0x90];
    unsigned char type[256];
    char pad190[0x30];
    int (*isInvalid2)(const ExpatNormalEncoding* enc, const char* p);  // +0x1c0
    int (*isInvalid3)(const ExpatNormalEncoding* enc, const char* p);  // +0x1c8
    int (*isInvalid4)(const ExpatNormalEncoding* enc, const char* p);  // +0x1d0
};

enum { BT_NONXML = 0, BT_MALFORM = 1, BT_LEAD2 = 5, BT_LEAD3 = 6, BT_LEAD4 = 7, BT_TRAIL = 8,
       BT_LSQB = 20, BT_S = 21, BT_NMSTRT = 22, BT_HEX = 24, BT_MINUS = 27, BT_CR = 9, BT_LF = 10, BT_PERCNT = 30 };

// @0x1423c55a0  expat normal_scanComment: ptr is past "<!-"; returns XML_TOK_COMMENT (13) after "-->"
int FUN_1423c55a0(const ExpatNormalEncoding* enc, const char* ptr, const char* end, const char** nextTokPtr)
{
    if (ptr == end)
        return -1;
    if (*ptr != '-')
    {
        *nextTokPtr = ptr;
        return 0;
    }
    ++ptr;
    while (ptr != end)
    {
        switch (enc->type[(unsigned char)*ptr])
        {
        case BT_LEAD2:
            if (end - ptr < 2)
                return -2;
            if (enc->isInvalid2(enc, ptr))
            {
                *nextTokPtr = ptr;
                return 0;
            }
            ptr += 2;
            break;
        case BT_LEAD3:
            if (end - ptr < 3)
                return -2;
            if (enc->isInvalid3(enc, ptr))
            {
                *nextTokPtr = ptr;
                return 0;
            }
            ptr += 3;
            break;
        case BT_LEAD4:
            if (end - ptr < 4)
                return -2;
            if (enc->isInvalid4(enc, ptr))
            {
                *nextTokPtr = ptr;
                return 0;
            }
            ptr += 4;
            break;
        case BT_NONXML:
        case BT_MALFORM:
        case BT_TRAIL:
            *nextTokPtr = ptr;
            return 0;
        case BT_MINUS:
            if (++ptr == end)
                return -1;
            if (*ptr == '-')
            {
                if (++ptr == end)
                    return -1;
                if (*ptr != '>')
                {
                    *nextTokPtr = ptr;
                    return 0;
                }
                *nextTokPtr = ptr + 1;
                return 13;
            }
            break;
        default:
            ++ptr;
            break;
        }
    }
    return -1;
}

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

// libjpeg jidctflt.c jpeg_idct_float: dequantize + 8x8 float IDCT (AA&N), range-limited output
struct JpegDecompressLite { char pad[0x188]; const unsigned char* sample_range_limit; };
struct JpegComponentLite { char pad[0x58]; const float* dct_table; };

// DESCALE(x, 3) & RANGE_MASK of the float result
static __forceinline unsigned JpegDescale(float v)
{
    long long i = static_cast<long long>(v);
    return static_cast<unsigned>((i + 4) >> 3) & 0x3ff;
}

// MS2-FUNCTIONAL: same AA&N arithmetic as jidctflt.c; SSE register allocation and loop unrolling differ
// @0x142702350
void FUN_142702350(JpegDecompressLite* cinfo, JpegComponentLite* compptr, short* coef_block, unsigned char** output_buf, unsigned int output_col)
{
    float workspace[64];
    const unsigned char* range_limit = cinfo->sample_range_limit + 128;
    const float* quantptr = compptr->dct_table;
    float* wsptr = workspace;
    short* inptr = coef_block;
    for (int ctr = 8; ctr > 0; --ctr)
    {
        if (inptr[8] == 0 && inptr[16] == 0 && inptr[24] == 0 && inptr[32] == 0 && inptr[40] == 0 && inptr[48] == 0 && inptr[56] == 0)
        {
            float dcval = (float)inptr[0] * quantptr[0];
            for (int r = 0; r < 8; ++r)
                wsptr[8 * r] = dcval;
        }
        else
        {
            float tmp0 = (float)inptr[0] * quantptr[0];
            float tmp1 = (float)inptr[16] * quantptr[16];
            float tmp2 = (float)inptr[32] * quantptr[32];
            float tmp3 = (float)inptr[48] * quantptr[48];
            float tmp10 = tmp0 + tmp2;
            float tmp11 = tmp0 - tmp2;
            float tmp13 = tmp1 + tmp3;
            float tmp12 = (tmp1 - tmp3) * 1.414213562f - tmp13;
            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;
            float tmp4 = (float)inptr[8] * quantptr[8];
            float tmp5 = (float)inptr[24] * quantptr[24];
            float tmp6 = (float)inptr[40] * quantptr[40];
            float tmp7 = (float)inptr[56] * quantptr[56];
            float z13 = tmp6 + tmp5;
            float z10 = tmp6 - tmp5;
            float z11 = tmp4 + tmp7;
            float z12 = tmp4 - tmp7;
            tmp7 = z11 + z13;
            tmp11 = (z11 - z13) * 1.414213562f;
            float z5 = (z10 + z12) * 1.847759065f;
            tmp10 = 1.082392200f * z12 - z5;
            tmp12 = -2.613125930f * z10 + z5;
            tmp6 = tmp12 - tmp7;
            tmp5 = tmp11 - tmp6;
            tmp4 = tmp10 - tmp5;
            wsptr[0] = tmp0 + tmp7;
            wsptr[56] = tmp0 - tmp7;
            wsptr[8] = tmp1 + tmp6;
            wsptr[48] = tmp1 - tmp6;
            wsptr[16] = tmp2 + tmp5;
            wsptr[40] = tmp2 - tmp5;
            wsptr[32] = tmp3 + tmp4;
            wsptr[24] = tmp3 - tmp4;
        }
        ++inptr; ++quantptr; ++wsptr;
    }
    wsptr = workspace;
    for (int ctr = 0; ctr < 8; ++ctr)
    {
        unsigned char* outptr = output_buf[ctr] + output_col;
        float tmp10 = wsptr[0] + wsptr[4];
        float tmp11 = wsptr[0] - wsptr[4];
        float tmp13 = wsptr[2] + wsptr[6];
        float tmp12 = (wsptr[2] - wsptr[6]) * 1.414213562f - tmp13;
        float tmp0 = tmp10 + tmp13;
        float tmp3 = tmp10 - tmp13;
        float tmp1 = tmp11 + tmp12;
        float tmp2 = tmp11 - tmp12;
        float z13 = wsptr[5] + wsptr[3];
        float z10 = wsptr[5] - wsptr[3];
        float z11 = wsptr[1] + wsptr[7];
        float z12 = wsptr[1] - wsptr[7];
        float tmp7 = z11 + z13;
        tmp11 = (z11 - z13) * 1.414213562f;
        float z5 = (z10 + z12) * 1.847759065f;
        tmp10 = 1.082392200f * z12 - z5;
        tmp12 = -2.613125930f * z10 + z5;
        float tmp6 = tmp12 - tmp7;
        float tmp5 = tmp11 - tmp6;
        float tmp4 = tmp10 - tmp5;
        outptr[0] = range_limit[JpegDescale(tmp0 + tmp7)];
        outptr[7] = range_limit[JpegDescale(tmp0 - tmp7)];
        outptr[1] = range_limit[JpegDescale(tmp1 + tmp6)];
        outptr[6] = range_limit[JpegDescale(tmp1 - tmp6)];
        outptr[2] = range_limit[JpegDescale(tmp2 + tmp5)];
        outptr[5] = range_limit[JpegDescale(tmp2 - tmp5)];
        outptr[4] = range_limit[JpegDescale(tmp3 + tmp4)];
        outptr[3] = range_limit[JpegDescale(tmp3 - tmp4)];
        wsptr += 8;
    }
}
