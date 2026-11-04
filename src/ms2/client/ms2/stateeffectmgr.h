// stateeffectmgr.h - StateEffectMgr (RTTI name) and its row type. Table/StateEffectPC.xml: per state type, the effects an
// avatar plays. Header name assumed from the unit; member names invented from use.
#pragma once
#include <afx.h>
#include <list>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/commonfiles/os.h"

class GameObject;

// One <StateEffect> row, 0x28 bytes.
struct StateEffectData
{
    StateEffectData();                  // 0x140c9f7a0
    ~StateEffectData();                 // 0x140c9f820

    int m_nStateType;                   // +0x00 "stateType" (resolved through the state name table)
    CString m_strEffect;                // +0x08 "effect"
    int m_nEmotionSkillId;              // +0x10 "emotionSkillID"
    int m_nSetId;                       // +0x14 "setID"
    int m_nSkillId;                     // +0x18 "skillID"
    short m_nPad1c;                     // +0x1c
    int m_nGender;                      // +0x20 "gender" (2 = any)
};
MS2_CHECK_SIZE(StateEffectData, 0x28);
MS2_CHECK_OFFSET(StateEffectData, m_strEffect, 0x08);
MS2_CHECK_OFFSET(StateEffectData, m_nGender, 0x20);

// Output list the effect lookup appends effect ids to.
class Unk_StateEffectIdList : public std::list<unsigned>   // C3: the State's m_ids; ids go in through the real push_back (0x140a3fce0)
{
};

// RTTI StateEffectMgr, 0x40 bytes (TSingleton at +0).
class StateEffectMgr : public TSingleton<StateEffectMgr>
{
public:
    typedef std::list<StateEffectData> EffectList;
    typedef std::map<int, EffectList> EffectMap;

    StateEffectMgr();                   // 0x140c9f840
    virtual ~StateEffectMgr();          // 0x140c9f8a0

    bool Load();                                                                // 0x140c9f8f0 StateEffectPC.xml
    void GetEffects(GameObject* pObject, int nStateType, Unk_StateEffectIdList* pOut);   // 0x140c9fa00
    bool IsPlayerObject(GameObject* pObject);                                   // 0x140c9fc30
    bool LoadXml(const char* pszPath, EffectMap* pMap);                         // 0x140c9fc90

private:
    MS2_LAYOUT_FRIEND;
    EffectMap m_effects;                // +0x08
    CCacheData m_cache;                 // +0x18
};
MS2_CHECK_SIZE(StateEffectMgr, 0x40);
MS2_CHECK_OFFSET(StateEffectMgr, m_effects, 0x08);
MS2_CHECK_OFFSET(StateEffectMgr, m_cache, 0x18);
