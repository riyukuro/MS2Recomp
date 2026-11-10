// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Process-shutdown glue: one thunk per TSingleton-style global that deletes
// the singleton through its deleting destructor and clears the global (149 of them, 0x1414a1c30-0x1414a53f0), the matching
// GetInstance accessors, five ATL hash map (CAtlMap) RemoveAll instances with their auto-rehash lock helpers, and a handful of
// tiny virtual-slot stubs of classes that live in other units (CGameApp, the property visualization service, ...).
// File and function names are invented. The singleton classes themselves are not recovered here: they are opaque polymorphic
// types (Unk_SingletonObj*) whose only used member is the scalar deleting destructor in vftable slot 0.
// MS2-UNIT: unit_1414a1c30
// MS2-RANGE: 0x1414a1c30-0x1414a6010 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include <atlstr.h>
#include <direct.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/filesystem.h"
#include "hook/ms2hook.h"
#include <efd/RefCount.h>
#include <efd/SmartPointer.h>
#include <efd/ClassInfo.h>
#include "ms2/placeholder/gameeventmanagercli.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/cusereventmanager.h"
#include "ms2/commonfiles/seasondatatable.h"
#include "ms2/commonfiles/maid.h"
#include "ms2/commonfiles/shopcategorytable.h"
#include "ms2/commonfiles/ugcdesigntable.h"
#include "ms2/placeholder/paybacktable.h"
#include "ms2/commonfiles/reactordata.h"
#include "ms2/placeholder/carcadedatatable.h"
#include "ms2/client/ms2/commoneffectdummy.h"
#include "ms2/placeholder/setitemtable.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/unnamed/unit_140ad1860.h"
#include "ms2/commonfiles/specialeffectfunctionmanager.h"
#include "ms2/commonfiles/maidgradejockpottable.h"
#include "ms2/placeholder/cmanufacturemanager.h"
#include "ms2/placeholder/ms2propertyvisualizationservice.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/commonfiles/ugcmapsetiteminfo.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/termtagmanagercli.h"
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/placeholder/ctaximanager.h"
#include "ms2/placeholder/oncecallbacktimer.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "ms2/placeholder/uibuddyeventdispatcher.h"
#include "ms2/placeholder/cserverstring.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/commonfiles/taileffectdatatable.h"
#include "ms2/placeholder/costumesettable.h"
#include "ms2/commonfiles/dungeonmissiondatatable.h"
#include "ms2/placeholder/csoapclient.h"
#include "ms2/client/ms2/ugchomebgdata.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/client/ms2/uidungeoncategory.h"
#include "ms2/client/ms2/npsman.h"
#include "ms2/placeholder/recodemgr.h"
#include "ms2/commonfiles/trafficoptimizer.h"
#include "ms2/placeholder/cmasterymanager.h"
#include "ms2/placeholder/uiworldshareinfoeventdispatcher.h"
#include "ms2/commonfiles/learningquesttable.h"
#include "ms2/client/ms2/effectskipmgr.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/soundproperty.h"
#include "ms2/placeholder/clientlogmanager.h"
#include "ms2/client/ms2/usercommandcli.h"
#include "ms2/placeholder/uidialogeventdispatcher.h"
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <efdPhysX/PhysXSDKManager.h>   // C3: ms_pPhysXManager (was extern Unk_SingletonObj* DAT_143b05988)
#pragma pop_macro("max")
#pragma pop_macro("min")

// Typed prefix for the otherwise opaque getter objects.
struct Unk_ShutdownValue30 { void* m_opaque[6]; int m_value; };
MS2_CHECK_SIZE(Unk_ShutdownValue30, 0x38);
MS2_CHECK_OFFSET(Unk_ShutdownValue30, m_value, 0x30);

// ---- opaque singleton objects ---------------------------------------------------------------------------------------------
class Unk_SingletonObj { public: virtual ~Unk_SingletonObj(); };                                // deleted via slot 0
class Unk_SingletonObj1 { public: virtual void vfunc_0(); virtual ~Unk_SingletonObj1(); };      // deleted via slot 1 (0x1414a3df0)
class Unk_SubObj { public: virtual ~Unk_SubObj(); };
// Primary base has a vfptr but no virtual dtor, so delete dispatches through the Unk_SubObj vfptr at +0x140 (+0x80).
class Unk_Pad140 { public: virtual void Unk_V0(); char m_pad[0x138]; };
class Unk_SingletonObj140 : public Unk_Pad140, public Unk_SubObj { };
class Unk_Pad80 { public: virtual void Unk_V0(); char m_pad[0x78]; };
class Unk_SingletonObj80 : public Unk_Pad80, public Unk_SubObj { };

// the singleton classes the shutdown thunks clear (TSingleton<T>::s_instance; only the pointer is used)
class CDynamicBanWordManager;
class CJobConditionTable;
class CKeyTable;
class CLearningQuestTable;
class CLoadingDescriptionTable;
class CLoadingImageTable;
class CLocaleLanguage;
class CLogString;
class CLuaClient;
class CMachineIDManager;
class CMaidDescTable;
class CMaidExpTable;
class CMaidInfoTable;
class CMaidManufactureMsgTable;
class CMaidRecipeGroupTable;
class CMaidRecipeTable;
class CManufactureManager;
class CMasteryInteriorTable;
class CMasteryManager;
class CMasteryTable;
class CMenteeSearchManager;
class CMentoringManager;
class CMeratMarketMan;
class CMeratMarketPremium;
class CMesoMarketMan;
class CMicroGameManagerCli;
class CMouseController;
class CNPSMan;
class CNametagSymbolTable;
class CNiStreamLoadThread;
class COSInfo;
class COnlinePatchManagerCli;
class COptimizer;
class CPCEffectDummy;
class CPVPManager;
class CPartyManager;
class CPetDataTable;
class CPetManager;
class CPhysXHelper;
class CPopupProfileImageMan;
class CPortalTable;
class CPriceTable;
class CQuestManager;
class CQuestMaskTable;
class CQuestNavigationMap;
class CQuestNavigator;
class CQuestTable;
class CRankViewer;
class CRankingArenaDataTable;
class CReactorDataTable;
class CReconnectionManagerCli;
class CReservedWordTable;
class CRewardPreviewTable;
class CScriptTable;
class CSeasonDataTable;
class CServerListTable;
class CServerString;
class CShopCategoryTable;
class CShopEventManager;
class CSkillCompactControlTable;
class CSkillSetTable;
class CSmartPushManager;
class CSmartPushTable;
class CSmartRecommendShopTable;
class CSoapClient;
class CSoundDataTable;
class CSpecialDungeonDataTable;
class CSpecialEffectFunctionManager;
class CStoryBookTable;
class CStringTable;
class CTailEffectDataTable;
class CTaxiManager;
class CTitleTable;
class CTradeManagerEx;
class CTrafficOptimizer;
class CUGCDesignTable;
class CUGCMapSetItemTable;
class CUgcDownloadDown;
class CUgcDownloadLoad;
class CUgcGetCostTable;
class CUgcManager;
class CUserCommandCli;
class CUserEventManager;
class CUserMaidManager;
class CVIPTable;
class CameraMgr;
namespace Client { class Constants; }
class ClientLogManager;
class CommonEffectDummy;
class CommonResource;
class CommonString;
class CooltimeManager;
class CostumeSetTable;
class CrashManagerCli;
class CubeHolderManager;
class DungeonMissionDataTable;
class DungeonRoomTable;
class EffectDataManager;
class EffectSkipMgr;
class EngineLog;
class FieldWarDataTable;
class GPUManager;
class GameDictionaryManager;
class GameEventManagerCli;
class GameEventUserValueManager;
class HomeBlockManager;
class ItemDropTable;
class ItemPreviewMgr;
class JobTable;
class LoginBgBgmTable;
class MentoringDataTable;
class MultiSceneUpdater;
class NotifySystem;
class NpcDataTableCli;
class OnceCallbackTimer;
class PCActionDataTable;
class PacketHandlerManager;
class PaybackManagerClient;
class PaybackTable;
class QuestDataTable;
class RecodeMgr;
class RewardContentsTable;
class SetItemTable;
class SkillDataTableCli;
class SoundPropertyMgr;
class StanceTable;
class StateEffectMgr;
class StringManager;
class TermTagManagerCli;
class UGCCubeCategoryTable;
class UIBottomCenterAlignManager;
class UIBuddyEventDispatcher;
class UIDialogEventDispatcher;
class UIDungeonCategoryTable;
class UIEntityEventDispatcher;
class UIItemEventDispatcher;
class UIQuestEventDispatcher;
class UIServerEventDispatcher;
class UIStatusEventDispatcher;
class UITalkManager;
class UIUGCEventDispatcher;
class UIWorldShareInfoEventDispatcher;
class UgcHomeOptionData;
class WebGuideTable;
class WeddingEmotionTable;
class WeddingManager;
class WeddingTable;
class WorldMapManager;
// return types of the getters the shutdown thunks call
class CLocaleLanguage;
class CLogString;
class CMenteeSearchManager;
class CMentoringManager;
class CMeratMarketPremium;
class CMesoMarketMan;
class CPVPManager;
class CPartyManager;
class CQuestMaskTable;
class CQuestNavigationMap;
class CReconnectionManagerCli;
class CSmartPushTable;
class CSoundEventMgr;
class CTradeManagerEx;
class CVIPTable;
class CommonString;
class ItemDropTable;
class ItemGachaBoxTable;
class QuestDataTable;
class StringManager;
class UGCCubePalette;
class UIQuestEventDispatcher;
class Unk_140bccd50;
class Unk_AdditionalFlags;
class Unk_AvModeSvc;
class Unk_AvPhysicsSvc;
class Unk_BmPriceMgr;
class Unk_BonusBar;
class Unk_BreakSelected;
class Unk_GoDeviceInfo;
class Unk_Hud;
class Unk_InventoryListener;
class Unk_ItemPreview;
class Unk_ItemSlotTable;
class Unk_LsEntityEvents;
class Unk_MData;
class Unk_McPayback;
class Unk_MdBookTable;
class Unk_MeratButtonHelper;
class Unk_NpcTableCli;
class Unk_NtMgr;
class Unk_PcBangTable;
class Unk_PcFieldTable;
class Unk_PetRowTable;
class Unk_PriceTable;
class CQuestNavigator;
class Unk_RankTable;
class Unk_SoundSink;
class WeddingManager;
// the class's own unit defines s_instance / GetInstance out of line (explicit specializations): only declared here, so
// this obj does not instantiate a second copy (LNK2005 in the full-exe link)
template<> class TSingleton<CLogString> { public: static CLogString* s_instance; static CLogString* GetInstance(); };
template<> class TSingleton<CMachineIDManager> { public: static CMachineIDManager* s_instance; static CMachineIDManager* GetInstance(); };
template<> class TSingleton<CNiStreamLoadThread> { public: static CNiStreamLoadThread* s_instance; static CNiStreamLoadThread* GetInstance(); };
template<> class TSingleton<CPhysXHelper> { public: static CPhysXHelper* s_instance; static CPhysXHelper* GetInstance(); };
template<> class TSingleton<CReconnectionManagerCli> { public: static CReconnectionManagerCli* s_instance; static CReconnectionManagerCli* GetInstance(); };
template<> class TSingleton<CSoundEventMgr> { public: static CSoundEventMgr* s_instance; static CSoundEventMgr* GetInstance(); };
template<> class TSingleton<CTradeManagerEx> { public: static CTradeManagerEx* s_instance; static CTradeManagerEx* GetInstance(); };
template<> class TSingleton<Client::Constants> { public: static Client::Constants* s_instance; static Client::Constants* GetInstance(); };
template<> class TSingleton<CommonString> { public: static CommonString* s_instance; static CommonString* GetInstance(); };
template<> class TSingleton<GPUManager> { public: static GPUManager* s_instance; static GPUManager* GetInstance(); };
template<> class TSingleton<ItemGachaBoxTable> { public: static ItemGachaBoxTable* s_instance; static ItemGachaBoxTable* GetInstance(); };   // 0x143aaf1d0
template<class T> class SingletonClass { public: static T* ms_pSingleton; };
class GFxService;
struct Unk_NametagFlags;
// ---- exe globals (the singleton pointers) and getters of other units ----------------------------------------------------------
// PhysXSDKManager::ms_pPhysXManager is protected; this view reads it under its own name (0x143b05988).
struct Unk_PhysXSDKManagerStatics : efdPhysX::PhysXSDKManager { using efdPhysX::PhysXSDKManager::ms_pPhysXManager; };

