// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTooltip (item/skill tooltip builder, Scaleform AS bridge).
// MS2-UNIT: ?\astooltip.cpp
// MS2-RANGE: 0x1409c5210-0x1409f00e0 .text$mn
// MS2-RANGE: 0x1400c13a0-0x1400c2000 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x1409ef8a0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GASTooltip@@UEAAPEAXI@Z 0x1409ee9a0
// MS2-PIN: ??4AScript@@QEAAAEAV0@AEBV0@@Z 0x1409edaf0
// MS2-PIN: ?GetCount@?$CAtlArray@W4Unk_StatType@@V?$CDefaultElementTraits@W4Unk_StatType@@@ATL@@@ATL@@QEBA_KXZ 0x1409eecc0
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2SvrPtr@VCUGCMapSetItemInfo@@@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1409edfd0
// MS2-PIN: ?Find@?$CAtlList@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@QEBAPEAU__POSITION@@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@2@PEAU3@@Z 0x1409eea60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\astooltip.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "astooltip_local.h"

// The statics of this unit, in the exe's initializer order (.text$di).
static CString s_strDropShadowDisable = "dropShadowDisable";
static CString s_strIconPath = "iconPath";
static CString s_strItemCash = "itemCash";
static CString s_strItemCount = "itemCount";
static CString s_strItemEquip = "itemEquip";
static CString s_strItemGrade = "itemGrade";
static CString s_strItemIconLock = "itemIconLock";
static CString s_strItemPiece = "itemPiece";
static CString s_strItemIconUnLock = "itemIconUnLock";
static CString s_strItemKinds = "itemKinds";
static CString s_strItemMovie = "itemMovie";
static CString s_strItemName = "itemName";
static CString s_strItemPackageList = "itemPackageList";
static CString s_strItemPcBang = "itemPcBang";
static CString s_strItemPet = "itemPet";
static CString s_strItemSkin = "itemSkin";
static CString s_strItemVIP = "itemVIP";
static CString s_strItemWedding = "itemWedding";
static CString s_strItemBreakIngredientList = "itemBreakIngredientList";
static CString s_strItemPetRank = "itemPetRank";
static CString s_strItemPetSkin = "itemPetSkin";
static CString s_strSkillName = "skillName";
static CString s_strText = "text";
static CString s_strTooltipAlign = "tooltipAlign";
static CString s_strUgctag = "ugctag";
static CString s_strChartSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/astooltip_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"  // C3: WorldService::FUN_141bd1290
class GFxManager { public: CStringW Localize(const CString& strKey); };   // C3: the real member (0x1422b0570, a $-key's localized string)
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;
static CStringW s_wsNewline;
static CStringW s_wsWhiteFont;
static CStringW s_wsPetEvolutionPoint;
static CStringW s_wsPetExp;
static CStringW s_wsSetNameRow;
static CStringW s_wsSetName;
static CStringW s_wsSetStatRow;
static CStringW s_wsSetTitle;
static CStringW s_wsSocket;
static CStringW s_wsSocketByPet;
static CStringW s_wsSocketRowEmpty;
static CStringW s_wsSocketRowLock;
static CStringW s_wsSocketRowStat;
static CStringW s_wsSocketRowStatByPet;
static CStringW s_wsSocketTransfer;
static CStringW s_wsKindLabel[5] = {L""};      // per-kind labels, indexed by the option kind
static CStringW s_wsMerge;
static CStringW s_wsText0xbf5;
static CStringW s_wsText0x48d;
static CStringW s_wsText0xbf8;
static CStringW s_wsStatRowBest;
static CStringW s_wsUgcSetName;
static CStringW s_wsUgcSetRow;
static CStringW s_wsUnlimited;

extern CStringW GetStringCommon(int nId);

// @0x1409c6540
__int64 ASTooltip::FUN_1409c6540()
{
    return m_40;
}
MS2_REPLACE_METHOD(0x1409C6540, ASTooltip, FUN_1409c6540, 15, 0x8B0075C1);

// @0x1409c6560
unsigned ASTooltip::FUN_1409c6560()
{
    return m_48;
}
MS2_REPLACE_METHOD(0x1409C6560, ASTooltip, FUN_1409c6560, 14, 0x921EE467);

// @0x1409c6580
void ASTooltip::FUN_1409c6580(unsigned n)
{
    m_48 = n;
}
MS2_REPLACE_METHOD(0x1409C6580, ASTooltip, FUN_1409c6580, 22, 0x6608447B);

// @0x1409c65a0
void ASTooltip::SetEnableUseDbClickDefault()
{
    FUN_1407cbb20("enableUseDbClick", GetStringCommon(0x762));
}
MS2_REPLACE_METHOD(0x1409C65A0, ASTooltip, SetEnableUseDbClickDefault, 66, 0xFCB30E07);

// @0x1409c65f0
void ASTooltip::SetEnableUseDbClick(const CStringW& strText)
{
    FUN_1407cbb20("enableUseDbClick", strText);
}
MS2_REPLACE_METHOD(0x1409C65F0, ASTooltip, SetEnableUseDbClick, 72, 0x638B88F9);

// @0x1409c6880
void ASTooltip::SetEnablePutonDefault()
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enablePuton", GetStringCommon(0x751));
}
MS2_REPLACE_METHOD(0x1409C6880, ASTooltip, SetEnablePutonDefault, 85, 0xF4AF37A1);

// @0x1409c68e0
void ASTooltip::SetEnableCompareSwapDefault()
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enableCompareSwap", GetStringCommon(0x765));
}
MS2_REPLACE_METHOD(0x1409C68E0, ASTooltip, SetEnableCompareSwapDefault, 85, 0xE798AF82);

// @0x1409c6940
void ASTooltip::SetEnableLClick(const CStringW& strText)
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enableLClick", strText);
}
MS2_REPLACE_METHOD(0x1409C6940, ASTooltip, SetEnableLClick, 91, 0x7BDAE921);

// @0x1409c69b0
void ASTooltip::SetEnablePuton(const CStringW& strTitle)
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enablePuton", strTitle);
}
MS2_REPLACE_METHOD(0x1409C69B0, ASTooltip, SetEnablePuton, 91, 0x3AB5F601);

// @0x1409c6c80
void ASTooltip::FUN_1409c6c80()
{
    FUN_1407cbbe0("closeButton", true);
}
MS2_REPLACE_METHOD(0x1409C6C80, ASTooltip, FUN_1409c6c80, 34, 0x29258324);

// @0x1409c6cb0
void ASTooltip::SetText(const CStringW& strText)
{
    FUN_1407cbb20(s_strText, strText);
}
MS2_REPLACE_METHOD(0x1409C6CB0, ASTooltip, SetText, 81, 0x1E6A3D31);

// @0x1409c6d10
void ASTooltip::FUN_1409c6d10(const CString& str)
{
    FUN_1407cba60(s_strText, str);
}
MS2_REPLACE_METHOD(0x1409C6D10, ASTooltip, FUN_1409c6d10, 81, 0xB4DE3543);

// @0x1409c6d70
void ASTooltip::SetTooltipClass(const CString& strClass)
{
    FUN_1407cba60("tooltip", strClass);
}
MS2_REPLACE_METHOD(0x1409C6D70, ASTooltip, SetTooltipClass, 72, 0xEDA57631);

// @0x1409c6dc0
void ASTooltip::SetTooltipAlign(int n)
{
    FUN_1409eb310(s_strTooltipAlign, n);
}
MS2_REPLACE_METHOD(0x1409C6DC0, ASTooltip, SetTooltipAlign, 49, 0x3D4B1FA2);

// @0x1409c6e00
void ASTooltip::SetOnDelay(int n)
{
    FUN_1407cb9c0("onDelay", n);
}
MS2_REPLACE_METHOD(0x1409C6E00, ASTooltip, SetOnDelay, 40, 0x4B5EE22C);

// @0x1409c6e30
void ASTooltip::SetOffDelay(int n)
{
    FUN_1407cb9c0("offDelay", n);
}
MS2_REPLACE_METHOD(0x1409C6E30, ASTooltip, SetOffDelay, 40, 0xB08E9A97);

// @0x1409c6e60
void ASTooltip::SetOffsetX(int n)
{
    FUN_1407cb9c0("offsetX", n);
}
MS2_REPLACE_METHOD(0x1409C6E60, ASTooltip, SetOffsetX, 40, 0xFF9581A7);

// @0x1409c6e90
void ASTooltip::SetOffsetY(int n)
{
    FUN_1407cb9c0("offsetY", n);
}
MS2_REPLACE_METHOD(0x1409C6E90, ASTooltip, SetOffsetY, 40, 0x0CC6F34F);

// @0x1409c6ec0
void ASTooltip::SetMaxWidth(int n)
{
    FUN_1407cb9c0("maxWidth", n);
}
MS2_REPLACE_METHOD(0x1409C6EC0, ASTooltip, SetMaxWidth, 40, 0xD65BBE56);

// @0x1409eb310
void ASObj::FUN_1409eb310(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}
MS2_REPLACE_METHOD(0x1409EB310, ASObj, FUN_1409eb310, 152, 0x1164D0E6);


// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c62e0
ASTooltip::ASTooltip(int nMovieId)
    : ASObj(nMovieId), m_40(0), m_48(0)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c6350
ASTooltip::ASTooltip(const Scaleform::GFx::Value& root, int nMovieId)
    : ASObj(root, nMovieId), m_40(0), m_48(0)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c63d0
ASTooltip::ASTooltip(int a1, int a2)
    : ASObj(a2), m_40(0), m_48(a1)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c6440
ASTooltip::ASTooltip(void* pOwner, int a1, int a2)
    : ASObj(a2), m_40((__int64)pOwner), m_48(a1)
{
}

// @0x1409c7b10
void ASTooltip::FUN_1409c7b10(CItem* pItem)
{
    if (pItem == 0)
        return;
    CStringW str;
    FUN_1409d95f0(pItem, str);
    FUN_1409d8d90(pItem, str);
    FUN_1409d9330(pItem, str);
    FUN_1409d99a0(pItem, str);
    FUN_1409d9aa0(pItem, str);
    if (str.IsEmpty())
        return;
    FUN_1407cbb20("itemDamage", str);
}
MS2_REPLACE_METHOD(0x1409C7B10, ASTooltip, FUN_1409c7b10, 249, 0x1E53A7AB);

// @0x1409c7c10
void ASTooltip::SetItemName(CItem* pItem)
{
    FUN_1407cbb20(s_strItemName, pItem->FUN_140527b10());
}
MS2_REPLACE_METHOD(0x1409C7C10, ASTooltip, SetItemName, 80, 0x3F6AE606);

// @0x1409c7c70
void ASTooltip::SetItemGrade(CItem* pItem)
{
    FUN_1409adc90(s_strItemGrade, pItem->GetRarity());
}
MS2_REPLACE_METHOD(0x1409C7C70, ASTooltip, SetItemGrade, 66, 0xFE5BD3AD);

// @0x1409c7f70
void ASTooltip::SetUgcTag(CItem* pItem)
{
    FUN_1407cb9c0(s_strUgctag, pItem->GetUgcTag());
}
MS2_REPLACE_METHOD(0x1409C7F70, ASTooltip, SetUgcTag, 66, 0xDD1978AD);

// @0x1409c7fc0
void ASTooltip::FUN_1409c7fc0(CItem* pItem)
{
    if ((m_48 & 0x800) != 0 && (m_48 & 0x10000) == 0)
        FUN_1409cc090(pItem);
    else
        FUN_1409c9170(pItem);
}
MS2_REPLACE_METHOD(0x1409C7FC0, ASTooltip, FUN_1409c7fc0, 85, 0xF8318C61);

// @0x1409e13a0
int ASTooltip::FUN_1409e13a0(CItem* pCompare, CItem* pItem)
{
    unsigned nFlags = FUN_1409c6560();
    return FUN_1409e13f0(pCompare, pItem, nFlags, nFlags);
}
MS2_REPLACE_METHOD(0x1409E13A0, ASTooltip, FUN_1409e13a0, 71, 0x2CE140FC);

// @0x1409e25e0
int ASTooltip::FUN_1409e25e0(CItem* pItem, unsigned n)
{
    if (FUN_1409e0d40(pItem) == 0)
        return 0;
    FUN_1409cf010(pItem, n);
    return 1;
}
MS2_REPLACE_METHOD(0x1409E25E0, ASTooltip, FUN_1409e25e0, 72, 0x15346D77);

// @0x1409e26b0
int ASTooltip::ApplyTextTooltip(const CStringW& strText)
{
    if (strText.IsEmpty())
        return 0;
    SetTooltipClass("export_common_tooltip_tooltipText");
    SetText(strText);
    SetOnDelay(300);
    SetOffDelay(60000);
    return 1;
}
MS2_REPLACE_METHOD(0x1409E26B0, ASTooltip, ApplyTextTooltip, 146, 0x067A651D);

struct Unk_CommandStrings {  };

// @0x1409d4350
void ASTooltip::SetItemPiece(CItemData* pData)
{
    if (pData == 0)
        return;
    FUN_1407cbbe0(s_strItemPiece, pData->IsPieceItem());
}
MS2_REPLACE_METHOD(0x1409D4350, ASTooltip, SetItemPiece, 78, 0xFE2943FA);

// @0x1409d43b0
void ASTooltip::FUN_1409d43b0(CItem* pItem)
{
    FUN_1409d74a0(pItem->FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1409D43B0, ASTooltip, FUN_1409d43b0, 41, 0x6D4FFE0F);

// @0x1409d43e0
void ASTooltip::SetItemPetRankAndDisableShadow(CItem* pItem)
{
    if (pItem->IsPetItem() != 0)
    {
        FUN_1409adc90(s_strItemPetRank, pItem->GetRarity());
        FUN_1407cb9c0(s_strDropShadowDisable, 1);
    }
}
MS2_REPLACE_METHOD(0x1409D43E0, ASTooltip, SetItemPetRankAndDisableShadow, 112, 0x67EE15C6);

// @0x1409d4460
void ASTooltip::FUN_1409d4460(CItem* pItem)
{
    FUN_1409d8300(pItem->FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1409D4460, ASTooltip, FUN_1409d4460, 41, 0xA7E502CD);

// @0x1409d46a0
void ASTooltip::FUN_1409d46a0(CItem* pItem)
{
    if (pItem == 0)
        return;
    FUN_1409d77b0(pItem->FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1409D46A0, ASTooltip, FUN_1409d46a0, 51, 0x7A950BD3);

// @0x1409d5530
void ASTooltip::SetItemNameById(unsigned nId)
{
    FUN_1407cbb20(s_strItemName, ((CStringTable*)(Unk_CommandStrings*)(((struct Unk_CommandStrings*)TSingleton<CStringTable>::GetInstance())))->FUN_141811980(1, nId));
}
MS2_REPLACE_METHOD(0x1409D5530, ASTooltip, SetItemNameById, 93, 0xF4A248DA);

// @0x1409d55a0
void ASTooltip::FUN_1409d55a0(int nId, int n)
{
    if (n != 0)
        FUN_1409adc90(s_strItemGrade, n);
    else
        FUN_1409adc90(s_strItemGrade, 1);
}
MS2_REPLACE_METHOD(0x1409D55A0, ASTooltip, FUN_1409d55a0, 95, 0x6202B546);

MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// @0x1409d5160
void ASTooltip::SetItemPetFlag(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemPet, sp->IsPetItem());
}
MS2_REPLACE_METHOD(0x1409D5160, ASTooltip, SetItemPetFlag, 139, 0x04E59FDE);

// @0x1409d5200
void ASTooltip::SetItemCashFlag(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemCash, sp->IsCashItem());
}
MS2_REPLACE_METHOD(0x1409D5200, ASTooltip, SetItemCashFlag, 139, 0xDAA972D2);

// @0x1409d52a0
void ASTooltip::SetItemSkinFlag(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemSkin, sp->HasSkinType());
}
MS2_REPLACE_METHOD(0x1409D52A0, ASTooltip, SetItemSkinFlag, 139, 0xFD2B7855);

// @0x1409d5340
void ASTooltip::SetItemPcBangFlag(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cb9c0(s_strItemPcBang, sp->IsPCBangItem() != 0);
}
MS2_REPLACE_METHOD(0x1409D5340, ASTooltip, SetItemPcBangFlag, 156, 0x2C1CCF54);

// @0x1409d53f0
void ASTooltip::SetItemVIPFlag(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemVIP, sp->FUN_14053d1f0());
}
MS2_REPLACE_METHOD(0x1409D53F0, ASTooltip, SetItemVIPFlag, 139, 0x2426DEF4);

// @0x1409d5490
void ASTooltip::SetItemWeddingFlag(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemWedding, sp->HasWeddingLimit());
}
MS2_REPLACE_METHOD(0x1409D5490, ASTooltip, SetItemWeddingFlag, 139, 0x00739E47);

unsigned short FUN_140626f20(unsigned nItemId);

// @0x1409d74a0
void ASTooltip::FUN_1409d74a0(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp == NULL || !sp->FUN_14053d840())
        return;
    unsigned short sLevel = FUN_140626f20(sp->GetItemId());
    if (sLevel == 0)
        return;
    FUN_1409c48f0("gemstoneLevel", (short)sLevel);
}
MS2_REPLACE_METHOD(0x1409D74A0, ASTooltip, FUN_1409d74a0, 183, 0xB7CB9094);

// @0x1409d8c80
void ASTooltip::SetItemEquip(const CStringW& str)
{
    FUN_1407cbb20(s_strItemEquip, str);
}
MS2_REPLACE_METHOD(0x1409D8C80, ASTooltip, SetItemEquip, 81, 0xD3C1BF91);

// @0x1409d8ce0
void ASTooltip::SetItemDamage(CStringW str)
{
    FUN_1407cbb20("itemDamage", str);
}
MS2_REPLACE_METHOD(0x1409D8CE0, ASTooltip, SetItemDamage, 93, 0x134D71AB);

// @0x1409d8d50
void ASTooltip::SetItemPetSkin(bool b)
{
    FUN_1407cbbe0(s_strItemPetSkin, b);
}
MS2_REPLACE_METHOD(0x1409D8D50, ASTooltip, SetItemPetSkin, 50, 0x9E275AA4);

// @0x1409dbc30
void ASTooltip::FUN_1409dbc30(const CStringW& str)
{
    m_50 = str;
}
MS2_REPLACE_METHOD(0x1409DBC30, ASTooltip, FUN_1409dbc30, 42, 0xA6EBFD24);

// @0x1409e5450
bool FUN_1409e5450(int n)
{
    return n == 4;
}

// ---- chunk 1: the tooltip text pairs (w152) ----


// @0x1409c64c0
ASTooltip::ASTooltip(Unk_TooltipOwner* pOwner, int a1, int a2)
    : ASObj(a2), m_40((__int64)pOwner), m_48(a1)
{
}

// Sets the same member of the left and right comparison tooltips.
// @0x1409c6640
void ASTooltip::FUN_1409c6640(const CStringW& strLhs, const CStringW& strRhs)
{
    Scaleform::GFx::Value lhs = GetMember("lhsTooltip");
    if (((Scaleform::GFx::Value*)(void*)(&lhs))->IsUndefined() == 0)
    {
        ASObj obj(lhs, 2);
        {
            CStringW strCopy(strLhs);
            obj.FUN_1407cbb20("enableUseDbClick", strCopy);
        }
    }
    else
        FUN_1407cbb20("enableUseDbClick", strLhs);
    Scaleform::GFx::Value rhs = GetMember("rhsTooltip");
    if (((Scaleform::GFx::Value*)(void*)(&rhs))->IsUndefined() == 0)
    {
        ASObj obj(rhs, 2);
        {
            CStringW strCopy(strRhs);
            obj.FUN_1407cbb20("enableUseDbClick", strCopy);
        }
    }
    else
        FUN_1407cbb20("enableUseDbClick", strRhs);
}
MS2_REPLACE_METHOD(0x1409C6640, ASTooltip, FUN_1409c6640, 564, 0x5FB63B17);

// @0x1409c6a20
void ASTooltip::FUN_1409c6a20(const CStringW& strLhs, const CStringW& strRhs)
{
    if (m_48 & 0x100)
        return;
    Scaleform::GFx::Value lhs = GetMember("lhsTooltip");
    if (((Scaleform::GFx::Value*)(void*)(&lhs))->IsUndefined() == 0)
    {
        ASObj obj(lhs, 2);
        {
            CStringW strCopy(strLhs);
            obj.FUN_1407cbb20("enablePuton", strCopy);
        }
    }
    else
        FUN_1407cbb20("enablePuton", strLhs);
    Scaleform::GFx::Value rhs = GetMember("rhsTooltip");
    if (((Scaleform::GFx::Value*)(void*)(&rhs))->IsUndefined() == 0)
    {
        ASObj obj(rhs, 2);
        {
            CStringW strCopy(strRhs);
            obj.FUN_1407cbb20("enablePuton", strCopy);
        }
    }
    else
        FUN_1407cbb20("enablePuton", strRhs);
}
MS2_REPLACE_METHOD(0x1409C6A20, ASTooltip, FUN_1409c6a20, 589, 0x573459D7);

// Appends a text to the textBgArr array (created when missing).
// @0x1409c6ef0
void ASTooltip::FUN_1409c6ef0(const CStringW& strText)
{
    CString strHolder("textBgArr");
    CString& strName = strHolder;
    Scaleform::GFx::Value v = GetMember(strName);
    if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() != 0 || ((Scaleform::GFx::Value*)(void*)(&v))->IsNull() != 0)
    {
        ASArray arr(2);
        arr.PushWString(strText);
        FUN_1409adbe0(strName, Scaleform::GFx::Value(arr.FUN_1422bb870()));
    }
    else
    {
        ASArray arr(v, 2);
        arr.PushWString(strText);
    }
}
MS2_REPLACE_METHOD(0x1409C6EF0, ASTooltip, FUN_1409c6ef0, 355, 0xB1F3433B);

// @0x1409c7060
void ASTooltip::FUN_1409c7060(const CStringW& strLhs, const CStringW& strRhs)
{
    Scaleform::GFx::Value lhs = GetMember("lhsTooltip");
    if (((Scaleform::GFx::Value*)(void*)(&lhs))->IsUndefined() == 0)
    {
        ASObj obj(lhs, 2);
        {
            CStringW strCopy(strLhs);
            obj.FUN_1407cbb20(s_strItemEquip, strCopy);
        }
    }
    else
        FUN_1407cbb20(s_strItemEquip, strLhs);
    Scaleform::GFx::Value rhs = GetMember("rhsTooltip");
    if (((Scaleform::GFx::Value*)(void*)(&rhs))->IsUndefined() == 0)
    {
        ASObj obj(rhs, 2);
        {
            CStringW strCopy(strRhs);
            obj.FUN_1407cbb20(s_strItemEquip, strCopy);
        }
    }
    else
        FUN_1407cbb20(s_strItemEquip, strRhs);
}
MS2_REPLACE_METHOD(0x1409C7060, ASTooltip, FUN_1409c7060, 600, 0x33E89F47);

extern CStringW GetStringCommonByKey(const CStringW& strKey);
static int s_bTextsLoaded;

// @0x1409e5480  loads the tooltip texts once
void FUN_1409e5480()
{
    if (s_bTextsLoaded != 0)
        return;

    s_wsKindLabel[0] = GetStringCommon(0xbf3);
    s_wsKindLabel[2] = GetStringCommon(0xbf4);
    s_wsKindLabel[4] = GetStringCommonByKey(L"s_tooltip_itemoption_kinds_merge_1step");
    s_wsMerge = GetStringCommonByKey(L"s_tooltip_itemoption_kinds_merge");
    s_wsText0xbf5 = GetStringCommon(0xbf5);
    s_wsText0x48d = GetStringCommon(0x48d);
    s_wsText0xbf8 = GetStringCommon(0xbf8);
    s_wsStatRowBest = GetStringCommonByKey(L"s_tooltip_itemoption_stat_row_best");
    s_wsNewline = L"\n";
    s_wsText0xbf6 = GetStringCommon(0xbf6);
    s_wsText0xbf7 = GetStringCommon(0xbf7);
    s_wsEnchantExp = GetStringCommonByKey(L"s_tooltip_itemoption_enchant_exp");
    s_wsWhiteFont = L"<font color='#ffffff'>{0}</font>";
    s_wsUnlimited = GetStringCommonByKey(L"s_tooltip_itemoption_unlimited");
    s_wsSetTitle = GetStringCommonByKey(L"s_tooltip_itemoption_setitem_set_title");
    s_wsSetNameRow = GetStringCommonByKey(L"s_tooltip_itemoption_setitem_name_row");
    s_wsSetStatRow = GetStringCommonByKey(L"s_tooltip_itemoption_setitem_stat_row");
    s_wsSetName = GetStringCommonByKey(L"s_tooltip_itemoption_setitem_name");
    s_wsUgcSetName = GetStringCommonByKey(L"s_tooltip_itemoption_ugcmap_setitem_name");
    s_wsUgcSetRow = GetStringCommonByKey(L"s_tooltip_itemoption_ugcmap_setitem_row");
    s_wsSocket = GetStringCommonByKey(L"s_tooltip_itemoption_socket");
    s_wsSocketByPet = GetStringCommonByKey(L"s_tooltip_itemoption_socket_by_pet");
    s_wsSocketRowStat = GetStringCommonByKey(L"s_tooltip_itemoption_socket_row_stat");
    s_wsSocketRowStatByPet = GetStringCommonByKey(L"s_tooltip_itemoption_socket_row_stat_by_pet");
    s_wsSocketRowEmpty = GetStringCommonByKey(L"s_tooltip_itemoption_socket_row_empty");
    s_wsSocketRowLock = GetStringCommonByKey(L"s_tooltip_itemoption_socket_row_lock");
    s_wsSocketTransfer = GetStringCommonByKey(L"s_tooltip_itemoption_socket_transfer");
    s_wsPetEvolutionPoint = GetStringCommonByKey(L"s_pet_tooltip_evolution_point");
    s_wsPetExp = GetStringCommonByKey(L"s_pet_tooltip_exp");
    s_bTextsLoaded = 1;
}
// not hooked: writes the unit statics s_ws*/s_bTextsLoaded (DLL-local copies; the exe readers would see empty strings)




// Formats one stat option value row; kind 2 (random options) marks the top of the roll range as "best".
// @0x1409c5210
bool FUN_1409c5210(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, MS2Ptr<BaseOption> spOption, const CStringW& strValue)
{
    if (spItem == 0 || spOption == 0)
        return false;
    if (nKind != 2)
    {
        if (FUN_1409e5450(nKind))
        {
            strOut = StringFormat(FUN_1409e6010(nKind, spItem.get()), strValue);
            strOut = StringFormat(s_wsText0xbf8, strOut);
        }
        else
        {
            strOut = StringFormat(s_wsText0xbf8, strValue);
        }
        return true;
    }
    std::pair<int, int> range = reinterpret_cast<CItemOptionTable*>(FUN_140166430())->GetRandomOptionRange(spItem->FUN_1405276c0(), spItem->GetRarity(), nIndex);
    bool bBest = range.second == spOption->GetValue();
    if (bBest)
    {
        CStringW strBest = StringFormat(s_wsText0x48d, strValue);
        strOut = StringFormat(s_wsStatRowBest, strBest);
    }
    else if (reinterpret_cast<CItemOptionTable*>(FUN_140166430())->IsHighRollValue(spItem, nIndex, nKind, spOption->GetValue()) == true)
    {
        strOut = StringFormat(s_wsStatRowBest, strValue);
    }
    else
    {
        strOut = StringFormat(s_wsText0xbf8, strValue);
    }
    return true;
}
// not hooked: reads the unit statics s_ws* without loading them (FUN_1409e5480)

// The special option twin of FUN_1409c5210.
// @0x1409c56f0
bool FUN_1409c56f0(CStringW& strOut, MS2Ptr<CItem> spItem, int nIndex, int nKind, MS2Ptr<BaseOption> spOption, const CStringW& strValue)
{
    if (spItem == 0 || spOption == 0)
        return false;
    if (nKind != 2)
    {
        if (FUN_1409e5450(nKind))
        {
            strOut = StringFormat(FUN_1409e6010(nKind, spItem.get()), strValue);
            strOut = StringFormat(s_wsText0xbf8, strOut);
        }
        else
        {
            strOut = StringFormat(s_wsText0xbf8, strValue);
        }
        return true;
    }
    std::pair<int, int> range = reinterpret_cast<CItemOptionTable*>(FUN_140166430())->GetRandomSpecialOptionRange(spItem->FUN_1405276c0(), spItem->GetRarity(), nIndex);
    bool bBest = range.second == spOption->GetValue();
    if (bBest)
    {
        CStringW strBest = StringFormat(s_wsText0x48d, strValue);
        strOut = StringFormat(s_wsStatRowBest, strBest);
    }
    else if (reinterpret_cast<CItemOptionTable*>(FUN_140166430())->IsHighRollSpecialValue(spItem, nIndex, nKind, spOption->GetValue()) == true)
    {
        strOut = StringFormat(s_wsStatRowBest, strValue);
    }
    else
    {
        strOut = StringFormat(s_wsText0xbf8, strValue);
    }
    return true;
}
// not hooked: reads the unit statics s_ws* without loading them (FUN_1409e5480)

