// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See fishcube.h.
// MS2-UNIT: ?\fishcube.cpp
// MS2-RANGE: 0x1403b08b0-0x1403b0e20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fishcube.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "fishcube.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1403b08b0
CFishCube::CFishCube()
{
    m_id = 0;
    FUN_1403b0b30();
}

// @0x1403b0910
void CFishCube::FUN_1403b0910(COutputStream* pStream)
{
    pStream->WriteInt32(m_id);
    pStream->WriteInt32(10000001);
    pStream->WriteInt32(25);
    pStream->WriteInt32(m_c);
    pStream->WriteInt16(1);
}
MS2_REPLACE_METHOD(0x1403b0910, CFishCube, FUN_1403b0910, 129, 0x2568022D);

// @0x1403b09a0
void CFishCube::FUN_1403b09a0(COutputStream* pStream)
{
    pStream->WriteInt32(m_id);
    pStream->WriteInt32(m_a);
    pStream->WriteInt32(m_b);
    pStream->WriteInt32(m_c);
    pStream->WriteInt16((short)m_d);
}
MS2_REPLACE_METHOD(0x1403b09a0, CFishCube, FUN_1403b09a0, 140, 0x567C591A);

// @0x1403b0a40
void CFishCube::FUN_1403b0a40(CByteBuffer* pStream)
{
    m_id = pStream->ReadInt32();
    m_a = pStream->ReadInt32();
    m_b = pStream->ReadInt32();
    m_c = pStream->ReadInt32();
    m_d = (unsigned short)pStream->ReadInt16();
}
MS2_REPLACE_METHOD(0x1403b0a40, CFishCube, FUN_1403b0a40, 232, 0xC483254E);

// @0x1403b0b30
void CFishCube::FUN_1403b0b30()
{
    m_a = 0;
    m_b = 0;
    m_c = 0;
    m_d = 0;
}
MS2_REPLACE_METHOD(0x1403b0b30, CFishCube, FUN_1403b0b30, 54, 0x8F98AE17);

// @0x1403b0b70
void CFishCube::FUN_1403b0b70(COutputStream* pStream)
{
    pStream->WriteInt32(m_id);
    pStream->WriteInt32(m_a);
    pStream->WriteInt32(m_b);
    pStream->WriteInt32(m_c);
}
MS2_REPLACE_METHOD(0x1403b0b70, CFishCube, FUN_1403b0b70, 115, 0x4007E1D0);

// @0x1403b0bf0
void CFishCube::FUN_1403b0bf0(CByteBuffer* pStream)
{
    m_id = pStream->ReadInt32();
    m_a = pStream->ReadInt32();
    m_b = pStream->ReadInt32();
    m_c = pStream->ReadInt32();
}
MS2_REPLACE_METHOD(0x1403b0bf0, CFishCube, FUN_1403b0bf0, 187, 0xD9717130);

// @0x1403b0cb0
// MS2-FUNCTIONAL: exe dtor omits the vftable store before calling ~CPtred; cl always emits it
CFishCube::~CFishCube()
{
}

// @0x1403b0d10 (the UCRT header-inline memmove_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
errno_t FUN_1403b0d10(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
