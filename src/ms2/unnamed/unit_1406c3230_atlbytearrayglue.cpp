// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Byte-vector glue over ATL::CAtlArray<char> /
// CAtlArray<char>: data-pointer helpers, the assign/serialize routines of the login blobs, and a hex dump.
// MS2-UNIT: unit_1406c3230
// MS2-RANGE: 0x1406c3230-0x1406c3700 .text$mn
// MS2-PIN: ?IsEmpty@?$CAtlArray@EV?$CElementTraits@E@ATL@@@ATL@@QEBA_NXZ 0x1406c3680
// MS2-PIN: ?IsEmpty@?$CAtlArray@DV?$CElementTraits@D@ATL@@@ATL@@QEBA_NXZ 0x1406c36c0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <intrin.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/serverpacketdef.h"

// 0x1406c35b0 / 0x1406c35f0 (operator[]) and 0x1406c3680 / 0x1406c36c0 (IsEmpty<unsigned char> / IsEmpty<char>) are the
// CAtlArray<char> template members instantiated below. The IsEmpty copies call GetCount, which the exe folded into 0x140204ee0.
// The exe's IsEmpty copies for these two arrays test GetCount() rather than m_nSize (the other CAtlArray copies read
// the member), so they are declared as explicit specializations here.
template <> inline bool ATL::CAtlArray<char>::IsEmpty() const throw() { return GetCount() == 0; }
template <> inline bool ATL::CAtlArray<unsigned char>::IsEmpty() const throw() { return GetCount() == 0; }

// @0x1406c3630
const unsigned char* FUN_1406c3630(const ATL::CAtlArray<char>& a)
{
    if (a.IsEmpty()) return 0;
    return (const unsigned char*)&a[0];
}

// @0x1406c3660
int FUN_1406c3660(const ATL::CAtlArray<char>& a) { return (int)a.GetCount(); }

// @0x1406c3230
char* GetData(ATL::CAtlArray<char>& a)
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
void SetData(ATL::CAtlArray<char>& a, const char* src, __int64 count)
{
    if (count == 0) return;
    if (a.GetCount() != (size_t)count) a.SetCount(count, -1);
    memcpy(&a[0], src, (size_t)count);
}

// @0x1406c3320
ATL::CAtlArray<char>& Assign(ATL::CAtlArray<char>& a, const ATL::CAtlArray<char>& b)
{
    if (FUN_1406c3660(b) != 0) SetData(a, (const char*)FUN_1406c3630(b), FUN_1406c3660(b));
    return a;
}

// @0x1406c3380
void FUN_1406c3380(ATL::CAtlArray<char>& a, COutputStream* out)
{
    int n = (int)a.GetCount();
    out->WriteInt32(n);
    if (n != 0) out->WriteBytes(GetData(a), n);
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
