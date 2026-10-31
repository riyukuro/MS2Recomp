// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UgcHomeOptionData: the ugc home background / light /
// camera tables and the selection that is applied to the home map (plus the CRBMap<int, MS2Ptr<..>> template glue).
// MS2-UNIT: unit_140b67d70
// MS2-RANGE: 0x140b67d70-0x140b6c7a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugchomebgdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugchomebgdata.h"
#include "ms2/client/ms2/cameramode.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"

// Unrecovered xml loader helpers (the same ones the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);       // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char* pszName);       // NextSiblingElement
};
class Unk_UhXmlList
{
public:
    Unk_UhXmlList();                                            // 0x140163e20
    ~Unk_UhXmlList();                                           // 0x1401644e0
    unsigned __int64 FUN_14016d900();                           // size
    Unk_140165cf0*& FUN_140164a30(unsigned __int64 n);          // operator[]
    void *m_a, *m_b, *m_c;
};
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, Unk_UhXmlList* pOut);
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);   // string attribute
int XmlGetAttr(class TiXmlElement*, char const*, class NiPoint3&);   // C3: was FUN_1408746f0
class Unk_UhFiles;
class CFileSystem   // C3: member view for the former free stand-ins
{
public:
    int FUN_1403974b0(class TiXmlDocument*, char const*, int, bool, bool);
};
class CFileSystem* GetFileSystem();   // C3: was FUN_140166420
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);

extern Vector3 DAT_143a08d08;   // zero colour
extern Vector3 DAT_143b01a60;   // zero point
extern Vector3 DAT_143a08cf8;   // zero up axis

// The statics of the home apply functions (opaque stand-ins for helpers of other units).
class Unk_UhUiService { public: void FUN_141ad9980(unsigned char nStage); };
struct Unk_UhHandle;
struct Unk_UhWorld { Unk_UhHandle FUN_141bd0420(unsigned hash); };   // the tagged-entity lookup of the world service
void FUN_14097faa0(void* pDst, const Unk_UhPoint3& pt);     // NiPoint3::operator=
struct Unk_UhHandle { ~Unk_UhHandle(); void* m_a; void* m_p; void* m_c; };   // 24 byte handle, released at 0x1409f20e0
long long FUN_1409f2170(Unk_UhHandle* h);   // get()
void* FUN_1409f2190(Unk_UhHandle* h);
void* FUN_140b285b0(void* p);
struct Unk_UhEntRef { Unk_UhEntRef(void* p); ~Unk_UhEntRef(); void* m_p; };    // 0x1408a7ed0 / 0x1408a8720
void* FUN_1408a9280(Unk_UhEntRef* r);
struct Unk_UhVec3f { Unk_UhVec3f(float x, float y, float z); float x, y, z; };   // 0x1406c4340
void FUN_140b27f00(void* pEntity, unsigned id, void* p);

// The part of the camera manager used here (the current mode holder).
struct Unk_UhModeRef
{
    long long FUN_1409f2180() const;                            // non-null test
    CCameraMode* FUN_1409f21a0() const;                         // operator->
    void* m_pad_00;
    CCameraMode* m_p;
};
struct Unk_UhCameraView
{
    char m_pad_00[0x118];
    Unk_UhModeRef m_mode;                                       // +0x118
};

void FUN_140b6bd30(void* pCamera);

// @0x140b67d70
UgcHomeBgData::UgcHomeBgData(CStringW strName, CString strPath)
    : m_strName(strName), m_strPath(strPath)
{
}

// @0x140b67e00
UgcHomeLightData::UgcHomeLightData(CStringW strName, Unk_UhPoint3 color)
    : m_strName(strName), m_color(color)
{
}

// @0x140b67e90
UgcHomeCameraData::UgcHomeCameraData(CStringW strName)
    : m_strName(strName)
{
}

// @0x140b67f20
UgcHomeOptionData::UgcHomeOptionData()
    : m_mapBg(10), m_mapLight(10), m_mapCamera(10)
{
}

// @0x140b67fa0
void UgcHomeOptionData::Load()
{
    LoadBg();
    LoadLight();
    LoadCamera();
}

