// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The fishing manager: the fishing cubes and fishes of the
// current spot (packet 0x73), the cast / bite / catch flow of the local player, auto fishing, the fishing line of the
// guide object (Unk_FishLine, CFishingGuideObject + 0xda8) and the catch statistics of a session.
// MS2-UNIT: ?\fishingmanager.cpp
// MS2-RANGE: 0x140cd7e40-0x140ce27f0 .text$mn
// MS2-RANGE: 0x1400d08a0-0x1400d0b50 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$MS2Ptr@VCFishCube@@@@QEBAPEAVCFishCube@@XZ 0x140cd8c10 ; unique
// MS2-PIN: ??R<lambda_19b5090103c7d1d77b829144b6a9da73>@@QEBAMM@Z 0x140cd8c20 ; unique
// MS2-PIN: ??$Unk_FmGetDialog@VUIFishingBookDialog@@@@YAPEAVUIFishingBookDialog@@W4eUIClassID@@@Z 0x140cdecd0 ; prop
// MS2-PIN: ??$Unk_FmGetDialog@VUIFishingFloatDialog@@@@YAPEAVUIFishingFloatDialog@@W4eUIClassID@@@Z 0x140cded70 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCFishingManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140cdf140 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCFish@@@@QEAA@AEBV0@@Z 0x140cdf210 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCFish@@@@QEAA@PEAVCFish@@@Z 0x140cdf270 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCFish@@@@QEAA@XZ 0x140cdf2a0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCFishCube@@@@QEAA@AEBV0@@Z 0x140cdf2f0 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCFishCube@@@@QEAA@PEAVCFishCube@@@Z 0x140cdf350 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCFishCube@@@@QEAA@XZ 0x140cdf380 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCFishSimulteData@@@@QEAA@PEAVCFishSimulteData@@@Z 0x140cdf3e0 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2Ptr@VCFishCube@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFishCube@@@@@3@@ATL@@IEAA@I@Z 0x140cdf590 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2Ptr@VCFish@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFish@@@@@3@@ATL@@IEAA@I@Z 0x140cdf5d0 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCFishSimulteData@@@@V?$CElementTraits@V?$MS2Ptr@VCFishSimulteData@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCFishSimulteData@@@@_K@Z 0x140cdf960 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCFish@@@@QEBAPEAVCFish@@XZ 0x140cdf9a0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCFishData@@@@QEBAPEAVCFishData@@XZ 0x140cdf9b0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCFishingSpotData@@@@QEBAPEAVCFishingSpotData@@XZ 0x140cdf9c0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCFish@@@@V?$CElementTraits@V?$MS2Ptr@VCFish@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCFish@@@@@Z 0x140cdfbb0 ; prop
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCFishSimulteData@@@@V?$CElementTraits@V?$MS2Ptr@VCFishSimulteData@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCFishSimulteData@@@@@Z 0x140cdfc60 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VCFishCube@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCFishCube@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x140ce0390 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCFish@@@@V?$CElementTraits@V?$MS2Ptr@VCFish@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x140ce0730 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCFishSimulteData@@@@V?$CElementTraits@V?$MS2Ptr@VCFishSimulteData@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x140ce08d0 ; prop
// MS2-PIN: ?FUN_140ce0cb0@CFishingManager@@QEAAHXZ 0x140ce0cb0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCFish@@@@@ATL@@SAXPEAV?$MS2Ptr@VCFish@@@@0_K@Z 0x140ce18a0 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VCFishSimulteData@@@@@ATL@@SAXPEAV?$MS2Ptr@VCFishSimulteData@@@@0_K@Z 0x140ce18e0 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCFishingManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140ce25a0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVCFishingManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140ce2600 ; unique
// MS2-PIN: ??$Call@VCFishingManager@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVCFishingManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVCFishingManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x140ce2630 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCFishingManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140ce2670 ; unique
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders"); their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fishingmanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <efd/IBase.h>
#include <efd/SmartPointer.h>
#include <NiNode.h>
#include <NiTransform.h>

#include "ms2/placeholder/fishingmanager.h"

#include "ms2/client/ms2/cubecraft_1.h"
#include "ms2/client/ms2/cubeguide.h"
#include "ms2/client/ms2/fishcube.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/cube.h"
#include "ms2/client/ms2/uicastingbar.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/commonfiles/fishsimultedata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/client/ms2/statefishingdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern template class MS2Ptr<CItem>;
extern template class MS2Ptr<CItemData>;
extern template class MS2Ptr<UIObject>;

// ---- statics (the .di of this unit constructs them in this order) ----
static CString s_strCursorSound("System_Fishing_Cursor_01");
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uichatballoon_ptr.h"
#include "ms2/placeholder/header_statics_a.h"
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x1400d09f0
static CString s_strFailSound("System_Fishing_Fail");
static CString s_strGreatSuccessSound("System_Fishing_Great_Success");
static CString s_strStartSound("System_Fishing_Start");
static CString s_strSuccessSound("System_Fishing_Success");
static CString s_strThrowSound("System_Fishing_Throw");

// ---- unit-local placeholders ----
using ATL::CAtlArray;

// The global name table (effect / sound file names; FUN_1401d31f0).
struct Unk_FmNames
{
    char m_pad_00[0x3f8];
    CString m_strLineGuide1;                                // +0x3f8 the line guide model (mode 1)
    CString m_strLineGuide0;                                // +0x400 the line guide model (mode 0)
    CString m_strSplashEffect;                              // +0x408
    char m_pad_410[0x10];
    CString m_strCubeMarkEffect;                            // +0x420
    char m_pad_428[0x20];
    CString m_aStrSizeEffect[4];                            // +0x448 the effect of a caught size class
};
Unk_FmNames* FUN_1401d31f0();

// The cube map service (efd class id 0x06100017).
struct Unk_FmInt3
{
    Unk_FmInt3();                                           // 0x1408850a0
    int x, y, z;
};
class Cube;
class Unk_FmCubeMap : public efd::ISystemService
{
public:
    efd::Point3 FUN_1410b7ba0(efd::Point3 kFrom, efd::Point3 kTo, float fStep, efd::Point3* pOut, int bSnap);
    efd::Point3 FUN_1410b7a20(efd::Point3 kPos, efd::Point3* pOut);   // the cell position of a point
    Cube* FUN_1410b8a60(Unk_FmInt3 kCell);                  // the cube at a cell
};
struct Unk_FmFramework;
extern Unk_FmFramework DAT_143b059e8;
Unk_FmCubeMap* FUN_1401cd040(Unk_FmFramework* pFramework);
template <> MS2Ptr<Cube>::MS2Ptr(Cube* p);                  // 0x140884fb0
extern template class MS2Ptr<Cube>;

// Grid helpers.
int FUN_1408a13d0(efd::Point3 kPos);                        // the grid cell key of a point
Unk_FmInt3 FUN_1408a1430(efd::Point3 kPos);                 // the grid cell of a point
Unk_FmInt3 FUN_1408a0400(int nKey);                         // the grid cell of a key
efd::Point3 FUN_1408a15b0(Unk_FmInt3 kCell, const efd::Point3& kOffset);   // the cell centre
float FUN_14096b1c0(float f);                               // sqrt
extern efd::Point3 DAT_143b01a60;                           // the zero point
void FUN_1420849a0(NiMatrix3* pRot);                        // identity

// The local player with the members this unit calls.
class Unk_FmPC : public MyPC
{
public:
    PCBase* FUN_141662440(int nType);                       // the guide object of a kind (1 = fishing)
    unsigned FUN_141662750(int nType);                      // the fishing mastery
    int FUN_141658f30();                                    // the player may use a premium rod
    int FUN_141662de0();
    int FUN_141654700();                                    // the job code
};
class Unk_FmWorld
{
public:
    Unk_FmPC* FUN_141bd0cc0();                              // the local player
    int FUN_141bd3060();                                    // the current map
    int FUN_141bcafa0(egf::Entity* pEntity);                // the entity blocks the way
};
Unk_FmWorld* FUN_1403ed2d0();
bool FUN_140374410(int nMapId);                             // fishing is forbidden on the map

