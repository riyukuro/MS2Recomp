// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiitemdropsimulatordialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIItemDropSimulatorDialog is the item drop simulator window ("ItemDropSimulatorDialog", UI type 0x4e37): the movie
// reports "onClickDropButton" / "onClickCustomDrop" with the simulation settings, and the result text goes to the
// "m_simulateResult" text field. RTTI .?AVUIItemDropSimulatorDialog@@, 0x178 bytes (a plain UIDialog: no members),
// vftables at +0 and +0x18 (IMessageListener). m_40 (UISwfEntity) is set to 1 by the ctor.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASTextField;

class UIItemDropSimulatorDialog : public UIDialog
{
public:
    UIItemDropSimulatorDialog();                                // 0x14192a2e0
    virtual CString GetTypeName();                                  //  1 0x14192a330
    virtual void OnLoadInit();                                  // 20 0x14192a380
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x14192a3b0
    virtual int vfunc_48();                                     // 48 0x14192ab00
    // The destructor is implicit (0x14192aaa0: just ~UIDialog), ??_G 0x14192aac0.

    // The simulation itself was stripped from the exe: both entry points only destroy their by-value strings.
    void FUN_14192a900(int nA, CString strA, int nB, int nC, int nD, int nE, int nF, int nG, int nH, int nI, int nJ,
                       bool bFlag, CString strB);               // 0x14192a900 drop with the preset settings
    void FUN_14192a940(CString strA, CString strB, int nA, int nB, int nC, int nD, int nE, int nF, int nG, int nH,
                       int nI);                                 // 0x14192a940 custom drop
    void FUN_14192a9a0(CStringW strText);                       // 0x14192a9a0 show the result text
    CStringW* FUN_14192aa50(CStringW* pOut, unsigned int nId, void* pArg);  // 0x14192aa50 localized word

    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)
};
MS2_CHECK_SIZE(UIItemDropSimulatorDialog, 0x178);
