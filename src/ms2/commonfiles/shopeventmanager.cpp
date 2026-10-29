// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CShopEventManager: the running premium market sale events
// (PreminmMarketSaleEventContext, by event id) behind a lock and the price maths of an event, followed by the
// lock-guarded add / remove / query members of the shut down event sets (placeholder/cshutdownevent.h). The rest of the
// range is the ATL::CAtlMap<int, MS2Ptr<PreminmMarketSaleEventContext> > / CAtlArray / MS2Ptr glue those instantiate.
// MS2-UNIT: ?\shopeventmanager.cpp
// MS2-RANGE: 0x1407cde30-0x1407d1080 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEAA@AEBV0@@Z 0x1407ce960 ; unique
// MS2-PIN: ??0?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEAA@H@Z 0x1407cea10 ; unique
// MS2-PIN: ??4?$MS2Ptr@UPreminmMarketSaleEventContext@@@@QEAAAEAV0@AEBV0@@Z 0x1407ceb90 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@UPreminmMarketSaleEventContext@@@@V?$CElementTraits@V?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@Z 0x1407cecd0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@UPreminmMarketSaleEventContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1407cf0b0 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@HV?$MS2Ptr@UPreminmMarketSaleEventContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@3@@ATL@@QEBA_NHAEAV?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@Z 0x1407cf5a0 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$MS2Ptr@UPreminmMarketSaleEventContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@UPreminmMarketSaleEventContext@@@@@Z 0x1407cfeb0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\shopeventmanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <math.h>
#include <map>
#include <set>
#include <new>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/cshutdownevent.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The scoped lock of a CLockCriticalSection (the 0x140203610 copy of the ctor, dtor 0x1401b5120).
struct Unk_ShopEventLock
{
    Unk_ShopEventLock(CLockCriticalSection& lock, int acquire);     // 0x140203610
    ~Unk_ShopEventLock();                                           // 0x1401b5120
    void* m_p;
};
MS2_CHECK_SIZE(Unk_ShopEventLock, 8);

CShopEventManager* FUN_1403ed2a0();                                 // TSingleton<CShopEventManager>::GetInstance
extern "C" float (__cdecl* __imp_ceilf)(float);
bool FUN_1406a5040(int nId);                                        // the id is a special (whole) sale id

// ---- one sale event (PreminmMarketSaleEventContext: m_18 rate in 1/10000, m_20 covered ids, m_30 currency) ----

// @0x1407cde30
bool FUN_1407cde30(PreminmMarketSaleEventContext* pContext, int nId, int nCurrency)
{
    if (nCurrency != pContext->m_30)
        return false;
    int nRest = nId % 100;
    int nBase = -1;
    if (nRest > 0)
        nBase = nId - nRest;
    bool bFound = false;
    if (nBase >= 0)
        bFound = pContext->m_20.find(nBase) != pContext->m_20.end();
    if (!bFound)
        bFound = pContext->m_20.find(nId) != pContext->m_20.end();
    if (!bFound)
    {
        int nAll = 0;
        bFound = pContext->m_20.find(nAll) != pContext->m_20.end();
    }
    return bFound;
}

// @0x1407cdfc0
bool FUN_1407cdfc0(PreminmMarketSaleEventContext* pContext, int nId, int nCurrency)
{
    if (nCurrency != pContext->m_30)
        return false;
    bool bFound = pContext->m_20.find(nId) != pContext->m_20.end();
    if (!bFound)
    {
        bool bWhole = false;
        bool bSpecial = FUN_1406a5040(nId);
        if (bSpecial)
            bWhole = true;
        else
        {
            int nRest = nId % 100;
            bWhole = nRest == 0;
        }
        if (bWhole)
        {
            int nAll = 0;
            bFound = pContext->m_20.find(nAll) != pContext->m_20.end();
        }
    }
    return bFound;
}

// @0x1407ce100
int FUN_1407ce100(PreminmMarketSaleEventContext* pContext, int nPrice)
{
    const int nRateBase = 10000;
    float fPrice = __imp_ceilf((float)(nPrice * (nRateBase - pContext->m_18)) / 10000.0f);
    return (int)fPrice;
}

// ---- CShopEventManager ----

// @0x1407ce160
CShopEventManager::CShopEventManager()
{
}

// @0x1407ce1f0
CShopEventManager::~CShopEventManager()
{
}

// @0x1407ce240
bool CShopEventManager::FUN_1407ce240()
{
    Unk_ShopEventLock lock(m_lock, 1);
    m_events.RemoveAll();
    return true;
}

