// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: the team PvP (battlefield) member tables. Two
// tables (teams 0xc9 and 0xca) of player rows (kills / wins / losses / job, sorted online first, then by name) fed by the
// server's team packets (0x6b-0x71); the result (0x4ed2), score (0x4ed3) and flag gauge (0x4ed4) dialogs are refreshed from
// them. Descriptive names are provisional; the layouts are in client\ms2\pvpmanager.h.
// MS2-UNIT: unit_14101b7f0
// MS2-RANGE: 0x14101b7f0-0x141020350 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FUN_14101ec80@Unk_PvInfoPtr@@QEBA_NPEBVCPvPInfo@@@Z 0x14101ec80 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <algorithm>
#include <vector>

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/pvpmanager.h"
#include "ms2/client/ms2/uipvpteamflaggaguedialog.h"
#include "ms2/client/ms2/uipvpteamresultdialog.h"
#include "ms2/client/ms2/uipvpteamscoredialog.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/commonfiles/pvpinfo.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

class Unk_PvpWorld                                                  // the world service
{
public:
    PCBase* FUN_141bd1530(unsigned __int64 nCharId);                // a player by character id
};
Unk_PvpWorld* FUN_1403ed2d0();

// The player's PvP info proxy (PC method 0x140967420): operator-> 0x140965970, release 0x140964aa0.
class Unk_PvInfoPtr
{
public:
    ~Unk_PvInfoPtr() { FUN_140964aa0(); }
    CPvPInfo* FUN_140965970() const;                                // operator->
    bool FUN_14101ec80(const CPvPInfo* p) const { return m_p == p; }   // operator== (0x14101ec80)
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
    void FUN_141adc5d0(int nClass);                                 // hide a dialog
    MS2Ptr<UIObject> FUN_141adcea0(int nClass);                     // object by class id
};
Unk_PvpUiService* FUN_1403ed2b0();

CStringW FUN_14052bd00(int nStringId, const CStringW& strName);     // formatted message
CStringW FUN_140632a60(int nStringId, const CStringW& strA, const CStringW& strB);   // formatted message, two arguments
CStringW FUN_14028de60(int nStringId);                              // string table text
void FUN_1412751f0(const CStringW& strText, int nType, int nFlag);  // post a notice
int FUN_141654730(PCBase* pPlayer);                                 // the job of a player

bool FUN_14101c5b0(Unk_PvpEntryItem* pA, Unk_PvpEntryItem* pB);
UIPvPTeamFlagGagueDialog* FUN_14101c7b0(int nClass);
UIPvPTeamResultDialog* FUN_14101c850(int nClass);
UIPvPTeamScoreDialog* FUN_14101c8f0(int nClass);

// @0x14101b7f0
void Unk_PvpEntryBlock::FUN_14101b7f0()
{
    m_a.FUN_14101ef40();
    m_b.FUN_14101ef40();
}

