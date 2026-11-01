// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A zone of client UI helpers: system-message popups, number/meso
// formatting, screen-scale lookup, GFx layer names, and the CAtlMap<Unk_ScreenKey, float> cache they use.
// MS2-UNIT: unit_141274d10
// MS2-RANGE: 0x141274d10-0x141279710 .text$mn
// MS2-RANGE: 0x1400eba80-0x1400ebd60 .text$di
// MS2-RANGE: 0x142cae800-0x142cae900 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsNull@?$MS2Ptr@VASWindow@@@@QEBA_NXZ 0x1412784a0 ; unique
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x141278750 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEBA_NXZ 0x141278a50 ; unique
// MS2-PIN: ??0?$MS2Ptr@VASWindow@@@@QEAA@PEAVASWindow@@@Z 0x141278340 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ??1?$MS2Ptr@VASWindow@@@@QEAA@XZ 0x141278440 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ??C?$MS2Ptr@VASWindow@@@@QEBAPEAVASWindow@@XZ 0x1412784e0 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ?AddRef@?$MS2Ptr@VASWindow@@@@AEBAXXZ 0x141279550 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ?Reference@?$MS2Ptr@VASWindow@@@@CAXPEAVASWindow@@@Z 0x141279580 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VASWindow@@@@AEBAXPEAX@Z 0x1412795c0 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ?Release@?$MS2Ptr@VASWindow@@@@AEAAXXZ 0x1412795f0 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VASWindow@@@@AEAAXPEAX@Z 0x141279670 ; folded lookalike (MS2Ptr<T> identical bodies)
// MS2-PIN: ?CompareElements@Unk_ScreenKeyTraits@@SA_NAEBUUnk_ScreenKey@@0@Z 0x141278500 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

static CString s_strEmpty = "";                                                          // @0x1400eba80
static CString s_strChartSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400ebab0
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/unnamed/unit_141274d10_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

#include "ms2/ms2format.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/autofindtaxistation.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/commandchat.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cugcitemlook.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/itemlapensharddata.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/scaleform/include/gfx/gfx_value.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
class CItemData;   // C3: MS2Ptr<CItemData>::operator->
class CUserMail { public: static __int64 FUN_1408e57f0(); };  // C3: member view (0x1408e57f0, the scene-service global)

// return types of the getters this unit calls
class CEffectService;
class CGameOption;
class CItemDataTable;
class CameraMgr;
class CommonString;
class Unk_InventoryStateManager;
class Unk_SlotLapenTable;
struct Unk_MdState;

// ---- unit-local stand-ins -------------------------------------------------------------------------------------------
class Unk_ChatLog;
class Unk_ChatWindow {                                  // the chat UI singleton: the chat log panel is at +0x48
public:
    char m_pad_00[0x48];
    Unk_ChatLog* m_log;
};
MS2_CHECK_OFFSET(Unk_ChatWindow, m_log, 0x48);
struct Unk_MdState* FUN_141482e80();   // C3: was FUN_141482e80
void FUN_141a24cb0(Unk_ChatLog*, const CStringW&, int, int, int, int);

class UISystemText : public UIObject {                  // the system message line (UI id 0x4e41)
public:
    void FUN_141b15ec0(const CStringW& msg, int a, int b);
    void FUN_141b16270(const CStringW& msg, int a, int b);
};
class UITopLayerNotify : public UIObject {              // the top-layer notice (UI id 0x4ef5)
public:
    void FUN_140fa8970(const CStringW& msg, int a);
};

class Unk_PlayerActor { public: char m_pad_00[8]; };
class Unk_PlayerRef;
void FUN_14151f460(int);
void FUN_141a8a730();
int FUN_141a8a760();
UIMessageBox* FUN_14151f890();
void* FUN_140967100();
class UITalkManager   // C3: member view for the former free stand-ins
{
public:
    int GetTalking();
};
class PC { public: int FUN_1416595d0(); int FUN_141659690(); };   // C3: unit-local view
CStringW GetStringCommon(int nId);
CStringW FUN_140298ea0(CStringW);
UISystemText* FUN_141278110(int nId);
UITopLayerNotify* FUN_1412781b0(int nId);
void FUN_1412751b0(const CStringW&, int);
void FUN_1412751f0(const CStringW&, int, int);
class UIMessengerBrowser* FUN_140a3ab70(int);   // C3: was FUN_140a3ab70
class UICommunityDialog;
UICommunityDialog* FUN_140ae5990(int);
class Unk_GuideInventory;
class UIInventoryDialog;
template<class T> T* Unk_BreakDialog(int);   // C3: was Unk_GuideInventory* FUN_1405344f0 (calls cast back)
class UIGroupMessengerBrowser* FUN_140a3aad0(int);   // C3: was FUN_140a3aad0
class UIMessengerBrowser   // C3: member view for the former free stand-ins
{
public:
    void FUN_141a247c0(const CStringW& strText, int nType);
    void FUN_141a24890(CItem* pItem, unsigned nCount, int nManyId, int nOneId);
    void FUN_141a23c20();
};
void FUN_1418d6410(UICommunityDialog*);
class UIInventoryDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_141999e20();
};
class UIGroupMessengerBrowser   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419524e0();
};

