// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSetItemManager: the equipped set items of a player,
// counted per (set id, equip layer), and the summed set bonuses rebuilt from the SetItemOptionPart rows. The second
// TU of the ?\setiteminfo.cpp queue range (the first, SetItemInfo, is setiteminfo.cpp). Bodies after the v2525
// snapshot (tu/1407af440.cpp). See csetitemmanager.h.
// MS2-UNIT: ?\setiteminfo.cpp#2
// MS2-RANGE: 0x1407af440-0x1407bc4b0 .text$mn
// MS2-PIN: ??1CSetItemManager@@UEAA@XZ 0x1407b5ef0
// MS2-PIN: ??1CSetItemProxy@@UEAA@XZ 0x1407b5f90
// MS2-PIN: memmove_s 0x1407bc390
// MS2-PIN: ??$_Call@AEAV<lambda_139169c20169df97f37d68e9c11f515a>@@AEBU?$pair@W4OptionKey@UnlimitedEnchantInfo@@V?$MS2Ptr@VBaseOption@@@@@std@@@_Invoker_functor@std@@SAXAEAV<lambda_139169c20169df97f37d68e9c11f515a>@@AEBU?$pair@W4OptionKey@UnlimitedEnchantInfo@@V?$MS2Ptr@VBaseOption@@@@@1@@Z 0x1407b1f60 ; unique
// MS2-PIN: ??$_Call@AEAV<lambda_d9f6fbbd6b0a841527635be964ea555f>@@AEBU?$pair@W4Unk_SocketSpecialStat@@V?$MS2Ptr@VBaseOption@@@@@std@@@_Invoker_functor@std@@SAXAEAV<lambda_d9f6fbbd6b0a841527635be964ea555f>@@AEBU?$pair@W4Unk_SocketSpecialStat@@V?$MS2Ptr@VBaseOption@@@@@1@@Z 0x1407b1ee0 ; unique
// MS2-PIN: ??$invoke@AEAV<lambda_139169c20169df97f37d68e9c11f515a>@@AEBU?$pair@W4OptionKey@UnlimitedEnchantInfo@@V?$MS2Ptr@VBaseOption@@@@@std@@@std@@YAXAEAV<lambda_139169c20169df97f37d68e9c11f515a>@@AEBU?$pair@W4OptionKey@UnlimitedEnchantInfo@@V?$MS2Ptr@VBaseOption@@@@@0@@Z 0x1407b4e70 ; unique
// MS2-PIN: ??$invoke@AEAV<lambda_d9f6fbbd6b0a841527635be964ea555f>@@AEBU?$pair@W4Unk_SocketSpecialStat@@V?$MS2Ptr@VBaseOption@@@@@std@@@std@@YAXAEAV<lambda_d9f6fbbd6b0a841527635be964ea555f>@@AEBU?$pair@W4Unk_SocketSpecialStat@@V?$MS2Ptr@VBaseOption@@@@@0@@Z 0x1407b4e30 ; unique
// MS2-PIN: ?_Delete_this@?$_Func_impl_no_alloc@V<lambda_d9f6fbbd6b0a841527635be964ea555f>@@XAEBU?$pair@W4Unk_SocketSpecialStat@@V?$MS2Ptr@VBaseOption@@@@@std@@@std@@EEAAX_N@Z 0x1407b8320 ; unique
// MS2-PIN: ?_Delete_this@?$_Func_impl_no_alloc@V<lambda_139169c20169df97f37d68e9c11f515a>@@XAEBU?$pair@W4OptionKey@UnlimitedEnchantInfo@@V?$MS2Ptr@VBaseOption@@@@@std@@@std@@EEAAX_N@Z 0x1407b8360 ; unique
// MS2-PIN: ?_Get@?$_Func_impl_no_alloc@V<lambda_d9f6fbbd6b0a841527635be964ea555f>@@XAEBU?$pair@W4Unk_SocketSpecialStat@@V?$MS2Ptr@VBaseOption@@@@@std@@@std@@EEBAPEBXXZ 0x1407b99c0 ; unique
// MS2-PIN: ?_Get@?$_Func_impl_no_alloc@V<lambda_139169c20169df97f37d68e9c11f515a>@@XAEBU?$pair@W4OptionKey@UnlimitedEnchantInfo@@V?$MS2Ptr@VBaseOption@@@@@std@@@std@@EEBAPEBXXZ 0x1407b99e0 ; unique
// The exe RTTI spells both handles TPtr<...> (TPtrValue/MS2Ptr here): pin the two box vftables.
// MS2-PIN: ??_7?$TPtredDummy@V?$map@U?$pair@IW4T@eSetItemLayer@@@std@@V?$MS2Ptr@VCSetItemProxy@@@@U?$less@U?$pair@IW4T@eSetItemLayer@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IW4T@eSetItemLayer@@@std@@V?$MS2Ptr@VCSetItemProxy@@@@@std@@@2@@std@@@@6B@ 0x142d8d410
// MS2-PIN: ??_7?$TPtredDummy@V?$map@U?$pair@IW4T@eSetItemLayer@@@std@@V?$TPtrValue@V?$CAtlList@_KV?$CElementTraits@_K@ATL@@@ATL@@@@U?$less@U?$pair@IW4T@eSetItemLayer@@@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IW4T@eSetItemLayer@@@std@@V?$TPtrValue@V?$CAtlList@_KV?$CElementTraits@_K@ATL@@@ATL@@@@@std@@@2@@std@@@@6B@ 0x142d8d430
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\setiteminfo.cpp"
#define MS2_TPTRVALUE_MOVE      // lvalue copies add a reference, moves steal it (the exe pair ctors 0x1407b1590/0x1407b1770)
// The exe's memmove_s is a plain call (no /Oi expansion); the pragma must precede the inline copy.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>
#include <functional>
#include "ms2/placeholder/csetitemmanager.h"
#include "ms2/placeholder/setitemtable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/setiteminfo.h"
#include "ms2/commonfiles/setitemoptionpart.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/clockcriticalsection.h"   // Unk_CriticalSectionLock (was a local lock view)

