// npcshopproductbase.h - the client NPC shop products (RTTI .?AVCNpcShopProductBase@@ 0x50 bytes, .?AVCNpcShopProductCli@@
// 0xe8, .?AVCNpcShopProductNewCli@@ 0x98, .?AVCNpcShopMeratItemCli@@ 0x48), recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\npcshopproductbase.cpp` (0x140db5c50-0x140db8d80 .text$mn, 0x1400d4e20-0x1400d4fa0 .text$di,
// dir client\ms2). Header/unit name assumed (the class name). FUN_<va> are non-virtual members; member names are
// invented. Layouts: base ctor 0x140db5c50, Cli ctor 0x140db5f50, NewCli ctor 0x140db87e0, MeratItemCli ctor 0x140db8920.
//
// All three products derive CPtred: vftable slots 0 dtor, 1 and 2 (two small virtual getters, overridden by each class).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/cnpcshopitemnew.h"
#include "ms2/placeholder/cnpcshopmeratitembase.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class CInPacket;
class CItem;
class CNpcShopBuyPeriod;

class CNpcShopProductBase : public CPtred
{
public:
    CNpcShopProductBase();                                          // 0x140db5c50
    virtual ~CNpcShopProductBase();                                 //  0 0x140db5cd0 (??_G 0x140db8c40)
    virtual int vfunc_1();                                          //  1 0x140db5f20
    virtual int vfunc_2();                                          //  2 0x140db5f40

    CStringW FUN_140db5d20();                                       // the item's name ("" when there is no item)
    int FUN_140db5e20();                                            // the item id (0: no item)
    int FUN_140db5e70();                                            // the product serial id
    MS2Ptr<CItem> FUN_140db5e90();                                  // a copy of the item handle
    int FUN_140db5ee0();                                            // the product type
    ATL::CAtlArray<CString>* FUN_140db5f00();                         // the category list
    ATL::CAtlArray<CString>* FUN_140db7040();

    int m_18;                                                       // +0x18 serial id
    int m_1c;                                                       // +0x1c product type
    ATL::CAtlArray<CString> m_20;                                     // +0x20 categories (split from the tag text)
    MS2Ptr<CItem> m_40;                                             // +0x40 the item
};
MS2_CHECK_SIZE(CNpcShopProductBase, 0x50);

class CNpcShopProductCli : public CNpcShopProductBase
{
public:
    CNpcShopProductCli();                                           // 0x140db5f50
    virtual ~CNpcShopProductCli();                                  //  0 0x140db6120 (??_G 0x140db8c80)
    virtual int vfunc_1() { return m_bc; }                          //  1 0x140db8d00
    virtual int vfunc_2() { return m_c0; }                          //  2 0x140db8d40

    void FUN_140db61a0(CInPacket& in, int nMode);                   // read the product (mode 1: list entry, 7: update)
    void FUN_140db6db0(int nIndex);                                 // set the item index
    void FUN_140db6e00(int nBuyCount);                              // m_58 = n, refresh the remainder
    void FUN_140db6e30(unsigned nBuyCount);                         // split a total into packs of m_b8
    int FUN_140db6e90();                            // remaining
    int FUN_140db6eb0();                                            // remaining (items)
    int FUN_140db6ef0();                            // limit
    int FUN_140db6f10();                                            // limit (items)
    int FUN_140db6f50();                            // bought
    int FUN_140db6f70();                                            // bought (items)
    int FUN_140db6fb0();
    int FUN_140db6fd0();
    CString FUN_140db6ff0();                                        // the price tag text
    int FUN_140db7060();                                            // sold out
    bool FUN_140db70a0(CStringW& strError);                         // can be bought now (fills the reason)
    __int64 FUN_140db8180();                        // sale price
    __int64 FUN_140db81a0();                        // original price
    void FUN_140db81c0();                                           // m_54 = max(m_5c - m_58, 0)
    unsigned FUN_140db8210();                                       // the most that can be bought at once
    int FUN_140db8400();                                            // the most the player can afford
    int FUN_140db8580(int nCount);                                  // pay nCount items; 1 when the payment can be made (exe: xor eax,eax / mov eax,1; callers test eax)
    bool FUN_140db8600();                                           // the star point event is running
    CString FUN_140db86d0();                                        // debug text

    int m_50, m_54, m_58, m_5c, m_60, m_64, m_68, m_6c;             // +0x50
    int m_70, m_74, m_78, m_7c, m_80, m_84, m_88, m_8c, m_90;       // +0x70
    int m_94;                                                       // +0x94
    CString m_98;                                                   // +0x98 the price tag
    __int64 m_a0;                                                   // +0xa0 sale price
    __int64 m_a8;                                                   // +0xa8 original price
    CString m_b0;                                                   // +0xb0 the category text
    unsigned m_b8;                                                  // +0xb8 pack size
    int m_bc;                                                       // +0xbc
    int m_c0;                                                       // +0xc0
    unsigned char m_c4;                                             // +0xc4
    MS2SvrPtr<CNpcShopBuyPeriod> m_c8;                              // +0xc8 the buy period
    Unk_ShopLifeRef m_d8;                                           // +0xd8 the item life (NpcShopItemLife)
};
MS2_CHECK_SIZE(CNpcShopProductCli, 0xe8);
MS2_CHECK_OFFSET(CNpcShopProductCli, m_98, 0x98);
MS2_CHECK_OFFSET(CNpcShopProductCli, m_a0, 0xa0);
MS2_CHECK_OFFSET(CNpcShopProductCli, m_b0, 0xb0);
MS2_CHECK_OFFSET(CNpcShopProductCli, m_c8, 0xc8);
MS2_CHECK_OFFSET(CNpcShopProductCli, m_d8, 0xd8);

class CNpcShopProductNewCli : public CNpcShopProductBase
{
public:
    CNpcShopProductNewCli();                                        // 0x140db87e0
    virtual ~CNpcShopProductNewCli();                               //  0 0x140db8b60 (??_G 0x140db8cc0)
    virtual int vfunc_1() { return m_item.m_nProductType; }         //  1 0x140db8d20
    virtual int vfunc_2() { return m_item.m_nProductKind; }         //  2 0x140db8d60

    void FUN_140db8840(CInPacket& in);                              // read the product

    CNpcShopItemNew m_item;                                         // +0x50
};
MS2_CHECK_SIZE(CNpcShopProductNewCli, 0x98);

class CNpcShopMeratItemCli : public CNpcShopMeratItemBase
{
public:
    CNpcShopMeratItemCli();                                         // 0x140db8920
    virtual ~CNpcShopMeratItemCli();                                //  0 0x140db8980 (??_G 0x140db8c00)
    virtual void vfunc_1(COutputStream* pOut) {}                    //  1 0x140db89e0
    virtual void vfunc_2(CInPacket* pIn);                           //  2 0x140db8a00

    void FUN_140db8ac0(MS2Ptr<CItem> spItem);                       // set the preview item
    MS2Ptr<CItem> FUN_140db8b10();                                  // a copy of the preview item

    MS2Ptr<CItem> m_30;                                             // +0x30
    int m_40;                                                       // +0x40 product type
};
MS2_CHECK_SIZE(CNpcShopMeratItemCli, 0x48);
