// blackmarketitemoption.h - the black market ("BlackMarket") data classes (RTTI names CBlackMarketItemOption,
// CDBBlackMarketProductInfo, CBlackMarketProduct, CBlackMarketSchCond, CBlackMarketTable, CBlackMarketUtil): one
// product of the player auction house with its price/stock bookkeeping, the search condition sent to the server and
// the client table read from Table/blackMarketTable.xml (tab tree, option -> stat table links). Header name assumed;
// member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/guilddef_1.h"

class CInPacket;
class CInputStream;
class COutputStream;
class CItem;

struct Unk_BmNewTag
{
    explicit Unk_BmNewTag(int);                             // 0x1401b7b90 (returns its this, no code)
};

CPtred* FUN_1401ba820(CPtred* p);                           // marks a freshly allocated object (sets the count to 1)

// 16-byte intrusive smart pointer (RTTI TPtr<T>; field 0 unused, field 1 the pointee) to a CPtred-derived object.
// Members are defined below the class so that they stay out-of-line COMDATs like the exe's.
template <class T>
class Unk_BmPtr
{
public:
    Unk_BmPtr();
    Unk_BmPtr(int);
    Unk_BmPtr(decltype(nullptr));                           // `Unk_BmPtr p(nullptr)`: the dummy argument is a qword (npcdata.cpp GetRegionSpawnData)
    Unk_BmPtr(T* p);                                        // raw pointer + AddRef
    Unk_BmPtr(const Unk_BmNewTag&);                         // fresh object
    Unk_BmPtr(const Unk_BmPtr& o);                          // copy + AddRef
    Unk_BmPtr(Unk_BmPtr&& o);                               // move (a returned local)
    ~Unk_BmPtr();
    Unk_BmPtr& operator=(const Unk_BmPtr& o);
    Unk_BmPtr& operator=(const Unk_BmNewTag&);
    // `Unk_BmPtr tmp(p); swap` - assignment from a raw pointer (0x141746fd0 for T = UserUGCMapInfo, scenestategame).
    // A named member, not operator=(T*), so that existing `p = q` / `p = 0` call sites keep their overloads.
    Unk_BmPtr& AssignRaw(T* p);
    T* get() const;
    T* operator->() const;
    T& operator*() const;
    bool operator==(T* p) const;
    bool operator!() const;                                 // 0x140f17990 for T = CBlackMarketTable::StatInfo (uiblackmarketpage.cpp)

private:
    void AddRef() const;
    void Make();
    void Release();
    static T* Allocate(void*);
    static T* Create(void*);
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    static void Ref(CPtred* p);
    void* m_00;
    T* m_p;
};

