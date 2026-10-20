// ckeytable.h - PLACEHOLDER for CKeyTable (RTTI .?AVCKeyTable@@, 0x2a8 bytes, vftable 0x142f12de0). NOT an original header.
// Bases: TSingleton<CKeyTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the key bindings (key code -> stKeyData: action id +
// priority slot 0..2), the key-setting categories (tab ids 9..13) and the quick slot pages. The methods live in
// client\ms2\keytable.cpp; layout recovered from the ctor 0x141428830 / dtor 0x141428a70 and the container glue
// (w493). Member names are invented from their use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tptrvalue.h"

class CKeySettingParam;
class CInPacket;
struct Unk_SsQuickEntry;                                    // gameoptioninputdefault.h: one quick slot binding (0x18)

// A quick slot key id (FUN_14142c5d0; name from client\ms2\mypc.cpp, which declares the same enum).
enum Unk_MyPCKeyId { MYPC_KEY_NONE = 0 };

class CKeyTable : public TSingleton<CKeyTable>
{
public:
    // CKeyTable::stKeyData (RTTI .?AVstKeyData@CKeyTable@@, CPtred, 0x38, ??_G 0x141436340): one key and its binding.
    class stKeyData : public CPtred
    {
    public:
        stKeyData();                                        // 0x1414286a0
        stKeyData(const CStringW& strName);                 // 0x141428730
        int FUN_1414287c0(int nType, __int64 nCode, int nSlot, int nPriority);   // the binding equals
        CStringW m_strName;                                 // +0x18 the key's display name
        int m_nType;                                        // +0x20 binding type (0 = unbound)
        __int64 m_nCode;                                    // +0x28 action id ("code")
        int m_nPriority;                                    // +0x30 primary (0) / secondary (1) / thirdly (2)
        int m_nSlot;                                        // +0x34
    };
    // The key codes are an enum in the source: the exe's containers take them by reference, which
    // CDefaultElementTraits<int> reproduces (same hash / ordering code) while keeping the int signatures.
    typedef ATL::CDefaultElementTraits<int> KeyTraits;
    typedef ATL::CRBMap<int, MS2Ptr<stKeyData>, KeyTraits> KeyMap;
    typedef ATL::CAtlMap<int, int, KeyTraits, KeyTraits> KeyPairMap;
    typedef ATL::CAtlMap<unsigned int, Unk_SsQuickEntry> QuickSlotPage;
    typedef TPtrValue<ATL::CAtlList<MS2Ptr<CKeySettingParam> > > SettingList;

    CKeyTable();                                            // 0x141428830
    virtual ~CKeyTable();                                   // 0x141428a70

