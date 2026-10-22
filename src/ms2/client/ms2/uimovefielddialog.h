// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimovefielddialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UIMoveFieldDialog ("MoveFieldDialog", UI type 0x4e2a, RTTI .?AVUIMoveFieldDialog@@, 0x178 bytes = UIDialog): the
// debug "move to map" list. The movie sends "OnMoveField" / "OnAddField" (a field id as text) and "OnSearchField" (a
// filter); the dialog turns them into the chat commands "/MoveField {0}" and "/AddField {0}" or refills "m_fieldList"
// with every CFieldData whose id or name contains the filter. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are
// non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_MoveFieldList;

class UIMoveFieldDialog : public UIDialog
{
public:
    UIMoveFieldDialog();                                                // 0x141a55740 (open tween 1)
    virtual ~UIMoveFieldDialog() = default;                                   //  0 0x141a57940 (??_G 0x141a579e0)
    virtual CString GetTypeName();                                          //  1 0x141a557b0 "MoveFieldDialog"
    virtual void OnLoadInit();                                          // 20 0x141a55800 show the whole list
    virtual int vfunc_13();                                             // 13 0x141a55830 enter / escape keys
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x141a55900
    virtual int vfunc_48() { return 0x4e2a; }                           // 48 0x141a57a20 UI type id

    MS2Ptr<Unk_MoveFieldList> FUN_140c02900(const CString& strName);    // bind a list child of the movie
    void FUN_141a55de0();                                               // FUN_141a55e30("")
    void FUN_141a55e30(const CStringW& strFilter);                      // refill m_fieldList
};
MS2_CHECK_SIZE(UIMoveFieldDialog, 0x178);
