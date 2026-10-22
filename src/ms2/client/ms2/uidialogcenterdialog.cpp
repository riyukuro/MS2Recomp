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
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----------------------------------------------------------------------------------

// The debug window of a trigger xml (an MFC dialog; CPtred sits behind the 0x130 bytes of CDialog).
class TriggerDebugDialog : public CDialog, public CPtred
{
public:
    TriggerDebugDialog(CWnd* pParent);                  // 0x140b9b?? (size 0x630)
    void FUN_140b9b820(CString strPath);                // set the xml path
    void FUN_140b9b870(int nDialogId);                  // show the dialog id
};

// The wedding hall reservation dialog (open with a mode and a tab name).
class UIWeddingHallReservationDialog : public UIDialog
{
public:
    void FUN_140fdbf50(int nMode);
    void FUN_140fdcaa0(CString strTab);
};

// The movie child "UIDialogCenterDialog_btn": a clip with a label, a position and a click delegate.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    Unk_140acd6e0(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cdde0
    void FUN_1409c0d20(const char* szName, unsigned nValue);            // set a member
    void FUN_1422c0060(int x, int y);                                   // set the position
    void FUN_1422cdfb0(const CStringW& strLabel);                       // set the label
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_140acd6e0, 0x88);

class ASDialog : public ASDisplayObjectContainer {};

// The ui manager: toggle a dialog, look one up.
class Unk_DcUiMgr { public: void FUN_141adc750(int nId); };
Unk_DcUiMgr* FUN_1403ed2b0();
class Unk_DcUiRef
{
public:
    ~Unk_DcUiRef();                                                     // 0x1403e5630
    UIObject* FUN_1403e8a70() const;
private:
    void* m_unknown;
    UIObject* m_pObject;
};
MS2_CHECK_SIZE(Unk_DcUiRef, 0x10);
struct Unk_DcUiMgrCall { Unk_DcUiRef FUN_141adcea0(int nId); };
UIObject* FUN_1403ed9e0(Unk_DcUiRef& ref);

// The dialog of a ui id, and the value of a movie member.
UIDialog* FUN_140c300a0(unsigned nDialogID);
int FUN_1409c17e0(const Scaleform::GFx::Value& v);

// The main window of the application.
class Unk_DcApp { public: void* m_pad; char m_svc; };
Unk_DcApp* FUN_14086d260();
class Unk_DcHost;
Unk_DcHost* FUN_140af8310(void* pHolder);
void* FUN_140aadf80();
HWND FUN_14209c720(void* pApp);

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
extern void* DAT_143ad6820;
void FUN_1414515e0(void* pLog);

// The movie of a ui layer and its object factory.
void* FUN_1422bb8b0(int nMovieId);
void FUN_14256e8e0(void* pMovie, Scaleform::GFx::Value* pValue, const char* szClass, __int64 a, int b);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
void* FUN_140c7fa70(size_t nSize);
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
    if (pSvc == 0 || !pSvc->vfunc_5(0x7002010, &pOut))
        pOut = 0;
    return pOut;
}

// @0x1412976a0
static void* FUN_1412976a0()
{
    return DAT_143ad6820;
}

// @0x1412976b0
static HWND FUN_1412976b0(CWnd* pWnd)
{
    if (pWnd == 0)
        return 0;
    return pWnd->m_hWnd;
}

// @0x141296b50
static Unk_DcService* FUN_141296b50(Unk_DcHost* pHost)
{
    return FUN_141296a60(pHost->vfunc_14(0x7002010));
}

