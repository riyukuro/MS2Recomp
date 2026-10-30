/* VC9 intrin.h stand-in (WDK 7.1 crt lacks it): the declarations our CRI units use; cl 15 treats them as intrinsics. */
#ifndef MS2_VC9_INTRIN_H
#define MS2_VC9_INTRIN_H
#include <emmintrin.h>
#ifdef __cplusplus
extern "C" {
#endif
unsigned __int64 __popcnt64(unsigned __int64);
unsigned int __popcnt(unsigned int);
unsigned char _BitScanForward(unsigned long *, unsigned long);
unsigned char _BitScanReverse(unsigned long *, unsigned long);
unsigned char _BitScanForward64(unsigned long *, unsigned __int64);
unsigned char _BitScanReverse64(unsigned long *, unsigned __int64);
unsigned int _rotl(unsigned int, int);
unsigned int _rotr(unsigned int, int);
unsigned __int64 _rotl64(unsigned __int64, int);
unsigned __int64 _rotr64(unsigned __int64, int);
__int64 _mul128(__int64, __int64, __int64 *);
unsigned __int64 _umul128(unsigned __int64, unsigned __int64, unsigned __int64 *);
__int64 __mulh(__int64, __int64);
unsigned __int64 __umulh(unsigned __int64, unsigned __int64);
long _InterlockedIncrement(long volatile *);
long _InterlockedDecrement(long volatile *);
long _InterlockedExchange(long volatile *, long);
long _InterlockedCompareExchange(long volatile *, long, long);
long _InterlockedExchangeAdd(long volatile *, long);
void __cpuid(int[4], int);
unsigned __int64 __rdtsc(void);
void _ReadWriteBarrier(void);
/* x64-only SSE2 conversions: the VS2008 emmintrin.h has them, the WDK 7.1 copy (1999 Intel header) does not */
__m128i _mm_cvtsi64_si128(__int64);
__int64 _mm_cvtsi128_si64(__m128i);
__m128i _mm_cvtsi64x_si128(__int64);
__int64 _mm_cvtsi128_si64x(__m128i);
#pragma intrinsic(__popcnt64, __popcnt, _BitScanForward, _BitScanReverse, _BitScanForward64, _BitScanReverse64)
#pragma intrinsic(_rotl, _rotr, _rotl64, _rotr64, _mul128, _umul128, __mulh, __umulh, __cpuid, __rdtsc, _ReadWriteBarrier)
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement, _InterlockedExchange, _InterlockedCompareExchange, _InterlockedExchangeAdd)
#ifdef __cplusplus
}
#endif
#endif
