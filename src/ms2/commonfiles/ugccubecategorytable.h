// ugccubecategorytable.h - UGCCubeCategoryTable (RTTI name): the UGC cube (housing item) shop categories read from
// Table/cubeCategory.xml (menus, sort orders, per-category tab trees) and Table/ugcCubeDefaultCategory.xml (interior
// housing bonus per category). Header name assumed; member and helper names are invented from use.
//
// Layout: TSingleton<UGCCubeCategoryTable> (vftable only, 8 bytes), CValidData at +8, the CCacheData base at +0x10
// (path of the loaded file), then the containers from +0x38; 0x178 bytes.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/tptreddummy.h"

class TiXmlElement;    // xml element (declared where the loader is)

// Key type of the interior maps (a distinct key type: the exe's maps pass the key by reference).
enum ECubeCategory { ECubeCategory_None = 0 };

#include "ms2/placeholder/socketptr.h"   // C3: Unk_CubeNewTag = Unk_SocketNew (one tag type; its ctor 0x1401b7b90 is shared)
typedef Unk_SocketNew Unk_CubeNewTag;



CPtred* FUN_1401ba820(CPtred* p);                           // marks a freshly allocated object (sets the count to 1)

// 16-byte intrusive smart pointer (RTTI TPtr<T>; field 0 unused, field 1 the pointee) to a CPtred-derived object.
// Members are defined below the class so that they stay out-of-line COMDATs like the exe's.
template <class T>
class Unk_CubePtr
{
public:
    Unk_CubePtr();
    Unk_CubePtr(int);
    Unk_CubePtr(const Unk_CubeNewTag&);                     // fresh object
    Unk_CubePtr(const Unk_CubePtr& o);                      // copy + AddRef
    Unk_CubePtr(Unk_CubePtr&& o);                           // move (a returned local)
    ~Unk_CubePtr();
    Unk_CubePtr& operator=(const Unk_CubePtr& o);
    Unk_CubePtr& operator=(const Unk_CubeNewTag&);
    T* get() const;
    T* operator->() const;
    bool operator==(T* p) const;
    friend struct Unk_CubePtrAccess;    // uiugccubepalettedialog FUN_140ef0500 (AddRef / Release)
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

template <class T> Unk_CubePtr<T>::Unk_CubePtr() { m_p = 0; }
template <class T> Unk_CubePtr<T>::Unk_CubePtr(int) { m_p = 0; }
template <class T> Unk_CubePtr<T>::Unk_CubePtr(const Unk_CubeNewTag&) { m_p = 0; Make(); }
template <class T> Unk_CubePtr<T>::Unk_CubePtr(const Unk_CubePtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_CubePtr<T>::Unk_CubePtr(Unk_CubePtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_CubePtr<T>::~Unk_CubePtr() { Release(); }
template <class T> Unk_CubePtr<T>& Unk_CubePtr<T>::operator=(const Unk_CubePtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_CubePtr<T>& Unk_CubePtr<T>::operator=(const Unk_CubeNewTag&) { Make(); return *this; }
template <class T> T* Unk_CubePtr<T>::get() const { return m_p; }
template <class T> T* Unk_CubePtr<T>::operator->() const { return m_p; }
template <class T> bool Unk_CubePtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> void Unk_CubePtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_CubePtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_CubePtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> T* Unk_CubePtr<T>::Allocate(void*) { return new T(); }
template <class T> T* Unk_CubePtr<T>::Create(void*) { return static_cast<T*>(FUN_1401ba820(Allocate(0))); }
template <class T> void Unk_CubePtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_CubePtr<T>::AddRefImpl(void*) const { Ref(m_p); }
template <class T> void Unk_CubePtr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) { Ref(m_p); CPtred::DeletePtred(m_p); }
}

// The same pointer to a boxed value (TPtredDummy<T>: a CPtred header 0x18 bytes before the pointee).
template <class T>
class Unk_CubeBoxPtr
{
public:
    Unk_CubeBoxPtr();
    Unk_CubeBoxPtr(int);
    Unk_CubeBoxPtr(const Unk_CubeNewTag&);
    Unk_CubeBoxPtr(const Unk_CubeBoxPtr& o);
    Unk_CubeBoxPtr(Unk_CubeBoxPtr&& o);
    ~Unk_CubeBoxPtr();
    Unk_CubeBoxPtr& operator=(const Unk_CubeBoxPtr& o);
    Unk_CubeBoxPtr& operator=(const Unk_CubeNewTag&);
    T* get() const;
    T* operator->() const;
    bool operator==(T* p) const;

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

template <class T> Unk_CubeBoxPtr<T>::Unk_CubeBoxPtr() { m_p = 0; }
template <class T> Unk_CubeBoxPtr<T>::Unk_CubeBoxPtr(int) { m_p = 0; }
template <class T> Unk_CubeBoxPtr<T>::Unk_CubeBoxPtr(const Unk_CubeNewTag&) { m_p = 0; Make(); }
template <class T> Unk_CubeBoxPtr<T>::Unk_CubeBoxPtr(const Unk_CubeBoxPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_CubeBoxPtr<T>::Unk_CubeBoxPtr(Unk_CubeBoxPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_CubeBoxPtr<T>::~Unk_CubeBoxPtr() { Release(); }
template <class T> Unk_CubeBoxPtr<T>& Unk_CubeBoxPtr<T>::operator=(const Unk_CubeBoxPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_CubeBoxPtr<T>& Unk_CubeBoxPtr<T>::operator=(const Unk_CubeNewTag&) { Make(); return *this; }
template <class T> T* Unk_CubeBoxPtr<T>::get() const { return m_p; }
template <class T> T* Unk_CubeBoxPtr<T>::operator->() const { return m_p; }
template <class T> bool Unk_CubeBoxPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> void Unk_CubeBoxPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_CubeBoxPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_CubeBoxPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> TPtredDummy<T>* Unk_CubeBoxPtr<T>::Allocate(void*) { return new TPtredDummy<T>(); }
template <class T> T* Unk_CubeBoxPtr<T>::Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
template <class T> TPtredDummy<T>* Unk_CubeBoxPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> void Unk_CubeBoxPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> T* Unk_CubeBoxPtr<T>::Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
template <class T> void Unk_CubeBoxPtr<T>::AddRefImpl(void*) const { Ref(Owner(m_p)); }
template <class T> void Unk_CubeBoxPtr<T>::ReleaseImpl(void*)
{
    CPtred* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
}

// RTTI CUGCCubeCategoryTable's namesake; 0x178 bytes, vftables 0x142d9e688 (TSingleton), 0x142d9e698 (CValidData, +8),
// 0x142d9e6a8 (CCacheData, +0x10); each has only the deleting destructor.
class UGCCubeCategoryTable : public TSingleton<UGCCubeCategoryTable>, public CValidData<UGCCubeCategoryTable>,
                             public CCacheData
{
public:
    // <menus><menu> of cubeCategory.xml: one shop menu (0x30 bytes).
    class MenuInfo : public CPtred
    {
    public:
        MenuInfo();                     // 0x140885f20
        // ~MenuInfo (0x140888d70) is implicit: the exe stores no vftable in it.

        CStringW m_strName;             // +0x18 localized menu name (string id "name")
        int m_nCategory;                // +0x20 "category"
        int m_nFilter;                  // +0x24 "filter"
        int m_nDelegator;               // +0x28 "delegator"
        int m_nOrder;                   // +0x2c
    };

    // <sorts><sort> (0x28 bytes).
    class SortInfo : public CPtred
    {
    public:
        SortInfo();                     // 0x140885fa0
        // ~SortInfo (0x140888da0) is implicit: the exe stores no vftable in it.

        CStringW m_strName;             // +0x18
        int m_nOrder;                   // +0x20 "order"
    };

    typedef Unk_CubePtr<MenuInfo> MenuPtr;
    typedef Unk_CubePtr<SortInfo> SortPtr;

    // A <category>/<tab> node (0x50 bytes) with its child tabs.
    class TabInfo;
    typedef Unk_CubePtr<TabInfo> TabPtr;
    class TabInfo : public CPtred
    {
    public:
        TabInfo();                      // 0x140886010
        // ~TabInfo (0x140888dd0) is implicit: the exe stores no vftable in it.

        CStringW m_strName;             // +0x18
        unsigned int m_nCategory;       // +0x20 "category"
        ATL::CAtlArray<TabPtr> m_children;  // +0x28
        int m_nDelegator;               // +0x48 "delegator"
    };

    // One <house> row of ugcCubeDefaultCategory.xml (0x28 bytes).
    class Interior : public CPtred
    {
    public:
        Interior();                     // 0x140886090
        // ~Interior (0x140888d50) is implicit: the exe stores no vftable in it.

        int m_nBonusPoint;              // +0x18 "housingBonusPoint"
        int m_nBonusCount;              // +0x1c "housingBonusCount"
        unsigned short m_nRequireLevel; // +0x20 "requireHousingLevel"
        ECubeCategory m_nCategory;      // +0x24 "categoryIndex"
    };

    typedef Unk_CubePtr<Interior> InteriorPtr;
    typedef ATL::CAtlArray<MenuPtr> MenuArray;
    typedef ATL::CAtlArray<SortPtr> SortArray;
    typedef ATL::CAtlArray<TabPtr> TabArray;
    typedef Unk_CubeBoxPtr<MenuArray> MenuArrayPtr;
    typedef Unk_CubeBoxPtr<SortArray> SortArrayPtr;
    typedef Unk_CubeBoxPtr<TabArray> TabArrayPtr;
    typedef ATL::CAtlMap<int, TabArrayPtr> TabMap;
    typedef ATL::CAtlMap<ECubeCategory, InteriorPtr> InteriorMap;
    typedef ATL::CRBMap<unsigned int, MenuPtr> MenuSortMap;

    static void SetInit(bool b);        // 0x14088cc90
    static bool s_bInit;                // 0x143ab2130

    UGCCubeCategoryTable();             // 0x140886100
    virtual ~UGCCubeCategoryTable();    // 0x140886380

    bool Load();                                                    // 0x140886460 both files
    MenuArrayPtr GetMenus();                                        // 0x140886490
    SortArrayPtr GetSorts();                                        // 0x1408864e0
    TabArrayPtr GetTabs(int nCategory);                             // 0x140886530
    InteriorPtr GetInterior(int nCategory);                         // 0x1408865b0
    InteriorMap& GetBonusInteriors();                               // 0x140886640
    MenuPtr FindMenu(int nCategory);                                // 0x140886660
    int AddMenuById(int nNameId, int nOrder);                       // 0x140886790 name looked up in the string table
    int AddMenu(CStringW strName, int nOrder);                      // 0x1408867f0 returns the new filter
    void RemoveMenu(int nFilter);                                   // 0x140886920
    bool HasAnyField(const std::vector<unsigned int>& fields);      // 0x140886a40

    void LoadMenus();                                              // 0x140886af0 cubeCategory.xml
    void LoadInteriors();                                            // 0x140886fc0 ugcCubeDefaultCategory.xml

private:
    void ReadTabsInto(int nCategory, TiXmlElement* pElem, TabArray* pOut);            // 0x140887430
    void ReadTabChildren(int nCategory, TiXmlElement* pElem, TabPtr tab);             // 0x140887240
    TabPtr ReadTab(TiXmlElement* pElem);                                              // 0x140887530
    int NextCategory();                                             // 0x1408876a0 largest category + 1
    int NextOrder();                                                // 0x1408877a0 largest order + 1
    int NextFilter();                                               // 0x1408878a0 largest filter + 1
    void SortMenus();                                               // 0x1408879a0

    MS2_LAYOUT_FRIEND;
    MenuArrayPtr m_menus;               // +0x38
    SortArrayPtr m_sorts;               // +0x48
    TabMap m_tabs;                      // +0x58 tab tree per category
    InteriorMap m_interiors;            // +0xa0 default interior per category
    InteriorMap m_bonusInteriors;       // +0xe8 only the ones with a housing bonus
    std::set<unsigned int> m_tabCategories; // +0x130 every category a tab leaf refers to
};