MS2Ptr<CItemData> FUN_14053f870(int nItemId);                  // the item data of an id

// @0x1407af440
CSetItemManager::CSetItemManager()
{
    m_uids = Unk_GrNewTag(0);
    m_counts = Unk_GrNewTag(0);
    m_proxies = Unk_GrNewTag(0);
    m_n100 = 0;
    m_f104 = 0.0f;
}

// @0x1407af5b0
void CSetItemManager::Clear()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_uids->clear();
    m_counts->clear();
    m_proxies->clear();
    m_n100 = 0;
    m_f104 = 0.0f;
}

// @0x1407af660
void CSetItemManager::AddItemCount(int nItemId, __int64 nUid, eSetItemLayer::T nLayer, bool bActive)
{
    if (nLayer == 0 || nLayer == 4)
        return;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return;
    if (!SetItemTable::GetInstance()->HasSetItem(spItem->GetOriginOrItemId()))
        return;
    std::vector<MS2Ptr<SetItemInfo> > sets;
    SetItemTable::GetInstance()->GetSetItemInfos(spItem->GetOriginOrItemId(), sets);
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (size_t i = 0; i < sets.size(); i++)
    {
        LayerKey key(sets[i]->GetId(), nLayer);
        int nOne = 1;
        std::map<LayerKey, int>::iterator itCount = m_counts->find(key);
        if (itCount != m_counts->end())
            itCount->second += nOne;
        else
            m_counts->insert(std::make_pair(key, nOne));
        std::map<LayerKey, MS2Ptr<CSetItemProxy> >::iterator itProxy = m_proxies->find(key);
        if (itProxy == m_proxies->end())
        {
            MS2Ptr<CSetItemProxy> spProxy(new CSetItemProxy);
            if (spProxy)
            {
                spProxy->m_pInfo = sets[i].get();
                spProxy->m_bActive = bActive;
                m_proxies->insert(std::make_pair(key, spProxy));
            }
        }
    }
}

// @0x1407afa80
void CSetItemManager::RemoveItem(int nItemId, __int64 nUid, eSetItemLayer::T nLayer)
{
    if (nLayer == 0 || nLayer == 4)
        return;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return;
    if (!SetItemTable::GetInstance()->HasSetItem(spItem->GetOriginOrItemId()))
        return;
    std::vector<MS2Ptr<SetItemInfo> > sets;
    SetItemTable::GetInstance()->GetSetItemInfos(spItem->GetOriginOrItemId(), sets);
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (size_t i = 0; i < sets.size(); i++)
    {
        int nCount = 0;
        LayerKey key(sets[i]->GetId(), nLayer);
        std::map<LayerKey, int>::iterator itCount = m_counts->find(key);
        if (itCount != m_counts->end())
        {
            const int nOne = 1;
            int& nRef = itCount->second;
            nRef -= nOne;
            nCount = itCount->second;
        }
        if (nCount <= 0)
        {
            m_counts->erase(key);
            m_proxies->erase(key);
        }
    }
}

