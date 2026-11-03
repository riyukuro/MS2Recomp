// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIEnchantScrollDialog: the item enchant scroll window. See uienchantscrolldialog.h.
// MS2-UNIT: ?\uienchantscrolldialog.cpp
// MS2-GUESS-LOOKALIKES (the CAtlArray<unsigned> / MS2Ptr accessor glue is byte-identical to other instances)
// MS2-RANGE: 0x140f3b490-0x140f3fb10 .text$mn
// MS2-RANGE: 0x1400deeb0-0x1400df250 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0UIEnchantScrollDialog@@QEAA@XZ 0x140f3b490 ; unique
// MS2-PIN: ?FUN_140f3e920@@YAHAEBV?$CAtlArray@HV?$CDefaultElementTraits@H@ATL@@@ATL@@AEBH@Z 0x140f3e920 ; unique
// MS2-PIN: ??1UIEnchantScrollDialog@@UEAA@XZ 0x140f3f140 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@IV?$CDefaultElementTraits@I@ATL@@@ATL@@CAXPEAI_K@Z 0x140f3f370 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@IV?$CDefaultElementTraits@I@ATL@@@ATL@@QEAAXXZ 0x140f3f690 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@IV?$CDefaultElementTraits@I@ATL@@@ATL@@QEAA_N_KH@Z 0x140f3f6d0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uienchantscrolldialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uienchantscrolldialog.h"
#include "uimessagebox.h"
#include "uimessageboxdata.h"
#include "enchantscrollslot.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/formatstringid.h"
#include "ms2/placeholder/blockformat.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/uiservice.h"

MS2_EMIT_CRT_MEMMOVE_S();

// The header statics of this TU (the sort-type names twice, then the skill/stun pair and the condition table; the whole
// group once more).
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe objects ----

// The inventory (global 0x143ab2a90): item handle by uid.
class Unk_Inventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 uid); };
extern Unk_Inventory g_143ab2a90;   // the real global (0x143ab2a90)

// The enchant data of an item (CItem::FUN_1405278a0).
class CItemStatus
{
public:
    int GetStatValue(unsigned nType, int nWhich, int nSub);
    float GetEnchantRatio(unsigned nType);
};

class Unk_EsUiMgr { public:  void FUN_141adc530(int uiId); };

class UIInventoryDialog { public: void FUN_141999e00(); };
template<class T> T* Unk_BreakDialog(int);

CStringW GetStatValueText(unsigned nKey);                                           // option name template
__int64 FUN_140632990(__int64 nBase, float fExtra);                                 // the option value
CStringW FUN_14183e9c0(CStringW strText, int nRank);                                // rank-coloured text
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nId);
void FUN_14151f200();
unsigned __int64 FUN_140718370(const CStringW& str);
void FUN_140710590(COutPacket& packet);
void FUN_141275260(int nId, int a, int b);                                          // system message by string id
int FUN_141276180(const CString& strSound, const CString& strArg);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* pListener, CStringW strTag);
void FUN_140cd73b0(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem);   // set the slot item
void FUN_140cd74a0(const CString& strName);                                                // clear the slot

// The id-keyed string-table formatter (FUN_14028dee0: looks up the id and formats its "{0}.." text) and its wrappers.
CStringW FUN_14028dee0(unsigned nId, const fmt::ArgList& args);
#define ES_ID_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dee0(unsigned nId, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, WC_REF)}; \
        return FUN_14028dee0(nId, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
ES_ID_WRAP(3)

CStringW FUN_141b71910(__int64 n);

typedef ATL::CAtlMap<int, Unk_EnchantPtr<BaseOption>, Unk_EnchantKeyTraits> Unk_EsOptionMap;
typedef ATL::CAtlArray<int, ATL::CDefaultElementTraits<int> > Unk_EsKeyArray;

static int FUN_140f3e920(const Unk_EsKeyArray& arr, const int& nValue)
{
    for (int i = 0; i < (int)arr.GetCount(); i++) {
        if (arr[i] == nValue)
            return i;
    }
    return -1;
}

// ---- the packet readers: the option rows of the movie ----

// @0x140f3b490
UIEnchantScrollDialog::UIEnchantScrollDialog()
{
    FUN_141924170(1);
    m_164 = 1;
}

// @0x140f3b530
CString UIEnchantScrollDialog::GetTypeName()
{
    return CString("EnchantScrollDialog");
}

// @0x140f3b580
int UIEnchantScrollDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140f3b5b0
void UIEnchantScrollDialog::vfunc_67()
{
    FUN_140f3d210();
    FUN_140cd74a0(GetTypeName());
    UIDialog::vfunc_67();
}

// @0x140f3b620
void UIEnchantScrollDialog::vfunc_72()
{
    vfunc_55();
}

// @0x140f3b650
void UIEnchantScrollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140f3cb10();
}

