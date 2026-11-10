// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Emoticon bubbles over actors (world-anchored, UIHudEntity family).
// MS2-UNIT: ?\uiemoticon.cpp
// MS2-RANGE: 0x14192e8f0-0x141930710 .text$mn
// MS2-RANGE: 0x140113000-0x140113280 .text$di
// MS2-RANGE: 0x142cbde60-0x142cbdf40 .text$yd
// MS2-PIN: ??_7Entity@UIEmoticon@@6BTimerEntity@UIHudEntity@@@ 0x142fa3268
// MS2-PIN: ??__Fs_npcMovieNames@@YAXXZ 0x142cbde60
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142cbdef0
// MS2-PIN: ?vfunc_48@UIEmoticon@@UEAAHXZ 0x1419305b0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiemoticon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "uiemoticon.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The unit's statics: the npc id -> movie name table, then the shared header statics, then one more sort name table.
static ATL::CAtlMap<unsigned int, CString, ATL::CElementTraits<unsigned int>, ATL::CElementTraits<CString> > s_npcMovieNames(17, 0.75f, 0.25f, 2.25f, 10);
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC (efd::DynamicCast<PC, PCBase>)
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// Unit-local declarations; the unidentified names describe uses rather than original class names.
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980
// C3: the float getter 0x140298f40 is Common::Constants::Value<float>::Get() (clientconstants.h)
class Unk_EmoCfgFloat { public: void* m_unknown; };
struct Unk_EmoCfg
{
    char m_pad_0000[0x218];
    Unk_EmoCfgFloat m_218;
    char m_pad_0220[0x638 - 0x218 - sizeof(Unk_EmoCfgFloat)];
    Unk_EmoCfgFloat m_638;
    char m_pad_0640[0x2600 - 0x638 - sizeof(Unk_EmoCfgFloat)];
    Unk_EmoCfgFloat m_2600;
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
class Unk_EmoPlayer : public CNpc                                                         // the player-side object of an actor (quest/status)
{
};
class CFameTable { public: int IsOfficerNpc(int nKind); CString GetSymbolByOfficerNpc(int nKind); };   // famegradedata.h's fame table
class Unk_EmoNpcTable* GetFameTable();
CString SelectStringByQuestId(int nQuestId, const CString& a, const CString& b, const CString& c, const CString& d);
UIQuestEventDispatcher* FUN_140bfc4b0();
class Unk_EmoUIScale;
class Unk_AltStringMgr* GetGFxManager();   // C3: was GetGFxManager
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    float GetMovieScale(int);
};
float FUN_1412762d0(const NiPoint3& pt);
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1422b9ea0();
    int GetSubSceneId();
};
bool FUN_140930110(int nActorId);
class Unk_EmoClip : public ASGameEntity { };   // C3: FUN_1422bb870 (AScript) and FUN_1422c00f0 (ASDisplayObject) are inherited
class Unk_BannerClip   // C3: unit-local view (defs in uibanner); the entity clip's create / update calls
{
public:
    Scaleform::GFx::Value CreateEntity(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value UpdateEntity(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
};
// ASUIComponent::vfunc_24(bool) (validateNow) is slot 24 of the clip's vftable; ASGameEntity declares only 6 slots.
class Unk_EmoClipSlots
{
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void vfunc_24(bool b);                                          // MS2: slot 24
};
class Unk_EmoPopupMgr { public: };
UIEmoticon* GetEmoticon(int nUiId);
unsigned int GetNpcId(Unk_EmoPlayer* pPlayer);

int InitNpcMovieNames();
#ifndef MS2_HOOK_DLL
// @0x14192e8f0
int InitNpcMovieNames()
{
    if (s_npcMovieNames.IsEmpty())
    {
        s_npcMovieNames.SetAt(2, "emoticon_movie_npc_warehouse");
        s_npcMovieNames.SetAt(3, "emoticon_movie_npc_mail");
        s_npcMovieNames.SetAt(0xb, "emoticon_movie_npc_equip");
        s_npcMovieNames.SetAt(0xc, "emoticon_movie_npc_equip");
        s_npcMovieNames.SetAt(0xd, "emoticon_movie_npc_shopetc");
        s_npcMovieNames.SetAt(0xe, "emoticon_movie_npc_ugc");
        s_npcMovieNames.SetAt(0xf, "emoticon_movie_npc_shopetc");
        s_npcMovieNames.SetAt(0x51, "emoticon_movie_npc_doctor");
        s_npcMovieNames.SetAt(0x52, "emoticon_movie_npc_trans");
        s_npcMovieNames.SetAt(0x53, "emoticon_movie_npc_container");
        s_npcMovieNames.SetAt(0x54, "emoticon_movie_npc_landagent");
        s_npcMovieNames.SetAt(0x50, "emoticon_movie_npc_headhunter");
        s_npcMovieNames.SetAt(500, "");
    }
    return 1;
}
#endif

CString GetNpcMovieName(unsigned int nNpcId);
#ifndef MS2_HOOK_DLL
// @0x14192ebf0
CString GetNpcMovieName(unsigned int nNpcId)
{
    CString strName;
    if (s_npcMovieNames.Lookup(nNpcId, strName))
        return strName;
    if (((class CFameTable*)GetFameTable())->IsOfficerNpc(nNpcId) != 0)
        return Unk_SocketFormat("emoticon_movie_npc_{0}", ((class CFameTable*)GetFameTable())->GetSymbolByOfficerNpc(nNpcId));
    return CString("");
}
#endif

// @0x14192ed20
CString GetQuestMovieName(unsigned int nQuestId, int nKind)
{
    CString strName;
    switch (nKind)
    {
    case 0:
        strName = "emoticon_movie_quest_start";
        break;
    case 2:
        strName = "emoticon_movie_quest_complete";
        break;
    case 1:
        return CString("emoticon_movie_quest_progress");
    }
    if (strName.GetLength() != 0)
    {
        strName += SelectStringByQuestId(nQuestId, "_epic", "", "_repeat", "_event");
        return strName;
    }
    return CString("");
}

// @0x14192ef40
UIEmoticon::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : TimerEntity(nLayer, clip, nActorId), m_b0(4), m_b8("")
{
    m_64 = 99999999;
    float fDefault = 400.0f;
    m_c0 = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_EmoCfg*)GetClientConstants())->m_218)->Get(fDefault);
    m_54 = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_EmoCfg*)GetClientConstants())->m_2600)->Read();
    FUN_140bfc4b0()->AddListener(static_cast<UIQuestEventListener*>(this));
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_14192f910();
}

