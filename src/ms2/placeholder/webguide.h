// webguide.h - WebGuide / WebGuideTable (RTTI names): Table/WebGuide.xml, <v dialogName webUrl/> rows keyed by the dialog
// name (the web guide page of a dialog). NOT an original header (member names invented).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/datatablemap.h"

class Unk_140165cf0;

class WebGuide : public CPtred
{
public:
    WebGuide();                                             // 0x141b81ac0
    CString GetKey() const;                                 // 0x141b81b20 the dialog name
    void LoadXml(Unk_140165cf0* pNode);                     // 0x141b81b70

    CString m_strDialogName;                                // +0x18 "dialogName"
    CString m_strWebUrl;                                    // +0x20 "webUrl"
};
MS2_CHECK_SIZE(WebGuide, 0x28);
MS2_CHECK_OFFSET(WebGuide, m_strDialogName, 0x18);
MS2_CHECK_OFFSET(WebGuide, m_strWebUrl, 0x20);

class WebGuideTable : public DataTableMap<WebGuide, CString, ATL::CStringElementTraits<CString> >,
                      public TSingleton<WebGuideTable>
{
public:
    WebGuideTable();                                        // 0x141b81bd0 loads Table/WebGuide.xml
};
MS2_CHECK_SIZE(WebGuideTable, 0x88);
