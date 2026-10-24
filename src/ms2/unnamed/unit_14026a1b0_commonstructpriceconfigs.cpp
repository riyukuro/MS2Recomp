// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The rest of the commonstruct price records (the used-time
// record and its list), the skill window layout configs (CSkillCompactControlConfig / CSkillBookTreeTabConfig) and a
// two int text parser. Class and member names are invented (no __FILE__ in the range).
// MS2-UNIT: unit_14026a1b0
// MS2-RANGE: 0x14026a1b0-0x14026ab50 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/commonfiles/commonpricerecord.h"
#include "ms2/commonfiles/skillconfig.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

__int64 FUN_140869440();                                            // the current server time
__int64 FUN_14028d0e0();                                            // a new tab id
void FUN_140274fc0(CStringW& str, ATL::CAtlArray<unsigned>& out, const wchar_t* pszSep);   // split into numbers

// @0x14026a1b0
unsigned char Unk_CommonPriceRecord::IsAvailable()
{
    unsigned char bResult;
    if (m_price.m_amount < 1 || m_usedTime != 0)
        bResult = 0;
    else
        bResult = 1;
    return bResult;
}

// @0x14026a1f0
__int64 Unk_CommonPriceRecord::GetAvailableAmount()
{
    if (m_usedTime == 0)
        return m_price.m_amount;
    return 0;
}

// @0x14026a220
bool Unk_CommonPriceRecord::MarkUsed()
{
    bool bUnused = m_usedTime == 0;
    if (bUnused)
        m_usedTime = FUN_140869440();
    return bUnused;
}

// @0x14026a260
void Unk_CommonPriceRecord::Write(COutputStream* pOut)
{
    m_price.Write(pOut);
    pOut->WriteInt64(m_usedTime);
}

// @0x14026a2b0
void Unk_CommonPriceRecord::Read(CInputStream* pIn)
{
    m_price.Read(pIn);
    m_usedTime = pIn->ReadInt64();
}

// @0x14026a300
Unk_CommonPriceRecordList& Unk_CommonPriceRecordList::operator=(const Unk_CommonPriceRecordList& rOther)
{
    if (this != &rOther)
    {
        m_records.RemoveAll();
        m_records.Copy(rOther.m_records);
    }
    return *this;
}

// @0x14026a350
void Unk_CommonPriceRecordList::Write(COutputStream* pOut)
{
    unsigned char nCount = (unsigned char)m_records.GetCount();
    pOut->WriteUInt8(nCount);
    for (int i = 0; i < (int)nCount; i++)
        m_records.GetAt(i).Write(pOut);
}

// @0x14026a3d0
void Unk_CommonPriceRecordList::Read(CInputStream* pIn)
{
    unsigned char nCount = pIn->ReadUInt8();
    for (int i = 0; i < (int)nCount; i++)
    {
        Unk_CommonPriceRecord record;
        record.Read(pIn);
        m_records.Add(record);
    }
}

// @0x14026a450
void Unk_CommonPriceRecordList::AddRecord(int type, int subType, __int64 amount, __int64 usedTime)
{
    m_records.Add(Unk_CommonPriceRecord(type, subType, amount, usedTime));
}

// @0x14026a4b0
int Unk_CommonPriceRecordList::GetCount()
{
    return (int)m_records.GetCount();
}

// @0x14026a4e0
void Unk_CommonPriceRecordList::Clear()
{
    m_records.RemoveAll();
}

// @0x14026a510
unsigned char Unk_CommonPriceRecordList::HasAvailable()
{
    int nCount = GetCount();
    for (int i = 0; i < nCount; i++)
    {
        if (m_records.GetAt(i).IsAvailable() == 1)
            return 1;
    }
    return 0;
}

// @0x14026a580
__int64 Unk_CommonPriceRecordList::GetUsedTime(int nIndex)
{
    if (nIndex < (int)m_records.GetCount())
        return m_records.GetAt(nIndex).m_usedTime;
    return 0;
}

// @0x14026a5d0
CSkillCompactControlConfig::CSkillCompactControlConfig() : m_30(0) {}

// @0x14026a640
CSkillBookTreeTabConfig::CSkillBookTreeTabConfig() : m_nId(FUN_14028d0e0()), m_slots(17, 0.75f, 0.25f, 2.25f, 10) {}

// @0x14026a6e0
void CSkillBookTreeTabConfig::Write(COutputStream* pOut)
{
    pOut->WriteInt64(m_nId);
    m_strName = m_strName.Left(10);
    pOut->WriteUnicodeString(m_strName);
    pOut->WriteInt32((int)m_slots.GetCount());
    POSITION pos = m_slots.GetStartPosition();
    while (pos != NULL)
    {
        unsigned nKey = m_slots.GetKeyAt(pos);
        unsigned nValue = m_slots.GetValueAt(pos);
        pOut->WriteInt32(nKey);
        pOut->WriteInt32(nValue);
        m_slots.GetNext(pos);
    }
}

// @0x14026a860
void CSkillBookTreeTabConfig::Read(CInputStream* pIn)
{
    m_nId = pIn->ReadInt64();
    m_strName = pIn->ReadUnicodeString();
    m_strName = m_strName.Left(10);
    unsigned nCount = pIn->ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        unsigned nKey = pIn->ReadInt32();
        unsigned nValue = pIn->ReadInt32();
        m_slots.SetAt(nKey, nValue);
    }
}

// @0x14026aa70
Unk_CommonIntPair::Unk_CommonIntPair() : m_first(0), m_second(0) {}

// @0x14026aaa0
void Unk_CommonIntPair::Parse(CStringW strText)
{
    ATL::CAtlArray<unsigned> values;
    FUN_140274fc0(strText, values, L",");
    if (values.GetCount() != 0)
        m_first = values[0];
    if (values.GetCount() > 1)
        m_second = values[1];
}
