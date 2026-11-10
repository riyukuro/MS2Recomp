// cdrawdebugstring.h - CDrawDebugString (RTTI .?AVCDrawDebugString@@): one line of text of the in-game debug overlay
// (a NiVisualTrackerBase that draws a label plus a changing value). Declaration only: the owning unit
// `?\drawdebugstring.cpp` (0x14118b420-0x14118c730) is not recovered yet; the methods are bound by their FUN_ names.
// The setters only redraw when the overlay line is shown (m_bShow) or bForce is set, and only when the value changed.
// The label text and the formatted value share m_acName (+0x40 .. 0xff chars, "%s %s%s" = label, value, suffix).
#pragma once

#include <afx.h>
#include <string>
#include <NiVisualTracker.h>
#include <NiPoint3.h>
#include <efd/utf8string.h>
#include "ms2/ms2layout.h"

class CDrawDebugString : public NiVisualTrackerBase
{
public:
    CDrawDebugString(const char* pcName, NiColorA kColor);          // 0x14118b420 (the color is passed by pointer to a copy)
    virtual ~CDrawDebugString();                                    // 0x14118b670, ??_G 0x14118c3d0
    virtual void Draw();                                            // 0x14118b780

    void FUN_14118b820(int nValue, bool bForce, const char* pszSuffix);     // "<label> <value><suffix>"
    void FUN_14118b9b0(unsigned nValue, bool bForce, const char* pszSuffix);
    void FUN_14118bb40(float fValue, bool bForce, const char* pszSuffix);   // "%.2f"
    void FUN_14118bc70(bool bValue, bool bForce, const char* pszSuffix);    // "True" / "False"
    void FUN_14118bdc0(const NiPoint3& kValue, bool bForce);                // "%.2f %.2f %.2f"
    void FUN_14118bee0(efd::utf8string strValue, bool bForce);                      // by value: the callee destroys it
    void FUN_14118bf80(const char* pszLabel, unsigned x, unsigned y);       // set the label and place the text
    void WriteToCrashLog();                                                   // log the line
    void SetColor(NiColorA* pColor);                                   // color of the text
    void UpdateText();                                                   // push m_acName into both texts
    std::string FormatWithThousandsSeparator(unsigned nValue);                             // 1234567 -> "1,234,567"
    const char* GetText();                                                  // m_acName

protected:
    NiVisualTrackerBase::ScreenText* m_pText;                       // +0x140
    NiVisualTrackerBase::ScreenText* m_pShadow;                     // +0x148 (drawn one pixel down-right in black)
    CString m_strLabel;                                             // +0x150
    union { int m_nValue; float m_fValue; unsigned char m_cValue; };         // +0x158 last value shown
    NiPoint3 m_kPoint;                                              // +0x15c
};
MS2_CHECK_SIZE(CDrawDebugString, 0x168);
typedef NiPointer<CDrawDebugString> CDrawDebugStringPtr;
