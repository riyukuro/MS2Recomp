// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: the chat hyperlink helpers. They parse a chat
// message's <A HREF=...> links (is a link the player's own, strip tags), and build the "event:itemTooltip / achieveTooltip /
// billDialog / searchFromMeratmarket" link markup for items, achievements, cash and Merat Market products, which the
// notification code posts to the chat log; descriptive names are provisional.
// MS2-UNIT: unit_140d2a7e0
// MS2-PIN: ??$format_arg@_WW4Unk_ChatLinkKind@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_ChatLinkKind@@@Z 0x140d311a0
// MS2-RANGE: 0x1400d2300-0x1400d2540 .text$di
// MS2-RANGE: 0x140d2a7e0-0x140d31670 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$Unk_WcStringFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@W4Unk_ChatLinkKind@@V12@H$$BY00_WHI@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@AEBW4Unk_ChatLinkKind@@1AEBHAEAY00$$CB_W3AEBI@Z 0x140d2f0e0 ; unique
// MS2-PIN: ??$Unk_WcStringFormat@_KW4Unk_ChatLinkKind@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H$$BY00_WH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_KAEBW4Unk_ChatLinkKind@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@AEBHAEAY00$$CB_W4@Z 0x140d30560 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCCashSaleProduct@@@@QEBA_NPEAVCCashSaleProduct@@@Z 0x140d313e0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <algorithm>
#include <utility>
#include <vector>

#include "ms2/client/ms2/achievemanager.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/store.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/cashproductdata.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemmergeoptiontable.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

// The chat links' second argument: what the link points at (item sources differ, 4 = achievement, 5 = bill, 7 = Merat Market).
enum Unk_ChatLinkKind
{
    CHATLINK_ITEM_OWNED = 1,
    CHATLINK_ITEM_ID = 2,
    CHATLINK_ITEM_UID = 3,
    CHATLINK_ACHIEVE = 4,
    CHATLINK_BILL = 5,
    CHATLINK_ITEM_REF = 6,
    CHATLINK_MERAT = 7
};

// One stat row of an item (MS2Ptr element of the item's stat list): the kind at +0x18 selects how the row is rendered.
class Unk_StatRow : public CPtred
{
public:
    int m_nKind;        // +0x18 0 = stat, 1 = special stat
    int m_nId;          // +0x1c
    int m_nValue;       // +0x20
};
MS2_CHECK_SIZE(Unk_StatRow, 0x28);

// The chat panel's text input (a Scaleform text field with an html getter/setter).
class Unk_ChatInput : public ASDisplayObject
{
public:
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(bool bFocus);                     // 24 set the focus
    int FUN_1422c76c0();                                    // has the focus
    CStringW FUN_1422e0b00();                               // the plain text
    CStringW FUN_1422e0c20();                               // the html text
    void FUN_1422e0bd0(const CStringW& strHtml);            // set the html text
};

class Unk_ChatLog;
class Unk_ChatMessenger;
// The chat UI singleton: the chat log panel is at +0x48, the messenger panel at +0x50.
class Unk_ChatWindow
{
public:
    char m_pad_00[0x48];
    Unk_ChatLog* m_pLog;
    Unk_ChatMessenger* m_pMessenger;
};
MS2_CHECK_OFFSET(Unk_ChatWindow, m_pLog, 0x48);
MS2_CHECK_OFFSET(Unk_ChatWindow, m_pMessenger, 0x50);

// The messenger browser (UI id 0x4e61): finds an item that was linked into a chat line.
class Unk_ChatBrowser
{
public:
    MS2Ptr<CItem> FUN_141a263d0(unsigned __int64 nUid);
};

