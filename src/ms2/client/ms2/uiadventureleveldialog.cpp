// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Adventure level window ("AdventureLevelDialog").
// MS2-UNIT: ?\uiadventureleveldialog.cpp
// MS2-RANGE: 0x140ba2a80-0x140ba53b0 .text$mn
// MS2-RANGE: 0x1400c9750-0x1400c98c0 .text$di
// MS2-PIN: ?vfunc_oa0_9@UIStatusEventListener@@UEAAXG@Z 0x140ba4fd0
// MS2-PIN: ??1CreateParam@ItemInfoSlot@@UEAA@XZ 0x140ba4e80
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Kfn@$$CBIVCAdventureLevelMissionData@@@?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@SAAEBIAEBU?$pair@$$CBIVCAdventureLevelMissionData@@@1@@Z 0x140ba4d60 ; prop
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@1@AEBI@Z 0x140ba4d70 ; unique
// MS2-PIN: ??$addressof@$$CBU?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@YAPEBU?$pair@$$CBIVCAdventureLevelMissionData@@@0@AEBU10@@Z 0x140ba4e10 ; unique
// MS2-PIN: ?vfunc_oa0_3@UIStatusEventListener@@UEAAXHH@Z 0x140ba4fc0 ; unique
// MS2-PIN: ?vfunc_oa0_4@UIStatusEventListener@@UEAAXHH@Z 0x140ba4fe0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x140ba4ff0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140ba5070 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@2@XZ 0x140ba5080 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@2@XZ 0x140ba5090 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x140ba50a0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x140ba50c0 ; prop
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@IEBAAEBIPEAU?$_Tree_node@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@PEAX@2@@Z 0x140ba50e0 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBIVCAdventureLevelMissionData@@@2@@Z 0x140ba5110 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@2@AEBI@Z 0x140ba5130 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@std@@@std@@@2@AEBI@Z 0x140ba5210 ; unique
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiadventureleveldialog.cpp"
#define MS2_ASUICOMPONENT_SLOTS   // ASTileList::vfunc_24 (validateNow)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"

#include "uiadventureleveldialog.h"

#include <algorithm>
#include <map>

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
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/commonfiles/adventureleveltablehelper.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // C3: AdditionalLevelData
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/additionalclilist.h"

template <> MS2Ptr<ASTileList> UISwfEntity::GetChild<ASTileList>(const CString& strName);    // 0x140ba4b70 (defined below)

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

void FUN_141415600(const CString& strBindID);                           // release the item bound to the name
void FUN_141415450(const CString& strName, MS2Ptr<CItem> pItem, int a1, int a2, int a3);
void FUN_141415560(const CString& strName, ItemInfoSlot::CreateParam* pParam);

extern template class MS2Ptr<AdditionalLevelData>;

// The state of a mission of the player.
// The mission state is CAdventureLevelMissionData (adventureleveltablehelper.h): +0x18 progress, +0x1c reward received.
//
//
//
//
//
//
extern std::map<unsigned int, CAdventureLevelMissionData> DAT_143ab3318;   // 0x143ab3318, the mission progress (userproxy)

// The claimed level rewards.
extern std::set<unsigned int> DAT_143ab3308;

bool FUN_1401958d0(CAdventureLevelReward* p);    // empty record
bool FUN_140195ae0(CAdventureLevelMission* p);   // empty record
void FUN_140202290(unsigned char* payload, COutputStream& stream);
void FUN_140202380(unsigned char* payload, COutputStream& stream);
class CAdventureLevelTableHelper;

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
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
class Unk_ALIdentity { public: char m_pad_0[0x1d0]; CString m_1d0; };
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0
extern __int64 DAT_143ab2958;

// The localized-string helpers.
CStringW FUN_14183e9c0(CStringW str, int n);


template <> inline bool MS2Ptr<ASTileList>::operator==(ASTileList* p) const;      // COMDAT 0x140ba4ee0 (inline: uiblackmarketpagemeso and uidungeonroomdialog instantiate it too)

