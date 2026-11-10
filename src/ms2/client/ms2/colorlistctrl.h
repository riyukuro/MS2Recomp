// colorlistctrl.h - CColorListCtrl (RTTI .?AVCColorListCtrl@@, 0x148 bytes, CListCtrl, MFC dynamic-create): a list control of
// the tool UI that paints rows / columns / single cells in registered colours (custom draw), with optional row and column
// stripes, a "selected" shading and an automatic contrast text colour. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\colorlistctrl.cpp` (0x14109c630-0x14109eb00 .text$mn, dir client\ms2). Header name assumed;
// member names are invented from use, FUN_<va> are non-virtual members.
#pragma once
#include <afxcmn.h>
#include <vector>

#include "ms2/ms2layout.h"

// One registered colour (12 bytes): the colour, the row / column it applies to, the column of a single cell.
struct Unk_ClItem
{
    COLORREF m_clr;                                             // +0x00
    int m_nId;                                                  // +0x04 row, column or row of the cell
    int m_nSub;                                                 // +0x08 column of the cell (cells only)
};
MS2_CHECK_SIZE(Unk_ClItem, 0xc);

class CColorListCtrl : public CListCtrl
{
    DECLARE_DYNCREATE(CColorListCtrl)
public:
    CColorListCtrl();                                           // 0x14109c630
    virtual ~CColorListCtrl();                                  // 0x14109c770 (??_G 0x14109e0f0)

    int FindEntryIndex(int nId, int nKind, int nSub);            // the index of a registered colour (kind 0 row, 1 column, 2 cell), -1 if none
    COLORREF FUN_14109d0f0(COLORREF clr);                       // a contrast colour of clr
    void AddRowColor(COLORREF clr, int nRow, int bRedraw);    // 0x14109d1a0 colour a row
    void AddColumnColor(COLORREF clr, int nColumn, int bRedraw); // 0x14109d230 colour a column
    void AddCellColor(COLORREF clr, int nRow, int nColumn, int bRedraw);   // 0x14109d2c0 colour one cell
    void RemoveRowColor(int nRow);                               // 0x14109d350 drop a row colour
    void RemoveColumnColor(int nColumn);                            // 0x14109d400 drop a column colour
    void RemoveCellColor(int nRow, int nColumn);                  // 0x14109d4b0 drop a cell colour
    void FUN_14109d560(bool bEnable, COLORREF clrB, COLORREF clrA);   // 0x14109d560 checkerboard stripes
    void SetContrastText(bool bEnable);                           // 0x14109d5d0 contrast text colour
    void SetRowShade(bool bEnable, COLORREF clrOdd, COLORREF clrEven);   // 0x14109d610 row stripes
    void FUN_14109d680();                                       // 0x14109d680 drop every registered colour
    void Redraw();                                       // 0x14109d710 redraw

    afx_msg void OnLvnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult);        // 0x14109c7e0
    afx_msg void OnLvnDeleteallitems(NMHDR* pNMHDR, LRESULT* pResult);    // 0x14109ca80
    afx_msg void OnLvnInsertitem(NMHDR* pNMHDR, LRESULT* pResult);        // 0x14109caf0
    afx_msg void OnNMCustomdraw(NMHDR* pNMHDR, LRESULT* pResult);         // 0x14109cc70
    DECLARE_MESSAGE_MAP()                                       // GetMessageMap 0x14109cc50

private:
    MS2_LAYOUT_FRIEND;
    std::vector<Unk_ClItem> m_rows;                             // +0xe8 row colours
    std::vector<Unk_ClItem> m_columns;                          // +0x100 column colours
    std::vector<Unk_ClItem> m_cells;                            // +0x118 cell colours
    COLORREF m_clrStripeA;                                      // +0x130
    COLORREF m_clrStripeB;                                      // +0x134
    COLORREF m_clrOdd;                                          // +0x138
    COLORREF m_clrEven;                                         // +0x13c
    bool m_bStripes;                                            // +0x140
    bool m_bRowShade;                                           // +0x141
    bool m_bContrastText;                                       // +0x142
};
MS2_CHECK_SIZE(CColorListCtrl, 0x148);
MS2_CHECK_OFFSET(CColorListCtrl, m_rows, 0xe8);
MS2_CHECK_OFFSET(CColorListCtrl, m_cells, 0x118);
MS2_CHECK_OFFSET(CColorListCtrl, m_clrStripeA, 0x130);
MS2_CHECK_OFFSET(CColorListCtrl, m_bContrastText, 0x142);
