// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPvPInfo (the pvp state of a player), the pvp record block
// codecs and the two CQuestCommon field checks that follow them in the object.
// MS2-UNIT: ?\pvpinfo.cpp
// MS2-RANGE: 0x140743430-0x140744670 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\pvpinfo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "pvpinfo.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>

int FUN_140869420();                                                    // server time (seconds, low 32 bits)
int FUN_140768010(int nRange, int nBase);                               // random number in [nBase, nBase + nRange)
int FUN_140408410(ATL::CAtlArray<unsigned>* pArr, const int* pValue);   // index of the value, -1 if absent

// @0x140743430
CPvPInfo::CPvPInfo()
{
    m_nPoint = 0;
    m_nTeam = 0;
    m_nUnk20 = -1;
    m_nKill = 0;
    m_nWin = 0;
    m_nLose = 0;
    m_nMode = 0;
    m_nUnk34 = 0;
    m_nStartTime = 0;
}

// @0x1407434d0
CPvPInfo::~CPvPInfo()
{
}

// @0x140743550
bool CPvPInfo::FUN_140743550()
{
    return 0 < m_nPoint;
}

// @0x140743590
bool CPvPInfo::FUN_140743590()
{
    return m_nMode == 1;
}

// @0x1407435d0
bool CPvPInfo::FUN_1407435d0()
{
    return m_nMode == 2;
}

// @0x140743610
bool CPvPInfo::FUN_140743610()
{
    return m_nMode == 3;
}

// @0x140743650
bool CPvPInfo::FUN_140743650()
{
    return m_nMode == 4;
}

// @0x140743690
bool CPvPInfo::FUN_140743690()
{
    return m_nMode == 10;
}

// @0x1407436d0
bool CPvPInfo::FUN_1407436d0()
{
    return m_nMode == 5;
}

// @0x140743710
int CPvPInfo::GetPoint()
{
    return m_nPoint;
}

// @0x140743730
void CPvPInfo::FUN_140743730()
{
    m_nPoint = 0;
    m_nTeam = 0;
    m_nUnk20 = -1;
    m_nKill = 0;
    m_nWin = 0;
    m_nLose = 0;
    m_nUnk34 = 0;
    m_nMode = 0;
    m_nStartTime = 0;
}

// @0x1407437b0
void CPvPInfo::FUN_1407437b0(int nDelta)
{
    m_nKill += nDelta;
    m_nKill = (std::max)(m_nKill, 0);
}

// @0x140743810
void CPvPInfo::FUN_140743810(__int64 nDelta)
{
    m_nUnk34 += nDelta;
}

// @0x140743840
void CPvPInfo::FUN_140743840(int nDelta)
{
    m_nWin += nDelta;
    m_nWin = (std::max)(m_nWin, 0);
    if (m_nStartTime == 0)
        m_nStartTime = FUN_140869420();
}

// @0x1407438b0
void CPvPInfo::FUN_1407438b0(int nDelta)
{
    m_nLose += nDelta;
    m_nLose = (std::max)(m_nLose, 0);
}

// @0x140743910
void CPvPInfo::FUN_140743910()
{
    m_nTeam = FUN_140768010(2, 0);
}

// @0x140743940
int CPvPInfo::FUN_140743940()
{
    if (FUN_1407436d0())
        return *Client::Constants::GetInstance()->PvpOnePunchRewardItem.Get();
    else
        return *Client::Constants::GetInstance()->PvpFFARewardItem.Get();
}

// @0x1407439a0
void CPvPInfo::FUN_1407439a0(COutputStream* pOut)
{
    pOut->vfunc_o10_3(m_nPoint);
    pOut->vfunc_o10_1((unsigned char)m_nTeam);
    pOut->vfunc_o10_1((unsigned char)m_nMode);
}

// @0x140743a10
void CPvPInfo::FUN_140743a10(CInPacket& packet)
{
    m_nPoint = packet.vfunc_o8_3();
    m_nTeam = packet.vfunc_o8_1();
    m_nMode = packet.vfunc_o8_1();
}

// @0x140743ab0
void CPvPInfo::FUN_140743ab0(COutputStream* pOut)
{
    pOut->vfunc_o10_3(m_nWin);
    pOut->vfunc_o10_3(m_nLose);
    pOut->vfunc_o10_3(m_nKill);
}

// @0x140743b20
void CPvPInfo::FUN_140743b20(CInPacket& packet)
{
    m_nWin = packet.vfunc_o8_3();
    m_nLose = packet.vfunc_o8_3();
    m_nKill = packet.vfunc_o8_3();
}

