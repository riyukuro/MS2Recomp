// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemSocket, the gemstone sockets of an item, and the
// per-socket records TSocketGemStoneInfo / Bind / Lock. The file name is a guess from the classes (no __FILE__ string).
// MS2-UNIT: ?\itemsocket.cpp
// MS2-RANGE: 0x14061f540-0x140624700 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_GTSocketGemStoneBind@@UEAAPEAXI@Z 0x140623a50 ; the CNode ??_G look-alikes are not in this unit
// MS2-PIN: ?get@?$MS2Ptr@VCItemData@@@@QEBAPEAVCItemData@@XZ 0x1406239c0 ; GetModuleInstance is an ATL look-alike
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemsocket.cpp"   // guessed (no asserts)
#include "ms2/placeholder/ms2stdafx.h"
#include "itemsocket.h"
#include "stream.h"
#include "ms2/placeholder/citem.h"
#include "item.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

class Unk_ItemOwnerRef : public CItemTransfer {};
__int64 GetServerTime();                        // the current server time
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_14053feb0(int nItemId);                 // the rank of an item
bool FUN_140635b90(unsigned nFlags, unsigned nFlag);
template<class Map> void CopyEnchantMap(Map& to, const Map& from);   // itemoptiondata.cpp
// The option table (CItemOptionTable; FUN_140166430 returns the singleton).
class CItemOptionTable { public: bool ApplyConstantOptions(class MS2Ptr<class CItemOption>, int, int); }; class Unk_140166430 : public CItemOptionTable {};
Unk_140166430* FUN_140166430();

// @0x14061f540
void TSocketGemStoneBind::Write(COutputStream& kOut)
{
    kOut.WriteInt64(m_nCharacterId);
    kOut.WriteUnicodeString(m_strName);
}

// @0x14061f5a0
void TSocketGemStoneBind::Read(CInputStream& kIn)
{
    m_nCharacterId = kIn.ReadInt64();
    m_strName = kIn.ReadUnicodeString();
}

// @0x14061f630
void TSocketGemStoneLock::FUN_14061f630(COutputStream& kOut)
{
    kOut.WriteUInt8((unsigned char)m_nState);
    kOut.WriteInt64(m_nExpireTime);
}

// @0x14061f680
void TSocketGemStoneLock::FUN_14061f680(CInputStream& kIn)
{
    m_nState = kIn.ReadUInt8();
    m_nExpireTime = kIn.ReadInt64();
}

// @0x14061f6d0
bool TSocketGemStoneLock::IsLocked()
{
    if (FUN_140623e20() == 1)
        return true;
    if (FUN_140623e20() == 0 && GetServerTime() < FUN_140623e10())
        return true;
    return false;
}

// @0x14061f730
bool TSocketGemStoneLock::FUN_14061f730()
{
    if (FUN_140623e20() == 1)
        return false;
    return true;
}

// @0x14061f760
bool TSocketGemStoneLock::FUN_14061f760()
{
    if (FUN_140623e20() == 1)
        return true;
    return false;
}

// @0x14061f790
TSocketGemStoneInfo::TSocketGemStoneInfo()
{
    Reset();
}

// @0x14061f800
TSocketGemStoneInfo::TSocketGemStoneInfo(const int& nGemId)
{
    Reset();
    m_nGemId = nGemId;
}

// @0x14061f880
TSocketGemStoneInfo::TSocketGemStoneInfo(MS2Ptr<CItem> spGem)
{
    Reset();
    SetFromItem(spGem);
}

// @0x14061f930
void TSocketGemStoneInfo::SetFromItem(MS2Ptr<CItem> spGem)
{
    if (spGem == 0)
        return;
    m_nGemId = spGem->FUN_1405276c0();
    SetBindFromItem(spGem);
    SetLockFromItem(spGem);
    if (Unk_ItemOwnerRef* pTransfer = spGem->FUN_140527930())
        m_n40 = pTransfer->GetCount();
}

