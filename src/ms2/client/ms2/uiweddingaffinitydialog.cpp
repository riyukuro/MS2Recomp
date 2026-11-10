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
#include "ms2/placeholder/mstime.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/placeholder/weddingproxy.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----


// The kind of an affinity log row (Unk_WeddingLog::m_nType), formatted into the string key.
enum Unk_WdKind : unsigned int {};
class WeddingManager;
class WeddingManager   // C3: member view for the former free stand-ins
{
public:
    class WeddingProxy* FUN_140d295d0();
};
__int64 GetServerTime();                                        // server time
int GetDayNumberDifference(__int64 nFrom, __int64 nTo);         // whole days between
CStringW FormatYearMonthDayHour(const CMsTime& time);                    // the date text
#include "ms2/placeholder/wcformat.h"
#include "ms2/commonfiles/os.h"

// @0x140fc2090
UIWeddingAffinityDialog::UIWeddingAffinityDialog()
{
    m_2c = 0x19;
    FUN_1422dc3b0(1);
    SetTweenEnabled(1);
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

// @0x140fc21e0
void UIWeddingAffinityDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    WeddingProxy* pWedding = TSingleton<WeddingManager>::GetInstance()->FUN_140d295d0();
    __int64 nExp = reinterpret_cast<WeddingTable*>(TSingleton<WeddingTable>::GetInstance())->GetRewardExp(1, 0);
    int nDays = GetDayNumberDifference(pWedding->m_n30, GetServerTime());
    nExp = nExp * nDays;
    CStringW strHistory;
    strHistory += FUN_14028dfa0(CStringW(L"s_wedding_dialog_exp_1"), nExp, nDays);
    std::list<Unk_WeddingLog>::const_iterator it = static_cast<const std::list<Unk_WeddingLog>&>(pWedding->m_log.m_list).begin();
    std::list<Unk_WeddingLog>::const_iterator itEnd = static_cast<const std::list<Unk_WeddingLog>&>(pWedding->m_log.m_list).end();
    for (; it != itEnd; ++it)
    {
        const Unk_WeddingLog& log = *it;
        CMsTime kTime(log.m_nTime);
        CStringW strDate = FormatYearMonthDayHour(kTime);
        CStringW strText = FUN_14028dfa0<__int64>(StringFormat(L"s_wedding_dialog_exp_{0}", reinterpret_cast<const Unk_WdKind&>(log.m_nType)), log.m_nAmount);
        strHistory += L"\n";
        strHistory += StringFormat<CStringW, CStringW>(L"[{0}] {1}", strDate, strText);
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
