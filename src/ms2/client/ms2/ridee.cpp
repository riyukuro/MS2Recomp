// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ridee.h.
// MS2-UNIT: client\ms2\ridee.cpp
// MS2-RANGE: 0x141703a70-0x141709320 .text$mn
// MS2-RANGE: 0x1400ff360-0x1400ff540 .text$di
// MS2-RANGE: 0x142cb5e00-0x142cb5eb0 .text$yd
// MS2-PIN: ?GetClassDesc@Ridee@@UEBAPEBVClassInfo@efd@@XZ 0x141708af0
// MS2-PIN: ?TypeCast@Ridee@@UEBA_NIPEAPEAX@Z 0x141709280
// MS2-PIN: ?TypeCast@Ridee@@UEBA_NIPEAPEBX@Z 0x1417092d0
// MS2-PIN: ??_7Ridee@@6BIBase@efd@@@ 0x142f5b738
// MS2-PIN: ??_7Ridee@@6BCallbackObject@NiActorManager@@@ 0x142f5bb20
// MS2-PIN: ??_7StateRideeController@@6B@ 0x142f5b728
// MS2-PIN: ??0Ridee@@QEAA@XZ 0x141703a70
// MS2-PIN: ??1StateRideeController@@QEAA@XZ 0x1417089c0
// MS2-PIN: ?FUN_141708b10@PCBase@@QEAAAEAV?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$SmartPointer@VNiAVObject@@@efd@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$SmartPointer@VNiAVObject@@@efd@@@2@@ATL@@XZ 0x141708b10
// MS2-PIN: ??__Es_kNoEntity@@YAXXZ 0x1400ff4a0
// MS2-PIN: ?GetCount@?$CAtlArray@V?$SmartPointer@VCEffect@@@efd@@V?$CElementTraits@V?$SmartPointer@VCEffect@@@efd@@@ATL@@@ATL@@QEBA_KXZ 0x141708b00
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ridee.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/timeutil.h"
#include "ridee.h"
#include "ms2/client/ms2/effectdummy.h"   // C3: std::vector<CEffectDummy> (the part list)
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <io.h>
#include <NxPhysics.h>
#include <NiTransformData.h>
#include <NiTransformInterpolator.h>
#include <NiTransformController.h>
#include <egf/Entity.h>
#include <efd/ParseHelper.h>   // C3: ParseHelper<ID128>::ToString
#include <egf/FlatModel.h>
#include <ecr/SceneGraphService.h>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/client/ms2/stateemotionidle.h"         // StateTriggerEmotion, StateTriggerFollowNpc
#include "ms2/client/ms2/gameobjectcontrollerhitreport.h"
#include "ms2/client/ms2/rideeinterpolator.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/placeholder/cgraphicoptiontable.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/cbreakableobject.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC (efd::DynamicCast<PC, PCBase>)

// ---- unit-local placeholders ----

// The actor states a Ridee registers (state.cpp family; only their constructors are called here).
class StateIdle : public State
{
public:
    StateIdle(PCBase* pOwner);                                      // 0x1417cd420
    virtual int vfunc_1();
private:
    char m_pad_40[0xb8 - 0x40];
};
class StateWalk : public State
{
public:
    StateWalk(PCBase* pOwner);                                      // 0x1417ff730
    virtual int vfunc_1();
private:
    char m_pad_40[0x58 - 0x40];
};
class StateLand : public State
{
public:
    StateLand(PCBase* pOwner);                                      // 0x1417d9c70
    virtual int vfunc_1();
private:
    char m_pad_40[0x50 - 0x40];
};
class StateFall : public State
{
public:
    StateFall(PCBase* pOwner);                                      // 0x1417c6e40
    virtual int vfunc_1();
private:
    char m_pad_40[0x60 - 0x40];
};
class StateJump : public State
{
public:
    StateJump(PCBase* pOwner);                                      // 0x1417d5160
    virtual int vfunc_1();
private:
    char m_pad_40[0xa0 - 0x40];
};
class StateSkill : public State
{
public:
    StateSkill(PCBase* pOwner);                                     // 0x1417e4f70
    virtual int vfunc_1();
private:
    char m_pad_40[0x168 - 0x40];
};
class StateSwim : public State
{
public:
    StateSwim(PCBase* pOwner);                                      // 0x1417fa370
    virtual int vfunc_1();
private:
    char m_pad_40[0x48 - 0x40];
};
class StateTalk : public State
{
public:
    StateTalk(PCBase* pOwner);                                      // 0x1417fc010
    virtual int vfunc_1();
private:
    char m_pad_40[0x48 - 0x40];
};

// MS2Ptr members instantiated by other objs.
template <> MS2Ptr<Unk_PCBaseComp_b18>::MS2Ptr(int nNull);                              // 0x141532470
template <> MS2Ptr<Unk_PCBaseComp_b18>::MS2Ptr(const MS2Ptr& o);                         // 0x141532430
template <> MS2Ptr<Unk_PCBaseComp_b18>::~MS2Ptr();                                      // 0x140964b60
template <> Unk_PCBaseComp_b18* MS2Ptr<Unk_PCBaseComp_b18>::operator->() const;         // 0x141533240
template <> MS2Ptr<Unk_PCBaseComp_a58>::MS2Ptr(int nNull);                              // 0x14108af40
template <> MS2Ptr<Unk_PCBaseComp_a58>::MS2Ptr(const MS2Ptr& o);                         // 0x141099dc0
template <> MS2Ptr<Unk_PCBaseComp_a58>::~MS2Ptr();                                      // 0x141099f30
template <> MS2Ptr<Unk_PCBaseComp_a58>& MS2Ptr<Unk_PCBaseComp_a58>::operator=(const MS2Ptr& o);   // 0x14109a150
template <> bool MS2Ptr<Unk_PCBaseComp_a58>::operator==(Unk_PCBaseComp_a58* p) const;   // 0x14109a2e0
template <> MS2Ptr<Unk_StateArg22>::MS2Ptr(const MS2Ptr& o);                             // 0x140b8b8e0
template <> MS2Ptr<Unk_StateArg22>::~MS2Ptr();                                          // 0x140837140
template <> Unk_StateArg22* MS2Ptr<Unk_StateArg22>::operator->() const;                 // 0x140ac5b40
template <> Unk_StateArg22* MS2Ptr<Unk_StateArg22>::get() const;                        // 0x1410a7160
template <> bool MS2Ptr<Unk_StateArg22>::operator==(Unk_StateArg22* p) const;           // 0x140b8bbf0
template <> MS2Ptr<CStateManager>& MS2Ptr<CStateManager>::AssignRaw(CStateManager* p);  // 0x140a4fd30
template <> CStateManager* MS2Ptr<CStateManager>::operator->() const;                   // 0x140a4ff20
template <> CStateManager* MS2Ptr<CStateManager>::get() const;                          // 0x140b122c0
template <> MS2Ptr<CSkillRecord>::MS2Ptr(const MS2Ptr& o);                               // 0x1409f71b0
template <> MS2Ptr<CSkillRecord>::~MS2Ptr();                                            // 0x140975740

