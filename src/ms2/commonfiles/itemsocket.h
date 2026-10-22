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
    void FUN_14061f540(COutputStream& kOut);        // 0x14061f540 write
    void FUN_14061f5a0(CInputStream& kIn);          // 0x14061f5a0 read

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
    bool FUN_14061f6d0();                           // 0x14061f6d0 is locked now
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
    void FUN_14061f930(MS2Ptr<CItem> spGem);        // 0x14061f930 init from a gemstone item
    void FUN_14061fa50();                           // 0x14061fa50 clear
    bool FUN_14061fab0();                           // 0x14061fab0 no gemstone
    bool FUN_14061faf0();                           // 0x14061faf0 bound to a character
    bool FUN_14061fb40(const __int64* pCharacterId);   // 0x14061fb40 unbound or bound to this character
    bool FUN_14061fbb0();                           // 0x14061fbb0 locked
    bool FUN_14061fc00(MS2Ptr<CItem> spGem);        // 0x14061fc00 take the binding of a gemstone item
    bool FUN_14061fd00(const unsigned __int64& nCharacterId, const CStringW& strName);   // 0x14061fd00 bind
    bool FUN_14061fde0(MS2Ptr<CItem> spGem);        // 0x14061fde0 take the lock of a gemstone item
    bool FUN_14061fea0(const int& nState, const __int64& nExpireTime);   // 0x14061fea0 lock
    void FUN_14061ff90(COutputStream& kOut);        // 0x14061ff90 write
    void FUN_140620080(CInputStream& kIn);          // 0x140620080 read
    CStringW FUN_1406201d0();                       // 0x1406201d0 the bound character name
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
    // A per-gemstone test of FUN_140621e60 (the socket, the gemstone item data, the socket record).
    typedef int (*Unk_GemFilter)(CItemSocket* pSocket, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);

    CItemSocket();                                  // 0x140620320
    virtual ~CItemSocket();                         // 0x140620400
    MS2Ptr<CItemSocket> FUN_140620490();            // 0x140620490 copy
    void FUN_1406205e0(COutputStream& kOut);        // 0x1406205e0 write
    void FUN_140620700(CInputStream& kIn);          // 0x140620700 read
    void FUN_140620840(unsigned nMaxSlot, unsigned nCount);   // 0x140620840 reset to empty sockets
    int FUN_140620940();                            // 0x140620940 the filled socket count
    unsigned FUN_140620a20();                       // 0x140620a20 the open socket count
    unsigned GetMaxSlot();                       // 0x140620a50 the max socket count
    int FUN_140620a70();                            // 0x140620a70 the sockets left to open
    int FUN_140620ac0(unsigned nIndex);             // 0x140620ac0 the gemstone id in a socket
    MS2Ptr<TSocketGemStoneInfo> FUN_140620b70(unsigned nIndex);   // 0x140620b70
    Unk_SocketGemArray& FUN_140620c20();            // 0x140620c20
    MS2Ptr<TSocketGemStoneInfo> FUN_140620c40();    // 0x140620c40 the first bound gemstone
    bool FUN_140620de0() const;                     // 0x140620de0
    bool FUN_140620f40(int nGemId) const;           // 0x140620f40 has this gemstone
    bool FUN_140621020(unsigned nIndex);            // 0x140621020 the socket is open and empty
    bool FUN_1406210e0();                           // 0x1406210e0 has a gemstone
    bool FUN_1406211f0();                           // 0x1406211f0 has a locked gemstone
    bool FUN_140621310();                           // 0x140621310 no sockets
    bool FUN_140621340();                           // 0x140621340 has an empty socket
    bool FUN_1406213a0(unsigned nIndex, MS2Ptr<CItem> spGem);   // 0x1406213a0
    bool FUN_140621500(unsigned nIndex, int nGemId);            // 0x140621500
    bool FUN_140621600(unsigned nIndex, MS2Ptr<TSocketGemStoneInfo> spInfo);   // 0x140621600
    bool FUN_1406216b0(unsigned nIndex, int nGemId);            // 0x1406216b0
    bool FUN_140621790(unsigned nIndex, const unsigned __int64& nCharacterId, const CStringW& strName);   // 0x140621790
    MS2Ptr<TSocketGemStoneInfo> FUN_140621830(unsigned nIndex); // 0x140621830 take the gemstone out
    bool FUN_1406219d0(int* pIndex);                // 0x1406219d0 open a socket
    bool FUN_140621ac0();                           // 0x140621ac0 drop the sockets when all are empty
    bool FUN_140621b10(Unk_EnchantMap& kOut);       // 0x140621b10 copy the stat options (+0x40)
    bool FUN_140621b60(Unk_EnchantMap* pOut);       // 0x140621b60
    bool FUN_140621b80(Unk_SocketSpecialMap& kOut); // 0x140621b80 copy the special-stat options (+0x88)
    Unk_EnchantPtr<BaseOption> FUN_140621be0(Unk_SocketSpecialStat nStat);   // 0x140621be0
    Unk_EnchantPtr<BaseOption> FUN_140621ca0(int nStat);        // 0x140621ca0
    bool FUN_140621cf0(unsigned nCount);            // 0x140621cf0
    int FUN_140621d60();                            // 0x140621d60 the first gemstone id
    int FUN_140621e60(Unk_GemFilter pfnFilter);     // 0x140621e60 every gemstone passes
    bool FUN_140622680();                           // 0x140622680
    bool FUN_1406226d0();                           // 0x1406226d0
    int FUN_140622720();                            // 0x140622720
    int FUN_140622750();                            // 0x140622750
    int FUN_140622780();                            // 0x140622780
    int FUN_140622790();                            // 0x140622790
    int FUN_1406227c0();                            // 0x1406227c0
    int FUN_1406227f0();                            // 0x1406227f0
    int FUN_140622820();                            // 0x140622820
    int FUN_140622850();                            // 0x140622850
    int FUN_140622880();                            // 0x140622880
    int FUN_1406228b0();                            // 0x1406228b0
    bool FUN_1406228d0();                           // 0x1406228d0 has a bound gemstone
    bool FUN_140622a00(const __int64* pCharacterId);    // 0x140622a00 every gemstone usable by the character
    void FUN_140622b40(__int64* pCharacterId, CStringW* pName);   // 0x140622b40 the bound character
    void FUN_140622d00();                           // 0x140622d00 rebuild the options from the gemstones
    void FUN_140622f10(MS2Ptr<CItemOption> spOption);   // 0x140622f10 add the stat options
    void FUN_1406230e0(MS2Ptr<CItemOption> spOption);   // 0x1406230e0 add the special-stat options
private:
    static int FUN_140622020(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406220f0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406221c0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406222c0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_140622330(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_140622400(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_140622440(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406224d0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);
    static int FUN_1406225d0(CItemSocket*, CItemData* pGemData, MS2Ptr<TSocketGemStoneInfo> spInfo);

    unsigned m_nMaxSlot;                            // +0x18
    Unk_SocketGemArray m_aGems;                     // +0x20
    Unk_EnchantMap m_kStat;                         // +0x40 the summed stat options of the gemstones
    Unk_SocketSpecialMap m_kSpecial;                // +0x88 the summed special-stat options
    Unk_SocketGemArray m_aD0;                       // +0xd0
    friend class ASTooltip;                         // astooltip.cpp 0x1409cc800 calls the gem filters FUN_1406221c0/FUN_140622440
};
MS2_CHECK_SIZE(CItemSocket, 0xf0);
