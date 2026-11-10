// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASDisplayObjectContainer, the wrapper of an AS
// DisplayObjectContainer (child list access).
// MS2-UNIT: ?\asdisplayobjectcontainer.cpp
// MS2-RANGE: 0x1422c6570-0x1422c70b0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Unit
// boundaries: the ctor 0x1422c6570 follows ASTooltipManager's COMDAT tail; ASUIComponent's ctor starts the next obj at
// 0x1422c70b0. The obj's COMDAT tail: the Invoke(const char*, Value, float) instance 0x1422c6f70 and the scalar deleting
// dtor 0x1422c7070. The class is declared in src/ms2/placeholder/asdisplayobject.h.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

// The typed Value setters of the Invoke argument lists (COMDATs of ASArray's obj).
void SetValue(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);

// @0x1422c6570
ASDisplayObjectContainer::ASDisplayObjectContainer(const Scaleform::GFx::Value& v, int nMovieId)
    : ASInteractiveObject(v, nMovieId)
{
}

// @0x1422c65c0
ASDisplayObjectContainer::~ASDisplayObjectContainer()
{
}

// @0x1422c65f0
void ASDisplayObjectContainer::SetTabChildren(int bTab)
{
    SetBoolMember("tabChildren", bTab != 0);
}
MS2_REPLACE_METHOD(0x1422C65F0, ASDisplayObjectContainer, SetTabChildren, 60, 0x661F6825);

// @0x1422c6640
void ASDisplayObjectContainer::SetMouseChildren(bool b)
{
    SetBoolMember("mouseChildren", b);
}
MS2_REPLACE_METHOD(0x1422C6640, ASDisplayObjectContainer, SetMouseChildren, 41, 0xFFB9C06B);

// @0x1422c6670
int ASDisplayObjectContainer::GetNumChildren()
{
    return GetMember("numChildren").GetInt();
}
MS2_REPLACE_METHOD(0x1422C6670, ASDisplayObjectContainer, GetNumChildren, 88, 0x078F0851);

// @0x1422c66d0
int ASDisplayObjectContainer::GetTabChildren()
{
    return GetMember("tabChildren").GetBool();
}
MS2_REPLACE_METHOD(0x1422C66D0, ASDisplayObjectContainer, GetTabChildren, 91, 0x70563FC4);

// @0x1422c6740
int ASDisplayObjectContainer::GetMouseChildren()
{
    return GetMember("mouseChildren").GetBool();
}
MS2_REPLACE_METHOD(0x1422C6740, ASDisplayObjectContainer, GetMouseChildren, 91, 0x1139B52F);

// @0x1422c67b0
int ASDisplayObjectContainer::GetChildIndex(MS2Ptr<ASDisplayObject> spChild)
{
    return Invoke("getChildIndex", spChild->GetValue()).GetUInt();
}

// @0x1422c6860
int ASDisplayObjectContainer::Contains(const Scaleform::GFx::Value& child)
{
    return Invoke("contains", child).GetBool();
}
MS2_REPLACE_METHOD(0x1422C6860, ASDisplayObjectContainer, Contains, 143, 0x197D5FA0);

// @0x1422c6900
Scaleform::GFx::Value ASDisplayObjectContainer::AddChild(Scaleform::GFx::Value child)
{
    Invoke("addChild", child);
    return child;
}

// @0x1422c69c0
Scaleform::GFx::Value ASDisplayObjectContainer::AddChildAt(Scaleform::GFx::Value child, int nIndex)
{
    FUN_1422c6f70("addChildAt", child, (float)nIndex);
    return child;
}

// @0x1422c6aa0
Scaleform::GFx::Value ASDisplayObjectContainer::GetChildAt(int nIndex)
{
    return Invoke("getChildAt", nIndex);
}
MS2_REPLACE_METHOD(0x1422C6AA0, ASDisplayObjectContainer, GetChildAt, 75, 0x000D3658);

// @0x1422c6b00
Scaleform::GFx::Value ASDisplayObjectContainer::GetChildByName(const CString& strName)
{
    return Invoke("getChildByName", strName);
}
MS2_REPLACE_METHOD(0x1422C6B00, ASDisplayObjectContainer, GetChildByName, 106, 0x07634845);

// @0x1422c6b70
Scaleform::GFx::Value ASDisplayObjectContainer::RemoveChild(Scaleform::GFx::Value child)
{
    return Invoke("removeChild", child);
}

// @0x1422c6c00
Scaleform::GFx::Value ASDisplayObjectContainer::RemoveChildAt(int nIndex)
{
    return Invoke("removeChildAt", nIndex);
}
MS2_REPLACE_METHOD(0x1422C6C00, ASDisplayObjectContainer, RemoveChildAt, 75, 0x04E81819);

// @0x1422c6c60
Scaleform::GFx::Value ASDisplayObjectContainer::GetParent()
{
    return GetMember("parent");
}
MS2_REPLACE_METHOD(0x1422C6C60, ASDisplayObjectContainer, GetParent, 65, 0x592F520F);

// @0x1422c6cb0
void ASDisplayObjectContainer::SetChildIndex(MS2Ptr<ASDisplayObject> spChild, int nIndex)
{
    FUN_1422c6f70("setChildIndex", spChild->GetValue(), (float)nIndex);
}

// @0x1422c6d60
void ASDisplayObjectContainer::SwapChildren(MS2Ptr<ASDisplayObject> spChild1, MS2Ptr<ASDisplayObject> spChild2)
{
    Invoke("swapChildren", spChild1->GetValue(), spChild2->GetValue());
}

// @0x1422c6e50
void ASDisplayObjectContainer::SwapChildrenAt(int nIndex1, int nIndex2)
{
    FUN_140e5bf20("swapChildrenAt", (float)nIndex1, (float)nIndex2);
}
MS2_REPLACE_METHOD(0x1422C6E50, ASDisplayObjectContainer, SwapChildrenAt, 76, 0x9EA4565D);

// @0x1422c6eb0
void ASDisplayObjectContainer::RemoveFromParent()
{
    Scaleform::GFx::Value parent = GetParent();
    if (parent.IsObject()) {
        ASDisplayObjectContainer container(parent, 2);
        container.RemoveChild(m_value);
    }
}
MS2_REPLACE_METHOD(0x1422C6EB0, ASDisplayObjectContainer, RemoveFromParent, 188, 0x95ED2739);

// @0x1422c6f70
inline Scaleform::GFx::Value AScript::FUN_1422c6f70(const char* szMethod, Scaleform::GFx::Value a1, float a2)
{
    ASArgList args;
    args.resize(2);
    SetValue(&args[0], a1);
    FUN_1422bcd70(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GASDisplayObjectContainer@@UEAAPEAXI@Z 0x1422c7070