// The reward-claim packets (op, id): written into packet 0xac.
class Unk_ALClaimLevel
{
public:
    Unk_ALClaimLevel() : m_op(8), m_id(0) {}
    void FUN_140202290(COutPacket& packet);
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
class Unk_ALCurrent* FUN_140ba4fa0();

// @0x1400c9750 @0x1400c9810 @0x1400c9840 @0x1400c9870
// (the four initializers above are the statics of header_statics_a.h)

// @0x140ba2a80
UIAdventureLevelDialog::UIAdventureLevelDialog()
{
    FUN_141924170(1);
}

// @0x140ba2b20
UIAdventureLevelDialog::~UIAdventureLevelDialog()
{
}

// @0x140ba2ba0
CString UIAdventureLevelDialog::GetTypeName()
{
    return "AdventureLevelDialog";
}

// @0x140ba2bf0
int UIAdventureLevelDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 1;
}

// @0x140ba2c50
void UIAdventureLevelDialog::vfunc_67()
{
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    for (size_t i = 0; i < m_binds.GetCount(); i++)
        FUN_141415600(m_binds.GetAt(i));
    UIDialog::vfunc_67();
}

// @0x140ba2d00
void UIAdventureLevelDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    FUN_140ba3330();
    FUN_140ba34b0();
    FUN_140ba35a0();
    FUN_140ba3a30();
}

// @0x140ba2d70
int UIAdventureLevelDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onReceiveItem") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned short nLevel = data.PopUInt();
            FUN_140ba4960(nLevel);
        }
        return 1;
    }
    if (_stricmp(szMethod, "onReceiveMissionReward") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned int nMissionId = data.PopUInt();
            FUN_140ba4a10(nMissionId);
        }
        return 1;
    }
    return 0;
}

// @0x140ba2ee0
void UIAdventureLevelDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    unsigned int nId = pArgs->PopUInt();
    const CAdventureLevelAbility* pAbility = TSingleton<CAdventureLevelTable>::GetInstance()->GetAbility(nId);
    if (pAbility->m_nEffectId == 0)
        return;
    unsigned short nStep = pAbility->GetCount(pPlayer->vfunc_141());
    MS2Ptr<AdditionalLevelData> spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_nEffectId, nStep);
    if (spAttr == NULL) {
        spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_nEffectId, 1);
        if (spAttr == NULL)
            return;
    }
    ASTooltip tooltip(*pRetVal, 2);
    tooltip.FUN_1409e2750(spAttr.get(), 6, 0);
}

// @0x140ba30a0
void UIAdventureLevelDialog::vfunc_oa0_30(int a1)
{
    if (vfunc_55() != 0)
        return;
    if (m_30.IsNull())
        return;
    FUN_140ba3330();
    FUN_140ba34b0();
    FUN_140ba35a0();
}

// @0x140ba3140
void UIAdventureLevelDialog::vfunc_oa0_31(void* a1)
{
    if (vfunc_55() != 0)
        return;
    if (m_30.IsNull())
        return;
    FUN_140ba34b0();
}

// @0x140ba31c0
void UIAdventureLevelDialog::FUN_140ba31c0()
{
    if (m_30.IsNull())
        return;
    FUN_140ba3330();
}

// @0x140ba3200
void UIAdventureLevelDialog::FUN_140ba3200()
{
    if (m_30.IsNull())
        return;
    FUN_140ba3a30();
}

// The number of missions that are done but whose reward is not claimed yet.
// @0x140ba3240
int UIAdventureLevelDialog::FUN_140ba3240()
{
    int nCount = 0;
    for (std::map<unsigned int, CAdventureLevelMissionData>::const_iterator it = DAT_143ab3318.begin(); it != DAT_143ab3318.end(); ++it) {
        if (it->second.m_b1c != 0)
            continue;
        const unsigned int* pId = &it->first;
        const CAdventureLevelMission* pMission = TSingleton<CAdventureLevelTable>::GetInstance()->GetMission(*pId);
        if (FUN_140195ae0(const_cast<CAdventureLevelMission*>(pMission)))
            continue;
        if ((unsigned int)it->second.m_nId < (unsigned int)pMission->m_nCount)
            continue;
        nCount++;
    }
    return nCount;
}

// @0x140ba3330
void UIAdventureLevelDialog::FUN_140ba3330()
{
    if (m_30.IsNull())
        return;
    const std::vector<unsigned int>& levels = TSingleton<CAdventureLevelTable>::GetInstance()->GetLevels();
    for (std::vector<unsigned int>::const_iterator it = levels.begin(); it != levels.end(); ++it) {
        unsigned short nLevel = (unsigned short)*it;
        ASObj obj(2);
        if (!FUN_140ba3d60(obj, nLevel))
            continue;
        if (!FUN_140ba3f80(obj, nLevel) && !FUN_140ba4250(obj, nLevel))
            continue;
        m_30->Invoke("addLevelGuide", obj);
    }
}