// shared helpers of other units
Unk_ChatWindow* FUN_141482e80();
void FUN_141a24fb0(Unk_ChatLog* pLog, CStringW strText);
void FUN_141953660(Unk_ChatMessenger* pMessenger, CStringW strText);
Unk_ChatBrowser* FUN_140a3ab70(int nUiId);
CAchieveManager* FUN_1406c7600();
CPetManager* FUN_140535320();
CStringW FUN_14093e330(CAchieve* pAchieve, int nGrade);
CStringW FUN_14093b9c0(int nAchieveId, int nGrade);
CStringW FUN_141425950(int nItemId);                        // the item's name
CStringW FUN_140763e10(int nId);
CStringW FUN_140631720(int nId, int nValue, bool bTwo);     // a stat's "name +value" text
CStringW FUN_140631830(int nId, int nValue, int nMode);     // a special stat's text
bool FUN_14082f250(int nId);                                // IsStatKindTwo
CStringA FUN_140719190(int nId);
CStringA FUN_140719530(unsigned __int64 nId);
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_140632a60(int nStringId, const CStringW& strA, const CStringW& strB);
CStringW FUN_14052bd00(int nStringId, const CStringW& strA);
CStringW FUN_1409eadb0(int nStringId, const CStringW& strA, const CStringW& strB, const CStringW& strC);
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& strA, const CStringW& strB, const CStringW& strC);
void FUN_14028cf00(const CStringW& strText, ATL::CAtlArray<CStringW>& arrOut, const CStringW& strOpen, const CStringW& strClose);
void FUN_14025a680(const CStringW& strText, ATL::CAtlArray<CStringW>& arrOut, const wchar_t* pszDelimiters);
int FUN_1407181a0(const CStringW& str);
int FUN_140718200(const CStringW& str);
unsigned __int64 FUN_140718370(const CStringW& str);
bool FUN_14053f8c0(unsigned nUid);
bool FUN_14053f940(unsigned nUid);
void FUN_140615ca0(MS2Ptr<CItem> spItem, int nMode, ATL::CAtlArray<MS2Ptr<Unk_StatRow> >& rows);
WorldService* FUN_1403ed2d0();
class Unk_DsInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nUid); };
extern Unk_DsInventory DAT_143ab2a90;                       // the player's inventory
void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_142ca4bc0();                                       // the exe's atexit destructors of the string arrays / marker
void FUN_142ca4bf0();
void FUN_142ca4c20();
void FUN_142ca4c40();
void FUN_142ca4c60();
struct Unk_ChatLinkMarker {};


// The wide formatter flavour (a wide literal argument is WSTRING there): the Merat Market search links pass an empty wide string.
template <typename... Args>
inline CStringW Unk_WcStringFormat(const wchar_t* pszFormat, const Args&... args)
{
    const typename fmt::internal::ArgArray<sizeof...(Args)>::Type array = {fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(args)...};
    return StringFormat(pszFormat, fmt::ArgList(fmt::internal::wc_make_type(args...), array));
}

// ---- dynamic initializers (.text$di) ----

// @0x1400d2300
static CString s_orderNames[8] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// @0x1400d23d0
static CString s_sortNames[7] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400d2490
static CString s_skill("skill");

// @0x1400d24c0
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x1400d24f0
static char s_marker[0x48];
static Unk_ChatLinkMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142ca4c60), Unk_ChatLinkMarker());
#endif

// ---- chat links ----

CStringW FUN_140d2ef00(CStringW strHref, CStringW strColor, CStringW strText);
CStringW FUN_140d2e6f0(MS2Ptr<CItem> spItem);
CStringW FUN_140d2e2b0(int nItemId, int nGrade, __int64 nUid);
CStringW FUN_140d2d8a0(int nAchieveId, int nGrade, CStringW strText, CStringW strDate);
CStringW FUN_140d2d440(unsigned nId, int nGrade);
CStringW FUN_140d2e900(unsigned nItemId, int nGrade);
CStringW FUN_140d2ea90(int nNameId, int nGrade, unsigned nCount, int nUid);
CStringW FUN_140d2e090(unsigned __int64 nUid, MS2Ptr<CItem> spItem);
CStringW FUN_140d2da30(MS2Ptr<CCashSaleProduct> spProduct);
CStringW FUN_140d2dc70(MS2Ptr<CMeratMarketProduct> spProduct);
CStringW FUN_140d2ec30(MS2Ptr<CMeratMarketPremiumProduct> spProduct);
void FUN_140d2d060(int nItemId, int nGrade, __int64 nUid);
void FUN_140d2c730(CStringW& strText, const CStringW& strTag);
__int64 FUN_140d2caf0(const CStringW& strText);
void FUN_140d2f020(const CStringW& strText, ATL::CAtlArray<__int64>& ids, const wchar_t* pszDelimiters);
bool FUN_140d2a7e0(CStringW strText, ATL::CAtlArray<CStringW>& arrLinks);
CStringW FUN_140d2b190(const CStringW& strArgs, MS2Ptr<CItem> spItem, int nKind);
CStringW FUN_140d2b8f0(MS2Ptr<CItem> spItem, const CStringW& strFilter);
CStringW FUN_140d2bff0(MS2Ptr<CItem> spItem);

