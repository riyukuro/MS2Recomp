// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). AdditionalCliList (additionalclilist.h): the actor's
// additional effect list at PCBase+0x748 - add / modify / remove packets, the per-frame update that drops finished
// records, the sums of the active records (status, motion, consume, special abilities, super armor, shield), the buff
// UIs, the stun state, the invoke effect options and the special effects - plus SAInvokeEffectStat and this part's
// COMDATs. The first part of the unit (AdditionalCli) is additionalcli_1.cpp.
// MS2-UNIT: ?\additionalcli.cpp#2
// MS2-RANGE: 0x14096ee00-0x140978f40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAA@II@Z 0x1409754a0 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@IEAA@I@Z 0x140975530 ; prop
// MS2-PIN: ??1?$MS2Ptr@VUnk_PCBaseComp_a98@@@@QEAA@XZ 0x1409757a0 ; prop
// MS2-PIN: ??1CNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAA@XZ 0x1409757f0 ; prop
// MS2-PIN: ??1CPair@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAA@XZ 0x140975830 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VInvokeEffectOption@@@@QEAAAEAV1@PEAVInvokeEffectOption@@@Z 0x1409759f0 ; prop
// MS2-PIN: ??4?$MS2Ptr@VSAInvokeEffectStat@@@@QEAAAEAV0@AEBV0@@Z 0x140975a60 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VSAInvokeEffectStat@@@@QEAAAEAV1@PEAVSAInvokeEffectStat@@@Z 0x140975aa0 ; prop
// MS2-PIN: ??C?$SmartPointer@VRidee@@@efd@@QEBAPEAVRidee@@XZ 0x140975bc0 ; prop
// MS2-PIN: ??_GCNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAAPEAXI@Z 0x140975c80 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140975f60 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x140976180 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEAAXXZ 0x140976320 ; prop
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEBAIXZ 0x140976540 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x140976650 ; prop
// MS2-PIN: ?InitHashTable@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAA_NI_N@Z 0x1409769c0 ; prop
// MS2-PIN: ?IsLocked@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEBA_NXZ 0x140976c40 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEBA_NIAEAV?$MS2Ptr@VSAInvokeEffectStat@@@@@Z 0x140976dc0 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140977040 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEBAI_K@Z 0x1409774b0 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAAXI@Z 0x140977dd0 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1409782e0 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140978420 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VSAInvokeEffectStat@@@@@Z 0x140978670 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$MS2Ptr@VSAInvokeEffectStat@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSAInvokeEffectStat@@@@@3@@ATL@@AEAAXXZ 0x140978b00 ; prop
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_PCBaseComp_a98@@@@CAXPEAVUnk_PCBaseComp_a98@@@Z 0x140978c80 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_PCBaseComp_a98@@@@AEAAXXZ 0x140978d80 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_PCBaseComp_a98@@@@AEAAXPEAX@Z 0x140978e60 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??_GSAInvokeEffectStat@@UEAAPEAXI@Z 0x140975d00
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\additionalcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <set>
#include <efd/IBase.h>
#include <efd/SmartPointer.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/portraitpc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/client/ms2/uiupperhpbar.h"
#include "ms2/client/ms2/uinpcduelhpbardialog.h"
#include "ms2/client/ms2/uishieldbar.h"
#include "ms2/unnamed/unit_14128e7f0.h"
#include "ms2/client/ms2/costumemanager.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/stateskill.h"
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/commonfiles/skillattackdata.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/cspecialeffectctx.h"
#include "ms2/commonfiles/specialeffectfunctionmanager.h"
#include "ms2/ms2recover.h"

// The shield bar entity behind PCBase vfunc_81 and the buff balloon entity behind vfunc_84.
class Unk_PCBaseComp_a68 : public UIShieldBar::Entity {};
class Unk_PCBaseComp_a98 : public UIBuffBalloon::Entity {};

// The buff UIs take the record by value (the callee destroys the copy).
class Unk_AclUpperBar : public UIUpperHpBar
{
public:
    void FUN_141b4cf40(MS2Ptr<AdditionalCli> sp);           // add a buff icon
    void FUN_141b4d060(PCBase* pActor, int nKey);           // remove a buff icon
};
class Unk_AclDuelBar : public UINpcDuelHPBarDialog
{
public:
    void FUN_140e6c440(MS2Ptr<AdditionalCli> sp);           // add a buff icon
};
class Unk_AclMainInfo : public UIMainPlayerInfo
{
public:
    void FUN_1419f0fe0(MS2Ptr<AdditionalCli> sp);           // add a buff icon
};
// The shield buff HUD (unnamed/unit_140c5d230.h; that header's UIEntityEventListener clashes with uiupperhpbar.h's,
// so the class is declared here with the same bases for the dynamic_cast of Unk_AcFindUI).
class UILapenshardShieldBar : public UIHeadUpDisplay, public UIEntityEventListener
{
public:
    void FUN_140c5f8f0(MS2Ptr<AdditionalCli> sp);           // show the shield record
};
// The skill table (SkillDataTableCli; placeholder/skilldatatablecli.h clashes with commonfiles/skilloverlapcompare.h).
class Unk_AclSkillTable : public SkillDataTable
{
public:
    const std::set<unsigned>* FUN_140aaffb0(unsigned nGroup);   // the effects of an additional effect group
};
// The current field data.
// the caller tests the result as an int (no movzx); the definition in additionalactionadditional.cpp returns bool
class Unk_AclInvokeEffect : public AdditionalLevelData::InvokeEffectProperty
{
public:
    int FUN_140192ac0();
};

// the exe passes the entity id by value here (the callee's own header takes it by reference; same ABI)
class Unk_AclEffect : public CEffectService
{
public:
    void FUN_1411a6f00(egf::EntityID id);
};

class Unk_AclWorld : public WorldService
{
public:
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();
};

