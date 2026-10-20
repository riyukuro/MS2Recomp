// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTextArea, the ActionScript multi-line text area wrapper of
// the GFx UI library (the messenger's chat lines).
// MS2-UNIT: ?\astextarea.cpp
// MS2-RANGE: 0x1422e4570-0x1422e47c0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/astextarea.h. "position" is the scroll position in lines; the last line is
// the text field's "maxScrollV".
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/astextarea.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "hook/ms2hook.h"

// @0x1422e4570
ASTextArea::ASTextArea(const Scaleform::GFx::Value& v, int nMovieId)
    : ASTextInput(v, nMovieId)
{
}

// @0x1422e45c0
ASTextArea::~ASTextArea()
{
}

// @0x1422e45f0
void ASTextArea::FUN_1422e45f0(int nPosition)
{
    FUN_1407cb9c0("position", nPosition);
}
MS2_REPLACE_METHOD(0x1422E45F0, ASTextArea, FUN_1422e45f0, 40, 0xA9BCC004);

// @0x1422e4620
int ASTextArea::FUN_1422e4620()
{
    return FUN_1422baa20("position").GetInt();
}
MS2_REPLACE_METHOD(0x1422E4620, ASTextArea, FUN_1422e4620, 88, 0xEA75B308);

// @0x1422e4680
int ASTextArea::FUN_1422e4680()
{
    if (FUN_1422e4620() == FUN_1422e1490()->FUN_1422c58b0())
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1422E4680, ASTextArea, FUN_1422e4680, 148, 0x165DC057);

// @0x1422e4720
void ASTextArea::FUN_1422e4720()
{
    FUN_1422e45f0(FUN_1422e1490()->FUN_1422c58b0());
}
MS2_REPLACE_METHOD(0x1422E4720, ASTextArea, FUN_1422e4720, 94, 0x3285D998);

// MS2-PIN: ??_GASTextArea@@UEAAPEAXI@Z 0x1422e4780
