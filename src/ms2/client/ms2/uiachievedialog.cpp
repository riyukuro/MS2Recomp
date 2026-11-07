// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAchieveDialog (the trophy window) and the glue of its lists
// (vector / sort / CRBMap / CAtlMap). See uiachievedialog.h. w335.
// MS2-UNIT: ?\uiachievedialog.cpp
// MS2-RANGE: 0x1418a7310-0x1418b1520 .text$mn
// MS2-RANGE: 0x14010fa00-0x14010fbc0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__EkTrophyRewardGet@@YAXXZ 0x14010fa00 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x14010faf0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x14010fb20 ; probe
// MS2-PIN: ??$?0AEAHH$0A@@?$pair@HH@std@@QEAA@AEAH$$QEAH@Z 0x1418ade00 ; hand
// MS2-PIN: ??$make_pair@AEAHH@std@@YA?AU?$pair@HH@0@AEAH$$QEAH@Z 0x1418af680 ; hand
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@UClearRecord@UIAchieveDialog@@@std@@V?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@$00@std@@QEBAAEBV?$allocator@UClearRecord@UIAchieveDialog@@@2@XZ 0x1418b0f60 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@UClearRecord@UIAchieveDialog@@@std@@V?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@XZ 0x1418b0f70 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@UClearRecord@UIAchieveDialog@@@std@@V?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@UClearRecord@UIAchieveDialog@@@std@@@2@XZ 0x1418b0f80 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiachievedialog.cpp"
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"
#include "uiachievedialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/commonfiles/achievedata.h"
#include "ms2/commonfiles/achievecondition.h"
#include "ms2/client/ms2/achievemanager.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/fishingmanager.h"
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/placeholder/unk_blocklist.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/client/ms2/dungeonrecordcli.h"

// ---- unit-local views of exe types ----

// the "m_heroTrophy" / "m_summaryTrophy" component is an ASGameEntity: the MS2Ptr dtor/bool/->/! at
// 0x140ba7b40/bf0/c00/0x140ede6c0 and GetChild 0x140ede180 carry only the ASGameEntity name besides stand-ins.
#include "ms2/placeholder/asgameentity.h"
class Unk_ReportDialogAccess : public UIDialog { public: template<class T> MS2Ptr<T> GetChild(const CString& name); };   // C3: the child lookup 0x140ede180 (defined in uitencentuserreportdialog.cpp)


// the movie root: gotoAndPlay(label) and the reward count call
class UIDailyMissionDialog { public: MS2Ptr<ASScrollingList> FUN_140c02900(const CString& strName); };
class Unk_RsScript { public: Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int n, CStringW str); };

// the root pointer of the movie (m_30)

// the local player and the client options
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
void* FUN_14025e7c0();                                          // the text hook object
class CInputKeyHandler   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14116d840();
    bool IsDebugMode();
    bool FUN_14116d9c0(int nKey, bool bDebugOnly, int nLevel);
};
class PCBase { public: int IsDead(); };
class Unk_140166410* FUN_140166410();

// strings
template <class T1> CStringW FUN_14028dfa0(CStringW strKey, const T1& a1);
template <class T1, class T2> CStringW FUN_14028dfa0(CStringW strKey, const T1& a1, const T2& a2);
CStringW GetStringCommon(int nStringId);
template <class T1> CStringW BlockFormat(int nStringId, const T1& a1);
CStringW BlockFormat(int nStringId);
CStringW FUN_1416e4df0(int nId);
CStringW TranslateEnumDungeonGroup(unsigned int nGroup);
CString FUN_14016a600(const wchar_t* sz, int nCodePage);
void FUN_14083d2b0(CStringW& str);
int FUN_14083fec0(CStringW strText, CStringW strSearch);
void FUN_141842290(CStringW& str);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
int FUN_14053feb0(int nItemId);
void FUN_141275260(int nStringId, int nA, int nB);
int FUN_141276180(const CString& strName, const CString& strArg);
void FUN_140d2cca0(unsigned nId, unsigned nRank);
void FUN_14025a680(CStringW& str, ATL::CAtlArray<CStringW>& rOut, const wchar_t* szDelim);
void FUN_140710590(COutPacket& packet);

// the xml persistence
void XmlSetAttr(class TiXmlElement*, char const*, bool);   // C3: was FUN_140873bc0
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0

// the unit's own setters of the Invoke argument lists and members
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);

// the platform: request answers
class Unk_AcPlatform
{
public:
#define AC_V(n) virtual void vfunc_##n();
    AC_V(0) AC_V(1) AC_V(2) AC_V(3) AC_V(4) AC_V(5) AC_V(6) AC_V(7) AC_V(8) AC_V(9)
    AC_V(10) AC_V(11) AC_V(12) AC_V(13) AC_V(14) AC_V(15) AC_V(16) AC_V(17) AC_V(18) AC_V(19)
    AC_V(20) AC_V(21) AC_V(22) AC_V(23) AC_V(24) AC_V(25) AC_V(26) AC_V(27) AC_V(28) AC_V(29)
    AC_V(30) AC_V(31) AC_V(32) AC_V(33) AC_V(34) AC_V(35) AC_V(36)
    virtual int vfunc_37(void* pRequest);
#undef AC_V
};
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()


// collected ids: dungeons, fish, pets, quests, items
CMyCharacter* FUN_140931510();
class Unk_BreakSelected* FUN_140535320();
struct Unk_AcQuestMgr { char m_pad_00[0x10]; char m_10[0x10]; };
void* FUN_140764020();
extern ATL::CAtlMap<unsigned int, unsigned int> DAT_143ab30e0;        // achievement id -> grade

extern int DAT_143ab2914;                                       // the GM level

// the trophies updated by the server (refreshed per frame) and the claim sound
ATL::CAtlMap<unsigned int, int> DAT_143af0f30;
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
egf::EntityID DAT_143af0fc8(0);   // @0x14010fb50
static CString kTrophyRewardGet("system_Trophy_Reward_Get");

class Unk_NametagTrophy* FUN_1406c7600();   // C3: was FUN_1406c7600

// the summary page rows
struct Unk_AcCount { int m_id; int m_count; };