bool FUN_140930110(int nObjectId);                          // 0x140930110 the object is the local player
UIMainPlayerInfo* FUN_140931900(int nClass);                // 0x140931900 the main player info dialog
int FUN_141092ff0(PCBase* pNpc);                            // 0x141092ff0 the npc shows an upper hp bar
bool FUN_14028d470(float a, float b);                       // 0x14028d470 nearly equal
__int64 FUN_140632990(__int64 nValue, float fRate);         // 0x140632990 scale and round
float FUN_140768090();                                      // 0x140768090 random [0, 1)
int FUN_14081d8a0(int nType);                               // 0x14081d8a0 the stat option applies to skills
int FUN_14081d8e0(int nType);                               // 0x14081d8e0 the stat option applies to effects
void FUN_1419f37f0(int nEvent);                             // 0x1419f37f0 notify the skill UIs
Unk_AclSkillTable* FUN_1401958b0();                         // 0x1401958b0 the skill table

// A UI object by class id, cast to its class.
template <class T> T* Unk_AcFindUI(eUIClassID nId)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// The overlap count test of FUN_14096fe60 (0: the count does not pass).
// @0x140975ed0
inline int FUN_140975ed0(int nCompare, unsigned nCount, unsigned nOverlap)
{
    if (nCompare == 1)
    {
        if (nCount != nOverlap)
            return 0;
    }
    else if (nCompare == 2)
    {
        if (nCount <= nOverlap)
            return 0;
    }
    else if (nCompare == 3)
    {
        if (nCount < nOverlap)
            return 0;
    }
    else if (nCompare == 4)
    {
        if (nCount >= nOverlap)
            return 0;
    }
    else if (nCompare == 5)
    {
        if (nCount > nOverlap)
            return 0;
    }
    else
        return 0;
    return 1;
}

// @0x14096ef20
AdditionalCliList::AdditionalCliList(PCBase* pOwner)
    : m_map(10), m_pOwner(pOwner), m_fAlpha(1.0f), m_nSkillUseDisable(0), m_bDirty(0), m_spShield(0)
{
    FUN_140973520();
}

// @0x14096f000
AdditionalCliList::~AdditionalCliList()
{
    FUN_140970490();
}

// @0x14096f070
int AdditionalCliList::FUN_14096f070(MS2Ptr<AdditionalCli> sp)
{
    if (!sp->FUN_14096c6f0())
        return 0;
    if (m_map.Lookup(sp->FUN_14096d260()))
        return 0;
    m_map.SetAt(sp->FUN_14096d260(), sp);
    if (FUN_1409735c0())
        sp->FUN_14096c3f0();
    sp->FUN_14096c4c0();
    FUN_140973950(sp);
    FUN_140973f40(sp);
    if (PC* pPC = efd::DynamicCast<PC>(m_pOwner))
    {
        pPC->FUN_1416561a0()->FUN_1411e7640();
        if (sp->FUN_14096d810()->m_nCostumeSetID)
            pPC->FUN_1409763e0()->FUN_140b1d360(sp->FUN_14096d810()->m_nCostumeSetID);
        if (sp->FUN_14096d810()->m_nTailEffect)
            pPC->FUN_141663ef0(sp);
    }
    if (MyPC* pMy = FUN_140973920())
    {
        const unsigned& nSet = sp->FUN_14096d810()->m_nSkillSetID;
        if (nSet)
        {
            pMy->FUN_141523bc0()->FUN_141767f80(nSet);
            pMy->FUN_141523bc0()->FUN_1417683d0();
        }
        CGuildManager::GetInstance()->FUN_1413bce40(sp->FUN_14096d2a0(), sp->FUN_14096d2c0());
        int nEvent = 0xd;
        FUN_1419f37f0(nEvent);
    }
    if (sp->FUN_14096d810()->m_shield.m_eUIType)
    {
        m_spShield = sp;
        UIUpperHpBar* pBar = Unk_AcFindUI<UIUpperHpBar>((eUIClassID)20029);
        if (pBar)
        {
            UpperHpBarEntity* pEntity = pBar->FUN_140976440();
            if (pEntity && pEntity->FUN_141b4bbe0() == m_pOwner->FUN_14123c580())
            {
                UILapenshardShieldBar* pShield = Unk_AcFindUI<UILapenshardShieldBar>((eUIClassID)0x4f73);
                if (pShield)
                    pShield->FUN_140c5f8f0(m_spShield);
            }
        }
    }
    FUN_1409725d0();
    return 1;
}

// @0x14096f500
void AdditionalCliList::FUN_14096f500(int nKey, int nCaster)
{
    MS2Ptr<AdditionalCli> sp;
    if (!m_map.Lookup(nKey, sp))
        return;
    sp->FUN_14096c650(nCaster);
    FUN_140973cc0(sp);
    FUN_140974090(sp);
    m_map.RemoveKey(nKey);
    FUN_140974130(sp);
    if (PC* pPC = efd::DynamicCast<PC>(m_pOwner))
    {
        pPC->FUN_1416561a0()->FUN_1411e7640();
        if (sp->FUN_14096d810()->m_nCostumeSetID)
            pPC->FUN_1409763e0()->FUN_140b1d890(sp->FUN_14096d810()->m_nCostumeSetID);
        if (sp->FUN_14096d810()->m_nTailEffect)
            pPC->FUN_141664160(sp);
    }
    if (MyPC* pMy = FUN_140973920())
    {
        const unsigned& nSet = sp->FUN_14096d810()->m_nSkillSetID;
        if (nSet)
        {
            pMy->FUN_141523bc0()->FUN_141768100(nSet);
            pMy->FUN_141523bc0()->FUN_1417683d0();
        }
        int nEvent = 0xd;
        FUN_1419f37f0(nEvent);
    }
    if (sp->FUN_14096d810()->m_shield.m_eUIType)
    {
        if (m_spShield == sp)
            m_spShield = 0;
    }
    FUN_1409725d0();
}

