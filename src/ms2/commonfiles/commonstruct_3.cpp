// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 3 of commonstruct.cpp: the COMDAT tail
// 0x14027f2d0-0x140287f50 (iterator operators, ??_G, CAtlArray/CAtlList/CAtlMap/CRBTree and TPtr members, the first
// std::vector/list/_Tree internals). The instantiations are in commonstruct_tail.inl (shared with part 4).
// MS2-UNIT: commonfiles\commonstruct.cpp#3
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x14027f2d0-0x140287f50 .text$mn
// The boxed history list of CUserLimitGroup (RTTI TPtredDummy<CAtlList<TPtr<CUserLimitHistory>>>; TPtr = our MS2Ptr):
// ICF-folded vector internals (identical code for several element types; hand-paired by the v2525 names):
// MS2-PIN: ?_Buy@?$vector@_JV?$allocator@_J@std@@@std@@AEAA_N_K@Z 0x140286a60
// MS2-PIN: ?_Buy@?$vector@V?$MS2Ptr@VCPtred@@@@V?$allocator@V?$MS2Ptr@VCPtred@@@@@std@@@std@@AEAA_N_K@Z 0x140286b50
// MS2-PIN: ?_Change_array@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@AEAAXQEAV?$MS2Ptr@VCIngredientInfo@@@@_K1@Z 0x1402873b0
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@6B@ 0x142d15c08
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAPEBU?$pair@$$CBHH@1@XZ 0x14027f350 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHH@1@XZ 0x14027f410 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHH@1@XZ 0x14027f430 ; prop
// MS2-PIN: ??D?$reverse_iterator@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@std@@@std@@@std@@QEBAAEAUItemEntity@@XZ 0x14027f4b0 ; unique
// MS2-PIN: ??E?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f530 ; prop
// MS2-PIN: ??E?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f550 ; prop
// MS2-PIN: ??E?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14027f570 ; prop
// MS2-PIN: ??E?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f590 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14027f5b0 ; hand: map<int,int> const_iterator++(int) (copies, calls 0x14027f600; caller erase 0x14028ab00)
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f600 ; hand: calls _Tree_unchecked_const_iterator++ 0x14027f620 (was the vector<ItemEntity> -- look-alike)
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14027f620 ; unique
// MS2-PIN: ??0?$list@V?$MS2Ptr@VCUserChangeableItemHistory@@@@V?$allocator@V?$MS2Ptr@VCUserChangeableItemHistory@@@@@std@@@std@@QEAA@XZ 0x14027f740 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14027f760 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x14027f870 ; unique
// MS2-PIN: ??_GCNode@?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@QEAAPEAXI@Z 0x14027fcf0 ; prop
// MS2-PIN: ?FUN_1402804e0@CLogString@@QEAAX_K0HPEB_W@Z 0x1402804e0 ; unique
// MS2-PIN: ?CallConstructors@?$CAtlArray@UUnk_QuestMaskRange@@V?$CElementTraits@UUnk_QuestMaskRange@@@ATL@@@ATL@@CAXPEAUUnk_QuestMaskRange@@_K@Z 0x140280770 ; unique
// MS2-PIN: ?Copy@?$CAtlArray@UUnk_Z16i@@V?$CElementTraits@UUnk_Z16i@@@ATL@@@ATL@@QEAAXAEBV12@@Z 0x140280a70 ; prop
// MS2-PIN: ?CopyElements@?$CElementTraitsBase@VUnk_CommonPriceRecord@@@ATL@@SAXPEAVUnk_CommonPriceRecord@@PEBV3@_K@Z 0x140280bc0 ; unique
// MS2-PIN: ?FindNextNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140280ea0 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x140280f60 ; prop
// MS2-PIN: ?FreeNode@?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@AEAAXPEAVCNode@12@@Z 0x140281090 ; prop
// MS2-PIN: ?FreeNode@?$CAtlList@W4Unk_AdditionalEventValue@@V?$CElementTraits@W4Unk_AdditionalEventValue@@@ATL@@@ATL@@AEAAXPEAVCNode@12@@Z 0x140281100 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x140281170 ; unique
// MS2-PIN: ?Owner@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@PEAV?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@Z 0x140281490 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAAEAUUnk_CommonCachedPacket@@PEAU__POSITION@@@Z 0x1402814d0 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@UUnk_CommonPacketLogEntry@@V?$CElementTraits@UUnk_CommonPacketLogEntry@@@ATL@@@ATL@@QEBA_KXZ 0x1402815c0 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@VUnk_CommonPriceRecord@@V?$CElementTraits@VUnk_CommonPriceRecord@@@ATL@@@ATL@@QEBA_KXZ 0x1402815d0 ; prop
// MS2-PIN: ?GetCount@?$CAtlArray@VUnk_CommonPrice@@V?$CElementTraits@VUnk_CommonPrice@@@ATL@@@ATL@@QEBA_KXZ 0x1402815e0 ; prop
// MS2-PIN: ?GetCount@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEBA_KXZ 0x140281600 ; prop
// MS2-PIN: ?GetHeadPosition@?$CAtlList@W4Unk_AdditionalEventValue@@V?$CElementTraits@W4Unk_AdditionalEventValue@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x140281950 ; prop
// MS2-PIN: ?GetInstance@?$TSingleton@VCItemDataTable@@@@SAPEAVCItemDataTable@@XZ 0x140281980 ; unique
// MS2-PIN: ?GetKeyAt@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEBAAEBHPEAU__POSITION@@@Z 0x140281a00 ; prop
// MS2-PIN: ?GetNext@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAAEAUUnk_CommonCachedPacket@@AEAPEAU__POSITION@@@Z 0x140281a70 ; prop
// MS2-PIN: ?GetNext@?$CAtlList@W4Unk_AdditionalEventValue@@V?$CElementTraits@W4Unk_AdditionalEventValue@@@ATL@@@ATL@@QEBAAEBW4Unk_AdditionalEventValue@@AEAPEAU__POSITION@@@Z 0x140281b70 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x140281c90 ; prop
// MS2-PIN: ?GetStartPosition@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x140281fb0 ; prop
// MS2-PIN: ?GetValueAt@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEAAAEAW4Unk_LimitValue@@PEAU__POSITION@@@Z 0x1402821a0 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@UUnk_Z16i@@V?$CElementTraits@UUnk_Z16i@@@ATL@@@ATL@@AEAA_N_K@Z 0x140282270 ; prop
// MS2-PIN: ?GrowBuffer@?$CAtlArray@UUnk_CommonPacketLogEntry@@V?$CElementTraits@UUnk_CommonPacketLogEntry@@@ATL@@@ATL@@AEAA_N_K@Z 0x1402825b0 ; prop
// MS2-PIN: ?IsEmpty@?$CAtlMap@HW4Unk_LimitValue@@V?$CElementTraits@H@ATL@@V?$CElementTraits@W4Unk_LimitValue@@@3@@ATL@@QEBA_NXZ 0x140282e30 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1402833c0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXI@Z 0x140284450 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@UUnk_Z16i@@@ATL@@SAXPEAUUnk_Z16i@@0_K@Z 0x1402848b0 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@UUnk_CommonCachedPacket@@@ATL@@SAXPEAUUnk_CommonCachedPacket@@0_K@Z 0x1402848f0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@UUnk_CommonPacketLogEntry@@@ATL@@SAXPEAUUnk_CommonPacketLogEntry@@0_K@Z 0x140284930 ; prop
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@VUnk_CommonPriceRecord@@@ATL@@SAXPEAVUnk_CommonPriceRecord@@0_K@Z 0x140284970 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@VUnk_CommonPrice@@@ATL@@SAXPEAVUnk_CommonPrice@@0_K@Z 0x1402849b0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlArray@VUnk_CommonPriceRecord@@V?$CElementTraits@VUnk_CommonPriceRecord@@@ATL@@@ATL@@QEAAXXZ 0x1402849f0 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAXXZ 0x140284a50 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@QEAAXXZ 0x140284b30 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlList@W4Unk_AdditionalEventValue@@V?$CElementTraits@W4Unk_AdditionalEventValue@@@ATL@@@ATL@@QEAAXXZ 0x140284c10 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x140284cf0 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1402850a0 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140285430 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAPEAU__POSITION@@HH@Z 0x140285720 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@UUnk_Z16i@@V?$CElementTraits@UUnk_Z16i@@@ATL@@@ATL@@QEAA_N_KH@Z 0x1402858c0 ; prop
// MS2-PIN: ?SetCount@?$CAtlArray@UUnk_CommonPacketLogEntry@@V?$CElementTraits@UUnk_CommonPacketLogEntry@@@ATL@@@ATL@@QEAA_N_KH@Z 0x140285a50 ; prop
// MS2-PIN: ?AddRef@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@AEBAXXZ 0x1402864f0 ; prop
// MS2-PIN: ?Reference@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@CAXPEAV?$TPtredDummy@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@@Z 0x1402866c0 ; prop
// MS2-PIN: ?AddRefImpl@?$TPtrValue@V?$CAtlList@V?$MS2Ptr@VCUserLimitHistory@@@@V?$CElementTraits@V?$MS2Ptr@VCUserLimitHistory@@@@@ATL@@@ATL@@@@AEBAXPEAX@Z 0x140286850 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x140286c60 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@XZ 0x140286de0 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEBA_K_K@Z 0x140286f50 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@AEBA_K_K@Z 0x140286fe0 ; prop
// MS2-PIN: ?_Change_array@?$vector@UItemEntity@@V?$allocator@UItemEntity@@@std@@@std@@AEAAXQEAUItemEntity@@_K1@Z 0x140287190 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x1402874c0 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x140287520 ; unique
// MS2-PIN: ?_Destroy@?$vector@V?$MS2Ptr@VCIngredientInfo@@@@V?$allocator@V?$MS2Ptr@VCIngredientInfo@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCIngredientInfo@@@@0@Z 0x140287670 ; prop
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x1402876f0 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x140287740 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@@Z 0x1402877e0 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@2@XZ 0x140287eb0 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/commonfiles/commonstruct_tail.inl"