// @0x140b67fe0
CString UgcHomeOptionData::GetBgPath(unsigned char nType)
{
    MS2Ptr<UgcHomeBgData> spData(0);
    if (m_mapBg.Lookup(nType, spData))
        return spData->m_strPath;
    return CString("");
}

// @0x140b680b0
Unk_UhPoint3 UgcHomeOptionData::GetLightColor(unsigned char nType)
{
    MS2Ptr<UgcHomeLightData> spData(0);
    if (m_mapLight.Lookup(nType, spData))
        return spData->m_color;
    return Unk_UhPoint3(DAT_143a08d08);
}

// @0x140b68160
Unk_UhPoint3 UgcHomeOptionData::GetCameraOffset(unsigned char nType)
{
    MS2Ptr<UgcHomeCameraData> spData(0);
    if (m_mapCamera.Lookup(nType, spData))
        return spData->m_offset;
    return Unk_UhPoint3(DAT_143b01a60);
}

// @0x140b68210
Unk_UhPoint3 UgcHomeOptionData::GetCameraUp(unsigned char nType)
{
    MS2Ptr<UgcHomeCameraData> spData(0);
    if (m_mapCamera.Lookup(nType, spData))
        return spData->m_upAxis;
    return Unk_UhPoint3(DAT_143a08cf8);
}

// @0x140b682c0
void UgcHomeOptionData::ApplyBg(unsigned char nType)
{
    reinterpret_cast<Unk_UhUiService*>(TSingleton<CUIService>::GetInstance())->FUN_141ad9980(nType);
}

// @0x140b682f0
void UgcHomeOptionData::ApplyLight(unsigned char nType)
{
    Unk_UhPoint3 color = GetLightColor(nType);
    Unk_UhHandle hTag = reinterpret_cast<Unk_UhWorld*>(WorldService::GetInstance())->FUN_141bd0420(0x169ea355);
    if ((FUN_1409f2170(&hTag) != 0 ? true : false) && ((ATL::CAtlList<efd::SmartPointer<egf::Entity>, ATL::CElementTraits<efd::SmartPointer<egf::Entity>>>*)(void*)(FUN_1409f2190(&hTag)))->GetCount() > 0)
    {
        Unk_UhEntRef ent(FUN_140b285b0(FUN_1409f2190(&hTag)));
        Unk_UhVec3f vec(color.x, color.y, color.z);
        FUN_140b27f00(FUN_1408a9280(&ent), 0xb086f4a8, &vec);
    }
}

// @0x140b683f0
void UgcHomeOptionData::ApplyCamera(unsigned char nType)
{
    FUN_14097faa0((char*)CameraMgr::GetInstance() + 200, GetCameraOffset(nType));
    FUN_14097faa0((char*)CameraMgr::GetInstance() + 0xd4, GetCameraUp(nType));
    CameraMgr::GetInstance()->FUN_140aed750(0x11, 1);
    FUN_140b6bd30(CameraMgr::GetInstance());
}

