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
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// Unit-local declarations; the unidentified names describe uses rather than original class names.
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980
class Unk_EmoCfgFloat { public: float* FUN_140967520(const float* pDefault); float* FUN_140298f40(); float FUN_1402bac70(); void* m_unknown; };
struct Unk_EmoCfg
{
    char m_pad_0000[0x218];
    Unk_EmoCfgFloat m_218;
    char m_pad_0220[0x638 - 0x218 - sizeof(Unk_EmoCfgFloat)];
    Unk_EmoCfgFloat m_638;
    char m_pad_0640[0x2600 - 0x638 - sizeof(Unk_EmoCfgFloat)];
    Unk_EmoCfgFloat m_2600;
};
Unk_EmoCfg* FUN_1401d3200();
class Unk_EmoPlayer                                                         // the player-side object of an actor (quest/status)
{
public:
    int FUN_141093c60();                                                    // kind: 4 = npc movie
    unsigned int FUN_141093c20();                                           // quest id
    void FUN_141093e90();
    unsigned int FUN_1410937b0();                                           // npc id
};
Unk_EmoPlayer* FUN_14096e110(PCBase* pActor);
class Unk_EmoNpcTable { public: int FUN_14035b0a0(unsigned int nId); CString FUN_14035b2a0(unsigned int nId); };
Unk_EmoNpcTable* FUN_140764010();
CString FUN_141082090(unsigned int nQuestId, const CString& a, const CString& b, const CString& c, const CString& d);
class Unk_EmoQuestMgr { public: void FUN_141aa87c0(UIQuestEventListener*); void FUN_141aa8850(UIQuestEventListener*); };
Unk_EmoQuestMgr* FUN_140bfc4b0();
class Unk_EmoStatusMgr { public: void FUN_141b0cd00(UIStatusEventListener*); void FUN_141b0cd90(UIStatusEventListener*); };
Unk_EmoStatusMgr* FUN_140aa6d40();
class Unk_EmoUIScale;
Unk_EmoUIScale* FUN_14025e7a0();                                            // ui scale service
float FUN_1422afec0(Unk_EmoUIScale* pScale, int nLayer);                    // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
float FUN_1412762d0(const NiPoint3& pt);
float FUN_141670500(PCBase* pActor);
PCBase* FUN_140974230(PCBase*);
void* FUN_1408e57f0();
int FUN_1422b9ea0(void*);
int FUN_1422b9e00(void*);
bool FUN_140930110(int nActorId);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
class Unk_EmoClip : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1422c00f0(float x, float y);
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
class Unk_EmoPopupMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_EmoPopupMgr* FUN_1403ed2b0();
UIEmoticon* FUN_141930440(int nUiId);
unsigned int FUN_14192fe00(Unk_EmoPlayer* pPlayer);

int FUN_14192e8f0();
#ifndef MS2_HOOK_DLL
// @0x14192e8f0
int FUN_14192e8f0()
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

CString FUN_14192ebf0(unsigned int nNpcId);
#ifndef MS2_HOOK_DLL
// @0x14192ebf0
CString FUN_14192ebf0(unsigned int nNpcId)
{
    CString strName;
    if (s_npcMovieNames.Lookup(nNpcId, strName))
        return strName;
    if (FUN_140764010()->FUN_14035b0a0(nNpcId) != 0)
        return Unk_SocketFormat("emoticon_movie_npc_{0}", FUN_140764010()->FUN_14035b2a0(nNpcId));
    return CString("");
}
#endif

// @0x14192ed20
CString FUN_14192ed20(unsigned int nQuestId, int nKind)
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
        strName += FUN_141082090(nQuestId, "_epic", "", "_repeat", "_event");
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
    m_c0 = *FUN_1401d3200()->m_218.FUN_140967520(&fDefault);
    m_54 = FUN_1401d3200()->m_2600.FUN_1402bac70();
    FUN_140bfc4b0()->FUN_141aa87c0(static_cast<UIQuestEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    FUN_14192f910();
}

