// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tail of the ms2.cpp object: a SceneGraphCacheData smart-pointer
// release helper, three virtual-delete helpers, a destructor thunk for the magicdata table, and 78 singleton destroy
// helpers `if (instance) { delete GetInstance(); instance = 0; }` (one per TSingleton-style class; the class names are not
// recoverable from the bodies, so instance pointers and getters are typed void* and the virtual destructor call goes
// through the unit-local Unk_VirtualDtor).
// MS2-UNIT: unit_14149fd50
// MS2-RANGE: 0x14149fd50-0x1414a1c30 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/MemObject.h>
#include <efd/RefCount.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// return types of the getters the shutdown thunks call
class AnimationCallbackManager;
class ApplyEffect;
class CAdBannerManagerCli;
class CAdventureLevelTable;
class CAsyncImageLoader;
class CAutoFindTaxiStation;
class CBankTable;
class CBattleRecordManager;
class CBigDataLogSystem;
class CBlackMarketMan;
class CBlackMarketTable;
class CBuddyManager;
class CCashCallManager;
class CCashMarketMan;
class CChapterBookTable;
class CCharacterAbilityManager;
class CCharacterAbilityTable;
class CChatEmoticonTable;
class CContinentRegionTable;
class CCoupleEmotionTable;
class CDPSMeterSystem;
class CDirWatcher;
class CDynamicBanWordManager;
class CEnchantScrollTable;
class CFieldMaidManager;
class CFieldMetaTable;
class CFilePreload;
class CFileSystem;
class CFishingManager;
class CFishingTable;
class CGameEventValueManager;
class CGameOption;
class CGameRankingCli;
class CGloabalFactor;
class CGraphicOptionTable;
class CGroupChatManager;
class CGuildManager;
class CGuildXmlData;
class CIgnoreFile;
class CIndividualArenaDataTable;
class CItemDataTable;
class CItemEnchantLimitTable;
class CItemEnchantTransformTable;
class CItemExchangeScrollTable;
class CItemGemPropertyTable;
class CItemGemStoneUpgradeTable;
class CItemLoader;
class CItemMergeOptionTable;
class CItemRemakeScrollTable;
class CItemSocketScrollTable;
class Unk_140166410;
class Unk_140166430;
class Unk_ALCurrent;
class Unk_AttendGiftDataGroup;
class Unk_BreakRecipes;
class Unk_BreakRules;
class Unk_ClubBuffTable;
class Unk_ClubManager;
class Unk_EmoNpcTable;
class Unk_EnchantRates;
class Unk_InventoryStateManager;
class Unk_MeratBlindManager;
class Unk_MusicBookTable;
class Unk_NametagTrophy;
class Unk_QmGroupTable;
class Unk_RankArcadeTable;
class Unk_Restrictions;
class Unk_RpTable;
class Unk_SlotBreakManager;
class Unk_SlotLapenTable;
struct Unk_BanConfig;
struct Unk_PmFixedItem;

