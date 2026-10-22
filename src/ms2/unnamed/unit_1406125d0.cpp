// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemLockManager (the item lock / gemstone-lock packet
// manager, packet type 0x87) and the std::map<CString, GFx::Value> glue that CMsgBoxData::FUN_140613810 instantiates.
// MS2-UNIT: unit_1406125d0
// MS2-RANGE: 0x1406125d0-0x140615410 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??$format_arg@_WW4Unk_LockResult@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_LockResult@@@Z 0x140614320
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_1406125d0.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1406125d0
CItemLockManager::CItemLockManager()
{
    m_mode = 0;
    m_pending.RemoveAll();
    m_locked.RemoveAll();
    m_locked.SetCount(0x12, -1);
}

// @0x140612680
CItemLockManager::~CItemLockManager()
{
    SendRequestItemLockMode0();
}

// @0x1406126f0
void CItemLockManager::SendRequestItemLockMode0()
{
    m_pending.RemoveAll();
    m_locked.RemoveAll();
    m_locked.SetCount(0x12, -1);
    COutPacket packet(static_cast<int>(SendOp::RequestItemLock), 0);
    packet.WriteUInt8(0);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1406126F0, CItemLockManager, SendRequestItemLockMode0, 137, 0x6C3F07B6);

// @0x140612780
void CItemLockManager::FUN_140612780()
{
    SendRequestItemLockMode0();
}
MS2_REPLACE_METHOD(0x140612780, CItemLockManager, FUN_140612780, 24, 0xEE473776);

// @0x1406127a0
MS2Ptr<CItem> CItemLockManager::FUN_1406127a0(int nSlot)
{
    if (nSlot < 0 || nSlot >= (int)m_locked.GetCount())
        return MS2Ptr<CItem>(0);
    __int64 nItemUid = m_locked.GetAt(nSlot);
    return DAT_143ab2a90.FUN_140a5d680(nItemUid);
}
MS2_REPLACE_METHOD(0x1406127A0, CItemLockManager, FUN_1406127a0, 160, 0xB62C07D5);

// @0x140612850
void CItemLockManager::FUN_140612850(CInPacket& packet)
{
    unsigned char nMode = packet.ReadUInt8();
    UIItemLockDialog* pDialog = Unk_LockDialog<UIItemLockDialog>(0x4f08);
    if (pDialog == 0)
        return;
    {
        if (nMode == 1)
        {
            __int64 nItemUid = packet.ReadInt64();
            int nSlot = (unsigned short)packet.ReadInt16();
            if (nSlot < 0 || nSlot >= 0x12)
                return;
            MS2Ptr<CItem> item = DAT_143ab2a90.FUN_140a5d680(nItemUid);
            if (item.get() != 0)
            {
                m_locked.GetAt(nSlot) = nItemUid;
                pDialog->FUN_140f56c80();
            }
            UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
            if (pInventory != 0)
                pInventory->FUN_14199a3f0(nItemUid);
        }
        else if (nMode == 2)
        {
            __int64 nItemUid = packet.ReadInt64();
            FUN_140612c60(nItemUid);
            pDialog->FUN_140f56c80();
            UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
            if (pInventory != 0)
                pInventory->FUN_14199a3f0(nItemUid);
        }
        else if (nMode == 3)
        {
            unsigned nCount = packet.ReadUInt8();
            for (int i = 0; i < (int)nCount; i = i + 1)
            {
                __int64 nItemUid = packet.ReadInt64();
                MS2Ptr<CItem> item = DAT_143ab2a90.FUN_140a5d680(nItemUid);
                if (item.get() != 0)
                    item->FUN_140524eb0(packet);
                FUN_140612c60(nItemUid);
                UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
                if (pInventory != 0)
                    pInventory->FUN_14199a3f0(item->FUN_140526a50());
            }
            pDialog->FUN_140f56c80();
        }
        else if (nMode == 4)
        {
            Unk_LockResult nResult = (Unk_LockResult)packet.ReadInt32();
            if (nResult == 1)
                FUN_141275260(0xc45, 1, 1);
            else if (nResult == 3)
                FUN_141275260(0x43, 1, 1);
            else
                Unk_LockMessage(0xc45, 1, 1, nResult);
        }
        pDialog->FUN_140f56e00();
    }
}
MS2_REPLACE_METHOD(0x140612850, CItemLockManager, FUN_140612850, 1030, 0xAF0BFFC6);

// @0x140612c60
void CItemLockManager::FUN_140612c60(__int64 nItemUid)
{
    for (size_t i = 0; i < m_locked.GetCount(); i = i + 1)
    {
        if (m_locked.GetAt(i) == nItemUid)
        {
            m_locked.GetAt(i) = 0;
            break;
        }
    }
    for (size_t j = 0; j < m_pending.GetCount(); j = j + 1)
    {
        if (m_pending.GetAt(j) == nItemUid)
        {
            m_pending.GetAt(j) = 0;
            return;
        }
    }
}
MS2_REPLACE_METHOD(0x140612C60, CItemLockManager, FUN_140612c60, 245, 0x781DF609);

