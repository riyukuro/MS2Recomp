// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The shut down ("shutdown event") values of
// CGameEventValueManager: the per-kind id counts (CShutdownEventValue / Group), the item remake option table and the
// locked id sets / UGC upload map / dual set the manager owns.
// MS2-UNIT: commonfiles\shutdowneventvalue.cpp
// MS2-RANGE: 0x1407d1080-0x1407dc950 .text$mn
// MS2-PIN: ??$_Try_emplace@AEBU?$pair@IH@std@@$$V@?$map@U?$pair@IH@std@@JU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@J@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@std@@_N@1@AEBU?$pair@IH@1@@Z 0x1407d80d0
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBU?$pair@IH@std@@J@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@J@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@JU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@J@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@1@AEAU?$pair@$$CBU?$pair@IH@std@@J@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@J@std@@PEAX@1@@Z 0x1407d5f00
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0V?$tuple@AEBU?$pair@IH@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@IH@std@@J@std@@QEAA@AEAV?$tuple@AEBU?$pair@IH@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1407d2d90 ; unique
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x1407d3550 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBU?$pair@IH@std@@J@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBU?$pair@IH@std@@@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@J@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@J@std@@PEAX@std@@@1@QEAU?$pair@$$CBU?$pair@IH@std@@J@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBU?$pair@IH@std@@@1@$$QEAV?$tuple@$$V@1@@Z 0x1407d8730 ; unique
// MS2-PIN: ??$distance@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@0@0@Z 0x1407d89d0 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_ShutdownUGCUploadInfo@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1407d9800 ; prop
// MS2-PIN: ?RemoveKey@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA_NH@Z 0x1407da3d0 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@JU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@J@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@IH@std@@J@std@@PEAX@2@@Z 0x1407db2d0 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_ShutdownDualKeyB@@U?$less@W4Unk_ShutdownDualKeyB@@@std@@V?$allocator@W4Unk_ShutdownDualKeyB@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@W4Unk_ShutdownDualKeyB@@PEAX@2@@Z 0x1407db300 ; prop
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_ShutdownDualKeyA@@U?$less@W4Unk_ShutdownDualKeyA@@@std@@V?$allocator@W4Unk_ShutdownDualKeyA@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@W4Unk_ShutdownDualKeyA@@PEAX@2@@Z 0x1407db330 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@U?$pair@IH@std@@JU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@J@std@@@2@$0A@@std@@@std@@QEAAAEAU?$less@U?$pair@IH@std@@@2@XZ 0x1407db6e0 ; prop
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@JU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@J@std@@@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@std@@V12@@2@AEBU?$pair@IH@2@@Z 0x1407dbe30 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@JU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@J@std@@@2@$0A@@std@@@std@@QEAA_KAEBU?$pair@IH@2@@Z 0x1407dbf60 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@U?$pair@IH@std@@JU?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@J@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@J@std@@@std@@@std@@@2@AEBU?$pair@IH@2@@Z 0x1407dc170 ; prop
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??1CShutdownEventValue@@UEAA@XZ 0x1407d9550
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\shutdowneventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include <map>
#include <vector>
#include "ms2/placeholder/ms2ptr_impl.h"
#define MS2_GAMEEVENTVALUE_TYPES
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#ifndef MS2_HOOK_DLL
// The ctors of these classes (0x1407d00f0 ... 0x1407d1000, shopeventmanager.cpp's range) emit their vftables, and the
// exe keeps their ??_G COMDATs in this range. Emit them here for the byte-match build only.
CShutdownEventDropBox::CShutdownEventDropBox()
{
}
CShutdownEventInteractObject::CShutdownEventInteractObject()
{
}
CShutdownEventFunctionItem::CShutdownEventFunctionItem()
{
}
CShutdownEventQuest::CShutdownEventQuest()
{
}
// The std::map members the drop box / function item / interact object classes use (their tree COMDATs are in this range).
void Unk_ShutdownCountMapAnchor(std::map<unsigned long, int>& kMap, unsigned long nKey)
{
    kMap[nKey]++;
    if (kMap.find(nKey) == kMap.end())
        return;
    int nCount = kMap[nKey];
    if (nCount < 2)
        kMap.erase(nKey);
    else
        kMap[nKey]--;
    if (kMap.empty())
        return;
    if (kMap.find(nKey) != kMap.end())
        return;
}
void Unk_ShutdownObjectMapAnchor(std::map<std::pair<unsigned, int>, long>& kMap, unsigned nField, int nObject)
{
    std::pair<unsigned, int> kKey(nField, nObject);
    kMap[kKey]++;
    if (kMap.find(kKey) == kMap.end())
        return;
    long nCount = kMap[kKey];
    if (nCount < 2)
        kMap.erase(kKey);
    else
        kMap[kKey]--;
    if (kMap.empty())
        return;
    if (kMap.find(kKey) != kMap.end())
        return;
}
// The members of CAtlMap<Unk_ShutdownQuestKey, int> the quest class (0x1407d0870 ...) instantiates: the exe keeps their
// COMDATs in this range.
void Unk_ShutdownQuestKeyAnchor(ATL::CAtlMap<Unk_ShutdownQuestKey, int>& kMap, Unk_ShutdownQuestKey eKey)
{
    int nValue = 0;
    kMap.SetAt(eKey, 1);
    kMap.RemoveKey(eKey);
    kMap.Lookup(eKey, nValue);
}
CShutdownEventItemTransfer::CShutdownEventItemTransfer()
{
}
CShutdownEventCoupleEmotion::CShutdownEventCoupleEmotion()
{
}
#endif