// the comparator of the summary sort: an empty functor (the exe passes it as a 1-byte value)
struct AcClearOrder { bool operator()(const UIAchieveDialog::ClearRecord& a, const UIAchieveDialog::ClearRecord& b) const; };
CStringW FUN_14093b970(int nId);
CStringW FUN_14093c320(CAchieve* pAchieve);
CStringW FUN_14093c8d0(int nId, int nGrade, int bRaw);
CStringW FUN_14093cdb0(int nId);
CStringW FUN_14093e330(CAchieve* pAchieve, int nKey);
CStringW FUN_14093bf10(CAchieve* pAchieve, int nGrade);
static void AcCollectClears(std::vector<UIAchieveDialog::ClearRecord>& rRecords);
#define FUN_1418adae0 AcCollectClears
static void FUN_1418ae010(ASObj& rObj, const char* szName, int n);
// Opens ASObj's protected value for the setter helper below (no members of its own).
class Unk_AcObjView : public ASObj { public: using AScript::m_value; };

// @0x1418aff70
int CAchieve::GetBookmark() { return m_d8; }

// @0x1418aff90
int CAchieve::GetValue80() { return m_80; }

// @0x1418b0bc0
void CAchieve::SetBookmark(int bBookmark) { m_d8 = bBookmark; }

// @0x1418afce0
bool AcClearOrder::operator()(const UIAchieveDialog::ClearRecord& a, const UIAchieveDialog::ClearRecord& b) const
{
    if (a.m_time == b.m_time)
        return a.m_grade > b.m_grade;
    return a.m_time > b.m_time;
}

// ---- UIAchieveDialog ----

// @0x1418a7310
UIAchieveDialog::UIAchieveDialog()
{
    m_7c = 1;
    m_5c = 1;
    m_88 = 1;
    m_180 = 0;
    m_190 = true;
    FUN_141924170(1);
    CAchieveCategory::Load();
    m_178 = 0;
    m_17c = CAchieveCategory::FindIdByTab(1);
    for (size_t i = 0; i < 14; i++)
        m_198.SetAt(i, 1);
}

// @0x1418a74b0
UIAchieveDialog::~UIAchieveDialog()
{
}

// @0x1418a7530
CString UIAchieveDialog::GetTypeName()
{
    return "AchieveDialog";
}

// @0x1418a7580
void UIAchieveDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_1e0.RemoveAll();
    DAT_143af0f30.RemoveAll();
    SetSearchText(m_188);
    COutPacket packet(static_cast<int>(SendOp::RequestUserEnv), 0);
    packet.WriteUInt8(3);
    FUN_140710590(packet);
    SetFilterIndex(m_180);
    FUN_1418a9360();
}

// @0x1418a7640
int UIAchieveDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onTabChange") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            m_178 = data.PopInt();
            m_17c = data.PopInt();
            FUN_1418a8ff0();
            m_1e0.RemoveAll();
            return 1;
        }
    }
    else if (_stricmp(szMethod, "onUpdateRenderer") == 0) {
        FUN_1418a9800();
        return 1;
    }
    else if (_stricmp(szMethod, "onReward") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
            if (pPlayer == 0)
                return 0;
            if (((class PCBase*)pPlayer)->IsDead() != 0) {
                FUN_141275260(0x80d, 1, 1);
                return 0;
            }
            unsigned nId = data.PopUInt();
            COutPacket packet(static_cast<int>(SendOp::Achieve), 0);
            packet.WriteUInt8(3);
            packet.WriteInt32(nId);
            FUN_140710590(packet);
            FUN_141276180(kTrophyRewardGet, "");
            return 1;
        }
    }
    else if (_stricmp(szMethod, "OnUseLink") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            unsigned nRank = data.PopUInt();
            FUN_140d2cca0(nId, nRank);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onDbgUp") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            if (FUN_1418acd10(nId) != 0) {
                COutPacket packet(static_cast<int>(SendOp::Achieve), 0);
                packet.WriteUInt8(5);
                packet.WriteInt32(nId);
                packet.WriteUInt8(0);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onDbgDown") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            COutPacket packet(static_cast<int>(SendOp::Achieve), 0);
            packet.WriteUInt8(5);
            packet.WriteInt32(nId);
            packet.WriteUInt8(1);
            FUN_140710590(packet);
        }
    }
    else if (_stricmp(szMethod, "onDbgUp30") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            if (FUN_1418acd10(nId) != 0) {
                COutPacket packet(static_cast<int>(SendOp::Achieve), 0);
                packet.WriteUInt8(5);
                packet.WriteInt32(nId);
                packet.WriteUInt8(2);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onDbgUp99") == 0) {
        if (DAT_143ab2914 < 50)
            return 0;
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            if (FUN_1418acd10(nId) != 0) {
                COutPacket packet(static_cast<int>(SendOp::Achieve), 0);
                packet.WriteUInt8(5);
                packet.WriteInt32(nId);
                packet.WriteUInt8(3);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onClickAchieveDetail") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nId = data.PopInt();
            FUN_1418aa9b0(nId);
        }
    }
    else if (_stricmp(szMethod, "onSearch") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            RequestSearch();
    }
    else if (_stricmp(szMethod, "onBookmark") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            int bBookmark = data.PopBool();
            MS2Ptr<CAchieve> spAchieve = ((class CAchieveManager*)FUN_1406c7600())->Find(nId);
            if (spAchieve.get() != 0) {
                spAchieve->SetBookmark(bBookmark);
                COutPacket packet(static_cast<int>(SendOp::Achieve), 0);
                packet.WriteUInt8(4);
                packet.WriteInt32(spAchieve->GetId());
                packet.WriteUInt8(bBookmark);
                FUN_140710590(packet);
            }
        }
    }
    else if (_stricmp(szMethod, "onFilterChange") == 0) {
        FUN_1418a8ff0();
        return 1;
    }
    else if (_stricmp(szMethod, "onClickSummary") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            FUN_1418aa9b0(nId);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onExpand") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            unsigned nId = data.PopUInt();
            int bExpand = data.PopBool();
            m_1e0.SetAt(nId, bExpand);
        }
    }
    else if (_stricmp(szMethod, "onFilter") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            m_190 = data.PopBool();
            CStringW strKinds = data.FUN_1422b8f40();
            ATL::CAtlArray<CStringW> tokens;
            FUN_14025a680(strKinds, tokens, L",");
            for (POSITION pos = m_198.GetStartPosition(); pos != 0; m_198.GetNext(pos))
                m_198.SetAt(m_198.GetKeyAt(pos), 0);
            for (size_t i = 0; i < tokens.GetCount(); i++) {
                int nKind = CAchieveData::ParseRewardType(tokens[i]);
                m_198.SetAt(nKind, 1);
            }
            FUN_1418a8ff0();
        }
    }
    return 0;
}

