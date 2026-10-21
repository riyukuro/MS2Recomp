// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The skill "magic" projectiles: CMagicData (one <move> of
// data/xml/table/magicPath.xml), CMagic (a running projectile), CMagicModel, CArrowFillTargetContext and CMagicService.
// Names of members are invented from the XML attribute names the loader reads.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include <efd/ISystemService.h>

class Unk_140165cf0;    // game TinyXML element
CPtred* FUN_1404efd80(CPtred* pThis, const CPtred* pOther);      // the exe's CPtred assignment (ICF-folded `return this`)

// One <move> element of magicPath.xml (0xc0 bytes, RTTI base CPtred).
class CMagicData : public CPtred
{
public:
    CMagicData();                                                   // 0x14145bd70
    virtual ~CMagicData() = default;                                // 0 0x141468d80
    // A position between the two control points (random fractions per axis).
    Unk_StreamPoint FUN_14145c030(void* pRandom);                   // 0x14145c030
    CMagicData& operator=(const CMagicData& kOther);                // 0x141468f10 (the implicit copy assignment)
    bool FUN_14145c180();                                           // 0x14145c180 any control point is not the zero point

    Unk_StreamPoint m_ptFireOffset;                                 // +0x18 fireOffsetPosition
    Unk_StreamPoint m_ptFireFixed;                                  // +0x24 fireFixedPosition
    CString m_strFireNode;                                          // +0x30 fireNode
    int m_nRotation;                                                // +0x38 rotation
    float m_fLifeTime;                                              // +0x3c lifeTime
    float m_fDelayTime;                                             // +0x40 delayTime
    float m_fSpawnTime;                                             // +0x44 spawnTime
    Unk_StreamPoint m_ptDirection;                                  // +0x48 direction
    float m_fDirRotZ;                                               // +0x54 dirRotZDegree
    float m_fVelocity;                                              // +0x58 vel
    float m_fDistance;                                              // +0x5c distance
    float m_fSpeed;                                                 // +0x60 distance / vel
    float m_fNonTargetMoveDistance;                                 // +0x64 nonTargetMoveDistance
    float m_fTraceTargetDuration;                                   // +0x68 traceTargetDuration
    float m_fDestroyTime;                                           // +0x6c destroyTime
    Unk_StreamPoint m_ptControl[2];                                 // +0x70 controlValue0 / controlValue1
    float m_fControlRate;                                           // +0x88 controlRate
    Unk_StreamPoint m_ptControlEnd;                                 // +0x8c controlEndOffsetValue
    int m_nCatmullRom;                                              // +0x98 catmullrom
    unsigned m_nMoveEndHoldDuration;                                // +0x9c moveEndHoldDuration
    int m_nExplosionByDestroy;                                      // +0xa0 explosionByDestroy
    unsigned m_nPiercingAttackInterval;                             // +0xa4 piercingAttackInterval
    unsigned char m_nPiercingAttackMaxTargetCount;                  // +0xa8 piercingAttackMaxTargetCount
    int m_nLookAtType;                                              // +0xac lookAtType
    int m_nIgnoreCancelAtSpawnTime;                                 // +0xb0 ignoreCancelAtSpawnTime
    int m_nIgnorePhysxTestInitPosition;                             // +0xb4 ignorePhysxTestInitPosition
    int m_nTraceTargetOffsetPos;                                    // +0xb8 traceTargetOffsetPos
};
MS2_CHECK_SIZE(CMagicData, 0xc0);

// The <type> element of magicPath.xml: the <move> records of one magic id, boxed so the id table can share it. The exe's
// RTTI calls the element pointer TPtr<CMagicData> and the box TPtredDummy<CAtlArray<TPtr<CMagicData>>>.
typedef ATL::CAtlArray<Unk_SocketPtr<CMagicData> > Unk_MagicList;
template<> struct Unk_SocketRef<Unk_MagicList> {
    static CPtred* Base(Unk_MagicList* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_MagicList>, value);
        return result;
    }
    static TPtredDummy<Unk_MagicList>* New(void*) { return new TPtredDummy<Unk_MagicList>(); }
    static Unk_MagicList* Value(CPtred* p) {
        Unk_MagicList* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_MagicList>*>(p)->value;
        return result;
    }
    static Unk_MagicList* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_MagicList)
