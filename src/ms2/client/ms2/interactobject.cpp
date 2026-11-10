// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\interactobject.cpp
// MS2-RANGE: 0x1400f5200-0x1400f5230 .text$di
// MS2-RANGE: 0x1413fd240-0x1414043e0 .text$mn
// MS2-RANGE: 0x142cb1720-0x142cb1740 .text$yd
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@0@AEAV10@@Z 0x141403920
// MS2-PIN: ?begin@?$vector@UUnk_InteractReqItem@@V?$allocator@UUnk_InteractReqItem@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@std@@@2@XZ 0x1414040e0
// MS2-PIN: ?end@?$vector@UUnk_InteractReqItem@@V?$allocator@UUnk_InteractReqItem@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_InteractReqItem@@@std@@@std@@@2@XZ 0x1414041a0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCInteractTelescopeObject@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141404140
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\interactobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <io.h>
#include <string>
#include "interactobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "notifychangebuff.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/masterytable.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/gfxui/uiswfentity.h"
#include "physxhelper.h"
#include <efd/AssetID.h>
#include <efd/Point3.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <NiTexture.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cwinhttpclient.h"

// MS2-FUNCTIONAL: unit-wide; the bodies lean on many unrecovered services (world, effect, ranking, url and quest managers) that are
// declared as FUN_<va> externs with approximated signatures, and on out-of-line COMDATs of other objs, so only the trivial
// virtuals and the smart-pointer / iterator COMDATs are expected to be byte-identical.

// ---- the unit's header static (.text$di 0x1400f5200, atexit thunk 0x142cb1720): the sound name played when a telescope is used ----
#ifndef MS2_HOOK_DLL
static CString s_strUseTelescope("PC_use_telescope");       // 0x143ad97b8
#else
extern CString s_strUseTelescope;
#endif

// ---- exe callees (unit-local stand-ins) ----
// @0x141404030
static bool HasItems(CInteractObjectData::ConditionEffectList& reqItem)
{
    if (reqItem.m_aItem.empty())
        return false;
    return true;
}
class Unk_IoPlayerBase
{
public:
    virtual void vf00() = 0; virtual void vf01() = 0; virtual void vf02() = 0; virtual void vf03() = 0;
    virtual void vf04() = 0; virtual void vf05() = 0; virtual void vf06() = 0; virtual void vf07() = 0;
    virtual void vf08() = 0; virtual void vf09() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0;
    virtual Vector3 GetPosition() = 0;                      // 18
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29() = 0;
    virtual void vf30() = 0;
    virtual void vf31() = 0;
    virtual void vf32() = 0;
    virtual void vf33() = 0;
    virtual void vf34() = 0;
    virtual void vf35() = 0;
    virtual void vf36() = 0;
    virtual void vf37() = 0;
    virtual void vf38() = 0;
    virtual void vf39() = 0;
    virtual void vf40() = 0;
    virtual void vf41() = 0;
    virtual void vf42() = 0;
    virtual void vf43() = 0;
    virtual void vf44() = 0;
    virtual void vf45() = 0;
    virtual void vf46() = 0;
    virtual void vf47() = 0;
    virtual void vf48() = 0;
    virtual void vf49() = 0;
    virtual void vf50() = 0;
    virtual void vf51() = 0;
    virtual void vf52() = 0;
    virtual void vf53() = 0;
    virtual void vf54() = 0;
    virtual void vf55() = 0;
    virtual void vf56() = 0;
    virtual void vf57() = 0;
    virtual void vf58() = 0;
    virtual void SendState(int nKind, void* pData, int nMsg, int nZero) = 0;   // 59
};
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/triggerservice.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/client/ms2/uicutscenecinematic.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/blindmanager.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/commonfiles/contentshutdown.h"
#include "ms2/placeholder/cmasterymanager.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/applyeffect.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/client/ms2/gamerankingcli.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ms2scenegraphservice.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/placeholder/cwebbrowserservice.h"




#include "ms2/client/ms2/additionalclilist.h"   // PCBase +0x748 (C3: the local AdditionalCliList view is gone)
class Unk_IoPlayer : public Unk_IoPlayerBase
{
public:
};
struct Unk_IoCutData
{
    char m_pad_000[0x1fd];
    bool m_b1fd;
    char m_pad_1fe[2];
    int m_n200;
    float m_n204;
    float m_n208;
    bool m_b20c;
    char m_pad_20d[3];
    unsigned m_n210;
    float m_n214;
    float m_n218;
    float m_n21c;
};
struct Unk_IoRanking
{
    int m_nRank;                // +0x00
    int m_pad_04;
    int m_nScore;               // +0x08
    char m_pad_0c[0x14];
    unsigned __int64 m_u20;     // +0x20 guild serial
    char m_pad_28[8];
    unsigned __int64 m_u30;     // +0x30 character serial
    CStringW m_str38;           // +0x38 character name
    char m_pad_40[8];
    CStringW m_str48;           // +0x48 guild name
    char m_pad_50[0x28];
    CStringW m_str78;           // +0x78 image key
};
MS2_CHECK_SIZE(Unk_IoRanking, 0x80);
class Unk_IoWorld : public WorldService
{
};
// 0x141bdb0f0 queues a ranking entry; worldservice_1.cpp defines it as a free function on the service.
void FUN_141bdb0f0(WorldService* self, CStringA name, TPtrValue<CGameRankingData> value);
class Unk_IoQuestEval
{
public:
    virtual void vf00() = 0; virtual void vf01() = 0; virtual void vf02() = 0; virtual void vf03() = 0;
    virtual void vf04() = 0; virtual void vf05() = 0; virtual void vf06() = 0; virtual void vf07() = 0;
    virtual void vf08() = 0; virtual void vf09() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0; virtual void vf18() = 0; virtual void vf19() = 0;
    virtual void vf20() = 0; virtual void vf21() = 0; virtual void vf22() = 0;
    virtual int CheckMask(const QuestMask* pMask) = 0;          // 23
};
struct Unk_IoQuestMgr
{
    char m_pad_00[0x10];
    void* m_pEvalVptr;
};
void* FUN_140764020();   // C3: was FUN_140764020
extern QuestMask DAT_143aacd50;                                 // empty mask

