// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMsgBoxData / CMsgBoxDataItem: the data record of a message
// box and the AS object it fills for the movie. See uimessageboxdata.h.
// MS2-UNIT: client\ms2\uimessageboxdata.cpp
// MS2-RANGE: 0x1401174d0-0x140117620 .text$di
// MS2-RANGE: 0x141a034d0-0x141a08af0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??4?$MS2Ptr@VCMsgBoxDataItem@@@@QEAAAEAV0@AEBV0@@Z 0x141a07910 ; unique (fx18: CMsgBoxData::m_spItem = , not CItem's 0x140692c90)
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VValue@GFx@Scaleform@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a07af0 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VValue@GFx@Scaleform@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141a07b10 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VValue@GFx@Scaleform@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141a07b60 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VValue@GFx@Scaleform@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VValue@GFx@Scaleform@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@VValue@GFx@Scaleform@@@std@@@std@@@2@XZ 0x141a08610 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@XZ 0x141a07330 ; look-alike group (CItem/Unk_MsgCheck/Unk_MsgInput default ctors)
// MS2-PIN: ??8?$MS2Ptr@VCMsgBoxDataItem@@@@QEBA_NPEAVCMsgBoxDataItem@@@Z 0x141a07980 ; unique (fx18: not CItem's 0x1401c0050)
// MS2-PIN: ??4?$MS2Ptr@VCItem@@@@QEAAAEAV0@H@Z 0x141a07950 ; unique (p = NULL of ~CMsgBoxData, uimessagebox.cpp)
// MS2-PIN: ??R?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEBA_NHAEBVCMsgBoxData@@@Z 0x141a07c10 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimessageboxdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimessageboxdata.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// 0x141a07950 is MS2Ptr<CItem>::operator=(int) (Release; return *this), the `= NULL` of ~CMsgBoxData; it lands in
// this unit's range, so the instance is emitted here.
template MS2Ptr<CItem>& MS2Ptr<CItem>::operator=(int);

// ---- statics (.text$di) ----
// The sort type names of the shared statics header (without the skill / stun strings after them).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

extern Unk_MessageBoxStatic g_messageBoxState;                // 0x143af3df8
extern Unk_MsgPoint2 DAT_143b02320;                                    // the zero point both ctor fields start from

static CString s_strDialogOpen = "dialog_open";
static CString s_strSystemNoticeConfirm = "system_notice_confirm";
static CString s_strSystemNoticeError = "system_notice_error";

// "label" / "index": member names of the drop-down rows, initialised by uimessagebox.cpp.
extern CString DAT_143af3e28;
extern CString DAT_143af3e30;

// ---- unit-local declarations (names describe uses, not original class names) ----

// The check box / text input controls of the movie ("m_checkbox0", "m_textInput").
class Unk_MsgDisplay : public ASDisplayObject
{
public:
    int FUN_1422c1500();                                            // width
    int FUN_1422c1530();                                            // height
    void FUN_1422c0f60(float* pX, float* pY);                       // position
};
class Unk_MsgCheck : public ASDisplayObject
{
public:
    unsigned char FUN_1422ce0e0();                                  // checked
};
class Unk_MsgInput : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                                       // the text
};

// The AS object `obj` keys. Free functions of other units.
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);         // value is undefined
unsigned char FUN_1409b0350(Scaleform::GFx::Value* pValue);

CString FUN_14016a5c0(const char* psz, int n);
CStringW FUN_1401d0160(const wchar_t* szLeft, const CStringW& strRight);
CStringW FUN_1401d0080(const CStringW& strLeft, const CStringW& strRight);
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& nArg);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a1, const CStringW& a2);
CStringW FUN_14183e930(const CStringW& str, int nColor);
CString FUN_140513200(const char* szFormat, const unsigned int& nArg);
unsigned int FUN_140869420();                                       // now (ms)
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags);
void FUN_141415560(const CString& strName, ItemInfoSlot::CreateParam* pParam);
void FUN_141415600(const CString& strName);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
int FUN_14151f9c0();                                                // the modaless setting
class Unk_MsgPopup { public: int FUN_1422db730(); };
Unk_MsgPopup* FUN_14151fcb0(int nUiType);                           // a dialog by type
class Unk_MsgColors { public: int FUN_1405569f0(int nColor); };
Unk_MsgColors* FUN_140281980();

class Unk_MsgFeature { public: bool FUN_14036d570(int nId); bool FUN_14036d710(int nId); };
Unk_MsgFeature* FUN_140166410();
class Unk_MsgLocalizer { public: CStringW FUN_1422b0570(const CString& key); };
Unk_MsgLocalizer* FUN_14025e7a0();
class Unk_MsgOption { public: int* FUN_1402056b0(); char m_pad[0x58]; };
class Unk_MsgGlobals { public: char m_pad_0[0xdf30]; Unk_MsgOption m_dfOption30; Unk_MsgOption m_dfOption88; };
Unk_MsgGlobals* FUN_1401d3200();
class Unk_MsgPad { public: int FUN_140d8ee40(); };
Unk_MsgPad* FUN_140a58540();

