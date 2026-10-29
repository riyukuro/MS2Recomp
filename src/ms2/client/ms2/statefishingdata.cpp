// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateFishing / StateFishingFloat / StateFishingData: the actor
// states of a player fishing (cast, wait, bite, reel in) and of the guide object's float, the payload with the rod id and
// the MS2Ptr glue they instantiate. See statefishingdata.h.
// MS2-UNIT: ?\statefishingdata.cpp
// MS2-RANGE: 0x1400d5fd0-0x1400d6090 .text$di
// MS2-RANGE: 0x140dda280-0x140ddcf00 .text$mn
// MS2-PIN: ?get@?$MS2Ptr@VStateFishingData@@@@QEBAPEAVStateFishingData@@XZ 0x140ddcae0
// MS2-PIN: ??C?$MS2Ptr@VStateFishingData@@@@QEBAPEAVStateFishingData@@XZ 0x140ddcb00
// MS2-PIN: ?get@?$MS2Ptr@VCGemFishing@@@@QEBAPEAVCGemFishing@@XZ 0x140ddcad0
// MS2-PIN: ??C?$MS2Ptr@VCGemFishing@@@@QEBAPEAVCGemFishing@@XZ 0x140ddcaf0
// MS2-PIN: ??C?$MS2Ptr@VCGemBase@@@@QEBAPEAVCGemBase@@XZ 0x140ddcc50
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statefishingdata.cpp"    // assumed
#define NOMINMAX                        // NxPhysics (physxhelper.h)
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <string.h>
#include <errno.h>
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <NiNode.h>
#include <NiAVObject.h>

#include "statefishingdata.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/clonepc.h"
#include "ms2/client/ms2/cubecraft_1.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/uicastingbar.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/fishsimultedata.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The names of the shop sort orders (the initializer of this unit's .text$di).
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The state-sync record (slots 1/2 of StateData): the rod id is kept as text at +0x70.
class Unk_StateDataArg
{
public:
    char m_pad_00[0x70];
    CString m_str70;                                         // +0x70
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

CString FUN_140b62550(int n);                                // number -> text

extern Vector3 DAT_143b01a60;                       // the zero point
extern Vector3 DAT_143a08cf8;                       // the up vector
extern NiRTTI DAT_143afa4d8;                                // RTTI NiNode

class AdditionalCli : public CPtred
{
};
class Unk_FishPacket : public CPtred
{
};

struct Unk_FsSpeed { float m_f0; float m_f4; float m_f8; };

// A player seen with the slots after PCBase's last declared one (123): the held item of the player; the equipment.
class Unk_FsPC : public PCBase
{
public:
    virtual void vfunc_124();
    virtual void vfunc_125();
    virtual void vfunc_126();
    virtual void vfunc_127(CItem* pItem, int n);             // MS2: slot 127 (0x3f8) puts the item into the hand
    virtual void vfunc_128(CItem* pItem, int n);             // MS2: slot 128 (0x400) takes it out again
    PCGemEquip* FUN_14165f460();                             // the worn gems
    Unk_FsSpeed* FUN_141671920();                            // the move speeds (pcbase.h: float*)
    Vector3 FUN_14123c360();                                 // m_pos98 (gameobject.h: NiPoint3)
    void FUN_14166d970(const efd::Point3& kDir);             // turn to a direction (pcbase.h: by value)
    efd::Point3 FUN_141674b60(Vector3 kDir);                 // local dir -> world dir (pcbase.h)
};

// The owner seen through its vftable where gameobject.h/pcbase.h's shared slot list declares a different parameter form:
// slot 22 takes the point and slot 68 the move by value (the caller copies the point into an argument temp), and slot 18
// returns an efd::Point3 (one caller converts it to a NiPoint3).
class Unk_FsOwnerSlots
{
public:
#define MS2_FS_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_FS_SLOTS(0, 1, 2, 3, 4) MS2_FS_SLOTS(5, 6, 7, 8, 9) MS2_FS_SLOTS(10, 11, 12, 13, 14)
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual efd::Point3 vfunc_18();                                         // 18 the position (pcbase.h: NiPoint3)
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kPos);                                // 22 0x14123c3a0
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_FS_SLOTS(25, 26, 27, 28, 29) MS2_FS_SLOTS(30, 31, 32, 33, 34) MS2_FS_SLOTS(35, 36, 37, 38, 39)
    MS2_FS_SLOTS(40, 41, 42, 43, 44) MS2_FS_SLOTS(45, 46, 47, 48, 49) MS2_FS_SLOTS(50, 51, 52, 53, 54)
    MS2_FS_SLOTS(55, 56, 57, 58, 59) MS2_FS_SLOTS(60, 61, 62, 63, 64)
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
#undef MS2_FS_SLOTS
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};

