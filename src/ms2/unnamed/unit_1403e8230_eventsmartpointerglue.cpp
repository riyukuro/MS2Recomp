// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tail of the gameevent smart-pointer glue (see unit_1403e9650): the
// std::map<int,int> copy assignment (GameEventSAHotTime copies its SA value map into SAHotTimeEventContext) and 13 identical
// MS2Ptr<T>::IsNull / 4 identical MS2Ptr<T>::operator==(T*) instances (`m_p == 0` / `m_p == p` at +8; element types not
// recoverable per copy, so unit-local stand-ins as in unit_1403e8960).
// MS2-UNIT: unit_1403e8230
// MS2-RANGE: 0x1403e8230-0x1403e8650 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <map>

// Smart-pointer shaped handle: 8 bytes of header, then the raw pointer.
template <int N>
class Unk_Ptr
{
public:
    bool IsNull() const { return m_p == 0; }
    bool Equals(void* p) const { return m_p == p; }
    void* m_pHeader;
    void* m_p;
};

template std::map<int, int>& std::map<int, int>::operator=(const std::map<int, int>&);   // 0x1403e82b0, _Tree::operator= 0x1403e8230

template bool Unk_Ptr<0>::IsNull() const;   // 0x1403e82e0
template bool Unk_Ptr<1>::IsNull() const;   // 0x1403e8310
template bool Unk_Ptr<2>::IsNull() const;   // 0x1403e8340
template bool Unk_Ptr<3>::IsNull() const;   // 0x1403e8370
template bool Unk_Ptr<4>::IsNull() const;   // 0x1403e83a0
template bool Unk_Ptr<5>::IsNull() const;   // 0x1403e83d0
template bool Unk_Ptr<6>::IsNull() const;   // 0x1403e8400
template bool Unk_Ptr<7>::IsNull() const;   // 0x1403e8430
template bool Unk_Ptr<8>::IsNull() const;   // 0x1403e8460
template bool Unk_Ptr<9>::IsNull() const;   // 0x1403e8490
template bool Unk_Ptr<10>::IsNull() const;   // 0x1403e84c0
template bool Unk_Ptr<11>::IsNull() const;   // 0x1403e84f0
template bool Unk_Ptr<12>::IsNull() const;   // 0x1403e8520
template bool Unk_Ptr<0>::Equals(void*) const;   // 0x1403e8550
template bool Unk_Ptr<1>::Equals(void*) const;   // 0x1403e8590
template bool Unk_Ptr<2>::Equals(void*) const;   // 0x1403e85d0
template bool Unk_Ptr<3>::Equals(void*) const;   // 0x1403e8610
