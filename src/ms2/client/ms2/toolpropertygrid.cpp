// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's toolpropertygrid.cpp: the MFC property-grid
// classes of the tool UI (a float-formatting base property, a slider property and its slider control, colour / file /
// vector properties). See toolpropertygrid.h.
// MS2-UNIT: client\ms2\toolpropertygrid.cpp
// MS2-RANGE: 0x1418555f0-0x141856e00 .text$mn
// MS2-PIN: ??1CMS2PropertyGridProperty@@UEAA@XZ 0x141856a80
// MS2-PIN: ??1CSliderProp@@UEAA@XZ 0x141856ac0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolpropertygrid.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <atlcoll.h>
#include <stdlib.h>

#include "toolpropertygrid.h"

#include "ms2/client/ms2/ms2.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of callees emitted in other units ----

int FUN_14028c3e0(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim, int nMax);   // split
void FUN_141854f50(CDC* pDC, const RECT* pRect, CBrush* pBrush);   // CDC::FillRect (toolcolorlistbox.cpp's COMDAT)
int FUN_140518af0(const CRect* pRect);                  // CRect::Height
LPRECT FUN_14098a2a0(CRect* pRect);                     // CRect::operator LPRECT

// ---- CPropSliderCtrl ----

// @0x1418555f0
CPropSliderCtrl::CPropSliderCtrl(CSliderProp* pProperty, COLORREF clrBack) : m_clrBack(clrBack)
{
    m_brush.CreateSolidBrush(m_clrBack);
    m_pProperty = pProperty;
}

// @0x141855690
CPropSliderCtrl::~CPropSliderCtrl()
{
}

// @0x1418556d0
HBRUSH CPropSliderCtrl::CtlColor(CDC* pDC, UINT nCtlColor)
{
    pDC->SetBkColor(m_clrBack);
    return (HBRUSH)m_brush;
}

// @0x141855720
void CPropSliderCtrl::HScroll(UINT nSBCode, UINT nPos)
{
    m_pProperty->OnUpdateValue();
    m_pProperty->Redraw();
}

BEGIN_MESSAGE_MAP(CPropSliderCtrl, CSliderCtrl)
    ON_WM_CTLCOLOR_REFLECT()
    ON_WM_HSCROLL_REFLECT()
END_MESSAGE_MAP()

// ---- CMS2ColorProperty ----

// @0x1418557a0
CString CMS2ColorProperty::FormatProperty()
{
    if (m_Color == (COLORREF)-1)
        m_Color = m_ColorAutomatic;
    return CMFCPropertyGridColorProperty::FormatProperty();
}

// ---- CMS2PropertyGridProperty ----

// @0x141855810
CString CMS2PropertyGridProperty::FormatProperty()
{
    const COleVariant& var = m_varValue;
    if (!m_bIsValueList && (var.vt == VT_R4 || var.vt == VT_R8))
    {
        CString strText;
        if (var.vt == VT_R4)
            strText.Format("%0.2f", var.fltVal);
        else if (var.vt == VT_R8)
            strText.Format("%0.2f", (float)var.dblVal);
        return CString(strText);
    }
    return CMFCPropertyGridProperty::FormatProperty();
}

// ---- CSliderProp ----

// @0x141855940
CSliderProp::CSliderProp(const CString& strName, const COleVariant& varValue, float fScale, LPCTSTR lpszDescr, unsigned int dwData)
    : CMS2PropertyGridProperty(strName, varValue, lpszDescr, dwData, 0, 0, 0), m_fScale(fScale), m_nMin(0), m_nMax(100)
{
}

// @0x141855a30
BOOL CSliderProp::OnUpdateValue()
{
    MS2_ASSERT_AT(112, ::IsWindow(m_pWndInPlace->GetSafeHwnd()));
    COleVariant varPrev = m_varValue;
    CSliderCtrl* pSlider = (CSliderCtrl*)m_pWndInPlace;
    if (m_varValue.vt == VT_R4 || m_varValue.vt == VT_R8)
        m_varValue = (float)pSlider->GetPos() / m_fScale;
    else
        m_varValue = (long)((float)pSlider->GetPos() / m_fScale + 0.5f);
    if (varPrev != m_varValue)
        m_pWndList->OnPropertyChanged(this);
    return TRUE;
}

// @0x141855ba0
CWnd* CSliderProp::CreateInPlaceEdit(CRect rectEdit, BOOL& bDefaultFormat)
{
    CPropSliderCtrl* pSlider = new CPropSliderCtrl(this, m_pWndList->GetBkColor());
    rectEdit.left += rectEdit.Height() + 25;
    pSlider->Create(WS_CHILD | WS_VISIBLE, rectEdit, m_pWndList, 3);
    pSlider->SetRange(m_nMin, m_nMax, FALSE);
    if (m_varValue.vt == VT_R4 || m_varValue.vt == VT_R8)
        pSlider->SetPos((int)(m_varValue.fltVal * m_fScale));
    else
        pSlider->SetPos((int)((float)m_varValue.lVal * m_fScale + 0.5f));
    bDefaultFormat = TRUE;
    return pSlider;
}

// ---- CMS2FileProperty ----

// @0x141855d20
void CMS2FileProperty::OnClickButton(CPoint point)
{
    CMFCPropertyGridFileProperty::OnClickButton(point);
    MS2::SetWorkingDirectory(true);
}

// ---- CMS2VectorProperty ----

