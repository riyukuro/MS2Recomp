// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPCData (the persisted player record) and CPCDataPack (the
// three byte buffers it travels in), with the ATL array / CByteBuffer glue instantiated here. See pcdata.h.
// MS2-UNIT: ?\pcdata.cpp
// MS2-RANGE: 0x14071e2f0-0x140721000 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEBAAEBV?$MS2Ptr@VCItem@@@@_K@Z 0x140720ac0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1CPCData@@UEAA@XZ 0x1407209c0
// MS2-PIN: ??_GCPCData@@UEAAPEAXI@Z 0x140720b00
// MS2-PIN: ??_GCPCDataPack@@UEAAPEAXI@Z 0x140720b40
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/commonfiles/pcdata.h"
#include "ms2/placeholder/exception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects --------------------------------------------------------------------------------------

__int64 FUN_140869440();                                    // the server time

// The Crypto++ CRC32 hash object (vftable + running value, 0x10 bytes); only the pieces this unit touches.
class Unk_Crc32
{
public:
    Unk_Crc32* FUN_142351b30();                             // ctor 0x142351b30
    void FUN_1403901d0(int& nOut, const unsigned char* pData, unsigned nSize);   // hash a block
    void FUN_140720aa0();                                   // dtor (forwards to the hash base dtor 0x14038f3b0)
    void* m_vfptr;
    unsigned m_nCrc;
    unsigned m_pad;
};
MS2_CHECK_SIZE(Unk_Crc32, 0x10);
void FUN_14038f3b0(Unk_Crc32*);

// ---- CPCData ---------------------------------------------------------------------------------------------------------------

// @0x14071e2f0
CPCData::CPCData()
    : m_n18(0), m_n20(0), m_n30(1), m_n34(1), m_n38(10), m_n3c(3), m_n40(0), m_n44(0),
      m_n3c8(0), m_n3cc(0), m_n3d0(0), m_n3d4(0), m_n3f8(0), m_n3fc(0), m_n400(0), m_n408(0), m_n40c(0), m_n418(0),
      m_n430(0), m_n438(0)
{
    memset(m_a48, 0, sizeof(m_a48));
    memset(m_a160, 0, sizeof(m_a160));
    memset(m_a278, 0, sizeof(m_a278));
    memset(m_an410, 0, sizeof(m_an410));
}

// @0x14071e570
void CPCData::FUN_14071e570(COutputStream& out)
{
    out.vfunc_o10_4(m_n18);
    out.vfunc_o10_4(m_n20);
    out.vfunc_o10_8(m_str28);
    out.vfunc_o10_2(m_n30);
    out.vfunc_o10_3(m_n34);
    out.vfunc_o10_3(m_n38);
    out.vfunc_o10_3(m_n3c);
    out.vfunc_o10_3(m_n40);
    out.vfunc_o10_1(m_n44);
    out.vfunc_o10_9(m_a48, 0x118);
    out.vfunc_o10_9(m_a160, 0x118);
    out.vfunc_o10_9(m_a278, 0x118);
    out.vfunc_o10_3((int)m_map390.size());
    for (std::pair<const Unk_PcMapKey, int> entry : m_map390) {
        out.vfunc_o10_2((short)entry.first);
        out.vfunc_o10_3(entry.second);
    }
    out.vfunc_o10_6(m_str3a0);
    out.vfunc_o10_8(m_str3a8);
    out.vfunc_o10_8(m_str3b0);
    out.vfunc_o10_8(m_str3b8);
    out.vfunc_o10_8(m_str3c0);
    out.vfunc_o10_3(m_n3c8);
    out.vfunc_o10_3(m_n3cc);
    out.vfunc_o10_3(m_n3d0);
    out.vfunc_o10_3(m_n3d4);
    int nCount = (int)m_arr3d8.GetCount();
    out.vfunc_o10_3(nCount);
    for (int i = 0; i < nCount; i++) {
        out.vfunc_o10_3(m_arr3d8[i]);
    }
    out.vfunc_o10_3(m_n3f8);
    out.vfunc_o10_3(m_n3fc);
    out.vfunc_o10_4(m_n400);
    out.vfunc_o10_3(m_n408);
    out.vfunc_o10_3(m_n40c);
    out.vfunc_o10_3(m_an410[0]);
    out.vfunc_o10_3(m_an410[1]);
    out.vfunc_o10_2(m_n418);
    out.vfunc_o10_8(m_str420);
    out.vfunc_o10_8(m_str428);
    out.vfunc_o10_4(m_n430);
    out.vfunc_o10_4(m_n438);
}

