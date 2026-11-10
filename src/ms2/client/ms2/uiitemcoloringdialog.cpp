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
// MS2-PIN: ??C?$MS2Ptr@VASArray@@@@QEBAPEAVASArray@@XZ 0x1419b3340
// MS2-PIN: ??0?$MS2Ptr@VTData@UIBillDialog@@@@QEAA@PEAVTData@UIBillDialog@@@Z 0x1419b3190
// MS2-PIN: ?AddRef@?$MS2Ptr@VTData@UIBillDialog@@@@AEBAXXZ 0x1419b3600
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VTData@UIBillDialog@@@@AEBAXPEAX@Z 0x1419b3630
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemColoringDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419b3660
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemColoringDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419b3720
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemcoloringdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/gfxui/uimsg.h"
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
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/effectquery.h"   // C3: NoticeMessage (ctor 0x140a52ef0, dtor 0x1405a89e0, SetActor 0x140a53190)
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/formatstringid.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/client/ms2/uicameraeditdialog.h"
#include "ms2/client/ms2/equipment.h"
#include "ms2/commonfiles/usermail.h"

// GetChild COMDATs are owned by unit_140ba6b20 (ASMovieClip, 0x140ba7930) and uibingoeventdialog (0x140bb4b10)
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);
template <> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString& strName);

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
#include "ms2/placeholder/asbutton.h"   // C3: the button child is ASButton (was the stand-in Unk_140acd6e0)
//
//

class ASFunction : public AScript
{
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 pUser, int nMovieId);
    virtual ~ASFunction();
private:
    void* m_40;
};

// The player.
class Unk_IcPlayer : public PC
{
};
int FUN_141421690(CItem* pItem);                // the item is locked
struct Unk_EquipItemData : public CItemData {};   // CEquipItem::FUN_1411dc7f0's record (as customize.cpp)

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
    Unk_IcPlayer* GetLocalPlayer();              // the player (NULL outside the game)
};

class Unk_IcUIMgr
{
public:
    void FUN_141adc530(int nId);                // open
};

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
class IClientPlatform* GetClientPlatform();   // C3: was void* FUN_140d86260()

class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
void* GetGameRule();   // C3: was GetGameRule
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
class Unk_SingletonObj* FUN_140939a10();   // C3: was FUN_140939a10
class Unk_140bccd50* GetPacketHandlerManager();   // C3: was FUN_140bccd50
class Unk_ItemEventSystem
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);
    void FUN_1419caeb0(UIItemEventListener* pListener);
};
class Unk_InventoryListener* GetItemEventDispatcher();   // C3: was GetItemEventDispatcher
UICameraEditDialog* FindCameraEditDialog(eUIClassID nId);
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int SetSubScene(int);
};
extern Unk_Inventory g_143ab2a90;
int FUN_14109a9e0();                            // rand

struct Unk_IcEffectPaths { char m_pad_0[0x2e0]; CString m_hairApply; };   // +0x2e0
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource

// Message boxes and strings.
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
MS2Ptr<CMsgBoxData> ShowMessageBoxWithCallback(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void ShowMessageBox(CStringW strText, int nType, void* pListener, CStringW strTag);
void FUN_14151f200();
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nId);
CStringW FUN_1409eb450(int n);
CStringW FUN_14183e930(const CStringW& strName, unsigned nRarity);
unsigned FUN_141275c00(int nRarity);
void FUN_1412752d0(const CStringW& strKey, int nType);
void FUN_1412761e0(MS2Ptr<AScript> spRoot, int bEnable);   // enable the root's input
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& arr, const wchar_t* szSep, int nMax);
__int64 FUN_141b71960(const char* sz);
int ParseInt(const char* sz);
CStringW FUN_141b71990(unsigned n);
CStringW FUN_141b71910(__int64 n);
CString FUN_14016a600(const wchar_t* psz, int nCodePage);
void SetValue(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void SetBoolean(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_140f024e0(ASData* pData, int* pA, int* pB);           // the two int arguments

// The beauty shop helpers (uibeautyshopstyledialog.cpp).
enum ePaymentType : int;
class TShopPaymentAttr      // the fee row of the shop data
{
public:
    unsigned GetItemId() const;
    __int64 GetAmount() const;
    ePaymentType GetPaymentType() const;
};
class CBeautyShopDataCommon
{
public:
    TShopPaymentAttr& GetRecolorPayment();
};
struct Unk_ColorItems       // the view of ChangeColors in unit_1401f9eb0
{
    void FUN_140200950(COutputStream&);
    void AddItem(MS2Ptr<CCItemColoringPacket::ChangeColorItem>);
};
CStringW GetFeePriceText(Unk_BSFee* pFee, const unsigned int* pPrice);   // the price text
void FUN_14134a2e0(Unk_BSFee* pFee);                                       // "not enough" message
__int64 FUN_141349ef0(int nFeeType, int a2, unsigned nPrice);              // the money left after paying
void FUN_140f014f0(MS2Ptr<Customize> spCustomize);                         // leave the preview
void FUN_140f01540(ASObj& obj, bool b);
bool FUN_140f01670(class ASTooltip&, int, class ASData*);   // C3: was FUN_140f01670
void FUN_140f328a0(MS2Ptr<Customize> spCustomize, ASObj& obj, int n);
int FUN_140f32290(ASObj& obj, MS2Ptr<CItemData> spData, MS2Ptr<Customize> spCustomize, unsigned nFlags, int nMode, bool bColor);
bool IsPaletteColorLocked(int, int);   // C3: was IsPaletteColorLocked
UIBillDialog* FUN_140f0a350(int nId);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
enum Unk_BSResult : unsigned int {};

class Unk_IcCustomizeListener : public IItemCustomizeEventListener {};

int FUN_1419b1fd0(MS2Ptr<Customize> spCustomize, const __int64& nUid, int nIndex, CString strTag, IMessageListener* pListener);

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
    SetFlag(0, 1);
    ((PacketHandlerManager*)GetPacketHandlerManager())->RegisterHandler(0x31, Delegate<void(CInPacket&)>(this, &UIItemColoringDialog::OnBeautyShopPacket));
}

// @0x1419ac060
UIItemColoringDialog::~UIItemColoringDialog()
{
    ((PacketHandlerManager*)GetPacketHandlerManager())->UnregisterHandler(0x31, Delegate<void(CInPacket&)>(this, &UIItemColoringDialog::OnBeautyShopPacket));
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
    ((class Unk_ItemEventSystem*)GetItemEventDispatcher())->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    PlayDyePose();
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
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
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::OnGameEventChanged));
    ((class NotifySystem*)FUN_140939a10())->UnregisterNotify(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::OnActiveMyCodiTabChanged));
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
    m_2d8 = FindCameraEditDialog((eUIClassID)0x4ef2);
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(CStringW(L"NotifyGameEventChanged"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::OnGameEventChanged));
}
MS2_REPLACE_METHOD(0x1419ac580, UIItemColoringDialog, OnLoadInit, 245, 0xE6DA347E);

