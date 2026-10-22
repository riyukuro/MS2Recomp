// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateIdle and its siblings, the actor states of a standing
// player / npc / pet / fitting doll: pick and play the idle animation of the sub state, run the bore and emotion
// timers and start the idle sounds. See stateidle.h.
// MS2-UNIT: ?\stateidle.cpp
// MS2-RANGE: 0x1417cd420-0x1417d0be0 .text$mn
// MS2-PIN: memmove_s 0x1417d0ac0
#pragma function(memmove)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateidle.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <string.h>

#include <new>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <efd/utf8string.h>

#include "stateidle.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

extern Unk_StreamPoint DAT_143b01a60;                    // the zero point

// The item a state is told about in its slots 29/30.
class Unk_StateArg29 : public CItem { };

// A npc / pet actor: the animation named by the npc's record.
class CNpc : public PCBase
{
public:
    CString FUN_141093530();                             // the jump animation name of the record
};

// Buff container of an actor.
class Unk_SiBuffMgr
{
public:
    Unk_StreamPoint FUN_141683290();                     // knock-back direction
    bool FUN_141683100(int nBuff);
    bool FUN_141682fe0(int nBuff);
};

// The player-side views of the actor (PC members seen through the PCBase pointer of FUN_1417b8370).
class Unk_PCD88 : public CPtred { public: int FUN_140a35780(); };    // the target the player is bound to
class Unk_SiPC
{
public:
    void FUN_141659000(int n);
    int FUN_141659610();                                 // sitting
    int FUN_141659690();                                 // lying
    int FUN_141654700();                                 // the job
    MS2Ptr<Unk_PCD88> FUN_14165c2d0();                   // copies the +0xd88 pointer out
    CString FUN_14165e010(int nKey);                     // the player's sound name of a key
    void FUN_14165e2a0(void* pStr, int nKey);            // the player's animation name of a key
};
// The actor's +0xd00 action table lookup (returns an int; pcbase.h declares it void).
class Unk_SiActor { public: int FUN_141679120(int n); };
inline Unk_SiActor* AsActor(PCBase* p) { return reinterpret_cast<Unk_SiActor*>(p); }
#define AsPC(p) reinterpret_cast<Unk_SiPC*>(p)

// The efd::utf8string the exe builds out of line (ctor 0x1409989e0, dtor 0x1408a8900; 0x20 bytes).
void FUN_1409989e0(void* pOut, const char* psz);           // 0x1409989e0 efd::utf8string(const char*)
void FUN_1408a8700(void* pStr);                            // 0x1408a8700 efd::utf8string()
void FUN_1408a8900(void* pStr);                            // 0x1408a8900 ~efd::utf8string
void FUN_140ae18f0(void* pStr, const char* psz);           // 0x140ae18f0 efd::utf8string::operator=(const char*)
bool FUN_14096ad40(const efd::utf8string& str);            // 0x14096ad40 the string is empty
struct Unk_SiString
{
    Unk_SiString() { FUN_1408a8700(m_buf); }
    Unk_SiString(const char* psz) { FUN_1409989e0(m_buf, psz); }
    ~Unk_SiString() { FUN_1408a8900(m_buf); }
    Unk_SiString& operator=(const char* psz) { FUN_140ae18f0(m_buf, psz); return *this; }
    operator const efd::utf8string&() const { return *(const efd::utf8string*)m_buf; }
    char m_buf[0x20];
};
// The exe passes the string's address directly (no conversion call).
#define SI_STR(k) (*reinterpret_cast<const efd::utf8string*>(&(k)))

// The animation service: the sequence id / actor manager of a model key.
class Unk_SiAnimSvc
{
public:
    unsigned FUN_140b7f6a0(const Unk_GoModelKey& kKey);
    NiActorManager* FUN_140999440(const Unk_GoModelKey& kKey);
};
Unk_SiAnimSvc* FUN_141b6f910();
unsigned FUN_1409a1a00(NiActorManager* pMgr);              // 0x1409a1a00 the manager's target animation

