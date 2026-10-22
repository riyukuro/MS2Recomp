// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCHousingPointDialog: the housing point window of the
// player's home (see uiugchousingpointdialog.h). No __FILE__ in the range: the unit name is guessed; the TU repeats the
// shared header statics (the sort type names, "skill"/"stun", the condition table static, the key input controller).
// MS2-UNIT: ?\uiugchousingpointdialog.cpp
// MS2-RANGE: 0x140fadb00-0x140faf390 .text$mn
// MS2-RANGE: 0x1400e1d60-0x1400e20f0 .text$di
// MS2-RANGE: 0x142caa6b0-0x142caa830 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugchousingpointdialog.cpp"
#define MS2_PTR_MOVE_CONVERT
#include "ms2/placeholder/ms2stdafx.h"

#include "uiugchousingpointdialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/masteryinteriortable.h"
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/uimasterydialog.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics of the unit's headers ----

class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100

static CString s_strIconPath("iconPath");
static CString s_strItemDesc("itemDesc");
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_Handle1401cd100 s_handle(0);
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe types ----

class ASDialog : public ASDisplayObject {};

// The ugc home state of the player (the cube map information service).
class Unk_UhpHome
{
public:
    bool FUN_1410c35c0();                                       // the reward was already taken
    int FUN_1410c3470();                                        // the area step
    int FUN_1410c34b0();                                        // the height step
    bool FUN_1410d27c0(__int64 nOwner, int nMode, int* pCount, int* pLimit);   // installed objects of a kind
    __int64 FUN_1410d4fa0();                                    // the housing points
    __int64 FUN_1410d50c0();                                    // the housing point maximum
    unsigned int FUN_1410d5550(int nCategory);                  // installed interiors of a cube category
};
Unk_UhpHome* FUN_1409670e0();

class Unk_UhpOptions { public: bool FUN_14036d570(int nFeature); };      // the content switches
Unk_UhpOptions* FUN_140166410();
class Unk_UhpBlockFlags { public: int FUN_1402c4c90(int nFlag); };       // blocked-action flag set
struct Unk_UhpConfig { char m_pad[8]; Unk_UhpBlockFlags m_flags; };
Unk_UhpConfig* FUN_14025e7b0();                                 // global client config

class Unk_UhpWorld;
class Unk_UhpPc;
Unk_UhpWorld* FUN_1403ed2d0();
Unk_UhpPc* FUN_141bd0cc0(Unk_UhpWorld*);
__int64 FUN_141656ad0(Unk_UhpPc* pPc);                          // the character id
int FUN_1416595d0(Unk_UhpPc* pPc);
int FUN_141659690(Unk_UhpPc* pPc);

// The UI service: dialogs by UI type.
class Unk_UhpUIService
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                    // the dialog object
    int FUN_141adc940(int nId);                                 // the dialog is closed
    void FUN_141adc5d0(int nId);                                // open (toggle)
    void FUN_141adc530(int nId);                                // close
};
Unk_UhpUIService* FUN_1403ed2b0();

class Unk_UhpItemEvents;
Unk_UhpItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_UhpItemEvents*, UIItemEventListener*);   // add a listener
void FUN_1419caeb0(Unk_UhpItemEvents*, UIItemEventListener*);   // remove it

CMasteryInteriorTable* FUN_140933200();
UGCCubeCategoryTable* FUN_1409eed80();
CStringTable* GetStringTable();
CGuideManager* FUN_1409331e0();
int FUN_1418fd280();
bool FUN_1409301c0();
void FUN_140710590(COutPacket& pkt);
CStringW FUN_14016a730(const char* szKey, int nFlags);         // the string of a key
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text

CStringW FormatStringId(int nId, const fmt::ArgList& args);     // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

extern unsigned short DAT_143ab291c;                            // the housing grade of the player
extern __int64 DAT_143ab2930;                                   // the housing exp of the player

// The UI dialog of a UI type (null when the UI service is not up).
// UIMasteryDialog::FUN_140eafdb0 homes a second argument the shared header does not declare (an overload there would
// make that unit's MS2_REPLACE_METHOD ambiguous): call it through a view.
class Unk_UhpMasteryDialog
{
public:
    void FUN_140eafdb0(int nMainTab, int nSubTab);              // 0x140eafdb0 UIMasteryDialog: open on a tab
};

