// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDialogCenterDialog: see uidialogcenterdialog.h.
// MS2-UNIT: ?\uidialogcenterdialog.cpp
// MS2-RANGE: 0x141294100-0x141299650 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VTriggerDebugDialog@@@@QEAA@PEAVTriggerDebugDialog@@@Z 0x141296e60 ; unique
// MS2-PIN: ??4?$MS2Ptr@VTriggerDebugDialog@@@@QEAAAEAV0@AEBV0@@Z 0x141297150 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VTriggerDebugDialog@@@@QEAAAEAV1@PEAVTriggerDebugDialog@@@Z 0x141297190 ; unique
// MS2-PIN: ?vfunc_48@UIDialogCenterDialog@@UEAAHXZ 0x1412976f0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?AddRef@?$MS2Ptr@VTriggerDebugDialog@@@@AEBAXXZ 0x1412991e0 ; manual: exe caller references this copy
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidialogcenterdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uidialogcenterdialog.h"

#include <afxwin.h>
#include <commdlg.h>

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asbutton.h"
#include <efd/Win32/Win32PlatformService.h>
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "triggerdebugdialog.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/clockcriticalsection.h"   // Unk_CriticalSectionLock (was a local lock view)

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----------------------------------------------------------------------------------

// The wedding hall reservation dialog (open with a mode and a tab name).
class UIWeddingHallReservationDialog : public UIDialog
{
public:
    void SetPackage(int nMode);
    void SetMode(const CString& strTab);   // exe: Compare on [rdx home] (a CString*)
};

// The movie child "UIDialogCenterDialog_btn": a clip with a label, a position and a click delegate.
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
MS2_CHECK_SIZE(ASButton, 0x88);

class ASDialog : public ASDisplayObjectContainer {};

// The dialog of a ui id, and the value of a movie member.
class UIDialog* FindDialog(int);   // C3: was FindDialog

// The main window of the application.
class Unk_DcApp { public: void* m_pad; char m_svc; };
class Unk_DcHost;
class Unk_GameContext { public: efd::ServiceManager* GetServiceManager(); };   // C3: member view of the real holder
void* FUN_140aadf80();

// A service object queried by class id (slot 5 = query interface, slot 14 of the host = get service by id).
#define DC_V(n) virtual void vfunc_##n();
class Unk_DcService
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual bool vfunc_5(unsigned nId, void* ppOut);
    DC_V(6) DC_V(7) DC_V(8) DC_V(9) DC_V(10) DC_V(11) DC_V(12) DC_V(13) DC_V(14) DC_V(15)
    virtual void vfunc_16();                                            // the action of the visual tracker menu
};
class Unk_DcHost
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual Unk_DcService* vfunc_14(unsigned nId);
};

// The log dialog singleton (0x1412976a0 returns the global) and its toggle.
class ClientLogManager;
class ClientLogManager   // C3: member view for the former free stand-ins
{
public:
    void ToggleDialog();
};

// The movie of a ui layer and its object factory.
Scaleform::GFx::Movie* GetMovie(int nMovieId);
void FUN_1401d3700(CString& str);
extern const char DAT_142ed3718[];                                      // the open file filter of the xml dialog

// ---- ref-counted pointer to the trigger window (CPtred behind CDialog) ----------------------------------------------------

template<> void MS2Ptr<TriggerDebugDialog>::AddRef() const
{
    if (m_p)
        AddRefImpl(static_cast<CPtred*>(static_cast<TriggerDebugDialog*>(0)));
}
template<> MS2Ptr<TriggerDebugDialog>::MS2Ptr(TriggerDebugDialog* p)
{
    m_p = static_cast<TriggerDebugDialog*>(static_cast<CPtred*>(p));
    AddRef();
}
template<> void MS2Ptr<TriggerDebugDialog>::Release()
{
    if (m_p)
    {
        ReleaseImpl(static_cast<CPtred*>(static_cast<TriggerDebugDialog*>(0)));
        m_p = 0;
    }
}

// ---- helpers --------------------------------------------------------------------------------------------------------

// @0x141296a60
static Unk_DcService* FUN_141296a60(Unk_DcService* pSvc)
{
    Unk_DcService* pOut = 0;
    if (pSvc != 0 && pSvc->vfunc_5(0x7002010, &pOut))
    {
        return pOut;
    }
    else
    {
        return 0;
    }
}

