// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateTalk (type 0x16, 0x48) is the player's side of an
// npc dialogue: on enter it looks the npc's two talk animations (owner slot 123 names 0x2d / 0x2e) up in the model
// and, if both exist and the npc's record is talkable, plays the first one (phase 0x47) - otherwise the idle motion
// (phase 0x49); the update plays the talking / waiting loop anim and spawns the dialogue effect of the client config
// (+0x290 / +0x298) whenever the phase changes. StateTalkNpc (type 0x16, 0x40) is the npc's own side: it mirrors the
// talk manager into m_n10 and plays the talking (0x2e) or the idle (0) animation. The unit also holds its unreferenced
// CRT memmove_s copy (0x1417fce10).
// MS2-UNIT: ?\statetalk.cpp
// MS2-RANGE: 0x1417fc010-0x1417fcf30 .text$mn
// MS2-PIN: ??_7StateTalk@@6B@ 0x142f74e78 ; order
// MS2-PIN: ??_7StateTalkNpc@@6B@ 0x142f74fa0 ; order
// MS2-PIN: ??_GStateTalk@@UEAAPEAXI@Z 0x1417fcd70 ; order
// MS2-PIN: ??_GStateTalkNpc@@UEAAPEAXI@Z 0x1417fcdb0 ; order
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statetalk.cpp"    // assumed
// The exe's memmove_s is a plain call (no /Oi expansion); the pragma must precede the inline copy below.
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include <errno.h>
#include <new>
#include <string.h>
#include <vcruntime_string.h>

#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <efd/utf8string.h>
#include <NiActorManager.h>

#include "statetalk.h"

#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

void FUN_1409989e0(void* pOut, const char* psz);           // 0x1409989e0 efd::utf8string(const char*)
void FUN_1408a8900(void* pStr);                            // 0x1408a8900 ~efd::utf8string
void FUN_140ae18f0(void* pStr, const char* psz);           // 0x140ae18f0 efd::utf8string::operator=(const char*)
bool FUN_14096ad40(const efd::utf8string& str);            // 0x14096ad40 the string is empty
const char* FUN_1408ac310(const efd::utf8string& str);     // 0x1408ac310 the string's c string

// The efd::utf8string the exe builds out of line (ctor 0x1409989e0, dtor 0x1408a8900; 0x20 bytes, as statefall.h's
// StateFall::m_strAnim proves). The engine header inlines both, so the TU uses this plain-buffer view instead.
struct Unk_TalkString
{
    Unk_TalkString(const char* psz) { FUN_1409989e0(m_buf, psz); }
    ~Unk_TalkString() { FUN_1408a8900(m_buf); }
    Unk_TalkString& operator=(const char* psz) { FUN_140ae18f0(m_buf, psz); return *this; }
    operator const efd::utf8string&() const { return *(const efd::utf8string*)m_buf; }
    char m_buf[0x20];
};

// The npc's data record (uinametag.cpp owns the full one; only the "talkable" flag is read here).
struct Unk_TalkNpcData
{
    char m_pad_00[0x8a];
    unsigned char m_bTalkable;                             // +0x8a
};
MS2_CHECK_OFFSET(Unk_TalkNpcData, m_bTalkable, 0x8a);
class Unk_TalkNpcDataPtr
{
public:
    ~Unk_TalkNpcDataPtr() { FUN_1406d5390(); }
    Unk_TalkNpcData* FUN_140965990() const;                // operator->
    void FUN_1406d5390();                                  // release
    void* m_pad_00;
    Unk_TalkNpcData* m_p;
};

// The talk manager and the npc it is talking to (cinematiccomponent.cpp owns the full view).
class Unk_CinNpc;
class Unk_CinTalk
{
public:
    int FUN_141b21220();                                   // a dialogue is open
    void FUN_141b1feb0();                                  // end it
    Unk_CinNpc* FUN_141b21350();                           // the talking npc
};
Unk_CinTalk* FUN_140967100();

class Unk_CinNpc : public PCBase
{
public:
    Unk_TalkNpcDataPtr FUN_141093270();                    // the npc's data record
};

// The animation service: an animation name resolves to the model's sequence id (the config's sentinel without one).
class Unk_TalkAnimSvc
{
public:
    int FUN_140999490(const egf::EntityID& kId, const efd::utf8string& strName);
};
Unk_TalkAnimSvc* FUN_1413f9b10();
unsigned int FUN_1409a1a00(NiActorManager* pActor);        // 0x1409a1a00 the actor's playing sequence id

