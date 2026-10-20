// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMsgBoxData: the ctor/dtor and the builder setters and
// getters of the message box data record (layout in client\ms2\uimessageboxdata.h). Split from uimessagebox.cpp's range
// (the exe has no __FILE__ for this part; it is probably the head of uimessageboxdata.cpp). Names: FUN_<va> are the
// members of uimessageboxdata.h; parameter names are invented from the fields they set.
// MS2-UNIT: unit_141a00db0
// MS2-RANGE: 0x141a00db0-0x141a034d0 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// Free functions of other units.
CStringW FUN_14028de60(int nStringId);                              // a common string by id
unsigned int FUN_140869420();                                       // now (ms)
CString FUN_141a06ff0(int nSound);                                  // the sound event name (uimessageboxdata.cpp)
void FUN_141415600(const CString& strName);                         // drops an item slot bind id
CStringW FUN_140a228f0(int nId, const int& n, const CStringW& str); // a string by id formatted with two arguments
CString FUN_141028be0(__int64 nCharId, const CString& strKey, int nFlag, CString strEmpty);   // the profile image key
CStringW FUN_14016a730(const char* psz, int nCodePage);
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& nArg);
CStringW FUN_1401d0080(const CStringW& strLeft, const CStringW& strRight);

// @0x141a00db0
CMsgBoxData::CMsgBoxData(int nType)
    : m_18(0),
      m_nType(nType),
      m_24(-1),
      m_nId(CPtred::InterlockedInc(&s_nLastId)),
      m_30(0),
      m_strStrike(L""),
      m_nWidth(0),
      m_nHeight(0),
      m_bAgreement(false),
      m_nRetraction(0),
      m_nFlags(0),
      m_20c(false),
      m_bModaless(false),
      m_20e(true),
      m_20f(false),
      m_strAlign{"left", "center", "right", "justify"},
      m_nAlign(4)
{
    FUN_141a050b0();
}

// @0x141a01170
CMsgBoxData::~CMsgBoxData()
{
    m_spItem = NULL;
    m_spItem2 = NULL;
    for (size_t i = 0; i < m_reqItems.m_binds.GetCount(); i++)
        FUN_141415600(m_reqItems.m_binds[i]);
}

// @0x141a01480
bool CMsgBoxData::FUN_141a01480()
{
    return !m_callback.IsNull();
}
MS2_REPLACE_METHOD(0x141A01480, CMsgBoxData, FUN_141a01480, 63, 0x30009C27);

// @0x141a014d0
bool CMsgBoxData::FUN_141a014d0(int n, Scaleform::GFx::Value* pMovie)
{
    if (m_callback.IsNull())
        return false;
    m_movie = *pMovie;
    return m_callback(n, *this);
}
MS2_REPLACE_METHOD(0x141A014D0, CMsgBoxData, FUN_141a014d0, 105, 0x844FB949);

// @0x141a01540
void CMsgBoxData::FUN_141a01540(const CStringW& strTag)
{
    m_str38 = strTag;
}
MS2_REPLACE_METHOD(0x141A01540, CMsgBoxData, FUN_141a01540, 42, 0x9069D985);

// @0x141a01570
void CMsgBoxData::FUN_141a01570(const CStringW& strMsg)
{
    m_strMsg = strMsg;
}
MS2_REPLACE_METHOD(0x141A01570, CMsgBoxData, FUN_141a01570, 42, 0xB0C8C505);

// @0x141a015a0
void CMsgBoxData::FUN_141a015a0(const CStringW& str)
{
    m_strMsg2 = str;
}
MS2_REPLACE_METHOD(0x141A015A0, CMsgBoxData, FUN_141a015a0, 42, 0x83F2430D);

// @0x141a015d0
void CMsgBoxData::FUN_141a015d0(const CStringW& str)
{
    m_strTitle = str;
}
MS2_REPLACE_METHOD(0x141A015D0, CMsgBoxData, FUN_141a015d0, 42, 0x90927BED);