// @0x1412976a0
static void* GetClientLogManager()
{
    return reinterpret_cast<void*>(TSingleton<ClientLogManager>::s_instance);
}

// @0x1412976b0
static HWND GetHwnd(CWnd* pWnd)
{
    return pWnd == 0 ? 0 : pWnd->m_hWnd;
}

// @0x141296b50
Unk_DcService* FUN_141296b50(Unk_DcHost* pHost)
{
    Unk_DcService* pRaw = pHost->vfunc_14(0x7002010);
    Unk_DcService* pSvc = FUN_141296a60(pRaw);
    return pSvc;
}

// @0x141296ab0
UIWeddingHallReservationDialog* GetWeddingHallReservationDialog(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0)
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (ref.get() != 0)
            return dynamic_cast<UIWeddingHallReservationDialog*>(ref.operator UIObject*());
    }
    return 0;
}

// @0x1412968a0
static MS2Ptr<ASButton> CreateButton(int nMovieId, CString strLinkage, __int64 a, int b)
{
    Scaleform::GFx::Movie* pMovie = GetMovie(nMovieId);
    if (pMovie == 0)
        return MS2Ptr<ASButton>(0);
    Scaleform::GFx::Value v;
    pMovie->CreateObject(&v, strLinkage, reinterpret_cast<const Scaleform::GFx::Value*>(a), b);
    if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() != 0)
        return MS2Ptr<ASButton>(0);
    MS2Ptr<ASButton> spBtn(static_cast<ASButton*>(new ASButton(v, nMovieId)));
    return spBtn;
}

// The ui text service (singleton): the text of a "$s_..." key.
class GFxManager { public: CStringW Localize(const CString& strKey); };   // C3: the real member (0x1422b0570, a $-key's localized string)
class Unk_AltStringMgr* GetGFxManager();   // C3: the GFxManager (calls cast back)

// ---- UIDialogCenterDialog -------------------------------------------------------------------------------------------

// @0x141294100
UIDialogCenterDialog::UIDialogCenterDialog()
    : m_map(0x11, 0.75f, 0.25f, 2.25f, 10), m_triggers(10)
{
    m_7c = 1;
    m_80 = 0;
    m_40 = 1;
}

// @0x141294200
UIDialogCenterDialog::~UIDialogCenterDialog()
{
}

// @0x141294290
CString UIDialogCenterDialog::GetTypeName()
{
    return CString("DialogCenterDialog");
}

// @0x1412942e0
void UIDialogCenterDialog::OnLoadComplete()
{
    typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Cb;
    UIDialog::OnLoadComplete();
    BindDragBar(CString("m_dragBar"));
    BindCloseButton(CString("m_closeButton"));
    int nRow = -1;
    int nColumn = 0;
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_npc_info"), 0x4eb0);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_develop"), 0x4eb1);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_hsl"), 0x4eab);
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_light"), 0x4ead);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_rimlight"), 0x4eae);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_chaoslight"), 0x4eac);
    ++nRow;
    nColumn = 0;
    AddCallbackButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_visualtracker"), Cb(this, &UIDialogCenterDialog::OnVisualTracker));
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_visualtrackerlist"), 0x4eb2);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_visualeffect"), 0x4eb3);
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_weapondummy"), 0x4eb4);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_rangepreview"), 0x4eb5);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_colorboost"), 0x4eaf);
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_camera"), 0x4eb6);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_texturedensity"), 0x4eaa);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_create_packet"), 0x4ecc);
    ++nRow;
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_debug_command"), 0x4ea3);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_create_item"), 0x4e25);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_create_npc"), 0x4e46);
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_edit_deco"), 0x4e2c);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_edit_minimap"), 0x4e2b);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_graphic_option"), 0x4e34);
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_damage_meter"), 0x4e44);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_hairphysx"), 0x4e6f);
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_additional_controller"), 0x4e8f);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_stat_controller"), 0x4ea6);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_create_object"), 0x4ed0);
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_preview_text"), 0x4eb7);
    AddCallbackButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_log_dialog"), Cb(this, &UIDialogCenterDialog::OnLogDialog));
    AddCallbackButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_trigger_debug"), Cb(this, &UIDialogCenterDialog::OnTriggerDebug));
    ++nRow;
    ++nRow;
    nColumn = 0;
    AddCallbackButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_create_blueprint"), Cb(this, &UIDialogCenterDialog::OnCreateBlueprint));
    ++nRow;
    nColumn = 0;
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_wedding"), 0x4f8c);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_wedding_billboard"), 0x4f90);
    AddDialogButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_wedding_invitation"), 0x4f8e);
    ++nRow;
    nColumn = 0;
    AddCallbackButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_wedding_hall"), Cb(this, &UIDialogCenterDialog::OnWeddingHallReservation));
    AddCallbackButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_wedding_hall_cancel"), Cb(this, &UIDialogCenterDialog::OnWeddingHallCancel));
    AddCallbackButton(nRow, nColumn++, CString("$s_debug_ui_center_menu_wedding_hall_change"), Cb(this, &UIDialogCenterDialog::OnWeddingHallChange));
}

