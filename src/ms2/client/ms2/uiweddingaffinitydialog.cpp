// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingAffinityDialog: the couple's affinity experience history.
// MS2-UNIT: ?\uiweddingaffinitydialog.cpp
// MS2-RANGE: 0x140fc2090-0x140fc2c50 .text$mn
// MS2-PIN: ?vfunc_48@UIWeddingAffinityDialog@@UEAAHXZ 0x140fc2b20
// MS2-PIN: ??_GUIWeddingAffinityDialog@@UEAAPEAXI@Z 0x140fc2ae0
// MS2-PIN: ??$FUN_14028dfa0@_JH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_JAEBH@Z 0x140fc2630
// MS2-PIN: ??$format_arg@_WW4Unk_WdKind@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_WdKind@@@Z 0x140fc2960
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddingaffinitydialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiweddingaffinitydialog.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----

CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);   // string table text, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

// The wedding data of the own character: the marriage time (+0x30) and the affinity experience log (+0x130, a map keyed
// by the kind of event; the value is the event time and the experience).
enum Unk_WdKind : unsigned int {};
struct Unk_WdEvent { __int64 m_nTime; __int64 m_nExp; };
struct Unk_WdNode { Unk_WdKind m_kind; Unk_WdEvent m_event; };
class Unk_WdIter
{
public:
    bool FUN_140902060(const Unk_WdIter& end);                  // !=
    Unk_WdNode* FUN_140902120();                                // operator*
    void FUN_1409021f0();                                       // ++
private:
    void* m_pad_00;
};
class Unk_WdLog { public: void FUN_140902c10(Unk_WdIter* out); void FUN_140902e70(Unk_WdIter* out); };   // begin / end
struct Unk_WdWedding
{
    char m_pad_00[0x30];
    __int64 m_nMarriedTime;             // +0x30
    char m_pad_38[0x130 - 0x38];
    Unk_WdLog m_log;                    // +0x130
};
void* FUN_1409eed90();                                          // the singleton of the own character
Unk_WdWedding* FUN_140d295d0(void* pSingleton);
class Unk_WdRates { public: __int64 FUN_140908e60(int a, int b); };   // the base experience per day
Unk_WdRates* FUN_1409023c0();
__int64 FUN_140869440();                                        // server time
int FUN_14086b900(__int64 nFrom, __int64 nTo);                  // whole days between
struct Unk_WdTime { __int64 m_a; __int64 m_b; };
Unk_WdTime FUN_1406c47a0(__int64 time);
CStringW FUN_140b8e850(Unk_WdTime time);                           // the date text
CStringW FUN_140c160b0(CStringW strKey, const __int64* pValue);
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& arg0, const CStringW& arg1);

// @0x140fc2090
UIWeddingAffinityDialog::UIWeddingAffinityDialog()
{
    m_2c = 0x19;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
}

// @0x140fc2110
UIWeddingAffinityDialog::~UIWeddingAffinityDialog()
{
}

// @0x140fc2150
CString UIWeddingAffinityDialog::GetTypeName()
{
    return "WeddingAffinityDialog";
}

// @0x140fc21a0
int UIWeddingAffinityDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}

// @0x140fc21c0
void UIWeddingAffinityDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// MS2-FUNCTIONAL: behaviour-equivalent (temporaries / EH states differ)
// @0x140fc21e0
void UIWeddingAffinityDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_WdWedding* pWedding = FUN_140d295d0(FUN_1409eed90());
    __int64 nExp = FUN_1409023c0()->FUN_140908e60(1, 0);
    int nDays = FUN_14086b900(pWedding->m_nMarriedTime, FUN_140869440());
    nExp = nExp * nDays;
    CStringW strHistory;
    strHistory += FUN_14028dfa0(CStringW(L"s_wedding_dialog_exp_1"), nExp, nDays);
    Unk_WdIter it;
    Unk_WdIter itEnd;
    pWedding->m_log.FUN_140902c10(&it);
    pWedding->m_log.FUN_140902e70(&itEnd);
    while (it.FUN_140902060(itEnd))
    {
        Unk_WdNode* pNode = it.FUN_140902120();
        CStringW strDate = FUN_140b8e850(FUN_1406c47a0(pNode->m_event.m_nTime));
        CStringW strText = FUN_140c160b0(StringFormat(L"s_wedding_dialog_exp_{0}", pNode->m_kind), &pNode->m_event.m_nExp);
        strHistory += L"\n";
        strHistory += FUN_140656190(L"[{0}] {1}", strDate, strText);
        it.FUN_1409021f0();
    }
    if (m_30.get() != 0)
        m_30->Invoke("setHistory", strHistory);
}

// @0x140fc2510
int UIWeddingAffinityDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