// Does the chat line contain a link that is also in the list (compared without its A / FONT tags, same linked id)?
// @0x140d2a7e0
bool FUN_140d2a7e0(CStringW strText, ATL::CAtlArray<CStringW>& arrLinks)
{
    CStringW strPlain(strText);
    FUN_140d2c730(strPlain, CStringW(L"A"));
    FUN_140d2c730(strPlain, CStringW(L"FONT"));
    strPlain.Replace(L"&apos;", L"'");
    strPlain.Replace(L"&lt;", L"<");
    strPlain.Replace(L"&gt;", L">");
    strPlain.Replace(L"&nbsp;", L"\xa0");
    for (unsigned i = 0; i < arrLinks.GetCount(); ++i)
    {
        CStringW strOther(arrLinks[i]);
        FUN_140d2c730(strOther, CStringW(L"a"));
        FUN_140d2c730(strOther, CStringW(L"FONT"));
        if (strPlain == strOther)
        {
            __int64 nId = FUN_140d2caf0(strText);
            __int64 nOther = FUN_140d2caf0(arrLinks[i]);
            if (nId != 0 && nId == nOther)
                return true;
        }
    }
    return false;
}

// @0x140d2aa60
int FUN_140d2aa60(CStringW& strLink)
{
    if (strLink.Find(L"event:itemTooltip", 0) > 0)
        return 1;
    if (strLink.Find(L"event:achieveTooltip", 0) > 0)
        return 1;
    if (strLink.Find(L"event:billDialog", 0) > 0)
        return 1;
    if (strLink.Find(L"event:searchFromMeratmarket", 0) > 0)
        return 1;
    return 0;
}

// Replaces a link's text with the announcement the link kind stands for (the chat line "kind:id:..:text"). false: unusable.
// @0x140d2ab10
bool FUN_140d2ab10(CStringW& strLine)
{
    ATL::CAtlArray<CStringW> parts;
    FUN_14025a680(strLine, parts, L",");
    if (parts.GetCount() < 4)
        return false;

    int nSource = FUN_1407181a0(parts[0]);
    unsigned __int64 nUid = FUN_140718370(parts[1]);
    int nKind = FUN_1407181a0(parts[2]);
    CStringW strArgs(parts[3]);

    Unk_ChatBrowser* pBrowser = FUN_140a3ab70(0x4e61);
    if (pBrowser == NULL)
        return false;

    if (nSource == 2)
    {
        if (!FUN_14053f8c0((unsigned)nUid) && !FUN_14053f940((unsigned)nUid))
        {
            MS2Ptr<CItem> spItem = pBrowser->FUN_141a263d0(nUid);
            if (spItem.IsNull())
                return false;
            strLine = FUN_140d2b190(strArgs, spItem, nKind);
        }
        else if (nKind == 3)
        {
            ATL::CAtlArray<CStringW> fields;
            FUN_14025a680(strArgs, fields, L":");
            if (fields.GetCount() != 3)
                return true;
            CStringW& strName = fields[0];
            int nItemId = FUN_140718200(fields[1]);
            int nCount = FUN_1407181a0(fields[2]);
            CStringW strCount = FUN_140763e10(nCount);
            if (!FUN_14053f8c0((unsigned)nUid))
            {
                if (FUN_14053f940((unsigned)nUid))
                    strLine = FUN_1409eaa20(CStringW(L"s_msg_item_open_item_announce_to_world_merat"), strName, FUN_141425950(nItemId), strCount);
            }
            else
            {
                strLine = FUN_1409eaa20(CStringW(L"s_msg_item_open_item_announce_to_world_meso"), strName, FUN_141425950(nItemId), strCount);
            }
        }
        return true;
    }
    if (nSource == 3)
    {
        MS2Ptr<CItem> spItem = pBrowser->FUN_141a263d0(nUid);
        if (spItem.IsNull())
            return false;
        strLine = FUN_140d2b190(strArgs, spItem, nKind);
        return true;
    }
    return false;
}

