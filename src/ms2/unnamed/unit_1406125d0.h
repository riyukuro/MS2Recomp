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

class CItemLockManager;
class UIItemLockDialog;
class UIInventoryDialog;
class CMsgBoxData;
enum Unk_LockResult : int {};
enum Unk_LockMode : int { LOCKMODE_LOCK = 0, LOCKMODE_UNLOCK = 1 };

// Free functions of the exe, bound by their FUN_<va> names.
class Unk_LockUIManager
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
};
Unk_LockUIManager* FUN_1403ed2b0();
UIInventoryDialog* FUN_1405344f0(int nId);
int FUN_140534480(const ATL::CAtlArray<unsigned __int64>& aIds, const unsigned __int64& nId);
bool FUN_140634120(MS2Ptr<CItem> item, int* pReason);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);
CStringW FUN_14028b8e0(const CStringW& str);

template <class T> T* Unk_LockDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
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
class Unk_LockInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);
};
extern Unk_LockInventory DAT_143ab2a90;

// The item lock dialog (RTTI .?AVUIItemLockDialog@@, id 0x4f08) and the inventory dialog (id 0x4e2d): only the calls
// the manager makes.
class UIItemLockDialog : public UIDialog
{
public:
    void FUN_140f56c80();
    void FUN_140f56e00();
    int FUN_140f56f50();
};
class UIInventoryDialog : public UIDialog
{
public:
    void FUN_14199a3f0(__int64 nItemUid);
};

class CItemLockManager : public TSingleton<CItemLockManager>
{
public:
    CItemLockManager();
    virtual ~CItemLockManager();
    void FUN_1406126f0();
    void FUN_140612780();
    MS2Ptr<CItem> FUN_1406127a0(int nSlot);
    void FUN_140612850(CInPacket& packet);                  // item lock packet (mode 1 lock, 2 unlock, 3 list, 4 result)
    void FUN_140612c60(__int64 nItemUid);
    int FUN_140612d60();                                    // dialog open state
    int FUN_140612da0();                                   // any slot locked
    int FUN_140612e10();
    int FUN_140612e90(MS2Ptr<CItem> item);
    int FUN_1406130e0(__int64 nItemUid);
    int FUN_140613160(CItem* pItem);
    void FUN_1406132f0();
    int FUN_140613430(MS2Ptr<CItem> item);
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
