// asslot.h - PLACEHOLDER for ASSlot (RTTI .?AVASSlot@@, base ASObj, 0x40 bytes): the AS item slot data object (code in
// ?\asitemslot.cpp). Ctor 0x1409c1c20 (type), dtor 0x1409c1cb0. NOT an original header. uiattendgiftdialog.cpp still
// carries a unit-local copy; new units include this one. The FUN_ setters each set one AS member (named in the comment).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asobj.h"

class CItem;
class CItemData;
class CItemEnchantInfo;
class Unk_ItemPlusInfo;
class Unk_SlotSkillInfo;
class Unk_SlotIconSource;

class ASSlot : public ASObj
{
public:
    ASSlot(int nType);
    ASSlot(const Scaleform::GFx::Value& v, int nMovieId);                 // 0x1409c1c60
    virtual ~ASSlot();
#ifdef MS2_ASSLOT_COPY_EXTERN
    ASSlot(const ASSlot& o);                                              // 0x1409bb770 (opt-in per unit: the other units keep the implicit copy)
#endif
    void FUN_1409c1ce0(int n);                                           // itemPet
    void FUN_1409c1d20(int n);                                           // itemCash
    void FUN_1409c1d60(int n);                                           // itemSkin
    void FUN_1409c1da0(bool b);                                          // itemPcBang
    void FUN_1409c1e00(int n);                                           // itemVIP
    void FUN_1409c1e40(int n);                                           // itemWedding
    void FUN_1409c1e80(int n);                                           // itemLock
    void FUN_1409c1ec0(int n);                                           // itemConditionLock
    void FUN_1409c1f00(int n);                                           // itemSeal
    void FUN_1409c1f40(CItem* pItem);                                    // itemIconLock / itemIconUnLock
    void FUN_1409c2050(int n);                                           // itemPiece
    void FUN_1409c2090(int n);                                           // grayColor
    void FUN_1409c20d0(int n);                                           // itemEquip
    void FUN_1409c2110(int n);                                           // itemEquip2
    void FUN_1409c2150(int n);                                           // itemSummon
    void FUN_1409c2190(unsigned n);                                      // itemCount (when nonzero)
    void FUN_1409c2200(CItem* pItem);                                    // itemCount of a stackable item
    void FUN_1409c2360(unsigned long nColor);                            // itemColor
    void FUN_1409c23a0(unsigned nItemId);                                // itemID
    void FUN_1409c23e0(int nGrade);                                      // itemGrade
    void FUN_1409c2420(int nRank);                                       // itemPetRank (+ dropShadowDisable)
    void FUN_1409c2470(int n);                                           // itemPetSkin
    void FUN_1409c24b0(int n);                                           // itemBothEquip
    void FUN_1409c24f0(int n);                                           // itemNew
    void FUN_1409c2530(int n);                                           // itemEvent
    void FUN_1409c2570(int n);                                           // itemResultTag
    void FUN_1409c25b0(const CStringW& strName);                         // itemName
    void FUN_1409c2610();                                                // dropShadowDisable
    void FUN_1409c2650();                                                // disableDrag
    void FUN_1409c2690(int n);                                           // learn
    void FUN_1409c26d0(int nIndex);                                      // index
    void FUN_1409c2710(int n);                                           // disable
    void FUN_1409c2750(const CString& strPath);                          // iconPath
    void FUN_1409c27c0(const CStringW& strPath);                         // iconPath
    void FUN_1409c2820(const CString& strHint);                          // slotHint
    void FUN_1409c2890(const CStringW& strHint);                         // slotHint
    void FUN_1409c28f0(const CStringW& strGuid);                         // itemGUID
    void FUN_1409c2950(int nTag);                                        // ugctag (when nonzero)
    void FUN_1409c2990(const CStringW& strCategory);                     // itemCategory
    void FUN_1409c29f0(unsigned nType);                                  // skilltype
    void FUN_1409c2a30(int n);                                           // skillmaster
    void FUN_1409c2a70(MS2Ptr<Unk_SlotSkillInfo> spSkill, int nPoints);  // upgradeCondition
    void FUN_1409c2af0(CItem* pItem, void* pPlayer);                     // the skill item cooldown
    void FUN_1409c2dc0(float fRemain);                                   // remainTime
    void FUN_1409c2e00(float fTotal);                                    // totalTime
    void FUN_1409c2e40();                                                // the cooldown unit strings
    void FUN_1409c2f40(CItemEnchantInfo* pEnchant);                      // enchant / enchantBroken
    void FUN_1409c2fe0(Unk_ItemPlusInfo* pPlus);                         // unlimited
    void FUN_1409c3040(MS2Ptr<CItemData> spData);                        // enchant of a fixed-enchant item
    void FUN_1409c30f0(MS2Ptr<CItemData> spData);                        // enchant of a lapenshard
    void FUN_1409c31b0(MS2Ptr<CItem> spItem);                            // itemSeason of an item
    void FUN_1409c3290(MS2Ptr<CItemData> spData);                        // itemSeason
    void FUN_1409c33d0();                                                // enchant = 0
    void FUN_1409c3400();                                                // gradeBG = 0
    void FUN_1409c3430(CItem* pItem);                                    // questBeginAble / questProgress
    void FUN_1409c34e0(CItem* pItem);                                    // itemSeal for the inventory break/lock modes
    void FUN_1409c3750(bool b);                                          // useRightClick
    int FUN_1409c3780();                                                 // itemID
    int FUN_1409c37f0();                                                 // itemGrade
    int FUN_1409c3860(CItem* pItem, void* pPlayer, int nFlags);          // fill the slot from an item
    int FUN_1409c41f0(CItem* pItem, void* pPc, int nSlot, int nFlags);   // fill from an item + itemBothEquip
    int FUN_1409c4360(Unk_SlotSkillInfo* pSkill, unsigned nFlags);       // fill the slot from a skill
    int FUN_1409c4510(int nItemId, int nRarity, int nCount);             // fill the slot from an item id
    int FUN_1409c4860(Unk_SlotIconSource* pSource);                     // icon of an icon source
    int FUN_1409c48b0(const CString& strText);                           // set the slot's icon path (ItemInfoSlot)
};
MS2_CHECK_SIZE(ASSlot, 0x40);
