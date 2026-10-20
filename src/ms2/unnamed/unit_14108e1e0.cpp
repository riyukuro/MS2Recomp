// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The npc actor: CNpcVibrate (the hit shake, 0x14108e1e0..)
// and CNpc (RTTI CNpc -> PCBase, class id 0x06200028; vftables 0x142ea8b58 / 0x142ea8f68), followed by the COMDAT
// tail of the templates it instantiates. Layout: placeholder/cnpc.h (members 0xd40..0xf40 from the ctor 0x14108e420 /
// dtor 0x14108ef30). CNpc::ms_ClassInfo is registered in unit_1400e53e0. Names are the FUN_<va> / vfunc_<slot>
// spellings of the shared header unless the exe names them.
// MS2-UNIT: unit_14108e1e0
// MS2-RANGE: 0x14108e1e0-0x14109b6b0 .text$mn
// MS2-RANGE: 0x1400e56b0-0x1400e59d0 .text$di
// MS2-RANGE: 0x142cabd60-0x142cabe80 .text$yd
// MS2-PIN: ??_7CNpc@@6BIBase@efd@@@ 0x142ea8b58
// MS2-PIN: ??_7CNpc@@6BCallbackObject@NiActorManager@@@ 0x142ea8f68
// MS2-PIN: ??_7CNpcVibrate@@6B@ 0x142ea8b48
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\npc.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/stateidle.h"
#include "ms2/client/ms2/statewalk.h"
#include "ms2/client/ms2/statedead.h"
#include "ms2/client/ms2/stateskill.h"
#include "ms2/client/ms2/statehit.h"
#include "ms2/client/ms2/statestun.h"
#include "ms2/client/ms2/statetalk.h"
#include "ms2/client/ms2/statespawn.h"
#include "ms2/client/ms2/statesummon.h"
#include "ms2/client/ms2/randomtargeteffect.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class CEffectService;
CEffectService* FUN_1403ed280();                                    // the effect service
void FUN_1411a6060(CEffectService* pService, unsigned int nHandle); // stop an effect
int FUN_140768010(int nMax, int nMin);                              // random integer
float FUN_140768090();                                              // random float in [0, 1)

// ---- unit-local placeholders ----

// The lazily created per-actor components (pcbase.cpp names; the exe types are UIHpBar / UINameTag / UIEmoticon /
// UIBuffBalloon / UIChatBalloon ::Entity).
class Unk_PCBaseComp_a58 : public CPtred
{
public:
    void FUN_141992140(int bShow);
    void FUN_141992180(__int64 nCur, __int64 nMax);
};
class Unk_PCBaseComp_a78 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
    void FUN_141a5e4c0(int nFontSize);
    void FUN_141a5e500(int n);
};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_a98 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred {};
MS2Ptr<Unk_PCBaseComp_a58> FUN_141992920(int nObjectId);           // new hp bar
MS2Ptr<Unk_PCBaseComp_a78> FUN_141a60da0(int nObjectId);           // new name tag
MS2Ptr<Unk_PCBaseComp_a88> FUN_14192fd40(int nObjectId);           // new emoticon
MS2Ptr<Unk_PCBaseComp_a98> FUN_14128ef70(int nObjectId);           // new buff balloon
MS2Ptr<Unk_PCBaseComp_aa8> FUN_1418fbdb0(int nObjectId);           // new chat balloon

// The actor's ground shadow (GameObject +0x58; unit_14160fb10).
class CObjectShadow : public NiRefObject
{
public:
    // @0x14109a720
    bool FUN_14109a720() { return m_bVisible; }
private:
    char m_pad_10[0x35 - sizeof(NiRefObject)];
    bool m_bVisible;                                                // +0x35
};

// The buffs (AdditionalCliList, pcbase.h's Unk_PCBaseBuffs view).
class Unk_PCBaseBuffs
{
public:
    float FUN_140970720();                                          // scale
};