CLogString* GetLogString();
class Unk_AdditionalFlags* GetStanceTable();   // C3: was GetStanceTable
class CLocaleLanguage* GetLocaleLanguage();   // C3: was GetLocaleLanguage
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
Unk_SingletonObj* GetCommonResource();
#define GetClientConstants() (reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))   // C3: was Unk_SingletonObj1* FUN_1401d3200()
class Unk_PetRowTable* GetPetDataTable();   // C3: was GetPetDataTable
// (C3: FUN_14052d230 = TSingleton<ItemGachaBoxTable>::GetInstance, itemgachaboxtable.h)
class Unk_BreakSelected* GetPetManager();   // C3: was GetPetManager
class Unk_PcBangTable* FUN_140541580();   // C3: was FUN_140541580
class CPriceTable* GetPriceTable();   // C3: was GetPriceTable
struct Unk_NametagFlags* FUN_1406c7610();   // C3: was FUN_1406c7610
class Unk_NpcTableCli* FUN_1406d6e90();   // C3: was FUN_1406d6e90
void* FUN_140764020();   // C3: was FUN_140764020
void* GetRewardContentsTable();   // C3: was GetRewardContentsTable
class Unk_SoundSink* GetKeyTable();   // C3: was GetKeyTable
CMasteryInteriorTable* GetMasteryInteriorTable();
class Unk_ItemSlotTable* GetTitleTable();   // C3: was GetTitleTable
class Unk_BonusBar* GetGameEventUserValueManager();   // C3: was GetGameEventUserValueManager
class Unk_Hud* GetUIServerEventDispatcher();   // C3: was GetUIServerEventDispatcher
Unk_SingletonObj* GetMeratMarketMan();
Unk_SingletonObj* FUN_140939a10();
class Unk_MData* FUN_1409670c0();   // C3: was FUN_1409670c0
class Unk_ItemPreview* GetItemPreviewMgr();   // C3: was GetItemPreviewMgr
class Unk_MeratButtonHelper* GetPaybackManager();   // C3: was GetPaybackManager
class Unk_AvModeSvc* GetOptimizer();   // C3: was GetOptimizer
class Unk_AvPhysicsSvc* GetPhysXHelper();   // C3: was GetPhysXHelper
class Unk_InventoryListener* GetItemEventDispatcher();   // C3: was GetItemEventDispatcher
void* GetMachineIDManager();   // C3: was GetMachineIDManager
Unk_SingletonObj* GetWeddingEmotionTable();
class Unk_140bccd50* GetPacketHandlerManager();   // C3: was FUN_140bccd50
class UIQuestEventDispatcher* FUN_140bfc4b0();   // C3: was FUN_140bfc4b0
void* GetUIBottomCenterAlignManager();   // C3: was FUN_140c24ef0
class Unk_LsEntityEvents* FUN_140c607b0();   // C3: was FUN_140c607b0
class CQuestNavigationMap* GetQuestNavigationMap();   // C3: was GetQuestNavigationMap
class Unk_PcFieldTable* GetWorldMapManager();   // C3: was GetWorldMapManager
Unk_SingletonObj* GetSmartPushManager();
class Unk_RankTable* GetRankingArenaDataTable();   // C3: was GetRankingArenaDataTable
class CQuestNavigator* GetQuestNavigator();   // C3: was GetQuestNavigator
// (C3: FUN_140e800e0 = TSingleton<CReconnectionManagerCli>::GetInstance, reconnectionmanagercli.h)
class Unk_McPayback* GetUgcGetCostTable();   // C3: was GetUgcGetCostTable
UGCCubePalette* GetUGCCubePalette();
Unk_SingletonObj* GetRewardPreviewTable();
class CVIPTable* FUN_140fb9980();   // C3: was FUN_140fb9980
StringManager* GetStringManager();
class CCooltimeManager   // C3: member view for the former free stand-ins
{
public:
    static class CCooltimeManager* GetInstance();
};
// (C3: FUN_141245b20 = TSingleton<GPUManager>::GetInstance, gpumanager.h)
class Unk_MdBookTable* GetMaidRecipeGroupTable();   // C3: was GetMaidRecipeGroupTable
class Unk_NtMgr* GetNametagSymbolTable();   // C3: was GetNametagSymbolTable
class Unk_RecommendCache   // C3: member view for the former free stand-ins
{
public:
    static class Unk_RecommendCache* GetSmartRecommendShopTable();
};
void* FUN_141371b30();   // C3: was FUN_141371b30
// ---- in-unit getters (defined below)
GFxService* GetGFxService();
Unk_SingletonObj* FUN_1414a56d0();
Unk_SingletonObj* FUN_1414a56e0();
Unk_SingletonObj* FUN_1414a56f0();
Unk_SingletonObj* FUN_1414a5700();
Unk_SingletonObj* FUN_1414a5710();
Unk_SingletonObj* FUN_1414a5730();
Unk_SingletonObj* FUN_1414a5740();
Unk_SingletonObj* FUN_1414a5750();
Unk_SingletonObj* FUN_1414a5760();
Unk_SingletonObj* FUN_1414a5770();
Unk_SingletonObj* FUN_1414a5780();
Unk_SingletonObj* FUN_1414a5790();
Unk_SingletonObj* FUN_1414a57a0();
Unk_SingletonObj* FUN_1414a57b0();
Unk_SingletonObj* FUN_1414a57c0();
Unk_SingletonObj* FUN_1414a57d0();
Unk_SingletonObj* FUN_1414a57e0();
Unk_SingletonObj* FUN_1414a57f0();
Unk_SingletonObj* FUN_1414a5800();
Unk_SingletonObj* GetEngineLog();
Unk_SingletonObj* GetFieldWarDataTable();
Unk_SingletonObj* GetHomeBlockManager();
Unk_SingletonObj* GetLoginBgBgmTable();
Unk_SingletonObj* GetMultiSceneUpdater();
Unk_SingletonObj* GetPCActionDataTable();
Unk_SingletonObj* GetStateEffectMgr();
Unk_SingletonObj80* GetWebGuideTable();
Unk_SingletonObj* GetPhysXManager();
class Unk_MiscThis {
public:
    unsigned long long FUN_1414a55e0(); unsigned long long FUN_1414a55f0(); unsigned long long FUN_1414a5600(); void* FUN_1414a5640(); int* FUN_1414a5650(); int* FUN_1414a5660();
};
// ---- misc externs ---------------------------------------------------------------------------------------------------------
extern int DAT_143ae2b48;   // (0x143a284b0 = egmVisualizers::PropertyVisualizationService::ms_ClassInfo)
#include <NiMaterialSwapProcessor.h>   // C3: was struct CResultObj (a view of NiMaterialSwapProcessorPtr)
class NiShadowManager { protected: static NiShadowManager* ms_pkShadowManager; friend NiMaterialSwapProcessorPtr GetMaterialSwapProcessor(int idx); };
#define DAT_143afa980 (*reinterpret_cast<char**>(&NiShadowManager::ms_pkShadowManager))   // C3: was extern char* DAT_143afa980
// (0x1414a54f0 is the real Unk_GFxImageHandler::Clone, below)
void* FUN_140c8f690(const efd::SmartPointer<class NiViewRenderClick>&);   // C3: was FUN_140c8f690
class NiMaterial; class NiTexture;
// The five CAtlMap::RemoveAll COMDATs below (and their Disable/EnableAutoRehash) belong to CReactorDataTable's and
// CArcadeDataTable's maps; FreeNode, IsLocked, PickSize, InitHashTable and FreePlexes are the COMDATs of those tables'
// units, declared here as explicit specializations so this unit does not carry copies of them.
template <> void ATL::CAtlMap<int, MS2Ptr<ReactorData> >::FreeNode(CNode* pNode);
template <> bool ATL::CAtlMap<int, MS2Ptr<ReactorData> >::IsLocked() const throw();
template <> UINT ATL::CAtlMap<int, MS2Ptr<ReactorData> >::PickSize(size_t nElements) const throw();
template <> bool ATL::CAtlMap<int, MS2Ptr<ReactorData> >::InitHashTable(UINT nBins, bool bAllocNow);
template <> void ATL::CAtlMap<int, MS2Ptr<ReactorData> >::FreePlexes() throw();
template <> void ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::FreeNode(CNode* pNode);
template <> bool ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::IsLocked() const throw();
template <> UINT ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::PickSize(size_t nElements) const throw();
template <> bool ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::InitHashTable(UINT nBins, bool bAllocNow);
template <> void ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::FreePlexes() throw();
template <> void ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::FreeNode(CNode* pNode);
template <> bool ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::IsLocked() const throw();
template <> UINT ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::PickSize(size_t nElements) const throw();
template <> bool ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::InitHashTable(UINT nBins, bool bAllocNow);
template <> void ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::FreePlexes() throw();
template <> void ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::FreeNode(CNode* pNode);
template <> bool ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::IsLocked() const throw();
template <> UINT ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::PickSize(size_t nElements) const throw();
template <> bool ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::InitHashTable(UINT nBins, bool bAllocNow);
template <> void ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::FreePlexes() throw();
template <> void ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::FreeNode(CNode* pNode);
template <> bool ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::IsLocked() const throw();
template <> UINT ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::PickSize(size_t nElements) const throw();
template <> bool ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::InitHashTable(UINT nBins, bool bAllocNow);
template <> void ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::FreePlexes() throw();