typedef Unk_SocketPtr<Unk_MagicList> Unk_MagicListPtr;
MS2_CHECK_SIZE(TPtredDummy<Unk_MagicList>, 0x38);
MS2_CHECK_OFFSET(TPtredDummy<Unk_MagicList>, value, 0x18);

// The magicPath.xml table (cached; reloaded when the file changes on disk).
Unk_MagicListPtr FUN_14145c250(unsigned nMagicId);                  // 0x14145c250 all moves of one id
Unk_SocketPtr<CMagicData> FUN_14145c300(unsigned nMagicId, int nIndex); // 0x14145c300 one move, index wraps
int FUN_14145c4d0();                                                // 0x14145c4d0 loads ./data/xml/table/magicPath.xml

// ---- the running projectile ----
struct Unk_MagicTag;
struct Unk_MagicXform;
struct Unk_MagicEntity;
struct Unk_MagicSkillRow;
// 16 byte smart pointers shared with the cube/world code (out-of-line members bound by VA in symbols-manual.tsv).
struct Unk_MagicTagPtr {
    Unk_MagicTagPtr();                                              // 0x141234900
    Unk_MagicTagPtr(int);                                           // 0x1410a6af0
    Unk_MagicTagPtr(const Unk_MagicTagPtr&);                        // 0x1412348c0
    ~Unk_MagicTagPtr();                                             // 0x1410a6d40
    Unk_MagicTagPtr& operator=(const Unk_MagicTagPtr&);             // 0x141235040
    Unk_MagicTag* operator->() const;                               // 0x141235260
    Unk_MagicTagPtr(Unk_MagicTag* p);                               // 0x1410a6b10 (scenestategame 0x3d)
    Unk_MagicTag* get() const;                                      // 0x1410a7150 (scenestategame 0x3d)
    void* m_pad;
    Unk_MagicTag* m_p;
};
MS2_CHECK_SIZE(Unk_MagicTagPtr, 0x10);
struct Unk_MagicValPtr {
    Unk_MagicValPtr() : m_p(0) {}                                   // 0x1414687c0 (inline)
    Unk_MagicValPtr(int);                                           // 0x141234840
    Unk_MagicValPtr(const Unk_MagicValPtr&);                        // 0x141234800
    ~Unk_MagicValPtr();                                             // 0x141234e70
    Unk_MagicValPtr& operator=(const Unk_MagicValPtr&);             // 0x141235000
    void* m_pad;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_MagicValPtr, 0x10);

// Element types of the 8 byte pointer arrays (distinct instantiations in the exe, so distinct types; names invented).
struct Unk_MagicNodeLink;
struct Unk_MagicTargetRef;
struct Unk_MagicArrowRef;

// One of the 16 effect slots of a CMagic: the ids spawned for it and the live effect handle.
struct Unk_MagicSlot {
    Unk_MagicSlot();                                                // 0x141468b30
    ~Unk_MagicSlot();                                               // 0x141468e40
    ATL::CAtlArray<Unk_MagicNodeLink*> m_ids;
    int m_nEffect;
};
MS2_CHECK_SIZE(Unk_MagicSlot, 0x28);

// An id -> id hash map whose members live out of line in the exe (additionalactionadditional.cpp); 0x48 bytes.
class Unk_MagicUIntMap {
public:
    Unk_MagicUIntMap(unsigned nBins, float fOptimalLoad, float fLowThreshold, float fHighThreshold, unsigned nBlockSize);  // 0x140181eb0
    ~Unk_MagicUIntMap();                                            // 0x1401835e0
private:
    void* m_raw[9];
};
MS2_CHECK_SIZE(Unk_MagicUIntMap, 0x48);

class CMagic : public CPtred
{
public:
    CMagic();                                                       // 0x14145d120
    virtual ~CMagic();                                              // 0 0x14145d390

