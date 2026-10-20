// cnpcshopmeratitembase.h - PLACEHOLDER for CNpcShopMeratItemBase (RTTI .?AVCNpcShopMeratItemBase@@, CPtred-derived,
// 0x30 bytes: ctor 0x1406eeb50, dtor 0x1406ef7e0 (??_G 0x1406f1100)): a merat NPC shop product. NOT an original header;
// the class is defined by commonfiles\npcshopdata.cpp (w514). Slots: 1 write, 2 read, 3 (unused here).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class CInPacket;
class COutputStream;
class CMeratMarketPremiumProduct;

class CNpcShopMeratItemBase : public CPtred
{
public:
    CNpcShopMeratItemBase();                                // 0x1406eeb50 (an inline COMDAT in the exe: m_nDisplayOrder(1), m_spProduct(0))
    virtual ~CNpcShopMeratItemBase();                       // 0x1406ef7e0 (an inline COMDAT in the exe: m_spProduct = 0)
    virtual void vfunc_1(COutputStream* pOut);              // 1 0x1406f1980 write
    virtual void vfunc_2(CInPacket* pIn);                   // 2 0x1406f1840 read
    virtual unsigned vfunc_3();                             // 3 0x1406f2470

    int m_nDisplayOrder;                                    // +0x18
    MS2Ptr<CMeratMarketPremiumProduct> m_spProduct;         // +0x20
};
MS2_CHECK_SIZE(CNpcShopMeratItemBase, 0x30);
