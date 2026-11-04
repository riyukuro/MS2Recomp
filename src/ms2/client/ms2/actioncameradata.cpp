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
#include "ms2/commonfiles/filesystem.h"
#include <efd/ILogger.h>
#include <efd/Helpers.h>
class Unk_140165cf0;
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// Game TinyXML element: FirstChildElement by name.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);
};
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
CString FUN_140188f50(const char* psz, int n);
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
unsigned char FUN_1401d1320(CCacheData*);

class Unk_ActionFiles : public CFileSystem { };
class CLogString;
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was V::FUN_14015eb90
class Unk_ActionLog { public: };
class CLogString* GetLogString();   // C3: was FUN_140166440

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
    if (((class Unk_ActionFiles*)GetFileSystem())->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return DataPtr(0);
    Unk_140165cf0* pRoot = ((class Unk_140165cf0*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        EE_LOG_AT(1, 1, ("Failed to read %s", (const char*)strPath), MS2_THIS_FILE, 0x34);
        return DataPtr(0);
    }
    DataPtr spData(new CActionCameraData);
    spData->FUN_1401d1160(CString(strPath));
    ActionCameraInfo* pInfo = spData->GetInfo();
    Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("actionCamera"));
    pInfo->m_strPath = ((class TiXmlElement*)(class Unk_140165cf0*)(pNode))->Attribute("path");
    CString strStay = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pNode))->Attribute("stayLocked"), 0);
    pInfo->m_bStayLocked = (strStay == "true");
    XmlGetAttr((class TiXmlElement*)(pNode), "interpolationTime", pInfo->m_fInterpolationTime);
    return spData;
}


// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9d2d0-0x142c9d2f0 .text$yd
