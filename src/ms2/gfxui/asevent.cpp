// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASEvent / ASTextEvent / ASListEvent / ASIndexEvent, the
// ActionScript event wrappers of the GFx UI library.
// MS2-UNIT: ?\asevent.cpp
// MS2-RANGE: 0x1422e2080-0x1422e2cd0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// classes are declared in src/ms2/placeholder/asevent.h. The obj's tail is ~ASTextEvent and the scalar deleting dtors.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asevent.h"

#include "hook/ms2hook.h"

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);  // set a string Value (a COMDAT of ASArray's obj)
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);          // set a bool Value (a COMDAT of ASArray's obj)

// @0x1422e2080
ASEvent::ASEvent(const CString& strType, bool bBubbles, bool bCancelable, int nMovieId)
    : AScript(nMovieId)
{
    m_value.SetNull();
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie) {
        ASArgList args;
        args.FUN_1409b2800(3);
        FUN_1422bce70(args.FUN_1409b1f70(0), strType);
        FUN_1422bcce0(args.FUN_1409b1f70(1), bBubbles);
        FUN_1422bcce0(args.FUN_1409b1f70(2), bCancelable);
        pMovie->CreateObject(&m_value, "flash.events.Event", args.FUN_1409b1f70(0), (unsigned)args.FUN_1409b2840());
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
CString ASEvent::FUN_1422e22d0()
{
    return FUN_1422baa20("type").GetString();
}
MS2_REPLACE_METHOD(0x1422E22D0, ASEvent, FUN_1422e22d0, 123, 0xD03CD1C3);

// @0x1422e2360
Scaleform::GFx::Value ASEvent::FUN_1422e2360()
{
    return FUN_1422baa20("target");
}
MS2_REPLACE_METHOD(0x1422E2360, ASEvent, FUN_1422e2360, 65, 0xFD6E1D87);

// @0x1422e23b0
Scaleform::GFx::Value ASEvent::FUN_1422e23b0()
{
    return FUN_1422baa20("currentTarget");
}
MS2_REPLACE_METHOD(0x1422E23B0, ASEvent, FUN_1422e23b0, 65, 0x80EFB99B);

// @0x1422e2400
bool ASEvent::FUN_1422e2400()
{
    return FUN_1422baa20("cancelable").GetBool();
}
MS2_REPLACE_METHOD(0x1422E2400, ASEvent, FUN_1422e2400, 89, 0x78D18A51);

// @0x1422e2460
bool ASEvent::FUN_1422e2460()
{
    return FUN_1422baa20("bubbles").GetBool();
}
MS2_REPLACE_METHOD(0x1422E2460, ASEvent, FUN_1422e2460, 89, 0x3C076FA1);

// @0x1422e24c0
bool ASEvent::FUN_1422e24c0()
{
    return Invoke("isDefaultPrevented").GetBool();
}
MS2_REPLACE_METHOD(0x1422E24C0, ASEvent, FUN_1422e24c0, 89, 0x2A34440D);

// @0x1422e2520
void ASEvent::FUN_1422e2520()
{
    Invoke("preventDefault");
}
MS2_REPLACE_METHOD(0x1422E2520, ASEvent, FUN_1422e2520, 46, 0x7DA5633D);

// @0x1422e2560
void ASEvent::FUN_1422e2560()
{
    Invoke("stopImmediatePropagation");
}
MS2_REPLACE_METHOD(0x1422E2560, ASEvent, FUN_1422e2560, 46, 0x2FD73F48);

// @0x1422e25a0
void ASEvent::FUN_1422e25a0()
{
    Invoke("stopPropagation");
}
MS2_REPLACE_METHOD(0x1422E25A0, ASEvent, FUN_1422e25a0, 46, 0xA9752B28);

// @0x1422e25e0
CString ASEvent::FUN_1422e25e0()
{
    return Invoke("toString").GetString();
}
MS2_REPLACE_METHOD(0x1422E25E0, ASEvent, FUN_1422e25e0, 123, 0xB347F1C8);

// @0x1422e2670
ASTextEvent::ASTextEvent(const Scaleform::GFx::FunctionHandler::Params& params)
    : ASEvent(params)
{
}

// @0x1422e26b0
CString ASTextEvent::FUN_1422e26b0()
{
    return FUN_1422baa20("text").GetString();
}
MS2_REPLACE_METHOD(0x1422E26B0, ASTextEvent, FUN_1422e26b0, 123, 0x34214D81);

// @0x1422e2740
ASListEvent::ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params)
    : ASEvent(params)
{
}

