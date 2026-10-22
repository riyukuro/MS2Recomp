// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemOption, the option record of an item: five option
// groups of stat and special-stat options (the first object of the itemoptiondata.cpp range).
// MS2-UNIT: commonfiles\itemoptiondata.cpp#1
// MS2-RANGE: 0x1405caed0-0x1405ce250 .text$mn
// MS2-RANGE: 0x1400ba590-0x1400ba650 .text$di
// MS2-RANGE: 0x142c9b1f0-0x142c9b220 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemoptiondata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemoption.h"
#include "stream.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

static CString s_sortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

// The option table (CItemOptionTable; FUN_140166430 returns the singleton).
class Unk_140166430 { public: unsigned FUN_1405f6ed0(int nKey); };
Unk_140166430* FUN_140166430();
int FUN_14081d480(int nStat);                   // the display key of a stat
const CString& FUN_14082efb0(int nStat);        // the xml name of a stat
const CString& FUN_14081d380(int nStat);        // the xml name of a special stat
int FUN_14081d830(int nStat);
extern Unk_SpecialAbilityMap g_kSpecialAbilityMap;  // specialability.cpp

template<class Map> void CopyEnchantMap(Map& to,const Map& from) {
    for (POSITION pos=from.GetStartPosition();pos;from.GetNext(pos)) {
        to.SetAt(from.GetKeyAt(pos),from.GetValueAt(pos));
    }
}

// @0x1405caed0
CItemOption::CItemOption(unsigned nItemId) : m_nItemId(nItemId) {
    FUN_1405cb110();
}

// @0x1405caf90
MS2Ptr<CItemOption> CItemOption::FUN_1405caf90() {
    MS2Ptr<CItemOption> spCopy(new CItemOption(m_nItemId));
    for (int i=0;i<5;i++) {
        CopyEnchantMap(spCopy->m_aStat[i],m_aStat[i]);
        CopyEnchantMap(spCopy->m_aSpecial[i],m_aSpecial[i]);
    }
    spCopy->m_n2f0=m_n2f0;
    return spCopy;
}

// @0x1405cb110
void CItemOption::FUN_1405cb110() {
    for (int i=0;i<5;i++) {
        m_aStat[i].RemoveAll();
        m_aSpecial[i].RemoveAll();
    }
    m_n2f0=0;
}

// @0x1405cb190
void CItemOption::FUN_1405cb190(int nGroup) {
    if (nGroup<0 || nGroup>=5) return;
    m_aStat[nGroup].RemoveAll();
    m_aSpecial[nGroup].RemoveAll();
}

// @0x1405cb200
bool CItemOption::FUN_1405cb200(int nGroup, int nStat, Unk_EnchantPtr<BaseOption> spOption) {
    if (!spOption->HasValue()) return false;
    m_aStat[nGroup].SetAt(nStat,spOption);
    return true;
}

// @0x1405cb2a0
bool CItemOption::FUN_1405cb2a0(int nGroup, unsigned nStat, Unk_EnchantPtr<BaseOption> spOption) {
    if (!spOption->HasValue()) return false;
    m_aSpecial[nGroup].SetAt(reinterpret_cast<const Unk_SocketSpecialStat&>(nStat),spOption);
    return true;
}

// @0x1405cb340
unsigned CItemOption::GetItemId() {
    return m_nItemId;
}

// @0x1405cb360
void CItemOption::FUN_1405cb360(int nValue) {
    m_n2f0=nValue;
}

// @0x1405cb380
int CItemOption::FUN_1405cb380() {
    return m_n2f0;
}

// @0x1405cb3a0
int CItemOption::FUN_1405cb3a0(unsigned nType) {
    int nSum=0;
    for (size_t i=0;i<5;i++) {
        Unk_EnchantPtr<BaseOption> spOption=FUN_1405cb760((int)i,nType);
        if (spOption.get()!=0) nSum+=spOption->GetValue();
    }
    return nSum;
}

// @0x1405cb440
int CItemOption::FUN_1405cb440(unsigned nType) {
    int nSum=0;
    for (size_t i=0;i<5;i++) {
        Unk_EnchantPtr<BaseOption> spOption=FUN_1405cb800((int)i,nType);
        if (spOption.get()!=0) nSum+=spOption->GetValue();
    }
    return nSum;
}

// @0x1405cb4e0
std::pair<Unk_StatType, int> CItemOption::FUN_1405cb4e0(int nGroup) const {
    if (m_aStat[nGroup].IsEmpty()) return std::make_pair((Unk_StatType)-1,0);
    Unk_StatType eStat=(Unk_StatType)m_aStat[nGroup].GetKeyAt(m_aStat[nGroup].GetStartPosition());
    Unk_EnchantPtr<BaseOption> spOption=m_aStat[nGroup].GetValueAt(m_aStat[nGroup].GetStartPosition());
    int nValue=spOption->GetValue();
    return std::make_pair(eStat,nValue);
}