// The skill-attribute record behind a buff icon (CPtred + 0xa8 bytes, then the icon path at +0xc0).
class Unk_MsgSkillAttr : public CPtred
{
public:
    char m_pad_18[0xa8];
    CString m_strIcon;                                              // +0xc0
    CString FUN_1401756c0();                                        // copy of the icon path
};
MS2_CHECK_OFFSET(Unk_MsgSkillAttr, m_strIcon, 0xc0);
class Unk_MsgSkillTable
{
public:
    MS2Ptr<Unk_MsgSkillAttr> FUN_140aafef0(int nSkillId, unsigned short nLevel);
};
Unk_MsgSkillTable* FUN_1401958b0();

class Unk_ClubBuffData : public CPtred
{
public:
    int m_pad_18; int m_pad_1c; int m_pad_20; int m_pad_24;
    int m_nBuffId;                                                  // +0x28
    int m_nLevel;                                                   // +0x2c
};
class Unk_ClubBuffTable
{
public:
    void FUN_140211990(ATL::CAtlArray<MS2Ptr<Unk_ClubBuffData>>& out);
};
Unk_ClubBuffTable* FUN_140b1a4e0();
class Unk_MsgStrings
{
public:
    CStringW FUN_141812290(int nBuffId, unsigned short nLevel, CString strKey);
};
Unk_MsgStrings* FUN_1401a9d70();


// The AS array push helpers (an AS array is built from objects and strings), and the int-valued AS object setter.
class Unk_MsgASArray : public ASArray
{
public:
    void FUN_1422bbf00(const ASObj& obj);                           // push an object
    void FUN_1422bbf70(const char* szValue);                        // push a string
};
class Unk_MsgASObj : public ASObj
{
public:
    void FUN_141a07250(const char* szName, int n);                  // set an int member through an ASData
};

CString FUN_141a066e0(int nType);                                   // the AS box type name
CString FUN_141a06e80(int nTextType);                               // the AS text input type name
CString FUN_141a06ff0(int nSound);                                  // the sound event name
CString FUN_1407186a0(const CStringW& str);
bool FUN_1407183f0(const CStringW& str);

