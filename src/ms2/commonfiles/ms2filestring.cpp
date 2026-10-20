// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pack archive reader: CPackFile opens <name>.m2h (magic,
// stream header, the deflated "index,[archive,]name" file list and file table), keeps one entry header per file and
// reads/inflates entries out of the .m2d data files; CMS2FileString is the parsed file list plus the .m2d handles.
// Version classes are RTTI names; CPackFile/CMS2FileString and every method name are invented (the TU name is the
// _wassert string of Parse). The client's filesystem.cpp drives these through its own opaque Unk_FileArchive stand-ins.
// MS2-UNIT: commonfiles\ms2filestring.cpp
// MS2-RANGE: 0x1406af1a0-0x1406c3230 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHAEAPEAX$0A@@?$pair@HPEAX@std@@QEAA@AEAHAEAPEAX@Z 0x1406b2dd0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBIPEAX@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIPEAX@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIPEAX@std@@PEAX@std@@@1@QEAU?$pair@$$CBIPEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x1406b5450 ; unique
// MS2-PIN: ??$make_pair@AEAHAEAPEAX@std@@YA?AU?$pair@HPEAX@0@AEAHAEAPEAX@Z 0x1406b57d0 ; unique
// MS2-PIN: ??0?$PackFileHeader@VCPackFileHeaderVer1@@@@QEAA@PEBX@Z 0x1406b5860 ; prop
// MS2-PIN: ??0?$PackFileHeader@VCPackFileHeaderVer1@@@@QEAA@XZ 0x1406b58d0 ; prop
// MS2-PIN: ??0?$PackFileHeader@VCPackFileHeaderVer2@@@@QEAA@PEBX@Z 0x1406b5930 ; prop
// MS2-PIN: ??0?$PackFileHeader@VCPackFileHeaderVer2@@@@QEAA@XZ 0x1406b59a0 ; prop
// MS2-PIN: ??0?$PackFileHeader@VCPackFileHeaderVer3@@@@QEAA@PEBX@Z 0x1406b5a00 ; prop
// MS2-PIN: ??0?$PackFileHeader@VCPackFileHeaderVer3@@@@QEAA@XZ 0x1406b5a70 ; prop
// MS2-PIN: ??0?$PackFileStream@VCPackStreamVer1@@@@QEAA@XZ 0x1406b5ad0 ; prop
// MS2-PIN: ??0?$PackFileStream@VCPackStreamVer2@@@@QEAA@XZ 0x1406b5b30 ; prop
// MS2-PIN: ??0?$PackFileStream@VCPackStreamVer3@@@@QEAA@XZ 0x1406b5b90 ; prop
// MS2-PIN: ??1?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAA@XZ 0x1406b66a0 ; prop
// MS2-PIN: ??1?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAA@XZ 0x1406b66d0 ; prop
// MS2-PIN: ??1?$PackFileStream@VCPackStreamVer2@@@@UEAA@XZ 0x1406b6730 ; prop
// MS2-PIN: ??1?$PackFileStream@VCPackStreamVer3@@@@UEAA@XZ 0x1406b6760 ; prop
// MS2-PIN: ??1CPackFileHeaderVer2@@UEAA@XZ 0x1406b6a30 ; prop
// MS2-PIN: ??1CPackFileHeaderVer3@@UEAA@XZ 0x1406b6a50 ; prop
// MS2-PIN: ??1CPackStreamVer2@@UEAA@XZ 0x1406b6ab0 ; prop
// MS2-PIN: ??1CPackStreamVer3@@UEAA@XZ 0x1406b6ad0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAX@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIPEAX@1@XZ 0x1406b6d90 ; unique
// MS2-PIN: ??_E?$PackFileHeader@VCPackFileHeaderVer1@@@@W7EAAPEAXI@Z 0x1406b73d4 ; unique
// MS2-PIN: ??_E?$PackFileHeader@VCPackFileHeaderVer2@@@@W7EAAPEAXI@Z 0x1406b73e0 ; unique
// MS2-PIN: ??_E?$PackFileHeader@VCPackFileHeaderVer3@@@@W7EAAPEAXI@Z 0x1406b73ec ; unique
// MS2-PIN: ??_E?$PackFileStream@VCPackStreamVer1@@@@WBA@EAAPEAXI@Z 0x1406b73f8 ; unique
// MS2-PIN: ??_E?$PackFileStream@VCPackStreamVer2@@@@WBA@EAAPEAXI@Z 0x1406b7404 ; unique
// MS2-PIN: ??_E?$PackFileStream@VCPackStreamVer3@@@@WBA@EAAPEAXI@Z 0x1406b7410 ; unique
// MS2-PIN: ??_G?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAPEAXI@Z 0x1406b7460 ; prop
// MS2-PIN: ??_G?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAPEAXI@Z 0x1406b74a0 ; prop
// MS2-PIN: ??_G?$PackFileStream@VCPackStreamVer2@@@@UEAAPEAXI@Z 0x1406b7520 ; prop
// MS2-PIN: ??_G?$PackFileStream@VCPackStreamVer3@@@@UEAAPEAXI@Z 0x1406b7560 ; prop
// MS2-PIN: ??_GCPackFileHeaderVer2@@UEAAPEAXI@Z 0x1406b7660 ; prop
// MS2-PIN: ??_GCPackStreamVer2@@UEAAPEAXI@Z 0x1406b7760 ; prop
// MS2-PIN: ??_GCPackStreamVer3@@UEAAPEAXI@Z 0x1406b77a0 ; prop
// MS2-PIN: ?GetTableCompressedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAA_KXZ 0x1406b7820 ; unique
// MS2-PIN: ?GetTableCompressedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAA_KXZ 0x1406b7830 ; unique
// MS2-PIN: ?GetTableCompressedSize@?$PackFileStream@VCPackStreamVer3@@@@UEAA_KXZ 0x1406b7840 ; unique
// MS2-PIN: ?GetListCompressedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAA_KXZ 0x1406b7850 ; unique
// MS2-PIN: ?GetListCompressedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAA_KXZ 0x1406b7860 ; unique
// MS2-PIN: ?GetListCompressedSize@?$PackFileStream@VCPackStreamVer3@@@@UEAA_KXZ 0x1406b7870 ; unique
// MS2-PIN: ?GetCompressedSize@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAA_KXZ 0x1406b7880 ; unique
// MS2-PIN: ?GetCompressedSize@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAA_KXZ 0x1406b7890 ; unique
// MS2-PIN: ?GetCompressedSize@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAA_KXZ 0x1406b78a0 ; unique
// MS2-PIN: ?GetTableEncodedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAA_KXZ 0x1406b78b0 ; unique
// MS2-PIN: ?GetTableEncodedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAA_KXZ 0x1406b78c0 ; unique
// MS2-PIN: ?GetTableEncodedSize@?$PackFileStream@VCPackStreamVer3@@@@UEAA_KXZ 0x1406b78d0 ; unique
// MS2-PIN: ?GetEncodedSize@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAIXZ 0x1406b78e0 ; unique
// MS2-PIN: ?GetEncodedSize@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAIXZ 0x1406b78f0 ; unique
// MS2-PIN: ?GetEncodedSize@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAIXZ 0x1406b7900 ; unique
// MS2-PIN: ?GetListEncodedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAA_KXZ 0x1406b7910 ; unique
// MS2-PIN: ?GetListEncodedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAA_KXZ 0x1406b7920 ; unique
// MS2-PIN: ?GetListEncodedSize@?$PackFileStream@VCPackStreamVer3@@@@UEAA_KXZ 0x1406b7930 ; unique
// MS2-PIN: ?GetFileCount@?$PackFileStream@VCPackStreamVer1@@@@UEAAIXZ 0x1406b7940 ; unique
// MS2-PIN: ?GetFileCount@?$PackFileStream@VCPackStreamVer2@@@@UEAAIXZ 0x1406b7950 ; unique
// MS2-PIN: ?GetFileCount@?$PackFileStream@VCPackStreamVer3@@@@UEAAIXZ 0x1406b7960 ; unique
// MS2-PIN: ?GetHeaderData@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAPEAXXZ 0x1406b7970 ; unique
// MS2-PIN: ?GetHeaderData@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAPEAXXZ 0x1406b7980 ; unique
// MS2-PIN: ?GetHeaderData@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAPEAXXZ 0x1406b7990 ; unique
// MS2-PIN: ?GetTableSize@?$PackFileStream@VCPackStreamVer1@@@@UEAA_KXZ 0x1406b79a0 ; unique
// MS2-PIN: ?GetTableSize@?$PackFileStream@VCPackStreamVer2@@@@UEAA_KXZ 0x1406b79b0 ; unique
// MS2-PIN: ?GetTableSize@?$PackFileStream@VCPackStreamVer3@@@@UEAA_KXZ 0x1406b79c0 ; unique
// MS2-PIN: ?GetOffset@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAA_KXZ 0x1406b79d0 ; unique
// MS2-PIN: ?GetOffset@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAA_KXZ 0x1406b79e0 ; unique
// MS2-PIN: ?GetOffset@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAA_KXZ 0x1406b79f0 ; unique
// MS2-PIN: ?GetEncodeFlags@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAA?AUCPackEncodeFlags@@XZ 0x1406b7a00 ; unique
// MS2-PIN: ?GetEncodeFlags@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAA?AUCPackEncodeFlags@@XZ 0x1406b7a20 ; unique
// MS2-PIN: ?GetEncodeFlags@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAA?AUCPackEncodeFlags@@XZ 0x1406b7a40 ; unique
// MS2-PIN: ?GetHeaderSize@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAIXZ 0x1406b7a60 ; unique
// MS2-PIN: ?GetHeaderSize@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAIXZ 0x1406b7a70 ; unique
// MS2-PIN: ?GetHeaderSize@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAIXZ 0x1406b7a80 ; unique
// MS2-PIN: ?GetHeaderSize@?$PackFileStream@VCPackStreamVer1@@@@UEAAIXZ 0x1406b7a90 ; unique
// MS2-PIN: ?GetHeaderSize@?$PackFileStream@VCPackStreamVer2@@@@UEAAIXZ 0x1406b7aa0 ; unique
// MS2-PIN: ?GetHeaderSize@?$PackFileStream@VCPackStreamVer3@@@@UEAAIXZ 0x1406b7ab0 ; unique
// MS2-PIN: ?GetFlags@?$PackFileStream@VCPackStreamVer3@@@@QEAAIXZ 0x1406b7ac0 ; unique
// MS2-PIN: ?GetExtra@CPackFileHeaderVer3@@UEAAIXZ 0x1406b7ad0 ; unique
// MS2-PIN: ?GetHeaderData@?$PackFileStream@VCPackStreamVer1@@@@UEAAPEAXXZ 0x1406b7ae0 ; unique
// MS2-PIN: ?GetHeaderData@?$PackFileStream@VCPackStreamVer2@@@@UEAAPEAXXZ 0x1406b7af0 ; unique
// MS2-PIN: ?GetHeaderData@?$PackFileStream@VCPackStreamVer3@@@@UEAAPEAXXZ 0x1406b7b00 ; unique
// MS2-PIN: ?GetIndex@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAIXZ 0x1406b7b10 ; unique
// MS2-PIN: ?GetIndex@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAIXZ 0x1406b7b20 ; unique
// MS2-PIN: ?GetIndex@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAIXZ 0x1406b7b30 ; unique
// MS2-PIN: ?GetListSize@?$PackFileStream@VCPackStreamVer1@@@@UEAA_KXZ 0x1406b7b40 ; unique
// MS2-PIN: ?GetListSize@?$PackFileStream@VCPackStreamVer2@@@@UEAA_KXZ 0x1406b7b50 ; unique
// MS2-PIN: ?GetListSize@?$PackFileStream@VCPackStreamVer3@@@@UEAA_KXZ 0x1406b7b60 ; unique
// MS2-PIN: ?GetSize@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAA_KXZ 0x1406b7b70 ; unique
// MS2-PIN: ?GetSize@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAA_KXZ 0x1406b7b80 ; unique
// MS2-PIN: ?GetSize@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAA_KXZ 0x1406b7b90 ; unique
// MS2-PIN: ?SetTableCompressedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAAX_K@Z 0x1406b7c10 ; unique
// MS2-PIN: ?SetTableCompressedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAAX_K@Z 0x1406b7c30 ; unique
// MS2-PIN: ?SetTableCompressedSize@?$PackFileStream@VCPackStreamVer3@@@@UEAAX_K@Z 0x1406b7c50 ; unique
// MS2-PIN: ?SetListCompressedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAAX_K@Z 0x1406b7c70 ; unique
// MS2-PIN: ?SetListCompressedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAAX_K@Z 0x1406b7c90 ; unique
// MS2-PIN: ?SetListCompressedSize@?$PackFileStream@VCPackStreamVer3@@@@UEAAX_K@Z 0x1406b7cb0 ; unique
// MS2-PIN: ?SetTableEncodedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAAX_K@Z 0x1406b7d30 ; unique
// MS2-PIN: ?SetTableEncodedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAAX_K@Z 0x1406b7d50 ; unique
// MS2-PIN: ?SetTableEncodedSize@?$PackFileStream@VCPackStreamVer3@@@@UEAAX_K@Z 0x1406b7d70 ; unique
// MS2-PIN: ?SetEncodedSize@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAXI@Z 0x1406b7db0 ; unique
// MS2-PIN: ?SetEncodedSize@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAXI@Z 0x1406b7dd0 ; unique
// MS2-PIN: ?SetListEncodedSize@?$PackFileStream@VCPackStreamVer1@@@@UEAAX_K@Z 0x1406b7df0 ; unique
// MS2-PIN: ?SetListEncodedSize@?$PackFileStream@VCPackStreamVer2@@@@UEAAX_K@Z 0x1406b7e10 ; unique
// MS2-PIN: ?SetFileCount@?$PackFileStream@VCPackStreamVer2@@@@UEAAXI@Z 0x1406b7e70 ; unique
// MS2-PIN: ?SetFileCount@?$PackFileStream@VCPackStreamVer3@@@@UEAAXI@Z 0x1406b7e90 ; unique
// MS2-PIN: ?SetMagic@?$PackFileStream@VCPackStreamVer1@@@@UEAAXI@Z 0x1406b7f10 ; unique
// MS2-PIN: ?SetMagic@?$PackFileStream@VCPackStreamVer2@@@@UEAAXI@Z 0x1406b7f30 ; unique
// MS2-PIN: ?SetMagic@?$PackFileStream@VCPackStreamVer3@@@@UEAAXI@Z 0x1406b7f50 ; unique
// MS2-PIN: ?SetOffset@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAX_K@Z 0x1406b7f70 ; unique
// MS2-PIN: ?SetOffset@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAX_K@Z 0x1406b7f90 ; unique
// MS2-PIN: ?SetOffset@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAX_K@Z 0x1406b7fb0 ; unique
// MS2-PIN: ?SetEncodeFlags@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAXUCPackEncodeFlags@@@Z 0x1406b7fd0 ; unique
// MS2-PIN: ?SetEncodeFlags@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAXUCPackEncodeFlags@@@Z 0x1406b7ff0 ; unique
// MS2-PIN: ?SetEncodeFlags@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAXUCPackEncodeFlags@@@Z 0x1406b8010 ; unique
// MS2-PIN: ?SetExtra@CPackFileHeaderVer3@@UEAAXI@Z 0x1406b8030 ; unique
// MS2-PIN: ?SetIndex@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAXI@Z 0x1406b8050 ; unique
// MS2-PIN: ?SetIndex@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAXI@Z 0x1406b8070 ; unique
// MS2-PIN: ?SetIndex@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAXI@Z 0x1406b8090 ; unique
// MS2-PIN: ?SetListSize@?$PackFileStream@VCPackStreamVer1@@@@UEAAX_K@Z 0x1406b80b0 ; unique
// MS2-PIN: ?SetListSize@?$PackFileStream@VCPackStreamVer2@@@@UEAAX_K@Z 0x1406b80d0 ; unique
// MS2-PIN: ?SetListSize@?$PackFileStream@VCPackStreamVer3@@@@UEAAX_K@Z 0x1406b80f0 ; unique
// MS2-PIN: ?SetSize@?$PackFileHeader@VCPackFileHeaderVer1@@@@UEAAX_K@Z 0x1406b8110 ; unique
// MS2-PIN: ?SetSize@?$PackFileHeader@VCPackFileHeaderVer2@@@@UEAAX_K@Z 0x1406b8130 ; unique
// MS2-PIN: ?SetSize@?$PackFileHeader@VCPackFileHeaderVer3@@@@UEAAX_K@Z 0x1406b8150 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIPEAX@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIPEAX@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x1406ba4e0 ; unique
// MS2-PIN: ??$?0AEAHAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0A@@?$pair@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QEAA@AEAHAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z 0x1406be7c0 ; unique
// MS2-PIN: ??$?0HPEAX$0A@@?$pair@$$CBIPEAX@std@@QEAA@$$QEAU?$pair@HPEAX@1@@Z 0x1406be9b0 ; unique
// MS2-PIN: ??$?0HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$0A@@?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QEAA@$$QEAU?$pair@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@@Z 0x1406bea00 ; unique
// MS2-PIN: ??$?0V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAX$0A@@?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAX@std@@QEAA@$$QEAU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PEAX@1@@Z 0x1406beb90 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@1@Z 0x1406bef70 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@PEAX@1@@Z 0x1406bf990 ; unique
// MS2-PIN: ??$forward@PEAX@std@@YA$$QEAPEAXAEAPEAX@Z 0x1406c0b60 ; prop
// MS2-PIN: ??$make_pair@AEAHAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@YA?AU?$pair@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@AEAHAEAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@@Z 0x1406c0d40 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@PEAX@2@@Z 0x1406c1ae0 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x1406c2850 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@std@@@2@XZ 0x1406c2a30 ; unique
// MS2-PIN: ?size@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VSFileStringInfo@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@VSFileStringInfo@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x1406c3000 ; unique
// MS2-PIN: ?strchr@@YAPEADQEADH@Z 0x1406c3040 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ms2filestring.cpp"
// The exe's memcpy_s and char_traits::copy call memcpy (no /Oi expansion): the STL headers come before the intrinsic.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <string>
#pragma intrinsic(memset, memcpy)
#include "ms2filestring.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"

