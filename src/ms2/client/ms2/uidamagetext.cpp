// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Floating damage / heal / exp / meso / item numbers HUD.
// MS2-UNIT: ?\uidamagetext.cpp
// MS2-RANGE: 0x140112070-0x1401124f0 .text$di
// MS2-RANGE: 0x141910bf0-0x14191a7e0 .text$mn
// MS2-RANGE: 0x142cbd770-0x142cbda20 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidamagetext.cpp"   // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uidamagetext.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/gameoptionbattle.h"
#include "ms2/client/ms2/gameoptioninterface.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local declarations; the unidentified names describe uses rather than original class names.
class Unk_WsC_GameObj : public PCBase {};                                   // the actor lookups of WorldService
class Unk_MyPCEquip : public PCGemEquip {};                                 // PC::FUN_14165f460: the equipment
class Unk_PCBaseBuffs { public: unsigned int FUN_140970b10(); };            // the buff flags of an actor
// CNpc::FUN_141093270 returns the client row: the exe calls the MS2Ptr<NpcDataCli> get / operator-> (cnpc.h types it as
// MS2Ptr<CNpcData>).
class Unk_DtNpc : public CNpc { public: MS2Ptr<NpcDataCli> FUN_141093270(); };
Unk_DtNpc* FUN_14096e110(GameObject* p);                                    // as an npc (0 for a player)
PC* FUN_140974230(GameObject* p);                                           // as a player character (0 otherwise)
class Unk_DtParty { public: int FUN_14162ae20(__int64 nCharId); };          // CPartyManager: a party member (int return)
Unk_DtParty* FUN_1409670d0();                                               // the party manager
// The "RemoveAni" event dispatched by a dying number (an AS event object; 0x40 bytes, no array: the exe has no GS cookie).
class Unk_DtAniEvent
{
public:
    Unk_DtAniEvent(const CString& strType, bool bBubbles, bool bCancelable, int nMovieId);   // 0x1422e2080
    ~Unk_DtAniEvent();                                                      // 0x1422e22a0
    __int64 m_f0, m_f1, m_f2, m_f3, m_f4, m_f5, m_f6, m_f7;
};
class Unk_DtClip : public ASMovieClip
{
public:
    void FUN_1407cbbe0(const char* szName, bool b);                         // set a bool member
    void FUN_1422c0290(float cx, float cy);                                 // set the scale
    float FUN_1422c11f0();                                                  // the y scale
    void FUN_1422c3d30(Unk_DtAniEvent& ev);                                 // dispatchEvent
};
class Unk_DtCamera
{
public:
    static Unk_DtCamera* FUN_1409478c0();                                   // CameraMgr
    bool FUN_140af0700(const efd::Point3& kWorld, efd::Point3& kScreen);    // world -> screen; false when off screen
    efd::Point3 FUN_140a17e10();                                            // the camera position
};
struct Unk_DtCfgValue { float FUN_1402bac70(); const float& FUN_140298f40(); int* FUN_1402056b0(); char m_pad[0x58]; };
int FUN_14025a620(Unk_DtCfgValue* pValue);
struct Unk_DtCfg
{
    char m_pad_0000[0x168];
    Unk_DtCfgValue m_168;                   // show distance
    char m_pad_01c0[0xc8c8 - 0x168 - sizeof(Unk_DtCfgValue)];
    Unk_DtCfgValue m_c8c8;                  // line height
    Unk_DtCfgValue m_c920;                  // jump count
    Unk_DtCfgValue m_c978;                  // max shown
    Unk_DtCfgValue m_c9d0;                  // diffScale
    Unk_DtCfgValue m_ca28;                  // diffAlpha
};
Unk_DtCfg* FUN_1401d3200();
class Unk_DtOption { public: Unk_BattleState* FUN_141248630(); Unk_InterfaceState* FUN_140e09150(); };
Unk_DtOption* FUN_1409a8b10();
class Unk_DtUIScale;
Unk_DtUIScale* FUN_14025e7a0();                                             // ui scale service
float FUN_1422afec0(Unk_DtUIScale* pScale, int nLayer);                     // scale of a layer
class Unk_DtScene;
Unk_DtScene* FUN_1408e57f0();
int FUN_1422b9e00(Unk_DtScene* pScene);                                     // the scene state id
unsigned int FUN_140869420();                                               // the time (ms)
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);          // IsKindOf
PCBase* FUN_1409ffd30(GameObject* p);                                       // the actor of a game object (0 otherwise)
float FUN_1412762d0(const NiPoint3& pt);
const NiPoint3* FUN_140947900(NiAVObject* pNode);                           // world translate
NiNode* FUN_1413fa070(egf::EntityID id);                                    // entity id -> scene root
float FUN_140a0fda0(float a, float b);                                      // max
float FUN_140a0fde0(float a, float b);                                      // min
bool FUN_1409c1720(const Scaleform::GFx::Value& v);                         // the value as a bool
bool FUN_1409b4d40(const Scaleform::GFx::Value& v);                         // the value is set
// Call an AS function object (skillslot.cpp; a member: rcx = the function object, rdx = the returned value).
class Unk_SsFn : public AScript
{
public:
    Scaleform::GFx::Value FUN_1417620b0(Scaleform::GFx::Value kArg);
};
MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);  // new ASGameEntity(v, n)
CStringW FUN_140719630(int n);
CString Name_140219830(int value);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static CString s_strBlock = "Block";
static CString s_strRecover2 = "Recover";
static CString s_strCritical = "Critical";
static CString s_strFormat = "{0}";
static CString s_strDecreaseCounter = "decreaseCounter";
static CString s_strNext = "_next";
static CString s_strUp = "_up";
static CString s_strGarbage = "garbage";
static CString s_strRecover3 = "Recover";
static CString s_strMiss = "Miss";
static CString s_strMonster = "Monster";
static CString s_strRecover4 = "Recover";
static CString s_strNormal = "Normal";
static CString s_strPC = "PC";
static CString s_strRecover = "Recover";
static CString s_strPlusFormat = "+{0}";
static CString s_strRemoveAni = "RemoveAni";
static CString s_strUser = "User";

int UIDamageText::DamageInfo::s_nMovieId = 1;
bool UIDamageText::DamageInfo::s_bClearing;

// Removes pos from a number list, moving the list's last-inserted mark back when it pointed there.
template <class T>
void FUN_141917ab0(POSITION pos, POSITION* pLast, ATL::CAtlList<T>& list)
{
    if (pos == 0)
        return;
    if (!list.IsEmpty())
    {
        if (pos == *pLast)
        {
            POSITION posPrev = pos;
            if (list.GetHeadPosition() == pos)
                posPrev = 0;
            else
                list.GetPrev(posPrev);
            *pLast = posPrev;
        }
        list.RemoveAt(pos);
    }
}

// @0x141910bf0
UIDamageText::DamageInfo::DamageInfo(int nType, unsigned __int64 nOwnerId, const NiPoint3& kPos, int nIndex,
                                     MS2Ptr<ASMovieClip> spClip, int nGrade)
    : m_nType(nType), m_nOwnerId(nOwnerId), m_kPos(kPos), m_nIndex(nIndex), m_spClip(spClip), m_spAni(0),
      m_nGrade(nGrade), m_fScale(1.0f), m_bMyDamage(false), m_bCanJump(true), m_nStart(0), m_nState(0), m_nElapsed(0)
{
}

// @0x141910d10
UIDamageText::DamageInfo::~DamageInfo()
{
    if (s_bClearing)
        return;
    if (((m_spAni.get() != 0 ? true : false) && m_nState == 0) || m_nState == 3)
    {
        m_spAni->vfunc_7();
        Unk_DtAniEvent ev(s_strRemoveAni, false, false, s_nMovieId);
        static_cast<Unk_DtClip*>(m_spAni.operator->())->FUN_1422c3d30(ev);
    }
}

