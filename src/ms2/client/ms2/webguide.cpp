// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WebGuide / WebGuideTable: Table/WebGuide.xml (<v dialogName
// webUrl/>), the first user of the DataTable / DataTableBase / DataTableMap templates (datatable.h, datatablemap.h).
// MS2-UNIT: ?\webguide.cpp
// MS2-RANGE: 0x141b81ac0-0x141b835d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Add@?$DataTableMap@VWebGuide@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@3@@@UEAAXV?$MS2Ptr@VWebGuide@@@@@Z 0x141b82890 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7WebGuideTable@@6B?$TSingleton@VWebGuideTable@@@@@ 0x142ff57a0
// MS2-PIN: ??_7WebGuideTable@@6B?$DataTableMap@VWebGuide@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CStringElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@3@@@@ 0x142ff5780
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/webguide.h"
#include "ms2/placeholder/datatable_impl.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

int XmlGetAttr(class TiXmlElement* pElem, const char* pszName, CString& out);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton (symbols-manual.tsv)
WebGuideTable* TSingleton<WebGuideTable>::s_instance;
#endif

// @0x141b81ac0
WebGuide::WebGuide()
{
}

// @0x141b81b20
CString WebGuide::GetKey() const
{
    return m_strDialogName;
}

// @0x141b81b70
void WebGuide::LoadXml(Unk_140165cf0* pNode)
{
    XmlGetAttr((TiXmlElement*)pNode, "dialogName", m_strDialogName);
    XmlGetAttr((TiXmlElement*)pNode, "webUrl", m_strWebUrl);
}

// @0x141b81bd0
WebGuideTable::WebGuideTable()
{
    Load(CString("Table"), CString("WebGuide.xml"), CString("v"));
}

// @0x141b82110
WebGuide::~WebGuide()
{
}

// @0x141b834b0
MS2_EMIT_CRT_MEMMOVE_S();
