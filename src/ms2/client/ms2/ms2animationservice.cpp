// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2AnimationService: the game's subclass of the engine's
// animation service; reloads the gender specific KF sets, uncaches NPC assets and keeps the KF "preload" XML cache.
// MS2-UNIT: ?\ms2animationservice.cpp
// MS2-RANGE: 0x1400f8710-0x1400f8990 .text$di
// MS2-RANGE: 0x1414a8770-0x1414af320 .text$mn
// MS2-PIN: ??1?$SmartPointer@VKFMCacheRequestData@AnimationService@egmAnimation@@@efd@@QEAA@XZ 0x1414abb00
// MS2-PIN: ??B?$SmartPointer@VKFMCacheRequestData@AnimationService@egmAnimation@@@efd@@QEBAPEAVKFMCacheRequestData@AnimationService@egmAnimation@@XZ 0x1414abdd0
// MS2-PIN: ??B?$SmartPointer@VSceneGraphCacheData@SceneGraphCache@ecr@@@efd@@QEBAPEAVSceneGraphCacheData@SceneGraphCache@ecr@@XZ 0x1414abde0
// MS2-PIN: ??C?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@QEBAPEAVKFMCacheData@KFMCache@egmAnimation@@XZ 0x1414abdf0
// MS2-PIN: ?_Max_size1@?$_Normal_allocator_traits@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@@std@@SA_KAEBV?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@U?$integral_constant@_N$00@2@@Z 0x1414ae680
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiString@@VTiXmlDocument@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBVNiString@@VTiXmlDocument@@@1@XZ 0x1414abe60 ; unique
// MS2-PIN: ?GetClassDesc@AnimationService@egmAnimation@@UEBAPEBVClassInfo@efd@@XZ 0x1414ac860 ; unique
// MS2-PIN: ?GetClassDesc@MS2KFMCache@@UEBAPEBVClassInfo@efd@@XZ 0x1414ac870 ; unique
// MS2-PIN: ?TypeCast@AnimationService@egmAnimation@@UEBA_NIPEAPEAX@Z 0x1414ad5c0 ; unique
// MS2-PIN: ?TypeCast@AnimationService@egmAnimation@@UEBA_NIPEAPEBX@Z 0x1414ad610 ; unique
// MS2-PIN: ?TypeCast@MS2KFMCache@@UEBA_NIPEAPEAX@Z 0x1414ad660 ; unique
// MS2-PIN: ?TypeCast@MS2KFMCache@@UEBA_NIPEAPEBX@Z 0x1414ad6b0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@VNiString@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVNiString@@VTiXmlDocument@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiString@@VTiXmlDocument@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@VNiString@@@2@XZ 0x1414ae2e0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@VNiString@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBVNiString@@VTiXmlDocument@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVNiString@@VTiXmlDocument@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@VNiString@@@2@XZ 0x1414ae2f0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@XZ 0x1414ae300 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@efd@@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@std@@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VKFMCacheData@KFMCache@egmAnimation@@@efd@@@std@@@2@XZ 0x1414ae380 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@PEAVEntityPreloadData@AnimationService@egmAnimation@@V?$CustomAllocator@PEAVEntityPreloadData@AnimationService@egmAnimation@@@efd@@@std@@@std@@QEBAAEBQEAPEAVEntityPreloadData@AnimationService@egmAnimation@@XZ 0x1414ae720 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@PEAVEntityPreloadData@AnimationService@egmAnimation@@V?$CustomAllocator@PEAVEntityPreloadData@AnimationService@egmAnimation@@@efd@@@std@@@std@@QEBAAEBQEAPEAVEntityPreloadData@AnimationService@egmAnimation@@XZ 0x1414ae760 ; prop
// MS2-PIN: ?empty@?$vector@PEAVActorEntry@AnimationService@egmAnimation@@V?$CustomAllocator@PEAVActorEntry@AnimationService@egmAnimation@@@efd@@@std@@QEBA_NXZ 0x1414aed20 ; unique
// MS2-PIN: ?empty@?$vector@PEAVEntityPreloadData@AnimationService@egmAnimation@@V?$CustomAllocator@PEAVEntityPreloadData@AnimationService@egmAnimation@@@efd@@@std@@QEBA_NXZ 0x1414aed70 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7MS2AnimationService@@6BISystemService@efd@@@ 0x142f1eee8
// MS2-PIN: ??_7MS2AnimationService@@6BIPropertyCallback@egf@@@ 0x142f1efd0
// MS2-PIN: ??_7MS2KFMCache@@6BIBase@efd@@@ 0x142f1efe8
// MS2-PIN: ??_7MS2KFMCache@@6BAssetChangeHandler@efd@@@ 0x142f1f060
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2animationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <map>
#include <NiActorManager.h>
#include <NiFilename.h>
#include <NiKFMTool.h>
#include <NiString.h>
#include "ms2animationservice.h"
#include "ms2kfmfactory.h"
#include "gameobject.h"
#include "filepreload_1.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern int DAT_1439ed00c;                       // option: remember the KF preload files (0 = read the XML each time)
extern void* DAT_143b09498;                     // callback slot set by OnInit (the asset filter)
typedef std::map<NiString, TiXmlDocument> XmlDocMap;

