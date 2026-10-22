// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Beauty shop developer page (UIBeautyShopDevDialog, UI id
// 0x4e79): lists every hair / face / makeup / skin / cap / emotion item the player's gender can wear, previews it on the
// character through a Customize controller, saves or resets the change and stores the cap transform of a hat.
// MS2-UNIT: unit_14191c7d0
// MS2-RANGE: 0x14191c7d0-0x1419231f0 .text$mn
// MS2-RANGE: 0x140112750-0x140112990 .text$di
// MS2-RANGE: 0x142cbdb10-0x142cbdbd0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1401128e0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x140112910 ; probe
// MS2-PIN: ??$?8PEAVUIBeautyShopDevDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopDevDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x141921880 ; prop
// MS2-PIN: ??$?8PEAVUIBeautyShopDevDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1419218f0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x141922a60 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x141922b00 ; prop
// MS2-PIN: ?IsString@Value@GFx@Scaleform@@QEBA_NXZ 0x141922e40 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141922f20 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141922f80 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141923070 ; unique
// MS2-PIN: ??$Call@VUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1419230f0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141923130 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIBeautyShopDevDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141923190 ; unique
// MS2-PIN: ??__Fs_strSkill@@YAXXZ 0x142cbdb70 ; probe
// MS2-PIN: ??__Fs_strStun@@YAXXZ 0x142cbdb90 ; probe
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibeautyshopdevdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uibeautyshopdevdialog.h"
static CString s_strItemSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/commonresource.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/customize.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/equipitem.h"
#include "ms2/client/ms2/equipmodel.h"
#include "ms2/client/ms2/itemcustomizecontroller_1.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <algorithm>
#include <vector>

// ---- local stand-ins for classes whose units are not recovered yet ----

// The beauty shop scene (the page's parent movie); only its RTTI is used.
class UISceneGameBeautyShop : public UISwfEntity
{
public:
    virtual ~UISceneGameBeautyShop();
};

// CItem::FUN_140527840's record (as commonfiles\item.cpp).
class Unk_ItemEquipData : public CItemData {};
// The table data of an equipped item (CEquipItem::FUN_1411dc7f0).
struct Unk_EquipItemData : CItemData {};
ItemModelHead* FUN_14053ec70(CItemData* pData);         // the <customize> block

// The models of an equipped item: the cap attach point.
class Unk_BSDevEquipModel : public CEquipModel
{
public:
    efd::Point3 FUN_141200130();                        // the position
    efd::Point3 FUN_1412000d0();                        // the rotation
};

// The current field (the page refreshes its camera through it).
class Unk_BSDevField
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
    virtual void vfunc_149();                           // 149 restore the field camera
};
class Unk_BSDevWorld
{
public:
    PC* FUN_141bd0cc0();                                // the player (NULL outside the game)
    Unk_BSDevField* FUN_141bd3620();
};
Unk_BSDevWorld* FUN_1403ed2d0();

// The emotion animations of a model (the "emotion" tab lists their names).
class Unk_BSDevMotionSet : public CPtred
{
public:
    virtual CString vfunc_1();
    virtual void vfunc_2(void* pKey);
    virtual void vfunc_3(std::vector<CString>& aNames);  // the animation names
};
class Unk_BSDevMotionLib
{
public:
    MS2Ptr<Unk_BSDevMotionSet> FUN_1411bde10(int nModelId);
};
class Unk_BSDevSpawnMgr
{
public:
    Unk_BSDevMotionLib* FUN_1411bf1b0();
};
Unk_BSDevSpawnMgr* FUN_140a50010();

// An element of a tile list's data provider, viewed as an object.
class Unk_BSDevRow : public ASObj
{
public:
    Unk_BSDevRow(ASArray* pArray, unsigned nIndex);     // 0x1422df140
};

class Unk_BSDevItemEvents
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);
    void FUN_1419caeb0(UIItemEventListener* pListener);
};
Unk_BSDevItemEvents* FUN_140a6a840();
Unk_BSCamera* FUN_140cd47b0(int nId);
class Unk_BSDevSound;
Unk_BSDevSound* FUN_1408e57f0();
void FUN_1422b9fd0(Unk_BSDevSound* p, int nEvent);

NotifySystem* FUN_140939a10();
CInputKeyHandler* FUN_14025e7c0();
CStringTable* FUN_1401a9d70();
CommonResource* FUN_1401d31f0();
CItemDataTable* FUN_140281980();

// Message boxes and strings.
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_14151f200();
CStringW FUN_14028de60(int nId);
void FUN_1412761e0(MS2Ptr<AScript> spRoot, int bEnable);   // enable the root's input
bool FUN_140184310(const CString& str, const char* sz);
int FUN_141b71a10(const char* sz);
CStringW FUN_141b71910(__int64 n);
CStringW FUN_141b71990(unsigned n);
CString FUN_14016a600(const wchar_t* sz, int n);
CStringW FUN_14016a730(const char* sz, int n);
int FUN_1409c17e0(const Scaleform::GFx::Value& v);
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);

