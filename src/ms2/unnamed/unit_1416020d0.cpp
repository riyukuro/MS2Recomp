// Recovered Nexon Messenger STL helpers from unit_1416020d0.
// MS2-UNIT: unit_1416020d0
// MS2-RANGE: 0x1416020d0-0x1416088c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/unnamed/unk_stlglue.h"
#include <cstring>
#include <new>
#include <stdexcept>

extern void FUN_141602830(void*, void*);
extern void* FUN_1415dbda0(void*);

// MS2-FUNCTIONAL: returns the recovered opaque vector storage reference.
Unk_StlElem<224>*& FUN_1416035c0(void* p) { return *reinterpret_cast<Unk_StlElem<224>**>(p); }
// MS2-PIN: ?FUN_1416035c0@@YAAEAPEAU?$Unk_StlElem@$0OA@@@PEAX@Z 0x1416035c0

// MS2-FUNCTIONAL: returns the recovered opaque vector storage reference.
Unk_StlElem<104>*& FUN_1416037c0(void* p) { return *reinterpret_cast<Unk_StlElem<104>**>(p); }
// MS2-PIN: ?FUN_1416037c0@@YAAEAPEAU?$Unk_StlElem@$0GI@@@PEAX@Z 0x1416037c0

// MS2-FUNCTIONAL: returns the recovered opaque vector storage reference.
Unk_StlElem<224>*& FUN_141603b80(void* p) { return *reinterpret_cast<Unk_StlElem<224>**>(p); }
// MS2-PIN: ?FUN_141603b80@@YAAEAPEAU?$Unk_StlElem@$0OA@@@PEAX@Z 0x141603b80

// MS2-FUNCTIONAL: returns the recovered opaque vector storage reference.
Unk_StlElem<104>*& FUN_141603d80(void* p) { return *reinterpret_cast<Unk_StlElem<104>**>(p); }
// MS2-PIN: ?FUN_141603d80@@YAAEAPEAU?$Unk_StlElem@$0GI@@@PEAX@Z 0x141603d80

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 16-byte elements.
void FUN_141604220(void*, Unk_StlElem<16>*, Unk_StlElem<16>*) { }
// MS2-PIN: ?FUN_141604220@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@1@Z 0x141604220

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 24-byte elements.
void FUN_141604230(void*, Unk_StlElem<24>*, Unk_StlElem<24>*) { }
// MS2-PIN: ?FUN_141604230@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x141604230

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 88-byte elements.
void FUN_141604240(void*, Unk_StlElem<88>*, Unk_StlElem<88>*) { }
// MS2-PIN: ?FUN_141604240@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x141604240

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 48-byte elements.
void FUN_141604250(void*, Unk_StlElem<48>*, Unk_StlElem<48>*) { }
// MS2-PIN: ?FUN_141604250@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x141604250

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 152-byte elements.
void FUN_141604260(void*, Unk_StlElem<152>*, Unk_StlElem<152>*) { }
// MS2-PIN: ?FUN_141604260@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x141604260

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 544-byte elements.
void FUN_141604270(void*, Unk_StlElem<544>*, Unk_StlElem<544>*) { }
// MS2-PIN: ?FUN_141604270@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x141604270

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 296-byte elements.
void FUN_141604280(void*, Unk_StlElem<296>*, Unk_StlElem<296>*) { }
// MS2-PIN: ?FUN_141604280@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x141604280

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 280-byte elements.
void FUN_141604290(void*, Unk_StlElem<280>*, Unk_StlElem<280>*) { }
// MS2-PIN: ?FUN_141604290@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x141604290

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 224-byte elements.
void FUN_1416042a0(void*, Unk_StlElem<224>*, Unk_StlElem<224>*) { }
// MS2-PIN: ?FUN_1416042a0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1416042a0

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 1408-byte elements.
void FUN_1416042b0(void*, Unk_StlElem<1408>*, Unk_StlElem<1408>*) { }
// MS2-PIN: ?FUN_1416042b0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1416042b0

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 24-byte elements.
void FUN_1416042c0(void*, Unk_StlElem<24>*, Unk_StlElem<24>*) { }
// MS2-PIN: ?FUN_1416042c0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1416042c0

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 5288-byte elements.
void FUN_1416042d0(void*, Unk_StlElem<5288>*, Unk_StlElem<5288>*) { }
// MS2-PIN: ?FUN_1416042d0@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1416042d0

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 24-byte elements.
void FUN_1416042e0(void*, Unk_StlElem<24>*, Unk_StlElem<24>*) { }
// MS2-PIN: ?FUN_1416042e0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1416042e0

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 400-byte elements.
void FUN_1416042f0(void*, Unk_StlElem<400>*, Unk_StlElem<400>*) { }
// MS2-PIN: ?FUN_1416042f0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1416042f0

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 184-byte elements.
void FUN_141604300(void*, Unk_StlElem<184>*, Unk_StlElem<184>*) { }
// MS2-PIN: ?FUN_141604300@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x141604300

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 88-byte elements.
void FUN_141604310(void*, Unk_StlElem<88>*, Unk_StlElem<88>*) { }
// MS2-PIN: ?FUN_141604310@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x141604310

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 104-byte elements.
void FUN_141604320(void*, Unk_StlElem<104>*, Unk_StlElem<104>*) { }
// MS2-PIN: ?FUN_141604320@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x141604320

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 2792-byte elements.
void FUN_141604330(void*, Unk_StlElem<2792>*, Unk_StlElem<2792>*) { }
// MS2-PIN: ?FUN_141604330@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x141604330

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 3784-byte elements.
void FUN_141604340(void*, Unk_StlElem<3784>*, Unk_StlElem<3784>*) { }
// MS2-PIN: ?FUN_141604340@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x141604340

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 200-byte elements.
void FUN_141604350(void*, Unk_StlElem<200>*, Unk_StlElem<200>*) { }
// MS2-PIN: ?FUN_141604350@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x141604350

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 248-byte elements.
void FUN_141604360(void*, Unk_StlElem<248>*, Unk_StlElem<248>*) { }
// MS2-PIN: ?FUN_141604360@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x141604360

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 1168-byte elements.
void FUN_141604370(void*, Unk_StlElem<1168>*, Unk_StlElem<1168>*) { }
// MS2-PIN: ?FUN_141604370@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x141604370