// @0x1419ac680
void UIItemColoringDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    ((class Unk_ItemEventSystem*)GetItemEventDispatcher())->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    m_198 = GetTickCountMs2();
    m_19c = (FUN_14109a9e0() % 6 + 5) * 1000;
    m_268.AssignRaw(new Customize(((class GameObject*)(class PCBase*)(pPc))->GetObjectId(), static_cast<IItemCustomizeEventListener*>(this), 0));
    FUN_1419afe30();
    m_25c = 1;
    ((class Unk_IcPlatform*)((void*)GetClientPlatform()))->vfunc_43(0xe, 0, 1000);
    ((class NotifySystem*)FUN_140939a10())->RegisterNotify(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                   Delegate<void(NotifyObject*)>(this, &UIItemColoringDialog::OnActiveMyCodiTabChanged));
}
MS2_REPLACE_METHOD(0x1419ac680, UIItemColoringDialog, OnLoadComplete, 618, 0x1F43C844);

// @0x1419ac8f0
int UIItemColoringDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->IsEscapePressed()) {
        RequestClose();
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
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    if (m_268 == 0)
        return;
    if (m_2d8 != 0)
        m_2d8->SetEnableFlagIfHidden(m_268->IsDragging() == 0);
    m_268->UpdateEditItems();
    if ((unsigned)(GetTickCountMs2() - m_198) > m_19c) {
        PlayDyePose();
        m_198 = GetTickCountMs2();
        m_19c = (FUN_14109a9e0() % 6 + 5) * 1000;
    }
}
MS2_REPLACE_METHOD(0x1419ac940, UIItemColoringDialog, vfunc_15, 308, 0x5788D810);

// @0x1419aca80
int UIItemColoringDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0) {
        if (dynamic_cast<UISceneGameBeautyShop*>(pSender) != 0) {
            CString strMethod = pMsg->FUN_1422b8d30();
            if (strMethod == "OnExit") {
                RequestClose();
                return 1;
            }
        } else if (dynamic_cast<UIMessageBox*>(pSender) != 0) {
            int nResult = pMsg->PopInt();
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
                    unsigned __int64 nUid = FUN_141b71960(FUN_14016a600(aParts[1], 0));
                    int nIndex = _wtoi(aParts[2]);
                    CStringW strNext = aParts[3];
                    if (m_268.get() != 0) {
                        unsigned __int64 nPrev = m_268->GetEditItemUid();
                        if (nPrev > 0) {
                            if (nResult == 0) {
                                int bAppend = nIndex == -1;
                                m_30->FUN_1409ba0d0("forceAddBasket", m_250, bAppend);
                            } else {
                                m_268->RestoreUid(nPrev);
                                if (nIndex < 0)
                                    ClearSelected();
                            }
                        }
                    }
                    if (nUid > 0)
                        PreviewItem(nUid, nIndex);
                    if (strNext == L"clickSave")
                        OpenBill();
                }
            }
            return 1;
        } else if (dynamic_cast<UIBillDialog*>(pSender) != 0) {
            int nResult = pMsg->PopInt();
            m_10 = pMsg->PopBool() != 0;
            if (nResult == 0) {
                ClearSelected();
                FUN_1419af980();
            }
            return 1;
        }
    }
    return 0;
}

// @0x1419acfb0
int UIItemColoringDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnChangeItem", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            data.FUN_1422b8d30();
            __int64 nUid = FUN_141b71960(data.FUN_1422b8d30());
            int nIndex = data.PopInt();
            SelectItem(&nUid, nIndex);
            return 1;
        }
    } else if (_stricmp("OnChangeInvalidItemIndex", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nIndex = data.PopInt();
            m_250 = -1;
        }
    } else if (_stricmp("OnChangeColor", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nIndex = data.PopInt();
            CString strName = data.FUN_1422b8d30();
            ASObj obj(data.PopValue(), 2);
            unsigned nColor = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(obj.GetMember("colorSN")))->GetUInt();
            unsigned nPalette = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(obj.GetMember("paletteID")))->GetUInt();
            m_254 = std::pair<unsigned, unsigned>(nPalette, nColor);
            PreviewPaletteColor(nPalette, nColor);
            RefreshButtons(0);
        }
        return 1;
    } else if (_stricmp("OnChangeDetailColor", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            m_254 = std::pair<unsigned, unsigned>(0, 0);
            int nPalette = 0;
            int nColor = 0;
            FUN_140f024e0(&data, &nPalette, &nColor);
            PreviewDetailColor(nPalette, nColor);
            RefreshButtons(0);
        }
        return 1;
    } else if (_stricmp("onClickAddBasket", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nItemId = ParseInt(data.FUN_1422b8d30());
            if (m_268.get() != 0) {
                if (void* pMy = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer())) {
                    MS2Ptr<CItem> spItem = AddCurrentItemToBasket(nItemId);
                    if (spItem.get() != 0)
                        RefreshBasketState();
                }
            }
        }
        return 1;
    } else if (_stricmp("onClickSubBasket", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            int nItemId = ParseInt(data.FUN_1422b8d30());
            if (m_268.get() != 0) {
                if (void* pMy = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer())) {
                    MS2Ptr<CItem> spItem = RemoveBasketItem(nItemId);
                    if (spItem.get() != 0)
                        RefreshBasketState();
                }
            }
        }
        return 1;
    } else if (_stricmp("OnClickSave", szMethod) == 0) {
        if (FUN_1419b1fd0(m_268, 0, -1, CString("clickSave"), static_cast<IMessageListener*>(this)) == 0)
            OpenBill();
        return 1;
    } else if (_stricmp("OnClickReset", szMethod) == 0) {
        if (m_268.get() != 0) {
            m_268->RestoreUid(m_268->GetEditItemUid());
            ASObj obj(2);
            int nFlags = 6;
            FUN_140f328a0(m_268, obj, nFlags);
            m_30->Invoke("buildResetItem", Scaleform::GFx::Value(obj.GetValue()));
        }
        return 1;
    } else if (_stricmp("OnClickClose", szMethod) == 0) {
        RequestClose();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419acfb0, UIItemColoringDialog, vfunc_28, 2633, 0xCB086DC6);

