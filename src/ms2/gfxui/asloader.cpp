// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASLoader, the wrapper of the AS3 Loader clip
// ("scaleform.ms2.loader.debugLoader") that shows an external image (icons, banners, guild event images).
// MS2-UNIT: ?\asloader.cpp
// MS2-RANGE: 0x1422e5300-0x1422e5a70 .text$mn
// MS2-PIN: ??_GASLoader@@UEAAPEAXI@Z 0x1422e59f0
// MS2-PIN: ??_GASURLRequest@@UEAAPEAXI@Z 0x1422e5a30
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: ASTextFieldEx's obj ends at 0x1422e5300; ASURLRequest's ctor starts the next obj at 0x1422e5a70. The class
// is declared in src/ms2/placeholder/asdisplayobject.h (method names invented after the AS calls). The tail holds the
// child binder AScript::FUN_1422e5780<ASEventDispatcher>, Invoke(method, ASURLRequest), the MS2Ptr<ASEventDispatcher>
// default ctor / copy ctor / operator=, MS2Ptr<ASURLRequest>::operator*, ASURLRequest's implicit copy ctor and the two
// scalar deleting dtors (ASURLRequest's is first emitted here, by the by-value Invoke argument).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/gfxui/asurlrequest.h"

#include "hook/ms2hook.h"

// The undefined value the loader clip starts from (a constant of the GFx UI library; aseffect.cpp).
extern Scaleform::GFx::Value DAT_143b0ae18;

// The GFx movie of a movie id (AScript's static helper, ascript.cpp range; null if the movie is not loaded).
Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);
// args[i] = v (the argument is destroyed by the callee; asitemslot.cpp declares the same).
void FUN_1422bcc70(Scaleform::GFx::Value* pDst, Scaleform::GFx::Value v);

// @0x1422e5300
ASLoader::ASLoader(int nMovieId)
    : ASDisplayObjectContainer(DAT_143b0ae18, nMovieId)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie == NULL)
        return;
    pMovie->CreateObject(&m_value, "scaleform.ms2.loader.debugLoader", NULL, 0);
    if (m_value.IsUndefined())
        return;
    BindContentLoaderInfo();
}

// @0x1422e53d0
ASLoader::ASLoader(const Scaleform::GFx::Value& v, int nMovieId)
    : ASDisplayObjectContainer(v, nMovieId)
{
    BindContentLoaderInfo();
}

// @0x1422e5440
ASLoader::~ASLoader()
{
    UnloadAndStop(true);
}

// @0x1422e54a0
void ASLoader::BindContentLoaderInfo()
{
    if (m_value.IsUndefined())
        return;
    FUN_1422e5780<ASEventDispatcher>("contentLoaderInfo", m_spContentLoaderInfo);
}
MS2_REPLACE_METHOD(0x1422E54A0, ASLoader, BindContentLoaderInfo, 124, 0x0CF9221E);

// @0x1422e5530
void ASLoader::Load(MS2Ptr<ASURLRequest> spRequest)
{
    Invoke("load", *spRequest);
}

// @0x1422e55c0
void ASLoader::UnloadAndStop(bool bGC)
{
    Invoke("unloadAndStop", bGC);
}
MS2_REPLACE_METHOD(0x1422E55C0, ASLoader, UnloadAndStop, 56, 0x01E16389);

// @0x1422e5600
void ASLoader::AddCompleteListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser)
{
    if (m_spContentLoaderInfo.get() != 0)
        m_spContentLoaderInfo->FUN_1422c3600("complete", cb, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422E5600, ASLoader, AddCompleteListener, 154, 0x9B06E033);

// @0x1422e56a0
void ASLoader::RemoveCompleteListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    if (m_spContentLoaderInfo.get() != 0)
        m_spContentLoaderInfo->FUN_1422c3820("complete", cb, false);
}
MS2_REPLACE_METHOD(0x1422E56A0, ASLoader, RemoveCompleteListener, 123, 0xC983CB1D);

// @0x1422e5730
Scaleform::GFx::Value ASLoader::GetContent()
{
    return FUN_1422baa20("content");
}
MS2_REPLACE_METHOD(0x1422E5730, ASLoader, GetContent, 65, 0x29D49803);

// @0x1422e5780
template <class T> MS2Ptr<T> AScript::FUN_1422e5780(const CString& strName, MS2Ptr<T>& out)
{
    out = FUN_140eb9cf0<T>(strName);
    return out;
}

// @0x1422e5810
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, ASURLRequest a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1.FUN_1422bb890());
    return FUN_1422bb8f0(szMethod, args);
}
