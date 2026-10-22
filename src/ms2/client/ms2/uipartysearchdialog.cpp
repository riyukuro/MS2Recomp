// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Party search window ("PartySearchDialog"). See uipartysearchdialog.h.
// MS2-UNIT: ?\uipartysearchdialog.cpp
// MS2-RANGE: 0x140f8c480-0x140f90780 .text$mn
// MS2-RANGE: 0x1400e0d70-0x1400e0ee0 .text$di
// MS2-RANGE: 0x142caa080-0x142caa110 .text$yd
// MS2-PIN: ??$forward@_K@std@@YA$$QEA_KAEA_K@Z 0x140f8fac0
// MS2-PIN: ??A?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAAAEAU?$pair@HH@std@@_K@Z 0x140f90000
// MS2-PIN: ??A?$CAtlArray@U?$pair@HI@std@@V?$CElementTraits@U?$pair@HI@std@@@ATL@@@ATL@@QEAAAEAU?$pair@HI@std@@_K@Z 0x140f90000
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCMatchPartyRecruit@@@@AEBAXPEAX@Z 0x140f90570
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0HH$0A@@?$pair@HH@std@@QEAA@$$QEAH0@Z 0x140f8f7b0 ; unique
// MS2-PIN: ??$?0HI$0A@@?$pair@HI@std@@QEAA@$$QEAH$$QEAI@Z 0x140f8f800 ; unique
// MS2-PIN: ??$forward@H@std@@YA$$QEAHAEAH@Z 0x140f8fab0 ; prop
// MS2-PIN: ??$forward@I@std@@YA$$QEAIAEAI@Z 0x140f8fad0 ; prop
// MS2-PIN: ??0?$CAtlArray@U?$pair@HI@std@@V?$CElementTraits@U?$pair@HI@std@@@ATL@@@ATL@@QEAA@XZ 0x140f8fb20 ; unique
// MS2-PIN: ??1?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAA@XZ 0x140f8fbf0 ; order
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCMatchPartyRecruitSchCond@@@@QEAAAEAV1@PEAVCMatchPartyRecruitSchCond@@@Z 0x140f8fca0 ; unique
// MS2-PIN: ??7?$MS2Ptr@VAScript@@@@QEBA_NXZ 0x140f8fd10 ; order
// MS2-PIN: ??7?$MS2Ptr@VCMatchPartyRecruitSchCond@@@@QEBA_NXZ 0x140f8fd40 ; order
// MS2-PIN: ??C?$MS2Ptr@VCMatchPartyRecruitSchCond@@@@QEBAPEAVCMatchPartyRecruitSchCond@@XZ 0x140f8fd80 ; unique
// MS2-PIN: ??D?$MS2Ptr@VCMatchPartyRecruitSchCond@@@@QEBAAEAVCMatchPartyRecruitSchCond@@XZ 0x140f8fd90 ; order
// MS2-PIN: ?Add@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAA_KAEBU?$pair@HH@std@@@Z 0x140f8fde0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@U?$pair@HI@std@@V?$CElementTraits@U?$pair@HI@std@@@ATL@@@ATL@@QEAA_KAEBU?$pair@HI@std@@@Z 0x140f8fe90 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@CAXPEAU?$pair@HH@std@@_K@Z 0x140f8ff80 ; order
// MS2-PIN: ?CallDestructors@?$CAtlArray@U?$pair@HI@std@@V?$CElementTraits@U?$pair@HI@std@@@ATL@@@ATL@@CAXPEAU?$pair@HI@std@@_K@Z 0x140f8ffc0 ; order
// MS2-PIN: ??A?$CAtlArray@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@1@_K@Z 0x140f90040 ; order
// MS2-PIN: ?GetCount@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEBA_KXZ 0x140f900c0 ; order
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VCMatchPartyRecruit@@@@V?$CElementTraits@V?$MS2Ptr@VCMatchPartyRecruit@@@@@ATL@@@ATL@@QEBA_KXZ 0x140f900e0 ; unique
// MS2-PIN: ?vfunc_48@UIPartySearchDialog@@UEAAHXZ 0x140f900f0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@AEAA_N_K@Z 0x140f90100 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@U?$pair@HI@std@@V?$CElementTraits@U?$pair@HI@std@@@ATL@@@ATL@@AEAA_N_K@Z 0x140f902a0 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VCMatchPartyRecruit@@@@QEBA_NXZ 0x140f90440 ; order
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@U?$pair@HH@std@@@ATL@@SAXPEAU?$pair@HH@std@@0_K@Z 0x140f90470 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@U?$pair@HI@std@@@ATL@@SAXPEAU?$pair@HI@std@@0_K@Z 0x140f904b0 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipartysearchdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uipartysearchdialog.h"
#include "partymanager.h"
#include "pcbase.h"
#include "uimessagebox.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <utility>

