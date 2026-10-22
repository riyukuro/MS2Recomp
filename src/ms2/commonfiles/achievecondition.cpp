// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CAchieveCondition / CAchieve: one achievement of the
// player (grade progress, values, requirement check, stream encode/decode). The first obj of .text$mn; it also
// instantiated CPtred's out-of-line members and the shared CAtlMap / MS2Ptr COMDATs.
// The units.tsv range `?\achievecondition.cpp` (0x1401580a0-0x14016da90) is two objs; the second one
// (CAchieveData, from 0x14015b490) is src/ms2/commonfiles/achievedata.cpp.
// MS2-UNIT: ?\achievecondition.cpp
// MS2-RANGE: 0x1401580a0-0x14015b490 .text$mn
// Key type of CAchieve::m_mapValue: the bytes only show a 32-bit key passed by value. Its CDefaultHashTraits /
// CDefaultCompareTraits COMDATs are this obj's (0x14015a330 / 0x140159be0); the second 32-bit instance
// (0x140167190 / 0x140165720, first used by achievedata.cpp's achievement table) is already harvested as both int
// (uiupperhpbar) and unsigned int (uiguideeventarrow, uidteventdialog). DWORD avoids the clash; int is as likely.
// MS2-PIN: ??_GCAchieveCondition@@UEAAPEAXI@Z 0x140159af0
// MS2-PIN: ??_GCPtred@@UEAAPEAXI@Z 0x140159b30
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@K@ATL@@SA_NAEBK0@Z 0x140159be0
// MS2-PIN: ?Hash@?$CDefaultHashTraits@K@ATL@@SAKAEBK@Z 0x14015a330
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\achievecondition.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "achievecondition.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// A game event (T of the pointer GameEventManagerCli::FindEvent returns; name unknown).
class Unk_GameEvent : public CPtred
{
};

// client\ms2\gameeventmanagercli.cpp (instance pointer 0x143aab380).
class GameEventManagerCli : public TSingleton<GameEventManagerCli>
{
public:
    bool IsEventClosed(CStringW strName);           // 0x140cead80
    MS2Ptr<Unk_GameEvent> FindEvent(int nId);       // 0x140ceacd0
};

int FUN_140718200(const CStringW& value);           // _wtoi (packetlogger.cpp)

// @0x140159740
CPtred::CPtred() : m_nRef(0), m_pad_10(0) {}
// @0x140159840
CPtred::~CPtred() {}

// @0x1401580a0
CAchieveCondition::CAchieveCondition()
{
    m_pData = NULL;
    m_nGoal = 0;
}
// @0x1401580f0
CAchieveCondition::~CAchieveCondition()
{
    m_pData = NULL;
}
// @0x140158130
int CAchieveCondition::Init(CConditionCommonData* pData, __int64 nGoal)
{
    int nResult = CConditionCommon::vfunc_3(pData);
    m_nGoal = nGoal;
    return nResult;
}
MS2_REPLACE_METHOD(0x140158130, CAchieveCondition, Init, 61, 0x1928E1A5);

