// cpetdatatable.h - CPetData (RTTI .?AVCPetData@@, 0xd0 bytes) and CPetDataTable (RTTI .?AVCPetDataTable@@, 0x130 bytes).
// NOT original headers (names assumed; member names invented from the xml attribute each one is read from).
// Both live in unit_140728140.cpp (0x140728140-0x14072bdc0), which reads Table/petProperty.xml.
// CPetDataTable bases: TSingleton<CPetDataTable> at +0x0, CValidData<CPetDataTable> at +0x8, CCacheData at +0x10.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
#pragma once

#include <atlcoll.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/petgroupinfo.h"

class Unk_140165cf0;    // xml element

// One <pets> row.
class CPetData : public CPtred
{
public:
    CPetData();                                             // 0x140728140
    virtual ~CPetData();                                    // 0x1407282b0
    bool Load(Unk_140165cf0* pNode);                        // 0x140728320
    int GetItemId(int nKind);                               // 0x1407287e0 "itemIDs" or, when 0, the pet id
    unsigned int GetId();                                   // 0x140728820

    int m_nType;                                            // +0x18 "type"
    bool m_bEnablePetExtraction;                            // +0x1c "enablePetExtraction"
    bool m_bCollectPreview;                                 // +0x1d "isCollectPreview" (default true)
    unsigned int m_nCollectGroupId;                                 // +0x20 "collectGroupId"
    unsigned int m_nTamingGroupId;                                  // +0x24 "tamingGroupID"
    ATL::CAtlArray<CStringA> m_tamingAiPresets;             // +0x28 "tamingAiPresets"
    ATL::CAtlMap<int, unsigned short> m_passiveSkills;      // +0x48 "passiveSkillId" -> "passiveSkillLevel"
    float m_fWarpDistance;                                  // +0x90 "warpDistance" (1500)
    float m_fTraceDistance;                                 // +0x94 "traceDistance" (300)
    float m_fBattleTraceDistance;                           // +0x98 "battleTraceDistance" (600)
    float m_fNameTagOffsetY;                                // +0x9c "nameTagOffsetY"
    unsigned int m_nSlotNum;                                // +0xa0 "slotNum"
    unsigned short m_nOptionLevel;                          // +0xa4 "optionLevel"
    float m_fConstantOptionFactor;                          // +0xa8 "constantOptionFactor"
    unsigned int m_nItemIds;                                // +0xac "itemIDs"
    std::vector<std::pair<unsigned int, unsigned short> > m_additionalEffects;   // +0xb0 "additionalEffectID/Level"
    unsigned int m_nId;                                     // +0xc8 "code"
};
MS2_CHECK_SIZE(CPetData, 0xd0);
MS2_CHECK_OFFSET(CPetData, m_passiveSkills, 0x48);
MS2_CHECK_OFFSET(CPetData, m_additionalEffects, 0xb0);

class CPetDataTable : public TSingleton<CPetDataTable>, public CValidData<CPetDataTable>, public CCacheData
{
public:
    typedef MS2Ptr<CPetData> PetPtr;

    CPetDataTable();                                        // 0x140728840
    virtual ~CPetDataTable();                               // 0x140728970

    bool Load();                                            // 0x140728a30 (properties, then the collect groups)
    bool LoadProperties();                                  // 0x140728a70 Table/petProperty.xml
    bool LoadCollectGroups();                               // 0x140728fe0
    PetPtr Find(unsigned int nPetId);                       // 0x1407290f0 (the exe name is FUN_1407290f0)
    PetPtr Find(CString strKfm);                            // 0x1407291c0 pet by model kfm
    int Contains(CString strKfm);                           // 0x1407292a0
    CPetCollectTable* GetCollect() { return &m_collect; }   // 0x140cb17e0 (inline COMDAT, tabcontentspetcollect.cpp)

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x38
    ATL::CAtlMap<unsigned int, PetPtr> m_pets;              // +0x68 by pet id
    CPetCollectTable m_collect;                             // +0xb0
    ATL::CAtlMap<CStringA, PetPtr, ATL::CStringElementTraits<CStringA> > m_petsByKfm;   // +0xe8 taming pets by model kfm
};
MS2_CHECK_SIZE(CPetDataTable, 0x130);
