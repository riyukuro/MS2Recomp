// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\weathereffectparam.cpp
// MS2-RANGE: 0x141b77250-0x141b77810 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\weathereffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "weathereffectparam.h"
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Game TinyXML element and attribute helper (commonfiles\tinyxmlhelper.cpp).
int FUN_140873220(Unk_140165cf0* pNode, const char* pszName, int& nOut);

// Weather manager (singleton 0x1403ed280).
class Unk_WeatherMgr
{
public:
    void FUN_1411a7960(int nFallType);
};
Unk_WeatherMgr* FUN_1403ed280();

// @0x141b77250
WeatherEffectParam::WeatherEffectParam()
    : CEffectParam(6), m_nFallType(0)
{
}

// @0x141b772a0
void WeatherEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_140873220(pNode, "fallType", m_nFallType);
}
MS2_REPLACE_METHOD(0x141b772a0, WeatherEffectParam, vfunc_1, 63, 0xD2D9FD4B);

// @0x141b772f0
// Not hooked: constructs WeatherEffect with this unit's (DLL) constructor/vftable.
CEffectPtr WeatherEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) WeatherEffect;
}

// @0x141b77390
WeatherEffect::WeatherEffect()
    : m_nFallType(0)
{
}

// @0x141b773d0
bool WeatherEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const WeatherEffectParam* pWeather = static_cast<const WeatherEffectParam*>(pParam);
    m_nFallType = pWeather->m_nFallType;
    return true;
}
MS2_REPLACE_METHOD(0x141b773d0, WeatherEffect, vfunc_3, 83, 0xC8C62722);

// @0x141b77430
void WeatherEffect::vfunc_4()
{
    CEffect::vfunc_4();
    FUN_1403ed280()->FUN_1411a7960(m_nFallType);
}
MS2_REPLACE_METHOD(0x141b77430, WeatherEffect, vfunc_4, 45, 0x474AF68F);

// @0x141b77470
void WeatherEffect::vfunc_7()
{
    CEffect::vfunc_7();
    FUN_1403ed280()->FUN_1411a7960(0);
}
MS2_REPLACE_METHOD(0x141b77470, WeatherEffect, vfunc_7, 39, 0x3046C663);

// @0x141b774a0
int WeatherEffect::vfunc_12()
{
    return 6;
}

// UCRT header-inline memcpy_s / memmove_s (corecrt_memcpy_s.h), emitted here as ordinary functions.
#pragma function(memset, memcpy)
#include <errno.h>
#include <string.h>
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }

// @0x141b775a0
errno_t FUN_141b775a0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize)
    {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}

// @0x141b776f0
errno_t FUN_141b776f0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x14011fb40-0x14011fb70 .text$di
#ifndef MS2_HOOK_DLL
const NiRTTI WeatherEffect::ms_RTTI("WeatherEffect", &CEffect::ms_RTTI);   // @0x14011fb40
#endif