// @0x141a01600
void CMsgBoxData::FUN_141a01600(__int64 n)
{
    m_30 = (void*)n;
}
MS2_REPLACE_METHOD(0x141A01600, CMsgBoxData, FUN_141a01600, 25, 0x3BC76AD3);

// @0x141a01620
void CMsgBoxData::FUN_141a01620(int n)
{
    m_24 = n;
}
MS2_REPLACE_METHOD(0x141A01620, CMsgBoxData, FUN_141a01620, 22, 0x5ED7A56F);

// @0x141a01640
void CMsgBoxData::FUN_141a01640(int nAlign)
{
    m_nAlign = nAlign;
}
MS2_REPLACE_METHOD(0x141A01640, CMsgBoxData, FUN_141a01640, 25, 0xE2AA40B1);

// @0x141a01660
void CMsgBoxData::FUN_141a01660(const CStringW& strTag)
{
    m_strExtra = strTag;
}
MS2_REPLACE_METHOD(0x141A01660, CMsgBoxData, FUN_141a01660, 42, 0x0C3F20DC);

// @0x141a01690
void CMsgBoxData::FUN_141a01690(const CStringW& strBtn0, const CStringW& strBtn1, const CStringW& strBtn2)
{
    m_strBtn0 = strBtn0;
    m_strBtn1 = strBtn1;
    m_strBtn2 = strBtn2;
}
MS2_REPLACE_METHOD(0x141A01690, CMsgBoxData, FUN_141a01690, 98, 0x50FBFC55);

// @0x141a01700
void CMsgBoxData::FUN_141a01700(int nA, int nB, int nC)
{
    m_strBtn0 = FUN_14028de60(nA);
    m_strBtn1 = FUN_14028de60(nB);
    m_strBtn2 = FUN_14028de60(nC);
}
MS2_REPLACE_METHOD(0x141A01700, CMsgBoxData, FUN_141a01700, 247, 0xF5BEBE7F);

// @0x141a01800
// The button label presets (OK/Cancel, Yes/No, OK, ...).
void CMsgBoxData::FUN_141a01800(int n)
{
    switch (n)
    {
    case 1:
        m_strBtn0 = FUN_14028de60(0x477);
        m_strBtn1 = FUN_14028de60(0x478);
        m_strBtn2 = L"";
        break;
    case 2:
        m_strBtn0 = FUN_14028de60(0x475);
        m_strBtn1 = FUN_14028de60(0x476);
        m_strBtn2 = L"";
        break;
    case 3:
        m_strBtn0 = FUN_14028de60(0x475);
        m_strBtn1 = L"";
        m_strBtn2 = L"";
        break;
    case 4:
        m_strBtn0 = FUN_14028de60(0x476);
        m_strBtn1 = L"";
        m_strBtn2 = L"";
        break;
    case 5:
        m_strBtn0 = FUN_14028de60(0x5a0);
        m_strBtn1 = FUN_14028de60(0x5a1);
        m_strBtn2 = L"";
        break;
    }
}
MS2_REPLACE_METHOD(0x141A01800, CMsgBoxData, FUN_141a01800, 941, 0x281846E7);

// @0x141a01bc0
void CMsgBoxData::FUN_141a01bc0(int nSound)
{
    m_strSound = FUN_141a06ff0(nSound);
}
MS2_REPLACE_METHOD(0x141A01BC0, CMsgBoxData, FUN_141a01bc0, 93, 0x9FD7ABA2);

// @0x141a01c30
void CMsgBoxData::FUN_141a01c30(const CString& strSound)
{
    m_strSound = strSound;
}
MS2_REPLACE_METHOD(0x141A01C30, CMsgBoxData, FUN_141a01c30, 44, 0xB3DF27B1);

// @0x141a01c70
void CMsgBoxData::FUN_141a01c70(const CStringW& str)
{
    m_strStrike = str;
}
MS2_REPLACE_METHOD(0x141A01C70, CMsgBoxData, FUN_141a01c70, 42, 0x96759442);