// @0x141274d10
int FUN_141274d10(MS2Ptr<UIDialog> pDlg)
{
    if ((UIDialog*)pDlg != 0) {
        if (pDlg.get()->vfunc_56() != 0)
            return 0;
        if (pDlg.get()->vfunc_55() != 0)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x141274d10, FUN_141274d10, 212, 0x8E8D6EEC);

// @0x141274df0
int FUN_141274df0(MS2Ptr<UIDialog> pDlg)
{
    if ((UIDialog*)pDlg != 0) {
        if (pDlg.get()->vfunc_56() != 0)
            return 0;
        if (pDlg.get()->vfunc_55() != 0)
            return 0;
        if (pDlg.get()->vfunc_64() != 0)
            return 0;
        if (pDlg.get()->FUN_1419244c0(1) != 0)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x141274df0, FUN_141274df0, 331, 0xD4D42BD8);

// @0x141274f50
void FUN_141274f50()
{
    FUN_14151f460(0);
    FUN_141a8a730();
    TSingleton<CUIService>::GetInstance()->CloseAllDialogs();
}
MS2_REPLACE(0x141274f50, FUN_141274f50, 34, 0x61491953);

// @0x141274f80
int FUN_141274f80()
{
    if (TSingleton<CUIService>::GetInstance()->FUN_141adcbb0(FUN_141274d10) != 0)
        return 1;
    if (FUN_141a8a760() != 0)
        return 1;
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0 && pBox->FUN_1419f8270() == 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x141274f80, FUN_141274f80, 97, 0x2E5323AD);

// @0x141274ff0
int FUN_141274ff0()
{
    if (TSingleton<CUIService>::GetInstance()->FUN_141adcbb0(FUN_141274df0) != 0)
        return 1;
    if (FUN_141a8a760() != 0)
        return 1;
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0 && pBox->FUN_1419f8270() == 0)
        return 1;
    return 0;
}
MS2_REPLACE(0x141274ff0, FUN_141274ff0, 97, 0x12D8B30D);

// @0x141275060
int FUN_141275060()
{
    return ((class UITalkManager*)(void*)(FUN_140967100()))->GetTalking();
}
MS2_REPLACE(0x141275060, FUN_141275060, 22, 0x80B1C3A0);

// @0x141275080
int FUN_141275080()
{
    if (FUN_141275060() != 0)
        return 0;
    void* pActor = ((class WorldService*)(void*)(WorldService::GetInstance()))->FUN_141bd0cc0();
    if (pActor != 0) {
        if (((PC*)pActor)->FUN_1416595d0() != 0 && ((PC*)pActor)->FUN_141659690() == 0)
            return 0;
        if (CAutoFindTaxiStation::GetInstance()->FUN_141278a40() != 0)
            return 0;
    }
    return 1;
}

// @0x1412750f0
void FUN_1412750f0(const CStringW& str, int a, int b, int c)
{
    if (reinterpret_cast<Unk_ChatWindow*>(((class Unk_ChatWindow*)FUN_141482e80()))->m_log != 0)
        reinterpret_cast<UIMessengerBrowser*>(reinterpret_cast<Unk_ChatWindow*>(((class Unk_ChatWindow*)FUN_141482e80()))->m_log)->FUN_141a24890((CItem*)&str, a, b, c);
}
MS2_REPLACE(0x1412750f0, FUN_1412750f0, 77, 0x2112E627);

// @0x141275150
void FUN_141275150(const CStringW& str, int a, int b, int c, int d)
{
    if (reinterpret_cast<Unk_ChatWindow*>(((class Unk_ChatWindow*)FUN_141482e80()))->m_log != 0)
        FUN_141a24cb0(reinterpret_cast<Unk_ChatWindow*>(((class Unk_ChatWindow*)FUN_141482e80()))->m_log, str, a, b, c, d);
}
MS2_REPLACE(0x141275150, FUN_141275150, 85, 0xA770C8C1);

// @0x1412751b0
void FUN_1412751b0(const CStringW& str, int nType)
{
    if (reinterpret_cast<Unk_ChatWindow*>(((class Unk_ChatWindow*)FUN_141482e80()))->m_log != 0)
        reinterpret_cast<UIMessengerBrowser*>(reinterpret_cast<Unk_ChatWindow*>(((class Unk_ChatWindow*)FUN_141482e80()))->m_log)->FUN_141a247c0(str, nType);
}
MS2_REPLACE(0x1412751b0, FUN_1412751b0, 54, 0x5701C5EE);

// @0x1412751f0
void FUN_1412751f0(const CStringW& str, int a, int bLog)
{
    UISystemText* pText = FUN_141278110(0x4e41);
    if (pText != 0) {
        pText->FUN_141b15ec0(str, a, 0);
        if (bLog != 0)
            FUN_1412751b0(str, 0x14);
    }
}
MS2_REPLACE(0x1412751f0, FUN_1412751f0, 91, 0xEB4DF479);

// @0x141275260
void FUN_141275260(int nId, int a, int b)
{
    CStringW str = GetStringCommon(nId);
    if (str.GetLength() == 0)
        return;
    FUN_1412751f0(str, a, b);
}
MS2_REPLACE(0x141275260, FUN_141275260, 105, 0x8556833F);

// @0x1412752d0
void FUN_1412752d0(const CStringW& str, int a)
{
    CStringW text = FUN_140298ea0(str);
    if (text.GetLength() == 0)
        return;
    FUN_1412751f0(text, a, 1);
}
MS2_REPLACE(0x1412752d0, FUN_1412752d0, 134, 0x4DC78C07);

// @0x141275360
void FUN_141275360(const CStringW& str, int a, int b)
{
    UISystemText* pText = FUN_141278110(0x4e41);
    if (pText != 0)
        pText->FUN_141b16270(str, a, b);
}
MS2_REPLACE(0x141275360, FUN_141275360, 71, 0x77F73145);

// @0x1412753b0
void FUN_1412753b0(const CStringW& str, int a, int b)
{
    UISystemText* pText = FUN_141278110(0x4e41);
    if (pText != 0)
        pText->FUN_141b15ec0(str, a, b);
}
MS2_REPLACE(0x1412753b0, FUN_1412753b0, 71, 0x21351DE1);

// @0x141275400
void FUN_141275400(const CStringW& str, int a)
{
    UITopLayerNotify* pNotify = FUN_1412781b0(0x4ef5);
    if (pNotify != 0) {
        pNotify->FUN_140fa8970(str, a);
        FUN_1412751b0(str, 0x1d);
    }
}
MS2_REPLACE(0x141275400, FUN_141275400, 76, 0x2195EA41);

// @0x141275460
void FUN_141275460(int nId, int a, int b, const fmt::ArgList& args)
{
    CStringW fmtStr = GetStringCommon(nId);
    if (fmtStr.GetLength() == 0)
        return;
    CStringW text = StringFormat((const wchar_t*)fmtStr, args);
    FUN_1412751f0(text, a, b);
}
MS2_REPLACE(0x141275460, FUN_141275460, 152, 0xFB7641A0);

// @0x141275500
void FUN_141275500()
{
    void* pDlg = ((void*)FUN_140a3ab70(0x4e61));
    if (pDlg != 0)
        ((class UIMessengerBrowser*)(void*)(pDlg))->FUN_141a23c20();
    UICommunityDialog* pCommunity = FUN_140ae5990(0x4e4d);
    if (pCommunity != 0)
        FUN_1418d6410(pCommunity);
    Unk_GuideInventory* pGuide = reinterpret_cast<Unk_GuideInventory*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
    if (pGuide != 0)
        ((class UIInventoryDialog*)(class Unk_GuideInventory*)(pGuide))->FUN_141999e20();
    void* pOther = ((void*)FUN_140a3aad0(0x4e93));
    if (pOther != 0)
        ((class UIGroupMessengerBrowser*)(void*)(pOther))->FUN_1419524e0();
}
MS2_REPLACE(0x141275500, FUN_141275500, 141, 0xF32E1E3E);

// ---- unit-local stand-ins (constants table, inventory view, ASWindow) ---------------------------------------------
// A Common::Constants value slot: Object header (0x50 bytes, the "is set" flag at +8), then the value.
template<class T> struct alignas(8) Unk_McValue {
    char m_pad_00[8];
    bool m_bSet;                                        // +0x08
    char m_pad_09[0x47];
    T m_value;                                          // +0x50
    T* FUN_1412788b0()                                  // checked access
    {
        if (!m_bSet)
            ((Common::Constants::Object*)(void*)(this))->Error("constants is not set");
        return &m_value;
    }
};
struct Unk_ClientConsts {
    char m_pad_00[0xb1e0];
    Unk_McValue<ATL::CAtlArray<int> > m_colorTable;     // +0xb1e0
    char m_pad_b250[0x20];
    Unk_McValue<unsigned> m_b270;                       // +0xb270
    Unk_McValue<unsigned> m_b2c8;                       // +0xb2c8
    Unk_McValue<unsigned> m_b320;                       // +0xb320
    char m_pad_b378[0x90];
    Unk_McValue<unsigned> m_b408;                       // +0xb408
};
MS2_CHECK_OFFSET(Unk_ClientConsts, m_colorTable, 0xb1e0);
MS2_CHECK_OFFSET(Unk_ClientConsts, m_b270, 0xb270);
MS2_CHECK_OFFSET(Unk_ClientConsts, m_b2c8, 0xb2c8);
MS2_CHECK_OFFSET(Unk_ClientConsts, m_b320, 0xb320);
MS2_CHECK_OFFSET(Unk_ClientConsts, m_b408, 0xb408);
// clientconstants.h declares FUN_1401d3200 as Common::Constants*; this unit uses its own view of the block
#define UNK_CLIENT_CONSTS() reinterpret_cast<Unk_ClientConsts*>(FUN_1401d3200())
template<class T> struct Unk_NpcConstant { T* Get(); };
unsigned int Unk_ColorValue(struct Unk_ConstColor const&);   // C3: was FUN_14056d500

class CItem;
extern Unk_Inventory g_143ab2a90;

extern __int64 DAT_143ab2820;
extern __int64 DAT_143ab2828;
CStringW FUN_140b8f7a0(const CStringW&);
CStringW FUN_1409404f0(__int64);
CStringW FUN_140719a00(__int64);
__int64 FUN_140718320(const CStringW&);

unsigned FUN_1412780f0(Unk_McValue<unsigned>* pSlot);
CString FUN_1412756c0(__int64 a, __int64 b);
CStringW FUN_141275790(const CStringW& str);
CStringW FUN_1412757d0(__int64 n);

// @0x1412755a0
int FUN_1412755a0()
{
    return 0;
}
MS2_REPLACE(0x1412755a0, FUN_1412755a0, 3, 0x94777CFF);

// @0x1412755b0
CString FUN_1412755b0()
{
    return CString("../../Config/");
}
MS2_REPLACE(0x1412755b0, FUN_1412755b0, 56, 0x66DFF2A6);

// @0x1412755f0
CString FUN_1412755f0()
{
    return FUN_1412756c0(DAT_143ab2820, DAT_143ab2828);
}
MS2_REPLACE(0x1412755f0, FUN_1412755f0, 62, 0xD2DDF8EA);

// @0x141275640
CString FUN_141275640()
{
    CString str;
    str.Format("%s%I64u", "../../Config/", DAT_143ab2820);
    return CString(str);
}
MS2_REPLACE(0x141275640, FUN_141275640, 118, 0x0758439E);

// @0x1412756c0
CString FUN_1412756c0(__int64 a, __int64 b)
{
    CString str;
    str.Format("%s%I64u/%I64u", "../../Config/", a, b);
    return CString(str);
}
MS2_REPLACE(0x1412756c0, FUN_1412756c0, 136, 0xC8FACBDD);

// @0x141275750
CString FUN_141275750()
{
    return CString("../../Data/Xml/Table/Default");
}
MS2_REPLACE(0x141275750, FUN_141275750, 56, 0x8631081E);

// @0x141275790
CStringW FUN_141275790(const CStringW& str)
{
    return FUN_140b8f7a0(str);
}
MS2_REPLACE(0x141275790, FUN_141275790, 58, 0x43C292A0);

// @0x1412757d0
CStringW FUN_1412757d0(__int64 n)
{
    if (n < 10000)
        return FUN_1409404f0(n);
    CStringW strNum = FUN_140719a00(n);
    return FUN_141275790(strNum);
}
MS2_REPLACE(0x1412757d0, FUN_1412757d0, 138, 0x632A0D97);

// @0x141275860
CStringW FUN_141275860(__int64 n)
{
    return FUN_14028dfa0<CStringW>(CStringW(L"s_number_string_meso"), FUN_1412757d0(n));
}
MS2_REPLACE(0x141275860, FUN_141275860, 146, 0xE1F2ADA4);

// @0x141275900
CStringW FUN_141275900(const CStringW& str)
{
    return FUN_14028dfa0<CStringW>(CStringW(L"s_number_string_meso"), FUN_141275790(str));
}
MS2_REPLACE(0x141275900, FUN_141275900, 146, 0xEBEE6EE7);

// @0x1412759a0
__int64 FUN_1412759a0(const CStringW& str)
{
    CStringW num(str);
    num.Replace(L",", L"");
    return FUN_140718320(num);
}
MS2_REPLACE(0x1412759a0, FUN_1412759a0, 96, 0xFED3BB25);

// @0x141275a10
int FUN_141275a10(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    int nKind = g_143ab2a90.FUN_140a65770(pItem);
    if (nKind == 2 || nKind == 3 || nKind == 5 || nKind == 6 || nKind == 10) {
        return 2;
    } else if (nKind == 1 || nKind == 9) {
        return 1;
    } else if (nKind == 7) {
        return 3;
    }
    return 0;
}
MS2_REPLACE(0x141275a10, FUN_141275a10, 126, 0xBF3ECD51);

// @0x141275aa0
int FUN_141275aa0(int nCode)
{
    if (UNK_CLIENT_CONSTS()->m_colorTable.FUN_1412788b0()->IsEmpty())
        return 0xffffff;
    size_t nIndex;
    ATL::CAtlArray<int>* pColors = UNK_CLIENT_CONSTS()->m_colorTable.FUN_1412788b0();
    nIndex = (size_t)(__int64)nCode / 100;
    if (((ATL::CAtlArray<int, ATL::CElementTraits<int>>*)(void*)(pColors))->GetCount() <= nIndex)
        return 0xffffff;
    return (*pColors)[nIndex];
}
MS2_REPLACE(0x141275aa0, FUN_141275aa0, 139, 0x50397E44);

// @0x141275b40
unsigned FUN_141275b40()
{
    return Unk_ColorValue(*(struct Unk_ConstColor const*)(reinterpret_cast<Unk_NpcConstant<unsigned>*>(&UNK_CLIENT_CONSTS()->m_b270)->Get()));
}
MS2_REPLACE(0x141275b40, FUN_141275b40, 36, 0x353EE636);

// @0x141275b70
unsigned FUN_141275b70()
{
    return Unk_ColorValue(*(struct Unk_ConstColor const*)(reinterpret_cast<Unk_NpcConstant<unsigned>*>(&UNK_CLIENT_CONSTS()->m_b2c8)->Get()));
}
MS2_REPLACE(0x141275b70, FUN_141275b70, 36, 0x92818E0E);

// @0x141275ba0
unsigned FUN_141275ba0()
{
    return Unk_ColorValue(*(struct Unk_ConstColor const*)(reinterpret_cast<Unk_NpcConstant<unsigned>*>(&UNK_CLIENT_CONSTS()->m_b320)->Get()));
}
MS2_REPLACE(0x141275ba0, FUN_141275ba0, 36, 0xB9F8727F);

// @0x141275bd0
unsigned FUN_141275bd0(void*)
{
    return FUN_1412780f0(&UNK_CLIENT_CONSTS()->m_b408);
}
MS2_REPLACE(0x141275bd0, FUN_141275bd0, 33, 0x3752B9CB);

// @0x141275c00
void FUN_141275c00(int nValue)
{
    TSingleton<CItemDataTable>::GetInstance()->GetTextColor((ItemGradeKey)nValue);
}
MS2_REPLACE(0x141275c00, FUN_141275c00, 30, 0x3CCFEEBB);

// ---- window alignment ---------------------------------------------------------------------------------------------
class ASWindow : public ASDisplayObjectContainer {      // the dialog frame wrapper (RTTI .?AVASWindow@@)
public:
    int FUN_1422e6310();                                // width of the frame
};
struct Unk_AlignOffset { float x, y; };

// Places two dialogs side by side: when they do not fit next to each other, the left one is moved to make room.
// @0x141275c30
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_AlignOffset offLeft, Unk_AlignOffset offRight)
{
    if (pLeft == 0 || pRight == 0)
        return;
    MS2Ptr<ASWindow> winLeft(dynamic_cast<ASWindow*>((AScript*)pLeft->FUN_1422dba00()));
    if (winLeft.IsNull())
        return;
    float fLeftWidth = 436.0f;
    Unk_AlignOffset* pPos = ((struct Unk_AlignOffset*)((class UIDialog*)(class UISwfEntity*)(pLeft))->FUN_1419265c0());
    float fX = pPos->x;
    float fY = pPos->y;
    if (MS2Ptr<ASMovieClip> panel = winLeft->FUN_1409b4560("m_panel"))
        fLeftWidth = (float)panel->FUN_1422c1340();
    else
        fLeftWidth = (float)winLeft->FUN_1422e6310();
    MS2Ptr<ASWindow> winRight(dynamic_cast<ASWindow*>((AScript*)pRight->FUN_1422dba00()));
    if (winRight.IsNull())
        return;
    float fRightWidth = 436.0f;
    if (MS2Ptr<ASMovieClip> panel = winRight->FUN_1409b4560("m_panel"))
        fRightWidth = (float)panel->FUN_1422c1340();
    else
        fRightWidth = (float)winRight->FUN_1422e6310();
    int nTotal = winLeft->FUN_1422c1500();
    float fBoth = fLeftWidth + fRightWidth;
    float fOverflow = (float)nTotal - (fX + fBoth);
    if (fOverflow < 0.0f) {
        fX = fX + fOverflow;
        fX = fX - ((float)nTotal - fBoth) * 0.5f;
        winLeft->FUN_1422c00f0(fX + offLeft.x, fY + offLeft.y);
    }
    winRight->FUN_1422c00f0(fX + fLeftWidth + offRight.x, fY + offRight.y);
}
MS2_REPLACE(0x141275c30, FUN_141275c30, 1201, 0xE804638C);

