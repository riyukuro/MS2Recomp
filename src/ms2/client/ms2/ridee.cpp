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
#include "ridee.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <io.h>
#include <NxPhysics.h>
#include <NiTransformData.h>
#include <NiTransformInterpolator.h>
#include <NiTransformController.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <ecr/SceneGraphService.h>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/client/ms2/stateemotionidle.h"         // StateTriggerEmotion, StateTriggerFollowNpc
#include "ms2/client/ms2/gameobjectcontrollerhitreport.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/effectparam.h"

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

// The riding table (unit_140781d80).
MS2Ptr<Unk_RideeData> FUN_1407844b0(int nRideeId);

// MS2Ptr members instantiated by other objs.
template <> MS2Ptr<Unk_RideeData>::MS2Ptr(int nNull);                                   // 0x140788a00
template <> MS2Ptr<Unk_RideeData>::MS2Ptr(const MS2Ptr& o);                              // 0x1407889c0
template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0
template <> MS2Ptr<Unk_RideeData>& MS2Ptr<Unk_RideeData>::operator=(const MS2Ptr& o);   // 0x1407892d0
template <> bool MS2Ptr<Unk_RideeData>::operator==(Unk_RideeData* p) const;             // 0x1407893c0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::get() const;                          // 0x1409f78a0
template <> MS2Ptr<Unk_RideeModel>::~MS2Ptr();                                          // 0x140788ea0
template <> Unk_RideeModel* MS2Ptr<Unk_RideeModel>::operator->() const;                 // 0x1407895c0
template <> Unk_RideeModel* MS2Ptr<Unk_RideeModel>::get() const;                        // 0x140789570
template <> bool MS2Ptr<Unk_RideeModel>::operator==(Unk_RideeModel* p) const;           // 0x140789380
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
int FUN_140897300(Unk_PCBaseComp_b18* pItem);                       // the item has a ugc texture

// The ugc texture manager.
class Unk_RideeUgcMgr
{
public:
    void FUN_141887810(Ridee* pRidee);                              // apply the downloaded texture
    void FUN_141884830(MS2Ptr<Unk_PCBaseComp_b18> spItem, egf::EntityID kId);   // download it
};
Unk_RideeUgcMgr* FUN_14052d220();
CString FUN_1410280d0(int nKind, CString strUrl);                   // local path of a ugc file

// An object of the field (prop or actor) found by entity or name.
class Unk_RideeFieldObj
{
public:
    NiPoint3 FUN_140adf8e0();                                       // position
    NiPoint3 FUN_140ae0660();                                       // collision box size
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
class Unk_RideeWorld
{
public:
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4f10(Unk_Entity* pEntity);
    int FUN_141bd1a10(PCBase* pActor);
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();
    NiPoint3 FUN_141bd37e0();                                       // water line
    MS2Ptr<Unk_RideeFieldObj> FUN_141bc4e70(CString strName);
    void FUN_141bc8e00();
};
Unk_RideeWorld* FUN_1403ed2d0();

// The effect manager (FUN_1403ed280).
class Unk_RideeEffects
{
public:
    int FUN_1411a49c0(Unk_EffectQuery* pQuery);                     // spawn, returns the handle
    void FUN_1411a4a00(Unk_EffectQuery* pQuery);                    // play once
    void FUN_1411a6060(int nHandle);                                // release
    void FUN_1411a7760(int nHandle, ATL::CAtlArray<efd::SmartPointer<CEffect> >& out);    // the live instances of a handle
};
Unk_RideeEffects* FUN_1403ed280();

class Unk_RideeGameMode
{
public:
    int FUN_1409f7ea0();
    int FUN_140ddcc90();
};
Unk_RideeGameMode* FUN_1409f7c90();

class Unk_RideeEntity;
class Unk_RideePhysX
{
public:
    NxScene* FUN_14168a1c0();
    void FUN_14168a540(int n);                                      // lock
    void FUN_14168a570();                                           // unlock
    int FUN_14168a9b0(Unk_RideeEntity* pEntity, efd::Point3 kPos);
};
Unk_RideePhysX* FUN_1409f7ca0();

// The server clock.
class Unk_RideeClock
{
public:
    float FUN_141473230();
    unsigned int FUN_141473390();
};
Unk_RideeClock* FUN_14086d260();
int FUN_141472bc0();
unsigned int FUN_140869420();                                       // GetTickCountMs2

class Unk_RideeCamera
{
public:
    int FUN_140af7e30();
    NiPoint3 FUN_140af8290();
};
Unk_RideeCamera* FUN_1409478c0();

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
Unk_RideeOptions* FUN_1409a8b10();

class Unk_RideeSpawnMgr
{
public:
    Unk_PCBaseFxLib* FUN_1411bf1e0();
};
Unk_RideeSpawnMgr* FUN_140a50010();

class Unk_RideeShadowMgr
{
public:
    int FUN_141376880(bool b);
    int FUN_1413769d0(bool b);
};
Unk_RideeShadowMgr* FUN_140ae1c00();

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
class Unk_PCBaseBuffs
{
public:
    int FUN_1409701d0(int nKind);
    int FUN_140970eb0(float& fOut);                                 // a buff fixes the height
};

// The player character behind a rider (a PCBase).
class Unk_RideePC : public PCBase
{
};
class Unk_RideeStats;
Unk_RideePC* FUN_140974230(PCBase* pActor);
int FUN_141658e60(Unk_RideePC* pc);                                 // level
Unk_RideeStats* FUN_1416561a0(Unk_RideePC* pc);
float FUN_1411e1110(Unk_RideeStats* pStats, int nStat);
float FUN_1411f0e30(float fBase, float fRate);
bool FUN_14028d470(float a, float b);

// The physics body of an actor and its controller hit report.
class Unk_RideeBody;
Unk_RideeBody* FUN_14166d220(PCBase* pActor);
GameObjectControllerHitReport* FUN_141240f20(Unk_RideeBody* pBody);

// An egf entity (property access).
class Unk_RideeEntityModel
{
public:
    void FUN_140ae1f60(efd::utf8string& strOut);                    // model name
};
class Unk_RideeEntity
{
public:
    void FUN_1409618c0(unsigned int uiPropId, NiPoint3& out);       // point property
    void FUN_1408a20a0(unsigned int uiPropId, bool* pOut);          // bool property
    void FUN_140ae1160(unsigned int uiPropId, int* pOut);           // int property
    Unk_RideeEntityModel* FUN_140ae1be0();
    egf::FlatModel* FUN_1408a9bd0();
};
class Unk_RideeEntityMgr
{
public:
    Unk_RideeEntity* FUN_1411cf440(const egf::EntityID& kId);
};
Unk_RideeEntityMgr* FUN_1409670f0();

// The application service (class id 0x06100017) found through the framework cell (buddy.cpp keeps the same view).
class Unk_Service6100017 : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    void* FUN_1410b8ab0(efd::Point3 kPos);                          // the cube at a position
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* pFramework);
ecr::SceneGraphService* FUN_1410a68f0(Unk_EntityAppFramework* pFramework);

