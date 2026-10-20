// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIChangeJobEffect: see uichangejobeffect.h.
// MS2-UNIT: ?\uichangejobeffect.cpp
// MS2-RANGE: 0x140bd09e0-0x140bd0e90 .text$mn
// MS2-RANGE: 0x1400ca530-0x1400ca6a0 .text$di
// MS2-PIN: ??_GUIChangeJobEffect@@UEAAPEAXI@Z 0x140bd0e40
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uichangejobeffect.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uichangejobeffect.h"

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_CjStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_CjStrings* FUN_1401a9d70();
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);   // a localised key formatted with one argument

class Unk_CjPC { public: int FUN_141654730(); };                  // job code
class Unk_CjWorld { public: Unk_CjPC* FUN_141bd0cc0(); };         // the local player
Unk_CjWorld* FUN_1403ed2d0();

void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released

// FUN_140bd0bb0 is a free function, so it reaches the dialog's AS pointer (UISwfEntity::m_30 at +0x30) through this
// layout view.
struct Unk_CjAS { char m_pad_00[0x30]; MS2Ptr<AScript> m_30; };

// @0x140bd09e0
UIChangeJobEffect::UIChangeJobEffect()
{
}

// @0x140bd0a50
UIChangeJobEffect::~UIChangeJobEffect()
{
}

// @0x140bd0ab0
CString UIChangeJobEffect::vfunc_1()
{
    return "ChangeJobEffect";
}
MS2_REPLACE_METHOD(0x140BD0AB0, UIChangeJobEffect, vfunc_1, 61, 0x30B69F4A);

// @0x140bd0b00
void UIChangeJobEffect::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_140bd0bb0(this);
}
MS2_REPLACE_METHOD(0x140BD0B00, UIChangeJobEffect, OnLoadComplete, 34, 0x62BCD511);

// @0x140bd0b30
int UIChangeJobEffect::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onHide", szMethod) == 0)
    {
        vfunc_3();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140BD0B30, UIChangeJobEffect, vfunc_28, 111, 0x578A6BDE);

// @0x140bd0bb0
void FUN_140bd0bb0(UIChangeJobEffect* pEffect)
{
    if (FUN_140ba28d0(&((Unk_CjAS*)pEffect)->m_30, 0))
        return;
    Unk_CjPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    int nJob = pPc->FUN_141654730();
    CStringW strText = FUN_1405c2690(CStringW(L"s_changejob_effect_text"), FUN_1401a9d70()->FUN_141811980(6, nJob));
    ASObj obj(2);
    obj.FUN_140bd0d90("jobCode", nJob);
    obj.FUN_1407cbb20("text", CStringW(strText));
    ((Unk_CjAS*)pEffect)->m_30->Invoke("setData", obj.FUN_1422bb870());
}
MS2_REPLACE(0x140BD0BB0, FUN_140bd0bb0, 474, 0x84C58FA1);

// @0x140bd0d90
void ASObj::FUN_140bd0d90(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}
MS2_REPLACE_METHOD(0x140BD0D90, ASObj, FUN_140bd0d90, 152, 0x1CED670B);

// @0x140bd0e80
int UIChangeJobEffect::vfunc_48()
{
    return 0x4f6c;
}
MS2_REPLACE_METHOD(0x140BD0E80, UIChangeJobEffect, vfunc_48, 11, 0x321E533C);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca19c0-0x142ca1a50 .text$yd
