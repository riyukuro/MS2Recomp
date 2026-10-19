// gameoptioninputdefault.h - CGameOptionInputDefault (RTTI .?AVCGameOptionInputDefault@@, bases CBaseOption + IMessageListener
// at +0x30, 0xe0 bytes): the key-binding tabs. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in
// unit `?\gameoptioninputdefault.cpp`. Header and member names are assumed. UIGameOptionDialog builds it five times as tab ids
// 9, 10, 11, 12 (gamepad feature 0xb5) and 13; the ctor and the dialog agree on (nId, nType).
// Ctor 0x141250a80 sets +0x38 = 1, +0x40 = 0, +0x58 = 0, clears the edited setting (+0x48) and builds the quick slot
// backup map (+0x98, CAtlMap(17, .75f, .25f, 2.25f, 10)).
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/baseoption.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ascript.h"

class CKeySettingParam;
class CMsgBoxData;

// The quick slot binding of one slot (0x18 bytes, ctor 0x141253e20): a skill, or an item id + uid. Same name and shape as
// client\ms2\skillslot.cpp's view.
struct Unk_SsQuickEntry
{
    int m_nSkillId;                                                 // +0x00
    __int64 m_nItemUid;                                             // +0x08
    int m_nItemId;                                                  // +0x10
    Unk_SsQuickEntry() : m_nSkillId(0), m_nItemUid(0), m_nItemId(0) {}   // 0x141253e20
};
MS2_CHECK_SIZE(Unk_SsQuickEntry, 0x18);

class CGameOptionInputDefault : public CBaseOption, public IMessageListener
{
public:
    CGameOptionInputDefault(int nId, int nType);                    // 0x141250a80
    virtual ~CGameOptionInputDefault();                             // 0x141250b90
    virtual CString vfunc_1();                                     // 0x1412521b0
    virtual void vfunc_3(int n);                                   // 0x141250c10
    virtual void vfunc_4(int n);                                   // 0x141250c80
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg);// 0x141251a30
    virtual void vfunc_6();                                        // 0x1412514e0
    virtual void vfunc_7();                                        // 0x141251510
    virtual int vfunc_8();                                         // 0x141251540
    virtual void vfunc_9();                                        // 0x141251db0
    virtual void vfunc_10();                                       // 0x141251df0
    virtual void vfunc_12();                                       // 0x141251e90
    virtual void vfunc_13();                                       // 0x141251490
    virtual int vfunc_14();                                       // 0x141251d90
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // 0x141252f20 (vfunc_o30_0)

    void FUN_141250cc0(int nCategory);                              // fill the key list of a tab
    void FUN_141252200(int nPadKind);                               // reset to the default keys
    bool FUN_1412523d0(int nButton, const CMsgBoxData& data);       // the reset confirm box answer
    void FUN_141252460();                                           // leave the key edit
    void FUN_1412524d0(__int64 nAction, int nPriority);             // unbind the action's slot
    CString FUN_141252540(__int64 nAction);                         // the action id as text
    void FUN_1412525c0(CString strAction, int nPriority);           // focus in: start editing the action's slot
    void FUN_141252700(int nKey);                                   // bind the edited slot to the key
    void FUN_141252840(int nMsgId);                                 // cancel the edit, with a notice
    void FUN_141252910();                                           // category 9: back up the quick slot keys
    void FUN_141252940();                                           // category 9: restore them
    void FUN_141252970();                                           // remember the quick slots
    void FUN_141252ae0();                                           // put the quick slots back
    int FUN_141252c10();                                            // this page is the current tab (the base input tab)
    int FUN_141252ca0();                                            // this page is the current tab
    void FUN_141252cf0(int bRelease);                               // block / release the player's keys
    int FUN_141252d40(int nKey);                                    // the key may be bound to the edited slot
    int FUN_141252ea0();                                            // the edited action is not a fixed one
    static bool FUN_1412530e0(int* pKey);                           // the key captured since the last call
    static bool FUN_1412532b0(int nKey);                            // no action uses the key
    static void FUN_1412532f0(MS2Ptr<CGameOptionInputDefault> sp); // notify the change of a page
    static void FUN_1412533f0();                                    // notify the change of every input tab

    int m_nRelease;                                                 // +0x38 1 = the player's keys are released (ctor)
    int m_bConfirm;                                                 // +0x3c a confirm box is open
    int m_bChanged;                                                 // +0x40
    int m_pad_44;
    MS2Ptr<CKeySettingParam> m_spEdit;                              // +0x48 the setting being edited
    int m_nOldKey;                                                  // +0x58 the key the edited slot had
    int m_pad_5c;
    Timer m_timer;                                                  // +0x60 re-enable delay after a bind
    ATL::CAtlMap<unsigned int, Unk_SsQuickEntry> m_mapQuickSlots;   // +0x98 quick slot -> binding
};
MS2_CHECK_SIZE(CGameOptionInputDefault, 0xe0);
MS2_CHECK_OFFSET(CGameOptionInputDefault, m_nRelease, 0x38);
MS2_CHECK_OFFSET(CGameOptionInputDefault, m_spEdit, 0x48);
MS2_CHECK_OFFSET(CGameOptionInputDefault, m_timer, 0x60);
MS2_CHECK_OFFSET(CGameOptionInputDefault, m_mapQuickSlots, 0x98);