// @0x140b684a0
void UgcHomeOptionData::LoadBg()
{
    TiXmlDocument doc;
    bool bFailed = ((class CFileSystem*)(class Unk_UhFiles*)(((class Unk_UhFiles*)GetFileSystem())))->FUN_1403974b0(&doc, FUN_14071a5b0("Table", "ugcBackground.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return;
    m_mapBg.RemoveAll();
    Unk_UhXmlList list;
    FUN_14028faa0(pRoot, "list", "id", &list);
    for (unsigned __int64 i = 0; i < list.FUN_14016d900(); ++i)
    {
        Unk_140165cf0* pNode = list.FUN_140164a30(i);
        unsigned nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", nId);
        CString strPath;
        FUN_1408733e0(pNode, "path", strPath);
        MS2Ptr<UgcHomeBgData> spData(new UgcHomeBgData(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x33, nId), strPath));
        m_mapBg.SetAt((unsigned)m_mapBg.GetCount(), spData);
    }
}

// @0x140b68810
void UgcHomeOptionData::LoadLight()
{
    TiXmlDocument doc;
    bool bFailed = ((class CFileSystem*)(class Unk_UhFiles*)(((class Unk_UhFiles*)GetFileSystem())))->FUN_1403974b0(&doc, FUN_14071a5b0("Table", "ugcHousingLight.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return;
    m_mapLight.RemoveAll();
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("list"); pNode != 0; pNode = pNode->FUN_140168650("list"))
    {
        unsigned nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", nId);
        Unk_UhPoint3 color;
        XmlGetAttr((class TiXmlElement*)(pNode), "ambientcolor", *(class NiPoint3*)&static_cast<struct Unk_UhPoint3&>(color));
        color.FUN_140ae9270(255.0f);
        MS2Ptr<UgcHomeLightData> spData(new UgcHomeLightData(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x33, nId), color));
        m_mapLight.SetAt((unsigned)m_mapLight.GetCount(), spData);
    }
}

// @0x140b68b20
void UgcHomeOptionData::LoadCamera()
{
    TiXmlDocument doc;
    bool bFailed = ((class CFileSystem*)(class Unk_UhFiles*)(((class Unk_UhFiles*)GetFileSystem())))->FUN_1403974b0(&doc, FUN_14071a5b0("Table", "ugcHousingCamera.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return;
    m_mapCamera.RemoveAll();
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("list"); pNode != 0; pNode = pNode->FUN_140168650("list"))
    {
        unsigned nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", nId);
        Unk_UhPoint3 offset(DAT_143b01a60);
        XmlGetAttr((class TiXmlElement*)(pNode), "offset", *(class NiPoint3*)&static_cast<struct Unk_UhPoint3&>(offset));
        Unk_UhPoint3 upAxis(DAT_143b01a60);
        XmlGetAttr((class TiXmlElement*)(pNode), "upAxis", *(class NiPoint3*)&static_cast<struct Unk_UhPoint3&>(upAxis));
        MS2Ptr<UgcHomeCameraData> spData(new UgcHomeCameraData(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x33, nId)));
        spData->m_offset = offset;
        spData->m_upAxis = upAxis;
        m_mapCamera.SetAt((unsigned)m_mapCamera.GetCount(), spData);
    }
}

// @0x140b68e60
Unk_UhSetting::Unk_UhSetting()
{
    m_nBg = 0;
    m_nLight = 0;
    m_nCamera = 0;
}

// @0x140b68e90
void Unk_UhSetting::Reset()
{
    m_nBg = 0;
    m_nLight = 0;
    m_nCamera = 0;
}

// @0x140b68ec0
void Unk_UhSetting::Read(CInPacket& packet)
{
    m_nBg = packet.ReadUInt8();
    m_nLight = packet.ReadUInt8();
    m_nCamera = packet.ReadUInt8();
}

// @0x140b68f60
void Unk_UhSetting::Apply()
{
    UgcHomeOptionData::GetInstance()->ApplyBg(m_nBg);
    UgcHomeOptionData::GetInstance()->ApplyLight(m_nLight);
    UgcHomeOptionData::GetInstance()->ApplyCamera(m_nCamera);
}

// @0x140b6bd30
void FUN_140b6bd30(void* pCamera)
{
    if (reinterpret_cast<Unk_UhCameraView*>(pCamera)->m_mode.FUN_1409f2180() != 0)
        reinterpret_cast<Unk_UhCameraView*>(pCamera)->m_mode.FUN_1409f21a0()->vfunc_10();
}

// @0x140b6c680
// MS2-FUNCTIONAL: CRT memcpy_s copy (library lane); same checks and errno values as the CRT
unsigned __int64 FUN_140b6c680(void* pDst, unsigned __int64 nDstSize, const void* pSrc, unsigned __int64 nCount)
{
    if (nCount == 0)
        return 0;
    if (pDst == 0 || pSrc == 0 || nDstSize < nCount)
    {
        int nErr = (pDst == 0 || pSrc == 0) ? 22 : 34;
        *_errno() = nErr;
        _invalid_parameter_noinfo();
        return nErr;
    }
    memmove(pDst, pSrc, nCount);
    return 0;
}