// ---- unit-local declarations (names describe uses, not original class names) ----

// The search text input of the window.
class Unk_PsdInput : public ASDisplayObject
{
public:
    void FUN_1422e0ab0(const CStringW& strText);
};

// A proxy of another character (what the world service hands out for a character id).
class Unk_PsdProxy : public CPtred
{
};
struct Unk_PsdProxyRef
{
    unsigned char m_pad[0x18];
};
MS2_CHECK_SIZE(Unk_PsdProxyRef, 0x18);
Unk_PsdProxyRef* FUN_140ac58f0(Unk_PsdProxyRef* pDst, const MS2Ptr<Unk_PsdProxy>& src);

class Unk_PsdWorld
{
public:
    void* FUN_141bd0cc0();                                              // the local player
    void FUN_141bc9c60(MS2Ptr<Unk_PsdProxy>* pOut, __int64 nChar);       // the proxy of a character
};
Unk_PsdWorld* FUN_1403ed2d0();

// The UI manager (open / close a dialog by UI id).
class Unk_PsdUIManager
{
public:
    void FUN_141adc530(int nUiId);                                      // open
    void FUN_141adc5d0(int nUiId);                                      // close
};
Unk_PsdUIManager* FUN_1403ed2b0();

// The popup menu on a character (UI id 0x4e39) and its parameter block.
class Unk_PsdMenuInfo
{
public:
    void FUN_140c302f0(float x, float y, int nKind, int nMenuId, int a5, CString strKey, void* p);
    void FUN_140c304c0();
    unsigned char m_pad[0x88];
};
MS2_CHECK_SIZE(Unk_PsdMenuInfo, 0x88);
class Unk_PsdMenu
{
public:
    void FUN_141a7e280(Unk_PsdMenuInfo& info, void* pPlayer, int nType);                    // menu on the local player
    void FUN_141a7eb60(Unk_PsdMenuInfo& info, const Unk_PsdProxyRef* pRef, int nType);      // menu on a visible character
    void FUN_141a7f090(Unk_PsdMenuInfo& info, const CStringW& strName, __int64 nChar, unsigned __int64 nAccount, int nType, int a);   // menu on a name
};
Unk_PsdMenu* FUN_140c30140(int nUiId);

// The chat window: the input line takes the whisper target.
class Unk_PsdChatInput
{
public:
    void FUN_141a252a0(const CStringW& strName);
};
class Unk_PsdChatWindow
{
public:
    unsigned char m_pad_0[0x48];
    Unk_PsdChatInput* m_48;
};
Unk_PsdChatWindow* FUN_141482e80();

// The text filter (bad words) of the search text.
class Unk_PsdFilter : public CPtred
{
public:
    int FUN_140226320(const CStringW& strText, CStringW& strBad);        // nonzero: the text is rejected, strBad = the reason
};
class Unk_PsdFilterMgr
{
public:
    MS2Ptr<Unk_PsdFilter> FUN_140229a50();
};
Unk_PsdFilterMgr* FUN_14025e7d0();

// The blocked-action flags and the keyboard state.
class Unk_PsdFlags
{
public:
    int FUN_1402c4c90(int nFlag);
};
class Unk_PsdConfig
{
public:
    unsigned char m_pad_0[8];
    Unk_PsdFlags m_8;
};
Unk_PsdConfig* FUN_14025e7b0();
class Unk_PsdKeys
{
public:
    bool FUN_14116d9c0(int nKey, int a, int b);
};
Unk_PsdKeys* FUN_14025e7c0();

// The key event of vfunc_79: a base with the key code and a second base (+8) whose slot 1 tells "repeated".
class Unk_PsdKeyBase
{
public:
    virtual ~Unk_PsdKeyBase();
    int FUN_14070fe80();                                                // key code
};
class Unk_PsdKeyState
{
public:
    virtual void vfunc_0();
    virtual bool vfunc_1();
};
class Unk_PsdKeyEvent : public Unk_PsdKeyBase, public Unk_PsdKeyState
{
};

class Unk_PsdDialogMgr
{
public:
    UISwfEntity* FUN_1422d4980(int nLayer);
};
Unk_PsdDialogMgr* FUN_140b632f0();

