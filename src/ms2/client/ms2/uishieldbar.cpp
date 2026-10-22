// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Shield bar HUD (world-anchored, UIHudEntity family).
// MS2-UNIT: ?\uishieldbar.cpp
// MS2-RANGE: 0x140e855f0-0x140e86d80 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIShieldBar@@UEAAHXZ 0x140e86bf0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uishieldbar.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uishieldbar.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_ShieldClip : public ASMovieClip
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const CString& strLabel);     // 13 gotoAndPlay(label)
    void FUN_1422c0e20(int nWidth);
};
class Unk_ShieldEntity : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_140cb6990(const char* szMethod, __int64 a1, __int64 a2);          // "open"
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1422c00f0(float x, float y);
    void FUN_1422c0290(float cx, float cy);
};
struct Unk_ShieldCfgFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_ShieldCfgInt { int* FUN_1402056b0(); void* m_unknown; };
struct Unk_ShieldCfg
{
    char m_pad_0000[0x2c8];
    Unk_ShieldCfgFloat m_2c8;
    char m_pad_0320[0xe610 - 0x2c8 - sizeof(Unk_ShieldCfgFloat)];
    Unk_ShieldCfgInt m_e610;
};
Unk_ShieldCfg* FUN_1401d3200();
class Unk_ShieldUIScale;
Unk_ShieldUIScale* FUN_14025e7a0();                                         // ui scale service
float FUN_1422afec0(Unk_ShieldUIScale* pScale, int nLayer);                 // scale of a layer
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
float FUN_1412762d0(const NiPoint3& pt);
class Unk_ShieldActor : public PCBase
{
public:
    int FUN_14166ce30();
    float FUN_141670390();
};
class Unk_ShieldPlayer
{
public:
    int FUN_1415278d0(__int64 nId);
};
class Unk_ShieldWorld;
Unk_ShieldWorld* FUN_1403ed2d0();
Unk_ShieldPlayer* FUN_141bd0cc0(Unk_ShieldWorld*);
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);
PCBase* FUN_140974230(PCBase*);
__int64 FUN_141656a80(PCBase*);
struct Unk_ShieldCfgData { char m_pad[0xb]; bool m_b; char m_c; bool m_d; };
class Unk_ShieldCfgHolder { public: Unk_ShieldCfgData* FUN_140b123b0(); };
Unk_ShieldCfgHolder* FUN_1409a8b10();
bool FUN_140930110(int nActorId);
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
class Unk_ShieldUIMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_ShieldUIMgr* FUN_1403ed2b0();

// @0x140e855f0
UIShieldBar::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : TimerEntity(nLayer, clip, nActorId)
{
    m_a0 = 0;
    m_a8 = 0;
    m_b0 = 0;
    m_b4 = 0;
    m_b8 = 0;
    m_54 = FUN_1401d3200()->m_2c8.FUN_1402bac70();
}

// @0x140e856c0
UIShieldBar::Entity::~Entity()
{
}

// @0x140e856f0
void UIShieldBar::Entity::vfunc_3()
{
    TimerEntity::vfunc_3();
    vfunc_7();
}

// @0x140e85720
void UIShieldBar::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_a0 = 0;
    m_a8 = 0;
    m_b0 = 0;
    m_b4 = 0;
    m_b8 = 0;
}

// @0x140e85790
void UIShieldBar::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    if (m_38.get())
    {
        ((Unk_ShieldEntity*)m_38.operator->())->FUN_140cb6990("open", m_a0, m_a8);
        MS2Ptr<ASMovieClip> shield = m_38->FUN_1409b4560("m_shield");
        if (shield.get())
        {
            MS2Ptr<ASMovieClip> gaugeMc = shield->FUN_1409b4560("m_gauge");
            if (gaugeMc.get())
            {
                MS2Ptr<ASMovieClip> gauge = gaugeMc->FUN_1409b4560("gauge");
                if (gauge.get())
                    m_b8 = gauge->FUN_1422c1340();
            }
        }
    }
}

