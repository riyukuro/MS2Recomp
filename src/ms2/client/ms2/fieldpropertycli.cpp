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
#include <atlcoll.h>        // C3: the entity list of the handle
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<egf::Entity>
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::FUN_141adc5d0
#include "ms2/commonfiles/os.h"

// ---- unit-local stand-ins for helpers of other units (opaque) ----
namespace egf { class Entity; }
typedef ATL::CAtlList<efd::SmartPointer<egf::Entity> > Unk_FpEntityList;
struct Unk_WsC_TagPtr {             // 16 byte handle filled by WorldService::FUN_141bd0420 (worldservice_1.cpp defines it)
    ~Unk_WsC_TagPtr();                              // 0x1409f20e0
    Unk_FpEntityList* operator->() const; bool operator==(Unk_FpEntityList* p) const;   // 0x1409f2190 / 0x1409f2130
    void* m_a; void* m_p;
};
// (operator== 0x1409f2130: Unk_WsC_TagPtr::operator==, worldservice_1.cpp)
struct Unk_Rec24 { char b[24]; };
struct Unk_MapIt { void* p; };                   // map iterator scratch
struct Unk_MapPair { void* a[4]; };              // 32 byte (key, value) pair scratch
namespace egf {
enum PropertyResult { PropertyResult_Unknown };
class Entity {
protected:
    PropertyResult GetPropertyValueUnsafe(unsigned id, void* pValue, unsigned type) const;     // 0x14212b480
    PropertyResult SetPropertyValueUnsafe(unsigned id, const void* pValue, unsigned type);     // 0x14212f160
};
}
// The entity reference built from the handle's entity.
template <> efd::SmartPointer<egf::Entity>::SmartPointer(const efd::SmartPointer<egf::Entity>& ptr);   // 0x1408a7ed0
template <> efd::SmartPointer<egf::Entity>::~SmartPointer();                                         // 0x1408a8720
template <> egf::Entity* efd::SmartPointer<egf::Entity>::operator->() const;                         // 0x1408a9280
struct Unk_EntityAccess : egf::Entity {
    egf::PropertyResult Get(unsigned id, void* p, unsigned t) const { return GetPropertyValueUnsafe(id, p, t); }
    egf::PropertyResult Set(unsigned id, const void* p, unsigned t) { return SetPropertyValueUnsafe(id, p, t); }
};

class WorldService   // C3: member view for the former free stand-ins
{
public:
    int SetGravity(float);
    void FUN_141bcabf0();
    void* GetLocalPlayer();
    void SetMusicConcert(void* p, int n);
    Unk_WsC_TagPtr FUN_141bd0420(unsigned key);   // the entities of a model
    static class WorldService* GetInstance();
};
class CEffectService;
class CUIService;
class CameraMgr;
template<> CameraMgr* TSingleton<CameraMgr>::GetInstance();   // actioncameramode.cpp defines it
class PCBase   // C3: member view for the former free stand-ins
{
public:
    class Ridee* GetRidee();
    void* FUN_141676a10();
public:
    void AddHideReason(unsigned int);   // C3: was free AddHideReason
public:
    void RemoveHideReason(unsigned int);   // C3: was free RemoveHideReason
public:
    void AddStateFlags(unsigned int);   // C3: was free AddStateFlags
public:
    void RemoveStateFlags(unsigned int);   // C3: was free RemoveStateFlags
};
class CEffectService   // C3: member view for the former free stand-ins
{
public:
    void FUN_1411a7e80(int);
};
class CameraMgr   // C3: member view
{
public:
    void FUN_140aeb900(bool b);
};
// C3: was the Unk_PCWorld view of WorldService (FUN_1403ed2d0)
//   for FUN_141bd0420 (the entities of a model): it is WorldService's own member.
void* FUN_140b285a0(void* p);
void* FUN_140b285b0(void* p);
// 0x1406c3780 = Unk_Rgb3b::ToColor (rgb bytes -> 0..1 floats, fieldproperty.h)
void FUN_140b27ec0(void* ent, unsigned id, void* p);
void FUN_140b27f00(void* ent, unsigned id, void* p);
unsigned FUN_140b27eb0();

// ---- the factory ----
// @0x140b26ff0
MS2Ptr<FieldProperty> CreateFieldProperty(int nType)
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
void FieldPropertyGravityCli::vfunc_4() { ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->SetGravity(m_fGravity); }

// @0x140b27690
void FieldPropertyMusicConcertCli::vfunc_4() { WorldService::GetInstance()->SetMusicConcert((void*)m_i64, m_n); }
// @0x140b276d0
void FieldPropertyMusicConcertCli::vfunc_5() { WorldService::GetInstance()->SetMusicConcert(0, 0); }

