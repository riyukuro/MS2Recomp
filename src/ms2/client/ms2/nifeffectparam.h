// nifeffectparam.h - the "Nif" effect (effect XML type 1): plays a .nif model as an effect, optionally attached to a
// node/bone of the target. CNifEffectParam (param, CEffectParam), CNifEffect (runtime effect, CEffect),
// DuplicatedAlphaController (alpha controller clone used to fade a nif out) and the nif cache/loader service
// CNifLoadingService + CNiStreamLoadThread. Owning unit: ?\nifeffectparam.cpp (0x141548790-0x141562ee0, .text$di
// 0x1400fa2f0). Header name assumed from the unit path. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiNode.h>
#include <NiAlphaController.h>
#include <NiTransform.h>
#include <NiRTTI.h>
#include <NiSmartPointer.h>

#include <NiTexturePalette.h>
#include <NiSourceTexture.h>
#include <NiPixelData.h>
#include <map>
#include <vector>
#include <efd/ISystemService.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"                      // TSingleton<T>
#include "ms2/placeholder/cthread_startup.h"        // CThread, Unk_140659080
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/unnamed/unit_140ad1860.h"           // Unk_McTimer
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/lighteffectparam.h"        // Unk_LightUpdateBits (bitset<3>)
#include "ms2/placeholder/ascript.h"                // MS2Ptr<T>
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"

class CEffectObject;
class CBirdMovement;

// 0x58 bytes (operator delete size in the deleting dtor). A NiAlphaController copied from an existing controller
// (CopyMembers with the clone map target -> target) whose output is scaled by m_fScale. vftable = NiAlphaController's
// 0x? slots with Update replaced; dtor 0x14154f230, ??_G 0x14154f790, GetRTTI 0x14154fa00, RTTI "DuplicatedAlphaController"
// 0x143ae1ef8.
class DuplicatedAlphaController : public NiAlphaController
{
    NiDeclareRTTI;
public:
    explicit DuplicatedAlphaController(NiSingleInterpController* pkSource);        // 0x141548790
    virtual ~DuplicatedAlphaController() = default;                // 0x14154f230
    virtual void Update(float fTime);                                       // 0x141548880
    // @0x141548850
    void SetScale(float fScale) { m_fScale = fScale; }

    float m_fScale;                 // +0x50 multiplies the interpolated alpha
    char m_pad_54[4];
};
MS2_CHECK_SIZE(DuplicatedAlphaController, 0x58);
MS2_CHECK_OFFSET(DuplicatedAlphaController, m_fScale, 0x50);

typedef efd::SmartPointer<DuplicatedAlphaController> DuplicatedAlphaControllerPtr;