// MS2-FUNCTIONAL: behaviour-equivalent (frame layout / temp slots differ)
// @0x14101b830
void Unk_PvpEntryBlock::FUN_14101b830(int nMessage, CInPacket& packet)
{
    if (nMessage == 0x6b)
    {
        UIPvPTeamResultDialog* pResult = FUN_14101c850(0x4ed2);
        if (pResult != 0)
        {
            pResult->FUN_1413452c0();
            pResult->FUN_141345310();
        }
    }
    else if (nMessage == 0x6c)
    {
        int nA = packet.vfunc_o8_3();
        int nB = packet.vfunc_o8_3();
        FUN_14101c470(nA, nB);
        UIPvPTeamScoreDialog* pScore = FUN_14101c8f0(0x4ed3);
        if (pScore != 0)
            FUN_141346960(pScore);
        UIPvPTeamResultDialog* pResult = FUN_14101c850(0x4ed2);
        if (pResult != 0)
            pResult->FUN_1413456a0();
    }
    else if (nMessage == 0x6e)
    {
        int nTeam = packet.vfunc_o8_3();
        int nCount = packet.vfunc_o8_3();
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ed3);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e95);
        UIPvPTeamResultDialog* pResult = FUN_14101c850(0x4ed2);
        if (pResult != 0)
            pResult->FUN_141345740(nTeam, nCount);
        if (FUN_1403ed2b0()->FUN_141adc940(0x4ed2) != 0)
            FUN_1403ed2b0()->FUN_141adc530(0x4ed2);
    }
    else if (nMessage == 0x6d)
    {
        __int64 nCharId = packet.vfunc_o8_4();
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd1530(nCharId);
        if (pPlayer != 0)
        {
            Unk_PvInfoPtr info = ((Unk_PvActor*)pPlayer)->FUN_140967420();
            if (!info.FUN_14101ec80(0))
            {
                info.FUN_140965970()->FUN_140743b20(packet);
                FUN_14101c220(info.FUN_140965970()->m_nPoint, nCharId, info.FUN_140965970()->m_nWin,
                              info.FUN_140965970()->m_nLose, info.FUN_140965970()->m_nKill);
                UIPvPTeamResultDialog* pResult = FUN_14101c850(0x4ed2);
                if (pResult != 0)
                    pResult->FUN_1413454b0();
            }
        }
    }
    else if (nMessage == 0x70)
    {
        int nKind = packet.vfunc_o8_3();
        int nOutcome = packet.vfunc_o8_3();
        CStringW strKind;
        if (nKind == 1)
            strKind = FUN_14028de60(0xb15);
        else if (nKind == 2)
            strKind = FUN_14028de60(0xb16);
        else
            return;
        CStringW strOutcome;
        if (nOutcome == 0)
            strOutcome = FUN_14028de60(0xb17);
        else if (nOutcome == 1)
            strOutcome = FUN_14028de60(0xb18);
        else if (nOutcome == 2)
            strOutcome = FUN_14028de60(0xb19);
        else
            return;
        FUN_1412751f0(FUN_140632a60(0xb1a, strKind, strOutcome), 4, 1);
    }
    else if (nMessage == 0x6f)
    {
        packet.vfunc_o8_3();
        int nValue = packet.vfunc_o8_3();
        if (FUN_1403ed2b0()->FUN_141adc940(0x4ed4) != 0)
            FUN_1403ed2b0()->FUN_141adc530(0x4ed4);
        UIPvPTeamFlagGagueDialog* pGauge = FUN_14101c7b0(0x4ed4);
        if (pGauge != 0)
            pGauge->FUN_141344d50(nValue / 10);
    }
    else if (nMessage == 0x71)
    {
        CStringW strName = packet.vfunc_o8_8();
        int nKind = packet.vfunc_o8_1();
        if (nKind == 1)
            FUN_1412751f0(FUN_14052bd00(0xb1b, strName), 4, 1);
        else if (nKind == 2)
            FUN_1412751f0(FUN_14052bd00(0xb1c, strName), 4, 1);
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent (temp slots differ)
// @0x14101c0b0
void Unk_PvpEntryBlock::FUN_14101c0b0(void* pArgument)
{
    Unk_PvpEntryItem* pItem = FUN_14101c560(0xc9)->FUN_14101f010((__int64)pArgument);
    if (pItem != 0)
    {
        pItem->m_bOnline = false;
        FUN_14101c4e0(0xc9);
    }
    pItem = FUN_14101c560(0xca)->FUN_14101f010((__int64)pArgument);
    if (pItem != 0)
    {
        pItem->m_bOnline = false;
        FUN_14101c4e0(0xca);
    }
}

// @0x14101c160
std::vector<Unk_PvpEntryItem*>* Unk_PvpEntryBlock::FUN_14101c160(int nTeam)
{
    Unk_PvpEntryTable* pTable = FUN_14101c560(nTeam);
    if (pTable == 0)
        return 0;
    return &pTable->m_items;
}

// @0x14101c1a0
void Unk_PvpEntryBlock::FUN_14101c1a0(int* pA, int* pB)
{
    Unk_PvpEntryTable* pTableA = FUN_14101c560(0xc9);
    if (pTableA != 0)
        *pA = pTableA->m_4;
    Unk_PvpEntryTable* pTableB = FUN_14101c560(0xca);
    if (pTableB != 0)
        *pB = pTableB->m_4;
}

// MS2-FUNCTIONAL: behaviour-equivalent (temp slots differ)
// @0x14101c220
void Unk_PvpEntryBlock::FUN_14101c220(int nTeam, __int64 nCharId, int nWin, int nLose, int nKill)
{
    Unk_PvpEntryTable* pTable = FUN_14101c560(nTeam);
    if (pTable != 0)
    {
        bool bAdded = false;
        Unk_PvpEntryItem* pItem = pTable->FUN_14101f010(nCharId);
        if (pItem == 0)
        {
            CStringW strName(L"Unknown");
            int nJob = 0;
            PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd1530(nCharId);
            if (pPlayer != 0)
            {
                strName = pPlayer->vfunc_77();
                nJob = FUN_141654730(pPlayer);
            }
            pItem = new Unk_PvpEntryItem(nCharId, strName, nJob, nKill, nWin, nLose);
            pTable->FUN_14101eee0(pItem);
            bAdded = true;
        }
        else
        {
            pItem->m_nCharId = nCharId;
            pItem->m_nWin = nWin;
            pItem->m_nLose = nLose;
            pItem->m_nKill = nKill;
        }
        if (bAdded)
            FUN_14101c4e0(nTeam);
    }
}

// @0x14101c470
void Unk_PvpEntryBlock::FUN_14101c470(int nA, int nB)
{
    Unk_PvpEntryTable* pTableA = FUN_14101c560(0xc9);
    if (pTableA != 0)
        pTableA->m_4 = nA;
    Unk_PvpEntryTable* pTableB = FUN_14101c560(0xca);
    if (pTableB != 0)
        pTableB->m_4 = nB;
}

// @0x14101c4e0
void Unk_PvpEntryBlock::FUN_14101c4e0(int nTeam)
{
    Unk_PvpEntryTable* pTable = FUN_14101c560(nTeam);
    if (pTable == 0)
        return;
    std::sort(pTable->m_items.begin(), pTable->m_items.end(), FUN_14101c5b0);
}

// @0x14101c560
Unk_PvpEntryTable* Unk_PvpEntryBlock::FUN_14101c560(int nTeam)
{
    Unk_PvpEntryTable* pTable = 0;
    if (nTeam == 0xc9)
        pTable = &m_a;
    else if (nTeam == 0xca)
        pTable = &m_b;
    return pTable;
}

// The row order: online rows first, then by name.
// MS2-FUNCTIONAL: behaviour-equivalent (branch layout differs)
// @0x14101c5b0
bool FUN_14101c5b0(Unk_PvpEntryItem* pA, Unk_PvpEntryItem* pB)
{
    if (pA == 0)
        return false;
    if (pB == 0)
        return true;
    if (!pA->m_bOnline)
        return false;
    if (!pB->m_bOnline)
        return true;
    return pA->m_strName < pB->m_strName;
}

// @0x14101c7b0
UIPvPTeamFlagGagueDialog* FUN_14101c7b0(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObject.get() != 0)
            return dynamic_cast<UIPvPTeamFlagGagueDialog*>((UIObject*)spObject);
    }
    return 0;
}

