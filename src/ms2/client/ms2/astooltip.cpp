// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTooltip (item/skill tooltip builder, Scaleform AS bridge).
// MS2-UNIT: ?\astooltip.cpp
// MS2-RANGE: 0x1409c5210-0x1409f00e0 .text$mn
// MS2-RANGE: 0x1400c13a0-0x1400c2000 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x1409ef8a0 ; unique
// MS2-PINS-END tplpin
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

extern CStringW FUN_14028de60(int nId);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);

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
void ASTooltip::FUN_1409c65a0()
{
    FUN_1407cbb20("enableUseDbClick", FUN_14028de60(0x762));
}
MS2_REPLACE_METHOD(0x1409C65A0, ASTooltip, FUN_1409c65a0, 66, 0xFCB30E07);

// @0x1409c65f0
void ASTooltip::FUN_1409c65f0(const CStringW& strText)
{
    FUN_1407cbb20("enableUseDbClick", strText);
}
MS2_REPLACE_METHOD(0x1409C65F0, ASTooltip, FUN_1409c65f0, 72, 0x638B88F9);

// @0x1409c6880
void ASTooltip::FUN_1409c6880()
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enablePuton", FUN_14028de60(0x751));
}
MS2_REPLACE_METHOD(0x1409C6880, ASTooltip, FUN_1409c6880, 85, 0xF4AF37A1);

// @0x1409c68e0
void ASTooltip::FUN_1409c68e0()
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enableCompareSwap", FUN_14028de60(0x765));
}
MS2_REPLACE_METHOD(0x1409C68E0, ASTooltip, FUN_1409c68e0, 85, 0xE798AF82);

// @0x1409c6940
void ASTooltip::FUN_1409c6940(const CStringW& strText)
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enableLClick", strText);
}
MS2_REPLACE_METHOD(0x1409C6940, ASTooltip, FUN_1409c6940, 91, 0x7BDAE921);

// @0x1409c69b0
void ASTooltip::FUN_1409c69b0(const CStringW& strTitle)
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enablePuton", strTitle);
}
MS2_REPLACE_METHOD(0x1409C69B0, ASTooltip, FUN_1409c69b0, 91, 0x3AB5F601);

// @0x1409c6c80
void ASTooltip::FUN_1409c6c80()
{
    FUN_1407cbbe0("closeButton", true);
}
MS2_REPLACE_METHOD(0x1409C6C80, ASTooltip, FUN_1409c6c80, 34, 0x29258324);

// @0x1409c6cb0
void ASTooltip::FUN_1409c6cb0(const CStringW& strText)
{
    FUN_1407cbb20(s_strText, strText);
}
MS2_REPLACE_METHOD(0x1409C6CB0, ASTooltip, FUN_1409c6cb0, 81, 0x1E6A3D31);

// @0x1409c6d10
void ASTooltip::FUN_1409c6d10(const CString& str)
{
    FUN_1407cba60(s_strText, str);
}
MS2_REPLACE_METHOD(0x1409C6D10, ASTooltip, FUN_1409c6d10, 81, 0xB4DE3543);

// @0x1409c6d70
void ASTooltip::FUN_1409c6d70(const CString& strClass)
{
    FUN_1407cba60("tooltip", strClass);
}
MS2_REPLACE_METHOD(0x1409C6D70, ASTooltip, FUN_1409c6d70, 72, 0xEDA57631);

// @0x1409c6dc0
void ASTooltip::FUN_1409c6dc0(int n)
{
    FUN_1409eb310(s_strTooltipAlign, n);
}
MS2_REPLACE_METHOD(0x1409C6DC0, ASTooltip, FUN_1409c6dc0, 49, 0x3D4B1FA2);

// @0x1409c6e00
void ASTooltip::FUN_1409c6e00(int n)
{
    FUN_1407cb9c0("onDelay", n);
}
MS2_REPLACE_METHOD(0x1409C6E00, ASTooltip, FUN_1409c6e00, 40, 0x4B5EE22C);

// @0x1409c6e30
void ASTooltip::FUN_1409c6e30(int n)
{
    FUN_1407cb9c0("offDelay", n);
}
MS2_REPLACE_METHOD(0x1409C6E30, ASTooltip, FUN_1409c6e30, 40, 0xB08E9A97);

// @0x1409c6e60
void ASTooltip::FUN_1409c6e60(int n)
{
    FUN_1407cb9c0("offsetX", n);
}
MS2_REPLACE_METHOD(0x1409C6E60, ASTooltip, FUN_1409c6e60, 40, 0xFF9581A7);