// The owner's play-actor component (pcbase.cpp owns the full one) and its flag.
class Unk_PCBaseComp_aa8 : public CPtred { };
int FUN_140f48d40(void* pComp);                            // 0x140f48d40 the component's flag
void* FUN_14165f100(PCBase* p);                            // 0x14165f100 the playing emotion
void FUN_14165f170(PCBase* p);                             // 0x14165f170 stop it

extern Vector3 DAT_143b01a60;                      // 0x143b01a60 the zero point

// The effect-spawn request (0x70 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0) and the manager that takes it.
struct Unk_TalkEffectReq
{
    CString m_strName;                                     // +0x00
    int m_nObject;                                         // +0x08
    int m_pad_0c;
    void* m_pSlot10;                                       // +0x10
    char m_pad_18[0x58];
};
MS2_CHECK_SIZE(Unk_TalkEffectReq, 0x70);
MS2_CHECK_OFFSET(Unk_TalkEffectReq, m_nObject, 0x08);
void FUN_140a52ef0(Unk_TalkEffectReq* p);                  // construct
void FUN_1405a89e0(Unk_TalkEffectReq* p);                  // destroy
void FUN_140a53190(Unk_TalkEffectReq* p, int nObject);     // bind the object
class Unk_TalkEffectMgr
{
public:
    int FUN_1411a49c0(Unk_TalkEffectReq* pRequest);        // spawn, returns the handle
    void FUN_1411a6060(int nHandle);                       // release
};
Unk_TalkEffectMgr* FUN_1403ed280();
void* FUN_1401d31f0();                                     // the client configuration object

// ---- StateTalk ----

// @0x1417fc010
StateTalk::StateTalk(PCBase* pOwner) : State(pOwner), m_n40(0x47), m_n44(0)
{
}

// @0x1417fc070
StateTalk::~StateTalk()
{
}

// Enter: look the npc's two talk animations up and pick the phase; with a talkable npc the first anim plays,
// otherwise the idle motion.
// @0x1417fc0a0
void StateTalk::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    Unk_TalkAnimSvc* pAnim = FUN_1413f9b10();
    Unk_CinNpc* pNpc = FUN_140967100()->FUN_141b21350();
    int bFirst = 0;
    int bSecond = 0;
    bool bTalk = false;
    if (pNpc != 0)
    {
        Unk_TalkNpcDataPtr kData = pNpc->FUN_141093270();
        bTalk = kData.FUN_140965990()->m_bTalkable != 0;
    }
    if (FUN_1417b8560())
    {
        {
            egf::EntityID kId;
            Unk_TalkString strFirst(m_pOwner->vfunc_123(0x2d));
            bFirst = pAnim->FUN_140999490(m_pOwner->FUN_14123c460(kId), strFirst) != (int)NiActorManager::INVALID_SEQUENCE_ID;
        }
        {
            egf::EntityID kId;
            Unk_TalkString strSecond(m_pOwner->vfunc_123(0x2e));
            bSecond = pAnim->FUN_140999490(m_pOwner->FUN_14123c460(kId), strSecond) != (int)NiActorManager::INVALID_SEQUENCE_ID;
        }
        MyPC* pPlayer = FUN_1417b84b0();
        if (pPlayer != 0 && FUN_14165f100(pPlayer) != 0)
            FUN_14165f170(pPlayer);
    }
    if (bFirst && bSecond && bTalk)
    {
        m_n10 = 0x47;
        Unk_TalkString strPlay(m_pOwner->vfunc_123(0x2d));
        m_pOwner->FUN_14166dd20(strPlay, 1.0f, true, false);
    }
    else
    {
        m_n10 = 0x49;
        Unk_TalkString strPlay(m_pOwner->vfunc_123(0));
        m_pOwner->FUN_14166dd20(strPlay, 1.0f, false, false);
    }
    m_n40 = m_n10;
}

// Leave: end the open dialogue and release the dialogue effect.
// @0x1417fc460
void StateTalk::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (FUN_140967100()->FUN_141b21220() && FUN_1417b8560())
        FUN_140967100()->FUN_141b1feb0();
    if (m_n44 != 0)
        FUN_1403ed280()->FUN_1411a6060(m_n44);
}

