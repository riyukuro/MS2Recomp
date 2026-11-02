// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDPSDialog: the damage-per-second meter window.
// MS2-UNIT: ?\uidpsdialog.cpp
// MS2-RANGE: 0x141928c80-0x14192a2e0 .text$mn
// MS2-PIN: ??1UIDPSDialog@@UEAA@XZ 0x14192a180
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidpsdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uidpsdialog.h"
#include "toolbasedialog.h"
#include "dpsmetersystem.h"
#include "pcbase.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/dpsmetersystem.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/commonfiles/jobsystem.h"
#include "ms2/placeholder/cinputkeyhandler.h"  // C3: CInputKeyHandler::FUN_14116d9c0
#include <stdlib.h>
#include <efd/Win32/Win32PlatformService.h>  // C3: efd::Win32PlatformService::GetWindowRef

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_14192a060(const char* szMethod, CString strTime, __int64 nDamage, CString strDps);   // 0x14192a060 setAttr
};

void* FUN_140aadf80();   // C3: was FUN_140aadf80

class Unk_DpsKeys : public CInputKeyHandler {};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0


// The tool dialog CDPSDialog (TSingleton<CDPSDialog>, a CToolBaseDialog; 0x350 bytes).

class Unk_DpsWorld;
// An MS2Ptr (16 bytes, m_p at +8): FUN_140639bb0 returns it through a hidden pointer, the dtor 0x14063e530 writes 16.

unsigned long GetTickCountMs2();   // C3: was FUN_140869420
void FUN_141b70720(unsigned nMs, CString& strOut);                      // "mm:ss" text
void FUN_140710590(COutPacket& packet);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);      // Value::SetString
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);           // Value::SetNumber

CToolBaseDialog* FUN_14192a1e0();                                       // TSingleton<CDPSDialog>::CreateInstance
void FUN_14192a260();                                                   // DestroyInstance
CToolBaseDialog* GetToolBaseDialog();                                       // GetInstance

// @0x141928c80
UIDPSDialog::UIDPSDialog()
{
    m_178 = 0;
    m_17c = 0;
    m_180 = 0;
    m_184 = 0;
    m_188 = 0;
    m_40 = 1;
    FUN_141925e70(2, 1);
    FUN_141925e70(1, 1);
}

// @0x141928d50
CString UIDPSDialog::GetTypeName()
{
    return "DPSDialog";
}

// @0x141928da0
int UIDPSDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    if (GetToolBaseDialog() == 0)
        FUN_14192a260();
    FUN_14192a1e0();
    CToolBaseDialog* pTool = GetToolBaseDialog();
    pTool->Create(0x91, CWnd::FromHandle(((efd::Win32PlatformService*)FUN_140aadf80())->GetWindowRef()));
    COutPacket packet(static_cast<int>(SendOp::DpsMode), 0);
    packet.WriteUInt8(1);
    FUN_140710590(packet);
    return 1;
}

// @0x141928e80
void UIDPSDialog::vfunc_67()
{
    TSingleton<CDPSMeterSystem>::GetInstance()->StopRecord(GetTickCountMs2());
    if (GetToolBaseDialog() != 0)
        FUN_14192a260();
    COutPacket packet(static_cast<int>(SendOp::DpsMode), 0);
    packet.WriteUInt8(0);
    FUN_140710590(packet);
    FUN_141929700();
    UIDialog::vfunc_67();
}

// @0x141928f20
void UIDPSDialog::vfunc_72()
{
    if (GetToolBaseDialog() != 0)
        ((class CDPSDialog*)(class CToolBaseDialog*)(GetToolBaseDialog()))->Refresh();
    if (m_17c != 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
        {
            unsigned nNow = GetTickCountMs2();
            unsigned nElapsed = 0;
            if (nNow < m_180)
            {
                nElapsed = m_180 - nNow;
                CString strTime;
                FUN_141b70720(m_180 - nNow, strTime);
                pDialog->Invoke("setTime", CString(strTime));
            }
            else
            {
                nElapsed = nNow - m_180;
                CString strTime;
                FUN_141b70720(nElapsed, strTime);
                double dSeconds = (double)nElapsed / 1000.0;
                if (m_184 != 0 && nNow > m_184)
                {
                    dSeconds = (double)(unsigned)(m_184 - m_180) / 1000.0;
                    double dDps = (double)m_188 / dSeconds;
                    CString strDps;
                    strDps.Format("%.2f", dDps);
                    pDialog->FUN_14192a060("setAttr", CString(strTime), m_188, CString(strDps));
                    if (GetToolBaseDialog() != 0)
                        ((class CDPSDialog*)(class CToolBaseDialog*)(GetToolBaseDialog()))->OnStop(m_184);
                    TSingleton<CDPSMeterSystem>::GetInstance()->StopRecord(m_184);
                    pDialog->Invoke("onStop");
                    return;
                }
                if (m_178 == 0)
                {
                    m_178 = 1;
                    TSingleton<CDPSMeterSystem>::GetInstance()->StartRecord(m_180);
                }
                if (dSeconds > 0.0)
                {
                    double dDps = (double)m_188 / dSeconds;
                    CString strDps;
                    strDps.Format("%.2f", dDps);
                    pDialog->FUN_14192a060("setAttr", CString(strTime), m_188, CString(strDps));
                    TSingleton<CDPSMeterSystem>::GetInstance()->FUN_14117ea90(nNow, 0);
                }
                else
                {
                    pDialog->Invoke("setTime", CString(strTime));
                }
            }
        }
    }
}

