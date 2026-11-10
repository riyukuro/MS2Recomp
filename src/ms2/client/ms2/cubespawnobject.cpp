// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See cubespawnobject.h.
// MS2-UNIT: ?\cubespawnobject.cpp
// MS2-RANGE: 0x140a4e690-0x140a50440 .text$mn
// MS2-RANGE: 0x1400c3a20-0x1400c3bb0 .text$di
// MS2-RANGE: 0x142c9f2b0-0x142c9f340 .text$yd
// MS2-PIN: ??0?$MS2Ptr@VUnk_HpBarFx@@@@QEAA@H@Z 0x140a4fc50
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCStateManager@@@@QEAAAEAV1@PEAVCStateManager@@@Z 0x140a4fd30
// MS2-PIN: ??4?$MS2Ptr@VUnk_HpBarFx@@@@QEAAAEAV0@AEBV0@@Z 0x140a4fde0
// MS2-PIN: ?get@?$MS2Ptr@VNpcDataCli@@@@QEBAPEAVNpcDataCli@@XZ 0x140a4ff10
// MS2-PIN: ??C?$MS2Ptr@VCStateManager@@@@QEBAPEAVCStateManager@@XZ 0x140a4ff20
// MS2-PIN: ?vfunc_114@PCBase@@UEAAXPEAX@Z 0x140a4ffb0
// MS2-PIN: ?GetClassDesc@CubeSpawnObject@@UEBAPEBVClassInfo@efd@@XZ 0x140a50000
// MS2-PIN: ?TypeCast@CubeSpawnObject@@UEBA_NIPEAPEAX@Z 0x140a500c0
// MS2-PIN: ?TypeCast@CubeSpawnObject@@UEBA_NIPEAPEBX@Z 0x140a50110
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_HpBarFx@@@@AEBAXXZ 0x140a501c0
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCStateManager@@@@AEBAXPEAX@Z 0x140a50260
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_HpBarFx@@@@AEBAXPEAX@Z 0x140a502c0
// MS2-PIN: ??_7CubeSpawnObject@@6BIBase@efd@@@ 0x142dc7b40
// MS2-PIN: ??_7CubeSpawnObject@@6BCallbackObject@NiActorManager@@@ 0x142dc7f30
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubespawnobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cubespawnobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/client/ms2/effectservice.h"
#include <egf/Entity.h>   // C3: egf::Entity::GetPropertyValue<efd::Point3>
#include "ms2/placeholder/clientconstants.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/client/ms2/uihpbar.h"
#include "ms2/client/ms2/emotiondata.h"
#include "ms2/commonfiles/talkscript.h"
#include "ms2/client/ms2/effectdummy.h"   // C3: std::vector<CEffectDummy> (the npc row part list)
#include <vector>

// ---- unit-local placeholders ----

class Unk_NpcTableCli* GetNpcDataTableCli();   // C3: was GetNpcDataTableCli

// MS2Ptr<NpcDataCli> members instantiated by earlier objs (the rest are this obj's COMDATs).
template <> void MS2Ptr<NpcDataCli>::Reference(NpcDataCli* p);         // 0x1406d9f40
template <> void MS2Ptr<NpcDataCli>::Release();                          // 0x1406db080
template <> MS2Ptr<NpcDataCli>::~MS2Ptr();                               // 0x1406d5390
template <> NpcDataCli* MS2Ptr<NpcDataCli>::operator->() const;         // 0x140965990
template <> bool MS2Ptr<NpcDataCli>::operator==(NpcDataCli* p) const;   // 0x1409f90f0

#include "ms2/client/ms2/uichatballoon.h"   // the chat balloon component (GetChatBalloonEntity(object id))
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int vfunc_8(int n);                                     // can show a balloon
};
MS2Ptr<UIChatBalloon::Entity> GetChatBalloonEntity(int nObjectId);
template <> void MS2Ptr<Unk_PCBaseComp_aa8>::Reference(Unk_PCBaseComp_aa8* p);   // 0x1405aaca0
template <> void MS2Ptr<Unk_PCBaseComp_aa8>::Release();                          // 0x1405ab4d0
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40

// Housing object gauge effect.
class Unk_HpBarFx : public CPtred
{
};
MS2Ptr<UISlimeEventBar::Entity> GetSlimeEventBarEntity(int nObjectId);   // C3: the real return type (uihpbar.h)
void FUN_141993750(int nObjectId);

