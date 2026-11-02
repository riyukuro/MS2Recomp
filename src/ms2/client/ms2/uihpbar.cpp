// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Hp bar HUDs over actors (world-anchored, UIHudEntity family):
// UIHpBar, UITombStoneBar (a dead pc's tomb hit counter) and UISlimeEventBar (event arrow gauge).
// MS2-UNIT: ?\uihpbar.cpp
// MS2-RANGE: 0x141991700-0x1419950d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihpbar.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uihpbar.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/cpet.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#include "ms2/placeholder/cnpc.h"  // C3: CNpc (efd::DynamicCast<CNpc, PCBase>)

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_HpMovie : public ASMovieClip
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(const CString& strLabel);     // 15 gotoAndPlay(label)
};
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcdd0(Scaleform::GFx::Value* pValue, __int64 n);
class Unk_HpClip : public ASGameEntity
{
public:
    Scaleform::GFx::Value FUN_141994b30(const char* szMethod, unsigned int a1, unsigned int a2, int a3);               // "setArrow"
    Scaleform::GFx::Value FUN_141994c00(const char* szMethod, __int64 a1, __int64 a2, unsigned short a3, int a4);    // "open"
};
class Unk_BannerClip   // C3: unit-local view (defs in uibanner); the entity clip's create / update calls
{
public:
    Scaleform::GFx::Value FUN_140ba9470(const char* szMethod, int a1, CString a2, bool a3);      // "createEntity"
    Scaleform::GFx::Value FUN_140ba9570(const char* szMethod, Scaleform::GFx::Value a1, bool a2); // "updateEntity"
};
struct Unk_HpCfgFloat { char m_pad[0x58]; };
struct Unk_HpCfg
{
    char m_pad_0000[0x2c8];
    Unk_HpCfgFloat m_2c8;
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
class Unk_HpUIScale;
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: was FUN_14025e7a0
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    float FUN_1422afec0(int);
};
NiPoint3* FUN_140ad0c10(NiPoint3* pt, float f);                             // efd::Point3::operator*=
float FUN_1412762d0(const NiPoint3& pt);
extern template CString StringFormat<int>(const char*, const int&);
float FUN_140bf4fd0(float f);                                               // ceilf
bool FUN_140930110(int nActorId);
class Unk_HpNpc : public PCBase
{
public:
};
class Unk_HpPet : public CPet { };
struct Unk_HpSeatPos : Unk_GVec3 {};                                    // the returned seat position (copied out through Unk_GVec3)
class Unk_HpSeat { public: Unk_HpSeatPos FUN_140adf8e0(); };
class RideeData { public: struct Rider : public CPtred { char m_pad[0x68 - sizeof(CPtred)]; int m_68; }; };
class CRideeData { public: Unk_SocketPtr<RideeData::Rider> FUN_140784970(); };   // C3: member view
class Unk_RideeData : public CPtred { };
class Ridee : public PCBase { public: MS2Ptr<Unk_RideeData> GetData(); };   // C3: member view
// An actor (pc, npc, pet) with the non-virtual accessors this unit calls.
class MyPC { public: int FUN_1415278d0(void* p); };   // C3: member view (mypc.h needs CHomePrivilege)
class Unk_HpActor : public PC
{
public:
};
struct Unk_HpCfgData { char m_pad[0xa]; bool m_a; char m_b; bool m_c; char m_d; bool m_e; };
class Unk_HpWorld;
class Unk_HpUIMgr { public: };
template <class T> T* Unk_SSGGetDialog(int nUiId);
template <> bool MS2Ptr<ASGameEntity>::operator!() const;                   // 0x140ede6c0
UITombStoneBar* FUN_141994a90(int nUiId);
UISlimeEventBar* FUN_1419949f0(int nUiId);

// @0x141991700
UIHpBar::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : TimerEntity(nLayer, clip, nActorId)
{
    m_a0 = 0;
    m_a8 = 0;
    m_b0 = 0;
    m_b4 = -1;
    m_b8 = 0;
    m_bc = 0;
    m_c0 = 0;
    m_c4 = 100;
    m_54 = reinterpret_cast<Common::Constants::Value<float>*>(&((struct Unk_HpCfg*)FUN_1401d3200())->m_2c8)->Read();
    FUN_141992680();
    FUN_141992580();
}

