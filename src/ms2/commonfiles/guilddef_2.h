// Guild NPC shop classes shared by guilddef.cpp#2 (methods) and #4 (inline ctors/dtors). Not an original header.
#pragma once
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/placeholder/ascript.h"   // C3: MS2Ptr (NPC shop records)
#include <map>
#include <vector>
class CInPacket;
// Product slot of an NPC shop: item id, rank, price, bought count.
class CNpcShopProductProxy : public CPtred {
public:
    CNpcShopProductProxy():f18(0),f1c(0),f20(0),f24(0){}
    void Write(COutputStream& out);
    void Read(CInPacket* packet);
    int f18,f1c,f20,f24;
};
MS2_CHECK_SIZE(CNpcShopProductProxy,0x28);
class CGuildNpcShop : public CPtred {
public:
    CGuildNpcShop():f18(0),f20(0),f28(0){}
    virtual ~CGuildNpcShop(){}
    bool IsExpired(__int64 now);
    void ClearProducts();
    MS2Ptr<CNpcShopProductProxy> AddProduct(int itemId,int rank,int price);
    MS2Ptr<CNpcShopProductProxy> FindProduct(int itemId,int rank,int price);
    int FindProductIndex(int itemId,int rank,int price);
    void Write(COutputStream& out);
    void Read(CInPacket* packet);
    unsigned f18; __int64 f20,f28;
    std::vector<MS2Ptr<CNpcShopProductProxy>> products;
};
MS2_CHECK_SIZE(CGuildNpcShop,0x48);
// Purchase request/offer record (0x30).
class Unk_GuildShopOffer : public CPtred {
public:
    Unk_GuildShopOffer():f18(0),f1c(0),f20(0),f28(0){}
    virtual ~Unk_GuildShopOffer(){}
    void Write(COutputStream& out);
    void Read(CInPacket* packet);
    int f18; unsigned f1c; unsigned f20; __int64 f28;
};
MS2_CHECK_SIZE(Unk_GuildShopOffer,0x30);
class CGuildNpcShopMgr : public CPtred {
public:
    CGuildNpcShopMgr(){}
    virtual ~CGuildNpcShopMgr(){}
    MS2Ptr<CGuildNpcShop> CreateShop(unsigned id,__int64 time);
    MS2Ptr<CGuildNpcShop> GetShop(unsigned id);
    MS2Ptr<CGuildNpcShop> GetOrCreateShop(unsigned id);
    int FUN_1404d89e0(ItemEntity* item,Unk_GuildShopOffer* offer,bool* created);
    void Write(COutputStream& out);
    void Read(CInPacket* packet);
    void ReadShop(unsigned id,CInPacket* packet);
    void FUN_1404d9060(unsigned id,CInPacket* packet);
    std::map<unsigned,MS2Ptr<CGuildNpcShop>> shops;
};
MS2_CHECK_SIZE(CGuildNpcShopMgr,0x28);
int FUN_1404d9330(const CString& text);
