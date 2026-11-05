// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uiclubdialog.h.
// MS2-UNIT: client\ms2\uiclubdialog.cpp
// MS2-RANGE: 0x1400d7230-0x1400d72c0 .text$di
// MS2-RANGE: 0x140e0aa10-0x140e0da60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??B?$Unk_SocketPtr@V?$CRBMap@_KV?$MS2Ptr@VCClubCli@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCClubCli@@@@@3@@ATL@@@@QEBAPEAV?$CRBMap@_KV?$MS2Ptr@VCClubCli@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$MS2Ptr@VCClubCli@@@@@3@@ATL@@XZ 0x140e0d860 ; unique
// MS2-PIN: ??B?$MS2Ptr@VCClubMember@@@@QEBAPEAVCClubMember@@XZ 0x140e0d870 ; unique
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiclubdialog.cpp"
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"

#include "uiclubdialog.h"

#include <atltime.h>

#include "ms2/commonfiles/clubcommon.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uipopupmenu.h"
// clubcli.cpp owns the (non-inline) CClubCli specializations at 0x140b1cda0 / 0x140b1cfa0; call them instead of instantiating.
class CClubCli;
template<> void MS2Ptr<CClubCli>::AddRef() const;
template<> void MS2Ptr<CClubCli>::Release();

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/clubcli.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // C3: AdditionalLevelData
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include "ms2/commonfiles/contentshutdown.h"

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);   // 0x140ba7930, owned by unit_140ba6b20

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----

// The message box record (MS2Ptr<CMsgBoxData> members are bound to the exe copies in symbols.tsv).
class CMsgBoxData : public CPtred
{
public:
    CStringW FUN_141a02d50() const;                                     // the input text
    void SetExtra(const CStringW& strTag);                         // tag
    void FUN_141a01800(int n);
    void SetInput(int nMode, const CStringW& strDefault, unsigned int nMax, int a4, int a5);    // input box setup (0x141a01d30)
    void SetCallback(Delegate<bool(int, const CMsgBoxData&)> cb);     // result callback
    void SetBuff(int nBuffId, short nLevel, CStringW strName);         // club buff description
};
extern template class MS2Ptr<CMsgBoxData>;

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

// The club manager (global 0x143abad48): the joined clubs and the server requests.
class Unk_ClubManager : public CClubClientManager
{
public:
};
class CClubClientManager;
inline Unk_ClubManager* FUN_140e0d900() { return reinterpret_cast<Unk_ClubManager*>(TSingleton<CClubClientManager>::s_instance); }

CClubDataTable* FUN_140b1a4e0();   // the CClubDataTable instance

            // my character name

class Unk_ClubState { public: void* m_pad_00; CContentShutdown m_flags; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
void FUN_141275260(int nMsgId, int a2, int a3);

class Unk_ClubConstInt { public: int m_n; };
class Unk_ClubConsts { public: char m_pad[0x9e68]; Unk_ClubConstInt m_nameChange; };
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200




// ---- string helpers (instances living in other units; declared with their real argument lists) ----
CString FUN_140719530(unsigned __int64 n);                                       // number to text
unsigned __int64 FUN_140718350(const CString& str);                              // text to number
CStringW GetStringCommon(int nId);                                        // string table text
CStringW FUN_140298ea0(CStringW strKey);                                // localized string by key
template <class A1, class A2> CStringW FUN_14028dfa0(CStringW strKey, const A1& a1, const A2& a2);   // wcformat.h's key formatter
template <class A> CStringW FormatStringId(int nId, const A& a);
template <class A1, class A2> CStringW FUN_14028dee0(int nId, const A1& a1, const A2& a2);   // the string-id formatter (formatstringid.h)
CString FUN_141028be0(__int64 nId, const CString& strPicture, int n, CString strKey);   // profile image path
__time64_t GetServerTime();                                             // current time

// ---- statics ----
// @0x1400d7230
static CStringW s_strClubBuff(L"clubbuff");
// @0x1400d7260
static CString s_strSkill("skill");
// @0x1400d7290
static CString s_strStun("stun");

// @0x140e0aa10
UIClubDialog::UIClubDialog()
{
    m_nClubId = 0;
    m_nCategory = 0;
}

// @0x140e0aa80
UIClubDialog::~UIClubDialog()
{
}

// @0x140e0aac0
CString UIClubDialog::GetTypeName()
{
    return "ClubDialog";
}
MS2_REPLACE_METHOD(0x140E0AAC0, UIClubDialog, GetTypeName, 61, 0x32B5C262);

// @0x140e0ab10
int UIClubDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140E0AB10, UIClubDialog, vfunc_65, 37, 0xE93A055A);

