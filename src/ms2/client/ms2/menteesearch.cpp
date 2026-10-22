// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The mentee list search: the web request thread, the answer
// parser and the manager that hands the mentors to the invite dialog.
// MS2-UNIT: ?\menteesearch.cpp
// MS2-RANGE: 0x140b6df50-0x140b71440 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VResponseMenteeList@MenteeSearch@@@@QEAA@AEBV0@@Z 0x140b6f8c0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCMenteeSearchParam@@@@QEBA_NPEAVCMenteeSearchParam@@@Z 0x140b6fd90 ; unique
// MS2-PIN: ??8?$MS2Ptr@VCMenteeSearchWebResult@@@@QEBA_NPEAVCMenteeSearchWebResult@@@Z 0x140b6fdd0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCMenteeSearchWebResult@@@@QEBAPEAVCMenteeSearchWebResult@@XZ 0x140b6fe80 ; unique
// MS2-PIN: ??C?$Unk_MentorPtr@VCMentor@@@@QEBAPEAVCMentor@@XZ 0x140b6fe90 ; unique
// MS2-PIN: ??C?$MS2Ptr@VResponseMenteeList@MenteeSearch@@@@QEBAPEAVResponseMenteeList@MenteeSearch@@XZ 0x140b6fea0 ; unique
// MS2-PIN: ?Find@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@IEBAPEAVCNode@12@_K@Z 0x140b700f0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140b70280 ; unique
// MS2-PIN: ?GetInstance@?$TSingleton@VCMenteeSearchManager@@@@SAPEAVCMenteeSearchManager@@XZ 0x140b702a0 ; unique
// MS2-PIN: ?GetNext@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140b702b0 ; unique
// MS2-PIN: ?GetValueAt@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@QEAAAEAV?$Unk_MentorPtr@VCMentor@@@@PEAU__POSITION@@@Z 0x140b702f0 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@AEAAPEAVCNode@12@_KAEBV?$Unk_MentorPtr@VCMentor@@@@@Z 0x140b70350 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140b70490 ; unique
// MS2-PIN: ?Maximum@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140b705a0 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140b70610 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@AEAAPEAVCNode@12@_KAEBV?$Unk_MentorPtr@VCMentor@@@@@Z 0x140b70680 ; unique
// MS2-PIN: ?Predecessor@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140b708e0 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@IEAAPEAVCNode@12@_KAEBV?$Unk_MentorPtr@VCMentor@@@@@Z 0x140b709b0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@V?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@ATL@@@ATL@@QEAAXXZ 0x140b70c30 ; unique
// MS2-PIN: ?RightRotate@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140b70d30 ; unique
// MS2-PIN: ?SetAt@?$CRBMap@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@QEAAPEAU__POSITION@@_KAEBV?$Unk_MentorPtr@VCMentor@@@@@Z 0x140b70e40 ; unique
// MS2-PIN: ?SetNil@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x140b70eb0 ; unique
// MS2-PIN: ?Successor@?$CRBTree@_KV?$Unk_MentorPtr@VCMentor@@@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@V?$Unk_MentorPtr@VCMentor@@@@@3@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140b70f20 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\menteesearch.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "menteesearch.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/exception.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/uiinvitementoringdialog.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees and data (bound to the exe by their FUN_<va> / DAT_<va> names) ----

extern unsigned DAT_143ab2830;                      // the own character's type
extern __int64 DAT_143ab2820;                       // the own account id
extern __int64 DAT_143ab2828;                       // the own character id

class Unk_MenteeSettings { public: bool FUN_14036d570(int nFeature); };     // the content switches
Unk_MenteeSettings* FUN_140166410();
class Unk_MenteeBanFlags { public: int FUN_1402c4c90(int nFlag); };         // blocked-action flag set
struct Unk_MenteeConfig { char m_pad[8]; Unk_MenteeBanFlags m_8; };
Unk_MenteeConfig* FUN_14025e7b0();                                          // global client config
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
void FUN_1412751b0(const CStringW& strText, int nKind);                     // shows the text as a notice
void FUN_141b6de20();                                                       // thread start-up
struct Unk_IoThreadScope { char m_buf[0x40]; };
void FUN_141b721f0(Unk_IoThreadScope* p, CString strName);
void FUN_141b722b0(Unk_IoThreadScope* p);
class Unk_MenteeSoap { public: MS2Ptr<CMenteeSearchWebResult> FUN_141770be0(MS2Ptr<CMenteeSearchParam> pParam); };
Unk_MenteeSoap* FUN_140b2e990();                                            // the web client
class Unk_MenteeUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nClass); };
Unk_MenteeUIManager* FUN_1403ed2b0();                                       // the UI service

// ---- MenteeSearch::ResponseMenteeList ----

// @0x140b6df50
MenteeSearch::ResponseMenteeList::ResponseMenteeList()
    : m_map(10)
{
    m_nResult = 1;
}

// The mentor record of the answer (declared below with the other parsers).
static CMentorPtr FUN_140b6f200(CByteBuffer& buffer);