// The fishing manager with the members of the fishing states.
class Unk_FsFishMgr : public CFishingManager
{
public:
    void FUN_140cdac50();                                    // the cast was thrown
    void FUN_140cdb0a0();                                    // leaves the casting
    int FUN_140ce0cb0();                                     // a fish is hooked
    MS2Ptr<Unk_FishPacket> FUN_140cdbb10(int nCell);         // the fishing zone of a grid cell
};
static inline Unk_FsFishMgr* FsFishMgr() { return static_cast<Unk_FsFishMgr*>(TSingleton<CFishingManager>::GetInstance()); }

// The game mode singleton (hud / sound): slot 7 starts a mode, slot 8 ends it.
class Unk_FsGameMode
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int nMode, int n);                  // MS2: slot 7 (0x38)
    virtual void vfunc_8(int n);                             // MS2: slot 8 (0x40)
};
Unk_FsGameMode* FUN_140a94350();

// The effect manager: plays an effect for a request (returns its id), stops it by id, hands out the effect root.
class Unk_FsEffectMgr
{
public:
    unsigned FUN_1411a49c0(Unk_EffectQuery* pQuery);
    NiNode* FUN_1411a6b10();
};
Unk_FsEffectMgr* FUN_1403ed280();
void FUN_1411a6060(Unk_FsEffectMgr* pMgr, int nId);

// The model loader (singleton): loads a nif by path.
class Unk_FsResourceMgr
{
public:
    NiAVObjectPtr FUN_141551ea0(CString strPath, bool bA, int nB, int nC, int nD);   // model load
};
Unk_FsResourceMgr* FUN_140a0afd0();
void* FUN_1409849b0(void* pHandle);                          // handle -> node pointer
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);   // dynamic cast through an NiRTTI

// The optimizer with the inline accessor of this unit.
class Unk_FsOptimizer : public COptimizer
{
public:
    int FUN_140ddcc90() { return m_nMode; }                  // 0x140ddcc90
};
Unk_FsOptimizer* FUN_1409f7c90();

class Unk_FsWorld
{
public:
    int FUN_141bd1a10(GameObject* pObject);
};
Unk_FsWorld* FUN_1403ed2d0();

class Unk_PCBaseMoveTarget { public: efd::Point3 FUN_141683900(); };

CPhysXHelper* FUN_1409f7ca0();
CUIService* FUN_1403ed2b0();
UICastingBar* FUN_140ac2270(int nId);
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned nId);   // efd::ClassInfo::IsKindOf
__int64 FUN_14028d0e0();                                     // the current time
PCBase* FUN_140974230(PCBase* pPC);                          // the player of an actor
ClonePC* FUN_1405a7e30(PCBase* pPC);                         // the mannequin of a player
CFishingGuideObject* FUN_1416625e0(PCBase* pPC);             // the fishing guide object of a player
class Unk_PCBaseBuffs { public: MS2Ptr<AdditionalCli> FUN_14096fd30(int nKind); };   // AdditionalCliList (FUN_1416749a0)
efd::Point3 FUN_140a0b080(const efd::Point3& kA, const efd::Point3& kB, const efd::Point3& kC);
void FUN_140b86230(const efd::Point3& kDir, NiMatrix3& kOut);   // rotation matrix of a direction
Unk_FsCell FUN_1408a1430(Vector3 k);                 // the grid cell of a point
int FUN_1408a03c0(Unk_FsCell kCell);                         // the cell as a key
void FUN_140ae1160(egf::Entity* pEntity, unsigned nProp, unsigned short* pValue);   // GetProperty(short)

// Plays an animation on the owner at the owner's speed (spelled out in every branch: the name is a block-local string).
#define MS2_FS_PLAY(pszAnim)                                                                                  \
    {                                                                                                         \
        efd::utf8string kAnim(pszAnim);                                                                       \
        m_pOwner->FUN_14166dd20(kAnim, m_pOwner->FUN_1416713c0(), false, false);                              \
    }