// Elements of the XML preload files (TinyXML nodes of the game's copy; unrecovered class).
class Unk_XmlNode
{
public:
    Unk_XmlNode* FUN_140165cf0(const char* pcName);     // FirstChild(name)
    Unk_XmlNode* FUN_140168650(const char* pcName);     // NextSibling(name)
    const char* FUN_14086f4b0(const char* pcName);      // Attribute(name)
    void FUN_140873ca0(const char* pcName, int nValue); // SetAttribute(name, int)
};
Unk_XmlNode* FUN_140165cf0(TiXmlDocument* pDoc, const char* pcName);    // FirstChild(name) of the document
// The file system: loads XML documents and holds the pending gender-reload request (1 male, 2 female, 3 both, -1 none).
class Unk_FileSys
{
public:
    int FUN_1403974b0(TiXmlDocument* pDoc, const char* pcPath, int nA, bool bB, bool bC);
    int FUN_14039a720();
    void FUN_14039a740();
};
Unk_FileSys* FUN_140166420();
CString FUN_140188f50(const char* pcText, int nCodePage);               // converts attribute text to a CString
CFilePreload* FUN_140ab7a10();                                          // the preload singleton

// ---- static initializers (.text$di, in this order) ----
// @0x1400f8710
static ATL::CRBMap<NiString, MS2Ptr<CCacheData> > s_mapCache(10);
// @0x1400f8740
static XmlDocMap s_mapXml;
// @0x1400f8770
static CLockCriticalSection s_lock;
// @0x1400f87a0
static CString s_aSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f8860
static CString s_strSkill = "skill";
// @0x1400f8890
static CString s_strStun = "stun";
// @0x1400f88c0
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
// @0x1400f8910
static CString s_strSkill2 = "skill";
// @0x1400f8940
static CString s_strStun2 = "stun";
// @0x1400f8970
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static Unk_1401cd100 s_pointer(NULL);

static int s_nReloading;                        // 0x143ae07d0: a KF reload is pending; cleared when the preload lookup ends

// ---- unrecovered callees ----
// 0x30 byte list the player manager fills (ctor 0x140963ae0, dtor 0x1409647c0).
class Unk_ShList
{
public:
    Unk_ShList(int n);                          // 0x140963ae0
    ~Unk_ShList();                              // 0x1409647c0
private:
    void* m_pad[6];
};
MS2_CHECK_SIZE(Unk_ShList, 0x30);
// The game's NiStream (the engine's plus a 0x104 byte label buffer at +8; 0x5d0 bytes; ctor 0x141d44620, dtor 0x141d451c0).
class Unk_KFStream
{
public:
    Unk_KFStream();                             // 0x141d44620
    ~Unk_KFStream();                            // 0x141d451c0
    bool FUN_141d476d0(const char* pcFile);     // loads the file under the label
    void* m_pVtbl;
    char m_acLabel[0x5c8];
};
MS2_CHECK_SIZE(Unk_KFStream, 0x5d0);
void* FUN_1403ed2d0();                                                  // the player manager
void FUN_141bd2db0(void* pMgr, Unk_ShList& kList, int (*pfnFilter)(void*));    // collects the objects accepted by the filter
void* FUN_141bd0cc0(void* pMgr);                                        // the local player (a GameObject)
int FUN_141658e60(GameObject* pPlayer);                                 // gender of the player (0 male, 1 female)
void FUN_1401d3700(CString& kStr);                                      // lower-cases in place
bool FUN_141c43800(NiActorManager* pMgr, Unk_KFStream* pStream);       // NiActorManager::ReloadKFFile for a stream
int FUN_1403b0860(char* pcBuffer, const char* pcFormat, ...);           // sprintf
void* FUN_14099eef0(void* pObj);                                        // object -> player (0 if it is not one)
bool FUN_1414f1760(ecr::SceneGraphService* pSvc, efd::utf8string kID); // MS2SceneGraphService::RemoveUnusedCacheAssetData
ecr::SceneGraphService* FUN_1413f98b0();                                // the scene graph service
int FUN_1401859c0(void* pLog, int nA, int nB, const wchar_t* pwcMsg);   // assertion report
void* FUN_140166440();                                                  // the assert log