// @0x141991810
UIHpBar::Entity::~Entity()
{
}

// @0x141991840
void UIHpBar::Entity::vfunc_3()
{
    TimerEntity::vfunc_3();
    vfunc_7();
}

// @0x141991870
void UIHpBar::Entity::vfunc_4()
{
    UIHudEntity::Entity::vfunc_4();
    m_a0 = 0;
    m_a8 = 0;
    m_b0 = 0;
    m_b4 = -1;
    m_b8 = 0;
    m_bc = 0;
    m_c0 = 0;
}

// @0x141991900
void UIHpBar::Entity::vfunc_5()
{
    UIHudEntity::Entity::vfunc_5();
    FUN_141992680();
    FUN_141992580();
    if (m_38.get())
    {
        ((Unk_HpClip*)m_38.operator->())->FUN_141994c00("open", m_a0, m_a8, m_b0, m_b4);
        if (MS2Ptr<ASMovieClip> guide = m_38->FUN_1409b4560("m_guideHp"))
            m_c0 = guide->FUN_1422c1340();
    }
}

// @0x141991a80
void UIHpBar::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get())
    {
        MS2Ptr<ASMovieClip> render = m_38->FUN_1409b4560("m_renderHp");
        if (render.get())
        {
            if (m_bc != 0)
            {
                if (0 < m_64)
                    m_68.FUN_140868750(m_64);
                float fRate = (float)m_a0 / (float)m_a8;
                ((Unk_HpMovie*)render.operator->())->SetWidthInt((int)(fRate * (float)m_c0));
                m_bc = 0;
            }
            if (FUN_141992580() != 0)
            {
                const char* szLabel;
                if (m_b4 == 1)
                    szLabel = "friendly";
                else
                    szLabel = "hostile";
                ((Unk_HpMovie*)render.operator->())->vfunc_15(szLabel);
            }
            FUN_140ad0c10(pPos, ((class GFxManager*)(class Unk_HpUIScale*)(((class Unk_HpUIScale*)FUN_14025e7a0())))->FUN_1422afec0(m_18));
            pPos->y = pPos->y + vfunc_9();
            pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
            ((Unk_HpClip*)m_38.operator->())->SetPositionFloat(pPos->x, pPos->y);
        }
    }
}

// @0x141991d40
void UIHpBar::Entity::vfunc_7()
{
    if (m_38.get())
        m_38->vfunc_3(0);
}