class Unk_CapWorld { public: void FUN_141bc7f10(const egf::EntityID& kId); };    // WorldService
Unk_CapWorld* FUN_1403ed2d0();
class COptimizer { public: int FUN_1409f7ea0(); void FUN_14161d070(const egf::EntityID& kId); };
COptimizer* FUN_1409f7c90();
class Unk_CsoSpawnMgr { public: Unk_PCBaseFxLib* FUN_1411bf1e0(); };
Unk_CsoSpawnMgr* FUN_140a50010();
class CLua { public: float FUN_1406745e0(long long a, float b); };
CLua* FUN_1401c0db0();
int FUN_141092ff0(PCBase* pActor);
bool FUN_14028d470(float a, float b);                               // a != b (with epsilon)
unsigned char FUN_140a7c8d0(NpcDataCli* pData);                     // NpcDataCli::GetNametag
int FUN_140a7c970(NpcDataCli* pData);                               // NpcDataCli::GetClassConstant

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };   // zero-initialised pointer holder (0x1401cd100)

// ---- header statics (two copies: the unit holds two objs' initializers) ----

static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- CNpcVibrate ----

// @0x14108e1e0
CNpcVibrate::CNpcVibrate()
{
    m_nAmp = 0;
    m_nDuration = 0;
    m_nScale = 0;
    m_bActive = 0;
}

// @0x14108e250
CNpcVibrate::~CNpcVibrate()
{
}

// @0x14108e280
int CNpcVibrate::FUN_14108e280()
{
    return m_bActive;
}

// @0x14108e2a0
void CNpcVibrate::FUN_14108e2a0(int nAmp, int nDuration, int nScale)
{
    m_nAmp = nAmp;
    m_nDuration = nDuration;
    m_nScale = nScale;
    m_bActive = 1;
}

// @0x14108e300
void CNpcVibrate::FUN_14108e300(float fTime, efd::Point3& kPos)
{
    if (m_bActive != 0) {
        if ((float)m_nDuration <= fTime) {
            m_bActive = 0;
        } else {
            efd::Point3 kOffset = efd::Point3::ZERO;
            unsigned int nX = FUN_140768010(2, 0);
            unsigned int nY = FUN_140768010(2, 0);
            kOffset.x = FUN_140768090();
            kOffset.x = kOffset.x * ((float)nX - 0.5f) * 2.0f;
            kOffset.y = FUN_140768090();
            kOffset.y = kOffset.y * ((float)nY - 0.5f) * 2.0f;
            kOffset.Unitize();
            kPos += kOffset * (float)m_nScale;
        }
    }
}

// ---- CNpc ----

// @0x14108e420
CNpc::CNpc()
    : m_cEAC(0), m_nEB0(0), m_nEB4(0), m_nOwnerId(0), m_nEC0(0), m_nEC4(0), m_spF28(0), m_cF38(0)
{
    m_spSkillRow = 0;
    m_nD80 = 3;
    m_nD84 = 4;
    m_bUnkB8 = 1;
    m_nDAC = 0;
    m_unk_b0 = 1;
    m_posD40 = efd::Point3::ZERO;
    m_spNpcData = 0;
    m_unkD88.MakeIdentity();
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->FUN_1417daeb0(1, new StateIdleNPC(this));
    m_spStateMgr->FUN_1417daeb0(2, new StateWalkNPC(this));
    m_spStateMgr->FUN_1417daeb0(0xc, new StateDeadNPC(this));
    m_spStateMgr->FUN_1417daeb0(6, new StateJumpNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x10, new StateSkill(this));
    m_spStateMgr->FUN_1417daeb0(0xd, new StateHitNPC(this));
    m_spStateMgr->FUN_1417daeb0(0x12, new StateStun(this));
    m_spStateMgr->FUN_1417daeb0(0x16, new StateTalkNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x11, new StateSpawn(this));
    m_spStateMgr->FUN_1417daeb0(0x17, new StateRegen(this));
    m_spStateMgr->FUN_1417daeb0(0x23, new StatePuppetNpc(this));
    m_spStateMgr->FUN_1417daeb0(0x38, new StateSummonPortal(this));
    m_f164 = FUN_1401d3200()->OffsetNpcHpbar.Read();
    m_f168 = FUN_1401d3200()->OffsetNpcChatballoon.Read();
    m_f16c = FUN_1401d3200()->OffsetNpcNametag.Read();
    m_f170 = 0.0f;
    m_f174 = 0.0f;
    m_f178 = FUN_1401d3200()->OffsetNpcDamagenumber.Read();
    m_nDE0 = 0;
    m_nDE4 = 0;
    m_nE60 = 0;
    m_nE10 = 0;
    m_cE40 = 0;
    m_nE48 = 0;
    m_nE14 = 0;
    m_cE50 = 0;
    m_nE54 = 0;
    m_nE58 = 0;
    m_nEA8 = 0;
    m_spC40 = 0;
    m_nDE8 = 0;
    m_nEB8 = 0;
    m_nEE0 = 0;
    m_nF20 = 0;
}