// The player's buffs.
class Unk_FmBuffs { public: int FUN_1409701d0(int nKind); int FUN_140970020(int nId, int a, int b, int c); };

// The effect manager.
class Unk_FmEffects
{
public:
    unsigned FUN_1411a49c0(Unk_EffectTarget& kTarget);     // spawn
    unsigned FUN_1411a4a00(Unk_EffectTarget& kTarget);     // play once
    NiNode* FUN_1411a6b10();                                // the effect root
};
Unk_FmEffects* FUN_1403ed280();
void FUN_1411a6060(Unk_FmEffects* pMgr, unsigned nId);     // stop an effect
void FUN_140a332d0(NiTransform* pXform);                    // NiTransform()
void FUN_140a53190(Unk_EffectTarget* pTarget, int nObjectId);

// Sounds.
int FUN_141276180(const CString& strSound, CString strArg);

// UI.
class Unk_FmCastingBar : public UICastingBar
{
public:
    void FUN_1418e12f0(ICastingEventListener* pListener, const CStringW& strText, int nDuration, bool bShowTime,
        bool bActive, const CStringW& strEnd);
    void FUN_1418e13c0(ICastingEventListener* pListener, const Unk_CastingParam* pParam);
};
Unk_FmCastingBar* FUN_140ac2270(int nId);
class UIFishingBookDialog : public UIDialog { public: void FUN_140f419e0(); };
class UIFishingFloatDialog : public UIDialog { public: void FUN_140f443d0(MS2Ptr<CFishCube> cube); unsigned char FUN_140f44490(); };
class UIAutoFishingDialog : public UIDialog { public: void FUN_140fa5ba0(int nMode); void FUN_140fa5bc0(); };
class Unk_FmFishGuide;
Unk_FmFishGuide* FUN_140938cd0(int nId);
void FUN_141abf6e0(Unk_FmFishGuide* p, int nFishId, unsigned nCount);
void FUN_141ac11b0(Unk_FmFishGuide* p, unsigned nFishId, unsigned nSize);
void FUN_141ac0e50(Unk_FmFishGuide* p, unsigned nFishId, unsigned nSize);
class Unk_FmQuest { public: void FUN_14138bf00(int nType, unsigned nId, int n); };
Unk_FmQuest* FUN_1409331e0();
class Unk_FmGameMode { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7(int nMode, int n); };
Unk_FmGameMode* FUN_140a94350();

// Notices.
void FUN_141275260(int nMsgId, int a, int b);
void FUN_1412751f0(const CStringW& strText, int a, int b);
void FUN_1412751b0(const CStringW& strText, int nType);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_14062b4f0(CStringW strKey, const int* pn);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_1409e97f0(int nId, const unsigned* pn);
CStringW FUN_140632a60(int nId, const CStringW& a, const CStringW& b);
class Unk_FmStringTable { public: CStringW FUN_141811980(int nKind, int nId); };
Unk_FmStringTable* FUN_1401a9d70();
class Unk_FmMasteryTable { public: unsigned FUN_14066b050(int nKind); int FUN_14066af60(int nKind, unsigned nMastery); };
Unk_FmMasteryTable* FUN_1409670c0();
CStringW FUN_14016a730(const char* sz, int nCodePage);      // CString -> CStringW
CString FUN_140390ea0(const wchar_t* sz, int nCodePage);    // CStringW -> CString
unsigned FUN_140768010(unsigned nRange, int n);             // random
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
unsigned FUN_141472bc0();                                   // the server time

// The item helpers.
bool FUN_14053f8c0(int nItemId);
bool FUN_14053f900(int nItemId);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
struct Unk_FmAdditional;
class Unk_FmAdditionalPtr { public: ~Unk_FmAdditionalPtr(); bool FUN_1409c4ad0() const; Unk_FmAdditional* FUN_1407ebbf0();
    void* m_p0; void* m_p8; };
class Unk_FmAdditionalLevels { public: size_t FUN_1407e59e0(); void* FUN_1407e46a0(size_t n); };
struct Unk_FmAdditional { char m_pad_00[0x98]; Unk_FmAdditionalLevels m_levels; };
struct Unk_FmAdditionalLevel { char m_pad_00[0x18]; int m_nBuffId; };
Unk_FmAdditionalLevel* FUN_1407e4770(void* p);
struct Unk_FmAdditionalRow;
class Unk_FmAdditionalRowPtr { public: ~Unk_FmAdditionalRowPtr(); bool FUN_14096e7e0(int n) const;
    Unk_FmAdditionalRow* FUN_140184880(); void* m_p0; void* m_p8; };
struct Unk_FmAdditionalRow { char m_pad_00[0x30]; int m_nType; };
class Unk_FmAdditionalData { public: Unk_FmAdditionalRowPtr FUN_140aafef0(int nId, unsigned short nLevel);
    Unk_FmAdditionalPtr FUN_1407ee2f0(int nId, short nLevel); };
Unk_FmAdditionalData* FUN_1401958b0();                      // the additional effect table

class Unk_FmPhysX { public: int FUN_14168a310(const efd::Point3& kFrom, const efd::Point3& kTo, void* pHit, int a, __int64 b, int c); };
Unk_FmPhysX* FUN_1409f7ca0();
void FUN_140ad4440(void* pHit);

void FUN_140710590(COutPacket& pkt);
CUIService* FUN_1403ed2b0();                               // TSingleton<CUIService>::GetInstance
CFeatureManager* FUN_140166410();                           // TSingleton<CFeatureManager>::GetInstance
NotifySystem* FUN_140939a10();
extern Unk_Inventory DAT_143ab2a90;
extern int DAT_143ab2914;                                   // the account's GM level

// The fishing line (Unk_FishLine of cubecraft_1.h, CFishingGuideObject + 0xda8) with its members.
class Unk_FishLineBody
{
public:
    Unk_FishLineBody();
    ~Unk_FishLineBody();                                    // 0x140cd7e40
    void FUN_140cd7eb0(int nKind, const efd::Point3& kPos); // start
    void FUN_140cd8080();                                   // stop
    void FUN_140cd80d0();                                   // update
    int FUN_140cd85b0();                                    // the line is out
    int FUN_140cd85e0();                                    // the grid cell under the float
    efd::Point3 FUN_140cd8630();                            // the float position
    void FUN_140cd8740(efd::Point3 kPos);                   // the float landed
    void FUN_140cd89c0(efd::Point3 kPos);                   // retarget the line
    void FUN_140cd8a90();                                   // drop the guide model
    static void FUN_140cd8b20(efd::Point3 kPos);            // snap to the grid (the exe passes a copy: no effect)

    CFishingGuideObject* m_pOwner;                          // +0x00
    CCubeGuideWrapper* m_pGuide;                            // +0x08 the line model
    int m_nKind;                                            // +0x10 0 = water, 1 = spot
    Timer m_flyTimer;                                       // +0x18 the throw flight
    efd::Point3 m_kTarget;                                  // +0x50
    efd::Point3 m_kLanding;                                 // +0x5c
    unsigned m_nEffect;                                     // +0x68 the splash effect
    Timer m_waitTimer;                                      // +0x70
};
MS2_CHECK_SIZE(Unk_FishLineBody, 0xa8);

// @0x140ce02b0
static Unk_FishLineBody* FUN_140ce02b0(CFishingGuideObject* pGuide)
{
    return reinterpret_cast<Unk_FishLineBody*>(&pGuide->m_fishLine);   // the same 0xa8 bytes, typed
}

// ---- template glue first emitted here ----

// MS2-PIN: ??_7CFishingManager@@6B?$TSingleton@VCFishingManager@@@@@ 0x142e1eb28

template <class T> T* Unk_FmGetDialog(eUIClassID nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> obj = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (obj.get())
            return dynamic_cast<T*>(obj.operator->());
    }
    return 0;
}

// ---- Unk_FishLineBody ----

// @0x140cd7e40
Unk_FishLineBody::~Unk_FishLineBody()
{
    FUN_140cd8080();
    m_pOwner = 0;
    m_pGuide = 0;
}

