// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ms2/placeholder/freecameramode.h.
// MS2-UNIT: ?\freecameramode.cpp
// MS2-RANGE: 0x1412221e0-0x141222df0 .text$mn
// MS2-PIN: ??_GCFreeCameraMode@@UEAAPEAXI@Z 0x141222d90
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\freecameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/freecameramode.h"
#include "ms2/placeholder/tixmldocument.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/uiservice.h"
#include <efd/Matrix3.h>
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940
#include <NiPoint3.h>
#include "ms2/client/ms2/fielddatacli.h"   // C3: MS2Ptr<CFieldDataCli>, the option row
template <class T> class TSingleton;
class CameraMgr { public: Vector3 FUN_140a38d00(); void FUN_140a38d90(Vector3 pt); };   // C3: member view (was Unk_CameraManager)
template <> class TSingleton<CameraMgr> { public: static CameraMgr* GetInstance(); };   // C3: 0x1409478c0, as camera.h declares it

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The camera option row held by the game context (+0x1f4 fov).
struct Unk_FreeCamOption
{
    char m_pad_000[0x1f4];
    float m_1f4;
};

class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();   // copy of +0x298 (worldservice.h)
    static class WorldService* GetInstance();
};

// The UI service (TSingleton<CUIService>::GetInstance).

// The game's TinyXML element (0x90 bytes).
class TiXmlElement
{
public:
    TiXmlElement(const char* pszValue);                         // 0x14086f2f0
private:
    char m_pad_00[0x90];
};
class TiXmlNode   // C3: member view for the former free stand-ins
{
public:
    class TiXmlNode* LinkEndChild(class TiXmlNode*);
};
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};
void XmlSetAttr(class TiXmlElement*, char const*, float);   // C3: was FUN_140873e30
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
// The exe writes NiPoint3 attributes: each efd::Point3 converts through the out-of-line NiPoint3(const efd::Point3&).
void XmlSetAttr(class TiXmlElement*, char const*, const efd::Point3&);   // C3: was FUN_140874ad0 (NiPoint3 view); callers cast it to a const NiPoint3& signature so the Point3 converts implicitly (lea of the temp, as in the exe)

float FUN_140a38cd0(float f);                       // fabs

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x1412221e0
CFreeCameraMode::CFreeCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev)
{
    m_78 = g_143b01a60;
}

// @0x141222290
CFreeCameraMode::~CFreeCameraMode()
{
}

