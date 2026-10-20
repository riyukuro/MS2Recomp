// nigfxexternalinterfacedelegate.h - PLACEHOLDER for NiGFxExternalInterfaceDelegate<T> (RTTI
// .?AV?$NiGFxExternalInterfaceDelegate@VGFxMovie@@@@, 0x30 bytes, base Scaleform::GFx::ExternalInterface): forwards the
// movie's ExternalInterface.call callbacks to a member function of T. NOT an original header (the name suggests the
// Gamebryo GFx integration, which is not in our SDK copy). Instantiated for GFxMovie in ?\gfxmovie.cpp (vftable 0x14310aae0?
// see the unit; ctor 0x1422be9c0, Create 0x1422be730, Callback 0x1422bf4f0, scalar deleting dtor 0x1422bf370), bound to
// GFxMovie::vfunc_4 (a vcall thunk: the slot is virtual).
#pragma once

#include "ms2/placeholder/gfxvalue.h"

template <class T>
class NiGFxExternalInterfaceDelegate : public Scaleform::GFx::ExternalInterface
{
public:
    // The callback's movie parameter is void* because GFxMovie::vfunc_4 (and its overrides) spell it so.
    typedef void (T::*Callback_t)(void* pMovie, const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs);

    NiGFxExternalInterfaceDelegate(T* pObj, Callback_t pfn)
        : m_pObj(pObj), m_pfn(pfn)
    {
    }
    // new (the RefCountBase class operator new) wrapped in a Ptr that takes over the reference
    static Scaleform::Ptr<NiGFxExternalInterfaceDelegate> Create(T* pObj, Callback_t pfn)
    {
        return *new NiGFxExternalInterfaceDelegate(pObj, pfn);
    }
    virtual void Callback(Scaleform::GFx::Movie* pMovieView, const char* szMethod, const Scaleform::GFx::Value* pArgs,
                          unsigned nArgs)
    {
        (m_pObj->*m_pfn)(pMovieView, szMethod, pArgs, nArgs);
    }

private:
    T* m_pObj;                                                      // +0x18
    Callback_t m_pfn;                                               // +0x20 (16 bytes: pointer + this adjustment)
};
