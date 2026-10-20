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
#include "ms2/commonfiles/maid.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2format.h"
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
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();                                         // hide
};
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
bool FUN_14028d470(float a, float b);                               // a != b (with epsilon)
unsigned char FUN_140a7c8d0(NpcDataCli* pData);                     // NpcDataCli::GetNametag
int FUN_140a7c970(NpcDataCli* pData);                               // NpcDataCli::GetClassConstant

class Unk_SSG09a700 { public: MS2Ptr<CMaid> FUN_14127e400(__int64 nUid); };   // the field maids (before the user's own)
Unk_SSG09a700* FUN_14109a700();
class Unk_ArcMoverView { public: bool FUN_14160c1c0() const; CStringA FUN_14160c1e0() const; };   // Unk_NpcBeam getters
class Unk_1401aa6a0 : public CStringW { public: Unk_1401aa6a0(int nNpcId); };   // the npc name of the string table
class Unk_EqWorld { public: PCBase* FUN_141bd0cc0(); };
class Unk_Svc7476c0 { public: unsigned char FUN_14074e030(int nNpcId); };
Unk_Svc7476c0* FUN_1407476c0();
class Unk_PortalQuestTable { public: int FUN_140764c90(CNpc* pNpc); };
Unk_PortalQuestTable* FUN_14109a710();
class Unk_MmNpcTable { public: MS2Ptr<NpcDataCli> FUN_140a7cab0(int nNpcId); };
Unk_MmNpcTable* FUN_1406d6e90();
class UIDamageText { public: void FUN_141912a80(GameObject* pObj, int nValue, int n); };
UIDamageText* FUN_140b624b0(int nUiId);
class CStringTable { public: CStringW FUN_141811980(int nKind, int nId); };
CStringTable* FUN_1401a9d70();
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
void FUN_141567330(NiAVObject* pObj, bool b);
void FUN_1412751b0(const CStringW& str, int nLevel);              // debug log
void FUN_1410943b0(PCBase* pActor, int n);
void FUN_14123fbf0(Unk_PCBaseBody* pBody, unsigned short nGroup);  // collision group
void FUN_141670d50(PCBase* pActor, efd::Point2 kSize);

