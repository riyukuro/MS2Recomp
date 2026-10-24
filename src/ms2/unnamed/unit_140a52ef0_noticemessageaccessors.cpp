// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NoticeMessage (placeholder/effectquery.h): the effect
// request's ctor and accessors, plus its DynamicCast and callback-handle COMDATs.
// MS2-UNIT: unit_140a52ef0
// MS2-RANGE: 0x140a52ef0-0x140a53740 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include <efd/IBase.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

int FUN_141658e60(PC* pPC);                                 // 0x141658e60 (also read by itemgem / scenestategame)
int FUN_140976780(GameObject* pObject);                     // 0x140976780 the object's code (+0x118)
GameObject* FUN_141bd1180(WorldService* pWorld, int nId);   // 0x141bd1180 the game object of an actor id
NiAVObject* FUN_141b6ef70(egf::EntityID id);                // 0x141b6ef70 the scene node of an entity
double FUN_141473280(CMainSystem* pSystem);                 // 0x141473280 the current time

// @0x140a52ef0
NoticeMessage::NoticeMessage()
    : m_nObject(9), m_spNode(0), m_p18(0), m_p20(0), m_p28(0), m_bFlag30(false), m_bFlag31(false), m_bFlag32(false),
      m_bFlag33(false), m_bFlag34(true), m_n38(0), m_nMode48(6), m_n4c(0), m_nObjectCode(0), m_nActor(0), m_pOwner(0),
      m_nLookupId(0), m_dTimestamp(0)
{
}

// @0x140a53010
int NoticeMessage::FUN_140a53010()
{
    PC* pPC = efd::DynamicCast<PC>(m_pOwner);
    if (pPC)
        return FUN_141658e60(pPC);
    return 2;
}
MS2_REPLACE_METHOD(0x140A53010, NoticeMessage, FUN_140a53010, 58, 0xA2303F78);

// @0x140a53050
int NoticeMessage::FUN_140a53050()
{
    PC* pPC = efd::DynamicCast<PC>(m_pOwner);
    if (pPC)
        return pPC->FUN_141654700();
    return 2;
}
MS2_REPLACE_METHOD(0x140A53050, NoticeMessage, FUN_140a53050, 58, 0xA668C7D0);

// @0x140a53090
int NoticeMessage::GetObjectCode()
{
    if (m_pOwner)
        return FUN_140976780(m_pOwner);
    return m_nObjectCode;
}
MS2_REPLACE_METHOD(0x140A53090, NoticeMessage, GetObjectCode, 50, 0x7ED2125A);

// @0x140a530d0
bool NoticeMessage::IsMyPC()
{
    return efd::DynamicCast<MyPC>(m_pOwner) ? 1 : 0;
}
MS2_REPLACE_METHOD(0x140A530D0, NoticeMessage, IsMyPC, 56, 0x3C4C2ED3);

// @0x140a53110
bool NoticeMessage::CanShow()
{
    if (m_bFlag31)
        return false;
    GameObject* pObject = ResolveOwner();
    if (pObject && pObject->vfunc_25())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140A53110, NoticeMessage, CanShow, 83, 0xE0C28375);

// @0x140a53170
void NoticeMessage::SetObjectCode(int nCode)
{
    m_nObjectCode = nCode;
}
MS2_REPLACE_METHOD(0x140A53170, NoticeMessage, SetObjectCode, 22, 0x55CC0123);

// @0x140a53190
void NoticeMessage::SetActor(int nActor)
{
    m_nActor = nActor;
}
MS2_REPLACE_METHOD(0x140A53190, NoticeMessage, SetActor, 22, 0x3DC2E0FF);

// @0x140a531b0
void NoticeMessage::SetLookupId(int nId)
{
    m_nLookupId = nId;
}
MS2_REPLACE_METHOD(0x140A531B0, NoticeMessage, SetLookupId, 22, 0xF643BE53);

// @0x140a531d0
void NoticeMessage::SetValue38(unsigned __int64 nValue)
{
    m_n38 = nValue;
}
MS2_REPLACE_METHOD(0x140A531D0, NoticeMessage, SetValue38, 25, 0x6BD9AB1B);

// @0x140a531f0
void NoticeMessage::SetCallback(Unk_NoticeCallbackPtr callback)
{
    m_callback = callback;
}

