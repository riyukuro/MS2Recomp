// flybycameramode.h - CFlyByCameraMode (RTTI .?AVCFlyByCameraMode@@): a camera mode (id 3) that interpolates the camera
// settings from a start to an end CameraData (the game's `CameraData`, here Unk_CameraSetting) with a linear, log or
// exp curve. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\flybycameramode.cpp`
// (0x14121f110-0x1412208a0). Header name assumed (TInterpolator and the one-argument TFunctor are unit-local
// templates); vfunc_N are vftable slots.
#pragma once

#include "cameramode.h"
#include "ms2/placeholder/tfunctor.h"

// The one-argument functor (TFunctor<R, ParamList<A, EmptyParam>>); same shape as the EmptyParam family in tfunctor.h.
template<class R, class A> class FunctorImpl<R, ParamList<A, EmptyParam>> : public FunctorImplBase<R> {
public:
    FunctorImpl() {}
    FunctorImpl(const FunctorImpl& other) noexcept : FunctorImplBase<R>(other) {}
    virtual ~FunctorImpl() = default;
    virtual R Invoke(A a) = 0;
};
template<class R, class A> class TFunctor<R, ParamList<A, EmptyParam>> {
public:
    typedef R Result;
    typedef A Arg1;
    typedef FunctorImpl<R, ParamList<A, EmptyParam>> Impl;
    TFunctor() : implementation(nullptr) {}
    ~TFunctor() { Clear(); }
    R operator()(A a) { return implementation->Invoke(a); }
    bool IsNull() const { return implementation == nullptr; }
    void Clear() { if (implementation) { delete implementation; implementation = nullptr; } }
private:
    TFunctor(const TFunctor&);
    Impl* implementation;
};

// The interpolator base (0x70 bytes; the derived kinds add the elapsed time at +0x70).
template<class T> class TInterpolator
{
public:
    TInterpolator(float fDuration, const T& from, const T& to);
    virtual ~TInterpolator();
    virtual void vfunc_1() = 0;                         // reset
    virtual T vfunc_2(float fDelta) = 0;                // advance and return the blended value
    virtual void vfunc_3();                             // run the completion callback

    template<class Object, class Method> void SetCallback(const Object& object, Method method)
    {
        m_onComplete.Bind(object, method);
    }

    float m_fDuration;                                  // +0x08
    T m_from;                                           // +0x0c
    T m_to;                                             // +0x34
    TFunctor<void, EmptyParam> m_onComplete;            // +0x60
    TFunctor<T, ParamList<T, EmptyParam> > m_modifier;  // +0x68 (optional: rewrites the end value every step)
};

template<class T> class TLinearInterpolator : public TInterpolator<T>
{
public:
    TLinearInterpolator(float fDuration, const T& from, const T& to);
    virtual ~TLinearInterpolator();
    virtual void vfunc_1();
    virtual T vfunc_2(float fDelta);
    float m_fElapsed;                                   // +0x70
};

template<class T> class TLogInterpolator : public TInterpolator<T>
{
public:
    TLogInterpolator(float fDuration, const T& from, const T& to);
    virtual ~TLogInterpolator();
    virtual void vfunc_1();
    virtual T vfunc_2(float fDelta);
    float m_fElapsed;                                   // +0x70
};

template<class T> class TExpInterpolator : public TInterpolator<T>
{
public:
    TExpInterpolator(float fDuration, const T& from, const T& to);
    virtual ~TExpInterpolator();
    virtual void vfunc_1();
    virtual T vfunc_2(float fDelta);
    float m_fElapsed;                                   // +0x70
};

// 0x98 bytes. vftable: 37 slots.
class CFlyByCameraMode : public CCameraMode
{
public:
    CFlyByCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev, int nMode);   // 0x14121f110
    virtual ~CFlyByCameraMode();                                        // 0x14121f1c0

    // @0x141220190
    virtual int vfunc_1() { return 3; }
    // @0x141220210
    virtual bool vfunc_2() { return true; }
    virtual void vfunc_6(int n);                                        // 0x14121f440
    virtual void vfunc_7();                                             // 0x14121f850
    virtual void vfunc_8(double fTime);                                 // 0x14121f260
    virtual void vfunc_9();                                             // 0x14121f430

    Vector3 FUN_14121f910(const Vector3& a, const Vector3& b, const Vector3& c);
    void FUN_14121f9f0();                                               // interpolation finished: apply the end setting

    int m_nMode;                                                        // +0x78 (5: the cut-scene variant)
    float m_7c;
    void* m_80;
    TInterpolator<Unk_CameraSetting>* m_pInterp;                        // +0x88
    float m_fElapsed;                                                   // +0x90
    float m_fDuration;                                                  // +0x94
};
MS2_CHECK_SIZE(CFlyByCameraMode, 0x98);
MS2_CHECK_OFFSET(CFlyByCameraMode, m_pInterp, 0x88);