// Fills an item drop/reward row object (count, pet rank, icon, name, grade, gemstone level or season).
// @0x1409c5bd0
bool ASObj::FUN_1409c5bd0(ItemDropResult* pDrop)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(pDrop->m_itemId);
    if (spData == 0)
        return false;
    bool bMoney = FUN_1403ba4c0(reinterpret_cast<const int&>(pDrop->m_itemId));
    if (bMoney)
        FUN_1407cb9c0(s_strItemCount, 0);
    else
        FUN_1409c0d20(s_strItemCount, pDrop->vfunc_o18_2());
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x8c))
    {
        if (spData->IsPetItem())
        {
            FUN_1409adc90(s_strItemPetRank, pDrop->vfunc_o18_1());
            FUN_1407cb9c0(s_strDropShadowDisable, 1);
        }
    }
    else
        FUN_1407cbbe0(s_strItemPet, spData->IsPetItem());
    FUN_1407cbbe0(s_strItemCash, spData->IsCashItem());
    FUN_1407cbb20(s_strIconPath, FUN_14016a730(spData->GetIconPath(), 0));
    FUN_1407cbbe0(s_strItemSkin, spData->HasSkinType());
    if (bMoney)
    {
        CStringW strName = FUN_14028dfa0(CStringW(L"s_tooltip_fmt_in_package_money"), FUN_141425950(spData->GetItemId()), FUN_1409eb450(pDrop->vfunc_o18_2()));
        FUN_1407cbb20(s_strItemName, strName);
    }
    else
    {
        CStringW strName = FUN_141425950(spData->GetItemId());
        const CStringW& strNameRef = strName;
        if (static_cast<Unk_ItemDataIntView*>(spData.operator->())->HasPeriod())
            FUN_1407cbb20(s_strItemName, FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expiration_prefix"), strNameRef));
        else
            FUN_1407cbb20(s_strItemName, FUN_141425950(spData->GetItemId()));
    }
    FUN_1409adc90(s_strItemGrade, pDrop->vfunc_o18_1());
    if (spData->FUN_14053d840())
    {
        unsigned short nLevel = FUN_140626f20(spData->GetItemId());
        if (nLevel > 0)
            FUN_1409c48f0("gemstoneLevel", nLevel);
    }
    else if (pDrop->m_enchant > 0)
        FUN_1407cb9c0("gemstoneLevel", pDrop->m_enchant);
    else if ((unsigned)spData->GetOpenGachaBoxParam0() > 0)
    {
        int nSeason = spData->GetOpenGachaBoxParam0();
        CStringW strSeason = FUN_1409e5320(nSeason);
        FUN_1407cbb20("itemSeason", strSeason);
    }
    FUN_1407cbbe0(s_strItemPiece, spData->IsPieceItem());
    return true;
}
MS2_REPLACE_METHOD(0x1409C5BD0, ASObj, FUN_1409c5bd0, 1799, 0xE8C98E14);

// The maid contract item: the maid description row, the maid's name and the running manufacture.
// @0x1409c72c0
void ASTooltip::FUN_1409c72c0(CItem* pItem)
{
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    if (spData->FUN_14053dd30() <= 0)
        return;
    TPtrValue<MaidDesc> spDesc = CMaidDescTable::GetInstance()->Find(spData->FUN_14053dd30());
    if (!spDesc)
        return;
    TPtrValue<MaidInfo> spInfo = CMaidInfoTable::GetInstance()->Find(spData->FUN_14053dd30());
    if (!spInfo)
        return;
    CStringW strIcon(spInfo->FUN_1409eee80() != 0 ? L"export_common_icon_meso" : L"export_common_icon_merat");
    CStringW strText = BlockFormat(0x7a2, spDesc->specialty, FUN_140763e10(spInfo->salary), strIcon);
    ASObj row(2);
    row.FUN_1407cb9c0("type", 0);
    row.FUN_1407cbb20("text", strText);
    FUN_1409adbe0("statDescription", Scaleform::GFx::Value(row.FUN_1422bb870()));
    MS2Ptr<CMaid> spMaid = CUserMaidManager::GetInstance()->GetMaid(pItem->GetItemUid());
    if (spMaid.get() != 0)
    {
    CStringW strName = spMaid->FUN_1409eeda0().IsEmpty() ? ((CStringTable*)(Unk_CommandStrings*)(((struct Unk_CommandStrings*)TSingleton<CStringTable>::GetInstance())))->FUN_141811980(1, pItem->FUN_1405276c0()) : spMaid->FUN_1409eeda0();
    FUN_1409dbbc0(strName);
    MS2Ptr<CManufacture> spManufacture(0);
    if (CManufactureManager::GetInstance()->Lookup(pItem->GetItemUid(), spManufacture) != 0)
    {
        BOOL bWorking = spMaid->m_n4c == 1;
        int nStringId = bWorking ? 0x7a4 : 0x7a3;
        CTimeSpan span(spManufacture->FUN_140694200());
        CStringW strProduct(L"");
        {
            MS2Ptr<CMaidRecipe> spRecipe = CMaidRecipeTable::GetInstance()->Find(spManufacture->FUN_1409eedf0());
            if (spRecipe.get() != 0)
                strProduct = ((CStringTable*)(Unk_CommandStrings*)(((struct Unk_CommandStrings*)TSingleton<CStringTable>::GetInstance())))->FUN_141811980(1, spRecipe->productItemId);
        }
        CStringW strRemain(L"");
        if (span.GetTotalSeconds() > 0)
            strRemain = FUN_1412e1e50(span, 1, 1);
        else
            strRemain = GetStringCommon(0x7b8);
        FUN_1407cbb20("itemManufacture", FormatStringId<CStringW, CStringW>(nStringId, strProduct, strRemain));
    }
    }
}
// not hooked: reads the TSingleton<CMaid*Table/CUserMaidManager/CManufactureManager>::s_instance (DLL-local copies)

// The item movie: the UGC look's resource for UGC items (kind 0x16), else the item data's movie.
// @0x1409c7cc0
void ASTooltip::FUN_1409c7cc0(CItem* pItem)
{
    if ((m_48 & 0x40) != 0)
        return;
    {
        MS2Ptr<CItemData> spData(pItem->FUN_140527840());
        if (spData == 0)
            return;
        if (spData->GetType() == 0x16)
        {
            if (pItem->GetUgcInfo() != 0 && pItem->FUN_140525f60() != 0)
            {
                CString strMovie;
                // CItem::FUN_1405278d0 returns the placeholder name of the item's CItemUgc
                if (TSingleton<CUgcManager>::GetInstance()->FUN_1418859f0(&reinterpret_cast<CItemUgc*>(pItem->GetUgcInfo())->m_look,
                        &reinterpret_cast<CItemUgc*>(pItem->GetUgcInfo())->m_blueprint, MS2Ptr<CItem>(pItem)))
                    strMovie = reinterpret_cast<Unk_TooltipConfigPaths*>(FUN_1401d31f0())->m_strUgcMovie;
                else
                    strMovie = FUN_1410280d0(9, pItem->GetUgcInfo()->m_strName);
                FUN_1407cba60(s_strItemMovie, strMovie);
            }
        }
        else
            FUN_1407cba60(s_strItemMovie, spData->property.movie);
    }
}
MS2_REPLACE_METHOD(0x1409C7CC0, ASTooltip, FUN_1409c7cc0, 681, 0xD953CC81);

// Matches an equipped item whose data is the given set piece (the find_if predicate of FUN_1409c8020; name invented,
// the exe constructs it through a real constructor taking the id by value: 0x1409ed7f0).
struct Unk_SetPieceEquipped
{
    unsigned m_nPieceId;
    Unk_SetPieceEquipped(unsigned nPieceId) : m_nPieceId(nPieceId) {}
    bool operator()(MS2Ptr<CEquipItem> spEquip) const
    {
        if (spEquip == 0 || spEquip->GetItem() == 0)
            return false;
        if (!spEquip->GetItem()->FUN_140528980())
            return false;
        if (spEquip->FUN_1411dc7f0()->GetOriginOrItemId() == m_nPieceId)
            return true;
        return false;
    }
};

// The equipment sets of the item: per set the pieces (equipped ones highlighted) and the option parts by piece count.
// @0x1409c8020
// MS2-FUNCTIONAL: /Od frame is 0x10 larger (lambda/list temporaries placed differently); behaviour as the exe
void ASTooltip::FUN_1409c8020(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (!SetItemTable::GetInstance()->HasSetItem(pItem->FUN_140527840()->GetOriginOrItemId()))
    {
        FUN_1409c8df0(pItem->FUN_1405276c0());
        return;
    }
    int nItemGender = 2;
    int nFixedGender = pItem->HasAnyEquipSlotOf();
    if (nFixedGender == 0)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
        if (spData == 0)
            return;
        nItemGender = spData->limit.genderLimit;
    }
    if (nItemGender == 3)
        nItemGender = 2;
    FUN_1409e5480();
    int nActiveColor = 0xd205;
    int nInactiveColor = 0x505050;
    int nEquippedColor = 0xffffff;
    const CStringW& strRowFormat = s_wsSetNameRow;
    const CStringW& strPartFormat = s_wsSetTitle;
    const CStringW& strStatFormat = s_wsSetStatRow;
    std::vector<SetItemInfoPtr> sets;
    SetItemTable::GetInstance()->GetSetItemInfos(pItem->FUN_140527840()->GetOriginOrItemId(), sets);
    ASArray arr(2);
    for (unsigned i = 0; i < sets.size(); i++)
    {
        CStringW strText;
        if (sets[i]->IsDisableTooltip())
            continue;
        ATL::CAtlArray<unsigned> pieces;
        SetItemTable::GetInstance()->FUN_1407c50e0(sets[i]->FUN_1407ad550(), &pieces);
        unsigned nEquipped = 0;
        unsigned nRequired = (unsigned)sets[i]->GetItemCount();
        CStringW strPieces;
        int nPcGender = 2;
        PCBase* pPc = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1290(pItem->FUN_140526b10()));
        if (pPc == 0 && pItem->FUN_140526b10() == 0)
            pPc = reinterpret_cast<PCBase*>(FUN_1409c6540());
        std::list<MS2Ptr<CEquipItem> > equipped;
        if (pPc != 0)
        {
            reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->FUN_1416561a0())->FUN_1411e1fc0(equipped, 2);
            nPcGender = reinterpret_cast<PC*>(pPc)->FUN_141658e60();
            if (nPcGender == 3)
                nPcGender = 2;
        }
        int nGender = 2;
        if (nItemGender != 2)
            nGender = nItemGender;
        else
            nGender = nPcGender;
        bool bValid = true;
        for (unsigned j = 0; j < pieces.GetCount(); j++)
        {
            bool bClassBound = false;
            unsigned nPieceId = pieces.GetAt(j);
            MS2Ptr<CItemData> spData = FUN_14053f870(nPieceId);
            if (spData == 0)
                continue;
            int nClassCount = 4;
            for (int k = 0; k < nClassCount; k++)
            {
                if (spData->GetModelOrEmpty()->FUN_14054b450(DAT_142dbac18[k]))
                {
                    bClassBound = true;
                    break;
                }
            }
            if (!bClassBound && spData->limit.genderLimit == 2)
                continue;
            if (nGender != 2 && nGender != spData->limit.genderLimit)
            {
                bValid = false;
                break;
            }
        }
        if (!bValid)
            continue;
        for (unsigned j = 0; j < pieces.GetCount(); j++)
        {
            unsigned nPieceId = pieces.GetAt(j);
            MS2Ptr<CItemData> spData = FUN_14053f870(nPieceId);
            if (spData == 0)
                continue;
            const CStringW& strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nPieceId);
            unsigned nColor = nInactiveColor;
            if (!equipped.empty())
            {
                std::list<MS2Ptr<CEquipItem> >::iterator it = std::find_if(equipped.begin(), equipped.end(), Unk_SetPieceEquipped(nPieceId));
                if (it != equipped.end())
                {
                    nEquipped++;
                    nColor = nEquippedColor;
                }
            }
            strPieces.Append(StringFormat(strRowFormat, nColor, strName));
        }
        nEquipped = nEquipped < nRequired ? nEquipped : nRequired;
        CStringW strTitle = StringFormat(s_wsSetName, TSingleton<CStringTable>::GetInstance()->GetSetItemName(sets[i]->FUN_1407ad550(), "name"), nEquipped, nRequired);
        strText.Append(strTitle);
        strText.Append(strPieces);
        for (unsigned n = 0; n <= (unsigned)sets[i]->GetItemCount(); n++)
        {
            MS2Ptr<SetItemOptionPart> spPart = sets[i]->GetOptionPart(n);
            if (spPart == 0)
                continue;
            unsigned nColor = nInactiveColor;
            if (n <= nEquipped)
                nColor = nActiveColor;
            CStringW strPartTitle = StringFormat(strPartFormat, nColor, n);
            CStringW strOptions;
            spPart->FUN_1407bccf0([&strOptions, &strStatFormat, &nColor](const std::pair<SetItemOptionPart::StatKey, MS2Ptr<BaseOption> >& v) {
                strOptions.Append(StringFormat(strStatFormat, nColor, FUN_140631600(v.first, v.second.get())));
            });
            spPart->FUN_1407bcdb0([&strOptions, &strStatFormat, &nColor, &pItem](const std::pair<SetItemOptionPart::SpecialKey, MS2Ptr<BaseOption> >& v) {
                strOptions.Append(StringFormat(strStatFormat, nColor, FUN_140631830(v.first, v.second->GetValue(), pItem->FUN_140527840())));
            });
            const ATL::CAtlArray<int>& arrSkills = spPart->FUN_1407bc9d0();
            const ATL::CAtlArray<unsigned short>& arrLevels = spPart->FUN_1407bc9f0();
            if (!arrSkills.IsEmpty())
            {
                for (unsigned k = 0; k < arrSkills.GetCount(); k++)
                {
                    if (arrSkills[k] == 0)
                        continue;
                    CStringW strSkill = FUN_1406319f0(arrSkills[k], arrLevels[k]);
                    if (!strSkill.IsEmpty())
                        strOptions.Append(StringFormat(strStatFormat, nColor, strSkill));
                }
            }
            if (!strOptions.IsEmpty())
            {
                strText.Append(strPartTitle);
                strText.Append(strOptions);
            }
        }
        if (!strText.IsEmpty())
            arr.PushWString(strText);
    }
    FUN_1409eb1d0("itemStatusSet", arr);
}
// not hooked: reads TSingleton<SetItemTable>::s_instance (a DLL-local copy)

// The UGC map (housing) set of an item: the set name and its pieces.
// @0x1409c8df0
void ASTooltip::FUN_1409c8df0(int nItemId)
{
    MS2Ptr<ItemHousing> spHousing = TSingleton<CItemDataTable>::GetInstance()->GetHousing(nItemId);
    if (spHousing == 0)
        return;
    if (spHousing->setItemID == 0)
        return;
    UGCMapSetItemDataPtr spSet = CUGCMapSetItemTable::GetInstance()->FUN_140b9df60(spHousing->setItemID);
    if (spSet == 0)
        return;
    FUN_1409e5480();
    unsigned nColor = 0xffffff;
    ASArray arr(2);
    CStringW strUnused;
    CStringW strBody;
    for (std::map<unsigned int, UGCMapSetItemInfoPtr>::iterator it = spSet->m_items.begin(); it != spSet->m_items.end(); ++it)
    {
        int nPieceId = it->first;
        const CStringW& strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nPieceId);
        strBody.Append(StringFormat(s_wsUgcSetRow, nColor, strName));
    }
    CStringW strTitle = StringFormat(s_wsUgcSetName, TSingleton<CStringTable>::GetInstance()->GetUGCMapSetItemName(spHousing->setItemID, "name"));
    arr.PushWString(strTitle);
    arr.PushWString(strBody);
    FUN_1409eb1d0("itemStatusSet", arr);
}
MS2_REPLACE_METHOD(0x1409C8DF0, ASTooltip, FUN_1409c8df0, 883, 0x730BDFE3);

// The option block of the item tooltip ("itemStatus"): the option rows per kind, the socket and additional-effect rows,
// the enchant and unlimited-enchant rows and the enchant / pet exp gauges. Merge items show their merge ranges instead.
// @0x1409c9170
void ASTooltip::FUN_1409c9170(CItem* pItem)
{
    if (pItem == 0)
        return;
    CItemData* pData = pItem->FUN_140527840();
    if (pData == 0)
        return;
    if (pItem->FUN_140527840()->GetSubtype() == 2)
    {
        FUN_1409cb7b0(pItem);
        return;
    }
    CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(pItem->FUN_1405278a0());
    if (pStatus == 0)
        return;
    MS2Ptr<CItemOption> spOption(pStatus->m_spOption);
    if (spOption.IsNull())
        return;
    FUN_1409e5480();
    const CStringW& strRowFormat = s_wsText0xbf8;
    CStringW strKinds[5] = { L"" };
    CStringW strText;
    int bPet = pItem->IsPetItem();
    MS2Ptr<CPetData> spPet(0);
    if (bPet != 0)
        spPet = TSingleton<CPetDataTable>::GetInstance()->Find(pItem->FUN_140527840()->GetPetId());
    for (unsigned __int64 i = 0; i < 5; i++)
    {
        if (i == 1)
            continue;
        CStringW& strKind = strKinds[i];
        int nKind = (int)i;
        Unk_EnchantMap& mapStats = spOption->GetStatMap(nKind);
        Unk_SocketSpecialMap& mapSpecials = spOption->GetSpecialMap(nKind);
        Unk_OptionTextMap mapTexts(10);
        if (bPet != 0 && nKind == 2)
        {
            spOption->FUN_1405cb900(nKind, mapTexts);
        }
        else
        {
            unsigned nOrder = 0;
            for (POSITION pos = mapStats.GetStartPosition(); pos != 0; mapStats.GetNext(pos))
            {
                int nStat = mapStats.GetKeyAt(pos);
                mapTexts.SetAt(nOrder++, GetStatName(nStat));
            }
            for (POSITION pos = mapSpecials.GetStartPosition(); pos != 0; mapSpecials.GetNext(pos))
            {
                Unk_SocketSpecialStat eSpecial = mapSpecials.GetKeyAt(pos);
                mapTexts.SetAt(nOrder++, FUN_14081d380(eSpecial));
            }
        }
        int nRow = 0;
        int nTexts = (int)mapTexts.GetCount();
        for (POSITION pos = mapTexts.GetHeadPosition(); pos != 0; mapTexts.GetNext(pos))
        {
            int nStat = FindStatByName(mapTexts.GetValueAt(pos));
            if (nStat != -1)
            {
                Unk_EnchantMap::CPair* pPair = mapStats.Lookup(nStat);
                if (pPair == 0)
                    continue;
                MS2Ptr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                if (i == 0 && pData->FUN_14053f750(nStat))
                {
                    nRow++;
                    continue;
                }
                CStringW strValue;
                CStringW strRow;
                if (i == 0 && bPet != 0 && spPet.get() != 0)
                {
                    CStringW strBase;
                    CStringW strMax;
                    CStringW strRate;
                    if (spBase->HasValue())
                    {
                        __int64 nValue = spBase->GetValue();
                        float fRate = (float)__imp_floor((double)FUN_140632990(nValue, spPet->m_fConstantOptionFactor));
                        float fBase = (float)nValue;
                        __int64 nMax = (__int64)(fBase + fRate * (float)(*GetClientConstants()->PetMaxLevel.Get() - 1));
                        nValue += fRate * (float)(pItem->FUN_140528c20() - 1);
                        strValue = FUN_140631720(nStat, (int)nValue, false);
                        strBase = FUN_1409e0900(spBase->GetValue());
                        strMax = FUN_1409e0900((int)nMax);
                        strRate = FUN_1409e0900((int)fRate);
                    }
                    if (FUN_1409c5210(strRow, MS2Ptr<CItem>(pItem), nStat, nKind, spBase, strValue))
                    {
                        strKind.Append(strRow);
                        CStringW strDesc = FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_stat_row_pet_constant_desc"), strBase, strMax, strRate);
                        strKind.Append(strDesc);
                    }
                }
                else
                {
                    strValue = FUN_140631600(nStat, spBase.get());
                    if (FUN_1409c5210(strRow, MS2Ptr<CItem>(pItem), nStat, nKind, spBase, strValue))
                        strKind.Append(strRow);
                }
                nRow++;
                continue;
            }
            {
                Unk_SocketSpecialStat eSpecial = (Unk_SocketSpecialStat)FUN_14081d260(mapTexts.GetValueAt(pos));
                if (eSpecial != 0)
                {
                    Unk_SocketSpecialMap::CPair* pPair = mapSpecials.Lookup(eSpecial);
                    if (pPair == 0)
                        continue;
                    MS2Ptr<BaseOption> spBase(pPair->m_value);
                    if (!spBase)
                        continue;
                    CStringW strValue;
                    CStringW strRow;
                    if (i == 0 && bPet != 0 && spPet.get() != 0)
                    {
                        CStringW strBase;
                        CStringW strMax;
                        CStringW strRate;
                        if (spBase->HasValue())
                        {
                            int nValue = spBase->GetValue();
                            float fRate = (float)floor(FUN_1406198a0(nValue, spPet->m_fConstantOptionFactor));
                            float fBase = (float)nValue;
                            float fMax = fBase + fRate * (float)(*GetClientConstants()->PetMaxLevel.Get() - 1);
                            nValue += fRate * (float)(pItem->FUN_140528c20() - 1);
                            strValue = FUN_140631830(eSpecial, nValue, pItem->FUN_140527840());
                            int nRaw = spBase->GetValue();
                            strBase = StringFormat(L"{0:0.1f}", nRaw);
                            strMax = StringFormat(L"{0:0.1f}", fMax);
                            strRate = StringFormat(L"{0:0.1f}", fRate);
                        }
                        if (FUN_1409c56f0(strRow, MS2Ptr<CItem>(pItem), eSpecial, nKind, spBase, strValue))
                        {
                            strKind.Append(strRow);
                            CStringW strDesc = FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_stat_row_pet_constant_desc"), strBase, strMax, strRate);
                            strKind.Append(strDesc);
                        }
                    }
                    else
                    {
                        strValue = FUN_140631830(eSpecial, spBase->GetValue(), pItem->FUN_140527840());
                        if (FUN_1409c56f0(strRow, MS2Ptr<CItem>(pItem), eSpecial, nKind, spBase, strValue))
                            strKind.Append(strRow);
                    }
                    nRow++;
                    continue;
                }
            }
        }
    }
    if ((m_48 & 0x10000) != 0)
    {
        CStringW& strSocket = strKinds[2];
        if (pItem->IsPetItem())
        {
            unsigned nCount = FUN_14072fd00(pItem->GetRarity());
            strSocket.Append(StringFormat(s_wsText0xbf8, FUN_14028dfa0(CStringW(L"s_pet_item_option_count"), nCount)));
        }
    }
    if (pItem->FUN_140526390())
    {
        CStringW& strConstant = strKinds[0];
        unsigned nCount = (unsigned)pItem->FUN_140527840()->additionalEffect.ids.GetCount();
        ItemAdditionalEffect& effect = pItem->FUN_140527840()->additionalEffect;
        for (unsigned j = 0; j < nCount; j++)
        {
            MS2Ptr<AdditionalLevelData> spLevel = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(effect.ids[j], effect.levels[j]);
            if (spLevel == 0)
                continue;
            if (!spLevel->IsVisibleItemOption())
                continue;
            CStringW strOption = FUN_1406319f0(effect.ids[j], effect.levels[j]);
            if (strOption.IsEmpty())
                continue;
            strConstant.Append(StringFormat(strRowFormat, strOption));
        }
    }
    CStringW strSeparator(s_wsText0xbf5);
    for (unsigned __int64 k = 0; k < 5; k++)
    {
        if (FUN_1409e5450((int)k))
            continue;
        CStringW& strKind = strKinds[k];
        if (strKind.IsEmpty())
            continue;
        if (!strSeparator.IsEmpty() && !strText.IsEmpty())
            strText.Append(strSeparator);
        strText.Append(StringFormat(FUN_1409e6010((int)k, pItem), strKind));
    }
    MS2Ptr<CItemEnchantInfo> spEnchant(pStatus->GetEnchant());
    if (spEnchant != 0)
    {
        if (spEnchant->FUN_14058c8a0() == 0)
        {
            Unk_EnchantMap& mapEnchant = spEnchant->GetOptions();
            if (!mapEnchant.IsEmpty())
            {
                CStringW strRows;
                for (POSITION pos = mapEnchant.GetStartPosition(); pos != 0; mapEnchant.GetNext(pos))
                {
                    int nStat = mapEnchant.GetKeyAt(pos);
                    MS2Ptr<BaseOption> spBase(mapEnchant.GetValueAt(pos));
                    if (!spBase)
                        continue;
                    CStringW strStat = FUN_140631af0(nStat, spBase, pStatus);
                    strRows.Append(StringFormat(strRowFormat, strStat));
                }
                if (!strRows.IsEmpty())
                {
                    if (!strText.IsEmpty())
                        strText.Append(strSeparator);
                    CStringW strBlock = StringFormat(s_wsText0xbf6, strRows);
                    strText.Append(strBlock);
                }
            }
        }
        if (CItemEnchantLimitTable::GetInstance()->FUN_14058df90(pItem))
        {
            int nPercent = pItem->GetEnchantCharge() * 100 / 10000;
            int nNeed = 0;
            int nCur = 0;
            int nStep = pItem->FUN_140528f90();
            if (nStep > 0)
            {
                nNeed = (int)(10000.0f / (float)nStep + 0.5f);
                nCur = pItem->GetEnchantCharge() / nStep;
            }
            CStringW strExp = StringFormat(L"{0} / {1}", nCur, nNeed);
            CStringW strLabel = StringFormat(s_wsEnchantExp);
            if (spEnchant->NeedsChargeVersionUpdate())
                strLabel = GetStringCommonByKey(L"s_tooltip_itemoption_enchant_exp_refund");
            CStringW strSep(s_wsText0xbf5);
            if (!strText.IsEmpty())
                strText.Append(strSep);
            strText.Append(strLabel);
            strText.Append(L"gauge:\n\n");
            FUN_1407cbb20("itemEnchantExpString", strExp);
            FUN_1407cb9c0("itemEnchantExpPercent", nPercent);
        }
    }
    MS2Ptr<UnlimitedEnchantInfo> spUnlimited(reinterpret_cast<UnlimitedEnchantInfo*>(pStatus->FUN_140630d90()));
    if (spUnlimited.get() ? true : false)
    {
        if (spUnlimited->GetLevel() > 0)
        {
            CStringW strRows;
            const UnlimitedEnchantInfo::OptionMap& mapOptions = spUnlimited->FUN_1408bc2d0();
            if (mapOptions.size() > 0)
            {
                for (UnlimitedEnchantInfo::OptionMap::const_iterator it = mapOptions.begin(), itEnd = mapOptions.end(); it != itEnd; ++it)
                {
                    int nKey = it->first;
                    MS2Ptr<BaseOption> spBase(it->second);
                    CStringW strRow;
                    if (nKey == 0x1c || nKey == 0x1b || nKey == 0x14)
                        strRow = FUN_140631af0(nKey, spBase, pStatus);
                    else
                        strRow = FUN_140631600(nKey, spBase.get());
                    strRows.Append(StringFormat(strRowFormat, strRow));
                }
            }
            const UnlimitedEnchantInfo::SecondaryMap& mapSpecials = spUnlimited->FUN_1408bc3b0();
            if (mapSpecials.size() > 0)
            {
                for (UnlimitedEnchantInfo::SecondaryMap::const_iterator it = mapSpecials.begin(), itEnd = mapSpecials.end(); it != itEnd; ++it)
                {
                    int nSpecial = it->first;
                    MS2Ptr<BaseOption> spBase(it->second);
                    CStringW strRow = FUN_140631830(nSpecial, spBase->GetValue(), pItem->FUN_140527840());
                    strRows.Append(StringFormat(strRowFormat, strRow));
                }
            }
            if (!strRows.IsEmpty())
            {
                if (!strText.IsEmpty())
                    strText.Append(strSeparator);
                int nLevel = spUnlimited->GetLevel();
                CStringW strBlock = StringFormat(s_wsUnlimited, nLevel, strRows);
                strText.Append(strBlock);
            }
        }
    }
    if (pItem->IsPetItem())
    {
        MS2Ptr<CPetData> spPetData = TSingleton<CPetDataTable>::GetInstance()->Find(pItem->FUN_140527840()->GetPetId());
        if ((spPetData.get() ? true : false) && spPetData->m_nType == 1)
        {
            __int64 nExp = pItem->FUN_140528b90();
            __int64 nNeed = reinterpret_cast<CExpTable*>(FUN_1404a1bb0())->GetPetExp(pItem->FUN_140528c20(), pItem->GetRarity(), pItem->FUN_1405282d0());
            int nPercent = 0;
            if (nNeed > 0)
                nPercent = (int)(nExp * 100 / nNeed);
            CStringW strExp;
            strExp.Format(L"%s", (const wchar_t*)FUN_14028dfa0(CStringW(L"s_common_cur_max_ingredient"), FUN_1409404f0(nExp), FUN_1409404f0(nNeed)));
            CStringW strLabel = StringFormat(s_wsPetExp);
            CStringW strSep(s_wsText0xbf5);
            if (!strText.IsEmpty())
                strText.Append(strSep);
            strText.Append(strLabel);
            strText.Append(L"gauge:\n\n");
            if (pItem->FUN_140528c20() < *GetClientConstants()->PetMaxLevel.Get())
            {
                FUN_1407cbb20("itemEnchantExpString", strExp);
                FUN_1407cb9c0("itemEnchantExpPercent", nPercent);
            }
            else
            {
                FUN_1407cbb20("itemEnchantExpString", GetStringCommonByKey(L"s_mag_skillbook_max_level"));
                FUN_1407cb9c0("itemEnchantExpPercent", 100);
            }
        }
    }
    FUN_1407cbb20("itemStatus", strText);
}
// not hooked: reads TSingleton<CItemEnchantLimitTable>::s_instance (a DLL-local copy)