// @0x141a034d0
// MS2-FUNCTIONAL: large ASObj filler; temporaries and sequencing differ from the exe (70 bytes longer)
int CMsgBoxData::FUN_141a034d0(ASObj& obj)
{
    obj.FUN_1407cba60("boxType", FUN_14016a5c0(FUN_141a066e0(m_nType), 0));
    ((Unk_MsgASObj&)obj).FUN_141a07250("sID", m_nId);
    obj.FUN_1407cbb20("msg", m_strMsg);
    obj.FUN_1407cbb20("msg2", m_strMsg2);
    obj.FUN_1407cbb20("btnLabel0", m_strBtn0);
    obj.FUN_1407cbb20("btnLabel1", m_strBtn1);
    obj.FUN_1407cbb20("btnLabel2", m_strBtn2);
    obj.FUN_1407cbb20("title", m_strTitle);
    obj.FUN_1407cbbe0("modaless", m_bModaless);
    int nShowModaless = 1;
    if (FUN_14151f9c0() == 0 || !m_bModaless)
        nShowModaless = 0;
    obj.FUN_1407cb9c0("showModaless", nShowModaless);
    obj.FUN_1407cbb20("strikeStr", m_strStrike);
    if (m_nAlign != 4)
        obj.FUN_1407cba60("textAlign", m_strAlign[m_nAlign]);
    if (FUN_141a03070() && g_messageBoxState.m_bSaved != 0)
    {
        ASObj posData(2);
        posData.FUN_1409c4a30("posX", g_messageBoxState.m_pos.x);
        posData.FUN_1409c4a30("posY", g_messageBoxState.m_pos.y);
        posData.FUN_1409c4a30("stageWidth", g_messageBoxState.m_stage.x);
        posData.FUN_1409c4a30("stageHeight", g_messageBoxState.m_stage.y);
        obj.FUN_1409adbe0("modalessPosData", posData.FUN_1422bb870());
    }
    if (m_strExtra.GetLength() > 0)
        obj.FUN_1407cbb20("extra", m_strExtra);
    if ((m_nFlags & 4) != 0)
    {
        if (m_timer.m_nArmed != -1)
        {
            int nRemain = m_timer.m_timer.FUN_140868ab0();
            m_timer.m_nSec = nRemain / 1000;
            m_timer.m_nArmed = -1;
            m_timer.m_timer.FUN_140868820();
        }
        obj.FUN_1407cb9c0("time", m_timer.m_nSec);
        if (m_timer.m_nShowFormat != 0)
        {
            CStringW strTail = FUN_1401d0160(L"\n", FUN_1401ceea0(m_timer.m_strFormat, m_timer.m_nSec));
            obj.FUN_1407cbb20("msg", FUN_1401d0080(m_strMsg, strTail));
        }
    }
    if ((m_nFlags & 2) != 0)
    {
        obj.FUN_1407cba60("textType", FUN_14016a5c0(FUN_141a06e80(m_input.m_nType), 0));
        obj.FUN_1407cbb20("inputDefault", m_input.m_strDefault);
        obj.FUN_1407cb9c0("inputMaxChars", m_input.m_nMaxChars);
        obj.FUN_1407cb9c0("inputTextShowLimit", m_input.m_nShowLimit);
        obj.FUN_1407cb9c0("inputMaxLine", m_input.m_nMaxLine);
        obj.FUN_1407cbb20("maxLineMsg", m_input.m_strMaxLineMsg);
        obj.FUN_1407cbb20("textCountMsg", m_input.m_strCountMsg);
    }
    if ((m_nFlags & 1) != 0 && m_spItem.get() != 0)
    {
        CString strBagId("MsgBoxData");
        strBagId.Format("MsgBoxData_%d", m_nId);
        FUN_141415600(strBagId);
        FUN_141415450(strBagId, m_spItem->m_spItem, 0, m_spItem->m_48, 0);
        m_spItem->m_strBindId = strBagId;
        obj.FUN_1407cba60("bagId", m_spItem->m_strBindId);
        obj.FUN_1407cbb20("itemName", m_spItem->m_strName);
        if (m_spItem->m_nCount != -1)
        {
            obj.FUN_1407cb9c0("itemCount", m_spItem->m_nCount);
            obj.FUN_1407cb9c0("itemMax", m_spItem->m_nMax);
            obj.FUN_1407cb9c0("itemUnitCount", m_spItem->m_nUnitCount);
            if (m_spItem->m_nPrice != -1)
            {
                obj.FUN_1409c1180("itemTotalPrice", (__int64)(m_spItem->m_nPrice * m_spItem->m_nCount));
                obj.FUN_1407cb9c0("itemPrice", m_spItem->m_nPrice);
            }
        }
    }
    if ((m_nFlags & 0x20) != 0 && m_spItem2.get() != 0)
    {
        CString strBagId("MsgBoxData2");
        strBagId.Format("MsgBoxData2_%d", m_nId);
        FUN_141415600(strBagId);
        FUN_141415450(strBagId, m_spItem2->m_spItem, 0, m_spItem2->m_48, 0);
        m_spItem2->m_strBindId = strBagId;
        obj.FUN_1407cba60("bagId2", m_spItem2->m_strBindId);
        obj.FUN_1407cbb20("itemName2", m_spItem2->m_strName);
        if (m_spItem2->m_nCount != -1)
        {
            obj.FUN_1407cb9c0("itemCount2", m_spItem2->m_nCount);
            obj.FUN_1407cb9c0("itemMax2", m_spItem2->m_nMax);
            obj.FUN_1407cb9c0("itemUnitCount2", m_spItem2->m_nUnitCount);
            if (m_spItem2->m_nPrice != -1)
            {
                obj.FUN_1409c1180("itemTotalPrice2", (__int64)(m_spItem2->m_nPrice * m_spItem2->m_nCount));
                obj.FUN_1407cb9c0("itemPrice2", m_spItem2->m_nPrice);
            }
        }
    }
    if ((m_nFlags & 8) != 0)
    {
        if (!m_checks.m_strLabel0.IsEmpty())
            obj.FUN_1407cbb20("checkbox0", m_checks.m_strLabel0);
        if (!m_checks.m_strLabel1.IsEmpty())
            obj.FUN_1407cbb20("checkbox1", m_checks.m_strLabel1);
        if (!m_checks.m_bEnabled0)
            obj.FUN_1407cbbe0("check0Enabled", m_checks.m_bEnabled0);
        if (!m_checks.m_bEnabled1)
            obj.FUN_1407cbbe0("check1Enabled", m_checks.m_bEnabled1);
        obj.FUN_1407cbbe0("check0Selected", m_checks.m_bSelected0);
        obj.FUN_1407cbbe0("check1Selected", m_checks.m_bSelected1);
        obj.FUN_1407cbbe0("mustCheck", m_checks.m_bMust);
    }
    if ((m_nFlags & 0x10) != 0)
    {
        obj.FUN_1407cb9c0("width", m_nWidth);
        obj.FUN_1407cb9c0("height", m_nHeight);
    }
    if ((m_nFlags & 0x40) != 0 && !m_strLinkTitle.IsEmpty())
    {
        obj.FUN_1407cbb20("hyperLinkTitle", m_strLinkTitle);
        obj.FUN_1407cba60("hyperLinkUrl", m_strLinkUrl);
    }
    if (FUN_140166410()->FUN_14036d710(0x61))
        obj.FUN_1407cbbe0("rbmerat", true);
    if (!m_values.empty())
    {
        for (std::map<CString, Scaleform::GFx::Value>::iterator it = m_values.begin(); it != m_values.end(); it++)
            obj.FUN_1409adbe0(it->first, it->second);
    }
    FUN_141a051e0(obj);
    return 1;
}

// @0x141a04900
int CMsgBoxData::FUN_141a04900()
{
    if ((m_nFlags & 4) != 0)
    {
        if (m_timer.m_nArmed > 0)
        {
            int nSec = m_timer.m_timer.FUN_140868ab0() / 1000;
            return (nSec > 0 && m_timer.m_timer.FUN_140868c00() == 0) ? 1 : 0;
        }
        if (m_timer.m_nSec < 0)
            return 0;
    }
    return 1;
}