// Cached preload table entry of a KF file: 16 bytes (time at +0, text key name at +8).
// Event handed to the asset filter: load state at +0x40, the asset's refcount base at +0x48.
struct Unk_AssetEvent
{
    char m_pad[0x40];
    int m_nState;
    int m_nPad;
    char* m_pAsset;
    char* GetAsset();      // 0x1414ac920
    int GetState();        // 0x1414ac930
};
MS2_CHECK_SIZE(Unk_AssetEvent, 0x50);

// @0x1414ac920
char* Unk_AssetEvent::GetAsset()
{
    return m_pAsset;
}

// @0x1414ac930
int Unk_AssetEvent::GetState()
{
    return m_nState;
}

class Unk_PreloadEntry : public efd::MemObject
{
public:
    Unk_PreloadEntry() {}
    ~Unk_PreloadEntry();                        // 0x141c50d70
    void SetName(const NiFixedString& kName);   // 0x141c50ef0
    void SetTime(float fTime) { m_fTime = fTime; }  // 0x1414ad5a0
    float m_fTime;
    NiFixedString m_kName;
};

// Filter given to the player manager: accepts the objects that are players.
// @0x1414a9c80
static int FUN_1414a9c80(void* pObj)
{
    void* pPlayer = FUN_14099eef0(pObj);
    return pPlayer != 0 ? 1 : 0;
}

// ---- MS2AnimationService ----
// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414a8770
MS2AnimationService::MS2AnimationService() : egmAnimation::AnimationService(false)
{
}
#endif

// @0x1414a87c0
MS2AnimationService::~MS2AnimationService()
{
    if (Unk_LockGuard kGuard = s_lock) {}
    else
    {
        s_mapXml.clear();
        s_mapCache.RemoveAll();
    }
}

// Stores the asset filter in the callback slot.
// @0x1414ad580
static void FUN_1414ad580(bool (*pFilter)(Unk_AssetEvent*))
{
    DAT_143b09498 = (void*)pFilter;
}

// @0x1414a8850
efd::AsyncResult MS2AnimationService::OnInit()
{
    FUN_1414ad580(&MS2AnimationService::FUN_1414a9810);
    return egmAnimation::AnimationService::OnInit();
}

// @0x1414a8880
efd::AsyncResult MS2AnimationService::OnTick()
{
    int nReload = FUN_140166420()->FUN_14039a720();
    if (nReload != -1)
    {
        switch (nReload)
        {
        case 1:
            ReloadMaleKF();
            break;
        case 2:
            ReloadFemaleKF();
            break;
        case 3:
            ReloadMaleKF();
            ReloadFemaleKF();
            break;
        }
        FUN_140166420()->FUN_14039a740();
    }
    return egmAnimation::AnimationService::OnTick();
}
MS2_REPLACE_METHOD(0x1414A8880, MS2AnimationService, OnTick, 136, 0x46C1B757);

// @0x1414a8910
efd::AsyncResult MS2AnimationService::OnShutdown()
{
    if (Unk_LockGuard kGuard = s_lock) {}
    else
    {
        s_mapXml.clear();
        s_mapCache.RemoveAll();
    }
    return egmAnimation::AnimationService::OnShutdown();
}