// @0x1407afd10
void CSetItemManager::AddItem(int nItemId, __int64 nUid, eSetItemLayer::T nLayer, bool bActive)
{
    if (nLayer == 0 || nLayer == 4)
        return;
    if (nLayer == 3)
        bActive = false;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return;
    if (!SetItemTable::GetInstance()->HasSetItem(spItem->GetOriginOrItemId()))
        return;
    std::vector<MS2Ptr<SetItemInfo> > sets;
    SetItemTable::GetInstance()->GetSetItemInfos(spItem->GetOriginOrItemId(), sets);
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (size_t i = 0; i < sets.size(); i++)
    {
        TPtrValue<UidList> spUids(0);
        LayerKey key(sets[i]->GetId(), nLayer);
        std::map<LayerKey, TPtrValue<UidList> >::iterator itUids = m_uids->find(key);
        if (itUids == m_uids->end())
        {
            spUids = Unk_GrNewTag(0);
            m_uids->insert(std::make_pair(key, spUids));
        }
        else
        {
            spUids = itUids->second;
        }
        if (spUids == 0)
            continue;
        spUids->AddTail(nUid);
        int nOne = 1;
        std::map<LayerKey, int>::iterator itCount = m_counts->find(key);
        if (itCount == m_counts->end())
            m_counts->insert(std::make_pair(key, nOne));
        else
            itCount->second += nOne;
        std::map<LayerKey, MS2Ptr<CSetItemProxy> >::iterator itProxy = m_proxies->find(key);
        if (itProxy == m_proxies->end())
        {
            MS2Ptr<CSetItemProxy> spProxy(new CSetItemProxy);
            if (spProxy)
            {
                spProxy->m_pInfo = sets[i].get();
                spProxy->m_bActive = bActive;
                m_proxies->insert(std::make_pair(key, spProxy));
            }
        }
    }
    Refresh();
}

// @0x1407b02e0
void CSetItemManager::RemoveItemByUid(int nItemId, __int64 nUid, eSetItemLayer::T nLayer)
{
    if (nLayer == 0 || nLayer == 4)
        return;
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return;
    if (!SetItemTable::GetInstance()->HasSetItem(spItem->GetOriginOrItemId()))
        return;
    std::vector<MS2Ptr<SetItemInfo> > sets;
    SetItemTable::GetInstance()->GetSetItemInfos(spItem->GetOriginOrItemId(), sets);
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (size_t i = 0; i < sets.size(); i++)
    {
        int nSetId = sets[i]->GetId();
        TPtrValue<UidList> spUids(0);
        LayerKey key(nSetId, nLayer);
        std::map<LayerKey, TPtrValue<UidList> >::iterator itUids = m_uids->find(key);
        if (itUids == m_uids->end())
            continue;
        spUids = itUids->second;
        if (spUids == 0)
            continue;
        POSITION pos = spUids->Find(nUid, 0);
        if (pos == 0)
            continue;
        spUids->RemoveAt(pos);
        int nCount = 0;
        std::map<LayerKey, int>::iterator itCount = m_counts->find(key);
        if (itCount != m_counts->end())
        {
            const int nOne = 1;
            int& nRef = itCount->second;
            nRef -= nOne;
            nCount = itCount->second;
        }
        if (nCount <= 0)
        {
            m_uids->erase(key);
            m_counts->erase(key);
            m_proxies->erase(key);
        }
    }
    Refresh();
}

// @0x1407b06e0
void CSetItemManager::SetM100(int nValue)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_n100 = nValue;
    Refresh();
}

