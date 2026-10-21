// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See localtargetcameramode.h.
// MS2-UNIT: ?\localtargetcameramode.cpp
// MS2-RANGE: 0x140d4dce0-0x140d4fcd0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GCLocalTargetCameraMode@@UEAAPEAXI@Z 0x140d4fc40 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0CLocalTargetCameraMode@@QEAA@PEAVUnk_CameraOwner@@V?$MS2Ptr@VCCameraMode@@@@@Z 0x140d4dce0
// MS2-PIN: ?get@?$MS2Ptr@VCCameraMode@@@@QEBAPEAVCCameraMode@@XZ 0x1409f2180
// MS2-PIN: ??C?$MS2Ptr@VCCameraMode@@@@QEBAPEAVCCameraMode@@XZ 0x1409f21a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\localtargetcameramode.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "localtargetcameramode.h"

#include <math.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

extern const Unk_StreamPoint g_143a08cf8;   // NiPoint3::UNIT_Z

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

// The camera target entity, with the slots past vfunc_18.
class Unk_TargetEnt : public Unk_CameraTargetEntity
{
public:
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(Unk_StreamPoint pt);              // set the player rotation
};

// The target's rpg object (FUN_1409ffd30); slot 20 reads the player rotation.
class Unk_TargetRpg
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual Unk_StreamPoint vfunc_20();
};
Unk_TargetRpg* FUN_1409ffd30(Unk_CameraTargetEntity* p);    // rpg object of a target
void FUN_14166d8b0(Unk_TargetRpg* p, float fYaw);

float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
Unk_CameraSetting* FUN_140947880(CCameraMode* p);           // &p->m_setting
bool FUN_140aed0d0(Unk_CameraManager* pMgr);                // the camera setup is active?
void FUN_140aec8a0(Unk_CameraManager* pMgr, bool b);
void FUN_140aeb920(Unk_CameraManager* pMgr);
void FUN_140aed720(Unk_CameraManager* pMgr, Unk_CameraSetup* pSetup);
void FUN_140947980(Unk_CameraManager* pMgr, int nMode);
void* FUN_140ad4b90();                                      // world service
bool FUN_141863100(void* service, int mapId, const Unk_StreamPoint& pos);   // is the position inside the map?
float FUN_141b6fe40(float t, int nInterpolator);            // easing

// @0x140d4fc90
inline const Unk_CameraPose& FUN_140d4fc90(CTargetCameraMode* p) { return p->m_c0; }
// @0x140d4fcb0
inline const Unk_CameraPose& FUN_140d4fcb0(CTargetCameraMode* p) { return p->m_d8; }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140d4dce0
CLocalTargetCameraMode::CLocalTargetCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CTargetCameraMode(pOwner, pPrev),
      m_108(),
      m_178(0),
      m_17c(0),
      m_180(0),
      m_184(0),
      m_188(0),
      m_194(),
      m_1a0(),
      m_1ac(0.0f, 0.0f, 0.0f),
      m_1b8(0.0f),
      m_1bc(0.0f),
      m_1c0(0.0f),
      m_1c4(),
      m_1ec(0),
      m_1f0(0)
{
    if (pPrev.get())
    {
        m_1ec = pPrev->vfunc_1();
        Unk_CameraSetting* pSetting = FUN_140947880(pPrev.operator->());
        m_1b8 = pPrev->vfunc_23();
        m_1bc = pPrev->vfunc_22();
        m_1c0 = pPrev->vfunc_19();
        m_178 = 1;
        m_188 = 0;
        m_190 = pPrev->FUN_140ad4b30();
        m_194 = pSetting->m_18;
        m_1a0 = pSetting->m_c;
        m_18c = pSetting->m_c.FUN_140965c40(pPrev->vfunc_35()).FUN_140967ac0();
        m_78 = pPrev->vfunc_35();
        m_setting = *pSetting;
        m_1c4 = *pSetting;
        CTargetCameraMode* pTarget = dynamic_cast<CTargetCameraMode*>(pPrev.get());
        if (pTarget)
        {
            m_c0 = FUN_140d4fc90(pTarget);
            m_d8 = FUN_140d4fcb0(pTarget);
            pTarget->FUN_14183d9a0(m_9c, m_a0, m_a4);
        }
        else
        {
            m_d8.m_pos = FUN_1409f2540();
            m_d8.m_rot = FUN_140af8260();
            m_c0 = m_d8;
            m_9c = FUN_1401d3200()->m_1a80.FUN_1402bac70();
            m_a0 = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
            m_a4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
        }
    }
}

// @0x140d4e2b0
CLocalTargetCameraMode::~CLocalTargetCameraMode()
{
}

