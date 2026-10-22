// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiitemenchantsimulatedialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIItemEnchantSimulateDialog is the enchant simulator window ("ItemEnchantSimulateDialog", UI type 0x4e9c): "OnSelect"
// and "OnEnchant" send the simulation requests (packet 0x5e, sub-ops 0xd / 0xe) and vfunc_79 shows the replies (opcode
// 0x97: the result counters in m_tfSuccess / m_tfReset / m_tfReturn / m_tfIngredient, or the summary in m_result).
// RTTI .?AVUIItemEnchantSimulateDialog@@, 0x178 bytes (a plain UIDialog: no members), vftables at +0 and +0x18
// (IMessageListener). m_40 (UISwfEntity) is set to 1 by the ctor.
// Names: virtuals are Ghidra's vfunc_<slot>.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASTextField;

class UIItemEnchantSimulateDialog : public UIDialog
{
public:
    UIItemEnchantSimulateDialog();                              // 0x1412d1400
    virtual CString GetTypeName();                                  //  1 0x1412d1450
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1412d14a0
    virtual void vfunc_79(void* p);                             // 79 0x1412d19a0 (CInPacket*)
    virtual int vfunc_48();                                     // 48 0x1412d2530
    // The destructor is implicit (0x1412d24d0: just ~UIDialog), ??_G 0x1412d24f0.

    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)
};
MS2_CHECK_SIZE(UIItemEnchantSimulateDialog, 0x178);
