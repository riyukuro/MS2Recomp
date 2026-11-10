// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UgcHomeOptionData: the ugc home background / light /
// camera tables and the selection that is applied to the home map (plus the CRBMap<int, MS2Ptr<..>> template glue).
// MS2-UNIT: unit_140b67d70
// MS2-RANGE: 0x140b67d70-0x140b6c7a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugchomebgdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
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
#include <egf/Entity.h>   // C3: egf::EntityPtr (efd::SmartPointer<egf::Entity>::operator->)
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0

// Unrecovered xml loader helpers (the same ones the other table units use).
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view





// C3 #8: dead FUN_140165cf0 / FUN_140168650 view removed (callers use Unk_XmlNode::FirstChild / NextSibling)
void FUN_14028faa0(struct Unk_XmlElement*, char const*, char const*, std::vector<struct Unk_XmlElement*>&);   // C3: retyped to the commonutil def
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

int XmlGetAttr(class TiXmlElement*, char const*, class NiPoint3&);   // C3: was FUN_1408746f0
class Unk_UhFiles;
class CFileSystem   // C3: member view for the former free stand-ins
{
public:
    int LoadXmlFile(class TiXmlDocument*, char const*, int, bool, bool);
};
class CFileSystem* GetFileSystem();   // C3: was FUN_140166420
CString GetXmlPath(const CString& strDir, const CString& strFile);

extern Vector3 DAT_143a08d08;   // zero colour
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
#define DAT_143a08cf8 (*(Vector3*)&efd::Point3::UNIT_Z)          // C3: was extern Vector3 DAT_143a08cf8

// The statics of the home apply functions (opaque stand-ins for helpers of other units).
// The entity list a WorldService model lookup returns (worldservice.h declares it incomplete).
struct Unk_WsC_TagPtr
{
    ~Unk_WsC_TagPtr();                                                      // 0x1409f20e0
    ATL::CAtlList<efd::SmartPointer<egf::Entity> >* get() const { return (ATL::CAtlList<efd::SmartPointer<egf::Entity> >*)m_p; }   // 0x1409f2170
    ATL::CAtlList<efd::SmartPointer<egf::Entity> >* operator->() const;     // 0x1409f2190 (worldservice_1.cpp)
    void* m_a; void* m_p; void* m_c;
};
void* FUN_140b285b0(void* p);
void FUN_140b27f00(void* pEntity, unsigned id, void* p);

// The part of the camera manager used here (the current mode holder).
struct Unk_UhCameraView
{
    char m_pad_00[0x118];
    MS2Ptr<CCameraMode> m_mode;                                 // +0x118
};

void FUN_140b6bd30(void* pCamera);

// @0x140b67d70
UgcHomeBgData::UgcHomeBgData(CStringW strName, CString strPath)
    : m_strName(strName), m_strPath(strPath)
{
}

// @0x140b67e00
UgcHomeLightData::UgcHomeLightData(CStringW strName, NiPoint3 color)
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
NiPoint3 UgcHomeOptionData::GetLightColor(unsigned char nType)
{
    MS2Ptr<UgcHomeLightData> spData(0);
    if (m_mapLight.Lookup(nType, spData))
        return spData->m_color;
    return NiPoint3(reinterpret_cast<const efd::Point3&>(DAT_143a08d08));
}

// @0x140b68160
NiPoint3 UgcHomeOptionData::GetCameraOffset(unsigned char nType)
{
    MS2Ptr<UgcHomeCameraData> spData(0);
    if (m_mapCamera.Lookup(nType, spData))
        return spData->m_offset;
    return NiPoint3(reinterpret_cast<const efd::Point3&>(DAT_143b01a60));
}

// @0x140b68210
NiPoint3 UgcHomeOptionData::GetCameraUp(unsigned char nType)
{
    MS2Ptr<UgcHomeCameraData> spData(0);
    if (m_mapCamera.Lookup(nType, spData))
        return spData->m_upAxis;
    return NiPoint3(reinterpret_cast<const efd::Point3&>(DAT_143a08cf8));
}

// @0x140b682c0
void UgcHomeOptionData::ApplyBg(unsigned char nType)
{
    TSingleton<CUIService>::GetInstance()->LoadStageBackground(nType);
}

// @0x140b682f0
void UgcHomeOptionData::ApplyLight(unsigned char nType)
{
    NiPoint3 color = GetLightColor(nType);
    Unk_WsC_TagPtr hTag = WorldService::GetInstance()->FUN_141bd0420(0x169ea355);
    if ((hTag.get() != 0 ? true : false) && hTag->GetCount() > 0)
    {
        efd::SmartPointer<egf::Entity> ent(*reinterpret_cast<efd::SmartPointer<egf::Entity>*>(FUN_140b285b0(hTag.operator->())));
        efd::Color vec(color.x, color.y, color.z);
        FUN_140b27f00(reinterpret_cast<void*>(ent.operator->()), 0xb086f4a8, &vec);
    }
}

