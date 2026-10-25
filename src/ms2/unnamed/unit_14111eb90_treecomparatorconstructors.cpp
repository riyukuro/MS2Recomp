// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tree container constructors taking a comparator (std::map /
// std::set (const key_compare&) and the _Tree base constructor), one instance per map family; stand-in value types.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_14111eb90
// MS2-RANGE: 0x14111eb90-0x14111fdf0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$00@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$00@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111eb90 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$01@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$01@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ebc0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$02@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$02@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ebf0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BN@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0BN@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ec20 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$03@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$03@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ec50 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$04@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$04@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ec80 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$05@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$05@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ecb0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BO@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0BO@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ece0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$06@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$06@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ed10 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$07@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$07@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ed40 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BP@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0BP@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ed70 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0CA@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CA@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111eda0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0CB@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CB@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111edd0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$08@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$08@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ee00 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$09@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$09@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ee30 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BA@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BA@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ee60 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BB@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BB@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ee90 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BC@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BC@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111eec0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BD@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BD@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111eef0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BE@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BE@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ef20 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0CC@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CC@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ef50 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BF@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BF@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111ef80 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BG@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BG@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111efb0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BH@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BH@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111efe0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BI@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BI@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f010 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BJ@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BJ@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f040 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BK@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BK@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f070 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0CD@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CD@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f0a0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BL@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BL@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f0d0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0BM@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BM@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f100 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0L@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0L@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f130 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0CE@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CE@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f160 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0M@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0M@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f190 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0N@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0N@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f1c0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0CF@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CF@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f1f0 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0O@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0O@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f220 ; probe
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IU?$Unk_MC@$0CG@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CG@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f250 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$00@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$00@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f2b0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$01@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$01@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f300 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$02@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$02@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f350 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BN@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0BN@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f3a0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$03@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$03@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f3e0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$04@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$04@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f430 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$05@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$05@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f480 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BO@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0BO@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f4d0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$06@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$06@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f510 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$07@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$07@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f560 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BP@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0BP@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f5b0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0CA@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CA@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f5f0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0CB@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CB@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f630 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$08@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$08@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f670 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$09@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$09@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f6c0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BA@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BA@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f710 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BB@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BB@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f760 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BC@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BC@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f7b0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BD@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BD@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f800 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BE@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BE@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f850 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0CC@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CC@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f8a0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BF@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BF@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f8e0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BG@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BG@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f930 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BH@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BH@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f980 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BI@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BI@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111f9d0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BJ@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BJ@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fa20 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BK@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BK@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fa70 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0CD@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CD@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fac0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BL@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BL@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fb00 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0BM@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0BM@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fb50 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0L@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0L@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fba0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0CE@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CE@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fbf0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0M@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0M@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fc30 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0N@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0N@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fc80 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0CF@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CF@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fcd0 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0O@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0O@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fd10 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0CG@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_MC@$0CG@@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fd60 ; probe
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IU?$Unk_MC@$0P@@@U?$less@I@std@@U?$Unk_McAlloc@U?$pair@$$CBIU?$Unk_MC@$0P@@@@std@@@@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14111fda0 ; probe
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <set>
#include "ms2/ms2recover.h"

template <int N> struct Unk_MC { int v[N + 1]; };

// Stand-in for the exe's tree allocator: a converting constructor and a user-provided destructor are out-of-line calls.
template <class T>
struct Unk_McAlloc
{
    typedef T value_type;
    template <class U> struct rebind { typedef Unk_McAlloc<U> other; };
    Unk_McAlloc() {}
    template <class U> Unk_McAlloc(const Unk_McAlloc<U>&) {}
    ~Unk_McAlloc() {}
    T* allocate(size_t n) { return (T*)::operator new(n * sizeof(T)); }
    void deallocate(T* p, size_t) { ::operator delete(p); }
};

// 28 families whose tree uses the stand-in allocator, 10 that use std::allocator
template <int N> void Unk_McCustom()
{
    std::map<unsigned, Unk_MC<N>, std::less<unsigned>, Unk_McAlloc<std::pair<const unsigned, Unk_MC<N> > > > m((std::less<unsigned>()));
}
template <int N> void Unk_McStd()
{
    std::map<unsigned, Unk_MC<N> > m((std::less<unsigned>()));
}

void Unk_MCAnchor()
{
    Unk_McCustom<1>();
    Unk_McCustom<2>();
    Unk_McCustom<3>();
    Unk_McCustom<4>();
    Unk_McCustom<5>();
    Unk_McCustom<6>();
    Unk_McCustom<7>();
    Unk_McCustom<8>();
    Unk_McCustom<9>();
    Unk_McCustom<10>();
    Unk_McCustom<11>();
    Unk_McCustom<12>();
    Unk_McCustom<13>();
    Unk_McCustom<14>();
    Unk_McCustom<15>();
    Unk_McCustom<16>();
    Unk_McCustom<17>();
    Unk_McCustom<18>();
    Unk_McCustom<19>();
    Unk_McCustom<20>();
    Unk_McCustom<21>();
    Unk_McCustom<22>();
    Unk_McCustom<23>();
    Unk_McCustom<24>();
    Unk_McCustom<25>();
    Unk_McCustom<26>();
    Unk_McCustom<27>();
    Unk_McCustom<28>();
    Unk_McStd<29>();
    Unk_McStd<30>();
    Unk_McStd<31>();
    Unk_McStd<32>();
    Unk_McStd<33>();
    Unk_McStd<34>();
    Unk_McStd<35>();
    Unk_McStd<36>();
    Unk_McStd<37>();
    Unk_McStd<38>();
}
