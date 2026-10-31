// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CToolColorListBox: the tool UI's owner-draw list box with a
// per-item colour record (background, text, DrawText flags, optional alpha-blended highlight). See toolcolorlistbox.h.
// MS2-UNIT: ?\toolcolorlistbox.cpp
// MS2-RANGE: 0x141853bc0-0x141855140 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolcolorlistbox.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "toolcolorlistbox.h"

#include "ms2/client/ms2/effectdummy.h"

#include "hook/ms2hook.h"

// ---- unit-local views of callees emitted in other units ----

CRect* FUN_140517a60(CRect* pRect);                     // 0x140517a60 CRect::CRect()
LPRECT FUN_14098a2a0(CRect* pRect);                     // 0x14098a2a0 CRect::operator LPRECT

// @0x141853bc0
int CToolColorListBox::FUN_141853bc0(int nIndex)
{
    if (GetCount() == 0)
        return -1;
    if (nIndex == -1)
    {
        return GetCurSel();
    }
    else
    {
        if (nIndex < 0 || nIndex >= GetCount())
            return -1;
        else
            return nIndex;
    }
}

// @0x141853c30
Unk_ColorItem* CToolColorListBox::FUN_141853c30(int nIndex)
{
    int nReal = FUN_141853bc0(nIndex);
    if (nReal == -1)
        return 0;
    return (Unk_ColorItem*)m_pListBox->GetItemDataPtr(nReal);
}

// Alpha-blend the source rectangle of hSrc over the rectangle of hDst (32 bit DIB sections, nAlpha of 255 keeps the destination).
// @0x141853c80
bool AlphaBlendRect(HDC hDst, int x, int y, int cx, int cy, HDC hSrc, int nSrcX, int nSrcY, int nSrcCx, int nSrcCy, int nAlpha)
{
    BITMAPINFOHEADER bmi;
    void* pSrcBits;
    void* pDstBits;
    bmi.biSize = 0x28;
    bmi.biWidth = cx;
    bmi.biHeight = cy;
    bmi.biPlanes = 1;
    bmi.biBitCount = 0x20;
    bmi.biCompression = 0;
    bmi.biSizeImage = 0;
    bmi.biXPelsPerMeter = 0;
    bmi.biYPelsPerMeter = 0;
    bmi.biClrUsed = 0;
    bmi.biClrImportant = 0;
    HBITMAP hDstBmp;
    HGDIOBJ hOld;
    HBITMAP hSrcBmp;
    HDC hMem;
    hSrcBmp = CreateDIBSection(hSrc, (BITMAPINFO*)&bmi, 0, &pSrcBits, 0, 0);
    hDstBmp = CreateDIBSection(hDst, (BITMAPINFO*)&bmi, 0, &pDstBits, 0, 0);
    hMem = CreateCompatibleDC(0);
    hOld = SelectObject(hMem, hSrcBmp);
    if (!StretchBlt(hMem, 0, 0, cx, cy, hSrc, nSrcX, nSrcY, nSrcCx, nSrcCy, SRCCOPY))
        return false;
    SelectObject(hMem, hDstBmp);
    if (!StretchBlt(hMem, 0, 0, cx, cy, hDst, x, y, cx, cy, SRCCOPY))
        return false;
    SelectObject(hMem, hOld);
    DeleteDC(hMem);
    for (int nRow = 0; nRow < cy; nRow++)
    {
        BYTE* pDst = (BYTE*)((DWORD*)pDstBits + nRow * cx);
        BYTE* pSrc = (BYTE*)((DWORD*)pSrcBits + nRow * cx);
        for (int nCol = 0; nCol < cx; nCol++)
        {
            pSrc[0] = (BYTE)((int)pDst[0] * (0xff - nAlpha) + (int)pSrc[0] * nAlpha >> 8);
            pSrc[1] = (BYTE)((int)pDst[1] * (0xff - nAlpha) + (int)pSrc[1] * nAlpha >> 8);
            pSrc[2] = (BYTE)((int)pDst[2] * (0xff - nAlpha) + (int)pSrc[2] * nAlpha >> 8);
            pSrc += 4;
            pDst += 4;
        }
    }
    hMem = CreateCompatibleDC(0);
    hOld = SelectObject(hMem, hSrcBmp);
    if (!BitBlt(hDst, x, y, cx, cy, hMem, 0, 0, SRCCOPY))
        return false;
    DeleteDC(hMem);
    DeleteObject(hSrcBmp);
    DeleteObject(hDstBmp);
    return true;
}