// The merge option ranges of the item (the first normal and the first special option of its merge slot).
// @0x1409cb7b0
void ASTooltip::FUN_1409cb7b0(CItem* pItem)
{
    if (pItem == 0 || pItem->FUN_140527840() == 0)
        return;
    CItemStatus* pEnchant = pItem->FUN_1405278a0();
    if (pEnchant == 0)
        return;
    FUN_1409e5480();
    CStringW strText;
    CStringW strRows;
    int nStat = -1;
    if (CItemMergeOptionTable::GetInstance()->FUN_1405c03d0(pItem->FUN_140527840()->FUN_14053de10(), &nStat))
    {
        CStringW strRange;
        // FUN_1405c0610 returns the option's whole-range variation (option + 0x20); the shared header calls it Unk_MergeRange*
        CItemMergeOptionVariation* pVariation = reinterpret_cast<CItemMergeOptionVariation*>(CItemMergeOptionTable::GetInstance()->FUN_1405c0610(pItem->FUN_140527840()->FUN_14053de10(), nStat));
        if (pVariation != 0)
        {
            if (IsStatKindOne(nStat))
            {
                CStringW strMin = FUN_1409e0900(pVariation->FUN_1405beac0());
                CStringW strMax = FUN_1409e0900(pVariation->FUN_1405beae0());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), GetStatCommonText(nStat), strMin, strMax);
            }
            else
            {
                CStringW strMin = FUN_1409e0a90(pVariation->FUN_1405beb00());
                CStringW strMax = FUN_1409e0a90(pVariation->FUN_1405beb20());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), GetStatCommonText(nStat), strMin, strMax);
            }
            strRows.Append(StringFormat(s_wsText0xbf8, strRange));
        }
    }
    int nSpecial = 0;
    if (CItemMergeOptionTable::GetInstance()->FUN_1405c04f0(pItem->FUN_140527840()->FUN_14053de10(), &nSpecial))
    {
        CStringW strRange;
        CItemMergeOptionVariation* pVariation = reinterpret_cast<CItemMergeOptionVariation*>(CItemMergeOptionTable::GetInstance()->FUN_1405c0740(pItem->FUN_140527840()->FUN_14053de10(), nSpecial));
        if (pVariation != 0)
        {
            if (FUN_14081dc50(nSpecial))
            {
                CStringW strMin = FUN_1409e0900(pVariation->FUN_1405beac0());
                CStringW strMax = FUN_1409e0900(pVariation->FUN_1405beae0());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), FUN_140630e10(nSpecial), strMin, strMax);
            }
            else
            {
                CStringW strMin = FUN_1409e0a90(pVariation->FUN_1405beb00());
                CStringW strMax = FUN_1409e0a90(pVariation->FUN_1405beb20());
                strRange = FUN_14028dfa0(CStringW(L"s_tooltip_itemmerge_option_range"), FUN_140630e10(nSpecial), strMin, strMax);
            }
            strRows.Append(StringFormat(s_wsText0xbf8, strRange));
        }
    }
    if (strRows.IsEmpty())
        return;
    CStringW strMerge(s_wsText0xbf5);
    if (!strMerge.IsEmpty() && !strText.IsEmpty())
        strText.Append(strMerge);
    FUN_14083d2b0(strRows);
    int nStep = 0;
    strText.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_kinds_merge_step"), nStep, strRows));
    strText.TrimRight();
    FUN_1407cbb20("itemMerge", strText);
}
// not hooked: reads TSingleton<CItemMergeOptionTable>::s_instance (a DLL-local copy)

// @0x1409cc090
void ASTooltip::FUN_1409cc090(CItem* pItem)
{
    if (pItem == 0)
        return;
    CItemData* pData = pItem->FUN_140527840();
    if (pData == 0)
        return;
    CItemStatus* pEnchant = pItem->FUN_1405278a0();
    if (pEnchant == 0)
        return;
    MS2Ptr<CItemOption> spOption(reinterpret_cast<CItemStatus*>(pEnchant)->m_spOption);
    if (spOption.IsNull())
        return;
    {
        unsigned nTotal = 0;
        int nSocketOptions = 0;
        int nSkip = 0;
        int nOptions = 0;
        int nAdditional = 0;
        FUN_1409e5480();
        ATL::CAtlMap<int, MS2Ptr<BaseOption>, Unk_EnchantKeyTraits, ATL::CElementTraits<MS2Ptr<BaseOption> > >& mapStats = spOption->GetStatMap(0);
        for (POSITION pos = mapStats.GetStartPosition(); pos != 0; mapStats.GetNext(pos))
        {
            int nStat = mapStats.GetKeyAt(pos);
            if (pData->FUN_14053f750(nStat))
            {
                if (nStat == 0x1b || nStat == 0x1c)
                    nSkip = 2;
                else
                    nSkip = 1;
            }
        }
        if (pItem->FUN_140526390())
        {
            unsigned nCount = (unsigned)pItem->FUN_140527840()->additionalEffect.ids.GetCount();
            ItemAdditionalEffect& effect = pItem->FUN_140527840()->additionalEffect;
            for (unsigned i = 0; i < nCount; i++)
            {
                MS2Ptr<AdditionalLevelData> spLevel = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(effect.ids[i], effect.levels[i]);
                if (spLevel == 0)
                    continue;
                if (!spLevel->IsVisibleItemOption())
                    continue;
                CStringW strOption = FUN_1406319f0(effect.ids[i], effect.levels[i]);
                if (strOption.IsEmpty())
                    continue;
                nAdditional++;
            }
        }
        nOptions = spOption->GetGroupOptionCount(0);
        nSocketOptions = pItem->FUN_14052a060();
        nTotal = nOptions - nSkip + nSocketOptions + nAdditional;
        CStringW strText;
        if (nTotal >= 1)
        {
            CStringW strCount;
            if (pItem->IsPetItem())
                strCount = FUN_14028dfa0(CStringW(L"s_pet_item_option_count"), nTotal);
            else
                strCount = BlockFormat(0x7a8, nTotal);
            strText.Append(StringFormat(s_wsWhiteFont, strCount));
        }
        unsigned nMaxSockets = reinterpret_cast<CItemSocketTable*>(FUN_14052d200())->GetMaxSocketCount(pItem->FUN_140527840()->property.socketDataId, pItem->GetRarity(), MS2Ptr<CItemData>(pItem->FUN_140527840()));
        if (nMaxSockets > 0 && pItem->IsPetItem() == 0)
        {
            bool bShow = (FUN_1409c6560() & 0x4000) == 0;
            if (bShow)
            {
                if (!strText.IsEmpty())
                    strText.Append(L"\n");
                strText.Append(StringFormat(s_wsWhiteFont, FUN_14028dfa0(CStringW(L"s_itemsocketsystem_socket_maxcount"), nMaxSockets)));
            }
        }
        FUN_1407cbb20("itemStatus", strText);
    }
}
MS2_REPLACE_METHOD(0x1409CC090, ASTooltip, FUN_1409cc090, 1897, 0xE19E2303);


// The socket rows of an item (itemSocket): one row per open socket (gemstone options, bind/trade limits), the locked
// sockets, or the empty rows of the compact layout.
// @0x1409cc800
// MS2-FUNCTIONAL: frame/temporary layout differs from the exe
void ASTooltip::FUN_1409cc800(CItem* pItem)
{
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x2e))
        return;
    if (pItem == 0 || pItem->FUN_140527840() == 0 || pItem->GetSocket() == 0)
        return;
    if (pItem->HasSkin() != 0 && !reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x5e))
        return;
    CItemSocket* pSocket = pItem->GetSocket();
    unsigned nFlags = FUN_1409c6560();
    if (nFlags & 0x800)
    {
        bool bHide = !(nFlags & 0x4000);
        if (bHide)
            return;
        if (pItem->IsPetItem() == 0)
        {
            const CStringW& strRowEmpty = s_wsSocketRowEmpty;
            CStringW strRows;
            if (pSocket->GetMaxSlot() == 0)
            {
                unsigned nMax = reinterpret_cast<CItemSocketTable*>(FUN_14052d200())->GetMaxSocketCount(pItem->FUN_140527840()->property.socketDataId, pItem->GetRarity(),
                                                              MS2Ptr<CItemData>(pItem->FUN_140527840()));
                for (unsigned i = 0; i < nMax; i++)
                    strRows.Append(strRowEmpty);
            }
            else
            {
                unsigned nOpen = pSocket->GetOpenSlotCount();
                for (unsigned i = 0; i < nOpen; i++)
                    strRows.Append(strRowEmpty);
                unsigned nLocked = pSocket->GetLockedSlotCount();
                if (nLocked > 0)
                {
                    const CStringW& strRowLock = s_wsSocketRowLock;
                    for (unsigned i = 0; i < nLocked; i++)
                        strRows.Append(strRowLock);
                }
            }
            const CStringW& strSocket = s_wsSocket;
            FUN_1407cbb20("itemSocket", StringFormat(strSocket, strRows));
        }
    }
    else
    {
        if (pSocket->GetMaxSlot() == 0)
            return;
        FUN_1409e5480();
        const CStringW& strRowEmpty = s_wsSocketRowEmpty;
        const CStringW& strRowStat = s_wsSocketRowStat;
        const CStringW& strRowStatByPet = s_wsSocketRowStatByPet;
        const CStringW& strTransfer = s_wsSocketTransfer;
        CStringW strSeparator(L", ");
        CStringW strRows;
        unsigned nOpen = pSocket->GetOpenSlotCount();
        for (unsigned i = 0; i < nOpen; i++)
        {
            MS2Ptr<TSocketGemStoneInfo> spGem = pSocket->GetGemInfo(i);
            if (spGem == 0 || spGem->m_nGemId == 0)
            {
                if (pItem->IsPetItem() == 0)
                    strRows.Append(strRowEmpty);
                continue;
            }
            int nGemId = spGem->m_nGemId;
            MS2Ptr<CItemData> spData = FUN_14053f870(nGemId);
            if (spData == 0)
            {
                if (pItem->IsPetItem() == 0)
                    strRows.Append(strRowEmpty);
                continue;
            }
            CStringW strOption = FUN_14062ae60(nGemId);
            if (spData->HasAdditionalEffect())
            {
                unsigned nCount = spData->additionalEffect.ids.GetCount();
                const ItemAdditionalEffect& effect = spData->additionalEffect;
                for (unsigned j = 0; j < nCount; j++)
                {
                    MS2Ptr<AdditionalLevelData> spLevel = TSingleton<SkillDataTableCli>::GetInstance()->FUN_140aafef0(effect.ids[j], effect.levels[j]);
                    if (spLevel == 0)
                        continue;
                    if (!spLevel->IsVisibleItemOption())
                        continue;
                    CStringW strEffect = FUN_1406319f0(effect.ids[j], effect.levels[j]);
                    if (strEffect.IsEmpty())
                        continue;
                    if (strOption.IsEmpty())
                        strOption.Append(strEffect);
                    else
                    {
                        strOption.AppendChar(L'\n');
                        strOption.Append(FUN_14028dfa0(CStringW(L"s_tooltip_itemoption_socket_additional"), strEffect));
                    }
                }
            }
            int nPersonal = CItemSocket::IsGemShopSellable(pSocket, spData, spGem);
            int nTradeable = CItemSocket::FUN_1406221c0(pSocket, spData, spGem);
            CStringW strName = spGem->GetBindName();
            int nBindable = spData->FUN_14053d7c0();
            int nBound = !strName.IsEmpty();
            CStringW strText = FUN_1409e6120(pItem, nTradeable, nPersonal, nBindable, nBound, strSeparator, 0, strName, 0);
            if (!strText.IsEmpty())
                strText = StringFormat(strTransfer, strText);
            if (pItem->IsPetItem() != 0)
                strRows.Append(StringFormat(strRowStatByPet, strOption, strText));
            else
            {
                CStringW strGem = FUN_14062b310(spGem);
                strRows.Append(StringFormat(strRowStat, FUN_140627390(nGemId), strOption, strText, strGem));
            }
        }
        if (pItem->IsPetItem() != 0)
        {
            if (!strRows.IsEmpty())
            {
                const CStringW& strSocket = s_wsSocketByPet;
                FUN_1407cbb20("itemSocket", StringFormat(strSocket, strRows));
            }
        }
        else
        {
            unsigned nLocked = pSocket->GetLockedSlotCount();
            if (nLocked > 0)
            {
                const CStringW& strRowLock = s_wsSocketRowLock;
                for (unsigned i = 0; i < nLocked; i++)
                    strRows.Append(strRowLock);
            }
            const CStringW& strSocket = s_wsSocket;
            FUN_1407cbb20("itemSocket", StringFormat(strSocket, strRows));
        }
    }
}
// not hooked: the compact-layout branch reads the unit statics s_ws* without calling FUN_1409e5480() first

// itemMerge: the merge option description.
// @0x1409cd5b0
void ASTooltip::FUN_1409cd5b0(CItem* pItem)
{
    FUN_1409e5480();
    CStringW strMerge = TSingleton<CItemMergeOptionTable>::GetInstance()->FUN_1405c1090(MS2Ptr<CItem>(pItem), 1);
    if (strMerge.GetLength() != 0)
    {
        CStringW strText = StringFormat(L"{0}{1}", s_wsMerge, strMerge);
        FUN_1407cbb20("itemMerge", strText);
    }
}
// not hooked: TSingleton<CItemMergeOptionTable>::GetInstance reads the DLL-local s_instance

// @0x1409cd6b0
void ASTooltip::SetItemIconPath(CItem* pItem)
{
    FUN_1407cbb20(s_strIconPath, FUN_14016a730(pItem->FUN_140528590(), 0));
}
MS2_REPLACE_METHOD(0x1409CD6B0, ASTooltip, SetItemIconPath, 143, 0x5DBF3A1B);

// The double-click / equip hints of an item that the player does not wear.
// @0x1409cd750
void ASTooltip::FUN_1409cd750(CItem* pItem)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = reinterpret_cast<PC*>(FUN_1409c6540())->GetEquipByUid(pItem->GetItemUid());
    if (spEquip.get() != 0)
        FUN_1407cbb20(s_strItemEquip, GetStringCommon(0x58a));
    else if ((m_48 & 0x80) != 0)
    {
        if (FUN_1409e6c80(pItem) != 0)
        {
            SetEnablePutonDefault();
            if (pItem->FUN_140527840()->FUN_14053d510())
                SetEnableCompareSwapDefault();
        }
        if (pItem->FUN_140525a80() != 0)
        {
            if (pItem->IsStoryBook() != 0)
                SetEnableUseDbClick(GetStringCommon(0x763));
            else if (pItem->FUN_140527840()->FUN_14053cd10())
            {
                if (pItem->FUN_140525730())
                    SetEnableUseDbClickDefault();
            }
            else if ((unsigned)pItem->FUN_140527840()->FUN_14053ddb0() > 0)
                SetEnableUseDbClick(GetStringCommonByKey(L"s_msg_dclick_open_shop"));
            else
                SetEnableUseDbClickDefault();
        }
    }
}
MS2_REPLACE_METHOD(0x1409CD750, ASTooltip, FUN_1409cd750, 606, 0xD4640D82);

// itemSellPrice and the trade limits (notExchange).
// @0x1409cd9c0
// MS2-FUNCTIONAL: temporary/frame layout differs from the exe
void ASTooltip::FUN_1409cd9c0(CItem* pItem)
{
    if (pItem == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
    if (spData == 0)
        return;
    MS2Ptr<CItemTransfer> spTransfer(pItem->FUN_140527930());
    if (spTransfer == 0)
        return;
    if (spData->FUN_14053cb80())
    {
        MS2Ptr<ItemHousing> spHousing = TSingleton<CItemDataTable>::GetInstance()->GetHousing(spData->GetItemId());
        if (spHousing == 0)
            return;
        if (spTransfer->IsSellable() != 0)
        {
            CStringW strText;
            strText.Format(L"%s : %s", (const wchar_t*)GetStringCommon(0x587),
                           (const wchar_t*)FUN_1418fec00(spHousing->priceCount, pItem->GetSellPrice(), true));
            FUN_1407cbb20("itemSellPrice", strText);
        }
        else if (spHousing->FUN_140549470(pItem->FUN_1405276c0(), pItem->GetItemUid(), pItem->GetUgcUid()) != 0)
        {
            __int64 nPrice = reinterpret_cast<CGameRule*>(FUN_1401c0d90())->FUN_14047bc50((Unk_SaleHousingKey)spHousing->filter, spHousing->priceCount, spHousing->price);
            CStringW strText;
            strText.Format(L"%s : %s", (const wchar_t*)GetStringCommon(0x6f9), (const wchar_t*)FUN_1418fec00(spHousing->priceCount, nPrice, true));
            FUN_1407cbb20("itemSellPrice", strText);
        }
    }
    else if (spTransfer->IsSellable() != 0)
    {
        CStringW strText;
        strText.Format(L"%s : %s", (const wchar_t*)GetStringCommon(0x587), (const wchar_t*)FUN_1418fec00(1, pItem->GetSellPrice(), true));
        FUN_1407cbb20("itemSellPrice", strText);
    }
    CStringW strText;
    if ((m_48 & 0x2000) == 0)
    {
        int nTradeable = FUN_140633a20(MS2Ptr<CItem>(pItem));
        int nPersonal = spTransfer->IsSellable();
        CStringW strBindName;
        int nBindable = 0;
        int nBindOnGet = 0;
        FUN_1409dfa50(pItem, nBindable, nBindOnGet, strBindName);
        int nCount = spTransfer->HasTradeCountLeft() != 0 ? spTransfer->GetCount() : 0;
        strText = FUN_1409e6120(pItem, nTradeable, nPersonal, nBindable, nBindOnGet, L"\n", nCount, strBindName, FUN_1409dfae0(pItem));
        FUN_1409d98a0(pItem, strText);
        if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xa7) && spData->HasSkinType() && spTransfer->CanTransferSocket() == 0)
        {
            strText.Append(L"\n");
            strText.Append(GetStringCommonByKey(L"s_word_item_limit_socket_transfer"));
        }
    }
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x8d) && pItem->IsPetItem() != 0)
    {
        MS2Ptr<CPetData> spPet = TSingleton<CPetDataTable>::GetInstance()->Find(pItem->FUN_140527840()->GetPetId());
        if ((spPet.get() != 0 ? true : false) && spPet->m_nType == 0)
        {
            if (!strText.IsEmpty())
                strText.Append(L"\n");
            strText.Append(GetStringCommonByKey(L"s_word_limit_petcompose"));
        }
    }
    CStringW strCouple = pItem->GetCoupleName();
    if (!strCouple.IsEmpty())
    {
        if (!strText.IsEmpty())
            strText.Append(L"\n");
        strText.Append(FUN_14028dfa0(CStringW(L"s_couple_effect_partner"), strCouple));
    }
    FUN_1407cbb20("notExchange", strText);
}
MS2_REPLACE_METHOD(0x1409CD9C0, ASTooltip, FUN_1409cd9c0, 3106, 0x09CDE211);

// itemCreateTime: the creation time of a crafted item, or the UGC design time and the original item name.
// @0x1409ce5f0
void ASTooltip::FUN_1409ce5f0(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (pItem->HasCubeTextureMesh() != 0 || pItem->FUN_140526010() != 0)
    {
        CUgcItemLook* pLook = pItem->GetUgcLook();
        if (pLook == 0)
            return;
        __int64 nUid = pLook->m_n18;
        if (nUid == 0)
        {
            CStringW strText = GetStringCommon(0x46a);
            FUN_1407cbb20("itemCreateTime", strText);
        }
        else
        {
            CMsTime time(pLook->m_n50);
            int nYear = time.GetYear();
            int nMonth = time.GetMonth();
            int nDay = time.GetDay();
            int nHour = time.GetHour();
            int nMinute = time.GetMinute();
            int nSecond = time.GetSecond();
            CStringW strText = BlockFormat(0xb7, pLook->m_str48, nYear, nMonth, nDay, nHour, nMinute, nSecond);
            FUN_1407cbb20("itemCreateTime", strText);
            CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, pItem->FUN_1405276c0());
            FUN_1407cbb20("designOrgItemName", strName);
        }
    }
    else if (pItem->FUN_140525680())
    {
        CStringW strTime = pItem->FUN_140529890();
        if (!strTime.IsEmpty())
            FUN_1407cbb20("itemCreateTime", FormatStringId<CStringW>(0x9c2, strTime));
    }
}
MS2_REPLACE_METHOD(0x1409CE5F0, ASTooltip, FUN_1409ce5f0, 852, 0xD65B232C);

// itemUsePeriod: the expiry time of an item (or its shop life / item data period).
// @0x1409ce950
void ASTooltip::FUN_1409ce950(CItem* pItem)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
    if (spData == 0)
        return;
    Unk_ItemSlot188 spLife = pItem->FUN_14052b8c0();
    if (pItem->FUN_140528910() > 0)
    {
        if (pItem->IsPetItem() == 0)
        {
            CMsTime time(pItem->FUN_140528910());
            int nYear = time.GetYear();
            int nMonth = time.GetMonth();
            int nDay = time.GetDay();
            int nHour = time.GetHour();
            int nMinute = time.GetMinute();
            CStringW strText(L"");
            if (pItem->FUN_140527840() != 0 && pItem->FUN_140527840()->HasMaidId())
                strText = pItem->IsExpired() ? BlockFormat(0xbb, nYear, nMonth, nDay, nHour, nMinute) : BlockFormat(0xba, nYear, nMonth, nDay, nHour, nMinute);
            else if (pItem->FUN_140527840() != 0 && pItem->FUN_140527840()->IsPCBangItem())
                strText = pItem->IsExpired() ? BlockFormat(0xbd, nYear, nMonth, nDay, nHour, nMinute) : BlockFormat(0xbc, nYear, nMonth, nDay, nHour, nMinute);
            else
                strText = pItem->IsExpired() ? BlockFormat(0xb9, nYear, nMonth, nDay, nHour, nMinute) : BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute);
            FUN_1407cbb20("itemUsePeriod", strText);
        }
    }
    else
    {
        if ((CPtred*)spLife != 0 && static_cast<NpcShopItemLife*>(spLife.get())->FUN_14026f0f0())
            // the slot holds the item's NpcShopItemLife (C3 #10: was the Unk_ShopLifeRef view)
            FUN_1409cf4d0(spLife);
        else if (static_cast<Unk_ItemDataIntView*>(spData.operator->())->HasPeriod() || spData->IsPCBangItem())
            FUN_1409d6a40(pItem->FUN_1405276c0(), 0);
    }
}
MS2_REPLACE_METHOD(0x1409CE950, ASTooltip, FUN_1409ce950, 1710, 0x68CBE9AD);

// itemUsePeriod: the use period in minutes as "{days}{ hours}{ minutes}".
// @0x1409cf010
void ASTooltip::FUN_1409cf010(CItem* pItem, unsigned n)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->FUN_1405276c0());
    if (spData == 0)
        return;
    if (n > 0)
    {
        CStringW strText(L"");
        CStringW strDays(L"");
        CStringW strHours(L"");
        CStringW strMinutes(L"");
        __time64_t tSpan = n * 60;
        ATL::CTimeSpan span(tSpan);
        if (span.GetDays() > 0)
            strDays = FormatStringId<__int64>(0xc5, span.GetDays());
        if (span.GetHours() > 0)
        {
            strHours = FormatStringId<long>(0xc6, span.GetHours());
            if (span.GetDays() > 0)
                strHours = StringFormat(L" {0}", strHours);
        }
        if (span.GetMinutes() > 0)
        {
            strMinutes = FormatStringId<long>(199, span.GetMinutes());
            if (span.GetDays() > 0 || span.GetHours() > 0)
                strMinutes = StringFormat(L" {0}", strMinutes);
        }
        strText = StringFormat(L"{0}{1}{2}", strDays, strHours, strMinutes);
        if (spData->IsPCBangItem())
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xc3, strText));
        else if (spData->HasMaidId())
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xc4, strText));
        else
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xc2, strText));
    }
}
// (hook registration line kept off line numbers used by astooltip.cpp: the thunk names use __LINE__)
MS2_REPLACE_METHOD(0x1409CF010, ASTooltip, FUN_1409cf010, 1208, 0x498EDCFE);

// itemUsePeriod of a shop item life: a duration (1), an end date (2), weekly (3) or monthly (4) expiry.
// @0x1409cf4d0
void ASTooltip::FUN_1409cf4d0(MS2SvrPtr<CPtred> spLife)
{
    if (spLife == 0)
        return;
    switch (static_cast<NpcShopItemLife*>(spLife.get())->m_type)
    {
    case 1:
    {
        CStringW strText(L"");
        CStringW strDays(L"");
        CStringW strHours(L"");
        CStringW strMinutes(L"");
        __time64_t tSpan = (unsigned)(static_cast<NpcShopItemLife*>(spLife.get())->m_value * 60);
        ATL::CTimeSpan span(tSpan);
        if (span.GetDays() > 0)
            strDays = FormatStringId<__int64>(0xc5, span.GetDays());
        if (span.GetHours() > 0)
        {
            strHours = FormatStringId<long>(0xc6, span.GetHours());
            if (span.GetDays() > 0)
                strHours = StringFormat(L" {0}", strHours);
        }
        if (span.GetMinutes() > 0)
        {
            strMinutes = FormatStringId<long>(199, span.GetMinutes());
            if (span.GetDays() > 0 || span.GetHours() > 0)
                strMinutes = StringFormat(L" {0}", strMinutes);
        }
        strText = StringFormat(L"{0}{1}{2}", strDays, strHours, strMinutes);
        FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xbe, strText));
        break;
    }
    case 2:
    {
        int nYear = static_cast<NpcShopItemLife*>(spLife.get())->m_time.GetYear();
        int nMonth = static_cast<NpcShopItemLife*>(spLife.get())->m_time.GetMonth();
        int nDay = static_cast<NpcShopItemLife*>(spLife.get())->m_time.GetDay();
        int nHour = static_cast<NpcShopItemLife*>(spLife.get())->m_time.GetHour();
        int nMinute = static_cast<NpcShopItemLife*>(spLife.get())->m_time.GetMinute();
        FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xbf, BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute)));
        break;
    }
    case 3:
    {
        unsigned nWeeks = static_cast<NpcShopItemLife*>(spLife.get())->m_value;
        if (nWeeks == 0)
            nWeeks = 1;
        FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_weekly"), nWeeks));
        break;
    }
    case 4:
    {
        unsigned nMonths = static_cast<NpcShopItemLife*>(spLife.get())->m_value;
        if (nMonths == 0)
            nMonths = 1;
        FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_monthly"), nMonths));
        break;
    }
    }
}
// not hooked: by-value MS2SvrPtr<CPtred> parameter (the callee destroys it)