// MS2-FUNCTIONAL: preserves the recovered allocator construction operation for opaque 32-byte elements.
void FUN_141604380(void*, Unk_StlElem<32>*, Unk_StlElem<32>*) { }
// MS2-PIN: ?FUN_141604380@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x141604380

// MS2-FUNCTIONAL: performs the recovered move over opaque 16-byte elements and returns the destination end.
Unk_StlElem<16>* FUN_141605bd0(void*, Unk_StlElem<16>* first, Unk_StlElem<16>* last, Unk_StlElem<16>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 16); return dest + count; }
// MS2-PIN: ?FUN_141605bd0@@YAPEAU?$Unk_StlElem@$0BA@@@PEAXPEAU1@11@Z 0x141605bd0

// MS2-FUNCTIONAL: performs the recovered move over opaque 24-byte elements and returns the destination end.
Unk_StlElem<24>* FUN_141605c10(void*, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 24); return dest + count; }
// MS2-PIN: ?FUN_141605c10@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z 0x141605c10

// MS2-FUNCTIONAL: performs the recovered move over opaque 88-byte elements and returns the destination end.
Unk_StlElem<88>* FUN_141605c50(void*, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 88); return dest + count; }
// MS2-PIN: ?FUN_141605c50@@YAPEAU?$Unk_StlElem@$0FI@@@PEAXPEAU1@11@Z 0x141605c50

// MS2-FUNCTIONAL: performs the recovered move over opaque 48-byte elements and returns the destination end.
Unk_StlElem<48>* FUN_141605c90(void*, Unk_StlElem<48>* first, Unk_StlElem<48>* last, Unk_StlElem<48>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 48); return dest + count; }
// MS2-PIN: ?FUN_141605c90@@YAPEAU?$Unk_StlElem@$0DA@@@PEAXPEAU1@11@Z 0x141605c90

// MS2-FUNCTIONAL: performs the recovered move over opaque 152-byte elements and returns the destination end.
Unk_StlElem<152>* FUN_141605cd0(void*, Unk_StlElem<152>* first, Unk_StlElem<152>* last, Unk_StlElem<152>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 152); return dest + count; }
// MS2-PIN: ?FUN_141605cd0@@YAPEAU?$Unk_StlElem@$0JI@@@PEAXPEAU1@11@Z 0x141605cd0

// MS2-FUNCTIONAL: performs the recovered move over opaque 544-byte elements and returns the destination end.
Unk_StlElem<544>* FUN_141605d10(void*, Unk_StlElem<544>* first, Unk_StlElem<544>* last, Unk_StlElem<544>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 544); return dest + count; }
// MS2-PIN: ?FUN_141605d10@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAXPEAU1@11@Z 0x141605d10

// MS2-FUNCTIONAL: performs the recovered move over opaque 296-byte elements and returns the destination end.
Unk_StlElem<296>* FUN_141605d50(void*, Unk_StlElem<296>* first, Unk_StlElem<296>* last, Unk_StlElem<296>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 296); return dest + count; }
// MS2-PIN: ?FUN_141605d50@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAXPEAU1@11@Z 0x141605d50

// MS2-FUNCTIONAL: performs the recovered move over opaque 280-byte elements and returns the destination end.
Unk_StlElem<280>* FUN_141605d90(void*, Unk_StlElem<280>* first, Unk_StlElem<280>* last, Unk_StlElem<280>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 280); return dest + count; }
// MS2-PIN: ?FUN_141605d90@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAXPEAU1@11@Z 0x141605d90

// MS2-FUNCTIONAL: performs the recovered move over opaque 224-byte elements and returns the destination end.
Unk_StlElem<224>* FUN_141605dd0(void*, Unk_StlElem<224>* first, Unk_StlElem<224>* last, Unk_StlElem<224>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 224); return dest + count; }
// MS2-PIN: ?FUN_141605dd0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAXPEAU1@11@Z 0x141605dd0

// MS2-FUNCTIONAL: performs the recovered move over opaque 1408-byte elements and returns the destination end.
Unk_StlElem<1408>* FUN_141605e10(void*, Unk_StlElem<1408>* first, Unk_StlElem<1408>* last, Unk_StlElem<1408>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 1408); return dest + count; }
// MS2-PIN: ?FUN_141605e10@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAXPEAU1@11@Z 0x141605e10

// MS2-FUNCTIONAL: performs the recovered move over opaque 24-byte elements and returns the destination end.
Unk_StlElem<24>* FUN_141605e50(void*, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 24); return dest + count; }
// MS2-PIN: ?FUN_141605e50@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z 0x141605e50

// MS2-FUNCTIONAL: performs the recovered move over opaque 5288-byte elements and returns the destination end.
Unk_StlElem<5288>* FUN_141605e90(void*, Unk_StlElem<5288>* first, Unk_StlElem<5288>* last, Unk_StlElem<5288>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 5288); return dest + count; }
// MS2-PIN: ?FUN_141605e90@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAXPEAU1@11@Z 0x141605e90

// MS2-FUNCTIONAL: performs the recovered move over opaque 24-byte elements and returns the destination end.
Unk_StlElem<24>* FUN_141605ed0(void*, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 24); return dest + count; }
// MS2-PIN: ?FUN_141605ed0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z 0x141605ed0

// MS2-FUNCTIONAL: performs the recovered move over opaque 400-byte elements and returns the destination end.
Unk_StlElem<400>* FUN_141605f10(void*, Unk_StlElem<400>* first, Unk_StlElem<400>* last, Unk_StlElem<400>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 400); return dest + count; }
// MS2-PIN: ?FUN_141605f10@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAXPEAU1@11@Z 0x141605f10

// MS2-FUNCTIONAL: performs the recovered move over opaque 184-byte elements and returns the destination end.
Unk_StlElem<184>* FUN_141605f50(void*, Unk_StlElem<184>* first, Unk_StlElem<184>* last, Unk_StlElem<184>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 184); return dest + count; }
// MS2-PIN: ?FUN_141605f50@@YAPEAU?$Unk_StlElem@$0LI@@@PEAXPEAU1@11@Z 0x141605f50