// @0x140d4e2e0
void CLocalTargetCameraMode::vfunc_6(int n)
{
    CCameraMode::vfunc_6(0);
    m_f0 = 1;
}
MS2_REPLACE_METHOD(0x140d4e2e0, CLocalTargetCameraMode, vfunc_6, 45, 0x0BA7AB48);

// @0x140d4e320
void CLocalTargetCameraMode::vfunc_7()
{
    if (m_1ec == 2)
    {
        CCameraMode* pMode = Unk_CameraManager::FUN_1409478c0()->FUN_140af24f0();
        if (pMode)
            static_cast<CTargetCameraMode*>(pMode)->FUN_14183dfe0(m_c0, m_d8);
    }
}
MS2_REPLACE_METHOD(0x140d4e320, CLocalTargetCameraMode, vfunc_7, 93, 0xD7644922);

// @0x140d4e390
// MS2-FUNCTIONAL: the stack slots of the temporaries (and 15 bytes of code) differ from the exe; behaviour is the same
void CLocalTargetCameraMode::vfunc_8(double fTime)
{
    if (!FUN_140aed0d0(Unk_CameraManager::FUN_1409478c0()))
    {
        FUN_140d4f830();
    }
    else if (m_17c != 0)
    {
        Unk_TargetEnt* pTarget = static_cast<Unk_TargetEnt*>(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60());
        if (!pTarget)
        {
            FUN_140aec8a0(Unk_CameraManager::FUN_1409478c0(), false);
        }
        else if (m_184 == 0)
        {
            float fDist = pTarget->vfunc_18().FUN_140965c40(m_108.m_setting.m_c).FUN_140967ac0();
            if (m_108.m_30 < fDist)
                FUN_140d4f830();
        }
    }
    else if (m_180 != 0)
    {
        Unk_TargetEnt* pTarget = static_cast<Unk_TargetEnt*>(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60());
        if (!pTarget)
        {
            FUN_140aec8a0(Unk_CameraManager::FUN_1409478c0(), false);
        }
        else if (m_184 == 0)
        {
            if (!FUN_141863100(FUN_140ad4b90(), m_108.m_34, pTarget->vfunc_18()))
                FUN_140d4f830();
        }
    }

    Unk_TargetEnt* pTarget = static_cast<Unk_TargetEnt*>(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60());
    if (!pTarget)
        return;

    Unk_TargetRpg* pRpg = FUN_1409ffd30(pTarget);
    Unk_StreamPoint ptCenter;
    m_78 = pTarget->vfunc_17();
    m_78.z += vfunc_27();
    ptCenter = m_78;
    if (m_178 != 0)
    {
        m_188 = (float)((double)m_188 + fTime);
        float t = 0.0f;
        if (m_184 != 0)
        {
            Unk_StreamPoint ptEye = m_d8.m_pos;
            if (m_6c <= 0.15f)
                m_6c = 0.15f;
            if (1.57f <= m_6c)
                m_6c = 1.57f;
            ptEye.x = m_1c0 * FUN_1409f25a0(m_1b8) + ptCenter.x;
            ptEye.y = m_1c0 * FUN_1409f2310(m_1b8) + ptCenter.y;
            ptEye.z = m_1c0 * FUN_1409f2310(m_1bc) + ptCenter.z;
            m_108.m_setting.m_c = ptEye;
            m_108.m_setting.m_18 = CCameraMode::FUN_140afdd40(ptCenter, ptEye, g_143a08cf8);
            if (m_188 < m_108.m_3c)
            {
                t = m_188 / m_108.m_3c;
                t = FUN_141b6fe40(t, m_108.m_60);
                m_50 = m_108.m_38 * t + (1.0f - t) * m_18c;
                ptCenter = ptCenter.FUN_14097fd50(m_108.m_40.FUN_14097fc90(t));
                m_d8.m_pos = m_1a0.FUN_14097fd50(FUN_1409ab5c0(t, m_108.m_setting.m_c.FUN_140965c40(m_1a0)));
                Unk_StreamPoint ptDelta = ptCenter.FUN_140965c40(m_d8.m_pos);
                if (ptDelta.x == ptDelta.y)
                    m_d8.m_pos.x += 5.0f;
                m_d8.m_rot = CCameraMode::FUN_140afdd40(ptCenter, m_d8.m_pos, g_143a08cf8);
                vfunc_39(fTime);
                vfunc_11(m_190 + t * (m_108.m_setting.m_0 - m_190));
            }
            else
            {
                t = 1.0f;
                m_d8.m_rot = m_108.m_setting.m_18;
                m_d8.m_pos = m_108.m_setting.m_c;
                vfunc_39(fTime);
                m_178 = 0;
                FUN_140aed720(Unk_CameraManager::FUN_1409478c0(), &m_108);
                if (m_1ec == 0 || m_1ec == 2)
                    FUN_140947980(Unk_CameraManager::FUN_1409478c0(), 2);
                else
                    FUN_140947980(Unk_CameraManager::FUN_1409478c0(), m_1ec);
                vfunc_11(m_108.m_setting.m_0);
            }
        }
        else
        {
            if (m_188 < m_108.m_3c)
            {
                t = m_188 / m_108.m_3c;
                t = FUN_141b6fe40(t, m_108.m_5c);
                m_50 = m_108.m_38 * t + (1.0f - t) * m_18c;
                m_d8.m_rot = CCameraMode::FUN_140afdec0(t, m_194, m_108.m_setting.m_18);
                Unk_NiMatrix3 kRot;
                kRot.FUN_142083d40(m_d8.m_rot.x * -0.0174532924f, m_d8.m_rot.y * -0.0174532924f,
                                   m_d8.m_rot.z * -0.0174532924f);
                Unk_StreamPoint ptDir;
                kRot.FUN_140a01190(0, ptDir);
                ptCenter = ptCenter.FUN_14097fd50(m_108.m_40.FUN_14097fc90(t));
                m_d8.m_pos = ptDir.FUN_1409f7960().FUN_14097fc90(m_50).FUN_14097fd50(ptCenter);
                m_d8.m_rot = CCameraMode::FUN_140afdd40(ptCenter, m_d8.m_pos, g_143a08cf8);
                vfunc_39(fTime);
                if (m_108.m_58)
                {
                    Unk_StreamPoint ptRot = m_1ac.FUN_14097fd50(FUN_1409ab5c0(t, m_108.m_4c.FUN_140965c40(m_1ac)));
                    pTarget->vfunc_21(ptRot);
                    if (pRpg)
                        FUN_14166d8b0(pRpg, ptRot.z);
                }
                vfunc_11(m_190 + t * (m_108.m_setting.m_0 - m_190));
            }
            else
            {
                t = 1.0f;
                m_d8.m_rot = m_108.m_setting.m_18;
                Unk_NiMatrix3 kRot;
                kRot.FUN_142083d40(m_108.m_setting.m_18.x * -0.0174532924f, m_108.m_setting.m_18.y * -0.0174532924f,
                                   m_108.m_setting.m_18.z * -0.0174532924f);
                Unk_StreamPoint ptDir;
                kRot.FUN_140a01190(0, ptDir);
                ptCenter = ptCenter.FUN_14097fd50(m_108.m_40);
                m_50 = m_108.m_38;
                m_d8.m_pos = ptDir.FUN_1409f7960().FUN_14097fc90(m_108.m_38).FUN_14097fd50(ptCenter);
                m_d8.m_rot = m_108.m_setting.m_18;
                vfunc_39(fTime);
                m_178 = 0;
                if (m_108.m_58)
                {
                    pTarget->vfunc_21(m_108.m_4c);
                    if (pRpg)
                        FUN_14166d8b0(pRpg, m_108.m_4c.z);
                }
                vfunc_11(m_108.m_setting.m_0);
            }
        }
    }
    else
    {
        Unk_StreamPoint ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
        if (ptMove.FUN_140552700(g_143b01a60))
        {
            m_1f0 = (int)((float)m_1f0 - ptMove.x);
            if (m_1f0 < m_108.m_64)
                m_1f0 = m_108.m_64;
            if (m_108.m_68 < m_1f0)
                m_1f0 = m_108.m_68;
        }
        m_d8.m_rot = m_108.m_setting.m_18;
        Unk_NiMatrix3 kRot;
        kRot.FUN_142083d40(m_108.m_setting.m_18.x * -0.0174532924f, m_108.m_setting.m_18.y * -0.0174532924f, m_108.m_setting.m_18.z * -0.0174532924f);
        Unk_StreamPoint ptDir;
        kRot.FUN_140a01190(0, ptDir);
        ptCenter = ptCenter.FUN_14097fd50(m_108.m_40);
        float fDist = m_108.m_38 + (float)(m_1f0 * m_108.m_6c);
        m_d8.m_pos = ptDir.FUN_1409f7960().FUN_14097fc90(fDist).FUN_14097fd50(ptCenter);
        m_d8.m_rot = m_108.m_setting.m_18;
        if (m_108.m_setting.m_0 != m_setting.m_0)
            vfunc_11(m_108.m_setting.m_0);
        vfunc_39(fTime);
    }
}

