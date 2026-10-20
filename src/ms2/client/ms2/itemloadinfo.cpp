// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemLoader is the item model loader thread: requests (item
// model nifs, or a plain "hand this back" item/target) are queued under an id, the worker loads the nifs and icon texture of the
// item through CNifLoadingService and parks the finished request for the owner. See itemloadinfo.h.
// MS2-UNIT: ?\itemloadinfo.cpp
// MS2-RANGE: 0x1400d2540-0x1400d2630 .text$di
// MS2-RANGE: 0x140d31670-0x140d3b9f0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Buynode@AEBV?$SmartPointer@VNiAVObject@@@efd@@@?$_List_buy@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEAAPEAU?$_List_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@1@PEAU21@0AEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x140d339b0 ; unique
// MS2-PIN: ??$_Insert@AEBV?$SmartPointer@VNiAVObject@@@efd@@@?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEAAXV?$_List_unchecked_const_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@U_Iterator_base0@2@@1@AEBV?$SmartPointer@VNiAVObject@@@efd@@@Z 0x140d33e30 ; unique
// MS2-PIN: ??$construct@V?$SmartPointer@VNiAVObject@@@efd@@AEBV12@@?$_Default_allocator_traits@V?$allocator@U?$_List_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_List_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@std@@@1@QEAV?$SmartPointer@VNiAVObject@@@efd@@AEBV34@@Z 0x140d36d80 ; unique
// MS2-PIN: ??$forward@AEBV?$SmartPointer@VNiAVObject@@@efd@@@std@@YAAEBV?$SmartPointer@VNiAVObject@@@efd@@AEBV12@@Z 0x140d37060 ; prop
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2Ptr@VCItemLoadInfo@@@@V?$CElementTraits@V?$MS2Ptr@VCItemLoadInfo@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItemLoadInfo@@@@_K@Z 0x140d38830 ; unique
// MS2-PIN: ?GetTexture@CharacterDecalData@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x140d38880 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@V?$MS2Ptr@VCItemLoadInfo@@@@V?$CElementTraits@V?$MS2Ptr@VCItemLoadInfo@@@@@ATL@@@ATL@@QEAAX_K0@Z 0x140d38a70 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@2@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@2@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@XZ 0x140d3a1f0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CItemLoader@@6B?$TSingleton@VCItemLoader@@@@@ 0x142e2ab90
// MS2-PIN: ??_7?$TPtredDummy@V?$CAtlArray@V?$MS2Ptr@VCItemLoadInfo@@@@V?$CElementTraits@V?$MS2Ptr@VCItemLoadInfo@@@@@ATL@@@ATL@@@@6B@ 0x142e2aba0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemloadinfo.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "itemloadinfo.h"

#include <efd/SmartPointer.h>

#include "ms2/client/ms2/nifeffectparam.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/placeholder/characterdecaldata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <utility>
MS2_EMIT_CRT_MEMMOVE_S();

CNifLoadingService* FUN_140a0afd0();
bool FUN_140184310(const CString& str, const char* psz);                // str == psz
CString FUN_141421740(const CString& strPath, int* pnFlag);            // the variant letter of a model path
CString FUN_1414218c0(const CString& strPath, const CString& strSuffix);   // model path with another variant letter
CString FUN_141425220(const CString& strPath, int bDiffuse);
CString FUN_1414253b0(const CString& strPath, int bDiffuse);

// The payload of CItem::FUN_140527900 (a CItem-owned object with a virtual refresh at slot 8).
struct Unk_ItemPayload
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void Refresh();                                 // slot 8
};

// ---- statics (dynamic initializers 0x1400d2540, 0x1400d2570) ----
// The queue lock is not hooked (the by-value MS2Ptr entry points, Complete/Request*, cannot be hooked safely and share
// the exe's lock with LoadNext/TakeLoaded/ClearPending/GetPendingCount, so none of them is replaced).
static CLockCriticalSection s_lock;
#ifndef MS2_HOOK_DLL
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif

// @0x140d31670
CItemLoadInfo::CItemLoadInfo() : m_type(0), m_item(0), m_40(0)
{
}

// @0x140d31700
CItemLoadInfo::~CItemLoadInfo()
{
    m_item = 0;
    m_type = 0;
    m_40 = 0;
}

// @0x140d317a0
CItemLoader::CItemLoader()
{
    m_bStop = 0;
    m_hStop = 0;
    m_hWake = CreateSemaphoreA(0, 0, 0x7fffffff, 0);
}

