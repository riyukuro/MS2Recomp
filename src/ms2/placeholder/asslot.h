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
    void SetItemPet(int n);                                           // itemPet
    void SetItemCash(int n);                                           // itemCash
    void SetItemSkin(int n);                                           // itemSkin
    void SetItemPcBang(bool b);                                          // itemPcBang
    void SetItemVIP(int n);                                           // itemVIP
    void SetItemWedding(int n);                                           // itemWedding
    void SetItemLock(int n);                                           // itemLock
    void SetItemConditionLock(int n);                                           // itemConditionLock
    void SetItemSeal(int n);                                           // itemSeal
    void FUN_1409c1f40(CItem* pItem);                                    // itemIconLock / itemIconUnLock
    void SetItemPiece(int n);                                           // itemPiece
    void SetGrayColor(int n);                                           // grayColor
    void SetItemEquip(int n);                                           // itemEquip
    void SetItemEquip2(int n);                                           // itemEquip2
    void SetItemSummon(int n);                                           // itemSummon
    void SetItemCountValue(unsigned n);                                      // itemCount (when nonzero)
    void SetItemCountFromItem(CItem* pItem);                                    // itemCount of a stackable item
    void SetItemColor(unsigned long nColor);                            // itemColor
    void SetItemID(unsigned nItemId);                                // itemID
    void SetItemGrade(int nGrade);                                      // itemGrade
    void SetItemPetRankAndDisableShadow(int nRank);                                       // itemPetRank (+ dropShadowDisable)
    void SetItemPetSkin(int n);                                           // itemPetSkin
    void SetItemBothEquip(int n);                                           // itemBothEquip
    void SetItemNew(int n);                                           // itemNew
    void SetItemEvent(int n);                                           // itemEvent
    void SetItemResultTag(int n);                                           // itemResultTag
    void SetItemName(const CStringW& strName);                         // itemName
    void DisableDropShadow();                                                // dropShadowDisable
    void DisableDrag();                                                // disableDrag
    void SetLearn(int n);                                           // learn
    void SetIndex(int nIndex);                                      // index
    void SetDisable(int n);                                           // disable
    void SetIconPathString(const CString& strPath);                          // iconPath
    void SetIconPath(const CStringW& strPath);                         // iconPath
    void SetSlotHintString(const CString& strHint);                          // slotHint
    void SetSlotHint(const CStringW& strHint);                         // slotHint
    void SetItemGUID(const CStringW& strGuid);                         // itemGUID
    void SetUgcTag(int nTag);                                        // ugctag (when nonzero)
    void SetItemCategory(const CStringW& strCategory);                     // itemCategory
    void SetSkillType(unsigned nType);                                  // skilltype
    void SetSkillMaster(int n);                                           // skillmaster
    void SetUpgradeCondition(MS2Ptr<Unk_SlotSkillInfo> spSkill, int nPoints);  // upgradeCondition
    void FUN_1409c2af0(CItem* pItem, void* pPlayer);                     // the skill item cooldown
    void SetRemainTime(float fRemain);                                   // remainTime
    void SetTotalTime(float fTotal);                                    // totalTime
    void SetCooldownStrings();                                                // the cooldown unit strings
    void SetItemEnchant(CItemEnchantInfo* pEnchant);                      // enchant / enchantBroken
    void SetItemUnlimitedEnchant(Unk_ItemPlusInfo* pPlus);                         // unlimited
    void SetGemstoneLevel(MS2Ptr<CItemData> spData);                        // enchant of a fixed-enchant item
    void SetLapenshardLevel(MS2Ptr<CItemData> spData);                        // enchant of a lapenshard
    void SetItemSeasonFromItem(MS2Ptr<CItem> spItem);                            // itemSeason of an item
    void SetItemSeason(MS2Ptr<CItemData> spData);                        // itemSeason
    void ClearEnchant();                                                // enchant = 0
    void ClearGradeBG();                                                // gradeBG = 0
    void SetItemQuestMark(CItem* pItem);                                    // questBeginAble / questProgress
    void FUN_1409c34e0(CItem* pItem);                                    // itemSeal for the inventory break/lock modes
    void SetUseRightClick(bool b);                                          // useRightClick
    int GetItemID();                                                 // itemID
    int GetItemGrade();                                                 // itemGrade
    int FUN_1409c3860(CItem* pItem, void* pPlayer, int nFlags);          // fill the slot from an item
    int SetEquipItem(CItem* pItem, void* pPc, int nSlot, int nFlags);   // fill from an item + itemBothEquip
    int FUN_1409c4360(Unk_SlotSkillInfo* pSkill, unsigned nFlags);       // fill the slot from a skill
    int SetItemById(int nItemId, int nRarity, int nCount);             // fill the slot from an item id
    int SetIconFromSource(Unk_SlotIconSource* pSource);                     // icon of an icon source
    int FUN_1409c48b0(const CString& strText);                           // set the slot's icon path (ItemInfoSlot)
};
MS2_CHECK_SIZE(ASSlot, 0x40);