template <class T> Unk_BmPtr<T>::Unk_BmPtr() { m_p = 0; }
template <class T> Unk_BmPtr<T>::Unk_BmPtr(int) { m_p = 0; }
template <class T> Unk_BmPtr<T>::Unk_BmPtr(decltype(nullptr)) { m_p = 0; }
template <class T> Unk_BmPtr<T>::Unk_BmPtr(T* p) { m_p = p; AddRef(); }
template <class T> Unk_BmPtr<T>::Unk_BmPtr(const Unk_BmNewTag&) { m_p = 0; Make(); }
template <class T> Unk_BmPtr<T>::Unk_BmPtr(const Unk_BmPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_BmPtr<T>::Unk_BmPtr(Unk_BmPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_BmPtr<T>::~Unk_BmPtr() { Release(); }
template <class T> Unk_BmPtr<T>& Unk_BmPtr<T>::operator=(const Unk_BmPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_BmPtr<T>& Unk_BmPtr<T>::operator=(const Unk_BmNewTag&) { Make(); return *this; }
template <class T> Unk_BmPtr<T>& Unk_BmPtr<T>::AssignRaw(T* p)
{
    Unk_BmPtr tmp(p);
    T* pOld = m_p;
    m_p = tmp.m_p;
    tmp.m_p = pOld;
    return *this;
}
template <class T> T* Unk_BmPtr<T>::get() const { return m_p; }
template <class T> T* Unk_BmPtr<T>::operator->() const { return m_p; }
template <class T> T& Unk_BmPtr<T>::operator*() const { return *m_p; }
template <class T> bool Unk_BmPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> bool Unk_BmPtr<T>::operator!() const { return m_p == 0; }
template <class T> void Unk_BmPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_BmPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_BmPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> T* Unk_BmPtr<T>::Allocate(void*) { return new T(); }
template <class T> T* Unk_BmPtr<T>::Create(void*) { return static_cast<T*>(FUN_1401ba820(Allocate(0))); }
template <class T> void Unk_BmPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_BmPtr<T>::AddRefImpl(void*) const { Ref(m_p); }
template <class T> void Unk_BmPtr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) { Ref(m_p); CPtred::DeletePtred(m_p); }
}

// The same pointer to a boxed value (TPtredDummy<T>: a CPtred header 0x18 bytes before the pointee).
template <class T>
class Unk_BmBoxPtr
{
public:
    Unk_BmBoxPtr();
    Unk_BmBoxPtr(int);
    Unk_BmBoxPtr(const Unk_BmNewTag&);
    Unk_BmBoxPtr(const Unk_BmBoxPtr& o);
    Unk_BmBoxPtr(Unk_BmBoxPtr&& o);
    ~Unk_BmBoxPtr();
    Unk_BmBoxPtr& operator=(const Unk_BmBoxPtr& o);
    Unk_BmBoxPtr& operator=(const Unk_BmNewTag&);
    Unk_BmBoxPtr& operator=(int);
    T* get() const;
    T* operator->() const;
    T& operator*() const;
    bool operator==(T* p) const;
    bool operator!() const;

private:
    void AddRef() const;
    void Make();
    void Release();
    static TPtredDummy<T>* Allocate(void*);
    static T* Value(TPtredDummy<T>* p);
    static TPtredDummy<T>* Owner(T* p);
    static void Ref(CPtred* p);
    static T* Create(void*);
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    void* m_00;
    T* m_p;
};

template <class T> Unk_BmBoxPtr<T>::Unk_BmBoxPtr() { m_p = 0; }
template <class T> Unk_BmBoxPtr<T>::Unk_BmBoxPtr(int) { m_p = 0; }
template <class T> Unk_BmBoxPtr<T>::Unk_BmBoxPtr(const Unk_BmNewTag&) { m_p = 0; Make(); }
template <class T> Unk_BmBoxPtr<T>::Unk_BmBoxPtr(const Unk_BmBoxPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_BmBoxPtr<T>::Unk_BmBoxPtr(Unk_BmBoxPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_BmBoxPtr<T>::~Unk_BmBoxPtr() { Release(); }
template <class T> Unk_BmBoxPtr<T>& Unk_BmBoxPtr<T>::operator=(const Unk_BmBoxPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_BmBoxPtr<T>& Unk_BmBoxPtr<T>::operator=(const Unk_BmNewTag&) { Make(); return *this; }
template <class T> Unk_BmBoxPtr<T>& Unk_BmBoxPtr<T>::operator=(int) { Release(); return *this; }
template <class T> T* Unk_BmBoxPtr<T>::get() const { return m_p; }
template <class T> T* Unk_BmBoxPtr<T>::operator->() const { return m_p; }
template <class T> T& Unk_BmBoxPtr<T>::operator*() const { return *m_p; }
template <class T> bool Unk_BmBoxPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> bool Unk_BmBoxPtr<T>::operator!() const { return m_p == 0; }
template <class T> void Unk_BmBoxPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_BmBoxPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_BmBoxPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> TPtredDummy<T>* Unk_BmBoxPtr<T>::Allocate(void*) { return new TPtredDummy<T>(); }
template <class T> T* Unk_BmBoxPtr<T>::Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
template <class T> TPtredDummy<T>* Unk_BmBoxPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> void Unk_BmBoxPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> T* Unk_BmBoxPtr<T>::Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
template <class T> void Unk_BmBoxPtr<T>::AddRefImpl(void*) const { Ref(Owner(m_p)); }
template <class T> void Unk_BmBoxPtr<T>::ReleaseImpl(void*)
{
    CPtred* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
}

// A line of the black market's searchable options (0x38 bytes; the vftable has the deleting dtor only).
class CBlackMarketItemOption : public CPtred
{
public:
    CBlackMarketItemOption();               // 0x1401bdae0
    virtual ~CBlackMarketItemOption();      // 0x1401bdb30

    void Reset();                           // 0x1401bdb80

    unsigned long long m_qw18;              // +0x18
    unsigned long long m_qw20;              // +0x20
    unsigned int m_dw28;                    // +0x28
    unsigned int m_dw2c;                    // +0x2c
    unsigned int m_dw30;                    // +0x30
    unsigned int m_pad34;
};
MS2_CHECK_SIZE(CBlackMarketItemOption, 0x38);

// The product row delivered by the DB (0x98 bytes, vftable: the deleting dtor only).
class CDBBlackMarketProductInfo : public CPtred
{
public:
    CDBBlackMarketProductInfo();            // 0x1401bd920
    virtual ~CDBBlackMarketProductInfo();   // 0x1401bd980

    void Reset();                           // 0x1401bd9e0

    unsigned long long m_qw18;              // +0x18
    unsigned long long m_qw20;              // +0x20
    unsigned int m_dw28;                    // +0x28
    unsigned int m_dw2c;                    // +0x2c
    unsigned int m_dw30;                    // +0x30
    unsigned int m_dw34;                    // +0x34
    unsigned int m_dw38;                    // +0x38
    unsigned int m_dw3c;                    // +0x3c
    Unk_GuildArray m_list;                  // +0x40 byte array wrapper (shared with the guild / buddy records)
    unsigned long long m_qw60;              // +0x60
    unsigned long long m_qw68;              // +0x68
    unsigned long long m_qw70;              // +0x70
    unsigned long long m_qw78;              // +0x78
    unsigned long long m_qw80;              // +0x80
    unsigned long long m_qw88;              // +0x88
    unsigned int m_dw90;                    // +0x90
    unsigned int m_dw94;                    // +0x94
};
MS2_CHECK_SIZE(CDBBlackMarketProductInfo, 0x98);
MS2_CHECK_OFFSET(CDBBlackMarketProductInfo, m_list, 0x40);

// The unit-local view of the item data record behind an item (CItemData): only the group at +0x138 is read here.
class Unk_BmItemData : public CPtred
{
public:
    unsigned char m_pad18[0x120];
    unsigned int m_nGroup;                  // +0x138
};
MS2_CHECK_OFFSET(Unk_BmItemData, m_nGroup, 0x138);

// One product listed on the black market (at least 0x90 bytes, vftable: the deleting dtor only).
class CBlackMarketProduct : public CPtred
{
public:
    CBlackMarketProduct();                  // 0x1401bdbd0
    virtual ~CBlackMarketProduct();         // 0x1401bdc30

    void Reset();                           // 0x1401bdc90
    void Write(COutputStream* pStream);     // 0x1401bdd80
    void Read(CInPacket* pPacket);          // 0x1401bdf60
    long long TotalPrice();                 // 0x1401be2f0 count * unit price
    long long PriceFor(int nCount);         // 0x1401be310
    unsigned long long GetState(bool bLike);    // 0x1401be330 2 = open, 3 = expired, 4 / 5 = already used
    int GetRemain();                        // 0x1401be3b0 count - bought
    void SetQw78(unsigned long long qw);    // 0x1401be3d0
    unsigned int RollCount();               // 0x1401be3f0 a random purchase count within the remaining stock

    unsigned long long m_qw18;              // +0x18
    unsigned long long m_qw20;              // +0x20
    unsigned long long m_qw28;              // +0x28
    long long m_nExpire;                    // +0x30 end of the sale
    MS2Ptr<CItem> m_item;                   // +0x38
    int m_nCount;                           // +0x48
    int m_nBought;                          // +0x4c
    long long m_nUnitPrice;                 // +0x50
    unsigned long long m_qw58;              // +0x58
    int m_n60;                              // +0x60
    int m_pad64;
    unsigned long long m_qw68;              // +0x68
    unsigned long long m_qw70;              // +0x70
    unsigned long long m_qw78;              // +0x78
    int m_nStateA;                          // +0x80
    int m_nStateB;                          // +0x84
    int m_n88;                              // +0x88
    int m_n8c;                              // +0x8c
};
MS2_CHECK_OFFSET(CBlackMarketProduct, m_item, 0x38);
MS2_CHECK_OFFSET(CBlackMarketProduct, m_n8c, 0x8c);

// The search condition of the black market window (0x80 bytes, vftable: the deleting dtor only).
class CBlackMarketSchCond : public CPtred
{
public:
    CBlackMarketSchCond();                  // 0x1401be4a0
    CBlackMarketSchCond(CInPacket* pPacket);    // 0x1401be500
    virtual ~CBlackMarketSchCond();         // 0x1401be570

    void Reset();                           // 0x1401be5d0
    void CopyFrom(const CBlackMarketSchCond* pOther);   // 0x1401be710
    void Write(COutputStream* pStream);     // 0x1401be8d0
    void Read(CInPacket* pPacket);          // 0x1401be900
    void WriteStream(COutputStream* pStream);   // 0x1401be950
    void ReadStream(CInputStream* pStream);     // 0x1401beba0
    int GetLevelBand();                     // 0x1401bee10 (level - 1) / 10 of the lower level, -1 when none
    int GetBandMin();                       // 0x1401bee60
    int GetBandMax();                       // 0x1401beeb0
    int GetLimit();                         // 0x1401bef00
    int IsEqual(const CBlackMarketSchCond* pOther);    // 0x1401bef60
    int Compact();                         // 0x1401bf1d0 moves the used price ranges to the front

    unsigned int m_dw18;                    // +0x18
    unsigned int m_dw1c;                    // +0x1c
    unsigned int m_dw20;                    // +0x20
    unsigned int m_dw24;                    // +0x24
    unsigned int m_dw28;                    // +0x28
    unsigned int m_dw2c;                    // +0x2c
    unsigned int m_dw30;                    // +0x30
    unsigned int m_dw34;                    // +0x34
    unsigned int m_dw38;                    // +0x38
    unsigned int m_dw3c;                    // +0x3c
    CStringW m_strName;                     // +0x40
    unsigned int m_dw48;                    // +0x48
    unsigned int m_dw4c;                    // +0x4c
    unsigned int m_dw50;                    // +0x50
    unsigned int m_dw54;                    // +0x54
    unsigned int m_dw58;                    // +0x58
    unsigned int m_dw5c;                    // +0x5c
    unsigned int m_dw60;                    // +0x60
    unsigned int m_aMin[3];                 // +0x64
    unsigned int m_aMax[3];                 // +0x70
};
MS2_CHECK_OFFSET(CBlackMarketSchCond, m_strName, 0x40);
MS2_CHECK_OFFSET(CBlackMarketSchCond, m_aMin, 0x64);
MS2_CHECK_OFFSET(CBlackMarketSchCond, m_aMax, 0x70);

class Unk_140165cf0;    // xml element (declared where the loader is)

// RTTI CBlackMarketTable, 0x120 bytes: TSingleton at +0, the CCacheData base at +8 (path of the loaded file),
// CValidData at +0x30 (vftables 0x142cedee0 / 0x142cedef0 / 0x142cedf00, each only the deleting destructor).
class CBlackMarketTable : public TSingleton<CBlackMarketTable>, public CCacheData, public CValidData<CBlackMarketTable>
{
public:
    // A <stat> row of a stat table (0x38 bytes).
    class StatInfo : public CPtred
    {
    public:
        StatInfo();                     // 0x1401c5540
        virtual ~StatInfo();            // 0x1401c5980

        int m_nId;                      // +0x18 stat id (-1 none)
        CStringW m_strName;             // +0x20
        int m_nKind;                    // +0x28 1 when the name is a string id, 0 for a stat-name
        int m_nPercent;                 // +0x2c "percent"
        float m_fDefault;               // +0x30 "default" (a float attribute: the ctor stores 0.0f, read by the float query 0x140873a50)
    };
    MS2_CHECK_SIZE(StatInfo, 0x38);

    // A <tab> row of the tab tree (0x70 bytes) with its child tabs.
    class TabInfo;
    typedef Unk_BmPtr<TabInfo> TabPtr;
    typedef ATL::CAtlList<TabPtr> TabList;
    class TabInfo : public CPtred
    {
    public:
        TabInfo();                      // 0x1401c55b0
        virtual ~TabInfo();             // 0x1401c59b0

        CStringW m_strName;             // +0x18 localized tab name (string id "name")
        int m_nPriority;                // +0x20 "priority"
        CStringA m_strCategory;         // +0x28 "category" (comma separated item categories)
        int m_nId;                      // +0x30 "id"
        int m_nOptionId;                // +0x34 "option_id"
        bool m_bAutoCompleteName;       // +0x38 "auto_complete_name"
        bool m_bShowIncludeLowTab;      // +0x39 "showIncludeLowTab"
        TabList m_children;             // +0x40
    };
    MS2_CHECK_SIZE(TabInfo, 0x70);

    typedef Unk_BmPtr<StatInfo> StatPtr;
    typedef ATL::CAtlArray<StatPtr> StatArray;
    typedef ATL::CAtlArray<unsigned int> IdArray;
    typedef Unk_BmBoxPtr<TabList> TabListPtr;
    typedef Unk_BmBoxPtr<StatArray> StatArrayPtr;
    typedef Unk_BmBoxPtr<IdArray> IdArrayPtr;
    typedef ATL::CAtlMap<unsigned int, TabPtr> TabMap;
    typedef ATL::CAtlMap<unsigned int, IdArrayPtr> OptionMap;
    typedef ATL::CAtlMap<unsigned int, StatArrayPtr> StatTableMap;

    CBlackMarketTable();                // 0x1401c3aa0
    virtual ~CBlackMarketTable();       // 0x1401c3cc0

    void Load();                        // 0x1401c3da0 Table/blackMarketTable.xml
    void Clear();                       // 0x1401c4390
    TabListPtr GetTabs();               // 0x1401c43e0
    IdArrayPtr GetOptionStats(unsigned int nOption);    // 0x1401c4430 stat tables of an option
    StatArrayPtr GetStatTable(unsigned int nId);        // 0x1401c44f0
    TabPtr GetTab(unsigned int nId);    // 0x1401c45b0
    void ReadTabs(Unk_140165cf0* pElem, TabList* pOut, TabMap* pById, CStringA* pCategories);  // 0x1401c4670

    static void CheckInit();            // 0x1401c60f0
    static void SetInit(bool b);        // 0x1401c9180

    static bool s_bInit;                // 0x143aac4e0

private:
    MS2_LAYOUT_FRIEND;
    TabListPtr m_tabs;                  // +0x38 top level tabs
    OptionMap m_options;                // +0x48 option id -> stat table ids
    StatTableMap m_statTables;          // +0x90 stat table id -> stats
    TabMap m_tabById;                   // +0xd8 every tab by its id
};
MS2_CHECK_SIZE(CBlackMarketTable, 0x120);
MS2_CHECK_OFFSET(CBlackMarketTable, m_tabs, 0x38);
MS2_CHECK_OFFSET(CBlackMarketTable, m_options, 0x48);
MS2_CHECK_OFFSET(CBlackMarketTable, m_statTables, 0x90);
MS2_CHECK_OFFSET(CBlackMarketTable, m_tabById, 0xd8);

// RTTI CBlackMarketUtil: static helpers (only the init guard lives in the class).
class CBlackMarketUtil
{
public:
    static void CheckInit();            // 0x1401c04d0
    static bool s_bInit;                // 0x143aac3d0
};
