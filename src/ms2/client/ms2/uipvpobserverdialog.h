// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uipvpobserverdialog.h (name assumed:
// the class name; the exe has no assert path for it).
//
// UIPvPObserverDialog is the HUD of a spectator of a PvP match ("PvPObserverDialog", UI type 0x4e96): the two fighters
// (name, job level, portrait, hp bar, win marks, status text), the countdown ("setTime") and the camera buttons
// ("onObserveLeft" / "onObserveRight" / "onObserveCenter"). FUN_141a91940 feeds it a normal match, FUN_141a91a30 a duel
// match (rating instead of wins, a center camera). RTTI .?AVUIPvPObserverDialog@@, 0x1d8 bytes, vftables at +0 and
// +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset> or invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

// One fighter as the dialog keeps it (0x28 bytes; the ctor 0x141a92d00 is a COMDAT).
struct Unk_PvPObsSide
{
    Unk_PvPObsSide()                                                // 0x141a92d00
    {
        m_nCharId = 0;
        m_nHp = 0;
        m_nMaxHp = 0;
        m_nShownWins = 0;
        m_nWins = 0;
        m_nRating = 0;
    }

    __int64 m_nCharId;                  // +0x00
    __int64 m_nHp;                      // +0x08
    __int64 m_nMaxHp;                   // +0x10
    int m_nShownWins;                   // +0x18 the win mark the movie shows
    int m_nWins;                        // +0x1c
    int m_nRating;                      // +0x20 duel rating
    int m_24;                           // +0x24 (never written)
};
MS2_CHECK_SIZE(Unk_PvPObsSide, 0x28);

// One fighter of the match info handed in by the match packet (0x20 bytes).
struct Unk_PvPObsInput
{
    __int64 m_nCharId;                  // +0x00
    __int64 m_nHp;                      // +0x08
    __int64 m_nMaxHp;                   // +0x10
    int m_nWins;                        // +0x18
    int m_nRating;                      // +0x1c
};
MS2_CHECK_SIZE(Unk_PvPObsInput, 0x20);

// The match info (0x48 bytes).
struct Unk_PvPObsInfo
{
    Unk_PvPObsInput m_a;                // +0x00
    Unk_PvPObsInput m_b;                // +0x20
    int m_nCenter;                      // +0x40 the center camera team
    int m_44;
};
MS2_CHECK_SIZE(Unk_PvPObsInfo, 0x48);

class UIPvPObserverDialog : public UIDialog
{
public:
    UIPvPObserverDialog();                                      // 0x141a911b0
    virtual ~UIPvPObserverDialog();                             //  0 0x141a91260 (??_G 0x141a92d60)
    virtual CString GetTypeName();                                  //  1 0x141a912a0
    virtual void OnLoadComplete();                              // 22 0x141a91640
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x141a916d0
    virtual void vfunc_43();                                    // 43 0x141a91860
    virtual int vfunc_48() { return 0x4e96; }                   // 48 (COMDAT 0x141a92da0)
    virtual int vfunc_65();                                     // 65 0x141a912f0
    virtual void vfunc_67();                                    // 67 0x141a91330
    virtual void vfunc_72();                                    // 72 0x141a91400 per-frame: the countdown
    virtual void vfunc_79(void* pData);                         // 79 0x141a91670
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141a91880

    void FUN_141a91940(const Unk_PvPObsInfo& info);             // a normal match
    void FUN_141a91a30(const Unk_PvPObsInfo& info);             // a duel match
    void FUN_141a91b40();                                       // send both fighters to the movie
    void FUN_141a92b10(__int64 nCharId, __int64 nHp, __int64 nMaxHp);   // a fighter's hp bar
    void FUN_141a92c80();                                       // "startClosingUI"
    int FUN_141a92ce0();                                        // m_1c8

private:
    MS2_LAYOUT_FRIEND;
    Unk_PvPObsSide m_178;                                       // +0x178 left fighter
    Unk_PvPObsSide m_1a0;                                       // +0x1a0 right fighter
    int m_1c8;                                                  // +0x1c8 center camera team (0 = none)
    int m_1cc;                                                  // +0x1cc the countdown effect was started
    unsigned m_1d0;                                             // +0x1d0 countdown effect id
    bool m_1d4;                                                 // +0x1d4 duel match
    bool m_1d5;                                                 // +0x1d5 spectating (not one of the fighters)
};
MS2_CHECK_SIZE(UIPvPObserverDialog, 0x1d8);
MS2_CHECK_OFFSET(UIPvPObserverDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIPvPObserverDialog, m_1a0, 0x1a0);
MS2_CHECK_OFFSET(UIPvPObserverDialog, m_1c8, 0x1c8);
MS2_CHECK_OFFSET(UIPvPObserverDialog, m_1d4, 0x1d4);
