// ckeytable.h - PLACEHOLDER for CKeyTable (RTTI .?AVCKeyTable@@, 0x2a8 bytes). NOT an original header.
// Bases: TSingleton<CKeyTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the key bindings (action id -> key code per priority
// slot 0..2), the key-setting categories (tab ids 9..13) and the quick slots. Only the ctor and the members other units
// call are declared (FUN_<va> names, meaning in the comment); the layout is not recovered.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tptrvalue.h"

class CKeySettingParam;

// A quick slot key id (FUN_14142c5d0; name from client\ms2\mypc.cpp, which declares the same enum).
enum Unk_MyPCKeyId { MYPC_KEY_NONE = 0 };

class CKeyTable : public TSingleton<CKeyTable>
{
public:
    CKeyTable();                                            // 0x141428830
    virtual ~CKeyTable();

    // appended by ?\gameoptioninputdefault.cpp (w471); signatures from its call sites
    void FUN_1414297e0(const CString& strPath, int n);             // load the default key file
    void FUN_141429600();                                          // apply / save the edited bindings
    void FUN_141429e60(const CString& strPath);                    // load a default gamepad key file
    void FUN_14142a510();                                          // category 9: back up the quick slot keys
    void FUN_14142a680();                                          // category 9: restore them
    void FUN_14142a8b0(__int64 nAction);                           // the action's binding changed
    int FUN_14142b1c0(int nKey, int nType, __int64 nAction, int n, int nPriority, int nOldKey);   // bind; 0 = failed
    void FUN_14142c5d0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut);       // the quick slot keys
    int FUN_14142c940(__int64 nAction, int nPriority);             // the key bound to the action, 0 = none
    int FUN_14142cc40(int nKey);                                   // the key can be bound
    int FUN_14142cf10(__int64 nAction);
    __int64 FUN_14142d190(int nKey);                               // the action bound to the key, 0 = none
    CStringW FUN_14142d220(int nKey);                              // the key's display name
    int FUN_14142dad0(unsigned nSlot);                             // the skill id of the quick slot
    __int64 FUN_14142ded0(unsigned nSlot);                         // the item uid of the quick slot
    int FUN_14142e090(int nSkillId, __int64 nItemUid);             // the quick slot holding them, -1 = none
    int FUN_14142e340(int n);                                      // the key pressed (key capture)
    int FUN_14142e470(int n);                                      // the key held (key capture)
    int FUN_141430470(__int64 nAction);
    MS2Ptr<CKeySettingParam> FUN_141430590(__int64 nAction);       // the setting of the action
    TPtrValue<ATL::CAtlList<MS2Ptr<CKeySettingParam> > > FUN_141430710(int nCategory);   // the settings of a tab
    int FUN_141430b10(__int64 nAction);
    int FUN_141430b90(int nKey);
    int FUN_141430c30(int nKey);
    int FUN_141430cb0(int nKey);
    int FUN_1414319f0();                                           // the input layout (2 = gamepad keys >= 0x91)
    int FUN_141431a90(int nKey);                                   // the key is reserved
    int FUN_140a700b0();                                           // the current quick slot page
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x2a8 - 0x8];
};
MS2_CHECK_SIZE(CKeyTable, 0x2a8);

CKeyTable* FUN_1409331f0();                                     // the instance
