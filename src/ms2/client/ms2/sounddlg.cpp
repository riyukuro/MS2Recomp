// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's sounddlg.cpp: the volume tool dialog.
// MS2-UNIT: ?\sounddlg.cpp
// MS2-RANGE: 0x141774240-0x141775810 .text$mn
// MS2-PIN: ??_7CSoundDlg@@6B?$TSingleton@VCSoundDlg@@@@@ 0x142f639c8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\sounddlg.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "sounddlg.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2color.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

IMPLEMENT_DYNAMIC(CSoundDlg, CDialog)

// The UCRT's header-inline memcpy_s / memmove_s of this TU (0x1417755a0 / 0x1417756f0), kept alive through ATL::Checked.
// @0x1417755a0
#pragma function(memset, memcpy)
static __inline errno_t ms2_sd_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnSdMemcpyS)(void*, size_t, const void*, size_t) = &ms2_sd_memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();

// @0x141774260
CSoundDlg::CSoundDlg(CWnd* pParent)
    : CToolBaseDialog(0x92, pParent)
    , m_strMyPcToNpc(""), m_strMyPcToObject(""), m_strMyPcToBreakableObject(""), m_strNpcToMyPc("")
    , m_strOtherPc(""), m_strPcToNpc(""), m_strPcToBreakableObject(""), m_strNpcToPc("")
{
}

// @0x141774460
CSoundDlg::~CSoundDlg()
{
}

// @0x1417745f0
void CSoundDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, 0x4d1, m_sldMyPcToNpc);
    DDX_Control(pDX, 0x4d9, m_sldMyPcToObject);
    DDX_Control(pDX, 0x4da, m_sldMyPcToBreakableObject);
    DDX_Control(pDX, 0x4df, m_sldNpcToMyPc);
    DDX_Control(pDX, 0x4db, m_sldOtherPc);
    DDX_Control(pDX, 0x4dc, m_sldPcToNpc);
    DDX_Control(pDX, 0x4dd, m_sldPcToBreakableObject);
    DDX_Control(pDX, 0x4de, m_sldNpcToPc);
    DDX_Text(pDX, 0x4d2, m_strMyPcToNpc);
    DDX_Text(pDX, 0x4d3, m_strMyPcToObject);
    DDX_Text(pDX, 0x4d4, m_strMyPcToBreakableObject);
    DDX_Text(pDX, 0x4d5, m_strNpcToMyPc);
    DDX_Text(pDX, 0x4d6, m_strOtherPc);
    DDX_Text(pDX, 0x4d7, m_strPcToNpc);
    DDX_Text(pDX, 0x4d8, m_strPcToBreakableObject);
    DDX_Text(pDX, 0x4e0, m_strNpcToPc);
}

template<> float* Common::Constants::Value<float>::Set(const float& v);     // defined below (0x1417754b0)
#define GetConstants() static_cast<Client::Constants*>(FUN_1401d3200())

// @0x1417747f0
BOOL CSoundDlg::OnInitDialog()
{
    if (!CToolBaseDialog::OnInitDialog())
        return 0;
    m_sldMyPcToNpc.SetRange(0, 10, 1);
    m_sldMyPcToNpc.SetPageSize(1);
    { MS2Color kColor(10); m_sldMyPcToNpc.SetPos(GetConstants()->VolumeMyPcToNpc.Read() * kColor); }
    m_sldMyPcToObject.SetRange(0, 10, 1);
    { MS2Color kColor(10); m_sldMyPcToObject.SetPos(GetConstants()->VolumeMyPcToObject.Read() * kColor); }
    m_sldMyPcToBreakableObject.SetRange(0, 10, 1);
    { MS2Color kColor(10); m_sldMyPcToBreakableObject.SetPos(GetConstants()->VolumeMyPcToBreakableObject.Read() * kColor); }
    m_sldNpcToMyPc.SetRange(0, 10, 1);
    { MS2Color kColor(10); m_sldNpcToMyPc.SetPos(GetConstants()->VolumeNpcToMyPc.Read() * kColor); }
    m_sldOtherPc.SetRange(0, 10, 1);
    { MS2Color kColor(10); m_sldOtherPc.SetPos(GetConstants()->VolumeOtherPc.Read() * kColor); }
    m_sldPcToNpc.SetRange(0, 10, 1);
    { MS2Color kColor(10); m_sldPcToNpc.SetPos(GetConstants()->VolumePcToNpc.Read() * kColor); }
    m_sldPcToBreakableObject.SetRange(0, 10, 1);
    { MS2Color kColor(10); m_sldPcToBreakableObject.SetPos(GetConstants()->VolumePcToBreakableObject.Read() * kColor); }
    m_sldNpcToPc.SetRange(0, 10, 1);
    { MS2Color kColor(10); m_sldNpcToPc.SetPos(GetConstants()->VolumeNpcToPc.Read() * kColor); }
    m_strMyPcToNpc.Format("%.1f", (double)*GetConstants()->VolumeMyPcToNpc.Get());
    m_strMyPcToObject.Format("%.1f", (double)*GetConstants()->VolumeMyPcToObject.Get());
    m_strMyPcToBreakableObject.Format("%.1f", (double)*GetConstants()->VolumeMyPcToBreakableObject.Get());
    m_strNpcToMyPc.Format("%.1f", (double)*GetConstants()->VolumeNpcToMyPc.Get());
    m_strOtherPc.Format("%.1f", (double)*GetConstants()->VolumeOtherPc.Get());
    m_strPcToNpc.Format("%.1f", (double)*GetConstants()->VolumePcToNpc.Get());
    m_strPcToBreakableObject.Format("%.1f", (double)*GetConstants()->VolumePcToBreakableObject.Get());
    m_strNpcToPc.Format("%.1f", (double)*GetConstants()->VolumeNpcToPc.Get());
    UpdateData(0);
    return 1;
}