    // Start the projectile: bind the skill and caster records, copy the move data, build the scene root and prime the effects.
    int FUN_14145d5d0(Unk_MagicTagPtr spSkill, Unk_MagicTagPtr spCaster, const CMagicData* pData,
        Unk_StreamPoint ptStart, unsigned n530, unsigned n534, unsigned n53c);   // 0x14145d5d0
    void FUN_14145d9d0();                                           // 0x14145d9d0 flight time and the random landing point
    void FUN_14145ddd0(const Unk_StreamPoint& ptStart);             // 0x14145ddd0 restart from a new start point
    void FUN_14145de80();                                           // 0x14145de80 per-frame state machine
    void FUN_14145e960(unsigned nNow);                              // 0x14145e960 spawn the main effect
    void FUN_141460640(unsigned nNow);                              // 0x141460640 release every spawned effect (nNow unused)
    void FUN_141460700(unsigned nNow);                              // 0x141460700 restart the flight from the current point
    void FUN_141461140();                                           // 0x141461140 pick the target point
    void FUN_141461a80(Unk_StreamPoint ptNew);                      // 0x141461a80 move the projectile and its scene root
    void FUN_141461b60(const Unk_StreamPoint& ptDirection);         // 0x141461b60 set the direction and rotate
    void FUN_141461ba0(const Unk_NiMatrix3& matRotation);           // 0x141461ba0 set the rotation matrix
    void FUN_141463fb0(unsigned nNow);                              // 0x141463fb0 end-of-flight transitions
    void FUN_141464160();                                           // 0x141464160 show/hide the scene root by distance
    bool FUN_141464220();                                           // 0x141464220 is the projectile out of the visible range
    Unk_MagicEntity* FUN_141464360();                               // 0x141464360 the target entity
    bool FUN_141464410();                                           // 0x141464410 the caster's lock-on entity
    int FUN_141464490();                                            // 0x141464490 has an attacker record
    void FUN_1414644d0(int bHide);                                  // 0x1414644d0 show or hide the scene root
    Unk_StreamPoint FUN_141464520();                                // 0x141464520 rotation matrix column 0
    Unk_StreamPoint FUN_141464580();                                // 0x141464580 rotation matrix column 1
    Unk_StreamPoint FUN_1414645e0();                                // 0x1414645e0 rotation matrix column 2
    float FUN_141464640();                                          // 0x141464640 move-end hold duration
    int FUN_141464670();                                            // 0x141464670 total duration in ms
    unsigned FUN_141467440();                                       // 0x141467440 the current time for this skill
    int FUN_141467420();                                            // 0x141467420 the state

    void FUN_141462900(unsigned nNow);                              // 0x141462900
    void FUN_141461bd0(unsigned nNow);
    void FUN_141464d00(unsigned nNow, const Unk_MagicSkillRow* pRow);   // 0x141464d00
    void FUN_141465b30(unsigned nNow, const Unk_MagicSkillRow* pRow);   // 0x141465b30                              // 0x141461bd0
    void FUN_141462490(unsigned nNow);                              // 0x141462490
    int FUN_141467100(Unk_MagicEntity* pEntity, Unk_StreamPoint* pOut);   // 0x141467100 nearest hit point of the target
    void FUN_141463960();                                           // 0x141463960
    void FUN_14145f570(unsigned nNow);                              // 0x14145f570 begin the destroy phase
    void FUN_14145ec50(unsigned nNow);                              // 0x14145ec50 per-frame update while alive
    void FUN_1414609e0();                                           // 0x1414609e0
    void FUN_141464790(void* pHits, int nHits);                      // 0x141464790 play the hit effect on every hit entity
    void FUN_141464b40();                                           // 0x141464b40
    void FUN_141466da0(unsigned nNow, const Unk_MagicSkillRow* pRow);  // 0x141466da0 piercing hit tick
    void FUN_141461720(int nFlag);                                  // 0x141461720
    void FUN_1414614d0();                                           // 0x1414614d0
    void FUN_1414607e0();                                           // 0x1414607e0

