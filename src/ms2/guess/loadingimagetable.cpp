// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CLoadingImageTable and its rows LoadingImage / LoadingMovie:
// the loading screen backgrounds and movies (Table/loadingImage.xml), plus the template glue of their containers
// (CAtlArray / CRBMultiMap of the row pointer, CAtlMap of the movie pointer, std::map<int, CString>).
// MS2-UNIT: ?\loadingimagetable.cpp
// MS2-RANGE: 0x140d43fe0-0x140d4a310 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@$0A@@?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@QEAA@$$QEAU?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x140d45560 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@1@$$QEAU?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x140d459f0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@U?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@$$QEAU?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x140d46ac0 ; unique
// MS2-PIN: ??$emplace@U?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x140d46b10 ; unique
// MS2-PIN: ??$insert@U?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@X@?$map@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@4@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@IV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@1@@Z 0x140d46cd0 ; unique
// MS2-PIN: ??0Unk_MapRange@CLoadingImageTable@@QEAA@HH@Z 0x140d46fd0 ; unique
// MS2-PIN: ??0?$Unk_LiRowPtr@VLoadingImage@CLoadingImageTable@@@@QEAA@PEAVLoadingImage@CLoadingImageTable@@@Z 0x140d47040 ; unique
// MS2-PIN: ??0?$Unk_LiRowPtr@VLoadingMovie@CLoadingImageTable@@@@QEAA@H@Z 0x140d47090 ; unique
// MS2-PIN: ??0?$Unk_LiRowPtr@VLoadingMovie@CLoadingImageTable@@@@QEAA@PEAVLoadingMovie@CLoadingImageTable@@@Z 0x140d470b0 ; unique
// MS2-PIN: ??1CPair@?$CRBTree@IV?$Unk_LiRowPtr@VLoadingImage@CLoadingImageTable@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_LiRowPtr@VLoadingImage@CLoadingImageTable@@@@@3@@ATL@@IEAA@XZ 0x140d474d0 ; unique
// MS2-PIN: ?get@?$Unk_LiRowPtr@VLoadingImage@CLoadingImageTable@@@@QEBAPEAVLoadingImage@CLoadingImageTable@@XZ 0x140d47660 ; unique
// MS2-PIN: ?get@?$Unk_LiRowPtr@VLoadingMovie@CLoadingImageTable@@@@QEBAPEAVLoadingMovie@CLoadingImageTable@@XZ 0x140d47670 ; unique
// MS2-PIN: ??_G?$TSingleton@VCLoadingImageTable@@@@UEAAPEAXI@Z 0x140d47720 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$Unk_LiRowPtr@VLoadingImage@CLoadingImageTable@@@@V?$CElementTraits@V?$Unk_LiRowPtr@VLoadingImage@CLoadingImageTable@@@@@ATL@@@ATL@@QEBA_KXZ 0x140d47f90 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$Unk_LiRowPtr@VLoadingMovie@CLoadingImageTable@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$Unk_LiRowPtr@VLoadingMovie@CLoadingImageTable@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140d480a0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ?ms2_memmove_s_copy1@@YAHQEAX_KQEBX1@Z 0x140d4a1c0
// MS2-PIN: ??1LoadingImage@CLoadingImageTable@@UEAA@XZ 0x140d474f0
// MS2-PIN: ??1LoadingMovie@CLoadingImageTable@@UEAA@XZ 0x140d47530
// MS2-PIN: ??_7CLoadingImageTable@@6B?$TSingleton@VCLoadingImageTable@@@@@ 0x142e2bef8
// MS2-PIN: ??_7CLoadingImageTable@@6B?$CValidData@VCLoadingImageTable@@@@@ 0x142e2bf08
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\loadingimagetable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/guess/loadingimagetable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include <vector>
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
CString FUN_140cc2ad0(const CString& strDir, const CString& strFile);    // <dir>/<file>
CString FUN_14016a5c0(const char* psz, int nCodePage);                   // narrows a string (the RTTI name in CheckInit)
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
void FUN_140177e10(const CString& str, ATL::CAtlArray<int>& arr, const char* pszDelim);   // split into ints
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, CMsTime& tOut);   // time attribute
__int64 FUN_140869440();                                                 // the server time
unsigned FUN_140768010(unsigned nMax, int nMin);                         // random index
int FUN_1407181d0(CString* pStr);                                        // string to int

