// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateJump, the actor state of a player jumping: picks the
// jump variant, plays the jump / fall animation, steers in the air with the launch direction and lands (on the ground,
// on a ridee or onto a sit / lie / climb object). See statejump.h.
// MS2-UNIT: ?\statejump.cpp
// MS2-RANGE: 0x140102ff0-0x140103020 .text$di
// MS2-RANGE: 0x1417d5160-0x1417d6c00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statejump.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <cstdlib>
#include <float.h>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "statejump.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/client/ms2/gameobjectcontroller.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------


void FUN_1409989e0(void* pOut, const char* psz);           // 0x1409989e0 efd::utf8string(const char*)
void FUN_1408a8900(void* pStr);                            // 0x1408a8900 ~efd::utf8string
const char* FUN_1408ac310(const efd::utf8string& str);     // 0x1408ac310 the string's c string
class Unk_CubeSelection;
        // the cube selection is in the craft mode
float FUN_14059d930(float f);                              // 0x14059d930 fabs
int FUN_14028d260(float f);                                // 0x14028d260 round to ms
unsigned FUN_140869420();                                  // 0x140869420 the millisecond clock
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);       // 0x1408a9bd0 the flat model of the entity
efd::Point3 FUN_140a0b080(efd::Point3 kDir, efd::Point3 kPos, const efd::Point3& kUp);   // 0x140a0b080 look-at angles
extern efd::Point3 DAT_143a08cf8;                          // the up axis

// The animation service: the sequence id of the model.
class Unk_JpAnimSvc { public: unsigned FUN_140b7f6a0(const egf::EntityID& kId); };
Unk_JpAnimSvc* FUN_141b6f910();

// The efd::Point3 *.
class Unk_JpConsts { public: char m_pad[0x48e8]; };
class Unk_JpScale { public: float* FUN_140298f40(); };
Unk_JpConsts* FUN_1401d3200();

// The actor's physics body.
class Unk_JpBody
{
public:
    void FUN_141240700(efd::Point3 kVel);
    void FUN_141240730();
    void FUN_141240610(float f, efd::Point3 kDir, float fSpeed);
    int FUN_141240780();
    int FUN_1412407a0();
    unsigned FUN_141240ef0();
    float FUN_141241090();
};
inline Unk_JpBody* JpBody(PCBase* p) { return reinterpret_cast<Unk_JpBody*>(p->FUN_14166d220()); }

// The actor's buffs.
class Unk_JpBuff
{
public:
    efd::Point3 FUN_141683290();                          // knock-back velocity
    bool FUN_141683100(int nBuff);
};

// The record reference of the actor (a 16-byte smart pointer: the record at +8).
struct Unk_JpRef { void* m_00; void* m_08; void* FUN_141371260() const { return m_08; } };
void FUN_141664200(MyPC* p, Unk_JpRef* pOut);              // 0x141664200 the actor's skill record ref
void* FUN_140c207b0(Unk_JpRef* p);
int FUN_14050a6a0(void* pRecord);
void FUN_141276180(const CString& strCommand, const CString& strArg);   // 0x141276180 run a client command
void FUN_140c20600(Unk_JpRef* p);

// The efd::utf8string the exe builds out of line (ctor 0x1409989e0, dtor 0x1408a8900; 0x20 bytes).
struct Unk_JpString
{
    Unk_JpString(const char* psz) { FUN_1409989e0(m_buf, psz); }
    ~Unk_JpString() { FUN_1408a8900(m_buf); }
    operator const efd::utf8string&() const { return *(const efd::utf8string*)m_buf; }
    char m_buf[0x20];
};

// The hide-and-seek jump animation name (set up by the .text$di init, cleared when the actor hides) and the toggle of the
// random jump.
static CString s_strHideSeekJump("System_HideNSeek_Jump_01");
static int s_nJumpToggle;