class Unk_Entity
{
public:
};

// The state machine and the two states this actor registers.
class CStateManager : public CPtred
{
public:
    CStateManager(PCBase* pOwner);                                  // 0x1417da7a0
    void RegisterState(int nId, class State* pState);        // AddState
private:
    char m_pad_18[0x98 - 0x18];
};
class Unk_CsoState
{
    char m_pad[0x40];
};
class StateIdleSpawnObject : public Unk_CsoState
{
public:
    StateIdleSpawnObject(CubeSpawnObject* pOwner);                  // 0x140ac1e20
private:
    char m_pad_40[8];
};
class StateInterActionSpawnObject : public Unk_CsoState
{
public:
    StateInterActionSpawnObject(CubeSpawnObject* pOwner);           // 0x140ac1c30
};

// Talk scripts (FUN_140856fa0(npc id, n)).
typedef ATL::CAtlArray<Unk_TalkContentPtr<CScriptContent> > Unk_ScriptContentArray;
Unk_ScriptPtr<CTalkScript> FUN_140856fa0(int nNpcId, int n);

// Common::Constants::Value<T>::Get, header-inline in the original.
// @0x140a50020
template <> inline CStringW* Common::Constants::Value<CStringW>::Get()
{
    if (!m_defined)
        Error("constants is not set");
    return &m_value;
}
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

void* GetGameRule();

class COptimizer   // C3: member view (coptimizer.h)
{
public:
    int FUN_1409f7ea0();
};
class Unk_AvModeSvc* GetOptimizer();   // C3: was GetOptimizer


class Unk_CsoSpawnMgr
{
public:
};
class CEmotionManager;
// @0x140a50010
inline Unk_CsoSpawnMgr* GetEmotionManager() { return reinterpret_cast<Unk_CsoSpawnMgr*>(TSingleton<CEmotionManager>::s_instance); }

CString FUN_1409a2360(const char* psz, int n);
CStringW FUN_1401aa6a0(int nId);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CubeSpawnObject);

// ---- the unit's header statics ----
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140a4e690
CubeSpawnObject::CubeSpawnObject()
    : m_nAnimState(0), m_pD48(0), m_mapAnim(17, .75f, .25f, 2.25f, 10), m_spNpc(0), m_entity(0), m_spFx(0),
      m_nGaugeA(300), m_nGaugeB(500), m_strOwner(L"")
{
    m_str88 = "GameObject";
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->RegisterState(1, reinterpret_cast<State*>(new StateIdleSpawnObject(this)));
    m_spStateMgr->RegisterState(0x19, reinterpret_cast<State*>(new StateInterActionSpawnObject(this)));
    m_f164 = reinterpret_cast<Common::Constants*>(GetClientConstants())->OffsetNpcHpbar.Read();
    m_f168 = reinterpret_cast<Common::Constants*>(GetClientConstants())->OffsetNpcChatballoon.Read();
    m_f16c = reinterpret_cast<Common::Constants*>(GetClientConstants())->OffsetNpcNametag.Read();
    m_f170 = 0.0f;
    m_f174 = 0.0f;
    m_f178 = reinterpret_cast<Common::Constants*>(GetClientConstants())->OffsetNpcDamagenumber.Read();
    m_mapAnim.SetAt(0x5a, "Idle_A");
    m_mapAnim.SetAt(0x62, "Grow_A");
    m_mapAnim.SetAt(99, "Full_A");
    m_mapAnim.SetAt(100, "Gift_A");
    m_mapAnim.SetAt(0x65, "Play_A");
    m_mapAnim.SetAt(0x66, "Hungry_A");
    m_mapAnim.SetAt(0x67, "Eat_A");
}

// @0x140a4ebe0
CubeSpawnObject::~CubeSpawnObject()
{
    m_spNpc = 0;
    reinterpret_cast<egf::EntityPtr&>(m_entity) = (egf::Entity*)0;
    if (m_spFx.get())
    {
        FUN_141993750(GetObjectId());
        m_spFx = 0;
    }
}