// @0x14192f0f0
UIEmoticon::Entity::~Entity()
{
    FUN_140bfc4b0()->RemoveListener(static_cast<UIQuestEventListener*>(this));
    TSingleton<UIStatusEventDispatcher>::GetInstance()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
}

// @0x14192f200
void UIEmoticon::Entity::vfunc_2()
{
    TimerEntity::vfunc_2();
}

// @0x14192f220
void UIEmoticon::Entity::vfunc_3()
{
    TimerEntity::vfunc_3();
    vfunc_7();
}

// @0x14192f250
void UIEmoticon::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_b0 = 4;
    m_b8 = "";
}

// @0x14192f2a0
void UIEmoticon::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    if (m_38.get())
    {
        m_38->Invoke("open", FUN_14192fa50());
        ((Unk_EmoClipSlots*)(void*)m_38.operator->())->vfunc_24(true);
    }
    if (m_b0 == 2)
        m_b8.Empty();
}

// @0x14192f3a0
void UIEmoticon::Entity::vfunc_6(NiPoint3* pPos)
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return;
    if (m_38.get())
    {
        *pPos *= ((class GFxManager*)(class Unk_EmoUIScale*)(((class Unk_EmoUIScale*)GetGFxManager())))->GetMovieScale(m_18);
        if (reinterpret_cast<Unk_EmoPlayer*>(efd::DynamicCast<CNpc, PCBase>(pActor)) != 0)
        {
            pPos->y = pPos->y + *reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_EmoCfg*)GetClientConstants())->m_638)->Get();
        }
        else
        {
            if (efd::DynamicCast<PC, PCBase>(pActor) != 0)
                pPos->y = pPos->y + ((class PCBase*)(class PCBase*)(pActor))->FUN_141670500();
        }
        switch (m_b0)
        {
        case 3:
            pPos->y = pPos->y + -90.0f;
            break;
        case 2:
            pPos->y = pPos->y + 30.0f;
            break;
        }
        pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
        ((Unk_EmoClip*)m_38.operator->())->SetPositionFloat(pPos->x, pPos->y);
    }
}

