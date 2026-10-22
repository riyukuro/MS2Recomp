// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Black market data classes (CBlackMarketItemOption,
// CDBBlackMarketProductInfo, CBlackMarketProduct, CBlackMarketSchCond), the client table CBlackMarketTable
// (Table/blackMarketTable.xml) and the item name / category lookup helpers around them.
// MS2-UNIT: ?\blackmarketitemoption.cpp
// MS2-RANGE: 0x1400b4430-0x1400b4660 .text$di
// MS2-RANGE: 0x1401bcbf0-0x1401c9a00 .text$mn
// MS2-RANGE: 0x142c9a140-0x142c9a1f8 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Allocate@?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@CAPEAV?$TPtredDummy@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@PEAX@Z 0x1401bf600 ; unique
// MS2-PIN: ??0?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@2@@ATL@@IEAA@_K@Z 0x1401bf7a0 ; unique
// MS2-PIN: ??0?$CRBTree@W4Unk_BmLanguage@@V?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@W4Unk_BmLanguage@@@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@@4@@ATL@@IEAA@_K@Z 0x1401bf800 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@PEAVCItem@@@Z 0x1401bf920 ; prop
// MS2-PIN: ??0?$TPtredDummy@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@QEAA@XZ 0x1401bf9a0 ; prop
// MS2-PIN: ??1?$TPtredDummy@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@UEAA@XZ 0x1401bfe10 ; prop
// MS2-PIN: ??4?$MS2Ptr@VCItem@@@@QEAAAEAV0@H@Z 0x1401bffb0 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCItem@@@@QEAAAEAV1@PEAVCItem@@@Z 0x1401bffe0 ; unique
// MS2-PIN: ?get@?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEBAPEAV?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@XZ 0x1401c00f0 ; unique
// MS2-PIN: ?Value@?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@CAPEAV?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@PEAV?$TPtredDummy@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@@Z 0x1401c0110 ; unique
// MS2-PIN: ??_G?$TPtredDummy@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@UEAAPEAXI@Z 0x1401c01f0 ; prop
// MS2-PIN: ??_GCBlackMarketItemOption@@UEAAPEAXI@Z 0x1401c0230 ; prop
// MS2-PIN: ??4?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@QEAAAEAV0@AEBUUnk_BmNewTag@@@Z 0x1401c03f0 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4Unk_BmLanguage@@@ATL@@SAHAEBW4Unk_BmLanguage@@0@Z 0x1401c0690 ; unique
// MS2-PIN: ??A?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@QEAAAEAI_K@Z 0x1401c0c80 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEAAAEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@1@_K@Z 0x1401c0cc0 ; unique
// MS2-PIN: ?GetAt@?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@PEAU__POSITION@@@Z 0x1401c0d00 ; unique
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x1401c0d70 ; unique
// MS2-PIN: ?GetNext@?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@AEAPEAU__POSITION@@@Z 0x1401c0dc0 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VCItem@@@@AEBAXXZ 0x1401c3540 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_BmItemData@@@@AEBAXPEAX@Z 0x1401c36b0 ; unique
// MS2-PIN: ?Allocate@?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@PEAX@Z 0x1401c4af0 ; unique
// MS2-PIN: ?Allocate@?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@PEAX@Z 0x1401c4b60 ; unique
// MS2-PIN: ?Allocate@?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@CAPEAV?$TPtredDummy@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@PEAX@Z 0x1401c4bd0 ; unique
// MS2-PIN: ??0?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@QEAA@XZ 0x1401c4c40 ; prop
// MS2-PIN: ??0?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@QEAA@I@Z 0x1401c4c80 ; unique
// MS2-PIN: ??0?$CAtlMap@IV?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@3@@ATL@@QEAA@IMMMI@Z 0x1401c4ce0 ; prop
// MS2-PIN: ??0?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@QEAA@IMMMI@Z 0x1401c4dd0 ; prop
// MS2-PIN: ??0?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@@3@@ATL@@QEAA@IMMMI@Z 0x1401c4ec0 ; prop
// MS2-PIN: ??0?$CValidData@VCBlackMarketTable@@@@QEAA@XZ 0x1401c4fb0 ; unique
// MS2-PIN: ??0?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@QEAA@PEAVStatInfo@CBlackMarketTable@@@Z 0x1401c5010 ; prop
// MS2-PIN: ??0?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@QEAA@$$QEAV0@@Z 0x1401c5040 ; unique
// MS2-PIN: ??0?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@QEAA@PEAVTabInfo@CBlackMarketTable@@@Z 0x1401c5070 ; prop
// MS2-PIN: ??0?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEAA@AEBUUnk_BmNewTag@@@Z 0x1401c5240 ; unique
// MS2-PIN: ??0?$TPtredDummy@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@QEAA@XZ 0x1401c5290 ; prop
// MS2-PIN: ??0?$TPtredDummy@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEAA@XZ 0x1401c52d0 ; prop
// MS2-PIN: ??0?$TPtredDummy@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEAA@XZ 0x1401c5310 ; prop
// MS2-PIN: ??0?$TSingleton@VCBlackMarketTable@@@@QEAA@XZ 0x1401c5360 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@3@@ATL@@IEAA@I@Z 0x1401c5480 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@@3@@ATL@@IEAA@I@Z 0x1401c54c0 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@@3@@ATL@@IEAA@I@Z 0x1401c5500 ; unique
// MS2-PIN: ??1?$TPtredDummy@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@UEAA@XZ 0x1401c57f0 ; prop
// MS2-PIN: ??1?$TPtredDummy@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@UEAA@XZ 0x1401c5820 ; prop
// MS2-PIN: ??1?$TPtredDummy@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@UEAA@XZ 0x1401c5850 ; prop
// MS2-PIN: ?Value@?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@CAPEAV?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@PEAV?$TPtredDummy@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@@Z 0x1401c5b10 ; unique
// MS2-PIN: ?Value@?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@CAPEAV?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@PEAV?$TPtredDummy@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@@Z 0x1401c5b50 ; unique
// MS2-PIN: ?Value@?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@CAPEAV?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@PEAV?$TPtredDummy@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@@Z 0x1401c5b90 ; unique
// MS2-PIN: ??_G?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@QEAAPEAXI@Z 0x1401c5c60 ; unique
// MS2-PIN: ??_G?$TPtredDummy@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@UEAAPEAXI@Z 0x1401c5ca0 ; prop
// MS2-PIN: ??_G?$TPtredDummy@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@UEAAPEAXI@Z 0x1401c5ce0 ; prop
// MS2-PIN: ??_G?$TPtredDummy@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@UEAAPEAXI@Z 0x1401c5d20 ; prop
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x1401c69d0 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@IV?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@3@@ATL@@QEBA_NIAEAV?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@Z 0x1401c7260 ; unique
// MS2-PIN: ?AddRef@?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@AEBAXXZ 0x1401c9430 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$CAtlArray@EV?$CElementTraits@E@ATL@@@ATL@@QEAA@XZ 0x1401bfbf0 ; w80 caller evidence (Unk_GuildArray dtor)
// MS2-PIN: ?GetCount@?$CAtlArray@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@2@@ATL@@QEBA_KXZ 0x1401c00e0 ; w80 caller evidence (ReadTabs)
// MS2-PIN: ??_7CBlackMarketTable@@6B?$TSingleton@VCBlackMarketTable@@@@@ 0x142cedee0 ; w80 ctor stores the vftable
// MS2-PIN: ??_7CBlackMarketTable@@6B?$CValidData@VCBlackMarketTable@@@@@ 0x142cedf00 ; w80 ctor stores the vftable
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@6B@ 0x142cedf30 ; w80 ctor stores the vftable
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@6B@ 0x142cedf20 ; w80 ctor stores the vftable
// MS2-PIN: ??_GCNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@2@@ATL@@QEAAPEAXI@Z 0x1401c0370 ; w80 caller evidence (FreeNode 0x1401c0ac0)
// MS2-PIN: ??_GCNode@?$CRBTree@W4Unk_BmLanguage@@V?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@V?$CElementTraits@W4Unk_BmLanguage@@@ATL@@V?$CElementTraits@V?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@@4@@ATL@@QEAAPEAXI@Z 0x1401c03b0 ; w80 caller evidence (FreeNode 0x1401c0b60)
// MS2-PIN: ??0?$CAtlArray@EV?$CElementTraits@E@ATL@@@ATL@@QEAA@XZ 0x1401bf670 ; w80 caller evidence (Unk_GuildArray ctor)
// MS2-PIN: ??0?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEAA@H@Z 0x1401c5270 ; w80 caller evidence (m_tabs(0) in table ctor)
// MS2-PIN: ??1?$MS2Ptr@VCItem@@@@QEAA@XZ 0x1401bfde0 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ?Reference@?$MS2Ptr@VCItem@@@@CAXPEAVCItem@@@Z 0x1401c3600 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCItem@@@@AEBAXPEAX@Z 0x1401c3680 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ?Release@?$MS2Ptr@VCItem@@@@AEAAXXZ 0x1401c3800 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCItem@@@@AEAAXPEAX@Z 0x1401c3930 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ??4?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEAAAEAV0@H@Z 0x1401c5ac0 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ?Release@?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@AEAAXXZ 0x1401c3780 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ?ReleaseImpl@?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@AEAAXPEAX@Z 0x1401c3890 ; w80 caller evidence (CItem ptr glue / m_tabs at +0x38)
// MS2-PIN: ??__Fs_strSortNames@@YAXXZ 0x142c9a180 ; w80 caller evidence
// MS2-PIN: ??__Fs_strSortNames2@@YAXXZ 0x142c9a1d0 ; w80 caller evidence
// MS2-PIN: ??__Es_strSortNames@@YAXXZ 0x1400b4490 ; w80 order of declaration
// MS2-PIN: ??__Es_strSortNames2@@YAXXZ 0x1400b4580 ; w80 order of declaration
// MS2-PIN: ?get@?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@QEBAPEAV?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@XZ 0x1401c0100 ; w80 caller evidence
// MS2-PIN: ??C?$Unk_BmBoxPtr@V?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@@@QEBAPEAV?$CRBMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@XZ 0x1401c0170 ; w80 caller evidence
// MS2-PIN: ??C?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEBAPEAV?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@XZ 0x1401c0160 ; w80 caller evidence
// MS2-PIN: ??D?$Unk_BmBoxPtr@V?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEBAAEAV?$CAtlList@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VTabInfo@CBlackMarketTable@@@@@ATL@@@ATL@@XZ 0x1401c0190 ; w80 caller evidence
// MS2-PIN: ?get@?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@QEBAPEAVStatInfo@CBlackMarketTable@@XZ 0x1401c5af0 ; w80 caller evidence
// MS2-PIN: ?get@?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEBAPEAV?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@XZ 0x1401c5b00 ; w80 caller evidence
// MS2-PIN: ??C?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@QEBAPEAVStatInfo@CBlackMarketTable@@XZ 0x1401c5bd0 ; w80 caller evidence
// MS2-PIN: ??C?$Unk_BmBoxPtr@V?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@@@QEBAPEAV?$CAtlArray@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@V?$CElementTraits@V?$Unk_BmPtr@VStatInfo@CBlackMarketTable@@@@@ATL@@@ATL@@XZ 0x1401c5be0 ; w80 caller evidence
// MS2-PIN: ??C?$Unk_BmBoxPtr@V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@@@QEBAPEAV?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@XZ 0x1401c5bf0 ; w80 caller evidence
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\blackmarketitemoption.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "blackmarketitemoption.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/commonfiles/localepath.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "hook/ms2hook.h"

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);              // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char* pszName);              // NextSiblingElement
};
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14016a5c0(const char* psz, int n);
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873220(Unk_140165cf0*, const char*, unsigned&);
int FUN_140873420(Unk_140165cf0*, const char*, CStringW&);
int FUN_1408736d0(Unk_140165cf0*, const char*, bool&);
int FUN_140873710(Unk_140165cf0*, const char*, int*);
int FUN_140873a50(Unk_140165cf0*, const char*, float*);
const char* FUN_14086f4b0(Unk_140165cf0*, const char*);
CString FUN_14015f710(Unk_140165cf0*, const char*, CString strDefault);   // string attribute with default
bool FUN_14028f710(Unk_140165cf0*);                                 // the element is usable
void FUN_140177e10(const CStringA& str, ATL::CAtlArray<unsigned>& rOut, const char* pszSep);
void FUN_14015f050(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);   // split into strings
enum Unk_BmLanguage { Unk_BmLanguage_None = 0 };
Unk_BmLanguage FUN_140651920(CString strCode);                                 // language code -> enum
__int64 FUN_140869440();                                            // server time
__int64 FUN_1418ff5a0(int nCurrency, __int64 nAmount, int nItemId); // random roll
int FUN_14082ee80(const CStringA& strName);                         // stat name -> id (-1 when none)
int FUN_14081d260(const CStringA& strName);                         // special option name -> id
CStringW FUN_140630e10(int nId);                                    // special option text
CStringW FUN_14082f000(int nId);                                    // stat text
unsigned FUN_140630d00(Unk_ItemEnchantData* pEnchant);
class Unk_140166410 { public: bool FUN_14036d4b0(const CStringW& strFeature); };
Unk_140166410* FUN_140166410();
void FUN_140159b70(long hr);                                        // AtlThrow
class Unk_1401a9d70 { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_1401a9d70* FUN_1401a9d70();

// The singletons the price helpers talk to (0x143aac4c8 / 0x143aac4d0, the locale one is TSingleton<CLocaleLanguage>).
class Unk_BmPriceMgr
{
public:
    long long FUN_140674f30(long long nPrice, int nRarity, unsigned nGroup, unsigned nEnchant);
    float FUN_140675150(int);
    void FUN_1406752e0(long long);
    void FUN_1406755d0();
    float FUN_140675470();
};
int FUN_140479560(void* pEventMgr);                                 // fixed black market fee rate (negative when none)
class Unk_SingletonObj;
extern Unk_SingletonObj* DAT_143aac4c8;
extern void* DAT_143aac4d0;
extern Unk_SingletonObj* DAT_143aac4d8;

class Unk_143aac520
{
public:
    Unk_143aac520(int);                                             // 0x1401cd100
};

typedef ATL::CRBMap<unsigned int, CStringW> Unk_BmNameMap;
typedef Unk_BmBoxPtr<Unk_BmNameMap> Unk_BmNameMapPtr;
typedef ATL::CRBMap<CStringA, CBlackMarketTable::TabPtr> Unk_BmTabIndex;
typedef ATL::CRBMap<Unk_BmLanguage, Unk_BmNameMapPtr> Unk_BmNameTable;

float FUN_1401bcd60();
Unk_BmPriceMgr* FUN_1401c0db0();
void* FUN_1401c0d90();
CBlackMarketTable* FUN_1401c06d0();
CBlackMarketTable* FUN_1401c0d80();
void FUN_1401bf440(CBlackMarketTable::TabList& rList, Unk_BmTabIndex* pIndex);
CLocaleLanguage* FUN_1401c0da0();
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszName, CStringW strDefault);
void FUN_1401c04d0();

