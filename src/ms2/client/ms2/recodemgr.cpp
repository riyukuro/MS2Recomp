// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's recodemgr.cpp: RecodeMgr, the screen-recording
// service (a CThread + TSingleton; the recording is done by the MS2RenderContext's recode surface, RecodeMgr starts and
// stops it and launches the external MS2Media recorder exactly once, guarded by the named mutex "MS2Media"), and the
// MFC debug dialog CResearchAndDevelopmentDialog that drives it together with the net stream sound.
// MS2-UNIT: ?\recodemgr.cpp
// MS2-RANGE: 0x140c9ba20-0x140c9cc60 .text$mn
// MS2-PIN: ??_7RecodeMgr@@6B?$TSingleton@VRecodeMgr@@@@@ 0x142e15460
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\recodemgr.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <direct.h>
#include <shellapi.h>

#include "ms2/placeholder/recodemgr.h"
#include "researchanddevelopmentdialog.h"
#include "ms2rendercontext.h"
#include "soundservice.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The mutex wrapper RecodeMgr uses to run one MS2Media (0x10 bytes, no vftable).
class Unk_RmMutex
{
public:
    Unk_RmMutex(const char* szName);                        // 0x140c9c030
    ~Unk_RmMutex();                                         // 0x140c9c090
    int FUN_140c9c1e0();                                    // the mutex existed already
private:
    DWORD m_dwError;                                        // +0x00
    HANDLE m_hMutex;                                        // +0x08
};
MS2_CHECK_SIZE(Unk_RmMutex, 0x10);

struct Unk_RmRenderLink { char m_pad[0x38]; ecr::RenderContext* m_pContext; };
struct Unk_RmRenderService { char m_pad[0x48]; Unk_RmRenderLink* m_pLink; };
class Unk_RmApp { public: HWND FUN_14209c720(); };
class Unk_RmGraphic { public: void FUN_1409a8ab0(); void FUN_1409a8aa0(); };
class Unk_RmOption { public: Unk_RmGraphic* FUN_1409a8ac0(); };

Unk_RmApp* FUN_140aadf80();
Unk_RmOption* FUN_1409a8b10();
void FUN_14098a440(CDialogEx* pDlg, CDataExchange* pDX);            // 0x14098a440 CDialogEx::DoDataExchange
Unk_RmRenderService* FUN_1413f9890();

// @0x140c9cb10
CSoundService* FUN_140c9cb10() { return TSingleton<CSoundService>::s_instance; }

// @0x140c9c1a0
static ecr::RenderContext* FUN_140c9c1d0(Unk_RmRenderLink* pLink);
static ecr::RenderContext* FUN_140c9c1a0(Unk_RmRenderService* pService)
{
    if (pService->m_pLink != 0)
        return FUN_140c9c1d0(pService->m_pLink);
    return 0;
}

// @0x140c9c1d0
static ecr::RenderContext* FUN_140c9c1d0(Unk_RmRenderLink* pLink)
{
    return pLink->m_pContext;
}

// ---- RecodeMgr ------------------------------------------------------------------------------------------------------

// @0x140c9ba20
RecodeMgr::RecodeMgr()
{
    m_bRecording = 0;
    m_70 = 0;
    m_74 = 0;
    m_6c = 0;
}

// @0x140c9bac0
RecodeMgr::~RecodeMgr()
{
}

// @0x140c9bb20
void RecodeMgr::FUN_140c9bb20()
{
    FUN_140c9bc00();
}

// @0x140c9bb40
int RecodeMgr::FUN_140c9bb40()
{
    return m_bRecording;
}

// @0x140c9bb60
int RecodeMgr::FUN_140c9bb60()
{
    FUN_140c9bc00();
    MS2RenderContext* pContext = dynamic_cast<MS2RenderContext*>(FUN_140c9c1a0(FUN_1413f9890()));
    if (pContext != 0)
    {
        FUN_140c9be00();
        if (pContext->CreateRecodeSurface() == 0)
        {
            pContext->ReleaseRecodeSurface();
            return 0;
        }
        pContext->EnableRecode();
        m_bRecording = 1;
    }
    else
    {
        return 0;
    }
    return 1;
}