extern int DAT_143ae2b30;                                           // no rendering (server/tool build)

int FUN_1408a13d0(efd::Point3 kPos);
void FUN_140b86230(const efd::Point3& kDegrees, NiMatrix3& out);  // euler angles (degrees) to a rotation
void FUN_140a0b1f0(const NiMatrix3& kRotate, NiPoint3& out);      // rotation to euler angles (degrees)
void FUN_1401d3700(CString& str);
CString FUN_140188f50(const char* psz, int n);
CString FUN_140298360(const char* pszPrefix, const CString& str);
void FUN_14098c6e0(void* pEntity, unsigned int uiPropId, const bool& b);
NiAVObject* FUN_141b6efc0(void* pEntity);                          // the scene root of an entity
NiAVObject* FUN_141b6ef70(egf::EntityID kId);
MS2Ptr<Unk_StateArg22> FUN_140835450(int nState);                   // new state record
MS2Ptr<Unk_PCBaseComp_a58> FUN_141992920(int nObjectId);           // hp bar
void FUN_141275260(int nSound, int a, int b);
void FUN_141276180(const CString& strKey, const CString& strArg);  // system notice

// PCBase's node map and its m_unk_6d8 buff tracker.
void FUN_141682f60(void* pTracker, PCBase* pOwner);
void FUN_141683a90(void* pTracker);
bool FUN_141682fe0(void* pTracker, int nKind);
void FUN_14123fbf0(void* pBody, unsigned short n);
void FUN_14123fd30(void* pBody, int n);

// The interpolator driving a seat node from the rider (?\rideeinterpolator.cpp).
class RideeInterpolator : public NiTransformInterpolator
{
public:
    RideeInterpolator(NiTransformData* pData);                      // 0x1410203a0
    void FUN_141020a70(int nObjectId);
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
// MS2-FUNCTIONAL: PCBase::m_unk_180/190 are arrays here; the exe stores to named float fields (constant offsets)
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
    m_spStateMgr->FUN_1417daeb0(1, new StateIdle(this));
    m_spStateMgr->FUN_1417daeb0(2, new StateWalk(this));
    m_spStateMgr->FUN_1417daeb0(4, new StateLand(this));
    m_spStateMgr->FUN_1417daeb0(5, new StateFall(this));
    m_spStateMgr->FUN_1417daeb0(6, new StateJump(this));
    m_spStateMgr->FUN_1417daeb0(0x10, new StateSkill(this));
    m_spStateMgr->FUN_1417daeb0(0x1b, new StateSwim(this));
    m_spStateMgr->FUN_1417daeb0(0x16, new StateTalk(this));
    m_spStateMgr->FUN_1417daeb0(0x35, new StateTriggerEmotion(this));
    m_spStateMgr->FUN_1417daeb0(0x46, new StateTriggerFollowNpc(this));
    m_unk_180[2] = 3.5f;
    m_unk_180[1] = 1.2f;
    m_unk_180[3] = 3.5f;
    m_unk_190[2] = 3.5f;
    m_unk_190[1] = 1.2f;
    m_unk_190[3] = 3.5f;
    m_nD40 = FUN_141472bc0();
    m_nD44 = 0;
    m_controller.FUN_1417b7430(this);
    m_nDE0 = 0;
    m_f164 = 0;
    m_f174 = 0;
}