// @0x140b683f0
void UgcHomeOptionData::ApplyCamera(unsigned char nType)
{
    *reinterpret_cast<NiPoint3*>((char*)CameraMgr::GetInstance() + 200) = GetCameraOffset(nType);
    *reinterpret_cast<NiPoint3*>((char*)CameraMgr::GetInstance() + 0xd4) = GetCameraUp(nType);
    CameraMgr::GetInstance()->SetMode(0x11, 1);
    FUN_140b6bd30(CameraMgr::GetInstance());
}

// @0x140b684a0
void UgcHomeOptionData::LoadBg()
{
    TiXmlDocument doc;
    bool bFailed = ((class CFileSystem*)(class Unk_UhFiles*)(((class Unk_UhFiles*)GetFileSystem())))->LoadXmlFile(&doc, GetXmlPath("Table", "ugcBackground.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
        return;
    m_mapBg.RemoveAll();
    std::vector<Unk_XmlNode*> list;
    FUN_14028faa0((struct Unk_XmlElement*)(pRoot), "list", "id", *reinterpret_cast<std::vector<struct Unk_XmlElement*>*>(&list));
    for (unsigned __int64 i = 0; i < list.size(); ++i)
    {
        TiXmlElement* pNode = reinterpret_cast<TiXmlElement*&>(list[i]);
        unsigned nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", nId);
        CString strPath;
        XmlGetAttr((class TiXmlElement*)(pNode), "path", strPath);
        MS2Ptr<UgcHomeBgData> spData(new UgcHomeBgData(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x33, nId), strPath));
        m_mapBg.SetAt((unsigned)m_mapBg.GetCount(), spData);
    }
}

// @0x140b68810
void UgcHomeOptionData::LoadLight()
{
    TiXmlDocument doc;
    bool bFailed = ((class CFileSystem*)(class Unk_UhFiles*)(((class Unk_UhFiles*)GetFileSystem())))->LoadXmlFile(&doc, GetXmlPath("Table", "ugcHousingLight.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
        return;
    m_mapLight.RemoveAll();
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("list")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("list")))
    {
        unsigned nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", nId);
        NiPoint3 color;
        XmlGetAttr((class TiXmlElement*)(pNode), "ambientcolor", color);
        (reinterpret_cast<Vector3&>(color) /= 255.0f);   // C3: efd::Point3::operator/= on the Vector3 view (nipoint3.h)
        MS2Ptr<UgcHomeLightData> spData(new UgcHomeLightData(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x33, nId), color));
        m_mapLight.SetAt((unsigned)m_mapLight.GetCount(), spData);
    }
}

// @0x140b68b20
void UgcHomeOptionData::LoadCamera()
{
    TiXmlDocument doc;
    bool bFailed = ((class CFileSystem*)(class Unk_UhFiles*)(((class Unk_UhFiles*)GetFileSystem())))->LoadXmlFile(&doc, GetXmlPath("Table", "ugcHousingCamera.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
        return;
    m_mapCamera.RemoveAll();
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("list")); pNode != 0; pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->NextSibling("list")))
    {
        unsigned nId = 0;
        XmlGetAttr((class TiXmlElement*)(pNode), "id", nId);
        NiPoint3 offset(reinterpret_cast<const efd::Point3&>(DAT_143b01a60));
        XmlGetAttr((class TiXmlElement*)(pNode), "offset", offset);
        NiPoint3 upAxis(reinterpret_cast<const efd::Point3&>(DAT_143b01a60));
        XmlGetAttr((class TiXmlElement*)(pNode), "upAxis", upAxis);
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
    if (reinterpret_cast<Unk_UhCameraView*>(pCamera)->m_mode.get() != 0)
        reinterpret_cast<Unk_UhCameraView*>(pCamera)->m_mode->vfunc_10();
}

// @0x140b6c680
#pragma function(memset, memcpy)
unsigned __int64 FUN_140b6c680(void* pDst, unsigned __int64 nDstSize, const void* pSrc, unsigned __int64 nCount)
{
    if (nCount == 0) { return 0; }
    { int e = !!(pDst != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(pSrc != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(nDstSize >= nCount); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memmove(pDst, pSrc, nCount);
    return 0;
}
#pragma intrinsic(memset, memcpy)