// @0x141a049a0
int CMsgBoxData::FUN_141a049a0() const
{
    if ((m_nFlags & 4) != 0)
        return 1;
    return 0;
}

// @0x141a049d0
int CMsgBoxData::FUN_141a049d0() const
{
    if (FUN_141a049a0())
    {
        unsigned int nEnd = m_timer.m_nSec * 1000 + m_timer.m_nMs;
        unsigned int nNow = FUN_140869420();
        if (nEnd <= nNow)
            return 1;
    }
    return 0;
}

// @0x141a04a30
// MS2-FUNCTIONAL: return-value handling differs (exe returns the first callee byte)
#pragma warning(push)
#pragma warning(disable : 4715)   // the false path returns the first call's (zero) result
bool CMsgBoxData::FUN_141a04a30()
{
    if (FUN_141a01480())
        return FUN_141a014d0(1, &m_movie);
}
#pragma warning(pop)

// @0x141a04a80
const Unk_MsgBoxTimer& CMsgBoxData::FUN_141a04a80() const
{
    return m_timer;
}

// @0x141a04aa0
// MS2-FUNCTIONAL: cl adds a /GS cookie (frame 0x138 vs 0x128) that the exe lacks; same call sequence
bool CMsgBoxData::FUN_141a04aa0()
{
    if (FUN_1409b0390(&m_movie))
    {
        MS2_ASSERT_AT(0x3c4, 0);
        return false;
    }
    ASMovieClip root(m_movie, 2);
    MS2Ptr<Unk_MsgCheck> check;
    if (root.FUN_140c12010("m_checkbox0", check).get() == 0)
        return false;
    return check->FUN_1422ce0e0();
}

// @0x141a04c20
// MS2-FUNCTIONAL: cl adds a /GS cookie (frame 0x138 vs 0x128) that the exe lacks; same call sequence
bool CMsgBoxData::FUN_141a04c20()
{
    if (FUN_1409b0390(&m_movie))
    {
        MS2_ASSERT_AT(0x3d6, 0);
        return false;
    }
    ASMovieClip root(m_movie, 2);
    MS2Ptr<Unk_MsgCheck> check;
    if (root.FUN_140c12010("m_checkbox1", check).get() == 0)
        return false;
    return check->FUN_1422ce0e0();
}

// @0x141a04da0
// MS2-FUNCTIONAL: cl adds a /GS cookie that the exe lacks; same call sequence
CStringW CMsgBoxData::FUN_141a04da0()
{
    if (FUN_1409b0390(&m_movie))
    {
        MS2_ASSERT_AT(1000, 0);
        return CStringW(L"");
    }
    ASMovieClip root(m_movie, 2);
    MS2Ptr<Unk_MsgInput> input;
    if (root.FUN_140bbe940("m_textInput", input).get() == 0)
        return CStringW(L"");
    return input->FUN_1422e0b00();
}

// @0x141a04f80
// MS2-FUNCTIONAL: MS2Ptr by-value argument temp layout differs
void FUN_141a04f80(MS2Ptr<Unk_MsgDisplay> spBox)
{
    if (FUN_1409b0350(&spBox->FUN_1422bb870()) == 0)
    {
        g_messageBoxState.m_stage.x = (float)spBox->FUN_1422c1500();
        g_messageBoxState.m_stage.y = (float)spBox->FUN_1422c1530();
        spBox->FUN_1422c0f60(&g_messageBoxState.m_pos.x, &g_messageBoxState.m_pos.y);
        g_messageBoxState.m_bSaved = 1;
    }
}

// @0x141a05070
// MS2-FUNCTIONAL: call sequence differs slightly
int FUN_141a05070()
{
    Unk_MsgPopup* pPopup = FUN_14151fcb0(0x4e48);
    if (pPopup == 0)
        return 2;
    return pPopup->FUN_1422db730();
}

// @0x141a050b0
// MS2-FUNCTIONAL: temporary layout differs
void CMsgBoxData::FUN_141a050b0()
{
    int nSound = 3;
    switch (m_nType)
    {
    case 0:
        nSound = 2;
        FUN_141a01800(3);
        break;
    case 1:
    case 0x14:
    case 0x18:
        FUN_141a01800(1);
        break;
    default:
        FUN_141a01800(3);
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xf:
    case 0x12:
    case 0x15:
    case 0x16:
    case 0x19:
    case 0x1a:
        FUN_141a01800(2);
        break;
    case 0x17:
        FUN_141a01800(5);
    }
    m_strSound = FUN_141a06ff0(nSound);
}