// The text of an item announcement in the chat by what the item came from (nKind).
// @0x140d2b190
CStringW FUN_140d2b190(const CStringW& strArgs, MS2Ptr<CItem> spItem, int nKind)
{
    CStringW strLink = FUN_140d2e6f0(spItem);
    switch (nKind)
    {
    case 1:
        return FUN_140632a60(0x960, strArgs, strLink);
    case 2:
    {
        ATL::CAtlArray<CStringW> fields;
        FUN_14025a680(strArgs, fields, L":");
        CStringW strFirst;
        CStringW strSecond;
        if (!fields.IsEmpty())
        {
            strFirst = fields.GetAt(0);
            if (fields.GetCount() > 1)
                strSecond = fields.GetAt(1);
        }
        return FUN_1409eadb0(0x962, strFirst, strLink, FUN_140d2b8f0(spItem, strSecond));
    }
    case 3:
    {
        ATL::CAtlArray<CStringW> fields;
        FUN_14025a680(strArgs, fields, L":");
        if (fields.GetCount() == 2)
        {
            CStringW& strName = fields[0];
            int nItemId = FUN_140718200(fields[1]);
            return FUN_1409eaa20(CStringW(L"s_msg_item_open_item_announce_to_world"), strName, FUN_141425950(nItemId), strLink);
        }
        return CStringW(L"");
    }
    case 4:
        return FUN_140632a60(0xc42, strArgs, strLink);
    case 5:
        return FUN_1409eaa20(CStringW(L"s_item_merge_chat_maxoption"), strArgs, strLink, FUN_140d2bff0(spItem));
    case 6:
    {
        ATL::CAtlArray<CStringW> fields;
        FUN_14025a680(strArgs, fields, L":");
        if (fields.GetCount() == 2)
        {
            CStringW& strName = fields[0];
            int nItemId = FUN_140718200(fields[1]);
            return FUN_1409eaa20(CStringW(L"s_msg_item_identified_item_announce_to_world"), strName, FUN_141425950(nItemId), strLink);
        }
        return CStringW(L"");
    }
    }
    return CStringW(L"");
}

// The item's stat lines that the filter ("kind_id|kind_id...") asks for, joined with ", " and wrapped in the max-stat colour.
// @0x140d2b8f0
CStringW FUN_140d2b8f0(MS2Ptr<CItem> spItem, const CStringW& strFilter)
{
    CStringW strLabel = FUN_14028b8e0(CStringW(L"s_word_stat_max"));
    CStringW strLines;
    CStringW strSeparator(L", ");
    ATL::CAtlArray<MS2Ptr<Unk_StatRow> > rows;
    FUN_140615ca0(spItem, 2, rows);
    if (!rows.IsEmpty())
    {
        std::vector<std::pair<int, int> > wanted;
        if (!strFilter.IsEmpty())
        {
            ATL::CAtlArray<CStringW> entries;
            FUN_14025a680(strFilter, entries, L"|");
            for (size_t i = 0; i < entries.GetCount(); ++i)
            {
                CStringW strEntry(entries.GetAt(i));
                ATL::CAtlArray<CStringW> ids;
                FUN_14025a680(strEntry, ids, L"_");
                if (ids.GetCount() < 2)
                    continue;
                std::pair<int, int> key;
                key.first = FUN_1407181a0(ids.GetAt(0));
                key.second = FUN_1407181a0(ids.GetAt(1));
                wanted.push_back(key);
            }
        }
        int nRemaining = (int)wanted.size();
        for (size_t i = 0; i < rows.GetCount() && nRemaining > 0; ++i)
        {
            MS2Ptr<Unk_StatRow> spRow(rows[i]);
            if (spRow == NULL)
                continue;
            int nKind = spRow->m_nKind;
            std::pair<int, int> key(nKind, spRow->m_nId);
            if (std::find(wanted.begin(), wanted.end(), key) == wanted.end())
                continue;
            --nRemaining;
            if (!strLines.IsEmpty())
                strLines.Append(strSeparator);
            CStringW strText;
            if (nKind == 0)
                strText = StringFormat(strLabel, FUN_140631720(spRow->m_nId, spRow->m_nValue, FUN_14082f250(spRow->m_nId)));
            else if (nKind == 1)
                strText = StringFormat(strLabel, FUN_140631830(spRow->m_nId, spRow->m_nValue, 0));
            strLines.Append(strText);
        }
    }
    return StringFormat(FUN_14028b8e0(CStringW(L"s_word_stat_max_color")), strLines);
}

// The merge option description of an item (the max-option announcement).
// @0x140d2bff0
CStringW FUN_140d2bff0(MS2Ptr<CItem> spItem)
{
    return TSingleton<CItemMergeOptionTable>::GetInstance()->FUN_1405c1090(spItem, 0);
}