// @0x141991da0
int UIHpBar::Entity::vfunc_8(int n)
{
    if (FUN_1419923f0() == 0)
        return 1;
    Unk_HpActor* pActor = (Unk_HpActor*)FUN_140f49330();
    if (pActor == 0)
        return 1;
    if (m_b8 == 0)
        return 1;
    int nDead = pActor->IsDead();
    if (nDead != 0)
        return 1;
    Unk_HpPet* pPet = reinterpret_cast<Unk_HpPet*>(efd::DynamicCast<CPet, PCBase>(pActor));
    if (pPet != 0 && pPet->GetKind() != 0)
        return 1;
    Unk_HpActor* pPc = reinterpret_cast<Unk_HpActor*>(efd::DynamicCast<PC, PCBase>(pActor));
    if (pPc != 0)
    {
        Unk_HpActor* pLocal = ((class Unk_HpActor*)((class WorldService*)(class Unk_HpWorld*)(reinterpret_cast<Unk_HpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
        if (pLocal != 0 && pLocal->vfunc_122(pPc) == 1 && pPc->FUN_141674bc0() != 0)
            return 1;
        Ridee* pHolder = reinterpret_cast<Ridee*>(pActor->FUN_1416764a0());
        if (pHolder != 0)
        {
            MS2Ptr<Unk_RideeData> spMount = pHolder->GetData();
            bool bMounted = (bool)spMount.get() && reinterpret_cast<CRideeData*>(spMount.operator->())->FUN_140784970().operator->()->m_68 != 0;
            if (bMounted)
                return 1;
        }
        if (pPc->FUN_14165ef30() == 1)
        {
            if (pPc->FUN_141674bc0() == 0)
                return 0;
            else
                return 1;
        }
        if (pActor->vfunc_65() != 0)
            return 0;
        if (pActor->FUN_141670a30(4) != pActor->FUN_141670a00(4))
            return 0;
    }
    else
    {
        Unk_HpNpc* pNpc = reinterpret_cast<Unk_HpNpc*>(efd::DynamicCast<CNpc, PCBase>(pActor));
        if (pNpc != 0)
        {
            if (reinterpret_cast<CNpc*>(pNpc)->GetNpcData()->HasPropertyTag(2))
                return 0;
        }
    }
    return TimerEntity::vfunc_8(nDead);
}

// @0x141992100
float UIHpBar::Entity::vfunc_9()
{
    Unk_HpActor* pActor = (Unk_HpActor*)FUN_140f49330();
    if (pActor == 0)
        return 0.0f;
    return pActor->FUN_141670390();
}

// @0x141992140
void UIHpBar::Entity::FUN_141992140(int n)
{
    m_b8 = n;
}

// @0x141992160
int UIHpBar::Entity::FUN_141992160()
{
    return m_b8;
}

// @0x141992180
void UIHpBar::Entity::FUN_141992180(__int64 nCur, __int64 nMax)
{
    int bChanged;
    if (m_bc == 0 && m_a0 == nCur && m_a8 == nMax)
        bChanged = 0;
    else
        bChanged = 1;
    m_bc = bChanged;
    m_a0 = nCur;
    m_a8 = nMax;
    FUN_140f49470();
    vfunc_2();
}

// @0x141992230
void UIHpBar::Entity::FUN_141992230(__int64 nCur, __int64 nMax)
{
    int bChanged = (m_bc == 0 && m_a0 == nCur && m_a8 == nMax) ? 0 : 1;
    m_a0 = nCur;
    m_a8 = nMax;
    if (m_4c != 0 && bChanged)
        m_bc = 1;
    if (bChanged)
    {
        const efd::ClassInfo* pInfo;
        if (FUN_140f49330() != 0)
            pInfo = FUN_140f49330()->GetClassDesc();
        else
            pInfo = 0;
        if (efd::ClassInfo::IsKindOf(pInfo, 0x6200003))
        {
            m_bc = 1;
            FUN_141992140(1);
            if (nCur == nMax)
            {
                m_68.FUN_140868820();
                m_64 = 2000;
            }
            else
            {
                m_68.FUN_140868820();
                m_64 = 0;
            }
        }
    }
}

// @0x1419923b0
void UIHpBar::Entity::FUN_1419923b0()
{
    ((Unk_HpClip*)m_38.operator->())->SetScaleFloat(100.0f, 100.0f);
}

// @0x1419923f0
int UIHpBar::Entity::FUN_1419923f0()
{
    Unk_HpActor* pLocal = ((class Unk_HpActor*)((class WorldService*)(class Unk_HpWorld*)(reinterpret_cast<Unk_HpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pLocal == 0)
        return 0;
    Unk_HpActor* pActor = (Unk_HpActor*)FUN_140f49330();
    if (pActor == 0)
        return 0;
    const efd::ClassInfo* pInfo;
    if (pActor != 0)
        pInfo = pActor->GetClassDesc();
    else
        pInfo = 0;
    if (efd::ClassInfo::IsKindOf(pInfo, 0x6200004))
    {
        return reinterpret_cast<Unk_HpCfgData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_a;
    }
    else
    {
        Unk_HpActor* pPc = reinterpret_cast<Unk_HpActor*>(efd::DynamicCast<PC, PCBase>(pActor));
        if (pPc != 0)
        {
            if (pLocal->vfunc_122(pPc) != 0)
                return reinterpret_cast<Unk_HpCfgData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_e;
            if (reinterpret_cast<MyPC*>(pLocal)->FUN_1415278d0((void*)pPc->FUN_141656a80()) == 0)
                return 0;
            return reinterpret_cast<Unk_HpCfgData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_c;
        }
        else
        {
            Unk_HpNpc* pNpc = reinterpret_cast<Unk_HpNpc*>(efd::DynamicCast<CNpc, PCBase>(pActor));
            if (pNpc != 0)
            {
                if (pNpc->vfunc_116() == 2)
                    return reinterpret_cast<Unk_HpCfgData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_c;
                return reinterpret_cast<Unk_HpCfgData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_e;
            }
        }
    }
    return 1;
}

// @0x141992580
int UIHpBar::Entity::FUN_141992580()
{
    Unk_HpActor* pActor = (Unk_HpActor*)FUN_140f49330();
    if (pActor == 0)
        return 0;
    int nOld = m_b4;
    if (pActor != 0)
    {
        Unk_HpActor* pLocal = ((class Unk_HpActor*)((class WorldService*)(class Unk_HpWorld*)(reinterpret_cast<Unk_HpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
        if (pLocal != 0)
        {
            if (pLocal->FUN_14123c580() == pActor->FUN_14123c580())
                m_b4 = 1;
            else
                m_b4 = pLocal->vfunc_122(pActor) != 0 ? 0 : 1;
            if (nOld != m_b4)
                return 1;
        }
    }
    return 0;
}

// @0x141992680
void UIHpBar::Entity::FUN_141992680()
{
    Unk_HpActor* pPc = reinterpret_cast<Unk_HpActor*>(efd::DynamicCast<PC, PCBase>(FUN_140f49330()));
    if (pPc != 0)
    {
        if (pPc->FUN_14165ef30() != 0)
            m_b0 = (unsigned short)m_c4;
        else
            m_b0 = 1;
    }
    else
    {
        Unk_HpNpc* pNpc = reinterpret_cast<Unk_HpNpc*>(efd::DynamicCast<CNpc, PCBase>(FUN_140f49330()));
        if (pNpc != 0)
        {
            NpcDataCli* pData = reinterpret_cast<CNpc*>(pNpc)->GetNpcData().get();
            if (pData != 0)
            {
                m_b0 = pData->GetClass();
                if (reinterpret_cast<CNpc*>(pNpc)->GetNpcData()->HasPropertyTag(1))
                    m_b0 = 10;
            }
        }
    }
}

// @0x1419927f0
UIHpBar::UIHpBar()
{
    m_70 = "hpbar_entity_HPBar";
}

// @0x141992860
UIHpBar::~UIHpBar()
{
}

// @0x1419928a0
CString UIHpBar::GetTypeName()
{
    return CString("HpBar");
}

// @0x1419928f0
void UIHpBar::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_141993790(m_68);
}

// @0x141992920
MS2Ptr<UIHpBar::Entity> FUN_141992920(int nActorId)
{
    UIHpBar* pBar = Unk_SSGGetDialog<UIHpBar>(0x4e36);
    if (pBar != 0)
    {
        MS2Ptr<UIHpBar::Entity> pEntity(pBar->FUN_141993d30(nActorId));
        if (pEntity.get())
            pEntity->FUN_1419923b0();
        return pEntity;
    }
    return MS2Ptr<UIHpBar::Entity>(0);
}

// @0x1419929f0
void FUN_1419929f0(int nActorId)
{
    UIHpBar* pBar = Unk_SSGGetDialog<UIHpBar>(0x4e36);
    if (pBar)
        pBar->FUN_140f49c00(nActorId);
}

// @0x141992a30
UITombStoneBar::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : UIHpBar::Entity(nLayer, clip, nActorId)
{
    m_c8 = 5;
    m_cc = 5;
}

// @0x141992aa0
UITombStoneBar::Entity::~Entity()
{
}

// @0x141992ad0
void UITombStoneBar::Entity::vfunc_5()
{
    UIHpBar::Entity::vfunc_5();
    if (m_38.get())
        m_38->FUN_1422bb870().GotoAndPlay("start");
}

// @0x141992b30
void UITombStoneBar::Entity::vfunc_6(NiPoint3* pPos)
{
    if (!m_38)
        return;
    FUN_140ad0c10(pPos, ((class GFxManager*)(class Unk_HpUIScale*)(((class Unk_HpUIScale*)FUN_14025e7a0())))->FUN_1422afec0(m_18));
    pPos->y = pPos->y + vfunc_9();
    pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
    ((Unk_HpClip*)m_38.operator->())->SetPositionFloat(pPos->x, pPos->y - 35.0f);
}

// @0x141992c30
int UITombStoneBar::Entity::vfunc_8(int n)
{
    Unk_HpActor* pPc = reinterpret_cast<Unk_HpActor*>(efd::DynamicCast<PC, PCBase>(FUN_140f49330()));
    if (pPc == 0)
        return 1;
    if (m_50 != 0)
        return 0;
    if (pPc->IsDead() == 0)
        return 1;
    Unk_HpActor* pLocal = ((class Unk_HpActor*)((class WorldService*)(class Unk_HpWorld*)(reinterpret_cast<Unk_HpWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pLocal != 0 && pLocal->vfunc_122(pPc) != 0)
        return 1;
    if (pPc->IsRevivalBlocked() != 0 || pPc->FUN_14165ca20() == 0)
        return 1;
    if (m_60 == 0 && m_68.FUN_140868ba0() == 0)
        return 1;
    if (FUN_140f48e20() > m_54)
        return 1;
    return 0;
}

// @0x141992d50
NiPoint3 UITombStoneBar::Entity::vfunc_10()
{
    PC* pPc = dynamic_cast<PC*>(FUN_140f49330());
    if (pPc != 0)
    {
        Unk_HpSeat* pSeat = reinterpret_cast<Unk_HpSeat*>(((Unk_HpActor*)pPc)->FUN_14165ca20());
        if (pSeat != 0)
        {
            NiPoint3 base = UIHudEntity::Entity::vfunc_10();
            Unk_GVec3 pos(pSeat->FUN_140adf8e0());
            pos.z = base.z;
            return *(NiPoint3*)&pos;
        }
    }
    return UIHudEntity::Entity::vfunc_10();
}

// @0x141992e40
void UITombStoneBar::Entity::FUN_141992e40()
{
    m_cc = 5;
    m_c8 = 5;
    FUN_141992140(1);
    FUN_140f49470();
    vfunc_2();
}

// @0x141992ea0
void UITombStoneBar::Entity::FUN_141992ea0(int nHit, int nMax)
{
    if (m_38.get())
    {
        m_c8 = nHit;
        m_cc = nMax;
        const int nStages = 5;
        int nMaxHits = m_cc;
        int nOne = 1;
        float fStep = 5.0f / (float)std::max<int>(nOne, nMaxHits);
        int nStage = (int)FUN_140bf4fd0(fStep * (float)m_c8);
        if (nStage >= nStages)
            return;
        CString strLabel = StringFormat("hit{0}", nStage);
        m_38.operator->()->FUN_1422bb870().GotoAndPlay(strLabel);
    }
}

// @0x141992fd0
UITombStoneBar::UITombStoneBar()
{
    m_70 = "tombGaugeBar";
}

// @0x141993040
UITombStoneBar::~UITombStoneBar()
{
}

// @0x141993080
CString UITombStoneBar::GetTypeName()
{
    return CString("TombGaugeBar");
}

// @0x1419930d0
void UITombStoneBar::OnLoadComplete()
{
    UIHpBar::OnLoadComplete();
    FUN_141993b50(m_68);
}

// @0x141993100
MS2Ptr<UITombStoneBar::Entity> FUN_141993100(int nActorId)
{
    UITombStoneBar* pBar = FUN_141994a90(0x4e64);
    if (pBar != 0)
        return MS2Ptr<UITombStoneBar::Entity>(pBar->FUN_1419945b0(nActorId));
    return MS2Ptr<UITombStoneBar::Entity>(0);
}

// @0x141993180
void FUN_141993180(int nActorId)
{
    UITombStoneBar* pBar = FUN_141994a90(0x4e64);
    if (pBar)
        pBar->FUN_140f49c00(nActorId);
}

// @0x1419931c0
UISlimeEventBar::Entity::Entity(int nLayer, const Scaleform::GFx::Value& clip, int nActorId)
    : UIHpBar::Entity(nLayer, clip, nActorId), m_c8(0), m_cc(0), m_d0(*(const Unk_GVec3*)&efd::Point3::ZERO)
{
}

// @0x141993260
UISlimeEventBar::Entity::~Entity()
{
}

// @0x141993290
void UISlimeEventBar::Entity::vfunc_5()
{
    UIHpBar::Entity::vfunc_5();
}

// @0x1419932b0
void UISlimeEventBar::Entity::vfunc_6(NiPoint3* pPos)
{
    if (m_38.get())
    {
        FUN_140ad0c10(pPos, ((class GFxManager*)(class Unk_HpUIScale*)(((class Unk_HpUIScale*)FUN_14025e7a0())))->FUN_1422afec0(m_18));
        pPos->y = pPos->y + vfunc_9();
        pPos->y = pPos->y + FUN_1412762d0(vfunc_10());
        ((Unk_HpClip*)m_38.operator->())->SetPositionFloat(pPos->x, pPos->y - 35.0f);
    }
}

// @0x1419933b0
int UISlimeEventBar::Entity::vfunc_8(int n)
{
    return UIHpBar::Entity::vfunc_8(n);
}

// @0x1419933e0
void UISlimeEventBar::Entity::FUN_1419933e0()
{
    FUN_141992140(1);
    FUN_140f49470();
    vfunc_2();
}

// @0x141993420
void UISlimeEventBar::Entity::FUN_141993420(unsigned int nX, unsigned int nY, int nCur, int nMax)
{
    if (m_38.get())
    {
        m_cc = nMax;
        m_c8 = nCur < nMax ? nCur : nMax;
        ((Unk_HpClip*)m_38.operator->())->FUN_141994b30("setArrow", nX, nY, m_cc);
        ((Unk_HpClip*)m_38.operator->())->FUN_1409ba0d0("setValue", m_c8, m_cc);
    }
}

// @0x141993560
int UISlimeEventBar::Entity::FUN_141993560()
{
    if (m_cc == 0)
        return 0;
    if (m_c8 == m_cc)
        return 1;
    return 0;
}

// @0x1419935a0
UISlimeEventBar::UISlimeEventBar()
{
    m_70 = "slimeEventBar";
}

// @0x141993610
UISlimeEventBar::~UISlimeEventBar()
{
}

// @0x141993650
CString UISlimeEventBar::GetTypeName()
{
    return CString("SlimeEventBar");
}

// @0x1419936a0
void UISlimeEventBar::OnLoadComplete()
{
    UIHpBar::OnLoadComplete();
    FUN_141993970(m_68);
}

// @0x1419936d0
MS2Ptr<UISlimeEventBar::Entity> FUN_1419936d0(int nActorId)
{
    UISlimeEventBar* pBar = FUN_1419949f0(0x4e65);
    if (pBar != 0)
        return MS2Ptr<UISlimeEventBar::Entity>(pBar->FUN_141994170(nActorId));
    return MS2Ptr<UISlimeEventBar::Entity>(0);
}

// @0x141993750
void FUN_141993750(int nActorId)
{
    UISlimeEventBar* pBar = FUN_1419949f0(0x4e65);
    if (pBar)
        pBar->FUN_140f49c00(nActorId);
}

// @0x141993790
void UIHpBar::FUN_141993790(unsigned int nCount)
{
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        for (unsigned int i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value v = pClip->Invoke("createCache", m_70);
            if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() == 0)
            {
                UIHpBar::Entity* p = new UIHpBar::Entity(m_28, v, 0);
                if (p)
                {
                    MS2Ptr<UIHudEntity::Entity> sp(p);
                    m_78.AddTail(sp);
                }
            }
        }
    }
}

// @0x141993970
void UISlimeEventBar::FUN_141993970(unsigned int nCount)
{
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        for (unsigned int i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value v = pClip->Invoke("createCache", m_70);
            if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() == 0)
            {
                UISlimeEventBar::Entity* p = new UISlimeEventBar::Entity(m_28, v, 0);
                if (p)
                {
                    MS2Ptr<UIHudEntity::Entity> sp(p);
                    m_78.AddTail(sp);
                }
            }
        }
    }
}

// @0x141993b50
void UITombStoneBar::FUN_141993b50(unsigned int nCount)
{
    MS2Ptr<ASGameEntity> pClip(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pClip.get())
    {
        for (unsigned int i = 0; i < nCount; i++)
        {
            Scaleform::GFx::Value v = pClip->Invoke("createCache", m_70);
            if (((Scaleform::GFx::Value*)(void*)(&v))->IsUndefined() == 0)
            {
                UITombStoneBar::Entity* p = new UITombStoneBar::Entity(m_28, v, 0);
                if (p)
                {
                    MS2Ptr<UIHudEntity::Entity> sp(p);
                    m_78.AddTail(sp);
                }
            }
        }
    }
}

// @0x141993d30
UIHpBar::Entity* UIHpBar::FUN_141993d30(int nActorId)
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
            Scaleform::GFx::Value v = ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                            ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_HpClip*)pOldClip.operator->())->FUN_1422bb870(), bNew);
                    }
                }
                pEntity->FUN_140f48ce0(nActorId);
                m_a8.SetAt(nActorId, pEntity);
                return (UIHpBar::Entity*)pEntity.get();
            }
        }
    }
    }
    return 0;
}

