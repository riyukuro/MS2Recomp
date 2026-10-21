// Two-argument functors bound to a free function (FunctorHandler<TFunctor, Fn>), sharing the established functor bases.
// Seen in MS2::RegisterServices: the Scaleform image callback TFunctor<Image*, ParamList<const Protocol&, ParamList<
// TextureManager*, EmptyParam>>> built from a function pointer (vftable 2 slots after FunctorImplBase: Clone, Invoke).
#pragma once
#include "ms2/placeholder/tfunctor.h"
template<class R,class A,class B>
class FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> : public FunctorImplBase<R> {
public:
    FunctorImpl() {}
    FunctorImpl(const FunctorImpl& o) noexcept : FunctorImplBase<R>(o) {}
    virtual ~FunctorImpl() = default;
    virtual R Invoke(A,B) = 0;
};
template<class Functor,class Fn> class FunctorHandler;
template<class R,class A,class B,class Fn>
class FunctorHandler<TFunctor<R,ParamList<A,ParamList<B,EmptyParam>>>,Fn>
    : public FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> {
public:
    typedef FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> Impl;
    FunctorHandler(const Fn& f) : fn(f) {}
    FunctorHandler(const FunctorHandler& o) noexcept : Impl(o),fn(o.fn) {}
    virtual ~FunctorHandler() = default;
    virtual FunctorHandler* Clone() const { return new FunctorHandler(*this); }
    virtual R Invoke(A a,B b) { return fn(a,b); }
private:
    Fn fn;
};
template<class R,class A,class B>
class TFunctor<R,ParamList<A,ParamList<B,EmptyParam>>> {
public:
    typedef FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> Impl;
    TFunctor() : implementation(0) {}
    template<class Fn> TFunctor(Fn fn) : implementation(new FunctorHandler<TFunctor,Fn>(fn)) {}
    // MS2: bound member function (ms2memfile.cpp, 0x141628a30 for CFileSystem)
    template<class Object,class Method> TFunctor(const Object& o,Method m)
        : implementation(new ClassFunHandler<TFunctor,Object,Method>(o,m)) {}
    TFunctor(const TFunctor& o) : implementation(Clone(o.implementation)) {}
    ~TFunctor() { Clear(); }
    TFunctor& operator=(const TFunctor& o) { Clear(); implementation=Clone(o.implementation); return *this; }
    R operator()(A a,B b) { return implementation->Invoke(a,b); }
    bool IsNull() const { return implementation==0; }
    void Clear() { if(implementation) { delete implementation; implementation=0; } }
private:
    static Impl* Clone(Impl* p) { if(p==0) return 0; Impl* copy=static_cast<Impl*>(p->Clone()); return copy; }
    Impl* implementation;
};
// Two-argument handler bound to an object and member function (appended by gap3: ms2memfile.cpp, the file-change
// listener ClassFunHandler<TFunctor<void, ParamList<CString, ParamList<FILETIME>>>, CFileSystem*, ...>, 0x18 bytes;
// tfunctor_search.h has the same form for units that include it instead of this header).
template<class R,class A,class B,class Object,class Method>
class ClassFunHandler<TFunctor<R,ParamList<A,ParamList<B,EmptyParam>>>,Object,Method>
    : public FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> {
public:
    typedef FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> Impl;
    ClassFunHandler(const Object& o,Method m) : object(o),method(m) {}
    ClassFunHandler(const ClassFunHandler& o) noexcept : Impl(o),object(o.object),method(o.method) {}
    virtual ~ClassFunHandler() = default;
    virtual ClassFunHandler* Clone() const { return new ClassFunHandler(*this); }
    virtual R Invoke(A a,B b) { return (object->*method)(a,b); }
private:
    Object object;
    Method method;
};
