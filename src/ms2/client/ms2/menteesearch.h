// menteesearch.h - the mentee list search: CMenteeSearchManager (singleton), CMenteeSearchParam (the search request),
// CMenteeSearchWebResult (the web answer bytes) and MenteeSearch::ResponseMenteeList (the parsed mentor list), RTTI
// names. Header name assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/mentor.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"

typedef Unk_MentorPtr<CMentor> CMentorPtr;
typedef ATL::CAtlArray<CMentorPtr> CMentorArray;

// The search request (0x38 bytes, base CPtred). The first three members default to the logged-in character's globals.
class CMenteeSearchParam : public CPtred
{
public:
    CMenteeSearchParam();                           // 0x140b6e0f0
    void FUN_140b6e170(const CMenteeSearchParam* pSrc);     // copies the two search options

    unsigned int m_nCharType;                       // +0x18 DAT_143ab2830
    __int64 m_nAccountId;                           // +0x20 DAT_143ab2820
    __int64 m_nCharacterId;                         // +0x28 DAT_143ab2828
    int m_nOption30;                                // +0x30 (0)
    int m_nOption34;                                // +0x34 (2)
};
MS2_CHECK_SIZE(CMenteeSearchParam, 0x38);

// The web answer: a result code and the raw bytes to parse.
class CMenteeSearchWebResult : public CPtred
{
public:
    CMenteeSearchWebResult();                       // 0x140b6e1b0
    explicit CMenteeSearchWebResult(int nResult);   // 0x140b6e220

    int m_nResult;                                  // +0x18 (0 = ok)
    CByteBuffer m_buffer;                           // +0x20
};
MS2_CHECK_SIZE(CMenteeSearchWebResult, 0x60);
MS2_CHECK_OFFSET(CMenteeSearchWebResult, m_buffer, 0x20);

namespace MenteeSearch
{
// The parsed answer: mentors keyed by their id.
class ResponseMenteeList : public CPtred
{
public:
    ResponseMenteeList();                           // 0x140b6df50
    int FUN_140b6dfb0(CByteBuffer& buffer);         // parses the answer (always 1)

    int m_nResult;                                  // +0x18
    ATL::CRBMap<unsigned __int64, CMentorPtr> m_map;         // +0x20 id -> mentor
};
MS2_CHECK_SIZE(ResponseMenteeList, 0x50);
}
MS2_CHECK_OFFSET(MenteeSearch::ResponseMenteeList, m_map, 0x20);

class UIInviteMentoringDialog;

// The singleton CGameApp::InitInstance (?\ms2.cpp) creates.
class CMenteeSearchManager : public TSingleton<CMenteeSearchManager>
{
public:
    CMenteeSearchManager();                         // 0x140b6e290
    virtual ~CMenteeSearchManager();                // 0x140b6e340

    void FUN_140b6e3e0();                           // feature 0x3f on: push the answer to the dialog
    void GetMentees(CMentorArray& arrOut);          // 0x140b6e420 the mentors of the answer, shuffled
    void SetParam(const CMenteeSearchParam* pParam);    // 0x140b6e560 keeps a copy of the request
    MS2Ptr<CMenteeSearchParam> GetParam();          // 0x140b6e630
    void ClearParam();                              // 0x140b6e6c0
    void RequestSearch(const CMenteeSearchParam* pParam);   // 0x140b6e730 starts the web thread
    void OnWebResult(MS2Ptr<CMenteeSearchParam> pParam, MS2Ptr<CMenteeSearchWebResult> pResult);    // 0x140b6e800
    void FUN_140b6eae0();                           // 0x140b6eae0 hands a new answer to the dialog
    void SetResponse(MS2Ptr<MenteeSearch::ResponseMenteeList> pList);   // 0x140b6ec20
    static UINT RequestWeb(LPVOID pParam);          // 0x140b6ecc0 thread entry

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                    // +0x08
    MS2Ptr<CMenteeSearchParam> m_pParam;            // +0x38
    MS2Ptr<MenteeSearch::ResponseMenteeList> m_pResponse;   // +0x48
    int m_bNewResponse;                             // +0x58
};
MS2_CHECK_SIZE(CMenteeSearchManager, 0x60);
MS2_CHECK_OFFSET(CMenteeSearchManager, m_lock, 0x8);
MS2_CHECK_OFFSET(CMenteeSearchManager, m_pParam, 0x38);
MS2_CHECK_OFFSET(CMenteeSearchManager, m_pResponse, 0x48);
