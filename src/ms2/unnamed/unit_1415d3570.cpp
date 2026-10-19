// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template zone of the boxed-pointer TU, part 0: the STL
// glue of about twenty std::vector<T> instantiations whose element types are not recoverable from this range (only their
// sizes are). In exe order: std::_Destroy_range1 (trivial / non-trivial), std::_Destroy_range, std::_Idl_distance1
// (pointer difference), std::_Uninitialized_backout_al<T*>::_Emplace_back, vector::_Emplace_back_with_unused_capacity and
// vector::_Emplace_reallocate. The element types are modelled as Unk_StlElem<sizeof(T)> and every member is written as a
// free function taking the container first (same ABI); the callees are the vectors' own accessors in other units.
// MS2-UNIT: unit_1415d3570
// MS2-RANGE: 0x1415d3570-0x1415da4b0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <type_traits>
#include <iterator>

// an element of sizeof(T) == N
template <size_t N>
struct Unk_StlElem
{
    unsigned char m_bytes[N];
};

// std::_Uninitialized_backout_al<T*, allocator<T>>: the elements [m_pFirst, m_pLast) constructed so far
template <class T>
struct Unk_StlBackout
{
    T* m_pFirst;
    T* m_pLast;
    void* m_pAl;
};

// Callees (accessors, allocator_traits, uninitialized copy helpers) of the same vectors, in other units.
extern Unk_StlElem<0x20>* FUN_140296020(Unk_StlElem<0x20>* p);
extern size_t FUN_14029a300(void* pThis, size_t nNewSize);
extern void FUN_14029a4a0(void* pThis, Unk_StlElem<0x20>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_14029a860(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast);
extern void* FUN_14029bab0(void* pThis);
extern Unk_StlElem<0x20>*& FUN_14029bfd0(void* pThis);
extern Unk_StlElem<0x20>*& FUN_14029c010(void* pThis);
extern void FUN_14029c080(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast);
extern Unk_StlElem<0x20>* FUN_14029c550(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, Unk_StlElem<0x20>* pDest);
extern void FUN_14029c670(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, Unk_StlElem<0x20>* pDest);
extern void FUN_14029c6f0();
extern Unk_StlElem<0x20>* FUN_14029c7c0(void* pAl, size_t n);
extern void FUN_14029cd50(void* pAl, Unk_StlElem<0x20>* p, size_t n);
extern size_t FUN_14029d620(void* pThis);
extern size_t FUN_14029dc20(void* pThis);
extern Unk_StlElem<0x20>* FUN_1403a4b80(Unk_StlElem<0x20>* p);
extern Unk_StlElem<0x10>* FUN_1415dd7c0(Unk_StlElem<0x10>* p);
extern Unk_StlElem<0x18>* FUN_1415dd7d0(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x58>* FUN_1415dd7e0(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x30>* FUN_1415dd7f0(Unk_StlElem<0x30>* p);
extern Unk_StlElem<0x98>* FUN_1415dd800(Unk_StlElem<0x98>* p);
extern Unk_StlElem<0x220>* FUN_1415dd810(Unk_StlElem<0x220>* p);
extern Unk_StlElem<0x128>* FUN_1415dd820(Unk_StlElem<0x128>* p);
extern Unk_StlElem<0x118>* FUN_1415dd830(Unk_StlElem<0x118>* p);
extern Unk_StlElem<0xe0>* FUN_1415dd840(Unk_StlElem<0xe0>* p);
extern Unk_StlElem<0x580>* FUN_1415dd850(Unk_StlElem<0x580>* p);
extern Unk_StlElem<0x18>* FUN_1415dd860(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x14a8>* FUN_1415dd870(Unk_StlElem<0x14a8>* p);
extern Unk_StlElem<0x18>* FUN_1415dd880(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x190>* FUN_1415dd890(Unk_StlElem<0x190>* p);
extern Unk_StlElem<0xb8>* FUN_1415dd8a0(Unk_StlElem<0xb8>* p);
extern Unk_StlElem<0x58>* FUN_1415dd8b0(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x68>* FUN_1415dd8c0(Unk_StlElem<0x68>* p);
extern Unk_StlElem<0xae8>* FUN_1415dd8d0(Unk_StlElem<0xae8>* p);
extern Unk_StlElem<0xec8>* FUN_1415dd8e0(Unk_StlElem<0xec8>* p);
extern Unk_StlElem<0xc8>* FUN_1415dd8f0(Unk_StlElem<0xc8>* p);
extern Unk_StlElem<0xf8>* FUN_1415dd900(Unk_StlElem<0xf8>* p);
extern Unk_StlElem<0x490>* FUN_1415dd910(Unk_StlElem<0x490>* p);
extern Unk_StlElem<0x20>* FUN_1415dd920(Unk_StlElem<0x20>* p);
extern void FUN_1415e2430(void* pAl, Unk_StlElem<0x10>* p, Unk_StlElem<0x10>* pVal);
extern void FUN_1415e2480(void* pAl, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal);
extern void FUN_1415e24d0(void* pAl, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal);
extern void FUN_1415e2520(void* pAl, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal);
extern void FUN_1415e2570(void* pAl, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal);
extern void FUN_1415e25c0(void* pAl, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal);
extern void FUN_1415e2610(void* pAl, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal);
extern void FUN_1415e2660(void* pAl, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal);
extern void FUN_1415e26b0(void* pAl, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal);
extern void FUN_1415e2700(void* pAl, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal);
extern void FUN_1415e2750(void* pAl, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal);
extern void FUN_1415e27a0(void* pAl, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal);
extern void FUN_1415e27f0(void* pAl, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal);
extern void FUN_1415e2840(void* pAl, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal);
extern void FUN_1415e2890(void* pAl, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal);
extern void FUN_1415e28e0(void* pAl, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal);
extern void FUN_1415e2930(void* pAl, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal);
extern void FUN_1415e2980(void* pAl, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal);
extern void FUN_1415e29d0(void* pAl, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal);
extern void FUN_1415e2a20(void* pAl, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal);
extern void FUN_1415e2a70(void* pAl, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal);
extern void FUN_1415e2ac0(void* pAl, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal);
extern void FUN_1415e2b10(void* pAl, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal);
extern void FUN_1415e2b60(void* pAl, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal);
extern void FUN_1415e2bb0(void* pAl, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal);
extern void FUN_1415e2c00(void* pAl, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal);
extern void FUN_1415e2c50(void* pAl, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal);
extern void FUN_1415e2ca0(void* pAl, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal);
extern void FUN_1415e2cf0(void* pAl, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal);
extern void FUN_1415e2d40(void* pAl, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal);
extern void FUN_1415e2d90(void* pAl, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal);
extern void FUN_1415e2de0(void* pAl, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal);
extern void FUN_1415e2e30(void* pAl, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal);
extern void FUN_1415e2e80(void* pAl, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal);
extern void FUN_1415e2ed0(void* pAl, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal);
extern void FUN_1415e2f20(void* pAl, Unk_StlElem<0x190>* p, Unk_StlElem<0x190>* pVal);
extern void FUN_1415e2f70(void* pAl, Unk_StlElem<0x190>* p, Unk_StlElem<0x190>* pVal);
extern void FUN_1415e2fc0(void* pAl, Unk_StlElem<0x190>* p, Unk_StlElem<0x190>* pVal);
extern void FUN_1415e3010(void* pAl, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal);
extern void FUN_1415e3060(void* pAl, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal);
extern void FUN_1415e30b0(void* pAl, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal);
extern void FUN_1415e3100(void* pAl, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal);
extern void FUN_1415e3150(void* pAl, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal);
extern void FUN_1415e31a0(void* pAl, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal);
extern void FUN_1415e31f0(void* pAl, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal);
extern void FUN_1415e3240(void* pAl, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal);
extern void FUN_1415e3290(void* pAl, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal);
extern void FUN_1415e32e0(void* pAl, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal);
extern void FUN_1415e3330(void* pAl, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal);
extern void FUN_1415e3380(void* pAl, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal);
extern void FUN_1415e33d0(void* pAl, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal);
extern void FUN_1415e3420(void* pAl, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal);
extern void FUN_1415e3470(void* pAl, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal);
extern void FUN_1415e34c0(void* pAl, Unk_StlElem<0xc8>* p, Unk_StlElem<0xc8>* pVal);
extern void FUN_1415e3510(void* pAl, Unk_StlElem<0xc8>* p, Unk_StlElem<0xc8>* pVal);
extern void FUN_1415e3560(void* pAl, Unk_StlElem<0xc8>* p, Unk_StlElem<0xc8>* pVal);
extern void FUN_1415e35b0(void* pAl, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal);
extern void FUN_1415e3600(void* pAl, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal);
extern void FUN_1415e3650(void* pAl, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal);
extern void FUN_1415e36a0(void* pAl, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal);
extern void FUN_1415e36f0(void* pAl, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal);
extern void FUN_1415e3740(void* pAl, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal);
extern void FUN_1415e3790(void* pAl, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal);
extern void FUN_1415e37e0(void* pAl, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal);
extern void FUN_1415e3830(void* pAl, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal);
extern void FUN_1415e38a0(void* pAl, Unk_StlElem<0x58>* p);
extern void FUN_1415e38d0(void* pAl, Unk_StlElem<0x30>* p);
extern void FUN_1415e3900(void* pAl, Unk_StlElem<0x98>* p);
extern void FUN_1415e3930(void* pAl, Unk_StlElem<0x220>* p);
extern void FUN_1415e3960(void* pAl, Unk_StlElem<0x128>* p);
extern void FUN_1415e3990(void* pAl, Unk_StlElem<0x118>* p);
extern void FUN_1415e39c0(void* pAl, Unk_StlElem<0xe0>* p);
extern void FUN_1415e39f0(void* pAl, Unk_StlElem<0x580>* p);
extern void FUN_1415e3a20(void* pAl, Unk_StlElem<0x18>* p);
extern void FUN_1415e3a50(void* pAl, Unk_StlElem<0x14a8>* p);
extern void FUN_1415e3a80(void* pAl, Unk_StlElem<0x18>* p);
extern void FUN_1415e3ab0(void* pAl, Unk_StlElem<0x190>* p);
extern void FUN_1415e3ae0(void* pAl, Unk_StlElem<0xb8>* p);
extern void FUN_1415e3b10(void* pAl, Unk_StlElem<0x58>* p);
extern void FUN_1415e3b40(void* pAl, Unk_StlElem<0x68>* p);
extern void FUN_1415e3b70(void* pAl, Unk_StlElem<0xae8>* p);
extern void FUN_1415e3ba0(void* pAl, Unk_StlElem<0xec8>* p);
extern void FUN_1415e3bd0(void* pAl, Unk_StlElem<0xc8>* p);
extern void FUN_1415e3c00(void* pAl, Unk_StlElem<0xf8>* p);
extern void FUN_1415e3c30(void* pAl, Unk_StlElem<0x490>* p);
extern void FUN_1415e3c60(void* pAl, Unk_StlElem<0x20>* p);
extern Unk_StlElem<0x58>* FUN_1415e4bf0(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x30>* FUN_1415e4c00(Unk_StlElem<0x30>* p);
extern Unk_StlElem<0x98>* FUN_1415e4c10(Unk_StlElem<0x98>* p);
extern Unk_StlElem<0x220>* FUN_1415e4c20(Unk_StlElem<0x220>* p);
extern Unk_StlElem<0x128>* FUN_1415e4c30(Unk_StlElem<0x128>* p);
extern Unk_StlElem<0x118>* FUN_1415e4c40(Unk_StlElem<0x118>* p);
extern Unk_StlElem<0x580>* FUN_1415e4c50(Unk_StlElem<0x580>* p);
extern Unk_StlElem<0x18>* FUN_1415e4c60(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x14a8>* FUN_1415e4c70(Unk_StlElem<0x14a8>* p);
extern Unk_StlElem<0x18>* FUN_1415e4c80(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x190>* FUN_1415e4c90(Unk_StlElem<0x190>* p);
extern Unk_StlElem<0xb8>* FUN_1415e4ca0(Unk_StlElem<0xb8>* p);
extern Unk_StlElem<0x58>* FUN_1415e4cb0(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0xae8>* FUN_1415e4cc0(Unk_StlElem<0xae8>* p);
extern Unk_StlElem<0xec8>* FUN_1415e4cd0(Unk_StlElem<0xec8>* p);
extern Unk_StlElem<0xc8>* FUN_1415e4ce0(Unk_StlElem<0xc8>* p);
extern Unk_StlElem<0xf8>* FUN_1415e4cf0(Unk_StlElem<0xf8>* p);
extern Unk_StlElem<0x490>* FUN_1415e4d00(Unk_StlElem<0x490>* p);
extern Unk_StlElem<0x20>* FUN_1415e4d10(Unk_StlElem<0x20>* p);
extern Unk_StlElem<0x10>* FUN_1415e4d20(Unk_StlElem<0x10>* p);
extern Unk_StlElem<0x18>* FUN_1415e4d30(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x58>* FUN_1415e4d40(Unk_StlElem<0x58>* p);
extern void* FUN_1415e4d50(void* p);
extern Unk_StlElem<0x98>* FUN_1415e4d60(Unk_StlElem<0x98>* p);
extern Unk_StlElem<0x220>* FUN_1415e4d70(Unk_StlElem<0x220>* p);
extern Unk_StlElem<0x128>* FUN_1415e4d80(Unk_StlElem<0x128>* p);
extern Unk_StlElem<0x118>* FUN_1415e4d90(Unk_StlElem<0x118>* p);
extern Unk_StlElem<0xe0>* FUN_1415e4da0(Unk_StlElem<0xe0>* p);
extern Unk_StlElem<0x580>* FUN_1415e4db0(Unk_StlElem<0x580>* p);
extern Unk_StlElem<0x18>* FUN_1415e4dc0(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x14a8>* FUN_1415e4dd0(Unk_StlElem<0x14a8>* p);
extern Unk_StlElem<0x18>* FUN_1415e4de0(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x190>* FUN_1415e4df0(Unk_StlElem<0x190>* p);
extern Unk_StlElem<0xb8>* FUN_1415e4e00(Unk_StlElem<0xb8>* p);
extern Unk_StlElem<0x58>* FUN_1415e4e10(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x68>* FUN_1415e4e20(Unk_StlElem<0x68>* p);
extern Unk_StlElem<0xae8>* FUN_1415e4e30(Unk_StlElem<0xae8>* p);
extern Unk_StlElem<0xec8>* FUN_1415e4e40(Unk_StlElem<0xec8>* p);
extern Unk_StlElem<0xc8>* FUN_1415e4e50(Unk_StlElem<0xc8>* p);
extern Unk_StlElem<0xf8>* FUN_1415e4e60(Unk_StlElem<0xf8>* p);
extern Unk_StlElem<0x490>* FUN_1415e4e70(Unk_StlElem<0x490>* p);
extern Unk_StlElem<0x20>* FUN_1415e4e80(Unk_StlElem<0x20>* p);
extern Unk_StlElem<0x58>* FUN_1415e4f60(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x30>* FUN_1415e4f70(Unk_StlElem<0x30>* p);
extern Unk_StlElem<0x98>* FUN_1415e4f80(Unk_StlElem<0x98>* p);
extern Unk_StlElem<0x220>* FUN_1415e4f90(Unk_StlElem<0x220>* p);
extern Unk_StlElem<0x128>* FUN_1415e4fa0(Unk_StlElem<0x128>* p);
extern Unk_StlElem<0x118>* FUN_1415e4fb0(Unk_StlElem<0x118>* p);
extern Unk_StlElem<0xe0>* FUN_1415e4fc0(Unk_StlElem<0xe0>* p);
extern Unk_StlElem<0x580>* FUN_1415e4fd0(Unk_StlElem<0x580>* p);
extern Unk_StlElem<0x18>* FUN_1415e4fe0(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x14a8>* FUN_1415e4ff0(Unk_StlElem<0x14a8>* p);
extern Unk_StlElem<0x18>* FUN_1415e5000(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x190>* FUN_1415e5010(Unk_StlElem<0x190>* p);
extern Unk_StlElem<0xb8>* FUN_1415e5020(Unk_StlElem<0xb8>* p);
extern Unk_StlElem<0x58>* FUN_1415e5030(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x68>* FUN_1415e5040(Unk_StlElem<0x68>* p);
extern Unk_StlElem<0xae8>* FUN_1415e5050(Unk_StlElem<0xae8>* p);
extern Unk_StlElem<0xec8>* FUN_1415e5060(Unk_StlElem<0xec8>* p);
extern Unk_StlElem<0xc8>* FUN_1415e5070(Unk_StlElem<0xc8>* p);
extern Unk_StlElem<0xf8>* FUN_1415e5080(Unk_StlElem<0xf8>* p);
extern Unk_StlElem<0x490>* FUN_1415e5090(Unk_StlElem<0x490>* p);
extern Unk_StlElem<0x20>* FUN_1415e50a0(Unk_StlElem<0x20>* p);
extern size_t FUN_1415fd6d0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fd760(void* pThis, size_t nNewSize);
extern size_t FUN_1415fd7f0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fd880(void* pThis, size_t nNewSize);
extern size_t FUN_1415fd910(void* pThis, size_t nNewSize);
extern size_t FUN_1415fd9a0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fda30(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdac0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdb50(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdbe0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdc70(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdd00(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdd90(void* pThis, size_t nNewSize);
extern size_t FUN_1415fde20(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdeb0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdf40(void* pThis, size_t nNewSize);
extern size_t FUN_1415fdfd0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fe060(void* pThis, size_t nNewSize);
extern size_t FUN_1415fe0f0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fe180(void* pThis, size_t nNewSize);
extern size_t FUN_1415fe210(void* pThis, size_t nNewSize);
extern size_t FUN_1415fe2a0(void* pThis, size_t nNewSize);
extern size_t FUN_1415fe330(void* pThis, size_t nNewSize);
extern void FUN_1415fe3c0(void* pThis, Unk_StlElem<0x10>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fe4d0(void* pThis, Unk_StlElem<0x18>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fe5e0(void* pThis, Unk_StlElem<0x58>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fe6f0(void* pThis, Unk_StlElem<0x30>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fe800(void* pThis, Unk_StlElem<0x98>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fe910(void* pThis, Unk_StlElem<0x220>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fea20(void* pThis, Unk_StlElem<0x128>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415feb30(void* pThis, Unk_StlElem<0x118>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fec40(void* pThis, Unk_StlElem<0xe0>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fed50(void* pThis, Unk_StlElem<0x580>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fee60(void* pThis, Unk_StlElem<0x18>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415fef70(void* pThis, Unk_StlElem<0x14a8>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff080(void* pThis, Unk_StlElem<0x18>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff190(void* pThis, Unk_StlElem<0x190>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff2a0(void* pThis, Unk_StlElem<0xb8>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff3b0(void* pThis, Unk_StlElem<0x58>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff4c0(void* pThis, Unk_StlElem<0x68>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff5d0(void* pThis, Unk_StlElem<0xae8>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff6e0(void* pThis, Unk_StlElem<0xec8>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff7f0(void* pThis, Unk_StlElem<0xc8>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ff900(void* pThis, Unk_StlElem<0xf8>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ffa10(void* pThis, Unk_StlElem<0x490>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_1415ffb20(void* pThis, Unk_StlElem<0x20>* pNewVec, size_t nNewSize, size_t nNewCapacity);
extern void FUN_141600150(void* pThis, Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast);
extern void FUN_141600190(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast);
extern void FUN_1416001d0(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast);
extern void FUN_141600210(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast);
extern void FUN_141600250(void* pThis, Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast);
extern void FUN_141600290(void* pThis, Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast);
extern void FUN_1416002d0(void* pThis, Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast);
extern void FUN_141600310(void* pThis, Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast);
extern void FUN_141600350(void* pThis, Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* pLast);
extern void FUN_141600390(void* pThis, Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast);
extern void FUN_1416003d0(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast);
extern void FUN_141600410(void* pThis, Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast);
extern void FUN_141600450(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast);
extern void FUN_141600490(void* pThis, Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast);
extern void FUN_1416004d0(void* pThis, Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast);
extern void FUN_141600510(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast);
extern void FUN_141600550(void* pThis, Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* pLast);
extern void FUN_141600590(void* pThis, Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast);
extern void FUN_1416005d0(void* pThis, Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast);
extern void FUN_141600610(void* pThis, Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast);
extern void FUN_141600650(void* pThis, Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast);
extern void FUN_141600690(void* pThis, Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast);
extern void FUN_1416006d0(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast);
extern void* FUN_141601ad0(void* pThis);
extern void* FUN_141601b10(void* pThis);
extern void* FUN_141601b50(void* pThis);
extern void* FUN_141601b90(void* pThis);
extern void* FUN_141601bd0(void* pThis);
extern void* FUN_141601c10(void* pThis);
extern void* FUN_141601c50(void* pThis);
extern void* FUN_141601c90(void* pThis);
extern void* FUN_141601cd0(void* pThis);
extern void* FUN_141601d10(void* pThis);
extern void* FUN_141601d50(void* pThis);
extern void* FUN_141601d90(void* pThis);
extern void* FUN_141601dd0(void* pThis);
extern void* FUN_141601e10(void* pThis);
extern void* FUN_141601e50(void* pThis);
extern void* FUN_141601e90(void* pThis);
extern void* FUN_141601ed0(void* pThis);
extern void* FUN_141601f10(void* pThis);
extern void* FUN_141601f50(void* pThis);
extern void* FUN_141601f90(void* pThis);
extern void* FUN_141601fd0(void* pThis);
extern void* FUN_141602010(void* pThis);
extern void* FUN_141602050(void* pThis);
extern Unk_StlElem<0x10>*& FUN_1416033c0(void* pThis);
extern Unk_StlElem<0x18>*& FUN_141603400(void* pThis);
extern Unk_StlElem<0x58>*& FUN_141603440(void* pThis);
extern Unk_StlElem<0x30>*& FUN_141603480(void* pThis);
extern Unk_StlElem<0x98>*& FUN_1416034c0(void* pThis);
extern Unk_StlElem<0x220>*& FUN_141603500(void* pThis);
extern Unk_StlElem<0x128>*& FUN_141603540(void* pThis);
extern Unk_StlElem<0x118>*& FUN_141603580(void* pThis);
extern Unk_StlElem<0xe0>*& FUN_1416035c0(void* pThis);
extern Unk_StlElem<0x580>*& FUN_141603600(void* pThis);
extern Unk_StlElem<0x18>*& FUN_141603640(void* pThis);
extern Unk_StlElem<0x14a8>*& FUN_141603680(void* pThis);
extern Unk_StlElem<0x18>*& FUN_1416036c0(void* pThis);
extern Unk_StlElem<0x190>*& FUN_141603700(void* pThis);
extern Unk_StlElem<0xb8>*& FUN_141603740(void* pThis);
extern Unk_StlElem<0x58>*& FUN_141603780(void* pThis);
extern Unk_StlElem<0x68>*& FUN_1416037c0(void* pThis);
extern Unk_StlElem<0xae8>*& FUN_141603800(void* pThis);
extern Unk_StlElem<0xec8>*& FUN_141603840(void* pThis);
extern Unk_StlElem<0xc8>*& FUN_141603880(void* pThis);
extern Unk_StlElem<0xf8>*& FUN_1416038c0(void* pThis);
extern Unk_StlElem<0x490>*& FUN_141603900(void* pThis);
extern Unk_StlElem<0x20>*& FUN_141603940(void* pThis);
extern Unk_StlElem<0x10>*& FUN_141603980(void* pThis);
extern Unk_StlElem<0x18>*& FUN_1416039c0(void* pThis);
extern Unk_StlElem<0x58>*& FUN_141603a00(void* pThis);
extern Unk_StlElem<0x30>*& FUN_141603a40(void* pThis);
extern Unk_StlElem<0x98>*& FUN_141603a80(void* pThis);
extern Unk_StlElem<0x220>*& FUN_141603ac0(void* pThis);
extern Unk_StlElem<0x128>*& FUN_141603b00(void* pThis);
extern Unk_StlElem<0x118>*& FUN_141603b40(void* pThis);
extern Unk_StlElem<0xe0>*& FUN_141603b80(void* pThis);
extern Unk_StlElem<0x580>*& FUN_141603bc0(void* pThis);
extern Unk_StlElem<0x18>*& FUN_141603c00(void* pThis);
extern Unk_StlElem<0x14a8>*& FUN_141603c40(void* pThis);
extern Unk_StlElem<0x18>*& FUN_141603c80(void* pThis);
extern Unk_StlElem<0x190>*& FUN_141603cc0(void* pThis);
extern Unk_StlElem<0xb8>*& FUN_141603d00(void* pThis);
extern Unk_StlElem<0x58>*& FUN_141603d40(void* pThis);
extern Unk_StlElem<0x68>*& FUN_141603d80(void* pThis);
extern Unk_StlElem<0xae8>*& FUN_141603dc0(void* pThis);
extern Unk_StlElem<0xec8>*& FUN_141603e00(void* pThis);
extern Unk_StlElem<0xc8>*& FUN_141603e40(void* pThis);
extern Unk_StlElem<0xf8>*& FUN_141603e80(void* pThis);
extern Unk_StlElem<0x490>*& FUN_141603ec0(void* pThis);
extern Unk_StlElem<0x20>*& FUN_141603f00(void* pThis);
extern void FUN_141604220(void* pThis, Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast);
extern void FUN_141604230(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast);
extern void FUN_141604240(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast);
extern void FUN_141604250(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast);
extern void FUN_141604260(void* pThis, Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast);
extern void FUN_141604270(void* pThis, Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast);
extern void FUN_141604280(void* pThis, Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast);
extern void FUN_141604290(void* pThis, Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast);
extern void FUN_1416042a0(void* pThis, Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* pLast);
extern void FUN_1416042b0(void* pThis, Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast);
extern void FUN_1416042c0(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast);
extern void FUN_1416042d0(void* pThis, Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast);
extern void FUN_1416042e0(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast);
extern void FUN_1416042f0(void* pThis, Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast);
extern void FUN_141604300(void* pThis, Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast);
extern void FUN_141604310(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast);
extern void FUN_141604320(void* pThis, Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* pLast);
extern void FUN_141604330(void* pThis, Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast);
extern void FUN_141604340(void* pThis, Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast);
extern void FUN_141604350(void* pThis, Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast);
extern void FUN_141604360(void* pThis, Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast);
extern void FUN_141604370(void* pThis, Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast);
extern void FUN_141604380(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast);
extern Unk_StlElem<0x10>* FUN_141605bd0(void* pThis, Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast, Unk_StlElem<0x10>* pDest);
extern Unk_StlElem<0x18>* FUN_141605c10(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
extern Unk_StlElem<0x58>* FUN_141605c50(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest);
extern Unk_StlElem<0x30>* FUN_141605c90(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, Unk_StlElem<0x30>* pDest);
extern Unk_StlElem<0x98>* FUN_141605cd0(void* pThis, Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast, Unk_StlElem<0x98>* pDest);
extern Unk_StlElem<0x220>* FUN_141605d10(void* pThis, Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast, Unk_StlElem<0x220>* pDest);
extern Unk_StlElem<0x128>* FUN_141605d50(void* pThis, Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast, Unk_StlElem<0x128>* pDest);
extern Unk_StlElem<0x118>* FUN_141605d90(void* pThis, Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast, Unk_StlElem<0x118>* pDest);
extern Unk_StlElem<0xe0>* FUN_141605dd0(void* pThis, Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* pLast, Unk_StlElem<0xe0>* pDest);
extern Unk_StlElem<0x580>* FUN_141605e10(void* pThis, Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast, Unk_StlElem<0x580>* pDest);
extern Unk_StlElem<0x18>* FUN_141605e50(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
extern Unk_StlElem<0x14a8>* FUN_141605e90(void* pThis, Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast, Unk_StlElem<0x14a8>* pDest);
extern Unk_StlElem<0x18>* FUN_141605ed0(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
extern Unk_StlElem<0x190>* FUN_141605f10(void* pThis, Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast, Unk_StlElem<0x190>* pDest);
extern Unk_StlElem<0xb8>* FUN_141605f50(void* pThis, Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast, Unk_StlElem<0xb8>* pDest);
extern Unk_StlElem<0x58>* FUN_141605f90(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest);
extern Unk_StlElem<0x68>* FUN_141605fd0(void* pThis, Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* pLast, Unk_StlElem<0x68>* pDest);
extern Unk_StlElem<0xae8>* FUN_141606010(void* pThis, Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast, Unk_StlElem<0xae8>* pDest);
extern Unk_StlElem<0xec8>* FUN_141606050(void* pThis, Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast, Unk_StlElem<0xec8>* pDest);
extern Unk_StlElem<0xc8>* FUN_141606090(void* pThis, Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast, Unk_StlElem<0xc8>* pDest);
extern Unk_StlElem<0xf8>* FUN_1416060d0(void* pThis, Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast, Unk_StlElem<0xf8>* pDest);
extern Unk_StlElem<0x490>* FUN_141606110(void* pThis, Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast, Unk_StlElem<0x490>* pDest);
extern Unk_StlElem<0x20>* FUN_141606150(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, Unk_StlElem<0x20>* pDest);
extern void FUN_141606750(void* pThis, Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast, Unk_StlElem<0x10>* pDest);
extern void FUN_1416067b0(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
extern void FUN_141606810(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest);
extern void FUN_141606870(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, Unk_StlElem<0x30>* pDest);
extern void FUN_1416068d0(void* pThis, Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast, Unk_StlElem<0x98>* pDest);
extern void FUN_141606930(void* pThis, Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast, Unk_StlElem<0x220>* pDest);
extern void FUN_141606990(void* pThis, Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast, Unk_StlElem<0x128>* pDest);
extern void FUN_1416069f0(void* pThis, Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast, Unk_StlElem<0x118>* pDest);
extern void FUN_141606a50(void* pThis, Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* pLast, Unk_StlElem<0xe0>* pDest);
extern void FUN_141606ab0(void* pThis, Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast, Unk_StlElem<0x580>* pDest);
extern void FUN_141606b10(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
extern void FUN_141606b70(void* pThis, Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast, Unk_StlElem<0x14a8>* pDest);
extern void FUN_141606bd0(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
extern void FUN_141606c30(void* pThis, Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast, Unk_StlElem<0x190>* pDest);
extern void FUN_141606c90(void* pThis, Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast, Unk_StlElem<0xb8>* pDest);
extern void FUN_141606cf0(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest);
extern void FUN_141606d50(void* pThis, Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* pLast, Unk_StlElem<0x68>* pDest);
extern void FUN_141606db0(void* pThis, Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast, Unk_StlElem<0xae8>* pDest);
extern void FUN_141606e10(void* pThis, Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast, Unk_StlElem<0xec8>* pDest);
extern void FUN_141606e70(void* pThis, Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast, Unk_StlElem<0xc8>* pDest);
extern void FUN_141606ed0(void* pThis, Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast, Unk_StlElem<0xf8>* pDest);
extern void FUN_141606f30(void* pThis, Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast, Unk_StlElem<0x490>* pDest);
extern void FUN_141606f90(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, Unk_StlElem<0x20>* pDest);
extern void FUN_141607020();
extern void FUN_141607040();
extern void FUN_141607060();
extern void FUN_141607080();
extern void FUN_1416070a0();
extern void FUN_1416070c0();
extern void FUN_1416070e0();
extern void FUN_141607100();
extern void FUN_141607120();
extern void FUN_141607140();
extern void FUN_141607160();
extern void FUN_141607180();
extern void FUN_1416071a0();
extern void FUN_1416071c0();
extern void FUN_1416071e0();
extern void FUN_141607200();
extern void FUN_141607220();
extern void FUN_141607240();
extern void FUN_141607260();
extern void FUN_141607280();
extern void FUN_1416072a0();
extern void FUN_1416072c0();
extern void FUN_1416072e0();
extern Unk_StlElem<0x10>* FUN_141607330(void* pAl, size_t n);
extern Unk_StlElem<0x18>* FUN_141607360(void* pAl, size_t n);
extern Unk_StlElem<0x58>* FUN_141607390(void* pAl, size_t n);
extern Unk_StlElem<0x30>* FUN_1416073c0(void* pAl, size_t n);
extern Unk_StlElem<0x98>* FUN_1416073f0(void* pAl, size_t n);
extern Unk_StlElem<0x220>* FUN_141607420(void* pAl, size_t n);
extern Unk_StlElem<0x128>* FUN_141607450(void* pAl, size_t n);
extern Unk_StlElem<0x118>* FUN_141607480(void* pAl, size_t n);
extern Unk_StlElem<0xe0>* FUN_1416074b0(void* pAl, size_t n);
extern Unk_StlElem<0x580>* FUN_1416074e0(void* pAl, size_t n);
extern Unk_StlElem<0x18>* FUN_141607510(void* pAl, size_t n);
extern Unk_StlElem<0x14a8>* FUN_141607540(void* pAl, size_t n);
extern Unk_StlElem<0x18>* FUN_141607570(void* pAl, size_t n);
extern Unk_StlElem<0x190>* FUN_1416075a0(void* pAl, size_t n);
extern Unk_StlElem<0xb8>* FUN_1416075d0(void* pAl, size_t n);
extern Unk_StlElem<0x58>* FUN_141607600(void* pAl, size_t n);
extern Unk_StlElem<0x68>* FUN_141607630(void* pAl, size_t n);
extern Unk_StlElem<0xae8>* FUN_141607660(void* pAl, size_t n);
extern Unk_StlElem<0xec8>* FUN_141607690(void* pAl, size_t n);
extern Unk_StlElem<0xc8>* FUN_1416076c0(void* pAl, size_t n);
extern Unk_StlElem<0xf8>* FUN_1416076f0(void* pAl, size_t n);
extern Unk_StlElem<0x490>* FUN_141607720(void* pAl, size_t n);
extern Unk_StlElem<0x20>* FUN_141607750(void* pAl, size_t n);
extern void FUN_1416094c0(void* pAl, Unk_StlElem<0x10>* p, size_t n);
extern void FUN_1416094f0(void* pAl, Unk_StlElem<0x18>* p, size_t n);
extern void FUN_141609520(void* pAl, Unk_StlElem<0x58>* p, size_t n);
extern void FUN_141609550(void* pAl, Unk_StlElem<0x30>* p, size_t n);
extern void FUN_141609580(void* pAl, Unk_StlElem<0x98>* p, size_t n);
extern void FUN_1416095b0(void* pAl, Unk_StlElem<0x220>* p, size_t n);
extern void FUN_1416095e0(void* pAl, Unk_StlElem<0x128>* p, size_t n);
extern void FUN_141609610(void* pAl, Unk_StlElem<0x118>* p, size_t n);
extern void FUN_141609640(void* pAl, Unk_StlElem<0xe0>* p, size_t n);
extern void FUN_141609670(void* pAl, Unk_StlElem<0x580>* p, size_t n);
extern void FUN_1416096a0(void* pAl, Unk_StlElem<0x18>* p, size_t n);
extern void FUN_1416096d0(void* pAl, Unk_StlElem<0x14a8>* p, size_t n);
extern void FUN_141609700(void* pAl, Unk_StlElem<0x18>* p, size_t n);
extern void FUN_141609730(void* pAl, Unk_StlElem<0x190>* p, size_t n);
extern void FUN_141609760(void* pAl, Unk_StlElem<0xb8>* p, size_t n);
extern void FUN_141609790(void* pAl, Unk_StlElem<0x58>* p, size_t n);
extern void FUN_1416097c0(void* pAl, Unk_StlElem<0x68>* p, size_t n);
extern void FUN_1416097f0(void* pAl, Unk_StlElem<0xae8>* p, size_t n);
extern void FUN_141609820(void* pAl, Unk_StlElem<0xec8>* p, size_t n);
extern void FUN_141609850(void* pAl, Unk_StlElem<0xc8>* p, size_t n);
extern void FUN_141609880(void* pAl, Unk_StlElem<0xf8>* p, size_t n);
extern void FUN_1416098b0(void* pAl, Unk_StlElem<0x490>* p, size_t n);
extern void FUN_1416098e0(void* pAl, Unk_StlElem<0x20>* p, size_t n);
extern size_t FUN_14160a990(void* pThis);
extern size_t FUN_14160a9e0(void* pThis);
extern size_t FUN_14160aa30(void* pThis);
extern size_t FUN_14160aa80(void* pThis);
extern size_t FUN_14160aad0(void* pThis);
extern size_t FUN_14160ab20(void* pThis);
extern size_t FUN_14160ab70(void* pThis);
extern size_t FUN_14160abc0(void* pThis);
extern size_t FUN_14160ac10(void* pThis);
extern size_t FUN_14160ac60(void* pThis);
extern size_t FUN_14160acb0(void* pThis);
extern size_t FUN_14160ad00(void* pThis);
extern size_t FUN_14160ad50(void* pThis);
extern size_t FUN_14160ada0(void* pThis);
extern size_t FUN_14160adf0(void* pThis);
extern size_t FUN_14160ae40(void* pThis);
extern size_t FUN_14160ae90(void* pThis);
extern size_t FUN_14160aee0(void* pThis);
extern size_t FUN_14160af30(void* pThis);
extern size_t FUN_14160af80(void* pThis);
extern size_t FUN_14160afd0(void* pThis);
extern size_t FUN_14160b020(void* pThis);
extern size_t FUN_14160b070(void* pThis);
extern size_t FUN_14160b620(void* pThis);
extern size_t FUN_14160b660(void* pThis);
extern size_t FUN_14160b6b0(void* pThis);
extern size_t FUN_14160b700(void* pThis);
extern size_t FUN_14160b750(void* pThis);
extern size_t FUN_14160b7a0(void* pThis);
extern size_t FUN_14160b7f0(void* pThis);
extern size_t FUN_14160b840(void* pThis);
extern size_t FUN_14160b890(void* pThis);
extern size_t FUN_14160b8e0(void* pThis);
extern size_t FUN_14160b930(void* pThis);
extern size_t FUN_14160b980(void* pThis);
extern size_t FUN_14160b9d0(void* pThis);
extern size_t FUN_14160ba20(void* pThis);
extern size_t FUN_14160ba70(void* pThis);
extern size_t FUN_14160bac0(void* pThis);
extern size_t FUN_14160bb10(void* pThis);
extern size_t FUN_14160bb60(void* pThis);
extern size_t FUN_14160bbb0(void* pThis);
extern size_t FUN_14160bc00(void* pThis);
extern size_t FUN_14160bc50(void* pThis);
extern size_t FUN_14160bca0(void* pThis);
extern size_t FUN_14160bcf0(void* pThis);

// @0x1415d3570
void FUN_1415d3570(void* pFirst, void* pLast, void* pAl, std::true_type)
{
}

// @0x1415d3590
void FUN_1415d3590(void* pFirst, void* pLast, void* pAl, std::true_type)
{
}

// @0x1415d35b0
void FUN_1415d35b0(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e38a0(pAl, FUN_1415dd7e0(pFirst));
}

// @0x1415d3610
void FUN_1415d3610(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e38d0(pAl, FUN_1415dd7f0(pFirst));
}

// @0x1415d3670
void FUN_1415d3670(Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3900(pAl, FUN_1415dd800(pFirst));
}

// @0x1415d36d0
void FUN_1415d36d0(Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3930(pAl, FUN_1415dd810(pFirst));
}

// @0x1415d3730
void FUN_1415d3730(Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3960(pAl, FUN_1415dd820(pFirst));
}

// @0x1415d3790
void FUN_1415d3790(Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3990(pAl, FUN_1415dd830(pFirst));
}

// @0x1415d37f0
void FUN_1415d37f0(Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e39c0(pAl, FUN_1415dd840(pFirst));
}

// @0x1415d3850
void FUN_1415d3850(Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e39f0(pAl, FUN_1415dd850(pFirst));
}

// @0x1415d38b0
void FUN_1415d38b0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3a20(pAl, FUN_1415dd860(pFirst));
}

// @0x1415d3910
void FUN_1415d3910(Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3a50(pAl, FUN_1415dd870(pFirst));
}

// @0x1415d3970
void FUN_1415d3970(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3a80(pAl, FUN_1415dd880(pFirst));
}

// @0x1415d39d0
void FUN_1415d39d0(Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3ab0(pAl, FUN_1415dd890(pFirst));
}

// @0x1415d3a30
void FUN_1415d3a30(Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3ae0(pAl, FUN_1415dd8a0(pFirst));
}

// @0x1415d3a90
void FUN_1415d3a90(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3b10(pAl, FUN_1415dd8b0(pFirst));
}

// @0x1415d3af0
void FUN_1415d3af0(Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3b40(pAl, FUN_1415dd8c0(pFirst));
}

// @0x1415d3b50
void FUN_1415d3b50(Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3b70(pAl, FUN_1415dd8d0(pFirst));
}

// @0x1415d3bb0
void FUN_1415d3bb0(Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3ba0(pAl, FUN_1415dd8e0(pFirst));
}

// @0x1415d3c10
void FUN_1415d3c10(Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3bd0(pAl, FUN_1415dd8f0(pFirst));
}

// @0x1415d3c70
void FUN_1415d3c70(Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3c00(pAl, FUN_1415dd900(pFirst));
}

// @0x1415d3cd0
void FUN_1415d3cd0(Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3c30(pAl, FUN_1415dd910(pFirst));
}

// @0x1415d3d30
void FUN_1415d3d30(Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, void* pAl, std::false_type)
{
    for (; pFirst != pLast; ++pFirst)
        FUN_1415e3c60(pAl, FUN_1415dd920(pFirst));
}

// @0x1415d3d90
void FUN_1415d3d90(void* pFirst, void* pLast, void* pAl)
{
    FUN_1415d3570(pFirst, pLast, pAl, std::true_type{});
}

// @0x1415d3de0
void FUN_1415d3de0(void* pFirst, void* pLast, void* pAl)
{
    FUN_1415d3590(pFirst, pLast, pAl, std::true_type{});
}

// @0x1415d3e30
void FUN_1415d3e30(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, void* pAl)
{
    FUN_1415d35b0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d3e80
void FUN_1415d3e80(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, void* pAl)
{
    FUN_1415d3610(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d3ed0
void FUN_1415d3ed0(Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast, void* pAl)
{
    FUN_1415d3670(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d3f20
void FUN_1415d3f20(Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast, void* pAl)
{
    FUN_1415d36d0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d3f70
void FUN_1415d3f70(Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast, void* pAl)
{
    FUN_1415d3730(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d3fc0
void FUN_1415d3fc0(Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast, void* pAl)
{
    FUN_1415d3790(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4010
void FUN_1415d4010(Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* pLast, void* pAl)
{
    FUN_1415d37f0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4060
void FUN_1415d4060(Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast, void* pAl)
{
    FUN_1415d3850(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d40b0
void FUN_1415d40b0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, void* pAl)
{
    FUN_1415d38b0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4100
void FUN_1415d4100(Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast, void* pAl)
{
    FUN_1415d3910(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4150
void FUN_1415d4150(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, void* pAl)
{
    FUN_1415d3970(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d41a0
void FUN_1415d41a0(Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast, void* pAl)
{
    FUN_1415d39d0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d41f0
void FUN_1415d41f0(Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast, void* pAl)
{
    FUN_1415d3a30(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4240
void FUN_1415d4240(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, void* pAl)
{
    FUN_1415d3a90(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4290
void FUN_1415d4290(Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* pLast, void* pAl)
{
    FUN_1415d3af0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d42e0
void FUN_1415d42e0(Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast, void* pAl)
{
    FUN_1415d3b50(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4330
void FUN_1415d4330(Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast, void* pAl)
{
    FUN_1415d3bb0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4380
void FUN_1415d4380(Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast, void* pAl)
{
    FUN_1415d3c10(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d43d0
void FUN_1415d43d0(Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast, void* pAl)
{
    FUN_1415d3c70(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4420
void FUN_1415d4420(Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast, void* pAl)
{
    FUN_1415d3cd0(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d4470
void FUN_1415d4470(Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, void* pAl)
{
    FUN_1415d3d30(pFirst, pLast, pAl, std::false_type{});
}

// @0x1415d44c0
ptrdiff_t FUN_1415d44c0(Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d44f0
ptrdiff_t FUN_1415d44f0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4520
ptrdiff_t FUN_1415d4520(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4550
ptrdiff_t FUN_1415d4550(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4580
ptrdiff_t FUN_1415d4580(Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d45b0
ptrdiff_t FUN_1415d45b0(Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d45e0
ptrdiff_t FUN_1415d45e0(Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4610
ptrdiff_t FUN_1415d4610(Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4640
ptrdiff_t FUN_1415d4640(Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4670
ptrdiff_t FUN_1415d4670(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d46a0
ptrdiff_t FUN_1415d46a0(Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d46d0
ptrdiff_t FUN_1415d46d0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4700
ptrdiff_t FUN_1415d4700(Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4730
ptrdiff_t FUN_1415d4730(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4760
ptrdiff_t FUN_1415d4760(Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4790
ptrdiff_t FUN_1415d4790(Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d47c0
ptrdiff_t FUN_1415d47c0(Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d47f0
ptrdiff_t FUN_1415d47f0(Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4820
ptrdiff_t FUN_1415d4820(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415d4850
void FUN_1415d4850(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal)
{
    FUN_1415e2520(pThis->m_pAl, FUN_1415dd7e0(pThis->m_pLast), FUN_1415e4bf0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d48b0
void FUN_1415d48b0(Unk_StlBackout<Unk_StlElem<0x30>>* pThis, Unk_StlElem<0x30>* pVal)
{
    FUN_1415e2610(pThis->m_pAl, FUN_1415dd7f0(pThis->m_pLast), FUN_1415e4c00(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4910
void FUN_1415d4910(Unk_StlBackout<Unk_StlElem<0x98>>* pThis, Unk_StlElem<0x98>* pVal)
{
    FUN_1415e2700(pThis->m_pAl, FUN_1415dd800(pThis->m_pLast), FUN_1415e4c10(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4980
void FUN_1415d4980(Unk_StlBackout<Unk_StlElem<0x220>>* pThis, Unk_StlElem<0x220>* pVal)
{
    FUN_1415e27f0(pThis->m_pAl, FUN_1415dd810(pThis->m_pLast), FUN_1415e4c20(pVal));
    ++pThis->m_pLast;
}

// @0x1415d49f0
void FUN_1415d49f0(Unk_StlBackout<Unk_StlElem<0x128>>* pThis, Unk_StlElem<0x128>* pVal)
{
    FUN_1415e28e0(pThis->m_pAl, FUN_1415dd820(pThis->m_pLast), FUN_1415e4c30(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4a60
void FUN_1415d4a60(Unk_StlBackout<Unk_StlElem<0x118>>* pThis, Unk_StlElem<0x118>* pVal)
{
    FUN_1415e29d0(pThis->m_pAl, FUN_1415dd830(pThis->m_pLast), FUN_1415e4c40(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4ad0
void FUN_1415d4ad0(Unk_StlBackout<Unk_StlElem<0x580>>* pThis, Unk_StlElem<0x580>* pVal)
{
    FUN_1415e2b60(pThis->m_pAl, FUN_1415dd850(pThis->m_pLast), FUN_1415e4c50(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4b40
void FUN_1415d4b40(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal)
{
    FUN_1415e2c50(pThis->m_pAl, FUN_1415dd860(pThis->m_pLast), FUN_1415e4c60(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4ba0
void FUN_1415d4ba0(Unk_StlBackout<Unk_StlElem<0x14a8>>* pThis, Unk_StlElem<0x14a8>* pVal)
{
    FUN_1415e2d40(pThis->m_pAl, FUN_1415dd870(pThis->m_pLast), FUN_1415e4c70(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4c10
void FUN_1415d4c10(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal)
{
    FUN_1415e2e30(pThis->m_pAl, FUN_1415dd880(pThis->m_pLast), FUN_1415e4c80(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4c70
void FUN_1415d4c70(Unk_StlBackout<Unk_StlElem<0x190>>* pThis, Unk_StlElem<0x190>* pVal)
{
    FUN_1415e2f20(pThis->m_pAl, FUN_1415dd890(pThis->m_pLast), FUN_1415e4c90(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4ce0
void FUN_1415d4ce0(Unk_StlBackout<Unk_StlElem<0xb8>>* pThis, Unk_StlElem<0xb8>* pVal)
{
    FUN_1415e3010(pThis->m_pAl, FUN_1415dd8a0(pThis->m_pLast), FUN_1415e4ca0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4d50
void FUN_1415d4d50(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal)
{
    FUN_1415e3150(pThis->m_pAl, FUN_1415dd8b0(pThis->m_pLast), FUN_1415e4cb0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4db0
void FUN_1415d4db0(Unk_StlBackout<Unk_StlElem<0xae8>>* pThis, Unk_StlElem<0xae8>* pVal)
{
    FUN_1415e32e0(pThis->m_pAl, FUN_1415dd8d0(pThis->m_pLast), FUN_1415e4cc0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4e20
void FUN_1415d4e20(Unk_StlBackout<Unk_StlElem<0xec8>>* pThis, Unk_StlElem<0xec8>* pVal)
{
    FUN_1415e33d0(pThis->m_pAl, FUN_1415dd8e0(pThis->m_pLast), FUN_1415e4cd0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4e90
void FUN_1415d4e90(Unk_StlBackout<Unk_StlElem<0xc8>>* pThis, Unk_StlElem<0xc8>* pVal)
{
    FUN_1415e34c0(pThis->m_pAl, FUN_1415dd8f0(pThis->m_pLast), FUN_1415e4ce0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4f00
void FUN_1415d4f00(Unk_StlBackout<Unk_StlElem<0xf8>>* pThis, Unk_StlElem<0xf8>* pVal)
{
    FUN_1415e35b0(pThis->m_pAl, FUN_1415dd900(pThis->m_pLast), FUN_1415e4cf0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4f70
void FUN_1415d4f70(Unk_StlBackout<Unk_StlElem<0x490>>* pThis, Unk_StlElem<0x490>* pVal)
{
    FUN_1415e36a0(pThis->m_pAl, FUN_1415dd910(pThis->m_pLast), FUN_1415e4d00(pVal));
    ++pThis->m_pLast;
}

// @0x1415d4fe0
void FUN_1415d4fe0(Unk_StlBackout<Unk_StlElem<0x20>>* pThis, Unk_StlElem<0x20>* pVal)
{
    FUN_1415e3790(pThis->m_pAl, FUN_1415dd920(pThis->m_pLast), FUN_1415e4d10(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5040
void FUN_1415d5040(Unk_StlBackout<Unk_StlElem<0xb8>>* pThis, Unk_StlElem<0xb8>* pVal)
{
    FUN_1415e30b0(pThis->m_pAl, FUN_1415dd8a0(pThis->m_pLast), static_cast<Unk_StlElem<0xb8>*>(FUN_1415e4d50(pVal)));
    ++pThis->m_pLast;
}

// @0x1415d50b0
void FUN_1415d50b0(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal)
{
    FUN_1415e25c0(pThis->m_pAl, FUN_1415dd7e0(pThis->m_pLast), FUN_1415e4f60(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5110
void FUN_1415d5110(Unk_StlBackout<Unk_StlElem<0x30>>* pThis, Unk_StlElem<0x30>* pVal)
{
    FUN_1415e26b0(pThis->m_pAl, FUN_1415dd7f0(pThis->m_pLast), FUN_1415e4f70(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5170
void FUN_1415d5170(Unk_StlBackout<Unk_StlElem<0x98>>* pThis, Unk_StlElem<0x98>* pVal)
{
    FUN_1415e27a0(pThis->m_pAl, FUN_1415dd800(pThis->m_pLast), FUN_1415e4f80(pVal));
    ++pThis->m_pLast;
}

// @0x1415d51e0
void FUN_1415d51e0(Unk_StlBackout<Unk_StlElem<0x220>>* pThis, Unk_StlElem<0x220>* pVal)
{
    FUN_1415e2890(pThis->m_pAl, FUN_1415dd810(pThis->m_pLast), FUN_1415e4f90(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5250
void FUN_1415d5250(Unk_StlBackout<Unk_StlElem<0x128>>* pThis, Unk_StlElem<0x128>* pVal)
{
    FUN_1415e2980(pThis->m_pAl, FUN_1415dd820(pThis->m_pLast), FUN_1415e4fa0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d52c0
void FUN_1415d52c0(Unk_StlBackout<Unk_StlElem<0x118>>* pThis, Unk_StlElem<0x118>* pVal)
{
    FUN_1415e2a70(pThis->m_pAl, FUN_1415dd830(pThis->m_pLast), FUN_1415e4fb0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5330
void FUN_1415d5330(Unk_StlBackout<Unk_StlElem<0xe0>>* pThis, Unk_StlElem<0xe0>* pVal)
{
    FUN_1415e2b10(pThis->m_pAl, FUN_1415dd840(pThis->m_pLast), FUN_1415e4fc0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d53a0
void FUN_1415d53a0(Unk_StlBackout<Unk_StlElem<0x580>>* pThis, Unk_StlElem<0x580>* pVal)
{
    FUN_1415e2c00(pThis->m_pAl, FUN_1415dd850(pThis->m_pLast), FUN_1415e4fd0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5410
void FUN_1415d5410(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal)
{
    FUN_1415e2cf0(pThis->m_pAl, FUN_1415dd860(pThis->m_pLast), FUN_1415e4fe0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5470
void FUN_1415d5470(Unk_StlBackout<Unk_StlElem<0x14a8>>* pThis, Unk_StlElem<0x14a8>* pVal)
{
    FUN_1415e2de0(pThis->m_pAl, FUN_1415dd870(pThis->m_pLast), FUN_1415e4ff0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d54e0
void FUN_1415d54e0(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal)
{
    FUN_1415e2ed0(pThis->m_pAl, FUN_1415dd880(pThis->m_pLast), FUN_1415e5000(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5540
void FUN_1415d5540(Unk_StlBackout<Unk_StlElem<0x190>>* pThis, Unk_StlElem<0x190>* pVal)
{
    FUN_1415e2fc0(pThis->m_pAl, FUN_1415dd890(pThis->m_pLast), FUN_1415e5010(pVal));
    ++pThis->m_pLast;
}

// @0x1415d55b0
void FUN_1415d55b0(Unk_StlBackout<Unk_StlElem<0xb8>>* pThis, Unk_StlElem<0xb8>* pVal)
{
    FUN_1415e3100(pThis->m_pAl, FUN_1415dd8a0(pThis->m_pLast), FUN_1415e5020(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5620
void FUN_1415d5620(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal)
{
    FUN_1415e31f0(pThis->m_pAl, FUN_1415dd8b0(pThis->m_pLast), FUN_1415e5030(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5680
void FUN_1415d5680(Unk_StlBackout<Unk_StlElem<0x68>>* pThis, Unk_StlElem<0x68>* pVal)
{
    FUN_1415e3290(pThis->m_pAl, FUN_1415dd8c0(pThis->m_pLast), FUN_1415e5040(pVal));
    ++pThis->m_pLast;
}

// @0x1415d56e0
void FUN_1415d56e0(Unk_StlBackout<Unk_StlElem<0xae8>>* pThis, Unk_StlElem<0xae8>* pVal)
{
    FUN_1415e3380(pThis->m_pAl, FUN_1415dd8d0(pThis->m_pLast), FUN_1415e5050(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5750
void FUN_1415d5750(Unk_StlBackout<Unk_StlElem<0xec8>>* pThis, Unk_StlElem<0xec8>* pVal)
{
    FUN_1415e3470(pThis->m_pAl, FUN_1415dd8e0(pThis->m_pLast), FUN_1415e5060(pVal));
    ++pThis->m_pLast;
}

// @0x1415d57c0
void FUN_1415d57c0(Unk_StlBackout<Unk_StlElem<0xc8>>* pThis, Unk_StlElem<0xc8>* pVal)
{
    FUN_1415e3560(pThis->m_pAl, FUN_1415dd8f0(pThis->m_pLast), FUN_1415e5070(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5830
void FUN_1415d5830(Unk_StlBackout<Unk_StlElem<0xf8>>* pThis, Unk_StlElem<0xf8>* pVal)
{
    FUN_1415e3650(pThis->m_pAl, FUN_1415dd900(pThis->m_pLast), FUN_1415e5080(pVal));
    ++pThis->m_pLast;
}

// @0x1415d58a0
void FUN_1415d58a0(Unk_StlBackout<Unk_StlElem<0x490>>* pThis, Unk_StlElem<0x490>* pVal)
{
    FUN_1415e3740(pThis->m_pAl, FUN_1415dd910(pThis->m_pLast), FUN_1415e5090(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5910
void FUN_1415d5910(Unk_StlBackout<Unk_StlElem<0x20>>* pThis, Unk_StlElem<0x20>* pVal)
{
    FUN_1415e3830(pThis->m_pAl, FUN_1415dd920(pThis->m_pLast), FUN_1415e50a0(pVal));
    ++pThis->m_pLast;
}

// @0x1415d5970
void FUN_1415d5970(void* pThis, Unk_StlElem<0x10>* pVal)
{
    FUN_1415e2430(FUN_141601ad0(pThis), FUN_1415dd7c0(FUN_141603980(pThis)), FUN_1415e4d20(pVal));
    FUN_141604220(pThis, FUN_141603980(pThis), FUN_141603980(pThis));
    Unk_StlElem<0x10>& result = *FUN_141603980(pThis);
    (void)result;
    ++FUN_141603980(pThis);
}

// @0x1415d5a30
void FUN_1415d5a30(void* pThis, Unk_StlElem<0x18>* pVal)
{
    FUN_1415e2480(FUN_141601b10(pThis), FUN_1415dd7d0(FUN_1416039c0(pThis)), FUN_1415e4d30(pVal));
    FUN_141604230(pThis, FUN_1416039c0(pThis), FUN_1416039c0(pThis));
    Unk_StlElem<0x18>& result = *FUN_1416039c0(pThis);
    (void)result;
    ++FUN_1416039c0(pThis);
}

// @0x1415d5af0
void FUN_1415d5af0(void* pThis, Unk_StlElem<0x20>* pVal)
{
    FUN_1415e24d0(FUN_14029bab0(pThis), FUN_140296020(FUN_14029c010(pThis)), FUN_1403a4b80(pVal));
    FUN_14029c080(pThis, FUN_14029c010(pThis), FUN_14029c010(pThis));
    Unk_StlElem<0x20>& result = *FUN_14029c010(pThis);
    (void)result;
    ++FUN_14029c010(pThis);
}

// @0x1415d5bb0
void FUN_1415d5bb0(void* pThis, Unk_StlElem<0x58>* pVal)
{
    FUN_1415e2570(FUN_141601b50(pThis), FUN_1415dd7e0(FUN_141603a00(pThis)), FUN_1415e4d40(pVal));
    FUN_141604240(pThis, FUN_141603a00(pThis), FUN_141603a00(pThis));
    Unk_StlElem<0x58>& result = *FUN_141603a00(pThis);
    (void)result;
    ++FUN_141603a00(pThis);
}

// @0x1415d5c70
void FUN_1415d5c70(void* pThis, Unk_StlElem<0x30>* pVal)
{
    FUN_1415e2660(FUN_141601b90(pThis), FUN_1415dd7f0(FUN_141603a40(pThis)), static_cast<Unk_StlElem<0x30>*>(FUN_1415e4d50(pVal)));
    FUN_141604250(pThis, FUN_141603a40(pThis), FUN_141603a40(pThis));
    Unk_StlElem<0x30>& result = *FUN_141603a40(pThis);
    (void)result;
    ++FUN_141603a40(pThis);
}

// @0x1415d5d30
void FUN_1415d5d30(void* pThis, Unk_StlElem<0x98>* pVal)
{
    FUN_1415e2750(FUN_141601bd0(pThis), FUN_1415dd800(FUN_141603a80(pThis)), FUN_1415e4d60(pVal));
    FUN_141604260(pThis, FUN_141603a80(pThis), FUN_141603a80(pThis));
    Unk_StlElem<0x98>& result = *FUN_141603a80(pThis);
    (void)result;
    ++FUN_141603a80(pThis);
}

// @0x1415d5df0
void FUN_1415d5df0(void* pThis, Unk_StlElem<0x220>* pVal)
{
    FUN_1415e2840(FUN_141601c10(pThis), FUN_1415dd810(FUN_141603ac0(pThis)), FUN_1415e4d70(pVal));
    FUN_141604270(pThis, FUN_141603ac0(pThis), FUN_141603ac0(pThis));
    Unk_StlElem<0x220>& result = *FUN_141603ac0(pThis);
    (void)result;
    ++FUN_141603ac0(pThis);
}

// @0x1415d5eb0
void FUN_1415d5eb0(void* pThis, Unk_StlElem<0x128>* pVal)
{
    FUN_1415e2930(FUN_141601c50(pThis), FUN_1415dd820(FUN_141603b00(pThis)), FUN_1415e4d80(pVal));
    FUN_141604280(pThis, FUN_141603b00(pThis), FUN_141603b00(pThis));
    Unk_StlElem<0x128>& result = *FUN_141603b00(pThis);
    (void)result;
    ++FUN_141603b00(pThis);
}

// @0x1415d5f70
void FUN_1415d5f70(void* pThis, Unk_StlElem<0x118>* pVal)
{
    FUN_1415e2a20(FUN_141601c90(pThis), FUN_1415dd830(FUN_141603b40(pThis)), FUN_1415e4d90(pVal));
    FUN_141604290(pThis, FUN_141603b40(pThis), FUN_141603b40(pThis));
    Unk_StlElem<0x118>& result = *FUN_141603b40(pThis);
    (void)result;
    ++FUN_141603b40(pThis);
}

// @0x1415d6030
void FUN_1415d6030(void* pThis, Unk_StlElem<0xe0>* pVal)
{
    FUN_1415e2ac0(FUN_141601cd0(pThis), FUN_1415dd840(FUN_141603b80(pThis)), FUN_1415e4da0(pVal));
    FUN_1416042a0(pThis, FUN_141603b80(pThis), FUN_141603b80(pThis));
    Unk_StlElem<0xe0>& result = *FUN_141603b80(pThis);
    (void)result;
    ++FUN_141603b80(pThis);
}

// @0x1415d60f0
void FUN_1415d60f0(void* pThis, Unk_StlElem<0x580>* pVal)
{
    FUN_1415e2bb0(FUN_141601d10(pThis), FUN_1415dd850(FUN_141603bc0(pThis)), FUN_1415e4db0(pVal));
    FUN_1416042b0(pThis, FUN_141603bc0(pThis), FUN_141603bc0(pThis));
    Unk_StlElem<0x580>& result = *FUN_141603bc0(pThis);
    (void)result;
    ++FUN_141603bc0(pThis);
}

// @0x1415d61b0
void FUN_1415d61b0(void* pThis, Unk_StlElem<0x18>* pVal)
{
    FUN_1415e2ca0(FUN_141601d50(pThis), FUN_1415dd860(FUN_141603c00(pThis)), FUN_1415e4dc0(pVal));
    FUN_1416042c0(pThis, FUN_141603c00(pThis), FUN_141603c00(pThis));
    Unk_StlElem<0x18>& result = *FUN_141603c00(pThis);
    (void)result;
    ++FUN_141603c00(pThis);
}

// @0x1415d6270
void FUN_1415d6270(void* pThis, Unk_StlElem<0x14a8>* pVal)
{
    FUN_1415e2d90(FUN_141601d90(pThis), FUN_1415dd870(FUN_141603c40(pThis)), FUN_1415e4dd0(pVal));
    FUN_1416042d0(pThis, FUN_141603c40(pThis), FUN_141603c40(pThis));
    Unk_StlElem<0x14a8>& result = *FUN_141603c40(pThis);
    (void)result;
    ++FUN_141603c40(pThis);
}

// @0x1415d6330
void FUN_1415d6330(void* pThis, Unk_StlElem<0x18>* pVal)
{
    FUN_1415e2e80(FUN_141601dd0(pThis), FUN_1415dd880(FUN_141603c80(pThis)), FUN_1415e4de0(pVal));
    FUN_1416042e0(pThis, FUN_141603c80(pThis), FUN_141603c80(pThis));
    Unk_StlElem<0x18>& result = *FUN_141603c80(pThis);
    (void)result;
    ++FUN_141603c80(pThis);
}

// @0x1415d63f0
void FUN_1415d63f0(void* pThis, Unk_StlElem<0x190>* pVal)
{
    FUN_1415e2f70(FUN_141601e10(pThis), FUN_1415dd890(FUN_141603cc0(pThis)), FUN_1415e4df0(pVal));
    FUN_1416042f0(pThis, FUN_141603cc0(pThis), FUN_141603cc0(pThis));
    Unk_StlElem<0x190>& result = *FUN_141603cc0(pThis);
    (void)result;
    ++FUN_141603cc0(pThis);
}

// @0x1415d64b0
void FUN_1415d64b0(void* pThis, Unk_StlElem<0xb8>* pVal)
{
    FUN_1415e3060(FUN_141601e50(pThis), FUN_1415dd8a0(FUN_141603d00(pThis)), FUN_1415e4e00(pVal));
    FUN_141604300(pThis, FUN_141603d00(pThis), FUN_141603d00(pThis));
    Unk_StlElem<0xb8>& result = *FUN_141603d00(pThis);
    (void)result;
    ++FUN_141603d00(pThis);
}

// @0x1415d6570
void FUN_1415d6570(void* pThis, Unk_StlElem<0x58>* pVal)
{
    FUN_1415e31a0(FUN_141601e90(pThis), FUN_1415dd8b0(FUN_141603d40(pThis)), FUN_1415e4e10(pVal));
    FUN_141604310(pThis, FUN_141603d40(pThis), FUN_141603d40(pThis));
    Unk_StlElem<0x58>& result = *FUN_141603d40(pThis);
    (void)result;
    ++FUN_141603d40(pThis);
}

// @0x1415d6630
void FUN_1415d6630(void* pThis, Unk_StlElem<0x68>* pVal)
{
    FUN_1415e3240(FUN_141601ed0(pThis), FUN_1415dd8c0(FUN_141603d80(pThis)), FUN_1415e4e20(pVal));
    FUN_141604320(pThis, FUN_141603d80(pThis), FUN_141603d80(pThis));
    Unk_StlElem<0x68>& result = *FUN_141603d80(pThis);
    (void)result;
    ++FUN_141603d80(pThis);
}

// @0x1415d66f0
void FUN_1415d66f0(void* pThis, Unk_StlElem<0xae8>* pVal)
{
    FUN_1415e3330(FUN_141601f10(pThis), FUN_1415dd8d0(FUN_141603dc0(pThis)), FUN_1415e4e30(pVal));
    FUN_141604330(pThis, FUN_141603dc0(pThis), FUN_141603dc0(pThis));
    Unk_StlElem<0xae8>& result = *FUN_141603dc0(pThis);
    (void)result;
    ++FUN_141603dc0(pThis);
}

// @0x1415d67b0
void FUN_1415d67b0(void* pThis, Unk_StlElem<0xec8>* pVal)
{
    FUN_1415e3420(FUN_141601f50(pThis), FUN_1415dd8e0(FUN_141603e00(pThis)), FUN_1415e4e40(pVal));
    FUN_141604340(pThis, FUN_141603e00(pThis), FUN_141603e00(pThis));
    Unk_StlElem<0xec8>& result = *FUN_141603e00(pThis);
    (void)result;
    ++FUN_141603e00(pThis);
}

// @0x1415d6870
void FUN_1415d6870(void* pThis, Unk_StlElem<0xc8>* pVal)
{
    FUN_1415e3510(FUN_141601f90(pThis), FUN_1415dd8f0(FUN_141603e40(pThis)), FUN_1415e4e50(pVal));
    FUN_141604350(pThis, FUN_141603e40(pThis), FUN_141603e40(pThis));
    Unk_StlElem<0xc8>& result = *FUN_141603e40(pThis);
    (void)result;
    ++FUN_141603e40(pThis);
}

// @0x1415d6930
void FUN_1415d6930(void* pThis, Unk_StlElem<0xf8>* pVal)
{
    FUN_1415e3600(FUN_141601fd0(pThis), FUN_1415dd900(FUN_141603e80(pThis)), FUN_1415e4e60(pVal));
    FUN_141604360(pThis, FUN_141603e80(pThis), FUN_141603e80(pThis));
    Unk_StlElem<0xf8>& result = *FUN_141603e80(pThis);
    (void)result;
    ++FUN_141603e80(pThis);
}

// @0x1415d69f0
void FUN_1415d69f0(void* pThis, Unk_StlElem<0x490>* pVal)
{
    FUN_1415e36f0(FUN_141602010(pThis), FUN_1415dd910(FUN_141603ec0(pThis)), FUN_1415e4e70(pVal));
    FUN_141604370(pThis, FUN_141603ec0(pThis), FUN_141603ec0(pThis));
    Unk_StlElem<0x490>& result = *FUN_141603ec0(pThis);
    (void)result;
    ++FUN_141603ec0(pThis);
}

// @0x1415d6ab0
void FUN_1415d6ab0(void* pThis, Unk_StlElem<0x20>* pVal)
{
    FUN_1415e37e0(FUN_141602050(pThis), FUN_1415dd920(FUN_141603f00(pThis)), FUN_1415e4e80(pVal));
    FUN_141604380(pThis, FUN_141603f00(pThis), FUN_141603f00(pThis));
    Unk_StlElem<0x20>& result = *FUN_141603f00(pThis);
    (void)result;
    ++FUN_141603f00(pThis);
}

// @0x1415d6b70
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x10>* FUN_1415d6b70(void* pThis, Unk_StlElem<0x10>* pWhere, Unk_StlElem<0x10>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_1416033c0(pThis));
    void* pAl = FUN_141601ad0(pThis);
    const size_t nOldSize = FUN_14160b620(pThis);
    if (nOldSize == FUN_14160a990(pThis))
        FUN_141607020();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fd6d0(pThis, nNewSize);
    Unk_StlElem<0x10>* const pNewVec = FUN_141607330(pAl, nNewCapacity);
    Unk_StlElem<0x10>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x10>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2430(pAl, FUN_1415dd7c0(pNewVec + nWhereOff), FUN_1415e4d20(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603980(pThis))
        {
            FUN_141606750(pThis, FUN_1416033c0(pThis), FUN_141603980(pThis), pNewVec);
        }
        else
        {
            FUN_141605bd0(pThis, FUN_1416033c0(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605bd0(pThis, pWhere, FUN_141603980(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600150(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416094c0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fe3c0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_1416033c0(pThis) + nWhereOff;
}

// @0x1415d6dc0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x18>* FUN_1415d6dc0(void* pThis, Unk_StlElem<0x18>* pWhere, Unk_StlElem<0x18>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603400(pThis));
    void* pAl = FUN_141601b10(pThis);
    const size_t nOldSize = FUN_14160b660(pThis);
    if (nOldSize == FUN_14160a9e0(pThis))
        FUN_141607040();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fd760(pThis, nNewSize);
    Unk_StlElem<0x18>* const pNewVec = FUN_141607360(pAl, nNewCapacity);
    Unk_StlElem<0x18>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x18>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2480(pAl, FUN_1415dd7d0(pNewVec + nWhereOff), FUN_1415e4d30(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_1416039c0(pThis))
        {
            FUN_1416067b0(pThis, FUN_141603400(pThis), FUN_1416039c0(pThis), pNewVec);
        }
        else
        {
            FUN_141605c10(pThis, FUN_141603400(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605c10(pThis, pWhere, FUN_1416039c0(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600190(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416094f0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fe4d0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603400(pThis) + nWhereOff;
}

// @0x1415d7010
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x20>* FUN_1415d7010(void* pThis, Unk_StlElem<0x20>* pWhere, Unk_StlElem<0x20>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_14029bfd0(pThis));
    void* pAl = FUN_14029bab0(pThis);
    const size_t nOldSize = FUN_14029dc20(pThis);
    if (nOldSize == FUN_14029d620(pThis))
        FUN_14029c6f0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_14029a300(pThis, nNewSize);
    Unk_StlElem<0x20>* const pNewVec = FUN_14029c7c0(pAl, nNewCapacity);
    Unk_StlElem<0x20>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x20>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e24d0(pAl, FUN_140296020(pNewVec + nWhereOff), FUN_1403a4b80(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_14029c010(pThis))
        {
            FUN_14029c670(pThis, FUN_14029bfd0(pThis), FUN_14029c010(pThis), pNewVec);
        }
        else
        {
            FUN_14029c550(pThis, FUN_14029bfd0(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_14029c550(pThis, pWhere, FUN_14029c010(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_14029a860(pThis, pConstructedFirst, pConstructedLast);
        FUN_14029cd50(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_14029a4a0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_14029bfd0(pThis) + nWhereOff;
}

// @0x1415d7260
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x58>* FUN_1415d7260(void* pThis, Unk_StlElem<0x58>* pWhere, Unk_StlElem<0x58>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603440(pThis));
    void* pAl = FUN_141601b50(pThis);
    const size_t nOldSize = FUN_14160b6b0(pThis);
    if (nOldSize == FUN_14160aa30(pThis))
        FUN_141607060();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fd7f0(pThis, nNewSize);
    Unk_StlElem<0x58>* const pNewVec = FUN_141607390(pAl, nNewCapacity);
    Unk_StlElem<0x58>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x58>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2570(pAl, FUN_1415dd7e0(pNewVec + nWhereOff), FUN_1415e4d40(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603a00(pThis))
        {
            FUN_141606810(pThis, FUN_141603440(pThis), FUN_141603a00(pThis), pNewVec);
        }
        else
        {
            FUN_141605c50(pThis, FUN_141603440(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605c50(pThis, pWhere, FUN_141603a00(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_1416001d0(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609520(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fe5e0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603440(pThis) + nWhereOff;
}

// @0x1415d74b0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x30>* FUN_1415d74b0(void* pThis, Unk_StlElem<0x30>* pWhere, Unk_StlElem<0x30>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603480(pThis));
    void* pAl = FUN_141601b90(pThis);
    const size_t nOldSize = FUN_14160b700(pThis);
    if (nOldSize == FUN_14160aa80(pThis))
        FUN_141607080();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fd880(pThis, nNewSize);
    Unk_StlElem<0x30>* const pNewVec = FUN_1416073c0(pAl, nNewCapacity);
    Unk_StlElem<0x30>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x30>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2660(pAl, FUN_1415dd7f0(pNewVec + nWhereOff), static_cast<Unk_StlElem<0x30>*>(FUN_1415e4d50(pVal)));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603a40(pThis))
        {
            FUN_141606870(pThis, FUN_141603480(pThis), FUN_141603a40(pThis), pNewVec);
        }
        else
        {
            FUN_141605c90(pThis, FUN_141603480(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605c90(pThis, pWhere, FUN_141603a40(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600210(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609550(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fe6f0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603480(pThis) + nWhereOff;
}

// @0x1415d7700
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x98>* FUN_1415d7700(void* pThis, Unk_StlElem<0x98>* pWhere, Unk_StlElem<0x98>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_1416034c0(pThis));
    void* pAl = FUN_141601bd0(pThis);
    const size_t nOldSize = FUN_14160b750(pThis);
    if (nOldSize == FUN_14160aad0(pThis))
        FUN_1416070a0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fd910(pThis, nNewSize);
    Unk_StlElem<0x98>* const pNewVec = FUN_1416073f0(pAl, nNewCapacity);
    Unk_StlElem<0x98>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x98>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2750(pAl, FUN_1415dd800(pNewVec + nWhereOff), FUN_1415e4d60(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603a80(pThis))
        {
            FUN_1416068d0(pThis, FUN_1416034c0(pThis), FUN_141603a80(pThis), pNewVec);
        }
        else
        {
            FUN_141605cd0(pThis, FUN_1416034c0(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605cd0(pThis, pWhere, FUN_141603a80(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600250(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609580(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fe800(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_1416034c0(pThis) + nWhereOff;
}

// @0x1415d7970
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x220>* FUN_1415d7970(void* pThis, Unk_StlElem<0x220>* pWhere, Unk_StlElem<0x220>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603500(pThis));
    void* pAl = FUN_141601c10(pThis);
    const size_t nOldSize = FUN_14160b7a0(pThis);
    if (nOldSize == FUN_14160ab20(pThis))
        FUN_1416070c0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fd9a0(pThis, nNewSize);
    Unk_StlElem<0x220>* const pNewVec = FUN_141607420(pAl, nNewCapacity);
    Unk_StlElem<0x220>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x220>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2840(pAl, FUN_1415dd810(pNewVec + nWhereOff), FUN_1415e4d70(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603ac0(pThis))
        {
            FUN_141606930(pThis, FUN_141603500(pThis), FUN_141603ac0(pThis), pNewVec);
        }
        else
        {
            FUN_141605d10(pThis, FUN_141603500(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605d10(pThis, pWhere, FUN_141603ac0(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600290(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416095b0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fe910(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603500(pThis) + nWhereOff;
}

// @0x1415d7be0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x128>* FUN_1415d7be0(void* pThis, Unk_StlElem<0x128>* pWhere, Unk_StlElem<0x128>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603540(pThis));
    void* pAl = FUN_141601c50(pThis);
    const size_t nOldSize = FUN_14160b7f0(pThis);
    if (nOldSize == FUN_14160ab70(pThis))
        FUN_1416070e0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fda30(pThis, nNewSize);
    Unk_StlElem<0x128>* const pNewVec = FUN_141607450(pAl, nNewCapacity);
    Unk_StlElem<0x128>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x128>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2930(pAl, FUN_1415dd820(pNewVec + nWhereOff), FUN_1415e4d80(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603b00(pThis))
        {
            FUN_141606990(pThis, FUN_141603540(pThis), FUN_141603b00(pThis), pNewVec);
        }
        else
        {
            FUN_141605d50(pThis, FUN_141603540(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605d50(pThis, pWhere, FUN_141603b00(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_1416002d0(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416095e0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fea20(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603540(pThis) + nWhereOff;
}

// @0x1415d7e50
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x118>* FUN_1415d7e50(void* pThis, Unk_StlElem<0x118>* pWhere, Unk_StlElem<0x118>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603580(pThis));
    void* pAl = FUN_141601c90(pThis);
    const size_t nOldSize = FUN_14160b840(pThis);
    if (nOldSize == FUN_14160abc0(pThis))
        FUN_141607100();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdac0(pThis, nNewSize);
    Unk_StlElem<0x118>* const pNewVec = FUN_141607480(pAl, nNewCapacity);
    Unk_StlElem<0x118>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x118>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2a20(pAl, FUN_1415dd830(pNewVec + nWhereOff), FUN_1415e4d90(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603b40(pThis))
        {
            FUN_1416069f0(pThis, FUN_141603580(pThis), FUN_141603b40(pThis), pNewVec);
        }
        else
        {
            FUN_141605d90(pThis, FUN_141603580(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605d90(pThis, pWhere, FUN_141603b40(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600310(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609610(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415feb30(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603580(pThis) + nWhereOff;
}

// @0x1415d80c0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0xe0>* FUN_1415d80c0(void* pThis, Unk_StlElem<0xe0>* pWhere, Unk_StlElem<0xe0>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_1416035c0(pThis));
    void* pAl = FUN_141601cd0(pThis);
    const size_t nOldSize = FUN_14160b890(pThis);
    if (nOldSize == FUN_14160ac10(pThis))
        FUN_141607120();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdb50(pThis, nNewSize);
    Unk_StlElem<0xe0>* const pNewVec = FUN_1416074b0(pAl, nNewCapacity);
    Unk_StlElem<0xe0>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0xe0>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2ac0(pAl, FUN_1415dd840(pNewVec + nWhereOff), FUN_1415e4da0(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603b80(pThis))
        {
            FUN_141606a50(pThis, FUN_1416035c0(pThis), FUN_141603b80(pThis), pNewVec);
        }
        else
        {
            FUN_141605dd0(pThis, FUN_1416035c0(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605dd0(pThis, pWhere, FUN_141603b80(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600350(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609640(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fec40(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_1416035c0(pThis) + nWhereOff;
}

// @0x1415d8330
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x580>* FUN_1415d8330(void* pThis, Unk_StlElem<0x580>* pWhere, Unk_StlElem<0x580>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603600(pThis));
    void* pAl = FUN_141601d10(pThis);
    const size_t nOldSize = FUN_14160b8e0(pThis);
    if (nOldSize == FUN_14160ac60(pThis))
        FUN_141607140();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdbe0(pThis, nNewSize);
    Unk_StlElem<0x580>* const pNewVec = FUN_1416074e0(pAl, nNewCapacity);
    Unk_StlElem<0x580>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x580>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2bb0(pAl, FUN_1415dd850(pNewVec + nWhereOff), FUN_1415e4db0(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603bc0(pThis))
        {
            FUN_141606ab0(pThis, FUN_141603600(pThis), FUN_141603bc0(pThis), pNewVec);
        }
        else
        {
            FUN_141605e10(pThis, FUN_141603600(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605e10(pThis, pWhere, FUN_141603bc0(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600390(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609670(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fed50(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603600(pThis) + nWhereOff;
}

// @0x1415d85a0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x18>* FUN_1415d85a0(void* pThis, Unk_StlElem<0x18>* pWhere, Unk_StlElem<0x18>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603640(pThis));
    void* pAl = FUN_141601d50(pThis);
    const size_t nOldSize = FUN_14160b930(pThis);
    if (nOldSize == FUN_14160acb0(pThis))
        FUN_141607160();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdc70(pThis, nNewSize);
    Unk_StlElem<0x18>* const pNewVec = FUN_141607510(pAl, nNewCapacity);
    Unk_StlElem<0x18>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x18>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2ca0(pAl, FUN_1415dd860(pNewVec + nWhereOff), FUN_1415e4dc0(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603c00(pThis))
        {
            FUN_141606b10(pThis, FUN_141603640(pThis), FUN_141603c00(pThis), pNewVec);
        }
        else
        {
            FUN_141605e50(pThis, FUN_141603640(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605e50(pThis, pWhere, FUN_141603c00(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_1416003d0(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416096a0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fee60(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603640(pThis) + nWhereOff;
}

// @0x1415d87f0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x14a8>* FUN_1415d87f0(void* pThis, Unk_StlElem<0x14a8>* pWhere, Unk_StlElem<0x14a8>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603680(pThis));
    void* pAl = FUN_141601d90(pThis);
    const size_t nOldSize = FUN_14160b980(pThis);
    if (nOldSize == FUN_14160ad00(pThis))
        FUN_141607180();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdd00(pThis, nNewSize);
    Unk_StlElem<0x14a8>* const pNewVec = FUN_141607540(pAl, nNewCapacity);
    Unk_StlElem<0x14a8>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x14a8>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2d90(pAl, FUN_1415dd870(pNewVec + nWhereOff), FUN_1415e4dd0(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603c40(pThis))
        {
            FUN_141606b70(pThis, FUN_141603680(pThis), FUN_141603c40(pThis), pNewVec);
        }
        else
        {
            FUN_141605e90(pThis, FUN_141603680(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605e90(pThis, pWhere, FUN_141603c40(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600410(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416096d0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415fef70(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603680(pThis) + nWhereOff;
}

// @0x1415d8a60
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x18>* FUN_1415d8a60(void* pThis, Unk_StlElem<0x18>* pWhere, Unk_StlElem<0x18>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_1416036c0(pThis));
    void* pAl = FUN_141601dd0(pThis);
    const size_t nOldSize = FUN_14160b9d0(pThis);
    if (nOldSize == FUN_14160ad50(pThis))
        FUN_1416071a0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdd90(pThis, nNewSize);
    Unk_StlElem<0x18>* const pNewVec = FUN_141607570(pAl, nNewCapacity);
    Unk_StlElem<0x18>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x18>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2e80(pAl, FUN_1415dd880(pNewVec + nWhereOff), FUN_1415e4de0(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603c80(pThis))
        {
            FUN_141606bd0(pThis, FUN_1416036c0(pThis), FUN_141603c80(pThis), pNewVec);
        }
        else
        {
            FUN_141605ed0(pThis, FUN_1416036c0(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605ed0(pThis, pWhere, FUN_141603c80(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600450(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609700(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff080(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_1416036c0(pThis) + nWhereOff;
}

// @0x1415d8cb0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x190>* FUN_1415d8cb0(void* pThis, Unk_StlElem<0x190>* pWhere, Unk_StlElem<0x190>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603700(pThis));
    void* pAl = FUN_141601e10(pThis);
    const size_t nOldSize = FUN_14160ba20(pThis);
    if (nOldSize == FUN_14160ada0(pThis))
        FUN_1416071c0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fde20(pThis, nNewSize);
    Unk_StlElem<0x190>* const pNewVec = FUN_1416075a0(pAl, nNewCapacity);
    Unk_StlElem<0x190>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x190>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e2f70(pAl, FUN_1415dd890(pNewVec + nWhereOff), FUN_1415e4df0(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603cc0(pThis))
        {
            FUN_141606c30(pThis, FUN_141603700(pThis), FUN_141603cc0(pThis), pNewVec);
        }
        else
        {
            FUN_141605f10(pThis, FUN_141603700(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605f10(pThis, pWhere, FUN_141603cc0(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600490(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609730(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff190(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603700(pThis) + nWhereOff;
}

// @0x1415d8f20
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0xb8>* FUN_1415d8f20(void* pThis, Unk_StlElem<0xb8>* pWhere, Unk_StlElem<0xb8>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603740(pThis));
    void* pAl = FUN_141601e50(pThis);
    const size_t nOldSize = FUN_14160ba70(pThis);
    if (nOldSize == FUN_14160adf0(pThis))
        FUN_1416071e0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdeb0(pThis, nNewSize);
    Unk_StlElem<0xb8>* const pNewVec = FUN_1416075d0(pAl, nNewCapacity);
    Unk_StlElem<0xb8>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0xb8>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e3060(pAl, FUN_1415dd8a0(pNewVec + nWhereOff), FUN_1415e4e00(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603d00(pThis))
        {
            FUN_141606c90(pThis, FUN_141603740(pThis), FUN_141603d00(pThis), pNewVec);
        }
        else
        {
            FUN_141605f50(pThis, FUN_141603740(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605f50(pThis, pWhere, FUN_141603d00(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_1416004d0(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609760(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff2a0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603740(pThis) + nWhereOff;
}

// @0x1415d9190
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x58>* FUN_1415d9190(void* pThis, Unk_StlElem<0x58>* pWhere, Unk_StlElem<0x58>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603780(pThis));
    void* pAl = FUN_141601e90(pThis);
    const size_t nOldSize = FUN_14160bac0(pThis);
    if (nOldSize == FUN_14160ae40(pThis))
        FUN_141607200();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdf40(pThis, nNewSize);
    Unk_StlElem<0x58>* const pNewVec = FUN_141607600(pAl, nNewCapacity);
    Unk_StlElem<0x58>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x58>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e31a0(pAl, FUN_1415dd8b0(pNewVec + nWhereOff), FUN_1415e4e10(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603d40(pThis))
        {
            FUN_141606cf0(pThis, FUN_141603780(pThis), FUN_141603d40(pThis), pNewVec);
        }
        else
        {
            FUN_141605f90(pThis, FUN_141603780(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605f90(pThis, pWhere, FUN_141603d40(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600510(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609790(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff3b0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603780(pThis) + nWhereOff;
}

// @0x1415d93e0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x68>* FUN_1415d93e0(void* pThis, Unk_StlElem<0x68>* pWhere, Unk_StlElem<0x68>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_1416037c0(pThis));
    void* pAl = FUN_141601ed0(pThis);
    const size_t nOldSize = FUN_14160bb10(pThis);
    if (nOldSize == FUN_14160ae90(pThis))
        FUN_141607220();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fdfd0(pThis, nNewSize);
    Unk_StlElem<0x68>* const pNewVec = FUN_141607630(pAl, nNewCapacity);
    Unk_StlElem<0x68>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x68>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e3240(pAl, FUN_1415dd8c0(pNewVec + nWhereOff), FUN_1415e4e20(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603d80(pThis))
        {
            FUN_141606d50(pThis, FUN_1416037c0(pThis), FUN_141603d80(pThis), pNewVec);
        }
        else
        {
            FUN_141605fd0(pThis, FUN_1416037c0(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141605fd0(pThis, pWhere, FUN_141603d80(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600550(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416097c0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff4c0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_1416037c0(pThis) + nWhereOff;
}

// @0x1415d9630
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0xae8>* FUN_1415d9630(void* pThis, Unk_StlElem<0xae8>* pWhere, Unk_StlElem<0xae8>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603800(pThis));
    void* pAl = FUN_141601f10(pThis);
    const size_t nOldSize = FUN_14160bb60(pThis);
    if (nOldSize == FUN_14160aee0(pThis))
        FUN_141607240();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fe060(pThis, nNewSize);
    Unk_StlElem<0xae8>* const pNewVec = FUN_141607660(pAl, nNewCapacity);
    Unk_StlElem<0xae8>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0xae8>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e3330(pAl, FUN_1415dd8d0(pNewVec + nWhereOff), FUN_1415e4e30(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603dc0(pThis))
        {
            FUN_141606db0(pThis, FUN_141603800(pThis), FUN_141603dc0(pThis), pNewVec);
        }
        else
        {
            FUN_141606010(pThis, FUN_141603800(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141606010(pThis, pWhere, FUN_141603dc0(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600590(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416097f0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff5d0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603800(pThis) + nWhereOff;
}

// @0x1415d98a0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0xec8>* FUN_1415d98a0(void* pThis, Unk_StlElem<0xec8>* pWhere, Unk_StlElem<0xec8>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603840(pThis));
    void* pAl = FUN_141601f50(pThis);
    const size_t nOldSize = FUN_14160bbb0(pThis);
    if (nOldSize == FUN_14160af30(pThis))
        FUN_141607260();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fe0f0(pThis, nNewSize);
    Unk_StlElem<0xec8>* const pNewVec = FUN_141607690(pAl, nNewCapacity);
    Unk_StlElem<0xec8>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0xec8>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e3420(pAl, FUN_1415dd8e0(pNewVec + nWhereOff), FUN_1415e4e40(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603e00(pThis))
        {
            FUN_141606e10(pThis, FUN_141603840(pThis), FUN_141603e00(pThis), pNewVec);
        }
        else
        {
            FUN_141606050(pThis, FUN_141603840(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141606050(pThis, pWhere, FUN_141603e00(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_1416005d0(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609820(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff6e0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603840(pThis) + nWhereOff;
}

// @0x1415d9b10
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0xc8>* FUN_1415d9b10(void* pThis, Unk_StlElem<0xc8>* pWhere, Unk_StlElem<0xc8>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603880(pThis));
    void* pAl = FUN_141601f90(pThis);
    const size_t nOldSize = FUN_14160bc00(pThis);
    if (nOldSize == FUN_14160af80(pThis))
        FUN_141607280();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fe180(pThis, nNewSize);
    Unk_StlElem<0xc8>* const pNewVec = FUN_1416076c0(pAl, nNewCapacity);
    Unk_StlElem<0xc8>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0xc8>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e3510(pAl, FUN_1415dd8f0(pNewVec + nWhereOff), FUN_1415e4e50(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603e40(pThis))
        {
            FUN_141606e70(pThis, FUN_141603880(pThis), FUN_141603e40(pThis), pNewVec);
        }
        else
        {
            FUN_141606090(pThis, FUN_141603880(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141606090(pThis, pWhere, FUN_141603e40(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600610(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609850(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff7f0(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603880(pThis) + nWhereOff;
}

// @0x1415d9d80
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0xf8>* FUN_1415d9d80(void* pThis, Unk_StlElem<0xf8>* pWhere, Unk_StlElem<0xf8>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_1416038c0(pThis));
    void* pAl = FUN_141601fd0(pThis);
    const size_t nOldSize = FUN_14160bc50(pThis);
    if (nOldSize == FUN_14160afd0(pThis))
        FUN_1416072a0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fe210(pThis, nNewSize);
    Unk_StlElem<0xf8>* const pNewVec = FUN_1416076f0(pAl, nNewCapacity);
    Unk_StlElem<0xf8>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0xf8>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e3600(pAl, FUN_1415dd900(pNewVec + nWhereOff), FUN_1415e4e60(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603e80(pThis))
        {
            FUN_141606ed0(pThis, FUN_1416038c0(pThis), FUN_141603e80(pThis), pNewVec);
        }
        else
        {
            FUN_1416060d0(pThis, FUN_1416038c0(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_1416060d0(pThis, pWhere, FUN_141603e80(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600650(pThis, pConstructedFirst, pConstructedLast);
        FUN_141609880(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ff900(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_1416038c0(pThis) + nWhereOff;
}

// @0x1415d9ff0
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x490>* FUN_1415d9ff0(void* pThis, Unk_StlElem<0x490>* pWhere, Unk_StlElem<0x490>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603900(pThis));
    void* pAl = FUN_141602010(pThis);
    const size_t nOldSize = FUN_14160bca0(pThis);
    if (nOldSize == FUN_14160b020(pThis))
        FUN_1416072c0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fe2a0(pThis, nNewSize);
    Unk_StlElem<0x490>* const pNewVec = FUN_141607720(pAl, nNewCapacity);
    Unk_StlElem<0x490>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x490>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e36f0(pAl, FUN_1415dd910(pNewVec + nWhereOff), FUN_1415e4e70(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603ec0(pThis))
        {
            FUN_141606f30(pThis, FUN_141603900(pThis), FUN_141603ec0(pThis), pNewVec);
        }
        else
        {
            FUN_141606110(pThis, FUN_141603900(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141606110(pThis, pWhere, FUN_141603ec0(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_141600690(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416098b0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ffa10(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603900(pThis) + nWhereOff;
}

// @0x1415da260
// MS2-FUNCTIONAL: same calls and EH (catch: destroy + deallocate + rethrow); the exe evaluates the construct arguments
// left to right and keeps fewer temporaries than this free-function form.
Unk_StlElem<0x20>* FUN_1415da260(void* pThis, Unk_StlElem<0x20>* pWhere, Unk_StlElem<0x20>* pVal)
{
    const size_t nWhereOff = static_cast<size_t>(pWhere - FUN_141603940(pThis));
    void* pAl = FUN_141602050(pThis);
    const size_t nOldSize = FUN_14160bcf0(pThis);
    if (nOldSize == FUN_14160b070(pThis))
        FUN_1416072e0();
    const size_t nNewSize = nOldSize + 1;
    const size_t nNewCapacity = FUN_1415fe330(pThis, nNewSize);
    Unk_StlElem<0x20>* const pNewVec = FUN_141607750(pAl, nNewCapacity);
    Unk_StlElem<0x20>* const pConstructedLast = pNewVec + nWhereOff + 1;
    Unk_StlElem<0x20>* pConstructedFirst = pConstructedLast;
    try
    {
        FUN_1415e37e0(pAl, FUN_1415dd920(pNewVec + nWhereOff), FUN_1415e4e80(pVal));
        pConstructedFirst = pNewVec + nWhereOff;
        if (pWhere == FUN_141603f00(pThis))
        {
            FUN_141606f90(pThis, FUN_141603940(pThis), FUN_141603f00(pThis), pNewVec);
        }
        else
        {
            FUN_141606150(pThis, FUN_141603940(pThis), pWhere, pNewVec);
            pConstructedFirst = pNewVec;
            FUN_141606150(pThis, pWhere, FUN_141603f00(pThis), pNewVec + nWhereOff + 1);
        }
    }
    catch (...)
    {
        FUN_1416006d0(pThis, pConstructedFirst, pConstructedLast);
        FUN_1416098e0(pAl, pNewVec, nNewCapacity);
        throw;
    }
    FUN_1415ffb20(pThis, pNewVec, nNewSize, nNewCapacity);
    return FUN_141603940(pThis) + nWhereOff;
}