// @0x140ddc910
// The guide object (class id 0x6200064) of an object, NULL when it is none.
CFishingGuideObject* FUN_140ddc910(GameObject* pObject)
{
    void* pValue = 0;
    if (pObject != 0 && pObject->TypeCast(0x6200064, &pValue))
        return (CFishingGuideObject*)pValue;
    else
        return 0;
}

// ---- StateFishingData ----

// @0x140dda280
StateFishingData::StateFishingData() : m_nRod(0)
{
}

// @0x140dda2c0
StateFishingData::StateFishingData(int nRod) : m_nRod(nRod)
{
}

// @0x140dda310
void StateFishingData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = FUN_140b62550(m_nRod);
}

// @0x140dda390
void StateFishingData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_nRod = FUN_1407181d0(p->m_str70);
}

// ---- StateFishing ----

// @0x140dda3e0
StateFishing::StateFishing(PCBase* pOwner) : State(pOwner), m_spEffect(0)
{
    m_n14 = 0;
    m_spEffect = 0;
    m_spItem = 0;
    m_nRod = 0;
    m_nA8 = 0;
    m_nAC = 1;
    m_nB0 = 0;
    m_nEffect = 0;
}

// @0x140dda4f0
StateFishing::~StateFishing()
{
}

// @0x140dda570
void StateFishing::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_nA8 = 0;
    m_n10 = 0x75;
    m_spFishingData.AssignRaw(dynamic_cast<StateFishingData*>(pData));
    if (m_spFishingData.IsNull())
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    m_nRod = FUN_140ddb620();
    FUN_140ddb740(m_nRod);
    if (FUN_1417b84b0() != 0)
    {
        reinterpret_cast<Unk_FsOwnerSlots*>(m_pOwner)->vfunc_22(reinterpret_cast<const efd::Point3&>(DAT_143b01a60));
        FUN_140a94350()->vfunc_7(0x493e2, 0);
        return;
    }
    if (FUN_14087ddc0(FUN_1417b8370() ? FUN_1417b8370()->GetClassDesc() : 0, 0x6200044))
        m_nA8 = 1;
}

// @0x140dda770
void StateFishing::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (FUN_1417b8560() != 0)
    {
        if (TSingleton<CFishingManager>::GetInstance()->FUN_140954150() != 0)
            FsFishMgr()->FUN_140cdb0a0();
    }
    Unk_FsPC* pPC = static_cast<Unk_FsPC*>(FUN_1417b8370());
    if (pPC != 0)
    {
        pPC->vfunc_128(m_spItem.get(), 0);
        m_spItem = 0;
    }
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
            pBar->FUN_1418e1390();
        if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)0x4ee7) != 0)
            FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4ee7);
    }
    if (m_spEffect)
    {
        NiNode* pParent = m_spEffect->GetParent();
        if (pParent != 0)
        {
            pParent->DetachChild(m_spEffect);
            m_spEffect = 0;
        }
    }
    if (m_nEffect != 0)
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
    FUN_140a94350()->vfunc_8(0);
}

// @0x140dda950
void StateFishing::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pPC = FUN_140974230(m_pOwner);
    if (pPC != 0)
    {
        int nRod = FUN_140ddb620();
        if (m_nRod != nRod)
        {
            FUN_140ddb740(nRod);
            m_nRod = nRod;
        }
        if (m_nB0 != m_pOwner->vfunc_25())
        {
            m_nB0 = m_pOwner->vfunc_25();
            if (m_spEffect ? true : false)
            {
                if (FUN_1409f7c90()->FUN_140ddcc90() == 0)
                    m_spEffect->SetAppCulled(m_nB0 ? true : false);
            }
        }
        if (m_nA8 == 0)
        {
            CFishingGuideObject* pGuide = FUN_1416625e0(pPC);
            if (pGuide != 0)
            {
                efd::Point3 kRot = FUN_140a0b080(pGuide->vfunc_18(), pPC->vfunc_18(), reinterpret_cast<const efd::Point3&>(DAT_143a08cf8));
                static_cast<Unk_FsPC*>(pPC)->FUN_14166d970(kRot);
                if (m_spEffect)
                {
                    NiMatrix3 kMat;
                    FUN_140b86230(kRot, kMat);
                    m_spEffect->SetRotate(kMat);
                }
                m_nA8 = 1;
            }
        }
    }
    reinterpret_cast<Unk_FsOwnerSlots*>(m_pOwner)->vfunc_68(reinterpret_cast<const efd::Point3&>(DAT_143b01a60), fTime, 0, 0, 0);
}