// the singleton classes the shutdown thunks clear (TSingleton<T>::s_instance; only the pointer is used)
class AnimationCallbackManager;
class ApplyEffect;
class AttendGiftDataTable;
class BGTransparencyMgr;
class BlindManager;
class CAchieveManager;
class CAdBannerManagerCli;
class CAdventureLevelTable;
class CAdventureLevelTableHelper;
class CArcadeDataTable;
class CAsyncImageLoader;
class CAutoFindTaxiStation;
class CBankTable;
class CBattleRecordManager;
class CBigDataLogSystem;
class CBlackMarketMan;
class CBlackMarketTable;
class CBlockManager;
class CBuddyManager;
class CCashCallManager;
class CCashMarketMan;
class CChapterBookTable;
class CCharacterAbilityManager;
class CCharacterAbilityTable;
class CChatEmoticonTable;
class CClubClientManager;
class CClubDataTable;
class CContentShutdownManager;
class CContinentRegionTable;
class CCoupleEmotionTable;
class CDPSMeterSystem;
class CDirWatcher;
class CDynamicBanWordManager;
class CEnchantScrollTable;
class CExpTable;
class CFameTable;
class CFeatureManager;
class CFieldMaidManager;
class CFieldMetaTable;
class CFieldMissionTable;
class CFilePreload;
class CFileSystem;
class CFishingManager;
class CFishingTable;
class CGFxLanguage;
class CGameEventValueManager;
class CGameOption;
class CGameRankingCli;
class CGameRule;
class CGloabalFactor;
class CGraphicOptionTable;
class CGroupChatManager;
class CGuideManager;
class CGuildManager;
class CGuildXmlData;
class CIgnoreFile;
class CIndividualArenaDataTable;
class CInstrumentDataTable;
class CInstrumentManager;
class CItemBreakIngredientTable;
class CItemBreakManager;
class CItemDataTable;
class CItemEnchantLimitTable;
class CItemEnchantTransformTable;
class CItemEnchantUtil;
class CItemExchangeScrollTable;
class CItemExtractionTable;
class CItemGemPropertyTable;
class CItemGemStoneUpgradeTable;
class CItemLapenshardTable;
class CItemLoader;
class CItemLockManager;
class CItemMergeOptionTable;
class CItemOptionTable;
class CItemRePackingScrollTable;
class CItemRemakeScrollTable;
class CItemSocketScrollTable;
class CItemSocketTable;
// the class's own unit defines s_instance / GetInstance out of line (explicit specializations): only declared here, so
// this obj does not instantiate a second copy (LNK2005 in the full-exe link)
template<> class TSingleton<AnimationCallbackManager> { public: static AnimationCallbackManager* s_instance; static AnimationCallbackManager* GetInstance(); };
template<> class TSingleton<BGTransparencyMgr> { public: static BGTransparencyMgr* s_instance; static BGTransparencyMgr* GetInstance(); };
template<> class TSingleton<CChatEmoticonTable> { public: static CChatEmoticonTable* s_instance; static CChatEmoticonTable* GetInstance(); };
template<> class TSingleton<CDirWatcher> { public: static CDirWatcher* s_instance; static CDirWatcher* GetInstance(); };
template<> class TSingleton<CFilePreload> { public: static CFilePreload* s_instance; static CFilePreload* GetInstance(); };

// Unit-local declarations; the unidentified names describe uses rather than original class names.
// Release target of the scene graph cache smart pointer (ecr::SceneGraphCache::SceneGraphCacheData in the exe: the reference
// count is the first member and the destructor is non-virtual, deleted through the MemObject operator delete). The sized
// delete hands the block back to the efd pool by size, so the stand-in keeps the exe's sizeof (0x90): a smaller one returns
// the 0x90 block to the wrong FixedSizeAllocator.
struct Unk_SceneCacheData : public efd::MemObject
{
    ~Unk_SceneCacheData();
    efd::AtomicRefCount m_refCount;
    char m_aRest[0x8c];             // status, llid/physicalID/filePath, objects, request list (not touched here)
};
MS2_CHECK_SIZE(Unk_SceneCacheData, 0x90);
// Class whose virtual destructor sits in vftable slot 8.
struct Unk_Slot8Delete
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual ~Unk_Slot8Delete();
};
// Singleton class with a virtual destructor in slot 0.
struct Unk_VirtualDtor
{
    virtual ~Unk_VirtualDtor();
};
// Singleton class whose TSingleton base (virtual destructor) is a secondary base at +8.
struct Unk_PrimaryBase
{
    virtual void vfunc_0();
};
struct Unk_SecondaryDtorBase
{
    virtual ~Unk_SecondaryDtorBase();
};
struct Unk_SecondaryDtorSingleton : public Unk_PrimaryBase, public Unk_SecondaryDtorBase
{
};
// Static table of the magic data (FUN_14146a6a0 = its destructor).
struct Unk_MagicTable
{
    void FUN_14146a6a0();
};
extern Unk_MagicTable DAT_143adca50;