// @0x140c9bc00
int RecodeMgr::FUN_140c9bc00()
{
    m_bRecording = 0;
    MS2RenderContext* pContext = dynamic_cast<MS2RenderContext*>(FUN_140c9c1a0(FUN_1413f9890()));
    if (pContext != 0)
        pContext->ReleaseRecodeSurface();
    return 1;
}

// @0x140c9bc70
int RecodeMgr::FUN_140c9bc70(CString strText)
{
    FUN_140c9bc00();
    MS2RenderContext* pContext = dynamic_cast<MS2RenderContext*>(FUN_140c9c1a0(FUN_1413f9890()));
    if (pContext != 0)
    {
        FUN_140c9be00();
        if (pContext->CreateRecodeSurface() == 0)
        {
            pContext->ReleaseRecodeSurface();
            return 0;
        }
        pContext->SetRecodeText(strText);
        m_bRecording = 1;
    }
    else
    {
        return 0;
    }
    return 1;
}

// @0x140c9bda0
void RecodeMgr::FUN_140c9bda0() { FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8ab0(); }

// @0x140c9bdd0
void RecodeMgr::FUN_140c9bdd0() { FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8aa0(); }

// @0x140c9be00
int RecodeMgr::FUN_140c9be00()
{
    _mkdir("Movies");
    Unk_RmMutex* pMutex = new Unk_RmMutex("MS2Media");
    if (pMutex != 0)
    {
        if (!pMutex->FUN_140c9c1e0())
        {
            delete pMutex;
            CString strExe;
            strExe.Format(".\\MS2Media\\MS2Media.exe");
            SHELLEXECUTEINFOA info;
            memset(&info, 0, sizeof(info));
            info.cbSize = sizeof(info);
            info.fMask = 0;
            info.hwnd = FUN_140aadf80()->FUN_14209c720();
            info.lpVerb = "Open";
            info.lpFile = strExe;
            info.lpDirectory = 0;
            info.nShow = 7;
            info.hInstApp = 0;
            info.lpParameters = "";
            ShellExecuteExA(&info);
        }
        else
        {
            delete pMutex;
        }
    }
    return 1;
}

// @0x140c9c030
Unk_RmMutex::Unk_RmMutex(const char* szName)
{
    m_hMutex = CreateMutexA(0, 0, szName);
    m_dwError = GetLastError();
}

// @0x140c9c090
Unk_RmMutex::~Unk_RmMutex()
{
    if (m_hMutex != 0)
    {
        CloseHandle(m_hMutex);
        m_hMutex = 0;
    }
}

// @0x140c9c1e0
int Unk_RmMutex::FUN_140c9c1e0()
{
    return m_dwError == 0xb7;
}

// ---- CResearchAndDevelopmentDialog ------------------------------------------------------------------------------------

IMPLEMENT_DYNAMIC(CResearchAndDevelopmentDialog, CDialogEx)

// @0x140c9c260
CResearchAndDevelopmentDialog::CResearchAndDevelopmentDialog(CWnd* pParent)
    : CDialogEx(0xa1, pParent)
    , m_strUrl("http://184.107.132.90:4050/192K/")
    , m_strVolume("")
    , m_strStatus("")
    , m_strRecordName("")
    , m_strRecordStatus("")
{
}

// @0x140c9c350
CResearchAndDevelopmentDialog::~CResearchAndDevelopmentDialog()
{
}

// @0x140c9c400
BOOL CResearchAndDevelopmentDialog::OnInitDialog()
{
    if (!CDialog::OnInitDialog())
        return 0;
    m_sldVolume.SetRange(1, 100, 0);
    m_sldVolume.SetPos(100);
    m_sldVolume.SetTicFreq(10);
    m_sldVolume.SetLineSize(1);
    m_sldVolume.SetPageSize(10);
    m_sldVolume.ClearSel(0);
    ShowWindow(5);
    return 1;
}

// @0x140c9c4e0
void CResearchAndDevelopmentDialog::FUN_140c9c4e0(CString strText)
{
    m_strStatus = strText;
    UpdateData(0);
}

// @0x140c9c540
void CResearchAndDevelopmentDialog::FUN_140c9c540(CString strText)
{
    m_strRecordStatus = strText;
    UpdateData(0);
}