// @0x14061fa50
void TSocketGemStoneInfo::Reset()
{
    m_nGemId = 0;
    m_spBind = 0;
    m_spLock = 0;
    m_n40 = 0;
}

// @0x14061fab0
bool TSocketGemStoneInfo::IsEmpty()
{
    return m_nGemId == 0;
}

// @0x14061faf0
bool TSocketGemStoneInfo::IsBound()
{
    if (m_spBind == 0 || m_spBind->m_nCharacterId == 0)
        return false;
    return true;
}

// @0x14061fb40
bool TSocketGemStoneInfo::IsUsableBy(const __int64* pCharacterId)
{
    if (!IsBound())
        return true;
    return m_spBind->m_nCharacterId == *pCharacterId;
}

// @0x14061fbb0
bool TSocketGemStoneInfo::IsLocked()
{
    if (m_spLock == 0)
        return false;
    return m_spLock->IsLocked();
}

// @0x14061fc00
bool TSocketGemStoneInfo::SetBindFromItem(MS2Ptr<CItem> spGem)
{
    if (spGem == 0 || spGem->FUN_140527930() == 0 || spGem->FUN_140527930()->HasBinding() == 0)
        return false;
    CItemTransfer::CItemBinding* pBinding = spGem->FUN_140527930()->GetBinding();
    if (pBinding != 0)
    {
        unsigned __int64 nCharacterId = pBinding->FUN_14052d1c0();
        return SetBind(nCharacterId, pBinding->FUN_14052d1b0());
    }
    return true;
}

// @0x14061fd00
bool TSocketGemStoneInfo::SetBind(const unsigned __int64& nCharacterId, const CStringW& strName)
{
    if (nCharacterId > 0)
    {
        m_spBind.AssignRaw(new TSocketGemStoneBind);
        if (m_spBind.get() != 0)
        {
            m_spBind->m_nCharacterId = nCharacterId;
            m_spBind->m_strName = strName;
        }
    }
    return true;
}

// @0x14061fde0
bool TSocketGemStoneInfo::SetLockFromItem(MS2Ptr<CItem> spGem)
{
    if (spGem == 0 || !spGem->FUN_140528e20())
        return false;
    __int64 nExpireTime = spGem->FUN_140528e00();
    int nState = spGem->FUN_140528ca0();
    return TrySetLock(nState, nExpireTime);
}

// @0x14061fea0
bool TSocketGemStoneInfo::TrySetLock(const int& nState, const __int64& nExpireTime)
{
    if (nState == 0 && GetServerTime() >= nExpireTime)
        return false;
    m_spLock.AssignRaw(new TSocketGemStoneLock);
    if (m_spLock.get() != 0)
    {
        m_spLock->m_nState = nState;
        m_spLock->m_nExpireTime = nExpireTime;
    }
    return true;
}

// @0x14061ff90
void TSocketGemStoneInfo::WriteToStream(COutputStream& kOut)
{
    kOut.WriteInt32(m_nGemId);
    if (m_spBind.get() != 0)
    {
        kOut.WriteBool(true);
        m_spBind->Write(kOut);
    }
    else
        kOut.WriteBool(false);
    if (m_spLock.get() != 0)
    {
        kOut.WriteBool(true);
        m_spLock->FUN_14061f630(kOut);
    }
    else
        kOut.WriteBool(false);
}

// @0x140620080
void TSocketGemStoneInfo::ReadFromStream(CInputStream& kIn)
{
    m_nGemId = kIn.ReadInt32();
    bool bBind = kIn.ReadBool();
    if (bBind)
    {
        m_spBind.AssignRaw(new TSocketGemStoneBind);
        m_spBind->Read(kIn);
    }
    bool bLock = kIn.ReadBool();
    if (bLock)
    {
        m_spLock.AssignRaw(new TSocketGemStoneLock);
        m_spLock->FUN_14061f680(kIn);
    }
}

// @0x1406201d0
CStringW TSocketGemStoneInfo::GetBindName()
{
    if (m_spBind.get() != 0)
        return m_spBind->m_strName;
    return CStringW(L"");
}