// @0x140cd7eb0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void Unk_FishLineBody::FUN_140cd7eb0(int nKind, const efd::Point3& kPos)
{
    CString strModel = (nKind == 0) ? FUN_1401d31f0()->m_strLineGuide0 : FUN_1401d31f0()->m_strLineGuide1;
    CNifCubeGuide* pGuide = new CNifCubeGuide();
    if (pGuide->FUN_1410afc10(CString(strModel)) == 0)
        return;
    NiNode* pRoot = FUN_1403ed280()->FUN_1411a6b10();
    if (pRoot == 0)
        return;
    FUN_140cd8a90();
    pGuide->vfunc_10(pRoot, 0);
    NiPoint3 kAt(kPos.x, kPos.y, kPos.z);
    pGuide->vfunc_2(kAt);
    m_pGuide = pGuide;
    m_nKind = nKind;
    m_waitTimer.FUN_140868750(1000);
}

// @0x140cd8080
void Unk_FishLineBody::FUN_140cd8080()
{
    FUN_140cd8a90();
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
}
MS2_REPLACE_METHOD(0x140CD8080, Unk_FishLineBody, FUN_140cd8080, 68, 0x785D1C07);

// @0x140cd80d0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void Unk_FishLineBody::FUN_140cd80d0()
{
    if (m_pGuide == 0 || m_pOwner == 0)
        return;
    if (m_flyTimer.FUN_140868ba0() == 0 && m_flyTimer.FUN_140868c00() == 0)
    {
        efd::SmartPointer<Unk_FmCubeMap> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
        efd::Point3 kHit;
        efd::Point3 kCell;
        NiPoint3 kDir = m_pOwner->vfunc_20();
        NiPoint3 kPos = m_pOwner->vfunc_18();
        spCubeMap->FUN_1410b7ba0(efd::Point3(kPos.x, kPos.y, kPos.z), efd::Point3(kDir.x, kDir.y, kDir.z), 10.0f,
            &kHit, 0);
        spCubeMap->FUN_1410b7a20(kHit, &kCell);
        NiPoint3 kGuide = m_pGuide->vfunc_3();
        if (kCell != efd::Point3(kGuide.x, kGuide.y, kGuide.z))
        {
            m_flyTimer.FUN_140868750(200);
            NiPoint3 kFrom = m_pGuide->vfunc_3();
            m_kTarget = efd::Point3(kFrom.x, kFrom.y, kFrom.z);
            m_kLanding = kCell;
            FUN_141276180(s_strCursorSound, CString(""));
            m_waitTimer.FUN_140868750(1000);
        }
    }
    else
    {
        auto ease = [](float t) -> float {
            if (t < 0.0f)
                return 0.0f;
            if (1.0f < t)
                return 1.0f;
            return FUN_14096b1c0(1.0f - (t - 1.0f) * (t - 1.0f));
        };
        float fEase = ease(m_flyTimer.FUN_140868940());
        efd::Point3 kDelta = m_kLanding - m_kTarget;
        float fLength = kDelta.Length();
        kDelta.Unitize();
        efd::Point3 kNow = m_kTarget + kDelta * fEase * fLength;
        NiPoint3 kAt(kNow.x, kNow.y, kNow.z);
        m_pGuide->vfunc_2(kAt);
        if (m_flyTimer.FUN_140868c00() != 0)
        {
            m_flyTimer.FUN_1408687f0();
            FUN_140cd8740(kNow);
            FUN_140cd89c0(kNow);
            int nCell = FUN_140cd85e0();
            MS2Ptr<CFishCube> cube = TSingleton<CFishingManager>::GetInstance()->FUN_140cdbb10(nCell);
            if (cube.get() != 0 && m_pOwner != 0)
                m_pOwner->FUN_1410a4d30(cube.get());
        }
    }
}

// @0x140cd85b0
int Unk_FishLineBody::FUN_140cd85b0()
{
    return m_waitTimer.FUN_140868c00();
}
MS2_REPLACE_METHOD(0x140CD85B0, Unk_FishLineBody, FUN_140cd85b0, 31, 0x3385E2D8);

// @0x140cd85e0
int Unk_FishLineBody::FUN_140cd85e0()
{
    return FUN_1408a13d0(FUN_140cd8630());
}
MS2_REPLACE_METHOD(0x140CD85E0, Unk_FishLineBody, FUN_140cd85e0, 61, 0xB115E804);

// @0x140cd8630
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
efd::Point3 Unk_FishLineBody::FUN_140cd8630()
{
    if (m_pGuide == 0)
        return DAT_143b01a60;
    NiPoint3 kGuide = m_pGuide->vfunc_3();
    efd::Point3 kPos = efd::Point3(kGuide.x, kGuide.y, kGuide.z) - efd::Point3(0.0f, 0.0f, 75.0f);
    FUN_140cd8b20(efd::Point3(kPos));
    return kPos;
}

// @0x140cd8740
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void Unk_FishLineBody::FUN_140cd8740(efd::Point3 kPos)
{
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
    efd::Point3 kBelow = kPos - efd::Point3(0.0f, 0.0f, 75.0f);
    NiTransform kXform;
    FUN_1420849a0(&kXform.m_Rotate);
    kXform.m_fScale = 1.0f;
    kXform.m_Translate = NiPoint3(kBelow.x, kBelow.y, kBelow.z);
    int nCell = FUN_1408a13d0(kBelow);
    MS2Ptr<CFishCube> cube = TSingleton<CFishingManager>::GetInstance()->FUN_140cdbb10(nCell);
    if (cube.get() == 0)
        return;
    CFishCube* pCube = cube.operator->();
    CFishDataPtr fish = TSingleton<CFishingTable>::GetInstance()->GetFish(pCube->m_a);
    if (!fish.IsNull())
    {
        CFishCube* pCube2 = cube.operator->();
        int nClass = (int)fish->FUN_1403b1520(pCube2->m_b);
        if (nClass != 4)
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = FUN_1401d31f0()->m_aStrSizeEffect[nClass];
            kTarget.m_nKind = 0;
            kTarget.m_unk_20 = &kXform;
            m_nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
        }
    }
}

// @0x140cd89c0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void Unk_FishLineBody::FUN_140cd89c0(efd::Point3 kPos)
{
    efd::Point3 kBelow = kPos - efd::Point3(0.0f, 0.0f, 75.0f);
    int nKind = TSingleton<CFishingManager>::GetInstance()->FUN_140cdb110(kBelow);
    if (nKind != m_nKind)
    {
        FUN_140cd7eb0(nKind, kPos);
        m_nKind = nKind;
    }
}

// @0x140cd8a90
void Unk_FishLineBody::FUN_140cd8a90()
{
    if (m_pGuide != 0)
    {
        m_pGuide->vfunc_11();
        delete m_pGuide;
        m_pGuide = 0;
    }
}
MS2_REPLACE_METHOD(0x140CD8A90, Unk_FishLineBody, FUN_140cd8a90, 131, 0xE3D986D7);

// @0x140cd8b20
void Unk_FishLineBody::FUN_140cd8b20(efd::Point3 kPos)
{
    Unk_FmInt3 kCell = FUN_1408a1430(kPos);
    kPos.x = (float)kCell.x * 150.0f;
    kPos.y = (float)kCell.y * 150.0f;
    kPos.z = (float)kCell.z * 150.0f;
}
MS2_REPLACE(0x140CD8B20, Unk_FishLineBody::FUN_140cd8b20, 124, 0x5088FE3E);

// @0x140cd8d50
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- Unk_FishRecord ----

// @0x140cd8e70
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void Unk_FishRecord::FUN_140cd8e70(unsigned nFishId, int bSuccess)
{
    if (m_bOff == 0)
    {
        m_nTry++;
        if (bSuccess != 0)
        {
            m_nSuccess++;
            int nCount = 0;
            m_counts.Lookup(nFishId, nCount);
            nCount++;
            m_counts.SetAt(nFishId, nCount);
        }
    }
}

// @0x140cd8f10
void Unk_FishRecord::FUN_140cd8f10()
{
    m_bOff = 0;
    m_nTry = 0;
    m_nSuccess = 0;
    m_counts.RemoveAll();
}
MS2_REPLACE_METHOD(0x140CD8F10, Unk_FishRecord, FUN_140cd8f10, 66, 0xBD312399);

