// uiweddinghalllistdialog.h - UIWeddingHallListDialog (RTTI .?AVUIWeddingHallListDialog@@, UI id 0x4f96, swf
// "WeddingHallListDialog"): the list of wedding halls the character has booked. It fills two lists ("m_openList" for
// weddings that have not started yet, "m_progressList" for the others) from the character's wedding hall ticket map
// and enters a wedding when the movie sends "onEnter" with the wedding serial number. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); unit `?\uiweddinghalllistdialog.cpp` (0x140fd8df0-0x140fdab30, dir
// client\ms2). Header name assumed from the unit path; names are invented (vfunc_N are vftable slots).
#pragma once

#include <afx.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/weddinghallticket.h"

class Unk_WhList;

class UIWeddingHallListDialog : public UIDialog
{
public:
    UIWeddingHallListDialog();                                  // 0x140fd8df0
    virtual ~UIWeddingHallListDialog();                         //  0 0x140fd8e80 (??_G 0x140fd9c50)
    virtual CString GetTypeName();                                  //  1 0x140fd8ec0 "WeddingHallListDialog"
    virtual void OnLoadComplete();                              // 22 0x140fd8fa0 refresh the lists
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140fd8fd0 onEnter
    virtual int vfunc_48() { return 0x4f96; }                   // 48 0x140fd9c90
    virtual int vfunc_65();                                     // 65 0x140fd8f10
    virtual void vfunc_67();                                    // 67 0x140fd8f30
    virtual void vfunc_72();                                    // 72 0x140fd8f50 refresh once when marked

    void FUN_140fd90f0(bool b);                                    // 0x140fd90f0 mark the lists for a refresh
    void FUN_140fd9110();                                       // 0x140fd9110 fill the open and the progress list
    MS2Ptr<Unk_WhList> FUN_140c02900(const CString& strName);   // bind a list child

private:
    MS2_LAYOUT_FRIEND;
    unsigned char m_bRefresh;                                   // +0x178
};
MS2_CHECK_OFFSET(UIWeddingHallListDialog, m_bRefresh, 0x178);
MS2_CHECK_SIZE(UIWeddingHallListDialog, 0x180);
