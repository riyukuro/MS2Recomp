// commonstruct slice A (0x14026ab50-0x1402709a0, minus the part owned by commonstruct.cpp). Sub-unit header.
// Class names are RTTI; member names are invented. FUN_ declarations below are template/ATL/STL helpers living in
// the later COMDAT region of the unit (0x14027c000-0x14028b8..), declared loosely until the integration step.
#pragma once
#include <afx.h>
#include <atltime.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/mstime.h"

// 8-byte iterator of the exe's list/map/vector instantiations.
struct Unk_It { void* p; };
MS2_CHECK_SIZE(Unk_It, 8);
// 24-byte iterator result buffer.
struct Unk_It24 { void* a; void* b; void* c; };
MS2_CHECK_SIZE(Unk_It24, 24);

class CIngredientInfo;
class CIngredientContainer;

// Intrusive smart pointer (16 bytes: unknown, pointer) to CIngredientInfo. Template COMDATs at 0x14027c9b0.. (later part).
class Unk_IngRef {
public:
    Unk_IngRef(int);                       // 0x14027c9f0
    Unk_IngRef(CIngredientInfo*);          // 0x14027ca10
    Unk_IngRef(const Unk_IngRef&);         // 0x14027c9b0
    ~Unk_IngRef();                         // 0x14027df70
    bool operator==(CIngredientInfo*) const;   // 0x14027ec60
    CIngredientInfo* operator->() const;       // 0x14027f2c0
    CIngredientInfo* FUN_14027f250() const;
    CIngredientInfo* FUN_140281f10() const;
    void* m_unknown; CIngredientInfo* m_p;
};
MS2_CHECK_SIZE(Unk_IngRef, 16);

// std::vector<Unk_IngRef> (24 bytes)
class Unk_IngVec {
public:
    Unk_IngVec() noexcept;                 // 0x14027d720
    ~Unk_IngVec();                         // 0x14027e480
    void FUN_14028a610() noexcept;         // clear
    void FUN_14028b3a0(size_t);            // reserve
    size_t FUN_14028b500();                // size
    void FUN_14028b330(Unk_IngRef&);       // push_back
    void FUN_14028b300(Unk_IngRef&);       // push_back (rvalue)
    Unk_IngRef* FUN_14028a0b0(size_t);
    Unk_IngRef* FUN_14028a0f0(size_t);
    Unk_IngRef* FUN_14027f1f0(size_t);
    Unk_IngRef* FUN_14027f220(size_t);
    bool FUN_14028a8c0();                  // empty
    Unk_IngRef* FUN_140289d60();
    Unk_IngRef* FUN_140289dc0();
    Unk_It* FUN_14028aa90(Unk_It*);        // end
    Unk_It* FUN_14028a260(Unk_It*);        // begin
    void FUN_14027c290(Unk_It24*, Unk_It, Unk_It, Unk_It);   // insert(range)
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_IngVec, 24);

class CIngredientInfo : public CPtred {
public:
    CIngredientInfo();                     // 0x14027d830
    CIngredientInfo(int a, int b, int c);  // 0x14027d7d0
    virtual ~CIngredientInfo();            // 0x14027e620
    void FUN_14026b1e0(COutputStream&);
    void FUN_14026b250(CInPacket&);
    bool FUN_14026b2f0(CIngredientInfo*);
    bool FUN_14026b350();
    void FUN_14026b3a0(COutputStream&);
    void FUN_14026b410(CInPacket&);
    unsigned FUN_14026b4b0();
    unsigned FUN_14026b500();
    int m_a, m_b, m_c;
};
MS2_CHECK_SIZE(CIngredientInfo, 0x28);
MS2_CHECK_OFFSET(CIngredientInfo, m_a, 0x18);

int* FUN_14026b540(int* out, int value);    // *out = value; return out
bool FUN_14026b560(int* id, Unk_IngRef ref);

