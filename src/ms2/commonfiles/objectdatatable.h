// objectdatatable.h - CObjectDataTable and its Display rows (RTTI names): the object display table read from
// Table/ObjectData.xml (<display id actionkey ui/>). Header name assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tixmldocument.h"

class TiXmlElement;

// The table. RTTI CObjectDataTable, 0xf0 bytes: CCacheData +0, TSingleton +0x28, CValidData +0x30, the xml document
// +0x38, the id -> row map +0xa8. Created by CGameApp::InitInstance (?\ms2.cpp).
class CObjectDataTable : public CCacheData,
                         public TSingleton<CObjectDataTable>,
                         public CValidData<CObjectDataTable>
{
public:
    // One <display> row. RTTI CObjectDataTable::Display, 0x28 bytes, base CPtred.
    class Display : public CPtred
    {
    public:
        Display();                          // 0x14070cc90
        // The destructor (0x14070cdc0) and deleting destructor (0x14070cf70) are implicit.

        CString m_strActionKey;             // +0x18 "actionkey"
        CString m_strUi;                    // +0x20 "ui"
    };
    typedef MS2Ptr<Display> DisplayPtr;

    CObjectDataTable();                     // 0x14070c3f0
    virtual ~CObjectDataTable();            // 0x14070c4d0

    void Load();                            // 0x14070c590 Table/ObjectData.xml
    DisplayPtr GetData(int nId);            // 0x14070c710 the row of an id (null when missing); reloads a changed file
    void Reload();                          // 0x14070c7c0
    void LoadDisplays(TiXmlElement* pRoot);    // 0x14070c800

    static void CheckInit();                // 0x14070cfb0
    static void SetInit(bool b);            // 0x14070de80

    static bool s_bInit;

private:
    MS2_LAYOUT_FRIEND;
    TiXmlDocument m_doc;                    // +0x38
    ATL::CAtlMap<int, DisplayPtr> m_map;    // +0xa8 id -> row
};
MS2_CHECK_SIZE(CObjectDataTable::Display, 0x28);
MS2_CHECK_SIZE(CObjectDataTable, 0xf0);
MS2_CHECK_OFFSET(CObjectDataTable, m_doc, 0x38);
MS2_CHECK_OFFSET(CObjectDataTable, m_map, 0xa8);