// Config constants singleton (FUN_1401d3200).
class Unk_SiDelay { public: unsigned FUN_14025a620(); char m_c; };
class Unk_SiUInt { public: unsigned* FUN_1401d7c10(); char m_c; };
class Unk_SiName { public: CString* FUN_140298f80(); char m_c; };
class Unk_SiConsts
{
public:
    char m_pad0[0x8a0];
    Unk_SiDelay m_delayLeave;                            // +0x8a0
    char m_pad1[0xa00 - 0x8a1];
    Unk_SiDelay m_delayBore;                             // +0xa00
    char m_pad2[0x7de0 - 0xa01];
    Unk_SiUInt m_intervalA;                              // +0x7de0
    char m_pad3[0x7e90 - 0x7de1];
    Unk_SiUInt m_intervalB;                              // +0x7e90
    char m_pad4[0xe038 - 0x7e91];
    Unk_SiName m_strSoundJob50;                          // +0xe038
    char m_pad5[0xe098 - 0xe039];
    Unk_SiName m_strSoundJob110;                         // +0xe098
};
MS2_CHECK_OFFSET(Unk_SiConsts, m_delayBore, 0xa00);
MS2_CHECK_OFFSET(Unk_SiConsts, m_intervalB, 0x7e90);
MS2_CHECK_OFFSET(Unk_SiConsts, m_strSoundJob110, 0xe098);
Unk_SiConsts* FUN_1401d3200();
class Unk_PCBaseComp_aa8 : public CPtred { public: int FUN_140f48d40(); };     // the pet component
CStateService* FUN_140aa6d30();                            // 0x140aa6d30 the actor state manager
egf::Entity* FUN_141659af0(MyPC* p, int n);                // 0x141659af0 the nearby object to sit on
egf::FlatModel* FUN_1408a9bd0(egf::Entity* pEntity);       // 0x1408a9bd0
Ridee* FUN_141468360(PCBase* p);                           // 0x141468360 the ridee the actor sits on

// The effect service and the player manager.
CEffectService* FUN_1403ed280();
class Unk_SiWorld { public: int FUN_141bd1a10(GameObject* pObject); };
Unk_SiWorld* FUN_1403ed2d0();

// Scene / mode queries of the bore timer.
class Unk_SiScene;
Unk_SiScene* FUN_1408e57f0();
int FUN_1422b9ea0(Unk_SiScene* p);
class Unk_SiMode;
Unk_SiMode* FUN_14025e7a0();
int FUN_1422ae940(Unk_SiMode* p);
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);     // 0x14087ddc0 the class (or a base) has the id

// The npc's pet bookkeeping (idle voices).
PCBase* FUN_140b10360(PCBase* pNpc);                       // 0x140b10360 the pet of the npc
void FUN_140b11180(PCBase* pNpc);                          // 0x140b11180
void FUN_140b114e0(PCBase* pNpc, int nVoice);              // 0x140b114e0 say a voice
class Unk_SiPetRow : public CPtred { };
class Unk_SiPetTable { public: MS2Ptr<Unk_SiPetRow> FUN_140c892c0(int nId); };
class Unk_SiPetBook { public: int FUN_140b11e90(PCBase* pPet); };
class Unk_SiPetData { public: char m_pad[0x68]; Unk_SiPetBook m_book; };
class Unk_SiPetMgr;
Unk_SiPetMgr* FUN_140535320();
Unk_SiPetData* FUN_140c8b450(Unk_SiPetMgr* p);
Unk_SiPetTable* FUN_140c8b430(Unk_SiPetMgr* p);
bool FUN_1401c0050(MS2Ptr<Unk_SiPetRow>* p, int n);      // MS2Ptr::operator==(T*)

// ---- StateIdle ----

// @0x1417cd420
StateIdle::StateIdle(PCBase* pOwner) : State(pOwner)
{
    m_nSoundIdle = 0;
}

// @0x1417cd4a0
StateIdle::~StateIdle()
{
    FUN_1417cf210();
    FUN_1417cf4a0();
}