// @0x14101c850
UIPvPTeamResultDialog* FUN_14101c850(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObject.get() != 0)
            return dynamic_cast<UIPvPTeamResultDialog*>((UIObject*)spObject);
    }
    return 0;
}

// @0x14101c8f0
UIPvPTeamScoreDialog* FUN_14101c8f0(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObject.get() != 0)
            return dynamic_cast<UIPvPTeamScoreDialog*>((UIObject*)spObject);
    }
    return 0;
}

// ---- the row and the table ----

// @0x14101ebb0
Unk_PvpEntryItem::Unk_PvpEntryItem(unsigned __int64 nCharId, CStringW strName, int nJob, int nKill, int nWin, int nLose)
    : m_nCharId(nCharId)
{
    m_nKill = nKill;
    m_nWin = nWin;
    m_nLose = nLose;
    m_nJob = nJob;
    m_bOnline = true;
    m_strName = strName;
}

// @0x14101eea0
void* Unk_PvpEntryItem::FUN_14101eea0(unsigned nFlags)
{
    this->Unk_PvpEntryItem::~Unk_PvpEntryItem();
    if ((nFlags & 1) != 0)
        operator delete(this, sizeof(Unk_PvpEntryItem));
    return this;
}

// @0x14101eee0
void Unk_PvpEntryTable::FUN_14101eee0(Unk_PvpEntryItem* pItem)
{
    m_items.push_back(pItem);
    m_targets.insert(std::make_pair(pItem->m_nCharId, pItem));
}

// @0x14101ef40
void Unk_PvpEntryTable::FUN_14101ef40()
{
    m_0 = 0;
    m_4 = 0;
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        Unk_PvpEntryItem* pItem = m_items[i];
        Unk_PvpEntryItem* pDelete = pItem;
        pDelete ? pDelete->FUN_14101eea0(1) : 0;
    }
    m_items.clear();
    m_targets.clear();
}

// MS2-FUNCTIONAL: behaviour-equivalent (early-out layout differs)
// @0x14101f010
Unk_PvpEntryItem* Unk_PvpEntryTable::FUN_14101f010(unsigned __int64 nCharId)
{
    std::map<unsigned __int64, Unk_PvpEntryItem*>::iterator it = m_targets.find(nCharId);
    if (!(it == m_targets.end()))
        return it->second;
    return 0;
}

// The UCRT's header-inline memcpy_s / memmove_s of this TU (0x141020200 / the memmove_s copy), kept alive through ATL::Checked.
// @0x141020200
#pragma function(memset, memcpy)
static __inline errno_t ms2_pvp_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnPvpMemcpyS)(void*, size_t, const void*, size_t) = &ms2_pvp_memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();