// @0x141774e10
BOOL CSoundDlg::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->wParam == 1)
    {
        if (pMsg->hwnd == m_sldMyPcToNpc.m_hWnd)
        {
            int nPos = m_sldMyPcToNpc.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumeMyPcToNpc.Set(fVolume);
            m_strMyPcToNpc.Format("%.1f", (double)*GetConstants()->VolumeMyPcToNpc.Get());
            UpdateData(0);
        }
        else if (pMsg->hwnd == m_sldMyPcToObject.m_hWnd)
        {
            int nPos = m_sldMyPcToObject.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumeMyPcToObject.Set(fVolume);
            m_strMyPcToObject.Format("%.1f", (double)*GetConstants()->VolumeMyPcToObject.Get());
            UpdateData(0);
        }
        else if (pMsg->hwnd == m_sldMyPcToBreakableObject.m_hWnd)
        {
            int nPos = m_sldMyPcToBreakableObject.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumeMyPcToBreakableObject.Set(fVolume);
            m_strMyPcToBreakableObject.Format("%.1f", (double)*GetConstants()->VolumeMyPcToBreakableObject.Get());
            UpdateData(0);
        }
        else if (pMsg->hwnd == m_sldNpcToMyPc.m_hWnd)
        {
            int nPos = m_sldNpcToMyPc.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumeNpcToMyPc.Set(fVolume);
            m_strNpcToMyPc.Format("%.1f", (double)*GetConstants()->VolumeNpcToMyPc.Get());
            UpdateData(0);
        }
        else if (pMsg->hwnd == m_sldOtherPc.m_hWnd)
        {
            int nPos = m_sldOtherPc.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumeOtherPc.Set(fVolume);
            m_strOtherPc.Format("%.1f", (double)*GetConstants()->VolumeOtherPc.Get());
            UpdateData(0);
        }
        else if (pMsg->hwnd == m_sldPcToNpc.m_hWnd)
        {
            int nPos = m_sldPcToNpc.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumePcToNpc.Set(fVolume);
            m_strPcToNpc.Format("%.1f", (double)*GetConstants()->VolumePcToNpc.Get());
            UpdateData(0);
        }
        else if (pMsg->hwnd == m_sldPcToBreakableObject.m_hWnd)
        {
            int nPos = m_sldPcToBreakableObject.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumePcToBreakableObject.Set(fVolume);
            m_strPcToBreakableObject.Format("%.1f", (double)*GetConstants()->VolumePcToBreakableObject.Get());
            UpdateData(0);
        }
        else if (pMsg->hwnd == m_sldNpcToPc.m_hWnd)
        {
            int nPos = m_sldNpcToPc.GetPos();
            float fVolume = 0.1f * (float)nPos;
            GetConstants()->VolumeNpcToPc.Set(fVolume);
            m_strNpcToPc.Format("%.1f", (double)*GetConstants()->VolumeNpcToPc.Get());
            UpdateData(0);
        }
    }
    return CToolBaseDialog::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(CSoundDlg, CDialog)   // the exe chains to CDialog, not CToolBaseDialog
    ON_WM_CLOSE()
    ON_COMMAND(IDOK, &CSoundDlg::OnBnClickedOk)
    ON_COMMAND(IDCANCEL, &CSoundDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

// @0x1417753f0
void CSoundDlg::OnBnClickedOk()
{
}

// @0x141775400
void CSoundDlg::OnBnClickedCancel()
{
    CDialog::OnCancel();
}

// @0x141775420
void CSoundDlg::OnClose()
{
    CToolBaseDialog::OnClose();
}

// @0x1417754b0
template<> float* Common::Constants::Value<float>::Set(const float& v)
{
    if (!m_defined)
        m_defined = true;
    m_value = v;
    return &m_value;
}