// @0x1409c6e90
void ASTooltip::FUN_1409c6e90(int n)
{
    FUN_1407cb9c0("offsetY", n);
}
MS2_REPLACE_METHOD(0x1409C6E90, ASTooltip, FUN_1409c6e90, 40, 0x0CC6F34F);

// @0x1409c6ec0
void ASTooltip::FUN_1409c6ec0(int n)
{
    FUN_1407cb9c0("maxWidth", n);
}
MS2_REPLACE_METHOD(0x1409C6EC0, ASTooltip, FUN_1409c6ec0, 40, 0xD65BBE56);

// @0x1409eb310
void ASObj::FUN_1409eb310(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
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
void ASTooltip::FUN_1409c7c10(CItem* pItem)
{
    FUN_1407cbb20(s_strItemName, pItem->FUN_140527b10());
}
MS2_REPLACE_METHOD(0x1409C7C10, ASTooltip, FUN_1409c7c10, 80, 0x3F6AE606);

// @0x1409c7c70
void ASTooltip::FUN_1409c7c70(CItem* pItem)
{
    FUN_1409adc90(s_strItemGrade, pItem->FUN_140526bd0());
}
MS2_REPLACE_METHOD(0x1409C7C70, ASTooltip, FUN_1409c7c70, 66, 0xFE5BD3AD);

// @0x1409c7f70
void ASTooltip::FUN_1409c7f70(CItem* pItem)
{
    FUN_1407cb9c0(s_strUgctag, pItem->FUN_140528840());
}
MS2_REPLACE_METHOD(0x1409C7F70, ASTooltip, FUN_1409c7f70, 66, 0xDD1978AD);

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

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409e25e0
bool ASTooltip::FUN_1409e25e0(CItem* pItem, unsigned n)
{
    if (FUN_1409e0d40(pItem) == 0)
        return false;
    FUN_1409cf010(pItem, n);
    return true;
}
MS2_REPLACE_METHOD(0x1409E25E0, ASTooltip, FUN_1409e25e0, 72, 0x15346D77);

// @0x1409e26b0
int ASTooltip::FUN_1409e26b0(const CStringW& strText)
{
    if (strText.IsEmpty())
        return 0;
    FUN_1409c6d70("export_common_tooltip_tooltipText");
    FUN_1409c6cb0(strText);
    FUN_1409c6e00(300);
    FUN_1409c6e30(60000);
    return 1;
}
MS2_REPLACE_METHOD(0x1409E26B0, ASTooltip, FUN_1409e26b0, 146, 0x067A651D);

struct Unk_CommandStrings { CStringW FUN_141811980(int, int); };
Unk_CommandStrings* FUN_1401a9d70();

// @0x1409d4350
void ASTooltip::FUN_1409d4350(CItemData* pData)
{
    if (pData == 0)
        return;
    FUN_1407cbbe0(s_strItemPiece, pData->FUN_14053d990());
}
MS2_REPLACE_METHOD(0x1409D4350, ASTooltip, FUN_1409d4350, 78, 0xFE2943FA);

// @0x1409d43b0
void ASTooltip::FUN_1409d43b0(CItem* pItem)
{
    FUN_1409d74a0(pItem->FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1409D43B0, ASTooltip, FUN_1409d43b0, 41, 0x6D4FFE0F);

// @0x1409d43e0
void ASTooltip::FUN_1409d43e0(CItem* pItem)
{
    if (pItem->FUN_140525640() != 0)
    {
        FUN_1409adc90(s_strItemPetRank, pItem->FUN_140526bd0());
        FUN_1407cb9c0(s_strDropShadowDisable, 1);
    }
}
MS2_REPLACE_METHOD(0x1409D43E0, ASTooltip, FUN_1409d43e0, 112, 0x67EE15C6);

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
void ASTooltip::FUN_1409d5530(unsigned nId)
{
    FUN_1407cbb20(s_strItemName, FUN_1401a9d70()->FUN_141811980(1, nId));
}
MS2_REPLACE_METHOD(0x1409D5530, ASTooltip, FUN_1409d5530, 93, 0xF4A248DA);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409d55a0
void ASTooltip::FUN_1409d55a0(CItem* pItem, int n)
{
    FUN_1409adc90(s_strItemGrade, n == 0 ? 1 : n);
}
MS2_REPLACE_METHOD(0x1409D55A0, ASTooltip, FUN_1409d55a0, 95, 0x6202B546);

MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);

// @0x1409d5160
void ASTooltip::FUN_1409d5160(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemPet, sp->FUN_14053cc40());
}
MS2_REPLACE_METHOD(0x1409D5160, ASTooltip, FUN_1409d5160, 139, 0x04E59FDE);