class Unk_IoSession : public CFeatureManager
{
public:
};
class Unk_IoMapRules { public: unsigned char IsShutdown(unsigned nMapId, int nBanType); };
class Unk_IoGameCtx { public: Unk_IoMapRules* FUN_1403f3230(); };
void FUN_141275260(int, int, int);
int FUN_141276180(const CString&, const CString&);
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class Unk_IoCfg { public: int FUN_1402c4c90(int n); };
struct Unk_IoCfgHolder { char m_pad_00[8]; Unk_IoCfg m_cfg; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0

class Unk_AvPhysicsSvc* GetPhysXHelper();   // C3: was GetPhysXHelper

// item inventory
extern Unk_Inventory g_143ab2a90;
int FUN_14053feb0(int nItemId);

// condition helpers
struct Unk_IoRefOwner;

// entity and property access
void FUN_140b27ec0(void* e, unsigned nHash, void* pOut);
int FUN_1408a2060(Unk_Entity* e, unsigned nHash, efd::utf8string* pOut);
int FUN_140998250(Unk_Entity* e, unsigned nHash, efd::AssetID* pOut);
void SetCachedBoolProperty(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0
void SetAssetIdProperty(egf::Entity* e, unsigned nHash, efd::AssetID* pValue);
const egf::EntityID* FUN_1408b76f0(Unk_Entity* e);
egf::EntityID* FUN_1408b6b20(egf::EntityID* pDst, const egf::EntityID* pSrc);
void FUN_1401cd100(egf::EntityID* pDst, int n);
unsigned __int64 FUN_140affe40(Unk_Entity* e);
CString FUN_141b70dd0(struct Unk_UtilNameSrc* e);
void FUN_1401d3700(CString& s);
void SetEntityHighlight(egf::EntityID id, bool bEnable, unsigned uColor, bool bSkipEffectRoot);    // util.cpp
const char* FUN_1408ac310(efd::utf8string* p);
const char* Unk_AssetUrnText(const efd::AssetID* pAsset);
void FUN_1409989e0(efd::utf8string* p, const char* psz);
void FUN_140de0cb0(efd::AssetID* pDst, efd::utf8string* pStr);
void FUN_1408a8900(efd::utf8string* p);
class Unk_AnimSvc { public: bool PlayAnimation(const egf::EntityID& id, const efd::utf8string& strName, float fVol, bool bLoop); };
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();

// physics prop object of a mesh interact object






// egfPhysX::EntityActorData (a MemObject); the owner is a by-value SmartPointer<Entity> that the ctor releases
#include <egfPhysX/EntityActorData.h>









// notices

// highlight manager
namespace ecr { class SceneGraphService; }
ecr::SceneGraphService* GetSceneGraphService();

// post effect / system sound / ui
struct Unk_GpState* GetGamepadState(class Unk_GpSettings*);   // C3: the real function (0x140a58500, gameoptiongamepad.cpp)
class Unk_McEntityRules* GetTriggerService();   // C3: was GetTriggerService
class CUserMail { public: static __int64 GetGFxSceneService(); };   // C3: the scene-service global (usermail.h clashes on FUN_141276180)
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1422b9fd0(int);
};
void* FindCutSceneCinematic(int);   // C3: was FindCutSceneCinematic
CStringW GetStringCommon(int nStringId);
CStringW GetStringCommonByKey(const CStringW& str);
   // member (this=rcx, hidden return=rdx)
// FUN_1409331f0 (the CKeyTable instance) is declared in ckeytable.h
class Unk_IoUiMgr { public: void FUN_141adc530(int n); };
UISwfEntityManager* GetUISwfEntityManager();
DWORD GetTickCountMs2();

// gathering and tables
class UIMasteryObjectMark   // C3: member view for the former free stand-ins
{
public:
    void AddNodeMark(class CInteractObject*);
};
template <typename T> T* Unk_FcDialog(int nId);
class Unk_IoGatherChk : public CMasteryManager { public: };
extern ATL::CAtlMap<int, int> g_143ab3150;
class Unk_IoCursorMgr : public CGameEventValueMasteryReduce { public: int FUN_1404240e0(int n);};
class Unk_IoBoardSvc;
template <typename T> T* GetItemUseDialog(int nId);
class UIItemBillBoardDialog   // C3: member view for the former free stand-ins
{
public:
    __int64 GetBillboardOwner();
};
class Unk_IoStream
{
public:
    virtual void vf0(); virtual void vf1();
    virtual unsigned short ReadShort(); // 2
    virtual int ReadInt();              // 3
};
struct Unk_InteractMsg
{
    void* m_pad_00;
    Unk_IoStream m_stream;          // +0x08
};

// ================================================================================================================
// CInteractObject
// ================================================================================================================

// @0x1413fd240
CInteractObject::CInteractObject()
    : m_ent(0)
    , m_strName()
    , m_nState(0)
    , m_nShownState(3)
{
    m_spRow = 0;
    m_ent = 0;
    m_nEffect = 0;
    m_nRowId = 0;
    m_nParticle = 0;
    m_nVisible = 0;
    m_bHighlight = 1;
    m_timer.Reset();
    m_bSpawned = 0;
}

// @0x1413fd380
CInteractObject::~CInteractObject()
{
    ClearStateEffect();
    if (m_nParticle != 0)
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nParticle);
    m_spRow = 0;
    m_ent = 0;
}

// @0x1413fd460
int CInteractObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    if (pEntity == 0)
        return 0;
    m_ent.operator=((egf::Entity*)pEntity);
    ((egf::Entity*)pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)m_vPos);
    ((egf::Entity*)pEntity)->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)m_vRot);
    ((egf::Entity*)pEntity)->GetPropertyValue<int>(0xd460e9bc, m_nRowId);
    m_spRow = CInteractObjectData::Get(m_nRowId);
    if (!m_spRow)
        return 0;
    m_strName = FUN_141b70dd0((Unk_UtilNameSrc*)pEntity);
    FUN_1401d3700(m_strName);
    if (m_strName.GetLength() == 0)
        return 0;
    vfunc_3(nState);
    NotifySystem::GetInstance()->Post(MS2Ptr<NotifyObject>(new NotifyAddInteract(this)));
    return 1;
}

// @0x1413fd6b0
void CInteractObject::vfunc_2(Unk_InteractMsg*)
{
}

// @0x1413fd6d0
void CInteractObject::vfunc_3(int nState)
{
    if (m_ent.operator==((egf::Entity*)0))
        return;
    if (m_spRow == 0)
        return;
    m_nState = nState;
    UpdateStateEffect();
}

// @0x1413fd740
int CInteractObject::vfunc_4()
{
    if (m_nState != 1)
        return 0;
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    unsigned nMapId = (unsigned)WorldService::GetInstance()->FUN_141bd3060();
    if (TSingleton<CGameEventValueManager>::GetInstance()->ShutdownInteractObjectId()->IsShutdown(nMapId, m_spRow->m_nId) == 1)
    {
        FUN_141275260(0x2f7, 1, 1);
        return 0;
    }
    if (!CheckHomePrivilege())
        return 0;
    if (!CheckArenaTeam())
        return 0;
    if (!HasAnyRequiredItem())
        return 0;
    if (!FUN_1413fdfc0())
        return 0;
    if (!CheckItemRequirement())
        return 0;
    if (!HasRequiredMastery())
        return 0;
    return 1;
}

// @0x1413fd890
efd::SmartPointer<egf::Entity> CInteractObject::GetEnt()
{
    return m_ent;
}

// @0x1413fd8e0
egf::EntityID CInteractObject::GetEntityID()
{
    if (m_ent.operator==((egf::Entity*)0))
        return egf::EntityID(0);
    return m_ent->GetEntityID();
}

// @0x1413fd960
unsigned __int64 CInteractObject::GetEntityIDValue()
{
    if (m_ent.operator==((egf::Entity*)0))
        return 0;
    return m_ent->GetEntityIDValue();
}

// @0x1413fd9b0
void CInteractObject::vfunc_6(Unk_InteractCursor* pOut)
{
    pOut->m_strHint = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xb, GetRowId());
    pOut->m_nCursor = m_spRow->m_nReactTime;
}

// @0x1413fda50
void CInteractObject::ShowStateEffect()
{
    if (m_nShownState == m_nState)
        return;
    ClearStateEffect();
    CString strAsset = vfunc_13();
    if (strAsset.GetLength() != 0)
    {
        NiTransform xf;
        xf.m_Translate = reinterpret_cast<const efd::Point3&>(m_vPos) + efd::Point3(0.0f, 0.0f, 1.0f);
        xf.m_Rotate.FromEulerAnglesXYZ((m_vRot.x * 3.1415927f) / 180.0f, (m_vRot.y * 3.1415927f) / 180.0f,
                                       (m_vRot.z * 3.1415927f) / 180.0f);
        xf.m_fScale = 1.0f;
        NoticeMessage request;
        request.m_strName = strAsset;
        request.m_nObject = 0;
        request.m_p18 = &xf;
        m_nEffect = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&request));
        m_nShownState = m_nState;
    }
}

// @0x1413fdc50
void CInteractObject::ClearStateEffect()
{
    if (m_nEffect != 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
        m_nShownState = 3;
    }
}

// @0x1413fdca0
void CInteractObject::SetVisible(unsigned char bVisible)
{
    if (m_ent.operator egf::Entity*() == 0)
        return;
    m_nVisible = bVisible;
    if (bVisible != 0)
        SetEntityHighlight(m_ent->GetEntityID(), true, 1, false);
    else
        SetEntityHighlight(m_ent->GetEntityID(), false, 1, false);
}

// @0x1413fdd80
int CInteractObject::HasRequiredMastery()
{
    if (!m_spRow)
        return 0;
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow->m_mastery.m_eType != 0)
    {
        int nItemId = m_spRow->m_mastery.m_eType;
        int nNeed = m_spRow->m_mastery.m_nValue;
        if (reinterpret_cast<PC*>(pPlayer)->GetMasteryGrade(nItemId) < nNeed)
            return 0;
    }
    return 1;
}

