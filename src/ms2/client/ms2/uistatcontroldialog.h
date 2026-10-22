// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uistatcontroldialog.h (name assumed:
// the exe has no __FILE__ string for this unit).
//
// UIStatControlDialog ("StatControlDialog", RTTI .?AVUIStatControlDialog@@, 0x188 bytes = UIDialog +
// UIStatusEventListener at +0x178 + UIItemEventListener at +0x180): the GM stat window. It lists every stat of the
// local player (current value, bonus, the "[ stat ] [ value ]" label) in the movie list "m_stats" and sends the chat
// commands "/SetMaxStat <stat> <value>" and "/ResetMaxStat <stat|all>" for the movie's buttons. The status and item
// listeners refresh the list whenever the dialog is open. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are
// non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uistatuseventlistener.h"
// UIItemEventListener::vfunc_23 and UISwfEntity::vfunc_23 share a name and signature; this dialog overrides only the
// listener's slot (the exe keeps UISwfEntity::vfunc_23 in the primary vftable), so the listener's slot is renamed here.
#define vfunc_23 vfunc_il23
#include "ms2/placeholder/uiitemeventlistener.h"
#undef vfunc_23

class Unk_StatList;

class UIStatControlDialog : public UIDialog, public UIStatusEventListener, public UIItemEventListener
{
public:
    UIStatControlDialog();                                              // 0x14134e450 (open tween 1)
    virtual ~UIStatControlDialog();                                     //  0 0x14134fbe0 (??_G 0x14134fc40)
    virtual CString GetTypeName();                                          //  1 0x14134e510 "StatControlDialog"
    virtual int vfunc_13();                                             // 13 0x14134e730 escape key closes
    virtual void OnLoadInit();                                          // 20 0x14134e690 register the listeners, fill the list
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x14134e790 the movie's button callbacks
    virtual int vfunc_48() { return 0x4ea6; }                           // 48 0x14134fc80 UI type id
    virtual void vfunc_67();                                            // 67 0x14134e600 unregister the listeners, close

    // UIStatusEventListener (o178): refresh when the dialog is open.
    virtual int vfunc_oa0_1();                                          // o178 1 0x14134e5b0
    virtual void vfunc_oa0_2();                                         // o178 2 0x14134ecb0
    virtual void vfunc_oa0_3(int a1, int a2);                           // o178 3 0x14134ed10
    virtual void vfunc_oa0_4(int a1, int a2);                           // o178 4 0x14134ed70
    virtual void vfunc_oa0_5(int a1, int a2);                           // o178 5 0x14134edd0
    virtual void vfunc_oa0_6(void* a1, void* a2);                       // o178 6 0x14134ee30
    virtual void vfunc_oa0_7(int a1, CStringW s);                       // o178 7 0x14134ef80
    virtual void vfunc_oa0_9(unsigned short a1);                        // o178 9 0x14134eea0
    virtual void vfunc_oa0_10(CStringW s);                              // o178 10 0x14134ef00

    // UIItemEventListener (o180).
    virtual int vfunc_il1();                                            // o180 1 0x14134e560
    virtual void vfunc_21(void* pItem);                                 // o180 21 0x14134f000
    virtual void vfunc_22(void* pItem);                                 // o180 22 0x14134f070
    virtual void vfunc_il23(void* pItem);                               // o180 23 0x14134f0e0

    MS2Ptr<Unk_StatList> FUN_140c02900(const CString& strName);         // bind a list child of the movie
    void FUN_14134f150();                                               // refill the stat list
    void FUN_14134f790(MS2Ptr<Unk_StatList> list, int nStat, int bFloat);   // append the row of one stat
};
MS2_CHECK_SIZE(UIStatControlDialog, 0x188);
