// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Adventure level window, older layout ("AdventureLevelOldDialog").
// MS2-UNIT: ?\uiadventurelevelolddialog.cpp
// MS2-RANGE: 0x140ba53b0-0x140ba6b20 .text$mn
// MS2-RANGE: 0x1400c98c0-0x1400c9a30 .text$di
// MS2-PIN: ?vfunc_48@UIAdventureLevelOldDialog@@UEAAHXZ 0x140ba6b10
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiadventurelevelolddialog.cpp"    // assumed
#define MS2_ASUICOMPONENT_SLOTS   // ASTileList::vfunc_24 (validateNow)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"

#include "uiadventurelevelolddialog.h"

#include <algorithm>
#include <map>
#include <set>

#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/commonfiles/adventureleveltablehelper.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // C3: AdditionalLevelData
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/commonfiles/os.h"

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

// The local player: a large virtual class; slot 78 is the class id, slot 141 the level.
class Unk_ALPlayer
{
public:
#define AL_V(n) virtual void vfunc_##n();
    AL_V(0) AL_V(1) AL_V(2) AL_V(3) AL_V(4) AL_V(5) AL_V(6) AL_V(7) AL_V(8) AL_V(9)
    AL_V(10) AL_V(11) AL_V(12) AL_V(13) AL_V(14) AL_V(15) AL_V(16) AL_V(17) AL_V(18) AL_V(19)
    AL_V(20) AL_V(21) AL_V(22) AL_V(23) AL_V(24) AL_V(25) AL_V(26) AL_V(27) AL_V(28) AL_V(29)
    AL_V(30) AL_V(31) AL_V(32) AL_V(33) AL_V(34) AL_V(35) AL_V(36) AL_V(37) AL_V(38) AL_V(39)
    AL_V(40) AL_V(41) AL_V(42) AL_V(43) AL_V(44) AL_V(45) AL_V(46) AL_V(47) AL_V(48) AL_V(49)
    AL_V(50) AL_V(51) AL_V(52) AL_V(53) AL_V(54) AL_V(55) AL_V(56) AL_V(57) AL_V(58) AL_V(59)
    AL_V(60) AL_V(61) AL_V(62) AL_V(63) AL_V(64) AL_V(65) AL_V(66) AL_V(67) AL_V(68) AL_V(69)
    AL_V(70) AL_V(71) AL_V(72) AL_V(73) AL_V(74) AL_V(75) AL_V(76) AL_V(77)
    virtual unsigned short vfunc_78();
    AL_V(79)
    AL_V(80) AL_V(81) AL_V(82) AL_V(83) AL_V(84) AL_V(85) AL_V(86) AL_V(87) AL_V(88) AL_V(89)
    AL_V(90) AL_V(91) AL_V(92) AL_V(93) AL_V(94) AL_V(95) AL_V(96) AL_V(97) AL_V(98) AL_V(99)
    AL_V(100) AL_V(101) AL_V(102) AL_V(103) AL_V(104) AL_V(105) AL_V(106) AL_V(107) AL_V(108) AL_V(109)
    AL_V(110) AL_V(111) AL_V(112) AL_V(113) AL_V(114) AL_V(115) AL_V(116) AL_V(117) AL_V(118) AL_V(119)
    AL_V(120) AL_V(121) AL_V(122) AL_V(123) AL_V(124) AL_V(125) AL_V(126) AL_V(127) AL_V(128) AL_V(129)
    AL_V(130) AL_V(131) AL_V(132) AL_V(133) AL_V(134) AL_V(135) AL_V(136) AL_V(137) AL_V(138) AL_V(139)
    AL_V(140)
    virtual unsigned int vfunc_141();                               // level
#undef AL_V
};
class Unk_1403ed2d0 { public: Unk_ALPlayer* FUN_141bd0cc0(); };

// The status-listener registry (singleton 0x140aa6d40).
class UIStatusEventDispatcher;

void DestroyItemInfoSlot(const CString& strBindID);                           // release the item bound to the name
void CreateItemInfoSlot(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);
void FUN_141415560(const CString& strName, ItemInfoSlot::CreateParam* pParam);

extern template class MS2Ptr<AdditionalLevelData>;

// An ability of the adventure level (a skill per character level step).
class Unk_ALAbility
{
public:
    unsigned short FUN_140195910(unsigned int nLevel);              // the ability's step for the level
    float FUN_140195a20(unsigned int nLevel);                       // progress of the step
    unsigned int FUN_1401959d0(unsigned int nLevel);                // level shown for the next step

    int m_0;                                                        // skill id
    int m_4;
    unsigned int m_8;                                               // level that unlocks it
    int m_c;
    int m_10;                                                       // highest step
};

