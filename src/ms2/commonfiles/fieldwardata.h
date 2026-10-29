// fieldwardata.h - the field war table (Table/FieldWarData.xml): FieldWarData (one war field entry), FieldWarGroup (the
// entries of one group, picked by weight) and the FieldWarDataTable singleton. Owning unit: commonfiles\fieldwardata.cpp
// (0x1403820e0-0x14038b670). Class names from RTTI, field names from the xml attributes; method names invented.
// NOT an original header.
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;     // game TinyXML element
class Unk_Random;

// RTTI FieldWarData, 0x38 bytes (one <fieldWar> element).
class FieldWarData : public CPtred
{
public:
    FieldWarData();                                 // 0x1403820e0
    virtual ~FieldWarData();                        // 0x140382170
    void Load(Unk_140165cf0* pElem);                // 0x1403821a0
    unsigned GetFieldWarID() const;                 // 0x1403822b0
    unsigned GetFieldWarGroupID() const;            // 0x1403822d0
    bool IsValid() const;                           // 0x1403822f0 always true

    unsigned m_fieldWarID;                          // +0x18
    unsigned m_fieldWarGroupID;                     // +0x1c
    unsigned m_pickWeight;                          // +0x20
    unsigned m_fieldID;                             // +0x24
    unsigned m_rewardID;                            // +0x28
    unsigned m_uiFieldID;                           // +0x2c
    bool m_isChangeMaxUser;                         // +0x30
    unsigned m_playerCountFactorID;                 // +0x34
};
MS2_CHECK_SIZE(FieldWarData, 0x38);
MS2_CHECK_OFFSET(FieldWarData, m_fieldWarID, 0x18);
MS2_CHECK_OFFSET(FieldWarData, m_pickWeight, 0x20);
MS2_CHECK_OFFSET(FieldWarData, m_isChangeMaxUser, 0x30);
MS2_CHECK_OFFSET(FieldWarData, m_playerCountFactorID, 0x34);

// RTTI FieldWarGroup, 0x50 bytes: the entries of one group with the running sum of their pick weights.
class FieldWarGroup : public CPtred
{
public:
    explicit FieldWarGroup(unsigned nGroupID);      // 0x140382300
    // ~FieldWarGroup() is implicit (0x140387c80): the exe dtor stores no vftable pointer
    void AddData(MS2Ptr<FieldWarData> spData);      // 0x140382370
    unsigned GetTotalWeight();                      // 0x1403823f0
    MS2Ptr<FieldWarData> PickData(Unk_Random& kRandom);     // 0x140382440 by weight

    unsigned m_groupID;                             // +0x18
    std::vector<unsigned> m_weights;                // +0x20 running sums
    std::vector<MS2Ptr<FieldWarData> > m_datas;     // +0x38
};
MS2_CHECK_SIZE(FieldWarGroup, 0x50);
MS2_CHECK_OFFSET(FieldWarGroup, m_weights, 0x20);
MS2_CHECK_OFFSET(FieldWarGroup, m_datas, 0x38);

// RTTI FieldWarDataTable, 0x40 bytes: TSingleton at +0, CValidData at +8.
class FieldWarDataTable : public TSingleton<FieldWarDataTable>, public CValidData<FieldWarDataTable>
{
public:
    FieldWarDataTable();                            // 0x1403825b0
    virtual ~FieldWarDataTable();                   // 0x140382650

    bool Load();                                    // 0x1403826e0 FieldWarData.xml
    MS2Ptr<FieldWarGroup> GetOrAddGroup(unsigned nGroupID);         // 0x1403829c0
    MS2Ptr<FieldWarData> GetDataByFieldID(unsigned nFieldID);       // 0x140382b20
    MS2Ptr<FieldWarData> GetData(unsigned nFieldWarID);             // 0x140382be0
    void Clear();                                   // 0x140382ca0 (only the by id map)
    void AddData(MS2Ptr<FieldWarData> spData);      // 0x140382cd0

    // @0x140388680
    static void SetInit(bool bInit) { s_bInit = bInit; }
    static bool s_bInit;                            // DAT_143aaec58

    std::map<unsigned, MS2Ptr<FieldWarData> > m_byID;               // +0x10 by fieldWarID
    std::map<unsigned, MS2Ptr<FieldWarGroup> > m_groups;            // +0x20 by fieldWarGroupID
    std::map<unsigned, MS2Ptr<FieldWarData> > m_byFieldID;          // +0x30 by fieldID
};
MS2_CHECK_SIZE(FieldWarDataTable, 0x40);
MS2_CHECK_OFFSET(FieldWarDataTable, m_byID, 0x10);
MS2_CHECK_OFFSET(FieldWarDataTable, m_groups, 0x20);
MS2_CHECK_OFFSET(FieldWarDataTable, m_byFieldID, 0x30);
