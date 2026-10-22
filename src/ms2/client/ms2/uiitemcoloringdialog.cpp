// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item dye page of the beauty shop (UIItemColoringDialog).
//
// The page lists the dyeable equipment of the player, previews a palette colour (or a detail colour) on the selected
// item through the customize controller, collects the dyed items in a basket and buys them in one bill (UIBillDialog
// 0x4e7b; packet 0x23/0x16 with one CCItemColoringPacket::ChangeColorItem per basket item). The beauty shop packet 0x31
// carries the shop (mode 1) and the dye results (mode 8).
// MS2-UNIT: ?\uiitemcoloringdialog.cpp
// MS2-RANGE: 0x1419abdd0-0x1419b3c50 .text$mn
// MS2-RANGE: 0x140115140-0x140115380 .text$di
// MS2-PIN: memmove_s 0x1419b3b30 ; unique
// MS2-PIN: ??1ChangeColors@CCItemColoringPacket@@UEAA@XZ 0x1419b32c0
// MS2-FUNCTIONAL: ??1ChangeColors (inline in ccitemcoloringpacket.h): CAtlArray dtor inlining differs
// MS2-PIN: ??C?$MS2Ptr@VASArray@@@@QEBAPEAVASArray@@XZ 0x1419b3340
// MS2-PIN: ??0?$MS2Ptr@VTData@UIBillDialog@@@@QEAA@PEAVTData@UIBillDialog@@@Z 0x1419b3190
// MS2-PIN: ?AddRef@?$MS2Ptr@VTData@UIBillDialog@@@@AEBAXXZ 0x1419b3600
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VTData@UIBillDialog@@@@AEBAXPEAX@Z 0x1419b3630
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemColoringDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419b3660
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemColoringDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419b3720
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemcoloringdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/uiitemcoloringdialog.h"
#ifndef MS2_HOOK_DLL
static CString s_strItemSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x140115140
#endif
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/citemextradata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/ccitemcoloringpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// GetChild COMDATs are owned by unit_140ba6b20 (ASMovieClip, 0x140ba7930) and uibingoeventdialog (0x140bb4b10)
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);
template <> MS2Ptr<Unk_140acd6e0> UISwfEntity::GetChild<Unk_140acd6e0>(const CString& strName);

MS2_EMIT_CRT_MEMMOVE_S();

// ---- local stand-ins for classes whose units are not recovered yet ----

class NotifyChangeActiveMyCodiTab : public NotifyObject
{
public:
    NotifyChangeActiveMyCodiTab();
    virtual ~NotifyChangeActiveMyCodiTab();
    bool m_bActive;                             // +0x18 the "my codi" tab is still valid
};
MS2_CHECK_OFFSET(NotifyChangeActiveMyCodiTab, m_bActive, 0x18);

class UISceneGameBeautyShop : public UISwfEntity
{
public:
    virtual ~UISceneGameBeautyShop();
};
class UIMessageBox : public UISwfEntity
{
public:
    virtual ~UIMessageBox();
};

// A button child ("m_save", "m_reset", "m_addBasket").
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(unsigned int bEnabled);  // enable / disable
    int FUN_1422c2030();                        // enabled
};

class ASFunction : public AScript
{
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, CItem* pUser, int nMovieId);
    virtual ~ASFunction();
private:
    void* m_40;
};

// The player.
class Unk_IcPlayer : public PCBase
{
public:
    MS2Ptr<CItem> FUN_141655b80(__int64 nUid);  // the inventory item
};
class Unk_IcEquipSet;
Unk_IcEquipSet* FUN_1416561a0(PCBase* pPc);
void FUN_1411e3000(Unk_IcEquipSet* pSet, ATL::CAtlList<MS2Ptr<CEquipItem> >* pList, int nType, int a4, int a5);
int FUN_14123c580(PCBase* pPc);                 // object id
int FUN_141658f30(PCBase* pPc);                 // level
void FUN_14166cc40(PCBase* pPc, int nPose);
int FUN_141421690(CItem* pItem);                // the item is locked
class Unk_IcCapItem : public CItemData {};
class Unk_IcEquip : public CEquipItem
{
public:
    MS2Ptr<CItem> FUN_1411dc7a0();
    Unk_IcCapItem* FUN_1411dc7f0();
    int FUN_1411dcda0();
};
CItemData* FUN_140527840(CItem* pItem);         // the item's data record
CItemExtraData* FUN_140527870(CItem* pItem);    // the item's extra data (colours)
CString FUN_140528590(CItem* pItem);            // icon path

class Unk_IcField
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69();
    virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76(); virtual void vfunc_77(); virtual void vfunc_78(); virtual void vfunc_79();
    virtual void vfunc_80(); virtual void vfunc_81(); virtual void vfunc_82(); virtual void vfunc_83(); virtual void vfunc_84(); virtual void vfunc_85(); virtual void vfunc_86(); virtual void vfunc_87(); virtual void vfunc_88(); virtual void vfunc_89();
    virtual void vfunc_90(); virtual void vfunc_91(); virtual void vfunc_92(); virtual void vfunc_93(); virtual void vfunc_94(); virtual void vfunc_95(); virtual void vfunc_96(); virtual void vfunc_97(); virtual void vfunc_98(); virtual void vfunc_99();
    virtual void vfunc_100(); virtual void vfunc_101(); virtual void vfunc_102(); virtual void vfunc_103(); virtual void vfunc_104(); virtual void vfunc_105(); virtual void vfunc_106(); virtual void vfunc_107(); virtual void vfunc_108(); virtual void vfunc_109();
    virtual void vfunc_110(); virtual void vfunc_111(); virtual void vfunc_112(); virtual void vfunc_113(); virtual void vfunc_114(); virtual void vfunc_115(); virtual void vfunc_116(); virtual void vfunc_117(); virtual void vfunc_118(); virtual void vfunc_119();
    virtual void vfunc_120(); virtual void vfunc_121(); virtual void vfunc_122(); virtual void vfunc_123(); virtual void vfunc_124(); virtual void vfunc_125(); virtual void vfunc_126(); virtual void vfunc_127(); virtual void vfunc_128(); virtual void vfunc_129();
    virtual void vfunc_130(); virtual void vfunc_131(); virtual void vfunc_132(); virtual void vfunc_133(); virtual void vfunc_134(); virtual void vfunc_135(); virtual void vfunc_136(); virtual void vfunc_137(); virtual void vfunc_138(); virtual void vfunc_139();
    virtual void vfunc_140(); virtual void vfunc_141(); virtual void vfunc_142(); virtual void vfunc_143(); virtual void vfunc_144(); virtual void vfunc_145(); virtual void vfunc_146(); virtual void vfunc_147(); virtual void vfunc_148();
    virtual void vfunc_149();                   // 149 restore the field camera
};
class Unk_IcWorld
{
public:
    Unk_IcPlayer* FUN_141bd0cc0();              // the player (NULL outside the game)
    Unk_IcField* FUN_141bd3620();
};
Unk_IcWorld* FUN_1403ed2d0();

class Unk_IcUIMgr
{
public:
    void FUN_141adc530(int nId);                // open
    void FUN_141adc5d0(int nId);                // close
    int FUN_141adc890(int nId);                 // is open
};
Unk_IcUIMgr* FUN_1403ed2b0();

