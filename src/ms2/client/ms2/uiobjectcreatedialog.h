// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiobjectcreatedialog.h (name assumed:
// the exe has no __FILE__ string for this unit).
//
// UIObjectCreateDialog ("ObjectCreateDialog", UI type 0x4ed0, RTTI .?AVUIObjectCreateDialog@@, 0x178 bytes = UIDialog):
// the GM window that places interact objects. The movie lists every row of the interact-object table ("m_objects",
// filtered by the "m_search" text), "OnObjectCreate" asks the server to create the chosen object at the player's
// position (packet 0x31 / 9), "onIndexChange" lists the positions where the selected object stands ("m_position")
// and "OnMove" asks the server to move to one (packet 0x50 / 2). Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va>
// are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_ObjectCreateList;
class Unk_ObjectCreateInput;

class UIObjectCreateDialog : public UIDialog
{
public:
    UIObjectCreateDialog();                                             // 0x14131f690 (open tween 1)
    virtual ~UIObjectCreateDialog() = default;                          //  0 0x1413203e0 (??_G 0x141320480)
    virtual CString GetTypeName();                                          //  1 0x14131f700 "ObjectCreateDialog"
    virtual int vfunc_13();                                             // 13 0x14131f7a0 enter key refills the list
    virtual void OnLoadInit();                                          // 20 0x14131f750 fill the list
    virtual void vfunc_26();                                            // 26 0x14131f780
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x14131f800 the movie's callbacks
    virtual int vfunc_48() { return 0x4ed0; }                           // 48 0x141320530 UI type id

    MS2Ptr<Unk_ObjectCreateInput> FUN_140e35bd0(const CString& strName);    // bind a text input child of the movie
    MS2Ptr<Unk_ObjectCreateList> FUN_140c02900(const CString& strName);     // bind a list child of the movie
    void FUN_14131ff70();                                               // refill m_objects from the search text
};
MS2_CHECK_SIZE(UIObjectCreateDialog, 0x178);