// @0x141296ab0
static UIWeddingHallReservationDialog* FUN_141296ab0(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_DcUiRef ref = reinterpret_cast<Unk_DcUiMgrCall*>(FUN_1403ed2b0())->FUN_141adcea0(nId);
        if (ref.FUN_1403e8a70() != 0)
            return dynamic_cast<UIWeddingHallReservationDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// @0x1412968a0
static MS2Ptr<Unk_140acd6e0> FUN_1412968a0(int nMovieId, CString strLinkage, __int64 a, int b)
{
    void* pMovie = FUN_1422bb8b0(nMovieId);
    if (pMovie == 0)
        return MS2Ptr<Unk_140acd6e0>(0);
    Scaleform::GFx::Value v;
    FUN_14256e8e0(pMovie, &v, strLinkage, a, b);
    if (FUN_1409b0390(&v) == 0)
        return MS2Ptr<Unk_140acd6e0>(MS2Ptr<Unk_140acd6e0>(new Unk_140acd6e0(v, nMovieId)));
    return MS2Ptr<Unk_140acd6e0>(0);
}

// The ui text service (singleton): the text of a "$s_..." key.
class Unk_DcText { public: CStringW FUN_1422b0570(const CString& strKey); };
Unk_DcText* FUN_14025e7a0();

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
CString UIDialogCenterDialog::vfunc_1()
{
    return CString("DialogCenterDialog");
}

// @0x1412942e0
void UIDialogCenterDialog::OnLoadComplete()
{
    typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Cb;
    UIDialog::OnLoadComplete();
    FUN_141925fa0(CString("m_dragBar"));
    FUN_141925ec0(CString("m_closeButton"));
    FUN_141296370(0, 0, CString("$s_debug_ui_center_menu_npc_info"), 0x4eb0);
    FUN_141296370(0, 1, CString("$s_debug_ui_center_menu_develop"), 0x4eb1);
    FUN_141296370(0, 2, CString("$s_debug_ui_center_menu_hsl"), 0x4eab);
    FUN_141296370(1, 0, CString("$s_debug_ui_center_menu_light"), 0x4ead);
    FUN_141296370(1, 1, CString("$s_debug_ui_center_menu_rimlight"), 0x4eae);
    FUN_141296370(1, 2, CString("$s_debug_ui_center_menu_chaoslight"), 0x4eac);
    FUN_141296500(2, 0, CString("$s_debug_ui_center_menu_visualtracker"), Cb(this, &UIDialogCenterDialog::FUN_141295a70));
    FUN_141296370(2, 1, CString("$s_debug_ui_center_menu_visualtrackerlist"), 0x4eb2);
    FUN_141296370(2, 2, CString("$s_debug_ui_center_menu_visualeffect"), 0x4eb3);
    FUN_141296370(3, 0, CString("$s_debug_ui_center_menu_weapondummy"), 0x4eb4);
    FUN_141296370(3, 1, CString("$s_debug_ui_center_menu_rangepreview"), 0x4eb5);
    FUN_141296370(3, 2, CString("$s_debug_ui_center_menu_colorboost"), 0x4eaf);
    FUN_141296370(4, 0, CString("$s_debug_ui_center_menu_camera"), 0x4eb6);
    FUN_141296370(4, 1, CString("$s_debug_ui_center_menu_texturedensity"), 0x4eaa);
    FUN_141296370(4, 2, CString("$s_debug_ui_center_menu_create_packet"), 0x4ecc);
    FUN_141296370(6, 0, CString("$s_debug_ui_center_menu_debug_command"), 0x4ea3);
    FUN_141296370(6, 1, CString("$s_debug_ui_center_menu_create_item"), 0x4e25);
    FUN_141296370(6, 2, CString("$s_debug_ui_center_menu_create_npc"), 0x4e46);
    FUN_141296370(7, 0, CString("$s_debug_ui_center_menu_edit_deco"), 0x4e2c);
    FUN_141296370(7, 1, CString("$s_debug_ui_center_menu_edit_minimap"), 0x4e2b);
    FUN_141296370(7, 2, CString("$s_debug_ui_center_menu_graphic_option"), 0x4e34);
    FUN_141296370(8, 0, CString("$s_debug_ui_center_menu_damage_meter"), 0x4e44);
    FUN_141296370(8, 1, CString("$s_debug_ui_center_menu_hairphysx"), 0x4e6f);
    FUN_141296370(9, 0, CString("$s_debug_ui_center_menu_additional_controller"), 0x4e8f);
    FUN_141296370(9, 1, CString("$s_debug_ui_center_menu_stat_controller"), 0x4ea6);
    FUN_141296370(9, 2, CString("$s_debug_ui_center_menu_create_object"), 0x4ed0);
    FUN_141296370(10, 0, CString("$s_debug_ui_center_menu_preview_text"), 0x4eb7);
    FUN_141296500(10, 1, CString("$s_debug_ui_center_menu_log_dialog"), Cb(this, &UIDialogCenterDialog::FUN_141295ad0));
    FUN_141296500(10, 2, CString("$s_debug_ui_center_menu_trigger_debug"), Cb(this, &UIDialogCenterDialog::FUN_141295cb0));
    FUN_141296500(0xc, 0, CString("$s_debug_ui_center_menu_create_blueprint"), Cb(this, &UIDialogCenterDialog::FUN_141295b00));
    FUN_141296370(0xd, 0, CString("$s_debug_ui_center_menu_wedding"), 0x4f8c);
    FUN_141296370(0xd, 1, CString("$s_debug_ui_center_menu_wedding_billboard"), 0x4f90);
    FUN_141296370(0xd, 2, CString("$s_debug_ui_center_menu_wedding_invitation"), 0x4f8e);
    FUN_141296500(0xe, 0, CString("$s_debug_ui_center_menu_wedding_hall"), Cb(this, &UIDialogCenterDialog::FUN_141295b30));
    FUN_141296500(0xe, 1, CString("$s_debug_ui_center_menu_wedding_hall_cancel"), Cb(this, &UIDialogCenterDialog::FUN_141295c30));
    FUN_141296500(0xe, 2, CString("$s_debug_ui_center_menu_wedding_hall_change"), Cb(this, &UIDialogCenterDialog::FUN_141295bb0));
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
    CInPacket* pPkt = static_cast<CInPacket*>(p);
    UIDialog::vfunc_79(p);
    if (pPkt->FUN_14070fe80() == 0x87)
    {
        unsigned char nKind = pPkt->vfunc_o8_1();
        if (nKind == 10)
        {
            CString strPath = pPkt->vfunc_o8_6();
            int nDialogId = pPkt->vfunc_o8_3();
            strPath = strPath.MakeLower();
            Unk_CriticalSectionLock lock(m_lock, 1);
            MS2Ptr<TriggerDebugDialog> spDlg;
            if (m_triggers.Lookup(strPath, spDlg))
                spDlg.get()->FUN_140b9b870(nDialogId);
        }
    }
}

// @0x141295930
void UIDialogCenterDialog::FUN_141295930(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ASObj evt(params.pArgs[0], 2);
    Unk_140acd6e0 btn(evt.FUN_1422baa20("target"), m_28);
    unsigned nId = FUN_1409c17e0(btn.FUN_1422baa20("dialogID"));
    MS2Ptr<UIDialog> spDlg(FUN_140c300a0(nId));
    if (spDlg.get() != 0)
        spDlg->FUN_1419246f0();
}

// @0x141295a70
void UIDialogCenterDialog::FUN_141295a70(const Scaleform::GFx::FunctionHandler::Params& params)
{
    Unk_DcService* pSvc = FUN_141296b50(FUN_140af8310(&FUN_14086d260()->m_svc));
    if (pSvc != 0)
        pSvc->vfunc_16();
}

// @0x141295ad0
void UIDialogCenterDialog::FUN_141295ad0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (FUN_1412976a0() != 0)
        FUN_1414515e0(FUN_1412976a0());
}

