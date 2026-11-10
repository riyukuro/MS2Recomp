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
#include <efd/SmartPointer.h>
#include <map>
#include <NiActorManager.h>
#include <NiFilename.h>
#include <NiKFMTool.h>
#include <NiString.h>
#include <NiTextKey.h>   // C3: the KF text keys the preload table fills
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
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC (efd::DynamicCast<PC, GameObject>)
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/filepreload_1.h"
class TiXmlElement;
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};

extern int DAT_1439ed00c;                       // option: remember the KF preload files (0 = read the XML each time)
namespace ecr { class SceneGraphCacheResponse; }
extern bool (*g_pfnMS2SceneGraphCacheFilter)(const ecr::SceneGraphCacheResponse*);   // C3: was DAT_143b09498, the asset filter set by OnInit
typedef std::map<NiString, TiXmlDocument> XmlDocMap;

// Elements of the XML preload files (TinyXML nodes of the game's copy; unrecovered class).
class Unk_XmlNode
{
public:
    Unk_XmlNode* FirstChild(const char* pcName);
    Unk_XmlNode* NextSibling(const char* pcName);
};
void XmlSetAttr(TiXmlElement* pElem, const char* pcName, int nValue);
// The file system: loads XML documents and holds the pending gender-reload request (1 male, 2 female, 3 both, -1 none).
class Unk_FileSys : public CFileSystem
{
};
CString FUN_140188f50(const char* pcText, int nCodePage);               // converts attribute text to a CString

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
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_pointer(0);

static int s_nReloading;                        // 0x143ae07d0: a KF reload is pending; cleared when the preload lookup ends

// ---- unrecovered callees ----
// The world game object WorldService lists (complete so the list can destroy its SmartPointers).
class Unk_WsC_GameObj : public GameObject { };
// GameObject view: 0x14123c460 returns the actor entity id by value (written through the hidden return pointer).

class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* GetLocalPlayer();
    void CollectObjects(ATL::CAtlList<efd::SmartPointer<class Unk_WsC_GameObj> >* out, int (*filter)(class Unk_WsC_GameObj*));
    static class WorldService* GetInstance();
};
void ToLower(CString& kStr);                                      // lower-cases in place
class MS2SceneGraphService { public: bool RemoveUnusedCacheAssetData(efd::utf8string physicalID); };   // C3: member view
ecr::SceneGraphService* FUN_1413f98b0();                                // the scene graph service
class CLogString* GetLogString();   // C3: was FUN_140166440
void Unk_AdditionalLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszText);   // C3: was FUN_1401859c0

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


// Filter given to the player manager: accepts the objects that are players.
// @0x1414a9c80
static int IsPlayerObject(void* pObj)
{
    void* pPlayer = efd::DynamicCast<PC, GameObject>(reinterpret_cast<GameObject*>(pObj));
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
static void SetAssetFilter(bool (*pFilter)(Unk_AssetEvent*))
{
    g_pfnMS2SceneGraphCacheFilter = (bool (*)(const ecr::SceneGraphCacheResponse*))pFilter;
}

// @0x1414a8850
efd::AsyncResult MS2AnimationService::OnInit()
{
    SetAssetFilter(&MS2AnimationService::HasOutstandingNifs);
    return egmAnimation::AnimationService::OnInit();
}

// @0x1414a8880
efd::AsyncResult MS2AnimationService::OnTick()
{
    int nReload = GetFileSystem()->GetCharacterMask();
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
        ((class Unk_FileSys*)GetFileSystem())->ResetCharacterMask();
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
#ifndef MS2_HOOK_DLL
// @0x1414a8980
void MS2AnimationService::ReloadFemaleKF()
{
    s_nReloading = 1;
    ATL::CAtlList<efd::SmartPointer<Unk_WsC_GameObj> > kList(10);   // C3: was Unk_ShList
    WorldService::GetInstance()->CollectObjects(&kList, reinterpret_cast<int (*)(Unk_WsC_GameObj*)>(IsPlayerObject));
    GameObject* pPlayer = (GameObject*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer != 0 && reinterpret_cast<PC*>(pPlayer)->GetGender() == 1)
    {
        NiFilename kFilename(pPlayer->GetModelPath());
        CString kName(kFilename.GetFilename());
        ToLower(kName);
        if (kName.Find(":female", 0) != -1)
        {
            egf::EntityID kID = ((GameObject*)pPlayer)->GetEntityID();
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
                    NiStream kStream;
                    sprintf(kStream.m_acStudioPath0x8, "female");
                    if (kStream.Load(kFile))
                        pActor->ReloadKFFile(kStream);
                }
                if (pIDs != 0)
                    EE_FREE(pIDs);
            }
        }
    }
}
#endif

