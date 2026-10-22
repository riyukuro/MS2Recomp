// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See fpscameramode.h.
// MS2-UNIT: ?\fpscameramode.cpp
// MS2-RANGE: 0x141221290-0x1412221e0 .text$mn
// MS2-PIN: ??_GCFPSCameraMode@@UEAAPEAXI@Z 0x141222180
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fpscameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "fpscameramode.h"

#include <NiAVObject.h>
#include <NiFixedString.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
class Unk_InputState
{
public:
    bool FUN_14116daa0(int nButton, bool b, int n);                 // mouse button held
    bool FUN_14116dbf0(int* pnX, int* pnY, int* pnZ, bool b, int n);    // mouse move delta
};
Unk_InputState* FUN_14025e7c0();

// A field actor (FUN_1409ffd30 casts an object to it).
class Unk_RpgActor : public Unk_CameraTargetEntity
{
public:
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual void vfunc_23(int bVisible);
};
Unk_RpgActor* FUN_1409ffd30(Unk_CameraTargetEntity* p);

// A float table value of the client configuration (FUN_1401d3200).
struct Unk_ConfigFloat
{
    float FUN_1402bac70();
    char m_pad[0x58];
};
struct Unk_ClientConfig
{
    char m_pad_0000[0x1a80];
    Unk_ConfigFloat m_1a80;
    Unk_ConfigFloat m_1ad8;
    Unk_ConfigFloat m_1b30;
};
Unk_ClientConfig* FUN_1401d3200();

// The cursor / window (FUN_140aadf80): its screen rectangle.
class Unk_Cursor
{
public:
    RECT FUN_140ad4c30();
};
Unk_Cursor* FUN_140aadf80();

namespace egf { class Entity; }
egf::Entity* FUN_14123c410(Unk_RpgActor* p);                // m_80 of the game object
NiAVObject* FUN_141b6efc0(egf::Entity* p);
const Vector3* FUN_140947900(NiAVObject* p);        // &world translate

float FUN_140a38cd0(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
int FUN_140ae8540();                                // reloads the camera xml (returns 0 on failure)
int FUN_140ae89e0(CString key);                     // integer value of the camera xml key

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141221290
CFPSCameraMode::CFPSCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CConsoleCameraMode(pOwner, pPrev),
      m_130(NULL),
      m_138(NULL),
      m_140(1),
      m_144(0)
{
}

// @0x141221350
CFPSCameraMode::~CFPSCameraMode()
{
}

// @0x141221380
void CFPSCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    vfunc_31();
    m_50 = 1.0f;
    m_9c = FUN_1401d3200()->m_1a80.FUN_1402bac70();
    m_a0 = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
    m_a4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
    ShowCursor(FALSE);
    Unk_CameraTargetEntity* pTarget = vfunc_25();
    m_130 = FUN_1409ffd30(pTarget);
    vfunc_24(pTarget, 1);
}
MS2_REPLACE_METHOD(0x141221380, CFPSCameraMode, vfunc_6, 249, 0xD19A803D);

// @0x141221480
void CFPSCameraMode::vfunc_7()
{
    ShowCursor(TRUE);
    if (m_130)
        m_130->vfunc_23(false);
}
MS2_REPLACE_METHOD(0x141221480, CFPSCameraMode, vfunc_7, 75, 0xC5DEA605);

// @0x1412214e0
void CFPSCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    unsigned int nButton = FUN_14025e7c0()->FUN_14116daa0(1, true, 0);
    if (m_144 != 0 && nButton == 0)
        return;
    int nX;
    int nY;
    int nZ;
    if (FUN_14025e7c0()->FUN_14116dbf0(&nX, &nY, &nZ, false, 0))
    {
        ptMove.x = (float)nY * 0.05f;
        ptMove.y = (float)nX * 0.05f;
        RECT rc = FUN_140aadf80()->FUN_140ad4c30();
        int nCenterX = ((rc.right - rc.left) >> 1) + rc.left;
        int nCenterY = ((rc.bottom - rc.top) >> 1) + rc.top;
        SetCursorPos(nCenterX, nCenterY);
    }
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x1412214e0, CFPSCameraMode, vfunc_9, 348, 0xC7783C36);