// @0x140b27700
void FieldPropertyHideMyPCCli::vfunc_4()
{
    void* p = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (!p)
        return;
    ((class PCBase*)(void*)(p))->AddHideReason(1);
    void* q = ((void*)((class PCBase*)(void*)(p))->GetRidee());
    if (q)
        ((class PCBase*)(void*)(q))->AddHideReason(1);
    void* r = ((class PCBase*)(void*)(p))->FUN_141676a10();
    if (r)
        ((class PCBase*)(void*)(p))->AddHideReason(1);            // sic: the exe passes p again
}
// @0x140b27790
void FieldPropertyHideMyPCCli::vfunc_5()
{
    void* p = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (!p)
        return;
    ((class PCBase*)(void*)(p))->RemoveHideReason(1);
    void* q = ((void*)((class PCBase*)(void*)(p))->GetRidee());
    if (q)
        ((class PCBase*)(void*)(q))->RemoveHideReason(1);
    void* r = ((class PCBase*)(void*)(p))->FUN_141676a10();
    if (r)
        ((class PCBase*)(void*)(p))->RemoveHideReason(1);            // sic: the exe passes p again
}

// @0x140b27820
void FieldPropertyLockMyPCCli::vfunc_4()
{
    void* p = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (!p)
        return;
    ((class PCBase*)(void*)(p))->AddStateFlags(0x400);
}
// @0x140b27860
void FieldPropertyLockMyPCCli::vfunc_5()
{
    void* p = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (!p)
        return;
    ((class PCBase*)(void*)(p))->RemoveStateFlags(0x400);
}

// @0x140b278a0
void FieldPropertyUserTagSymbolCli::vfunc_4() { ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bcabf0(); }

// @0x140b278d0
void FieldPropertyWeatherCli::vfunc_4() { TSingleton<CEffectService>::GetInstance()->FUN_1411a7e80(m_nWeather); }
// @0x140b27900
void FieldPropertyWeatherCli::vfunc_5() { TSingleton<CEffectService>::GetInstance()->FUN_1411a7e80(0); }

// @0x140b27930
void FieldPropertyAmbientLightCli::vfunc_4()
{
    Unk_WsC_TagPtr h = WorldService::GetInstance()->FUN_141bd0420(0x169ea355);
    if (h == 0 || !FUN_140b285a0(h.operator->()))
        return;
    efd::SmartPointer<egf::Entity> ent(*(const efd::SmartPointer<egf::Entity>*)FUN_140b285b0(h.operator->()));
    if (m_bFlag)
    {
        m_bCached = true;
        m_fCached = 0;
        FUN_140b27ec0(ent.operator->(), 0xb086f4a8, &m_vecOld);
        return;
    }
    FUN_140b27f00(ent.operator->(), 0xb086f4a8, (void*)&static_cast<const Unk_Vec3f&>(m_color.ToColor()));
}

// @0x140b27a80
Unk_Vec3f FieldPropertyAmbientLightCli::GetColor() const { return m_color.ToColor(); }

// @0x140b27ac0
void FieldPropertyDirectionalLightCli::vfunc_4()
{
    Unk_WsC_TagPtr h = WorldService::GetInstance()->FUN_141bd0420(0x628f2cf9);
    if (h == 0 || !FUN_140b285a0(h.operator->()))
        return;
    efd::SmartPointer<egf::Entity> ent(*(const efd::SmartPointer<egf::Entity>*)FUN_140b285b0(h.operator->()));
    if (m_bFlag)
    {
        m_bCached = true;
        m_fCached = 0;
        FUN_140b27ec0(ent.operator->(), 0x2d8cf386, &m_vecOld);
        return;
    }
    FUN_140b27f00(ent.operator->(), 0x2d8cf386, (void*)&static_cast<const Unk_Vec3f&>(m_color1.ToColor()));
    FUN_140b27f00(ent.operator->(), 0xc3f0329e, (void*)&static_cast<const Unk_Vec3f&>(m_color1.ToColor()));
}

// @0x140b27c60
Unk_Vec3f FieldPropertyDirectionalLightCli::GetColor() const { return m_color1.ToColor(); }

// @0x140b27ca0
void FieldPropertyEnableLocalCameraCli::vfunc_4() { ((CameraMgr*)TSingleton<CameraMgr>::GetInstance())->FUN_140aeb900(m_b); }
// @0x140b27cd0
void FieldPropertyEnableLocalCameraCli::vfunc_5() { ((CameraMgr*)TSingleton<CameraMgr>::GetInstance())->FUN_140aeb900(1); }

