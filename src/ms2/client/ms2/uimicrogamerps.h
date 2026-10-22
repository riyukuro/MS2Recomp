// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimicrogamerps.h (name assumed:
// the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIMicroGameRps is the HUD of the rock-paper-scissors micro game. RTTI .?AVUIMicroGameRps@@, 0x78 bytes, vftables
// 0x142e50ef8 (primary) and 0x142e510a0 (IMessageListener at +0x18). It is a UIHeadUpDisplay with one new field
// (m_70, the selected card). Member names are invented where the exe has no name (FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class UIMicroGameRps : public UIHeadUpDisplay
{
public:
    UIMicroGameRps();

    virtual CString vfunc_1();                                                  //  1 "MicroGameRps"
    virtual void vfunc_2();                                                     //  2
    virtual void vfunc_3();                                                     //  3
    virtual void vfunc_15();                                                    // 15 per-frame: centre the entity / hide
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28
    virtual void vfunc_41(const Scaleform::GFx::Value& root);                   // 41
    virtual void vfunc_43();                                                    // 43 empty
    virtual int vfunc_48() { return 20320; }                                    // 48 UI type id (COMDAT 0x140e667c0)

    void FUN_140e66330();                                                       // popUp
    void FUN_140e663b0();                                                       // hide
    void FUN_140e664a0();                                                       // centre the game entity on screen
    void FUN_140e665e0(int nCard);                                              // m_70 = nCard
    void SendMicrogame();                                                       // onSelectTimeUp: send the selection
    void FUN_140e666a0();                                                       // onRandChat
    int FUN_140e66710();                                                        // not in the micro game state?

private:
    MS2_LAYOUT_FRIEND;
    int m_nCard;                        // +0x70 selected card (-1 = none yet)
};
MS2_CHECK_SIZE(UIMicroGameRps, 0x78);
MS2_CHECK_OFFSET(UIMicroGameRps, m_nCard, 0x70);