// @0x140620260
int TSocketGemStoneInfo::GetGemId()
{
    return m_nGemId;
}

// @0x140620280
MS2Ptr<TSocketGemStoneLock> TSocketGemStoneInfo::GetLock()
{
    return m_spLock;
}

// @0x1406202d0
MS2Ptr<TSocketGemStoneBind> TSocketGemStoneInfo::GetBind()
{
    return m_spBind;
}

// @0x140620320
CItemSocket::CItemSocket()
    : m_nMaxSlot(0), m_kStat(17, 0.75f, 0.25f, 2.25f, 10), m_kSpecial(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140620400
CItemSocket::~CItemSocket()
{
    m_aGems.RemoveAll();
}

// @0x140620490
MS2Ptr<CItemSocket> CItemSocket::Clone()
{
    MS2Ptr<CItemSocket> spCopy(new CItemSocket);
    spCopy->m_nMaxSlot = m_nMaxSlot;
    spCopy->m_aGems.Copy(m_aGems);
    CopyEnchantMap(spCopy->m_kStat, m_kStat);
    CopyEnchantMap(spCopy->m_kSpecial, m_kSpecial);
    return spCopy;
}

// @0x1406205e0
void CItemSocket::WriteToStream(COutputStream& kOut)
{
    kOut.WriteUInt8((unsigned char)m_nMaxSlot);
    unsigned nCount = (unsigned)m_aGems.GetCount();
    kOut.WriteUInt8((unsigned char)nCount);
    for (unsigned i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            kOut.WriteBool(false);
        else
        {
            kOut.WriteBool(true);
            spInfo->WriteToStream(kOut);
        }
    }
}

// @0x140620700
void CItemSocket::ReadFromStream(CInputStream& kIn)
{
    m_nMaxSlot = kIn.ReadUInt8();
    unsigned nCount = kIn.ReadUInt8();
    m_aGems.RemoveAll();
    for (unsigned i = 0; i < nCount; i++)
    {
        bool bFilled = kIn.ReadBool();
        MS2Ptr<TSocketGemStoneInfo> spInfo(new TSocketGemStoneInfo);
        m_aGems.Add(spInfo);
        if (bFilled)
            spInfo->ReadFromStream(kIn);
    }
    RebuildStats();
}

// @0x140620840
void CItemSocket::InitSlots(unsigned nMaxSlot, unsigned nCount)
{
    m_nMaxSlot = nMaxSlot;
    m_aGems.RemoveAll();
    m_aGems.SetCount(nCount);
    for (unsigned i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo(new TSocketGemStoneInfo);
        m_aGems.SetAt(i, spInfo);
    }
}

// @0x140620940
int CItemSocket::GetFilledSlotCount()
{
    int nFilled = 0;
    for (unsigned i = 0; i < m_aGems.GetCount(); i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        nFilled++;
    }
    return nFilled;
}

// @0x140620a20
unsigned CItemSocket::GetOpenSlotCount()
{
    return (unsigned)m_aGems.GetCount();
}

// @0x140620a50
unsigned CItemSocket::GetMaxSlot()
{
    return m_nMaxSlot;
}

// @0x140620a70
int CItemSocket::GetLockedSlotCount()
{
    unsigned nOpen = GetOpenSlotCount();
    unsigned nMax = GetMaxSlot();
    if (nMax < nOpen)
        return 0;
    return nMax - nOpen;
}

// @0x140620ac0
int CItemSocket::GetGemId(unsigned nIndex)
{
    if (nIndex >= GetOpenSlotCount())
        return 0;
    MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[nIndex];
    if (spInfo == 0)
        return 0;
    return spInfo->m_nGemId;
}

// @0x140620b70
MS2Ptr<TSocketGemStoneInfo> CItemSocket::GetGemInfo(unsigned nIndex)
{
    if (nIndex >= GetOpenSlotCount())
        return 0;
    MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[nIndex];
    return spInfo;
}

// @0x140620c20
Unk_SocketGemArray& CItemSocket::GetGems()
{
    return m_aGems;
}

// @0x140620c40
MS2Ptr<TSocketGemStoneInfo> CItemSocket::FindFirstBoundGem()
{
    if (GetOpenSlotCount() == 0)
        return 0;
    if (m_aGems.IsEmpty())
        return 0;
    size_t nCount = m_aGems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        if (!spInfo->IsBound())
            continue;
        return spInfo;
    }
    return 0;
}

