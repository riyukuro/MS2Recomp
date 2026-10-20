// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWorldMapDialog, the world map window: see
// uiworldmapdialog.h. The world map records (UIWorldMap::*) are in placeholder/uiworldmap.h, their owner
// WorldMapManager in placeholder/worldmapmanager.h.
// MS2-UNIT: ?\uiworldmapdialog.cpp
// MS2-RANGE: 0x14011f630-0x14011f750 .text$di
// MS2-RANGE: 0x141b53fc0-0x141b6db40 .text$mn
// MS2-PIN: ?GetValueAt@?$CAtlMap@HV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@QEAAAEAV?$MS2Ptr@VCQuestData@@@@PEAU__POSITION@@@Z 0x141b69540 ; caller FUN_141b58f80 (the quest maps)
// MS2-PIN: ?GetValueAt@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAAEAV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@PEAU__POSITION@@@Z 0x141b695b0 ; caller FUN_141b58f80 (the field npc map)
// MS2-PIN: memcpy_s 0x141b6d9f0 ; the ucrt inline (CAtlArray<unsigned>::Append of Values<unsigned>::Get)
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUIWorldMapDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x141b628a0 ; prop
// MS2-PIN: ??$?8PEAVUIWorldMapDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIWorldMapDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x141b62910 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@V?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@V?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@PEAX@0@AEAPEAU10@@Z 0x141b67470 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@0@AEAPEAU10@@Z 0x141b67480 ; unique
// MS2-PIN: ??$forward@AEAPEAUTooltipEntry@UIWorldMap@@@std@@YAAEAPEAUTooltipEntry@UIWorldMap@@AEAPEAU12@@Z 0x141b67490 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x141b679a0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@QEAA@AEBV0@@Z 0x141b67ae0 ; prop
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VMapTile@UIWorldMap@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@1@@Z 0x141b67cb0 ; unique
// MS2-PIN: ??0?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_List_node@V?$MS2Ptr@VMapTile@UIWorldMap@@@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@1@@Z 0x141b67db0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x141b67f10 ; unique
// MS2-PIN: ??0?$allocator@U?$_List_node@V?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x141b68100 ; unique
// MS2-PIN: ??0?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@QEAA@XZ 0x141b68110 ; unique
// MS2-PIN: ??1?$MS2Ptr@VFieldSearchInfo@UIWorldMap@@@@QEAA@XZ 0x141b685a0 ; prop
// MS2-PIN: ??7?$MS2Ptr@VIconInfo@UIWorldMap@@@@QEBA_NXZ 0x141b689f0 ; unique
// MS2-PIN: ??7?$MS2Ptr@VMapTile@UIWorldMap@@@@QEBA_NXZ 0x141b68a20 ; unique
// MS2-PIN: ??7?$MS2Ptr@VCFishingSpotData@@@@QEBA_NXZ 0x141b68a50 ; unique
// MS2-PIN: ??8?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@QEBA_NPEAVAddtionalInfo@UIWorldMap@@@Z 0x141b68a80 ; unique
// MS2-PIN: ??8?$MS2Ptr@VIconInfo@UIWorldMap@@@@QEBA_NPEAVIconInfo@UIWorldMap@@@Z 0x141b68b00 ; unique
// MS2-PIN: ??C?$MS2Ptr@VAddtionalInfo@UIWorldMap@@@@QEBAPEAVAddtionalInfo@UIWorldMap@@XZ 0x141b68c70 ; unique
// MS2-PIN: ??D?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@QEBAAEBV?$MS2Ptr@VMapTile@UIWorldMap@@@@XZ 0x141b68ca0 ; unique
// MS2-PIN: ?vfunc_48@UIWorldMapDialog@@UEAAHXZ 0x141b69530 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141b69ea0 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@HV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x141b69f90 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$MS2Ptr@VCQuestData@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VCQuestData@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VCQuestData@@@@@Z 0x141b6a050 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x141b6b700 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x141b6b710 ; unique
// MS2-PIN: ?_Unwrapped@?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@QEBAPEAV?$MS2Ptr@VMapTile@UIWorldMap@@@@XZ 0x141b6c8a0 ; unique
// MS2-PIN: ?begin@?$vector@UTooltipEntry@UIWorldMap@@V?$allocator@UTooltipEntry@UIWorldMap@@@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UTooltipEntry@UIWorldMap@@@std@@@std@@@2@XZ 0x141b6caf0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141b6ce80 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x141b6cee0 ; unique
// MS2-PIN: ?end@?$list@V?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@V?$allocator@V?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@2@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$vector@V?$MS2Ptr@VMapTile@UIWorldMap@@@@V?$allocator@V?$MS2Ptr@VMapTile@UIWorldMap@@@@@std@@@std@@@std@@@std@@@2@XZ 0x141b6d130 ; prop
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141b6d430 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x141b6d460 ; unique
// MS2-PIN: ??$Call@VUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x141b6d4a0 ; unique
// MS2-PIN: ??$Call@VUIWorldMapDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIWorldMapDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x141b6d4e0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141b6d520 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIWorldMapDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x141b6d580 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiworldmapdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uiworldmapdialog.h"

#include <algorithm>

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/unk_blocklist.h"
#include "ms2/placeholder/worldmapmanager.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/continentregiontable.h"
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/rewardpreviewitem.h"
#include "ms2/client/ms2/uidungeonroomdialog.h"
#include "ms2/client/ms2/uiworldchampionrewarddialog.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/client/ms2/statetaxicalldata.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/ctaximanager.h"
#include "ms2/placeholder/ccashcallmanager.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/commonfiles/fieldmissiontable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/commonfiles/fishsimultedata.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/commandchat.h"

// ---- unit-local views (names invented) --------------------------------------------------------------------------------

class ASDialog : public ASUIComponent { };

// The AS function object wrapping a delegate (the same view as uishopdialog.cpp).
class ASFunction : public AScript
{
public:
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser, int nMovieId);   // 0x1422c8430
    virtual ~ASFunction();
private:
    void* m_40;
};

// The entity list a WorldService model lookup returns (worldservice.h declares it incomplete).
struct Unk_WsC_TagPtr
{
    ~Unk_WsC_TagPtr();                                                      // 0x1409f20e0
    ATL::CAtlList<efd::SmartPointer<egf::Entity> >* FUN_1409f2170() const;  // get
    ATL::CAtlList<efd::SmartPointer<egf::Entity> >* FUN_1409f2190() const;  // operator->
    void* m_0;
    void* m_8;
};

// ---- out-of-unit callees ----------------------------------------------------------------------------------------------
extern Unk_Inventory DAT_143ab2a90;                                         // the player's inventory
WorldMapManager* FUN_140cb17d0();                                           // TSingleton<WorldMapManager>::GetInstance
CFeatureManager* FUN_140166410();                                           // TSingleton<CFeatureManager>::GetInstance
CFieldMetaTable* FUN_140700390();                                           // TSingleton<CFieldMetaTable>::GetInstance
CStringTable* FUN_1401a9d70();                                              // TSingleton<CStringTable>::GetInstance
CInputKeyHandler* FUN_14025e7c0();                                          // TSingleton<CInputKeyHandler>::GetInstance
CQuestManager* FUN_140764020();                                             // TSingleton<CQuestManager>::GetInstance
bool FUN_14036d570(CFeatureManager* pFeatures, int nFeature);               // the content switch is on
int FUN_141654700(void* pPlayer);                                           // the player's job
void FUN_141415600(const CString& strBindID);                               // release the items bound to the name
int FUN_1409c1750(const Scaleform::GFx::Value& v);                          // the value as an int
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);   // pRetVal = v
Scaleform::GFx::Value* FUN_1412dd680(Scaleform::GFx::Value* pOut, const wchar_t* sz);   // a string value
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);                 // operator== (CStringW, const wchar_t*)
void FUN_14151f200();                                                       // show the next queued message box
void FUN_140874440(void* pCfg, const char* szSection, const char* szKey, int nValue, int bFlag);   // save a setting
void FUN_1408741a0(void* pCfg, const char* szSection, const char* szKey, int* pnValue);           // load a setting
void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW strTag);                     // a notice box by string id
void FUN_140d73aa0(CStringW strText, int nType, IMessageListener* pListener, CStringW strTag);                           // a notice box
CStringW FUN_1409eec40(int nStringId);                                      // a string table text by id
CStringW FUN_14028de60(int nStringId);                                      // a string table text by id
CStringW FUN_140298ea0(CStringW strKey);                                    // a string table text by key
CStringW FUN_1401aa6a0(int nNpcId);                                         // the npc's name
CStringW FUN_140a22c00(int nStrId, const CStringW& strArg1, const unsigned short& nArg2);   // FormatStringId<CStringW, unsigned short>
CStringW FUN_141a46280(int nStrId, const CStringW& strArg1, const wchar_t (&szArg2)[3]);   // FormatStringId<CStringW, wchar_t[3]>
CStringW FUN_1408116a0(int nStrId, const int& nArg);                        // FormatStringId<int>
CStringW FUN_14028dee0(int nStrId, const fmt::ArgList& args);               // a string table text by id, formatted
int FUN_14092f640();                                                        // the current channel
float FUN_140966f00(NiPoint3 kA, NiPoint3 kB);
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);                             // the quest's data record
int FUN_14074b050(CQuestData* pData);                                       // the quest's state
bool FUN_1407640c0(CQuestData* pData);
CStringW FUN_1416e4df0(int nQuestId);                                       // the quest's name
CStringW FUN_1401d0160(const wchar_t* sz, const CStringW& str);             // ATL::operator+(const wchar_t*, const CStringW&)
CStringW FUN_14061ad70(const CStringW& str, const wchar_t* sz);             // str + sz
CStringW FUN_14052bd00(int nStrId, const CStringW& strArg);                 // FormatStringId<CStringW>
CStringW FUN_1409eadb0(int nStrId, const CStringW& a1, const CStringW& a2, const CStringW& a3);   // FormatStringId<CStringW x3>
__int64 FUN_141656a80(void* pPlayer);                                       // the player's character id
CPartyManager* FUN_1409670d0();                                             // TSingleton<CPartyManager>::GetInstance
CBuddyManager* FUN_14097a780();                                             // TSingleton<CBuddyManager>::GetInstance
DungeonRoomTable* FUN_14031c2a0();                                          // TSingleton<DungeonRoomTable>::GetInstance
extern ATL::CAtlArray<unsigned int> DAT_143ab3058;                          // the fields with a world map icon
CStringW FUN_1409e97f0(int nStrId, const unsigned int& nArg);              // FormatStringId<unsigned>
CStringW FUN_140632a60(int nStrId, const CStringW& a1, const CStringW& a2);  // FormatStringId<CStringW, CStringW>
CStringW FUN_14028b8e0(const CStringW& strKey);                             // a string table text by key
CFishingManager* FUN_140953f20();                                           // TSingleton<CFishingManager>::GetInstance
void* FUN_1422bb8b0(int nMovieId);                                          // the movie of an id
CFieldMissionTable* FUN_140d738f0();                                        // TSingleton<CFieldMissionTable>::GetInstance
int FUN_14037c450(CFieldMissionTable* pTable, int nRound);                  // there is a previous round
int FUN_14037c510(CFieldMissionTable* pTable, int nRound);                  // there is a next round
CStringW FUN_14062b4f0(CStringW strKey, const int& nArg);                   // a string table text by key, formatted
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);           // a string table text by key, formatted
CReservedWordTable* FUN_1403b4750();                                        // TSingleton<CReservedWordTable>::GetInstance
CString FUN_14021a6b0(int nId);                                             // the name movie of an id
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
extern unsigned DAT_143ae0fb8;                                              // the debug "show all fields" switch
void FUN_14256e3e0(void* pMovie, Scaleform::GFx::Value* pValue);           // movie->CreateArray
int FUN_141b71c00(unsigned short nLevel);                                   // the good taxi applies to the level
CStringW FUN_1409404f0(__int64 n);                                          // the number with separators
CStringW FUN_1409e88d0(int nStrId, const unsigned short& nArg);            // FormatStringId<unsigned short>
CStringW FUN_14016a730(const char* sz, int nCodePage);                     // widen
int FUN_140408410(const ATL::CAtlArray<int>& arr, const unsigned int& n);   // the index of a value or -1
extern ATL::CAtlArray<int> DAT_143ab3078;                                   // the taxi stops the player has found
QuestDataTable* FUN_1407476c0();                                            // TSingleton<QuestDataTable>::GetInstance
void FUN_1416e5890(int nQuestId, ATL::CAtlArray<CStringW>& lines);          // the quest's mission tooltip lines
CFishingTable* FUN_1403b4740();                                             // TSingleton<CFishingTable>::GetInstance
unsigned int FUN_141662750(PCBase* pActor, int nKind);                      // the actor's mastery
extern __int64 DAT_143ab2898;                                               // the player's meso
CGameRule* FUN_1401c0d90();                                                 // TSingleton<CGameRule>::GetInstance
bool FUN_140a55d20(CFieldDataCli* pField, CStringW* pstrError);             // the field can be entered (else the reason)
__int64 FUN_140632990(__int64 nValue, float fRate);                        // a meso value scaled by a rate
float FUN_1411e1110(Unk_PCEquipSet* pEquips, int nStat);                    // a stat rate of the equips (0xaa: taxi discount)
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);           // a string table format with one string
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
CStringW FUN_140f1fa40(CStringW strKey, const CStringW& strArg, const __int64& nArg);   // a string table format (string, meso)
CStringW FUN_140c160b0(CStringW strKey, const __int64& nArg);              // a string table format (meso)
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> kHandler, CStringW strText);   // a yes/no box
void FUN_14151f150(MS2Ptr<CMsgBoxData> spBox);                              // show a message box
static MS2Ptr<CMsgBoxData> FUN_141b62e40(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> kHandler, __int64 nPrice);   // the priced prompt (below)
CStringW FUN_141ac31a0(int nStrId, const CStringW& strArg, const __int64& nArg);  // FormatStringId<CStringW, __int64>
CStringW FUN_14028de60(int nStrId);                                         // string table text by id
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UIDialog* pDialog);   // the common dialog AS calls
CRewardPreviewTable* FUN_140f26650();                                       // TSingleton<CRewardPreviewTable>::GetInstance
class UIBossRewardPreviewDialog : public UIDialog { public: int FUN_140f25ad0(int nNpcId); };   // the boss reward preview (view)
UIBossRewardPreviewDialog* FUN_141a46590(int nUiId);                        // the open boss reward preview dialog
UIWorldChampionRewardDialog* FUN_14193f2b0(int nUiId);                      // the open world champion reward dialog
UIDungeonRoomDialog* FUN_140961550(int nUiId);                              // the open dungeon room dialog
static MS2Ptr<CMsgBoxData> FUN_141b62fc0(Delegate<bool(int, const CMsgBoxData&)> kHandler, CStringW strKey, CStringW strArg);   // the formatted prompt (below)

