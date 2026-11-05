// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See autofindtaxistation.h.
// MS2-UNIT: ?\autofindtaxistation.cpp
// MS2-RANGE: 0x1409f11a0-0x1409f2670 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVCAutoFindTaxiStation@@P82@EAAXXZ@@UEAA@XZ 0x1409f2080 ; prop
// MS2-PIN: ??1?$FunctorImpl@XVEmptyParam@@@@UEAA@XZ 0x1409f20a0 ; prop
// MS2-PIN: ??_G?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVCAutoFindTaxiStation@@P82@EAAXXZ@@UEAAPEAXI@Z 0x1409f21d0 ; prop
// MS2-PIN: ??_G?$FunctorImpl@XVEmptyParam@@@@UEAAPEAXI@Z 0x1409f2210 ; prop
// MS2-PIN: ??_G?$FunctorImplBase@X@@UEAAPEAXI@Z 0x1409f2250 ; prop
// MS2-PIN: ??_G?$TSingleton@VCAutoFindTaxiStation@@@@UEAAPEAXI@Z 0x1409f2290 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?get@?$MS2Ptr@VCCameraMode@@@@QEBAPEAVCCameraMode@@XZ 0x1409f2180
// MS2-PIN: ??C?$MS2Ptr@VCCameraMode@@@@QEBAPEAVCCameraMode@@XZ 0x1409f21a0
// MS2-PIN: ?Invoke@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVCAutoFindTaxiStation@@P82@EAAXXZ@@UEAAXXZ 0x1409f21b0
// MS2-PIN: ??_GCAutoFindTaxiStation@@UEAAPEAXI@Z 0x1409f22d0
// MS2-PIN: ??1?$Unk_TaxiPtr@V?$CAtlList@UUnk_TaxiEntRef@@V?$CElementTraits@UUnk_TaxiEntRef@@@ATL@@@ATL@@@@QEAA@XZ 0x1409f20e0
// MS2-PIN: ?get@?$Unk_TaxiPtr@V?$CAtlList@UUnk_TaxiEntRef@@V?$CElementTraits@UUnk_TaxiEntRef@@@ATL@@@ATL@@@@QEBAPEAV?$CAtlList@UUnk_TaxiEntRef@@V?$CElementTraits@UUnk_TaxiEntRef@@@ATL@@@ATL@@XZ 0x1409f2170
// MS2-PIN: ??C?$Unk_TaxiPtr@V?$CAtlList@UUnk_TaxiEntRef@@V?$CElementTraits@UUnk_TaxiEntRef@@@ATL@@@ATL@@@@QEBAPEAV?$CAtlList@UUnk_TaxiEntRef@@V?$CElementTraits@UUnk_TaxiEntRef@@@ATL@@@ATL@@XZ 0x1409f2190
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\autofindtaxistation.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <atlcoll.h>
#include "autofindtaxistation.h"
#include "cameramode.h"
#include "homecameramode.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/tfunctor.h"
#include "ms2/placeholder/oncecallbacktimer.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <egf/Entity.h>   // C3: egf::Entity::GetPropertyValue<efd::Point3>
class CameraMgr;
template <> class TSingleton<CameraMgr> { public: static CameraMgr* GetInstance(); };   // C3: 0x1409478c0, as camera.h declares it

// ---- types local to this unit (all member names invented) ----

// Entity reference stored in the world service's lists (8 bytes). Its members are inline COMDATs of other objs.
struct Unk_TaxiEntRef
{
    void FUN_1408a7ed0(const Unk_TaxiEntRef& o);        // copy ctor
    struct Unk_TaxiEnt* FUN_1408a9280();                // operator->
    void FUN_1408a8720();                               // dtor
    void* m_p;
};

typedef ATL::CAtlList<Unk_TaxiEntRef> Unk_TaxiEntList;