// @0x140b6dfb0
int MenteeSearch::ResponseMenteeList::FUN_140b6dfb0(CByteBuffer& buffer)
{
    m_nResult = buffer.ReadInt32();
    if (m_nResult == 0)
    {
        int nCount = buffer.ReadInt32();
        for (int i = 0; i < nCount; ++i)
        {
            CMentorPtr spMentor = FUN_140b6f200(buffer);
            if (spMentor.get() != 0)
                m_map.SetAt(spMentor->c, spMentor);
        }
    }
    return 1;
}

// ---- CMenteeSearchParam ----

// @0x140b6e0f0
CMenteeSearchParam::CMenteeSearchParam()
    : m_nCharType(DAT_143ab2830), m_nAccountId(DAT_143ab2820), m_nCharacterId(DAT_143ab2828), m_nOption30(0), m_nOption34(2)
{
}

// @0x140b6e170
void CMenteeSearchParam::FUN_140b6e170(const CMenteeSearchParam* pSrc)
{
    if (pSrc != 0)
    {
        m_nOption30 = pSrc->m_nOption30;
        m_nOption34 = pSrc->m_nOption34;
    }
}

// ---- CMenteeSearchWebResult ----

// @0x140b6e1b0
CMenteeSearchWebResult::CMenteeSearchWebResult()
{
    m_nResult = 1;
    m_buffer.FUN_140518490();
}

// @0x140b6e220
CMenteeSearchWebResult::CMenteeSearchWebResult(int nResult)
{
    m_nResult = nResult;
    m_buffer.FUN_140518490();
}

// ---- CMenteeSearchManager ----

// @0x140b6e290
CMenteeSearchManager::CMenteeSearchManager()
{
    m_pParam = 0;
    m_pResponse = 0;
    m_bNewResponse = 0;
}

// @0x140b6e340
CMenteeSearchManager::~CMenteeSearchManager()
{
    m_pParam = 0;
    m_pResponse = 0;
}

// @0x140b6e3e0
void CMenteeSearchManager::FUN_140b6e3e0()
{
    if (FUN_140166410()->FUN_14036d570(0x3f))
        FUN_140b6eae0();
}

// Shuffles the list (declared here, defined with the other helpers below).
static void FUN_140b6f560(CMentorArray& arrMentors);

// @0x140b6e420
void CMenteeSearchManager::GetMentees(CMentorArray& arrOut)
{
    arrOut.RemoveAll();
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        if (m_pResponse == 0)
            return;
        POSITION pos = m_pResponse->m_map.GetHeadPosition();
        while (pos != 0)
        {
            CMentorPtr spMentor = m_pResponse->m_map.GetValueAt(pos);
            if (spMentor.get() != 0)
                arrOut.Add(spMentor);
            m_pResponse->m_map.GetNext(pos);
        }
    }
    FUN_140b6f560(arrOut);
}

// @0x140b6e560
void CMenteeSearchManager::SetParam(const CMenteeSearchParam* pParam)
{
    ClearParam();
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        m_pParam.AssignRaw(new CMenteeSearchParam);
        m_pParam->FUN_140b6e170(pParam);
    }
}

// @0x140b6e630
MS2Ptr<CMenteeSearchParam> CMenteeSearchManager::GetParam()
{
    MS2Ptr<CMenteeSearchParam> spParam(0);
    if (Unk_LockGuard guard = m_lock) {}
    else
        spParam = m_pParam;
    return spParam;
}

// @0x140b6e6c0
void CMenteeSearchManager::ClearParam()
{
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_pParam = 0;
}

// @0x140b6e730
void CMenteeSearchManager::RequestSearch(const CMenteeSearchParam* pParam)
{
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x41) != 1)
    {
        if (FUN_140166410()->FUN_14036d570(0x3f))
        {
            SetParam(pParam);
            MS2Ptr<CMenteeSearchParam> spParam = GetParam();
            if (spParam.get() != 0)
                AfxBeginThread(RequestWeb, spParam.get(), 0, 0, 0, 0);
        }
    }
}

// @0x140b6e800
void CMenteeSearchManager::OnWebResult(MS2Ptr<CMenteeSearchParam> pParam, MS2Ptr<CMenteeSearchWebResult> pResult)
{
    if (pParam == 0)
        return;
    if (pResult == 0)
        return;
    ClearParam();
    int nError = 1;
    if (pResult->m_nResult == 0)
    {
        MS2Ptr<MenteeSearch::ResponseMenteeList> spList(new MenteeSearch::ResponseMenteeList);
        if (spList == 0)
            throw Exception(0x20);
        if (spList->FUN_140b6dfb0(pResult->m_buffer) == 0)
            throw Exception(0x21);
        if (spList->m_nResult == 0)
        {
            nError = 0;
            SetResponse(spList);
        }
        else
            nError = spList->m_nResult;
    }
    if (nError != 0)
    {
        CStringW strText = GetStringCommonByKey(CStringW(L"s_mentoring_error_request_mentee_list_search_error"));
        FUN_1412751b0(strText, 20);
    }
}