// @0x1418a8310
int UIAchieveDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}

// @0x1418a8330
void UIAchieveDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_178 = 0;
    m_188.Empty();
    m_17c = CAchieveCategory::FindIdByTab(1);
}

// @0x1418a8390
void UIAchieveDialog::vfunc_15()
{
    if (DAT_143af0f30.GetCount() == 0)
        return;
    if (vfunc_55() != 0)
        return;
    for (POSITION pos = DAT_143af0f30.GetStartPosition(); pos != 0; DAT_143af0f30.GetNext(pos))
        FUN_1418aa660(DAT_143af0f30.GetKeyAt(pos));
    DAT_143af0f30.RemoveAll();
}

// @0x1418a8430
int UIAchieveDialog::vfunc_13()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return 0;
    if (((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->FUN_14116d840()) {
        bool bHandled = ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("closePopup").GetBool();
        if (bHandled)
            return 1;
        vfunc_69();
        return 1;
    }
    if (((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->FUN_14116d9c0(0x1c, false, 0))
        RequestSearch();
    return 0;
}

// @0x1418a8530
void UIAchieveDialog::vfunc_80(void* pRequest)
{
    Unk_BlockList request(*reinterpret_cast<CInPacket*>(pRequest));
    Unk_BlockEntry value;
    if (request.Find("m_searchInput", value) == 1) {
        if (value.m_nFlags == 0) {
            FUN_1418a8ff0();
        }
        else {
            FUN_140d73aa0(BlockFormat(0x8b7), 0, 0, L"");
            SetSearchText(L"");
        }
    }
}

// @0x1418a8690
void UIAchieveDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    int nItemId = pArgs->PopUInt();
    int nRank = FUN_14053feb0(nItemId);
    ASTooltip tip(((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0(), 0x20, 2);
    if (tip.FUN_1409e1770(nItemId, nRank) != 0)
        *pRetVal = tip.FUN_1422bb870();
}

// @0x1418a8760
int UIAchieveDialog::vfunc_53(void* pCfg)
{
    if (UIDialog::vfunc_53(pCfg) == 0)
        return 0;
    XmlSetAttr((class TiXmlElement*)(pCfg), "all", m_190);
    for (POSITION pos = m_198.GetStartPosition(); pos != 0; m_198.GetNext(pos)) {
        CStringW strName = CAchieveData::GetRewardTypeName(m_198.GetKeyAt(pos));
        int nValue = m_198.GetValueAt(pos);
        XmlSetAttr((class TiXmlElement*)(pCfg), FUN_14016a600(strName, 0), nValue);
    }
    return 1;
}

// @0x1418a88b0
int UIAchieveDialog::vfunc_54(void* pCfg)
{
    if (UIDialog::vfunc_54(pCfg) == 0)
        return 0;
    XmlGetAttr((class TiXmlElement*)(pCfg), "all", m_190);
    for (size_t i = 0; i < 14; i++) {
        CStringW strName = CAchieveData::GetRewardTypeName(i);
        int nValue = 1;
        XmlGetAttr((class TiXmlElement*)(pCfg), FUN_14016a600(strName, 0), nValue);
        m_198.SetAt(i, nValue);
    }
    return 1;
}

// @0x1418a89d0
void UIAchieveDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (strMethod == "getFilter") {
        CStringW strKind = pArgs->FUN_1422b8f40();
        int nKind = CAchieveData::ParseRewardType(strKind);
        int bEnabled = 1;
        m_198.Lookup(nKind, bEnabled);
        Scaleform::GFx::Value value(bEnabled != 0);
        *pRetVal = value;
    }
    else if (_stricmp("getTooltipColor", strMethod) == 0) {
        unsigned nUnk1 = pArgs->PopUInt();
        unsigned nUnk2 = pArgs->PopUInt();
        unsigned nUnk3 = pArgs->PopUInt();
        unsigned nUnk4 = pArgs->PopUInt();
        ASObj data(pArgs->PopValue(), 2);
        unsigned nPalette = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(data.GetMember("paletteID")))->GetUInt();
        unsigned nSN = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(data.GetMember("colorSN")))->GetUInt();
        MS2Ptr<ItemColorEx> elem = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColorBySN(nPalette, nSN);
        if (elem.get() != 0) {
            CStringW strDesc;
            if ((unsigned)elem->m_n2c > 0) {
                int nKey = (unsigned)elem->m_n2c;
                CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x48, nKey);
                if (!strName.IsEmpty()) {
                    strDesc = FUN_14028dfa0(CStringW(L"s_beauty_tooltip_color_desc"), strName, TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x49, nKey));
                    strDesc.Append(L"\n");
                }
                ASTooltip tip(1, 2);
                if (tip.ApplyTextTooltip(strDesc) != 0) {
                    tip.SetTooltipAlign(1);
                    *pRetVal = tip.FUN_1422bb870();
                }
            }
        }
    }
    else if (_stricmp("getTooltipAchieve", strMethod) == 0) {
        void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
        unsigned nId = pArgs->PopUInt();
        unsigned nGrade = pArgs->PopUInt();
        ASTooltip tip(pPlayer, 2, 2);
        if (tip.FUN_1409e21a0(nId, nGrade) != 0) {
            tip.FUN_1407cbb20("comment", GetStringCommon(0x781));
            *pRetVal = tip.FUN_1422bb870();
        }
    }
}

// @0x1418a8f80
void UIAchieveDialog::FUN_1418a8f80()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    ApplyTabIndex(m_178);
    FUN_1418a8ff0();
    FUN_1418a9800();
    m_1e0.RemoveAll();
}

// @0x1418a8ff0
void UIAchieveDialog::FUN_1418a8ff0()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    MS2Ptr<CAchieveCategory> spCategory = CAchieveCategory::FindById(m_17c);
    if (spCategory.IsNull())
        return;
    {
        if (MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy")) {
            switch (spCategory->m_nTab) {
            case 2:
                spHero->vfunc_13("search");
                break;
            case 0:
                spHero->vfunc_13("search_filter");
                break;
            }
        }
    }
    FilterOptions options;
    switch (spCategory->m_nTab) {
    case 1:
        reinterpret_cast<AScript*>(m_30.operator->())->FUN_140e262c0("gotoAndPlay", "summary");
        FUN_1418a9c20();
        return;
    case 2:
        reinterpret_cast<AScript*>(m_30.operator->())->FUN_140e262c0("gotoAndPlay", "hero");
        options.m_survival = 1;
        options.m_filter = GetFilterIndex();
        FUN_1418aa190(&options);
        break;
    case 0:
        reinterpret_cast<AScript*>(m_30.operator->())->FUN_140e262c0("gotoAndPlay", "hero");
        options.m_survival = 0;
        options.m_categoryTag = spCategory->m_strCategoryTag;
        options.m_contentsTag = spCategory->m_strContentsTag;
        options.m_filter = GetFilterIndex();
        FUN_1418aa190(&options);
        break;
    }
}