// @0x141a01ca0
void CMsgBoxData::FUN_141a01ca0(int nSec, int nShowFormat, const CStringW& strFormat)
{
    m_nFlags |= 4;
    m_timer.m_nSec = nSec;
    m_timer.m_nMs = FUN_140869420();
    m_timer.m_nShowFormat = nShowFormat;
    m_timer.m_strFormat = strFormat;
}
MS2_REPLACE_METHOD(0x141A01CA0, CMsgBoxData, FUN_141a01ca0, 124, 0xA9E8F79C);

// @0x141a01d30
void CMsgBoxData::FUN_141a01d30(int nMode, const CStringW& strDefault, unsigned int nMax, int nShowLimit, int nMaxLine)
{
    m_nFlags |= 2;
    m_input.m_nType = nMode;
    m_input.m_strDefault = strDefault;
    m_input.m_nMaxChars = nMax;
    m_input.m_nShowLimit = nShowLimit;
    m_input.m_nMaxLine = nMaxLine;
    m_input.m_strMaxLineMsg = FUN_14028de60(0x982);
    m_input.m_strCountMsg = FUN_14028de60(0x984);
}
MS2_REPLACE_METHOD(0x141A01D30, CMsgBoxData, FUN_141a01d30, 293, 0xB4B29E7F);

// @0x141a01e60
void CMsgBoxData::FUN_141a01e60(MS2Ptr<CMsgBoxDataItem> spItem)
{
    if (spItem == NULL)
        return;
    m_nFlags |= 1;
    m_spItem = spItem;
}
MS2_REPLACE_METHOD(0x141A01E60, CMsgBoxData, FUN_141a01e60, 119, 0xB6F56F2A);

// @0x141a01ee0
void CMsgBoxData::FUN_141a01ee0(MS2Ptr<CItem> spItem, const CStringW& strName, int nColorMode, int nCount, int nMax,
                                int nPrice, int nUnitCount)
{
    if (spItem.get() != NULL)
    {
        m_spItem.AssignRaw(new CMsgBoxDataItem);
        if (m_spItem == NULL)
            return;
        m_nFlags |= 1;
        m_spItem->FUN_141a06630(strName, nColorMode == 1, spItem->FUN_140526bd0());
        m_spItem->m_spItem = spItem;
        m_spItem->m_nCount = nCount;
        m_spItem->m_nMax = nMax;
        m_spItem->m_nPrice = nPrice;
        m_spItem->m_nUnitCount = nUnitCount;
    }
}
MS2_REPLACE_METHOD(0x141A01EE0, CMsgBoxData, FUN_141a01ee0, 454, 0x3868D69C);

// @0x141a020b0
void CMsgBoxData::FUN_141a020b0(int nItemId, int nRarity, int n)
{
    MS2Ptr<CItem> spItem(new CItem);
    spItem->FUN_140523c40(nItemId, nRarity, 0);
    spItem->FUN_140526c70(n);
    FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, n, -1, -1, 1);
}
MS2_REPLACE_METHOD(0x141A020B0, CMsgBoxData, FUN_141a020b0, 352, 0x59C6C9F8);

// @0x141a02220
void CMsgBoxData::FUN_141a02220(MS2Ptr<CMsgBoxDataItem> spItem)
{
    if (spItem == NULL)
        return;
    m_nFlags |= 0x20;
    m_spItem2 = spItem;
}
MS2_REPLACE_METHOD(0x141A02220, CMsgBoxData, FUN_141a02220, 119, 0x62468448);

// @0x141a022a0
void CMsgBoxData::FUN_141a022a0(__int64 nCharId, const CStringW& strName, int nLevel, int nJob, const CString& strCode)
{
    m_strCharName = strName;
    m_strCharDetail = FUN_140a228f0(0xaa0, nLevel, TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, nJob));
    m_strProfile = FUN_14016a730(FUN_141028be0(nCharId, strCode, 1, ""), 0);
}
MS2_REPLACE_METHOD(0x141A022A0, CMsgBoxData, FUN_141a022a0, 431, 0x6722233A);

