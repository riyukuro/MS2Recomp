// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIAutoReviveCountDownDialog (class name
// "AutoReviveCountDownDialog", UI type id 0x4ea2, 0x180 bytes) is the auto-revive countdown: FUN_141284d70 arms it
// with a duration (deadline = GetTickCountMs2() + duration, remaining = duration/1000 + 1), its per-frame vfunc_72
// then sends the remaining whole seconds to the swf ("setTime") whenever they change and closes the dialog
// (vfunc_67) once the deadline has passed.
// MS2-UNIT: ?\uiautorevivecountdowndialog.cpp
// MS2-RANGE: 0x141284ac0-0x141284e00 .text$mn
// MS2-PIN: ??_GUIAutoReviveCountDownDialog@@UEAAPEAXI@Z 0x141284db0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiautorevivecountdowndialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiautorevivecountdowndialog.h"

#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x141284ac0
UIAutoReviveCountDownDialog::UIAutoReviveCountDownDialog()
{
    FUN_141925e70(1, 1);
}

// @0x141284b30
UIAutoReviveCountDownDialog::~UIAutoReviveCountDownDialog()
{
}

// The countdown: no movie root yet, nothing to do; the deadline has passed, close; otherwise send the remaining
// whole seconds (which is also the initial value FUN_141284d70 computed) to the swf when it changed.
// @0x141284b70
void UIAutoReviveCountDownDialog::vfunc_72()
{
    if (m_30.IsNull())
        return;
    unsigned int nNow = GetTickCountMs2();
    if (m_nEndTime < nNow)
    {
        vfunc_67();
        return;
    }
    unsigned int nRemain = (m_nEndTime - nNow) / 1000 + 1;
    if (nRemain != m_nRemainSec)
    {
        m_nRemainSec = nRemain;
        m_30.operator->()->Invoke("setTime", m_nRemainSec);
    }
}

// Line the movie root's game-entity clip up (the dialog is placed by the AS side).
// @0x141284c50
void UIAutoReviveCountDownDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(0, 0, 0x118);
}

// @0x141284d00
CString UIAutoReviveCountDownDialog::GetTypeName()
{
    return "AutoReviveCountDownDialog";
}

// @0x141284d50
void UIAutoReviveCountDownDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// Arm the countdown with a duration in milliseconds; the swf is told the whole seconds right away (the extra second
// is the one the deadline is still in).
// @0x141284d70
void UIAutoReviveCountDownDialog::FUN_141284d70(int nDuration)
{
    m_nEndTime = GetTickCountMs2() + nDuration;
    m_nRemainSec = (unsigned int)nDuration / 1000 + 1;
}

// @0x141284df0
int UIAutoReviveCountDownDialog::vfunc_48()
{
    return 0x4ea2;
}