// @0x1417cd520
void StateIdle::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    if (m_pOwner->FUN_141676b70() != 0)
        vfunc_2(0xc);
    else
        vfunc_2(1);
    m_timerBore.FUN_1408687f0();
    m_timerLeave.FUN_1408687f0();
    if (m_pOwner->FUN_141675ed0() != 0)
    {
        if (m_pOwner->GetClassID() == 0x6200045)
            PCBase::FUN_141677f40(m_pOwner);
        vfunc_2(7);
        if (m_nSoundIdle == 0)
            FUN_1417cf260();
    }
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
        AsPC(pPC)->FUN_141659000(0);
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC != 0)
        static_cast<CPushControl*>(pMyPC->FUN_141675eb0())->FUN_1413fcf90();
    m_pOwner->FUN_14166f8f0(0, 1);
}

// @0x1417cd680
// MS2-FUNCTIONAL: slot 68 takes the move point by value in the exe, but the shared header declares void*.
void StateIdle::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Unk_StreamPoint kMove = DAT_143b01a60;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417cd700
void StateIdle::vfunc_5(int n)
{
    State::vfunc_5(n);
    FUN_1417cf210();
    FUN_1417cf4a0();
}

// @0x1417cd740
int StateIdle::vfunc_15()
{
    if (m_n10 == 7)
        return 0;
    if (m_n10 == 6)
        return 0;
    return 1;
}

// @0x1417cd770
// MS2-FUNCTIONAL: slot 22 of GameObject takes the point by value in the exe (second 12-byte copy), but the shared
// header declares it by reference; the sit / lie action pointer is a plain MS2Ptr.
void StateIdle::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (FUN_140aa6d30()->FUN_1417e2610() == 0x620000d)
    {
        FUN_1417cef60();
        return;
    }
    MyPC* pPC = FUN_1417b84b0();
    if (m_pOwner->vfunc_63() == 0)
        return;
    int nWater = m_pOwner->FUN_141675ed0();
    Unk_SiBuffMgr* pBuff = static_cast<Unk_SiBuffMgr*>(m_pOwner->FUN_14166d240());
    Unk_StreamPoint kPos = pBuff->FUN_141683290();
    Unk_StreamPoint kArg = kPos;
    m_pOwner->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kArg));
    if (m_pOwner->FUN_141676b70() == 0)
    {
        if (m_n10 == 0xc)
            vfunc_2(1);
    }
    else
    {
        vfunc_2(0xc);
    }
    if (pPC != 0 && pBuff->FUN_141683100(0x30d41))
    {
        egf::Entity* pEntity = FUN_141659af0(pPC, 1);
        if (pEntity != 0)
        {
            if (pPC->FUN_1416764a0() == 0)
            {
                pPC->FUN_1415248d0(1, 0);
            }
            else
            {
                RideOffActionTakeLR* pAction = new RideOffActionTakeLR(1);
                MS2Ptr<RideOffAction> spAction(pAction);
                pAction->m_n28 = 1;
                if (FUN_1408a9bd0(pEntity)->ContainsModel(0xbadf0a13))
                {
                    pAction->m_n2c = 0xbadf0a13;
                }
                else if (FUN_1408a9bd0(pEntity)->ContainsModel(0xc13e30c8))
                {
                    pAction->m_n2c = 0xc13e30c8;
                }
                pPC->SendRequestRideMode1(spAction.get());
            }
        }
    }
    else if (pPC != 0 && pBuff->FUN_141683100(0x30d42))
    {
        pPC->FUN_1415248d0(2, 0);
    }
    else if (m_pOwner->FUN_141671a30() != 0 && pBuff->FUN_141682fe0(0x493e1))
    {
        m_pOwner->vfunc_59(6, 0, 0x25, 0);
    }
    else if (m_pOwner->FUN_1416749c0())
    {
        m_pOwner->vfunc_59(2, 0, 0, 0);
    }
    else if (pBuff->FUN_141682fe0(0x493e5) == 0 || nWater != 0)
    {
        FUN_1417b9460();
    }
    else
    {
        m_pOwner->vfunc_59(3, 0, 0, 0);
    }
    if (nWater == 0)
        FUN_1417cef60();
}