// @0x140d31860
CItemLoader::~CItemLoader()
{
    if (m_hWake)
        CloseHandle(m_hWake);
    if (m_hStop)
        CloseHandle(m_hStop);
}

// @0x140d31910
unsigned CItemLoader::vfunc_1(void*, Unk_140659080& start)
{
    m_hStop = CreateEventA(0, 0, 0, 0);
    if (m_hStop == 0)
    {
        start.FUN_140659080(E_FAIL);
        return -1;
    }
    start.FUN_1401d42d0();
    for (;;)
    {
        WaitForSingleObject(m_hWake, INFINITE);
        if (m_bStop != 0)
            break;
        LoadNext(this);
        DWORD dwResult = WaitForSingleObject(m_hStop, 10);
        if (dwResult == 0)
            break;
    }
    return 0;
}

// @0x140d319d0
void CItemLoader::Shutdown()
{
    if (m_hStop)
        SetEvent(m_hStop);
    if (m_hWake)
    {
        m_bStop = 1;
        ReleaseSemaphore(m_hWake, 1, 0);
        FUN_1401d3510(INFINITE);
    }
    m_pending.clear();
    m_loaded.clear();
}
MS2_REPLACE_METHOD(0x140D319D0, CItemLoader, Shutdown, 137, 0xEFD42CC5);

// @0x140d31a60
void CItemLoader::ClearPending()
{
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        m_pending.clear();
    }
}

// @0x140d31ac0
int CItemLoader::IsStopping()
{
    return m_bStop;
}
MS2_REPLACE_METHOD(0x140D31AC0, CItemLoader, IsStopping, 14, 0x620CA41F);

// MS2-FUNCTIONAL: the exe's lock-error path returns the guard destructor's rax and emits a trailing nop after it; not expressible in source
// @0x140d31ae0
size_t CItemLoader::GetPendingCount()
{
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        return m_pending.size();
    }
}

// @0x140d31b60
void CItemLoader::TakeLoaded(ItemLoadInfoMap& loaded)
{
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        loaded = m_loaded;
        m_loaded.clear();
    }
}

// @0x140d31be0
void CItemLoader::Complete(unsigned nId, MS2Ptr<CItemLoadInfo> info)
{
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        ItemLoadInfoList list(0);
        if (m_loaded.find(nId) == m_loaded.end())
        {
            list = Unk_GrNewTag(0);
            m_loaded[nId] = list;
            list->Add(info);
        }
        else
        {
            list = m_loaded[nId];
            list->Add(info);
        }
    }
}

// Loads one nif of the item model and keeps it under its path in the request.
#define ITEMLOADER_LOAD_NIF(strNifPath) \
    nif = FUN_140a0afd0()->Load(CString(strNifPath), false, 5, 0, 0); \
    if (nif) \
    { \
        std::string strKey((const char*)(strNifPath)); \
        nifs[static_cast<std::string&&>(strKey)].push_back(nif); \
    }