// The beauty shop helpers (uibeautyshopstyledialog.cpp and the item row builders).
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
bool FUN_140f01670(ASTooltip& tip, void*, ASData* pArgs);
void FUN_140f014b0(ATL::CAtlList<MS2Ptr<CEquipItem> >* pOut, Unk_PCEquipSet* pEquip);
void FUN_140f024e0(ASData* pArgs, int* pnPalette, int* pnType);
int FUN_140f32290(ASObj& obj, MS2Ptr<CItemData> spData, MS2Ptr<Customize> spCustomize, unsigned nFlags, int nMode, bool bColor);
void FUN_140f328a0(MS2Ptr<Customize> spCustomize, ASObj& obj, int n);
int FUN_141421690(CItem* pItem);                        // the item's customize kind

// The server result of a beauty shop request.
enum Unk_BSResult : unsigned int {};

// fmt message with one argument (string id, mode, flag, value).
// @0x141921990
template <class A> void FUN_141921990(int nStringId, int nA, int nB, const A& x)
{
    const fmt::internal::ArgArray<1>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(x), values));
}

// The equip slot of a tab (0: none).
// @0x141921580
int FUN_141921580(int nTab)
{
    int nSlot = 0;
    if (nTab == 0)
        nSlot = 1;
    else if (nTab == 1)
        nSlot = 2;
    else if (nTab == 2)
        nSlot = 3;
    else if (nTab == 6)
        nSlot = 6;
    return nSlot;
}

// The debug text of an equipped item (empty in this build).
// @0x1419215e0
CString FUN_1419215e0(Unk_EquipItemData* pData, MS2Ptr<CEquipItem> spItem)
{
    if (!pData)
        return CString("");
    CString strText;
    return strText;
}

// ---- UIBeautyShopDevDialog ----

// @0x14191c7d0
UIBeautyShopDevDialog::UIBeautyShopDevDialog()
    : m_198(0), m_19c(1), m_1a0(-1), m_1a4(0), m_298(0)
{
    m_40 = 1;
    m_2c = 0xc;
    m_80 = 0;
    FUN_141925e70(0, 1);
    FUN_1422dc3b0(1);
    FUN_141920770();
}

// @0x14191c980
UIBeautyShopDevDialog::~UIBeautyShopDevDialog()
{
}

// @0x14191ca70
CString UIBeautyShopDevDialog::GetTypeName()
{
    return "BeautyShopDevDialog";
}

// @0x14191cac0
void UIBeautyShopDevDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_141920770();
    FUN_14191f9d0();
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
        pPc->FUN_14166ed70(0x56057c6);
    m_1a0 = -1;
    m_198 = 0;
    m_1a4 = 0;
    m_288 = 0;
    m_298 = 0;
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->UnregisterNotify(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                      Delegate<void(NotifyObject*)>(this, &UIBeautyShopDevDialog::FUN_1419213f0));
}

// @0x14191ccd0
int UIBeautyShopDevDialog::vfunc_74(int a1, void* p2, void* p3)
{
    return UIDialog::vfunc_74(a1, p2, p3);
}

// Sort the items of the player's gender into the tabs.
// @0x14191cd10
int UIBeautyShopDevDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return 0;
    std::vector<MS2Ptr<CItemData> > aItems;
    FUN_140281980()->GetAllItemData(aItems);
    int nGender = pPc->FUN_141658e60();
    for (std::vector<MS2Ptr<CItemData> >::iterator it = aItems.begin(); it != aItems.end(); ++it)
    {
        MS2Ptr<CItemData> spData = *it;
        int nLimit = spData->limit.genderLimit;
        if (nLimit == nGender || nLimit == 2)
        {
            int nTab = -1;
            FUN_1419206a0(&nTab, spData);
            if (nTab != -1)
                m_1a8[nTab].Add(spData->FUN_14053c510());
        }
    }
    return 1;
}

// @0x14191cec0
// MS2-FUNCTIONAL: temporaries and EH state layout differ (Customize new/AssignRaw, CString child name)
void UIBeautyShopDevDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        m_288.AssignRaw(new Customize(pPc->FUN_14123c580(), static_cast<IItemCustomizeEventListener*>(this), 0));
        m_288->FUN_140cd25c0(2);
        m_298 = FUN_140cd47b0(0x4ef2);
        static_cast<IItemCustomizeEventListener*>(this)->FUN_141922e80(1);
        m_198 = 0;
        m_30->Invoke("initData");
        m_30->FUN_140bbe7c0<ASDropdownMenu>(CString("m_colorIndexMenu"), m_2b8);
        FUN_1419200c0(1);
        FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
        FUN_140939a10()->RegisterNotify(CStringW(L"NotifyChangeActiveMyCodiTab"),
                                        Delegate<void(NotifyObject*)>(this, &UIBeautyShopDevDialog::FUN_1419213f0));
    }
}

