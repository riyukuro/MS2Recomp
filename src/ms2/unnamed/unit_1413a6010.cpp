// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition class Dialog (factory, name, loader, check).
// See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a6010
// MS2-RANGE: 0x1413a6010-0x1413a6580 .text$mn
// MS2-RANGE: 0x1413b4700-0x1413b4740 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

UIDialog* FUN_140c300a0(unsigned nDialogID);                // the dialog of a UI id
UIDialog* FUN_141386950(const CStringA* pName);             // the dialog of a name
void FUN_141386b50(Unk_140165cf0* pElem, const char* pszName, ATL::CAtlArray<CString>& arr);   // the "control" name list
CStringW FUN_14016a730(const char* sz, int nFlags);         // FormatStringId(sz) without arguments

class Unk_GdMgr { public: int FUN_14138d870(const CStringA* pName); };   // the dialog state service
Unk_GdMgr* FUN_1409331e0();

template <> MS2Ptr<ASDisplayObject> UISwfEntity::GetChild<ASDisplayObject>(const CString& strName);    // 0x1413b1a90

// (the CGuideConditionDialog registrar, 0x1400f3420, lives in unit_1413a6e30)

// @0x1413a6010
ClassObject* CGuideConditionDialog::CreateObject()
{
    return new CGuideConditionDialog;
}

// @0x1413a6070
CStringW CGuideConditionDialog::GetTypeName()
{
    return L"CGuideConditionDialog";
}

// @0x1413a60c0
CGuideConditionDialog::CGuideConditionDialog()
    : m_nIsOpen(1), m_nDialogID(0), m_nSubIndex(-1)
{
}

// @0x1413a6140
int CGuideConditionDialog::vfunc_3()
{
    UIDialog* pDlg = 0;
    if (m_nDialogID != 0)
        pDlg = FUN_140c300a0(m_nDialogID);
    if (pDlg == 0)
        pDlg = FUN_141386950(&m_strDialog);
    if (pDlg == 0)
        return 0;
    unsigned nOpen = pDlg->vfunc_55() == 0;
    if (nOpen != (unsigned)m_nIsOpen)
        return 0;
    for (unsigned i = 0; i < m_arrControl.GetCount(); i++)
    {
        MS2Ptr<ASDisplayObject> spChild = pDlg->GetChild<ASDisplayObject>(m_arrControl[i]);
        if (spChild == 0)
            return 0;
        if (!spChild->FUN_1422bfca0())
            return 0;
    }
    if (m_nSubIndex >= 0 && pDlg->vfunc_82() != m_nSubIndex)
        return 0;
    return 1;
}

// @0x1413a6300
CStringW CGuideConditionDialog::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"dialogName({0}), isOpen({1}), subIndex({2})", FUN_14016a730(m_strDialog, 0), m_nIsOpen, m_nSubIndex));
    return str;
}

// @0x1413a6430
int CGuideConditionDialog::vfunc_8()
{
    if (m_nIsOpen == 0)
        return 0;
    int nResult = FUN_1409331e0()->FUN_14138d870(&m_strDialog);
    return nResult;
}

// @0x1413a6480
void CGuideConditionDialog::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 3;
    if (m_b1c != 0)
        throw std::exception("Dialog is Not Allow Keword 'not'");
    FUN_1408733e0(pElem, "dialogName", m_strDialog);
    FUN_140873220(pElem, "dialogID", m_nDialogID);
    FUN_1408731e0(pElem, "isOpen", m_nIsOpen);
    FUN_1408731e0(pElem, "subIndex", m_nSubIndex);
    FUN_141386b50(pElem, "control", m_arrControl);
}