CPartyManager* FUN_1409670d0();
int FUN_140695080(CMatchPartyRecruit* pRecruit);                         // recruitId == 0
__int64 FUN_141656a80(PCBase* pPlayer);                                  // character id
bool FUN_141527280(PCBase* pPlayer);                                     // in a party
// (0x1406943b0 is CMatchPartyRecruitSchCond's constructor, cmatchpartyrecruit.h)
unsigned int FUN_140869420();                                           // tick count
unsigned __int64 FUN_140718350(const CString& str);                     // string -> id
unsigned __int64 FUN_140718370(const CStringW& str);
CStringW FUN_140719a80(unsigned __int64 n);
CStringW FUN_14028de60(int nId);                                        // string table
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_14052bd00(int nId, const CStringW& strArg);
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a1, const int& a2);
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const __int64& nArg);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
void FUN_14151f200();
bool FUN_14025cd60(const CStringW& a, const CStringW& b);
void FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelim, int nMax);
bool FUN_1409c1720(const Scaleform::GFx::Value& v);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_141275460(int nId, int a, int b, const fmt::ArgList& args);
void FUN_141275260(int nId, int a, int b);
extern __int64 DAT_143ab2828;                                           // the local character id

// The exe carries a third 11-byte identity forwarder here (from the std::pair ctors); keep an instance so the range pairs up.
template unsigned __int64&& std::forward<unsigned __int64>(unsigned __int64&) noexcept;

// ---- free helpers ----

// @0x140f8f3b0
void FUN_140f8f3b0(ASObj* pObj, CMatchPartyRecruit* pRecruit)
{
    bool bAlready = FUN_140695080(pRecruit) ? false : true;
    pObj->FUN_1407cbbe0("alreadyRegisterMemberSearch", bAlready);
}

// @0x140f8ff40
void FUN_140f8ff40(int nId, int a, int b)
{
    FUN_141275460(nId, a, b, fmt::ArgList());
}