// itemCompare: the stat change of equipping the item (stats, special stats, the item level score).
// @0x1409cfbf0
void ASTooltip::FUN_1409cfbf0(CItem* pItem)
{
    MyPC* pPC = reinterpret_cast<MyPC*>(efd::DynamicCast<Unk_AkoMyPC, PCBase>((PCBase*)m_40));
    if (pPC == 0)
        return;
    if ((m_48 & 0x800) != 0)
        return;
    if (pItem->FUN_140527840()->GetType() != 1)
        return;
    static ATL::CAtlArray<Unk_StatType, ATL::CDefaultElementTraits<Unk_StatType> > s_aStatOrder;   // the stat display order
    if (s_aStatOrder.IsEmpty())
    {
        s_aStatOrder.Add((Unk_StatType)0x1c);
        s_aStatOrder.Add((Unk_StatType)0x1d);
        s_aStatOrder.Add((Unk_StatType)0x1e);
        s_aStatOrder.Add((Unk_StatType)0x14);
        s_aStatOrder.Add((Unk_StatType)4);
        s_aStatOrder.Add((Unk_StatType)7);
        s_aStatOrder.Add((Unk_StatType)10);
        s_aStatOrder.Add((Unk_StatType)0xe);
        s_aStatOrder.Add((Unk_StatType)0x20);
        s_aStatOrder.Add((Unk_StatType)0);
        s_aStatOrder.Add((Unk_StatType)1);
        s_aStatOrder.Add((Unk_StatType)2);
        s_aStatOrder.Add((Unk_StatType)3);
        s_aStatOrder.Add((Unk_StatType)0x17);
        s_aStatOrder.Add((Unk_StatType)0x18);
        s_aStatOrder.Add((Unk_StatType)0xd);
        s_aStatOrder.Add((Unk_StatType)0xf);
        s_aStatOrder.Add((Unk_StatType)0x11);
        s_aStatOrder.Add((Unk_StatType)0x19);
        s_aStatOrder.Add((Unk_StatType)0x1a);
        s_aStatOrder.Add((Unk_StatType)0x12);
        s_aStatOrder.Add((Unk_StatType)0x10);
        s_aStatOrder.Add((Unk_StatType)0x13);
        s_aStatOrder.Add((Unk_StatType)0x15);
        s_aStatOrder.Add((Unk_StatType)0x16);
        s_aStatOrder.Add((Unk_StatType)0x1f);
        s_aStatOrder.Add((Unk_StatType)5);
        s_aStatOrder.Add((Unk_StatType)6);
        s_aStatOrder.Add((Unk_StatType)8);
        s_aStatOrder.Add((Unk_StatType)9);
        s_aStatOrder.Add((Unk_StatType)0xb);
        s_aStatOrder.Add((Unk_StatType)0xc);
    }
    int aStat[35] = {0};
    int aSpecial[207] = {0};
    int nScore = 0;
    pPC->FUN_141523e60(pItem, aStat, aSpecial, &nScore);
    ASArray arr(2);
    for (unsigned i = 0; i < s_aStatOrder.GetCount(); i++)
    {
        int nStat = s_aStatOrder[i];
        if (aStat[nStat] != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20("statName", GetStatCommonText(nStat));
            if (IsStatKindTwo(nStat))
                obj.FUN_1407cbb20("statRate", FUN_1409e0b40(abs(aStat[nStat])));
            else
                obj.FUN_1407cbb20("statValue", FUN_1409e0900(abs(aStat[nStat])));
            obj.FUN_1407cbbe0("up", aStat[nStat] > 0 ? true : false);
            arr.PushValue(obj.FUN_1422bb870());
        }
    }
    for (unsigned i = 0; i < 0xcf; i++)
    {
        int nStat = i;
        CStringW strName = FUN_140630e10(nStat);
        if (strName.IsEmpty())
            continue;
        if (aSpecial[nStat] != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cbb20("statName", strName);
            if (FUN_14081dcd0(nStat))
                obj.FUN_1407cbb20("statRate", FUN_1409e0b40(abs(aSpecial[nStat])));
            else
                obj.FUN_1407cbb20("statValue", FUN_1409e0900(abs(aSpecial[nStat])));
            obj.FUN_1407cbbe0("up", aSpecial[nStat] > 0 ? true : false);
            arr.PushValue(obj.FUN_1422bb870());
        }
    }
    if (nScore != 0)
    {
        ASObj obj(2);
        obj.FUN_1407cbb20("statName", GetStringCommonByKey(L"s_common_item_level"));
        obj.FUN_1407cbb20("statRate", FUN_1409e0900(abs(nScore)));
        obj.FUN_1407cbbe0("up", nScore > 0 ? true : false);
        arr.PushValue(obj.FUN_1422bb870());
    }
    FUN_1409adbe0("itemCompare", arr.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409CFBF0, ASTooltip, FUN_1409cfbf0, 2840, 0xE852E99E);

// itemDescription: the music score / UGC text, else the string table's tooltipDescription.
// @0x1409d0710
void ASTooltip::FUN_1409d0710(CItem* pItem)
{
    if (pItem == 0)
        return;
    int bCustom = 0;
    CStringW strDesc;
    if (pItem->HasCubeTextureMesh() != 0 || pItem->FUN_140526010() != 0)
    {
        Unk_ItemUgcInfo* pUgc = pItem->GetUgcInfo();
        if (pUgc != 0)
        {
            if (reinterpret_cast<CItemUgc*>(pUgc)->FUN_1406321a0() != 0)
            {
                bCustom = 1;
                strDesc = GetStringCommon(0xf3);
            }
            else if (reinterpret_cast<CItemUgc*>(pItem->GetUgcInfo())->GetLookLocalPath().GetLength() > 0)
            {
                bCustom = 1;
                strDesc.Empty();
            }
        }
    }
    else if (pItem->FUN_140525790())
    {
        MS2Ptr<ItemMusicScore> spScore = TSingleton<CItemDataTable>::GetInstance()->GetMusicScore(pItem->FUN_140527840()->GetItemId());
        if ((ItemMusicScore*)spScore != 0)
        {
            bCustom = 1;
            int nMax = spScore->FUN_14054ade0();
            strDesc = BlockFormat<int>(0x9be, nMax);
        }
    }
    if (bCustom != 0)
        FUN_1407cbb20("itemDescription", strDesc);
    else
    {
        CStringW strText = TSingleton<CStringTable>::GetInstance()->GetItemDescription(pItem->FUN_1405276c0(), "tooltipDescription");
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
        FUN_1407cbb20("itemDescription", strText);
    }
}
MS2_REPLACE_METHOD(0x1409D0710, ASTooltip, FUN_1409d0710, 873, 0xFBAEFA73);

// itemGuideDescription: the guide text of an item (box contents, billboard limits, object rights, housing limits and
// the trophy requirement), followed by m_50.
// @0x1409d0a80
void ASTooltip::FUN_1409d0a80(CItem* pItem)
{
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    int bCustom = 0;
    CStringW strDesc;
    if (pItem->HasCubeTextureMesh() != 0 || pItem->FUN_140526010() != 0)
    {
        Unk_ItemUgcInfo* pUgc = pItem->GetUgcInfo();
        if (pUgc != 0)
        {
            if (reinterpret_cast<CItemUgc*>(pUgc)->FUN_1406321a0() != 0 || reinterpret_cast<CItemUgc*>(pUgc)->GetLookLocalPath().GetLength() > 0)
            {
                bCustom = 1;
                strDesc.Empty();
            }
        }
    }
    else if (pItem->FUN_140525790())
    {
        bCustom = 1;
        strDesc = GetStringCommon(0x9bf);
    }
    else if (pItem->FUN_140527840()->FUN_14053ccc0() && reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xad))
    {
        bCustom = 1;
        strDesc = TSingleton<CStringTable>::GetInstance()->GetItemDescription(pItem->FUN_1405276c0(), "guideDescription");
        strDesc += GetStringCommonByKey(L"s_multi_riding_item_desc");
    }
    CStringW strResult;
    if (bCustom != 0)
    {
        PCBase* pPC = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPC != 0)
        {
            unsigned nA = FUN_141901d20(pItem->FUN_1405276c0(), pItem->GetItemUid(), pItem->GetUgcUid());
            unsigned nB = FUN_141901f70(pItem->FUN_1405276c0(), pItem->GetItemUid(), pItem->GetUgcUid());
            if (nA > 0 || nB > 0)
            {
                if (!strDesc.IsEmpty())
                    strDesc.Append(L"\n");
                strDesc.Append(BlockFormat(0x6fd, nB, nA));
            }
        }
        strResult = strDesc;
    }
    else
    {
        CStringW strGuide = TSingleton<CStringTable>::GetInstance()->GetItemDescription(pItem->FUN_1405276c0(), "guideDescription");
        if (spData->GetType() == 0x1a)
        {
            int bExpiring = 0;
            const unsigned nMaxCount = 15;
            ATL::CAtlList<CStringW> list;
            FUN_1409dfba0(spData, list, &bExpiring, nMaxCount, pItem->FUN_140528910());
            if (!list.IsEmpty())
            {
                CStringW strItems;
                POSITION pos = list.GetHeadPosition();
                for (; pos != 0; list.GetNext(pos))
                    strItems.Append(list.GetAt(pos));
                strGuide.Append(L"\n\n");
                strGuide.Append(GetStringCommonByKey(L"s_gachaitem_acquire"));
                strGuide.Append(L"\n");
                strGuide.Append(strItems);
                strGuide.Append(L"\n");
                strGuide.Append(GetStringCommonByKey(L"s_gachaitem_open_desc"));
                if (bExpiring != 0)
                {
                    strGuide.Append(L"\n");
                    strGuide.Append(GetStringCommonByKey(L"s_item_end_time_tooltip_expiration_notice"));
                }
            }
        }
        else if (spData->HasFunction() == true && spData->function.name == L"InstallBillBoard")
        {
            if (DAT_143ab2964 > 0)
                strGuide.Append(FUN_14028dfa0(CStringW(L"s_special_item_billboard_tooltip_limit_defence_spamer_level"), DAT_143ab2964));
            if (DAT_143ab2970 > 0)
                strGuide.Append(FUN_14028dfa0(CStringW(L"s_special_item_billboard_tooltip_limit_defence_spamer_adventure_level"), DAT_143ab2970));
        }
        else
        {
            int nObjCode = pItem->FUN_140527840()->install.objCode;
            if (nObjCode != 0)
            {
                if (FUN_1407077c0(nObjCode) != 0)
                    strGuide = FormatStringId<CStringW>(0xafa, strGuide);
                if (FUN_140707710(nObjCode) != 0)
                    strGuide = FormatStringId<CStringW>(0xaf9, strGuide);
            }
            if (spData->FUN_14053cb80())
            {
                MS2Ptr<ItemHousing> spHousing = TSingleton<CItemDataTable>::GetInstance()->GetHousing(spData->GetItemId());
                if (spHousing == 0)
                    return;
                unsigned short nLevel = spHousing->interiorLevel;
                unsigned nTrophyId = spHousing->trophyID;
                unsigned nTrophyLevel = spHousing->trophyLevel;
                int nPriceCount = spHousing->priceCount;
                bool bServer = false;
                if (FUN_140930c50())
                    bServer = true;
                if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xdb) && nLevel > 0 && nPriceCount == 1)
                {
                    UGCCubeCategoryTable::InteriorPtr spInterior = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetInterior(spHousing->categoryIndex);
                    if (spInterior.get() != 0)
                    {
                        nLevel = nLevel > spInterior->m_nRequireLevel ? nLevel : spInterior->m_nRequireLevel;
                    }
                    bool bShow = false;
                    if (bServer)
                    {
                        if (nLevel > DAT_143ab2940)
                            bShow = true;
                    }
                    else
                    {
                        if (nLevel > DAT_143ab291c)
                            bShow = true;
                    }
                    if (bShow)
                    {
                        if (!strGuide.IsEmpty())
                            strGuide.Append(L"\n");
                        strGuide.Append(BlockFormat(0x6fa, nLevel));
                    }
                }
                bool bTrophy = false;
                if (bServer)
                {
                    Unk_TrophyKey key;
                    key.m_nId = nTrophyId;
                    key.m_nLevel = nTrophyLevel;
                    if (DAT_143ab32d8.find(key) != DAT_143ab32d8.end())
                        bTrophy = true;
                }
                else
                {
                    if (reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsGradeCleared(nTrophyId, nTrophyLevel) == 0)
                        bTrophy = true;
                }
                if (bTrophy)
                {
                    CStringW strTrophy = FUN_14093bd40(nTrophyId, nTrophyLevel, CStringW(L""));
                    if (!strTrophy.IsEmpty())
                    {
                        if (!strGuide.IsEmpty())
                            strGuide.Append(L"\n");
                        strGuide.Append(FUN_14028dfa0(CStringW(L"s_construct_require_trophy"), strTrophy));
                    }
                }
                PCBase* pPC = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
                if (!bServer && pPC != 0)
                {
                    unsigned nA = FUN_141901d20(pItem->FUN_1405276c0(), pItem->GetItemUid(), pItem->GetUgcUid());
                    unsigned nB = FUN_141901f70(pItem->FUN_1405276c0(), pItem->GetItemUid(), pItem->GetUgcUid());
                    if (nA > 0 || nB > 0)
                    {
                        if (!strGuide.IsEmpty())
                            strGuide.Append(L"\n");
                        strGuide.Append(BlockFormat(0x6fd, nB, nA));
                    }
                }
            }
            else
            {
                if (spData->GetType() == 0x19 && FUN_1409e0450(pItem->FUN_1405276c0(), pItem->FUN_140528910()) != 0)
                {
                    strGuide.Append(L"\n");
                    strGuide.Append(GetStringCommonByKey(L"s_item_end_time_tooltip_expiration_notice"));
                }
            }
        }
        strResult = strGuide;
    }
    if (!m_50.IsEmpty())
    {
        if (!strResult.IsEmpty())
            strResult.Append(L"\n");
        strResult.Append(m_50);
    }
    FUN_1407cbb20("itemGuideDescription", strResult);
}
// not hooked: TSingleton<UGCCubeCategoryTable>::GetInstance reads the DLL-local s_instance

// The main description in the full (0x800 clear) or the compact layout.
// @0x1409d1d30
void ASTooltip::FUN_1409d1d30(CItem* pItem)
{
    if ((m_48 & 0x800) != 0)
        FUN_1409d26d0(pItem);
    else
        FUN_1409d1d80(pItem);
}
MS2_REPLACE_METHOD(0x1409D1D30, ASTooltip, FUN_1409d1d30, 68, 0x120E11D7);

// statDescription (full layout): the main description, the pet size-up level, the chat emoticon, the book, a special
// description or the music score text.
// @0x1409d1d80
void ASTooltip::FUN_1409d1d80(CItem* pItem)
{
    if (pItem == 0)
        return;
    MS2Ptr<CItemEnchantInfo> spEnchant(pItem->FUN_1405278a0()->GetEnchant());
    if (!spEnchant)
        return;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData.IsNull())
        return;
    CStringW strMain = TSingleton<CStringTable>::GetInstance()->GetItemDescription(pItem->FUN_1405276c0(), "mainDescription");
    if (strMain.GetLength() > 0)
    {
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strMain);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (pItem->IsPetItem() != 0)
    {
        MS2Ptr<CPetData> spPet = TSingleton<CPetDataTable>::GetInstance()->Find(pItem->FUN_140527840()->GetPetId());
        if ((bool)spPet.get() && spPet->m_nType == 1)
        {
            CStringW strText;
            unsigned short nLevel = pItem->FUN_140528c20();
            strText.Format(L"%s", (const wchar_t*)FUN_14028dfa0(CStringW(L"s_word_petlevel_sizeup"), nLevel));
            ASObj row(2);
            row.FUN_1407cb9c0("type", 0);
            row.FUN_1407cbb20("text", strText);
            FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        }
        return;
    }
    if (spData->IsFunctionName(L"ChatEmoticonAdd"))
    {
        CStringW strText = FUN_1409daff0(spData);
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (pItem->HasQuestStartFunction() != 0)
    {
        int nBookId = pItem->FUN_140527840()->GetQuestStartQuestId();
        CStringW strText = FUN_1416e4df0(nBookId);
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (FUN_1409d4760(pItem))
        return;
    if (pItem->FUN_140527840()->FUN_14053cd10())
    {
        CStringW strText = FUN_1409da1c0(pItem);
        if (strText.IsEmpty())
            return;
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
}
MS2_REPLACE_METHOD(0x1409D1D80, ASTooltip, FUN_1409d1d80, 2376, 0x9D5E3B93);

// statDescription (compact layout).
// @0x1409d26d0
void ASTooltip::FUN_1409d26d0(CItem* pItem)
{
    if (pItem == 0)
        return;
    MS2Ptr<CItemEnchantInfo> spEnchant(pItem->FUN_1405278a0()->GetEnchant());
    if (!spEnchant)
        return;
    CStringW strMain = TSingleton<CStringTable>::GetInstance()->GetItemDescription(pItem->FUN_1405276c0(), "mainDescription");
    if (strMain.GetLength() > 0)
    {
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strMain);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
    if (pItem->IsPetItem() != 0)
    {
        MS2Ptr<CPetData> spPet = TSingleton<CPetDataTable>::GetInstance()->Find(pItem->FUN_140527840()->GetPetId());
        if ((bool)spPet.get() && spPet->m_nType == 1)
        {
            CStringW strText;
            unsigned short nLevel = pItem->FUN_140528c20();
            strText.Format(L"%s", (const wchar_t*)FUN_14028dfa0(CStringW(L"s_word_petlevel_sizeup"), nLevel));
            ASObj row(2);
            row.FUN_1407cb9c0("type", 0);
            row.FUN_1407cbb20("text", strText);
            FUN_1409adbe0("statDescription", row.FUN_1422bb870());
            return;
        }
    }
    if (FUN_1409d4760(pItem))
        return;
    if (pItem->FUN_140527840()->FUN_14053cd10())
    {
        CStringW strText = FUN_1409da1c0(pItem);
        if (strText.IsEmpty())
            return;
        ASObj row(2);
        row.FUN_1407cb9c0("type", 0);
        row.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", row.FUN_1422bb870());
        return;
    }
}
MS2_REPLACE_METHOD(0x1409D26D0, ASTooltip, FUN_1409d26d0, 1490, 0xE8CE7567);

// customizeColor: the dye hint of a customizable item.
// @0x1409d2cb0
bool ASTooltip::FUN_1409d2cb0(CItem* pItem)
{
    MyPC* pPC = (MyPC*)FUN_1409c6540();
    if (pPC == 0)
        return false;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return false;
    bool bCustomizable = spData->FUN_14053e170();
    if (!bCustomizable)
        return false;
    CStringW strText;
    bool bEquipCheck = (m_48 & 4) > 0;
    bool bHasColor = spData->FUN_14053e2b0(0) >= 0;
    if (bEquipCheck && !bHasColor)
    {
        MS2Ptr<CEquipItem> spEquip = pPC->GetEquipByUid(pItem->GetItemUid());
        if (spEquip == 0)
        {
            CStringW strLines;
            strLines.Format(L"%s\n%s", (const wchar_t*)GetStringCommon(0x9b8), (const wchar_t*)GetStringCommon(0x9b7));
            strText = strLines;
        }
        else
            strText = GetStringCommon(0x9b7);
    }
    else
        strText = GetStringCommon(0x9b7);
    FUN_1407cbb20("customizeColor", strText);
    return true;
}
MS2_REPLACE_METHOD(0x1409D2CB0, ASTooltip, FUN_1409d2cb0, 857, 0x9F20292B);


// @0x1409d3010
void ASTooltip::FUN_1409d3010(CItem* pItem)
{
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xb7))
        return;
    __int64 nOwner = FUN_1409c6540();
    if (nOwner == 0)
        return;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    if (spData->FUN_14053e260() == 0)
        return;
    bool bFixed = (m_48 & 4) > 0 || (m_48 & 0x8000) > 0;
    bool bHasDefault = spData->FUN_14053e2b0(0) >= 0;
    if (bFixed && !bHasDefault)
        return;
    // the proxy data of an item is its CItemExtraData (CItem::FUN_140527870 returns the proxy base)
    Unk_PayloadPtr<CItemExtraData> spExtra(reinterpret_cast<CItemExtraData*>(pItem->FUN_140527870()));
    if (spExtra == 0)
        return;
    int nPalette = spExtra->GetSlotPaletteId(0);
    int nColorSN = spExtra->GetSlotColorId(0);
    if (nPalette == 0 || nColorSN < 0)
        return;
    MS2Ptr<ItemColorEx> spColor = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColorBySN(nPalette, nColorSN);
    if (spColor == 0 || spColor->m_n2c == 0)
        return;
    ASObj obj(2);
    {
        ASObj color(2);
        bool bAlt = false;
        FUN_140f33250(color, spColor, spData, bAlt);
        obj.FUN_1409adbe0("color", color.FUN_1422bb870());
        obj.FUN_1407cbb20("desc", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x48, spColor->m_n2c));
    }
    FUN_1409adbe0("customizeColorData", obj.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3010, ASTooltip, FUN_1409d3010, 1104, 0x85F94BBB); }

// @0x1409d3470
void ASTooltip::FUN_1409d3470(CItem* pItem)
{
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData == 0)
        return;
    CStringW str;
    if (spData->FUN_14053cd10())
        str = FUN_1409d9c50(pItem);
    else if (spData->FUN_14053d840())
    {
        if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x2e))
            return;
        MS2Ptr<CItemGemStoneData> spRow = FUN_14062c280()->FindData(spData->GetItemId());
        if ((bool)spRow)
        {
            if (!FUN_140627020(spRow))
            {
                str = GetStringCommon(0x9c3);
                CIngredientContainer* pIngredients = &spRow->m_ingredients;
                if (!pIngredients->FUN_14026bf70())
                {
                    str.Append(L"\n");
                    CStringW strList;
                    size_t nCount = pIngredients->FUN_14026bf10();
                    for (size_t i = 0; i < nCount; i++)
                    {
                        Unk_IngRef ref = pIngredients->FUN_14026be50(i);
                        if (ref == 0)
                            continue;
                        if (!strList.IsEmpty())
                            strList.Append(L", ");
                        CIngredientInfo* pInfo = ref.operator->();
                        strList.Append(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, pInfo->m_a));
                    }
                    str.Append(FUN_14028dfa0(L"s_msg_tooltip_gemstone_enable_upgrade_ingredients", strList));
                }
            }
        }
    }
    else if (spData->GetType() == 0x10)
        str = FUN_1409da690(pItem);
    else if (spData->IsFunctionName(L"ChatEmoticonAdd"))
        str = FUN_1409daa30(spData);
    if (!str.IsEmpty())
        FUN_1407cbb20("extraComment", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3470, ASTooltip, FUN_1409d3470, 1471, 0xBE16A635); }

// @0x1409d3a40
void ASTooltip::FUN_1409d3a40(CItem* pItem)
{
    PCBase* pPc = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    ATL::CAtlArray<Unk_QuestItemLink> arrLinks;
    reinterpret_cast<CQuestManager*>(FUN_140764020())->GetQuestItemLinks(MS2Ptr<CItem>(pItem), arrLinks);
    if (arrLinks.GetCount() != 0)
    {
        int bEquipQuest = 0;
        CStringW strQuests;
        for (size_t i = 0; i < arrLinks.GetCount(); i++)
        {
            if (arrLinks[i].m_kind == 0)
            {
                CStringW strKey;
                switch (arrLinks[i].m_state)
                {
                case 1:
                    strKey = L"s_msg_tooltip_quest_name_progress";
                    break;
                case 0:
                    strKey = L"s_msg_tooltip_quest_name";
                    break;
                case 2:
                    strKey = L"s_msg_tooltip_quest_name_complete";
                    break;
                }
                if (strQuests.GetLength() != 0)
                    strQuests += L", ";
                strQuests += FUN_1416e5210(arrLinks[i].m_questId, strKey);
            }
            else if (arrLinks[i].m_kind == 1)
                bEquipQuest = 1;
        }
        CStringW strInfo;
        if (strQuests.GetLength() != 0)
            strInfo = FUN_14028dfa0(L"s_msg_tooltip_quest_info", strQuests);
        if (bEquipQuest != 0)
        {
            if (strInfo.GetLength() != 0)
                strInfo += "\n";
            strInfo += GetStringCommonByKey(L"s_msg_tooltip_equip_quest_info");
        }
        if (strInfo.GetLength() != 0)
        {
            FUN_1407cbb20("itemQuestInfo", strInfo);
            int nState = reinterpret_cast<CQuestManager*>(FUN_140764020())->FUN_1416ce6a0(MS2Ptr<CItem>(pItem));
            if (nState == 0)
                FUN_1407cb9c0("questBeginAble", 1);
            else if (nState == 1)
                FUN_1407cb9c0("questProgress", 1);
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3A40, ASTooltip, FUN_1409d3a40, 1219, 0x3120A701); }

// @0x1409d3f10
void ASTooltip::FUN_1409d3f10(CItem* pItem)
{
    int nState = pItem->FUN_140528ca0();
    __int64 nUnlockTime = pItem->FUN_140528e00();
    if (nState == 0 && nUnlockTime > GetServerTime())
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, true);
        CStringW strText;
        CMsTime remain(pItem->FUN_140528e00() - GetServerTime());
        int nHours = (int)(remain.Get() / 3600);
        int nMinutes = (std::max)((int)(remain.Get() % 3600 / 60), 1);
        if (nHours > 0)
        {
            strText = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_itemlock_tooltip_msg_unlock");
            strText = StringFormat(strText, nHours, nMinutes);
        }
        else
        {
            strText = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_itemlock_tooltip_msg_unlock2");
            strText = StringFormat(strText, nMinutes);
        }
        FUN_1407cbb20("itemLockInfo", strText);
        return;
    }
    if (nState == 1)
    {
        FUN_1407cbbe0(s_strItemIconLock, true);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
        FUN_1407cbb20("itemLockInfo", reinterpret_cast<GFxManager*>(FUN_14025e7a0())->Localize("$s_itemlock_tooltip_msg_lock"));
    }
    else
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D3F10, ASTooltip, FUN_1409d3f10, 1072, 0x005C7805); }

// @0x1409d4490
void ASTooltip::FUN_1409d4490(CItem* pItem)
{
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xeb))
        return;
    if (pItem == 0)
        return;
    if (pItem->IsPetItem() == 0)
        return;
    unsigned nNeed = reinterpret_cast<CExpTable*>(FUN_1404a1bb0())->GetPetEvolution(pItem->FUN_1405282d0(), pItem->GetRarity());
    if (nNeed == 0)
        return;
    if (pItem->FUN_140528c20() < *GetClientConstants()->PetMaxLevel.Get())
        return;
    CStringW strText = StringFormat(s_wsPetEvolutionPoint);
    unsigned nPoint = pItem->FUN_140528bd0();
    CStringW strGauge = StringFormat(L"{0} / {1}", nPoint, nNeed);
    unsigned nPercent = (unsigned)(pItem->FUN_140528bd0() * 100) / nNeed;
    strText.Append(L"gauge:\n\n");
    FUN_1407cbb20("petEvolution", strText);
    FUN_1407cbb20("petEvolutionGauge", strGauge);
    FUN_1409c0d20("petEvolutionPercent", nPercent);
}
// not hooked: reads s_wsPetEvolutionPoint (a DLL-local copy, filled by FUN_1409e5480)

// @0x1409d46e0
void ASTooltip::FUN_1409d46e0(CItem* pItem)
{
    if (pItem == 0)
        return;
    if (pItem->FUN_1405278a0() == 0)
        return;
    Unk_ItemPlusInfo* pInfo = pItem->FUN_1405278a0()->FUN_140630d90();
    if (pInfo != 0 && pInfo->GetLevel() > 0)
        FUN_1407cb9c0("unlimited", pInfo->GetLevel());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D46E0, ASTooltip, FUN_1409d46e0, 121, 0x0809F9B2); }

// @0x1409d4760
bool ASTooltip::FUN_1409d4760(CItem* pItem)
{
    if (pItem->FUN_140527840()->FUN_14053d760())
    {
        if (pItem->FUN_140527840()->FUN_14053efd0() == 0)
            return true;
        __int64 nMin = pItem->FUN_1405278a0()->GetStatValue(0x1b, 3, 0);
        __int64 nMax = pItem->FUN_1405278a0()->GetStatValue(0x1c, 3, 0);
        ASObj obj(2);
        obj.FUN_1407cb9c0("type", 2);
        obj.FUN_1407cbb20("title", GetStatCommonText(0x1b));
        obj.FUN_1407cb9c0("extraup", 0);
        obj.FUN_1407cbb20("min", FUN_1409e0900((int)nMin));
        obj.FUN_1407cbb20("max", FUN_1409e0900((int)nMax));
        FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        return true;
    }
    if (pItem->FUN_140527840()->GetType() == 0xd)
    {
        if (pItem->FUN_140527840()->FUN_14053efd0() == 0)
            return true;
        std::pair<Unk_SocketSpecialStat, int> special = pItem->FUN_1405278a0()->GetOption()->GetFirstSpecialStat(0);
        if (special.first != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 2);
            obj.FUN_1407cbb20("title", FUN_140630e10(special.first));
            obj.FUN_1407cb9c0("extraup", 0);
            CStringW strValue;
            if (FUN_14081dcd0(special.first))
                strValue = FUN_1409e0a90((float)special.second / 1000.0f);
            else
                strValue = FUN_1409e0900(special.second);
            obj.FUN_1407cbb20("min", strValue);
            obj.FUN_1407cbb20("max", strValue);
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        }
        std::pair<Unk_StatType, int> stat = pItem->FUN_1405278a0()->GetOption()->GetFirstStat(0);
        if (stat.first != -1)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 2);
            obj.FUN_1407cbb20("title", GetStatCommonText(stat.first));
            obj.FUN_1407cb9c0("extraup", 0);
            CStringW strValue;
            if (IsStatKindTwo(stat.first))
                strValue = FUN_1409e0a90((float)stat.second / 1000.0f);
            else
                strValue = FUN_1409e0900(stat.second);
            obj.FUN_1407cbb20("min", strValue);
            obj.FUN_1407cbb20("max", strValue);
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        }
    }
    int nStat = pItem->FUN_140527840()->FUN_14053f7c0();
    if (nStat != -1)
    {
        if (pItem->FUN_140527840()->FUN_14053efd0() == 0)
            return true;
        __int64 nValue = pItem->FUN_1405278a0()->GetStatValue(nStat, 3, 0);
        if (nValue != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 2);
            obj.FUN_1407cbb20("title", GetStatCommonText(nStat));
            obj.FUN_1407cb9c0("extraup", 0);
            if (IsStatKindTwo(nStat))
            {
                obj.FUN_1407cbb20("min", FUN_1409e0a90((float)nValue / 1000.0f));
                obj.FUN_1407cbb20("max", FUN_1409e0a90((float)nValue / 1000.0f));
            }
            else
            {
                obj.FUN_1407cbb20("min", FUN_1409e0900((int)nValue));
                obj.FUN_1407cbb20("max", FUN_1409e0900((int)nValue));
            }
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
        }
        return true;
    }
    return false;
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D4760, ASTooltip, FUN_1409d4760, 2550, 0x405341EB); }