// @0x1413fde40
int CInteractObject::CheckItemRequirement()
{
    if (!m_spRow)
        return 0;
    if (m_spRow->m_item.m_nCode != 0)
    {
        int nRarity = m_spRow->m_item.m_nRank;
        if (nRarity == 0)
            nRarity = FUN_14053feb0(m_spRow->m_item.m_nCode);
        MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5e5c0(m_spRow->m_item.m_nCode, nRarity);
        if (!spItem)
            return 0;
        if ((unsigned)((CItem*)spItem)->GetCount() < m_spRow->m_item.m_nConsume)
            return 0;
        if (((CItem*)spItem)->GetRarity() != nRarity)
            return 0;
    }
    return 1;
}

// @0x1413fdfc0
int CInteractObject::FUN_1413fdfc0()
{
    if (m_spRow == 0)
        return 0;
    Unk_IoQuestEval* pEval = reinterpret_cast<Unk_IoQuestEval*>(&((struct Unk_IoQuestMgr*)FUN_140764020())->m_pEvalVptr);
    return pEval->CheckMask(&m_spRow->m_maskUse);
}

// @0x1413fe040
int CInteractObject::CheckHomePrivilege()
{
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    if (m_spRow->m_homePrivilege.m_nCheck == 0)
        return 1;
    return reinterpret_cast<MyPC*>(pPlayer)->GetHomePrivilege()->FUN_14050d890(GetRowId());
}

// @0x1413fe120
int CInteractObject::CheckArenaTeam()
{
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    int nNeed = m_spRow->m_arena.m_nCanInteractTeamId;
    if (nNeed == 0)
        return 1;
    bool bSame = reinterpret_cast<CPvPInfo*>(reinterpret_cast<PC*>(pPlayer)->GetPvPInfo().operator->())->GetPoint() == nNeed;
    if (bSame)
        return 1;
    return 0;
}

// @0x1413fe220
int CInteractObject::HasAnyRequiredItem()
{
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow == 0)
        return 0;
    if (!HasItems(m_spRow->m_aReqItem))
        return 1;
    std::vector<Unk_InteractReqItem>& aReq = m_spRow->m_aReqItem.m_aItem;
    std::vector<Unk_InteractReqItem>::const_iterator itEnd = aReq.end();
    for (std::vector<Unk_InteractReqItem>::const_iterator it = aReq.begin(); it != itEnd; ++it)
    {
        Unk_InteractReqItem req = Unk_InteractReqItem(*it);
        if (reinterpret_cast<AdditionalCliList*>(reinterpret_cast<PCBase*>(pPlayer)->FUN_1416749a0())->FUN_140970020(req.first, req.second, 0, 1) == 1)
            return 1;
    }
    return 0;
}

// @0x1413fe370
void CInteractObject::vfunc_8()
{
    if (vfunc_4() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::InteractObject), 0);
        packet.WriteUInt8(0xb);
        packet.WriteInt32(1);
        packet.WriteString(GetName());
        FUN_140710590(packet);
    }
}

// @0x1413fe430
void CInteractObject::vfunc_9()
{
}

// @0x1413fe440
void CInteractObject::vfunc_10()
{
    if (vfunc_4() != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::InteractObject), 0);
        packet.WriteUInt8(0xc);
        packet.WriteInt32(1);
        packet.WriteString(GetName());
        FUN_140710590(packet);
    }
}

// @0x1413fe500
void CInteractObject::UpdateStateEffect()
{
    if (FUN_1413fdfc0() == 0 ||
        reinterpret_cast<Unk_IoQuestEval*>(&((struct Unk_IoQuestMgr*)FUN_140764020())->m_pEvalVptr)->CheckMask(GetStateQuestMask()) == 0)
        ClearStateEffect();
    else
        ShowStateEffect();
}

// @0x1413fe580
void CInteractObject::vfunc_11()
{
    if (m_timer.IsExpired() != 0)
    {
        m_timer.Reset();
        DisableDynamicUpdate(0);
    }
}

// @0x1413fe5d0
void CInteractObject::vfunc_12()
{
    if (m_spRow->m_effect.m_strSuccess.GetLength() != 0)
    {
        NiTransform xf;
        xf.m_Translate = reinterpret_cast<const efd::Point3&>(m_vPos) + efd::Point3(0.0f, 0.0f, 1.0f);
        xf.m_Rotate.FromEulerAnglesXYZ((m_vRot.x * 3.1415927f) / 180.0f, (m_vRot.y * 3.1415927f) / 180.0f,
                                       (m_vRot.z * 3.1415927f) / 180.0f);
        xf.m_fScale = 1.0f;
        NoticeMessage request;
        request.m_strName = m_spRow->m_effect.m_strSuccess;
        request.m_nObject = 1;
        request.m_p18 = &xf;
        Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
        if (pPlayer != 0)
            request.SetActor(reinterpret_cast<GameObject*>(pPlayer)->GetObjectId());
        m_nParticle = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&request));
    }
}

// @0x1413fe7d0
CString CInteractObject::vfunc_13()
{
    switch (m_nState)
    {
    case 0:
        return m_spRow->m_effect.m_strNormal;
    case 1:
        return m_spRow->m_effect.m_strReactable;
    }
    return CString();
}

// @0x1413fe8a0
QuestMask* CInteractObject::GetStateQuestMask()
{
    switch (m_nState)
    {
    case 0:
        return &m_spRow->m_effect.m_maskNormal;
    case 1:
        return &m_spRow->m_effect.m_maskReactable;
    }
    return &DAT_143aacd50;
}

// @0x1413fe910
void CInteractObject::EnableHighlight()
{
    if (m_bHighlight != 0)
        return;
    if (m_ent.operator==((egf::Entity*)0))
        return;
    if (vfunc_5() == 8)
        return;
    reinterpret_cast<MS2SceneGraphService*>(GetSceneGraphService())->MarkEntityDynamic(m_ent.operator egf::Entity*());
    m_bHighlight = 1;
}

// @0x1413fe9a0
void CInteractObject::DisableDynamicUpdate(int nDelay)
{
    if (m_bHighlight == 0)
        return;
    if (m_ent.operator==((egf::Entity*)0))
        return;
    if (vfunc_5() == 8)
        return;
    bool bFlag = false;
    if (m_ent.operator->()->GetPropertyValue<bool>(0x2e0ec6f3, bFlag) == 0 && bFlag)
        return;
    if (nDelay != 0)
    {
        m_timer.Start(nDelay);
    }
    else
    {
        reinterpret_cast<MS2SceneGraphService*>(GetSceneGraphService())->RemoveEntityFromUpdate(m_ent.operator egf::Entity*());
        m_bHighlight = 0;
    }
}

// ================================================================================================================
// CInteractMeshObject
// ================================================================================================================

// @0x1413fea90
CInteractMeshObject::CInteractMeshObject()
    : m_spProp(0)
    , m_strAssetA()
    , m_strAssetB()
{
    m_pActor = 0;
    m_spProp = 0;
}

// @0x1413feb40
CInteractMeshObject::~CInteractMeshObject()
{
    ReleaseActor();
    m_pActor = 0;
    m_spProp = 0;
}

// @0x1413febf0
int CInteractMeshObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    m_spProp = new (efd::MemHint(efd::MemHint::NONE)) egfPhysX::EntityActorData((egf::Entity*)pEntity);
    if (((egf::Entity*)pEntity)->GetModel()->ContainsModel("MS2InteractMesh"))
    {
        efd::AssetID idA;
        efd::AssetID idB;
        ((egf::Entity*)pEntity)->GetPropertyValue<efd::AssetID>(0x770e5fc6, idA);
        ((egf::Entity*)pEntity)->GetPropertyValue<efd::AssetID>(0xae1cf70e, idB);
        m_strAssetA = Unk_AssetUrnText(&idA);
        m_strAssetB = Unk_AssetUrnText(&idB);
        m_nAssetType = 1;
    }
    else if (((egf::Entity*)pEntity)->GetModel()->ContainsModel("MS2InteractActor"))
    {
        efd::utf8string strA;
        efd::utf8string strB;
        ((egf::Entity*)pEntity)->GetPropertyValue<efd::utf8string>(0x3ff293c8, strA);
        ((egf::Entity*)pEntity)->GetPropertyValue<efd::utf8string>(0x63c7b14a, strB);
        m_strAssetA = strA.c_str();
        m_strAssetB = strB.c_str();
        m_nAssetType = 2;
    }
    else
        return 0;
    return CInteractObject::vfunc_1(pEntity, nState);
}