// @0x1419ada20
void UIItemColoringDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (_stricmp("getTooltipFee", strMethod) == 0) {
        int nTotal = 0;
        ASArray rows(2);
        BuildBillRows(&rows, &nTotal);
        *pRetVal = rows.GetValue();
    } else if (_stricmp("getTooltipColor", strMethod) == 0) {
        if (m_268 == 0)
            return;
        MS2Ptr<CItem> spItem = m_268->GetEditItem();
        if (spItem == 0)
            return;
        ASTooltip tooltip(1, 2);
        if (FUN_140f01670(*(class ASTooltip*)(&tooltip), spItem->GetItemId(), pArgs))
            *pRetVal = tooltip.GetValue();
    }
}
MS2_REPLACE_METHOD(0x1419ada20, UIItemColoringDialog, vfunc_45, 433, 0x15B149A3);

// @0x1419adbe0
void UIItemColoringDialog::OnGameEventChanged(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pEvent = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pEvent != 0 && pEvent->m_eventName == "SaleBeautyShop") {
        SetFee((unsigned)GetTotalPrice());
        if (MS2Ptr<ASMovieClip> spPcBang = GetChild<ASMovieClip>("m_pcBang")) {
            int nSale = ((class CGameRule*)GetGameRule())->GetSaleIndex(GetSaleEventId(), FUN_1419b1a50());
            spPcBang->vfunc_4(nSale == 0);
        }
        UIBillDialog* pBill;
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->IsDialogOpen((eUIClassID)(0x4e7b))) != 0 && (pBill = FUN_140f0a350(0x4e7b)) != 0) {
            unsigned nSale = GetSalePrice((unsigned)GetTotalPrice());
            pBill->FUN_1418cda70(nSale);
        }
    }
}
MS2_REPLACE_METHOD(0x1419adbe0, UIItemColoringDialog, OnGameEventChanged, 471, 0x44A00205);

// @0x1419addc0
void UIItemColoringDialog::OnActiveMyCodiTabChanged(NotifyObject* pNotify)
{
    if (m_30 == 0 || m_268 == 0)
        return;
    NotifyChangeActiveMyCodiTab* pTab = dynamic_cast<NotifyChangeActiveMyCodiTab*>(pNotify);
    if (pTab != 0 && !pTab->m_bActive) {
        ShowMessageBoxWithCallback(GetStringCommonByKey(L"s_beauty_msg_restart_by_expired_codi"), 0, Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemColoringDialog::OnRestartConfirm));
    } else {
        if (m_260 == false)
            Restart();
        else
            FUN_1419ae940();
    }
}
MS2_REPLACE_METHOD(0x1419addc0, UIItemColoringDialog, OnActiveMyCodiTabChanged, 439, 0x99B7D012);

// @0x1419adf80
void UIItemColoringDialog::vfunc_24(void* p)
{
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    if ((m_30.get() ? true : false) && vfunc_55() == 0) {
        int nItemId = static_cast<CItem*>(p)->GetItemId();
        if (RemoveBasketItem(nItemId).get() != 0)
            AddPendingRequests(-1);
        m_30->Invoke("removeBasketItem", FUN_141b71990(nItemId));
        if (m_2a8.IsEmpty())
            OnDyeApplied();
    }
}

// @0x1419ae170
void UIItemColoringDialog::BuildItems()
{
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    m_278.RemoveAll();
    ATL::CAtlList<MS2Ptr<CEquipItem> > equips(10);
    reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(pPc)->GetEquipment())->FUN_1411e3000(equips, 4, 0, 1);
    ASArray items(2);
    for (POSITION pos = equips.GetHeadPosition(); pos != NULL; equips.GetNext(pos)) {
        MS2Ptr<CEquipItem> spEquip = equips.GetAt(pos);
        if (spEquip.get()) {
            if (FUN_141421690(spEquip->GetItem().get()))
                continue;
            MS2Ptr<CItem> spItem = spEquip->GetItem();
            if (spItem == 0)
                continue;
            Unk_EquipItemData* pData = spEquip->GetItemData();
            if (pData == 0)
                continue;
            if (spEquip->FUN_1411dcda0() == 0)
                continue;
            if (!pData->IsCustomizable())
                continue;
            int nItemId = pData->GetItemId();
            ASObj obj(2);
            obj.SetWStringMember("guid", FUN_141b71910(spItem->GetItemUid()));
            obj.SetWStringMember("itemid", FUN_141b71990(nItemId));
            obj.SetWStringMember("itemname", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));
            obj.SetStringMember("iconPath", spItem->GetIconPath());
            ASFunction tooltip(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemColoringDialog::FUN_1419afcd0),
                               (__int64)spItem.get(), FUN_1422db730());
            obj.FUN_1409adbe0("tooltipFunction", Scaleform::GFx::Value(tooltip.GetValue()));
            items.PushValue(Scaleform::GFx::Value(obj.GetValue()));
            m_278.AddTail(spItem);
        }
    }
    m_30->Invoke("buildItems", Scaleform::GFx::Value(items.GetValue()), -1);
}
MS2_REPLACE_METHOD(0x1419ae170, UIItemColoringDialog, BuildItems, 1558, 0xF5106CDC);