bool FUN_1401958d0(CAdventureLevelReward* p);                       // empty record
void FUN_140202290(unsigned char* payload, COutputStream& stream);

// A mission: m_0 is the amount to reach, m_4 the reward kind, then the reward item (id, rarity, count).
class Unk_ALMission
{
public:
    bool FUN_140195ae0();                                           // empty record
    unsigned int m_0;
    int m_4;
    int m_8;
    int m_c;
    int m_10;
};

// The adventure level data table (singleton 0x1401958a0).
class Unk_ALTable
{
public:
    Unk_ALMission* FUN_140196090(unsigned int nMissionId);
};

// The state of a mission of the player.
// The mission state is CAdventureLevelMissionData (adventureleveltablehelper.h): +0x18 progress, +0x1c reward received.
//
//
//
//
//
//
extern std::map<unsigned int, CAdventureLevelMissionData> DAT_143ab3318;   // 0x143ab3318, the mission progress (userproxy)

// The claimed level rewards (global 0x143ab3308): find / end / iterator compare are COMDATs of earlier units.
extern std::set<unsigned int> DAT_143ab3308;

#include "ms2/client/ms2/additionalclilist.h"   // the ability manager of the player (C3: the local AdditionalCliList view is gone)
class Unk_ALAbilityMgr : public AdditionalCliList { };
class PCBase { public: class Unk_PCBaseBuffs* FUN_1416749a0(); };   // C3: member view
class Unk_ALCurrent { public: };
extern void* DAT_143aac280;

// The client configuration constants.
class Unk_ALConstU16 { public: unsigned short m_n; };
class Unk_ALConstU32 { public: unsigned int m_n; };
class Unk_ALConfig
{
public:
    char m_pad_0[0x91e8];
    Unk_ALConstU32 m_expMax;                                        // +0x91e8
    char m_pad_91ec[0x9298 - 0x91ec];
    Unk_ALConstU16 m_stat;                                          // +0x9298
};
namespace Client { class Constants; } template<class T> class TSingleton; template<> class TSingleton<Client::Constants> { public: static Client::Constants* GetInstance(); }; class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance)
class Unk_ALIdentity { public: char m_pad_0[0x1d0]; CString m_1d0; };
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource
extern __int64 DAT_143ab2958;

// The localized-string helpers.
template <class T> CString Unk_SocketFormat(const char* szFormat, const T& n);   // C3: was FUN_1402bad60
CStringW FUN_14183e9c0(CStringW str, int n);
class Unk_1401a9d70 { public: CStringW FUN_141811980(int a1, int a2); };
class CStringTable;


template <> bool MS2Ptr<ASTileList>::operator==(ASTileList* p) const;      // COMDAT 0x140ba4ee0 of this unit

// The reward-claim packets (op, id): written into packet 0xac.
class Unk_ALClaimLevel
{
public:
    Unk_ALClaimLevel() : m_op(8), m_id(0) {}
    int m_op;
    int m_id;
};
class Unk_ALClaimMission
{
public:
    Unk_ALClaimMission() : m_op(8), m_id(0) {}
    void FUN_140202380(COutPacket& packet);
    int m_op;
    int m_id;
};
void FUN_140710590(COutPacket& packet);


// ---- Value setters of the Invoke argument lists and the helpers of this unit ----
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);          // Value = n (UInt)
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);                 // Value = f
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);      // Value = the object's value
unsigned short FUN_140ba4b30(Unk_ALConstU16* p);
float FUN_140ba4b50(Unk_ALConstU32* p);
Unk_ALCurrent* GetAdventureLevelTableHelper();

// The helpers below are COMDATs of UIAdventureLevelDialog's unit (shared by identical code).
unsigned short FUN_140ba4b30(Unk_ALConstU16* p);
float FUN_140ba4b50(Unk_ALConstU32* p);
Unk_ALCurrent* GetAdventureLevelTableHelper();

// @0x1400c98c0 @0x1400c9980 @0x1400c99b0 @0x1400c99e0
// (the four initializers above are the statics of header_statics_a.h)

// @0x140ba53b0
UIAdventureLevelOldDialog::UIAdventureLevelOldDialog()
{
    SetTweenEnabled(1);
}

// @0x140ba5460
UIAdventureLevelOldDialog::~UIAdventureLevelOldDialog()
{
}

// @0x140ba54f0
CString UIAdventureLevelOldDialog::GetTypeName()
{
    return "AdventureLevelOldDialog";
}

// @0x140ba5540
int UIAdventureLevelOldDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}

// @0x140ba55a0
void UIAdventureLevelOldDialog::vfunc_67()
{
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    for (size_t i = 0; i < m_binds.GetCount(); i++)
        DestroyItemInfoSlot(m_binds.GetAt(i));
    UIDialog::vfunc_67();
}

