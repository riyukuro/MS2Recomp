// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PathEngine glue: cSolidObjects (iSolidObjects over heap
// point buffers). The client's copy is the PathEngine SDK sample "Building from Physics Scene Data/SolidObjects.cpp"
// unchanged, so it is compiled in place from third_party (wrapper only: pins and hooks; no SDK text in src/).
// The exe has no asserts in it: NDEBUG for the sample's <assert.h>.
// MS2-UNIT: unit_14164cc70
// MS2-RANGE: 0x14164cc70-0x14164dfd0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pathengine\\solidobjects.cpp"
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"

#define NDEBUG
#include "../third_party/src/pathengine-sigmaco/samples/Code Snippets/Building from Physics Scene Data/SolidObjects.cpp"
#undef NDEBUG

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_REPLACE_METHOD(0x14164CD20, cSolidObjects, add, 242, 0x861EF790);
MS2_REPLACE_METHOD(0x14164CE20, cSolidObjects, applyCoordinateMapping, 167, 0x3DC6E01D);
MS2_REPLACE_METHOD(0x14164CED0, cSolidObjects, numberOfConvexSolids, 41, 0x5481A767);
MS2_REPLACE_METHOD(0x14164CF00, cSolidObjects, convexSolid_Points, 121, 0x9DC7C507);
MS2_REPLACE_METHOD(0x14164CF80, cSolidObjects, convexSolid_Point, 154, 0xF09C2920);
MS2_REPLACE_METHOD(0x14164D020, cSolidObjects, convexSolid_Attribute, 20, 0x67261AB5);

// The UCRT's per-TU `static __inline memmove_s` copy that ends the range.
// @0x14164deb0
MS2_EMIT_CRT_MEMMOVE_S();

// The sample has no source tags; the exe functions it compiles to:
// MS2-PIN: ??1cSolidObjects@@UEAA@XZ 0x14164cc70
// MS2-PIN: ?add@cSolidObjects@@QEAAXAEBV?$vector@JV?$allocator@J@std@@@std@@@Z 0x14164cd20
// MS2-PIN: ?applyCoordinateMapping@cSolidObjects@@QEAAXAEBVcCoordinateMapping@@@Z 0x14164ce20
// MS2-PIN: ?numberOfConvexSolids@cSolidObjects@@UEBAJXZ 0x14164ced0
// MS2-PIN: ?convexSolid_Points@cSolidObjects@@UEBAJJ@Z 0x14164cf00
// MS2-PIN: ?convexSolid_Point@cSolidObjects@@UEBAXJJAEAJ00@Z 0x14164cf80
// MS2-PIN: ?convexSolid_Attribute@cSolidObjects@@UEBAJJJ@Z 0x14164d020
