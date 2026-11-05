// itemsocket.h - CItemSocket, the gemstone sockets of an item (alloc 0xf0), and its per-socket records
// TSocketGemStoneInfo / TSocketGemStoneBind / TSocketGemStoneLock (RTTI names). Recovered from ?\itemsocket.cpp
// (0x14061f540-0x140624700). Member names are invented from use.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/itemoption.h"

class COutputStream;
class CInputStream;
class CItem;
class CItemData;

// The character a socketed gemstone is bound to (alloc 0x28).
class TSocketGemStoneBind : public CPtred
{
public:
    TSocketGemStoneBind() : m_nCharacterId(0) {}    // 0x140623520
    void Write(COutputStream& kOut);        // 0x14061f540 write
    void Read(CInputStream& kIn);          // 0x14061f5a0 read

    __int64 m_nCharacterId;                         // +0x18
    CStringW m_strName;                             // +0x20
};
MS2_CHECK_SIZE(TSocketGemStoneBind, 0x28);

// The lock of a socketed gemstone: state 1 is locked, state 0 stays locked until the expire time (alloc 0x28).
class TSocketGemStoneLock : public CPtred
{
public:
    TSocketGemStoneLock() : m_nState(0), m_nExpireTime(0) {}   // 0x140623570
    void FUN_14061f630(COutputStream& kOut);        // 0x14061f630 write
    void FUN_14061f680(CInputStream& kIn);          // 0x14061f680 read
    bool IsLocked();                           // 0x14061f6d0 is locked now
    bool FUN_14061f730();                           // 0x14061f730 state != 1
    bool FUN_14061f760();                           // 0x14061f760 state == 1
    int FUN_140623e20() { return m_nState; }                // 0x140623e20
    __int64 FUN_140623e10() { return m_nExpireTime; }       // 0x140623e10

    int m_nState;                                   // +0x18
    __int64 m_nExpireTime;                          // +0x20
};
MS2_CHECK_SIZE(TSocketGemStoneLock, 0x28);

// One gemstone socket of an item (alloc 0x48).
class TSocketGemStoneInfo : public CPtred
{
public:
    TSocketGemStoneInfo();                          // 0x14061f790
    TSocketGemStoneInfo(const int& nGemId);         // 0x14061f800
    TSocketGemStoneInfo(MS2Ptr<CItem> spGem);       // 0x14061f880
    void SetFromItem(MS2Ptr<CItem> spGem);        // 0x14061f930 init from a gemstone item
    void Reset();                           // 0x14061fa50 clear
    bool IsEmpty();                           // 0x14061fab0 no gemstone
    bool IsBound();                           // 0x14061faf0 bound to a character
    bool IsUsableBy(const __int64* pCharacterId);   // 0x14061fb40 unbound or bound to this character
    bool IsLocked();                           // 0x14061fbb0 locked
    bool SetBindFromItem(MS2Ptr<CItem> spGem);        // 0x14061fc00 take the binding of a gemstone item
    bool SetBind(const unsigned __int64& nCharacterId, const CStringW& strName);   // 0x14061fd00 bind
    bool SetLockFromItem(MS2Ptr<CItem> spGem);        // 0x14061fde0 take the lock of a gemstone item
    bool TrySetLock(const int& nState, const __int64& nExpireTime);   // 0x14061fea0 lock
    void WriteToStream(COutputStream& kOut);        // 0x14061ff90 write
    void ReadFromStream(CInputStream& kIn);          // 0x140620080 read
    CStringW GetBindName();                       // 0x1406201d0 the bound character name
    int GetGemId();                            // 0x140620260 the gemstone id
    MS2Ptr<TSocketGemStoneLock> GetLock();    // 0x140620280
    MS2Ptr<TSocketGemStoneBind> GetBind();    // 0x1406202d0

    int m_nGemId;                                   // +0x18 gemstone item id
    MS2Ptr<TSocketGemStoneBind> m_spBind;           // +0x20
    MS2Ptr<TSocketGemStoneLock> m_spLock;           // +0x30
    int m_n40;                                      // +0x40 from the gemstone's CItemTransfer
};
MS2_CHECK_SIZE(TSocketGemStoneInfo, 0x48);

typedef ATL::CAtlArray<MS2Ptr<TSocketGemStoneInfo> > Unk_SocketGemArray;

class CItemSocket : public CPtred
{
public:
    // A per-gemstone test of AllGemsPass (the socket, the gemstone item data, the socket record).
    typedef int (*Unk_GemFilter)(CItemSocket* pSocket, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);

