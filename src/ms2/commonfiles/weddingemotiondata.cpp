// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WeddingEmotionData / WeddingEmotionTable, the wedding
// couple emotion table (Table/weddingEmotion.xml: <weddingEmotion code anim="a,b"/>), plus the template glue of its
// std::map<unsigned, MS2Ptr<WeddingEmotionData>>.
// MS2-UNIT: ?\weddingemotiondata.cpp
// MS2-RANGE: 0x1409030d0-0x1409063b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_7WeddingEmotionTable@@6B?$TSingleton@VWeddingEmotionTable@@@@@ 0x142da7d20
// MS2-PIN: ??_7WeddingEmotionTable@@6B?$CValidData@VWeddingEmotionTable@@@@@ 0x142da7d30
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\weddingemotiondata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/weddingemotiontable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <set>
#include <vector>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
// The unit's two-argument log call (FMT_VARIADIC instantiation, ?\characterability.cpp).
void FUN_1401e0850(CLogString* log, int level, int category, const wchar_t* format, const CString& first,
                   const unsigned& second);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
unsigned int FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned int nDefault);
CString FUN_14015f710(Unk_140165cf0* pElem, const char* pszName, CString strDefault);
void FUN_1402c8940(const CString& str, std::vector<CString>& vec, const char* pszDelim);   // split into strings

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool WeddingEmotionTable::s_bInit;
#endif

// @0x1409030d0
WeddingEmotionData::WeddingEmotionData()
{
}

// @0x140903120
WeddingEmotionData::~WeddingEmotionData()
{
    m_anim.clear();
}

// @0x140903170
WeddingEmotionTable::WeddingEmotionTable()
{
}

// @0x1409031e0
WeddingEmotionTable::~WeddingEmotionTable()
{
    m_map.clear();
}

// @0x140903250
int WeddingEmotionTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "weddingEmotion.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]", strPath);
        return 0;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    std::set<unsigned> codes;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("weddingEmotion"); pNode != 0;
         pNode = pNode->FUN_140168650("weddingEmotion"))
    {
        MS2Ptr<WeddingEmotionData> spData(new WeddingEmotionData);
        unsigned nCode = FUN_140197390(pNode, "code", 0);
        if (nCode == 0)
            continue;
        if (codes.find(nCode) != codes.end())
        {
            FUN_1401e0850(GetLogString(), 1, 0x13, L"중복된 키 값이 존재 합니다.[<ms2> {0} id : {1}]", strPath, nCode);
            return 0;
        }
        CString strAnim = FUN_14015f710(pNode, "anim", CString(""));
        if (strAnim.IsEmpty())
            continue;
        std::vector<CString> unused;
        FUN_1402c8940(strAnim, spData->m_anim, ",");
        if (spData->m_anim.empty())
            continue;
        m_map.insert(std::make_pair(nCode, spData));
    }
    SetInit(true);
    return 1;
}

// @0x140903740
MS2Ptr<WeddingEmotionData> WeddingEmotionTable::FUN_140903740(unsigned nCode)
{
    std::map<unsigned, MS2Ptr<WeddingEmotionData> >::const_iterator it = m_map.find(nCode);
    if (it == m_map.end())
        return MS2Ptr<WeddingEmotionData>(0);
    return it->second;
}

// @0x140906290
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
