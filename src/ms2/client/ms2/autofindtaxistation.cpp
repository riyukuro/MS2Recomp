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
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/tfunctor.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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
struct Unk_TaxiHolder;
class Unk_TaxiPlayer;
class Unk_TaxiCtx
{
public:
    Unk_TaxiHolder FUN_141bd30a0();
    void FUN_141bd0420(Unk_TaxiListPtr* out, unsigned hash);
    Unk_TaxiPlayer* FUN_141bd0cc0();
};
struct Unk_TaxiInfo { char m_pad[0xb8]; int m_nValue; };
struct Unk_TaxiHolder
{
    ~Unk_TaxiHolder();                                  // 0x1408850f0
    Unk_TaxiInfo* FUN_140885340();
    void* m_pad[3];
};
class Unk_TaxiResTable;
class Unk_TaxiTimer;
struct Unk_TaxiEnt { void FUN_1409618c0(unsigned hash, Vector3* out); };

struct Unk_TaxiIdArray { int* m_data; unsigned __int64 m_count; unsigned __int64 m_cap; };   // ATL::CAtlArray<int>
extern Unk_TaxiIdArray DAT_143ab3078;
extern Unk_TaxiIdArray DAT_143ab3098;
extern int DAT_143ab2870;                               // taxi station id (resource id)
extern Unk_TaxiResTable* DAT_143ab1f30;
extern Unk_TaxiTimer* DAT_143ab47a0;

Unk_TaxiCtx* FUN_1403ed2d0();
void FUN_14166cce0(Unk_TaxiPlayer* p, int flag);
void FUN_14166cd70(Unk_TaxiPlayer* p, int flag);
int FUN_140408410(Unk_TaxiIdArray* arr, int* id);       // CAtlArray<int>::Find
unsigned __int64 FUN_1401855a0(Unk_TaxiIdArray* arr, int id);   // CAtlArray<int>::Add
bool FUN_14085f730(Unk_TaxiResTable* t, int id);
bool FUN_14116d840(void* p);
void* FUN_14025e7c0();
void FUN_140710590(COutPacket* p);                      // send
void FUN_140ca7230(Unk_TaxiTimer* t, unsigned delayMs, TFunctor<void, EmptyParam> f);

int FUN_140aed440(Unk_CameraManager* cam, Unk_CameraSetting* out);
float FUN_140af0c70(Unk_CameraManager* cam);
float FUN_140af0d30(Unk_CameraManager* cam);
struct Unk_TaxiCamMove { int m_nKind; int m_04; void* m_pad[16]; };
void FUN_140aeffd0(Unk_CameraManager* cam, Unk_TaxiCamMove* out, float t, Unk_CameraSetting* setting);
void FUN_140aed580(Unk_CameraManager* cam, Unk_TaxiCamMove* mv, int n, float fDuration);
void FUN_140aed750(Unk_CameraManager* cam, int a, bool b);
void FUN_140947980(Unk_CameraManager* cam, int n);
float FUN_14029cc60(float f);
float FUN_14029dba0(float f);

// ---- inline COMDATs of this obj ----

// @0x1409f2310
float FUN_1409f2310(float f) { return FUN_14029cc60(f); }
// @0x1409f25a0
float FUN_1409f25a0(float f) { return FUN_14029dba0(f); }
// @0x1409f24a0
Unk_TaxiResTable* FUN_1409f24a0() { return DAT_143ab1f30; }
// @0x1409f24b0
Unk_TaxiTimer* FUN_1409f24b0() { return DAT_143ab47a0; }
// @0x1409f2430
// MS2-FUNCTIONAL: reads the mode distance through the camera manager's declared accessor
float FUN_1409f2430(Unk_CameraManager* cam) { return cam->FUN_140b67d10(); }

