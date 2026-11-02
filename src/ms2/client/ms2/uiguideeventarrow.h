// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
#pragma once
#include <atlcoll.h>
#include <utility>
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/intervaltimer.h"

// The arrow is a reference-counted data object, not a window (RTTI base CPtred). m_34 is its own use count (several
// AddArrow calls share one arrow; the CPtred count is the MS2Ptr's).
class UIGuideEventArrow : public CPtred {
public:
    UIGuideEventArrow();                                            // 0x14195dd10
    // 0 ~UIGuideEventArrow 0x1419609a0 is implicit (no vptr store in the exe)
    virtual void vfunc_1(MS2Ptr<AScript>);                          // 1 0x14195dd90 push the position to the swf (updateArrow/hideArrow)
    virtual int vfunc_2(void*);                                     // 2 0x14195dee0 screen position (Vector3*), 0 when off screen
    void FUN_14195dfa0();                                           // ++m_34
    void FUN_14195dfc0();                                           // --m_34 (asserts when 0)
    int GetUseCount();                                            // m_34
    int m_id;                                                       // +0x18 arrow id
    Vector3 m_pos;                                          // +0x1c world position
    int m_direction;                                                // +0x28
    int m_align;                                                    // +0x2c
    int m_textId;                                                   // +0x30 stringGuide id of the text arrow (0: plain arrow)
    int m_useCount;                                                 // +0x34
};
MS2_CHECK_SIZE(UIGuideEventArrow,0x38);
// Arrow that follows a UI element chosen by kind (m_kind) and name path (m_path) / parameter (m_param).
class UIGuideEventArrowDialog : public UIGuideEventArrow {
public:
    UIGuideEventArrowDialog();                                      // 0x14195e040
    // ~UIGuideEventArrowDialog 0x1419609c0 is implicit
    virtual int vfunc_2(void*);                                     // 2 0x14195e0e0
    void SetKindFromName(CString);                                    // kind from its name
    int GetTargetPosition(void*);                                       // kind 0: UI by id / name
    int FUN_14195e3f0(void*);                                       // 1 skill slot of MainPlayerInfo
    int FUN_14195e6e0(void*);                                       // 2..5 inventory item
    int FUN_14195ead0(void*);                                       // 6 inventory tab
    int FUN_14195eee0(void*);                                       // 7, 8 minimap marker
    int GetHouseMarkPosition(void*);                                       // 9 house mark
    int GetPartyDialogPosition(void*);                                       // 10 party camera
    int GetMessengerTargetPosition(void*);                                       // 11 messenger
    int GetCubeTypePosition(void*);                                       // 12 cube palette
    int FUN_14195f600(MS2Ptr<CItem>,int);                     // item matches the kind
    unsigned FUN_14195f7b0(int);                                    // object id of kind 7 / 8
    int FUN_14195f870(UISwfEntity*,void*);                          // position from the element path
    int FUN_14195fc40(UISwfEntity*,void*);                          // same, game menu dialog
    int FUN_141960510();                                            // current scene is one of m_70
    int m_38;                                                       // +0x38 ui id
    CString m_name;                                                 // +0x40 ui name
    int m_48;                                                       // +0x48 cube
    ATL::CAtlArray<CString> m_path;                                 // +0x50 child path
    ATL::CAtlArray<CString> m_scenes;                               // +0x70 scenes in which the arrow is shown
    int m_kind;                                                     // +0x90
    int m_param;                                                    // +0x94
};
MS2_CHECK_SIZE(UIGuideEventArrowDialog,0x98);
class UIGuideEvent : public UIObject {
public:
    UIGuideEvent();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual void vfunc_43();
    virtual void vfunc_15();
    virtual int vfunc_28(const char*,const Scaleform::GFx::Value*,unsigned int);
    virtual void vfunc_2();
    virtual void vfunc_3();
    // @0x14195cd90
    virtual int vfunc_48() { return 0x4e53; }
    int SkipTextTip();
    void FUN_141959a60(MS2Ptr<UIGuideEventArrow>);                  // AddArrow
    void ReleaseArrow(unsigned int);
    void FUN_14195a520(unsigned int,unsigned int,int);              // ShowTutorial
    void FUN_14195ab40(unsigned int,unsigned int,int);              // ShowSummary
    void ParseTagNameValue(CStringW,CStringW&,CStringW&);               // split "[[name:value]]"
    void PlayVoice(unsigned int);                               // play the voice of a string
    MS2Ptr<AScript> FindChildScript(const CString&);
    void FUN_14195a1d0(CStringW&,CStringW&,int&);
    void QueueOrShowTextTip(unsigned int,unsigned int);
    void HideTutorial(int);
    void HideSummary(int);
    void AdvanceTextTip(int);
    int IsTutorialShowing();
    int IsSummaryShowing();
    int IsTextTipShowing();
    int GetLastTip();
    void FUN_14195b970();
    void FUN_14195be30();
    void CheckSummaryExpiry();
    CStringW GetGuideText(unsigned int);
    CString GetGuideVoice(unsigned int);
    MS2Ptr<AScript> FUN_14195c230(const CString&,MS2Ptr<AScript>&);
private:
    MS2_LAYOUT_FRIEND;
    int m_sound;
    int m_guide;
    int m_tip;
    int m_lastTip;
    ATL::CAtlList<std::pair<unsigned int,unsigned int>> m_tips;
    ATL::CAtlMap<unsigned int,CStringW> m_strings;
    ATL::CAtlMap<unsigned int,CString> m_voices;
    MS2Ptr<AScript> m_summary;
    MS2Ptr<AScript> m_tutorial;
    unsigned int m_expiry;
    ATL::CAtlMap<unsigned int,MS2Ptr<UIGuideEventArrow>> m_arrows;
    MS2Ptr<AScript> m_hasArrow;
    Unk_IntervalTimer m_timer;
};
MS2_CHECK_SIZE(UIGuideEvent,0x1c0);
MS2_CHECK_OFFSET(UIGuideEvent,m_tips,0x78);
MS2_CHECK_OFFSET(UIGuideEvent,m_strings,0xa8);
MS2_CHECK_OFFSET(UIGuideEvent,m_voices,0xf0);
MS2_CHECK_OFFSET(UIGuideEvent,m_summary,0x138);
MS2_CHECK_OFFSET(UIGuideEvent,m_arrows,0x160);
MS2_CHECK_OFFSET(UIGuideEvent,m_timer,0x1b8);
