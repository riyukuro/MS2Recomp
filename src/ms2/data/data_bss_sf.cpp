// Data unit (sfr22; group 143b17214 of work/sfr35/outside-units.tsv):
// exe globals of the .bss block below that no recovered TU defines (zero: the exe's raw .data ends at 0x143aab400).
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_bss_sf
// MS2-RANGE: 0x143b15780-0x143b157a0 .bss
// MS2-RANGE: 0x143b17214-0x143b172a8 .bss

#ifndef MS2_HOOK_DLL

alignas(16) unsigned char DAT_143b15780[0x20];                  // 0x143b15780: an AS3 Value (destroyed by the exe exit dtor, sfr_atexit_01)
unsigned int BundlePatternFrameId = 0x0u;                       // 0x143b17214
unsigned int BuildPatternCount = 0x0u;                          // 0x143b17218
alignas(16) unsigned char DAT_143b17220[0x8];                   // 0x143b17220
alignas(8) unsigned char DAT_143b17228[0x8];                    // 0x143b17228
alignas(16) unsigned char DAT_143b17230[0x78];                  // 0x143b17230

#pragma comment(linker, "/alternatename:DAT_143b15780=?DAT_143b15780@@3PAEA")
#pragma comment(linker, "/alternatename:?TCN_This@@3PEDVTreeCacheNode@Render@Scaleform@@ED=?DAT_143b17220@@3PAEA")
#pragma comment(linker, "/alternatename:?TCN_ThisData@@3PEDVNodeData@TreeNode@Render@Scaleform@@ED=?DAT_143b17228@@3PAEA")
#pragma comment(linker, "/alternatename:?TCN_ChildNode@@3PEDVTreeNode@Render@Scaleform@@ED=?DAT_143b17230@@3PAEA")

#endif // MS2_HOOK_DLL