// The statics of this unit.
static Unk_BmTabIndex s_mapTabByCategory(10);                       // 0x143aac468
static Unk_BmNameTable s_mapItemNames(10);                          // 0x143aac498
static CStringA s_strSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;                // 0x143aac420
static CStringA s_strSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static Unk_143aac520 s_unk520(0);

bool CBlackMarketUtil::s_bInit;
bool CBlackMarketTable::s_bInit;

// @0x1401bcbf0
long long FUN_1401bcbf0(CItem* pItem, long long nPrice)
{
    if (pItem == 0)
        return 0;
    if (FUN_140479560(FUN_1401c0d90()) >= 0)
    {
        float fRate = FUN_1401bcd60();
        return (long long)((float)nPrice * fRate);
    }
    MS2Ptr<Unk_BmItemData> data(reinterpret_cast<Unk_BmItemData*>(pItem->FUN_140527840()));
    if (data == 0)
        return 0;
    int nRarity = pItem->FUN_140526bd0();
    unsigned nGroup = data->m_nGroup;
    unsigned nEnchant = FUN_140630d00(pItem->FUN_1405278a0());
    long long nResult = FUN_1401c0db0()->FUN_140674f30(nPrice, nRarity, nGroup, nEnchant);
    return nResult;
}

// @0x1401bcd30
int FUN_1401bcd30()
{
    int nResult = (int)(FUN_1401bcd60() * 10000.0f);
    return nResult;
}