// @0x1414a1c30
void FUN_1414a1c30()
{
    if (TSingleton<CJobConditionTable>::s_instance != 0) {
        delete FUN_1414a56e0();
        TSingleton<CJobConditionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1C30, FUN_1414a1c30, 94, 0x5D047549);
// @0x1414a1c90
void FUN_1414a1c90()
{
    if (TSingleton<CKeyTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetKeyTable()));
        TSingleton<CKeyTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1C90, FUN_1414a1c90, 94, 0x5F0E2522);
// @0x1414a1cf0
void FUN_1414a1cf0()
{
    if (TSingleton<CLearningQuestTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CLearningQuestTable>::GetInstance());
        TSingleton<CLearningQuestTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1CF0, FUN_1414a1cf0, 94, 0x38EC75AE);
// @0x1414a1d50
void FUN_1414a1d50()
{
    if (TSingleton<CLoadingDescriptionTable>::s_instance != 0) {
        delete FUN_1414a56f0();
        TSingleton<CLoadingDescriptionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1D50, FUN_1414a1d50, 94, 0xCB3F4CBD);
// @0x1414a1db0
void FUN_1414a1db0()
{
    if (TSingleton<CLoadingImageTable>::s_instance != 0) {
        delete FUN_1414a5700();
        TSingleton<CLoadingImageTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1DB0, FUN_1414a1db0, 94, 0x2FE8C8DA);
// @0x1414a1e10
void FUN_1414a1e10()
{
    if (TSingleton<CLocaleLanguage>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetLocaleLanguage()));
        TSingleton<CLocaleLanguage>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1E10, FUN_1414a1e10, 94, 0x06CE8805);
// @0x1414a1e70
void FUN_1414a1e70()
{
    if (TSingleton<CLogString>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(GetLogString());
        TSingleton<CLogString>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1E70, FUN_1414a1e70, 94, 0x670F1EE5);
// @0x1414a1ed0
void FUN_1414a1ed0()
{
    if (TSingleton<CLuaClient>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_1401c0db0()));
        TSingleton<CLuaClient>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1ED0, FUN_1414a1ed0, 94, 0xE5A6F238);
// @0x1414a1f30
void FUN_1414a1f30()
{
    if (TSingleton<CMachineIDManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetMachineIDManager()));
        TSingleton<CMachineIDManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1F30, FUN_1414a1f30, 94, 0xE0475430);
// @0x1414a1f90
void FUN_1414a1f90()
{
    if (TSingleton<CMaidDescTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMaidDescTable>::GetInstance());
        TSingleton<CMaidDescTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1F90, FUN_1414a1f90, 94, 0x9A1392E9);
// @0x1414a1ff0
void FUN_1414a1ff0()
{
    if (TSingleton<CMaidExpTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMaidExpTable>::GetInstance());
        TSingleton<CMaidExpTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1FF0, FUN_1414a1ff0, 94, 0xCAB7A503);
// @0x1414a2050
void FUN_1414a2050()
{
    if (TSingleton<CMaidInfoTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMaidInfoTable>::GetInstance());
        TSingleton<CMaidInfoTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2050, FUN_1414a2050, 94, 0x5C9BCF69);
// @0x1414a20b0
void FUN_1414a20b0()
{
    if (TSingleton<CMaidManufactureMsgTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMaidManufactureMsgTable>::GetInstance());
        TSingleton<CMaidManufactureMsgTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A20B0, FUN_1414a20b0, 94, 0xDFFD19A9);
// @0x1414a2110
void FUN_1414a2110()
{
    if (TSingleton<CMaidRecipeGroupTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetMaidRecipeGroupTable()));
        TSingleton<CMaidRecipeGroupTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2110, FUN_1414a2110, 94, 0xA6232421);
// @0x1414a2170
void FUN_1414a2170()
{
    if (TSingleton<CMaidRecipeTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMaidRecipeTable>::GetInstance());
        TSingleton<CMaidRecipeTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2170, FUN_1414a2170, 94, 0x27944BBC);
// @0x1414a21d0
void FUN_1414a21d0()
{
    if (TSingleton<CManufactureManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CManufactureManager>::GetInstance());
        TSingleton<CManufactureManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A21D0, FUN_1414a21d0, 94, 0x7FDD7164);
// @0x1414a2230
void FUN_1414a2230()
{
    if (TSingleton<CMasteryInteriorTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetMasteryInteriorTable()));
        TSingleton<CMasteryInteriorTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2230, FUN_1414a2230, 94, 0xD5C92767);
// @0x1414a2290
void FUN_1414a2290()
{
    if (TSingleton<CMasteryManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMasteryManager>::GetInstance());
        TSingleton<CMasteryManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2290, FUN_1414a2290, 94, 0xC025FFEE);
// @0x1414a22f0
void FUN_1414a22f0()
{
    if (TSingleton<CMasteryTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_1409670c0()));
        TSingleton<CMasteryTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A22F0, FUN_1414a22f0, 94, 0x658FD221);
// @0x1414a2350
void FUN_1414a2350()
{
    if (TSingleton<CMenteeSearchManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMenteeSearchManager>::GetInstance());
        TSingleton<CMenteeSearchManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2350, FUN_1414a2350, 94, 0x73FAC6CE);
// @0x1414a23b0
void FUN_1414a23b0()
{
    if (TSingleton<CMentoringManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMentoringManager>::GetInstance());
        TSingleton<CMentoringManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A23B0, FUN_1414a23b0, 94, 0x70469E1B);