// Singleton instance pointers and instance getters (exe data/functions; bound through progress/symbols).
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
CFileSystem* GetFileSystem();
class Unk_140166430* FUN_140166430();   // C3: was FUN_140166430
class CBlackMarketTable* FUN_1401c0d80();   // C3: was FUN_1401c0d80
void* FUN_1401c0d90();
class CDirWatcher* FUN_1401d31e0();   // C3: was FUN_1401d31e0
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
class Unk_AttendGiftDataGroup* FUN_1403fc330();   // C3: was FUN_1403fc330
void* FUN_1404a1bb0();
class Unk_MusicBookTable* FUN_14052d1d0();   // C3: was FUN_14052d1d0
class Unk_EnchantRates* FUN_14052d1e0();   // C3: was FUN_14052d1e0
void* FUN_14052d1f0();
void* FUN_14052d200();
class Unk_BreakRecipes* FUN_140535300();   // C3: was FUN_140535300
class Unk_BreakRules* FUN_140535310();   // C3: was FUN_140535310
class CItemGemPropertyTable* FUN_1405a96f0();   // C3: was FUN_1405a96f0
class CItemGemStoneUpgradeTable* FUN_14062c280();   // C3: was FUN_14062c280
class Unk_NametagTrophy* FUN_1406c7600();   // C3: was FUN_1406c7600
class Unk_EmoNpcTable* FUN_140764010();   // C3: was FUN_140764010
class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
class Unk_MeratBlindManager* FUN_1409c1730();   // C3: was FUN_1409c1730
class Unk_SlotBreakManager* FUN_1409c4b20();   // C3: was FUN_1409c4b20
class Unk_SlotLapenTable* FUN_1409c4b30();   // C3: was FUN_1409c4b30
class Unk_InventoryStateManager* FUN_140a6a830();   // C3: was FUN_140a6a830
class Unk_ClubBuffTable* FUN_140b1a4e0();   // C3: was FUN_140b1a4e0
class Unk_ALCurrent* FUN_140ba4fa0();   // C3: was FUN_140ba4fa0
struct Unk_PmFixedItem* FUN_140c8dac0();   // C3: was FUN_140c8dac0
class Unk_QmGroupTable* FUN_140d738f0();   // C3: was FUN_140d738f0
class Unk_ClubManager* FUN_140e0d900();   // C3: was FUN_140e0d900
class Unk_RankArcadeTable* FUN_140e37aa0();   // C3: was FUN_140e37aa0
class Unk_RpTable* FUN_140f64150();   // C3: was FUN_140f64150
class Unk_GoUpdateList   // C3: member view for the former free stand-ins
{
public:
    static class Unk_GoUpdateList* FUN_14123ee80();
};
void* FUN_141371b20();

void FUN_14149fe70(Unk_SceneCacheData* p);

// @0x14149fd50
void FUN_14149fd50(Unk_SceneCacheData* p)
{
    if (--p->m_refCount == 0)
        FUN_14149fe70(p);
}
MS2_REPLACE(0x14149FD50, FUN_14149fd50, 41, 0x0E2FCD50);

// @0x14149fd80
void FUN_14149fd80(Unk_Slot8Delete* p)
{
    delete p;
}
MS2_REPLACE(0x14149FD80, FUN_14149fd80, 79, 0x0838999B);

// @0x14149fdd0
void FUN_14149fdd0(Unk_Slot8Delete* p)
{
    delete p;
}
MS2_REPLACE(0x14149FDD0, FUN_14149fdd0, 79, 0x0838999B);

// @0x14149fe20
void FUN_14149fe20(Unk_Slot8Delete* p)
{
    delete p;
}
MS2_REPLACE(0x14149FE20, FUN_14149fe20, 79, 0x0838999B);

// @0x14149fe70
void FUN_14149fe70(Unk_SceneCacheData* p)
{
    delete p;
}
MS2_REPLACE(0x14149FE70, FUN_14149fe70, 73, 0x032D49BB);

// @0x14149fec0
void FUN_14149fec0()
{
    DAT_143adca50.FUN_14146a6a0();
}
MS2_REPLACE(0x14149FEC0, FUN_14149fec0, 21, 0xC697E12D);