#ifdef __clang__
// Bind the exe's CStringW + const wchar_t* (0x14061ad70); clang otherwise emits an unavailable MFC CopyChars import.
CStringW FUN_14061ad70(const CStringW& left, const wchar_t* right);
#define Unk_UhpConcat(left, right) FUN_14061ad70(left, right)
#else
#define Unk_UhpConcat(left, right) ((left) + (right))
#endif

// @0x140faf160
template <class T> T* GetUIDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x140fadb00
UIUGCHousingPointDialog::UIUGCHousingPointDialog()
{
}

// @0x140fadb80
UIUGCHousingPointDialog::~UIUGCHousingPointDialog()
{
    FUN_1419caeb0(FUN_140a6a840(), this);
}

// @0x140fadc30
CString UIUGCHousingPointDialog::GetTypeName()
{
    return "UGCHousingPointDialog";
}
MS2_REPLACE_METHOD(0x140FADC30, UIUGCHousingPointDialog, GetTypeName, 61, 0x870774B7);

// @0x140fadc80
int UIUGCHousingPointDialog::vfunc_il1()
{
    if (vfunc_55())
        return 0;
    Unk_UhpPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return 0;
    if (FUN_141659690(pPc))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x140FADC80, UIUGCHousingPointDialog, UIItemEventListener, vfunc_il1, 117, 0xBEB78C84);

// @0x140fadd00
int UIUGCHousingPointDialog::vfunc_52()
{
    MS2Ptr<ASUIComponent> spInfo = GetChild<ASButton>("m_interiorInfo");
    if (spInfo)
        return spInfo->FUN_140acce30<ASButton>("m_dragBar") != 0;
    return 0;
}
MS2_REPLACE_METHOD(0x140FADD00, UIUGCHousingPointDialog, vfunc_52, 313, 0xB52E1E1A);

// @0x140fade40
void UIUGCHousingPointDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_1419caeb0(FUN_140a6a840(), this);
}
MS2_REPLACE_METHOD(0x140FADE40, UIUGCHousingPointDialog, vfunc_67, 77, 0x26482748);

// @0x140fadea0
void UIUGCHousingPointDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419260d0("m_webGuideButton", 0);
    RefreshFoldButton();
    RefreshInfo();
    vfunc_84();
    RefreshList();
    FUN_1419cae20(FUN_140a6a840(), this);
}
MS2_REPLACE_METHOD(0x140FADEA0, UIUGCHousingPointDialog, OnLoadComplete, 177, 0x59E8950A);

// @0x140fadf60
void UIUGCHousingPointDialog::vfunc_34()
{
    RefreshInfo();
    vfunc_84();
    RefreshList();
}
MS2_REPLACE_METHOD_VIA(0x140FADF60, UIUGCHousingPointDialog, UIItemEventListener, vfunc_34, 94, 0xD947F6C6);

// @0x140fadfd0
int UIUGCHousingPointDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIHomeResizeDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnRewardItem", szMethod) == 0) {
        OnRewardItem();
        return 1;
    } else if (_stricmp("OnOpenLeisureGroup", szMethod) == 0) {
        if (FUN_1403ed2b0()->FUN_141adc940(0x4f1e)) {
            UIMasteryDialog* pDialog = GetUIDialog<UIMasteryDialog>(0x4f1e);
            if (pDialog != 0)
                reinterpret_cast<Unk_UhpMasteryDialog*>(pDialog)->FUN_140eafdb0(2, 8);
            FUN_1403ed2b0()->FUN_141adc530(0x4f1e);
        } else {
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f1e);
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FADFD0, UIUGCHousingPointDialog, vfunc_28, 243, 0x1AB60EC2);

// @0x140fae0d0
void UIUGCHousingPointDialog::FUN_140fae0d0()
{
    RefreshInfo();
}
MS2_REPLACE_METHOD(0x140FAE0D0, UIUGCHousingPointDialog, FUN_140fae0d0, 24, 0xB49D2BEF);