// @0x1409d5610
void ASTooltip::FUN_1409d5610(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    long nKinds = FUN_1409e6fc0(sp->GetIconCode());
    FUN_1409eb3b0(s_strItemKinds, nKinds);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5610, ASTooltip, FUN_1409d5610, 142, 0x346866BF); }

// @0x1409d56b0
void ASTooltip::SetItemMovie(int nItemId)
{
    if (m_48 & 0x40)
        return;
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cba60(s_strItemMovie, sp->property.movie);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D56B0, ASTooltip, SetItemMovie, 178, 0x8173E7A7); }

// @0x1409d5770
void ASTooltip::FUN_1409d5770(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbb20(s_strIconPath, FUN_14016a730(sp->GetIconPath(), 0));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5770, ASTooltip, FUN_1409d5770, 214, 0x8CD290D2); }

// @0x1409d5850
void ASTooltip::FUN_1409d5850(int nItemId)
{
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5850, ASTooltip, FUN_1409d5850, 10, 0x96F6F902); }

// @0x1409d5860
void ASTooltip::FUN_1409d5860(int nItemId, int nRarity)
{
    MS2Ptr<CItem> sp(new CItem);
    if (sp->FUN_140523c40(nItemId, nRarity, 0))
        FUN_1409cd9c0(sp.get());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5860, ASTooltip, FUN_1409d5860, 178, 0x98E59B9F); }

// @0x1409d5920
void ASTooltip::FUN_1409d5920(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    if (sp->GetType() != 0x19)
        return;
    int nBoxId = sp->function.FUN_14054a460();
    if (nBoxId == 0)
        return;
    PCBase* pPc = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    std::vector<ItemDropResult> results;
    ItemDropContext ctx;
    ctx.m_job = reinterpret_cast<PC*>(pPc)->FUN_141654700();
    ctx.m_gender = reinterpret_cast<PC*>(pPc)->FUN_141658e60();
    if (!TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nBoxId, ctx, results, true))
        return;
    FUN_1409e72a0(&results);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5920, ASTooltip, FUN_1409d5920, 363, 0x5540657B); }

// @0x1409d5aa0
void ASTooltip::SetItemDescription(int nItemId)
{
    CStringW str = TSingleton<CStringTable>::GetInstance()->GetItemDescription(nItemId, "tooltipDescription");
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(str);
    FUN_1407cbb20("itemDescription", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5AA0, ASTooltip, SetItemDescription, 189, 0xA32EDB32); }

// @0x1409d5b70
void ASTooltip::FUN_1409d5b70(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    CStringW strGuide = TSingleton<CStringTable>::GetInstance()->GetItemDescription(nItemId, "guideDescription");
    int nObjCode = spData->install.objCode;
    if (nObjCode != 0)
    {
        if (FUN_1407077c0(nObjCode) != 0)
            strGuide = FormatStringId<CStringW>(0xafa, strGuide);
        if (FUN_140707710(nObjCode) != 0)
            strGuide = FormatStringId<CStringW>(0xaf9, strGuide);
    }
    if (spData->FUN_14053cb80())
    {
        MS2Ptr<ItemHousing> spHousing = TSingleton<CItemDataTable>::GetInstance()->GetHousing(spData->GetItemId());
        if (spHousing == 0)
            return;
        unsigned short nLevel = spHousing->interiorLevel;
        unsigned nTrophyId = spHousing->trophyID;
        unsigned nTrophyLevel = spHousing->trophyLevel;
        int nPriceCount = spHousing->priceCount;
        if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xdb) && nLevel > 0 && nPriceCount == 1)
        {
            UGCCubeCategoryTable::InteriorPtr spInterior = TSingleton<UGCCubeCategoryTable>::GetInstance()->GetInterior(spHousing->categoryIndex);
            if (spInterior.get() != 0)
            {
                nLevel = nLevel > spInterior->m_nRequireLevel ? nLevel : spInterior->m_nRequireLevel;
            }
            if (nLevel > DAT_143ab291c)
            {
                if (!strGuide.IsEmpty())
                    strGuide.Append(L"\n");
                strGuide.Append(BlockFormat(0x6fa, nLevel));
            }
        }
        if (reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsGradeCleared(nTrophyId, nTrophyLevel) == 0)
        {
            CStringW strTrophy = FUN_14093bd40(nTrophyId, nTrophyLevel, CStringW(L""));
            if (!strTrophy.IsEmpty())
            {
                if (!strGuide.IsEmpty())
                    strGuide.Append(L"\n");
                strGuide.Append(FUN_14028dfa0(CStringW(L"s_construct_require_trophy"), strTrophy));
            }
        }
    }
    if (!m_50.IsEmpty())
    {
        if (!strGuide.IsEmpty())
            strGuide.Append(L"\n");
        strGuide.Append(m_50);
    }
    FUN_1407cbb20("itemGuideDescription", strGuide);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D5B70, ASTooltip, FUN_1409d5b70, 1438, 0x2F4EEABA); }

// @0x1409d6120
void ASTooltip::FUN_1409d6120(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    {
        CStringW strMain = TSingleton<CStringTable>::GetInstance()->GetItemDescription(nItemId, "mainDescription");
        if (strMain.GetLength() != 0)
        {
            ASObj obj(2);
            obj.FUN_1407cb9c0("type", 0);
            obj.FUN_1407cbb20("text", strMain);
            FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
            return;
        }
    }
    CStringW strText;
    if (spData->IsFunctionName(L"ChatEmoticonAdd"))
        strText = FUN_1409daff0(spData);
    if (strText.GetLength() != 0)
    {
        ASObj obj(2);
        obj.FUN_1407cb9c0("type", 0);
        obj.FUN_1407cbb20("text", strText);
        FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D6120, ASTooltip, FUN_1409d6120, 876, 0x748328C9); }

// @0x1409d64a0
void ASTooltip::FUN_1409d64a0(int nItemId, int nRank, int nLevel, int nAdditional)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    ASArray arr(2);
    FUN_1409deea0(&arr, nItemId, nRank, nLevel, nAdditional);
    FUN_1409df180(&arr, nItemId);
    if (spData->FUN_14053cb80())
    {
        FUN_1409de140(&arr, nItemId, nRank);
        FUN_1409de630(&arr, nItemId);
        FUN_1409dea00(&arr, nItemId);
    }
    else if (spData->FUN_14053d840())
    {
        FUN_1409de140(&arr, nItemId, nRank);
        FUN_1409df760(&arr, spData);
    }
    else
    {
        FUN_1409de140(&arr, nItemId, nRank);
    }
    FUN_1409deb80(&arr, nItemId);
    FUN_1409df400(&arr, nItemId);
    FUN_1409df5b0(&arr, nItemId);
    FUN_1409adbe0("extraDescription", arr.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D64A0, ASTooltip, FUN_1409d64a0, 650, 0x9A297696); }

// @0x1409d6730
void ASTooltip::FUN_1409d6730(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    if (spData->FUN_14053dd30() <= 0)
        return;
    TPtrValue<MaidDesc> spDesc = CMaidDescTable::GetInstance()->Find(spData->FUN_14053dd30());
    if (!spDesc)
        return;
    TPtrValue<MaidInfo> spInfo = CMaidInfoTable::GetInstance()->Find(spData->FUN_14053dd30());
    if (!spInfo)
        return;
    CStringW strIcon(spInfo->FUN_1409eee80() != 0 ? L"export_common_icon_meso" : L"export_common_icon_merat");
    CStringW strText = BlockFormat(0x7a2, spDesc->specialty, FUN_140763e10(spInfo->salary), strIcon);
    ASObj row(2);
    row.FUN_1407cb9c0("type", 0);
    row.FUN_1407cbb20("text", strText);
    FUN_1409adbe0("statDescription", row.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D6730, ASTooltip, FUN_1409d6730, 763, 0x6733EB1B); }

// @0x1409d6a40
void ASTooltip::FUN_1409d6a40(int nItemId, __int64 nMinutes)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    if (spData->period.usePeriod > 0 || spData->IsPCBangItem() || nMinutes > 0)
    {
        CStringW strPeriod(L"");
        CStringW strDays(L"");
        CStringW strHours(L"");
        CStringW strMinutes(L"");
        __int64 nSeconds = 0;
        if (spData->period.usePeriod > 0)
            nSeconds = spData->period.usePeriod * 60;
        else if (spData->IsPCBangItem())
            nSeconds = *GetClientConstants()->PCBangItemDefaultPeriod.Get() * 60;
        if (nMinutes > 0)
            nSeconds = nMinutes * 60;
        ATL::CTimeSpan span(nSeconds);
        if (span.GetDays() > 0)
            strDays = FormatStringId<__int64>(0xc5, span.GetDays());
        if (span.GetHours() > 0)
        {
            strHours = FormatStringId<long>(0xc6, span.GetHours());
            if (span.GetDays() > 0)
                strHours = StringFormat(L" {0}", strHours);
        }
        if (span.GetMinutes() > 0)
        {
            strMinutes = FormatStringId<long>(199, span.GetMinutes());
            if (span.GetDays() > 0 || span.GetHours() > 0)
                strMinutes = StringFormat(L" {0}", strMinutes);
        }
        strPeriod = StringFormat(L"{0}{1}{2}", strDays, strHours, strMinutes);
        if (spData->IsPCBangItem())
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xc0, strPeriod));
        else if (spData->HasMaidId())
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xc1, strPeriod));
        else
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xbe, strPeriod));
    }
    else
    {
        CMsTime tNull(0);
        if (spData->period.expiration > tNull)
        {
            int nYear = spData->period.expiration.GetYear();
            int nMonth = spData->period.expiration.GetMonth();
            int nDay = spData->period.expiration.GetDay();
            int nHour = spData->period.expiration.GetHour();
            int nMinute = spData->period.expiration.GetMinute();
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xbf, BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute)));
        }
        else if (spData->period.expirationType == 1)
        {
            unsigned nCount = spData->period.numberOfWeeksMonths;
            if (nCount == 0)
                nCount = 1;
            FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_weekly"), nCount));
        }
        else if (spData->period.expirationType == 2)
        {
            unsigned nCount = spData->period.numberOfWeeksMonths;
            if (nCount == 0)
                nCount = 1;
            FUN_1407cbb20("itemUsePeriod", FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expirationtype_monthly"), nCount));
        }
        else if (!spData->period.termTag.IsEmpty())
        {
            CMsTime end = TermTagManagerCli::GetInstance()->GetEndTime(spData->period.termTag);
            int nYear = end.GetYear();
            int nMonth = end.GetMonth();
            int nDay = end.GetDay();
            int nHour = end.GetHour();
            int nMinute = end.GetMinute();
            FUN_1407cbb20("itemUsePeriod", FormatStringId<CStringW>(0xbf, BlockFormat(0xb8, nYear, nMonth, nDay, nHour, nMinute)));
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D6A40, ASTooltip, FUN_1409d6a40, 2638, 0xD20CA894); }

// @0x1409d7560
void ASTooltip::FUN_1409d7560(int nItemId, int nRank)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    if (!sp->IsPetItem())
        return;
    FUN_1409adc90(s_strItemPetRank, nRank);
    FUN_1407cb9c0(s_strDropShadowDisable, 1);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D7560, ASTooltip, FUN_1409d7560, 187, 0xFBC6422C); }

// @0x1409d7630
void ASTooltip::FUN_1409d7630(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp == 0)
        return;
    CStringW str;
    if (sp->IsFunctionName(L"ChatEmoticonAdd"))
        str = FUN_1409daa30(sp);
    if (!str.IsEmpty())
        FUN_1407cbb20("extraComment", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D7630, ASTooltip, FUN_1409d7630, 365, 0xCCE37309); }

// @0x1409d77b0
void ASTooltip::FUN_1409d77b0(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp == 0)
        return;
    int nSeason = sp->GetOpenGachaBoxParam0();
    ItemGachaBoxTable* pTable = TSingleton<ItemGachaBoxTable>::GetInstance();
    if (pTable == 0)
        return;
    if (pTable->IsCoinItem(nItemId) == true)
        nSeason = pTable->GetRandomBoxIdByCoinItem(nItemId);
    if (nSeason == 0)
        return;
    if (!pTable->IsSeasonNumberOnIcon(nSeason))
        return;
    CStringW str = FUN_1409e5320(nSeason);
    FUN_1407cbb20("itemSeason", str);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D77B0, ASTooltip, FUN_1409d77b0, 330, 0xAD681CF7); }

// @0x1409d7900
void ASTooltip::FUN_1409d7900(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    PCBase* pPc = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc == 0)
        return;
    ItemFunction& func = spData->function;
    if (func.name == L"ItemChangeBeauty")
    {
        unsigned nCount = ((ItemFunctionArgs&)(func.parameter)).FUN_1408d2380();
        if (nCount == 0)
            return;
        if (nCount > 0)
        {
            int nShopId = ((ItemFunctionArgs&)(func.parameter)).FUN_1408d1fd0(0, 0);
            if (nShopId == 0)
                return;
            Unk_SocketPtr<Unk_TooltipBeautyItems> spItems = FUN_1406e5af0(nShopId);
            if (spItems == 0 || spItems.operator->()->IsEmpty() == true)
                return;
            std::vector<ItemDropResult> drops;
            size_t nItems = spItems->GetCount();
            drops.reserve(nItems);
            int nGender = reinterpret_cast<PC*>(pPc)->FUN_141658e60();
            bool bGenderOnly = static_cast<Unk_ItemDataIntView*>(spData.operator->())->IsGenderAllowed(nGender) == 1;
            for (size_t i = 0; i < nItems; i++)
            {
                MS2Ptr<CItemData> spItem(spItems->operator[](i));
                if (spItem == 0)
                    continue;
                if (bGenderOnly && static_cast<Unk_ItemDataIntView*>(spItem.operator->())->IsGenderAllowed(nGender) == 0)
                    continue;
                int nId = spItem->GetItemId();
                int nRank = FUN_14053feb0(nId);
                ItemDropResult drop(nId, 0, nRank, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                drops.push_back(drop);
            }
            if (drops.empty() == true)
                return;
            FUN_1409e72a0(&drops);
        }
    }
    else if (func.name == L"OpenCoupleEffectBox")
    {
        unsigned nCount = ((ItemFunctionArgs&)(func.parameter)).FUN_1408d2380();
        if (nCount < 2)
            return;
        int nId = ((ItemFunctionArgs&)(func.parameter)).FUN_1408d1fd0(0, 0);
        if (nId == 0)
            return;
        MS2Ptr<CItemData> spItem = FUN_14053f870(nId);
        if (spItem == 0)
            return;
        int nRank = ((ItemFunctionArgs&)(func.parameter)).FUN_1408d1fd0(1, 0);
        if (nRank == 0)
            return;
        std::vector<ItemDropResult> drops;
        drops.push_back(ItemDropResult(nId, 0, nRank, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
        FUN_1409e72a0(&drops);
    }
    else if (func.name == L"ItemRemakeScroll")
    {
        unsigned nCount = ((ItemFunctionArgs&)(func.parameter)).FUN_1408d2380();
        if (nCount == 0)
            return;
        unsigned nScrollId = ((ItemFunctionArgs&)(func.parameter)).FUN_1408d1f60(0, 0);
        CItemRemakeScrollDataPtr spInfo = CItemRemakeScrollTable::GetInstance()->GetData(nScrollId);
        if (spInfo == 0 || spInfo->m_arrItemTypes.IsEmpty() == true)
            return;
        std::vector<ItemDropResult> drops;
        const ATL::CAtlArray<unsigned>& ids = spInfo->m_arrItemTypes;
        const ATL::CAtlArray<unsigned>& ranks = spInfo->m_arrRanks;
        int nRank = ranks.IsEmpty() ? 1 : ranks[0];
        int nJob = reinterpret_cast<PC*>(pPc)->FUN_141654700();
        for (size_t i = 0; i < ids.GetCount(); i++)
        {
            unsigned nId = ids[i];
            MS2Ptr<CItemData> spItem = FUN_14053f870(nId);
            if (spItem == 0)
                continue;
            if (!spItem->limit.IsJobAllowed(nJob))
                continue;
            if (!spItem->limit.IsJobRecommended(nJob))
                continue;
            drops.push_back(ItemDropResult(nId, 0, nRank, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
        }
        FUN_1409e72a0(&drops);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D7900, ASTooltip, FUN_1409d7900, 2552, 0x6AF15DEB); }

// @0x1409d8300
void ASTooltip::FUN_1409d8300(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    if (spData->function.name != L"SuperWorldChat")
        return;
    unsigned long nColor1 = s_color6;
    unsigned long nColor2 = s_color18;
    unsigned long nSize = 1;
    CStringW strIcon(DAT_143aef3b8);
    FUN_14183eba0(nItemId, strIcon, nSize, nColor1, nColor2);
    CStringW strPreview = FUN_14028dfa0(CStringW(L"s_html_chat_super_preview"), strIcon, nColor1, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
    ASObj obj(2);
    obj.FUN_1407cbb20("text", strPreview);
    obj.FUN_1409c4990("colorIdx", nSize);
    FUN_1409adbe0("previewSuperWorldChat", obj.FUN_1422bb870());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8300, ASTooltip, FUN_1409d8300, 606, 0xC0DF2680); }

// @0x1409d8570
void ASTooltip::FUN_1409d8570(CItem* pItem)
{
    if (reinterpret_cast<CItemBreakManager*>(FUN_1409c4b20())->CanBreakItem(MS2Ptr<CItem>(pItem)) == 0)
        return;
    int nItemId = pItem->FUN_1405276c0();
    if (pItem->FUN_140529640() != 0)
        nItemId = pItem->FUN_140529640();
    int nSockets = 0;
    if (pItem->GetSocket() != 0)
        nSockets = pItem->GetSocket()->GetOpenSlotCount();
    FUN_1409d8650(nItemId, pItem->GetRarity(), nSockets);
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8570, ASTooltip, FUN_1409d8570, 212, 0xF9182D6C); }

// @0x1409d8650
void ASTooltip::FUN_1409d8650(int nItemId, int nGrade, int nSockets)
{
    bool bGacha = false;
    if (TSingleton<ItemGachaBoxTable>::GetInstance() != 0)
        bGacha = TSingleton<ItemGachaBoxTable>::GetInstance()->GetBox(nItemId) == 0 ? false : true;
    MS2SvrPtr<CIngredientContainer> spIngredients(0);
    if (bGacha)
        spIngredients = reinterpret_cast<CItemBreakIngredientTable*>(FUN_140535300())->GetGachaBox(nItemId);
    else
        spIngredients = reinterpret_cast<CItemBreakIngredientTable*>(FUN_140535300())->GetIngredients(nItemId, nGrade, nSockets);
    if (spIngredients == 0)
        return;
    FUN_1409e7460(spIngredients->FUN_14026c230());
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8650, ASTooltip, FUN_1409d8650, 420, 0x50CA6567); }

// @0x1409d8800
void ASTooltip::FUN_1409d8800(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return;
    if (!FUN_1406a6030(spData))
        return;
    if (spData->IsMeratMarketRegisterable() == 0)
        FUN_1407cbb20("ugcItemLimitRegister", GetStringCommon(0x9b9));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8800, ASTooltip, FUN_1409d8800, 206, 0xE07649E6); }

// @0x1409d88e0
void ASTooltip::FUN_1409d88e0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || spItem->FUN_140527840() == 0 || FUN_1409c6540() == 0)
        return;
    if (!FUN_1406a6030(MS2Ptr<CItemData>(spItem->FUN_140527840())))
        return;
    Unk_BillOwner owner;

    owner.m_nAccount = DAT_143ab2820;
    owner.m_nType = DAT_143ab2830;
    owner.m_pCharacter = (void*)DAT_143ab2838;
    owner.m_n18 = DAT_143ab2834;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    bool bRegistrable = false;
    if (spItem->HasCubeTextureMesh() != 0 || spItem->FUN_140526010() != 0)
    {
        if (spItem->FUN_140525f60())
            bRegistrable = FUN_1406a5a50(spItem, reinterpret_cast<const Unk_MeratItemOwner*>(&owner));
        else
            bRegistrable = spData->IsMeratMarketRegisterable() == 1;
    }
    else if (spItem->FUN_140525680())
    {
        if (spItem->FUN_140525790())
            bRegistrable = FUN_1406a5a50(spItem, reinterpret_cast<const Unk_MeratItemOwner*>(&owner));
        else
            bRegistrable = spData->IsMeratMarketRegisterable() == 1;
    }
    if (!bRegistrable)
        FUN_1407cbb20("ugcItemLimitRegister", GetStringCommon(0x9b9));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D88E0, ASTooltip, FUN_1409d88e0, 775, 0xA2C0CBD9); }

// @0x1409d8bf0
void ASTooltip::SetItemEquipText(bool bEnable)
{
    if (bEnable)
        FUN_1407cbb20(s_strItemEquip, GetStringCommon(0x58a));
    else
        FUN_1409c0e60(s_strItemEquip, L"");
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8BF0, ASTooltip, SetItemEquipText, 123, 0xFF195793); }

// @0x1409d8d90
void ASTooltip::FUN_1409d8d90(CItem* pItem, CStringW& strOut)
{
    if (pItem == 0)
        return;
    MS2Ptr<CItemEnchantInfo> spEnchant(pItem->FUN_1405278a0()->GetEnchant());
    if (!spEnchant)
        return;
    if (!pItem->FUN_140527840()->FUN_14053cbc0())
        return;
    if (pItem->HasSkin() != 0)
        return;
    int bNoEnchant = pItem->FUN_140525c60() != 0 || static_cast<Unk_ItemDataIntView*>(static_cast<CItemData*>(pItem->FUN_140527840()))->HasPeriod() != 0 || pItem->FUN_140525ca0() != 0;
    if (pItem->FUN_140527840()->limit.exceptEnchant || bNoEnchant != 0)
    {
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        strOut.Append(GetStringCommon(0x94e));
        return;
    }
    bool bEnchantable = true;
    if (CItemEnchantLimitTable::GetInstance()->FUN_14058df90(pItem) == 0)
        bEnchantable = false;
    if (bEnchantable)
    {
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        if (spEnchant->FUN_14058c8a0() == 0)
        {
            strOut.Append(GetStringCommon(0x959));
            if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xa6))
            {
                unsigned nLevel = CItemEnchantTransformTable::GetInstance()->GetLowestLimitLevel(pItem->FUN_1405276c0());
                if (nLevel != 0)
                {
                    strOut.Append(L"\n");
                    strOut.Append(FUN_14028dfa0(CStringW(L"s_itemenchant_transform_valid_item"), nLevel));
                }
            }
        }
        else
        {
            strOut.Append(GetStringCommon(0x95a));
        }
        if (spEnchant->FUN_14058ccf0() > 0)
        {
            if (!strOut.IsEmpty())
                strOut.Append(L"\n");
            strOut.Append(FUN_14028dfa0(CStringW(L"s_itemenchant_fail_stack_count"), spEnchant->FUN_14058ccf0()));
        }
    }
    else
    {
        if (spEnchant->FUN_14058c8a0() == 0)
        {
            if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xa6))
            {
                unsigned nLevel = CItemEnchantTransformTable::GetInstance()->GetLowestLimitLevel(pItem->FUN_1405276c0());
                if (nLevel != 0)
                {
                    strOut.Append(L"\n");
                    strOut.Append(FUN_14028dfa0(CStringW(L"s_itemenchant_transform_valid_item"), nLevel));
                }
            }
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D8D90, ASTooltip, FUN_1409d8d90, 1423, 0x01772AAA); }

// @0x1409d9330
void ASTooltip::FUN_1409d9330(CItem* pItem, CStringW& strOut)
{
    if (pItem == 0)
        return;
    if (pItem->FUN_140526470(2) == 1)
    {
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        if ((m_48 & 0x400) != 0 || (m_48 & 0x1000) != 0)
        {
            CStringW str;
            if (pItem->IsPetItem() != 0)
                str = GetStringCommonByKey(L"s_tooltip_petremake_enable");
            else
                str = GetStringCommon(0xbfa);
            strOut.Append(str);
        }
        else
        {
            CStringW str;
            if (pItem->IsPetItem() != 0)
            {
                int nCount = pItem->FUN_140527300();
                str = FUN_14028dfa0(L"s_tooltip_petremake_count", nCount);
            }
            else
            {
                int nCount = pItem->FUN_140527300();
                str = BlockFormat<int>(0xbf9, nCount);
            }
            strOut.Append(str);
        }
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D9330, ASTooltip, FUN_1409d9330, 683, 0x416C252A); }

// @0x1409d95f0
void ASTooltip::FUN_1409d95f0(CItem* pItem, CStringW& strOut)
{
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x38))
        return;
    if (pItem == 0)
        return;
    if (pItem->FUN_140527840() == 0)
        return;
    if (!pItem->FUN_140527840()->FUN_14053d800())
        return;
    if (pItem->FUN_140527030() != 0)
        return;
    if (FUN_140634230(MS2Ptr<CItem>(pItem)))
        return;
    CItemEnchantInfo* pEnchant = pItem->FUN_1405278a0()->GetEnchant();
    if (pEnchant != 0 && !pEnchant->FUN_14058c9a0())
        return;
    int nRemain = pItem->GetRepackLimitCount();
    if (nRemain <= 0)
        return;
    if (!strOut.IsEmpty())
        strOut.Append(L"\n");
    if (pItem->GetRemainingRePackingCount() == 0)
    {
        CStringW str = GetStringCommonByKey(L"s_item_repacking_disable");
        strOut.Append(str);
    }
    else
    {
        CStringW strKey(L"s_item_repacking_limit_count");
        if (pItem->IsPetItem() != 0)
        {
            if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x101))
                return;
            strKey = L"s_item_repacking_pet_limit_count";
        }
        int nUsed = pItem->GetRepackConsumeCount();
        int nMax = pItem->GetRemainingRePackingCount();
        CStringW str = FUN_14028dfa0(strKey, nMax, nUsed);
        strOut.Append(str);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D95F0, ASTooltip, FUN_1409d95f0, 679, 0x1836DFFB); }

// @0x1409d98a0
void ASTooltip::FUN_1409d98a0(CItem* pItem, CStringW& strText)
{
    if (pItem == 0)
        return;
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x3a))
        return;
    if (pItem->HasSkin() == 0)
        return;
    if (reinterpret_cast<CItemBreakManager*>(FUN_1409c4b20())->CanBreakItem(MS2Ptr<CItem>(pItem)) == 0)
    {
        if (!strText.IsEmpty())
            strText.Append(L"\n");
        CStringW str = GetStringCommon(0xc44);
        strText.Append(str);
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D98A0, ASTooltip, FUN_1409d98a0, 247, 0x20F31EEC); }

// @0x1409d99a0
void ASTooltip::FUN_1409d99a0(CItem* pItem, CStringW& strText)
{
    if (pItem == 0)
        return;
    if (!reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x6f))
        return;
    if (pItem->FUN_140527840() == 0)
        return;
    if (pItem->FUN_140527840()->fusion.fusionable == 0)
        return;
    if (!strText.IsEmpty())
        strText.Append(L"\n");
    strText.Append(GetStringCommonByKey(L"s_item_merge_valid_item"));
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D99A0, ASTooltip, FUN_1409d99a0, 242, 0xE8D921E7); }

// @0x1409d9aa0
void ASTooltip::FUN_1409d9aa0(CItem* pItem, CStringW& strText)
{
    if (pItem == 0)
        return;
    CExtractionItemInfoPtr spRow = reinterpret_cast<CItemExtractionTable*>(FUN_14052d1f0())->GetData(pItem->FUN_1405276c0());
    if (spRow.get() != 0)
    {
        unsigned nTry = pItem->FUN_1405292a0();
        if (!strText.IsEmpty())
            strText.Append(L"\n");
        if (nTry > 0)
            strText.Append(FUN_14028dfa0(L"s_itemextraction_trycount", nTry, spRow->m_nScrollCount));
        else
            strText.Append(GetStringCommonByKey(L"s_itemextraction_invalid"));
    }
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D9AA0, ASTooltip, FUN_1409d9aa0, 424, 0x4D23CBFE); }

// @0x1409d9c50
CStringW ASTooltip::FUN_1409d9c50(CItem* pItem)
{
    CStringW str;
    if (pItem == 0)
        return str;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData.IsNull())
        return str;
    if (!spData->FUN_14053cd10())
        return str;
    if (pItem->FUN_140525680() && pItem->FUN_140527990() != 0 && pItem->FUN_140527990()->FUN_140632780())
        return FUN_1409d9f30(spData);
    int nCount = pItem->FUN_140527340();
    if (nCount > 0)
        str = BlockFormat<int>(0x9bb, nCount);
    else
        str = BlockFormat<int>(0x9bc, nCount);
    return str;
}
namespace p3hook { MS2_REPLACE_METHOD(0x1409D9C50, ASTooltip, FUN_1409d9c50, 723, 0x63A8522D); }

// The hook registrations are named by __LINE__: each one sits in namespace p4hook so that it cannot collide with a
// registration on the same line of astooltip.cpp or of another part (same translation unit).

// The play count text of a music score item.
// @0x1409d9f30
CStringW ASTooltip::FUN_1409d9f30(MS2Ptr<CItemData> spData)
{
    CStringW str;
    if (!spData)
        return str;
    if (!spData->FUN_14053cd10())
        return str;
    MS2Ptr<ItemMusicScore> spScore = CItemDataTable::GetInstance()->GetMusicScore(spData->GetItemId());
    if (spScore == 0)
        return str;
    int nCount = spScore->FUN_14054ad00();
    if (spScore->FUN_14054aca0())
        str = BlockFormat(0x9bd, nCount);
    else
        str = BlockFormat(0x9bb, nCount);
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409D9F30, ASTooltip, FUN_1409d9f30, 641, 0x5D355221); }

