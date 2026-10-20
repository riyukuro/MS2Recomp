// changejobtable.h - CChangeJobTable and ChangeJobData (RTTI names): the sub-job change table read from
// Table/changeJob.xml (<subjob feature subJobCode changeSubJobCode startquestid endquestid movie desc skilldesc1
// skilldesc2 skillID1 skillID2/>). Header name assumed from the unit path; member and helper names are invented from use.
// Proven (exe): CChangeJobTable is 0x50 bytes (TSingleton at +0, the CAtlMap of the rows at +8), ChangeJobData is 0x80 bytes
// (boxed in a TPtredDummy, 0x98).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// The sub job code (the exe keys the row map by an enum, so its ATL traits take the key by reference).
enum Unk_SubJobCode { Unk_SubJobCode_None = 0 };

// One <subjob> row.
struct ChangeJobData
{
public:
    ChangeJobData();                                    // 0x1401d72f0
    ~ChangeJobData();                                   // 0x1401d74b0

    Unk_SubJobCode m_nSubJobCode;                      // +0x00 "subJobCode" (the map key)
    int m_nChangeSubJobCode;                            // +0x04 "changeSubJobCode"
    int m_nStartQuestId;                                // +0x08 "startquestid"
    int m_nEndQuestId;                                  // +0x0c "endquestid"
    CString m_strMovie;                                 // +0x10 "movie"
    CStringW m_strDesc;                                 // +0x18 string table 0x4f, "desc"
    CStringW m_strJobName;                              // +0x20 string table 6, changeSubJobCode
    CStringW m_strSkillDesc1;                           // +0x28 "skilldesc1"
    CStringW m_strSkillDesc2;                           // +0x30 "skilldesc2"
    ATL::CAtlArray<unsigned int> m_skills1;             // +0x38 "skillID1"
    ATL::CAtlArray<unsigned int> m_skills2;             // +0x58 "skillID2"
    bool m_bValid;                                      // +0x78
};
MS2_CHECK_SIZE(ChangeJobData, 0x80);
MS2_CHECK_OFFSET(ChangeJobData, m_strMovie, 0x10);
MS2_CHECK_OFFSET(ChangeJobData, m_skills1, 0x38);
MS2_CHECK_OFFSET(ChangeJobData, m_skills2, 0x58);
MS2_CHECK_OFFSET(ChangeJobData, m_bValid, 0x78);

CPtred* FUN_1401ba820(CPtred* p);
// The CPtred box of a row: the smart pointer points at the value, 0x18 bytes behind the box.
template<> struct Unk_SocketRef<ChangeJobData> {
    static CPtred* Base(ChangeJobData* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<ChangeJobData>, value);
        return result;
    }
    static TPtredDummy<ChangeJobData>* New(void*) { return new TPtredDummy<ChangeJobData>(); }
    static ChangeJobData* Value(CPtred* p) {
        ChangeJobData* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<ChangeJobData>*>(p)->value;
        return result;
    }
    static ChangeJobData* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(ChangeJobData)
MS2_CHECK_SIZE(TPtredDummy<ChangeJobData>, 0x98);
MS2_CHECK_OFFSET(TPtredDummy<ChangeJobData>, value, 0x18);

// RTTI CChangeJobTable, 0x50 bytes. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates.
class CChangeJobTable : public TSingleton<CChangeJobTable>
{
public:
    typedef Unk_SocketPtr<ChangeJobData> DataPtr;
    typedef ATL::CAtlMap<Unk_SubJobCode, DataPtr> DataMap;

    CChangeJobTable();                                  // 0x1401d64a0
    virtual ~CChangeJobTable();                         // 0x1401d6510

    void Load();                                        // 0x1401d6550 Table/changeJob.xml (when content switch 0xca is on)
    DataPtr Get(Unk_SubJobCode nSubJobCode);                       // 0x1401d6c30 the row of a sub job
    int CanChange(int nJobGroup, Unk_SubJobCode nJobCode, unsigned short nLevel);   // 0x1401d6ce0
    int GetStartQuestId(Unk_SubJobCode nSubJobCode);               // 0x1401d6d70
    int GetEndQuestId(Unk_SubJobCode nSubJobCode);                 // 0x1401d6df0
    int GetChangeSubJobCode(Unk_SubJobCode nSubJobCode);           // 0x1401d6e70
    int IsChangeTarget(int nJobCode);                   // 0x1401d6ef0 some row changes to this job

private:
    MS2_LAYOUT_FRIEND;
    DataMap m_map;                                      // +0x08 subJobCode -> row
};
MS2_CHECK_SIZE(CChangeJobTable, 0x50);
MS2_CHECK_OFFSET(CChangeJobTable, m_map, 0x08);
