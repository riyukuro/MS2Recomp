// UIHomeSaveSlotDialog: the six save/load slots of the home (and blueprint) designer, with the confirmation message boxes
// and the packets (type 0x37) the buttons send. Recovered from MapleStory2.exe KMS2_DEV x64. Not an original header (the
// source file is unnamed: the exe has no __FILE__ string for it); member names are invented, FUN_<va> names follow the exe.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class CMsgBoxData;

// Slot 0..5 of the dialog. m_saveMode (+0x178): 1 = save, 0 = load (the movie's "saveMode").
class UIHomeSaveSlotDialog : public UIDialog {
public:
    UIHomeSaveSlotDialog();                                                             // 0x140fa9eb0
    virtual ~UIHomeSaveSlotDialog();                                                    // 0 0x140fa9f20 (??_G 0x140fac750)
    virtual CString vfunc_1();                                                          // 1 "HomeSaveSlotDialog"
    virtual void OnLoadComplete();                                                      // 22 0x140fa9fb0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140faa070 "OnSaveSlot" / "OnLoadSlot"
    virtual int vfunc_48();                                                             // 48 0x140fac7b0 UI type id
    virtual void vfunc_79(void* p);                                                     // 79 0x140faa010

    void FUN_140faa2d0();                                                               // fill the five slot entries ("setSlot")
    void FUN_140faa6d0();                                                               // save mode
    void FUN_140faa750();                                                               // load mode
    bool FUN_140faa7d0(int nResult, const CMsgBoxData& data);                           // overwrite confirmed / name entered: send save
    bool FUN_140faac30(int nResult, const CMsgBoxData& data);                           // load confirmed: send load
    bool SendRequestCubeMode46(int nResult, const CMsgBoxData& data);                           // overwrite confirmed: send save
    bool FUN_140faaeb0(int nResult, const CMsgBoxData& data);                           // blueprint: name entered, send save
    bool SendRequestCubeMode65(int nResult, const CMsgBoxData& data);                           // blueprint: load confirmed
    bool SendRequestCubeMode64(int nResult, const CMsgBoxData& data);                           // blueprint: overwrite confirmed
    void FUN_140fab520(int nSlot);                                                      // ask for a name to save the slot
    void FUN_140fab8c0(int nSlot);                                                      // ask to load the slot
    void FUN_140fabae0(int nSlot);                                                      // blueprint: ask for a name to save the slot
    void FUN_140fabe80(int nSlot);                                                      // blueprint: ask to load the slot

private:
    MS2_LAYOUT_FRIEND;
    int m_saveMode;                                                                     // +0x178
};
MS2_CHECK_SIZE(UIHomeSaveSlotDialog, 0x180);
MS2_CHECK_OFFSET(UIHomeSaveSlotDialog, m_saveMode, 0x178);