// 0xc0 bytes. Overrides vfuncs 1-6. Implicit-style dtor 0x14154f1c0, ??_G 0x14154f750.
class CNifEffectParam : public CEffectParam
{
public:
    CNifEffectParam();                                          // 0x141548990
    virtual ~CNifEffectParam() = default;                       // 0x14154f1c0
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141548b90 parse the <nif> element
    virtual bool vfunc_2();                                     // 2 0x1415491c0 validate
    virtual bool vfunc_3();                                     // 3 0x1415491f0 preload the nif (true when none)
    virtual void vfunc_4();                                     // 4 0x1415492a0 release the nif cache entry
    virtual bool vfunc_5(int n);                                // 5 0x141549340 load the nif into the cache
    virtual CEffectPtr vfunc_6();                               // 6 0x141549430 new CNifEffect
public:
    MS2_LAYOUT_FRIEND;
    CString m_strFilePath;              // +0x48 "filePath" (relative to "Effect")
    Unk_StreamPoint m_ptTranslate;      // +0x50 <transform translate>
    Unk_StreamPoint m_ptRotation;       // +0x5c <transform rotation> (degrees)
    float m_fScale;                     // +0x68 <transform scale> = 1
    bool m_bApplyNodeTransform;         // +0x6c <attachInfo applyNodeTransform>
    bool m_bOnGround;                   // +0x6d <attachInfo onGround>
    bool m_bUseLighting;                // +0x6e <attachInfo useLighting> = true
    bool m_bUseShadow;                  // +0x6f <attachInfo useShadow>
    int m_nAttachType;                  // +0x70 <attachInfo attachType>: 0 none, 1 Node, 2 Mesh, 3 WeaponL, 4 WeaponR
    CString m_strParentNode;            // +0x78 <attachInfo parentNode>
    Unk_LightUpdateBits m_bitsUpdate;   // +0x80 <update translate/rotation/scale>, all set by default
    Unk_LightUpdateBits m_bitsApply;    // +0x81 <applyNodeTransform ...>, set when the element says false
    int m_nMyReferCount;                // +0x84 "myReferCount"
    int m_nOtherReferCount;             // +0x88 "otherReferCount"
    CString m_strLerpType;              // +0x90 <lerp type> ("bird" selects CBirdMovement)
    float m_fMaxLength;                 // +0x98 <lerp MaxLength> = 500
    float m_fMinLength;                 // +0x9c <lerp MinLength> = 1
    float m_fStep;                      // +0xa0 <lerp Step> = 0.01
    float m_fVelocity;                  // +0xa4 <lerp Velocity> = 300
    bool m_bNotForceStop;               // +0xa8 "notForceStop"
    bool m_bOffFadeOut;                 // +0xa9 "offFadeOut"
    float m_fViewDistance;              // +0xac "viewDistance" = -1
    bool m_bBipedLoop;                  // +0xb0 "bipedLoop"
    CString m_strEffectObjectKfm;       // +0xb8 "effectObjectKfmName"
};
MS2_CHECK_SIZE(CNifEffectParam, 0xc0);
MS2_CHECK_OFFSET(CNifEffectParam, m_strFilePath, 0x48);
MS2_CHECK_OFFSET(CNifEffectParam, m_fScale, 0x68);
MS2_CHECK_OFFSET(CNifEffectParam, m_nAttachType, 0x70);
MS2_CHECK_OFFSET(CNifEffectParam, m_strParentNode, 0x78);
MS2_CHECK_OFFSET(CNifEffectParam, m_bitsApply, 0x81);
MS2_CHECK_OFFSET(CNifEffectParam, m_nOtherReferCount, 0x88);
MS2_CHECK_OFFSET(CNifEffectParam, m_strLerpType, 0x90);
MS2_CHECK_OFFSET(CNifEffectParam, m_fVelocity, 0xa4);
MS2_CHECK_OFFSET(CNifEffectParam, m_fViewDistance, 0xac);
MS2_CHECK_OFFSET(CNifEffectParam, m_strEffectObjectKfm, 0xb8);

// CBirdMovement (0x60 bytes, CPtred-based): the bird-like lerp movement of the "bird" lerp type. Constructed by the
// exe (0x1411a3...); only the members this unit sets are named.
class CBirdMovement : public CPtred
{
public:
    CBirdMovement();                                            // out of unit
    void FUN_141207fb0(float f);                                // out of unit (step)
    char m_pad_18[0x38];
    float m_fVelocity;                                          // +0x50 (setter 0x141550030)
    float m_fMaxLength;                                         // +0x54 (setter 0x14154ff50)
    float m_fMinLength;                                         // +0x58 (setter 0x14154ff70)
    char m_pad_5c[4];
    void SetMaxLength(float f) { m_fMaxLength = f; }            // @0x14154ff50
    void SetMinLength(float f) { m_fMinLength = f; }            // @0x14154ff70
    void SetVelocity(float f) { m_fVelocity = f; }              // @0x141550030
};
MS2_CHECK_SIZE(CBirdMovement, 0x60);
MS2_CHECK_OFFSET(CBirdMovement, m_fMinLength, 0x58);