// @0x140a4ed00
int CubeSpawnObject::vfunc_124(int nNpcId, egf::EntityPtr ent, int nGaugeA, int nGaugeB, const CStringW& strOwner)
{
    m_spNpc = reinterpret_cast<NpcDataTableCli*>(GetNpcDataTableCli())->Find(nNpcId);
    if (m_spNpc == NULL)
        return 0;
    reinterpret_cast<egf::EntityPtr&>(m_entity) = reinterpret_cast<egf::EntityPtr&>(ent);
    m_nGaugeA = nGaugeA;
    m_nGaugeB = nGaugeB;
    m_strOwner = strOwner;
    CString strPath;
    strPath.Format("urn:gamebryo-animation:%s", (const char*)m_spNpc->m_model.m_strKfm);
    SetModelPath(strPath);
    m_fScaleAC = m_spNpc->m_model.m_fScale;
    SetScale(m_spNpc->m_model.m_fScale);
    CStringW strName = FUN_1401aa6a0(m_spNpc->GetId());
    if (!strName.IsEmpty())
    {
        if (m_spNpc->GetNametag())
            vfunc_76(strName);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140a4ed00, CubeSpawnObject, vfunc_124, 700, 0x45FDEF8A);

// @0x140a4efd0
int CubeSpawnObject::vfunc_116()
{
    return 1;
}

// @0x140a4eff0
int CubeSpawnObject::vfunc_69()
{
    if (m_spNpc == NULL)
        return 0;
    if (m_spNpc->m_nEmotionId != 0)
        return m_spNpc->m_nEmotionId;
    return m_spNpc->GetId();
}
MS2_REPLACE_METHOD(0x140a4eff0, CubeSpawnObject, vfunc_69, 128, 0xCE493C67);

// @0x140a4f080
Unk_PCBaseFxLib* CubeSpawnObject::vfunc_70()
{
    return reinterpret_cast<Unk_PCBaseFxLib*>(reinterpret_cast<CEmotionManager*>(GetEmotionManager())->GetNpcTable());
}
MS2_REPLACE_METHOD(0x140a4f080, CubeSpawnObject, vfunc_70, 27, 0xC7E44435);

// @0x140a4f0b0
MS2Ptr<Unk_PCBaseComp_aa8> CubeSpawnObject::vfunc_85()
{
    if (((class COptimizer*)GetOptimizer())->FUN_1409f7ea0() && !FUN_14123dbd0())
        return MS2Ptr<Unk_PCBaseComp_aa8>(0);
    if (m_spAA8 == NULL)
        m_spAA8 = reinterpret_cast<const MS2Ptr<Unk_PCBaseComp_aa8>&>(static_cast<const MS2Ptr<UIChatBalloon::Entity>&>(GetChatBalloonEntity(m_unk_70)));
    return m_spAA8;
}
MS2_REPLACE_METHOD(0x140a4f0b0, CubeSpawnObject, vfunc_85, 236, 0x2B063CFF);

// @0x140a4f1b0
MS2Ptr<NpcDataCli> CubeSpawnObject::GetNpc()
{
    return m_spNpc;
}
MS2_REPLACE_METHOD(0x140a4f1b0, CubeSpawnObject, GetNpc, 67, 0x3741EA17);

// @0x140a4f200
void CubeSpawnObject::FUN_140a4f200(void* p)
{
    m_pD48 = p;
}
MS2_REPLACE_METHOD(0x140a4f200, CubeSpawnObject, FUN_140a4f200, 28, 0x3CB6144A);

// @0x140a4f230
void CubeSpawnObject::FUN_140a4f230(int a, int b)
{
    if (m_spFx.get())
        reinterpret_cast<UISlimeEventBar::Entity*>(m_spFx.operator->())->FUN_141993420(m_nGaugeA, m_nGaugeB, a, b);
}
MS2_REPLACE_METHOD(0x140a4f230, CubeSpawnObject, FUN_140a4f230, 110, 0xC1319B93);

// @0x140a4f2b0
void CubeSpawnObject::SetAnimState(unsigned int nState)
{
    CString strAnim("");
    if (m_mapAnim.Lookup(nState, strAnim))
        PlayAnimation(efd::utf8string(FUN_1409a2360(strAnim, 0)), 1.0f, false, false);
    m_nAnimState = nState;
}
MS2_REPLACE_METHOD(0x140a4f2b0, CubeSpawnObject, SetAnimState, 301, 0x4DD60614);

// @0x140a4f3f0
void CubeSpawnObject::FUN_140a4f3f0(int n)
{
    if (m_spNpc == NULL)
        return;
    if (!FUN_140a4f690())
        return;
    Unk_ScriptPtr<CTalkScript> spScript = FUN_140856fa0(m_spNpc->GetId(), n);
    if (spScript.get())
    {
        if (spScript.operator->()->m_contents.GetCount() > 0)
        {
            MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85();
            if (spBalloon.get() ? true : false)
            {
                if (spBalloon->vfunc_8(0))
                {
                    CStringW strText = static_cast<const Unk_ScriptContentArray&>(spScript.operator->()->m_contents).GetAt(0).operator->()->m_text;
                    if (strText.GetLength() > 0)
                        ShowChatBalloon(strText);
                    if (static_cast<const Unk_ScriptContentArray&>(spScript.operator->()->m_contents).GetAt(0).operator->()->m_voiceId.GetLength() > 0)
                        TSingleton<CEffectService>::GetInstance()->PlayVoiceAt(
                            spScript.operator->()->m_contents.GetAt(0).operator->()->m_voiceId,
                            vfunc_18());
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a4f3f0, CubeSpawnObject, FUN_140a4f3f0, 655, 0x7F90AEE9);

// @0x140a4f690
int CubeSpawnObject::FUN_140a4f690()
{
    if (m_strOwner != *reinterpret_cast<Common::Constants*>(GetClientConstants())->NurturingQuestTag.Get())
        return false;
    return ((CGameRule*)GetGameRule())->HasTermTag(*reinterpret_cast<Common::Constants*>(GetClientConstants())->NurturingQuestTag.Get());
}
MS2_REPLACE_METHOD(0x140a4f690, CubeSpawnObject, FUN_140a4f690, 112, 0x1E480BE2);

// @0x140a4f710
void CubeSpawnObject::vfunc_9(void* p)
{
    PCBase::vfunc_9(p);
    if (((egf::Entity*)reinterpret_cast<egf::EntityPtr&>(m_entity) ? true : false) && (m_spNpc.get() ? true : false))
    {
        efd::Point3 kPos = efd::Point3::ZERO;
        efd::Point3 kDir = efd::Point3::ZERO;
        reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(kPos));
        reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(kDir));
        kPos = kPos + reinterpret_cast<const efd::Point3&>(m_spNpc->m_model.m_vOffset);
        vfunc_19(kPos);
        vfunc_21(kDir);
        vfunc_59(1, NULL, 0, 0);
        if (FUN_140a4f690())
        {
            if ((m_spFx = reinterpret_cast<const MS2Ptr<Unk_HpBarFx>&>(static_cast<const MS2Ptr<UISlimeEventBar::Entity>&>(GetSlimeEventBarEntity(GetObjectId())))).get())
            {
                reinterpret_cast<UISlimeEventBar::Entity*>(m_spFx.operator->())->FUN_1419933e0();
                reinterpret_cast<UIHpBar::Entity*>(m_spFx.operator->())->FUN_141992140(FUN_140a4f690());
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140a4f710, CubeSpawnObject, vfunc_9, 718, 0x44CD5478);

// @0x140a4f9f0
void CubeSpawnObject::vfunc_12()
{
    PCBase::vfunc_12();
    for (size_t i = 0; i < m_spNpc->m_effectDummies.size(); i++)
        FUN_141674ef0(m_spNpc->m_effectDummies[i]);
    vfunc_59(1, NULL, 0xa8, 0);
}
MS2_REPLACE_METHOD(0x140a4f9f0, CubeSpawnObject, vfunc_12, 182, 0x080792C4);

// @0x140a4fab0
int CubeSpawnObject::vfunc_11()
{
    if (!GameObject::vfunc_11())
        return 0;
    vfunc_109(0);
    return 1;
}
MS2_REPLACE_METHOD(0x140a4fab0, CubeSpawnObject, vfunc_11, 58, 0x3360C81A);

// @0x140a4faf0
void CubeSpawnObject::vfunc_53(float f)
{
    PCBase::vfunc_53(f);
    if (m_spFx.get())
    {
        if (FUN_140a4f690())
        {
            if (!reinterpret_cast<UIHpBar::Entity*>(m_spFx.operator->())->FUN_141992160())
                reinterpret_cast<UIHpBar::Entity*>(m_spFx.operator->())->FUN_141992140(1);
        }
        else
        {
            if (reinterpret_cast<UIHpBar::Entity*>(m_spFx.operator->())->FUN_141992160())
                reinterpret_cast<UIHpBar::Entity*>(m_spFx.operator->())->FUN_141992140(0);
        }
    }
}
MS2_REPLACE_METHOD(0x140a4faf0, CubeSpawnObject, vfunc_53, 203, 0x5C3E9953);