// @0x1407ce2a0
void CShopEventManager::FUN_1407ce2a0(int eventId, MS2Ptr<PreminmMarketSaleEventContext> spContext)
{
    Unk_ShopEventLock lock(m_lock, 1);
    m_events.SetAt(eventId, spContext);
}

// @0x1407ce320
void CShopEventManager::FUN_1407ce320(int eventId)
{
    Unk_ShopEventLock lock(m_lock, 1);
    m_events.RemoveKey(eventId);
}

// The pointer temporary FUN_1407ce380 copies each event through before it is added (a MS2Ptr built from another one
// through its getter; the byte-identical sibling of the plain copy at 0x1407ce960). Not referenced by the source: the
// original TU's template layer made it from a conversion this source does not have.
// @0x1407ce9a0
// MS2-FUNCTIONAL: the exact conversion that selects this copy is not known; the plain copy is used by FUN_1407ce380
MS2Ptr<PreminmMarketSaleEventContext>* FUN_1407ce9a0(MS2Ptr<PreminmMarketSaleEventContext>* pDst,
                                                     const MS2Ptr<PreminmMarketSaleEventContext>& spSrc)
{
    return new (pDst) MS2Ptr<PreminmMarketSaleEventContext>((PreminmMarketSaleEventContext*)spSrc);
}

// @0x1407ce380
// MS2-FUNCTIONAL: the exe adds each event through a MS2Ptr temporary (0x1407ce9a0, dtor 0x1406a8810)
void CShopEventManager::FUN_1407ce380(ATL::CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> >& arr, const int& nCurrency)
{
    Unk_ShopEventLock lock(m_lock, 1);
    for (POSITION pos = m_events.GetStartPosition(); pos != NULL; m_events.GetNext(pos))
    {
        MS2Ptr<PreminmMarketSaleEventContext> spContext = m_events.GetValueAt(pos);
        if (spContext == 0)
            continue;
        if (nCurrency == 0 || nCurrency == spContext->m_30)
            arr.Add(spContext);
    }
}

// @0x1407ce4b0
MS2Ptr<PreminmMarketSaleEventContext> CShopEventManager::FUN_1407ce4b0(const int& nEventId)
{
    Unk_ShopEventLock lock(m_lock, 1);
    MS2Ptr<PreminmMarketSaleEventContext> spContext(0);
    m_events.Lookup(nEventId, spContext);
    return spContext;
}

// @0x1407ce560
bool CShopEventManager::FUN_1407ce560(int nId, int nCurrency)
{
    Unk_ShopEventLock lock(m_lock, 1);
    for (POSITION pos = m_events.GetStartPosition(); pos != NULL; m_events.GetNext(pos))
    {
        MS2Ptr<PreminmMarketSaleEventContext> spContext = m_events.GetValueAt(pos);
        if (spContext == 0)
            continue;
        if (FUN_1407cde30(spContext.operator->(), nId, nCurrency))
            return true;
    }
    return false;
}

// @0x1407ce690
bool CShopEventManager::FUN_1407ce690(int nId, int nCurrency)
{
    Unk_ShopEventLock lock(m_lock, 1);
    for (POSITION pos = m_events.GetStartPosition(); pos != NULL; m_events.GetNext(pos))
    {
        MS2Ptr<PreminmMarketSaleEventContext> spContext = m_events.GetValueAt(pos);
        if (spContext == 0)
            continue;
        if (FUN_1407cdfc0(spContext.operator->(), nId, nCurrency))
            return true;
    }
    return false;
}

// @0x1407ce7c0
bool CShopEventManager::FUN_1407ce7c0()
{
    Unk_ShopEventLock lock(m_lock, 1);
    ATL::CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> > arr;
    int nCurrency = 0x186a2;
    FUN_1403ed2a0()->FUN_1407ce380(arr, nCurrency);
    return !arr.IsEmpty();
}

// ---- the shut down event sets ----

// @0x1407d00f0
CShutdownEventDropBox::CShutdownEventDropBox()
{
}

// @0x1407d0150
bool CShutdownEventDropBox::FUN_1407d0150(unsigned long nBoxId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_ids[nBoxId]++;
    return true;
}

// @0x1407d01d0
void CShutdownEventDropBox::FUN_1407d01d0(unsigned long nBoxId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_ids.find(nBoxId) == m_ids.end())
        return;
    int nCount = m_ids[nBoxId];
    if (nCount < 2)
        m_ids.erase(nBoxId);
    else
        m_ids[nBoxId]--;
}

