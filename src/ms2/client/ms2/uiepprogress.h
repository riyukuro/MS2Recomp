// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiepprogress.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UIEpProgress (RTTI .?AVUIEpProgress@@, 0xe8 bytes) is the "EpProgress" popup entity (UI type 0x4e66): a
// UIPopupEntity (0xd8) + the UIStatusEventListener subobject at +0xd8 + the last ep value at +0xe0. It pushes
// "setEP(old, new, arg)" to its clip when the ep value drops and keeps itself above the target's name tag.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uipopupentity.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class UIEpProgress : public UIPopupEntity, public UIStatusEventListener
{
public:
    UIEpProgress(Unk_PopupOwner* pOwner);                           // 0x141931550
    virtual ~UIEpProgress();                                        //  0 0x141931640 (??_G 0x141931e60)
    virtual CString GetTypeName();                                      //  1 0x1419316f0 "EpProgress"
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x141931d10 m_30 = new ASGameEntity
    virtual int vfunc_48() { return 0x4e66; }                       // 48 0x141931ea0 UI type id
    virtual void vfunc_52();                                        // 52 0x141931790
    virtual void vfunc_53(Unk_PopupPos pos);                        // 53 0x1419317b0 place the clip above the target's tag
    virtual void vfunc_54(int nMode);                               // 54 0x141931740
    virtual void vfunc_55();                                        // 55 0x141931770
    virtual int vfunc_57(int nForce);                               // 57 0x1419319a0
    virtual float vfunc_59();                                       // 59 0x141931a10 owner's slot 89
    // UIStatusEventListener (+0xd8) override: slot 5 (the ep changed), 0x141931a50
    virtual void vfunc_oa0_5(int a1, int a2);

    void FUN_141931bd0(int nEp, int a2);                            // set the ep value and push "setEP"

private:
    int m_e0;                                                       // +0xe0 last ep value
};
MS2_CHECK_SIZE(UIEpProgress, 0xe8);