// @0x140ba5650
void UIAdventureLevelOldDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    FillLevelGuide();
    FUN_140ba5c30();
    FillAbilityList();
}

// @0x140ba56b0
int UIAdventureLevelOldDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onReceiveItem") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned short nLevel = data.PopUInt();
            SendPrestige(nLevel);
        }
    }
    return 0;
}

// @0x140ba5790
void UIAdventureLevelOldDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    unsigned int nId = pArgs->PopUInt();
    Unk_ALAbility* pAbility = (Unk_ALAbility*)TSingleton<CAdventureLevelTable>::GetInstance()->GetAbility(nId);
    if (pAbility->m_0 == 0)
        return;
    unsigned short nStep = ((class CAdventureLevelAbility*)(pAbility))->GetCount(pPlayer->vfunc_141());
    MS2Ptr<AdditionalLevelData> spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_0, nStep);
    if (spAttr == NULL) {
        spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_0, 1);
        if (spAttr == NULL)
            return;
    }
    ASTooltip tooltip(*pRetVal, 2);
    tooltip.FUN_1409e2750(spAttr.get(), 6, 0);
}

// @0x140ba5950
void UIAdventureLevelOldDialog::vfunc_oa0_30(int a1)
{
    if (vfunc_55() != 0)
        return;
    if (m_30.IsNull())
        return;
    FillLevelGuide();
    FUN_140ba5c30();
    FillAbilityList();
}

// @0x140ba59f0
void UIAdventureLevelOldDialog::vfunc_oa0_31(void* a1)
{
    if (vfunc_55() != 0)
        return;
    if (m_30.IsNull())
        return;
    FUN_140ba5c30();
}

// @0x140ba5a70
void UIAdventureLevelOldDialog::RefreshLevelGuide()
{
    if (m_30.IsNull())
        return;
    FillLevelGuide();
}

// @0x140ba5ab0
void UIAdventureLevelOldDialog::FillLevelGuide()
{
    if (m_30.IsNull())
        return;
    const std::vector<unsigned int>& levels = TSingleton<CAdventureLevelTable>::GetInstance()->GetLevels();
    for (std::vector<unsigned int>::const_iterator it = levels.begin(); it != levels.end(); ++it) {
        unsigned short nLevel = (unsigned short)*it;
        ASObj obj(2);
        if (!FUN_140ba61b0(obj, nLevel))
            continue;
        if (!FUN_140ba63d0(obj, nLevel) && !FUN_140ba66a0(obj, nLevel))
            continue;
        m_30->Invoke("addLevelGuide", obj);
    }
}

// @0x140ba5c30
void UIAdventureLevelOldDialog::FUN_140ba5c30()
{
    if (m_30.IsNull())
        return;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    float fExp = (float)DAT_143ab2958;
    float fRatio = fExp / FUN_140ba4b50(&((class Unk_ALConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_expMax);
    m_30->Invoke("setLevelAndExp", pPlayer->vfunc_141(), fRatio);
}

// @0x140ba5d20
void UIAdventureLevelOldDialog::FillAbilityList()
{
    if (m_30.IsNull())
        return;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    MS2Ptr<ASTileList> spList = GetChild<ASTileList>("m_abilityList");
    if (spList == NULL)
        return;
    spList->Invoke("resetRenderer");
    ((class ASCoreList*)(spList))->FUN_1422dd1d0();
    const std::vector<unsigned int>& abilities = TSingleton<CAdventureLevelTable>::GetInstance()->GetAbilityIds();
    for (std::vector<unsigned int>::const_iterator it = abilities.begin(); it != abilities.end(); ++it) {
        const unsigned int* pId = &*it;
        Unk_ALAbility* pAbility = (Unk_ALAbility*)TSingleton<CAdventureLevelTable>::GetInstance()->GetAbility(*pId);
        unsigned short nStep = ((class CAdventureLevelAbility*)(pAbility))->GetCount(pPlayer->vfunc_141());
        MS2Ptr<AdditionalLevelData> spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_0, nStep);
        if (spAttr == NULL) {
            spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_0, 1);
            if (spAttr == NULL)
                continue;
        }
        bool bLock = pPlayer->vfunc_141() < pAbility->m_8;
        if (reinterpret_cast<Unk_ALAbilityMgr*>(reinterpret_cast<PCBase*>(pPlayer)->FUN_1416749a0())->FUN_140970020(pAbility->m_0, nStep, 0, 1) == 0) {
            if (pAbility->m_0 != *reinterpret_cast<int*>(reinterpret_cast<CAdventureLevelTableHelper*>(GetAdventureLevelTableHelper())->GetCurrent()))
                bLock = true;
        }
        ASObj obj(2);
        obj.SetMemberUInt("id", pAbility->m_0);
        obj.SetBoolMember("isLock", bLock);
        obj.SetStringMember("imgPath", spAttr->GetIcon());
        obj.SetMemberFloat("abilityStatus", ((class CAdventureLevelAbility*)(pAbility))->GetPercent(pPlayer->vfunc_141()));
        if (bLock)
            obj.SetMemberUInt("level", pAbility->m_8);
        else if ((int)nStep < pAbility->m_10)
            obj.SetMemberUInt("level", ((unsigned int)((class CAdventureLevelAbility*)(pAbility))->GetLevelOfCount(pPlayer->vfunc_141())));
        ((class ASCoreList*)(spList))->AddItem(obj);
    }
    spList->vfunc_24(true);
}