// @0x140f3b680
int UIEnchantScrollDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onEnchant") == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0) {
            unsigned __int64 nItemUid = FUN_140718370(data.FUN_1422b8f40());
            MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(nItemUid);
            if (((void*)((MS2Ptr<CItem>*)(void*)(&spItem))->get()) != 0) {
                COutPacket packet(static_cast<int>(SendOp::EnchantScroll), 0);
                packet.Encode1(2);
                packet.Encode8(m_nScrollUid);
                packet.Encode8(nItemUid);
                FUN_140710590(packet);
            }
        }
    }
    return 0;
}

// @0x140f3b810
void UIEnchantScrollDialog::vfunc_15()
{
}

// @0x140f3b820
int UIEnchantScrollDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0) {
        FUN_14151f200();
        int nResult = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0 && strTag == L"enchant_ok") {
            vfunc_67();
            return 1;
        }
    }
    return 0;
}

// @0x140f3b920
void UIEnchantScrollDialog::FUN_140f3b920(CInPacket& packet)
{
    FUN_140f3d210();
    m_nScrollUid = packet.ReadInt64();
    m_nType = (unsigned short)packet.ReadInt16();
    m_bDisableBreak = packet.ReadUInt8() != 0;
    m_nTargetLevel = packet.ReadInt32();
    m_nFailRate = packet.ReadInt32();
    m_nLevelMin = packet.ReadInt16();
    m_nLevelMax = packet.ReadInt16();
    int nCount = packet.ReadInt32();
    for (int i = 0; i < nCount; i++)
        m_equipTypes.Add(packet.ReadInt32());
    nCount = packet.ReadInt32();
    for (int j = 0; j < nCount; j++)
        m_ranks.Add((Unk_EsRank)packet.ReadInt32());
    if (m_nType == 3) {
        m_nRandomMin = packet.ReadInt32();
        m_nRandomMax = packet.ReadInt32();
    }
    m_nFailRate /= 100;
    if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ee0))))
        FUN_140f3cb10();
    else
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4ee0)));
}

// @0x140f3bd10
void UIEnchantScrollDialog::FUN_140f3bd10(CInPacket& packet)
{
    m_nItemUid = packet.ReadInt64();
    int nType = (unsigned short)packet.ReadInt16();
    MS2Ptr<CItem> spScroll = g_143ab2a90.FUN_140a5d680(m_nScrollUid);
    MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(m_nItemUid);
    if ((((void*)((MS2Ptr<CItem>*)(void*)(&spItem))->get()) ? true : false) && (((void*)((MS2Ptr<CItem>*)(void*)(&spScroll))->get()) ? true : false)) {
        FUN_140cd74a0(GetTypeName());
        FUN_140cd73b0(GetTypeName(), m_nScrollUid, spItem);
        ASObj data(2);
        data.FUN_140f3f020("scrollType", m_nType);
        data.FUN_1407cbb20("itemGUID", FUN_141b71910(spItem->GetItemUid()));
        data.FUN_1407cba60("bindID", GetTypeName());
        data.FUN_1407cb9c0("ready", 1);
        data.FUN_1407cbb20("itemName", FUN_140f3d320(spItem->FUN_140526fc0(), spItem, spItem->FUN_140527030(), 0));
        data.FUN_1407cbb20("desc", FUN_140f3e550(spScroll));
        switch (nType) {
        case 1:
        case 2:
            data.FUN_1407cbb20("prop", BlockFormat(0xb70, m_nFailRate, 100 - m_nFailRate));
            data.FUN_1407cbb20("resultItemName", FUN_140f3d320(m_nTargetLevel, spItem, 0, 0));
            if (spItem->FUN_140526fc0() != m_nTargetLevel)
                FUN_140f3d5b0(spItem, data, packet);
            break;
        case 5:
            data.FUN_1407cbb20("prop", BlockFormat(0xb70, m_nFailRate, 100 - m_nFailRate));
            data.FUN_1407cbb20("resultItemName", FUN_140f3d320(spItem->FUN_140526fc0(), spItem, 0, 1));
            break;
        case 3: {
            CStringW strRank = TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)spItem->GetRarity());
            CStringW strName = BlockFormat(0xb6e, strRank, FUN_140f3e390(), TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->FUN_1405276c0()));
            data.FUN_1407cbb20("resultItemName", strName);
            FUN_140f3db20(spItem, data, packet);
            break;
        }
        }
        ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("setData", data);
    }
}

