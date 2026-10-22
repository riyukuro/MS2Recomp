// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITimerDialog: the countdown timer dialog.
// MS2-UNIT: ?\uitimerdialog.cpp
// MS2-RANGE: 0x141b265f0-0x141b26de0 .text$mn
// MS2-PIN: ??_GUITimerDialog@@UEAAPEAXI@Z 0x141b26d90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitimerdialog.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "uitimerdialog.h"

#include "ms2/client/ms2/effectservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types ----

// The client configuration singleton; the timer's low-time effect name is the CString at +0x2f0.
struct Unk_TimerCfg { char m_pad_00[0x2f0]; CString m_strEffect; };
Unk_TimerCfg* FUN_1401d31f0();

CEffectService* FUN_1403ed280();               // the effect service singleton

bool FUN_140a467d0(const MS2Ptr<AScript>* p);  // MS2Ptr<AScript>::IsNull / operator!

// @0x141b265f0
UITimerDialog::UITimerDialog()
{
    m_2c = 19;
    m_80 = 0;
    m_nEffectRunning = 0;
    m_nEffect = 0;
    m_nMin = 0;
    m_nSec = 0;
    m_bReset = false;
    FUN_141925e70(0, 1);
}

// @0x141b266d0
UITimerDialog::~UITimerDialog()
{
    FUN_141b26bf0();
}

// @0x141b26730
CString UITimerDialog::GetTypeName()
{
    return "TimerDialog";
}
MS2_REPLACE_METHOD(0x141B26730, UITimerDialog, GetTypeName, 61, 0x9C98EE2E);

// @0x141b26780
void UITimerDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_tick.FUN_140268870(100) == 0)
        return;
    int nMin = 0;
    int nSec = 0;
    if (!FUN_141b26c50(nMin, nSec))
        return;
    if (m_30.get() != 0 && (m_nMin != nMin || m_nSec != nSec)) {
        CString str;
        str.Format("%02d%02d", nMin, nSec);
        if (m_bReset != 0) {
            m_30->Invoke("resetTime", str);
            m_bReset = false;
        } else {
            m_30->Invoke("setTime", str);
        }
    }
    if (m_nEffectRunning == 0 && nMin == 0 && nSec <= 10) {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = FUN_1401d31f0()->m_strEffect;
        kTarget.m_nKind = 0;
        m_nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
        m_nEffectRunning = 1;
    } else if (m_nEffectRunning != 0 && (nMin > 0 || nSec > 10)) {
        FUN_141b26bf0();
    }
    m_nMin = nMin;
    m_nSec = nSec;
}
MS2_REPLACE_METHOD(0x141B26780, UITimerDialog, vfunc_72, 730, 0x32F5FC3D);

// @0x141b26a60
void UITimerDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}
MS2_REPLACE_METHOD(0x141B26A60, UITimerDialog, OnLoadComplete, 24, 0xCE72123F);

// @0x141b26a80
void UITimerDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_141b26bf0();
    m_nMin = 0;
    m_nSec = 0;
    m_bReset = false;
}
MS2_REPLACE_METHOD(0x141B26A80, UITimerDialog, vfunc_26, 76, 0x5696442D);

// @0x141b26ae0
void UITimerDialog::vfunc_84(unsigned int start, unsigned int duration, int offset)
{
    UITimerBase::vfunc_84(start, duration, offset);
    m_bReset = true;
}
MS2_REPLACE_METHOD(0x141B26AE0, UITimerDialog, vfunc_84, 64, 0xEC104942);

// @0x141b26b30
void UITimerDialog::vfunc_85()
{
    if (FUN_140a467d0(&m_30))
        return;
    m_30->Invoke("showIncreaseEffect");
}
MS2_REPLACE_METHOD(0x141B26B30, UITimerDialog, vfunc_85, 87, 0x169FA0D2);

// @0x141b26b90
void UITimerDialog::vfunc_86()
{
    if (FUN_140a467d0(&m_30))
        return;
    m_30->Invoke("showDecreaseEffect");
}
MS2_REPLACE_METHOD(0x141B26B90, UITimerDialog, vfunc_86, 87, 0x0987DDCB);

// @0x141b26bf0
void UITimerDialog::FUN_141b26bf0()
{
    if (m_nEffect > 0) {
        FUN_1403ed280()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
        m_nEffectRunning = 0;
    }
}
MS2_REPLACE_METHOD(0x141B26BF0, UITimerDialog, FUN_141b26bf0, 82, 0x02F74680);

// @0x141b26c50
bool UITimerDialog::FUN_141b26c50(int& nMin, int& nSec)
{
    nMin = 0;
    nSec = 0;
    if (m_duration == 0)
        return false;
    unsigned int now = FUN_140edeba0();
    if (now == 0)
        return false;
    if (m_start > now) {
        nMin = m_duration / 1000 / 60;
        nSec = m_duration / 1000 % 60;
        return true;
    }
    unsigned int elapsed = now - m_start;
    if (elapsed >= m_duration)
        return true;
    unsigned int remain = m_duration - elapsed;
    nMin = remain / 1000 / 60;
    nSec = remain / 1000 % 60;
    return true;
}
MS2_REPLACE_METHOD(0x141B26C50, UITimerDialog, FUN_141b26c50, 317, 0x151F8164);

// @0x141b26dd0
int UITimerDialog::vfunc_48()
{
    return 20026;
}
MS2_REPLACE_METHOD(0x141B26DD0, UITimerDialog, vfunc_48, 11, 0xBD5926F3);

MS2_EMIT_CRT_MEMMOVE_S();
