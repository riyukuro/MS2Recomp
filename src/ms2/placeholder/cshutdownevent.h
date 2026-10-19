// cshutdownevent.h - PLACEHOLDER for the CShutdownEvent* members of CGameEventValueManager (RTTI
// .?AVCShutdownEventInteractObject@@, .?AVCShutdownEventFunctionItem@@, .?AV?$CShutdownEventKeyCountMap@IH@@, ...).
// NOT an original header. Each one is a CPtred with a CLockCriticalSection at +0x18 and a container at +0x48; their
// ctors are in the shutdown event TU (0x1407d00f0.., commonfiles\shutdowneventvalue.cpp) and in the manager TU
// (0x14046d570). The implicit dtors are the manager TU's COMDATs (?\gameeventvaluemanager.cpp, 0x14046e2c0..).
// The container types come from those dtors' callees (w268): a map<unsigned long, int> dtor 0x14025c810, the
// CAtlMap<int, int> dtor 0x1401642a0.
#pragma once

#include <map>
#include <vector>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"

// Shutdown count per key: a key is shut down while its count is non-zero. vftable 0x142d499d0 (only ??_G).
// The map key is DWORD (unsigned long), not K: the exe's operator[] / end() this code calls (0x1403e89a0, 0x140265e30)
// are the map<unsigned long, int> copies of the symbol table (unit_1403e8960), byte-identical to but distinct from the
// map<unsigned int, int> family (client\ms2\gameobject.cpp, 0x140a4xxxx / 0x14123ed20), and the key is passed
// straight to operator[] (no conversion temporary).
template <class K, class V>
class CShutdownEventKeyCountMap : public CPtred
{
public:
    // @0x14046d570
    CShutdownEventKeyCountMap() {}                          // K = unsigned, V = int
    // @0x1403f3150
    bool SetShutdown(unsigned long key)
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        m_counts[key]++;
        return true;
    }
    // @0x1403f24d0
    void ResetShutdown(unsigned long key)
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        if (m_counts.find(key) == m_counts.end())
            return;
        V count = m_counts[key];
        if (count < 2)
            m_counts.erase(key);
        else
            m_counts[key]--;
    }
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    std::map<unsigned long, V> m_counts;                    // +0x48
};
typedef CShutdownEventKeyCountMap<unsigned int, int> CShutdownEventKeyCountMapUInt;
MS2_CHECK_SIZE(CShutdownEventKeyCountMapUInt, 0x58);

// Shut down drop box ids (CGameEventValueManager +0xe58; dtor 0x14046e300 calls the map<unsigned long, int> dtor).
class CShutdownEventDropBox : public CPtred
{
public:
    CShutdownEventDropBox();                                // 0x1407d00f0
    bool FUN_1407d0150(unsigned long nBoxId);               // 0x1407d0150 shut a box down
    void FUN_1407d01d0(unsigned long nBoxId);               // 0x1407d01d0 undo one shut down
    bool IsShutdown(unsigned long nBoxId);                     // 0x1407d02e0
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    std::map<unsigned long, int> m_ids;                     // +0x48
};
MS2_CHECK_SIZE(CShutdownEventDropBox, 0x58);

// Shut down interact objects (vftable written by 0x1407d03c0; dtor 0x14046e3b0): count per (field id, object id).
// The map's nodes hold a 4-aligned 12-byte value (0x14046e3b0 -> 0x140470710 `add rax, 0x1c`), the key is built by
// pair<unsigned, int>(unsigned&, int&) (0x14015e2a0) and the value is a counter (`++m[key]`). Its tree glue is a fresh
// instantiation here, so the value is neither int (map<pair<unsigned,int>,int> dtor 0x1401644a0) nor unsigned
// (0x140410430): long is assumed (any other 4-byte counter type gives the same code).
class CShutdownEventInteractObject : public CPtred
{
public:
    CShutdownEventInteractObject();                         // 0x1407d03c0
    bool FUN_1407d0420(unsigned nFieldId, int nObjectId);   // 0x1407d0420 shut an object down
    void FUN_1407d04c0(unsigned nFieldId, int nObjectId);   // 0x1407d04c0 undo one shut down
    bool FUN_1407d05e0(unsigned nFieldId, int nObjectId);   // 0x1407d05e0 is the object shut down
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    std::map<std::pair<unsigned, int>, long> m_objects;     // +0x48
};
MS2_CHECK_SIZE(CShutdownEventInteractObject, 0x58);

// Shut down function items (ctor 0x1407d0bd0; dtor 0x14046e340 calls the map<unsigned long, int> dtor).
class CShutdownEventFunctionItem : public CPtred
{
public:
    CShutdownEventFunctionItem();                           // 0x1407d0bd0
    bool FUN_1407d0c30(unsigned long nItemId);              // 0x1407d0c30 shut a function item down
    void FUN_1407d0cb0(unsigned long nItemId);              // 0x1407d0cb0 undo one shut down
    bool FUN_1407d0dc0(unsigned long nItemId);              // 0x1407d0dc0 is the item shut down
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    std::map<unsigned long, int> m_items;                   // +0x48
};
MS2_CHECK_SIZE(CShutdownEventFunctionItem, 0x58);