// The log file writer.
class Unk_FmFile
{
public:
    Unk_FmFile();                                           // 0x1402970b0
    ~Unk_FmFile();                                          // 0x1402978f0
    int FUN_1402989b0(const char* szName, unsigned nAccess, unsigned nShare, unsigned nCreate, unsigned nAttr,
        int a, int b);
    int FUN_140299dc0(const char* pData, int nLength, int a);
    void FUN_1402988c0();
    void* m_p0;
    void* m_p8;
};
CStringW FUN_1401ceea0(const wchar_t* format, const fmt::ArgList& args);   // wide StringFormat
FMT_VARIADIC_W(CStringW, FUN_1401ceea0, const wchar_t*)
__int64 FUN_140869440();                                    // now

// @0x140cd8f60
// MS2-FUNCTIONAL: formatter argument temporaries
CString Unk_FishRecord::FUN_140cd8f60()
{
    CMsTime kNow(FUN_140869440());
    int nMinute = kNow.GetMinute();
    int nHour = kNow.GetHour();
    CString strFile = StringFormat(".\\log\\client\\fishRecord_{0:02d}{1:02d}.txt", nHour, nMinute);
    Unk_FmFile file;
    file.FUN_1402989b0(strFile, 0x40000000, 3, 2, 0x80, 0, 0);
    CString strText;
    strText += FUN_140390ea0(FUN_1401ceea0(L"TryCount : {0}\r\n", m_nTry), 0);
    strText += FUN_140390ea0(FUN_1401ceea0(L"SuccessCount : {0}\r\n", m_nSuccess), 0);
    strText += FUN_140390ea0(L"\r\nidCount\r\n", 0);
    POSITION pos = m_counts.GetStartPosition();
    while (pos != 0)
    {
        const unsigned& nId = m_counts.GetKeyAt(pos);
        CStringW strName = FUN_1401a9d70()->FUN_141811980(0x1d, nId);
        const int& nCount = m_counts.GetValueAt(pos);
        strText += FUN_140390ea0(StringFormat(L"{0} {1}[{2}]\r\n", m_counts.GetKeyAt(pos), nCount, strName), 0);
        m_counts.GetNext(pos);
    }
    int nLength = strText.GetLength();
    file.FUN_140299dc0(strText, nLength, 0);
    file.FUN_1402988c0();
    return strFile;
}

// ---- CFishingManager ----

// @0x140cd9400
CFishingManager::CFishingManager()
{
    m_bFishing = 0;
    m_nBiteEnd = 0;
    m_bGreat = 0;
    m_nReelSound = 0;
    m_uidRod = 0;
    m_bAutoFishing = 0;
    m_nAutoCount = 0;
    m_nBaitId = 0;
    m_bCountdown = 0;
    FUN_140939a10()->RegisterNotify(CStringW(L"NotifyChangeBuff"),
        Delegate<void(NotifyObject*)>(this, &CFishingManager::FUN_140cdacb0));
}

// @0x140cd96c0
CFishingManager::~CFishingManager()
{
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyChangeBuff"),
        Delegate<void(NotifyObject*)>(this, &CFishingManager::FUN_140cdacb0));
}

// The packet readers of the fishing records (?\fishcube.cpp / ?\fishsimultedata.cpp).
class Unk_FmFishCube : public CFishCube { public: void FUN_1403b0a40(CInPacket* pPacket); };
class Unk_FmSimulate : public CFishSimulteData { public: void FUN_1403b0f50(CInPacket* pPacket); };

// @0x140cd9840
// MS2-FUNCTIONAL: switch on the packet mode, temporaries
void CFishingManager::FUN_140cd9840(CInPacket* pPacket)
{
    if (!FUN_140166410()->FUN_14036d570(0xb))
        return;
    unsigned char nMode = pPacket->vfunc_o8_1();
    if (nMode == 0)
    {
        MS2Ptr<CItem> rod = DAT_143ab2a90.FUN_140a5d680(pPacket->vfunc_o8_4());
        FUN_140cdce70(rod);
    }
    else if (nMode == 1)
    {
        FUN_140cdd030();
    }
    else if (nMode == 7)
    {
        m_bFishing = 0;
        m_fishes.RemoveAll();
        int nCount = pPacket->vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<CFish> fish(new CFish());
            fish->FUN_1403b0bf0(pPacket);
            m_fishes.SetAt(fish->m_nId, fish);
        }
    }
    else if (nMode == 4)
    {
        unsigned bAppend = pPacket->vfunc_o8_1();
        if (bAppend == 0)
        {
            m_cubes.RemoveAll();
            FUN_140cdcde0();
        }
        int nCount = pPacket->vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<CFishCube> cube(new CFishCube());
            static_cast<Unk_FmFishCube*>(cube.operator->())->FUN_1403b0a40(pPacket);
            m_cubes.SetAt(cube->m_id, cube);
            if (bAppend == 0)
                FUN_140cdcaa0(MS2Ptr<CFishCube>(cube));
        }
    }
    else if (nMode == 9)
    {
        m_bGreat = pPacket->vfunc_o8_1();
        m_nBiteEnd = pPacket->vfunc_o8_3();
        FUN_140cdd1f0();
    }
    else if (nMode == 8)
    {
        unsigned nFishId = pPacket->vfunc_o8_3();
        unsigned nSize = pPacket->vfunc_o8_3();
        unsigned bSuccess = pPacket->vfunc_o8_1();
        m_bAutoFishing = pPacket->vfunc_o8_1();
        if (bSuccess != 0)
        {
            MS2Ptr<CFish> fish = FUN_140cdba00(nFishId);
            if (fish == 0)
            {
                fish.AssignRaw(new CFish());
                fish->m_bNew = 1;
                m_fishes.SetAt(nFishId, fish);
            }
            fish->FUN_1403b0bf0(pPacket);
        }
        FUN_140cdd540(nFishId, nSize, bSuccess);
    }
    else if (nMode == 5)
    {
        int nCount = pPacket->vfunc_o8_3();
        for (int i = 0; i < nCount; i++)
        {
            int nItemId = pPacket->vfunc_o8_3();
            unsigned nItemCount = (unsigned short)pPacket->vfunc_o8_2();
            if (!FUN_14053f8c0(nItemId) && !FUN_14053f900(nItemId))
            {
                Unk_FmFishGuide* pGuide = FUN_140938cd0(0x4e5d);
                if (pGuide != 0)
                    FUN_141abf6e0(pGuide, nItemId, nItemCount);
            }
        }
    }
    else if (nMode == 6)
    {
        CStringW strName = pPacket->vfunc_o8_8();
        int nFishId = pPacket->vfunc_o8_3();
        int nCount = pPacket->vfunc_o8_3();
        CStringW strFish = FUN_1401a9d70()->FUN_141811980(0x1d, nFishId);
        CStringW strNotice = FUN_1408f71a0(CStringW(L"s_fishing_notice_bigfish"), strName, strFish);
        if (nCount != 0 && 0x31 < DAT_143ab2914)
            strNotice += FUN_14062b4f0(CStringW(L"s_fishing_notice_bigfish_count"), &nCount);
        FUN_1412751b0(strNotice, 0x14);
    }
    else if (nMode == 2)
    {
        unsigned nError = (unsigned short)pPacket->vfunc_o8_2();
        switch (nError)
        {
        case 1: FUN_141275260(0xbde, 1, 1); break;
        case 2: FUN_141275260(0xbdf, 1, 1); break;
        case 3: FUN_141275260(0xbe0, 1, 1); break;
        case 4: FUN_141275260(0xbe1, 1, 1); break;
        case 5: FUN_141275260(0xbdd, 1, 1); break;
        case 6: FUN_141275260(0xbe3, 1, 1); break;
        case 7: FUN_141275260(0xbe5, 1, 1); break;
        case 8: FUN_141275260(0xbe6, 1, 1); break;
        case 9: FUN_141275260(0xbe2, 1, 1); break;
        }
    }
    else if (nMode == 0xb)
    {
        int nCount = pPacket->vfunc_o8_3();
        CAtlArray<MS2Ptr<CFishSimulteData> > results;
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<CFishSimulteData> result(new CFishSimulteData());
            static_cast<Unk_FmSimulate*>(result.operator->())->FUN_1403b0f50(pPacket);
            results.Add(result);
        }
        FUN_1412751b0(CStringW(L"----------------------------------------------------"), 0x14);
        for (size_t i = 0; i < results.GetCount(); i++)
        {
            MS2Ptr<CFishSimulteData> result = results[i];
            CStringW strFish = FUN_1401a9d70()->FUN_141811980(0x1d, result->m_n18);
            FUN_1412751b0(FUN_14028dfa0(CStringW(L"s_fishing_simulate"), strFish, result->m_n1c, result->m_n20,
                result->m_aN24[3]), 0x14);
        }
    }
    else if (nMode == 3)
    {
        Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            unsigned nMastery = pPC->FUN_141662750(1);
            int nFishId = pPacket->vfunc_o8_3();
            unsigned nExp = pPacket->vfunc_o8_3();
            short nKind = pPacket->vfunc_o8_2();
            unsigned nLevel = (unsigned short)pPacket->vfunc_o8_2();
            CStringW strNotice;
            if (nLevel != FUN_1409670c0()->FUN_14066b050(1))
            {
                if (nKind == 1)
                {
                    strNotice = FUN_1409e97f0(0xbe7, &nExp);
                }
                else if (nKind == 2)
                {
                    CStringW strFish = FUN_1401a9d70()->FUN_141811980(0x1d, nFishId);
                    strNotice = FUN_14028dee0(0xbe8, strFish, nExp, nMastery);
                }
                else if (nKind == 3)
                {
                    CStringW strFish = FUN_1401a9d70()->FUN_141811980(0x1d, nFishId);
                    strNotice = FUN_14028dee0(0xbe9, strFish, nExp, nMastery);
                }
                FUN_1412751b0(strNotice, 0x14);
            }
        }
    }
    else if (nMode == 10)
    {
        m_bAutoFishing = pPacket->vfunc_o8_1();
        if (m_bAutoFishing != 0)
            SendFishingMode9();
    }
}

