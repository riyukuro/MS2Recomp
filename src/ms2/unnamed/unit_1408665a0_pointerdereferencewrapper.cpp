// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dereferencing accessor and its discarding wrapper.
// MS2-UNIT: unit_1408665a0
// MS2-RANGE: 0x1408665a0-0x1408665e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <deque>
class _CTaxiPathInfo; template <class T> class Unk_TaxiPtr;   // 0x140864d80 = _Deque_alloc<..Unk_TaxiPtr<_CTaxiPathInfo>..>::_Mysize() const (taximanager)
void* FUN_1408665a0(void* node);

// @0x1408665a0
void* FUN_1408665a0(void* node)
{
    return (void*)((const std::_Deque_alloc<std::_Deque_base_types<Unk_TaxiPtr<_CTaxiPathInfo>, std::allocator<Unk_TaxiPtr<_CTaxiPathInfo>>>>*)node)->_Mysize();
}

// The argument is the node's first member.
struct Unk_NodeView
{
    void* m_first;
};

// @0x1408665c0
void FUN_1408665c0(void* node)
{
    FUN_1408665a0(&static_cast<Unk_NodeView*>(node)->m_first);
}
