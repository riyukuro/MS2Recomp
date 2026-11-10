// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASInteractiveObject, the ActionScript InteractiveObject
// wrapper of the GFx UI library.
// MS2-UNIT: ?\asinteractiveobject.cpp
// MS2-RANGE: 0x1422de680-0x1422deec0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asdisplayobject.h. The int accessors read and write the AS member as a
// Boolean, "tabIndex" included (that is what the exe does).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdisplayobject.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

// @0x1422de680
ASInteractiveObject::ASInteractiveObject(const Scaleform::GFx::Value& v, int nMovieId)
    : ASDisplayObject(v, nMovieId)
{
}

// @0x1422de6d0
ASInteractiveObject::~ASInteractiveObject()
{
}

// @0x1422de700
void ASInteractiveObject::AddFocusInListener(const ASCallback& cb, bool bCapture, void* pUser)
{
    AddEventListener("focusIn", cb, bCapture, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE700, ASInteractiveObject, AddFocusInListener, 121, 0x8AFFA4E0);

// @0x1422de780
void ASInteractiveObject::AddFocusOutListener(const ASCallback& cb, bool bCapture, void* pUser)
{
    AddEventListener("focusOut", cb, bCapture, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE780, ASInteractiveObject, AddFocusOutListener, 121, 0xE95A519F);

// @0x1422de800
void ASInteractiveObject::AddRollOverListener(const ASCallback& cb, bool bCapture, void* pUser)
{
    AddEventListener("rollOver", cb, bCapture, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE800, ASInteractiveObject, AddRollOverListener, 121, 0x66E4CDCA);

// @0x1422de880
void ASInteractiveObject::AddRollOutListener(const ASCallback& cb, bool bCapture, void* pUser)
{
    AddEventListener("rollOut", cb, bCapture, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422DE880, ASInteractiveObject, AddRollOutListener, 121, 0xD1EC524B);

// @0x1422de900
void ASInteractiveObject::RemoveFocusInListener(const ASCallback& cb, bool bCapture)
{
    RemoveEventListener("focusIn", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE900, ASInteractiveObject, RemoveFocusInListener, 87, 0x0C962461);

// @0x1422de960
void ASInteractiveObject::RemoveFocusOutListener(const ASCallback& cb, bool bCapture)
{
    RemoveEventListener("focusOut", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE960, ASInteractiveObject, RemoveFocusOutListener, 87, 0xA11C4379);

// @0x1422de9c0
void ASInteractiveObject::RemoveRollOverListener(const ASCallback& cb, bool bCapture)
{
    RemoveEventListener("rollOver", cb, false);
}
MS2_REPLACE_METHOD(0x1422DE9C0, ASInteractiveObject, RemoveRollOverListener, 87, 0xAC470DC2);

// @0x1422dea20
void ASInteractiveObject::RemoveRollOutListener(const ASCallback& cb, bool bCapture)
{
    RemoveEventListener("rollOut", cb, false);
}
MS2_REPLACE_METHOD(0x1422DEA20, ASInteractiveObject, RemoveRollOutListener, 87, 0x45FD8B07);

// @0x1422dea80
void ASInteractiveObject::SetDoubleClickEnabled(int bEnabled)
{
    SetBoolMember("doubleClickEnabled", bEnabled != 0);
}
MS2_REPLACE_METHOD(0x1422DEA80, ASInteractiveObject, SetDoubleClickEnabled, 60, 0x5D5E07E2);

// @0x1422dead0
int ASInteractiveObject::IsDoubleClickEnabled()
{
    return GetMember("doubleClickEnabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422DEAD0, ASInteractiveObject, IsDoubleClickEnabled, 91, 0x551D001D);

// @0x1422deb40
void ASInteractiveObject::SetMouseEnabled(bool bEnabled)
{
    SetBoolMember("mouseEnabled", bEnabled);
}
MS2_REPLACE_METHOD(0x1422DEB40, ASInteractiveObject, SetMouseEnabled, 41, 0xFE36E9A0);

// @0x1422deb70
int ASInteractiveObject::IsMouseEnabled()
{
    return GetMember("mouseEnabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422DEB70, ASInteractiveObject, IsMouseEnabled, 91, 0x53E74FF2);

// @0x1422debe0
void ASInteractiveObject::SetNeedsSoftKeyboard(int bNeeds)
{
    SetBoolMember("needsSoftKeyboard", bNeeds != 0);
}
MS2_REPLACE_METHOD(0x1422DEBE0, ASInteractiveObject, SetNeedsSoftKeyboard, 60, 0x7C5BC531);

// @0x1422dec30
int ASInteractiveObject::FUN_1422dec30()
{
    return GetMember("needsSoftKeyboard").GetBool();
}
MS2_REPLACE_METHOD(0x1422DEC30, ASInteractiveObject, FUN_1422dec30, 91, 0x5DAA17D5);

// @0x1422deca0
void ASInteractiveObject::SetTabEnabled(int bEnabled)
{
    SetBoolMember("tabEnabled", bEnabled != 0);
}
MS2_REPLACE_METHOD(0x1422DECA0, ASInteractiveObject, SetTabEnabled, 60, 0x3666EBD2);

// @0x1422decf0
int ASInteractiveObject::IsTabEnabled()
{
    return GetMember("tabEnabled").GetBool();
}
MS2_REPLACE_METHOD(0x1422DECF0, ASInteractiveObject, IsTabEnabled, 91, 0xB02EB8D8);

// @0x1422ded60
void ASInteractiveObject::SetTabIndex(int nIndex)
{
    SetBoolMember("tabIndex", nIndex != 0);
}
MS2_REPLACE_METHOD(0x1422DED60, ASInteractiveObject, SetTabIndex, 60, 0x8022D047);

// @0x1422dedb0
int ASInteractiveObject::GetTabIndex()
{
    return GetMember("tabIndex").GetBool();
}
MS2_REPLACE_METHOD(0x1422DEDB0, ASInteractiveObject, GetTabIndex, 91, 0x22BEF5AE);

// @0x1422dee20
int ASInteractiveObject::RequestSoftKeyboard()
{
    return Invoke("requestSoftKeyboard").GetBool();
}
MS2_REPLACE_METHOD(0x1422DEE20, ASInteractiveObject, RequestSoftKeyboard, 91, 0xAA1BFFE6);

// MS2-PIN: ??_GASInteractiveObject@@UEAAPEAXI@Z 0x1422dee80