// @0x14192f540
void UIEmoticon::Entity::vfunc_7()
{
    if (m_38.get())
        m_38->vfunc_3(0);
}

// @0x14192f5a0
int UIEmoticon::Entity::vfunc_8(int n)
{
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 1;
    bool bKind3 = (m_b0 == 3) ? true : false;
    MS2Ptr<Unk_PCBaseComp_aa8> sp = pActor->vfunc_85();
    if ((bool)sp.get() && ((UIHudEntity::Entity*)(void*)sp.operator->())->FUN_140f48d40() != 0 && FUN_1419305c0() == 0 && !bKind3)
        return 1;
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->FUN_1422b9ea0() != 0 || ((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->GetSubSceneId() == 0x6200031)
    {
        if (m_b0 != 2)
            return 1;
    }
    else
    {
        if (m_b0 == 2)
        {
            FUN_14192f8b0(4);
            FUN_14192f910();
            return 1;
        }
    }
    return TimerEntity::vfunc_8(n);
}

// @0x14192f740
void UIEmoticon::Entity::vfunc_oa0_9(unsigned short a1)
{
    FUN_14192fbd0();
}

// @0x14192f770
void UIEmoticon::Entity::vfunc_oa0_7(int a1, CStringW s)
{
    FUN_14192fbd0();
}

// @0x14192f7c0
void UIEmoticon::Entity::vfunc_o178_1(void*)
{
    FUN_14192fbd0();
}

// @0x14192f7f0
void UIEmoticon::Entity::vfunc_o178_3(void*)
{
    FUN_14192fbd0();
}

// @0x14192f820
void UIEmoticon::Entity::vfunc_o178_2(void*)
{
    FUN_14192fbd0();
}

// @0x14192f850
void UIEmoticon::Entity::vfunc_o178_7(int, int)
{
    FUN_14192fbd0();
}

// @0x14192f880
void UIEmoticon::Entity::vfunc_o178_5(void*)
{
    FUN_14192fbd0();
}

// @0x14192f8b0
void UIEmoticon::Entity::FUN_14192f8b0(int nState)
{
    m_b0 = nState;
}

// @0x14192f8d0
void UIEmoticon::Entity::FUN_14192f8d0(const CString& str)
{
    m_b8 = str;
}

// @0x14192f910
void UIEmoticon::Entity::FUN_14192f910()
{
    Unk_EmoPlayer* pPlayer = reinterpret_cast<Unk_EmoPlayer*>(efd::DynamicCast<CNpc, PCBase>(FUN_140f49330()));
    if (pPlayer != 0)
    {
        int nType = pPlayer->GetQuestState();
        if (nType != 4)
        {
            FUN_14192f8b0(1);
            vfunc_2();
        }
        else
        {
            FUN_14192f8b0(0);
            CString strMovie = FUN_14192fa50();
            if (strMovie.GetLength() != 0)
            {
                vfunc_2();
            }
            else
            {
                FUN_14192f8b0(4);
                vfunc_3();
            }
        }
    }
}

// @0x14192f9f0
void UIEmoticon::Entity::FUN_14192f9f0(int n)
{
    if (m_b0 == 2 && n != 1)
    {
        m_b0 = 4;
        m_b8.Empty();
        FUN_14192f910();
    }
}

// @0x14192fa50
CString UIEmoticon::Entity::FUN_14192fa50()
{
    if (m_b0 == 1)
    {
        Unk_EmoPlayer* pPlayer = reinterpret_cast<Unk_EmoPlayer*>(efd::DynamicCast<CNpc, PCBase>(FUN_140f49330()));
        if (pPlayer != 0)
            return GetQuestMovieName(pPlayer->GetQuestId(), pPlayer->GetQuestState());
    }
    if (!m_b8.IsEmpty())
        return m_b8;
    if (m_b0 == 0)
    {
        Unk_EmoPlayer* pPlayer = reinterpret_cast<Unk_EmoPlayer*>(efd::DynamicCast<CNpc, PCBase>(FUN_140f49330()));
        if (pPlayer != 0)
        {
            CString strName = GetNpcMovieName(GetNpcId(pPlayer));
            return strName;
        }
    }
    return CString("");
}

// @0x14192fbd0
void UIEmoticon::Entity::FUN_14192fbd0()
{
    Unk_EmoPlayer* pPlayer = reinterpret_cast<Unk_EmoPlayer*>(efd::DynamicCast<CNpc, PCBase>(FUN_140f49330()));
    if (pPlayer != 0)
        pPlayer->FUN_141093e90();
}

// @0x14192fc10
UIEmoticon::UIEmoticon()
{
    m_70 = "emoticon_entity_body";
    InitNpcMovieNames();
}

// @0x14192fc80
UIEmoticon::~UIEmoticon()
{
}

// @0x14192fcc0
CString UIEmoticon::GetTypeName()
{
    return CString("Emoticon");
}

// @0x14192fd10
void UIEmoticon::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    CreateEntityCache(m_68);
}

