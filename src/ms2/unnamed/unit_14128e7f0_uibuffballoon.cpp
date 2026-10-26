// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBuffBalloon (world-anchored buff icon, UIHudEntity family).
// MS2-UNIT: unit_14128e7f0
// MS2-RANGE: 0x14128e7f0-0x14128f8f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_14128e7f0.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_BuffEntity : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1422c00f0(float x, float y);
};
struct Unk_BuffCfgFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_BuffCfg
{
    char m_pad_0000[0x378];
    Unk_BuffCfgFloat m_378;
};
Unk_BuffCfg* FUN_1401d3200();
class Unk_BuffUIScale;
Unk_BuffUIScale* FUN_14025e7a0();                                           // ui scale service
float FUN_1422afec0(Unk_BuffUIScale* pScale, int nLayer);                   // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
float FUN_1412762d0(const NiPoint3& pt);
class Unk_BuffActor : public PCBase
{
public:
    int FUN_14166ce30();
    float FUN_141670500();
};
class Unk_BuffMgr;
Unk_BuffMgr* FUN_1409478c0();                                               // singleton accessor
int FUN_140a18070(Unk_BuffMgr*);
CStringW FUN_14016a730(const char* sz, int nFlags);                         // FormatStringId(id) without arguments
bool FUN_140930110(int nActorId);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
class Unk_BuffUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_BuffUIMgr* FUN_1403ed2b0();
class Unk_BuffInfoAS : public AScript
{
public:
    Unk_BuffInfoAS(int nMovieId);
    void FUN_1407cbb20(const char* szMember, CStringW strValue);
};
UIBuffBalloon* FUN_14128f650(int nUiId);

// @0x14128e7f0
UIBuffBalloon::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : TimerEntity(nLayer, clip, nActorId), m_a0("")
{
    m_a8 = 0;
    m_54 = FUN_1401d3200()->m_378.FUN_1402bac70();
}

// @0x14128e890
UIBuffBalloon::Entity::~Entity()
{
}

// @0x14128e8e0
void UIBuffBalloon::Entity::vfunc_2()
{
    if (FUN_140a18070(FUN_1409478c0()) == 0)
        return;
    TimerEntity::vfunc_2();
}

// @0x14128e920
void UIBuffBalloon::Entity::vfunc_3()
{
    TimerEntity::vfunc_3();
    vfunc_7();
}

// @0x14128e950
void UIBuffBalloon::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_a0 = "";
    m_a8 = 0;
}

// @0x14128e9a0
void UIBuffBalloon::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    if (FUN_140a18070(FUN_1409478c0()) == 0)
        return;
    if (m_38.get() != 0)
    {
        Unk_BuffInfoAS info(m_18);
        info.FUN_1407cbb20("imgPath", FUN_14016a730((const char*)FUN_14128edf0(), 0));
        m_38->Invoke("open", info);
    }
}

// @0x14128eae0
void UIBuffBalloon::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get())
    {
        FUN_140ad0c10(pPos, FUN_1422afec0(FUN_14025e7a0(), m_18));
        pPos->y = pPos->y + vfunc_9();
        pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
        ((Unk_BuffEntity*)m_38.operator->())->FUN_1422c00f0(pPos->x - 55.0f, pPos->y - 110.0f);
    }
}

// @0x14128ec00
void UIBuffBalloon::Entity::vfunc_7()
{
    if (m_38.get())
        m_38->vfunc_3(0);
}

// @0x14128ec60
int UIBuffBalloon::Entity::vfunc_8(int n)
{
    Unk_BuffActor* pActor = (Unk_BuffActor*)FUN_140f49330();
    if (pActor == 0)
        return 1;
    return TimerEntity::vfunc_8(pActor->FUN_14166ce30());
}

// @0x14128ecb0
float UIBuffBalloon::Entity::vfunc_9()
{
    Unk_BuffActor* pActor = (Unk_BuffActor*)FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    return pActor->FUN_141670500();
}

// @0x14128ecf0
void UIBuffBalloon::Entity::FUN_14128ecf0(int nBuffId, CString strImg, int nTime)
{
    m_a8 = nBuffId;
    m_a0 = strImg;
    m_64 = nTime;
    if (FUN_140f48d40() != 0)
    {
        FUN_140f48d80();
        m_68.FUN_140868750(m_64);
    }
    else
    {
        FUN_140f49470();
        vfunc_2();
    }
}