// @0x140ddac60
void StateFishing::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    MyPC* pMy = FUN_1417b84b0();
    if (pMy != 0)
    {
        if (FUN_1417b7e40() == 0x75)
        {
            if (eSequenceID == pkManager->GetTargetAnimation())
            {
                m_n10 = 0x76;
                CFishingGuideObject* pGuide = FUN_1416625e0(pMy);
                if (pGuide != 0)
                    pGuide->FUN_1410a4cb0();
                FsFishMgr()->FUN_140cdac50();
            }
        }
        else if (FUN_1417b7e40() == 0x79)
        {
            if (eSequenceID == pkManager->GetTargetAnimation())
            {
                m_n10 = 0x76;
                PCBase* pGuide = FUN_1416625e0(pMy);
                if (pGuide != 0)
                    pGuide->FUN_14166cc40(0x7a);
                bool bLeave = FsFishMgr()->FUN_140ce0cb0() || pMy->FUN_1416749a0()->FUN_14096fd30(1);
                if (bLeave)
                    FsFishMgr()->SendFishingMode9();
            }
        }
        else if (FUN_1417b7e40() == 0x77)
        {
            if (eSequenceID == pkManager->GetTargetAnimation())
                m_n10 = 0x76;
        }
    }
    else
    {
        ClonePC* pClone = FUN_1405a7e30(FUN_1417b8370());
        if (pClone != 0)
        {
            if (FUN_1417b7e40() == 0x75)
            {
                if (eSequenceID == pkManager->GetTargetAnimation())
                {
                    m_n10 = 0x76;
                    CFishingGuideObject* pGuide = FUN_1416625e0(pClone);
                    if (pGuide != 0)
                        pGuide->FUN_1410a4cb0();
                }
            }
        }
    }
}

// @0x140ddaf00
void StateFishing::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pMy = FUN_1417b84b0();
    if (pMy == 0)
        return;
    if (m_n10 == 0x76)
    {
        if (m_timer.FUN_140868c00() != 0)
        {
            m_n10 = 0x77;
            m_timer.FUN_1408687f0();
            m_nAC = (m_nAC == 0);
        }
        if (m_timer.FUN_140868ba0() == 0)
            m_timer.FUN_140868750(*Client::Constants::GetInstance()->fisherBoreDuration.Get());
    }
    else
    {
        m_timer.FUN_1408687f0();
    }
    FUN_1417b9460();
}

// @0x140ddb010
void StateFishing::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    switch (m_n10)
    {
    case 0x75:
        if (m_pOwner->FUN_14166dc50() != "Fishing_Start_A")
            MS2_FS_PLAY("Fishing_Start_A")
        break;
    case 0x76:
        if (m_pOwner->FUN_14166dc50() != "Fishing_Idle_A")
            MS2_FS_PLAY("Fishing_Idle_A")
        break;
    case 0x77:
    {
        bool bPlay = m_pOwner->FUN_14166dc50() != "Fishing_Bore_A"
            && m_pOwner->FUN_14166dc50() != "Fishing_Bore_B";
        if (bPlay)
            MS2_FS_PLAY(m_nAC ? "Fishing_Bore_A" : "Fishing_Bore_B")
        break;
    }
    case 0x78:
        if (m_pOwner->FUN_14166dc50() != "Fishing_Reel_In_A")
            MS2_FS_PLAY("Fishing_Reel_In_A")
        break;
    case 0x79:
        if (m_pOwner->FUN_14166dc50() != "Fishing_End_A")
            MS2_FS_PLAY("Fishing_End_A")
        break;
    }
}

// @0x140ddb4e0
int StateFishing::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_nSub)
        return 0;
    return 1;
}

// @0x140ddb580
void StateFishing::vfunc_6()
{
    if (FUN_1417b8560() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x140ddb5d0
int StateFishing::FUN_140ddb5d0()
{
    if (m_spFishingData.get() != 0)
        return m_spFishingData->m_nRod;
    return 0;
}

// @0x140ddb620
int StateFishing::FUN_140ddb620()
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        MS2Ptr<CGemBase> spGem = static_cast<Unk_FsPC*>(pPC)->FUN_14165f460()->FUN_141270740(8);
        if (spGem.get() != 0)
        {
            MS2Ptr<CGemFishing> spFishing(dynamic_cast<CGemFishing*>(spGem.operator->()));
            if (spFishing.get() != 0)
            {
                unsigned nRod = spFishing->GetDataId();
                if (nRod != 0)
                    return nRod;
            }
        }
    }
    return FUN_140ddb5d0();
}