class Unk_IcPlatform
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42();
    virtual void vfunc_43(int nEvent, int a2, int nDelay);
};
Unk_IcPlatform* FUN_140d86260();

class Unk_IcOptions { public: bool FUN_14036d570(int nId); };
Unk_IcOptions* FUN_140166410();
class Unk_IcStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_IcStrings* FUN_1401a9d70();
class Unk_IcGameEvents
{
public:
    int FUN_140476cf0(int nEvent, int nLevel);                          // 0: the sale applies
    unsigned FUN_140476c70(int nEvent, unsigned nPrice, int nLevel);    // the sale price
};
Unk_IcGameEvents* FUN_1401c0d90();
class Unk_IcCutScene { public: bool FUN_14116d840(); };
Unk_IcCutScene* FUN_14025e7c0();
class Unk_IcNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);
};
Unk_IcNotices* FUN_140939a10();
class Unk_IcPackets
{
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> cb);
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> cb);
};
Unk_IcPackets* FUN_140bccd50();
class Unk_IcItemEvents
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);
    void FUN_1419caeb0(UIItemEventListener* pListener);
};
Unk_IcItemEvents* FUN_140a6a840();
Unk_BSCamera* FUN_140cd47b0(int nId);
class Unk_IcSound;
Unk_IcSound* FUN_1408e57f0();
void FUN_1422b9fd0(Unk_IcSound* p, int nEvent);
class Unk_IcInventory { public: int FUN_140a5f7b0(int nItemId, int n); int FUN_140a60ec0(int nItemId); };
extern Unk_IcInventory DAT_143ab2a90;
unsigned FUN_140869420();                       // the tick count
int FUN_14109a9e0();                            // rand

// The hair apply effect.
struct Unk_IcEffectRequest
{
    CString m_strName;                          // +0x00 effect xml
    int m_n08;                                  // +0x08
    char m_pad_0c[0x78 - 0x0c];
};
MS2_CHECK_SIZE(Unk_IcEffectRequest, 0x78);
class Unk_IcEffectMgr { public: void FUN_1411a4a00(Unk_IcEffectRequest* pRequest); };
Unk_IcEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_IcEffectRequest* p);         // construct
void FUN_140a53190(Unk_IcEffectRequest* p, int nObjectId);
void FUN_1405a89e0(Unk_IcEffectRequest* p);         // destroy
struct Unk_IcEffectPaths { char m_pad_0[0x2e0]; CString m_hairApply; };   // +0x2e0
Unk_IcEffectPaths* FUN_1401d31f0();

// Message boxes and strings.
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_140d73aa0(CStringW strText, int nType, IMessageListener* pListener, CStringW strTag);
void FUN_14151f200();
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nId);
CStringW FUN_14052bd00(int nId, const CStringW& a);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);
CStringW FUN_1409eb450(int n);
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& strName, const int& n);
CStringW FUN_14183e930(CStringW strName, int nRarity);
int FUN_141275c00(int nRarity);
void FUN_1412752d0(const CStringW& strKey, int nType);
void FUN_1412761e0(MS2Ptr<AScript> spRoot, int bEnable);   // enable the root's input
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& arr, const wchar_t* szSep, int nMax);
bool FUN_140841300(const CStringW& str, const char* sz);
__int64 FUN_141b71960(const char* sz);
int FUN_141b71a10(const char* sz);
CStringW FUN_141b71990(unsigned n);
CStringW FUN_141b71910(__int64 n);
CString FUN_14016a600(const wchar_t* psz, int nCodePage);
int FUN_1409c17e0(const Scaleform::GFx::Value& v);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_140f024e0(ASData* pData, int* pA, int* pB);           // the two int arguments

// The beauty shop helpers (uibeautyshopstyledialog.cpp).
CStringW FUN_14134a220(Unk_BSFee* pFee, const unsigned __int64* pPrice);   // the price text
void FUN_14134a2e0(Unk_BSFee* pFee);                                       // "not enough" message
__int64 FUN_141349ef0(int nFeeType, int a2, unsigned nPrice);              // the money left after paying
void FUN_140f014f0(MS2Ptr<Customize> spCustomize);                         // leave the preview
void FUN_140f01540(ASObj& obj, bool b);
bool FUN_140f01670(ASTooltip* pTooltip, int nItemId, ASData* pArgs);
void FUN_140f328a0(MS2Ptr<Customize> spCustomize, ASObj& obj, int n);
int FUN_140f32290(ASObj& obj, MS2Ptr<CItemData> spData, MS2Ptr<Customize> spCustomize, int a4, int a5, int a6);
bool FUN_140f02a80(unsigned nPalette, unsigned nColor);                    // the default colour
UIBillDialog* FUN_140f0a350(int nId);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
enum Unk_BSResult : unsigned int {};
CStringW BlockFormat(int, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, BlockFormat, int)
CStringW LocalizedMentorFormat(const CStringW&, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, LocalizedMentorFormat, CStringW)

class Unk_IcCustomizeListener : public IItemCustomizeEventListener {};
int FUN_140cd60e0(IItemCustomizeEventListener* p);     // the coupon box is checked
int FUN_140cd5950(IItemCustomizeEventListener* p);     // coupons used

int FUN_1419b1fd0(MS2Ptr<Customize> spCustomize, const __int64* pUid, int nIndex, CString strTag, IMessageListener* pListener);

// ---- static initializers (.text$di) ----
// (s_strItemSortNames above and the statics of header_statics_a.h)

// ---- UIItemColoringDialog ----

// @0x1419abdd0
UIItemColoringDialog::UIItemColoringDialog()
    : m_198(0), m_19c(5000), m_1a0(0), m_250(-1), m_260(false), m_264(0), m_278(10), m_2a8(10), m_2d8(0)
{
    m_2c = 0xc;
    m_80 = 0;
    m_88 = 1;
    m_58 = 0;
    FUN_141925e70(0, 1);
    FUN_140bccd50()->FUN_140da5180(0x31, Delegate<void(CInPacket&)>(this, &UIItemColoringDialog::FUN_1419b00b0));
}

// @0x1419ac060
UIItemColoringDialog::~UIItemColoringDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0x31, Delegate<void(CInPacket&)>(this, &UIItemColoringDialog::FUN_1419b00b0));
}

// @0x1419ac1d0
CString UIItemColoringDialog::GetTypeName()
{
    return "ItemColoringDialog";
}
MS2_REPLACE_METHOD(0x1419ac1d0, UIItemColoringDialog, GetTypeName, 61, 0x40CB051C);

// @0x1419ac220
void UIItemColoringDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_1419ae790();
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc != 0)
        pPc->FUN_14166ed70(0x56057c6);
    m_198 = 0;
    m_268 = 0;
    m_2d8 = 0;
    m_250 = -1;
    m_254 = std::pair<unsigned, unsigned>(0, 0);
    m_260 = false;
    m_264 = 0;
    m_2a8.RemoveAll();
    m_278.RemoveAll();
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::FUN_1419adbe0));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::FUN_1419addc0));
}
MS2_REPLACE_METHOD(0x1419ac220, UIItemColoringDialog, vfunc_67, 788, 0xC7A1D4F8);