// @0x1414a2410
void FUN_1414a2410()
{
    if (TSingleton<CMeratMarketMan>::s_instance != 0) {
        delete GetMeratMarketMan();
        TSingleton<CMeratMarketMan>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2410, FUN_1414a2410, 94, 0xEC6E0E4E);
// @0x1414a2470
void FUN_1414a2470()
{
    if (TSingleton<CMeratMarketPremium>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMeratMarketPremium>::GetInstance());
        TSingleton<CMeratMarketPremium>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2470, FUN_1414a2470, 94, 0xD6A98232);
// @0x1414a24d0
void FUN_1414a24d0()
{
    if (TSingleton<CMesoMarketMan>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMesoMarketMan>::GetInstance());
        TSingleton<CMesoMarketMan>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A24D0, FUN_1414a24d0, 94, 0x0C227F71);
// @0x1414a2530
void FUN_1414a2530()
{
    if (TSingleton<CMicroGameManagerCli>::s_instance != 0) {
        delete FUN_1414a5710();
        TSingleton<CMicroGameManagerCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2530, FUN_1414a2530, 94, 0xCDA6DDFA);
// @0x1414a2590
void FUN_1414a2590()
{
    if (TSingleton<CMouseController>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMouseController>::GetInstance());
        TSingleton<CMouseController>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2590, FUN_1414a2590, 94, 0x21B5BA98);
// @0x1414a25f0
void FUN_1414a25f0()
{
    if (TSingleton<CNPSMan>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CNPSMan>::GetInstance());
        TSingleton<CNPSMan>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A25F0, FUN_1414a25f0, 94, 0x7FEBD5CE);
// @0x1414a2650
void FUN_1414a2650()
{
    if (TSingleton<CNametagSymbolTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetNametagSymbolTable()));
        TSingleton<CNametagSymbolTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2650, FUN_1414a2650, 94, 0xA327B3AF);
// @0x1414a26b0
void FUN_1414a26b0()
{
    if (TSingleton<CNiStreamLoadThread>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CNiStreamLoadThread>::GetInstance());
        TSingleton<CNiStreamLoadThread>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A26B0, FUN_1414a26b0, 94, 0xF4B59DEF);
// @0x1414a2710
void FUN_1414a2710()
{
    if (TSingleton<COSInfo>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<COSInfo>::GetInstance());
        TSingleton<COSInfo>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2710, FUN_1414a2710, 94, 0x0F17A306);
// @0x1414a2770
void FUN_1414a2770()
{
    if (TSingleton<COnlinePatchManagerCli>::s_instance != 0) {
        delete FUN_1414a5730();
        TSingleton<COnlinePatchManagerCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2770, FUN_1414a2770, 94, 0xF22A46B0);
// @0x1414a27d0
void FUN_1414a27d0()
{
    if (TSingleton<COptimizer>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetOptimizer()));
        TSingleton<COptimizer>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A27D0, FUN_1414a27d0, 94, 0xDE0809E3);
// @0x1414a2830
void FUN_1414a2830()
{
    if (TSingleton<CPCEffectDummy>::s_instance != 0) {
        delete FUN_1414a5740();
        TSingleton<CPCEffectDummy>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2830, FUN_1414a2830, 94, 0x1408F048);
// @0x1414a2890
void FUN_1414a2890()
{
    if (TSingleton<CPVPManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CPVPManager>::GetInstance());
        TSingleton<CPVPManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2890, FUN_1414a2890, 94, 0xE0594503);
// @0x1414a28f0
void FUN_1414a28f0()
{
    if (TSingleton<CPartyManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CPartyManager>::GetInstance());
        TSingleton<CPartyManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A28F0, FUN_1414a28f0, 94, 0xA7D7656B);
// @0x1414a2950
void FUN_1414a2950()
{
    if (TSingleton<CPetDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetPetDataTable()));
        TSingleton<CPetDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2950, FUN_1414a2950, 94, 0x2262C580);
// @0x1414a29b0
void FUN_1414a29b0()
{
    if (TSingleton<CPetManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetPetManager()));
        TSingleton<CPetManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A29B0, FUN_1414a29b0, 94, 0x213EEB3E);
// @0x1414a2a10
void FUN_1414a2a10()
{
    if (TSingleton<CPhysXHelper>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetPhysXHelper()));
        TSingleton<CPhysXHelper>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2A10, FUN_1414a2a10, 94, 0x3FA8C3C1);
// @0x1414a2a70
void FUN_1414a2a70()
{
    if (TSingleton<CPopupProfileImageMan>::s_instance != 0) {
        delete FUN_1414a5750();
        TSingleton<CPopupProfileImageMan>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2A70, FUN_1414a2a70, 94, 0xF938B626);
// @0x1414a2ad0
void FUN_1414a2ad0()
{
    if (TSingleton<CPortalTable>::s_instance != 0) {
        delete FUN_1414a5760();
        TSingleton<CPortalTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2AD0, FUN_1414a2ad0, 94, 0xEF432CFB);
// @0x1414a2b30
void FUN_1414a2b30()
{
    if (TSingleton<CPriceTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetPriceTable()));
        TSingleton<CPriceTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2B30, FUN_1414a2b30, 94, 0x42CD3A87);
// @0x1414a2b90
void FUN_1414a2b90()
{
    if (TSingleton<CQuestManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_140764020()));
        TSingleton<CQuestManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2B90, FUN_1414a2b90, 94, 0x7296AF54);
// @0x1414a2bf0
void FUN_1414a2bf0()
{
    if (TSingleton<CQuestMaskTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CQuestMaskTable>::GetInstance());
        TSingleton<CQuestMaskTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2BF0, FUN_1414a2bf0, 94, 0x8971EF9E);
// @0x1414a2c50
void FUN_1414a2c50()
{
    if (TSingleton<CQuestNavigationMap>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetQuestNavigationMap()));
        TSingleton<CQuestNavigationMap>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2C50, FUN_1414a2c50, 94, 0x0496A4FD);
// @0x1414a2cb0
void FUN_1414a2cb0()
{
    if (TSingleton<CQuestNavigator>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetQuestNavigator()));
        TSingleton<CQuestNavigator>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2CB0, FUN_1414a2cb0, 94, 0xF0CFCCF6);
// @0x1414a2d10
void FUN_1414a2d10()
{
    if (TSingleton<CQuestTable>::s_instance != 0) {
        delete FUN_1414a5770();
        TSingleton<CQuestTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2D10, FUN_1414a2d10, 94, 0x1244F2CA);
// @0x1414a2d70
void FUN_1414a2d70()
{
    if (TSingleton<CRankViewer>::s_instance != 0) {
        delete FUN_1414a5780();
        TSingleton<CRankViewer>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2D70, FUN_1414a2d70, 94, 0x3B1D802E);
// @0x1414a2dd0
void FUN_1414a2dd0()
{
    if (TSingleton<CRankingArenaDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetRankingArenaDataTable()));
        TSingleton<CRankingArenaDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2DD0, FUN_1414a2dd0, 94, 0xEDF53850);
// @0x1414a2e30
void FUN_1414a2e30()
{
    if (TSingleton<CReactorDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CReactorDataTable>::GetInstance());
        TSingleton<CReactorDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2E30, FUN_1414a2e30, 94, 0x8854C121);
// @0x1414a2e90
void FUN_1414a2e90()
{
    if (TSingleton<CReconnectionManagerCli>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)TSingleton<CReconnectionManagerCli>::GetInstance()));
        TSingleton<CReconnectionManagerCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2E90, FUN_1414a2e90, 94, 0x32132896);
// @0x1414a2ef0
void FUN_1414a2ef0()
{
    if (TSingleton<CReservedWordTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CReservedWordTable>::GetInstance());
        TSingleton<CReservedWordTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2EF0, FUN_1414a2ef0, 94, 0x63475792);
// @0x1414a2f50
void FUN_1414a2f50()
{
    if (TSingleton<CRewardPreviewTable>::s_instance != 0) {
        delete GetRewardPreviewTable();
        TSingleton<CRewardPreviewTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2F50, FUN_1414a2f50, 94, 0x23151BB2);
// @0x1414a2fb0
void FUN_1414a2fb0()
{
    if (TSingleton<CScriptTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_141371b30()));
        TSingleton<CScriptTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A2FB0, FUN_1414a2fb0, 94, 0xDB010B03);
// @0x1414a3010
void FUN_1414a3010()
{
    if (TSingleton<CSeasonDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSeasonDataTable>::GetInstance());
        TSingleton<CSeasonDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3010, FUN_1414a3010, 94, 0x7BD2310F);