// @0x14071ec80
void CPCData::FUN_14071ec80(CInputStream& in)
{
    m_n18 = in.vfunc_o8_4();
    m_n20 = in.vfunc_o8_4();
    m_str28 = in.vfunc_o8_8();
    m_n30 = in.vfunc_o8_2();
    m_n34 = in.vfunc_o8_3();
    m_n38 = in.vfunc_o8_3();
    m_n3c = in.vfunc_o8_3();
    m_n40 = in.vfunc_o8_3();
    m_n44 = in.vfunc_o8_1();
    in.vfunc_o8_9(m_a48, 0x118);
    in.vfunc_o8_9(m_a160, 0x118);
    in.vfunc_o8_9(m_a278, 0x118);
    int nPairs = in.vfunc_o8_3();
    for (int i = 0; i < nPairs; i++) {
        Unk_PcMapKey nKey = (Unk_PcMapKey)(unsigned short)in.vfunc_o8_2();
        int nValue = in.vfunc_o8_3();
        m_map390[nKey] = nValue;
    }
    m_str3a0 = in.vfunc_o8_6();
    m_str3a8 = in.vfunc_o8_8();
    m_str3b0 = in.vfunc_o8_8();
    m_str3b8 = in.vfunc_o8_8();
    m_str3c0 = in.vfunc_o8_8();
    m_n3c8 = in.vfunc_o8_3();
    m_n3cc = in.vfunc_o8_3();
    m_n3d0 = in.vfunc_o8_3();
    m_n3d4 = in.vfunc_o8_3();
    m_arr3d8.RemoveAll();
    int nCount = in.vfunc_o8_3();
    for (int j = 0; j < nCount; j++) {
        m_arr3d8.Add(in.vfunc_o8_3());
    }
    m_n3f8 = in.vfunc_o8_3();
    m_n3fc = in.vfunc_o8_3();
    m_n400 = in.vfunc_o8_4();
    m_n408 = in.vfunc_o8_3();
    m_n40c = in.vfunc_o8_3();
    m_an410[0] = in.vfunc_o8_3();
    m_an410[1] = in.vfunc_o8_3();
    m_n418 = (unsigned short)in.vfunc_o8_2();
    m_str420 = in.vfunc_o8_8();
    m_str428 = in.vfunc_o8_8();
    m_n430 = in.vfunc_o8_4();
    m_n438 = in.vfunc_o8_4();
}

// ---- CPCDataPack -----------------------------------------------------------------------------------------------------------

// @0x14071f480
CPCDataPack::CPCDataPack()
    : m_n20(0), m_n28(0)
{
}

// @0x14071f510
CPCDataPack::~CPCDataPack()
{
}

// @0x14071f580
void CPCDataPack::FUN_14071f580(COutputStream& out)
{
    out.vfunc_o10_4(m_n18);
    out.vfunc_o10_4(m_n20);
    out.vfunc_o10_4(m_n28);
    unsigned nSize = 0;
    nSize = m_bufRecord.GetLength();
    out.vfunc_o10_3(nSize);
    out.vfunc_o10_9(m_bufRecord.FUN_14067c4c0(), nSize);
    nSize = m_bufItems.GetLength();
    out.vfunc_o10_3(nSize);
    out.vfunc_o10_9(m_bufItems.FUN_14067c4c0(), nSize);
    nSize = m_bufExtra.GetLength();
    out.vfunc_o10_3(nSize);
    out.vfunc_o10_9(m_bufExtra.FUN_14067c4c0(), nSize);
}

// @0x14071f710
void CPCDataPack::FUN_14071f710(CInputStream& in)
{
    m_n18 = in.vfunc_o8_4();
    m_n20 = in.vfunc_o8_4();
    m_n28 = in.vfunc_o8_4();
    int nSize = 0;
    nSize = in.vfunc_o8_3();
    m_bufRecord.FUN_140204670(nSize);
    in.vfunc_o8_9(m_bufRecord.FUN_140204eb0(), nSize);
    nSize = in.vfunc_o8_3();
    m_bufItems.FUN_140204670(nSize);
    in.vfunc_o8_9(m_bufItems.FUN_140204eb0(), nSize);
    nSize = in.vfunc_o8_3();
    m_bufExtra.FUN_140204670(nSize);
    in.vfunc_o8_9(m_bufExtra.FUN_140204eb0(), nSize);
}