// @0x140ddb740
void StateFishing::FUN_140ddb740(int nRod)
{
    MS2Ptr<CFishingRodData> spRod = CFishingTable::GetInstance()->GetRod(nRod);
    if (spRod.IsNull())
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    Unk_FsPC* pPC = static_cast<Unk_FsPC*>(FUN_1417b8370());
    if (pPC != 0)
    {
        if (m_spItem.get())
        {
            pPC->vfunc_128(m_spItem.get(), 0);
            m_spItem = 0;
        }
        MS2Ptr<CItem> spNew(new CItem);
        if (spNew->FUN_140523c40(nRod, 1, 0))
        {
            spNew->FUN_140526b30(m_pOwner->FUN_14123c580());
            spNew->FUN_140526a70(FUN_14028d0e0());
            if (FUN_14087ddc0(pPC ? pPC->GetClassDesc() : 0, 0x6200044))
                spNew->FUN_14052a130(3);
            else
                spNew->FUN_14052a130(5);
            pPC->vfunc_127(spNew.get(), 0);
            m_spItem = spNew;
        }
    }
    if (m_spEffect)
    {
        NiNode* pParent = m_spEffect->GetParent();
        if (pParent != 0)
        {
            pParent->DetachChild(m_spEffect);
            m_spEffect = 0;
        }
    }
    if (spRod->m_strChair.GetLength() > 0)
    {
        m_spEffect = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, FUN_140a0afd0()->FUN_141551ea0(CString(spRod->m_strChair), false, 5, 0, 0)));
        if (m_spEffect)
        {
            NiNode* pRoot = FUN_1403ed280()->FUN_1411a6b10();
            ClonePC* pClone = FUN_1405a7e30(pPC);
            if (pClone != 0)
                static_cast<AvatarPC*>(pClone)->FUN_1409f5560(m_spEffect);
            else
                pRoot->AttachChild(m_spEffect, true);
            if (pRoot != 0 && pClone == 0)
            {
                NiPoint3 kDir = m_pOwner->vfunc_20();
                NiMatrix3 kMat;
                FUN_140b86230(kDir, kMat);
                m_spEffect->SetRotate(kMat);
                m_spEffect->SetTranslate(reinterpret_cast<Unk_FsOwnerSlots*>(m_pOwner)->vfunc_18());
                m_spEffect->UpdateEffects();
                m_spEffect->UpdateProperties();
                m_spEffect->Update(0.0f, true);
                m_nB0 = m_pOwner->vfunc_25();
                if (FUN_1409f7c90()->FUN_140ddcc90() == 0 && m_nB0 != 0)
                    m_spEffect->SetAppCulled(true);
            }
        }
    }
    if (m_nEffect != 0)
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
    if (spRod->m_strChairEffect.GetLength() > 0)
    {
        Unk_EffectQuery kQuery;
        kQuery.m_strName = spRod->m_strChairEffect;
        kQuery.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
        kQuery.SetActor(m_pOwner->FUN_14123c580());
        m_nEffect = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
    }
}

// @0x140ddcbd0
MS2Ptr<StateData> StateFishing::vfunc_27()
{
    return MS2Ptr<StateData>(new StateFishingData());
}

// @0x140ddcc60
int StateFishing::vfunc_1()
{
    return 0x2d;
}

// @0x140ddcc80
int StateFishing::vfunc_19()
{
    return 0;
}

// ---- StateFishingFloat ----

// @0x140ddbf50
StateFishingFloat::StateFishingFloat(PCBase* pOwner) : State(pOwner)
{
}

// @0x140ddbf90
StateFishingFloat::~StateFishingFloat()
{
}

// @0x140ddbfc0
void StateFishingFloat::vfunc_4(StateData* pData)
{
    m_n10 = 0x7a;
}

// @0x140ddbfe0
void StateFishingFloat::vfunc_5(int n)
{
}