// ---- helpers for the name-filter / screen-scale functions below -----------------------------------------------------
CStringA FUN_1401d4330(const wchar_t* pszWide, int nCodePage);
class CEffectService { public: unsigned FUN_1411a5a60(const CString& strName, const CString& strArg); };
int FUN_141276180(const CString& str, const CString& strArg);

// @0x1412760f0
int FUN_1412760f0(const CStringW& str, const CString& strArg)
{
    if (str.IsEmpty())
        return 0;
    return FUN_141276180(FUN_1401d4330(str, 0), strArg);
}
MS2_REPLACE(0x1412760f0, FUN_1412760f0, 126, 0x92BD5363);

// @0x141276180
int FUN_141276180(const CString& str, const CString& strArg)
{
    if (str.IsEmpty())
        return 0;
    return TSingleton<CEffectService>::GetInstance()->FUN_1411a5a60(str, strArg) != 0;
}
MS2_REPLACE(0x141276180, FUN_141276180, 90, 0x95D6641F);

// @0x1412761e0
void FUN_1412761e0(MS2Ptr<AScript> pScript, int bShow)
{
    if (pScript.get() != 0) {
        MS2Ptr<ASDisplayObjectContainer> pContainer(dynamic_cast<ASDisplayObjectContainer*>((AScript*)pScript));
        if (pContainer) {
            ((class ASDisplayObjectContainer*)(class ASDisplayObjectContainer*)(pContainer.get()))->FUN_1422c6640(bShow ? true : false);
            ((class ASInteractiveObject*)(class ASDisplayObjectContainer*)(pContainer.get()))->FUN_1422deb40(bShow ? true : false);
        }
    }
}
MS2_REPLACE(0x1412761e0, FUN_1412761e0, 223, 0xBC6F98B8);