// The id key of CShutdownEventQuest's second map (an enum: its CAtlMap is a separate instantiation, dtor 0x14046da60
// beside the shared CAtlMap<int, int> one). Name invented.
enum Unk_ShutdownQuestKey
{
};
// Shut down quests (ctor 0x1407d06d0; dtor 0x14046e500).
class CShutdownEventQuest : public CPtred
{
public:
    CShutdownEventQuest();                                  // 0x1407d06d0
    int FUN_1407d07a0(int nQuestId);                        // 0x1407d07a0
    void FUN_1407d0810(int nQuestId);                       // 0x1407d0810
    int FUN_1407d0870(Unk_ShutdownQuestKey eKey);           // 0x1407d0870
    void FUN_1407d08f0(Unk_ShutdownQuestKey eKey);          // 0x1407d08f0
    int FUN_1407d0950(int nQuestId);                        // 0x1407d0950 is the quest shut down
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    ATL::CAtlMap<int, int> m_quests;                        // +0x48
    ATL::CAtlMap<Unk_ShutdownQuestKey, int> m_keys;         // +0x90
};
MS2_CHECK_SIZE(CShutdownEventQuest, 0xd8);

// Shut down item transfers (ctor 0x1407d09f0; dtor 0x14046e430).
class CShutdownEventItemTransfer : public CPtred
{
public:
    CShutdownEventItemTransfer();                           // 0x1407d09f0
    int FUN_1407d0a80(int nKey);                            // 0x1407d0a80
    void FUN_1407d0af0(int nKey);                           // 0x1407d0af0
    int FUN_1407d0b50(int nKey);                            // 0x1407d0b50
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    ATL::CAtlMap<int, int> m_items;                         // +0x48
};
MS2_CHECK_SIZE(CShutdownEventItemTransfer, 0x90);

// Shut down couple emotions (ctor 0x1407d0ea0; dtor 0x14046e2c0).
class CShutdownEventCoupleEmotion : public CPtred
{
public:
    CShutdownEventCoupleEmotion();                          // 0x1407d0ea0
    int FUN_1407d0f30(int nKey);                            // 0x1407d0f30
    void FUN_1407d0fa0(int nKey);                           // 0x1407d0fa0
    int FUN_1407d1000(int nKey);                            // 0x1407d1000
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    ATL::CAtlMap<int, int> m_emotions;                      // +0x48
};
MS2_CHECK_SIZE(CShutdownEventCoupleEmotion, 0x90);

// Shut down item remake options (ctor 0x1407d1470; dtor 0x14046e3f0).
class CShutdownEventItemRemakeOption : public CPtred
{
public:
    CShutdownEventItemRemakeOption();                       // 0x1407d1470
    int FUN_1407d1500(int nKey);                            // 0x1407d1500 shut an option down
    void FUN_1407d1570(int nKey);                           // 0x1407d1570 undo it
    int FUN_1407d15d0(int nKey);                            // 0x1407d15d0 the shut down value (0 if none)
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    ATL::CAtlMap<int, int> m_options;                       // +0x48
};
MS2_CHECK_SIZE(CShutdownEventItemRemakeOption, 0x90);

// One shut down value of CShutdownEventGroup (GameEventShutdown* add / remove ids: 0x1407d10e0 / 0x1407d1160).
class CShutdownEventValue : public CPtred
{
public:
    CShutdownEventValue();                                  // 0x1407d1080
    void FUN_1407d10e0(unsigned long nId);                            // 0x1407d10e0 count one more shut down of the id
    void FUN_1407d1160(unsigned long nId);                            // 0x1407d1160 undo one (drops the id at zero)
    bool FUN_1407d1210(unsigned long nId);                            // 0x1407d1210 the id is shut down
    bool FUN_1407d12b0();                                   // 0x1407d12b0 any id is shut down
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    std::map<unsigned long, unsigned long> m_ids;           // +0x48 (the exe map is <DWORD, DWORD>: 0x140445750 / 0x140446b20)
};
MS2_CHECK_SIZE(CShutdownEventValue, 0x58);

// The 12 shut down values by kind (ctor 0x1407d1300 fills the vector; dtor 0x14046e380).
class CShutdownEventGroup : public CPtred
{
public:
    CShutdownEventGroup();                                  // 0x1407d1300
    CShutdownEventValue* FUN_1407d1400(int nIndex);         // the value of a kind
private:
    MS2_LAYOUT_FRIEND;
    std::vector<MS2Ptr<CShutdownEventValue> > m_values;     // +0x18
};
MS2_CHECK_SIZE(CShutdownEventGroup, 0x30);