// @0x140e0ab40
void UIClubDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x140E0AB40, UIClubDialog, vfunc_67, 24, 0x3BE63D56);

// @0x140e0ab60
void UIClubDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}
MS2_REPLACE_METHOD(0x140E0AB60, UIClubDialog, vfunc_26, 24, 0x250F3EDA);

// @0x140e0ab80
int UIClubDialog::vfunc_73()
{
    if (((class Unk_ClubState*)FUN_14025e7b0())->m_flags.Get((CContentShutdown::Content)0x31) != 0) {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    return UIDialog::vfunc_73();
}
MS2_REPLACE_METHOD(0x140E0AB80, UIClubDialog, vfunc_73, 75, 0xCBCCD4F4);

// @0x140e0abe0
void UIClubDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419260d0("m_webGuideButton", 0);
    if (FUN_140e0d900()->FUN_140b15310() != 0)
        FUN_140e0bfd0();
}
MS2_REPLACE_METHOD(0x140E0ABE0, UIClubDialog, OnLoadComplete, 102, 0x247ED296);

// @0x140e0ac50
int UIClubDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("onSelectCategory", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            m_nCategory = data.PopInt();
            m_nClubId = FUN_140718350(data.FUN_1422b8d30());
            FUN_140e0c570(m_nClubId);
        }
        return 1;
    } else if (_stricmp("onAddMember", szMethod) == 0) {
        {
            MS2Ptr<CMsgBoxData> box = FUN_140d73e40(10, 0x361, 0, CStringW(L""));
            if (box.get() != 0) {
                box->SetInput(2, L"", 0x18, 0, 0);
                box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::FUN_140e0bcd0));
                FUN_140d73c60(box);
            }
        }
        return 1;
    } else if (_stricmp("onWithdrawal", szMethod) == 0) {
        {
        MS2Ptr<CClubCli> club = FUN_140e0d900()->GetClub(m_nClubId);
        if (club.get() != 0) {
            if (MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, StringFormat<CStringW>(GetStringCommon(0x363), club->FUN_14020f1a0()), 0, CStringW(L""))) {
                box->FUN_141a01800(2);
                box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::FUN_140e0bdb0));
                FUN_140d73c60(box);
            }
        }
        }
    } else if (_stricmp("onSettingBuff", szMethod) == 0) {
        MS2Ptr<CClubCli> club = FUN_140e0d900()->GetClub(m_nClubId);
        if (club == 0)
            return 1;
        CClubDataTable::BuffPtr buff = FUN_140b1a4e0()->FUN_140211a40();
        int nBuffId = buff->m_effectId;
        unsigned short nLevel = buff->m_effectLevel;
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x25, FUN_140298ea0(CStringW(L"s_club_ui_msg_buff_setting")), 0, CStringW(L""));
        if (box.get() != 0) {
            box->SetExtra(s_strClubBuff);
            box->FUN_141a01800(2);
            box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::OnMsgBoxBuffConfirm));
            if (club->GetBuffId() != 0) {
                box->SetBuff(club->GetBuffId(), club->GetBuffLevel(),
                                   TSingleton<CStringTable>::GetInstance()->FUN_141812290(club->GetBuffId(), club->GetBuffLevel(), CString("name")));
            } else {
                box->SetBuff(nBuffId, nLevel, TSingleton<CStringTable>::GetInstance()->FUN_141812290(nBuffId, nLevel, CString("name")));
            }
            FUN_140d73c60(box);
        }
    } else if (_stricmp("onNameChange", szMethod) == 0) {
        int nCost = *reinterpret_cast<Common::Constants::Value<int>*>(&((class Unk_ClubConsts*)FUN_1401d3200())->m_nameChange)->Get();
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(10, FUN_14028dfa0<int, int>(CStringW(L"s_party_change_name"), nCost / 2, nCost), 0, CStringW(L""));
        if (box.get() != 0) {
            box->SetInput(2, L"", nCost, 0, 0);
            box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::FUN_140e0bef0));
            FUN_140d73c60(box);
        }
    } else if (_stricmp("OnClubMemberPopupMenu", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            float x = data.PopFloat();
            float y = data.PopFloat();
            CStringW strName = data.FUN_1422b8f40();
            {
                MS2Ptr<CClubCli> club = FUN_140e0d900()->GetClub(m_nClubId);
                if (club.get() != 0) {
                    MS2Ptr<CClubMember> member = club->FindMemberByName(strName);
                    if (member.get() != 0) {
                        UIPopUpMenu* pPopup = (UIPopUpMenu*)FUN_140c30140(0x4e39);
                        if (pPopup != 0) {
                            Unk_PopupMenuInfo info(x, y, 3, 0x63de, 1, CString(""), 0);
                            pPopup->PopUpMenuFromClubMember(info, member);
                        }
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

// @0x140e0bc30
void UIClubDialog::RefreshData()
{
    if (vfunc_55() != 0)
        return;
    if (FUN_140e0d900()->FUN_140b15310() != 0) {
        FUN_140e0bfd0();
    } else {
        if (m_30.get() != 0)
            m_30->Invoke("showData", false);
    }
}
MS2_REPLACE_METHOD(0x140E0BC30, UIClubDialog, RefreshData, 140, 0xDA87C57B);

// @0x140e0bcd0
bool UIClubDialog::FUN_140e0bcd0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    CStringW strName = data.FUN_141a02d50();
    strName.Trim(L",");
    if (strName.IsEmpty())
        return false;
    FUN_140e0d900()->FUN_140b160c0(m_nClubId, strName);
    return true;
}
MS2_REPLACE_METHOD(0x140E0BCD0, UIClubDialog, FUN_140e0bcd0, 217, 0x5985EA9A);

// @0x140e0bdb0
bool UIClubDialog::FUN_140e0bdb0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    FUN_140e0d900()->WithdrawFromClub(m_nClubId);
    return true;
}
MS2_REPLACE_METHOD(0x140E0BDB0, UIClubDialog, FUN_140e0bdb0, 61, 0x7B7F7ED9);

// @0x140e0be00
bool UIClubDialog::OnMsgBoxBuffConfirm(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    {
        int nId = _wtoi(data.FUN_141a02d50());
        CClubDataTable::BuffPtr spBuff = FUN_140b1a4e0()->FUN_1402116a0(nId);
        if (spBuff != 0)
            FUN_140e0d900()->FUN_140b163c0(m_nClubId, spBuff->m_effectId, spBuff->m_effectLevel);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140E0BE00, UIClubDialog, OnMsgBoxBuffConfirm, 229, 0xCF3E7CF4);

// @0x140e0bef0
bool UIClubDialog::FUN_140e0bef0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    CStringW strName = data.FUN_141a02d50();
    strName.Trim(L",");
    if (strName.IsEmpty())
        return false;
    FUN_140e0d900()->RenameClub(m_nClubId, strName);
    return true;
}
MS2_REPLACE_METHOD(0x140E0BEF0, UIClubDialog, FUN_140e0bef0, 217, 0x8D1F2157);

// @0x140e0bfd0
void UIClubDialog::FUN_140e0bfd0()
{
    Unk_SocketPtr<Unk_ClubCliMap> spMap = FUN_140e0d900()->FUN_140b14e40();
    if (spMap != 0) {
        {
            if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_category")) {
                spList->SetSelectedIndex(-1);
                spList->FUN_1422dd1d0();
                ASDataProvider rows(2);
                CStringW strMyName = WorldService::GetInstance()->FUN_141bd0d30();
                for (POSITION pos = spMap.operator->()->GetHeadPosition(); pos != 0; spMap.operator->()->GetNext(pos)) {
                    __int64 nClubSN = spMap.operator->()->GetKeyAt(pos);
                    MS2Ptr<CClubCli> spClub = spMap.operator->()->GetValueAt(pos);
                    if (spClub == 0)
                        continue;
                    ASObj row(2);
                    row.FUN_1407cba60("clubSN", FUN_140719530(nClubSN));
                    row.FUN_1407cb9c0("master", spClub->IsLeaderName(CStringW(strMyName)));
                    row.FUN_1407cbb20("label", spClub->FUN_14020f1a0());
                    row.FUN_1407cbb20("memberCount", StringFormat<int, int>(GetStringCommon(0x367), spClub->GetMemberCount(), 10));
                    SetRowBuffIcon(row, spClub->GetBuffId(), spClub->GetBuffLevel());
                    SetRowNameChange(row, spClub->GetNameChangeAvailableTime());
                    rows.PushValue(Scaleform::GFx::Value(row.FUN_1422bb870()));
                }
                spList->vfunc_25(rows.FUN_1422bb870());
                spList->vfunc_24(true);
                if (m_nCategory >= (int)spMap.operator->()->GetCount())
                    m_nCategory = 0;
                spList->SetSelectedIndex(m_nCategory);
            }
        }
        if (m_30.get() != 0)
            m_30->Invoke("showData", true);
    }
}

// @0x140e0c570
void UIClubDialog::FUN_140e0c570(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = FUN_140e0d900()->GetClub(nClubId);
    if (spClub.get() != 0) {
        MS2Ptr<ASMovieClip> spClip = GetChild<ASMovieClip>("m_clubData");
        if (spClip == 0)
            return;
        if (MS2Ptr<ASScrollingList> spList = spClip->FUN_140bc7280<ASScrollingList>("m_items")) {
            spList->FUN_1422dd1d0();
            ASDataProvider rows(2);
            MS2Ptr<CClubMember> spLeader = spClub->GetLeader();
            if (spLeader.get() != 0) {
                ASObj row(2);
                row.FUN_1407cbbe0("master", true);
                FUN_140e0ca20(row, spLeader);
                rows.PushValue(Scaleform::GFx::Value(row.FUN_1422bb870()));
            }
            ATL::CAtlArray<MS2Ptr<CClubMember> > members;
            spClub->GetAllMembers(members);
            for (size_t i = 0; i < members.GetCount(); ++i) {
                if (spClub->IsLeaderName(members[i]->m_info.GetName()) != 0)
                    continue;
                ASObj row(2);
                row.FUN_1407cbbe0("master", false);
                FUN_140e0ca20(row, members[i]);
                rows.PushValue(Scaleform::GFx::Value(row.FUN_1422bb870()));
            }
            spList->vfunc_25(rows.FUN_1422bb870());
            spList->vfunc_24(true);
        }
    }
}

// @0x140e0ca20
void UIClubDialog::FUN_140e0ca20(ASObj& row, MS2Ptr<CClubMember> spMember)
{
    row.FUN_1407cbb20("name", spMember->m_info.GetName());
    CStringW strInfo = StringFormat(GetStringCommon(0x360),
                                    reinterpret_cast<const unsigned short&>(spMember->m_info.m_level),
                                    TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, spMember->m_info.m_job));
    row.FUN_1407cbb20("info", strInfo);
    CStringW strLocation;
    CStringW strTime;
    if (spMember->m_f0 != 0) {
        __time64_t nElapsed = GetServerTime() - spMember->m_d8;
        ATL::CTimeSpan span(nElapsed);
        if (span.GetDays() > 0)
            strTime = FormatStringId<__int64>(0x359, span.GetDays());
        else if (span.GetHours() > 0)
            strTime = FormatStringId<long>(0x35a, span.GetHours());
        else if (span.GetMinutes() > 0)
            strTime = FormatStringId<long>(0x35b, span.GetMinutes());
        else
            strTime = GetStringCommon(0x35c);
        strLocation = StringFormat<CStringW>(GetStringCommon(0x35e), strTime);
    } else {
        if (spMember->m_info.m_channel == 0) {
            strLocation = TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, spMember->m_info.m_mapId);
        } else {
            strLocation = FUN_14028dee0<int, CStringW>(0x3d8, spMember->m_info.m_channel,
                                        TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, spMember->m_info.m_mapId));
        }
    }
    row.FUN_1407cbb20("location", strLocation);
    CString strImage = FUN_141028be0(spMember->m_info.m_characterId, spMember->m_info.GetPicture(), 1, CString(""));
    row.FUN_1407cba60("profileImage", strImage);
    row.FUN_1407cb9c0("offline", spMember->m_f0);
}

// @0x140e0d180
void UIClubDialog::SetRowBuffIcon(ASObj& row, int nBuffId, unsigned short nLevel)
{
    MS2Ptr<AdditionalLevelData> spAttr = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(nBuffId, nLevel);
    if (spAttr.get() != 0)
        row.FUN_1407cba60("buffIcon", spAttr->GetIcon());
}
MS2_REPLACE_METHOD(0x140E0D180, UIClubDialog, SetRowBuffIcon, 155, 0x66BCF20D);

// @0x140e0d230
void UIClubDialog::SetRowNameChange(ASObj& row, __int64 nNameChangeTime)
{
    __int64 nNow = GetServerTime();
    if (nNow > nNameChangeTime)
        row.FUN_1407cb9c0("nameChange", 1);
    else
        row.FUN_1407cb9c0("nameChange", 0);
}
MS2_REPLACE_METHOD(0x140E0D230, UIClubDialog, SetRowNameChange, 91, 0x3A2471AF);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca62f0-0x142ca6350 .text$yd