// @0x1417fc4e0
void StateTalk::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Vector3 kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// Update: while a talk anim is not playing, re-play the talking (npc has the 0x2e anim) or the waiting (0x2f) loop;
// a phase change releases the previous dialogue effect and spawns the one the phase asks for.
// @0x1417fc560
void StateTalk::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (FUN_1417b8560() && FUN_1417fca20())
    {
        if (m_pOwner->vfunc_85().get() != 0 && FUN_140f48d40(m_pOwner->vfunc_85().operator->()) != 0)
        {
            Unk_TalkString strAnim(m_pOwner->vfunc_123(0x2e));
            m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
        }
        else
        {
            Unk_TalkString strAnim(m_pOwner->vfunc_123(0x2f));
            m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
        }
    }
    if (m_n40 != m_n10)
    {
        FUN_1403ed280()->FUN_1411a6060(m_n44);
        if (m_n10 == 0x4a)
        {
            Unk_TalkEffectReq kReq;
            FUN_140a52ef0(&kReq);
            kReq.m_strName = *(const CString*)((const char*)FUN_1401d31f0() + 0x290);
            kReq.m_nObject = 0;
            FUN_140a53190(&kReq, m_pOwner->FUN_14123c580());
            m_n44 = FUN_1403ed280()->FUN_1411a49c0(&kReq);
            FUN_1405a89e0(&kReq);
        }
        else if (m_n10 == 0x4b)
        {
            Unk_TalkEffectReq kReq;
            FUN_140a52ef0(&kReq);
            kReq.m_strName = *(const CString*)((const char*)FUN_1401d31f0() + 0x298);
            kReq.m_nObject = 0;
            FUN_140a53190(&kReq, m_pOwner->FUN_14123c580());
            m_n44 = FUN_1403ed280()->FUN_1411a49c0(&kReq);
            FUN_1405a89e0(&kReq);
        }
        m_n40 = m_n10;
    }
}

// @0x1417fc960
void StateTalk::vfunc_6()
{
    if (FUN_140967100()->FUN_141b21220() && FUN_1417b8560())
        FUN_140967100()->FUN_141b1feb0();
}

// @0x1417fc9a0
void StateTalk::vfunc_8(double fTime)
{
}

// The npc's talk animation finished: the actor's sequence id advances the phase from 0x47 to 0x48.
// @0x1417fc9c0
void StateTalk::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID, NiControllerSequence* pkSeq,
                              float fEventTime)
{
    (void)pkSeq;
    (void)fEventTime;
    if (FUN_1417b8560() && FUN_1417b7e40() == 0x47 && eSequenceID == FUN_1409a1a00(pkManager))
        m_n10 = 0x48;
}

// The phase is neither "wait for a talkable npc" (0x47) nor "nothing to talk to" (0x49).
// @0x1417fca20
bool StateTalk::FUN_1417fca20()
{
    return m_n10 != 0x47 && m_n10 != 0x49;
}

// A dialogue branch was chosen: 1 is the first effect, 2-3 the second, anything else just shows the anim.
// @0x1417fca60
void StateTalk::FUN_1417fca60(int n)
{
    switch (n)
    {
    case 1:
        m_n10 = 0x4a;
        break;
    case 2:
    case 3:
        m_n10 = 0x4b;
        break;
    default:
        m_n10 = 0x48;
        break;
    }
}

// ---- StateTalkNpc ----

// @0x1417fcac0
StateTalkNpc::StateTalkNpc(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417fcb00
StateTalkNpc::~StateTalkNpc()
{
}

// Enter: an open dialogue plays the npc's talking animation, otherwise its idle one. A model without the talking
// animation falls back to the idle animation.
// @0x1417fcb30
void StateTalkNpc::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    if (FUN_140967100()->FUN_141b21220())
    {
        m_n10 = 0x48;
        Unk_TalkString strAnim(m_pOwner->vfunc_123(0x2e));
        if (FUN_14096ad40(strAnim) || !m_pOwner->FUN_141679220(FUN_1408ac310(strAnim)))
            strAnim = m_pOwner->vfunc_123(0);
        m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
    }
    else
    {
        m_n10 = 0x49;
        Unk_TalkString strAnim(m_pOwner->vfunc_123(0));
        m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
    }
}

// @0x1417fccf0
void StateTalkNpc::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Vector3 kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x1417fcdf0
int StateTalk::vfunc_1()
{
    return 0x16;
}

// @0x1417fce00
int StateTalkNpc::vfunc_1()
{
    return 0x16;
}

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy).
// @0x1417fce10
MS2_EMIT_CRT_MEMMOVE_S();
