// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uibluemarblegamedialog.h (name assumed:
// the exe has no __FILE__ string for this unit).
//
// UIBlueMarbleGameDialog ("BlueMarbleGameDialog", UI type 0x4f15) is the board game window of the blue marble event
// (GameEventBlueMarble / BlueMarbleEventContext): the player rolls the dice ("onDice" -> packet 0x8d sub-op 1), the
// server answers with packet 0xe5 (0 = open: board, rewards and counters, 2 = trap escape result, 4 = move result,
// 6 = error / dice messages) and the movie animates the walk ("onActionNotify*", "onActionWalk", "onActionFly").
// RTTI .?AVUIBlueMarbleGameDialog@@, 0x1b0 bytes = UIDialog + the bound item id list and five counters.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; the counters are named from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASTextField;
class CInPacket;
class CMsgBoxData;
class Unk_140acd6e0;

class UIBlueMarbleGameDialog : public UIDialog
{
public:
    UIBlueMarbleGameDialog();                                           // 0x140f21590 (open tween 1)
    virtual ~UIBlueMarbleGameDialog() = default;                        //  0 0x140f24ac0 (??_G 0x140f24b40)
    virtual CString GetTypeName();                                          //  1 0x140f21680 "BlueMarbleGameDialog"
    virtual void OnLoadInit();                                          // 20 0x140f217f0 ask the server for the board
    virtual void OnLoadComplete();                                      // 22 0x140f216d0
    virtual void vfunc_26();                                            // 26 0x140f216f0 release the bound reward items
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                        // 28 0x140f22350
    virtual int vfunc_48() { return 0x4f15; }                           // 48 0x140f24b80 UI type id
    virtual void vfunc_67();                                            // 67 0x140f21790 close
    virtual int vfunc_71();                                             // 71 0x140f22640 ask before closing
    virtual void vfunc_79(void* p);                                     // 79 0x140f21850 (CInPacket*)

    bool FUN_140f22760(int nResult, const CMsgBoxData& box);            // close confirm callback
    void FUN_140f227a0(CInPacket& packet);                              // send the board cells ("setBoard")
    void FUN_140f22bb0(int nPosition);                                  // send the round rewards ("onReward")
    void FUN_140f22fe0(int nDice1, int nDice2, int nKind);              // "onDice": the roll result
    void FUN_140f23200(int nAction, int nArg, int nPrevPosition);       // "onActionNotify*" / walk / fly
    void FUN_140f23590(int nItemId, int nRarity, int nCount);           // "onRewardNotify"
    void FUN_140f237e0(int nPrevPosition, int nPosition);               // reward notify when a round is passed
    void FUN_140f23940();                                               // "updateDiceButton"
    void FUN_140f23b90();                                               // m_coinCount text
    void FUN_140f23ca0();                                               // m_finishCount text
    void FUN_140f23da0();                                               // "updateReward"
    CString FUN_140f23f10(int nItemId, int nRarity, int nCount);        // bind a reward item, returns its bind id
    void FUN_140f24140(int bEnabled);                                   // enable the m_dice button
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);          // 0x140bb4cf0 text field child lookup
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);        // 0x140bb4b10 bind a button child

private:
    ATL::CAtlArray<CString> m_boundIds;                                 // +0x178 bind ids of the reward items
    int m_nConsumeItemId;                                               // +0x198
    int m_nConsumeItemCount;                                            // +0x19c
    int m_nPosition;                                                    // +0x1a0 board position (laps * 0x1c + cell)
    int m_nFreeDice;                                                    // +0x1a4
    int m_bIdle;                                                        // +0x1a8
};
MS2_CHECK_SIZE(UIBlueMarbleGameDialog, 0x1b0);
