// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CColorListCtrl: see colorlistctrl.h. w307.
// MS2-UNIT: ?\colorlistctrl.cpp
// MS2-RANGE: 0x14109c630-0x14109eb00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\colorlistctrl.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "colorlistctrl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x14109c630
CColorListCtrl::CColorListCtrl()
{
    m_bStripes = 0;
    m_bRowShade = 0;
    m_bContrastText = 0;
}

// CColorListCtrl IMPLEMENT_DYNCREATE, spelled out in the exe's function order
// @0x14109c6c0
CRuntimeClass* PASCAL CColorListCtrl::_GetBaseClass()
{
    return RUNTIME_CLASS(CListCtrl);
}

AFX_COMDAT const CRuntimeClass CColorListCtrl::classCColorListCtrl = {
    "CColorListCtrl", sizeof(class CColorListCtrl), 0xFFFF, CColorListCtrl::CreateObject, &CColorListCtrl::_GetBaseClass, NULL, NULL };

CRuntimeClass* PASCAL CColorListCtrl::GetThisClass()
{
    return _RUNTIME_CLASS(CColorListCtrl);
}

// @0x14109c6f0
CRuntimeClass* CColorListCtrl::GetRuntimeClass() const
{
    return _RUNTIME_CLASS(CColorListCtrl);
}

// @0x14109c710
CObject* PASCAL CColorListCtrl::CreateObject()
{
    return new CColorListCtrl;
}

// @0x14109c770
CColorListCtrl::~CColorListCtrl()
{
}

// @0x14109c7e0
void CColorListCtrl::OnLvnDeleteitem(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    int nItem = pNMLV->iItem;
    for (size_t n = 0; n < m_rows.size(); ++n)
    {
        if (m_rows[n].m_nId == nItem)
        {
            m_rows.erase(m_rows.begin() + n);
            --n;
            continue;
        }
        if (m_rows[n].m_nId > nItem)
        {
            m_rows[n].m_nId--;
        }
    }
    for (size_t n = 0; n < m_cells.size(); ++n)
    {
        if (m_cells[n].m_nId == nItem)
        {
            m_cells.erase(m_cells.begin() + n);
            --n;
            continue;
        }
        if (m_cells[n].m_nId > nItem)
        {
            m_cells[n].m_nId--;
        }
    }
    *pResult = 0;
}

// @0x14109ca80
void CColorListCtrl::OnLvnDeleteallitems(NMHDR* pNMHDR, LRESULT* pResult)
{
    m_rows.clear();
    m_columns.clear();
    m_cells.clear();
    *pResult = 0;
}

// @0x14109caf0
void CColorListCtrl::OnLvnInsertitem(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    int nItem = pNMLV->iItem;
    size_t nR;
    size_t nC;
    for (nR = 0; nR < m_rows.size(); ++nR)
    {
        if (m_rows[nR].m_nId > nItem)
            m_rows[nR].m_nId++;
    }
    for (nC = 0; nC < m_cells.size(); ++nC)
    {
        if (m_cells[nC].m_nId > nItem)
            m_cells[nC].m_nId++;
    }
    *pResult = 0;
}

BEGIN_MESSAGE_MAP(CColorListCtrl, CListCtrl)
    ON_NOTIFY_REFLECT(LVN_DELETEITEM, &CColorListCtrl::OnLvnDeleteitem)
    ON_NOTIFY_REFLECT(LVN_DELETEALLITEMS, &CColorListCtrl::OnLvnDeleteallitems)
    ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CColorListCtrl::OnNMCustomdraw)
    ON_NOTIFY_REFLECT(LVN_INSERTITEM, &CColorListCtrl::OnLvnInsertitem)
END_MESSAGE_MAP()

// @0x14109cc70
void CColorListCtrl::OnNMCustomdraw(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLVCUSTOMDRAW pDraw = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
    int nRow = 0;
    int nColumn = 0;
    int nColIdx = 0;
    int nCellIdx = 0;
    int nRowIdx = 0;
    switch (pDraw->nmcd.dwDrawStage)
    {
    case CDDS_PREPAINT:
        *pResult = CDRF_NOTIFYITEMDRAW;
        break;
    case CDDS_ITEMPREPAINT:
        *pResult = CDRF_NOTIFYSUBITEMDRAW;
        break;
    case CDDS_ITEMPREPAINT | CDDS_SUBITEM:
        nRow = (int)pDraw->nmcd.dwItemSpec;
        nColumn = pDraw->iSubItem;
        if (m_bStripes)
        {
            if (nRow % 2 == 1)
            {
                if (nColumn % 2 == 0)
                    pDraw->clrTextBk = m_clrStripeA;
                else
                    pDraw->clrTextBk = m_clrStripeB;
            }
            else if (nColumn % 2 == 0)
            {
                pDraw->clrTextBk = m_clrStripeB;
            }
            else
            {
                pDraw->clrTextBk = m_clrStripeA;
            }
        }
        if (m_bRowShade)
        {
            if (nRow % 2 == 1)
                pDraw->clrTextBk = m_clrOdd;
            else
                pDraw->clrTextBk = m_clrEven;
        }
        nRowIdx = FUN_14109cf70(nRow, 0, -1);
        nColIdx = FUN_14109cf70(nColumn, 1, -1);
        nCellIdx = FUN_14109cf70(nRow, 2, nColumn);
        if (nRowIdx == -1 && nColIdx == -1 && nCellIdx == -1)
        {
            if (m_bStripes == 0 && m_bRowShade == 0)
                pDraw->clrTextBk = GetBkColor();
        }
        else if (nCellIdx != -1)
        {
            pDraw->clrTextBk = m_cells[nCellIdx].m_clr;
        }
        else if (nRowIdx != -1)
        {
            pDraw->clrTextBk = m_rows[nRowIdx].m_clr;
        }
        else
        {
            pDraw->clrTextBk = m_columns[nColIdx].m_clr;
        }
        if (m_bContrastText)
            pDraw->clrText = FUN_14109d0f0(pDraw->clrTextBk);
        *pResult = CDRF_NEWFONT;
        break;
    default:
        *pResult = 0;
        break;
    }
}

