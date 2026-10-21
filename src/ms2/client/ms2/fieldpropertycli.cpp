// MS2-UNIT: client\ms2\fieldpropertycli.cpp
// MS2-RANGE: 0x140b26ff0-0x140b287b0 .text$mn
// MS2-PIN: ??0FieldPropertyGravityCli@@QEAA@XZ 0x140b28090
// MS2-PIN: ??0FieldPropertyMusicConcertCli@@QEAA@XZ 0x140b28120
// MS2-PIN: ??0FieldPropertyHideMyPCCli@@QEAA@XZ 0x140b280c0
// MS2-PIN: ??0FieldPropertyLockMyPCCli@@QEAA@XZ 0x140b280f0
// MS2-PIN: ??0FieldPropertyUserTagSymbolCli@@QEAA@XZ 0x140b28180
// MS2-PIN: ??0FieldPropertyWeatherCli@@QEAA@XZ 0x140b281b0
// MS2-PIN: ??0FieldPropertyAmbientLightCli@@QEAA@XZ 0x140b27fa0
// MS2-PIN: ??0FieldPropertyDirectionalLightCli@@QEAA@XZ 0x140b28000
// MS2-PIN: ??0FieldPropertyEnableLocalCameraCli@@QEAA@XZ 0x140b28060
// MS2-PIN: ??0FieldPropertyPhotoStudioCli@@QEAA@XZ 0x140b28150
// MS2-PIN: ??_GFieldPropertyAmbientLightCli@@UEAAPEAXI@Z 0x140b28320
// MS2-PIN: ??_GFieldPropertyDirectionalLightCli@@UEAAPEAXI@Z 0x140b28360
// MS2-PIN: ??_GFieldPropertyEnableLocalCameraCli@@UEAAPEAXI@Z 0x140b283a0
// MS2-PIN: ??_GFieldPropertyGravityCli@@UEAAPEAXI@Z 0x140b283e0
// MS2-PIN: ??_GFieldPropertyHideMyPCCli@@UEAAPEAXI@Z 0x140b28420
// MS2-PIN: ??_GFieldPropertyLockMyPCCli@@UEAAPEAXI@Z 0x140b28460
// MS2-PIN: ??_GFieldPropertyMusicConcertCli@@UEAAPEAXI@Z 0x140b284a0
// MS2-PIN: ??_GFieldPropertyPhotoStudioCli@@UEAAPEAXI@Z 0x140b284e0
// MS2-PIN: ??_GFieldPropertyUserTagSymbolCli@@UEAAPEAXI@Z 0x140b28520
// MS2-PIN: ??_GFieldPropertyWeatherCli@@UEAAPEAXI@Z 0x140b28560
//
// Client-side FieldProperty subclasses: Apply (vfunc_4) pushes the property into the client systems, Unapply (vfunc_5)
// resets it. Everything the bodies call is another unit's code, declared as FUN_<va> externs.
#include "ms2/client/ms2/fieldpropertycli.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include <cassert>
#ifdef __clang__
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // clang-cl: assert.h hides it under NDEBUG
#endif
#include <atlbase.h>

// ---- unit-local stand-ins for helpers of other units (opaque) ----
struct Unk_Handle {                 // 24 byte handle filled by FUN_141bd0420, released by ~Unk_Handle (0x1409f20e0)
    ~Unk_Handle();
    void* m_a; void* m_p; void* m_c;
};
struct Unk_EntRef {                 // entity reference built from the handle's entity (0x1408a7ed0), released at 0x1408a8720
    Unk_EntRef(void* p);
    ~Unk_EntRef();
    void* m_p;
};
struct Unk_Raw12 { int a, b, c; };               // uninitialised colour scratch (filled by FUN_1406c3780)
struct Unk_Raw16 { __int64 a, b; };
struct Unk_Rec24 { char b[24]; };
namespace egf {
enum PropertyResult { PropertyResult_Unknown };
class Entity {
protected:
    PropertyResult GetPropertyValueUnsafe(unsigned id, void* pValue, unsigned type) const;     // 0x14212b480
    PropertyResult SetPropertyValueUnsafe(unsigned id, const void* pValue, unsigned type);     // 0x14212f160
};
}
struct Unk_EntityAccess : egf::Entity {
    egf::PropertyResult Get(unsigned id, void* p, unsigned t) const { return GetPropertyValueUnsafe(id, p, t); }
    egf::PropertyResult Set(unsigned id, const void* p, unsigned t) { return SetPropertyValueUnsafe(id, p, t); }
};

