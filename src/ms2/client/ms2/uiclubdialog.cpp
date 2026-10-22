// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uiclubdialog.h.
// MS2-UNIT: client\ms2\uiclubdialog.cpp
// MS2-RANGE: 0x1400d7230-0x1400d72c0 .text$di
// MS2-RANGE: 0x140e0aa10-0x140e0da60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??B?$MS2Ptr@VUnk_ClubMap@@@@QEBAPEAVUnk_ClubMap@@XZ 0x140e0d860 ; unique
// MS2-PIN: ??B?$MS2Ptr@VCClubMember@@@@QEBAPEAVCClubMember@@XZ 0x140e0d870 ; unique
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiclubdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uiclubdialog.h"

#include <atltime.h>

#include "ms2/commonfiles/clubcommon.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
// clubcli.cpp owns the (non-inline) CClubCli specializations at 0x140b1cda0 / 0x140b1cfa0; call them instead of instantiating.
class CClubCli;
template<> void MS2Ptr<CClubCli>::AddRef() const;
template<> void MS2Ptr<CClubCli>::Release();

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----

// The message box record (MS2Ptr<CMsgBoxData> members are bound to the exe copies in symbols.tsv).
class CMsgBoxData : public CPtred
{
public:
    CStringW FUN_141a02d50() const;                                     // the input text
    void SetExtra(const CStringW& strTag);                         // tag
    void FUN_141a01800(int n);
    void FUN_141a01d30(int nMode, const CStringW& strDefault, unsigned nMax, int a4, int a5);   // input box setup
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);     // result callback
    void FUN_141a02880(int nBuffId, unsigned short nLevel, CStringW strName);   // club buff description
};
extern template class MS2Ptr<CMsgBoxData>;

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

// The club manager (global 0x143abad48): the joined clubs and the server requests.
class Unk_ClubMap : public CPtred
{
public:
    POSITION FUN_140b1a4c0();                                           // head position
    const __int64& FUN_140b1a4f0(POSITION pos);                         // key (club serial number)
    MS2Ptr<CClubCli>& FUN_140b1a590(POSITION pos);                      // value
    void FUN_140b1a550(POSITION& pos);                                  // next
    int FUN_140b1a4a0();                                                // count
};
class Unk_ClubManager
{
public:
    MS2Ptr<CClubCli> FUN_140b14d80(__int64 nClubId);
    MS2Ptr<Unk_ClubMap> FUN_140b14e40();
    int FUN_140b15310();                                                // 1 when a club is joined
    void FUN_140b160c0(__int64 nClubId, CStringW strName);              // add member request
    void FUN_140b16270(__int64 nClubId);                                // withdrawal request
    void FUN_140b163c0(__int64 nClubId, int nBuffId, int nLevel);       // buff setting request
    void FUN_140b16450(__int64 nClubId, CStringW strName);              // rename request
};
extern Unk_ClubManager* DAT_143abad48;
inline Unk_ClubManager* FUN_140e0d900() { return DAT_143abad48; }

// A club buff record: the buff id and its level.
class Unk_ClubBuffData : public CPtred
{
public:
    int m_pad_18; int m_pad_1c; int m_pad_20; int m_pad_24;
    int m_nBuffId;                                                      // +0x28
    int m_nLevel;                                                       // +0x2c
};
class Unk_ClubBuffTable
{
public:
    MS2Ptr<Unk_ClubBuffData> FUN_140211a40();                           // the default buff
    MS2Ptr<Unk_ClubBuffData> FUN_1402116a0(int nId);
};
Unk_ClubBuffTable* FUN_140b1a4e0();

class Unk_ClubStrings
{
public:
    CStringW FUN_141811980(int nTable, int nId);
    CStringW FUN_141812290(int nBuffId, unsigned short nLevel, CString strKey);
};
Unk_ClubStrings* FUN_1401a9d70();

class Unk_ClubSession { public: CStringW FUN_141bd0d30(); };            // my character name
Unk_ClubSession* FUN_1403ed2d0();