// @0x1417d5160
StateJump::StateJump(PCBase* pOwner) : State(pOwner), m_n54(1), m_n80(0x32)
{
    m_n14 = 0;
    m_vDir = efd::Point3::ZERO;
    m_nOnGround = 0;
    m_fSpeed = 0;
    m_pSeat = 0;
    m_f60 = -FLT_MAX;
    m_v64 = efd::Point3::ZERO;
    m_aSub[0] = 0x21;
    m_aSub[1] = 0x23;
    (m_aSub + 2)[0] = 0x22;
    (m_aSub + 2)[1] = 0x24;
}

// @0x1417d52e0
StateJump::~StateJump()
{
}

// @0x1417d5320
// MS2-FUNCTIONAL: the record ref has no dtor (the exe has two more EH states)
void StateJump::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spJump.AssignRaw(dynamic_cast<StateJumpData*>(pData));
    if (m_pOwner->FUN_141676b70() != 0)
    {
        m_n10 = 0x27;
    }
    else if (m_n10 == 0)
    {
        m_n10 = 0x21;
    }
    else if (m_n10 == 0x25)
    {
        s_nJumpToggle = (s_nJumpToggle + 1) % 2;
        int nSub;
        if (rand() % 2 != 0)
            nSub = (m_aSub + 2)[s_nJumpToggle];
        else
            nSub = m_aSub[s_nJumpToggle];
        m_n10 = nSub;
    }
    m_pSeat = 0;
    m_f60 = -FLT_MAX;
    m_v64 = efd::Point3::ZERO;
    m_vDir = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
    m_n54 = 1;
    m_fSpeed = m_pOwner->FUN_141671940();
    m_nOnGround = m_pOwner->FUN_1416749c0();
    float fA = m_pOwner->FUN_14166da60();
    float fSpeed = m_pOwner->vfunc_95();
    Unk_JpBody* pBody = JpBody(m_pOwner);
    pBody->FUN_141240730();
    pBody->FUN_141240610(fA, m_vDir, fSpeed);
    reinterpret_cast<Unk_IntervalTimer*>(&m_tick)->Init();
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        pPC->FUN_141676060(m_pOwner->vfunc_18());
        pPC->FUN_14152e170(0, 6);
        Unk_JpRef ref;
        FUN_141664200(pPC, &ref);
        if (ref.FUN_141371260() ? true : false)
        {
            if (FUN_14050a6a0(FUN_140c207b0(&ref)) == 1)
                FUN_141276180(s_strHideSeekJump, "");
        }
        FUN_140c20600(&ref);
    }
}

extern const NiPoint3 DAT_143b01a60;

// @0x1417d5700
// MS2-FUNCTIONAL: the zero point is copied byte-wise in the exe
void StateJump::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_141671960(m_fSpeed);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        if (n != 5 && n != 4 && n != 0x10)
            pPC->FUN_141676060(DAT_143b01a60);
        pPC->FUN_14152e170(1, 6);
    }
}

// @0x1417d57b0
void StateJump::vfunc_6()
{
    State::vfunc_6();
    m_n10 = 0x26;
    unsigned nSeq = FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460());
    if (!m_pOwner->FUN_14166de90(0x35, nSeq))
    {
        efd::utf8string strAnim(m_pOwner->vfunc_123(0x35));
        m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
    }
}

// @0x1417d58d0
// MS2-FUNCTIONAL: vfunc_18 returns NiPoint3 in the shared gameobject.h (efd::Point3 in the exe), so extra copies
void StateJump::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Unk_JpBody* pBody = JpBody(m_pOwner);
    if (pBody->FUN_141240780() != 0)
    {
        efd::Point3 kWorld = m_pOwner->FUN_141674b60(m_pOwner->FUN_14123c360());
        if (m_pOwner->FUN_14166dbb0() != efd::Point3::ZERO)
        {
            m_vDir = m_pOwner->FUN_14166dbb0();
            if (m_spJump)
            {
                efd::Point3 kJump = m_spJump->m_pos;
                efd::Point3 kRot = FUN_140a0b080(kJump, m_pOwner->vfunc_18(), DAT_143a08cf8);
                m_pOwner->FUN_14166d970(kRot);
            }
        }
        else
        {
            if (m_nOnGround == 0 && m_n54 != 0 && kWorld != efd::Point3::ZERO)
            {
                m_vDir = kWorld;
                m_n54 = 0;
                m_pOwner->FUN_141671960(1.0f);
            }
            else if (kWorld != efd::Point3::ZERO)
            {
                m_vDir = kWorld;
            }
        }
        float fScale = *reinterpret_cast<Unk_JpScale*>(reinterpret_cast<char*>(FUN_1401d3200()) + 0x48e8)->FUN_140298f40();
        efd::Point3 kVel = (m_vDir * m_pOwner->vfunc_95()) * fScale;
        JpBody(m_pOwner)->FUN_141240700(kVel);
        efd::Point3 kMove = efd::Point3::ZERO;
        m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
    }
    else
    {
        m_pOwner->vfunc_59(4, 0, 0, 0);
    }
}

