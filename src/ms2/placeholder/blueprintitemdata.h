// blueprintitemdata.h - CBlueprintItemData (RTTI .?AVCBlueprintItemData@@, owner commonfiles\ugcdef.cpp), the blueprint
// half of a CItemUgc (item.h, at +0x80). 0x58 bytes: CPtred, eight scalar fields, one wide string. Ctor 0x1408923d0 (CPtred
// ctor, vftable, string ctor, reset), dtor 0x140892430, deleting dtor 0x140899e90. Header name assumed; member names are by
// offset. The one definition: commonfiles/ugcdef.h includes this (item.h cannot include all of ugcdef.h).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class COutputStream;
class CInputStream;

class CBlueprintItemData : public CPtred
{
public:
    CBlueprintItemData();                                   // 0x1408923d0
    virtual ~CBlueprintItemData();                          // 0x140892430

    void Clear();                                           // 0x140892470 every field reset, the string to L""
    void CopyFrom(const CBlueprintItemData& other);         // 0x140892510 field-wise copy
    void Write(COutputStream& stream) const;                // 0x1408925d0
    void Read(CInputStream& stream);                        // 0x1408926e0

    __int64 m_n18;                                          // +0x18
    int m_n20;                                              // +0x20
    int m_n24;                                              // +0x24
    int m_n28;                                              // +0x28
    __int64 m_n30;                                          // +0x30
    int m_n38;                                              // +0x38
    __int64 m_n40;                                          // +0x40
    __int64 m_n48;                                          // +0x48
    CStringW m_strName;                                     // +0x50
};
MS2_CHECK_SIZE(CBlueprintItemData, 0x58);