// @0x141854160
CToolColorListBox::CToolColorListBox() : m_pListBox(this), m_nItemHeight(0)
{
}

// @0x1418541c0
CToolColorListBox::~CToolColorListBox()
{
}

// @0x1418541f0
int CToolColorListBox::FUN_1418541f0(LPCSTR pszText, COLORREF clrBack, COLORREF clrText, UINT nFormat8, UINT nFormatC, int bNoBlend, int n14)
{
    return FUN_141854270(pszText, GetCount(), clrBack, clrText, nFormat8, nFormatC, bNoBlend, n14);
}

// @0x141854270
int CToolColorListBox::FUN_141854270(LPCSTR pszText, int nIndex, COLORREF clrBack, COLORREF clrText, UINT nFormat8, UINT nFormatC, int bNoBlend, int n14)
{
    if (nIndex < 0 || nIndex > GetCount())
        return -1;
    int nResult = m_pListBox->InsertString(nIndex, pszText);
    if (nResult == -1)
        return nResult;
    Unk_ColorItem* pItem = new Unk_ColorItem;
    pItem->m_clrBack = clrBack;
    pItem->m_clrText = clrText;
    pItem->m_nFormat8 = nFormat8;
    pItem->m_nFormatC = nFormatC;
    pItem->m_bNoBlend = bNoBlend;
    pItem->m_n14 = n14;
    if (m_pListBox->SetItemDataPtr(nIndex, pItem) == -1)
        return -1;
    return nResult;
}

// @0x141854380
int CToolColorListBox::FUN_141854380(int nIndex)
{
    int nReal = FUN_141853bc0(nIndex);
    if (nReal == -1)
        return 0;
    Unk_ColorItem* pItem = (Unk_ColorItem*)m_pListBox->GetItemDataPtr(nReal);
    if (m_pListBox->DeleteString(nReal) == -1 || pItem == 0)
        return 0;
    delete pItem;
    return 1;
}

// @0x141854420
void CToolColorListBox::FUN_141854420()
{
    while (GetCount() != 0)
        FUN_141854380(0);
}

// @0x141854450
int CToolColorListBox::FUN_141854450(COLORREF clr, int nIndex)
{
    Unk_ColorItem* pItem = FUN_141853c30(nIndex);
    if (pItem == 0)
        return 0;
    pItem->m_clrBack = clr;
    RedrawWindow(0, 0, 0x105);
    return 1;
}

// @0x1418544c0
int CToolColorListBox::FUN_1418544c0(COLORREF clr, int nIndex)
{
    Unk_ColorItem* pItem = FUN_141853c30(nIndex);
    if (pItem == 0)
        return 0;
    pItem->m_clrText = clr;
    RedrawWindow(0, 0, 0x105);
    return 1;
}

// @0x141854530
int CToolColorListBox::FUN_141854530(UINT nFormat, int nIndex)
{
    Unk_ColorItem* pItem = FUN_141853c30(nIndex);
    if (pItem == 0)
        return 0;
    pItem->m_nFormatC = nFormat;
    RedrawWindow(0, 0, 0x105);
    return 1;
}

// @0x1418545a0
int CToolColorListBox::FUN_1418545a0(UINT nFormat, int nIndex)
{
    Unk_ColorItem* pItem = FUN_141853c30(nIndex);
    if (pItem == 0)
        return 0;
    pItem->m_nFormat8 = nFormat;
    RedrawWindow(0, 0, 0x105);
    return 1;
}

// @0x141854610
int CToolColorListBox::FUN_141854610(int bNoBlend, int nIndex)
{
    Unk_ColorItem* pItem = FUN_141853c30(nIndex);
    if (pItem == 0)
        return 0;
    pItem->m_bNoBlend = bNoBlend;
    RedrawWindow(0, 0, 0x105);
    return 1;
}

// @0x141854680
int CToolColorListBox::FUN_141854680(int n, int nIndex)
{
    Unk_ColorItem* pItem = FUN_141853c30(nIndex);
    if (pItem == 0)
        return 0;
    pItem->m_n14 = n;
    RedrawWindow(0, 0, 0x105);
    return 1;
}

