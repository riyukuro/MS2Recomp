// groundeffectdata.h - CGroundEffectDataManager and the data classes it owns. Data/Xml/GroundEffect/<name>.xml:
// <ms2><action type=".."><effects><effect filePath=".." percent=".."/>..</effects></action></ms2>. A ground name (the
// avatar's surface) selects a CGroundData, an action name (walk, run, ..) a CGroundActionData, and a CGroundEffectData
// picks one of its effect files by weighted random for the footstep effect.
// Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <vector>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/commonfiles/os.h"        // TSingleton<T>

class GameObject;

// The weighted index pool at CGroundEffectData+0x58 (0x18 bytes, a vector of ints). Its members are defined in
// weddingmanager.cpp (the exe places them at 0x141b90b70..0x141b90c70, after that unit's template glue); names invented.
class Unk_IndexPool
{
public:
    Unk_IndexPool();                            // 0x141b90b70
    ~Unk_IndexPool();                           // 0x141b90ba0
    void AddIndex(int nIndex, int nCount);      // 0x141b90bd0 pushes nIndex nCount times
    void Shuffle();                             // 0x141b90c20
    int Pick();                                 // 0x141b90c70 random entry

private:
    std::vector<int> m_indices;                 // each index repeated by its weight
};
MS2_CHECK_SIZE(Unk_IndexPool, 0x18);

// RTTI CGroundEffectData, 0x70 bytes: the effect files of one <effects> block.
class CGroundEffectData : public CPtred
{
public:
    CGroundEffectData();                        // 0x141376d00
    virtual ~CGroundEffectData();               // 0x141376d80

    ATL::CAtlArray<CString> m_files;            // +0x18 "filePath"
    ATL::CAtlArray<int> m_percents;             // +0x38 "percent" (0 when absent)
    Unk_IndexPool m_pool;                       // +0x58 index pool weighted by the percents
};
MS2_CHECK_SIZE(CGroundEffectData, 0x70);
MS2_CHECK_OFFSET(CGroundEffectData, m_files, 0x18);
MS2_CHECK_OFFSET(CGroundEffectData, m_percents, 0x38);
MS2_CHECK_OFFSET(CGroundEffectData, m_pool, 0x58);

// RTTI CGroundActionData, 0x38 bytes: one <action type="..">.
class CGroundActionData : public CPtred
{
public:
    typedef MS2Ptr<CGroundEffectData> EffectPtr;

    CGroundActionData();                        // 0x141376de0
    virtual ~CGroundActionData();               // 0x141376e30

    ATL::CAtlArray<EffectPtr> m_effects;        // +0x18 the <effects> blocks
};
MS2_CHECK_SIZE(CGroundActionData, 0x38);
MS2_CHECK_OFFSET(CGroundActionData, m_effects, 0x18);

// RTTI CGroundData, 0x48 bytes: one ground xml file.
class CGroundData : public CPtred
{
public:
    typedef MS2Ptr<CGroundActionData> ActionPtr;

    CGroundData();                              // 0x141376e70
    virtual ~CGroundData();                     // 0x141376ec0

    ATL::CRBMap<CString, ActionPtr> m_actions; // +0x18 by action type
};
MS2_CHECK_SIZE(CGroundData, 0x48);
MS2_CHECK_OFFSET(CGroundData, m_actions, 0x18);

// RTTI CGroundEffectDataManager, 0x38 bytes (TSingleton at +0).
class CGroundEffectDataManager : public TSingleton<CGroundEffectDataManager>
{
public:
    typedef MS2Ptr<CGroundData> GroundPtr;

    CGroundEffectDataManager();                 // 0x141376f00
    virtual ~CGroundEffectDataManager();        // 0x141376f50

    GroundPtr Load(const CString& strGround);                                                       // 0x141377760
    void GetEffectFiles(CString strGround, CString strAction, ATL::CAtlArray<CString>* pFiles);     // 0x1413771f0
    void PlayEffects(GameObject* pObject, CString strAction);                                       // 0x141377420

    ATL::CRBMap<CString, GroundPtr> m_grounds; // +0x08 cache by ground name
};
MS2_CHECK_SIZE(CGroundEffectDataManager, 0x38);
MS2_CHECK_OFFSET(CGroundEffectDataManager, m_grounds, 0x08);