// 16-byte smart pointer to a boxed value (TPtredDummy<T>): the CPtred header sits 0x18 bytes before the pointee.
template <class T>
class Unk_TaxiPtr
{
public:
    bool operator==(T* p) const { return m_p == p; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
    ~Unk_TaxiPtr() { Release(); }
    void Release()
    {
        if (m_p)
        {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    void ReleaseImpl(void*)
    {
        CPtred* owner = Owner(m_p);
        if (CPtred::ReleasePtred(owner) == 0)
        {
            Ref(owner);
            CPtred::DeletePtred(owner);
        }
    }
    static void Ref(CPtred* p) { CPtred::AddRefPtred(p); }
    static TPtredDummy<T>* Owner(T* p)
    {
        return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
    }
    void* m_00;
    T* m_p;
};

typedef Unk_TaxiPtr<Unk_TaxiEntList> Unk_TaxiListPtr;

// World service pieces reached through FUN_1403ed2d0.
class Unk_TaxiPlayer;
class Unk_TaxiCtx
{
public:
    Unk_TaxiListPtr FUN_141bd0420(unsigned hash);
    Unk_TaxiPlayer* FUN_141bd0cc0();
};
struct Unk_TaxiInfo { char m_pad[0xb8]; int m_nValue; };
class Unk_TaxiResTable;
class Unk_TaxiTimer;
struct Unk_TaxiEnt { };

extern ATL::CAtlArray<unsigned int> DAT_143ab3078;            // the taxi stops found (ids)
extern ATL::CAtlArray<unsigned int> DAT_143ab3098;
extern int DAT_143ab2870;                               // taxi station id (resource id)
class CTaxiManager;
class OnceCallbackTimer;

class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();   // C3: the real member (0x141bd0cc0, the local player)
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();
    static class WorldService* GetInstance();
};
class PCBase   // C3: member view for the former free stand-ins
{
public:
    void AddStateFlags(unsigned int);
    void RemoveStateFlags(unsigned int);
};
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>&, const T&);
class CTaxiManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14085f730(unsigned int);
};
class CInputKeyHandler   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14116d840();
};
void* FUN_14025e7c0();
void FUN_140710590(COutPacket& p);                      // send

// The fly-by request (camera.h; 0x80 bytes).
struct Unk_CameraFlyBy
{
    Unk_CameraFlyBy();                                                  // 0x140947440

    int m_nKind;                                                        // +0x00
    float m_fDuration;                                                  // +0x04
    Unk_CameraSetting m_from;                                           // +0x08
    Unk_CameraSetting m_to;                                             // +0x30
    Unk_CameraSetting m_return;                                         // +0x58
};
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    Unk_CameraFlyBy MakeFlyBy(float fDuration, const Unk_CameraSetting& to);  // 0x140aeffd0 a fly-by from the current view
    int GetModeSetting(struct Unk_CameraSetting&);
    CCameraMode* FUN_140af24f0();
    float FUN_140af0c70();
    float FUN_140af0d30();
public:
    void FUN_140947980(int);   // C3: was free FUN_140947980
public:
    void FUN_140aed580(struct Unk_CameraFlyBy const*, int, float);   // C3: was free FUN_140aed580
public:
    void FUN_140aed750(int, int);   // C3: was free FUN_140aed750
};
float FUN_14029cc60(float f);
float FUN_14029dba0(float f);

// ---- inline COMDATs of this obj ----

// @0x1409f2310
float FUN_1409f2310(float f) { return FUN_14029cc60(f); }
// @0x1409f25a0
float FUN_1409f25a0(float f) { return FUN_14029dba0(f); }
// @0x1409f24a0
Unk_TaxiResTable* FUN_1409f24a0() { return reinterpret_cast<Unk_TaxiResTable*>(TSingleton<CTaxiManager>::s_instance); }
// @0x1409f24b0
Unk_TaxiTimer* FUN_1409f24b0() { return reinterpret_cast<Unk_TaxiTimer*>(TSingleton<OnceCallbackTimer>::s_instance); }
// @0x1409f2430
// The current mode's distance (slot 19; FUN_140b67d10 is the same shape over slot 17).
float FUN_1409f2430(CameraMgr* cam)
{
    if (reinterpret_cast<Unk_CameraManagerData*>(cam)->m_118.get())
        return reinterpret_cast<Unk_CameraManagerData*>(cam)->m_118->vfunc_19();
    return 0.0f;
}

// The camera manager's current-mode pointer (MS2Ptr<CCameraMode> at +0x118): FUN_1409f2430 reads it through these two
// accessors (0x1409f2180 get, 0x1409f21a0 operator->).
template CCameraMode* MS2Ptr<CCameraMode>::get() const;
template CCameraMode* MS2Ptr<CCameraMode>::operator->() const;

typedef TFunctor<void, EmptyParam> Unk_TaxiCallback;

// ---- CAutoFindTaxiStation ----

// @0x1409f11a0
CAutoFindTaxiStation::CAutoFindTaxiStation()
    : m_nActive(0), m_nDone(0), m_nPaused(0), m_nPending(0)
{
}

// @0x1409f1210
CAutoFindTaxiStation::~CAutoFindTaxiStation()
{
}