// @0x1417cdbb0
// MS2-FUNCTIONAL: the exe holds the ridee in a CComPtr (temp + EH frame); a raw pointer is used here
void StateIdle::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    Unk_GoModelKey kKey;
    Unk_GoModelKey& rKey = m_pOwner->FUN_14123c460(kKey);
    unsigned nSeq = FUN_141b6f910()->FUN_140b7f6a0(rKey);
    const efd::ClassInfo* pDesc;
    if (m_pOwner == 0)
        pDesc = 0;
    else
        pDesc = m_pOwner->GetClassDesc();
    if (!FUN_14087ddc0(pDesc, 0x6200044))
    {
        int nWater = m_pOwner->FUN_141675ed0();
        if (nWater == 0 && m_pOwner->vfunc_99(0) != 0)
        {
            m_pOwner->vfunc_59(5, 0, 0, 0);
            return;
        }
        PCBase* pPC = FUN_1417b8370();
        if (FUN_1417b84b0() != 0)
        {
            Ridee* pRidee = FUN_141468360(m_pOwner);
            if (pRidee != 0)
            {
                if (pRidee->FUN_1417075e0() != 0)
                    nWater = 0;
            }
            if (nWater == 0)
            {
                if (pPC != 0)
                {
                    if (m_n10 == 7)
                        vfunc_2(1);
                    if (AsPC(pPC)->FUN_141659610() == 0)
                    {
                        if (AsPC(pPC)->FUN_141659690() == 0)
                        {
                            if (m_n10 == 8 || m_n10 == 9)
                                vfunc_2(1);
                        }
                        else
                        {
                            vfunc_2(8);
                        }
                    }
                    else
                    {
                        vfunc_2(9);
                    }
                }
            }
            else
            {
                vfunc_2(7);
            }
        }
        if (m_n10 != 7 && m_nSoundIdle != 0)
        {
            FUN_1417cf210();
            return;
        }
    }
    switch (m_n10 - 1)
    {
    case 0:
        FUN_1417ce6f0(nSeq);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        FUN_1417ce820(nSeq);
        break;
    case 5:
        FUN_1417ce9f0(nSeq);
        break;
    case 6:
        FUN_1417ceab0(nSeq);
        break;
    case 7:
        FUN_1417ceca0(nSeq);
        break;
    case 8:
        FUN_1417ced70(nSeq);
        break;
    case 9:
        if (m_pOwner->vfunc_65() != 0)
            m_pOwner->FUN_14166ce70(0);
        if (m_pOwner->FUN_14166dda0(0x3d))
            m_pOwner->FUN_14166f8f0(0, 1);
        break;
    case 10:
    {
        if (m_pOwner->vfunc_65() != 0)
            m_pOwner->FUN_14166ce70(0);
        Unk_SiString kName("FittingDoll_Idle_A");
        bool bPlayed = m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        if (bPlayed)
            m_pOwner->FUN_14166f8f0(0, 1);
        break;
    }
    case 0xb:
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x1e));
        m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        break;
    }
    case 0xc:
        FUN_1417ce970(nSeq);
        break;
    case 0xd:
        FUN_1417ce9b0(nSeq);
        break;
    case 0x13:
        FUN_1417cee40(nSeq);
        break;
    case 0x14:
        FUN_1417cee90(nSeq);
        break;
    case 0x15:
    {
        if (m_pOwner->vfunc_65() != 0)
            m_pOwner->FUN_14166ce70(0);
        Unk_SiString kName("Emotion_MusicStart_A");
        bool bPlayed = m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        if (bPlayed)
            m_pOwner->FUN_14166f8f0(0, 1);
        break;
    }
    case 0x4b:
    {
        Unk_SiString kName("Equip_Change_Cap_A");
        m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        break;
    }
    case 0x4d:
    {
        Unk_SiString kName("Equip_Change_Body_A");
        m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        break;
    }
    case 0x50:
    {
        Unk_SiString kName("Equip_Change_Glove_A");
        m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        break;
    }
    case 0x51:
    {
        Unk_SiString kName("Equip_Change_Mantle_A");
        m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        break;
    }
    case 0x52:
    {
        Unk_SiString kName("Equip_Change_Shoes_A");
        m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
        break;
    }
    }
}