void* FUN_1403ed2d0();                                       // game singleton getters
void* FUN_1403ed280();
void* FUN_1403ed2b0();
void* FUN_1409478c0();
void FUN_141bca3c0(void* o, float fGravity);
void FUN_141bcad60(void* o, __int64 a, int b);
void* FUN_141bd0cc0(void* o);
void FUN_14166ca20(void* p, int n);
void FUN_14166ca80(void* p, int n);
void FUN_14166cce0(void* p, int n);
void FUN_14166cd70(void* p, int n);
void* FUN_1416764a0(void* p);
void* FUN_141676a10(void* p);
void FUN_141bcabf0(void* o);
void FUN_1411a7e80(void* o, int n);
void FUN_140aeb900(void* o, unsigned char b);
void FUN_141adc530(void* o, int n);
void FUN_141adc5d0(void* o, int n);
void FUN_141bd0420(void* o, Unk_Handle* out, unsigned hash);
bool FUN_1409f2130(Unk_Handle* h, int n);
void* FUN_1409f2190(Unk_Handle* h);
void* FUN_140b285a0(void* p);
void* FUN_140b285b0(void* p);
void* FUN_1408a9280(Unk_EntRef* r);
Unk_Vec3f* FUN_1406c3780(Unk_Rgb3b* c, Unk_Vec3f* out);      // rgb bytes -> 0..1 floats
void FUN_140b27ec0(void* ent, unsigned id, void* p);
void FUN_140b27f00(void* ent, unsigned id, void* p);
unsigned FUN_140b27eb0();

// ---- the factory ----
// @0x140b26ff0
MS2Ptr<FieldProperty> FUN_140b26ff0(int nType)
{
    switch (nType)
    {
    case 1:  return MS2Ptr<FieldProperty>(new FieldPropertyGravityCli());
    case 2:  return MS2Ptr<FieldProperty>(new FieldPropertyMusicConcertCli());
    case 3:  return MS2Ptr<FieldProperty>(new FieldPropertyHideMyPCCli());
    case 4:  return MS2Ptr<FieldProperty>(new FieldPropertyLockMyPCCli());
    case 5:  return MS2Ptr<FieldProperty>(new FieldPropertyUserTagSymbolCli());
    case 6:  return MS2Ptr<FieldProperty>(new FieldPropertySightRange());
    case 7:  return MS2Ptr<FieldProperty>(new FieldPropertyWeatherCli());
    case 8:  return MS2Ptr<FieldProperty>(new FieldPropertyAmbientLightCli());
    case 9:  return MS2Ptr<FieldProperty>(new FieldPropertyDirectionalLightCli());
    case 10: return MS2Ptr<FieldProperty>(new FieldPropertyEnableLocalCameraCli());
    case 11: return MS2Ptr<FieldProperty>(new FieldPropertyPhotoStudioCli());
    default:
        (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fieldpropertycli.cpp", 0x27), 0));
        return MS2Ptr<FieldProperty>(0);
    }
}

// ---- Apply / Unapply ----
// @0x140b27660
void FieldPropertyGravityCli::vfunc_4() { FUN_141bca3c0(FUN_1403ed2d0(), m_fGravity); }

// @0x140b27690
void FieldPropertyMusicConcertCli::vfunc_4() { FUN_141bcad60(FUN_1403ed2d0(), m_i64, m_n); }
// @0x140b276d0
void FieldPropertyMusicConcertCli::vfunc_5() { FUN_141bcad60(FUN_1403ed2d0(), 0, 0); }

// @0x140b27700
void FieldPropertyHideMyPCCli::vfunc_4()
{
    void* p = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!p)
        return;
    FUN_14166ca20(p, 1);
    void* q = FUN_1416764a0(p);
    if (q)
        FUN_14166ca20(q, 1);
    void* r = FUN_141676a10(p);
    if (r)
        FUN_14166ca20(p, 1);            // sic: the exe passes p again
}
// @0x140b27790
void FieldPropertyHideMyPCCli::vfunc_5()
{
    void* p = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!p)
        return;
    FUN_14166ca80(p, 1);
    void* q = FUN_1416764a0(p);
    if (q)
        FUN_14166ca80(q, 1);
    void* r = FUN_141676a10(p);
    if (r)
        FUN_14166ca80(p, 1);            // sic: the exe passes p again
}

