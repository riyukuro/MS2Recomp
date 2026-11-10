// toolcolorlistbox.h - CToolColorListBox (RTTI .?AVCToolColorListBox@@): an owner-draw MFC list box of the tool UI whose
// items carry their own background / text colour, draw flags and an optional alpha-blend. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\toolcolorlistbox.cpp` (0x141853bc0-0x141855140 .text$mn,
// dir client\ms2). Header name assumed; member names invented from use.
#pragma once
#include <afxwin.h>

#include "ms2/ms2layout.h"

// The per-item record the list keeps in the item data pointer (0x18 bytes, new'd per item).
struct Unk_ColorItem
{
    COLORREF m_clrBack;                                             // +0x00 (17000000 = the system window colour)
    COLORREF m_clrText;                                             // +0x04 (17000000 = the system window text colour)
    UINT m_nFormat8;                                                // +0x08 extra DrawText flags
    UINT m_nFormatC;                                                // +0x0c DrawText flags
    int m_bNoBlend;                                                 // +0x10 0: blend the row over the background
    int m_n14;                                                      // +0x14
};
MS2_CHECK_SIZE(Unk_ColorItem, 0x18);

// 0xf8 = CListBox (0xe8) + the self pointer + the fixed item height.
class CToolColorListBox : public CListBox
{
public:
    CToolColorListBox();                                            // 0x141854160
    virtual ~CToolColorListBox();                                   // 0x1418541c0 (??_G 0x141854dc0)

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);       // 0x1418546f0
    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);  // 0x141854b40

    int FUN_141853bc0(int nIndex);                                  // the valid list index of nIndex (-1: the current selection), else -1
    Unk_ColorItem* GetColorItem(int nIndex);                       // the item record of an index
    int FUN_1418541f0(LPCSTR pszText, COLORREF clrBack, COLORREF clrText, UINT nFormat8, UINT nFormatC, int bNoBlend, int n14);   // append
    int InsertItem(LPCSTR pszText, int nIndex, COLORREF clrBack, COLORREF clrText, UINT nFormat8, UINT nFormatC, int bNoBlend, int n14);   // insert
    int FUN_141854380(int nIndex);                                 // delete one item and its record
    void FUN_141854420();                                           // delete every item
    int FUN_141854450(COLORREF clr, int nIndex);                   // set the background colour
    int FUN_1418544c0(COLORREF clr, int nIndex);                   // set the text colour
    int FUN_141854530(UINT nFormat, int nIndex);                   // set +0xc
    int FUN_1418545a0(UINT nFormat, int nIndex);                   // set +0x8
    int FUN_141854610(int bNoBlend, int nIndex);                   // set +0x10
    int FUN_141854680(int n, int nIndex);                          // set +0x14

    afx_msg void OnDestroy();                                       // 0x141854c20
    afx_msg void OnSysColorChange();                                // 0x141854c50
    DECLARE_MESSAGE_MAP()                                           // GetMessageMap 0x141854ca0

public:
    CListBox* m_pListBox;                                           // +0xe8 (the list itself)
    int m_nItemHeight;                                              // +0xf0 0: measure from the font
};
MS2_CHECK_SIZE(CToolColorListBox, 0xf8);
MS2_CHECK_OFFSET(CToolColorListBox, m_pListBox, 0xe8);
MS2_CHECK_OFFSET(CToolColorListBox, m_nItemHeight, 0xf0);