// @0x140fae0f0
// MS2-FUNCTIONAL: the exe copies the GetChild result pointer through three dead stack slots (unknown source form)
int UIUGCHousingPointDialog::RefreshFoldButton()
{
    if (FUN_1418fd280() == 0)
        return 0;
    {
        MS2Ptr<ASButton> spFold = GetChild<ASButton>("m_fold");
        if (spFold != 0)
            spFold->FUN_1422ce090(IsInMyHome() ? false : true);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FAE0F0, UIUGCHousingPointDialog, RefreshFoldButton, 204, 0xC53870EE);

// @0x140fae1d0
void UIUGCHousingPointDialog::RefreshInfo()
{
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog == 0)
        return;
    bool bReceive = CanReceiveReward();
    unsigned short nGrade = DAT_143ab291c;
    unsigned short nNext = nGrade + 1;
    __int64 nPoint = FUN_1409670e0()->FUN_1410d4fa0();
    __int64 nMaxPoint = FUN_1409670e0()->FUN_1410d50c0();
    bool bMaster = FUN_140933200()->FUN_140ebb020() < nNext ? true : false;
    ASObj obj(2);
    obj.FUN_1409c48f0("interiorLevel", nGrade);
    obj.FUN_1407cbb20("interiorTitle", FormatStringId(0x6fe, nGrade));
    obj.FUN_1409c1180("interiorExp", DAT_143ab2930);
    obj.FUN_1409c1180("interiorPoint", nPoint);
    obj.FUN_1409c1180("interiorMaxPoint", nMaxPoint);
    obj.FUN_1407cbbe0("interiorMaster", bMaster);
    obj.FUN_1407cbbe0("receiveItem", bReceive);
    MS2Ptr<MasteryInteriorInfo> spNext = FUN_140933200()->GetMastery(nNext);
    if (spNext.get() != 0)
        obj.FUN_1409c0d20("interiorMaxExp", spNext->m_nValue);
    MS2Ptr<InteriorPointReward> spReward = FUN_140933200()->GetPointReward(nPoint);
    if (spReward.get() != 0) {
        obj.FUN_1407cbb20(s_strIconPath, FUN_14016a730(spReward->m_strIcon, 0));
        obj.FUN_1407cbb20(s_strItemDesc, GetStringCommonByKey(FUN_14016a730(spReward->m_strKey, 0)));
    }
    dialog->FUN_140acd1f0("buildInteriorInfo", obj);
    if (bReceive)
        FUN_1409331e0()->AddTrigger(static_cast<CGuideManager::TriggerType>(0x1b), 1, 0);
}
MS2_REPLACE_METHOD(0x140FAE1D0, UIUGCHousingPointDialog, RefreshInfo, 1011, 0x634D59D7);

// @0x140fae5d0
void UIUGCHousingPointDialog::RefreshList()
{
    Unk_UhpPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog == 0)
        return;
    ASArray list(2);
    UGCCubeCategoryTable::InteriorMap& interiors = FUN_1409eed80()->GetBonusInteriors();
    for (POSITION pos = interiors.GetStartPosition(); pos != 0; interiors.GetNext(pos)) {
        ECubeCategory nCategory = interiors.GetKeyAt(pos);
        UGCCubeCategoryTable::InteriorPtr spInterior = interiors.GetValueAt(pos);
        CStringW strPoint;
        strPoint.Format(L"+%d", spInterior->m_nBonusPoint);
        unsigned int nMax;
        unsigned int nCount = FUN_1409670e0()->FUN_1410d5550(nCategory);
        nMax = spInterior->m_nBonusCount;
        CStringW strCount;
        strCount.Format(L"%d/%d", nCount, nMax);
        ASObj item(2);
        item.FUN_1407cbb20("name", GetStringTable()->FUN_141811980(0x32, nCategory));
        item.FUN_1407cbb20("count", strCount);
        item.FUN_1407cbb20("point", strPoint);
        item.FUN_1407cbbe0("active", nCount >= nMax);
        list.FUN_1422bc050(item.FUN_1422bb870());
    }
    ASObj obj(2);
    obj.FUN_1409adbe0("interiorList", list.FUN_1422bb870());
    dialog->FUN_140acd1f0("buildInteriorList", obj);
}
MS2_REPLACE_METHOD(0x140FAE5D0, UIUGCHousingPointDialog, RefreshList, 1026, 0x64FB61EB);