// @0x14096f820
MS2Ptr<AdditionalCli> AdditionalCliList::FUN_14096f820(const Unk_AdditionalOwner& owner, CInPacket& packet)
{
    unsigned nFlags = packet.vfunc_o8_3();
    MS2Ptr<AdditionalCli> sp(0);
    if (!m_map.Lookup(owner.m_n4, sp) && (nFlags & 1))
        sp.AssignRaw(new AdditionalCli);
    if (sp == 0)
        return MS2Ptr<AdditionalCli>(0);
    sp->FUN_14096bf40(m_pOwner, nFlags, owner, packet);
    if (!sp->FUN_14096c6f0())
        return MS2Ptr<AdditionalCli>(0);
    if (nFlags & 1)
    {
        sp->FUN_14096c4c0();
        sp->FUN_14096d430();
        if (PC* pPC = efd::DynamicCast<PC>(m_pOwner))
        {
            if (sp->FUN_14096d810()->m_nTailEffect)
                pPC->FUN_1416640d0(sp);
            pPC->FUN_1416561a0()->FUN_1411e7640();
        }
        if (FUN_1409735c0())
        {
            CGuildManager::GetInstance()->FUN_1413bce40(sp->FUN_14096d2a0(), sp->FUN_14096d2c0());
            int nEvent = 0xd;
            FUN_1419f37f0(nEvent);
        }
        FUN_1409725d0();
    }
    return sp;
}

// @0x14096fb20
void AdditionalCliList::FUN_14096fb20(int nEvent)
{
    if (FUN_140973640())
        return;
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (!sp->m_bEnabled)
            continue;
        if (sp->FUN_14096d810()->m_nInvokeEvent == nEvent)
            sp->FUN_14096cec0();
    }
}

// @0x14096fc00
void AdditionalCliList::FUN_14096fc00(int nKey)
{
    if (FUN_140973640())
        return;
    MS2Ptr<AdditionalCli> sp;
    if (m_map.Lookup(nKey, sp))
        sp->FUN_14096cec0();
}

// @0x14096fc80
MS2Ptr<AdditionalCli> AdditionalCliList::FUN_14096fc80(int nKey)
{
    MS2Ptr<AdditionalCli> sp(0);
    if (m_map.Lookup(nKey, sp))
        return sp;
    return MS2Ptr<AdditionalCli>(0);
}

// @0x14096fd30
MS2Ptr<AdditionalCli> AdditionalCliList::FUN_14096fd30(int nType)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (!sp->m_bEnabled)
            continue;
        if (sp->FUN_14096d810()->m_nEventBuffType == nType)
            return sp;
    }
    return MS2Ptr<AdditionalCli>(0);
}

// @0x14096fe60
MS2Ptr<AdditionalCli> AdditionalCliList::FUN_14096fe60(unsigned nId, unsigned short nLevel, unsigned nCount, bool bAll,
                                                       int nCompare)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (!bAll && !sp->m_bEnabled)
            continue;
        if (sp->FUN_14096d2a0() != nId)
            continue;
        if (nLevel && sp->FUN_14096d2c0() != nLevel)
            continue;
        if (nCount && FUN_140975ed0(nCompare, nCount, sp->m_nOverlapCount) == 0)
            continue;
        return sp;
    }
    return MS2Ptr<AdditionalCli>(0);
}

// @0x140970020
int AdditionalCliList::FUN_140970020(unsigned nId, unsigned short nLevel, unsigned nCount, int nCompare)
{
    if (FUN_14096fe60(nId, nLevel, nCount, false, nCompare) == 0)
        return 0;
    return 1;
}

// @0x1409700d0
int AdditionalCliList::FUN_1409700d0(int nType)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (!sp->m_bEnabled)
            continue;
        if (sp->FUN_14096d810()->GetMainType() == nType)
            return 1;
    }
    return 0;
}

// @0x1409701d0
int AdditionalCliList::FUN_1409701d0(int nType)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (!sp->m_bEnabled)
            continue;
        if (sp->FUN_14096d810()->m_nEventBuffType == nType)
            return 1;
    }
    return 0;
}

// @0x1409702d0
int AdditionalCliList::FUN_1409702d0(int nGroup)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (!sp->m_bEnabled)
            continue;
        if (sp->FUN_14096d810()->GetGroup() == nGroup)
            return 1;
    }
    return 0;
}

// @0x1409703d0
bool AdditionalCliList::FUN_1409703d0(int nSlot)
{
    if (nSlot == 0)
        return false;
    return m_nItemSlotDisable == nSlot;
}

// @0x140970420
void AdditionalCliList::FUN_140970420(double dTime)
{
    FUN_1409728b0();
    if (m_bDirty)
        FUN_140972a00();
    FUN_1409713b0();
    FUN_140972770();
    FUN_1409733f0();
    FUN_140973450();
    FUN_1409734b0();
}

// @0x140970490
void AdditionalCliList::FUN_140970490()
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        sp->FUN_14096ce50();
        FUN_140973cc0(sp);
        FUN_140974090(sp);
    }
    m_map.RemoveAll();
    m_spShield = 0;
    FUN_1409725d0();
}

// @0x1409705d0
float AdditionalCliList::FUN_1409705d0()
{
    for (POSITION pos = m_map.GetTailPosition(); pos != 0; m_map.GetPrev(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (!sp->m_bEnabled)
            continue;
        if (0.0f != sp->FUN_14096d810()->m_motion.m_fScale)
            return 1.0f + sp->FUN_14096d810()->m_motion.m_fScale * sp->m_nOverlapCount;
    }
    return 1.0f;
}

// @0x140970700
float AdditionalCliList::FUN_140970700()
{
    return m_fAlpha;
}

// @0x140970720
float AdditionalCliList::FUN_140970720()
{
    float fAlpha = m_motion.m_fAlphaBlending;
    if (!FUN_14028d470(m_motion.m_fAlphaBlending, 1.0f))
    {
        PC* pPC = efd::DynamicCast<PC>(m_pOwner);
        PC* pLocal = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPC && pLocal && pPC != pLocal)
        {
            if (FUN_140970990())
            {
                if (pPC->vfunc_122(pLocal))
                    fAlpha = 0.0f;
                else if (pPC->FUN_140967420()->FUN_140743550())
                    fAlpha = 0.0f;
            }
        }
    }
    if (FUN_14028d470(0.0f, fAlpha))
        m_pOwner->vfunc_31(false);
    else
        m_pOwner->vfunc_31(true);
    return fAlpha;
}