// @0x140ba34b0
void UIAdventureLevelDialog::FUN_140ba34b0()
{
    if (m_30.IsNull())
        return;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    float fExp = (float)DAT_143ab2958;
    float fRatio = fExp / FUN_140ba4b50(&((class Unk_ALConfig*)GetClientConstants())->m_expMax);
    m_30->Invoke("setLevelAndExp", pPlayer->vfunc_141(), fRatio);
}

// @0x140ba35a0
void UIAdventureLevelDialog::FUN_140ba35a0()
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
    spList->FUN_1422dd1d0();
    const std::vector<unsigned int>& abilities = TSingleton<CAdventureLevelTable>::GetInstance()->GetAbilityIds();
    for (std::vector<unsigned int>::const_iterator it = abilities.begin(); it != abilities.end(); ++it) {
        const unsigned int* pId = &*it;
        const CAdventureLevelAbility* pAbility = TSingleton<CAdventureLevelTable>::GetInstance()->GetAbility(*pId);
        unsigned short nStep = pAbility->GetCount(pPlayer->vfunc_141());
        MS2Ptr<AdditionalLevelData> spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_nEffectId, nStep);
        if (spAttr == NULL) {
            spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(pAbility->m_nEffectId, 1);
            if (spAttr == NULL)
                continue;
        }
        bool bLock = pPlayer->vfunc_141() < pAbility->m_nRequireLevel;
        if (reinterpret_cast<AdditionalCliList*>(reinterpret_cast<PCBase*>(pPlayer)->FUN_1416749a0())->FUN_140970020(pAbility->m_nEffectId, nStep, 0, 1) == 0) {
            if (pAbility->m_nEffectId != reinterpret_cast<CAdventureLevelTableHelper*>(FUN_140ba4fa0())->GetCurrent()->m_nEffectId)
                bLock = true;
        }
        ASObj obj(2);
        obj.FUN_1409c0d20("id", pAbility->m_nEffectId);
        obj.FUN_1407cbbe0("isLock", bLock);
        obj.FUN_1407cba60("imgPath", spAttr->GetIcon());
        obj.FUN_1409c4a30("abilityStatus", pAbility->GetPercent(pPlayer->vfunc_141()));
        if (bLock)
            obj.FUN_1409c0d20("level", pAbility->m_nRequireLevel);
        else if ((int)nStep < pAbility->m_nMaxCount)
            obj.FUN_1409c0d20("level", pAbility->GetLevelOfCount(pPlayer->vfunc_141()));
        spList->AddItem(obj);
    }
    spList->vfunc_24(true);
}

// @0x140ba3a30
void UIAdventureLevelDialog::FUN_140ba3a30()
{
    if (m_30.IsNull())
        return;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return;
    MS2Ptr<ASTileList> spList = GetChild<ASTileList>("m_missionList");
    if (spList == NULL)
        return;
    spList->Invoke("resetRenderer");
    spList->FUN_1422dd1d0();
    for (std::map<unsigned int, CAdventureLevelMissionData>::const_iterator it = DAT_143ab3318.begin(); it != DAT_143ab3318.end(); ++it) {
        const unsigned int* pId = &it->first;
        const CAdventureLevelMission* pMission = TSingleton<CAdventureLevelTable>::GetInstance()->GetMission(*pId);
        if (FUN_140195ae0(const_cast<CAdventureLevelMission*>(pMission)))
            continue;
        ASObj obj(2);
        obj.FUN_1409c0d20("id", it->first);
        FUN_140ba45c0(obj, it->first);
        obj.FUN_1407cbb20("missionName", FUN_14028dfa0<unsigned int>(CStringW(L"s_adventure_level_mission_NameKey"), reinterpret_cast<const unsigned int&>(pMission->m_nCount)));
        obj.FUN_1407cbbe0("received", it->second.m_b1c);
        obj.FUN_1407cbbe0("completed", (unsigned int)it->second.m_nId >= (unsigned int)pMission->m_nCount);
        spList->AddItem(obj);
    }
    spList->vfunc_24(true);
}