// Unk_CommandChat: placeholder/commandchat.h (the chat command record).
void FUN_141276f80(const Unk_CommandChat& record);                       // send a chat line
QuestDataTable* FUN_1407476c0();                                            // TSingleton<QuestDataTable>::GetInstance
void FUN_141415450(const CString& strBindID, MS2Ptr<CItem> spItem, int a, int b, int c);   // bind an item under the name
void FUN_141415560(const CString& strBindID, ItemInfoSlot::CreateParam* pParam);   // bind a slot of the parameters under the name
CString FUN_1402bad60(const char* szFormat, const int* pn);                 // a narrow format with one int
// The client resources record (icon paths): +0x1d0 the stat point icon; 0x140cca050 the skill point icon of a kind.
class Unk_WmIcons { public: CString FUN_140cca050(int nKind); char m_pad_0[0x1d0]; CString m_1d0; };
Unk_WmIcons* FUN_1401d31f0();                                               // the client resources record
CContinentRegionTable* FUN_1403782c0();                                     // TSingleton<CContinentRegionTable>::GetInstance
int FUN_14074b030(CQuestData* pData);                                       // the quest id
int FUN_14074b1c0(CQuestData* pData, int nBit);                             // a quest flag bit
int FUN_1416e8060(int nChapter);                                            // the chapter is hidden
class Unk_WmNpcTable { public: int FUN_140764e40(int nField, unsigned nNpcId); };   // the npc placement table (view)
Unk_WmNpcTable* FUN_14109a710();                                            // the npc placement table
CTaxiManager* FUN_1409f24a0();                                              // TSingleton<CTaxiManager>::GetInstance
CUIService* FUN_1403ed2b0();                                                // TSingleton<CUIService>::GetInstance
CCashCallManager* FUN_140d294c0();                                          // TSingleton<CCashCallManager>::GetInstance
IClientPlatform* FUN_140d86260();                                           // the client platform
void FUN_140291bc0(efd::Point3* pRot);                                      // normalize the angles
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int n, CStringW strTag);   // a message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                              // show a message box
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);                                // the npc data record
void* FUN_140165cf0(void* pNode, const char* szName);                       // the first child element by name
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);                   // Value = Int
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);          // Value = UInt
void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned long long n);    // Value = UInt64
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);      // Value = the object's value

// ---- functions of the unit defined below ---------------------------------------------------------------
CStringW FUN_141b62980(int nStrId, const __int64& v0);                     // FormatStringId<__int64>
static CStringW FUN_141b621d0(int nChannel);                                // the channel line
static CStringW FUN_141b622d0(unsigned short nLevel, int nKind);           // the quest level line
template <class T> T FUN_141b62a20(int nQuestId, const T& a0, const T& a1, const T& a2, const T& a3);   // a value by the quest's state
static bool FUN_141b62110(const MS2Ptr<UIWorldMap::MapTile>& spA, const MS2Ptr<UIWorldMap::MapTile>& spB);   // the tile order

// ---- statics --------------------------------------------------------------------------------------------------------
static UICommon::CMyPCKeyInputController s_keyInput;

// @0x141b53fc0
UIWorldMapDialog::UIWorldMapDialog()
    : m_nWorld(0), m_nField(0), m_190(0), m_194(0), m_198(0), m_nMode(0), m_1c0(0), m_1c4(0), m_1c8(0),
      m_210(0), m_214(0), m_218(0)
{
    m_88 = 1;
    FUN_141924170(1);
    m_158 = 0;
    m_5c = 1;
    m_80 = 1;
    memset(m_islandIndex, 0, sizeof(m_islandIndex));
    TSingleton<Client::Constants>::GetInstance()->WorldmapSpecialFunctionNpcID.Get(m_npcIds);
    TSingleton<Client::Constants>::GetInstance()->WorldmapSpecialFunctionNpcFrame.Get(m_npcFrames);
    TSingleton<Client::Constants>::GetInstance()->WorldmapSpecialFunctionNpcTooltip.Get(m_npcTooltips);
}

// @0x141b54250
UIWorldMapDialog::~UIWorldMapDialog()
{
    m_1a0.clear();
    m_tiles.clear();
}

// @0x141b54350
CString UIWorldMapDialog::vfunc_1()
{
    return "WorldMapDialog";
}
MS2_REPLACE_METHOD(0x141B54350, UIWorldMapDialog, vfunc_1, 61, 0x85A1F562);

// @0x141b543a0
int UIWorldMapDialog::vfunc_65()
{
    FUN_140cb17d0()->PollChangedFiles();
    if (vfunc_55() == 0)
    {
        if (m_30.get() != 0)
            m_30->Invoke("setTopMostLayer");
    }
    return UIDialog::vfunc_65();
}
MS2_REPLACE_METHOD(0x141B543A0, UIWorldMapDialog, vfunc_65, 129, 0x25378835);

// @0x141b54430
void UIWorldMapDialog::vfunc_67()
{
    if (m_30.get() != 0)
    {
        for (size_t i = 0; i < 2; i++)
            m_islandIndex[i] = FUN_1409c1750(m_30->FUN_140c1c8c0("getCachedIslandIndex", i));
    }
    FUN_141415600(vfunc_1());
    UIDialog::vfunc_67();
    m_tiles.clear();
    m_194 = 0;
    vfunc_47(m_194 == 0);
    m_1c0 = 0;
    m_1c4 = 0;
    m_1c8 = 0;
    m_1a0.clear();
    m_210 = 0;
    m_214 = 0;
}
MS2_REPLACE_METHOD(0x141B54430, UIWorldMapDialog, vfunc_67, 485, 0x1E94AC03);

// @0x141b54620
void UIWorldMapDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    FUN_141b5b190();
}
MS2_REPLACE_METHOD(0x141B54620, UIWorldMapDialog, vfunc_72, 34, 0xB562F763);

// @0x141b54650
int UIWorldMapDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (vfunc_55() != 0 || !m_30)
        return 0;
    ASDialog* pDialog = dynamic_cast<ASDialog*>(m_30.get());
    if (pDialog == 0)
        return 0;
    if (!FUN_14025e7c0()->FUN_14116d9c0(0x1c, false, 0))
        return 0;
    if (FUN_140b632f0() != 0)
    {
        if (FUN_140b632f0()->FUN_1422d4e20(CString(m_20)) == 0)
            return 0;
    }
    MS2Ptr<ASTextInput> spInput = FUN_140e35bd0("m_fieldSearch");
    if (spInput.get() != 0)
    {
        if (spInput->FUN_1422c76c0() == 0)
        {
            pDialog->FUN_1422c7630(0);
            spInput->FUN_1422c7630(1);
        }
        else if (spInput->Invoke("processEnterKey").GetBool())
        {
            pDialog->FUN_1422c7630(1);
            spInput->FUN_1422c7630(0);
            FUN_141b60490(spInput->FUN_1422e0b00());
        }
    }
    return 1;
}

// @0x141b54920
void UIWorldMapDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    void* pPlayer = TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    m_30->Invoke("setTooltipFunctionBossIcon",
        ASFunction(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIWorldMapDialog::FUN_141b56c30), 0, 2));
    ASObj island(2);
    island.FUN_1407cbbe0("karkarIsland", FUN_14036d570(FUN_140166410(), 3));
    m_30->FUN_141b62c20("initializeIsland", FUN_141654700(pPlayer), island);
    for (size_t i = 0; i < 2; i++)
        m_30->FUN_141b62ce0("setCachedIslandIndexByWorld", i, m_islandIndex[i]);
    m_nField = FUN_141b57410();
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(FUN_141b69690());
    if (!spField)
        return;
    m_nWorld = FUN_140cb17d0()->WorldOfField(spField->FUN_140375350());
    FUN_141b58e80();
    FUN_141b60c40(m_nField, m_210 != 0);
    FUN_141b5be10();
    if (m_210 != 0)
        FUN_141b61ff0(m_nField);
    if (m_170.CompareNoCase("missionAttack") == 0)
        m_214 = 1;
    if (m_214 != 0)
        m_30->FUN_1409ba0d0("setMissionAttackMode", 1, FUN_140764020()->FUN_1416d0e20());
}

// @0x141b54d50
void UIWorldMapDialog::vfunc_79(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    UIDialog::vfunc_79(p);
    if (vfunc_55() != 0 || !m_30)
        return;
    if (pPacket->FUN_14070fe80() == 0x84)
    {
        char nMode = pPacket->vfunc_o8_1();
        if (nMode == 0)
            FUN_141b57580(pPacket);
        else if (nMode == 1)
            FUN_141b57620(pPacket);
    }
    else if (pPacket->FUN_14070fe80() == 0x85)
    {
        char nMode = pPacket->vfunc_o8_1();
        if (nMode == 0)
            FUN_140d73bc0(0xa1, 0, 0, CStringW(L""));
        else if (nMode == 1)
            FUN_140d73bc0(0xa4, 0, 0, CStringW(L""));
    }
}
MS2_REPLACE_METHOD(0x141B54D50, UIWorldMapDialog, vfunc_79, 424, 0x7A7BDACA);

// @0x141b54f00
void UIWorldMapDialog::vfunc_80(void* p)
{
    Unk_BlockList request(*static_cast<CInPacket*>(p));
    Unk_BlockEntry entry;
    if (request.Find("m_fieldSearch", entry) == true)
    {
        if (entry.m_nFlags == 0)
        {
            FUN_141b60d40(CStringW(entry.m_strName));
        }
        else
        {
            FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
            MS2Ptr<ASTextInput> spInput = FUN_140e35bd0("m_fieldSearch");
            if (spInput.get() != 0)
                spInput->FUN_1422e0a60(CString(""));
        }
    }
}
MS2_REPLACE_METHOD(0x141B54F00, UIWorldMapDialog, vfunc_80, 523, 0xDEF8A522);

// @0x141b55120
int UIWorldMapDialog::vfunc_53(void* pCfg)
{
    UIDialog::vfunc_53(pCfg);
    FUN_140874440(pCfg, "setting", "displayProperQuest", m_display.m_18[3], 1);
    FUN_140874440(pCfg, "setting", "displayProperDungeon", m_display.m_18[4], 1);
    return 1;
}
MS2_REPLACE_METHOD(0x141B55120, UIWorldMapDialog, vfunc_53, 141, 0xE15B5A3A);