// @0x1419ac540
int UIItemColoringDialog::vfunc_74(int a1, void* p2, void* p3)
{
    return UIDialog::vfunc_74(a1, p2, p3);
}
MS2_REPLACE_METHOD(0x1419ac540, UIItemColoringDialog, vfunc_74, 52, 0xE735FA8A);

// @0x1419ac580
void UIItemColoringDialog::OnLoadInit()
{
    UIDialog::OnLoadInit();
    m_2d8 = FUN_140cd47b0(0x4ef2);
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::FUN_1419adbe0));
}
MS2_REPLACE_METHOD(0x1419ac580, UIItemColoringDialog, OnLoadInit, 245, 0xE6DA347E);

// @0x1419ac680
void UIItemColoringDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    m_198 = FUN_140869420();
    m_19c = (FUN_14109a9e0() % 6 + 5) * 1000;
    m_268.AssignRaw(new Customize(FUN_14123c580(pPc), static_cast<IItemCustomizeEventListener*>(this), 0));
    FUN_1419afe30();
    m_25c = 1;
    FUN_140d86260()->vfunc_43(0xe, 0, 1000);
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::FUN_1419addc0));
}
MS2_REPLACE_METHOD(0x1419ac680, UIItemColoringDialog, OnLoadComplete, 618, 0x1F43C844);

// @0x1419ac8f0
int UIItemColoringDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d840()) {
        FUN_1419ae9f0();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419ac8f0, UIItemColoringDialog, vfunc_13, 74, 0x91CBCDB2);

// @0x1419ac940
void UIItemColoringDialog::vfunc_15()
{
    if (vfunc_55() != 0)
        return;
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (m_268 == 0)
        return;
    if (m_2d8 != 0)
        m_2d8->FUN_1418dda30(m_268->FUN_140cd27f0() == 0);
    m_268->FUN_140cd1bf0();
    if ((unsigned)(FUN_140869420() - m_198) > m_19c) {
        FUN_1419ae790();
        m_198 = FUN_140869420();
        m_19c = (FUN_14109a9e0() % 6 + 5) * 1000;
    }
}
MS2_REPLACE_METHOD(0x1419ac940, UIItemColoringDialog, vfunc_15, 308, 0x5788D810);

// @0x1419aca80
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int UIItemColoringDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0) {
        if (dynamic_cast<UISceneGameBeautyShop*>(pSender) != 0) {
            if (pMsg->FUN_1422b8d30() == "OnExit") {
                FUN_1419ae9f0();
                return 1;
            }
        } else if (dynamic_cast<UIMessageBox*>(pSender) != 0) {
            int nResult = pMsg->FUN_1422b8a10();
            CStringW strTag = pMsg->FUN_1422b8f40();
            FUN_14151f200();
            if (nResult == 0 && strTag == L"errorcoloring") {
                FUN_1419ae940();
                return 1;
            }
            ATL::CAtlArray<CStringW> aParts;
            if (FUN_14028cb70(strTag, aParts, L",", 4) != 0) {
                CStringW strCmd = aParts[0];
                if (strCmd == L"changeitem") {
                    __int64 nUid = FUN_141b71960(FUN_14016a600(aParts[1], 0));
                    int nIndex = _wtoi(aParts[2]);
                    CStringW strNext = aParts[3];
                    if (m_268.get() != 0) {
                        __int64 nPrev = m_268->FUN_140cd1980();
                        if (nPrev != 0) {
                            if (nResult == 0) {
                                m_30->FUN_1409ba0d0("forceAddBasket", m_250, nIndex == -1);
                            } else {
                                m_268->FUN_140cd2210(nPrev);
                                if (nIndex < 0)
                                    FUN_1419af290();
                            }
                        }
                    }
                    if (nUid != 0)
                        FUN_1419b02c0(nUid, nIndex);
                    if (strNext == L"clickSave")
                        FUN_1419b0ef0();
                }
            }
            return 1;
        } else if (dynamic_cast<UIBillDialog*>(pSender) != 0) {
            int nResult = pMsg->FUN_1422b8a10();
            m_10 = pMsg->FUN_1422b8a90() != 0;
            if (nResult == 0) {
                FUN_1419af290();
                FUN_1419af980();
            }
            return 1;
        }
    }
    return 0;
}

// @0x1419acfb0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int UIItemColoringDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnChangeItem", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            data.FUN_1422b8d30();
            __int64 nUid = FUN_141b71960(data.FUN_1422b8d30());
            FUN_1419aebc0(&nUid, data.FUN_1422b8a10());
            return 1;
        }
    } else if (_stricmp("OnChangeInvalidItemIndex", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            data.FUN_1422b8a10();
            m_250 = -1;
        }
    } else {
        if (_stricmp("OnChangeColor", szMethod) == 0) {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs)) {
                data.FUN_1422b8a10();
                CString strName = data.FUN_1422b8d30();
                ASObj obj(data.FUN_1422b9260(), 2);
                unsigned nColor = FUN_1409c17e0(obj.FUN_1422baa20("colorSN"));
                unsigned nPalette = FUN_1409c17e0(obj.FUN_1422baa20("paletteID"));
                m_254 = std::pair<unsigned, unsigned>(nPalette, nColor);
                FUN_1419aeea0(nPalette, nColor);
                FUN_1419b0620(0);
            }
            return 1;
        }
        if (_stricmp("OnChangeDetailColor", szMethod) == 0) {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs)) {
                m_254 = std::pair<unsigned, unsigned>(0, 0);
                int nPalette = 0;
                int nColor = 0;
                FUN_140f024e0(&data, &nPalette, &nColor);
                FUN_1419aef10(nPalette, nColor);
                FUN_1419b0620(0);
            }
            return 1;
        }
        if (_stricmp("onClickAddBasket", szMethod) == 0) {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs)) {
                int nItemId = FUN_141b71a10(data.FUN_1422b8d30());
                if (m_268.get() != 0 && FUN_1403ed2d0()->FUN_141bd0cc0() != 0) {
                    MS2Ptr<CItem> spItem = FUN_1419b1440(nItemId);
                    if (spItem.get() != 0)
                        FUN_1419aeb50();
                }
            }
            return 1;
        }
        if (_stricmp("onClickSubBasket", szMethod) == 0) {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs)) {
                int nItemId = FUN_141b71a10(data.FUN_1422b8d30());
                if (m_268.get() != 0 && FUN_1403ed2d0()->FUN_141bd0cc0() != 0) {
                    MS2Ptr<CItem> spItem = FUN_1419b1590(nItemId);
                    if (spItem.get() != 0)
                        FUN_1419aeb50();
                }
            }
            return 1;
        }
        if (_stricmp("OnClickSave", szMethod) == 0) {
            __int64 nUid = 0;
            if (FUN_1419b1fd0(m_268, &nUid, -1, CString("clickSave"), static_cast<IMessageListener*>(this)) == 0)
                FUN_1419b0ef0();
            return 1;
        }
        if (_stricmp("OnClickReset", szMethod) == 0) {
            if (m_268.get() != 0) {
                __int64 nPrev = m_268->FUN_140cd1980();
                m_268->FUN_140cd2210(nPrev);
                ASObj obj(2);
                FUN_140f328a0(m_268, obj, 6);
                m_30->Invoke("buildResetItem", Scaleform::GFx::Value(obj.FUN_1422bb870()));
            }
            return 1;
        }
        if (_stricmp("OnClickClose", szMethod) == 0) {
            FUN_1419ae9f0();
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419acfb0, UIItemColoringDialog, vfunc_28, 2633, 0xCB086DC6);