class Unk_ClubFlag { public: int FUN_1402c4c90(int nFlag); };
class Unk_ClubState { public: void* m_pad_00; Unk_ClubFlag m_flags; };
Unk_ClubState* FUN_14025e7b0();
void FUN_141275260(int nMsgId, int a2, int a3);

class Unk_ClubConstInt { public: int m_n; };
class Unk_ClubConsts { public: char m_pad[0x9e68]; Unk_ClubConstInt m_nameChange; };
Unk_ClubConsts* FUN_1401d3200();
int* FUN_1402056b0(Unk_ClubConstInt* p);

// The list control of the swf (a CPtred-derived AS wrapper with a slot table).
class Unk_ClubList : public CPtred
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    virtual void vfunc_25(const Scaleform::GFx::Value& data);           // set the data provider
    void FUN_1422dd1d0();                                               // clear
    void FUN_1422dcca0(int nIndex);                                     // select
};
// The movie clip holding the lists.
class Unk_ClubClip : public CPtred
{
public:
    MS2Ptr<Unk_ClubList> FUN_140bc7280(const CString& strName);
};

// The AS array (ctor 0x1422deec0, dtor 0x1422df070) of the row objects.
class Unk_ClubArray : public AScript
{
public:
    Unk_ClubArray(int nType);
    virtual ~Unk_ClubArray();
    bool FUN_1422bc050(Scaleform::GFx::Value v);                        // push
};

// The popup menu parameters (0x88 bytes; ctor 0x140c302f0, dtor 0x140c304c0 called as members).
class Unk_ClubPopup
{
public:
    void FUN_140c302f0(float x, float y, int nKind, int nMenuId, int a5, CString strKey, void* p);
    void FUN_140c304c0();
    char m_pad[0x88];
};
MS2_CHECK_SIZE(Unk_ClubPopup, 0x88);
class Unk_ClubPopupDialog { public: void FUN_141a80210(const Unk_ClubPopup& params, CClubMember* pMember); };
Unk_ClubPopupDialog* FUN_140c30140(int nType);


// The skill-attribute record behind a club buff icon (CPtred + 0xa8 bytes, then the icon path at +0xc0).
class Unk_ClubSkillAttr : public CPtred
{
public:
    char m_pad_18[0xa8];
    CString m_strIcon;                                                  // +0xc0
    CString FUN_1401756c0();                                            // copy of the icon path
};
MS2_CHECK_OFFSET(Unk_ClubSkillAttr, m_strIcon, 0xc0);
class Unk_ClubSkillTable
{
public:
    MS2Ptr<Unk_ClubSkillAttr> FUN_140aafef0(int nSkillId, unsigned short nLevel);
};
Unk_ClubSkillTable* FUN_1401958b0();

