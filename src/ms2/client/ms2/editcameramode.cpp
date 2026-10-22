// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ms2/placeholder/freecameramode.h.
// MS2-UNIT: ?\editcameramode.cpp
// MS2-RANGE: 0x141198830-0x141199270 .text$mn
// MS2-PIN: ??_GCEditCameraMode@@UEAAPEAXI@Z 0x1411990f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\editcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/freecameramode.h"
#include "ms2/placeholder/tixmldocument.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
class Unk_FreeCamInput
{
public:
    bool FUN_14116d950(int nKey, bool b, int n);                    // key held
    bool FUN_14116da30(int nKey, bool b, int n);                    // key pressed
    bool FUN_14116daa0(int nButton, bool b, int n);                 // mouse button held
    bool FUN_14116dbf0(int* pnX, int* pnY, int* pnZ, bool b, int n);    // mouse move delta
};
Unk_FreeCamInput* FUN_14025e7c0();

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
Unk_FreeCamContext* FUN_1403ed2d0();
Unk_CameraTargetEntity* FUN_141bd0cc0(Unk_FreeCamContext* p);   // the local player

// The game's TinyXML element (0x90 bytes).
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszValue);                         // 0x14086f2f0
private:
    char m_pad_00[0x90];
};
void* FUN_14086e090(void* pParent, Unk_TiXmlElement* pChild);       // LinkEndChild
Unk_TiXmlElement* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);  // FirstChildElement
void FUN_140873e30(Unk_TiXmlElement* pElem, const char* pszName, float fValue);   // SetFloatAttribute
void FUN_140873ca0(Unk_TiXmlElement* pElem, const char* pszName, int nValue);     // SetAttribute
void FUN_140874ad0(Unk_TiXmlElement* pElem, const char* pszName, Vector3 pt);   // SetPointAttribute
void FUN_140870f90(TiXmlDocument* pDoc);                            // SaveFile

void FUN_140a01190(const Unk_EfdMatrix3* pMatrix, unsigned int uiCol, Vector3* pOut);  // GetCol
bool FUN_14028d470(float a, float b);                       // nearly equal
float FUN_140a38cd0(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max

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

// MS2-FUNCTIONAL: exe frame is 0x10 smaller (temp slot sharing of the point temporaries not reproduced)
// @0x1411988e0
void CEditCameraMode::vfunc_8(double fTime)
{
    vfunc_9();
    Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
    if (FUN_14025e7c0()->FUN_14116daa0(0, false, 0) && FUN_14025e7c0()->FUN_14116daa0(1, false, 0))
    {
        Vector3 ptPos = FUN_1409f2540();
        ptPos.z = ptPos.z - ptMove.z * 2.0f;
        vfunc_3(ptPos);
    }
    else if (FUN_14025e7c0()->FUN_14116daa0(1, false, 0))
    {
        if (ptMove.FUN_140552700(g_143b01a60))
        {
            Vector3 ptInput = ptMove;
            float fRate = 15.0f;
            float fDelta = (float)fTime;
            float fStep = FUN_140a17940(fDelta, 0.0f, 1.0f / 15.0f);
            float fAbsZ = FUN_140a38cd0(ptInput.z);
            float fMaxYZ = FUN_140a0fda0(FUN_140a38cd0(ptInput.y), fAbsZ);
            float fMax = FUN_140a0fda0(FUN_140a38cd0(ptInput.x), fMaxYZ);
            float fScale = fStep * fMax;
            float fRotX = ptInput.y * fScale;
            float fRotY = ptInput.z * fScale;
            if (fRotX != 0.0f || fRotY != 0.0f)
            {
                if (1.0f < FUN_140a38cd0(fRotX))
                    fRotX = (0.0f <= fRotX) ? 1.0f : -1.0f;
                if (1.0f < FUN_140a38cd0(fRotY))
                    fRotY = (0.0f <= fRotY) ? 1.0f : -1.0f;
                Vector3 ptRot = FUN_140af8260();
                ptRot.y = ptRot.y - fRotX;
                ptRot.z = ptRot.z - fRotY;
                vfunc_4(ptRot);
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
        Vector3 ptUp;
        FUN_140a01190(&kRot, 1, &ptUp);
        ptUp.FUN_140968990();
        Vector3 ptForward;
        FUN_140a01190(&kRot, 2, &ptForward);
        ptForward.FUN_140968990();
        Vector3 ptPos = FUN_1409f2540();
        float fDelta = (float)fTime;
        const Vector3& ptSideF = ptForward.FUN_14097fc90(m_78.y);
        const Vector3& ptSideU = ptUp.FUN_14097fc90(m_78.z);
        ptPos = ptPos.FUN_14097fd50(ptRight.FUN_14097fc90(m_78.x).FUN_14097fd50(ptSideU).FUN_14097fd50(ptSideF).FUN_14097fc90(1000.0f).FUN_14097fc90(fDelta));
        vfunc_3(ptPos);
    }
}
MS2_REPLACE_METHOD(0x1411988e0, CEditCameraMode, vfunc_8, 1555, 0x18A044F7);

// @0x141198f00
void CEditCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    m_78 = g_143b01a60;
    if (FUN_14025e7c0()->FUN_14116d950(0x11, false, 0))
        m_78.z = -1.0f;
    else if (FUN_14025e7c0()->FUN_14116d950(0x1f, false, 0))
        m_78.z = 1.0f;
    if (FUN_14025e7c0()->FUN_14116d950(0x1e, false, 0))
        m_78.y = 1.0f;
    else if (FUN_14025e7c0()->FUN_14116d950(0x20, false, 0))
        m_78.y = -1.0f;
    int nX;
    int nY;
    int nWheel;
    if (FUN_14025e7c0()->FUN_14116dbf0(&nX, &nY, &nWheel, false, 0))
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
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x141198f00, CEditCameraMode, vfunc_9, 487, 0x048DBDFC);
