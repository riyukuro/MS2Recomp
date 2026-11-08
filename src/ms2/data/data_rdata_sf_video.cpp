// Data unit (sfr22; group sfr33v of work/sfr35/outside-units.tsv):
// exe globals of the .rdata block below that no recovered TU defines, initialized with the exe's values.
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_rdata_sf_video
// MS2-RANGE: 0x1431b4be0-0x1431b8030 .rdata

#ifndef MS2_HOOK_DLL

// Functions and objects the tables below point at (static members, free functions and globals defined in other
// units), declared here so the slots name them directly; the owning classes are reduced to those members.
namespace Scaleform {
namespace GFx {
namespace AS2 {
class AvmCharacter;
class Object;
class CFunctionObject;
class Environment;
class ASStringContext;
class Value;
template <unsigned __int64 P0> class RefCountCollector;
class FnCall;
typedef void (*FunctionCFunc)(const FnCall&);
struct NameFunction { const char* Name; FunctionCFunc Function; };   // as sfr_video_01 declares it
class NetStreamProto
{
public:
    static void Close(const FnCall&);
    static void Pause(const FnCall&);
    static void Play(const FnCall&);
    static void Seek(const FnCall&);
    static void SetBufferTime(const FnCall&);
};
}
class InteractiveObject
{
public: enum FocusEventType : int;
};
enum FocusMovedType : int;
class ASString;
namespace AS3 {
namespace InstanceTraits {
class CTraits;
}
class Class;
class Value;
}
}
namespace Render {
template <class P0> class Rect;
template <class P0> class Matrix2x4;
}
}
namespace Scaleform {
namespace GFx {
namespace AS2 {
bool AvmVideoCharacter_OnUnloading(::Scaleform::GFx::AS2::AvmCharacter *);
}
}
}
extern unsigned char DAT_1424f0700[]; __pragma(comment(linker, "/alternatename:?DAT_1424f0700@@3PAEA=?Construct@Instance@AS3@GFx@Scaleform@@UEAAXAEAVValue@234@IPEBV5234@_N@Z")) // AS3 Instance::Construct
extern unsigned char DAT_142503800[]; __pragma(comment(linker, "/alternatename:?DAT_142503800@@3PAEA=?ForEachChild_GC@Class@AS3@GFx@Scaleform@@UEBAXPEAV?$RefCountCollector@$0BED@@234@P6AX0PEAPEBV?$RefCountBaseGC@$0BED@@234@@Z@Z")) // AS3 Class::ForEachChild_GC
extern unsigned char DAT_142503f50[]; __pragma(comment(linker, "/alternatename:?DAT_142503f50@@3PAEA=?ForEachChild_GC@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBAXPEAV?$RefCountCollector@$0BED@@345@P6AX0PEAPEBV?$RefCountBaseGC@$0BED@@345@@Z@Z")) // AS3 ClassTraits::Traits::ForEachChild_GC
extern unsigned char DAT_142503fa0[]; __pragma(comment(linker, "/alternatename:?DAT_142503fa0@@3PAEA=?ForEachChild_GC@Traits@InstanceTraits@AS3@GFx@Scaleform@@UEBAXPEAV?$RefCountCollector@$0BED@@345@P6AX0PEAPEBV?$RefCountBaseGC@$0BED@@345@@Z@Z")) // AS3 InstanceTraits::Traits::ForEachChild_GC
//
//
void FUN_140012e10(void *, void *, void *);
char const * FUN_140012ef0(void *);
char const * FUN_140012f40(void *);
void FUN_140013230(void *, void *, void const *, void *, unsigned int, void const *);
void FUN_140013250(void *, void *, void const *, void *, unsigned int, void const *);
void FUN_1400133e0(void *, void *, void const *, void *, unsigned int, void const *);
void FUN_140013400(void *, void *, void const *, void *, unsigned int, void const *);
void FUN_140013420(void *, void *, void const *, void *, unsigned int, void const *);
void FUN_140013440(void *, void *, void const *, void *, unsigned int, void const *);
char const * FUN_1400141a0(void *);
void FUN_140014900(void *, unsigned __int64 const *);
::Scaleform::GFx::AS3::InstanceTraits::CTraits * FUN_140014a80(::Scaleform::GFx::AS3::InstanceTraits::CTraits *, unsigned int);
::Scaleform::GFx::AS3::Class * FUN_140014b10(::Scaleform::GFx::AS3::Class *, unsigned int);
void * FUN_140015590(void *, unsigned int);
void FUN_1400155d0(void *, ::Scaleform::GFx::AS3::Value *, void *);
void * FUN_140015c00(void *, unsigned int);
void FUN_140015c40(void *);
void FUN_140015d20(void *, void *, void *, unsigned int *);
void FUN_140015da0(void *, void *, void *, unsigned int *);
void FUN_140015e20(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140015eb0(void *, void *, void *, unsigned int *);
void FUN_140015f20(void *, void *, void *, unsigned int *);
void FUN_140015f90(void *, void *, void *, unsigned int *);
void FUN_140016000(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016060(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016100(void *, void *, void *, unsigned int *);
void FUN_140016180(void *, void *, void *, unsigned int *);
void FUN_140016200(void *, void *, void *, unsigned int *);
void FUN_140016270(void *, void *, void *, unsigned int *);
void FUN_1400162f0(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016350(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_1400163b0(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016410(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_1400164a0(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016530(void *, void *, void *, unsigned int *);
void FUN_1400165a0(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016600(void *, void *, void *, unsigned int *);
void FUN_140016680(void *, void *, void *, unsigned int *);
void FUN_140016700(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016790(void *, void *, void *, unsigned int *);
void FUN_140016810(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_1400168a0(void *, void *, void *, unsigned int *);
void FUN_140016920(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_1400169b0(void *, void *, void *, unsigned int *);
void FUN_140016a30(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016ac0(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140019d70(void *, void *, void *, ::Scaleform::GFx::AS3::Value *);
void FUN_140019e20(void *, void *, void *, ::Scaleform::GFx::AS3::Value *);
void FUN_140019ed0(void *, void *, void *, ::Scaleform::GFx::AS3::Value *);

namespace Scaleform { namespace GFx { namespace AS2 { class ASStringContext; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class AvmCharacter; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class Environment; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class FunctionRef; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class Object; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class ObjectInterface; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class PropFlags; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class Value; } } }
namespace Scaleform { namespace GFx { namespace AS2 { class VideoObject; } } }
namespace Scaleform { namespace GFx { namespace AS3 { namespace InstanceTraits { class CTraits; } } } }
namespace Scaleform { namespace GFx { namespace AS3 { namespace InstanceTraits { class Traits; } } } }
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl_display { class DisplayObject; } } } } }
namespace Scaleform { namespace GFx { namespace AS3 { class Value; } } }
namespace Scaleform { namespace GFx { class ASString; } }
namespace Scaleform { namespace GFx { class InteractiveObject; } }
namespace Scaleform { class String; }
void FUN_140002930(void *);
bool FUN_140002950(void *);
void FUN_140002960(void *, float);
void FUN_140002980(void *);
void * FUN_140002b30(void *, unsigned int);
void * FUN_140002bb0(void *, unsigned int);
void * FUN_140002c10(void *, unsigned int);
void * FUN_140002cc0(void *, unsigned int);
void * FUN_140002d20(void *, unsigned int);
int FUN_140002d90(void *);
int FUN_140002da0(void *);
void FUN_140002db0(void *);
void FUN_140002dc0(void *);
float FUN_140002dd0(void *);
void FUN_140002de0(void *);
float FUN_140002df0(void *);
float FUN_140002e00(void *);
void FUN_140002e10(void *);
void FUN_140002e20(void *);
void * FUN_140002e40(void *, unsigned int);
::Scaleform::GFx::AS2::FunctionRef * FUN_140007ff0(::Scaleform::GFx::AS2::ObjectInterface *, ::Scaleform::GFx::AS2::FunctionRef *, ::Scaleform::GFx::AS2::ASStringContext *); __pragma(comment(linker, "/alternatename:?FUN_140007ff0@@YAPEAVFunctionRef@AS2@GFx@Scaleform@@PEAVObjectInterface@234@PEAV1234@PEAVASStringContext@234@@Z=?Get__constructor__@ObjectInterface@AS2@GFx@Scaleform@@UEAA?AVFunctionRef@234@PEAVASStringContext@234@@Z")) // AS2 ObjectInterface::Get__constructor__
extern unsigned char DAT_14000a110[];
extern unsigned char DAT_14252e480[];
extern unsigned char DAT_14000d760[];
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e470(void **, void *, void *, void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { int FUN_14000e500(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void * FUN_14000e510(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { char const * FUN_14000e570(::Scaleform::GFx::AS2::AvmCharacter *, ::Scaleform::String *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e590(void **); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e630(::Scaleform::GFx::AS2::AvmCharacter *, ::Scaleform::GFx::InteractiveObject const *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e640(::Scaleform::GFx::AS2::AvmCharacter *, ::Scaleform::GFx::InteractiveObject const *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e670(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e680(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e690(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e6a0(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e6b0(::Scaleform::GFx::AS2::AvmCharacter const *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void * FUN_14000e6c0(void *, unsigned __int64); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e6d0(void *, ::Scaleform::GFx::InteractiveObject const *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e6e0(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e700(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void * FUN_14000e710(void *, unsigned __int64); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e720(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { unsigned __int64 FUN_14000e730(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e740(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { char const * FUN_14000e750(void *, ::Scaleform::String *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e760(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { unsigned __int64 FUN_14000e770(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e780(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void * FUN_14000e790(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { unsigned __int64 FUN_14000e7a0(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { unsigned __int64 FUN_14000e7b0(unsigned __int64); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e7c0(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e7d0(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e7e0(void *, ::Scaleform::GFx::InteractiveObject const *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e7f0(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { unsigned __int64 FUN_14000e800(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { unsigned __int64 FUN_14000e810(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e820(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { void FUN_14000e830(void *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { ::Scaleform::GFx::AS2::VideoObject * FUN_14000e880(::Scaleform::GFx::AS2::AvmCharacter *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { ::Scaleform::GFx::AS2::VideoObject * FUN_14000e890(::Scaleform::GFx::AS2::AvmCharacter *); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e8f0(void *, ::Scaleform::GFx::AS2::Environment *, ::Scaleform::GFx::ASString const &, ::Scaleform::GFx::AS2::Value const &, ::Scaleform::GFx::AS2::PropFlags const &); } } }
namespace Scaleform { namespace GFx { namespace AS2 { bool FUN_14000e9f0(void *, ::Scaleform::GFx::AS2::Environment *, ::Scaleform::GFx::ASString const &, ::Scaleform::GFx::AS2::Value *); } } }
char const * FUN_140019af0(void const *);
void * FUN_140019b60(void *, unsigned int);
void ** FUN_140019bd0(void **, void *);
char const * FUN_14001a040(void const *);
char const * FUN_14001a0b0(void const *);
void * FUN_14001a2f0(::Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, unsigned int);
void * FUN_14001a470(void *);
::Scaleform::GFx::AS3::InstanceTraits::CTraits * FUN_14001a5c0(::Scaleform::GFx::AS3::InstanceTraits::CTraits *, unsigned int);
void FUN_14001a760(void *, unsigned int, ::Scaleform::GFx::AS3::Value *);
void FUN_14001a800(unsigned __int64 *, unsigned char);
void FUN_14001a860(void *, ::Scaleform::GFx::AS3::Value *, ::Scaleform::GFx::AS3::InstanceTraits::Traits *);
char const * FUN_14001ae30(void const *);
void * FUN_14001aea0(void *, unsigned int);
void ** FUN_14001af10(void **, void *);
void FUN_140016b50(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016be0(void *, void *, void *, void *, int, ::Scaleform::GFx::AS3::Value *);
void FUN_140016fd0(void *, void *, void *, void *, unsigned int, unsigned char const *);
void FUN_140017020(void *, void *, void *, void *, unsigned int, unsigned char const *);
void FUN_140017070(void *, void *, void *, void *, unsigned int, unsigned char const *);
void FUN_140017470(void *, void *, void *, void *, unsigned int, unsigned char const *);
void FUN_140017520(void *, void *, void *, unsigned __int64, unsigned int, unsigned __int64 const *);
void FUN_140017670(void *, void *, void *, unsigned __int64, unsigned int, unsigned __int64 const *);
void FUN_1400182f0(void *, unsigned int const *);
void FUN_140018930(void *, unsigned int const *);
void FUN_140019890(void *, unsigned __int64 const *, unsigned __int64 const *);
extern unsigned char DAT_140002b00[];
extern unsigned char DAT_140007ba0[];
extern unsigned char DAT_140007d90[];
extern unsigned char DAT_140007da0[];
extern unsigned char DAT_140007db0[];
extern unsigned char DAT_140007dc0[];
extern unsigned char DAT_140007dd0[];
extern unsigned char DAT_140007de0[];
extern unsigned char DAT_140007df0[];
extern unsigned char DAT_140007e00[];
extern unsigned char DAT_140007e10[];
extern unsigned char DAT_140008250[];
extern unsigned char DAT_140009ef0[];
extern unsigned char DAT_140009f00[];
extern unsigned char DAT_140009f10[];
extern unsigned char DAT_140009f30[];
extern unsigned char DAT_14000a3a0[];
extern unsigned char DAT_14000a770[];
extern unsigned char DAT_14000ce70[];
extern unsigned char DAT_14000ce80[];
extern unsigned char DAT_14000ce90[];
extern unsigned char DAT_14000cea0[];
extern unsigned char DAT_14000ceb0[];
extern unsigned char DAT_14000d6e0[];
extern unsigned char DAT_14000d6f0[];
extern unsigned char DAT_14000d700[];
extern unsigned char DAT_14000d710[];
extern unsigned char DAT_14000d730[];
extern unsigned char DAT_14000daa0[];
extern unsigned char DAT_14000db10[];
extern unsigned char DAT_14000dbc0[];
extern unsigned char DAT_14000e1a0[];
extern unsigned char DAT_14000e370[];
extern unsigned char DAT_14000e380[];
extern unsigned char DAT_14000e3e0[];
extern unsigned char DAT_14000e3f0[];
extern unsigned char DAT_14000e400[];
extern unsigned char DAT_14000e4d0[];
extern unsigned char DAT_142300840[];
extern unsigned char DAT_1423dc0b0[];
extern unsigned char DAT_1423dcd60[];
extern unsigned char DAT_1423df420[];
extern unsigned char DAT_1423df430[];
extern unsigned char DAT_1423df460[];
extern unsigned char DAT_1423df4a0[];
extern unsigned char DAT_1423df580[];
extern unsigned char DAT_1423df590[];
extern unsigned char DAT_1423df5a0[];
extern unsigned char DAT_1423df5b0[];
extern unsigned char DAT_142442e10[];
extern unsigned char DAT_142443380[];
extern unsigned char DAT_1424e4290[];
extern unsigned char DAT_1424e42a0[];
extern unsigned char DAT_1424e8060[];
extern unsigned char DAT_1424eb250[];
extern unsigned char DAT_1424eb770[];
extern unsigned char DAT_1424ee6f0[];
extern unsigned char DAT_1424ee7f0[];
extern unsigned char DAT_1424eeca0[];
extern unsigned char DAT_1424effa0[];
extern unsigned char DAT_1424f0610[];
extern unsigned char DAT_1424f2400[];
extern unsigned char DAT_1424f4a40[];
extern unsigned char DAT_1424f7180[];
extern unsigned char DAT_1424f74d0[];
extern unsigned char DAT_1424fe610[];
extern unsigned char DAT_142500e50[];
extern unsigned char DAT_142501a60[];
extern unsigned char DAT_142504840[];
extern unsigned char DAT_142505f20[];
extern unsigned char DAT_142506ef0[];
extern unsigned char DAT_142507590[];
extern unsigned char DAT_1425084c0[];
extern unsigned char DAT_1425084d0[];
extern unsigned char DAT_142509990[];
extern unsigned char DAT_142509a80[];
extern unsigned char DAT_142509ca0[];
extern unsigned char DAT_142509d30[];
extern unsigned char DAT_142509d40[];
extern unsigned char DAT_142509da0[];
extern unsigned char DAT_142509dc0[];
extern unsigned char DAT_14250a5b0[];
extern unsigned char DAT_14250b360[];
extern unsigned char DAT_14250b3a0[];
extern unsigned char DAT_14250bbd0[];
extern unsigned char DAT_14250bc40[];
extern unsigned char DAT_14250be40[];
extern unsigned char DAT_14250c010[];
extern unsigned char DAT_14250c060[];
extern unsigned char DAT_14250c2e0[];
extern unsigned char DAT_14250cc20[];
extern unsigned char DAT_14250cc60[];
extern unsigned char DAT_14250d550[];
extern unsigned char DAT_14250d570[];
extern unsigned char DAT_14250d620[];
extern unsigned char DAT_14250d6f0[];
extern unsigned char DAT_14250ee20[];
extern unsigned char DAT_14250f760[];
extern unsigned char DAT_14250f820[];
extern unsigned char DAT_14250f850[];
extern unsigned char DAT_142510a30[];
extern unsigned char DAT_142510d10[];
extern unsigned char DAT_142510d40[];
extern unsigned char DAT_142510e60[];
extern unsigned char DAT_1425117e0[];
extern unsigned char DAT_1425117f0[];
extern unsigned char DAT_142511810[];
extern unsigned char DAT_142512620[];
extern unsigned char DAT_142514320[];
extern unsigned char DAT_142515190[];
extern unsigned char DAT_142516630[];
extern unsigned char DAT_1425185d0[];
extern unsigned char DAT_142518990[];
extern unsigned char DAT_14251a100[];
extern unsigned char DAT_14251a3a0[];
extern unsigned char DAT_14251a820[];
extern unsigned char DAT_14251ac20[];
extern unsigned char DAT_14251ac30[];
extern unsigned char DAT_14251ace0[];
extern unsigned char DAT_14251cab0[];
extern unsigned char DAT_14251ced0[];
extern unsigned char DAT_14251cfc0[];
extern unsigned char DAT_14251f3a0[];
extern unsigned char DAT_14251f540[];
extern unsigned char DAT_14251f550[];
extern unsigned char DAT_14251f560[];
extern unsigned char DAT_14251f5c0[];
extern unsigned char DAT_14251f5d0[];
extern unsigned char DAT_1425227d0[];
extern unsigned char DAT_142525c90[];
extern unsigned char DAT_1425265f0[];
extern unsigned char DAT_142526720[];
extern unsigned char DAT_1425287f0[];
extern unsigned char DAT_142528800[];
extern unsigned char DAT_142528a50[];
extern unsigned char DAT_142528d90[];
extern unsigned char DAT_142529f50[];
extern unsigned char DAT_14252b580[];
extern unsigned char DAT_14252c4e0[];
extern unsigned char DAT_14252c9c0[];
extern unsigned char DAT_14252c9d0[];
extern unsigned char DAT_14252c9e0[];
extern unsigned char DAT_1425f1ae0[];
extern unsigned char DAT_1425f1ca0[];
extern unsigned char DAT_1425f1d50[];
extern unsigned char DAT_1425f1d70[];
extern unsigned char DAT_1425f1db0[];
extern unsigned char DAT_1425f1f60[];
extern unsigned char DAT_1425f2040[];
extern unsigned char DAT_1425f2140[];
extern unsigned char DAT_1425f2210[];
extern unsigned char DAT_1425f22e0[];
extern unsigned char DAT_1425f23e0[];
extern unsigned char DAT_1425f25c0[];
extern unsigned char DAT_1425f2600[];
extern unsigned char DAT_1425f2760[];
extern unsigned char DAT_1425f29a0[];
extern unsigned char DAT_1425f2a40[];
extern unsigned char DAT_1425f2cd0[];
extern unsigned char DAT_1425f2d40[];
extern unsigned char DAT_1425f2db0[];
extern unsigned char DAT_1425f2e20[];
extern unsigned char DAT_1425f2e90[];
extern unsigned char DAT_1425f2f00[];
extern unsigned char DAT_1425f2f70[];
extern unsigned char DAT_1425f2fe0[];
extern unsigned char DAT_1425f3390[];
extern unsigned char DAT_1425f33e0[];
extern unsigned char DAT_1425f3980[];
extern unsigned char DAT_1425f3de0[];
extern unsigned char DAT_1425f40a0[];
extern unsigned char DAT_1425f41b0[];
extern unsigned char DAT_1425f41f0[];
extern unsigned char DAT_1425f4460[];
extern unsigned char DAT_1425f4d70[];
extern unsigned char DAT_1425f5010[];
extern unsigned char DAT_1425f5530[];
extern unsigned char DAT_1425f56c0[];
extern unsigned char DAT_1425f57a0[];
extern unsigned char DAT_1425f5e70[];
extern unsigned char DAT_1425f6130[];
extern unsigned char DAT_1425f64c0[];
extern unsigned char DAT_1425f6690[];
extern unsigned char DAT_1425f6760[];
extern unsigned char DAT_1425f69f0[];
extern unsigned char DAT_1425f6bc0[];
extern unsigned char DAT_1425f6c90[];
extern unsigned char DAT_1425f6f20[];
extern unsigned char DAT_1425f6fe0[];
extern unsigned char DAT_1425f75c0[];
extern unsigned char DAT_1425f7af0[];
extern unsigned char DAT_1425f7fc0[];
extern unsigned char DAT_1425f8480[];
extern unsigned char DAT_1425f8540[];
extern unsigned char DAT_1425f8550[];
extern unsigned char DAT_1425f85e0[];
extern unsigned char DAT_1425f8630[];
extern unsigned char DAT_1425f8690[];
extern unsigned char DAT_1425f86d0[];
extern unsigned char DAT_1425f8760[];
extern unsigned char DAT_1425f8870[];
extern unsigned char DAT_1425f8880[];
extern unsigned char DAT_1425f88e0[];
extern unsigned char DAT_1425f8940[];
extern "C" int __cdecl _purecall(void); // 0x14280ef52 vftable pure-virtual slot
extern unsigned char DAT_1429386e0[];
extern unsigned char DAT_1429388e0[];
extern unsigned char DAT_14293ff70[];
extern unsigned char DAT_142940160[];
extern unsigned char DAT_1429411f0[];
extern unsigned char DAT_1429413c0[];
extern unsigned char DAT_142942e70[];
extern unsigned char DAT_1429448c0[];
extern unsigned char DAT_142944950[];
extern unsigned char DAT_1429493c0[];
extern unsigned char DAT_142949400[];
extern unsigned char DAT_142949860[];
extern unsigned char DAT_14294ab50[];
extern unsigned char DAT_14294afb0[];
extern unsigned char DAT_14294f7d0[];
extern unsigned char DAT_142953280[];
extern unsigned char DAT_142955080[];
extern unsigned char DAT_142956b10[];
extern unsigned char DAT_142956ca0[];
extern unsigned char DAT_14295d840[];
extern unsigned char DAT_14295d970[];
extern unsigned char DAT_142962310[];
extern unsigned char DAT_1429623a0[];
extern unsigned char DAT_142962bb0[];
extern unsigned char DAT_142965510[];
extern unsigned char DAT_1429867f0[];
extern unsigned char DAT_142988930[];
extern unsigned char DAT_1429889c0[];
extern unsigned char DAT_142988bb0[];
extern unsigned char DAT_14298ab80[];
extern unsigned char DAT_14298cc70[];
extern unsigned char DAT_14298dcb0[];
extern unsigned char DAT_142991140[];
extern unsigned char DAT_142991170[];
extern unsigned char DAT_1429926f0[];
extern unsigned char DAT_142992780[];
extern unsigned char DAT_142994660[];
extern unsigned char DAT_1429947f0[];
extern unsigned char DAT_142994bb0[];
extern unsigned char DAT_142994c50[];
namespace Scaleform {
namespace GFx {
namespace AS3 {
struct ClassInfo
{
    unsigned long long Flags;
    const char* Name;
    const char* PkgName;
    const ClassInfo* Parent;
    const void* Factory;
    unsigned char ClassMethodNum;
    unsigned char ClassMemberNum;
    unsigned char InstanceMethodNum;
    unsigned char InstanceMemberNum;
    const void* ClassMethod;
    const void* ClassMember;
    const void* InstanceMethod;
    const void* InstanceMember;
};
namespace fl_net { alignas(16) extern const ClassInfo NetStreamCI; }
namespace fl_media { alignas(16) extern const ClassInfo VideoCI; }
namespace fl { alignas(16) extern const ClassInfo ObjectCI; alignas(16) extern const ClassInfo BooleanCI; alignas(16) extern const ClassInfo uintCI; alignas(16) extern const ClassInfo NumberCI; }
namespace fl_display { alignas(16) extern const ClassInfo DisplayObjectCI; }
namespace fl_events { alignas(16) extern const ClassInfo EventDispatcherCI; }
namespace fl_media { alignas(16) extern const ClassInfo SoundTransformCI; }
}
}
}
void FUN_14000e0c0();

#pragma pack(push, 1)
struct Sd_1431b6878 {
    unsigned char ba8[0x1b8];
    const void* p260;
    const void* p268;
    const void* p270;
    unsigned char b278[0x10];
    const void* p288;
    const void* p290;
    const void* p298;
    unsigned char b2a0[0x10];
    const void* p2b0;
    unsigned char b2b8[0x8];
    const void* p2c0;
    unsigned char b2c8[0x10];
    const void* p2d8;
    const void* p2e0;
    const void* p2e8;
    unsigned char b2f0[0x10];
    const void* p300;
    const void* p308;
    const void* p310;
    unsigned char b318[0x10];
    const void* p328;
    const void* p330;
    const void* p338;
    unsigned char b340[0x10];
    const void* p350;
    unsigned char b358[0x8];
    const void* p360;
    unsigned char b368[0x10];
    const void* p378;
    const void* p380;
    const void* p388;
    unsigned char b390[0x10];
    const void* p3a0;
    unsigned char b3a8[0x8];
    const void* p3b0;
    unsigned char b3b8[0x10];
    const void* p3c8;
    const void* p3d0;
    const void* p3d8;
    unsigned char b3e0[0x10];
    const void* p3f0;
    const void* p3f8;
    const void* p400;
    unsigned char b408[0x10];
    const void* p418;
    const void* p420;
    const void* p428;
    unsigned char b430[0x10];
    const void* p440;
    const void* p448;
    const void* p450;
    unsigned char b458[0x10];
    const void* p468;
    unsigned char b470[0x8];
    const void* p478;
    unsigned char b480[0x10];
    const void* p490;
    const void* p498;
    const void* p4a0;
    unsigned char b4a8[0x10];
    const void* p4b8;
    unsigned char b4c0[0x8];
    const void* p4c8;
    unsigned char b4d0[0x10];
    const void* p4e0;
    unsigned char b4e8[0x8];
    const void* p4f0;
    unsigned char b4f8[0x10];
    const void* p508;
    unsigned char b510[0x8];
    const void* p518;
    unsigned char b520[0x10];
    const void* p530;
    unsigned char b538[0x8];
    const void* p540;
    unsigned char b548[0x10];
    const void* p558;
    unsigned char b560[0x8];
    const void* p568;
    unsigned char b570[0x10];
    const void* p580;
    unsigned char b588[0x8];
    const void* p590;
    unsigned char b598[0x10];
    const void* p5a8;
    unsigned char b5b0[0x8];
    const void* p5b8;
    unsigned char b5c0[0x10];
    const void* p5d0;
    unsigned char b5d8[0x8];
    const void* p5e0;
    unsigned char b5e8[0x10];
    const void* p5f8;
    unsigned char b600[0x8];
    const void* p608;
    unsigned char b610[0x10];
    const void* p620;
    unsigned char b628[0x8];
    const void* p630;
    unsigned char b638[0x10];
    const void* p648;
    unsigned char b650[0x8];
    const void* p658;
    unsigned char b660[0x10];
    const void* p670;
    unsigned char b678[0x8];
    const void* p680;
    unsigned char b688[0x10];
    const void* p698;
    unsigned char b6a0[0x8];
    const void* p6a8;
    unsigned char b6b0[0x10];
    const void* p6c0;
    unsigned char b6c8[0x8];
    const void* p6d0;
    unsigned char b6d8[0x10];
    const void* p6e8;
    const void* p6f0;
    const void* p6f8;
    unsigned char b700[0x10];
    const void* p710;
    unsigned char b718[0x8];
    const void* p720;
    unsigned char b728[0x10];
    const void* p738;
    const void* p740;
    const void* p748;
    unsigned char b750[0x10];
    const void* p760;
    const void* p768;
    const void* p770;
    unsigned char b778[0x10];
    const void* p788;
    unsigned char b790[0x8];
    const void* p798;
    unsigned char b7a0[0x10];
    const void* p7b0;
    const void* p7b8;
    const void* p7c0;
    unsigned char b7c8[0x10];
    const void* p7d8;
    unsigned char b7e0[0x8];
    const void* p7e8;
    unsigned char b7f0[0x10];
    const void* p800;
    const void* p808;
    const void* p810;
    unsigned char b818[0x10];
    const void* p828;
    unsigned char b830[0x8];
    const void* p838;
    unsigned char b840[0x10];
    const void* p850;
    const void* p858;
    const void* p860;
    unsigned char b868[0x10];
    const void* p878;
    unsigned char b880[0x8];
    const void* p888;
    unsigned char b890[0x10];
    const void* p8a0;
    const void* p8a8;
    const void* p8b0;
    unsigned char b8b8[0x10];
    const void* p8c8;
    unsigned char b8d0[0x8];
    const void* p8d8;
    unsigned char b8e0[0x10];
    const void* p8f0;
    unsigned char b8f8[0x8];
    const void* p900;
    unsigned char b908[0x10];
    const void* p918;
    unsigned char b920[0x8];
    const void* p928;
    unsigned char b930[0x10];
    const void* p940;
    unsigned char b948[0x8];
    const void* p950;
    unsigned char b958[0x10];
    const void* p968;
    unsigned char b970[0x8];
    const void* p978;
    unsigned char b980[0x10];
};
#pragma pack(pop)

extern Sd_1431b6878 DAT_1431b6878;

// 0x1431b4be0
extern void* DAT_1431b4be0[];
alignas(16) void* DAT_1431b4be0[16] = {
    (void*)&FUN_140002c10,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    DAT_140002b00,
    DAT_142300840,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&FUN_140002b30,
    (void*)&FUN_140002bb0,
    (void*)&FUN_140002cc0,
};
// 0x1431b4c60
extern void* DAT_1431b4c60[];
alignas(16) void* DAT_1431b4c60[16] = {
    (void*)&FUN_140002d20,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    (void*)&_purecall,
    0,
};
// 0x1431b4ce0
extern void* DAT_1431b4ce0[];
alignas(16) void* DAT_1431b4ce0[15] = {
    (void*)&FUN_140002e40,
    (void*)&FUN_140002d90,
    (void*)&FUN_140002da0,
    (void*)&FUN_140002930,
    (void*)&FUN_140002db0,
    (void*)&FUN_140002950,
    (void*)&FUN_140002dc0,
    (void*)&FUN_140002dd0,
    (void*)&FUN_140002de0,
    (void*)&FUN_140002df0,
    (void*)&FUN_140002960,
    (void*)&FUN_140002e00,
    (void*)&FUN_140002e10,
    (void*)&FUN_140002e20,
    (void*)&FUN_140002980,
};
// 0x1431b4d58: the string bytes after the vftable
alignas(8) unsigned char DAT_1431b4d58[0x28] = {
    0x73, 0x65, 0x74, 0x42, 0x75, 0x66, 0x66, 0x65, 0x72, 0x54, 0x69, 0x6d, 0x65, 0x00, 0x00, 0x00,
    0x70, 0x6c, 0x61, 0x79, 0x00, 0x00, 0x00, 0x00, 0x70, 0x61, 0x75, 0x73, 0x65, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431b4d80
extern Scaleform::GFx::AS2::NameFunction DAT_1431b4d80[];
alignas(16) Scaleform::GFx::AS2::NameFunction DAT_1431b4d80[6] = {
    { "close", &::Scaleform::GFx::AS2::NetStreamProto::Close },
    { "pause", &::Scaleform::GFx::AS2::NetStreamProto::Pause },
    { "play", &::Scaleform::GFx::AS2::NetStreamProto::Play },
    { "setBufferTime", &::Scaleform::GFx::AS2::NetStreamProto::SetBufferTime },
    { "seek", &::Scaleform::GFx::AS2::NetStreamProto::Seek },
    { 0, 0 },
};
void* PTR_s_attachVideo_1431b5800 = (void*)"attachVideo";       // 0x1431b5800
// 0x1431b6060 is Video02Character's vftable, emitted by sfr_video_02
// 0x1431b63f8 is Video02Character's vftable, emitted by sfr_video_02
void* PTR_s_connect_1431b6410 = (void*)"connect";               // 0x1431b6410
// 0x1431b6878
alignas(8) Sd_1431b6878 DAT_1431b6878 = {
    {
        0x66, 0x6c, 0x61, 0x73, 0x68, 0x2e, 0x6e, 0x65, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x4e, 0x65, 0x74, 0x53, 0x74, 0x72, 0x65, 0x61, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x72, 0x65, 0x73, 0x65, 0x74, 0x44, 0x52, 0x4d, 0x56, 0x6f, 0x75, 0x63, 0x68, 0x65, 0x72, 0x73,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x70, 0x65, 0x6e, 0x54, 0x69, 0x6d, 0x65,
        0x6f, 0x75, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x4f, 0x66,
        0x46, 0x72, 0x61, 0x6d, 0x65, 0x50, 0x6f, 0x6f, 0x6c, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x72, 0x65, 0x6c, 0x6f, 0x61, 0x64, 0x54, 0x68, 0x72, 0x65, 0x73, 0x68, 0x6f, 0x6c, 0x64, 0x54,
        0x69, 0x6d, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x75, 0x62, 0x53, 0x6f, 0x75, 0x6e, 0x64,
        0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x6f, 0x72, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x74, 0x6f, 0x67, 0x67, 0x6c, 0x65, 0x50, 0x61, 0x75, 0x73, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x73, 0x65, 0x74, 0x44, 0x52, 0x4d, 0x41, 0x75, 0x74, 0x68, 0x65, 0x6e, 0x74, 0x69, 0x63, 0x61,
        0x74, 0x69, 0x6f, 0x6e, 0x43, 0x72, 0x65, 0x64, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x73, 0x00,
        0x73, 0x65, 0x6e, 0x64, 0x00, 0x00, 0x00, 0x00, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x56,
        0x69, 0x64, 0x65, 0x6f, 0x46, 0x50, 0x53, 0x00, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x56,
        0x69, 0x64, 0x65, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x41,
        0x75, 0x64, 0x69, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x70, 0x75, 0x62, 0x6c, 0x69, 0x73, 0x68, 0x00,
        0x61, 0x74, 0x74, 0x61, 0x63, 0x68, 0x43, 0x61, 0x6d, 0x65, 0x72, 0x61, 0x00, 0x00, 0x00, 0x00,
        0x61, 0x74, 0x74, 0x61, 0x63, 0x68, 0x41, 0x75, 0x64, 0x69, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x73, 0x6f, 0x75, 0x6e, 0x64, 0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x6f, 0x72, 0x6d, 0x00, 0x00,
        0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x45, 0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0x00, 0x00,
        0x6c, 0x69, 0x76, 0x65, 0x44, 0x65, 0x6c, 0x61, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x63, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x46, 0x50, 0x53, 0x00, 0x00, 0x63, 0x6c, 0x69, 0x65,
        0x6e, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x68, 0x65, 0x63, 0x6b, 0x50, 0x6f, 0x6c,
        0x69, 0x63, 0x79, 0x46, 0x69, 0x6c, 0x65, 0x00, 0x62, 0x79, 0x74, 0x65, 0x73, 0x54, 0x6f, 0x74,
        0x61, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x79, 0x74, 0x65, 0x73, 0x4c, 0x6f, 0x61,
        0x64, 0x65, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x75, 0x66, 0x66, 0x65, 0x72, 0x54, 0x69,
        0x6d, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x75, 0x66, 0x66, 0x65, 0x72, 0x4c, 0x65,
        0x6e, 0x67, 0x74, 0x68, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015d20,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "bufferLength",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015da0,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "bufferTime",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015e20,
    {0},
    "bufferTime",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015eb0,
    &::Scaleform::GFx::AS3::fl::uintCI,
    "bytesLoaded",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015f20,
    &::Scaleform::GFx::AS3::fl::uintCI,
    "bytesTotal",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015f90,
    &::Scaleform::GFx::AS3::fl::BooleanCI,
    "checkPolicyFile",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016000,
    {0},
    "checkPolicyFile",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140019d70,
    &::Scaleform::GFx::AS3::fl::ObjectCI,
    "client",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016060,
    {0},
    "client",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016100,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "currentFPS",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016180,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "liveDelay",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016200,
    &::Scaleform::GFx::AS3::fl::uintCI,
    "objectEncoding",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140019e20,
    &::Scaleform::GFx::AS3::fl_media::SoundTransformCI,
    "soundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016fd0,
    {0},
    "soundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016270,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "time",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017020,
    {0},
    "attachAudio",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017470,
    {0},
    "attachCamera",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400162f0,
    {0},
    "close",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400133e0,
    {0},
    "pause",
    {0},
    (const void*)&FUN_140013230,
    {0},
    "play",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017520,
    {0},
    "publish",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016350,
    {0},
    "receiveAudio",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400163b0,
    {0},
    "receiveVideo",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016410,
    {0},
    "receiveVideoFPS",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013400,
    {0},
    "resume",
    {0},
    (const void*)&FUN_1400164a0,
    {0},
    "seek",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013250,
    {0},
    "send",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017670,
    {0},
    "setDRMAuthenticationCredentials",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013420,
    {0},
    "togglePause",
    {0},
    (const void*)&FUN_140016530,
    &::Scaleform::GFx::AS3::fl::BooleanCI,
    "loop",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400165a0,
    {0},
    "loop",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016600,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "currentFrame",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016680,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "audioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016700,
    {0},
    "audioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016790,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "subAudioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016810,
    {0},
    "subAudioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400168a0,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "voiceTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016920,
    {0},
    "voiceTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400169b0,
    &::Scaleform::GFx::AS3::fl::NumberCI,
    "subtitleTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016a30,
    {0},
    "subtitleTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140019ed0,
    &::Scaleform::GFx::AS3::fl_media::SoundTransformCI,
    "subSoundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017070,
    {0},
    "subSoundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016ac0,
    {0},
    "reloadThresholdTime",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016b50,
    {0},
    "numberOfFramePools",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016be0,
    {0},
    "openTimeout",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013440,
    {0},
    "resetDRMVouchers",
    {0},
};
// 0x1431b7160
alignas(16) const Scaleform::GFx::AS3::ClassInfo Scaleform::GFx::AS3::fl_net::NetStreamCI = {
    0x1,
    "NetStream",
    "flash.net",
    &::Scaleform::GFx::AS3::fl_events::EventDispatcherCI,
    (const void*)&FUN_140019bd0,
    0x01, 0x00, 0x2d, 0x00,
    (const unsigned char*)&DAT_1431b6878 + 0x8c0,
    0,
    (const unsigned char*)&DAT_1431b6878 + 0x1b8,
    0,
};
// 0x1431b71b0
extern void* DAT_1431b71b0[];
alignas(16) void* DAT_1431b71b0[17] = {
    (void*)DAT_142503fa0,
    DAT_1423df5a0,
    (void*)&FUN_140012ef0,
    DAT_1423df460,
    (void*)&FUN_140014a80,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bbd0,
    DAT_14250d570,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117e0,
    (void*)&FUN_1400155d0,
    DAT_1424e42a0,
    DAT_14252e480,
};
// 0x1431b7260
extern void* DAT_1431b7260[];
alignas(16) void* DAT_1431b7260[26] = {
    (void*)DAT_142503800,
    DAT_1423df5b0,
    (void*)&FUN_140012f40,
    DAT_1423df430,
    (void*)&FUN_140014b10,
    DAT_1423df420,
    DAT_142528a50,
    DAT_14250cc60,
    DAT_142509a80,
    DAT_1424f4a40,
    DAT_1424ee6f0,
    DAT_1424e4290,
    DAT_1424f0610,
    DAT_1423df590,
    DAT_1424e8060,
    DAT_1423df580,
    DAT_14250c010,
    DAT_14250be40,
    DAT_14250c060,
    DAT_142500e50,
    DAT_142512620,
    DAT_14251cfc0,
    DAT_14251ced0,
    DAT_1424eb770,
    DAT_142511810,
    DAT_142516630,
};
// 0x1431b7360
extern void* DAT_1431b7360[];
alignas(16) void* DAT_1431b7360[21] = {
    (void*)&FUN_140012e10,
    DAT_1423df5b0,
    (void*)&FUN_1400141a0,
    DAT_1423df430,
    (void*)&FUN_140015590,
    DAT_1423df420,
    DAT_142528a50,
    DAT_14250cc60,
    DAT_142509a80,
    DAT_1424f4a40,
    DAT_1424ee7f0,
    (void*)&FUN_140015c40,
    (void*)DAT_1424f0700,
    DAT_1423df590,
    DAT_1424e8060,
    DAT_1423df580,
    DAT_14250c010,
    DAT_14250be40,
    DAT_14250c060,
    DAT_142500e50,
    DAT_142512620,
};
// 0x1431b7858
extern void* DAT_1431b7858[];
alignas(8) void* DAT_1431b7858[5] = {
    (void*)&FUN_140015c00,
    (void*)&FUN_140019890,
    (void*)&FUN_1400182f0,
    (void*)&FUN_140018930,
    (void*)&FUN_140014900,
};
// 0x1431b7900
extern void* DAT_1431b7900[];
alignas(16) void* DAT_1431b7900[15] = {
    (void*)DAT_142503f50,
    DAT_1423df5a0,
    (void*)&FUN_140019af0,
    DAT_1423df4a0,
    (void*)&FUN_140019b60,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bc40,
    DAT_14250d550,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117f0,
    DAT_1424effa0,
};
// Video instance thunks begin at 0x1431b79e0, beyond the preceding vtable.
namespace Scaleform { namespace GFx { namespace AS3 { struct ClassInfo; namespace fl { alignas(16) extern const ClassInfo int_CI; } } } }
void FUN_14001a9b0(void*, void*, void*, unsigned int*);
void FUN_14001aa20(void*, void*, void*, unsigned __int64, unsigned int, void*);
void FUN_14001aa90(void*, void*, void*, unsigned int*);
void FUN_14001ab00(void*, void*, void*, unsigned __int64, unsigned int, void*);
void FUN_14001ab60(void*, void*, void*, unsigned int*);
void FUN_14001abd0(void*, void*, void*, unsigned int*);
void FUN_14001ac80(void*, void*, void*, unsigned __int64, unsigned int, const unsigned char*);
void FUN_14001acd0(void*, void*, void*, unsigned __int64, unsigned int, const unsigned char*);
void FUN_14001a180(void*, void*, void*, void*);
struct Sd_1431b79e0 { const void* f; const void* t; const char* n; const void* ns; unsigned long long k; };
alignas(16) extern const Sd_1431b79e0 DAT_1431b79e0[9];
alignas(16) const Sd_1431b79e0 DAT_1431b79e0[9] = {
    {(const void*)&FUN_14001a9b0, &::Scaleform::GFx::AS3::fl::int_CI, "deblocking", nullptr, 0x1ull},
    {(const void*)&FUN_14001aa20, nullptr, "deblocking", nullptr, 0x4aull},
    {(const void*)&FUN_14001aa90, &::Scaleform::GFx::AS3::fl::BooleanCI, "smoothing", nullptr, 0x1ull},
    {(const void*)&FUN_14001ab00, nullptr, "smoothing", nullptr, 0x4aull},
    {(const void*)&FUN_14001ab60, &::Scaleform::GFx::AS3::fl::int_CI, "videoHeight", nullptr, 0x1ull},
    {(const void*)&FUN_14001abd0, &::Scaleform::GFx::AS3::fl::int_CI, "videoWidth", nullptr, 0x1ull},
    {(const void*)&FUN_14001ac80, nullptr, "attachCamera", nullptr, 0x48ull},
    {(const void*)&FUN_14001acd0, nullptr, "attachNetStream", nullptr, 0x48ull},
    {(const void*)&FUN_14001a180, nullptr, "clear", nullptr, 0x0ull},
};
// 0x1431b7b50
alignas(16) const Scaleform::GFx::AS3::ClassInfo Scaleform::GFx::AS3::fl_media::VideoCI = {
    0x1,
    "Video",
    "flash.media",
    &::Scaleform::GFx::AS3::fl_display::DisplayObjectCI,
    (const void*)&FUN_14001af10,
    0x00, 0x00, 0x09, 0x00,
    0,
    0,
    &DAT_1431b79e0[0],
    0,
};
// 0x1431b7ba0
extern void* DAT_1431b7ba0[];
alignas(16) void* DAT_1431b7ba0[22] = {
    DAT_142442e10,
    DAT_1423df5b0,
    (void*)&FUN_14001a040,
    DAT_142443380,
    (void*)&FUN_14001a2f0,
    DAT_1423df420,
    DAT_142528a50,
    DAT_14250cc60,
    DAT_142509a80,
    DAT_1424f4a40,
    DAT_1424ee7f0,
    (void*)&FUN_14001a760,
    (void*)DAT_1424f0700,
    (void*)&FUN_14001a800,
    DAT_1424e8060,
    DAT_1423df580,
    DAT_14250c010,
    DAT_14250be40,
    DAT_14250c060,
    DAT_142500e50,
    DAT_142512620,
    (void*)&FUN_14001a470,
};
// 0x1431b7c70
extern void* DAT_1431b7c70[];
alignas(16) void* DAT_1431b7c70[17] = {
    (void*)DAT_142503fa0,
    DAT_1423df5a0,
    (void*)&FUN_14001a0b0,
    DAT_1423df460,
    (void*)&FUN_14001a5c0,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bbd0,
    DAT_14250d570,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117e0,
    (void*)&FUN_14001a860,
    DAT_1424e42a0,
    DAT_14252e480,
};
// 0x1431b7d50
extern void* DAT_1431b7d50[];
alignas(16) void* DAT_1431b7d50[15] = {
    (void*)DAT_142503f50,
    DAT_1423df5a0,
    (void*)&FUN_14001ae30,
    DAT_1423df4a0,
    (void*)&FUN_14001aea0,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bc40,
    DAT_14250d550,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117f0,
    DAT_1424effa0,
};

#pragma comment(linker, "/alternatename:?DAT_1431b5300@@3PEAXEA=??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@")
#pragma comment(linker, "/alternatename:?DAT_1431b5310@@3PEAXEA=??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@")
#pragma comment(linker, "/alternatename:?DAT_1431b53c0@@3PEAXEA=??_7?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@")
#pragma comment(linker, "/alternatename:?DAT_140002b00@@3PAEA=?GetSoundChannel@VideoSoundStream@Video@GFx@Scaleform@@UEAAPEAVSoundChannel@Sound@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_142300840@@3PAEA=?SetSpatialInfo@VideoSoundStream@Video@GFx@Scaleform@@UEAAXQEBV?$Array@UVector@SoundChannel@Sound@Scaleform@@$01UArrayDefaultPolicy@4@@4@@Z")
#pragma comment(linker, "/alternatename:?DAT_1423df420@@3PAEA=?Finalize_GC@?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df430@@3PAEA=?GetAS3ObjectName@Object@AS3@GFx@Scaleform@@UEBA?AVString@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_1423df460@@3PAEA=?GetAS3ObjectName@Traits@AS3@GFx@Scaleform@@UEBA?AVString@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_1423df4a0@@3PAEA=?GetAS3ObjectName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVString@5@XZ")
#pragma comment(linker, "/alternatename:?DAT_14252e480@@3PAEA=?SupportsInterface@CTraits@InstanceTraits@AS3@GFx@Scaleform@@UEBA_NAEBVTraits@2345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1423df580@@3PAEA=?Unk15@Object@AS3@GFx@Scaleform@@UEAAPEAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df590@@3PAEA=?InitInstance@Object@AS3@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1423df5a0@@3PAEA=?IsAS3Object@?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df5b0@@3PAEA=?IsAS3Object@Object@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142442e10@@3PAEA=?ForEachChild_GC@DisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@456@P6AX0PEAPEBV?$RefCountBaseGC@$0BED@@456@@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142443380@@3PAEA=?GetAS3ObjectName@DisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@UEBA?AVString@6@XZ")
#pragma comment(linker, "/alternatename:?DAT_1424e4290@@3PAEA=??1CheckResult@AS3@GFx@Scaleform@@QEAA@XZ")
#pragma comment(linker, "/alternatename:?DAT_1424e42a0@@3PAEA=?AS3Constructor@Traits@InstanceTraits@AS3@GFx@Scaleform@@UEBAXAEBV1345@AEBVValue@345@IPEBV6345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424e8060@@3PAEA=?AddDynamicSlotValuePair@Object@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@0W4Attribute@SlotInfo@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424eb770@@3PAEA=?ApplyTypeArgs@Class@AS3@GFx@Scaleform@@UEAAAEAV1234@IPEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424ee6f0@@3PAEA=?Call@Class@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@AEAV5234@IQEBV5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424ee7f0@@3PAEA=?Call@Object@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@AEAV5234@IQEBV5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424effa0@@3PAEA=?Coerce@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA_NAEBVValue@345@AEAV6345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f0610@@3PAEA=?Construct@Class@AS3@GFx@Scaleform@@UEAAXAEAVValue@234@IPEBV5234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f4a40@@3PAEA=?DeleteProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142500e50@@3PAEA=?FindDynamicSlot@Object@AS3@GFx@Scaleform@@UEAA?AVPropRef@234@AEBVMultiname@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142509a80@@3PAEA=?GetDynamicProperty@Object@AS3@GFx@Scaleform@@UEAAXVAbsoluteIndex@234@AEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142509ca0@@3PAEA=?GetFilePtr@Traits@AS3@GFx@Scaleform@@UEBAPEAVVMAbcFile@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142509d30@@3PAEA=?GetFixedMemSize@Traits@AS3@GFx@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_14250a5b0@@3PAEA=?GetGlobalObjectScript@Traits@AS3@GFx@Scaleform@@UEBAPEAVGlobalObjectScript@fl@Instances@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250bbd0@@3PAEA=?GetName@CTraits@InstanceTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250bc40@@3PAEA=?GetName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250be40@@3PAEA=?GetNextDynPropIndex@Object@AS3@GFx@Scaleform@@UEBA?AVGlobalSlotIndex@234@V5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c010@@3PAEA=?GetNextPropertyName@Object@AS3@GFx@Scaleform@@UEBAXAEAVValue@234@VGlobalSlotIndex@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c060@@3PAEA=?GetNextPropertyValue@Object@AS3@GFx@Scaleform@@UEAAXAEAVValue@234@VGlobalSlotIndex@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250cc60@@3PAEA=?GetProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@AEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250d550@@3PAEA=?GetQualifiedName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@W4QNameFormat@1345@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250d570@@3PAEA=?GetQualifiedName@Traits@InstanceTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@W4QNameFormat@1345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425117e0@@3PAEA=?InitOnDemand@Traits@AS3@GFx@Scaleform@@MEBAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425117f0@@3PAEA=?InitOnDemand@Traits@ClassTraits@AS3@GFx@Scaleform@@MEBAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142511810@@3PAEA=?InitPrototype@Class@AS3@GFx@Scaleform@@UEBAXAEAVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142512620@@3PAEA=?InitializeOnDemand@Object@AS3@GFx@Scaleform@@UEAAPEBVSlotInfo@234@PEBV5234@AEBVASString@34@AEBVNamespace@Instances@234@AEA_K@Z")
#pragma comment(linker, "/alternatename:?DAT_142514320@@3PAEA=?IsGlobal@Traits@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142516630@@3PAEA=?MakePrototype@Class@AS3@GFx@Scaleform@@UEBA?AV?$Pickable@VObject@AS3@GFx@Scaleform@@@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_14251ced0@@3PAEA=?PostInit@Class@AS3@GFx@Scaleform@@UEBAXAEBVValue@234@IPEBV5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14251cfc0@@3PAEA=?PreInit@Class@AS3@GFx@Scaleform@@UEBA?AVCheckResult@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142528a50@@3PAEA=?SetProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14252c4e0@@3PAEA=?SetupSlotValues@Traits@AS3@GFx@Scaleform@@UEBA?AVCheckResult@234@AEAVObject@234@@Z")

#endif // MS2_HOOK_DLL
