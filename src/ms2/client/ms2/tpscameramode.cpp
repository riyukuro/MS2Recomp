// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See tpscameramode.h.
// MS2-UNIT: ?\tpscameramode.cpp
// MS2-RANGE: 0x14185aa10-0x14185b1b0 .text$mn
// MS2-PIN: ??_GCTPSCameraMode@@UEAAPEAXI@Z 0x14185afb0
// MS2-PIN: memmove_s 0x14185b010
// MS2-FUNCTIONAL: ??0_ATL_WIN_MODULE70 (0x14185b130) / ??1_ATL_WIN_MODULE70 (0x14185b170) are toolchain ATL COMDATs; the
// exe's ATL build had a nothrow CSimpleArray<ATOM> (no EH state) and its dtor call is ICF-folded with
// CAtlArray<void*>::~CAtlArray (0x1408f2340), hence the cross-unit alias CONFLICT on ??1?$CSimpleArray@G...
// MS2-PIN: ??0_ATL_WIN_MODULE70@ATL@@QEAA@XZ 0x14185b130
// MS2-FUNCTIONAL ??0_ATL_WIN_MODULE70@ATL@@QEAA@XZ: the toolchain's ATL header (VS2017 atlbase.h) builds the member array with an EH state; the exe's older ATL constructs it nothrow with an explicit growth argument (ctor 0x140a698a0 with 10) - not reproducible without the original ATL headers
// MS2-PIN: ??1_ATL_WIN_MODULE70@ATL@@QEAA@XZ 0x14185b170
// MS2-FUNCTIONAL ??1_ATL_WIN_MODULE70@ATL@@QEAA@XZ: bytes equal the exe; its member-array dtor call binds ~CSimpleArray<ATOM>, which the exe ICF-folded into CAtlArray<void*>::~CAtlArray (0x1408f2340) while symbols.tsv holds 0x14041cf90 (gameeventreturnuser) - cross-unit alias, not a type error
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tpscameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "tpscameramode.h"

#include <NiAVObject.h>
#include <NiFixedString.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

MS2_EMIT_CRT_MEMMOVE_S();

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
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42(float fAlpha, bool bFade);
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
const Unk_StreamPoint* FUN_140947900(NiAVObject* p);        // &world translate

float FUN_140a38cd0(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
int FUN_140ae8540();                                // reloads the camera xml (returns 0 on failure)
int FUN_140ae89e0(CString key);                     // integer value of the camera xml key

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14185aa10
CTPSCameraMode::CTPSCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CFPSCameraMode(pOwner, pPrev)
{
}

// @0x14185aa90
CTPSCameraMode::~CTPSCameraMode()
{
}

// @0x14185aac0
void CTPSCameraMode::vfunc_8(double fTime)
{
    CFPSCameraMode::vfunc_8(fTime);
}
MS2_REPLACE_METHOD(0x14185aac0, CTPSCameraMode, vfunc_8, 36, 0xF8B84114);

// @0x14185aaf0
void CTPSCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_RpgActor* pActor = FUN_1409ffd30(p);
    if (m_130 && m_130 != pActor)
    {
        if (m_130)
            m_130->vfunc_42(1.0f, 1);
    }
    m_130 = pActor;
    if (m_130)
    {
        NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410(m_130));
        if (pRoot)
        {
            NiFixedString kName("TPS_Dummy");
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
            m_130->vfunc_42(0.0f, 1);
    }
    m_68 = m_48;
    m_f0 = 0;
    float fX = m_50 * FUN_1409f25a0(m_68) + m_78.x;
    float fY = m_50 * FUN_1409f2310(m_68) + m_78.y;
    float fZ = m_50 * FUN_1409f2310(m_6c) + m_78.z;
    m_d8.m_pos = Unk_StreamPoint(fX, fY, fZ);
    m_8c = m_d8.m_pos.FUN_140965c40(m_78);
    m_d8.m_rot = FUN_1410a0a00(m_d8.m_pos);
    m_c0 = m_d8;
    vfunc_3(m_d8.m_pos);
    vfunc_4(m_d8.m_rot);
}
MS2_REPLACE_METHOD(0x14185aaf0, CTPSCameraMode, vfunc_24, 1154, 0x5AFB40B1);

// @0x14185af80
BOOL CTPSCameraMode::vfunc_31()
{
    m_140 = 0;
    m_144 = 0;
    return 0;
}
MS2_REPLACE_METHOD(0x14185af80, CTPSCameraMode, vfunc_31, 38, 0x9014BB20);