    int m_nState;                                                   // +0x18
    unsigned m_nStateTick;                                          // +0x1c
    Unk_MagicTagPtr m_spSkill;                                      // +0x20
    Unk_MagicTagPtr m_spCaster;                                     // +0x30
    Unk_StreamPoint m_ptStart;                                      // +0x40
    Unk_StreamPoint m_ptTarget;                                     // +0x4c
    Unk_StreamPoint m_ptCurrent;                                    // +0x58
    Unk_StreamPoint m_ptDirection;                                  // +0x64
    Unk_StreamPoint m_ptLast;                                       // +0x70
    Unk_StreamPoint m_ptPredicted;                                  // +0x7c
    Unk_NiMatrix3 m_matRotation;                                    // +0x88
    Unk_StreamPoint m_ptAc;                                         // +0xac
    Unk_StreamPoint m_ptB8;                                         // +0xb8
    float m_fTotalTime;                                             // +0xc4
    float m_fRemainTime;                                            // +0xc8
    unsigned m_nLastTick;                                           // +0xcc
    int m_nD0;                                                      // +0xd0
    Unk_NodePtr m_spScene;                                          // +0xd8 "Scene Root"
    unsigned m_nEffectId;                                           // +0xe0
    unsigned m_nEffectId2;                                          // +0xe4
    CMagicData m_data;                                              // +0xe8 working copy of the move
    ATL::CAtlArray<Unk_MagicNodeLink*> m_arr1A8;                                 // +0x1a8
    int m_n1C8;
    int m_n1CC;
    int m_n1D0;
    Unk_MagicUIntMap m_map1D8;                                      // +0x1d8
    Unk_MagicUIntMap m_map220;                                      // +0x220
    int m_n268;
    int m_n26C;
    Unk_MagicValPtr m_spVal;                                        // +0x270
    int m_n280;
    int m_n284;
    ATL::CAtlArray<Unk_MagicTargetRef*> m_arr288;                                 // +0x288
    Unk_MagicSlot m_slots[16];                                      // +0x2a8
    int m_n528;
    int m_n52C;
    int m_n530;
    int m_n534;
    int m_n538;
    int m_n53C;
    __int64 m_nCollision;                                           // +0x540 handle of the debug collision shape
};
MS2_CHECK_SIZE(CMagic, 0x548);

class CMagicModel : public CPtred
{
public:
    CMagicModel();                                                  // 0x141467480
    virtual ~CMagicModel() = default;                               // 0 0x141468db0
    int FUN_141467b30();                                            // 0x141467b30 the model's own duration
    int FUN_141467a90();                                            // 0x141467a90 state > 2
    int FUN_141467ae0();                                            // 0x141467ae0 state == 4
    Unk_MagicTagPtr FUN_141467bc0();                                // 0x141467bc0 copy of the cast record handle
    unsigned long long FUN_141467b60();                             // 0x141467b60 the tag's sub id
    Unk_StreamPoint FUN_141467c10();                                // 0x141467c10 projectile position
    Unk_StreamPoint FUN_141467c60();                                // 0x141467c60 projectile direction
    Unk_NiMatrix3 FUN_141467cb0();                                  // 0x141467cb0 projectile rotation
    void FUN_141467d00(Unk_StreamPoint ptNew);                      // 0x141467d00 move the projectile
    void FUN_141467d50(Unk_StreamPoint ptDirection);                // 0x141467d50 turn the projectile
    void FUN_141467ed0();                                           // 0x141467ed0 begin the destroy phase of an orphaned model
    void FUN_141467da0();                                           // 0x141467da0
    void FUN_141467800();                                           // 0x141467800
    int FUN_141467dd0(unsigned long long nTag);                     // 0x141467dd0 can this cast be cancelled
    CMagic* FUN_141467b90();                                        // 0x141467b90 the projectile
    void FUN_141467860();                                           // 0x141467860 per-tick update
    void FUN_141467500(Unk_MagicTagPtr spSkill, Unk_MagicTagPtr spCaster, Unk_StreamPoint ptStart,
        unsigned n530, unsigned n534, unsigned n53c);                // 0x141467500 start a projectile for a cast

    Unk_SocketPtr<CMagic> m_spMagic;                                // +0x18
    Unk_MagicTagPtr m_spA;                                          // +0x28
    Unk_MagicTagPtr m_spB;                                          // +0x38
};
MS2_CHECK_SIZE(CMagicModel, 0x48);

class CArrowFillTargetContext : public CPtred
{
public:
    CArrowFillTargetContext();                                      // 0x1414689b0
    virtual ~CArrowFillTargetContext() = default;                   // 0 0x141468d30

    Unk_MagicTagPtr m_spOwner;                                      // +0x18
    void* m_p28;
    ATL::CAtlArray<Unk_MagicArrowRef*> m_arr30;
    Unk_StreamPoint m_ptFrom;                                       // +0x50
    Unk_StreamPoint m_ptTo;                                         // +0x5c
    Unk_NiMatrix3 m_matAim;                                         // +0x68
    int m_n8C;
    Unk_MagicValPtr m_spVal;                                        // +0x90
    int m_nA0;
    int m_nA4;
};
MS2_CHECK_SIZE(CArrowFillTargetContext, 0xa8);