// @0x140fae9e0
void UIUGCHousingPointDialog::vfunc_84()
{
    Unk_UhpPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog == 0)
        return;
    int nNpcCount = 0;
    int nNpcLimit = 0;
    int nPortalCount = 0;
    int nPortalLimit = 0;
    int nInstallCount = 0;
    int nInstallLimit = 0;
    bool bShrink = true;
    bool bExtend = true;
    if (!FUN_140166410()->FUN_14036d570(0xe4))
        bShrink = false;
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(99) != 0)
        bShrink = false;
    FUN_1409670e0()->FUN_1410d27c0(FUN_141656ad0(pPc), 1, &nNpcCount, &nNpcLimit);
    FUN_1409670e0()->FUN_1410d27c0(FUN_141656ad0(pPc), 2, &nPortalCount, &nPortalLimit);
    FUN_1409670e0()->FUN_1410d27c0(FUN_141656ad0(pPc), 4, &nInstallCount, &nInstallLimit);
    CStringW strPlace;
    strPlace.Append(Unk_UhpConcat(FormatStringId(0x701, nNpcCount, nNpcLimit), L"\n"));
    strPlace.Append(Unk_UhpConcat(FormatStringId(0x702, nPortalCount, nPortalLimit), L"\n"));
    strPlace.Append(Unk_UhpConcat(FUN_14028dfa0(CStringW(L"s_mainplayinfo_installnpc_count"), nInstallCount, nInstallLimit), L"\n"));
    ASObj obj(2);
    obj.FUN_1407cbb20("place", strPlace);
    int nArea;
    obj.FUN_1407cbb20("extensionArea", FUN_14028dfa0(CStringW(L"s_home_info_area"), nArea = FUN_1409670e0()->FUN_1410c3470()));
    int nHeight;
    obj.FUN_1407cbb20("extensionHeight", FUN_14028dfa0(CStringW(L"s_home_info_height"), nHeight = FUN_1409670e0()->FUN_1410c34b0()));
    obj.FUN_1407cbbe0("shrinkEnable", bShrink);
    obj.FUN_1407cbbe0("extensionEnable", bExtend);
    dialog->FUN_140acd1f0("buildInteriorExtension", obj);
}
MS2_REPLACE_METHOD(0x140FAE9E0, UIUGCHousingPointDialog, vfunc_84, 1519, 0x598EBA96);

// @0x140faefe0
void UIUGCHousingPointDialog::OnRewardItem()
{
    if (FUN_1409301c0() == false) {
        COutPacket pkt(0x37, 0);
        pkt.Encode1(0x28);
        FUN_140710590(pkt);
        FUN_1409331e0()->AddTrigger(static_cast<CGuideManager::TriggerType>(0x1b), 2, 0);
    }
}
MS2_REPLACE_METHOD(0x140FAEFE0, UIUGCHousingPointDialog, OnRewardItem, 114, 0xD32C7259);

// @0x140faf060
bool UIUGCHousingPointDialog::IsInMyHome()
{
    Unk_UhpPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    return FUN_1416595d0(pPc) ? true : false;
}
MS2_REPLACE_METHOD(0x140FAF060, UIUGCHousingPointDialog, IsInMyHome, 75, 0x05CE87F6);

// @0x140faf0c0
bool UIUGCHousingPointDialog::CanReceiveReward()
{
    if (FUN_1409301c0())
        return false;
    if (FUN_1409670e0()->FUN_1410c35c0())
        return false;
    __int64 nPoint = FUN_1409670e0()->FUN_1410d4fa0();
    unsigned int nBox = FUN_140933200()->GetDropBox(nPoint);
    if (nBox > 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140FAF0C0, UIUGCHousingPointDialog, CanReceiveReward, 107, 0xB307293C);