// @0x14191d1e0
void UIBeautyShopDevDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_2b8 = 0;
}

// ESC closes the page; Enter runs the search (or focuses the search box).
// @0x14191d220
// MS2-FUNCTIONAL: GetChild temporary copies differ
int UIBeautyShopDevDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (FUN_14025e7c0()->FUN_14116d840())
    {
        FUN_14191fae0();
        return 1;
    }
    if (!FUN_14025e7c0()->FUN_14116d9c0(0x1c, false, 0))
        return 0;
    if (m_30.get())
    {
        MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>(CString("m_inputSearch"));
        if (spInput.get())
        {
            if (spInput->FUN_1422c76c0() == 0)
                spInput->FUN_1422c7630(1);
            else
                vfunc_84(m_1a0, 0, spInput->FUN_1422e0b00());
        }
    }
    return 1;
}

// Per frame: the customize controller, the pending debug text, the camera and the input lock.
// @0x14191d3d0
// MS2-FUNCTIONAL: branch layout / temporaries differ
void UIBeautyShopDevDialog::vfunc_15()
{
    if (vfunc_55() != 0)
        return;
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc && !(m_288 == 0))
    {
        m_288->FUN_140cd1bf0();
        if (m_1a4)
        {
            MS2Ptr<CEquipItem> spItem(0);
            int nSlot = FUN_141921580(m_1a0);
            if (!nSlot)
            {
                MS2Ptr<CItemData> spData = FUN_14053f870(m_1a4);
                if (!spData->FUN_14053cf00())
                    nSlot = spData->FUN_14053eba0()->FUN_14054b400();
            }
            if (!nSlot)
            {
                m_1a4 = 0;
            }
            else
            {
                PC* pPc2 = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPc2)
                    spItem = pPc2->FUN_141655e10(nSlot);
                if (spItem.get() && spItem->FUN_1411dc820() == m_1a4 && spItem->FUN_1411dc0d0())
                {
                    CString strText = FUN_1419215e0(spItem->FUN_1411dc7f0(), spItem);
                    m_30->Invoke("setDebugText", CString(strText));
                    m_1a4 = 0;
                }
            }
        }
        if (m_298)
            m_298->FUN_1418dda30(m_288->FUN_140cd27f0() == 0);
        if (m_19c == 0 && pPc->FUN_14166cc80() != 0x50)
        {
            m_19c = 1;
            FUN_1412761e0(MS2Ptr<AScript>(m_30), m_19c);
        }
    }
}

// The scene's exit button closes the page.
// @0x14191d7e0
// MS2-FUNCTIONAL: stack frame / branch layout differ
int UIBeautyShopDevDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (!pMsg->FUN_1422e4520() && dynamic_cast<UISceneGameBeautyShop*>(pSender))
    {
        if (FUN_140184310(pMsg->FUN_1422b8d30(), "OnExit"))
        {
            FUN_14191fae0();
            return 1;
        }
    }
    return 0;
}

// The AS calls of the page.
// @0x14191d8d0
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
int UIBeautyShopDevDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnChangeTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nTab = m_1a0 = data.FUN_1422b8a10();
            if (nTab == 0)
                FUN_14191f970();
            else
                FUN_14191f9d0();
            vfunc_84(nTab, 0, CStringW(L""));
            FUN_1419207c0(nTab);
        }
        return 1;
    }
    if (_stricmp("OnChangeItem", szMethod) == 0)
    {
        if (m_1a0 < 0)
            return 1;
        if (m_1a0 == 5)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                int nIndex = FUN_141b71a10(data.FUN_1422b8d30());
                FUN_14191f8e0(nIndex);
                if (m_198)
                    FUN_14191fc40(1);
                m_198 = 1;
            }
        }
        else if (m_1a0 <= 4 || m_1a0 == 6)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                int nItemId = FUN_141b71a10(data.FUN_1422b8d30());
                FUN_14191f620(nItemId);
                if (m_198)
                    FUN_14191fc40(1);
                m_198 = 1;
            }
        }
        return 1;
    }
    if (_stricmp("OnClickReset", szMethod) == 0)
    {
        if (m_288.get())
            m_288->FUN_140cd20c0();
        FUN_14191ff70();
        FUN_14191fc40(0);
        vfunc_84(m_1a0, 1, CStringW(L""));
        return 1;
    }
    if (_stricmp("OnClickSave", szMethod) == 0)
    {
        if (m_1a0 < 0)
            return 1;
        if (m_1a0 == 5)
        {
            MS2Ptr<ASTileList> spList = GetChild<ASTileList>(CString("m_items"));
            if (spList.get())
            {
                if (spList->FUN_1422dccd0() >= 0)
                    FUN_14191f8e0(spList->FUN_1422dccd0());
            }
        }
        else if (m_1a0 <= 4 || m_1a0 == 6)
        {
            m_288->FUN_140cd1ff0();
            if (m_1a0 == 3)
                FUN_14191fe00();
        }
        return 1;
    }
    if (_stricmp("OnClickNew", szMethod) == 0)
    {
        OnClickNew();
    }
    else if (_stricmp("OnClickAdd", szMethod) == 0)
    {
        OnClickAdd();
    }
    else if (_stricmp("OnClickDelete", szMethod) == 0)
    {
        OnClickDelete();
    }
    else
    {
        if (_stricmp("OnClickClose", szMethod) == 0)
        {
            FUN_14191fae0();
            return 1;
        }
        if (_stricmp("OnChangeColor", szMethod) == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                data.FUN_1422b8a10();
                CString strName = data.FUN_1422b8d30();
                AScript obj(data.FUN_1422b9260(), 2);
                int nColorSN = FUN_1409c17e0(obj.FUN_1422baa20("colorSN"));
                int nPaletteId = FUN_1409c17e0(obj.FUN_1422baa20("paletteID"));
                vfunc_86(nPaletteId, nColorSN);
                FUN_14191fc40(1);
            }
            return 1;
        }
        if (_stricmp("OnChangeDetailColor", szMethod) == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                int nPalette = 0;
                int nType = 0;
                FUN_140f024e0(&data, &nPalette, &nType);
                vfunc_85(nPalette, nType);
                FUN_14191fc40(1);
            }
            return 1;
        }
        if (_stricmp("OnClickSearch", szMethod) == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
                vfunc_84(m_1a0, 0, data.FUN_1422b8f40());
            return 1;
        }
    }
    return 0;
}