// @0x140b27d00
void FieldPropertyPhotoStudioCli::vfunc_4() { (TSingleton<CUIService>::GetInstance()->OpenDialog((eUIClassID)(0x4f8f))); }
// @0x140b27d30
void FieldPropertyPhotoStudioCli::vfunc_5() { TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4f8f); }

// ---- Entity property helpers (egf::Entity; the change-tracking map lives at entity+0xd0) ----
#include <efd/StdContainers.h>
// C3: the map is the real efd::map<unsigned, Unk_PropertyCacheEntry> (find 0x140948250, end 0x1409481f0,
// const_iterator::operator== 0x140947540, operator[] 0x140947580; glue in actioncameramode, see propertycache.h).
struct Unk_PropertyCacheEntry {     // C3: was the free FUN_140947490 (the inline ctor of alphaanimation's view)
    Unk_PropertyCacheEntry(unsigned nId, void* pValue, unsigned nType);   // 0x140947490
    Unk_PropertyCacheEntry() : m_id(0), m_pValue(NULL), m_type(0) {}   unsigned m_id; void* m_pValue; unsigned m_type;   // () 0x1409474d0
};
typedef efd::map<unsigned, Unk_PropertyCacheEntry> Unk_PropertyCacheMap;

// Remembers the entity's original value for a property before it is overwritten (map find/insert).
// @0x140b27d50
void FUN_140b27d50(egf::Entity* pEntity, unsigned id, void* pNew)
{
    if (*((unsigned char*)pEntity + 0xc8))
    {

        if (((Unk_PropertyCacheMap*)((char*)pEntity + 0xd0))->find(id) == ((Unk_PropertyCacheMap*)((char*)pEntity + 0xd0))->end())
        {
            Unk_Vec3f old(0, 0, 0);
            ((Unk_EntityAccess*)pEntity)->Get(id, &old, FUN_140b27eb0());
            *(Unk_Rec24*)&(*(Unk_PropertyCacheMap*)((char*)pEntity + 0xd0))[id] = reinterpret_cast<const Unk_Rec24&>(static_cast<const Unk_PropertyCacheEntry&>(Unk_PropertyCacheEntry(id, new Unk_Vec3f(old), FUN_140b27eb0())));
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
MS2_REPLACE_METHOD(0x140b27a80, FieldPropertyAmbientLightCli, GetColor, 46, 0xFF3862E1);
MS2_REPLACE_METHOD(0x140b27c60, FieldPropertyDirectionalLightCli, GetColor, 46, 0x77829EFF);
MS2_REPLACE_METHOD(0x140b27ca0, FieldPropertyEnableLocalCameraCli, vfunc_4, 36, 0x3EC2A4E7);
MS2_REPLACE_METHOD(0x140b27cd0, FieldPropertyEnableLocalCameraCli, vfunc_5, 29, 0x41CD19A7);
MS2_REPLACE_METHOD(0x140b27d00, FieldPropertyPhotoStudioCli, vfunc_4, 32, 0x9E7FC2AE);
MS2_REPLACE_METHOD(0x140b27d30, FieldPropertyPhotoStudioCli, vfunc_5, 32, 0x1FE7D96E);
MS2_REPLACE(0x140b27eb0, FUN_140b27eb0, 6, 0x45E646C2);
MS2_REPLACE(0x140b27ec0, FUN_140b27ec0, 50, 0x1305F788);
MS2_REPLACE(0x140b27f00, FUN_140b27f00, 69, 0x1DC18B03);
MS2_REPLACE(0x140b285a0, FUN_140b285a0, 15, 0x6BC6B691);
MS2_REPLACE(0x140b285b0, FUN_140b285b0, 92, 0x5368ACA2);
MS2_REPLACE_DTOR(0x140b281e0, FieldPropertyAmbientLightCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b28200, FieldPropertyDirectionalLightCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b28220, FieldPropertyEnableLocalCameraCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b28240, FieldPropertyGravityCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b28260, FieldPropertyHideMyPCCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b28280, FieldPropertyLockMyPCCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b282a0, FieldPropertyMusicConcertCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b282c0, FieldPropertyPhotoStudioCli, 24, 0xBA686CA9);
MS2_REPLACE_DTOR(0x140b282e0, FieldPropertyUserTagSymbolCli, 24, 0x73BA3849);
MS2_REPLACE_DTOR(0x140b28300, FieldPropertyWeatherCli, 24, 0x7B5DC969);