// The period text of a music score item.
// @0x1409da1c0
CStringW ASTooltip::FUN_1409da1c0(CItem* pItem)
{
    CStringW str;
    if (pItem == 0)
        return str;
    if (pItem->FUN_140525730())
        str = FUN_1409da3d0(MS2Ptr<CItemData>(pItem->FUN_140527840()));
    if (str.IsEmpty())
    {
        unsigned nSeconds = MsToSeconds(pItem->FUN_1405299a0());
        CStringW strPeriod = FUN_141b708a0(nSeconds, true);
        str = BlockFormat(0x9c1, pItem->FUN_140529aa0(), strPeriod);
    }
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DA1C0, ASTooltip, FUN_1409da1c0, 513, 0x386E96EF); }

// @0x1409da3d0
CStringW ASTooltip::FUN_1409da3d0(MS2Ptr<CItemData> spData)
{
    CStringW str;
    if (!spData)
        return str;
    MS2Ptr<ItemMusicScore> spScore = CItemDataTable::GetInstance()->GetMusicScore(spData->GetItemId());
    if (spScore == 0)
        return str;
    if (spScore->FUN_14054aca0())
    {
        int nLength = spScore->FUN_14054acc0();
        str = BlockFormat(0x9c0, nLength);
    }
    else
    {
        unsigned nSeconds = MsToSeconds(spScore->FUN_14054ace0());
        CStringW strPeriod = FUN_141b708a0(nSeconds, true);
        str = BlockFormat(0x9c1, spScore->FUN_14054ad20(), strPeriod);
    }
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DA3D0, ASTooltip, FUN_1409da3d0, 689, 0x1A4506A2); }

// The mastery recipes that use the item as an ingredient (with the owned / needed count).
// @0x1409da690
CStringW ASTooltip::FUN_1409da690(CItem* pItem)
{
    CMasteryTable::IngredientListPtr spList = CMasteryTable::GetInstance()->IngredientReceipes(pItem->FUN_1405276c0());
    if (spList.get() != 0)
    {
        CStringW str;
        for (size_t i = 0; i < spList->GetCount(); i++)
        {
            std::pair<int, int>* pEntry = &(*spList.operator->())[i];
            CMasteryTable::ReceipePtr spReceipe = CMasteryTable::GetInstance()->Find(pEntry->first);
            if (!spReceipe)
                continue;
            int nHave = g_143ab2a90.FUN_140a5f180(pItem->FUN_1405276c0(), 0);
            int nNeed = pEntry->second;
            CStringW strKey(L"s_msg_tooltip_mastery_recipe_count");
            if (nHave < nNeed)
                strKey += L"_lack";
            CStringW strType = CMasteryTable::GetInstance()->TypeName(spReceipe->m_nType);
            CStringW strName = ((CStringTable*)(Unk_CommandStrings*)(CStringTable::GetInstance()))->FUN_141811980(0x2f, spReceipe->m_nId);
            CStringW strCount = FUN_14028dfa0(strKey, nHave, nNeed);
            if (str.GetLength() != 0)
                str += L"\n";
            str += FUN_14028dfa0(CStringW(L"s_msg_tooltip_mastery_recipe_info"), strType, strName, strCount);
        }
        return str;
    }
    return L"";
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DA690, ASTooltip, FUN_1409da690, 922, 0x597922AA); }

// @0x1409daa30
CStringW ASTooltip::FUN_1409daa30(MS2Ptr<CItemData> spData)
{
    if (!spData)
        return L"";
    if (!spData->IsFunctionName(L"ChatEmoticonAdd"))
        return L"";
    CXmlData& xml = spData->function.xml;
    std::vector<unsigned> ids;
    {
        CStringW strIds = xml.FUN_14042cad0(L"id", L"");
        FUN_1402929a0(strIds, reinterpret_cast<std::vector<int>&>(ids), L",");
    }
    std::list<MS2Ptr<ChatEmoticonData> > emoticons;
    std::vector<unsigned>& rIds = ids;
    std::vector<unsigned>::const_iterator itIdEnd = rIds.end();
    for (std::vector<unsigned>::const_iterator itId = rIds.begin(); itId != itIdEnd; ++itId)
    {
        unsigned nGroupId = *itId;
        std::list<MS2Ptr<ChatEmoticonData> > group;
        CChatEmoticonTable::GetInstance()->FUN_1401e73c0(nGroupId, &group);
        emoticons.insert(emoticons.end(), group.begin(), group.end());
    }
    const int nPerRow = 4;
    CStringW strGap = GetStringCommonByKey(L"s_tooltip_chat_emoticon_extra_comment_image_gap");
    int nCount = 0;
    CStringW str;
    std::list<MS2Ptr<ChatEmoticonData> >& rEmoticons = emoticons;
    std::list<MS2Ptr<ChatEmoticonData> >::const_iterator itEnd = rEmoticons.end();
    for (std::list<MS2Ptr<ChatEmoticonData> >::const_iterator it = rEmoticons.begin(); it != itEnd; ++it)
    {
        MS2Ptr<ChatEmoticonData> spEmoticon = *it;
        if (!spEmoticon)
            continue;
        CStringW strIcon = StringFormat(L"img://icon:{0}", spEmoticon->m_strImagePath);
        str += FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_extra_comment_image_tag"), strIcon);
        nCount++;
        if (nCount % nPerRow != 0)
            str += strGap;
        else
            str += L"\n";
    }
    FUN_1409c0dc0("extraCommentAlign", "center");
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DAA30, ASTooltip, FUN_1409daa30, 1466, 0xEE156D83); }

// @0x1409daff0
CStringW ASTooltip::FUN_1409daff0(MS2Ptr<CItemData> spData)
{
    if (!spData)
        return L"";
    CXmlData& xml = spData->function.xml;
    int nCount = 0;
    std::vector<int> ids = xml.GetIntArray(L"id", std::vector<int>());
    MS2_FOR_EACH(int nGroupId, ids)
    {
        std::list<MS2Ptr<ChatEmoticonData> > group;
        CChatEmoticonTable::GetInstance()->FUN_1401e73c0(nGroupId, &group);
        nCount += static_cast<int>(group.size());
    }
    CStringW str = FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_description"), nCount) + L"\n";
    if (xml.FUN_14092c5f0(L"endDate"))
    {
        CString strEndDate = xml.GetString(L"endDate", "");
        CMsTime time;
        CString strFormat("%04d-%02d-%02d-%02d-%02d-%02d");
        if (FUN_14028e280(time, strFormat, strEndDate) == 0)
            return L"";
        str += FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_description_enddate"), time.GetYear(), time.GetMonth(),
            time.GetDay(), time.GetHour(), time.GetMinute());
    }
    else if (xml.FUN_14092c5f0(L"durationSec"))
    {
        __int64 nSeconds = xml.GetInt64(L"durationSec", 0);
        CTimeSpan span(nSeconds);
        CStringW strDuration = FormatTimeSpan(span, true, true, true, true);
        str += FUN_14028dfa0(CStringW(L"s_tooltip_chat_emoticon_description_duration"), strDuration);
    }
    return str;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DAFF0, ASTooltip, FUN_1409daff0, 1710, 0x5BC1D730); }

// @0x1409db6b0
MS2Ptr<AScript> ASTooltip::GetRhsTooltip()
{
    Scaleform::GFx::Value v = GetMember("rhsTooltip");
    return FUN_1409e7dc0(m_nMovieId, v);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB6B0, ASTooltip, GetRhsTooltip, 108, 0xEB7EE570); }

// @0x1409db730
MS2Ptr<AScript> ASTooltip::GetLhsTooltip()
{
    Scaleform::GFx::Value v = GetMember("lhsTooltip");
    return FUN_1409e7dc0(m_nMovieId, v);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB730, ASTooltip, GetLhsTooltip, 108, 0x9E63F646); }

// @0x1409db7b0
void ASTooltip::FUN_1409db7b0(MS2Ptr<CItem> spItem)
{
    if (!FUN_141b48950(spItem))
        return;
    CStringW str = FUN_1409e7880();
    FUN_1407cbb20("enablePreview", str);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB7B0, ASTooltip, FUN_1409db7b0, 186, 0x7FFD03BD); }

// @0x1409db870
void ASTooltip::FUN_1409db870(MS2Ptr<CItemData> spData)
{
    if (!FUN_141b488c0(spData))
        return;
    CStringW str = FUN_1409e7880();
    FUN_1407cbb20("enablePreview", str);
}
// not hooked: overloaded with the stale Unk_GalleryPtr declaration (uigalleryeventdialog.cpp)

// The item tooltip with an optional comparison item: each one goes to its side tooltip when the movie has one.
// @0x1409db930
void ASTooltip::FUN_1409db930(MS2Ptr<CItem> spCompare, MS2Ptr<CItem> spItem)
{
    if (spCompare.get() != 0)
    {
        MS2Ptr<AScript> spLhs = GetLhsTooltip();
        if ((spLhs.get() ? true : false) && !spLhs->IsUndefinedOrNull())
        {
            ASTooltip tip(spLhs->FUN_1422bb870(), 2);
            tip.FUN_1409db7b0(spCompare);
        }
        else
            FUN_1409db7b0(spCompare);
    }
    if (spItem.get() != 0)
    {
        MS2Ptr<AScript> spRhs = GetRhsTooltip();
        if ((spRhs.get() ? true : false) && !spRhs->IsUndefinedOrNull())
        {
            ASTooltip tip(spRhs->FUN_1422bb870(), 2);
            tip.FUN_1409db7b0(spItem);
        }
        else
            FUN_1409db7b0(spItem);
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DB930, ASTooltip, FUN_1409db930, 640, 0x795DD30D); }

// @0x1409dbbc0
void ASTooltip::FUN_1409dbbc0(CStringW str)
{
    FUN_1407cbb20(s_strItemName, str);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBBC0, ASTooltip, FUN_1409dbbc0, 102, 0x4BAE7722); }

// @0x1409dbc60
void ASTooltip::FUN_1409dbc60(int nSkillId, const CStringW& strSuffix)
{
    CStringW str = ((CStringTable*)(Unk_CommandStrings*)(CStringTable::GetInstance()))->FUN_141811980(4, nSkillId) + strSuffix;
    FUN_1407cbb20(s_strSkillName, str);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBC60, ASTooltip, FUN_1409dbc60, 185, 0xA2BE6DF6); }

// @0x1409dbd30
void ASTooltip::FUN_1409dbd30(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    unsigned nElement = spSkill->GetElement();
    int ids[8] = {0, 0x5c4, 0x5c5, 0x5c6, 0x5c7, 0x5c8, 0x5c9, 0};
    if ((int)nElement >= 8)
        return;
    ASObj obj(2);
    obj.FUN_1409c0d20("type", nElement);
    obj.FUN_1407cbb20("text", GetStringCommon(ids[nElement]));
    FUN_1409adbe0("skillElement", obj.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBD30, ASTooltip, FUN_1409dbd30, 442, 0x5850A4D6); }

// @0x1409dbef0
void ASTooltip::SetSkillIconPath(int nSkillId)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    FUN_1407cba60(s_strIconPath, spSkill->m_strIcon);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBEF0, ASTooltip, SetSkillIconPath, 165, 0x9B19764E); }

// The quick slot hint of an active skill the player has learnt.
// @0x1409dbfa0
void ASTooltip::FUN_1409dbfa0(int nSkillId)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    if (spSkill->FUN_1407e9de0())
        return;
    JobSystem* pJob = reinterpret_cast<JobSystem*>(reinterpret_cast<PC*>(FUN_1409c6540())->FUN_1416546d0());
    if (pJob->vfunc_2(nSkillId))
    {
        int nSlot = CKeyTable::GetInstance()->FindQuickSlotBySkillAndItemUid(nSkillId, 0);
        if (nSlot != -1)
            FUN_1407cbb20(s_strItemEquip, GetStringCommon(0x58a));
        else
            SetEnablePuton(GetStringCommon(0x75a));
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DBFA0, ASTooltip, FUN_1409dbfa0, 386, 0xE6EADCDD); }

// @0x1409dc130
void ASTooltip::SetSkillDescription(int nSkillId, unsigned short nLevel)
{
    FUN_1407cbb20("skillDescription", CStringTable::GetInstance()->GetSkillDescription(nSkillId, nLevel, "name"));
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DC130, ASTooltip, SetSkillDescription, 178, 0x7C4A5F42); }

// @0x1409dc1f0
void ASTooltip::FUN_1409dc1f0(int nSkillId, unsigned short nLevel)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (spSkill == 0)
        return;
    MS2Ptr<SkillLevelData> spLevel = spSkill->FUN_1407e90a0(nLevel);
    if (spLevel == 0)
        return;
    CStringW strLevel;
    strLevel = BlockFormat(0x57e, nLevel);
    if (spSkill->FUN_1407e9ac0() == nLevel)
        strLevel += GetStringCommon(0x79b);
    CStringW strSp;
    if (spLevel->m_nSp > 0)
        strSp.Format(L"%s %d", (const wchar_t*)GetStringCommon(0x490), spLevel->m_nSp);
    CStringW strEp;
    if (spLevel->m_nEp > 0)
        strEp.Format(L"%s %d", (const wchar_t*)GetStringCommon(0x491), spLevel->m_nEp);
    CStringW strCooltime;
    int nCooltime = (int)spLevel->FUN_140804660();
    if (nCooltime > 0)
        strCooltime = BlockFormat(0x583, nCooltime);
    ASObj obj(2);
    obj.FUN_1407cb9c0("type", 1);
    obj.FUN_1407cbb20("level", strLevel);
    obj.FUN_1407cbb20("statSP", strSp);
    obj.FUN_1407cbb20("statEP", strEp);
    obj.FUN_1407cbb20("cooltime", strCooltime);
    FUN_1409adbe0("statDescription", obj.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DC1F0, ASTooltip, FUN_1409dc1f0, 1288, 0x964B9442); }

// The cast hint, the target / attack kind and the required weapons of a skill level.
// @0x1409dc700
void ASTooltip::FUN_1409dc700(int nSkillId, unsigned short nLevel)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    MS2Ptr<SkillLevelData> spLevel = spSkill->FUN_1407e90a0(nLevel);
    if (!spLevel)
        return;
    ASArray rows(2);
    {
        CStringW str;
        if (!spSkill->FUN_1407e9de0())
            str = GetStringCommon(0x5c1);
        else
            str = GetStringCommon(0x5c2);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", "aaaaaa");
            rows.PushValue(row.FUN_1422bb870());
        }
    }
    unsigned nRange = spSkill->GetRangeType();
    unsigned nAttack = spSkill->m_eAttackType;
    int rangeIds[3] = {0, 0x597, 0x598};
    int attackIds[3] = {0, 0x5c3, 0x596};
    {
        CStringW str;
        if (rangeIds[nRange] != 0)
            str.AppendFormat(L"%s", (const wchar_t*)GetStringCommon(rangeIds[nRange]));
        if (attackIds[nAttack] != 0)
        {
            if (str.IsEmpty())
                str.AppendFormat(L"%s", (const wchar_t*)GetStringCommon(attackIds[nAttack]));
            else
                str.AppendFormat(L" / %s", (const wchar_t*)GetStringCommon(attackIds[nAttack]));
        }
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", "aaaaaa");
            rows.PushValue(row.FUN_1422bb870());
        }
    }
    int nRight = 0;
    int nLeft = 0;
    {
        MS2Ptr<CEquipItem> spEquip = reinterpret_cast<PC*>(FUN_1409c6540())->FUN_141655c90(5);
        if (spEquip.get() != 0)
            nRight = spEquip->FUN_1411dc7f0()->GetEquipSubtype();
    }
    {
        MS2Ptr<CEquipItem> spEquip = reinterpret_cast<PC*>(FUN_1409c6540())->FUN_141655c90(4);
        if (spEquip.get() != 0)
            nLeft = spEquip->FUN_1411dc7f0()->GetEquipSubtype();
    }
    {
        int nAllowed = 0;
        CStringW str(L"");
        FUN_1409e6d00(nRight, nLeft, spSkill->m_condition.m_arrWeapon, nAllowed, str);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", nAllowed != 0 ? "aaaaaa" : "ff4040");
            rows.PushValue(row.FUN_1422bb870());
        }
    }
    FUN_1409adbe0("extraDescription", rows.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DC700, ASTooltip, FUN_1409dc700, 2045, 0x705AB547); }

// @0x1409dcf10
void ASTooltip::FUN_1409dcf10(int nSkillId, unsigned short nLevel, int bFromDialog)
{
    MS2Ptr<SkillData> spSkill = SkillDataTableCli::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return;
    MS2Ptr<JobData> spJob = reinterpret_cast<JobSystem*>(reinterpret_cast<PC*>(FUN_1409c6540())->FUN_1416546d0())->GetJobData();
    if (spJob == 0)
        return;
    MS2Ptr<JobSkillData> spRequire = spJob->FindSkill(nSkillId);
    if (spRequire == 0)
    {
        spRequire = spJob->FindSkill(spSkill->GetOriginId());
        if (spRequire == 0)
            return;
    }
    if (!spRequire->HasRequirement())
        return;
    ASArray rows(2);
    {
        ASObj row(2);
        row.FUN_1407cbb20("text", GetStringCommonByKey(L"s_word_learn_require_condition"));
        row.FUN_1409c0dc0("color", "aaaaaa");
        rows.PushValue(row.FUN_1422bb870());
    }
    unsigned short nRequireLevel = spRequire->GetRequireLevel(nLevel);
    if (nRequireLevel > 0)
    {
        // vfunc_78 is the level (an unsigned short in the exe's view of this slot)
        int nAllowed = static_cast<unsigned short>(reinterpret_cast<PCBase*>(FUN_1409c6540())->vfunc_78()) >= nRequireLevel;
        ASObj row(2);
        row.FUN_1407cbb20("text", FUN_14028dfa0(CStringW(L"s_word_require_player_level"), nRequireLevel));
        row.FUN_1409c0dc0("color", nAllowed != 0 ? "ffd400" : "ff4040");
        rows.PushValue(row.FUN_1422bb870());
    }
    {
        MS2Ptr<CSkillPointSimulator> spSim(0);
        if (bFromDialog != 0)
        {
            UISkillBookTreeDialog* pDialog = FUN_1409eb120(0x4f2d);
            if (pDialog != 0)
                spSim = pDialog->GetSimulator();
        }
        ATL::CAtlArray<unsigned>& ids = spRequire->m_requireSkillIDs;
        ATL::CAtlArray<unsigned short>& levels = spRequire->m_requireSkillLevels;
        for (unsigned i = 0; i < ids.GetCount(); i++)
        {
            MS2Ptr<JobSkill> spJobSkill(0);
            if (spSim.get() != 0)
                spJobSkill = spSim->GetEditSkill(ids[i]);
            else
                spJobSkill = reinterpret_cast<JobSystem*>(reinterpret_cast<PC*>(FUN_1409c6540())->FUN_1416546d0())->FindSkill(ids[i]);
            if (spJobSkill == 0)
                continue;
            int nAllowed = 1;
            if (!spJobSkill->m_bLearned || spJobSkill->m_nLevel < levels[i])
                nAllowed = 0;
            CStringW str = FUN_14028dfa0(CStringW(L"s_word_require_skill_level"),
                ((CStringTable*)(Unk_CommandStrings*)(CStringTable::GetInstance()))->FUN_141811980(4, spJobSkill->GetID()), levels[i]);
            if (nAllowed == 0
                && reinterpret_cast<PC*>(FUN_1409c6540())->FUN_1409eee00()->GetSkillLevel(spJobSkill->GetID()) > 0)
                str = FUN_14028dfa0(CStringW(L"s_word_require_skill_level_without_leveloption"), str);
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", nAllowed != 0 ? "ffd400" : "ff4040");
            rows.PushValue(row.FUN_1422bb870());
        }
    }
    MyPC* pPC = reinterpret_cast<MyPC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC != 0 && spRequire->m_requireQuestID != 0)
    {
        CStringW str = FUN_14028dfa0(CStringW(L"s_word_require_quest_completed"), FUN_1416e4df0(spRequire->m_requireQuestID));
        int bCompleted = reinterpret_cast<CQuestManagerCommon*>(&reinterpret_cast<Unk_TooltipQuestHolder*>(pPC->FUN_141523ba0())->m_quests)->FUN_140745590(spRequire->m_requireQuestID);
        ASObj row(2);
        row.FUN_1407cbb20("text", str);
        row.FUN_1409c0dc0("color", bCompleted != 0 ? "ffd400" : "ff4040");
        rows.PushValue(row.FUN_1422bb870());
    }
    FUN_1409adbe0("requireDescription", rows.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DCF10, ASTooltip, FUN_1409dcf10, 3355, 0x74CB32AB); }
// The market description of an UGC market product (seller, sale count / date / price).
// @0x1409ddc40
void ASTooltip::FUN_1409ddc40(CMeratMarketProduct* pProduct)
{
    if (pProduct == 0)
        return;
    CMsTime endDate(pProduct->m_ugc.m_n68);
    CStringW strDate;
    CMsTime zero(0);
    if (endDate == zero)
        strDate = L"-";
    else
    {
        int nSecond = endDate.GetSecond();
        int nMinute = endDate.GetMinute();
        int nHour = endDate.GetHour();
        int nDay = endDate.GetDay();
        int nMonth = endDate.GetMonth();
        int nYear = endDate.GetYear();
        strDate = BlockFormat(0x9dd, nYear, nMonth, nDay, nHour, nMinute, nSecond);
    }
    ASObj obj(2);
    obj.FUN_1407cbb20("seller", pProduct->m_ugc.m_user.m_strName);
    obj.FUN_1407cbb20("desc", pProduct->m_ugc.GetStr208());
    obj.FUN_1407cbb20("tag", pProduct->m_ugc.GetStr200Head());
    obj.FUN_1407cbb20("sellcount", BlockFormat(0x9dc, pProduct->m_ugc.m_n44));
    obj.FUN_1407cbb20("selldate", strDate);
    obj.FUN_1407cbb20("sellprice", StringFormat(L"{0}<img src = 'export_common_icon_merat' vspace = '-4'>< / img>", FUN_1409404f0(pProduct->m_ugc.m_n50)));
    FUN_1409eb270("marketDesc", obj);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DDC40, ASTooltip, FUN_1409ddc40, 976, 0xF641BD2B); }

// @0x1409de020
void ASTooltip::SetBuyLimitTextFromProduct(CMeratMarketPremiumProduct* pProduct)
{
    SetBuyLimitText(pProduct->m_nBuyLimit, pProduct->m_n90, pProduct->m_nBuyLimitMax);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE020, ASTooltip, SetBuyLimitTextFromProduct, 64, 0x3806FEEC); }

// @0x1409de070
void ASTooltip::SetBuyLimitText(int nScope, int nReset, int nCount)
{
    CStringW strKey = FUN_1409e3050(L"s_tooltip_buylimit", nScope, nReset);
    CStringW strText = FUN_14028dfa0(strKey, nCount);
    FUN_1409c6ef0(strText);
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE070, ASTooltip, SetBuyLimitText, 190, 0xC37C1BCE); }

// The name row of an item, with its icon code and the cash prefix.
// @0x1409de140
void ASTooltip::FUN_1409de140(ASArray* pRows, int nItemId, int nRank)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    CStringW strCode(nRank == 0 ? L"" : (const wchar_t*)CStringTable::GetInstance()->GetRankName(nRank));
    CStringW strName = FUN_141277910(spData);
    CStringW strBody;
    if (strCode.IsEmpty())
        strBody = strName;
    else
    {
        CStringW strSuffix = FUN_1409df920(spData);
        if (strSuffix.IsEmpty())
            strBody = FUN_14028dfa0(CStringW(L"s_item_tooltip_icon_code_param2"), strCode, strName);
        else
            strBody = FUN_14028dfa0(CStringW(L"s_item_tooltip_icon_code_param3"), strCode, strSuffix, strName);
    }
    CStringW strText;
    if (spData->IsCashItem())
        strText = StringFormat(L"{0} {1}", GetStringCommon(0x593), strBody);
    else
        strText = strBody;
    ASObj row(2);
    row.FUN_1407cbb20("text", strText);
    row.FUN_1409c0dc0("color", "aaaaaa");
    pRows->PushValue(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE140, ASTooltip, FUN_1409de140, 1245, 0xB8C7CCAF); }

// The trade rows of an item (install space bits 1, 2, 4).
// @0x1409de630
void ASTooltip::FUN_1409de630(ASArray* pRows, int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if ((spData->install.space & 1) != 0)
    {
        if ((spData->install.space & 2) != 0)
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", GetStringCommon(0x590));
            row.FUN_1409c0dc0("color", "aaaaaa");
            pRows->PushValue(row.FUN_1422bb870());
        }
        else if ((spData->install.space & 4) != 0)
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", GetStringCommon(0x590));
            row.FUN_1409c0dc0("color", "aaaaaa");
            pRows->PushValue(row.FUN_1422bb870());
        }
        else
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", GetStringCommon(0x58f));
            row.FUN_1409c0dc0("color", "aaaaaa");
            pRows->PushValue(row.FUN_1422bb870());
        }
    }
    else
    {
        ASObj row(2);
        row.FUN_1407cbb20("text", GetStringCommon(0x58e));
        row.FUN_1409c0dc0("color", "aaaaaa");
        pRows->PushValue(row.FUN_1422bb870());
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DE630, ASTooltip, FUN_1409de630, 955, 0x29905478); }

// @0x1409dea00
void ASTooltip::FUN_1409dea00(ASArray* pRows, int nItemId)
{
    MS2Ptr<ItemHousing> spHousing = CItemDataTable::GetInstance()->GetHousing(nItemId);
    if (spHousing == 0)
        return;
    ASObj row(2);
    row.FUN_1407cbb20("text", FormatStringId<CStringW>(0x6f8, ((CStringTable*)(Unk_CommandStrings*)(CStringTable::GetInstance()))->FUN_141811980(0x32, spHousing->categoryIndex)));
    row.FUN_1409c0dc0("color", "aaaaaa");
    pRows->PushValue(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DEA00, ASTooltip, FUN_1409dea00, 368, 0x47F7EBFE); }

// @0x1409deb80
void ASTooltip::FUN_1409deb80(ASArray* pRows, int nItemId)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    {
        int nAllowed = 0;
        CStringW str(L"");
        FUN_1409e68a0(reinterpret_cast<PC*>(FUN_1409c6540())->FUN_141654700(), spData->limit.jobLimit, nAllowed, str);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", nAllowed ? "aaaaaa" : "ff4040");
            pRows->PushValue(row.FUN_1422bb870());
        }
    }
    {
        CStringW str(L"");
        FUN_1409e6aa0(reinterpret_cast<PC*>(FUN_1409c6540())->FUN_141654700(), spData->limit.disableJobLimit, str);
        if (!str.IsEmpty())
        {
            ASObj row(2);
            row.FUN_1407cbb20("text", str);
            row.FUN_1409c0dc0("color", "ff4040");
            pRows->PushValue(row.FUN_1422bb870());
        }
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DEB80, ASTooltip, FUN_1409deb80, 786, 0x867CF598); }

// The level row of an item (with the additional level).
// @0x1409deea0
void ASTooltip::FUN_1409deea0(ASArray* pRows, int nItemId, int nRarity, int nLevel, int nAdditional)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->FUN_14053cbc0())
        return;
    if (spData->HasSkinType())
        return;
    int nBase = nLevel - nAdditional;
    int nAdd = nAdditional;
    if (nLevel <= 0)
    {
        nBase = spData->FUN_14053f0d0(nRarity);
        nAdd = 0;
    }
    CStringW str;
    if (nAdd > 0)
        str = FUN_14028dfa0(CStringW(L"s_common_item_level_with_value_additional"), nBase, nAdd);
    else
        str = FUN_14028dfa0(CStringW(L"s_common_item_level_with_value"), nBase);
    ASObj row(2);
    row.FUN_1407cbb20("text", str);
    row.FUN_1409c0dc0("color", "aaaaaa");
    pRows->PushValue(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DEEA0, ASTooltip, FUN_1409deea0, 721, 0xF72AA294); }

// The level limit row of an item (red when the owner is below it).
// @0x1409df180
void ASTooltip::FUN_1409df180(ASArray* pRows, int nItemId)
{
    if (FUN_1409c6540() == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->FUN_14053c8b0())
        return;
    if (spData->limit.levelLimit == 1)
        return;
    PCBase* pOwner = reinterpret_cast<PCBase*>(FUN_1409c6540());
    unsigned short nLevel = (unsigned short)pOwner->vfunc_78();
    int bAllowed = spData->IsLevelAllowed(nLevel);
    CStringW str;
    str.Format(L"%s %d", (const wchar_t*)GetStringCommon(0x589), spData->limit.levelLimit);
    ASObj row(2);
    row.FUN_1407cbb20("text", str);
    row.FUN_1409c0dc0("color", bAllowed ? "aaaaaa" : "ff4040");
    pRows->PushValue(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF180, ASTooltip, FUN_1409df180, 624, 0x3E3F3BC9); }