#include "ms2/client/ms2/blockmanager.h"
#include "ms2/placeholder/billboardinfo.h"
#include "ms2/placeholder/cclienthardwareinfo.h"
#include "ms2/commonfiles/cmarketbuylimithistory.h"
#include "ms2/commonfiles/skillconfig.h"
#include "ms2/commonfiles/commonstruct_wb.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/placeholder/itemcustom.h"

// The two classes below are defined by their owning units only (unit_1402698d0.cpp / unit_140267390.cpp, with
// unit-local member types); the scalar deleting destructors need just their destructor and size.
class CPremiumProductLimitInfo : public CPtred
{
public:
    virtual ~CPremiumProductLimitInfo();                // 0x140269970
private:
    char m_body[0x80 - sizeof(CPtred)];
};
MS2_CHECK_SIZE(CPremiumProductLimitInfo, 0x80);

class RemakeOptionContext : public CPtred
{
public:
    virtual ~RemakeOptionContext();                     // 0x1402675b0
private:
    char m_body[0x80 - sizeof(CPtred)];
};
MS2_CHECK_SIZE(RemakeOptionContext, 0x80);

// Scalar deleting destructors (vftable slot 0) of the CPtred records. Their vftables are emitted by the parts that
// construct them (commonstruct.cpp #1/#2 and the record units), so these COMDATs have no producer here; each is spelled
// out as the compiler generates it.
#define MS2_CS_SCALAR_DELETING_DTOR(T)                                                                           \
    void* Unk_ScalarDeletingDtor(T* self, unsigned int flags)                                                   \
    {                                                                                                           \
        self->T::~T();                                                                                          \
        if (flags & 1)                                                                                          \
            operator delete(self, sizeof(T));                                                                   \
        return self;                                                                                            \
    }
