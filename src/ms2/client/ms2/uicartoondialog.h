// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicartoondialog.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UICartoonDialog is the story book / sketch book viewer (UI type 0x4e87, "CartoonDialog"): it shows the pages of one
// CStoryBookData (storybooktable.h) two at a time (one for types 2 and 4) and handles the page keys. RTTI
// .?AVUICartoonDialog@@, 0x180 bytes, vftables at +0 and +0x18 (IMessageListener). The server starts it with packet
// 0x88 (the book id).
// Names: virtuals are Ghidra's vfunc_<slot>; members are invented from their use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CInPacket;
class ASObj;
class Unk_CtButton;

class UICartoonDialog : public UIDialog
{
public:
    UICartoonDialog();                                              // 0x1418df4e0
    virtual ~UICartoonDialog();                                     //  0 0x1418df5f0 (??_G 0x1418e08e0)
    virtual CString vfunc_1();                                      //  1 0x1418df6c0 "CartoonDialog"
    virtual int vfunc_13();                                         // 13 0x1418df7e0 page keys
    virtual void OnLoadComplete();                                  // 22 0x1418df790
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x1418dfa90 "onPrev" / "onNext"
    virtual int vfunc_48();                                         // 48 0x1418e0920
    virtual void vfunc_67();                                        // 67 0x1418df710 Close

    int FUN_1418dfb30(int nBookId, int n2c, int nLayer);            // 0x1418dfb30 show a book (open the dialog when closed)
    int GetBookId();                                            // 0x1418dfc40 m_nBookId
    void FUN_1418dfc60(CInPacket& packet);                          // 0x1418dfc60 packet 0x88: show the book
    void FUN_1418dfd50();                                           // 0x1418dfd50 send the current pages to the movie
    void OnNext();                                           // 0x1418dffc0 next pages
    void OnPrev();                                           // 0x1418e0010 previous pages
    int FUN_1418e0070(int nPage, ASObj* pPage);                     // 0x1418e0070 fill an AS page object (img/str/valign)
    void FUN_1418e0230();                                           // 0x1418e0230 enable the prev/next buttons
    int FUN_1418e0480();                                            // 0x1418e0480 pages shown at once
    MS2Ptr<Unk_CtButton> FUN_140bb4b10(const CString& strName);     // 0x140bb4b10 bind a button child

    int m_nBookId;                                                  // +0x178
    int m_nPage;                                                    // +0x17c number of pages shown so far
};
MS2_CHECK_SIZE(UICartoonDialog, 0x180);
