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

extern Unk_StreamPoint DAT_143b01a60;                       // the zero point
extern Unk_StreamPoint DAT_143a08cf8;                       // the up vector
extern NiRTTI DAT_143afa4d8;                                // RTTI NiNode

class AdditionalCli : public CPtred
{
};
class Unk_FishPacket : public CPtred
{
};

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
NiNode* FUN_140a0b000(NiAVObject* pObject);                  // GetParent
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
char FUN_1402a5b40(const CString& a, const char* b);        // CString != C string
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned nId);   // efd::ClassInfo::IsKindOf
void FUN_140a0b300(NiAVObject* pNode, char bCulled);         // set app-culled
__int64 FUN_14028d0e0();                                     // the current time
PCBase* FUN_140974230(PCBase* pPC);                          // the player of an actor
ClonePC* FUN_1405a7e30(PCBase* pPC);                         // the mannequin of a player
CFishingGuideObject* FUN_1416625e0(PCBase* pPC);             // the fishing guide object of a player
MS2Ptr<AdditionalCli> FUN_14096fd30(Unk_PCBaseBuffs* pBuffs, int n);
Unk_StreamPoint FUN_140a0b080(const NiPoint3& kA, const NiPoint3& kB, const Unk_StreamPoint& kC);
void FUN_140b86230(const efd::Point3& kDir, NiMatrix3& kOut);   // rotation matrix of a direction
Unk_FsCell FUN_1408a1430(Unk_StreamPoint k);                 // the grid cell of a point
int FUN_1408a03c0(Unk_FsCell kCell);                         // the cell as a key
void FUN_140ae1160(egf::Entity* pEntity, unsigned nProp, short* pValue);   // GetProperty(short)

static inline Unk_StreamPoint FsPoint(const NiPoint3& k) { return *reinterpret_cast<const Unk_StreamPoint*>(&k); }
static inline Unk_StreamPoint FsPoint(const efd::Point3& k) { return *reinterpret_cast<const Unk_StreamPoint*>(&k); }
static inline efd::Point3 FsEfd(const Unk_StreamPoint& k) { return efd::Point3(k.x, k.y, k.z); }

// Plays an animation on the owner at the owner's speed.
static void FsPlay(PCBase* pOwner, const char* pszAnim)
{
    efd::utf8string kAnim(pszAnim);
    pOwner->FUN_14166dd20(kAnim, pOwner->FUN_1416713c0(), false, false);
}

// @0x140ddc910
// The guide object (class id 0x6200064) of an object, NULL when it is none.
static CFishingGuideObject* FUN_140ddc910(GameObject* pObject)
{
    CFishingGuideObject* pValue = 0;
    if (pObject == 0 || !pObject->TypeCast(0x6200064, (const void**)&pValue))
        pValue = 0;
    return pValue;
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
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
void StateFishing::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_nA8 = 0;
    m_n10 = 0x75;
    m_spFishingData.AssignRaw(dynamic_cast<StateFishingData*>(pData));
    if (!m_spFishingData.IsNull())
    {
        m_nRod = FUN_140ddb620();
        FUN_140ddb740(m_nRod);
        if (FUN_1417b84b0() == 0)
        {
            PCBase* pPC = FUN_1417b8370();
            if (FUN_14087ddc0(pPC ? pPC->GetClassDesc() : 0, 0x6200044))
                m_nA8 = 1;
        }
        else
        {
            m_pOwner->vfunc_22(FsEfd(DAT_143b01a60));
            FUN_140a94350()->vfunc_7(0x493e2, 0);
        }
    }
    else
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
}