// @0x140620de0
bool CItemSocket::FUN_140620de0() const
{
    for (unsigned i = 0; i < m_aGems.GetCount(); i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        int nGemId = spInfo->m_nGemId;
        MS2Ptr<CItemData> spData = FUN_14053f870(nGemId);
        if (spData == 0)
            continue;
        if (spData->HasAdditionalEffect())
            return true;
    }
    return false;
}

// @0x140620f40
bool CItemSocket::HasGemId(int nGemId) const
{
    for (unsigned i = 0; i < m_aGems.GetCount(); i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if ((spInfo.get() ? true : false) && spInfo->m_nGemId == nGemId)
            return true;
    }
    return false;
}

// @0x140621020
bool CItemSocket::IsSlotEmpty(unsigned nIndex)
{
    if (nIndex >= m_aGems.GetCount())
        return false;
    MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[nIndex];
    if (spInfo == 0 || spInfo->IsEmpty())
        return true;
    return false;
}

// @0x1406210e0
bool CItemSocket::HasAnyGem()
{
    if (m_aGems.IsEmpty())
        return false;
    size_t nCount = m_aGems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if ((spInfo.get() ? true : false) && !spInfo->IsEmpty())
            return true;
    }
    return false;
}

// @0x1406211f0
bool CItemSocket::HasLockedGem()
{
    if (m_aGems.IsEmpty())
        return false;
    size_t nCount = m_aGems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty() == true)
            continue;
        if (spInfo->IsLocked())
            return true;
    }
    return false;
}

// @0x140621310
bool CItemSocket::HasNoSlots()
{
    return m_aGems.IsEmpty();
}

// @0x140621340
bool CItemSocket::HasEmptyOpenSlot()
{
    unsigned nOpen = GetOpenSlotCount();
    if (nOpen == 0)
        return false;
    return (unsigned)GetFilledSlotCount() < nOpen;
}

// @0x1406213a0
bool CItemSocket::SetGemFromItem(unsigned nIndex, MS2Ptr<CItem> spGem)
{
    if (spGem == 0 || nIndex >= m_aGems.GetCount())
        return false;
    MS2Ptr<TSocketGemStoneInfo> spInfo(new TSocketGemStoneInfo(spGem));
    return SetGemInfo(nIndex, spInfo);
}

// @0x140621500
bool CItemSocket::SetGemById(unsigned nIndex, int nGemId)
{
    if (nIndex >= m_aGems.GetCount())
        return false;
    MS2Ptr<TSocketGemStoneInfo> spInfo(new TSocketGemStoneInfo(nGemId));
    return SetGemInfo(nIndex, spInfo);
}

// @0x140621600
bool CItemSocket::SetGemInfo(unsigned nIndex, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if (spInfo == 0 || nIndex >= m_aGems.GetCount())
        return false;
    m_aGems.SetAt(nIndex, spInfo);
    RebuildStats();
    return true;
}

// @0x1406216b0
bool CItemSocket::UpdateGemId(unsigned nIndex, int nGemId)
{
    if (nIndex >= m_aGems.GetCount())
        return false;
    MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[nIndex];
    if (spInfo == 0)
        return SetGemById(nIndex, nGemId);
    spInfo->m_nGemId = nGemId;
    RebuildStats();
    return true;
}