// @0x140f3c6c0
void UIEnchantScrollDialog::FUN_140f3c6c0(CInPacket& packet)
{
    int nResult = (unsigned short)packet.ReadInt16();
    if (nResult == 0) {
        unsigned __int64 nItemUid = packet.ReadInt64();
        MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem.IsNull())
            return;
        spItem->FUN_140524eb0(packet);
        UIInventoryDialog* pInventory = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
        if (pInventory != 0)
            pInventory->FUN_141999e00();
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x11, 0xb71, static_cast<IMessageListener*>(this), L"enchant_ok");
        if (spBox.get()) {
            // The box methods live on the derived box; the downcast is offset 0 (no code).
            spBox.operator->()->FUN_141a01600(nItemUid);
            spBox.operator->()->FUN_141a024a0(0);
            spBox.operator->()->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
            spBox.operator->()->SetButtonLabelIds(0x475, 0, 0);
            FUN_140d73c60(spBox);
        }
    }
    else {
        switch (nResult) {
        case 1: FUN_141275260(0xb72, 1, 1); break;
        case 2: FUN_141275260(0xb73, 1, 1); break;
        case 3: FUN_141275260(0xb74, 1, 1); break;
        case 4: FUN_141275260(0xb75, 1, 1); break;
        case 6: FUN_141275260(0xb77, 1, 1); break;
        case 5: FUN_141275260(0xb76, 1, 1); break;
        case 7: FUN_141275260(0xb78, 1, 1); break;
        case 8: FUN_141275260(0xb79, 1, 1); break;
        }
        if (nResult == 1)
            vfunc_67();
    }
}

// @0x140f3cb10
void UIEnchantScrollDialog::FUN_140f3cb10()
{
    FUN_140cd74a0(GetTypeName());
    FUN_140cd73b0(GetTypeName(), m_nScrollUid, MS2Ptr<CItem>(0));
    MS2Ptr<CItem> spScroll = g_143ab2a90.FUN_140a5d680(m_nScrollUid);
    if ((((MS2Ptr<AScript>*)(void*)(&m_30))->get() ? true : false) && (((void*)((MS2Ptr<CItem>*)(void*)(&spScroll))->get()) ? true : false)) {
        CStringW strLevel;
        CStringW strTypes;
        CStringW strRanks;
        if (m_nLevelMin == m_nLevelMax)
            strLevel = StringFormat(L"{0}", m_nLevelMin);
        else
            strLevel = StringFormat(L"{0}~{1}", m_nLevelMin, m_nLevelMax);
        for (size_t i = 0; i < m_ranks.GetCount(); i++) {
            unsigned nRank = m_ranks[i];
            CStringW strRank = FUN_14183e9c0(TSingleton<CStringTable>::GetInstance()->GetRankName(nRank), nRank);
            strRanks.AppendFormat(L"%s, ", (LPCWSTR)strRank);
        }
        strRanks.TrimRight(L", ");
        for (size_t i = 0; i < m_equipTypes.GetCount(); i++)
            strTypes.AppendFormat(L"%s, ", (LPCWSTR)TSingleton<CStringTable>::GetInstance()->FUN_141811980(8, m_equipTypes[i]));
        strTypes.TrimRight(L", ");
        ASObj data(2);
        data.FUN_1407cbb20("itemGUID", FUN_141b71910(0));
        data.FUN_140f3f020("scrollType", m_nType);
        data.FUN_1407cba60("bindID", GetTypeName());
        data.FUN_1407cb9c0("ready", 0);
        data.FUN_1407cbb20("desc", FUN_140f3e550(spScroll));
        data.FUN_1407cbb20("limit", BlockFormat(0xb6d, strLevel, strRanks, strTypes));
        data.FUN_1407cbb20("failDesc", FUN_140f3e730());
        ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("setData", data);
    }
}