// @0x1417d5c70
void StateJump::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    Unk_JpBuff* pBuff = (Unk_JpBuff*)m_pOwner->FUN_14166d240();
    m_pOwner->vfunc_22(pBuff->FUN_141683290());
    if (m_pOwner->FUN_141676b70() != 0)
        m_n10 = 0x27;
    if (pPC != 0 && pBuff->FUN_141683100(0x30d41))
    {
        if (!FUN_1417d65d0())
            return;
        egf::Entity* pEntity = reinterpret_cast<PC*>(pPC)->FUN_141659af0(1);
        if (pEntity != 0)
        {
            if (pPC->FUN_1416764a0())
            {
                MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
                spAction->m_n28 = 1;
                if (FUN_1408a9bd0(pEntity)->ContainsModel(0xbadf0a13))
                    spAction->m_n2c = 0xbadf0a13;
                else if (FUN_1408a9bd0(pEntity)->ContainsModel(0xc13e30c8))
                    spAction->m_n2c = 0xc13e30c8;
                pPC->SendRequestRideMode1(spAction);
            }
            else
            {
                pPC->FUN_1415248d0(1, 0);
            }
        }
        else
        {
            if (pPC->FUN_141678820() != 0 && reinterpret_cast<PC*>(pPC)->FUN_14165b500(1) != 0)
                pPC->FUN_1416788d0();
        }
    }
    else
    {
        if (!FUN_1417b9460() && pPC != 0 && FUN_1417d65d0() && FUN_1417d6620() == 0)
        {
            if (pPC->FUN_1416764a0())
            {
                if (m_pOwner->FUN_141678820() != 0 && reinterpret_cast<PC*>(pPC)->FUN_14165b500(1) != 0)
                    pPC->SendRequestRideMode1(new RideOffActionAutoClimb(1));
            }
            else
            {
                if (pPC->FUN_141678820() != 0 && reinterpret_cast<PC*>(pPC)->FUN_14165b500(1) != 0)
                    pPC->FUN_1416788d0();
            }
        }
    }
}