    void FUN_141428bb0(CInPacket& packet);                  // the key table packet
    void FUN_1414294e0(int nKey);                           // send one binding
    void FUN_141429600();                                   // apply / save the edited bindings
    int FUN_1414297e0(const CString& strPath, int n);       // load the default key file
    int FUN_141429e60(const CString& strPath);              // load a default gamepad key file
    void FUN_14142a510();                                   // category 9: back up the bindings
    void FUN_14142a680();                                   // category 9: restore them
    void FUN_14142a800();                                   // clear every binding
    void FUN_14142a8b0(__int64 nAction);                    // the action's binding changed
    void FUN_14142a910();                                   // build the key list
    int FUN_14142b1c0(int nKey, int nType, __int64 nAction, int n, int nPriority, int nOldKey);   // bind; 0 = failed
    int FUN_14142b250(int nKey, int nType, __int64 nAction, int nSlot, int nPriority);
    int FUN_14142b300(int nKey);
    int FUN_14142b340(int nAction);                         // run a key action
    void FUN_14142bad0(int nMode);
    int FUN_14142baf0();
    void FUN_14142bb10();                                   // use the quick slots of the pressed keys
    int FUN_14142c0c0(int nSkillId);                        // the skill's key is held
    int FUN_14142c270(int nAction);                         // the action's key is held
    int FUN_14142c300(int nSkillId);                        // the skill's key was pressed
    int FUN_14142c4b0(int nAction);                         // the action's key was pressed
    int FUN_14142c540(int nAction);                         // the action's key was released
    void FUN_14142c5d0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut);       // the quick slot keys
    void FUN_14142c6c0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut, int nSkillId);   // the keys of a skill
    int FUN_14142c830(int nKey, int& nPair);                // the twin modifier key
    MS2Ptr<stKeyData> FUN_14142c890(int nKey);              // the binding of a key
    int FUN_14142c940(__int64 nAction, int nPriority);      // the key bound to the action, 0 = none
    int FUN_14142ca40(int nId, int nPriority);
    int FUN_14142cb40(unsigned nIndex, int nPriority);      // the key of a quick slot action
    size_t FUN_14142cbb0();                                 // the quick slot action count
    __int64 FUN_14142cbe0(unsigned nIndex);                 // a quick slot action
    int FUN_14142cc40(int nKey);                            // the key can be bound
    int FUN_14142cca0(int nKey);
    int FUN_14142cd50(int nKey, int nAction);
    int FUN_14142ce10(int nKey);                            // the key is a quick slot key
    int FUN_14142cf10(__int64 nAction);                     // the action is a quick slot action
    int FUN_14142cf60(MS2Ptr<stKeyData> spKey);             // the binding is usable
    int FUN_14142d100(int nKey);                            // the binding type of a key
    __int64 FUN_14142d190(int nKey);                        // the action bound to the key, 0 = none
    CStringW FUN_14142d220(int nKey);                       // the key's display name
    CStringW FUN_14142d580(int nKey);
    CStringW FUN_14142d760(int nAction, int nPriority);     // the key name of a binding
    CStringW FUN_14142d7e0(const int& nKey);
    int FUN_14142d9b0(stKeyData* pKey);
    int FUN_14142dad0(unsigned nSlot);                      // the skill id of the quick slot
    int FUN_14142dc50(unsigned nSlot);                      // the skill id of a slot of the current page
    int FUN_14142dcb0(int nKey, int& nIndex);               // the quick slot action index of a key
    __int64 FUN_14142ded0(unsigned nSlot);                  // the item uid of the quick slot
    bool FUN_14142e030(unsigned nSlot, Unk_SsQuickEntry& entry);   // a slot of the current page
    int FUN_14142e090(int nSkillId, __int64 nItemUid);      // the quick slot holding them, -1 = none
    int FUN_14142e150(int nSkillId, int nItemId, __int64 nItemUid);
    int FUN_14142e220(__int64 nAction);                     // the quick slot index of an action, -1 = none
    void FUN_14142e2a0(unsigned nSlot, const Unk_SsQuickEntry& entry);
    void FUN_14142e2e0(int nPage, unsigned nSlot, const Unk_SsQuickEntry& entry);
    int FUN_14142e340(int n);                               // the key pressed (key capture)
    int FUN_14142e470(int n);                               // the key held (key capture)
    int FUN_14142e6f0(int nKey);
    void FUN_14142e730(int nKey);
    void FUN_14142e770(int nKey);
    int FUN_14142e7a0();
    int FUN_141430470(__int64 nAction);
    MS2Ptr<CKeySettingParam> FUN_141430590(__int64 nAction);       // the setting of the action
    SettingList FUN_141430710(int nCategory);               // the settings of a tab
    void FUN_14142fff0();
    void FUN_1414307a0();                                   // build the setting categories
    int FUN_141430b10(__int64 nAction);
    int FUN_141430b90(int nKey);
    int FUN_141430c30(int nKey);
    int FUN_141430cb0(int nKey);
    void FUN_141430d30(__int64 nAction, int nKey, int nPriority, int nOldKey);
    unsigned* FUN_141430e70(unsigned* pOut, int nFirst, int nSecond, unsigned char nMode);
    CStringW FUN_141430ee0(int nFirst, int nSecond);
    void FUN_1414310a0(unsigned nKey, int* pFirst, int* pSecond);
    __int64 FUN_1414317b0(__int64 nAction);
    int FUN_1414319f0();                                    // the input layout (2 = gamepad keys >= 0x91)
    int FUN_141431a30(int nKey);
    int FUN_141431a60(int nKey);
    int FUN_141431a90(int nKey);                            // the key is reserved
    void FUN_141431ae0(int nPage, int bSend);               // switch the quick slot page
    QuickSlotPage* FUN_141431c20(int nPage);                // a quick slot page
    int FUN_141431c80(int nKey, int nType, __int64 nCode, int nSlot, int nPriority, int bSave);   // set a binding
    int FUN_141431fc0();
    int FUN_141432010(int nAction);
    void FUN_1414321f0();                                   // rebuild the action index
    void FUN_141432360(int nAction);
    void FUN_1414323f0(int nPage, unsigned nSlot, int nSkillId, int nItemId, __int64 nItemUid);   // set a quick slot
    int FUN_140a700b0();                                    // the current quick slot page

    int m_nLoaded;                                          // +0x08 the server's table arrived
    int m_bDirty;                                           // +0x0c the bindings changed (FUN_141429600 sends them)
    int m_nMode;                                            // +0x10 (ctor 1)
    int m_nLocked;                                          // +0x14 nonzero: nothing is sent
    ATL::CRBMap<unsigned int, unsigned int> m_18;           // +0x18
    KeyMap m_keys;                                          // +0x48 key code -> binding
    KeyMap m_keysBackup;                                    // +0x78 (FUN_14142a510 / FUN_14142a680)
    ATL::CRBMultiMap<__int64, int, ATL::CElementTraits<__int64>, KeyTraits> m_actionKeys;   // +0xa8 action -> keys
    ATL::CRBMultiMap<unsigned int, int, ATL::CElementTraits<unsigned int>, KeyTraits> m_d8; // +0xd8 slot -> keys
    KeyPairMap m_pairKeys;                                  // +0x108 left/right modifier twins
    KeyPairMap m_shortKeys;                                 // +0x150
    int m_nQuickSlotPage;                                   // +0x198
    ATL::CAtlArray<QuickSlotPage> m_quickSlots;             // +0x1a0 quick slot pages
    ATL::CAtlArray<__int64> m_quickSlotActions;             // +0x1c0
    ATL::CAtlArray<__int64> m_1e0;                          // +0x1e0
    ATL::CAtlArray<int> m_200;                              // +0x200
    ATL::CAtlArray<int> m_220;                              // +0x220
    ATL::CAtlArray<int> m_240;                              // +0x240
    ATL::CAtlMap<int, SettingList> m_settings;              // +0x260 category -> settings
};
MS2_CHECK_SIZE(CKeyTable, 0x2a8);
MS2_CHECK_SIZE(CKeyTable::stKeyData, 0x38);
MS2_CHECK_OFFSET(CKeyTable, m_18, 0x18);
MS2_CHECK_OFFSET(CKeyTable, m_actionKeys, 0xa8);
MS2_CHECK_OFFSET(CKeyTable, m_pairKeys, 0x108);
MS2_CHECK_OFFSET(CKeyTable, m_nQuickSlotPage, 0x198);
MS2_CHECK_OFFSET(CKeyTable, m_quickSlots, 0x1a0);
MS2_CHECK_OFFSET(CKeyTable, m_settings, 0x260);

CKeyTable* FUN_1409331f0();                                     // the instance