// @0x1417ce460
void StateIdle::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    if (!m_pOwner->FUN_14166de90(0x27, eSequenceID))
    {
        if (m_pOwner->FUN_14166de90(0x49, eSequenceID))
        {
            vfunc_2(0x15);
            unsigned nSeq = FUN_1409a1a00(pkManager);
            FUN_1417cee90(nSeq);
            FUN_1417cf360();
        }
    }
    else
    {
        vfunc_2(1);
        unsigned nSeq = FUN_1409a1a00(pkManager);
        FUN_1417ce6f0(nSeq);
    }
    if (m_n10 == 0x4c || m_n10 == 0x4e || m_n10 == 0x53 || m_n10 == 0x51 || m_n10 == 0x52)
    {
        vfunc_2(1);
    }
    else if (m_n10 == 0xd || m_n10 == 0xe)
    {
        vfunc_2(0x15);
    }
}

// @0x1417ce5b0
void StateIdle::vfunc_21(int n)
{
    m_timerLeave.FUN_140868750(FUN_1401d3200()->m_delayLeave.FUN_14025a620());
    vfunc_2(6);
}

// @0x1417ce600
int StateIdle::vfunc_14()
{
    if (m_n10 == 7)
        return 0;
    else
        return m_n14;
}

// @0x1417ce630
int StateIdle::vfunc_16()
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0 && AsPC(pPC)->FUN_141659610() != 0)
        return 1;
    return 0;
}

// @0x1417ce680
int StateIdle::vfunc_22(MS2Ptr<Unk_StateArg22> p)
{
    if (p->m_nSub != m_n10)
        return 1;
    return 0;
}

// @0x1417ce6f0
void StateIdle::FUN_1417ce6f0(unsigned nSeq)
{
    int nKey = 0;
    if (m_pOwner->vfunc_65() != 0)
        nKey = 1;
    if (!m_pOwner->FUN_14166de90(nKey, nSeq))
    {
        {
            Unk_SiString kName(m_pOwner->vfunc_123(nKey));
            m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
        }
        m_pOwner->FUN_14166f8f0(0, 1);
    }
}

// @0x1417ce820
// MS2-FUNCTIONAL: the efd::utf8string temporaries differ from the exe
void StateIdle::FUN_1417ce820(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x27, nSeq))
    {
        int nSub = m_n10 - 2;
        efd::utf8string kName = m_pOwner->FUN_141679170(0x27, nSub);
        if (!m_pOwner->FUN_141679220(kName.c_str()))
            kName = m_pOwner->FUN_141679170(0x27, 0);
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417ce970
void StateIdle::FUN_1417ce970(unsigned nSeq)
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        pPC->FUN_14166dda0(0x49);
}

// @0x1417ce9b0
void StateIdle::FUN_1417ce9b0(unsigned nSeq)
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
        pPC->FUN_14166dda0(0x49);
}

// @0x1417ce9f0
void StateIdle::FUN_1417ce9f0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x2e, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x2e));
        m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
    }
}

// @0x1417ceab0
// MS2-FUNCTIONAL: the exe holds the ridee in a CComPtr (temp + EH frame); a raw pointer is used here
void StateIdle::FUN_1417ceab0(unsigned nSeq)
{
    int nKey = 0x30;
    Ridee* pRidee = FUN_141468360(m_pOwner);
    if (pRidee != 0)
    {
        if (pRidee->FUN_1417075e0() != 0)
            nKey = 0;
    }
    Unk_SiString kName;
    if (nKey == 0x30)
    {
        PCBase* pPC = FUN_1417b8370();
        if (pPC != 0)
            AsPC(pPC)->FUN_14165e2a0(kName.m_buf, nKey);
    }
    if (FUN_14096ad40(SI_STR(kName)) && !m_pOwner->FUN_14166de90(nKey, nSeq))
        kName = m_pOwner->vfunc_123(nKey);
    bool bPlayed = false;
    if (!FUN_14096ad40(SI_STR(kName)))
        bPlayed = m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    if (bPlayed)
        FUN_1417cf210();
    if (m_nSoundIdle == 0)
        FUN_1417cf260();
}

// @0x1417ceca0
void StateIdle::FUN_1417ceca0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x37, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x37));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417ced70
void StateIdle::FUN_1417ced70(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x36, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x36));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417cee40
void StateIdle::FUN_1417cee40(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x49, nSeq))
        m_pOwner->FUN_14166dda0(0x49);
}