// @0x141295730
void UIDialogCenterDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_buttons.RemoveAll();
}

// @0x141295770
void UIDialogCenterDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    int nOp = static_cast<CInPacket*>(p)->FUN_14070fe80();
    if (nOp == 0x87)
    {
        int nKind = static_cast<CInPacket*>(p)->ReadUInt8();
        if (nKind == 10)
        {
            CString strPath = static_cast<CInPacket*>(p)->ReadUnicodeStringA();
            int nDialogId = static_cast<CInPacket*>(p)->ReadInt32();
            strPath = strPath.MakeLower();
            Unk_CriticalSectionLock lock(m_lock, 1);
            MS2Ptr<TriggerDebugDialog> spDlg;
            if (!m_triggers.Lookup(strPath, spDlg))
                return;
            spDlg.get()->AddLine(nDialogId);
        }
    }
}

// @0x141295930
void UIDialogCenterDialog::OnDialogButtonClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ASObj evt(params.pArgs[0], 2);
    Scaleform::GFx::Value target = evt.GetMember("target");
    ASButton btn(target, m_28);
    unsigned nId = ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(btn.GetMember("dialogID")))->GetUInt();
    MS2Ptr<UIDialog> spDlg(FindDialog(nId));
    if (spDlg.get() != 0)
        spDlg->FUN_1419246f0();
}

// @0x141295a70
void UIDialogCenterDialog::OnVisualTracker(const Scaleform::GFx::FunctionHandler::Params& params)
{
    auto pHost = reinterpret_cast<Unk_DcHost*>(reinterpret_cast<Unk_GameContext*>(&reinterpret_cast<Unk_DcApp*>(TSingleton<CMainSystem>::GetInstance())->m_svc)->GetServiceManager());
    Unk_DcService* pSvc = FUN_141296b50(pHost);
    if (pSvc != 0)
        pSvc->vfunc_16();
}

// @0x141295ad0
void UIDialogCenterDialog::OnLogDialog(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (GetClientLogManager() != 0)
        ((class ClientLogManager*)(void*)(GetClientLogManager()))->ToggleDialog();
}

// @0x141295b00
void UIDialogCenterDialog::OnCreateBlueprint(const Scaleform::GFx::FunctionHandler::Params& params)
{
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4f7f)));
}

// @0x141295b30
void UIDialogCenterDialog::OnWeddingHallReservation(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIWeddingHallReservationDialog* pDlg = GetWeddingHallReservationDialog(0x4f8d);
    pDlg->SetPackage(1);
    pDlg->SetMode("reservation");
    pDlg->FUN_141924680();
}

// @0x141295bb0
void UIDialogCenterDialog::OnWeddingHallChange(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIWeddingHallReservationDialog* pDlg = GetWeddingHallReservationDialog(0x4f8d);
    pDlg->SetPackage(1);
    pDlg->SetMode("reservationChange");
    pDlg->FUN_141924680();
}

// @0x141295c30
void UIDialogCenterDialog::OnWeddingHallCancel(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIWeddingHallReservationDialog* pDlg = GetWeddingHallReservationDialog(0x4f8d);
    pDlg->SetPackage(1);
    pDlg->SetMode("reservationCancel");
    pDlg->FUN_141924680();
}