// @0x140dda770
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
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
    if (m_spEffect != 0)
    {
        NiNode* pParent = FUN_140a0b000(m_spEffect);
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
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
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
            bool bEffect = m_spEffect != 0;
            if (bEffect)
            {
                if (FUN_1409f7c90()->FUN_140ddcc90() == 0)
                    FUN_140a0b300(m_spEffect, m_nB0 != 0);
            }
        }
        if (m_nA8 == 0)
        {
            CFishingGuideObject* pGuide = FUN_1416625e0(pPC);
            if (pGuide != 0)
            {
                Unk_StreamPoint kRot = FUN_140a0b080(pGuide->vfunc_18(), pPC->vfunc_18(), DAT_143a08cf8);
                pPC->FUN_14166d970(FsEfd(kRot));
                if (m_spEffect != 0)
                {
                    NiMatrix3 kMat;
                    FUN_140b86230(FsEfd(kRot), kMat);
                    m_spEffect->SetRotate(kMat);
                }
                m_nA8 = 1;
            }
        }
    }
    Unk_StreamPoint kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x140ddac60
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
void StateFishing::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    MyPC* pMy = FUN_1417b84b0();
    if (pMy == 0)
    {
        ClonePC* pClone = FUN_1405a7e30(FUN_1417b8370());
        if (pClone == 0)
            return;
        if (FUN_1417b7e40() != 0x75)
            return;
        if (eSequenceID != pkManager->GetTargetAnimation())
            return;
        m_n10 = 0x76;
        CFishingGuideObject* pGuide = FUN_1416625e0(pClone);
        if (pGuide == 0)
            return;
        pGuide->FUN_1410a4cb0();
        return;
    }
    if (FUN_1417b7e40() == 0x75)
    {
        if (eSequenceID != pkManager->GetTargetAnimation())
            return;
        m_n10 = 0x76;
        CFishingGuideObject* pGuide = FUN_1416625e0(pMy);
        if (pGuide != 0)
            pGuide->FUN_1410a4cb0();
        FsFishMgr()->FUN_140cdac50();
        return;
    }
    if (FUN_1417b7e40() != 0x79)
    {
        if (FUN_1417b7e40() != 0x77)
            return;
        if (eSequenceID != pkManager->GetTargetAnimation())
            return;
        m_n10 = 0x76;
        return;
    }
    if (eSequenceID != pkManager->GetTargetAnimation())
        return;
    m_n10 = 0x76;
    PCBase* pGuide = FUN_1416625e0(pMy);
    if (pGuide != 0)
        pGuide->FUN_14166cc40(0x7a);
    bool bLeave = true;
    if (FsFishMgr()->FUN_140ce0cb0() == 0)
    {
        MS2Ptr<AdditionalCli> spCli = FUN_14096fd30(pMy->FUN_1416749a0(), 1);
        bLeave = spCli.get() != 0;
    }
    if (bLeave)
        FsFishMgr()->SendFishingMode9();
}

// @0x140ddaf00
void StateFishing::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (FUN_1417b84b0() != 0)
    {
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
}

// @0x140ddb010
// MS2-FUNCTIONAL: the animation names are tested through a shared helper
void StateFishing::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (m_n10 == 0x75)
    {
        if (FUN_1402a5b40(m_pOwner->FUN_14166dc50(), "Fishing_Start_A") == 0)
            return;
        FsPlay(m_pOwner, "Fishing_Start_A");
        return;
    }
    if (m_n10 == 0x76)
    {
        if (FUN_1402a5b40(m_pOwner->FUN_14166dc50(), "Fishing_Idle_A") == 0)
            return;
        FsPlay(m_pOwner, "Fishing_Idle_A");
        return;
    }
    if (m_n10 != 0x77)
    {
        if (m_n10 == 0x78)
        {
            if (FUN_1402a5b40(m_pOwner->FUN_14166dc50(), "Fishing_Reel_In_A") == 0)
                return;
            FsPlay(m_pOwner, "Fishing_Reel_In_A");
            return;
        }
        if (m_n10 != 0x79)
            return;
        if (FUN_1402a5b40(m_pOwner->FUN_14166dc50(), "Fishing_End_A") == 0)
            return;
        FsPlay(m_pOwner, "Fishing_End_A");
        return;
    }
    bool bPlay = FUN_1402a5b40(m_pOwner->FUN_14166dc50(), "Fishing_Bore_A") != 0
        && FUN_1402a5b40(m_pOwner->FUN_14166dc50(), "Fishing_Bore_B") != 0;
    if (bPlay)
        FsPlay(m_pOwner, (m_nAC == 0) ? "Fishing_Bore_B" : "Fishing_Bore_A");
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
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer accessors that the source spells inline
int StateFishing::FUN_140ddb5d0()
{
    if (m_spFishingData.get() == 0)
        return 0;
    return m_spFishingData->m_nRod;
}