// @0x14108ef30
CNpc::~CNpc()
{
    if (m_nE54 != 0)
        FUN_1411a6060(FUN_1403ed280(), m_nE54);
    FUN_141095140();
}

// @0x14108f710
void CNpc::vfunc_12()
{
    PCBase::vfunc_12();
    for (unsigned __int64 i = 0; i < m_spNpcData->m_effectDummies.size(); i++)
        FUN_141674ef0(m_spNpcData->m_effectDummies[i]);
    if (FUN_14028d470(FUN_1416749a0()->FUN_140970720(), 1.0f)) {
        if (FUN_141093270()->m_model.m_nSpawnAlphaAnimation != 0)
            vfunc_40(0.0f, 1.0f, 0.0f, 0.5f);
    }
    vfunc_119();
    FUN_141675980();
    vfunc_82();
    if (!FUN_141093270()->HasPropertyTag(2))
        return;
    if (FUN_14166ce30() == 0 && vfunc_80().get() != 0) {
        vfunc_80()->FUN_141992140(1);
        vfunc_80()->FUN_141992180(FUN_141670a00(4), FUN_141670a30(4));
    }
}

// @0x14108fb00
void CNpc::vfunc_14()
{
    if (FUN_141092ff0(this) != 0) {
        FUN_1403ed2d0()->FUN_141bc7f10(FUN_14123c460());
        FUN_1409f7c90()->FUN_14161d070(FUN_14123c460());
    }
    FUN_1410979a0();
    FUN_141099ab0();
    PCBase::vfunc_14();
}

// @0x14108fbb0
void CNpc::vfunc_45(float f)
{
    GameObject::vfunc_45(f);
}

// @0x14108fbe0
float CNpc::vfunc_46(const efd::Point3& kPos)
{
    return GameObject::vfunc_46(kPos);
}

// @0x14108fc10
void CNpc::vfunc_47(bool b)
{
    if (m_spNpcData->IsBossNpc())
        GameObject::vfunc_47(false);
    else
        GameObject::vfunc_47(b);
}

// @0x14108fc70
void CNpc::vfunc_27(ATL::CAtlArray<Unk_GoAnchorPtr>& kArr)
{
    reinterpret_cast<ATL::CAtlArray<MS2Ptr<CBoxCollision> >&>(kArr).Copy(m_arrE68);
}

// @0x14108fcb0
void CNpc::vfunc_28(void* p)
{
    static_cast<ATL::CAtlArray<MS2Ptr<CBoxCollision> >*>(p)->Copy(m_arrE88);
}

// @0x14108fcf0
int CNpc::vfunc_58()
{
    if (FUN_141093270()->IsBoss())
        return 6;
    return 5;
}

// @0x14108fd60
Unk_PCBaseFxLib* CNpc::vfunc_70()
{
    return FUN_140a50010()->FUN_1411bf1e0();
}

// @0x14108fd90
int CNpc::vfunc_64()
{
    return m_spNpcData->m_nHitImmune;
}

// @0x14108fdc0
int CNpc::vfunc_78()
{
    if (m_nE58 != 0)
        return (unsigned short)m_nE58;
    return m_spNpcData->GetLevel();
}

// MS2-FUNCTIONAL: the exe returns vfunc_78() / 0 in eax (PCBase declares the slot void).
// @0x14108fe10
void CNpc::vfunc_79()
{
    if (m_spNpcData == 0)
        return;
    if (m_spNpcData->HasPropertyTag(3))
        return;
    vfunc_78();
}

