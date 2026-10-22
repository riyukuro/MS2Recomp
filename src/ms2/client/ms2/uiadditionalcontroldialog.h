// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiadditionalcontroldialog.h (name
// assumed: the class name; the exe has no __FILE__ string for this unit).
//
// UIAdditionalControlDialog ("AdditionalEffectControlDialog", UI type 0x4e8f, RTTI .?AVUIAdditionalControlDialog@@,
// 0x188 bytes = UIDialog + one list handle at +0x178): the GM tool that applies additional effects (buffs/debuffs) to
// the own character. "m_effects" lists every <additional> row of the skill table ("[id] [Lv.n] name (passive) (buff)"),
// "OnGroupChange" / "OnSearchItem" refill it, "OnAddEffect" / "OnResetEffect" send packet 0x5c, and the "m_contextMenu"
// right-click menu opens the effect's Data/Xml/Additional/NNN.xml. Names: virtuals are Ghidra's vfunc_<slot>;
// FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_AcList;

class UIAdditionalControlDialog : public UIDialog
{
public:
    UIAdditionalControlDialog();                                        // 0x1418b25f0 (open tween 1)
    virtual ~UIAdditionalControlDialog();                               //  0 0x1418b50b0 (??_G 0x1418b5260)
    virtual CString GetTypeName();                                          //  1 0x1418b2670 "AdditionalEffectControlDialog"
    virtual void OnLoadInit();                                          // 20 0x1418b26c0 build the context menu
    virtual void vfunc_26();                                            // 26 0x1418b26f0 drop the list handle
    virtual int vfunc_13();                                             // 13 0x1418b2720 enter / tab / escape keys
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x1418b2860
    virtual int vfunc_48() { return 0x4e8f; }                           // 48 0x1418b5400 UI type id

    MS2Ptr<Unk_AcList> FUN_140c02900(const CString& strName);           // bind a list child of the movie
    void FUN_1418b2c20(const Scaleform::GFx::FunctionHandler::Params& params);   // context menu click
    void FUN_1418b2e80(const CString& strGroup, const CStringW& strSearch);      // refill "m_effects"
    void FUN_1418b3620();                                               // fill "m_contextMenu"
    unsigned FUN_1418b3ac0();                                           // the effect id of the selected row

    MS2Ptr<Unk_AcList> m_pList;                                         // +0x178 the context menu list
};
MS2_CHECK_SIZE(UIAdditionalControlDialog, 0x188);
