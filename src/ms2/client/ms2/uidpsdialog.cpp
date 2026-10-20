// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDPSDialog: the damage-per-second meter window.
// MS2-UNIT: ?\uidpsdialog.cpp
// MS2-RANGE: 0x141928c80-0x14192a2e0 .text$mn
// MS2-PIN: ??1UIDPSDialog@@UEAA@XZ 0x14192a180
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidpsdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uidpsdialog.h"
#include "toolbasedialog.h"
#include "pcbase.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
public:
    Scaleform::GFx::Value FUN_14192a060(const char* szMethod, CString strTime, __int64 nDamage, CString strDps);   // 0x14192a060 setAttr
};

class Unk_DpsApp { public: HWND FUN_14209c720(); };                     // the application window holder
Unk_DpsApp* FUN_140aadf80();

class Unk_DpsKeys { public: bool FUN_14116d9c0(int nKey, int a, int b); bool FUN_14116d950(int nKey, int a, int b); };
Unk_DpsKeys* FUN_14025e7c0();

// The DPS meter system (dpsmetersystem.cpp): records the measurement window.
class Unk_DpsMeter
{
public:
    void FUN_14117c650(unsigned nStart);                                // measurement started
    void FUN_14117c7c0(unsigned nTime);                                 // measurement ended
    void FUN_14117c920();                                               // reset the history
    void FUN_14117ea90(unsigned nTime, int a);                          // sample
};
Unk_DpsMeter* FUN_14109a6f0();

// The tool dialog CDPSDialog (TSingleton<CDPSDialog>, a CToolBaseDialog; 0x350 bytes).
extern CToolBaseDialog* DAT_143ad0d98;                                  // TSingleton<CDPSDialog>::s_instance
void FUN_141178870(CToolBaseDialog* pDialog);                           // refresh
void FUN_1411789e0(CToolBaseDialog* pDialog, unsigned nTime);           // end time
void* FUN_140c7fa70(size_t cb);                                         // MFC allocation
CToolBaseDialog* FUN_141178390(void* mem, CWnd* pParent);               // CDPSDialog ctor

class Unk_DpsWorld;
Unk_DpsWorld* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(Unk_DpsWorld* pWorld);                            // the local player
class Unk_DpsActorState { public: void FUN_14063e530(); bool FUN_14063e9f0(int n); void* m_p; };
class Unk_DpsActorStateHolder { public: Unk_DpsActorState FUN_140639bb0(); };
Unk_DpsActorStateHolder* FUN_1416546d0(PCBase* pPC);
int FUN_141654730(PCBase* pPC);                                         // job code
class Unk_DpsStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_DpsStrings* FUN_1401a9d70();

unsigned FUN_140869420();                                               // tick
void FUN_141b70720(unsigned nMs, CString& strOut);                      // "mm:ss" text
void FUN_140710590(COutPacket& packet);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);      // Value::SetString
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);           // Value::SetNumber

CToolBaseDialog* FUN_14192a1e0();                                       // TSingleton<CDPSDialog>::CreateInstance
void FUN_14192a260();                                                   // DestroyInstance
CToolBaseDialog* FUN_14192a2c0();                                       // GetInstance

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
CString UIDPSDialog::vfunc_1()
{
    return "DPSDialog";
}

// @0x141928da0
int UIDPSDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    if (FUN_14192a2c0() == 0)
        FUN_14192a260();
    FUN_14192a1e0();
    CToolBaseDialog* pTool = FUN_14192a2c0();
    pTool->Create(0x91, CWnd::FromHandle(FUN_140aadf80()->FUN_14209c720()));
    COutPacket packet(0x56, 0);
    packet.vfunc_o10_1(1);
    FUN_140710590(packet);
    return 1;
}

// @0x141928e80
void UIDPSDialog::vfunc_67()
{
    FUN_14109a6f0()->FUN_14117c7c0(FUN_140869420());
    if (FUN_14192a2c0() != 0)
        FUN_14192a260();
    COutPacket packet(0x56, 0);
    packet.vfunc_o10_1(0);
    FUN_140710590(packet);
    FUN_141929700();
    UIDialog::vfunc_67();
}