// @0x140a53240
void NoticeMessage::SetMode48(int nMode)
{
    m_nMode48 = nMode;
}
MS2_REPLACE_METHOD(0x140A53240, NoticeMessage, SetMode48, 22, 0x6608447B);

// @0x140a53260
void NoticeMessage::CopyFrom(const NoticeMessage& other)
{
    m_strName = other.m_strName;
    m_nObject = other.m_nObject;
    m_nActor = other.m_nActor;
    m_spNode = other.m_spNode;
    m_bFlag30 = other.m_bFlag30;
    m_bFlag31 = other.m_bFlag31;
    m_bFlag32 = other.m_bFlag32;
    m_bFlag33 = other.m_bFlag33;
    m_bFlag34 = other.m_bFlag34;
    m_nObjectCode = other.m_nObjectCode;
    m_nLookupId = other.m_nLookupId;
    m_dTimestamp = other.m_dTimestamp;
    m_n38 = other.m_n38;
    m_callback = other.m_callback;
    m_nMode48 = other.m_nMode48;
}
MS2_REPLACE_METHOD(0x140A53260, NoticeMessage, CopyFrom, 293, 0xAF95D93F);

// @0x140a53390
int NoticeMessage::GetActor()
{
    return m_nActor;
}
MS2_REPLACE_METHOD(0x140A53390, NoticeMessage, GetActor, 14, 0x5A3CA153);

// @0x140a533b0
GameObject* NoticeMessage::GetOwner()
{
    return m_pOwner;
}
MS2_REPLACE_METHOD(0x140A533B0, NoticeMessage, GetOwner, 15, 0xBB12B609);

// @0x140a533d0
NiNode* NoticeMessage::GetRoot()
{
    AvatarPC* pAvatar = efd::DynamicCast<AvatarPC>(m_pOwner);
    if (pAvatar)
        return pAvatar->FUN_1409f62c0();
    return CEffectService::GetInstance()->FUN_1411a6b10();
}
MS2_REPLACE_METHOD(0x140A533D0, NoticeMessage, GetRoot, 66, 0x2B7E420C);

// @0x140a53420
double NoticeMessage::GetTimestamp()
{
    return m_dTimestamp;
}
MS2_REPLACE_METHOD(0x140A53420, NoticeMessage, GetTimestamp, 16, 0x3DAD5E2F);

// @0x140a53440
unsigned __int64 NoticeMessage::GetValue38()
{
    return m_n38;
}
MS2_REPLACE_METHOD(0x140A53440, NoticeMessage, GetValue38, 15, 0x7BFFD3E9);

// @0x140a53460
Unk_NoticeCallbackPtr& NoticeMessage::GetCallback()
{
    return m_callback;
}
MS2_REPLACE_METHOD(0x140A53460, NoticeMessage, GetCallback, 15, 0x177FAFB9);

// @0x140a53480
int NoticeMessage::GetMode48()
{
    return m_nMode48;
}
MS2_REPLACE_METHOD(0x140A53480, NoticeMessage, GetMode48, 14, 0x921EE467);

// @0x140a534a0
void NoticeMessage::Bind()
{
    if (m_pOwner == 0 && m_nActor != 0)
        m_pOwner = FUN_141bd1180(WorldService::GetInstance(), m_nActor);
    if (m_spNode == 0 && m_pOwner != 0)
        m_spNode = FUN_141b6ef70(m_pOwner->FUN_14123c460());
}
MS2_REPLACE_METHOD(0x140A534A0, NoticeMessage, Bind, 159, 0x9C92423F);

// @0x140a53550
void NoticeMessage::Stamp()
{
    m_dTimestamp = FUN_141473280(CMainSystem::GetInstance());
}
MS2_REPLACE_METHOD(0x140A53550, NoticeMessage, Stamp, 37, 0x77A3EC3C);

// @0x140a53580
GameObject* NoticeMessage::ResolveOwner()
{
    if (m_nLookupId)
        return FUN_141bd1180(WorldService::GetInstance(), m_nLookupId);
    return m_pOwner;
}
MS2_REPLACE_METHOD(0x140A53580, NoticeMessage, ResolveOwner, 57, 0x380DA0FA);
