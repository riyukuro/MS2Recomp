// ms2ptr_impl.h - generic bodies of MS2Ptr<T> (ascript.h), the game's 16-byte intrusive pointer to CPtred-derived
// objects. NOT an original header. Recovered from the first .text$mn obj (?\achievecondition.cpp), where the
// instances for CAchieveData, CAchieveGradeData, CConditionCommonData and a game-event type byte-match.
//
// Include it in a unit that wants MS2Ptr<T> members as implicit COMDAT instantiations (the exe has one copy per T in
// the first obj that used it). Units that write explicit specializations of single members (uiitemdropinfodialog,
// uicommunitypopup, ...) must not include it, or must declare their specializations before the first use.
// T must derive from CPtred at offset 0 (the helpers take CPtred*).
#pragma once

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

template <class T> MS2Ptr<T>::MS2Ptr() { m_p = 0; }
template <class T> MS2Ptr<T>::MS2Ptr(int) { m_p = 0; }
template <class T> MS2Ptr<T>::MS2Ptr(T* p) { m_p = p; AddRef(); }
template <class T> MS2Ptr<T>::MS2Ptr(const MS2Ptr& o) { m_p = o.m_p; AddRef(); }
template <class T> MS2Ptr<T>::~MS2Ptr() { Release(); }
template <class T> MS2Ptr<T>& MS2Ptr<T>::operator=(const MS2Ptr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> MS2Ptr<T>& MS2Ptr<T>::operator=(int) { Release(); return *this; }
template <class T> MS2Ptr<T>& MS2Ptr<T>::AssignRaw(T* p)
{
    MS2Ptr tmp(p);
    T* pOld = m_p;
    m_p = tmp.m_p;
    tmp.m_p = pOld;
    return *this;
}
template <class T> bool MS2Ptr<T>::operator==(T* p) const { return m_p == p; }
template <class T> T* MS2Ptr<T>::get() const { return m_p; }
template <class T> MS2Ptr<T>::operator T*() const { return m_p; }
template <class T> T* MS2Ptr<T>::operator->() const { return m_p; }
template <class T> T& MS2Ptr<T>::operator*() const { return *m_p; }
template <class T> bool MS2Ptr<T>::IsNull() const { return m_p == 0; }
template <class T> void MS2Ptr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void MS2Ptr<T>::AddRefImpl(void*) const { Reference(m_p); }
template <class T> void MS2Ptr<T>::Reference(T* p) { CPtred::AddRefPtred(p); }
template <class T> void MS2Ptr<T>::Release()
{
    if (m_p)
    {
        ReleaseImpl(0);
        m_p = 0;
    }
}
template <class T> void MS2Ptr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0)
    {
        Reference(m_p);
        CPtred::DeletePtred(m_p);
    }
}