// A std::vector<CString> the exe keeps out of line (ctor 0x14027d6f0, dtor 0x14027e450).
class Unk_StrVec
{
public:
    Unk_StrVec();                          // 0x14027d6f0
    ~Unk_StrVec();                         // 0x14027e450
    size_t FUN_14028b4c0();
    CString* FUN_14027f1c0(size_t);
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_StrVec, 24);
void FUN_140275080(CString& str, Unk_StrVec* pOut, const char* pszDelim);   // splits into a std::vector<CString>

// The maps whose movie has already played (playOneTime).
class Unk_IdList { public: int FUN_140408410(const int& nId); };
extern Unk_IdList DAT_143ab3058;
extern int DAT_143ab2874;                                                // the current map code

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CLoadingImageTable::s_bInit;
#endif

// @0x140d43fe0
CLoadingImageTable::LoadingImage::LoadingImage()
    : m_nCode(0)
{
}

// @0x140d44070
bool CLoadingImageTable::LoadingImage::IsSameCondition(const LoadingImage& o) const
{
    if (m_startTime != o.m_startTime)
        return false;
    if (m_endTime != o.m_endTime)
        return false;
    if (m_strFile != o.m_strFile)
        return false;
    return true;
}

// @0x140d44100
int CLoadingImageTable::LoadingImage::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "code", m_nCode);
    FUN_140873600(pElem, "startTime", m_startTime);
    FUN_140873600(pElem, "endTime", m_endTime);
    ParseExceptMap(pElem, "exceptMap", m_exceptMaps);
    CString strBg;
    FUN_1408733e0(pElem, "bgLoading", strBg);
    if (strBg.GetLength() != 0)
    {
        if (strBg.Find(".dds", 0) == -1)
            strBg.AppendFormat(".dds");
        CString strDir("LoadingImage");
        m_strFile = FUN_140cc2ad0(strDir, strBg);
    }
    return 1;
}

// @0x140d44280
int CLoadingImageTable::LoadingImage::IsCommon() const
{
    return m_nCode == 0;
}

// @0x140d442c0
int CLoadingImageTable::LoadingImage::IsInPeriod() const
{
    if (m_strFile.GetLength() == 0)
        return 0;
    CMsTime now(FUN_140869440());
    if (m_startTime.Get() != 0)
    {
        if (now.Get() < m_startTime.Get())
            return 0;
    }
    if (m_endTime.Get() != 0)
    {
        if (now.Get() > m_endTime.Get())
            return 0;
    }
    return 1;
}

// @0x140d44390
int CLoadingImageTable::LoadingImage::IsExceptMap(int nMapCode) const
{
    for (size_t i = 0; i < m_exceptMaps.GetCount(); i++)
    {
        if (m_exceptMaps[i].FUN_1403b4ef0(nMapCode))
            return 1;
    }
    return 0;
}

// @0x140d44410
CLoadingImageTable::CLoadingImageTable()
    : m_mapImages(10)
{
}

// @0x140d444e0
CLoadingImageTable::~CLoadingImageTable()
{
    m_images.RemoveAll();
    m_mapImages.RemoveAll();
}

// @0x140d44590
int CLoadingImageTable::Load()
{
    SetInit(true);
    CString strPath = FUN_14071a5b0("Table", "loadingImage.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("image"); pNode != 0; pNode = pNode->FUN_140168650("image"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        ImagePtr spImage(new LoadingImage);
        if (spImage.get()->Load(pNode) != 0)
        {
            if (spImage.get()->IsCommon() == 0)
                m_mapImages.Insert(spImage.get()->m_nCode, spImage);
            else
                m_images.Add(spImage);
        }
        CString strMovie;
        FUN_1408733e0(pNode, "movieFileName", strMovie);
        if (strMovie.GetLength() != 0)
        {
            MoviePtr spMovie(new LoadingMovie);
            Unk_StrVec tokens;
            FUN_140275080(strMovie, &tokens, ",");
            for (size_t i = 0; i < tokens.FUN_14028b4c0(); i++)
            {
                tokens.FUN_14027f1c0(i)->Trim();
                Unk_StrVec parts;
                FUN_140275080(*tokens.FUN_14027f1c0(i), &parts, ":");
                if (parts.FUN_14028b4c0() == 2)
                {
                    unsigned nIndex = FUN_1407181d0(parts.FUN_14027f1c0(0));
                    CString strFile(parts.FUN_14027f1c0(1)->Trim());
                    spMovie.get()->m_files.insert(std::make_pair(nIndex, strFile));
                }
                else if (parts.FUN_14028b4c0() == 1)
                {
                    CString strFile(parts.FUN_14027f1c0(0)->Trim());
                    spMovie.get()->m_files.insert(std::make_pair(0u, strFile));
                }
            }
            FUN_1408731e0(pNode, "playOneTime", spMovie.get()->m_nPlayOneTime);
            m_movies.SetAt(spImage.get()->m_nCode, spMovie);
        }
    }
    return 1;
}