// @0x1418a9360
void UIAchieveDialog::FUN_1418a9360()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    ASObj tree(2);
    ASArray nodes(2);
    tree.FUN_140e35d00("type", 1);
    tree.FUN_1409eb1d0("nodes", nodes);
    CAchieveCategory::List roots;
    CAchieveCategory::GetTabs(roots);
    for (size_t i = 0; i < roots.GetCount(); i++) {
        MS2Ptr<CAchieveCategory> spRoot = roots[i];
        ASObj node(2);
        node.FUN_1407cb9c0("id", spRoot->m_nId);
        node.FUN_1407cbb20("label", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x4a, spRoot->m_nId));
        node.FUN_1409c0dc0("rendererClassName", "export_renderer_category");
        FUN_1418ae010(node, "tabType", spRoot->m_nTab);
        node.FUN_1407cbbe0("alwaysOpen", spRoot->m_nTree == 2);
        node.FUN_140e35d00("type", spRoot->m_nTree == 1 ? 2 : 1);
        ASArray children(2);
        for (size_t j = 0; j < spRoot->m_aChildren.GetCount(); j++) {
            MS2Ptr<CAchieveCategory> spChild = spRoot->m_aChildren[j];
            ASObj row(2);
            row.FUN_1407cb9c0("id", spChild->m_nId);
            row.FUN_1407cbb20("label", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x4a, spChild->m_nId));
            row.FUN_1409c0dc0("rendererClassName", "export_renderer_category_low");
            FUN_1418ae010(row, "tabType", spChild->m_nTab);
            children.PushObj(row);
        }
        if (children.GetLength() != 0)
            node.FUN_1409eb1d0("nodes", children);
        nodes.PushObj(node);
    }
    ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("setCategory", tree);
}

// @0x1418a9800
void UIAchieveDialog::FUN_1418a9800()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    CAchieveList achieves;
    CAchieveCategory::List roots;
    CAchieveCategory::GetRows(roots);
    ((class CAchieveManager*)FUN_1406c7600())->GetList(achieves, 0, 0, 0, 0);
    std::vector<std::pair<int, int> > counts;
    for (size_t i = 0; i < roots.GetCount(); i++) {
        counts.push_back(std::make_pair(roots[i]->m_nId, 0));
    }
    for (size_t i = 0; i < achieves.GetCount(); i++) {
        MS2Ptr<CAchieve> spAchieve = achieves[i];
        if (spAchieve->GetType() == 8)
            continue;
        int nRewards = spAchieve->GetRewardCount();
        if (nRewards == 0)
            continue;
        for (size_t j = 0; j < roots.GetCount(); j++) {
            if (roots[j]->Matches(spAchieve->GetId()))
                counts[j].second += nRewards;
        }
    }
    for (size_t i = 0; i < counts.size(); i++) {
        CStringW strTitle = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x4a, counts[i].first);
        if (counts[i].second > 0) {
            CStringW strCount = BlockFormat(0x784, counts[i].second);
            strTitle.Append(strCount);
        }
        reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("setRewardCount", counts[i].first, CStringW(strTitle));
    }
}

// @0x1418a9c20
void UIAchieveDialog::FUN_1418a9c20()
{
    if (MS2Ptr<ASGameEntity> spSummary = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_summaryTrophy")) {
        spSummary->Invoke("removeAll");
        std::vector<ClearRecord> records;
        FUN_1418adae0(records);
        unsigned char nIndex = 0;
        for (std::vector<ClearRecord>::iterator it = records.begin(); it != records.end(); ++it) {
            ASObj row(2);
            MS2Ptr<CAchieve> spAchieve = ((class CAchieveManager*)FUN_1406c7600())->Find(it->m_id);
            MS2Ptr<CAchieveData> spData = spAchieve->GetDataRef();
            if (spData.IsNull())
                continue;
            if (!spData->IsAvailable())
                continue;
            CStringW strDesc = FUN_1418aac30(spAchieve, it->m_grade);
            FUN_141842290(strDesc);
            row.FUN_1409c0d20("id", spAchieve->GetId());
            row.FUN_1407cba60("icon", spAchieve->GetName(1));
            row.FUN_1407cb9c0("grade", it->m_grade);
            row.FUN_1407cbb20("date", FUN_14093e330(spAchieve, it->m_grade));
            row.FUN_1407cbb20("title", FUN_14093b970(spAchieve->GetId()));
            row.FUN_1407cbb20("desc", CStringW(strDesc));
            spSummary->FUN_1418adea0("setTrophy", nIndex, row);
            if (nIndex++ >= 12)
                break;
        }
        Unk_AchieveTab* pTally = ((class CAchieveManager*)FUN_1406c7600())->GetTally();
        int nA = reinterpret_cast<Unk_IntTriple*>(pTally)->Get(0);
        int nB = reinterpret_cast<Unk_IntTriple*>(pTally)->Get(1);
        int nC = reinterpret_cast<Unk_IntTriple*>(pTally)->Get(2);
        spSummary->Invoke("setScore", nA, nB, nC);
    }
}