// @0x1419ada20
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (_stricmp("getTooltipFee", strMethod) == 0) {
        int nTotal = 0;
        ASArray rows(2);
        FUN_1419b0b10(&rows, &nTotal);
        *pRetVal = rows.FUN_1422bb870();
    } else if (_stricmp("getTooltipColor", strMethod) == 0 && m_268 != 0) {
        MS2Ptr<CItem> spItem = m_268->FUN_140cd1890();
        if (spItem != 0) {
            ASTooltip tooltip(1, 2);
            if (FUN_140f01670(&tooltip, spItem->FUN_1405276c0(), pArgs))
                *pRetVal = tooltip.FUN_1422bb870();
        }
    }
}
MS2_REPLACE_METHOD(0x1419ada20, UIItemColoringDialog, vfunc_45, 433, 0x15B149A3);

// @0x1419adbe0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419adbe0(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent != 0 && FUN_140841300(pEvent->m_eventName, "SaleBeautyShop")) {
        FUN_1419af2f0((unsigned)FUN_1419b1710());
        if (MS2Ptr<ASMovieClip> spPcBang = GetChild<ASMovieClip>("m_pcBang")) {
            int nSale = FUN_1401c0d90()->FUN_140476cf0(FUN_1418ce5b0(), FUN_1419b1a50());
            spPcBang->vfunc_4(nSale == 0);
        }
        UIBillDialog* pBill;
        if (FUN_1403ed2b0()->FUN_141adc890(0x4e7b) != 0 && (pBill = FUN_140f0a350(0x4e7b)) != 0)
            pBill->FUN_1418cda70(FUN_1419b1af0((unsigned)FUN_1419b1710()));
    }
}
MS2_REPLACE_METHOD(0x1419adbe0, UIItemColoringDialog, FUN_1419adbe0, 471, 0x44A00205);

// @0x1419addc0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419addc0(NotifyObject* pNotify)
{
    if (!(m_30 == 0) && !(m_268 == 0)) {
        NotifyChangeActiveMyCodiTab* pTab = dynamic_cast<NotifyChangeActiveMyCodiTab*>(pNotify);
        if (pTab == 0 || pTab->m_bActive) {
            if (m_260 == false)
                FUN_1419b1b50();
            else
                FUN_1419ae940();
        } else {
            CStringW strKey(L"s_beauty_msg_restart_by_expired_codi");
            FUN_140d74390(GetStringCommonByKey(strKey), 0, Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemColoringDialog::FUN_1419b1d70));
        }
    }
}
MS2_REPLACE_METHOD(0x1419addc0, UIItemColoringDialog, FUN_1419addc0, 439, 0x99B7D012);

// @0x1419adf80
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::vfunc_24(void* p)
{
    CItem* pItem = static_cast<CItem*>(p);
    if (!(FUN_1403ed2d0()->FUN_141bd0cc0() != 0 && m_30.get() != 0 && vfunc_55() == 0))
        return;
    int nItemId = pItem->FUN_1405276c0();
    if (FUN_1419b1590(nItemId).get() != 0)
        FUN_1419b1f50(-1);
    m_30->Invoke("removeBasketItem", FUN_141b71990(nItemId));
    if (m_2a8.IsEmpty())
        FUN_1419af840();
}

// @0x1419ae170
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419ae170()
{
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    m_278.RemoveAll();
    ATL::CAtlList<MS2Ptr<CEquipItem> > equips(10);
    FUN_1411e3000(FUN_1416561a0(pPc), &equips, 4, 0, 1);
    ASArray items(2);
    for (POSITION pos = equips.GetHeadPosition(); pos != NULL; equips.GetNext(pos)) {
        MS2Ptr<CEquipItem> spEquip = equips.GetAt(pos);
        if (spEquip.get() == 0)
            continue;
        Unk_IcEquip* pEquip = static_cast<Unk_IcEquip*>(spEquip.operator->());
        if (FUN_141421690(pEquip->FUN_1411dc7a0().get()) != 0)
            continue;
        MS2Ptr<CItem> spItem = pEquip->FUN_1411dc7a0();
        if (spItem == 0)
            continue;
        Unk_IcCapItem* pData = pEquip->FUN_1411dc7f0();
        if (pData == 0)
            continue;
        if (pEquip->FUN_1411dcda0() == 0)
            continue;
        if (!pData->FUN_14053e170())
            continue;
        int nItemId = pData->FUN_14053c510();
        ASObj obj(2);
        obj.FUN_1407cbb20("guid", FUN_141b71910(spItem->FUN_140526a50()));
        obj.FUN_1407cbb20("itemid", FUN_141b71990(nItemId));
        obj.FUN_1407cbb20("itemname", FUN_1401a9d70()->FUN_141811980(1, nItemId));
        obj.FUN_1407cba60("iconPath", FUN_140528590(spItem.operator->()));
        ASFunction tooltip(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemColoringDialog::FUN_1419afcd0),
                           spItem.get(), FUN_1422db730());
        obj.FUN_1409adbe0("tooltipFunction", Scaleform::GFx::Value(tooltip.FUN_1422bb870()));
        items.FUN_1422bc050(Scaleform::GFx::Value(obj.FUN_1422bb870()));
        m_278.AddTail(spItem);
    }
    m_30->Invoke("buildItems", Scaleform::GFx::Value(items.FUN_1422bb870()), -1);
}
MS2_REPLACE_METHOD(0x1419ae170, UIItemColoringDialog, FUN_1419ae170, 1558, 0xF5106CDC);

// @0x1419ae790
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419ae790()
{
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc != 0 && !(m_268 == 0)) {
        MS2Ptr<CItemData> spData = FUN_14053f870(m_268->FUN_140cd17e0());
        if (spData.get() != 0) {
            int nPose = 0;
            if (spData->FUN_14053c620() == 0xd)
                nPose = 0x4c;
            else if (spData->FUN_14053c620() == 0x10)
                nPose = 0x51;
            else if (spData->FUN_14053c620() == 0x12)
                nPose = 0x52;
            else if (spData->FUN_14053c620() == 0x11)
                nPose = 0x53;
            else if (spData->FUN_14053c5c0() == 2)
                nPose = 0x4e;
            if (nPose != 0) {
                if (pPc->FUN_14166c930() != 0xe)
                    pPc->vfunc_59(0xe, 0, 0, 0);
                FUN_14166cc40(pPc, nPose);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1419ae790, UIItemColoringDialog, FUN_1419ae790, 411, 0xAC05A2F3);

// @0x1419ae940
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
bool UIItemColoringDialog::FUN_1419ae940()
{
    if (m_268 == 0)
        return false;
    FUN_140f014f0(m_268);
    Unk_IcField* pField = FUN_1403ed2d0()->FUN_141bd3620();
    if (pField != 0)
        pField->vfunc_149();
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
    return true;
}
MS2_REPLACE_METHOD(0x1419ae940, UIItemColoringDialog, FUN_1419ae940, 163, 0x937074BA);

// @0x1419ae9f0
void UIItemColoringDialog::FUN_1419ae9f0()
{
    if (FUN_1419aef80() != 0) {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommon(0x271), 1);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemColoringDialog::FUN_1419b1d00));
        spBox->FUN_141a01800(2);
        FUN_140d73c60(spBox);
    } else {
        FUN_1419ae940();
    }
}
MS2_REPLACE_METHOD(0x1419ae9f0, UIItemColoringDialog, FUN_1419ae9f0, 338, 0xB7886C44);