// @0x1407d02e0
bool CShutdownEventDropBox::IsShutdown(unsigned long nBoxId)
{
    if (m_ids.empty())
        return false;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_ids.find(nBoxId) != m_ids.end())
        return true;
    return false;
}

// @0x1407d03c0
CShutdownEventInteractObject::CShutdownEventInteractObject()
{
}

// @0x1407d0420
bool CShutdownEventInteractObject::FUN_1407d0420(unsigned nFieldId, int nObjectId)
{
    std::pair<unsigned, int> key(nFieldId, nObjectId);
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_objects[key]++;
    return true;
}

// @0x1407d04c0
void CShutdownEventInteractObject::FUN_1407d04c0(unsigned nFieldId, int nObjectId)
{
    std::pair<unsigned, int> key(nFieldId, nObjectId);
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_objects.find(key) == m_objects.end())
        return;
    int nCount = m_objects[key];
    if (nCount < 2)
        m_objects.erase(key);
    else
        m_objects[key]--;
}

// @0x1407d05e0
bool CShutdownEventInteractObject::FUN_1407d05e0(unsigned nFieldId, int nObjectId)
{
    if (m_objects.empty())
        return false;
    std::pair<unsigned, int> key(nFieldId, nObjectId);
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_objects.find(key) != m_objects.end())
        return true;
    return false;
}

// @0x1407d06d0
CShutdownEventQuest::CShutdownEventQuest()
{
}

// @0x1407d07a0
int CShutdownEventQuest::FUN_1407d07a0(int nQuestId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_quests.SetAt(nQuestId, 1);
    return 1;
}

// @0x1407d0810
void CShutdownEventQuest::FUN_1407d0810(int nQuestId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_quests.RemoveKey(nQuestId);
}

// @0x1407d0870
int CShutdownEventQuest::FUN_1407d0870(Unk_ShutdownQuestKey eKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_keys.SetAt(eKey, 1);
    return 1;
}

// @0x1407d08f0
void CShutdownEventQuest::FUN_1407d08f0(Unk_ShutdownQuestKey eKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_keys.RemoveKey(eKey);
}

// @0x1407d0950
int CShutdownEventQuest::FUN_1407d0950(int nQuestId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nCount = 0;
    if (m_quests.Lookup(nQuestId, nCount) && nCount != 0)
        return 1;
    return 0;
}

// @0x1407d09f0
CShutdownEventItemTransfer::CShutdownEventItemTransfer()
{
}

// @0x1407d0a80
int CShutdownEventItemTransfer::FUN_1407d0a80(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_items.SetAt(nKey, 1);
    return 1;
}

// @0x1407d0af0
void CShutdownEventItemTransfer::FUN_1407d0af0(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_items.RemoveKey(nKey);
}

// @0x1407d0b50
int CShutdownEventItemTransfer::FUN_1407d0b50(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nValue = 0;
    m_items.Lookup(nKey, nValue);
    return nValue;
}

// @0x1407d0bd0
CShutdownEventFunctionItem::CShutdownEventFunctionItem()
{
}

// @0x1407d0c30
bool CShutdownEventFunctionItem::FUN_1407d0c30(unsigned long nItemId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_items[nItemId]++;
    return true;
}

// @0x1407d0cb0
void CShutdownEventFunctionItem::FUN_1407d0cb0(unsigned long nItemId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_items.find(nItemId) == m_items.end())
        return;
    int nCount = m_items[nItemId];
    if (nCount < 2)
        m_items.erase(nItemId);
    else
        m_items[nItemId]--;
}

// @0x1407d0dc0
bool CShutdownEventFunctionItem::FUN_1407d0dc0(unsigned long nItemId)
{
    if (m_items.empty())
        return false;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_items.find(nItemId) != m_items.end())
        return true;
    return false;
}

// @0x1407d0ea0
CShutdownEventCoupleEmotion::CShutdownEventCoupleEmotion()
{
}

// @0x1407d0f30
int CShutdownEventCoupleEmotion::FUN_1407d0f30(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_emotions.SetAt(nKey, 1);
    return 1;
}

// @0x1407d0fa0
void CShutdownEventCoupleEmotion::FUN_1407d0fa0(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_emotions.RemoveKey(nKey);
}

// @0x1407d1000
int CShutdownEventCoupleEmotion::FUN_1407d1000(int nKey)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nValue = 0;
    m_emotions.Lookup(nKey, nValue);
    return nValue;
}

MS2_EMIT_CRT_MEMMOVE_S();