// @0x140621790
bool CItemSocket::SetGemBind(unsigned nIndex, const unsigned __int64& nCharacterId, const CStringW& strName)
{
    MS2Ptr<TSocketGemStoneInfo> spInfo = GetGemInfo(nIndex);
    if (spInfo == 0)
        return false;
    return spInfo->SetBind(nCharacterId, strName);
}

// @0x140621830
MS2Ptr<TSocketGemStoneInfo> CItemSocket::RemoveGem(unsigned nIndex)
{
    if (nIndex >= m_aGems.GetCount())
        return 0;
    MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[nIndex];
    if (spInfo == 0)
        return 0;
    MS2Ptr<TSocketGemStoneInfo> spEmpty(new TSocketGemStoneInfo);
    m_aGems.SetAt(nIndex, spEmpty);
    RebuildStats();
    return spInfo;
}

// @0x1406219d0
bool CItemSocket::AddSlot(int* pIndex)
{
    *pIndex = -1;
    if (GetLockedSlotCount() == 0 || GetOpenSlotCount() > GetMaxSlot())
        return false;
    *pIndex = (int)m_aGems.GetCount();
    MS2Ptr<TSocketGemStoneInfo> spInfo(new TSocketGemStoneInfo);
    m_aGems.Add(spInfo);
    return true;
}

// @0x140621ac0
bool CItemSocket::ClearSlotsIfAllEmpty()
{
    if (GetOpenSlotCount() == 0)
        return false;
    if (GetFilledSlotCount() != 0)
        return false;
    m_aGems.RemoveAll();
    return true;
}

// @0x140621b10
bool CItemSocket::GetGemStats(Unk_EnchantMap& kOut)
{
    if (m_kStat.IsEmpty())
        return true;
    CopyEnchantMap(kOut, m_kStat);
    return true;
}

// @0x140621b60
bool CItemSocket::FUN_140621b60(Unk_EnchantMap*)
{
    return true;
}

// @0x140621b80
bool CItemSocket::GetGemSpecialStats(Unk_SocketSpecialMap& kOut)
{
    if (m_kSpecial.IsEmpty())
        return true;
    CopyEnchantMap(kOut, m_kSpecial);
    return true;
}

// @0x140621be0
MS2Ptr<BaseOption> CItemSocket::GetSpecialOption(Unk_SocketSpecialStat nStat)
{
    if (m_kSpecial.IsEmpty())
        return MS2Ptr<BaseOption>(0);
    MS2Ptr<BaseOption> spOption(0);
    m_kSpecial.Lookup(nStat, spOption);
    return spOption;
}

// @0x140621ca0
MS2Ptr<BaseOption> CItemSocket::FUN_140621ca0(int)
{
    return MS2Ptr<BaseOption>(0);
}

// @0x140621cf0
bool CItemSocket::CanExpandSlotsTo(unsigned nCount)
{
    unsigned nMax = GetMaxSlot();
    if (nMax == 0)
        return false;
    unsigned nWanted = nMax < nCount ? nMax : nCount;
    if (nWanted <= GetOpenSlotCount())
        return false;
    return true;
}

// @0x140621d60
int CItemSocket::GetFirstGemId()
{
    if (m_aGems.IsEmpty())
        return 0;
    size_t nCount = m_aGems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        return spInfo->m_nGemId;
    }
    return 0;
}

// @0x140621e60
int CItemSocket::AllGemsPass(Unk_GemFilter pfnFilter)
{
    if (GetMaxSlot() == 0 || GetOpenSlotCount() == 0)
        return 1;
    unsigned nOpen = GetOpenSlotCount();
    for (unsigned i = 0; i < nOpen; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = GetGemInfo(i);
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        unsigned nGemId = spInfo->GetGemId();
        MS2Ptr<CItemData> spData = FUN_14053f870(nGemId);
        if (spData == 0)
            continue;
        if (pfnFilter(this, spData.get(), spInfo) == 0)
            return 0;
    }
    return 1;
}