// @0x140f8f970
void ASObj::FUN_140f8f970(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140f8fa10
void ASObj::FUN_140f8fa10(const char* szName, unsigned int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140f8f850
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2, bool a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// The two sort lists of the window: (string id, sort value) rows; *pnIndex receives the row of nSort.
// @0x140f8ef30
void FUN_140f8ef30(ASArray* pArray, int nSort, int* pnIndex)
{
    ATL::CAtlArray<std::pair<int, int> > sorts;
    sorts.Add(std::pair<int, int>(0xb29, 0xc));
    sorts.Add(std::pair<int, int>(0xb2a, 0xb));
    sorts.Add(std::pair<int, int>(0xb2b, 0x16));
    sorts.Add(std::pair<int, int>(0xb2c, 0x15));
    for (size_t i = 0; i < sorts.GetCount(); ++i)
    {
        ASObj item(2);
        std::pair<int, int> sort = sorts[i];
        item.FUN_1407cbb20("label", FUN_14028de60(sort.first));
        item.FUN_140f8f970("sortValue", sort.second);
        if (nSort == sort.second)
            *pnIndex = (int)i;
        pArray->FUN_1422bc050(item.FUN_1422bb870());
    }
}

// @0x140f8f170
void FUN_140f8f170(ASArray* pArray, int nSort, int* pnIndex)
{
    ATL::CAtlArray<std::pair<int, unsigned int> > sorts;
    sorts.Add(std::pair<int, unsigned int>(0xb26, 0x15u));
    sorts.Add(std::pair<int, unsigned int>(0xb25, 0x16u));
    sorts.Add(std::pair<int, unsigned int>(0xb27, 0xcu));
    sorts.Add(std::pair<int, unsigned int>(0xb28, 0xbu));
    for (size_t i = 0; i < sorts.GetCount(); ++i)
    {
        ASObj item(2);
        std::pair<int, unsigned int> sort = sorts[i];
        item.FUN_1407cbb20("label", FUN_14028de60(sort.first));
        item.FUN_140f8fa10("sortValue", sort.second);
        if (nSort == (int)sort.second)
            *pnIndex = (int)i;
        pArray->FUN_1422bc050(item.FUN_1422bb870());
    }
}

// Rows [nStart, nStart + nCount) of the received recruitments as AS objects; returns the number of recruitments.
// @0x140f8f410
int FUN_140f8f410(int nStart, int nCount, ASArray* pOut, ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit> >& list)
{
    int nTotal = (int)list.GetCount();
    if (nCount != 0 && nStart >= 0 && (list.GetCount() == 0 || nStart < (int)list.GetCount()) && list.GetCount() != 0)
    {
        int nEnd = nTotal;
        if (nStart + nCount < nTotal)
            nEnd = nStart + nCount;
        for (int i = nStart; i < nEnd; ++i)
        {
            MS2Ptr<CMatchPartyRecruit> recruit = list[i];
            if (!recruit.IsNull())
            {
                ASObj item(2);
                item.FUN_1407cbb20("title", CStringW(recruit->title));
                CStringW strCount = FUN_14083dc40(L"{0}/{1}", recruit->maximumLevel, recruit->members);
                item.FUN_1407cbb20("memberCount", CStringW(strCount));
                item.FUN_1407cbb20("chiefName", CStringW(recruit->ownerName));
                item.FUN_1407cb9c0("allowAutoJoin", recruit->minimumLevel);
                item.FUN_1407cbbe0("mine", DAT_143ab2828 == recruit->created);
                item.FUN_1407cbb20("sn", FUN_140719a80(recruit->recruitId));
                pOut->FUN_1422bc050(item.FUN_1422bb890());
            }
        }
    }
    return nTotal;
}

// ---- UIPartySearchDialog ----

// @0x140f8c480
UIPartySearchDialog::UIPartySearchDialog()
    : m_178(0), m_17c(0), m_180(0)
{
    FUN_141924170(1);
    FUN_1422dc3b0(1);
    m_88 = 1;
}

// @0x140f8c530
UIPartySearchDialog::~UIPartySearchDialog()
{
}

// @0x140f8c580
CString UIPartySearchDialog::vfunc_1()
{
    return "PartySearchDialog";
}

// @0x140f8c5d0
int UIPartySearchDialog::vfunc_65()
{
    if (vfunc_55() == 0)
    {
        if (m_30.get())
            m_30->Invoke("setTopMostLayer");
    }
    return UIDialog::vfunc_65();
}

// @0x140f8c650
int UIPartySearchDialog::vfunc_73()
{
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x1b) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    return UIDialog::vfunc_73();
}

// @0x140f8c6b0
void UIPartySearchDialog::vfunc_79(void* pEvent)
{
    UIDialog::vfunc_79(pEvent);
    if (!m_30)
        return;
    if (static_cast<Unk_PsdKeyEvent*>(pEvent)->FUN_14070fe80() == 0x53)
    {
        int bRepeat = static_cast<Unk_PsdKeyEvent*>(pEvent)->vfunc_1();
        if (bRepeat == 0)
            FUN_140f8e610();
    }
}

// @0x140f8c740
void UIPartySearchDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    FUN_140f8e670();
    m_30->Invoke("initData");
    ASObj root(2);
    ASArray sorts(2);
    FUN_140f8f3b0(&root, &FUN_1409670d0()->FUN_141631ce0());
    int nIndex = 0;
    FUN_140f8ef30(&sorts, m_180->kind, &nIndex);
    root.FUN_1409adbe0("arrSortMemberSearch", sorts.FUN_1422bb870());
    root.FUN_1407cb9c0("selectedSortIndex", nIndex);
    FUN_140f8e3f0(1);
    m_30->Invoke("initDataTo", root.FUN_1422bb870());
}

// @0x140f8c970
void UIPartySearchDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_17c = 0;
    FUN_140f8ded0();
    FUN_1403ed2b0()->FUN_141adc5d0(0x4edb);
}

// @0x140f8c9c0
void UIPartySearchDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (!m_30)
        return;
    if (m_178 != 0)
    {
        if (!FUN_140f8e3a0())
            return;
        if (m_180.get())
        {
            FUN_1409670d0()->SendMatchPartyMode2(*m_180);
            m_17c = FUN_140869420();
            m_178 = 0;
        }
    }
}

// @0x140f8ca80
int UIPartySearchDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (m_30.get())
    {
        if (FUN_140b632f0()->FUN_1422d4980(m_e0) == this)
        {
            CString strKey("");
            if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
                strKey = "onEnterKey";
            if (!strKey.IsEmpty())
            {
                if (FUN_1409c1720(m_30->Invoke("onProcessKey", CString(strKey))))
                    return 1;
            }
        }
    }
    return 0;
}

