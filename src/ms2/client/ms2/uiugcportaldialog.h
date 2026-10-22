// uiugcportaldialog.h - UIUGCPortalDialog (RTTI .?AVUIUGCPortalDialog@@, 0x1b0 bytes, UI id 0x4f1f, swf "UGCPortalDialog"): the
// UGC portal setup dialog. A packet fills the portal id, its title, the trigger and target type, the current target and the
// list of target names; the target drop down is filled by target type (0 = names from the packet, 1 = the UGC maps that are
// remembered, 2 = the friends) and "OnApply" sends the portal (opcode 0x90 / 6). Owning unit: ?\uiugcportaldialog.cpp.
// Header name assumed from the unit path; member names are invented from use.
#pragma once

#include <afx.h>

#include <string>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"

class CInPacket;
class Unk_UgcpCombo;

class UIUGCPortalDialog : public UIDialog
{
public:
    UIUGCPortalDialog();                                        // 0x140fb0190
    virtual ~UIUGCPortalDialog();                               //  0 0x140fb0210 (??_G 0x140fb4360)
    virtual CString vfunc_1();                                  //  1 0x140fb05e0 "UGCPortalDialog"
    virtual void OnLoadComplete();                              // 22 0x140fb0630
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fb07d0
    virtual int vfunc_48() { return 0x4f1f; }                   // 48 0x140fb4410

    void FUN_140fb0290(CInPacket& packet);                      // 0x140fb0290 read the portal from the packet
    void OnApply();                                       // 0x140fb0a70 OnApply: check the name and send
    bool FUN_140fb0da0(CStringW& strName);                      // 0x140fb0da0 name -> string table id, then its text
    void FUN_140fb0e30();                                       // 0x140fb0e30 fill the drop down: names from the packet
    void FUN_140fb1040();                                       // 0x140fb1040 fill the drop down: remembered UGC maps
    void FUN_140fb15a0();                                       // 0x140fb15a0 fill the drop down: friends
    bool FUN_140fb1860(int nType);                              // 0x140fb1860 a map type that has portal targets
    template <class T> MS2Ptr<T> FUN_140c28560(const CString& strName);   // 0x140c28560 bind a child of the movie
    template <class T> MS2Ptr<T> FUN_140e48d80(const CString& strName, MS2Ptr<T>* pOut);   // 0x140e48d80 bind a text child

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                  // +0x178 portal id
    CStringW m_180;                                             // +0x180 title
    int m_188;                                                  // +0x188 trigger
    int m_18c;                                                  // +0x18c target type
    CStringW m_190;                                             // +0x190 current target
    std::vector<std::wstring> m_198;                            // +0x198 target names (sorted)
};
MS2_CHECK_SIZE(UIUGCPortalDialog, 0x1b0);
MS2_CHECK_OFFSET(UIUGCPortalDialog, m_198, 0x198);
