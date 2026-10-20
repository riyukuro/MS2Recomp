// csetitemmanager.h - CSetItemManager (RTTI name, 0x108 bytes, base CPtred, vftable 0x142d8d400, ctor 0x1407af440) and
// CSetItemProxy (RTTI name, 0x28 bytes, vftable 0x142d8d3f0, ctor 0x1407b59a0): the equipped set items of a player,
// counted per (set id, equip layer), and the summed set bonuses. NOT an original header (name assumed). Recovered from
// the second TU of the ?\setiteminfo.cpp range (0x1407af440-0x1407bc4b0); layout after the v2525 snapshot
// (include/ms2/client/CSetItemManager.h). Member and method names are invented from use.
#pragma once
#include <map>
#include <utility>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/additionalactionadditional.h"   // SAType, AdditionalLevelData::MakeKey

class SetItemInfo;

// The equip layer of a set piece (0 and 4 are never counted; 3 never activates the bonus).
namespace eSetItemLayer { enum T { }; }

// One counted set: its row and whether its bonus applies.
class CSetItemProxy : public CPtred
{
public:
    CSetItemProxy();                                    // 0x1407b59a0
    SetItemInfo* m_pInfo;                               // +0x18
    bool m_bActive;                                     // +0x20
};
MS2_CHECK_SIZE(CSetItemProxy, 0x28);

class CSetItemManager : public CPtred
{
public:
    typedef std::pair<unsigned, eSetItemLayer::T> LayerKey;
    typedef ATL::CAtlList<unsigned __int64> UidList;

    CSetItemManager();                                                              // 0x1407af440
    void Clear();                                                                   // 0x1407af5b0
    void AddItemCount(int nItemId, __int64 nUid, eSetItemLayer::T nLayer, bool bActive);    // 0x1407af660
    void RemoveItem(int nItemId, __int64 nUid, eSetItemLayer::T nLayer);            // 0x1407afa80
    void AddItem(int nItemId, __int64 nUid, eSetItemLayer::T nLayer, bool bActive); // 0x1407afd10
    void RemoveItemByUid(int nItemId, __int64 nUid, eSetItemLayer::T nLayer);       // 0x1407b02e0
    void SetM100(int nValue);                                                       // 0x1407b06e0
    void Refresh();                                                                 // 0x1407b0750 rebuilds the bonuses
    void GetList(UidList& out);                                                     // 0x1407b0b90 the additional effects
    Unk_EnchantPtr<BaseOption> GetOption(int nStat);                                // 0x1407b0c00
    int GetSpecialAbility(SAType nType);                                            // 0x1407b0cb0
    int HasOptions();                                                               // 0x1407b0d20
    int HasSpecialAbilities();                                                      // 0x1407b0d90
    float GetM104();                                                                // 0x1407b0e10
    unsigned GetSetCount(const LayerKey& key);                                      // 0x1407b0e70
    int GetLayer1Count(unsigned nSetId);                                            // 0x1407b0f40

    CLockCriticalSection m_lock;                                                    // +0x18
    TPtrValue<std::map<LayerKey, TPtrValue<UidList> > > m_uids;                     // +0x48
    TPtrValue<std::map<LayerKey, int> > m_counts;                                   // +0x58
    TPtrValue<std::map<LayerKey, MS2Ptr<CSetItemProxy> > > m_proxies;               // +0x68
    Unk_EnchantMap m_options;                                                       // +0x78
    std::map<SAType, int> m_specials;                                               // +0xc0
    UidList m_effects;                                                              // +0xd0 AdditionalLevelData keys
    int m_n100;                                                                     // +0x100
    float m_f104;                                                                   // +0x104
};
MS2_CHECK_SIZE(CSetItemManager, 0x108);
MS2_CHECK_OFFSET(CSetItemManager, m_lock, 0x18);
MS2_CHECK_OFFSET(CSetItemManager, m_uids, 0x48);
MS2_CHECK_OFFSET(CSetItemManager, m_options, 0x78);
MS2_CHECK_OFFSET(CSetItemManager, m_specials, 0xc0);
MS2_CHECK_OFFSET(CSetItemManager, m_effects, 0xd0);
MS2_CHECK_OFFSET(CSetItemManager, m_n100, 0x100);