// @0x1409708a0
__int64 AdditionalCliList::FUN_1409708a0()
{
    __int64 nSum = 0;
    for (POSITION pos = m_map.GetTailPosition(); pos != 0; m_map.GetPrev(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp->m_nShieldValue == 0)
            continue;
        if (!sp->m_bEnabled)
            continue;
        nSum += sp->m_nShieldValue;
    }
    return nSum;
}

// @0x140970990
int AdditionalCliList::FUN_140970990()
{
    return m_motion.m_nHide;
}

// @0x1409709b0
unsigned AdditionalCliList::FUN_1409709b0()
{
    return m_motion.m_nStun;
}

// @0x1409709d0
int AdditionalCliList::FUN_1409709d0()
{
    if (FUN_1409709b0() != 0)
        return 1;
    return 0;
}

// @0x140970a00
int AdditionalCliList::FUN_140970a00()
{
    return m_motion.m_nNoFly;
}

// @0x140970a20
bool AdditionalCliList::FUN_140970a20()
{
    return m_bPvpOnOff;
}

// @0x140970a40
int AdditionalCliList::FUN_140970a40()
{
    return m_motion.m_nConfusionMove;
}

// @0x140970a60
int AdditionalCliList::FUN_140970a60(unsigned nSkillId)
{
    return m_motion.m_setSkillUseDisableIDs.find(nSkillId) != m_motion.m_setSkillUseDisableIDs.end();
}

// @0x140970ad0
bool AdditionalCliList::FUN_140970ad0()
{
    return m_bDisableRevivalHere;
}

// @0x140970af0
int AdditionalCliList::FUN_140970af0()
{
    return m_nInvincible;
}

// @0x140970b10
int AdditionalCliList::FUN_140970b10()
{
    return m_nForceApplyTarget;
}

// @0x140970b30
unsigned AdditionalCliList::FUN_140970b30()
{
    unsigned nValue = 0;
    if (m_pOwner->FUN_14166c930() == 0x10)
    {
        StateSkill* pState = static_cast<StateSkill*>(m_pOwner->FUN_14166ccb0());
        if (pState)
        {
            MS2Ptr<CSkillRecord> spRecord = pState->FUN_1417ed6f0();
            if (spRecord.get())
                nValue = spRecord->FUN_14175a210();
        }
    }
    return nValue > m_motion.m_nSuperArmor ? nValue : m_motion.m_nSuperArmor;
}

// @0x140970bf0
unsigned AdditionalCliList::FUN_140970bf0()
{
    return m_motion.m_nSkillUseDisable;
}

// @0x140970c10
int AdditionalCliList::FUN_140970c10(SkillAttackData* pAttack, int nPush)
{
    if (PC* pPC = efd::DynamicCast<PC>(m_pOwner))
    {
        if (pPC->FUN_140976c10())
            return 1;
    }
    if (!pAttack)
        return 0;
    if (pAttack->m_damage.m_nSuperArmorBreak)
        return 0;
    unsigned nArmor = FUN_140970b30();
    int nFieldId = WorldService::GetInstance()->FUN_141bd3060();
    SkillPushType ePush = pAttack->m_damage.GetPush(nFieldId);
    switch (nArmor)
    {
    case 1:
        if (ePush)
            return 0;
        if (pAttack->m_eGrabTargetType == 1)
            return 0;
        return 1;
    case 2:
        if (ePush && !FUN_14028d470(pAttack->m_damage.m_fPushUpDistance, 0.0f))
            return 0;
        if (pAttack->m_eGrabTargetType == 1)
            return 0;
        return 1;
    case 3:
        return 1;
    case 4:
        if (nPush)
            return 0;
        if (pAttack->m_eGrabTargetType == 1)
            return 0;
        return 1;
    }
    return 0;
}

// @0x140970d70
bool AdditionalCliList::FUN_140970d70()
{
    return m_bInfinitySP;
}

// @0x140970d90
unsigned AdditionalCliList::FUN_140970d90(unsigned nId, unsigned short nLevel)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp == 0)
            continue;
        if (sp->FUN_14096d2a0() != nId)
            continue;
        if (nLevel && sp->FUN_14096d2c0() != nLevel)
            continue;
        return sp->m_nOverlapCount;
    }
    return 0;
}

// @0x140970eb0
int AdditionalCliList::FUN_140970eb0(float& fOut)
{
    if (0.0f == m_motion.m_fFixedZRotation)
        return 0;
    fOut = m_motion.m_fFixedZRotation;
    return 1;
}

// @0x140970f00
__int64 AdditionalCliList::FUN_140970f00(int nType, __int64 nValue)
{
    if (nType != 4 && nType != 7)
        return nValue;
    __int64 nFlat = 0;
    float fRate = 0.0f;
    if (nType == 4)
        fRate = m_consume.m_fHpRate;
    else if (nType == 7)
        fRate = m_consume.m_fSpRate;
    return FUN_140632990(nValue + nFlat, 1.0f + fRate);
}

// @0x140970fb0
float AdditionalCliList::FUN_140970fb0()
{
    return m_consume.m_fSpConsumeChangeHpRate;
}

// @0x140970fd0
float AdditionalCliList::FUN_140970fd0()
{
    return m_consume.m_fSpRate;
}

// @0x140970ff0
void AdditionalCliList::FUN_140970ff0(CInPacket& packet)
{
    int nCount = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < nCount; i++)
    {
        Unk_AdditionalOwner owner;
        owner.Decode(packet);
        MS2Ptr<AdditionalCli> sp(new AdditionalCli);
        sp->FUN_14096be10(m_pOwner, owner, packet);
        sp->m_b40 = 1;
        FUN_14096f070(sp);
    }
}

// @0x140971150
void AdditionalCliList::FUN_140971150()
{
    float fAlpha = FUN_140970720();
    if (!FUN_14028d470(fAlpha, 1.0f))
        m_pOwner->vfunc_42(fAlpha, true);
}