// @0x140743bc0
void FUN_140743bc0(Unk_TrigPvpA* pBlock, COutputStream* pOut)
{
    pOut->vfunc_o10_4(pBlock->m_0);
    pOut->vfunc_o10_3((int)pBlock->m_8);
    pOut->vfunc_o10_3((int)pBlock->m_10);
    pOut->vfunc_o10_1((unsigned char)pBlock->m_18);
    pOut->vfunc_o10_4(pBlock->m_20);
    pOut->vfunc_o10_3((int)pBlock->m_28);
    pOut->vfunc_o10_3((int)pBlock->m_30);
    pOut->vfunc_o10_1((unsigned char)pBlock->m_38);
}

// @0x140743ca0
void FUN_140743ca0(Unk_TrigPvpA* pBlock, CInPacket* pPacket)
{
    pBlock->m_0 = pPacket->vfunc_o8_4();
    pBlock->m_8 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_10 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_18 = pPacket->vfunc_o8_1();
    pBlock->m_20 = pPacket->vfunc_o8_4();
    pBlock->m_28 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_30 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_38 = pPacket->vfunc_o8_1();
}

// @0x140743e20
void FUN_140743e20(Unk_TrigPvpB* pBlock, COutputStream* pOut)
{
    pOut->vfunc_o10_4(pBlock->m_0);
    pOut->vfunc_o10_3((int)pBlock->m_8);
    pOut->vfunc_o10_3((int)pBlock->m_10);
    pOut->vfunc_o10_1((unsigned char)pBlock->m_18);
    pOut->vfunc_o10_3(pBlock->m_1c);
    pOut->vfunc_o10_4(pBlock->m_20);
    pOut->vfunc_o10_3((int)pBlock->m_28);
    pOut->vfunc_o10_3((int)pBlock->m_30);
    pOut->vfunc_o10_1((unsigned char)pBlock->m_38);
    pOut->vfunc_o10_3(pBlock->m_3c);
    pOut->vfunc_o10_3(pBlock->m_40);
}

// @0x140743f50
void FUN_140743f50(Unk_TrigPvpB* pBlock, CInPacket* pPacket)
{
    pBlock->m_0 = pPacket->vfunc_o8_4();
    pBlock->m_8 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_10 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_18 = pPacket->vfunc_o8_1();
    pBlock->m_1c = pPacket->vfunc_o8_3();
    pBlock->m_20 = pPacket->vfunc_o8_4();
    pBlock->m_28 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_30 = (unsigned)pPacket->vfunc_o8_3();
    pBlock->m_38 = pPacket->vfunc_o8_1();
    pBlock->m_3c = pPacket->vfunc_o8_3();
    pBlock->m_40 = pPacket->vfunc_o8_3();
}

// @0x1407441f0
int CQuestCommon::FUN_1407441f0(int field)
{
    if (!FUN_140744cd0(field))
        return 0;
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return 0;
    if (data->m_300.m_0 == 0)
        return 0;
    if (!IsComplete())
        return 0;
    int nTarget = data->m_300.m_4;
    if (nTarget == 0)
        return 0;
    Unk_FieldIdList fields(10);
    CFieldMetaTable::GetInstance()->FUN_1406fb520(data->m_2ec, fields);
    if (fields.Find(field, 0) != 0)
        return 0;
    if (nTarget == field)
        return 0;
    return 1;
}

// @0x1407443e0
int CQuestCommon::FUN_1407443e0(int field)
{
    if (!FUN_140744cd0(field))
        return 0;
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return 0;
    int nKind = data->m_30c.m_0;
    int nRoomId = data->m_30c.m_roomId;
    int nFieldId = data->m_30c.m_fieldId;
    if (nRoomId == 0 && nFieldId == 0)
        return 0;
    if (nRoomId != 0)
    {
        DungeonRoomPtr spRoom = DungeonRoomTable::GetInstance()->GetRoom((unsigned)nRoomId);
        if (spRoom.operator==(0))
            return 0;
        if (FUN_140408410(&spRoom->m_fieldIDs, &field) != -1)
            return 0;
    }
    if (nKind == 1)
    {
        if (IsActive() && !IsComplete())
            return 1;
    }
    else if (nKind == 2)
    {
        if (IsComplete())
            return 1;
    }
    else if (nKind == 3 && IsActive())
        return 1;
    return 0;
}