// The hp bar (created when the npc row shows one).
// @0x14108fe90
MS2Ptr<Unk_PCBaseComp_a58> CNpc::vfunc_80()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (m_spA58 == 0) {
        bool bHpBar = FUN_141093270()->m_bHpBar;
        if (bHpBar) {
            if ((m_spA58 = FUN_141992920(m_unk_70)).get() != 0)
                m_spA58->FUN_141992140(0);
        }
    }
    return m_spA58;
}

// The name tag.
// @0x141090030
MS2Ptr<Unk_PCBaseComp_a78> CNpc::vfunc_82()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a78>(0);
    if (m_spA78.get() == 0) {
        if (FUN_140a7c8d0(FUN_141093270().operator->())) {
            if ((m_spA78 = FUN_141a60da0(m_unk_70)).get() != 0) {
                m_spA78->FUN_141a5e4c0(FUN_141093270()->GetUnknown12());
                m_spA78->FUN_141a5e500(FUN_140a7c970(FUN_141093270().operator->()));
                m_spA78->vfunc_2();
            }
        }
        return m_spA78;
    }
    return m_spA78;
}

// The buff balloon.
// @0x1410902f0
MS2Ptr<Unk_PCBaseComp_a98> CNpc::vfunc_84()
{
    if (m_spA98 == 0)
        m_spA98 = FUN_14128ef70(m_unk_70);
    return m_spA98;
}

// The emoticon.
// @0x1410903b0
MS2Ptr<Unk_PCBaseComp_a88> CNpc::vfunc_83()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a88>(0);
    if (m_spA88.IsNull() && vfunc_116() > 0)
        m_spA88 = FUN_14192fd40(m_unk_70);
    return m_spA88;
}

// The chat balloon.
// @0x1410904c0
MS2Ptr<Unk_PCBaseComp_aa8> CNpc::vfunc_85()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0 && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_aa8>(0);
    if (m_spAA8 == 0)
        m_spAA8 = FUN_1418fbdb0(m_unk_70);
    return m_spAA8;
}

// @0x1410905c0
const char* CNpc::vfunc_123(int n)
{
    if (n == 0x34 && !m_strED0.IsEmpty())
        return m_strED0;
    return PCBase::vfunc_123(n);
}

// MS2-FUNCTIONAL: the last argument is a 12-byte point passed by value (PCBase declares it void*).
// @0x141090620
void CNpc::vfunc_111(void* p, int a, int b, void* q)
{
    if (FUN_14166ce30() != 0 && FUN_141093270()->GetCorpseHitAble() != 0)
        return;
    efd::Point3 kPos = *static_cast<efd::Point3*>(q);
    PCBase::vfunc_111(p, a, b, &kPos);
}

// @0x141090740
void CNpc::vfunc_112(void* p, int n)
{
    if (FUN_14166ce30() != 0 && FUN_141093270()->GetCorpseHitAble() != 0)
        return;
    PCBase::vfunc_112(p, n);
}

// @0x141090820
void CNpc::vfunc_113(void* p)
{
    PCBase::vfunc_113(p);
}

// @0x141090850
float CNpc::vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut)
{
    *pOut = 0;
    float fRate = 1.0f;
    float fSpeed = 1.0f;
    if (vfunc_65() != 0) {
        if (0.0f < b)
            fRate = a / b;
    } else if (0.0f < c) {
        fRate = a / c;
    }
    if (nFlag == 0)
        fSpeed = vfunc_97();
    if (m_unk_968 != 0)
        fRate = 1.0f;
    return d * fRate * fSpeed;
}

// @0x141090950
float CNpc::vfunc_98(float f)
{
    return FUN_1401c0db0()->FUN_1406745e0(FUN_141670a00(0xd), f);
}

// @0x141090ba0
int CNpc::vfunc_116()
{
    return m_spNpcData->GetFriendly();
}

// @0x141090bd0
CStringW CNpc::vfunc_77()
{
    if (vfunc_128())
        return FUN_141093310();
    if (!m_strW918.IsEmpty())
        return m_strW918;
    if (m_spNpcData.get() == 0)
        return L"";
    return FUN_141093310();
}

// @0x141090cd0
void CNpc::vfunc_32(bool b)
{
    if (m_spShadow != 0 && m_spShadow->FUN_14109a720()) {
        if (FUN_140f4a450() < 200000.0f)
            vfunc_93(false);
    }
    PCBase::vfunc_32(b);
}
