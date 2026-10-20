// Original functor family, recovered from CFileSystem's archive callbacks.
// FunctorImplBase and FunctorImpl are 8-byte polymorphic bases. TFunctor is
// an owning 8-byte handle; ClassFunHandler holds object and member pointers.
#pragma once
#include "ms2/ms2layout.h"
class EmptyParam {};
template<class Head, class Tail> class ParamList {};
template<class Result> class FunctorImplBase {
public:
    FunctorImplBase() {}
    FunctorImplBase(const FunctorImplBase&) noexcept {}
    virtual ~FunctorImplBase() {}
    virtual FunctorImplBase* Clone() const = 0;
};
template<class Result, class Parameters> class FunctorImpl;
template<class R, class A, class B, class C, class D, class E>
class FunctorImpl<R, ParamList<A, ParamList<B, ParamList<C, ParamList<D, ParamList<E, EmptyParam>>>>>>
    : public FunctorImplBase<R> {
public:
    FunctorImpl() {}
    FunctorImpl(const FunctorImpl& other) noexcept : FunctorImplBase<R>(other) {}
    virtual ~FunctorImpl() = default;
    virtual R Invoke(A, B, C, D, E) = 0;
};
template<class Functor, class Object, class Method> class ClassFunHandler : public Functor::Impl {
public:
    typedef typename Functor::Result Result;
    ClassFunHandler(const Object& object, Method method) : object(object), method(method) {}
    ClassFunHandler(const ClassFunHandler& other) noexcept
        : Functor::Impl(other), object(other.object), method(other.method) {}
    virtual ~ClassFunHandler() = default;
    virtual ClassFunHandler* Clone() const { return new ClassFunHandler(*this); }
    virtual Result Invoke(typename Functor::Arg1 a, typename Functor::Arg2 b, typename Functor::Arg3 c,
                          typename Functor::Arg4 d, typename Functor::Arg5 e) {
        return (object->*method)(a, b, c, d, e);
    }
private:
    Object object;
    Method method;
};
template<class Result, class Parameters> class TFunctor;
template<class R, class A, class B, class C, class D, class E>
class TFunctor<R, ParamList<A, ParamList<B, ParamList<C, ParamList<D, ParamList<E, EmptyParam>>>>>> {
public:
    typedef R Result;
    typedef A Arg1; typedef B Arg2; typedef C Arg3; typedef D Arg4; typedef E Arg5;
    typedef ParamList<A, ParamList<B, ParamList<C, ParamList<D, ParamList<E, EmptyParam>>>>> Parameters;
    typedef FunctorImpl<R, Parameters> Impl;
    TFunctor() : implementation(nullptr) {}
    template<class Object, class Method> TFunctor(const Object& object, Method method)
        : implementation(new ClassFunHandler<TFunctor, Object, Method>(object, method)) {}
    TFunctor(const TFunctor& other) : implementation(Clone(other.implementation)) {}
    ~TFunctor() { Clear(); }
    TFunctor& operator=(const TFunctor& other) {
        Clear();
        implementation = Clone(other.implementation);
        return *this;
    }
    R operator()(A a, B b, C c, D d, E e) { return implementation->Invoke(a, b, c, d, e); }
private:
    static Impl* Clone(Impl* source) {
        if (!source)
            return nullptr;
        Impl* clone = static_cast<Impl*>(source->Clone());
        return clone;
    }
    void Clear() { if (implementation) { delete implementation; implementation = nullptr; } }
    Impl* implementation;
};
MS2_CHECK_SIZE(FunctorImplBase<unsigned long>, 8);

template<class R> class FunctorImpl<R, EmptyParam> : public FunctorImplBase<R> {
public:
    FunctorImpl() {}
    FunctorImpl(const FunctorImpl& other) noexcept : FunctorImplBase<R>(other) {}
    virtual ~FunctorImpl() = default;
    virtual R Invoke() = 0;
};
template<class R> class TFunctor<R, EmptyParam> {
public:
    typedef R Result;
    typedef FunctorImpl<R, EmptyParam> Impl;
    TFunctor() : implementation(nullptr) {}
    template<class Object, class Method> TFunctor(const Object& object, Method method)
        : implementation(new ClassFunHandler<TFunctor, Object, Method>(object, method)) {}
    TFunctor(const TFunctor& other) : implementation(Clone(other.implementation)) {}
    ~TFunctor() { Clear(); }
    TFunctor& operator=(const TFunctor& other) {
        Clear(); implementation = Clone(other.implementation); return *this;
    }
    R operator()() { return implementation->Invoke(); }
    bool IsNull() const { return implementation == nullptr; }
    // MS2: replace the handler with a new ClassFunHandler (flybycameramode.cpp, 0x14121fa40 for CFlyByCameraMode).
    template<class Object, class Method> void Bind(const Object& object, Method method) {
        if (!IsNull()) Clear();
        Impl* pImpl = new ClassFunHandler<TFunctor, Object, Method>(object, method);
        implementation = pImpl;
    }
    void Clear() { if (implementation) { delete implementation; implementation = nullptr; } }
private:
    static Impl* Clone(Impl* source) {
        if (!source) return nullptr;
        Impl* pClone = static_cast<Impl*>(source->Clone());
        return pClone;
    }
    Impl* implementation;
};
template<class R, class Object, class Method>
class ClassFunHandler<TFunctor<R, EmptyParam>, Object, Method> : public FunctorImpl<R, EmptyParam> {
public:
    ClassFunHandler(const Object& object, Method method) : object(object), method(method) {}
    ClassFunHandler(const ClassFunHandler& other) noexcept
        : FunctorImpl<R, EmptyParam>(other), object(other.object), method(other.method) {}
    virtual ~ClassFunHandler() = default;
    virtual ClassFunHandler* Clone() const { return new ClassFunHandler(*this); }
    virtual R Invoke() { return (object->*method)(); }
private:
    Object object;
    Method method;
};