// @0x1417089e0 (COMDAT first instantiated here; inline so ugcmanager_4.cpp's own COMDAT copy does not collide)
template <> inline bool MS2Ptr<Unk_PCBaseComp_b18>::operator==(Unk_PCBaseComp_b18* p) const
{
    return m_p == p;
}

// The ugc ridee item (+0x80: the ugc texture url).
class Unk_PCBaseComp_b18
{
public:
    char m_pad_00[0x80];
    CString m_strUrl;                                               // +0x80
};
class RideeItemInfo   // C3: member view for the former free stand-ins
{
public:
    int IsValid() const;
};

CString FUN_1410280d0(int nKind, CString strUrl);                   // local path of a ugc file

// An object of the field (prop or actor) found by entity or name.
class Unk_RideeFieldObj
{
public:
};
template <> MS2Ptr<Unk_RideeFieldObj>::~MS2Ptr();                                       // 0x140d28f40
template <> Unk_RideeFieldObj* MS2Ptr<Unk_RideeFieldObj>::get() const;                  // 0x140d290a0
template <> Unk_RideeFieldObj* MS2Ptr<Unk_RideeFieldObj>::operator->() const;           // 0x1409f7920

class CFieldDataCli
{
public:
    char m_pad_00[0xa4];
    int m_nA4;                                                      // +0xa4 run needs stamina
};
template <> MS2Ptr<CFieldDataCli>::~MS2Ptr();                                           // 0x1408850f0
template <> CFieldDataCli* MS2Ptr<CFieldDataCli>::operator->() const;                   // 0x140885340

// The field service (FUN_1403ed2d0).
class Unk_RideeWorld : public WorldService
{
public:
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4f10(Unk_Entity* pEntity);
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4e70(CString strName);
};

// The effect manager (FUN_1403ed280).
class CEffectService   // C3: member view (real class not in this TU)
{
public:
    unsigned int FUN_1411a49c0(Unk_EffectTarget&);
    unsigned int FUN_1411a4a00(Unk_EffectTarget&);
    void FUN_1411a6060(unsigned int);
    void GetGroupEffects(unsigned nId, ATL::CAtlArray<efd::SmartPointer<CEffect> >& aOut);
};
class Unk_RideeEffects
{
public:
};

class Unk_AvModeSvc   // C3: member view (real class not in this TU)
{
public:
    int FUN_1409f7ea0();
};
class Unk_RideeGameMode
{
public:
};
class Unk_AvModeSvc* FUN_1409f7c90();   // C3: was FUN_1409f7c90

class Unk_RideeEntity;
class Unk_RideePhysX : public CPhysXHelper
{
public:
    int FUN_14168a9b0(Unk_RideeEntity* pEntity, NiPoint3 kPos);
};
Unk_RideePhysX* FUN_1409f7ca0();

// The server clock.
class Unk_RideeClock : public CMainSystem
{
public:
};
int FUN_141472bc0();

class Unk_RideeCamera : public CameraMgr
{
public:
};

class Unk_RideeOption
{
public:
    char m_pad_00[0xc];
    bool m_bShowHpBar;                                              // +0xc
};
class Unk_RideeOptions
{
public:
    Unk_RideeOption* FUN_140b123b0();
};

class Unk_RideeSpawnMgr
{
public:
};
Unk_RideeSpawnMgr* FUN_140a50010();
class CEmotionTable;
class CEmotionManager   // C3: member view (real class not in this TU)
{
public:
    CEmotionTable* GetNpcTable();
};

// The actor's ground shadow (unit_14160fb10).
class CObjectShadow : public NiRefObject
{
public:
    CObjectShadow(void* pOwner, int a, int b, float fSize, float fAlpha);   // 0x14160fc90
    bool FUN_141534300();                                           // visible
private:
    char m_pad[0x58 - sizeof(NiRefObject)];
};

// The rider's buffs (PCBase::FUN_1416749a0).
class Unk_PCBaseBuffs : public AdditionalCliList
{
};

// The player character behind a rider (a PCBase).
class Unk_RideePC : public PCBase
{
};
class Unk_RideeStats;
class CEquipment   // C3: member view (real class not in this TU)
{
public:
    float GetAbilityRate(SAType eType);
};
float FUN_1411f0e30(float fBase, float fRate);
bool FUN_14028d470(float a, float b);

// The physics body of an actor and its controller hit report.
class Unk_RideeBody;
class GameObjectController   // C3: member view for the former free stand-ins
{
public:
    void FUN_14123fbf0(unsigned short);
    void FUN_14123fd30(unsigned int);
    class GameObjectControllerHitReport* FUN_141240f20();
};

// An egf entity (property access).
class Unk_RideeEntity
{
public:
    
};
class Unk_RideeEntityMgr
{
public:
};

// The application service (class id 0x06100017) found through the framework cell (buddy.cpp keeps the same view).
class Cube;
class CubeMapInformationService { public: Cube* GetCubeAtPoint(Vector3 pt); };   // C3: member view
class Unk_Service6100017 : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(Unk_EntityAppFramework*)&egf::g_bapiContext)          // C3: was extern Unk_EntityAppFramework DAT_143b059e8
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* pFramework);
ecr::SceneGraphService* FUN_1410a68f0(Unk_EntityAppFramework* pFramework);

extern int DAT_143ae2b30;                                           // no rendering (server/tool build)
#define g_kCubeGuideZero (*(const NiPoint3*)&efd::Point3::ZERO) // C3: 0x143b01a60, was extern const NiPoint3 g_kCubeGuideZero

int FUN_1408a13d0(NiPoint3 kPos);
void FUN_140b86230(const efd::Point3& kDegrees, NiMatrix3& out);  // euler angles (degrees) to a rotation
void FUN_140a0b1f0(const NiMatrix3& kRotate, efd::Point3& out); // rotation to euler angles (degrees)
void FUN_1401d3700(CString& str);
CString FUN_140188f50(const char* psz, int n);
void FUN_14098c6e0(void* pEntity, unsigned int uiPropId, const bool& b);
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                          // the scene root of an entity
NiAVObject* FUN_141b6ef70(egf::EntityID kId);
MS2Ptr<Unk_StateArg22> FUN_140835450(int nState);                   // new state record
MS2Ptr<Unk_PCBaseComp_a58> FUN_141992920(int nObjectId);           // hp bar
void FUN_141275260(int nSound, int a, int b);
int FUN_141276180(const CString& strKey, const CString& strArg);  // system notice