// @0x14192f0f0
UIEmoticon::Entity::~Entity()
{
    FUN_140bfc4b0()->FUN_141aa8850(static_cast<UIQuestEventListener*>(this));
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
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
        FUN_140ad0c10(pPos, FUN_1422afec0(FUN_14025e7a0(), m_18));
        if (FUN_14096e110(pActor) != 0)
        {
            pPos->y = pPos->y + *FUN_1401d3200()->m_638.FUN_140298f40();
        }
        else
        {
            if (FUN_140974230(pActor) != 0)
                pPos->y = pPos->y + FUN_141670500(pActor);
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
        ((Unk_EmoClip*)m_38.operator->())->FUN_1422c00f0(pPos->x, pPos->y);
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
    if (FUN_1422b9ea0(FUN_1408e57f0()) != 0 || FUN_1422b9e00(FUN_1408e57f0()) == 0x6200031)
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
    Unk_EmoPlayer* pPlayer = FUN_14096e110(FUN_140f49330());
    if (pPlayer != 0)
    {
        int nType = pPlayer->FUN_141093c60();
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
        Unk_EmoPlayer* pPlayer = FUN_14096e110(FUN_140f49330());
        if (pPlayer != 0)
            return FUN_14192ed20(pPlayer->FUN_141093c20(), pPlayer->FUN_141093c60());
    }
    if (!m_b8.IsEmpty())
        return m_b8;
    if (m_b0 == 0)
    {
        Unk_EmoPlayer* pPlayer = FUN_14096e110(FUN_140f49330());
        if (pPlayer != 0)
        {
            CString strName = FUN_14192ebf0(FUN_14192fe00(pPlayer));
            return strName;
        }
    }
    return CString("");
}

// @0x14192fbd0
void UIEmoticon::Entity::FUN_14192fbd0()
{
    Unk_EmoPlayer* pPlayer = FUN_14096e110(FUN_140f49330());
    if (pPlayer != 0)
        pPlayer->FUN_141093e90();
}

// @0x14192fc10
UIEmoticon::UIEmoticon()
{
    m_70 = "emoticon_entity_body";
    FUN_14192e8f0();
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
    FUN_14192fe20(m_68);
}

// @0x14192fd40
MS2Ptr<UIEmoticon::Entity> FUN_14192fd40(int nActorId)
{
    UIEmoticon* pUi = FUN_141930440(0x4e2f);
    if (pUi != 0)
        return MS2Ptr<UIEmoticon::Entity>(pUi->FUN_141930000(nActorId));
    return MS2Ptr<UIEmoticon::Entity>(0);
}

// @0x14192fdc0
void FUN_14192fdc0(int nActorId)
{
    UIEmoticon* pUi = FUN_141930440(0x4e2f);
    if (pUi)
        pUi->FUN_140f49c00(nActorId);
}

// @0x14192fe00
unsigned int FUN_14192fe00(Unk_EmoPlayer* pPlayer)
{
    unsigned int nNpcId = pPlayer->FUN_1410937b0();
    return nNpcId;
}

// @0x14192fe20
void UIEmoticon::FUN_14192fe20(unsigned int nCount)
{
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        for (unsigned int i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value v = pClip->Invoke("createCache", m_70);
            if (FUN_1409b0390(&v) == 0)
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
UIEmoticon::Entity* UIEmoticon::FUN_141930000(int nActorId)
{
    if (FUN_140f49890(nActorId) != 0)
        return 0;
    {
        FUN_140f49c00(nActorId);
        MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pClip.get())
        {
            if (m_78.IsEmpty())
            {
                bool bFlag = FUN_140930110(nActorId);
                bFlag = false;
                Scaleform::GFx::Value v = ((Unk_EmoClip*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
                if (FUN_1409b0390(&v) == 0)
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
                                ((Unk_EmoClip*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_EmoClip*)pOldClip.operator->())->FUN_1422bb870(), bNew);
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
UIEmoticon* FUN_141930440(int nUiId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
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

// Hooks. Not hooked: the ctors/dtors, FUN_14192e8f0/FUN_14192ebf0 (read the unit's mutable name table, which the exe fills),
// everything that reaches FUN_14192ebf0 (vfunc_5, vfunc_8, FUN_14192f910/f9f0/fa50), and everything that constructs an
// Entity (OnLoadComplete, FUN_14192fe20, FUN_141930000, FUN_14192fd40: the DLL would build it with its own vftables) or
// dynamic_casts to UIEmoticon (FUN_141930440, FUN_14192fdc0). FUN_14192ed20 returns a CString by value (free-function thunk).
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
MS2_REPLACE(0x14192FE00, FUN_14192fe00, 32, 0x18CD16A5);
MS2_REPLACE_METHOD(0x1419305C0, UIEmoticon::Entity, FUN_1419305c0, 47, 0x1858A2DC);
