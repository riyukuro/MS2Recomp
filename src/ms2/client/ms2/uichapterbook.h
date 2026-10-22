// uichapterbook.h - UIChapterBook (RTTI .?AVUIChapterBook@@, 0x78 bytes, UIHeadUpDisplay + IMessageListener, UI id 0x4f37,
// swf "ChapterBook"): the HUD page that shows a chapter book's prologue or epilogue with its rewards. The chapter ids are set
// by FUN_140e0a850 (prologue) / FUN_140e0a890 (epilogue), each of which shows the page. On "onHide" the rewards of the
// epilogue are handed to the reward notify.
// Owning unit: ?\uichapterbook.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/ascript.h"

class UIChapterBook : public UIHeadUpDisplay
{
public:
    UIChapterBook();                                            // 0x140e09a90
    virtual ~UIChapterBook();                                   //  0 0x140e09b00 (??_G 0x140e0a9b0)
    virtual CString GetTypeName();                                  //  1 0x140e09b40 "ChapterBook"
    virtual void vfunc_2();                                     //  2 0x140e0a7d0 show
    virtual void vfunc_3();                                     //  3 0x140e0a800 hide: forget the chapters
    virtual void OnLoadComplete();                              // 22 0x140e09b90 "setPrologue" / "setEpilogue"
    virtual void vfunc_26();                                    // 26 0x140e0a3b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140e0a3d0 onHide
    virtual void vfunc_43();                                    // 43 0x140e0a770 "alignment"
    virtual int vfunc_48() { return 0x4f37; }                   // 48 0x140e0aa00

    void FUN_140e0a850(int nPrologue);                          // show the prologue of a chapter
    void FUN_140e0a890(int nEpilogue);                          // show the epilogue of a chapter

private:
    MS2_LAYOUT_FRIEND;
    int m_nPrologue;                                            // +0x70
    int m_nEpilogue;                                            // +0x74
};
MS2_CHECK_SIZE(UIChapterBook, 0x78);
MS2_CHECK_OFFSET(UIChapterBook, m_nPrologue, 0x70);
MS2_CHECK_OFFSET(UIChapterBook, m_nEpilogue, 0x74);