// std::vector<CString> (24 bytes)
class Unk_StrVec {
public:
    Unk_StrVec();                          // 0x14027d6f0
    ~Unk_StrVec();                         // 0x14027e450
    size_t FUN_14028b4c0();
    CString* FUN_14027f1c0(size_t);
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_StrVec, 24);

class CIngredientContainer : public CPtred {
public:
    CIngredientContainer();                // 0x14026b5f0
    CIngredientContainer(size_t reserve);  // 0x14026b640
    CIngredientContainer(CIngredientContainer* other);   // 0x14026b6b0
    virtual ~CIngredientContainer();       // 0x14026b980
    bool FUN_14026b890(CIngredientContainer* other);
    void FUN_14026b9d0(const CStringW& text);
    void FUN_14026bbf0(int a, int b);
    void FUN_14026bca0(Unk_IngRef r);
    void FUN_14026bd10(int a, int b);
    Unk_IngRef FUN_14026bdc0(size_t index);
    Unk_IngRef FUN_14026be50(size_t index);
    size_t FUN_14026bee0();
    size_t FUN_14026bf10();
    bool FUN_14026bf40();
    bool FUN_14026bf70();
    void FUN_14026bfa0(size_t n);
    void FUN_14026bfd0(COutputStream& out);
    void FUN_14026c0b0(CInPacket& in);
    Unk_IngVec* FUN_14026c230();
    void FUN_14026c250(CIngredientContainer* other);
    Unk_IngRef FUN_14026c450(unsigned key);
    Unk_IngVec m_items;
};
MS2_CHECK_SIZE(CIngredientContainer, 0x30);

// Smart pointer to a CIngredientContainer inside an unrecovered holder class (pointer at +0x18).
class Unk_IngContRef {
public:
    CIngredientContainer* FUN_140281f00();
    void* m_unknown; CIngredientContainer* m_p;
};
MS2_CHECK_SIZE(Unk_IngContRef, 16);
class Unk_IngHolder {
public:
    bool FUN_14026c550(Unk_IngHolder* other);
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
    Unk_IngContRef m_container;
};

// std::map<unsigned,int> (16 bytes) and std::vector<ItemEntity> (24 bytes)
class Unk_RewardMap {
public:
    Unk_RewardMap();                       // 0x14027d600
    ~Unk_RewardMap();                      // 0x14027e3d0
    size_t FUN_14028b3f0();                // size
    Unk_It* FUN_14028a910(Unk_It*);        // end
    Unk_It* FUN_14028a130(Unk_It*);        // begin
    int& FUN_14027f180(unsigned&);         // operator[]
    Unk_It* FUN_14028adf0(Unk_It*, int*);  // find
    Unk_It* FUN_14028ad10(Unk_It*, int*);  // find
    Unk_It* FUN_14028a970(Unk_It*);        // end (const)
    void FUN_14028a410();                  // clear
    void* m_head; size_t m_size;
};
MS2_CHECK_SIZE(Unk_RewardMap, 16);
class Unk_ItemVec {
public:
    Unk_ItemVec() noexcept;                         // 0x14027d6c0
    ~Unk_ItemVec() noexcept;                        // 0x14027e420
    size_t FUN_14028b470();                // size
    void FUN_14028b2a0(const ItemEntity&);       // push_back
    Unk_It* FUN_14028b360(Unk_It*);        // last element iterator
    Unk_It* FUN_14028aa30(Unk_It*);        // end
    Unk_It* FUN_14028a200(Unk_It*);        // begin
    void FUN_14028a590();                  // clear
    void* m_begin; void* m_end; void* m_cap;
};
MS2_CHECK_SIZE(Unk_ItemVec, 24);

