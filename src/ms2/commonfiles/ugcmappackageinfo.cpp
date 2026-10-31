// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ugcmappackageinfo.cpp
// MS2-RANGE: 0x1408b9860-0x1408bb9d0 .text$mn
// MS2-RANGE: 0x1400bdfc0-0x1400be020 .text$di
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2SvrPtr@VCUGCMapPackageData@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2SvrPtr@VCUGCMapPackageData@@@@@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEBV?$MS2SvrPtr@VCUGCMapPackageData@@@@@Z 0x1408bb6d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcmappackageinfo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcmappackageinfo.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"

// Unrecovered helpers.
class Unk_1401b4ec0 { public: Unk_1401b4ec0(CLockCriticalSection&, int); ~Unk_1401b4ec0(); private: void* m_p; };
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
void FUN_140873220(void*, const char*, int&);
void FUN_140873360(void*, const char*, float&);
void FUN_1408730a0(void*, const char*, bool&);
int FUN_1408733e0(void*, const char*, CString&);
int FUN_140873890(void*, const char*, int&);
void FUN_140177de0(CString&, ATL::CAtlArray<int>&, const char* delimiter);
Unk_Int3* FUN_1408a85a0(Unk_Int3*, int, int, int);
void FUN_1401d1160(CCacheData*, CString);
unsigned char FUN_1401d1320(CCacheData*);

typedef ATL::CRBMap<CString, UGCMapPackageDataPtr> UGCMapPackageCache;

static CLockCriticalSection s_lock;
static UGCMapPackageCache s_cache;

// @0x1408b9860
UGCMapPackageInfo::UGCMapPackageInfo()
{
    m_nItemId = 0;
    m_nItemCount = 1;
    FUN_1408a85a0(&m_offsetCubePoint, 0, 0, 0);
    m_fRotation = 0;
    m_nWallDir = 0;
    m_bNotPlace = 0;
}

// @0x1408ba070
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
static int FUN_1408ba070(void* pNode, const char* pszName, int* pOut)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xe7, FALSE);
        return 2;
    }
    int value = 0;
    int result = FUN_140873890(pNode, pszName, value);
    if (result != 0)
        return result;
    *pOut = value;
    return result;
}

#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcmappackageinfo.cpp"
// @0x1408ba3b0
// MS2-FUNCTIONAL: frame has the EH slot at +0x20 in the exe (array at +0x28); cl places both 8 bytes higher
static Unk_Int3* FUN_1408ba3b0(Unk_Int3* out, CString& text)
{
    ATL::CAtlArray<int> parts;
    FUN_140177de0(text, parts, ",");
    if (parts.GetCount() == 3)
    {
        out->x = parts[0];
        out->y = parts[1];
        out->z = parts[2];
    }
    else
    {
        out->z = 0;
        out->y = 0;
        out->x = 0;
    }
    return out;
}

// @0x1408b98f0
void UGCMapPackageInfo::FUN_1408b98f0(void* pXmlNode)
{
    FUN_140873220(pXmlNode, "itemID", m_nItemId);
    FUN_140873220(pXmlNode, "itemCount", m_nItemCount);
    CString strPoint;
    FUN_1408733e0(pXmlNode, "offsetCubePoint3", strPoint);
    Unk_Int3 tmp;
    FUN_1408ba3b0(&tmp, strPoint);
    m_offsetCubePoint = tmp;
    FUN_140873360(pXmlNode, "rotation", m_fRotation);
    FUN_1408ba070(pXmlNode, "wallDir", &m_nWallDir);
    FUN_1408730a0(pXmlNode, "isNotPlace", m_bNotPlace);
}

// @0x1408b9a00
CUGCMapPackageData::CUGCMapPackageData()
{
}

// @0x1408b9a60
CUGCMapPackageData::~CUGCMapPackageData()
{
}

#ifndef MS2_HOOK_DLL
// @0x1408b9ab0
int CUGCMapPackageData::FUN_1408b9ab0(int nItemId)
{
    Unk_1401b4ec0 lock(s_lock, 1);
    int nCount = 0;
    for (unsigned int i = 0; i < m_cubes.GetCount(); ++i)
    {
        UGCMapPackageInfoPtr p(static_cast<const UGCMapPackageInfoPtr&>(m_cubes[i]));
        if (p->m_nItemId == nItemId)
            nCount = nCount + 1;
    }
    return nCount;
}
#endif

// @0x1408b9b90
UGCMapPackageDataPtr FUN_1408b9b90(const CString& strName)
{
    UGCMapPackageDataPtr found(0);
    if (Unk_LockGuard guard = s_lock) {}
    else
    {
        if (s_cache.Lookup(strName, found))
        {
            if (FUN_1401d1320(found.operator->()) == 0)
                return found;
        }
    }
    return LoadExportedUGCMap(strName);
}

void FUN_1408b9c90();
#ifndef MS2_HOOK_DLL
// @0x1408b9c90
void FUN_1408b9c90()
{
    s_cache.RemoveAll();
}
#endif

// @0x1408b9cb0
UGCMapPackageDataPtr LoadExportedUGCMap(const CString& strName)
{
    CString strPath;
    strPath.Format("./Data/Xml/ExportedUGCMap/%s.xml", (const char*)strName);
    TiXmlDocument doc;
    if (GetFileSystem()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return UGCMapPackageDataPtr(0);
    UGCMapPackageDataPtr data(new CUGCMapPackageData);
    FUN_1401d1160(data.get(), strPath);
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ugcmap");
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ugcmap> {0}]", strPath);
        return UGCMapPackageDataPtr(0);
    }
    FUN_1408733e0(pRoot, "indoorSizeType", data->m_strIndoorSizeType);
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("cube"); pNode != 0;
         pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650("cube")))
    {
        UGCMapPackageInfoPtr info(new UGCMapPackageInfo);
        info->FUN_1408b98f0(pNode);
        data->m_cubes.Add(info);
    }
    {
        Unk_LockGuard guard(s_lock);
        if (static_cast<int>(guard) != 0)
        {
        }
        else
            s_cache.SetAt(strName, data);
    }
    return data;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c9b0-0x142c9c9f0 .text$yd