// MS2-FUNCTIONAL: performs the recovered move over opaque 88-byte elements and returns the destination end.
Unk_StlElem<88>* FUN_141605f90(void*, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 88); return dest + count; }
// MS2-PIN: ?FUN_141605f90@@YAPEAU?$Unk_StlElem@$0FI@@@PEAXPEAU1@11@Z 0x141605f90

// MS2-FUNCTIONAL: performs the recovered move over opaque 104-byte elements and returns the destination end.
Unk_StlElem<104>* FUN_141605fd0(void*, Unk_StlElem<104>* first, Unk_StlElem<104>* last, Unk_StlElem<104>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 104); return dest + count; }
// MS2-PIN: ?FUN_141605fd0@@YAPEAU?$Unk_StlElem@$0GI@@@PEAXPEAU1@11@Z 0x141605fd0

// MS2-FUNCTIONAL: performs the recovered move over opaque 2792-byte elements and returns the destination end.
Unk_StlElem<2792>* FUN_141606010(void*, Unk_StlElem<2792>* first, Unk_StlElem<2792>* last, Unk_StlElem<2792>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 2792); return dest + count; }
// MS2-PIN: ?FUN_141606010@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAXPEAU1@11@Z 0x141606010

// MS2-FUNCTIONAL: performs the recovered move over opaque 3784-byte elements and returns the destination end.
Unk_StlElem<3784>* FUN_141606050(void*, Unk_StlElem<3784>* first, Unk_StlElem<3784>* last, Unk_StlElem<3784>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 3784); return dest + count; }
// MS2-PIN: ?FUN_141606050@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAXPEAU1@11@Z 0x141606050

// MS2-FUNCTIONAL: performs the recovered move over opaque 200-byte elements and returns the destination end.
Unk_StlElem<200>* FUN_141606090(void*, Unk_StlElem<200>* first, Unk_StlElem<200>* last, Unk_StlElem<200>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 200); return dest + count; }
// MS2-PIN: ?FUN_141606090@@YAPEAU?$Unk_StlElem@$0MI@@@PEAXPEAU1@11@Z 0x141606090

// MS2-FUNCTIONAL: performs the recovered move over opaque 248-byte elements and returns the destination end.
Unk_StlElem<248>* FUN_1416060d0(void*, Unk_StlElem<248>* first, Unk_StlElem<248>* last, Unk_StlElem<248>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 248); return dest + count; }
// MS2-PIN: ?FUN_1416060d0@@YAPEAU?$Unk_StlElem@$0PI@@@PEAXPEAU1@11@Z 0x1416060d0

// MS2-FUNCTIONAL: performs the recovered move over opaque 1168-byte elements and returns the destination end.
Unk_StlElem<1168>* FUN_141606110(void*, Unk_StlElem<1168>* first, Unk_StlElem<1168>* last, Unk_StlElem<1168>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 1168); return dest + count; }
// MS2-PIN: ?FUN_141606110@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAXPEAU1@11@Z 0x141606110

// MS2-FUNCTIONAL: performs the recovered move over opaque 32-byte elements and returns the destination end.
Unk_StlElem<32>* FUN_141606150(void*, Unk_StlElem<32>* first, Unk_StlElem<32>* last, Unk_StlElem<32>* dest) { size_t count = static_cast<size_t>(last-first); if (count) std::memmove(dest, first, count * 32); return dest + count; }
// MS2-PIN: ?FUN_141606150@@YAPEAU?$Unk_StlElem@$0CA@@@PEAXPEAU1@11@Z 0x141606150