// The beauty shop answer (0x31, op 8): the result message, then a refresh on failure.
// @0x14191e2c0
void UIBeautyShopDevDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    int nOpcode = static_cast<CInPacket*>(pPacket)->FUN_14070fe80();
    if (nOpcode != 0x31)
        return;
    unsigned nOp = static_cast<CInPacket*>(pPacket)->vfunc_o8_1();
    if (nOp == 8)
    {
        Unk_BSResult nResult = (Unk_BSResult)static_cast<CInPacket*>(pPacket)->vfunc_o8_3();
        FUN_141921990(0xcd, 1, 1, nResult);
        if (nResult != 0)
            FUN_14191ffb0();
    }
}

// The colour tooltip of the AS list.
// @0x14191e390
void UIBeautyShopDevDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (_stricmp("getTooltipColor", strMethod) == 0)
    {
        ASTooltip tip(1, 2);
        if (FUN_140f01670(tip, 0, pArgs))
            *pRetVal = tip.FUN_1422bb870();
    }
}

// The player's equipment changed: replay the apply effect.
// @0x14191e440
void UIBeautyShopDevDialog::vfunc_21(void* p)
{
    if ((m_30.get() ? true : false) && vfunc_55() == 0 && p)
        FUN_14191fe00();
}

// @0x14191e4d0
void UIBeautyShopDevDialog::vfunc_24(void* p)
{
    if ((m_30.get() ? true : false) && vfunc_55() == 0 && p)
        FUN_14191fe00();
}

// @0x14191e560
void UIBeautyShopDevDialog::vfunc_25(void* p)
{
    if ((m_30.get() ? true : false) && vfunc_55() == 0)
        FUN_14191fe00();
}

// The customize controller's events: enable "m_save" / "m_reset" and remember the item whose debug text is pending.
// @0x14191e5f0
int UIBeautyShopDevDialog::vfunc_1(void* p)
{
    FUN_14191fc40(1);
    return 1;
}

// @0x14191e630
int UIBeautyShopDevDialog::vfunc_2(void* p, float fValue, int nIndex)
{
    FUN_14191fc40(1);
    return 1;
}

// @0x14191e680
int UIBeautyShopDevDialog::vfunc_3(void* p, float fValue)
{
    FUN_14191fc40(1);
    MS2Ptr<CEquipItem> spItem = static_cast<CItemCustomizeController*>(p)->GetEquipItem();
    if ((spItem.get() ? true : false) && spItem->FUN_1411dc7f0() && spItem->FUN_1411dc7f0()->FUN_14053d070())
        m_1a4 = spItem->FUN_1411dc820();
    return 1;
}

// @0x14191e760
int UIBeautyShopDevDialog::vfunc_4(void* p, void* q)
{
    MS2Ptr<CEquipItem> spItem = static_cast<CItemCustomizeController*>(p)->GetEquipItem();
    if ((spItem.get() ? true : false) && spItem->FUN_1411dc7f0() && spItem->FUN_1411dc7f0()->FUN_14053d070())
        m_1a4 = spItem->FUN_1411dc820();
    return 1;
}

