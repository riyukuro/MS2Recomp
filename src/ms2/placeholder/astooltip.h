// astooltip.h - PLACEHOLDER for ASTooltip (RTTI .?AVASTooltip@@, base AScript, 0x60 bytes). NOT an original header.
// Ctors 0x1409c63d0 (int, int) and an (owner, int, int) variant, dtor 0x1409b4af0. Units must include this header
// instead of redefining the class.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"

class CItem;
class CItemData;
template <class T> class Unk_GalleryPtr;     // unit-local smart pointer of uigalleryeventdialog.h
class Unk_GalleryItem;

class ASTooltip : public ASObj
{
public:
    explicit ASTooltip(int nMovieId);                // 0x1409c62e0 (aseffect.cpp)
    ASTooltip(int a1, int a2);
    ASTooltip(void* pOwner, int a1, int a2);
    ASTooltip(class Unk_TooltipOwner* pOwner, int a1, int a2);       // 0x1409c64c0 (same body as the void* form; the owner's real type is unknown)
    ASTooltip(const Scaleform::GFx::Value& root, int nMovieId);     // 0x1409c6350 (uiadventureleveldialog.cpp)
    virtual ~ASTooltip();
    void FUN_1409c7b10(CItem* pItem);                                    // itemDamage (sum of the damage lines)
    void FUN_1409c7c10(CItem* pItem);
    void FUN_1409c7c70(CItem* pItem);
    void FUN_1409c7f70(CItem* pItem);
    void FUN_1409c7fc0(CItem* pItem);                                    // picks the plain or the extended item layout
    void FUN_1409c9170(CItem* pItem);
    void FUN_1409cc090(CItem* pItem);
    void FUN_1409d95f0(CItem* pItem, CStringW& strOut);
    void FUN_1409d8d90(CItem* pItem, CStringW& strOut);
    void FUN_1409d9330(CItem* pItem, CStringW& strOut);
    void FUN_1409d99a0(CItem* pItem, CStringW& strOut);
    void FUN_1409d9aa0(CItem* pItem, CStringW& strOut);
    void FUN_1409d4350(CItemData* pData);
    void FUN_1409d43b0(CItem* pItem);
    void FUN_1409d43e0(CItem* pItem);
    void FUN_1409d4460(CItem* pItem);
    void FUN_1409d46a0(CItem* pItem);
    void FUN_1409d5530(unsigned nId);
    void FUN_1409d55a0(CItem* pItem, int n);
    void FUN_1409d8300(int n);
    void FUN_1409d77b0(int n);
    void FUN_1409d5160(unsigned nItemId);
    void FUN_1409d5200(unsigned nItemId);
    void FUN_1409d52a0(unsigned nItemId);
    void FUN_1409d5340(unsigned nItemId);
    void FUN_1409d53f0(unsigned nItemId);
    void FUN_1409d5490(unsigned nItemId);
    void FUN_1409d8c80(const CStringW& str);
    void FUN_1409d8ce0(CStringW str);                                    // itemDamage (by value: the callee destroys it)
    void FUN_1409d8d50(bool b);
    void FUN_1409dbc30(const CStringW& str);                             // set m_50
    void FUN_1409d74a0(int nItemId);
    __int64 FUN_1409c6540();                                             // m_40
    unsigned FUN_1409c6560();                                            // m_48 (flags; 0x100 = no extra buttons)
    void FUN_1409c6580(unsigned n);
    void FUN_1409c65a0();                                                // enableUseDbClick = string 0x762
    void FUN_1409c6880();                                                // enablePuton = string 0x751 (unless flag 0x100)
    void FUN_1409c68e0();                                                // enableCompareSwap = string 0x765 (unless flag 0x100)
    void FUN_1409c6940(const CStringW& strText);                         // enableLClick (unless flag 0x100)
    void FUN_1409c6c80();                                                // closeButton = true
    void FUN_1409c6d10(const CString& str);                              // string member DAT_143ab45a8
    void FUN_1409c6e30(int n);
    void FUN_1409c6ec0(int n);
    void FUN_1409c6dc0(int n);
    void FUN_1409c6d70(const CString& strClass);                         // set the AS class name
    void FUN_1409c6e00(int n);
    void FUN_1409c6e60(int n);
    void FUN_1409c6cb0(const CStringW& strText);                         // set the text
    void FUN_1409c6e90(int n);
    int FUN_1409e26b0(const CStringW& strText);
    int FUN_1409e1770(int a1, int a2);
    int FUN_1409e21a0(unsigned nId, unsigned nGrade);                   // achievement tooltip (uiachievedialog.cpp)
    int FUN_1409e0d40(CItem* pItem);
    int FUN_1409e2750(void* pSkillAttr, int a1, int a2);                   // skill record tooltip (uiadventureleveldialog.cpp)
    void FUN_1409db870(Unk_GalleryPtr<Unk_GalleryItem> item);
    void FUN_1409c69b0(const CStringW& strTitle);                        // set the tooltip title line
    void FUN_1409c65f0(const CStringW& strText);                         // set the tooltip text line
    void FUN_1409c6640(const CStringW& strLhs, const CStringW& strRhs);   // enableUseDbClick on both comparison tooltips
    void FUN_1409c6ef0(const CStringW& strText);                        // append to textBgArr
    void FUN_1409e13a0(CItem* pCompare, CItem* pItem);                  // item tooltip with the default flags
    bool FUN_1409e25e0(CItem* pItem, unsigned n);
    void FUN_1409cf010(CItem* pItem, unsigned n);
    int FUN_1409e13f0(CItem* pCompare, CItem* pItem, int a1, int a2);   // item tooltip with a comparison item (ItemInfoSlot)
    void FUN_1409c6a20(const CStringW& strA, const CStringW& strB);     // set a tooltip text pair (ItemInfoSlot exchange scroll)
    void FUN_1409c7060(const CStringW& strKey, const CStringW& strB);   // set a keyed tooltip text pair (ItemInfoSlot exchange scroll)
    void FUN_1409db7b0(MS2Ptr<CItem> spItem);                            // compare against this item (by value: callee destroys)
    void FUN_1409db930(MS2Ptr<CItem> spCompare, MS2Ptr<CItem> spItem);   // item tooltip with an optional comparison item (by value: callee destroys)

private:
    __int64 m_40; unsigned m_48; unsigned m_pad_4c; CStringW m_50; void* m_pad_58;   // m_50: text (destroyed by ~ASTooltip, aseffect.cpp)
};
MS2_CHECK_SIZE(ASTooltip, 0x60);