// @0x141b551c0
int UIWorldMapDialog::vfunc_54(void* pCfg)
{
    UIDialog::vfunc_54(pCfg);
    m_display.FUN_141b95000();
    if (pCfg != 0 && FUN_140165cf0(pCfg, "setting") != 0)
    {
        m_display.m_18[0] = ((unsigned char*)TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n20)[0];
        m_display.m_18[1] = ((unsigned char*)TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n20)[1];
        m_display.m_18[2] = ((unsigned char*)TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n20)[2];
        FUN_1408741a0(pCfg, "setting", "displayProperQuest", &m_display.m_18[3]);
        FUN_1408741a0(pCfg, "setting", "displayProperDungeon", &m_display.m_18[4]);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141B551C0, UIWorldMapDialog, vfunc_54, 308, 0xBC07D643);

// @0x141b55300
// MS2-FUNCTIONAL: the AS callback dispatch (/Od temporaries of the notice strings; per-branch ASData frames)
int UIWorldMapDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 1;
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0))
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnRadioBtn", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_nMode = data.FUN_1422b8a10();
            FUN_141b5d390();
        }
        return 1;
    }
    if (_stricmp("OnChangeWorld", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_nWorld = data.FUN_1422b8a10();
            FUN_141b58200();
        }
        return 1;
    }
    if (_stricmp("OnTaxi", szMethod) == 0)
    {
        if (m_214 != 0)
            return 1;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            m_190 = data.FUN_1422b8b10();
            short nLevel = (short)pPlayer->vfunc_78();
            __int64 nFare = FUN_1409f24a0()->FUN_14085f780(FUN_141b69690(), m_190, nLevel);
            if (FUN_141b69690() == m_190)
            {
                FUN_140d73bc0(0x8a, 0, 0, CStringW(L""));
                return 1;
            }
            if (nFare < 1)
            {
                CStringW strKey(L"s_err_taxi_continent");
                FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, CStringW(L""));
                return 1;
            }
            if (pPlayer->FUN_141527160(0x25) == 0)
            {
                FUN_140d73bc0(0x93, 0, 0, CStringW(L""));
                return 1;
            }
            CStringW strText = FUN_141ac31a0(0x8b, FUN_1401a9d70()->FUN_141811980(3, m_190), nFare);
            FUN_140d73aa0(CStringW(strText), 1, static_cast<IMessageListener*>(this), CStringW(L"onTaxi"));
        }
        return 1;
    }
    if (_stricmp("OnCashTaxi", szMethod) == 0)
    {
        if (m_214 != 0)
            return 1;
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_141b60e90(data.FUN_1422b8b10(), pPlayer);
        return 1;
    }
    if (_stricmp("OnBoss", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nKey = data.FUN_1422b8b10();
            MS2Ptr<UIWorldMap::IconInfo> spIcon = FUN_140cb17d0()->GetOrAddIconInfo(nKey);
            if (!spIcon || spIcon->m_20.m_0 == 0)
                return 1;
            if (spIcon->m_20.m_20 == 1)
            {
                if (FUN_14036d570(FUN_140166410(), 0x1a))
                {
                    MS2Ptr<RewardPreviewInfo> spPreview = FUN_140f26650()->GetBoss(spIcon->m_20.m_0);
                    UIBossRewardPreviewDialog* pDialog;
                    if (spPreview.operator RewardPreviewInfo*() != 0 && (pDialog = FUN_141a46590(0x4efb)) != 0)
                    {
                        FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4efb);
                        pDialog->FUN_140f25ad0(spIcon->m_20.m_0);
                        FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4efb);
                    }
                }
            }
            else
            {
                UIWorldChampionRewardDialog* pDialog;
                if (spIcon->m_20.m_20 == 2 && (pDialog = FUN_14193f2b0(0x4f68)) != 0)
                    pDialog->FUN_140feb5b0();
            }
        }
    }
    else if (_stricmp("OnDungeon", szMethod) == 0)
    {
        if (FUN_14036d570(FUN_140166410(), 0x1a))
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs))
            {
                int nId = data.FUN_1422b8b10();
                UIDungeonRoomDialog* pDialog = FUN_140961550(0x4ebd);
                if (pDialog != 0)
                {
                    FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4ebd);
                    if (pDialog->FUN_1412b8f00(nId))
                        FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4ebd);
                }
            }
        }
    }
    else if (_stricmp("OnPortal", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_198 = data.FUN_1422b8b10();
            int nField = TSingleton<WorldService>::GetInstance()->FUN_141bd3060();
            if (nField == m_198)
            {
                FUN_140d73bc0(0xa3, 0, 0, CStringW(L""));
                return 1;
            }
            if (!FUN_141b60b40(nField, m_198))
            {
                FUN_140d73bc0(0xa4, 0, 0, CStringW(L""));
                return 1;
            }
            FUN_140d73aa0(FUN_14028de60(0xa8), 1, static_cast<IMessageListener*>(this), CStringW(L"onPortal"));
        }
        return 1;
    }
    else if (_stricmp("OnSelected", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_141b60490(data.FUN_1422b8f40());
        return 1;
    }
    else if (_stricmp("OnSetting", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            m_display.m_18[3] = data.FUN_1422b8a90();
            m_display.m_18[4] = data.FUN_1422b8a90();
            FUN_141b5bd30();
        }
        return 1;
    }
    else if (_stricmp("OnMouseClickTile", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned nKey = data.FUN_1422b8b10();
            FUN_141b60c40(nKey, data.FUN_1422b8a90());
            FUN_141b61ff0(nKey);
            MS2Ptr<ASTextInput> spSearch = FUN_140e35bd0("m_fieldSearch");
            if (spSearch.operator ASTextInput*() != 0)
                spSearch->FUN_1422e0a60(CStringA(""));
            if (m_214 != 0 && FUN_140764020()->FUN_1416d0e60(nKey) != 0)
                FUN_141b62fc0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIWorldMapDialog::FUN_141b5af30),
                    CStringW(L"s_worldmap_mission_attack_msg"), FUN_1401a9d70()->FUN_141811980(3, nKey));
            MS2Ptr<UIWorldMap::MapTile> spTile = FUN_140cb17d0()->FindMapTileByKey(nKey);
            UIDungeonRoomDialog* pDialog;
            if (spTile.operator UIWorldMap::MapTile*() != 0 && spTile->m_70 != 0 && (pDialog = FUN_140961550(0x4ebd)) != 0)
            {
                FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4ebd);
                pDialog->FUN_1412b8ff0(spTile->m_70);
                FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4ebd);
            }
            if (FUN_14025e7c0()->FUN_14116d950(0x1d, 0, 0))
            {
                Unk_CommandChat record;
                record.kind = 0;
                record.message = StringFormat(L"/MoveField {0} 1", nKey);
                FUN_141276f80(record);
                return 1;
            }
        }
    }
    else if (_stricmp("onClickSearchInfo", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nKey = data.FUN_1422b8b10();
            FUN_141b61ff0(nKey);
            FUN_141b605e0(FUN_1401a9d70()->FUN_141811980(3, nKey));
        }
    }
    else if (_stricmp("onClickSearchInfoIcon", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strKind = data.FUN_1422b8f40();
            int nId = data.FUN_1422b8b10();
            if (strKind.Find(L"dungeon", 0) == -1)
            {
                if (strKind.Find(L"cashTaxi", 0) != -1)
                    FUN_141b60e90(nId, static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0()));
            }
            else
            {
                UIDungeonRoomDialog* pDialog = FUN_140961550(0x4ebd);
                if (pDialog != 0)
                {
                    FUN_1403ed2b0()->FUN_141adc690((eUIClassID)0x4ebd);
                    pDialog->FUN_1412b8ff0(nId);
                    FUN_1403ed2b0()->FUN_141adc530((eUIClassID)0x4ebd);
                }
            }
        }
    }
    else if (_stricmp("onClickMissionReward", szMethod) == 0)
    {
        FUN_141b5cbc0();
    }
    else if (_stricmp("onClickMissionRewardPrev", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nRound = FUN_14037c450(FUN_140d738f0(), data.FUN_1422b8a10());
            if (nRound != 0)
                FUN_141b5cc40(nRound);
        }
    }
    else if (_stricmp("onClickMissionRewardNext", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nRound = FUN_14037c510(FUN_140d738f0(), data.FUN_1422b8a10());
            if (nRound != 0)
                FUN_141b5cc40(nRound);
        }
    }
    else if (_stricmp("onCllckFieldMission", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nKey = data.FUN_1422b8b10();
            bool bFlag = data.FUN_1422b8a90();
            FUN_141b60c40(nKey, bFlag);
            m_210 = bFlag;
        }
    }
    else if (_stricmp("onClickSkyFortressMode", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_218 = data.FUN_1422b8a90();
    }
    return 0;
}

// @0x141b56a20
int UIWorldMapDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() != 0 || dynamic_cast<UIMessageBox*>(pSender) == 0)
        return 0;
    int nResult = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    FUN_14151f200();
    if (nResult != 0)
        return 0;
    if (FUN_1403b3c40(strTag, L"onTaxi"))
        FUN_141b5a550(m_190);
    else if (FUN_1403b3c40(strTag, L"onPortal"))
        FUN_141b5afe0(m_198);
    else if (FUN_1403b3c40(strTag, L"onCashTaxi"))
        FUN_141b5aa70(m_190);
    else if (FUN_1403b3c40(strTag, L"onTopMostLayer"))
        FUN_140b632f0()->FUN_1422d4dd0(CString(m_20));
    return 1;
}

// @0x141b56c30
// MS2-FUNCTIONAL: the boss icon tooltip (frame layout of the temporaries)
void UIWorldMapDialog::FUN_141b56c30(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0() == 0)
        return;
    ASObj arg(params.pArgs[0], 2);
    MS2Ptr<UIWorldMap::IconInfo> spIcon = FUN_140cb17d0()->GetOrAddIconInfo(arg.FUN_1422bb870().GetUInt());
    if (spIcon == 0)
        return;
    ASTooltip tooltip(2);
    tooltip.FUN_1409c6d70("WorldMapTooltip_Boss");
    tooltip.FUN_1409c6dc0(1);
    tooltip.FUN_1409c6e00(300);
    tooltip.FUN_1409c6e30(5000);
    ASArray unused(2);
    unsigned __int64 nMaxChannels = *TSingleton<Client::Constants>::GetInstance()->WorldmapBossTooltipCount.Get();
    UIWorldMap::IconInfo::Rect& boss = spIcon->m_20;
    MS2Ptr<CNpcData> spNpc = FUN_1406cd330(boss.m_0);
    if (spNpc == 0)
        return;
    CStringW strTitle;
    if (!spNpc->HasPropertyTag(3))
    {
        unsigned short nLevel = spNpc->GetLevel();
        strTitle = FUN_140a22c00(0x71a, FUN_1401aa6a0(boss.m_0), nLevel);
    }
    else
    {
        strTitle = FUN_141a46280(0x71a, FUN_1401aa6a0(boss.m_0), L"??");
    }
    tooltip.FUN_1407cbb20("text", strTitle);
    if (boss.m_20 == 1)
    {
        ASArray channels(2);
        for (size_t i = 0; i < boss.m_8.size() && i < nMaxChannels; i++)
        {
            CStringW strChannel;
            if (boss.m_8[i] == FUN_14092f640())
                strChannel = FUN_1408116a0(0x71b, boss.m_8[i]);
            else
                strChannel = FUN_1408116a0(0x71c, boss.m_8[i]);
            Scaleform::GFx::Value v;
            channels.FUN_1422bc050(*FUN_1412dd680(&v, strChannel));
        }
        tooltip.FUN_140c16160("channels", ASArray(channels));
        CStringW strExtra;
        if (nMaxChannels < boss.m_8.size())
        {
            __int64 nMore = boss.m_8.size() - nMaxChannels;
            tooltip.FUN_1407cbb20("extra", FUN_141b62980(0x71d, nMore));
        }
    }
    else
    {
        tooltip.FUN_1407cbb20("extra", FUN_140298ea0(CStringW(L"s_worldmap_tooltip_channel_all")));
        tooltip.FUN_1407cbb20("enableLClick", FUN_14028de60(0x764));
    }
    FUN_140cb17d0()->BuildNpcRewardPreview(boss.m_0, &tooltip);
    FUN_1409b4bc0(params.pRetVal, tooltip.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x141B56C30, UIWorldMapDialog, FUN_141b56c30, 1999, 0x1CCFE87F);

// @0x141b57410
int UIWorldMapDialog::FUN_141b57410()
{
    int nField = TSingleton<WorldService>::GetInstance()->FUN_141bd3060();
    if (CFieldData::FUN_140374410(nField))
    {
        MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
        if (pPlayer != 0)
            nField = pPlayer->FUN_14152e950();
    }
    MS2Ptr<UIWorldMap::MapTile> spTile = FUN_140cb17d0()->FindMapTileByKey(nField);
    if (spTile == 0)
    {
        unsigned int nParent;
        if (FUN_140700390()->FUN_1406fc110(nField, &nParent) == 0)
        {
            int nDefault = FUN_140cb17d0()->SelectedField();
            if (nDefault != 0)
            {
                bool bFound = FUN_140cb17d0()->FindMapTileByKey(nDefault).get() != 0;
                int nOld = nField;
                nField = nDefault;
                if (!bFound)
                {
                    unsigned int nParent2;
                    nField = nOld;
                    if (FUN_140700390()->FUN_1406fc110(nOld, &nParent2) != 0)
                        nField = nParent2;
                }
            }
        }
        else
        {
            nField = nParent;
        }
    }
    return nField;
}
MS2_REPLACE_METHOD(0x141B57410, UIWorldMapDialog, FUN_141b57410, 349, 0x33CA565A);

// @0x141b57580
void UIWorldMapDialog::FUN_141b57580(CInPacket* pPacket)
{
    FUN_140cb17d0()->LoadIconPacket(pPacket);
    if (m_nMode == 2)
    {
        FUN_140cb17d0()->ClearAddtionalInfos();
        FUN_141b59d40();
    }
    FUN_141b58f00();
    FUN_141b58f80();
    FUN_141b5a290();
    FUN_141b59840();
    FUN_141b59a80();
    FUN_141b57660();
    FUN_141b57740();
    FUN_141b57870();
}
MS2_REPLACE_METHOD(0x141B57580, UIWorldMapDialog, FUN_141b57580, 154, 0x70657340);

// @0x141b57620
void UIWorldMapDialog::FUN_141b57620(CInPacket* pPacket)
{
    FUN_140cb17d0()->LoadAddtionalInfos(pPacket);
    FUN_141b58220();
}
MS2_REPLACE_METHOD(0x141B57620, UIWorldMapDialog, FUN_141b57620, 47, 0xE0025F2A);

// @0x141b57660
void UIWorldMapDialog::FUN_141b57660()
{
    if (m_30 && m_1c8 != 0)
    {
        CStringW strName = FUN_1401a9d70()->FUN_141811980(3, m_1c8);
        FUN_141b605e0(strName);
        FUN_141b60c40(m_1c8, false);
        m_1c8 = 0;
    }
}
MS2_REPLACE_METHOD(0x141B57660, UIWorldMapDialog, FUN_141b57660, 203, 0xD190983F);

// @0x141b57740
void UIWorldMapDialog::FUN_141b57740()
{
    if (m_strSearch.GetLength() != 0)
    {
        MS2Ptr<ASTextInput> spInput = FUN_140e35bd0("m_fieldSearch");
        if (spInput.get() != 0)
            spInput->FUN_1422e0ab0(m_strSearch);
        FUN_141b60d40(m_strSearch);
        m_strSearch.Empty();
    }
}
MS2_REPLACE_METHOD(0x141B57740, UIWorldMapDialog, FUN_141b57740, 294, 0x24CD3D3A);

// @0x141b57870
// MS2-FUNCTIONAL: the tiles of the world (frame layout of the containers)
void UIWorldMapDialog::FUN_141b57870()
{
    if (!m_30)
        return;
    m_spTile = FUN_141b5d120();
    if (m_spTile == 0)
        return;
    m_tiles.clear();
    int nCount = 0;
    std::list<TileVector> groups;
    std::map<int, TileVector> worlds = FUN_140cb17d0()->GetTileGroups();
    for (std::map<int, TileVector>::iterator it = worlds.begin(); it != worlds.end(); ++it)
    {
        if (it->first == FUN_141b69340())
        {
            groups.push_back(it->second);
            nCount += (int)it->second.size();
        }
    }
    m_30->Invoke("clearMapTile");
    m_30->Invoke("selectWorld", FUN_141b69340());
    m_30->Invoke("makeDisplayTile", nCount);
    m_30->Invoke("setInitalRadioBtn", m_nMode);
    m_30->Invoke("setVisibleRadioGroup", 0);
    int nAirTaxi = DAT_143ab2a90.FUN_140a5f7b0(10, 0);
    int nAirTaxi2 = DAT_143ab2a90.FUN_140a5f7b0(0xb, 0);
    m_30->FUN_1409ba0d0("setAirTaxiCount", nAirTaxi, nAirTaxi2);
    int nMinX = INT_MAX;
    int nMinY = INT_MAX;
    int nMaxX = INT_MIN;
    int nMaxY = INT_MIN;
    for (std::list<TileVector>::iterator it = groups.begin(); it != groups.end(); it++)
    {
        TileVector tiles = *it;
        TileVector sorted;
        for (size_t i = 0; i < tiles.size(); i++)
        {
            MS2Ptr<UIWorldMap::MapTile> spTile = tiles[i];
            NiPoint3 kTile((float)spTile->m_24, (float)spTile->m_28, (float)spTile->m_2c);
            NiPoint3 kCur((float)FUN_141b5d120()->m_24, (float)FUN_141b5d120()->m_28, (float)FUN_141b5d120()->m_2c);
            float fDistance = FUN_140966f00(kTile, kCur);
            spTile->m_50 = (int)fDistance;
            sorted.push_back(spTile);
            if (nMaxX < spTile->m_24)
                nMaxX = spTile->m_24;
            if (spTile->m_24 < nMinX)
                nMinX = spTile->m_24;
            if (nMaxY < spTile->m_28)
                nMaxY = spTile->m_28;
            if (spTile->m_28 < nMinY)
                nMinY = spTile->m_28;
        }
        std::sort(sorted.begin(), sorted.end(), FUN_141b62110);
        for (size_t i = 0; i < sorted.size(); i++)
            m_tiles.push_back(sorted[i]);
    }
    m_30->Invoke("precalculateSize", nMinX, nMaxX, nMinY, nMaxY);
    MS2Ptr<UIWorldMap::MapTile> spCur = FUN_141b5d120();
    if (spCur.get() != 0)
        m_30->Invoke("setInitalPos", spCur->m_24, spCur->m_28, spCur->m_2c, spCur->m_30);
}
MS2_REPLACE_METHOD(0x141B57870, UIWorldMapDialog, FUN_141b57870, 2428, 0xF6B08EB7);