// @0x14191e830
int UIBeautyShopDevDialog::vfunc_5(void* p, void* q)
{
    FUN_14191fc40(1);
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        MS2Ptr<CEquipItem> spItem = pPc->FUN_141655e10(FUN_141921580(m_1a0));
        if (spItem.get())
        {
            Unk_EquipItemData* pData = spItem->FUN_1411dc7f0();
            if (pData && pData->FUN_14053cfd0() && spItem->FUN_1411dc0d0())
            {
                CString strText = FUN_1419215e0(pData, spItem);
                m_30->Invoke("setDebugText", CString(strText));
            }
        }
    }
    return 1;
}

// The close confirmation: OK restores the look.
// @0x14191e9e0
bool UIBeautyShopDevDialog::FUN_14191e9e0(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
        FUN_14191fa30();
    FUN_14151f200();
    return true;
}

// Build the item list of a tab ("buildItems"), filtered by the search text; bKeepList only reselects the worn item.
// @0x14191ea20
// MS2-FUNCTIONAL: large EH frame; temporaries and branch order differ
void UIBeautyShopDevDialog::vfunc_84(int nTab, int bKeepList, const CStringW& strSearch)
{
    int nSelected = -1;
    ASArray aItems(2);
    if (nTab < 0 || nTab > 6)
        return;
    switch (nTab)
    {
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
    {
        int nWornId = 0;
        int nSlot = FUN_141921580(nTab);
        PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc)
        {
            MS2Ptr<CEquipItem> spItem = pPc->FUN_141655e10(nSlot);
            if (spItem.get())
                nWornId = spItem->FUN_1411dc820();
        }
        size_t nCount = m_1a8[nTab].GetCount();
        ATL::CAtlArray<unsigned>& aIds = m_1a8[nTab];
        for (size_t i = 0; i < nCount; i++)
        {
            int nItemId = aIds.GetAt(i);
            if (nWornId == nItemId)
                nSelected = (int)i;
            if (bKeepList == 0)
            {
                CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
                CStringW strCode = FUN_141b71990(nItemId);
                int bMatch = 1;
                if (!strSearch.IsEmpty())
                {
                    if (strName.Find(strSearch, 0) == -1 && strCode.Find(strSearch, 0) == -1)
                        bMatch = 0;
                }
                if (bMatch)
                {
                    ASObj row(2);
                    row.FUN_1407cbb20("field", CStringW(strName));
                    row.FUN_1407cbb20("code", CStringW(strCode));
                    aItems.FUN_1422bc050(row.FUN_1422bb870());
                }
            }
        }
        break;
    }
    case 3:
    {
        PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc)
            FUN_14191f620(0x9a1d21);
        break;
    }
    case 5:
    {
        PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc)
        {
            m_2a0.clear();
            Unk_BSDevMotionLib* pLib = FUN_140a50010()->FUN_1411bf1b0();
            MS2Ptr<Unk_BSDevMotionSet> spSet = pLib->FUN_1411bde10(pPc->vfunc_69());
            if (strSearch.IsEmpty())
            {
                spSet->vfunc_3(m_2a0);
            }
            else
            {
                std::vector<CString> aAll;
                spSet->vfunc_3(aAll);
                CString strKey = FUN_14016a600(strSearch, 0);
                strKey.MakeLower();
                for (std::vector<CString>::iterator it = aAll.begin(); it != aAll.end(); ++it)
                {
                    CString strName(*it);
                    CString strLower(strName);
                    strLower.MakeLower();
                    if (strLower.Find(strKey, 0) != -1)
                        m_2a0.push_back(strName);
                }
                std::sort(m_2a0.begin(), m_2a0.end());
            }
            for (unsigned i = 0; i < m_2a0.size(); i++)
            {
                ASObj row(2);
                row.FUN_1407cbb20("code", StringFormat(L"{0}", i));
                row.FUN_1407cbb20("field", FUN_14016a730(m_2a0[i], 0));
                aItems.FUN_1422bc050(row.FUN_1422bb870());
            }
        }
        break;
    }
    }
    if (bKeepList == 0)
    {
        m_30->Invoke("buildItems", Scaleform::GFx::Value(aItems.FUN_1422bb870()), (long)nSelected);
    }
    else
    {
        MS2Ptr<ASTileList> spList = GetChild<ASTileList>(CString("m_items"));
        if (spList.get())
        {
            if (spList->FUN_1422dccd0() == nSelected)
            {
                ASObj row(2);
                int nMode = 6;
                MS2Ptr<CItem> spItem = m_288->FUN_140cd1890();
                if (spItem.get())
                {
                    FUN_140f328a0(MS2Ptr<Customize>(m_288), row, nMode);
                    m_30->Invoke("buildResetItem", Scaleform::GFx::Value(row.FUN_1422bb870()));
                }
            }
            else
            {
                spList->FUN_1422dcca0(nSelected);
            }
        }
    }
}