// @0x1413fef20
void CInteractMeshObject::vfunc_3(int nState)
{
    CInteractObject::vfunc_3(nState);
    if (m_spRow == 0)
        return;
    if (m_ent.operator==((egf::Entity*)0))
        return;
    if (m_nState == 0)
    {
        EnableHighlight();
        DisableDynamicUpdate(5000);
    }
    else if (m_nState == 1)
    {
        EnableHighlight();
        DisableDynamicUpdate(5000);
    }
    else
    {
        DisableDynamicUpdate(0);
    }
    if (m_nState == 2)
    {
        unsigned char bFlag = 0;
        SetCachedBoolProperty((class Unk_CachedEntity*)((Unk_Entity*)m_ent.operator->()), 0xa0b6b179, *(bool const*)(&bFlag));
        return;
    }
    unsigned char bFlag = 1;
    SetCachedBoolProperty((class Unk_CachedEntity*)((Unk_Entity*)m_ent.operator->()), 0xa0b6b179, *(bool const*)(&bFlag));
    unsigned bFirst = m_nState == 0;
    CString* pAsset = bFirst != 0 ? &m_strAssetA : &m_strAssetB;
    FUN_1413ff690(*pAsset);
    int nCollision;
    if (bFirst != 0)
        nCollision = m_spRow->m_mesh.m_nNormalCollision;
    else
        nCollision = m_spRow->m_mesh.m_nReactableCollision;
    SetCollision(nCollision);
}

// @0x1413ff0f0
int CInteractMeshObject::vfunc_4()
{
    return CInteractObject::vfunc_4();
}

// @0x1413ff110
void CInteractMeshObject::vfunc_8()
{
    CInteractObject::vfunc_8();
    PlayReactAni();
}

// @0x1413ff140
void CInteractMeshObject::vfunc_9()
{
    CInteractObject::vfunc_9();
    ApplyAssetB();
}

class NiPhysXTypes   // C3: member view for the former free stand-ins
{
public:
    static void NiPoint3ToNxVec3(class NiPoint3 const&, class NxVec3&);
};

// @0x1413ff170
void CInteractMeshObject::MakeNxBoxController()
{
    if (m_pActor != 0)
        return;
    NxScene* pScene = ((class CPhysXHelper*)GetPhysXHelper())->GetNxScene();
    if (pScene == 0)
        return;
    NxVec3 ptPos;
    NiPhysXTypes::NiPoint3ToNxVec3(*(class NiPoint3 const*)&static_cast<Vector3 const&>(m_vPos), ptPos);
    NxBoxShapeDesc box;
    box.dimensions.set(m_spRow->m_mesh.m_shapeDimension.x, m_spRow->m_mesh.m_shapeDimension.y, m_spRow->m_mesh.m_shapeDimension.z);
    box.dimensions = box.dimensions * 0.01f * 0.5f;
    box.groupsMask.bits0 = 0xffffffff;
    box.shapeFlags &= 0xffedffff;
    NxActorDesc actorDesc;
    actorDesc.body = NULL;
    actorDesc.shapes.pushBack(&box);
    Vector3 vPos = m_vPos;
    actorDesc.globalPose.t = NxVec3(vPos.x, vPos.y, vPos.z);
    actorDesc.globalPose.t = actorDesc.globalPose.t * 0.01f;
    actorDesc.globalPose.t.z += box.dimensions.z;
    actorDesc.globalPose.M.rotZ((m_vRot.z * 3.1415927f) / 180.0f);
    NxVec3 vSet(m_vPos.x, m_vPos.y, m_vPos.z);
    vSet = vSet * 0.01f;
    vSet.z += m_spRow->m_mesh.m_shapeDimension.z * 0.01f * 0.5f;
    ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
    m_pActor = pScene->createActor(actorDesc);
    if (m_pActor != 0)
    {
        m_pActor->setName("CInteractMeshObject::MakeNxBoxController");
        NxU32 nShapes = m_pActor->getNbShapes();
        NxShape* const* ppShapes = m_pActor->getShapes();
        for (NxU32 i = 0; i < nShapes; ++i)
        {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(0);   // exe: NxShape slot 2 [rax+0x10] with edx=0, not setFlag
        }
        m_pActor->userData = m_spProp.operator egfPhysX::EntityActorData*();
        m_pActor->setGlobalPosition(vSet);
    }
    ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
}

// @0x1413ff5f0
void CInteractMeshObject::ReleaseActor()
{
    if (m_pActor != 0)
    {
        NxScene* pScene = ((class CPhysXHelper*)GetPhysXHelper())->GetNxScene();
        if (pScene != 0)
        {
            ((class CPhysXHelper*)GetPhysXHelper())->FUN_14168a540(0);
            pScene->releaseActor(*m_pActor);
            reinterpret_cast<Unk_IoWorld*>(WorldService::GetInstance())->FUN_141bc8e00();
            ((class CPhysXHelper*)GetPhysXHelper())->Unlock();
            m_pActor = 0;
        }
    }
}

// @0x1413ff690
void CInteractMeshObject::FUN_1413ff690(const CString& strAsset)
{
    if (m_nAssetType == 1)
    {
        efd::AssetID id;
        id.SetURN((const char*)strAsset);
        SetAssetIdProperty(m_ent.operator->(), 0x770e5fc6, &id);
    }
    else if (m_nAssetType == 2)
    {
        efd::utf8string str(strAsset);
        reinterpret_cast<Unk_AnimSvc*>(FUN_141b6f910())->PlayAnimation(m_ent->GetEntityID(), str, 1.0f, false);
    }
}

// @0x1413ff800
void CInteractMeshObject::SetCollision(int nCollision)
{
    if (nCollision != 0)
        MakeNxBoxController();
    else
        ReleaseActor();
}

// @0x1413ff840
void CInteractMeshObject::PlayReactAni()
{
    if (m_spRow->m_mesh.m_strReactObjectAni.GetLength() > 0)
        FUN_1413ff690(m_spRow->m_mesh.m_strReactObjectAni);
}

// @0x1413ff8a0
void CInteractMeshObject::ApplyAssetB()
{
    FUN_1413ff690(m_strAssetB);
}

// ================================================================================================================
// CInteractTelescopeObject
// ================================================================================================================

// @0x1413ff8d0
CInteractTelescopeObject::CInteractTelescopeObject()
{
    m_bActive = 0;
}

// @0x1413ff920
CInteractTelescopeObject::~CInteractTelescopeObject()
{
    if (m_bActive != 0)
        OnCutSceneSkip(0);
}