// The camera manager's current-mode pointer (MS2Ptr<CCameraMode>, member of Unk_CameraManager, whose layout is not
// declared): FUN_1409f2430 reads it through these two accessors (0x1409f2180 get, 0x1409f21a0 operator->).
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
    bool bNone = FUN_1403ed2d0()->FUN_141bd30a0().FUN_140885340()->m_nValue == 0;
    if (bNone)
        return;
    Unk_TaxiListPtr list;
    FUN_1403ed2d0()->FUN_141bd0420(&list, 0x85359406);
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
    if (FUN_140408410(&DAT_143ab3078, &DAT_143ab2870) < 0 && FUN_140408410(&DAT_143ab3098, &DAT_143ab2870) < 0)
    {
        m_nActive = 1;
        FUN_140ca7230(FUN_1409f24b0(), 1000, Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1450));
        Unk_TaxiPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (player != 0)
            FUN_14166cce0(player, 0x100);
    }
}

// @0x1409f1450
void CAutoFindTaxiStation::FUN_1409f1450()
{
    if (m_nActive == 0 || m_nDone != 0)
        return;
    {
        Unk_TaxiEntRef ent;
        Unk_TaxiPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (FUN_140408410(&DAT_143ab3078, &DAT_143ab2870) < 0)
        {
            if (FUN_140408410(&DAT_143ab3098, &DAT_143ab2870) < 0)
            {
                if (!FUN_14085f730(FUN_1409f24a0(), DAT_143ab2870))
                {
                    Unk_TaxiListPtr list;
    FUN_1403ed2d0()->FUN_141bd0420(&list, 0x85359406);
                    if (list.get() != 0)
                    {
                        for (POSITION pos = list->GetHeadPosition(); pos != 0; list->GetNext(pos))
                        {
                            ent.FUN_1408a7ed0(list->GetAt(pos));
                            Unk_CameraSetting setting;
                            if (FUN_140aed440(Unk_CameraManager::FUN_1409478c0(), &setting) == 0)
                            {
                                SendRequestTaxiMode5();
                            }
                            else
                            {
                                Vector3 base;
                                ent.FUN_1408a9280()->FUN_1409618c0(0xfd95ca52, &base);
                                float fDist = FUN_1409f2430(Unk_CameraManager::FUN_1409478c0());
                                float fYaw = FUN_140af0c70(Unk_CameraManager::FUN_1409478c0());
                                float fPitch = FUN_140af0d30(Unk_CameraManager::FUN_1409478c0());
                                float x = fDist * FUN_1409f25a0(fYaw) + base.x;
                                float y = fDist * FUN_1409f2310(fYaw) + base.y;
                                float z = fDist * FUN_1409f2310(fPitch) + base.z;
                                Vector3 delta = setting.m_c.FUN_140965c40(Vector3(x, y, z));
                                setting.m_c = Vector3(x, y, z);
                                float fLen = delta.FUN_140967ac0();
                                Unk_TaxiCamMove mv;
                                FUN_140aeffd0(Unk_CameraManager::FUN_1409478c0(), &mv, (fLen * 0.8) / 1000.0, &setting);
                                mv.m_nKind = 2;
                                FUN_140aed580(Unk_CameraManager::FUN_1409478c0(), &mv, 1, 1.0f);
                                FUN_140aed750(Unk_CameraManager::FUN_1409478c0(), 4, false);
                                FUN_140ca7230(FUN_1409f24b0(), (unsigned)(long long)(fLen * 0.8),
                                              Unk_TaxiCallback(this, &CAutoFindTaxiStation::SendRequestTaxiMode5));
                                if (player != 0)
                                    FUN_14166cce0(player, 0x100);
                            }
                            ent.FUN_1408a8720();
                        }
                    }
                }
                else if (player != 0)
                    FUN_14166cd70(player, 0x100);
            }
            else if (player != 0)
                FUN_14166cd70(player, 0x100);
        }
        else if (player != 0)
            FUN_14166cd70(player, 0x100);
    }
}