// @0x141b58200
void UIWorldMapDialog::FUN_141b58200()
{
    FUN_141b58e80();
}
MS2_REPLACE_METHOD(0x141B58200, UIWorldMapDialog, FUN_141b58200, 24, 0x7DF05EEB);

// @0x141b58220
void UIWorldMapDialog::FUN_141b58220()
{
    if (!m_tiles.empty() || !m_30)
        return;
    if (TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0() == 0)
        return;
    TileVector& tiles = FUN_140cb17d0()->GetWorldTiles(FUN_141b69340());
    for (size_t i = 0; i < tiles.size(); i++)
    {
        MS2Ptr<UIWorldMap::MapTile> spTile = tiles[i];
        FUN_141b58350(spTile);
    }
}
MS2_REPLACE_METHOD(0x141B58220, UIWorldMapDialog, FUN_141b58220, 298, 0xBB14442C);

// @0x141b58350
void UIWorldMapDialog::FUN_141b58350(MS2Ptr<UIWorldMap::MapTile> spTile)
{
    if (!m_30)
        return;
    MS2Ptr<UIWorldMap::AddtionalInfo> spInfo = FUN_140cb17d0()->GetOrAddAddtionalInfo(spTile->m_34);
    if (spInfo == 0)
        return;
    ASObj obj(2);
    obj.FUN_1407cb9c0("index", spTile->m_1c);
    obj.FUN_1409c0d20("fieldSN", spTile->m_34);
    if (m_nMode == 1)
        FUN_141b5faa0(spInfo, &obj);
    else if (m_nMode == 2)
    {
        if (FUN_141b69340() == spTile->m_38)
            FUN_141b5fb80(spInfo, &obj);
    }
    else if (m_nMode == 3)
        FUN_141b60000(spInfo, &obj);
    else if (m_nMode == 4)
        FUN_141b60170(spInfo, &obj);
    if (m_1c4 == spTile->m_34)
        obj.FUN_1409c0d20("fieldSearchID", m_1c4);
    m_30->Invoke("updateAdditional", obj);
}

// @0x141b58670
void UIWorldMapDialog::FUN_141b58670(unsigned int nFieldId, int nQuestId, short nLevel, int bRelated)
{
    MS2Ptr<UIWorldMap::AddtionalInfo> spInfo = FUN_140cb17d0()->GetOrAddAddtionalInfo(nFieldId);
    if (!spInfo)
        return;
    for (size_t i = 0; i < spInfo->m_28.size(); i++)
    {
        if (spInfo->m_28[i].m_0 == nQuestId)
            return;
    }
    UIWorldMap::TooltipEntry entry;
    CStringW strName = FUN_1416e4df0(nQuestId);
    entry.m_0 = nQuestId;
    entry.m_8 = strName;
    entry.m_10 = nLevel;
    if (bRelated == 0)
        entry.m_4 = 5;
    else
        entry.m_4 = FUN_141b62a20(nQuestId, 1, 2, 3, 4);
    spInfo->m_28.push_back(entry);
}
MS2_REPLACE_METHOD(0x141B58670, UIWorldMapDialog, FUN_141b58670, 433, 0xA3097EC7);

// @0x141b58830
// MS2-FUNCTIONAL: the npc quest line (frame layout of the string temporaries)
void UIWorldMapDialog::FUN_141b58830(unsigned int nFieldId, int nNpcField, int nNpcId, int nKind, int nQuestId, short nLevel, int nState)
{
    MS2Ptr<UIWorldMap::IconInfo> spIcon = FUN_140cb17d0()->GetOrAddIconInfo(nFieldId);
    if (!spIcon)
        return;
    for (size_t i = 0; i < spIcon->m_80.size(); i++)
    {
        if (spIcon->m_80[i].m_0 == nQuestId)
            return;
    }
    UIWorldMap::TooltipEntry entry;
    CStringW strLine(L"");
    CStringW strNpc(L"");
    CStringW strState(L"");
    if (nNpcId != 0)
        strNpc = FUN_14061ad70(FUN_1401d0160(L" (", FUN_1401a9d70()->FUN_141811980(3, nNpcField)), L")");   // exe ATL::operator+ (clang would import MFC CopyChars)
    int nCheck = nState;
    if (nCheck == 0)
        strState = FUN_14028de60(0x72a);
    else if (nCheck == 1)
        strState = FUN_14028de60(0x72b);
    switch (nKind)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        strLine = FUN_1409eadb0(0x720, strState, FUN_1416e4df0(nQuestId), strNpc);
        break;
    case 5:
        strLine = FUN_1409eadb0(0x721, strState, FUN_1416e4df0(nQuestId), strNpc);
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        strLine = FUN_1409eadb0(0x722, strState, FUN_1416e4df0(nQuestId), strNpc);
        break;
    case 10:
        strLine = FUN_1409eadb0(0x723, strState, FUN_1416e4df0(nQuestId), strNpc);
        break;
    }
    entry.m_0 = nQuestId;
    entry.m_4 = nKind;
    entry.m_8 = strLine;
    entry.m_10 = nLevel;
    spIcon->m_80.push_back(entry);
}
MS2_REPLACE_METHOD(0x141B58830, UIWorldMapDialog, FUN_141b58830, 1554, 0xD7B92CE9);

// @0x141b58e80
void UIWorldMapDialog::FUN_141b58e80()
{
    COutPacket packet(0x4a);
    packet.Encode1(0);
    packet.Encode1((char)m_nMode);
    packet.Encode4(FUN_141b69340());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x141B58E80, UIWorldMapDialog, FUN_141b58e80, 119, 0x11A35320);

// @0x141b58f00
void UIWorldMapDialog::FUN_141b58f00()
{
    for (unsigned int i = 0; i < DAT_143ab3058.GetCount(); i++)
        m_1a0.insert(DAT_143ab3058[i]);
}
MS2_REPLACE_METHOD(0x141B58F00, UIWorldMapDialog, FUN_141b58f00, 120, 0x07162164);

// @0x141b58f80
// MS2-FUNCTIONAL: the npc quest lines of the fields (frame layout of the temporaries; the two local quest maps)
void UIWorldMapDialog::FUN_141b58f80()
{
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(FUN_141b69690());
    if (!spField)
        return;
    int bHideOtherWorld = 0;
    int nContinent = spField->FUN_140375350();
    {
        CContinentRegionTable::InfoPtr spContinent = FUN_1403782c0()->GetContinent(nContinent);
        if (spContinent.get() != 0)
            bHideOtherWorld = spContinent->m_nHideOtherWorldQuest;
    }
    Unk_FieldIdListMap& fields = FUN_140700390()->FUN_141b69360();
    for (POSITION pos = fields.GetStartPosition(); pos != NULL; fields.GetNext(pos))
    {
        unsigned int nNpcField = fields.GetKeyAt(pos);
        unsigned int nParent = 0;
        unsigned int nField = nNpcField;
        if (FUN_140700390()->FUN_1406fc110(nNpcField, &nParent) != 0)
            nField = nParent;
        MS2Ptr<CFieldDataCli> spTarget = CFieldDataCli::Find(nField);
        if (!spTarget)
            continue;
        CStringW strError;
        if (FUN_140a55d20(spTarget.operator->(), &strError) == 0)
            continue;
        if (bHideOtherWorld != 0 && nContinent != spTarget->FUN_140375350())
            continue;
        Unk_FieldIdListPtr spNpcs(fields.GetValueAt(pos));
        unsigned short nLevel = (unsigned short)pPlayer->vfunc_78();
        CQuestManager* pQuests = FUN_140764020();
        ATL::CAtlMap<int, MS2Ptr<CQuestData> > starts;
        ATL::CAtlMap<int, MS2Ptr<CQuestData> > completes;
        FUN_141b5cea0(starts, completes, Unk_FieldIdListPtr(spNpcs), nLevel, 1);
        for (POSITION pos2 = starts.GetStartPosition(); pos2 != NULL; starts.GetNext(pos2))
        {
            MS2Ptr<CQuestData> spQuest(starts.GetValueAt(pos2));
            int nNpc = spQuest->m_2e8;
            int nQuestId = FUN_14074b030(spQuest.operator->());
            int nQuestLevel = spQuest->m_level;
            int nType = FUN_14074b050(spQuest.operator->());
            if (FUN_14109a710()->FUN_140764e40(nNpcField, nNpc) == 0)
                continue;
            if (FUN_14074b1c0(spQuest.operator->(), 3) != 0)
                continue;
            if (pQuests->vfunc_1(nQuestId, nNpc) == 0)
                continue;
            unsigned int nRequire = spQuest->m_require.m_level;
            if ((int)(unsigned short)pPlayer->vfunc_78() < (int)nRequire)
                FUN_141b58830(nField, nNpcField, nParent, 10, nQuestId, (short)nQuestLevel, nType);
            else
                FUN_141b58830(nField, nNpcField, nParent, FUN_141b62a20<int>(nQuestId, 6, 7, 8, 9), nQuestId, (short)nQuestLevel, nType);
        }
        for (POSITION pos2 = completes.GetStartPosition(); pos2 != NULL; completes.GetNext(pos2))
        {
            MS2Ptr<CQuestData> spQuest(completes.GetValueAt(pos2));
            int nNpc = spQuest->m_2ec;
            int nQuestId = FUN_14074b030(spQuest.operator->());
            int nQuestLevel = spQuest->m_level;
            int nType = FUN_14074b050(spQuest.operator->());
            if (FUN_14109a710()->FUN_140764e40(nNpcField, nNpc) == 0)
                continue;
            if (FUN_14074b1c0(spQuest.operator->(), 3) != 0)
                continue;
            CQuestManagerCommon* pCommon = pQuests;
            if (pCommon->FUN_140746ba0(nQuestId, nNpc, 0) == 0)
                FUN_141b58830(nField, nNpcField, nParent, FUN_141b62a20<int>(nQuestId, 1, 2, 3, 4), nQuestId, (short)nQuestLevel, nType);
            else if (pCommon->FUN_140746850(nQuestId, nNpc, 0) != 0)
                FUN_141b58830(nField, nNpcField, nParent, 5, nQuestId, (short)nQuestLevel, nType);
        }
    }
}
MS2_REPLACE_METHOD(0x141B58F80, UIWorldMapDialog, FUN_141b58f80, 2221, 0xD2E85AE7);

// @0x141b59840
void UIWorldMapDialog::FUN_141b59840()
{
    void* pPlayer = TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    ATL::CAtlArray<MS2Ptr<CPartyMember> >& members = FUN_1409670d0()->FUN_14162ba30();
    size_t nCount = members.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CPartyMember> spMember = members[i];
        if (spMember->FUN_141637c20())
            continue;
        if (spMember->user.m_38 == 0)
            continue;
        if (spMember->user.m_8 != FUN_141656a80(pPlayer))
        {
            MS2Ptr<UIWorldMap::IconInfo> spIcon = FUN_140cb17d0()->GetOrAddIconInfo(spMember->user.m_28);
            CStringW strName = FUN_14052bd00(0x712, spMember->user.FUN_1408f19e0());
            CStringW strChannel = FUN_141b621d0(spMember->user.m_38);
            spIcon->m_98.push_back(std::make_pair(strName, strChannel));
        }
    }
}
MS2_REPLACE_METHOD(0x141B59840, UIWorldMapDialog, FUN_141b59840, 570, 0x0D8EA2A5);

// @0x141b59a80
void UIWorldMapDialog::FUN_141b59a80()
{
    if (TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0() == 0)
        return;
    ASArray unused(2);
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    FUN_14097a780()->FUN_140ae4df0(buddies);
    for (size_t i = 0; i < buddies.GetCount(); i++)
    {
        CBuddyManager::Ptr spBuddy = buddies[i];
        if (!spBuddy)
            continue;
        if (spBuddy->FUN_1401cc680() == 0)
            continue;
        if (FUN_1409670d0()->FUN_14162ae20(spBuddy->FUN_1401cc230()))
            continue;
        if (spBuddy->FUN_1401cc310() == 0)
            continue;
        MS2Ptr<UIWorldMap::IconInfo> spIcon = FUN_140cb17d0()->GetOrAddIconInfo(spBuddy->FUN_1401cc270());
        CStringW strChannel = FUN_141b621d0(spBuddy->FUN_1401cc310());
        CStringW strName = FUN_14052bd00(0x710, spBuddy->FUN_1401cc1c0());
        spIcon->m_b0.push_back(std::make_pair(strName, strChannel));
    }
}
MS2_REPLACE_METHOD(0x141B59A80, UIWorldMapDialog, FUN_141b59a80, 686, 0xDA37BB0B);