class Unk_Svc764020;
Unk_Svc764020* FUN_140764020();
void FUN_1416d12d0(Unk_Svc764020* pMgr, int nNpcId, Unk_QmNpcQuestState* pState, int n);   // fill the npc's quest icon
class Unk_PCBaseCompEmoView : public Unk_PCBaseComp_a88 { public: void FUN_14192f910(); };     // UIEmoticon::Entity refresh
class Unk_CscWorld { public: PCBase* FUN_141bd1200(int nObjectId); };
const efd::Point3& FUN_140947900(void* pAVObject);                  // world translate of the node
void FUN_1411a4f40(CEffectService* pService, CStringA strEffect, const efd::Point3& kPos);   // play an effect at a point
class Unk_EmoNpcTable { public: int FUN_14035b0a0(int nNpcType); };
Unk_EmoNpcTable* FUN_140764010();
class Unk_FactoryApp;
Unk_FactoryApp* FUN_1403ed2b0();
const CStringA& FUN_141adc5d0(Unk_FactoryApp* pApp, int nUiId); // close a ui
const CStringA& FUN_141adc530(Unk_FactoryApp* pApp, int nUiId); // open a ui
int FUN_140de2860(void* pStore);
void FUN_140de2b50(void* pStore);
class Unk_SSGMisc2d80 { public: void FUN_140de2a00(); };
extern Unk_SSGMisc2d80 DAT_143ab2d80;
extern int DAT_143abdc30;                                           // the npc id of the last 0x4f50 dialog
class Unk_EmoCfgFloat { public: float* FUN_140967520(const float* pDefault); };

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
    if (FUN_141092ff0() != 0) {
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

// @0x141090d60 (vfunc_124) - see below

// @0x1410916a0
void CNpc::vfunc_126(int a, int b)
{
    if (!m_spNpcData.IsNull() && (m_nEB8 == 0 || b != 0)) {
        if (a == 0 || m_spNpcData->m_capsule.m_nIgnore != 0)
            FUN_14123fbf0(m_unk_150, 5);
        else
            FUN_14123fbf0(m_unk_150, 4);
    }
}

// @0x141091740
int CNpc::vfunc_127()
{
    return 1;
}

// @0x141091760
bool CNpc::vfunc_128()
{
    return m_nE48 != 0;
}

// @0x141092c50
void CNpc::FUN_141092c50(CInPacket& packet)
{
    unsigned char nMode = packet.vfunc_o8_1();
    if (nMode == 0)
        FUN_141095240(packet.vfunc_o8_4());
    else if (nMode == 1)
        m_nF20 = packet.vfunc_o8_3();
    else if (nMode == 2)
        m_nF20 = 0;
}

// @0x141092d20
bool CNpc::vfunc_68(void* a, double t, int b, unsigned c, int d)
{
    return false;
}

// @0x141092d40
void CNpc::FUN_141092d40(CString strAnim)
{
    if (m_cEAC == 0)
        return;
    if (FUN_14166dc50() != "Bore_A" && strAnim == "Bore_A") {
        m_nEB0++;
        FUN_1412751b0(StringFormat(L"OnPreStartAnimation Bore ani:{0} / emo:{1}", (unsigned&)m_nEB0, (unsigned&)m_nEB4), 0x14);
    }
    if (FUN_14166dc50() == "Bore_A" && strAnim != "Bore_A")
        FUN_1412751b0(StringFormat(L"Not Bore!! {0}/{1}", (unsigned&)m_nEB0, (unsigned&)m_nEB4), 0x14);
}

// @0x141092fa0
int CNpc::FUN_141092fa0()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->GetId();
    return 0;
}

// @0x141092ff0
bool CNpc::FUN_141092ff0()
{
    return m_spNpcData->IsBoss();
}

// @0x141093030
int CNpc::FUN_141093030()
{
    int nKind = FUN_1410934c0();
    if (nKind == 4 || nKind == 6)
        return 1;
    return 0;
}

// @0x141093070
bool CNpc::FUN_141093070()
{
    return m_spNpcData->IsMinimap();
}

// @0x1410930a0
int CNpc::FUN_1410930a0()
{
    if (FUN_141670a00(4) == 0) {
        if (FUN_14166c930() == 0xc) {
            if (FUN_141093270()->GetCorpseHitAble() != 0)
                return 1;
            return 0;
        }
        return 0;
    }
    return 0;
}

// @0x141093160
int CNpc::FUN_141093160()
{
    if (m_spNpcData.get() != 0 && m_spNpcData->GetKind() == 2)
        return 1;
    return 0;
}

// @0x1410931c0
int CNpc::FUN_1410931c0()
{
    if (m_spNpcData.get() != 0 && m_spNpcData->GetKind() == 3)
        return 1;
    return 0;
}

// @0x141093220
bool CNpc::FUN_141093220()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->IsShopKind();
    return false;
}

// @0x141093270
MS2Ptr<NpcDataCli> CNpc::FUN_141093270()
{
    return m_spNpcData;
}

// @0x1410932c0
void CNpc::FUN_1410932c0(bool b)
{
    NiAVObject* pObj = FUN_141b6efc0(FUN_14123c410());
    if (pObj != NULL)
        FUN_141567330(pObj, b);
}

// @0x141093310
CStringW CNpc::FUN_141093310()
{
    if (vfunc_128()) {
        MS2Ptr<CMaid> spMaid = FUN_14109a700()->FUN_14127e400(m_nE48);
        if (spMaid.IsNull())
            spMaid = CUserMaidManager::GetInstance()->GetMaid(m_nE48);
        if (spMaid.get() != 0 && !spMaid->FUN_1409eeda0().IsEmpty())
            return spMaid->FUN_1409eeda0();
    }
    return Unk_1401aa6a0(FUN_141092fa0());
}