// @0x1401bcd60
float FUN_1401bcd60()
{
    int nRate = FUN_140479560(FUN_1401c0d90());
    if (nRate >= 0)
        return (float)nRate / 10000.0f;
    return FUN_1401c0db0()->FUN_140675150(1);
}

// @0x1401bcdb0
void FUN_1401bcdb0(long long n)
{
    FUN_1401c0db0()->FUN_1406752e0(n);
}

// @0x1401bcde0
void FUN_1401bcde0()
{
    FUN_1401c0db0()->FUN_1406755d0();
}

// @0x1401bce00
int FUN_1401bce00()
{
    return (int)FUN_1401c0db0()->FUN_140675470();
}

// @0x1401bce20
int FUN_1401bce20(unsigned int a, unsigned int b, int c)
{
    CStringA str;
    str.Format("%01d%01d%03d", a, b, c);
    int nResult = atoi(str);
    return nResult;
}

// @0x1401bceb0
int FUN_1401bceb0(unsigned int a, unsigned int b, int c)
{
    CStringA str;
    str.Format("%01d%01d%03d", a, b, c);
    int nResult = atoi(str);
    return nResult;
}

// @0x1401bd000
unsigned int FUN_1401bd000(unsigned int n)
{
    return n;
}

// @0x1401bd010
int FUN_1401bd010(int n)
{
    int nResult = 99999;
    if (n == 30000)
        return nResult;
    if (n % 100 == 0)
        nResult = n + 99;
    else
        nResult = n;
    return nResult;
}

// @0x1401bd070
unsigned int FUN_1401bd070(CStringA strCategory)
{
    if (strCategory.IsEmpty())
        return 99999;
    unsigned int nResult = 99999;
    CBlackMarketTable::TabPtr tab(0);
    if (s_mapTabByCategory.Lookup(strCategory, tab))
        nResult = tab->m_nId;
    return nResult;
}

