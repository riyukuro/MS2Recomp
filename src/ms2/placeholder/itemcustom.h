// itemcustom.h - PLACEHOLDER for ItemCustom (RTTI .?AVItemCustom@@, 0x38 bytes), the <custom> child of an item model
// <asset> element. NOT an original header. Ctor 0x140266a10 and XML reader 0x140266aa0 are in unit_140266860, the
// implicit destructor 0x14027e890 and ??_G 0x140280070 in commonfiles\commonstruct.cpp. The size is the `operator new(0x38)`
// of commonfiles\itemdatastruct.cpp (ModelPart reader 0x140543ca0); the layout is the ctor's.
#pragma once
#include <afx.h>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class TiXmlElement;    // game TinyXML element

class ItemCustom : public CPtred
{
public:
    ItemCustom();                                   // 0x140266a10
    // ~ItemCustom() is implicit (0x14027e890 has no vptr store); commonstruct_2 emits it
    void ReadXml(TiXmlElement* pElem);        // XML read
    void WriteXml(void* pElem) const;          // XML write
    efd::Point3 unknown18;          // +0x18
    efd::Point3 unknown24;          // +0x24
    CString name;                   // +0x30
};
MS2_CHECK_SIZE(ItemCustom, 0x38);
