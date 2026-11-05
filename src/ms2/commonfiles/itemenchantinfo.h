// Recovered item enchantment layout; Unk_ names are unit-local descriptive placeholders.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr
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
typedef ATL::CAtlMap<int,MS2Ptr<BaseOption>,Unk_EnchantKeyTraits> Unk_EnchantMap;
class CItemEnchantInfo : public CPtred {
public:
    CItemEnchantInfo(int,int);
    ~CItemEnchantInfo() = default;
    static int Version() { return 1; }
    MS2Ptr<CItemEnchantInfo> Clone();
    void Reset();
    int GetAttemptCount();
    int IncrementAttemptCount();
    int GetLevel();
    int IncreaseLevel();
    int DecreaseLevel();
    void SetLevel(int level, bool dirty);
    int GetCharge();
    void AddCharge(int charge);
    void SetCharge(int charge);
    void ClearCharge();
    bool IsChargeFull();
    void FUN_14058c870();
    void ClearHistoryItemId();
    int FUN_14058c8a0();
    __int64 GetHistoryItemId();
    int GetFailureCount();
    int IncrementFailureCount();
    void MarkFailed();
    bool HasFailed();
    bool FUN_14058c9a0();
    void Write(Unk_EnchantWrite& stream) const;
    void Read(Unk_EnchantRead& stream);
    void SetDirty(bool dirty);
    bool GetDirty();
    int FUN_14058ccf0();
    Unk_EnchantMap& GetOptions();
    int NeedsChargeVersionUpdate();
    void SetVersion(int version);
    int GetVersion();
    MS2Ptr<BaseOption> GetOption(int key);
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
