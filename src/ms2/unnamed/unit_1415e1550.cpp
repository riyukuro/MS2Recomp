// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template zone of the boxed-pointer TU, part 3:
// std::find<char> limit checks, 46 identity thunks (std::_Get_unwrapped for pointer iterators), 19 "ptr += n * sizeof(T)"
// forwarders and 19 range-checked (verify_range, unwrap, unwrap) forwarders into the per-element-type copy helpers of
// unit_1415cf3e0. Element types are not recoverable, so everything is void*.
// MS2-UNIT: unit_1415e1550
// MS2-RANGE: 0x1415e1550-0x1415e2390 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <algorithm>

extern void* FUN_1415da9f0(void* p);
extern void* FUN_1415daa00(void* p);
extern void* FUN_1415daa10(void* p);
extern void* FUN_1415daa50(void* p);
extern void* FUN_1415daa70(void* p);
extern void* FUN_1415daa80(void* p);
extern void* FUN_1415daa90(void* p);
extern void* FUN_1415daaa0(void* p);
extern void* FUN_1415daab0(void* p);
extern void* FUN_1415daac0(void* p);
extern void* FUN_1415daae0(void* p);
extern void* FUN_1415daaf0(void* p);
extern void* FUN_1415dab00(void* p);
extern void* FUN_1415dab10(void* p);
extern void* FUN_1415dab30(void* p);
extern void* FUN_1415dab40(void* p);
extern void* FUN_1415dab80(void* p);
extern void* FUN_1415dab90(void* p);
extern void* FUN_1415daba0(void* p);
extern void FUN_1415ceb50(void* first, void* last);
extern void FUN_1415ceb90(void* first, void* last);
extern void FUN_1415cebd0(void* first, void* last);
extern void FUN_1415cec10(void* first, void* last);
extern void FUN_1415cec50(void* first, void* last);
extern void FUN_1415cec90(void* first, void* last);
extern void FUN_1415cecd0(void* first, void* last);
extern void FUN_1415ced10(void* first, void* last);
extern void FUN_1415ced50(void* first, void* last);
extern void FUN_1415ced90(void* first, void* last);
extern void FUN_1415cedd0(void* first, void* last);
extern void FUN_1415cee10(void* first, void* last);
extern void FUN_1415cee50(void* first, void* last);
extern void FUN_1415cee90(void* first, void* last);
extern void FUN_1415ceed0(void* first, void* last);
extern void FUN_1415cef10(void* first, void* last);
extern void FUN_1415cef50(void* first, void* last);
extern void FUN_1415cef90(void* first, void* last);
extern void FUN_1415cf010(void* first, void* last);
extern void FUN_1415cf050(void* a, void* b, char tag);
extern void FUN_1415cf080(void* a, void* b, char tag);
extern void FUN_1415cf0b0(void* a, void* b, char tag);
extern void FUN_1415cf0e0(void* a, void* b, char tag);
extern void FUN_1415cf110(void* a, void* b, char tag);
extern void FUN_1415cf140(void* a, void* b, char tag);
extern void FUN_1415cf170(void* a, void* b, char tag);
extern void FUN_1415cf1a0(void* a, void* b, char tag);
extern void FUN_1415cf1d0(void* a, void* b, char tag);
extern void FUN_1415cf200(void* a, void* b, char tag);
extern void FUN_1415cf230(void* a, void* b, char tag);
extern void FUN_1415cf260(void* a, void* b, char tag);
extern void FUN_1415cf290(void* a, void* b, char tag);
extern void FUN_1415cf2c0(void* a, void* b, char tag);
extern void FUN_1415cf2f0(void* a, void* b, char tag);
extern void FUN_1415cf320(void* a, void* b, char tag);
extern void FUN_1415cf350(void* a, void* b, char tag);
extern void FUN_1415cf380(void* a, void* b, char tag);
extern void FUN_1415cf3b0(void* a, void* b, char tag);
extern void FUN_1415cf3e0(void* dest, void* first, void* last, char tag);
extern void FUN_1415cf680(void* dest, void* first, void* last, char tag);
extern void FUN_1415cf920(void* dest, void* first, void* last, char tag);
extern void FUN_1415cfbc0(void* dest, void* first, void* last, char tag);
extern void FUN_1415cfe60(void* dest, void* first, void* last, char tag);
extern void FUN_1415d0100(void* dest, void* first, void* last, char tag);
extern void FUN_1415d03a0(void* dest, void* first, void* last, char tag);
extern void FUN_1415d0640(void* dest, void* first, void* last, char tag);
extern void FUN_1415d08e0(void* dest, void* first, void* last, char tag);
extern void FUN_1415d0b80(void* dest, void* first, void* last, char tag);
extern void FUN_1415d0e20(void* dest, void* first, void* last, char tag);
extern void FUN_1415d10c0(void* dest, void* first, void* last, char tag);
extern void FUN_1415d1360(void* dest, void* first, void* last, char tag);
extern void FUN_1415d1600(void* dest, void* first, void* last, char tag);
extern void FUN_1415d18a0(void* dest, void* first, void* last, char tag);
extern void FUN_1415d1b40(void* dest, void* first, void* last, char tag);
extern void FUN_1415d1de0(void* dest, void* first, void* last, char tag);
extern void FUN_1415d2080(void* dest, void* first, void* last, char tag);
extern void FUN_1415d2320(void* dest, void* first, void* last, char tag);

