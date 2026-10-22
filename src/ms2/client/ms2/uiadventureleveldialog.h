// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiadventureleveldialog.h (name assumed:
// the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIAdventureLevelDialog ("AdventureLevelDialog", UI type 0x4f67): the adventure level window. It lists the level guide
// ("addLevelGuide": level rows with item / stat rewards), the level + experience gauge ("setLevelAndExp"), the ability
// list ("m_abilityList") and the mission list ("m_missionList"), and sends the reward claims (packet 0xac, operations
// 3 and 5). RTTI .?AVUIAdventureLevelDialog@@, 0x1a0 bytes, vftables 0x142deb238 (UIDialog), 0x142deb4e0 (+0x18) and
// 0x142deb4f0 (UIStatusEventListener at +0x178).
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

class UIAdventureLevelDialog : public UIDialog, public UIStatusEventListener
{
public:
    UIAdventureLevelDialog();                                                                       // 0x140ba2a80
    virtual ~UIAdventureLevelDialog();                                                              //  0 0x140ba2b20 (??_G 0x140ba4f60)
    virtual CString GetTypeName();                                                                      //  1 0x140ba2ba0
    virtual void OnLoadComplete();                                                                  // 22 0x140ba2d00
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x140ba2d70
    virtual int vfunc_48() { return 0x4f67; }                                                       // 48 (COMDAT 0x140ba4fb0)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);                           // 49 0x140ba2ee0 tooltip
    virtual int vfunc_65();                                                                         // 65 0x140ba2bf0
    virtual void vfunc_67();                                                                        // 67 0x140ba2c50

    // UIStatusEventListener (+0x178) overrides: 3, 4, 9 (empty), 30 and 31 (refresh the lists)
    virtual void vfunc_oa0_3(int a1, int a2) {}                                                     // COMDAT 0x140ba4fc0
    virtual void vfunc_oa0_4(int a1, int a2) {}                                                     // COMDAT 0x140ba4fe0
    virtual void vfunc_oa0_9(unsigned short a1) {}                                                  // COMDAT 0x140ba4fd0
    virtual void vfunc_oa0_30(int a1);                                                              // 0x140ba30a0
    virtual void vfunc_oa0_31(void* a1);                                                            // 0x140ba3140

    void FUN_140ba31c0();                                                                           // level guide when the movie is up
    void FUN_140ba3200();                                                                           // mission list when the movie is up
    int FUN_140ba3240();                                                                            // missions done but not yet claimed
    void FUN_140ba3330();                                                                           // fill the level guide
    void FUN_140ba34b0();                                                                           // level + experience gauge
    void FUN_140ba35a0();                                                                           // fill the ability list
    void FUN_140ba3a30();                                                                           // fill the mission list
    int FUN_140ba3d60(ASObj& obj, unsigned int nLevel);                                             // level row: state, level text
    int FUN_140ba3f80(ASObj& obj, unsigned int nLevel);                                             // level row: item reward
    int FUN_140ba4250(ASObj& obj, unsigned int nLevel);                                             // level row: stat reward
    int FUN_140ba45c0(ASObj& obj, unsigned int nMissionId);                                         // mission row: item reward
    void FUN_140ba4960(unsigned int nLevel);                                                        // claim a level reward
    void FUN_140ba4a10(unsigned int nMissionId);                                                    // claim a mission reward
    MS2Ptr<Unk_ALList> FUN_140ba4b70(const CString& strName);                                       // the list control of the movie

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<CString> m_binds;                                                                // +0x180 names of the bound item slots
};
MS2_CHECK_SIZE(UIAdventureLevelDialog, 0x1a0);
MS2_CHECK_OFFSET(UIAdventureLevelDialog, m_binds, 0x180);
