// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASUIComponent, the ActionScript UIComponent wrapper of the
// GFx UI library (an ASMovieClip with focus, size, tooltip and invalidate helpers).
// MS2-UNIT: ?\asuicomponent.cpp
// MS2-RANGE: 0x1422c70b0-0x1422c8390 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asuicomponent.h; its slots 3 and 16-24 are opt-in there
// (MS2_ASUICOMPONENT_SLOTS). The tail holds the MS2Ptr<ASInteractiveObject> COMDATs of FUN_1422c7630 (ctor(int) 0x1422c8250,
// dtor 0x1422c8270, Release 0x1422c8300, ReleaseImpl 0x1422c8340, Reference 0x1422c82e0; ms2ptr_impl.h) and the
// AScript::FUN_1422c81c0<AScript> child binder.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asevent.h"
#include "ms2/placeholder/asfunction.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

// The tooltip registry of a movie (aseffect.cpp, uiobject.cpp declare the same).
void FUN_1422c6380(Scaleform::GFx::Value& value, int nGroup);   // register
void FUN_1422c63f0(Scaleform::GFx::Value& value, int nGroup);   // unregister

// @0x1422c70b0
ASUIComponent::ASUIComponent(int nMovieId)
    : ASMovieClip(nMovieId)
{
    m_bTooltip = false;
}

// @0x1422c7100
ASUIComponent::ASUIComponent(const Scaleform::GFx::Value& v, int nMovieId)
    : ASMovieClip(v, nMovieId)
{
    m_bTooltip = false;
}

// @0x1422c7170
ASUIComponent::ASUIComponent(CString strName, int nMovieId)
    : ASMovieClip(strName, nMovieId)
{
    m_bTooltip = false;
}

// @0x1422c7200
ASUIComponent::~ASUIComponent()
{
}

// @0x1422c7230
void ASUIComponent::vfunc_4(bool b)
{
    ASDisplayObject::vfunc_4(b);
}
MS2_REPLACE_METHOD(0x1422C7230, ASUIComponent, vfunc_4, 33, 0x364BDDF8);

// @0x1422c7260
void ASUIComponent::vfunc_3(int nVisible)
{
    ASDisplayObject::vfunc_3(nVisible);
}
MS2_REPLACE_METHOD(0x1422C7260, ASUIComponent, vfunc_3, 32, 0xB50F12CC);

// @0x1422c7290
void ASUIComponent::FUN_1422c7290(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser)
{
    FUN_1422c3600("show", cb, false, 0, 0, (void*)nUser);
}
MS2_REPLACE_METHOD(0x1422C7290, ASUIComponent, FUN_1422c7290, 113, 0x35FD9F7A);

// @0x1422c7310
void ASUIComponent::FUN_1422c7310(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser)
{
    FUN_1422c3600("hide", cb, false, 0, 0, (void*)nUser);
}
MS2_REPLACE_METHOD(0x1422C7310, ASUIComponent, FUN_1422c7310, 113, 0x796AAD8B);

// @0x1422c7390
void ASUIComponent::FUN_1422c7390(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser)
{
    FUN_1422c3600("keyFocusChange", cb, false, 0, 0, (void*)nUser);
}
MS2_REPLACE_METHOD(0x1422C7390, ASUIComponent, FUN_1422c7390, 113, 0x35C702F8);

// @0x1422c7410
void ASUIComponent::FUN_1422c7410(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser)
{
    FUN_1422c3600("dragStart", cb, false, 0, 0, (void*)nUser);
}
MS2_REPLACE_METHOD(0x1422C7410, ASUIComponent, FUN_1422c7410, 113, 0x4EA7E277);

// @0x1422c7490
void ASUIComponent::FUN_1422c7490(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser)
{
    FUN_1422c3600("dragEnd", cb, false, 0, 0, (void*)nUser);
}
MS2_REPLACE_METHOD(0x1422C7490, ASUIComponent, FUN_1422c7490, 113, 0xE2959106);

// @0x1422c7510
void ASUIComponent::FUN_1422c7510(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("keyFocusChange", cb, false);
}
MS2_REPLACE_METHOD(0x1422C7510, ASUIComponent, FUN_1422c7510, 82, 0x12881C1F);

// @0x1422c7570
void ASUIComponent::FUN_1422c7570(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("dragStart", cb, false);
}
MS2_REPLACE_METHOD(0x1422C7570, ASUIComponent, FUN_1422c7570, 82, 0xF16D9061);

// @0x1422c75d0
void ASUIComponent::FUN_1422c75d0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    FUN_1422c3820("dragEnd", cb, false);
}
MS2_REPLACE_METHOD(0x1422C75D0, ASUIComponent, FUN_1422c75d0, 82, 0x0D0252F1);

