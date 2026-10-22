// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiadventurelevelolddialog.h (name assumed:
// the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIAdventureLevelOldDialog ("AdventureLevelOldDialog", UI type 0x4f87): the older layout of the adventure level window
// (UIAdventureLevelDialog without the mission list): the level guide ("addLevelGuide"), the level + experience gauge
// ("setLevelAndExp") and the ability list ("m_abilityList"); it sends the level reward claim (packet 0xac, operation 3).
// RTTI .?AVUIAdventureLevelOldDialog@@, 0x1c0 bytes, vftables 0x142deb988 (UIDialog), +0x18 and UIStatusEventListener at +0x178.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset>.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class ASData;
class ASObj;
class Unk_ALList;

class UIAdventureLevelOldDialog : public UIDialog, public UIStatusEventListener
{
public:
    UIAdventureLevelOldDialog();                                                                    // 0x140ba53b0
    virtual ~UIAdventureLevelOldDialog();                                                           //  0 0x140ba5460 (??_G 0x140ba6ad0)
    virtual CString vfunc_1();                                                                      //  1 0x140ba54f0
    virtual void OnLoadComplete();                                                                  // 22 0x140ba5650
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x140ba56b0
    virtual int vfunc_48() { return 0x4f87; }                                                       // 48 (COMDAT 0x140ba6b10)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);                           // 49 0x140ba5790 tooltip
    virtual int vfunc_65();                                                                         // 65 0x140ba5540
    virtual void vfunc_67();                                                                        // 67 0x140ba55a0

    // UIStatusEventListener (+0x178) overrides: 30 and 31 (refresh the lists)
    virtual void vfunc_oa0_30(int a1);                                                              // 0x140ba5950
    virtual void vfunc_oa0_31(void* a1);                                                            // 0x140ba59f0

    void FUN_140ba5a70();                                                                           // level guide when the movie is up
    void FUN_140ba5ab0();                                                                           // fill the level guide
    void FUN_140ba5c30();                                                                           // level + experience gauge
    void FUN_140ba5d20();                                                                           // fill the ability list
    int FUN_140ba61b0(ASObj& obj, unsigned int nLevel);                                             // level row: state, level text
    int FUN_140ba63d0(ASObj& obj, unsigned int nLevel);                                             // level row: item reward
    int FUN_140ba66a0(ASObj& obj, unsigned int nLevel);                                             // level row: stat reward
    void SendPrestige(unsigned int nLevel);                                                        // claim a level reward
    MS2Ptr<Unk_ALList> FUN_140ba4b70(const CString& strName);                                       // the list control of the movie (shared with UIAdventureLevelDialog)

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<void*> m_unk180;                                                                 // +0x180
    ATL::CAtlArray<CString> m_binds;                                                                // +0x1a0 names of the bound item slots
};
MS2_CHECK_SIZE(UIAdventureLevelOldDialog, 0x1c0);
MS2_CHECK_OFFSET(UIAdventureLevelOldDialog, m_unk180, 0x180);
MS2_CHECK_OFFSET(UIAdventureLevelOldDialog, m_binds, 0x1a0);