// @0x140622020
int CItemSocket::FUN_140622020(CItemSocket* pSocket, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if ((spInfo.get() ? true : false) && !spInfo->IsEmpty())
        return false;
    return IsGemShopSellable(pSocket, pGemData, spInfo);
}

// @0x1406220f0
int CItemSocket::FUN_1406220f0(CItemSocket* pSocket, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if ((spInfo.get() ? true : false) && !spInfo->IsEmpty())
        return false;
    return FUN_1406224d0(pSocket, pGemData, spInfo);
}

// @0x1406221c0
int CItemSocket::FUN_1406221c0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if (spInfo.get() != 0 && (spInfo->IsBound() || spInfo->IsLocked()))
        return false;
    int nType = FUN_14053feb0(pGemData->GetItemId());
    unsigned nFlags = CItemTransfer::ComputeRule(pGemData->limit.transferType, pGemData, nType);
    if (!FUN_140635b90(nFlags, 4))
        return false;
    return true;
}

// @0x1406222c0
int CItemSocket::FUN_1406222c0(CItemSocket* pSocket, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    return FUN_1406221c0(pSocket, pGemData, spInfo);
}

// @0x140622330
int CItemSocket::FUN_140622330(CItemSocket* pSocket, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if ((spInfo.get() ? true : false) && !spInfo->IsEmpty())
        return false;
    return IsGemBreakable(pSocket, pGemData, spInfo);
}

// @0x140622400
int CItemSocket::IsGemMeratMarketRegistrable(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo>)
{
    return pGemData->limit.enableRegisterMeratMarket;
}

// @0x140622440
int CItemSocket::IsGemShopSellable(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if (spInfo.get() != 0 && spInfo->IsLocked())
        return false;
    return pGemData->limit.shopSell;
}

// @0x1406224d0
int CItemSocket::FUN_1406224d0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if (spInfo.get() != 0 && (spInfo->IsBound() || spInfo->IsLocked()))
        return false;
    int nType = FUN_14053feb0(pGemData->GetItemId());
    unsigned nFlags = CItemTransfer::ComputeRule(pGemData->limit.transferType, pGemData, nType);
    if (!FUN_140635b90(nFlags, 4))
        return false;
    return true;
}

// @0x1406225d0
int CItemSocket::IsGemBreakable(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo)
{
    if (spInfo.get() != 0 && spInfo->IsLocked())
        return false;
    if (pGemData->limit.enableBreak == 0)
        return false;
    return true;
}

// @0x140622680
bool CItemSocket::FUN_140622680()
{
    return !m_aD0.IsEmpty();
}

// @0x1406226d0
bool CItemSocket::FUN_1406226d0()
{
    if (m_aD0.IsEmpty())
        return false;
    m_aD0.RemoveAll();
    return true;
}

// @0x140622720
int CItemSocket::CheckGemsShopSellable()
{
    return AllGemsPass(FUN_140622020);
}

// @0x140622750
int CItemSocket::FUN_140622750()
{
    return AllGemsPass(FUN_1406220f0);
}

// @0x140622780
int CItemSocket::FUN_140622780()
{
    return 0;
}

// @0x140622790
int CItemSocket::FUN_140622790()
{
    return AllGemsPass(FUN_1406221c0);
}

// @0x1406227c0
int CItemSocket::CheckNoBoundGem()
{
    if (HasBoundGem())
        return 0;
    return 1;
}

// @0x1406227f0
int CItemSocket::FUN_1406227f0()
{
    return AllGemsPass(FUN_1406222c0);
}

// @0x140622820
int CItemSocket::CheckGemsBreakable()
{
    return AllGemsPass(FUN_140622330);
}

// @0x140622850
int CItemSocket::CheckNoLockedGem()
{
    if (HasLockedGem())
        return 0;
    return 1;
}

// @0x140622880
int CItemSocket::CheckGemsMeratMarketRegistrable()
{
    return AllGemsPass(IsGemMeratMarketRegistrable);
}

// @0x1406228b0
int CItemSocket::FUN_1406228b0()
{
    return 1;
}