// @0x140158180
CAchieve::CAchieve()
    : m_18(0), m_pData(0), m_30(0), m_38(0), m_40(0), m_nId(0), m_nState(0), m_80(0), m_nStartGrade(0),
      m_nCurGrade(0), m_d8(0)
{
}
// @0x1401582b0
CAchieve::~CAchieve()
{
    m_pData = 0;
    m_mapValue.RemoveAll();
}
// @0x140158350
int CAchieve::Init(int nId, int nGrade, int nState, int nUnused)
{
    m_nId = nId;
    m_pData = GetAchieveData(nId);
    if (m_pData == NULL)
        return 0;
    MS2Ptr<CAchieveGradeData> pGrade = m_pData->GetGrade(nGrade);
    if (pGrade == NULL)
    {
        pGrade = m_pData->GetGrade(m_pData->m_nFirstGrade);
        if (pGrade == NULL)
            return 0;
        else
            nGrade = m_pData->m_nFirstGrade;
    }
    m_nState = nState;
    m_cond.m_nCount = 0;
    if (!m_cond.Init(pGrade->m_pCondition, GetPrevGradeGoal(nGrade)))
        return 0;
    m_nCurGrade = nGrade ? nGrade : m_pData->m_nFirstGrade;
    m_nStartGrade = m_pData->m_nFirstGrade;
    m_80 = 0;
    m_mapValue.RemoveAll();
    return 1;
}
MS2_REPLACE_METHOD(0x140158350, CAchieve, Init, 726, 0xBF2491AC);
// @0x140158630
BOOL CAchieve::IsStarted()
{
    return m_cond.m_nCount != 0;
}
MS2_REPLACE_METHOD(0x140158630, CAchieve, IsStarted, 45, 0x5F592E00);
// @0x140158670
int CAchieve::GetData30()
{
    if (m_pData == NULL)
        return 0;
    return m_pData->m_nAccount;
}
MS2_REPLACE_METHOD(0x140158670, CAchieve, GetData30, 64, 0x41D4FCA4);
// @0x1401586c0
BOOL CAchieve::HasNextGrade()
{
    if (m_pData == NULL)
        return FALSE;
    return m_nCurGrade < m_pData->m_nMaxGrade;
}
MS2_REPLACE_METHOD(0x1401586C0, CAchieve, HasNextGrade, 99, 0x893AE9AC);
// @0x140158730
BOOL CAchieve::IsGradeReached()
{
    if (GetState() == 3)
        return m_nStartGrade <= m_nCurGrade;
    return m_nStartGrade < m_nCurGrade;
}
MS2_REPLACE_METHOD(0x140158730, CAchieve, IsGradeReached, 123, 0x331423E2);
// @0x1401587c0
BOOL CAchieve::IsCompleted()
{
    if (m_pData->m_nFirstGrade == m_pData->m_nMaxGrade)
        return GetState() == 3;
    return m_nCurGrade > m_pData->m_nFirstGrade;
}
MS2_REPLACE_METHOD(0x1401587C0, CAchieve, IsCompleted, 157, 0x4C0DDDE2);
// @0x140158870
int CAchieve::GetData68()
{
    if (m_pData == NULL)
        return 0;
    return m_pData->m_nLocking;
}
MS2_REPLACE_METHOD(0x140158870, CAchieve, GetData68, 64, 0x24CF358C);
// @0x1401588c0
BOOL CAchieve::IsValid()
{
    if (m_pData == NULL)
        return FALSE;
    return TRUE;
}
MS2_REPLACE_METHOD(0x1401588C0, CAchieve, IsValid, 49, 0xF4BB5101);
// @0x140158900
void CAchieve::Encode(COutputStream& s)
{
    s.WriteUInt8((unsigned char)m_nState);
    s.WriteInt32(m_80);
    s.WriteInt32(m_nCurGrade);
    s.WriteInt32(m_nStartGrade);
    s.WriteUInt8((unsigned char)m_d8);
    s.WriteInt64(m_cond.m_nCount);
    s.WriteInt32((int)m_mapValue.GetCount());
    for (POSITION pos = m_mapValue.GetStartPosition(); pos != NULL; m_mapValue.GetNext(pos))
    {
        int nKey = m_mapValue.GetKeyAt(pos);
        __int64 nValue = m_mapValue.GetValueAt(pos);
        s.WriteInt32(nKey);
        s.WriteInt64(nValue);
    }
}
MS2_REPLACE_METHOD(0x140158900, CAchieve, Encode, 391, 0x8BF80BE0);
// @0x140158a90
void CAchieve::Decode(CByteBuffer& b)
{
    m_nState = b.ReadUInt8();
    m_80 = b.ReadInt32();
    m_nCurGrade = b.ReadInt32();
    m_nStartGrade = b.ReadInt32();
    m_d8 = b.ReadUInt8();
    m_cond.m_nCount = b.ReadInt64();
    m_mapValue.RemoveAll();
    size_t nCount = (unsigned int)b.ReadInt32();
    for (size_t i = 0; i < nCount; ++i)
    {
        int nKey = b.ReadInt32();
        __int64 nValue = b.ReadInt64();
        m_mapValue.SetAt(nKey, nValue);
    }
}
MS2_REPLACE_METHOD(0x140158A90, CAchieve, Decode, 590, 0xD06D17DF);
// @0x140158cf0
int CAchieve::GetTab()
{
    int nTab = 3;
    if (GetType() != 2)
        return nTab;
    if (m_pData == NULL)
        return nTab;
    switch (m_pData->m_nCategory)
    {
    case 1: nTab = 0; break;
    case 2: nTab = 1; break;
    case 3: nTab = 2; break;
    }
    return nTab;
}
MS2_REPLACE_METHOD(0x140158CF0, CAchieve, GetTab, 154, 0xA60EB53F);
// @0x140158d90
Unk_AchieveReward* CAchieve::GetReward()
{
    MS2Ptr<CAchieveGradeData> pGrade = m_pData->GetGrade(m_nStartGrade);
    if ((CAchieveGradeData*)pGrade)
        return &pGrade->m_reward;
    return NULL;
}
MS2_REPLACE_METHOD(0x140158D90, CAchieve, GetReward, 141, 0x45AAB72A);
// @0x140158e30
__int64 CAchieve::GetGradeGoal(int nGrade)
{
    if (!m_pData)
        return 0;
    MS2Ptr<CAchieveGradeData> pGrade = m_pData->GetGrade(nGrade);
    if (!pGrade)
        return 0;
    return pGrade->m_pCondition->m_nGoal;
}
MS2_REPLACE_METHOD(0x140158E30, CAchieve, GetGradeGoal, 182, 0x4AF0323C);
// @0x140158ef0
__int64 CAchieve::GetGoal()
{
    return GetGradeGoal(m_nCurGrade);
}
MS2_REPLACE_METHOD(0x140158EF0, CAchieve, GetGoal, 35, 0x4368A371);
// @0x140158f20
int CAchieve::GetRewardCount()
{
    if (!m_pData)
        return 0;
    int nLast = GetState() == 3 ? m_nCurGrade : m_nCurGrade - 1;
    int nCount = 0;
    for (int i = m_nStartGrade; i <= nLast; ++i)
    {
        MS2Ptr<CAchieveGradeData> pGrade = m_pData->GetGrade(i);
        if (!pGrade)
            continue;
        if (pGrade->m_reward.m_nType == 0)
            continue;
        ++nCount;
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x140158F20, CAchieve, GetRewardCount, 278, 0x584F59FC);
// @0x140159040
__int64 CAchieve::GetValue(int nKey)
{
    __int64 nValue = 0;
    m_mapValue.Lookup(nKey, nValue);
    return nValue;
}
MS2_REPLACE_METHOD(0x140159040, CAchieve, GetValue, 60, 0x5B4908ED);
// @0x140159090
__int64 CAchieve::GetPrevGradeGoal(int nGrade)
{
    if (!m_pData)
        return 0;
    MS2Ptr<CAchieveGradeData> pGrade = m_pData->GetGrade(nGrade - 1);
    if (!pGrade)
        return 0;
    return pGrade->m_pCondition->m_nGoal;
}
MS2_REPLACE_METHOD(0x140159090, CAchieve, GetPrevGradeGoal, 194, 0xE3ADF7D4);
// @0x140159160
BOOL CAchieve::CheckRequire()
{
    if (!m_pData)
        return TRUE;
    int nType = m_pData->m_nRequireType;
    if (nType == 0)
        return FALSE;
    for (size_t i = 0; i < m_pData->m_aRequire.GetCount(); ++i)
    {
        switch (nType)
        {
        case 1:
            if (GameEventManagerCli::GetInstance()->IsEventClosed(m_pData->m_aRequire[i]))
                return FALSE;
        case 2:
            if (GameEventManagerCli::GetInstance()->FindEvent(FUN_140718200(m_pData->m_aRequire[i])) != NULL)
                return FALSE;
            break;
        }
    }
    return TRUE;
}
// not hooked: reads TSingleton<GameEventManagerCli>::s_instance (a DLL-local copy; RECOVERY.md section 9)
// @0x140159350
BOOL CAchieve::CanRewardRequire()
{
    if (!CheckRequire())
        return FALSE;
    return GetCurGrade() > m_pData->m_nFirstGrade;
}
// not hooked: reads TSingleton<GameEventManagerCli>::s_instance (a DLL-local copy; RECOVERY.md section 9)
// @0x1401593c0
BOOL CAchieve::CanRewardData68()
{
    if (!GetData68())
        return FALSE;
    return GetCurGrade() > m_pData->m_nFirstGrade;
}
MS2_REPLACE_METHOD(0x1401593C0, CAchieve, CanRewardData68, 91, 0x40E30D70);

static CString GetAchieveName(CAchieveData* pData);
// @0x140159430
CString CAchieve::GetName(int nUnused)
{
    return GetAchieveName(m_pData);
}
MS2_REPLACE_METHOD(0x140159430, CAchieve, GetName, 78, 0x3AE703C8);
// @0x140159490
static CString GetAchieveName(CAchieveData* pData)
{
    if (pData == NULL)
        return CString("");
    return pData->GetName();
}

MS2_EMIT_CRT_MEMMOVE_S();