// A detail colour of the colour dialog.
// @0x14191f540
void UIBeautyShopDevDialog::vfunc_85(int nPalette, int nType)
{
    if (m_288.get())
        m_288->FUN_140cd32f0(nPalette, nType, FUN_141921500());
}

// A palette colour.
// @0x14191f5b0
void UIBeautyShopDevDialog::vfunc_86(int nPalette, int nColor)
{
    if (m_288.get())
        m_288->FUN_140cd3220(nPalette, nColor, FUN_141921500());
}

// Preview an item ("buildCurrentItem").
// @0x14191f620
void UIBeautyShopDevDialog::FUN_14191f620(int nItemId)
{
    if (m_288 == 0)
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    FUN_141920aa0(nItemId);
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc)
    {
        if (m_1a0 == 4 && spData->FUN_14053d2f0())
        {
            if (pPc->FUN_14166c930() != 0xe)
                pPc->vfunc_59(0xe, 0, 0, 0);
            pPc->FUN_14166cc40(0x55);
        }
        else
        {
            pPc->FUN_14166cc40(0x4d);
        }
    }
    ASObj row(2);
    int nMode = 0xf;
    if (spData->FUN_14053cf00())
        nMode = 1;
    if (FUN_140f32290(row, MS2Ptr<CItemData>(spData), MS2Ptr<Customize>(m_288), 1, nMode, true))
    {
        m_1a4 = nItemId;
        m_30->Invoke("buildCurrentItem", Scaleform::GFx::Value(row.FUN_1422bb870()));
    }
    FUN_141921190(nItemId);
}

// Play the nIndex-th listed emotion.
// @0x14191f8e0
void UIBeautyShopDevDialog::FUN_14191f8e0(unsigned nIndex)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    if (nIndex >= m_2a0.size())
        return;
    pPc->FUN_14166ef10(m_2a0[nIndex], 1, 1, false);
}

// @0x14191f970
void UIBeautyShopDevDialog::FUN_14191f970()
{
    if (m_288 == 0)
        return;
    m_288->FUN_140cd2530(6);
}

// @0x14191f9d0
void UIBeautyShopDevDialog::FUN_14191f9d0()
{
    if (m_288 == 0)
        return;
    m_288->FUN_140cd24a0(6);
}

// Restore the look and the field camera and leave.
// @0x14191fa30
int UIBeautyShopDevDialog::FUN_14191fa30()
{
    if (m_288.get())
        m_288->FUN_140cd22f0(FUN_141921580(m_1a0));
    Unk_BSDevField* pField = FUN_1403ed2d0()->FUN_141bd3620();
    if (pField)
        pField->vfunc_149();
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
    return 1;
}

// Close: asks first when there are unsaved changes.
// @0x14191fae0
void UIBeautyShopDevDialog::FUN_14191fae0()
{
    if (!FUN_14191fff0())
    {
        FUN_14191fa30();
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73f20(FUN_14028de60(0x271), 1);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIBeautyShopDevDialog::FUN_14191e9e0));
        spBox->FUN_141a01800(2);
        FUN_140d73c60(MS2Ptr<CMsgBoxData>(spBox));
    }
}

// Enable "m_save" / "m_reset" (only when the controller has a change).
// @0x14191fc40
// MS2-FUNCTIONAL: GetChild result copies (three pointer hops per child) differ
void UIBeautyShopDevDialog::FUN_14191fc40(int bChanged)
{
    if (m_30 == 0)
        return;
    if (m_288 == 0)
        return;
    int bEnable = (bChanged && m_288->FUN_140cd2a00()) ? 1 : 0;
    MS2Ptr<ASButton> spSave = GetChild<ASButton>(CString("m_save"));
    if (spSave.get())
        spSave->FUN_1422c1fe0(bEnable);
    MS2Ptr<ASButton> spReset = GetChild<ASButton>(CString("m_reset"));
    if (spReset.get())
        spReset->FUN_1422c1fe0(bEnable);
}

// The change was applied: play the customizing effect and unlock the input.
// @0x14191fe00
void UIBeautyShopDevDialog::FUN_14191fe00()
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    if (pPc->FUN_14166cc80() == 0x50)
        return;
    if (pPc->FUN_14166c930() != 0xe)
        pPc->vfunc_59(0xe, 0, 0, 0);
    pPc->FUN_14166cc40(0x50);
    Unk_EffectTarget target;
    target.m_strName = FUN_1401d31f0()->m_strCustomizingFinish;
    target.m_nKind = 1;
    target.FUN_140a53190(pPc->FUN_14123c580());
    CEffectService::GetInstance()->FUN_1411a4a00(target);
    FUN_14191fc40(0);
    FUN_14191ff70();
    m_19c = 0;
    FUN_1412761e0(MS2Ptr<AScript>(m_30), m_19c);
}

// @0x14191ff70
void UIBeautyShopDevDialog::FUN_14191ff70()
{
    FUN_1419200c0(0);
    FUN_1419207c0(m_1a0);
}