// @0x141929490
int UIDPSDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnStart", szMethod) == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nDelay = atoi(data.FUN_1422b8d30());
            int nDuration = atoi(data.FUN_1422b8d30());
            FUN_141929a60(nDelay, nDuration);
        }
        return 1;
    }
    else if (_stricmp("OnStop", szMethod) == 0)
    {
        OnStop();
        return 1;
    }
    else if (_stricmp("OnResetHistory", szMethod) == 0)
    {
        TSingleton<CDPSMeterSystem>::GetInstance()->Reset();
        return 1;
    }
    return 0;
}

// @0x141929640
int UIDPSDialog::vfunc_13()
{
    if (vfunc_55() == 0)
    {
        if (UIDialog::vfunc_13() != 0)
            return 1;
        if (((class Unk_DpsKeys*)FUN_14025e7c0())->FUN_14116d9c0(0x39, 0, 0))
        {
            if (((class Unk_DpsKeys*)FUN_14025e7c0())->FUN_14116d950(0x1d, 0, 0))
                FUN_141929b70(m_17c == 0);
        }
    }
    return 0;
}

// @0x141929700
void UIDPSDialog::FUN_141929700()
{
    m_178 = 0;
    m_17c = 0;
    m_180 = 0;
    m_188 = 0;
    m_184 = 0;
}

// @0x141929760
void UIDPSDialog::FUN_141929760()
{
    if (m_178 == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        PCBase* pPC = ((class PCBase*)((class WorldService*)(class Unk_DpsWorld*)(reinterpret_cast<Unk_DpsWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
        if (pPC == 0)
            return;
        if (reinterpret_cast<JobSystem*>(reinterpret_cast<PC*>(pPC)->FUN_1416546d0())->GetJobData().operator==((JobData*)0))
            return;
        double dSeconds = (unsigned)(GetTickCountMs2() - m_180);
        dSeconds /= 1000.0;
        double dDps = (double)m_188 / dSeconds;
        CStringW strLine = StringFormat(L"Lv.{0} {1}, {2:.2f}Second, total: {3}, {4:.2f} damage/sec\n",
                                        (unsigned short)pPC->vfunc_78(),
                                        (const wchar_t*)TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, reinterpret_cast<PC*>(pPC)->FUN_141654730()),
                                        dSeconds, m_188, dDps);
        pDialog->Invoke("history", strLine);
    }
}

// @0x1419299e0
int UIDPSDialog::FUN_1419299e0()
{
    return m_178;
}

// @0x141929a00
void UIDPSDialog::FUN_141929a00(__int64 nDamage, int nType)
{
    if (m_178 == 0)
        return;
    if (nType == 0 || nType == 1)
        m_188 += nDamage;
}

// @0x141929a60
void UIDPSDialog::FUN_141929a60(int nDelay, int nDuration)
{
    m_17c = 1;
    m_180 = GetTickCountMs2();
    m_180 = nDelay * 1000 + m_180;
    unsigned nEnd;
    if (nDuration > 0)
        nEnd = nDuration * 1000 + m_180;
    else
        nEnd = 0;
    m_184 = nEnd;
}

// @0x141929b00
void UIDPSDialog::OnStop()
{
    if (GetToolBaseDialog() != 0)
        ((class CDPSDialog*)(class CToolBaseDialog*)(GetToolBaseDialog()))->OnStop(GetTickCountMs2());
    TSingleton<CDPSMeterSystem>::GetInstance()->StopRecord(GetTickCountMs2());
    FUN_141929760();
    FUN_141929700();
}

// @0x141929b70
void UIDPSDialog::FUN_141929b70(int bStart)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        CString strMethod = "";
        if (bStart != 0)
            strMethod = "onStart";
        else
            strMethod = "onStop";
        pDialog->Invoke(strMethod);
    }
}

// @0x14192a060
Scaleform::GFx::Value ASDialog::FUN_14192a060(const char* szMethod, CString strTime, __int64 nDamage, CString strDps)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), strTime);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), nDamage);
    FUN_1422bce70(args.FUN_1409b1f70(2), strDps);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14192a1e0
CToolBaseDialog* FUN_14192a1e0()
{
    CToolBaseDialog* pDialog;
    if (TSingleton<CDPSDialog>::s_instance != 0)
        pDialog = GetToolBaseDialog();
    else
        pDialog = new CDPSDialog();
    return pDialog;
}

// @0x14192a260
void FUN_14192a260()
{
    if (TSingleton<CDPSDialog>::s_instance != 0)
    {
        delete GetToolBaseDialog();
        TSingleton<CDPSDialog>::s_instance = 0;
    }
}

// @0x14192a2c0
CToolBaseDialog* GetToolBaseDialog()
{
    return TSingleton<CDPSDialog>::s_instance;
}

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x140112b40-0x140112cb0 .text$di
// MS2-RANGE: 0x142cbdca0-0x142cbdd30 .text$yd
#include "ms2/placeholder/header_statics_a.h"