// @0x141a051e0
// MS2-FUNCTIONAL: temporary layout differs
void CMsgBoxData::FUN_141a051e0(ASObj& obj)
{
    switch (m_nType)
    {
    case 6:
        FUN_141a06250(obj);
        break;
    case 0xf:
        FUN_141a063e0(obj);
        break;
    case 0x14:
        FUN_141a05380(obj);
        break;
    case 0x15:
        FUN_141a05470(obj);
        break;
    case 0x16:
        FUN_141a05540(obj);
        break;
    case 0x1b:
    case 0x1c:
    case 0x1f:
        FUN_141a056f0(obj);
        break;
    case 0x1d:
        FUN_141a05730(obj);
        break;
    case 0x1e:
        FUN_141a058c0(obj);
        break;
    case 0x20:
    case 0x24:
    case 0x26:
        FUN_141a05770(obj);
        break;
    case 0x21:
        FUN_141a05930(obj);
        break;
    case 0x23:
        FUN_141a05bd0(obj);
        break;
    case 0x25:
        FUN_141a05f30(obj);
        FUN_141a05770(obj);
    }
}

// @0x141a05380
void CMsgBoxData::FUN_141a05380(ASObj& obj)
{
    obj.FUN_1407cbb20("charName", m_strCharName);
    obj.FUN_1407cbb20("charDetail", m_strCharDetail);
    obj.FUN_1407cbb20("profile", m_strProfile);
}

// @0x141a05470
// MS2-FUNCTIONAL: temporary layout differs
void CMsgBoxData::FUN_141a05470(ASObj& obj)
{
    CStringW strGroupName = FUN_141a02fd0(0, CStringW());
    obj.FUN_1407cb9c0("alpha", FUN_141a02e50(1, 0));
    obj.FUN_1407cbb20("groupName", strGroupName);
}

// @0x141a05540
// MS2-FUNCTIONAL: temporary layout differs
void CMsgBoxData::FUN_141a05540(ASObj& obj)
{
    if (!m_choices.m_list.IsEmpty())
    {
        ASArray list(2);
        POSITION pos = m_choices.m_list.GetHeadPosition();
        while (pos != 0)
        {
            ASObj row(2);
            row.FUN_1407cbb20(DAT_143af3e28, m_choices.m_list.GetAt(pos));
            list.FUN_1422bc050(row.FUN_1422bb870());
            m_choices.m_list.GetNext(pos);
        }
        obj.FUN_1409adbe0("dropdownList", list.FUN_1422bb870());
    }
}

// @0x141a056f0
void CMsgBoxData::FUN_141a056f0(ASObj& obj)
{
    obj.FUN_1407cbbe0("agreement", m_bAgreement);
}

// @0x141a05730
void CMsgBoxData::FUN_141a05730(ASObj& obj)
{
    obj.FUN_1407cb9c0("retraction", m_nRetraction);
}

// @0x141a05770
void CMsgBoxData::FUN_141a05770(ASObj& obj)
{
    MS2Ptr<Unk_MsgSkillAttr> spAttr = FUN_1401958b0()->FUN_140aafef0(m_buff.m_nId, m_buff.m_nLevel);
    if (spAttr.get() != 0)
    {
        obj.FUN_1407cbb20("buffDesc", m_buff.m_strDesc);
        obj.FUN_1407cba60("buffIcon", spAttr->m_strIcon);
        obj.FUN_1407cbb20("extraBuffDesc", m_buff.m_strExtra);
    }
}

// @0x141a058c0
void CMsgBoxData::FUN_141a058c0(ASObj& obj)
{
    obj.FUN_1407cb9c0("ugcAttention", *FUN_1401d3200()->m_dfOption30.FUN_1402056b0());
    obj.FUN_1407cb9c0("ugcInfringementCenter", *FUN_1401d3200()->m_dfOption88.FUN_1402056b0());
}

// @0x141a05930
void CMsgBoxData::FUN_141a05930(ASObj& obj)
{
    CStringW strEnable = FUN_14025e7a0()->FUN_1422b0570("$s_itemlock_msgbox_lock_desc_enable");
    if (FUN_140166410()->FUN_14036d570(0x38) == true)
        strEnable += FUN_14025e7a0()->FUN_1422b0570("$s_itemlock_msgbox_lock_desc_enable_repacking");
    CStringW strDisable = FUN_14025e7a0()->FUN_1422b0570("$s_itemlock_msgbox_lock_desc_disable");
    if (FUN_140166410()->FUN_14036d570(0x2e) == true)
        strDisable += FUN_14025e7a0()->FUN_1422b0570("$s_itemlock_msgbox_lock_desc_disable_socket");
    strDisable += FUN_14025e7a0()->FUN_1422b0570("$s_itemlock_msgbox_lock_desc_disable_remakeoption");
    CStringW strDesc = FUN_140656190(L"{0}\n\n{1}", strEnable, strDisable);
    obj.FUN_1407cbb20("itemLockConfirmDesc", strDesc);
}

