// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIEnchantScrollDialog: the item enchant scroll window. See uienchantscrolldialog.h.
// MS2-UNIT: ?\uienchantscrolldialog.cpp
// MS2-GUESS-LOOKALIKES (the CAtlArray<unsigned> / MS2Ptr accessor glue is byte-identical to other instances)
// MS2-RANGE: 0x140f3b490-0x140f3fb10 .text$mn
// MS2-RANGE: 0x1400deeb0-0x1400df250 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0UIEnchantScrollDialog@@QEAA@XZ 0x140f3b490 ; unique
// MS2-PIN: ?FUN_140f3e920@@YAHAEBV?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@AEBI@Z 0x140f3e920 ; unique
// MS2-PIN: ??1UIEnchantScrollDialog@@UEAA@XZ 0x140f3f140 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@CAXPEAI_K@Z 0x140f3f370 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAAXXZ 0x140f3f690 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAA_N_KH@Z 0x140f3f6d0 ; unique
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
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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
class Unk_EsInventory { public: MS2Ptr<CItem> FUN_140a5d680(unsigned __int64 uid); };
extern Unk_EsInventory DAT_143ab2a90;

// The enchant data of an item (CItem::FUN_1405278a0).
class Unk_EsEnchantData
{
public:
    int FUN_14062ffb0(unsigned key, int a, int b);
    float FUN_1406303e0(unsigned key);
};

// The AS root object of the movie: only the call by name is used here.
class Unk_EsAS : public AScript { public: Scaleform::GFx::Value FUN_140ba4cc0(const char* szMethod, const ASObj& rArg); };
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
AScript* FUN_1409ee240(MS2Ptr<AScript>* p);

class Unk_EsUiMgr { public: int FUN_141adc890(int uiId); void FUN_141adc530(int uiId); };
Unk_EsUiMgr* FUN_1403ed2b0();

class Unk_EsStrings { public: CStringW FUN_141813150(int nId); CStringW FUN_141811980(int nTable, int nId); };
Unk_EsStrings* FUN_1401a9d70();
class Unk_EsIngTable { public: CStringW FUN_140556a40(int nId); };
Unk_EsIngTable* FUN_140281980();
class Unk_EsTextFilter { public: void FUN_1416fb340(CStringW& strText); };
Unk_EsTextFilter* FUN_1403b4750();
class Unk_EsInvDialog { public: void FUN_141999e00(); };
Unk_EsInvDialog* FUN_1405344f0(int uiId);

CStringW FUN_14082f090(unsigned nKey);                                              // option name template
__int64 FUN_140632990(__int64 nBase, float fExtra);                                 // the option value
CStringW FUN_14183e9c0(CStringW strText, int nRank);                                // rank-coloured text
CStringW FUN_140632a60(int nId, const CStringW& strA, const CStringW& strB);
CStringW FUN_1409e9bc0(int nId, const int& nA, const int& nB);
CStringW FUN_1409eadb0(int nId, const CStringW& strA, const CStringW& strB, const CStringW& strC);
CStringW FUN_1409e9890(CStringW strKey, const unsigned& nA, const unsigned& nB);
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nId);
CStringW FUN_1401d0160(const wchar_t* psz, const CStringW& str);                   // psz + str
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);
void FUN_14151f200();
unsigned __int64 FUN_140718370(const CStringW& str);
void FUN_140710590(COutPacket& packet);
void FUN_141275260(int nId, int a, int b);                                          // system message by string id
void FUN_141276180(const CString& strSound, const CString& strArg);
void* FUN_14052cd70(const MS2Ptr<CItem>* pItem);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* pListener, CStringW strTag);
class Unk_EsMsgBox : public CMsgBoxData
{
public:
    void FUN_141a01600(__int64 nUid);
    void FUN_141a024a0(int n);
    void FUN_141a01ee0(MS2Ptr<CItem> spItem, const CStringW& strName, int nA, int nB, int nC, int nD, int nE);
    void FUN_141a01700(int nA, int nB, int nC);
};
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

void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
CStringW FUN_141b71910(__int64 n);

typedef ATL::CAtlMap<int, Unk_EnchantPtr<BaseOption>, Unk_EnchantKeyTraits> Unk_EsOptionMap;