// @0x141b59d40
// MS2-FUNCTIONAL: the quest lines of the fields (frame layout of the temporaries)
void UIWorldMapDialog::FUN_141b59d40()
{
    ATL::CAtlArray<Unk_PayloadPtr<CQuest> > quests;
    FUN_140764020()->FUN_1416cb8b0(quests, 1, 0xb, -1);
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = quests[i];
        if (spQuest.IsNull())
            continue;
        CQuestCommon* pCommon = spQuest.operator->();
        if (m_display.FUN_141b95080(pCommon->GetData()) == 0)
            continue;
        if (pCommon->IsComplete() == 0)
        {
            for (size_t j = 0; j < pCommon->GetData()->m_fields.GetCount(); j++)
            {
                unsigned int nField = pCommon->GetData()->m_fields[j];
                MS2Ptr<CQuestData> spData = pCommon->GetData();
                FUN_141b58670(FUN_141b602a0(nField), spQuest->FUN_140bfc580(), (short)spData->m_level, 0);
            }
        }
        else
        {
            int nNpc = pCommon->GetData()->m_2ec;
            ATL::CAtlList<unsigned int> fields(10);
            FUN_140700390()->FUN_1406fb3a0(nNpc, fields);
            for (POSITION pos = fields.GetHeadPosition(); pos != NULL; fields.GetNext(pos))
            {
                unsigned int nField = fields.GetAt(pos);
                MS2Ptr<CQuestData> spData = pCommon->GetData();
                FUN_141b58670(FUN_141b602a0(nField), spQuest->FUN_140bfc580(), (short)spData->m_level, 1);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141B59D40, UIWorldMapDialog, FUN_141b59d40, 1351, 0x04ED6297);

// @0x141b5a290
void UIWorldMapDialog::FUN_141b5a290()
{
    Unk_FieldIdListMap& fields = FUN_140700390()->FUN_1406fc450();
    if (TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0() == 0)
        return;
    for (POSITION pos = fields.GetStartPosition(); pos != NULL; fields.GetNext(pos))
    {
        unsigned int nFieldId = fields.GetKeyAt(pos);
        MS2Ptr<UIWorldMap::IconInfo> spIcon = FUN_140cb17d0()->GetOrAddIconInfo(nFieldId);
        if (spIcon == 0)
            continue;
        if (spIcon->m_48.m_18 != 0)
            continue;
        Unk_FieldIdListPtr spList = fields.GetValueAt(pos);
        for (POSITION pos2 = spList.get()->GetHeadPosition(); pos2 != NULL; spList.get()->GetNext(pos2))
        {
            unsigned int nDungeonId = spList.get()->GetAt(pos2);
            ATL::CAtlArray<DungeonRoomPtr> rooms;
            FUN_14031c2a0()->GetRooms(nDungeonId, rooms);
            if (rooms.IsEmpty())
                continue;
            if (!m_display.FUN_141b95270(rooms[0]))
                continue;
            spIcon->m_48.m_18 = nDungeonId;
            spIcon->m_48.m_1c = rooms[0]->m_isUseBossIcon;
            spIcon->m_48.m_1d = rooms[0]->m_isTimeUp == 1;
        }
    }
}
MS2_REPLACE_METHOD(0x141B5A290, UIWorldMapDialog, FUN_141b5a290, 698, 0xF358CB3C);

// @0x141b5a550
// MS2-FUNCTIONAL: take the taxi (frame layout of the temporaries; the station list loop)
void UIWorldMapDialog::FUN_141b5a550(int nFieldId)
{
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0 || pPlayer->FUN_14166ce30() != 0 || pPlayer->FUN_14166c930() == 0x25 || pPlayer->FUN_14166c930() == 0x2a)
        return;
    const float& fRange = *TSingleton<Client::Constants>::GetInstance()->TaxiStationFindDistance.Get();
    if (TSingleton<WorldService>::GetInstance()->FUN_141bcfd30(0x85359406, pPlayer->FUN_1416767d0(), fRange, 1, 0) == 0)
    {
        FUN_140d73bc0(0x89, 0, 0, CStringW(L""));
        return;
    }
    if (CFieldData::FUN_140374410(nFieldId) == true)
    {
        FUN_140d73bc0(0x51, 0, 0, CStringW(L""));
        return;
    }
    if (FUN_141b69690() == nFieldId)
    {
        FUN_140d73bc0(0x8a, 0, 0, CStringW(L""));
        return;
    }
    __int64 nFare = FUN_1409f24a0()->FUN_14085f780(FUN_141b69690(), nFieldId, (short)pPlayer->vfunc_78());
    if (DAT_143ab2898 - nFare < 0)
    {
        FUN_140d73bc0(0x34, 0, 0, CStringW(L""));
        return;
    }
    FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4e42);
    if (pPlayer->FUN_1416764d0() == 0)
    {
        if (pPlayer->FUN_141527160(0x25) != 0)
        {
            NiPoint3 kRot = pPlayer->vfunc_20();
            Unk_WsC_TagPtr stations = TSingleton<WorldService>::GetInstance()->FUN_141bd0420(0x85359406);
            if (stations.FUN_1409f2170() != 0)
            {
                for (POSITION pos = stations.FUN_1409f2190()->GetHeadPosition(); pos != NULL; stations.FUN_1409f2190()->GetNext(pos))
                {
                    efd::SmartPointer<egf::Entity> spStation = stations.FUN_1409f2190()->GetAt(pos);
                    efd::Point3 kStationRot;
                    spStation->GetPropertyValue(0x68c7c29d, kStationRot);
                    kStationRot.z += 180.0f;
                    FUN_140291bc0(&kStationRot);
                    kRot = NiPoint3(kStationRot.x, kStationRot.y, kStationRot.z);
                }
            }
            pPlayer->FUN_14166d970(efd::Point3(kRot.x, kRot.y, kRot.z));
            pPlayer->vfunc_59(0x25, new StateTaxiCallData(nFieldId), 0, 0);
        }
    }
    else
    {
        MS2Ptr<RideOffActionTaxi> spAction(new RideOffActionTaxi(0));
        spAction->m_n28 = nFieldId;
        pPlayer->FUN_14152c280(spAction.operator->());
    }
}

// @0x141b5aa70
void UIWorldMapDialog::FUN_141b5aa70(int nFieldId)
{
    MS2Ptr<CFieldDataCli> spFrom = CFieldDataCli::Find(TSingleton<WorldService>::GetInstance()->FUN_141bd3060());
    MS2Ptr<CFieldDataCli> spTo = CFieldDataCli::Find(nFieldId);
    if (spFrom.operator CFieldDataCli*() != 0 && spTo.operator CFieldDataCli*() != 0 && spTo->FUN_1403754f0() != 0
        && spFrom->FUN_1403754d0() == 0 && spTo->FUN_1403754d0() != 0)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028de60(0x971), 0, CStringW(L""));
        if (spBox.operator CMsgBoxData*() != 0)
        {
            spBox->FUN_140534050(nFieldId);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIWorldMapDialog::FUN_141b5aec0));
            FUN_140d73c60(spBox);
        }
        return;
    }
    FUN_140d294c0()->FUN_140b030b0(nFieldId);
    vfunc_67();
}

// @0x141b5ad60
bool UIWorldMapDialog::FUN_141b5ad60(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        if (DAT_143ab2898 < data.FUN_141a02ed0(0, 0))
            FUN_140d73bc0(0x34, 0, 0, CStringW(L""));
        else
            FUN_141b5aa70(m_190);
    }
    return true;
}

// @0x141b5ae00
bool UIWorldMapDialog::FUN_141b5ae00(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        if (!FUN_140d86260()->vfunc_40(*TSingleton<Client::Constants>::GetInstance()->MeratAirTaxiPrice.Get()))
            FUN_140d73bc0(0x35, 0, 0, CStringW(L""));
        else
            FUN_141b5aa70(m_190);
    }
    return true;
}

// @0x141b5aec0
bool UIWorldMapDialog::FUN_141b5aec0(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        FUN_140d294c0()->FUN_140b030b0(data.FUN_141a02e90(0, 0));
        vfunc_67();
    }
    return true;
}
MS2_REPLACE_METHOD(0x141B5AEC0, UIWorldMapDialog, FUN_141b5aec0, 91, 0xBCE3A810);

// @0x141b5af30
bool UIWorldMapDialog::FUN_141b5af30(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
        FUN_140764020()->FUN_1416d0c90(m_1c4);
    return true;
}
MS2_REPLACE_METHOD(0x141B5AF30, UIWorldMapDialog, FUN_141b5af30, 60, 0x34E1CF2E);

// @0x141b5af80
void UIWorldMapDialog::FUN_141b5af80(int n)
{
    m_194 = n;
    vfunc_47(m_194 == 0);
}
MS2_REPLACE_METHOD(0x141B5AF80, UIWorldMapDialog, FUN_141b5af80, 88, 0x5F89A9A8);

// @0x141b5afe0
int UIWorldMapDialog::FUN_141b5afe0(int nFieldId)
{
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0 || pPlayer->FUN_14166ce30() != 0)
        return 1;
    if (pPlayer->vfunc_65() != 0)
    {
        FUN_140d73bc0(0xa2, 0, 0, CStringW(L""));
        return 1;
    }
    if (CFieldData::FUN_140374410(nFieldId) == true)
    {
        FUN_140d73bc0(0x51, 0, 0, CStringW(L""));
        return 1;
    }
    if (TSingleton<WorldService>::GetInstance()->FUN_141bd3060() == nFieldId)
    {
        FUN_140d73bc0(0xa3, 0, 0, CStringW(L""));
        return 1;
    }
    FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)0x4e42);
    COutPacket packet(0x54);
    packet.Encode4(nFieldId);
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE_METHOD(0x141B5AFE0, UIWorldMapDialog, FUN_141b5afe0, 424, 0xAA38612C);

// @0x141b5b190
void UIWorldMapDialog::FUN_141b5b190()
{
    if (m_30 && !m_tiles.empty())
    {
        for (size_t i = 0; !m_tiles.empty() && i < 5; i++)
        {
            MS2Ptr<UIWorldMap::MapTile> spTile = m_tiles.front();
            m_tiles.pop_front();
            FUN_141b5b790(spTile);
            FUN_141b58350(spTile);
        }
        if (m_tiles.empty())
        {
            m_30->Invoke("setVisibleRadioGroup", 1);
            m_30->Invoke("onTileComplete");
        }
    }
}
MS2_REPLACE_METHOD(0x141B5B190, UIWorldMapDialog, FUN_141b5b190, 481, 0x92997848);

// @0x141b5b380
// MS2-FUNCTIONAL: the tile tooltip (frame layout of the string temporaries)
CStringW UIWorldMapDialog::FUN_141b5b380(MS2Ptr<UIWorldMap::MapTile> spTile)
{
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return L"";
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(spTile->m_34);
    if (!spField)
        return L"";
    unsigned short nLevel = (unsigned short)pPlayer->vfunc_78();
    CStringW strLevel = FUN_1409e97f0(0x713, spField->m_nMapLevel);
    CStringW strText;
    int nLimit = nLevel + 5;
    if (nLimit < (int)(unsigned short)spField->m_nMapLevel)
        strText = FUN_140632a60(0x717, FUN_1401a9d70()->FUN_141811980(3, spTile->m_34), strLevel);
    else
        strText = FUN_140632a60(0x716, FUN_1401a9d70()->FUN_141811980(3, spTile->m_34), strLevel);
    CStringW strFishing = FUN_140953f20()->FUN_140cdc000(spTile->m_34);
    if (strFishing.GetLength() > 0)
    {
        strText += L"\n";
        strText += strFishing;
    }
    CStringW strHint = FUN_14028b8e0(CStringW(L"s_worldmap_tooltip_dbclick"));
    if (strHint.GetLength() > 0)
    {
        strText += L"\n";
        strText += strHint;
    }
    return strText;
}

// @0x141b5b790
void UIWorldMapDialog::FUN_141b5b790(MS2Ptr<UIWorldMap::MapTile> spTile)
{
    if (!m_30)
        return;
    if (!spTile)
        return;
    if (spTile->FUN_141b94b90() == 0)
        return;
    if (FUN_1422bb8b0(m_28) == 0)
        return;
    if (TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0() == 0)
        return;
    MS2Ptr<UIWorldMap::IconInfo> spIcon = FUN_140cb17d0()->GetOrAddIconInfo(spTile->m_34);
    if (!spIcon)
        return;
    ASObj obj(2);
    FUN_141b5d4b0(spTile, &obj);
    FUN_141b5e160(spIcon, &obj);
    FUN_141b5e330(spIcon, &obj);
    FUN_141b5e580(spIcon, &obj);
    FUN_141b5e9e0(spIcon, &obj);
    FUN_141b5ec30(spIcon, &obj);
    FUN_141b5ee80(spTile, &obj);
    FUN_141b5f540(spTile, &obj);
    FUN_141b5f740(spTile, &obj);
    FUN_140cb17d0()->SetEventScript(spTile->m_34, &obj);
    FUN_140cb17d0()->SetDungeonScript(spIcon, &obj, m_28);
    m_30->Invoke("createMap", obj);
}

// @0x141b5bc70
void UIWorldMapDialog::FUN_141b5bc70(int nFieldId)
{
    m_1c8 = nFieldId;
    if (vfunc_55() == 0)
        FUN_141b57660();
}
MS2_REPLACE_METHOD(0x141B5BC70, UIWorldMapDialog, FUN_141b5bc70, 66, 0x9824B008);

// @0x141b5bcc0
void UIWorldMapDialog::FUN_141b5bcc0(CStringW strText)
{
    m_strSearch = strText;
    if (vfunc_55() == 0)
        FUN_141b57740();
}
MS2_REPLACE_METHOD(0x141B5BCC0, UIWorldMapDialog, FUN_141b5bcc0, 98, 0x76119B01);

// @0x141b5bd30
void UIWorldMapDialog::FUN_141b5bd30()
{
    m_display.m_18[0] = ((unsigned char*)TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n20)[0];
    m_display.m_18[1] = ((unsigned char*)TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n20)[1];
    m_display.m_18[2] = ((unsigned char*)TSingleton<CGameOption>::GetInstance()->FUN_140c9b8b0()->m_n20)[2];
    FUN_140cb17d0()->ClearIconInfoTooltips();
    FUN_140cb17d0()->ClearDungeonInfos();
    FUN_140cb17d0()->ClearAddtionalInfoTooltips();
    FUN_141b58f80();
    FUN_141b5a290();
    FUN_141b59d40();
    FUN_141b57870();
}
MS2_REPLACE_METHOD(0x141B5BD30, UIWorldMapDialog, FUN_141b5bd30, 207, 0x5244D3B3);