// @0x141a02460
void CMsgBoxData::FUN_141a02460(int)
{
    m_20c = true;
}
MS2_REPLACE_METHOD(0x141A02460, CMsgBoxData, FUN_141a02460, 22, 0xA2777C50);

// @0x141a02480
void CMsgBoxData::FUN_141a02480(int)
{
    m_bModaless = true;
}
MS2_REPLACE_METHOD(0x141A02480, CMsgBoxData, FUN_141a02480, 22, 0x7365A7F5);

// @0x141a024a0
void CMsgBoxData::FUN_141a024a0(int)
{
    m_20e = false;
}
MS2_REPLACE_METHOD(0x141A024A0, CMsgBoxData, FUN_141a024a0, 22, 0x20656AA7);

// @0x141a024c0
void CMsgBoxData::FUN_141a024c0()
{
    m_20f = true;
}
MS2_REPLACE_METHOD(0x141A024C0, CMsgBoxData, FUN_141a024c0, 18, 0x4ED51B3A);

// @0x141a024e0
void CMsgBoxData::FUN_141a024e0(CStringW str, bool bSelected)
{
    m_nFlags |= 8;
    m_checks.m_strLabel0 = str;
    m_checks.m_bSelected0 = bSelected;
}
MS2_REPLACE_METHOD(0x141A024E0, CMsgBoxData, FUN_141a024e0, 110, 0xF1B541D0);

// @0x141a02560
void CMsgBoxData::FUN_141a02560(CStringW str, bool bSelected)
{
    m_nFlags |= 8;
    m_checks.m_strLabel1 = str;
    m_checks.m_bSelected1 = bSelected;
}
MS2_REPLACE_METHOD(0x141A02560, CMsgBoxData, FUN_141a02560, 110, 0x83CF50FC);

// @0x141a025e0
void CMsgBoxData::FUN_141a025e0(CStringW strLabel0, CStringW strLabel1)
{
    m_nFlags |= 8;
    m_checks.m_strLabel0 = strLabel0;
    m_checks.m_strLabel1 = strLabel1;
}
MS2_REPLACE_METHOD(0x141A025E0, CMsgBoxData, FUN_141a025e0, 132, 0xEFE897F7);

// @0x141a02670
void CMsgBoxData::FUN_141a02670(bool b)
{
    m_nFlags |= 8;
    m_checks.m_bEnabled0 = b;
}
MS2_REPLACE_METHOD(0x141A02670, CMsgBoxData, FUN_141a02670, 51, 0x037F8A96);

// @0x141a026f0
void CMsgBoxData::FUN_141a026f0(bool b)
{
    m_nFlags |= 8;
    m_checks.m_bMust = b;
}
MS2_REPLACE_METHOD(0x141A026F0, CMsgBoxData, FUN_141a026f0, 51, 0x68E00F0A);

// @0x141a02730
void CMsgBoxData::FUN_141a02730(bool b)
{
    m_bAgreement = b;
}
MS2_REPLACE_METHOD(0x141A02730, CMsgBoxData, FUN_141a02730, 26, 0x83983DAB);

// @0x141a02750
void CMsgBoxData::FUN_141a02750(int n)
{
    m_nRetraction = n;
}
MS2_REPLACE_METHOD(0x141A02750, CMsgBoxData, FUN_141a02750, 25, 0xBF2FCB8D);

// @0x141a02770
void CMsgBoxData::FUN_141a02770(int nWidth, int nHeight)
{
    m_nFlags |= 0x10;
    m_nWidth = nWidth;
    m_nHeight = nHeight;
}
MS2_REPLACE_METHOD(0x141A02770, CMsgBoxData, FUN_141a02770, 70, 0x79022C97);

// @0x141a027c0
void CMsgBoxData::FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb)
{
    m_callback = cb;
}
MS2_REPLACE_METHOD(0x141A027C0, CMsgBoxData, FUN_141a027c0, 63, 0xADB0997D);