// @0x140ba3d60
int UIAdventureLevelDialog::FUN_140ba3d60(ASObj& obj, unsigned int nLevel)
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
    obj.FUN_1409c0d20("id", nLevel);
    obj.FUN_1407cba60("state", strState);
    unsigned int nOne = 1;
    obj.FUN_1409c0d20("level", (std::max)(nLevel, nOne));
    obj.FUN_1407cbb20("levelStr", FUN_14028dfa0<unsigned int>(CStringW(L"s_adventure_level_level"), nLevel));
    return 1;
}

// @0x140ba3f80
int UIAdventureLevelDialog::FUN_140ba3f80(ASObj& obj, unsigned int nLevel)
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
    FUN_141415450(strBindID, spItem, 0, nIconType, 0x800);
    obj.FUN_1407cba60("binding", strBindID);
    m_binds.Add(strBindID);
    return 1;
}

// @0x140ba4250
int UIAdventureLevelDialog::FUN_140ba4250(ASObj& obj, unsigned int nLevel)
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
    if (pPlayer->vfunc_78() < FUN_140ba4b30(&((class Unk_ALConfig*)GetClientConstants())->m_stat))
        obj.FUN_1409c0dc0("state", "lock");
    ItemInfoSlot::CreateParam param;
    param.m_strSlotText = ((class Unk_ALIdentity*)FUN_1401d31f0())->m_1d0;
    param.m_strTip = FUN_14028dfa0<int>(CStringW(L"s_adventure_level_stat_reward"), pReward->m_nValue);
    param.m_nFlags = 1;
    param.m_nTipArg = 4;
    param.m_strCount = Unk_SocketFormat("{0}", pReward->m_nValue);
    CString strBindID;
    strBindID.Format("%s.%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
    FUN_141415560(strBindID, &param);
    obj.FUN_1407cba60("binding", strBindID);
    m_binds.Add(strBindID);
    return 1;
}

// @0x140ba45c0
int UIAdventureLevelDialog::FUN_140ba45c0(ASObj& obj, unsigned int nMissionId)
{
    const CAdventureLevelMission* pMission = TSingleton<CAdventureLevelTable>::GetInstance()->GetMission(nMissionId);
    if (FUN_140195ae0(const_cast<CAdventureLevelMission*>(pMission)))
        return 0;
    if (pMission->m_nOne != 1)
        return 0;
    Unk_ALPlayer* pPlayer = ((Unk_ALPlayer*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer == NULL)
        return 0;
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem->FUN_14052b130(pMission->m_nItemId, pMission->m_nItemRank, 0) == 0)
        return 0;
    spItem->SetCountClamped(pMission->m_nItemCount);
    int nIconType = 0x415;
    CString strBindID;
    strBindID.Format("%s.%d", (LPCSTR)GetTypeName(), m_binds.GetCount() + 1);
    FUN_141415450(strBindID, spItem, 0, nIconType, 0x800);
    obj.FUN_1407cba60("binding", strBindID);
    obj.FUN_1407cbb20("slotName", FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->FUN_1405276c0()), spItem->GetRarity()));
    m_binds.Add(strBindID);
    return 1;
}

// @0x140ba4960
void UIAdventureLevelDialog::FUN_140ba4960(unsigned int nLevel)
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

// @0x140ba4a10
void UIAdventureLevelDialog::FUN_140ba4a10(unsigned int nMissionId)
{
    const CAdventureLevelMission* pMission = TSingleton<CAdventureLevelTable>::GetInstance()->GetMission(nMissionId);
    if (FUN_140195ae0(const_cast<CAdventureLevelMission*>(pMission)))
        return;
    std::map<unsigned int, CAdventureLevelMissionData>::const_iterator it = DAT_143ab3318.find(nMissionId);
    if (it == DAT_143ab3318.end())
        return;
    if (it->second.m_b1c != 0)
        return;
    if ((unsigned int)it->second.m_nId < (unsigned int)pMission->m_nCount)
        return;
    Unk_ALClaimMission claim;
    claim.m_op = 5;
    claim.m_id = nMissionId;
    COutPacket packet(static_cast<int>(SendOp::Prestige), 0);
    FUN_140202380(reinterpret_cast<unsigned char*>(&claim), packet);
    FUN_140710590(packet);
}

// @0x140ba4b30
unsigned short FUN_140ba4b30(Unk_ALConstU16* p)
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(p)->Get());
}

// @0x140ba4b50
float FUN_140ba4b50(Unk_ALConstU32* p)
{
    return (float)*reinterpret_cast<Common::Constants::Value<unsigned int>*>(p)->Get();
}

