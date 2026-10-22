// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). LoginBgBgmTable / LoginBgBgmData: Table/loginBgBgm.xml, the
// login screen background and its music for each month.
// MS2-UNIT: commonfiles\loginbgbgmdata.cpp
// MS2-RANGE: 0x140a71e70-0x140a78f00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHV?$vector@V?$MS2Ptr@VLoginBgBgmData@@@@V?$allocator@V?$MS2Ptr@VLoginBgBgmData@@@@@std@@@std@@$0A@@?$pair@HV?$vector@V?$MS2Ptr@VLoginBgBgmData@@@@V?$allocator@V?$MS2Ptr@VLoginBgBgmData@@@@@std@@@std@@@std@@QEAA@AEAH$$QEAV?$vector@V?$MS2Ptr@VLoginBgBgmData@@@@V?$allocator@V?$MS2Ptr@VLoginBgBgmData@@@@@std@@@1@@Z 0x140a72ec0 ; unique
// MS2-PIN: ??$_Emplace_back@U?$pair@II@std@@@?$_Uninitialized_backout_al@PEAU?$pair@II@std@@V?$allocator@U?$pair@II@std@@@2@@std@@QEAAX$$QEAU?$pair@II@1@@Z 0x140a734c0 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@U?$pair@II@std@@@?$vector@U?$pair@II@std@@V?$allocator@U?$pair@II@std@@@2@@std@@AEAAX$$QEAU?$pair@II@1@@Z 0x140a73640 ; unique
// MS2-PIN: ??$_Emplace_reallocate@U?$pair@II@std@@@?$vector@U?$pair@II@std@@V?$allocator@U?$pair@II@std@@@2@@std@@QEAAPEAU?$pair@II@1@QEAU21@$$QEAU21@@Z 0x140a73950 ; unique
// MS2-PIN: ??$construct@U?$pair@II@std@@U12@@?$_Default_allocator_traits@V?$allocator@U?$pair@II@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@II@std@@@1@QEAU?$pair@II@1@$$QEAU31@@Z 0x140a75960 ; unique
// MS2-PIN: ??$make_pair@AEAHV?$vector@V?$MS2Ptr@VLoginBgBgmData@@@@V?$allocator@V?$MS2Ptr@VLoginBgBgmData@@@@@std@@@std@@@std@@YA?AU?$pair@HV?$vector@V?$MS2Ptr@VLoginBgBgmData@@@@V?$allocator@V?$MS2Ptr@VLoginBgBgmData@@@@@std@@@std@@@0@AEAH$$QEAV?$vector@V?$MS2Ptr@VLoginBgBgmData@@@@V?$allocator@V?$MS2Ptr@VLoginBgBgmData@@@@@std@@@0@@Z 0x140a75dc0 ; unique
// MS2-PIN: ?_Change_array@?$vector@U?$pair@II@std@@V?$allocator@U?$pair@II@std@@@2@@std@@AEAAXQEAU?$pair@II@2@_K1@Z 0x140a76ef0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@II@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@II@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$pair@II@std@@@2@XZ 0x140a77a20 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$emplace_back@U?$pair@II@std@@@?$vector@U?$pair@II@std@@V?$allocator@U?$pair@II@std@@@2@@std@@QEAAX$$QEAU?$pair@II@1@@Z 0x140a75bd0
// MS2-PIN: ??_7LoginBgBgmTable@@6B?$TSingleton@VLoginBgBgmTable@@@@@ 0x142dcc2c0
// MS2-PIN: ??_7LoginBgBgmTable@@6B?$CValidData@VLoginBgBgmTable@@@@@ 0x142dcc2d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\loginbgbgmdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "loginbgbgmdata.h"
#include "logstring.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <algorithm>
#include <time.h>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char* pszName); };   // FirstChildElement
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
void FUN_1401859c0(CLogString* log, int level, int category, const wchar_t* format);
void FUN_14054c030(CLogString* log, int level, int category, const wchar_t* format, const CString& first,
                   const CString& second);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
CString FUN_14015f710(Unk_140165cf0* pElem, const char* pszName, CString strDefault);   // string attribute
unsigned int FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned int nDefault);
void FUN_1401782a0(const CString& str, std::vector<unsigned int>& rOut, const char* pszSep);   // split into numbers
__int64 FUN_140869440();                                                  // server time
unsigned FUN_140768010(unsigned nRange, unsigned nBase);                  // random number in base..base+range-1

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flag (symbols-manual.tsv)
LoginBgBgmTable* TSingleton<LoginBgBgmTable>::s_instance;
bool LoginBgBgmTable::s_bInit;
#endif

