// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See actioncameradata.h.
// MS2-UNIT: client\ms2\actioncameradata.cpp
// MS2-RANGE: 0x1409436b0-0x140944f30 .text$mn
// MS2-RANGE: 0x1400bf220-0x1400bf250 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\actioncameradata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "actioncameradata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/ILogger.h>
#include <efd/Helpers.h>

// Game TinyXML element: FirstChildElement by name.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);
};
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
CString FUN_140188f50(const char* psz, int n);
bool FUN_140184310(const CString& str, const char* psz);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
unsigned char FUN_1401d1320(CCacheData*);

class Unk_ActionFiles { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_ActionFiles* FUN_140166420();
class Unk_ActionLog { public: void FUN_14015eb90(int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg); };
Unk_ActionLog* FUN_140166440();

extern int DAT_1439ed00c;   // camera cache enabled

typedef ATL::CRBMap<CString, CActionCameraData::DataPtr> ActionCameraMap;
// @0x1400bf220
static ActionCameraMap s_mapCache(10);

// @0x1409436b0
CActionCameraData::CActionCameraData()
{
}

// @0x140943700
CActionCameraData::~CActionCameraData()
{
}

// @0x140943740
CActionCameraData::DataPtr CActionCameraData::Get(CString strName)
{
    DataPtr spData(0);
    if (DAT_1439ed00c != 0 && s_mapCache.Lookup(strName, spData) && !FUN_1401d1320(spData))
        return spData;
    spData = Load(strName);
    if (spData.get())
        s_mapCache.SetAt(strName, spData);
    return spData;
}

// @0x140943890
CActionCameraData::DataPtr CActionCameraData::Load(const CString& strName)
{
    CString strPath = FUN_14071a5b0("Camera", strName);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return DataPtr(0);
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        EE_LOG_AT(1, 1, ("Failed to read %s", (const char*)strPath), MS2_THIS_FILE, 0x34);
        return DataPtr(0);
    }
    DataPtr spData(new CActionCameraData);
    spData->FUN_1401d1160(CString(strPath));
    ActionCameraInfo* pInfo = spData->GetInfo();
    Unk_140165cf0* pNode = pRoot->FUN_140165cf0("actionCamera");
    pInfo->m_strPath = FUN_14086f4b0(pNode, "path");
    CString strStay = FUN_140188f50(FUN_14086f4b0(pNode, "stayLocked"), 0);
    pInfo->m_bStayLocked = FUN_140184310(strStay, "true");
    FUN_140873360(pNode, "interpolationTime", pInfo->m_fInterpolationTime);
    return spData;
}


// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9d2d0-0x142c9d2f0 .text$yd