// @0x140e85970
void UIShieldBar::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get())
    {
        MS2Ptr<ASMovieClip> shield = m_38->FUN_1409b4560("m_shield");
        if (shield.get())
        {
            MS2Ptr<ASMovieClip> gaugeMc = shield->FUN_1409b4560("m_gauge");
            if (gaugeMc.get())
            {
                MS2Ptr<ASMovieClip> gauge = gaugeMc->FUN_1409b4560("gauge");
                if (gauge.get())
                {
                    if (m_b4 != 0)
                    {
                        if (0 < m_64)
                            m_68.FUN_140868750(m_64);
                        float fRate = (float)m_a0 / (float)m_a8;
                        ((Unk_ShieldClip*)gauge.operator->())->FUN_1422c0e20((int)(fRate * (float)m_b8));
                        ((Unk_ShieldClip*)gaugeMc.operator->())->vfunc_13("defence");
                        m_b4 = 0;
                    }
                    FUN_140ad0c10(pPos, FUN_1422afec0(FUN_14025e7a0(), m_18));
                    pPos->y = pPos->y + vfunc_9();
                    pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
                    pPos->x = pPos->x - (float)(m_38->FUN_1422c1340() / 2);
                    ((Unk_ShieldEntity*)m_38.operator->())->FUN_1422c00f0(pPos->x, pPos->y);
                }
            }
        }
    }
}

// @0x140e85cf0
void UIShieldBar::Entity::vfunc_7()
{
    if (m_38.get())
    {
        MS2Ptr<ASMovieClip> shield = m_38->FUN_1409b4560("m_shield");
        if (shield.get())
            ((Unk_ShieldClip*)shield.operator->())->vfunc_13("_hide");
    }
}

// @0x140e85dd0
int UIShieldBar::Entity::vfunc_8(int n)
{
    if (FUN_140e860f0() == 0)
        return 1;
    Unk_ShieldActor* pActor = (Unk_ShieldActor*)FUN_140f49330();
    if (pActor == 0)
        return 1;
    if (m_b0 == 0)
        return 1;
    int nDead = pActor->FUN_14166ce30();
    if (nDead != 0)
        return 1;
    return TimerEntity::vfunc_8(nDead);
}

// @0x140e85e60
float UIShieldBar::Entity::vfunc_9()
{
    Unk_ShieldActor* pActor = (Unk_ShieldActor*)FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    float f = pActor->FUN_141670390();
    return f + (float)*FUN_1401d3200()->m_e610.FUN_1402056b0();
}

// @0x140e85ed0
void UIShieldBar::Entity::FUN_140e85ed0(int n)
{
    m_b0 = n;
}

// @0x140e85ef0
int UIShieldBar::Entity::FUN_140e85ef0()
{
    return m_b0;
}

// @0x140e85f10
void UIShieldBar::Entity::FUN_140e85f10(__int64 nCur, __int64 nMax)
{
    int bChanged;
    if (m_b4 == 0 && m_a0 == nCur && m_a8 == nMax)
        bChanged = 0;
    else
        bChanged = 1;
    m_b4 = bChanged;
    m_a0 = nCur;
    m_a8 = nMax;
    FUN_140f49470();
    vfunc_2();
}

// @0x140e85fc0
void UIShieldBar::Entity::FUN_140e85fc0(__int64 nCur, __int64 nMax)
{
    int bChanged = (m_b4 == 0 && m_a0 == nCur && m_a8 == nMax) ? 0 : 1;
    m_a0 = nCur;
    m_a8 = nMax;
    if (m_4c != 0 && bChanged)
    {
        if (m_a0 == 0)
            vfunc_3();
        else
            m_b4 = 1;
    }
}

// @0x140e86090
void UIShieldBar::Entity::FUN_140e86090()
{
    if (m_38.get())
        ((Unk_ShieldEntity*)m_38.operator->())->FUN_1422c0290(100.0f, 100.0f);
}

// @0x140e860f0
int UIShieldBar::Entity::FUN_140e860f0()
{
    Unk_ShieldPlayer* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return 0;
    PCBase* pActor = FUN_140f49330();
    if (pActor == 0)
        return 0;
    if (FUN_14087ddc0(pActor ? pActor->GetClassDesc() : 0, 0x6200004) != 0)
        return FUN_1409a8b10()->FUN_140b123b0()->m_b;
    else
    {
        PCBase* pPc = FUN_140974230(pActor);
        if (pPc != 0)
        {
            if (pPlayer->FUN_1415278d0(FUN_141656a80(pPc)) == 0)
                return 0;
            return FUN_1409a8b10()->FUN_140b123b0()->m_d;
        }
    }
    return 1;
}

// @0x140e861f0
UIShieldBar::UIShieldBar()
{
    m_70 = "UIShieldBar";
}