// @0x1415e1550, 0x1415e15a0
template bool std::_Within_limits<char>(const char&, std::true_type, std::true_type, std::_Any_tag);
template bool std::_Within_limits<const char*, char>(const char*, const char&);

// @0x1415e1600
void* FUN_1415e1600(void* p)
{
    return p;
}

// @0x1415e1610
void* FUN_1415e1610(void* p)
{
    return p;
}

// @0x1415e1620
void* FUN_1415e1620(void* p)
{
    return p;
}

// @0x1415e1630
void* FUN_1415e1630(void* p)
{
    return p;
}

// @0x1415e1640
void* FUN_1415e1640(void* p)
{
    return p;
}

// @0x1415e1650
void* FUN_1415e1650(void* p)
{
    return p;
}

// @0x1415e1660
void* FUN_1415e1660(void* p)
{
    return p;
}

// @0x1415e1670
void* FUN_1415e1670(void* p)
{
    return p;
}

// @0x1415e1680
void* FUN_1415e1680(void* p)
{
    return p;
}

// @0x1415e1690
void* FUN_1415e1690(void* p)
{
    return p;
}

// @0x1415e16a0
void* FUN_1415e16a0(void* p)
{
    return p;
}

// @0x1415e16b0
void* FUN_1415e16b0(void* p)
{
    return p;
}

// @0x1415e16c0
void* FUN_1415e16c0(void* p)
{
    return p;
}

// @0x1415e16d0
void* FUN_1415e16d0(void* p)
{
    return p;
}

// @0x1415e16e0
void* FUN_1415e16e0(void* p)
{
    return p;
}

// @0x1415e16f0
void* FUN_1415e16f0(void* p)
{
    return p;
}

// @0x1415e1700
void* FUN_1415e1700(void* p)
{
    return p;
}

// @0x1415e1710
void* FUN_1415e1710(void* p)
{
    return p;
}

// @0x1415e1720
void* FUN_1415e1720(void* p)
{
    return p;
}

// @0x1415e1730
void* FUN_1415e1730(void* p)
{
    return p;
}

// @0x1415e1740
void* FUN_1415e1740(void* p)
{
    return p;
}

// @0x1415e1750
void* FUN_1415e1750(void* p)
{
    return p;
}

// @0x1415e1760
void* FUN_1415e1760(void* p)
{
    return p;
}

// @0x1415e1770
void* FUN_1415e1770(void* p)
{
    return p;
}

// @0x1415e1780
void* FUN_1415e1780(void* p)
{
    return p;
}

// @0x1415e1790
void* FUN_1415e1790(void* p)
{
    return p;
}

// @0x1415e17a0
void* FUN_1415e17a0(void* p)
{
    return p;
}

// @0x1415e17b0
void* FUN_1415e17b0(void* p)
{
    return p;
}

// @0x1415e17c0
void* FUN_1415e17c0(void* p)
{
    return p;
}

// @0x1415e17d0
void* FUN_1415e17d0(void* p)
{
    return p;
}