// @0x141b5be10
// MS2-FUNCTIONAL: the field mission panel (frame layout of the temporaries)
void UIWorldMapDialog::FUN_141b5be10()
{
    ATL::CAtlArray<MS2Ptr<CQuestData> > quests;
    FUN_1407476c0()->FUN_14074cad0(quests, 4);
    int nTotal = (int)quests.GetCount();
    if (nTotal == 0)
        return;
    int nRound = FUN_140764020()->FUN_1416d00c0();
    int nEnable = FUN_140764020()->FUN_1416d0100();
    int nDone = FUN_140764020()->FUN_1416d0150();
    if (FUN_140764020()->FUN_1416d0210() != 0)
    {
        nRound = FUN_140d738f0()->GetMaxRound();
        nEnable = 0;
    }
    ASObj obj(2);
    obj.FUN_1407cb9c0("rewardCount", nRound);
    int nRate = (nDone * 100) / nTotal;
    obj.FUN_1407cbb20("rate", FUN_14052bd00(0x98e, StringFormat(L"{0}", nRate)));
    obj.FUN_1407cbb20("count", StringFormat(L"{0}/{1}", nDone, nTotal));
    obj.FUN_1407cbb20("desc", FUN_14062b4f0(CStringW(L"s_fieldmission_desc"), nRound));
    obj.FUN_1407cbbe0("prev", FUN_14037c450(FUN_140d738f0(), nRound) != 0);
    obj.FUN_1407cbbe0("next", FUN_14037c510(FUN_140d738f0(), nRound) != 0);
    obj.FUN_1407cb9c0("enable", nEnable);
    FUN_141b5c2b0(nRound, &obj);
    MS2Ptr<ASUIComponent> spPanel = FUN_140c02990("m_fieldMission");
    if (spPanel.operator ASUIComponent*() != 0)
        spPanel->Invoke("setData", obj);
    if (m_210 != 0)
        m_30->Invoke("setFieldMissionMode", 1);
}
MS2_REPLACE_METHOD(0x141B5BE10, UIWorldMapDialog, FUN_141b5be10, 1041, 0xE8AF9593);

// @0x141b5c230
void UIWorldMapDialog::FUN_141b5c230()
{
    m_210 = 1;
    if (!m_30)
        FUN_141924680();
    else
        m_30->Invoke("setFieldMissionMode", 1);
}
MS2_REPLACE_METHOD(0x141B5C230, UIWorldMapDialog, FUN_141b5c230, 118, 0x1D79830E);

// @0x141b5c2b0
// MS2-FUNCTIONAL: the reward slot of a field mission round (frame layout of the CreateParam temporaries)
void UIWorldMapDialog::FUN_141b5c2b0(int nRound, ASObj* pObj)
{
    MS2Ptr<CFieldMissionReward> spReward = FUN_140d738f0()->GetReward(nRound);
    if (spReward.operator->() == 0)
        return;
    if (spReward->m_nType == 1)
    {
        MS2Ptr<CItem> spItem(new CItem);
        ItemAble* pAble = &spReward->m_item;
        int nRarity = pAble->vfunc_o18_1();
        if (spItem->FUN_140523c40(spReward->m_item.m_itemId, nRarity, 0))
        {
            spItem->FUN_140526c70(spReward->m_item.m_count);
            FUN_141415600(vfunc_1());
            FUN_141415450(vfunc_1(), MS2Ptr<CItem>(spItem), 0, 0, 0);
            pObj->FUN_1407cba60("binding", vfunc_1());
            pObj->FUN_1407cbb20("reward", FUN_14028b8e0(CStringW(L"s_fieldmission_reward")));
        }
    }
    else if (spReward->m_nType == 3)
    {
        ItemInfoSlot::CreateParam param;
        param.m_strSlotText = FUN_1401d31f0()->FUN_140cca050(spReward->m_nSubJob);
        param.m_strTip = FUN_14062b4f0(CStringW(L"s_fieldmission_skill_reward"), spReward->m_nValue);
        param.m_nFlags = 1;
        param.m_nTipArg = 4;
        param.m_strCount = FUN_1402bad60("{0}", &spReward->m_nValue);
        FUN_141415600(vfunc_1());
        FUN_141415560(vfunc_1(), &param);
        pObj->FUN_1407cba60("binding", vfunc_1());
        pObj->FUN_1407cbb20("reward", FUN_14028b8e0(CStringW(L"s_fieldmission_point_reward")));
    }
    else if (spReward->m_nType == 2)
    {
        ItemInfoSlot::CreateParam param;
        param.m_strSlotText = FUN_1401d31f0()->m_1d0;
        param.m_strTip = FUN_14062b4f0(CStringW(L"s_fieldmission_stat_reward"), spReward->m_nValue);
        param.m_nFlags = 1;
        param.m_nTipArg = 4;
        param.m_strCount = FUN_1402bad60("{0}", &spReward->m_nValue);
        FUN_141415600(vfunc_1());
        FUN_141415560(vfunc_1(), &param);
        pObj->FUN_1407cba60("binding", vfunc_1());
        pObj->FUN_1407cbb20("reward", FUN_14028b8e0(CStringW(L"s_fieldmission_point_reward")));
    }
}

// @0x141b5cea0
// MS2-FUNCTIONAL: the quests the npcs of a field start / complete (temporaries of the quest pointer copies)
void UIWorldMapDialog::FUN_141b5cea0(ATL::CAtlMap<int, MS2Ptr<CQuestData> >& starts, ATL::CAtlMap<int, MS2Ptr<CQuestData> >& completes,
    Unk_FieldIdListPtr spNpcs, unsigned short nLevel, unsigned short nRange)
{
    for (POSITION pos = spNpcs.get()->GetHeadPosition(); pos != NULL; spNpcs.get()->GetNext(pos))
    {
        int nNpc = spNpcs.get()->GetAt(pos);
        std::vector<unsigned>* pQuestIds = FUN_1407476c0()->FUN_14074e0f0(nNpc);
        if (pQuestIds == 0)
            continue;
        for (std::vector<unsigned>::iterator it = pQuestIds->begin(); it != pQuestIds->end(); ++it)
        {
            int nQuestId = *it;
            MS2Ptr<CQuestData> spQuest = FUN_1407476c0()->FUN_14074c9d0(nQuestId);
            if (!spQuest)
                continue;
            if (FUN_1416e8060(spQuest->m_28) != 0)
                continue;
            if (m_display.FUN_141b95080(MS2Ptr<CQuestData>(spQuest)) == 0)
                continue;
            if ((unsigned)nLevel + (unsigned)nRange < (unsigned)(unsigned short)spQuest->m_require.m_level)
                continue;
            if (spQuest->m_2e8 == nNpc)
                starts.SetAt(FUN_14074b030(spQuest.operator->()), spQuest);
            if (spQuest->m_2ec == nNpc)
                completes.SetAt(FUN_14074b030(spQuest.operator->()), spQuest);
        }
    }
}