// @0x1409711c0
unsigned AdditionalCliList::FUN_1409711c0()
{
    unsigned nGroups = 0;
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        const MS2Ptr<AdditionalCli>& sp = m_map.GetValueAt(pos);
        if (!sp->m_bEnabled)
            continue;
        nGroups |= sp->FUN_14096d810()->m_motion.m_nIgnoreCollisionGroups;
    }
    return nGroups;
}

// @0x140971260
int AdditionalCliList::FUN_140971260(int nId)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        AdditionalCli* p = m_map.GetValueAt(pos);
        if (!p->m_bEnabled)
            continue;
        if (p->FUN_14096d810()->GetID() == nId)
            return 1;
    }
    return 0;
}

// @0x140971300
int AdditionalCliList::FUN_140971300(int nId, int nCaster)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        AdditionalCli* p = m_map.GetValueAt(pos);
        if (!p->m_bEnabled)
            continue;
        if (p->FUN_14096d810()->GetID() == nId && p->m_nCasterId == nCaster)
            return 1;
    }
    return 0;
}

// @0x1409713b0
void AdditionalCliList::FUN_1409713b0()
{
    if (FUN_140973640())
        return;
    if (m_pOwner->FUN_141670a00(4) == 0)
        return;
    State* pState = m_pOwner->FUN_14166ccb0();
    if (!pState->vfunc_17())
        return;
    PC* pPC = efd::DynamicCast<PC>(m_pOwner);
    if (pPC && pPC->FUN_141660120())
        return;
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (!sp->m_bEnabled)
            continue;
        int nStun = sp->FUN_14096d810()->m_motion.m_nStun;
        if (nStun)
        {
            int nFlags = 0x40;
            if (nStun == 2 || nStun == 6)
            {
                if (efd::DynamicCast<PC>(m_pOwner))
                {
                    if (sp->m_b40)
                        nFlags = 0x3e;
                    else
                        nFlags = 0x3d;
                }
            }
            else if (nStun == 3)
                nFlags = 0x41;
            else if (nStun == 4)
                nFlags = 0x42;
            else if (nStun == 5)
                nFlags = 0x43;
            else if (nStun == 7)
                nFlags = 0x44;
            else if (nStun == 8)
                nFlags = 0x45;
            else if (nStun == 99)
                nFlags = 0x46;
            m_motion.m_nStun = nStun;
            m_motion.m_strStunAnimation = sp->FUN_14096d810()->m_motion.m_strStunAnimation;
            m_pOwner->vfunc_59(0x12, new StateStunData(nStun), nFlags, 0);
            return;
        }
    }
}

// @0x1409716a0
CString AdditionalCliList::FUN_1409716a0()
{
    return m_motion.m_strStunAnimation;
}

// @0x1409716f0
int AdditionalCliList::FUN_1409716f0(SAType eType)
{
    return m_status.m_mapSA[eType];
}

// The invoke effect options of the active records, per skill (skills) and per additional effect (effects).
// @0x140971720
void AdditionalCliList::FUN_140971720(StatMap& skills, StatMap& effects)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (!sp->m_bEnabled)
            continue;
        if (!sp->FUN_14096d050())
            continue;
        if (!static_cast<Unk_AclInvokeEffect&>(sp->FUN_14096d810()->m_invokeEffect).FUN_140192ac0())
            continue;
        for (unsigned i = 0; i < sp->FUN_14096d810()->m_invokeEffect.m_vTypes.size(); ++i)
        {
            Unk_InvokeOptionType nType = (Unk_InvokeOptionType)sp->FUN_14096d810()->m_invokeEffect.m_vTypes[i];
            ATL::CAtlArray<MS2Ptr<SAInvokeEffectStat> > stats;
            if (sp->FUN_14096d810()->m_invokeEffect.m_nSkillID)
            {
                if (FUN_14081d8a0(nType) == 0)
                    continue;
                MS2Ptr<SAInvokeEffectStat> spStat(0);
                if (!skills.Lookup(sp->FUN_14096d810()->m_invokeEffect.m_nSkillID, spStat))
                {
                    spStat.AssignRaw(new SAInvokeEffectStat);
                    skills.SetAt(sp->FUN_14096d810()->m_invokeEffect.m_nSkillID, spStat);
                }
                stats.Add(spStat);
            }
            else if (sp->FUN_14096d810()->m_invokeEffect.m_nEffectID)
            {
                if (FUN_14081d8e0(nType) == 0)
                    continue;
                MS2Ptr<SAInvokeEffectStat> spStat(0);
                if (!effects.Lookup(sp->FUN_14096d810()->m_invokeEffect.m_nEffectID, spStat))
                {
                    spStat.AssignRaw(new SAInvokeEffectStat);
                    effects.SetAt(sp->FUN_14096d810()->m_invokeEffect.m_nEffectID, spStat);
                }
                stats.Add(spStat);
            }
            else if (sp->FUN_14096d810()->m_invokeEffect.m_nSkillGroupID)
            {
                if (FUN_14081d8a0(nType) == 0)
                    continue;
                std::set<unsigned>* pGroup =
                    FUN_1401958b0()->GetGroupSkills(sp->FUN_14096d810()->m_invokeEffect.m_nSkillGroupID);
                if (!pGroup)
                    continue;
                for (unsigned nId : *pGroup)
                {
                    MS2Ptr<SAInvokeEffectStat> spStat(0);
                    if (!skills.Lookup(nId, spStat))
                    {
                        spStat.AssignRaw(new SAInvokeEffectStat);
                        skills.SetAt(nId, spStat);
                    }
                    stats.Add(spStat);
                }
            }
            else if (sp->FUN_14096d810()->m_invokeEffect.m_nEffectGroupID)
            {
                if (FUN_14081d8e0(nType) == 0)
                    continue;
                const std::set<unsigned>* pGroup =
                    FUN_1401958b0()->FUN_140aaffb0(sp->FUN_14096d810()->m_invokeEffect.m_nEffectGroupID);
                if (!pGroup)
                    continue;
                for (unsigned nId : *pGroup)
                {
                    MS2Ptr<SAInvokeEffectStat> spStat(0);
                    if (!effects.Lookup(nId, spStat))
                    {
                        spStat.AssignRaw(new SAInvokeEffectStat);
                        effects.SetAt(nId, spStat);
                    }
                    stats.Add(spStat);
                }
            }
            if (stats.IsEmpty())
                continue;
            for (unsigned j = 0; j < stats.GetCount(); ++j)
            {
                MS2Ptr<SAInvokeEffectStat> spStat = stats.GetAt(j);
                MS2Ptr<InvokeEffectOption> spOption;
                if (!spStat->m_18.Lookup(nType, spOption))
                {
                    spOption.AssignRaw(new InvokeEffectOption);
                    spOption->m_nA = nType;
                    spOption->FUN_140267330(sp->FUN_14096d810()->m_invokeEffect.m_vValues[i] * sp->m_nOverlapCount);
                    spOption->FUN_140267300(sp->FUN_14096d810()->m_invokeEffect.m_vRates[i] * sp->m_nOverlapCount);
                    spStat->m_18.SetAt(nType, spOption);
                }
                else
                {
                    MS2Ptr<InvokeEffectOption> spOther(new InvokeEffectOption);
                    spOther->m_nA = nType;
                    spOther->FUN_140267330(sp->FUN_14096d810()->m_invokeEffect.m_vValues[i] * sp->m_nOverlapCount);
                    spOther->FUN_140267300(sp->FUN_14096d810()->m_invokeEffect.m_vRates[i] * sp->m_nOverlapCount);
                    spOption->FUN_140267220(spOther);
                }
            }
        }
    }
}