// @0x140f3d210
void UIEnchantScrollDialog::FUN_140f3d210()
{
    m_nTargetLevel = 0;
    m_nFailRate = 0;
    m_nScrollUid = 0;
    m_nItemUid = 0;
    m_bDisableBreak = false;
    m_nLevelMin = 0;
    m_nLevelMax = 0;
    m_equipTypes.RemoveAll();
    m_ranks.RemoveAll();
    m_nRandomMin = 0;
    m_nRandomMax = 0;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
        ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("clear");
}

// @0x140f3d320
CStringW UIEnchantScrollDialog::FUN_140f3d320(int nLevel, MS2Ptr<CItem> spItem, int bStable, int bRandom)
{
    CStringW strRank = TSingleton<CItemDataTable>::GetInstance()->GetTextColorString((ItemGradeKey)spItem->GetRarity());
    CStringW strName = FUN_14028dee0(0xb6e, strRank, nLevel, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->FUN_1405276c0()));
    if (bStable)
        strName += L" " + GetStringCommon(0xb6f);
    else if (bRandom)
        strName += L" " + GetStringCommonByKey(L"s_enchantscroll_stable");
    return strName;
}

// @0x140f3d5b0
void UIEnchantScrollDialog::FUN_140f3d5b0(MS2Ptr<CItem> spItem, ASObj& rData, CInPacket& packet)
{
    size_t nCount = (unsigned)packet.ReadInt32();
    Unk_EsOptionMap map(17, 0.75f, 0.25f, 2.25f, 10);
    for (size_t i = 0; i < nCount; i++) {
        Unk_EnchantPtr<BaseOption> spOpt(new BaseOption());
        int nKey = (unsigned short)packet.ReadInt16();
        spOpt->SetValue(packet.ReadInt32());
        map.SetAt(nKey, spOpt);
    }
    ASArray list(2);
    for (POSITION pos = map.GetStartPosition(); pos != 0; map.GetNext(pos)) {
        unsigned nKey = map.GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spOpt = map.GetValueAt(pos);
        if (!spOpt)
            continue;
        if (spOpt->HasValue()) {
            ASObj obj(2);
            __int64 nBase = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->GetStatValue(nKey, 0, 0);
            float fExtra = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->GetEnchantRatio(nKey);
            float fRate = spOpt->FUN_140266e10();
            __int64 nBefore = FUN_140632990(nBase, fExtra);
            __int64 nAfter = FUN_140632990(nBase, fExtra + fRate);
            CStringW strBefore = StringFormat(L"{0}", nBefore);
            CStringW strAfter = StringFormat(L"{0}", nAfter);
            CStringW strName = GetStatValueText(nKey);
            strName.Replace(L"{0}", L"");
            obj.FUN_1407cbb20("statName", strName);
            obj.FUN_1407cbb20("prevStat", strBefore);
            obj.FUN_1407cbb20("afterStat", strAfter);
            list.PushValue(obj.FUN_1422bb870());
        }
    }
    rData.FUN_1409eb1d0("options", list);
}