// @0x1407d1080
CShutdownEventValue::CShutdownEventValue()
{
}

// @0x1407d10e0
void CShutdownEventValue::FUN_1407d10e0(unsigned long nId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    ++m_ids[nId];
}

// @0x1407d1160
void CShutdownEventValue::FUN_1407d1160(unsigned long nId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    --m_ids[nId];
    if (m_ids[nId] == 0)
        m_ids.erase(nId);
}

// @0x1407d1210
bool CShutdownEventValue::FUN_1407d1210(unsigned long nId)
{
    if (m_ids.empty())
        return false;
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_ids[nId] != 0;
}

// @0x1407d12b0
bool CShutdownEventValue::FUN_1407d12b0()
{
    return !m_ids.empty();
}

// @0x1407d1300
CShutdownEventGroup::CShutdownEventGroup()
{
    m_values.reserve(12);
    for (size_t i = 0; i < 12; i++)
    {
        m_values.push_back(MS2Ptr<CShutdownEventValue>(new CShutdownEventValue));
    }
}

// @0x1407d1400
CShutdownEventValue* CShutdownEventGroup::FUN_1407d1400(int nIndex)
{
    if (nIndex <= 0 || nIndex >= 12)
        return m_values[0].get();
    return m_values[nIndex].get();
}

// @0x1407d1470
CShutdownEventItemRemakeOption::CShutdownEventItemRemakeOption()
{
}

// @0x1407d1500
int CShutdownEventItemRemakeOption::FUN_1407d1500(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_options.SetAt(nKey, 1);
    return 1;
}

// @0x1407d1570
void CShutdownEventItemRemakeOption::FUN_1407d1570(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_options.RemoveKey(nKey);
}

// @0x1407d15d0
int CShutdownEventItemRemakeOption::FUN_1407d15d0(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nValue = 0;
    m_options.Lookup(nKey, nValue);
    return nValue;
}

// @0x1407d1650
CShutdownEventKeySetA::CShutdownEventKeySetA()
{
}

// @0x1407d16a0 shut an id down
bool FUN_1407d16a0(CShutdownEventKeySetA* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.insert(nId);
    return true;
}

// @0x1407d1710 undo it
void FUN_1407d1710(CShutdownEventKeySetA* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.erase(nId);
}

// @0x1407d1770 any id is shut down
bool FUN_1407d1770(CShutdownEventKeySetA* pSet)
{
    if (pSet->m_ids.empty())
        return false;
    return true;
}

// @0x1407d17b0
CShutdownEventKeySetB::CShutdownEventKeySetB()
{
}

// @0x1407d1800 shut an id down
bool FUN_1407d1800(CShutdownEventKeySetB* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.insert(nId);
    return true;
}

// @0x1407d1870 undo it
void FUN_1407d1870(CShutdownEventKeySetB* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.erase(nId);
}

// @0x1407d18d0 any id is shut down
bool FUN_1407d18d0(CShutdownEventKeySetB* pSet)
{
    if (pSet->m_ids.empty())
        return false;
    return true;
}

// @0x1407d1910
CShutdownEventKeySetC::CShutdownEventKeySetC()
{
}

// @0x1407d1960 shut an id down
bool FUN_1407d1960(CShutdownEventKeySetC* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.insert(nId);
    return true;
}

// @0x1407d19d0 undo it
void FUN_1407d19d0(CShutdownEventKeySetC* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.erase(nId);
}

// @0x1407d1a30 any id is shut down
bool FUN_1407d1a30(CShutdownEventKeySetC* pSet)
{
    if (pSet->m_ids.empty())
        return false;
    return true;
}

// @0x1407d1a70
CShutdownEventSet1300::CShutdownEventSet1300()
{
}

// @0x1407d1ac0 shut an id down
bool FUN_1407d1ac0(CShutdownEventSet1300* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.insert(nId);
    return true;
}

// @0x1407d1b30 undo it
void FUN_1407d1b30(CShutdownEventSet1300* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.erase(nId);
}

// @0x1407d1b90 an id is shut down and the level is below 50
bool FUN_1407d1b90(CShutdownEventSet1300* pSet, int nLevel)
{
    if (pSet->m_ids.empty())
        return false;
    if (nLevel < 50)
        return true;
    return false;
}

