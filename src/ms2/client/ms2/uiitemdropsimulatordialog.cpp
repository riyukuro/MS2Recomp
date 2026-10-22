// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemDropSimulatorDialog: see uiitemdropsimulatordialog.h.
// MS2-UNIT: unit_14192a2e0
// MS2-RANGE: 0x14192a2e0-0x14192ac30 .text$mn
// MS2-RANGE: 0x140112cb0-0x140112e30 .text$di
// MS2-RANGE: 0x142cbdd30-0x142cbdd90 .text$yd
// MS2-PIN: ??1UIItemDropSimulatorDialog@@UEAA@XZ 0x14192aaa0
// MS2-PIN: ??_GUIItemDropSimulatorDialog@@UEAAPEAXI@Z 0x14192aac0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemdropsimulatordialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemdropsimulatordialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The sort type names (the two dynamic initializers at 0x140112cb0 / 0x140112d70; header statics of two headers).
static CString s_sortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_sortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class Unk_OptionTable { public: bool FUN_1405f4720(); };            // loads every table
Unk_OptionTable* FUN_140166430();                                   // the option table singleton
void* FUN_1401a9d70();                                              // the string table
void* FUN_141813150(void* pTable, CStringW* pOut, unsigned int nId, void* pArg, int nZero);

// @0x14192a2e0
UIItemDropSimulatorDialog::UIItemDropSimulatorDialog()
{
    m_40 = 1;
}

// @0x14192a330
CString UIItemDropSimulatorDialog::GetTypeName()
{
    return "ItemDropSimulatorDialog";
}

// @0x14192a380
void UIItemDropSimulatorDialog::OnLoadInit()
{
    UIDialog::OnLoadInit();
    FUN_140166430()->FUN_1405f4720();
}

// @0x14192a3b0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe keeps each ASData string / int read in its own temp slot, EH unwind map differs
int UIItemDropSimulatorDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onClickDropButton", szMethod) == 0) {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs) != 0) {
            int nA = args.FUN_1422b8a10();
            CString strA = args.FUN_1422b8d30();
            int nB = args.FUN_1422b8a10();
            int nC = args.FUN_1422b8a10();
            int nD = args.FUN_1422b8a10();
            int nE = args.FUN_1422b8a10();
            int nF = args.FUN_1422b8a10();
            int nG = args.FUN_1422b8a10();
            int nH = args.FUN_1422b8a10();
            int nI = args.FUN_1422b8a10();
            int nJ = args.FUN_1422b8a10();
            bool bFlag = args.FUN_1422b8a90();
            CString strB = args.FUN_1422b8d30();
            FUN_14192a900(nA, strA, nB, nC, nD, nE, nF, nG, nH, nI, nJ, bFlag, strB);
        }
        return 1;
    }
    if (_stricmp("onClickCustomDrop", szMethod) == 0) {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs) != 0) {
            CString strA = args.FUN_1422b8d30();
            int nA = args.FUN_1422b8a10();
            int nB = args.FUN_1422b8a10();
            int nC = args.FUN_1422b8a10();
            int nD = args.FUN_1422b8a10();
            int nE = args.FUN_1422b8a10();
            int nF = args.FUN_1422b8a10();
            CString strB = args.FUN_1422b8d30();
            int nG = args.FUN_1422b8a10();
            int nH = args.FUN_1422b8a10();
            int nI = args.FUN_1422b8a10();
            FUN_14192a940(strA, strB, nA, nD, nF, nB, nC, nE, nG, nH, nI);
        }
        return 1;
    }
    return 0;
}

// @0x14192a900
void UIItemDropSimulatorDialog::FUN_14192a900(int nA, CString strA, int nB, int nC, int nD, int nE, int nF, int nG, int nH,
                                              int nI, int nJ, bool bFlag, CString strB)
{
}

// @0x14192a940
void UIItemDropSimulatorDialog::FUN_14192a940(CString strA, CString strB, int nA, int nB, int nC, int nD, int nE, int nF,
                                              int nG, int nH, int nI)
{
}

// @0x14192a9a0
void UIItemDropSimulatorDialog::FUN_14192a9a0(CStringW strText)
{
    if (MS2Ptr<ASTextField> spText = FUN_140bb4cf0("m_simulateResult"))
        spText->FUN_1422c4cd0(strText);
}

// @0x14192aa50
CStringW* UIItemDropSimulatorDialog::FUN_14192aa50(CStringW* pOut, unsigned int nId, void* pArg)
{
    FUN_141813150(FUN_1401a9d70(), pOut, nId, pArg, 0);
    return pOut;
}

// @0x14192ab00
int UIItemDropSimulatorDialog::vfunc_48()
{
    return 0x4e37;
}

// @0x14192ab10
MS2_EMIT_CRT_MEMMOVE_S();
