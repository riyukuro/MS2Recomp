// uipvpresultdialog.h - UIPvPResultDialog (RTTI .?AVUIPvPResultDialog@@, 0x188 bytes, UIDialog, UI id 0x4e9b, swf
// "PvPResultDialog"): the result table of the free-for-all / one-punch PvP match (one row per rank, "AddOrUpdateMember"),
// plus the player's own last result and reward ("showLastResult", "setRewardText", "setRewardIcon"). Owning unit:
// ?\uipvpresultdialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASObj;
class Unk_PrEntry;

class UIPvPResultDialog : public UIDialog
{
public:
    UIPvPResultDialog();                                        // 0x1413439a0
    virtual ~UIPvPResultDialog();                               //  0 0x141343a30 (??_G 0x141344a40)
    virtual CString GetTypeName();                                  //  1 0x141343a70 "PvPResultDialog"
    virtual void OnLoadComplete();                              // 22 0x141343b70
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1413448f0 "OnClose"
    virtual void vfunc_43();                                    // 43 0x141344990
    virtual int vfunc_48() { return 0x4e9b; }                   // 48 0x141344aa0
    virtual int vfunc_65();                                     // 65 0x141343ac0
    virtual void vfunc_67();                                    // 67 0x141343af0 close: tell the server we left the result
    virtual void vfunc_79(void* pData);                         // 79 0x141343bb0

    void FUN_141343c10(int nFrom, int nTo);                     // push the rows of ranks nFrom..nTo (any order)
    void FUN_141343da0(int nRank);                              // m_180 = nRank; the reward text / icon and "showLastResult"
    void FUN_1413440a0();                                       // read the mode and the reward item from the player's PvP info
    bool FUN_141344210(ASObj* pObj, int nRank, Unk_PrEntry* pEntry);   // fill one row object
    void FUN_141344780(int nRank);                              // push all rows, then FUN_141343da0

    int m_178;                                                  // +0x178 mode (2 = free-for-all, 5 = one punch)
    int m_17c;                                                  // +0x17c reward item id
    int m_180;                                                  // +0x180 own rank (-1 = none)
};
MS2_CHECK_SIZE(UIPvPResultDialog, 0x188);
MS2_CHECK_OFFSET(UIPvPResultDialog, m_178, 0x178);