// @0x140b27820
void FieldPropertyLockMyPCCli::vfunc_4()
{
    void* p = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!p)
        return;
    FUN_14166cce0(p, 0x400);
}
// @0x140b27860
void FieldPropertyLockMyPCCli::vfunc_5()
{
    void* p = FUN_141bd0cc0(FUN_1403ed2d0());
    if (!p)
        return;
    FUN_14166cd70(p, 0x400);
}

// @0x140b278a0
void FieldPropertyUserTagSymbolCli::vfunc_4() { FUN_141bcabf0(FUN_1403ed2d0()); }

// @0x140b278d0
void FieldPropertyWeatherCli::vfunc_4() { FUN_1411a7e80(FUN_1403ed280(), m_nWeather); }
// @0x140b27900
void FieldPropertyWeatherCli::vfunc_5() { FUN_1411a7e80(FUN_1403ed280(), 0); }

// MS2-FUNCTIONAL: stack layout / GS differs (safebuffers approximates the exe's missing cookie)
// @0x140b27930
__declspec(safebuffers) void FieldPropertyAmbientLightCli::vfunc_4()
{
    Unk_Handle h;
    FUN_141bd0420(FUN_1403ed2d0(), &h, 0x169ea355);
    if (FUN_1409f2130(&h, 0) || !FUN_140b285a0(FUN_1409f2190(&h)))
        return;
    Unk_EntRef ent(FUN_140b285b0(FUN_1409f2190(&h)));
    if (m_bFlag)
    {
        m_bCached = true;
        m_fCached = 0;
        Unk_Vec3f* pOld = &m_vecOld;
        FUN_140b27ec0(FUN_1408a9280(&ent), 0xb086f4a8, pOld);
        return;
    }
    Unk_Raw16 tmp;
    Unk_Vec3f* pv = FUN_1406c3780(&m_color, (Unk_Vec3f*)&tmp);
    FUN_140b27f00(FUN_1408a9280(&ent), 0xb086f4a8, pv);
}

// @0x140b27a80
Unk_Vec3f* FUN_140b27a80(FieldPropertyAmbientLightCli* p, Unk_Vec3f* out) { FUN_1406c3780(&p->m_color, out); return out; }

// MS2-FUNCTIONAL: stack layout / GS differs
// @0x140b27ac0
__declspec(safebuffers) void FieldPropertyDirectionalLightCli::vfunc_4()
{
    Unk_Handle h;
    FUN_141bd0420(FUN_1403ed2d0(), &h, 0x628f2cf9);
    if (FUN_1409f2130(&h, 0) || !FUN_140b285a0(FUN_1409f2190(&h)))
        return;
    Unk_EntRef ent(FUN_140b285b0(FUN_1409f2190(&h)));
    if (m_bFlag)
    {
        m_bCached = true;
        m_fCached = 0;
        Unk_Vec3f* pOld = &m_vecOld;
        FUN_140b27ec0(FUN_1408a9280(&ent), 0x2d8cf386, pOld);
        return;
    }
    Unk_Raw12 t1, t2;
    Unk_Vec3f* p1 = FUN_1406c3780(&m_color1, (Unk_Vec3f*)&t1);
    FUN_140b27f00(FUN_1408a9280(&ent), 0x2d8cf386, p1);
    Unk_Vec3f* p2 = FUN_1406c3780(&m_color1, (Unk_Vec3f*)&t2);
    FUN_140b27f00(FUN_1408a9280(&ent), 0xc3f0329e, p2);
}

// @0x140b27c60
Unk_Vec3f* FUN_140b27c60(FieldPropertyDirectionalLightCli* p, Unk_Vec3f* out) { FUN_1406c3780(&p->m_color1, out); return out; }

// @0x140b27ca0
void FieldPropertyEnableLocalCameraCli::vfunc_4() { FUN_140aeb900(FUN_1409478c0(), m_b); }
// @0x140b27cd0
void FieldPropertyEnableLocalCameraCli::vfunc_5() { FUN_140aeb900(FUN_1409478c0(), 1); }

// @0x140b27d00
void FieldPropertyPhotoStudioCli::vfunc_4() { FUN_141adc530(FUN_1403ed2b0(), 0x4f8f); }
// @0x140b27d30
void FieldPropertyPhotoStudioCli::vfunc_5() { FUN_141adc5d0(FUN_1403ed2b0(), 0x4f8f); }

