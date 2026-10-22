// Recovered item enchantment layout; Unk_ names are unit-local descriptive placeholders.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/placeholder/cptred.h"
class Unk_EnchantWrite {
public:
    virtual void vfunc_0(bool);
    virtual void vfunc_1(unsigned char);
    virtual void vfunc_2();
    virtual void vfunc_3(int);
    virtual void vfunc_4(__int64);
};
class Unk_EnchantRead {
public:
    virtual bool vfunc_0();
    virtual unsigned char vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3();
    virtual __int64 vfunc_4();
};
class Unk_EnchantRef { public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0(); };
template<class T> class Unk_EnchantPtr {
public:
    Unk_EnchantPtr();
    Unk_EnchantPtr(const Unk_EnchantPtr&);
    Unk_EnchantPtr(Unk_EnchantPtr&& o) : p(o.p) { o.p=0; }
    Unk_EnchantPtr(T* value) : p(value) { AddRef(); }
    explicit Unk_EnchantPtr(int) : p(0) {}  // `Unk_EnchantPtr<T>(0)`: the int is homed as a dword (0x1405ccda0, itemoptiondata.cpp)
    explicit Unk_EnchantPtr(__int64) : p(0) {}  // `Unk_EnchantPtr<T>(0LL)`: the qword is homed (0x1407bf260, setitemoptionpart.cpp)
    ~Unk_EnchantPtr() { Release(); }
    Unk_EnchantPtr& operator=(const Unk_EnchantPtr&);
    T* operator->() const { return p; }
    bool operator!() const { return p == 0; }   // 0x14058f0c0 (CItemEnchantInfo; itemenchantlimittable.cpp)
    bool operator==(T* value) const { return p == value; }   // 0x1419ca6e0 (CItemEnchantInfo; uiitemenchantdialog.cpp)
    operator T*() const { return p; }       // 0x140633420 (CItemEnchantInfo)
    T* get() const { return p; }            // 0x1405c4950 (BaseOption; itemsocketsystemutil.cpp)
    Unk_EnchantPtr& AssignRaw(T* value) { Unk_EnchantPtr tmp(value); T* old = p; p = tmp.p; tmp.p = old; return *this; }   // 0x1406332d0 (CItemEnchantInfo)
private:
    void AddRef() const { if (p) AddRefImpl(0); }
    static void AddRefObject(T* value) { reinterpret_cast<Unk_EnchantRef*>(value)->FUN_14015b020(); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void Release() { if (p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) {
        if (reinterpret_cast<Unk_EnchantRef*>(p)->FUN_140159bc0() == 0) {
            AddRefObject(p); reinterpret_cast<Unk_EnchantRef*>(p)->FUN_140159ba0();
        }
    }
    void* pad; T* p;
};
class BaseOption {
public:
    BaseOption();
    bool HasValue() const;             // 0x140266ce0 (uiitemenchantdialog.cpp)
    float FUN_140266e10() const;            // 0x140266e10 (float)[+0x18] / divisor
    int GetValue() const;              // 0x140266e30 the value [+0x18] (itemsocketsystemutil.cpp)
    void SetValue(int nValue);         // 0x140266e90 sets the value [+0x18] (itemsocket.cpp)
    void FUN_140266d20(Unk_EnchantWrite&) const;
    void FUN_140266d60(Unk_EnchantRead&);
    void FUN_140266da0(const BaseOption* pSource);   // copy
    void FUN_140266dd0(const BaseOption* pSource);   // add the values (unlimitedenchantoption.cpp)
    void FUN_140266e50(float fRate);        // sets the rate (unlimitedenchantoption.cpp)
    bool FUN_140266ee0(const BaseOption* pOther) const;   // the same option (itemoptiondata.cpp)
private: void* p0; void* p8; void* p10; int m_nValue;
public:
    int m_nIndex;                           // +0x1c the roll order (ItemOptionRandomContext::FUN_1405da4b0)
};
MS2_CHECK_SIZE(BaseOption, 0x20);
struct Unk_EnchantHistory {
    Unk_EnchantHistory() { FUN_14058c160(); }
    void FUN_14058c160();
    void FUN_14058c1b0(Unk_EnchantWrite&) const;
    void FUN_14058c250(Unk_EnchantRead&);
    __int64 itemId; int attempts,failures; bool failed,enabled; int extra;
};
MS2_CHECK_SIZE(Unk_EnchantHistory, 0x18);
// Preserve the enum-like const-reference key ABI used by the original map.
struct Unk_EnchantKeyTraits : ATL::CElementTraits<int> { typedef const int& INARGTYPE; };
typedef ATL::CAtlMap<int,Unk_EnchantPtr<BaseOption>,Unk_EnchantKeyTraits> Unk_EnchantMap;
class CItemEnchantInfo : public CPtred {
public:
    CItemEnchantInfo(int,int);
    ~CItemEnchantInfo() = default;
    static int Version() { return 1; }
    Unk_EnchantPtr<CItemEnchantInfo> FUN_14058c3b0();
    void FUN_14058c510();
    int FUN_14058c5a0();
    int FUN_14058c5c0();
    int GetLevel();
    int FUN_14058c610();
    int FUN_14058c660();
    void FUN_14058c6b0(int level, bool dirty);
    int GetCharge();
    void FUN_14058c750(int charge);
    void FUN_14058c7c0(int charge);
    void FUN_14058c830();
    bool FUN_14058c850();
    void FUN_14058c870();
    void FUN_14058c880();
    int FUN_14058c8a0();
    __int64 FUN_14058c8b0();
    int FUN_14058c8f0();
    int FUN_14058c910();
    void FUN_14058c940();
    bool FUN_14058c960();
    bool FUN_14058c9a0();
    void FUN_14058c9c0(Unk_EnchantWrite& stream) const;
    void FUN_14058cb20(Unk_EnchantRead& stream);
    void FUN_14058cc90(bool dirty);
    bool GetDirty();
    int FUN_14058ccf0();
    Unk_EnchantMap& FUN_14058cd40();
    int FUN_14058cd60();
    void FUN_14058cda0(int version);
    int GetVersion();
    Unk_EnchantPtr<BaseOption> FUN_14058cde0(int key);
    void FUN_14058ce60();
private:
    MS2_LAYOUT_FRIEND;
    int m_id,m_rarity,m_level,m_charge,m_version;
    Unk_EnchantHistory m_history;
    Unk_EnchantMap m_options;
    bool m_dirty;
};
MS2_CHECK_SIZE(CItemEnchantInfo,0x98);
MS2_CHECK_OFFSET(CItemEnchantInfo,m_history,0x30);
MS2_CHECK_OFFSET(CItemEnchantInfo,m_options,0x48);
MS2_CHECK_OFFSET(CItemEnchantInfo,m_dirty,0x90);
