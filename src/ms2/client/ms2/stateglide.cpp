// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateGlide, the actor state of a player gliding: falls with
// the glide animation, drifts forward along the skill row's curves and plays a looping effect. See stateglide.h.
// MS2-UNIT: ?\stateglide.cpp
// MS2-RANGE: 0x1417c8900-0x1417ca270 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateglide.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <math.h>
#include <efd/utf8string.h>

#include "stateglide.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/client/ms2/worldservice.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

void FUN_14165f170(PCBase* p);                             // 0x14165f170
void* FUN_1403ed280();                                     // effect manager
int FUN_1411a49c0(void* pEffectMgr, Unk_EffectQuery* pQuery);
void FUN_1411a6060(void* pEffectMgr, int nId);
class Unk_PCBaseBody;
class Unk_GlideBody { public: void FUN_141240730(); };     // the actor body (+0x150)
void FUN_141240700(Unk_PCBaseBody* pBody, efd::Point3 kVel);               // 0x141240700
class Unk_PCBaseBodyDummy;
class Unk_GlideHit { public: void FUN_140cfaf30(); };
Unk_GlideHit* FUN_141240f20(Unk_PCBaseBody* pBody);

// The owner's vtable up to slot 68, which takes the move by value (the exe passes a pointer to a copy).
class Unk_GlOwnerSlots
{
public:
#define MS2_GL_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_GL_SLOTS(0, 1, 2, 3, 4) MS2_GL_SLOTS(5, 6, 7, 8, 9) MS2_GL_SLOTS(10, 11, 12, 13, 14)
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual efd::Point3 vfunc_18();                                                 // 18 returns the position by value
    virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kDir);                                        // 22 takes the direction by value
    virtual void vfunc_23(); virtual void vfunc_24();
    MS2_GL_SLOTS(25, 26, 27, 28, 29) MS2_GL_SLOTS(30, 31, 32, 33, 34)
    MS2_GL_SLOTS(35, 36, 37, 38, 39) MS2_GL_SLOTS(40, 41, 42, 43, 44) MS2_GL_SLOTS(45, 46, 47, 48, 49)
    MS2_GL_SLOTS(50, 51, 52, 53, 54) MS2_GL_SLOTS(55, 56, 57, 58, 59) MS2_GL_SLOTS(60, 61, 62, 63, 64)
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67();
#undef MS2_GL_SLOTS
    virtual bool vfunc_68(efd::Point3 kMove, double fTime, int b, unsigned c, int d);   // 68 0x14166e100
};
bool FUN_14028d470(float a, float b);                      // approximately equal
CStringW GetStringCommonByKey(const CStringW& strKey);             // string table text
void FUN_1412751f0(const CStringW& str, int a, int b);     // 0x1412751f0 chat notice

// The skill table (FUN_1401958b0): the row of a glide data id.
class Unk_GlideTable { public: MS2Ptr<Unk_GlideRow> FUN_1407ee470(int nId); };
Unk_GlideTable* FUN_1401958b0();

// The world service (0x1403ed2d0): the upper bound of the map.
class Unk_GlideWorld { public: efd::Point3 FUN_141bd3820(); };

// The actor's buff set: the airborne check.

// The actor's buff view: the movement direction.
class Unk_GlideBuff { public: efd::Point3 FUN_141683900(); };

// The actor's player character (+ the buff based speed bonus).
PC* FUN_140974230(PCBase* p);

// The cube grid: the cell of a cube key and the centre point of a cell.
struct Unk_GlCell { Unk_GlCell(); int x, y, z; };
Unk_GlCell FUN_1408a0400(int nKey);
efd::Point3 FUN_1408a15b0(Unk_GlCell kCell, efd::Point3& kCentre);     // fills kCentre with the cell centre

// The PhysX helper (0x1409f7ca0): ground below a point.
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();
class Unk_GlidePhys
{
public:
    int FUN_14168a450(const efd::Point3& kPos, float* pfDist, float fMaxDist);     // ground below kPos
    bool FUN_14168a770(const efd::Point3* pPoint);
};

