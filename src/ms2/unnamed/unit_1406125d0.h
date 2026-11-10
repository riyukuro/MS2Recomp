// CItemLockManager (RTTI .?AVCItemLockManager@@, 0x50 bytes, TSingleton<CItemLockManager> base) and its helper types.
// Not an original header: member names are inferred (the exe has no strings for them), Unk_ types are local stand-ins.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/client/ms2/uiservice.h"   // C3: CUIService::FindObject was Unk_LockUIManager::FUN_141adcea0

class CItemLockManager;
class UIItemLockDialog;
class UIInventoryDialog;
class CMsgBoxData;
enum Unk_LockResult : int {};
enum Unk_LockMode : int { LOCKMODE_LOCK = 0, LOCKMODE_UNLOCK = 1 };

// Free functions of the exe, bound by their FUN_<va> names.
template<class T> T* Unk_BreakDialog(int);   // C3: was FUN_1405344f0
template <class T> int Unk_BreakFind(const ATL::CAtlArray<T>& values, const T& value);   // C3: was FUN_140534480 (the index of a value, itembreakmanager)
bool FUN_140634120(MS2Ptr<CItem> item, int* pReason);
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void ShowSystemNotice(const CStringW& text, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);
CStringW GetStringCommonByKey(const CStringW& str);

template <class T> T* Unk_LockDialog(int nId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// fmt message with one argument: the original is a template over the argument type (here the result enum).
template <class A> void Unk_LockMessage(int nStringId, int nA, int nB, const A& x)
{
    const fmt::internal::ArgArray<1>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(x)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(x), values));
}

// Player inventory (global at 0x143ab2a90): item lookup by uid.
class Unk_Inventory;
extern Unk_Inventory g_143ab2a90;

// The item lock dialog (RTTI .?AVUIItemLockDialog@@, id 0x4f08) and the inventory dialog (id 0x4e2d): only the calls
// the manager makes.
class UIItemLockDialog : public UIDialog
{
public:
    void BindItemBag();
    void UpdateLockButtons();
    int IsItemBagVisible();
};
class UIInventoryDialog : public UIDialog
{
public:
    void RefreshItemSlot(__int64 nItemUid);
};

class CItemLockManager : public TSingleton<CItemLockManager>
{
public:
    CItemLockManager();
    virtual ~CItemLockManager();
    void SendRequestItemLockMode0();
    void FUN_140612780();
    MS2Ptr<CItem> FUN_1406127a0(int nSlot);
    void OnItemLockPacket(CInPacket& packet);                  // item lock packet (mode 1 lock, 2 unlock, 3 list, 4 result)
    void FUN_140612c60(__int64 nItemUid);
    int FUN_140612d60();                                    // dialog open state
    int FUN_140612da0();                                   // any slot locked
    int SendRequestItemLockMode3();
    int FUN_140612e90(MS2Ptr<CItem> item);
    int FUN_1406130e0(__int64 nItemUid);
    int CanUseItem(CItem* pItem);
    void FUN_1406132f0();
    int CanAddItem(MS2Ptr<CItem> item);
    Unk_LockMode GetMode() const { return (Unk_LockMode)m_mode; }   // 0x140614b50

    ATL::CAtlArray<unsigned __int64> m_locked;      // +0x08 item uids in the lock slots (0x12 slots)
    ATL::CAtlArray<unsigned __int64> m_pending;     // +0x28 uids already sent for unlocking
    int m_mode;                                     // +0x48
    int m_pad_4c;
};
MS2_CHECK_SIZE(CItemLockManager, 0x50);
MS2_CHECK_OFFSET(CItemLockManager, m_locked, 8);
MS2_CHECK_OFFSET(CItemLockManager, m_pending, 0x28);
MS2_CHECK_OFFSET(CItemLockManager, m_mode, 0x48);

void FUN_140159e70(void* p);

// Message box data (RTTI .?AVCMsgBoxData@@): only the extra GFx value map at +0x290 is used here.
class CMsgBoxData : public CPtred
{
public:
    void FUN_140613810(const char* szName, const wchar_t* szText);
    void* m_pad_18[0x4f];
    std::map<CString, Scaleform::GFx::Value> m_values;      // +0x290
};
MS2_CHECK_OFFSET(CMsgBoxData, m_values, 0x290);
