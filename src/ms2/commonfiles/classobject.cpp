// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ClassObject, the factory registry (a case-insensitive
// CAtlMap of class name -> create function) and a run of login packet payload structs that follow it in the TU.
// MS2-UNIT: ?\classobject.cpp
// MS2-RANGE: 0x1401f7ee0-0x1401f9eb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\classobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/commonfiles/serverpacketdef.h"
#include <errno.h>
#include <string.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1401f7ee0
ClassObject::ClassObject() {}

// @0x1401f7f20
ClassObject::~ClassObject() {}

// @0x1401f7f50
ClassObject* FUN_1401f7f50(CStringW strName)
{
    ClassObjectCreateFn pfnCreate = NULL;
    if (FUN_1401f7fe0()->Lookup(strName, pfnCreate))
        return pfnCreate();
    return NULL;
}
MS2_REPLACE(0x1401F7F50, FUN_1401f7f50, 133, 0x1120D2F1);

// @0x1401f7fe0
ClassObjectFactoryMap* FUN_1401f7fe0()
{
    static ClassObjectFactoryMap s_map;
    return &s_map;
}
MS2_REPLACE(0x1401F7FE0, FUN_1401f7fe0, 153, 0x2E87AF23);

// @0x1401f8450
CStringW ClassObject::GetTypeName()
{
    return CStringW(L"ClassObject");
}
MS2_REPLACE_METHOD(0x1401F8450, ClassObject, GetTypeName, 61, 0xC95ED7E5);

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h) closes the CAtlMap instantiations.
#pragma function(memmove)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x1401f8df0
errno_t FUN_1401f8df0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
MS2_REPLACE(0x1401F8DF0, FUN_1401f8df0, 271, 0xEF910EA6);

// ---- login packet payloads --------------------------------------------------------------------------------------
// The structs are named after their layout only; the owning request/response classes are not recovered yet.
struct Unk_NarrowLimit { int maximum; explicit Unk_NarrowLimit(int); };      // 0x1402c38f0 (owned by unit_1401f9eb0)
MS2_CHECK_SIZE(Unk_NarrowLimit, 4);

// The payload reader of unit_1401f9eb0, which owns the template ReadNarrowWrapper<Unk_NarrowLimit> (0x140202cb0).
struct Unk_PayloadReader : Unk_SPDReader {
    template<class C> CString ReadNarrowWrapper(C constraint);
};

struct Unk_LoginMachineId { unsigned char m_data[16]; };                    // encoded by 0x14067c2c0, decoded by 0x14067c310
MS2_CHECK_SIZE(Unk_LoginMachineId, 16);
struct Unk_LoginBlob { unsigned char m_data[0x20]; };                       // encoded by 0x1406c3380, decoded by 0x1406c33f0
MS2_CHECK_SIZE(Unk_LoginBlob, 0x20);
void FUN_14067c2c0(Unk_LoginMachineId* pId, COutputStream* pOut);
void FUN_14067c310(Unk_LoginMachineId* pId, CInputStream* pIn);
void FUN_1406c3380(Unk_LoginBlob* pBlob, COutputStream* pOut);
void FUN_1406c33f0(Unk_LoginBlob* pBlob, Unk_PayloadReader* pIn);

// The first hello of the connection (Unk_NetworkHello in networkservice.cpp).
struct Unk_LoginHello { unsigned m_nVersion, m_nLocale, m_nBuild; };
MS2_CHECK_SIZE(Unk_LoginHello, 12);

// @0x1401f8f10
void FUN_1401f8f10(Unk_LoginHello* p, COutputStream* out)
{
    out->vfunc_o10_3(p->m_nVersion);
    out->vfunc_o10_2((short)p->m_nLocale);
    out->vfunc_o10_2((short)p->m_nBuild);
}
MS2_REPLACE(0x1401F8F10, FUN_1401f8f10, 92, 0x5E8BA88F);

// @0x1401f8f80
void FUN_1401f8f80(Unk_LoginHello* p, Unk_PayloadReader& in)
{
    p->m_nVersion = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_nLocale = (unsigned short)static_cast<CInputStream&>(in).vfunc_o8_2();
    p->m_nBuild = (unsigned short)static_cast<CInputStream&>(in).vfunc_o8_2();
}
MS2_REPLACE(0x1401F8F80, FUN_1401f8f80, 150, 0x9F4DC64A);

struct Unk_LoginA {
    unsigned m_nType; CString m_s08; CString m_s10; unsigned m_n18; Unk_LoginMachineId m_id;
    int m_n2c; int m_n30; CString m_s38;
};
MS2_CHECK_SIZE(Unk_LoginA, 0x40);

