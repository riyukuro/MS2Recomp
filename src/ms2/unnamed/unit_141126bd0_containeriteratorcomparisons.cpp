// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A zone of STL/ATL COMDATs: 25 pointer-wrapper iterator
// comparison pairs, the std::string / std::wstring const_iterator comparisons, a 3-int key comparison, a CAtlArray indexer
// and a map lookup. The iterator types are unit-local stand-ins (Unk_Iter<n>): the exe's own template argument lists are
// not recoverable from the byte-identical bodies; the callers only use them as opaque iterators.
// MS2-UNIT: unit_141126bd0
// MS2-RANGE: 0x141126bd0-0x141127a90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$Unk_Int3@$0A@@@QEBA_NAEBV0@@Z 0x1411272b0 ; unique
// MS2-PIN: ??9?$Unk_Int3@$0A@@@QEBA_NAEBV0@@Z 0x1411279c0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <string>
#include <atlcoll.h>
#include <efd/StdContainers.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unit-local iterator stand-in (N selects the exe copy; the exe's real template argument lists are unknown).
template <int N>
class Unk_Iter
{
public:
    bool operator==(const Unk_Iter& r) const { return (m_ptr == r.m_ptr); }
    bool operator!=(const Unk_Iter& r) const { return (!(*this == r)); }
    void* m_ptr;
};

template class Unk_Iter<0>;
template class Unk_Iter<1>;
template class Unk_Iter<2>;
template class Unk_Iter<3>;
template class Unk_Iter<4>;
template class Unk_Iter<5>;
template class Unk_Iter<6>;
template class Unk_Iter<7>;
template class Unk_Iter<8>;
template class Unk_Iter<9>;
template class Unk_Iter<10>;
template class Unk_Iter<11>;
template class Unk_Iter<12>;
template class Unk_Iter<13>;
template class Unk_Iter<14>;
template class Unk_Iter<15>;
template class Unk_Iter<16>;
template class Unk_Iter<17>;
template class Unk_Iter<18>;
template class Unk_Iter<19>;
template class Unk_Iter<20>;
template class Unk_Iter<21>;
template class Unk_Iter<22>;
template class Unk_Iter<23>;
template class Unk_Iter<24>;

// std::wstring::const_iterator comparisons (each calls its own empty _Compat). The char (std::string) pair here is a byte-identical
// look-alike of filesystem.cpp's real std::string iterator copy (0x1403a7800 / 0x1403a79a0), so it is a unit-local stand-in.
// Unk_StdCharIter<0>: 0x141127210 (==), 0x141127940 (!=); _Compat 0x141134f50.
template <int N>
class Unk_StdCharIter
{
public:
    void _Compat(const Unk_StdCharIter&) const {}
    bool operator==(const Unk_StdCharIter& r) const { _Compat(r); return (m_ptr == r.m_ptr); }
    bool operator!=(const Unk_StdCharIter& r) const { return (!(*this == r)); }
    const char* m_ptr;
};
// MS2-PIN: ??8?$_String_const_iterator@V?$_String_val@U?$_Simple_types@_W@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127260
// MS2-PIN: ??9?$_String_const_iterator@V?$_String_val@U?$_Simple_types@_W@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141127980
// MS2-PIN: ??8?$Unk_StdCharIter@$0A@@@QEBA_NAEBV0@@Z 0x141127210
// MS2-PIN: ??9?$Unk_StdCharIter@$0A@@@QEBA_NAEBV0@@Z 0x141127940
template bool Unk_StdCharIter<0>::operator==(const Unk_StdCharIter<0>&) const;
template bool std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >::operator==(const std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >&) const;
template bool Unk_StdCharIter<0>::operator!=(const Unk_StdCharIter<0>&) const;
template bool std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >::operator!=(const std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >&) const;

// A 12-byte key of three ints compared member-wise.
template <int N>
class Unk_Int3
{
public:
    bool operator==(const Unk_Int3& r) const
    {
        if (r.m_a == m_a && r.m_b == m_b && r.m_c == m_c)
            return true;
        return false;
    }
    bool operator!=(const Unk_Int3& r) const
    {
        if (r.m_a != m_a || r.m_b != m_b || r.m_c != m_c)
            return true;
        return false;
    }
    int m_a;
    int m_b;
    int m_c;
};

template class Unk_Int3<0>;

// A 16-byte array element (two pointers).
struct Unk_Elem16
{
    void* m_p0;
    void* m_p1;
};

// CAtlArray<Unk_Elem16>::operator[]: bounds-checked (AtlThrow(E_INVALIDARG)).
// MS2-PIN: ??A?$CAtlArray@UUnk_Elem16@@V?$CElementTraits@UUnk_Elem16@@@ATL@@@ATL@@QEAAAEAUUnk_Elem16@@_K@Z 0x141127a10
template Unk_Elem16& ATL::CAtlArray<Unk_Elem16, ATL::CElementTraits<Unk_Elem16> >::operator[](size_t) throw();

// efd::map<long,int>::operator[] (= try_emplace(key).first->second), keyed by the cube position hash (key type long: the exe has distinct operator-> copies per 32-bit key type; int/unsigned/unsigned long are taken by other units).
// MS2-PIN: ??A?$map@JHU?$less@J@std@@V?$CustomAllocator@U?$pair@$$CBJH@std@@@efd@@@std@@QEAAAEAHAEBJ@Z 0x141127a50
template int& std::map<long, int, std::less<long>, efd::CustomAllocator<std::pair<const long, int> > >::operator[](const long&);
