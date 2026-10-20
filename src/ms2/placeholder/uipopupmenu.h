// uipopupmenu.h - PLACEHOLDER for UIPopUpMenu (RTTI .?AVUIPopUpMenu@@, the right click menu, UI id 0x4e39) and its
// stack request Unk_PopupMenuInfo. NOT an original header.
// The full class is being recovered in ms2/client/ms2/uipartydialog.h; this placeholder only declares the
// non-virtual entry points other units call (same signatures, so the mangled names agree) and does NOT give the
// class layout. Do not include it together with uipartydialog.h.
// Callers reach the menu as (UIPopUpMenu*)FUN_140c30140(0x4e39).
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"

class UIDialog;

UIDialog* FUN_140c30140(int nDialogId);                     // the open dialog of this id

// The menu request (callers build it on the stack). ctor 0x140c302f0, dtor 0x140c304c0.
// Copied from uipartydialog.h (keep the two in sync).
class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);   // 0x140c302f0
    ~Unk_PopupMenuInfo() {}                                         // 0x140c304c0
    struct Unk_PmA                                                  // ctor 0x140c30440, dtor 0x140c30550
    {
        Unk_PmA() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(0) {}
        __int64 m_00; __int64 m_08; CStringW m_10; int m_18; __int64 m_20;
    };
    struct Unk_PmB                                                  // ctor 0x140c303c0, dtor 0x140c30510
    {
        Unk_PmB() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(L"") {}
        __int64 m_00; int m_08; CStringW m_10; __int64 m_18; CStringW m_20;
        __int64 m_28;                                                 // not set by the ctor
    };
    float m_x, m_y;
    int m_a, m_b, m_c;
    CString m_str;
    void* m_p;
    Unk_PmA m_infoA;
    Unk_PmB m_infoB;
};
MS2_CHECK_SIZE(Unk_PopupMenuInfo, 0x80);

class UIPopUpMenu
{
public:
    void FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nCharId, void* pAccount, int nType, int nDir);
    void FUN_141a80910();                                       // copy the own guild
    void FUN_141a809e0(__int64 nGuildId, const CStringW& strGuild, const CString& strMark);
    void FUN_141a7f510(const Unk_PopupMenuInfo& info, class CGuildMember* pMember);   // the guild member menu (uiguilddialog.cpp)
};
