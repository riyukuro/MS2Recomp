// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiugccubenoticepopup.h (name assumed: the
// .cpp's __FILE__ string is not in the exe for this unit).
//
// UIUGCCubeNoticePopup ("UGCCubeNoticePopup", UI type 0x4f52, RTTI .?AVUIUGCCubeNoticePopup@@, 0x98 bytes): the notice
// floating above a function cube in a player-made map (the cube's text and its owner-entered notice). Created and
// driven by FunctionCubeObject (functioncubeobject.h declares a placeholder of the same name; this is the real layout:
// it is a UIObject, not a CPtred). Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/placeholder/nipoint3.h"

#include <egf/EntityID.h>

class UIUGCCubeNoticePopup : public UIObject
{
public:
    UIUGCCubeNoticePopup();                                         // 0x140fb49b0 (loads the swf at depth 7)
    virtual ~UIUGCCubeNoticePopup();                                //  0 0x140fb4aa0 (??_G 0x140fb5260)
    virtual CString GetTypeName();                                      //  1 0x140fb4b10 "UGCCubeNoticePopup"
    virtual void OnLoadComplete();                                  // 22 0x140fb4b60 base, then show the text
    virtual void vfunc_15();                                        // 15 0x140fb4dc0 per-frame: follow the cube's point
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fb4e60
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x140fb51f0 m_30 = new ASGameEntity
    virtual int vfunc_48() { return 0x4f52; }                       // 48 0x140fb52a0 UI type id
    virtual void vfunc_52();                                        // 52 0x140fb4d10 hide when the movie clip is up

    int IsShown();                                            // m_bShown
    void FUN_140fb4bb0();                                           // start showing (m_bShown = m_bPending = 1)
    void FUN_140fb4be0();                                           // unregister the popup and stop showing
    void SetPtWorld(Vector3 ptWorld);                    // the world point the popup floats at
    void SetIdEntity(const egf::EntityID& id);                    // the cube's entity
    void FUN_140fb4cc0(const CStringW& strTitle, const CStringW& strText);   // the texts
    void FUN_140fb4eb0();                                           // project the world point and place the movie
    void FUN_140fb5080(int bShow);                                  // push the texts and the visibility to the movie

private:
    MS2_LAYOUT_FRIEND;
    Vector3 m_ptWorld;                                      // +0x68 the world point above the cube
    int m_bShown;                                                   // +0x74 the popup is wanted
    int m_bPending;                                                 // +0x78 hide it once the movie clip is up (vfunc_52)
    int m_bVisible;                                                 // +0x7c the last visibility sent to the movie
    egf::EntityID m_idEntity;                                       // +0x80
    CStringW m_strText;                                             // +0x88
    CStringW m_strTitle;                                            // +0x90
};
MS2_CHECK_SIZE(UIUGCCubeNoticePopup, 0x98);
MS2_CHECK_OFFSET(UIUGCCubeNoticePopup, m_ptWorld, 0x68);
MS2_CHECK_OFFSET(UIUGCCubeNoticePopup, m_bShown, 0x74);
MS2_CHECK_OFFSET(UIUGCCubeNoticePopup, m_bVisible, 0x7c);
MS2_CHECK_OFFSET(UIUGCCubeNoticePopup, m_idEntity, 0x80);
MS2_CHECK_OFFSET(UIUGCCubeNoticePopup, m_strText, 0x88);
MS2_CHECK_OFFSET(UIUGCCubeNoticePopup, m_strTitle, 0x90);