// @0x1414a3070
void FUN_1414a3070()
{
    if (TSingleton<CServerListTable>::s_instance != 0) {
        delete FUN_1414a5790();
        TSingleton<CServerListTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3070, FUN_1414a3070, 94, 0xAB9DE9C9);
// @0x1414a30d0
void FUN_1414a30d0()
{
    if (TSingleton<CServerString>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CServerString>::GetInstance());
        TSingleton<CServerString>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A30D0, FUN_1414a30d0, 94, 0xAD0A4637);
// @0x1414a3130
void FUN_1414a3130()
{
    if (TSingleton<CShopCategoryTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CShopCategoryTable>::GetInstance());
        TSingleton<CShopCategoryTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3130, FUN_1414a3130, 94, 0x05CC0E62);
// @0x1414a3190
void FUN_1414a3190()
{
    if (TSingleton<CShopEventManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CShopEventManager>::GetInstance());
        TSingleton<CShopEventManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3190, FUN_1414a3190, 94, 0x793C4AFD);
// @0x1414a31f0
void FUN_1414a31f0()
{
    if (TSingleton<CSkillCompactControlTable>::s_instance != 0) {
        delete FUN_1414a57a0();
        TSingleton<CSkillCompactControlTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A31F0, FUN_1414a31f0, 94, 0x444F494A);
// @0x1414a3250
void FUN_1414a3250()
{
    if (TSingleton<CSkillSetTable>::s_instance != 0) {
        delete FUN_1414a57b0();
        TSingleton<CSkillSetTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3250, FUN_1414a3250, 94, 0x3CBF46EE);
// @0x1414a32b0
void FUN_1414a32b0()
{
    if (TSingleton<CSmartPushManager>::s_instance != 0) {
        delete GetSmartPushManager();
        TSingleton<CSmartPushManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A32B0, FUN_1414a32b0, 94, 0xD0C912A5);
// @0x1414a3310
void FUN_1414a3310()
{
    if (TSingleton<CSmartPushTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSmartPushTable>::GetInstance());
        TSingleton<CSmartPushTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3310, FUN_1414a3310, 94, 0x57813219);
// @0x1414a3370
void FUN_1414a3370()
{
    if (TSingleton<CSmartRecommendShopTable>::s_instance != 0) {
        delete ((class Unk_SingletonObj*)Unk_RecommendCache::GetSmartRecommendShopTable());
        TSingleton<CSmartRecommendShopTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3370, FUN_1414a3370, 94, 0xD98601C2);
// @0x1414a33d0
void FUN_1414a33d0()
{
    if (TSingleton<CSoapClient>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSoapClient>::GetInstance());
        TSingleton<CSoapClient>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A33D0, FUN_1414a33d0, 94, 0xD2E6055A);
// @0x1414a3430
void FUN_1414a3430()
{
    if (TSingleton<CSoundDataTable>::s_instance != 0) {
        delete FUN_1414a57c0();
        TSingleton<CSoundDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3430, FUN_1414a3430, 94, 0xF8F04190);
// @0x1414a3490
void FUN_1414a3490()
{
    if (TSingleton<CSoundEventMgr>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSoundEventMgr>::GetInstance());
        TSingleton<CSoundEventMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3490, FUN_1414a3490, 94, 0xCD8ED2A6);
// @0x1414a34f0
void FUN_1414a34f0()
{
    if (TSingleton<CSpecialDungeonDataTable>::s_instance != 0) {
        delete FUN_1414a57d0();
        TSingleton<CSpecialDungeonDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A34F0, FUN_1414a34f0, 94, 0x702DF741);
// @0x1414a3550
void FUN_1414a3550()
{
    if (TSingleton<CSpecialEffectFunctionManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSpecialEffectFunctionManager>::GetInstance());
        TSingleton<CSpecialEffectFunctionManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3550, FUN_1414a3550, 94, 0x371777FF);
// @0x1414a35b0
void FUN_1414a35b0()
{
    if (TSingleton<CStoryBookTable>::s_instance != 0) {
        delete FUN_1414a57e0();
        TSingleton<CStoryBookTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A35B0, FUN_1414a35b0, 94, 0x44476E8D);
// @0x1414a3610
void FUN_1414a3610()
{
    if (TSingleton<CStringTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CStringTable>::GetInstance());
        TSingleton<CStringTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3610, FUN_1414a3610, 94, 0x88FFB246);
// @0x1414a3670
void FUN_1414a3670()
{
    if (TSingleton<CTailEffectDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CTailEffectDataTable>::GetInstance());
        TSingleton<CTailEffectDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3670, FUN_1414a3670, 94, 0x4F112A91);
// @0x1414a36d0
void FUN_1414a36d0()
{
    if (TSingleton<CTaxiManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CTaxiManager>::GetInstance());
        TSingleton<CTaxiManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A36D0, FUN_1414a36d0, 94, 0xABC65B61);
// @0x1414a3730
void FUN_1414a3730()
{
    if (TSingleton<CTitleTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetTitleTable()));
        TSingleton<CTitleTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3730, FUN_1414a3730, 94, 0xE64E015A);
// @0x1414a3790
void FUN_1414a3790()
{
    if (TSingleton<CTradeManagerEx>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CTradeManagerEx>::GetInstance());
        TSingleton<CTradeManagerEx>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3790, FUN_1414a3790, 94, 0xC59A7510);
// @0x1414a37f0
void FUN_1414a37f0()
{
    if (TSingleton<CTrafficOptimizer>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CTrafficOptimizer>::GetInstance());
        TSingleton<CTrafficOptimizer>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A37F0, FUN_1414a37f0, 94, 0xE084A75C);
// @0x1414a3850
void FUN_1414a3850()
{
    if (TSingleton<CUGCDesignTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CUGCDesignTable>::GetInstance());
        TSingleton<CUGCDesignTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3850, FUN_1414a3850, 94, 0xF2260634);
// @0x1414a38b0
void FUN_1414a38b0()
{
    if (TSingleton<CUGCMapSetItemTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CUGCMapSetItemTable>::GetInstance());
        TSingleton<CUGCMapSetItemTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A38B0, FUN_1414a38b0, 94, 0x41A8B8C8);
// @0x1414a3910
void FUN_1414a3910()
{
    if (TSingleton<CUgcDownloadDown>::s_instance != 0) {
        delete FUN_1414a57f0();
        TSingleton<CUgcDownloadDown>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3910, FUN_1414a3910, 94, 0xC21544C6);
// @0x1414a3970
void FUN_1414a3970()
{
    if (TSingleton<CUgcDownloadLoad>::s_instance != 0) {
        delete FUN_1414a5800();
        TSingleton<CUgcDownloadLoad>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3970, FUN_1414a3970, 94, 0xDD4A3579);
// @0x1414a39d0
void FUN_1414a39d0()
{
    if (TSingleton<CUgcGetCostTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetUgcGetCostTable()));
        TSingleton<CUgcGetCostTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A39D0, FUN_1414a39d0, 94, 0x78B3D6DC);
// @0x1414a3a30
void FUN_1414a3a30()
{
    if (TSingleton<CUgcManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)TSingleton<CUgcManager>::GetInstance()));
        TSingleton<CUgcManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3A30, FUN_1414a3a30, 94, 0x8581D2D7);
// @0x1414a3a90
void FUN_1414a3a90()
{
    if (TSingleton<CUserCommandCli>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CUserCommandCli>::GetInstance());
        TSingleton<CUserCommandCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3A90, FUN_1414a3a90, 94, 0x43C76F10);
// @0x1414a3af0
void FUN_1414a3af0()
{
    if (TSingleton<CUserEventManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CUserEventManager>::GetInstance());
        TSingleton<CUserEventManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3AF0, FUN_1414a3af0, 94, 0x98C9C077);
// @0x1414a3b50
void FUN_1414a3b50()
{
    if (TSingleton<CUserMaidManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CUserMaidManager>::GetInstance());
        TSingleton<CUserMaidManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3B50, FUN_1414a3b50, 94, 0x484FE139);
// @0x1414a3bb0
void FUN_1414a3bb0()
{
    if (TSingleton<CVIPTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_140fb9980()));
        TSingleton<CVIPTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3BB0, FUN_1414a3bb0, 94, 0xA273971A);
// @0x1414a3c10
void DestroyCameraMgr()
{
    if (TSingleton<CameraMgr>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CameraMgr>::GetInstance());
        TSingleton<CameraMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3C10, DestroyCameraMgr, 94, 0x7EC97F36);
// @0x1414a3c70
void DestroyClientLogManager()
{
    if (TSingleton<ClientLogManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<ClientLogManager>::GetInstance());
        TSingleton<ClientLogManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3C70, DestroyClientLogManager, 94, 0x10A5FB83);
// @0x1414a3cd0
void DestroyCommonEffectDummy()
{
    if (TSingleton<CommonEffectDummy>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CommonEffectDummy>::GetInstance());
        TSingleton<CommonEffectDummy>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3CD0, DestroyCommonEffectDummy, 94, 0x424E3052);
// @0x1414a3d30
void DestroyCommonResource()
{
    if (TSingleton<CommonResource>::s_instance != 0) {
        delete GetCommonResource();
        TSingleton<CommonResource>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3D30, DestroyCommonResource, 94, 0x2B2DA0BB);
// @0x1414a3d90
void DestroyCommonString()
{
    if (TSingleton<CommonString>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)TSingleton<CommonString>::GetInstance()));
        TSingleton<CommonString>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3D90, DestroyCommonString, 94, 0x6EEE7143);
// @0x1414a3df0
void FUN_1414a3df0()
{
    if (TSingleton<Client::Constants>::s_instance != 0) {
        delete GetClientConstants();
        TSingleton<Client::Constants>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3DF0, FUN_1414a3df0, 95, 0x2F862E4F);
// @0x1414a3e50
void DestroyCooltimeManager()
{
    if (TSingleton<CooltimeManager>::s_instance != 0) {
        delete ((class Unk_SingletonObj*)CCooltimeManager::GetInstance());
        TSingleton<CooltimeManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3E50, DestroyCooltimeManager, 94, 0x3CD3859F);
// @0x1414a3eb0
void DestroyCostumeSetTable()
{
    if (TSingleton<CostumeSetTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CostumeSetTable>::GetInstance());
        TSingleton<CostumeSetTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3EB0, DestroyCostumeSetTable, 94, 0x994256D1);
// @0x1414a3f10
void DestroyCrashManagerCli()
{
    if (TSingleton<CrashManagerCli>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<CrashManagerCli>::GetInstance());
        TSingleton<CrashManagerCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3F10, DestroyCrashManagerCli, 94, 0xF19B752C);
// @0x1414a3f70
void DestroyCubeHolderManager()
{
    if (TSingleton<CubeHolderManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(GetUGCCubePalette());
        TSingleton<CubeHolderManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3F70, DestroyCubeHolderManager, 94, 0x128A9E27);
// @0x1414a3fd0
void DestroyDungeonMissionDataTable()
{
    if (TSingleton<DungeonMissionDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<DungeonMissionDataTable>::GetInstance());
        TSingleton<DungeonMissionDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A3FD0, DestroyDungeonMissionDataTable, 94, 0xBC1EF21F);
// @0x1414a4030
void DestroyDungeonRoomTable()
{
    if (TSingleton<DungeonRoomTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<DungeonRoomTable>::GetInstance());
        TSingleton<DungeonRoomTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4030, DestroyDungeonRoomTable, 94, 0xF4AA19C6);
// @0x1414a4090
void DestroyEffectDataManager()
{
    if (TSingleton<EffectDataManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<EffectDataManager>::GetInstance());
        TSingleton<EffectDataManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4090, DestroyEffectDataManager, 94, 0x4134B3DD);
// @0x1414a40f0
void DestroyEffectSkipMgr()
{
    if (TSingleton<EffectSkipMgr>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<EffectSkipMgr>::GetInstance());
        TSingleton<EffectSkipMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A40F0, DestroyEffectSkipMgr, 94, 0x9787CD5A);
// @0x1414a4150
void DestroyEngineLog()
{
    if (TSingleton<EngineLog>::s_instance != 0) {
        delete GetEngineLog();
        TSingleton<EngineLog>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4150, DestroyEngineLog, 94, 0xF9201881);
// @0x1414a41b0
void DestroyFieldWarDataTable()
{
    if (TSingleton<FieldWarDataTable>::s_instance != 0) {
        delete GetFieldWarDataTable();
        TSingleton<FieldWarDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A41B0, DestroyFieldWarDataTable, 94, 0x37405945);
// @0x1414a4210
void DestroyGPUManager()
{
    if (TSingleton<GPUManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)TSingleton<GPUManager>::GetInstance()));
        TSingleton<GPUManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4210, DestroyGPUManager, 94, 0xAA0F2CF3);
// @0x1414a4270
void DestroyGameDictionaryManager()
{
    if (TSingleton<GameDictionaryManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_140541580()));
        TSingleton<GameDictionaryManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4270, DestroyGameDictionaryManager, 94, 0xC6F92785);
// @0x1414a42d0
void DestroyGameEventManagerCli()
{
    if (TSingleton<GameEventManagerCli>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<GameEventManagerCli>::GetInstance());
        TSingleton<GameEventManagerCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A42D0, DestroyGameEventManagerCli, 94, 0xFCAB6435);
// @0x1414a4330
void DestroyGameEventUserValueManager()
{
    if (TSingleton<GameEventUserValueManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetGameEventUserValueManager()));
        TSingleton<GameEventUserValueManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4330, DestroyGameEventUserValueManager, 94, 0x0EB0AC8E);
// @0x1414a4390
void DestroyHomeBlockManager()
{
    if (TSingleton<HomeBlockManager>::s_instance != 0) {
        delete GetHomeBlockManager();
        TSingleton<HomeBlockManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4390, DestroyHomeBlockManager, 94, 0x33E83678);
// @0x1414a43f0
void DestroyItemDropTable()
{
    if (TSingleton<ItemDropTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<ItemDropTable>::GetInstance());
        TSingleton<ItemDropTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A43F0, DestroyItemDropTable, 94, 0x0E6BA856);
// @0x1414a4450
void DestroyItemGachaBoxTable()
{
    if (TSingleton<ItemGachaBoxTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)TSingleton<ItemGachaBoxTable>::GetInstance()));
        TSingleton<ItemGachaBoxTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4450, DestroyItemGachaBoxTable, 94, 0x87DBB161);
// @0x1414a44b0
void DestroyItemPreviewMgr()
{
    if (TSingleton<ItemPreviewMgr>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetItemPreviewMgr()));
        TSingleton<ItemPreviewMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A44B0, DestroyItemPreviewMgr, 94, 0x23986293);
// @0x1414a4510
void DestroyJobTable()
{
    if (TSingleton<JobTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<JobTable>::GetInstance());
        TSingleton<JobTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4510, DestroyJobTable, 94, 0x879E4000);
// @0x1414a4570
void DestroyLoginBgBgmTable()
{
    if (TSingleton<LoginBgBgmTable>::s_instance != 0) {
        delete GetLoginBgBgmTable();
        TSingleton<LoginBgBgmTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4570, DestroyLoginBgBgmTable, 94, 0x6819E981);
// @0x1414a45d0
void DestroyMentoringDataTable()
{
    if (TSingleton<MentoringDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_1406c7610()));
        TSingleton<MentoringDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A45D0, DestroyMentoringDataTable, 94, 0xF6EDF752);
// @0x1414a4630
void DestroyMultiSceneUpdater()
{
    if (TSingleton<MultiSceneUpdater>::s_instance != 0) {
        delete GetMultiSceneUpdater();
        TSingleton<MultiSceneUpdater>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4630, DestroyMultiSceneUpdater, 94, 0x30110431);
// @0x1414a4690
void DestroyNotifySystem()
{
    if (TSingleton<NotifySystem>::s_instance != 0) {
        delete FUN_140939a10();
        TSingleton<NotifySystem>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4690, DestroyNotifySystem, 94, 0xF88364D7);
// @0x1414a46f0
void DestroyNpcDataTableCli()
{
    if (TSingleton<NpcDataTableCli>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_1406d6e90()));
        TSingleton<NpcDataTableCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A46F0, DestroyNpcDataTableCli, 94, 0x6E73979E);
// @0x1414a4750
void DestroyOnceCallbackTimer()
{
    if (TSingleton<OnceCallbackTimer>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<OnceCallbackTimer>::GetInstance());
        TSingleton<OnceCallbackTimer>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4750, DestroyOnceCallbackTimer, 94, 0x40A420CD);
// @0x1414a47b0
void DestroyPCActionDataTable()
{
    if (TSingleton<PCActionDataTable>::s_instance != 0) {
        delete GetPCActionDataTable();
        TSingleton<PCActionDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A47B0, DestroyPCActionDataTable, 94, 0x1C74740E);
// @0x1414a4810
void DestroyPacketHandlerManager()
{
    if (TSingleton<PacketHandlerManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetPacketHandlerManager()));
        TSingleton<PacketHandlerManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4810, DestroyPacketHandlerManager, 94, 0x6F65BAF4);
// @0x1414a4870
void DestroyPaybackManagerClient()
{
    if (TSingleton<PaybackManagerClient>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetPaybackManager()));
        TSingleton<PaybackManagerClient>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4870, DestroyPaybackManagerClient, 94, 0x655019B1);
// @0x1414a48d0
void DestroyPaybackTable()
{
    if (TSingleton<PaybackTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<PaybackTable>::GetInstance());
        TSingleton<PaybackTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A48D0, DestroyPaybackTable, 94, 0xF13FF98B);
// @0x1414a4930
void DestroyQuestDataTable()
{
    if (TSingleton<QuestDataTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<QuestDataTable>::GetInstance());
        TSingleton<QuestDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4930, DestroyQuestDataTable, 94, 0xD3DA3822);
// @0x1414a4990
void DestroyRecodeMgr()
{
    if (TSingleton<RecodeMgr>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<RecodeMgr>::GetInstance());
        TSingleton<RecodeMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4990, DestroyRecodeMgr, 94, 0xFE51A354);
// @0x1414a49f0
void DestroyRewardContentsTable()
{
    if (TSingleton<RewardContentsTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetRewardContentsTable()));
        TSingleton<RewardContentsTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A49F0, DestroyRewardContentsTable, 94, 0x331AAB1F);
// @0x1414a4a50
void DestroySetItemTable()
{
    if (TSingleton<SetItemTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<SetItemTable>::GetInstance());
        TSingleton<SetItemTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4A50, DestroySetItemTable, 94, 0xD90BC029);
// @0x1414a4ab0
void DestroySkillDataTableCli()
{
    if (TSingleton<SkillDataTableCli>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj140*>(TSingleton<SkillDataTableCli>::GetInstance());
        TSingleton<SkillDataTableCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4AB0, DestroySkillDataTableCli, 117, 0x313028D3);
// @0x1414a4b30
void DestroySoundPropertyMgr()
{
    if (TSingleton<SoundPropertyMgr>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<SoundPropertyMgr>::GetInstance());
        TSingleton<SoundPropertyMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4B30, DestroySoundPropertyMgr, 94, 0x0CBBBA6A);
// @0x1414a4b90
void DestroyStanceTable()
{
    if (TSingleton<StanceTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetStanceTable()));
        TSingleton<StanceTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4B90, DestroyStanceTable, 94, 0x490821D4);
// @0x1414a4bf0
void DestroyStateEffectMgr()
{
    if (TSingleton<StateEffectMgr>::s_instance != 0) {
        delete GetStateEffectMgr();
        TSingleton<StateEffectMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4BF0, DestroyStateEffectMgr, 94, 0x5A4F6B43);
// @0x1414a4c50
void DestroyStringManager()
{
    if (TSingleton<StringManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(GetStringManager());
        TSingleton<StringManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4C50, DestroyStringManager, 94, 0xDB996F1C);
// @0x1414a4cb0
void DestroyTermTagManagerCli()
{
    if (TSingleton<TermTagManagerCli>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<TermTagManagerCli>::GetInstance());
        TSingleton<TermTagManagerCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4CB0, DestroyTermTagManagerCli, 94, 0x1D473DD0);
// @0x1414a4d10
void DestroyUGCCubeCategoryTable()
{
    if (TSingleton<UGCCubeCategoryTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UGCCubeCategoryTable>::GetInstance());
        TSingleton<UGCCubeCategoryTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4D10, DestroyUGCCubeCategoryTable, 94, 0x18FFC21F);
// @0x1414a4d70
void DestroyUIBottomCenterAlignManager()
{
    if (TSingleton<UIBottomCenterAlignManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetUIBottomCenterAlignManager()));
        TSingleton<UIBottomCenterAlignManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4D70, DestroyUIBottomCenterAlignManager, 94, 0xDE9241E5);
// @0x1414a4dd0
void DestroyUIBuddyEventDispatcher()
{
    if (TSingleton<UIBuddyEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UIBuddyEventDispatcher>::GetInstance());
        TSingleton<UIBuddyEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4DD0, DestroyUIBuddyEventDispatcher, 94, 0x709ABCE7);
// @0x1414a4e30
void DestroyUIDialogEventDispatcher()
{
    if (TSingleton<UIDialogEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UIDialogEventDispatcher>::GetInstance());
        TSingleton<UIDialogEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4E30, DestroyUIDialogEventDispatcher, 94, 0xCEEF069C);
// @0x1414a4e90
void DestroyUIDungeonCategoryTable()
{
    if (TSingleton<UIDungeonCategoryTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UIDungeonCategoryTable>::GetInstance());
        TSingleton<UIDungeonCategoryTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4E90, DestroyUIDungeonCategoryTable, 94, 0x626BFA13);
// @0x1414a4ef0
void DestroyUIEntityEventDispatcher()
{
    if (TSingleton<UIEntityEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_140c607b0()));
        TSingleton<UIEntityEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4EF0, DestroyUIEntityEventDispatcher, 94, 0x2D1FF1F4);
// @0x1414a4f50
void DestroyUIItemEventDispatcher()
{
    if (TSingleton<UIItemEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetItemEventDispatcher()));
        TSingleton<UIItemEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4F50, DestroyUIItemEventDispatcher, 94, 0x00A4DD0C);
// @0x1414a4fb0
void DestroyUIQuestEventDispatcher()
{
    if (TSingleton<UIQuestEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)FUN_140bfc4b0()));
        TSingleton<UIQuestEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A4FB0, DestroyUIQuestEventDispatcher, 94, 0xF3966947);
