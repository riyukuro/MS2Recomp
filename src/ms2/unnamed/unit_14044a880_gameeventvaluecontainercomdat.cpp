// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDATs of commonfiles\gameeventvalue.cpp's real TU
// (0x140422c10-0x14046c710), sorted by mangled name: the non-template members of the ATL containers behind the event
// value classes (CAtlArray / CAtlList / CAtlMap / CRBMap / CRBMultiMap, `?Add` .. `?SetOptimalLoad`).
// gameeventvalue.cpp's bodies reference them; the members are emitted here through explicit instantiations, and
// members the exe never kept stay unpaired.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_14044a880
// MS2-RANGE: 0x14044a880-0x14045b2c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GCNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAXI@Z 0x14044a8c0 ; prop
// MS2-PIN: ??_GCNode@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@QEAAPEAXI@Z 0x14044a940 ; prop
// MS2-PIN: ??_GCNode@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAAPEAXI@Z 0x14044a9c0 ; prop
// MS2-PIN: ?AddTail@?$CAtlList@V?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$MS2Ptr@VUnk_DayItemContext@@@@@Z 0x14044acb0 ; prop
// MS2-PIN: ?AddTail@?$CAtlList@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$MS2Ptr@VUnk_FieldObjectDropContext@@@@@Z 0x14044ad30 ; prop
// MS2-PIN: ?AddTail@?$CAtlList@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@Z 0x14044adb0 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEAAPEAVCNode@12@III@Z 0x14044af20 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x14044b0a0 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$MS2Ptr@VFestivalContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VFestivalContext@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x14044b120 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x14044b1a0 ; prop
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x14044b2a0 ; prop
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAXXZ 0x14044b5a0 ; prop
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAXXZ 0x14044b5c0 ; prop
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAAXXZ 0x14044b600 ; prop
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAXXZ 0x14044b620 ; prop
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAXXZ 0x14044b640 ; prop
// MS2-PIN: ?Find@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEBAPEAVCNode@12@I@Z 0x14044b6a0 ; unique
// MS2-PIN: ?FindNextNode@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x14044b960 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044bc60 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044bd50 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044be40 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044c030 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044c430 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044c730 ; prop
// MS2-PIN: ?FreeNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@UUnk_FieldTimeSpan@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_FieldTimeSpan@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044c910 ; unique
// MS2-PIN: ?FreeNode@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044ca10 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXXZ 0x14044cb50 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEAAXXZ 0x14044cba0 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@AEAAXXZ 0x14044cbf0 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAXXZ 0x14044cc90 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEAAXXZ 0x14044cdd0 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@AEAAXXZ 0x14044cec0 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@UUnk_FieldTimeSpan@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_FieldTimeSpan@@@2@@ATL@@AEAAXXZ 0x14044cf60 ; prop
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEBAIXZ 0x14044d320 ; prop
// MS2-PIN: ?GetNext@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14044d3d0 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x14044d980 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x14044dd40 ; prop
// MS2-PIN: ?GetPrev@?$CRBTree@IV?$MS2Ptr@VRestrictionData@CGameEventValueItemTradeRestriction@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VRestrictionData@CGameEventValueItemTradeRestriction@@@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14044e2f0 ; prop
// MS2-PIN: ?InitHashTable@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA_NI_N@Z 0x14044ea10 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAA_NI_N@Z 0x14044eb30 ; prop
// MS2-PIN: ?InitHashTable@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@QEAA_NI_N@Z 0x14044ec50 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAA_NI_N@Z 0x14044ee90 ; prop
// MS2-PIN: ?InitHashTable@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAA_NI_N@Z 0x14044f310 ; prop
// MS2-PIN: ?InitHashTable@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAA_NI_N@Z 0x14044f670 ; unique
// MS2-PIN: ?Insert@?$CRBMultiMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAAPEAU__POSITION@@II@Z 0x14044f9d0 ; unique
// MS2-PIN: ?InsertImpl@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAPEAVCNode@12@II@Z 0x14044fa00 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEBA_NXZ 0x14044fd80 ; prop
// MS2-PIN: ?IsLocked@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@AEBA_NXZ 0x14044fdb0 ; prop
// MS2-PIN: ?IsLocked@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEBA_NXZ 0x14044fe10 ; prop
// MS2-PIN: ?IsLocked@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEBA_NXZ 0x14044fed0 ; prop
// MS2-PIN: ?IsLocked@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@AEBA_NXZ 0x14044ff60 ; prop
// MS2-PIN: ?IsLocked@?$CAtlMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEBA_NXZ 0x14044ff90 ; prop
// MS2-PIN: ?IsNil@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEBA_NPEAVCNode@12@@Z 0x14044fff0 ; unique
// MS2-PIN: ?LeftRotate@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140450070 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEBA_NIAEAV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@Z 0x140450420 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@QEBA_NIAEAV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@Z 0x140450490 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAAPEAVCPair@12@I@Z 0x140450500 ; prop
// MS2-PIN: ?Maximum@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140450720 ; unique
// MS2-PIN: ?Minimum@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140450800 ; unique
// MS2-PIN: ?NewNode@?$CAtlList@V?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@AEBV?$MS2Ptr@VUnk_DayItemContext@@@@PEAV312@1@Z 0x1404508e0 ; prop
// MS2-PIN: ?NewNode@?$CAtlList@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@AEBV?$MS2Ptr@VUnk_FieldObjectDropContext@@@@PEAV312@1@Z 0x1404509a0 ; prop
// MS2-PIN: ?NewNode@?$CAtlList@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@AEBV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@PEAV312@1@Z 0x140450a60 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@KII@Z 0x140450b20 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEAAPEAVCNode@12@III@Z 0x140450d30 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@AEAAPEAVCNode@12@III@Z 0x140450f40 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140451360 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140451780 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140451ba0 ; prop
// MS2-PIN: ?NewNode@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@AEAAPEAVCNode@12@III@Z 0x1404521d0 ; unique
// MS2-PIN: ?NewNode@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAPEAVCNode@12@II@Z 0x140452800 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@AEBAI_K@Z 0x140452cc0 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEBAI_K@Z 0x140452db0 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@AEBAI_K@Z 0x140452ea0 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEBAI_K@Z 0x140453080 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEBAI_K@Z 0x140453440 ; prop
// MS2-PIN: ?PickSize@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@AEBAI_K@Z 0x140453710 ; prop
// MS2-PIN: ?Predecessor@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x1404539e0 ; unique
// MS2-PIN: ?RBDelete@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAA_NPEAVCNode@12@@Z 0x140453b80 ; unique
// MS2-PIN: ?RBDeleteFixup@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x140453ee0 ; unique
// MS2-PIN: ?RBInsert@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEAAPEAVCNode@12@II@Z 0x140454540 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXI@Z 0x140454a40 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@QEAAXI@Z 0x140454ea0 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAXI@Z 0x140455300 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VCNpcShopGivePointContextBase@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopGivePointContextBase@@@@@3@@ATL@@QEAAXI@Z 0x140455760 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAAXI@Z 0x140455bc0 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAXI@Z 0x140456250 ; prop
// MS2-PIN: ?Rehash@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@QEAAXI@Z 0x140456480 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAXXZ 0x140456920 ; prop
// MS2-PIN: ?RemoveAll@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAXXZ 0x140456a30 ; prop
// MS2-PIN: ?RemoveAt@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140456e40 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140456f90 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140457080 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140457260 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140457440 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140457620 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1404578f0 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x1404579e0 ; prop
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@UUnk_FieldTimeSpan@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_FieldTimeSpan@@@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140457ad0 ; prop
// MS2-PIN: ?RemoveKey@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA_NK@Z 0x140457bc0 ; prop
// MS2-PIN: ?RemoveKey@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@QEAA_NI@Z 0x140457ca0 ; prop
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAA_NI@Z 0x140457d80 ; prop
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VFestivalContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VFestivalContext@@@@@3@@ATL@@QEAA_NI@Z 0x140457df0 ; prop
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAA_NI@Z 0x140457f40 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140458150 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@AEAAXPEAVCNode@12@0@Z 0x1404582d0 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140458450 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VFestivalContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VFestivalContext@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140458510 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x1404585d0 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140458750 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140458990 ; prop
// MS2-PIN: ?RemoveNode@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140458a50 ; prop
// MS2-PIN: ?RightRotate@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAPEAVCNode@12@PEAV312@@Z 0x140458bd0 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@Z 0x140459080 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VFestivalContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VFestivalContext@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VFestivalContext@@@@@Z 0x140459130 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@Z 0x1404591e0 ; prop
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@Z 0x140459340 ; prop
// MS2-PIN: ?SetNil@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAXPEAPEAVCNode@12@@Z 0x1404597a0 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXMMM_N@Z 0x140459880 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAXMMM_N@Z 0x140459930 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@QEAAXMMM_N@Z 0x1404599e0 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAAXMMM_N@Z 0x140459b40 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$MS2Ptr@VCNpcShopGivePointContextBase@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopGivePointContextBase@@@@@3@@ATL@@QEAAXMMM_N@Z 0x140459ca0 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@QEAAXMMM_N@Z 0x140459e00 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAXMMM_N@Z 0x14045a010 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@I_NV?$CElementTraits@I@ATL@@V?$CElementTraits@_N@2@@ATL@@QEAAXMMM_N@Z 0x14045a0c0 ; prop
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@UUnk_FieldTimeSpan@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_FieldTimeSpan@@@2@@ATL@@QEAAXMMM_N@Z 0x14045a170 ; prop
// MS2-PIN: ?Successor@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x14045a220 ; unique
// MS2-PIN: ?SwapNode@?$CRBTree@IIV?$CElementTraits@I@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x14045a3c0 ; unique
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@KHV?$CElementTraits@K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXXZ 0x14045a680 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEAAXXZ 0x14045a760 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IU?$pair@II@std@@V?$CElementTraits@I@ATL@@V?$CElementTraits@U?$pair@II@std@@@4@@ATL@@AEAAXXZ 0x14045a840 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@AEAAXXZ 0x14045aa00 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@IV?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@@3@@ATL@@AEAAXXZ 0x14045ad80 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@I_JV?$CElementTraits@I@ATL@@V?$CElementTraits@_J@2@@ATL@@AEAAXXZ 0x14045b020 ; prop
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@UUnk_FieldTimeSpan@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_FieldTimeSpan@@@2@@ATL@@AEAAXXZ 0x14045b1e0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GCNode@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@QEAAPEAXI@Z 0x14044a980
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x14044b220
// MS2-PIN: ?FreeNode@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x14044c330
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@QEBAIXZ 0x14044d310
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@QEAAXI@Z 0x140455990
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@IV?$MS2Ptr@VCNpcShopGivePointContextBase@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopGivePointContextBase@@@@@3@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140457530
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@QEAA_NI@Z 0x140457ed0
// MS2-PIN: ?RemoveNode@?$CAtlMap@IV?$MS2Ptr@VCNpcShopGivePointContextBase@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VCNpcShopGivePointContextBase@@@@@3@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140458690
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2Ptr@VUnk_DayItemContext@@@@@Z 0x140459290
// MS2-PIN: ??_GSpawnContext@CGameEventValueBattlePetSpawn@@UEAAPEAXI@Z 0x14044abc0
// MS2-PIN: ??_GRestrictionData@CGameEventValueItemTradeRestriction@@UEAAPEAXI@Z 0x14044ab80
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@QEAA_NI@Z 0x140457fb0
// MS2-PIN: ?RemoveKey@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@@3@@ATL@@QEAA_NI@Z 0x140458020
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x14044de30
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140451fc0
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140451db0
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@QEAAXI@Z 0x140455df0
// MS2-PIN: ?Rehash@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropContext@@@@@3@@ATL@@QEAAXI@Z 0x140456020
// MS2-PIN: ??_GIDIPEventContext@CGameEventValueIDIPEvent@@UEAAPEAXI@Z 0x14044ab40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