// @0x1419ae790
void UIItemColoringDialog::PlayDyePose()
{
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    if (m_268 == 0)
        return;
    int nItemId = m_268->GetEditItemId();
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.get() != 0) {
        int nPose = 0;
        if (spData->GetEquipSubtype() == 0xd)
            nPose = 0x4c;
        else if (spData->GetEquipSubtype() == 0x10)
            nPose = 0x51;
        else if (spData->GetEquipSubtype() == 0x12)
            nPose = 0x52;
        else if (spData->GetEquipSubtype() == 0x11)
            nPose = 0x53;
        else if (spData->GetType() == 2)
            nPose = 0x4e;
        if (nPose != 0) {
            if (pPc->GetCurStateId() != 0xe)
                pPc->vfunc_59(0xe, 0, 0, 0);
            pPc->FUN_14166cc40(nPose);
        }
    }
}
MS2_REPLACE_METHOD(0x1419ae790, UIItemColoringDialog, PlayDyePose, 411, 0xAC05A2F3);

// @0x1419ae940
int UIItemColoringDialog::FUN_1419ae940()
{
    if (m_268 == 0)
        return 0;
    FUN_140f014f0(m_268);
    Unk_IcField* pField = reinterpret_cast<Unk_IcField*>(((WorldService*)(WorldService::GetInstance()))->FUN_141bd3620());
    if (pField != 0)
        pField->vfunc_149();
    ((class GFxSceneService*)(CUserMail::GetGFxSceneService()))->SetSubScene(0x620001d);
    return 1;
}
MS2_REPLACE_METHOD(0x1419ae940, UIItemColoringDialog, FUN_1419ae940, 163, 0x937074BA);

// @0x1419ae9f0
void UIItemColoringDialog::RequestClose()
{
    if (IsSaveEnabled() != 0) {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(GetStringCommon(0x271), 1);
        spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemColoringDialog::OnCloseConfirm));
        spBox->SetButtonPreset(2);
        FUN_140d73c60(spBox);
    } else {
        FUN_1419ae940();
    }
}
MS2_REPLACE_METHOD(0x1419ae9f0, UIItemColoringDialog, RequestClose, 338, 0xB7886C44);

// @0x1419aeb50
void UIItemColoringDialog::RefreshBasketState()
{
    SetSaveButtonEnabled(m_2a8.IsEmpty() == false);
    SetFee((unsigned)GetTotalPrice());
}
MS2_REPLACE_METHOD(0x1419aeb50, UIItemColoringDialog, RefreshBasketState, 94, 0x70A4DBA6);

// @0x1419aebc0
void UIItemColoringDialog::SelectItem(const __int64* pUid, int nIndex)
{
    bool bAsk = true;
    bool bHasColor = (m_268.get() ? true : false) && (m_268->GetEditItem().get() ? true : false);
    if (bHasColor && IsPaletteColorLocked(m_254.first, m_254.second)) {
        bAsk = false;
        m_268->RestoreUid(m_268->GetEditItemUid());
        if (nIndex < 0)
            ClearSelected();
    }
    if (bAsk) {
        int nAsked = FUN_1419b1fd0(m_268, *pUid, nIndex, CString(""), static_cast<IMessageListener*>(this));
        if (nAsked != 0)
            return;
        m_268->RestoreUid(m_268->GetEditItemUid());
    }
    PreviewItem(*pUid, nIndex);
}
MS2_REPLACE_METHOD(0x1419aebc0, UIItemColoringDialog, SelectItem, 723, 0x72ACCCE6);

// @0x1419aeea0
void UIItemColoringDialog::PreviewPaletteColor(unsigned nPalette, unsigned nColor)
{
    if (m_268 == 0)
        return;
    m_268->ApplyPalette(nPalette, nColor, 0);
}
MS2_REPLACE_METHOD(0x1419aeea0, UIItemColoringDialog, PreviewPaletteColor, 92, 0x5F263C17);

// @0x1419aef10
void UIItemColoringDialog::PreviewDetailColor(int nPalette, int nColor)
{
    if (m_268 == 0)
        return;
    m_268->SetColors(nPalette, nColor, 0);
}
MS2_REPLACE_METHOD(0x1419aef10, UIItemColoringDialog, PreviewDetailColor, 93, 0x9C2EF510);

