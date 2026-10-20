// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: the free-for-all PvP ranking list. The server's
// kill-feed / score packets (0x67-0x6a) update a list of player rows (sorted by score) plus an id -> rank map and refresh the
// ranking (0x4e9a) and result (0x4e9b) dialogs; descriptive names are provisional.
// MS2-UNIT: unit_141017950
// MS2-RANGE: 0x1400e3ce0-0x1400e3e80 .text$di
// MS2-RANGE: 0x141017950-0x14101b7f0 .text$mn
// MS2-PIN: ??1Unk_PvpTimerItem@@QEAA@XZ 0x14101a1b0
// MS2-PIN: ??0CPair@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@IEAA@_K@Z 0x14101a100
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0CNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA@_KI@Z 0x14101a0c0 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x14101a240 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x14101a2c0 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x14101a2e0 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x14101a300 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXXZ 0x14101a3f0 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBAIXZ 0x14101a440 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x14101a450 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAA_NI_N@Z 0x14101a540 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEBA_NXZ 0x14101a660 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEBA_N_KAEAH@Z 0x14101a690 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x14101a6f0 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEBAI_K@Z 0x14101a900 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXI@Z 0x14101a9f0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x14101ac20 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x14101ad30 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x14101ae20 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@QEAAPEAU__POSITION@@_KH@Z 0x14101aee0 ; unique
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@_KHV?$CElementTraits@_K@ATL@@V?$CElementTraits@H@2@@ATL@@AEAAXXZ 0x14101af70 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@PEAUUnk_PvpTimerItem@@@std@@V?$_Vector_val@U?$_Simple_types@PEAUUnk_PvpTimerItem@@@std@@@2@$00@std@@QEBAAEBV?$allocator@PEAUUnk_PvpTimerItem@@@2@XZ 0x14101b280 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <algorithm>
#include <vector>

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uipvprankingdialog.h"
#include "ms2/client/ms2/uipvpresultdialog.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

// One row of the ranking (0x30 bytes; see uipvprankingdialog.cpp / uipvpresultdialog.cpp for the readers).
struct Unk_PvpTimerItem
{
    Unk_PvpTimerItem(unsigned __int64 nCharId, const CStringW& strName, int nScore, int nKill, int nDeath, unsigned n1c);
    ~Unk_PvpTimerItem();                                            // 0x14101a1b0
    void* FUN_14101a200(unsigned nFlags);                           // scalar deleting destructor

    unsigned __int64 m_nCharId;         // +0x00
    CStringW m_strName;                 // +0x08
    int m_nScore;                       // +0x10
    int m_nKill;                        // +0x14
    int m_nDeath;                       // +0x18
    unsigned m_n1c;                     // +0x1c
    __int64 m_nDamage;                  // +0x20
    bool m_bOnline;                     // +0x28
};

class Unk_PvpWorld                                                  // the world service
{
public:
    MyPC* FUN_141bd0cc0();                                          // the local player
    PCBase* FUN_141bd1530(unsigned __int64 nCharId);                // a player by character id
};
Unk_PvpWorld* FUN_1403ed2d0();

// The player's PvP info proxy (PC method 0x140967420): operator-> 0x140965970, release 0x140964aa0.
class Unk_PvInfoPtr
{
public:
    ~Unk_PvInfoPtr() { FUN_140964aa0(); }
    CPvPInfo* FUN_140965970() const;                                // operator->
    void FUN_140964aa0();                                           // release
    void* m_pad_00;
    CPvPInfo* m_p;
};
class Unk_PvActor { public: Unk_PvInfoPtr FUN_140967420(); };

class UIObject;
class Unk_PvpUiService                                              // the UI service
{
public:
    int FUN_141adc940(int nClass);                                  // dialog closed
    void FUN_141adc530(int nClass);                                 // open a dialog
    MS2Ptr<UIObject> FUN_141adcea0(int nClass);                     // object by class id
};
Unk_PvpUiService* FUN_1403ed2b0();