// @0x140ba61b0
int UIAdventureLevelOldDialog::FUN_140ba61b0(ASObj& obj, unsigned int nLevel)
{
    if (m_30.IsNull())
        return 0;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return 0;
    CString strState("active");
    if (DAT_143ab3308.find(nLevel) != DAT_143ab3308.end())
        strState = "inactive";
    if (nLevel > pPlayer->vfunc_141())
        strState = "lock";
    obj.SetMemberUInt("id", nLevel);
    obj.SetStringMember("state", strState);
    unsigned int nOne = 1;
    obj.SetMemberUInt("level", (std::max)(nLevel, nOne));
    ((class AScript&)(obj)).SetWStringMember("levelStr", FUN_14028dfa0<unsigned int>(CStringW(L"s_adventure_level_level"), nLevel));
    return 1;
}

// @0x140ba63d0
int UIAdventureLevelOldDialog::FUN_140ba63d0(ASObj& obj, unsigned int nLevel)
{
    const CAdventureLevelReward* pReward = TSingleton<CAdventureLevelTable>::GetInstance()->GetReward(nLevel);
    if (FUN_1401958d0(const_cast<CAdventureLevelReward*>(pReward)))
        return 0;
    if (pReward->m_nType != 1)
        return 0;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return 0;
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem->FUN_14052b130(pReward->m_nId, pReward->m_nRank, 0) == 0)
        return 0;
    spItem->SetCountClamped(pReward->m_nValue);
    int nIconType = 0x415;
    CString strBindID;
    strBindID.Format("%s.%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
    CreateItemInfoSlot(strBindID, spItem, 0, nIconType, 0x800);
    obj.SetStringMember("binding", strBindID);
    m_binds.Add(strBindID);
    return 1;
}

// @0x140ba66a0
int UIAdventureLevelOldDialog::FUN_140ba66a0(ASObj& obj, unsigned int nLevel)
{
    const CAdventureLevelReward* pReward = TSingleton<CAdventureLevelTable>::GetInstance()->GetReward(nLevel);
    if (FUN_1401958d0(const_cast<CAdventureLevelReward*>(pReward)))
        return 0;
    if (pReward->m_nType != 2)
        return 0;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return 0;
    if (nLevel <= pPlayer->vfunc_141())
        obj.FUN_1409c0dc0("state", "inactive");
    if ((int)pPlayer->vfunc_78() < (int)FUN_140ba4b30(&((class Unk_ALConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_stat))
        obj.FUN_1409c0dc0("state", "lock");
    ItemInfoSlot::CreateParam param;
    param.m_strSlotText = ((class Unk_ALIdentity*)GetCommonResource())->m_1d0;
    param.m_strTip = FUN_14028dfa0<int>(CStringW(L"s_adventure_level_stat_reward"), reinterpret_cast<const int&>(pReward->m_nValue));
    param.m_nFlags = 1;
    param.m_nTipArg = 4;
    param.m_strCount = Unk_SocketFormat<int>("{0}", pReward->m_nValue);
    CString strBindID;
    strBindID.Format("%s.%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
    FUN_141415560(strBindID, &param);
    obj.SetStringMember("binding", strBindID);
    m_binds.Add(strBindID);
    return 1;
}

// @0x140ba6a10
void UIAdventureLevelOldDialog::SendPrestige(unsigned int nLevel)
{
    const CAdventureLevelReward* pReward = TSingleton<CAdventureLevelTable>::GetInstance()->GetReward(nLevel);
    if (FUN_1401958d0(const_cast<CAdventureLevelReward*>(pReward)))
        return;
    if (pReward->m_nType == 2)
        return;
    Unk_ALClaimLevel claim;
    claim.m_op = 3;
    claim.m_id = nLevel;
    COutPacket packet(static_cast<int>(SendOp::Prestige), 0);
    FUN_140202290(reinterpret_cast<unsigned char*>(&claim), packet);
    FUN_140710590(packet);
}


// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca14d0-0x142ca1560 .text$yd