// Reloads the KF files of the local player when it is a female model (same pass as ReloadMaleKF with the other label).
// MS2-FUNCTIONAL: player-name handling / local buffer layout differs from the exe
#ifndef MS2_HOOK_DLL
// @0x1414a8980
void MS2AnimationService::ReloadFemaleKF()
{
    s_nReloading = 1;
    Unk_ShList kList(10);
    FUN_141bd2db0(FUN_1403ed2d0(), kList, FUN_1414a9c80);
    GameObject* pPlayer = (GameObject*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0 && FUN_141658e60(pPlayer) == 1)
    {
        NiFilename kFilename(pPlayer->FUN_14123bbd0());
        CString kName(kFilename.GetFilename());
        FUN_1401d3700(kName);
        if (kName.Find(":female", 0) != -1)
        {
            egf::EntityID kID;
            pPlayer->FUN_14123c460(kID);
            NiActorManager* pActor = GetActorManager(kID);
            if (pActor != 0)
            {
                pActor->Reset();
                NiKFMTool* pTool = pActor->GetKFMTool();
                unsigned int* pIDs;
                unsigned int uiCount;
                char szBuf[260];
                pTool->GetSequenceIDs(pIDs, uiCount);
                szBuf[0] = 0;
                for (unsigned int i = 0; i < uiCount; ++i)
                {
                    unsigned int uiID = pIDs[i];
                    NiFixedString kFile = pTool->GetFullKFFilename(uiID);
                    Unk_KFStream kStream;
                    FUN_1403b0860(kStream.m_acLabel, "female");
                    if (kStream.FUN_141d476d0(kFile))
                        FUN_141c43800(pActor, &kStream);
                }
                if (pIDs != 0)
                    EE_FREE(pIDs);
            }
        }
    }
}
#endif

// MS2-FUNCTIONAL: player-name handling / local buffer layout differs from the exe
#ifndef MS2_HOOK_DLL
// @0x1414a8c40
void MS2AnimationService::ReloadMaleKF()
{
    s_nReloading = 1;
    Unk_ShList kList(10);
    FUN_141bd2db0(FUN_1403ed2d0(), kList, FUN_1414a9c80);
    GameObject* pPlayer = (GameObject*)FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0 && FUN_141658e60(pPlayer) == 0)
    {
        NiFilename kFilename(pPlayer->FUN_14123bbd0());
        CString kName(kFilename.GetFilename());
        FUN_1401d3700(kName);
        if (kName.Find(":male", 0) != -1)
        {
            egf::EntityID kID;
            pPlayer->FUN_14123c460(kID);
            NiActorManager* pActor = GetActorManager(kID);
            if (pActor != 0)
            {
                pActor->Reset();
                NiKFMTool* pTool = pActor->GetKFMTool();
                unsigned int* pIDs;
                unsigned int uiCount;
                char szBuf[260];
                pTool->GetSequenceIDs(pIDs, uiCount);
                szBuf[0] = 0;
                for (unsigned int i = 0; i < uiCount; ++i)
                {
                    unsigned int uiID = pIDs[i];
                    NiFixedString kFile = pTool->GetFullKFFilename(uiID);
                    Unk_KFStream kStream;
                    FUN_1403b0860(kStream.m_acLabel, "male");
                    if (kStream.FUN_141d476d0(kFile))
                        FUN_141c43800(pActor, &kStream);
                }
                if (pIDs != 0)
                    EE_FREE(pIDs);
            }
        }
    }
}
#endif

// @0x1414a8f00
void MS2AnimationService::OnAssetLoadFailure(AssetDataPtr spAssetData)
{
    egmAnimation::AnimationService::OnAssetLoadFailure(spAssetData);
}
MS2_REPLACE_METHOD(0x1414A8F00, MS2AnimationService, OnAssetLoadFailure, 84, 0x04D8F244);

