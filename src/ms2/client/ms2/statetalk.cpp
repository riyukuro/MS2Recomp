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
#include <efd/Point3.h>

#include <errno.h>
#include <new>
#include <string.h>
#include <vcruntime_string.h>

#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <efd/utf8string.h>
#include <NiActorManager.h>
#include <egmAnimation/AnimationService.h>

#include "statetalk.h"

#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/uihudentity.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The npc's data record (uinametag.cpp owns the full one; only the "talkable" flag is read here).
struct Unk_TalkNpcData
{
    char m_pad_00[0x8a];
    unsigned char m_bTalkable;                             // +0x8a
};
MS2_CHECK_OFFSET(Unk_TalkNpcData, m_bTalkable, 0x8a);

// The talk manager and the npc it is talking to (cinematiccomponent.cpp owns the full view).
class Unk_CinNpc;
class Unk_CinTalk : public UITalkManager
{
public:
};

class NpcDataCli : public CPtred { };   // C3: view of the real class (the npc table row)
class CNpc { public: MS2Ptr<NpcDataCli> GetNpcData(); };   // C3: view of the real class
class Unk_CinNpc : public PCBase
{
public:
};

// The animation service: an animation name resolves to the model's sequence id (the config's sentinel without one).
// The owner's model key (returned by value: no ctor, the exe leaves the slot unset before the call).
typedef egf::EntityID Unk_TalkModelKey;
class Unk_TalkAnimSvc
{
public:
    // C3: the name lookup is the real egmAnimation::AnimationService::GetAnimationIdFromName (0x140999490)
};
void* FUN_1413f9b10();   // C3: was FUN_1413f9b10
// The owner's play-actor component (pcbase.cpp owns the full one) and its flag.
class Unk_PCBaseComp_aa8 : public CPtred { };

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource

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
    Unk_TalkAnimSvc* pAnim = ((class Unk_TalkAnimSvc*)FUN_1413f9b10());
    Unk_CinNpc* pNpc = (Unk_CinNpc*)((class Unk_CinTalk*)TSingleton<UITalkManager>::GetInstance())->GetTalkNpc();
    int bFirst = 0;
    int bSecond = 0;
    bool bTalk = pNpc != 0 && reinterpret_cast<Unk_TalkNpcData*>(reinterpret_cast<CNpc*>(pNpc)->GetNpcData().operator->())->m_bTalkable != 0;
    if (FUN_1417b8560())
    {
        {
            efd::utf8string strFirst(m_pOwner->vfunc_123(0x2d));
            bFirst = reinterpret_cast<egmAnimation::AnimationService*>(pAnim)->GetAnimationIdFromName(reinterpret_cast<GameObject*>(m_pOwner)->GetEntityID(), reinterpret_cast<const efd::utf8string&>(strFirst))
                != (int)NiActorManager::INVALID_SEQUENCE_ID;
        }
        {
            efd::utf8string strSecond(m_pOwner->vfunc_123(0x2e));
            bSecond = reinterpret_cast<egmAnimation::AnimationService*>(pAnim)->GetAnimationIdFromName(reinterpret_cast<GameObject*>(m_pOwner)->GetEntityID(), reinterpret_cast<const efd::utf8string&>(strSecond))
                != (int)NiActorManager::INVALID_SEQUENCE_ID;
        }
        MyPC* pPlayer = FUN_1417b84b0();
        if (pPlayer != 0 && ((void*)(reinterpret_cast<PC*>(pPlayer)->GetHeldItem())) != 0)
            reinterpret_cast<PC*>(pPlayer)->SendRequestCube();
    }
    if (bFirst && bSecond && bTalk)
    {
        m_n10 = 0x47;
        efd::utf8string strPlay(m_pOwner->vfunc_123(0x2d));
        reinterpret_cast<PCBase*>(m_pOwner)->PlayAnimation(reinterpret_cast<const efd::utf8string&>(strPlay), 1.0f, true, false);
    }
    else
    {
        m_n10 = 0x49;
        efd::utf8string strPlay(m_pOwner->vfunc_123(0));
        reinterpret_cast<PCBase*>(m_pOwner)->PlayAnimation(reinterpret_cast<const efd::utf8string&>(strPlay), 1.0f, false, false);
    }
    m_n40 = m_n10;
}