// @0x1414a5010
void DestroyUIServerEventDispatcher()
{
    if (TSingleton<UIServerEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetUIServerEventDispatcher()));
        TSingleton<UIServerEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A5010, DestroyUIServerEventDispatcher, 94, 0x51DCA32B);
// @0x1414a5070
void DestroyUIStatusEventDispatcher()
{
    if (TSingleton<UIStatusEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UIStatusEventDispatcher>::GetInstance());
        TSingleton<UIStatusEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A5070, DestroyUIStatusEventDispatcher, 94, 0x1C7FB274);
// @0x1414a50d0
void DestroyUITalkManager()
{
    if (TSingleton<UITalkManager>::s_instance != 0) {
        delete ((class Unk_SingletonObj*)TSingleton<UITalkManager>::GetInstance());
        TSingleton<UITalkManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A50D0, DestroyUITalkManager, 94, 0xDBE27E7F);
// @0x1414a5130
void DestroyUIUGCEventDispatcher()
{
    if (TSingleton<UIUGCEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UIUGCEventDispatcher>::GetInstance());
        TSingleton<UIUGCEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A5130, DestroyUIUGCEventDispatcher, 94, 0xAFBAF998);
// @0x1414a5190
void DestroyUIWorldShareInfoEventDispatcher()
{
    if (TSingleton<UIWorldShareInfoEventDispatcher>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UIWorldShareInfoEventDispatcher>::GetInstance());
        TSingleton<UIWorldShareInfoEventDispatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A5190, DestroyUIWorldShareInfoEventDispatcher, 94, 0xE9B3A445);
// @0x1414a51f0
void DestroyUgcHomeOptionData()
{
    if (TSingleton<UgcHomeOptionData>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<UgcHomeOptionData>::GetInstance());
        TSingleton<UgcHomeOptionData>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A51F0, DestroyUgcHomeOptionData, 94, 0x993BA5D3);
// @0x1414a5250
void DestroyWebGuideTable()
{
    if (TSingleton<WebGuideTable>::s_instance != 0) {
        delete GetWebGuideTable();
        TSingleton<WebGuideTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A5250, DestroyWebGuideTable, 117, 0x4F2219E0);
// @0x1414a52d0
void DestroyWeddingEmotionTable()
{
    if (TSingleton<WeddingEmotionTable>::s_instance != 0) {
        delete GetWeddingEmotionTable();
        TSingleton<WeddingEmotionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A52D0, DestroyWeddingEmotionTable, 94, 0x2D0FCE7F);
// @0x1414a5330
void DestroyWeddingManager()
{
    if (TSingleton<WeddingManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<WeddingManager>::GetInstance());
        TSingleton<WeddingManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A5330, DestroyWeddingManager, 94, 0xCF0DEAAA);
// @0x1414a5390
void DestroyWeddingTable()
{
    if (TSingleton<WeddingTable>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(TSingleton<WeddingTable>::GetInstance());
        TSingleton<WeddingTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A5390, DestroyWeddingTable, 94, 0x0ED93E76);
// @0x1414a53f0
void DestroyWorldMapManager()
{
    if (TSingleton<WorldMapManager>::s_instance != 0) {
        delete reinterpret_cast<Unk_SingletonObj*>(((class Unk_SingletonObj*)GetWorldMapManager()));
        TSingleton<WorldMapManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A53F0, DestroyWorldMapManager, 94, 0xAE08E5EE);
// @0x1414a5450
template void ATL::CAtlMap<int, MS2Ptr<ReactorData> >::DisableAutoRehash() throw();
// @0x1414a5470
template void ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::DisableAutoRehash() throw();
// @0x1414a5490
template void ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::DisableAutoRehash() throw();
// @0x1414a54b0
template void ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::DisableAutoRehash() throw();
// @0x1414a54d0
template void ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::DisableAutoRehash() throw();
#include "ms2/placeholder/gfximageloader.h"   // GFxImageLoader::Protocol
#include "ms2/placeholder/tfunctor2.h"         // FunctorHandler<TFunctor<R, ParamList<A, ParamList<B>>>, Fn>
namespace Scaleform { namespace Render { class Image; class TextureManager; } }
typedef TFunctor<Scaleform::Render::Image*, ParamList<const GFxImageLoader::Protocol&,
    ParamList<Scaleform::Render::TextureManager*, EmptyParam>>> Unk_GFxImageCallback;   // as in ms2.cpp
typedef FunctorHandler<Unk_GFxImageCallback, Scaleform::Render::Image* (*)(const GFxImageLoader::Protocol&,
    Scaleform::Render::TextureManager*)> Unk_GFxImageHandler;
// the image callback handler's Clone: new FunctorHandler(*this) (was FUN_1414a54f0 over FUN_1414a54f0_ctor)
// @0x1414a54f0
template Unk_GFxImageHandler* Unk_GFxImageHandler::Clone() const;
//
// @0x1414a5540
template void ATL::CAtlMap<int, MS2Ptr<ReactorData> >::EnableAutoRehash() throw();
// @0x1414a5560
template void ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::EnableAutoRehash() throw();
// @0x1414a5580
template void ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::EnableAutoRehash() throw();
// @0x1414a55a0
template void ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::EnableAutoRehash() throw();
// @0x1414a55c0
template void ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::EnableAutoRehash() throw();
// @0x1414a55e0
unsigned long long Unk_MiscThis::FUN_1414a55e0() { return 0; }
// @0x1414a55f0
unsigned long long Unk_MiscThis::FUN_1414a55f0() { return 5000; }
// @0x1414a5600
unsigned long long Unk_MiscThis::FUN_1414a5600() { return 0; }
// @0x1414a5610
void FUN_1414a5610(char* pThis, char* pDst) { memcpy(pDst, pThis + 0x60, 0x10); }
MS2_REPLACE(0x1414A5610, FUN_1414a5610, 36, 0x8905C4F3);
class MS2 { public: static const efd::ClassInfo ms_ClassInfo; };                          // C3: was extern char DAT_143ae0130
// @0x1414a5640
void* Unk_MiscThis::FUN_1414a5640() { return (void*)&MS2::ms_ClassInfo; }
// @0x1414a5650
int* Unk_MiscThis::FUN_1414a5650() { return (int*)&ecr::PickService::ms_ClassInfo; }
// @0x1414a5660
int* Unk_MiscThis::FUN_1414a5660() { return (int*)&egmVisualizers::PropertyVisualizationService::ms_ClassInfo; }
// @0x1414a5670
int GetValue(Unk_ShutdownValue30* pThis) { return pThis->m_value; }
MS2_REPLACE(0x1414A5670, GetValue, 14, 0x828204CF);
// @0x1414a5680
const char* MS2PropertyVisualizationService::GetDisplayName() const { return "MS2PropertyVisualizationService"; }
// @0x1414a5690
int GetArchiveMode(CFileSystem* pThis) { return pThis->archiveMode; }
MS2_REPLACE(0x1414A5690, GetArchiveMode, 17, 0x05FDCC0A);
// @0x1414a56b0
int FUN_1414a56b0(char* pThis) { return *(int*)(pThis + 8); }
MS2_REPLACE(0x1414A56B0, FUN_1414a56b0, 14, 0x92BE4827);
// @0x1414a56c0
GFxService* GetGFxService() { return SingletonClass<GFxService>::ms_pSingleton; }   // 0x143ae0748
MS2_REPLACE(0x1414A56C0, GetGFxService, 8, 0x088FC0A0);
// @0x1414a56d0
Unk_SingletonObj* FUN_1414a56d0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CDynamicBanWordManager>::s_instance); }
MS2_REPLACE(0x1414A56D0, FUN_1414a56d0, 8, 0x102F39C2);
// @0x1414a56e0
Unk_SingletonObj* FUN_1414a56e0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CJobConditionTable>::s_instance); }
MS2_REPLACE(0x1414A56E0, FUN_1414a56e0, 8, 0x6F63F71B);
// @0x1414a56f0
Unk_SingletonObj* FUN_1414a56f0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CLoadingDescriptionTable>::s_instance); }
MS2_REPLACE(0x1414A56F0, FUN_1414a56f0, 8, 0x42AB2040);
// @0x1414a5700
Unk_SingletonObj* FUN_1414a5700() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CLoadingImageTable>::s_instance); }
MS2_REPLACE(0x1414A5700, FUN_1414a5700, 8, 0x70220B8A);
// @0x1414a5710
Unk_SingletonObj* FUN_1414a5710() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CMicroGameManagerCli>::s_instance); }
MS2_REPLACE(0x1414A5710, FUN_1414a5710, 8, 0xEDD70F33);
// @0x1414a5720
CNiStreamLoadThread* TSingleton<CNiStreamLoadThread>::GetInstance() { return s_instance; }
MS2_REPLACE(0x1414A5720, TSingleton<CNiStreamLoadThread>::GetInstance, 8, 0xA57EC080);
// @0x1414a5730
Unk_SingletonObj* FUN_1414a5730() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<COnlinePatchManagerCli>::s_instance); }
MS2_REPLACE(0x1414A5730, FUN_1414a5730, 8, 0x5647EF76);
// @0x1414a5740
Unk_SingletonObj* FUN_1414a5740() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CPCEffectDummy>::s_instance); }
MS2_REPLACE(0x1414A5740, FUN_1414a5740, 8, 0x586410F8);
// @0x1414a5750
Unk_SingletonObj* FUN_1414a5750() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CPopupProfileImageMan>::s_instance); }
MS2_REPLACE(0x1414A5750, FUN_1414a5750, 8, 0x1B5AC088);
// @0x1414a5760
Unk_SingletonObj* FUN_1414a5760() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CPortalTable>::s_instance); }
MS2_REPLACE(0x1414A5760, FUN_1414a5760, 8, 0xF2F59F09);
// @0x1414a5770
Unk_SingletonObj* FUN_1414a5770() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CQuestTable>::s_instance); }
MS2_REPLACE(0x1414A5770, FUN_1414a5770, 8, 0xE29D831F);
// @0x1414a5780
Unk_SingletonObj* FUN_1414a5780() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CRankViewer>::s_instance); }
MS2_REPLACE(0x1414A5780, FUN_1414a5780, 8, 0x640A1A97);
// @0x1414a5790
Unk_SingletonObj* FUN_1414a5790() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CServerListTable>::s_instance); }
MS2_REPLACE(0x1414A5790, FUN_1414a5790, 8, 0xE29D831F);
// @0x1414a57a0
Unk_SingletonObj* FUN_1414a57a0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSkillCompactControlTable>::s_instance); }
MS2_REPLACE(0x1414A57A0, FUN_1414a57a0, 8, 0xCB0CBDA4);
// @0x1414a57b0
Unk_SingletonObj* FUN_1414a57b0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSkillSetTable>::s_instance); }
MS2_REPLACE(0x1414A57B0, FUN_1414a57b0, 8, 0x119CF53C);
// @0x1414a57c0
Unk_SingletonObj* FUN_1414a57c0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSoundDataTable>::s_instance); }
MS2_REPLACE(0x1414A57C0, FUN_1414a57c0, 8, 0xF5F7CA73);
// @0x1414a57d0
Unk_SingletonObj* FUN_1414a57d0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CSpecialDungeonDataTable>::s_instance); }
MS2_REPLACE(0x1414A57D0, FUN_1414a57d0, 8, 0xC1CED87F);
// @0x1414a57e0
Unk_SingletonObj* FUN_1414a57e0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CStoryBookTable>::s_instance); }
MS2_REPLACE(0x1414A57E0, FUN_1414a57e0, 8, 0xFE969267);
// @0x1414a57f0
Unk_SingletonObj* FUN_1414a57f0() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CUgcDownloadDown>::s_instance); }
MS2_REPLACE(0x1414A57F0, FUN_1414a57f0, 8, 0xAF7A7FD7);
// @0x1414a5800
Unk_SingletonObj* FUN_1414a5800() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<CUgcDownloadLoad>::s_instance); }
MS2_REPLACE(0x1414A5800, FUN_1414a5800, 8, 0xAF7A7FD7);
// @0x1414a5810
Unk_SingletonObj* GetEngineLog() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<EngineLog>::s_instance); }
MS2_REPLACE(0x1414A5810, GetEngineLog, 8, 0x5C402B0F);
// @0x1414a5820
Unk_SingletonObj* GetFieldWarDataTable() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<FieldWarDataTable>::s_instance); }
MS2_REPLACE(0x1414A5820, GetFieldWarDataTable, 8, 0xE2227D11);
// @0x1414a5830
Unk_SingletonObj* GetHomeBlockManager() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<HomeBlockManager>::s_instance); }
MS2_REPLACE(0x1414A5830, GetHomeBlockManager, 8, 0x8BBF69B5);
// @0x1414a5840
Unk_SingletonObj* GetLoginBgBgmTable() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<LoginBgBgmTable>::s_instance); }
MS2_REPLACE(0x1414A5840, GetLoginBgBgmTable, 8, 0x7852BC4C);
// @0x1414a5850
Unk_SingletonObj* GetMultiSceneUpdater() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<MultiSceneUpdater>::s_instance); }
MS2_REPLACE(0x1414A5850, GetMultiSceneUpdater, 8, 0xBF92926A);
// @0x1414a5860
Unk_SingletonObj* GetPCActionDataTable() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<PCActionDataTable>::s_instance); }
MS2_REPLACE(0x1414A5860, GetPCActionDataTable, 8, 0xD92FE2D7);
// @0x1414a5870
Unk_SingletonObj* GetStateEffectMgr() { return reinterpret_cast<Unk_SingletonObj*>(TSingleton<StateEffectMgr>::s_instance); }
MS2_REPLACE(0x1414A5870, GetStateEffectMgr, 8, 0x3EFF4636);
// @0x1414a5880
Unk_SingletonObj80* GetWebGuideTable() { return reinterpret_cast<Unk_SingletonObj80*>(TSingleton<WebGuideTable>::s_instance); }
MS2_REPLACE(0x1414A5880, GetWebGuideTable, 8, 0x2543A217);
// @0x1414a5890
Unk_SingletonObj* GetPhysXManager() { return reinterpret_cast<Unk_SingletonObj*>(Unk_PhysXSDKManagerStatics::ms_pPhysXManager); }
MS2_REPLACE(0x1414A5890, GetPhysXManager, 8, 0xC6930D6B);
// @0x1414a58a0
void FUN_1414a58a0(char* pThis) { reinterpret_cast<efd::SmartPointer<NiMaterial>*>(pThis + 0x10)->operator NiMaterial*(); }
MS2_REPLACE(0x1414A58A0, FUN_1414a58a0, 31, 0x5650D8A9);
// @0x1414a58c0
NiMaterialSwapProcessorPtr GetMaterialSwapProcessor(int idx)   // NiShadowManager::GetMaterialSwapProcessor: m_aspMaterialSwapProcessor[eType] (+0x170)
{
    return *reinterpret_cast<NiMaterialSwapProcessorPtr*>(DAT_143afa980 + 0x170 + (long long)idx * 8);
}
// @0x1414a5910
int FUN_1414a5910(char* pThis) { return *(int*)(pThis + 100); }
MS2_REPLACE(0x1414A5910, FUN_1414a5910, 14, 0xB9C4E423);
// @0x1414a5920
void FUN_1414a5920(char* pThis) { reinterpret_cast<efd::AtomicRefCount*>(pThis + 0x20)->operator efd::UInt32(); }
MS2_REPLACE(0x1414A5920, FUN_1414a5920, 31, 0xF886CB09);
// @0x1414a5940
void FUN_1414a5940(char* pThis) { reinterpret_cast<efd::AtomicRefCount*>(pThis + 0x18)->operator efd::UInt32(); }
MS2_REPLACE(0x1414A5940, FUN_1414a5940, 31, 0x888D3262);
// @0x1414a5960
void FUN_1414a5960(char* pThis) { reinterpret_cast<efd::AtomicRefCount*>(pThis + 0x18)->operator efd::UInt32(); }
MS2_REPLACE(0x1414A5960, FUN_1414a5960, 31, 0x24583782);
// @0x1414a5980
void FUN_1414a5980(char* pThis) { FUN_140c8f690(*(const efd::SmartPointer<class NiViewRenderClick>*)(pThis + 0x28)); }
MS2_REPLACE(0x1414A5980, FUN_1414a5980, 31, 0xEFCBF263);
// @0x1414a59a0
void* GetTexture(char* pThis) { return reinterpret_cast<efd::SmartPointer<NiTexture>*>(pThis + 0x118)->operator NiTexture*(); }
MS2_REPLACE(0x1414A59A0, GetTexture, 33, 0x0033409D);
// @0x1414a59d0
void FUN_1414a59d0(char* pThis) { reinterpret_cast<efd::AtomicRefCount*>(pThis + 0x20)->operator++(); }
MS2_REPLACE(0x1414A59D0, FUN_1414a59d0, 31, 0x1941A24A);
// @0x1414a59f0
void FUN_1414a59f0(char* pThis) { reinterpret_cast<efd::AtomicRefCount*>(pThis + 0x18)->operator++(); }
MS2_REPLACE(0x1414A59F0, FUN_1414a59f0, 31, 0x4A3FA102);
// @0x1414a5a10
void FUN_1414a5a10(char* pThis) { reinterpret_cast<efd::AtomicRefCount*>(pThis + 0x18)->operator++(); }
MS2_REPLACE(0x1414A5A10, FUN_1414a5a10, 31, 0x09A43922);
// @0x1414a5a30
int COptimizer::FUN_1414a5a30() { return DAT_143ae2b48; }
// @0x1414a5a40
int FUN_1414a5a40(CStringW sPath) { return _wmkdir(sPath); }
// @0x1414a5a80
void Close(HANDLE* pThis)
{
    if (*pThis != 0)
        CloseHandle(*pThis);
    *pThis = 0;
    *(int*)(pThis + 1) = 0;
}
MS2_REPLACE(0x1414A5A80, Close, 63, 0x35494406);
// @0x1414a5ac0
template void ATL::CAtlMap<int, MS2Ptr<ReactorData> >::RemoveAll();
// @0x1414a5bd0
template void ATL::CAtlMap<int, MS2Ptr<ReactorStateData> >::RemoveAll();
// @0x1414a5ce0
template void ATL::CAtlMap<int, MS2SvrPtr<CArcadeMainData>, ATL::CDefaultElementTraits<int> >::RemoveAll();
// @0x1414a5df0
template void ATL::CAtlMap<int, std::vector<std::pair<int, CStringW> >, ATL::CDefaultElementTraits<int> >::RemoveAll();
// @0x1414a5f00
template void ATL::CAtlMap<int, std::vector<MS2SvrPtr<CArcadeRewardData> >, ATL::CDefaultElementTraits<int> >::RemoveAll();