// @0x1413ff980
void CInteractTelescopeObject::vfunc_2(Unk_InteractMsg* pMsg)
{
    CInteractObject::vfunc_2(pMsg);
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_ent.operator=(reinterpret_cast<MyPC*>(pPlayer)->FUN_141529900());
    if (m_ent.operator egf::Entity*() != 0)
    {
        m_bActive = 1;
        FUN_141276180(s_strUseTelescope, "");
        ((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->FUN_1422b9fd0(0x6200041);
        CStringW strDesc;
        UICutSceneCinematic* pHelp = ((class UICutSceneCinematic*)FindCutSceneCinematic(0x4e52));
        if (pHelp != 0)
        {
            CStringW strTitle = GetStringCommon(0x666);
            if (*reinterpret_cast<unsigned char*>(GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance()))) != 0)
                strTitle = GetKeyTable()->GetActionKeyName(0x49409, 2);
            pHelp->StartCinematic(9, strDesc);
            pHelp->FUN_141907d60(3, strTitle, GetStringCommon(0x667));
            NotifySystem::GetInstance()->RegisterNotify(CStringW(L"NotifyCutSceneCinematicSkip"),
                                           Delegate<void(NotifyObject*)>(this, &CInteractTelescopeObject::OnCutSceneSkip));
        }
        efd::Color colA(0.0f, 0.0f, 0.0f);
        efd::Color colB(0.0f, 0.0f, 0.0f);
        bool bFilter;
        bool bColor;
        float nFilterA, nFilterB, nColA, nColB, nColC;
        m_ent.operator->()->GetPropertyValue<bool>(0x4c87bc48, bFilter);
        FUN_140b27ec0((Unk_Entity*)m_ent.operator->(), 0x22a89b35, &colA);
        m_ent.operator->()->GetPropertyValue<float>(0x65832be6, nFilterA);
        m_ent.operator->()->GetPropertyValue<float>(0xf8696656, nFilterB);
        unsigned nFilterColor = ((int)(colA.m_r * 255.0f) & 0xffU) << 16 | 0xff000000 | ((int)(colA.m_g * 255.0f) & 0xffU) << 8 |
                                ((int)(colA.m_b * 255.0f) & 0xffU);
        m_ent.operator->()->GetPropertyValue<bool>(0x554eb57d, bColor);
        FUN_140b27ec0((Unk_Entity*)m_ent.operator->(), 0x85eb5e6b, &colB);
        m_ent.operator->()->GetPropertyValue<float>(0x2c1b71fe, nColA);
        m_ent.operator->()->GetPropertyValue<float>(0xc55896f7, nColB);
        m_ent.operator->()->GetPropertyValue<float>(0xc9603b18, nColC);
        unsigned nColor = ((int)(colB.m_r * 255.0f) & 0xffU) << 16 | 0xff000000 | ((int)(colB.m_g * 255.0f) & 0xffU) << 8 |
                          ((int)(colB.m_b * 255.0f) & 0xffU);
        TSingleton<ApplyEffect>::GetInstance()->SetFogRange(bFilter, nFilterA, nFilterB, nFilterColor);
        TSingleton<ApplyEffect>::GetInstance()->SetFogEffect(bColor, &nColor, nColA, nColB, nColC);
    }
}

// @0x1413fff60
void CInteractTelescopeObject::OnCutSceneSkip(NotifyObject*)
{
    ((class CTriggerService*)GetTriggerService())->FUN_141863460(0.0f);
    ((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->FUN_1422b9fd0(0x620001d);
    MS2Ptr<CFieldDataCli> ref = WorldService::GetInstance()->FUN_141bd30a0();
    if (reinterpret_cast<Unk_IoCutData*>(ref.get()) != 0)
    {
        TSingleton<ApplyEffect>::GetInstance()->SetFogRange(reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_b1fd, reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_n204, reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_n208,
                                       reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_n200);
        TSingleton<ApplyEffect>::GetInstance()->SetFogEffect(reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_b20c, &reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_n210, reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_n214,
                                       reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_n218, reinterpret_cast<Unk_IoCutData*>(ref.operator->())->m_n21c);
    }
    NotifySystem::GetInstance()->UnregisterNotify(CStringW(L"NotifyCutSceneCinematicSkip"),
                                   Delegate<void(NotifyObject*)>(this, &CInteractTelescopeObject::OnCutSceneSkip));
    m_bActive = 0;
}

// ================================================================================================================
// CInteractUIObject
// ================================================================================================================

// @0x1414001e0
CInteractUIObject::CInteractUIObject()
{
    m_nDialogId = 0;
}

// @0x141400230
CInteractUIObject::~CInteractUIObject()
{
}

// @0x141400260
void CInteractUIObject::vfunc_2(Unk_InteractMsg* pMsg)
{
    CInteractObject::vfunc_2(pMsg);
    UIDialog* pDialog = dynamic_cast<UIDialog*>(GetUISwfEntityManager()->GetUISwfEntity(m_spRow->m_ui.m_strSwf).get());
    if (pDialog != 0)
    {
        if (m_spRow->m_ui.m_strValue.GetLength() != 0)
            pDialog->FUN_1419265e0(m_spRow->m_ui.m_strValue);
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(pDialog->vfunc_48())));
        m_nDialogId = pDialog->vfunc_48();
    }
}

// @0x1414003c0
void CInteractUIObject::vfunc_11()
{
    CInteractObject::vfunc_11();
    if (m_nDialogId == 0)
        return;
    if (TSingleton<CUIService>::GetInstance()->IsDialogClosed((eUIClassID)m_nDialogId) != 0)
    {
        m_nDialogId = 0;
        return;
    }
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
    {
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)m_nDialogId);
        return;
    }
    float fRange = GetRow()->m_validate.m_fInteractionDistance;
    if ((*((Vector3*)&(const NiPoint3&)reinterpret_cast<PCBase*>(pPlayer)->FUN_1416767d0()) - GetPos()).Length() > fRange)
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)m_nDialogId);
}

// ================================================================================================================
// CInteractDisplayImage
// ================================================================================================================

// @0x141400520
CInteractDisplayImage::CInteractDisplayImage()
    : m_strUrl()
    , m_strGuildName()
    , m_strCharName()
{
    m_pThread = 0;
    m_nGuildRank = 0;
    m_nGuildTrophy = 0;
    m_nGuildScore = 0;
    m_nCharTrophy = 0;
    m_nCharBuildPoint = 0;
    m_nCharScore = 0;
}

// @0x141400600
CInteractDisplayImage::~CInteractDisplayImage()
{
}

// @0x141400670
int CInteractDisplayImage::vfunc_1(Unk_Entity* pEntity, int nState)
{
    if (CInteractObject::vfunc_1(pEntity, nState) == 0)
        return 0;
    if (((CContentShutdown*)&((struct Unk_IoCfgHolder*)FUN_14025e7b0())->m_cfg)->Get((CContentShutdown::Content)0x32) == 0 && ((class Unk_IoSession*)FUN_140166410())->IsFeatureEnabled(0x3f) == 1)
        m_pThread = AfxBeginThread(GetURLFromGameRanking, this, 0, 0, 0, 0);
    else if (((class Unk_IoSession*)FUN_140166410())->IsRegionKR())
    {
        m_strUrl = "";
        TSingleton<CWebBrowserService>::GetInstance()->ExpandUrlPrefix(m_strUrl, (const char*)m_spRow->m_displayUrl.m_strIndirectUrl);
        if (m_strUrl.GetLength() > 0)
            m_pThread = AfxBeginThread(GetURLFromIndirectURL, this, 0, 0, 0, 0);
    }
    return 1;
}

// ---- worker thread / url stand-ins ----
void FUN_141b6de20();
CStringW Unk_ArcWide(const wchar_t* sz, int n);              // 0x140efe330
// The scoped log line of util.cpp ("<tag> begin" / "<tag> end").
class Unk_UtilLogScope
{
public:
    Unk_UtilLogScope(CStringA kTag);                            // 0x141b721f0
    ~Unk_UtilLogScope();                                        // 0x141b722b0
private:
    DWORD m_dwThread;
    CStringA m_kTag;
};

// ---- ranking / xml / image stand-ins used by the display image ----
#ifndef TIXML_ENCODING_DEFINED   // also tixmldocument.h and tinyxml.h
#define TIXML_ENCODING_DEFINED
enum TiXmlEncoding { TIXML_ENCODING_UNKNOWN, TIXML_ENCODING_UTF8, TIXML_ENCODING_LEGACY };
#endif
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view







typedef TiXmlElement Unk_IoXmlElem;
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
CStringW FUN_1401bf530(class TiXmlElement* p, const char* pszName, CStringW strDefault);
int FUN_140197350(class TiXmlElement*, char const*, int);   // C3: was FUN_140197350
int XmlGetAttr(class TiXmlElement*, char const*, unsigned __int64&);   // C3: was FUN_140873320
// @0x1414038e0
static unsigned __int64 FUN_1414038e0(Unk_IoXmlElem* p, const char* pszName, unsigned __int64 nDefault)
{
    unsigned __int64 nValue;
    if (XmlGetAttr(p, pszName, *(unsigned __int64*)(&nValue)) != 0)
        return nDefault;
    return nValue;
}
CString FUN_140390ea0(const wchar_t* psz, int nCodePage);
CStringW FUN_14016a730(const char* psz, int nCodePage);
CString FUN_14016a600(const wchar_t* psz, int nCodePage);
CString FUN_141029590(unsigned __int64 nId, const CString& strKey, const CString& strName, CString strExtra);
CString FUN_141028be0(__int64 nId, const CString& strPortrait, int nFlag, CString strExtra);
CString FUN_1410299f0(unsigned __int64 nA, const CString& strB, int nId, const CString& strName, bool bFlag);
class Unk_IoPosterSvc {};
struct Unk_IoPosterHolder { char m_pad_00[8]; Unk_IoPosterSvc m_svc; };