static int FUN_140f3e920(const ATL::CAtlArray<unsigned>& arr, const unsigned& nValue)
{
    for (int i = 0; i < (int)arr.GetCount(); i++) {
        if (arr[i] == nValue)
            return i;
    }
    return -1;
}

// ---- the packet readers: the option rows of the movie ----

// Reads the options of the packet (a short key, an int value) into a map.
static __forceinline void ReadOptions(CInPacket& packet, Unk_EsOptionMap& rMap)
{
    unsigned nCount = packet.vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++) {
        Unk_EnchantPtr<BaseOption> spOpt(new BaseOption());
        unsigned nKey = (unsigned short)packet.vfunc_o8_2();
        spOpt->SetValue(packet.vfunc_o8_3());
        rMap.SetAt(nKey, spOpt);
    }
}

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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            unsigned __int64 nItemUid = FUN_140718370(data.FUN_1422b8f40());
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
            if (FUN_14052cd70(&spItem) != 0) {
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
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0 && FUN_1403b3c40(strTag, L"enchant_ok") != 0) {
            vfunc_67();
            return 1;
        }
    }
    return 0;
}

// @0x140f3b920
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIEnchantScrollDialog::FUN_140f3b920(CInPacket& packet)
{
    FUN_140f3d210();
    m_nScrollUid = packet.vfunc_o8_4();
    m_nType = (unsigned short)packet.vfunc_o8_2();
    m_bDisableBreak = packet.vfunc_o8_1() != 0;
    m_nTargetLevel = packet.vfunc_o8_3();
    m_nFailRate = packet.vfunc_o8_3();
    m_nLevelMin = packet.vfunc_o8_2();
    m_nLevelMax = packet.vfunc_o8_2();
    int nTypes = packet.vfunc_o8_3();
    for (int i = 0; i < nTypes; i++)
        m_equipTypes.Add(packet.vfunc_o8_3());
    int nRanks = packet.vfunc_o8_3();
    for (int i = 0; i < nRanks; i++)
        m_ranks.Add((Unk_EsRank)packet.vfunc_o8_3());
    if (m_nType == 3) {
        m_nRandomMin = packet.vfunc_o8_3();
        m_nRandomMax = packet.vfunc_o8_3();
    }
    unsigned nFail = m_nFailRate;
    m_nFailRate = nFail / 100;
    if (FUN_1403ed2b0()->FUN_141adc890(0x4ee0) == 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4ee0);
    else
        FUN_140f3cb10();
}

// @0x140f3bd10
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIEnchantScrollDialog::FUN_140f3bd10(CInPacket& packet)
{
    m_nItemUid = packet.vfunc_o8_4();
    unsigned nType = (unsigned short)packet.vfunc_o8_2();
    MS2Ptr<CItem> spScroll = DAT_143ab2a90.FUN_140a5d680(m_nScrollUid);
    MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (FUN_14052cd70(&spItem) == 0 || FUN_14052cd70(&spScroll) == 0)
        return;
    FUN_140cd74a0(GetTypeName());
    FUN_140cd73b0(GetTypeName(), m_nScrollUid, spItem);
    ASObj data(2);
    data.FUN_140f3f020("scrollType", m_nType);
    data.FUN_1407cbb20("itemGUID", FUN_141b71910(spItem->FUN_140526a50()));
    data.FUN_1407cba60("bindID", GetTypeName());
    data.FUN_1407cb9c0("ready", 1);
    data.FUN_1407cbb20("itemName", FUN_140f3d320(spItem->FUN_140527030(), spItem, 0, 0));
    data.FUN_1407cbb20("desc", FUN_140f3e550(spItem));
    if ((int)nType > 0) {
        if ((int)nType < 3) {
            data.FUN_1407cbb20("prop", FUN_1409e9bc0(0xb70, m_nFailRate, 100 - m_nFailRate));
            data.FUN_1407cbb20("resultItemName", FUN_140f3d320(m_nTargetLevel, spItem, 0, 0));
            if (spItem->FUN_140526fc0() != m_nTargetLevel)
                FUN_140f3d5b0(spItem, data, packet);
        }
        else if (nType == 3) {
            CStringW strRank = FUN_140281980()->FUN_140556a40(spItem->FUN_140526bd0());
            CStringW strType = FUN_1401a9d70()->FUN_141811980(1, spItem->FUN_1405276c0());
            data.FUN_1407cbb20("resultItemName", FUN_1409eadb0(0xb6e, strRank, FUN_140f3e390(), strType));
            FUN_140f3db20(spItem, data, packet);
        }
        else if (nType == 5) {
            data.FUN_1407cbb20("prop", FUN_1409e9bc0(0xb70, m_nFailRate, 100 - m_nFailRate));
            data.FUN_1407cbb20("resultItemName", FUN_140f3d320(spItem->FUN_140526fc0(), spItem, 0, 1));
        }
    }
    static_cast<Unk_EsAS*>(FUN_1409ee290(&m_30))->FUN_140ba4cc0("setData", data);
}