// @0x1419aeb50
void UIItemColoringDialog::FUN_1419aeb50()
{
    FUN_1419af050(m_2a8.IsEmpty() == false);
    FUN_1419af2f0((unsigned)FUN_1419b1710());
}
MS2_REPLACE_METHOD(0x1419aeb50, UIItemColoringDialog, FUN_1419aeb50, 94, 0x70A4DBA6);

// @0x1419aebc0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419aebc0(const __int64* pUid, int nIndex)
{
    bool bAsk = true;
    if (m_268.get() != 0 && m_268->FUN_140cd1890().get() != 0 && FUN_140f02a80(m_254.first, m_254.second)) {
        bAsk = false;
        m_268->FUN_140cd2210(m_268->FUN_140cd1980());
        if (nIndex < 0)
            FUN_1419af290();
    }
    if (bAsk) {
        if (FUN_1419b1fd0(m_268, pUid, nIndex, CString(""), static_cast<IMessageListener*>(this)) != 0)
            return;
        m_268->FUN_140cd2210(m_268->FUN_140cd1980());
    }
    FUN_1419b02c0(*pUid, nIndex);
}
MS2_REPLACE_METHOD(0x1419aebc0, UIItemColoringDialog, FUN_1419aebc0, 723, 0x72ACCCE6);

// @0x1419aeea0
void UIItemColoringDialog::FUN_1419aeea0(unsigned nPalette, unsigned nColor)
{
    if (m_268 == 0)
        return;
    m_268->FUN_140cd3220(nPalette, nColor, 0);
}
MS2_REPLACE_METHOD(0x1419aeea0, UIItemColoringDialog, FUN_1419aeea0, 92, 0x5F263C17);

// @0x1419aef10
void UIItemColoringDialog::FUN_1419aef10(int nPalette, int nColor)
{
    if (m_268 == 0)
        return;
    m_268->FUN_140cd32f0(nPalette, nColor, 0);
}
MS2_REPLACE_METHOD(0x1419aef10, UIItemColoringDialog, FUN_1419aef10, 93, 0x9C2EF510);

// @0x1419aef80
int UIItemColoringDialog::FUN_1419aef80()
{
    if (m_30.get() != 0) {
        if (MS2Ptr<Unk_140acd6e0> spButton = GetChild<Unk_140acd6e0>("m_save"))
            return spButton->FUN_1422c2030();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419aef80, UIItemColoringDialog, FUN_1419aef80, 189, 0x409C1BE8);

// @0x1419af050
void UIItemColoringDialog::FUN_1419af050(int bEnable)
{
    if (m_30.get() != 0) {
        if (MS2Ptr<Unk_140acd6e0> spButton = GetChild<Unk_140acd6e0>("m_save"))
            spButton->FUN_1422c1fe0(bEnable);
    }
}
MS2_REPLACE_METHOD(0x1419af050, UIItemColoringDialog, FUN_1419af050, 172, 0x929EDA32);

// @0x1419af110
void UIItemColoringDialog::FUN_1419af110(int bEnable)
{
    if (m_30.get() != 0) {
        if (MS2Ptr<Unk_140acd6e0> spButton = GetChild<Unk_140acd6e0>("m_reset"))
            spButton->FUN_1422c1fe0(bEnable);
    }
}
MS2_REPLACE_METHOD(0x1419af110, UIItemColoringDialog, FUN_1419af110, 172, 0xF4E3DD79);

// @0x1419af1d0
void UIItemColoringDialog::FUN_1419af1d0(int bEnable)
{
    if (m_30.get() != 0) {
        if (MS2Ptr<Unk_140acd6e0> spButton = GetChild<Unk_140acd6e0>("m_addBasket"))
            spButton->FUN_1422c1fe0(bEnable);
    }
}
MS2_REPLACE_METHOD(0x1419af1d0, UIItemColoringDialog, FUN_1419af1d0, 172, 0xEC497619);

// @0x1419af290
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419af290()
{
    if (m_30.get() == 0)
        return;
    m_30->Invoke("forceClearSelected");
}
MS2_REPLACE_METHOD(0x1419af290, UIItemColoringDialog, FUN_1419af290, 83, 0x441CCDD4);

// @0x1419af2f0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419af2f0(unsigned nPrice)
{
    if (!(m_30 == 0)) {
        bool bSale = FUN_1401c0d90()->FUN_140476cf0(FUN_1418ce5b0(), FUN_1419b1a50()) == 0;
        if (m_2a8.IsEmpty() == false) {
            unsigned nSale = FUN_1419b1af0(nPrice);
            bool bDiscount = nPrice != nSale;
            Unk_BSFee* pFee = FUN_1419b1ac0();
            if (bDiscount) {
                unsigned __int64 nValue = nSale;
                CStringW strPrice = FUN_14134a220(pFee, &nValue);
                m_30->Invoke("setFee", FUN_1409eb450(nPrice), CStringW(strPrice), bSale, bDiscount);
            } else {
                unsigned __int64 nValue = nPrice;
                CStringW strPrice = FUN_14134a220(pFee, &nValue);
                m_30->Invoke("setFee", CStringW(strPrice), FUN_1409eb450(nSale), bSale, bDiscount);
            }
        } else {
            CStringW strDefault = GetStringCommonByKey(CStringW(L"s_beauty_fee_default"));
            m_30->Invoke("setFee", CStringW(strDefault), CStringW(strDefault), bSale, false);
        }
    }
}
MS2_REPLACE_METHOD(0x1419af2f0, UIItemColoringDialog, FUN_1419af2f0, 1105, 0xDCBE6A3E);

// @0x1419af750
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419af750()
{
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc != 0) {
        if (pPc->FUN_14166c930() != 0xe)
            pPc->vfunc_59(0xe, 0, 0, 0);
        FUN_14166cc40(pPc, 0x53);
        Unk_IcEffectRequest request;
        FUN_140a52ef0(&request);
        request.m_strName = FUN_1401d31f0()->m_hairApply;
        request.m_n08 = 1;
        FUN_140a53190(&request, FUN_14123c580(pPc));
        FUN_1403ed280()->FUN_1411a4a00(&request);
        FUN_1405a89e0(&request);
    }
}
MS2_REPLACE_METHOD(0x1419af750, UIItemColoringDialog, FUN_1419af750, 222, 0x7478D72B);

// @0x1419af840
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
bool UIItemColoringDialog::FUN_1419af840()
{
    m_260 = false;
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc != 0) {
        FUN_1419aeb50();
        FUN_1412761e0(m_30, 1);
        FUN_1419af750();
    }
    return pPc != 0;
}
MS2_REPLACE_METHOD(0x1419af840, UIItemColoringDialog, FUN_1419af840, 133, 0x113DE5AE);