// @0x140972380
void AdditionalCliList::FUN_140972380(CSpecialEffectCtx* pCtx)
{
    if (!FUN_140973920())
        return;
    if (!pCtx)
        return;
    MS2Ptr<CSpecialEffectFunction> spFn = CSpecialEffectFunctionManager::GetInstance()->Find(pCtx->m_nKind);
    if (spFn == 0)
        return;
    ATL::CAtlList<MS2Ptr<AdditionalCli> > list(10);
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (!sp->m_bEnabled)
            continue;
        if (!sp->FUN_14096d050())
            continue;
        if (sp->FUN_14096d810()->m_specialEffect.m_eType != pCtx->m_nKind)
            continue;
        if (sp->FUN_14096d810()->m_specialEffect.m_fProbability < FUN_140768090())
            continue;
        reinterpret_cast<MS2Ptr<CXmlData>&>(pCtx->m_pParam) = sp->FUN_14096d810()->m_specialEffect.m_xml;
        if (!spFn->vfunc_1(pCtx))
            continue;
        pCtx->m_n30++;
    }
}

// @0x1409725d0
void AdditionalCliList::FUN_1409725d0()
{
    m_bDirty = 1;
}

// @0x1409725f0
void AdditionalCliList::FUN_1409725f0(ATL::CAtlList<MS2Ptr<AdditionalCli> >& list)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (sp)
            list.AddTail(sp);
    }
}

// @0x140972690
MS2Ptr<AdditionalCli> AdditionalCliList::FUN_140972690()
{
    return m_spShield;
}

// @0x1409726e0
int AdditionalCliList::FUN_1409726e0(unsigned nSuperArmor, ApplyFieldType eField)
{
    if (!nSuperArmor)
        return 0;
    if (!eField)
        return 1;
    int bField = CFieldData::FUN_1403744a0(WorldService::GetInstance()->FUN_141bd3060());
    return (eField == 2) == bField;
}

// @0x140972770
void AdditionalCliList::FUN_140972770()
{
    if (FUN_140973640())
        return;
    if ((FUN_1409735c0() || FUN_140973600()) && m_pOwner->FUN_14166ce30())
        return;
    float fAlpha = FUN_140970720();
    if (fAlpha != m_fAlpha)
    {
        m_fAlpha = fAlpha;
        if (FUN_14028d470(m_fAlpha, 0.0f))
            m_pOwner->FUN_14166ca20(3);
        else
        {
            static_cast<Unk_AclEffect*>(CEffectService::GetInstance())->FUN_1411a6f00(m_pOwner->FUN_14123c460());
            m_pOwner->FUN_14166ca80(3);
            m_pOwner->vfunc_42(fAlpha, true);
        }
    }
}

// @0x1409728b0
void AdditionalCliList::FUN_1409728b0()
{
    ATL::CAtlList<MS2Ptr<AdditionalCli> > list(10);
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli>& sp = m_map.GetValueAt(pos);
        sp->FUN_14096c520();
        if (sp->m_b44)
            list.AddTail(sp);
    }
    for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = list.GetAt(pos);
        FUN_14096f500(sp->FUN_14096d260(), sp->m_nCasterId);
    }
}