// @0x140d4f520
void CLocalTargetCameraMode::vfunc_10()
{
    m_f0 = 0;
    Unk_CameraManager::FUN_1409478c0()->FUN_140aeaf40(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60(), 1);
}
MS2_REPLACE_METHOD(0x140d4f520, CLocalTargetCameraMode, vfunc_10, 74, 0x67DE058B);

// @0x140d4f570
// MS2-FUNCTIONAL: the const-ref argument of vfunc_35's look-at is passed through a different temporary
void CLocalTargetCameraMode::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    m_18c = m_setting.m_c.FUN_140965c40(CCameraMode::vfunc_35()).FUN_140967ac0();
    Unk_TargetRpg* pRpg = FUN_1409ffd30(p);
    if (pRpg)
    {
        const Unk_StreamPoint& ptPos = m_setting.m_c;
        m_194 = CCameraMode::FUN_140afdd40(CCameraMode::vfunc_35(), ptPos, g_143a08cf8);
    }
}
MS2_REPLACE_METHOD(0x140d4f570, CLocalTargetCameraMode, vfunc_24, 182, 0xF93BE46C);

// @0x140d4f630
void CLocalTargetCameraMode::vfunc_37()
{
    m_8c = m_d8.m_pos.FUN_140965c40(m_78);
}
MS2_REPLACE_METHOD(0x140d4f630, CLocalTargetCameraMode, vfunc_37, 68, 0x09F34078);

