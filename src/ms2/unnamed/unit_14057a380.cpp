// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT tail of client/ms2-independent commonfiles/itemdatatable.cpp:
// the std/ATL template members that sort after the table's code (vector/list/hash/tree glue over MS2Ptr<CItemData> & co).
// The instantiations come from the table's own member bodies, so this unit compiles the table source again and only
// its tail (this unit's ranges) is paired.
// MS2-UNIT: unit_14057a380
// MS2-RANGE: 0x14057a380-0x14057a5c0 .text$mn
// MS2-RANGE: 0x14057a5c0-0x140583f00 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_7CItemDataTable@@6B?$TSingleton@VCItemDataTable@@@@@ 0x142d5f500
// MS2-PIN: ??_7CItemDataTable@@6B?$CValidData@VCItemDataTable@@@@@ 0x142d5f510
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@ATL@@@ATL@@@@6B@ 0x142d5f538
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlMap@HV?$MS2Ptr@VItemColorEx@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VItemColorEx@@@@@3@@ATL@@@@6B@ 0x142d5f528
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Change_array@?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@AEAAXQEAV?$MS2Ptr@VDropNifData@@@@_K1@Z 0x14057b100 ; unique
// MS2-PIN: ?_Destroy@?$vector@V?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCItemData@@@@0@Z 0x14057b870 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VItemHousing@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@2@@Z 0x14057dca0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VItemModelData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@2@@Z 0x14057dcd0 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VItemMusicScore@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@2@@Z 0x14057dd00 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@2@@Z 0x14057dd30 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_TrophyKey@@U?$less@UUnk_TrophyKey@@@std@@V?$allocator@UUnk_TrophyKey@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_TrophyKey@@PEAX@2@@Z 0x14057dd60 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VItemHousing@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@2@@Z 0x14057dd90 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$MS2Ptr@VItemMusicScore@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@2@@Z 0x14057ddf0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@2@@Z 0x14057de20 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@UUnk_TrophyKey@@U?$less@UUnk_TrophyKey@@@std@@V?$allocator@UUnk_TrophyKey@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@UUnk_TrophyKey@@PEAX@2@@Z 0x14057de50 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@std@@V?$_Vector_val@U?$_Simple_types@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$_List_unchecked_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@std@@@2@XZ 0x14057e3c0 ; unique
// MS2-PIN: ?_Make_iter@?$list@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@2@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@2@@Z 0x14057f530 ; unique
// MS2-PIN: ?_Make_iter@?$list@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@2@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@@2@V?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@@std@@@std@@U_Iterator_base0@2@@2@@Z 0x14057f580 ; unique
// MS2-PIN: ?Release@?$MS2Ptr@VItemDropEffect@@@@AEAAXXZ 0x14057fec0 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VItemTagParam@CItemDataTable@@@@AEAAXXZ 0x14057ff00 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VItemColorEx@@@@AEAAXXZ 0x140580000 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VItemHousing@@@@AEAAXXZ 0x140580040 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VItemDropEffect@@@@AEAAXPEAX@Z 0x140580150 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VItemTagParam@CItemDataTable@@@@AEAAXPEAX@Z 0x1405801a0 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VItemColorEx@@@@AEAAXPEAX@Z 0x1405802e0 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VItemHousing@@@@AEAAXPEAX@Z 0x140580330 ; prop
// MS2-PIN: ?_Umove@?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@AEAAPEAV?$MS2Ptr@VDropNifData@@@@PEAV3@00@Z 0x140580cf0 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VDropNifData@@@@00U?$integral_constant@_N$0A@@2@@Z 0x140580db0 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$MS2Ptr@VCItemData@@@@V?$allocator@V?$MS2Ptr@VCItemData@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VCItemData@@@@00U?$integral_constant@_N$0A@@2@@Z 0x140580df0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@std@@@2@QEAU?$_List_node@U?$pair@$$CBHV?$MS2Ptr@VCItemData@@@@@std@@PEAX@2@_K@Z 0x140581fc0 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemHousing@@@@@std@@PEAX@2@_K@Z 0x140581ff0 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemModelData@@@@@std@@PEAX@2@_K@Z 0x140582020 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VItemMusicScore@@@@@std@@PEAX@2@_K@Z 0x140582050 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@2@_K@Z 0x140582080 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@UUnk_TrophyKey@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@UUnk_TrophyKey@@PEAX@std@@@2@QEAU?$_Tree_node@UUnk_TrophyKey@@PEAX@2@_K@Z 0x1405820b0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$MS2Ptr@VDropNifData@@@@V?$allocator@V?$MS2Ptr@VDropNifData@@@@@std@@@std@@@std@@PEAX@2@_K@Z 0x1405821a0 ; prop
// MS2-PINS-END tplpin
#ifndef MS2_HOOK_DLL   // the hook DLL gets all of this from commonfiles/itemdatatable.cpp itself
#include "ms2/commonfiles/itemdatatable.cpp"

// ---- the exe's static-teardown function of the item default tables (CItemDefaultData::ms_aMaps and its sibling) ----
extern char g_itemDefaultSiblingStatic[0x50];                    // 0x143aaf9f0; owned by ?\itemdefaultdata.cpp
void FUN_14058a830(void* pThis);

// @0x140583ea0
void FUN_140583ea0()
{
    for (int i = 0; i < 2; i++) {
        g_itemDefaultSlotMaps[i].RemoveAll();
    }
    FUN_14058a830(g_itemDefaultSiblingStatic);
}
#endif