// ---- camera-scaled offset ---------------------------------------------------------------------------------------------
struct Unk_Point2 { float m_x, m_y; public:
    float FUN_140affe70() const;   // C3: was free FUN_140affe70
};
// the class's own unit defines s_instance / GetInstance out of line (explicit specializations): only declared here, so
// this obj does not instantiate a second copy (LNK2005 in the full-exe link)
template<> class TSingleton<CameraMgr> { public: static CameraMgr* s_instance; static CameraMgr* GetInstance(); };
class Unk_Vec2Pair;
class Unk_Vec2 {
public:
    float m_x, m_y;
    Unk_Vec2* FUN_140a0a600(float x, float y);                                      // constructs in place, returns this
    Unk_Vec2Pair* FUN_140a4e500(Unk_Vec2Pair* pOut, const Unk_Vec2* pRhs);          // this - rhs
};
class Unk_Vec2Pair {
public:
    float m_x, m_y;
};
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    int FUN_140a18070();
    Vector3 FUN_140a17e10();
};
// CameraMgr::FUN_140a17e10 returns a Vector3 (12 bytes) by value. The type has a user ctor (never called here), so it
// is returned through a hidden pointer and is not a /GS buffer.
float FUN_141032df0(void*);
float FUN_141032e60(void*);
float FUN_14028aed0(float);

