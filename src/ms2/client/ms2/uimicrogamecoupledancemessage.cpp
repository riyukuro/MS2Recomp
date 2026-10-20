// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uimicrogamecoupledancemessage.h.
//
// MS2-UNIT: ?\uimicrogamecoupledancemessage.cpp
// MS2-RANGE: 0x140e65990-0x140e65f80 .text$mn
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimicrogamecoupledancemessage.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uimicrogamecoupledancemessage.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

int FUN_1412755a0();                                                    // a global mode query of the show/hide
int FUN_140d03130(MS2Ptr<ASDisplayObject>* pRoot, int n);               // the display object could not be made
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);               // set an Int argument
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);  // set a String argument

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140e65990
UIMicroGameCoupleDanceMessage::UIMicroGameCoupleDanceMessage()
{
    m_58 = 0;
    m_2c = 0x1e;
}

// @0x140e659f0
UIMicroGameCoupleDanceMessage::~UIMicroGameCoupleDanceMessage()
{
}

// @0x140e65a30
CString UIMicroGameCoupleDanceMessage::vfunc_1()
{
    return "MicroGameCoupleDanceMessage";
}

// @0x140e65a80
void UIMicroGameCoupleDanceMessage::vfunc_2()
{
    if (FUN_1412755a0() == 0) {
        UIHeadUpDisplay::vfunc_2();
        FUN_1422dbf00(0x1e, 0, 0);
    }
}

// @0x140e65ac0
void UIMicroGameCoupleDanceMessage::vfunc_3()
{
    if (FUN_1412755a0() == 0) {
        FUN_1422dc080();
        UIHeadUpDisplay::vfunc_3();
    }
}

// @0x140e65b00
void UIMicroGameCoupleDanceMessage::vfunc_43()
{
    MS2Ptr<ASDisplayObject> pRoot = FUN_1422dba50();
    if (FUN_140d03130(&pRoot, 0) != 0)
        return;
    pRoot->vfunc_2(5, 0, 0);
    pRoot->Invoke("resizeStage");
}

// @0x140e65bb0
int UIMicroGameCoupleDanceMessage::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0;
}

// @0x140e65c00
void UIMicroGameCoupleDanceMessage::FUN_140e65c00(CStringW strMessage, int nTime)
{
    if (m_30.IsNull())
        return;
    m_30->Invoke("showMessage", strMessage, nTime);
}

// @0x140e65ce0
void UIMicroGameCoupleDanceMessage::FUN_140e65ce0(int nType, CStringW strMessage, int nTime)
{
    if (m_30.IsNull())
        return;
    m_30->Invoke("showStageMessage", nType, strMessage, nTime);
}

// @0x140e65dd0 (the "showStageMessage" Invoke: an Int, a String and an Int argument)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, CStringW a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2.GetString());
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140e65f20
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