// @0x141704240
Ridee::~Ridee()
{
    if (m_nRunFx)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nRunFx);
        m_nRunFx = 0;
    }
    if (m_nRunFx2)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nRunFx2);
        m_nRunFx2 = 0;
    }
    if (m_nIdleFx)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nIdleFx);
        m_nIdleFx = 0;
    }
    FUN_1417082c0();
}

// @0x1417043a0
// MS2-FUNCTIONAL: temporaries/stack layout differ (CString/MS2Ptr temporaries of the row lookups)
int Ridee::FUN_1417043a0(int nRideeId, int nObjectId, PCBase* pRider)
{
    MS2Ptr<Unk_RideeData> spData = FUN_1407844b0(nRideeId);
    if (spData == 0)
        return 0;

    int nLevel = 1;
    if (Unk_RideePC* pc = FUN_140974230(pRider))
        nLevel = FUN_141658e60(pc);
    CString strAnim = spData->FUN_140784880(nLevel);
    CString strModel = spData->FUN_140784920(nLevel);
    if (strAnim.IsEmpty() && strModel.IsEmpty())
        return 0;

    m_spData = spData;
    FUN_14123c5a0(nObjectId);
    vfunc_76(CStringW(L""));
    vfunc_59(1, 0, 0, 0);
    FUN_141670d50(efd::Point2(25.0f, 105.0f));
    m_unk_180[1] = spData->m_f78;
    m_unk_180[2] = spData->m_f7c;
    m_unk_180[3] = spData->m_f84;
    FUN_141671960(spData->m_f7c);
    FUN_14123c300(spData->m_fScale);
    if (strAnim.IsEmpty())
    {
        m_str88 = "MS2PropCollide";
        FUN_14123bb80(FUN_140298360("urn:gamebryo-scenegraph:", strModel));
    }
    else
    {
        FUN_14123bb80(FUN_140298360("urn:gamebryo-animation:", strAnim));
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1417043a0, Ridee, FUN_1417043a0, 925, 0xFC8D7B99);

// @0x141704750
// MS2-FUNCTIONAL: stack layout and temporary order of the hit-report entity handling differ
int Ridee::vfunc_10()
{
    PCBase::vfunc_10();
    FUN_14123fbf0(m_unk_150, 2);
    FUN_14123fd30(m_unk_150, 0x399);
    if (m_spData.get())
    {
        efd::Point3 kSize(m_spData->m_f108, m_spData->m_f110 * 0.5f, m_spData->m_f10c);
        efd::Point3 kOffset(0, m_spData->m_f110 * 0.5f, 0);
        FUN_141670fd0(kSize, kOffset);
        if (m_pRider)
        {
            m_pRider->vfunc_59(0x21, 0, 0, 0);
            NiPoint3 kPos = m_pRider->vfunc_18();
            Unk_EntRef spEntity(FUN_141240f20(::FUN_14166d220(m_pRider))->GetEntity());
            if (spEntity != 0)
            {
                MS2Ptr<Unk_RideeFieldObj> spObj = FUN_1403ed2d0()->FUN_141bc4f10(spEntity.FUN_1408a9090());
                if (spObj.get() == 0)
                {
                    FUN_141240f20(::FUN_14166d220(this))->SetEntity(spEntity.FUN_1408a9090());
                }
                else
                {
                    kPos.z = spObj->FUN_140adf8e0().z + spObj->FUN_140ae0660().z + 10.0f;
                    FUN_141240f20(::FUN_14166d220(this))->SetEntity(spEntity.FUN_1408a9090());
                    egf::EntityID kId(s_kNoEntity);
                    NiPoint3 kAt = NiPoint3::ZERO;
                    m_pRider->FUN_141678240(kId, kAt);
                    FUN_141678290(kId, kAt);
                }
            }
            kPos.z += 25.0f;
            vfunc_19(kPos);
            FUN_141240f20(::FUN_14166d220(m_pRider))->FUN_140cfaf30();
            m_pRider->FUN_141678290(s_kNoEntity, NiPoint3::ZERO);
            vfunc_24(0);
        }
        MakeNxBoxController();
    }
    return 1;
}

// @0x141704c80
// MS2-FUNCTIONAL: stack layout differs (NiFixedString/SmartPointer temporaries, effect query)
void Ridee::vfunc_12()
{
    PCBase::vfunc_12();
    for (size_t i = 0; i < m_spData->m_parts.FUN_14078cd60(); i++)
        FUN_141674ef0(m_spData->m_parts.FUN_140789540(i));

    if (NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410()))
    {
        m_spSeat = pRoot->GetObjectByName(NiFixedString(m_spData->FUN_140784970()->m_strNode));
        if (DAT_143ae2b30 == 0 && m_spSeat)
        {
            NiTransformData* pData = NiNew NiTransformData;
            m_pDC0 = NiNew RideeInterpolator(pData);
            m_pDC0->FUN_141020a70(m_pRider->FUN_14123c580());
            NiTransformController* pController = NiNew NiTransformController;
            pController->SetInterpolator(m_pDC0, 0);
            pController->SetTarget(m_spSeat);
            pController->ResetTimeExtrema();
        }
    }
    FUN_1417072b0();
    if (m_pRider)
    {
        m_pRider->vfunc_59(0x21, 0, 0, 0);
        vfunc_19(m_pRider->vfunc_18());
        if (FUN_1409f7c90()->FUN_140ddcc90() == 0 && m_unk_40 != 0)
        {
            bool bValue = false;
            FUN_14098c6e0(FUN_14123c410(), 0xa0b6b179, bValue);
        }
    }
    if (m_spData->m_strE0 != "")
    {
        Unk_EffectQuery kQuery;
        kQuery.m_strName = m_spData->m_strE0;
        kQuery.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.SetActor(FUN_14123c580());
        m_nIdleFx = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
    }
    FUN_14166e0a0();
}

