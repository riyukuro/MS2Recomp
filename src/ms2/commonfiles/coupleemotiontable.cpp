// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCoupleEmotionTable: the couple emotion table
// (Table/coupleEmotion.xml), the animations two players play together per gender pairing.
// MS2-UNIT: commonfiles\coupleemotiontable.cpp
// MS2-RANGE: 0x1402c6c20-0x1402cb2a0 .text$mn
// MS2-PIN: ??_7CCoupleEmotionTable@@6B?$TSingleton@VCCoupleEmotionTable@@@@@ 0x142d20b58
// MS2-PIN: ??_7CCoupleEmotionTable@@6B?$CValidData@VCCoupleEmotionTable@@@@@ 0x142d20b68
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\coupleemotiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <utility>
#include "ms2/placeholder/ccoupleemotiontable.h"
#include "logstring.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
void FUN_140177a80(void* log, int level, int category, const wchar_t* format, const unsigned int& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
unsigned int FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned int nDefault);
void FUN_140275080(CString& str, void* pOut, const char* pszDelim);      // splits into a std::vector<CString>

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CCoupleEmotionTable::s_bInit;
#endif

// The unit's two-argument log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0).
template <class T, class U>
inline void Unk_CoupleEmotionLog(CLogString* log, int level, int category, const wchar_t* format, const T& first,
                                 const U& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// @0x1402c8940
inline void Unk_CoupleEmotionSplit(CString& str, std::vector<CString>& vec, const char* pszDelim)
{
    FUN_140275080(str, &vec, pszDelim);
}

// @0x1402c8970
inline bool Unk_CoupleEmotionBool(Unk_140165cf0* pElem, const char* pszName, bool bDefault)
{
    bool bValue;
    if (FUN_1408730a0(pElem, pszName, bValue) != 0)
        return bDefault;
    return bValue;
}

// @0x1402c6c20
CCoupleEmotionData::CCoupleEmotionData()
    : m_nId(0)
{
}

// @0x1402c6c90
CCoupleEmotionData::~CCoupleEmotionData()
{
}

// @0x1402c6ce0
bool CCoupleEmotionData::AddAni(int nGender1, int nGender2, MS2Ptr<AnimationData> spAni)
{
    if (nGender1 > nGender2)
        std::swap(nGender1, nGender2);
    m_anis.SetAt(MAKELONG(nGender1, nGender2), spAni);
    return true;
}

// @0x1402c6d70
MS2Ptr<CCoupleEmotionData::AnimationData> CCoupleEmotionData::GetAni(int nGender1, int nGender2)
{
    if (nGender1 > nGender2)
        std::swap(nGender1, nGender2);
    MS2Ptr<AnimationData> spAni(0);
    if (!m_anis.Lookup(MAKELONG(nGender1, nGender2), spAni))
        return 0;
    return spAni;
}

// @0x1402c6e60
CCoupleEmotionTable::CCoupleEmotionTable()
{
}

// @0x1402c6ee0
CCoupleEmotionTable::~CCoupleEmotionTable()
{
    m_data.RemoveAll();
}

// @0x1402c6f50
int CCoupleEmotionTable::Load()
{
    CString strPath = FUN_14071a5b0("Table", "coupleEmotion.xml");
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
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("coupleEmotion"); pElem != 0;
         pElem = pElem->FUN_140168650("coupleEmotion"))
    {
        MS2Ptr<CCoupleEmotionData> spData(new CCoupleEmotionData);
        spData->m_nId = FUN_140197390(pElem, "id", 0);
        {
            MS2Ptr<CCoupleEmotionData::AnimationData> spAni(new CCoupleEmotionData::AnimationData());
            CString str("");
            str = FUN_14015f710(pElem, "animationDiffGender_female", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_requestAnis, ",");
            str = FUN_14015f710(pElem, "animationDiffGender_male", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_targetAnis, ",");
            str = FUN_14015f710(pElem, "animationDiffGender_pathNif", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_nifPaths, ",");
            spAni->m_bLoop = Unk_CoupleEmotionBool(pElem, "animationDiffGender_loop", false);
            spData->AddAni(0, 1, spAni);
        }
        {
            MS2Ptr<CCoupleEmotionData::AnimationData> spAni(new CCoupleEmotionData::AnimationData());
            CString str("");
            str = FUN_14015f710(pElem, "animationSameGenderMale_requestUser", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_requestAnis, ",");
            str = FUN_14015f710(pElem, "animationSameGenderMale_targetUser", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_targetAnis, ",");
            str = FUN_14015f710(pElem, "animationSameGenderMale_pathNif", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_nifPaths, ",");
            spAni->m_bLoop = Unk_CoupleEmotionBool(pElem, "animationSameGenderMale_loop", false);
            spData->AddAni(0, 0, spAni);
        }
        {
            MS2Ptr<CCoupleEmotionData::AnimationData> spAni(new CCoupleEmotionData::AnimationData());
            CString str("");
            str = FUN_14015f710(pElem, "animationSameGenderFemale_requestUser", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_requestAnis, ",");
            str = FUN_14015f710(pElem, "animationSameGenderFemale_targetUser", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_targetAnis, ",");
            str = FUN_14015f710(pElem, "animationSameGenderFemale_pathNif", CString(""));
            str.Remove('[');
            str.Remove(']');
            str.Remove(' ');
            Unk_CoupleEmotionSplit(str, spAni->m_nifPaths, ",");
            spAni->m_bLoop = Unk_CoupleEmotionBool(pElem, "animationSameGenderFemale_loop", false);
            spData->AddAni(1, 1, spAni);
        }
        spData->m_strTeleportEffect = FUN_14015f710(pElem, "teleport_effect", CString((const char*)0));
        if (!Validate(spData))
            continue;
        m_data.SetAt(spData->m_nId, spData);
    }
    SetInit(true);
    return 1;
}