// @0x1401bd120
unsigned int FUN_1401bd120(ATL::CAtlArray<unsigned int>* pIds)
{
    if (pIds->GetCount() == 0)
        return 0xfff;
    unsigned int nFlags = 0;
    for (unsigned int i = 0; i < pIds->GetCount(); i++)
    {
        unsigned int nId = (*pIds)[i];
        if (nId == 0)
            return 0xfff;
        switch (nId)
        {
        case 1:
            nFlags |= 1;
            break;
        case 10:
            nFlags |= 2;
            break;
        case 20:
            nFlags |= 4;
            break;
        case 30:
            nFlags |= 8;
            break;
        case 40:
            nFlags |= 0x10;
            break;
        case 50:
            nFlags |= 0x20;
            break;
        case 60:
            nFlags |= 0x40;
            break;
        case 70:
            nFlags |= 0x80;
            break;
        case 80:
            nFlags |= 0x100;
            break;
        case 90:
            nFlags |= 0x200;
            break;
        case 100:
            nFlags |= 0x400;
            break;
        case 110:
            nFlags |= 0x800;
            break;
        }
    }
    return nFlags;
}

// @0x1401bd340
unsigned int FUN_1401bd340(int n)
{
    unsigned int nResult = 0;
    switch (n)
    {
    case 0:
        nResult = 1;
        break;
    case 1:
        nResult = 2;
        break;
    case 2:
        nResult = 3;
        break;
    }
    return nResult;
}

// @0x1401bd3a0
// MS2-FUNCTIONAL: string temporaries placed differently
unsigned int FUN_1401bd3a0()
{
    FUN_1401c06d0();
    CBlackMarketTable::TabListPtr tabs = FUN_1401c0d80()->GetTabs();
    if (tabs.get() != 0)
    {
        if (!tabs->IsEmpty())
        {
            FUN_1401bf440(*tabs, &s_mapTabByCategory);
            return 1;
        }
    }
    return 0;
}

// @0x1401bd470
// MS2-FUNCTIONAL: loop temporaries and cleanup paths laid out differently
unsigned int LoadItemNames()
{
    ATL::CAtlArray<CString> languages;
    FUN_1401c0da0()->FUN_14064f310(languages);
    if (languages.GetCount() == 0)
        return 0;
    for (size_t i = 0; i < languages.GetCount(); i++)
    {
        CString strLanguage(languages[i]);
        CString strCopy(strLanguage);
        Unk_BmLanguage nLanguage = FUN_140651920(strCopy);
        CString strPath;
        strPath.Format("%s%s/%s/%s", "./Data/Xml/", "String", (const char*)strLanguage, "itemName.xml");
        Unk_BmNameMapPtr names(0);
        names = Unk_BmNewTag(0);
        s_mapItemNames.SetAt(nLanguage, names);
        TiXmlDocument doc;
        if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
            return 0;
        Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
        if (pRoot == 0)
            return 0;
        for (Unk_140165cf0* pItem = pRoot->FUN_140165cf0("key"); pItem != 0; pItem = pItem->FUN_140168650("key"))
        {
            if (FUN_14028f710(pItem))
            {
                unsigned int nId = 0;
                FUN_140873220(pItem, "id", nId);
                CStringW strName = FUN_1401bf530(pItem, "name", CStringW(L""));
                names.operator->()->SetAt(nId, strName);
            }
        }
    }
    return 1;
}

// @0x1401bd850
CStringW FUN_1401bd850(Unk_BmLanguage nLanguage, unsigned int nId)
{
    FUN_1401c04d0();
    CStringW strName;
    Unk_BmNameMapPtr names(0);
    s_mapItemNames.Lookup(nLanguage, names);
    if (names.get() != 0)
        names->Lookup(nId, strName);
    return strName;
}

// @0x1401bd920
CDBBlackMarketProductInfo::CDBBlackMarketProductInfo()
{
    Reset();
}

// @0x1401bd980
CDBBlackMarketProductInfo::~CDBBlackMarketProductInfo()
{
    Reset();
}

// @0x1401bd9e0
void CDBBlackMarketProductInfo::Reset()
{
    m_qw18 = 0;
    m_qw20 = 0;
    m_dw28 = 0;
    m_dw2c = 0;
    m_dw30 = 0;
    m_dw34 = 0;
    m_dw38 = 0;
    m_dw3c = 0;
    m_list.FUN_1401c0580();
    m_qw60 = 0;
    m_qw78 = 0;
    m_qw80 = 0;
    m_qw88 = 0;
    m_qw68 = 0;
    m_qw70 = 0;
    m_dw90 = 0;
    m_dw94 = 0;
}

MS2_REPLACE_METHOD(0x1401BD9E0, CDBBlackMarketProductInfo, Reset, 243, 0x9172EF63);

// @0x1401bdae0
CBlackMarketItemOption::CBlackMarketItemOption()
{
    Reset();
}

// @0x1401bdb30
CBlackMarketItemOption::~CBlackMarketItemOption()
{
    Reset();
}

// @0x1401bdb80
void CBlackMarketItemOption::Reset()
{
    m_qw18 = 0;
    m_qw20 = 0;
    m_dw28 = 0;
    m_dw2c = 0;
    m_dw30 = 0;
}

MS2_REPLACE_METHOD(0x1401BDB80, CBlackMarketItemOption, Reset, 68, 0x56C3D2AF);

// @0x1401bdbd0
CBlackMarketProduct::CBlackMarketProduct()
{
    Reset();
}

// @0x1401bdc30
CBlackMarketProduct::~CBlackMarketProduct()
{
    m_item = 0;
}

// @0x1401bdc90
void CBlackMarketProduct::Reset()
{
    m_qw18 = 0;
    m_qw20 = 0;
    m_qw28 = 0;
    m_nExpire = 0;
    m_item = 0;
    m_nCount = 0;
    m_nBought = 0;
    m_nUnitPrice = 0;
    m_nStateA = 0;
    m_nStateB = 0;
    m_qw58 = 0;
    m_n60 = 0;
    m_n88 = -1;
    m_n8c = 0;
    m_qw78 = 0;
}

MS2_REPLACE_METHOD(0x1401BDC90, CBlackMarketProduct, Reset, 220, 0x37342CAD);