// @0x141a02810
void CMsgBoxData::FUN_141a02810(CStringW strTag)
{
    m_str218 = strTag;
}
MS2_REPLACE_METHOD(0x141A02810, CMsgBoxData, FUN_141a02810, 65, 0xAD380117);

// @0x141a02860
void CMsgBoxData::FUN_141a02860(void* p)
{
    m_18 = p;
}
MS2_REPLACE_METHOD(0x141A02860, CMsgBoxData, FUN_141a02860, 25, 0xAB8BF0FB);

// @0x141a02880
void CMsgBoxData::FUN_141a02880(int nBuffId, short nLevel, CStringW strExtra)
{
    m_buff.m_nId = nBuffId;
    m_buff.m_nLevel = nLevel;
    m_buff.m_strDesc = TSingleton<CStringTable>::GetInstance()->FUN_141812290(m_buff.m_nId, m_buff.m_nLevel, "tooltipDescription");
    m_buff.m_strExtra = strExtra;
}
MS2_REPLACE_METHOD(0x141A02880, CMsgBoxData, FUN_141a02880, 286, 0xAFC42ECF);

// @0x141a029b0
void CMsgBoxData::FUN_141a029b0(const Unk_MsgBoxBuff& buff)
{
    m_buff.m_nId = buff.m_nId;
    m_buff.m_nLevel = buff.m_nLevel;
    m_buff.m_strDesc = buff.m_strDesc;
    m_buff.m_strExtra = buff.m_strExtra;
}
MS2_REPLACE_METHOD(0x141A029B0, CMsgBoxData, FUN_141a029b0, 118, 0x11EE05B1);

// @0x141a02a30
void CMsgBoxData::FUN_141a02a30(const ATL::CAtlArray<ItemEntity>& items)
{
    m_reqItems.m_items.Copy(items);
}
MS2_REPLACE_METHOD(0x141A02A30, CMsgBoxData, FUN_141a02a30, 43, 0x2983810C);

// @0x141a02a70
void CMsgBoxData::FUN_141a02a70(CStringW strTitle, CString strUrl)
{
    m_nFlags |= 0x40;
    m_strLinkTitle = strTitle;
    m_strLinkUrl = strUrl;
}
MS2_REPLACE_METHOD(0x141A02A70, CMsgBoxData, FUN_141a02a70, 132, 0x95F33E05);

// @0x141a02b00
void CMsgBoxData::FUN_141a02b00(const CStringW& strDefault, ATL::CAtlList<CStringW>& list)
{
    m_choices.m_strDefault = strDefault;
    for (POSITION pos = list.GetHeadPosition(); pos != NULL; list.GetNext(pos))
        m_choices.m_list.AddTail(list.GetAt(pos));
}
MS2_REPLACE_METHOD(0x141A02B00, CMsgBoxData, FUN_141a02b00, 126, 0xC35A3BBB);

// @0x141a02b90
CStringW CMsgBoxData::FUN_141a02b90() const
{
    return m_str38;
}
MS2_REPLACE_METHOD(0x141A02B90, CMsgBoxData, FUN_141a02b90, 66, 0xC4B09B74);

// @0x141a02be0
const CString& CMsgBoxData::FUN_141a02be0() const
{
    return m_strSound;
}
MS2_REPLACE_METHOD(0x141A02BE0, CMsgBoxData, FUN_141a02be0, 17, 0x827BAE3D);

// @0x141a02c00
__int64 CMsgBoxData::FUN_141a02c00() const
{
    return (__int64)m_30;
}
MS2_REPLACE_METHOD(0x141A02C00, CMsgBoxData, FUN_141a02c00, 15, 0xAC153A31);

// @0x141a02c20
__int64 CMsgBoxData::FUN_141a02c20() const
{
    return (__int64)m_30;
}
MS2_REPLACE_METHOD(0x141A02C20, CMsgBoxData, FUN_141a02c20, 15, 0xAC153A31);

// @0x141a02c40
int CMsgBoxData::FUN_141a02c40() const
{
    return m_nType;
}
MS2_REPLACE_METHOD(0x141A02C40, CMsgBoxData, FUN_141a02c40, 14, 0xA25B27BF);