// @0x141910e60
void UIDamageText::DamageInfo::FUN_141910e60(const unsigned int& nNow)
{
    if (m_nStart == 0)
        m_nElapsed = 0;
    else if (m_nStart > nNow)
    {
        m_nStart = nNow;
        m_nElapsed = 0;
    }
    else
        m_nElapsed = nNow - m_nStart;
}
MS2_REPLACE_METHOD(0x141910E60, UIDamageText::DamageInfo, FUN_141910e60, 107, 0xFB81DCAE);

// @0x141910ee0
void UIDamageText::DamageInfo::FUN_141910ee0(const unsigned int& nNow)
{
    if (m_nStart == 0)
        m_nStart = nNow;
}
MS2_REPLACE_METHOD(0x141910EE0, UIDamageText::DamageInfo, FUN_141910ee0, 37, 0xF7E00DBF);

// @0x141910f10
bool UIDamageText::DamageInfo::FUN_141910f10(const unsigned int& nNow)
{
    return m_nElapsed > 0 && m_nElapsed > 1000;
}
MS2_REPLACE_METHOD(0x141910F10, UIDamageText::DamageInfo, FUN_141910f10, 64, 0x95077869);

// @0x141910f60
bool UIDamageText::DamageInfo::FUN_141910f60(const unsigned int& nNow)
{
    if (m_nState != 0)
        return false;
    return m_nElapsed > 0 && m_nElapsed > 100;
}
MS2_REPLACE_METHOD(0x141910F60, UIDamageText::DamageInfo, FUN_141910f60, 76, 0x62C5DCB2);

// @0x141910fc0
bool UIDamageText::DamageInfo::FUN_141910fc0(const unsigned int& nNow)
{
    if (m_nState != 0)
        return false;
    return m_nElapsed > 0 && m_nElapsed > 200;
}
MS2_REPLACE_METHOD(0x141910FC0, UIDamageText::DamageInfo, FUN_141910fc0, 79, 0x50921854);

// @0x141911020
void UIDamageText::DamageInfo::FUN_141911020(const int& nMovieId)
{
    s_nMovieId = nMovieId;
}

// @0x141911040
void UIDamageText::DamageInfo::FUN_141911040(bool bClearing)
{
    s_bClearing = bClearing;
}

// @0x141911060
UIDamageText::UIDamageText()
    : m_strDamageNode("Eff_Damage"), m_strBodyNode("Eff_Body"), m_posOwnerFollowers(0), m_posNormals(0),
      m_nLineHeight(0), m_nJumpCount(0), m_nMaxShown(0), m_nMaxList(0), m_nMaxIndex(0), m_pBattleOption(0),
      m_pInterfaceOption(0), m_nLastQueueTime(0), m_bObserver(false), m_bClearing(false), m_nRepeat(1)
{
    m_58 = 0;
    m_2c = 8;
    m_44 = 1;
    m_28 = 1;
    DamageInfo::FUN_141911020(m_28);
    DamageInfo::FUN_141911040(m_bClearing);
    FUN_141913a20();
}

// @0x141911370
UIDamageText::~UIDamageText()
{
}

// @0x1419114d0
CString UIDamageText::vfunc_1()
{
    return "DamageText";
}
MS2_REPLACE_METHOD(0x1419114D0, UIDamageText, vfunc_1, 61, 0x693D82EF);

// @0x141911520
void UIDamageText::vfunc_3()
{
    FUN_1419135c0();
    UIHeadUpDisplay::vfunc_3();
}
MS2_REPLACE_METHOD(0x141911520, UIDamageText, vfunc_3, 34, 0x74F08FAB);

// @0x141911550
void UIDamageText::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    m_loadFont = m_30->FUN_1422baa20("loadFont");
    m_unloadFont = m_30->FUN_1422baa20("unloadFont");
    m_spDamageText.AssignRaw(new AScript(m_30->FUN_1422baa20("damageText"), m_28));
    m_onNextAni = m_30->FUN_1422baa20("onNextAni");
    m_onJumpAni = m_30->FUN_1422baa20("onJumpAni");
    m_onForceRemove = m_30->FUN_1422baa20("onForceRemove");
    m_spDamageEnable.AssignRaw(new AScript(m_30->FUN_1422baa20("damageEnable"), m_28));
    m_spDamageGarbage.AssignRaw(new AScript(m_30->FUN_1422baa20("damageGarbage"), m_28));
    m_pBattleOption = FUN_1409a8b10()->FUN_141248630();
    m_pInterfaceOption = FUN_1409a8b10()->FUN_140e09150();
}
MS2_REPLACE_METHOD(0x141911550, UIDamageText, OnLoadComplete, 1294, 0x526C0A8E);

// @0x141911a70
void UIDamageText::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (!m_30)
        return;
    if (!m_queue.IsEmpty())
        FUN_141916340();
    if (!m_bClearing)
    {
        FUN_141915990();
        FUN_1419153d0();
    }
    else
    {
        if (m_ownerFollowers.IsEmpty() && m_normals.IsEmpty())
            return;
        MS2Ptr<ASGameEntity> spRoot(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (spRoot.get() != 0)
        {
            FUN_141916430(spRoot);
            FUN_141916ac0(spRoot);
        }
    }
}

// @0x141911c20
int UIDamageText::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141911C20, UIDamageText, vfunc_28, 67, 0xA56CCDD6);

// @0x141911c70
void UIDamageText::vfunc_43()
{
    MS2Ptr<ASGameEntity> spRoot(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spRoot.get() != 0)
        spRoot->vfunc_2(5, 0, 0);
}
MS2_REPLACE_METHOD(0x141911C70, UIDamageText, vfunc_43, 154, 0xB919F2A2);

// @0x141911d10
void UIDamageText::vfunc_26()
{
    UIObject::vfunc_26();
    m_posOwnerFollowers = 0;
    m_posNormals = 0;
    m_normals.RemoveAll();
    m_ownerFollowerCounter.RemoveAll();
    m_counter.RemoveAll();
    m_ownerFollowers.RemoveAll();
    m_loadFont.SetNull();
    m_unloadFont.SetNull();
    m_spDamageText = 0;
    m_pBattleOption = 0;
    m_pInterfaceOption = 0;
    m_queue.RemoveAll();
    m_nLastQueueTime = 0;
    m_onNextAni.SetNull();
    m_onJumpAni.SetNull();
    m_onForceRemove.SetNull();
    m_spDamageEnable = 0;
    m_spDamageGarbage = 0;
    FUN_141913a20();
}
MS2_REPLACE_METHOD(0x141911D10, UIDamageText, vfunc_26, 366, 0x9617A9C3);