// @0x1401bdd80
void CBlackMarketProduct::Write(COutputStream* pStream)
{
    if (m_item == 0)
        return;
    pStream->WriteInt64(m_qw18);
    pStream->WriteInt64(m_qw20);
    pStream->WriteInt64(m_qw28);
    pStream->WriteInt64(m_nExpire);
    pStream->WriteInt32(m_nCount);
    pStream->WriteInt32(m_nBought);
    pStream->WriteInt64(m_nUnitPrice);
    pStream->WriteUInt8((unsigned char)m_nStateB);
    pStream->WriteInt64(m_item->FUN_140526a50());
    pStream->WriteInt32(m_item->FUN_1405276c0());
    pStream->WriteUInt8((unsigned char)m_item->FUN_140526bd0());
    pStream->WriteInt64(m_qw68);
    m_item->FUN_140524ad0(*pStream);
}

MS2_REPLACE_METHOD(0x1401BDD80, CBlackMarketProduct, Write, 467, 0x4E40E47D);

// @0x1401bdf60
// MS2-FUNCTIONAL: stream temporaries placed differently
void CBlackMarketProduct::Read(CInPacket* pPacket)
{
    CInputStream& stream = *pPacket;
    m_qw18 = stream.ReadInt64();
    m_qw20 = stream.ReadInt64();
    m_qw28 = stream.ReadInt64();
    m_nExpire = stream.ReadInt64();
    m_nCount = stream.ReadInt32();
    m_nBought = stream.ReadInt32();
    m_nUnitPrice = stream.ReadInt64();
    m_nStateB = (unsigned char)stream.ReadUInt8();
    __int64 nUid = stream.ReadInt64();
    int nId = stream.ReadInt32();
    unsigned char nRank = stream.ReadUInt8();
    m_qw68 = stream.ReadInt64();
    m_item.AssignRaw(new CItem);
    if (m_item->FUN_140523c40(nId, nRank, 0))
    {
        m_item->FUN_140526a70(nUid);
        m_item->FUN_140524eb0(stream);
    }
}

// @0x1401be2f0
long long CBlackMarketProduct::TotalPrice()
{
    return (long long)m_nCount * m_nUnitPrice;
}

MS2_REPLACE_METHOD(0x1401BE2F0, CBlackMarketProduct, TotalPrice, 25, 0xA3844067);

// @0x1401be310
long long CBlackMarketProduct::PriceFor(int nCount)
{
    return (long long)nCount * m_nUnitPrice;
}

MS2_REPLACE_METHOD(0x1401BE310, CBlackMarketProduct, PriceFor, 25, 0x905B5C13);

// @0x1401be330
unsigned long long CBlackMarketProduct::GetState(bool bLike)
{
    if (bLike)
    {
        if (m_nStateB != 0)
            return 5;
    }
    else if (m_nStateA != 0)
    {
        return 4;
    }
    long long nNow = FUN_140869440();
    if (m_nExpire <= nNow)
        return 3;
    return 2;
}

MS2_REPLACE_METHOD(0x1401BE330, CBlackMarketProduct, GetState, 109, 0x825605D0);

// @0x1401be3b0
int CBlackMarketProduct::GetRemain()
{
    return m_nCount - m_nBought;
}

MS2_REPLACE_METHOD(0x1401BE3B0, CBlackMarketProduct, GetRemain, 24, 0x8E29E8C6);

// @0x1401be3d0
void CBlackMarketProduct::SetQw78(unsigned long long qw)
{
    m_qw78 = qw;
}

MS2_REPLACE_METHOD(0x1401BE3D0, CBlackMarketProduct, SetQw78, 25, 0x6C790EDB);

// @0x1401be3f0
// MS2-FUNCTIONAL: division operands and frame size differ
unsigned int CBlackMarketProduct::RollCount()
{
    unsigned int nResult = 1;
    long long nRoll = FUN_1418ff5a0(1, 0, 0);
    long long nUnit = PriceFor(1);
    if (0 < nUnit)
    {
        if (nRoll / nUnit < (long long)GetRemain())
            nResult = (unsigned int)(nRoll / nUnit);
        else
            nResult = GetRemain();
    }
    return nResult;
}

// @0x1401be4a0
CBlackMarketSchCond::CBlackMarketSchCond()
{
    Reset();
}

// @0x1401be500
CBlackMarketSchCond::CBlackMarketSchCond(CInPacket* pPacket)
{
    Read(pPacket);
}

// @0x1401be570
CBlackMarketSchCond::~CBlackMarketSchCond()
{
    Reset();
}

// @0x1401be5d0
void CBlackMarketSchCond::Reset()
{
    m_dw18 = 0;
    m_dw1c = 0;
    m_dw20 = 0;
    m_dw24 = 0;
    m_dw28 = 0;
    m_dw2c = 0;
    m_dw30 = 0;
    m_dw34 = 15;
    m_dw38 = 0;
    m_dw3c = 3;
    m_strName.Empty();
    m_dw48 = 0;
    m_dw54 = 0;
    m_dw58 = 0;
    m_dw50 = 0;
    m_dw4c = 0;
    m_dw5c = 0;
    m_dw60 = 1;
    for (int i = 0; i < 3; i++)
    {
        m_aMin[i] = 0;
        m_aMax[i] = 0;
    }
}

MS2_REPLACE_METHOD(0x1401BE5D0, CBlackMarketSchCond, Reset, 301, 0x34B611F1);

// @0x1401be710
void CBlackMarketSchCond::CopyFrom(const CBlackMarketSchCond* pOther)
{
    Reset();
    if (pOther == 0)
        return;
    m_dw18 = pOther->m_dw18;
    m_dw1c = pOther->m_dw1c;
    m_dw20 = pOther->m_dw20;
    m_dw24 = pOther->m_dw24;
    m_dw28 = pOther->m_dw28;
    m_dw2c = pOther->m_dw2c;
    m_dw30 = pOther->m_dw30;
    m_dw34 = pOther->m_dw34;
    m_dw38 = pOther->m_dw38;
    m_dw3c = pOther->m_dw3c;
    m_strName = pOther->m_strName;
    m_dw48 = pOther->m_dw48;
    m_dw54 = pOther->m_dw54;
    m_dw58 = pOther->m_dw58;
    m_dw50 = pOther->m_dw50;
    m_dw4c = pOther->m_dw4c;
    m_dw5c = pOther->m_dw5c;
    m_dw60 = pOther->m_dw60;
    for (int i = 0; i < 3; i++)
    {
        m_aMin[i] = pOther->m_aMin[i];
        m_aMax[i] = pOther->m_aMax[i];
    }
}

MS2_REPLACE_METHOD(0x1401BE710, CBlackMarketSchCond, CopyFrom, 428, 0xCEC8FD9F);