// 0xd8 bytes. vftable 13 slots. dtor 0x141549620, ??_G 0x14154f6f0. RTTI "CNifEffect" 0x143ae1f08.
class CNifEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x14154f9f0
public:
    CNifEffect();                                               // 0x1415494d0
    virtual ~CNifEffect();                                      // 0x141549620
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x1415496f0 build the nif instance
    virtual void vfunc_4();                                     // 4 0x14154acf0 start (re-parent, first update)
    virtual void vfunc_5();                                     // 5 0x14154aef0
    virtual void vfunc_6(float fFadeTime);                      // 6 0x14154af40 fade out
    virtual void vfunc_7();                                     // 7 0x14154b080 detach
    virtual int vfunc_8(void* p);                               // 8 0x14154b160 world position of the root
    virtual bool vfunc_9();                                     // 9 0x14154a7e0 per-update
    virtual void vfunc_10(bool bVisible);                       // 10 0x14154b420
    virtual int vfunc_11();                                     // 11 0x14154b1b0
    virtual int vfunc_12();                                     // 12 0x14154f9d0 effect type 1

    float FUN_14154b470();                                      // duration of the nif animation
    bool FUN_14154b4a0(NiObjectNET* pkNode);                    // swap the alpha controllers for duplicates
    bool FUN_14154b5e0();                                       // fade out allowed (param not "notForceStop")
    void FUN_14154b630(NiObjectNET* pkNode, float fTime);       // add a fade-out controller
    void FUN_14154ba40(Unk_EffectTarget* pTarget);              // attach type 0
    void FUN_14154bdd0(Unk_EffectTarget* pTarget);              // attach type 1
    void FUN_14154c260(Unk_EffectTarget* pTarget);              // attach type 2
    void FUN_14154c440(Unk_EffectTarget* pTarget, int nSlot);   // attach type 3/4
    void FUN_14154c580();                                       // wrap in a SeparateNode / make relative
    void FUN_14154c7f0(Unk_EffectTarget* pTarget);              // log "LOD level"
    void FUN_14154cf20(NiAVObject* pkRoot);                     // apply the "Eff_LOD" level
    Unk_NodePtr FUN_14154d0d0(const CString& strPath, int nA, int nB);     // load the nif
    NiAVObjectPtr FUN_14154d410(Unk_EffectTarget* pTarget, const char* pszName, bool b);

public:
    MS2_LAYOUT_FRIEND;
    bool m_bSplit;                          // +0x30 the model was split off a parent (type 1 after the duration)
    char m_pad_31[7];
    Unk_NodePtr m_spTarget;                 // +0x38 the node the effect hangs on
    NiAVObjectPtr m_spModel;                // +0x40 the attach model/bone object
    NiTransform m_kXform;                   // +0x48 local transform (0x34)
    char m_pad_7c[4];
    Unk_NodePtr m_spSplit;                  // +0x80 plain NiNode created for the split
    Unk_NodePtr m_spRoot;                   // +0x88 "Effect Root" EffectNode
    float m_fFadeStart;                     // +0x90
    float m_fFadeTime;                      // +0x94
    int m_nLodLevel;                        // +0x98
    float m_fStartTime;                     // +0x9c
    ATL::CAtlArray<DuplicatedAlphaControllerPtr> m_aAlphaCtrls;     // +0xa0
    efd::SmartPointer<CEffectObject> m_spEffectObject;              // +0xc0 kfm effect object
    MS2Ptr<CNifEffectParam> m_spParam;      // +0xc8
};
MS2_CHECK_SIZE(CNifEffect, 0xd8);
MS2_CHECK_OFFSET(CNifEffect, m_spTarget, 0x38);
MS2_CHECK_OFFSET(CNifEffect, m_kXform, 0x48);
MS2_CHECK_OFFSET(CNifEffect, m_spRoot, 0x88);
MS2_CHECK_OFFSET(CNifEffect, m_aAlphaCtrls, 0xa0);
MS2_CHECK_OFFSET(CNifEffect, m_spParam, 0xc8);

class NiStream;