// @0x1418aa190
void UIAchieveDialog::FUN_1418aa190(const FilterOptions* pOptions)
{
    MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy");
    if (spHero.IsNull())
        return;
    MS2Ptr<ASScrollingList> spList = spHero->FUN_140bc7280<ASScrollingList>("m_list");
    if (spList.IsNull())
        return;
    spList->FUN_1422dd1d0();
    CStringW strSearch = GetSearchText();
    int nSelected = 0;
    int nCount = 0;
    CAchieveList achieves;
    ((class CAchieveManager*)FUN_1406c7600())->GetListFromTable(achieves, 0, 0, 0, 0);
    if (achieves.GetCount() != 0) {
        ATL::CRBMap<unsigned __int64, MS2Ptr<CAchieve> > sorted(10);
        for (size_t i = 0; i < achieves.GetCount(); i++) {
            MS2Ptr<CAchieve> spAchieve = achieves[i];
            if (FUN_1418ace00(spAchieve, strSearch, pOptions) == 0)
                continue;
            unsigned nState = FUN_1418ac8f0(spAchieve);
            unsigned nOrder = (unsigned)i;
            sorted.SetAt(((unsigned __int64)nState << 32) | nOrder, spAchieve);
        }
        for (POSITION pos = sorted.GetHeadPosition(); pos != 0; sorted.GetNext(pos)) {
            MS2Ptr<CAchieve> spAchieve = sorted.GetValueAt(pos);
            ASObj row(2);
            FUN_1418ab7e0(row, spAchieve);
            spList->AddItem(row);
            nCount++;
        }
        if (nCount == 0) {
            ASObj row(2);
            row.FUN_1409c0dc0("state", "empty");
            row.FUN_1407cb9c0("search", 1);
            spList->AddItem(row);
        }
    }
    else {
        ASObj row(2);
        row.FUN_1409c0dc0("state", "empty");
        spList->AddItem(row);
    }
    spList->SetSelectedIndex(nSelected);
    spList->vfunc_24(true);
    static_cast<ASObj*>(static_cast<AScript*>(spList.get()))->FUN_1407cb9c0("scrollPosition", 0);
}

// @0x1418aa660
void UIAchieveDialog::FUN_1418aa660(int nId)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    MS2Ptr<CAchieve> spAchieve = ((class CAchieveManager*)FUN_1406c7600())->Find(nId);
    if (spAchieve.IsNull())
        return;
    FUN_1418a9800();
    MS2Ptr<CAchieveCategory> spCategory = CAchieveCategory::FindById(m_17c);
    if (spCategory.IsNull())
        return;
    switch (spCategory->m_nTab) {
    case 1:
        FUN_1418a9c20();
        break;
    case 0:
    case 2:
        if (spCategory->Matches(nId)) {
            if (MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy")) {
                ASObj row(2);
                FUN_1418ab7e0(row, spAchieve);
                spHero->Invoke("updateAchieve", row);
            }
        }
        break;
    }
}

// @0x1418aa890
void UIAchieveDialog::RequestSearch()
{
    CStringW strSearch = GetSearchText();
    if (strSearch.IsEmpty() == true)
        return;
    Unk_BlockList request(0x4e73);
    request.Add("m_searchInput", CStringW(strSearch), false);
    if (((class Unk_AcPlatform*)((void*)GetClientPlatform()))->vfunc_37(&request) == 1)
        FUN_1418a8ff0();
}

// @0x1418aa9b0
void UIAchieveDialog::FUN_1418aa9b0(int nId)
{
    m_188 = FUN_14093b970(nId);
    m_178 = FUN_1418ac320(nId);
    MS2Ptr<CAchieveCategory> spCategory = CAchieveCategory::GetRow(m_178);
    if (spCategory)
        m_17c = spCategory->m_nId;
    if (vfunc_55()) {
        m_180 = 0;
        FUN_141924680();
    }
    else {
        SetFilterIndex(0);
        SetSearchText(m_188);
        ApplyTabIndex(m_178);
        FUN_1418a8ff0();
    }
}

// @0x1418aaaf0
CStringW UIAchieveDialog::GetAchieveStateName(CAchieve* pAchieve)
{
    if (pAchieve == 0)
        return CStringW(L"");
    if (FUN_1418aca90(pAchieve) != 0)
        return CStringW(L"complete");
    return CStringW(L"normal");
}

// @0x1418aaba0
int UIAchieveDialog::GetRewardCount(CAchieve* pAchieve)
{
    if (pAchieve == 0)
        return 0;
    return pAchieve->GetRewardCount();
}

// @0x1418aabd0
CStringW UIAchieveDialog::FUN_1418aabd0(CAchieve* pAchieve)
{
    return FUN_1418aac30(pAchieve, pAchieve->GetCurGrade());
}

// @0x1418aac30
CStringW UIAchieveDialog::FUN_1418aac30(CAchieve* pAchieve, int nGrade)
{
    bool bSecret = FUN_1418aca90(pAchieve) && nGrade == pAchieve->GetDataRef()->m_nMaxGrade;
    if (bSecret)
        return FUN_14093c320(pAchieve);
    return FUN_14093c8d0(pAchieve->GetId(), nGrade, 1);
}

// @0x1418aad60
CStringW UIAchieveDialog::GetSearchText()
{
    if (MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy")) {
        if (MS2Ptr<ASTextInput> spInput = spHero->FUN_140bbe880<ASTextInput>("m_searchInput"))
            return reinterpret_cast<ASTextInput*>(spInput.operator->())->GetText();
    }
    return CStringW(L"");
}

// @0x1418aaee0
void UIAchieveDialog::SetSearchText(const CStringW& strText)
{
    if (MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy")) {
        if (MS2Ptr<ASTextInput> spInput = spHero->FUN_140bbe880<ASTextInput>("m_searchInput"))
            spInput->SetTextW(strText);
    }
}

// @0x1418ab000
void UIAchieveDialog::FUN_1418ab000(ASObj& rRow, CAchieve* pAchieve)
{
    CStringW strReward = FUN_14093cdb0(pAchieve->GetDataRef()->m_nId);
    if (strReward.GetLength() > 0) {
        CStringW strText = FUN_14028dfa0(CStringW(L"s_achieve_reward"), strReward);
        if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xbb)) {
            Unk_AchieveReward* pReward = pAchieve->GetReward();
            if (pReward != 0 && pReward->m_nType == 8) {
                strText = FUN_14028dfa0(CStringW(L"s_achieve_reward_item_coloring"), strReward);
                int nPalette = pReward->m_nCode;
                Unk_BmBoxPtr<CColorPaletteInfo::ColorArray> set = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColors(nPalette);
                if (set.get() != 0) {
                    int nIndex = 0;
                    for (size_t i = 0; i < set->GetCount(); i++) {
                        MS2Ptr<ItemColorEx> elem(set->GetAt(i));
                        if (elem->m_n24 != (int)pAchieve->GetId())
                            continue;
                        if (elem->m_n28 != pAchieve->GetStartGrade())
                            continue;
                        ASObj palette(2);
                        palette.FUN_1409c0d20("paletteID", nPalette);
                        palette.FUN_1409c4990("realColor", (unsigned)elem->m_aValues[0]);
                        palette.FUN_1409c4990("visibleColor", (unsigned)elem->m_n38);
                        palette.FUN_1409c4990("ch2Color", (unsigned)elem->m_aValues[2]);
                        palette.FUN_1407cb9c0("colorSN", elem->m_nColor);
                        if (elem->m_bFlag != 0) {
                            palette.FUN_1409c4990("realColor2", (unsigned)elem->m_aValues[2]);
                            palette.FUN_1409c4990("visibleColor2", (unsigned)elem->m_aValues[2]);
                        }
                        rRow.FUN_1418adf60(Unk_SocketFormat("palette{0}", nIndex++), AScript(palette));
                    }
                }
            }
        }
        rRow.FUN_1407cbb20("reward", CStringW(strText));
    }
}