// @0x140c9c5a0
void CResearchAndDevelopmentDialog::DoDataExchange(CDataExchange* pDX)
{
    FUN_14098a440(this, pDX);
    DDX_Text(pDX, 0x4e4, m_strUrl);
    DDX_Control(pDX, 0x4e7, m_sldVolume);
    DDX_Text(pDX, 0x4e8, m_strVolume);
    DDX_Text(pDX, 0x4e9, m_strStatus);
    DDX_Text(pDX, 0x4ea, m_strRecordName);
    DDX_Text(pDX, 0x4ee, m_strRecordStatus);
}

BEGIN_MESSAGE_MAP(CResearchAndDevelopmentDialog, CDialogEx)
    ON_BN_CLICKED(2, &CResearchAndDevelopmentDialog::OnBnClickedCancel)
    ON_BN_CLICKED(1, &CResearchAndDevelopmentDialog::OnBnClickedOk)
    ON_BN_CLICKED(0x4e5, &CResearchAndDevelopmentDialog::OnBnClickedPlay)
    ON_BN_CLICKED(0x4e6, &CResearchAndDevelopmentDialog::OnBnClickedStop)
    ON_NOTIFY(NM_CUSTOMDRAW, 0x4e7, &CResearchAndDevelopmentDialog::OnNMCustomdrawVolume)
    ON_BN_CLICKED(0x4ec, &CResearchAndDevelopmentDialog::OnBnClickedRecord)
    ON_BN_CLICKED(0x4ed, &CResearchAndDevelopmentDialog::OnBnClickedStopRecord)
    ON_NOTIFY(NM_CLICK, 0x4ef, &CResearchAndDevelopmentDialog::OnNMClickHelp)
END_MESSAGE_MAP()

// @0x140c9c6b0
void CResearchAndDevelopmentDialog::OnBnClickedCancel()
{
    CDialog::OnCancel();
}

// @0x140c9c6d0
void CResearchAndDevelopmentDialog::OnBnClickedOk()
{
    CDialog::OnOK();
}

// @0x140c9c6f0
void CResearchAndDevelopmentDialog::OnBnClickedPlay()
{
    UpdateData(1);
    if (m_strUrl.IsEmpty())
        return;
    if (FUN_140c9cb10() != 0)
    {
        FUN_140c9cb10()->FUN_1417af4f0(CStringA(m_strUrl));
        int nPos = m_sldVolume.GetPos();
        float fVolume = (float)nPos * 0.01f;
        FUN_140c9cb10()->FUN_1417ae760(fVolume);
    }
}

// @0x140c9c7d0
void CResearchAndDevelopmentDialog::OnBnClickedStop()
{
    if (FUN_140c9cb10() != 0)
        FUN_140c9cb10()->FUN_1417af600();
}

// @0x140c9c800
void CResearchAndDevelopmentDialog::OnNMCustomdrawVolume(NMHDR* pNMHDR, LRESULT* pResult)
{
    int nPos = m_sldVolume.GetPos();
    if (FUN_140c9cb10() != 0)
    {
        float fVolume = (float)nPos * 0.01f;
        FUN_140c9cb10()->FUN_1417ae760(fVolume);
        m_strVolume.Format("%.2f", fVolume);
        UpdateData(0);
    }
    *pResult = 0;
}

// @0x140c9c8b0
void CResearchAndDevelopmentDialog::OnBnClickedRecord()
{
    UpdateData(1);
    if (RecodeMgr::GetInstance() != 0 && !m_strRecordName.IsEmpty())
        RecodeMgr::GetInstance()->FUN_140c9bc70(CString(m_strRecordName));
}

// @0x140c9c950
void CResearchAndDevelopmentDialog::OnBnClickedStopRecord()
{
    if (RecodeMgr::GetInstance() != 0)
        RecodeMgr::GetInstance()->FUN_140c9bc00();
}

// @0x140c9c980
void CResearchAndDevelopmentDialog::OnNMClickHelp(NMHDR* pNMHDR, LRESULT* pResult)
{
    ShellExecuteA(0, "open", "iexplore.exe", "https://support.microsoft.com/ko-kr/help/2247769", 0, 1);
    *pResult = 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
