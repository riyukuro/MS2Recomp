// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item preview dialog: see uiitempreviewdialog.h.
// MS2-UNIT: ?\uiitempreviewdialog.cpp
// MS2-RANGE: 0x1400ede80-0x1400ee150 .text$di
// MS2-RANGE: 0x1412d5890-0x1412d7040 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitempreviewdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
static CString s_sortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";

#include "uiitempreviewdialog.h"
#include "ms2/client/ms2/uiequipiconcontainer.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_IpActor { public: virtual void vfunc_0(); };
class Unk_IpOutfit;
class Unk_IpOutfitView;
class Unk_IpAvatar
{
public:
#define IP_V(n) virtual void vfunc_##n();
    IP_V(0) IP_V(1) IP_V(2) IP_V(3) IP_V(4) IP_V(5) IP_V(6) IP_V(7) IP_V(8) IP_V(9) IP_V(10) IP_V(11)
    IP_V(12) IP_V(13) IP_V(14) IP_V(15) IP_V(16) IP_V(17) IP_V(18) IP_V(19) IP_V(20) IP_V(21) IP_V(22) IP_V(23)
#undef IP_V
    virtual Unk_IpActor* vfunc_24();
};
class AvatarPC;
AvatarPC* FUN_140a535c0(Unk_IpActor* pObj);

// The preview service (singleton 0x1409bb9e0): the item shown on the preview avatar.
class Unk_IpPreview
{
public:
    void FUN_140d407d0();
    int FUN_140d409e0(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    void FUN_140d40910(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);
    MS2Ptr<CItem> FUN_140d40470();
    int FUN_140d40850();
    MS2Ptr<CItem> FUN_140d40500();
    MS2Ptr<CItemData> FUN_140d40590();
    int FUN_140d40800();
    MS2Ptr<Unk_IpOutfit> FUN_140d40620();
};
Unk_IpPreview* FUN_1409bb9e0();

class Unk_IpOutfitView : public CPtred { public: Unk_IpOutfitView(); };
class Unk_IpOutfit : public CPtred { public: MS2Ptr<Unk_IpOutfitView> FUN_140d3cf00(); };
class Unk_EquipOutfit : public CPtred { public: Unk_EquipOutfit(); };
class Unk_IpPlayer { public: void* FUN_141bd0cc0(); };
Unk_IpPlayer* FUN_1403ed2d0();
CStringW GetStringCommon(int nStringId);
CItemData* FUN_140527840(CItem* pItem);
bool FUN_141b487f0(MS2Ptr<CItemData> spData);
void FUN_1418bee30(ASObj* pObj, int n);
void FUN_1419235d0();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1412d5890
UIItemPreviewDialog::UIItemPreviewDialog()
{
}

// @0x1412d5920
UIItemPreviewDialog::~UIItemPreviewDialog()
{
}

// @0x1412d5990
CString UIItemPreviewDialog::GetTypeName() { return "ItemPreviewDialog"; }
MS2_REPLACE_METHOD(0x1412D5990, UIItemPreviewDialog, GetTypeName, 61, 0xB27CF424);

// @0x1412d59e0
void UIItemPreviewDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_1412d62d0();
    m_equip = 0;
}
MS2_REPLACE_METHOD(0x1412D59E0, UIItemPreviewDialog, vfunc_26, 55, 0x01783B9C);

// @0x1412d5a20
void UIItemPreviewDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_1409bb9e0()->FUN_140d407d0();
}
MS2_REPLACE_METHOD(0x1412D5A20, UIItemPreviewDialog, vfunc_67, 37, 0x2ACBE4B5);

// @0x1412d5a50
int UIItemPreviewDialog::vfunc_65()
{
    if (!vfunc_55()) FUN_1419235d0();
    return UIDialog::vfunc_65();
}
MS2_REPLACE_METHOD(0x1412D5A50, UIItemPreviewDialog, vfunc_65, 57, 0xE7CB367A);

// @0x1412d5a90
void UIItemPreviewDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == 0) {
        vfunc_67();
    } else {
        m_equip.AssignRaw(new UIEquipIconContainer);
        if (m_equip.get() != 0) {
            MS2Ptr<ASMovieClip> spClip = GetChild<ASMovieClip>("m_equipContainer");
            if (spClip.get() != 0) m_equip->FUN_1412d6ca0(spClip);
        }
    }
}
MS2_REPLACE_METHOD(0x1412D5A90, UIItemPreviewDialog, OnLoadComplete, 374, 0xD0A35C51);

// @0x1412d5c10
void UIItemPreviewDialog::vfunc_15() { vfunc_55(); }
MS2_REPLACE_METHOD(0x1412D5C10, UIItemPreviewDialog, vfunc_15, 33, 0x18A5D356);

// @0x1412d5c40
int UIItemPreviewDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    if (FUN_1409bb9e0()->FUN_140d409e0(szMethod, pArgs, nArgs)) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1412D5C40, UIItemPreviewDialog, vfunc_28, 106, 0x6E031EB7);