// @0x140a71e70
static struct tm* Unk_LocalTime(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// @0x140a71e90
LoginBgBgmData::LoginBgBgmData() : m_strBgDay(""), m_nPriority(0)
{
    m_bgm.clear();
}

// @0x140a71f20
LoginBgBgmData::~LoginBgBgmData()
{
    m_bgm.clear();
}

// @0x140a71f90
LoginBgBgmTable::LoginBgBgmTable() : m_spCurrent(0)
{
    m_byMonth.clear();
    for (int i = 0; i <= 12; i++)
    {
        m_byMonth.insert(std::make_pair(i, DataList()));
    }
}

// @0x140a720e0
LoginBgBgmTable::~LoginBgBgmTable()
{
    m_byMonth.clear();
}

// @0x140a72170
bool LoginBgBgmTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "loginBgBgm.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return true;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return true;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "login", "clientPropertyBgDay", &nodes);
    for (unsigned __int64 i = 0; i < nodes.size(); i++)
    {
        CString strMonth = FUN_14015f710(nodes[i], "month", CString(""));
        if (strMonth.IsEmpty())
            continue;
        std::vector<unsigned int> months;
        FUN_1401782a0(strMonth, months, ",");
        CString strBgDay = FUN_14015f710(nodes[i], "clientPropertyBgDay", CString(""));
        if (strBgDay.IsEmpty())
            continue;
        CString strBgmId = FUN_14015f710(nodes[i], "bgmID", CString(""));
        if (strBgmId.IsEmpty())
            continue;
        std::vector<unsigned int> bgmIds;
        FUN_1401782a0(strBgmId, bgmIds, ",");
        CString strBgmParam = FUN_14015f710(nodes[i], "bgmParam", CString(""));
        std::vector<unsigned int> bgmParams;
        FUN_1401782a0(strBgmParam, bgmParams, ",");
        unsigned nIds = bgmIds.size();
        unsigned nParams = bgmParams.size();
        if (nIds > nParams)
        {
            FUN_14054c030(GetLogString(), 2, 0x13,
                          L"[<ms2> loginBgBgm.xml bgmID count != bgmParam count. clientPropertyBgDay : {0}]",
                          strPath, strBgDay);
            for (unsigned n = 0; n < nIds - nParams; n++)
                bgmParams.push_back(5);
        }
        unsigned nPriority = FUN_140197390(nodes[i], "priority", 0);
        LoginBgBgmDataPtr spData(new LoginBgBgmData);
        spData->m_strBgDay = strBgDay;
        spData->m_nPriority = nPriority;
        int nCount = bgmIds.size();
        for (int k = 0; k < nCount; k++)
            spData->m_bgm.push_back(std::make_pair(bgmIds[k], bgmParams[k]));
        for (std::vector<unsigned int>::iterator it = months.begin(); it != months.end(); ++it)
        {
            unsigned nMonth = *it;
            if (nMonth > 12)
            {
                FUN_14054c030(GetLogString(), 2, 0x13, L"[<ms2> loginBgBgm.xml month > 12. clientPropertyBgDay : {0}]",
                              strPath, strBgDay);
                continue;
            }
            m_byMonth[nMonth].push_back(spData);
        }
    }
    SetInit(true);
    return true;
}
MS2_REPLACE_METHOD(0x140A72170, LoginBgBgmTable, Load, 2149, 0xD1132959);

// @0x140a729e0
void LoginBgBgmTable::SelectCurrent()
{
    m_spCurrent = 0;
    int nMonth = 0;
    if (CMsTime::IsTimeZoneSet())
    {
        CMsTime time(FUN_140869440());
        nMonth = time.GetMonth();
    }
    else
    {
        __time64_t now = FUN_140869440();
        struct tm* ptm = Unk_LocalTime(&now);
        if (ptm == 0)
            return;
        nMonth = ptm->tm_mon + 1;
    }
    if (nMonth <= 0 || nMonth > 12)
        return;
    if (m_byMonth[nMonth].size() == 0)
        return;
    unsigned nTop = 0;
    unsigned nCount = m_byMonth[nMonth].size();
    for (unsigned i = 0; i < nCount; i++)
        nTop = (std::max)(nTop, m_byMonth[nMonth][i]->m_nPriority);
    DataList candidates;
    for (unsigned i = 0; i < nCount; i++)
    {
        if (m_byMonth[nMonth][i]->m_nPriority == nTop)
            candidates.push_back(m_byMonth[nMonth][i]);
    }
    int nCandidates = candidates.size();
    if (nCandidates == 0)
    {
        FUN_1401859c0(GetLogString(), 2, 0x13, L"[<ms2> LoginBgBgmTable::Get candidateVector size 0 error");
        return;
    }
    m_spCurrent = candidates[FUN_140768010(nCandidates, 0)];
}
MS2_REPLACE_METHOD(0x140A729E0, LoginBgBgmTable, SelectCurrent, 718, 0xFB4A22D4);

// @0x140a72cc0
CStringA LoginBgBgmTable::GetBgDay()
{
    CStringA strResult("");
    if (m_spCurrent.get() != 0)
        strResult = m_spCurrent->m_strBgDay;
    return strResult;
}
MS2_REPLACE_METHOD(0x140A72CC0, LoginBgBgmTable, GetBgDay, 155, 0xE1AC0A30);

// @0x140a72d70
std::pair<unsigned, unsigned> LoginBgBgmTable::GetBgm()
{
    std::pair<unsigned, unsigned> result(0, 0);
    if (m_spCurrent.get() != 0)
    {
        std::vector<std::pair<unsigned, unsigned> >* pBgm = &m_spCurrent->m_bgm;
        int nCount = pBgm->size();
        if (nCount != 0)
            result = (*pBgm)[FUN_140768010(nCount, 0)];
    }
    return result;
}
MS2_REPLACE_METHOD(0x140A72D70, LoginBgBgmTable, GetBgm, 180, 0x9BA62059);