// MS2-FUNCTIONAL: performs the recovered move over opaque 16-byte elements.
void FUN_141606750(void*, Unk_StlElem<16>* first, Unk_StlElem<16>* last, Unk_StlElem<16>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606750@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@11@Z 0x141606750

// MS2-FUNCTIONAL: performs the recovered move over opaque 24-byte elements.
void FUN_1416067b0(void*, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_1416067b0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z 0x1416067b0

// MS2-FUNCTIONAL: performs the recovered move over opaque 88-byte elements.
void FUN_141606810(void*, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606810@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@11@Z 0x141606810

// MS2-FUNCTIONAL: performs the recovered move over opaque 48-byte elements.
void FUN_141606870(void*, Unk_StlElem<48>* first, Unk_StlElem<48>* last, Unk_StlElem<48>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606870@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@11@Z 0x141606870

// MS2-FUNCTIONAL: performs the recovered move over opaque 152-byte elements.
void FUN_1416068d0(void*, Unk_StlElem<152>* first, Unk_StlElem<152>* last, Unk_StlElem<152>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_1416068d0@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@11@Z 0x1416068d0

// MS2-FUNCTIONAL: performs the recovered move over opaque 544-byte elements.
void FUN_141606930(void*, Unk_StlElem<544>* first, Unk_StlElem<544>* last, Unk_StlElem<544>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606930@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@11@Z 0x141606930

// MS2-FUNCTIONAL: performs the recovered move over opaque 296-byte elements.
void FUN_141606990(void*, Unk_StlElem<296>* first, Unk_StlElem<296>* last, Unk_StlElem<296>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606990@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@11@Z 0x141606990

// MS2-FUNCTIONAL: performs the recovered move over opaque 280-byte elements.
void FUN_1416069f0(void*, Unk_StlElem<280>* first, Unk_StlElem<280>* last, Unk_StlElem<280>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_1416069f0@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@11@Z 0x1416069f0

// MS2-FUNCTIONAL: performs the recovered move over opaque 224-byte elements.
void FUN_141606a50(void*, Unk_StlElem<224>* first, Unk_StlElem<224>* last, Unk_StlElem<224>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606a50@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@11@Z 0x141606a50

// MS2-FUNCTIONAL: performs the recovered move over opaque 1408-byte elements.
void FUN_141606ab0(void*, Unk_StlElem<1408>* first, Unk_StlElem<1408>* last, Unk_StlElem<1408>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606ab0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@11@Z 0x141606ab0

// MS2-FUNCTIONAL: performs the recovered move over opaque 24-byte elements.
void FUN_141606b10(void*, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606b10@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z 0x141606b10

// MS2-FUNCTIONAL: performs the recovered move over opaque 5288-byte elements.
void FUN_141606b70(void*, Unk_StlElem<5288>* first, Unk_StlElem<5288>* last, Unk_StlElem<5288>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606b70@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@11@Z 0x141606b70

// MS2-FUNCTIONAL: performs the recovered move over opaque 24-byte elements.
void FUN_141606bd0(void*, Unk_StlElem<24>* first, Unk_StlElem<24>* last, Unk_StlElem<24>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606bd0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z 0x141606bd0

// MS2-FUNCTIONAL: performs the recovered move over opaque 400-byte elements.
void FUN_141606c30(void*, Unk_StlElem<400>* first, Unk_StlElem<400>* last, Unk_StlElem<400>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606c30@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@11@Z 0x141606c30

// MS2-FUNCTIONAL: performs the recovered move over opaque 184-byte elements.
void FUN_141606c90(void*, Unk_StlElem<184>* first, Unk_StlElem<184>* last, Unk_StlElem<184>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606c90@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@11@Z 0x141606c90

// MS2-FUNCTIONAL: performs the recovered move over opaque 88-byte elements.
void FUN_141606cf0(void*, Unk_StlElem<88>* first, Unk_StlElem<88>* last, Unk_StlElem<88>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606cf0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@11@Z 0x141606cf0

// MS2-FUNCTIONAL: performs the recovered move over opaque 104-byte elements.
void FUN_141606d50(void*, Unk_StlElem<104>* first, Unk_StlElem<104>* last, Unk_StlElem<104>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606d50@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@11@Z 0x141606d50

// MS2-FUNCTIONAL: performs the recovered move over opaque 2792-byte elements.
void FUN_141606db0(void*, Unk_StlElem<2792>* first, Unk_StlElem<2792>* last, Unk_StlElem<2792>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606db0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@11@Z 0x141606db0

// MS2-FUNCTIONAL: performs the recovered move over opaque 3784-byte elements.
void FUN_141606e10(void*, Unk_StlElem<3784>* first, Unk_StlElem<3784>* last, Unk_StlElem<3784>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606e10@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@11@Z 0x141606e10

// MS2-FUNCTIONAL: performs the recovered move over opaque 200-byte elements.
void FUN_141606e70(void*, Unk_StlElem<200>* first, Unk_StlElem<200>* last, Unk_StlElem<200>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606e70@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@11@Z 0x141606e70

// MS2-FUNCTIONAL: performs the recovered move over opaque 248-byte elements.
void FUN_141606ed0(void*, Unk_StlElem<248>* first, Unk_StlElem<248>* last, Unk_StlElem<248>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606ed0@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@11@Z 0x141606ed0

// MS2-FUNCTIONAL: performs the recovered move over opaque 1168-byte elements.
void FUN_141606f30(void*, Unk_StlElem<1168>* first, Unk_StlElem<1168>* last, Unk_StlElem<1168>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606f30@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@11@Z 0x141606f30

// MS2-FUNCTIONAL: performs the recovered move over opaque 32-byte elements.
void FUN_141606f90(void*, Unk_StlElem<32>* first, Unk_StlElem<32>* last, Unk_StlElem<32>* dest) { if (first != last) std::memmove(dest, first, static_cast<size_t>(reinterpret_cast<const unsigned char*>(last)-reinterpret_cast<const unsigned char*>(first))); }
// MS2-PIN: ?FUN_141606f90@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@11@Z 0x141606f90

// @0x141607120
void FUN_141607120(void) { std::_Xlength_error("vector<T> too long"); }
// MS2-PIN: ?FUN_141607120@@YAXXZ 0x141607120

// @0x141607220
void FUN_141607220(void) { std::_Xlength_error("vector<T> too long"); }
// MS2-PIN: ?FUN_141607220@@YAXXZ 0x141607220

// MS2-FUNCTIONAL: applies the allocator size multiplication recovered from the decompilation.
Unk_StlElem<224>* FUN_1416074b0(void*, unsigned long long count) { return static_cast<Unk_StlElem<224>*>(::operator new(count * 224)); }
// MS2-PIN: ?FUN_1416074b0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAX_K@Z 0x1416074b0

// MS2-FUNCTIONAL: applies the allocator size multiplication recovered from the decompilation.
Unk_StlElem<104>* FUN_141607630(void*, unsigned long long count) { return static_cast<Unk_StlElem<104>*>(::operator new(count * 104)); }
// MS2-PIN: ?FUN_141607630@@YAPEAU?$Unk_StlElem@$0GI@@@PEAX_K@Z 0x141607630

// These accessors return the value subobject at +0x10 in their corresponding vector allocation triples.
extern unsigned long long FUN_141600e70(void*);
extern unsigned long long FUN_141600e90(void*);
extern unsigned long long FUN_141600eb0(void*);
extern unsigned long long FUN_141600ed0(void*);
extern unsigned long long FUN_141600ef0(void*);
extern unsigned long long FUN_141600f10(void*);
extern unsigned long long FUN_141600f30(void*);
extern unsigned long long FUN_141600f50(void*);
extern unsigned long long FUN_141600f70(void*);
extern unsigned long long FUN_141600f90(void*);
extern unsigned long long FUN_141600fb0(void*);
extern unsigned long long FUN_141600fd0(void*);
extern unsigned long long FUN_141600ff0(void*);
extern unsigned long long FUN_141601010(void*);
extern unsigned long long FUN_141601030(void*);
extern unsigned long long FUN_141601050(void*);
extern unsigned long long FUN_141601070(void*);
extern unsigned long long FUN_141601090(void*);
extern unsigned long long FUN_1416010b0(void*);
extern unsigned long long FUN_1416010d0(void*);
extern unsigned long long FUN_1416010f0(void*);
extern unsigned long long FUN_141601110(void*);
extern unsigned long long FUN_141601130(void*);
extern unsigned long long FUN_141601150(void*);
extern unsigned long long FUN_141601170(void*);
extern unsigned long long FUN_141601190(void*);
extern unsigned long long FUN_1416011b0(void*);
extern unsigned long long FUN_1416011d0(void*);
extern unsigned long long FUN_1416011f0(void*);
extern unsigned long long FUN_141601210(void*);
extern unsigned long long FUN_141601230(void*);
extern unsigned long long FUN_141601250(void*);

extern void* FUN_141601270(void*);
extern unsigned long long FUN_141601290(void*);

// @0x141602e00
unsigned long long FUN_141602e00(void* p) { return FUN_141600e70(p) + 0x10; }

// @0x141602e20
unsigned long long FUN_141602e20(void* p) { return FUN_141600e90(p) + 0x10; }

// @0x141602e40
unsigned long long FUN_141602e40(void* p) { return FUN_141600eb0(p) + 0x10; }

// @0x141602e60
unsigned long long FUN_141602e60(void* p) { return FUN_141600ed0(p) + 0x10; }

// @0x141602e80
unsigned long long FUN_141602e80(void* p) { return FUN_141600ef0(p) + 0x10; }

// @0x141602ea0
unsigned long long FUN_141602ea0(void* p) { return FUN_141600f10(p) + 0x10; }

// @0x141602ec0
unsigned long long FUN_141602ec0(void* p) { return FUN_141600f30(p) + 0x10; }

// @0x141602ee0
unsigned long long FUN_141602ee0(void* p) { return FUN_141600f50(p) + 0x10; }

// @0x141602f00
unsigned long long FUN_141602f00(void* p) { return FUN_141600f70(p) + 0x10; }

// @0x141602f20
unsigned long long FUN_141602f20(void* p) { return FUN_141600f90(p) + 0x10; }

// @0x141602f40
unsigned long long FUN_141602f40(void* p) { return FUN_141600fb0(p) + 0x10; }

// @0x141602f60
unsigned long long FUN_141602f60(void* p) { return FUN_141600fd0(p) + 0x10; }

// @0x141602f80
unsigned long long FUN_141602f80(void* p) { return FUN_141600ff0(p) + 0x10; }

// @0x141602fa0
unsigned long long FUN_141602fa0(void* p) { return FUN_141601010(p) + 0x10; }

// @0x141602fc0
unsigned long long FUN_141602fc0(void* p) { return FUN_141601030(p) + 0x10; }

// @0x141602fe0
unsigned long long FUN_141602fe0(void* p) { return FUN_141601050(p) + 0x10; }

// @0x141603000
unsigned long long FUN_141603000(void* p) { return FUN_141601070(p) + 0x10; }

// @0x141603020
unsigned long long FUN_141603020(void* p) { return FUN_141601090(p) + 0x10; }

// @0x141603040
unsigned long long FUN_141603040(void* p) { return FUN_1416010b0(p) + 0x10; }

// @0x141603060
unsigned long long FUN_141603060(void* p) { return FUN_1416010d0(p) + 0x10; }

// @0x141603080
unsigned long long FUN_141603080(void* p) { return FUN_1416010f0(p) + 0x10; }

// @0x1416030a0
unsigned long long FUN_1416030a0(void* p) { return FUN_141601110(p) + 0x10; }

// @0x1416030c0
unsigned long long FUN_1416030c0(void* p) { return FUN_141601130(p) + 0x10; }

// @0x1416030e0
unsigned long long FUN_1416030e0(void* p) { return FUN_141601150(p) + 0x10; }

// @0x141603100
unsigned long long FUN_141603100(void* p) { return FUN_141601170(p) + 0x10; }

// @0x141603120
unsigned long long FUN_141603120(void* p) { return FUN_141601190(p) + 0x10; }

// @0x141603140
unsigned long long FUN_141603140(void* p) { return FUN_1416011b0(p) + 0x10; }

// @0x141603160
unsigned long long FUN_141603160(void* p) { return FUN_1416011d0(p) + 0x10; }

// @0x141603180
unsigned long long FUN_141603180(void* p) { return FUN_1416011f0(p) + 0x10; }

// @0x1416031a0
unsigned long long FUN_1416031a0(void* p) { return FUN_141601210(p) + 0x10; }

// @0x1416031c0
unsigned long long FUN_1416031c0(void* p) { return FUN_141601230(p) + 0x10; }

// @0x1416031e0
unsigned long long FUN_1416031e0(void* p) { return FUN_141601250(p) + 0x10; }


// Explicit functional-interface notes for opaque vector specializations shared with unit_1415d3570.
// MS2-FUNCTIONAL ?FUN_1416035c0@@YAAEAPEAU?$Unk_StlElem@$0OA@@@PEAX@Z: The observed reference targets the allocation-member subobject; the executable helper layering and frame are not recovered.
// MS2-FUNCTIONAL ?FUN_1416037c0@@YAAEAPEAU?$Unk_StlElem@$0GI@@@PEAX@Z: The observed reference targets the allocation-member subobject; the executable helper layering and frame are not recovered.
// MS2-FUNCTIONAL ?FUN_141603b80@@YAAEAPEAU?$Unk_StlElem@$0OA@@@PEAX@Z: The observed reference targets the allocation-member subobject; the executable helper layering and frame are not recovered.
// MS2-FUNCTIONAL ?FUN_141603d80@@YAAEAPEAU?$Unk_StlElem@$0GI@@@PEAX@Z: The observed reference targets the allocation-member subobject; the executable helper layering and frame are not recovered.
// MS2-FUNCTIONAL ?FUN_141605bd0@@YAPEAU?$Unk_StlElem@$0BA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605c10@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605c50@@YAPEAU?$Unk_StlElem@$0FI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605c90@@YAPEAU?$Unk_StlElem@$0DA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605cd0@@YAPEAU?$Unk_StlElem@$0JI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605d10@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605d50@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605d90@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605dd0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605e10@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605e50@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605e90@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605ed0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605f10@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605f50@@YAPEAU?$Unk_StlElem@$0LI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605f90@@YAPEAU?$Unk_StlElem@$0FI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141605fd0@@YAPEAU?$Unk_StlElem@$0GI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141606010@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141606050@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141606090@@YAPEAU?$Unk_StlElem@$0MI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_1416060d0@@YAPEAU?$Unk_StlElem@$0PI@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141606110@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141606150@@YAPEAU?$Unk_StlElem@$0CA@@@PEAXPEAU1@11@Z: Opaque element lifetime and allocator details remain unrecovered; this body preserves the observed byte span move and returned destination end.
// MS2-FUNCTIONAL ?FUN_141606750@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_1416067b0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606810@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606870@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_1416068d0@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606930@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606990@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_1416069f0@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606a50@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606ab0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606b10@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606b70@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606bd0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606c30@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606c90@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606cf0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606d50@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606db0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606e10@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606e70@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606ed0@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606f30@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_141606f90@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@11@Z: Opaque element lifetime details remain unrecovered; this body preserves the observed byte span move for the caller-facing range.
// MS2-FUNCTIONAL ?FUN_1416074b0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAX_K@Z: The recovered allocation scales element count by the correct opaque element stride; the executable length-check helper sequence differs.
// MS2-FUNCTIONAL ?FUN_141607630@@YAPEAU?$Unk_StlElem@$0GI@@@PEAX_K@Z: The recovered allocation scales element count by the correct opaque element stride; the executable length-check helper sequence differs.


// Recovered container iterator sentinel checks from the owner decomp.
// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416020d0
bool FUN_1416020d0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602120
bool FUN_141602120(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602170
bool FUN_141602170(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416021c0
bool FUN_1416021c0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602210
bool FUN_141602210(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602260
bool FUN_141602260(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416022b0
bool FUN_1416022b0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602300
bool FUN_141602300(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602350
bool FUN_141602350(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416023a0
bool FUN_1416023a0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416023f0
bool FUN_1416023f0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602440
bool FUN_141602440(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602490
bool FUN_141602490(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416024e0
bool FUN_1416024e0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602530
bool FUN_141602530(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602580
bool FUN_141602580(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416025d0
bool FUN_1416025d0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602620
bool FUN_141602620(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602670
bool FUN_141602670(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416026c0
bool FUN_1416026c0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602710
bool FUN_141602710(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x141602760
bool FUN_141602760(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// MS2-FUNCTIONAL: the decompiled accessor chain resolves to the vector's +0x10 begin and +0x08 end slots; compare those recovered boundaries.
// @0x1416027b0
bool FUN_1416027b0(const void* p)
{
    const auto* bytes = static_cast<const unsigned char*>(p);
    const auto first = *reinterpret_cast<const unsigned long long*>(bytes + 0x10);
    const auto last = *reinterpret_cast<const unsigned long long*>(bytes + 0x08);
    return first != last;
}

// Recovered vector end adapters and empty allocator callbacks.
// @0x141603980
unsigned long long FUN_141603980(void* p) { return FUN_141600e70(p) + 8; }

// @0x1416039a0
unsigned long long FUN_1416039a0(void* p) { return FUN_141600e90(p) + 8; }

// @0x1416039c0
unsigned long long FUN_1416039c0(void* p) { return FUN_141600eb0(p) + 8; }

// @0x1416039e0
unsigned long long FUN_1416039e0(void* p) { return FUN_141600ed0(p) + 8; }

// @0x141603a00
unsigned long long FUN_141603a00(void* p) { return FUN_141600ef0(p) + 8; }

// @0x141603a20
unsigned long long FUN_141603a20(void* p) { return FUN_141600f10(p) + 8; }

// @0x141603a40
unsigned long long FUN_141603a40(void* p) { return FUN_141600f30(p) + 8; }

// @0x141603a60
unsigned long long FUN_141603a60(void* p) { return FUN_141600f50(p) + 8; }

// @0x141603a80
unsigned long long FUN_141603a80(void* p) { return FUN_141600f70(p) + 8; }

// @0x141603aa0
unsigned long long FUN_141603aa0(void* p) { return FUN_141600f90(p) + 8; }

// @0x141603ac0
unsigned long long FUN_141603ac0(void* p) { return FUN_141600fb0(p) + 8; }

// @0x141603ae0
unsigned long long FUN_141603ae0(void* p) { return FUN_141600fd0(p) + 8; }

// @0x141603b00
unsigned long long FUN_141603b00(void* p) { return FUN_141600ff0(p) + 8; }

// @0x141603b20
unsigned long long FUN_141603b20(void* p) { return FUN_141601010(p) + 8; }

// @0x141603b40
unsigned long long FUN_141603b40(void* p) { return FUN_141601030(p) + 8; }

// @0x141603b60
unsigned long long FUN_141603b60(void* p) { return FUN_141601050(p) + 8; }

// @0x141603ba0
unsigned long long FUN_141603ba0(void* p) { return FUN_141601090(p) + 8; }

// @0x141603bc0
unsigned long long FUN_141603bc0(void* p) { return FUN_1416010b0(p) + 8; }

// @0x141603be0
unsigned long long FUN_141603be0(void* p) { return FUN_1416010d0(p) + 8; }

// @0x141603c00
unsigned long long FUN_141603c00(void* p) { return FUN_1416010f0(p) + 8; }

// @0x141603c20
unsigned long long FUN_141603c20(void* p) { return FUN_141601110(p) + 8; }

// @0x141603c40
unsigned long long FUN_141603c40(void* p) { return FUN_141601130(p) + 8; }

// @0x141603c60
unsigned long long FUN_141603c60(void* p) { return FUN_141601150(p) + 8; }

// @0x141603c80
unsigned long long FUN_141603c80(void* p) { return FUN_141601170(p) + 8; }

// @0x141603ca0
unsigned long long FUN_141603ca0(void* p) { return FUN_141601190(p) + 8; }

// @0x141603cc0
unsigned long long FUN_141603cc0(void* p) { return FUN_1416011b0(p) + 8; }

// @0x141603ce0
unsigned long long FUN_141603ce0(void* p) { return FUN_1416011d0(p) + 8; }

// @0x141603d00
unsigned long long FUN_141603d00(void* p) { return FUN_1416011f0(p) + 8; }

// @0x141603d20
unsigned long long FUN_141603d20(void* p) { return FUN_141601210(p) + 8; }

// @0x141603d40
unsigned long long FUN_141603d40(void* p) { return FUN_141601230(p) + 8; }

// @0x141603d60
unsigned long long FUN_141603d60(void* p) { return FUN_141601250(p) + 8; }

// @0x1416033c0
void FUN_1416033c0(void* p) { (void)FUN_141600e70(p); }

// @0x1416033e0
void FUN_1416033e0(void* p) { (void)FUN_141600e90(p); }

// @0x141603400
void FUN_141603400(void* p) { (void)FUN_141600eb0(p); }

// @0x141603420
void FUN_141603420(void* p) { (void)FUN_141600ed0(p); }

// @0x141603440
void FUN_141603440(void* p) { (void)FUN_141600ef0(p); }

// @0x141603460
void FUN_141603460(void* p) { (void)FUN_141600f10(p); }

// @0x141603480
void FUN_141603480(void* p) { (void)FUN_141600f30(p); }

// @0x1416034a0
void FUN_1416034a0(void* p) { (void)FUN_141600f50(p); }

// @0x1416034c0
void FUN_1416034c0(void* p) { (void)FUN_141600f70(p); }

// @0x1416034e0
void FUN_1416034e0(void* p) { (void)FUN_141600f90(p); }

// @0x141603500
void FUN_141603500(void* p) { (void)FUN_141600fb0(p); }

// @0x141603520
void FUN_141603520(void* p) { (void)FUN_141600fd0(p); }

// @0x141603540
void FUN_141603540(void* p) { (void)FUN_141600ff0(p); }

// @0x141603560
void FUN_141603560(void* p) { (void)FUN_141601010(p); }

// @0x141603580
void FUN_141603580(void* p) { (void)FUN_141601030(p); }

// @0x1416035a0
void FUN_1416035a0(void* p) { (void)FUN_141601050(p); }

// @0x1416035e0
void FUN_1416035e0(void* p) { (void)FUN_141601090(p); }

// @0x141603600
void FUN_141603600(void* p) { (void)FUN_1416010b0(p); }

// @0x141603620
void FUN_141603620(void* p) { (void)FUN_1416010d0(p); }

// @0x141603640
void FUN_141603640(void* p) { (void)FUN_1416010f0(p); }

// @0x141603660
void FUN_141603660(void* p) { (void)FUN_141601110(p); }

// @0x141603680
void FUN_141603680(void* p) { (void)FUN_141601130(p); }

// @0x1416036a0
void FUN_1416036a0(void* p) { (void)FUN_141601150(p); }

// @0x1416036c0
void FUN_1416036c0(void* p) { (void)FUN_141601170(p); }

// @0x1416036e0
void FUN_1416036e0(void* p) { (void)FUN_141601190(p); }

// @0x141603700
void FUN_141603700(void* p) { (void)FUN_1416011b0(p); }

// @0x141603720
void FUN_141603720(void* p) { (void)FUN_1416011d0(p); }

// @0x141603740
void FUN_141603740(void* p) { (void)FUN_1416011f0(p); }

// @0x141603760
void FUN_141603760(void* p) { (void)FUN_141601210(p); }

// @0x141603780
void FUN_141603780(void* p) { (void)FUN_141601230(p); }

// @0x1416037a0
void FUN_1416037a0(void* p) { (void)FUN_141601250(p); }

// @0x1416037e0
void FUN_1416037e0(void* p) { (void)FUN_141601290(p); }


// MS2-FUNCTIONAL: preserves the observed MSVC tree-node relink using links at +0x00/+0x08/+0x10 and the nil flag at +0x19.
// @0x141602860
void FUN_141602860(long long* tree, long long node)
{
    auto* link = reinterpret_cast<long long*>(node + 0x10);
    const long long successor = *link;
    *link = *reinterpret_cast<long long*>(successor);
    if (*reinterpret_cast<unsigned char*>(*link + 0x19) == 0)
        *reinterpret_cast<long long*>(*link + 8) = node;
    *reinterpret_cast<long long*>(successor + 8) = *reinterpret_cast<long long*>(node + 8);
    if (node == *reinterpret_cast<long long*>(*tree + 8))
        *reinterpret_cast<long long*>(*tree + 8) = successor;
    else if (node == **reinterpret_cast<long long**>(node + 8))
        **reinterpret_cast<long long**>(node + 8) = successor;
    else
        *reinterpret_cast<long long*>(*reinterpret_cast<long long*>(node + 8) + 0x10) = successor;
    *reinterpret_cast<long long*>(successor) = node;
    *reinterpret_cast<long long*>(node + 8) = successor;
}

// MS2-FUNCTIONAL: follows the recovered tree right-link to the minimum node; the local node layout is inferred from the exe offsets.
// @0x141602940
long long FUN_141602940(long long node)
{
    while (*reinterpret_cast<unsigned char*>(*reinterpret_cast<long long*>(node + 0x10) + 0x19) == 0)
        node = *reinterpret_cast<long long*>(node + 0x10);
    return node;
}

// MS2-FUNCTIONAL: follows the recovered tree left-link to the maximum node; the local node layout is inferred from the exe offsets.
// @0x141602970
long long* FUN_141602970(long long* node)
{
    while (*reinterpret_cast<unsigned char*>(*node + 0x19) == 0)
        node = reinterpret_cast<long long*>(*node);
    return node;
}

// @0x141602800
void FUN_141602800(void* first, long long second)
{
    FUN_141602830(first, reinterpret_cast<void*>(second + 0x20));
}

// @0x141602830
void FUN_141602830(void*, void* value)
{
    FUN_1415dbda0(value);
}

// @0x141602850
void* FUN_141602850(void** value)
{
    return *value;
}

// Recovered tree accessor wrappers from the owner decomp.


// Recovered tree accessor wrappers from the owner decomp.
extern unsigned long long FUN_141601410(void*);

extern unsigned long long FUN_1416013f0(void*);

extern unsigned long long FUN_1416013d0(void*);

extern unsigned long long FUN_1416013b0(void*);

extern unsigned long long FUN_141601390(void*);

extern unsigned long long FUN_141601370(void*);

extern unsigned long long FUN_141601350(void*);

extern unsigned long long FUN_141601330(void*);

extern unsigned long long FUN_141601310(void*);

extern unsigned long long FUN_1416012f0(void*);

extern unsigned long long FUN_1416012d0(void*);

extern unsigned long long FUN_1416012b0(void*);

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603800
void FUN_141603800(void* p) { FUN_1416012b0(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603820
void FUN_141603820(void* p) { FUN_1416012d0(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603840
void FUN_141603840(void* p) { FUN_1416012f0(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603860
void FUN_141603860(void* p) { FUN_141601310(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603880
void FUN_141603880(void* p) { FUN_141601330(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x1416038a0
void FUN_1416038a0(void* p) { FUN_141601350(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x1416038c0
void FUN_1416038c0(void* p) { FUN_141601370(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x1416038e0
void FUN_1416038e0(void* p) { FUN_141601390(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603900
void FUN_141603900(void* p) { FUN_1416013b0(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603920
void FUN_141603920(void* p) { FUN_1416013d0(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603940
void FUN_141603940(void* p) { FUN_1416013f0(p); }

// MS2-FUNCTIONAL: forwards the recovered empty allocator accessor call; only codegen frame details may differ.
// @0x141603960
void FUN_141603960(void* p) { FUN_141601410(p); }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603da0
unsigned long long FUN_141603da0(void* p) { return FUN_141601290(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603dc0
unsigned long long FUN_141603dc0(void* p) { return FUN_1416012b0(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603de0
unsigned long long FUN_141603de0(void* p) { return FUN_1416012d0(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603e00
unsigned long long FUN_141603e00(void* p) { return FUN_1416012f0(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603e20
unsigned long long FUN_141603e20(void* p) { return FUN_141601310(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603e40
unsigned long long FUN_141603e40(void* p) { return FUN_141601330(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603e60
unsigned long long FUN_141603e60(void* p) { return FUN_141601350(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603e80
unsigned long long FUN_141603e80(void* p) { return FUN_141601370(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603ea0
unsigned long long FUN_141603ea0(void* p) { return FUN_141601390(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603ec0
unsigned long long FUN_141603ec0(void* p) { return FUN_1416013b0(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603ee0
unsigned long long FUN_141603ee0(void* p) { return FUN_1416013d0(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603f00
unsigned long long FUN_141603f00(void* p) { return FUN_1416013f0(p) + 8; }

// MS2-FUNCTIONAL: forwards the recovered tree end accessor and applies its +8 field displacement.
// @0x141603f20
unsigned long long FUN_141603f20(void* p) { return FUN_141601410(p) + 8; }


// @0x141604630
long long FUN_141604630(long long* tree) { return *tree + 0x10; }

// @0x141604650
long long FUN_141604650(long long* tree) { return *tree + 8; }

// MS2-FUNCTIONAL: reproduces the recovered red-black tree node relink using the exe field offsets (left 0, right 8, parent 16, nil flag 25).
// @0x141604670
void FUN_141604670(long long* tree, long long* position) {
    auto node = *position;
    auto right = *reinterpret_cast<long long*>(node + 16 / 8);
    *position = right;
    if (*reinterpret_cast<unsigned char*>(right + 25) == 0)
        *reinterpret_cast<long long**>(right + 8) = position;
    *reinterpret_cast<long long*>(node + 8) = position[1];
    auto head = *tree;
    if (position == *reinterpret_cast<long long**>(head + 8))
        *reinterpret_cast<long long*>(head + 8) = node;
    else if (position == *reinterpret_cast<long long**>(position[1] + 16))
        *reinterpret_cast<long long*>(position[1] + 16) = node;
    else
        *reinterpret_cast<long long*>(position[1]) = node;
    *reinterpret_cast<long long*>(node + 16) = reinterpret_cast<long long>(position);
    position[1] = node;
}

// @0x141603220
unsigned long long FUN_141603220(void* p) { return FUN_141601290(p) + 0x10; }

// @0x141603200
unsigned long long FUN_141603200(void* p) { return reinterpret_cast<unsigned long long>(FUN_141601270(p)) + 0x10; }
// @0x141603240
unsigned long long FUN_141603240(void* p) { return FUN_1416012b0(p) + 0x10; }
// @0x141603260
unsigned long long FUN_141603260(void* p) { return FUN_1416012d0(p) + 0x10; }
// @0x141603280
unsigned long long FUN_141603280(void* p) { return FUN_1416012f0(p) + 0x10; }
// @0x1416032a0
unsigned long long FUN_1416032a0(void* p) { return FUN_141601310(p) + 0x10; }
// @0x1416032c0
unsigned long long FUN_1416032c0(void* p) { return FUN_141601330(p) + 0x10; }
// @0x1416032e0
unsigned long long FUN_1416032e0(void* p) { return FUN_141601350(p) + 0x10; }
// @0x141603300
unsigned long long FUN_141603300(void* p) { return FUN_141601370(p) + 0x10; }
// @0x141603320
unsigned long long FUN_141603320(void* p) { return FUN_141601390(p) + 0x10; }
// @0x141603340
unsigned long long FUN_141603340(void* p) { return FUN_1416013b0(p) + 0x10; }
// @0x141603360
unsigned long long FUN_141603360(void* p) { return FUN_1416013d0(p) + 0x10; }
// @0x141603380
unsigned long long FUN_141603380(void* p) { return FUN_1416013f0(p) + 0x10; }
// @0x1416033a0
unsigned long long FUN_1416033a0(void* p) { return FUN_141601410(p) + 0x10; }

extern void FUN_14016c7c0(void*);
// @0x141604000
void FUN_141604000(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141600ff0(p))); }
// @0x141604020
void FUN_141604020(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601030(p))); }
// @0x141604040
void FUN_141604040(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601070(p))); }
// @0x141604060
void FUN_141604060(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416010b0(p))); }
// @0x141604080
void FUN_141604080(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416010f0(p))); }
// @0x1416040a0
void FUN_1416040a0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601130(p))); }
// @0x1416040c0
void FUN_1416040c0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601170(p))); }
// @0x1416040e0
void FUN_1416040e0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416011b0(p))); }
// @0x141604100
void FUN_141604100(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416011f0(p))); }
// @0x141604120
void FUN_141604120(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601230(p))); }
// @0x141604140
void FUN_141604140(void* p) { FUN_14016c7c0(FUN_141601270(p)); }
// @0x141604160
void FUN_141604160(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416012b0(p))); }
// @0x141604180
void FUN_141604180(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416012f0(p))); }
// @0x1416041a0
void FUN_1416041a0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601330(p))); }
// @0x1416041c0
void FUN_1416041c0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_141601370(p))); }
// @0x1416041e0
void FUN_1416041e0(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416013b0(p))); }
// @0x141604200
void FUN_141604200(void* p) { FUN_14016c7c0(reinterpret_cast<void*>(FUN_1416013f0(p))); }