// @0x1401be8d0
void CBlackMarketSchCond::Write(COutputStream* pStream)
{
    WriteStream(pStream);
}

MS2_REPLACE_METHOD(0x1401BE8D0, CBlackMarketSchCond, Write, 34, 0x04FC75E7);

// @0x1401be900
void CBlackMarketSchCond::Read(CInPacket* pPacket)
{
    ReadStream(pPacket);
}

MS2_REPLACE_METHOD(0x1401BE900, CBlackMarketSchCond, Read, 67, 0x3F2CE6F7);

// @0x1401be950
void CBlackMarketSchCond::WriteStream(COutputStream* pStream)
{
    pStream->WriteInt32(m_dw18);
    pStream->WriteInt32(m_dw1c);
    pStream->WriteInt32(m_dw20);
    pStream->WriteInt32(m_dw24);
    pStream->WriteInt32(m_dw28);
    pStream->WriteInt32(m_dw2c);
    pStream->WriteInt32(m_dw30);
    pStream->WriteInt32(m_dw34);
    pStream->WriteUInt8((unsigned char)m_dw38);
    pStream->WriteUInt8((unsigned char)m_dw3c);
    pStream->WriteUnicodeString(m_strName);
    pStream->WriteInt32(m_dw48);
    pStream->WriteUInt8((unsigned char)m_dw54);
    pStream->WriteUInt8((unsigned char)m_dw58);
    pStream->WriteInt32(m_dw50);
    pStream->WriteInt32(m_dw4c);
    pStream->WriteUInt8((unsigned char)m_dw5c);
    pStream->WriteUInt8((unsigned char)m_dw60);
    for (int i = 0; i < 3; i++)
    {
        pStream->WriteInt32(m_aMin[i]);
        pStream->WriteInt32(m_aMax[i]);
    }
}

MS2_REPLACE_METHOD(0x1401BE950, CBlackMarketSchCond, WriteStream, 580, 0xA49ACEC9);

// @0x1401beba0
void CBlackMarketSchCond::ReadStream(CInputStream* pStream)
{
    m_dw18 = pStream->ReadInt32();
    m_dw1c = pStream->ReadInt32();
    m_dw20 = pStream->ReadInt32();
    m_dw24 = pStream->ReadInt32();
    m_dw28 = pStream->ReadInt32();
    m_dw2c = pStream->ReadInt32();
    m_dw30 = pStream->ReadInt32();
    m_dw34 = pStream->ReadInt32();
    m_dw38 = pStream->ReadUInt8();
    m_dw3c = pStream->ReadUInt8();
    m_strName = pStream->ReadUnicodeString();
    m_dw48 = pStream->ReadInt32();
    m_dw54 = pStream->ReadUInt8();
    m_dw58 = pStream->ReadUInt8();
    m_dw50 = pStream->ReadInt32();
    m_dw4c = pStream->ReadInt32();
    m_dw5c = pStream->ReadUInt8();
    m_dw60 = pStream->ReadUInt8();
    for (int i = 0; i < 3; i++)
    {
        m_aMin[i] = pStream->ReadInt32();
        m_aMax[i] = pStream->ReadInt32();
    }
}

MS2_REPLACE_METHOD(0x1401BEBA0, CBlackMarketSchCond, ReadStream, 614, 0x076C94BB);

// @0x1401bee10
int CBlackMarketSchCond::GetLevelBand()
{
    if (m_dw48 == 0)
        return -1;
    int nIdx = m_dw48 - 1;
    int nBand = nIdx / 10;
    return nBand;
}

MS2_REPLACE_METHOD(0x1401BEE10, CBlackMarketSchCond, GetLevelBand, 64, 0x4A209CE5);

// @0x1401bee60
int CBlackMarketSchCond::GetBandMin()
{
    int nBand = GetLevelBand();
    if (nBand == -1)
        return 0;
    int nSpan = 70;
    int nResult = nBand * nSpan + 1;
    return nResult;
}

MS2_REPLACE_METHOD(0x1401BEE60, CBlackMarketSchCond, GetBandMin, 66, 0xFCBDC0EE);

// @0x1401beeb0
int CBlackMarketSchCond::GetBandMax()
{
    int nBand = GetLevelBand();
    if (nBand == -1)
        return 0;
    int nSpan = 70;
    int nResult = (nBand + 1) * nSpan;
    return nResult;
}

MS2_REPLACE_METHOD(0x1401BEEB0, CBlackMarketSchCond, GetBandMax, 66, 0x9A64A030);

// @0x1401bef00
int CBlackMarketSchCond::GetLimit()
{
    if (m_dw48 == 0)
        return -1;
    int nIdx = m_dw48 - 1;
    int nStep = nIdx / 50;
    int nSpan = 350;
    int nResult = (nStep + 1) * nSpan;
    return nResult;
}

MS2_REPLACE_METHOD(0x1401BEF00, CBlackMarketSchCond, GetLimit, 87, 0x804CDAFB);

// @0x1401bef60
int CBlackMarketSchCond::IsEqual(const CBlackMarketSchCond* pOther)
{
    if (pOther == 0)
        return 0;
    if (pOther->m_dw18 != m_dw18)
        return 0;
    if (pOther->m_dw1c != m_dw1c)
        return 0;
    if (pOther->m_dw20 != m_dw20)
        return 0;
    if (pOther->m_dw24 != m_dw24)
        return 0;
    if (pOther->m_dw28 != m_dw28)
        return 0;
    if (pOther->m_dw2c != m_dw2c)
        return 0;
    if (pOther->m_dw30 != m_dw30)
        return 0;
    if (pOther->m_dw34 != m_dw34)
        return 0;
    if (pOther->m_dw38 != m_dw38)
        return 0;
    if (pOther->m_dw3c != m_dw3c)
        return 0;
    if (pOther->m_strName != m_strName)
        return 0;
    if (pOther->m_dw54 != m_dw54)
        return 0;
    if (pOther->m_dw58 != m_dw58)
        return 0;
    if (pOther->m_dw50 != m_dw50)
        return 0;
    if (pOther->m_dw4c != m_dw4c)
        return 0;
    if (const_cast<CBlackMarketSchCond*>(pOther)->GetLimit() != GetLimit())
        return 0;
    if (pOther->m_dw5c != m_dw5c)
        return 0;
    if (pOther->m_dw60 != m_dw60)
        return 0;
    for (int i = 0; i < 3; i++)
    {
        if (pOther->m_aMin[i] != m_aMin[i])
            return 0;
        if (pOther->m_aMax[i] != m_aMax[i])
            return 0;
    }
    return 1;
}