// The mentoring invite dialog, when it is open (the UI service's lookup by class id).
static UIInviteMentoringDialog* FUN_140b6f4c0(int nClass);

// @0x140b6eae0
void CMenteeSearchManager::FUN_140b6eae0()
{
    MS2Ptr<MenteeSearch::ResponseMenteeList> spList(0);
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        if (m_bNewResponse == 0)
            return;
        m_bNewResponse = 0;
        spList = m_pResponse;
    }
    if (spList == 0)
        return;
    UIInviteMentoringDialog* pDlg = FUN_140b6f4c0(0x4f4c);
    if (pDlg != 0 && pDlg->vfunc_55() == 0)
    {
        CMentorArray arrMentors;
        GetMentees(arrMentors);
        pDlg->FUN_140c2f440(arrMentors);
    }
}

// @0x140b6ec20
void CMenteeSearchManager::SetResponse(MS2Ptr<MenteeSearch::ResponseMenteeList> pList)
{
    if (pList == 0)
        return;
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        m_pResponse = pList;
        m_bNewResponse = 1;
    }
}

// @0x140b6ecc0
UINT CMenteeSearchManager::RequestWeb(LPVOID pParam)
{
    FUN_141b6de20();
    Unk_IoThreadScope scope;
    FUN_141b721f0(&scope, CString("CMenteeSearchManager::RequestWeb"));
    MS2Ptr<CMenteeSearchParam> spParam(static_cast<CMenteeSearchParam*>(pParam));
    bool bNull = spParam == 0;
    if (!bNull)
    {
        MS2Ptr<CMenteeSearchWebResult> spResult = FUN_140b2e990()->FUN_141770be0(spParam);
        GetInstance()->OnWebResult(spParam, spResult);
    }
    FUN_141b722b0(&scope);
    return bNull;
}

// ---- the answer parser ----

// A length-prefixed wide string of the answer.
// @0x140b6ee70
static CStringW FUN_140b6ee70(CByteBuffer& buffer)
{
    int nLen = buffer.ReadInt32();
    unsigned char* pBuf = new unsigned char[nLen + 2];
    memset(pBuf, 0, nLen + 2);
    buffer.ReadBytes(pBuf, nLen);
    CStringW str(reinterpret_cast<wchar_t*>(pBuf));
    delete[] pBuf;
    return str;
}

// A "yyyy-mm-dd hh:mm:ss" text of the answer as a time.
// @0x140b6efa0
__time64_t FUN_140b6efa0(CByteBuffer& buffer)
{
    CStringW str = FUN_140b6ee70(buffer);
    int nYear = _wtoi(str.Mid(0));
    int nMonth = _wtoi(str.Mid(5));
    int nDay = _wtoi(str.Mid(8));
    int nHour = _wtoi(str.Mid(11));
    int nMinute = _wtoi(str.Mid(14));
    int nSecond = _wtoi(str.Mid(17));
    return CMsTime(nYear, nMonth, nDay, nHour, nMinute, nSecond).Get();
}

// One mentor of the answer.
// @0x140b6f200
static CMentorPtr FUN_140b6f200(CByteBuffer& buffer)
{
    CMentorPtr spMentor(new CMentor);
    spMentor->a = buffer.ReadInt64();
    spMentor->c = buffer.ReadInt64();
    spMentor->name = FUN_140b6ee70(buffer);
    spMentor->guild = FUN_140b6ee70(buffer);
    spMentor->level = (short)buffer.ReadInt32();
    spMentor->y = buffer.ReadInt32();
    spMentor->online = buffer.ReadInt32() != 0;
    return spMentor;
}

// @0x140b6f4c0
static UIInviteMentoringDialog* FUN_140b6f4c0(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObj.get() != 0)
            return dynamic_cast<UIInviteMentoringDialog*>(spObj.operator->());
    }
    return 0;
}

// Swaps two entries by their bytes.
template <class T> T* Unk_MenteeAddressOf(T& r) { return &r; }                  // @0x140b6f600
// @0x140b6f610
static void FUN_140b6f610(CMentorPtr& a, CMentorPtr& b)
{
    unsigned char tmp[sizeof(CMentorPtr)];
    memcpy(tmp, Unk_MenteeAddressOf(a), sizeof(CMentorPtr));
    memcpy(Unk_MenteeAddressOf(a), Unk_MenteeAddressOf(b), sizeof(CMentorPtr));
    memcpy(Unk_MenteeAddressOf(b), tmp, sizeof(CMentorPtr));
}

// Fisher-Yates shuffle.
// @0x140b6f560
static void FUN_140b6f560(CMentorArray& arrMentors)
{
    int n = (int)arrMentors.GetCount();
    int i;
    while (i = n - 1, i > 0)
    {
        int j = rand() % n;
        n = i;
        if (i != j)
            FUN_140b6f610(arrMentors[i], arrMentors[j]);
    }
}

// A dword read through a pointer.
// @0x140b700e0
int FUN_140b700e0(const int* p)
{
    return *p;
}

// @0x140b71320
MS2_EMIT_CRT_MEMMOVE_S();