// @0x1405cb620
std::pair<Unk_SocketSpecialStat, int> CItemOption::FUN_1405cb620(int nGroup) const {
    if (m_aSpecial[nGroup].IsEmpty()) return std::make_pair((Unk_SocketSpecialStat)0,0);
    Unk_SocketSpecialStat eStat=m_aSpecial[nGroup].GetKeyAt(m_aSpecial[nGroup].GetStartPosition());
    Unk_EnchantPtr<BaseOption> spOption=m_aSpecial[nGroup].GetValueAt(m_aSpecial[nGroup].GetStartPosition());
    int nValue=spOption->GetValue();
    return std::make_pair(eStat,nValue);
}

// @0x1405cb760
Unk_EnchantPtr<BaseOption> CItemOption::FUN_1405cb760(int nGroup, int nStat) {
    Unk_EnchantMap::CPair* pPair=m_aStat[nGroup].Lookup(nStat);
    if (pPair==NULL) return Unk_EnchantPtr<BaseOption>(0);
    return pPair->m_value;
}

// @0x1405cb800
Unk_EnchantPtr<BaseOption> CItemOption::FUN_1405cb800(int nGroup, unsigned nType) {
    Unk_SocketSpecialMap::CPair* pPair=m_aSpecial[nGroup].Lookup(reinterpret_cast<const Unk_SocketSpecialStat&>(nType));
    if (pPair==NULL) return Unk_EnchantPtr<BaseOption>(0);
    return pPair->m_value;
}

// @0x1405cb8a0
Unk_EnchantMap& CItemOption::FUN_1405cb8a0(int nGroup) {
    return m_aStat[nGroup];
}

// @0x1405cb8d0
Unk_SocketSpecialMap& CItemOption::FUN_1405cb8d0(int nGroup) {
    return m_aSpecial[nGroup];
}

// @0x1405cb900
void CItemOption::FUN_1405cb900(int nGroup, Unk_OptionTextMap& kOut) {
    for (POSITION pos=m_aStat[nGroup].GetStartPosition();pos;m_aStat[nGroup].GetNext(pos)) {
        int nStat=m_aStat[nGroup].GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spOption=m_aStat[nGroup].GetValueAt(pos);
        int nKey=0;
        if (spOption->HasValue()) nKey=FUN_14081d480(nStat);
        unsigned nOrder=FUN_140166430()->FUN_1405f6ed0(nKey);
        kOut.SetAt(nOrder,FUN_14082efb0(nStat));
    }
    for (POSITION pos=m_aSpecial[nGroup].GetStartPosition();pos;m_aSpecial[nGroup].GetNext(pos)) {
        Unk_SocketSpecialStat eStat=m_aSpecial[nGroup].GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spOption=m_aSpecial[nGroup].GetValueAt(pos);
        CString strName;
        if (spOption->HasValue()) strName=FUN_14081d380(eStat);
        unsigned nOrder=FUN_140166430()->FUN_1405f6ed0(eStat);
        kOut.SetAt(nOrder,FUN_14081d380(eStat));
    }
}

// @0x1405cbbb0
int CItemOption::FUN_1405cbbb0(int nGroup) {
    return (int)(m_aStat[nGroup].GetCount()+m_aSpecial[nGroup].GetCount());
}

// @0x1405cbc10
BOOL CItemOption::FUN_1405cbc10(int nGroup) const {
    const Unk_SocketSpecialMap& kMap=m_aSpecial[nGroup];
    for (POSITION pos=kMap.GetStartPosition();pos;kMap.GetNext(pos)) {
        if (FUN_14081d830(kMap.GetKeyAt(pos))!=0) return TRUE;
    }
    return FALSE;
}

// @0x1405cbc90
int CItemOption::FUN_1405cbc90() {
    const Unk_SpecialAbilityMap& kMap=g_kSpecialAbilityMap;
    for (POSITION pos=kMap.GetStartPosition();pos;kMap.GetNext(pos)) {
        Unk_SocketSpecialStat eStat=kMap.GetKeyAt(pos);
        for (size_t i=0;i<5;i++) {
            Unk_EnchantPtr<BaseOption> spOption=FUN_1405cb800((int)i,eStat);
            if (spOption.get()!=0) return 1;
        }
    }
    return 0;
}

// @0x1405cbd70
void CItemOption::FUN_1405cbd70(ATL::CAtlMap<unsigned, unsigned short>& kOut) {
    const Unk_SpecialAbilityMap& kMap=g_kSpecialAbilityMap;
    for (POSITION pos=kMap.GetStartPosition();pos;kMap.GetNext(pos)) {
        Unk_SocketSpecialStat eStat=kMap.GetKeyAt(pos);
        unsigned nAbility=kMap.GetValueAt(pos);
        for (size_t i=0;i<5;i++) {
            Unk_EnchantPtr<BaseOption> spOption=FUN_1405cb800((int)i,eStat);
            if (spOption.get()!=0) {
                unsigned short nValue=0;
                kOut.Lookup(nAbility,nValue);
                nValue+=(unsigned short)spOption->GetValue();
                kOut.SetAt(nAbility,nValue);
            }
        }
    }
}