// @0x140cdaaa0
void CFishingManager::SendFishingMode10()
{
    COutPacket pkt(0x73, 0);
    pkt.Encode1(10);
    FUN_140710590(pkt);
    FUN_140cdc9d0(0x76, 0x7a);
    Unk_FmCastingBar* pBar = FUN_140ac2270(0x4e72);
    if (pBar != 0)
        pBar->FUN_1418e1390();
    if (m_nReelSound != 0)
        FUN_1411a6060(FUN_1403ed280(), m_nReelSound);
}
MS2_REPLACE_METHOD(0x140CDAAA0, CFishingManager, SendFishingMode10, 176, 0x1AA5308B);

// @0x140cdab60
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void CFishingManager::OnCastingFinished()
{
    UIFishingFloatDialog* pFloat = Unk_FmGetDialog<UIFishingFloatDialog>((eUIClassID)0x4ee7);
    if (pFloat != 0)
    {
        unsigned char nResult = pFloat->FUN_140f44490();
        COutPacket pkt(0x73, 0);
        pkt.Encode1(8);
        pkt.Encode1(nResult);
        FUN_140710590(pkt);
    }
    if (m_bGreat != 0)
        FUN_1411a6060(FUN_1403ed280(), m_bGreat);
}

// @0x140cdac20
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void CFishingManager::FUN_140cdac20()
{
    if (FUN_140954150() != 0)
        FUN_140cdd030();
}

// @0x140cdac50
void CFishingManager::FUN_140cdac50()
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (reinterpret_cast<Unk_FmBuffs*>(pPC->FUN_1416749a0())->FUN_1409701d0(1) != 0)
        SendFishingMode9();
}

// @0x140cdacb0
void CFishingManager::FUN_140cdacb0(NotifyObject* pNotify)
{
    NotifyChangeBuff* pBuff = dynamic_cast<NotifyChangeBuff*>(pNotify);
    if (pBuff == 0)
        return;
    if (pBuff->m_bAdded == 0)
        return;
    Unk_FmAdditionalRowPtr row = FUN_1401958b0()->FUN_140aafef0(pBuff->m_nId, 1);
    if (row.FUN_14096e7e0(0))
        return;
    if (!(row.FUN_140184880()->m_nType == 1))
        return;
    if (FUN_140954150() != 0 && FUN_140cdbb90() != 0)
        SendFishingMode9();
}

// @0x140cdadb0
void CFishingManager::FUN_140cdadb0(MS2Ptr<CItem> rod)
{
    if (m_bFishing == 0)
        FUN_140cdae30(MS2Ptr<CItem>(rod));
    else
        SendFishingMode1();
}
MS2_REPLACE_METHOD(0x140CDADB0, CFishingManager, FUN_140cdadb0, 107, 0x5D2F9C3D);

// @0x140cdae30
void CFishingManager::FUN_140cdae30(MS2Ptr<CItem> rod)
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (FUN_140954150() != 0)
        return;
    if (m_startTimer.FUN_140868ba0() != 0)
        return;
    if (FUN_140374410(FUN_1403ed2d0()->FUN_141bd3060()))
    {
        FUN_141275260(0xbe6, 1, 1);
        return;
    }
    if (rod.IsNull())
    {
        FUN_141275260(0xbdf, 1, 1);
        return;
    }
    if (FUN_140cdc810() == 0 || FUN_140cdc520() == 0)
    {
        FUN_141275260(0xbdd, 1, 1);
        return;
    }
    if (FUN_140cdd7b0() == 0)
    {
        FUN_141275260(0xbde, 1, 1);
        return;
    }
    if (pPC->FUN_1416764a0() != 0 && pPC->SendRequestRideMode1(0) == 0)
    {
        FUN_141275260(0xbe4, 1, 1);
        return;
    }
    COutPacket pkt(0x73, 0);
    pkt.Encode1(0);
    pkt.Encode8(rod->FUN_140526a50());
    FUN_140710590(pkt);
    m_startTimer.FUN_140868750(1000);
}
MS2_REPLACE_METHOD(0x140CDAE30, CFishingManager, FUN_140cdae30, 604, 0x17346286);

// @0x140cdb0a0
void CFishingManager::SendFishingMode1()
{
    if (FUN_140954150() == 0)
        return;
    COutPacket pkt(0x73, 0);
    pkt.Encode1(1);
    FUN_140710590(pkt);
}

// @0x140cdb110
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
int CFishingManager::FUN_140cdb110(const efd::Point3& kPos)
{
    MS2Ptr<CFishCube> cube = FUN_140cdbb10(FUN_1408a13d0(kPos));
    if (cube == 0)
        return 0;
    if (cube->m_a == 0)
        return 0;
    return 1;
}

// @0x140cdb1e0
void CFishingManager::SendFishingMode9()
{
    COutPacket pkt(0x73, 0);
    pkt.Encode1(9);
    pkt.Encode4(FUN_140cdc950());
    FUN_140710590(pkt);
}
MS2_REPLACE_METHOD(0x140CDB1E0, CFishingManager, SendFishingMode9, 97, 0x3BC9DD37);

// @0x140cdb250
// MS2-FUNCTIONAL: return value temporaries
int CFishingManager::FUN_140cdb250()
{
    MS2Ptr<CFishCube> cube = FUN_140cdbb10(FUN_140cdc950());
    if (cube.IsNull())
        return 0;
    if (cube->m_a == 0)
        return 0;
    if (m_resultTimer.FUN_140868ba0() != 0)
        return 0;
    if (m_nBiteEnd != 0)
        return 0;
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (pPC->FUN_14166cc80() != 0x76 && pPC->FUN_14166cc80() != 0x77)
        return 0;
    CFishingGuideObject* pGuide = efd::DynamicCast<CFishingGuideObject>(pPC->FUN_141662440(1));
    if (pGuide == 0)
        return 0;
    if (pGuide->FUN_14166cc80() != 0x7a)
        return 0;
    return FUN_140ce02b0(pGuide)->FUN_140cd85b0();
}