// ---- Entity property helpers (egf::Entity; the change-tracking map lives at entity+0xd0) ----
void* FUN_1409481f0(void* map, void* it);
void* FUN_140948250(void* map, void* it, unsigned* key);
bool FUN_140947540(void* a, void* b);
void* FUN_140947490(void* it, unsigned id, void* pVal, unsigned type);
void* FUN_140947580(void* map, unsigned* key);

// MS2-FUNCTIONAL: remembers the entity's original value for a property before it is overwritten (map find/insert)
// @0x140b27d50
void FUN_140b27d50(egf::Entity* pEntity, unsigned id, void* pNew)
{
    char* e = (char*)pEntity;
    if (*(unsigned char*)(e + 0xc8))
    {
        char it1[8], it2[8];
        void* endIt = FUN_1409481f0(e + 0xd0, it1);
        if (FUN_140947540(FUN_140948250(e + 0xd0, it2, &id), endIt))
        {
            Unk_Vec3f old(0, 0, 0);
            ((Unk_EntityAccess*)pEntity)->Get(id, &old, FUN_140b27eb0());
            Unk_Vec3f* copy = new Unk_Vec3f(old);
            char it3[40];
            Unk_Rec24* rec = (Unk_Rec24*)FUN_140947490(it3, id, copy, FUN_140b27eb0());
            *(Unk_Rec24*)FUN_140947580(e + 0xd0, &id) = *rec;
        }
    }
}

// @0x140b27eb0
unsigned FUN_140b27eb0() { return 0xf0000012; }

// @0x140b27ec0
void FUN_140b27ec0(void* ent, unsigned id, void* p) { ((Unk_EntityAccess*)ent)->Get(id, p, FUN_140b27eb0()); }

// @0x140b27f00
void FUN_140b27f00(void* ent, unsigned id, void* p)
{
    FUN_140b27d50((egf::Entity*)ent, id, p);
    ((Unk_EntityAccess*)ent)->Set(id, p, FUN_140b27eb0());
}

// ---- MS2Ptr<FieldProperty> helpers (instantiated here; ms2ptr_impl.h generic bodies) ----
// @0x140b285a0
void* FUN_140b285a0(void* p) { return *(void**)((char*)p + 0x10); }

// @0x140b285b0
void* FUN_140b285b0(void* p)
{
    ATLENSURE_THROW(*(void**)p, E_FAIL);
    return (char*)*(void**)p + 0x10;
}

// the UCRT header-inline memmove_s, emitted here as an ordinary function
#include <errno.h>
#include <string.h>
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)   \
    {                                                  \
        int _Expr_val = !!(expr);                      \
        if (!(_Expr_val)) {                            \
            errno = errorcode;                         \
            _invalid_parameter_noinfo();               \
            return errorcode;                          \
        }                                              \
    }
// @0x140b28690
errno_t FUN_140b28690(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}

