// citemenchanttransformtable.h - PLACEHOLDER for CItemEnchantTransformTable (RTTI .?AVCItemEnchantTransformTable@@, 0xe0 bytes). NOT an original header.
// Bases: TSingleton<CItemEnchantTransformTable> at +0x0, CValidData<CItemEnchantTransformTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemEnchantTransformTable : public TSingleton<CItemEnchantTransformTable>,
                                   public CValidData<CItemEnchantTransformTable>
{
public:
    CItemEnchantTransformTable();                           // 0x140591410
    virtual ~CItemEnchantTransformTable();
    int FUN_1405915b0();                                    // 0x1405915b0
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xe0 - 0x10];
};
MS2_CHECK_SIZE(CItemEnchantTransformTable, 0xe0);