// @0x140f3c6c0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIEnchantScrollDialog::FUN_140f3c6c0(CInPacket& packet)
{
    short nResult = packet.vfunc_o8_2();
    if (nResult == 0) {
        unsigned __int64 nItemUid = packet.vfunc_o8_4();
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (FUN_14052cd70(&spItem) == 0) {
            spItem->FUN_140524eb0(packet);
            Unk_EsInvDialog* pInventory = FUN_1405344f0(0x4e2d);
            if (pInventory != 0)
                pInventory->FUN_141999e00();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x11, 0xb71, static_cast<IMessageListener*>(this), CStringW(L"enchant_ok"));
            if (spBox.get() != 0) {
                Unk_EsMsgBox* pBox = static_cast<Unk_EsMsgBox*>(spBox.get());
                pBox->FUN_141a01600(nItemUid);
                pBox->FUN_141a024a0(0);
                pBox->FUN_141a01ee0(spItem, spItem->FUN_140527b10(), 1, 0, -1, -1, 1);
                pBox->FUN_141a01700(0x475, 0, 0);
                FUN_140d73c60(spBox);
            }
        }
    }
    else {
        switch (nResult) {
        case 1: FUN_141275260(0xb72, 1, 1); break;
        case 2: FUN_141275260(0xb73, 1, 1); break;
        case 3: FUN_141275260(0xb74, 1, 1); break;
        case 4: FUN_141275260(0xb75, 1, 1); break;
        case 5: FUN_141275260(0xb76, 1, 1); break;
        case 6: FUN_141275260(0xb77, 1, 1); break;
        case 7: FUN_141275260(0xb78, 1, 1); break;
        case 8: FUN_141275260(0xb79, 1, 1); break;
        }
        if (nResult == 1)
            vfunc_67();
    }
}