extern int g_nLocaleMode;                  // 2: resolve paths through the mode/locale folders first
extern std::string g_strLocaleFolder;      // locale resource folder (string files)
extern std::string g_strDefaultFolder;     // default resource folder

// @0x1406af2f0
CPackFile::CPackFile() : m_remaining(0), m_magic(MS2_PACK_MAGIC_V1), m_elapsed(0) {
    m_start.QuadPart = 0;
}

// @0x1406af3e0
CPackFile::~CPackFile() {
    for (std::map<unsigned int, CPackFileHeaderVerBase*>::iterator it = m_headers.begin(); it != m_headers.end(); ++it)
        delete it->second;
    m_headers.clear();
}

// @0x1406af540
CPackFile::CPackFile(std::string path, CPackDecodeFunctor decode, CPackDecodeFunctor decodeShort)
    : m_remaining(0), m_decode(decode), m_decodeShort(decodeShort), m_magic(MS2_PACK_MAGIC_V1) {
    Open(path, NULL);
}

// MS2-FUNCTIONAL: same reads, version dispatch, two inflate passes and entry table; frame layout (0x4c0) and temp slots differ.
// @0x1406af680
int CPackFile::Open(std::string path, const char* directory) {
    std::transform(path.begin(), path.end(), path.begin(), tolower);
    m_path = path;
    memset(&m_stream, 0, sizeof(m_stream));
    std::string headerPath = path + ".m2h";
    if (directory) {
        headerPath.clear();
        headerPath.append(directory);
        headerPath.append("/");
        headerPath.append(path);
        headerPath.append(".m2h");
    }
    HANDLE file = CreateFileA(headerPath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    unsigned int streamFlags = 0;
    if (file != INVALID_HANDLE_VALUE) {
        CPackStreamVerBase* stream = NULL;
        CPackFileHeaderVerBase* header = NULL;
        DWORD read = 0;
        ReadFile(file, &m_magic, 4, &read, NULL);
        if (read != 4) {
            CloseHandle(file);
            return 0;
        }
        switch (m_magic) {
        case MS2_PACK_MAGIC_V1:
            stream = new PackFileStream<CPackStreamVer1>();
            header = new PackFileHeader<CPackFileHeaderVer1>();
            break;
        case MS2_PACK_MAGIC_V2:
            stream = new PackFileStream<CPackStreamVer2>();
            header = new PackFileHeader<CPackFileHeaderVer2>();
            break;
        case MS2_PACK_MAGIC_V3:
            stream = new PackFileStream<CPackStreamVer3>();
            header = new PackFileHeader<CPackFileHeaderVer3>();
            break;
        case MS2_PACK_MAGIC_V4:
            stream = new PackFileStream<CPackStreamVer3>();
            header = new PackFileHeader<CPackFileHeaderVer3>();
            break;
        default:
            CloseHandle(file);
            return 0;
        }
        DWORD headerSize = stream->GetHeaderSize();
        ReadFile(file, stream->GetHeaderData(), headerSize, &read, NULL);
        if (read != stream->GetHeaderSize()) {
            CloseHandle(file);
            delete stream;
            delete header;
            return 0;
        }
        if (stream->GetListSize() == 0) {
            delete stream;
            delete header;
            CloseHandle(file);
            return 0;
        }
        if (m_magic == MS2_PACK_MAGIC_V3 || m_magic == MS2_PACK_MAGIC_V4)
            streamFlags = static_cast<PackFileStream<CPackStreamVer3>*>(stream)->GetFlags();

        // pass 1: the file list
        inflateInit(&m_stream);
        header->SetSize(stream->GetListSize());
        header->SetCompressedSize(stream->GetListCompressedSize());
        CPackEncodeFlags flags;
        flags.m_value = 0;
        flags.m_flags[0] = 9;
        flags.m_flags[3] = 0xee;
        header->SetEncodeFlags(flags);
        header->SetOffset(0);
        header->SetEncodedSize((unsigned int)stream->GetListEncodedSize());
        unsigned int bufferSize = (unsigned int)(header->GetSize() + 2);
        char* list = new char[(size_t)(bufferSize * 1.5f)];
        list[header->GetSize()] = 0;
        list[header->GetSize() + 1] = 0;
        m_remaining = header->GetCompressedSize();
        unsigned __int64 written = 0;
        if (!Inflate(file, header, (unsigned char**)&list, (size_t)(bufferSize * 1.5f), &written)) {
            delete stream;
            delete header;
            CloseHandle(file);
            return 0;
        }
        inflateEnd(&m_stream);
        if (!m_index.Load(list, (unsigned int)stream->GetListSize())) {
            delete[] list;
            delete stream;
            delete header;
            CloseHandle(file);
            return 0;
        }
        delete[] list;

        // pass 2: the file table
        header->SetSize(stream->GetTableSize());
        header->SetCompressedSize(stream->GetTableCompressedSize());
        header->SetOffset(0);
        flags.m_value = 0;
        flags.m_flags[0] = 9;
        flags.m_flags[3] = 0xee;
        header->SetEncodeFlags(flags);
        header->SetEncodedSize((unsigned int)stream->GetTableEncodedSize());
        bufferSize = (unsigned int)header->GetSize() + 2;
        char* table = new char[(size_t)(bufferSize * 1.5f)];
        table[header->GetSize()] = 0;
        table[header->GetSize() + 1] = 0;
        m_remaining = header->GetCompressedSize();
        inflateInit(&m_stream);
        memset(table, 0, bufferSize);
        written = 0;
        if (!Inflate(file, header, (unsigned char**)&table, (size_t)(bufferSize * 1.5f), &written)) {
            delete[] table;
            delete stream;
            delete header;
            CloseHandle(file);
            return 0;
        }
        unsigned int count = (unsigned int)(stream->GetTableSize() / header->GetHeaderSize());
        if (stream->GetTableSize() % header->GetHeaderSize() != 0) {
            delete[] table;
            delete stream;
            delete header;
            CloseHandle(file);
            return 0;
        }
        for (unsigned int i = 0; i < count; i++) {
            CPackFileHeaderVerBase* entry = NULL;
            if (m_magic == MS2_PACK_MAGIC_V1)
                entry = new PackFileHeader<CPackFileHeaderVer1>(table + i * sizeof(CPackFileHeaderVer1Data));
            else if (m_magic == MS2_PACK_MAGIC_V2)
                entry = new PackFileHeader<CPackFileHeaderVer2>(table + i * sizeof(CPackFileHeaderVer2Data));
            else if (m_magic == MS2_PACK_MAGIC_V3)
                entry = new PackFileHeader<CPackFileHeaderVer3>(table + i * sizeof(CPackFileHeaderVer3Data));
            else if (m_magic == MS2_PACK_MAGIC_V4)
                entry = new PackFileHeader<CPackFileHeaderVer3>(table + i * sizeof(CPackFileHeaderVer3Data));
            if (entry) {
                unsigned int index = entry->GetIndex();
                m_headers.insert(std::make_pair(index, entry));
            }
        }
        delete[] table;
        delete stream;
        delete header;
        CloseHandle(file);
        inflateEnd(&m_stream);
    } else {
        return 0;
    }
    return m_index.Open(m_magic, m_path, m_handles, directory);
}

// MS2-FUNCTIONAL: same lookup order (mode, locale, plain) and locked inflate; local slot order differs.
// @0x1406b0e20
int CPackFile::Read(std::string path, unsigned char** data, unsigned __int64* size, bool stringFile) {
    CPackFileHeaderVerBase* header = NULL;
    std::string modePath = GetModePath(path);
    unsigned int id = 0;
    if (!modePath.empty())
        id = m_index.GetIndex(modePath);
    if (id == 0) {
        std::string localePath = GetLocalePath(path, stringFile);
        id = m_index.GetIndex(localePath);
        if (id == 0)
            id = m_index.GetIndex(path);
    }
    if (id == 0)
        return 0;
    HANDLE file = m_handles[id];
    header = GetHeader(id);
    if (!header)
        return 0;
    if (header->GetSize() == 0)
        return 0;
    if (Unk_LockGuard guard = m_lock) {
    } else {
        inflateInit(&m_stream);
        float capacity;
        if (header->GetEncodeFlags().m_flags[0] == 0)
            capacity = (float)header->GetSize();
        else
            capacity = (float)header->GetSize() * 1.5f;
        unsigned int allocSize = (int)capacity + 2;
        *data = (unsigned char*)EE_ALLOC(unsigned char, allocSize);
        (*data)[header->GetSize()] = 0;
        (*data)[header->GetSize() + 1] = 0;
        LARGE_INTEGER offset;
        offset.LowPart = (DWORD)header->GetOffset();
        offset.HighPart = (LONG)(header->GetOffset() >> 32);
        if (!SetFilePointerEx(file, offset, NULL, FILE_BEGIN)) {
            EE_FREE(*data);
            *data = NULL;
            return 0;
        }
        m_remaining = header->GetCompressedSize();
        *size = header->GetSize();
        unsigned __int64 written = 0;
        if (!Inflate(file, header, data, allocSize, &written)) {
            inflateEnd(&m_stream);
            EE_FREE(*data);
            *data = NULL;
            return 0;
        }
        inflateEnd(&m_stream);
    }
    return 1;
}

// @0x1406b1450
void CPackFile::Close() {
}

// MS2-FUNCTIONAL: same index lookup; the by-value string temp sits in a different frame slot.
// @0x1406b1460
bool CPackFile::Exists(std::string path) {
    int index = m_index.GetIndex(path);
    return index != 0;
}

// @0x1406b14f0
int CPackFile::IsPacked(std::string path, bool stringFile) {
    std::string modePath = GetModePath(path);
    bool found = false;
    if (!modePath.empty())
        found = m_index.GetIndex(modePath) != 0;
    if (!found) {
        std::string localePath = GetLocalePath(path, stringFile);
        if (m_index.GetIndex(localePath) == 0)
            return m_index.GetIndex(path) != 0;
    }
    return 1;
}

// @0x1406b1760
int CPackFile::Contains(std::string text) {
    CMS2FileString::FileMap& files = m_index.GetFiles();
    for (CMS2FileString::FileMap::iterator it = files.begin(); it != files.end(); ++it) {
        if (it->first.find(text, 0) != std::string::npos)
            return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: same "/textures" filter and path joins; temp string slots differ.
// @0x1406b1830
void CPackFile::GetTexturePaths(std::list<std::string>& paths) {
    if (m_path.find("/textures", 0) == std::string::npos) {
        CMS2FileString::FileMap& files = m_index.GetFiles();
        for (CMS2FileString::FileMap::iterator it = files.begin(); it != files.end(); ++it) {
            if (it->first.find("textures/", 0) != std::string::npos)
                paths.push_back(GetPath() + "/" + it->first);
        }
    } else {
        CMS2FileString::FileMap& files = m_index.GetFiles();
        for (CMS2FileString::FileMap::iterator it = files.begin(); it != files.end(); ++it)
            paths.push_back(GetPath() + "/" + it->first);
    }
}

// @0x1406b1ad0
void CPackFile::SetDecode(CPackDecodeFunctor decode) {
    m_decode = decode;
}

// @0x1406b1b20
void CPackFile::SetDecodeShort(CPackDecodeFunctor decode) {
    m_decodeShort = decode;
}

// MS2-FUNCTIONAL: same index lookup and header fetch; frame size differs.
// @0x1406b1b70
CPackFileHeaderVerBase* CPackFile::GetHeader(std::string path) {
    int index = m_index.GetIndex(path);
    if (index == 0)
        return NULL;
    return GetHeader(index);
}

// @0x1406b1c20
int CPackFile::Inflate(HANDLE file, CPackFileHeaderVerBase* header, unsigned char** out, unsigned __int64 capacity,
                       unsigned __int64* written) {
    QueryPerformanceCounter(&m_start);
    DWORD read = 0;
    m_stream.avail_in = 0;
    unsigned char* encoded = new unsigned char[header->GetEncodedSize()];
    ReadFile(file, encoded, header->GetEncodedSize(), &read, NULL);
    unsigned char* decoded = NULL;
    unsigned long decodedSize = 0;
    if (!(header->GetEncodeFlags().m_flags[3] & 1)) {
        decodedSize = m_decode(m_magic, encoded, read, &decoded, (unsigned long)header->GetCompressedSize());
        if (!decodedSize || !decoded) {
            delete[] encoded;
            return 0;
        }
        delete[] encoded;
        encoded = NULL;
    } else {
        decodedSize = m_decodeShort(m_magic, encoded, read, &decoded, (unsigned long)header->GetCompressedSize());
        if (!decodedSize || !decoded) {
            delete[] encoded;
            return 0;
        }
    }
    if (decodedSize != header->GetCompressedSize()) {
        if (encoded)
            delete[] encoded;
        return 0;
    }
    if (header->GetEncodeFlags().m_flags[0] == 0) {
        if ((__int64)(m_remaining - read) < 0)
            m_remaining = 0;
        else
            m_remaining -= read;
        *written = decodedSize;
        memcpy(*out, decoded, decodedSize);
        delete[] decoded;
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        m_elapsed = now.QuadPart - m_start.QuadPart;
        return 1;
    } else {
        int done = 0;
        m_stream.next_out = *out;
        m_stream.avail_out = (uInt)capacity;
        bool more = true;
        unsigned int consumed = 0;
        while (more) {
            if (m_stream.avail_out == 0) {
                *written = capacity;
                break;
            }
            if (m_stream.avail_in == 0) {
                m_stream.next_in = decoded + consumed;
                m_stream.avail_in = read;
                consumed += read;
                if (m_remaining - read < 0)
                    m_remaining = 0;
                else
                    m_remaining -= read;
            }
            int ret = inflate(&m_stream, m_remaining == 0 ? Z_FINISH : Z_NO_FLUSH);
            switch (ret) {
            case Z_BUF_ERROR:
                delete[] decoded;
                return 0;
            case Z_OK:
                if (m_stream.avail_out == 0) {
                    delete[] decoded;
                    return 0;
                }
                break;
            case Z_STREAM_END:
                more = false;
                done = 1;
                break;
            default:
                delete[] decoded;
                more = false;
                return 0;
            }
        }
        if (done)
            *written = capacity - m_stream.avail_out;
    }
    delete[] decoded;
    LARGE_INTEGER end;
    QueryPerformanceCounter(&end);
    m_elapsed = end.QuadPart - m_start.QuadPart;
    return 1;
}

// @0x1406b2260
CPackFileHeaderVerBase* CPackFile::GetHeader(unsigned int index) {
    if (index != 0) {
        std::map<unsigned int, CPackFileHeaderVerBase*>::iterator it = m_headers.find(index);
        if (it != m_headers.end())
            return it->second;
    }
    return NULL;
}

// MS2-FUNCTIONAL: same mode-folder path build; return/temp string slots differ.
// @0x1406b22e0
std::string CPackFile::GetModePath(std::string path) {
    if (g_nLocaleMode == 2) {
        std::string result;
        size_t pos = path.find_last_of('/');
        if (pos == std::string::npos) {
            result = g_strDefaultFolder;
            std::string locale(g_strLocaleFolder);
            std::transform(locale.begin(), locale.end(), locale.begin(), tolower);
            result.append(locale);
            result += path;
        } else {
            result = path.substr(0, pos + 1) + g_strDefaultFolder;
            std::string locale(g_strLocaleFolder);
            std::transform(locale.begin(), locale.end(), locale.begin(), tolower);
            result.append(locale);
            result += path.substr(pos + 1, path.size());
        }
        return result;
    }
    return std::string("");
}

// MS2-FUNCTIONAL: same locale-then-default path build; temp string slots differ.
// @0x1406b2660
std::string CPackFile::GetLocalePath(std::string path, bool stringFile) {
    std::string result;
    size_t pos = path.find_last_of('/');
    if (pos == std::string::npos) {
        bool fallback = true;
        if (stringFile) {
            result = g_strLocaleFolder;
            result += path;
            fallback = m_index.GetIndex(result) == 0;
        }
        if (fallback) {
            result = g_strDefaultFolder;
            result += path;
        }
    } else {
        bool fallback = true;
        if (stringFile) {
            result = path.substr(0, pos + 1) + g_strLocaleFolder;
            result += path.substr(pos + 1, path.size());
            fallback = m_index.GetIndex(result) == 0;
        }
        if (fallback) {
            result = path.substr(0, pos + 1) + g_strDefaultFolder;
            result += path.substr(pos + 1, path.size());
        }
    }
    return result;
}

// @0x1406bc4f0
CMS2FileString::~CMS2FileString() {
    for (std::map<std::string, HANDLE>::iterator it = m_archives.begin(); it != m_archives.end(); ++it)
        CloseHandle(it->second);
    m_archives.clear();
}

// @0x1406bc5c0
int CMS2FileString::GetIndex(std::string name) {
    int index = 0;
    FileMap::iterator it = m_files.find(name);
    if (it != m_files.end())
        index = it->second.m_index;
    return index;
}

// MS2-FUNCTIONAL: same index, _splitpath archive encoding and both inserts; temp slots differ.
// @0x1406bc650
int CMS2FileString::Add(std::string path) {
    int index = 0;
    index = (int)m_files.size();
    index++;
    SFileStringInfo info;
    info.m_index = index;
    char dir[256];
    char name[256];
    _splitpath(path.c_str(), NULL, dir, name, NULL);
    if (dir[0]) {
        char* slash = strchr(dir, '/');
        if (slash)
            *slash = 0;
        char* encoded = Encode(std::string(dir));
        info.m_archive = encoded;
        delete[] encoded;
    }
    m_files.insert(std::make_pair(path, info));
    m_names.insert(std::make_pair(index, path));
    return index;
}

// MS2-FUNCTIONAL: same index, archive encoding and both inserts; temp slots differ.
// @0x1406bc880
int CMS2FileString::Add(std::string path, std::string archive) {
    int index = 0;
    index = (int)m_files.size();
    index++;
    SFileStringInfo info;
    info.m_index = index;
    char* encoded = Encode(archive);
    info.m_archive = encoded;
    delete[] encoded;
    m_files.insert(std::make_pair(path, info));
    m_names.insert(std::make_pair(index, path));
    return index;
}

// @0x1406bca40
std::string CMS2FileString::GetName(unsigned int index) {
    std::map<unsigned int, std::string>::iterator it = m_names.find(index);
    if (it == m_names.end())
        return "";
    return it->second;
}

// MS2-FUNCTIONAL: same CRLF split and Parse per line; loop temps are laid out differently.
// @0x1406bcb00
int CMS2FileString::Load(char* data, unsigned int size) {
    m_files.clear();
    char* line = data;
    do {
        char* end = strstr(line, "\r\n");
        for (unsigned int i = 0; i < 2; i++)
            end[i] = 0;
        Parse(line);
        line = end + 2;
    } while (line < data + size);
    return 1;
}

// MS2-FUNCTIONAL: same "index,[archive,]name\r\n" lines written; temp slots differ.
// @0x1406bcbe0
int CMS2FileString::Save(HANDLE file) {
    std::string line;
    size_t charSize = 1;
    for (FileMap::iterator it = m_files.begin(); it != m_files.end(); ++it) {
        char buffer[32];
        _itoa_s(it->second.m_index, buffer, 10);
        line = buffer;
        line += ",";
        if (!it->second.m_archive.empty()) {
            line += it->second.m_archive;
            line += ",";
        }
        line += it->first;
        line += "\r\n";
        size_t bytes = line.size() * charSize;
        DWORD writtenBytes;
        WriteFile(file, line.c_str(), (DWORD)bytes, &writtenBytes, NULL);
    }
    return 1;
}

// MS2-FUNCTIONAL: same comma count, strtok fields, lowercase name and both inserts; temp slots differ.
// @0x1406bcdb0
void CMS2FileString::Parse(char* line) {
    SFileStringInfo info;
    int commas = 0;
    std::string text(line);
    for (int i = 0; line[i] != 0; i++) {
        if (line[i] == ',')
            commas++;
    }
    std::string name;
    if (commas == 1) {
        char* token = strtok(line, ",");
        info.m_index = atoi(token);
        if (token) {
            token = strtok(NULL, ",");
            name = token;
        }
    } else if (commas == 2) {
        char* token = strtok(line, ",");
        info.m_index = atoi(token);
        int field = 0;
        while (token) {
            token = strtok(NULL, ",");
            if (token) {
                if (field == 0)
                    info.m_archive = token;
                else if (field == 1)
                    name = token;
                field++;
            }
        }
    } else {
        MS2_ASSERT_AT(0x1e6, 0);
    }
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    m_files.insert(std::make_pair(name, info));
    m_names.insert(std::make_pair(info.m_index, name));
}

// MS2-FUNCTIONAL: same find and copy-out; the found flag is kept in a different form.
// @0x1406bd110
bool CMS2FileString::Find(std::string name, SFileStringInfo& info) {
    FileMap::iterator it = m_files.find(name);
    bool found = it != m_files.end();
    if (found)
        info = it->second;
    return found;
}

// @0x1406bd1c0
void CMS2FileString::GetArchiveNames(std::set<std::string>& names) {
    names.clear();
    for (FileMap::iterator it = m_files.begin(); it != m_files.end(); ++it)
        names.insert(it->second.m_archive);
}

// MS2-FUNCTIONAL: same archive-name iteration, .m2d opens, error box and handle mapping; temp slots differ.
// @0x1406bd250
int CMS2FileString::Open(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles,
                         const char* directory) {
    if (magic < MS2_PACK_MAGIC_V1 || magic > MS2_PACK_MAGIC_V2) {
        std::set<std::string> names;
        GetArchiveNames(names);
        if (!names.empty()) {
            std::string file(path);
            if (directory) {
                file.clear();
                file.append(directory);
                file.append("/");
                file.append(path);
            }
            for (std::set<std::string>::iterator it = names.begin(); it != names.end(); ++it) {
                if (!it->empty())
                    file = path + "_" + *it;
                file += ".m2d";
                HANDLE handle =
                    CreateFileA(file.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
                if (handle == INVALID_HANDLE_VALUE) {
                    LPSTR message;
                    FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                                       FORMAT_MESSAGE_IGNORE_INSERTS,
                                   NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message,
                                   0, NULL);
                    MessageBoxA(NULL, message, "Error", MB_ICONINFORMATION | MB_TOPMOST);
                    LocalFree(message);
                    return 0;
                }
                m_archives.insert(std::make_pair(*it, handle));
            }
            for (FileMap::iterator it = m_files.begin(); it != m_files.end(); ++it) {
                for (std::map<std::string, HANDLE>::iterator archive = m_archives.begin();
                     archive != m_archives.end(); ++archive) {
                    if (it->second.m_archive == archive->first) {
                        handles.insert(std::make_pair(it->second.m_index, archive->second));
                        break;
                    }
                }
            }
            return 1;
        }
        MessageBoxA(NULL, "FileString", "Error", MB_ICONINFORMATION | MB_TOPMOST);
        return 0;
    }
    return OpenSingle(magic, path, handles, directory);
}

// @0x1406bd810
int CMS2FileString::OpenSingle(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles,
                               const char* directory) {
    std::string file = path + ".m2d";
    if (directory) {
        file.clear();
        file.append(directory);
        file.append("/");
        file.append(path);
        file.append(".m2d");
    }
    HANDLE handle = CreateFileA(file.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (handle == INVALID_HANDLE_VALUE) {
        LPSTR message;
        FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message, 0, NULL);
        MessageBoxA(NULL, message, "Error", MB_ICONINFORMATION | MB_TOPMOST);
        LocalFree(message);
        return 0;
    }
    m_archives.insert(std::make_pair(std::string(), handle));
    for (FileMap::iterator it = m_files.begin(); it != m_files.end(); ++it)
        handles.insert(std::make_pair(it->second.m_index, handle));
    return 1;
}

// MS2-FUNCTIONAL: same as Open with write/CREATE_ALWAYS; temp slots differ.
// @0x1406bdb00
int CMS2FileString::Create(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles) {
    if (magic < MS2_PACK_MAGIC_V1 || magic > MS2_PACK_MAGIC_V2) {
        std::set<std::string> names;
        GetArchiveNames(names);
        if (!names.empty()) {
            std::string file(path);
            for (std::set<std::string>::iterator it = names.begin(); it != names.end(); ++it) {
                if (!it->empty())
                    file = path + "_" + *it;
                file += ".m2d";
                HANDLE handle =
                    CreateFileA(file.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, NULL);
                if (handle == INVALID_HANDLE_VALUE) {
                    LPSTR message;
                    FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                                       FORMAT_MESSAGE_IGNORE_INSERTS,
                                   NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message,
                                   0, NULL);
                    MessageBoxA(NULL, message, "Error", MB_ICONINFORMATION | MB_TOPMOST);
                    LocalFree(message);
                    return 0;
                }
                m_archives.insert(std::make_pair(*it, handle));
            }
            for (FileMap::iterator it = m_files.begin(); it != m_files.end(); ++it) {
                for (std::map<std::string, HANDLE>::iterator archive = m_archives.begin();
                     archive != m_archives.end(); ++archive) {
                    if (it->second.m_archive == archive->first) {
                        handles.insert(std::make_pair(it->second.m_index, archive->second));
                        break;
                    }
                }
            }
            return 1;
        }
        MessageBoxA(NULL, "FileString", "Error", MB_ICONINFORMATION | MB_TOPMOST);
        return 0;
    }
    return CreateSingle(magic, path, handles);
}

// @0x1406be060
int CMS2FileString::CreateSingle(unsigned int magic, std::string path, std::map<unsigned int, HANDLE>& handles) {
    std::string file = path + ".m2d";
    HANDLE handle = CreateFileA(file.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, NULL);
    if (handle == INVALID_HANDLE_VALUE) {
        LPSTR message;
        FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&message, 0, NULL);
        MessageBoxA(NULL, message, "Error", MB_ICONINFORMATION | MB_TOPMOST);
        LocalFree(message);
        return 0;
    }
    m_archives.insert(std::make_pair(std::string(), handle));
    for (FileMap::iterator it = m_files.begin(); it != m_files.end(); ++it)
        handles.insert(std::make_pair(it->second.m_index, handle));
    return 1;
}

// MS2-FUNCTIONAL: same letter-code encoding; strlen/temp layout differs.
// @0x1406be2e0
char* CMS2FileString::Encode(std::string name) {
    if (name.empty())
        return NULL;
    const char* text = name.c_str();
    size_t length = strlen(text);
    size_t size = length + 1 + CountLetters(text, length);
    char* out = new char[size];
    memset(out, 0, size);
    int j = 0;
    for (size_t i = 0; i < length; i++) {
        int code = GetLetterCode(text[i]);
        if (code == 0) {
            if (text[i] == '/')
                out[j] = '_';
            else
                out[j] = text[i];
            j++;
        } else {
            sprintf_s(out + j, size - j, "%02d", code);
            j += 2;
        }
    }
    out[size - 1] = 0;
    return out;
}

// MS2-FUNCTIONAL: same WideCharToMultiByte conversion; temp slots differ.
// @0x1406be510
char* CMS2FileString::ToMultiByte(const wchar_t* text) {
    size_t size = wcslen(text) * 2 + 2;
    char* out = new char[size];
    WideCharToMultiByte(CP_ACP, 0, text, -1, out, (int)size, NULL, NULL);
    return out;
}

// MS2-FUNCTIONAL: same mbstowcs conversion and buffer size; temp slots differ.
// @0x1406be590
wchar_t* CMS2FileString::ToWide(const char* text) {
    size_t length = strlen(text) + 1;
    wchar_t* out = new wchar_t[length * 2];
    mbstowcs(out, text, length);
    return out;
}

// @0x1406be640
size_t CMS2FileString::CountLetters(const char* text, size_t length) {
    size_t count = 0;
    for (size_t i = 0; i < length; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            count++;
        else if (text[i] >= 'a' && text[i] <= 'z')
            count++;
    }
    return count;
}

// @0x1406be710
int CMS2FileString::GetLetterCode(char c) {
    bool letter = false;
    if (c >= 'A' && c <= 'Z')
        letter = true;
    else if (c >= 'a' && c <= 'z')
        letter = true;
    if (letter)
        return c - '0';
    return 0;
}

// @0x1406c3060
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// Three unreferenced members of a CAtlArray<BYTE> byte buffer close the TU (no caller, no RTTI; names invented).
class CPackBuffer : public ATL::CAtlArray<BYTE> {
public:
    CPackBuffer();
    void Clear();
    void SetSize(size_t size, BOOL zero);
};

// @0x1406c3180
CPackBuffer::CPackBuffer() {
}

// @0x1406c31b0
void CPackBuffer::Clear() {
    RemoveAll();
}

// @0x1406c31d0
void CPackBuffer::SetSize(size_t size, BOOL zero) {
    SetCount(size, -1);
    if (zero)
        memset(&(*this)[0], 0, size);
}