// ---- nif loader thread -------------------------------------------------------------------------------------------
class CNiStreamLoadThread;
template <> class TSingleton<CNiStreamLoadThread>
{
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CNiStreamLoadThread* s_instance;         // 0x143ae0788
    static CNiStreamLoadThread* GetInstance();          // 0x1414a5720
};

// Background nif reader (RTTI "CNiStreamLoadThread", 0x178 bytes). Paths are queued with Enqueue (the worker loads
// them into m_mapDone), Get takes a finished stream or loads it on the calling thread.
class CNiStreamLoadThread : public CThread, public TSingleton<CNiStreamLoadThread>
{
public:
    CNiStreamLoadThread();                                      // 0x1415509b0
    virtual ~CNiStreamLoadThread();                             // 0x141550af0
    virtual unsigned vfunc_1(void* pParam, Unk_140659080& kStartup);    // 1 0x141550cf0 worker loop

    void Stop();                                                // 0x141550f20 signal the worker and join
    void Enqueue(CString strPath);                              // 0x141550f90 queue a path (loads inline when paused off)
    void SetTexturePalette(NiPointer<NiTexturePalette> spPalette);      // 0x1415510f0
    NiStream* Get(CString strPath);                             // 0x141551140 finished stream, else load now
    void Pause();                                               // 0x1415512c0
    void Resume();                                              // 0x1415512e0
    void Dequeue(CString strPath);                              // 0x141551300 drop a queued path
    NiStream* Load(CString strPath, int bKeep);                 // 0x1415513e0 read a nif; bKeep: park it in m_mapDone

public:
    MS2_LAYOUT_FRIEND;
    int m_nPause;                                               // +0x20
    HANDLE m_hStop;                                             // +0x28 event, set to stop the worker
    HANDLE m_hWork;                                             // +0x30 semaphore, one count per queued path
    int m_nStop;                                                // +0x38
    CLockCriticalSection m_kQueueLock;                          // +0x40
    CLockCriticalSection m_kDoneLock;                           // +0x70
    void* m_pParam;                                             // +0xa0 worker parameter
    ATL::CRBMap<CString, POSITION> m_mapQueued;                 // +0xa8 path -> position in m_lstQueue
    ATL::CAtlList<CString> m_lstQueue;                          // +0xd8 paths waiting to be read
    ATL::CRBMap<CString, NiStream*> m_mapDone;                  // +0x108 finished streams
    NiPointer<NiTexturePalette> m_spPalette;                    // +0x138
};
MS2_CHECK_SIZE(CNiStreamLoadThread, 0x140);
MS2_CHECK_OFFSET(CNiStreamLoadThread, m_hWork, 0x30);
MS2_CHECK_OFFSET(CNiStreamLoadThread, m_kDoneLock, 0x70);
MS2_CHECK_OFFSET(CNiStreamLoadThread, m_mapQueued, 0xa8);
MS2_CHECK_OFFSET(CNiStreamLoadThread, m_lstQueue, 0xd8);
MS2_CHECK_OFFSET(CNiStreamLoadThread, m_mapDone, 0x108);
MS2_CHECK_OFFSET(CNiStreamLoadThread, m_spPalette, 0x138);