// @0x140e86260
UIShieldBar::~UIShieldBar()
{
}

// @0x140e862a0
CString UIShieldBar::GetTypeName()
{
    return CString("ShieldBar");
}

// @0x140e862f0
void UIShieldBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140e86430(m_68);
}

// @0x140e86a50
UIShieldBar* FUN_140e86a50(int nUiId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (p.get())
            return dynamic_cast<UIShieldBar*>((UIObject*)p);
    }
    return 0;
}

// @0x140e86320
MS2Ptr<UIShieldBar::Entity> FUN_140e86320(int nActorId)
{
    UIShieldBar* pBar = FUN_140e86a50(0x4f77);
    if (pBar != 0)
    {
        MS2Ptr<UIShieldBar::Entity> pEntity(pBar->FUN_140e86610(nActorId));
        if (pEntity.get())
            pEntity->FUN_140e86090();
        return pEntity;
    }
    return MS2Ptr<UIShieldBar::Entity>(0);
}

// @0x140e863f0
void FUN_140e863f0(int nActorId)
{
    UIShieldBar* pBar = FUN_140e86a50(0x4f77);
    if (pBar)
        pBar->FUN_140f49c00(nActorId);
}

// @0x140e86430
void UIShieldBar::FUN_140e86430(unsigned int nCount)
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

// @0x140e86610
UIShieldBar::Entity* UIShieldBar::FUN_140e86610(int nActorId)
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
            Scaleform::GFx::Value v = ((Unk_ShieldEntity*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                            ((Unk_ShieldEntity*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_ShieldEntity*)pOldClip.operator->())->FUN_1422bb870(), bNew);
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
MS2_REPLACE_METHOD(0x140e856f0, UIShieldBar::Entity, vfunc_3, 40, 0xD6658280);
MS2_REPLACE_METHOD(0x140e85720, UIShieldBar::Entity, vfunc_4, 101, 0x9FCBA071);
MS2_REPLACE_METHOD(0x140e85790, UIShieldBar::Entity, vfunc_5, 462, 0x241D5087);
MS2_REPLACE_METHOD(0x140e85970, UIShieldBar::Entity, vfunc_6, 886, 0x1CDA2B3C);
MS2_REPLACE_METHOD(0x140e85cf0, UIShieldBar::Entity, vfunc_7, 208, 0xAE169465);
MS2_REPLACE_METHOD(0x140e85dd0, UIShieldBar::Entity, vfunc_8, 132, 0x53FDD5EC);
MS2_REPLACE_METHOD(0x140e85e60, UIShieldBar::Entity, vfunc_9, 94, 0xF2D64BFA);
MS2_REPLACE_METHOD(0x140e85ed0, UIShieldBar::Entity, FUN_140e85ed0, 25, 0x343F531F);
MS2_REPLACE_METHOD(0x140e85ef0, UIShieldBar::Entity, FUN_140e85ef0, 17, 0x1F8D7963);
MS2_REPLACE_METHOD(0x140e85f10, UIShieldBar::Entity, FUN_140e85f10, 169, 0xCD5D40F7);
MS2_REPLACE_METHOD(0x140e85fc0, UIShieldBar::Entity, FUN_140e85fc0, 202, 0x7FE18281);
MS2_REPLACE_METHOD(0x140e86090, UIShieldBar::Entity, FUN_140e86090, 77, 0xA954AA63);
MS2_REPLACE_METHOD(0x140e860f0, UIShieldBar::Entity, FUN_140e860f0, 236, 0xD81920B4);
MS2_REPLACE_METHOD(0x140e862a0, UIShieldBar, GetTypeName, 61, 0xFC836A90);
MS2_REPLACE_METHOD(0x140e862f0, UIShieldBar, OnLoadComplete, 42, 0x272BBEC3);
MS2_REPLACE_METHOD(0x140e86430, UIShieldBar, FUN_140e86430, 465, 0xC9744E09);
MS2_REPLACE_METHOD(0x140e86610, UIShieldBar, FUN_140e86610, 1082, 0x2816AFC0);
MS2_REPLACE(0x140e86a50, FUN_140e86a50, 147, 0x6B5755F8);
MS2_REPLACE(0x140e863f0, FUN_140e863f0, 50, 0x1EE05996);

MS2_EMIT_CRT_MEMMOVE_S();