// @0x14149fee0
void FUN_14149fee0()
{
    if (TSingleton<AnimationCallbackManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<AnimationCallbackManager>::GetInstance();
        TSingleton<AnimationCallbackManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x14149FEE0, FUN_14149fee0, 94, 0x7F62458B);

// @0x14149ff40
void FUN_14149ff40()
{
    if (TSingleton<ApplyEffect>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<ApplyEffect>::GetInstance();
        TSingleton<ApplyEffect>::s_instance = 0;
    }
}
MS2_REPLACE(0x14149FF40, FUN_14149ff40, 94, 0x92787D34);

// @0x14149ffa0
void FUN_14149ffa0()
{
    if (TSingleton<AttendGiftDataTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1403fc330());
        TSingleton<AttendGiftDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x14149FFA0, FUN_14149ffa0, 94, 0x5475E1A5);

// @0x1414a0000
void FUN_1414a0000()
{
    if (TSingleton<BGTransparencyMgr>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)Unk_GoUpdateList::FUN_14123ee80());
        TSingleton<BGTransparencyMgr>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0000, FUN_1414a0000, 94, 0x3E19299D);

// @0x1414a0060
void FUN_1414a0060()
{
    if (TSingleton<BlindManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1409c1730());
        TSingleton<BlindManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0060, FUN_1414a0060, 94, 0x6273A9F4);

// @0x1414a00c0
void FUN_1414a00c0()
{
    if (TSingleton<CAchieveManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1406c7600());
        TSingleton<CAchieveManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A00C0, FUN_1414a00c0, 94, 0x4A6BE7CF);