// Uncaches the cached assets whose KF path names an npc.
// @0x1414a8f60
void MS2AnimationService::UnCacheNpcAssets()
{
    efd::vector<egmAnimation::KFMCache::KFMCacheHandle> kHandles;
    AssetMap::iterator it = m_assetsByPhysicalID.begin();
    while (it != m_assetsByPhysicalID.end())
    {
        if (it->second->m_isCached)
        {
            CString kPath(it->second->m_cacheHandle->m_filePath.c_str());
            FUN_1401d3700(kPath);
            if (kPath.Find("npc", 0) != -1)
                kHandles.push_back(it->second->m_cacheHandle);
        }
        it++;
    }
    UnCacheHandles(kHandles);
}
MS2_REPLACE_METHOD(0x1414A8F60, MS2AnimationService, UnCacheNpcAssets, 336, 0x5187A1F7);

// Reads the "preload" table of a KF file (<ms2><kfm-name><key text= time=/>...</...></ms2>) into a new array of
// entries and returns their number. The preload files are cached per path in s_mapXml / s_mapCache.
// MS2-FUNCTIONAL: 1.8 KB XML reader; CString/temporary layout not byte-identical
// @0x1414a90c0
int FUN_1414a90c0(NiString kPath, NiString kAnim, Unk_PreloadEntry** ppEntries)
{
    int nCount = 0;
    Unk_XmlNode* pRoot = 0;
    if (Unk_LockGuard kGuard = s_lock) {}
    else
    {
        if (DAT_1439ed00c != 0)
        {
            MS2Ptr<CCacheData> spCache(0);
            NiString kKey(kPath);
            kKey.Replace("\\", "/");
            if (!s_mapCache.Lookup(kKey, spCache))
            {
                CCacheData* pNew = new CCacheData();
                spCache.AssignRaw(pNew);
                spCache.get()->FUN_1401d1160(CString((const char*)kKey));
                s_mapCache.SetAt(kKey, spCache);
            }
            else if (FUN_1401d1320(spCache.get()))
            {
                spCache.get()->FUN_1401d1160(CString((const char*)kKey));
                s_nReloading = 1;
            }
        }
        TiXmlDocument kDoc;
        XmlDocMap::iterator it = s_mapXml.find(kPath);
        if (it != s_mapXml.end())
        {
            if (s_nReloading == 0)
                pRoot = FUN_140165cf0(&it->second, "ms2");
            else
                s_mapXml.erase(it);
        }
        if (pRoot == 0)
        {
            if (FUN_140166420()->FUN_1403974b0(&kDoc, (const char*)kPath, 0, true, false) != 0)
            {
                pRoot = FUN_140165cf0(&kDoc, "ms2");
                s_mapXml.insert(std::make_pair(kPath, kDoc));
            }
        }
        if (pRoot != 0)
        {
            Unk_XmlNode* pAnim = pRoot->FUN_140165cf0((const char*)kAnim);
            if (pAnim != 0)
            {
                for (Unk_XmlNode* pKey = pAnim->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
                    ++nCount;
                if (nCount > 0)
                    *ppEntries = EE_NEW Unk_PreloadEntry[nCount];
                int nIndex = 0;
                for (Unk_XmlNode* pKey = pAnim->FUN_140165cf0("key"); pKey != 0; pKey = pKey->FUN_140168650("key"))
                {
                    CString kText = FUN_140188f50(pKey->FUN_14086f4b0("text"), 0);
                    (*ppEntries)[nIndex].SetName(NiFixedString(pKey->FUN_14086f4b0("text")));
                    (*ppEntries)[nIndex].SetTime((float)atof(pKey->FUN_14086f4b0("time")));
                    if (pKey->FUN_14086f4b0("preload") == 0)
                    {
                        pKey->FUN_140873ca0("preload", 1);
                        if (kText.Find("effect_", 0) == 0)
                            FUN_140ab7a10()->FUN_1412107f0(kText.Right(kText.GetLength() - 7), 5);
                    }
                    ++nIndex;
                }
            }
        }
        s_nReloading = 0;
    }
    return nCount;
}

// Asset filter (OnInit stores it in the callback slot): true when the asset is cached and its cache request still
// has NIFs outstanding.
// @0x1414a9810
bool MS2AnimationService::FUN_1414a9810(Unk_AssetEvent* pEvent)
{
    if (pEvent != 0)
    {
        char* pRaw = pEvent->GetAsset();
        AssetData* pAsset = pRaw != 0 ? (AssetData*)(pRaw - 8) : 0;
        if (pEvent->GetState() == 1)
            return false;
        if (pAsset == 0)
            return false;
        KFMCacheRequestDataPtr spRequest = pAsset->m_spCacheLoadData;
        if ((KFMCacheRequestData*)spRequest == 0)
            return false;
        if (!pAsset->m_isCached)
            return false;
        if (pAsset->m_spCacheLoadData->m_numOutstandingNIFs == 0)
            return false;
    }
    else
    {
        return false;
    }
    return true;
}

// @0x1414a9940
size_t MS2AnimationService::GetAssetCount()
{
    return m_assetsByPhysicalID.size();
}
MS2_REPLACE_METHOD(0x1414A9940, MS2AnimationService, GetAssetCount, 31, 0x38BAB10B);

// @0x1414a9970
size_t MS2AnimationService::GetActorCount()
{
    return m_entityData.size();
}
MS2_REPLACE_METHOD(0x1414A9970, MS2AnimationService, GetActorCount, 31, 0xC814EC1A);

// Protected view of the KFM cache's map of ready assets.
struct Unk_KFMCacheView : public egmAnimation::KFMCache
{
    typedef KFMCacheData Data;
    size_t FUN_1414ac840() { return m_cache.size(); }
};

// @0x1414ac8a0
egmAnimation::KFMCache* MS2AnimationService::GetKFMCache()
{
    return m_spKFMCache;
}

// @0x1414a99a0
size_t MS2AnimationService::GetKFMCacheCount()
{
    if (GetKFMCache())
        return static_cast<Unk_KFMCacheView*>(GetKFMCache())->FUN_1414ac840();
    return 0;
}
MS2_REPLACE_METHOD(0x1414A99A0, MS2AnimationService, GetKFMCacheCount, 51, 0x7CDB4B62);

// Drops the shared XML/preload caches.
// @0x1414a99e0
void FUN_1414a99e0()
{
    s_mapXml.clear();
    s_mapCache.RemoveAll();
}

// Factory of the KFM cache service object. Not in the hook DLL: MS2::RegisterServices (hooked) registers it, and it
// must build the exe's MS2KFMCache (fx6).
#ifndef MS2_HOOK_DLL
// @0x1414a9a10
efd::IBase* FUN_1414a9a10()
{
    return EE_NEW MS2KFMCache();
}
#endif

// Protected view of the scene graph cache's data type.
struct Unk_SGCacheView : public ecr::SceneGraphCache
{
    typedef SceneGraphCacheData Data;
};

// Drops an asset that nothing uses any more. The result is always false (the callers only test for the assert).
// @0x1414a9a80
bool MS2AnimationService::RemoveUnusedAsset(efd::utf8string kPhysicalID)
{
    ecr::SceneGraphService* pSceneGraph = FUN_1413f98b0();
    AssetData* pAsset = FindAssetData(kPhysicalID);
    if (pAsset != 0)
    {
        if (!pAsset->m_entities.empty() || !pAsset->m_preloads.empty())
            return false;
        pAsset->m_isCached = false;
        efd::utf8string kID;
        if ((Unk_SGCacheView::Data*)pAsset->m_nifCacheHandle != 0)
            kID = pAsset->m_nifCacheHandle->m_physicalID;
        RemoveUnusedAssetData(AssetDataPtr(pAsset));
        if (pAsset->m_state == 2)
        {
            if (!FUN_1414f1760(pSceneGraph, efd::utf8string(kID)))
            {
                FUN_1401859c0(FUN_140166440(), 0xc, 0x13,
                              L"!((MS2SceneGraphService*)pSceneGraph)->RemoveUnusedCacheAssetData(id)");
                return false;
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x1414A9A80, MS2AnimationService, RemoveUnusedAsset, 503, 0x794BD1CA);

// @0x1414ab9e0
MS2KFMCache::MS2KFMCache()
{
}

// MS2-FUNCTIONAL: exe omits the vftable resets in the destructor
// @0x1414abca0
MS2KFMCache::~MS2KFMCache()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2bf0-0x142cb2d20 .text$yd
