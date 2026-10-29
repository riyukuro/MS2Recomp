// Guild NPC shop classes shared by guilddef.cpp#2 (methods) and #4 (inline ctors/dtors). Not an original header.
#pragma once
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include <map>
#include <vector>
class CInPacket;
// Product slot of an NPC shop: item id, rank, price, bought count.
class CNpcShopProductProxy : public CPtred {
public:
    CNpcShopProductProxy():f18(0),f1c(0),f20(0),f24(0){}
    void FUN_1404d7f20(COutputStream& out);
    void FUN_1404d7fa0(CInPacket* packet);
    int f18,f1c,f20,f24;
};
MS2_CHECK_SIZE(CNpcShopProductProxy,0x28);
class CGuildNpcShop : public CPtred {
public:
    CGuildNpcShop():f18(0),f20(0),f28(0){}
    virtual ~CGuildNpcShop(){}
    bool FUN_1404d8070(__int64 now);
    void FUN_1404d80a0();
    Unk_PayloadPtr<CNpcShopProductProxy> FUN_1404d80d0(int itemId,int rank,int price);
    Unk_PayloadPtr<CNpcShopProductProxy> FUN_1404d81e0(int itemId,int rank,int price);
    int FUN_1404d82a0(int itemId,int rank,int price);
    void FUN_1404d83e0(COutputStream& out);
    void FUN_1404d8520(CInPacket* packet);
    unsigned f18; __int64 f20,f28;
    std::vector<Unk_PayloadPtr<CNpcShopProductProxy>> products;
};
MS2_CHECK_SIZE(CGuildNpcShop,0x48);
// Purchase request/offer record (0x30).
class Unk_GuildShopOffer : public CPtred {
public:
    Unk_GuildShopOffer():f18(0),f1c(0),f20(0),f28(0){}
    virtual ~Unk_GuildShopOffer(){}
    void FUN_1404d91e0(COutputStream& out);
    void FUN_1404d9260(CInPacket* packet);
    int f18; unsigned f1c; unsigned f20; __int64 f28;
};
MS2_CHECK_SIZE(Unk_GuildShopOffer,0x30);
class CGuildNpcShopMgr : public CPtred {
public:
    CGuildNpcShopMgr(){}
    virtual ~CGuildNpcShopMgr(){}
    Unk_PayloadPtr<CGuildNpcShop> FUN_1404d86e0(unsigned id,__int64 time);
    Unk_PayloadPtr<CGuildNpcShop> FUN_1404d87f0(unsigned id);
    Unk_PayloadPtr<CGuildNpcShop> FUN_1404d88e0(unsigned id);
    int FUN_1404d89e0(ItemEntity* item,Unk_GuildShopOffer* offer,bool* created);
    void FUN_1404d8d50(COutputStream& out);
    void FUN_1404d8e80(CInPacket* packet);
    void FUN_1404d8ff0(unsigned id,CInPacket* packet);
    void FUN_1404d9060(unsigned id,CInPacket* packet);
    std::map<unsigned,Unk_PayloadPtr<CGuildNpcShop>> shops;
};
MS2_CHECK_SIZE(CGuildNpcShopMgr,0x28);
int FUN_1404d9330(const CString& text);