// @0x140f8cc10
int UIPartySearchDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nAnswer = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nAnswer == 0 && strTag.Find(L"askPartyJoinByAlreadyMemberSearch", 0) == 0)
        {
            ATL::CAtlArray<CStringW> parts;
            FUN_14028cb70(strTag, parts, L",", 2);
            __int64 nId = FUN_140718370(parts[1]);
            MS2Ptr<CMatchPartyRecruit> recruit = FUN_1409670d0()->FUN_141631d40(nId);
            if (recruit.get())
            {
                if (FUN_140695080(recruit.operator->()) == 0)
                {
                    FUN_1409670d0()->FUN_14162bcc0(MS2Ptr<CMatchPartyRecruit>(recruit));
                }
            }
        }
        return 1;
    }
    return 0;
}

// @0x140f8cdf0
int UIPartySearchDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onChangeIndexDungeonList", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_180->fieldId = 0;
            m_180->category = 0;
            m_180->page = 1;
            m_180->text.Empty();
            FUN_140f8e3f0(1);
        }
        return 1;
    }
    if (_stricmp("onChangeSortPartySearch", szMethod) == 0)
        return 1;
    if (_stricmp("onChangeSortMemeberSearch", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nSort = data.FUN_1422b8a10();
            CStringW strText = data.FUN_1422b8f40();
            m_180->kind = (unsigned char)nSort;
            if (FUN_140f8e480(strText))
                FUN_140f8e3f0(1);
        }
        return 1;
    }
    if (_stricmp("onChangePage", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nStart = data.FUN_1422b8a10();
            int nCount = data.FUN_1422b8a10();
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            int bOk = FUN_140f8e3a0();
            if (bOk)
                FUN_140f8e340(nStart, nCount);
            FUN_1407cd930(&ret, "result", Scaleform::GFx::Value(bOk != 0));
        }
        return 1;
    }
    if (_stricmp("OnChangeList", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nPage = data.FUN_1422b8a10();
            Scaleform::GFx::Value ret = data.FUN_1422b9260();
            int bOk = FUN_140f8e3a0();
            if (bOk)
                FUN_140f8e3f0(nPage);
            FUN_1407cd930(&ret, "result", Scaleform::GFx::Value(bOk != 0));
        }
        return 1;
    }
    if (_stricmp("onClickRegisterMemeberSearch", szMethod) == 0)
    {
        FUN_140f8eab0();
        return 1;
    }
    if (_stricmp("onClickRegisterMemeberSearchModify", szMethod) == 0)
    {
        FUN_140f8ec40();
        return 1;
    }
    if (_stricmp("onClickRefresh", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strText = data.FUN_1422b8f40();
            if (FUN_140f8e480(strText))
                FUN_140f8e3f0(1);
        }
        return 1;
    }
    if (_stricmp("onClickSearch", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strText = data.FUN_1422b8f40();
            if (FUN_140f8e480(strText))
                FUN_140f8e3f0(1);
        }
        return 1;
    }
    if (_stricmp("onClickPartyInvite", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            if (!strName.IsEmpty())
            {
                PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
                if (pPlayer != 0)
                {
                    if (FUN_14025cd60(strName, pPlayer->vfunc_77()))
                    {
                        FUN_140f8ff40(0xb38, 1, 1);
                        return 1;
                    }
                    if (FUN_141527280(pPlayer) && !FUN_1409670d0()->FUN_14162ab60())
                    {
                        FUN_140f8ff40(0xb39, 1, 1);
                        return 1;
                    }
                    FUN_1409670d0()->SendPartyMode1(CStringW(strName));
                }
            }
        }
        return 1;
    }
    if (_stricmp("onClickPartyJoin", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            __int64 nId = FUN_140718350(data.FUN_1422b8d30());
            if (nId == 0)
                return 1;
            MS2Ptr<CMatchPartyRecruit> recruit = FUN_1409670d0()->FUN_141631d40(nId);
            if (recruit.get())
            {
                PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
                if (pPlayer != 0)
                {
                    if (recruit->created == FUN_141656a80(pPlayer))
                    {
                        FUN_140f8ff40(0xb35, 1, 1);
                        return 1;
                    }
                    if (FUN_141527280(pPlayer))
                    {
                        FUN_140d73bc0(0xb36, 0, 0, CStringW(L""));
                        return 1;
                    }
                    if (FUN_140695080(&FUN_1409670d0()->FUN_141631ce0()) == 0)
                    {
                        CStringW strAsk = FUN_1406c6bd0(L"askPartyJoinByAlreadyMemberSearch,{0}", nId);
                        FUN_140d73bc0(0xb31, 1, static_cast<IMessageListener*>(this), CStringW(strAsk));
                        return 1;
                    }
                }
                FUN_1409670d0()->FUN_14162bcc0(MS2Ptr<CMatchPartyRecruit>(recruit));
            }
        }
        return 1;
    }
    if (_stricmp("onClickWhisper", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            if (!strName.IsEmpty())
            {
                PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
                if (pPlayer != 0)
                {
                    if (FUN_14025cd60(pPlayer->vfunc_77(), strName))
                    {
                        FUN_140f8ff40(0xb34, 1, 1);
                        return 1;
                    }
                    if (FUN_141482e80()->m_48 != 0)
                        FUN_141482e80()->m_48->FUN_141a252a0(strName);
                }
            }
        }
        return 1;
    }
    if (_stricmp("onRightClickChiefName", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int x = data.FUN_1422b8a10();
            int y = data.FUN_1422b8a10();
            __int64 nId = FUN_140718350(data.FUN_1422b8d30());
            if (nId == 0)
                return 1;
            MS2Ptr<CMatchPartyRecruit> recruit = FUN_1409670d0()->FUN_141631d40(nId);
            if (recruit.get())
            {
                __int64 nChar = recruit->created;
                if (nChar != 0)
                    FUN_140f8e790((float)x, (float)y, recruit->ownerId, nChar, &recruit->ownerName, 0x40da);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140f8dde0
void UIPartySearchDialog::FUN_140f8dde0()
{
    MS2Ptr<Unk_PsdInput> input = FUN_140e35bd0("m_inputSearch");
    if (input.get())
        input->FUN_1422e0ab0(CStringW(L""));
    if (m_180.get())
        m_180->text.Empty();
}

// @0x140f8ded0
void UIPartySearchDialog::FUN_140f8ded0()
{
    m_178 = 0;
}

// @0x140f8def0
int UIPartySearchDialog::FUN_140f8def0(int nStart, int nCount, ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit> >& list)
{
    if (m_30.get() && m_180.get())
    {
        ASArray rows(2);
        int nTotal = FUN_140f8f410(nStart, nCount, &rows, list);
        m_30->Invoke("buildItemListTo", rows.FUN_1422bb870(), nTotal, nStart == 0);
        if (!m_180->text.IsEmpty())
        {
            CStringW strNotice = nTotal != 0 ? CStringW(L"") : FUN_14052bd00(0xb32, m_180->text);
            m_30->Invoke("updateNoticeText", CStringW(strNotice));
        }
        return 1;
    }
    return 0;
}

// @0x140f8e220
int UIPartySearchDialog::FUN_140f8e220(int nStart, int nCount, ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit> >& list)
{
    if (!m_30)
        return 0;
    ASArray rows(2);
    int nTotal = FUN_140f8f410(nStart, nCount, &rows, list);
    m_30->Invoke("buildPageTo", rows.FUN_1422bb870(), nTotal);
    return 1;
}

// @0x140f8e340
int UIPartySearchDialog::FUN_140f8e340(int nStart, int nCount)
{
    if (nStart < 0 || nCount == 0)
        return 1;
    ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>>& arr = FUN_1409670d0()->FUN_141631d20();
    return FUN_140f8e220(nStart, nCount, arr);
}

// @0x140f8e3a0
int UIPartySearchDialog::FUN_140f8e3a0()
{
    const unsigned nDelay = 500;
    unsigned nNow = FUN_140869420();
    if (nNow < m_17c + nDelay)
        return 0;
    return 1;
}

// @0x140f8e3f0
int UIPartySearchDialog::FUN_140f8e3f0(int nPage)
{
    if (!m_30)
        return 0;
    m_180->page = nPage;
    m_180->pageSize = 0;
    m_178 = 1;
    return m_178;
}

// @0x140f8e480
int UIPartySearchDialog::FUN_140f8e480(const CStringW& strText)
{
    MS2Ptr<Unk_PsdFilter> filter = FUN_14025e7d0()->FUN_140229a50();
    if (filter.get())
    {
        CStringW strBad;
        if (filter->FUN_140226320(strText, strBad) == 0)
        {
            m_180->text = strText;
            return 1;
        }
        if (m_30.get())
        {
            CStringW strNotice = FUN_14052bd00(0xb33, strBad);
            m_30->Invoke("updateNoticeText", CStringW(strNotice));
        }
    }
    return 0;
}

// @0x140f8e610
void UIPartySearchDialog::FUN_140f8e610()
{
    if (m_30.get())
        m_30->Invoke("forceClickRefresh");
}

// @0x140f8e670
void UIPartySearchDialog::FUN_140f8e670()
{
    if (!m_180)
    {
        // new + the 0x1406943b0 constructor
        m_180.AssignRaw(new CMatchPartyRecruitSchCond());
        if (!m_180)
            return;
        m_180->page = 1;
        // the exe stores the kind as a dword (cf. KindOf in matchpartyrecruitschcond.cpp)
        *reinterpret_cast<int*>(&m_180->kind) = 0xc;
    }
    else
    {
        m_180->page = 1;
        m_180->text.Empty();
    }
}

// @0x140f8e790
void UIPartySearchDialog::FUN_140f8e790(float x, float y, unsigned __int64 nAccount, __int64 nChar, CStringW* pName, int nFlag)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        if (FUN_141656a80(static_cast<PCBase*>(pPlayer)) == nChar)
        {
            Unk_PsdMenu* pMenu = FUN_140c30140(0x4e39);
            if (pMenu != 0)
            {
                Unk_PsdMenuInfo info;
                info.FUN_140c302f0(x, y, 3, nFlag, 1, CString("partySearchSlot"), 0);
                pMenu->FUN_141a7e280(info, pPlayer, 0xc);
                info.FUN_140c304c0();
            }
        }
        else
        {
            Unk_PsdMenu* pMenu = FUN_140c30140(0x4e39);
            if (pMenu != 0)
            {
                MS2Ptr<Unk_PsdProxy> ref;
                FUN_1403ed2d0()->FUN_141bc9c60(&ref, nChar);
                Unk_PsdMenuInfo info;
                if (ref.get() == 0)
                {
                    info.FUN_140c302f0(x, y, 3, nFlag, 0, CString("partySearchSlot"), 0);
                    pMenu->FUN_141a7f090(info, *pName, nChar, nAccount, 0xc, 1);
                }
                else
                {
                    info.FUN_140c302f0(x, y, 3, nFlag, 1, CString("partySearchSlot"), 0);
                    Unk_PsdProxyRef proxy;
                    pMenu->FUN_141a7eb60(info, FUN_140ac58f0(&proxy, ref), 0xc);
                }
                info.FUN_140c304c0();
            }
        }
    }
}

// @0x140f8eab0
void UIPartySearchDialog::FUN_140f8eab0()
{
    PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        if (FUN_141527280(pPlayer) && !FUN_1409670d0()->FUN_14162ab60())
        {
            FUN_140d73bc0(0xb3a, 0, 0, CStringW(L""));
            return;
        }
        if (FUN_1409670d0()->FUN_141631cc0() == 0)
        {
            if (FUN_1409670d0()->FUN_14162af00() < 10)
            {
                FUN_1403ed2b0()->FUN_141adc530(0x4edb);
            }
            else
            {
                int nMax = 10;
                FUN_140d73aa0(FUN_1408116a0(0xb3b, nMax), 0, 0, CStringW(L""));
            }
        }
        else
        {
            FUN_140d73bc0(0xb3d, 0, 0, CStringW(L""));
        }
    }
}

