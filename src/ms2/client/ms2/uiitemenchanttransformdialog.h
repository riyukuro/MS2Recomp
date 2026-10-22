// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiitemenchanttransformdialog.h (name
// assumed: the exe has no __FILE__ string for this unit).
//
// UIItemEnchantTransformDialog ("ItemEnchantTransformDialog", UI type 0x4e6e, RTTI .?AVUIItemEnchantTransformDialog@@,
// 0x208 bytes): the window that transforms an enchanted equipment item into one of the table's output items. State
// m_state: 0 = pick a target, 1 = target picked (the output list is shown), 2 = result received. The target and output
// item slots are bound to the movie's item bags by names "<UI>.Target" / "<UI>.Select" / "<UI>.Output.<n>".
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"

class CMsgBoxData;
class Unk_TfBoard;

class UIItemEnchantTransformDialog : public UIDialog
{
public:
    UIItemEnchantTransformDialog();                                     // 0x140c3cc10
    virtual ~UIItemEnchantTransformDialog();                            //  0 0x140c3ced0 (??_G 0x140c3f0a0)
    virtual CString GetTypeName();                                          //  1 0x140c3cfa0 "ItemEnchantTransformDialog"
    virtual int vfunc_13();                                             // 13 0x140c3d280 0
    virtual void OnLoadComplete();                                      // 22 0x140c3d150
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x140c3d290
    virtual void vfunc_43();                                            // 43 0x140c3d020 place beside the inventory
    virtual int vfunc_48() { return 0x4e6e; }                           // 48 0x140c3f0e0 UI type id
    virtual int vfunc_65();                                             // 65 0x140c3cff0
    virtual void vfunc_67();                                            // 67 0x140c3d190 reset and close
    virtual void vfunc_79(void* pPacket);                               // 79 0x140c3d3d0 transform result packet

    MS2Ptr<Unk_TfBoard> FUN_140c02990(const CString& strName);          // bind the child "m_board" / "m_targetItems"
    void FUN_140c3d420();                                               // refill the targets, relabel the submit button
    void FUN_140c3d5a0();                                               // collect the transformable items into m_targets
    void FUN_140c3d960(int nIndex);                                     // "OnSelectTargetItem": confirm / pick
    void FUN_140c3de50(int nIndex);                                     // pick the target, build the output list
    void OnSubmitTransform();                                               // "OnSubmitTransform": send packet 0x77
    void FUN_140c3ead0();                                               // result: relabel submit "retry", "onTransformResult"
    void OnSubmitRetry();                                               // "OnSubmitRetry": back to the first page
    bool FUN_140c3eda0(int nButton, const CMsgBoxData& box);            // the confirm box's answer

protected:
    MS2_LAYOUT_FRIEND;
    int m_state;                                                        // +0x178
    CString m_strTargetBag;                                             // +0x180 "<UI>.Target"
    CString m_strSelectBag;                                             // +0x188 "<UI>.Select"
    CString m_strOutputBag;                                             // +0x190 "<UI>.Output"
    ATL::CAtlArray<CString> m_outputNames;                              // +0x198 the bound output slot names
    MS2Ptr<CItem> m_selected;                                           // +0x1b8 the picked target
    ATL::CAtlArray<MS2Ptr<CItem> > m_targets;                           // +0x1c8
    ATL::CAtlArray<MS2Ptr<CItem> > m_outputs;                           // +0x1e8
};
MS2_CHECK_SIZE(UIItemEnchantTransformDialog, 0x208);
