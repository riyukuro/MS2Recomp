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

namespace Scaleform { namespace Render { class TreeCacheNode;
    // Stand-in for the SDK class: only its nested NodeData name is needed, for TCN_ThisData's mangled name.
    class TreeNode { public: class NodeData; }; } }
extern "C" { alignas(16) unsigned char DAT_143b15780[0x20]; }                  // 0x143b15780: an AS3 Value (destroyed by the exe exit dtor, sfr_atexit_01)
unsigned int BundlePatternFrameId = 0x0u;                       // 0x143b17214
unsigned int BuildPatternCount = 0x0u;                          // 0x143b17218
alignas(16) class Scaleform::Render::TreeCacheNode const volatile *TCN_This;                   // 0x143b17220
class Scaleform::Render::TreeNode::NodeData const volatile *TCN_ThisData;                     // 0x143b17228
alignas(16) class Scaleform::Render::TreeNode const volatile *TCN_ChildNode;                  // 0x143b17230
alignas(8) unsigned char DAT_143b17238[0x70];                   // 0x143b17238 (up to Scale9State::InterfaceImpl)

#endif // MS2_HOOK_DLL