// ---- nif / texture cache ----------------------------------------------------------------------------------------
// Fixed-size ring of the most recent clones handed out for one nif path (the "reference count" of a skill effect).
// 0x38 bytes; vftable 2 slots (dtor, vfunc_1 = reset to a new capacity), ??_G 0x14155c720.
template <class T> class TCircleList
{
public:
    explicit TCircleList(int nCapacity = 0)                     // 0x14155aad0
        : m_nWrite(0), m_nStart(0), m_nLast(0), m_nCount(0)
    {
        m_nCapacity = nCapacity;
        if (nCapacity == 0)
            m_nCapacity = 1;
        m_aItems.reserve(m_nCapacity);
        m_aItems.resize(m_nCapacity);
    }
    virtual ~TCircleList() {}                                   // 0x14155b6c0
    virtual void vfunc_1(int nCapacity)                         // 1 0x14155cd00 empty the ring and resize it
    {
        if (nCapacity == 0)
            m_nCapacity = 1;
        else
            m_nCapacity = nCapacity;
        m_nWrite = 0;
        m_nLast = 0;
        m_nStart = 0;
        m_nCount = 0;
        m_aItems.clear();
        m_aItems.reserve(m_nCapacity);
        m_aItems.resize(m_nCapacity);
    }
    int GetCapacity() const { return m_nCapacity; }             // @0x14155d830
    int GetCount() const { return m_nCount; }                   // @0x14155d9d0
    int Get(int nIndex, T& rOut) const                         // 0x14155d5b0 oldest first
    {
        int nInCapacity = nIndex < m_nCapacity;
        int nInCount = nIndex < m_nCount;
        if (nInCapacity & nInCount)
        {
            int nSum = m_nStart + nIndex;
            int nWrapped = (nSum >= m_nCapacity) * (nSum - m_nCapacity);
            nIndex = (nWrapped == 0) * nSum + nWrapped;
            rOut = m_aItems[nIndex];
            return 1;
        }
        return 0;
    }
    void Push(const T& rItem)                                   // 0x14155cb10 overwrites the oldest when full
    {
        m_aItems[m_nWrite] = rItem;
        int nNext = m_nWrite + 1;
        m_nLast = m_nWrite;
        m_nCount += m_nCount < m_nCapacity;
        m_nWrite = (nNext != m_nCapacity) * nNext;
        m_nStart = ((m_nLast + 1) * (m_nCount == m_nCapacity)) % m_nCapacity;
    }

    std::vector<T> m_aItems;        // +0x08
    int m_nWrite;                   // +0x20 next slot
    int m_nStart;                   // +0x24 oldest slot
    int m_nLast;                    // +0x28 slot written last
    int m_nCount;                   // +0x2c
    int m_nCapacity;                // +0x30
};
MS2_CHECK_SIZE(TCircleList<NiAVObjectPtr>, 0x38);

// One cached resource (RTTI "CCached<...>"): the resource, the time it was last handed out, the cache class (0 NotCache,
// 1 ForceKeep, 2 MySkill, 3 OtherSkill, 4 NPC, 5 DependTime) and the file stamp used to detect a changed file.
template <class T> class CCached : public NiRefObject
{
public:
    CCached() : m_spData(0), m_dLastUse(0), m_nClass(5) {}    // 0x14155a540 / 0x14155a5c0
    virtual ~CCached() = default;                                    // 0x14155b410 / 0x14155b450
    T m_spData;                     // +0x10
    double m_dLastUse;              // +0x18
    int m_nClass;                   // +0x20
    CCacheData m_kFile;             // +0x28
};
typedef CCached<NiAVObjectPtr> CCachedNifBase;
typedef CCached<efd::SmartPointer<NiTexture> > CCachedTexture;
MS2_CHECK_SIZE(CCachedTexture, 0x50);

// A cached nif plus the clones handed out of it.
class CCachedNif : public CCachedNifBase
{
public:
    CCachedNif() { m_aClones.RemoveAll(); }                     // 0x14155b020
    virtual ~CCachedNif() { m_aClones.RemoveAll(); }            // 0x14155b890
    ATL::CAtlArray<NiAVObjectPtr> m_aClones;                    // +0x50
    char m_pad_70[8];
};
MS2_CHECK_SIZE(CCachedNif, 0x78);
typedef efd::SmartPointer<CCachedNif> CCachedNifPtr;
typedef efd::SmartPointer<CCachedTexture> CCachedTexturePtr;