// @0x1418546f0
void CToolColorListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    if ((int)lpDrawItemStruct->itemID < 0)
        return;
    {
        int nPad = 3;
        CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
        Unk_ColorItem* pItem = FUN_141853c30(lpDrawItemStruct->itemID);
        COLORREF clrBack = pItem->m_clrBack;
        COLORREF clrText = pItem->m_clrText;
        if (clrBack == 17000000)
            clrBack = GetSysColor(COLOR_WINDOW);
        if (clrText == 17000000)
            clrText = GetSysColor(COLOR_WINDOWTEXT);
        CBrush brush(clrBack);
        pDC->FillRect(&lpDrawItemStruct->rcItem, &brush);
        UINT nFormat = pItem->m_nFormatC | 0x20 | pItem->m_nFormat8;
        int nOldBkMode = pDC->SetBkMode(1);
        COLORREF clrOld = pDC->SetTextColor(clrText);
        CString strText;
        CRect rcText(lpDrawItemStruct->rcItem);
        rcText.DeflateRect(nPad, nPad);
        GetText(lpDrawItemStruct->itemID, strText);
        pDC->DrawText(strText, -1, &rcText, nFormat);
        pDC->SetTextColor(clrOld);
        pDC->SetBkMode(nOldBkMode);
        if (pItem->m_bNoBlend == 0)
        {
            CRect rcBlend(lpDrawItemStruct->rcItem);
            rcBlend.DeflateRect(nPad, nPad);
            CDC dcMem;
            dcMem.CreateCompatibleDC(pDC);
            int nSrcH = ((class CRect*)(class CRect const*)(&rcBlend))->Height();
            int nSrcW = ((class CRect*)(class CRect const*)(&rcBlend))->Width();
            HDC hMem = dcMem;
            int nH = ((class CRect*)(class CRect const*)(&rcBlend))->Height();
            AlphaBlendRect(*pDC, rcBlend.left, rcBlend.top, ((class CRect*)(class CRect const*)(&rcBlend))->Width(), nH, hMem, rcBlend.left, rcBlend.top, nSrcW, nSrcH, 0x32);
            dcMem.DeleteDC();
        }
        if ((lpDrawItemStruct->itemAction & ODA_FOCUS) != 0 && (lpDrawItemStruct->itemState & ODS_FOCUS) != 0)
        {
            CRect rcFocus(lpDrawItemStruct->rcItem);
            for (int i = 0; i < nPad; i++)
            {
                pDC->DrawFocusRect(FUN_14098a2a0(&rcFocus));
                rcFocus.DeflateRect(1, 1);
            }
        }
    }
}

// @0x141854b40
void CToolColorListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
    if (m_nItemHeight == 0)
    {
        CPaintDC dc(this);
        RECT rc;
        FUN_140517a60((CRect*)&rc);
        dc.DrawText("M", -1, &rc, DT_CALCRECT);
        lpMeasureItemStruct->itemHeight = ((class CRect*)(class CRect const*)((CRect*)&rc))->Height() + 6;
    }
    else
    {
        lpMeasureItemStruct->itemHeight = m_nItemHeight + 6;
    }
}

// @0x141854c20
void CToolColorListBox::OnDestroy()
{
    FUN_141854420();
    CListBox::OnDestroy();
}

// @0x141854c50
void CToolColorListBox::OnSysColorChange()
{
    CListBox::OnSysColorChange();
    RedrawWindow(0, 0, 0x105);
}

BEGIN_MESSAGE_MAP(CToolColorListBox, CListBox)
    ON_WM_DESTROY()
    ON_WM_SYSCOLORCHANGE()
END_MESSAGE_MAP()

// ---- the default constructor of a 0x60-byte effect-dummy list element (the next TU's element type, named here by use) ----

// A CEffectDummy row (a member: the exe's constructor stores no vptr of its own) plus a name and an index.
class Unk_ToolDummyRow
{
public:
    Unk_ToolDummyRow();                                     // 0x1418550f0
    CEffectDummy m_dummy;                                   // +0x00
    CString m_strTool;                                      // +0x50
    int m_nTool;                                            // +0x58
};

// @0x1418550f0
Unk_ToolDummyRow::Unk_ToolDummyRow()
{
    m_nTool = 0;
}