// @0x14128edb0
void UIBuffBalloon::Entity::FUN_14128edb0(int nBuffId)
{
    if (m_a8 == nBuffId)
        vfunc_3();
}

// @0x14128edf0
CString UIBuffBalloon::Entity::FUN_14128edf0()
{
    return m_a0;
}

// @0x14128ee40
UIBuffBalloon::UIBuffBalloon()
{
    m_70 = "buff_ballon";
}

// @0x14128eeb0
UIBuffBalloon::~UIBuffBalloon()
{
}

// @0x14128eef0
CString UIBuffBalloon::GetTypeName()
{
    return CString("BuffBalloon");
}

// @0x14128ef40
void UIBuffBalloon::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_14128f030(m_68);
}

// @0x14128ef70
MS2Ptr<UIBuffBalloon::Entity> FUN_14128ef70(int nActorId)
{
    UIBuffBalloon* pBar = FUN_14128f650(0x4ea4);
    if (pBar != 0)
        return MS2Ptr<UIBuffBalloon::Entity>(pBar->FUN_14128f210(nActorId));
    return MS2Ptr<UIBuffBalloon::Entity>(0);
}

// @0x14128eff0
void FUN_14128eff0(int nActorId)
{
    UIBuffBalloon* pBar = FUN_14128f650(0x4ea4);
    if (pBar)
        pBar->FUN_140f49c00(nActorId);
}

// @0x14128f030
void UIBuffBalloon::FUN_14128f030(unsigned int nCount)
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

// @0x14128f210
UIBuffBalloon::Entity* UIBuffBalloon::FUN_14128f210(int nActorId)
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
                Scaleform::GFx::Value v = ((Unk_BuffEntity*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                                ((Unk_BuffEntity*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_BuffEntity*)pOldClip.operator->())->FUN_1422bb870(), bNew);
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

// @0x14128f650
UIBuffBalloon* FUN_14128f650(int nUiId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (p.get())
            return dynamic_cast<UIBuffBalloon*>((UIObject*)p);
    }
    return 0;
}

MS2_REPLACE_METHOD(0x14128e8e0, UIBuffBalloon::Entity, vfunc_2, 43, 0xED835FB6);
MS2_REPLACE_METHOD(0x14128e920, UIBuffBalloon::Entity, vfunc_3, 40, 0xCDEF3E70);
MS2_REPLACE_METHOD(0x14128e950, UIBuffBalloon::Entity, vfunc_4, 66, 0x95632185);
MS2_REPLACE_METHOD(0x14128e9a0, UIBuffBalloon::Entity, vfunc_5, 302, 0x61A2BBC8);
MS2_REPLACE_METHOD(0x14128eae0, UIBuffBalloon::Entity, vfunc_6, 268, 0x6876850B);
MS2_REPLACE_METHOD(0x14128ec00, UIBuffBalloon::Entity, vfunc_7, 76, 0x6A573BCC);
MS2_REPLACE_METHOD(0x14128ec60, UIBuffBalloon::Entity, vfunc_8, 70, 0xB6BB7C5F);
MS2_REPLACE_METHOD(0x14128ecb0, UIBuffBalloon::Entity, vfunc_9, 52, 0x04D723C6);
MS2_REPLACE_METHOD(0x14128ecf0, UIBuffBalloon::Entity, FUN_14128ecf0, 178, 0xD3B5E15B);
MS2_REPLACE_METHOD(0x14128edb0, UIBuffBalloon::Entity, FUN_14128edb0, 51, 0xBB112FB0);
MS2_REPLACE_METHOD(0x14128eef0, UIBuffBalloon, GetTypeName, 61, 0x66ADCDFE);
MS2_REPLACE_METHOD(0x14128ef40, UIBuffBalloon, OnLoadComplete, 42, 0x70E8ED61);
MS2_REPLACE(0x14128eff0, FUN_14128eff0, 50, 0x15407F24);
MS2_REPLACE_METHOD(0x14128f030, UIBuffBalloon, FUN_14128f030, 465, 0x0B5FAD34);
MS2_REPLACE_METHOD(0x14128f210, UIBuffBalloon, FUN_14128f210, 1082, 0xA2243DCB);
MS2_REPLACE(0x14128f650, FUN_14128f650, 147, 0x4464D1DD);

MS2_EMIT_CRT_MEMMOVE_S();