// @0x140f8ec40
void UIPartySearchDialog::FUN_140f8ec40()
{
    PCBase* pPlayer = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        if (FUN_141527280(pPlayer) && !FUN_1409670d0()->FUN_14162ab60())
        {
            FUN_140d73bc0(0xb3e, 0, 0, CStringW(L""));
            return;
        }
        if (FUN_140695080(&FUN_1409670d0()->FUN_141631ce0()) == 0)
            FUN_1403ed2b0()->FUN_141adc530(0x4edb);
        else
            FUN_140d73bc0(0xb3f, 0, 0, CStringW(L""));
    }
}

// @0x140f8ed40
void UIPartySearchDialog::FUN_140f8ed40(ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit> >& list, int nStart)
{
    FUN_140f8ded0();
    if (!m_30)
        return;
    int nPageSize = 0xc;
    FUN_140f8def0(nStart, nPageSize, list);
}

// @0x140f8edb0
void UIPartySearchDialog::FUN_140f8edb0()
{
    if (!m_30)
        return;
    CMatchPartyRecruit* pRecruit = &FUN_1409670d0()->FUN_141631ce0();
    FUN_140f8ee50(pRecruit);
}

// @0x140f8ee00
void UIPartySearchDialog::FUN_140f8ee00(CMatchPartyRecruit* pRecruit)
{
    if (!m_30)
        return;
    FUN_140f8ee50(pRecruit);
    FUN_140f8e610();
}