// @0x14071f8a0
void CPCDataPack::FUN_14071f8a0(CPCData* pData)
{
    CByteBuffer buf;
    m_bufRecord.FUN_140720c30(buf);
    buf.FUN_140720e90(0);
    pData->FUN_14071ec80(buf);
}

// @0x14071f920
void CPCDataPack::FUN_14071f920(CPCData* pData)
{
    pData->FUN_14071e570(m_bufRecord);
}

// @0x14071f950
void CPCDataPack::FUN_14071f950(const ItemArray& aEquip, const ItemArray& aExtra, const CMsTime& tmBegin, const CMsTime& tmEnd,
                                const ItemArray& aMore)
{
    int nEquip = (int)aEquip.GetCount();
    static_cast<COutputStream&>(m_bufItems).vfunc_o10_1((unsigned char)nEquip);
    for (int i = 0; i < nEquip; i++) {
        const MS2Ptr<CItem>& spItem = aEquip.GetAt(i);
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_3(spItem->FUN_1405276c0());
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_4(spItem->FUN_140526a50());
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_1(spItem->FUN_140526c30());
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_3(spItem->FUN_140526bd0());
        spItem->FUN_140524ad0(m_bufItems);
    }
    bool bTimed = false;
    CMsTime tmNull(0);
    if (tmBegin > tmNull) {
        CMsTime tmNull2(0);
        bTimed = tmEnd == tmNull2 || FUN_140869440() < tmEnd.Get();
    }
    static_cast<COutputStream&>(m_bufItems).vfunc_o10_0(bTimed);
    static_cast<COutputStream&>(m_bufItems).vfunc_o10_4(tmBegin.Get());
    static_cast<COutputStream&>(m_bufItems).vfunc_o10_4(tmEnd.Get());
    int nMore = (int)aMore.GetCount();
    static_cast<COutputStream&>(m_bufItems).vfunc_o10_1((unsigned char)nMore);
    for (int j = 0; j < nMore; j++) {
        const MS2Ptr<CItem>& spItem = aMore.GetAt(j);
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_3(spItem->FUN_1405276c0());
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_4(spItem->FUN_140526a50());
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_1(spItem->FUN_140526c30());
        static_cast<COutputStream&>(m_bufItems).vfunc_o10_3(spItem->FUN_140526bd0());
        spItem->FUN_140524ad0(m_bufItems);
    }
    int nExtra = (int)aExtra.GetCount();
    static_cast<COutputStream&>(m_bufExtra).vfunc_o10_1((unsigned char)nExtra);
    for (int k = 0; k < nExtra; k++) {
        const MS2Ptr<CItem>& spItem = aExtra.GetAt(k);
        static_cast<COutputStream&>(m_bufExtra).vfunc_o10_1(spItem->FUN_140526b50());
        static_cast<COutputStream&>(m_bufExtra).vfunc_o10_3(spItem->FUN_1405276c0());
        static_cast<COutputStream&>(m_bufExtra).vfunc_o10_4(spItem->FUN_140526a50());
        static_cast<COutputStream&>(m_bufExtra).vfunc_o10_3(spItem->FUN_140526bd0());
        spItem->FUN_140524ad0(m_bufExtra);
    }
}