// @0x141a05bd0
// MS2-FUNCTIONAL: temporary layout differs
void CMsgBoxData::FUN_141a05bd0(ASObj& obj)
{
    ATL::CAtlArray<ItemEntity>& items = m_reqItems.m_items;
    ASArray list(2);
    for (size_t i = 0; i < items.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem(new CItem);
        int nRank = items[i].vfunc_o18_1();
        if (spItem->FUN_140523c40(items[i].m_itemId, nRank, 0))
        {
            spItem->FUN_140526c70(items[i].m_count);
            CString strBind;
            strBind.Format("MsgBoxRequieData_%d_%d", m_nId, i);
            ItemInfoSlot::CreateParam param;
            param.m_spItem = spItem;
            param.m_strCount = FUN_140513200("{0}", items[i].m_count);
            FUN_141415600(strBind);
            FUN_141415560(strBind, &param);
            ASObj entry(2);
            entry.FUN_1407cba60("binding", strBind);
            entry.FUN_1409c0d20("itemCount", items[i].m_count);
            ((Unk_MsgASArray&)list).FUN_1422bbf00(entry);
            m_reqItems.m_binds.Add(strBind);
        }
    }
    obj.FUN_1409eb1d0("requireItems", list);
}

// @0x141a05f30
void CMsgBoxData::FUN_141a05f30(ASObj& obj)
{
    ATL::CAtlArray<MS2Ptr<Unk_ClubBuffData>> buffs;
    FUN_140b1a4e0()->FUN_140211990(buffs);
    ASArray list(2);
    for (size_t i = 0; i < buffs.GetCount(); i++)
    {
        ASObj row(2);
        unsigned int nBuffId = buffs[i]->m_nBuffId;
        unsigned short nLevel = buffs[i]->m_nLevel;
        CStringW strName = FUN_1401a9d70()->FUN_141812290(nBuffId, nLevel, CString("name"));
        MS2Ptr<Unk_MsgSkillAttr> spAttr = FUN_1401958b0()->FUN_140aafef0(nBuffId, nLevel);
        if (spAttr.get() != 0)
        {
            row.FUN_1409c0d20("effectID", nBuffId);
            row.FUN_1409c48f0("level", nLevel);
            row.FUN_1407cba60("buffIcon", spAttr->FUN_1401756c0());
            row.FUN_1407cbb20(DAT_143af3e28, strName);
            list.FUN_1422bc050(row.FUN_1422bb870());
        }
    }
    obj.FUN_1409adbe0("dropdownList", list.FUN_1422bb870());
}

// @0x141a06250
void CMsgBoxData::FUN_141a06250(ASObj& obj)
{
    if (!m_args.IsEmpty())
        obj.FUN_1407cbb20(DAT_143af3e30, m_args[0]);
    ASArray list(2);
    ((Unk_MsgASArray&)list).FUN_1422bbf70("$s_gameoption_input_select_keyboard");
    if (FUN_140166410()->FUN_14036d570(0xb5) == true)
    {
        int nPad = FUN_140a58540()->FUN_140d8ee40();
        if (nPad == 1)
            ((Unk_MsgASArray&)list).FUN_1422bbf70("$s_gameoption_input_select_xbox");
        else if (nPad == 2)
            ((Unk_MsgASArray&)list).FUN_1422bbf70("$s_gameoption_input_select_ps");
        else if (nPad == 3)
            ((Unk_MsgASArray&)list).FUN_1422bbf70("$s_gameoption_input_select_steam");
    }
    obj.FUN_1409adbe0("inputList", list.FUN_1422bb870());
}

// @0x141a063e0
void CMsgBoxData::FUN_141a063e0(ASObj& obj)
{
    CStringW strLabel1 = m_args[0];
    CStringW strLabel2 = m_args[1];
    obj.FUN_1407cbb20("label1", strLabel1);
    obj.FUN_1407cbb20("label2", strLabel2);
}

// @0x141a064e0
// MS2-FUNCTIONAL: member init / temporaries differ
CMsgBoxDataItem::CMsgBoxDataItem()
{
    m_nCount = -1;
    m_nMax = -1;
    m_nPrice = -1;
    m_nUnitCount = 1;
    m_48 = 0;
}

// @0x141a06590
CMsgBoxDataItem::~CMsgBoxDataItem()
{
    if (!m_strBindId.IsEmpty())
        FUN_141415600(m_strBindId);
}

// @0x141a06630
// MS2-FUNCTIONAL: temporary layout differs
void CMsgBoxDataItem::FUN_141a06630(const CStringW& strName, bool bColor, int nColor)
{
    m_strName = strName;
    if (bColor)
        m_strName = FUN_14183e930(strName, FUN_140281980()->FUN_1405569f0(nColor));
}

