// unk_stlglue.h - stand-ins for the anonymous element types of the STL template zone of the boxed-pointer TU
// (unit_1415d3570, unit_1415dad30 and neighbours). Only sizeof(T) of each element type is known, so the vector glue is
// written as free functions over Unk_StlElem<sizeof(T)>; the member functions of the exe's templates take the
// container as first argument (same ABI).
#pragma once

// an element of sizeof(T) == N
template <size_t N>
struct Unk_StlElem
{
    unsigned char m_bytes[N];
};

// std::_Uninitialized_backout_al<T*, allocator<T>>: the elements [m_pFirst, m_pLast) constructed so far. The ctor and
// dtor of each instantiation live in other units and are bound to the exe by symbols-manual rows.
template <class T>
struct Unk_StlBackout
{
    Unk_StlBackout(T* pDest, void* pAl);
    ~Unk_StlBackout();

    T* m_pFirst;
    T* m_pLast;
    void* m_pAl;
};