// PCBase's node map and its m_unk_6d8 buff tracker.
void FUN_141682f60(void* pTracker, PCBase* pOwner);
class Unk_PCMove   // C3: member view for the former free stand-ins
{
public:
    bool FUN_141682fe0(int);
public:
    void FUN_141683a90();   // C3: was free FUN_141683a90
};

EE_IMPLEMENT_CONCRETE_CLASS_INFO(Ridee);

// ---- the unit's header statics ----
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static egf::EntityID s_kNoEntity(0ull);
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);
static CString s_strNoticeEp("system_notice_error_ep");

// @0x141703a70
Ridee::Ridee()
    : m_pRider(0)
    , m_spD50(0)
    , m_spD58(0)
    , m_nRunFx(0)
    , m_nRunFx2(0)
    , m_nIdleFx(0)
    , m_pDC0(0)
    , m_spSeat(0)
    , m_spData(0)
    , m_pBox(0)
    , m_bDF8(false)
{
    FUN_141682f60(&m_unk_6d8, this);
    m_spStateMgr.AssignRaw(new CStateManager(this));
    m_spStateMgr->RegisterState(1, new StateIdle(this));
    m_spStateMgr->RegisterState(2, new StateWalk(this));
    m_spStateMgr->RegisterState(4, new StateLand(this));
    m_spStateMgr->RegisterState(5, new StateFall(this));
    m_spStateMgr->RegisterState(6, new StateJump(this));
    m_spStateMgr->RegisterState(0x10, new StateSkill(this));
    m_spStateMgr->RegisterState(0x1b, new StateSwim(this));
    m_spStateMgr->RegisterState(0x16, new StateTalk(this));
    m_spStateMgr->RegisterState(0x35, new StateTriggerEmotion(this));
    m_spStateMgr->RegisterState(0x46, new StateTriggerFollowNpc(this));
    m_unk_180.m_z = 3.5f;
    m_unk_180.m_y = 1.2f;
    m_unk_180.m_w = 3.5f;
    m_unk_190.m_z = 3.5f;
    m_unk_190.m_y = 1.2f;
    m_unk_190.m_w = 3.5f;
    m_nD40 = FUN_141472bc0();
    m_nD44 = 0;
    ((StatePcGuideObjectController*)&m_controller)->SetOwner(this);
    m_nDE0 = 0;
    m_f164 = 0;
    m_f174 = 0;
}

// @0x141704240
Ridee::~Ridee()
{
    if (m_nRunFx)
    {
        ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a6060(m_nRunFx);
        m_nRunFx = 0;
    }
    if (m_nRunFx2)
    {
        ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a6060(m_nRunFx2);
        m_nRunFx2 = 0;
    }
    if (m_nIdleFx)
    {
        ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a6060(m_nIdleFx);
        m_nIdleFx = 0;
    }
    FUN_1417082c0();
}