// @0x141705220
int Ridee::vfunc_58()
{
    PCBase* pRider = FUN_141706540();
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
        if (FUN_1409f7c90()->FUN_140ddcc90() == 0)
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
        if (m_pRider->FUN_1416749a0()->FUN_140970eb0(fZ))
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
    if (m_spData.get())
    {
        switch (n)
        {
        case 0x1e:
            return m_spData->m_str90;
        case 0x1f:
            return m_spData->m_str98;
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
// MS2-FUNCTIONAL: stack layout of the CString/SmartPointer temporaries differs
void Ridee::vfunc_119()
{
    MS2Ptr<Unk_RideeData> spData = FUN_141707750();
    if (!spData.get())
        return;
    for (int i = 0; i < spData->m_seats.FUN_140784180(); i++)
    {
        MS2Ptr<Unk_RideeModel> spModel = spData->FUN_1407849c0(i);
        if (spModel.get())
        {
            CString strNode(spModel->m_strNode);
            if (strNode.IsEmpty())
                return;
            if (NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410())))
            {
                if (NiAVObject* pNode = pRoot->GetObjectByName(NiFixedString(strNode)))
                {
                    efd::SmartPointer<NiAVObject> spNode(pNode);
                    FUN_141706540()->FUN_141708b10().SetAt(FUN_140188f50(pNode->GetName(), 0), spNode);
                }
            }
        }
    }
}

// @0x141705880
Unk_PCBaseFxLib* Ridee::vfunc_70()
{
    return FUN_140a50010()->FUN_1411bf1e0();
}
MS2_REPLACE_METHOD(0x141705880, Ridee, vfunc_70, 27, 0x48167045);

// @0x1417058b0
// MS2-FUNCTIONAL: stack layout of the CString temporaries differs
void Ridee::FUN_1417058b0()
{
    MS2Ptr<Unk_RideeData> spData = FUN_141707750();
    if (!spData.get())
        return;
    for (int i = 0; i < spData->m_seats.FUN_140784180(); i++)
    {
        MS2Ptr<Unk_RideeModel> spModel = spData->FUN_1407849c0(i);
        if (spModel.get())
        {
            CString strNode(spModel->m_strNode);
            if (strNode.IsEmpty())
                return;
            if (NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410())))
            {
                if (NiAVObject* pNode = pRoot->GetObjectByName(NiFixedString(strNode)))
                    FUN_141706540()->FUN_141708b10().RemoveKey(FUN_140188f50(pNode->GetName(), 0));
            }
        }
    }
}

// @0x141705ac0
void Ridee::FUN_141705ac0(double fTime)
{
    FUN_141683a90(&m_unk_6d8);
    FUN_141705b60(fTime);
    if (FUN_14166ccb0()->vfunc_18())
        FUN_14166d820();
    FUN_14166ccb0()->vfunc_8(fTime);
}
MS2_REPLACE_METHOD(0x141705ac0, Ridee, FUN_141705ac0, 140, 0xCEC6EC71);