// @0x140f3db20
void UIEnchantScrollDialog::FUN_140f3db20(MS2Ptr<CItem> spItem, ASObj& rData, CInPacket& packet)
{
    Unk_EsKeyArray keys;
    size_t nLow = (unsigned)packet.ReadInt32();
    Unk_EsOptionMap mapLow(17, 0.75f, 0.25f, 2.25f, 10);
    for (size_t i = 0; i < nLow; i++) {
        Unk_EnchantPtr<BaseOption> spOpt(new BaseOption());
        int nKey = (unsigned short)packet.ReadInt16();
        spOpt->SetValue(packet.ReadInt32());
        mapLow.SetAt(nKey, spOpt);
        if (FUN_140f3e920(keys, nKey) == -1)
            keys.Add(nKey);
    }
    size_t nHigh = (unsigned)packet.ReadInt32();
    Unk_EsOptionMap mapHigh(17, 0.75f, 0.25f, 2.25f, 10);
    for (size_t i = 0; i < nHigh; i++) {
        Unk_EnchantPtr<BaseOption> spOpt(new BaseOption());
        int nKey = (unsigned short)packet.ReadInt16();
        spOpt->SetValue(packet.ReadInt32());
        mapHigh.SetAt(nKey, spOpt);
        if (FUN_140f3e920(keys, nKey) == -1)
            keys.Add(nKey);
    }
    ASArray list(2);
    for (size_t i = 0; i < keys.GetCount(); i++) {
        int nKey = keys.GetAt(i);
        Unk_EnchantPtr<BaseOption> spLow(0);
        Unk_EnchantPtr<BaseOption> spHigh(0);
        if (!mapLow.Lookup(nKey, spLow))
            continue;
        if (!mapHigh.Lookup(nKey, spHigh))
            continue;
        if (spLow->HasValue()) {
            if (spHigh->HasValue()) {
                ASObj obj(2);
                __int64 nBase = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->GetStatValue(nKey, 0, 0);
                float fExtra = reinterpret_cast<CItemStatus*>(spItem->FUN_1405278a0())->GetEnchantRatio(nKey);
                float fRateLow = spLow->FUN_140266e10();
                float fRateHigh = spHigh->FUN_140266e10();
                __int64 nBefore = FUN_140632990(nBase, fExtra);
                __int64 nAfterLow = FUN_140632990(nBase, fExtra + fRateLow);
                __int64 nAfterHigh = FUN_140632990(nBase, fExtra + fRateHigh);
                CStringW strBefore = StringFormat(L"{0}", nBefore);
                CStringW strAfter = StringFormat(L"{0}~{1}", nAfterLow, nAfterHigh);
                CStringW strName = GetStatValueText(nKey);
                strName.Replace(L"{0}", L"");
                obj.FUN_1407cbb20("statName", strName);
                obj.FUN_1407cbb20("prevStat", strBefore);
                obj.FUN_1407cbb20("afterStat", strAfter);
                list.PushValue(obj.FUN_1422bb870());
            }
        }
    }
    rData.FUN_1409eb1d0("options", list);
}

// @0x140f3e390
CStringW UIEnchantScrollDialog::FUN_140f3e390()
{
    CStringW strText;
    switch (m_nType) {
    case 1:
    case 2:
        return StringFormat(L"{0}", m_nTargetLevel);
    case 3:
        return StringFormat(L"{0}~{1}", m_nRandomMin, m_nRandomMax);
    case 5: {
        MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(m_nItemUid);
        if (((void*)((MS2Ptr<CItem>*)(void*)(&spItem))->get()) != 0)
            return StringFormat(L"{0}", spItem->FUN_140526fc0());
    }
    }
    return L"";
}

// @0x140f3e550
CStringW UIEnchantScrollDialog::FUN_140f3e550(MS2Ptr<CItem> spItem)
{
    int nId = 0;
    switch (m_nType) {
    case 1:
        nId = 0xb69;
        break;
    case 2:
        nId = 0xb6a;
        break;
    case 3:
        nId = 0xb6c;
        break;
    case 5:
        nId = 0xb6b;
        break;
    }
    CStringW strDesc = FormatStringId(nId, spItem->FUN_140528160(), FUN_140f3e390());
    if (m_bDisableBreak)
        strDesc += GetStringCommonByKey(L"s_enchantscroll_desc_disable_break");
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strDesc);
    return strDesc;
}

// @0x140f3e730
CStringW UIEnchantScrollDialog::FUN_140f3e730()
{
    switch (m_nType) {
    case 1:
        return GetStringCommonByKey(L"s_enchant_fail_desc_enchant");
        break;
    case 2:
        return GetStringCommonByKey(L"s_enchant_fail_desc_restore");
        break;
    case 3:
        return FUN_14028dfa0<unsigned int, unsigned int>(L"s_enchant_fail_desc_random", m_nRandomMin, m_nRandomMax);
        break;
    case 5:
        return GetStringCommonByKey(L"s_enchant_fail_desc_repair");
    }
    return L"";
}

// @0x140f3f4a0
int UIEnchantScrollDialog::vfunc_48()
{
    return 0x4ee0;
}

// @0x140f3f020
void ASObj::FUN_140f3f020(const char* szName, int n)
{
    ASData data;
    data.AddInt(n);
    ((Scaleform::GFx::Value*)(void*)(&m_value))->SetMember(szName, data.PopValue());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9410-0x142ca9560 .text$yd
