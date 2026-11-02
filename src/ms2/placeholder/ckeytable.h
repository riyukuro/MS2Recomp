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
class TiXmlDocument;
class CSkillSet;
class CInPacket;
struct Unk_SsQuickEntry;                                    // gameoptioninputdefault.h: one quick slot binding (0x18)

// A quick slot key id (GetBoundKeys; name from client\ms2\mypc.cpp, which declares the same enum).
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

    void OnKeyTable(CInPacket& packet);                  // the key table packet
    void SendKeyTableMode1(int nKey);                           // send one binding
    void SendKeysToServer();                                   // apply / save the edited bindings
    int FUN_1414297e0(const CString& strPath, int n);       // load the default key file
    int FUN_141429e60(const CString& strPath);              // load a default gamepad key file
    void BackupKeys();                                   // category 9: back up the bindings
    void RestoreKeysFromBackup();                                   // category 9: restore them
    void ClearAllBindings();                                   // clear every binding
    void FUN_14142a8b0(__int64 nAction);                    // the action's binding changed
    void InitKeys();                                   // build the key list
    int FUN_14142b1c0(int nKey, int nType, __int64 nAction, int n, int nPriority, int nOldKey);   // bind; 0 = failed
    int SetKeyBindingAndSync(int nKey, int nType, __int64 nAction, int nSlot, int nPriority);
    int FUN_14142b300(int nKey);
    int ExecuteActionKey(int nAction);                         // run a key action
    void SetMode(int nMode);
    int GetMode();
    void FUN_14142bb10();                                   // use the quick slots of the pressed keys
    int IsSkillKeyDown(int nSkillId);                        // the skill's key is held
    int IsActionKeyDown(int nAction);                         // the action's key is held
    int IsSkillKeyPressed(int nSkillId);                        // the skill's key was pressed
    int IsActionKeyPressed(int nAction);                         // the action's key was pressed
    int IsActionKeyReleased(int nAction);                         // the action's key was released
    void GetBoundKeys(ATL::CAtlArray<Unk_MyPCKeyId>& aOut);       // the quick slot keys
    void FUN_14142c6c0(ATL::CAtlArray<Unk_MyPCKeyId>& aOut, int nSkillId);   // the keys of a skill
    int GetPairKey(int nKey, int& nPair);                // the twin modifier key
    MS2Ptr<stKeyData> FindKeyData(int nKey);              // the binding of a key
    int FUN_14142c940(__int64 nAction, int nPriority);      // the key bound to the action, 0 = none
    int FUN_14142ca40(int nId, int nPriority);
    int FindKeyByQuickSlot(unsigned nIndex, int nPriority);      // the key of a quick slot action
    size_t GetQuickSlotActionCount();                                 // the quick slot action count
    __int64 GetQuickSlotAction(unsigned nIndex);                 // a quick slot action
    int IsKeyRebindable(int nKey);                            // the key can be bound
    int IsKeyBound(int nKey);
    int IsKeyBoundToAction(int nKey, int nAction);
    int IsQuickSlotKey(int nKey);                            // the key is a quick slot key
    int IsQuickSlotAction(__int64 nAction);                     // the action is a quick slot action
    int IsKeyEntryValid(MS2Ptr<stKeyData> spKey);             // the binding is usable
    int GetKeyType(int nKey);                            // the binding type of a key
    __int64 GetKeyAction(int nKey);                        // the action bound to the key, 0 = none
    CStringW GetKeyName(int nKey);                       // the key's display name
    CStringW GetKeyDisplayName(int nKey);
    CStringW GetActionKeyName(int nAction, int nPriority);     // the key name of a binding
    CStringW GetKeyActionLabel(const int& nKey);
    int GetKeySkillId(stKeyData* pKey);
    int FUN_14142dad0(unsigned nSlot);                      // the skill id of the quick slot
    int GetQuickSlotSkillId(unsigned nSlot);                      // the skill id of a slot of the current page
    int FindQuickSlotIndexByKey(int nKey, int& nIndex);               // the quick slot action index of a key
    __int64 GetQuickSlotItemUidByKey(unsigned nSlot);                  // the item uid of the quick slot
    int GetQuickSlotItemIdByKey(unsigned nKey);                       // the item id of the key's quick slot
    bool GetQuickSlotEntry(unsigned nSlot, Unk_SsQuickEntry& entry);   // a slot of the current page
    int FindQuickSlotBySkillAndItemUid(int nSkillId, __int64 nItemUid);      // the quick slot holding them, -1 = none
    int FindQuickSlotBySkillAndItem(int nSkillId, int nItemId, __int64 nItemUid);
    int FindQuickSlotActionIndex(__int64 nAction);                     // the quick slot index of an action, -1 = none
    void SetQuickSlotEntry(unsigned nSlot, const Unk_SsQuickEntry& entry);
    void SetQuickSlotEntryOnPage(int nPage, unsigned nSlot, const Unk_SsQuickEntry& entry);
    int FindActiveKey(int bPressed);                         // the key pressed (key capture)
    int FindActiveComboPrefixKey(int bPressed);                         // the key held (key capture)
    bool IsComboKeyValid(unsigned nCombo);                    // both keys of a modifier combo are known
    void GetKeysForAction(__int64 nAction, ATL::CAtlArray<Unk_MyPCKeyId>& aOut);   // the keys bound to the action
    int IsShortKey(int nKey);
    void AddShortKey(int nKey);
    void RemoveShortKey(int nKey);
    int GetLocked();
    void ApplySkillSetToQuickSlots(MS2Ptr<CSkillSet> spSet);            // enter the skill set mode: the set fills the quick slots
    void ApplyItemListToQuickSlots(const ATL::CAtlArray<unsigned>& aItemIds);   // enter the skill set mode with these items in the quick slots
    int HasSkillSlotMatch(int nSkillId, int nItemId, __int64 nItemUid, unsigned nCount);   // a quick slot of the set holds it
    void FUN_14142ef50(int nSkillId, int nItemId, __int64 nItemUid, unsigned nCount);  // put it into a free quick slot (set mode)
    void FUN_14142f1c0(int nSkillId, int nItemId, __int64 nItemUid);   // put it into its job quick slot
    void FUN_14142f470(int nPage, int nSlot);              // put the job item of the slot into the page
    void SaveKeySetting(CString strName);                   // save the skill set layout (keySetting_<name>.xml)
    void LoadKeySetting(CString strName);                   // load the skill set layout (keySetting_<name>.xml)
    void SendKeyTableMode7();                                   // leave the skill set mode and save
    int FUN_14142f830(int nSlot);
    int FUN_14142f870(int nSlot);
    int FUN_141430470(__int64 nAction);
    MS2Ptr<CKeySettingParam> FindSettingParam(__int64 nAction) const;     // the setting of the action
    SettingList GetSettingList(int nCategory);               // the settings of a tab
    int LoadKeySettingTable();                                     // load Table/keySetting.xml into m_settings
    void FUN_1414307a0();                                   // build the setting categories
    int FUN_141430b10(__int64 nAction);
    int FUN_141430b90(int nKey);
    int FUN_141430c30(int nKey);
    int FUN_141430cb0(int nKey);
    void FUN_141430d30(__int64 nAction, int nKey, int nPriority, int nOldKey);
    unsigned* MakeCombineKey(unsigned* pOut, int nFirst, int nSecond, int nMode);
    CStringW CreateCombineKeyString(int nFirst, int nSecond);
    void SplitCombineKey(unsigned nKey, int* pFirst, int* pSecond);
    void FUN_1414310f0(int nKey, int nOtherKey, __int64 nAction, __int64 nOtherAction);   // swap the modifier combos
    void FUN_1414316e0(int nKey, __int64 nAction);          // unbind the modifier combos of a key
    __int64 FUN_1414317b0(__int64 nAction);
    CStringW FUN_141431820(int nKey);                       // the key's label (gamepad: L1/L2/R1/R2)
    int FUN_1414319f0();                                    // the input layout (2 = gamepad keys >= 0x91)
    int FUN_141431a30(int nKey);
    int FUN_141431a60(int nKey);
    int IsGamepadKey(int nKey);                            // the key is reserved
    void FUN_141431ae0(int nPage, bool bSend);               // switch the quick slot page
    QuickSlotPage* FUN_141431c20(int nPage);                // a quick slot page
    int FUN_141431c80(int nKey, int nType, __int64 nCode, int nSlot, int nPriority, int bSave);   // set a binding
    void FUN_141431f20(int nKey);                           // notify the key (and its twin) changed
    int FUN_141431fc0();
    int FUN_141432010(int nAction);
    void FUN_1414321f0();                                   // rebuild the action index
    void FUN_141432360(int nAction);
    void FUN_1414323f0(int nPage, unsigned nSlot, int nSkillId, int nItemId, __int64 nItemUid);   // set a quick slot
    TiXmlDocument FUN_141432480(const CString& strPath);    // write an empty key config (ms2/KeyConfig) to the file
    static int FUN_141432650(int nCode);
    int FUN_140a700b0();                                    // the current quick slot page

    int m_nLoaded;                                          // +0x08 the server's table arrived
    int m_bDirty;                                           // +0x0c the bindings changed (SendKeysToServer sends them)
    int m_nMode;                                            // +0x10 (ctor 1)
    int m_nLocked;                                          // +0x14 nonzero: nothing is sent
    ATL::CRBMap<unsigned int, unsigned int> m_18;           // +0x18
    KeyMap m_keys;                                          // +0x48 key code -> binding
    KeyMap m_keysBackup;                                    // +0x78 (BackupKeys / RestoreKeysFromBackup)
    ATL::CRBMultiMap<unsigned __int64, int, ATL::CElementTraits<unsigned __int64>, KeyTraits> m_actionKeys; // +0xa8 action -> keys
    ATL::CRBMultiMap<unsigned int, int, ATL::CElementTraits<unsigned int>, KeyTraits> m_d8; // +0xd8 slot -> keys
    KeyPairMap m_pairKeys;                                  // +0x108 left/right modifier twins
    KeyPairMap m_shortKeys;                                 // +0x150
    int m_nQuickSlotPage;                                   // +0x198
    ATL::CAtlArray<QuickSlotPage> m_quickSlots;             // +0x1a0 quick slot pages
    ATL::CAtlArray<__int64> m_quickSlotActions;             // +0x1c0
    ATL::CAtlArray<__int64> m_1e0;                          // +0x1e0
    ATL::CAtlArray<Unk_MyPCKeyId> m_200;                              // +0x200
    ATL::CAtlArray<Unk_MyPCKeyId> m_220;                              // +0x220
    ATL::CAtlArray<Unk_MyPCKeyId> m_240;                              // +0x240
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