// @0x141b5cbc0
void UIWorldMapDialog::FUN_141b5cbc0()
{
    if (FUN_140764020()->FUN_1416d0100() != 0)
    {
        COutPacket packet(0x29);
        packet.Encode1(0x1a);
        packet.Encode4(FUN_140764020()->FUN_1416d00c0());
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x141B5CBC0, UIWorldMapDialog, FUN_141b5cbc0, 117, 0xBD951E1F);

// @0x141b5cc40
// MS2-FUNCTIONAL: the field mission panel of a round (frame layout of the temporaries)
void UIWorldMapDialog::FUN_141b5cc40(int nRound)
{
    int nEnable = 0;
    if (FUN_140764020()->FUN_1416d00c0() == nRound)
        nEnable = FUN_140764020()->FUN_1416d0100();
    ASObj obj(2);
    obj.FUN_1407cb9c0("rewardCount", nRound);
    obj.FUN_1407cb9c0("enable", nEnable);
    obj.FUN_1407cbb20("desc", FUN_14062b4f0(CStringW(L"s_fieldmission_desc"), nRound));
    obj.FUN_1407cbbe0("prev", FUN_14037c450(FUN_140d738f0(), nRound) != 0);
    obj.FUN_1407cbbe0("next", FUN_14037c510(FUN_140d738f0(), nRound) != 0);
    FUN_141b5c2b0(nRound, &obj);
    MS2Ptr<ASUIComponent> spPanel = FUN_140c02990("m_fieldMission");
    if (spPanel.operator ASUIComponent*() != 0)
        spPanel->Invoke("setData", obj);
}
MS2_REPLACE_METHOD(0x141B5CC40, UIWorldMapDialog, FUN_141b5cc40, 602, 0xF031AAB0);

// @0x141b5d120
MS2Ptr<UIWorldMap::MapTile> UIWorldMapDialog::FUN_141b5d120()
{
    MS2Ptr<UIWorldMap::MapTile> spTile = FUN_140cb17d0()->FindMapTileByKey(FUN_141b69690());
    if (m_1c0 != 0)
    {
        MS2Ptr<UIWorldMap::MapTile> spSearch = FUN_140cb17d0()->FindMapTileByKey(m_1c4);
        if (!spSearch)
            return spTile;
        if (spSearch->m_38 == FUN_141b69340())
            return spSearch;
    }
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(FUN_141b69690());
    if (spField.operator CFieldDataCli*() != 0)
    {
        if (FUN_140cb17d0()->WorldOfField(spField->FUN_140375350()) != FUN_141b69340() || spTile == 0)
            spTile = FUN_140cb17d0()->FindMapTile(FUN_141b69340());
    }
    return spTile;
}
MS2_REPLACE_METHOD(0x141B5D120, UIWorldMapDialog, FUN_141b5d120, 609, 0x66E09A6F);

// @0x141b5d390
void UIWorldMapDialog::FUN_141b5d390()
{
    if (!m_tiles.empty())
        return;
    switch (m_nMode)
    {
    case 0:
        break;
    case 1:
    {
        COutPacket packet(0x4a);
        packet.Encode1(1);
        packet.Encode4(FUN_141b69340());
        FUN_140710590(packet);
        return;
    }
    case 2:
        FUN_140cb17d0()->ClearAddtionalInfos();
        FUN_141b59d40();
        FUN_141b58220();
        return;
    case 3:
    case 4:
        break;
    default:
        return;
    }
    FUN_141b58220();
}
MS2_REPLACE_METHOD(0x141B5D390, UIWorldMapDialog, FUN_141b5d390, 260, 0x20B4035F);

// @0x141b5d4b0
// MS2-FUNCTIONAL: the tile part of "createMap" (frame layout of the string temporaries)
void UIWorldMapDialog::FUN_141b5d4b0(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj)
{
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(spTile->m_34);
    if (!spField)
        return;
    int nHomeField = 0;
    pPlayer->FUN_141527f80(&nHomeField);
    if (spTile->m_54 == 0)
    {
        pObj->FUN_1409c0e60("shadowgate", L"");
    }
    else
    {
        CStringW strShadow = FUN_14028de60(0x72c);
        if (spTile->m_58 != 0)
        {
            strShadow += L"\n";
            strShadow += FUN_1405c2690(CStringW(L"s_worldmap_tooltip_shadowgate_field"), FUN_1401a9d70()->FUN_141811980(3, spTile->m_58));
            FUN_1403b4750()->FUN_1416fb340(strShadow);
        }
        pObj->FUN_1407cbb20("shadowgate", strShadow);
    }
    if (FUN_141b69690() == spTile->m_34 && FUN_141b69340() == spTile->m_38)
    {
        CStringW strMe = FUN_14052bd00(0x70e, pPlayer->vfunc_77());
        pObj->FUN_1407cbb20("mypc", strMe);
    }
    else
    {
        pObj->FUN_1409c0e60("mypc", L"");
    }
    CStringW strHouse = FUN_14052bd00(0x70f, pPlayer->FUN_1415281c0());
    CStringW strMyHouse = FUN_141b602a0(nHomeField) != spTile->m_34 ? CStringW(L"") : CStringW(strHouse);
    pObj->FUN_1407cbb20("myhouse", strMyHouse);
    bool bTown = spTile->m_20;
    pObj->FUN_1407cb9c0("index", spTile->m_1c);
    pObj->FUN_1407cbbe0("town", bTown);
    pObj->FUN_1407cbbe0("publicField", spTile->m_21);
    pObj->FUN_1407cbb20("fieldName", FUN_1401a9d70()->FUN_141811980(3, spTile->m_34));
    pObj->FUN_1407cb9c0("pvpField", spField->FUN_1403754d0());
    bool bShowName = !bTown;
    int nNameMovie = FUN_140764020()->FUN_1416d0800(spTile->m_34);
    if (nNameMovie == 0)
    {
        if (!spTile->m_60.IsEmpty())
        {
            pObj->FUN_1407cba60("nameMovie", spTile->m_60);
            pObj->FUN_1407cb9c0("nameAlign", spTile->m_5c);
            pObj->FUN_1407cb9c0("nameAlignOffsetX", spTile->m_68);
            pObj->FUN_1407cb9c0("nameAlignOffsetY", spTile->m_6c);
            bShowName = false;
        }
    }
    else
    {
        pObj->FUN_1407cba60("nameMovie", FUN_14021a6b0(nNameMovie));
        pObj->FUN_1407cb9c0("nameAlign", 0);
        bShowName = false;
    }
    pObj->FUN_1407cbbe0("showFieldName", bShowName);
    pObj->FUN_1407cbb20("fieldTooltip", FUN_141b5b380(spTile));
    pObj->FUN_1409c0d20("fieldSN", spTile->m_34);
    pObj->FUN_1407cb9c0("continent", spTile->m_38);
    pObj->FUN_1407cb9c0("gridX", spTile->m_24);
    pObj->FUN_1407cb9c0("gridY", spTile->m_28);
    pObj->FUN_1407cb9c0("gridZ", spTile->m_2c);
    pObj->FUN_1407cb9c0("size", spTile->m_30);
    pObj->FUN_141b62da0("tileType", spTile->m_18);
    pObj->FUN_1407cba60("normalImage", spTile->m_40);
    pObj->FUN_1407cba60("sealedImage", spTile->m_48);
    static int s_nShadowContinent = *TSingleton<Client::Constants>::GetInstance()->WorldMapShadowUsingContinent.Get();
    pObj->FUN_1407cbbe0("usingShadow", spTile->m_38 == s_nShadowContinent);
    if (m_214 == 0)
    {
        if (m_1a0.find(spTile->m_34) != m_1a0.end())
            pObj->FUN_1407cbbe0("sealed", false);
        else
            pObj->FUN_1407cbbe0("sealed", true);
    }
    else
    {
        if (FUN_140764020()->FUN_1416d0e60(spTile->m_34) == 0)
            pObj->FUN_1407cbbe0("sealed", true);
        else
            pObj->FUN_1407cbbe0("sealed", false);
    }
    if (spTile->m_18 == 1)
        pObj->FUN_1407cb9c0("tracing", m_218);
    if (DAT_143ae0fb8 != 0)
        pObj->FUN_1407cbbe0("sealed", false);
}

// @0x141b5e160
void UIWorldMapDialog::FUN_141b5e160(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj)
{
    if (spIcon == 0)
        return;
    if (spIcon->m_20.m_0 == 0)
        return;
    MS2Ptr<CNpcData> spNpc = FUN_1406cd330(spIcon->m_20.m_0);
    if (!!spNpc)
    {
        CStringW strFrame(L"boss");
        if (!spNpc->HasPropertyTag(0xd))
        {
            if (spNpc->m_nClass < 4 || spNpc->m_nClass == 7)
                strFrame = L"elite";
            else
                strFrame = L"boss";
        }
        else
        {
            strFrame = L"event";
        }
        pObj->FUN_1409c0d20("npcID", spIcon->m_20.m_0);
        pObj->FUN_1407cbb20("bossFrameName", strFrame);
        pObj->FUN_1407cbbe0("bossIcon", true);
    }
}

// @0x141b5e330
void UIWorldMapDialog::FUN_141b5e330(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj)
{
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    Scaleform::GFx::Value names;
    FUN_14256e3e0(pMovie, &names);
    Scaleform::GFx::Value times;
    FUN_14256e3e0(pMovie, &times);
    for (size_t i = 0; i < spIcon->m_68.size(); i++)
    {
        Scaleform::GFx::Value v;
        names.PushBack(*FUN_1412dd680(&v, spIcon->m_68[i].first));
        Scaleform::GFx::Value v2;
        times.PushBack(*FUN_1412dd680(&v2, spIcon->m_68[i].second));
    }
    pObj->FUN_1409adbe0("portal", Scaleform::GFx::Value(names));
    pObj->FUN_1409adbe0("portaltimes", Scaleform::GFx::Value(times));
}

// @0x141b5e580
void UIWorldMapDialog::FUN_141b5e580(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj)
{
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    if (spIcon->m_80.size() > 1)
        std::sort(spIcon->m_80.begin(), spIcon->m_80.end(), UIWorldMap::FUN_141b94e70);
    Scaleform::GFx::Value quests;
    FUN_14256e3e0(pMovie, &quests);
    Scaleform::GFx::Value types;
    FUN_14256e3e0(pMovie, &types);
    Scaleform::GFx::Value levels;
    FUN_14256e3e0(pMovie, &levels);
    for (size_t i = 0; i < spIcon->m_80.size(); i++)
    {
        ASData data;
        data.FUN_1422b7f70(spIcon->m_80[i].m_4);
        types.PushBack(data.FUN_1422b9260());
        Scaleform::GFx::Value v;
        quests.PushBack(*FUN_1412dd680(&v, spIcon->m_80[i].m_8));
        CStringW strLevel = FUN_141b622d0(spIcon->m_80[i].m_10, spIcon->m_80[i].m_4);
        Scaleform::GFx::Value v2;
        levels.PushBack(*FUN_1412dd680(&v2, strLevel));
    }
    pObj->FUN_1409adbe0("quest", Scaleform::GFx::Value(quests));
    pObj->FUN_1409adbe0("questType", Scaleform::GFx::Value(types));
    pObj->FUN_1409adbe0("questLevel", Scaleform::GFx::Value(levels));
}

// @0x141b5e9e0
void UIWorldMapDialog::FUN_141b5e9e0(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj)
{
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    Scaleform::GFx::Value names;
    FUN_14256e3e0(pMovie, &names);
    Scaleform::GFx::Value channels;
    FUN_14256e3e0(pMovie, &channels);
    for (size_t i = 0; i < spIcon->m_98.size(); i++)
    {
        Scaleform::GFx::Value v;
        names.PushBack(*FUN_1412dd680(&v, spIcon->m_98[i].first));
        Scaleform::GFx::Value v2;
        channels.PushBack(*FUN_1412dd680(&v2, spIcon->m_98[i].second));
    }
    pObj->FUN_1409adbe0("party", Scaleform::GFx::Value(names));
    pObj->FUN_1409adbe0("partyChannel", Scaleform::GFx::Value(channels));
}

// @0x141b5ec30
void UIWorldMapDialog::FUN_141b5ec30(MS2Ptr<UIWorldMap::IconInfo> spIcon, ASObj* pObj)
{
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    Scaleform::GFx::Value names;
    FUN_14256e3e0(pMovie, &names);
    Scaleform::GFx::Value channels;
    FUN_14256e3e0(pMovie, &channels);
    for (size_t i = 0; i < spIcon->m_b0.size(); i++)
    {
        Scaleform::GFx::Value v;
        names.PushBack(*FUN_1412dd680(&v, spIcon->m_b0[i].first));
        Scaleform::GFx::Value v2;
        channels.PushBack(*FUN_1412dd680(&v2, spIcon->m_b0[i].second));
    }
    pObj->FUN_1409adbe0("buddy", Scaleform::GFx::Value(names));
    pObj->FUN_1409adbe0("buddyChannel", Scaleform::GFx::Value(channels));
}

// @0x141b5ee80
// MS2-FUNCTIONAL: the taxi part of "createMap" (frame layout of the string temporaries)
void UIWorldMapDialog::FUN_141b5ee80(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj)
{
    if (FUN_1422bb8b0(m_28) == 0)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    int bGoodTaxi = FUN_141b71c00((unsigned short)pPlayer->vfunc_78());
    if (FUN_1409f24a0()->FUN_14085f6e0(spTile->m_34) && !FUN_1409f24a0()->FUN_14085f730(spTile->m_34))
    {
        CStringW strState(L"disabled");
        __int64 nFare = 0;
        bool bHere = false;
        if (FUN_140408410(DAT_143ab3078, spTile->m_34) >= 0)
        {
            bHere = spTile->m_34 == FUN_141b69690();
            if (m_194 == 0)
                strState = L"enabled";
            else
                strState = bHere ? L"default" : L"active";
            nFare = FUN_1409f24a0()->FUN_14085f780(FUN_141b69690(), spTile->m_34, (short)pPlayer->vfunc_78());
        }
        CStringW strCost(L"");
        CStringW strDesc(L"");
        if (nFare < 1)
        {
            if (bHere)
                strDesc = FUN_14028de60(0x727);
            else if (!FUN_1403b3c40(strState, L"disabled"))
                strDesc = FUN_14028de60(0x728);
            else
                strDesc = FUN_14028de60(0x726);
        }
        else
        {
            strCost = FUN_14052bd00(0x725, FUN_1409404f0(nFare));
        }
        if (bGoodTaxi == 0)
            pObj->FUN_1407cbb20("taxi", strState);
        else
            pObj->FUN_1407cbb20("goodtaxi", strState);
        pObj->FUN_1407cbb20("taxicost", strCost);
        pObj->FUN_1407cbb20("taxidesc", strDesc);
        CStringW strTitle = FUN_14052bd00(0x724, FUN_1401a9d70()->FUN_141811980(3, spTile->m_34));
        pObj->FUN_1407cbb20("taxiTitle", strTitle);
        return;
    }
    pObj->FUN_1409c0dc0("taxi", "");
    pObj->FUN_1409c0dc0("goodtaxi", "");
    pObj->FUN_1409c0dc0("taxicost", "");
}

// @0x141b5f540
void UIWorldMapDialog::FUN_141b5f540(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj)
{
    size_t i;
    for (i = 0; i < m_npcIds.GetCount(); i++)
    {
        if (FUN_140700390()->FUN_1406fba40(m_npcIds[i], spTile->m_34) != 0)
            break;
    }
    if (i >= m_npcIds.GetCount())
        return;
    if (i < m_npcFrames.GetCount())
        pObj->FUN_1407cba60("specialFunctionNpc", CString(m_npcFrames[i]));
    if (i < m_npcTooltips.GetCount())
        pObj->FUN_1407cbb20("specialFunctionNpcTooltip", FUN_14028b8e0(FUN_14016a730(m_npcTooltips[i], 0)));
}

// @0x141b5f740
// MS2-FUNCTIONAL: the field mission part of "createMap" (frame layout of the temporaries)
void UIWorldMapDialog::FUN_141b5f740(MS2Ptr<UIWorldMap::MapTile> spTile, ASObj* pObj)
{
    if (spTile == 0)
        return;
    ATL::CAtlArray<unsigned int> quests;
    FUN_1407476c0()->FUN_14074cbf0(spTile->m_34, quests);
    if (quests.GetCount() == 0)
        return;
    CStringW strTooltip;
    int nClear = 0;
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = static_cast<CQuestManagerCommon*>(FUN_140764020())->vfunc_o10_3(quests[i]);
        if (spQuest.get() != 0)
        {
            if (spQuest->FUN_1407476d0() == 2 || static_cast<CQuestCommon*>(spQuest.operator->())->IsComplete() != 0)
                nClear++;
        }
        if (strTooltip.GetLength() != 0)
            strTooltip += L"\n";
        ATL::CAtlArray<CStringW> lines;
        FUN_1416e5890(quests[i], lines);
        for (size_t j = 0; j < lines.GetCount(); j++)
            strTooltip += lines[j];
    }
    ASObj mission(2);
    mission.FUN_140e846b0("total", quests.GetCount());
    mission.FUN_1407cb9c0("clear", nClear);
    mission.FUN_1407cbb20("tooltip", strTooltip);
    pObj->FUN_1407cb9c0("missionMode", m_210);
    pObj->FUN_1409eb270("fieldMission", mission);
}

// @0x141b5faa0
void UIWorldMapDialog::FUN_141b5faa0(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj)
{
    if (spInfo == 0)
        return;
    pObj->FUN_1407cbb20("ranking", StringFormat(L"{0}", (unsigned int)spInfo->m_1c.m_0));
    pObj->FUN_1407cbb20("rankingChannel", FUN_141b621d0(spInfo->m_1c.m_4));
}

// @0x141b5fb80
void UIWorldMapDialog::FUN_141b5fb80(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj)
{
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    if (spInfo == 0)
        return;
    if (spInfo->m_28.size() > 1)
        std::sort(spInfo->m_28.begin(), spInfo->m_28.end(), UIWorldMap::FUN_141b94e70);
    Scaleform::GFx::Value quests;
    FUN_14256e3e0(pMovie, &quests);
    Scaleform::GFx::Value types;
    FUN_14256e3e0(pMovie, &types);
    Scaleform::GFx::Value levels;
    FUN_14256e3e0(pMovie, &levels);
    for (size_t i = 0; i < spInfo->m_28.size(); i++)
    {
        ASData data;
        data.FUN_1422b7f70(spInfo->m_28[i].m_4);
        types.PushBack(data.FUN_1422b9260());
        Scaleform::GFx::Value v;
        quests.PushBack(*FUN_1412dd680(&v, spInfo->m_28[i].m_8));
        CStringW strLevel = FUN_141b622d0(spInfo->m_28[i].m_10, spInfo->m_28[i].m_4);
        Scaleform::GFx::Value v2;
        levels.PushBack(*FUN_1412dd680(&v2, strLevel));
    }
    pObj->FUN_1409adbe0("quest", Scaleform::GFx::Value(quests));
    pObj->FUN_1409adbe0("questType", Scaleform::GFx::Value(types));
    pObj->FUN_1409adbe0("questLevel", Scaleform::GFx::Value(levels));
}

// @0x141b60000
void UIWorldMapDialog::FUN_141b60000(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj)
{
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(spInfo->m_18);
    if (!spField)
        return;
    if (spField->m_nMapType != 4 && spField->m_nMapType != 0xb)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    int nDiff = (int)spField->m_nMapLevel - (unsigned short)pPlayer->vfunc_78();
    if (abs(nDiff) < 4)
        pObj->FUN_1407cb9c0("recommendMap", 1);
}