// @0x1412762d0
float FUN_1412762d0(const Unk_Point2* pPos)
{
    float fZoomRaw;
    float fLength;
    float fRatio;
    float fMaxAngle;
    float fAngle;
    float fZero;
    float fRange;
    float fT;
    float fBase;
    float fZoom;
    if (((class CameraMgr*)(void*)(TSingleton<CameraMgr>::GetInstance()))->FUN_140a18070() == 0)
        return 0.0f;
    Vector3 vOrigin = TSingleton<CameraMgr>::GetInstance()->FUN_140a17e10();
    Unk_Vec2 vFromBuf, vToBuf;
    Unk_Vec2Pair vDelta;
    fLength = ((struct Unk_Point2*)(class Unk_Vec2Pair*)(vToBuf.FUN_140a0a600(vOrigin.x, vOrigin.y)->FUN_140a4e500(&vDelta, vFromBuf.FUN_140a0a600(pPos->m_x, pPos->m_y))))->FUN_140affe70();
    fBase = -40.0f;
    fRange = 70.0f;
    fZoomRaw = FUN_141032df0(TSingleton<CameraMgr>::GetInstance());
    if (fLength <= fZoomRaw)
        fRatio = 1.0f;
    else
        fRatio = fZoomRaw / fLength;
    fZoom = fRatio;
    fMaxAngle = 90.0f;
    fAngle = FUN_141032e60(TSingleton<CameraMgr>::GetInstance());
    fZero = 0.0f;
    fT = (std::max)(fZero, (std::min)(fAngle, fMaxAngle));
    return FUN_14028aed0((fBase + (fRange * fT) / 90.0f) * fZoom);
}
MS2_REPLACE(0x1412762d0, FUN_1412762d0, 390, 0x7A9ACA89);

struct Unk_Info140e09150 {
    __int64 m_pad_00;
    float m_fValue;
};
class Unk_ChaosSettings   // C3: member view for the former free stand-ins
{
public:
    struct Unk_ChaosOpt* FUN_140e09150();
};

// @0x141276460
float FUN_141276460()
{
    return ((struct Unk_Info140e09150*)((class Unk_ChaosSettings*)(void*)(TSingleton<CGameOption>::GetInstance()))->FUN_140e09150())->m_fValue;
}
MS2_REPLACE(0x141276460, FUN_141276460, 27, 0x15D9A2BD);

// ---- screen scale -----------------------------------------------------------------------------------------------------
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int GetSceneId();
    int GetSubSceneId();
};
bool FUN_14028d470(float, float);

float FUN_141276490(float fWidth, float fHeight);
#ifndef MS2_HOOK_DLL
// @0x141276490
float FUN_141276490(float fWidth, float fHeight)
{
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::FUN_1408e57f0())))->GetSceneId() == 0x6200018)
        return 1.0f;
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::FUN_1408e57f0())))->GetSubSceneId() != 0x620001d)
        fHeight = 1.0f;
    const Unk_ScaleMap::CPair* pPair = s_scaleCache.Lookup(Unk_ScreenKey(fWidth, fHeight));
    if (pPair != 0)
        return pPair->m_value;
    float fScale = 1.0f;
    float fRefWidth = 1920.0f;
    if (fWidth >= fRefWidth)
        fScale = 1.0f;
    else if (fWidth > 1366.0f)
        fScale = 2.0f - fWidth / fRefWidth;
    else if (fWidth > 1279.0f)
        fScale = 2.1f - fWidth / fRefWidth;
    else if (fWidth > 1024.0f)
        fScale = 2.2f - fWidth / fRefWidth;
    else if (fWidth == 1024.0f)
        fScale = 2.32f - fWidth / fRefWidth;
    if ((!FUN_14028d470(fScale, 1.0f) || !FUN_14028d470(fHeight, 1.0f)) && !FUN_14028d470(fHeight, 1.0f))
    {
        float fScalePct = fScale * 100.0f;
        float fHeightPct = fHeight * 100.0f;
        fScale = (fScalePct * fHeightPct) / 10000.0f;
    }
    s_scaleCache.SetAt(Unk_ScreenKey(fWidth, fHeight), fScale);
    return fScale;
}
#endif