// @0x140972a00
void AdditionalCliList::FUN_140972a00()
{
    FUN_140973520();
    for (POSITION pos = m_map.GetHeadPosition(); pos != 0; m_map.GetNext(pos))
    {
        MS2Ptr<AdditionalCli> sp = m_map.GetValueAt(pos);
        if (!sp->m_bEnabled)
            continue;
        if (sp->m_bSuspended)
            continue;
        if (!FUN_14028d470(sp->FUN_14096d810()->m_motion.m_fAlphaBlending, 1.0f))
            m_motion.m_fAlphaBlending = sp->FUN_14096d810()->m_motion.m_fAlphaBlending;
        if (sp->FUN_14096d810()->m_motion.m_nHide)
            m_motion.m_nHide = 1;
        if (sp->FUN_14096d810()->m_motion.m_nNoFly)
            m_motion.m_nNoFly = 1;
        if (sp->FUN_14096d810()->m_nInvincible)
            m_nInvincible = sp->FUN_14096d810()->m_nInvincible;
        unsigned nArmor = sp->FUN_14096d810()->m_motion.m_nSuperArmor;
        if (FUN_1409726e0(nArmor, sp->FUN_14096d810()->m_motion.m_eSuperArmorApplyFieldType) &&
            nArmor > m_motion.m_nSuperArmor)
            m_motion.m_nSuperArmor = nArmor;
        if (sp->FUN_14096d810()->m_bPvpOnOff)
            m_bPvpOnOff = true;
        int nPitch = sp->FUN_14096d810()->m_motion.m_nSoundPitch;
        if (nPitch)
            m_motion.m_nSoundPitch = nPitch;
        unsigned nDisable = sp->FUN_14096d810()->m_motion.m_nSkillUseDisable;
        if (nDisable)
            m_motion.m_nSkillUseDisable |= nDisable;
        const std::set<unsigned>& ids = sp->FUN_14096d810()->m_motion.m_setSkillUseDisableIDs;
        if (!ids.empty())
            m_motion.m_setSkillUseDisableIDs.insert(ids.begin(), ids.end());
        if (sp->FUN_14096d810()->m_ui.m_bInfinitySP)
            m_bInfinitySP = true;
        if (sp->FUN_14096d810()->m_motion.m_nConfusionMove)
            m_motion.m_nConfusionMove = 1;
        if (sp->FUN_14096d810()->m_nForceApplyTarget)
            m_nForceApplyTarget |= sp->FUN_14096d810()->m_nForceApplyTarget;
        if (0.0f < sp->FUN_14096d810()->m_motion.m_fFixedZRotation)
            m_motion.m_fFixedZRotation = sp->FUN_14096d810()->m_motion.m_fFixedZRotation;
        if (sp->FUN_14096d810()->m_bDisableRevivalHere)
            m_bDisableRevivalHere = true;
        m_status.m_nDeathResistanceHP = m_status.m_nDeathResistanceHP > sp->FUN_14096d810()->m_status.m_nDeathResistanceHP
                                            ? m_status.m_nDeathResistanceHP
                                            : sp->FUN_14096d810()->m_status.m_nDeathResistanceHP;
        if (sp->FUN_14096d810()->m_nItemSlotDisable)
            m_nItemSlotDisable = sp->FUN_14096d810()->m_nItemSlotDisable;
        if (sp->FUN_14096d050())
        {
            for (auto v : sp->FUN_14096d810()->m_status.m_mapSA)
                m_status.m_mapSA[v.first] += v.second * sp->m_nOverlapCount;
            m_consume.m_fHpRate += sp->FUN_14096d810()->m_consume.m_fHpRate * (float)sp->m_nOverlapCount;
            m_consume.m_fSpRate += sp->FUN_14096d810()->m_consume.m_fSpRate * (float)sp->m_nOverlapCount;
            m_consume.m_fSpConsumeChangeHpRate +=
                sp->FUN_14096d810()->m_consume.m_fSpConsumeChangeHpRate * (float)sp->m_nOverlapCount;
            m_status.m_fResWapR += sp->FUN_14096d810()->m_status.m_fResWapR * (float)sp->m_nOverlapCount;
            m_status.m_fResBapR += sp->FUN_14096d810()->m_status.m_fResBapR * (float)sp->m_nOverlapCount;
            m_status.m_fResCadR += sp->FUN_14096d810()->m_status.m_fResCadR * (float)sp->m_nOverlapCount;
            m_status.m_fResAtpR += sp->FUN_14096d810()->m_status.m_fResAtpR * (float)sp->m_nOverlapCount;
            m_status.m_fResEvpR += sp->FUN_14096d810()->m_status.m_fResEvpR * (float)sp->m_nOverlapCount;
            m_status.m_fResPenR += sp->FUN_14096d810()->m_status.m_fResPenR * (float)sp->m_nOverlapCount;
        }
    }
    m_bDirty = 0;
    if (MyPC* pMy = FUN_140973920())
        pMy->FUN_1416561a0()->FUN_1411e7660();
}

// @0x1409733f0
void AdditionalCliList::FUN_1409733f0()
{
    if (FUN_140973640())
        return;
    if (m_pOwner->FUN_140976780() != m_motion.m_nSoundPitch)
        m_pOwner->FUN_1409788b0(m_motion.m_nSoundPitch);
}

// @0x140973450
void AdditionalCliList::FUN_140973450()
{
    if (FUN_140973640())
        return;
    if (m_motion.m_nSkillUseDisable != m_nSkillUseDisable)
    {
        m_nSkillUseDisable = m_motion.m_nSkillUseDisable;
        FUN_1419f37f0(5);
    }
}

// @0x1409734b0
void AdditionalCliList::FUN_1409734b0()
{
    if (FUN_1409735c0())
    {
        if (UIMainPlayerInfo* pInfo = FUN_140931900(20063))
            pInfo->FUN_1419f13b0(m_bInfinitySP == 0, 0);
    }
}

// @0x140973520
void AdditionalCliList::FUN_140973520()
{
    m_status.Clear();
    m_motion.Clear();
    m_consume.Clear();
    m_bPvpOnOff = false;
    m_bDisableRevivalHere = false;
    m_nItemSlotDisable = 0;
    m_nForceApplyTarget = 0;
    m_bInfinitySP = false;
    m_nInvincible = 0;
}

// @0x1409735c0
bool AdditionalCliList::FUN_1409735c0()
{
    return efd::DynamicCast<MyPC>(m_pOwner) ? 1 : 0;
}

// @0x140973600
bool AdditionalCliList::FUN_140973600()
{
    return efd::DynamicCast<PC>(m_pOwner) ? 1 : 0;
}

// @0x140973640
bool AdditionalCliList::FUN_140973640()
{
    return efd::DynamicCast<PortraitPC>(m_pOwner) ? 1 : 0;
}

// @0x140973680
bool AdditionalCliList::FUN_140973680(MS2Ptr<AdditionalCli> sp)
{
    if (FUN_140973640())
        return false;
    if (PC* pPC = efd::DynamicCast<PC>(m_pOwner))
    {
        if (static_cast<Unk_AclWorld*>(WorldService::GetInstance())->FUN_141bd30a0()->FUN_1403754d0())
            return true;
        if (static_cast<Unk_AclWorld*>(WorldService::GetInstance())->FUN_141bd30a0()->m_nMapType == 3)
            return true;
        if (pPC->FUN_140967420()->FUN_140743550())
            return true;
    }
    if (CNpc* pNpc = efd::DynamicCast<CNpc>(m_pOwner))
    {
        if (FUN_141092ff0(pNpc))
            return true;
        if (sp && sp->FUN_14096d810()->GetParent()->GetCategory() == 9)
            return true;
    }
    return false;
}