class DungeonRewardInfo : public CPtred {
public:
    DungeonRewardInfo();                   // 0x14026c5b0
    virtual ~DungeonRewardInfo();          // 0x14026c610
    void FUN_14026c660(COutputStream& out);
    void FUN_14026c900(CInPacket& in);
    unsigned FUN_14026cbf0();
    unsigned FUN_14026cc70();
    unsigned FUN_14026ccf0();
    unsigned FUN_14026cd70(unsigned key);
    void FUN_14026cdf0();
    bool FUN_14026ce30();
    void FUN_14026ce80(unsigned key, int delta);
    Unk_RewardMap m_rewards;
    Unk_ItemVec m_items;
};
MS2_CHECK_SIZE(DungeonRewardInfo, 0x40);
MS2_CHECK_OFFSET(DungeonRewardInfo, m_items, 0x28);

class WeddingHallReservationFee : public CPtred {
public:
    WeddingHallReservationFee();           // 0x14026e700
    virtual ~WeddingHallReservationFee();  // 0x14026e750
    WeddingHallReservationFee& FUN_14026e780(const WeddingHallReservationFee& other);
    void FUN_14026e7b0();
    void FUN_14026e7e0(const WeddingHallReservationFee& other);
    void FUN_14026e860(const WeddingHallReservationFee& other);
    void FUN_14026e8c0(COutputStream& out);
    void FUN_14026e940(CInputStream& in);
    __int64 m_values[4];
    __int64 m_total;
};
MS2_CHECK_SIZE(WeddingHallReservationFee, 0x40);

// Smart pointer (16 bytes) to NpcShopItemLife.
class NpcShopItemLife;
class Unk_ShopLifeRef {
public:
    Unk_ShopLifeRef(NpcShopItemLife*);                 // 0x14027cd20
    Unk_ShopLifeRef(Unk_ShopLifeRef&&);                // 0x14027ccf0
    Unk_ShopLifeRef();                                 // 0x14052c0d0 (npcshopproductbase.cpp)
    Unk_ShopLifeRef(const Unk_ShopLifeRef&);           // 0x14052c090 (npcshopproductbase.cpp)
    ~Unk_ShopLifeRef();                                // 0x14027e150
    NpcShopItemLife* operator->() const;               // 0x14027f340
    Unk_ShopLifeRef(int) { m_p = 0; }                  // 0x1406ee480 (inline COMDAT, commonfiles\npcshopdata.cpp)
    Unk_ShopLifeRef& operator=(const Unk_ShopLifeRef&); // 0x14052caa0
    operator NpcShopItemLife*() const;                 // 0x14052ce00
    NpcShopItemLife& operator*() const { return *m_p; } // 0x1406f24f0 (inline COMDAT, commonfiles\npcshopdata.cpp)
    void* m_unknown; NpcShopItemLife* m_p;
};
MS2_CHECK_SIZE(Unk_ShopLifeRef, 16);

class Unk_UIntArr {
public:
    Unk_UIntArr(); ~Unk_UIntArr();
    size_t FUN_140186270();
    unsigned* FUN_140184510(size_t);
    void* m_data; size_t m_size, m_alloc, m_grow;
};
MS2_CHECK_SIZE(Unk_UIntArr, 32);
class Unk_IntArr {
public:
    Unk_IntArr(); ~Unk_IntArr();
    size_t FUN_140186260();
    int* FUN_1401844d0(size_t);
    void* m_data; size_t m_size, m_alloc, m_grow;
};
MS2_CHECK_SIZE(Unk_IntArr, 32);

class NpcShopItemLife : public CPtred {
public:
    NpcShopItemLife();                     // 0x14026e9b0
    virtual ~NpcShopItemLife();            // 0x14027e8e0
    bool FUN_14026ea20(NpcShopItemLife* other);
    Unk_ShopLifeRef FUN_14026eab0();
    bool FUN_14026ebc0(void* xml);
    void FUN_14026ee70(COutputStream& out);
    void FUN_14026ef20(CInPacket& in);
    bool FUN_14026f000();
    bool FUN_14026f040(const CMsTime& now);
    bool FUN_14026f080(const CMsTime& now);
    bool FUN_14026f0f0();
    __int64 FUN_14026f170();
    int m_type, m_value;
    CMsTime m_time;
    bool m_onlyVisible;
};
MS2_CHECK_SIZE(NpcShopItemLife, 0x38);
MS2_CHECK_OFFSET(NpcShopItemLife, m_time, 0x20);