// Sets "focused"; losing it clears the stage focus.
// @0x1422c7630
void ASUIComponent::FUN_1422c7630(int n)
{
    FUN_1407cb9c0("focused", n);
    if (n == 0)
        vfunc_5()->FUN_1422cfd30(MS2Ptr<ASInteractiveObject>(0));
}
MS2_REPLACE_METHOD(0x1422C7630, ASUIComponent, FUN_1422c7630, 123, 0xE5086F1E);

// @0x1422c76c0
int ASUIComponent::FUN_1422c76c0()
{
    return (int)FUN_1422baa20("focused").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C76C0, ASUIComponent, FUN_1422c76c0, 92, 0x2D3460C1);

// @0x1422c7730
void ASUIComponent::FUN_1422c7730(int n)
{
    FUN_1407cb9c0("displayFocus", n);
}
MS2_REPLACE_METHOD(0x1422C7730, ASUIComponent, FUN_1422c7730, 40, 0x151993AE);

// @0x1422c7760
int ASUIComponent::FUN_1422c7760()
{
    return FUN_1422baa20("displayFocus").GetBool();
}
MS2_REPLACE_METHOD(0x1422C7760, ASUIComponent, FUN_1422c7760, 91, 0xA1A5AEFB);

// @0x1422c77d0
int ASUIComponent::FUN_1422c77d0()
{
    return FUN_1422baa20("hasFocus").GetBool();
}
MS2_REPLACE_METHOD(0x1422C77D0, ASUIComponent, FUN_1422c77d0, 91, 0xE469DD7D);

// @0x1422c7840
void ASUIComponent::FUN_1422c7840(int n)
{
    FUN_1407cbbe0("focusable", n != 0);
}
MS2_REPLACE_METHOD(0x1422C7840, ASUIComponent, FUN_1422c7840, 60, 0xEF61A8B5);

// @0x1422c7890
int ASUIComponent::FUN_1422c7890()
{
    return FUN_1422baa20("focusable").GetBool();
}
MS2_REPLACE_METHOD(0x1422C7890, ASUIComponent, FUN_1422c7890, 91, 0xB39B1ABD);

// @0x1422c7900
int ASUIComponent::FUN_1422c7900()
{
    return (int)FUN_1422baa20("actualWidth").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C7900, ASUIComponent, FUN_1422c7900, 92, 0x7ECAFA1E);

// @0x1422c7970
int ASUIComponent::FUN_1422c7970()
{
    return (int)FUN_1422baa20("actualHeight").GetNumber();
}
MS2_REPLACE_METHOD(0x1422C7970, ASUIComponent, FUN_1422c7970, 92, 0x2DD6524E);

// @0x1422c79e0
void ASUIComponent::FUN_1422c79e0(int nWidth, int nHeight)
{
    FUN_1409ba0d0("setSize", nWidth, nHeight);
}
MS2_REPLACE_METHOD(0x1422C79E0, ASUIComponent, FUN_1422c79e0, 68, 0x81E3E8B6);

// @0x1422c7a30
void ASUIComponent::FUN_1422c7a30(float fWidth, float fHeight)
{
    FUN_140e5bf20("setSize", fWidth, fHeight);
}
MS2_REPLACE_METHOD(0x1422C7A30, ASUIComponent, FUN_1422c7a30, 76, 0x01AC4974);

// @0x1422c7a90
void ASUIComponent::FUN_1422c7a90(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> callback, long long n)
{
    Invoke("setGetTooltipFunction", ASFunction(callback, n, m_nMovieId));
    FUN_1422c7e20();
}
MS2_REPLACE_METHOD(0x1422C7A90, ASUIComponent, FUN_1422c7a90, 159, 0x6F761336);

// Sets the tooltip text: into the existing "_tooltipData" object, or a new { id: text } object as "tooltipData".
// @0x1422c7b40
bool ASUIComponent::FUN_1422c7b40(CStringW strTooltip)
{
    Scaleform::GFx::Value v = FUN_1422baa20("_tooltipData");
    AScript data(v, 2);
    if (!data.FUN_1422ba9a0()) {
        data.FUN_1407cbb20("text", strTooltip);
    } else {
        AScript obj(2);
        obj.FUN_1407cbb20("id", strTooltip);
        FUN_1418adf60("tooltipData", obj);
    }
    FUN_1422c7e20();
    return true;
}
MS2_REPLACE_METHOD(0x1422C7B40, ASUIComponent, FUN_1422c7b40, 384, 0xE2473B4A);