// @0x140ba4b70
template <> MS2Ptr<ASTileList> UISwfEntity::GetChild<ASTileList>(const CString& strName)
{
    if (m_30 == NULL)
        return MS2Ptr<ASTileList>(0);
    return m_30->FUN_140accef0<ASTileList>(strName);
}

// @0x140ba4c00
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned int a1, float a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bcd10(&args[0], a1);
    FUN_1422bcd70(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba4cc0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, const AScript& obj)
{
    ASArgList args;
    args.resize(1);
    FUN_1422bce40(&args[0], obj);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140ba4ee0
template <> inline bool MS2Ptr<ASTileList>::operator==(ASTileList* p) const
{
    return m_p == p;
}

// @0x140ba4f60
// (the scalar deleting destructor of UIAdventureLevelDialog and its thunk at +0x178 are compiler generated)

// @0x140ba4fa0
Unk_ALCurrent* FUN_140ba4fa0()
{
    return (Unk_ALCurrent*)reinterpret_cast<void*>(TSingleton<CAdventureLevelTableHelper>::s_instance);
}

MS2_REPLACE_METHOD(0x140BA2BA0, UIAdventureLevelDialog, GetTypeName, 61, 0x3BFF09FB);
MS2_REPLACE_METHOD(0x140BA2BF0, UIAdventureLevelDialog, vfunc_65, 90, 0xD7F49833);
MS2_REPLACE_METHOD(0x140BA2C50, UIAdventureLevelDialog, vfunc_67, 161, 0x5762322E);
MS2_REPLACE_METHOD(0x140BA2D00, UIAdventureLevelDialog, OnLoadComplete, 92, 0x20934D66);
MS2_REPLACE_METHOD(0x140BA2D70, UIAdventureLevelDialog, vfunc_28, 356, 0x0AF980D3);
MS2_REPLACE_METHOD(0x140BA2EE0, UIAdventureLevelDialog, vfunc_49, 432, 0xAA2C8A70);
MS2_REPLACE_METHOD_VIA(0x140BA30A0, UIAdventureLevelDialog, UIStatusEventListener, vfunc_oa0_30, 151, 0xE776427B);
MS2_REPLACE_METHOD_VIA(0x140BA3140, UIAdventureLevelDialog, UIStatusEventListener, vfunc_oa0_31, 114, 0x4817988E);
MS2_REPLACE_METHOD(0x140BA31C0, UIAdventureLevelDialog, FUN_140ba31c0, 50, 0x5EF17F2E);
MS2_REPLACE_METHOD(0x140BA3200, UIAdventureLevelDialog, FUN_140ba3200, 50, 0x303AA5F7);
MS2_REPLACE_METHOD(0x140BA3240, UIAdventureLevelDialog, FUN_140ba3240, 221, 0x9FDDA703);
MS2_REPLACE_METHOD(0x140BA3330, UIAdventureLevelDialog, FUN_140ba3330, 373, 0x4D04C112);
MS2_REPLACE_METHOD(0x140BA34B0, UIAdventureLevelDialog, FUN_140ba34b0, 219, 0xC2D3C388);
MS2_REPLACE_METHOD(0x140BA35A0, UIAdventureLevelDialog, FUN_140ba35a0, 1158, 0x69210AE4);
MS2_REPLACE_METHOD(0x140BA3A30, UIAdventureLevelDialog, FUN_140ba3a30, 803, 0xDD70B4AB);
MS2_REPLACE_METHOD(0x140BA3D60, UIAdventureLevelDialog, FUN_140ba3d60, 536, 0x9C7D0079);
MS2_REPLACE_METHOD(0x140BA3F80, UIAdventureLevelDialog, FUN_140ba3f80, 704, 0xA601EF8C);
MS2_REPLACE_METHOD(0x140BA4250, UIAdventureLevelDialog, FUN_140ba4250, 873, 0xD72347B1);
MS2_REPLACE_METHOD(0x140BA45C0, UIAdventureLevelDialog, FUN_140ba45c0, 909, 0x796168A3);
MS2_REPLACE_METHOD(0x140BA4960, UIAdventureLevelDialog, FUN_140ba4960, 167, 0x63E6C143);
MS2_REPLACE_METHOD(0x140BA4A10, UIAdventureLevelDialog, FUN_140ba4a10, 283, 0x7655C1F1);

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1440-0x142ca14d0 .text$yd