// @0x1417043a0
int Ridee::FUN_1417043a0(int nRideeId, int nObjectId, PCBase* pRider)
{
    MS2SvrPtr<CRideeData> spData = FUN_1407844b0(nRideeId);
    if (spData == 0)
        return 0;

    int nLevel = 1;
    if (Unk_RideePC* pc = reinterpret_cast<Unk_RideePC*>(efd::DynamicCast<PC, PCBase>(pRider)))
        nLevel = ((PC*)pc)->FUN_141658e60();
    const CString& strAnim = spData->FUN_140784880(nLevel);
    const CString& strModel = spData->FUN_140784920(nLevel);
    if (strAnim.IsEmpty() && strModel.IsEmpty())
        return 0;

    m_spData = spData;
    FUN_14123c5a0(nObjectId);
    vfunc_76(CStringW(L""));
    vfunc_59(1, 0, 0, 0);
    FUN_141670d50(efd::Point2(25.0f, 105.0f));
    m_unk_180.m_y = spData->m_basic.m_fWalkSpeed;
    m_unk_180.m_z = spData->m_basic.m_fRunSpeed;
    m_unk_180.m_w = spData->m_basic.m_fSwimSpeed;
    FUN_141671960(spData->m_basic.m_fRunSpeed);
    SetScaleAC(spData->m_basic.m_fScale);
    if (strAnim.IsEmpty())
    {
        m_str88 = "MS2PropCollide";
        FUN_14123bb80("urn:gamebryo-scenegraph:" + strModel);
    }
    else
    {
        FUN_14123bb80("urn:gamebryo-animation:" + strAnim);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1417043a0, Ridee, FUN_1417043a0, 925, 0xFC8D7B99);

// @0x141704750
int Ridee::vfunc_10()
{
    PCBase::vfunc_10();
    ((class GameObjectController*)(void*)(m_unk_150))->FUN_14123fbf0(2);
    ((class GameObjectController*)(void*)(m_unk_150))->FUN_14123fd30(0x399);
    if (m_spData)
    {
        efd::Point3 kSize(m_spData->m_collision.m_fWidth, m_spData->m_collision.m_fDepth * 0.5f, m_spData->m_collision.m_fHeight);
        efd::Point3 kOffset(0, m_spData->m_collision.m_fDepth * 0.5f, 0);
        FUN_141670fd0(kSize, kOffset);
        if (m_pRider)
        {
            m_pRider->vfunc_59(0x21, 0, 0, 0);
            NiPoint3 kPos = m_pRider->vfunc_18();
            egf::EntityPtr spEntity((egf::Entity*)((class GameObjectController*)(class Unk_RideeBody*)(m_pRider->GetPhysicsBody()))->FUN_141240f20()->GetEntity());
            if (spEntity != 0)
            {
                MS2Ptr<Unk_RideeFieldObj> spObj = ((class Unk_RideeWorld*)WorldService::GetInstance())->FUN_141bc4f10((Unk_Entity*)spEntity.data());
                if (spObj.get())
                {
                    kPos.z = ((CBreakableObject*)spObj.operator->())->GetPtPos().z + ((CBreakableObject*)spObj.operator->())->GetPtSize().z + 10.0f;
                    ((class GameObjectController*)(class Unk_RideeBody*)(GetPhysicsBody()))->FUN_141240f20()->SetEntity((Unk_Entity*)spEntity.data());
                    egf::EntityID kId(s_kNoEntity);
                    NiPoint3 kAt = g_kCubeGuideZero;
                    m_pRider->FUN_141678240(kId, kAt);
                    FUN_141678290(kId, kAt);
                }
                else
                {
                    ((class GameObjectController*)(class Unk_RideeBody*)(GetPhysicsBody()))->FUN_141240f20()->SetEntity((Unk_Entity*)spEntity.data());
                }
            }
            kPos.z += 25.0f;
            vfunc_19(static_cast<const efd::Point3&>(kPos));
            ((class GameObjectController*)(class Unk_RideeBody*)(m_pRider->GetPhysicsBody()))->FUN_141240f20()->FUN_140cfaf30();
            m_pRider->FUN_141678290(s_kNoEntity, g_kCubeGuideZero);
            vfunc_24(0);
        }
        MakeNxBoxController();
    }
    return 1;
}

// @0x141704c80
void Ridee::vfunc_12()
{
    PCBase::vfunc_12();
    for (size_t i = 0; i < m_spData->m_effectDummies.size(); i++)
        FUN_141674ef0(m_spData->m_effectDummies[i]);

    if (NiAVObject* pRoot = FUN_141b6efc0(reinterpret_cast<egf::Entity*>(FUN_14123c410())))
    {
        m_spSeat = pRoot->GetObjectByName((const char*)m_spData->FUN_140784970()->m_strRideBone);
        if (DAT_143ae2b30 == 0)
        {
            if (m_spSeat)
            {
                NiTransformData* pData = NiNew NiTransformData;
                m_pDC0 = NiNew RideeInterpolator(pData);
                m_pDC0->SetObjectId(m_pRider->FUN_14123c580());
                NiTransformController* pController = NiNew NiTransformController;
                pController->SetInterpolator(m_pDC0, 0);
                pController->SetTarget(m_spSeat);
                pController->ResetTimeExtrema();
            }
        }
    }
    FUN_1417072b0();
    if (m_pRider)
    {
        m_pRider->vfunc_59(0x21, 0, 0, 0);
        vfunc_19(static_cast<const efd::Point3&>(m_pRider->vfunc_18()));
        if (reinterpret_cast<COptimizer*>(FUN_1409f7c90())->FUN_140ddcc90() == 0 && m_unk_40 != 0)
        {
            bool bValue = false;
            FUN_14098c6e0(FUN_14123c410(), 0xa0b6b179, bValue);
        }
    }
    if (m_spData->m_basic.m_strLoopEffect != "")
    {
        Unk_EffectQuery kQuery;
        kQuery.m_strName = m_spData->m_basic.m_strLoopEffect;
        kQuery.m_nObject = ((WorldService*)(Unk_RideeWorld*)(((class Unk_RideeWorld*)WorldService::GetInstance())))->FUN_141bd1a10((Unk_WsC_GameObj*)(PCBase*)(this));
        kQuery.SetActor(FUN_14123c580());
        m_nIdleFx = ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a49c0(*(Unk_EffectTarget*)(NoticeMessage*)(&kQuery));
    }
    FUN_14166e0a0();
}

// @0x141705220
int Ridee::vfunc_58()
{
    PCBase* pRider = GetRider();
    if (pRider)
        return pRider->vfunc_58();
    return 3;
}
MS2_REPLACE_METHOD(0x141705220, Ridee, vfunc_58, 63, 0x29EFCE6D);

// @0x141705270
void Ridee::vfunc_24(int n)
{
    if (m_pRider)
    {
        if (m_unk_b0 != 0 && m_unk_40 == m_pRider->vfunc_25())
            return;
        m_unk_40 = m_pRider->vfunc_25();
        if (reinterpret_cast<COptimizer*>(FUN_1409f7c90())->FUN_140ddcc90() == 0)
        {
            efd::SmartPointer<ecr::SceneGraphService> spService(FUN_1410a68f0(&DAT_143b059e8));
            if (m_unk_40 != 0)
            {
                bool bValue = false;
                FUN_14098c6e0(m_unk_80, 0xa0b6b179, bValue);
            }
            else if (m_unk_b0 == 0)
            {
                bool bValue = true;
                FUN_14098c6e0(m_unk_80, 0xa0b6b179, bValue);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141705270, Ridee, vfunc_24, 298, 0xD16A2101);

// @0x1417053a0
void Ridee::vfunc_21(efd::Point3 kDir)
{
    if (m_pRider)
    {
        float fZ = 0;
        if (m_pRider->FUN_1416749a0()->TryGetFixedZRotation(fZ))
            kDir.z = fZ;
    }
    PCBase::vfunc_21(kDir);
}
MS2_REPLACE_METHOD(0x1417053a0, Ridee, vfunc_21, 132, 0xA4D70419);

// @0x141705430
void Ridee::vfunc_105(efd::Point3 kPos, void* b, void* c, int d)
{
    if (m_pRider)
        m_pRider->vfunc_105(kPos, b, c, d);
    else
        PCBase::vfunc_105(kPos, b, c, d);
}
MS2_REPLACE_METHOD(0x141705430, Ridee, vfunc_105, 197, 0x50F9DCAE);

// @0x141705500
int Ridee::vfunc_122(void* p)
{
    if (m_pRider)
        return m_pRider->vfunc_122(p);
    return PCBase::vfunc_122(p);
}
MS2_REPLACE_METHOD(0x141705500, Ridee, vfunc_122, 89, 0x638FAE5A);

// @0x141705560
int Ridee::vfunc_57()
{
    return 0x3e9;
}
MS2_REPLACE_METHOD(0x141705560, Ridee, vfunc_57, 11, 0x09C54D3F);

// @0x141705580
const char* Ridee::vfunc_123(int n)
{
    if (m_spData)
    {
        switch (n)
        {
        case 0x1e:
            return m_spData->m_basic.m_strIdleXMotion;
        case 0x1f:
            return m_spData->m_basic.m_strRunXMotion;
        }
    }
    return PCBase::vfunc_123(n);
}
MS2_REPLACE_METHOD(0x141705580, Ridee, vfunc_123, 152, 0x69999D56);

// @0x141705620
void Ridee::vfunc_110()
{
    m_bDF8 = true;
}
MS2_REPLACE_METHOD(0x141705620, Ridee, vfunc_110, 18, 0xA7C52B60);

// @0x141705640
void Ridee::vfunc_119()
{
    MS2SvrPtr<CRideeData> spData = GetData();
    if (spData)
    {
        for (int i = 0; i < (int)spData->m_passengers.FUN_140784180(); i++)
        {
            Unk_RiderPtr spModel = spData->FUN_1407849c0(i);
            if (spModel)
            {
                CString strNode(spModel->m_strRideBone);
                if (strNode.IsEmpty())
                    return;
                if (NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(reinterpret_cast<egf::Entity*>(FUN_14123c410()))))
                {
                    NiAVObject* pNode;
                    {
                        NiFixedString kName(strNode);
                        pNode = pRoot->GetObjectByName(kName);
                    }
                    if (pNode)
                    {
                        efd::SmartPointer<NiAVObject> spNode(pNode);
                        GetRider()->FUN_141708b10().SetAt(FUN_140188f50(pNode->GetName(), 0), spNode);
                    }
                }
            }
        }
    }
}

// @0x141705880
Unk_PCBaseFxLib* Ridee::vfunc_70()
{
    return (Unk_PCBaseFxLib*)((CEmotionManager*)FUN_140a50010())->GetNpcTable();
}
MS2_REPLACE_METHOD(0x141705880, Ridee, vfunc_70, 27, 0x48167045);

// @0x1417058b0
void Ridee::FUN_1417058b0()
{
    MS2SvrPtr<CRideeData> spData = GetData();
    if (spData)
    {
        for (int i = 0; i < (int)spData->m_passengers.FUN_140784180(); i++)
        {
            Unk_RiderPtr spModel = spData->FUN_1407849c0(i);
            if (spModel)
            {
                CString strNode(spModel->m_strRideBone);
                if (strNode.IsEmpty())
                    return;
                if (NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(reinterpret_cast<egf::Entity*>(FUN_14123c410()))))
                {
                    NiAVObject* pNode;
                    {
                        NiFixedString kName(strNode);
                        pNode = pRoot->GetObjectByName(kName);
                    }
                    if (pNode)
                        GetRider()->FUN_141708b10().RemoveKey(FUN_140188f50(pNode->GetName(), 0));
                }
            }
        }
    }
}

// @0x141705ac0
void Ridee::FUN_141705ac0(double fTime)
{
    ((class Unk_PCMove*)(void*)(&m_unk_6d8))->FUN_141683a90();
    FUN_141705b60(fTime);
    if (FUN_14166ccb0()->vfunc_18())
        UpdateTargetYawFromLook();
    FUN_14166ccb0()->vfunc_8(fTime);
}
MS2_REPLACE_METHOD(0x141705ac0, Ridee, FUN_141705ac0, 140, 0xCEC6EC71);

// @0x141705b60
void Ridee::FUN_141705b60(double fTime)
{
    if (!((class Unk_PCMove*)(void*)(&m_unk_6d8))->FUN_141682fe0(0x49401))
    {
        FUN_141676b50(0);
        return;
    }
    if (!FUN_1416749c0())
    {
        if (FUN_141676b70() == 0)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = m_spData->m_basic.m_strPressXEffectIdle;
            kQuery.m_nObject = 1;
            kQuery.SetActor(FUN_14123c580());
            ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a4a00(*(Unk_EffectTarget*)(NoticeMessage*)(&kQuery));
        }
        FUN_141676b50(1);
        int bSpawn = 1;
        if (m_nRunFx)
        {
            ATL::CAtlArray<efd::SmartPointer<CEffect> > kLive;
            ((CEffectService*)TSingleton<CEffectService>::GetInstance())->GetGroupEffects(m_nRunFx, kLive);
            if (kLive.GetCount() == 0)
                m_nRunFx = 0;
            else
                bSpawn = 0;
        }
        if (bSpawn)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = m_spData->m_basic.m_strPressXEffectIdleNonstop;
            kQuery.m_nObject = ((WorldService*)(Unk_RideeWorld*)(((class Unk_RideeWorld*)WorldService::GetInstance())))->FUN_141bd1a10((Unk_WsC_GameObj*)(PCBase*)(this));
            kQuery.SetActor(FUN_14123c580());
            m_nRunFx = ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a49c0(*(Unk_EffectTarget*)(NoticeMessage*)(&kQuery));
        }
        return;
    }

    int bNeedStamina = ((class Unk_RideeWorld*)WorldService::GetInstance())->FUN_141bd30a0()->m_nA4;
    int bFree = m_spData->m_basic.m_nRunXConsumeEp == 0;
    if (bNeedStamina != 0 && !FUN_1417060d0())
    {
        FUN_141676b50(0);
        const unsigned int nInterval = 5000;
        if (GetTickCountMs2() - m_nD44 > nInterval)
        {
            m_nD44 = GetTickCountMs2();
            FUN_141275260(0x48, 1, 0);
            FUN_141276180(s_strNoticeEp, "");
        }
    }
    else if (bNeedStamina != 0 || bFree != 0)
    {
        if (FUN_141676b70() == 0)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = m_spData->m_basic.m_strPressXEffectRun;
            kQuery.m_nObject = 1;
            kQuery.SetActor(FUN_14123c580());
            ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a4a00(*(Unk_EffectTarget*)(NoticeMessage*)(&kQuery));
        }
        FUN_141676b50(1);
        int bSpawn = 1;
        if (m_nRunFx2)
        {
            ATL::CAtlArray<efd::SmartPointer<CEffect> > kLive;
            ((CEffectService*)TSingleton<CEffectService>::GetInstance())->GetGroupEffects(m_nRunFx2, kLive);
            if (kLive.GetCount() == 0)
                m_nRunFx2 = 0;
            else
                bSpawn = 0;
        }
        if (bSpawn)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = m_spData->m_basic.m_strPressXEffectRunNonstop;
            kQuery.m_nObject = ((WorldService*)(Unk_RideeWorld*)(((class Unk_RideeWorld*)WorldService::GetInstance())))->FUN_141bd1a10((Unk_WsC_GameObj*)(PCBase*)(this));
            kQuery.SetActor(FUN_14123c580());
            m_nRunFx2 = ((CEffectService*)(Unk_RideeEffects*)(((class Unk_RideeEffects*)TSingleton<CEffectService>::GetInstance())))->FUN_1411a49c0(*(Unk_EffectTarget*)(NoticeMessage*)(&kQuery));
        }
    }
}