#ifndef MS2_HOOK_DLL
// @0x1414a8c40
void MS2AnimationService::ReloadMaleKF()
{
    s_nReloading = 1;
    ATL::CAtlList<efd::SmartPointer<Unk_WsC_GameObj> > kList(10);   // C3: was Unk_ShList
    WorldService::GetInstance()->CollectObjects(&kList, reinterpret_cast<int (*)(Unk_WsC_GameObj*)>(IsPlayerObject));
    GameObject* pPlayer = (GameObject*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetLocalPlayer();
    if (pPlayer != 0 && reinterpret_cast<PC*>(pPlayer)->GetGender() == 0)
    {
        NiFilename kFilename(pPlayer->GetModelPath());
        CString kName(kFilename.GetFilename());
        ToLower(kName);
        if (kName.Find(":male", 0) != -1)
        {
            egf::EntityID kID = ((GameObject*)pPlayer)->GetEntityID();
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
                    NiStream kStream;
                    sprintf(kStream.m_acStudioPath0x8, "male");
                    if (kStream.Load(kFile))
                        pActor->ReloadKFFile(kStream);
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
            ToLower(kPath);
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
// @0x1414a90c0
int FUN_1414a90c0(NiString kPath, NiString kAnim, NiTextKey** ppEntries)
{
    Unk_XmlNode* pRoot = 0;
    int nCount = 0;
    if (Unk_LockGuard kGuard = s_lock) {}
    else
    {
        if (DAT_1439ed00c != 0)
        {
            MS2Ptr<CCacheData> spCache(0);
            NiString kKey(kPath);
            kKey.Replace("\\", "/");
            if (s_mapCache.Lookup(kKey, spCache))
            {
                if (FUN_1401d1320(spCache.get()))
                {
                    spCache.get()->SetPath(CString((const char*)kKey));
                    s_nReloading = 1;
                }
            }
            else
            {
                spCache.AssignRaw(new CCacheData());
                spCache.get()->SetPath(CString((const char*)kKey));
                s_mapCache.SetAt(kKey, spCache);
            }
        }
        TiXmlDocument kDoc;
        XmlDocMap::iterator it = s_mapXml.find(kPath);
        if (it != s_mapXml.end())
        {
            if (s_nReloading != 0)
                s_mapXml.erase(it);
            else
                pRoot = reinterpret_cast<Unk_XmlNode*>(&it->second)->FirstChild("ms2");
        }
        if (pRoot == 0)
        {
            if (((class Unk_FileSys*)GetFileSystem())->LoadXmlFile(&kDoc, (const char*)kPath, 0, true, false) != 0)
            {
                pRoot = reinterpret_cast<Unk_XmlNode*>(&kDoc)->FirstChild("ms2");
                s_mapXml.insert(std::make_pair(kPath, kDoc));
            }
        }
        if (pRoot != 0)
        {
            Unk_XmlNode* pAnim = pRoot->FirstChild((const char*)kAnim);
            if (pAnim != 0)
            {
                for (Unk_XmlNode* pKey = pAnim->FirstChild("key"); pKey != 0; pKey = pKey->NextSibling("key"))
                    ++nCount;
                if (nCount > 0)
                    *ppEntries = EE_NEW NiTextKey[nCount];
                int nIndex = 0;
                for (Unk_XmlNode* pKey = pAnim->FirstChild("key"); pKey != 0; pKey = pKey->NextSibling("key"))
                {
                    CString kText = FUN_140188f50(((class TiXmlElement*)(pKey))->Attribute("text"), 0);
                    (*ppEntries)[nIndex].SetText(((class TiXmlElement*)(pKey))->Attribute("text"));
                    (*ppEntries)[nIndex].SetTime((float)atof(((class TiXmlElement*)(pKey))->Attribute("time")));
                    const char* szPreload = ((class TiXmlElement*)(pKey))->Attribute("preload");
                    if (szPreload == 0)
                    {
                        XmlSetAttr(reinterpret_cast<TiXmlElement*>(pKey), "preload", 1);
                        if (kText.Find("effect_", 0) == 0)
                            TSingleton<CFilePreload>::GetInstance()->FUN_1412107f0(kText.Right(kText.GetLength() - 7), 5);
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
bool MS2AnimationService::HasOutstandingNifs(Unk_AssetEvent* pEvent)
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
efd::UInt32 MS2AnimationService::GetAssetCount()
{
    return m_assetsByPhysicalID.size();
}
MS2_REPLACE_METHOD(0x1414A9940, MS2AnimationService, GetAssetCount, 31, 0x38BAB10B);

// @0x1414a9970
efd::UInt32 MS2AnimationService::GetActorCount()
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
efd::UInt32 MS2AnimationService::GetKFMCacheCount()
{
    if (GetKFMCache())
        return static_cast<Unk_KFMCacheView*>(GetKFMCache())->FUN_1414ac840();
    return 0;
}
MS2_REPLACE_METHOD(0x1414A99A0, MS2AnimationService, GetKFMCacheCount, 51, 0x7CDB4B62);

// Drops the shared XML/preload caches.
// @0x1414a99e0
void ClearCaches()
{
    s_mapXml.clear();
    s_mapCache.RemoveAll();
}

// Factory of the KFM cache service object. Not in the hook DLL: MS2::RegisterServices (hooked) registers it, and it
// must build the exe's MS2KFMCache (fx6).
#ifndef MS2_HOOK_DLL
// @0x1414a9a10
efd::IBase* CreateKFMCache()
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
            if (!reinterpret_cast<MS2SceneGraphService*>(pSceneGraph)->RemoveUnusedCacheAssetData(efd::utf8string(kID)))
            {
                Unk_AdditionalLog(GetLogString(), 0xc, 0x13,
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

// ~MS2KFMCache (0x1414abca0) is implicit: an explicit empty body keeps a dead vptr store the exe does not have.
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2bf0-0x142cb2d20 .text$yd