// @0x1417cee90
void StateIdle::FUN_1417cee90(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x4a, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x4a));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417cef60
// MS2-FUNCTIONAL: the player's target handle is held as a raw MS2Ptr view
void StateIdle::FUN_1417cef60()
{
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0 && pPC->FUN_1416764a0() == 0)
    {
        if (m_pOwner->vfunc_65() != 0)
            m_timerBore.FUN_1408687f0();
        bool bBusy = FUN_1422b9ea0(FUN_1408e57f0()) == 1;
        if (!bBusy)
            bBusy = FUN_1422ae940(FUN_14025e7a0()) == 1;
        if (m_n10 != 1 || m_pOwner->vfunc_65() != 0 || bBusy)
        {
            if (m_timerLeave.FUN_140868c00() != 0)
                vfunc_2(1);
        }
        else
        {
            MS2Ptr<Unk_PCD88> spTarget = AsPC(pPC)->FUN_14165c2d0();
            Unk_PCD88* pTarget = spTarget.get();
            if (pTarget != 0 && pTarget->FUN_140a35780() == 0 && m_timerBore.FUN_140868c00() != 0)
            {
                int nBore = AsActor(m_pOwner)->FUN_141679120(0x27);
                vfunc_2(nBore + 2);
                if (m_n10 < 2)
                    m_n10 = 2;
                if (5 < m_n10)
                    m_n10 = 5;
                m_timerBore.FUN_1408687f0();
            }
            if (m_timerBore.FUN_140868ba0() == 0)
                m_timerBore.FUN_140868750(FUN_1401d3200()->m_delayBore.FUN_14025a620());
        }
    }
}

// @0x1417cf210
void StateIdle::FUN_1417cf210()
{
    if (m_nSoundIdle != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nSoundIdle);
        m_nSoundIdle = 0;
    }
}

// @0x1417cf260
void StateIdle::FUN_1417cf260()
{
    FUN_1417cf210();
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = AsPC(pPC)->FUN_14165e010(0x30);
        kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        m_nSoundIdle = FUN_1403ed280()->FUN_1411a49c0(kTarget);
    }
}

// @0x1417cf360
void StateIdle::FUN_1417cf360()
{
    FUN_1417cf4a0();
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        Unk_EffectTarget kTarget;
        if (AsPC(pPC)->FUN_141654700() == 0x32)
        {
            kTarget.m_strName = *FUN_1401d3200()->m_strSoundJob50.FUN_140298f80();
        }
        else
        {
            if (AsPC(pPC)->FUN_141654700() != 0x6e)
                return;
            kTarget.m_strName = *FUN_1401d3200()->m_strSoundJob110.FUN_140298f80();
        }
        kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        kTarget.m_b30 = true;
        m_nSoundEmotion = FUN_1403ed280()->FUN_1411a49c0(kTarget);
    }
}

// @0x1417cf4a0
void StateIdle::FUN_1417cf4a0()
{
    if (m_nSoundEmotion != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nSoundEmotion);
        m_nSoundEmotion = 0;
    }
}

// @0x1417cf4f0
// MS2-FUNCTIONAL: the exe's smart-pointer temporaries and EH frame are not reproduced
void StateIdle::vfunc_29(MS2Ptr<Unk_StateArg29> p)
{
    State::vfunc_29(p);
    CItemGem* pGem = p->FUN_140527900();
    if (pGem != 0 && pGem->FUN_140d41400().get() != 0 && m_n10 == 7)
    {
        MS2Ptr<CGemSwim> spSwim(dynamic_cast<CGemSwim*>(pGem->FUN_140d41400().get()));
        if (spSwim.get() != 0)
            FUN_1417cf210();
    }
}

// ---- StateIdleNPC ----