// ---- console window ---------------------------------------------------------------------------------------------------
class Unk_GdTextArea : public CPtred {
public:
    virtual void vfunc_01(); virtual void vfunc_02(); virtual void vfunc_03();
    virtual void vfunc_04(); virtual void vfunc_05(); virtual void vfunc_06(); virtual void vfunc_07();
    virtual void vfunc_08(); virtual void vfunc_09(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bFlag);                                // +0xc0
};
class ASTextInput {
public:
    void FUN_1422e0b80(const CString& strText);
    void FUN_1422e1430(const CStringW& strText);
};
class ASTextArea   // C3: member view for the former free stand-ins
{
public:
    void FUN_1422e4720();
};
CStringW FUN_14183e930(const CStringW&, unsigned nColor);
CStringW FUN_14061ad70(const CStringW&, const wchar_t*);

// @0x141276700
void FUN_141276700(MS2Ptr<Unk_GdTextArea> console)
{
    {
        CString strEmpty("");
        reinterpret_cast<ASTextInput*>(console.operator->())->FUN_1422e0b80(strEmpty);
    }
    Unk_GdTextArea* pView = console.operator->();
    pView->vfunc_24(true);
}
MS2_REPLACE(0x141276700, FUN_141276700, 124, 0x0745A959);

// @0x141276790
void FUN_141276790(MS2Ptr<Unk_GdTextArea> console)
{
    Unk_GdTextArea* pView = console.operator->();
    pView->vfunc_24(true);
    ((class ASTextArea*)(console.operator->()))->FUN_1422e4720();
}
MS2_REPLACE(0x141276790, FUN_141276790, 88, 0x0E6E447B);

// @0x1412767f0
void FUN_1412767f0(MS2Ptr<Unk_GdTextArea> console)
{
    CStringW strLine(L"------------------------------------------\n");
    reinterpret_cast<ASTextInput*>(console.operator->())->FUN_1422e1430(FUN_14183e930(strLine, 0xffff));
}
MS2_REPLACE(0x1412767f0, FUN_1412767f0, 136, 0xF81C6C2B);

// @0x141276880
void FUN_141276880(MS2Ptr<Unk_GdTextArea> console, int nColor, const wchar_t* pszFormat, ...)
{
    CStringW str;
    va_list args;
    va_start(args, pszFormat);
    str.FormatV(pszFormat, args);
    va_end(args);
    reinterpret_cast<ASTextInput*>(console.operator->())->FUN_1422e1430(FUN_14183e930(FUN_14061ad70(str, L"\n"), nColor));
}
MS2_REPLACE(0x141276880, FUN_141276880, 246, 0x4A32C7FC);

// ---- filters ----------------------------------------------------------------------------------------------------------
class UITalkCinematic : public UISwfEntity { };
UITalkCinematic* FUN_140a7b2b0(int nId) noexcept;
bool FUN_1401647e0(const CString&, const CString&) noexcept;

// @0x141276980
int FUN_141276980()
{
    UITalkCinematic* pHolder = FUN_140a7b2b0(0x4e40);
    bool bMatch = pHolder != 0 && FUN_1401647e0(pHolder->FUN_1422db6e0(), s_strEmpty);
    if (bMatch)
        return 0;
    return 1;
}

class CommonString* FUN_14025e7d0();   // C3: was FUN_14025e7d0