// @0x1418ab520
void UIAchieveDialog::FUN_1418ab520(ASObj& rRow, CAchieve* pAchieve)
{
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return;
    int nGrade = 0;
    if (pAchieve->GetState() == 3)
        nGrade = pAchieve->GetCurGrade();
    else if (FUN_1418ac870(pAchieve) != 0)
        nGrade = pAchieve->GetCurGrade() - 1;
    else
        nGrade = pAchieve->GetStartGrade();
    rRow.FUN_1409c0d20("id", pAchieve->GetId());
    rRow.FUN_1407cbb20("desc", FUN_1418aac30(pAchieve, nGrade));
    rRow.FUN_1407cbb20("name", FUN_14093b970(pAchieve->GetId()));
    if (FUN_1418aca90(pAchieve) == 0) {
        __int64 nCur = pAchieve->GetProgress();
        __int64 nMax = pAchieve->GetGradeGoal(nGrade);
        if (nCur > nMax)
            nCur = nMax;
        rRow.FUN_1409c1180("cur", nCur);
        rRow.FUN_1409c1180("max", nMax);
        rRow.FUN_1407cb9c0("grade", nGrade);
        rRow.FUN_1407cbb20("progress", FUN_14093bf10(pAchieve, nGrade));
        if (DAT_143ab2914 >= 50)
            rRow.FUN_1407cbbe0("debug", ((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode());
    }
    else {
        rRow.FUN_1407cb9c0("grade", 11);
    }
}

// @0x1418ab7e0
void UIAchieveDialog::FUN_1418ab7e0(ASObj& rRow, CAchieve* pAchieve)
{
    void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    unsigned nItem = 0;
    Unk_AchieveReward* pReward = pAchieve->GetReward();
    if (pReward != 0 && pReward->m_nType == 1)
        nItem = pReward->m_nCode;
    FUN_1418ab520(rRow, pAchieve);
    FUN_1418ab000(rRow, pAchieve);
    rRow.FUN_1407cbb20("date", FUN_14093e330(pAchieve, pAchieve->GetCurGrade()));
    rRow.FUN_1407cbb20("state", GetAchieveStateName(pAchieve));
    rRow.FUN_1407cb9c0("count", GetRewardCount(pAchieve));
    rRow.FUN_1407cba60("icon", pAchieve->GetName(0));
    rRow.FUN_1407cb9c0("bookmark", pAchieve->GetBookmark());
    rRow.FUN_1409c0d20("tooltipItem", nItem);
    rRow.FUN_1407cb9c0("expand", FUN_1418acca0(pAchieve->GetId()));
    rRow.FUN_1407cb9c0("expandAble", 1);
    rRow.FUN_1407cb9c0("disabled", FUN_1418acce0(pAchieve));
    FUN_1418abaa0(rRow, pAchieve);
    FUN_1418abc60(rRow, pAchieve);
    FUN_1418abfa0(rRow, pAchieve);
}

// the list of the collected ids of the grade the trophy is at
static ATL::CAtlArray<__int64>* AcCollectedIds(CAchieve* pAchieve);

// @0x1418abaa0
void UIAchieveDialog::FUN_1418abaa0(ASObj& rRow, CAchieve* pAchieve)
{
    if (FUN_1418ad560(pAchieve->GetCondType()) == 0)
        return;
    ATL::CAtlArray<__int64>* pIds = AcCollectedIds(pAchieve);
    if (pIds == 0)
        return;
    if (pIds->GetCount() == 0)
        return;
    ASArray list(2);
    for (size_t i = 0; i < pIds->GetCount(); i++) {
        __int64 nId = pIds->GetAt(i);
        ASObj item(2);
        item.FUN_1407cbb20("condition", FUN_1418ad5d0(pAchieve->GetCondType(), nId));
        item.FUN_1407cb9c0("complete", FUN_1418ad960(pAchieve->GetCondType(), nId));
        list.PushObj(item);
    }
    rRow.FUN_1409eb1d0("reqCondition", list);
}

// @0x1418abc60
void UIAchieveDialog::FUN_1418abc60(ASObj& rRow, CAchieve* pAchieve)
{
    if (pAchieve->GetCondType() == 0x5e || pAchieve->GetCondType() == 0x61 || pAchieve->GetCondType() == 0x62 ||
        pAchieve->GetCondType() == 0x60) {
        int nGrade = pAchieve->GetCurGrade();
        MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
        if (!spData)
            return;
        MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
        if (!spGrade)
            return;
        int nWantGrade = (int)spGrade->m_pCondition->m_target.GetFirstValue();
        const ATL::CAtlArray<__int64>* pIds = AcCollectedIds(pAchieve);
        if (pIds != 0) {
            ASArray list(2);
            for (size_t i = 0; i < pIds->GetCount(); i++) {
                int nId = (int)(*pIds)[i];
                CAchieveData* pOther = GetAchieveData(nId);
                if (pOther != 0) {
                    int nReqGrade = nWantGrade == 0 ? pOther->m_nMaxGrade : nWantGrade;
                    ASObj item(2);
                    item.FUN_1409c0d20("id", nId);
                    item.FUN_1407cbb20("trophy", FUN_14093b970(nId));
                    item.FUN_1407cb9c0("complete", ((class CAchieveManager*)FUN_1406c7600())->IsGradeCleared(nId, nReqGrade));
                    item.FUN_1407cb9c0("grade", nReqGrade);
                    list.PushObj(item);
                }
            }
            rRow.FUN_1409eb1d0("reqAchieve", list);
        }
    }
}

// @0x1418abfa0
void UIAchieveDialog::FUN_1418abfa0(ASObj& rRow, CAchieve* pAchieve)
{
    void* pPlayer = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (!spData)
        return;
    int nFirst = pAchieve->GetDataRef()->m_nFirstGrade;
    int nLast = pAchieve->GetDataRef()->m_nMaxGrade;
    if (FUN_1418ac870(pAchieve) != 0 && pAchieve->GetState() != 3)
        nLast = pAchieve->GetCurGrade() - 1;
    ASArray list(2);
    for (int nGrade = nFirst; nGrade <= nLast; nGrade++) {
        int bComplete = pAchieve->GetValue(nGrade) != 0;
        ASObj item(2);
        item.FUN_1409c0d20("id", pAchieve->GetId());
        item.FUN_1407cb9c0("grade", nGrade);
        item.FUN_1407cba60("icon", pAchieve->GetName(0));
        item.FUN_1407cb9c0("complete", bComplete);
        MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
        if ((spGrade.operator CAchieveGradeData*() ? true : false) && spGrade->m_reward.m_nType != 0 && !m_190) {
            int nChecked = 0;
            if (m_198.Lookup(spGrade->m_reward.m_nType, nChecked))
                item.FUN_1407cb9c0("checked", nChecked);
        }
        list.PushObj(item);
    }
    rRow.FUN_1409eb1d0("clearAchieve", list);
}

// @0x1418ac320
int UIAchieveDialog::FUN_1418ac320(int nId)
{
    MS2Ptr<CAchieveData> spData = GetAchieveData(nId);
    if (spData.IsNull())
        return -1;
    CAchieveCategory::List roots;
    CAchieveCategory::GetRows(roots);
    int nTab = 0;
    for (size_t i = 0; i < roots.GetCount(); i++) {
        MS2Ptr<CAchieveCategory> spRoot = roots[i];
        if (spRoot->Matches(nId))
            return nTab;
        nTab++;
    }
    return -1;
}

// @0x1418ac480
int UIAchieveDialog::GetFilterIndex()
{
    if (MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy")) {
        if (MS2Ptr<ASDropdownMenu> spFilter = spHero->GetDropdownMenu("m_filter")) {
            return spFilter->GetVisible() ? spFilter->GetSelectedIndex() : 4;
        }
    }
    return 4;
}

// @0x1418ac5f0
void UIAchieveDialog::SetFilterIndex(int nIndex)
{
    if (MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy")) {
        if (MS2Ptr<ASDropdownMenu> spFilter = spHero->GetDropdownMenu("m_filter"))
            spFilter->SetSelectedIndex(nIndex);
    }
}

// @0x1418ac710
void UIAchieveDialog::ApplyTabIndex(int nTab)
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    m_30.operator->()->Invoke("setTabIndex", m_178);
}

// @0x1418ac780
int UIAchieveDialog::IsAchieveLocked(CAchieve* pAchieve)
{
    if (((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode())
        return 0;
    if (pAchieve == 0)
        return 0;
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    if (spData->m_nLocking != 0)
        return 1;
    if (pAchieve->CheckRequire() != 0)
        return 1;
    return 0;
}

// @0x1418ac870
int UIAchieveDialog::FUN_1418ac870(CAchieve* pAchieve)
{
    if (IsAchieveLocked(pAchieve) == 0)
        return 0;
    if (pAchieve->GetState() == 3)
        return 1;
    if (pAchieve->CanRewardData68() != 0)
        return 1;
    if (pAchieve->CanRewardRequire() != 0)
        return 1;
    return 0;
}

// @0x1418ac8f0
int UIAchieveDialog::FUN_1418ac8f0(CAchieve* pAchieve)
{
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    if (pAchieve->GetRewardCount() != 0)
        return 0;
    if (pAchieve->GetState() == 3)
        return 2;
    if (FUN_1418ac870(pAchieve) != 0)
        return 2;
    return 1;
}

// @0x1418ac9e0
int UIAchieveDialog::FUN_1418ac9e0()
{
    if (MS2Ptr<ASScrollingList> spTabs = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_tabList"))
        return spTabs->GetSelectedIndex();
    return 0;
}

// @0x1418aca90
int UIAchieveDialog::FUN_1418aca90(CAchieve* pAchieve)
{
    if (pAchieve->IsGradeReached() != 0)
        return 0;
    if (FUN_1418ac870(pAchieve) != 0)
        return 1;
    if (pAchieve->GetValue80() < 1)
        return 0;
    return 1;
}

// @0x1418acaf0
int UIAchieveDialog::FUN_1418acaf0()
{
    if (MS2Ptr<ASGameEntity> spHero = reinterpret_cast<Unk_ReportDialogAccess*>(this)->GetChild<ASGameEntity>("m_heroTrophy")) {
        if (MS2Ptr<ASDropdownMenu> spFilter = spHero->GetDropdownMenu("m_filter")) {
            if (!spFilter->GetVisible())
                return 0;
            if (spFilter->GetSelectedIndex() != 0)
                return 0;
            return 1;
        }
    }
    return 0;
}

// @0x1418acca0
int UIAchieveDialog::FUN_1418acca0(int nId)
{
    int nExpanded = 0;
    m_1e0.Lookup(nId, nExpanded);
    return nExpanded;
}

// @0x1418acce0
int UIAchieveDialog::FUN_1418acce0(CAchieve* pAchieve)
{
    if (pAchieve->GetState() == 3)
        return 0;
    return 0;
}

// @0x1418acd10
int UIAchieveDialog::FUN_1418acd10(int nId)
{
    MS2Ptr<CAchieve> spAchieve = ((class CAchieveManager*)FUN_1406c7600())->Find(nId);
    if (spAchieve.IsNull())
        return 0;
    __int64 nProgress = spAchieve->GetProgress();
    __int64 nGoal = spAchieve->GetGradeGoal(spAchieve->GetStartGrade());
    if (nProgress >= nGoal)
        return 0;
    return 1;
}

// @0x1418ace00
int UIAchieveDialog::FUN_1418ace00(CAchieve* pAchieve, const CStringW& strSearch, const FilterOptions* pOptions)
{
    if (pAchieve == 0)
        return 0;
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    int nState = pAchieve->GetState();
    if (FUN_1418ac870(pAchieve) != 0)
        nState = 3;
    if (pAchieve->GetType() == 8) {
        if (!((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode())
            return 0;
    }
    if (!m_190) {
        int bAny = 0;
        for (int nGrade = spData->m_nFirstGrade; nGrade <= spData->m_nMaxGrade; nGrade++) {
            MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
            if (spGrade.IsNull())
                continue;
            int bShown = 0;
            m_198.Lookup(spGrade->m_reward.m_nType, bShown);
            if (bShown != 0) {
                bAny = 1;
                break;
            }
        }
        if (bAny == 0)
            return 0;
    }
    if (pOptions->m_survival != 0) {
        if (spData->m_nType != 9)
            return 0;
        if (pAchieve->IsGradeReached() == 0 && nState != 3) {
            if (!((class CInputKeyHandler*)(void*)(FUN_14025e7c0()))->IsDebugMode())
                return 0;
        }
    }
    else {
        if (spData->m_nType == 9)
            return 0;
    }
    if (pOptions->m_categoryTag.GetLength() != 0) {
        if (spData->m_strCategoryTag.Find(pOptions->m_categoryTag, 0) == -1)
            return 0;
    }
    if (pOptions->m_contentsTag.GetLength() != 0) {
        if (spData->m_strContentsTag.Find(pOptions->m_contentsTag, 0) == -1)
            return 0;
    }
    switch (pOptions->m_filter) {
    case 1:
        if (nState != 2 || pAchieve->IsStarted() == 0)
            return 0;
        break;
    case 2:
        if (nState != 3)
            return 0;
        break;
    case 3:
        if (pAchieve->GetBookmark() == 0)
            return 0;
        break;
    }
    if (strSearch.GetLength() != 0) {
        CStringW strTitle = FUN_14093b970(pAchieve->GetId());
        CStringW strDesc = FUN_1418aabd0(pAchieve);
        CStringW strExtra = FUN_14093cdb0(pAchieve->GetId());
        FUN_14083d2b0(strTitle);
        FUN_14083d2b0(strDesc);
        FUN_14083d2b0(strExtra);
        if (FUN_14083fec0(strTitle, strSearch) == -1
            && FUN_14083fec0(strDesc, strSearch) == -1
            && FUN_14083fec0(strExtra, strSearch) == -1)
            return 0;
    }
    if (IsAchieveLocked(pAchieve) != 0 && FUN_1418ac870(pAchieve) == 0)
        return 0;
    return 1;
}

// @0x1418ad560
int UIAchieveDialog::FUN_1418ad560(int nCondType)
{
    switch (nCondType) {
    case 0x3b:
    case 8:
    case 10:
    case 0x31:
    case 0xc5:
    case 0xd1:
    case 0x10a:
        return 1;
    }
    return 0;
}

// @0x1418ad5d0
CStringW UIAchieveDialog::FUN_1418ad5d0(int nCondType, __int64 nId)
{
    switch (nCondType) {
    case 8:
    case 10:
        return TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nId);
    case 0x3b:
    case 0x31:
        return FUN_1416e4df0(nId);
    case 0xd1:
        return FUN_14028dfa0(CStringW(L"s_achieve_collectiong_fish_collect"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x1d, nId));
    case 0x10a:
        return FUN_14028dfa0(CStringW(L"s_achieve_collectiong_pet_collect"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x3b, nId));
    case 0xc5: {
        DungeonRoomPtr spRoom = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(nId);
        if (spRoom.get() != 0)
            return FUN_14028dfa0(CStringW(L"s_achieve_collectiong_dungeon_clear"), TranslateEnumDungeonGroup(spRoom->m_groupType),
                                 TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x14, nId));
    }
        break;
    }
    return CStringW(L"");
}

// @0x1418ad960
int UIAchieveDialog::FUN_1418ad960(int nCondType, __int64 nId)
{
    switch (nCondType) {
    case 8:
    case 10:
        return DAT_143ab30e0.Lookup(nId) != 0;
    case 0x3b:
    case 0x31:
        return reinterpret_cast<CQuestManagerCommon*>(((struct Unk_AcQuestMgr*)FUN_140764020())->m_10)->FUN_140745590(nId);
    case 0xd1:
        return TSingleton<CFishingManager>::GetInstance()->FUN_140cdc380(nId);
    case 0x10a:
        return reinterpret_cast<CPetManager*>(FUN_140535320())->GetCountByKey(nId) != 0;
    case 0xc5: {
        return FUN_140931510()->GetRecord()->GetRoomValue5c(nId) != 0;
    }
    }
    return 0;
}

// @0x1418adae0
static void AcCollectClears(std::vector<UIAchieveDialog::ClearRecord>& rRecords)
{
    CAchieveList achieves;
    ((class CAchieveManager*)FUN_1406c7600())->GetFirstList(achieves);
    for (size_t i = 0; i < achieves.GetCount(); i++) {
        MS2Ptr<CAchieve> spAchieve = achieves[i];
        for (int nGrade = spAchieve->GetDataRef()->m_nFirstGrade; nGrade <= spAchieve->GetCurGrade(); nGrade++) {
            __int64 nTime = spAchieve->GetValue(nGrade);
            if (nTime == 0)
                continue;
            UIAchieveDialog::ClearRecord record;
            record.m_time = nTime;
            record.m_id = spAchieve->GetId();
            record.m_grade = nGrade;
            rRecords.push_back(record);
        }
    }
    std::sort(rRecords.begin(), rRecords.end(), AcClearOrder());
}

// @0x1418adcd0
static ATL::CAtlArray<__int64>* AcCollectedIds(CAchieve* pAchieve)
{
    MS2Ptr<CAchieveData> spData = pAchieve->GetDataRef();
    if (spData.IsNull())
        return 0;
    int nGrade = pAchieve->GetCurGrade();
    MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
    if (spGrade.IsNull())
        return 0;
    return &spGrade->m_pCondition->m_code.m_ids;
}

// @0x1418adea0
Scaleform::GFx::Value ASGameEntity::FUN_1418adea0(const char* szMethod, unsigned char nIndex, const ASObj& row)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bccb0(&args[0], nIndex);
    FUN_1422bce40(&args[1], row);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1418ae010
static void FUN_1418ae010(ASObj& rObj, const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&static_cast<Unk_AcObjView&>(rObj).m_value))->SetMember(szName, data.PopValue());
}

// @0x1418adf60
void AScript::FUN_1418adf60(const char* szName, AScript obj)
{
    ASData data;
    data.AddValue(obj.FUN_1422bb890());
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbc7e0-0x142cbc890 .text$yd