// @0x140d31d40
void CItemLoader::LoadNext(CItemLoader* pLoader)
{
    ItemLoadInfoMap unused;
    unsigned nId = 0;
    MS2Ptr<CItemLoadInfo> info(0);
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else if (!m_pending.empty())
    {
        ItemLoadInfoMap::iterator it = m_pending.begin();
        if (it != m_pending.end())
        {
            nId = it->first;
            ItemLoadInfoList list(it->second);
            if (list.get())
            {
                if (list->GetCount() > 0)
                {
                    info = list->GetAt(0);
                    list->RemoveAt(0, 1);
                }
            }
            if (list->GetCount() == 0)
                m_pending.erase(it);
        }
    }
    if (nId == 0 || info == 0)
        return;
    if (FUN_140a0afd0() != 0)
    {
        if (info->m_type == 1 || info->m_type == 2)
        {
            Complete(nId, info);
        }
        else if (info->m_type == 0)
        {
            MS2Ptr<CItemData> data(reinterpret_cast<CItemData*>(info->m_item->FUN_140527840()));
            if (data->FUN_14053d070())
            {
                CharacterDecalData* pDecal = data->FUN_14053eba0()->FUN_14054b6b0();
                if (pDecal != 0)
                    FUN_140a0afd0()->GetTexture(CString(pDecal->GetTexture()), 5);
            }
            std::map<std::string, std::list<NiAVObjectPtr> >& nifs = info->m_nifs;
            NiAVObjectPtr nif(0);
            for (size_t i = 0; i < data->FUN_14053eba0()->FUN_14054b3d0(); ++i)
            {
                const ModelGroup* pGroup = data->FUN_14053eba0()->FUN_14054b2f0(i);
                for (size_t j = 0; j < pGroup->FUN_1405450c0(); ++j)
                {
                    const ModelPart* pPart = pGroup->FUN_140544fe0(j);
                    if (pPart->isNif == 1)
                    {
                        if (data->FUN_14053cfd0())
                        {
                            CString strVariant = FUN_141421740(pPart->name0, 0);
                            if (FUN_140184310(strVariant, "A"))
                            {
                                const CString& strC = FUN_1414218c0(pPart->name0, "C");
                                const CString& strD = FUN_1414218c0(pPart->name0, "D");
                                ITEMLOADER_LOAD_NIF(strC)
                                ITEMLOADER_LOAD_NIF(strD)
                            }
                        }
                        else if (data->FUN_14053cf40())
                        {
                            const CString& strPath = FUN_141425220(pPart->name0, 1);
                            ITEMLOADER_LOAD_NIF(strPath)
                        }
                        else if (data->FUN_14053c620() == 12)
                        {
                            const CString& strPath = FUN_1414253b0(pPart->name0, 1);
                            ITEMLOADER_LOAD_NIF(strPath)
                        }
                        ITEMLOADER_LOAD_NIF(pPart->name0)
                    }
                }
            }
            if (data->FUN_14053cc00())
                RefreshItem(info);
            Complete(nId, info);
        }
    }
}

// @0x140d329e0
void CItemLoader::Request(unsigned nId, MS2Ptr<CItem> item)
{
    if (IsStopping())
        return;
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        MS2Ptr<CItemLoadInfo> info(new CItemLoadInfo);
        info->m_item = item;
        info->m_type = 0;
        ItemLoadInfoList list;
        if (m_pending.find(nId) == m_pending.end())
        {
            list = Unk_GrNewTag(0);
            list->Add(info);
            m_pending[nId] = list;
        }
        else
        {
            list = m_pending[nId];
            list->Add(info);
        }
    }
    ReleaseSemaphore(m_hWake, 1, 0);
}

// @0x140d32c20
void CItemLoader::Request(unsigned nId, MS2Ptr<CItem> item, int nValue)
{
    if (IsStopping())
        return;
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        MS2Ptr<CItemLoadInfo> info(new CItemLoadInfo);
        info->m_item = item;
        info->m_target = 0;
        info->m_type = 1;
        info->m_40 = nValue;
        ItemLoadInfoList list;
        if (m_pending.find(nId) == m_pending.end())
        {
            list = Unk_GrNewTag(0);
            list->Add(info);
            m_pending[nId] = list;
        }
        else
        {
            list = m_pending[nId];
            list->Add(info);
        }
    }
    ReleaseSemaphore(m_hWake, 1, 0);
}

// @0x140d32e90
void CItemLoader::Request(unsigned nId, MS2Ptr<CPtred> target, int nValue)
{
    if (IsStopping())
        return;
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        MS2Ptr<CItemLoadInfo> info(new CItemLoadInfo);
        info->m_item = 0;
        info->m_target = target;
        info->m_type = 2;
        info->m_40 = nValue;
        ItemLoadInfoList list;
        if (m_pending.find(nId) == m_pending.end())
        {
            list = Unk_GrNewTag(0);
            list->Add(info);
            m_pending[nId] = list;
        }
        else
        {
            list = m_pending[nId];
            list->Add(info);
        }
    }
    ReleaseSemaphore(m_hWake, 1, 0);
}

// @0x140d33100
void CItemLoader::RefreshItem(MS2Ptr<CItemLoadInfo> info)
{
    if (info == 0 || info->m_item == 0)
        return;
    MS2Ptr<CItem> item(info->m_item);
    MS2Ptr<CItemData> data(reinterpret_cast<CItemData*>(item->FUN_140527840()));
    if (data->FUN_14053cc00())
    {
        if (item->FUN_140527900() != 0)
        {
            Unk_ItemPayload* pPayload = reinterpret_cast<Unk_ItemPayload*>(item->FUN_140527900());
            pPayload->Refresh();   // MS2: slot 8
        }
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca4c80-0x142ca4cd0 .text$yd