MS2_REPLACE_METHOD(0x1401BEF60, CBlackMarketSchCond, IsEqual, 611, 0xB2C3605C);

// @0x1401bf1d0
int CBlackMarketSchCond::Compact()
{
    if (m_dw5c == 0)
        return 1;
    unsigned int aMin[3];
    unsigned int aMax[3];
    for (int i = 0; i < 3; i++)
    {
        aMin[i] = 0;
        aMax[i] = 0;
    }
    int nUsed = 0;
    for (int j = 0; j < 3; j++)
    {
        if (!(m_aMin[j] != 0 || m_aMax[j] != 0))
            continue;
        aMin[nUsed] = m_aMin[j];
        aMax[nUsed] = m_aMax[j];
        nUsed++;
    }
    if (nUsed == 0)
        return 0;
    for (int k = 0; k < 3; k++)
    {
        if (k < nUsed)
        {
            m_aMin[k] = aMin[k];
            m_aMax[k] = aMax[k];
        }
        else
        {
            m_aMin[k] = 0;
            m_aMax[k] = 0;
        }
    }
    return 1;
}

// @0x1401bf350
void FUN_1401bf350(Unk_BmTabIndex* pIndex, CBlackMarketTable::TabPtr tab)
{
    ATL::CAtlArray<CString> categories;
    FUN_14015f050(tab->m_strCategory, categories, ",");
    for (unsigned int i = 0; i < categories.GetCount(); i++)
    {
        CStringA strCategory(categories[i]);
        if (pIndex->Lookup(strCategory) == 0)
            pIndex->SetAt(strCategory, tab);
    }
}

// @0x1401bf440
// MS2-FUNCTIONAL: list/iterator temporaries placed differently
void FUN_1401bf440(CBlackMarketTable::TabList& rList, Unk_BmTabIndex* pIndex)
{
    CBlackMarketTable::TabList* pList = &rList;
    for (POSITION pos = pList->GetHeadPosition(); pos != 0; pList->GetNext(pos))
    {
        CBlackMarketTable::TabPtr tab = pList->GetAt(pos);
        if (tab.get() != 0)
        {
            if (!tab->m_children.IsEmpty())
                FUN_1401bf440(tab->m_children, pIndex);
            else
                FUN_1401bf350(pIndex, tab);
        }
    }
}

// @0x1401bf530
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszName, CStringW strDefault)
{
    CStringW strValue;
    if (FUN_140873420(pElem, pszName, strValue) != 0)
    {
        return strDefault;
    }
    return strValue;
}

// @0x1401bfbd0
// MS2-FUNCTIONAL: member construction goes through a cast array view, call/EH layout differs
Unk_GuildArray::Unk_GuildArray()
{
    new (reinterpret_cast<ATL::CAtlArray<unsigned char>*>(this)) ATL::CAtlArray<unsigned char>();
}

// @0x1401bff10
// MS2-FUNCTIONAL: member destruction goes through a cast array view, call/EH layout differs
Unk_GuildArray::~Unk_GuildArray()
{
    reinterpret_cast<ATL::CAtlArray<unsigned char>*>(this)->~CAtlArray();
}

// @0x1401c0580
void Unk_GuildArray::FUN_1401c0580()
{
    reinterpret_cast<ATL::CAtlArray<unsigned char>*>(this)->RemoveAll();
}

// @0x1401c04d0
void CBlackMarketUtil::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CBlackMarketUtil).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1401c06d0
CBlackMarketTable* FUN_1401c06d0()
{
    return TSingleton<CBlackMarketTable>::s_instance != 0 ? FUN_1401c0d80() : new CBlackMarketTable;
}

// @0x1401c0d80
CBlackMarketTable* FUN_1401c0d80()
{
    return static_cast<CBlackMarketTable*>(TSingleton<CBlackMarketTable>::s_instance);
}

// @0x1401c0d90
void* FUN_1401c0d90()
{
    return DAT_143aac4d0;
}

// @0x1401c0da0
CLocaleLanguage* FUN_1401c0da0()
{
    return static_cast<CLocaleLanguage*>(TSingleton<CLocaleLanguage>::s_instance);
}

// @0x1401c0db0
Unk_BmPriceMgr* FUN_1401c0db0()
{
    return reinterpret_cast<Unk_BmPriceMgr*>(DAT_143aac4c8);
}

// @0x1401c3aa0
// MS2-FUNCTIONAL: member init order and float constants differ in the ctor
CBlackMarketTable::CBlackMarketTable()
    : m_tabs(0), m_tabById(17, 0.75f, 0.25f, 2.25f, 10), m_options(17, 0.75f, 0.25f, 2.25f, 10),
      m_statTables(17, 0.75f, 0.25f, 2.25f, 10)
{
    FUN_1401d1160(FUN_14071a5b0(CString("Table"), CString("blackMarketTable.xml")));
    Load();
}

// @0x1401c3cc0
CBlackMarketTable::~CBlackMarketTable()
{
    Clear();
}