// @0x140720030
void CPCDataPack::FUN_140720030(ItemArray& aEquip, ItemArray& aExtra, bool& bTimed, CMsTime& tmBegin, CMsTime& tmEnd,
                                ItemArray& aMore)
{
    unsigned nEquip = static_cast<CInputStream&>(m_bufItems).vfunc_o8_1();
    for (int i = 0; i < (int)nEquip; i++) {
        int nId = static_cast<CInputStream&>(m_bufItems).vfunc_o8_3();
        __int64 nUid = static_cast<CInputStream&>(m_bufItems).vfunc_o8_4();
        unsigned nRarity = static_cast<CInputStream&>(m_bufItems).vfunc_o8_1();
        int nAmount = static_cast<CInputStream&>(m_bufItems).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nId, nAmount, 0)) {
            break;
        }
        spItem->FUN_140526c10(nRarity);
        spItem->FUN_140524eb0(static_cast<CInputStream&>(m_bufItems));
        spItem->FUN_140526a70(nUid);
        spItem->FUN_140526b30(0);
        aEquip.Add(spItem);
    }
    bTimed = static_cast<CInputStream&>(m_bufItems).vfunc_o8_0();
    tmBegin = static_cast<CInputStream&>(m_bufItems).vfunc_o8_4();
    tmEnd = static_cast<CInputStream&>(m_bufItems).vfunc_o8_4();
    unsigned nMore = static_cast<CInputStream&>(m_bufItems).vfunc_o8_1();
    for (int j = 0; j < (int)nMore; j++) {
        int nId = static_cast<CInputStream&>(m_bufItems).vfunc_o8_3();
        __int64 nUid = static_cast<CInputStream&>(m_bufItems).vfunc_o8_4();
        unsigned nRarity = static_cast<CInputStream&>(m_bufItems).vfunc_o8_1();
        int nAmount = static_cast<CInputStream&>(m_bufItems).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nId, nAmount, 0)) {
            break;
        }
        spItem->FUN_140526c10(nRarity);
        spItem->FUN_140524eb0(static_cast<CInputStream&>(m_bufItems));
        spItem->FUN_140526a70(nUid);
        spItem->FUN_140526b30(0);
        spItem->FUN_14052a130(2);
        aMore.Add(spItem);
    }
    unsigned nExtra = static_cast<CInputStream&>(m_bufExtra).vfunc_o8_1();
    for (int k = 0; k < (int)nExtra; k++) {
        unsigned char nUnused = static_cast<CInputStream&>(m_bufExtra).vfunc_o8_1();
        int nId = static_cast<CInputStream&>(m_bufExtra).vfunc_o8_3();
        __int64 nUid = static_cast<CInputStream&>(m_bufExtra).vfunc_o8_4();
        int nAmount = static_cast<CInputStream&>(m_bufExtra).vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nId, nAmount, 0)) {
            return;
        }
        spItem->FUN_140524eb0(static_cast<CInputStream&>(m_bufExtra));
        spItem->FUN_140526a70(nUid);
        spItem->FUN_140526b30(0);
        aExtra.Add(spItem);
    }
}

// @0x140720850 MS2-FUNCTIONAL: the exe frame is an EH function around the Crypto++ CRC32 (a try state not reproduced)
int CPCDataPack::FUN_140720850()
{
    int nCrcRecord = 0;
    int nCrcItems = 0;
    int nCrcExtra = 0;
    Unk_Crc32 crc;
    crc.FUN_142351b30();
    int nOut;
    unsigned nRecord = m_bufRecord.GetLength();
    const unsigned char* pRecord = m_bufRecord.FUN_14067c4c0();
    crc.FUN_1403901d0(nOut, pRecord, nRecord);
    nCrcRecord = nOut;
    unsigned nItems = m_bufItems.GetLength();
    const unsigned char* pItems = m_bufItems.FUN_14067c4c0();
    crc.FUN_1403901d0(nOut, pItems, nItems);
    nCrcItems = nOut;
    unsigned nExtra = m_bufExtra.GetLength();
    const unsigned char* pExtra = m_bufExtra.FUN_14067c4c0();
    crc.FUN_1403901d0(nOut, pExtra, nExtra);
    nCrcExtra = nOut;
    crc.FUN_140720aa0();
    return nCrcRecord + nCrcItems + nCrcExtra;
}

// @0x140720aa0
void Unk_Crc32::FUN_140720aa0()
{
    FUN_14038f3b0(this);
}

// ---- CByteBuffer members defined here ------------------------------------------------------------------------------------

// @0x140720c30
void CByteBuffer::FUN_140720c30(CByteBuffer& dest)
{
    unsigned nCount = m_uLength - m_uOffset;
    static_cast<COutputStream&>(dest).vfunc_o10_9(&m_aByteBuff.GetAt(0) + m_uOffset, nCount);
}

// @0x140720e90
void CByteBuffer::FUN_140720e90(unsigned uOffset)
{
    if (uOffset <= m_uLength) {
        m_uOffset = uOffset;
        return;
    }
    CString text;
    FUN_140714df0(text, CString("SetOffset"));
    throw Exception(text, 0x26);
}
