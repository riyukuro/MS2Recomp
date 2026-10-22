// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHeadUpDisplay: see ms2/placeholder/uiheadupdisplay.h.
// MS2-UNIT: ?\uiheadupdisplay.cpp
// MS2-RANGE: 0x141986b50-0x141986d90 .text$mn
// MS2-RANGE: 0x140114820-0x1401148e0 .text$di
// MS2-RANGE: 0x142cbe930-0x142cbe960 .text$yd
//
// The unit map's low-confidence run 0x141986b50-0x141991700 holds three CUs: this one (8 functions), UIHideSettingDialog
// (0x141986d90..) and UIHouseMark/UIHouseMarkEntity (0x14198aca0..). The only static is the sort-type name table that
// header_statics_a.h also defines (this CU includes some header with just that table, not the skill/stun/condition set).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiheadupdisplay.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/uiheadupdisplay.h"

#include "ms2/placeholder/asgameentity.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// This assignment COMDAT belongs to the earlier unit at 0x140ba7780.
template <> template <>
MS2Ptr<AScript>& MS2Ptr<AScript>::operator=<ASGameEntity>(const MS2Ptr<ASGameEntity>&);

MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);    // new ASGameEntity(v, n)

static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x141986b50
UIHeadUpDisplay::UIHeadUpDisplay()
    : m_68(0)
{
    m_44 = 0;
    m_2c = 8;
}

// @0x141986bc0
UIHeadUpDisplay::~UIHeadUpDisplay()
{
}

// @0x141986c00
CString UIHeadUpDisplay::GetTypeName()
{
    return "HeadUpDisplay";
}
MS2_REPLACE_METHOD(0x141986C00, UIHeadUpDisplay, GetTypeName, 61, 0x0B1F24FC);

// @0x141986c50
void UIHeadUpDisplay::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x141986C50, UIHeadUpDisplay, vfunc_41, 99, 0xA8B7BC6F);

// @0x141986cc0
void UIHeadUpDisplay::vfunc_2()
{
    m_68 = 1;
    FUN_1422dbf00(m_2c, m_44, 0);
}
MS2_REPLACE_METHOD(0x141986CC0, UIHeadUpDisplay, vfunc_2, 56, 0x342FA7E4);

// @0x141986d00
void UIHeadUpDisplay::vfunc_3()
{
    m_68 = 0;
    FUN_1422dc080();
}
MS2_REPLACE_METHOD(0x141986D00, UIHeadUpDisplay, vfunc_3, 36, 0xC85DB727);

// @0x141986d30
int UIHeadUpDisplay::FUN_141986d30()
{
    return m_68;
}
MS2_REPLACE_METHOD(0x141986D30, UIHeadUpDisplay, FUN_141986d30, 14, 0xD1D12A47);