// @0x1417d6000
// MS2-FUNCTIONAL: temporaries / frame layout differ from the exe
void StateJump::vfunc_9(double fTime)
{
    static int s_nDelay = FUN_14028d260(sqrt(12.0f / FUN_14059d930(GameObjectController::FUN_141240c40(true))));
    State::vfunc_9(fTime);
    unsigned nSeq = FUN_141b6f910()->FUN_140b7f6a0(m_pOwner->FUN_14123c460());
    unsigned nLimit = s_nDelay;
    nLimit += FUN_14028d260(JpBody(m_pOwner)->FUN_141241090());
    if (m_pOwner->FUN_141671a30() != 0)
    {
        m_pOwner->vfunc_59(4, 0, 0, 0);
        return;
    }
    if (nLimit <= JpBody(m_pOwner)->FUN_141240ef0())
    {
        m_pOwner->FUN_14166dda0(5);
        return;
    }
    if (m_n10 == 0x27 || m_n10 == 0x21 || m_n10 == 0x22 || m_n10 == 0x23 || m_n10 == 0x24)
    {
        int nAnim;
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0 && reinterpret_cast<PC*>(pPC)->FUN_1416595d0() != 0 && ((Unk_PCCubeCraft*)((Unk_CubeSelection*)(reinterpret_cast<PC*>(pPC)->GetCubeCraft())))->FUN_1410aa010())
        {
            if (JpBody(m_pOwner)->FUN_1412407a0() != 0)
                nAnim = 0x3a;
            else
                nAnim = 0x3b;
        }
        else if (JpBody(m_pOwner)->FUN_1412407a0() != 0)
        {
            bool bHas = true;
            efd::utf8string strSpecial(m_pOwner->vfunc_123(0x2a));
            if (!m_pOwner->FUN_141679220(FUN_1408ac310(strSpecial)))
                bHas = false;
            if (bHas && (m_n10 == 0x22 || m_n10 == 0x24))
            {
                nAnim = 0x2a;
            }
            else
            {
                if (m_n10 == 0x27)
                    nAnim = 0x46;
                else
                    nAnim = 4;
            }
        }
        else
        {
            bool bHas = true;
            efd::utf8string strSpecial(m_pOwner->vfunc_123(0x2b));
            if (!m_pOwner->FUN_141679220(FUN_1408ac310(strSpecial)))
                bHas = false;
            if (bHas && (m_n10 == 0x22 || m_n10 == 0x24))
            {
                nAnim = 0x2b;
            }
            else
            {
                if (m_n10 == 0x27)
                    nAnim = 0x47;
                else
                    nAnim = 2;
            }
        }
        if (!m_pOwner->FUN_14166de90(nAnim, nSeq))
        {
            efd::utf8string strAnim(m_pOwner->vfunc_123(nAnim));
            m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
        }
    }
}

// @0x1417d64c0
int StateJump::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p == 0)
        return 0;
    if (m_n10 == p->m_nSub)
        return 0;
    return 1;
}

// @0x1417d6560
bool StateJump::vfunc_28(MS2Ptr<Unk_StateArg22> p)
{
    return FUN_1417b7e40() != p->m_nSub;
}

// @0x1417d65d0
bool StateJump::FUN_1417d65d0()
{
    int nStart = reinterpret_cast<Unk_IntervalTimer*>(&m_tick)->GetLast();
    int nMin = m_n80;
    return (unsigned)(nStart + nMin) < FUN_140869420();
}

// @0x1417d6620
int StateJump::FUN_1417d6620()
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return 0;
    if (m_pSeat == 0)
    {
        if (m_nOnGround == 0)
        {
            if (JpBody(m_pOwner)->FUN_1412407a0() != 0)
                return 0;
        }
        m_pSeat = reinterpret_cast<PC*>(pPC)->FUN_141659af0(0);
    }
    if (m_pSeat != 0)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
        {
            MS2Ptr<RideOffActionTakeLR> spAction(new RideOffActionTakeLR(1));
            spAction->m_n28 = 0;
            if (FUN_1408a9bd0(m_pSeat)->ContainsModel(0xbadf0a13))
                spAction->m_n2c = 0xbadf0a13;
            else if (FUN_1408a9bd0(m_pSeat)->ContainsModel(0xc13e30c8))
                spAction->m_n2c = 0xc13e30c8;
            if (pPC->SendRequestRideMode1(spAction) != 0)
                pPC->vfunc_59(1, 0, 0, 0);
        }
        else if (FUN_1408a9bd0(m_pSeat)->ContainsModel(0xbadf0a13))
        {
            m_pOwner->vfunc_22(efd::Point3::ZERO);
            m_pOwner->vfunc_59(8, 0, 0, 0);
        }
        else if (FUN_1408a9bd0(m_pSeat)->ContainsModel(0xc13e30c8))
        {
            m_pOwner->vfunc_22(efd::Point3::ZERO);
            m_pOwner->vfunc_59(9, 0, 0, 0);
        }
        return 1;
    }
    return 0;
}

// @0x1417d6ac0
int StateJump::vfunc_15()
{
    return 1;
}

// @0x1417d6ad0
int StateJump::vfunc_1()
{
    return 6;
}

// @0x1417d6ae0
int StateJump::vfunc_19()
{
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb77e0-0x142cb7800 .text$yd