// @0x141855d50
void CMS2VectorProperty::OnDrawValue(CDC* pDC, CRect rect)
{
    CRect rcOld = rect;
    rect.left += rect.Height();
    CMFCPropertyGridProperty::OnDrawValue(pDC, rect);
    rcOld.right = rcOld.left + rcOld.Height();
    rcOld.DeflateRect(1, 1);
    rcOld.top++;
    rcOld.left++;
    COLORREF clr = GetColor();
    CBrush brush(clr);
    FUN_141854f50(pDC, FUN_14098a2a0(&rcOld), &brush);
    pDC->Draw3dRect(FUN_14098a2a0(&rcOld), 0, 0);
}

// @0x141855eb0
// MS2-FUNCTIONAL: the exe's loop / static-flag blocks differ by 12 bytes (nLen compare operand order, block layout); not reproduced
BOOL CMS2VectorProperty::UpdateColor()
{
    MS2_ASSERT_AT(180, ::IsWindow(m_pWndInPlace->GetSafeHwnd()));
    CString strText;
    m_pWndInPlace->GetWindowText(strText);
    if ((int)(FormatProperty() != strText))
    {
        CString strDelim = ",";
        for (int nIndex = 0; !strText.IsEmpty() && nIndex < GetSubItemsCount(); ++nIndex)
        {
            CString strToken = strText.SpanExcluding(strDelim);
            int nLen = strToken.GetLength() + 1;
            if (strText.GetLength() < nLen)
                strText.Empty();
            else
                strText = strText.Mid(strToken.GetLength() + 1);
            strToken.TrimLeft();
            strToken.TrimRight();
            int nValue = atoi(strToken);
            if (nIndex == 0 && (nValue < 0 || nValue > 255))
            {
                static BOOL s_bShowingR = FALSE;
                if (s_bShowingR)
                    return TRUE;
                s_bShowingR = TRUE;
                CString strMsg;
                strMsg.Format("R value must be between %d and %d.", 0, 255);
                AfxMessageBox(strMsg, 0, 0);
                s_bShowingR = FALSE;
                return FALSE;
            }
            if (nIndex == 1 && (nValue < 0 || nValue > 255))
            {
                static BOOL s_bShowingG = FALSE;
                if (s_bShowingG)
                    return TRUE;
                s_bShowingG = TRUE;
                CString strMsg;
                strMsg.Format("G value must be between %d and %d.", 0, 255);
                AfxMessageBox(strMsg, 0, 0);
                s_bShowingG = FALSE;
                return FALSE;
            }
            if (nIndex == 2 && (nValue < 0 || nValue > 255))
            {
                static BOOL s_bShowingB = FALSE;
                if (s_bShowingB)
                    return TRUE;
                s_bShowingB = TRUE;
                CString strMsg;
                strMsg.Format("B value must be between %d and %d.", 0, 255);
                AfxMessageBox(strMsg, 0, 0);
                s_bShowingB = FALSE;
                return FALSE;
            }
        }
        return CMFCPropertyGridProperty::OnUpdateValue();
    }
    return TRUE;
}

// @0x1418563f0
COLORREF CMS2VectorProperty::GetColor()
{
    COLORREF clr = 0xffffff;
    CString strText = FormatProperty();
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 3))
    {
        clr = RGB(atoi(arrParts[0]), atoi(arrParts[1]), atoi(arrParts[2]));
    }
    return clr;
}

// @0x141856580
BOOL CMS2VectorProperty::OnUpdateValue()
{
    MS2_ASSERT_AT(308, ::IsWindow(m_pWndInPlace->GetSafeHwnd()));
    CString strText;
    m_pWndInPlace->GetWindowText(strText);
    if ((int)(FormatProperty() != strText))
        return CMFCPropertyGridProperty::OnUpdateValue();
    return TRUE;
}

// @0x141856680
Unk_GridPoint2 CMS2VectorProperty::GetVector2()
{
    CString strText = FormatProperty();
    Unk_GridPoint2 kResult;
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 2))
    {
        kResult.x = (float)atof(arrParts[0]);
        kResult.y = (float)atof(arrParts[1]);
    }
    return kResult;
}

// @0x141856770
Vector3 CMS2VectorProperty::GetVector3()
{
    CString strText = FormatProperty();
    Vector3 kResult;
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 3))
    {
        kResult.x = (float)atof(arrParts[0]);
        kResult.y = (float)atof(arrParts[1]);
        kResult.z = (float)atof(arrParts[2]);
    }
    return kResult;
}

// @0x1418568a0
BOOL CMS2VectorProperty::UpdateWithParent()
{
    BOOL bResult = TRUE;
    bResult = CMFCPropertyGridProperty::OnUpdateValue();
    if (m_pParent)
        m_pWndList->OnPropertyChanged(m_pParent);
    return bResult;
}

// @0x141856910
BOOL CSliderProp::UpdateWithParent2()
{
    BOOL bResult = TRUE;
    bResult = CSliderProp::OnUpdateValue();
    if (m_pParent)
        m_pWndList->OnPropertyChanged(m_pParent);
    return bResult;
}

// @0x141856510
BOOL CSliderProp::UpdateWithParent()
{
    BOOL bResult = TRUE;
    bResult = CSliderProp::OnUpdateValue();
    if (m_pParent)
        m_pWndList->OnPropertyChanged(m_pParent);
    return bResult;
}

// @0x1418569f0
CMS2PropertyGridProperty::CMS2PropertyGridProperty(const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr,
    DWORD_PTR dwData, LPCTSTR lpszEditMask, LPCTSTR lpszEditTemplate, LPCTSTR lpszValidChars)
    : CMFCPropertyGridProperty(strName, varValue, lpszDescr, dwData, lpszEditMask, lpszEditTemplate, lpszValidChars)
{
}

// @0x141856de0
BOOL CSliderProp::OnSetCursor() const
{
    return FALSE;
}