// @0x141705b60
// MS2-FUNCTIONAL: effect query / CAtlArray temporaries are scoped differently (exe frame 0x278)
void Ridee::FUN_141705b60(double fTime)
{
    if (!FUN_141682fe0(&m_unk_6d8, 0x49401))
    {
        FUN_141676b50(0);
        return;
    }
    if (!FUN_1416749c0())
    {
        if (FUN_141676b70() == 0)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = m_spData->m_strB8;
            kQuery.m_nObject = 1;
            kQuery.SetActor(FUN_14123c580());
            FUN_1403ed280()->FUN_1411a4a00(&kQuery);
        }
        FUN_141676b50(1);
        bool bSpawn = true;
        if (m_nRunFx)
        {
            ATL::CAtlArray<efd::SmartPointer<CEffect> > kLive;
            FUN_1403ed280()->FUN_1411a7760(m_nRunFx, kLive);
            bSpawn = kLive.GetCount() == 0;
            if (bSpawn)
                m_nRunFx = 0;
        }
        if (bSpawn)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = m_spData->m_strD0;
            kQuery.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(this);
            kQuery.SetActor(FUN_14123c580());
            m_nRunFx = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
        }
        return;
    }

    int bNeedStamina = FUN_1403ed2d0()->FUN_141bd30a0()->m_nA4;
    __int64 nStamina = m_spData->m_nA0;
    if (bNeedStamina == 0 || FUN_1417060d0())
    {
        if (bNeedStamina != 0 || nStamina == 0)
        {
            if (FUN_141676b70() == 0)
            {
                Unk_EffectQuery kQuery;
                kQuery.m_strName = m_spData->m_strC0;
                kQuery.m_nObject = 1;
                kQuery.SetActor(FUN_14123c580());
                FUN_1403ed280()->FUN_1411a4a00(&kQuery);
            }
            FUN_141676b50(1);
            bool bSpawn = true;
            if (m_nRunFx2)
            {
                ATL::CAtlArray<efd::SmartPointer<CEffect> > kLive;
                FUN_1403ed280()->FUN_1411a7760(m_nRunFx2, kLive);
                bSpawn = kLive.GetCount() == 0;
                if (bSpawn)
                    m_nRunFx2 = 0;
            }
            if (bSpawn)
            {
                Unk_EffectQuery kQuery;
                kQuery.m_strName = m_spData->m_strD8;
                kQuery.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(this);
                kQuery.SetActor(FUN_14123c580());
                m_nRunFx2 = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
            }
        }
    }
    else
    {
        FUN_141676b50(0);
        unsigned int nInterval = 5000;
        if (FUN_140869420() - m_nD44 > nInterval)
        {
            m_nD44 = FUN_140869420();
            FUN_141275260(0x48, 1, 0);
            FUN_141276180(s_strNoticeEp, CString(""));
        }
    }
}

// @0x1417060d0
bool Ridee::FUN_1417060d0()
{
    if (m_spData->m_nA0 == 0)
        return true;
    int nNow = FUN_141472bc0();
    if ((unsigned int)(nNow - m_nD40) <= 1000)
        return true;
    if (m_pRider->FUN_141670a00(10) >= m_spData->m_nA0)
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
    m_posBF4 = FUN_1409478c0()->FUN_140af8290();
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
// MS2-FUNCTIONAL: the exe evaluates the rider class test inline per call
void Ridee::vfunc_49()
{
    Unk_RideeShadowMgr* pMgr = FUN_140ae1c00();
    unsigned int nClassId = m_pRider->GetClassID();
    int a = pMgr->FUN_141376880(nClassId != 0x6200004);
    int b = pMgr->FUN_1413769d0(nClassId != 0x6200004);
    m_spShadow = NiNew CObjectShadow(this, a, b, m_spData->m_f120, 1.0f);
    FUN_14123cb20(m_bUnkB8);
}

// @0x141706490
float Ridee::vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut)
{
    return m_pRider->vfunc_115(a, b, c, d, nFlag, pOut);
}
MS2_REPLACE_METHOD(0x141706490, Ridee, vfunc_115, 116, 0x6486A19D);

// @0x141706510
void Ridee::FUN_141706510(PCBase* pRider)
{
    m_pRider = pRider;
}
MS2_REPLACE_METHOD(0x141706510, Ridee, FUN_141706510, 28, 0x3CB6144A);

// @0x141706540
PCBase* Ridee::FUN_141706540()
{
    return m_pRider;
}
MS2_REPLACE_METHOD(0x141706540, Ridee, FUN_141706540, 18, 0xB14E6424);

// @0x141706560
NiNode* Ridee::FUN_141706560()
{
    return m_spD58;
}
MS2_REPLACE_METHOD(0x141706560, Ridee, FUN_141706560, 33, 0x91641508);

