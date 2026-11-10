// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ms2searchtexturepath.cpp
// MS2-RANGE: 0x141507ff0-0x141508390 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2searchtexturepath.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2searchtexturepath.h"
#include <efd/PathUtils.h>
#include "hook/ms2hook.h"


// @0x141507ff0
MS2SearchTexturePath::MS2SearchTexturePath() { m_bQueried = false; }

// @0x141508030
MS2SearchTexturePath::~MS2SearchTexturePath() {}

// @0x141508060
void* FUN_141508060()
{
    return new (efd::MemHint(efd::MemHint::NONE)) MS2SearchTexturePath();
}

MS2_REPLACE(0x141508060, FUN_141508060, 106, 0xD2A657AB);

// @0x1415080d0
void MS2SearchTexturePath::Reset()
{
    NiTextureSearchPath::Reset();
    m_bQueried = false;
}

MS2_REPLACE_METHOD(0x1415080D0, MS2SearchTexturePath, Reset, 36, 0xABE92DA7);

// @0x141508100
bool MS2SearchTexturePath::GetNextSearchPath(char* pcPath, unsigned int uiStringLen)
{
    if (GetFileSystem()->FUN_140398190()) {
        if (!m_bQueried) {
            m_bQueried = true;
            StandardizePath(pcPath);
            return GetFileSystem()->FUN_14039a160(m_acReferencePath, m_acFilePath, pcPath, uiStringLen);
        }
    } else {
        return NiTextureSearchPath::GetNextSearchPath(pcPath, uiStringLen);
    }
    return false;
}

MS2_REPLACE_METHOD(0x141508100, MS2SearchTexturePath, GetNextSearchPath, 183, 0x179EEA3A);

// @0x141508220
void StandardizePath(char* pcPath) { efd::PathUtils::Standardize(pcPath); }

#pragma function(memset, memcpy)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
MS2_REPLACE(0x141508220, StandardizePath, 24, 0xA3905266);

// @0x141508240 (the UCRT header-inline memcpy_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
errno_t FUN_141508240(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}