// ---- string helpers (instances living in other units; declared with their real argument lists) ----
CString FUN_140719530(__int64 n);                                       // number to text
__int64 FUN_140718350(const CString& str);                              // text to number
CStringW FUN_14028de60(int nId);                                        // string table text
CStringW FUN_140298ea0(CStringW strKey);                                // localized string by key
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a1);    // StringFormat(fmt, a1)
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a1, const int& a2);
CStringW FUN_1409e8970(CStringW strFormat, const int& a1, const int& a2);
CStringW FUN_14086cfc0(int nId, const int& n);
CStringW FUN_14086d060(int nId, const __int64& n);
CStringW FUN_140a228f0(int nId, const int& n, const CStringW& str);
CString FUN_141028be0(__int64 nId, CString strPicture, int n, CString strKey);   // profile image path
__time64_t FUN_140869440();                                             // current time

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
CString UIClubDialog::vfunc_1()
{
    return "ClubDialog";
}
MS2_REPLACE_METHOD(0x140E0AAC0, UIClubDialog, vfunc_1, 61, 0x32B5C262);

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
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x31) != 0) {
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
// MS2-FUNCTIONAL: frame layout / temp slot order of the 6-way string dispatch differs from the exe
int UIClubDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("onSelectCategory", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            m_nCategory = data.FUN_1422b8a10();
            m_nClubId = FUN_140718350(data.FUN_1422b8d30());
            FUN_140e0c570(m_nClubId);
        }
        return 1;
    }
    if (_stricmp("onAddMember", szMethod) == 0) {
        MS2Ptr<CMsgBoxData> box = FUN_140d73e40(10, 0x361, 0, CStringW(L""));
        if (box.get() != 0) {
            box->FUN_141a01d30(2, CStringW(L""), 0x18, 0, 0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::FUN_140e0bcd0));
            FUN_140d73c60(box);
        }
        return 1;
    }
    if (_stricmp("onWithdrawal", szMethod) == 0) {
        MS2Ptr<CClubCli> club = FUN_140e0d900()->FUN_140b14d80(m_nClubId);
        if (club.get() != 0) {
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_1401e8510(FUN_14028de60(0x363), club->FUN_14020f1a0()), 0, CStringW(L""));
            if (box.get() != 0) {
                box->FUN_141a01800(2);
                box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::FUN_140e0bdb0));
                FUN_140d73c60(box);
            }
        }
        return 0;
    }
    if (_stricmp("onSettingBuff", szMethod) == 0) {
        MS2Ptr<CClubCli> club = FUN_140e0d900()->FUN_140b14d80(m_nClubId);
        if (club == 0)
            return 1;
        MS2Ptr<Unk_ClubBuffData> buff = FUN_140b1a4e0()->FUN_140211a40();
        int nBuffId = buff->m_nBuffId;
        unsigned short nLevel = buff->m_nLevel;
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x25, FUN_140298ea0(CStringW(L"s_club_ui_msg_buff_setting")), 0, CStringW(L""));
        if (box.get() != 0) {
            box->SetExtra(s_strClubBuff);
            box->FUN_141a01800(2);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::FUN_140e0be00));
            if (club->FUN_14020f640() == 0) {
                box->FUN_141a02880(nBuffId, nLevel, FUN_1401a9d70()->FUN_141812290(nBuffId, nLevel, CString("name")));
            } else {
                FUN_1401a9d70()->FUN_141812290(club->FUN_14020f640(), club->FUN_14020f6b0() & 0xffff, CString("name"));
                box->FUN_141a02880(club->FUN_14020f640(), club->FUN_14020f6b0() & 0xffff,
                                   FUN_1401a9d70()->FUN_141812290(club->FUN_14020f640(), club->FUN_14020f6b0() & 0xffff, CString("name")));
            }
            FUN_140d73c60(box);
        }
        return 0;
    }
    if (_stricmp("onNameChange", szMethod) == 0) {
        int nCost = *FUN_1402056b0(&FUN_1401d3200()->m_nameChange);
        int nHalf = nCost / 2;
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(10, FUN_1409e8970(CStringW(L"s_party_change_name"), nHalf, nCost), 0, CStringW(L""));
        if (box.get() != 0) {
            box->FUN_141a01d30(2, CStringW(L""), nCost, 0, 0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIClubDialog::FUN_140e0bef0));
            FUN_140d73c60(box);
        }
        return 0;
    }
    if (_stricmp("OnClubMemberPopupMenu", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            float x = data.FUN_1422b8c10();
            float y = data.FUN_1422b8c10();
            CStringW strName = data.FUN_1422b8f40();
            MS2Ptr<CClubCli> club = FUN_140e0d900()->FUN_140b14d80(m_nClubId);
            if (club.get() != 0) {
                MS2Ptr<CClubMember> member = club->FUN_140210560(strName);
                if (member.get() != 0) {
                    Unk_ClubPopupDialog* pPopup = FUN_140c30140(0x4e39);
                    if (pPopup != 0) {
                        Unk_ClubPopup params;
                        params.FUN_140c302f0(x, y, 3, 0x63de, 1, CString(""), 0);
                        pPopup->FUN_141a80210(params, member);
                        params.FUN_140c304c0();
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

// @0x140e0bc30
void UIClubDialog::FUN_140e0bc30()
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
MS2_REPLACE_METHOD(0x140E0BC30, UIClubDialog, FUN_140e0bc30, 140, 0xDA87C57B);

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
    FUN_140e0d900()->FUN_140b16270(m_nClubId);
    return true;
}
MS2_REPLACE_METHOD(0x140E0BDB0, UIClubDialog, FUN_140e0bdb0, 61, 0x7B7F7ED9);

// @0x140e0be00
bool UIClubDialog::FUN_140e0be00(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    {
        int nId = _wtoi(data.FUN_141a02d50());
        MS2Ptr<Unk_ClubBuffData> spBuff = FUN_140b1a4e0()->FUN_1402116a0(nId);
        if (spBuff != 0)
            FUN_140e0d900()->FUN_140b163c0(m_nClubId, spBuff->m_nBuffId, spBuff->m_nLevel);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140E0BE00, UIClubDialog, FUN_140e0be00, 229, 0xCF3E7CF4);

// @0x140e0bef0
bool UIClubDialog::FUN_140e0bef0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    CStringW strName = data.FUN_141a02d50();
    strName.Trim(L",");
    if (strName.IsEmpty())
        return false;
    FUN_140e0d900()->FUN_140b16450(m_nClubId, strName);
    return true;
}
MS2_REPLACE_METHOD(0x140E0BEF0, UIClubDialog, FUN_140e0bef0, 217, 0x8D1F2157);

// @0x140e0bfd0
// MS2-FUNCTIONAL: the exe spills the MS2Ptr return into an extra local; CString temp and frame slots differ
void UIClubDialog::FUN_140e0bfd0()
{
    MS2Ptr<Unk_ClubMap> spMap = FUN_140e0d900()->FUN_140b14e40();
    if (spMap != 0) {
        {
            MS2Ptr<Unk_ClubList> spList = FUN_140c02900(CString("m_category"));
            if (spList.get() != 0) {
                spList->FUN_1422dcca0(-1);
                spList->FUN_1422dd1d0();
                Unk_ClubArray rows(2);
                CStringW strMyName = FUN_1403ed2d0()->FUN_141bd0d30();
                POSITION pos = spMap->FUN_140b1a4c0();
                while (pos != 0) {
                    __int64 nClubSN = spMap->FUN_140b1a4f0(pos);
                    MS2Ptr<CClubCli> spClub = spMap->FUN_140b1a590(pos);
                    if (!(spClub == 0)) {
                        ASObj row(2);
                        row.FUN_1407cba60("clubSN", FUN_140719530(nClubSN));
                        row.FUN_1407cb9c0("master", spClub->FUN_140211080(CStringW(strMyName)));
                        row.FUN_1407cbb20("label", spClub->FUN_14020f1a0());
                        int nMax = 10;
                        int nCount = spClub->FUN_140210df0();
                        row.FUN_1407cbb20("memberCount", FUN_14083dc40(FUN_14028de60(0x367), nCount, nMax));
                        unsigned nLevel = spClub->FUN_14020f6b0();
                        FUN_140e0d180(row, spClub->FUN_14020f640(), nLevel & 0xffff);
                        FUN_140e0d230(row, spClub->FUN_14020f460());
                        rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
                    }
                    spMap->FUN_140b1a550(pos);
                }
                spList->vfunc_25(rows.FUN_1422bb870());
                spList->vfunc_24(true);
                if (spMap->FUN_140b1a4a0() <= m_nCategory)
                    m_nCategory = 0;
                spList->FUN_1422dcca0(m_nCategory);
            }
        }
        if (m_30.get() != 0)
            m_30->Invoke("showData", true);
    }
}

// @0x140e0c570
// MS2-FUNCTIONAL: the exe spills the MS2Ptr return into an extra local; CString temp and frame slots differ
void UIClubDialog::FUN_140e0c570(__int64 nClubId)
{
    MS2Ptr<CClubCli> spClub = FUN_140e0d900()->FUN_140b14d80(nClubId);
    if (spClub.get() != 0) {
        MS2Ptr<Unk_ClubClip> spClip = FUN_140ba7930(CString("m_clubData"));
        if (spClip == 0)
            return;
        MS2Ptr<Unk_ClubList> spList = spClip->FUN_140bc7280(CString("m_items"));
        if (spList.get() != 0) {
            spList->FUN_1422dd1d0();
            Unk_ClubArray rows(2);
            MS2Ptr<CClubMember> spLeader = spClub->FUN_140210f70();
            if (spLeader.get() != 0) {
                ASObj row(2);
                row.FUN_1407cbbe0("master", true);
                FUN_140e0ca20(row, spLeader);
                rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
            }
            ATL::CAtlArray<MS2Ptr<CClubMember> > members;
            spClub->FUN_1402109d0(members);
            for (size_t i = 0; i < members.GetCount(); ++i) {
                if (spClub->FUN_140211080(members[i]->m_info.FUN_14020e5d0()) == 0) {
                    ASObj row(2);
                    row.FUN_1407cbbe0("master", false);
                    FUN_140e0ca20(row, members[i]);
                    rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
                }
            }
            spList->vfunc_25(rows.FUN_1422bb870());
            spList->vfunc_24(true);
        }
    }
}

// @0x140e0ca20
// MS2-FUNCTIONAL: CTimeSpan span helpers are out-of-line calls in the exe; temp slots differ
void UIClubDialog::FUN_140e0ca20(ASObj& row, MS2Ptr<CClubMember> spMember)
{
    row.FUN_1407cbb20("name", spMember->m_info.FUN_14020e5d0());
    CStringW strInfo = StringFormat(FUN_14028de60(0x360),
                                    reinterpret_cast<const unsigned short&>(spMember->m_info.m_level),
                                    FUN_1401a9d70()->FUN_141811980(6, spMember->m_info.m_job));
    row.FUN_1407cbb20("info", strInfo);
    CStringW strLocation;
    CStringW strTime;
    if (spMember->m_f0 != 0) {
        ATL::CTimeSpan span = FUN_140869440() - spMember->m_d8;
        if (span.GetDays() < 1) {
            if (span.GetHours() < 1) {
                if (span.GetMinutes() < 1)
                    strTime = FUN_14028de60(0x35c);
                else
                    strTime = FUN_14086cfc0(0x35b, span.GetMinutes());
            } else {
                strTime = FUN_14086cfc0(0x35a, span.GetHours());
            }
        } else {
            strTime = FUN_14086d060(0x359, span.GetDays());
        }
        strLocation = FUN_1401e8510(FUN_14028de60(0x35e), strTime);
    } else {
        if (spMember->m_info.m_channel == 0) {
            strLocation = FUN_1401a9d70()->FUN_141811980(3, spMember->m_info.m_mapId);
        } else {
            strLocation = FUN_140a228f0(0x3d8, spMember->m_info.m_channel,
                                        FUN_1401a9d70()->FUN_141811980(3, spMember->m_info.m_mapId));
        }
    }
    row.FUN_1407cbb20("location", strLocation);
    CString strImage = FUN_141028be0(spMember->m_info.m_characterId, spMember->m_info.FUN_14020e6c0(), 1, CString(""));
    row.FUN_1407cba60("profileImage", strImage);
    row.FUN_1407cb9c0("offline", spMember->m_f0);
}

// @0x140e0d180
void UIClubDialog::FUN_140e0d180(ASObj& row, int nBuffId, unsigned short nLevel)
{
    MS2Ptr<Unk_ClubSkillAttr> spAttr = FUN_1401958b0()->FUN_140aafef0(nBuffId, nLevel);
    if (spAttr.get() != 0)
        row.FUN_1407cba60("buffIcon", spAttr->FUN_1401756c0());
}
MS2_REPLACE_METHOD(0x140E0D180, UIClubDialog, FUN_140e0d180, 155, 0x66BCF20D);

// @0x140e0d230
void UIClubDialog::FUN_140e0d230(ASObj& row, __int64 nNameChangeTime)
{
    __int64 nNow = FUN_140869440();
    if (nNow > nNameChangeTime)
        row.FUN_1407cb9c0("nameChange", 1);
    else
        row.FUN_1407cb9c0("nameChange", 0);
}
MS2_REPLACE_METHOD(0x140E0D230, UIClubDialog, FUN_140e0d230, 91, 0x3A2471AF);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca62f0-0x142ca6350 .text$yd
