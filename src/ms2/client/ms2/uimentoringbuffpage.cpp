// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mentoring: the buff tab page. Field/helper names are inferred.
// MS2-UNIT: ?\uimentoringbuffpage.cpp
// MS2-RANGE: 0x140c6e3a0-0x140c6e790 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimentoringbuffpage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimentoringrewardpage.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
CStringTable* GetStringTable();
void FUN_14025a680(const CStringW&, ATL::CAtlArray<CStringW>&, const wchar_t*);
CStringW GetStringCommonByKey(const CStringW& str);

// @0x140c6e3a0
UIMentoringBuffPage::UIMentoringBuffPage(UIMentoringDialog* p) : UIMentoringPage(p) {}
// @0x140c6e3e0
UIMentoringBuffPage::~UIMentoringBuffPage() {}

// @0x140c6e410
// MS2-FUNCTIONAL: frame 8 bytes smaller / 21 bytes shorter than the exe (extra stored temp pointers around the MS2Ptr<ASTextField> result)
int UIMentoringBuffPage::vfunc_1()
{
    int bBase = UIMentoringPage::vfunc_1();
    if (bBase == 0)
    {
        return 0;
    }
    else
    {
        int nBuffId = 0x55d4d2d;
        CStringW strDesc = GetStringTable()->FUN_141812290(nBuffId, 1, CString("tooltipDescription"));
        ATL::CAtlArray<CStringW> lines;
        FUN_14025a680(strDesc, lines, L"\n");
        for (size_t i = 0; i < 7; i++)
        {
            CStringW strLine;
            if (i < lines.GetCount())
                strLine = lines[i];
            MS2Ptr<ASTextField> text = m_script->FUN_1409b4620(StringFormat("m_benefitDesc{0}", i));
            if (text.get() != 0)
                text->FUN_1422c4cd0(strLine);
        }
        return 1;
    }
}

// @0x140c6e630
void UIMentoringBuffPage::vfunc_2()
{
    UIMentoringPage::vfunc_2();
}

// @0x140c6e650
int UIMentoringBuffPage::vfunc_5(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    return UIMentoringPage::vfunc_5(szMethod, pArgs, nArgs);
}

// @0x140c6e690
CString UIMentoringBuffPage::vfunc_6() { return "BuffPage"; }

// @0x140c6e6e0
CStringW UIMentoringBuffPage::vfunc_7() { return GetStringCommonByKey(L"s_mentoring_tab_buff"); }