// Cuts every pair of [begin ... end] out of the text into the list. true when at least one was found.
// @0x140d2c080
bool FUN_140d2c080(CStringW strText, ATL::CAtlList<CStringW>& links, CStringW strBegin, CStringW strEnd)
{
    if (strText.IsEmpty())
        return false;
    if (strBegin.IsEmpty())
        return false;
    if (strEnd.IsEmpty())
        return false;
    int nPos = 0;
    for (;;)
    {
        int nFirst = strText.Find(strBegin, nPos);
        if (nFirst < 0)
            break;
        nPos = strText.Find(strEnd, nFirst);
        if (nPos < 0)
            break;
        nPos += strEnd.GetLength();
        links.AddTail(strText.Mid(nFirst, nPos - nFirst));
    }
    return links.GetCount() != 0;
}

// Removes the links from the chat input that were not taken from the list (hand-typed links are not allowed).
// @0x140d2c2a0
void FUN_140d2c2a0(MS2Ptr<Unk_ChatInput> spInput, ATL::CAtlArray<CStringW>& arrLinks)
{
    if (spInput->FUN_1422c76c0() == 0)
        return;
    if (!arrLinks.IsEmpty())
        return;
    CStringW strHtml = spInput->FUN_1422e0c20();
    if (strHtml.IsEmpty())
        return;

    ATL::CAtlList<CStringW> links(10);
    if (FUN_140d2c080(CStringW(strHtml), links, CStringW(L"<A HREF="), CStringW(L"/A>")))
    {
        bool bChanged = false;
        POSITION pos = links.GetHeadPosition();
        while (pos != NULL)
        {
            CStringW strLink(links.GetAt(pos));
            if (!FUN_140d2a7e0(CStringW(strLink), arrLinks))
            {
                strHtml.Replace(strLink, L"");
                bChanged = true;
            }
            links.GetNext(pos);
        }
        if (bChanged)
        {
            spInput->FUN_1422e0bd0(strHtml);
            spInput->vfunc_24(true);
            if (spInput->FUN_1422e0b00().IsEmpty())
            {
                CStringW strEmpty(L"<Font></Font>");
                spInput->FUN_1422e0bd0(strEmpty);
                spInput->vfunc_24(true);
            }
        }
    }
}

// @0x140d2c620
void FUN_140d2c620(CStringW& strText)
{
    strText.Replace(L"&", L"&amp;");
}

// @0x140d2c650
void FUN_140d2c650(CStringW& strText)
{
    FUN_140d2c730(strText, CStringW(L"P"));
    FUN_140d2c730(strText, CStringW(L"BR"));
    FUN_140d2c730(strText, CStringW(L"TEXTFORMAT"));
    FUN_140d2c730(strText, CStringW(L"FONT"));
}

// Removes the <tag ...> and </tag> markup of the tag from the text (at most 20 tags); a broken tag clears the text.
// @0x140d2c730
void FUN_140d2c730(CStringW& strText, const CStringW& strTag)
{
    CStringW strLowerTag(strTag);
    strLowerTag.MakeLower();
    CStringW strLower(strText);
    strLower.MakeLower();
    CStringW strClose;
    strClose.Format(L"%s", L">");
    CStringW strOpen;
    strOpen.Format(L"<%s", (const wchar_t*)strLowerTag);
    CStringW strEndTag;
    strEndTag.Format(L"</%s>", (const wchar_t*)strLowerTag);
    CStringW strEmpty(L"");
    int nRemaining = 20;
    while (nRemaining > 0)
    {
        --nRemaining;
        int nBegin = strLower.Find(strOpen, 0);
        if (nBegin < 0)
            break;
        int nEnd = strLower.Find(strClose, nBegin);
        if (nEnd < 0 || nEnd <= nBegin)
        {
            strText = strEmpty;
            return;
        }
        strLower.Delete(nBegin, nEnd - nBegin + 1);
        strText.Delete(nBegin, nEnd - nBegin + 1);
        nBegin = strLower.Find(strEndTag, 0);
        if (nBegin < 0)
        {
            strText = strEmpty;
            return;
        }
        strLower.Delete(nBegin, strEndTag.GetLength());
        strText.Delete(nBegin, strEndTag.GetLength());
        continue;
    }
    if (nRemaining <= 0 && strText.Find(strOpen, 0) >= 0)
        strText = strEmpty;
}

// The linked id of a chat line: the second number of the first <...> group that has more than two comma separated ids.
// @0x140d2caf0
__int64 FUN_140d2caf0(const CStringW& strText)
{
    ATL::CAtlArray<CStringW> groups;
    FUN_14028cf00(strText, groups, CStringW(L"<"), CStringW(L">"));
    for (unsigned i = 0; i < groups.GetCount(); ++i)
    {
        CStringW strGroup(groups.GetAt(i));
        if (strGroup.IsEmpty())
            continue;
        ATL::CAtlArray<__int64> ids;
        FUN_140d2f020(strGroup, ids, L",");
        if (ids.GetCount() > 2)
            return ids[1];
    }
    return 0;
}