// @0x1419aef80
int UIItemColoringDialog::IsSaveEnabled()
{
    if (m_30.get() != 0) {
        if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_save"))
            return spButton->IsEnabled();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419aef80, UIItemColoringDialog, IsSaveEnabled, 189, 0x409C1BE8);

// @0x1419af050
void UIItemColoringDialog::SetSaveButtonEnabled(int bEnable)
{
    if (m_30.get() != 0) {
        if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_save"))
            spButton->SetEnabled(bEnable);
    }
}
MS2_REPLACE_METHOD(0x1419af050, UIItemColoringDialog, SetSaveButtonEnabled, 172, 0x929EDA32);

// @0x1419af110
void UIItemColoringDialog::SetResetButtonEnabled(int bEnable)
{
    if (m_30.get() != 0) {
        if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_reset"))
            spButton->SetEnabled(bEnable);
    }
}
MS2_REPLACE_METHOD(0x1419af110, UIItemColoringDialog, SetResetButtonEnabled, 172, 0xF4E3DD79);

// @0x1419af1d0
void UIItemColoringDialog::SetAddBasketButtonEnabled(int bEnable)
{
    if (m_30.get() != 0) {
        if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_addBasket"))
            spButton->SetEnabled(bEnable);
    }
}
MS2_REPLACE_METHOD(0x1419af1d0, UIItemColoringDialog, SetAddBasketButtonEnabled, 172, 0xEC497619);

// @0x1419af290
void UIItemColoringDialog::ClearSelected()
{
    if (m_30.get() != 0)
        m_30->Invoke("forceClearSelected");
}
MS2_REPLACE_METHOD(0x1419af290, UIItemColoringDialog, ClearSelected, 83, 0x441CCDD4);

// @0x1419af2f0
void UIItemColoringDialog::SetFee(unsigned nPrice)
{
    if (m_30 == 0)
        return;
    int nLevel = FUN_1419b1a50();
    int nEvent = GetSaleEventId();
    int nResult = ((class CGameRule*)GetGameRule())->GetSaleIndex(nEvent, nLevel);
    bool bSale = nResult == 0;
    if (m_2a8.IsEmpty() != false) {
        CStringW strDefault = GetStringCommonByKey(L"s_beauty_fee_default");
        m_30->Invoke("setFee", CStringW(strDefault), CStringW(strDefault), bSale, false);
    } else {
        unsigned nSale = GetSalePrice(nPrice);
        bool bDiscount = nPrice != nSale;
        Unk_BSFee* pFee = GetFee();
        if (bDiscount) {
            unsigned __int64 nValue = nSale;
            CStringW strPrice = GetFeePriceText(pFee, reinterpret_cast<const unsigned*>(&nValue));
            m_30->Invoke("setFee", FUN_1409eb450(nPrice), CStringW(strPrice), bSale, bDiscount);
        } else {
            unsigned __int64 nValue = nPrice;
            CStringW strPrice = GetFeePriceText(pFee, reinterpret_cast<const unsigned*>(&nValue));
            m_30->Invoke("setFee", CStringW(strPrice), FUN_1409eb450(nSale), bSale, bDiscount);
        }
    }
}
MS2_REPLACE_METHOD(0x1419af2f0, UIItemColoringDialog, SetFee, 1105, 0xDCBE6A3E);

// @0x1419af750
void UIItemColoringDialog::FUN_1419af750()
{
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc != 0) {
        if (pPc->GetCurStateId() != 0xe)
            pPc->vfunc_59(0xe, 0, 0, 0);
        pPc->FUN_14166cc40(0x53);
        NoticeMessage request;   // the hair apply effect
        request.m_strName = ((struct Unk_IcEffectPaths*)GetCommonResource())->m_hairApply;
        request.m_nObject = 1;
        request.SetActor(((class GameObject*)(class PCBase*)(pPc))->GetObjectId());
        TSingleton<CEffectService>::GetInstance()->InsertEffect(*reinterpret_cast<Unk_EffectTarget*>(&request));
    }
}
MS2_REPLACE_METHOD(0x1419af750, UIItemColoringDialog, FUN_1419af750, 222, 0x7478D72B);

// @0x1419af840
int UIItemColoringDialog::OnDyeApplied()
{
    m_260 = false;
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc != 0) {
        RefreshBasketState();
        FUN_1412761e0(m_30, 1);
        FUN_1419af750();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419af840, UIItemColoringDialog, OnDyeApplied, 133, 0x113DE5AE);

// @0x1419af8d0
void UIItemColoringDialog::OnDyeFailed()
{
    AddPendingRequests(-1);
    if (m_268 == 0)
        return;
    FUN_140f014f0(m_268);
    FUN_1412761e0(m_30, 1);
}
MS2_REPLACE_METHOD(0x1419af8d0, UIItemColoringDialog, OnDyeFailed, 160, 0xBFC41A50);

// @0x1419af980
int UIItemColoringDialog::FUN_1419af980()
{
    if (m_268 == 0)
        return 0;
    if (m_2a8.IsEmpty() != false)
        return 1;
    Unk_BSFee* pFee = GetFee();
    int nCoupons = 0;
    if (FUN_1419b1760(&nCoupons) == 0) {
        FUN_14134a2e0(pFee);
        return 0;
    }
    m_14 = nCoupons;
    int nCount = (int)m_2a8.GetCount();
    if (m_10 != 0 && nCoupons < nCount) {
        int nPaid = nCount - nCoupons;
        unsigned __int64 nPrice = (unsigned)(nPaid * GetSalePrice(GetPricePerItem()));
        CStringW strText;
        CStringW strPrice = GetFeePriceText(pFee, reinterpret_cast<const unsigned*>(&nPrice));
        strText = FUN_14028dfa0(CStringW(L"s_beauty_msg_ask_coupon_and_merat_confirm"), nCount, GetCouponName(), nCoupons, strPrice);
        ShowMessageBoxWithCallback(CStringW(strText), 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemColoringDialog::OnPayConfirm));
        return 1;
    }
    FUN_1419b0700();
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
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    CItem* pItem = pPc->FUN_141655b80(pUser->GetItemUid()).get();
    if (pItem == 0)
        return;
    ASTooltip tooltip(pPc, 0x20, 2);
    if (tooltip.FUN_1409e0d40(pItem) == 0)
        return;
    *params.pRetVal = tooltip.GetValue();
}
MS2_REPLACE_METHOD(0x1419afcd0, UIItemColoringDialog, FUN_1419afcd0, 336, 0x43BD46A6);

// @0x1419afe30
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
    int nSale = ((class CGameRule*)GetGameRule())->GetSaleIndex(GetSaleEventId(), FUN_1419b1a50());
    bool bOption = ((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb6);
    ASObj obj(2);
    FUN_140f01540(obj, bOption);
    CStringW strDefault = GetStringCommonByKey(L"s_beauty_fee_default");
    bool bFree = nSale == 0;
    m_30->Invoke("initData", CStringW(strDefault), bFree, bOption, Scaleform::GFx::Value(obj.GetValue()));
    BuildItems();
    return 1;
}
MS2_REPLACE_METHOD(0x1419afe30, UIItemColoringDialog, FUN_1419afe30, 624, 0x56F62AE0);