// @0x14192fd40
MS2Ptr<UIEmoticon::Entity> GetEmoticonEntity(int nActorId)
{
    UIEmoticon* pUi = GetEmoticon(0x4e2f);
    if (pUi != 0)
        return MS2Ptr<UIEmoticon::Entity>(pUi->GetOrCreateEntity(nActorId));
    return MS2Ptr<UIEmoticon::Entity>(0);
}

// @0x14192fdc0
void RemoveEmoticonEntity(int nActorId)
{
    UIEmoticon* pUi = GetEmoticon(0x4e2f);
    if (pUi)
        pUi->ReleaseEntity(nActorId);
}

// @0x14192fe00
unsigned int GetNpcId(Unk_EmoPlayer* pPlayer)
{
    unsigned int nNpcId = pPlayer->FUN_1410937b0();
    return nNpcId;
}

// @0x14192fe20
void UIEmoticon::CreateEntityCache(unsigned int nCount)
{
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        for (unsigned int i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value v = pClip->Invoke("createCache", m_70);
            if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() == 0)
            {
                Entity* p = new Entity(m_28, v, 0);
                if (p)
                {
                    MS2Ptr<UIHudEntity::Entity> sp(p);
                    m_78.AddTail(sp);
                }
            }
        }
    }
}

// @0x141930000
UIEmoticon::Entity* UIEmoticon::GetOrCreateEntity(int nActorId)
{
    if (IsActorGone(nActorId) != 0)
        return 0;
    {
        ReleaseEntity(nActorId);
        MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pClip.get())
        {
            if (m_78.IsEmpty())
            {
                bool bFlag = FUN_140930110(nActorId);
                bFlag = false;
                Scaleform::GFx::Value v = ((Unk_BannerClip*)pClip.operator->())->CreateEntity("createEntity", nActorId, m_70, bFlag);
                if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() == 0)
                {
                    Entity* p = new Entity(m_28, v, nActorId);
                    if (p)
                    {
                        {
                            MS2Ptr<UIHudEntity::Entity> sp(p);
                            m_a8.SetAt(nActorId, sp);
                        }
                        return p;
                    }
                }
            }
            else
            {
                MS2Ptr<UIHudEntity::Entity> pEntity = m_78.RemoveHead();
                if (pEntity.get())
                {
                    int nOld = pEntity->FUN_140f48d20();
                    if (nActorId != nOld)
                    {
                        bool bNew = FUN_140930110(nActorId);
                        if (FUN_140930110(nOld) || bNew)
                        {
                            MS2Ptr<ASGameEntity> pOldClip = pEntity->FUN_140f48ed0();
                            if (pOldClip.get())
                                ((Unk_BannerClip*)pClip.operator->())->UpdateEntity("updateEntity", ((Unk_EmoClip*)pOldClip.operator->())->GetValue(), bNew);
                        }
                    }
                    pEntity->FUN_140f48ce0(nActorId);
                    m_a8.SetAt(nActorId, pEntity);
                    return (Entity*)pEntity.get();
                }
            }
        }
    }
    return 0;
}