// @0x1409d5200
void ASTooltip::FUN_1409d5200(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemCash, sp->FUN_14053e130());
}
MS2_REPLACE_METHOD(0x1409D5200, ASTooltip, FUN_1409d5200, 139, 0xDAA972D2);

// @0x1409d52a0
void ASTooltip::FUN_1409d52a0(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemSkin, sp->FUN_14053cf90());
}
MS2_REPLACE_METHOD(0x1409D52A0, ASTooltip, FUN_1409d52a0, 139, 0xFD2B7855);

// @0x1409d5340
void ASTooltip::FUN_1409d5340(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cb9c0(s_strItemPcBang, sp->FUN_14053ce20() != 0);
}
MS2_REPLACE_METHOD(0x1409D5340, ASTooltip, FUN_1409d5340, 156, 0x2C1CCF54);

// @0x1409d53f0
void ASTooltip::FUN_1409d53f0(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemVIP, sp->FUN_14053d1f0());
}
MS2_REPLACE_METHOD(0x1409D53F0, ASTooltip, FUN_1409d53f0, 139, 0x2426DEF4);

// @0x1409d5490
void ASTooltip::FUN_1409d5490(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(s_strItemWedding, sp->FUN_14053d210());
}
MS2_REPLACE_METHOD(0x1409D5490, ASTooltip, FUN_1409d5490, 139, 0x00739E47);

short FUN_140626f20(int nItemId);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409d74a0
void ASTooltip::FUN_1409d74a0(int nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (!(sp == NULL))
    {
        if (sp->FUN_14053d840())
        {
            short sLevel = FUN_140626f20(sp->FUN_14053c510());
            if (sLevel == 0)
                return;
            FUN_1409c48f0("gemstoneLevel", sLevel);
        }
    }
}
MS2_REPLACE_METHOD(0x1409D74A0, ASTooltip, FUN_1409d74a0, 183, 0xB7CB9094);

// @0x1409d8c80
void ASTooltip::FUN_1409d8c80(const CStringW& str)
{
    FUN_1407cbb20(s_strItemEquip, str);
}
MS2_REPLACE_METHOD(0x1409D8C80, ASTooltip, FUN_1409d8c80, 81, 0xD3C1BF91);

// @0x1409d8ce0
void ASTooltip::FUN_1409d8ce0(CStringW str)
{
    FUN_1407cbb20("itemDamage", str);
}
MS2_REPLACE_METHOD(0x1409D8CE0, ASTooltip, FUN_1409d8ce0, 93, 0x134D71AB);

// @0x1409d8d50
void ASTooltip::FUN_1409d8d50(bool b)
{
    FUN_1407cbbe0(s_strItemPetSkin, b);
}
MS2_REPLACE_METHOD(0x1409D8D50, ASTooltip, FUN_1409d8d50, 50, 0x9E275AA4);

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
unsigned char FUN_1409b0350(Scaleform::GFx::Value* pValue);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);

// @0x1409c64c0
ASTooltip::ASTooltip(Unk_TooltipOwner* pOwner, int a1, int a2)
    : ASObj(a2), m_40((__int64)pOwner), m_48(a1)
{
}

// Sets the same member of the left and right comparison tooltips.
// @0x1409c6640
void ASTooltip::FUN_1409c6640(const CStringW& strLhs, const CStringW& strRhs)
{
    Scaleform::GFx::Value lhs = FUN_1422baa20("lhsTooltip");
    if (FUN_1409b0390(&lhs) == 0)
    {
        ASObj obj(lhs, 2);
        {
            CStringW strCopy(strLhs);
            obj.FUN_1407cbb20("enableUseDbClick", strCopy);
        }
    }
    else
        FUN_1407cbb20("enableUseDbClick", strLhs);
    Scaleform::GFx::Value rhs = FUN_1422baa20("rhsTooltip");
    if (FUN_1409b0390(&rhs) == 0)
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
    Scaleform::GFx::Value lhs = FUN_1422baa20("lhsTooltip");
    if (FUN_1409b0390(&lhs) == 0)
    {
        ASObj obj(lhs, 2);
        {
            CStringW strCopy(strLhs);
            obj.FUN_1407cbb20("enablePuton", strCopy);
        }
    }
    else
        FUN_1407cbb20("enablePuton", strLhs);
    Scaleform::GFx::Value rhs = FUN_1422baa20("rhsTooltip");
    if (FUN_1409b0390(&rhs) == 0)
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
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (FUN_1409b0390(&v) != 0 || FUN_1409b0350(&v) != 0)
    {
        ASArray arr(2);
        arr.FUN_1422bbfe0(strText);
        FUN_1409adbe0(strName, Scaleform::GFx::Value(arr.FUN_1422bb870()));
    }
    else
    {
        ASArray arr(v, 2);
        arr.FUN_1422bbfe0(strText);
    }
}
MS2_REPLACE_METHOD(0x1409C6EF0, ASTooltip, FUN_1409c6ef0, 355, 0xB1F3433B);