// @0x1417c8900
StateGlide::StateGlide(PCBase* pOwner) : StateMoveSkill(pOwner), m_nEffect(0)
{
    m_fTime = 0;
    m_fStartZ = 0;
    m_bHeightErr = false;
    m_bTooHigh = false;
    m_n44 = 0x1e;
    m_nFallbackState = 5;
    m_n10 = 99;
    m_nAnim = 99;
    m_nMode = 1;
}

// @0x1417c89e0
StateGlide::~StateGlide()
{
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417c8a60
void StateGlide::vfunc_4(StateData* pData)
{
    StateMoveSkill::vfunc_4(pData);
    if (m_spRow == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }
    m_fTime = 0;
    efd::Point3 kCentre(0.0f, 0.0f, 0.0f);
    FUN_1408a15b0(FUN_1408a0400(m_pOwner->FUN_1416782e0()), kCentre);
    m_fStartZ = kCentre.z;
    m_bHeightErr = false;
    m_bTooHigh = false;
    bool bFromGlide = static_cast<CStateManager*>(m_pOwner->GetStateMgr())->GetPrev() == 0x1e;
    if (bFromGlide)
    {
        m_bTooHigh = FUN_1417ca000() == 0;
        if (m_bTooHigh && m_pOwner->vfunc_108() != 0)
            FUN_1412751f0(GetStringCommonByKey(L"s_err_skill_maximum_Height"), 1, 1);
    }
    ((Unk_GlideBody*)m_pOwner->FUN_14166d220())->FUN_141240730();
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        efd::Point3 kPos = reinterpret_cast<Unk_GlOwnerSlots*>(pPC)->vfunc_18();
        if (((Unk_GlidePhys*)FUN_1409f7ca0())->FUN_14168a770(&kPos))
        {
            pPC->vfunc_59(1, 0, 0, 0);
            return;
        }
        FUN_14165f170(pPC);
        ((CPushControl*)pPC->FUN_141675eb0())->FUN_1413fcf90();
    }
    m_nAnim = 99;
    Unk_EffectQuery query;
    query.m_strName = m_spRow->m_strEffectB;
    query.m_nObject = 0;
    query.SetActor(m_pOwner->FUN_14123c580());
    query.m_bFlag31 = true;
    m_nEffect = FUN_1411a49c0(FUN_1403ed280(), &query);
    m_pOwner->vfunc_47(false);
    m_pOwner->FUN_141670330((float)m_spRow->m_nSpeedMul);
    m_pOwner->FUN_141670360((float)m_spRow->m_nSpeedMul);
    efd::utf8string strAnim(m_spRow->m_strAnimB);
    m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), false, false);
}

// @0x1417c8f60
void StateGlide::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_pOwner->FUN_14166d220() != 0)
        FUN_141240f20(m_pOwner->FUN_14166d220())->FUN_140cfaf30();
    if (m_spRow == 0)
        return;
    FUN_1417c9880((float)fTime);
    int bLand = 0;
    if (m_spRow->m_bCheckGround)
    {
        if (m_pOwner->FUN_141671a30() != 0)
        {
            bLand = 1;
        }
        else
        {
            efd::Point3 kPos = reinterpret_cast<Unk_GlOwnerSlots*>(m_pOwner)->vfunc_18();
            float fDist = 0.0f;
            if (((Unk_GlidePhys*)FUN_1409f7ca0())->FUN_14168a450(kPos, &fDist, 200.0f) != 0 && fDist < 100.0f)
                bLand = 1;
        }
    }
    if (m_pOwner->GetClassID() == 0x6200044)
        bLand = 0;
    if (((AdditionalCliList*)m_pOwner->FUN_1416749a0())->FUN_140970a00() != 0 || bLand)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417c9110