// @0x141295b00
void UIDialogCenterDialog::FUN_141295b00(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc750(0x4f7f);
}

// @0x141295b30
void UIDialogCenterDialog::FUN_141295b30(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIWeddingHallReservationDialog* pDlg = FUN_141296ab0(0x4f8d);
    pDlg->FUN_140fdbf50(1);
    pDlg->FUN_140fdcaa0(CString("reservation"));
    pDlg->FUN_141924680();
}

// @0x141295bb0
void UIDialogCenterDialog::FUN_141295bb0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIWeddingHallReservationDialog* pDlg = FUN_141296ab0(0x4f8d);
    pDlg->FUN_140fdbf50(1);
    pDlg->FUN_140fdcaa0(CString("reservationChange"));
    pDlg->FUN_141924680();
}

// @0x141295c30
void UIDialogCenterDialog::FUN_141295c30(const Scaleform::GFx::FunctionHandler::Params& params)
{
    UIWeddingHallReservationDialog* pDlg = FUN_141296ab0(0x4f8d);
    pDlg->FUN_140fdbf50(1);
    pDlg->FUN_140fdcaa0(CString("reservationCancel"));
    pDlg->FUN_141924680();
}

// @0x1412965f0
CString UIDialogCenterDialog::FUN_1412965f0(CString strInitialDir, const char* pszFilter)
{
    OPENFILENAMEA ofn = { 0 };
    char szFile[MAX_PATH];
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = FUN_1412976b0(AfxGetMainWnd());
    ofn.lpstrFile = szFile;
    szFile[0] = 0;
    ofn.nMaxFile = MAX_PATH;
    ofn.nFilterIndex = 0;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrFilter = pszFilter;
    ofn.lpstrInitialDir = (LPCSTR)strInitialDir;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_NOCHANGEDIR;
    CString strResult;
    if (GetOpenFileNameA(&ofn) == 1)
        strResult = ofn.lpstrFile;
    return strResult;
}