NiTexturePtr LoadUgcTexture(const CStringW& strPath, int nSize, bool bPng);   // LoadUgcTexture
class Unk_IoTexMgr : public CUgcManager
{
public:
};
class Unk_MeratBlindManager* GetBlindManager();   // C3: was GetBlindManager

// ranking

// @0x141400800
void CInteractDisplayImage::FUN_141400800(const CStringW& strName)
{
    MS2Ptr<CInteractObjectData> spRow = GetRow();
    if (spRow == 0)
        return;
    CString strKey = FUN_140390ea0(strName, 0);
    if (spRow->m_displayUrl.m_nType == 1 || m_spRow->m_displayUrl.m_nType == 3)
    {
        Unk_IoXmlElem elem("guild");
        const char* pEnd = elem.Parse(strKey, 0, TIXML_ENCODING_UTF8);
        if (pEnd == 0)
            return;
        CString strMark = Unk_ReadString((class Unk_XmlNode*)(&elem), "mark", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strGuildName = FUN_1401bf530((TiXmlElement*)&elem, "name", CStringW(L""));
        m_nGuildRank = FUN_140197350((class TiXmlElement*)(&elem), "rank", 0);
        m_nGuildTrophy = FUN_140197350((class TiXmlElement*)(&elem), "trophy", 0);
        m_nGuildScore = FUN_140197350((class TiXmlElement*)(&elem), "score", 0);
        if (strMark.GetLength() < 1 || nSn < 1)
            return;
        CString strPath = FUN_141029590(nSn, strMark, GetName(), CString(""));
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
    else if (spRow->m_displayUrl.m_nType == 2)
    {
        Unk_IoXmlElem elem("character");
        const char* pEnd = elem.Parse(strKey, 0, TIXML_ENCODING_UTF8);
        if (pEnd == 0)
            return;
        CString strPortrait = Unk_ReadString((class Unk_XmlNode*)(&elem), "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530((TiXmlElement*)&elem, "name", CStringW(L""));
        m_nCharTrophy = FUN_140197350((class TiXmlElement*)(&elem), "trophy", 0);
        m_nCharRank = FUN_140197350((class TiXmlElement*)(&elem), "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
    else if (spRow->m_displayUrl.m_nType == 4)
    {
        Unk_IoXmlElem elem("character");
        const char* pEnd = elem.Parse(strKey, 0, TIXML_ENCODING_UTF8);
        if (pEnd == 0)
            return;
        CString strPortrait = Unk_ReadString((class Unk_XmlNode*)(&elem), "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530((TiXmlElement*)&elem, "name", CStringW(L""));
        m_nCharBuildPoint = FUN_140197350((class TiXmlElement*)(&elem), "build_point", 0);
        m_nCharRank = FUN_140197350((class TiXmlElement*)(&elem), "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
    else if (spRow->m_displayUrl.m_nType == 5)
    {
        Unk_IoXmlElem elem("character");
        const char* pEnd = elem.Parse(strKey, 0, TIXML_ENCODING_UTF8);
        if (pEnd == 0)
            return;
        CString strPortrait = Unk_ReadString((class Unk_XmlNode*)(&elem), "portrait", CString(""));
        unsigned __int64 nSn = FUN_1414038e0(&elem, "sn", 0);
        m_strCharName = FUN_1401bf530((TiXmlElement*)&elem, "name", CStringW(L""));
        m_nCharScore = FUN_140197350((class TiXmlElement*)(&elem), "score", 0);
        m_nCharRank = FUN_140197350((class TiXmlElement*)(&elem), "rank", 0);
        CString strPath = FUN_141028be0(nSn, strPortrait, 1, GetName());
        if (strPath.GetLength() > 0)
            FUN_1414017b0(strPath);
    }
}

// @0x141401380
void CInteractDisplayImage::ApplyRankEntry(TPtrValue<CGameRankingData> spRank)
{
    MS2Ptr<CInteractObjectData> spRow = GetRow();
    if (spRow == 0)
        return;
    if (spRank == 0)
        return;
    CString strKey = FUN_14016a600(reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_str78, 0);
    unsigned __int64 nGuildSn = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_u20;
    unsigned __int64 nCharSn = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_u30;
    m_strGuildName = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_str48;
    m_nGuildRank = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_nRank;
    m_nGuildTrophy = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_nScore;
    m_nGuildScore = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_nScore;
    m_strCharName = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_str38;
    m_nCharTrophy = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_nScore;
    m_nCharRank = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_nRank;
    m_nCharBuildPoint = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_nScore;
    m_nCharScore = reinterpret_cast<Unk_IoRanking*>(spRank.operator->())->m_nScore;
    CString strPath("");
    switch (spRow->m_displayUrl.m_nType)
    {
    case 1:
    case 3:
        strPath = FUN_141029590(nGuildSn, strKey, GetName(), CString(""));
        break;
    case 2:
    case 4:
    case 5:
        strPath = FUN_141028be0(nCharSn, strKey, 1, GetName());
        break;
    }
    if (strPath.GetLength() > 0)
        FUN_1414017b0(strPath);
}

// @0x1414017b0
void CInteractDisplayImage::FUN_1414017b0(const CString& strFile)
{
    CStringW strPath = FUN_14016a730(strFile, 0);
    if (m_ent.operator egf::Entity*() == 0)
        return;
    NiTexturePtr spTexA(0);
    if (_waccess(strPath, 0) == 0)
    {
        NiTexturePtr spTex = LoadUgcTexture(strPath, 0x100, false);
        if (spTex == 0)
            return;
        TSingleton<CUgcManager>::GetInstance()->FUN_141888770(m_ent, spTex);
    }
}

// @0x141401920
UINT CInteractDisplayImage::GetURLFromIndirectURL(LPVOID pParam)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString("CInteractDisplayImage::GetURLFromIndirectURL"));
    CInteractDisplayImage* pThis = static_cast<CInteractDisplayImage*>(pParam);
    if (pThis == 0)
        return 0;
    CString strName = pThis->GetName();
    std::wstring strUrl(CStringW(FUN_14016a730(pThis->m_strUrl, 0)));
    CWinHttpClient client(strUrl);
    if (client.SendRequest(L"GET", false))
    {
        if (client.FUN_140922f20() != 0)
            return 0;
        std::wstring strBody = client.GetResponseContent();
        CStringW strResult = Unk_ArcWide(strBody.c_str(), 0);
        if (reinterpret_cast<Unk_IoWorld*>(WorldService::GetInstance()) != 0)
            reinterpret_cast<Unk_IoWorld*>(WorldService::GetInstance())->FUN_141bdb030(CString(strName), CStringW(strResult));
    }
    return 0;
}

// @0x141401c20
UINT CInteractDisplayImage::GetURLFromGameRanking(LPVOID pParam)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString("CInteractDisplayImage::GetURLFromGameRanking"));
    CInteractDisplayImage* pThis = static_cast<CInteractDisplayImage*>(pParam);
    if (pThis == 0)
        return 0;
    CString strName = pThis->GetName();
    int nImageType = pThis->m_spRow->m_displayUrl.m_nType;
    int nRankType = 0;
    CString strUrl(pThis->m_spRow->m_displayUrl.m_strIndirectUrl);
    CString strTag("rank=");
    int nPos = strUrl.Find(strTag, 0);
    int nRank = pThis->m_spRow->m_displayUrl.m_strIndirectUrl.GetAt(nPos + strTag.GetLength()) - '0';
    switch (nImageType)
    {
    case 1:
        nRankType = 1;
        break;
    case 2:
        nRankType = 2;
        break;
    case 3:
        nRankType = 5;
        break;
    case 4:
        nRankType = 6;
        break;
    case 5:
        nRankType = 4;
        break;
    }
    CGameRankingParam::Key key;
    TSingleton<CGameRankingCli>::GetInstance()->BuildKey(key, nRankType, 0, 0, 0);
    TPtrValue<CGameRankingData> spRank = TSingleton<CGameRankingCli>::GetInstance()->GetData(key, nRank, 1);
    if (spRank == 0)
    {
        CGameRankingParam param;
        param.m_key = key;
        TSingleton<CGameRankingCli>::GetInstance()->Request(&param);
        int nTry = 0;
        while (nTry++ < 5)
        {
            Sleep(1000);
            spRank = static_cast<const TPtrValue<CGameRankingData>&>(TSingleton<CGameRankingCli>::GetInstance()->GetData(key, nRank, 0));
            if (spRank.get() != 0)
                break;
        }
    }
    if (spRank.get() != 0 && reinterpret_cast<Unk_IoWorld*>(WorldService::GetInstance()) != 0)
        FUN_141bdb0f0(WorldService::GetInstance(), CString(strName), static_cast<const TPtrValue<CGameRankingData>&>(spRank));
    return 0;
}

// @0x141402060
CStringW CInteractDisplayImage::GetDisplayName()
{
    if (m_spRow == 0)
        return CStringW();
    if (m_spRow->m_displayUrl.m_nType == 1 || m_spRow->m_displayUrl.m_nType == 3)
        return m_strGuildName;
    else if (m_spRow->m_displayUrl.m_nType == 2 || m_spRow->m_displayUrl.m_nType == 4 || m_spRow->m_displayUrl.m_nType == 5)
        return m_strCharName;
    return CStringW();
}

// @0x1414021c0
int CInteractDisplayImage::GetRank()
{
    if (m_spRow == 0)
        return 0;
    if (m_spRow->m_displayUrl.m_nType == 1 || m_spRow->m_displayUrl.m_nType == 3)
        return m_nGuildRank;
    else if (m_spRow->m_displayUrl.m_nType == 2 || m_spRow->m_displayUrl.m_nType == 4 || m_spRow->m_displayUrl.m_nType == 5)
        return m_nCharRank;
    return 0;
}

// @0x1414022a0
int CInteractDisplayImage::GetDisplayScore()
{
    if (m_spRow == 0)
        return 0;
    if (m_spRow->m_displayUrl.m_nType == 1)
        return m_nGuildTrophy;
    else if (m_spRow->m_displayUrl.m_nType == 2)
        return m_nCharTrophy;
    else if (m_spRow->m_displayUrl.m_nType == 3)
        return m_nGuildScore;
    else if (m_spRow->m_displayUrl.m_nType == 4)
        return m_nCharBuildPoint;
    else if (m_spRow->m_displayUrl.m_nType == 5)
        return m_nCharScore;
    return 0;
}

// ================================================================================================================
// CInteractGatheringObject
// ================================================================================================================

// @0x1414023b0
CInteractGatheringObject::CInteractGatheringObject()
{
    m_nRespawnTick = 0;
}

// @0x141402400
CInteractGatheringObject::~CInteractGatheringObject()
{
}

// @0x141402430
int CInteractGatheringObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    CInteractMeshObject::vfunc_1(pEntity, nState);
    void* pTable = Unk_FcDialog<UIMasteryObjectMark>(0x4f3a);
    if (pTable != 0)
        ((class UIMasteryObjectMark*)(void*)(pTable))->AddNodeMark(this);
    return 1;
}

// @0x141402490
void CInteractGatheringObject::vfunc_2(Unk_InteractMsg* pMsg)
{
    CInteractMeshObject::vfunc_2(pMsg);
    int sType = (&pMsg->m_stream)->ReadShort();
    int nCount = (&pMsg->m_stream)->ReadInt();
    vfunc_3(0);
    m_nRespawnTick = GetTickCountMs2() + m_spRow->m_nResetTime;
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        MS2Ptr<StateInteractData> spData(new StateInteractData);
        spData->m_nObjectId = GetRowId();
        spData->m_strObjectId = GetName();
        spData->m_nFlag = 1;
        int nMsg;
        if (sType == 0)
            nMsg = 0x8b;
        else
            nMsg = 0x8c;
        pPlayer->SendState(0x19, (StateInteractData*)spData, nMsg, 0);
    }
    int nGatherId = m_spRow->m_gathering.m_nReceipeId;
    if (nGatherId != 0 && sType == 0)
    {
        int nHave = 0;
        reinterpret_cast<ATL::CAtlMap<unsigned long, int>&>(g_143ab3150).Lookup(nGatherId, nHave);
        reinterpret_cast<ATL::CAtlMap<unsigned long, int>&>(g_143ab3150).SetAt(nGatherId, nHave + nCount);
    }
}

// @0x141402750
void CInteractGatheringObject::vfunc_11()
{
    CInteractObject::vfunc_11();
    if (m_nRespawnTick != 0)
    {
        if ((unsigned)m_nRespawnTick <= GetTickCountMs2())
        {
            vfunc_3(1);
            m_nRespawnTick = 0;
        }
    }
}

// @0x1414027c0
void CInteractGatheringObject::vfunc_6(Unk_InteractCursor* pOut)
{
    CInteractObject::vfunc_6(pOut);
    pOut->m_nCursor = ((CGameEventValueMasteryReduce*)TSingleton<CGameEventValueManager>::GetInstance()->MasteryReduce())->Apply(pOut->m_nCursor);
    pOut->m_strHint = GetStringCommonByKey(L"s_action_gathering");
    pOut->m_strHint += ((CGameEventValueMasteryReduce*)TSingleton<CGameEventValueManager>::GetInstance()->MasteryReduce())->GetText();
}

// @0x1414028c0
CString CInteractGatheringObject::vfunc_13()
{
    if (FUN_141402c90() == 0)
        return CString("");
    return CInteractObject::vfunc_13();
}

// @0x141402940
int CInteractGatheringObject::vfunc_7()
{
    if (CInteractObject::vfunc_7() == 0)
        return 0;
    if (vfunc_15() != 0)
        return 0;
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spRow->m_gathering.m_nReceipeId != 0)
    {
        CMasteryTable::ReceipePtr spReceipe = CMasteryTable::GetInstance()->Find(m_spRow->m_gathering.m_nReceipeId);
        if (!spReceipe)
            return 0;
        if (reinterpret_cast<PC*>(pPlayer)->GetMastery(spReceipe->m_nType) < spReceipe->m_nRequireMastery)
            return 0;
        if (reinterpret_cast<Unk_IoGatherChk*>(TSingleton<CMasteryManager>::GetInstance())->FUN_140b6d330(m_spRow->m_gathering.m_nReceipeId) == 0)
            return 0;
    }
    return 1;
}

// @0x141402ad0
int CInteractGatheringObject::vfunc_16()
{
    if (FUN_141402c90() == 0)
        return 0;
    if (CMasteryTable::GetInstance()->LimitState(m_spRow->m_gathering.m_nReceipeId) == 3)
        return 0;
    return 1;
}

// @0x141402b40
int CInteractGatheringObject::FUN_141402b40()
{
    if (vfunc_15() != 0)
        return 0;
    if (m_spRow->m_gathering.m_nReceipeId != 0)
    {
        CMasteryTable::ReceipePtr spReceipe = CMasteryTable::GetInstance()->Find(m_spRow->m_gathering.m_nReceipeId);
        if (!spReceipe)
            return 0;
        if (reinterpret_cast<Unk_IoGatherChk*>(TSingleton<CMasteryManager>::GetInstance())->FUN_140b6d330(m_spRow->m_gathering.m_nReceipeId) == 0)
            return 0;
    }
    return 1;
}

// @0x141402c50
int CInteractGatheringObject::GetRespawnRemainingTime()
{
    if (m_nRespawnTick != 0)
        return m_nRespawnTick - GetTickCountMs2();
    return 0;
}

// @0x141402c90
int CInteractGatheringObject::FUN_141402c90()
{
    return reinterpret_cast<Unk_IoGatherChk*>(TSingleton<CMasteryManager>::GetInstance())->FUN_140b6d470(m_spRow->m_gathering.m_nReceipeId) == 0;
}

// ================================================================================================================
// CInteractGuildPosterObject
// ================================================================================================================

// @0x141402cf0
CInteractGuildPosterObject::CInteractGuildPosterObject()
{
}

// @0x141402d30
CInteractGuildPosterObject::~CInteractGuildPosterObject()
{
}

// @0x141402d60
int CInteractGuildPosterObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    if (CInteractObject::vfunc_1(pEntity, nState) == 0)
        return 0;
    if (((class Unk_IoSession*)FUN_140166410())->IsFeatureEnabled(0x5b) == 0)
        return 0;
    UpdatePoster(1);
    return 1;
}