// @0x14191ffb0
void UIBeautyShopDevDialog::FUN_14191ffb0()
{
    if (m_288 == 0)
        return;
    FUN_14191ff70();
}

// "m_save" is enabled (there are unsaved changes).
// @0x14191fff0
// MS2-FUNCTIONAL: GetChild result copies differ
int UIBeautyShopDevDialog::FUN_14191fff0()
{
    if (m_30.get())
    {
        MS2Ptr<ASButton> spSave = GetChild<ASButton>(CString("m_save"));
        if (spSave.get())
            return spSave->FUN_1422c2030();
    }
    return 0;
}

// The worn customizable items ("buildEquipItems"; only on the cap tab unless forced).
// @0x1419200c0
// MS2-FUNCTIONAL: list iteration and temporaries differ
void UIBeautyShopDevDialog::FUN_1419200c0(int bForce)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc && !(m_30 == 0) && !(m_288 == 0))
    {
        bool bBuild = m_1a0 == 4 || bForce;
        ATL::CAtlList<MS2Ptr<CEquipItem> > aItems(10);
        FUN_140f014b0(&aItems, pPc->FUN_1416561a0());
        ASArray aRows(2);
        POSITION pos = aItems.GetHeadPosition();
        while (pos)
        {
            MS2Ptr<CEquipItem> spEquip(aItems.GetNext(pos));
            if (spEquip.IsNull())
                continue;
            MS2Ptr<CItem> spItem = spEquip->GetItem();
            if (!spItem)
                continue;
            Unk_EquipItemData* pData = spEquip->FUN_1411dc7f0();
            if (pData && bBuild && FUN_141421690(spEquip->GetItem().get()) == 0)
            {
                int nItemId = pData->FUN_14053c510();
                ASObj row(2);
                row.FUN_1407cbb20("guid", FUN_141b71910(spItem->FUN_140526a50()));
                CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
                row.FUN_1407cbb20("itemid", FUN_141b71990(nItemId));
                row.FUN_1407cbb20("itemname", CStringW(strName));
                row.FUN_1407cba60("iconPath", spItem->FUN_140528590());
                ASTooltip tip(pPc, 0x20, 2);
                if (tip.FUN_1409e0d40(spItem.get()))
                    row.FUN_1409adbe0("tooltip", tip.FUN_1422bb870());
                aRows.FUN_1422bc050(row.FUN_1422bb870());
            }
        }
        if (bBuild)
            m_30->Invoke("buildEquipItems", Scaleform::GFx::Value(aRows.FUN_1422bb870()), -1L);
    }
}

// The tab an item belongs to (-1: none).
// @0x1419206a0
void UIBeautyShopDevDialog::FUN_1419206a0(int* pnTab, MS2Ptr<CItemData> spData)
{
    *pnTab = -1;
    if (spData->FUN_14053cfd0())
        *pnTab = 0;
    else if (spData->FUN_14053d020())
        *pnTab = 1;
    else if (spData->FUN_14053d0c0())
        *pnTab = 2;
    else if (spData->FUN_14053c620() == 0xd)
        *pnTab = 6;
}

// @0x141920770
void UIBeautyShopDevDialog::FUN_141920770()
{
    for (int i = 0; i < 7; i++)
        m_1a8[i].RemoveAll();
}

// Preview the worn item of the tab (the selected equip row when the tab has no slot).
// @0x1419207c0
// MS2-FUNCTIONAL: GetChild result copies / row temporary differ
void UIBeautyShopDevDialog::FUN_1419207c0(int nTab)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc && !(m_288 == 0) && m_1a0 >= 0 && m_1a0 < 7)
    {
        int nSlot = FUN_141921580(m_1a0);
        if (nSlot == 0)
        {
            if (m_1a0 == 3)
            {
                FUN_141920aa0(0x9a1d21);
            }
            else
            {
                MS2Ptr<ASTileList> spList = GetChild<ASTileList>(CString("m_equipItems"));
                if (spList.get())
                {
                    if (spList->FUN_1422dccd0() < 0)
                    {
                        spList->FUN_1422dcca0(0);
                    }
                    else
                    {
                        Unk_BSDevRow row(spList->FUN_1422dcd80().operator->(), spList->FUN_1422dccd0());
                        if (row.FUN_1422bb870().IsObject())
                        {
                            Scaleform::GFx::Value vId = row.FUN_1422baa20("itemid");
                            if (vId.IsString())
                                FUN_141920aa0(FUN_141b71a10(vId.GetString()));
                        }
                    }
                }
            }
        }
        else
        {
            MS2Ptr<CEquipItem> spItem = pPc->FUN_141655e10(nSlot);
            if (spItem.get())
                FUN_141920aa0(spItem->FUN_1411dc820());
        }
    }
}