template class ATL::CAtlArray<MS2Ptr<FestivalContext> >;
template class ATL::CAtlArray<MS2Ptr<Unk_DayItemContext> >;
template class ATL::CAtlArray<MS2Ptr<Unk_FieldObjectDropContext> >;
template class ATL::CAtlArray<MS2Ptr<Unk_FieldObjectDropListContext> >;
template class ATL::CAtlArray<unsigned>;
template class ATL::CAtlList<MS2Ptr<Unk_DayItemContext> >;
template class ATL::CAtlList<MS2Ptr<Unk_FieldObjectDropContext> >;
template class ATL::CAtlList<MS2Ptr<Unk_FieldObjectDropListContext> >;
template class ATL::CAtlMap<CStringW, Unk_FieldTimeSpan, ATL::CStringElementTraits<CStringW> >;
template class ATL::CAtlMap<unsigned, bool>;
template class ATL::CAtlMap<unsigned, __int64>;
template class ATL::CAtlMap<unsigned long, int>;
template class ATL::CAtlMap<unsigned, MS2Ptr<CNpcShopGivePointContextBase> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<FestivalContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<Unk_DayItemContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<Unk_FieldObjectDropContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<Unk_FieldObjectDropListContext> >;
template class ATL::CAtlMap<unsigned, std::pair<unsigned, unsigned> >;
template class ATL::CAtlMap<unsigned, Unk_FieldIdListPtr>;
template class ATL::CAtlMap<unsigned, unsigned>;
template class ATL::CAtlMap<unsigned, unsigned short>;
template class ATL::CRBTree<unsigned, MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData> >;
template class ATL::CRBMap<unsigned, MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData> >;
template class ATL::CRBTree<unsigned, unsigned>;
template class ATL::CRBMultiMap<unsigned, unsigned>;

// The IDIPEventContext / RestrictionData / SpawnContext scalar deleting destructors (pinned above) come from the
// vftables, which only a ctor emits. Not exe code.
template <class T>
void Unk_GameEventValueConstruct(void* p)
{
    new (p) T;
}
template void Unk_GameEventValueConstruct<CGameEventValueBattlePetSpawn::SpawnContext>(void*);
template <class T>
void Unk_GameEventValueConstructTagged(void* p)
{
    new (p) T(Unk_VftableEmitTag());
}
template void Unk_GameEventValueConstructTagged<CGameEventValueItemTradeRestriction::RestrictionData>(void*);
template <class T>
void Unk_GameEventValueConstructTimed(void* p)
{
    new (p) T(0, CMsTime());
}
template void Unk_GameEventValueConstructTimed<CGameEventValueIDIPEvent::IDIPEventContext>(void*);