// @0x141402dd0
void CInteractGuildPosterObject::vfunc_10()
{
    if (vfunc_4() == 0)
        return;
    ((class Unk_IoTexMgr*)TSingleton<CUgcManager>::GetInstance())->OpenGuildPosterUpload(GetName(), GetHousePosterId());
}

// @0x141402e60
int CInteractGuildPosterObject::GetHousePosterId()
{
    if (m_spRow == 0)
        return 0;
    return m_spRow->m_guild.m_nHousePosterId;
}

// @0x141402eb0
void CInteractGuildPosterObject::UpdatePoster(unsigned char bShow)
{
    if (m_ent.operator egf::Entity*() == 0)
        return;
    int nPoster = GetHousePosterId();
    unsigned __int64 nSvc = reinterpret_cast<CGuildInfo*>(&reinterpret_cast<Unk_IoPosterHolder*>(TSingleton<CGuildManager>::GetInstance())->m_svc)->GetGuildId();
    CStringW strRaw = reinterpret_cast<CGuildInfo*>(&reinterpret_cast<Unk_IoPosterHolder*>(TSingleton<CGuildManager>::GetInstance())->m_svc)->FUN_1404d2220(nPoster);
    CStringW strFile = FUN_14016a730(FUN_1410299f0(nSvc, FUN_14016a600(strRaw, 0), nPoster, GetName(), reinterpret_cast<bool&>(bShow)), 0);
    if (((class BlindManager*)GetBlindManager())->IsBlocked(5, CStringW(strRaw)) == 1)
    {
        NiTexturePtr spTex = ((class Unk_IoTexMgr*)TSingleton<CUgcManager>::GetInstance())->GetDefaultTexture();
        if (spTex)
            TSingleton<CUgcManager>::GetInstance()->FUN_141888770(m_ent, spTex);
    }
    else
    {
        FUN_141403180(CStringW(strFile));
    }
}

