// Recovered UIIndividualDPSDialog (the personal damage meter: shows the local player's value from CBattleRecordManager).
// Unnamed helpers and members use invented names. Sibling of uichaosdpsdialog.h.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/client/ms2/uichaosdpsdialog.h"            // Unk_ChaosTick (the 100 ms poll timer)

class UIIndividualDPSDialog : public UIDialog
{
public:
    UIIndividualDPSDialog();                                                // 0x140f4ab90
    virtual ~UIIndividualDPSDialog();                                       //  0 0x140f4ac30
    virtual CString vfunc_1();                                              //  1 0x140f4ac70
    virtual void OnLoadComplete();                                          // 22 0x140f4afc0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x140f4b070
    virtual int vfunc_48() { return 0x4edf; }                               // 48 0x140f4b2a0
    virtual void vfunc_67();                                                // 67 0x140f4afa0
    virtual void vfunc_72();                                                // 72 0x140f4b1b0

    void OnTextToggle();                                                   // 0x140f4acc0 title bar
    void FUN_140f4ade0();                                                   // 0x140f4ade0 meter text and elapsed time

    int m_unk_178;                                                          // +0x178 (untouched by the ctor)
    Unk_ChaosTick m_tick;                                                   // +0x17c
    int m_nGroup;                                                           // +0x184 battle record group
    int m_nMode;                                                            // +0x188 value kind shown (0..8)
};
MS2_CHECK_SIZE(UIIndividualDPSDialog, 0x190);
MS2_CHECK_OFFSET(UIIndividualDPSDialog, m_tick, 0x17c);
MS2_CHECK_OFFSET(UIIndividualDPSDialog, m_nMode, 0x188);