// Post a chat line (the chat log and the messenger panel) of an achievement link.
// @0x140d2cca0
void FUN_140d2cca0(unsigned nId, unsigned nRank)
{
    CStringW strLink = FUN_140d2d440(nId, nRank);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
    if (FUN_141482e80()->m_pMessenger != NULL)
        FUN_141953660(FUN_141482e80()->m_pMessenger, CStringW(strLink));
}

// Post a chat line of a cash product link.
// @0x140d2cd80
void FUN_140d2cd80(MS2Ptr<CCashSaleProduct> spProduct)
{
    CStringW strLink = FUN_140d2da30(spProduct);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
}

// Post a chat line of a Merat Market product link.
// @0x140d2ce40
void FUN_140d2ce40(MS2Ptr<CMeratMarketProduct> spProduct)
{
    CStringW strLink = FUN_140d2dc70(spProduct);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
}

// Post a chat line of an item link of a uid.
// @0x140d2cf00
void FUN_140d2cf00(unsigned __int64 nUid, MS2Ptr<CItem> spItem)
{
    CStringW strLink = FUN_140d2e090(nUid, spItem);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
}

// Post the link of an item.
// @0x140d2cfc0
void FUN_140d2cfc0(MS2Ptr<CItem> spItem)
{
    if (spItem == NULL)
        return;
    __int64 nUid = spItem->FUN_140526a50();
    int nGrade = spItem->FUN_140526bd0();
    int nItemId = spItem->FUN_1405276c0();
    FUN_140d2d060(nItemId, nGrade, nUid);
}

// @0x140d2d060
void FUN_140d2d060(int nItemId, int nGrade, __int64 nUid)
{
    CStringW strLink = FUN_140d2e2b0(nItemId, nGrade, nUid);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
    if (FUN_141482e80()->m_pMessenger != NULL)
        FUN_141953660(FUN_141482e80()->m_pMessenger, CStringW(strLink));
}

// @0x140d2d150
void FUN_140d2d150(int nItemId, int nGrade)
{
    CStringW strLink = FUN_140d2e900(nItemId, nGrade);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
    if (FUN_141482e80()->m_pMessenger != NULL)
        FUN_141953660(FUN_141482e80()->m_pMessenger, CStringW(strLink));
}

// @0x140d2d230
void FUN_140d2d230(int nNameId, int nGrade, unsigned nCount, int nUid)
{
    CStringW strLink = FUN_140d2ea90(nNameId, nGrade, nCount, nUid);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
    if (FUN_141482e80()->m_pMessenger != NULL)
        FUN_141953660(FUN_141482e80()->m_pMessenger, CStringW(strLink));
}

// Post a chat line of a Merat Market premium product link.
// @0x140d2d330
void FUN_140d2d330(MS2Ptr<CMeratMarketPremiumProduct> spProduct)
{
    CStringW strLink = FUN_140d2ec30(spProduct);
    if (FUN_141482e80()->m_pLog != NULL)
        FUN_141a24fb0(FUN_141482e80()->m_pLog, CStringW(strLink));
    if (FUN_141482e80()->m_pMessenger != NULL)
        FUN_141953660(FUN_141482e80()->m_pMessenger, CStringW(strLink));
}

// The achievement link text: "<name> (user info)" for the earned grade.
// @0x140d2d440
CStringW FUN_140d2d440(unsigned nId, int nGrade)
{
    MS2Ptr<CAchieve> spAchieve = FUN_1406c7600()->Find(nId);
    if (spAchieve.IsNull())
        return CStringW(L"");

    CStringW strGrade;
    CStringW strUser;
    PCBase* pPC = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC != NULL)
    {
        int nKind = 2;
        int nState = spAchieve->GetState();
        if (nState == 2)
        {
            if (nGrade < spAchieve->GetCurGrade())
                nKind = 3;
            else
                nKind = 2;
        }
        else if (nState == 3)
        {
            nKind = 3;
        }
        CStringW strTitle(nKind != 3 ? FUN_14028de60(0x77f) : FUN_14028de60(0x780));
        strGrade = FUN_14093e330(spAchieve.get(), nGrade);
        strUser = StringFormat(FUN_14028b8e0(CStringW(L"s_achieve_tooltip_user_info")), pPC->vfunc_77(), strTitle);
    }
    return FUN_140d2d8a0(nId, nGrade, CStringW(strGrade), CStringW(strUser));
}