// @0x141706590
void Ridee::FUN_141706590()
{
    m_controller.FUN_1417b76b0(FUN_14086d260()->FUN_141473230());
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
// MS2-FUNCTIONAL: stack layout of the record/entity temporaries differs
void Ridee::FUN_141706650(bool bForce)
{
    if (!FUN_14166c930())
        return;
    m_controller.FUN_1417b76b0(FUN_14086d260()->FUN_141473230());
    if (m_controller.FUN_1417b7490())
        m_controller.vfunc_0();
    if (m_nDE0 == 0)
    {
        NiPoint3 kPos = vfunc_18();
        if (kPos.z < FUN_1403ed2d0()->FUN_141bd37e0().z)
        {
            m_nDE0 = 1;
            bForce = true;
        }
    }

    bool bSend = false;
    MS2Ptr<Unk_StateArg22> spCur = m_controller.FUN_1417b7620();
    if (bForce || m_bDF8 || spCur == 0 || spCur->m_vel3c != m_pos98 || spCur->m_nState != FUN_14166c930()
        || FUN_14166ccb0()->vfunc_22(spCur))
        bSend = true;
    if (!bSend)
        return;

    m_bDF8 = false;
    int bFlushAfter = 0;
    if (spCur.get())
    {
        if (spCur->m_nState == 2 && m_spStateMgr->FUN_1417db270() != 2)
            bFlushAfter = 1;
        else
            m_controller.vfunc_0();
    }

    MS2Ptr<Unk_StateArg22> spNew = FUN_140835450(FUN_14166c930());
    spNew->m_nSub = FUN_14166cc80();
    spNew->m_vel3c = m_pos98;
    spNew->m_pos20 = vfunc_18();
    spNew->m_dir2c = vfunc_20();
    spNew->m_f58 = FUN_14166da40();
    spNew->m_pos48 = m_posBF4;
    spNew->m_n54 = FUN_1409478c0()->FUN_140af7e30();
    spNew->m_nAC = FUN_14086d260()->FUN_141473390();
    if (State* pState = FUN_14166ccb0())
        pState->vfunc_26((Unk_StateDataArg*)spNew.get());

    if (m_unk_ae0 != s_kNoEntity)
    {
        if (Unk_RideeEntity* pEntity = FUN_1409670f0()->FUN_1411cf440(m_unk_ae0))
        {
            efd::utf8string strModel;
            pEntity->FUN_140ae1be0()->FUN_140ae1f60(strModel);
            CString strName(strModel.c_str());
            FUN_1401d3700(strName);
            bool bFound = FUN_1403ed2d0()->FUN_141bc4e70(strName).get() != 0;
            if (bFound)
            {
                NiPoint3 kObjPos;
                pEntity->FUN_1409618c0(0xfd95ca52, kObjPos);
                spNew->m_str88 = strName;
                spNew->m_pos78 = vfunc_18() - kObjPos;
            }
            if (pEntity->FUN_1408a9bd0()->ContainsModel(0xd8dea70d))
            {
                bool bRideable = false;
                int nKind = 0;
                pEntity->FUN_1408a20a0(0xecfdd742, &bRideable);
                pEntity->FUN_140ae1160(0xada5c5d2, &nKind);
                if (bRideable && (nKind == 9 || nKind == 8))
                {
                    NiPoint3 kPropPos;
                    pEntity->FUN_1409618c0(0xfd95ca52, kPropPos);
                    efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
                    if (spService->FUN_1410b8ab0(kPropPos) && vfunc_99(0) == 0)
                    {
                        if (FUN_1409f7ca0()->FUN_14168a9b0(pEntity, vfunc_18()))
                            spNew->m_nA0 = FUN_1408a13d0(kPropPos);
                    }
                }
            }
        }
    }
    m_controller.FUN_1417b7670(spNew.get());
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
    return m_spData->m_nNameId;
}
MS2_REPLACE_METHOD(0x141707070, Ridee, vfunc_69, 36, 0x619CC090);

// @0x1417070a0
float Ridee::FUN_1417070a0()
{
    float fSpeed = m_spData->m_f80;
    if (!m_pRider)
        return fSpeed;
    Unk_RideePC* pc = FUN_140974230(m_pRider);
    if (!pc)
        return fSpeed;
    if (FUN_14028d470(m_spData->m_f7c, m_spData->m_f80))
        return FUN_1411f0e30(fSpeed, 1.0f + FUN_1411e1110(FUN_1416561a0(pc), 0xae));
    return FUN_1411f0e30(fSpeed, 1.0f + FUN_1411e1110(FUN_1416561a0(pc), 0xa5));
}
MS2_REPLACE_METHOD(0x1417070a0, Ridee, FUN_1417070a0, 291, 0x5C3B4FBE);

// @0x1417071d0
// MS2-FUNCTIONAL: PCBase::m_unk_180 is an array here; the exe reads a named float field
float Ridee::FUN_1417071d0()
{
    float fSpeed = m_unk_180[2];
    if (!m_pRider)
        return fSpeed;
    Unk_RideePC* pc = FUN_140974230(m_pRider);
    if (!pc)
        return fSpeed;
    return FUN_1411f0e30(fSpeed, 1.0f + FUN_1411e1110(FUN_1416561a0(pc), 0xae));
}
MS2_REPLACE_METHOD(0x1417071d0, Ridee, FUN_1417071d0, 146, 0x045C94C9);

// @0x141707270
void Ridee::FUN_141707270()
{
    m_controller.FUN_1417b7450();
    m_nDE0 = 0;
}
MS2_REPLACE_METHOD(0x141707270, Ridee, FUN_141707270, 48, 0x05F57870);

// @0x1417072b0
// MS2-FUNCTIONAL: branch layout of the texture-exists test differs
void Ridee::FUN_1417072b0()
{
    MS2Ptr<Unk_PCBaseComp_b18> spItem = FUN_141707440();
    if (spItem == 0)
        return;
    if (FUN_140897300(spItem.operator->()) == 0)
        return;
    CString strPath = FUN_1410280d0(7, spItem->m_strUrl);
    if (_access(strPath, 4) == 0)
        FUN_14052d220()->FUN_141887810(this);
    else
        FUN_14052d220()->FUN_141884830(spItem, FUN_14123c460());
}
MS2_REPLACE_METHOD(0x1417072b0, Ridee, FUN_1417072b0, 393, 0x60E382B1);

// @0x141707440
MS2Ptr<Unk_PCBaseComp_b18> Ridee::FUN_141707440()
{
    if (!FUN_141706540())
        return MS2Ptr<Unk_PCBaseComp_b18>(0);
    return FUN_141706540()->FUN_141676930();
}
MS2_REPLACE_METHOD(0x141707440, Ridee, FUN_141707440, 111, 0x7A3B4502);

// @0x1417074c0
void Ridee::FUN_1417074c0()
{
    if (!m_pRider)
        return;
    MS2Ptr<Unk_RideeData> spData = FUN_1407844b0(m_pRider->FUN_141676410());
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
    Unk_RideePC* pc = FUN_140974230(m_pRider);
    if (!pc)
        return 0;
    if (FUN_141707750()->m_nType == 1 || FUN_141707750()->m_nType == 2)
        return 1;
    if (pc->FUN_1416749a0()->FUN_1409701d0(3))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1417075e0, Ridee, FUN_1417075e0, 354, 0x578429A8);

// @0x141707750
MS2Ptr<Unk_RideeData> Ridee::FUN_141707750()
{
    return m_spData;
}
MS2_REPLACE_METHOD(0x141707750, Ridee, FUN_141707750, 67, 0x6F354F30);

// @0x1417077a0
MS2Ptr<Unk_PCBaseComp_a58> Ridee::vfunc_80()
{
    if (FUN_1409f7c90()->FUN_1409f7ea0() && FUN_14123dbd0() == 0)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (!FUN_1409a8b10()->FUN_140b123b0()->m_bShowHpBar)
        return MS2Ptr<Unk_PCBaseComp_a58>(0);
    if (m_spA58 == 0)
        m_spA58 = FUN_141992920(m_unk_70);
    return m_spA58;
}
MS2_REPLACE_METHOD(0x1417077a0, Ridee, vfunc_80, 290, 0xFB08F93E);

// @0x1417078d0
float Ridee::vfunc_89()
{
    if (m_spData.get())
        return m_spData->FUN_140784970()->m_f60;
    return 0;
}
MS2_REPLACE_METHOD(0x1417078d0, Ridee, vfunc_89, 136, 0x27AA4A41);

// @0x141707960
float Ridee::FUN_141707960()
{
    if (m_spData.get())
        return m_spData->FUN_140784970()->m_f64;
    return 0;
}
MS2_REPLACE_METHOD(0x141707960, Ridee, FUN_141707960, 136, 0x6FC70E00);

// @0x1417079f0
// MS2-FUNCTIONAL: stack layout of the PhysX pose temporaries differs
void Ridee::vfunc_53(float f)
{
    PCBase::vfunc_53(f);
    FUN_141678360();
    bool bVisible = !(m_timer970.FUN_140868c00() == 0 && m_timer970.FUN_140868ba0() != 0);
    if (bVisible)
        m_timer970.FUN_140868750(200);
    vfunc_93(bVisible);
    if (m_spShadow && m_spShadow->FUN_141534300())
    {
        if (NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410()))
            pRoot->UpdateEffects();
    }
    if (DAT_143ae2b30 == 0 && m_pRider)
    {
        m_pRider->vfunc_19(vfunc_18());
        m_pRider->vfunc_21(vfunc_20());
    }
    if (m_pBox && m_spData.get())
    {
        NiPoint3 kPos = vfunc_18();
        NiPoint3 kRot = vfunc_20();
        efd::Point3 kHalf(m_spData->m_f108, m_spData->m_f110, m_spData->m_f10c);
        kHalf = kHalf * 0.01f * 0.5f;
        NxMat34 kPose(true);
        kPose.t = NxVec3(kPos.x, kPos.y, kPos.z);
        kPose.t = kPose.t * 0.01f;
        kPose.t.z += kHalf.z + 0.2f;
        kPose.M.rotZ(kRot.z * 3.1415927f / 180.0f);
        FUN_1409f7ca0()->FUN_14168a540(0);
        m_pBox->setGlobalPose(kPose);
        FUN_1409f7ca0()->FUN_14168a570();
    }
}
MS2_REPLACE_METHOD(0x1417079f0, Ridee, vfunc_53, 1128, 0x01E9F3D0);

