// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uitalkcinematic.h (name assumed from the unit
// path: the .cpp's __FILE__ string is not in the exe for this unit).
//
// UITalkCinematic ("TalkCinematic", UI type id 0x4e40, RTTI .?AVUITalkCinematic@@, 0xd0 bytes): the full-screen NPC talk
// window. UITalkManager (placeholder/uitalkmanager.h) owns the talk state; this window shows one page at a time through a
// CCinematicComponent (cinematiccomponent.h) and forwards the swf callbacks (OnNext, OnSelect, OnEnd, ...) to it.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinematiccontent.h"

class CCinematicComponent;
class CItem;
class Unk_TalkItemList;

// The 8-byte millisecond poll timer of the next-key repeat (ctor 0x140517b00, test 0x140268870, reset 0x140268840).
class Unk_TalkRepeatTimer
{
public:
    Unk_TalkRepeatTimer();                                      // 0x140517b00
    int FUN_140268870(unsigned nInterval);                      // true once the interval elapsed
    void FUN_140268840();                                       // restart
private:
    unsigned m_nTick; unsigned m_nExtra;
};

// The loaded reward image names (the exe's CAtlArray<void*> shape; the accessors are out of line).
class Unk_TalkImageList : public ATL::CAtlArray<void*>
{
public:
    unsigned __int64 FUN_1401662c0();                               // GetCount
    CString& FUN_140164930(unsigned __int64 nIndex);                // GetAt
    void FUN_140165270(const CString& strImage);                    // Add
    void FUN_1402c2890();                                           // RemoveAll
};
MS2_CHECK_SIZE(Unk_TalkImageList, 0x20);

class UITalkCinematic : public UIHeadUpDisplay
{
public:
    UITalkCinematic();                                              // 0x141b19ea0
    virtual ~UITalkCinematic();                                     //  0 0x141b19f90 (??_G 0x141b1d7d0)
    virtual CString vfunc_1();                                      //  1 0x141b1a030 "TalkCinematic"
    virtual void vfunc_2();                                         //  2 0x141b1a080 show: register for key input, TalkCinematic mode 2
    virtual void vfunc_3();                                         //  3 0x141b1a0e0 hide
    virtual int vfunc_13();                                         // 13 0x141b1a3b0 key handling: confirm / skip
    virtual void OnLoadComplete();                                  // 22 0x141b1a140 resume the open talk
    virtual void vfunc_26();                                        // 26 0x141b1a280 (the base's)
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b1a580 swf callbacks
    virtual void vfunc_43();                                        // 43 0x141b1a2a0 stage size
    virtual int vfunc_48() { return 0x4e40; }                       // 48 0x141b1d840 UI type id

    bool FUN_141b1a8e0(const CStringW& strScript, const CString& strSound, const CString& strIllust);   // show a plain script page (the 'modifyScript' call)
    void FUN_141b1ac40(Unk_TalkItemList& rItems, const CStringW& strTitle, unsigned nMeso, unsigned nExp, __int64 nMerat);   // reward page
    void FUN_141b1b000(Unk_TalkItemList& rItems, const CStringW& strTitle, const CStringW& strMood, const CStringW& strAffinityExp, int nJackpot);   // maid reward page
    int FUN_141b1b440(CCinematicContent* pContent, bool bLast);                 // show a page (nonzero: shown)
    void FUN_141b1b8b0();                                           // clear the page and close the window
    void FUN_141b1b9f0();                                           // the skip button
    void FUN_141b1bad0();                                           // focus up
    void FUN_141b1bb80();                                           // focus down
    void FUN_141b1bc30();                                           // select
    void FUN_141b1bce0(int nMsg);                                   // forward a key to the page component
    void FUN_141b1be50();                                           // firework effect
    void FUN_141b1beb0(CString strImage);                           // remember a loaded reward image (by value: destroyed by the callee)
    void FUN_141b1bf00();                                           // release the reward images
    void FUN_141b1bf80(unsigned nKeyGroup);                         // 0x141b1bf80
    void FUN_141b1bfa0();                                           // 0x141b1bfa0 default key group
    int FUN_141b1bfc0();                                            // 0x141b1bfc0
    void FUN_141b1bfe0(ASObj& rPage, const CCinematicContent* pContent);   // fill the illustrations of the page
    void FUN_141b1c4c0(ASObj& rPage, const CCinematicContent* pContent);   // the image plate
    int FUN_141b1c530();                                            // the next key was pressed
    CString FUN_141b1c5e0(unsigned nNpcId);                         // illustration path of an npc
    CString FUN_141b1c670(const CString& strName);                  // illustration path ("empty" when missing)
    void FUN_141b1c720(ASObj& rPage, int nNpcTalk);                 // illustration of the other npc
    MS2Ptr<CCinematicComponent> FUN_141b1c960(int nButtonSet);      // the component of a button set
    int FUN_141b1d3d0();                                            // lower cut line y
    int FUN_141b1d460();                                            // illust x

private:
    MS2_LAYOUT_FRIEND;
    int m_nTalkComplete;                                            // +0x70 1 until a page starts
    int m_nLoaded;                                                  // +0x74 the swf is ready
    char m_pad_78[8];
    Unk_TalkImageList m_images;                                     // +0x80 reward images to release
    MS2Ptr<CCinematicContent> m_spContent;                          // +0xa0 the current page
    MS2Ptr<CCinematicComponent> m_spComponent;                      // +0xb0 its component
    unsigned m_nKeyGroup;                                           // +0xc0 key group of the talk (0x620001d)
    Unk_TalkRepeatTimer m_nextKeyTimer;                             // +0xc4
};
MS2_CHECK_SIZE(UITalkCinematic, 0xd0);
MS2_CHECK_OFFSET(UITalkCinematic, m_images, 0x80);
MS2_CHECK_OFFSET(UITalkCinematic, m_spComponent, 0xb0);
MS2_CHECK_OFFSET(UITalkCinematic, m_nextKeyTimer, 0xc4);