// @0x141276a30
int FUN_141276a30(const CStringW& str, CStringW& strOut)
{
    {
        MS2Ptr<CBanTextChecker> filter = FUN_14025e7d0()->GetChecker();
        if ((CBanTextChecker*)filter != 0) {
            if (filter->FUN_140225210(str, strOut, 1) != 0)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE(0x141276a30, FUN_141276a30, 139, 0x026130D4);

// @0x141276ad0
int FUN_141276ad0(const CStringW& strName, int* pnResult, unsigned nMask)
{
    if ((nMask & 4) != 0) {
        PCBase* pPlayer = static_cast<PCBase*>(((class WorldService*)(void*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPlayer != 0) {
            if (strName.CompareNoCase(pPlayer->vfunc_77()) == 0) {
                *pnResult = 4;
                return 0;
            }
        }
    }
    if ((nMask & 2) != 0) {
        MS2Ptr<CBanTextChecker> filter = FUN_14025e7d0()->GetChecker();
        if ((CBanTextChecker*)filter != 0) {
            CStringW strOut;
            if (filter->FUN_140225210(strName, strOut, 0) != 0) {
                *pnResult = 2;
                return 0;
            }
        }
    }
    *pnResult = 1;
    return 1;
}
MS2_REPLACE(0x141276ad0, FUN_141276ad0, 413, 0x0BBFEC7E);

// @0x141276c80
int FUN_141276c80(const CStringW& strName, bool bCheckSelf, CStringW& strOut)
{
    if (bCheckSelf) {
        PCBase* pPlayer = static_cast<PCBase*>(((class WorldService*)(void*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPlayer != 0) {
            if (strName.CompareNoCase(pPlayer->vfunc_77()) == 0) {
                strOut = GetStringCommon(0);
                return 10;
            }
        }
    }
    {
        MS2Ptr<CBanTextChecker> filter = FUN_14025e7d0()->GetChecker();
        if ((CBanTextChecker*)filter != 0) {
            int nResult = filter->FUN_140225210(strName, strOut, 0);
            return nResult;
        }
    }
    return 0;
}
MS2_REPLACE(0x141276c80, FUN_141276c80, 378, 0xC17F18AE);

// @0x141276e00
int FUN_141276e00(const CStringW& strName, CStringW& strOut)
{
    PCBase* pPlayer = static_cast<PCBase*>(((class WorldService*)(void*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPlayer != 0) {
        bool bSame = strName.CompareNoCase(pPlayer->vfunc_77()) == 0;
        if (bSame) {
            strOut = GetStringCommon(0);
            return 10;
        }
    }
    {
        MS2Ptr<CBanTextChecker> filter = FUN_14025e7d0()->GetChecker();
        if ((CBanTextChecker*)filter != 0) {
            int nResult = filter->FUN_140225210(strName, strOut, 0);
            if (nResult != 0)
                return nResult;
        }
    }
    return 0;
}
MS2_REPLACE(0x141276e00, FUN_141276e00, 365, 0xC07834C7);

// ---- chat send --------------------------------------------------------------------------------------------------------
// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
class Unk_InventoryStateManager* FUN_140a6a830();   // C3: was FUN_140a6a830
CStringW FUN_140a2fcd0(__int64 nBegin, __int64 nEnd);
CStringW GetStringCommonByKey(const CStringW& strKey);
void FUN_140710590(COutPacket&);
extern int DAT_143ab2914;
void FUN_1401fa700(unsigned char*, class COutputStream&);

// @0x141276f80
int FUN_141276f80(Unk_CommandChat* pChat)
{
    int nKind = pChat->kind;
    if (nKind == 4) {
        CStringW strReply;
        int nResult = FUN_141276e00(pChat->target, strReply);
        if (nResult != 0) {
            int nStringId = (nResult == 10) ? 0x430 : 0x431;
            FUN_1412751b0(GetStringCommon(nStringId), 0x14);
            return 0;
        }
    }
    {
        BlockPtr penalty = reinterpret_cast<CBlockManager*>(FUN_140a6a830())->FindBlockedAction(2);
        if (penalty.get() != 0) {
            if (penalty->kind == 2) {
                FUN_1412751b0(GetStringCommon(0x433), 0x14);
            } else {
                CStringW strRemain = FUN_140a2fcd0((__int64)penalty->m_38, penalty->expiry);
                FUN_1412751b0(GetStringCommon(0x442), 0x14);
                FUN_1412751b0(strRemain, 0x14);
            }
            return 0;
        }
    }
    if (DAT_143ab2914 < 0x32) {
        int nRestricted = WorldService::GetInstance()->FUN_141bd30a0()->FUN_140375660(0x100);
        if (nRestricted != 0) {
            FUN_1412751b0(GetStringCommonByKey(L"s_field_limit_content_chat"), 0x14);
            return 0;
        }
    }
    COutPacket packet(static_cast<int>(SendOp::UserChat), 0);
    FUN_1401fa700(reinterpret_cast<unsigned char*>(pChat), reinterpret_cast<COutputStream&>(packet));
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE(0x141276f80, FUN_141276f80, 867, 0x9FE0BD97);

// ---- number / icon helpers --------------------------------------------------------------------------------------------
// @0x1412772f0
int FUN_1412772f0(__int64 nValue, int bGrouped)
{
    char szBuf[24];
    CString strDigits(_i64toa(nValue, szBuf, 10));
    int nLen = strDigits.GetLength();
    if (bGrouped != 0)
        nLen += nLen * 0.33;
    return nLen;
}
MS2_REPLACE(0x1412772f0, FUN_1412772f0, 162, 0x506850F8);

// @0x1412773a0
int FUN_1412773a0(int nValue)
{
    char szBuf[16];
    int nLen;
    {
        CString strDigits(_itoa(nValue, szBuf, 10));
        nLen = strDigits.GetLength();
    }
    return nLen;
}
MS2_REPLACE(0x1412773a0, FUN_1412773a0, 106, 0x48A5ECDC);

// @0x141277410
CStringW FUN_141277410(int nIconCode)
{
    int nStringId = 0;
    switch (nIconCode) {
    case 0x00: nStringId = 0x52c; break;
    case 0x01: nStringId = 0x52d; break;
    case 0x02: nStringId = 0x52e; break;
    case 0x03: nStringId = 0x52f; break;
    case 0x04: nStringId = 0x530; break;
    case 0x05: nStringId = 0x531; break;
    case 0x06: nStringId = 0x532; break;
    case 0x07: nStringId = 0x533; break;
    case 0x08: nStringId = 0x534; break;
    case 0x09: nStringId = 0x535; break;
    case 0x0a: nStringId = 0x536; break;
    case 0x0b: nStringId = 0x537; break;
    case 0x0c: nStringId = 0x538; break;
    case 0x0d: nStringId = 0x539; break;
    case 0x0e: nStringId = 0x53b; break;
    case 0x0f: nStringId = 0x53c; break;
    case 0x10: nStringId = 0x53d; break;
    case 0x11: nStringId = 0x53e; break;
    case 0x12: nStringId = 0x53f; break;
    case 0x13: nStringId = 0x540; break;
    case 0x14: nStringId = 0x541; break;
    case 0x15: nStringId = 0x542; break;
    case 0x16: nStringId = 0x543; break;
    case 0x17: nStringId = 0x544; break;
    case 0x18: nStringId = 0x545; break;
    case 0x19: nStringId = 0x546; break;
    case 0x1a: nStringId = 0x547; break;
    case 0x1b: nStringId = 0x548; break;
    case 0x1c: nStringId = 0x549; break;
    case 0x1d: nStringId = 0x54a; break;
    case 0x1e: nStringId = 0x54b; break;
    case 0x1f: nStringId = 0x54c; break;
    case 0x20: nStringId = 0x54d; break;
    case 0x21: nStringId = 0x54e; break;
    case 0x22: nStringId = 0x53a; break;
    case 0x23: nStringId = 0x54f; break;
    case 0x24: nStringId = 0x551; break;
    case 0x25: nStringId = 0x550; break;
    case 0x26: nStringId = 0x552; break;
    case 0x27: nStringId = 0x553; break;
    case 0x28: nStringId = 0x554; break;
    case 0x29: nStringId = 0x555; break;
    case 0x2a: nStringId = 0x556; break;
    case 0x2b: nStringId = 0x557; break;
    case 0x2c: nStringId = 0x558; break;
    case 0x2d: nStringId = 0x559; break;
    case 0x2e: { CStringW strKey(L"s_word_iconcode_pettaminggoods"); return GetStringCommonByKey(strKey); }
    case 0x2f: { CStringW strKey(L"s_word_iconcode_petgoods"); return GetStringCommonByKey(strKey); }
    case 0x30: { CStringW strKey(L"s_word_iconcode_interiorskill"); return GetStringCommonByKey(strKey); }
    case 0x31: { CStringW strKey(L"s_word_iconcode_interiormessage"); return GetStringCommonByKey(strKey); }
    case 0x32: { CStringW strKey(L"s_word_iconcode_lapenshard"); return GetStringCommonByKey(strKey); }
    case 0x34: nStringId = 0x55a; break;
    case 0x35: nStringId = 0x55b; break;
    }
    return GetStringCommon(nStringId);
}
MS2_REPLACE(0x141277410, FUN_141277410, 1056, 0x44216BDE);

// ---- item / icon names ------------------------------------------------------------------------------------------------
class Unk_IconItemData : public CItemData {
};
class Unk_SlotLapenTable* FUN_1409c4b30();   // C3: was FUN_1409c4b30

CStringW FUN_141277be0(MS2Ptr<CItemData> item);
CStringW FUN_141277b90(const CStringW& str);

// @0x141277910
CStringW FUN_141277910(MS2Ptr<CItemData> item)
{
    if (item.IsNull() != 0)
        return CStringW(L"");
    if (reinterpret_cast<Unk_IconItemData*>(item.operator->())->FUN_14053cbc0() != 0)
        return TSingleton<CStringTable>::GetInstance()->FUN_141811980(8, reinterpret_cast<Unk_IconItemData*>(item.operator->())->FUN_14053c620());
    if (reinterpret_cast<Unk_IconItemData*>(item.operator->())->IsLapenshardType() != 0)
        return FUN_141277be0(item);
    return FUN_141277410(reinterpret_cast<Unk_IconItemData*>(item.operator->())->GetIconCode());
}
MS2_REPLACE(0x141277910, FUN_141277910, 365, 0x0A17FA5D);

// @0x141277a90
CStringW FUN_141277a90(CUgcItemLook* pSource, const CStringW& strFallback)
{
    if (pSource->FUN_140893520() != 0)
        return GetStringCommon(0xf4);
    if (pSource->GetLocalPath().GetLength() > 0)
        return FUN_141277b90(pSource->m_str28);
    return CStringW(strFallback);
}
MS2_REPLACE(0x141277a90, FUN_141277a90, 236, 0xA59909FA);

// @0x141277b90
CStringW FUN_141277b90(const CStringW& str)
{
    return CStringW(str);
}
MS2_REPLACE(0x141277b90, FUN_141277b90, 59, 0x41F5801C);

// @0x141277be0
CStringW FUN_141277be0(MS2Ptr<CItemData> item)
{
    MS2Ptr<CItemLapenshardData> lapen = reinterpret_cast<CItemLapenshardTable*>(FUN_1409c4b30())->Get(reinterpret_cast<Unk_IconItemData*>(item.operator->())->GetItemId());
    if (lapen.get() != 0) {
        switch (lapen->m_nMask)
        {
        case 1:
        {
            CStringW strKey(L"s_word_iconcode_lapenshard_red");
            return GetStringCommonByKey(strKey);
        }
        case 2:
        {
            CStringW strKey(L"s_word_iconcode_lapenshard_blue");
            return GetStringCommonByKey(strKey);
        }
        case 4:
        {
            CStringW strKey(L"s_word_iconcode_lapenshard_green");
            return GetStringCommonByKey(strKey);
        }
        }
    }
    return FUN_141277410(reinterpret_cast<Unk_IconItemData*>(item.operator->())->GetIconCode());
}
MS2_REPLACE(0x141277be0, FUN_141277be0, 478, 0xA2D611FC);

class Unk_ConstString : public Scaleform::GFx::Value {
public:
    bool FUN_141278ab0() { return GetType() == 7; }              // COMDAT 0x141278ab0
    const wchar_t* FUN_1412788a0() { return mValue.pStringW; }   // COMDAT 0x1412788a0
};
CStringW XmlWide(const char*);

// @0x141277dd0
CStringW FUN_141277dd0(Unk_ConstString* pValue)
{
    return CStringW(pValue->FUN_141278ab0() ? pValue->FUN_1412788a0() : (const wchar_t*)XmlWide(pValue->GetString()));
}
MS2_REPLACE(0x141277dd0, FUN_141277dd0, 194, 0x729980BF);

// @0x141277f40
int FUN_141277f40()
{
    return 0;
}
MS2_REPLACE(0x141277f40, FUN_141277f40, 3, 0x94777CFF);

// @0x141277f50
int FUN_141277f50()
{
    return 3;
}
MS2_REPLACE(0x141277f50, FUN_141277f50, 6, 0x76552545);

// @0x141277f60
CString FUN_141277f60(int nLayer)
{
    switch (nLayer) {
    case 0: return CString("GC_Gfx HUD");
    case 2: return CString("GC_Gfx Main");
    case 3: return CString("GC_Gfx PostDisplay");
    case 4: return CString("GC_Gfx Background");
    case 5: return CString("GC_Gfx Tooltip");
    case 6: return CString("GC_Gfx MouseCursor");
    case 1: return CString("GC_Gfx Damage");
    }
    return CString("");
}
MS2_REPLACE(0x141277f60, FUN_141277f60, 367, 0xF155C2F4);

// @0x1412780f0
unsigned FUN_1412780f0(Unk_McValue<unsigned>* pSlot)
{
    return Unk_ColorValue(*(struct Unk_ConstColor const*)(reinterpret_cast<Unk_NpcConstant<unsigned>*>(pSlot)->Get()));
}
MS2_REPLACE(0x1412780f0, FUN_1412780f0, 32, 0x2D2EB095);

// @0x141278110
UISystemText* FUN_141278110(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0) {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get() != 0)
            return dynamic_cast<UISystemText*>(ref.operator UIObject*());
    }
    return 0;
}
MS2_REPLACE(0x141278110, FUN_141278110, 147, 0xBEDFD4A1);

// @0x1412781b0
UITopLayerNotify* FUN_1412781b0(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0) {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get() != 0)
            return dynamic_cast<UITopLayerNotify*>(ref.operator UIObject*());
    }
    return 0;
}
MS2_REPLACE(0x1412781b0, FUN_1412781b0, 147, 0x619EFE61);