// @0x1419b00b0
void UIItemColoringDialog::OnBeautyShopPacket(CInPacket& packet)
{
    unsigned nMode = packet.ReadUInt8();
    if (nMode == 8) {
        if (vfunc_55())
            return;
        Unk_BSResult nResult = (Unk_BSResult)packet.ReadInt32();
        switch (nResult) {
        case 2: {
            Unk_BSFee* pFee = GetFee();
            FUN_14134a2e0(pFee);
            break;
        }
        default:
            ShowMessageBox(FormatStringId(0x272, nResult), 0, static_cast<IMessageListener*>(this), CStringW(L"errorcoloring"));
            break;
        }
        if (nResult != 0)
            OnDyeFailed();
    } else if (nMode == 1) {
        m_1a0 = packet.ReadUInt8();
        m_1a8.Read(packet);
        if (m_25c != 0)
            FUN_1419afe30();
    }
}
MS2_REPLACE_METHOD(0x1419b00b0, UIItemColoringDialog, OnBeautyShopPacket, 514, 0x88E2A9D0);

// @0x1419b02c0
void UIItemColoringDialog::PreviewItem(__int64 nUid, int nIndex)
{
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return;
    if (m_268 == 0)
        return;
    m_268->SelectUid(nUid);
    MS2Ptr<CItem> spItem = m_268->GetEditItem();
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(((class CItemData*)((class CItem*)(class CItem*)(spItem.operator->()))->GetData()));
    if (spData->FUN_14053d2f0()) {
        if (pPc->GetCurStateId() != 0xe)
            pPc->vfunc_59(0xe, 0, 0, 0);
        pPc->FUN_14166cc40(0x55);
    } else {
        pPc->FUN_14166cc40(0x4d);
    }
    ASObj obj(2);
    if (FUN_140f32290(obj, spData, m_268, 3, 0xf, false) != 0) {
        CItemExtraData* pExtra = ((class CItemExtraData*)((class CItem*)(class CItem*)(spItem.operator->()))->GetProxy());
        if (pExtra != 0)
            m_254 = std::pair<unsigned, unsigned>((unsigned)pExtra->GetSlotPaletteId(0), pExtra->GetSlotColorId(0));
        m_30->Invoke("buildCurrentItem", Scaleform::GFx::Value(obj.GetValue()));
    }
    RefreshButtons(1);
    m_250 = nIndex;
}
MS2_REPLACE_METHOD(0x1419b02c0, UIItemColoringDialog, PreviewItem, 845, 0x93B847FF);

// @0x1419b0620
void UIItemColoringDialog::RefreshButtons(int n)
{
    if (m_268 == 0)
        return;
    if (m_268->FUN_140cd2a00() != 0) {
        SetResetButtonEnabled(1);
        if (IsPaletteColorLocked(m_254.first, m_254.second)) {
            SetAddBasketButtonEnabled(0);
        } else if (m_268->IsEditItemColorChanged() != 0) {
            SetAddBasketButtonEnabled(1);
        }
    } else {
        SetResetButtonEnabled(0);
        SetAddBasketButtonEnabled(0);
    }
}
MS2_REPLACE_METHOD(0x1419b0620, UIItemColoringDialog, RefreshButtons, 217, 0x07FE26A8);

// @0x1419b0700
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
        m_268->GetModifiedAndSelect(spBasket->GetItemUid(), spItem);
        if (spItem == 0)
            continue;
        MS2Ptr<CCItemColoringPacket::ChangeColorItem> spChange(new CCItemColoringPacket::ChangeColorItem());
        if (spChange == 0)
            continue;
        spChange->flag18 = GetShopId() != 0;
        spChange->type = spItem->GetItemId();
        spChange->flag19 = UseFreeTry() > 0;
        spChange->value28 = spItem->GetItemUid();
        spChange->extra = ((class CItemExtraData*)((class CItem*)(class CItem*)(spItem.operator->()))->GetProxy());
        reinterpret_cast<Unk_ColorItems*>(&request)->AddItem(spChange);
        nCount++;
    }
    reinterpret_cast<Unk_ColorItems*>(&request)->FUN_140200950(packet);
    FUN_140710590(packet);
    AddPendingRequests(nCount);
    FUN_1412761e0(m_30, 0);
}
MS2_REPLACE_METHOD(0x1419b0700, UIItemColoringDialog, FUN_1419b0700, 1022, 0xDA0BC7FD);

// @0x1419b0b10
int UIItemColoringDialog::BuildBillRows(ASArray* pRows, int* pTotal)
{
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return 0;
    if (m_2a8.IsEmpty() != false)
        return 0;
    CStringW strRow = GetStringCommonByKey(L"s_bill_list_row");
    int nCount = 0;
    CStringW strDetail;
    for (POSITION pos = m_2a8.GetHeadPosition(); pos != NULL; m_2a8.GetNext(pos)) {
        MS2Ptr<CItem> spItem = m_2a8.GetAt(pos);
        if (spItem == 0)
            continue;
        CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spItem->GetItemId());
        strDetail.Append(StringFormat(strRow, strName));
        nCount++;
    }
    *pTotal = 0;
    int nPrice = GetPricePerItem();
    if (!strDetail.IsEmpty()) {
        Unk_BSFee* pFee = GetFee();
        ASObj obj(2);
        obj.FUN_1409c0dc0("category", "$s_beauty_change_color");
        int nSum = nCount * nPrice;
        *pTotal += nSum;
        obj.SetWStringMember("strPrice", GetFeePriceText(pFee, reinterpret_cast<const unsigned*>(&static_cast<const unsigned __int64&>((unsigned)nSum))));
        obj.SetWStringMember("detail", CStringW(strDetail));
        pRows->PushValue(Scaleform::GFx::Value(obj.GetValue()));
    }
    return pRows->GetLength() > 0;
}
MS2_REPLACE_METHOD(0x1419b0b10, UIItemColoringDialog, BuildBillRows, 977, 0x81B0198B);