// @0x141930440
UIEmoticon* GetEmoticon(int nUiId)
{
    if (reinterpret_cast<Unk_EmoPopupMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (p.get())
            return dynamic_cast<UIEmoticon*>((UIObject*)p);
    }
    return 0;
}

// @0x1419305c0
int UIEmoticon::Entity::FUN_1419305c0()
{
    return m_b0 == 1;
}

// @0x1419305f0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// Hooks. Not hooked: the ctors/dtors, InitNpcMovieNames/GetNpcMovieName (read the unit's mutable name table, which the exe fills),
// everything that reaches GetNpcMovieName (vfunc_5, vfunc_8, FUN_14192f910/f9f0/fa50), and everything that constructs an
// Entity (OnLoadComplete, CreateEntityCache, GetOrCreateEntity, GetEmoticonEntity: the DLL would build it with its own vftables) or
// dynamic_casts to UIEmoticon (GetEmoticon, RemoveEmoticonEntity). GetQuestMovieName returns a CString by value (free-function thunk).
MS2_REPLACE_METHOD(0x14192F200, UIEmoticon::Entity, vfunc_2, 24, 0xADD81F8D);
MS2_REPLACE_METHOD(0x14192F220, UIEmoticon::Entity, vfunc_3, 40, 0xFD9E64B7);
MS2_REPLACE_METHOD(0x14192F250, UIEmoticon::Entity, vfunc_4, 66, 0xD138675A);
MS2_REPLACE_METHOD(0x14192F3A0, UIEmoticon::Entity, vfunc_6, 408, 0xCAA1D1D5);
MS2_REPLACE_METHOD(0x14192F540, UIEmoticon::Entity, vfunc_7, 76, 0xC3C930F8);
MS2_REPLACE_METHOD_VIA(0x14192F740, UIEmoticon::Entity, UIStatusEventListener, vfunc_oa0_9, 38, 0x4CC196F0);
MS2_REPLACE_METHOD_VIA(0x14192F770, UIEmoticon::Entity, UIStatusEventListener, vfunc_oa0_7, 63, 0x9A6840F2);
MS2_REPLACE_METHOD_VIA(0x14192F7C0, UIEmoticon::Entity, UIQuestEventListener, vfunc_o178_1, 38, 0x82FEFDB1);
MS2_REPLACE_METHOD_VIA(0x14192F7F0, UIEmoticon::Entity, UIQuestEventListener, vfunc_o178_3, 38, 0xD08C6BA1);
MS2_REPLACE_METHOD_VIA(0x14192F820, UIEmoticon::Entity, UIQuestEventListener, vfunc_o178_2, 38, 0xB81DC211);
MS2_REPLACE_METHOD_VIA(0x14192F850, UIEmoticon::Entity, UIQuestEventListener, vfunc_o178_7, 42, 0x8E04164E);
MS2_REPLACE_METHOD_VIA(0x14192F880, UIEmoticon::Entity, UIQuestEventListener, vfunc_o178_5, 38, 0x3292F671);
MS2_REPLACE_METHOD(0x14192F8B0, UIEmoticon::Entity, FUN_14192f8b0, 25, 0x343F531F);
MS2_REPLACE_METHOD(0x14192F8D0, UIEmoticon::Entity, FUN_14192f8d0, 44, 0xEF7CAE5C);
MS2_REPLACE_METHOD(0x14192FBD0, UIEmoticon::Entity, FUN_14192fbd0, 55, 0xB872E151);
MS2_REPLACE_METHOD(0x14192FCC0, UIEmoticon, GetTypeName, 61, 0x7392FE94);
MS2_REPLACE(0x14192FE00, GetNpcId, 32, 0x18CD16A5);
MS2_REPLACE_METHOD(0x1419305C0, UIEmoticon::Entity, FUN_1419305c0, 47, 0x1858A2DC);