// @0x141295cb0
void UIDialogCenterDialog::FUN_141295cb0(const Scaleform::GFx::FunctionHandler::Params& params)
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
    if (!m_triggers.Lookup(strPath, spDlg))
    {
        void* pMem = FUN_140c7fa70(0x630);
        TriggerDebugDialog* pNew = pMem ? new (pMem) TriggerDebugDialog(0) : 0;
        spDlg.AssignRaw(pNew);
        spDlg.get()->FUN_140b9b820(CString(strPath));
        spDlg.get()->Create(0xa7, CWnd::FromHandle(FUN_14209c720(FUN_140aadf80())));
        m_triggers.SetAt(strPath, spDlg);
        COutPacket pkt(0x50, 0);
        pkt.vfunc_o10_1(9);
        pkt.vfunc_o10_6(strPath);
        pkt.vfunc_o10_0(true);
        FUN_140710590(pkt);
    }
}

// @0x141296070
void UIDialogCenterDialog::SendSetDebugModeMode9(CString strPath)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_triggers.RemoveKey(strPath);
    COutPacket pkt(0x50, 0);
    pkt.vfunc_o10_1(9);
    pkt.vfunc_o10_6(strPath);
    pkt.vfunc_o10_0(false);
    FUN_140710590(pkt);
}

// @0x141296150
MS2Ptr<Unk_140acd6e0> UIDialogCenterDialog::FUN_141296150(int nRow, int nColumn, CStringW strLabel)
{
    const int nX = 0xc;
    const int nY = 0x4e;
    const int nWidth = 0xa6;
    const int nHeight = 0x2a;
    int x = nColumn * nWidth + nX;
    int y = nRow * nHeight + nY;
    MS2Ptr<Unk_140acd6e0> spBtn = FUN_1412968a0(m_28, CString("UIDialogCenterDialog_btn"), 0, 0);
    if (spBtn.get() == 0)
        return MS2Ptr<Unk_140acd6e0>(0);
    spBtn->FUN_1422c0060(x, y);
    spBtn->FUN_1422cdfb0(strLabel);
    m_buttons.Add(spBtn);
    m_90->FUN_1422c6900(spBtn->FUN_1422bb870());
    return spBtn;
}

// @0x141296370
void UIDialogCenterDialog::FUN_141296370(int nRow, int nColumn, CString strKey, int nDialogId)
{
    MS2Ptr<Unk_140acd6e0> spBtn = FUN_141296150(nRow, nColumn, FUN_14025e7a0()->FUN_1422b0570(strKey));
    if (spBtn.get() != 0)
    {
        spBtn->FUN_1409c0d20("dialogID", nDialogId);
        spBtn->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDialogCenterDialog::FUN_141295930), 0);
    }
}

// @0x141296500
void UIDialogCenterDialog::FUN_141296500(int nRow, int nColumn, CString strKey, Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb)
{
    MS2Ptr<Unk_140acd6e0> spBtn = FUN_141296150(nRow, nColumn, FUN_14025e7a0()->FUN_1422b0570(strKey));
    if (spBtn.get() != 0)
        spBtn->FUN_1422ce240(cb, 0);
}