// ---- the service ----
// The running projectiles of the field, boxed so the tables can share them: caster id -> (skill id -> CMagicModel).
typedef ATL::CRBMap<unsigned long long, Unk_SocketPtr<CMagicModel> > Unk_MagicModelMap;
template<> struct Unk_SocketRef<Unk_MagicModelMap> {
    static CPtred* Base(Unk_MagicModelMap* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_MagicModelMap>, value);
        return result;
    }
    static TPtredDummy<Unk_MagicModelMap>* New(void*) { return new TPtredDummy<Unk_MagicModelMap>(); }
    static Unk_MagicModelMap* Value(CPtred* p) {
        Unk_MagicModelMap* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_MagicModelMap>*>(p)->value;
        return result;
    }
    static Unk_MagicModelMap* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_MagicModelMap)
typedef Unk_SocketPtr<Unk_MagicModelMap> Unk_MagicModelMapPtr;
MS2_CHECK_SIZE(TPtredDummy<Unk_MagicModelMap>, 0x48);
MS2_CHECK_OFFSET(TPtredDummy<Unk_MagicModelMap>, value, 0x18);

class CMagicService;
template <class T> class TSingleton;
template <> class TSingleton<CMagicService>
{
public:
    TSingleton();                                   // 0x14146d630 (inline, in the .cpp)
    virtual ~TSingleton() { s_instance = 0; }       // 0x14146d9c0
    static CMagicService* s_instance;               // 0x143acf618
};

// The efd system service (class id 0x06100010) that owns every running projectile.
class CMagicService : public efd::ISystemService, public TSingleton<CMagicService>
{
    EE_DECLARE_CLASS1(CMagicService, 0x06100010, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CMagicService();                                // 0x14146b2e0
    virtual ~CMagicService();                       // 0x14146b3b0
    virtual const char* GetDisplayName() const;     // 0x14146b420
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x14146cee0
    virtual efd::AsyncResult OnInit();              // 0x14146cf00
    virtual efd::AsyncResult OnTick();              // 0x14146cf20
    virtual efd::AsyncResult OnShutdown();          // 0x14146d0b0

    // Members below are the table accessors (names invented): casts are keyed by (caster id, cast id).
    void FUN_14146c4b0(unsigned long long nCaster, unsigned long long nCast);       // 0x14146c4b0 drop one model
    Unk_SocketPtr<CMagicModel> FUN_14146c5d0(unsigned long long nCaster, unsigned long long nCast);  // 0x14146c5d0 find one model
    void FUN_14146c6c0(unsigned long long nCaster, int bForce, int bDestroy);        // 0x14146c6c0 cancel the casts of a caster
    Unk_MagicModelMapPtr FUN_14146c910(unsigned long long nCaster);                // 0x14146c910 all models of a caster
    int FUN_14146cbd0(Unk_SocketPtr<CMagicModel> spModel);                         // 0x14146cbd0 register a model
    void FUN_14146cd10(Unk_SocketPtr<CMagicModel> spModel);                        // 0x14146cd10 unregister a model
    Unk_SocketPtr<Unk_MagicTag> FUN_14146ce30(unsigned long long nCast);          // 0x14146ce30 find a cast record
    void FUN_14146ceb0(unsigned long long nCast);                                  // 0x14146ceb0 forget a cast record
    std::pair<bool, bool> FUN_14146c990(int* pKey, Unk_NiPoint3* pPoint, unsigned nOwner, Unk_MagicEntity* pCaster, int* pType);   // 0x14146c990 may the cast and end effects of a hit play
    void FUN_14146bc20(Unk_MagicTag* pTag);          // 0x14146bc20 the cast animation of a cast record
    void FUN_14146bc80(Unk_MagicTag* pTag);          // 0x14146bc80 play the end of a cast record
    void FUN_14146b440(Unk_MagicTag* pTag, int bTracked, Unk_MagicXform* pXform, Unk_StreamPoint ptDirection);   // 0x14146b440 play the hit of a cast record

    ATL::CRBMap<unsigned long long, Unk_SocketPtr<Unk_MagicTag> > m_mapCasts;     // +0x28 cast id -> cast record
    ATL::CAtlMap<unsigned long long, Unk_MagicModelMapPtr> m_mapModels;            // +0x58 caster id -> (cast id -> model)
};