// @0x140d2d8a0
CStringW FUN_140d2d8a0(int nAchieveId, int nGrade, CStringW strText, CStringW strDate)
{
    unsigned __int64 nLinkId = nAchieveId;
    Unk_ChatLinkKind eKind = CHATLINK_ACHIEVE;
    CStringW strLink = StringFormat(L"'event:achieveTooltip,{0},{1},{2},{3},{4}'", nLinkId, eKind, nGrade, strText, strDate);
    return FUN_140d2ef00(CStringW(strLink), CStringW(L"#ffffff"), FUN_14093b9c0(nAchieveId, nGrade));
}

// The cash product link.
// @0x140d2da30
CStringW FUN_140d2da30(MS2Ptr<CCashSaleProduct> spProduct)
{
    if (spProduct == NULL)
        return CStringW(L"");
    unsigned __int64 nLinkId = (unsigned)spProduct->m_n18;
    Unk_ChatLinkKind eKind = CHATLINK_BILL;
    CStringW strLink = StringFormat(L"'event:billDialog,{0},{1},{2},{3},{4}'", nLinkId, eKind, (unsigned)spProduct->m_data.m_n28, spProduct->m_data.m_n2c, spProduct->m_n1c);
    return FUN_140d2ef00(CStringW(strLink), CStringW(L"#ffffff"), FUN_14052bd00(0xabf, FUN_141425950(spProduct->m_data.m_n28)));
}

// The Merat Market product link (premium and UGC products).
// @0x140d2dc70
CStringW FUN_140d2dc70(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == NULL)
        return CStringW(L"");
    int nUgc = spProduct->IsUgc();
    int nCategory = spProduct->GetCategoryId();
    if (nCategory == 0)
        return CStringW(L"");

    CStringA strId;
    if (nUgc == 0)
        strId = FUN_140719190(spProduct->m_premium.m_nId);
    else
        strId = FUN_140719530(spProduct->m_ugc.m_n20);
    CStringW strName = spProduct->GetName();
    unsigned nItemId = spProduct->GetItemId();
    Unk_ChatLinkKind eKind = CHATLINK_MERAT;
    CStringW strLink = Unk_WcStringFormat(L"'event:searchFromMeratmarket,{0},{1},{2},{3},{4},{5},{6}'", strId, eKind, strId, nUgc, L"", nCategory, nItemId);
    int nGrade = nUgc == 0 ? spProduct->m_premium.m_nGrade : spProduct->m_ugc.m_n1f8;
    return FUN_140d2ef00(CStringW(strLink), TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)nGrade), FUN_14052bd00(0xabe, strName));
}

// The item link of an item with an uid (a held item of any container, else the item name only).
// @0x140d2e090
CStringW FUN_140d2e090(unsigned __int64 nUid, MS2Ptr<CItem> spItem)
{
    if (spItem == NULL)
        return CStringW(L"");
    Unk_ChatLinkKind eKind = CHATLINK_ITEM_REF;
    int nZero1 = 0;
    int nZero2 = 0;
    CStringW strLink = StringFormat(L"'event:itemTooltip,{0},{1},{2},{3},{4}'", nUid, eKind, nUid, nZero2, nZero1);
    CStringW strColor = TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)spItem->FUN_140526bd0());
    return FUN_140d2ef00(CStringW(strLink), CStringW(strColor), spItem->FUN_140527b10());
}

// The item link of an item by id, grade and uid; the uid is searched in the held containers.
// @0x140d2e2b0
CStringW FUN_140d2e2b0(int nItemId, int nGrade, __int64 nUid)
{
    Unk_ChatLinkKind eKind = CHATLINK_ITEM_UID;
    CStringW strLink = StringFormat(L"'event:itemTooltip,{0},{1},{2},{3},{4}'", (unsigned __int64)nUid, eKind, (unsigned __int64)nUid, (unsigned)nItemId, (ItemGradeKey)nGrade);
    CStringW strColor = TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)nGrade);
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
    if (spItem == NULL)
    {
        PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPC != NULL)
        {
            spItem = pPC->FUN_141655b80(nUid);
            if (spItem == NULL)
            {
                spItem = FUN_140535320()->FUN_140c8b410()->FUN_140c87250(nUid);
            }
            if (spItem == NULL)
                spItem = MS2_STORE_TABLE.Find(nUid);
        }
    }
    CStringW strName(spItem.get() == NULL ? FUN_141425950(nItemId) : spItem->FUN_140527b10());
    return FUN_140d2ef00(CStringW(strLink), CStringW(strColor), CStringW(strName));
}