// @0x1401f9020
void FUN_1401f9020(Unk_LoginA* p, COutputStream* out)
{
    out->vfunc_o10_1(p->m_nType);
    out->vfunc_o10_6(p->m_s08);
    out->vfunc_o10_6(p->m_s10);
    out->vfunc_o10_2((short)p->m_n18);
    FUN_14067c2c0(&p->m_id, out);
    out->vfunc_o10_3(p->m_n2c);
    out->vfunc_o10_3(p->m_n30);
    out->vfunc_o10_7(p->m_s38);
}
MS2_REPLACE(0x1401F9020, FUN_1401f9020, 252, 0x01402197);

// @0x1401f9130
void FUN_1401f9130(Unk_LoginA* p, Unk_PayloadReader& in)
{
    Unk_SPDByteRange range;
    p->m_nType = in.FUN_140202740(*FUN_140203550(&range, 1, 2));
    p->m_s08 = in.ReadNarrowWrapper(Unk_NarrowLimit(0x20));
    p->m_s10 = in.ReadNarrowWrapper(Unk_NarrowLimit(0x10));
    p->m_n18 = (unsigned short)static_cast<CInputStream&>(in).vfunc_o8_2();
    FUN_14067c310(&p->m_id, &static_cast<CInputStream&>(in));
    p->m_n2c = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_n30 = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_s38 = static_cast<CInputStream&>(in).vfunc_o8_7();
}
MS2_REPLACE(0x1401F9130, FUN_1401f9130, 563, 0xCA288641);

struct Unk_LoginB {
    unsigned m_nType; CString m_s08; CString m_s10; unsigned m_n18; int m_n1c; Unk_LoginMachineId m_id;
    int m_n30; int m_n34;
};
MS2_CHECK_SIZE(Unk_LoginB, 0x38);

// @0x1401f9370
void FUN_1401f9370(Unk_LoginB* p, COutputStream* out)
{
    out->vfunc_o10_1(p->m_nType);
    out->vfunc_o10_6(p->m_s08);
    out->vfunc_o10_6(p->m_s10);
    out->vfunc_o10_2((short)p->m_n18);
    out->vfunc_o10_3(p->m_n1c);
    FUN_14067c2c0(&p->m_id, out);
    out->vfunc_o10_3(p->m_n30);
    out->vfunc_o10_3(p->m_n34);
}
MS2_REPLACE(0x1401F9370, FUN_1401f9370, 238, 0xC5A4FE67);

// @0x1401f9470
void FUN_1401f9470(Unk_LoginB* p, Unk_PayloadReader& in)
{
    Unk_SPDByteRange range;
    p->m_nType = in.FUN_140202740(*FUN_140203550(&range, 1, 2));
    p->m_s08 = static_cast<CInputStream&>(in).vfunc_o8_6();
    p->m_s10 = static_cast<CInputStream&>(in).vfunc_o8_6();
    p->m_n18 = (unsigned short)static_cast<CInputStream&>(in).vfunc_o8_2();
    p->m_n1c = static_cast<CInputStream&>(in).vfunc_o8_3();
    FUN_14067c310(&p->m_id, &static_cast<CInputStream&>(in));
    p->m_n30 = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_n34 = static_cast<CInputStream&>(in).vfunc_o8_3();
}
MS2_REPLACE(0x1401F9470, FUN_1401f9470, 522, 0x6226ED33);

struct Unk_LoginC {
    unsigned m_nType; int m_n04; __int64 m_n08; Unk_LoginBlob m_blob10; Unk_LoginBlob m_blob30; unsigned m_n50;
    int m_n54; Unk_LoginMachineId m_id; int m_n68; int m_n6c; unsigned m_n70;
};
MS2_CHECK_SIZE(Unk_LoginC, 0x78);

// @0x1401f9680
void FUN_1401f9680(Unk_LoginC* p, COutputStream* out)
{
    out->vfunc_o10_1(p->m_nType);
    out->vfunc_o10_4(p->m_n08);
    FUN_1406c3380(&p->m_blob10, out);
    FUN_1406c3380(&p->m_blob30, out);
    out->vfunc_o10_2((short)p->m_n50);
    out->vfunc_o10_3(p->m_n54);
    FUN_14067c2c0(&p->m_id, out);
    out->vfunc_o10_3(p->m_n68);
    out->vfunc_o10_3(p->m_n6c);
    out->vfunc_o10_1((unsigned char)p->m_n70);
    out->vfunc_o10_3(p->m_n04);
}
MS2_REPLACE(0x1401F9680, FUN_1401f9680, 280, 0x4C0A9F22);