// @0x1406228d0
bool CItemSocket::HasBoundGem()
{
    if (GetOpenSlotCount() == 0)
        return false;
    if (m_aGems.IsEmpty())
        return false;
    size_t nCount = m_aGems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        if (!spInfo->IsBound())
            continue;
        return true;
    }
    return false;
}

// @0x140622a00
bool CItemSocket::AllGemsUsableByCharacter(const __int64* pCharacterId)
{
    if (GetOpenSlotCount() == 0)
        return true;
    if (m_aGems.IsEmpty())
        return true;
    size_t nCount = m_aGems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        if (!spInfo->IsUsableBy(pCharacterId))
            return false;
    }
    return true;
}

// @0x140622b40
void CItemSocket::GetGemBindOwner(__int64* pCharacterId, CStringW* pName)
{
    *pCharacterId = 0;
    pName->Empty();
    if (m_aGems.IsEmpty())
        return;
    size_t nCount = m_aGems.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<TSocketGemStoneInfo> spInfo = m_aGems[i];
        if (spInfo == 0 || spInfo->IsEmpty())
            continue;
        if (!spInfo->IsBound())
            continue;
        MS2Ptr<TSocketGemStoneBind> spBind = spInfo->m_spBind;
        if (spBind == 0)
            continue;
        *pName = spBind->m_strName;
        *pCharacterId = spBind->m_nCharacterId;
    }
}

// @0x140622d00
void CItemSocket::RebuildStats()
{
    m_kStat.RemoveAll();
    m_kSpecial.RemoveAll();
    if (GetMaxSlot() == 0 || GetOpenSlotCount() == 0)
        return;
    unsigned nOpen = GetOpenSlotCount();
    for (unsigned i = 0; i < nOpen; i++)
    {
        int nGemId = GetGemId(i);
        if (nGemId == 0)
            continue;
        MS2Ptr<CItemOption> spOption(new CItemOption(nGemId));
        if (spOption == 0)
            continue;
        int nRank = FUN_14053feb0(nGemId);
        FUN_140166430()->ApplyConstantOptions(spOption, nGemId, nRank);
        AccumulateStatOptions(spOption);
        AccumulateSpecialOptions(spOption);
    }
}

// @0x140622f10
void CItemSocket::AccumulateStatOptions(MS2Ptr<CItemOption> spOption)
{
    if (spOption == 0)
        return;
    Unk_EnchantMap& kFrom = spOption->GetStatMap(0);
    if (kFrom.IsEmpty())
        return;
    for (POSITION pos = kFrom.GetStartPosition(); pos != 0; kFrom.GetNext(pos))
    {
        MS2Ptr<BaseOption> spFrom = kFrom.GetValueAt(pos);
        if (spFrom == 0)
            continue;
        int nStat = kFrom.GetKeyAt(pos);
        MS2Ptr<BaseOption> spSum(0);
        if (m_kStat.Lookup(nStat, spSum))
            spSum->SetValue(spSum->GetValue() + spFrom->GetValue());
        else
            m_kStat.SetAt(nStat, spFrom);
    }
}

// @0x1406230e0
void CItemSocket::AccumulateSpecialOptions(MS2Ptr<CItemOption> spOption)
{
    if (spOption == 0)
        return;
    Unk_SocketSpecialMap& kFrom = spOption->GetSpecialMap(0);
    if (kFrom.IsEmpty())
        return;
    for (POSITION pos = kFrom.GetStartPosition(); pos != 0; kFrom.GetNext(pos))
    {
        MS2Ptr<BaseOption> spFrom = kFrom.GetValueAt(pos);
        if (spFrom == 0)
            continue;
        Unk_SocketSpecialStat nStat = kFrom.GetKeyAt(pos);
        MS2Ptr<BaseOption> spSum(0);
        if (m_kSpecial.Lookup(nStat, spSum))
            spSum->SetValue(spSum->GetValue() + spFrom->GetValue());
        else
            m_kSpecial.SetAt(nStat, spFrom);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