// The item link of an item object.
// @0x140d2e6f0
CStringW FUN_140d2e6f0(MS2Ptr<CItem> spItem)
{
    unsigned __int64 nUid = spItem->FUN_140526a50();
    ItemGradeKey eGrade = (ItemGradeKey)spItem->FUN_140526bd0();
    unsigned nItemId = spItem->FUN_1405276c0();
    unsigned __int64 nUid2 = spItem->FUN_140526a50();
    Unk_ChatLinkKind eKind = CHATLINK_ITEM_UID;
    CStringW strLink = StringFormat(L"'event:itemTooltip,{0},{1},{2},{3},{4}'", nUid, eKind, nUid2, nItemId, eGrade);
    CStringW strColor = TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)spItem->FUN_140526bd0());
    return FUN_140d2ef00(CStringW(strLink), CStringW(strColor), spItem->FUN_140527b10());
}

// The item link by item id and grade (no uid).
// @0x140d2e900
CStringW FUN_140d2e900(unsigned nItemId, int nGrade)
{
    unsigned __int64 nLinkId = nItemId;
    Unk_ChatLinkKind eKind = CHATLINK_ITEM_ID;
    int nZero = 0;
    CStringW strLink = StringFormat(L"'event:itemTooltip,{0},{1},{2},{3},{4}'", nLinkId, eKind, nZero, nItemId, (ItemGradeKey)nGrade);
    CStringW strColor = TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)nGrade);
    return FUN_140d2ef00(CStringW(strLink), CStringW(strColor), FUN_141425950((int)nItemId));
}

// The item link by name id, grade, count and uid.
// @0x140d2ea90
CStringW FUN_140d2ea90(int nNameId, int nGrade, unsigned nCount, int nUid)
{
    unsigned __int64 nLinkId = (__int64)nUid;
    Unk_ChatLinkKind eKind = CHATLINK_ITEM_OWNED;
    int nZero = 0;
    CStringW strLink = StringFormat(L"'event:itemTooltip,{0},{1},{2},{3},{4}'", nLinkId, eKind, nZero, nUid, nCount);
    CStringW strColor = TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)nGrade);
    return FUN_140d2ef00(CStringW(strLink), CStringW(strColor), FUN_141425950(nNameId));
}

// The Merat Market premium product link.
// @0x140d2ec30
CStringW FUN_140d2ec30(MS2Ptr<CMeratMarketPremiumProduct> spProduct)
{
    if (spProduct == NULL)
        return CStringW(L"");
    unsigned __int64 nLinkId = (__int64)spProduct->m_nId;
    int nZero = 0;
    int nCategory = spProduct->m_nCategoryId;
    if (nCategory == 0)
        return CStringW(L"");
    CStringA strId = FUN_140719190(spProduct->m_nId);
    CStringW strName = spProduct->CDBPremiumProduct::GetName();
    Unk_ChatLinkKind eKind = CHATLINK_MERAT;
    CStringW strLink = Unk_WcStringFormat(L"'event:searchFromMeratmarket,{0},{1},{2},{3},{4},{5}'", nLinkId, eKind, strId, nZero, L"", nCategory);
    return FUN_140d2ef00(CStringW(strLink), TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)spProduct->m_nGrade), FUN_14052bd00(0xabe, strName));
}

// The anchor markup of a chat link: <a href=...><FONT color=...>[name]</FONT></a>.
// @0x140d2ef00
CStringW FUN_140d2ef00(CStringW strHref, CStringW strColor, CStringW strText)
{
    FUN_140d2c620(strText);
    return StringFormat(L"<a href={0}><FONT color='{1}'>[{2}]</FONT></a>", strHref, strColor, strText);
}

// @0x140d2eff0
__int64 FUN_140d2eff0(const CStringW& str)
{
    return _wtoi64(str);
}

// Splits the text at the delimiters into numbers.
// @0x140d2f020
void FUN_140d2f020(const CStringW& strText, ATL::CAtlArray<__int64>& ids, const wchar_t* pszDelimiters)
{
    int nStart = 0;
    CStringW strToken = strText.Tokenize(pszDelimiters, nStart);
    while (!strToken.IsEmpty())
    {
        ids.Add(FUN_140d2eff0(strToken));
        strToken = strText.Tokenize(pszDelimiters, nStart);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4bc0-0x142ca4c80 .text$yd