// @0x140ddbff0
void StateFishingFloat::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    Unk_FsSpeed* pSpeed = static_cast<Unk_FsPC*>(m_pOwner)->FUN_141671920();
    efd::Point3 kDir = static_cast<Unk_FsPC*>(m_pOwner)->FUN_141674b60(static_cast<Unk_FsPC*>(m_pOwner)->FUN_14123c360());
    efd::Point3 kVel = kDir * pSpeed->m_f8;
    efd::Point3 kStep = kVel * (float)fTime;
    if (FUN_140ddc4b0(kDir))
        reinterpret_cast<Unk_FsOwnerSlots*>(m_pOwner)->vfunc_68(kStep, fTime, 0, 0xffffffff, 1);
}

// @0x140ddc180
void StateFishingFloat::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (m_pOwner->vfunc_63() == 0)
        return;
    if (m_n10 != 0x7a)
        return;
    Unk_PCBaseMoveTarget* pMove = static_cast<Unk_PCBaseMoveTarget*>(m_pOwner->FUN_14166d240());
    efd::Point3 kTarget = pMove->FUN_141683900();
    reinterpret_cast<Unk_FsOwnerSlots*>(m_pOwner)->vfunc_22(kTarget);
}

// @0x140ddc240
void StateFishingFloat::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (m_n10 == 0x7a)
        MS2_FS_PLAY("float_Idle_A")
    else if (m_n10 == 0x7b)
        MS2_FS_PLAY("float_Fishing_A")
    else if (m_n10 == 0x7c)
        MS2_FS_PLAY("float_End_A")
}

// @0x140ddc3c0
Unk_FsCell StateFishingFloat::FUN_140ddc3c0(efd::Point3 kPoint)
{
    Vector3 kCorner;
    kCorner.x = (kPoint.x > 0.0f) ? 75.0f : -75.0f;
    kCorner.y = (kPoint.y > 0.0f) ? 75.0f : -75.0f;
    kCorner.z = 0.0f;
    return FUN_1408a1430(reinterpret_cast<Vector3&>(kPoint).FUN_14097fd50(kCorner));
}

// @0x140ddc4b0
// The hit point of the ray as an efd::Point3 (the ray info keeps Vector3 placeholders).
#define MS2_FS_HIT (*reinterpret_cast<efd::Point3*>(&kRay.m_hitPoint))

int StateFishingFloat::FUN_140ddc4b0(efd::Point3 kDir)
{
    if (kDir == reinterpret_cast<const efd::Point3&>(DAT_143b01a60))
        return 1;
    CFishingGuideObject* pGuide = FUN_140ddc910(m_pOwner);
    if (pGuide == 0)
        return 0;
    PCBase* pPC = pGuide->FUN_1410a1310();
    if (!FUN_14087ddc0(pPC ? pPC->GetClassDesc() : 0, 0x6200004))
        return 1;
    NiPoint3 kStart = m_pOwner->vfunc_18();
    kStart += kDir * 30.0f;
    kStart.z = pPC->vfunc_18().z + 150.0f;
    Unk_RayCastInfo kRay;
    kRay.m_origin = reinterpret_cast<Vector3&>(kStart);
    kRay.m_dir = DAT_143a08cf8.FUN_1409f7960();
    kRay.m_maxDist = 0;
    kRay.m_groups = 0x301;
    efd::Point3 kFoot = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 5.0f);
    Unk_FsCell kCellA = FUN_140ddc3c0(kFoot);
    if (FUN_1409f7ca0()->CastRay(&kRay, 0))
    {
        if (kRay.m_hitEntity != 0)
        {
            unsigned short nType = 0;
            FUN_140ae1160(static_cast<egf::Entity*>(kRay.m_hitEntity), 0xada5c5d2, &nType);
            if (nType != 8)
                return 0;
            Unk_FsCell kCellB = FUN_140ddc3c0(MS2_FS_HIT + efd::Point3(0.0f, 0.0f, 55.0f));
            if (static_cast<Unk_FsFishMgr*>(TSingleton<CFishingManager>::GetInstance())->FUN_140cdbb10(FUN_1408a03c0(FUN_140ddc3c0(MS2_FS_HIT))).IsNull())
                return 0;
            if (kCellA.z != kCellB.z)
                m_pOwner->vfunc_19(MS2_FS_HIT + efd::Point3(0.0f, 0.0f, 55.0f));
        }
        return 1;
    }
    return 0;
}

// @0x140ddcc70
int StateFishingFloat::vfunc_1()
{
    return 0x2e;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca5c60-0x142ca5c90 .text$yd