// @0x1409df400
void ASTooltip::FUN_1409df400(ASArray* pRows, int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->limit.flag6a)
        return;
    CStringW str;
    ASObj row(2);
    row.FUN_1407cbb20("text", GetStringCommonByKey(L"s_word_item_limit_vip"));
    row.FUN_1409c0dc0("color", reinterpret_cast<PC*>(FUN_1409c6540())->FUN_141662de0() ? "aaaaaa" : "ff4040");
    pRows->PushValue(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF400, ASTooltip, FUN_1409df400, 417, 0x7C8CC9F0); }

// @0x1409df5b0
void ASTooltip::FUN_1409df5b0(ASArray* pRows, int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return;
    if (!spData->limit.wedding)
        return;
    CStringW str;
    ASObj row(2);
    row.FUN_1407cbb20("text", GetStringCommonByKey(L"s_word_item_limit_wedding"));
    row.FUN_1409c0dc0("color", WeddingManager::GetInstance()->IsInProgress() ? "aaaaaa" : "ff4040");
    pRows->PushValue(row.FUN_1422bb870());
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF5B0, ASTooltip, FUN_1409df5b0, 412, 0xF4AAE57C); }

// The upgrade row of a gemstone item.
// @0x1409df760
void ASTooltip::FUN_1409df760(ASArray* pRows, MS2Ptr<CItemData> spData)
{
    if (spData == 0 || !spData->FUN_14053d840())
        return;
    {
        CItemGemStoneUpgradeTable::DataPtr spGem = CItemGemStoneUpgradeTable::GetInstance()->FindData(spData->GetItemId());
        if (spGem == 0)
            return;
        int nMask = spGem->m_nMask;
        CStringW str = FUN_1406285d0(nMask);
        ASObj row(2);
        row.FUN_1407cbb20("text", str);
        row.FUN_1409c0dc0("color", "aaaaaa");
        pRows->PushValue(row.FUN_1422bb870());
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF760, ASTooltip, FUN_1409df760, 438, 0xECB12C0F); }

// @0x1409df920
CStringW ASTooltip::FUN_1409df920(MS2Ptr<CItemData> spData)
{
    if (!spData)
        return L"";
    if (spData->cubeTextureName.mesh.GetLength() != 0)
        return GetStringCommon(0x58c);
    if (spData->HasSkinType())
        return GetStringCommon(0x594);
    return L"";
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DF920, ASTooltip, FUN_1409df920, 291, 0xDEC1F450); }

// @0x1409dfa50
void ASTooltip::FUN_1409dfa50(CItem* pItem, int& nTransferable, int& nReady, CStringW& strName)
{
    Unk_ItemOwnerRef* pTransfer = pItem->FUN_140527930();
    if (pTransfer != 0)
    {
        if (pTransfer->HasBindingRule() != 0)
        {
            nTransferable = 1;
            if (pTransfer->HasBinding() != 0)
            {
                nReady = 1;
                pTransfer->GetBindingOwnerName(reinterpret_cast<PCBase*>(FUN_1409c6540()), &strName);
            }
        }
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DFA50, ASTooltip, FUN_1409dfa50, 130, 0x14099EEF); }

// @0x1409dfae0
int ASTooltip::FUN_1409dfae0(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    Unk_ItemOwnerRef* pTransfer = pItem->FUN_140527930();
    if (pTransfer == 0)
        return 0;
    if (!pItem->FUN_140528e20())
        return 0;
    if (pItem->GetSocket() != 0 && pItem->GetSocket()->FUN_140622790() == 0)
        return 0;
    if ((pItem->IsPetItem() != 0 || pItem->GetRarity() >= 4) && pTransfer->GetCount() > 0)
        return 1;
    return 0;
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DFAE0, ASTooltip, FUN_1409dfae0, 175, 0xE08D17A2); }

// @0x1409dfba0
void ASTooltip::FUN_1409dfba0(MS2Ptr<CItemData> spData, ATL::CAtlList<CStringW>& list, int* pExpiring, unsigned nMax,
    __int64 nExpiry)
{
    if (!spData->function.FUN_14054a3d0())
        return;
    ItemDropContext ctx;
    PCBase* pOwner = reinterpret_cast<PCBase*>(FUN_1409c6540());
    if (pOwner != 0)
    {
        ctx.m_gender = reinterpret_cast<PC*>(pOwner)->FUN_141658e60();
        ctx.m_job = reinterpret_cast<PC*>(pOwner)->FUN_141654700();
    }
    std::vector<ItemDropResult> drops;
    unsigned nBoxId = spData->function.FUN_14054a460();
    if (nBoxId > 0)
        TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nBoxId, ctx, drops, true);
    if (drops.empty())
        return;
    bool bFollowEndDate = false;
    if (spData->function.FUN_14054a410())
    {
        bool bDefault = false;
        bFollowEndDate = spData->function.xml.GetBool(L"isFollowEndDate", bDefault);
    }
    std::vector<ItemDropResult> picked;
    {
        ATL::CAtlList<CStringW> names(10);
        std::sort(drops.begin(), drops.end(), FUN_1409e7a40);
        for (std::vector<ItemDropResult>::iterator it = drops.begin(); it != drops.end(); ++it)
        {
            ItemDropResult drop = *it;
            MS2Ptr<CItemData> spItem = FUN_14053f870(drop.m_itemId);
            if (spItem == 0)
                continue;
            CStringW strName = ((CStringTable*)(Unk_CommandStrings*)(CStringTable::GetInstance()))->FUN_141811980(1, drop.m_itemId);
            const CStringW& rName = strName;
            if (names.Find(rName) != 0)
                continue;
            if (*pExpiring == 0)
            {
                if (drop.HasItemLife() || static_cast<Unk_ItemDataIntView*>(spData.operator->())->HasPeriod())
                    *pExpiring = 1;
                int nLifeType = 0;
                if (drop.m_itemLife)
                    nLifeType = drop.m_itemLife->m_type;
                if (*pExpiring == 0)
                {
                    if (FUN_14052a3f0(bFollowEndDate, nExpiry, spData->period.expirationType, nLifeType,
                            spItem->period.expirationType))
                        *pExpiring = 1;
                }
            }
            if (drop.m_tooltip != 1)
            {
                if (picked.size() >= nMax)
                    continue;
            }
            names.AddTail(rName);
            picked.push_back(drop);
        }
    }
    std::sort(picked.begin(), picked.end(), FUN_1409e7930);
    for (std::vector<ItemDropResult>::iterator it = picked.begin(); it != picked.end(); ++it)
    {
        ItemDropResult drop = *it;
        MS2Ptr<CItemData> spItem = FUN_14053f870(drop.m_itemId);
        if (spItem == 0)
            continue;
        CStringW strName = ((CStringTable*)(Unk_CommandStrings*)(CStringTable::GetInstance()))->FUN_141811980(1, drop.m_itemId);
        const CStringW& rName = strName;
        CStringW str;
        bool bExpiring = false;
        if (drop.HasItemLife() || static_cast<Unk_ItemDataIntView*>(spData.operator->())->HasPeriod())
            bExpiring = true;
        int nLifeType = 0;
        if (drop.m_itemLife)
            nLifeType = drop.m_itemLife->m_type;
        if (!bExpiring)
        {
            if (FUN_14052a3f0(bFollowEndDate, nExpiry, spData->period.expirationType, nLifeType,
                    spItem->period.expirationType))
                bExpiring = true;
        }
        if (bExpiring)
            str.Format(L"- %s\n",
                (const wchar_t*)FUN_14028dfa0(CStringW(L"s_item_end_time_tooltip_expiration_prefix"), rName));
        else
            str.Format(L"- %s\n", (const wchar_t*)rName);
        list.AddTail(FUN_14183e9c0(str, drop.vfunc_o18_1()));
    }
}
namespace p4hook { MS2_REPLACE_METHOD(0x1409DFBA0, ASTooltip, FUN_1409dfba0, 2207, 0xAB580EF8); }


// True when an individual drop box item (type 0x19) contains a drop that expires (item life or follows the end date).
// @0x1409e0450
// MS2-FUNCTIONAL: CItemData::FUN_14053d660 is declared bool but the exe tests its eax without movzx (as part 1); CXmlData::GetInt is an inline COMDAT here
int ASTooltip::FUN_1409e0450(int nItemId, __int64 nExpiry)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return 0;
    if (spData->GetType() != 0x19)
        return 0;
    bool bFollowEndDate = false;
    int nBoxId = 0;
    unsigned nArgs = ((ItemFunctionArgs&)(spData->function.parameter)).FUN_1408d2380();
    if (nArgs > 0)
    {
        nBoxId = ((ItemFunctionArgs&)(spData->function.parameter)).FUN_1408d1fd0(nArgs - 1, 0);
    }
    else
    {
        int nDefault = 0;
        nBoxId = spData->function.xml.GetInt(L"individualDropBoxId", nDefault);
        bool bDefault = false;
        bFollowEndDate = spData->function.xml.GetBool(L"isFollowEndDate", bDefault);
    }
    if (nBoxId == 0)
        return 0;
    PCBase* pPc = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPc == 0)
        return 0;
    std::vector<ItemDropResult> drops;
    ItemDropContext ctx;
    ctx.m_job = reinterpret_cast<PC*>(pPc)->FUN_141654700();
    ctx.m_gender = reinterpret_cast<PC*>(pPc)->FUN_141658e60();
    if (!TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(nBoxId, ctx, drops, true))
        return 0;
    for (std::vector<ItemDropResult>::const_iterator it = drops.begin(); it != drops.end(); ++it)
    {
        ItemDropResult* pDrop = const_cast<ItemDropResult*>(&*it);
        MS2Ptr<CItemData> spItem = FUN_14053f870(pDrop->m_itemId);
        if (spItem == 0)
            continue;
        if (pDrop->HasItemLife() || spItem->HasPeriod())
            return 1;
        int nLifeType = 0;
        if (pDrop->m_itemLife)
            nLifeType = pDrop->m_itemLife->m_type;
        CItemData* pItem = spItem.operator->();
        bool bExpiring = FUN_14052a3f0(bFollowEndDate, nExpiry, spData->period.expirationType, nLifeType, pItem->period.expirationType);
        if (bExpiring)
            return 1;
    }
    return 0;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E0450, ASTooltip, FUN_1409e0450, 1192, 0x235C66A5); }


// @0x1409e0900
CStringW FUN_1409e0900(int n)
{
    CStringW str = StringFormat(L"{0}", n);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0900, FUN_1409e0900, 101, 0xC860B13F); }

// @0x1409e0970
CStringW FUN_1409e0970(int nStat, int n)
{
    CStringW str = StringFormat((const wchar_t*)GetStatValueText(nStat), n);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0970, FUN_1409e0970, 153, 0x301A029D); }

// @0x1409e0a10
CStringW FUN_1409e0a10(const CStringW& strFormat, int n)
{
    CStringW str = StringFormat((const wchar_t*)strFormat, n);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0A10, FUN_1409e0a10, 114, 0x05CCA779); }

// @0x1409e0a90
CStringW FUN_1409e0a90(float fRate)
{
    CStringW str = FormatStringId<CStringW>(0x98e, StringFormat(L"{0:0.1f}", fRate * 100.0f));
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0A90, FUN_1409e0a90, 169, 0x6FF830AD); }

// @0x1409e0b40
CStringW FUN_1409e0b40(int nTenths)
{
    CStringW str = FormatStringId<CStringW>(0x98e, StringFormat(L"{0:0.1f}", (float)nTenths / 10.0f));
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0B40, FUN_1409e0b40, 167, 0x15562167); }

// @0x1409e0bf0
CStringW FUN_1409e0bf0(int nStat, int nTenths)
{
    CStringW str = StringFormat((const wchar_t*)GetStatValueText(nStat), (float)nTenths / 10.0f);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0BF0, FUN_1409e0bf0, 173, 0x06299A49); }

// @0x1409e0cb0
CStringW FUN_1409e0cb0(const CStringW& strFormat, float fRate)
{
    CStringW str = StringFormat((const wchar_t*)strFormat, fRate * 100.0f);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E0CB0, FUN_1409e0cb0, 135, 0x798D1A23); }

// Fills the whole item tooltip of an item; 0 when the item has no data.
// @0x1409e0d40
int ASTooltip::FUN_1409e0d40(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (!spData)
        return 0;
    {
        CString strKind("export_common_tooltip_kindsItem");
        SetTooltipClass(strKind);
    }
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x8c))
        SetItemPetRankAndDisableShadow(pItem);
    else
        SetItemPetFlag(pItem->FUN_1405276c0());
    int nItemId = pItem->FUN_1405276c0();
    SetItemCashFlag(pItem->FUN_1405276c0());
    SetItemSkinFlag(pItem->FUN_1405276c0());
    SetItemPcBangFlag(pItem->FUN_1405276c0());
    SetItemVIPFlag(pItem->FUN_1405276c0());
    SetItemWeddingFlag(pItem->FUN_1405276c0());
    SetItemName(pItem);
    SetItemGrade(pItem);
    FUN_1409d5610(pItem->FUN_1405276c0());
    FUN_1409c7cc0(pItem);
    SetUgcTag(pItem);
    FUN_1409c7fc0(pItem);
    FUN_1409c8020(pItem);
    FUN_1409cc800(pItem);
    FUN_1409cd5b0(pItem);
    SetItemIconPath(pItem);
    FUN_1409cd9c0(pItem);
    FUN_1409ce5f0(pItem);
    FUN_1409ce950(pItem);
    FUN_1409d5920(pItem->FUN_1405276c0());
    FUN_1409d7900(nItemId);
    FUN_1409cfbf0(pItem);
    FUN_1409d0710(pItem);
    FUN_1409d0a80(pItem);
    FUN_1409d1d30(pItem);
    FUN_1409d64a0(pItem->FUN_1405276c0(), pItem->GetRarity(), pItem->FUN_140529070(), pItem->FUN_140529090());
    FUN_1409c7b10(pItem);
    FUN_1409c72c0(pItem);
    FUN_1409d88e0(MS2Ptr<CItem>(pItem));
    FUN_1409d3470(pItem);
    FUN_1409d3f10(pItem);
    SetItemPiece(pItem->FUN_140527840());
    FUN_1409d43b0(pItem);
    FUN_1409d4460(pItem);
    FUN_1409d8570(pItem);
    FUN_1409d4490(pItem);
    FUN_1409d46a0(pItem);
    FUN_1409d46e0(pItem);
    bool bSkill = spData->FUN_14053e900() == 0xb ? true : false;
    SetItemPetSkin(bSkill);
    unsigned nFlags = FUN_1409c6560();
    if ((nFlags & 0x80) != 0 || (nFlags & 4) != 0)
        FUN_1409cd750(pItem);
    if (((nFlags & 0x80) != 0 || (nFlags & 4) != 0 || (nFlags & 0x200) != 0 || (nFlags & 0x20) != 0 ||
            (nFlags & 0x400) != 0 || (nFlags & 0x1000) != 0 || (nFlags & 0x100) != 0 || (nFlags & 2) != 0) &&
        FUN_1409d2cb0(pItem))
        FUN_1409d3010(pItem);
    if ((nFlags & 0x80) != 0 || (nFlags & 0x400) != 0 || (nFlags & 0x1000) != 0)
        FUN_1409d3a40(pItem);
    if ((nFlags & 0x40) != 0 || (nFlags & 2) != 0)
        SetTooltipAlign(9);
    else
        SetTooltipAlign(5);
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E0D40, ASTooltip, FUN_1409e0d40, 1621, 0x0A9BE151); }

// @0x1409e13f0
int ASTooltip::FUN_1409e13f0(CItem* pCompare, CItem* pItem, int a1, int a2)
{
    if (pItem == 0 && pCompare == 0)
        return 0;
    if (pCompare != 0 && pItem != 0)
    {
        SetTooltipClass("export_common_tooltip_tooltipCompare");
        ASTooltip lhs((void*)FUN_1409c6540(), a1, 2);
        ASTooltip rhs((void*)FUN_1409c6540(), a2, 2);
        FUN_1409e15a0(pCompare, pItem, &lhs, &rhs);
    }
    else
    {
        if (pCompare != 0)
        {
            FUN_1409c6580(a1);
            FUN_1409e0d40(pCompare);
        }
        if (pItem != 0)
        {
            FUN_1409c6580(a2);
            FUN_1409e0d40(pItem);
        }
    }
    return 1;
}
// not hooked: constructs local ASTooltip objects with the DLL-compiled ctor (functional, own vftable reference)

// @0x1409e15a0
int ASTooltip::FUN_1409e15a0(CItem* pEquipped, CItem* pItem, ASTooltip* pLhs, ASTooltip* pRhs)
{
    if (pItem == 0 && pEquipped == 0)
        return 0;
    if (pEquipped != 0 && pItem != 0)
    {
        SetTooltipClass("export_common_tooltip_tooltipCompare");
        if (pLhs->FUN_1409e0d40(pEquipped) != 0)
            FUN_1409adbe0("lhsTooltip", pLhs->FUN_1422bb870());
        if (pRhs->FUN_1409e0d40(pItem) != 0)
            FUN_1409adbe0("rhsTooltip", pRhs->FUN_1422bb870());
    }
    else
    {
        if (pEquipped != 0)
        {
            *this = *pLhs;
            pLhs->FUN_1409e0d40(pEquipped);
        }
        if (pItem != 0)
        {
            *this = *pRhs;
            pRhs->FUN_1409e0d40(pItem);
        }
    }
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E15A0, ASTooltip, FUN_1409e15a0, 447, 0x2508DDC9); }

// Fills the whole item tooltip of an item id (no item instance) at a rank; 0 when the item has no data.
// @0x1409e1770
int ASTooltip::FUN_1409e1770(int nItemId, int nRank)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (!spData)
        return 0;
    {
        CString strKind("export_common_tooltip_kindsItem");
        SetTooltipClass(strKind);
    }
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x8c))
        FUN_1409d7560(nItemId, nRank);
    else
        SetItemPetFlag(nItemId);
    SetItemCashFlag(nItemId);
    SetItemSkinFlag(nItemId);
    SetItemPcBangFlag(nItemId);
    SetItemVIPFlag(nItemId);
    SetItemWeddingFlag(nItemId);
    SetItemNameById(nItemId);
    FUN_1409d55a0(nItemId, nRank);
    FUN_1409d5610(nItemId);
    SetItemMovie(nItemId);
    FUN_1409c8df0(nItemId);
    FUN_1409d5770(nItemId);
    FUN_1409d5850(nItemId);
    FUN_1409d5860(nItemId, nRank);
    FUN_1409d5920(nItemId);
    FUN_1409d7900(nItemId);
    SetItemDescription(nItemId);
    FUN_1409d5b70(nItemId);
    FUN_1409d6120(nItemId);
    FUN_1409d64a0(nItemId, nRank, 0, 0);
    FUN_1409d6730(nItemId);
    SetItemPiece(spData);
    FUN_1409d6a40(nItemId, 0);
    FUN_1409d8800(spData);
    FUN_1409d74a0(nItemId);
    FUN_1409d8300(nItemId);
    FUN_1409d8650(nItemId, nRank, 0);
    FUN_1409d7630(nItemId);
    FUN_1409d77b0(nItemId);
    bool bSkill = spData->FUN_14053e900() == 0xb ? true : false;
    SetItemPetSkin(bSkill);
    unsigned nFlags = FUN_1409c6560();
    if ((nFlags & 0x40) != 0 || (nFlags & 2) != 0)
        SetTooltipAlign(7);
    else
        SetTooltipAlign(5);
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E1770, ASTooltip, FUN_1409e1770, 1028, 0xB3EFB093); }

// The skill tooltip at the level the player learnt (level 1 when not learnt).
// @0x1409e1b80
int FUN_1409e1b80(ASTooltip* pTooltip, int nSkillId, int bFromDialog)
{
    MyPC* pPC = (MyPC*)pTooltip->FUN_1409c6540();
    if (pPC == 0)
        return 0;
    MS2Ptr<JobSkill> spSkill = reinterpret_cast<JobSystem*>(reinterpret_cast<PC*>(pPC)->FUN_1416546d0())->FindSkill(nSkillId);
    if (spSkill.get() != 0)
        return pTooltip->FUN_1409e1c50(nSkillId, spSkill->m_nLevel, bFromDialog);
    return pTooltip->FUN_1409e1c50(nSkillId, 1, bFromDialog);
}
namespace p5hook { MS2_REPLACE(0x1409E1B80, FUN_1409e1b80, 202, 0x98C7C3C0); }

// @0x1409e1c50
int ASTooltip::FUN_1409e1c50(unsigned nSkillId, unsigned short nLevel, int n)
{
    MS2Ptr<SkillData> spSkill = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillData(nSkillId);
    if (!spSkill)
        return 0;
    unsigned nOrigId = nSkillId;
    CStringW strSuffix(L"");
    do
    {
        unsigned nTooltipId = spSkill->m_nTooltip;
        if (nTooltipId == 0)
            break;
        unsigned short nTooltipLevel = nLevel;
        MS2Ptr<SkillLevelData> spLevel = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillLevelData(nTooltipId, nTooltipLevel);
        if (!spLevel)
        {
            spLevel = TSingleton<SkillDataTableCli>::GetInstance()->GetSkillLevelData(nTooltipId, 1);
            nTooltipLevel = 1;
        }
        if (!spLevel)
            break;
        if (g_nDebugUI != 0)
            strSuffix.Format(L"&lt;-[%d]", nSkillId);
        nSkillId = nTooltipId;
        nLevel = nTooltipLevel;
    } while (0);
    MS2Ptr<SkillLevelData> spLevelData = spSkill->FUN_1407e90a0(nLevel);
    if (!spLevelData)
        return 0;
    SetTooltipClass("export_common_tooltip_kindsSkill");
    SetSkillIconPath(nOrigId);
    FUN_1409dbc60(nSkillId, strSuffix);
    FUN_1409dbd30(nSkillId);
    FUN_1409dbfa0(nOrigId);
    SetSkillDescription(nSkillId, nLevel);
    FUN_1409dc1f0(nSkillId, nLevel);
    FUN_1409dcf10(nSkillId, nLevel, n);
    FUN_1409dc700(nSkillId, nLevel);
    unsigned nFlags = FUN_1409c6560();
    if ((nFlags & 0x40) != 0 || (nFlags & 2) != 0)
        SetTooltipAlign(7);
    else
        SetTooltipAlign(5);
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E1C50, ASTooltip, FUN_1409e1c50, 916, 0x9544E995); }

// @0x1409e1ff0
int ASTooltip::FUN_1409e1ff0(CItem* pItem, int nSkillId)
{
    SetTooltipClass("export_common_tooltip_tooltipCompareSkill");
    ASTooltip lhs((void*)FUN_1409c6540(), FUN_1409c6560(), 2);
    if (lhs.FUN_1409e0d40(pItem) != 0)
        FUN_1409adbe0("lhsTooltip", lhs.FUN_1422bb870());
    ASTooltip rhs((void*)FUN_1409c6540(), FUN_1409c6560(), 2);
    if (FUN_1409e1b80(&rhs, nSkillId, 0) != 0)
        FUN_1409adbe0("rhsTooltip", rhs.FUN_1422bb870());
    return 1;
}
// not hooked: constructs local ASTooltip objects with the DLL-compiled ctor (functional, own vftable reference)

// @0x1409e21a0
int ASTooltip::FUN_1409e21a0(unsigned nId, unsigned nGrade)
{
    MS2Ptr<CAchieveData> spData = GetAchieveData(nId);
    if (!spData)
        return 0;
    SetTooltipClass("export_common_tooltip_kindsAchieve");
    SetTooltipAlign(7);
    FUN_1407cb9c0("grade", nGrade);
    FUN_1407cbb20("title", FUN_14093b970(nId));
    FUN_1407cbb20("desc", FUN_14093c8d0(nId, nGrade, 0));
    FUN_1407cbb20("reward", FUN_14093ce70(nId, nGrade));
    FUN_1407cba60("imgPath", GetAchieveName(spData));
    {
        MS2Ptr<CAchieve> spAchieve = reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->Find(nId);
        if (spAchieve.get() != 0)
        {
            int nValue = (int)spAchieve->GetValue(nGrade);
            CStringW strState = nValue != 0 ? GetStringCommon(0x780) : GetStringCommon(0x77f);
            if (nValue != 0)
            {
                CStringW strDate = FUN_14093e330(spAchieve.get(), nGrade);
                strState = StringFormat(L"{0} ({1})", strState, strDate);
            }
            FUN_1407cbb20("state", strState);
        }
    }
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E21A0, ASTooltip, FUN_1409e21a0, 1076, 0x920515FB); }

// @0x1409e2630
int ASTooltip::FUN_1409e2630(int nId)
{
    if (nId == 0)
        return 0;
    return ApplyTextTooltip(((CStringTable*)(Unk_CommandStrings*)(((struct Unk_CommandStrings*)TSingleton<CStringTable>::GetInstance())))->FUN_141811980(9, nId));
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E2630, ASTooltip, FUN_1409e2630, 116, 0xE5467A3C); }

// The buff (additional effect) tooltip; pSkillAttr is an AdditionalLevelData.
// @0x1409e2750
int ASTooltip::FUN_1409e2750(void* pSkillAttr, int a1, unsigned a2)
{
    if (pSkillAttr == 0)
        return 0;
    int nMaxWidth = 0x198;
    CStringW strText;
    if (((AdditionalLevelData*)pSkillAttr)->IsBuff())
        strText = StringFormat(L"<FONT color='#00AEFF'>{0}</FONT>\n", TSingleton<CStringTable>::GetInstance()->FUN_141812290(((AdditionalLevelData*)pSkillAttr)->GetID(), ((AdditionalLevelData*)pSkillAttr)->GetLevel(), "name"));
    else
        strText = StringFormat(L"<FONT color='#FF4040'>{0}</FONT>\n", TSingleton<CStringTable>::GetInstance()->FUN_141812290(((AdditionalLevelData*)pSkillAttr)->GetID(), ((AdditionalLevelData*)pSkillAttr)->GetLevel(), "name"));
    CStringW strDesc = TSingleton<CStringTable>::GetInstance()->FUN_141812290(((AdditionalLevelData*)pSkillAttr)->GetID(), ((AdditionalLevelData*)pSkillAttr)->GetLevel(), "tooltipDescription");
    if (a2 > 0 && ((AdditionalLevelData*)pSkillAttr)->m_nDurationTick > 0)
    {
        if (!((AdditionalLevelData*)pSkillAttr)->IsHideBuffIcon())
        {
            CTimeSpan span((__int64)FUN_14028d280(a2));
            CStringW strTime = FormatTimeSpan(span, true, true, true, true);
            if (strTime.IsEmpty() && a2 > 0 && a2 < 1000)
            {
                float fSec = (float)a2 / 1000.0f;
                strTime = FUN_14028dfa0(CStringW(L"s_common_millisec"), fSec);
            }
            CStringW strRemain = StringFormat((const wchar_t*)GetStringCommon(0x5cf), strTime);
            strDesc.Append(StringFormat(L"\n\n{0}", strRemain));
        }
    }
    strText.Append(strDesc);
    SetTooltipClass("export_common_tooltip_tooltipText");
    SetText(strText);
    SetOnDelay(0);
    SetOffDelay(0);
    SetTooltipAlign(a1);
    SetMaxWidth(0x198);
    return 1;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E2750, ASTooltip, FUN_1409e2750, 1517, 0x92AA5002); }

// @0x1409e2d50
void ASTooltip::FUN_1409e2d50(int nCount)
{
    CStringW strText;
    CStringW strCount;
    if (nCount < 0)
        strCount = GetStringCommon(0x51b);
    else if (nCount == 0)
        strCount = GetStringCommon(0x51d);
    else
        strCount.Format(L"%d", nCount);
    strText = FormatStringId<CStringW>(0x588, strCount);
    FUN_1407cbb20("text", strText);
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E2D50, ASTooltip, FUN_1409e2d50, 378, 0x856F2937); }

// Builds the item tooltip of an item-able entry (a reward / drop row) into pOut.
// @0x1409e2ed0
void FUN_1409e2ed0(Scaleform::GFx::Value* pOut, ItemAble& item)
{
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(item.vfunc_o18_0(), item.vfunc_o18_1(), 0) != 0)
    {
        spItem->SetCountClamped(item.vfunc_o18_2());
        ASTooltip tip((void*)reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0()), 0x20, 2);
        if (tip.FUN_1409e0d40(spItem.get()) != 0)
            *pOut = tip.FUN_1422bb870();
    }
}
// not hooked: constructs local ASTooltip objects with the DLL-compiled ctor (functional, own vftable reference)

// The buy-limit key "<prefix>_<reset>_<scope>".
// @0x1409e3050
CStringW FUN_1409e3050(const CStringW& strPrefix, int nScope, int nReset)
{
    CStringW strScope;
    if (nScope == 1)
        strScope = L"account";
    else if (nScope == 2)
        strScope = L"character";
    CStringW strReset;
    switch (nReset)
    {
    case 0:
        strReset = L"noreset";
        break;
    case 1:
        strReset = L"day";
        break;
    case 2:
        strReset = L"week";
        break;
    case 3:
        strReset = L"month";
        break;
    }
    return StringFormat(L"{0}_{1}_{2}", strPrefix, strReset, strScope);
}
namespace p5hook { MS2_REPLACE(0x1409E3050, FUN_1409e3050, 314, 0x28431E15); }

