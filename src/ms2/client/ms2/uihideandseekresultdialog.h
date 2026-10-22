// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uihideandseekresultdialog.h (name
// assumed: the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIHideAndSeekResultDialog is the result window of the Hide and Seek minigame (UI type 0x4f92, "HideAndSeekResultDialog").
// setData(round, rows, my row) fills the swf with one row per player of the map (team, job, name, kills, exp, isMe) and the
// local player's winner reward (an item shown through the item icon binder). RTTI .?AVUIHideAndSeekResultDialog@@,
// 0x198 bytes, 84 vtable slots plus the IMessageListener one at +0x18. Member names are invented.
#pragma once

#include <afx.h>
#include <set>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class ASArray;
class ASObj;
class PC;
class Unk_HsInfo;

class UIHideAndSeekResultDialog : public UIDialog
{
public:
    UIHideAndSeekResultDialog();                                    // 0x140c1e730
    virtual ~UIHideAndSeekResultDialog();                           //  0 0x140c1e7f0 (??_G 0x140c209d0)

    virtual CString GetTypeName();                                      //  1 "HideAndSeekResultDialog"
    virtual void OnLoadComplete();                                  // 22 fills the lists, plays the result sound
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 "OnClose"
    virtual void vfunc_43();                                        // 43 opens the swf entity animation
    virtual int vfunc_48() { return 0x4f92; }                       // 48 UI type id (COMDAT 0x140c20a70)
    virtual void vfunc_67();                                        // 67 Close: clears the result and the item icons

    void FUN_140c1eac0(int nRound, int nItemId, int nUnused, int nCount);   // stores the result (+0x188..+0x194)
    void FUN_140c1eb20();                                           // build the rows and call "setData"
    void FUN_140c1eec0(AScript objMine, MS2Ptr<Unk_HsInfo> spInfo);  // the winner reward of my row
    void FUN_140c1f120(ASArray& rows, MS2Ptr<Unk_HsInfo> spInfo, PC* pPC, bool bMine);   // one player row
    CString FUN_140c1f300(unsigned int nItemId, int nCount);        // bind the reward item icon, returns its bind id
    void FUN_140c1f590();                                           // release every bound item icon

private:
    MS2_LAYOUT_FRIEND;
    std::set<CString> m_boundIcons;                                 // +0x178 bind ids handed to the item icon binder
    int m_nRound;                                                   // +0x188 setData's first argument
    int m_nItemId;                                                  // +0x18c winner reward item
    int m_nUnused;                                                  // +0x190 (cleared with the others, never read)
    int m_nCount;                                                   // +0x194 winner reward count
};
MS2_CHECK_SIZE(UIHideAndSeekResultDialog, 0x198);
MS2_CHECK_OFFSET(UIHideAndSeekResultDialog, m_boundIcons, 0x178);
MS2_CHECK_OFFSET(UIHideAndSeekResultDialog, m_nRound, 0x188);
MS2_CHECK_OFFSET(UIHideAndSeekResultDialog, m_nCount, 0x194);