// @0x1410934c0
unsigned char CNpc::FUN_1410934c0()
{
    if (m_spNpcData == 0)
        return 0;
    return (unsigned char)m_spNpcData->m_nClass;
}

// @0x141093510
unsigned short CNpc::FUN_141093510()
{
    return m_nDE8;
}

// @0x141093530
CStringA CNpc::FUN_141093530()
{
    if (!reinterpret_cast<Unk_ArcMoverView*>(&m_unkDB0)->FUN_14160c1c0())
        return CStringA();
    return reinterpret_cast<Unk_ArcMoverView*>(&m_unkDB0)->FUN_14160c1e0();
}

// @0x1410935b0
void CNpc::vfunc_66(int n)
{
    PCBase::vfunc_66(n);
    if (n == 0)
        return;
    if (FUN_14166ce30() == 0 && vfunc_80().get() != 0)
        vfunc_80()->FUN_141992180(FUN_141670a00(4), FUN_141670a30(4));
    FUN_1410943b0(this, 1);
}

// @0x141093760
int CNpc::FUN_141093760()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->GetNpcType();
    return 0;
}

// @0x1410937b0
int CNpc::FUN_1410937b0()
{
    if (m_spNpcData.get() != 0)
        return m_spNpcData->GetKind();
    return 0;
}

// @0x141093800
MS2Ptr<CMaid> CNpc::FUN_141093800()
{
    if (!vfunc_128())
        return MS2Ptr<CMaid>(0);
    MS2Ptr<CMaid> spMaid = FUN_14109a700()->FUN_14127e400(m_nE48);
    if (spMaid.IsNull())
        spMaid = CUserMaidManager::GetInstance()->GetMaid(m_nE48);
    return spMaid;
}

// @0x141093910
void CNpc::FUN_141093910()
{
    if (0 < m_nE60) {
        UIDamageText* pText = FUN_140b624b0(0x4e32);
        if (pText != NULL)
            pText->FUN_141912a80(this, (int)m_nE60, 0);
    }
    m_nE60 = 0;
}

// @0x141093c20
unsigned int CNpc::FUN_141093c20()
{
    return m_questState.m_questId;
}

// @0x141093c40
int CNpc::FUN_141093c40()
{
    return m_questState.m_icon;
}

// @0x141093c60
int CNpc::FUN_141093c60()
{
    return m_questState.m_state;
}

// Refreshes the npc's quest icon state and the emoticon when it changed.
// @0x141093c80
void CNpc::FUN_141093c80()
{
    m_nE10 = 0;
    int nIcon = m_questState.m_icon;
    int nState = m_questState.m_state;
    if (!FUN_141093270().IsNull() && vfunc_116() != 0 && m_cE40 != 0) {
        m_questState.FUN_1409669c0();
        FUN_1416d12d0(FUN_140764020(), FUN_141092fa0(), &m_questState, 0);
        if (nIcon != m_questState.m_icon || nState != m_questState.m_state) {
            if (vfunc_83().get() != 0)
                static_cast<Unk_PCBaseCompEmoView*>(vfunc_83().operator->())->FUN_14192f910();
        }
    }
}

// @0x141093e90
void CNpc::FUN_141093e90()
{
    m_nE10 = 1;
}

// Turns toward the owner actor's model node.
// @0x141093eb0
void CNpc::FUN_141093eb0()
{
    if (m_nEC0 != 0) {
        PCBase* pOwner = reinterpret_cast<Unk_CscWorld*>(FUN_1403ed2d0())->FUN_141bd1200(m_nEC0);
        if (pOwner != NULL) {
            efd::SmartPointer<NiAVObject> spNode = pOwner->FUN_141675930();
            if (spNode != 0) {
                efd::Point3 kPos = FUN_140947900(spNode.operator->());
                vfunc_19(kPos);
            }
        }
    }
}