// The package tooltip of a limited (type 3) merat market product: its items as drop rows.
// @0x1409e3190
bool ASTooltip::FUN_1409e3190(CMeratMarketPremiumProduct* pProduct, bool bWithName)
{
    if (pProduct->m_nType != 3)
        return false;
    CRBMap<int, MS2Ptr<CDBPremiumProduct> >& mapLimit = pProduct->m_mapLimit;
    if (mapLimit.IsEmpty())
        return false;
    std::vector<ItemDropResult> results;
    for (POSITION pos = mapLimit.GetHeadPosition(); pos != 0; mapLimit.GetNext(pos))
    {
        MS2Ptr<CDBPremiumProduct> spSub = mapLimit.GetValueAt(pos);
        if (spSub == 0)
            continue;
        int nRank = spSub->m_nGrade;
        results.push_back(ItemDropResult(spSub->m_nItemId, spSub->m_nb0, nRank, 0, 0, 0, 0, false, false, 0, false, false, false, false));
    }
    if (results.empty())
        return false;
    FUN_1409e72a0(&results);
    CString strKind(bWithName == true ? "export_common_tooltip_item_package_and_name" : "export_common_tooltip_item_package");
    SetTooltipClass(strKind);
    FUN_1409dbbc0(pProduct->GetName());
    FUN_1409d55a0(0, pProduct->GetGrade());
    SetTooltipAlign(5);
    return true;
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E3190, ASTooltip, FUN_1409e3190, 833, 0x2635AC39); }

// The option text of an item: the rows of every shown option kind (the pet constant options with their growth), each
// kind under its title (pet info tab).
// @0x1409e34e0
CStringW FUN_1409e34e0(MS2Ptr<CItem> spItem)
{
    if (!spItem || spItem->FUN_140527840() == 0)
        return CStringW(L"");
    CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0());
    if (pStatus == 0)
        return CStringW(L"");
    MS2Ptr<CItemOption> spOption(pStatus->m_spOption);
    if (spOption.IsNull())
        return CStringW(L"");
    FUN_1409e5480();
    CStringW strKinds[5] = { L"" };
    CStringW strText;
    int bPet = spItem->IsPetItem();
    MS2Ptr<CPetData> spPet(0);
    if (bPet != 0)
        spPet = TSingleton<CPetDataTable>::GetInstance()->Find(spItem->FUN_140527840()->GetPetId());
    for (unsigned __int64 i = 0; i < 5; i++)
    {
        if (i == 1)
            continue;
        CStringW& strKind = strKinds[i];
        int nKind = (int)i;
        Unk_EnchantMap& mapStats = spOption->GetStatMap(nKind);
        Unk_SocketSpecialMap& mapSpecials = spOption->GetSpecialMap(nKind);
        Unk_OptionTextMap mapTexts(10);
        if (bPet != 0 && nKind == 2)
        {
            spOption->FUN_1405cb900(nKind, mapTexts);
        }
        else
        {
            unsigned nOrder = 0;
            for (POSITION pos = mapStats.GetStartPosition(); pos != 0; mapStats.GetNext(pos))
            {
                int nStat = mapStats.GetKeyAt(pos);
                unsigned nIndex = nOrder;
                mapTexts.SetAt(nIndex, GetStatName(nStat));
                nOrder++;
            }
            for (POSITION pos = mapSpecials.GetStartPosition(); pos != 0; mapSpecials.GetNext(pos))
            {
                Unk_SocketSpecialStat eSpecial = mapSpecials.GetKeyAt(pos);
                unsigned nIndex = nOrder;
                mapTexts.SetAt(nIndex, FUN_14081d380(eSpecial));
                nOrder++;
            }
        }
        int nRow = 0;
        int nTexts = mapTexts.GetCount();
        for (POSITION pos = mapTexts.GetHeadPosition(); pos != 0; mapTexts.GetNext(pos))
        {
            int nStat = FindStatByName(mapTexts.GetValueAt(pos));
            if (nStat != -1)
            {
                Unk_EnchantMap::CPair* pPair = mapStats.Lookup(nStat);
                if (pPair == 0)
                    continue;
                MS2Ptr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                if (i == 0 && spItem->FUN_140527840()->FUN_14053f750(nStat))
                {
                    nRow++;
                    continue;
                }
                CStringW strValue;
                CStringW strRow;
                if (i == 0 && bPet != 0 && spPet.get() != 0)
                {
                    CStringW strBase;
                    CStringW strMax;
                    CStringW strRate;
                    if (spBase->HasValue())
                    {
                        __int64 nValue = spBase->GetValue();
                        float fRate = (float)__imp_floor((double)FUN_140632990(nValue, spPet->m_fConstantOptionFactor));
                        __int64 nMax = (__int64)((float)nValue + fRate * (float)(*GetClientConstants()->PetMaxLevel.Get() - 1));
                        nValue += fRate * (float)(spItem->FUN_140528c20() - 1);
                        strValue = FUN_140631720(nStat, (int)nValue, false);
                        strBase = FUN_1409e0900(spBase->GetValue());
                        strMax = FUN_1409e0900((int)nMax);
                        strRate = FUN_1409e0900((int)fRate);
                    }
                    if (FUN_1409c5210(strRow, spItem, nStat, nKind, spBase, strValue))
                    {
                        strKind.Append(strRow);
                        CStringW strDesc = FUN_14028dfa0(L"s_tooltip_itemoption_stat_row_pet_constant_desc", strBase, strMax, strRate);
                        strKind.Append(strDesc);
                    }
                }
                else
                {
                    strValue = FUN_140631600(nStat, spBase.get());
                    if (FUN_1409c5210(strRow, spItem, nStat, nKind, spBase, strValue))
                        strKind.Append(strRow);
                }
                nRow++;
                continue;
            }
            Unk_SocketSpecialStat eSpecial = (Unk_SocketSpecialStat)FUN_14081d260(mapTexts.GetValueAt(pos));
            if (eSpecial != 0)
            {
                Unk_SocketSpecialMap::CPair* pPair = mapSpecials.Lookup(eSpecial);
                if (pPair == 0)
                    continue;
                MS2Ptr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                CStringW strValue;
                CStringW strRow;
                if (i == 0 && bPet != 0 && spPet.get() != 0)
                {
                    CStringW strBase;
                    CStringW strMax;
                    CStringW strRate;
                    if (spBase->HasValue())
                    {
                        int nValue = spBase->GetValue();
                        float fRate = (float)floor(FUN_1406198a0(nValue, spPet->m_fConstantOptionFactor));
                        float fMax = (float)nValue + fRate * (float)(*GetClientConstants()->PetMaxLevel.Get() - 1);
                        nValue += fRate * (float)(spItem->FUN_140528c20() - 1);
                        strValue = FUN_140631830(eSpecial, nValue, spItem->FUN_140527840());
                        int nRaw = spBase->GetValue();
                        strBase = StringFormat(L"{0:0.1f}", nRaw);
                        strMax = StringFormat(L"{0:0.1f}", fMax);
                        strRate = StringFormat(L"{0:0.1f}", fRate);
                    }
                    if (FUN_1409c56f0(strRow, spItem, eSpecial, nKind, spBase, strValue))
                    {
                        strKind.Append(strRow);
                        CStringW strDesc = FUN_14028dfa0(L"s_tooltip_itemoption_stat_row_pet_constant_desc", strBase, strMax, strRate);
                        strKind.Append(strDesc);
                    }
                }
                else
                {
                    strValue = FUN_140631830(eSpecial, spBase->GetValue(), spItem->FUN_140527840());
                    if (FUN_1409c56f0(strRow, spItem, eSpecial, nKind, spBase, strValue))
                        strKind.Append(strRow);
                }
                nRow++;
                continue;
            }
        }
    }
    CStringW strSeparator(s_wsText0xbf5);
    for (unsigned __int64 k = 0; k < 5; k++)
    {
        if (FUN_1409e5450((int)k))
            continue;
        CStringW& strKind = strKinds[k];
        if (strKind.IsEmpty())
            continue;
        if (!strSeparator.IsEmpty() && !strText.IsEmpty())
            strText.Append(strSeparator);
        strText.Append(StringFormat(FUN_1409e6010((int)k, spItem.get()), strKind));
    }
    return strText;
}
namespace p5hook { MS2_REPLACE(0x1409E34E0, FUN_1409e34e0, 5142, 0x1005618E); }

// The random option rows of an item (option kind 2) in the compact layout; *pBest when any row has the best roll.
// @0x1409e4950
void FUN_1409e4950(MS2Ptr<CItem> spItem, CStringW& strOut, bool* pBest)
{
    *pBest = false;
    if (!spItem)
        return;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (!spData)
        return;
    CItemStatus* pStatus = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0());
    if (pStatus == 0)
        return;
    MS2Ptr<CItemOption> spOption(pStatus->m_spOption);
    if (spOption.IsNull())
        return;
    FUN_1409e5480();
    CStringW strText;
    int bPet = spItem->IsPetItem();
    Unk_EnchantMap& mapStats = spOption->GetStatMap(2);
    Unk_SocketSpecialMap& mapSpecials = spOption->GetSpecialMap(2);
    {
        Unk_OptionTextMap mapTexts(10);
        if (bPet != 0)
        {
            spOption->FUN_1405cb900(2, mapTexts);
        }
        else
        {
            unsigned nOrder = 0;
            for (POSITION pos = mapStats.GetStartPosition(); pos != 0; mapStats.GetNext(pos))
            {
                int nStat = mapStats.GetKeyAt(pos);
                unsigned nIndex = nOrder;
                mapTexts.SetAt(nIndex, GetStatName(nStat));
                nOrder++;
            }
            for (POSITION pos = mapSpecials.GetStartPosition(); pos != 0; mapSpecials.GetNext(pos))
            {
                Unk_SocketSpecialStat eSpecial = mapSpecials.GetKeyAt(pos);
                unsigned nIndex = nOrder;
                mapTexts.SetAt(nIndex, FUN_14081d380(eSpecial));
                nOrder++;
            }
        }
        int nRow = 0;
        int nTexts = mapTexts.GetCount();
        for (POSITION pos = mapTexts.GetHeadPosition(); pos != 0; mapTexts.GetNext(pos))
        {
            int nStat = FindStatByName(mapTexts.GetValueAt(pos));
            if (nStat != -1)
            {
                Unk_EnchantMap::CPair* pPair = mapStats.Lookup(nStat);
                if (pPair == 0)
                    continue;
                MS2Ptr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                if (reinterpret_cast<CItemOptionTable*>(FUN_140166430())->IsHighRollValue(spItem, nStat, 2, spBase->GetValue()) == true)
                    *pBest = true;
                CStringW strValue = FUN_140631600(nStat, spBase.get());
                CStringW strRow;
                if (FUN_1409c5210(strRow, spItem, nStat, 2, spBase, strValue))
                    strText.Append(strRow);
                nRow++;
                continue;
            }
            Unk_SocketSpecialStat eSpecial = (Unk_SocketSpecialStat)FUN_14081d260(mapTexts.GetValueAt(pos));
            if (eSpecial != 0)
            {
                Unk_SocketSpecialMap::CPair* pPair = mapSpecials.Lookup(eSpecial);
                if (pPair == 0)
                    continue;
                MS2Ptr<BaseOption> spBase(pPair->m_value);
                if (!spBase)
                    continue;
                if (reinterpret_cast<CItemOptionTable*>(FUN_140166430())->IsHighRollSpecialValue(spItem, pPair->m_key, 2, spBase->GetValue()) == true)
                    *pBest = true;
                CStringW strValue = FUN_140631830(eSpecial, spBase->GetValue(), spItem->FUN_140527840());
                CStringW strRow;
                if (FUN_1409c56f0(strRow, spItem, eSpecial, 2, spBase, strValue))
                    strText.Append(strRow);
                nRow++;
                continue;
            }
        }
    }
    CStringW strSeparator(s_wsText0xbf5);
    if (!FUN_1409e5450(2) && !strText.IsEmpty())
    {
        CStringW strKey(L"s_tooltip_itemoption_kinds_random_nohead");
        strOut = StringFormat((const wchar_t*)GetStringCommonByKey(strKey), strText);
    }
}
namespace p5hook { MS2_REPLACE(0x1409E4950, FUN_1409e4950, 2417, 0xFE9700B0); }

// @0x1409e5320
CStringW FUN_1409e5320(const int& nSeason)
{
    GachaBoxDataPtr spBox = TSingleton<ItemGachaBoxTable>::GetInstance()->GetBox(nSeason);
    if (spBox == 0)
        return L"";
    if ((unsigned)spBox->GetSeason() <= 0)
        return L"";
    CStringW str = FUN_1407196b0(spBox->GetSeason());
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E5320, FUN_1409e5320, 284, 0xCE0B0243); }

// @0x1409e6010
CStringW FUN_1409e6010(int nKind, CItem* pItem)
{
    if (nKind == 0 && pItem->IsPetItem() != 0)
    {
        CStringW strKey(L"s_tooltip_itemoption_kinds_constant_pet");
        return GetStringCommonByKey(strKey);
    }
    if (nKind == 2 && pItem->IsPetItem() != 0)
    {
        CStringW strKey(L"s_tooltip_itemoption_kinds_random_pet");
        return GetStringCommonByKey(strKey);
    }
    return s_wsKindLabel[nKind];
}
// not hooked: reads s_wsKindLabel (filled by FUN_1409e5480 in the exe; the DLL copy stays empty)

// The trade / bind / move limit lines of an item, joined with strSeparator.
// @0x1409e6120
CStringW FUN_1409e6120(CItem* pItem, int nTradeable, int nPersonal, int nBindable, int nBindOnGet, const CStringW& strSeparator, int nCount, CStringW strBindName, int nRemainOnly)
{
    CStringW strText;
    if (nRemainOnly != 0)
        strText = BlockFormat<int>(0x525, nCount);
    else if (nTradeable == 1 && nCount > 0)
    {
        if (nPersonal != 0)
            strText = BlockFormat<int>(0x523, nCount);
        else
            strText = BlockFormat<int>(0x524, nCount);
    }
    else if (nPersonal == 0 && nTradeable == 0)
        strText = GetStringCommon(0x520);
    else if (nPersonal == 0)
        strText = GetStringCommon(0x51e);
    else if (nTradeable == 0)
        strText = GetStringCommon(0x51f);
    if (nBindable == 1)
    {
        if (nBindOnGet == 1)
        {
            if (!strText.IsEmpty())
                strText += strSeparator;
            strText += FormatStringId<CStringW>(0x527, strBindName);
        }
        else
        {
            CStringW strBind = BlockFormat(0x526);
            switch (pItem->FUN_140527840()->limit.transferType)
            {
            case 2:
            {
                CStringW strKey(L"s_word_item_limit_bind_get");
                strBind = GetStringCommonByKey(strKey);
            }
                break;
            case 3:
            case 4:
                if (pItem->FUN_140527840()->IsPetItem())
                {
                    CStringW strKey(L"s_word_item_limit_bind_pet");
                    strBind = GetStringCommonByKey(strKey);
                }
                else if (pItem->FUN_140527840()->FUN_14053cbc0())
                {
                    CStringW strKey(L"s_word_item_limit_bind_equip");
                    strBind = GetStringCommonByKey(strKey);
                }
                else
                {
                    CStringW strKey(L"s_word_item_limit_bind_use");
                    strBind = GetStringCommonByKey(strKey);
                }
                break;
            }
            if (!strText.IsEmpty())
                strText += strSeparator;
            strText += strBind;
        }
    }
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0xcf))
    {
        if (pItem->FUN_140527840()->IsMoveDisabled())
        {
            if (!strText.IsEmpty())
                strText += strSeparator;
            if (pItem->FUN_14052a480() != 0)
                strText += FUN_14028dfa0(CStringW(L"s_word_item_limit_moveDisable_store_in"), pItem->FUN_14052a4f0());
            else
            {
                CStringW strKey(L"s_word_item_limit_moveDisable");
                strText += GetStringCommonByKey(strKey);
            }
        }
    }
    return strText;
}
namespace p5hook { MS2_REPLACE(0x1409E6120, FUN_1409e6120, 1901, 0x31228E7E); }

// The "enabled jobs" line; nAllowed is set when the player's job (or the beginner job 1) is in the list.
// @0x1409e68a0
void FUN_1409e68a0(int nJob, ATL::CAtlArray<unsigned>& jobs, int& nAllowed, CStringW& strOut)
{
    if (nJob == 1)
        nJob = 10;
    CStringW strList;
    for (unsigned i = 0; i < jobs.GetCount(); i++)
    {
        int nJobId = jobs[i];
        if (!FUN_1402226b0(nJobId))
            continue;
        if (nJobId == 1)
            nAllowed = 1;
        if (nJobId == nJob)
            nAllowed = 1;
        CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x4d, nJobId);
        if (!strList.IsEmpty())
            strList.Append(StringFormat(L", {0}", strName));
        else
            strList.Append(strName);
    }
    if (strList.GetLength() > 0)
        strOut = FUN_14028dfa0(CStringW(L"s_word_enable_jobs"), strList);
}
namespace p5hook { MS2_REPLACE(0x1409E68A0, FUN_1409e68a0, 503, 0xAA7F5742); }

// The "disabled jobs" line (tests the output string's length, not the list's, as the exe does).
// @0x1409e6aa0
void FUN_1409e6aa0(int nJob, ATL::CAtlArray<unsigned>& jobs, CStringW& strOut)
{
    CStringW strList;
    for (unsigned i = 0; i < jobs.GetCount(); i++)
    {
        int nJobId = jobs[i];
        if (!FUN_1402226b0(nJobId))
            continue;
        CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x4d, TSingleton<JobTable>::GetInstance()->GetSubJob1(nJobId));
        if (!strList.IsEmpty())
            strList.Append(StringFormat(L", {0}", strName));
        else
            strList.Append(strName);
    }
    if (strOut.GetLength() > 0)
        strOut = FUN_14028dfa0(CStringW(L"s_word_disable_jobs"), strList);
}
namespace p5hook { MS2_REPLACE(0x1409E6AA0, FUN_1409e6aa0, 461, 0xD970B87F); }

// @0x1409e6c80
int FUN_1409e6c80(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    if (!pItem->FUN_140527840()->FUN_14053cbc0())
        return 0;
    if (TSingleton<CUIService>::GetInstance()->FUN_141adc940((eUIClassID)0x4e8d) == 0)
        return 0;
    if (TSingleton<CUIService>::GetInstance()->FUN_141adc940((eUIClassID)0x4e8e) == 0)
        return 0;
    return 1;
}
namespace p5hook { MS2_REPLACE(0x1409E6C80, FUN_1409e6c80, 112, 0xBBCD868C); }

// The required weapons line; nAllowed is set when the equipped right or left hand weapon kind is listed.
// @0x1409e6d00
void FUN_1409e6d00(int nRight, int nLeft, ATL::CAtlArray<Unk_SkillWeapon>& weapons, int& nAllowed, CStringW& strOut)
{
    CStringW strSep(L"");
    for (unsigned i = 0; i < weapons.GetCount(); i++)
    {
        Unk_SkillWeapon& weapon = weapons[i];
        if (weapon.m_nRightHand == nRight || weapon.m_nLeftHand == nLeft)
            nAllowed = 1;
        if (weapon.m_nRightHand != 0)
        {
            strOut += strSep + TSingleton<CStringTable>::GetInstance()->FUN_141811980(8, weapon.m_nRightHand);
            strSep = L", ";
        }
        if (weapon.m_nLeftHand != 0)
        {
            strOut += strSep + TSingleton<CStringTable>::GetInstance()->FUN_141811980(8, weapon.m_nLeftHand);
            strSep = L", ";
        }
    }
    if (strOut.GetLength() > 0)
    {
        CStringW strText = StringFormat((const wchar_t*)GetStringCommon(0x584), strOut);
        strOut = strText;
    }
}
namespace p5hook { MS2_REPLACE(0x1409E6D00, FUN_1409e6d00, 695, 0xCA3426ED); }

// @0x1409e6fc0
int FUN_1409e6fc0(int nKind)
{
    switch (nKind)
    {
    case 0x28:
    case 0x29:
        return 0x19;
    case 0x2b:
        return 9;
    case 0x2c:
        return 0xe;
    case 0x2d:
        return 0x26;
    case 0x2e:
    case 0x2f:
        return 0x22;
    case 0x30:
    case 0x31:
        return 0xc;
    case 0x32:
        return 0x32;
    case 0x35:
        return 0x17;
    }
    return nKind;
}
namespace p5hook { MS2_REPLACE(0x1409E6FC0, FUN_1409e6fc0, 118, 0xD6007B33); }

// Appends the trophy requirements (id + grade) the player has not reached; true when any.
// @0x1409e7080
bool FUN_1409e7080(const ATL::CAtlArray<unsigned long>& ids, const ATL::CAtlArray<int>& grades, CStringW& strOut)
{
    for (unsigned i = 0; i < ids.GetCount(); i++)
    {
        int nId = ids[i];
        MS2Ptr<CAchieveData> spData = GetAchieveData(nId);
        if (!spData)
            continue;
        int nGrade = FUN_1409e8500(grades, i, spData->m_nMaxGrade);
        MS2Ptr<CAchieveGradeData> spGrade = spData->GetGrade(nGrade);
        if (!spGrade)
            continue;
        if (reinterpret_cast<CAchieveManager*>(FUN_1406c7600())->IsGradeCleared(nId, nGrade) != 0)
            continue;
        if (!strOut.IsEmpty())
            strOut.Append(L"\n");
        CStringW strLine = FUN_14093bd40(nId, nGrade, CStringW(L""));
        strOut += strLine;
    }
    return !strOut.IsEmpty();
}
namespace p5hook { MS2_REPLACE(0x1409E7080, FUN_1409e7080, 530, 0xA5E61942); }

// Fills the itemPackageList rows (one row per drop result).
// @0x1409e72a0
void ASTooltip::FUN_1409e72a0(const std::vector<ItemDropResult>* pResults)
{
    if (pResults->empty())
        return;
    ASArray rows(2);
    for (std::vector<ItemDropResult>::const_iterator it = pResults->begin(); it != pResults->end(); ++it)
    {
        ItemDropResult* pDrop = const_cast<ItemDropResult*>(&*it);
        ASObj row(2);
        if (!row.FUN_1409c5bd0(pDrop))
            continue;
        rows.PushValue(row.FUN_1422bb870());
    }
    FUN_1409adbe0(s_strItemPackageList, rows.FUN_1422bb870());
    CString strKind("export_common_tooltip_kindsItemPackage");
    SetTooltipClass(strKind);
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E72A0, ASTooltip, FUN_1409e72a0, 431, 0x99FCA1A4); }

// Fills the itemBreakIngredientList rows (the ingredients with a count that are not plain materials).
// @0x1409e7460
void ASTooltip::FUN_1409e7460(Unk_IngVec* pIngredients)
{
    if (reinterpret_cast<std::vector<MS2Ptr<CIngredientInfo> >*>(pIngredients)->empty())
        return;
    ASArray rows(2);
    // Unk_IngVec is the opaque stand-in of std::vector<MS2Ptr<CIngredientInfo>> (same 24-byte layout)
    for (std::vector<MS2Ptr<CIngredientInfo> >::const_iterator it = reinterpret_cast<const std::vector<MS2Ptr<CIngredientInfo> >*>(pIngredients)->begin();
         it != reinterpret_cast<const std::vector<MS2Ptr<CIngredientInfo> >*>(pIngredients)->end(); ++it)
    {
        MS2Ptr<CIngredientInfo> spIng(*it.operator->());
        if (spIng == 0)
            continue;
        if (spIng->m_c == 0)
            continue;
        MS2Ptr<CItemData> spData = FUN_14053f870(spIng->m_a);
        if (spData == 0)
            continue;
        if (!spData->IsPieceItem() && !spData->FUN_14053d880() && spData->GetType() != 0xf)
            continue;
        ASObj row(2);
#ifdef __clang__
        ItemDropResult drop(spIng->m_a, spIng->m_c, FUN_14053feb0(spIng->m_a), 0, 0, 0, 0, false, false, 0, false, false, false, false);
        if (!row.FUN_1409c5bd0(&drop))
#else
        if (!row.FUN_1409c5bd0(&ItemDropResult(spIng->m_a, spIng->m_c, FUN_14053feb0(spIng->m_a), 0, 0, 0, 0, false, false, 0, false, false, false, false)))
#endif
            continue;
        rows.PushValue(row.FUN_1422bb870());
    }
    FUN_1409adbe0(s_strItemBreakIngredientList, rows.FUN_1422bb870());
}
namespace p5hook { MS2_REPLACE_METHOD(0x1409E7460, ASTooltip, FUN_1409e7460, 1043, 0xA27F316C); }

// The enablePreview hint ("preview" key binding text).
// @0x1409e7880
CStringW FUN_1409e7880()
{
    CStringW strKey = CKeyTable::GetInstance()->GetActionKeyName(0x49406, 0);
    CStringW str = FUN_14028dfa0(CStringW(L"s_msg_tooltip_enable_preview"), strKey);
    return str;
}
namespace p5hook { MS2_REPLACE(0x1409E7880, FUN_1409e7880, 168, 0x057BF814); }

// Drop list order: higher rank first, then the tooltip-flagged entries.
// @0x1409e7930
bool FUN_1409e7930(ItemDropResult& lhs, ItemDropResult& rhs)
{
    if (lhs.vfunc_o18_1() != rhs.vfunc_o18_1())
        return lhs.vfunc_o18_1() > rhs.vfunc_o18_1();
    int bLhs = lhs.m_tooltip == 1;
    int bRhs = rhs.m_tooltip == 1;
    return bLhs > bRhs;
}
namespace p5hook { MS2_REPLACE(0x1409E7930, FUN_1409e7930, 259, 0x1A341905); }

// Drop list order: the tooltip-flagged entries first, then lower rank first.
// @0x1409e7a40
bool FUN_1409e7a40(ItemDropResult& lhs, ItemDropResult& rhs)
{
    int bLhs = lhs.m_tooltip == 1;
    int bRhs = rhs.m_tooltip == 1;
    if (bLhs != bRhs)
        return bLhs > bRhs;
    return lhs.vfunc_o18_1() < rhs.vfunc_o18_1();
}
namespace p5hook { MS2_REPLACE(0x1409E7A40, FUN_1409e7a40, 215, 0x3F3CBC7A); }


// The value-from-XML getters of CXmlData (templated lookups over m_values, first instantiated here).
CString FUN_1407186a0(const CStringW& value);
std::vector<int> FUN_140719090(const CStringW& value);
__int64 FUN_140718320(const CStringW& value);
bool FUN_1407183f0(const CStringW& value);

// @0x1409e8500
const int& FUN_1409e8500(const CAtlArray<int>& arr, int nIndex, const int& nDefault)
{
    int nCount = (int)arr.GetCount();
    if (nIndex < 0 || nIndex > nCount - 1)
        return nDefault;
    return arr[nIndex];
}

// @0x1409e8560
CString CXmlData::GetString(const CStringW& strKey, const CString& strDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return strDefault;
    return FUN_1407186a0(strValue);
}

// @0x1409e8620
std::vector<int> CXmlData::GetIntArray(const CStringW& strKey, const std::vector<int>& vDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return vDefault;
    return FUN_140719090(strValue);
}

// @0x1409e86e0
__int64 CXmlData::GetInt64(const CStringW& strKey, const __int64& nDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return nDefault;
    return FUN_140718320(strValue);
}

// @0x1409e8780
bool CXmlData::GetBool(const CStringW& strKey, const bool& bDefault)
{
    CStringW strValue;
    if (!m_values.Lookup(strKey, strValue))
        return bDefault;
    return FUN_1407183f0(strValue);
}

// @0x1409eb1d0
void ASObj::FUN_1409eb1d0(const char* szName, const ASArray& arr)
{
    ASData data;
    data.AddObj(arr);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409eb270
void ASObj::FUN_1409eb270(const char* szName, const ASObj& obj)
{
    ASData data;
    data.AddObj(obj);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409eb3b0
void ASObj::FUN_1409eb3b0(const char* szName, long n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}

// @0x1409e7dc0
MS2Ptr<AScript> FUN_1409e7dc0(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<AScript> sp(new ASObj(v, nMovieId));
    return sp;
}

CStringW FUN_1407196b0(long n);                  // a number with thousands separators
CStringW FUN_14083cb20(const CStringW& str);

// @0x1409eb450
CStringW FUN_1409eb450(int n)
{
    return FUN_14083cb20(FUN_1407196b0(n));
}

// The singleton getters and the player's skill tier manager copy (inline members first instantiated in this unit).
// @0x1409eecd0
CChatEmoticonTable* TSingleton<CChatEmoticonTable>::GetInstance()
{
    return s_instance;
}

// @0x1409eed50
CUGCMapSetItemTable* TSingleton<CUGCMapSetItemTable>::GetInstance()
{
    return s_instance;
}

// @0x1409eee00
MS2Ptr<Unk_PCSkillTree> PC::FUN_1409eee00()
{
    return reinterpret_cast<const MS2Ptr<Unk_PCSkillTree>&>(m_spSkillTier1110);   // the member is typed by its real class in fittingdollpc.h
}

// The skill book tree dialog if it is open (UI id 0x4f2d at the callers).
// @0x1409eb120
UISkillBookTreeDialog* FUN_1409eb120(int nId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<UISkillBookTreeDialog*>((UIObject*)p);
    }
    return 0;
}

// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9e1c0-0x142c9e950 .text$yd