// @0x1417cf710
StateIdleNPC::StateIdleNPC(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417cf750
StateIdleNPC::~StateIdleNPC()
{
}

// @0x1417cf780
void StateIdleNPC::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n10 = 1;
    Unk_GoModelKey kKey;
    NiActorManager* pMgr = FUN_141b6f910()->FUN_140999440(m_pOwner->FUN_14123c460(kKey));
    if (pMgr != 0)
    {
        unsigned nSeq = FUN_1409a1a00(pMgr);
        if (!m_pOwner->FUN_14166de90(0, nSeq))
        {
            if (!m_pOwner->FUN_14166de90(1, nSeq))
                m_pOwner->FUN_14166de90(0x27, nSeq);
        }
    }
}

// @0x1417cf860
void StateIdleNPC::FUN_1417cf860(unsigned nSeq)
{
    int nKey = 0;
    if (m_pOwner->vfunc_65() != 0)
        nKey = 1;
    if (!m_pOwner->FUN_14166de90(nKey, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(nKey));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
}

// ---- StateIdlePet ----

// @0x1417cf970
StateIdlePet::StateIdlePet(PCBase* pOwner) : State(pOwner), m_nVoiced(0), m_nTired(0)
{
}

// @0x1417cfa00
StateIdlePet::~StateIdlePet()
{
}

// @0x1417cfa30
void StateIdlePet::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    if (m_nTired == 0)
    {
        m_timerVoiceA.FUN_140268840();
        m_nTired = 1;
    }
}

// @0x1417cfa80
void StateIdlePet::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    PCBase* pPet = FUN_140b10360(pNpc);
    if (pPet == 0)
        return;
    FUN_140b11180(pNpc);
}

// @0x1417cfaf0
void StateIdlePet::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 1;
}

// @0x1417cfb30
void StateIdlePet::vfunc_9(double fTime)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc != 0)
    {
        PCBase* pPet = FUN_140b10360(pNpc);
        if (pPet != 0)
        {
            if (pPet->FUN_14166ce30() == 0 || AsPC(pPet)->FUN_141659610() == 0)
            {
                Unk_GoModelKey kKey;
                Unk_GoModelKey& rKey = m_pOwner->FUN_14123c460(kKey);
                unsigned nSeq = FUN_141b6f910()->FUN_140b7f6a0(rKey);
                switch (m_n10 - 1)
                {
                case 0:
                    FUN_1417cfea0(nSeq);
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    FUN_1417d0140(nSeq);
                    break;
                case 0xe:
                    FUN_1417d0210(nSeq);
                    break;
                case 0xf:
                    FUN_1417d02e0(nSeq);
                    break;
                case 0x10:
                    FUN_1417d03b0(nSeq);
                    break;
                case 0x12:
                    FUN_1417d0470(nSeq);
                    break;
                }
            }
            else
            {
                Unk_SiString kName("Tired_A");
                m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
            }
        }
    }
}

// @0x1417cfd60
void StateIdlePet::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    {
        MS2Ptr<Unk_PCBaseComp_aa8> spComp = pNpc->vfunc_85();
        if (spComp.get() != 0)
        {
            if (spComp->FUN_140f48d40() == 0)
            {
                if (m_nVoiced != 0)
                    m_n10 = 1;
                m_nVoiced = 0;
            }
        }
        if (m_pOwner->FUN_14166de90(0x27, eSequenceID))
        {
            m_n10 = 1;
            unsigned nSeq = FUN_1409a1a00(pkManager);
            FUN_1417cfea0(nSeq);
        }
        else if (m_pOwner->FUN_14166de90(0x44, eSequenceID))
            m_n10 = 1;
    }
}

// @0x1417cfea0
void StateIdlePet::FUN_1417cfea0(unsigned nSeq)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc != 0)
    {
        PCBase* pPet = FUN_140b10360(pNpc);
        if (pPet != 0)
        {
            if (m_timerVoiceA.FUN_140268870(*FUN_1401d3200()->m_intervalA.FUN_1401d7c10()) != 0)
                FUN_1417d0540(0x5a);
            if (m_timerVoiceB.FUN_140268870(*FUN_1401d3200()->m_intervalB.FUN_1401d7c10()) != 0)
            {
                Unk_SiPetData* pData = FUN_140c8b450(FUN_140535320());
                int nPetId = pData->m_book.FUN_140b11e90(pPet);
                if (nPetId != 0)
                {
                    MS2Ptr<Unk_SiPetRow> spRow = FUN_140c8b430(FUN_140535320())->FUN_140c892c0(nPetId);
                    if (spRow == 0)
                        FUN_1417d0540(0x5f);
                }
            }
        }
        if (!m_pOwner->FUN_14166de90(0x27, nSeq))
        {
            if (!m_pOwner->FUN_14166de90(0, nSeq))
            {
                Unk_SiString kName(m_pOwner->vfunc_123(0));
                m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
            }
        }
        else
        {
            Unk_SiString kName(m_pOwner->vfunc_123(0x27));
            m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
        }
    }
}