// @0x140f3cb10
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIEnchantScrollDialog::FUN_140f3cb10()
{
    FUN_140cd74a0(GetTypeName());
    FUN_140cd73b0(GetTypeName(), m_nScrollUid, MS2Ptr<CItem>(0));
    MS2Ptr<CItem> spScroll = DAT_143ab2a90.FUN_140a5d680(m_nScrollUid);
    if (FUN_1409ee240(&m_30) != 0 && FUN_14052cd70(&spScroll) != 0) {
        CStringW strLevel;
        CStringW strTypes;
        CStringW strRanks;
        if (m_nLevelMin == m_nLevelMax)
            strLevel = StringFormat(L"{0}", m_nLevelMin);
        else
            strLevel = StringFormat(L"{0}~{1}", m_nLevelMin, m_nLevelMax);
        for (size_t i = 0; i < m_ranks.GetCount(); i++) {
            unsigned nRank = m_ranks[i];
            strRanks.AppendFormat(L"%s, ", (LPCWSTR)FUN_14183e9c0(FUN_1401a9d70()->FUN_141813150(nRank), nRank));
        }
        strRanks.TrimRight(L", ");
        for (size_t i = 0; i < m_equipTypes.GetCount(); i++)
            strTypes.AppendFormat(L"%s, ", (LPCWSTR)FUN_1401a9d70()->FUN_141811980(8, m_equipTypes[i]));
        strTypes.TrimRight(L", ");
        ASObj data(2);
        data.FUN_1407cbb20("itemGUID", FUN_141b71910(0));
        data.FUN_140f3f020("scrollType", m_nType);
        data.FUN_1407cba60("bindID", GetTypeName());
        data.FUN_1407cb9c0("ready", 0);
        data.FUN_1407cbb20("itemName", FUN_140f3e550(spScroll));
        data.FUN_1407cbb20("limit", FUN_1409eadb0(0xb6d, strLevel, strRanks, strTypes));
        data.FUN_1407cbb20("failDesc", FUN_140f3e730());
        static_cast<Unk_EsAS*>(FUN_1409ee290(&m_30))->FUN_140ba4cc0("setData", data);
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
    if (FUN_1409ee240(&m_30) != 0)
        FUN_1409ee290(&m_30)->Invoke("clear");
}

// @0x140f3d320
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
CStringW UIEnchantScrollDialog::FUN_140f3d320(int nLevel, MS2Ptr<CItem> spItem, int bStable, int bRandom)
{
    CStringW strRank = FUN_140281980()->FUN_140556a40(spItem->FUN_140526bd0());
    CStringW strType = FUN_1401a9d70()->FUN_141811980(1, spItem->FUN_1405276c0());
    CStringW strName = FUN_14028dee0(0xb6e, strRank, nLevel, strType);
    if (bStable == 0) {
        if (bRandom != 0)
            strName += FUN_1401d0160(L" ", GetStringCommonByKey(CStringW(L"s_enchantscroll_stable")));
    }
    else {
        strName += FUN_1401d0160(L" ", GetStringCommon(0xb6f));
    }
    return strName;
}

// @0x140f3d5b0
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIEnchantScrollDialog::FUN_140f3d5b0(MS2Ptr<CItem> spItem, ASObj& rData, CInPacket& packet)
{
    Unk_EsOptionMap map(17, 0.75f, 0.25f, 2.25f, 10);
    ReadOptions(packet, map);
    ASArray list(2);
    POSITION pos = map.GetStartPosition();
    while (pos != 0) {
        unsigned nKey = map.GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spOpt = map.GetValueAt(pos);
        if (!(!spOpt)) {
            if (spOpt->HasValue()) {
                ASObj obj(2);
                Unk_EsEnchantData* pData = reinterpret_cast<Unk_EsEnchantData*>(spItem->FUN_1405278a0());
                __int64 nBase = pData->FUN_14062ffb0(nKey, 0, 0);
                float fExtra = reinterpret_cast<Unk_EsEnchantData*>(spItem->FUN_1405278a0())->FUN_1406303e0(nKey);
                float fRate = spOpt->FUN_140266e10();
                __int64 nBefore = FUN_140632990(nBase, fExtra);
                __int64 nAfter = FUN_140632990(nBase, fExtra + fRate);
                CStringW strBefore = StringFormat(L"{0}", nBefore);
                CStringW strAfter = StringFormat(L"{0}", nAfter);
                CStringW strName = FUN_14082f090(nKey);
                strName.Replace(L"{0}", L"");
                obj.FUN_1407cbb20("statName", strName);
                obj.FUN_1407cbb20("prevStat", strBefore);
                obj.FUN_1407cbb20("afterStat", strAfter);
                list.FUN_1422bc050(obj.FUN_1422bb870());
            }
        }
        map.GetNext(pos);
    }
    rData.FUN_1409eb1d0("options", list);
}

// @0x140f3db20
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
void UIEnchantScrollDialog::FUN_140f3db20(MS2Ptr<CItem> spItem, ASObj& rData, CInPacket& packet)
{
    ATL::CAtlArray<unsigned> keys;
    Unk_EsOptionMap mapLow(17, 0.75f, 0.25f, 2.25f, 10);
    unsigned nLow = packet.vfunc_o8_3();
    for (unsigned i = 0; i < nLow; i++) {
        Unk_EnchantPtr<BaseOption> spOpt(new BaseOption());
        unsigned nKey = (unsigned short)packet.vfunc_o8_2();
        spOpt->SetValue(packet.vfunc_o8_3());
        mapLow.SetAt(nKey, spOpt);
        if (FUN_140f3e920(keys, nKey) == -1)
            keys.Add(nKey);
    }
    Unk_EsOptionMap mapHigh(17, 0.75f, 0.25f, 2.25f, 10);
    unsigned nHigh = packet.vfunc_o8_3();
    for (unsigned i = 0; i < nHigh; i++) {
        Unk_EnchantPtr<BaseOption> spOpt(new BaseOption());
        unsigned nKey = (unsigned short)packet.vfunc_o8_2();
        spOpt->SetValue(packet.vfunc_o8_3());
        mapHigh.SetAt(nKey, spOpt);
        if (FUN_140f3e920(keys, nKey) == -1)
            keys.Add(nKey);
    }
    ASArray list(2);
    for (size_t i = 0; i < keys.GetCount(); i++) {
        unsigned nKey = keys.GetAt(i);
        Unk_EnchantPtr<BaseOption> spLow(0);
        Unk_EnchantPtr<BaseOption> spHigh(0);
        if (!mapLow.Lookup(nKey, spLow))
            continue;
        if (!mapHigh.Lookup(nKey, spHigh))
            continue;
        if (spLow->HasValue()) {
            if (spHigh->HasValue()) {
                ASObj obj(2);
                Unk_EsEnchantData* pData = reinterpret_cast<Unk_EsEnchantData*>(spItem->FUN_1405278a0());
                __int64 nBase = pData->FUN_14062ffb0(nKey, 0, 0);
                float fExtra = reinterpret_cast<Unk_EsEnchantData*>(spItem->FUN_1405278a0())->FUN_1406303e0(nKey);
                float fRateLow = spLow->FUN_140266e10();
                float fRateHigh = spHigh->FUN_140266e10();
                __int64 nBefore = FUN_140632990(nBase, fExtra);
                __int64 nAfterLow = FUN_140632990(nBase, fExtra + fRateLow);
                __int64 nAfterHigh = FUN_140632990(nBase, fExtra + fRateHigh);
                CStringW strBefore = StringFormat(L"{0}", nBefore);
                CStringW strAfter = StringFormat(L"{0}~{1}", nAfterLow, nAfterHigh);
                CStringW strName = FUN_14082f090(nKey);
                strName.Replace(L"{0}", L"");
                obj.FUN_1407cbb20("statName", strName);
                obj.FUN_1407cbb20("prevStat", strBefore);
                obj.FUN_1407cbb20("afterStat", strAfter);
                list.FUN_1422bc050(obj.FUN_1422bb870());
            }
        }
    }
    rData.FUN_1409eb1d0("options", list);
}

// @0x140f3e390
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
CStringW UIEnchantScrollDialog::FUN_140f3e390()
{
    CStringW strText;
    if (m_nType > 0) {
        if (m_nType < 3)
            return StringFormat(L"{0}", m_nTargetLevel);
        if (m_nType == 3)
            return StringFormat(L"{0}~{1}", m_nRandomMin, m_nRandomMax);
        if (m_nType == 5) {
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
            if (FUN_14052cd70(&spItem) != 0)
                return StringFormat(L"{0}", spItem->FUN_140526fc0());
        }
    }
    return strText;
}

// @0x140f3e550
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
CStringW UIEnchantScrollDialog::FUN_140f3e550(MS2Ptr<CItem> spItem)
{
    int nId = 0;
    if (m_nType == 1)
        nId = 0xb69;
    else if (m_nType == 2)
        nId = 0xb6a;
    else if (m_nType == 3)
        nId = 0xb6c;
    else if (m_nType == 5)
        nId = 0xb6b;
    CStringW strDesc = FUN_140632a60(nId, spItem->FUN_140528160(), FUN_140f3e390());
    if (m_bDisableBreak)
        strDesc += GetStringCommonByKey(CStringW(L"s_enchantscroll_desc_disable_break"));
    FUN_1403b4750()->FUN_1416fb340(strDesc);
    return strDesc;
}

// @0x140f3e730
// MS2-FUNCTIONAL: not byte-exact yet (temporaries / call order differ)
CStringW UIEnchantScrollDialog::FUN_140f3e730()
{
    if (m_nType == 1)
        return GetStringCommonByKey(CStringW(L"s_enchant_fail_desc_enchant"));
    if (m_nType == 2)
        return GetStringCommonByKey(CStringW(L"s_enchant_fail_desc_restore"));
    if (m_nType == 3)
        return FUN_1409e9890(CStringW(L"s_enchant_fail_desc_random"), m_nRandomMin, m_nRandomMax);
    if (m_nType == 5)
        return GetStringCommonByKey(CStringW(L"s_enchant_fail_desc_repair"));
    return CStringW(L"");
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
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9410-0x142ca9560 .text$yd