// Key of the texture cache: the path plus the packed NiTexture::FormatPrefs. Ordered by the prefs word, then the path.
struct Unk_NifTexKey
{
    Unk_NifTexKey() : m_nPrefs(0) {}
    Unk_NifTexKey(CString strPath, NiTexture::FormatPrefs kPrefs)     // 0x14155b0b0
    {
        m_strPath = strPath;
        *(reinterpret_cast<unsigned char*>(&m_nPrefs) + 0) = (unsigned char)kPrefs.m_ePixelLayout;
        *(reinterpret_cast<unsigned char*>(&m_nPrefs) + 1) = (unsigned char)kPrefs.m_eAlphaFmt;
        *(reinterpret_cast<unsigned char*>(&m_nPrefs) + 2) = (unsigned char)kPrefs.m_eMipMapped;
        *(reinterpret_cast<unsigned char*>(&m_nPrefs) + 3) = 0;
    }
    bool operator<(const Unk_NifTexKey& r) const                // 0x14155c4d0
    {
        if (m_nPrefs == r.m_nPrefs)
            return m_strPath < r.m_strPath;
        return m_nPrefs < r.m_nPrefs;
    }
    bool operator==(const Unk_NifTexKey& r) const               // 0x14155bdc0
    {
        if (m_nPrefs == r.m_nPrefs)
            return m_strPath == r.m_strPath;
        return false;
    }
    CString m_strPath;
    unsigned m_nPrefs;                              // bytes: layout, alpha format, mip-mapped, pad
};
MS2_CHECK_SIZE(Unk_NifTexKey, 0x10);

// Entries per cache class (see CNifLoadingService).
struct Unk_NifCounts
{
    int nNotCache;
    int nForceKeep;
    int nMySkill;
    int nOtherSkill;
    int nNPC;
    int nDependTime;
};
MS2_CHECK_SIZE(Unk_NifCounts, 0x18);

// ---- the loading service ---------------------------------------------------------------------------------------
class CNifLoadingService;
template <> class TSingleton<CNifLoadingService>
{
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CNifLoadingService* s_instance;          // 0x143ab5bc8
};

// efd system service (class id 0x06100011, RTTI "CNifLoadingService"): caches loaded nifs and textures by path and
// hands out clones of the nifs. Cache classes (eRP_*): 0 NotCache, 1 ForceKeep, 2 MySkill, 3 OtherSkill, 4 NPC,
// 5 DependTime. Member names are invented from their use.
class CNifLoadingService : public efd::ISystemService, public TSingleton<CNifLoadingService>
{
    EE_DECLARE_CLASS1(CNifLoadingService, 0x06100011, efd::IBase);       // exe: SetupClassInfo chains to IBase directly
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    typedef std::map<CString, TCircleList<NiAVObjectPtr> > PoolMap;

    CNifLoadingService();                           // 0x141551810
    virtual ~CNifLoadingService();                  // 0x141551a10
    virtual const char* GetDisplayName() const;     // 0x141551ac0
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x141555ce0
    virtual efd::AsyncResult OnInit();              // 0x141555d60
    virtual efd::AsyncResult OnTick();              // 0x141555e60
    virtual efd::AsyncResult OnShutdown();          // 0x141555e90