// @0x1407b0750
void CSetItemManager::Refresh()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_options.RemoveAll();
    m_specials.clear();
    m_effects.RemoveAll();
    if (m_proxies->empty() == true)
        return;
    for (std::map<LayerKey, MS2Ptr<CSetItemProxy> >::iterator it = m_proxies->begin(); it != m_proxies->end(); ++it)
    {
        const LayerKey& key = it->first;
        MS2Ptr<CSetItemProxy> spProxy = it->second;
        if (spProxy == 0)
            continue;
        SetItemInfo* pInfo = spProxy->m_pInfo;
        bool bActive = spProxy->m_bActive;
        unsigned nCount = GetSetCount(key);
        ATL::CAtlArray<MS2Ptr<SetItemOptionPart> > parts;
        pInfo->GetOptionParts(nCount, parts);
        for (unsigned j = 0; j < parts.GetCount(); j++)
        {
            MS2Ptr<SetItemOptionPart> spPart = parts[j];
            if (bActive)
            {
                spPart->FUN_1407bccf0([this](const std::pair<SetItemOptionPart::StatKey, MS2Ptr<BaseOption> >& entry) {
                    if (entry.second->HasValue())
                    {
                        MS2Ptr<BaseOption> spOption;
                        if (!m_options.Lookup(reinterpret_cast<const int&>(entry.first), spOption))
                            spOption.AssignRaw(new BaseOption);
                        spOption->FUN_140266dd0(entry.second.get());
                        m_options.SetAt(reinterpret_cast<const int&>(entry.first), spOption);
                    }
                });
                spPart->FUN_1407bcdb0([this](const std::pair<SetItemOptionPart::SpecialKey, MS2Ptr<BaseOption> >& entry) {
                    if (entry.second->HasValue())
                        m_specials[(const SAType&)entry.first] += entry.second->GetValue();
                });
            }
            ATL::CAtlArray<int>& effectIds = spPart->GetEffectIds();
            ATL::CAtlArray<unsigned short>& effectLevels = spPart->GetEffectLevels();
            if (!effectIds.IsEmpty() && bActive)
            {
                for (unsigned k = 0; k < effectIds.GetCount(); k++)
                {
                    if (effectIds[k] == 0)
                        continue;
                    m_effects.AddTail(AdditionalLevelData::MakeKey(effectIds[k], effectLevels[k]));
                }
            }
        }
    }
}

// @0x1407b0b90
void CSetItemManager::GetList(UidList& out)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    out.RemoveAll();
    out.AddTailList(&m_effects);
}

// @0x1407b0c00
MS2Ptr<BaseOption> CSetItemManager::GetOption(int nStat)
{
    MS2Ptr<BaseOption> spOption;
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_options.Lookup(nStat, spOption);
    return spOption;
}
MS2_REPLACE_METHOD(0x1407B0C00, CSetItemManager, GetOption, 160, 0x1BBE78DF);

// @0x1407b0cb0
int CSetItemManager::GetSpecialAbility(SAType nType)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_specials[nType];
}

// @0x1407b0d20
int CSetItemManager::HasOptions()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_options.IsEmpty() == 0 ? 1 : 0;
}
MS2_REPLACE_METHOD(0x1407B0D20, CSetItemManager, HasOptions, 106, 0x07E01EC5);

// @0x1407b0d90
int CSetItemManager::HasSpecialAbilities()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_specials.empty() == 0 ? 1 : 0;
}
MS2_REPLACE_METHOD(0x1407B0D90, CSetItemManager, HasSpecialAbilities, 108, 0x68EEE267);

// @0x1407b0e10
float CSetItemManager::GetM104()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_f104;
}
MS2_REPLACE_METHOD(0x1407B0E10, CSetItemManager, GetM104, 77, 0x78234F7A);

// @0x1407b0e70
unsigned CSetItemManager::GetSetCount(const LayerKey& key)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    unsigned nCount = 0;
    std::map<LayerKey, int>::iterator it = m_counts->find(key);
    if (it != m_counts->end())
        nCount = it->second;
    return nCount;
}
MS2_REPLACE_METHOD(0x1407B0E70, CSetItemManager, GetSetCount, 189, 0x7662DAE1);

// @0x1407b0f40
int CSetItemManager::GetLayer1Count(unsigned nSetId)
{
    LayerKey key(nSetId, (eSetItemLayer::T)1);
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nCount = 0;
    std::map<LayerKey, int>::iterator it = m_counts->find(key);
    if (it != m_counts->end())
        nCount = it->second;
    return nCount;
}
MS2_REPLACE_METHOD(0x1407B0F40, CSetItemManager, GetLayer1Count, 216, 0x6FA35A1C);

// @0x1407b59a0
CSetItemProxy::CSetItemProxy() : m_pInfo(0), m_bActive(true)
{
}

// memmove_s 0x1407bc390 closes the obj's COMDAT tail.
__declspec(selectany) extern errno_t(__cdecl* const ms2_setItemManagerMemmoveS)(void*, size_t, const void*, size_t) = &memmove_s;