// @0x140d44bd0
int CLoadingImageTable::HasImage(int nMapCode)
{
    ATL::CAtlArray<ImagePtr> aImages;
    CollectImages(nMapCode, aImages, 1);
    return aImages.GetCount() != 0;
}

// @0x140d44c50
int CLoadingImageTable::IsSameImages(int nMapCode, int nOtherCode)
{
    ATL::CAtlArray<ImagePtr> aImages;
    ATL::CAtlArray<ImagePtr> aOthers;
    CollectImages(nMapCode, aImages, 0);
    CollectImages(nOtherCode, aOthers, 0);
    if (aImages.GetCount() != aOthers.GetCount())
        return 0;
    for (size_t i = 0; i < aImages.GetCount(); i++)
    {
        ImagePtr spImage(aImages[i]);
        int bFound = 0;
        for (size_t j = 0; j < aOthers.GetCount(); j++)
        {
            ImagePtr spOther(aOthers[j]);
            if (spImage.get()->IsSameCondition(*spOther.get()))
            {
                bFound = 1;
                break;
            }
        }
        if (!bFound)
            return 0;
    }
    return 1;
}

// @0x140d44e80
CString CLoadingImageTable::GetImageFile(int nMapCode, int bCommon)
{
    ATL::CAtlArray<ImagePtr> aImages;
    CollectImages(nMapCode, aImages, bCommon);
    if (aImages.GetCount() == 0)
        return CString("");
    ImagePtr spImage(aImages.GetAt(FUN_140768010(aImages.GetCount(), 0)));
    return CString(spImage.get()->m_strFile);
}

// @0x140d44f90
CString CLoadingImageTable::GetMovieFile(int nMapCode, unsigned nIndex)
{
    CString strEmpty("");
    MoviePtr spMovie(0);
    if (!m_movies.Lookup(nMapCode, spMovie))
        return strEmpty;
    if (spMovie.get()->m_nPlayOneTime != 0 && DAT_143ab3058.FUN_140408410(nMapCode) != -1)
        return strEmpty;
    if (spMovie.get()->m_files.empty())
        return strEmpty;
    if (spMovie.get()->m_files.find(nIndex) != spMovie.get()->m_files.end())
        return spMovie.get()->m_files[nIndex];
    else if (spMovie.get()->m_files.find(0) != spMovie.get()->m_files.end())
        return spMovie.get()->m_files[0];
    return strEmpty;
}

// @0x140d452d0
void CLoadingImageTable::CollectImages(int nMapCode, ATL::CAtlArray<ImagePtr>& aOut, int bCommon)
{
    CheckInit();
    if (bCommon != 0)
    {
        for (size_t i = 0; i < m_images.GetCount(); i++)
        {
            ImagePtr spImage = m_images[i];
            if (nMapCode == DAT_143ab2874)
                continue;
            if (spImage.get()->IsExceptMap(nMapCode) != 0)
                continue;
            if (spImage.get()->IsInPeriod() != 0)
                aOut.Add(spImage);
        }
    }
    POSITION pos = m_mapImages.FindFirstWithKey(nMapCode);
    while (pos != 0)
    {
        ImagePtr spImage = m_mapImages.GetNextValueWithKey(pos, nMapCode);
        if (spImage.get()->IsInPeriod() == 0)
            continue;
        aOut.Add(spImage);
    }
}

// @0x140d45660
int CLoadingImageTable::ParseExceptMap(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<Unk_MapRange>& aOut)
{
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet == 0)
    {
        ATL::CAtlArray<CString> tokens;
        FUN_14015f050(str, tokens, ",");
        for (size_t i = 0; i < tokens.GetCount(); i++)
        {
            ATL::CAtlArray<int> parts;
            FUN_140177e10(tokens[i], parts, "-");
            if (parts.GetCount() == 1)
            {
                int* pFrom = &parts[0];
                aOut.Add(Unk_MapRange(parts[0], *pFrom));
            }
            else if (parts.GetCount() == 2)
            {
                int* pTo = &parts[1];
                aOut.Add(Unk_MapRange(parts[0], *pTo));
            }
            else
            {
                return 2;
            }
        }
    }
    return nRet;
}

// @0x140d47280
CLoadingImageTable::LoadingMovie::LoadingMovie()
    : m_n18(0), m_nPlayOneTime(0)
{
}

// @0x140d47ae0
void CLoadingImageTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CLoadingImageTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