// @0x1415e17e0
void* FUN_1415e17e0(void* p)
{
    return p;
}

// @0x1415e17f0
void* FUN_1415e17f0(void* p)
{
    return p;
}

// @0x1415e1800
void* FUN_1415e1800(void* p)
{
    return p;
}

// @0x1415e1810
void* FUN_1415e1810(void* p)
{
    return p;
}

// @0x1415e1820
void* FUN_1415e1820(void* p)
{
    return p;
}

// @0x1415e1830
void* FUN_1415e1830(void* p)
{
    return p;
}

// @0x1415e1840
void* FUN_1415e1840(void* p)
{
    return p;
}

// @0x1415e1850
void* FUN_1415e1850(void* p)
{
    return p;
}

// @0x1415e1860
void* FUN_1415e1860(void* p)
{
    return p;
}

// @0x1415e1870
void* FUN_1415e1870(void* p)
{
    return p;
}

// @0x1415e1880
void* FUN_1415e1880(void* p)
{
    return p;
}

// @0x1415e1890
void* FUN_1415e1890(void* p)
{
    return p;
}

// @0x1415e18a0
void* FUN_1415e18a0(void* p)
{
    return p;
}

// @0x1415e18b0
void* FUN_1415e18b0(void* p)
{
    return p;
}

// @0x1415e18c0
void* FUN_1415e18c0(void* p)
{
    return p;
}

// @0x1415e18d0
void* FUN_1415e18d0(void* p)
{
    return p;
}

// @0x1415e18e0
void FUN_1415e18e0(void* a, void* b)
{
    char tag;
    FUN_1415cf050(a, b, tag);
}

// @0x1415e1910
void FUN_1415e1910(void* a, void* b)
{
    char tag;
    FUN_1415cf080(a, b, tag);
}

// @0x1415e1940
void FUN_1415e1940(void* a, void* b)
{
    char tag;
    FUN_1415cf0b0(a, b, tag);
}

// @0x1415e1970
void FUN_1415e1970(void* a, void* b)
{
    char tag;
    FUN_1415cf0e0(a, b, tag);
}

// @0x1415e19a0
void FUN_1415e19a0(void* a, void* b)
{
    char tag;
    FUN_1415cf110(a, b, tag);
}

// @0x1415e19d0
void FUN_1415e19d0(void* a, void* b)
{
    char tag;
    FUN_1415cf140(a, b, tag);
}

// @0x1415e1a00
void FUN_1415e1a00(void* a, void* b)
{
    char tag;
    FUN_1415cf170(a, b, tag);
}

// @0x1415e1a30
void FUN_1415e1a30(void* a, void* b)
{
    char tag;
    FUN_1415cf1a0(a, b, tag);
}

// @0x1415e1a60
void FUN_1415e1a60(void* a, void* b)
{
    char tag;
    FUN_1415cf1d0(a, b, tag);
}

// @0x1415e1a90
void FUN_1415e1a90(void* a, void* b)
{
    char tag;
    FUN_1415cf200(a, b, tag);
}

// @0x1415e1ac0
void FUN_1415e1ac0(void* a, void* b)
{
    char tag;
    FUN_1415cf230(a, b, tag);
}

// @0x1415e1af0
void FUN_1415e1af0(void* a, void* b)
{
    char tag;
    FUN_1415cf260(a, b, tag);
}

// @0x1415e1b20
void FUN_1415e1b20(void* a, void* b)
{
    char tag;
    FUN_1415cf290(a, b, tag);
}

// @0x1415e1b50
void FUN_1415e1b50(void* a, void* b)
{
    char tag;
    FUN_1415cf2c0(a, b, tag);
}

// @0x1415e1b80
void FUN_1415e1b80(void* a, void* b)
{
    char tag;
    FUN_1415cf2f0(a, b, tag);
}

// @0x1415e1bb0
void FUN_1415e1bb0(void* a, void* b)
{
    char tag;
    FUN_1415cf320(a, b, tag);
}

// @0x1415e1be0
void FUN_1415e1be0(void* a, void* b)
{
    char tag;
    FUN_1415cf350(a, b, tag);
}