// @0x141a02c60
int CMsgBoxData::FUN_141a02c60() const
{
    return m_24;
}
MS2_REPLACE_METHOD(0x141A02C60, CMsgBoxData, FUN_141a02c60, 14, 0xBA6447E3);

// @0x141a02c80
int CMsgBoxData::FUN_141a02c80() const
{
    return m_24;
}
MS2_REPLACE_METHOD(0x141A02C80, CMsgBoxData, FUN_141a02c80, 14, 0xBA6447E3);

// @0x141a02ca0
int CMsgBoxData::FUN_141a02ca0() const
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x141A02CA0, CMsgBoxData, FUN_141a02ca0, 14, 0xD26D6807);

// @0x141a02cc0
IMessageListener* CMsgBoxData::FUN_141a02cc0() const
{
    return (IMessageListener*)m_18;
}
MS2_REPLACE_METHOD(0x141A02CC0, CMsgBoxData, FUN_141a02cc0, 15, 0xBBB219C9);

// @0x141a02ce0
const CStringW& CMsgBoxData::FUN_141a02ce0() const
{
    return m_strExtra;
}
MS2_REPLACE_METHOD(0x141A02CE0, CMsgBoxData, FUN_141a02ce0, 15, 0x27BBF311);

// @0x141a02d00
CStringW CMsgBoxData::FUN_141a02d00() const
{
    return m_choices.m_strDefault;
}
MS2_REPLACE_METHOD(0x141A02D00, CMsgBoxData, FUN_141a02d00, 68, 0xF41C05E3);

// @0x141a02d50
CStringW CMsgBoxData::FUN_141a02d50() const
{
    return m_str218;
}
MS2_REPLACE_METHOD(0x141A02D50, CMsgBoxData, FUN_141a02d50, 68, 0x654CE2F0);

// @0x141a02da0
const Delegate<bool(int, const CMsgBoxData&)>& CMsgBoxData::FUN_141a02da0() const
{
    return m_callback;
}
MS2_REPLACE_METHOD(0x141A02DA0, CMsgBoxData, FUN_141a02da0, 17, 0x1807320D);

// @0x141a02dc0
CString CMsgBoxData::FUN_141a02dc0() const
{
    return m_strLinkUrl;
}
MS2_REPLACE_METHOD(0x141A02DC0, CMsgBoxData, FUN_141a02dc0, 68, 0xD8467B00);

// @0x141a02e10
bool CMsgBoxData::FUN_141a02e10(int nIndex, bool bDefault) const
{
    FUN_141a071e0(nIndex, bDefault);
    return bDefault;
}
MS2_REPLACE_METHOD(0x141A02E10, CMsgBoxData, FUN_141a02e10, 47, 0x2509F554);

// @0x141a02e50
int CMsgBoxData::FUN_141a02e50(int nIndex, int nDefault) const
{
    FUN_140be25f0(nIndex, nDefault);
    return nDefault;
}
MS2_REPLACE_METHOD(0x141A02E50, CMsgBoxData, FUN_141a02e50, 46, 0x49ECCABD);

// @0x141a02e90
unsigned int CMsgBoxData::FUN_141a02e90(int nIndex, unsigned int nDefault) const
{
    FUN_140961900(nIndex, reinterpret_cast<int&>(nDefault));   // GetArg<unsigned> 0x140961900 is declared once (int&): an unsigned& overload made actionkeyobject's hook &CMsgBoxData::FUN_140961900 ambiguous
    return nDefault;
}
MS2_REPLACE_METHOD(0x141A02E90, CMsgBoxData, FUN_141a02e90, 46, 0x12726095);

// @0x141a02ed0
__int64 CMsgBoxData::FUN_141a02ed0(int nIndex, __int64 nDefault) const
{
    FUN_140e01c50(nIndex, nDefault);
    return nDefault;
}
MS2_REPLACE_METHOD(0x141A02ED0, CMsgBoxData, FUN_141a02ed0, 47, 0x7A48351D);

