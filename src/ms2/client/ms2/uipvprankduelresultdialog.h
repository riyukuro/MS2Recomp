// uipvprankduelresultdialog.h - UIPvPRankDuelResultDialog (RTTI .?AVUIPvPRankDuelResultDialog@@, 0x1c0 bytes, UIDialog,
// UI id 0x4f05, swf "PvPRankDuelResultDialog"): the result of a ranked duel - both players (name, score, time, profile
// picture), who won, and the reward text / icon. The server feeds it with a packet (FUN_140f90b10). Owning unit:
// ?\uipvprankduelresultdialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;

// The duel result (0x48), read from the packet. Left / right are the two players.
struct Unk_PrdResult
{
    Unk_PrdResult();                                            // 0x140f91b30
    ~Unk_PrdResult();                                           // 0x140f91bf0

    CStringW m_strNameL;                                        // +0x00
    CStringW m_strNameR;                                        // +0x08
    int m_nScoreL;                                              // +0x10
    int m_nScoreR;                                              // +0x14
    int m_nMinL;                                                // +0x18
    int m_nMinR;                                                // +0x1c
    int m_nSecL;                                                // +0x20
    int m_nSecR;                                                // +0x24
    __int64 m_nCharIdL;                                         // +0x28
    __int64 m_nCharIdR;                                         // +0x30
    __int64 m_nWinnerId;                                        // +0x38 the character id of the winner
    int m_nRewardL;                                             // +0x40
    int m_nRewardR;                                             // +0x44
};
MS2_CHECK_SIZE(Unk_PrdResult, 0x48);

class UIPvPRankDuelResultDialog : public UIDialog
{
public:
    UIPvPRankDuelResultDialog();                                // 0x140f90780
    virtual ~UIPvPRankDuelResultDialog();                       //  0 0x140f90820 (??_G 0x140f91c20)
    virtual CString GetTypeName();                                  //  1 0x140f90870 "PvPRankDuelResultDialog"
    virtual void OnLoadComplete();                              // 22 0x140f90950
    virtual void vfunc_26();                                    // 26 0x140f909a0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f909c0 "OnClose"
    virtual void vfunc_43();                                    // 43 0x140f90a60
    virtual int vfunc_48() { return 0x4f05; }                   // 48 0x140f91c60
    virtual int vfunc_65();                                     // 65 0x140f908c0
    virtual void vfunc_67();                                    // 67 0x140f908f0 close: tell the server the result was seen

    void FUN_140f90b10(CInPacket* pIn);                         // the result packet
    void FUN_140f90ec0(__int64 nCharId, bool bLeft);            // a player's profile picture
    void FUN_140f91120(Unk_PrdResult* pResult);                 // push everything to the movie

    Unk_PrdResult m_result;                                     // +0x178
};
MS2_CHECK_SIZE(UIPvPRankDuelResultDialog, 0x1c0);
MS2_CHECK_OFFSET(UIPvPRankDuelResultDialog, m_result, 0x178);