// @0x1419af8d0
void UIItemColoringDialog::FUN_1419af8d0()
{
    FUN_1419b1f50(-1);
    if (m_268 == 0)
        return;
    FUN_140f014f0(m_268);
    FUN_1412761e0(m_30, 1);
}
MS2_REPLACE_METHOD(0x1419af8d0, UIItemColoringDialog, FUN_1419af8d0, 160, 0xBFC41A50);

// @0x1419af980
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int UIItemColoringDialog::FUN_1419af980()
{
    if (m_268 == 0)
        return 0;
    if (m_2a8.IsEmpty() != false)
        return 1;
    Unk_BSFee* pFee = FUN_1419b1ac0();
    int nCoupons = 0;
    if (FUN_1419b1760(&nCoupons) == 0) {
        FUN_14134a2e0(pFee);
        return 0;
    }
    m_14 = nCoupons;
    int nCount = (int)m_2a8.GetCount();
    if (m_10 == 0 || nCoupons >= nCount) {
        FUN_1419b0700();
        return 1;
    }
    int nPaid = nCount - nCoupons;
    unsigned __int64 nPrice = (unsigned)(nPaid * FUN_1419b1af0(FUN_1419b1a90()));
    CStringW strText;
    CStringW strPrice = FUN_14134a220(pFee, &nPrice);
    strText = LocalizedMentorFormat(CStringW(L"s_beauty_msg_ask_coupon_and_merat_confirm"), nCount, FUN_1419b19c0(), nCoupons, strPrice);
    FUN_140d74390(CStringW(strText), 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemColoringDialog::FUN_1419b1d40));
    return 1;
}
MS2_REPLACE_METHOD(0x1419af980, UIItemColoringDialog, FUN_1419af980, 829, 0x2D3A7545);

// @0x1419afcd0
void UIItemColoringDialog::FUN_1419afcd0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (!(!(m_30 == 0) && m_278.IsEmpty() != true))
        return;
    CItem* pUser = static_cast<CItem*>(params.pUserData);
    if (pUser == 0)
        return;
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    CItem* pItem = pPc->FUN_141655b80(pUser->FUN_140526a50()).get();
    if (pItem == 0)
        return;
    ASTooltip tooltip(pPc, 0x20, 2);
    if (tooltip.FUN_1409e0d40(pItem) == 0)
        return;
    *params.pRetVal = tooltip.FUN_1422bb870();
}
MS2_REPLACE_METHOD(0x1419afcd0, UIItemColoringDialog, FUN_1419afcd0, 336, 0x43BD46A6);

// @0x1419afe30
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int UIItemColoringDialog::FUN_1419afe30()
{
    if (!m_30)
        return 0;
    if (m_1a8.m_18 == 0)
        return 0;
    if (m_1a8.m_1c != 5)
        return 0;
    if (m_1a0 != 3)
        return 0;
    vfunc_8(1);
    int nSale = FUN_1401c0d90()->FUN_140476cf0(FUN_1418ce5b0(), FUN_1419b1a50());
    bool bOption = FUN_140166410()->FUN_14036d570(0xb6);
    ASObj obj(2);
    FUN_140f01540(obj, bOption);
    CStringW strDefault = GetStringCommonByKey(CStringW(L"s_beauty_fee_default"));
    m_30->Invoke("initData", CStringW(strDefault), nSale == 0, bOption, Scaleform::GFx::Value(obj.FUN_1422bb870()));
    FUN_1419ae170();
    return 1;
}
MS2_REPLACE_METHOD(0x1419afe30, UIItemColoringDialog, FUN_1419afe30, 624, 0x56F62AE0);

// @0x1419b00b0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419b00b0(CInPacket& packet)
{
    unsigned nMode = packet.ReadUInt8();
    if (nMode == 8) {
        if (vfunc_55() == 0) {
            Unk_BSResult nResult = (Unk_BSResult)packet.ReadInt32();
            if (nResult == 2) {
                FUN_14134a2e0(FUN_1419b1ac0());
            } else {
                FUN_140d73aa0(BlockFormat(0x272, nResult), 0, static_cast<IMessageListener*>(this), CStringW(L"errorcoloring"));
            }
            if (nResult != 0)
                FUN_1419af8d0();
        }
    } else if (nMode == 1) {
        m_1a0 = packet.ReadUInt8();
        m_1a8.FUN_1406e5420(packet);
        if (m_25c != 0)
            FUN_1419afe30();
    }
}
MS2_REPLACE_METHOD(0x1419b00b0, UIItemColoringDialog, FUN_1419b00b0, 514, 0x88E2A9D0);

// @0x1419b02c0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419b02c0(__int64 nUid, int nIndex)
{
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!(pPc != 0 && !(m_268 == 0)))
        return;
    m_268->FUN_140cd2700(nUid);
    MS2Ptr<CItem> spItem = m_268->FUN_140cd1890();
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(FUN_140527840(spItem.operator->()));
    if (spData->FUN_14053d2f0()) {
        if (pPc->FUN_14166c930() != 0xe)
            pPc->vfunc_59(0xe, 0, 0, 0);
        FUN_14166cc40(pPc, 0x55);
    } else {
        FUN_14166cc40(pPc, 0x4d);
    }
    ASObj obj(2);
    if (FUN_140f32290(obj, spData, m_268, 3, 0xf, 0) != 0) {
        CItemExtraData* pExtra = FUN_140527870(spItem.operator->());
        if (pExtra != 0)
            m_254 = std::pair<unsigned, unsigned>((unsigned)pExtra->FUN_14059a0b0(0), pExtra->FUN_14059a040(0));
        m_30->Invoke("buildCurrentItem", Scaleform::GFx::Value(obj.FUN_1422bb870()));
    }
    FUN_1419b0620(1);
    m_250 = nIndex;
}
MS2_REPLACE_METHOD(0x1419b02c0, UIItemColoringDialog, FUN_1419b02c0, 845, 0x93B847FF);

// @0x1419b0620
void UIItemColoringDialog::FUN_1419b0620(int n)
{
    if (m_268 == 0)
        return;
    if (m_268->FUN_140cd2a00() != 0) {
        FUN_1419af110(1);
        if (FUN_140f02a80(m_254.first, m_254.second)) {
            FUN_1419af1d0(0);
        } else if (m_268->FUN_140cd2ea0() != 0) {
            FUN_1419af1d0(1);
        }
    } else {
        FUN_1419af110(0);
        FUN_1419af1d0(0);
    }
}
MS2_REPLACE_METHOD(0x1419b0620, UIItemColoringDialog, FUN_1419b0620, 217, 0x07FE26A8);