// @0x1409c7060
void ASTooltip::FUN_1409c7060(const CStringW& strLhs, const CStringW& strRhs)
{
    Scaleform::GFx::Value lhs = FUN_1422baa20("lhsTooltip");
    if (FUN_1409b0390(&lhs) == 0)
    {
        ASObj obj(lhs, 2);
        {
            CStringW strCopy(strLhs);
            obj.FUN_1407cbb20(s_strItemEquip, strCopy);
        }
    }
    else
        FUN_1407cbb20(s_strItemEquip, strLhs);
    Scaleform::GFx::Value rhs = FUN_1422baa20("rhsTooltip");
    if (FUN_1409b0390(&rhs) == 0)
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

extern CStringW FUN_14028b8e0(const CStringW& strKey);
static int s_bTextsLoaded;

// @0x1409e5480  loads the tooltip texts once
// MS2-FUNCTIONAL: frame/unwind layout differs (the exe keeps one temporary per string, 0x348 frame); same loads and stores
void FUN_1409e5480()
{
    if (s_bTextsLoaded == 0)
    {
        s_wsKindLabel[0] = FUN_14028de60(0xbf3);
        s_wsKindLabel[2] = FUN_14028de60(0xbf4);
        s_wsKindLabel[4] = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_kinds_merge_1step"));
        s_wsMerge = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_kinds_merge"));
        s_wsText0xbf5 = FUN_14028de60(0xbf5);
        s_wsText0x48d = FUN_14028de60(0x48d);
        s_wsText0xbf8 = FUN_14028de60(0xbf8);
        s_wsStatRowBest = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_stat_row_best"));
        s_wsNewline = L"\n";
        s_wsText0xbf6 = FUN_14028de60(0xbf6);
        s_wsText0xbf7 = FUN_14028de60(0xbf7);
        s_wsEnchantExp = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_enchant_exp"));
        s_wsWhiteFont = L"<font color='#ffffff'>{0}</font>";
        s_wsUnlimited = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_unlimited"));
        s_wsSetTitle = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_setitem_set_title"));
        s_wsSetNameRow = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_setitem_name_row"));
        s_wsSetStatRow = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_setitem_stat_row"));
        s_wsSetName = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_setitem_name"));
        s_wsUgcSetName = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_ugcmap_setitem_name"));
        s_wsUgcSetRow = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_ugcmap_setitem_row"));
        s_wsSocket = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket"));
        s_wsSocketByPet = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_by_pet"));
        s_wsSocketRowStat = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_row_stat"));
        s_wsSocketRowStatByPet = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_row_stat_by_pet"));
        s_wsSocketRowEmpty = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_row_empty"));
        s_wsSocketRowLock = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_row_lock"));
        s_wsSocketTransfer = FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_socket_transfer"));
        s_wsPetEvolutionPoint = FUN_14028b8e0(CStringW(L"s_pet_tooltip_evolution_point"));
        s_wsPetExp = FUN_14028b8e0(CStringW(L"s_pet_tooltip_exp"));
        s_bTextsLoaded = 1;
    }
}
// not hooked: writes the unit statics s_ws*/s_bTextsLoaded (DLL-local copies; the exe readers would see empty strings)

#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 1
#include "astooltip_p1.inl"
#endif
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 2
#include "astooltip_p2.inl"
#endif
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 3
#include "astooltip_p3.inl"
#endif
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 4
#include "astooltip_p4.inl"
#endif
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 5
#include "astooltip_p5.inl"
#endif
#if !defined(MS2_AT_SOLO) || MS2_AT_SOLO == 6
#include "astooltip_p6.inl"
#endif