// @0x1417060d0
bool Ridee::FUN_1417060d0()
{
    if (m_spData->m_basic.m_nRunXConsumeEp == 0)
        return true;
    int nNow = FUN_141472bc0();
    if ((unsigned int)(nNow - m_nD40) <= 1000)
        return true;
    if (m_pRider->FUN_141670a00(10) >= m_spData->m_basic.m_nRunXConsumeEp)
    {
        m_nD40 = nNow;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1417060d0, Ridee, FUN_1417060d0, 165, 0x6A0276AB);

// @0x141706180
void Ridee::vfunc_67(efd::Point3* pDir, efd::Point3* pSide)
{
    m_posBF4 = reinterpret_cast<NiPoint3&&>(static_cast<Vector3&&>(TSingleton<CameraMgr>::GetInstance()->FUN_140af8290()));   // C3: was Unk_RideeCamera::FUN_140af8290 (NiPoint3 view)
    PCBase::vfunc_67(pDir, pSide);
}
MS2_REPLACE_METHOD(0x141706180, Ridee, vfunc_67, 82, 0xB163C752);

// @0x1417061e0
MS2Ptr<Unk_PCBaseComp_b18> Ridee::vfunc_104(bool a, bool b, bool c)
{
    return m_pRider->vfunc_104(a, b, c);
}
MS2_REPLACE_METHOD(0x1417061e0, Ridee, vfunc_104, 112, 0xE7D22CEE);

// @0x141706260
bool Ridee::vfunc_102(MS2Ptr<CSkillRecord> skill)
{
    return m_pRider->vfunc_102(skill);
}
MS2_REPLACE_METHOD(0x141706260, Ridee, vfunc_102, 115, 0x8A2AE959);

// @0x1417062e0
int Ridee::vfunc_116()
{
    return m_pRider->vfunc_116();
}
MS2_REPLACE_METHOD(0x1417062e0, Ridee, vfunc_116, 47, 0x0E80BE59);

// @0x141706320
void Ridee::vfunc_49()
{
    CGraphicOptionTable* pMgr = TSingleton<CGraphicOptionTable>::GetInstance();
    int nKind = 1;
    if (m_pRider->GetClassID() == 0x6200004)
        nKind = 0;
    int a = pMgr->GetShadowOption(nKind);
    int b = pMgr->GetShadowOptionOffset(nKind);
    const float fScale = 1.0f;
    m_spShadow = NiNew CObjectShadow(this, a, b, m_spData->m_shadow.m_fScale, fScale);
    FUN_14123cb20(m_bUnkB8);
}

// @0x141706490
float Ridee::vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut)
{
    return m_pRider->vfunc_115(a, b, c, d, nFlag, pOut);
}
MS2_REPLACE_METHOD(0x141706490, Ridee, vfunc_115, 116, 0x6486A19D);

