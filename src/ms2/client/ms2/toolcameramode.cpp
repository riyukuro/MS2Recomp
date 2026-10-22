// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See toolcameramode.h.
// MS2-UNIT: ?\toolcameramode.cpp
// MS2-RANGE: 0x141852c30-0x141853bc0 .text$mn
// MS2-PIN: ??_GCToolCameraMode@@UEAAPEAXI@Z 0x141853b60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "toolcameramode.h"

#include <NiAVObject.h>
#include <NiBound.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
class Unk_InputState
{
public:
    bool FUN_14116d950(int nKey, bool b, int n);                    // key held
    bool FUN_14116daa0(int nButton, bool b, int n);                 // mouse button held
    bool FUN_14116dbf0(int* pnX, int* pnY, int* pnZ, bool b, int n);    // mouse move delta
};
Unk_InputState* FUN_14025e7c0();

// The camera option row held by the game context (+0x154 rotation).
struct Unk_CameraOption
{
    char m_pad_000[0x154];
    float m_154;
};

// Smart pointer to it (pointer at +8).
class Unk_CameraOptionPtr
{
public:
    ~Unk_CameraOptionPtr() { FUN_140885ab0(); }     // 0x1408850f0 (another obj)
    Unk_CameraOption* FUN_140885340() const;        // operator->
    void FUN_140885ab0();                           // release

    void* m_pad_00;
    Unk_CameraOption* m_p;
};

class FieldProperty;

// The world service (FUN_1403ed2d0).
class Unk_GameContext
{
public:
    Unk_CameraOptionPtr FUN_141bd30a0();            // copy of +0x298
    FieldProperty* FUN_141bcab60(unsigned int nType);
    bool FUN_141bd3cd0();
    bool FUN_141bd3d10();
    int FUN_141bd36f0(Vector3 pt, Vector3* pOut);   // nonzero if inside
};
Unk_GameContext* FUN_1403ed2d0();

// The game clock (FUN_14086d260).
class Unk_GameClock
{
public:
    double FUN_141473280();
};
Unk_GameClock* FUN_14086d260();

namespace egf { class Entity; }
egf::Entity* FUN_14123c410(Unk_CameraTargetEntity* p);      // m_80 of the game object
NiAVObject* FUN_141b6efc0(egf::Entity* p);
const NiBound& FUN_140994490(NiAVObject* p);                // GetWorldBound
float FUN_1409803f0(const NiBound& kBound);                 // GetRadius
const NiPoint3& FUN_140980350(const NiBound& kBound);       // GetCenter
void FUN_140a01190(const Unk_EfdMatrix3* pMatrix, unsigned int uiCol, Vector3* pOut);  // GetCol
bool FUN_14028d470(float a, float b);                       // nearly equal

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141852c30
CToolCameraMode::CToolCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CCameraMode(pOwner, pPrev),
      m_84(0),
      m_88(0),
      m_90(0)
{
}

// @0x141852cf0
CToolCameraMode::~CToolCameraMode()
{
}

// @0x141852d20
void CToolCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    if (m_84 == 0)
    {
        Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
        if (pTarget)
        {
            m_84 = 1;
            float fRotation = FUN_1403ed2d0()->FUN_141bd30a0().FUN_140885340()->m_154;
            Vector3 ptRot(90.0f, fRotation, -60.0f);
            vfunc_4(ptRot);
            vfunc_24(pTarget, 1);
        }
    }
    m_90 = FUN_1403ed2d0()->FUN_141bcab60(0xb) != 0;
}
MS2_REPLACE_METHOD(0x141852d20, CToolCameraMode, vfunc_6, 370, 0x51A5235E);

// MS2-FUNCTIONAL: the exe binds the up-vector temporary through the ctor's returned this (frame 0x10 smaller)
// @0x141852ea0
void CToolCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    m_8c = n;
    if (!p)
        return;
    m_88 = 1;
    Vector3 ptRot = FUN_140af8260();
    if (FUN_1403ed2d0()->FUN_141bd3cd0() && FUN_1403ed2d0()->FUN_141bd3d10())
        ptRot.z = 0.0f;
    else
        ptRot.z = -45.0f;
    vfunc_4(ptRot);
    ptRot = ptRot.FUN_14097fc90(3.14159274f).FUN_140ae9180(180.0f);
    Vector3 ptPos = p->vfunc_18();
    vfunc_3(ptPos);
    Unk_EfdMatrix3 kRot;
    kRot.FUN_142083d40(ptRot.x, ptRot.y, ptRot.z);
    Vector3 ptAxis;
    FUN_140a01190(&kRot, 0, &ptAxis);
    ptAxis.FUN_140968990();
    float fDist = 200.0f;
    float fHeight = 0.0f;
    if (n == 0)
        fDist = 600.0f;
    ptPos = ptPos.FUN_14097fd50(ptAxis.FUN_14097fc90(-fDist));
    vfunc_3(ptPos);
    NiAVObject* pNode = FUN_141b6efc0(FUN_14123c410(p));
    if (!pNode)
        return;
    pNode->Update((float)FUN_14086d260()->FUN_141473280(), true);
    pNode->UpdateWorldBound();
    const NiBound& kBound = FUN_140994490(pNode);
    fDist = FUN_1409803f0(kBound);
    fHeight = (FUN_140980350(kBound).z - ptPos.z < 0.0f) ? 0.0f : FUN_140980350(kBound).z - ptPos.z;
    if (n != 0)
    {
        const Vector3& ptUp = Vector3(0.0f, 0.0f, fHeight);
        ptPos = ptPos.FUN_14097fd50(ptAxis.FUN_14097fc90(-fDist)).FUN_14097fd50(ptUp);
        vfunc_3(ptPos);
    }
    m_88 = 0;
}
MS2_REPLACE_METHOD(0x141852ea0, CToolCameraMode, vfunc_24, 1078, 0xF25AE606);