    CItemSocket();                                  // 0x140620320
    virtual ~CItemSocket();                         // 0x140620400
    MS2Ptr<CItemSocket> Clone();            // 0x140620490 copy
    void WriteToStream(COutputStream& kOut);        // 0x1406205e0 write
    void ReadFromStream(CInputStream& kIn);          // 0x140620700 read
    void InitSlots(unsigned nMaxSlot, unsigned nCount);   // 0x140620840 reset to empty sockets
    int GetFilledSlotCount();                            // 0x140620940 the filled socket count
    unsigned GetOpenSlotCount();                       // 0x140620a20 the open socket count
    unsigned GetMaxSlot();                       // 0x140620a50 the max socket count
    int GetLockedSlotCount();                            // 0x140620a70 the sockets left to open
    int GetGemId(unsigned nIndex);             // 0x140620ac0 the gemstone id in a socket
    MS2Ptr<TSocketGemStoneInfo> GetGemInfo(unsigned nIndex);   // 0x140620b70
    Unk_SocketGemArray& GetGems();            // 0x140620c20
    MS2Ptr<TSocketGemStoneInfo> FindFirstBoundGem();    // 0x140620c40 the first bound gemstone
    bool FUN_140620de0() const;                     // 0x140620de0
    bool HasGemId(int nGemId) const;           // 0x140620f40 has this gemstone
    bool IsSlotEmpty(unsigned nIndex);            // 0x140621020 the socket is open and empty
    bool HasAnyGem();                           // 0x1406210e0 has a gemstone
    bool HasLockedGem();                           // 0x1406211f0 has a locked gemstone
    bool HasNoSlots();                           // 0x140621310 no sockets
    bool HasEmptyOpenSlot();                           // 0x140621340 has an empty socket
    bool SetGemFromItem(unsigned nIndex, MS2Ptr<CItem> spGem);   // 0x1406213a0
    bool SetGemById(unsigned nIndex, int nGemId);            // 0x140621500
    bool SetGemInfo(unsigned nIndex, MS2Ptr<TSocketGemStoneInfo> spInfo);   // 0x140621600
    bool UpdateGemId(unsigned nIndex, int nGemId);            // 0x1406216b0
    bool SetGemBind(unsigned nIndex, const unsigned __int64& nCharacterId, const CStringW& strName);   // 0x140621790
    MS2Ptr<TSocketGemStoneInfo> RemoveGem(unsigned nIndex); // 0x140621830 take the gemstone out
    bool AddSlot(int* pIndex);                // 0x1406219d0 open a socket
    bool ClearSlotsIfAllEmpty();                           // 0x140621ac0 drop the sockets when all are empty
    bool GetGemStats(Unk_EnchantMap& kOut);       // 0x140621b10 copy the stat options (+0x40)
    bool FUN_140621b60(Unk_EnchantMap* pOut);       // 0x140621b60
    bool GetGemSpecialStats(Unk_SocketSpecialMap& kOut); // 0x140621b80 copy the special-stat options (+0x88)
    MS2Ptr<BaseOption> GetSpecialOption(Unk_SocketSpecialStat nStat);   // 0x140621be0
    MS2Ptr<BaseOption> FUN_140621ca0(int nStat);        // 0x140621ca0
    bool CanExpandSlotsTo(unsigned nCount);            // 0x140621cf0
    int GetFirstGemId();                            // 0x140621d60 the first gemstone id
    int AllGemsPass(Unk_GemFilter pfnFilter);     // 0x140621e60 every gemstone passes
    bool FUN_140622680();                           // 0x140622680
    bool FUN_1406226d0();                           // 0x1406226d0
    int CheckGemsShopSellable();                            // 0x140622720
    int FUN_140622750();                            // 0x140622750
    int FUN_140622780();                            // 0x140622780
    int FUN_140622790();                            // 0x140622790
    int CheckNoBoundGem();                            // 0x1406227c0
    int FUN_1406227f0();                            // 0x1406227f0
    int CheckGemsBreakable();                            // 0x140622820
    int CheckNoLockedGem();                            // 0x140622850
    int CheckGemsMeratMarketRegistrable();                            // 0x140622880
    int FUN_1406228b0();                            // 0x1406228b0
    bool HasBoundGem();                           // 0x1406228d0 has a bound gemstone
    bool AllGemsUsableByCharacter(const __int64* pCharacterId);    // 0x140622a00 every gemstone usable by the character
    void GetGemBindOwner(__int64* pCharacterId, CStringW* pName);   // 0x140622b40 the bound character
    void RebuildStats();                           // 0x140622d00 rebuild the options from the gemstones
    void AccumulateStatOptions(MS2Ptr<CItemOption> spOption);   // 0x140622f10 add the stat options
    void AccumulateSpecialOptions(MS2Ptr<CItemOption> spOption);   // 0x1406230e0 add the special-stat options
private:
    static int FUN_140622020(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406220f0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406221c0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406222c0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_140622330(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int IsGemMeratMarketRegistrable(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int IsGemShopSellable(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406224d0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int IsGemBreakable(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);

    unsigned m_nMaxSlot;                            // +0x18
    Unk_SocketGemArray m_aGems;                     // +0x20
    Unk_EnchantMap m_kStat;                         // +0x40 the summed stat options of the gemstones
    Unk_SocketSpecialMap m_kSpecial;                // +0x88 the summed special-stat options
    Unk_SocketGemArray m_aD0;                       // +0xd0
    friend class ASTooltip;                         // astooltip.cpp 0x1409cc800 calls the gem filters FUN_1406221c0/IsGemShopSellable
};
MS2_CHECK_SIZE(CItemSocket, 0xf0);
