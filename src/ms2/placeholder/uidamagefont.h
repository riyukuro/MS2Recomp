// uidamagefont.h - PLACEHOLDER for TDamageFontAttr and UIDamageFont, the damage-number font swf objects. NOT an original
// header. The bodies live in the done unit ms2/unnamed/unit_140e0da60.cpp, which keeps its own copy of these declarations
// (same layout); this header is for the users (?\gfxmoviedamage.cpp keeps the loaded fonts in CAtlMap<id, MS2Ptr<...>>).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/placeholder/cptred.h"

// The per-font attribute record: the font id at +0x18, the time of the last use at +0x20. 0x28 bytes.
class TDamageFontAttr : public CPtred
{
public:
    TDamageFontAttr();                                                      // 0x140e0da60
    ~TDamageFontAttr() = default;                                           // 0x140e0dd00 (no vptr store)

    int m_18;
    __int64 m_20;
};
MS2_CHECK_SIZE(TDamageFontAttr, 0x28);

// UIDamageFont: RTTI .?AVUIDamageFont@@, 0x80 bytes. One "DamageFont_<name>" swf.
class UIDamageFont : public UIObject
{
public:
    UIDamageFont(const CString& strName, MS2Ptr<TDamageFontAttr> spAttr);   // 0x140e0dab0 (spAttr by value)
    virtual ~UIDamageFont() = default;                                      //  0 0x140e0dd20 (no vptr store)
    virtual CString vfunc_1();                                              //  1 0x140e0db60
    virtual void OnLoadComplete();                                          // 22 0x140e0dbb0
    virtual int vfunc_48() { return 0x4f39; }                               // 48 (COMDAT 0x140e0de30)

    int FUN_140e0dbe0();                                                    // the attribute's +0x18 (font id), 0 without one
    bool FUN_140e0dc30();                                                   // stamp the attribute with the current time
    __int64 FUN_140e0dca0();                                                // the attribute's time stamp

public:
    MS2_LAYOUT_FRIEND;
    CString m_strName;                      // +0x68
    MS2Ptr<TDamageFontAttr> m_spAttr;       // +0x70
};
MS2_CHECK_SIZE(UIDamageFont, 0x80);
MS2_CHECK_OFFSET(UIDamageFont, m_spAttr, 0x70);
