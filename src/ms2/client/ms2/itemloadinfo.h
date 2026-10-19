// itemloadinfo.h - CItemLoadInfo (RTTI .?AVCItemLoadInfo@@, 0x58 bytes) and CItemLoader (RTTI .?AVCItemLoader@@, 0x58 bytes), the
// item model loader thread. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\itemloadinfo.cpp`
// (0x140d31670-0x140d3b9f0 .text$mn, dir client\ms2). Header name assumed from the unit. Member and method names are invented
// from use (cross-checked against the third-party v2525 snapshot, ms2/tu/140d31550).
//
// CItemLoader is a TSingleton worker (CThread at +0x0, TSingleton<CItemLoader> at +0x18). The UI asks it for item models
// with Request*(id, ...): a CItemLoadInfo is queued under `id` in m_pending and the semaphore is released. The thread
// (vfunc_1) wakes per request, loads the nifs/textures of the item (LoadNext) and moves the finished request to m_loaded
// under the same lock; the owner takes the finished requests with TakeLoaded.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <list>
#include <string>

#include <NiAVObject.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cthread.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tptrvalue.h"

class CItem;
class Unk_140659080;

// One queued load request. m_type 0 = load the nifs of the item model, 1 = hand an item back (with m_40), 2 = hand a
// CPtred target back (with m_40).
class CItemLoadInfo : public CPtred
{
public:
    CItemLoadInfo();                                                // 0x140d31670
    virtual ~CItemLoadInfo();                                       // 0x140d31700 (??_G 0x140d38630)

    int m_type;                                                     // +0x18
    MS2Ptr<CItem> m_item;                                           // +0x20
    MS2Ptr<CPtred> m_target;                                        // +0x30 a CPtred-derived target (type 2)
    int m_40;                                                       // +0x40 caller value
    std::map<std::string, std::list<NiAVObjectPtr> > m_nifs;       // +0x48 the loaded nifs by model path
};
MS2_CHECK_SIZE(CItemLoadInfo, 0x58);

typedef ATL::CAtlArray<MS2Ptr<CItemLoadInfo> > ItemLoadInfoArray;
typedef TPtrValue<ItemLoadInfoArray> ItemLoadInfoList;             // the requests queued under one id (TPtredDummy box)
typedef std::map<unsigned, ItemLoadInfoList> ItemLoadInfoMap;

class CItemLoader : public CThread, public TSingleton<CItemLoader>
{
public:
    CItemLoader();                                                  // 0x140d317a0
    virtual ~CItemLoader();                                         //  0 0x140d31860 (??_G 0x140d38670)
    virtual unsigned vfunc_1(void* pUser, Unk_140659080& start);    //  1 0x140d31910 the worker loop

    void Shutdown();                                                // 0x140d319d0 wake and join the thread, drop the queues
    void ClearPending();                                            // 0x140d31a60
    int IsStopping();                                               // 0x140d31ac0
    size_t GetPendingCount();                                       // 0x140d31ae0
    void TakeLoaded(ItemLoadInfoMap& loaded);                       // 0x140d31b60
    void Complete(unsigned nId, MS2Ptr<CItemLoadInfo> info);             // 0x140d31be0 move a finished request to m_loaded
    void LoadNext(CItemLoader* pLoader);                                            // 0x140d31d40 load the next pending request
    void Request(unsigned nId, MS2Ptr<CItem> item);                      // 0x140d329e0 type 0: load the item model
    void Request(unsigned nId, MS2Ptr<CItem> item, int nValue);          // 0x140d32c20 type 1
    void Request(unsigned nId, MS2Ptr<CPtred> target, int nValue);       // 0x140d32e90 type 2
    void RefreshItem(MS2Ptr<CItemLoadInfo> info);                   // 0x140d33100

private:
    MS2_LAYOUT_FRIEND;
    ItemLoadInfoMap m_pending;                                      // +0x20 queued requests by id
    ItemLoadInfoMap m_loaded;                                       // +0x30 finished requests by id
    int m_bStop;                                                  // +0x40
    HANDLE m_hStop;                                                 // +0x48 created by the thread
    HANDLE m_hWake;                                                 // +0x50 semaphore, one count per request
};
MS2_CHECK_SIZE(CItemLoader, 0x58);
