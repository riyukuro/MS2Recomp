// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITriggerTimerDialog / UIFreeForAllTimerDialog: see
// uitriggertimerdialog.h.
// MS2-UNIT: ?\uitriggertimerdialog.cpp
// MS2-RANGE: 0x141b330c0-0x141b33740 .text$mn
// MS2-PIN: ??_GUITriggerTimerDialog@@UEAAPEAXI@Z 0x141b336e0
// MS2-PIN: ??_GUIFreeForAllTimerDialog@@UEAAPEAXI@Z 0x141b336a0
// MS2-PIN: ??1UIFreeForAllTimerDialog@@UEAA@XZ 0x141b33660
// MS2-PIN: ??1UITriggerTimerDialog@@UEAA@XZ 0x141b33680
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitriggertimerdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uitriggertimerdialog.h"

#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};
class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };

// The client configuration singleton; the low-time effect name is the CString at +0x2f0 (as UITimerDialog's).
struct Unk_TriggerTimerCfg { char m_pad_00[0x2f0]; CString m_strEffect; };
Unk_TriggerTimerCfg* FUN_1401d31f0();

WorldService* FUN_1403ed2d0();
CEffectService* FUN_1403ed280();               // the effect service singleton

// @0x141b330c0
UITriggerTimerDialog::UITriggerTimerDialog()
{
    m_2c = 0x13;
    m_80 = 0;
    m_nEffectRunning = 0;
    m_nEffect = 0;
    m_nOffsetY = 0;
    m_nAlign = 1;
    FUN_141925e70(0, 1);
}

// @0x141b33180
CString UITriggerTimerDialog::GetTypeName()
{
    return "TriggerTimerDialog";
}
MS2_REPLACE_METHOD(0x141B33180, UITriggerTimerDialog, GetTypeName, 61, 0xF2CFB665);

// @0x141b331d0
int UITriggerTimerDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141B331D0, UITriggerTimerDialog, vfunc_65, 37, 0x0CAE131F);

// @0x141b33200
void UITriggerTimerDialog::vfunc_72()
{
    int nFlag = 0;
    int nMin = 0;
    int nSec = 0;
    int nUnused = 0;
    FUN_1403ed2d0()->FUN_141bc6fb0(&nMin, &nSec, &nUnused, &nFlag);
    if (nFlag != 0 && nMin == 0 && nSec == 0)
        vfunc_67();
    else
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
        {
            CString strTime;
            strTime.Format("%02d%02d", nMin, nSec);
            pDialog->Invoke("setTime", strTime);
        }
        if (m_nEffectRunning == 0 && nMin == 0 && nSec <= 10)
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = FUN_1401d31f0()->m_strEffect;
            kTarget.m_nKind = 0;
            m_nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
            m_nEffectRunning = 1;
        }
    }
}
MS2_REPLACE_METHOD(0x141B33200, UITriggerTimerDialog, vfunc_72, 489, 0xE432BDCD);

// @0x141b333f0
void UITriggerTimerDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_nEffectRunning = 0;
}
MS2_REPLACE_METHOD(0x141B333F0, UITriggerTimerDialog, OnLoadInit, 39, 0x43D681BD);

// @0x141b33420
void UITriggerTimerDialog::vfunc_67()
{
    if (m_nEffect != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
    UIDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x141B33420, UITriggerTimerDialog, vfunc_67, 77, 0x43A61863);

// @0x141b33480
int UITriggerTimerDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141B33480, UITriggerTimerDialog, vfunc_28, 67, 0xFD047DC9);

// @0x141b334d0
void UITriggerTimerDialog::FUN_141b334d0(int nOffsetY)
{
    m_nOffsetY = nOffsetY;
    vfunc_43();
}
MS2_REPLACE_METHOD(0x141B334D0, UITriggerTimerDialog, FUN_141b334d0, 52, 0xAD6E7DF7);

// @0x141b33510
void UITriggerTimerDialog::FUN_141b33510(int nAlign)
{
    m_nAlign = nAlign;
    vfunc_43();
}
MS2_REPLACE_METHOD(0x141B33510, UITriggerTimerDialog, FUN_141b33510, 52, 0x5ACC961B);

// @0x141b33550
void UITriggerTimerDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(m_nAlign, 0, m_nOffsetY + 0x82);
}
MS2_REPLACE_METHOD(0x141B33550, UITriggerTimerDialog, vfunc_43, 196, 0xB2C808BA);

// @0x141b33620
UIFreeForAllTimerDialog::UIFreeForAllTimerDialog()
{
}

// @0x141b33720
int UIFreeForAllTimerDialog::vfunc_48()
{
    return 0x4e99;
}
MS2_REPLACE_METHOD(0x141B33720, UIFreeForAllTimerDialog, vfunc_48, 11, 0x94D03812);

// @0x141b33730
int UITriggerTimerDialog::vfunc_48()
{
    return 0x4e95;
}
MS2_REPLACE_METHOD(0x141B33730, UITriggerTimerDialog, vfunc_48, 11, 0xF8CF8D7E);
