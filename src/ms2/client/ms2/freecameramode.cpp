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

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The camera option row held by the game context (+0x1f4 fov).
struct Unk_FreeCamOption
{
    char m_pad_000[0x1f4];
    float m_1f4;
};

// Smart pointer to it (pointer at +8).
class Unk_FreeCamOptionPtr
{
public:
    ~Unk_FreeCamOptionPtr() { FUN_140885ab0(); }    // 0x1408850f0 (another obj)
    Unk_FreeCamOption* FUN_140885340() const;       // operator->
    void FUN_140885ab0();                           // release
    Unk_FreeCamOption* FUN_1409657a0() const;       // get

    void* m_pad_00;
    Unk_FreeCamOption* m_p;
};

// The world service (FUN_1403ed2d0).
class Unk_FreeCamContext
{
public:
    Unk_FreeCamOptionPtr FUN_141bd30a0();           // copy of +0x298
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};

// The UI service (TSingleton<CUIService>::GetInstance).

// The game's TinyXML element (0x90 bytes).
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszValue);                         // 0x14086f2f0
private:
    char m_pad_00[0x90];
};
void* FUN_14086e090(void* pParent, Unk_TiXmlElement* pChild);       // LinkEndChild
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};
void FUN_140873e30(Unk_TiXmlElement* pElem, const char* pszName, float fValue);   // SetFloatAttribute
void FUN_140873ca0(Unk_TiXmlElement* pElem, const char* pszName, int nValue);     // SetAttribute
// The exe writes NiPoint3 attributes: each efd::Point3 converts through the out-of-line NiPoint3(const efd::Point3&).
struct Unk_FcNiPoint3 : public Vector3
{
    Unk_FcNiPoint3(const Vector3& pt);                      // 0x14027dcf0
};
void FUN_140874ad0(Unk_TiXmlElement* pElem, const char* pszName, const Unk_FcNiPoint3& pt);   // SetPointAttribute
void FUN_140870f90(TiXmlDocument* pDoc);                            // SaveFile

void FUN_140a01190(const Unk_EfdMatrix3* pMatrix, unsigned int uiCol, Vector3* pOut);  // GetCol
float FUN_140a38cd0(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max

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
    Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(0, true, 0) && ((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(1, true, 0))
    {
        Vector3 ptPos = FUN_1409f2540();
        ptPos.z = ptPos.z - ptMove.z * 2.0f;
        vfunc_3(ptPos);
    }
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116daa0(1, true, 0))
    {
        if (ptMove.FUN_140552700(g_143b01a60))
        {
            Vector3 ptInput = ptMove;
            float fRate = 15.0f;
            float fStep = FUN_140a17940((float)fTime, 0.0f, 1.0f / fRate);
            float fAbsZ = FUN_140a38cd0(ptInput.z);
            float fMaxYZ = FUN_140a0fda0(FUN_140a38cd0(ptInput.y), fAbsZ);
            float fMax = FUN_140a0fda0(FUN_140a38cd0(ptInput.x), fMaxYZ);
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
            Unk_CameraTargetEntity* pActor = ((class Unk_CameraTargetEntity*)((class WorldService*)(class Unk_FreeCamContext*)(((class Unk_FreeCamContext*)WorldService::GetInstance())))->FUN_141bd0cc0());
            if (pActor != 0)
            {
                Unk_FreeCamOptionPtr spOption = ((class Unk_FreeCamContext*)WorldService::GetInstance())->FUN_141bd30a0();
                if (spOption.FUN_1409657a0() != 0)
                {
                    TiXmlDocument doc;
                    if (!doc.FUN_140870fc0("./data/xml/camera/customize.xml", 0))
                    {
                        FUN_14086e090(&doc, new Unk_TiXmlElement("ms2"));
                    }
                    Unk_TiXmlElement* pMs2 = ((class Unk_TiXmlElement*)((class Unk_XmlNode*)(class TiXmlDocument*)(&doc))->FirstChild("ms2"));
                    if (pMs2 != 0)
                    {
                        Vector3 ptDir = FUN_1409f2540().FUN_140965c40(pActor->vfunc_18());
                        float fDist = ptDir.FUN_140968990();
                        Unk_TiXmlElement* pCamera = new Unk_TiXmlElement("camera");
                        FUN_14086e090(pMs2, pCamera);
                        FUN_140873e30(pCamera, "fov", spOption.FUN_140885340()->m_1f4);
                        FUN_140873e30(pCamera, "distance", fDist);
                        FUN_140873ca0(pCamera, "zoomIn", 50);
                        FUN_140873ca0(pCamera, "zoomOut", 150);
                        FUN_140874ad0(pCamera, "direction", ptDir);
                        FUN_140874ad0(pCamera, "rotation", FUN_140af8260());
                        FUN_140870f90(&doc);
                    }
                }
            }
        }
    }
    if (m_78.FUN_140552700(g_143b01a60))
    {
        Vector3 ptRot = FUN_140af8260();
        ptRot = ptRot.FUN_14097fc90(3.14159274f).FUN_140ae9180(180.0f);
        Unk_EfdMatrix3 kRot;
        kRot.FUN_142083d40(ptRot.x, ptRot.y, ptRot.z);
        Vector3 ptRight;
        FUN_140a01190(&kRot, 0, &ptRight);
        ptRight.FUN_140968990();
        Vector3 ptForward;
        FUN_140a01190(&kRot, 2, &ptForward);
        ptForward.FUN_140968990();
        Vector3 ptPos = FUN_1409f2540();
        ptPos = ptPos.FUN_14097fd50(ptRight.FUN_14097fc90(m_78.x).FUN_14097fd50(ptForward.FUN_14097fc90(m_78.y))
                                    .FUN_14097fc90(1000.0f).FUN_14097fc90((float)fTime));
        vfunc_3(ptPos);
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
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(ptMove);
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