// @0x141994170
UISlimeEventBar::Entity* UISlimeEventBar::FUN_141994170(int nActorId)
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
            Scaleform::GFx::Value v = ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                            ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_HpClip*)pOldClip.operator->())->FUN_1422bb870(), bNew);
                    }
                }
                pEntity->FUN_140f48ce0(nActorId);
                m_a8.SetAt(nActorId, pEntity);
                return (UISlimeEventBar::Entity*)pEntity.get();
            }
        }
    }
    }
    return 0;
}

// @0x1419945b0
UITombStoneBar::Entity* UITombStoneBar::FUN_1419945b0(int nActorId)
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
            Scaleform::GFx::Value v = ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9470("createEntity", nActorId, m_70, bFlag);
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
                            ((Unk_BannerClip*)pClip.operator->())->FUN_140ba9570("updateEntity", ((Unk_HpClip*)pOldClip.operator->())->FUN_1422bb870(), bNew);
                    }
                }
                pEntity->FUN_140f48ce0(nActorId);
                m_a8.SetAt(nActorId, pEntity);
                return (UITombStoneBar::Entity*)pEntity.get();
            }
        }
    }
    }
    return 0;
}

// @0x1419949f0
UISlimeEventBar* FUN_1419949f0(int nUiId)
{
    if (reinterpret_cast<Unk_HpUIMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (p.get())
            return dynamic_cast<UISlimeEventBar*>((UIObject*)p);
    }
    return 0;
}

// @0x141994a90
UITombStoneBar* FUN_141994a90(int nUiId)
{
    if (reinterpret_cast<Unk_HpUIMgr*>(TSingleton<CUIService>::GetInstance()))
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (p.get())
            return dynamic_cast<UITombStoneBar*>((UIObject*)p);
    }
    return 0;
}

// @0x141994b30
Scaleform::GFx::Value Unk_HpClip::FUN_141994b30(const char* szMethod, unsigned int a1, unsigned int a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141994c00
Scaleform::GFx::Value Unk_HpClip::FUN_141994c00(const char* szMethod, __int64 a1, __int64 a2, unsigned short a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcdd0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcdd0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ?vfunc_48@UIHpBar@@UEAAHXZ 0x141994f40
// MS2-PIN: ?vfunc_48@UISlimeEventBar@@UEAAHXZ 0x141994f50
// MS2-PIN: ?vfunc_48@UITombStoneBar@@UEAAHXZ 0x141994f60
// MS2-PIN: ?GotoAndPlay@Value@GFx@Scaleform@@QEAA_NPEBD@Z 0x141994f70

MS2_EMIT_CRT_MEMMOVE_S();
