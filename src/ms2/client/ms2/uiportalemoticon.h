// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiportalemoticon.h (name assumed: the
// .cpp's __FILE__ string is not in the exe for this unit).
//
// UIPortalEmoticon ("PortalEmoticon", UI type 0x4f0d, RTTI .?AVUIPortalEmoticon@@, 0x88 bytes): the emoticon bubble floating
// above a field portal (a sibling of UIUGCCubeNoticePopup: a UIObject whose movie root is an ASGameEntity, placed every frame
// at the screen projection of a world point). Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/placeholder/nipoint3.h"

class UIPortalEmoticon : public UIObject
{
public:
    UIPortalEmoticon();                                             // 0x140f9b9c0 (loads the swf at depth 4)
    virtual ~UIPortalEmoticon();                                    //  0 0x140f9baa0 (??_G 0x140f9c130)
    virtual CString GetTypeName();                                      //  1 0x140f9bb00 "PortalEmoticon"
    virtual void vfunc_2();                                         //  2 0x140f9bce0 show: load the movie and start showing
    virtual void vfunc_3();                                         //  3 0x140f9bd30 hide: unload and stop showing
    virtual void vfunc_15();                                        // 15 0x140f9bee0 per-frame: follow the portal's point
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x140f9c090 m_30 = new ASGameEntity
    virtual int vfunc_48() { return 0x4f0d; }                       // 48 0x140f9c170 UI type id
    virtual void vfunc_52();                                        // 52 0x140f9bd70 open the movie with the emoticon name

    int IsShown();                                            // m_bShown
    void FUN_140f9bb70();                                           // start showing (m_bShown = m_bPending = 1)
    void FUN_140f9bba0();                                           // stop showing
    void FUN_140f9bbd0();                                           // unregister the emoticon and stop showing
    void FUN_140f9bc40(Vector3 ptWorld);                    // the portal's point (the bubble floats 150 above it)
    void SetName(const CStringW& strName);                    // the emoticon name
    void FUN_140f9bf70();                                           // project the world point and place the movie

private:
    MS2_LAYOUT_FRIEND;
    Vector3 m_ptWorld;                                      // +0x68 the world point above the portal
    int m_bShown;                                                   // +0x74 the emoticon is wanted
    int m_bPending;                                                 // +0x78 open the movie once it is loaded (vfunc_52)
    int m_pad_7c;
    CStringW m_strName;                                             // +0x80 the emoticon name
};
MS2_CHECK_SIZE(UIPortalEmoticon, 0x88);
MS2_CHECK_OFFSET(UIPortalEmoticon, m_ptWorld, 0x68);
MS2_CHECK_OFFSET(UIPortalEmoticon, m_bShown, 0x74);
MS2_CHECK_OFFSET(UIPortalEmoticon, m_strName, 0x80);
