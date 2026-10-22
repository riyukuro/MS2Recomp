// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDamageFont (floating damage number UI object, UI type 0x4f39) and
// its attribute record TDamageFontAttr. File name guessed (damage font UI); the unit is unnamed in the exe.
// MS2-UNIT: unit_140e0da60
// MS2-RANGE: 0x140e0da60-0x140e0de40 .text$mn
// MS2-PIN: ??1UIDamageFont@@UEAA@XZ 0x140e0dd20
// MS2-PIN: ??1TDamageFontAttr@@UEAA@XZ 0x140e0dd00
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140e0da60.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CString FUN_140540050(const char* szFormat, const CString& strArg);          // StringFormat<CString> (this TU's own exe copy)
__int64 FUN_140869440();                                                    // current server time

// The per-font attribute record: the time of the last use is kept at +0x20.
class TDamageFontAttr : public CPtred
{
public:
    TDamageFontAttr();                                                      // 0x140e0da60
    ~TDamageFontAttr() = default;                                           // 0x140e0dd00 (no vptr store)

    int m_18;
    __int64 m_20;
};
MS2_CHECK_SIZE(TDamageFontAttr, 0x28);

// UIDamageFont: RTTI .?AVUIDamageFont@@, 0x80 bytes.
class UIDamageFont : public UIObject
{
public:
    UIDamageFont(const CString& strName, MS2Ptr<TDamageFontAttr> spAttr);   // 0x140e0dab0
    virtual ~UIDamageFont() = default;                                      //  0 0x140e0dd20 (no vptr store)
    virtual CString GetTypeName();                                              //  1 0x140e0db60
    virtual void OnLoadComplete();                                          // 22 0x140e0dbb0
    virtual int vfunc_48() { return 0x4f39; }                               // 48 (COMDAT 0x140e0de30)

    int FUN_140e0dbe0();                                                    // the attribute's +0x18, 0 without one
    bool FUN_140e0dc30();                                                   // stamp the attribute with the current time
    __int64 FUN_140e0dca0();                                                // the attribute's time stamp

public:
    MS2_LAYOUT_FRIEND;
    CString m_strName;                      // +0x68
    MS2Ptr<TDamageFontAttr> m_spAttr;       // +0x70
};
MS2_CHECK_SIZE(UIDamageFont, 0x80);
MS2_CHECK_OFFSET(UIDamageFont, m_spAttr, 0x70);

// @0x140e0da60
TDamageFontAttr::TDamageFontAttr()
{
    m_18 = 0;
    m_20 = 0;
}

// @0x140e0dab0
UIDamageFont::UIDamageFont(const CString& strName, MS2Ptr<TDamageFontAttr> spAttr)
    : m_strName(strName)
    , m_spAttr(spAttr)
{
    m_28 = 1;
    m_2c = 8;
}

// @0x140e0db60
CString UIDamageFont::GetTypeName()
{
    return FUN_140540050("DamageFont_{0}", m_strName);
}

// @0x140e0dbb0
void UIDamageFont::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140e0dc30();
}

// @0x140e0dbe0
int UIDamageFont::FUN_140e0dbe0()
{
    if (m_spAttr.get() != 0)
        return m_spAttr->m_18;
    return 0;
}

// @0x140e0dc30
bool UIDamageFont::FUN_140e0dc30()
{
    if (m_spAttr == 0 || m_30 == 0)
        return false;
    m_spAttr->m_20 = FUN_140869440();
    return true;
}

// @0x140e0dca0
__int64 UIDamageFont::FUN_140e0dca0()
{
    if (m_spAttr == 0 || m_30 == 0)
        return 0;
    return m_spAttr->m_20;
}