// @0x1409f1240
void CAutoFindTaxiStation::FUN_1409f1240()
{
    bool bNone = reinterpret_cast<Unk_TaxiInfo*>(WorldService::GetInstance()->FUN_141bd30a0().operator->())->m_nValue == 0;
    if (bNone)
        return;
    Unk_TaxiListPtr list = ((class Unk_TaxiCtx*)WorldService::GetInstance())->FUN_141bd0420(0x85359406);
    if (list == 0)
        return;
    if (list->IsEmpty())
        return;
    if (m_nDone != 0)
        return;
    if (m_nPaused != 0)
    {
        m_nPending = 1;
        return;
    }
    if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3078), DAT_143ab2870) < 0 && Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3098), DAT_143ab2870) < 0)
    {
        m_nActive = 1;
        reinterpret_cast<OnceCallbackTimer*>(FUN_1409f24b0())->Add(1000, Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1450));
        Unk_TaxiPlayer* player = ((Unk_TaxiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (player != 0)
            ((class PCBase*)(class Unk_TaxiPlayer*)(player))->AddStateFlags(0x100);
    }
}

// @0x1409f1450
void CAutoFindTaxiStation::FUN_1409f1450()
{
    if (m_nActive == 0 || m_nDone != 0)
        return;
    {
        // The loop holds each list entry in a smart pointer.
        Unk_TaxiPlayer* player = ((Unk_TaxiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3078), DAT_143ab2870) < 0)
        {
            if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3098), DAT_143ab2870) < 0)
            {
                if (!((class CTaxiManager*)(class Unk_TaxiResTable*)(FUN_1409f24a0()))->FUN_14085f730(DAT_143ab2870))
                {
                    Unk_TaxiListPtr list = ((class Unk_TaxiCtx*)WorldService::GetInstance())->FUN_141bd0420(0x85359406);
                    if (list.get() != 0)
                    {
                        for (POSITION pos = list->GetHeadPosition(); pos != 0; list->GetNext(pos))
                        {
                            efd::SmartPointer<egf::Entity> ent(reinterpret_cast<const efd::SmartPointer<egf::Entity>&>(list->GetAt(pos)));
                            Unk_CameraSetting setting;
                            if (TSingleton<CameraMgr>::GetInstance()->GetModeSetting(*(struct Unk_CameraSetting*)(&setting)) != 0)
                            {
                                Vector3 base;
                                ent->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(base));
                                float fDist = FUN_1409f2430(TSingleton<CameraMgr>::GetInstance());
                                float fYaw = TSingleton<CameraMgr>::GetInstance()->FUN_140af0c70();
                                float fPitch = TSingleton<CameraMgr>::GetInstance()->FUN_140af0d30();
                                float x = fDist * FUN_1409f25a0(fYaw) + base.x;
                                float y = fDist * FUN_1409f2310(fYaw) + base.y;
                                float z = fDist * FUN_1409f2310(fPitch) + base.z;
                                Vector3 delta = setting.m_c.FUN_140965c40(Vector3(x, y, z));
                                setting.m_c = Vector3(x, y, z);
                                float fTime = delta.FUN_140967ac0() * 0.8f;

                                Unk_CameraFlyBy mv = TSingleton<CameraMgr>::GetInstance()->MakeFlyBy(fTime / 1000.0f, setting);
                                mv.m_nKind = 2;
                                TSingleton<CameraMgr>::GetInstance()->FUN_140aed580(&mv, 1, 1.0f);
                                TSingleton<CameraMgr>::GetInstance()->FUN_140aed750(4, 0);
                                reinterpret_cast<OnceCallbackTimer*>(FUN_1409f24b0())->Add((unsigned)fTime,
                                              Unk_TaxiCallback(this, &CAutoFindTaxiStation::SendRequestTaxiMode5));
                                if (player != 0)
                                    ((class PCBase*)(class Unk_TaxiPlayer*)(player))->AddStateFlags(0x100);
                            }
                            else
                            {
                                SendRequestTaxiMode5();
                            }

                        }
                    }
                }
                else if (player != 0)
                    ((class PCBase*)(class Unk_TaxiPlayer*)(player))->RemoveStateFlags(0x100);
            }
            else if (player != 0)
                ((class PCBase*)(class Unk_TaxiPlayer*)(player))->RemoveStateFlags(0x100);
        }
        else if (player != 0)
            ((class PCBase*)(class Unk_TaxiPlayer*)(player))->RemoveStateFlags(0x100);
    }
}