// @0x141706510
void Ridee::SetRider(PCBase* pRider)
{
    m_pRider = pRider;
}
MS2_REPLACE_METHOD(0x141706510, Ridee, SetRider, 28, 0x3CB6144A);

// @0x141706540
PCBase* Ridee::GetRider()
{
    return m_pRider;
}
MS2_REPLACE_METHOD(0x141706540, Ridee, GetRider, 18, 0xB14E6424);

// @0x141706560
NiNode* Ridee::FUN_141706560()
{
    return m_spD58;
}
MS2_REPLACE_METHOD(0x141706560, Ridee, FUN_141706560, 33, 0x91641508);

// @0x141706590
void Ridee::FUN_141706590()
{
    ((StatePcGuideObjectController*)&m_controller)->FUN_1417b76b0(reinterpret_cast<Unk_RideeClock*>(TSingleton<CMainSystem>::GetInstance())->GetLastGameTimeDelta());
    m_controller.vfunc_0();
}
MS2_REPLACE_METHOD(0x141706590, Ridee, FUN_141706590, 87, 0xB093DCCD);

// @0x1417065f0
void Ridee::vfunc_114(void* p)
{
    if (m_spStateMgr.get())
        m_spStateMgr->FUN_1417db2e0((Unk_StateArg22*)p);
}
MS2_REPLACE_METHOD(0x1417065f0, Ridee, vfunc_114, 75, 0x2A3EE1C8);

// @0x141706650
void Ridee::FUN_141706650(bool bForce)
{
    if (!GetCurStateId())
        return;
    ((StatePcGuideObjectController*)&m_controller)->FUN_1417b76b0(reinterpret_cast<Unk_RideeClock*>(TSingleton<CMainSystem>::GetInstance())->GetLastGameTimeDelta());
    if (((StatePcGuideObjectController*)&m_controller)->FUN_1417b7490())
        m_controller.vfunc_0();
    if (m_nDE0 == 0)
    {
        if (vfunc_18().z < ((class Unk_RideeWorld*)WorldService::GetInstance())->GetBoundsMin().z)
        {
            m_nDE0 = 1;
            bForce = true;
        }
    }

    bool bSend = false;
    MS2Ptr<Unk_StateArg22> spCur = m_controller.FUN_1417b7620();
    if (bForce || m_bDF8 || spCur == 0 || spCur->m_vel3c != m_pos98 || spCur->m_nState != GetCurStateId()
        || FUN_14166ccb0()->vfunc_22(spCur))
        bSend = true;
    if (!bSend)
        return;

    m_bDF8 = false;
    int bFlushAfter = 0;
    if (spCur.get())
    {
        if (spCur->m_nState == 2 && m_spStateMgr->GetCur() != 2)
            bFlushAfter = 1;
        else
            m_controller.vfunc_0();
    }

    MS2Ptr<Unk_StateArg22> spNew = FUN_140835450(GetCurStateId());
    spNew->m_nSub = FUN_14166cc80();
    spNew->m_vel3c = m_pos98;
    spNew->m_pos20 = vfunc_18();
    spNew->m_dir2c = vfunc_20();
    spNew->m_f58 = GetTargetYaw();
    spNew->m_pos48 = m_posBF4;
    spNew->m_n54 = reinterpret_cast<Unk_RideeCamera*>(TSingleton<CameraMgr>::GetInstance())->FUN_140af7e30();
    spNew->m_nAC = ((CMainSystem*)(Unk_RideeClock*)(reinterpret_cast<Unk_RideeClock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473390();
    if (State* pState = FUN_14166ccb0())
        pState->vfunc_26((Unk_StateDataArg*)spNew.get());

    if (m_unk_ae0 != s_kNoEntity)
    {
        if (Unk_RideeEntity* pEntity = ((Unk_RideeEntity*)((EntityWorldManager*)(Unk_RideeEntityMgr*)(reinterpret_cast<Unk_RideeEntityMgr*>(TSingleton<EntityWorldManager>::GetInstance())))->FUN_1411cf440(m_unk_ae0)))
        {
            efd::utf8string strModel;
            efd::ParseHelper<efd::ID128>::ToString(((egf::Entity*)(Unk_RideeEntity*)(pEntity))->GetDataFileID(), strModel);
            CString strName(strModel.c_str());
            FUN_1401d3700(strName);
            if (((class Unk_RideeWorld*)WorldService::GetInstance())->FUN_141bc4e70(strName).get())
            {
                NiPoint3 kObjPos;
                reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(kObjPos));
                spNew->m_str88 = strName;
                spNew->m_pos78 = vfunc_18() - kObjPos;
            }
            if (((egf::FlatModel*)((egf::Entity*)(Unk_RideeEntity*)(pEntity))->GetModel())->ContainsModel(0xd8dea70d))
            {
                bool bRideable = false;
                unsigned short nKind = 0;
                reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<bool>(0xecfdd742, bRideable);   // C3: was Unk_RideeEntity::FUN_1408a20a0
                reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<unsigned short>(0xada5c5d2, nKind);
                if (bRideable && (nKind == 9 || nKind == 8))
                {
                    NiPoint3 kPropPos;
                    reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(kPropPos));
                    efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
                    if (reinterpret_cast<CubeMapInformationService*>(spService.operator->())->GetCubeAtPoint(reinterpret_cast<Vector3&>(kPropPos)) && vfunc_99(0) == 0)
                    {
                        if (FUN_1409f7ca0()->FUN_14168a9b0(pEntity, vfunc_18()))
                            spNew->m_nA0 = FUN_1408a13d0(kPropPos);
                    }
                }
            }
        }
    }
    ((StatePcGuideObjectController*)&m_controller)->FUN_1417b7670((Unk_GuideRecord*)spNew.get());
    if (bFlushAfter)
        m_controller.vfunc_0();
}

