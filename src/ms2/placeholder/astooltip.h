// astooltip.h - PLACEHOLDER for ASTooltip (RTTI .?AVASTooltip@@, base AScript, 0x58 bytes). NOT an original header.
// Ctors 0x1409c63d0 (int, int) and an (owner, int, int) variant, dtor 0x1409b4af0. Units must include this header
// instead of redefining the class.
#pragma once

#include <afx.h>
#include <atlcoll.h>                                 // ATL::CAtlList (part 2: FUN_1409dfba0)

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include <vector>                       // part 3: std::vector<ItemDropResult> member parameter (SetItemPackageList)

class CItem;
class CItemData;
template <class T> class Unk_GalleryPtr;     // unit-local smart pointer of uigalleryeventdialog.h
class Unk_GalleryItem;
template <class T> class MS2SvrPtr;          // ms2svrptr.h
class CPtred;

class ASTooltip : public ASObj
{
public:
    explicit ASTooltip(int nMovieId);                // 0x1409c62e0 (aseffect.cpp)
    ASTooltip(int a1, int a2);
    ASTooltip(void* pOwner, int a1, int a2);
    ASTooltip(class Unk_TooltipOwner* pOwner, int a1, int a2);       // 0x1409c64c0 (same body as the void* form; the owner's real type is unknown)
    ASTooltip(const Scaleform::GFx::Value& root, int nMovieId);     // 0x1409c6350 (uiadventureleveldialog.cpp)
    ASTooltip(const ASTooltip& o);                                  // 0x140f47c60 (inline COMDAT, uigamedictionarydialog.cpp)
    // ~ASTooltip is implicit (0x1409b4af0): the exe dtor stores no vftable.
    void FUN_1409c7b10(CItem* pItem);                                    // itemDamage (sum of the damage lines)
    void SetItemName(CItem* pItem);
    void SetItemGrade(CItem* pItem);
    void SetUgcTag(CItem* pItem);
    void FUN_1409c7fc0(CItem* pItem);                                    // picks the plain or the extended item layout
    void FUN_1409c9170(CItem* pItem);
    void FUN_1409cc090(CItem* pItem);
    void FUN_1409d95f0(CItem* pItem, CStringW& strOut);
    void FUN_1409d8d90(CItem* pItem, CStringW& strOut);
    void FUN_1409d9330(CItem* pItem, CStringW& strOut);
    void FUN_1409d99a0(CItem* pItem, CStringW& strOut);
    void FUN_1409d9aa0(CItem* pItem, CStringW& strOut);
    void SetItemPiece(CItemData* pData);
    void FUN_1409d43b0(CItem* pItem);
    void SetItemPetRankAndDisableShadow(CItem* pItem);
    void FUN_1409d4460(CItem* pItem);
    void FUN_1409d46a0(CItem* pItem);
    void SetItemNameById(unsigned nId);
    void FUN_1409d55a0(int nId, int n);
    void FUN_1409d8300(int n);
    void FUN_1409d77b0(int n);
    void SetItemPetFlag(unsigned nItemId);
    void SetItemCashFlag(unsigned nItemId);
    void SetItemSkinFlag(unsigned nItemId);
    void SetItemPcBangFlag(unsigned nItemId);
    void SetItemVIPFlag(unsigned nItemId);
    void SetItemWeddingFlag(unsigned nItemId);
    void SetItemEquip(const CStringW& str);
    void SetItemDamage(CStringW str);                                    // itemDamage (by value: the callee destroys it)
    void SetItemPetSkin(bool b);
    void FUN_1409dbc30(const CStringW& str);                             // set m_50
    void SetGemstoneLevel(int nItemId);
    __int64 FUN_1409c6540();                                             // m_40
    void FUN_140be62e0(void* pOwner) { m_40 = reinterpret_cast<__int64>(pOwner); }   // 0x140be62e0 set m_40 (the player; uiclosetdialog.cpp)
    unsigned GetFlags();                                            // m_48 (flags; 0x100 = no extra buttons)
    void SetFlags(unsigned n);
    void SetEnableUseDbClickDefault();                                                // enableUseDbClick = string 0x762
    void SetEnablePutonDefault();                                                // enablePuton = string 0x751 (unless flag 0x100)
    void SetEnableCompareSwapDefault();                                                // enableCompareSwap = string 0x765 (unless flag 0x100)
    void SetEnableLClick(const CStringW& strText);                         // enableLClick (unless flag 0x100)
    void ShowCloseButton();                                                // closeButton = true
    void FUN_1409c6d10(const CString& str);                              // string member DAT_143ab45a8
    void SetOffDelay(int n);
    void SetMaxWidth(int n);
    void SetTooltipAlign(int n);
    void SetTooltipClass(const CString& strClass);                         // set the AS class name
    void SetOnDelay(int n);
    void SetOffsetX(int n);
    void SetText(const CStringW& strText);                         // set the text
    void SetOffsetY(int n);
    int ApplyTextTooltip(const CStringW& strText);
    int FUN_1409e1c50(unsigned nSkillId, unsigned short nLevel, int n);       // skill tooltip (skill window)
    int FUN_1409e1770(int a1, int a2);
    int SetAchieveTooltip(unsigned nId, unsigned nGrade);                   // achievement tooltip (uiachievedialog.cpp)
    int FUN_1409e0d40(CItem* pItem);
    int FUN_1409e2750(void* pSkillAttr, int a1, unsigned a2);              // additional effect (buff) tooltip: an AdditionalLevelData, align, remaining ms (unsigned: jae/jb)
    void FUN_1409db870(Unk_GalleryPtr<Unk_GalleryItem> item);
    void SetEnablePuton(const CStringW& strTitle);                        // set the tooltip title line
    void SetEnableUseDbClick(const CStringW& strText);                         // set the tooltip text line
    void SetEnableUseDbClickBoth(const CStringW& strLhs, const CStringW& strRhs);   // enableUseDbClick on both comparison tooltips
    void FUN_1409c6ef0(const CStringW& strText);                        // append to textBgArr
    int FUN_1409e13a0(CItem* pCompare, CItem* pItem);                   // item tooltip with the default flags
    int FUN_1409e25e0(CItem* pItem, unsigned n);
    void FUN_1409cf010(CItem* pItem, unsigned n);
    int FUN_1409e13f0(CItem* pCompare, CItem* pItem, int a1, int a2);   // item tooltip with a comparison item (ItemInfoSlot)
    int FUN_1409e15a0(CItem* pEquipped, CItem* pItem, ASTooltip* pLhs, ASTooltip* pRhs);   // item tooltip compared with the equipped item (unit_141347b10)
    void SetEnablePutonBoth(const CStringW& strA, const CStringW& strB);     // set a tooltip text pair (ItemInfoSlot exchange scroll)
    void SetItemEquipBoth(const CStringW& strKey, const CStringW& strB);   // set a keyed tooltip text pair (ItemInfoSlot exchange scroll)
    void SetEnablePreview(MS2Ptr<CItem> spItem);                            // compare against this item (by value: callee destroys)
    void SetEnablePreviewBoth(MS2Ptr<CItem> spCompare, MS2Ptr<CItem> spItem);   // item tooltip with an optional comparison item (by value: callee destroys)

