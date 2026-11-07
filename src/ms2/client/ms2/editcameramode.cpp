// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ms2/placeholder/freecameramode.h.
// MS2-UNIT: ?\editcameramode.cpp
// MS2-RANGE: 0x141198830-0x141199270 .text$mn
// MS2-PIN: ??_GCEditCameraMode@@UEAAPEAXI@Z 0x1411990f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\editcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Matrix3.h>   // C3: efd::Matrix3::FromEulerAnglesXYZ

#include "ms2/placeholder/freecameramode.h"
#include "ms2/placeholder/tixmldocument.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/os.h"   // C3: TSingleton<CameraMgr>
class CameraMgr { public: Vector3 FUN_140a38d00(); void FUN_140a38d90(Vector3 pt); };   // C3: member view (was Unk_CameraManager)
template<> CameraMgr* TSingleton<CameraMgr>::GetInstance();   // C3: the real accessor (0x1409478c0; actioncameramode.cpp defines it)
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
class Unk_FreeCamInput : public CInputKeyHandler
{
public:
    bool FUN_14116da30(int nKey, bool b, int n);                    // key pressed
};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// C3: the Unk_FreeCamOption / Unk_FreeCamOptionPtr / Unk_FreeCamContext views are gone (no caller since db8eef594):
// the field data is WorldService::FUN_141bd30a0() -> MS2Ptr<CFieldDataCli> (fielddatacli.h).


























// The game's TinyXML element (0x90 bytes).
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszValue);                         // 0x14086f2f0
private:
    char m_pad_00[0x90];
};
void* FUN_14086e090(void* pParent, Unk_TiXmlElement* pChild);       // LinkEndChild
// C3 #8: dead FUN_140165cf0 / FUN_140168650 view removed (callers use Unk_XmlNode::FirstChild / NextSibling)
void FUN_140873e30(Unk_TiXmlElement* pElem, const char* pszName, float fValue);   // SetFloatAttribute
void FUN_140873ca0(Unk_TiXmlElement* pElem, const char* pszName, int nValue);     // SetAttribute
void FUN_140874ad0(Unk_TiXmlElement* pElem, const char* pszName, Vector3 pt);   // SetPointAttribute
void FUN_140870f90(TiXmlDocument* pDoc);                            // SaveFile

bool FUN_14028d470(float a, float b);                       // nearly equal
float FUN_140a38cd0(float f);                       // fabs

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MS2_EMIT_CRT_MEMMOVE_S();

// @0x141198830
CEditCameraMode::CEditCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CFreeCameraMode(pOwner, pPrev)
{
}

// @0x1411988b0
CEditCameraMode::~CEditCameraMode()
{
}

// @0x1411988e0
void CEditCameraMode::vfunc_8(double fTime)
{
    vfunc_9();
    Vector3 ptMove = TSingleton<CameraMgr>::GetInstance()->FUN_140a38d00();
    if (((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116daa0(0, false, 0) && ((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116daa0(1, false, 0))
    {
        efd::Point3 ptPos = FUN_1409f2540();
        ptPos.z = ptPos.z - ptMove.z * 2.0f;
        vfunc_3(reinterpret_cast<Vector3&>(ptPos));
    }
    else if (((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116daa0(1, false, 0))
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
    if (reinterpret_cast<const efd::Point3&>(m_78) != reinterpret_cast<const efd::Point3&>(g_143b01a60))
    {
        Vector3 ptRot = FUN_140af8260();
        ptRot = (reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(ptRot) * 3.14159274f)) / 180.0f);
        Unk_EfdMatrix3 kRot;
        reinterpret_cast<efd::Matrix3*>(&kRot)->FromEulerAnglesXYZ(ptRot.x, ptRot.y, ptRot.z);
        Vector3 ptRight;
        reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(0, reinterpret_cast<efd::Point3&>(ptRight));
        ptRight.Unitize();
        Vector3 ptUp;
        reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(1, reinterpret_cast<efd::Point3&>(ptUp));
        ptUp.Unitize();
        Vector3 ptForward;
        reinterpret_cast<const efd::Matrix3&>(kRot).GetCol(2, reinterpret_cast<efd::Point3&>(ptForward));
        ptForward.Unitize();
        efd::Point3 ptPos = FUN_1409f2540();
        reinterpret_cast<Vector3&>(ptPos) = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(reinterpret_cast<Vector3&>(ptPos)) + ((reinterpret_cast<const efd::Point3&>(ptRight) * m_78.x + reinterpret_cast<const efd::Point3&>(ptUp) * m_78.z) + reinterpret_cast<const efd::Point3&>(ptForward) * m_78.y) * 1000.0f * ((float)fTime)));
        vfunc_3(reinterpret_cast<Vector3&>(ptPos));
    }
}
MS2_REPLACE_METHOD(0x1411988e0, CEditCameraMode, vfunc_8, 1555, 0x18A044F7);

// @0x141198f00
void CEditCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    m_78 = g_143b01a60;
    if (((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116d950(0x11, false, 0))
        m_78.z = -1.0f;
    else if (((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116d950(0x1f, false, 0))
        m_78.z = 1.0f;
    if (((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116d950(0x1e, false, 0))
        m_78.y = 1.0f;
    else if (((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116d950(0x20, false, 0))
        m_78.y = -1.0f;
    int nX;
    int nY;
    int nWheel;
    if (((class Unk_FreeCamInput*)FUN_14025e7c0())->FUN_14116dbf0(&nX, &nY, &nWheel, false, 0))
    {
        ptMove.y = (float)nX;
        ptMove.z = (float)nY;
        if (FUN_14028d470(m_78.x, 0.0f))
        {
            if (nWheel > 0)
                m_78.x = 15.0f;
            else if (nWheel < 0)
                m_78.x = -15.0f;
        }
    }
    TSingleton<CameraMgr>::GetInstance()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x141198f00, CEditCameraMode, vfunc_9, 487, 0x048DBDFC);