// @0x141706fd0
int Ridee::vfunc_108()
{
    return m_pRider->vfunc_108();
}
MS2_REPLACE_METHOD(0x141706fd0, Ridee, vfunc_108, 47, 0xB7A50299);

// @0x141707010
MS2Ptr<Unk_PCBaseComp_b18> Ridee::vfunc_103()
{
    return m_pRider->vfunc_103();
}
MS2_REPLACE_METHOD(0x141707010, Ridee, vfunc_103, 81, 0x3865016B);

// @0x141707070
int Ridee::vfunc_69()
{
    return m_spData->m_basic.m_nId;
}
MS2_REPLACE_METHOD(0x141707070, Ridee, vfunc_69, 36, 0x619CC090);

// @0x1417070a0
float Ridee::GetRideSpeed()
{
    float fSpeed = m_spData->m_basic.m_fRunXSpeed;
    if (!m_pRider)
        return fSpeed;
    Unk_RideePC* pc = reinterpret_cast<Unk_RideePC*>(efd::DynamicCast<PC, PCBase>(m_pRider));
    if (!pc)
        return fSpeed;
    if (FUN_14028d470(m_spData->m_basic.m_fRunSpeed, m_spData->m_basic.m_fRunXSpeed))
        return FUN_1411f0e30(fSpeed, 1.0f + ((CEquipment*)((PC*)pc)->FUN_1416561a0())->GetAbilityRate((SAType)0xae));
    return FUN_1411f0e30(fSpeed, 1.0f + ((CEquipment*)((PC*)pc)->FUN_1416561a0())->GetAbilityRate((SAType)0xa5));
}
MS2_REPLACE_METHOD(0x1417070a0, Ridee, GetRideSpeed, 291, 0x5C3B4FBE);

// @0x1417071d0
float Ridee::FUN_1417071d0()
{
    float fSpeed = m_unk_180.m_z;
    if (!m_pRider)
        return fSpeed;
    Unk_RideePC* pc = reinterpret_cast<Unk_RideePC*>(efd::DynamicCast<PC, PCBase>(m_pRider));
    if (!pc)
        return fSpeed;
    return FUN_1411f0e30(fSpeed, 1.0f + ((CEquipment*)((PC*)pc)->FUN_1416561a0())->GetAbilityRate((SAType)0xae));
}
MS2_REPLACE_METHOD(0x1417071d0, Ridee, FUN_1417071d0, 146, 0x045C94C9);

// @0x141707270
void Ridee::FUN_141707270()
{
    ((StatePcGuideObjectController*)&m_controller)->FUN_1417b7450();
    m_nDE0 = 0;
}
MS2_REPLACE_METHOD(0x141707270, Ridee, FUN_141707270, 48, 0x05F57870);

// @0x1417072b0
void Ridee::FUN_1417072b0()
{
    MS2Ptr<Unk_PCBaseComp_b18> spItem = FUN_141707440();
    if (spItem == 0)
        return;
    if (((class RideeItemInfo*)(class Unk_PCBaseComp_b18*)(spItem.operator->()))->IsValid() == 0)
        return;
    CString strPath = FUN_1410280d0(7, spItem->m_strUrl);
    if (_access(strPath, 4) != 0)
    {
        TSingleton<CUgcManager>::GetInstance()->FUN_141884830(spItem, FUN_14123c460());
        return;
    }
    TSingleton<CUgcManager>::GetInstance()->FUN_141887810(this);
}
MS2_REPLACE_METHOD(0x1417072b0, Ridee, FUN_1417072b0, 393, 0x60E382B1);

// @0x141707440
MS2Ptr<Unk_PCBaseComp_b18> Ridee::FUN_141707440()
{
    if (!GetRider())
        return MS2Ptr<Unk_PCBaseComp_b18>(0);
    return GetRider()->FUN_141676930();
}
MS2_REPLACE_METHOD(0x141707440, Ridee, FUN_141707440, 111, 0x7A3B4502);

// @0x1417074c0
void Ridee::FUN_1417074c0()
{
    if (!m_pRider)
        return;
    MS2SvrPtr<CRideeData> spData = FUN_1407844b0(m_pRider->FUN_141676410());
    if (spData == 0)
        return;
    if (FUN_14123bea0() == 0)
        return;
    FUN_1417083a0(m_pRider, m_spSeat, spData->FUN_140784970());
}
MS2_REPLACE_METHOD(0x1417074c0, Ridee, FUN_1417074c0, 282, 0x26BFB6CE);

// @0x1417075e0
int Ridee::FUN_1417075e0()
{
    if (!m_pRider)
        return 0;
    Unk_RideePC* pc = reinterpret_cast<Unk_RideePC*>(efd::DynamicCast<PC, PCBase>(m_pRider));
    if (!pc)
        return 0;
    if (GetData()->m_basic.m_nType == 1 || GetData()->m_basic.m_nType == 2)
        return 1;
    if (pc->FUN_1416749a0()->HasEnabledWithEventBuffType(3))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1417075e0, Ridee, FUN_1417075e0, 354, 0x578429A8);

// @0x141707750
MS2SvrPtr<CRideeData> Ridee::GetData()
{
    return m_spData;
}
MS2_REPLACE_METHOD(0x141707750, Ridee, GetData, 67, 0x6F354F30);