// @0x1405cbeb0
void CItemOption::FUN_1405cbeb0(COutputStream& kOut) {
    for (unsigned i=0;i<5;i++) {
        kOut.WriteInt16((short)m_aStat[i].GetCount());
        for (POSITION pos=m_aStat[i].GetStartPosition();pos;m_aStat[i].GetNext(pos)) {
            int nStat=m_aStat[i].GetKeyAt(pos);
            Unk_EnchantPtr<BaseOption> spOption=m_aStat[i].GetValueAt(pos);
            kOut.WriteInt16((short)nStat);
            spOption->FUN_140266d20(reinterpret_cast<Unk_EnchantWrite&>(kOut));
        }
        kOut.WriteInt16((short)m_aSpecial[i].GetCount());
        for (POSITION pos=m_aSpecial[i].GetStartPosition();pos;m_aSpecial[i].GetNext(pos)) {
            Unk_SocketSpecialStat eStat=m_aSpecial[i].GetKeyAt(pos);
            Unk_EnchantPtr<BaseOption> spOption=m_aSpecial[i].GetValueAt(pos);
            kOut.WriteInt16((short)eStat);
            spOption->FUN_140266d20(reinterpret_cast<Unk_EnchantWrite&>(kOut));
        }
    }
    kOut.WriteInt32(m_n2f0);
}

// @0x1405cc190
void CItemOption::FUN_1405cc190(CInputStream& kIn) {
    FUN_1405cb110();
    for (unsigned i=0;i<5;i++) {
        unsigned nCount=(unsigned short)kIn.ReadInt16();
        for (unsigned j=0;j<nCount;j++) {
            Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
            int nStat=(unsigned short)kIn.ReadInt16();
            spOption->FUN_140266d60(reinterpret_cast<Unk_EnchantRead&>(kIn));
            m_aStat[i].SetAt(nStat,spOption);
        }
        unsigned nSpecialCount=(unsigned short)kIn.ReadInt16();
        for (unsigned j=0;j<nSpecialCount;j++) {
            Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
            Unk_SocketSpecialStat eStat=(Unk_SocketSpecialStat)(unsigned short)kIn.ReadInt16();
            spOption->FUN_140266d60(reinterpret_cast<Unk_EnchantRead&>(kIn));
            m_aSpecial[i].SetAt(eStat,spOption);
        }
    }
    m_n2f0=kIn.ReadInt32();
}

// @0x1405cc410
bool CItemOption::FUN_1405cc410() {
    return m_aStat[4].GetCount()!=0 || m_aSpecial[4].GetCount()!=0;
}

// @0x1405cc480
bool CItemOption::FUN_1405cc480(MS2Ptr<CItemOption> spSource) {
    if (spSource==0) return false;
    m_aStat[2].RemoveAll();
    m_aSpecial[2].RemoveAll();
    CopyEnchantMap(m_aStat[2],spSource->m_aStat[2]);
    CopyEnchantMap(m_aSpecial[2],spSource->m_aSpecial[2]);
    return true;
}

// @0x1405cc590
BOOL CItemOption::FUN_1405cc590(int nGroup, const Unk_EnchantMap& kStat, const Unk_SocketSpecialMap& kSpecial) {
    m_aStat[nGroup].RemoveAll();
    m_aSpecial[nGroup].RemoveAll();
    CopyEnchantMap(m_aStat[nGroup],kStat);
    CopyEnchantMap(m_aSpecial[nGroup],kSpecial);
    return TRUE;
}

// @0x1405cc640
bool CItemOption::FUN_1405cc640(int nGroup, CItemOption* pOther) const {
    for (POSITION pos=m_aStat[nGroup].GetStartPosition();pos;m_aStat[nGroup].GetNext(pos)) {
        int nStat=m_aStat[nGroup].GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spOther=pOther->FUN_1405cb760(nGroup,nStat);
        if (spOther==0) return false;
        Unk_EnchantPtr<BaseOption> spOption=m_aStat[nGroup].GetValueAt(pos);
        if (!spOption->FUN_140266ee0(spOther)) return false;
    }
    for (POSITION pos=m_aSpecial[nGroup].GetStartPosition();pos;m_aSpecial[nGroup].GetNext(pos)) {
        Unk_SocketSpecialStat eStat=m_aSpecial[nGroup].GetKeyAt(pos);
        Unk_EnchantPtr<BaseOption> spOther=pOther->FUN_1405cb800(nGroup,eStat);
        if (spOther==0) return false;
        Unk_EnchantPtr<BaseOption> spOption=m_aSpecial[nGroup].GetValueAt(pos);
        if (!spOption->FUN_140266ee0(spOther)) return false;
    }
    return true;
}

MS2_EMIT_CRT_MEMMOVE_S();