class ItemDropItemLife : public CPtred {
public:
    ItemDropItemLife();                    // 0x14026f220
    virtual ~ItemDropItemLife();           // 0x14027e8c0
    bool FUN_14026f290(void* xml);
    __int64 FUN_14026f520();
    bool FUN_14026f5d0();
    int m_type, m_value;
    CMsTime m_time;
};
MS2_CHECK_SIZE(ItemDropItemLife, 0x30);

class CUserChangeableItemHistory : public CPtred {
public:
    CUserChangeableItemHistory();          // 0x14026f650
    virtual ~CUserChangeableItemHistory(); // 0x14027e7a0
    virtual void vfunc_1();
    virtual void vfunc_2(COutputStream* out);
    virtual void vfunc_3(CInPacket* in);
    __int64 m_18, m_20, m_28, m_30;
    int m_38, m_3c, m_40;
    __int64 m_48;
};
MS2_CHECK_SIZE(CUserChangeableItemHistory, 0x50);

// Smart pointer to CUserChangeableItemHistory.
class Unk_HistRef {
public:
    Unk_HistRef(int);                              // 0x14027cc10
    Unk_HistRef(const Unk_HistRef&);               // 0x14027cc30
    Unk_HistRef(Unk_HistRef&&);                    // 0x14027cbe0
    ~Unk_HistRef();                                // 0x14027e060
    Unk_HistRef& FUN_14027eab0(Unk_HistRef&);      // assign
    bool operator==(CUserChangeableItemHistory*) const;   // 0x14027ed20
    CUserChangeableItemHistory* operator->() const;       // 0x14027f300
    void* m_unknown; CUserChangeableItemHistory* m_p;
};
MS2_CHECK_SIZE(Unk_HistRef, 16);

// Scoped lock helper (ctor 0x1401b4ec0, dtor 0x1401b5120).
class Unk_HistLock {
public:
    Unk_HistLock(CLockCriticalSection&, int);
    ~Unk_HistLock();
    void* m_p;
};

// std::list<Unk_HistRef> (16 bytes)
class Unk_HistList {
public:
    Unk_HistList();                        // 0x14027d5e0
    ~Unk_HistList();                       // 0x14027e3a0
    void FUN_14028a4b0() noexcept;                // clear
    Unk_It* FUN_14028a1a0(Unk_It*);        // begin
    Unk_It* FUN_14028a9d0(Unk_It*);        // end
    Unk_It* FUN_14028aca0(Unk_It*, Unk_It);// erase
    Unk_HistRef* FUN_14028aef0();          // front (returns pointer to element)
    void FUN_14028b260(Unk_HistRef&);      // push_back
    void FUN_140289d20(Unk_It*);           // begin
    void FUN_140289d80(Unk_It*);           // end
    __int64 FUN_14028b410();               // size
    void* m_head; size_t m_size;
};
MS2_CHECK_SIZE(Unk_HistList, 16);

class CChangeableHistoryInfo : public CPtred {
public:
    CChangeableHistoryInfo(int a, int b);  // 0x14026f9c0
    virtual ~CChangeableHistoryInfo();     // 0x14026fa50
    void FUN_14026fab0();
    int FUN_14026fc00(int mode, __int64 id);
    void FUN_14026fda0(Unk_HistRef entry);
    bool FUN_14026fea0(__int64 id);
    Unk_HistRef FUN_14026ffd0();
    CLockCriticalSection m_lock;
    int m_48, m_4c, m_total;
    int m_54;
    Unk_HistList m_list;
};
MS2_CHECK_SIZE(CChangeableHistoryInfo, 0x68);
MS2_CHECK_OFFSET(CChangeableHistoryInfo, m_lock, 0x18);
MS2_CHECK_OFFSET(CChangeableHistoryInfo, m_list, 0x58);