// @0x14027f9b0
MS2_CS_SCALAR_DELETING_DTOR(AccountBlockInfo)
// @0x14027f9f0
MS2_CS_SCALAR_DELETING_DTOR(AdditionalEffectEventCtx)
// @0x14027fa30
MS2_CS_SCALAR_DELETING_DTOR(BaseOption)
// @0x14027fa70
MS2_CS_SCALAR_DELETING_DTOR(BillBoardInfo)
// @0x14027fab0
MS2_CS_SCALAR_DELETING_DTOR(CAdditionalEvent)
// @0x14027faf0
MS2_CS_SCALAR_DELETING_DTOR(CChangeableHistoryInfo)
// @0x14027fb30
MS2_CS_SCALAR_DELETING_DTOR(CClientHardwareInfo)
// @0x14027fb70
MS2_CS_SCALAR_DELETING_DTOR(CDBMarketBuyLimitHistory)
// @0x14027fbb0
MS2_CS_SCALAR_DELETING_DTOR(CIngredientContainer)
// @0x14027fbf0
MS2_CS_SCALAR_DELETING_DTOR(CIngredientInfo)
// @0x14027fc30
MS2_CS_SCALAR_DELETING_DTOR(CMarketBuyLimitHistory)
// @0x14027fc70
MS2_CS_SCALAR_DELETING_DTOR(CMarketBuyLimitProduct)
// @0x14027fdb0
MS2_CS_SCALAR_DELETING_DTOR(CPremiumProductLimitInfo)
// @0x14027fdf0
MS2_CS_SCALAR_DELETING_DTOR(CSkillBookTreeTabConfig)
// @0x14027fe30
MS2_CS_SCALAR_DELETING_DTOR(CSkillCompactControlConfig)
// @0x14027fe70
MS2_CS_SCALAR_DELETING_DTOR(CUserChangeableItemHistory)
// @0x14027feb0
MS2_CS_SCALAR_DELETING_DTOR(CUserLimitGroup)
// @0x14027fef0
MS2_CS_SCALAR_DELETING_DTOR(CUserLimitHistory)
// @0x14027ff30
MS2_CS_SCALAR_DELETING_DTOR(ChangeableProductInfo)
// @0x14027ff70
MS2_CS_SCALAR_DELETING_DTOR(DamageCalculatorInfo)
// @0x14027ffb0
MS2_CS_SCALAR_DELETING_DTOR(DungeonRewardInfo)
// @0x14027fff0
MS2_CS_SCALAR_DELETING_DTOR(HomeBlockInfo)
// @0x140280030
MS2_CS_SCALAR_DELETING_DTOR(InvokeEffectOption)
// @0x140280070
MS2_CS_SCALAR_DELETING_DTOR(ItemCustom)
// @0x1402800f0
MS2_CS_SCALAR_DELETING_DTOR(NpcShopItemLife)
// @0x140280130
MS2_CS_SCALAR_DELETING_DTOR(QuestMask)
// @0x140280170
MS2_CS_SCALAR_DELETING_DTOR(RemakeOptionContext)
// @0x1402801b0
MS2_CS_SCALAR_DELETING_DTOR(WeddingHallReservationFee)
// MS2-PIN: ??F?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14027f850 ; hand: reverse_iterator<vector<ItemEntity>::iterator>::operator* 0x14027f4b0 calls it; it calls const_iterator-- 0x14027f830 (sub 0x30)
