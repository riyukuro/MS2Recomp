// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's translateenum.cpp: the dungeon-group enum
// translator, plus the CToolBlockFileModifyDialog that sits in front of it in the exe (probably a separate file whose
// boundary the unit map merged). See translateenum.h.
// MS2-UNIT: client\ms2\translateenum.cpp
// MS2-RANGE: 0x140cbf600-0x140cbfd50 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\translateenum.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "translateenum.h"

#include "hook/ms2hook.h"

CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
void FUN_141821bf0(CString strFirst, CString strSecond);                    // block-file modifier

IMPLEMENT_DYNAMIC(CToolBlockFileModifyDialog, CDialogEx)

// @0x140cbf620
CToolBlockFileModifyDialog::CToolBlockFileModifyDialog(CWnd* pParent) : CDialogEx(0xa2, pParent)
{
}

// @0x140cbf670
CToolBlockFileModifyDialog::~CToolBlockFileModifyDialog()
{
}

// @0x140cbf6a0
void CToolBlockFileModifyDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CToolBlockFileModifyDialog, CDialogEx)
END_MESSAGE_MAP()

// @0x140cbf700
void CToolBlockFileModifyDialog::OnBnClickedOk()
{
    CString strFirst;
    GetDlgItemText(0x4f0, strFirst);
    CString strSecond;
    GetDlgItemText(0x470, strSecond);
    FUN_141821bf0(strFirst, strSecond);
    CDialog::OnOK();
}

// @0x140cbf840
// MS2-FUNCTIONAL: exe has no NRVO flag and a shared epilogue (1288 bytes); every return-in-switch spelling tried adds the flag
CStringW TranslateEnumDungeonGroup(unsigned int nGroup)
{
    switch (nGroup)
    {
    case 0:
        return CStringW();
    case 1:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_normal"));
    case 2:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_raid"));
    case 3:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_chaosRaid"));
    case 4:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_reverseRaid"));
    case 5:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_lapenta"));
    case 6:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_guildRaid"));
    case 7:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_darkStream"));
    case 8:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_worldBoss"));
    case 9:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_item"));
    case 10:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_vip"));
    case 11:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_event"));
    case 12:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_fameChallenge"));
    case 13:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_colosseum"));
    case 14:
        return GetStringCommonByKey(CStringW(L"s_enum_dungeon_group_turka"));
    default:
        ASSERT(0);
        return CStringW();
    }
}
