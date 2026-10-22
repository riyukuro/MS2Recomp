// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Byte-vector glue over ATL::CAtlArray<char> /
// CAtlArray<char>: data-pointer helpers, the assign/serialize routines of the login blobs, and a hex dump.
// MS2-UNIT: unit_1406c3230
// MS2-RANGE: 0x1406c3230-0x1406c3700 .text$mn
// MS2-PIN: ?IsEmpty@?$CAtlArray@EV?$CElementTraits@E@ATL@@@ATL@@QEBA_NXZ 0x1406c3680
// MS2-PIN: ?IsEmpty@?$CAtlArray@DV?$CElementTraits@D@ATL@@@ATL@@QEBA_NXZ 0x1406c36c0
// MS2-FUNCTIONAL 0x1406c36c0: not ATL's inline IsEmpty (the 66 other CAtlArray::IsEmpty copies read m_nSize): the exe body is
// GetCount() == 0 (call 0x140204ee0), likely an unrecovered wrapper class's IsEmpty; bound to CAtlArray<char>::IsEmpty here
// MS2-FUNCTIONAL 0x1406c3680: the same GetCount() == 0 wrapper body for the unsigned char array
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <intrin.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/serverpacketdef.h"

// 0x1406c35b0 / 0x1406c35f0 (operator[]) and 0x1406c3680 / 0x1406c36c0 (IsEmpty<unsigned char> / IsEmpty<char>) are the
// CAtlArray<char> template members instantiated below. MS2-FUNCTIONAL: the IsEmpty copies call GetCount<char>, which the exe folded into 0x140204ee0.
// @0x1406c3630
const unsigned char* FUN_1406c3630(const ATL::CAtlArray<char>& a)
{
    if (a.IsEmpty()) return 0;
    return (const unsigned char*)&a[0];
}

// @0x1406c3660
int FUN_1406c3660(const ATL::CAtlArray<char>& a) { return (int)a.GetCount(); }

// @0x1406c3230
char* FUN_1406c3230(ATL::CAtlArray<char>& a)
{
    if (((const ATL::CAtlArray<unsigned char>&)a).IsEmpty()) return 0;
    return &a[0];
}

// @0x1406c3270
const char* FUN_1406c3270(const ATL::CAtlArray<char>& a)
{
    if (((const ATL::CAtlArray<unsigned char>&)a).IsEmpty()) return 0;
    return &a[0];
}

// @0x1406c32b0
void FUN_1406c32b0(ATL::CAtlArray<char>& a, const char* src, __int64 count)
{
    if (count == 0) return;
    if (a.GetCount() != (size_t)count) a.SetCount(count, -1);
    memcpy(&a[0], src, (size_t)count);
}

// @0x1406c3320
ATL::CAtlArray<char>& FUN_1406c3320(ATL::CAtlArray<char>& a, const ATL::CAtlArray<char>& b)
{
    if (FUN_1406c3660(b) != 0) FUN_1406c32b0(a, (const char*)FUN_1406c3630(b), FUN_1406c3660(b));
    return a;
}

// @0x1406c3380
void FUN_1406c3380(ATL::CAtlArray<char>& a, COutputStream* out)
{
    int n = (int)a.GetCount();
    out->WriteInt32(n);
    if (n != 0) out->WriteBytes(FUN_1406c3230(a), n);
}

// @0x1406c33f0
void FUN_1406c33f0(ATL::CAtlArray<char>& a, Unk_SPDReader* in)
{
    int n = in->ReadInt32();
    a.SetCount((unsigned)n, -1);
    if (n != 0) in->ReadBytes(&a[0], n);
}

// @0x1406c3480
void* FUN_1406c3480(void* p) { return p; }

// @0x1406c34a0
void FUN_1406c34a0(void*) {}

// @0x1406c34b0
// MS2-FUNCTIONAL: byte-patched to `mov eax,0; ret` in the exe (nexon_platform_compat.cpp)
int FUN_1406c34b0() { return 0; }

// @0x1406c34c0
int FUN_1406c34c0()
{
    if (FUN_1406c34b0() == 0) return 0;
    return 1;
}

// @0x1406c34f0
CStringA FUN_1406c34f0(const unsigned char* data, int count)
{
    CStringA s;
    s.Empty();
    if (data != 0) {
        for (int i = 0; i < count; ++i) s.AppendFormat("%02X ", data[i]);
    }
    return s;
}
