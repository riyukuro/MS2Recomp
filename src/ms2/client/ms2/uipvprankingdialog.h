// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uipvprankingdialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIPvPRankingDialog is the individual PvP ranking HUD ("PvPRankingDialog", UI type 0x4e9a): the top three ranks and
// the local player's own rank, pushed to the movie as "updateMember" / "updateMe" objects (rank, rankText,
// charName, score, job). RTTI .?AVUIPvPRankingDialog@@, 0x178 bytes (no members of its own), vftables at +0 and
// +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASObj;
class Unk_PvPRankEntry;

class UIPvPRankingDialog : public UIDialog
{
public:
    UIPvPRankingDialog();                                                                           // 0x141342f10
    virtual ~UIPvPRankingDialog();                                                                  //  0 0x141342f80 (??_G 0x1413437a0)
    virtual CString GetTypeName();                                                                      //  1 0x141342fc0
    virtual void OnLoadComplete();                                                                  // 22 0x141343060
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x141343530
    virtual void vfunc_43();                                                                        // 43 0x141343620
    virtual int vfunc_48();                                                                         // 48 0x141343840
    virtual int vfunc_52();                                                                         // 52 0x141343850
    virtual int vfunc_65();                                                                         // 65 0x141343010
    virtual void vfunc_67();                                                                        // 67 0x141343040
    virtual void vfunc_79(void* pData);                                                             // 79 0x141343090
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);                                       // o18 0 0x1413436e0

    bool FUN_1413430f0(ASObj* pObj, int nRank, Unk_PvPRankEntry* pEntry);   // fill a rank object
    void FUN_1413432b0();                                           // push the top three and the own rank
};
MS2_CHECK_SIZE(UIPvPRankingDialog, 0x178);
