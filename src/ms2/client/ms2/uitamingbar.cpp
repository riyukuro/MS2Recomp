// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Taming bar HUD (world-anchored, UIHudEntity family).
// MS2-UNIT: ?\uitamingbar.cpp
// MS2-RANGE: 0x140e97670-0x140e988a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitamingbar.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uitamingbar.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_TamingClip : public ASMovieClip
{
public:
    void FUN_1422c0e20(int nWidth);
};
class Unk_TamingEntity : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1422baea0(const char* szMember, float* pOut);                                       // read a member
    void FUN_1422c00f0(float x, float y);
};
struct Unk_TamingCfgFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_TamingCfgInt64 { __int64 FUN_140ba77c0(); char m_pad[8]; };
struct Unk_TamingCfg
{
    char m_pad_0000[0x2c8];
    Unk_TamingCfgFloat m_2c8;
    char m_pad_0320[0x8468 - 0x2c8 - sizeof(Unk_TamingCfgFloat)];
    Unk_TamingCfgInt64 m_8468;
};
Unk_TamingCfg* FUN_1401d3200();
class Unk_TamingUIScale;
Unk_TamingUIScale* FUN_14025e7a0();                                         // ui scale service
float FUN_1422afec0(Unk_TamingUIScale* pScale, int nLayer);                 // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
float FUN_1412762d0(const NiPoint3& pt);
class Unk_TamingTamed { public: int FUN_140b109f0(); int FUN_140b11000(); };
class Unk_TamingActor : public PCBase
{
public:
    int FUN_14166ce30();
    float FUN_141670390();
};
Unk_TamingTamed* FUN_1409ffc60(PCBase* pActor);
class Unk_TamingPlayer { public: int FUN_14123c580(); };
class Unk_TamingWorld;
Unk_TamingWorld* FUN_1403ed2d0();
Unk_TamingPlayer* FUN_141bd0cc0(Unk_TamingWorld*);
bool FUN_140930110(int nActorId);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
class Unk_TamingUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_TamingUIMgr* FUN_1403ed2b0();
void FUN_1422bcdd0(Scaleform::GFx::Value*, __int64);
void FUN_1422bccb0(Scaleform::GFx::Value*, int);

// @0x140e97670
UITamingBar::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : TimerEntity(nLayer, clip, nActorId)
{
    m_a0 = 0;
    m_b0 = 1;
    m_b4 = 0;
    m_b8 = 0;
    m_54 = FUN_1401d3200()->m_2c8.FUN_1402bac70();
    m_a8 = FUN_1401d3200()->m_8468.FUN_140ba77c0();
    FUN_140e97e00();
}

// @0x140e97750
UITamingBar::Entity::~Entity()
{
}

// @0x140e97780
void UITamingBar::Entity::vfunc_3()
{
    TimerEntity::vfunc_3();
    vfunc_7();
}

// @0x140e977b0
void UITamingBar::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_a0 = 0;
    m_a8 = FUN_1401d3200()->m_8468.FUN_140ba77c0();
    m_b0 = 1;
    m_b4 = 0;
    m_b8 = 0;
}

// @0x140e97830
void UITamingBar::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    FUN_140e97e00();
    if (m_38.get())
    {
        m_38->Invoke("open", m_a0, m_a8, m_b0);
        ((Unk_TamingEntity*)m_38.operator->())->FUN_1422baea0("m_barWidth", &m_bc);
    }
}

// @0x140e97910
void UITamingBar::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get())
    {
        MS2Ptr<ASMovieClip> bar = m_38->FUN_1409b4560("m_bar");
        if (bar.get())
        {
            if (m_b8 != 0)
            {
                if (0 < m_64)
                    m_68.FUN_140868750(m_64);
                float fRate = m_bc / (float)m_a8;
                ((Unk_TamingClip*)bar.operator->())->FUN_1422c0e20((int)(fRate * (float)m_a0));
                m_b8 = 0;
            }
            FUN_140ad0c10(pPos, FUN_1422afec0(FUN_14025e7a0(), m_18));
            pPos->y = pPos->y + vfunc_9();
            pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
            ((Unk_TamingEntity*)m_38.operator->())->FUN_1422c00f0(pPos->x, pPos->y);
        }
    }
}

// @0x140e97b10
void UITamingBar::Entity::vfunc_7()
{
    if (m_38.get())
        m_38->vfunc_3(0);
}

// @0x140e97b70
int UITamingBar::Entity::vfunc_8(int n)
{
    Unk_TamingActor* pActor = (Unk_TamingActor*)FUN_140f49330();
    if (pActor == 0)
        return 1;
    if (m_b4 == 0)
        return 1;
    int nDead = pActor->FUN_14166ce30();
    if (nDead != 0)
        return 1;
    Unk_TamingTamed* pTamed = FUN_1409ffc60(pActor);
    if (pTamed != 0)
    {
        Unk_TamingPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pPlayer != 0)
        {
            if (pPlayer->FUN_14123c580() != pTamed->FUN_140b109f0())
                return 1;
        }
    }
    return TimerEntity::vfunc_8(nDead);
}

// @0x140e97c50
float UITamingBar::Entity::vfunc_9()
{
    Unk_TamingActor* pActor = (Unk_TamingActor*)FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    return pActor->FUN_141670390() + 5.0f;
}

// @0x140e97ca0
void UITamingBar::Entity::FUN_140e97ca0(int n)
{
    m_b4 = n;
}