// @0x1409f1890
void CAutoFindTaxiStation::SendRequestTaxiMode5()
{
    if (m_nActive == 0)
        return;
    FUN_1401855a0(&DAT_143ab3098, DAT_143ab2870);
    COutPacket packet(static_cast<int>(SendOp::RequestTaxi), 0);
    packet.WriteUInt8(5);
    FUN_140710590(&packet);
    FUN_140ca7230(FUN_1409f24b0(), 5000, Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1a00));
}

// @0x1409f1970
void CAutoFindTaxiStation::FUN_1409f1970()
{
    if (m_nActive == 0 || m_nDone != 0)
        return;
    FUN_140ca7230(FUN_1409f24b0(), 0x5dc, Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1af0));
}

// @0x1409f1a00
void CAutoFindTaxiStation::FUN_1409f1a00()
{
    if (m_nActive == 0 || m_nDone != 0)
        return;
    if (FUN_140408410(&DAT_143ab3078, &DAT_143ab2870) >= 0)
        return;
    m_nDone = 1;
    FUN_140947980(Unk_CameraManager::FUN_1409478c0(), 2);
    FUN_1409f1a70();
}

// @0x1409f1a70
void CAutoFindTaxiStation::FUN_1409f1a70()
{
    if (m_nActive == 0)
        return;
    Unk_TaxiPlayer* player = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (player != 0)
        FUN_14166cd70(player, 0x100);
    m_nActive = 0;
    m_nDone = 0;
    m_nPaused = 0;
    m_nPending = 0;
}

// @0x1409f1af0
void CAutoFindTaxiStation::FUN_1409f1af0()
{
    Unk_CameraSetting setting;
    if (FUN_140aed440(Unk_CameraManager::FUN_1409478c0(), &setting) == 0)
    {
        FUN_140947980(Unk_CameraManager::FUN_1409478c0(), 2);
        FUN_1409f1a70();
    }
    else
    {
        CCameraMode* pMode = Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0();
        Vector3 delta = setting.m_c.FUN_140965c40(pMode->FUN_1409f2540());
        float fLen = delta.FUN_140967ac0();
        pMode = Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0();
        setting.m_c = pMode->FUN_1409f2540();
        Unk_TaxiCamMove mv;
        FUN_140aeffd0(Unk_CameraManager::FUN_1409478c0(), &mv, (fLen * 0.5) / 1000.0, &setting);
        mv.m_nKind = 2;
        FUN_140aed580(Unk_CameraManager::FUN_1409478c0(), &mv, 1, 1.0f);
        FUN_140aed750(Unk_CameraManager::FUN_1409478c0(), 2, true);
        FUN_140ca7230(FUN_1409f24b0(), (unsigned)(long long)(fLen * 0.5),
                      Unk_TaxiCallback(this, &CAutoFindTaxiStation::FUN_1409f1a70));
    }
}

// @0x1409f1cb0
int CAutoFindTaxiStation::FUN_1409f1cb0()
{
    if (m_nDone == 0)
    {
        if (m_nActive == 0)
        {
            if (m_nPending != 0 && m_nPaused == 0)
            {
                FUN_1409f1240();
                m_nPending = 0;
                return 0;
            }
        }
        else
        {
            if (FUN_14116d840(FUN_14025e7c0()))
            {
                if (FUN_140408410(&DAT_143ab3078, &DAT_143ab2870) < 0 && FUN_140408410(&DAT_143ab3098, &DAT_143ab2870) < 0)
                {
                    if (!FUN_14085f730(FUN_1409f24a0(), DAT_143ab2870))
                    {
                        FUN_1401855a0(&DAT_143ab3098, DAT_143ab2870);
                        COutPacket packet(static_cast<int>(SendOp::RequestTaxi), 0);
                        packet.WriteUInt8(5);
                        FUN_140710590(&packet);
                    }
                }
                FUN_1409f1a00();
                return 1;
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