// @0x140d4f680
void CLocalTargetCameraMode::FUN_140d4f680(const Unk_CameraSetup& setup)
{
    if (setup.m_28 == 1)
        m_17c = 1;
    else if (setup.m_28 == 3)
        m_180 = 1;
    m_108 = setup;
    m_178 = 1;
    m_1f0 = 0;
    Unk_TargetRpg* pRpg = FUN_1409ffd30(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60());
    if (pRpg)
    {
        m_1ac = pRpg->vfunc_20();
        m_108.m_4c.x = m_1ac.x;
        m_108.m_4c.y = m_1ac.y;
        if (m_1ac.z > 180.0f && m_108.m_4c.z < 180.0f)
            m_108.m_4c.z += 360.0f;
        else if (m_1ac.z < 180.0f && m_108.m_4c.z > 180.0f)
            m_1ac.z += 360.0f;
    }
}
MS2_REPLACE_METHOD(0x140d4f680, CLocalTargetCameraMode, FUN_140d4f680, 419, 0xF1BA60D2);

// @0x140d4f830
void CLocalTargetCameraMode::FUN_140d4f830()
{
    FUN_140aeb920(Unk_CameraManager::FUN_1409478c0());
    m_178 = 1;
    m_184 = 1;
    float fTime;
    if (m_108.m_3c > m_188)
        fTime = m_188;
    else
        fTime = m_108.m_3c;
    m_108.m_3c = fTime;
    m_188 = 0;
    m_108.m_setting = m_1c4;
    m_108.m_38 = m_18c;
    m_108.m_40 = Unk_StreamPoint(0.0f, 0.0f, 0.0f);
    m_108.m_58 = false;
    m_108.m_setting.m_0 = m_190;
    m_18c = m_50;
    m_190 = FUN_140ad4b30();
    m_194 = m_setting.m_18;
    m_1a0 = m_setting.m_c;
}
MS2_REPLACE_METHOD(0x140d4f830, CLocalTargetCameraMode, FUN_140d4f830, 397, 0xAECD03CE);

// @0x140d4fa10
void CLocalTargetCameraMode::FUN_140d4fa10(float f)
{
    m_108.m_setting.m_0 = f;
    m_1c4.m_0 = f;
    m_190 = f;
}
MS2_REPLACE_METHOD(0x140d4fa10, CLocalTargetCameraMode, FUN_140d4fa10, 69, 0x49A1496B);

// @0x140d4fa60
bool CLocalTargetCameraMode::FUN_140d4fa60(const Unk_CameraSetup& setup)
{
    if (m_178 == 0)
    {
        Unk_StreamPoint ptPos = setup.m_setting.m_c;
        Unk_TargetEnt* pTarget = static_cast<Unk_TargetEnt*>(Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60());
        if (pTarget)
            ptPos = pTarget->vfunc_18();
        m_108 = setup;
        m_1f0 = 0;
        m_d8.m_pos = setup.m_setting.m_c;
        m_d8.m_rot = setup.m_setting.m_18;
        m_c0.m_pos = ptPos;
        m_c0.m_rot = setup.m_setting.m_18;
        m_setting.m_c = ptPos;
        m_setting.m_18 = m_108.m_setting.m_18;
        m_pOwner->FUN_140a38dc0(ptPos);
        m_pOwner->FUN_140a38e00(m_108.m_setting.m_18);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140d4fa60, CLocalTargetCameraMode, FUN_140d4fa60, 476, 0xFF9E4AA5);

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x140d4fc90, FUN_140d4fc90, 17, 0xDF751E83);
MS2_REPLACE(0x140d4fcb0, FUN_140d4fcb0, 17, 0xAA3C736B);
MS2_REPLACE_METHOD(0x140d4e390, CLocalTargetCameraMode, vfunc_8, 4482, 0x0FA598F0);