// @0x140973920
MyPC* AdditionalCliList::FUN_140973920()
{
    return efd::DynamicCast<MyPC>(m_pOwner);
}

// @0x140973950
void AdditionalCliList::FUN_140973950(MS2Ptr<AdditionalCli> sp)
{
    bool bMe = FUN_140930110(sp->m_nCasterId);
    if (sp->FUN_14096d810()->m_ui.FUN_1401927c0(bMe))
    {
        if (FUN_1409735c0())
        {
            UIMainPlayerInfo* pInfo = FUN_140931900(20063);
            if (pInfo)
                static_cast<Unk_AclMainInfo*>(pInfo)->FUN_1419f0fe0(sp);
        }
        else if (FUN_140973680(sp))
        {
            UIUpperHpBar* pBar = Unk_AcFindUI<UIUpperHpBar>((eUIClassID)20029);
            if (pBar)
                static_cast<Unk_AclUpperBar*>(pBar)->FUN_141b4cf40(sp);
            UINpcDuelHPBarDialog* pDuel = Unk_AcFindUI<UINpcDuelHPBarDialog>((eUIClassID)20322);
            if (pDuel)
                static_cast<Unk_AclDuelBar*>(pDuel)->FUN_140e6c440(sp);
        }
    }
    if (!FUN_140973640())
    {
        if (sp->FUN_14096d810()->m_ui.m_bIconBalloonOnOff)
        {
            MS2Ptr<Unk_PCBaseComp_a98> spBalloon = m_pOwner->vfunc_84();
            if (spBalloon.get())
                spBalloon->FUN_14128ecf0(sp->FUN_14096d260(), CString(sp->FUN_14096d810()->m_ui.m_strIcon),
                                         sp->FUN_14096d2e0());
        }
    }
    if (sp->FUN_14096d810()->m_shield.m_fHpByTargetMaxHP > 0.0f || sp->FUN_14096d810()->m_shield.m_nHpValue > 0)
        m_pOwner->FUN_141670260((int)sp->m_nShieldValue, true);
}

// @0x140973cc0
void AdditionalCliList::FUN_140973cc0(MS2Ptr<AdditionalCli> sp)
{
    if (FUN_1409735c0())
    {
        UIMainPlayerInfo* pInfo = FUN_140931900(20063);
        if (pInfo)
            pInfo->FUN_1419f1180(sp->FUN_14096d260());
    }
    else if (FUN_140973680(sp))
    {
        UIUpperHpBar* pBar = Unk_AcFindUI<UIUpperHpBar>((eUIClassID)20029);
        if (pBar)
            static_cast<Unk_AclUpperBar*>(pBar)->FUN_141b4d060(m_pOwner, sp->FUN_14096d260());
        UINpcDuelHPBarDialog* pDuel = Unk_AcFindUI<UINpcDuelHPBarDialog>((eUIClassID)20322);
        if (pDuel)
            pDuel->FUN_140e6c640(sp->FUN_14096d260());
    }
    if (sp->FUN_14096d810()->m_ui.m_bIconBalloonOnOff)
    {
        MS2Ptr<Unk_PCBaseComp_a98> spBalloon = m_pOwner->vfunc_84();
        if (spBalloon.get())
            spBalloon->FUN_14128edb0(sp->FUN_14096d260());
    }
    if (sp->FUN_14096d810()->m_shield.m_fHpByTargetMaxHP > 0.0f || sp->FUN_14096d810()->m_shield.m_nHpValue > 0)
    {
        MS2Ptr<Unk_PCBaseComp_a68> spBar = m_pOwner->vfunc_81();
        if (spBar.get())
            spBar->vfunc_3();
    }
}

// @0x140973f40
void AdditionalCliList::FUN_140973f40(MS2Ptr<AdditionalCli> sp)
{
    if (!FUN_1409735c0())
        return;
    PC* pLocal = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (sp->FUN_14096d2a0() == *FUN_1401d3200()->PCBangAdditionalEffectID.Get())
    {
        pLocal->FUN_140978540();
        if (sp->FUN_14096d810())
        {
            if (sp->FUN_14096d810()->HasSA((SAType)1))
                pLocal->FUN_141658f70((unsigned char)*FUN_1401d3200()->PCBangAdditionalEffectExp.Get());
            if (sp->FUN_14096d810()->HasSA((SAType)2))
                pLocal->FUN_141658f70((unsigned char)*FUN_1401d3200()->PCBangAdditionalEffectMeso.Get());
        }
    }
}

// @0x140974090
void AdditionalCliList::FUN_140974090(MS2Ptr<AdditionalCli> sp)
{
    if (!FUN_1409735c0())
        return;
    PC* pLocal = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (sp->FUN_14096d2a0() == *FUN_1401d3200()->PCBangAdditionalEffectID.Get())
        pLocal->FUN_140978540();
}

// @0x140974130
void AdditionalCliList::FUN_140974130(MS2Ptr<AdditionalCli> sp)
{
    if (!FUN_1409735c0())
        return;
    PC* pLocal = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pLocal)
        return;
    if (sp->FUN_14096d810()->m_nEventBuffType == 3)
    {
        efd::SmartPointer<Ridee> spRidee(m_pOwner->FUN_1416764a0());
        if (static_cast<bool>(spRidee) && spRidee->FUN_141675ed0())
            PCBase::FUN_141677f40(spRidee.operator->());
    }
}

// ---- COMDATs ----

// @0x1409755e0
SAInvokeEffectStat::SAInvokeEffectStat()
{
}

// @0x140975870
SAInvokeEffectStat::~SAInvokeEffectStat()
{
    m_18.RemoveAll();
}