// @0x14109cf70
int CColorListCtrl::FUN_14109cf70(int nId, int nKind, int nSub)
{
    if (nKind == 0)
    {
        for (size_t n = 0; n < m_rows.size(); ++n)
        {
            if (m_rows[n].m_nId == nId)
                return (int)n;
        }
    }
    if (nKind == 1)
    {
        for (size_t n = 0; n < m_columns.size(); ++n)
        {
            if (m_columns[n].m_nId == nId)
                return (int)n;
        }
    }
    if (nKind == 2)
    {
        for (size_t n = 0; n < m_cells.size(); ++n)
        {
            if (nSub >= 0 && m_cells[n].m_nId == nId && m_cells[n].m_nSub == nSub)
                return (int)n;
        }
    }
    return -1;
}

// @0x14109d0f0
COLORREF CColorListCtrl::FUN_14109d0f0(COLORREF clr)
{
    return RGB(abs(0xdc - GetRValue(clr)), abs(0xdc - GetGValue(clr)), abs(0xdc - GetBValue(clr)));
}

// @0x14109d1a0
void CColorListCtrl::FUN_14109d1a0(COLORREF clr, int nRow, int bRedraw)
{
    Unk_ClItem item;
    item.m_clr = clr;
    item.m_nId = nRow;
    m_rows.push_back(item);
    if (bRedraw != 0)
        RedrawWindow(0, 0, 0x505);
}

// @0x14109d230
void CColorListCtrl::FUN_14109d230(COLORREF clr, int nColumn, int bRedraw)
{
    Unk_ClItem item;
    item.m_clr = clr;
    item.m_nId = nColumn;
    m_columns.push_back(item);
    if (bRedraw != 0)
        RedrawWindow(0, 0, 0x505);
}

// @0x14109d2c0
void CColorListCtrl::FUN_14109d2c0(COLORREF clr, int nRow, int nColumn, int bRedraw)
{
    Unk_ClItem item;
    item.m_clr = clr;
    item.m_nId = nRow;
    item.m_nSub = nColumn;
    m_cells.push_back(item);
    if (bRedraw != 0)
        RedrawWindow(0, 0, 0x505);
}

// @0x14109d350
void CColorListCtrl::FUN_14109d350(int nRow)
{
    int nIdx = FUN_14109cf70(nRow, 0, -1);
    if (nIdx != -1)
        m_rows.erase(m_rows.begin() + nIdx);
    RedrawWindow(0, 0, 0x505);
}

// @0x14109d400
void CColorListCtrl::FUN_14109d400(int nColumn)
{
    int nIdx = FUN_14109cf70(nColumn, 1, -1);
    if (nIdx != -1)
        m_columns.erase(m_columns.begin() + nIdx);
    RedrawWindow(0, 0, 0x505);
}

// @0x14109d4b0
void CColorListCtrl::FUN_14109d4b0(int nRow, int nColumn)
{
    int nIdx = FUN_14109cf70(nRow, 2, nColumn);
    if (nIdx != -1)
        m_cells.erase(m_cells.begin() + nIdx);
    RedrawWindow(0, 0, 0x505);
}

// @0x14109d560
void CColorListCtrl::FUN_14109d560(bool bEnable, COLORREF clrB, COLORREF clrA)
{
    m_clrStripeA = clrA;
    m_clrStripeB = clrB;
    m_bStripes = bEnable;
    RedrawWindow(0, 0, 0x505);
}

// @0x14109d5d0
void CColorListCtrl::FUN_14109d5d0(bool bEnable)
{
    m_bContrastText = bEnable;
    RedrawWindow(0, 0, 0x505);
}

// @0x14109d610
void CColorListCtrl::FUN_14109d610(bool bEnable, COLORREF clrOdd, COLORREF clrEven)
{
    m_clrOdd = clrOdd;
    m_clrEven = clrEven;
    m_bRowShade = bEnable;
    RedrawWindow(0, 0, 0x505);
}

// @0x14109d680
void CColorListCtrl::FUN_14109d680()
{
    m_rows.clear();
    m_columns.clear();
    m_cells.clear();
    m_bStripes = 0;
    m_bRowShade = 0;
    m_bContrastText = 0;
    RedrawWindow(0, 0, 0x505);
}

// @0x14109d710
void CColorListCtrl::FUN_14109d710()
{
    RedrawWindow(0, 0, 0x505);
}