// @0x1414a0120
void FUN_1414a0120()
{
    if (TSingleton<CAdBannerManagerCli>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CAdBannerManagerCli>::GetInstance();
        TSingleton<CAdBannerManagerCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0120, FUN_1414a0120, 94, 0xB97A7C60);

// @0x1414a0180
void FUN_1414a0180()
{
    if (TSingleton<CAdventureLevelTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CAdventureLevelTable>::GetInstance();
        TSingleton<CAdventureLevelTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0180, FUN_1414a0180, 94, 0x24B54FB7);

// @0x1414a01e0
void FUN_1414a01e0()
{
    if (TSingleton<CAdventureLevelTableHelper>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140ba4fa0());
        TSingleton<CAdventureLevelTableHelper>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A01E0, FUN_1414a01e0, 94, 0x434DD445);

// @0x1414a0240
void FUN_1414a0240()
{
    if (TSingleton<CArcadeDataTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140e37aa0());
        TSingleton<CArcadeDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0240, FUN_1414a0240, 94, 0xB9BB425B);

// @0x1414a02a0
void FUN_1414a02a0()
{
    if (TSingleton<CAsyncImageLoader>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CAsyncImageLoader>::GetInstance();
        TSingleton<CAsyncImageLoader>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A02A0, FUN_1414a02a0, 94, 0x8D2FCE7D);

// @0x1414a0300
void FUN_1414a0300()
{
    if (TSingleton<CAutoFindTaxiStation>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CAutoFindTaxiStation>::GetInstance();
        TSingleton<CAutoFindTaxiStation>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0300, FUN_1414a0300, 94, 0x23417763);

// @0x1414a0360
void FUN_1414a0360()
{
    if (TSingleton<CBankTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CBankTable>::GetInstance();
        TSingleton<CBankTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0360, FUN_1414a0360, 94, 0x1909B041);

// @0x1414a03c0
void FUN_1414a03c0()
{
    if (TSingleton<CBattleRecordManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CBattleRecordManager>::GetInstance();
        TSingleton<CBattleRecordManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A03C0, FUN_1414a03c0, 94, 0xC1E87E13);

// @0x1414a0420
void FUN_1414a0420()
{
    if (TSingleton<CBigDataLogSystem>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CBigDataLogSystem>::GetInstance();
        TSingleton<CBigDataLogSystem>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0420, FUN_1414a0420, 94, 0x739F711F);

// @0x1414a0480
void FUN_1414a0480()
{
    if (TSingleton<CBlackMarketMan>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CBlackMarketMan>::GetInstance();
        TSingleton<CBlackMarketMan>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0480, FUN_1414a0480, 94, 0x8D0D1F3E);

// @0x1414a04e0
void FUN_1414a04e0()
{
    if (TSingleton<CBlackMarketTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1401c0d80());
        TSingleton<CBlackMarketTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A04E0, FUN_1414a04e0, 94, 0x6D588353);

// @0x1414a0540
void FUN_1414a0540()
{
    if (TSingleton<CBlockManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140a6a830());
        TSingleton<CBlockManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0540, FUN_1414a0540, 94, 0xA92456EA);

// @0x1414a05a0
void FUN_1414a05a0()
{
    if (TSingleton<CBuddyManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CBuddyManager>::GetInstance();
        TSingleton<CBuddyManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A05A0, FUN_1414a05a0, 94, 0x9630DAEE);

// @0x1414a0600
void FUN_1414a0600()
{
    if (TSingleton<CCashCallManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CCashCallManager>::GetInstance();
        TSingleton<CCashCallManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0600, FUN_1414a0600, 94, 0xA03ED1FF);

// @0x1414a0660
void FUN_1414a0660()
{
    if (TSingleton<CCashMarketMan>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CCashMarketMan>::GetInstance();
        TSingleton<CCashMarketMan>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0660, FUN_1414a0660, 94, 0xD1BE3873);

// @0x1414a06c0
void FUN_1414a06c0()
{
    if (TSingleton<CChapterBookTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CChapterBookTable>::GetInstance();
        TSingleton<CChapterBookTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A06C0, FUN_1414a06c0, 94, 0x1EB76F19);

// @0x1414a0720
void FUN_1414a0720()
{
    if (TSingleton<CCharacterAbilityManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CCharacterAbilityManager>::GetInstance();
        TSingleton<CCharacterAbilityManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0720, FUN_1414a0720, 94, 0xA84F0957);

// @0x1414a0780
void FUN_1414a0780()
{
    if (TSingleton<CCharacterAbilityTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CCharacterAbilityTable>::GetInstance();
        TSingleton<CCharacterAbilityTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0780, FUN_1414a0780, 94, 0x609BF47E);

// @0x1414a07e0
void FUN_1414a07e0()
{
    if (TSingleton<CChatEmoticonTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CChatEmoticonTable>::GetInstance();
        TSingleton<CChatEmoticonTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A07E0, FUN_1414a07e0, 94, 0xE9648A44);

// @0x1414a0840
void FUN_1414a0840()
{
    if (TSingleton<CClubClientManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140e0d900());
        TSingleton<CClubClientManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0840, FUN_1414a0840, 94, 0x2EF1C062);

// @0x1414a08a0
void FUN_1414a08a0()
{
    if (TSingleton<CClubDataTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140b1a4e0());
        TSingleton<CClubDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A08A0, FUN_1414a08a0, 94, 0x1C5A456E);

// @0x1414a0900
void FUN_1414a0900()
{
    if (TSingleton<CContentShutdownManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_14025e7b0());
        TSingleton<CContentShutdownManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0900, FUN_1414a0900, 94, 0x710BAE1E);

// @0x1414a0960
void FUN_1414a0960()
{
    if (TSingleton<CContinentRegionTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CContinentRegionTable>::GetInstance();
        TSingleton<CContinentRegionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0960, FUN_1414a0960, 94, 0x6CD131BB);

// @0x1414a09c0
void FUN_1414a09c0()
{
    if (TSingleton<CCoupleEmotionTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CCoupleEmotionTable>::GetInstance();
        TSingleton<CCoupleEmotionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A09C0, FUN_1414a09c0, 94, 0x0C860B3D);

// @0x1414a0a20
void FUN_1414a0a20()
{
    if (TSingleton<CDPSMeterSystem>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CDPSMeterSystem>::GetInstance();
        TSingleton<CDPSMeterSystem>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0A20, FUN_1414a0a20, 94, 0xE0AFA01D);

// @0x1414a0a80
void FUN_1414a0a80()
{
    if (TSingleton<CDirWatcher>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1401d31e0());
        TSingleton<CDirWatcher>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0A80, FUN_1414a0a80, 94, 0x1B9DDC8E);

// @0x1414a0ae0
void FUN_1414a0ae0()
{
    if (TSingleton<CDynamicBanWordManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CDynamicBanWordManager>::GetInstance();
        TSingleton<CDynamicBanWordManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0AE0, FUN_1414a0ae0, 94, 0x68B35DB4);

// @0x1414a0b40
void FUN_1414a0b40()
{
    if (TSingleton<CEnchantScrollTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CEnchantScrollTable>::GetInstance();
        TSingleton<CEnchantScrollTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0B40, FUN_1414a0b40, 94, 0x7F79D7DE);

// @0x1414a0ba0
void FUN_1414a0ba0()
{
    if (TSingleton<CExpTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1404a1bb0();
        TSingleton<CExpTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0BA0, FUN_1414a0ba0, 94, 0x79D06837);

// @0x1414a0c00
void FUN_1414a0c00()
{
    if (TSingleton<CFameTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140764010());
        TSingleton<CFameTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0C00, FUN_1414a0c00, 94, 0x6985980E);

// @0x1414a0c60
void FUN_1414a0c60()
{
    if (TSingleton<CFeatureManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140166410());
        TSingleton<CFeatureManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0C60, FUN_1414a0c60, 94, 0x39C29BB3);

// @0x1414a0cc0
void FUN_1414a0cc0()
{
    if (TSingleton<CFieldMaidManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CFieldMaidManager>::GetInstance();
        TSingleton<CFieldMaidManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0CC0, FUN_1414a0cc0, 94, 0xBD69728F);

// @0x1414a0d20
void FUN_1414a0d20()
{
    if (TSingleton<CFieldMetaTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CFieldMetaTable>::GetInstance();
        TSingleton<CFieldMetaTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0D20, FUN_1414a0d20, 94, 0x1CA2C135);

// @0x1414a0d80
void FUN_1414a0d80()
{
    if (TSingleton<CFieldMissionTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140d738f0());
        TSingleton<CFieldMissionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0D80, FUN_1414a0d80, 94, 0xA8361B64);

// @0x1414a0de0
void FUN_1414a0de0()
{
    if (TSingleton<CFilePreload>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CFilePreload>::GetInstance();
        TSingleton<CFilePreload>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0DE0, FUN_1414a0de0, 94, 0xE4E04C53);

// @0x1414a0e40
void FUN_1414a0e40()
{
    if (TSingleton<CFileSystem>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)GetFileSystem();
        TSingleton<CFileSystem>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0E40, FUN_1414a0e40, 94, 0x202E0165);

// @0x1414a0ea0
void FUN_1414a0ea0()
{
    if (TSingleton<CFishingManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CFishingManager>::GetInstance();
        TSingleton<CFishingManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0EA0, FUN_1414a0ea0, 94, 0xB7401BE9);

// @0x1414a0f00
void FUN_1414a0f00()
{
    if (TSingleton<CFishingTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CFishingTable>::GetInstance();
        TSingleton<CFishingTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0F00, FUN_1414a0f00, 94, 0xBDEB2E52);

// @0x1414a0f60
void FUN_1414a0f60()
{
    if (TSingleton<CGFxLanguage>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)FUN_141371b20();
        TSingleton<CGFxLanguage>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0F60, FUN_1414a0f60, 94, 0x48576B5C);

// @0x1414a0fc0
void FUN_1414a0fc0()
{
    if (TSingleton<CGameEventValueManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGameEventValueManager>::GetInstance();
        TSingleton<CGameEventValueManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A0FC0, FUN_1414a0fc0, 94, 0xE6F93524);

// @0x1414a1020
void FUN_1414a1020()
{
    if (TSingleton<CGameOption>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGameOption>::GetInstance();
        TSingleton<CGameOption>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1020, FUN_1414a1020, 94, 0x9550C27E);

// @0x1414a1080
void FUN_1414a1080()
{
    if (TSingleton<CGameRankingCli>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGameRankingCli>::GetInstance();
        TSingleton<CGameRankingCli>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1080, FUN_1414a1080, 94, 0x3ED50C0D);

// @0x1414a10e0
void FUN_1414a10e0()
{
    if (TSingleton<CGameRule>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)FUN_1401c0d90();
        TSingleton<CGameRule>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A10E0, FUN_1414a10e0, 94, 0x369666FE);

// @0x1414a1140
void FUN_1414a1140()
{
    if (TSingleton<CGloabalFactor>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGloabalFactor>::GetInstance();
        TSingleton<CGloabalFactor>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1140, FUN_1414a1140, 94, 0x5ABEE7B5);

// @0x1414a11a0
void FUN_1414a11a0()
{
    if (TSingleton<CGraphicOptionTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGraphicOptionTable>::GetInstance();
        TSingleton<CGraphicOptionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A11A0, FUN_1414a11a0, 94, 0xCE57F242);

// @0x1414a1200
void FUN_1414a1200()
{
    if (TSingleton<CGroupChatManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGroupChatManager>::GetInstance();
        TSingleton<CGroupChatManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1200, FUN_1414a1200, 94, 0xC35E3377);

// @0x1414a1260
void FUN_1414a1260()
{
    if (TSingleton<CGuideManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1409331e0());
        TSingleton<CGuideManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1260, FUN_1414a1260, 94, 0x9D746BE4);

// @0x1414a12c0
void FUN_1414a12c0()
{
    if (TSingleton<CGuildManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGuildManager>::GetInstance();
        TSingleton<CGuildManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A12C0, FUN_1414a12c0, 94, 0x02A9F0AB);

// @0x1414a1320
void FUN_1414a1320()
{
    if (TSingleton<CGuildXmlData>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CGuildXmlData>::GetInstance();
        TSingleton<CGuildXmlData>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1320, FUN_1414a1320, 94, 0x70F05971);

// @0x1414a1380
void FUN_1414a1380()
{
    if (TSingleton<CIgnoreFile>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CIgnoreFile>::GetInstance();
        TSingleton<CIgnoreFile>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1380, FUN_1414a1380, 94, 0xFA35C5CC);

// @0x1414a13e0
void FUN_1414a13e0()
{
    if (TSingleton<CIndividualArenaDataTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CIndividualArenaDataTable>::GetInstance();
        TSingleton<CIndividualArenaDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A13E0, FUN_1414a13e0, 94, 0x8254972E);

// @0x1414a1440
void FUN_1414a1440()
{
    if (TSingleton<CInstrumentDataTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_14052d1d0());
        TSingleton<CInstrumentDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1440, FUN_1414a1440, 94, 0x76043011);

// @0x1414a14a0
void FUN_1414a14a0()
{
    if (TSingleton<CInstrumentManager>::s_instance != 0)
    {
        delete (Unk_SecondaryDtorSingleton*)((void*)FUN_140c8dac0());
        TSingleton<CInstrumentManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A14A0, FUN_1414a14a0, 112, 0xD1224E15);

// @0x1414a1510
void FUN_1414a1510()
{
    if (TSingleton<CItemBreakIngredientTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140535300());
        TSingleton<CItemBreakIngredientTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1510, FUN_1414a1510, 94, 0x2E8D4F9A);

// @0x1414a1570
void FUN_1414a1570()
{
    if (TSingleton<CItemBreakManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1409c4b20());
        TSingleton<CItemBreakManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1570, FUN_1414a1570, 94, 0xAD79A55F);

// @0x1414a15d0
void FUN_1414a15d0()
{
    if (TSingleton<CItemDataTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemDataTable>::GetInstance();
        TSingleton<CItemDataTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A15D0, FUN_1414a15d0, 94, 0xFA6A5F70);

// @0x1414a1630
void FUN_1414a1630()
{
    if (TSingleton<CItemEnchantLimitTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemEnchantLimitTable>::GetInstance();
        TSingleton<CItemEnchantLimitTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1630, FUN_1414a1630, 94, 0xF129029F);

// @0x1414a1690
void FUN_1414a1690()
{
    if (TSingleton<CItemEnchantTransformTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemEnchantTransformTable>::GetInstance();
        TSingleton<CItemEnchantTransformTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1690, FUN_1414a1690, 94, 0xE0C48CD7);

// @0x1414a16f0
void FUN_1414a16f0()
{
    if (TSingleton<CItemEnchantUtil>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_14052d1e0());
        TSingleton<CItemEnchantUtil>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A16F0, FUN_1414a16f0, 94, 0x32423A9E);

// @0x1414a1750
void FUN_1414a1750()
{
    if (TSingleton<CItemExchangeScrollTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemExchangeScrollTable>::GetInstance();
        TSingleton<CItemExchangeScrollTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1750, FUN_1414a1750, 94, 0xC3EC3C3B);

// @0x1414a17b0
void FUN_1414a17b0()
{
    if (TSingleton<CItemExtractionTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14052d1f0();
        TSingleton<CItemExtractionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A17B0, FUN_1414a17b0, 94, 0x5E92DE06);

// @0x1414a1810
void FUN_1414a1810()
{
    if (TSingleton<CItemGemPropertyTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1405a96f0());
        TSingleton<CItemGemPropertyTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1810, FUN_1414a1810, 94, 0x9763F4D6);

// @0x1414a1870
void FUN_1414a1870()
{
    if (TSingleton<CItemGemStoneUpgradeTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_14062c280());
        TSingleton<CItemGemStoneUpgradeTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1870, FUN_1414a1870, 94, 0xFCC9E551);

// @0x1414a18d0
void FUN_1414a18d0()
{
    if (TSingleton<CItemLapenshardTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_1409c4b30());
        TSingleton<CItemLapenshardTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A18D0, FUN_1414a18d0, 94, 0x28B27944);

// @0x1414a1930
void FUN_1414a1930()
{
    if (TSingleton<CItemLoader>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemLoader>::GetInstance();
        TSingleton<CItemLoader>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1930, FUN_1414a1930, 94, 0x643605B0);

// @0x1414a1990
void FUN_1414a1990()
{
    if (TSingleton<CItemLockManager>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140535310());
        TSingleton<CItemLockManager>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1990, FUN_1414a1990, 94, 0x29EECA1E);

// @0x1414a19f0
void FUN_1414a19f0()
{
    if (TSingleton<CItemMergeOptionTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemMergeOptionTable>::GetInstance();
        TSingleton<CItemMergeOptionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A19F0, FUN_1414a19f0, 94, 0x0A71209E);

// @0x1414a1a50
void FUN_1414a1a50()
{
    if (TSingleton<CItemOptionTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140166430());
        TSingleton<CItemOptionTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1A50, FUN_1414a1a50, 94, 0x3B2AB468);

// @0x1414a1ab0
void FUN_1414a1ab0()
{
    if (TSingleton<CItemRePackingScrollTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)((void*)FUN_140f64150());
        TSingleton<CItemRePackingScrollTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1AB0, FUN_1414a1ab0, 94, 0x37F4881A);

// @0x1414a1b10
void FUN_1414a1b10()
{
    if (TSingleton<CItemRemakeScrollTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemRemakeScrollTable>::GetInstance();
        TSingleton<CItemRemakeScrollTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1B10, FUN_1414a1b10, 94, 0x164B42F5);

// @0x1414a1b70
void FUN_1414a1b70()
{
    if (TSingleton<CItemSocketScrollTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)TSingleton<CItemSocketScrollTable>::GetInstance();
        TSingleton<CItemSocketScrollTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1B70, FUN_1414a1b70, 94, 0xE10587C9);

// @0x1414a1bd0
void FUN_1414a1bd0()
{
    if (TSingleton<CItemSocketTable>::s_instance != 0)
    {
        delete (Unk_VirtualDtor*)FUN_14052d200();
        TSingleton<CItemSocketTable>::s_instance = 0;
    }
}
MS2_REPLACE(0x1414A1BD0, FUN_1414a1bd0, 94, 0x927F4412);