// @0x141221650
void CFPSCameraMode::vfunc_8(double fTime)
{
    if (m_138)
    {
        m_78 = *FUN_140947900(m_138);
        m_78.z += vfunc_27();
    }
    Vector3 ptEye = m_78.FUN_14097fd50(FUN_14183c370());
    m_d8.m_pos = ptEye;
    Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
    if (ptMove.FUN_140552700(g_143b01a60))
    {
        Vector3 ptNew = g_143b01a60;
        Vector3 ptInput = ptMove;
        float fRate = 15.0f;
        float fStep = FUN_140a17940((float)fTime, 0.0f, 1.0f / fRate);
        float fMax = FUN_140a0fda0(FUN_140a38cd0(ptInput.x),
                                   FUN_140a0fda0(FUN_140a38cd0(ptInput.y), FUN_140a38cd0(ptInput.z)));
        float fScale = fStep * fMax;
        float fPitch = ptInput.x * fScale;
        float fYaw = ptInput.y * fScale;
        if (fYaw != 0.0f || fPitch != 0.0f)
        {
            m_68 += fYaw;
            m_6c -= fPitch;
            m_6c = FUN_140a17940(m_6c, 0.0f, 2.0f);
            Vector3 ptBase = m_78;
            ptNew = m_d8.m_pos;
            ptNew.z = ptBase.z;
            ptNew.x = m_50 * FUN_1409f25a0(m_68) + ptBase.x;
            ptNew.y = m_50 * FUN_1409f2310(m_68) + ptBase.y;
            ptNew.z = m_50 * FUN_1409f2310(m_6c) + ptBase.z;
            m_d8.m_pos = ptNew;
            m_d8.m_rot = FUN_1410a0a00(ptNew);
            vfunc_37();
            m_setting.m_c = m_d8.m_pos;
            m_setting.m_18 = m_d8.m_rot;
        }
        Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
    }
    m_setting.m_c = m_d8.m_pos;
    m_setting.m_18 = m_d8.m_rot;
    if (m_c0.m_pos.FUN_140552700(m_d8.m_pos))
    {
        m_c0.m_pos = m_d8.m_pos;
        m_pOwner->FUN_140a38dc0(m_d8.m_pos);
    }
    if (m_c0.m_rot.FUN_140552700(m_d8.m_rot))
    {
        m_c0.m_rot = m_d8.m_rot;
        m_pOwner->FUN_140a38e00(m_d8.m_rot);
    }
}
MS2_REPLACE_METHOD(0x141221650, CFPSCameraMode, vfunc_8, 1467, 0x61078DD5);

// @0x141221c20
void CFPSCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_RpgActor* pActor = FUN_1409ffd30(p);
    if (m_130 && m_130 != pActor)
    {
        if (m_130)
            m_130->vfunc_23(false);
    }
    m_130 = pActor;
    if (m_130)
    {
        NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410(m_130));
        if (pRoot)
        {
            NiFixedString kName("FPS_Dummy");
            m_138 = pRoot->GetObjectByName(kName);
        }
        else
        {
            m_138 = NULL;
        }
        if (!m_138)
            m_138 = pRoot;
        if (m_138)
            m_78 = *FUN_140947900(m_138);
        m_78.z += vfunc_27();
        m_6c = 1.5707964f;
        if (m_140)
            m_130->vfunc_23(true);
    }
    m_68 = m_48;
    m_f0 = 0;
    float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
    float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
    float fZ = m_50 * FUN_1409f2310(m_6c) + m_78.z;
    m_d8.m_pos = Vector3(fX, fY, fZ);
    m_8c = m_d8.m_pos.FUN_140965c40(m_78);
    m_d8.m_rot = FUN_1410a0a00(m_d8.m_pos);
    m_c0 = m_d8;
    vfunc_3(m_d8.m_pos);
    vfunc_4(m_d8.m_rot);
}
MS2_REPLACE_METHOD(0x141221c20, CFPSCameraMode, vfunc_24, 1144, 0xF427A063);

// @0x1412220a0
BOOL CFPSCameraMode::vfunc_31()
{
    if (FUN_140ae8540())
    {
        m_140 = FUN_140ae89e0(CString("FPS_HidePC"));
        m_144 = FUN_140ae89e0(CString("FPS_MouseDownMove"));
        vfunc_24(vfunc_25(), 1);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1412220a0, CFPSCameraMode, vfunc_31, 201, 0x4824DE2E);