// @0x1409f1890
void CAutoFindTaxiStation::SendRequestTaxiMode5()
{
    if (m_nActive == 0)
        return;
    ((ATL::CAtlArray<unsigned int, ATL::CElementTraits<unsigned int>>*)(void*)(&DAT_143ab3098))->Add(DAT_143ab2870);
    COutPacket packet(static_cast<int>(SendOp::RequestTaxi), 0);
    packet.WriteUInt8(5);
    FUN_140710590(packet);
    int nDelay = 5000;
    reinterpret_cast<OnceCallbackTimer*>(FUN_1409f24b0())->Add(nDelay, Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1a00));
}

// @0x1409f1970
void CAutoFindTaxiStation::FUN_1409f1970()
{
    if (m_nActive != 0 && m_nDone == 0)
        reinterpret_cast<OnceCallbackTimer*>(FUN_1409f24b0())->Add(0x5dc, Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1af0));
}

// @0x1409f1a00
void CAutoFindTaxiStation::FUN_1409f1a00()
{
    if (m_nActive == 0)
        return;
    if (m_nDone != 0)
        return;
    if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3078), DAT_143ab2870) < 0)
    {
        m_nDone = 1;
        TSingleton<CameraMgr>::GetInstance()->FUN_140947980(2);
        FUN_1409f1a70();
    }
}

// @0x1409f1a70
void CAutoFindTaxiStation::FUN_1409f1a70()
{
    if (m_nActive == 0)
        return;
    Unk_TaxiPlayer* player = ((Unk_TaxiPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (player != 0)
        ((class PCBase*)(class Unk_TaxiPlayer*)(player))->RemoveStateFlags(0x100);
    m_nActive = 0;
    m_nDone = 0;
    m_nPaused = 0;
    m_nPending = 0;
}

// @0x1409f1af0
void CAutoFindTaxiStation::FUN_1409f1af0()
{
    Unk_CameraSetting setting;
    if (TSingleton<CameraMgr>::GetInstance()->GetModeSetting(*(struct Unk_CameraSetting*)(&setting)) != 0)
    {
        Vector3 delta = setting.m_c.FUN_140965c40(TSingleton<CameraMgr>::GetInstance()->FUN_140af24f0()->FUN_1409f2540());
        float fLen = delta.FUN_140967ac0() * 0.5f;
        setting.m_c = TSingleton<CameraMgr>::GetInstance()->FUN_140af24f0()->FUN_1409f2540();
        Unk_CameraFlyBy mv = TSingleton<CameraMgr>::GetInstance()->MakeFlyBy(fLen / 1000.0f, setting);
        mv.m_nKind = 2;
        TSingleton<CameraMgr>::GetInstance()->FUN_140aed580(&mv, 1, 1.0f);
        TSingleton<CameraMgr>::GetInstance()->FUN_140aed750(2, 1);
        reinterpret_cast<OnceCallbackTimer*>(FUN_1409f24b0())->Add((unsigned)fLen,
                      Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1a70));
    }
    else
    {
        TSingleton<CameraMgr>::GetInstance()->FUN_140947980(2);
        FUN_1409f1a70();
    }
}

// @0x1409f1cb0
int CAutoFindTaxiStation::FUN_1409f1cb0()
{
    if (m_nDone == 0)
    {
        if (m_nActive != 0)
        {
            if (((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->FUN_14116d840())
            {
                if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3078), DAT_143ab2870) < 0 && Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(DAT_143ab3098), DAT_143ab2870) < 0)
                {
                    if (!((class CTaxiManager*)(class Unk_TaxiResTable*)(FUN_1409f24a0()))->FUN_14085f730(DAT_143ab2870))
                    {
                        ((ATL::CAtlArray<unsigned int, ATL::CElementTraits<unsigned int>>*)(void*)(&DAT_143ab3098))->Add(DAT_143ab2870);
                        COutPacket packet(static_cast<int>(SendOp::RequestTaxi), 0);
                        packet.WriteUInt8(5);
                        FUN_140710590(packet);
                    }
                }
                FUN_1409f1a00();
                return 1;
            }
        }
        else
        {
            if (m_nPending != 0 && m_nPaused == 0)
            {
                FUN_1409f1240();
                m_nPending = 0;
                return 0;
            }
        }
    }
    return 0;
}

// @0x1409f1de0
void CAutoFindTaxiStation::FUN_1409f1de0()
{
    m_nActive = 0;
    m_nDone = 0;
    m_nPaused = 0;
    m_nPending = 0;
}

// @0x1409f1e20
void CAutoFindTaxiStation::FUN_1409f1e20() { m_nPaused = 1; }

// @0x1409f1e40
void CAutoFindTaxiStation::FUN_1409f1e40() { m_nPaused = 0; }
