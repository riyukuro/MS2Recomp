// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASEvent / ASTextEvent / ASListEvent / ASIndexEvent, the
// ActionScript event wrappers of the GFx UI library.
// MS2-UNIT: ?\asevent.cpp
// MS2-RANGE: 0x1422e2080-0x1422e2cd0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// classes are declared in src/ms2/placeholder/asevent.h. The obj's tail is ~ASTextEvent and the scalar deleting dtors.
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>   // C3: std::vector<GFx::Value>::size (the ASArgList)
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asevent.h"

#include "hook/ms2hook.h"

Scaleform::GFx::Movie* GetMovie(int nMovieId);            // the GFx movie of a movie id (null if not loaded)
void SetString(Scaleform::GFx::Value* pValue, const char* sz);  // set a string Value (a COMDAT of ASArray's obj)
void SetBoolean(Scaleform::GFx::Value* pValue, bool b);          // set a bool Value (a COMDAT of ASArray's obj)

// @0x1422e2080
ASEvent::ASEvent(const CString& strType, bool bBubbles, bool bCancelable, int nMovieId)
    : AScript(nMovieId)
{
    m_value.SetNull();
    Scaleform::GFx::Movie* pMovie = GetMovie(m_nMovieId);
    if (pMovie) {
        ASArgList args;
        args.resize(3);
        SetString(&args[0], strType);
        SetBoolean(&args[1], bBubbles);
        SetBoolean(&args[2], bCancelable);
        pMovie->CreateObject(&m_value, "flash.events.Event", &args[0], (unsigned)reinterpret_cast<const std::vector<Scaleform::GFx::Value>&>(args).size());
    }
}

// @0x1422e21f0
ASEvent::ASEvent(const Scaleform::GFx::Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
}

// @0x1422e2240
ASEvent::ASEvent(const Scaleform::GFx::FunctionHandler::Params& params)
    : AScript(params.pArgs[0], 2)
{
}

// @0x1422e22a0
ASEvent::~ASEvent()
{
}

// @0x1422e22d0
CString ASEvent::GetType()
{
    return GetMember("type").GetString();
}
MS2_REPLACE_METHOD(0x1422E22D0, ASEvent, GetType, 123, 0xD03CD1C3);

// @0x1422e2360
Scaleform::GFx::Value ASEvent::GetTarget()
{
    return GetMember("target");
}
MS2_REPLACE_METHOD(0x1422E2360, ASEvent, GetTarget, 65, 0xFD6E1D87);

// @0x1422e23b0
Scaleform::GFx::Value ASEvent::GetCurrentTarget()
{
    return GetMember("currentTarget");
}
MS2_REPLACE_METHOD(0x1422E23B0, ASEvent, GetCurrentTarget, 65, 0x80EFB99B);

// @0x1422e2400
bool ASEvent::IsCancelable()
{
    return GetMember("cancelable").GetBool();
}
MS2_REPLACE_METHOD(0x1422E2400, ASEvent, IsCancelable, 89, 0x78D18A51);

// @0x1422e2460
bool ASEvent::IsBubbles()
{
    return GetMember("bubbles").GetBool();
}
MS2_REPLACE_METHOD(0x1422E2460, ASEvent, IsBubbles, 89, 0x3C076FA1);

// @0x1422e24c0
bool ASEvent::IsDefaultPrevented()
{
    return Invoke("isDefaultPrevented").GetBool();
}
MS2_REPLACE_METHOD(0x1422E24C0, ASEvent, IsDefaultPrevented, 89, 0x2A34440D);

// @0x1422e2520
void ASEvent::PreventDefault()
{
    Invoke("preventDefault");
}
MS2_REPLACE_METHOD(0x1422E2520, ASEvent, PreventDefault, 46, 0x7DA5633D);

// @0x1422e2560
void ASEvent::StopImmediatePropagation()
{
    Invoke("stopImmediatePropagation");
}
MS2_REPLACE_METHOD(0x1422E2560, ASEvent, StopImmediatePropagation, 46, 0x2FD73F48);