CStringW FUN_14052bd00(int nStringId, const CStringW& strName);     // formatted message
void FUN_1412751f0(const CStringW& strText, int nType, int nFlag);  // post a notice
void FUN_141276180(const CString& strSound, const CString& strArg); // play a sound by name
void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_142cab370();                                               // the exe's atexit destructor of the marker

struct Unk_PvpMarker {};

// ---- dynamic initializers (.text$di) ----

// @0x1400e3ce0
static CString s_killSlayer("System_KillSlayer");

// @0x1400e3d10
static CString s_sortNames[7] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400e3dd0
static CString s_skill("skill");

// @0x1400e3e00
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x1400e3e30
static char s_marker[0x48];
static Unk_PvpMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142cab370), Unk_PvpMarker());
#endif

// ---- the rank map and rows ----

// The rank list: an id -> rank map (rank = 1 + index) and the rows (0x48 map + vector at +0x48).
class Unk_PvpTimer
{
public:
    void FUN_141017950(int nMessage, CInPacket& packet);            // OnMessage
    void FUN_141017e80();                                           // clear
    int FUN_141017f40(__int64 nCharId);                             // the rank of a character
    int FUN_141017f80();                                            // the row count
    Unk_PvpTimerItem* FUN_141017fb0(int nRank);                     // the row of a rank
    void FUN_141018010();                                           // sort the rows, rebuild the map
    void FUN_141018260(unsigned __int64 nCharId, int nScore, int nKill, int nDeath, unsigned n1c);   // add / update a row
    void FUN_141018540(unsigned __int64 nCharId, unsigned __int64 nDamage);                           // set the damage of a row

    ATL::CAtlMap<unsigned __int64, int> m_ranks;                    // +0x00
    std::vector<Unk_PvpTimerItem*> m_items;                         // +0x48
};
MS2_CHECK_SIZE(Unk_PvpTimer, 0x60);

bool FUN_141018720(Unk_PvpTimerItem* pA, Unk_PvpTimerItem* pB);
bool FUN_141018870(Unk_PvpTimerItem* pA, Unk_PvpTimerItem* pB);
UIPvPRankingDialog* FUN_1410189e0(int nClass);
UIPvPResultDialog* FUN_141018a80(int nClass);

// MS2-FUNCTIONAL: behaviour-equivalent (frame layout / temp slots differ)
// @0x141017950
void Unk_PvpTimer::FUN_141017950(int nMessage, CInPacket& packet)
{
    if (nMessage == 0x67)
    {
        __int64 nCharId = packet.vfunc_o8_4();
        int nScore = packet.vfunc_o8_3();
        int nKill = packet.vfunc_o8_3();
        int nDeath = packet.vfunc_o8_3();
        int n1c = packet.vfunc_o8_3();
        int nFrom = FUN_141017f40(nCharId);
        FUN_141018260(nCharId, nScore, nKill, nDeath, n1c);
        int nTo = FUN_141017f40(nCharId);
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e9a) != 0)
            FUN_1403ed2b0()->FUN_141adc530(0x4e9a);
        UIPvPRankingDialog* pRanking = FUN_1410189e0(0x4e9a);
        if (pRanking != 0)
            pRanking->FUN_1413432b0();
        UIPvPResultDialog* pResult = FUN_141018a80(0x4e9b);
        if (pResult != 0)
        {
            pResult->FUN_1413440a0();
            pResult->FUN_141343c10(nFrom, nTo);
        }
    }
    else if (nMessage == 0x68)
    {
        Unk_PvpTimerItem* pFirst = FUN_141017fb0(1);
        if (pFirst != 0)
            FUN_141018260(pFirst->m_nCharId, pFirst->m_nScore, pFirst->m_nKill, pFirst->m_nDeath, pFirst->m_n1c);
        int nRank = packet.vfunc_o8_3();
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e9b) != 0)
            FUN_1403ed2b0()->FUN_141adc530(0x4e9b);
        UIPvPResultDialog* pResult = FUN_141018a80(0x4e9b);
        if (pResult != 0)
            pResult->FUN_141343da0(nRank);
    }
    else if (nMessage == 0x69)
    {
        int nStringId = packet.vfunc_o8_3();
        CStringW strName = packet.vfunc_o8_8();
        CStringW strText = FUN_14052bd00(nStringId, strName);
        FUN_1412751f0(strText, 4, 1);
        FUN_141276180(s_killSlayer, CString(""));
    }
    else if (nMessage == 0x6a)
    {
        __int64 nCharId = packet.vfunc_o8_4();
        unsigned __int64 nDamage = (unsigned)packet.vfunc_o8_3();
        int nFrom = FUN_141017f40(nCharId);
        FUN_141018540(nCharId, nDamage);
        int nTo = FUN_141017f40(nCharId);
        UIPvPRankingDialog* pRanking = FUN_1410189e0(0x4e9a);
        if (pRanking != 0)
            pRanking->FUN_1413432b0();
        UIPvPResultDialog* pResult = FUN_141018a80(0x4e9b);
        if (pResult != 0)
            pResult->FUN_141343c10(nFrom, nTo);
    }
}