// @0x141a066e0
// MS2-FUNCTIONAL: large string builder; temporaries differ
CString FUN_141a066e0(int nType)
{
    switch (nType)
    {
    case 0: return CString("ok");
    case 1: return CString("ok");
    case 2: return CString("ok_title");
    case 3: return CString("three_button");
    case 4: return CString("three_button_title");
    case 5: return CString("input");
    case 6: return CString("input_reset");
    case 7: return CString("input_meso");
    case 8: return CString("input_meso_merat");
    case 9: return CString("input_meso");
    case 10: return CString("input_showerror");
    case 0xb: return CString("input_textarea");
    case 0xc: return CString("input_apartment");
    case 0xd: return CString("input_item");
    case 0xe: return CString("input_checkbox");
    case 0xf: return CString("input_multi");
    case 0x10: return CString("scrollText");
    case 0x11: return CString("itemNotify");
    case 0x12: return CString("shopTrade");
    case 0x13: return CString("maintenance");
    case 0x14: return CString("profile_ok");
    case 0x15: return CString("groupEdit");
    case 0x16: return CString("groupList");
    case 0x17: return CString("imageYesNo");
    case 0x18: return CString("vertical");
    case 0x19: return CString("checkBox");
    case 0x1a: return CString("checkbox_slot");
    case 0x1b: return CString("terms");
    case 0x1c: return CString("terms_coupon");
    case 0x1d: return CString("market_retract");
    case 0x1e: return CString("ugcterms");
    case 0x1f: return CString("simple_terms");
    case 0x20: return CString("buffNotify");
    case 0x21: return CString("itemlock_confirm");
    case 0x22: return CString("itemlock_notify");
    case 0x23: return CString("itemCrafting");
    case 0x24: return CString("buffNotify_autoAction");
    case 0x25: return CString("clubbuff");
    case 0x26: return CString("buffNotify_inputBox");
    case 0x27: return CString("ugcevent");
    case 0x28: return CString("monologue");
    case 0x29: return CString("multiOpenBox");
    case 0x2a: return CString("two_slot");
    default: return CString("ok");
    }
}

// @0x141a06e80
CString FUN_141a06e80(int nTextType)
{
    switch (nTextType)
    {
    case 0: return CString("text");
    case 1: return CString("number");
    case 2: return CString("charname");
    case 3: return CString("housename");
    case 4: return CString("maidname");
    case 5: return CString("numberText");
    default: return CString("text");
    }
}

#ifndef MS2_HOOK_DLL
// @0x141a06ff0
// MS2-FUNCTIONAL: temporary layout differs
CString FUN_141a06ff0(int nSound)
{
    if (nSound == 1)
        return s_strDialogOpen;
    if (nSound == 2)
        return s_strSystemNoticeError;
    if (nSound == 3)
        return s_strSystemNoticeConfirm;
    return CString((const wchar_t*)L"");
}
#endif

// @0x141a07140
// MS2-FUNCTIONAL: temporary layout differs
bool CMsgBoxData::FUN_141a07140(unsigned int nIndex, CString& strOut) const
{
    size_t nCount = m_args.GetCount();
    if (nIndex < nCount)
        strOut = FUN_1407186a0(m_args[nIndex]);
    return nIndex < nCount;
}

// @0x141a071e0
// MS2-FUNCTIONAL: temporary layout differs
bool CMsgBoxData::FUN_141a071e0(unsigned int nIndex, bool& bOut) const
{
    size_t nCount = m_args.GetCount();
    if (nIndex < nCount)
        bOut = FUN_1407183f0(m_args[nIndex]);
    return nIndex < nCount;
}