// @0x1417d0140
void StateIdlePet::FUN_1417d0140(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x27, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x27));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x5c);
}

// @0x1417d0210
void StateIdlePet::FUN_1417d0210(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x42, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x42));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x5d);
}

// @0x1417d02e0
void StateIdlePet::FUN_1417d02e0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x43, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x43));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x5e);
}

// @0x1417d03b0
void StateIdlePet::FUN_1417d03b0(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x44, nSeq))
    {
        Unk_SiString kName("Revive_A");
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x60);
}

// @0x1417d0470
void StateIdlePet::FUN_1417d0470(unsigned nSeq)
{
    if (!m_pOwner->FUN_14166de90(0x45, nSeq))
    {
        Unk_SiString kName(m_pOwner->vfunc_123(0x45));
        m_pOwner->FUN_14166dd20(SI_STR(kName), m_pOwner->FUN_1416713c0(), false, false);
    }
    FUN_1417d0540(0x61);
}

// @0x1417d0540
void StateIdlePet::FUN_1417d0540(int nVoice)
{
    PCBase* pNpc = FUN_1417b83a0();
    if (pNpc == 0)
        return;
    if (m_nVoiced != 0)
        return;
    FUN_140b114e0(pNpc, nVoice);
    m_nVoiced = 1;
}

// ---- StateJumpNpc ----

// @0x1417d05a0
StateJumpNpc::StateJumpNpc(PCBase* pOwner) : State(pOwner)
{
    m_pNpc = dynamic_cast<CNpc*>(pOwner);
}

// @0x1417d0620
void StateJumpNpc::vfunc_4(StateData* pData)
{
    if (m_pNpc == 0)
        return;
    CString strAnim = m_pNpc->FUN_141093530();
    Unk_SiString kName((const char*)strAnim);
    m_pNpc->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
}

// @0x1417d08a0
StateJumpNpc::~StateJumpNpc()
{
}

// ---- StatePuppetNpc ----

// @0x1417d08c0
StatePuppetNpc::~StatePuppetNpc()
{
}

// @0x1417d06e0
StatePuppetNpc::StatePuppetNpc(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417d0720
void StatePuppetNpc::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
    float fEventTime)
{
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// ---- StateIdleFittingDoll ----

// @0x1417d0780
StateIdleFittingDoll::StateIdleFittingDoll(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417d07c0
StateIdleFittingDoll::~StateIdleFittingDoll()
{
}

// @0x1417d07f0
void StateIdleFittingDoll::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n10 = 1;
    Unk_SiString kName("EMPTY_SEQUENCE_AT_0f");
    m_pOwner->FUN_14166dd20(SI_STR(kName), 1.0f, false, false);
}

// @0x1417d0890
void StateIdleFittingDoll::vfunc_5(int n)
{
}

// ---- trivial slots ----

// @0x1417d0a60
int StateIdle::vfunc_1()
{
    return 1;
}

// @0x1417d0a70
int StateIdleFittingDoll::vfunc_1()
{
    return 1;
}

// @0x1417d0a80
int StateIdleNPC::vfunc_1()
{
    return 1;
}

// @0x1417d0a90
int StateIdlePet::vfunc_1()
{
    return 1;
}

// @0x1417d0aa0
int StateJumpNpc::vfunc_1()
{
    return 6;
}

// @0x1417d0ab0
int StatePuppetNpc::vfunc_1()
{
    return 0x23;
}

// ---- trailing CRT inline ----

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h) ends the unit; the pointer keeps the unreferenced COMDAT.
// @0x1417d0ac0
__declspec(selectany) extern errno_t(__cdecl* const g_pStateIdleMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