// @0x1412965f0
CString UIDialogCenterDialog::FUN_1412965f0(CString strInitialDir, const char* pszFilter)
{
    OPENFILENAMEA ofn = { 0 };
    char szFile[MAX_PATH];
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = GetHwnd(AfxGetMainWnd());
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = 0;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = pszFilter;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = (LPCSTR)strInitialDir;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    CString strResult;
    if (GetOpenFileNameA(&ofn) == 1)
        strResult = ofn.lpstrFile;
    return strResult;
}

// @0x141295cb0
void UIDialogCenterDialog::OnTriggerDebug(const Scaleform::GFx::FunctionHandler::Params& params)
{
    CString strFile = FUN_1412965f0(CString("./Data/Xml/Trigger/"), DAT_142ed3718);
    if (strFile.IsEmpty())
        return;
    FUN_1401d3700(strFile);
    char szDir[MAX_PATH] = { 0 };
    GetCurrentDirectoryA(MAX_PATH, szDir);
    CString strDir(szDir);
    FUN_1401d3700(strDir);
    strDir.Replace("\\", "/");
    CString strPath(strFile);
    strPath.Replace("\\", "/");
    strPath.Replace(strDir, ".");
    Unk_CriticalSectionLock lock(m_lock, 1);
    MS2Ptr<TriggerDebugDialog> spDlg;
    if (m_triggers.Lookup(strPath, spDlg))
        return;
    spDlg.AssignRaw(new TriggerDebugDialog(0));
    spDlg.get()->SetFile(CString(strPath));
    spDlg.get()->Create(0xa7, CWnd::FromHandle(reinterpret_cast<efd::Win32PlatformService*>(FUN_140aadf80())->GetWindowRef()));
    m_triggers.SetAt(strPath, spDlg);
    COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
    pkt.WriteUInt8(9);
    pkt.WriteUnicodeStringA(strPath);
    pkt.WriteBool(true);
    FUN_140710590(pkt);
}

// @0x141296070
void UIDialogCenterDialog::SendSetDebugModeMode9(CString strPath)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_triggers.RemoveKey(strPath);
    COutPacket pkt(static_cast<int>(SendOp::SetDebugMode), 0);
    pkt.WriteUInt8(9);
    pkt.WriteUnicodeStringA(strPath);
    pkt.WriteBool(false);
    FUN_140710590(pkt);
}

// @0x141296150
MS2Ptr<ASButton> UIDialogCenterDialog::CreateGridButton(int nRow, int nColumn, CStringW strLabel)
{
    const int nX = 0xc;
    const int nY = 0x4e;
    const int nWidth = 0xa6;
    const int nHeight = 0x2a;
    int x = nColumn * nWidth + nX;
    int y = nRow * nHeight + nY;
    {
        MS2Ptr<ASButton> spBtn = CreateButton(m_28, CString("UIDialogCenterDialog_btn"), 0, 0);
        if (spBtn.get() != 0)
        {
            spBtn->SetPositionUInt(x, y);
            spBtn->FUN_1422cdfb0(strLabel);
            m_buttons.Add(spBtn);
            m_90->AddChild(spBtn->GetValue());
            return spBtn;
        }
    }
    return MS2Ptr<ASButton>(0);
}

// @0x141296370
void UIDialogCenterDialog::AddDialogButton(int nRow, int nColumn, CString strKey, int nDialogId)
{
    CStringW strLabel = reinterpret_cast<GFxManager*>(GetGFxManager())->Localize(strKey);
    MS2Ptr<ASButton> spBtn = CreateGridButton(nRow, nColumn, strLabel);
    if (spBtn.get() != 0)
    {
        reinterpret_cast<ASObj*>(spBtn.operator->())->SetMemberUInt("dialogID", nDialogId);
        spBtn->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDialogCenterDialog::OnDialogButtonClick), 0);
    }
}

// @0x141296500
void UIDialogCenterDialog::AddCallbackButton(int nRow, int nColumn, CString strKey, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    CStringW strLabel = reinterpret_cast<GFxManager*>(GetGFxManager())->Localize(strKey);
    MS2Ptr<ASButton> spBtn = CreateGridButton(nRow, nColumn, strLabel);
    if (spBtn.get() != 0)
        spBtn->FUN_1422ce240(cb, 0);
}