// @0x1422e2780
Scaleform::GFx::Value ASListEvent::FUN_1422e2780()
{
    return FUN_1422baa20("itemData");
}
MS2_REPLACE_METHOD(0x1422E2780, ASListEvent, FUN_1422e2780, 65, 0xF6706C33);

// @0x1422e27d0
Scaleform::GFx::Value ASListEvent::FUN_1422e27d0()
{
    return FUN_1422baa20("itemRenderer");
}
MS2_REPLACE_METHOD(0x1422E27D0, ASListEvent, FUN_1422e27d0, 65, 0x3FA32223);

// @0x1422e2820
int ASListEvent::FUN_1422e2820()
{
    return FUN_1422baa20("index").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2820, ASListEvent, FUN_1422e2820, 88, 0xBE89DDE7);

// @0x1422e2880
int ASListEvent::FUN_1422e2880()
{
    return FUN_1422baa20("columnIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2880, ASListEvent, FUN_1422e2880, 88, 0x15100F0F);

// @0x1422e28e0
int ASListEvent::FUN_1422e28e0()
{
    return FUN_1422baa20("rowIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E28E0, ASListEvent, FUN_1422e28e0, 88, 0x9B9A6B0F);

// @0x1422e2940
unsigned int ASListEvent::FUN_1422e2940()
{
    return FUN_1422baa20("controllerIdx").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E2940, ASListEvent, FUN_1422e2940, 88, 0xC2BC7FAC);

// @0x1422e29a0
unsigned int ASListEvent::FUN_1422e29a0()
{
    return FUN_1422baa20("buttonIdx").GetUInt();
}
MS2_REPLACE_METHOD(0x1422E29A0, ASListEvent, FUN_1422e29a0, 88, 0x3115F9F3);

// @0x1422e2a00
bool ASListEvent::FUN_1422e2a00()
{
    return FUN_1422baa20("isKeyboard").GetBool();
}
MS2_REPLACE_METHOD(0x1422E2A00, ASListEvent, FUN_1422e2a00, 89, 0x7948D30E);

// @0x1422e2a60
ASIndexEvent::ASIndexEvent(const Scaleform::GFx::FunctionHandler::Params& params)
    : ASEvent(params)
{
}

// @0x1422e2aa0
int ASIndexEvent::FUN_1422e2aa0()
{
    return FUN_1422baa20("index").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2AA0, ASIndexEvent, FUN_1422e2aa0, 88, 0x37E2B3A3);

// @0x1422e2b00
int ASIndexEvent::FUN_1422e2b00()
{
    return FUN_1422baa20("lastIndex").GetInt();
}
MS2_REPLACE_METHOD(0x1422E2B00, ASIndexEvent, FUN_1422e2b00, 88, 0x85318D48);

// @0x1422e2b60
Scaleform::GFx::Value ASIndexEvent::FUN_1422e2b60()
{
    return FUN_1422baa20("data");
}
MS2_REPLACE_METHOD(0x1422E2B60, ASIndexEvent, FUN_1422e2b60, 65, 0x879438C6);

// MS2-PIN: ??1ASTextEvent@@UEAA@XZ 0x1422e2bb0
// MS2-PIN: ??_GASEvent@@UEAAPEAXI@Z 0x1422e2bd0
// MS2-PIN: ??_GASIndexEvent@@UEAAPEAXI@Z 0x1422e2c10
// MS2-PIN: ??_GASListEvent@@UEAAPEAXI@Z 0x1422e2c50
// MS2-PIN: ??_GASTextEvent@@UEAAPEAXI@Z 0x1422e2c90