// MS2-FUNCTIONAL: obj saves rsi/rdi (extra nonvolatiles) and allocates locals differently; body flow equivalent
// @0x141911e90
void UIDamageText::FUN_141911e90(PCBase* pTarget, __int64 nValue, int nGrade, int nCasterId, const efd::Point3& kHitPos)
{
    if (pTarget != 0 && !(m_30 == 0) && FUN_141913bd0(pTarget, nGrade, nCasterId) && FUN_141914d40(pTarget) != 1)
    {
        GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0 && m_pInterfaceOption != 0 && m_pBattleOption != 0)
        {
            NiPoint3 kPos(kHitPos);
            if (kPos == efd::Point3::ZERO)
                FUN_141914020(pTarget, kPos, m_strDamageNode);
            bool bMySummon = false;
            CNpc* pSummon = static_cast<CNpc*>(static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd13a0(nCasterId)));
            if (pSummon != 0)
                bMySummon = pSummon->FUN_141094f40() == pPlayer->FUN_14123c580();
            efd::Point3 kScreen;
            if (Unk_DtCamera::FUN_1409478c0()->FUN_140af0700(kPos, kScreen))
            {
                int nPlayerId = pPlayer->FUN_14123c580();
                bool bTargetMe = pTarget->FUN_14123c580() == pPlayer->FUN_14123c580();
                bool bMyDamage = bTargetMe || nCasterId == nPlayerId;
                unsigned int nFlags = m_pBattleOption->m_n10;
                int nTargetKind = FUN_1419142a0(pTarget);
                PCBase* pCaster = WorldService::GetInstance()->FUN_141bd1200(nCasterId);
                int nCasterKind = FUN_1419142a0(pCaster);
                CString strGrade = FUN_141914570(nGrade);
                bool bGem = nCasterKind == 0 && FUN_141914530(nGrade) == 0 && !bTargetMe;
                CString strCaster("");
                bool bUser;
                if (pCaster == 0 || nCasterKind != 0)
                    bUser = true;
                else
                    bUser = pTarget->vfunc_122(pCaster) == 0;
                if (bTargetMe)
                    bUser = true;
                else
                {
                    if (pCaster != 0 && nCasterKind == 0 && bUser)
                    {
                        if ((pCaster->FUN_1416749a0()->FUN_140970b10() & 2) != 0)
                            bUser = false;
                    }
                    if (m_bObserver && nCasterKind == 0)
                    {
                        PC* pPC = dynamic_cast<PC*>(pCaster);
                        if (pPC != 0 && pPC->FUN_141656a80() == m_nObservedId)
                            bUser = true;
                    }
                }
                unsigned __int64 nOwnerId = pTarget->FUN_14123c500();
                ASObj obj(m_28);
                {
                    CString strValue = FUN_141914660(nValue, nGrade);
                    obj.FUN_1407cba60("value", strValue);
                    CString strTarget = FUN_1419143c0(nTargetKind, bUser);
                    obj.FUN_1407cba60("target", strTarget);
                    obj.FUN_1407cba60("grade", strGrade);
                    obj.FUN_1407cba60("caster", strCaster);
                    obj.FUN_1407cbbe0("myDamage", bMyDamage);
                    obj.FUN_1409c4a30("scale", (float)((float)m_pInterfaceOption->m_n10 / 100.0));
                    obj.FUN_1407cbbe0("pcBang", false);
                    if (!m_bObserver)
                    {
                        if (!bMyDamage && (nFlags & 1) != 0 && !bMySummon)
                            obj.FUN_1409c4a30("diffScale", FUN_1401d3200()->m_c9d0.FUN_1402bac70());
                        if (!bMyDamage && (nFlags & 2) != 0 && !bMySummon)
                            obj.FUN_1409c4a30("diffAlpha", FUN_1401d3200()->m_ca28.FUN_1402bac70());
                    }
                    if (bGem)
                    {
                        PC* pPC = dynamic_cast<PC*>(pCaster);
                        if (pPC != 0)
                        {
                            MS2Ptr<CGemBase> spGem = pPC->FUN_14165f460()->FUN_141270740(2);
                            if (spGem.get() != 0)
                                obj.FUN_1407cbb20("gem", FUN_140719630(spGem->FUN_1405a39f0()));
                        }
                    }
                }
                int nRepeat = 1;
                if (1 < m_nRepeat)
                    nRepeat = (int)(nGrade == 1 ? m_nRepeat * 0.5 : (double)m_nRepeat);
                for (int i = 0; i < nRepeat; i++)
                {
                    Scaleform::GFx::Value clip = static_cast<Unk_SsFn*>(m_spDamageText.operator->())->FUN_1417620b0(obj.FUN_1422bb870());
                    MS2Ptr<DamageInfo> spInfo(new DamageInfo(0, nOwnerId, kPos, 0, MS2Ptr<ASMovieClip>(0), nGrade));
                    if (spInfo.get() != 0)
                    {
                        spInfo->m_bMyDamage = bMyDamage;
                        FUN_1419175c0(spInfo, NiPoint3(efd::Point3::ZERO), pTarget, clip, kScreen, bMyDamage);
                    }
                }
            }
        }
    }
}

// @0x1419129d0
void UIDamageText::FUN_1419129d0(GameObject* pTarget, int nValue, int nType)
{
    MS2Ptr<DamageQueueParam> spParam(new DamageQueueParam(pTarget->FUN_14123c580(), nValue, nType));
    m_queue.AddTail(spParam);
}

// @0x141912a80
void UIDamageText::FUN_141912a80(GameObject* pTarget, int nValue, int nType)
{
    NiPoint3 kPos;
    if (nType == 0)
        FUN_141914020(pTarget, kPos, m_strBodyNode);
    else
        FUN_141914020(pTarget, kPos, m_strDamageNode);
    FUN_141912b20(pTarget, nValue, nType, kPos);
}

// MS2-FUNCTIONAL: obj saves rsi/rdi (extra nonvolatiles) and allocates locals differently; body flow equivalent
// @0x141912b20
void UIDamageText::FUN_141912b20(GameObject* pTarget, int nValue, int nType, const NiPoint3& kPos)
{
    if (pTarget != 0 && !(m_30 == 0) && m_pBattleOption != 0)
    {
        bool bShow = true;
        if (nType != 2)
        {
            if (nType == 1)
                bShow = m_pBattleOption->m_b[3];
            else
                bShow = m_pBattleOption->m_b[4];
        }
        if (bShow && FUN_141914d40(pTarget) != 1)
        {
            efd::Point3 kScreen;
            if (Unk_DtCamera::FUN_1409478c0()->FUN_140af0700(kPos, kScreen))
            {
                int nPcBang = FUN_141914490(pTarget);
                unsigned __int64 nOwnerId = pTarget->FUN_14123c500();
                ASObj obj(m_28);
                {
                    CString strValue = FUN_141914890(nValue, nType);
                    obj.FUN_1407cba60("value", strValue);
                    CString strTarget = FUN_1419143c0(FUN_1419142a0(pTarget), true);
                    obj.FUN_1407cba60("target", strTarget);
                    obj.FUN_1407cba60("grade", FUN_1419149d0(nType));
                    obj.FUN_1407cbbe0("pcBang", nPcBang != 0);
                }
                Scaleform::GFx::Value clip = m_30->Invoke("damageText", obj.FUN_1422bb870());
                MS2Ptr<DamageInfo> spInfo(new DamageInfo(1, nOwnerId, kPos, 0, MS2Ptr<ASMovieClip>(0), 1));
                GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
                bool bMine = pPlayer != 0 && pTarget->FUN_14123c580() == pPlayer->FUN_14123c580();
                spInfo->m_bMyDamage = bMine;
                FUN_1419175c0(spInfo, NiPoint3(efd::Point3::ZERO), pTarget, clip, kScreen, 1);
            }
        }
    }
}

// MS2-FUNCTIONAL: obj saves rsi/rdi (extra nonvolatiles) and allocates locals differently; body flow equivalent
// @0x141913060
void UIDamageText::FUN_141913060(GameObject* pTarget, int nCount, const CString& strIcon)
{
    if (pTarget != 0 && !(m_30 == 0) && FUN_141914d40(pTarget) != 1)
    {
        NiPoint3 kPos;
        FUN_141914020(pTarget, kPos, m_strDamageNode);
        efd::Point3 kScreen;
        if (Unk_DtCamera::FUN_1409478c0()->FUN_140af0700(kPos, kScreen))
        {
            unsigned __int64 nOwnerId = pTarget->FUN_14123c500();
            Scaleform::GFx::Value clip = m_30->Invoke("itemIcon", FUN_141914890(nCount, 2),
                                                      FUN_1419143c0(FUN_1419142a0(pTarget), true), FUN_1419149d0(2), strIcon);
            MS2Ptr<DamageInfo> spInfo(new DamageInfo(1, nOwnerId, kPos, 0, MS2Ptr<ASMovieClip>(0), 1));
            GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
            bool bMine = pPlayer != 0 && pTarget->FUN_14123c580() == pPlayer->FUN_14123c580();
            spInfo->m_bMyDamage = bMine;
            FUN_1419175c0(spInfo, NiPoint3(efd::Point3::ZERO), pTarget, clip, kScreen, 1);
        }
    }
}

// @0x1419134a0
void UIDamageText::FUN_1419134a0(const CString& strFont)
{
    if (m_30 == 0)
        return;
    Scaleform::GFx::Value v;
    v.SetString((const char*)strFont);
    m_loadFont.InvokeSelf(0, &v, 1);
}
MS2_REPLACE_METHOD(0x1419134A0, UIDamageText, FUN_1419134a0, 134, 0x773B987B);