// MS2-FUNCTIONAL: the exe binds the right-hand operand temporary through the ctor/operator return value (frame 0x10 smaller)
// @0x1418532e0
void CToolCameraMode::vfunc_8(double fTime)
{
    if (m_88)
    {
        vfunc_24(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60(), m_8c);
    }
    Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
    unsigned int bShift = FUN_14025e7c0()->FUN_14116d950(0x2a, false, 0);
    unsigned int bLeft = FUN_14025e7c0()->FUN_14116daa0(0, false, 0);
    unsigned int bRight = FUN_14025e7c0()->FUN_14116daa0(1, false, 0);
    if (bLeft != 0 && bRight != 0)
    {
        Vector3 ptPos = FUN_1409f2540();
        ptPos.z = ptPos.z - ptMove.z * 2.0f;
        vfunc_3(ptPos);
    }
    else if (bShift == 0 && bRight != 0)
    {
        if (!FUN_1403ed2d0()->FUN_141bd3cd0() || FUN_1403ed2d0()->FUN_141bd3d10() == 1)
        {
            if (ptMove.FUN_140552700(g_143b01a60))
            {
                Vector3 ptRot = FUN_140af8260();
                ptRot.y = ptRot.y - ptMove.y / 512.0f * 90.0f;
                ptRot.z = ptRot.z - ptMove.z / 512.0f * 90.0f;
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
        Vector3 ptForward;
        FUN_140a01190(&kRot, 2, &ptForward);
        ptForward.FUN_140968990();
        Vector3 ptPos = FUN_1409f2540();
        float fDelta = (float)fTime;
        const Vector3& ptSide = ptForward.FUN_14097fc90(m_78.y);
        ptPos = ptPos.FUN_14097fd50(ptRight.FUN_14097fc90(m_78.x).FUN_14097fd50(ptSide).FUN_14097fc90(1000.0f).FUN_14097fc90(fDelta));
        vfunc_3(ptPos);
    }
}
MS2_REPLACE_METHOD(0x1418532e0, CToolCameraMode, vfunc_8, 1177, 0xB27624DC);

// @0x141853780
void CToolCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    m_78 = g_143b01a60;
    if (FUN_14025e7c0()->FUN_14116d950(0x11, false, 0))
    {
        if (FUN_140af8140())
        {
            if (0.01f < m_70)
                m_70 = m_70 - 0.01f;
            else
                m_70 = 0.01f;
        }
        else
        {
            m_78.x = 1.0f;
        }
    }
    else if (FUN_14025e7c0()->FUN_14116d950(0x1f, false, 0))
    {
        if (FUN_140af8140())
            m_70 = m_70 + 0.01f;
        else
            m_78.x = -1.0f;
    }
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
    if (FUN_140af8140())
        Unk_CameraManager::FUN_1409478c0()->FUN_140af0170(m_70, true);
}
MS2_REPLACE_METHOD(0x141853780, CToolCameraMode, vfunc_9, 687, 0x270105CE);

// @0x141853a40
void CToolCameraMode::vfunc_3(Vector3 pt)
{
    if (m_90)
    {
        Vector3 ptCur = FUN_1409f2540();
        Vector3 ptOut;
        if (!FUN_1403ed2d0()->FUN_141bd36f0(pt, &ptOut))
        {
            if (!FUN_14028d470(ptOut.x, 0.0f))
                pt.x = ptCur.x;
            if (!FUN_14028d470(ptOut.y, 0.0f))
                pt.y = ptCur.y;
            if (!FUN_14028d470(ptOut.z, 0.0f))
                pt.z = ptCur.z;
        }
    }
    CCameraMode::vfunc_3(pt);
}
MS2_REPLACE_METHOD(0x141853a40, CToolCameraMode, vfunc_3, 282, 0xDAD5715B);