void StateGlide::vfunc_5(int n)
{
    StateMoveSkill::vfunc_5(n);
    ((Unk_GlideBody*)m_pOwner->FUN_14166d220())->FUN_141240730();
    m_pOwner->FUN_141670330(0);
    m_pOwner->FUN_141670360(0);
    m_pOwner->vfunc_47(true);
    FUN_1411a6060(FUN_1403ed280(), m_nEffect);
    m_nAnim = 99;
    if (m_nEffect != 0)
    {
        FUN_1411a6060(FUN_1403ed280(), m_nEffect);
        m_nEffect = 0;
    }
    m_spRow.AssignRaw(0);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        pPC->FUN_141676060(reinterpret_cast<const NiPoint3&>(efd::Point3::ZERO));
    m_pOwner->FUN_14166f8f0(0, 1);
}

// @0x1417c9250
void StateGlide::vfunc_7(int n)
{
    m_pOwner->vfunc_59(n, 0, 0, 0);
}

// @0x1417c92a0
void StateGlide::vfunc_8(double fTime)
{
    StateMoveSkill::vfunc_8(fTime);
    Unk_GlideBuff* pBuff = (Unk_GlideBuff*)m_pOwner->FUN_14166d240();
    efd::Point3 kDir = pBuff->FUN_141683900();
    reinterpret_cast<Unk_GlOwnerSlots*>(m_pOwner)->vfunc_22(kDir);
    if (m_pOwner->FUN_1416749c0())
        m_n10 = 100;
    else
        m_n10 = 99;
}

// @0x1417c9360
void StateGlide::vfunc_9(double fTime)
{
    if (m_nAnim != m_n10)
    {
        if (m_nAnim == 99)
        {
            if (m_nEffect != 0)
            {
                FUN_1411a6060(FUN_1403ed280(), m_nEffect);
                Unk_EffectQuery query;
                query.m_strName = m_spRow->m_strEffectA;
                query.m_nObject = 0;
                query.SetActor(m_pOwner->FUN_14123c580());
                query.m_bFlag31 = true;
                m_nEffect = FUN_1411a49c0(FUN_1403ed280(), &query);
            }
            efd::utf8string strAnim(m_spRow->m_strAnimA);
            m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), false, false);
        }
        else
        {
            if (m_nEffect != 0)
            {
                FUN_1411a6060(FUN_1403ed280(), m_nEffect);
                Unk_EffectQuery query;
                query.m_strName = m_spRow->m_strEffectB;
                query.m_nObject = 0;
                query.SetActor(m_pOwner->FUN_14123c580());
                query.m_bFlag31 = true;
                m_nEffect = FUN_1411a49c0(FUN_1403ed280(), &query);
            }
            efd::utf8string strAnim(m_spRow->m_strAnimB);
            m_pOwner->FUN_14166dd20(strAnim, m_pOwner->FUN_1416713c0(), false, false);
        }
        m_nAnim = m_n10;
    }
}

// @0x1417c9660
bool StateGlide::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    if (m_spRow == 0)
        return true;
    return m_spRow->m_nSkill != p->m_n68;
}

// @0x1417c9710
int StateGlide::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    return 1;
}

// @0x1417c9740
int StateGlide::FUN_1417c9740()
{
    if (m_spRow == 0)
        return 0;
    return m_spRow->FUN_140802ab0();
}

// @0x1417c9790
bool StateGlide::vfunc_38(StateData* pData)
{
    if (!StateMoveSkill::vfunc_38(pData))
        return false;
    StateGlideData* pGlide = dynamic_cast<StateGlideData*>(pData);
    if (pGlide == 0)
        return false;
    m_spRow = FUN_1401958b0()->FUN_1407ee470(pGlide->m_n20);
    if (m_spRow == 0)
        return false;
    return true;
}