// @0x141707e60
// MS2-FUNCTIONAL: stack layout of the PhysX descriptors differs
void Ridee::MakeNxBoxController()
{
    if (m_spData == 0 || !m_spData->m_b114 || m_pBox)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (!pScene)
        return;

    NiPoint3 kPos = vfunc_18();
    NiPoint3 kRot = vfunc_20();
    efd::Point3 kSize(m_spData->m_f108, m_spData->m_f110, m_spData->m_f10c);
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
    kActorDesc.globalPose.t.z += kBoxDesc.dimensions.z + 0.2f;
    kActorDesc.globalPose.M.rotZ(kRot.z * 3.1415927f / 180.0f);
    FUN_1409f7ca0()->FUN_14168a540(0);
    m_pBox = pScene->createActor(kActorDesc);
    if (m_pBox)
    {
        m_pBox->setName("Ridee::MakeNxBoxController");
        NxU32 nShapes = m_pBox->getNbShapes();
        NxShape* const* ppShapes = m_pBox->getShapes();
        for (NxU32 i = 0; i < nShapes; i++)
            ppShapes[i]->setGroup(0);
    }
    FUN_1409f7ca0()->FUN_14168a570();
}

// @0x1417082c0
void Ridee::FUN_1417082c0()
{
    if (m_spData == 0)
        return;
    if (!m_spData->m_b114)
        return;
    NxScene* pScene = FUN_1409f7ca0()->FUN_14168a1c0();
    if (!pScene)
        return;
    if (m_pBox)
    {
        FUN_1409f7ca0()->FUN_14168a540(0);
        pScene->releaseActor(*m_pBox);
        FUN_1403ed2d0()->FUN_141bc8e00();
        FUN_1409f7ca0()->FUN_14168a570();
        m_pBox = 0;
    }
}
MS2_REPLACE_METHOD(0x1417082c0, Ridee, FUN_1417082c0, 210, 0xF313323A);