// @0x141913530
void UIDamageText::FUN_141913530(const CString& strFont)
{
    if (m_30 == 0)
        return;
    Scaleform::GFx::Value v;
    v.SetString((const char*)strFont);
    m_unloadFont.InvokeSelf(0, &v, 1);
}
MS2_REPLACE_METHOD(0x141913530, UIDamageText, FUN_141913530, 134, 0x45A8EDE9);

// @0x1419135c0
void UIDamageText::FUN_1419135c0()
{
    m_posOwnerFollowers = 0;
    m_posNormals = 0;
    m_normals.RemoveAll();
    m_ownerFollowerCounter.RemoveAll();
    m_counter.RemoveAll();
    m_ownerFollowers.RemoveAll();
    m_queue.RemoveAll();
    m_nLastQueueTime = 0;
    if (!m_bClearing && m_30.get() != 0)
        m_30->Invoke("ClearContainer");
}
MS2_REPLACE_METHOD(0x1419135C0, UIDamageText, FUN_1419135c0, 241, 0xFDBBADA7);

// @0x1419136c0
bool UIDamageText::FUN_1419136c0(CStringW& strOut)
{
    if (m_30 == 0)
        return false;
    Scaleform::GFx::Value v = m_30->Invoke("getMovieCount");
    strOut = CStringW(v.GetString());
    if (!strOut.IsEmpty())
    {
        strOut.Append(StringFormat(L"\nm_normals: {0}", m_normals.GetCount()));
        strOut.Append(StringFormat(L"\nm_ownerFollowers: {0}", m_ownerFollowers.GetCount()));
        strOut.Append(StringFormat(L"\nm_counter: {0}", m_counter.GetCount()));
        strOut.Append(StringFormat(L"\nm_ownerFollowerCounter: {0}", m_ownerFollowerCounter.GetCount()));
    }
    return !strOut.IsEmpty();
}
MS2_REPLACE_METHOD(0x1419136C0, UIDamageText, FUN_1419136c0, 709, 0x3BA9612D);

// @0x141913990
void UIDamageText::FUN_141913990(bool bClearing)
{
    m_bClearing = bClearing;
    DamageInfo::FUN_141911040(bClearing);
}

// @0x1419139d0
void UIDamageText::FUN_1419139d0(bool b)
{
    m_bObserver = b;
}
MS2_REPLACE_METHOD(0x1419139D0, UIDamageText, FUN_1419139d0, 26, 0x17DDE11B);

// @0x1419139f0
void UIDamageText::FUN_1419139f0(__int64 n)
{
    m_nObservedId = n;
}
MS2_REPLACE_METHOD(0x1419139F0, UIDamageText, FUN_1419139f0, 28, 0x4BB4D3D1);

// @0x141913a20
void UIDamageText::FUN_141913a20()
{
    m_nLineHeight = FUN_14025a620(&FUN_1401d3200()->m_c8c8);
    m_nJumpCount = (std::max)(1, *FUN_1401d3200()->m_c920.FUN_1402056b0());
    m_nMaxShown = (std::max)(1, *FUN_1401d3200()->m_c978.FUN_1402056b0());
    m_nMaxList = m_nMaxShown + 10;
    m_nMaxIndex = 1000;
}
MS2_REPLACE_METHOD(0x141913A20, UIDamageText, FUN_141913a20, 190, 0x2A0CED2F);

// @0x141913af0
float UIDamageText::FUN_141913af0(GameObject* pTarget)
{
    if (pTarget == 0)
        return 0.0f;
    float fHeight = FUN_1412762d0(pTarget->vfunc_18());
    PCBase* pActor = FUN_1409ffd30(pTarget);
    if (pActor != 0)
        fHeight += pActor->FUN_141670430();
    return fHeight;
}
MS2_REPLACE_METHOD(0x141913AF0, UIDamageText, FUN_141913af0, 128, 0xF6F52AFD);

// @0x141913b80
float UIDamageText::FUN_141913b80(const NiPoint3& kPos)
{
    return FUN_1412762d0(kPos);
}
MS2_REPLACE_METHOD(0x141913B80, UIDamageText, FUN_141913b80, 29, 0x5D2D3D01);

// MS2-FUNCTIONAL: shared Unk_BattleState uses bool m_b[6] (imul indexing) where the exe reads separate bool fields
// @0x141913bd0
int UIDamageText::FUN_141913bd0(GameObject* pTarget, int nGrade, int nCasterId)
{
    if (nGrade == 4)
        return 0;
    GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    if (m_pBattleOption == 0)
        return 0;
    bool bShow = false;
    unsigned int nCasterMask = 0;
    unsigned int nTargetMask = 0;
    int nTargetId = pTarget->FUN_14123c580();
    int nPlayerId = pPlayer->FUN_14123c580();
    CNpc* pSummon = static_cast<CNpc*>(static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd13a0(nCasterId)));
    if (pSummon != 0)
        nCasterId = pSummon->FUN_141094f40();
    if (nTargetId == nPlayerId)
        nTargetMask = 1;
    else
    {
        PC* pPC = FUN_140974230(pTarget);
        if (pPC != 0)
            nTargetMask = FUN_1409670d0()->FUN_14162ae20(pPC->FUN_141656a80()) ? 2 : 4;
    }
    if ((unsigned int)nCasterId > 0)
    {
        if (nCasterId == nTargetId)
            nCasterMask = nTargetMask;
        else if (nCasterId == nPlayerId)
            nCasterMask = 1;
        else
        {
            PCBase* pCaster = WorldService::GetInstance()->FUN_141bd1200(nCasterId);
            PC* pPC = FUN_140974230(pCaster);
            if (pPC != 0)
                nCasterMask = FUN_1409670d0()->FUN_14162ae20(pPC->FUN_141656a80()) ? 2 : 4;
            else
            {
                Unk_DtNpc* pNpc = FUN_14096e110(pCaster);
                if (pNpc != 0 && pNpc->vfunc_116() > 0)
                {
                    if (pNpc->FUN_141094f40() == nPlayerId)
                        bShow = true;
                    else if (pNpc->FUN_141093270().get())
                        bShow = pNpc->FUN_141093270()->m_bAttackDamage ? true : false;
                }
            }
        }
    }
    if (bShow)
        return 1;
    bool bRecover = FUN_141914530(nGrade) == 1;
    if (bRecover)
    {
        if (nTargetMask & 1)
            return m_pBattleOption->m_b[1];
        else if (nCasterMask & 1)
            return m_pBattleOption->m_b[0];
        else if ((nCasterMask & 2) || (nTargetMask & 2))
            return m_pBattleOption->m_b[2];
        return 0;
    }
    int nCasterFlags = m_pBattleOption->m_n08;
    int nTargetFlags = m_pBattleOption->m_n0c;
    return (nTargetFlags & nTargetMask) != 0 || (nCasterFlags & nCasterMask) != 0;
}
MS2_REPLACE_METHOD(0x141913BD0, UIDamageText, FUN_141913bd0, 1094, 0x593B0E73);