// @0x1402c7e10
MS2Ptr<CCoupleEmotionData> CCoupleEmotionTable::GetData(unsigned int nId)
{
    CheckInit();
    MS2Ptr<CCoupleEmotionData> spData(0);
    if (!m_data.Lookup(nId, spData))
        return 0;
    return spData;
}

// @0x1402c7ed0
int CCoupleEmotionTable::Validate(MS2Ptr<CCoupleEmotionData> spData)
{
    if (!spData)
    {
        MS2_ASSERT_AT(0xba, "pData" && 0);
        return 0;
    }
    for (POSITION pos = spData->m_anis.GetHeadPosition(); pos != 0; spData->m_anis.GetNext(pos))
    {
        MS2Ptr<CCoupleEmotionData::AnimationData> spAni = spData->m_anis.GetValueAt(pos);
        if (!spAni)
        {
            MS2_ASSERT_AT(0xbf, "pAniData" && 0);
            return 0;
        }
        if (!ValidateAni(spAni))
        {
            FUN_140177a80(GetLogString(), 1, 0x13, L"invalid couple_emotion data. id : {0}", spData->m_nId);
            return 0;
        }
    }
    return 1;
}

// @0x1402c8100
int CCoupleEmotionTable::ValidateAni(MS2Ptr<CCoupleEmotionData::AnimationData> spAni)
{
    if (!spAni)
    {
        MS2_ASSERT_AT(0xcd, "pAniData" && 0);
        return 0;
    }
    if (spAni->m_nifPaths.size() != spAni->m_requestAnis.size())
    {
        Unk_CoupleEmotionLog(GetLogString(), 1, 0x13, L"<{0}> 와 <{1}>의 갯수가 다릅니다", L"pathNifList",
                             L"animationNameList");
        return 0;
    }
    if (spAni->m_requestAnis.size() != spAni->m_targetAnis.size())
    {
        Unk_CoupleEmotionLog(GetLogString(), 1, 0x13, L"<{0}> 와 <{1}>의 갯수가 다릅니다", L"animationList_1",
                             L"animationList_2");
        return 0;
    }
    return 1;
}