// @0x1417077a0
MS2Ptr<Unk_PCBaseComp_a58> Ridee::vfunc_80()
{
    if (((Unk_AvModeSvc*)(FUN_1409f7c90()))->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (!reinterpret_cast<Unk_RideeOptions*>(TSingleton<CGameOption>::GetInstance())->FUN_140b123b0()->m_bShowHpBar)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (m_spA58 == 0)
        m_spA58 = FUN_141992920(m_unk_70);
    return m_spA58;
}
MS2_REPLACE_METHOD(0x1417077a0, Ridee, vfunc_80, 290, 0xFB08F93E);

// @0x1417078d0
float Ridee::vfunc_89()
{
    if (m_spData)
        return m_spData->FUN_140784970()->m_fNameTagOffsetY;
    return 0;
}
MS2_REPLACE_METHOD(0x1417078d0, Ridee, vfunc_89, 136, 0x27AA4A41);

// @0x141707960
float Ridee::FUN_141707960()
{
    if (m_spData)
        return m_spData->FUN_140784970()->m_fHpBarOffsetY;
    return 0;
}
MS2_REPLACE_METHOD(0x141707960, Ridee, FUN_141707960, 136, 0x6FC70E00);

// @0x1417079f0
void Ridee::vfunc_53(float f)
{
    PCBase::vfunc_53(f);
    FUN_141678360();
    bool bVisible = m_timer970.FUN_140868c00() == 0 && m_timer970.FUN_140868ba0() != 0 ? false : true;
    if (bVisible)
        m_timer970.FUN_140868750(200);
    vfunc_93(bVisible);
    if (m_spShadow)
    {
        if (m_spShadow->FUN_141534300())
        {
            if (NiAVObject* pRoot = FUN_141b6efc0(reinterpret_cast<egf::Entity*>(FUN_14123c410())))
                pRoot->UpdateEffects();
        }
    }
    if (DAT_143ae2b30 == 0 && m_pRider)
    {
        m_pRider->vfunc_19(static_cast<const efd::Point3&>(vfunc_18()));
        m_pRider->vfunc_21(static_cast<const efd::Point3&>(vfunc_20()));
    }
    if (m_pBox && (bool)m_spData)
    {
        NiPoint3 kPos = vfunc_18();
        NiPoint3 kRot = vfunc_20();
        efd::Point3 kHalf(m_spData->m_collision.m_fWidth, m_spData->m_collision.m_fDepth, m_spData->m_collision.m_fHeight);
        kHalf = kHalf * 0.01f * 0.5f;
        NxMat34 kPose(true);
        kPose.t = NxVec3(kPos.x, kPos.y, kPos.z);
        kPose.t = kPose.t * 0.01f;
        kPose.t.z = kPose.t.z + kHalf.z + 0.2f;
        kPose.M.rotZ(kRot.z * 3.1415927f / 180.0f);
        FUN_1409f7ca0()->FUN_14168a540(0);
        m_pBox->setGlobalPose(kPose);
        FUN_1409f7ca0()->FUN_14168a570();
    }
}
MS2_REPLACE_METHOD(0x1417079f0, Ridee, vfunc_53, 1128, 0x01E9F3D0);

// @0x141707e60
void Ridee::MakeNxBoxController()
{
    if (m_spData == 0)
        return;
    if (!m_spData->m_collision.m_bPhysic)
        return;
    if (m_pBox)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (!pScene)
        return;

    NiPoint3 kPos = vfunc_18();
    NiPoint3 kRot = vfunc_20();
    efd::Point3 kSize(m_spData->m_collision.m_fWidth, m_spData->m_collision.m_fDepth, m_spData->m_collision.m_fHeight);
    NxBoxShapeDesc kBoxDesc;
    kBoxDesc.dimensions.set(kSize.x, kSize.y, kSize.z);
    kBoxDesc.dimensions = kBoxDesc.dimensions * 0.01f * 0.5f;
    kBoxDesc.groupsMask.bits0 = 0xffffffff;
    kBoxDesc.shapeFlags &= ~(NX_SF_CLOTH_TWOWAY | NX_SF_SOFTBODY_TWOWAY);
    NxBodyDesc kBodyDesc;
    kBodyDesc.flags |= NX_BF_KINEMATIC;
    kBodyDesc.mass = 1.0f;
    kBodyDesc.massSpaceInertia.set(1.0f, 1.0f, 1.0f);
    NxActorDesc kActorDesc;
    kActorDesc.body = &kBodyDesc;
    kActorDesc.shapes.pushBack(&kBoxDesc);
    kActorDesc.globalPose.t = NxVec3(kPos.x, kPos.y, kPos.z);
    kActorDesc.globalPose.t = kActorDesc.globalPose.t * 0.01f;
    kActorDesc.globalPose.t.z = kActorDesc.globalPose.t.z + kBoxDesc.dimensions.z + 0.2f;
    kActorDesc.globalPose.M.rotZ(kRot.z * 3.1415927f / 180.0f);
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pBox = pScene->createActor(kActorDesc);
    if (m_pBox)
    {
        m_pBox->setName("Ridee::MakeNxBoxController");
        NxU32 nShapes = m_pBox->getNbShapes();
        NxShape* const* ppShapes = m_pBox->getShapes();
        for (NxU32 i = 0; i < nShapes; i++)
        {
            NxShape* pShape = ppShapes[i];
            pShape->setGroup(0);
        }
    }
    FUN_1409f7ca0()->FUN_14168a570();
}

// @0x1417082c0
void Ridee::FUN_1417082c0()
{
    if (m_spData == 0)
        return;
    if (!m_spData->m_collision.m_bPhysic)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (!pScene)
        return;
    if (m_pBox)
    {
        FUN_1409f7ca0()->FUN_14168a540(0);
        pScene->releaseActor(*m_pBox);
        ((class Unk_RideeWorld*)WorldService::GetInstance())->FUN_141bc8e00();
        FUN_1409f7ca0()->FUN_14168a570();
        m_pBox = 0;
    }
}
MS2_REPLACE_METHOD(0x1417082c0, Ridee, FUN_1417082c0, 210, 0xF313323A);

// @0x1417083a0
void Ridee::FUN_1417083a0(PCBase* pRider, efd::SmartPointer<NiAVObject> spSeat, Unk_RiderPtr spModel)
{
    if (!pRider || spSeat == 0 || spModel == 0)
        return;
    efd::SmartPointer<NiNode> spSeatNode(NiDynamicCast(NiNode, (NiAVObject*)spSeat));
    NiAVObject* pRiderRoot = FUN_141b6ef70(pRider->FUN_14123c460());
    if (spSeatNode && pRiderRoot)
    {
        NiTransform kWorld = spSeatNode->GetLocalTransform();
        NiTransform kParent;
        kParent.MakeIdentity();
        if (spSeatNode->GetParent())
            kParent = spSeatNode->GetParent()->GetWorldTransform();
        kWorld = kParent * kWorld;
        NiPoint3 kPos = kWorld.m_Translate;
        NiMatrix3 kRotate = kWorld.m_Rotate;

        efd::Point3 kAngles;
        efd::Point3 kSeatRot(spModel->m_vRotation.x, spModel->m_vRotation.y, spModel->m_vRotation.z);
        NiMatrix3 kSeatMatrix;
        FUN_140b86230(kSeatRot, kSeatMatrix);
        kRotate = kRotate * kSeatMatrix;
        FUN_140a0b1f0(kRotate, kAngles);

        NiPoint3 kX;
        kRotate.GetCol(0, kX);
        kX.Unitize();
        NiPoint3 kY;
        kRotate.GetCol(1, kY);
        kY.Unitize();
        NiPoint3 kZ;
        kRotate.GetCol(2, kZ);
        kZ.Unitize();
        kPos = kPos + kY * -spModel->m_vTranslation.y;
        kPos = kPos + kX * (0, spModel->m_vTranslation.x);
        kPos = kPos + kZ * (0, spModel->m_vTranslation.z);
        pRider->vfunc_19(kPos);
        pRider->vfunc_21(kAngles);
    }
}

// @0x141708950
StateRideeController::StateRideeController()
{
}

// ??_G 0x141708a30, GetClassDesc 0x141708af0, the class info setup 0x1417090c0 and TypeCast 0x141709280/0x1417092d0
// come from EE_DECLARE_CLASS1 / EE_IMPLEMENT_CONCRETE_CLASS_INFO.