// @0x1417083a0
// MS2-FUNCTIONAL: NiTransform/NiMatrix3/Point3 math written with the Gamebryo operators (the exe calls its COMDATs)
void Ridee::FUN_1417083a0(PCBase* pRider, efd::SmartPointer<NiAVObject> spSeat, MS2Ptr<Unk_RideeModel> spModel)
{
    if (!pRider || spSeat == 0 || spModel == 0)
        return;
    efd::SmartPointer<NiNode> spSeatNode(NiDynamicCast(NiNode, (NiAVObject*)spSeat));
    NiAVObject* pRiderRoot = FUN_141b6ef70(pRider->FUN_14123c460());
    if (!spSeatNode || !pRiderRoot)
        return;

    NiTransform kWorld = spSeatNode->GetWorldTransform();
    NiTransform kParent;
    kParent.MakeIdentity();
    if (spSeatNode->GetParent())
        kParent = spSeatNode->GetParent()->GetWorldTransform();
    kWorld = kParent * kWorld;
    NiPoint3 kPos = kWorld.m_Translate;
    NiMatrix3 kRotate = kWorld.m_Rotate;

    NiPoint3 kAngles;
    efd::Point3 kSeatRot(spModel->m_fRotX, spModel->m_fRotY, spModel->m_fRotZ);
    NiMatrix3 kSeatMatrix;
    FUN_140b86230(kSeatRot, kSeatMatrix);
    kRotate = kRotate * kSeatMatrix;
    FUN_140a0b1f0(kRotate, kAngles);

    NiPoint3 kX, kY, kZ;
    kRotate.GetCol(0, kX);
    kX.Unitize();
    kRotate.GetCol(1, kY);
    kY.Unitize();
    kRotate.GetCol(2, kZ);
    kZ.Unitize();
    kPos += kY * -spModel->m_fY;
    kPos += kX * spModel->m_fX;
    kPos += kZ * spModel->m_fZ;
    pRider->vfunc_19(kPos);
    pRider->vfunc_21(kAngles);
}

// @0x141708950
StateRideeController::StateRideeController()
{
}

// ??_G 0x141708a30, GetClassDesc 0x141708af0, the class info setup 0x1417090c0 and TypeCast 0x141709280/0x1417092d0
// come from EE_DECLARE_CLASS1 / EE_IMPLEMENT_CONCRETE_CLASS_INFO.