// @0x140f8ee50
void UIPartySearchDialog::FUN_140f8ee50(CMatchPartyRecruit* pRecruit)
{
    if (m_30.get())
    {
        ASObj obj(2);
        FUN_140f8f3b0(&obj, pRecruit);
        m_30->Invoke("updateDataTo", obj.FUN_1422bb870());
    }
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140F8C580, UIPartySearchDialog, vfunc_1, 61, 0x470601A1);
MS2_REPLACE_METHOD(0x140F8C5D0, UIPartySearchDialog, vfunc_65, 116, 0xF47905F5);
MS2_REPLACE_METHOD(0x140F8C650, UIPartySearchDialog, vfunc_73, 75, 0x0898C429);
MS2_REPLACE_METHOD(0x140F8C6B0, UIPartySearchDialog, vfunc_79, 133, 0x5A89C5DA);
MS2_REPLACE_METHOD(0x140F8C740, UIPartySearchDialog, OnLoadComplete, 543, 0x4007F141);
MS2_REPLACE_METHOD(0x140F8C970, UIPartySearchDialog, vfunc_26, 67, 0xBFD3DAB4);
MS2_REPLACE_METHOD(0x140F8C9C0, UIPartySearchDialog, vfunc_15, 183, 0x627E31FB);
MS2_REPLACE_METHOD(0x140F8CA80, UIPartySearchDialog, vfunc_13, 386, 0x56F88195);
MS2_REPLACE_METHOD_VIA(0x140F8CC10, UIPartySearchDialog, IMessageListener, OnMessage, 472, 0x9124EDAE);
MS2_REPLACE_METHOD(0x140F8CDF0, UIPartySearchDialog, vfunc_28, 4003, 0xFA22F03F);
MS2_REPLACE_METHOD(0x140F8DDE0, UIPartySearchDialog, FUN_140f8dde0, 234, 0xF22CA109);
MS2_REPLACE_METHOD(0x140F8DED0, UIPartySearchDialog, FUN_140f8ded0, 21, 0x5C036FB6);
MS2_REPLACE_METHOD(0x140F8DEF0, UIPartySearchDialog, FUN_140f8def0, 801, 0x2FAA629E);
MS2_REPLACE_METHOD(0x140F8E220, UIPartySearchDialog, FUN_140f8e220, 278, 0xAD8E281C);
MS2_REPLACE_METHOD(0x140F8E340, UIPartySearchDialog, FUN_140f8e340, 86, 0x4C748447);
MS2_REPLACE_METHOD(0x140F8E3A0, UIPartySearchDialog, FUN_140f8e3a0, 62, 0xA8728C13);
MS2_REPLACE_METHOD(0x140F8E3F0, UIPartySearchDialog, FUN_140f8e3f0, 124, 0x68C7BDF0);
MS2_REPLACE_METHOD(0x140F8E480, UIPartySearchDialog, FUN_140f8e480, 385, 0xF666571F);
MS2_REPLACE_METHOD(0x140F8E610, UIPartySearchDialog, FUN_140f8e610, 83, 0xDB1043DC);
MS2_REPLACE_METHOD(0x140F8E670, UIPartySearchDialog, FUN_140f8e670, 276, 0x3DADEC31);
MS2_REPLACE_METHOD(0x140F8E790, UIPartySearchDialog, FUN_140f8e790, 786, 0xD9F88A0F);
MS2_REPLACE_METHOD(0x140F8EAB0, UIPartySearchDialog, FUN_140f8eab0, 386, 0x2E525509);
MS2_REPLACE_METHOD(0x140F8EC40, UIPartySearchDialog, FUN_140f8ec40, 235, 0x12C1094E);
MS2_REPLACE_METHOD(0x140F8ED40, UIPartySearchDialog, FUN_140f8ed40, 92, 0x2085E5ED);
MS2_REPLACE_METHOD(0x140F8EDB0, UIPartySearchDialog, FUN_140f8edb0, 73, 0xEA81D959);
MS2_REPLACE_METHOD(0x140F8EE00, UIPartySearchDialog, FUN_140f8ee00, 70, 0x0B20ECD3);
MS2_REPLACE_METHOD(0x140F8EE50, UIPartySearchDialog, FUN_140f8ee50, 218, 0x99768554);
MS2_REPLACE(0x140F8EF30, FUN_140f8ef30, 557, 0xDD731B16);
MS2_REPLACE(0x140F8F170, FUN_140f8f170, 557, 0x2AEAC5AF);
MS2_REPLACE(0x140F8F3B0, FUN_140f8f3b0, 77, 0x8529DACE);
MS2_REPLACE(0x140F8F410, FUN_140f8f410, 924, 0xAA3DBAEA);
MS2_REPLACE(0x140F8FF40, FUN_140f8ff40, 53, 0x388A0D60);