// @0x1422c7cd0
void ASUIComponent::FUN_1422c7cd0(const Scaleform::GFx::Value& data)
{
    FUN_1409adbe0("_tooltipData", data);
    FUN_1422c7e20();
}
MS2_REPLACE_METHOD(0x1422C7CD0, ASUIComponent, FUN_1422c7cd0, 81, 0x8BF93F08);

// @0x1422c7d30
void ASUIComponent::FUN_1422c7d30(int nX, int nY)
{
    MS2Ptr<AScript> spData;
    if (FUN_1422c81c0<AScript>("_tooltipData", spData).get()) {
        spData->FUN_1407cb9c0("offsetX", nX);
        spData->FUN_1407cb9c0("offsetY", nY);
    }
}
MS2_REPLACE_METHOD(0x1422C7D30, ASUIComponent, FUN_1422c7d30, 227, 0x5E5C7A24);

// @0x1422c7e20
void ASUIComponent::FUN_1422c7e20()
{
    if (m_bTooltip)
        return;
    FUN_1422c6380(FUN_1422bb870(), m_nMovieId);
    m_bTooltip = true;
}
MS2_REPLACE_METHOD(0x1422C7E20, ASUIComponent, FUN_1422c7e20, 70, 0x2823471B);

// @0x1422c7e70
void ASUIComponent::FUN_1422c7e70()
{
    if (!m_bTooltip)
        return;
    FUN_1422c63f0(FUN_1422bb870(), m_nMovieId);
    m_bTooltip = false;
}
MS2_REPLACE_METHOD(0x1422C7E70, ASUIComponent, FUN_1422c7e70, 70, 0x107B6062);

// @0x1422c7ec0
void ASUIComponent::vfunc_16()
{
    Invoke("invalidate");
}
MS2_REPLACE_METHOD(0x1422C7EC0, ASUIComponent, vfunc_16, 46, 0xBB1CE21C);

// @0x1422c7f00
void ASUIComponent::vfunc_17()
{
    FUN_140e262c0("invalidate", "size");
}
MS2_REPLACE_METHOD(0x1422C7F00, ASUIComponent, vfunc_17, 53, 0x48869329);

// @0x1422c7f40
void ASUIComponent::vfunc_18()
{
    FUN_140e262c0("invalidate", "data");
}
MS2_REPLACE_METHOD(0x1422C7F40, ASUIComponent, vfunc_18, 53, 0x935D28C9);

// @0x1422c7f80
void ASUIComponent::vfunc_19()
{
    FUN_140e262c0("invalidate", "state");
}
MS2_REPLACE_METHOD(0x1422C7F80, ASUIComponent, vfunc_19, 53, 0xAF733509);

// @0x1422c7fc0
void ASUIComponent::vfunc_20()
{
    FUN_140e262c0("invalidate", "settings");
}
MS2_REPLACE_METHOD(0x1422C7FC0, ASUIComponent, vfunc_20, 53, 0x2E4E7712);

// @0x1422c8000
void ASUIComponent::vfunc_21()
{
    FUN_140e262c0("invalidate", "renderers");
}
MS2_REPLACE_METHOD(0x1422C8000, ASUIComponent, vfunc_21, 53, 0x5C0912B1);

// @0x1422c8040
void ASUIComponent::vfunc_22()
{
    FUN_140e262c0("invalidate", "scrollBar");
}
MS2_REPLACE_METHOD(0x1422C8040, ASUIComponent, vfunc_22, 53, 0x0DE5E031);

// @0x1422c8080
void ASUIComponent::vfunc_23()
{
    FUN_140e262c0("invalidate", "selectedIndex");
}
MS2_REPLACE_METHOD(0x1422C8080, ASUIComponent, vfunc_23, 53, 0xAE4FA331);

// @0x1422c80c0
void ASUIComponent::vfunc_24(bool bInvalidate)
{
    if (bInvalidate)
        vfunc_16();
    Invoke("validateNow");
}
MS2_REPLACE_METHOD(0x1422C80C0, ASUIComponent, vfunc_24, 78, 0x80075263);

// @0x1422c8120
void ASUIComponent::FUN_1422c8120(bool bShow)
{
    ASEvent ev(bShow ? "show" : "hide", false, false, 2);
    FUN_1422c3d30(ev);
}
MS2_REPLACE_METHOD(0x1422C8120, ASUIComponent, FUN_1422c8120, 158, 0x7246766E);

// @0x1422c81c0
template <class T> MS2Ptr<T> AScript::FUN_1422c81c0(const CString& strName, MS2Ptr<T>& out)
{
    out = FUN_141311f50<T>(strName);
    return out;
}

// MS2-PIN: ??_GASUIComponent@@UEAAPEAXI@Z 0x1422c82a0