// ---- more unit-local placeholders (the per-frame / spot code) ----
void FUN_14092f4e0(int nItemId);                            // use the bait item
struct Unk_PCBaseRayHit                                      // the ray hit of pcbase.cpp
{
    Unk_PCBaseRayHit();                                     // 0x140ad4440
    efd::Point3 m_origin;                                   // +0x00
    efd::Point3 m_dir;                                      // +0x0c
    float m_maxDist;                                        // +0x18
    int m_groups;                                           // +0x1c
    void* m_20;
    void* m_28;
    egf::Entity* m_hitEntity;                               // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                        // +0x48
    efd::Point3 m_hitPoint;                                 // +0x4c
    efd::Point3 m_hitNormal;                                // +0x58
};
MS2_CHECK_SIZE(Unk_PCBaseRayHit, 0x68);
int FUN_1408a2060(egf::Entity* pEntity, unsigned nProperty, efd::utf8string* pOut);
int FUN_1408a01e0(CStringA kText);                          // the liquid type of a cube name (0x40 = none)
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);       // the entity's model
int FUN_14123c580(PCBase* pActor);                          // the object id

template <class T> bool Common::Constants::Values<T>::Get(ATL::CAtlArray<T>& out)
{
    if (m_loaded)
    {
        out.RemoveAll();
        out.Append(m_values);
        return true;
    }
    if (!HasKey())
        Error("constants has no key");
    return false;
}

// @0x140cdb450
// MS2-FUNCTIONAL: temporaries
void CFishingManager::FUN_140cdb450()
{
    if (m_nBiteEnd != 0 && m_nBiteEnd < FUN_141472bc0())
    {
        MS2Ptr<CFishCube> cube(0);
        if (!m_cubes.Lookup(FUN_140cdc950(), cube))
            return;
        if (m_bGreat == 0)
        {
            Unk_FmCastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar != 0)
                pBar->FUN_1418e1390();
            COutPacket pkt(0x73, 0);
            pkt.Encode1(8);
            pkt.Encode1(1);
            FUN_140710590(pkt);
        }
        else
        {
            FUN_140cdc9d0(0x78, 0x7b);
            UIFishingFloatDialog* pFloat = Unk_FmGetDialog<UIFishingFloatDialog>((eUIClassID)0x4ee7);
            if (pFloat != 0)
            {
                pFloat->FUN_140f443d0(MS2Ptr<CFishCube>(cube));
                pFloat->FUN_141924680();
            }
            Unk_FmCastingBar* pBar = FUN_140ac2270(0x4e72);
            if (pBar != 0)
            {
                CAtlArray<CString> texts;
                TSingleton<Client::Constants>::GetInstance()->fishFightingCastingBarText.Get(texts);
                Unk_CastingParam param;
                param.m_str18 = L"showBlue";
                param.m_str20 = L"blue";
                param.m_str28 = FUN_140cddc70(texts);
                param.m_nDuration = 5000;
                pBar->FUN_1418e13c0(this, &param);
            }
            Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPC != 0)
            {
                CAtlArray<CString> texts;
                TSingleton<Client::Constants>::GetInstance()->fishFightingBalloonText.Get(texts);
                pPC->FUN_14166fff0(FUN_140cddc70(texts));
            }
            FUN_140a94350()->vfunc_7(0x493e2, 0);
        }
        if (m_nReelSound != 0)
            FUN_1411a6060(FUN_1403ed280(), m_nReelSound);
        m_nBiteEnd = 0;
    }
    if (m_uidRod != 0)
    {
        MS2Ptr<CItem> rod = DAT_143ab2a90.FUN_140a5d680(m_uidRod);
        if (rod.IsNull())
            SendFishingMode1();
    }
    if (m_tick.Check(1000) != 0 && FUN_140954150() != 0 && FUN_140ce0cb0() != 0)
    {
        int nBuff = FUN_140cdbe80();
        Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0 && reinterpret_cast<Unk_FmBuffs*>(pPC->FUN_1416749a0())->FUN_140970020(nBuff, 0, 0, 1) == 0)
        {
            MS2Ptr<CItem> bait = DAT_143ab2a90.FUN_140a5e2e0(m_nBaitId);
            if (bait.get() != 0 && FUN_140cdbbd0(MS2Ptr<CItem>(bait)) != 0)
                FUN_14092f4e0(reinterpret_cast<CItemData*>(bait->FUN_140527840())->FUN_14053dc20());
        }
    }
}

// @0x140cdba00
MS2Ptr<CFish> CFishingManager::FUN_140cdba00(unsigned nFishId)
{
    MS2Ptr<CFish> fish(0);
    m_fishes.Lookup(nFishId, fish);
    return fish;
}
MS2_REPLACE_METHOD(0x140CDBA00, CFishingManager, FUN_140cdba00, 123, 0x7632EFC3);

// @0x140cdba90
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void CFishingManager::FUN_140cdba90(ATL::CAtlArray<MS2Ptr<CFish> >& out)
{
    POSITION pos = m_fishes.GetStartPosition();
    while (pos != 0)
    {
        out.Add(m_fishes.GetValueAt(pos));
        m_fishes.GetNext(pos);
    }
}

// @0x140cdbb10
MS2Ptr<CFishCube> CFishingManager::FUN_140cdbb10(unsigned nCell)
{
    MS2Ptr<CFishCube> cube(0);
    m_cubes.Lookup(nCell, cube);
    return cube;
}
MS2_REPLACE_METHOD(0x140CDBB10, CFishingManager, FUN_140cdbb10, 121, 0xDF5ED915);

// @0x140cdbb90
int CFishingManager::FUN_140cdbb90()
{
    return m_nBiteEnd == 0;
}
MS2_REPLACE_METHOD(0x140CDBB90, CFishingManager, FUN_140cdbb90, 47, 0x728BBEF3);

// @0x140cdbbd0
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
int CFishingManager::FUN_140cdbbd0(MS2Ptr<CItem> rod)
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (!rod->FUN_140528980())
        return 0;
    if (rod->FUN_140525ca0() != 0 && pPC->FUN_141658f30() == 0)
        return 0;
    if (rod->FUN_140525db0() != 0 && pPC->FUN_141662de0() == 0)
        return 0;
    if (rod->FUN_140525e00() != 0 && !pPC->vfunc_146())
        return 0;

    if (!rod->FUN_140526810(pPC->vfunc_78()))
        return 0;
    if (!rod->FUN_140526790(pPC->FUN_141654700()))
        return 0;
    return 1;
}

// @0x140cdbdd0
int CFishingManager::GetAutoCount()
{
    return m_nAutoCount;
}
MS2_REPLACE_METHOD(0x140CDBDD0, CFishingManager, GetAutoCount, 17, 0xC417BCBA);

// @0x140cdbdf0
void CFishingManager::FUN_140cdbdf0(int nCount)
{
    m_nAutoCount = nCount;
    UIAutoFishingDialog* pDialog = Unk_FmGetDialog<UIAutoFishingDialog>((eUIClassID)0x4f07);
    if (pDialog != 0)
        pDialog->FUN_140fa5bc0();
}
MS2_REPLACE_METHOD(0x140CDBDF0, CFishingManager, FUN_140cdbdf0, 66, 0x92A25D21);

// @0x140cdbe40
void CFishingManager::SetBaitId(int nBait)
{
    m_nBaitId = nBait;
}
MS2_REPLACE_METHOD(0x140CDBE40, CFishingManager, SetBaitId, 25, 0xED11FA2A);

// @0x140cdbe60
int CFishingManager::GetBaitId()
{
    return m_nBaitId;
}
MS2_REPLACE_METHOD(0x140CDBE60, CFishingManager, GetBaitId, 17, 0x5EB41246);

// @0x140cdbe80
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
int CFishingManager::FUN_140cdbe80()
{
    if (m_nBaitId == 0)
        return 0;
    MS2Ptr<CItemData> data = FUN_14053f870(m_nBaitId);
    if (data.IsNull())
        return 0;
    unsigned short nLevel = data->FUN_14053dc40();
    Unk_FmAdditionalPtr add = FUN_1401958b0()->FUN_1407ee2f0(data->FUN_14053dc20(), nLevel);
    if (add.FUN_1409c4ad0())
        return 0;
    if (add.FUN_1407ebbf0()->m_levels.FUN_1407e59e0() == 0)
        return 0;
    return FUN_1407e4770(add.FUN_1407ebbf0()->m_levels.FUN_1407e46a0(0))->m_nBuffId;
}

