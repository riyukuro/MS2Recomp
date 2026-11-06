// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Four small helpers: a second copy of MS2Ptr<CLoadingDialog>::AddRef /
// AddRefImpl (m_p at +8), and two one-line forwarders.
// MS2-UNIT: unit_1414a6b50
// MS2-RANGE: 0x1414a6b50-0x1414a6be0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

#include "ms2/placeholder/ms2ptr_impl.h"   // C3: MS2Ptr<CLoadingDialog>::AddRef / AddRefImpl (0x140d4db40 is its Reference)
#include <list>   // 0x140ad85f0 = _List_alloc<pair<const unsigned long, MS2Ptr<TermTagContext>>>::_Buynode0
class CLoadingDialog; class TermTagContext;   // the pointee: symbols row ?AddRef@?$MS2Ptr@VCLoadingDialog@@@@AEBAXXZ at 0x1414a6b50 (a second copy of the AddRef / AddRefImpl pair)
//struct Unk_1414a6b50Ptr
//{
//    void* pad_00;
//    void* m_p;
//
//    void AddRef() const;
//    void AddRefImpl(void*) const;
//};

// @0x1414a6b50
template void MS2Ptr<CLoadingDialog>::AddRef() const;
//{
//    if (m_p)
//        AddRefImpl(0);
//}

// @0x1414a6b80
template void MS2Ptr<CLoadingDialog>::AddRefImpl(void*) const;
//{
//    FUN_140d4db40(m_p);
//}

// @0x1414a6bb0
int Unk_1414a6b50Free_Kind() { return 3; }

// @0x1414a6bc0
void Unk_1414a6bc0(void* p)
{
    typedef std::_List_alloc<std::_List_base_types<std::pair<const unsigned long, MS2Ptr<TermTagContext> >, std::allocator<std::pair<const unsigned long, MS2Ptr<TermTagContext> > > > > Unk_TtListAlc; reinterpret_cast<Unk_TtListAlc*>(p)->_Buynode0(nullptr, nullptr);
}