// @0x141017e80
void Unk_PvpTimer::FUN_141017e80()
{
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        Unk_PvpTimerItem* pItem = m_items[i];
        Unk_PvpTimerItem* pDelete = pItem;
        pDelete ? pDelete->FUN_14101a200(1) : 0;
    }
    m_items.clear();
    m_ranks.RemoveAll();
}

// @0x141017f40
int Unk_PvpTimer::FUN_141017f40(__int64 nCharId)
{
    int nRank = 0;
    m_ranks.Lookup(nCharId, nRank);
    return nRank;
}

// @0x141017f80
int Unk_PvpTimer::FUN_141017f80()
{
    return (int)m_items.size();
}

// @0x141017fb0
Unk_PvpTimerItem* Unk_PvpTimer::FUN_141017fb0(int nRank)
{
    int nIndex = nRank - 1;
    if (nIndex < 0 || nIndex >= (int)m_items.size())
        return 0;
    return m_items[nIndex];
}

// MS2-FUNCTIONAL: behaviour-equivalent (one more 8-byte local in the exe frame)
// @0x141018010
void Unk_PvpTimer::FUN_141018010()
{
    Unk_PvActor* pPC = (Unk_PvActor*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    if (pPC->FUN_140967420().FUN_140965970()->m_nMode == 2)
        std::sort(m_items.begin(), m_items.end(), FUN_141018720);
    else if (pPC->FUN_140967420().FUN_140965970()->m_nMode == 5)
        std::sort(m_items.begin(), m_items.end(), FUN_141018870);
    m_ranks.RemoveAll();
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        if (m_items[i] != 0)
            m_ranks.SetAt(m_items[i]->m_nCharId, (int)i + 1);
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent (temp slots differ)
// @0x141018260
void Unk_PvpTimer::FUN_141018260(unsigned __int64 nCharId, int nScore, int nKill, int nDeath, unsigned n1c)
{
    Unk_PvpTimerItem* pItem = 0;
    int nIndex = 0;
    if (!m_ranks.Lookup(nCharId, nIndex))
    {
        CStringW strName(L"Unknown");
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd1530(nCharId);
        if (pPlayer != 0)
            strName = pPlayer->vfunc_77();
        pItem = new Unk_PvpTimerItem(nCharId, strName, nScore, nKill, nDeath, n1c);
        m_items.push_back(pItem);
    }
    else
    {
        pItem = m_items[nIndex - 1];
        pItem->m_nScore = nScore;
        pItem->m_nKill = nKill;
        pItem->m_nDeath = nDeath;
        pItem->m_n1c = n1c;
    }
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        if (FUN_1403ed2d0()->FUN_141bd1530(m_items[i]->m_nCharId) == 0)
            m_items[i]->m_bOnline = false;
        else
            m_items[i]->m_bOnline = true;
    }
    FUN_141018010();
}

// MS2-FUNCTIONAL: behaviour-equivalent (temp slots differ)
// @0x141018540
void Unk_PvpTimer::FUN_141018540(unsigned __int64 nCharId, unsigned __int64 nDamage)
{
    Unk_PvpTimerItem* pItem = 0;
    int nIndex = 0;
    if (!m_ranks.Lookup(nCharId, nIndex))
    {
        CStringW strName(L"Unknown");
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd1530(nCharId);
        if (pPlayer != 0)
            strName = pPlayer->vfunc_77();
        pItem = new Unk_PvpTimerItem(nCharId, strName, 0, 0, 0, 0);
        pItem->m_nDamage = nDamage;
        m_items.push_back(pItem);
    }
    else
    {
        pItem = m_items[nIndex - 1];
        pItem->m_nDamage = nDamage;
    }
    FUN_141018010();
}

// The sort orders: online rows first, then by score (mode 2: kill, fewer deaths, damage) / (mode 5: kill, fewer deaths).
// @0x141018720
bool FUN_141018720(Unk_PvpTimerItem* pA, Unk_PvpTimerItem* pB)
{
    if (pA == 0)
        return false;
    if (pB == 0)
        return true;
    if (!pA->m_bOnline)
        return false;
    else if (!pB->m_bOnline)
        return true;
    if (pA->m_nScore > pB->m_nScore)
        return true;
    else if (pA->m_nScore < pB->m_nScore)
        return false;
    if (pA->m_nKill > pB->m_nKill)
        return true;
    else if (pA->m_nKill < pB->m_nKill)
        return false;
    if (pA->m_nDeath < pB->m_nDeath)
        return true;
    else if (pA->m_nDeath > pB->m_nDeath)
        return false;
    if (pA->m_nDamage > pB->m_nDamage)
        return true;
    else if (pA->m_nDamage < pB->m_nDamage)
        return false;
    return pA->m_nCharId > pB->m_nCharId;
}

// @0x141018870
bool FUN_141018870(Unk_PvpTimerItem* pA, Unk_PvpTimerItem* pB)
{
    if (pA == 0)
        return false;
    if (pB == 0)
        return true;
    if (pA->m_nScore > pB->m_nScore)
        return true;
    else if (pA->m_nScore < pB->m_nScore)
        return false;
    if (pA->m_nKill > pB->m_nKill)
        return true;
    else if (pA->m_nKill < pB->m_nKill)
        return false;
    if (pA->m_nDeath < pB->m_nDeath)
        return true;
    else if (pA->m_nDeath > pB->m_nDeath)
        return false;
    if (pA->m_n1c < pB->m_n1c)
        return true;
    else if (pA->m_n1c > pB->m_n1c)
        return false;
    return pA->m_nCharId > pB->m_nCharId;
}

// @0x1410189e0
UIPvPRankingDialog* FUN_1410189e0(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObject.get() != 0)
            return dynamic_cast<UIPvPRankingDialog*>((UIObject*)spObject);
    }
    return 0;
}

// @0x141018a80
UIPvPResultDialog* FUN_141018a80(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObject.get() != 0)
            return dynamic_cast<UIPvPResultDialog*>((UIObject*)spObject);
    }
    return 0;
}

// ---- the row ----

// @0x14101a120
Unk_PvpTimerItem::Unk_PvpTimerItem(unsigned __int64 nCharId, const CStringW& strName, int nScore, int nKill, int nDeath, unsigned n1c)
    : m_nCharId(nCharId), m_strName(strName), m_nScore(nScore), m_nKill(nKill), m_nDeath(nDeath), m_n1c(n1c), m_nDamage(0)
{
}

// @0x14101a1b0
Unk_PvpTimerItem::~Unk_PvpTimerItem()
{
}

// @0x14101a200
void* Unk_PvpTimerItem::FUN_14101a200(unsigned nFlags)
{
    this->Unk_PvpTimerItem::~Unk_PvpTimerItem();
    if ((nFlags & 1) != 0)
        operator delete(this, sizeof(Unk_PvpTimerItem));
    return this;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cab2e0-0x142cab390 .text$yd