    void ClearNifCache();                           // 0x141551ae0
    void ClearTextureCache();                       // 0x141551b80
    void ClearCaches();                             // 0x141551be0
    void PreloadEffectNifs();                       // 0x141551c10 preload ./Data/Resource/Model/Effect/BG/Perform/*.nif
    bool IsCached(CString strPath);                 // 0x141551db0
    // Cached clone of the nif (loading it first when needed); nMyRefs / nOtherRefs size the clone rings.
    NiAVObjectPtr Load(CString strPath, bool bFlag, int nClass, int nMyRefs, int nOtherRefs);   // 0x141551ea0
    bool Preload(CString strPath, bool bFlag, int nClass);          // 0x1415525d0
    CCachedNifPtr FindCachedNif(CString strPath, int nClass, bool* pbReloaded);    // 0x1415527a0
    CCachedNifPtr CreateCachedNif(CString strPath, int nClass, bool bFlag, bool bReloaded);    // 0x141552920
    efd::SmartPointer<NiTexture> GetTexture(CString strPath, int nClass);          // 0x141552f90
    efd::SmartPointer<NiSourceTexture> CreateTexture(CString strPath, NiPixelDataPtr spPixels, int nClass);   // 0x1415534d0
    efd::SmartPointer<NiTexture> GetTextureFrom(CString strKey, CString strFile, int nClass);  // 0x141553910
    efd::SmartPointer<NiTexture> FindTexture(CString strPath, const NiTexture::FormatPrefs* pPrefs);   // 0x141553eb0
    void AddTexture(CString strPath, NiSourceTexture* pTexture);   // 0x1415540f0
    void Sweep();                                   // 0x1415543e0 per-minute eviction pass and counter refresh
    void LowerLifetime(double dSeconds);            // 0x141554ce0
    void ResetLifetime();                           // 0x141554d20
    void SetLifetime(double dSeconds);              // 0x141554d90
    void DumpTextures();                            // 0x141554f60 write LoadedTextures.txt
    void DumpNifs();                                // 0x141555600 write LoadedNifs.txt
    void ApplyWeights(CString strNifPath, NiAVObject* pkRoot);     // 0x141555f50 per-node weight from the sibling .xml
    NiAVObjectPtr CloneCached(CString strPath, CCachedNifPtr spCached);     // 0x141556320
    void RefreshTextures();                         // 0x141556410
    void LogCounts();                               // 0x141556610
    unsigned FUN_14151e770();                       // 0x14151e770 number of cached nifs (defined elsewhere)
    unsigned FUN_14151e790();                       // 0x14151e790 number of cached textures (defined elsewhere)

    static bool OnDeviceReset(char bBefore, void* pRenderer);   // 0x141554df0
    static bool OnDeviceLost(void* pRenderer);                              // 0x141554ee0

public:
    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<CString, CCachedNifPtr> m_mapNif;               // +0x28 path -> cached nif
    ATL::CRBMap<Unk_NifTexKey, CCachedTexturePtr> m_mapTex;     // +0x58 (path, prefs) -> cached texture
    double m_dLifetime;                                         // +0x88 seconds a skill nif / texture stays cached = 120
    double m_dConfigLifetime;                                   // +0x90 override set by SetLifetime
    std::map<CString, TiXmlDocument> m_mapWeightDoc;            // +0x98 sibling .xml of each nif
    PoolMap m_mapMyPool;                                        // +0xa8 clone rings of the player's own effects
    PoolMap m_mapOtherPool;                                     // +0xb8 clone rings of other players' effects
    int m_bShutdown;                                            // +0xc8
    int m_bRefreshTextures;                                     // +0xcc
    Unk_McTimer m_kSweepTimer;                                  // +0xd0
    Unk_NifCounts m_kNifCount;                                         // +0xd8 per cache class
    Unk_NifCounts m_kTexCount;                                         // +0xf0 per cache class
};
MS2_CHECK_SIZE(CNifLoadingService, 0x108);
MS2_CHECK_OFFSET(CNifLoadingService, m_mapNif, 0x28);
MS2_CHECK_OFFSET(CNifLoadingService, m_mapTex, 0x58);
MS2_CHECK_OFFSET(CNifLoadingService, m_dLifetime, 0x88);
MS2_CHECK_OFFSET(CNifLoadingService, m_mapWeightDoc, 0x98);
MS2_CHECK_OFFSET(CNifLoadingService, m_mapMyPool, 0xa8);
MS2_CHECK_OFFSET(CNifLoadingService, m_mapOtherPool, 0xb8);
MS2_CHECK_OFFSET(CNifLoadingService, m_bShutdown, 0xc8);
MS2_CHECK_OFFSET(CNifLoadingService, m_kSweepTimer, 0xd0);
MS2_CHECK_OFFSET(CNifLoadingService, m_kNifCount, 0xd8);
MS2_CHECK_OFFSET(CNifLoadingService, m_kTexCount, 0xf0);