// @0x1419b0700
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419b0700()
{
    CCItemColoringPacket::ChangeColors request;
    COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
    packet.Encode1(0x16);
    int nCount = 0;
    for (POSITION pos = m_2a8.GetHeadPosition(); pos != NULL; m_2a8.GetNext(pos)) {
        MS2Ptr<CItem> spBasket = m_2a8.GetAt(pos);
        if (spBasket == 0)
            continue;
        MS2Ptr<CItem> spItem(0);
        m_268->FUN_140cd2360(spBasket->FUN_140526a50(), spItem);
        if (spItem == 0)
            continue;
        Unk_PayloadPtr<CCItemColoringPacket::ChangeColorItem> spChange(new CCItemColoringPacket::ChangeColorItem());
        if (spChange == 0)
            continue;
        spChange->flag18 = FUN_140cd60e0(static_cast<IItemCustomizeEventListener*>(this)) != 0;
        spChange->type = spItem->FUN_1405276c0();
        spChange->flag19 = FUN_140cd5950(static_cast<IItemCustomizeEventListener*>(this)) > 0;
        spChange->value28 = spItem->FUN_140526a50();
        spChange->extra = FUN_140527870(spItem.operator->());
        request.FUN_140200bc0(spChange);
        nCount++;
    }
    request.FUN_140200950(packet);
    FUN_140710590(packet);
    FUN_1419b1f50(nCount);
    FUN_1412761e0(m_30, 0);
}
MS2_REPLACE_METHOD(0x1419b0700, UIItemColoringDialog, FUN_1419b0700, 1022, 0xDA0BC7FD);

// @0x1419b0b10
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int UIItemColoringDialog::FUN_1419b0b10(ASArray* pRows, int* pTotal)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    if (m_2a8.IsEmpty() != false)
        return 0;
    CStringW strRow = GetStringCommonByKey(CStringW(L"s_bill_list_row"));
    int nCount = 0;
    CStringW strDetail;
    for (POSITION pos = m_2a8.GetHeadPosition(); pos != NULL; m_2a8.GetNext(pos)) {
        MS2Ptr<CItem> spItem = m_2a8.GetAt(pos);
        if (spItem == 0)
            continue;
        int nItemId = spItem->FUN_1405276c0();
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
        strDetail.Append(FUN_1401e8510(strRow, strName));
        nCount++;
    }
    *pTotal = 0;
    int nPrice = FUN_1419b1a90();
    if (!strDetail.IsEmpty()) {
        Unk_BSFee* pFee = FUN_1419b1ac0();
        ASObj obj(2);
        obj.FUN_1409c0dc0("category", "$s_beauty_change_color");
        *pTotal += nCount * nPrice;
        unsigned __int64 nValue = (unsigned)(nCount * nPrice);
        obj.FUN_1407cbb20("strPrice", FUN_14134a220(pFee, &nValue));
        obj.FUN_1407cbb20("detail", CStringW(strDetail));
        pRows->FUN_1422bc050(Scaleform::GFx::Value(obj.FUN_1422bb870()));
    }
    return pRows->FUN_1422bc5d0() != 0;
}
MS2_REPLACE_METHOD(0x1419b0b10, UIItemColoringDialog, FUN_1419b0b10, 977, 0x81B0198B);