// @0x1417c9880
void StateGlide::FUN_1417c9880(float fTime)
{
    m_fTime += fTime;
    efd::Point3 kMove = (FUN_1417c9c00() + FUN_1417c9ee0()) * fTime;
    m_pOwner->FUN_141671960(FUN_1417c9b70());
    FUN_141240700(m_pOwner->FUN_14166d220(), FUN_1417c9ee0());
    reinterpret_cast<Unk_GlOwnerSlots*>(m_pOwner)->vfunc_68(kMove, fTime, 0, 0x10, 1);
}

extern "C" float (__cdecl* __imp_cosf)(float);   // cosf through the CRT import table (the exe calls it indirectly)

// @0x1417c99f0
float StateGlide::FUN_1417c99f0()
{
    if (FUN_14028d470(m_spRow->m_f34, 0))
        return 0.0f;
    if (FUN_14028d470(m_spRow->m_f38, 0))
        return 0.0f;
    return m_spRow->m_f34 * __imp_cosf((m_fTime * 3.1415927f * 2.0f) / m_spRow->m_f38);
}

// @0x1417c9ad0
float StateGlide::FUN_1417c9ad0()
{
    float fBonus = 0.0f;
    PC* pActor = FUN_140974230(m_pOwner);
    if (pActor != 0)
    {
        fBonus += pActor->FUN_141662930(0x73);
    }
    return m_spRow->m_f30 + m_spRow->m_f30 * fBonus;
}

// @0x1417c9b70
float StateGlide::FUN_1417c9b70()
{
    return m_spRow->m_f28;
}

// @0x1417c9ba0
efd::Point3 StateGlide::FUN_1417c9ba0()
{
    return m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
}

// @0x1417c9c00
efd::Point3 StateGlide::FUN_1417c9c00()
{
    if (m_bTooHigh)
        return efd::Point3::ZERO;
    float fSway = FUN_1417c99f0();
    float fFall = m_spRow->m_f2c * m_fTime;
    if (!FUN_14028d470(m_spRow->m_f3c, 0))
        fFall = fFall > m_spRow->m_f3c ? m_spRow->m_f3c : fFall;
    float fTotal = FUN_1417c9ad0() + fFall;
    if (!m_bHeightErr)
    {
        m_bHeightErr = FUN_1417ca000() == 0;
        if (m_bHeightErr == true && m_pOwner->vfunc_108() != 0)
            FUN_1412751f0(GetStringCommonByKey(L"s_err_skill_maximum_Height"), 1, 1);
    }
    float fZ = m_bHeightErr ? fSway : (fTotal += fSway);
    if (!m_bHeightErr)
        fZ -= m_spRow->m_f1c;
    return efd::Point3::UNIT_Z * fZ;
}

// @0x1417c9ee0
efd::Point3 StateGlide::FUN_1417c9ee0()
{
    float fForward = m_spRow->m_f24 * m_fTime;
    if (!FUN_14028d470(m_spRow->m_f40, 0))
        fForward = fForward > m_spRow->m_f40 ? m_spRow->m_f40 : fForward;
    float fSpeed = FUN_1417c9b70() + fForward;
    if (20.0f < fSpeed)
        fSpeed = 20.0f;
    return FUN_1417c9ba0() * fSpeed;
}

// @0x1417ca000
int StateGlide::FUN_1417ca000()
{
    const efd::Point3& kPos = static_cast<const efd::Point3&>(m_pOwner->vfunc_18());
    if (reinterpret_cast<Unk_GlideWorld*>(WorldService::GetInstance())->FUN_141bd3820().z - 300.0f < kPos.z)
        return 0;
    if (0.0f < m_spRow->m_f20 && m_spRow->m_f20 < m_pOwner->vfunc_18().z - m_fStartZ)
        return 0;
    return 1;
}

// @0x1417ca1e0
MS2Ptr<StateData> StateGlide::vfunc_27()
{
    return MS2Ptr<StateData>(new StateGlideData());
}

// @0x1417ca260
int StateGlide::vfunc_1()
{
    return 0x1e;
}