// @0x140ddb620
// MS2-FUNCTIONAL: the exe calls out-of-line smart pointer accessors that the source spells inline
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
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
void StateFishing::FUN_140ddb740(int nRod)
{
    MS2Ptr<CFishingRodData> spRod = CFishingTable::GetInstance()->GetRod(nRod);
    if (!spRod.IsNull())
    {
        Unk_FsPC* pPC = static_cast<Unk_FsPC*>(FUN_1417b8370());
        if (pPC != 0)
        {
            if (m_spItem.get() != 0)
            {
                pPC->vfunc_128(m_spItem.get(), 0);
                m_spItem = 0;
            }
            MS2Ptr<CItem> spNew(new CItem);
            if (spNew->FUN_140523c40(nRod, 1, 0))
            {
                spNew->FUN_140526b30(m_pOwner->FUN_14123c580());
                spNew->FUN_140526a70(FUN_14028d0e0());
                if (FUN_14087ddc0(pPC->GetClassDesc(), 0x6200044))
                    spNew->FUN_14052a130(3);
                else
                    spNew->FUN_14052a130(5);
                pPC->vfunc_127(spNew.get(), 0);
                m_spItem = spNew;
            }
        }
        if (m_spEffect != 0)
        {
            NiNode* pParent = FUN_140a0b000(m_spEffect);
            if (pParent != 0)
            {
                pParent->DetachChild(m_spEffect);
                m_spEffect = 0;
            }
        }
        if (spRod->m_strChair.GetLength() > 0)
        {
            NiAVObjectPtr spModel = FUN_140a0afd0()->FUN_141551ea0(CString(spRod->m_strChair), false, 5, 0, 0);
            m_spEffect = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, static_cast<NiObject*>(FUN_1409849b0(&spModel))));
            if (m_spEffect != 0)
            {
                NiNode* pRoot = FUN_1403ed280()->FUN_1411a6b10();
                ClonePC* pClone = FUN_1405a7e30(pPC);
                if (pClone == 0)
                    pRoot->AttachChild(m_spEffect, true);
                else
                    static_cast<AvatarPC*>(pClone)->FUN_1409f5560(m_spEffect);
                if (pRoot != 0 && pClone == 0)
                {
                    NiPoint3 kDir = m_pOwner->vfunc_20();
                    NiMatrix3 kMat;
                    FUN_140b86230(FsEfd(FsPoint(kDir)), kMat);
                    m_spEffect->SetRotate(kMat);
                    m_spEffect->SetTranslate(m_pOwner->vfunc_18());
                    m_spEffect->UpdateEffects();
                    m_spEffect->UpdateProperties();
                    m_spEffect->Update(0.0f, true);
                    m_nB0 = m_pOwner->vfunc_25();
                    if (FUN_1409f7c90()->FUN_140ddcc90() == 0 && m_nB0 != 0)
                        FUN_140a0b300(m_spEffect, 1);
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
    else
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
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
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
void StateFishingFloat::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->vfunc_63() != 0)
    {
        float* pSpeed = m_pOwner->FUN_141671920();
        efd::Point3 kDir = m_pOwner->FUN_141674b60(FsEfd(FsPoint(m_pOwner->FUN_14123c360())));
        Unk_StreamPoint kWorld = FsPoint(kDir);
        Unk_StreamPoint kStep = kWorld.FUN_14097fc90(pSpeed[2]).FUN_14097fc90((float)fTime);
        if (FUN_140ddc4b0(kWorld))
            m_pOwner->vfunc_68(&kStep, fTime, 0, 0xffffffff, 1);
    }
}

// @0x140ddc180
void StateFishingFloat::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (m_pOwner->vfunc_63() != 0 && m_n10 == 0x7a)
    {
        efd::Point3 kTarget = static_cast<Unk_PCBaseMoveTarget*>(m_pOwner->FUN_14166d240())->FUN_141683900();
        m_pOwner->vfunc_22(kTarget);
    }
}