// @0x1419b0ef0
int UIItemColoringDialog::OpenBill()
{
    UIBillDialog* pBill;
    if (m_2a8.IsEmpty() == false && (pBill = FUN_140f0a350(0x4e7b)) != 0) {
        if (MS2Ptr<ASArray> spRows = new ASArray(2)) {
            int nTotal = 0;
            if (BuildBillRows(spRows.operator->(), &nTotal) != 0) {
                Unk_BSFee* pFee = GetFee();
                int bCoupon = 1;
                int nCoupons = GetCouponCount(1);
                if (nCoupons == 0 || GetSalePrice((unsigned)GetTotalPrice()) == 0)
                    bCoupon = 0;
                if (MS2Ptr<UIBillDialog::TData> spBill = new UIBillDialog::TData()) {
                    spBill->m_18 = static_cast<IMessageListener*>(this);
                    spBill->m_30 = 0;
                    spBill->m_20 = MS2Ptr<AScript>(spRows);
                    spBill->m_60 = bCoupon;
                    spBill->m_58 = GetStringCommon(0x997);
                    CStringW strCoupon = GetCouponName();
                    CStringW strLabel(bCoupon != 0 ? FUN_14028dfa0<CStringW, int>(CStringW(L"s_beauty_coupon_with_count"), strCoupon, nCoupons)
                                                   : CStringW(strCoupon));
                    spBill->m_50 = strLabel;
                    spBill->m_34 = reinterpret_cast<TShopPaymentAttr*>(pFee)->GetPaymentType();
                    spBill->m_38 = reinterpret_cast<TShopPaymentAttr*>(pFee)->GetItemId();
                    spBill->m_48 = nTotal;
                    pBill->SetData(spBill);
                    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4e7b)));
                }
                return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419b0ef0, UIItemColoringDialog, OpenBill, 1340, 0xD179D68F);

// @0x1419b1440
MS2Ptr<CItem> UIItemColoringDialog::AddCurrentItemToBasket(int nItemId)
{
    if (m_268 == 0)
        return MS2Ptr<CItem>(0);
    MS2Ptr<CItem> spItem = m_268->GetEditItem();
    if ((spItem.get() ? true : false) && spItem->GetItemId() == nItemId) {
        m_268->ResetEdit();
        m_2a8.AddTail(spItem);
        return spItem;
    }
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x1419b1440, UIItemColoringDialog, AddCurrentItemToBasket, 327, 0xAFB3734B);

// @0x1419b1590
MS2Ptr<CItem> UIItemColoringDialog::RemoveBasketItem(int nItemId)
{
    if (m_2a8.IsEmpty() != false)
        return MS2Ptr<CItem>(0);
    for (POSITION pos = m_2a8.GetHeadPosition(); pos != NULL; m_2a8.GetNext(pos)) {
        MS2Ptr<CItem> spItem = m_2a8.GetAt(pos);
        if ((spItem.get() ? true : false) && spItem->GetItemId() == nItemId) {
            m_2a8.RemoveAt(pos);
            return spItem;
        }
    }
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x1419b1590, UIItemColoringDialog, RemoveBasketItem, 370, 0xB49F2E22);

// @0x1419b1710
__int64 UIItemColoringDialog::GetTotalPrice()
{
    return m_2a8.GetCount() * GetPricePerItem();
}
MS2_REPLACE_METHOD(0x1419b1710, UIItemColoringDialog, GetTotalPrice, 62, 0x3A336233);

// @0x1419b1760
int UIItemColoringDialog::FUN_1419b1760(int* pCoupons)
{
    *pCoupons = 0;
    int nCoupons = GetCouponCount(m_10);
    Unk_BSFee* pFee = GetFee();
    unsigned nSale = GetSalePrice((unsigned)GetTotalPrice());
    __int64 nLeft = FUN_141349ef0(reinterpret_cast<TShopPaymentAttr*>(pFee)->GetPaymentType(), 0, nSale);
    for (POSITION pos = m_2a8.GetHeadPosition(); pos != NULL; m_2a8.GetNext(pos)) {
        unsigned nPrice = GetSalePrice(GetPricePerItem());
        MS2Ptr<CItem> spItem = m_2a8.GetAt(pos);
        if (spItem == 0)
            continue;
        if (m_10 != 0 && nCoupons > 0) {
            *pCoupons += 1;
            nCoupons--;
        } else {
            nLeft -= nPrice;
        }
    }
    if (nLeft < 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1419b1760, UIItemColoringDialog, FUN_1419b1760, 395, 0xCC307ED7);

// @0x1419b1900
bool UIItemColoringDialog::HasCoupon(int bCoupon)
{
    if (bCoupon != 0 && m_1a8.m_2c != 0)
        return g_143ab2a90.HasItemWithTag(m_1a8.m_2c) == 1;
    return false;
}
MS2_REPLACE_METHOD(0x1419b1900, UIItemColoringDialog, HasCoupon, 94, 0x9C2766CC);

// @0x1419b1970
int UIItemColoringDialog::GetCouponCount(int bCoupon)
{
    if (bCoupon != 0 && m_1a8.m_2c != 0)
        return g_143ab2a90.FUN_140a5f7b0(m_1a8.m_2c, 0);
    return 0;
}
MS2_REPLACE_METHOD(0x1419b1970, UIItemColoringDialog, GetCouponCount, 69, 0xC1358579);

// @0x1419b19c0
CStringW UIItemColoringDialog::GetCouponName()
{
    if (m_1a8.m_20 != 0)
        return TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, m_1a8.m_20);
    return GetStringCommon(0x995);
}
MS2_REPLACE_METHOD(0x1419b19c0, UIItemColoringDialog, GetCouponName, 126, 0x454EE4C7);