// @0x140cdc000
// MS2-FUNCTIONAL: temporaries
CStringW CFishingManager::FUN_140cdc000(unsigned nSpotId)
{
    CFishingSpotDataPtr spot = TSingleton<CFishingTable>::GetInstance()->GetSpot(nSpotId);
    if (spot.get() == 0)
        return CStringW(L"");
    CStringW strHabitat;
    for (size_t i = 0; i < spot->m_arrLiquid.GetCount(); i++)
    {
        int& nHabitat = spot->m_arrLiquid[i];
        strHabitat += TSingleton<CFishingTable>::GetInstance()->FUN_1403b20b0(nHabitat);
        strHabitat += L", ";
    }
    strHabitat.TrimRight(L", ");
    CFishingSpotData* pSpot = spot.operator->();
    int nLevel = FUN_1409670c0()->FUN_14066af60(1, pSpot->m_nMinMastery);
    CStringW strLevel = TSingleton<CFishingTable>::GetInstance()->FUN_1403b2240(nLevel);
    unsigned nMastery = 0;
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
        nMastery = pPC->FUN_141662750(1);
    int nId = (nMastery < spot->m_nMinMastery) ? 0x719 : 0x718;
    return FUN_140632a60(nId, strHabitat, strLevel);
}

// @0x140cdc280
int CFishingManager::FUN_140cdc280(unsigned nFishId)
{
    CFishDataPtr data = TSingleton<CFishingTable>::GetInstance()->GetFish(nFishId);
    if (data.IsNull())
        return 0;
    MS2Ptr<CFish> fish = FUN_140cdba00(nFishId);
    if (fish.IsNull())
        return 0;
    return data->FUN_1403b1590(fish->m_nSize);
}
MS2_REPLACE_METHOD(0x140CDC280, CFishingManager, FUN_140cdc280, 238, 0xE86E14BC);

// @0x140cdc380
int CFishingManager::FUN_140cdc380(unsigned nFishId)
{
    if (TSingleton<CFishingManager>::GetInstance()->FUN_140cdba00(nFishId).get() != 0)
        return 1;
    CFishDataPtr data = TSingleton<CFishingTable>::GetInstance()->GetFish(nFishId);
    if ((data.get() ? true : false) && data->m_nCompanion != 0)
    {
        CFishData* pData = data.operator->();
        if (TSingleton<CFishingManager>::GetInstance()->FUN_140cdba00(pData->m_nCompanion).get() != 0)
            return 1;
    }
    return 0;
}

// @0x140cdc520
// MS2-FUNCTIONAL: temporaries
int CFishingManager::FUN_140cdc520()
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    Unk_PCBaseRayHit kHit;
    NiPoint3 kPos = pPC->vfunc_18();
    efd::Point3 kFrom = efd::Point3(kPos.x, kPos.y, kPos.z) + efd::Point3(0.0f, 0.0f, 10.0f);
    efd::Point3 kTo = DAT_143b01a60;
    if (FUN_1409f7ca0()->FUN_14168a310(kFrom, kTo, &kHit, 0, 0, 0) == 0 || kHit.m_hitEntity == 0)
        return 0;
    efd::utf8string kName("None");
    FUN_1408a2060(kHit.m_hitEntity, 0x15014205, &kName);
    if (FUN_1408a01e0(CStringA(kName.c_str())) == 0x40)
        return 0;
    if (FUN_1408a9bd0(kHit.m_hitEntity)->ContainsModel(0xd3b04f05))
        return 0;
    if (FUN_1408a9bd0(kHit.m_hitEntity)->ContainsModel(0x32767dd))
        return 0;
    if (FUN_1408a9bd0(kHit.m_hitEntity)->ContainsModel(0x72f49865))
        return 0;
    if (FUN_1403ed2d0()->FUN_141bcafa0(kHit.m_hitEntity) == 0)
        return 1;
    return 0;
}

// @0x140cdc810
int CFishingManager::FUN_140cdc810()
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    int nState = pPC->FUN_14166c930();
    int nSub = pPC->FUN_14166cc80();
    if (nState == 1)
    {
        if (nSub == 8)
            return 0;
        if (nSub == 9)
            return 0;
        if (nSub == 6)
            return 0;
        if (nSub == 7)
            return 0;
        return 1;
    }
    if (nState == 2)
        return 1;
    if (nState == 0xb || nState == 0xf)
        return 1;
    if (nState == 0x21)
    {
        efd::SmartPointer<Ridee> spRidee(pPC->FUN_1416764a0());
        if (spRidee)
        {
            int nRideState = spRidee->FUN_14166c930();
            if (nRideState == 1 || nRideState == 2)
                return 1;
        }
    }
    return 0;
}

// @0x140cdc950
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
unsigned CFishingManager::FUN_140cdc950()
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    CFishingGuideObject* pGuide = efd::DynamicCast<CFishingGuideObject>(pPC->FUN_141662440(1));
    if (pGuide == 0)
        return 0;
    return FUN_140ce02b0(pGuide)->FUN_140cd85e0();
}

// @0x140cdc9d0
void CFishingManager::FUN_140cdc9d0(int nState, int nGuideState)
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (pPC->FUN_14166cc80() != nState)
        pPC->FUN_14166cc40(nState);
    PCBase* pGuide = pPC->FUN_141662440(1);
    if (pGuide != 0 && pGuide->FUN_14166cc80() != nGuideState)
    {
        pGuide->FUN_14166cc40(nGuideState);
        pGuide->vfunc_22(efd::Point3(DAT_143b01a60));
    }
}
MS2_REPLACE_METHOD(0x140CDC9D0, CFishingManager, FUN_140cdc9d0, 195, 0x179ED967);

// @0x140cdcaa0
// MS2-FUNCTIONAL: temporaries
void CFishingManager::FUN_140cdcaa0(MS2Ptr<CFishCube> cube)
{
    if (cube.IsNull())
        return;
    efd::Point3 kOffset;
    NiTransform kXform;
    FUN_1420849a0(&kXform.m_Rotate);
    kXform.m_fScale = 1.0f;
    efd::Point3 kUp(0.0f, 0.0f, 150.0f);
    efd::Point3 kPos = FUN_1408a15b0(FUN_1408a0400(cube->m_id), kOffset) + kUp;
    kXform.m_Translate = NiPoint3(kPos.x, kPos.y, kPos.z);
    Unk_EffectTarget kTarget;
    kTarget.m_strName = FUN_1401d31f0()->m_strCubeMarkEffect;
    kTarget.m_nKind = 0;
    kTarget.m_unk_20 = &kXform;
    m_marks.Add(FUN_1403ed280()->FUN_1411a49c0(kTarget));
}

// @0x140cdcc70
// MS2-FUNCTIONAL: temporaries
void CFishingManager::FUN_140cdcc70()
{
    int nCell = FUN_140cdc950();
    efd::Point3 kOffset;
    efd::Point3 kPos = FUN_1408a15b0(FUN_1408a0400(nCell), kOffset);
    kOffset = kPos;
    kOffset.z = kOffset.z + 150.0f;
    NiTransform kXform;
    kXform.m_fScale = 1.0f;
    FUN_1420849a0(&kXform.m_Rotate);
    kXform.m_Translate = NiPoint3(kOffset.x, kOffset.y, kOffset.z);
    Unk_EffectTarget kTarget;
    kTarget.m_strName = FUN_1401d31f0()->m_strSplashEffect;
    kTarget.m_nKind = 0;
    FUN_1403ed280()->FUN_1411a4a00(kTarget);
}

// @0x140cdcde0
void CFishingManager::FUN_140cdcde0()
{
    for (size_t i = 0; i < m_marks.GetCount(); i++)
        FUN_1411a6060(FUN_1403ed280(), m_marks[i]);
    m_marks.RemoveAll();
}
MS2_REPLACE_METHOD(0x140CDCDE0, CFishingManager, FUN_140cdcde0, 128, 0xBC1CDED3);