    // ---- astooltip.cpp part 1 members (owner: part 1 agent; append here only) ----
    void SetMaidInfo(CItem* pItem);                                    // maid item: description, name, manufacture state
    void FUN_1409c7cc0(CItem* pItem);                                    // itemMovie (unless flag 0x40)
    void FUN_1409c8020(CItem* pItem);                                    // itemStatusSet: the equipment sets of the item
    void FUN_1409c8df0(int nItemId);                                     // itemStatusSet of an UGC map set item (housing)
    void FUN_1409cb7b0(CItem* pItem);                                    // itemMerge: the merge option ranges of the item
    // ---- end part 1 ----
    // ---- astooltip.cpp part 2 members (owner: part 2 agent; append here only) ----
    void SetItemSocket(CItem* pItem);                                    // itemSocket (the socket rows)
    void FUN_1409cd5b0(CItem* pItem);                                    // itemMerge
    void SetItemIconPath(CItem* pItem);                                    // iconPath
    void FUN_1409cd750(CItem* pItem);                                    // the double-click / equip hints
    void SetItemSellPrice(CItem* pItem);                                    // itemSellPrice / notExchange
    void SetItemCreateTime(CItem* pItem);                                    // itemCreateTime (+ designOrgItemName)
    void SetItemUsePeriod(CItem* pItem);                                    // itemUsePeriod (the expiry time)
    void FUN_1409cf4d0(MS2SvrPtr<CPtred> spLife);                       // itemUsePeriod from the shop item life (NpcShopItemLife; by value: callee destroys)
    void FUN_1409cfbf0(CItem* pItem);                                    // itemCompare (the stat change of equipping)
    void FUN_1409d0710(CItem* pItem);                                    // itemDescription
    void FUN_1409d0a80(CItem* pItem);
    void FUN_1409d1d30(CItem* pItem);                                    // the main description (full or compact layout)
    void FUN_1409d1d80(CItem* pItem);
    void FUN_1409d26d0(CItem* pItem);
    bool FUN_1409d2cb0(CItem* pItem);
    // other parts' members called by part 2 (declared from the exe prologues / call sites):
    void FUN_1409d6a40(int nItemId, __int64 nMinutes);                   // part 3: the use period of an item data
    void FUN_1409d98a0(CItem* pItem, CStringW& strText);                 // part 3: append the bind limit text
    bool FUN_1409d4760(CItem* pItem);                                    // part 3: a special description was set
    void FUN_1409dfba0(MS2Ptr<CItemData> spData, ATL::CAtlList<CStringW>& list, int* pExpiring, unsigned nMax, __int64 nExpiry);   // part 4: the box contents
    int FUN_1409e0450(int nItemId, __int64 nExpiry);                     // part 5: the item expires soon
    // ---- end part 2 ----
    // ---- astooltip.cpp part 3 members (owner: part 3 agent; append here only) ----
    void FUN_1409d3010(CItem* pItem);                                    // customizeColorData
    void FUN_1409d46e0(CItem* pItem);                                    // unlimited (enchant level)
    void FUN_1409d5610(int nItemId);                                     // itemKinds
    void SetItemMovie(int nItemId);                                     // itemMovie
    void FUN_1409d5770(int nItemId);                                     // iconPath
    void FUN_1409d5850(int nItemId);                                     // (empty)
    void FUN_1409d5860(int nItemId, int nRarity);                        // not-exchange lines of a fresh item
    void SetItemDescription(int nItemId);                                     // itemDescription
    void FUN_1409d7560(int nItemId, int nRank);                          // itemPetRank
    void FUN_1409d7630(int nItemId);                                     // extraComment
    CStringW FUN_1409daa30(MS2Ptr<CItemData> spData);                    // part 4 (declared by part 3): chat emoticon comment (by value: the callee destroys it)
    void SetPetEvolution(CItem* pItem);                                    // petEvolution
    void FUN_1409d5920(int nItemId);                                     // the package rows of a box item
    void FUN_1409d8570(CItem* pItem);                                    // the break ingredients of an item
    void FUN_1409d8650(int nItemId, int nGrade, int nSockets);           // the break ingredients
    void SetUgcItemLimitRegister(MS2Ptr<CItemData> spData);                        // ugcItemLimitRegister (by value: the callee destroys it)
    void FUN_1409d88e0(MS2Ptr<CItem> spItem);                            // ugcItemLimitRegister (by value: the callee destroys it)
    void SetItemEquipText(bool bEnable);                                    // itemEquip
    void SetItemPackageList(const std::vector<class ItemDropResult>* pResults);    // part 5 (declared by part 3): the package rows
    void FUN_1409e7460(std::vector<MS2Ptr<class CIngredientInfo> >* pIngredients);                       // part 5 (declared by part 3): the break ingredient rows
    void FUN_1409d3470(CItem* pItem);                                    // extraComment (gemstone upgrade / mastery / emoticon)
    CStringW FUN_1409d9c50(CItem* pItem);                                // the extra comment of an item
    void FUN_1409d3a40(CItem* pItem);                                    // itemQuestInfo
    void SetItemLockInfo(CItem* pItem);                                    // itemLockInfo / the lock icons
    void FUN_1409d5b70(int nItemId);                                     // itemGuideDescription
    void FUN_1409d6120(int nItemId);                                     // the main description as a statDescription
    void FUN_1409d64a0(int nItemId, int nRank, int nLevel, int nAdditional);   // extraDescription
    void FUN_1409d6730(int nItemId);                                     // the maid contract description row
    void FUN_1409d7900(int nItemId);                                     // the package rows of a box item (beauty / couple / remake)
    // ---- end part 3 ----
    // ---- astooltip.cpp part 4 members (owner: part 4 agent; append here only) ----
    CStringW FUN_1409d9f30(MS2Ptr<CItemData> spData);                    // music score play count text
    CStringW FUN_1409da1c0(CItem* pItem);                                // music score period text
    CStringW FUN_1409da3d0(MS2Ptr<CItemData> spData);                    // music score period text (from the table)
    CStringW FUN_1409da690(CItem* pItem);                                // mastery recipes using the item
    CStringW FUN_1409daff0(MS2Ptr<CItemData> spData);                    // chat emoticon description
    MS2Ptr<AScript> GetRhsTooltip();                                     // rhsTooltip
    MS2Ptr<AScript> GetLhsTooltip();                                     // lhsTooltip
    void FUN_1409db870(MS2Ptr<CItemData> spData);                        // the exe's real parameter (copy 0x1403bb3b0 / dtor 0x1401b50d0)
    void FUN_1409dbbc0(CStringW str);                                    // itemName (by value)
    void SetSkillName(int nSkillId, const CStringW& strSuffix);         // skillName
    void SetSkillElement(int nSkillId);                                    // skillElement
    void SetSkillIconPath(int nSkillId);                                    // iconPath of a skill
    void FUN_1409dbfa0(int nSkillId);                                    // skill key slot hint
    void SetSkillDescription(int nSkillId, unsigned short nLevel);             // skillDescription
    void FUN_1409dc1f0(int nSkillId, unsigned short nLevel);             // statDescription (level, sp, ep, cooltime)
    void FUN_1409dc700(int nSkillId, unsigned short nLevel);             // extraDescription
    void FUN_1409dcf10(int nSkillId, unsigned short nLevel, int bFromDialog);   // requireDescription
    void FUN_1409ddc40(class CMeratMarketProduct* pProduct);              // marketDesc (UGC market product)
    void SetBuyLimitTextFromProduct(class CMeratMarketPremiumProduct* pProduct);       // the buy limit of a premium product
    void SetBuyLimitText(int nScope, int nReset, int nCount);              // the buy limit text
    void FUN_1409de140(ASArray* pRows, int nItemId, int nRank);          // the item name row
    void FUN_1409de630(ASArray* pRows, int nItemId);                     // the trade rows
    void FUN_1409dea00(ASArray* pRows, int nItemId);                     // the housing category row
    void AddJobLimitRows(ASArray* pRows, int nItemId);                     // the job limit rows
    void AddItemLevelRow(ASArray* pRows, int nItemId, int nRarity, int nLevel, int nAdditional);   // the item level row
    void AddLevelLimitRow(ASArray* pRows, int nItemId);                     // the level limit row
    void AddVipLimitRow(ASArray* pRows, int nItemId);                     // the VIP limit row
    void AddWeddingLimitRow(ASArray* pRows, int nItemId);                     // the wedding limit row
    void FUN_1409df760(ASArray* pRows, MS2Ptr<CItemData> spData);        // the gemstone upgrade row
    CStringW FUN_1409df920(MS2Ptr<CItemData> spData);                    // the icon code suffix
    void FUN_1409dfa50(CItem* pItem, int& nTransferable, int& nReady, CStringW& strName);   // the socket transfer state
    int FUN_1409dfae0(CItem* pItem);                                     // a gem can be extracted
    // ---- end part 4 ----
    // ---- astooltip.cpp part 5 members (owner: part 5 agent; append here only) ----
    int FUN_1409e2630(int nId);                                          // tooltip text by string-table id (category 9)
    int FUN_1409e1ff0(CItem* pItem, int nSkillId);                       // item vs skill comparison tooltip
    void FUN_1409e2d50(int nCount);                                      // buy limit count text
    bool FUN_1409e3190(class CMeratMarketPremiumProduct* pProduct, bool bWithName);   // merat market limited package tooltip
    // ---- end part 5 ----
    // ---- astooltip.cpp part 6 members (owner: part 6 agent; append here only) ----
    // ---- end part 6 ----

private:
    __int64 m_40; unsigned m_48; CStringW m_50;   // m_50: text (destroyed by ~ASTooltip, aseffect.cpp). 0x58 bytes: the deleting
    // dtor 0x1409ee9a0 frees 0x58, the copy ctor 0x140f47c60 / operator= 0x1409eda80 copy +0x40, +0x48, +0x50 only
};
MS2_CHECK_SIZE(ASTooltip, 0x58);