// @0x141a07250
void Unk_MsgASObj::FUN_141a07250(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x141a07430
Unk_MsgBoxChecks::Unk_MsgBoxChecks()
{
    m_bEnabled0 = true;
    m_bEnabled1 = true;
    m_bSelected0 = true;
    m_bSelected1 = true;
    m_bMust = false;
}

// @0x141a07490
Unk_MsgBoxChoices::Unk_MsgBoxChoices()
    : m_strDefault(L"")
    , m_list(10)
{
}

// @0x141a074d0
// MS2-FUNCTIONAL: EH state layout differs
Unk_MsgBoxInput::Unk_MsgBoxInput()
    : m_strMaxLineMsg(L"")
    , m_strCountMsg(L"")
{
    m_nType = 0;
    m_nMaxChars = 0x14;
    m_nMaxLine = 0;
    m_nShowLimit = 0;
}

// @0x141a07570
Unk_MessageBoxStatic::Unk_MessageBoxStatic()
{
    m_pos = DAT_143b02320;
    m_stage = DAT_143b02320;
    m_bSaved = 0;
}

// @0x141a075b0
Unk_MsgBoxItems::Unk_MsgBoxItems()
{
}

// @0x141a075f0
// MS2-FUNCTIONAL: EH state layout differs
Unk_MsgBoxTimer::Unk_MsgBoxTimer()
{
    m_nSec = -1;
    m_nMs = 0;
    m_nShowFormat = 0;
    m_nButton = 0;
    m_nArmed = m_nSec;
}

// @0x141a07730
Unk_MsgBoxChecks::~Unk_MsgBoxChecks()
{
}

// @0x141a07760
Unk_MsgBoxChoices::~Unk_MsgBoxChoices()
{
}

// @0x141a07790
Unk_MsgBoxInput::~Unk_MsgBoxInput()
{
}

// @0x141a077e0
Unk_MsgBoxItems::~Unk_MsgBoxItems()
{
}

// @0x141a07810
Unk_MsgBoxTimer::~Unk_MsgBoxTimer()
{
}

// @0x141a07850
template <> inline Delegate<bool(int, const CMsgBoxData&)>& Delegate<bool(int, const CMsgBoxData&)>::operator=(const Delegate& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (!o.m_pImpl)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}

// COMDAT glue of the CMsgBoxData members at 0x141a00db0-0x141a034d0 (map of extra values, item array copy, callback): the stand-in below pairs it.
template <class R> R ThrowInvalidCall();    // <bool> 0x1405625e0 (itemdatatable.cpp); the callback's operator() 0x141a07c10 null-checks first
template <> inline bool Delegate<bool(int, const CMsgBoxData&)>::operator()(int a1, const CMsgBoxData& a2) const { if (m_pImpl == 0) ThrowInvalidCall<bool>(); return m_pImpl->Invoke(a1, a2); }
void Unk_MsgBoxGlueAnchor(CMsgBoxData* pData, Delegate<bool(int, const CMsgBoxData&)>& cbDst,
                          const Delegate<bool(int, const CMsgBoxData&)>& cbSrc, ATL::CAtlArray<ItemEntity>& dst,
                          const ATL::CAtlArray<ItemEntity>& src)
{
    std::map<CString, Scaleform::GFx::Value> values;
    MS2Ptr<CMsgBoxDataItem> spItem, spItem2;   // m_spItem / m_spItem2 of the setters 0x141a01e60 / 0x141a02220
    spItem == (CMsgBoxDataItem*)0;
    cbDst = cbSrc, spItem = spItem2;
    cbDst(1, *pData);
    dst.Copy(src);
    delete pData;
}

// 0x141a01170 (outside this unit's range): defining it here emits the vftable and the scalar deleting destructor
// (0x141a07ca0) in this unit's COMDAT tail.
CMsgBoxData::~CMsgBoxData()
{
}

MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x141A034D0, CMsgBoxData, FUN_141a034d0, 5147, 0x5C72EDD0);
MS2_REPLACE_METHOD(0x141A04900, CMsgBoxData, FUN_141a04900, 154, 0x64CD6E62);
MS2_REPLACE_METHOD(0x141A049A0, CMsgBoxData, FUN_141a049a0, 33, 0x89107F8D);
MS2_REPLACE_METHOD(0x141A049D0, CMsgBoxData, FUN_141a049d0, 86, 0x2C7D803C);
MS2_REPLACE_METHOD(0x141A04A30, CMsgBoxData, FUN_141a04a30, 63, 0x2C84B9F2);
MS2_REPLACE_METHOD(0x141A04A80, CMsgBoxData, FUN_141a04a80, 17, 0x60BBC863);
MS2_REPLACE_METHOD(0x141A04AA0, CMsgBoxData, FUN_141a04aa0, 374, 0xD9CE5F6D);
MS2_REPLACE_METHOD(0x141A04C20, CMsgBoxData, FUN_141a04c20, 374, 0xCBD40F82);
MS2_REPLACE_METHOD(0x141A04DA0, CMsgBoxData, FUN_141a04da0, 473, 0x68010C21);
MS2_REPLACE_METHOD(0x141A050B0, CMsgBoxData, FUN_141a050b0, 239, 0xC461D7FD);
MS2_REPLACE_METHOD(0x141A051E0, CMsgBoxData, FUN_141a051e0, 317, 0x8B701FF3);
MS2_REPLACE_METHOD(0x141A05380, CMsgBoxData, FUN_141a05380, 223, 0x41624052);
MS2_REPLACE_METHOD(0x141A05470, CMsgBoxData, FUN_141a05470, 199, 0xC97B9BBC);
MS2_REPLACE_METHOD(0x141A05540, CMsgBoxData, FUN_141a05540, 415, 0xD1D45854);
MS2_REPLACE_METHOD(0x141A056F0, CMsgBoxData, FUN_141a056f0, 49, 0x2753803B);
MS2_REPLACE_METHOD(0x141A05730, CMsgBoxData, FUN_141a05730, 48, 0x4B92E680);
MS2_REPLACE_METHOD(0x141A05770, CMsgBoxData, FUN_141a05770, 320, 0x04D3E35E);
MS2_REPLACE_METHOD(0x141A058C0, CMsgBoxData, FUN_141a058c0, 97, 0x9877B99C);
MS2_REPLACE_METHOD(0x141A05930, CMsgBoxData, FUN_141a05930, 653, 0x5806077E);
MS2_REPLACE_METHOD(0x141A05BD0, CMsgBoxData, FUN_141a05bd0, 849, 0xE5ECF5D2);
MS2_REPLACE_METHOD(0x141A05F30, CMsgBoxData, FUN_141a05f30, 784, 0x0A52D0DA);
MS2_REPLACE_METHOD(0x141A06250, CMsgBoxData, FUN_141a06250, 379, 0x767DA9E5);
MS2_REPLACE_METHOD(0x141A063E0, CMsgBoxData, FUN_141a063e0, 245, 0xCDB086A7);
MS2_REPLACE_METHOD(0x141A07140, CMsgBoxData, FUN_141a07140, 153, 0x45E471F0);
MS2_REPLACE_METHOD(0x141A071E0, CMsgBoxData, FUN_141a071e0, 103, 0xC313FF72);
MS2_REPLACE_METHOD(0x141A06630, CMsgBoxDataItem, FUN_141a06630, 161, 0x524A9354);