// @0x1419b0ef0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int UIItemColoringDialog::FUN_1419b0ef0()
{
    UIBillDialog* pBill;
    if (m_2a8.IsEmpty() == false && (pBill = FUN_140f0a350(0x4e7b)) != 0) {
        if (MS2Ptr<ASArray> spRows = new ASArray(2)) {
            int nTotal = 0;
            if (FUN_1419b0b10(spRows.operator->(), &nTotal) != 0) {
                Unk_BSFee* pFee = FUN_1419b1ac0();
                int bCoupon = 1;
                int nCoupons = FUN_1419b1970(1);
                if (nCoupons == 0 || FUN_1419b1af0((unsigned)FUN_1419b1710()) == 0)
                    bCoupon = 0;
                if (MS2Ptr<UIBillDialog::TData> spBill = new UIBillDialog::TData()) {
                    spBill->m_18 = static_cast<IMessageListener*>(this);
                    spBill->m_30 = 0;
                    spBill->m_20 = MS2Ptr<AScript>(spRows);
                    spBill->m_60 = bCoupon;
                    spBill->m_58 = GetStringCommon(0x997);
                    CStringW strCoupon = FUN_1419b19c0();
                    CStringW strLabel(bCoupon == 0 ? CStringW(strCoupon)
                                                   : FUN_140bfa7f0(CStringW(L"s_beauty_coupon_with_count"), strCoupon, nCoupons));
                    spBill->m_50 = strLabel;
                    spBill->m_34 = pFee->FUN_1406dc510();
                    spBill->m_38 = pFee->FUN_1406dc4d0();
                    spBill->m_48 = nTotal;
                    pBill->FUN_1418cda20(spBill);
                    FUN_1403ed2b0()->FUN_141adc530(0x4e7b);
                }
                return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419b0ef0, UIItemColoringDialog, FUN_1419b0ef0, 1340, 0xD179D68F);

// @0x1419b1440
MS2Ptr<CItem> UIItemColoringDialog::FUN_1419b1440(int nItemId)
{
    if (m_268 == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spItem = m_268->FUN_140cd1890();
    if ((spItem.get() ? true : false) && spItem->FUN_1405276c0() == nItemId) {
        m_268->FUN_140cd27a0();
        m_2a8.AddTail(spItem);
        return spItem;
    }
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x1419b1440, UIItemColoringDialog, FUN_1419b1440, 327, 0xAFB3734B);

// @0x1419b1590
MS2Ptr<CItem> UIItemColoringDialog::FUN_1419b1590(int nItemId)
{
    if (m_2a8.IsEmpty() != false)
        return MS2Ptr<CItem>(0);
    for (POSITION pos = m_2a8.GetHeadPosition(); pos != NULL; m_2a8.GetNext(pos)) {
        MS2Ptr<CItem> spItem = m_2a8.GetAt(pos);
        if ((spItem.get() ? true : false) && spItem->FUN_1405276c0() == nItemId) {
            m_2a8.RemoveAt(pos);
            return spItem;
        }
    }
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x1419b1590, UIItemColoringDialog, FUN_1419b1590, 370, 0xB49F2E22);

// @0x1419b1710
__int64 UIItemColoringDialog::FUN_1419b1710()
{
    return m_2a8.GetCount() * FUN_1419b1a90();
}
MS2_REPLACE_METHOD(0x1419b1710, UIItemColoringDialog, FUN_1419b1710, 62, 0x3A336233);

// @0x1419b1760
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
bool UIItemColoringDialog::FUN_1419b1760(int* pCoupons)
{
    *pCoupons = 0;
    int nCoupons = FUN_1419b1970(m_10);
    Unk_BSFee* pFee = FUN_1419b1ac0();
    __int64 nLeft = FUN_141349ef0(pFee->FUN_1406dc510(), 0, FUN_1419b1af0((unsigned)FUN_1419b1710()));
    for (POSITION pos = m_2a8.GetHeadPosition(); pos != NULL; m_2a8.GetNext(pos)) {
        unsigned nPrice = FUN_1419b1af0(FUN_1419b1a90());
        MS2Ptr<CItem> spItem = m_2a8.GetAt(pos);
        if (spItem == 0)
            continue;
        if (m_10 == 0 || nCoupons < 1) {
            nLeft -= nPrice;
        } else {
            *pCoupons += 1;
            nCoupons--;
        }
    }
    return nLeft >= 0;
}
MS2_REPLACE_METHOD(0x1419b1760, UIItemColoringDialog, FUN_1419b1760, 395, 0xCC307ED7);

// @0x1419b1900
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
bool UIItemColoringDialog::FUN_1419b1900(int bCoupon)
{
    if (bCoupon == 0 || m_1a8.m_2c == 0)
        return false;
    return DAT_143ab2a90.FUN_140a60ec0(m_1a8.m_2c) == 1;
}
MS2_REPLACE_METHOD(0x1419b1900, UIItemColoringDialog, FUN_1419b1900, 94, 0x9C2766CC);

// @0x1419b1970
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int UIItemColoringDialog::FUN_1419b1970(int bCoupon)
{
    if (bCoupon == 0 || m_1a8.m_2c == 0)
        return 0;
    return DAT_143ab2a90.FUN_140a5f7b0(m_1a8.m_2c, 0);
}
MS2_REPLACE_METHOD(0x1419b1970, UIItemColoringDialog, FUN_1419b1970, 69, 0xC1358579);

// @0x1419b19c0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
CStringW UIItemColoringDialog::FUN_1419b19c0()
{
    if (m_1a8.m_20 == 0)
        return GetStringCommon(0x995);
    return FUN_1401a9d70()->FUN_141811980(1, m_1a8.m_20);
}
MS2_REPLACE_METHOD(0x1419b19c0, UIItemColoringDialog, FUN_1419b19c0, 126, 0x454EE4C7);

// @0x1419b1a50
int UIItemColoringDialog::FUN_1419b1a50()
{
    Unk_IcPlayer* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    return FUN_141658f30(pPc);
}
MS2_REPLACE_METHOD(0x1419b1a50, UIItemColoringDialog, FUN_1419b1a50, 54, 0x5A0DD506);

// @0x1419b1a90
unsigned UIItemColoringDialog::FUN_1419b1a90()
{
    return m_1a8.FUN_1406e3de0()->FUN_1406dc4f0();
}
MS2_REPLACE_METHOD(0x1419b1a90, UIItemColoringDialog, FUN_1419b1a90, 41, 0x566B4A3E);

// @0x1419b1ac0
Unk_BSFee* UIItemColoringDialog::FUN_1419b1ac0()
{
    return m_1a8.FUN_1406e3de0();
}
MS2_REPLACE_METHOD(0x1419b1ac0, UIItemColoringDialog, FUN_1419b1ac0, 33, 0x48B69FD3);

// @0x1419b1af0
unsigned UIItemColoringDialog::FUN_1419b1af0(unsigned nPrice)
{
    return FUN_1401c0d90()->FUN_140476c70(FUN_1418ce5b0(), nPrice, FUN_1419b1a50());
}
MS2_REPLACE_METHOD(0x1419b1af0, UIItemColoringDialog, FUN_1419b1af0, 77, 0x270DC376);

// @0x1419b1b50
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
bool UIItemColoringDialog::FUN_1419b1b50()
{
    if (m_30 != 0 && m_268 != 0) {
        if (m_260 == true) {
            CStringW strKey(L"s_beauty_msg_wait_by_expired_codi");
            FUN_1412752d0(strKey, 1);
            return false;
        }
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e7b);
        FUN_1419b1e40(m_2a8);
        FUN_1419b1e40(m_278);
        m_268->FUN_140cd2210(m_268->FUN_140cd1980());
        m_268->FUN_140cd2700(0);
        m_268->FUN_140cd3820();
        FUN_140f014f0(m_268);
        FUN_1419b1db0();
        FUN_1419aeb50();
        FUN_1419ae170();
        return true;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419b1b50, UIItemColoringDialog, FUN_1419b1b50, 422, 0x961642A6);

// @0x1419b1d00
bool UIItemColoringDialog::FUN_1419b1d00(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        FUN_1419ae940();
    FUN_14151f200();
    return true;
}
MS2_REPLACE_METHOD(0x1419b1d00, UIItemColoringDialog, FUN_1419b1d00, 47, 0x8E5829C1);

// @0x1419b1d40
bool UIItemColoringDialog::FUN_1419b1d40(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        FUN_1419b0700();
    return true;
}
MS2_REPLACE_METHOD(0x1419b1d40, UIItemColoringDialog, FUN_1419b1d40, 42, 0xC35DA1D7);

// @0x1419b1d70
bool UIItemColoringDialog::FUN_1419b1d70(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        return FUN_1419b1b50();
    return true;
}
MS2_REPLACE_METHOD(0x1419b1d70, UIItemColoringDialog, FUN_1419b1d70, 44, 0xB2E3A35A);

// @0x1419b1db0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
void UIItemColoringDialog::FUN_1419b1db0()
{
    if (m_30 == 0 || m_2a8.IsEmpty() != false)
        return;
    m_2a8.RemoveAll();
    m_30->Invoke("forceRemoveBasketItemAll");
}
MS2_REPLACE_METHOD(0x1419b1db0, UIItemColoringDialog, FUN_1419b1db0, 134, 0x5B58A172);

// @0x1419b1e40
void UIItemColoringDialog::FUN_1419b1e40(ATL::CAtlList<MS2Ptr<CItem> >& list)
{
    if (m_268 == 0 || list.IsEmpty() != false)
        return;
    for (POSITION pos = list.GetHeadPosition(); pos != NULL; list.GetNext(pos)) {
        MS2Ptr<CItem> spItem = list.GetAt(pos);
        if (spItem == 0)
            continue;
        m_268->FUN_140cd2210(spItem->FUN_140526a50());
    }
}
MS2_REPLACE_METHOD(0x1419b1e40, UIItemColoringDialog, FUN_1419b1e40, 254, 0x7D656948);

// @0x1419b1f50
void UIItemColoringDialog::FUN_1419b1f50(int nDelta)
{
    m_264 += nDelta;
    if (m_264 < 0)
        m_264 = 0;
    m_260 = m_264 > 0;
}
MS2_REPLACE_METHOD(0x1419b1f50, UIItemColoringDialog, FUN_1419b1f50, 118, 0x2FABD0CE);

// Ask before replacing an unsaved colour: "changeitem,<uid>,<index>,<tag>" is answered through OnMessage.
// @0x1419b1fd0
// MS2-FUNCTIONAL: code generation differs (stand-in callees / block layout)
int FUN_1419b1fd0(MS2Ptr<Customize> spCustomize, const __int64* pUid, int nIndex, CString strTag, IMessageListener* pListener)
{
    if (spCustomize == 0)
        return 0;
    if (spCustomize->FUN_140cd2ea0() == 0)
        return 0;
    CStringW strCmd;
    strCmd.Format(L"changeitem,%I64u,%d,%s", *pUid, nIndex, (const char*)strTag);
    CStringW strName;
    if (MS2Ptr<CItem> spItem = spCustomize->FUN_140cd1890()) {
        int nRarity = FUN_141275c00(spItem->FUN_140526bd0());
        strName = FUN_14183e930(spItem->FUN_140527b10(), nRarity);
    }
    FUN_140d73aa0(FUN_14052bd00(0x278, strName), 1, pListener, CStringW(strCmd));
    return 1;
}
MS2_REPLACE(0x1419b1fd0, FUN_1419b1fd0, 680, 0xEAD7E685);

// ---- template glue ----

// @0x1419b2be0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, bool a2, bool a3, Scaleform::GFx::Value a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcc70(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbecc0-0x142cbed80 .text$yd