// @0x1401f97a0
void FUN_1401f97a0(Unk_LoginC* p, Unk_PayloadReader& in)
{
    Unk_SPDByteRange range;
    p->m_nType = in.FUN_140202740(*FUN_140203550(&range, 1, 2));
    p->m_n08 = static_cast<CInputStream&>(in).vfunc_o8_4();
    FUN_1406c33f0(&p->m_blob10, &in);
    FUN_1406c33f0(&p->m_blob30, &in);
    p->m_n50 = (unsigned short)static_cast<CInputStream&>(in).vfunc_o8_2();
    p->m_n54 = static_cast<CInputStream&>(in).vfunc_o8_3();
    FUN_14067c310(&p->m_id, &static_cast<CInputStream&>(in));
    p->m_n68 = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_n6c = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_n70 = static_cast<CInputStream&>(in).vfunc_o8_1();
    p->m_n04 = static_cast<CInputStream&>(in).vfunc_o8_3();
}
MS2_REPLACE(0x1401F97A0, FUN_1401f97a0, 428, 0x8048F6B8);

struct Unk_LoginD {
    unsigned m_nType; __int64 m_n08; CString m_s10; unsigned m_n18; int m_n1c; Unk_LoginMachineId m_id;
    int m_n30; int m_n34; CString m_s38; unsigned m_n40;
};
MS2_CHECK_SIZE(Unk_LoginD, 0x48);

// @0x1401f9960
void FUN_1401f9960(Unk_LoginD* p, COutputStream* out)
{
    out->vfunc_o10_1(p->m_nType);
    out->vfunc_o10_4(p->m_n08);
    out->vfunc_o10_7(p->m_s10);
    out->vfunc_o10_2((short)p->m_n18);
    out->vfunc_o10_3(p->m_n1c);
    FUN_14067c2c0(&p->m_id, out);
    out->vfunc_o10_3(p->m_n30);
    out->vfunc_o10_3(p->m_n34);
    out->vfunc_o10_7(p->m_s38);
    out->vfunc_o10_1((unsigned char)p->m_n40);
}
MS2_REPLACE(0x1401F9960, FUN_1401f9960, 288, 0x69F24D7E);

// @0x1401f9a90
void FUN_1401f9a90(Unk_LoginD* p, Unk_PayloadReader& in)
{
    Unk_SPDByteRange range;
    p->m_nType = in.FUN_140202740(*FUN_140203550(&range, 1, 2));
    p->m_n08 = static_cast<CInputStream&>(in).vfunc_o8_4();
    p->m_s10 = static_cast<CInputStream&>(in).vfunc_o8_7();
    p->m_n18 = (unsigned short)static_cast<CInputStream&>(in).vfunc_o8_2();
    p->m_n1c = static_cast<CInputStream&>(in).vfunc_o8_3();
    FUN_14067c310(&p->m_id, &static_cast<CInputStream&>(in));
    p->m_n30 = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_n34 = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_s38 = static_cast<CInputStream&>(in).vfunc_o8_7();
    p->m_n40 = static_cast<CInputStream&>(in).vfunc_o8_1();
}
MS2_REPLACE(0x1401F9A90, FUN_1401f9a90, 640, 0x732160F3);

// The field-enter request (Unk_NetworkAuth in networkservice.cpp, Unk_SSGEnterRequest in scenestategame.cpp).
struct Unk_LoginEnter { __int64 m_nAccount; int m_n08; int m_n0c; Unk_LoginMachineId m_id; };
MS2_CHECK_SIZE(Unk_LoginEnter, 0x20);

// @0x1401f9d20
void FUN_1401f9d20(Unk_LoginEnter* p, COutputStream* out)
{
    out->vfunc_o10_4(p->m_nAccount);
    out->vfunc_o10_3(p->m_n08);
    out->vfunc_o10_3(p->m_n0c);
    FUN_14067c2c0(&p->m_id, out);
}
MS2_REPLACE(0x1401F9D20, FUN_1401f9d20, 113, 0xBE86F390);

// @0x1401f9da0
void FUN_1401f9da0(Unk_LoginEnter* p, Unk_PayloadReader& in)
{
    p->m_nAccount = static_cast<CInputStream&>(in).vfunc_o8_4();
    p->m_n08 = static_cast<CInputStream&>(in).vfunc_o8_3();
    p->m_n0c = static_cast<CInputStream&>(in).vfunc_o8_3();
    FUN_14067c310(&p->m_id, &static_cast<CInputStream&>(in));
}
MS2_REPLACE(0x1401F9DA0, FUN_1401f9da0, 171, 0x95932D2C);

struct Unk_LoginPing { __int64 m_nValue; short m_nCode; };
MS2_CHECK_SIZE(Unk_LoginPing, 0x10);

// @0x1401f9e60
void FUN_1401f9e60(Unk_LoginPing* p, COutputStream* out)
{
    out->vfunc_o10_4(p->m_nValue);
    out->vfunc_o10_2(p->m_nCode);
}
MS2_REPLACE(0x1401F9E60, FUN_1401f9e60, 68, 0x049D5AFD);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a2a0-0x142c9a2c0 .text$yd