// @0x1407d1be0
CShutdownEventBillboard::CShutdownEventBillboard()
{
}

// @0x1407d1c30 shut an id down
bool FUN_1407d1c30(CShutdownEventBillboard* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.insert(nId);
    return true;
}

// @0x1407d1ca0 undo it
void FUN_1407d1ca0(CShutdownEventBillboard* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.erase(nId);
}

// @0x1407d1d00 any id is shut down
bool FUN_1407d1d00(CShutdownEventBillboard* pSet)
{
    if (pSet->m_ids.empty())
        return false;
    return true;
}

// @0x1407d1d40
CShutdownEventUGCBanner::CShutdownEventUGCBanner()
{
}

// @0x1407d1d90 shut an id down
bool FUN_1407d1d90(CShutdownEventUGCBanner* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.insert(nId);
    return true;
}

// @0x1407d1e00 undo it
void FUN_1407d1e00(CShutdownEventUGCBanner* pSet, unsigned nId)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_ids.erase(nId);
}

// @0x1407d1e60 any id is shut down
bool FUN_1407d1e60(CShutdownEventUGCBanner* pSet)
{
    if (pSet->m_ids.empty())
        return false;
    return true;
}

// @0x1407d1ea0
CShutdownEventUGCUpload::CShutdownEventUGCUpload()
{
}

// @0x1407d1ef0 the shut down UGC upload kinds of an event
bool FUN_1407d1ef0(CShutdownEventUGCUpload* pUpload, unsigned nEventId, const Unk_ShutdownUGCUploadInfo& info)
{
    Unk_CriticalSectionLock lock(pUpload->m_lock, 1);
    pUpload->m_events[nEventId] = info;
    return true;
}

// @0x1407d1f70
void FUN_1407d1f70(CShutdownEventUGCUpload* pUpload, unsigned nEventId)
{
    Unk_CriticalSectionLock lock(pUpload->m_lock, 1);
    if (pUpload->m_events.find(nEventId) == pUpload->m_events.end())
        MS2_ASSERT_AT(0x219, FALSE);
    else
        pUpload->m_events.erase(nEventId);
}

// @0x1407d2050 an event shuts the upload kind down (mode 2: only the flagged events)
bool FUN_1407d2050(CShutdownEventUGCUpload* pUpload, Unk_UGCUploadType eKind, int nMode)
{
    if (pUpload->m_events.empty())
        return false;
    Unk_CriticalSectionLock lock(pUpload->m_lock, 1);
    std::map<unsigned, Unk_ShutdownUGCUploadInfo>::iterator it = pUpload->m_events.begin();
    while (it != pUpload->m_events.end())
    {
        Unk_ShutdownUGCUploadInfo* pInfo = &it->second;
        if (nMode != 2 || pInfo->m_bFlag != 0)
        {
            if (pInfo->m_ids.find(eKind) != pInfo->m_ids.end())
                return true;
        }
        ++it;
    }
    return false;
}

// @0x1407d21b0
CShutdownEventUnkDualSet::CShutdownEventUnkDualSet()
{
}

// @0x1407d2210
bool FUN_1407d2210(CShutdownEventUnkDualSet* pSet, Unk_ShutdownDualKeyA eKey)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_first.insert(eKey);
    return true;
}

// @0x1407d2280
void FUN_1407d2280(CShutdownEventUnkDualSet* pSet, Unk_ShutdownDualKeyA eKey)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_first.erase(eKey);
}

// @0x1407d22e0 the key (or the all key 0) is shut down
bool FUN_1407d22e0(CShutdownEventUnkDualSet* pSet, Unk_ShutdownDualKeyA eKey)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    Unk_ShutdownDualKeyA eAll = (Unk_ShutdownDualKeyA)0;
    if (pSet->m_first.find(eAll) != pSet->m_first.end())
        return true;
    if (pSet->m_first.find(eKey) != pSet->m_first.end())
        return true;
    return false;
}

// @0x1407d2410
bool FUN_1407d2410(CShutdownEventUnkDualSet* pSet, Unk_ShutdownDualKeyB eKey)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_second.insert(eKey);
    return true;
}

// @0x1407d2480
void FUN_1407d2480(CShutdownEventUnkDualSet* pSet, Unk_ShutdownDualKeyB eKey)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    pSet->m_second.erase(eKey);
}

// @0x1407d24e0 the key (or the all key 0) is shut down
bool FUN_1407d24e0(CShutdownEventUnkDualSet* pSet, Unk_ShutdownDualKeyB eKey)
{
    Unk_CriticalSectionLock lock(pSet->m_lock, 1);
    Unk_ShutdownDualKeyB eAll = (Unk_ShutdownDualKeyB)0;
    if (pSet->m_second.find(eAll) != pSet->m_second.end())
        return true;
    if (pSet->m_second.find(eKey) != pSet->m_second.end())
        return true;
    return false;
}