// ---- destructors (forward to the server class; no vptr store) ----
// @0x140b281e0
void FUN_140b281e0(FieldPropertyAmbientLightCli* p) { p->FieldPropertyAmbientLight::~FieldPropertyAmbientLight(); }
// @0x140b28200
void FUN_140b28200(FieldPropertyDirectionalLightCli* p) { p->FieldPropertyDirectionalLight::~FieldPropertyDirectionalLight(); }
// @0x140b28220
void FUN_140b28220(FieldPropertyEnableLocalCameraCli* p) { p->FieldPropertyEnableLocalCamera::~FieldPropertyEnableLocalCamera(); }
// @0x140b28240
void FUN_140b28240(FieldPropertyGravityCli* p) { p->FieldPropertyGravity::~FieldPropertyGravity(); }
// @0x140b28260
void FUN_140b28260(FieldPropertyHideMyPCCli* p) { p->FieldPropertyHideMyPC::~FieldPropertyHideMyPC(); }
// @0x140b28280
void FUN_140b28280(FieldPropertyLockMyPCCli* p) { p->FieldPropertyLockMyPC::~FieldPropertyLockMyPC(); }
// @0x140b282a0
void FUN_140b282a0(FieldPropertyMusicConcertCli* p) { p->FieldPropertyMusicConcert::~FieldPropertyMusicConcert(); }
// @0x140b282c0
void FUN_140b282c0(FieldPropertyPhotoStudioCli* p) { p->FieldPropertyPhotoStudio::~FieldPropertyPhotoStudio(); }
// @0x140b282e0
void FUN_140b282e0(FieldPropertyUserTagSymbolCli* p) { p->FieldPropertyUserTagSymbol::~FieldPropertyUserTagSymbol(); }
// @0x140b28300
void FUN_140b28300(FieldPropertyWeatherCli* p) { p->FieldPropertyWeather::~FieldPropertyWeather(); }

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
#include "hook/ms2hook.h"
MS2_REPLACE_METHOD(0x140b27660, FieldPropertyGravityCli, vfunc_4, 37, 0x6E525173);
MS2_REPLACE_METHOD(0x140b27690, FieldPropertyMusicConcertCli, vfunc_4, 45, 0xFDA128BC);
MS2_REPLACE_METHOD(0x140b276d0, FieldPropertyMusicConcertCli, vfunc_5, 32, 0x4DC02E87);
MS2_REPLACE_METHOD(0x140b27700, FieldPropertyHideMyPCCli, vfunc_4, 133, 0x8DB9D34E);
MS2_REPLACE_METHOD(0x140b27790, FieldPropertyHideMyPCCli, vfunc_5, 133, 0xC40C60A3);
MS2_REPLACE_METHOD(0x140b27820, FieldPropertyLockMyPCCli, vfunc_4, 57, 0x50E4CE2C);
MS2_REPLACE_METHOD(0x140b27860, FieldPropertyLockMyPCCli, vfunc_5, 57, 0xCD9CD6DC);
MS2_REPLACE_METHOD(0x140b278a0, FieldPropertyUserTagSymbolCli, vfunc_4, 27, 0x622133FB);
MS2_REPLACE_METHOD(0x140b278d0, FieldPropertyWeatherCli, vfunc_4, 35, 0x43231132);
MS2_REPLACE_METHOD(0x140b27900, FieldPropertyWeatherCli, vfunc_5, 29, 0x45C5C1E0);
MS2_REPLACE(0x140b27a80, FUN_140b27a80, 46, 0xFF3862E1);
MS2_REPLACE(0x140b27c60, FUN_140b27c60, 46, 0x77829EFF);
MS2_REPLACE_METHOD(0x140b27ca0, FieldPropertyEnableLocalCameraCli, vfunc_4, 36, 0x3EC2A4E7);
MS2_REPLACE_METHOD(0x140b27cd0, FieldPropertyEnableLocalCameraCli, vfunc_5, 29, 0x41CD19A7);
MS2_REPLACE_METHOD(0x140b27d00, FieldPropertyPhotoStudioCli, vfunc_4, 32, 0x9E7FC2AE);
MS2_REPLACE_METHOD(0x140b27d30, FieldPropertyPhotoStudioCli, vfunc_5, 32, 0x1FE7D96E);
MS2_REPLACE(0x140b27eb0, FUN_140b27eb0, 6, 0x45E646C2);
MS2_REPLACE(0x140b27ec0, FUN_140b27ec0, 50, 0x1305F788);
MS2_REPLACE(0x140b27f00, FUN_140b27f00, 69, 0x1DC18B03);
MS2_REPLACE(0x140b285a0, FUN_140b285a0, 15, 0x6BC6B691);
MS2_REPLACE(0x140b285b0, FUN_140b285b0, 92, 0x5368ACA2);
MS2_REPLACE(0x140b281e0, FUN_140b281e0, 24, 0xBA686CA9);
MS2_REPLACE(0x140b28200, FUN_140b28200, 24, 0xBA686CA9);
MS2_REPLACE(0x140b28220, FUN_140b28220, 24, 0xBA686CA9);
MS2_REPLACE(0x140b28240, FUN_140b28240, 24, 0xBA686CA9);
MS2_REPLACE(0x140b28260, FUN_140b28260, 24, 0xBA686CA9);
MS2_REPLACE(0x140b28280, FUN_140b28280, 24, 0xBA686CA9);
MS2_REPLACE(0x140b282a0, FUN_140b282a0, 24, 0xBA686CA9);
MS2_REPLACE(0x140b282c0, FUN_140b282c0, 24, 0xBA686CA9);
MS2_REPLACE(0x140b282e0, FUN_140b282e0, 24, 0x73BA3849);
MS2_REPLACE(0x140b28300, FUN_140b28300, 24, 0x7B5DC969);

