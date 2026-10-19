// uibuddyeventlistener.h - PLACEHOLDER for UIBuddyEventListener (RTTI .?AVUIBuddyEventListener@@): the 8-byte (vftable only)
// interface that the buddy UI classes derive from to receive the buddy events (UICommunityDialog, ...). Owning unit
// ?\uibuddyeventlistener.cpp; ctor 0x1418d9370, dtor 0x1418d9390 (scalar deleting 0x1418d9e90). The 14 event slots take the
// buddy id; the defaults are empty. NOT an original header (name assumed).
#pragma once

#include "ms2/ms2layout.h"

class UIBuddyEventListener
{
public:
    UIBuddyEventListener();                                 // 0x1418d9370
    virtual ~UIBuddyEventListener();                        // 0x1418d9390
    virtual void vfunc_buddy_1(__int64 nId) {}              //  1
    virtual void vfunc_buddy_2(__int64 nId) {}              //  2
    virtual void vfunc_buddy_3(__int64 nId) {}              //  3
    virtual void vfunc_buddy_4(__int64 nId, int n) {}       //  4 0x1418da220
    virtual void vfunc_buddy_5(__int64 nId) {}              //  5
    virtual void vfunc_buddy_6(__int64 nId) {}              //  6
    virtual void vfunc_buddy_7(__int64 nId) {}              //  7 0x1418d8ff0
    virtual void vfunc_buddy_8(__int64 nId) {}              //  8
    virtual void vfunc_buddy_9(__int64 nId) {}              //  9
    virtual void vfunc_buddy_10(__int64 nId, int n) {}      // 10
    virtual void vfunc_buddy_11(__int64 nId) {}             // 11
    virtual void vfunc_buddy_12(__int64 nId) {}             // 12
    virtual void vfunc_buddy_13(__int64 nId) {}             // 13
    virtual void vfunc_buddy_14() {}                        // 14
};
MS2_CHECK_SIZE(UIBuddyEventListener, 0x8);