// @0x141928f20
void UIDPSDialog::vfunc_72()
{
    if (FUN_14192a2c0() != 0)
        FUN_141178870(FUN_14192a2c0());
    if (m_17c != 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
        {
            unsigned nNow = FUN_140869420();
            if (nNow < m_180)
            {
                CString strTime;
                FUN_141b70720(m_180 - nNow, strTime);
                pDialog->Invoke("setTime", CString(strTime));
            }
            else
            {
                unsigned nElapsed = nNow - m_180;
                CString strTime;
                FUN_141b70720(nElapsed, strTime);
                double dSeconds = (double)nElapsed / 1000.0;
                if (m_184 == 0 || nNow <= m_184)
                {
                    if (m_178 == 0)
                    {
                        m_178 = 1;
                        FUN_14109a6f0()->FUN_14117c650(m_180);
                    }
                    if (dSeconds <= 0.0)
                    {
                        pDialog->Invoke("setTime", CString(strTime));
                    }
                    else
                    {
                        double dDps = (double)m_188 / dSeconds;
                        CString strDps;
                        strDps.Format("%.2f", dDps);
                        pDialog->FUN_14192a060("setAttr", CString(strTime), m_188, CString(strDps));
                        FUN_14109a6f0()->FUN_14117ea90(nNow, 0);
                    }
                }
                else
                {
                    double dDuration = (double)(unsigned)(m_184 - m_180) / 1000.0;
                    double dDps = (double)m_188 / dDuration;
                    CString strDps;
                    strDps.Format("%.2f", dDps);
                    pDialog->FUN_14192a060("setAttr", CString(strTime), m_188, CString(strDps));
                    if (FUN_14192a2c0() != 0)
                        FUN_1411789e0(FUN_14192a2c0(), m_184);
                    FUN_14109a6f0()->FUN_14117c7c0(m_184);
                    pDialog->Invoke("onStop");
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nDelay = atoi(data.FUN_1422b8d30());
            int nDuration = atoi(data.FUN_1422b8d30());
            FUN_141929a60(nDelay, nDuration);
        }
        return 1;
    }
    else if (_stricmp("OnStop", szMethod) == 0)
    {
        FUN_141929b00();
        return 1;
    }
    else if (_stricmp("OnResetHistory", szMethod) == 0)
    {
        FUN_14109a6f0()->FUN_14117c920();
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
        if (FUN_14025e7c0()->FUN_14116d9c0(0x39, 0, 0))
        {
            if (FUN_14025e7c0()->FUN_14116d950(0x1d, 0, 0))
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
// MS2-FUNCTIONAL: the exe frame is 0x108 (extra temps around the nested pPC/dialog tests); not matched in two attempts
void UIDPSDialog::FUN_141929760()
{
    if (m_178 == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPC == 0)
        return;
    Unk_DpsActorState state = FUN_1416546d0(pPC)->FUN_140639bb0();
    bool bOn = state.FUN_14063e9f0(0);
    state.FUN_14063e530();
    if (bOn == 0)
    {
        double dSeconds = (double)(unsigned)(FUN_140869420() - m_180) / 1000.0;
        double dDps = (double)m_188 / dSeconds;
        CStringW strLine = StringFormat(L"Lv.{0} {1}, {2:.2f}Second, total: {3}, {4:.2f} damage/sec\n",
                                        (unsigned short)pPC->vfunc_78(),
                                        (const wchar_t*)FUN_1401a9d70()->FUN_141811980(6, FUN_141654730(pPC)),
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
    m_180 = FUN_140869420();
    m_180 = nDelay * 1000 + m_180;
    unsigned nEnd;
    if (nDuration > 0)
        nEnd = nDuration * 1000 + m_180;
    else
        nEnd = 0;
    m_184 = nEnd;
}

// @0x141929b00
void UIDPSDialog::FUN_141929b00()
{
    if (FUN_14192a2c0() != 0)
        FUN_1411789e0(FUN_14192a2c0(), FUN_140869420());
    FUN_14109a6f0()->FUN_14117c7c0(FUN_140869420());
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

// MS2-FUNCTIONAL: the exe's `new CDPSDialog` is a new-expression with an EH frame; the ctor is an opaque FUN_ here
// @0x14192a1e0
CToolBaseDialog* FUN_14192a1e0()
{
    if (DAT_143ad0d98 == 0)
    {
        void* mem = FUN_140c7fa70(0x350);
        return mem ? FUN_141178390(mem, 0) : 0;
    }
    return FUN_14192a2c0();
}

// @0x14192a260
void FUN_14192a260()
{
    if (DAT_143ad0d98 != 0)
    {
        delete FUN_14192a2c0();
        DAT_143ad0d98 = 0;
    }
}

// @0x14192a2c0
CToolBaseDialog* FUN_14192a2c0()
{
    return DAT_143ad0d98;
}

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x140112b40-0x140112cb0 .text$di
// MS2-RANGE: 0x142cbdca0-0x142cbdd30 .text$yd
#include "ms2/placeholder/header_statics_a.h"