// MS2-FUNCTIONAL: NiPoint3 return temp lands 4 bytes higher on the stack (0x40 vs 0x3c)
// @0x141914020
int UIDamageText::FUN_141914020(GameObject* pTarget, NiPoint3& kPos, const CString& strNode)
{
    if (pTarget == 0)
        return 0;
    NiPoint3 kTargetPos(static_cast<const efd::Point3&>(pTarget->vfunc_18()));
    kPos = kTargetPos;
    if (strNode.IsEmpty())
        return 1;
    PCBase* pActor = FUN_1409ffd30(pTarget);
    if (pActor != 0)
    {
        NiAVObject* pNode = pActor->FUN_141675150(strNode);
        if (pNode != 0)
            kPos = *FUN_140947900(pNode);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141914020, UIDamageText, FUN_141914020, 200, 0x994C8D00);

// @0x1419140f0
int UIDamageText::FUN_1419140f0(GameObject* pTarget, int& nIndex, CounterMap& map)
{
    if (pTarget == 0)
        return 0;
    unsigned __int64 nOwnerId = pTarget->FUN_14123c500();
    MS2Ptr<CounterInfo> spCounter(0);
    if (map.Lookup(nOwnerId, spCounter))
    {
        if (spCounter.get() != 0)
            nIndex = spCounter->m_nIndex;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419140F0, UIDamageText, FUN_1419140f0, 162, 0x3E527376);

// @0x1419141a0
int UIDamageText::FUN_1419141a0(GameObject* pTarget)
{
    PCBase* pActor = FUN_1409ffd30(pTarget);
    if (pActor != 0)
    {
        if (m_bObserver)
            return 1;
        return pActor->FUN_140f4a450() <= FUN_1401d3200()->m_168.FUN_140298f40();
    }
    else if (pTarget != 0)
    {
        GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0)
            return pTarget->FUN_140f4a450() <= FUN_1401d3200()->m_168.FUN_140298f40();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419141A0, UIDamageText, FUN_1419141a0, 244, 0xBDDE2484);

// @0x1419142a0
int UIDamageText::FUN_1419142a0(GameObject* pTarget)
{
    int nKind = 1;
    GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        if (FUN_14087ddc0(pTarget ? pTarget->GetClassDesc() : 0, 0x6200004))
            nKind = 0;
        else if (FUN_14087ddc0(pTarget ? pTarget->GetClassDesc() : 0, 0x6200003))
            nKind = 0;
        else if (FUN_14087ddc0(pTarget ? pTarget->GetClassDesc() : 0, 0x6200011))
            nKind = 0;
    }
    return nKind;
}
MS2_REPLACE_METHOD(0x1419142A0, UIDamageText, FUN_1419142a0, 278, 0xA4962AB5);

// @0x1419143c0
CString UIDamageText::FUN_1419143c0(int nTargetKind, bool bUser)
{
    CString str;
    switch (nTargetKind)
    {
    case 0:
        if (bUser)
            str = s_strUser;
        else
            str = s_strMonster;
        break;
    case 1:
        str = s_strMonster;
        break;
    }
    return str;
}
MS2_REPLACE_METHOD(0x1419143C0, UIDamageText, FUN_1419143c0, 192, 0x44112EB6);

// @0x141914490
int UIDamageText::FUN_141914490(GameObject* pTarget)
{
    return 0;
}
MS2_REPLACE_METHOD(0x141914490, UIDamageText, FUN_141914490, 13, 0x370AB719);

// @0x1419144b0
int UIDamageText::FUN_1419144b0(int nGrade)
{
    switch (nGrade)
    {
    case 5:
    case 6:
    case 7:
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419144B0, UIDamageText, FUN_1419144b0, 48, 0x4AE2E2C0);

// @0x1419144f0
bool UIDamageText::FUN_1419144f0(int nGrade)
{
    switch (nGrade)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1419144F0, UIDamageText, FUN_1419144f0, 45, 0x77063B16);

// @0x141914530
int UIDamageText::FUN_141914530(int nGrade)
{
    switch (nGrade)
    {
    case 5:
    case 6:
    case 7:
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141914530, UIDamageText, FUN_141914530, 48, 0x4AE2E2C0);

// @0x141914570
CString UIDamageText::FUN_141914570(int nGrade)
{
    CString str;
    switch (nGrade)
    {
    case 0:
    case 2:
    case 3:
        str += s_strNormal;
        break;
    case 1:
        str += s_strCritical;
        break;
    case 5:
    case 6:
    case 7:
        str += s_strRecover;
        break;
    }
    return str;
}
MS2_REPLACE_METHOD(0x141914570, UIDamageText, FUN_141914570, 193, 0x55B28405);

// MS2-FUNCTIONAL: exe has an extra dead jmp after case 5 whose source form is unknown
// @0x141914660
CString UIDamageText::FUN_141914660(__int64 nValue, int nGrade)
{
    CString str;
    switch (nGrade)
    {
    case 0:
    case 1:
        str = Unk_SocketFormat((const char*)s_strFormat, nValue);
        break;
    case 5:
        str = Unk_SocketFormat((const char*)s_strPlusFormat, nValue);
        break;
    case 2:
        str = s_strMiss;
        break;
    case 3:
        str = s_strBlock;
        break;
    }
    return str;
}
MS2_REPLACE_METHOD(0x141914660, UIDamageText, FUN_141914660, 366, 0x28219061);

// @0x1419147e0
CString UIDamageText::FUN_1419147e0()
{
    int nFlags = 0;
    if (m_pBattleOption != 0)
        nFlags = m_pBattleOption->m_n10;
    return Name_140219830(nFlags);
}
MS2_REPLACE_METHOD(0x1419147E0, UIDamageText, FUN_1419147e0, 99, 0x2BBD4420);

// @0x141914850
int UIDamageText::FUN_141914850(int nType)
{
    switch (nType)
    {
    case 0:
        return 0;
    case 1:
    case 2:
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141914850, UIDamageText, FUN_141914850, 58, 0x1015100C);

// @0x141914890
CString UIDamageText::FUN_141914890(int nValue, int nType)
{
    CString str;
    switch (nType)
    {
    case 0:
    case 1:
        str = Unk_SocketFormat((const char*)s_strFormat, nValue);
        break;
    case 2:
        str = Unk_SocketFormat((const char*)s_strPlusFormat, nValue);
        break;
    }
    return str;
}
MS2_REPLACE_METHOD(0x141914890, UIDamageText, FUN_141914890, 304, 0x2205B6F5);

// @0x1419149d0
CString UIDamageText::FUN_1419149d0(int nType)
{
    CString str;
    switch (nType)
    {
    case 1:
        str += "Meso";
        break;
    case 0:
        str += "Exp";
        break;
    case 2:
        str += "Item";
        break;
    }
    return str;
}
MS2_REPLACE_METHOD(0x1419149D0, UIDamageText, FUN_1419149d0, 185, 0x278A2D2D);

// @0x141914a90
float UIDamageText::FUN_141914a90(const NiPoint3& kPos)
{
    float fScale = 1.0f;
    GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 1.0f;
    if (pPlayer->vfunc_18() == kPos)
        return 1.0f;
    NiPoint3 kPlayer = pPlayer->vfunc_18();
    efd::Point3 kCamera = Unk_DtCamera::FUN_1409478c0()->FUN_140a17e10();
    float fDistance = (kPos - kPlayer).Length();
    float fRange = FUN_1401d3200()->m_168.FUN_1402bac70();
    float fToTarget = (kPos - kCamera).Length();
    if (fToTarget > (kPlayer - kCamera).Length())
    {
        float fRatio = FUN_140a0fde0(1.0f, FUN_140a0fda0(0.0f, (fRange - fDistance) / fRange));
        return 0.5f + fRatio * 0.5f;
    }
    return 1.0f;
}
MS2_REPLACE_METHOD(0x141914A90, UIDamageText, FUN_141914a90, 411, 0x30A6C047);

// @0x141914c40
float UIDamageText::FUN_141914c40(GameObject* pTarget)
{
    float fScale = 1.0f;
    if (pTarget == 0)
        return 1.0f;
    GameObject* pPlayer = static_cast<GameObject*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 1.0f;
    if (pPlayer->FUN_14123c460() == pTarget->FUN_14123c460())
        return 1.0f;
    NiNode* pRoot = FUN_1413fa070(pTarget->FUN_14123c460());
    if (pRoot != 0)
        return FUN_141914a90(*FUN_140947900((NiAVObject*)pRoot));
    return 1.0f;
}
MS2_REPLACE_METHOD(0x141914C40, UIDamageText, FUN_141914c40, 240, 0xC525D00F);

// @0x141914d40
int UIDamageText::FUN_141914d40(GameObject* pTarget)
{
    if (pTarget == 0)
        return 1;
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001e)
        return 1;
    if (!FUN_1419141a0(pTarget))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141914D40, UIDamageText, FUN_141914d40, 89, 0x4CFCD192);

// MS2-FUNCTIONAL: temp/EH state layout differs (dispUnwindHelp 0x80 vs 0x88); same calls and flow
// @0x141914da0
void UIDamageText::FUN_141914da0(int bAppend, POSITION* pLast, DamageList& list, CounterMap& map,
                                 MS2Ptr<DamageInfo> spInfo, int nMax)
{
    if (spInfo == 0)
        return;
    bool bOver;
    if (!m_bClearing)
        bOver = nMax < (int)list.GetCount();
    else
        bOver = false;
    if (bAppend == 0)
    {
        if (*pLast == 0)
            list.AddHead(spInfo);
        else
        {
            list.InsertAfter(*pLast, spInfo);
            if (bOver)
            {
                MS2Ptr<DamageInfo> spTail = list.RemoveTail();
                if (spTail.get() != 0)
                    FUN_141915150(spInfo->m_nOwnerId, 1, map);
            }
        }
    }
    else if (*pLast == 0)
        *pLast = list.AddHead(spInfo);
    else
    {
        list.AddHead(spInfo);
        if (bOver)
        {
            POSITION pos = *pLast;
            MS2Ptr<DamageInfo> spOld = list.GetPrev(*pLast);
            if (spOld.get() != 0)
            {
                list.RemoveAt(pos);
                FUN_141915150(spOld->m_nOwnerId, 1, map);
            }
        }
    }
    MS2Ptr<CounterInfo> spCounter = FUN_141915240(spInfo->m_nOwnerId, map, spInfo->m_nGrade);
    if (spCounter.get() != 0)
        spInfo->m_nIndex = spCounter->m_nIndex;
}

// @0x141915090
void UIDamageText::FUN_141915090(POSITION pos)
{
    if (m_ownerFollowers.IsEmpty())
        return;
    FUN_141917ab0(pos, &m_posOwnerFollowers, m_ownerFollowers);
}
MS2_REPLACE_METHOD(0x141915090, UIDamageText, FUN_141915090, 86, 0x8191F121);

// @0x1419150f0
void UIDamageText::FUN_1419150f0(POSITION pos)
{
    if (m_normals.IsEmpty())
        return;
    FUN_141917ab0(pos, &m_posNormals, m_normals);
}
MS2_REPLACE_METHOD(0x1419150F0, UIDamageText, FUN_1419150f0, 86, 0x00CD1F29);

// @0x141915150
void UIDamageText::FUN_141915150(const unsigned __int64& nOwnerId, int nCount, CounterMap& map)
{
    if (map.IsEmpty())
        return;
    if (nCount == -1)
        map.RemoveKey(nOwnerId);
    else
    {
        MS2Ptr<CounterInfo> spCounter(0);
        if (map.Lookup(nOwnerId, spCounter) && spCounter.get() != 0)
        {
            spCounter->m_nCount -= nCount;
            if (spCounter->m_nCount <= 0)
                map.RemoveKey(nOwnerId);
        }
    }
}
MS2_REPLACE_METHOD(0x141915150, UIDamageText, FUN_141915150, 232, 0x2B03A287);

// @0x141915240
MS2Ptr<UIDamageText::CounterInfo> UIDamageText::FUN_141915240(unsigned __int64 nOwnerId, CounterMap& map, int nGrade)
{
    MS2Ptr<CounterInfo> spCounter(0);
    if (map.Lookup(nOwnerId, spCounter))
    {
        if (spCounter.get() != 0)
        {
            spCounter->m_nCount++;
            spCounter->m_nIndex++;
            if (spCounter->m_nIndex >= m_nMaxIndex)
                spCounter->m_nIndex = 0;
        }
    }
    else
    {
        spCounter.AssignRaw(new CounterInfo(1, 0));
        map.SetAt(nOwnerId, spCounter);
    }
    return spCounter;
}

// MS2-FUNCTIONAL: temp/EH state layout differs (ip2state offsets); same calls and flow
// @0x1419153d0
void UIDamageText::FUN_1419153d0()
{
    if (!m_ownerFollowers.IsEmpty())
    {
        unsigned int nNow = FUN_140869420();
        float fUIScale = FUN_1422afec0(FUN_14025e7a0(), m_28);
        POSITION pos = m_ownerFollowers.GetHeadPosition();
        while (pos != 0)
        {
            bool bRemove = false;
            unsigned __int64 nOwnerId = 0;
            MS2Ptr<DamageInfo> spInfo = m_ownerFollowers.GetAt(pos);
            if (spInfo == 0 || spInfo->m_spClip == 0 || spInfo->m_spAni == 0)
                bRemove = true;
            else
            {
                spInfo->FUN_141910e60(nNow);
                MS2Ptr<ASMovieClip> spClip = spInfo->m_spClip;
                MS2Ptr<ASMovieClip> spAni = spInfo->m_spAni;
                nOwnerId = spInfo->m_nOwnerId;
                if (!spInfo->FUN_141910f10(nNow))
                {
                    spInfo->FUN_141910e60(nNow);
                    GameObject* pOwner = WorldService::GetInstance()->FUN_141bd0fe0(nOwnerId);
                    if (pOwner == 0)
                        bRemove = true;
                    else
                    {
                        spInfo->FUN_141910ee0(nNow);
                        if (FUN_141914d40(pOwner) == 0)
                        {
                            efd::Point3 kScreen;
                            NiPoint3 kPos;
                            FUN_141914020(pOwner, kPos, m_strDamageNode);
                            if (!Unk_DtCamera::FUN_1409478c0()->FUN_140af0700(kPos, kScreen))
                                spClip->vfunc_4(false);
                            else
                            {
                                kScreen *= fUIScale;
                                MS2Ptr<CounterInfo> spCounter(0);
                                if (m_ownerFollowerCounter.Lookup(nOwnerId, spCounter))
                                {
                                    int nNext = spCounter->m_nIndex + 1;
                                    int nIndex = spInfo->m_nIndex;
                                    int nBehind = nNext - 1 - nIndex;
                                    if (0 < nBehind && spInfo->FUN_141910f60(nNow))
                                    {
                                        spAni->vfunc_13(s_strNext);
                                        spInfo->m_bCanJump = false;
                                        spInfo->m_nState = 1;
                                    }
                                }
                                kScreen.y += FUN_141913af0(pOwner);
                                spClip->FUN_1422c00f0(kScreen.x, kScreen.y);
                                float fDistanceScale = FUN_141914c40(pOwner);
                                float fScale = fDistanceScale * spInfo->m_fScale;
                                static_cast<Unk_DtClip*>(spClip.operator->())->FUN_1422c0290(fScale, fScale);
                                spClip->vfunc_4(true);
                            }
                        }
                        else
                        {
                            spAni->vfunc_7();
                            spClip->vfunc_4(false);
                            bRemove = true;
                        }
                    }
                }
                else
                    bRemove = true;
            }
            POSITION posCur = pos;
            m_ownerFollowers.GetNext(pos);
            if (bRemove)
            {
                FUN_141915150(nOwnerId, 1, m_ownerFollowerCounter);
                FUN_141915090(posCur);
            }
        }
    }
    else if (!m_ownerFollowerCounter.IsEmpty())
        m_ownerFollowerCounter.RemoveAll();
}
MS2_REPLACE_METHOD(0x1419153D0, UIDamageText, FUN_1419153d0, 1457, 0x8F16367D);

// MS2-FUNCTIONAL: temp/EH state layout differs (dispUnwindHelp 0x130 vs 0x120); same calls and flow
// @0x141915990
void UIDamageText::FUN_141915990()
{
    if (!m_normals.IsEmpty())
    {
        if (m_pInterfaceOption != 0 && m_pBattleOption != 0)
        {
            int nShown = 0;
            int nNext = 0;
            int nIndex = 0;
            int nStacked = 0;
            int nMyLine = (int)((float)(m_nLineHeight * m_pInterfaceOption->m_n10) / 100.0);
            int nMyLine2 = nMyLine << 1;
            int nOtherLine = nMyLine;
            int nOtherLine2 = nMyLine2;
            if ((m_pBattleOption->m_n10 & 1) != 0)
            {
                float fLine = (float)m_nLineHeight;
                nOtherLine = (int)(fLine * FUN_1401d3200()->m_c9d0.FUN_140298f40());
                nOtherLine2 = nOtherLine << 1;
            }
            float fUIScale = FUN_1422afec0(FUN_14025e7a0(), m_28);
            unsigned int nNow = FUN_140869420();
            POSITION pos = m_normals.GetHeadPosition();
            while (pos != 0)
            {
                bool bRemove = false;
                unsigned __int64 nOwnerId = 0;
                MS2Ptr<DamageInfo> spInfo = m_normals.GetAt(pos);
                if (spInfo == 0 || spInfo->m_spClip == 0 || spInfo->m_spAni == 0)
                    bRemove = true;
                else
                {
                    nOwnerId = spInfo->m_nOwnerId;
                    MS2Ptr<ASMovieClip> spClip = spInfo->m_spClip;
                    MS2Ptr<ASMovieClip> spAni = spInfo->m_spAni;
                    spInfo->FUN_141910e60(nNow);
                    bool bMine = spInfo->m_bMyDamage;
                    if (!spInfo->FUN_141910f10(nNow))
                    {
                        bool bCritical = spInfo->m_nGrade == 1;
                        bool bCanJump = spInfo->m_bCanJump;
                        bool bHide = false;
                        if (bCanJump)
                        {
                            if (!bCritical)
                            {
                                MS2Ptr<CounterInfo> spCounter(0);
                                m_counter.Lookup(nOwnerId, spCounter);
                                bHide = spCounter == 0 || m_nMaxShown < nShown;
                                if (!bHide)
                                {
                                    int nFirst = spCounter->m_nIndex - m_nJumpCount + 1;
                                    nNext = spCounter->m_nIndex + 1;
                                    nIndex = spInfo->m_nIndex;
                                    if (nFirst < 0)
                                    {
                                        bool bOld = nIndex <= m_nMaxIndex + nFirst - m_nJumpCount;
                                        bHide = nNext < nIndex && nIndex <= m_nMaxIndex + nFirst;
                                    }
                                    else
                                    {
                                        bool bOld = nIndex < nFirst - m_nJumpCount;
                                        bHide = nIndex < nFirst || nNext <= nIndex;
                                    }
                                }
                            }
                        }
                        spInfo->FUN_141910ee0(nNow);
                        if (!bHide)
                        {
                            efd::Point3 kScreen;
                            if (Unk_DtCamera::FUN_1409478c0()->FUN_140af0700(spInfo->m_kPos, kScreen))
                            {
                                nShown = (bCritical || !bCanJump) ? nShown : nShown + 1;
                                spClip->vfunc_3(1);
                                kScreen *= fUIScale;
                                int nBehind = nNext - 1 - nIndex - nStacked;
                                if (bCritical && spInfo->m_nType == 0)
                                {
                                    kScreen.y -= (float)(bMine ? nMyLine2 : nOtherLine2);
                                    nStacked++;
                                }
                                else if (spInfo->m_nType == 0)
                                {
                                    int nLines = nBehind - 1;
                                    if (nLines < 0)
                                        nLines = 0;
                                    int nLinesUp = nLines;
                                    if (0 < nLines)
                                        kScreen.y -= (float)(nLines * (bMine ? nMyLine : nOtherLine));
                                    nStacked = 0;
                                }
                                if (0 < nBehind && !bCritical)
                                {
                                    if (spInfo->FUN_141910f60(nNow))
                                    {
                                        spAni->vfunc_13(s_strNext);
                                        spInfo->m_nState = 1;
                                        spInfo->m_bCanJump = false;
                                    }
                                }
                                kScreen.y += FUN_141913b80(spInfo->m_kPos);
                                spClip->FUN_1422c00f0(kScreen.x, kScreen.y);
                                float fDistanceScale = FUN_141914a90(spInfo->m_kPos);
                                float fScale = fDistanceScale * spInfo->m_fScale;
                                static_cast<Unk_DtClip*>(spClip.operator->())->FUN_1422c0290(fScale, fScale);
                            }
                        }
                        else if (spInfo->m_nState == 0)
                        {
                            spInfo->m_nState = 3;
                            spClip->vfunc_4(false);
                            spInfo->m_bCanJump = false;
                        }
                    }
                    else
                        bRemove = true;
                }
                POSITION posCur = pos;
                m_normals.GetNext(pos);
                if (bRemove)
                {
                    FUN_141915150(nOwnerId, 1, m_counter);
                    FUN_1419150f0(posCur);
                }
            }
        }
    }
    else if (!m_counter.IsEmpty())
        m_counter.RemoveAll();
}
MS2_REPLACE_METHOD(0x141915990, UIDamageText, FUN_141915990, 2469, 0xC5EF7552);

// @0x141916340
void UIDamageText::FUN_141916340()
{
    unsigned int nNow = FUN_140869420();
    if (nNow < m_nLastQueueTime + 200)
        return;
    MS2Ptr<DamageQueueParam> spParam = m_queue.RemoveHead();
    GameObject* pTarget = WorldService::GetInstance()->FUN_141bd1180(spParam->m_nActorId);
    if (pTarget == 0)
        return;
    FUN_141912a80(pTarget, spParam->m_nValue, spParam->m_nType);
    m_nLastQueueTime = nNow;
}

// MS2-FUNCTIONAL: temp/EH state layout differs (ip2state offsets); same calls and flow
// @0x141916430
void UIDamageText::FUN_141916430(MS2Ptr<ASGameEntity> spRoot)
{
    if (spRoot == 0 || m_ownerFollowers.IsEmpty())
        return;
    float fUIScale = FUN_1422afec0(FUN_14025e7a0(), m_28);
    bool bGarbageSeen = false;
    POSITION pos = m_ownerFollowers.GetHeadPosition();
    while (pos != 0)
    {
        MS2Ptr<DamageInfo> spInfo = m_ownerFollowers.GetAt(pos);
        if (spInfo == 0)
            continue;
        MS2Ptr<ASMovieClip> spClip = spInfo->m_spClip;
        if (spClip == 0)
            continue;
        bool bRemove = false;
        unsigned __int64 nOwnerId = spInfo->m_nOwnerId;
        bool bMine = spInfo->m_bMyDamage;
        bool bGarbage = bGarbageSeen || FUN_1409c1720(spClip->FUN_1422baa20(s_strGarbage));
        if (!bGarbage)
        {
            if (FUN_1409c1720(spClip->FUN_1422baa20(s_strDecreaseCounter)))
            {
                static_cast<Unk_DtClip*>(spClip.operator->())->FUN_1407cbbe0(s_strDecreaseCounter, false);
                spInfo->m_bDecreased = true;
                FUN_141915150(nOwnerId, 1, m_ownerFollowerCounter);
            }
            GameObject* pOwner = WorldService::GetInstance()->FUN_141bd0fe0(nOwnerId);
            if (pOwner == 0)
                bRemove = true;
            else if (FUN_141914d40(pOwner) == 0)
            {
                efd::Point3 kScreen;
                NiPoint3 kPos;
                FUN_141914020(pOwner, kPos, m_strDamageNode);
                if (!Unk_DtCamera::FUN_1409478c0()->FUN_140af0700(kPos, kScreen))
                    spClip->vfunc_3(0);
                else
                {
                    kScreen *= fUIScale;
                    MS2Ptr<CounterInfo> spCounter(0);
                    if (m_ownerFollowerCounter.Lookup(nOwnerId, spCounter))
                    {
                        int nNext = spCounter->m_nIndex + 1;
                        int nIndex = spInfo->m_nIndex;
                        int nBehind = nNext - 1 - nIndex;
                        if (0 < nBehind)
                            m_onNextAni.InvokeSelf(0, &spClip->FUN_1422bb870(), 1);
                    }
                    kScreen.y += FUN_141913af0(pOwner);
                    spClip->FUN_1422c00f0(kScreen.x, kScreen.y);
                    float fDistanceScale = FUN_141914c40(pOwner);
                    float fScale = fDistanceScale * spInfo->m_fScale;
                    static_cast<Unk_DtClip*>(spClip.operator->())->FUN_1422c0290(fScale, fScale);
                    spClip->vfunc_3(1);
                }
            }
            else
                spClip->vfunc_3(0);
        }
        else
        {
            if (!bGarbageSeen && !bMine)
                bGarbageSeen = true;
            bRemove = true;
        }
        POSITION posCur = pos;
        m_ownerFollowers.GetNext(pos);
        if (bRemove)
        {
            if (!spInfo->m_bDecreased)
                FUN_141915150(nOwnerId, 1, m_counter);
            FUN_141915090(posCur);
        }
    }
}
MS2_REPLACE_METHOD(0x141916430, UIDamageText, FUN_141916430, 1669, 0x29E50C8E);

// MS2-FUNCTIONAL: temp/EH state layout differs (dispUnwindHelp 0x158 vs 0x160); same calls and flow
// @0x141916ac0
void UIDamageText::FUN_141916ac0(MS2Ptr<ASGameEntity> spRoot)
{
    if (spRoot == 0 || m_normals.IsEmpty())
        return;
    if (m_pInterfaceOption == 0 || m_pBattleOption == 0)
        return;
    if (m_spDamageEnable == 0 || m_spDamageGarbage == 0)
        return;
    bool bGarbageSeen = false;
    int nShown = 0;
    POSITION pos = m_normals.GetHeadPosition();
    int nNext = 0;
    int nIndex = 0;
    int nStacked = 0;
    int nMyLine = (int)((float)(m_nLineHeight * m_pInterfaceOption->m_n10) / 100.0);
    int nMyLine2 = nMyLine << 1;
    int nOtherLine = nMyLine;
    int nOtherLine2 = nMyLine2;
    if ((m_pBattleOption->m_n10 & 1) != 0)
    {
        float fLine = (float)m_nLineHeight;
        nOtherLine = (int)(fLine * FUN_1401d3200()->m_c9d0.FUN_140298f40());
        nOtherLine2 = nOtherLine << 1;
    }
    while (pos != 0)
    {
        MS2Ptr<DamageInfo> spInfo = m_normals.GetAt(pos);
        if (spInfo == 0)
            continue;
        bool bRemove = false;
        unsigned __int64 nOwnerId = spInfo->m_nOwnerId;
        MS2Ptr<ASMovieClip> spClip = spInfo->m_spClip;
        if (spClip.get() != 0)
        {
            bool bMine = spInfo->m_bMyDamage;
            Scaleform::GFx::Value& clip = spClip->FUN_1422bb870();
            bool bGarbage = bGarbageSeen || FUN_1409c1720(static_cast<Unk_SsFn*>(m_spDamageGarbage.operator->())->FUN_1417620b0(clip)) == true;
            if (!bGarbage)
            {
                bool bCritical = spInfo->m_nGrade == 1;
                bool bEnable = FUN_1409c1720(static_cast<Unk_SsFn*>(m_spDamageEnable.operator->())->FUN_1417620b0(clip));
                bool bOld = false;
                bool bHide = false;
                if (bEnable)
                {
                    if (!bCritical)
                    {
                        MS2Ptr<CounterInfo> spCounter(0);
                        m_counter.Lookup(nOwnerId, spCounter);
                        bHide = spCounter == 0 || m_nMaxShown < nShown;
                        if (!bHide)
                        {
                            int nFirst = spCounter->m_nIndex - m_nJumpCount + 1;
                            nNext = spCounter->m_nIndex + 1;
                            nIndex = spInfo->m_nIndex;
                            if (nFirst < 0)
                            {
                                bOld = nIndex <= m_nMaxIndex + nFirst - m_nJumpCount;
                                bHide = nNext < nIndex && nIndex <= m_nMaxIndex + nFirst;
                            }
                            else
                            {
                                bOld = nIndex < nFirst - m_nJumpCount;
                                bHide = nIndex < nFirst || nNext <= nIndex;
                            }
                        }
                    }
                }
                if (!bHide)
                {
                    efd::Point3 kScreen;
                    if (!Unk_DtCamera::FUN_1409478c0()->FUN_140af0700(spInfo->m_kPos, kScreen))
                        spClip->vfunc_4(false);
                    else
                    {
                        nShown = (bCritical || !bEnable) ? nShown : nShown + 1;
                        spClip->vfunc_4(true);
                        kScreen *= FUN_1422afec0(FUN_14025e7a0(), m_28);
                        int nBehind = nNext - 1 - nIndex - nStacked;
                        if (bCritical && spInfo->m_nType == 0)
                        {
                            kScreen.y -= (float)(bMine ? nMyLine2 : nOtherLine2);
                            nStacked++;
                        }
                        else if (spInfo->m_nType == 0)
                        {
                            int nLines = nBehind - 1;
                            if (nLines < 0)
                                nLines = 0;
                            if (0 < nLines)
                            {
                                int nLine = nMyLine;
                                if (!bMine)
                                    nLine = nOtherLine;
                                kScreen.y -= (float)(nLines * nLine);
                            }
                            nStacked = 0;
                        }
                        if (0 < nBehind && !bCritical)
                            m_onNextAni.InvokeSelf(0, &clip, 1);
                        kScreen.y += FUN_141913b80(spInfo->m_kPos);
                        spClip->FUN_1422c00f0(kScreen.x, kScreen.y);
                        float fDistanceScale = FUN_141914a90(spInfo->m_kPos);
                        float fScale = fDistanceScale * spInfo->m_fScale;
                        static_cast<Unk_DtClip*>(spClip.operator->())->FUN_1422c0290(fScale, fScale);
                    }
                }
                else if (bOld)
                {
                    m_onForceRemove.InvokeSelf(0, &clip, 1);
                    bRemove = true;
                }
                else
                    m_onJumpAni.InvokeSelf(0, &clip, 1);
            }
            else
            {
                if (!bGarbageSeen && !bMine)
                    bGarbageSeen = true;
                bRemove = true;
            }
        }
        POSITION posCur = pos;
        m_normals.GetNext(pos);
        if (bRemove)
        {
            FUN_141915150(nOwnerId, 1, m_counter);
            FUN_1419150f0(posCur);
        }
    }
}
MS2_REPLACE_METHOD(0x141916AC0, UIDamageText, FUN_141916ac0, 2804, 0x61338552);

// MS2-FUNCTIONAL: temp/EH state layout differs (ip2state states); same calls and flow
// @0x1419175c0
int UIDamageText::FUN_1419175c0(MS2Ptr<DamageInfo> spInfo, NiPoint3 kPos, GameObject* pTarget,
                                const Scaleform::GFx::Value& clip, const efd::Point3& kScreen, int bAppend)
{
    if (spInfo == 0)
        return 0;
    if (!FUN_1409b4d40(clip))
        return 0;
    int bRecover = FUN_1419144b0(spInfo->m_nGrade);
    MS2Ptr<ASMovieClip> spClip(new ASMovieClip(Scaleform::GFx::Value(clip), m_28));
    if (spClip.get() != 0)
    {
        spInfo->m_spClip = spClip;
        Scaleform::GFx::Value ani = spClip->FUN_1422baa20("m_ani");
        spInfo->m_spAni.AssignRaw(new ASMovieClip(Scaleform::GFx::Value(ani), m_28));
        spInfo->m_fScale = static_cast<Unk_DtClip*>(spClip.operator->())->FUN_1422c11f0();
        NiPoint3 kWorld = kPos;
        if (bRecover == 0)
            FUN_141914da0(bAppend, &m_posNormals, m_normals, m_counter, spInfo, m_nMaxList);
        else
            FUN_141914da0(bAppend, &m_posOwnerFollowers, m_ownerFollowers, m_ownerFollowerCounter, spInfo, m_nMaxList);
        spClip->vfunc_3(0);
    }
    vfunc_8(1);
    return 1;
}

// @0x141917a20
void UIDamageText::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x141917A20, UIDamageText, vfunc_41, 99, 0x9A0FF887);

// @0x141917a90
void UIDamageText::vfunc_16()
{
    FUN_1419135c0();
}
MS2_REPLACE_METHOD(0x141917A90, UIDamageText, vfunc_16, 24, 0x78A52482);

// @0x141917bf0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, CString a2, CString a3, CString a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    FUN_1422bce70(args.FUN_1409b1f70(2), a3);
    FUN_1422bce70(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}
