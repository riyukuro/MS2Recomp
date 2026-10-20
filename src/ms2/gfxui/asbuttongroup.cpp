// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASButtonGroup, the CLIK ButtonGroup wrapper of the GFx UI library.
// MS2-UNIT: ?\asbuttongroup.cpp
// MS2-RANGE: 0x1422e8920-0x1422e92e0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/asbuttongroup.h (shared; Ghidra's FUN_<va> names are kept there). The obj's
// COMDAT tail is the AScript::Invoke(method, CStringW, Value) instance 0x1422e9170 and the scalar deleting dtor.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asbuttongroup.h"
#include "ms2/placeholder/asdata.h"

#include "hook/ms2hook.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ASCallback;

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)
// The typed Value setters of the Invoke argument lists (COMDATs of ASArray's obj).
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);

// @0x1422e8920
ASButtonGroup::ASButtonGroup(const Scaleform::GFx::Value& v, int nMovieId)
    : ASEventDispatcher(v, nMovieId)
{
}

// @0x1422e8970
ASButtonGroup::~ASButtonGroup()
{
}

// @0x1422e89a0
unsigned int ASButtonGroup::FUN_1422e89a0()
{
    return FUN_1422baa20("length").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E89A0, ASButtonGroup, FUN_1422e89a0, 88, 0x83EDF72E);

// @0x1422e8a00
int ASButtonGroup::FUN_1422e8a00()
{
    return FUN_1422baa20("selectedIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E8A00, ASButtonGroup, FUN_1422e8a00, 88, 0x3C039DF8);

// Not hooked (8a60 / 8b20 / 8d60): the MS2Ptr argument is destroyed by the callee.
// @0x1422e8a60
void ASButtonGroup::FUN_1422e8a60(MS2Ptr<ASButton> spButton)
{
    if (spButton == 0)
        return;
    Invoke("addButton", spButton->FUN_1422bb870());
}

// @0x1422e8b20
void ASButtonGroup::FUN_1422e8b20(MS2Ptr<ASButton> spButton)
{
    if (spButton == 0)
        return;
    Invoke("removeButton", spButton->FUN_1422bb870());
}

// @0x1422e8be0
MS2Ptr<ASButton> ASButtonGroup::FUN_1422e8be0(int nIndex)
{
    Scaleform::GFx::Value v = Invoke("getButtonAt", nIndex);
    MS2Ptr<ASButton> spButton(new ASButton(v, FUN_14198f250()));
    return spButton;
}
MS2_REPLACE_METHOD(0x1422E8BE0, ASButtonGroup, FUN_1422e8be0, 235, 0x8CBC7520);

// @0x1422e8ce0
bool ASButtonGroup::FUN_1422e8ce0(int nIndex, bool bForce)
{
    return FUN_140ed0fd0("setSelectedButtonByIndex", nIndex, bForce).GetBool();
}
MS2_REPLACE_METHOD(0x1422E8CE0, ASButtonGroup, FUN_1422e8ce0, 121, 0x5A61716E);

// @0x1422e8d60
bool ASButtonGroup::FUN_1422e8d60(MS2Ptr<ASButton> spButton)
{
    if (spButton == 0)
        return false;
    return Invoke("hasButton", spButton->FUN_1422bb870()).GetBool();
}

// @0x1422e8e50
void ASButtonGroup::FUN_1422e8e50(const ASCallback& onClick, void* pUser)
{
    FUN_1422c3600("buttonClick", onClick, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422E8E50, ASButtonGroup, FUN_1422e8e50, 113, 0x873FD8B5);

// @0x1422e8ed0
void ASButtonGroup::FUN_1422e8ed0(const ASCallback& onChange, void* pUser)
{
    FUN_1422c3600("change", onChange, false, 0, 0, pUser);
}
MS2_REPLACE_METHOD(0x1422E8ED0, ASButtonGroup, FUN_1422e8ed0, 113, 0xD945B477);

// @0x1422e8f50
MS2Ptr<ASButtonGroup> ASButtonGroup::FUN_1422e8f50(const CStringW& strName, AScript* pScope)
{
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(pScope->FUN_14198f250());
    if (pMovie == 0)
        return MS2Ptr<ASButtonGroup>(0);
    int nMovieId = pScope->FUN_14198f250();
    Scaleform::GFx::Value vClass;
    pMovie->CreateObject(&vClass, "scaleform.clik.controls.ButtonGroup");
    AScript groupClass(vClass, nMovieId);
    Scaleform::GFx::Value vGroup = groupClass.FUN_1422e9170("getGroup", strName, pScope->FUN_1422bb870());
    MS2Ptr<ASButtonGroup> spGroup(new ASButtonGroup(vGroup, nMovieId));
    return spGroup;
}
MS2_REPLACE(0x1422E8F50, ASButtonGroup::FUN_1422e8f50, 537, 0xD17CD89C);

// @0x1422e9170
Scaleform::GFx::Value AScript::FUN_1422e9170(const char* szMethod, CStringW a1, Scaleform::GFx::Value a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcea0(args.FUN_1409b1f70(0), (const wchar_t*)a1);
    FUN_1422bcc70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GASButtonGroup@@UEAAPEAXI@Z 0x1422e92a0
