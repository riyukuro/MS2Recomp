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
#include "ms2/commonfiles/filesystem.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// Unrecovered helpers (the xml loader helpers the other table units use).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
void Unk_AdditionalLog(CLogString* log, int level, int category, const wchar_t* format);
template <class T, class U>
void Unk_ItemDataLog(CLogString* log, int level, int category, const wchar_t* format, const T& first, const U& second);   // C3: was FUN_14054c030
CString GetXmlPath(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(struct Unk_XmlElement*, char const*, char const*, std::vector<struct Unk_XmlElement*>&);   // C3: retyped to the commonutil def
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
unsigned int FUN_140197390(TiXmlElement* pElem, const char* pszName, unsigned int nDefault);
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // 0x1401782a0 for std::vector<unsigned> (xmlattr.h)
__int64 GetServerTime();                                                  // server time
int GetRandomRange(int, int);  // C3: the definition's signature

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
    CString strPath = GetXmlPath("Table", "loginBgBgm.xml");
    TiXmlDocument doc;
    if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return true;
    }
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return true;
    }
    std::vector<TiXmlElement*> nodes;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "login", "clientPropertyBgDay", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&nodes));
    for (unsigned __int64 i = 0; i < nodes.size(); i++)
    {
        CString strMonth = Unk_ReadString((class Unk_XmlNode*)(nodes[i]), "month", CString(""));
        if (strMonth.IsEmpty())
            continue;
        std::vector<unsigned int> months;
        XmlSplit(strMonth, months, ",");
        CString strBgDay = Unk_ReadString((class Unk_XmlNode*)(nodes[i]), "clientPropertyBgDay", CString(""));
        if (strBgDay.IsEmpty())
            continue;
        CString strBgmId = Unk_ReadString((class Unk_XmlNode*)(nodes[i]), "bgmID", CString(""));
        if (strBgmId.IsEmpty())
            continue;
        std::vector<unsigned int> bgmIds;
        XmlSplit(strBgmId, bgmIds, ",");
        CString strBgmParam = Unk_ReadString((class Unk_XmlNode*)(nodes[i]), "bgmParam", CString(""));
        std::vector<unsigned int> bgmParams;
        XmlSplit(strBgmParam, bgmParams, ",");
        unsigned nIds = bgmIds.size();
        unsigned nParams = bgmParams.size();
        if (nIds > nParams)
        {
            Unk_ItemDataLog<CString, CString>(GetLogString(), 2, 0x13,
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
                Unk_ItemDataLog<CString, CString>(GetLogString(), 2, 0x13, L"[<ms2> loginBgBgm.xml month > 12. clientPropertyBgDay : {0}]",
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
        CMsTime time(GetServerTime());
        nMonth = time.GetMonth();
    }
    else
    {
        __time64_t now = GetServerTime();
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
        Unk_AdditionalLog(GetLogString(), 2, 0x13, L"[<ms2> LoginBgBgmTable::Get candidateVector size 0 error");
        return;
    }
    m_spCurrent = candidates[(unsigned)GetRandomRange(nCandidates, 0)];
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
            result = (*pBgm)[(unsigned)GetRandomRange(nCount, 0)];
    }
    return result;
}
MS2_REPLACE_METHOD(0x140A72D70, LoginBgBgmTable, GetBgm, 180, 0x9BA62059);