// @0x141b60170
void UIWorldMapDialog::FUN_141b60170(MS2Ptr<UIWorldMap::AddtionalInfo> spInfo, ASObj* pObj)
{
    MS2Ptr<CFishingSpotData> spSpot = FUN_1403b4740()->GetSpot(spInfo->m_18);
    if (!spSpot)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(TSingleton<WorldService>::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    unsigned int nMastery = FUN_141662750(pPlayer, 1);
    if (spSpot->m_nMinMastery <= nMastery && nMastery <= spSpot->m_nMaxMastery)
        pObj->FUN_1407cb9c0("recommendMap", 1);
}

// @0x141b602a0
int UIWorldMapDialog::FUN_141b602a0(int nFieldId)
{
    unsigned int nParent = 0;
    int nResult = nFieldId;
    if (FUN_140700390()->FUN_1406fc110(nFieldId, &nParent) != 0)
        nResult = nParent;
    return nResult;
}
MS2_REPLACE_METHOD(0x141B602A0, UIWorldMapDialog, FUN_141b602a0, 74, 0xC44179A1);

// @0x141b602f0
void UIWorldMapDialog::FUN_141b602f0()
{
    if (!m_30 || m_1c0 == 0)
        return;
    MS2Ptr<UIWorldMap::MapTile> spTile = FUN_140cb17d0()->FindMapTileByKey(m_1c4);
    if (!spTile)
        return;
    m_1c0 = 0;
    m_1c4 = 0;
    FUN_141b58350(spTile);
    m_30->Invoke("setInitalPos", spTile->m_24, spTile->m_28, spTile->m_2c, spTile->m_30);
}
MS2_REPLACE_METHOD(0x141B602F0, UIWorldMapDialog, FUN_141b602f0, 408, 0x9979B2B8);

// @0x141b60490
void UIWorldMapDialog::FUN_141b60490(CStringW strText)
{
    if (strText.IsEmpty())
        return;
    Unk_BlockList request(0x4e42);
    request.Add("m_fieldSearch", CStringW(strText), false);
    if (FUN_140d86260()->vfunc_37(&request) == 1)
        FUN_141b60d40(CStringW(strText));
}
MS2_REPLACE_METHOD(0x141B60490, UIWorldMapDialog, FUN_141b60490, 320, 0x01A1E232);

// @0x141b605e0
void UIWorldMapDialog::FUN_141b605e0(CStringW strName)
{
    if (!m_30)
        return;
    if (strName.IsEmpty())
        return;
    MS2Ptr<UIWorldMap::FieldSearchInfo> spInfo = FUN_140cb17d0()->FindFieldSearchInfo(CStringW(strName));
    if (!spInfo)
    {
        FUN_140d73bc0(0xa6, 0, static_cast<IMessageListener*>(this), CStringW(L"onTopMostLayer"));
        return;
    }
    MS2Ptr<UIWorldMap::MapTile> spTile = FUN_140cb17d0()->FindMapTileByKey(spInfo->m_28);
    if (!spTile)
    {
        FUN_140d73bc0(0xa7, 0, static_cast<IMessageListener*>(this), CStringW(L"onTopMostLayer"));
        return;
    }
    FUN_141b602f0();
    m_1c4 = spInfo->m_28;
    m_1c0 = 1;
    if (spTile->m_18 == 0)
    {
        if (spTile->m_38 == FUN_141b69340())
        {
            FUN_141b58350(spTile);
            m_30->Invoke("setInitalPos", spTile->m_24, spTile->m_28, spTile->m_2c, spTile->m_30);
        }
        else
        {
            m_nWorld = spTile->m_38;
            FUN_141b58200();
        }
    }
    else
    {
        MS2Ptr<ASMovieClip> spMode = FUN_140ba7930("m_skyFortressMode");
        if (spMode.operator ASMovieClip*() != 0)
        {
            MS2Ptr<ASButton> spToggle = spMode->FUN_140acce30<ASButton>("m_toggle");
            if (spToggle.operator ASButton*() != 0)
            {
                spToggle->FUN_1422ce090(1);
                m_218 = 1;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141B605E0, UIWorldMapDialog, FUN_141b605e0, 1365, 0xE4221154);

// @0x141b60b40
bool UIWorldMapDialog::FUN_141b60b40(int nFrom, int nTo)
{
    MS2Ptr<CFieldDataCli> spFrom = CFieldDataCli::Find(nFrom);
    MS2Ptr<CFieldDataCli> spTo = CFieldDataCli::Find(nTo);
    if (spFrom.operator CFieldDataCli*() != 0 && spTo.operator CFieldDataCli*() != 0)
    {
        int nToGroup = spTo->FUN_140375350();
        int nFromGroup = spFrom->FUN_140375350();
        return TSingleton<Client::Constants>::GetInstance()->AreSameGroup(nFromGroup, nToGroup);
    }
    return false;
}
MS2_REPLACE_METHOD(0x141B60B40, UIWorldMapDialog, FUN_141b60b40, 236, 0xEBE314AD);

// @0x141b60c40
void UIWorldMapDialog::FUN_141b60c40(int nFieldId, bool bFlag)
{
    MS2Ptr<ASUIComponent> spInfo = FUN_140c02990("m_searchInfo");
    if (!spInfo)
        return;
    ASObj obj(2);
    if (FUN_140cb17d0()->BuildFieldSearch(nFieldId, &obj, bFlag))
        spInfo->Invoke("setData", obj);
}
MS2_REPLACE_METHOD(0x141B60C40, UIWorldMapDialog, FUN_141b60c40, 242, 0xFA03563C);

// @0x141b60d40
void UIWorldMapDialog::FUN_141b60d40(CStringW strName)
{
    MS2Ptr<ASUIComponent> spInfo = FUN_140c02990("m_searchInfo");
    if (!spInfo)
        return;
    ASObj obj(2);
    if (FUN_140cb17d0()->BuildNameSearch(CStringW(strName), &obj))
        spInfo->Invoke("setData", obj);
}
MS2_REPLACE_METHOD(0x141B60D40, UIWorldMapDialog, FUN_141b60d40, 317, 0x4ABA1518);

// @0x141b60e90
// MS2-FUNCTIONAL: the cash taxi checks (temporaries of the notice strings)
void UIWorldMapDialog::FUN_141b60e90(int nFieldId, MyPC* pPlayer)
{
    m_190 = nFieldId;
    if (pPlayer->FUN_14166ce30() != 0)
    {
        FUN_140d73bc0(0x91, 0, 0, CStringW(L""));
        return;
    }
    if (pPlayer->FUN_141527160(0x2a) == 0)
    {
        FUN_140d73bc0(0x93, 0, 0, CStringW(L""));
        return;
    }
    if (pPlayer->FUN_1416595d0() != 0)
    {
        FUN_140d73bc0(0x92, 0, 0, CStringW(L""));
        return;
    }
    if (pPlayer->FUN_14166c930() == 0x25 || pPlayer->FUN_14166c930() == 0x2a)
    {
        FUN_140d73bc0(0x91, 0, 0, CStringW(L""));
        return;
    }
    if (TSingleton<WorldService>::GetInstance()->FUN_141bd3060() == m_190)
    {
        FUN_140d73bc0(0x8a, 0, 0, CStringW(L""));
        return;
    }
    // m_298 of the world service is the current field's CFieldDataCli (its MS2Ptr dtor is 0x1408850f0)
    if (reinterpret_cast<CFieldDataCli*>(TSingleton<WorldService>::GetInstance()->FUN_141bd30a0().operator->())->FUN_140375390() == 0)
    {
        FUN_140d73bc0(0x8f, 0, 0, CStringW(L""));
        return;
    }
    MS2Ptr<CFieldDataCli> spFrom = CFieldDataCli::Find(FUN_141b69690());
    if (!spFrom)
        return;
    MS2Ptr<CFieldDataCli> spTo = CFieldDataCli::Find(m_190);
    if (!spTo)
        return;
    if (spTo->FUN_1403753d0() == 0)
    {
        CStringW strText = FUN_14052bd00(0x90, FUN_1401a9d70()->FUN_141811980(3, m_190));
        FUN_140d73aa0(CStringW(strText), 0, 0, CStringW(L""));
        return;
    }
    CStringW strError;
    if (FUN_140a55d20(spTo.operator->(), &strError) == 0)
    {
        FUN_140d73aa0(CStringW(strError), 0, 0, CStringW(L""));
        return;
    }
    if (FUN_141b60b40(FUN_141b69690(), m_190) == 0)
    {
        FUN_140d73bc0(0x8e, 0, 0, CStringW(L""));
        return;
    }
    FUN_141b614c0(pPlayer);
}

// @0x141b614c0
// MS2-FUNCTIONAL: the cash taxi prompts (temporaries of the string formats and the delegate copies)
void UIWorldMapDialog::FUN_141b614c0(MyPC* pPlayer)
{
    if (pPlayer->FUN_141662de0() != 0 && FUN_14036d570(FUN_140166410(), 0x57))
    {
        CStringW strText = FUN_1405c2690(CStringW(L"s_taxi_transfer_vip_user"), FUN_1401a9d70()->FUN_141811980(3, m_190));
        FUN_140d73aa0(CStringW(strText), 1, static_cast<IMessageListener*>(this), CStringW(L"onCashTaxi"));
        return;
    }
    if (m_1a0.find(m_190) == m_1a0.end())
    {
        if (FUN_1401c0d90()->FUN_140477ea0() != 0)
        {
            CStringW strText = FUN_14052bd00(0x8d, FUN_1401a9d70()->FUN_141811980(3, m_190));
            FUN_140d73aa0(CStringW(strText), 1, static_cast<IMessageListener*>(this), CStringW(L"onCashTaxi"));
        }
        else if (DAT_143ab2a90.FUN_140a5f7b0(10, 0) >= 1 || DAT_143ab2a90.FUN_140a5f7b0(0xb, 0) >= 1)
        {
            CStringW strText = FUN_14052bd00(0x8c, FUN_1401a9d70()->FUN_141811980(3, m_190));
            FUN_140d73aa0(CStringW(strText), 1, static_cast<IMessageListener*>(this), CStringW(L"onCashTaxi"));
        }
        else
        {
            __int64 nFare = FUN_1409f24a0()->FUN_14085fc80((short)pPlayer->vfunc_78());
            if (nFare != 0)
                nFare = FUN_140632990(nFare, 1.0f - FUN_1411e1110(pPlayer->FUN_1416561a0(), 0xaa));
            CStringW strText = FUN_140f1fa40(CStringW(L"s_cash_taxi_transfer_meso"), FUN_1401a9d70()->FUN_141811980(3, m_190), nFare);
            FUN_141b62e40(CStringW(strText), 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UIWorldMapDialog::FUN_141b5ad60), nFare);
        }
        return;
    }
    int nNeed = 3;
    if (FUN_140166410()->FUN_14036e5b0())
        nNeed = 1;
    int nTickets = DAT_143ab2a90.FUN_140a5f7b0(0xb, 0);
    if (nTickets >= nNeed)
    {
        CStringW strText = FUN_1405c2690(CStringW(L"s_cash_taxi_transfer_advanced"), FUN_1401a9d70()->FUN_141811980(3, m_190));
        FUN_140d73aa0(CStringW(strText), 1, static_cast<IMessageListener*>(this), CStringW(L"onCashTaxi"));
        return;
    }
    if (!FUN_14036d570(FUN_140166410(), 0x83))
    {
        CStringW strKey(L"s_err_cash_taxi_need_advanced_ticket");
        FUN_140d73aa0(FUN_14028b8e0(strKey), 0, 0, CStringW(L""));
        return;
    }
    FUN_140d86260()->vfunc_43(2, 0, 1000);
    __int64 nPrice = *TSingleton<Client::Constants>::GetInstance()->MeratAirTaxiPrice.Get();
    if (nPrice != 0)
        nPrice = FUN_140632990(nPrice, 1.0f - FUN_1411e1110(pPlayer->FUN_1416561a0(), 0xaa));
    FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIWorldMapDialog::FUN_141b5ae00),
        FUN_140c160b0(CStringW(L"s_err_cash_taxi_need_advanced_ticket_merat"), nPrice));
}

// @0x141b61ff0
void UIWorldMapDialog::FUN_141b61ff0(int nKey)
{
    int nOld = m_1c4;
    m_1c4 = nKey;
    MS2Ptr<UIWorldMap::MapTile> spOld = FUN_140cb17d0()->FindMapTileByKey(nOld);
    if (spOld.operator UIWorldMap::MapTile*() != 0)
        FUN_141b58350(spOld);
    MS2Ptr<UIWorldMap::MapTile> spNew = FUN_140cb17d0()->FindMapTileByKey(nKey);
    if (spNew.operator UIWorldMap::MapTile*() != 0)
        FUN_141b58350(spNew);
}
MS2_REPLACE_METHOD(0x141B61FF0, UIWorldMapDialog, FUN_141b61ff0, 274, 0xFC02AC08);

// ---- template COMDATs of the unit ------------------------------------------------------------------------------------

// Values<unsigned>::Get (0x141b69620, with its inline memcpy_s 0x141b6d9f0) is a COMDAT of this unit (the special npc ids)
template <class T> bool Common::Constants::Values<T>::Get(ATL::CAtlArray<T>& out)
{
    if (m_loaded)
    {
        out.RemoveAll();
        out.Append(m_values);
        return true;
    }
    if (!HasKey())
        Error("constants has no key");
    return false;
}

// @0x141b62fc0
static MS2Ptr<CMsgBoxData> FUN_141b62fc0(Delegate<bool(int, const CMsgBoxData&)> kHandler, CStringW strKey, CStringW strArg)
{
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(1));
    spBox->FUN_141a01570(FUN_1405c2690(CStringW(strKey), strArg));
    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(kHandler));
    FUN_14151f150(MS2Ptr<CMsgBoxData>(spBox));
    return spBox;
}

// @0x141b62e40
static MS2Ptr<CMsgBoxData> FUN_141b62e40(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> kHandler, __int64 nPrice)
{
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(nType));
    spBox->FUN_141a01570(strText);
    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(kHandler));
    spBox->FUN_140e01830(nPrice);
    FUN_14151f150(MS2Ptr<CMsgBoxData>(spBox));
    return spBox;
}

// @0x141b62110
static CStringW FUN_141b621d0(int nChannel);                                // the channel line
static CStringW FUN_141b622d0(unsigned short nLevel, int nKind);           // the quest level line
template <class T> T FUN_141b62a20(int nQuestId, const T& a0, const T& a1, const T& a2, const T& a3);   // a value by the quest's state
static bool FUN_141b62110(const MS2Ptr<UIWorldMap::MapTile>& spA, const MS2Ptr<UIWorldMap::MapTile>& spB)
{
    if (spA->m_18 == spB->m_18)
        return spA->m_50 < spB->m_50;
    return spA->m_18 < spB->m_18;
}

// @0x141b621d0
static CStringW FUN_141b621d0(int nChannel)
{
    CStringW strLine;
    if (nChannel == FUN_14092f640())
        strLine = FUN_1408116a0(0x71b, nChannel);
    else
        strLine = FUN_1408116a0(0x71c, nChannel);
    return strLine;
}

// @0x141b622d0
static CStringW FUN_141b622d0(unsigned short nLevel, int nKind)
{
    CStringW strLine;
    if (nKind == 5 || nKind == 10)
        strLine = FUN_1409e88d0(0x714, nLevel);
    else
        strLine = FUN_1409e88d0(0x713, nLevel);
    return strLine;
}

// @0x141b62ac0
template <class T> T FUN_141b62ac0(MS2Ptr<CQuestData> spQuest, const T& a0, const T& a1, const T& a2, const T& a3)
{
    if (spQuest.get() == 0)
        return a1;
    switch (FUN_14074b050(spQuest.operator->()))
    {
    case 0:
        return a0;
    case 1:
    case 6:
        if (FUN_1407640c0(spQuest.operator->()))
            return a2;
        return a1;
    case 2:
        return a3;
    case 8:
    case 9:
        return a1;
    default:
        return a1;
    }
}

// @0x141b62a20
template <class T> T FUN_141b62a20(int nQuestId, const T& a0, const T& a1, const T& a2, const T& a3)
{
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
    return FUN_141b62ac0(spQuest, a0, a1, a2, a3);
}

// @0x141b62980
CStringW FUN_141b62980(int nStrId, const __int64& v0)
{
    const fmt::internal::ArgArray<1>::Type array = {fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v0)};
    return FUN_14028dee0(nStrId, fmt::ArgList(fmt::internal::wc_make_type(v0), array));
}

// @0x141b62da0
void ASObj::FUN_141b62da0(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x141b62c20
inline Scaleform::GFx::Value AScript::FUN_141b62c20(const char* szMethod, int a1, const AScript& a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bce40(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141b62ce0
inline Scaleform::GFx::Value AScript::FUN_141b62ce0(const char* szMethod, unsigned __int64 a1, unsigned int a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce00(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// memcpy_s 0x141b6d9f0 closes the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_worldMapMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc3530-0x142cc35a0 .text$yd