// @0x141403180
void CInteractGuildPosterObject::FUN_141403180(CStringW strFile)
{
    if (m_ent.operator egf::Entity*() == 0)
        return;
    if (strFile.GetLength() < 1)
        return;
    NiTexturePtr spTexA(0);
    if (_waccess(strFile, 0) == 0)
    {
        NiTexturePtr spTex = LoadUgcTexture(strFile, 0x100, false);
        if (spTex == 0)
            return;
        TSingleton<CUgcManager>::GetInstance()->FUN_141888770(m_ent, spTex);
    }
}

// ================================================================================================================
// CInteractBillBoardObject
// ================================================================================================================

// @0x1414032e0
CInteractBillBoardObject::CInteractBillBoardObject()
    : m_strText()
{
    m_nBoard = 0;
}

// @0x141403340
CInteractBillBoardObject::~CInteractBillBoardObject()
{
}

// @0x141403390
int CInteractBillBoardObject::vfunc_4()
{
    if (CInteractMeshObject::vfunc_4() == 0)
        return 0;
    Unk_IoBoardSvc* pBoard = (Unk_IoBoardSvc*)GetItemUseDialog<UIItemBillBoardDialog>(0x4f4f);
    if (pBoard != 0)
    {
        __int64 nCur = ((class UIItemBillBoardDialog*)(class Unk_IoBoardSvc*)(pBoard))->GetBillboardOwner();
        if (nCur != 0 && nCur == m_nBoard)
            return 0;
    }
    return 1;
}

// ================================================================================================================
// CInteractWatchTowerObject
// ================================================================================================================

// @0x141403400
CInteractWatchTowerObject::CInteractWatchTowerObject()
{
    m_bNear = 0;
}

// @0x141403440
CInteractWatchTowerObject::~CInteractWatchTowerObject()
{
}

// @0x141403470
int CInteractWatchTowerObject::vfunc_1(Unk_Entity* pEntity, int nState)
{
    CInteractMeshObject::vfunc_1(pEntity, nState);
    m_bNear = 0;
    DisableDynamicUpdate(0);
    return 1;
}

// @0x1414034c0
int CInteractWatchTowerObject::vfunc_7()
{
    return 0;
}

// @0x1414034d0
int CInteractWatchTowerObject::vfunc_4()
{
    return 0;
}

// @0x1414034e0
void CInteractWatchTowerObject::vfunc_3(int nState)
{
    if (m_ent.operator==((egf::Entity*)0))
        return;
    if (m_spRow == 0)
        return;
    m_nState = nState;
    if (m_bNear != 0)
    {
        int bFirst = m_nState == 0;
        FUN_1413ff690(bFirst ? m_strAssetA : m_strAssetB);
        ShowStateEffect();
    }
}

// NiPoint3 taken by value: efd::Point3 results convert through the out-of-line NiPoint3(const efd::Point3&) and are copied into the argument.
// @0x141403f20
float GetDistance2D(NiPoint3 a, NiPoint3 b)
{
    a.z = 0.0f;
    b.z = 0.0f;
    return (reinterpret_cast<Vector3&>(a) - reinterpret_cast<Vector3&>(b)).Length();
}

// @0x1414035d0
void CInteractWatchTowerObject::vfunc_11()
{
    CInteractObject::vfunc_11();
    unsigned char bNear = 0;
    Unk_IoPlayer* pPlayer = (Unk_IoPlayer*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        float fDist = GetDistance2D(*(const efd::Point3*)&static_cast<const Vector3&>(pPlayer->GetPosition()), *(const efd::Point3*)&static_cast<const Vector3&>(GetPos()));
        if (fDist < 2000.0f)
            bNear = 1;
    }
    if (m_bNear == bNear)
        return;
    m_bNear = bNear;
    if (m_bNear != 0)
    {
        EnableHighlight();
        ShowStateEffect();
        int bFirst = m_nState == 0;
        const CString* pAsset = bFirst != 0 ? &m_strAssetA : &m_strAssetB;
        FUN_1413ff690(*pAsset);
    }
    else
    {
        DisableDynamicUpdate(0);
        ClearStateEffect();
    }
}

// ================================================================================================================
// trivial virtuals
// ================================================================================================================

// @0x141403f10
int CInteractObject::vfunc_16() { return 0; }
// @0x141403f70
int CInteractGatheringObject::vfunc_15() { return m_nRespawnTick; }
// @0x141403f90
int CInteractObject::vfunc_15() { return 0; }
// @0x141403fa0
int CInteractBillBoardObject::vfunc_5() { return 8; }
// @0x141403fb0
int CInteractDisplayImage::vfunc_5() { return 5; }
// @0x141403fc0
int CInteractGatheringObject::vfunc_5() { return 6; }
// @0x141403fd0
int CInteractGuildPosterObject::vfunc_5() { return 7; }
// @0x141403fe0
int CInteractMeshObject::vfunc_5() { return 1; }
// @0x141403ff0
int CInteractObject::vfunc_5() { return 1; }
// @0x141404000
int CInteractTelescopeObject::vfunc_5() { return 2; }
// @0x141404010
int CInteractUIObject::vfunc_5() { return 3; }
// @0x141404020
int CInteractWatchTowerObject::vfunc_5() { return 9; }
// @0x141404060
void CInteractMeshObject::vfunc_2(Unk_InteractMsg*) {}
// @0x141404070
int CInteractObject::vfunc_7() { return m_nState == 1; }
// @0x1414040a0
void CInteractGatheringObject::vfunc_14(int n) { m_nRespawnTick = n; }
// @0x1414040c0
void CInteractObject::vfunc_14(int) {}

// Trailing unreferenced CRT memmove_s COMDAT 0x1414042c0.
MS2_EMIT_CRT_MEMMOVE_S();
