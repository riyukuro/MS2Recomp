// characterdecaldata.h - PLACEHOLDER for CharacterDecalData (RTTI .?AVCharacterDecalData@@, 0x48 bytes), the decal
// block of an item model slot of type 3. NOT an original header. Ctor 0x1401e4000, XML reader 0x1401e4090, dtor
// 0x1401e4e40 and ??_G 0x1401e4ed0 are in ?\characterdecaldata.cpp. The size is the `operator new(0x48)` of
// commonfiles\itemdatastruct.cpp (ItemModelData reader 0x14054af00); the layout is the ctor's.
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/itemcustom.h"

class Unk_140165cf0;    // game TinyXML element

class CharacterDecalData : public CPtred
{
public:
    CharacterDecalData();                           // 0x1401e4000
    virtual ~CharacterDecalData() = default;        // 0x1401e4e40 (implicit: no vptr store; pinned)
    void FUN_1401e4090(Unk_140165cf0* pElem);       // XML read
    std::vector<MS2Ptr<ItemCustom> >* FUN_1401e41c0();      // &customs
    // Inline COMDAT 0x140d38880 (emitted by ?\itemloadinfo.cpp): the texture path.
    const CString& GetTexture() const { return unknown18; }
    CString unknown18;              // +0x18
    float unknown20;                // +0x20
    float unknown24;                // +0x24
    float unknown28;                // +0x28
    float unknown2c;                // +0x2c (default 1.0)
    std::vector<MS2Ptr<ItemCustom> > customs;   // +0x30 <custom> children
};
MS2_CHECK_SIZE(CharacterDecalData, 0x48);