// Leave: end the open dialogue and release the dialogue effect.
// @0x1417fc460
void StateTalk::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (((class Unk_CinTalk*)TSingleton<UITalkManager>::GetInstance())->GetTalking() && FUN_1417b8560())
        ((class Unk_CinTalk*)TSingleton<UITalkManager>::GetInstance())->SendNpcTalkMode0();
    if (m_n44 != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_n44);
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
        if ((m_pOwner->vfunc_85().get() ? true : false) && reinterpret_cast<UIHudEntity::Entity*>(m_pOwner->vfunc_85().operator->())->FUN_140f48d40() != 0)
        {
            efd::utf8string strAnim(m_pOwner->vfunc_123(0x2e));
            m_pOwner->PlayAnimation(*(const efd::utf8string*)&strAnim, 1.0f, false, false);
        }
        else
        {
            efd::utf8string strAnim(m_pOwner->vfunc_123(0x2f));
            m_pOwner->PlayAnimation(*(const efd::utf8string*)&strAnim, 1.0f, false, false);
        }
    }
    if (m_n40 != m_n10)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_n44);
        if (m_n10 == 0x4a)
        {
            NoticeMessage kReq;
            kReq.m_strName = *(const CString*)((const char*)((void*)GetCommonResource()) + 0x290);
            kReq.m_nObject = 0;
            kReq.SetActor(m_pOwner->GetObjectId());
            m_n44 = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&kReq));
        }
        else if (m_n10 == 0x4b)
        {
            NoticeMessage kReq;
            kReq.m_strName = *(const CString*)((const char*)((void*)GetCommonResource()) + 0x298);
            kReq.m_nObject = 0;
            kReq.SetActor(m_pOwner->GetObjectId());
            m_n44 = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&kReq));
        }
        m_n40 = m_n10;
    }
}

// @0x1417fc960
void StateTalk::vfunc_6()
{
    if (((class Unk_CinTalk*)TSingleton<UITalkManager>::GetInstance())->GetTalking() && FUN_1417b8560())
        ((class Unk_CinTalk*)TSingleton<UITalkManager>::GetInstance())->SendNpcTalkMode0();
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
    if (FUN_1417b8560() && GetStateId() == 0x47 && eSequenceID == static_cast<NiActorManager*>(pkManager)->GetTargetAnimation())
        m_n10 = 0x48;
}

// The phase is neither "wait for a talkable npc" (0x47) nor "nothing to talk to" (0x49).
// @0x1417fca20
int StateTalk::FUN_1417fca20()
{
    return m_n10 != 0x47 && m_n10 != 0x49;
}

// A dialogue branch was chosen: 1 is the first effect, 2-3 the second, anything else just shows the anim.
// @0x1417fca60
void StateTalk::SelectDialogueBranch(int n)
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
    if (((class Unk_CinTalk*)TSingleton<UITalkManager>::GetInstance())->GetTalking())
    {
        m_n10 = 0x48;
        efd::utf8string strAnim(m_pOwner->vfunc_123(0x2e));
        if (((efd::utf8string*)&static_cast<class efd::utf8string const&>(*(const efd::utf8string*)&strAnim))->empty() || !m_pOwner->HasAnimSequence(((efd::utf8string*)&static_cast<class efd::utf8string const&>(*(const efd::utf8string*)&strAnim))->c_str()))
            strAnim = m_pOwner->vfunc_123(0);
        m_pOwner->PlayAnimation(*(const efd::utf8string*)&strAnim, 1.0f, false, false);
    }
    else
    {
        m_n10 = 0x49;
        efd::utf8string strAnim(m_pOwner->vfunc_123(0));
        m_pOwner->PlayAnimation(*(const efd::utf8string*)&strAnim, 1.0f, false, false);
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
