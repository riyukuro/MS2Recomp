// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISceneLogo: see uiscenelogo.h.
// MS2-UNIT: ?\uiscenelogo.cpp
// MS2-RANGE: 0x141ad03f0-0x141ad0650 .text$mn
// MS2-PIN: ??_GUISceneLogo@@UEAAPEAXI@Z 0x141ad0610
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "uiscenelogo.h"
#include "ms2/placeholder/uivideocontents.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types (unrecovered helpers) ----

// The intro movie dialog (0xa8 bytes, base UIVideoContents; slot 52 plays a video).
class UIIntroMovie : public UIVideoContents
{
};

class Unk_SlUIMgr                                       // the UI service (FUN_1403ed2b0)
{
public:
    void FUN_141adafd0(int nSceneId);
};
Unk_SlUIMgr* FUN_1403ed2b0();

class Unk_SlA;  class Unk_SlB;  class Unk_SlC;  class Unk_SlD;  class Unk_SlE;
class Unk_SlF;  class Unk_SlG;
Unk_SlA* FUN_1414a5870();
void FUN_140c9f8f0(Unk_SlA* p);
Unk_SlB* FUN_140166430();
void FUN_1405f4720(Unk_SlB* p);
void FUN_140583fa0();
Unk_SlC* FUN_140166420();
Unk_SlD* FUN_1414a5720();
void FUN_141215220(Unk_SlD* p, Unk_SlC* pC, int a, int b, int c, void* d);
Unk_SlE* FUN_1406aeee0();
bool FUN_1406af080(Unk_SlE* p);
Unk_SlF* FUN_140ab7a10();
void FUN_141210cc0(Unk_SlF* p, int n);
void FUN_14120fcc0(Unk_SlF* p);

UIIntroMovie* FUN_140e85420(int nUiId);                 // the intro movie dialog (uiscenemodeselect.cpp's static)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141ad03f0
UISceneLogo::UISceneLogo()
{
    m_6c = 0x620000b;
}

// @0x141ad0440
UISceneLogo::~UISceneLogo()
{
}

// @0x141ad0480
CString UISceneLogo::GetTypeName()
{
    return "SceneLogo";
}
MS2_REPLACE_METHOD(0x141AD0480, UISceneLogo, GetTypeName, 61, 0x8DD3FAEE);

// @0x141ad04d0
void UISceneLogo::vfunc_48(int n)
{
    FUN_1403ed2b0()->FUN_141adafd0(m_6c);
    UISceneEntity::vfunc_48(n);
}
MS2_REPLACE_METHOD(0x141AD04D0, UISceneLogo, vfunc_48, 53, 0x4D72E8A7);

// @0x141ad0510
void UISceneLogo::OnLoadComplete()
{
    UISwfEntity::OnLoadComplete();
    UIIntroMovie* pIntro = FUN_140e85420(0x4e33);
    if (pIntro != 0)
        pIntro->vfunc_52("Common/MS2Intro.usm", 0);
    FUN_140c9f8f0(FUN_1414a5870());
    FUN_1405f4720(FUN_140166430());
    FUN_140583fa0();
    FUN_141215220(FUN_1414a5720(), FUN_140166420(), 0, 0, 0, 0);
    if (FUN_1406af080(FUN_1406aeee0()))
        FUN_141210cc0(FUN_140ab7a10(), 0);
    FUN_14120fcc0(FUN_140ab7a10());
}
MS2_REPLACE_METHOD(0x141AD0510, UISceneLogo, OnLoadComplete, 247, 0x8935B023);

MS2_EMIT_CRT_MEMMOVE_S();