// @0x1401c3da0
// MS2-FUNCTIONAL: loop temporaries and cleanup paths laid out differently
void CBlackMarketTable::Load()
{
    Clear();
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, *FUN_1401d1140(), 0, true, false))
    {
        Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
        if (pRoot != 0)
        {
            for (Unk_140165cf0* pCat = pRoot->FUN_140165cf0("category"); pCat != 0; pCat = pCat->FUN_140168650("category"))
            {
                TabListPtr tabs((Unk_BmNewTag(0)));
                if (tabs.get() != 0)
                {
                    ReadTabs(pCat, &*tabs, &m_tabById, 0);
                    m_tabs = tabs;
                }
            }
            for (Unk_140165cf0* pTable = pRoot->FUN_140165cf0("stat_table"); pTable != 0; pTable = pTable->FUN_140168650("stat_table"))
            {
                unsigned int nId = 0;
                FUN_140873220(pTable, "id", nId);
                StatArrayPtr stats((Unk_BmNewTag(0)));
                if (stats.get() != 0)
                {
                    for (Unk_140165cf0* pStat = pTable->FUN_140165cf0("stat"); pStat != 0; pStat = pStat->FUN_140168650("stat"))
                    {
                        StatPtr stat(new StatInfo());
                        if (stat.get() != 0)
                        {
                            CStringA strName(FUN_14086f4b0(pStat, "name"));
                            CStringW strText;
                            FUN_140873710(pStat, "percent", &stat->m_nPercent);
                            FUN_140873a50(pStat, "default", &stat->m_fDefault);
                            int nStat = FUN_14082ee80(strName);
                            if (nStat == -1)
                            {
                                nStat = FUN_14081d260(strName);
                                stat->m_nKind = 1;
                                strText = FUN_140630e10(nStat);
                            }
                            else
                            {
                                stat->m_nKind = 0;
                                strText = FUN_14082f000(nStat);
                            }
                            stat->m_nId = nStat;
                            stat->m_strName = strText;
                            stats->Add(stat);
                        }
                    }
                }
                m_statTables.SetAt(nId, stats);
            }
            for (Unk_140165cf0* pOption = pRoot->FUN_140165cf0("option"); pOption != 0; pOption = pOption->FUN_140168650("option"))
            {
                unsigned int nId = 0;
                FUN_140873220(pOption, "id", nId);
                IdArrayPtr ids((Unk_BmNewTag(0)));
                CStringA strTables(FUN_14086f4b0(pOption, "stat_tables"));
                FUN_140177e10(strTables, *ids.operator->(), ",");
                m_options.SetAt(nId, ids);
            }
        }
    }
    SetInit(true);
}

// @0x1401c4390
void CBlackMarketTable::Clear()
{
    m_tabs = 0;
    m_options.RemoveAll();
    m_statTables.RemoveAll();
}

MS2_REPLACE_METHOD(0x1401C4390, CBlackMarketTable, Clear, 69, 0xEF329932);

// @0x1401c43e0
CBlackMarketTable::TabListPtr CBlackMarketTable::GetTabs()
{
    CheckInit();
    return m_tabs;
}

// @0x1401c4430
CBlackMarketTable::IdArrayPtr CBlackMarketTable::GetOptionStats(unsigned int nOption)
{
    CheckInit();
    IdArrayPtr ids;
    if (m_options.Lookup(nOption, ids))
        return ids;
    return IdArrayPtr(0);
}

// @0x1401c44f0
CBlackMarketTable::StatArrayPtr CBlackMarketTable::GetStatTable(unsigned int nId)
{
    CheckInit();
    StatArrayPtr stats;
    if (m_statTables.Lookup(nId, stats))
        return stats;
    return StatArrayPtr(0);
}

// @0x1401c45b0
// MS2-FUNCTIONAL: smart pointer temporaries placed differently
CBlackMarketTable::TabPtr CBlackMarketTable::GetTab(unsigned int nId)
{
    CheckInit();
    if (!m_tabById.IsEmpty())
    {
        TabPtr tab(0);
        m_tabById.Lookup(nId, tab);
        return tab;
    }
    return TabPtr(0);
}

// @0x1401c4670
// MS2-FUNCTIONAL: loop temporaries and cleanup paths laid out differently
void CBlackMarketTable::ReadTabs(Unk_140165cf0* pElem, TabList* pOut, TabMap* pById, CStringA* pCategories)
{
    for (Unk_140165cf0* pTab = pElem->FUN_140165cf0("tab"); pTab != 0; pTab = pTab->FUN_140168650("tab"))
    {
        int nName = 0;
        FUN_1408731e0(pTab, "name", nName);
        CStringW strName = FUN_1401a9d70()->FUN_141811980(13, nName);
        if (nName < 1)
            continue;
        TabPtr tab(new TabInfo);
        if (tab.get() == 0)
            continue;
        tab->m_strName = strName;
        CStringW strFeature = FUN_1401bf530(pTab, "feature", CStringW(L""));
        if (!FUN_140166410()->FUN_14036d4b0(strFeature))
            continue;
        tab->m_strCategory = FUN_14015f710(pTab, "category", CString(""));
        FUN_1408731e0(pTab, "priority", tab->m_nPriority);
        FUN_1408731e0(pTab, "id", tab->m_nId);
        FUN_1408731e0(pTab, "option_id", tab->m_nOptionId);
        FUN_1408736d0(pTab, "auto_complete_name", tab->m_bAutoCompleteName);
        FUN_1408736d0(pTab, "showIncludeLowTab", tab->m_bShowIncludeLowTab);
        pById->SetAt(tab->m_nId, tab);
        ReadTabs(pTab, &tab->m_children, pById, &tab->m_strCategory);
        if (pCategories != 0)
        {
            if (!tab->m_strCategory.IsEmpty())
            {
                CStringA strJoin(pCategories->IsEmpty() ? "" : ",");
                strJoin += tab->m_strCategory;
                pCategories->Append(strJoin);
            }
        }
        pOut->AddTail(tab);
    }
}

// @0x1401c5540
// MS2-FUNCTIONAL: frame size and EH state setup differ
CBlackMarketTable::StatInfo::StatInfo()
    : m_nId(-1), m_strName(L""), m_nPercent(0), m_fDefault(0)
{
}

// @0x1401c5980
// MS2-FUNCTIONAL: member destruction order/EH differs
CBlackMarketTable::StatInfo::~StatInfo()
{
}

// @0x1401c55b0
// MS2-FUNCTIONAL: frame size and EH state setup differ
CBlackMarketTable::TabInfo::TabInfo()
    : m_strName(L""), m_nPriority(0), m_nId(-1), m_nOptionId(-1), m_bAutoCompleteName(false),
      m_bShowIncludeLowTab(false), m_children(10)
{
}

// @0x1401c59b0
// MS2-FUNCTIONAL: member destruction order/EH differs
CBlackMarketTable::TabInfo::~TabInfo()
{
}

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
// @0x1401c3980
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: source spelling differs
static __inline errno_t ms2_bm_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnBmMemcpyS)(void*, size_t, const void*, size_t) = &ms2_bm_memcpy_s;

// @0x1401c60f0
void CBlackMarketTable::CheckInit()
{
    if (!s_bInit)
    {
        CStringA msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CBlackMarketTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x1401c9180
void CBlackMarketTable::SetInit(bool b)
{
    s_bInit = b;
}