// @0x141093fa0
void CNpc::FUN_141093fa0()
{
    if (m_spNpcData.get() != 0)
        FUN_1411a4f40(FUN_1403ed280(), m_spNpcData->m_strSoundStart, vfunc_18());
}

// @0x141094050
void CNpc::FUN_141094050()
{
    MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85();
    if (spBalloon.get() != 0)
        spBalloon->vfunc_3();
    if (m_spNpcData.get() != 0)
        FUN_1411a4f40(FUN_1403ed280(), m_spNpcData->m_strSoundEnd, vfunc_18());
}

// The ui an npc type opens on talk (0: none).
// @0x141094170
int CNpc::FUN_141094170()
{
    int nType = FUN_141093760();
    if (nType == 1)
        return 0x4e3b;
    if (nType == 2)
        return 0x4e47;
    if (nType == 3)
        return 0x4e4a;
    if (nType == 0x56)
        return 0x4e97;
    if (nType == 0x58)
        return 0x4f55;
    if (FUN_140764010()->FUN_14035b0a0(nType) != 0)
        return 0x4f50;
    return 0;
}

// @0x141094200
int CNpc::FUN_141094200()
{
    int nUiId = FUN_141094170();
    if (nUiId == 0x4e4a) {
        FUN_141adc5d0(FUN_1403ed2b0(), 0x4e4a);
        FUN_141adc5d0(FUN_1403ed2b0(), 0x4e49);
    } else if (nUiId == 0x4e47) {
        if (FUN_140de2860(&DAT_143ab2d80) == 0) {
            FUN_140de2b50(&DAT_143ab2d80);
            return 0x4e47;
        }
        DAT_143ab2d80.FUN_140de2a00();
    } else if (nUiId == 0x4f50) {
        DAT_143abdc30 = FUN_141092fa0();
    }
    FUN_141adc530(FUN_1403ed2b0(), nUiId);
    return nUiId;
}

// @0x1410942c0
void CNpc::FUN_1410942c0()
{
    int nUiId = FUN_141094170();
    if (nUiId != 0)
        FUN_141adc5d0(FUN_1403ed2b0(), nUiId);
}

// In talk range of the camera (always for property tag 0x1a).
// @0x141094300
int CNpc::FUN_141094300()
{
    if (m_spNpcData->HasPropertyTag(0x1a))
        return 1;
    float fDefault = 400.0f;
    float* pRange = reinterpret_cast<Unk_EmoCfgFloat*>((char*)FUN_1401d3200() + 0x218)->FUN_140967520(&fDefault);
    float fRange = *pRange + m_spNpcData->m_capsule.m_fRadius;
    if (FUN_140f4a450() <= fRange)
        return 1;
    return 0;
}

// @0x1410945c0
void CNpc::vfunc_43(float f)
{
    GameObject::vfunc_43(f);
    if (f <= 0.0f) {
        if (FUN_14166ce30() == 0)
            vfunc_126(1, 0);
    } else {
        vfunc_126(0, 0);
    }
}

// The emotion id of the npc row (the npc id when the row has none).
// @0x141094640
int CNpc::vfunc_69()
{
    MS2Ptr<CNpcData> spData;
    spData = FUN_141093270();
    if (spData == 0)
        return 0;
    if (spData->m_nEmotionId == 0)
        return spData->GetId();
    return spData->m_nEmotionId;
}

// @0x141094730
void CNpc::FUN_141094730()
{
    COutPacket packet(0x32, 0);
    packet.vfunc_o10_3(FUN_14123c580());
    FUN_140710590(packet);
}

// @0x141094790
void CNpc::FUN_141094790(__int64 nUid)
{
    m_nE48 = nUid;
}

// @0x1410947c0
__int64 CNpc::FUN_1410947c0()
{
    return m_nE48;
}