class ChangeableProductInfo;
class Unk_ProdRef {
public:
    ~Unk_ProdRef();                                // 0x14027e0c0
    ChangeableProductInfo* operator->() const;     // 0x14027f320
    void* m_unknown; ChangeableProductInfo* m_p;
};
class ChangeableProductInfo : public CPtred {
public:
    ChangeableProductInfo();               // 0x140270170
    virtual ~ChangeableProductInfo();      // 0x14027e7e0
    void FUN_140270230(Unk_ProdRef other);
    bool FUN_140270330(const CMsTime& now);
    bool FUN_1402703a0(const CMsTime& now);
    bool FUN_140270450(const CMsTime& now);
    int m_18, m_1c, m_20, m_24;
    CMsTime m_28, m_38, m_48;
    bool m_58;
    int m_5c;
};
MS2_CHECK_SIZE(ChangeableProductInfo, 0x60);

class HomeBlockInfo : public CPtred {
public:
    HomeBlockInfo();                       // 0x1402704b0
    virtual ~HomeBlockInfo();              // 0x14027e820
    void FUN_140270530();
    void FUN_1402705d0(COutputStream& out);
    void FUN_1402706f0(CInPacket& in);
    __int64 m_18, m_20, m_28;
    CString m_30;
    short m_38;
    int m_3c, m_40;
    CString m_48, m_50;
};
MS2_CHECK_SIZE(HomeBlockInfo, 0x58);

// item table singleton (template COMDAT 0x140281980) and lookup
class Unk_IngTable;
Unk_IngTable* FUN_140281980();
unsigned FUN_1405575b0(Unk_IngTable*, int);
unsigned FUN_140557640(Unk_IngTable*, CString*);

// helpers of other units
bool FUN_14026aeb0(const ItemEntity&, const ItemEntity&);
void FUN_140274fc0(const CStringW&, Unk_UIntArr*, const wchar_t*);
void FUN_140275180(const CStringW&, Unk_StrVec*, const wchar_t*);
void FUN_140275080(CString&, Unk_StrVec*, const char*);
int FUN_1407181d0(CString*);
void FUN_140177de0(CString&, Unk_IntArr*, const char*);
void FUN_1408733e0(void*, const char*, CString&);
void FUN_1402767f0(void*, const char*, int&);
void FUN_1408730a0(void*, const char*, bool&);
void FUN_140873220(void*, const char*, unsigned int&);
void FUN_1408731e0(void*, const char*, int&);
__int64 FUN_140869440();
__int64 FUN_14086b950(const __int64&, int);
__int64 FUN_14086ba60(const __int64&, int);
bool FUN_14027ef80(Unk_It*, Unk_It*);
bool FUN_14027efc0(Unk_It*, Unk_It*);
bool FUN_14027ee20(Unk_It*, Unk_It*);
bool FUN_14027f000(Unk_It*, Unk_It*);
bool FUN_14027ef00(Unk_It*, Unk_It*);
bool FUN_14027ef40(Unk_It*, Unk_It*);
Unk_IngRef* FUN_14027f490(Unk_It*);
void* FUN_14027f410(Unk_It*);
void* FUN_14027f350(Unk_It*);
void* FUN_14027f450(Unk_It*);
ItemEntity* FUN_14027f4b0(Unk_It*);
Unk_HistRef* FUN_14027f3b0(Unk_It*);
Unk_HistRef* FUN_14027f3f0(Unk_It*);
void FUN_14027f600(Unk_It*);
void FUN_14027f6b0(Unk_It*);
void FUN_14027f550(Unk_It*);
void FUN_14027f590(Unk_It*);
void FUN_14027bf30(Unk_It*, Unk_It, Unk_It, int);
void FUN_14027c480(Unk_It*, Unk_It, int);