// @0x1412222c0
void CFreeCameraMode::vfunc_8(double fTime)
{
    Vector3 ptMove = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d00();
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(0, true, 0) && ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(1, true, 0))
    {
        efd::Point3 ptPos = FUN_1409f2540();
        ptPos.z = ptPos.z - ptMove.z * 2.0f;
        vfunc_3(reinterpret_cast<Vector3&>(ptPos));
    }
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(1, true, 0))
    {
        if (reinterpret_cast<const efd::Point3&>(ptMove) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
        {
            Vector3 ptInput = ptMove;
            float fRate = 15.0f;
            float fStep = efd::Clamp((float)fTime, 0.0f, 1.0f / fRate);
            float fAbsZ = FUN_140a38cd0(ptInput.z);
            float fMaxYZ = efd::Max<float>(FUN_140a38cd0(ptInput.y), fAbsZ);
            float fMax = efd::Max<float>(FUN_140a38cd0(ptInput.x), fMaxYZ);
            float fScale = fStep * fMax;
            float fRotX = ptInput.y * fScale;
            float fRotY = ptInput.z * fScale;
            if (fRotX != 0.0f || fRotY != 0.0f)
            {
                if (1.0f < FUN_140a38cd0(fRotX))
                    fRotX = (fRotX < 0.0f) ? -1.0f : 1.0f;
                if (1.0f < FUN_140a38cd0(fRotY))
                    fRotY = (fRotY < 0.0f) ? -1.0f : 1.0f;
                Vector3 ptRot = FUN_140af8260();
                ptRot.y = ptRot.y - fRotX;
                ptRot.z = ptRot.z - fRotY;
                vfunc_4(ptRot);
            }
        }
    }
    else
    {
        if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116da30(0x22, true, 0))
        {
            Unk_CameraTargetEntity* pActor = ((class Unk_CameraTargetEntity*)WorldService::GetInstance()->FUN_141bd0cc0());
            if (pActor != 0)
            {
                MS2Ptr<CFieldDataCli> spOption = WorldService::GetInstance()->FUN_141bd30a0();
                if (reinterpret_cast<Unk_FreeCamOption*>(spOption.get()) != 0)
                {
                    TiXmlDocument doc;
                    if (!doc.LoadFile("./data/xml/camera/customize.xml", TIXML_ENCODING_UNKNOWN))
                    {
                        ((void*)((class TiXmlNode*)(void*)(&doc))->LinkEndChild((class TiXmlNode*)(new TiXmlElement("ms2"))));
                    }
                    TiXmlElement* pMs2 = ((class TiXmlElement*)((class Unk_XmlNode*)(class TiXmlDocument*)(&doc))->FirstChild("ms2"));
                    if (pMs2 != 0)
                    {
                        Vector3 ptDir = (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(FUN_1409f2540())) - pActor->vfunc_18());
                        float fDist = ptDir.Unitize();
                        TiXmlElement* pCamera = new TiXmlElement("camera");
                        ((void*)((class TiXmlNode*)(void*)(pMs2))->LinkEndChild((class TiXmlNode*)(pCamera)));
                        XmlSetAttr((class TiXmlElement*)(pCamera), "fov", reinterpret_cast<Unk_FreeCamOption*>(spOption.operator->())->m_1f4);
                        XmlSetAttr((class TiXmlElement*)(pCamera), "distance", fDist);
                        XmlSetAttr((class TiXmlElement*)(pCamera), "zoomIn", 50);
                        XmlSetAttr((class TiXmlElement*)(pCamera), "zoomOut", 150);
                        reinterpret_cast<void (*)(class TiXmlElement*, const char*, const NiPoint3&)>(static_cast<void (*)(class TiXmlElement*, const char*, const efd::Point3&)>(&XmlSetAttr))((class TiXmlElement*)(pCamera), "direction", reinterpret_cast<const efd::Point3&>(ptDir));
                        reinterpret_cast<void (*)(class TiXmlElement*, const char*, const NiPoint3&)>(static_cast<void (*)(class TiXmlElement*, const char*, const efd::Point3&)>(&XmlSetAttr))((class TiXmlElement*)(pCamera), "rotation", reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(FUN_140af8260())));
                        doc.SaveFile();
                    }
                }
            }
        }
    }
    if (reinterpret_cast<const efd::Point3&>(m_78) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
    {
        Vector3 ptRot = FUN_140af8260();
        ptRot = (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptRot) * 3.14159274f)) / 180.0f);
        Unk_EfdMatrix3 kRot;
        reinterpret_cast<efd::Matrix3*>(&kRot)->FromEulerAnglesXYZ(ptRot.x, ptRot.y, ptRot.z);
        Vector3 ptRight;
        reinterpret_cast<efd::Matrix3*>(&kRot)->GetCol(0, *reinterpret_cast<efd::Point3*>(&ptRight));
        ptRight.Unitize();
        Vector3 ptForward;
        reinterpret_cast<efd::Matrix3*>(&kRot)->GetCol(2, *reinterpret_cast<efd::Point3*>(&ptForward));
        ptForward.Unitize();
        efd::Point3 ptPos = FUN_1409f2540();
        reinterpret_cast<Vector3&>(ptPos) = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(reinterpret_cast<Vector3&>(ptPos)) + (reinterpret_cast<const efd::Point3&>(ptRight) * m_78.x + reinterpret_cast<const efd::Point3&>(ptForward) * m_78.y)
                                    * 1000.0f * ((float)fTime)));
        vfunc_3(reinterpret_cast<Vector3&>(ptPos));
    }
}
MS2_REPLACE_METHOD(0x1412222c0, CFreeCameraMode, vfunc_8, 2230, 0x3BEA2191);

// @0x141222b80
void CFreeCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    m_78 = g_143b01a60;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x11, true, 0))
        m_78.x = 1.0f;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x1f, true, 0))
        m_78.x = -1.0f;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x1e, true, 0))
        m_78.y = 1.0f;
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d950(0x20, true, 0))
        m_78.y = -1.0f;
    int nX;
    int nY;
    int nWheel;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dbf0(&nX, &nY, &nWheel, false, 0))
    {
        ptMove.y = (float)nX;
        ptMove.z = (float)nY;
    }
    TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x141222b80, CFreeCameraMode, vfunc_9, 395, 0x1B154723);

// @0x141222d20
void CFreeCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    TSingleton<CUIService>::GetInstance()->FUN_141adbca0(0);
}
MS2_REPLACE_METHOD(0x141222d20, CFreeCameraMode, vfunc_6, 47, 0x7D85A084);

// @0x141222d60
void CFreeCameraMode::vfunc_7()
{
    CCameraMode::vfunc_7();
    TSingleton<CUIService>::GetInstance()->FUN_141adbca0(1);
}
MS2_REPLACE_METHOD(0x141222d60, CFreeCameraMode, vfunc_7, 42, 0x92129541);
