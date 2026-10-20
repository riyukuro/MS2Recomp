// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASEventDispatcher, the flash.events.EventDispatcher wrapper
// of the GFx UI library, and ASEventHandlerCtx, the AS function object that calls a C++ delegate. Declared in
// placeholder/asdisplayobject.h.
// MS2-UNIT: ?\aseventdispatcher.cpp
// MS2-RANGE: 0x1422c2fc0-0x1422c4c00 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings). The tail is the
// AScript::Invoke instances of the IEventDispatcher calls, the SDK FunctionHandler / Ptr inlines and the
// CAtlArray<Ptr<ASEventHandlerCtx>> instantiation.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asevent.h"
#include "hook/ms2hook.h"

using Scaleform::GFx::Value;

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)
extern Value DAT_143b0ae18;                                     // an undefined value (unit_140135ac0.cpp)
void FUN_140657820();                                           // throws: a null delegate was called

// Invoke argument setters (ascript.cpp's range).
void FUN_1422bce70(Value* pValue, const char* sz);
void FUN_1422bcc70(Value* pValue, Value v);
void FUN_1422bcce0(Value* pValue, bool b);
void FUN_1422bcd70(Value* pValue, float f);
void FUN_1422bce40(Value* pValue, const AScript& obj);

// @0x1422c4400
template <> inline void ASEventHandlerCtx::Callback::operator()(const Scaleform::GFx::FunctionHandler::Params& a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// @0x1422c4330
template <> inline bool ASEventHandlerCtx::Callback::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

// @0x1422c2fc0
ASEventHandlerCtx::ASEventHandlerCtx(CString strType, Callback cb)
    : m_strType(strType), m_cb(cb)
{
}

// @0x1422c3060
void ASEventHandlerCtx::Call(const Params& params)
{
    m_cb(params);
}

// @0x1422c3090
ASEventDispatcher::ASEventDispatcher(const Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
}

// @0x1422c3100
ASEventDispatcher::~ASEventDispatcher()
{
    FUN_1422c34f0();
    FUN_1422c3940();
}

// @0x1422c3180
void ASEventDispatcher::FUN_1422c3180(CString strName, const Callback& cb)
{
    for (int i = 0; i < (int)m_members.GetCount(); i++) {
        if (m_members[i]->m_strType == strName)
            return;
    }
    Scaleform::Ptr<ASEventHandlerCtx> spCtx = *new ASEventHandlerCtx(strName, cb);
    FUN_1422bb8b0(m_nMovieId)->CreateFunction(&spCtx->m_func, spCtx.GetPtr(), 0);
    m_members.Add(spCtx);
    FUN_1409adbe0(strName, spCtx->m_func);
}

// @0x1422c33c0
void ASEventDispatcher::FUN_1422c33c0(CString strName)
{
    for (int i = 0; i < (int)m_members.GetCount(); i++) {
        if (m_members[i]->m_strType == strName) {
            FUN_1409adbe0(strName, DAT_143b0ae18);
            m_members[i]->m_func.SetNull();
            m_members.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x1422c34f0
void ASEventDispatcher::FUN_1422c34f0()
{
    for (int i = 0; i < (int)m_members.GetCount(); i++) {
        FUN_1409adbe0(m_members[i]->m_strType, DAT_143b0ae18);
        m_members[i]->m_func.SetNull();
    }
    m_members.RemoveAll();
}

// @0x1422c3600
void ASEventDispatcher::FUN_1422c3600(const CString& strEvent, const Callback& cb, bool bCapture, int nPriority, int a5,
                                      void* pUser)
{
    for (int i = 0; i < (int)m_listeners.GetCount(); i++) {
        if (m_listeners[i]->m_cb == cb)
            return;
    }
    Scaleform::Ptr<ASEventHandlerCtx> spCtx = *new ASEventHandlerCtx(strEvent, cb);
    FUN_1422bb8b0(m_nMovieId)->CreateFunction(&spCtx->m_func, spCtx.GetPtr(), pUser);
    m_listeners.Add(spCtx);
    FUN_1422c3a30(strEvent, spCtx->m_func, bCapture, nPriority, a5);
}

// @0x1422c3820
void ASEventDispatcher::FUN_1422c3820(const CString& strEvent, const Callback& cb, bool bCapture)
{
    for (int i = 0; i < (int)m_listeners.GetCount(); i++) {
        if (m_listeners[i]->m_cb == cb) {
            FUN_1422c3b30(strEvent, m_listeners[i]->m_func, bCapture);
            m_listeners[i]->m_func.SetNull();
            m_listeners.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x1422c3940
void ASEventDispatcher::FUN_1422c3940()
{
    for (int i = 0; i < (int)m_listeners.GetCount(); i++) {
        FUN_1422c3b30(m_listeners[i]->m_strType, m_listeners[i]->m_func, false);
        m_listeners[i]->m_func.SetNull();
    }
    m_listeners.RemoveAll();
}

// @0x1422c3a30
void ASEventDispatcher::FUN_1422c3a30(const CString& strType, const Value& listener, bool bUseCapture, int nPriority,
                                      int bUseWeakReference)
{
    Invoke("addEventListener", strType, listener, bUseCapture, (float)nPriority, bUseWeakReference != 0);
}

// @0x1422c3b30
void ASEventDispatcher::FUN_1422c3b30(const CString& strType, const Value& listener, bool bUseCapture)
{
    FUN_1422c3e40("removeEventListener", strType, listener, bUseCapture);
}

// @0x1422c3bf0
int ASEventDispatcher::FUN_1422c3bf0(const CString& strType)
{
    return Invoke("hasEventListener", strType).GetBool();
}

// @0x1422c3c90
int ASEventDispatcher::FUN_1422c3c90(const CString& strType)
{
    return Invoke("willTrigger", strType).GetBool();
}

// @0x1422c3d30
int ASEventDispatcher::FUN_1422c3d30(ASEvent& ev)
{
    return Invoke("dispatchEvent", ev).GetBool();
}

// @0x1422c3da0
inline Value AScript::Invoke(const char* szMethod, const ASEvent& a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bce40(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1422c3e40
inline Value AScript::FUN_1422c3e40(const char* szMethod, CString a1, Value a2, bool a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1422c3f80
inline Value AScript::Invoke(const char* szMethod, CString a1, Value a2, bool a3, float a4, bool a5)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcd70(args.FUN_1409b1f70(3), a4);
    FUN_1422bcce0(args.FUN_1409b1f70(4), a5);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_REPLACE_METHOD(0x1422C3060, ASEventHandlerCtx, Call, 41, 0x42C5CD5B);
MS2_REPLACE_METHOD(0x1422C3180, ASEventDispatcher, FUN_1422c3180, 557, 0x6643482F);
MS2_REPLACE_METHOD(0x1422C33C0, ASEventDispatcher, FUN_1422c33c0, 294, 0x876F7367);
MS2_REPLACE_METHOD(0x1422C34F0, ASEventDispatcher, FUN_1422c34f0, 253, 0x7360C678);
MS2_REPLACE_METHOD(0x1422C3600, ASEventDispatcher, FUN_1422c3600, 527, 0x6DB52C8F);
MS2_REPLACE_METHOD(0x1422C3820, ASEventDispatcher, FUN_1422c3820, 269, 0xA7EBAB2E);
MS2_REPLACE_METHOD(0x1422C3940, ASEventDispatcher, FUN_1422c3940, 232, 0x8C5AD1E9);
MS2_REPLACE_METHOD(0x1422C3A30, ASEventDispatcher, FUN_1422c3a30, 250, 0x5501BD2E);
MS2_REPLACE_METHOD(0x1422C3B30, ASEventDispatcher, FUN_1422c3b30, 186, 0x530C8285);
MS2_REPLACE_METHOD(0x1422C3BF0, ASEventDispatcher, FUN_1422c3bf0, 144, 0x785A949C);
MS2_REPLACE_METHOD(0x1422C3C90, ASEventDispatcher, FUN_1422c3c90, 144, 0xC3D67C53);
MS2_REPLACE_METHOD(0x1422C3D30, ASEventDispatcher, FUN_1422c3d30, 101, 0xD43978BC);

// MS2-PIN: ??_G?$RefCountBase@VFunctionHandler@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1422c4480