// @0x140e97cc0
int UITamingBar::Entity::FUN_140e97cc0()
{
    return m_b4;
}

// @0x140e97ce0
void UITamingBar::Entity::FUN_140e97ce0(__int64 nCur)
{
    int bChanged;
    if (m_b8 == 0 && m_a0 == nCur)
        bChanged = 0;
    else
        bChanged = 1;
    m_b8 = bChanged;
    m_a0 = nCur;
    FUN_140f49470();
    vfunc_2();
}

// @0x140e97d70
void UITamingBar::Entity::FUN_140e97d70(__int64 nCur)
{
    int bChanged = (m_b8 == 0 && m_a0 == nCur) ? 0 : 1;
    m_a0 = nCur;
    if (m_4c != 0 && bChanged)
        m_b8 = 1;
}

// @0x140e97e00
void UITamingBar::Entity::FUN_140e97e00()
{
    Unk_TamingTamed* pTamed = FUN_1409ffc60(FUN_140f49330());
    if (pTamed != 0)
        m_b0 = pTamed->FUN_140b11000();
}

// @0x140e97e50
UITamingBar::UITamingBar()
{
    m_70 = "entity_TamingBar";
}

// @0x140e97ec0
UITamingBar::~UITamingBar()
{
}

// @0x140e97f00
CString UITamingBar::GetTypeName()
{
    return CString("TamingBar");
}

// @0x140e97f50
void UITamingBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140e98040(m_68);
}

// FUN_140e98660 is defined below; declared here for its callers.
UITamingBar* FUN_140e98660(int nUiId);

// @0x140e97f80
MS2Ptr<UITamingBar::Entity> FUN_140e97f80(int nActorId)
{
    UITamingBar* pBar = FUN_140e98660(0x4f3b);
    if (pBar != 0)
        return MS2Ptr<UITamingBar::Entity>(pBar->FUN_140e98220(nActorId));
    return MS2Ptr<UITamingBar::Entity>(0);
}

// @0x140e98000
void FUN_140e98000(int nActorId)
{
    UITamingBar* pBar = FUN_140e98660(0x4f3b);
    if (pBar)
        pBar->FUN_140f49c00(nActorId);
}

// @0x140e98040
void UITamingBar::FUN_140e98040(unsigned int nCount)
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

// @0x140e98220
UITamingBar::Entity* UITamingBar::FUN_140e98220(int nActorId)
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
                Scaleform::GFx::Value v = ((Unk_TamingEntity*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                                ((Unk_TamingEntity*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_TamingEntity*)pOldClip.operator->())->FUN_1422bb870(), bNew);
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

// @0x140e98660
UITamingBar* FUN_140e98660(int nUiId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (p.get())
            return dynamic_cast<UITamingBar*>((UIObject*)p);
    }
    return 0;
}

// @0x140e98700
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, __int64 a1, __int64 a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_REPLACE_METHOD(0x140e97780, UITamingBar::Entity, vfunc_3, 40, 0xBDD3E5C5);
MS2_REPLACE_METHOD(0x140e977b0, UITamingBar::Entity, vfunc_4, 116, 0xF7161E34);
MS2_REPLACE_METHOD(0x140e97830, UITamingBar::Entity, vfunc_5, 204, 0x6FE42C85);
MS2_REPLACE_METHOD(0x140e97910, UITamingBar::Entity, vfunc_6, 495, 0xAC076AD4);
MS2_REPLACE_METHOD(0x140e97b10, UITamingBar::Entity, vfunc_7, 76, 0x6DBCAFA8);
MS2_REPLACE_METHOD(0x140e97b70, UITamingBar::Entity, vfunc_8, 205, 0xE27002D1);
MS2_REPLACE_METHOD(0x140e97c50, UITamingBar::Entity, vfunc_9, 60, 0x3E2188A2);
MS2_REPLACE_METHOD(0x140e97ca0, UITamingBar::Entity, FUN_140e97ca0, 25, 0x999FD793);
MS2_REPLACE_METHOD(0x140e97cc0, UITamingBar::Entity, FUN_140e97cc0, 17, 0xBA29CEEF);
MS2_REPLACE_METHOD(0x140e97ce0, UITamingBar::Entity, FUN_140e97ce0, 128, 0xEDE2E208);
MS2_REPLACE_METHOD(0x140e97d70, UITamingBar::Entity, FUN_140e97d70, 125, 0xEB25A9C5);
MS2_REPLACE_METHOD(0x140e97e00, UITamingBar::Entity, FUN_140e97e00, 66, 0x36E57BCA);
MS2_REPLACE_METHOD(0x140e97f00, UITamingBar, GetTypeName, 61, 0x443B093E);
MS2_REPLACE_METHOD(0x140e97f50, UITamingBar, OnLoadComplete, 42, 0x10016461);
MS2_REPLACE_METHOD(0x140e98040, UITamingBar, FUN_140e98040, 465, 0x70DF7900);
MS2_REPLACE_METHOD(0x140e98220, UITamingBar, FUN_140e98220, 1082, 0xCAA7BFCA);
MS2_REPLACE(0x140e98000, FUN_140e98000, 50, 0xDB13BBC3);
MS2_REPLACE(0x140e98660, FUN_140e98660, 147, 0xB9785146);

MS2_EMIT_CRT_MEMMOVE_S();