// @0x140cdce70
// MS2-FUNCTIONAL: the fishing action
void CFishingManager::FUN_140cdce70(MS2Ptr<CItem> rod)
{
    if (rod.IsNull())
        return;
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
        pPC->vfunc_59(0x2d, new StateFishingData(rod->FUN_1405276c0()), 0, 0);
    m_bFishing = 1;
    m_nBiteEnd = 0;
    m_bGreat = 0;
    m_uidRod = rod->FUN_140526a50();
    FUN_141276180(s_strThrowSound, CString(""));
    UIAutoFishingDialog* pDialog = Unk_FmGetDialog<UIAutoFishingDialog>((eUIClassID)0x4f07);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630() != 0)
            return;
        pDialog->FUN_140fa5ba0(4);
        pDialog->FUN_141924680();
    }
}

// @0x140cdd030
void CFishingManager::FUN_140cdd030()
{
    if (0 < m_nAutoCount)
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_msg_autofishing_extend_cancel")), 1, 1);
    m_nAutoCount = 0;
    m_bFishing = 0;
    m_nBiteEnd = 0;
    m_bGreat = 0;
    m_uidRod = 0;
    FUN_140cdcde0();
    if (m_nReelSound != 0)
        FUN_1411a6060(FUN_1403ed280(), m_nReelSound);
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0 && pPC->FUN_14166c930() == 0x2d)
        pPC->vfunc_59(1, 0, 0, 0);
    if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4f07) != 0)
        FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4f07);
    Unk_FmCastingBar* pBar = FUN_140ac2270(0x4e72);
    if (pBar != 0)
        pBar->FUN_1418e1390();
}
MS2_REPLACE_METHOD(0x140CDD030, CFishingManager, FUN_140cdd030, 439, 0x93841DF5);

// @0x140cdd1f0
// MS2-FUNCTIONAL: temporaries
void CFishingManager::FUN_140cdd1f0()
{
    FUN_140cdc9d0(0x76, 0x7b);
    MS2Ptr<CFishCube> cube = FUN_140cdbb10(FUN_140cdc950());
    if (cube.IsNull())
        return;
    Unk_FmCastingBar* pBar = FUN_140ac2270(0x4e72);
    if (pBar != 0)
    {
        CAtlArray<CString> texts;
        TSingleton<Client::Constants>::GetInstance()->fishingStartCastingBarText.Get(texts);
        int nDuration = cube->m_c;
        if (m_bCountdown != 0)
            nDuration = m_nBiteEnd - FUN_141472bc0();
        CStringW strEnd(L"");
        pBar->FUN_1418e12f0(this, FUN_140cddc70(texts), nDuration, false, true, strEnd);
    }
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        CAtlArray<CString> texts;
        TSingleton<Client::Constants>::GetInstance()->fishingStartBalloonText.Get(texts);
        pPC->FUN_14166fff0(FUN_140cddc70(texts));
        if (m_nReelSound != 0)
            FUN_1411a6060(FUN_1403ed280(), m_nReelSound);
        Unk_EffectTarget kTarget;
        kTarget.m_strName = "ETC/Fishing/Sound_Fish_Action_Reel.xml";
        kTarget.m_nKind = 1;
        FUN_140a53190(&kTarget, FUN_14123c580(pPC));
        m_nReelSound = FUN_1403ed280()->FUN_1411a49c0(kTarget);
    }
    FUN_141276180(s_strStartSound, CString(""));
}

// @0x140cdd540
// MS2-FUNCTIONAL: register allocation / temporary layout differs from the exe
void CFishingManager::FUN_140cdd540(unsigned nFishId, unsigned nSize, int bSuccess)
{
    m_resultTimer.FUN_140868750(2000);
    m_nBiteEnd = 0;
    m_bGreat = 0;
    FUN_140cdc9d0(0x79, 0x7c);
    FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4ee7);
    if (bSuccess == 0)
    {
        Unk_FmFishGuide* pGuide = FUN_140938cd0(0x4e5d);
        if (pGuide != 0)
            FUN_141ac11b0(pGuide, nFishId, nSize);
        FUN_141276180(s_strFailSound, CString(""));
    }
    else
    {
        FUN_1409331e0()->FUN_14138bf00(0x16, nFishId, 0);
        Unk_FmFishGuide* pGuide = FUN_140938cd0(0x4e5d);
        if (pGuide != 0)
            FUN_141ac0e50(pGuide, nFishId, nSize);
        CFishDataPtr data = TSingleton<CFishingTable>::GetInstance()->GetFish(nFishId);
        if (data.get() != 0)
        {
            if (data->FUN_1403b14d0(nSize) == 0)
                FUN_141276180(s_strSuccessSound, CString(""));
            else
                FUN_141276180(s_strGreatSuccessSound, CString(""));
        }
    }
    UIFishingBookDialog* pBook = Unk_FmGetDialog<UIFishingBookDialog>((eUIClassID)0x4ee6);
    if (pBook != 0 && pBook->FUN_141924630() != 0)
        pBook->FUN_140f419e0();
    FUN_140cdcc70();
    m_record.FUN_140cd8e70(nFishId, bSuccess);
}

// @0x140cdd7b0
// MS2-FUNCTIONAL: temporaries
int CFishingManager::FUN_140cdd7b0()
{
    Unk_FmPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    NiPoint3 kPos = pPC->vfunc_18();
    efd::Point3 kAt = efd::Point3(kPos.x, kPos.y, kPos.z) + efd::Point3(0.0f, 0.0f, 75.0f);
    NiPoint3 kRot = pPC->vfunc_20();
    efd::Point3 kAhead;
    kAhead.x = (kAt.x <= 0.0f) ? -75.0f : 75.0f;
    kAhead.y = (kAt.y <= 0.0f) ? -75.0f : 75.0f;
    kAhead.z = 0.0f;
    Unk_FmInt3 kBase = FUN_1408a1430(kAt + kAhead);
    efd::SmartPointer<Unk_FmCubeMap> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
    float fYaw = kRot.z;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int k = j;
            if ((fYaw <= 45.0f || 135.0f < fYaw) && (fYaw <= 225.0f || 315.0f < fYaw))
                k = i;
            if (k == 0 || k == 6)
                continue;
            if (!((fYaw <= 315.0f && 45.0f < fYaw) || j < 3))
                continue;
            if (!(fYaw <= 45.0f || 135.0f < fYaw || 3 < i))
                continue;
            if (!(fYaw <= 135.0f || 225.0f < fYaw || 3 < j))
                continue;
            if (!(fYaw <= 225.0f || 315.0f < fYaw || i < 3))
                continue;
            Unk_FmInt3 kTop;
            kTop.x = kBase.x - 3 + i;
            kTop.y = kBase.y - 3 + j;
            kTop.z = kBase.z + 1;
            if (spCubeMap->FUN_1410b8a60(kTop) != 0)
                continue;
            for (int n = 0; n < 3; n++)
            {
                Unk_FmInt3 kCell;
                kCell.x = kBase.x - 3 + i;
                kCell.y = kBase.y - 3 + j;
                kCell.z = kBase.z - n;
                MS2Ptr<Cube> cube(spCubeMap->FUN_1410b8a60(kCell));
                if (cube.get() != 0)
                {
                    if (cube->field44 == 0x40)
                        return 1;
                    break;
                }
            }
        }
    }
    return 0;
}

// @0x140cddc70
CStringW CFishingManager::FUN_140cddc70(const ATL::CAtlArray<CString>& texts)
{
    int nCount = (int)texts.GetCount();
    if (nCount != 0)
    {
        unsigned nIndex = FUN_140768010(nCount, 0);
        return FUN_14028b8e0(FUN_14016a730(texts[nIndex], 0));
    }
    return CStringW(L"");
}

// ---- CFish ----

// @0x140cdfd70
void CFish::FUN_140cdfd70()
{
    m_nId = 0;
    m_n1c = 0;
    m_n20 = 0;
    m_nSize = 0;
    m_n28 = 0;
    m_bNew = 0;
}
MS2_REPLACE_METHOD(0x140CDFD70, CFish, FUN_140cdfd70, 78, 0x96CC443B);

// @0x140ce26d0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4300-0x142ca4450 .text$yd
