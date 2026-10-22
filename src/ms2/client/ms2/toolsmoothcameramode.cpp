// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See toolsmoothcameramode.h.
// MS2-UNIT: ?\toolsmoothcameramode.cpp
// MS2-RANGE: 0x14010e180-0x14010e4a0 .text$di
// MS2-RANGE: 0x141856e00-0x1418589b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolsmoothcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "toolsmoothcameramode.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/placeholder/unk_1402a9d70.h"

// The shared eight-byte null-handle wrapper; constructor forwards to its pointer setter.
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
MS2_CHECK_SIZE(Unk_1401cd100, 8);
static CString s_skill1("skill");
static CString s_stun1("stun");
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortNames1[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_skill2("skill");
static CString s_stun2("stun");
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_sortNames2[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// ---- unit-local placeholders ----

// The input state (FUN_14025e7c0).
class Unk_InputState
{
public:
    bool FUN_14116d950(int nKey, bool b, int n);                    // key held
    bool FUN_14116d9c0(int nKey, bool b, int n);                    // key pressed
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

// A field actor (FUN_1409ffd30 casts an object to it).
class Unk_RpgActor : public Unk_CameraTargetEntity
{
};
Unk_RpgActor* FUN_1409ffd30(Unk_CameraTargetEntity* p);

// The game context (FUN_1403ed2d0).
class Unk_GameContext
{
public:
    Unk_CameraOptionPtr FUN_141bd30a0();            // copy of +0x298
    Unk_CameraTargetEntity* FUN_141bd1050(__int64 nObjectId);
};
Unk_GameContext* FUN_1403ed2d0();

// The picked-object list returned by the camera manager's pick (FUN_140af0850).
class Unk_PickEntry
{
public:
    __int64 FUN_140a17cb0();                        // object id
};
class Unk_PickArray
{
public:
    Unk_PickEntry* FUN_140a17d70(unsigned int i);
    unsigned int FUN_140a17ea0();                   // count
};
class Unk_PickList
{
public:
    Unk_PickArray* FUN_140a17e00();
};
class Unk_PickListPtr
{
public:
    ~Unk_PickListPtr() { FUN_140a16120(); }        // 0x140a16120
    void FUN_140a16120();
    Unk_PickList* FUN_140a16c00() const;            // get
    Unk_PickList* FUN_140a16c30() const;            // operator->

    void* m_p;
};
// The cursor (FUN_140aadf80).
class Unk_Cursor
{
public:
    void FUN_141b90e30(float* pfX, float* pfY);
};
Unk_Cursor* FUN_140aadf80();

// Camera tuning values of the camera xml (FUN_140ae8910 consumes its by-value CString key).
float FUN_140ae8910(CString key);
int FUN_140ae8540();                                // reloads the camera xml (returns 0 on failure)

float FUN_14059d930(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
bool FUN_14028d470(float a, float b);               // nearly equal
const float& FUN_1409ffe80(const float& a, const float& b);   // std::min
const float& FUN_140805fc0(const float& a, const float& b);   // std::max
void FUN_1412751f0(const CStringW& str, int a, int b);     // chat/debug log line
CStringW FUN_1406329c0(const wchar_t* pszFormat, float* pfArg);   // "{0}" substitution (another obj)

// efd::Point3 with the default constructor 0x1405522f0 (another obj).
struct Unk_EfdPoint3
{
    Unk_EfdPoint3();
    float FUN_140968990();                          // Unitize
    float x, y, z;
};
float FUN_140a00f20(const Unk_EfdPoint3& a, const Unk_EfdPoint3& b);   // Dot
void FUN_140a01190(const Unk_EfdMatrix3* pMatrix, unsigned int uiCol, Vector3* pOut);   // GetCol
extern int DAT_143ab0248;
extern int DAT_143ab2914;

// efd::Matrix3::GetCol (0x1418588c0, this obj's COMDAT)
// @0x1418588c0
void FUN_1418588c0(const Unk_EfdMatrix3* pMatrix, unsigned int uiCol, float* pOut)
{
    pOut[0] = pMatrix->m_afEntry[0][uiCol];
    pOut[1] = pMatrix->m_afEntry[1][uiCol];
    pOut[2] = pMatrix->m_afEntry[2][uiCol];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141856e00
CToolSmoothCameraMode::CToolSmoothCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CConsoleCameraMode(pOwner, pPrev),
      m_130(),
      m_13c(g_143b01a60),
      m_148(g_143b01a60),
      m_154(50.0f),
      m_158(360.0f),
      m_15c(5.0f),
      m_160(1.0f)
{
}

// @0x141856f30
CToolSmoothCameraMode::~CToolSmoothCameraMode()
{
}

// @0x141856f60
void CToolSmoothCameraMode::vfunc_9()
{
    Vector3 ptMove = g_143b01a60;
    m_148 = m_13c = m_130 = g_143b01a60;
    if (FUN_14025e7c0()->FUN_14116d950(0x11, false, 0))
        m_130.x = m_154 * m_160;
    else if (FUN_14025e7c0()->FUN_14116d950(0x1f, false, 0))
        m_130.x = -m_154 * m_160;
    if (FUN_14025e7c0()->FUN_14116d950(0x1e, false, 0))
        m_130.y = m_154 * m_160;
    else if (FUN_14025e7c0()->FUN_14116d950(0x20, false, 0))
        m_130.y = -m_154 * m_160;
    if (FUN_14025e7c0()->FUN_14116d950(0x10, false, 0))
        ptMove.y = m_158 * m_160;
    else if (FUN_14025e7c0()->FUN_14116d950(0x12, false, 0))
        ptMove.y = -m_158 * m_160;
    if (FUN_14025e7c0()->FUN_14116d950(0x39, false, 0))
        m_148.z = m_154 * m_160 * 10.0f;
    else if (FUN_14025e7c0()->FUN_14116d950(0x2e, false, 0))
        m_148.z = -m_154 * m_160 * 10.0f;
    unsigned int bLeft = FUN_14025e7c0()->FUN_14116daa0(0, false, 0);
    unsigned int bRight = FUN_14025e7c0()->FUN_14116daa0(1, false, 0);
    int nX;
    int nY;
    int nWheel;
    unsigned int bMoved = FUN_14025e7c0()->FUN_14116dbf0(&nX, &nY, &nWheel, false, 0);
    if (bMoved != 0)
    {
        if (bRight != 0)
        {
            if (bLeft != 0)
            {
                m_148.z = m_148.z - (float)nY * 100.0f;
            }
            else
            {
                m_13c.x = (float)nX * m_15c * m_160;
                m_13c.y = (float)nY * m_15c * m_160;
                m_50 = FUN_140a17940(m_50 + (float)nWheel, m_58, m_54);
            }
        }
        else if (FUN_14028d470(m_130.x, 0.0f))
        {
            if (nWheel > 0)
                m_130.x = 300.0f;
            else if (nWheel < 0)
                m_130.x = -300.0f;
        }
    }
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(ptMove);
}
MS2_REPLACE_METHOD(0x141856F60, CToolSmoothCameraMode, vfunc_9, 1292, 0xF2E237FE);

// MS2-FUNCTIONAL: the exe passes the format result to FUN_1412751f0 through the pointer the callee returns in rax (frame 0x10 larger)
// @0x141857480
void CToolSmoothCameraMode::vfunc_8(double fTime)
{
    bool bEnabled = true;
    if (DAT_143ab0248 == 2)
        bEnabled = DAT_143ab2914 >= 0x34;
    if (bEnabled)
    {
        if (FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0) || FUN_14025e7c0()->FUN_14116d950(0x6b, true, 0))
        {
            float fOld = m_160;
            if (FUN_14025e7c0()->FUN_14116d9c0(0x52, true, 0) || FUN_14025e7c0()->FUN_14116d9c0(0xb, true, 0))
                m_160 = 1.0f;
            else if (FUN_14025e7c0()->FUN_14116d9c0(0x4e, true, 0) || FUN_14025e7c0()->FUN_14116d9c0(0xd, true, 0))
                m_160 = m_160 + 0.05f;
            else if (FUN_14025e7c0()->FUN_14116d9c0(0x4a, true, 0) || FUN_14025e7c0()->FUN_14116d9c0(0xc, true, 0))
                m_160 = m_160 - 0.05f;
            float fMax = 3.0f;
            m_160 = FUN_1409ffe80(m_160, fMax);
            float fMin = 0.05f;
            m_160 = FUN_140805fc0(m_160, fMin);
            if (fOld != m_160)
            {
                CStringW strMsg = FUN_1406329c0(L"move accelerate rate:{0}", &m_160);
                FUN_1412751f0(strMsg, 1, 1);
            }
        }
    }
    Vector3 ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
    float fRate = 15.0f;
    float fStep = FUN_140a17940((float)fTime, 0.0f, 1.0f / fRate);
    float fScale = fStep;
    if (m_148.FUN_140552700(g_143b01a60))
    {
        m_148 = m_148.FUN_14097fc90(fScale);
        m_c0.m_pos = m_d8.m_pos = m_d8.m_pos.FUN_14097fd50(m_148);
    }
    if (m_13c.FUN_140552700(g_143b01a60))
    {
        m_13c = m_13c.FUN_14097fc90(fScale);
        Vector3 ptRot = FUN_140af8260();
        ptRot.y = ptRot.y - m_13c.x;
        ptRot.z = ptRot.z - m_13c.y;
        m_d8.m_rot = ptRot;
    }
    if (ptMove.FUN_140552700(g_143b01a60))
    {
        ptMove = ptMove.FUN_14097fc90(fScale);
        Vector3 ptRot = m_c0.m_rot;
        ptRot.y = ptRot.y - ptMove.y;
        ptRot.z = ptRot.z - ptMove.z;
        m_d8.m_rot = ptRot;
    }
    if (m_130.FUN_140552700(g_143b01a60))
    {
        m_130 = m_130.FUN_14097fc90(fScale);
        Vector3 ptAngle = m_c0.m_rot;
        ptAngle = ptAngle.FUN_14097fc90(3.14159274f).FUN_140ae9180(180.0f);
        Unk_EfdMatrix3 kRot;
        kRot.FUN_142083d40(ptAngle.x, ptAngle.y, ptAngle.z);
        Vector3 ptRight;
        FUN_140a01190(&kRot, 0, &ptRight);
        ptRight.FUN_140968990();
        Vector3 ptForward;
        FUN_140a01190(&kRot, 2, &ptForward);
        ptForward.FUN_140968990();
        Vector3 ptPos = m_d8.m_pos;
        float fDelta = (float)fTime;
        const Vector3& ptSide = ptForward.FUN_14097fc90(m_130.y);
        ptPos = ptPos.FUN_14097fd50(ptRight.FUN_14097fc90(m_130.x).FUN_14097fd50(ptSide).FUN_14097fc90(1000.0f).FUN_14097fc90(fDelta));
        m_d8.m_pos = ptPos;
    }
    vfunc_39(fTime);
    m_setting.m_c = m_d8.m_pos;
    m_setting.m_18 = m_d8.m_rot;
}

// @0x141857ce0
void CToolSmoothCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    vfunc_31();
    m_68 = m_48;
    m_6c = m_4c;
    CConsoleCameraMode::vfunc_6(n);
    Unk_CameraTargetEntity* pTarget = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pTarget)
    {
        float fRotation = FUN_1403ed2d0()->FUN_141bd30a0().FUN_140885340()->m_154;
        Vector3 ptRot(90.0f, fRotation, -60.0f);
        vfunc_4(ptRot);
        vfunc_24(pTarget, 1);
    }
    m_130 = g_143b01a60;
}
MS2_REPLACE_METHOD(0x141857CE0, CToolSmoothCameraMode, vfunc_6, 398, 0x0E152FB4);

// @0x141857e80
void CToolSmoothCameraMode::vfunc_39(double fTime)
{
    if (m_f0 != 0)
    {
        Unk_NiPoint3 ptDelta(m_d8.m_pos.FUN_140965c40(m_c0.m_pos));
        float fDist = ptDelta.FUN_140967ac0();
        if (fDist <= 1.0f)
        {
            m_c0.m_pos = m_d8.m_pos;
        }
        else
        {
            float fSpeed = FUN_14059d930(m_a4) * (float)fTime;
            if (m_a0 != m_9c)
            {
                if (FUN_14059d930(m_a0 - m_9c) < fSpeed)
                    m_a0 = m_9c;
                else if (m_a0 > m_9c)
                    m_a0 = m_a0 - fSpeed;
                else
                    m_a0 = m_a0 + fSpeed;
            }
            float t = (float)fTime * fDist * m_a0;
            if (t > 1.0f)
                m_c0.m_pos = m_d8.m_pos;
            else
                m_c0.m_pos = m_c0.m_pos.FUN_14097fd50(FUN_1409ab5c0(t, m_d8.m_pos.FUN_140965c40(m_c0.m_pos)));
        }
        Unk_NiMatrix3 kCur;
        Unk_NiPoint3 ptCur(m_c0.m_rot.FUN_14097fc90(3.14159274f).FUN_140ae9180(180.0f));
        Unk_NiPoint3 ptWant(m_d8.m_rot.FUN_14097fc90(3.14159274f).FUN_140ae9180(180.0f));
        kCur.FUN_142083d40(ptCur.x, ptCur.y, ptCur.z);
        Unk_NiMatrix3 kWant;
        kWant.FUN_142083d40(ptWant.x, ptWant.y, ptWant.z);
        Unk_EfdPoint3 ptColCur;
        Unk_EfdPoint3 ptColWant;
        FUN_1418588c0(&kCur, 0, &ptColCur.x);
        FUN_1418588c0(&kWant, 0, &ptColWant.x);
        ptColCur.FUN_140968990();
        ptColWant.FUN_140968990();
        float fDot = FUN_140a00f20(ptColCur, ptColWant);
        float fBlend = FUN_14059d930(fDot) * (float)fTime * 8.0f;
        if (fBlend >= 1.0f)
            m_c0.m_rot = m_d8.m_rot;
        else
            m_c0.m_rot = m_c0.m_rot.FUN_14097fd50(FUN_1409ab5c0(fBlend, m_d8.m_rot.FUN_140965c40(m_c0.m_rot)));
    }
    else
    {
        m_c0.m_pos = m_d8.m_pos;
        m_c0.m_rot = m_c0.m_rot;
        m_f0 = 1;
    }
    m_setting.m_c = m_c0.m_pos;
    m_setting.m_18 = m_c0.m_rot;
    m_pOwner->FUN_140a38dc0(m_c0.m_pos);
    m_pOwner->FUN_140a38e00(m_c0.m_rot);
}
MS2_REPLACE_METHOD(0x141857E80, CToolSmoothCameraMode, vfunc_39, 1524, 0x2FD06C6A);

// @0x141858480
void CToolSmoothCameraMode::vfunc_30()
{
    float fX;
    float fY;
    FUN_140aadf80()->FUN_141b90e30(&fX, &fY);
    Unk_PickListPtr pList = Unk_CameraManager::FUN_1409478c0()->FUN_140af0850(fX, fY, true, true, false, NULL);
    if (!pList.FUN_140a16c00())
        return;
    Unk_GameContext* pContext = FUN_1403ed2d0();
    for (unsigned int i = 0; i < pList.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17ea0(); ++i)
    {
        Unk_PickEntry* pEntry = pList.FUN_140a16c30()->FUN_140a17e00()->FUN_140a17d70(i);
        Unk_CameraTargetEntity* pObject = pContext->FUN_141bd1050(pEntry->FUN_140a17cb0());
        Unk_RpgActor* pActor = FUN_1409ffd30(pObject);
        if (pActor)
        {
            Unk_CameraManager::FUN_1409478c0()->FUN_140aeaf40(pActor, 1);
            break;
        }
    }
}
MS2_REPLACE_METHOD(0x141858480, CToolSmoothCameraMode, vfunc_30, 326, 0x992A3EE3);

// @0x1418585d0
void CToolSmoothCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    CConsoleCameraMode::vfunc_24(p, n);
    if (p)
    {
        m_50 = m_c0.m_pos.FUN_140965c40(p->vfunc_18()).FUN_140967ac0();
        m_78 = p->vfunc_18();
        m_78.z = m_78.z + vfunc_27();
        Vector3 ptRot = FUN_1410a0a00(FUN_1409f2540());
        vfunc_4(ptRot);
        m_d8.m_rot = ptRot;
        m_c0.m_rot = ptRot;
    }
}
MS2_REPLACE_METHOD(0x1418585D0, CToolSmoothCameraMode, vfunc_24, 434, 0x00620478);

// @0x141858790
BOOL CToolSmoothCameraMode::vfunc_31()
{
    if (FUN_140ae8540())
    {
        m_154 = FUN_140ae8910(CString("ToolSmooth_KeyMoveSpeed"));
        m_158 = FUN_140ae8910(CString("ToolSmooth_KeyRotationSpeed"));
        m_15c = FUN_140ae8910(CString("ToolSmooth_MouseRotationSpeed"));
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141858790, CToolSmoothCameraMode, vfunc_31, 213, 0x5FEEEF7C);

// @0x141858980
CRuntimeClass* FUN_141858980()
{
    return CDialog::GetThisClass();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbbe70-0x142cbbf90 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x1418588c0, FUN_1418588c0, 162, 0x1E8F04A1);
MS2_REPLACE_METHOD(0x141857480, CToolSmoothCameraMode, vfunc_8, 2134, 0x211EFDDB);
MS2_REPLACE(0x141858980, FUN_141858980, 14, 0xFC327C3B);