// @0x1419b1a50
int UIItemColoringDialog::FUN_1419b1a50()
{
    Unk_IcPlayer* pPc = ((Unk_IcPlayer*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPc == 0)
        return 0;
    return pPc->FUN_141658f30();
}
MS2_REPLACE_METHOD(0x1419b1a50, UIItemColoringDialog, FUN_1419b1a50, 54, 0x5A0DD506);

// @0x1419b1a90
unsigned UIItemColoringDialog::GetPricePerItem()
{
    return reinterpret_cast<CBeautyShopDataCommon*>(&m_1a8)->GetRecolorPayment().GetAmount();
}
MS2_REPLACE_METHOD(0x1419b1a90, UIItemColoringDialog, GetPricePerItem, 41, 0x566B4A3E);

// @0x1419b1ac0
Unk_BSFee* UIItemColoringDialog::GetFee()
{
    return reinterpret_cast<Unk_BSFee*>(&reinterpret_cast<CBeautyShopDataCommon*>(&m_1a8)->GetRecolorPayment());
}
MS2_REPLACE_METHOD(0x1419b1ac0, UIItemColoringDialog, GetFee, 33, 0x48B69FD3);

// @0x1419b1af0
unsigned UIItemColoringDialog::GetSalePrice(unsigned nPrice)
{
    return ((class CGameRule*)GetGameRule())->GetDiscountedPrice(GetSaleEventId(), nPrice, FUN_1419b1a50());
}
MS2_REPLACE_METHOD(0x1419b1af0, UIItemColoringDialog, GetSalePrice, 77, 0x270DC376);

// @0x1419b1b50
bool UIItemColoringDialog::Restart()
{
    if (m_30 == 0 || m_268 == 0)
        return true;
    if (m_260 == true) {
        FUN_1412752d0(L"s_beauty_msg_wait_by_expired_codi", 1);
        return false;
    }
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e7b);
    RestoreItems(m_2a8);
    RestoreItems(m_278);
    m_268->RestoreUid(m_268->GetEditItemUid());
    m_268->SelectUid(0);
    m_268->FUN_140cd3820();
    FUN_140f014f0(m_268);
    ClearBasket();
    RefreshBasketState();
    BuildItems();
    return true;
}
MS2_REPLACE_METHOD(0x1419b1b50, UIItemColoringDialog, Restart, 422, 0x961642A6);

// @0x1419b1d00
bool UIItemColoringDialog::OnCloseConfirm(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        FUN_1419ae940();
    FUN_14151f200();
    return true;
}
MS2_REPLACE_METHOD(0x1419b1d00, UIItemColoringDialog, OnCloseConfirm, 47, 0x8E5829C1);

// @0x1419b1d40
bool UIItemColoringDialog::OnPayConfirm(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        FUN_1419b0700();
    return true;
}
MS2_REPLACE_METHOD(0x1419b1d40, UIItemColoringDialog, OnPayConfirm, 42, 0xC35DA1D7);

// @0x1419b1d70
bool UIItemColoringDialog::OnRestartConfirm(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        return Restart();
    return true;
}
MS2_REPLACE_METHOD(0x1419b1d70, UIItemColoringDialog, OnRestartConfirm, 44, 0xB2E3A35A);

// @0x1419b1db0
void UIItemColoringDialog::ClearBasket()
{
    if (m_30 == 0)
        return;
    if (m_2a8.IsEmpty() == false) {
        m_2a8.RemoveAll();
        m_30->Invoke("forceRemoveBasketItemAll");
    }
}
MS2_REPLACE_METHOD(0x1419b1db0, UIItemColoringDialog, ClearBasket, 134, 0x5B58A172);

// @0x1419b1e40
void UIItemColoringDialog::RestoreItems(ATL::CAtlList<MS2Ptr<CItem> >& list)
{
    if (m_268 == 0 || list.IsEmpty() != false)
        return;
    for (POSITION pos = list.GetHeadPosition(); pos != NULL; list.GetNext(pos)) {
        MS2Ptr<CItem> spItem = list.GetAt(pos);
        if (spItem == 0)
            continue;
        m_268->RestoreUid(spItem->GetItemUid());
    }
}
MS2_REPLACE_METHOD(0x1419b1e40, UIItemColoringDialog, RestoreItems, 254, 0x7D656948);

// @0x1419b1f50
void UIItemColoringDialog::AddPendingRequests(int nDelta)
{
    m_264 += nDelta;
    if (m_264 < 0)
        m_264 = 0;
    m_260 = m_264 > 0;
}
MS2_REPLACE_METHOD(0x1419b1f50, UIItemColoringDialog, AddPendingRequests, 118, 0x2FABD0CE);

// Ask before replacing an unsaved colour: "changeitem,<uid>,<index>,<tag>" is answered through OnMessage.
// @0x1419b1fd0
int FUN_1419b1fd0(MS2Ptr<Customize> spCustomize, const __int64& nUid, int nIndex, CString strTag, IMessageListener* pListener)
{
    if (spCustomize == 0)
        return 0;
    if (spCustomize->IsEditItemColorChanged() != 0) {
        CStringW strCmd;
        strCmd.Format(L"changeitem,%I64u,%d,%s", nUid, nIndex, (const char*)strTag);
        CStringW strName;
        if (MS2Ptr<CItem> spItem = spCustomize->GetEditItem()) {
            int nRarity = FUN_141275c00(spItem->GetRarity());
            strName = FUN_14183e930(spItem->FUN_140527b10(), nRarity);
        }
        ShowMessageBox(FormatStringId(0x278, strName), 1, pListener, CStringW(strCmd));
        return 1;
    }
    return 0;
}
MS2_REPLACE(0x1419b1fd0, FUN_1419b1fd0, 680, 0xEAD7E685);

// ---- template glue ----

// @0x1419b2be0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, bool a2, bool a3, Scaleform::GFx::Value a4)
{
    ASArgList args;
    args.resize(4);
    FUN_1422bcea0(&args[0], a1);
    SetBoolean(&args[1], a2);
    SetBoolean(&args[2], a3);
    SetValue(&args[3], a4);
    return FUN_1422bb8f0(szMethod, args);
}

// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbecc0-0x142cbed80 .text$yd
