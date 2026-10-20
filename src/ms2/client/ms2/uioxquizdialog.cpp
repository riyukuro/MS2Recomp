// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The OX quiz window ("OxQuizDialog"); see uioxquizdialog.h.
// One of the five TUs of the queue unit ?\uiotherpetsystemdialog.cpp (UIOtherPetSystemDialog, UIOxQuizDialog,
// UIPaybackDialog, UIPetExtractionScrollDialog, UIPetSystemDialog). This TU has no .text$di.
// MS2-UNIT: ?\uiotherpetsystemdialog.cpp
// MS2-RANGE: 0x140e6e400-0x140e6ec40 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uioxquizdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uioxquizdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names describe uses) ----
class ASDialog : public ASDisplayObject {};

int FUN_1418fd280();                                    // the player is in the OX quiz field
int FUN_1418fd2f0();                                    // the OX quiz is running
unsigned FUN_140869420();                               // the client tick (ms)
CStringW FUN_14028de60(int nId);                        // a common string by id
void FUN_140dff2b0();                                   // the OX quiz manager: request the promote
void FUN_140dfeeb0();                                   // the OX quiz manager: request a new quiz
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

bool UIOxQuizDialog::s_bEnable;

// @0x140e6e400
UIOxQuizDialog::UIOxQuizDialog()
    : m_178(0), m_17c(10.0f)
{
    FUN_141925e70(0, 1);
}

// @0x140e6e490
UIOxQuizDialog::~UIOxQuizDialog()
{
}

// @0x140e6e4d0
CString UIOxQuizDialog::vfunc_1()
{
    return "OxQuizDialog";
}

// @0x140e6e520
int UIOxQuizDialog::vfunc_65()
{
    if (!s_bEnable)
        return 0;
    return UIDialog::vfunc_65();
}

// @0x140e6e550
void UIOxQuizDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e6e640();
}

// @0x140e6e580
int UIOxQuizDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("OnQuizPromote", szMethod) == 0)
    {
        FUN_140e6e8d0();
        return 1;
    }
    else if (_stricmp("OnQuizCreate", szMethod) == 0)
    {
        FUN_140e6e8f0();
        return 1;
    }
    return 0;
}

// @0x140e6e610
void UIOxQuizDialog::FUN_140e6e610(bool bUnused)
{
    if (FUN_1418fd280() == 0)
        return;
    FUN_140e6e640();
}

// @0x140e6e640
void UIOxQuizDialog::FUN_140e6e640()
{
    if (FUN_1418fd280() == 0)
        return;
    if (FUN_1418fd2f0())
    {
        float fRemain = m_17c - (float)(FUN_140869420() - m_178) / 1000.0f;
        FUN_140e6e6c0(fRemain, m_17c);
    }
}

// @0x140e6e6c0
void UIOxQuizDialog::FUN_140e6e6c0(float fRemain, float fTotal)
{
    if (ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30))
        pDialog->Invoke("setQuizPromoteCooltime", fRemain, fTotal, FUN_14028de60(0x5ce), FUN_14028de60(0x5cc),
                        FUN_14028de60(0x5ca), FUN_14028de60(0x5cb));
    m_178 = FUN_140869420() - (unsigned)((fTotal - fRemain) * 1000.0f);
    m_17c = fTotal;
}

// @0x140e6e8b0
void UIOxQuizDialog::FUN_140e6e8b0(bool bEnable)
{
    s_bEnable = bEnable;
}

// @0x140e6e8d0
void UIOxQuizDialog::FUN_140e6e8d0()
{
    FUN_140dff2b0();
}

// @0x140e6e8f0
void UIOxQuizDialog::FUN_140e6e8f0()
{
    FUN_140dfeeb0();
}

// @0x140e6e910
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, float a1, float a2, CStringW a3, CStringW a4,
                                             CStringW a5, CStringW a6)
{
    ASArgList args;
    args.FUN_1409b2800(6);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), a4);
    FUN_1422bcea0(args.FUN_1409b1f70(4), a5);
    FUN_1422bcea0(args.FUN_1409b1f70(5), a6);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
