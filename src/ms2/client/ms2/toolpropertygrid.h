// toolpropertygrid.h - the tool UI's MFC property-grid classes (RTTI names): CMS2PropertyGridProperty (a
// CMFCPropertyGridProperty that prints floats with two decimals), CSliderProp / CPropSliderCtrl (a property edited by a
// slider), CMS2ColorProperty, CMS2FileProperty and CMS2VectorProperty (a "x, y, z" property with a colour swatch).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `client\ms2\toolpropertygrid.cpp`
// (0x1418555f0-0x141856e00 .text$mn). Header name assumed; member names invented from use.
#pragma once
#include <afxcmn.h>
#include <afxpropertygridctrl.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nipoint3.h"

class CSliderProp;

// 0x160 = CMFCPropertyGridProperty. Only the constructor and FormatProperty are overridden.
class CMS2PropertyGridProperty : public CMFCPropertyGridProperty
{
public:
    CMS2PropertyGridProperty(const CString& strName, const COleVariant& varValue, LPCTSTR lpszDescr = NULL,
        DWORD_PTR dwData = 0, LPCTSTR lpszEditMask = NULL, LPCTSTR lpszEditTemplate = NULL, LPCTSTR lpszValidChars = NULL);   // 0x1418569f0
    virtual ~CMS2PropertyGridProperty() = default;          // 0x141856a80 (??_G 0x141856b30)
    virtual CString FormatProperty();                       // 0x141855810: floats as "%0.2f"
};
MS2_CHECK_SIZE(CMS2PropertyGridProperty, 0x160);

// 0x170.
class CSliderProp : public CMS2PropertyGridProperty
{
public:
    CSliderProp(const CString& strName, const COleVariant& varValue, float fScale, LPCTSTR lpszDescr = NULL, unsigned int dwData = 0);   // 0x141855940
    virtual ~CSliderProp() = default;                       // 0x141856ac0 (??_G 0x141856bf0)
    virtual BOOL OnUpdateValue();                           // 0x141855a30
    virtual CWnd* CreateInPlaceEdit(CRect rectEdit, BOOL& bDefaultFormat);   // 0x141855ba0
    virtual BOOL OnSetCursor() const;                       // 0x141856de0: FALSE

    BOOL UpdateWithParent();                                // 0x141856510
    BOOL UpdateWithParent2();                               // 0x141856910 (an identical copy)

    float m_fScale;                                         // +0x160 slider ticks per unit
    int m_nMin;                                             // +0x164
    int m_nMax;                                             // +0x168
};
MS2_CHECK_SIZE(CSliderProp, 0x170);
MS2_CHECK_OFFSET(CSliderProp, m_fScale, 0x160);
MS2_CHECK_OFFSET(CSliderProp, m_nMax, 0x168);

// 0x108 = CSliderCtrl (0xe8) + the background brush + its colour + the owning property.
class CPropSliderCtrl : public CSliderCtrl
{
public:
    CPropSliderCtrl(CSliderProp* pProperty, COLORREF clrBack);   // 0x1418555f0
    virtual ~CPropSliderCtrl();                             // 0x141855690 (??_G 0x141856b90)

    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);      // 0x1418556d0
    afx_msg void HScroll(UINT nSBCode, UINT nPos);          // 0x141855720
    DECLARE_MESSAGE_MAP()                                   // GetMessageMap 0x141855780

public:
    CBrush m_brush;                                         // +0xe8
    COLORREF m_clrBack;                                     // +0xf8
    CSliderProp* m_pProperty;                               // +0x100
};
MS2_CHECK_SIZE(CPropSliderCtrl, 0x108);
MS2_CHECK_OFFSET(CPropSliderCtrl, m_brush, 0xe8);
MS2_CHECK_OFFSET(CPropSliderCtrl, m_clrBack, 0xf8);
MS2_CHECK_OFFSET(CPropSliderCtrl, m_pProperty, 0x100);

// No added fields.
class CMS2ColorProperty : public CMFCPropertyGridColorProperty
{
public:
    virtual CString FormatProperty();                       // 0x1418557a0: "automatic" colour when unset
};

class CMS2FileProperty : public CMFCPropertyGridFileProperty
{
public:
    virtual void OnClickButton(CPoint point);               // 0x141855d20: restore the working directory after the dialog
};

// A "r, g, b" / "x, y" / "x, y, z" text property.
class Unk_GridPoint2 { public: Unk_GridPoint2(); float x, y; };         // ctor 0x14097f3a0
class CMS2VectorProperty : public CMFCPropertyGridProperty
{
public:
    virtual void OnDrawValue(CDC* pDC, CRect rect);         // 0x141855d50: the value plus a colour swatch
    virtual BOOL OnUpdateValue();                           // 0x141856580

    COLORREF GetColor();                                    // 0x1418563f0
    Unk_GridPoint2 GetVector2();                            // 0x141856680
    Vector3 GetVector3();                           // 0x141856770
    BOOL UpdateColor();                                     // 0x141855eb0 range-checks r, g, b
    BOOL UpdateWithParent();                                // 0x1418568a0
};