// @0x140612d60
int CItemLockManager::FUN_140612d60()
{
    UIItemLockDialog* pDialog = Unk_LockDialog<UIItemLockDialog>(0x4f08);
    if (pDialog == 0)
        return 0;
    return pDialog->FUN_140f56f50();
}
MS2_REPLACE_METHOD(0x140612D60, CItemLockManager, FUN_140612d60, 51, 0x532E011C);

// @0x140612da0
int CItemLockManager::FUN_140612da0()
{
    for (size_t i = 0; i < m_locked.GetCount(); i = i + 1)
    {
        if (m_locked.GetAt(i) == 0)
            continue;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140612DA0, CItemLockManager, FUN_140612da0, 101, 0x68CEC8C8);

// @0x140612e10
int CItemLockManager::SendRequestItemLockMode3()
{
    COutPacket packet(static_cast<int>(SendOp::RequestItemLock), 0);
    packet.WriteUInt8(3);
    packet.WriteUInt8(m_mode);
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE_METHOD(0x140612E10, CItemLockManager, SendRequestItemLockMode3, 108, 0xB57742B3);

// @0x140612e90
int CItemLockManager::FUN_140612e90(MS2Ptr<CItem> item)
{
    if (item.IsNull())
        return 0;
    unsigned __int64 nItemUid = item->FUN_140526a50();
    if (FUN_140534480(m_locked, nItemUid) != -1)
    {
        {
            CStringW sKey(L"s_itemlock_selected_item");
            FUN_1412751f0(GetStringCommonByKey(sKey), 1, 1);
        }
        return 0;
    }
    if (m_mode == 0)
    {
        if (item->FUN_140528cc0() == false)
        {
            FUN_141275260(0xc46, 1, 1);
            return 0;
        }
    }
    else if (m_mode == 1)
    {
        if (item->FUN_140528da0() == false)
        {
            FUN_141275260(0xc47, 1, 1);
            return 0;
        }
    }
    COutPacket packet(static_cast<int>(SendOp::RequestItemLock), 0);
    packet.WriteUInt8(1);
    packet.WriteUInt8(m_mode);
    packet.WriteInt64(item->FUN_140526a50());
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE_METHOD(0x140612E90, CItemLockManager, FUN_140612e90, 585, 0xB6F104AC);

// @0x1406130e0
int CItemLockManager::FUN_1406130e0(__int64 nItemUid)
{
    COutPacket packet(static_cast<int>(SendOp::RequestItemLock), 0);
    packet.WriteUInt8(2);
    packet.WriteInt64(nItemUid);
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE_METHOD(0x1406130E0, CItemLockManager, FUN_1406130e0, 109, 0xBC78ABB8);

// @0x140613160
int CItemLockManager::FUN_140613160(CItem* pItem)
{
    if (pItem == 0)
        return 0;
    int nReason = 0;
    if (FUN_140634120(MS2Ptr<CItem>(pItem), &nReason) == false)
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x22, CStringW(L""), 0, CStringW(L""));
        if (box.get() != 0)
        {
            if (nReason == 2)
                box.operator->()->FUN_140613810("confirmMsg", L"$s_itemlock_msgbox_lock_gemstone_notice");
            FUN_140d73c60(box);
        }
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140613160, CItemLockManager, FUN_140613160, 379, 0x5DE28A4C);

// @0x1406132f0
void CItemLockManager::FUN_1406132f0()
{
    for (size_t i = 0; i < m_locked.GetCount(); i = i + 1)
    {
        unsigned __int64 nItemUid = m_locked.GetAt(i);
        if (nItemUid == 0)
            continue;
        MS2Ptr<CItem> item = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (item.IsNull() && FUN_140534480(m_pending, nItemUid) == -1)
        {
            COutPacket packet(static_cast<int>(SendOp::RequestItemLock), 0);
            packet.WriteUInt8(2);
            packet.WriteInt64(nItemUid);
            FUN_140710590(packet);
            m_pending.Add(nItemUid);
        }
    }
}
MS2_REPLACE_METHOD(0x1406132F0, CItemLockManager, FUN_1406132f0, 305, 0x72FF89B5);

// @0x140613430
// MS2-FUNCTIONAL: the exe routes the mode through an extra int temp and a different case-body layout (not reproduced)
int CItemLockManager::FUN_140613430(MS2Ptr<CItem> item)
{
    if (item == 0)
        return 0;
    switch (GetMode())
    {
    case LOCKMODE_LOCK:
        if (item->FUN_140528cc0() == false)
            return 0;
        break;
    case LOCKMODE_UNLOCK:
        if (item->FUN_140528da0() == false)
            return 0;
        break;
    }
    unsigned __int64 nItemUid = item->FUN_140526a50();
    if (FUN_140534480(m_locked, nItemUid) == -1)
        return 1;
    else
        return 0;
}

// @0x140613810
void CMsgBoxData::FUN_140613810(const char* szName, const wchar_t* szText)
{
    ASData data;
    data.FUN_1422b8310(szText);
    m_values.insert(std::make_pair(szName, data.FUN_1422b9260()));
}

// ASData::~ASData (0x1406147b0) is implicit (asdata.h); its CAtlList<Value> dtor COMDATs follow from the ASData local above.
