// gameeventuservalue.h - GameEventVariable (one keyed event value with a time stamp) and GameEventUserValue (the map of
// them that a user owns). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `commonfiles\gameeventuservalue.cpp` (0x14041eeb0-0x140421740 .text$mn). Header name assumed (the third-party v2525
// snapshot calls it GameEventUserValue.h); member names invented from their use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr

class COutputStream;
class CInPacket;

// 0x40 (allocation size at 0x14041f850). vftable 0x142d45cc0 (slot 0 = scalar deleting dtor 0x1404204f0).
class GameEventVariable : public CPtred
{
public:
    // 8 bytes, ordered by signed type then unsigned id (0x14041ef20); the key of GameEventUserValue::m_variables.
    struct Key
    {
        Key();                                  // 0x14041eeb0
        Key(int type, unsigned int id);         // 0x14041eee0
        bool operator<(const Key& other) const; // 0x14041ef20
        bool operator>(const Key& other) const; // 0x14041efa0
        bool operator==(const Key& other) const;// 0x14041f000
        void Write(COutputStream* stream);      // 0x14041f050
        void Read(CInPacket& packet);           // 0x14041f0a0
        int m_type;
        unsigned int m_id;
    };

    GameEventVariable();                                                                        // 0x14041f110
    GameEventVariable(const Key& key, const CStringW& value, const CMsTime& time, bool dirty);  // 0x14041f190
    virtual ~GameEventVariable() = default;                                                           // 0x140420330

    Key& GetKey();                              // 0x14041f230
    int GetType();                              // 0x14041f250
    void Write(COutputStream* stream);          // 0x14041f270
    void Read(CInPacket& packet);               // 0x14041f300
    void SetValue(const CStringW& value);                           // 0x14041f3e0
    void SetValue(const CStringW& value, const CMsTime& time);      // 0x14041f440
    void SetDirty(bool dirty);                  // 0x14041f4e0
    bool IsDirty();                             // 0x14041f500
    bool IsEmpty();                             // 0x14041f520
    // The value read as T, or nDefault once m_time has passed (inline; one COMDAT per T, the specialisations live with
    // their users: <__int64> 0x140be9030 in ?\uicollectitemgroupeventdialog.cpp).
    template <class T> T GetValue(const T& nDefault);

    Key m_key;          // +0x18
    CStringW m_value;   // +0x20
    CMsTime m_time;     // +0x28
    bool m_dirty;       // +0x38
};
MS2_CHECK_SIZE(GameEventVariable, 0x40);

// 0x48: CPtred, then a CRBMap (block size 10) at +0x18. vftable 0x142d45cd0 (slot 0 = scalar deleting dtor 0x1404204b0,
// slot 1 = OnChanged 0x14041fbf0).
class GameEventUserValue : public CPtred
{
public:
    typedef MS2Ptr<GameEventVariable> VariablePtr;
    typedef ATL::CRBMap<GameEventVariable::Key, VariablePtr> VariableMap;

    GameEventUserValue();                                       // 0x14041f550
    virtual ~GameEventUserValue() = default;                           // 0x140420300
    virtual void OnChanged(VariablePtr variable);               // 0x14041fbf0

    void Merge(const VariableMap& variables);                   // 0x14041f5a0
    void ExpireAll();                                           // 0x14041f5d0
    void Clear();                                               // 0x14041f6e0
    void Write(COutputStream* stream);                          // 0x14041f710
    void Read(CInPacket& packet);                               // 0x14041f7c0
    VariablePtr ReadVariable(CInPacket& packet);                // 0x14041f850
    bool Has(int type);                                         // 0x14041f940
    void Reset(int type);                                       // 0x14041f970
    bool GetTime(int type, CMsTime* time);                      // 0x14041f9a0
    bool Has(int type, unsigned int id);                        // 0x14041f9e0
    void Reset(int type, unsigned int id);                      // 0x14041fa70
    bool GetTime(int type, unsigned int id, CMsTime* time);     // 0x14041faf0
    void Insert(VariablePtr variable);                          // 0x14041fb90
    VariablePtr Get(int type, unsigned int id);                 // 0x14041fc20
    void Set(int type, unsigned int id, CStringW value, const CMsTime& time);   // 0x14041fda0
    // The variable (type, id) read as T, nDefault when it is missing or expired (inline; <__int64> 0x140be8f80).
    template <class T> T GetValue(int type, unsigned int id, const T& nDefault)
    {
        GameEventVariable::Key key(type, id);
        VariablePtr variable;
        if (!m_variables.Lookup(key, variable))
            return nDefault;
        return variable->GetValue(nDefault);
    }

    VariableMap m_variables;    // +0x18
};
MS2_CHECK_SIZE(GameEventUserValue, 0x48);

// The user values of the local player (0x143ab2fc0; a second instance follows at 0x143ab3010). Name invented.
extern GameEventUserValue g_gameEventUserValue;