// @0x140ddc240
void StateFishingFloat::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (m_n10 == 0x7a)
        FsPlay(m_pOwner, "float_Idle_A");
    else if (m_n10 == 0x7b)
        FsPlay(m_pOwner, "float_Fishing_A");
    else if (m_n10 == 0x7c)
        FsPlay(m_pOwner, "float_End_A");
}

// @0x140ddc3c0
Unk_FsCell StateFishingFloat::FUN_140ddc3c0(Unk_StreamPoint kPoint)
{
    Unk_StreamPoint kCorner;
    kCorner.x = (kPoint.x <= 0.0f) ? -75.0f : 75.0f;
    kCorner.y = (kPoint.y <= 0.0f) ? -75.0f : 75.0f;
    kCorner.z = 0.0f;
    return FUN_1408a1430(kPoint.FUN_14097fd50(kCorner));
}

// @0x140ddc4b0
// MS2-FUNCTIONAL: temporaries and the EH frame differ from the exe
bool StateFishingFloat::FUN_140ddc4b0(Unk_StreamPoint kDir)
{
    if (kDir.FUN_140552690(DAT_143b01a60))
        return true;
    CFishingGuideObject* pGuide = FUN_140ddc910(m_pOwner);
    if (pGuide == 0)
        return false;
    PCBase* pPC = pGuide->FUN_1410a1310();
    if (!FUN_14087ddc0(pPC ? pPC->GetClassDesc() : 0, 0x6200004))
        return true;
    Unk_StreamPoint kStart = FsPoint(m_pOwner->vfunc_18());
    kStart.FUN_140a4e560(kDir.FUN_14097fc90(30.0f));
    kStart.z = FsPoint(pPC->vfunc_18()).z + 150.0f;
    Unk_RayCastInfo kRay;
    kRay.m_origin = kStart;
    kRay.m_dir = DAT_143a08cf8.FUN_1409f7960();
    kRay.m_maxDist = 0;
    kRay.m_groups = 0x301;
    Unk_FsCell kCellA = FUN_140ddc3c0(FsPoint(m_pOwner->vfunc_18()).FUN_14097fd50(Unk_StreamPoint(0.0f, 0.0f, 5.0f)));
    if (!FUN_1409f7ca0()->CastRay(&kRay, 0))
        return false;
    if (kRay.m_hitEntity != 0)
    {
        short nType = 0;
        FUN_140ae1160(static_cast<egf::Entity*>(kRay.m_hitEntity), 0xada5c5d2, &nType);
        if (nType != 8)
            return false;
        Unk_StreamPoint kHigh = kRay.m_hitPoint.FUN_14097fd50(Unk_StreamPoint(0.0f, 0.0f, 55.0f));
        Unk_FsCell kCellB = FUN_140ddc3c0(kHigh);
        Unk_FsCell kCellC = FUN_140ddc3c0(kRay.m_hitPoint);
        MS2Ptr<Unk_FishPacket> spPacket = FsFishMgr()->FUN_140cdbb10(FUN_1408a03c0(kCellC));
        if (spPacket.IsNull())
            return false;
        if (kCellA.z != kCellB.z)
            m_pOwner->vfunc_19(FsEfd(kHigh));
    }
    return true;
}

// @0x140ddcc70
int StateFishingFloat::vfunc_1()
{
    return 0x2e;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca5c60-0x142ca5c90 .text$yd