// @0x141a02f10
__int64 CMsgBoxData::FUN_141a02f10(int nIndex, __int64 nDefault) const
{
    FUN_140b19130(nIndex, nDefault);
    return nDefault;
}
MS2_REPLACE_METHOD(0x141A02F10, CMsgBoxData, FUN_141a02f10, 47, 0x191DF553);

// @0x141a02f50
CString CMsgBoxData::FUN_141a02f50(int nIndex, CString strDefault) const
{
    FUN_141a07140(nIndex, strDefault);
    return strDefault;
}
MS2_REPLACE_METHOD(0x141A02F50, CMsgBoxData, FUN_141a02f50, 108, 0x19785B43);

// @0x141a02fd0
CStringW CMsgBoxData::FUN_141a02fd0(int nIndex, CStringW strDefault) const
{
    FUN_140b76a70(nIndex, strDefault);
    return strDefault;
}
MS2_REPLACE_METHOD(0x141A02FD0, CMsgBoxData, FUN_141a02fd0, 108, 0x964EB854);

// @0x141a03050
bool CMsgBoxData::FUN_141a03050() const
{
    return m_20c;
}
MS2_REPLACE_METHOD(0x141A03050, CMsgBoxData, FUN_141a03050, 18, 0x2FB94A37);

// @0x141a03070
bool CMsgBoxData::FUN_141a03070() const
{
    return m_bModaless;
}
MS2_REPLACE_METHOD(0x141A03070, CMsgBoxData, FUN_141a03070, 18, 0xB3B05C10);

// @0x141a03090
bool CMsgBoxData::FUN_141a03090() const
{
    return m_20e;
}
MS2_REPLACE_METHOD(0x141A03090, CMsgBoxData, FUN_141a03090, 18, 0x8056E3C5);

// @0x141a030b0
bool CMsgBoxData::FUN_141a030b0() const
{
    switch (m_nType)
    {
    case 5:
    case 6:
    case 10:
    case 11:
    case 15:
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141A030B0, CMsgBoxData, FUN_141a030b0, 63, 0x375D54B6);

// @0x141a03100
bool CMsgBoxData::FUN_141a03100() const
{
    if (m_20f)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x141A03100, CMsgBoxData, FUN_141a03100, 28, 0x0ADD16BD);

// @0x141a03130
void CMsgBoxData::FUN_141a03130(UIMessageBox* pBox, int nSec)
{
    bool bShown = pBox != NULL && (pBox->FUN_1422dba00().get() ? true : false);
    if (bShown && (m_nFlags & 4) != 0 && m_timer.m_nShowFormat != 0)
    {
        m_timer.m_nArmed = nSec;
        CStringW strTail(L"\n");
        strTail += FUN_1401ceea0(m_timer.m_strFormat, nSec);
        pBox->FUN_1422dba00()->Invoke("onProcessFunction", "updateMsg", FUN_1401d0080(m_strMsg, strTail));
    }
}
MS2_REPLACE_METHOD(0x141A03130, CMsgBoxData, FUN_141a03130, 588, 0x51A7E58A);

// @0x141a03390
void CMsgBoxData::FUN_141a03390(UIMessageBox* pBox)
{
    bool bShown = pBox != NULL && (pBox->FUN_1422dba00().get() ? true : false);
    if (bShown && (m_nFlags & 4) != 0)
        m_timer.m_nButton = 1;
}
MS2_REPLACE_METHOD(0x141A03390, CMsgBoxData, FUN_141a03390, 216, 0x62F41E31);

// @0x141a03470
void CMsgBoxData::FUN_141a03470()
{
    if ((m_nFlags & 4) != 0 && m_timer.m_nArmed > 0)
        m_timer.m_timer.FUN_140868750(m_timer.m_nArmed * 1000);
}
MS2_REPLACE_METHOD(0x141A03470, CMsgBoxData, FUN_141a03470, 80, 0x15EDB00B);