// @0x1422e25a0
void ASEvent::StopPropagation()
{
    Invoke("stopPropagation");
}
MS2_REPLACE_METHOD(0x1422E25A0, ASEvent, StopPropagation, 46, 0xA9752B28);

// @0x1422e25e0
CString ASEvent::ToString()
{
    return Invoke("toString").GetString();
}
MS2_REPLACE_METHOD(0x1422E25E0, ASEvent, ToString, 123, 0xB347F1C8);

// @0x1422e2670
ASTextEvent::ASTextEvent(const Scaleform::GFx::FunctionHandler::Params& params)
    : ASEvent(params)
{
}

// @0x1422e26b0
CString ASTextEvent::GetText()
{
    return GetMember("text").GetString();
}
MS2_REPLACE_METHOD(0x1422E26B0, ASTextEvent, GetText, 123, 0x34214D81);

// @0x1422e2740
ASListEvent::ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params)
    : ASEvent(params)
{
}

// @0x1422e2780
Scaleform::GFx::Value ASListEvent::GetItemData()
{
    return GetMember("itemData");
}
MS2_REPLACE_METHOD(0x1422E2780, ASListEvent, GetItemData, 65, 0xF6706C33);

// @0x1422e27d0
Scaleform::GFx::Value ASListEvent::GetItemRenderer()
{
    return GetMember("itemRenderer");
}
MS2_REPLACE_METHOD(0x1422E27D0, ASListEvent, GetItemRenderer, 65, 0x3FA32223);

// @0x1422e2820
int ASListEvent::GetIndex()
{
    return GetMember("index").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2820, ASListEvent, GetIndex, 88, 0xBE89DDE7);

// @0x1422e2880
int ASListEvent::GetColumnIndex()
{
    return GetMember("columnIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2880, ASListEvent, GetColumnIndex, 88, 0x15100F0F);

// @0x1422e28e0
int ASListEvent::GetRowIndex()
{
    return GetMember("rowIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E28E0, ASListEvent, GetRowIndex, 88, 0x9B9A6B0F);

// @0x1422e2940
unsigned int ASListEvent::GetControllerIdx()
{
    return GetMember("controllerIdx").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E2940, ASListEvent, GetControllerIdx, 88, 0xC2BC7FAC);

// @0x1422e29a0
unsigned int ASListEvent::GetButtonIdx()
{
    return GetMember("buttonIdx").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E29A0, ASListEvent, GetButtonIdx, 88, 0x3115F9F3);

// @0x1422e2a00
bool ASListEvent::IsKeyboard()
{
    return GetMember("isKeyboard").GetBool();
}
MS2_REPLACE_METHOD(0x1422E2A00, ASListEvent, IsKeyboard, 89, 0x7948D30E);

// @0x1422e2a60
ASIndexEvent::ASIndexEvent(const Scaleform::GFx::FunctionHandler::Params& params)
    : ASEvent(params)
{
}

// @0x1422e2aa0
int ASIndexEvent::GetIndex()
{
    return GetMember("index").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2AA0, ASIndexEvent, GetIndex, 88, 0x37E2B3A3);

// @0x1422e2b00
int ASIndexEvent::GetLastIndex()
{
    return GetMember("lastIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2B00, ASIndexEvent, GetLastIndex, 88, 0x85318D48);

// @0x1422e2b60
Scaleform::GFx::Value ASIndexEvent::GetData()
{
    return GetMember("data");
}
MS2_REPLACE_METHOD(0x1422E2B60, ASIndexEvent, GetData, 65, 0x879438C6);

// MS2-PIN: ??1ASTextEvent@@UEAA@XZ 0x1422e2bb0
// MS2-PIN: ??_GASEvent@@UEAAPEAXI@Z 0x1422e2bd0
// MS2-PIN: ??_GASIndexEvent@@UEAAPEAXI@Z 0x1422e2c10
// MS2-PIN: ??_GASListEvent@@UEAAPEAXI@Z 0x1422e2c50
// MS2-PIN: ??_GASTextEvent@@UEAAPEAXI@Z 0x1422e2c90