// @0x1412d5cb0
void UIItemPreviewDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (p2.get() == 0 || p3 == 0) return;
    FUN_1409bb9e0()->FUN_140d40910(p1, p2, p3, p4);
    if (MS2Ptr<ASTextField> spMessage = FUN_140bb4cf0("m_message")) {
        int bNoSlot = 0;
        MS2Ptr<CItem> spItem = FUN_1409bb9e0()->FUN_140d40470();
        if (spItem.get() ? true : false) {
            if (FUN_1409bb9e0()->FUN_140d40850() != 0) {
                MS2Ptr<CItemData> spData(FUN_140527840(spItem));
                if (spData.get() != 0) {
                    if (spData->FUN_14053e260() != 0) {
                        if (spData->FUN_14053e2b0(0) == -1) bNoSlot = 1;
                    }
                }
            }
        }
        if (bNoSlot) spMessage->FUN_1422c4cd0(GetStringCommon(0x9b8));
        else spMessage->FUN_1422c4cd0(GetStringCommon(0));
        MS2Ptr<CItem> spShown = FUN_1409bb9e0()->FUN_140d40500();
        FUN_1412d6330(spShown);
    }
}
MS2_REPLACE_METHOD(0x1412D5CB0, UIItemPreviewDialog, vfunc_25, 812, 0xFCF1276D);

// @0x1412d5ff0
void UIItemPreviewDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    FUN_1412d62d0();
}
MS2_REPLACE_METHOD(0x1412D5FF0, UIItemPreviewDialog, vfunc_16, 34, 0xA6A2E29F);

// @0x1412d6020
bool UIItemPreviewDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17()) return false;
    FUN_1412d6270();
    return true;
}
MS2_REPLACE_METHOD(0x1412D6020, UIItemPreviewDialog, vfunc_17, 47, 0x70D57397);

// @0x1412d6060
int UIItemPreviewDialog::vfunc_o178_1(void* pAvatar)
{
    if (pAvatar == 0) return 0;
    FUN_1412d6270();
    ASObj data(2);
    AvatarPC* pPc = FUN_140a535c0(static_cast<Unk_IpAvatar*>(pAvatar)->vfunc_24());
    if (pPc != 0) {
        if (pPc->GetType() == 1) FUN_1418bee30(&data, 10000);
        bool bShowActions = true;
        MS2Ptr<CItemData> spData = FUN_1409bb9e0()->FUN_140d40590();
        if (spData.get() != 0) bShowActions = FUN_141b487f0(spData);
        data.FUN_1407cbbe0("showActionList", bShowActions);
    }
    m_30->Invoke("initData", data.FUN_1422bb870());
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x1412D6060, UIItemPreviewDialog, IUIAvatarEventListener, vfunc_o178_1, 427, 0x20F573FA);

// @0x1412d6220
int UIItemPreviewDialog::vfunc_o178_0(void*)
{
    FUN_1409bb9e0()->FUN_140d40800();
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x1412D6220, UIItemPreviewDialog, IUIAvatarEventListener, vfunc_o178_0, 37, 0x840A456C);

// @0x1412d6250
int UIItemPreviewDialog::vfunc_o178_2(void*) { return 1; }
MS2_REPLACE_METHOD_VIA(0x1412D6250, UIItemPreviewDialog, IUIAvatarEventListener, vfunc_o178_2, 16, 0x32804D89);

// @0x1412d6270
void UIItemPreviewDialog::FUN_1412d6270()
{
    if (m_30.get()) m_30->Invoke("loadRenderTarget");
}
MS2_REPLACE_METHOD(0x1412D6270, UIItemPreviewDialog, FUN_1412d6270, 83, 0x7EF90741);

// @0x1412d62d0
void UIItemPreviewDialog::FUN_1412d62d0()
{
    if (m_30.get()) m_30->Invoke("unloadRenderTarget");
}
MS2_REPLACE_METHOD(0x1412D62D0, UIItemPreviewDialog, FUN_1412d62d0, 83, 0x87029718);

// MS2-FUNCTIONAL: the exe loads the item through rcx before rdx for the slot fill call (one extra mov); no source form found
// @0x1412d6330
void UIItemPreviewDialog::FUN_1412d6330(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || m_equip == 0) return;
    MS2Ptr<Unk_IpOutfit> spOutfit = FUN_1409bb9e0()->FUN_140d40620();
    MS2Ptr<Unk_IpOutfitView> spView(0);
    if (spOutfit.get() != 0) spView = spOutfit->FUN_140d3cf00();
    MS2Ptr<ASSlot> spSlot(new ASSlot(2));
    if (spSlot.get() != 0) {
        CItem* pItem;
        void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        pItem = spItem.get();
        spSlot->FUN_1409c3860(pItem, pPlayer, 0xd01);
    }
    MS2Ptr<ASEquipIcon> spIcon = m_equip->FUN_140e2a090(0x81, spItem, MS2Ptr<AScript>(spSlot.operator->()), MS2Ptr<Unk_EquipOutfit>(0));
    if (spIcon.get() != 0) {
        spIcon->FUN_1409b9240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPreviewDialog::FUN_1412d66e0), 0);
    }
}
MS2_REPLACE_METHOD(0x1412D6330, UIItemPreviewDialog, FUN_1412d6330, 930, 0x67B5456D);

// @0x1412d66e0
void UIItemPreviewDialog::FUN_1412d66e0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_equip == 0) return;
    MS2Ptr<CItem> spItem = FUN_1409bb9e0()->FUN_140d40500();
    if (spItem == 0) return;
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0) return;
    ASTooltip tip(pPlayer, 2, 2);
    tip.FUN_1409e0d40(spItem.get());
    tip.FUN_1409c6dc0(5);
    *params.pRetVal = tip.FUN_1422bb870();
}
MS2_REPLACE_METHOD(0x1412D66E0, UIItemPreviewDialog, FUN_1412d66e0, 278, 0xD8650525);

// @0x1412d6ca0
void UIEquipIconContainer::FUN_1412d6ca0(MS2Ptr<ASMovieClip> pClip)
{
    m_18 = pClip;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf5d0-0x142caf6f0 .text$yd