// Preview an item id (unless it is the one already previewed).
// @0x141920aa0
void UIBeautyShopDevDialog::FUN_141920aa0(int nItemId)
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    if (!pPc->FUN_1416561a0()->FUN_1411e09a0())
        return;
    int nCurrent = m_288->FUN_140cd17e0();
    if (nCurrent == 0 || nCurrent != nItemId)
    {
        if (!pPc->FUN_1416561a0()->FUN_1411e0c30(nItemId))
            m_288->FUN_140cd1d50(nItemId);
        m_288->FUN_140cd2660(nItemId);
    }
}

// "OnClickNew" (a hat is worn).
// @0x141920b80
void UIBeautyShopDevDialog::OnClickNew()
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    MS2Ptr<CEquipItem> spItem = pPc->FUN_141655e10(1);
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(spItem->GetItem()->FUN_140527840());
    if (spData == 0)
        return;
    OnClickAdd();
}

// "OnClickAdd": store the hat's cap attach point as the item model's cap transform.
// @0x141920ca0
// MS2-FUNCTIONAL: argument register shuffle of the model table refresh differs
void UIBeautyShopDevDialog::OnClickAdd()
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    MS2Ptr<CEquipItem> spItem = pPc->FUN_141655e10(6);
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(spItem->GetItem()->FUN_140527840());
    if (spData == 0)
        return;
    ATL::CAtlArray<CString> aNames;
    spItem->FUN_1411dca30(6, aNames);
    if (aNames.IsEmpty())
        return;
    if (!FUN_14053ec70(spData.operator->())->FUN_1405471b0())
        return;
    int nModel = spData->FUN_14053ec50();
    MS2Ptr<CEquipModel> spModel = spItem->FUN_1411dc950(aNames[0]);
    if (spModel.get())
    {
        CItemDataTable::ModelPtr spModelData = FUN_140281980()->GetModel(nModel);
        if (spModelData.get())
        {
            if (!FUN_14053ec70(spData.operator->())->FUN_140547360())
                spModelData->FUN_14054b670()->handle.AssignRaw(new MsTransform);
            spModelData->FUN_14054b670()->handle->position =
                static_cast<Unk_BSDevEquipModel*>(spModel.operator->())->FUN_141200130();
            spModelData->FUN_14054b670()->handle->rotation =
                static_cast<Unk_BSDevEquipModel*>(spModel.operator->())->FUN_1412000d0();
            unsigned nKey = ItemModelData::FUN_14054aec0(nModel);
            FUN_140281980()->FUN_140557910(nKey);
        }
    }
}

// "OnClickDelete" (no action in this build).
// @0x141921080
void UIBeautyShopDevDialog::OnClickDelete()
{
    PC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pPc)
        return;
    MS2Ptr<CEquipItem> spItem = pPc->FUN_141655e10(1);
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(spItem->GetItem()->FUN_140527840());
    if (spData == 0)
        return;
}

// Enable "m_new" / "m_add" / "m_delete" (the cap tab, for an item with a cap attach point).
// @0x141921190
// MS2-FUNCTIONAL: GetChild result copies (three pointer hops per child) differ
void UIBeautyShopDevDialog::FUN_141921190(int nItemId)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    int bEnable = 0;
    if (m_1a0 == 6 && FUN_14053ec70(spData.operator->())->FUN_1405471b0())
        bEnable = 1;
    MS2Ptr<ASButton> spNew = GetChild<ASButton>(CString("m_new"));
    if (spNew.get())
        spNew->FUN_1422c1fe0(bEnable);
    MS2Ptr<ASButton> spAdd = GetChild<ASButton>(CString("m_add"));
    if (spAdd.get())
        spAdd->FUN_1422c1fe0(bEnable);
    MS2Ptr<ASButton> spDelete = GetChild<ASButton>(CString("m_delete"));
    if (spDelete.get())
        spDelete->FUN_1422c1fe0(bEnable);
}

// NotifyChangeActiveMyCodiTab: forget the kept previews.
// @0x1419213f0
void UIBeautyShopDevDialog::FUN_1419213f0(NotifyObject* pNotify)
{
    if (m_30 == 0 || m_288 == 0)
        return;
    m_288->FUN_140cd3820();
}

// The previewed item has colours.
// @0x141921460
// MS2-FUNCTIONAL: FUN_14053e370 returns bool in the exe (shared header declares int)
bool UIBeautyShopDevDialog::FUN_141921460()
{
    MS2Ptr<CItemData> spData = FUN_14053f870(m_288->FUN_140cd17e0());
    if (spData == 0)
        return false;
    return spData->FUN_14053e370() != 0;
}

// The selected colour index ("m_colorIndexMenu"; 0 when the item has no colours).
// @0x141921500
int UIBeautyShopDevDialog::FUN_141921500()
{
    if ((m_2b8.get() ? true : false) && FUN_141921460())
        return m_2b8->FUN_1422df6c0();
    return 0;
}