// @0x1415e1c10
void FUN_1415e1c10(void* a, void* b)
{
    char tag;
    FUN_1415cf380(a, b, tag);
}

// @0x1415e1c40
void FUN_1415e1c40(void* a, void* b)
{
    char tag;
    FUN_1415cf3b0(a, b, tag);
}

// @0x1415e1c70
void FUN_1415e1c70(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415ceb50(&first, &last);
    FUN_1415cf3e0(dest, FUN_1415da9f0(first), FUN_1415da9f0(last), tag);
}

// @0x1415e1cd0
void FUN_1415e1cd0(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415ceb90(&first, &last);
    FUN_1415cf680(dest, FUN_1415daa00(first), FUN_1415daa00(last), tag);
}

// @0x1415e1d30
void FUN_1415e1d30(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cebd0(&first, &last);
    FUN_1415cf920(dest, FUN_1415daa70(first), FUN_1415daa70(last), tag);
}

// @0x1415e1d90
void FUN_1415e1d90(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cec10(&first, &last);
    FUN_1415cfbc0(dest, FUN_1415daa80(first), FUN_1415daa80(last), tag);
}

// @0x1415e1df0
void FUN_1415e1df0(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cec50(&first, &last);
    FUN_1415cfe60(dest, FUN_1415daa90(first), FUN_1415daa90(last), tag);
}

// @0x1415e1e50
void FUN_1415e1e50(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cec90(&first, &last);
    FUN_1415d0100(dest, FUN_1415daaa0(first), FUN_1415daaa0(last), tag);
}

// @0x1415e1eb0
void FUN_1415e1eb0(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cecd0(&first, &last);
    FUN_1415d03a0(dest, FUN_1415daab0(first), FUN_1415daab0(last), tag);
}

// @0x1415e1f10
void FUN_1415e1f10(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415ced10(&first, &last);
    FUN_1415d0640(dest, FUN_1415daac0(first), FUN_1415daac0(last), tag);
}

// @0x1415e1f70
void FUN_1415e1f70(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415ced50(&first, &last);
    FUN_1415d08e0(dest, FUN_1415daae0(first), FUN_1415daae0(last), tag);
}

// @0x1415e1fd0
void FUN_1415e1fd0(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415ced90(&first, &last);
    FUN_1415d0b80(dest, FUN_1415daaf0(first), FUN_1415daaf0(last), tag);
}

// @0x1415e2030
void FUN_1415e2030(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cedd0(&first, &last);
    FUN_1415d0e20(dest, FUN_1415dab00(first), FUN_1415dab00(last), tag);
}

// @0x1415e2090
void FUN_1415e2090(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cee10(&first, &last);
    FUN_1415d10c0(dest, FUN_1415dab10(first), FUN_1415dab10(last), tag);
}

// @0x1415e20f0
void FUN_1415e20f0(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cee50(&first, &last);
    FUN_1415d1360(dest, FUN_1415dab30(first), FUN_1415dab30(last), tag);
}

// @0x1415e2150
void FUN_1415e2150(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cee90(&first, &last);
    FUN_1415d1600(dest, FUN_1415dab40(first), FUN_1415dab40(last), tag);
}

// @0x1415e21b0
void FUN_1415e21b0(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415ceed0(&first, &last);
    FUN_1415d1b40(dest, FUN_1415dab80(first), FUN_1415dab80(last), tag);
}

// @0x1415e2210
void FUN_1415e2210(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cef10(&first, &last);
    FUN_1415d1de0(dest, FUN_1415dab90(first), FUN_1415dab90(last), tag);
}

// @0x1415e2270
void FUN_1415e2270(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cef50(&first, &last);
    FUN_1415d2080(dest, FUN_1415daba0(first), FUN_1415daba0(last), tag);
}

// @0x1415e22d0
void FUN_1415e22d0(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cef90(&first, &last);
    FUN_1415d2320(dest, FUN_1415daa10(first), FUN_1415daa10(last), tag);
}

// @0x1415e2330
void FUN_1415e2330(void* dest, void* first, void* last)
{
    char tag;
    FUN_1415cf010(&first, &last);
    FUN_1415d18a0(dest, FUN_1415daa50(first), FUN_1415daa50(last), tag);
}
