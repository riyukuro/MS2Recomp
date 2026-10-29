// CQuest subclasses created by CQuestManager's quest factory (0x1416ca9d0). Owner unit unrecovered
// (CEpicQuest ctor 0x14180fda0 ...); only the sizes (0x80 quests / 0x78 missions) and the constructors are proven.
#pragma once
#include "ms2/client/ms2/questmanager_1.h"

// The common base of the story quests (ctor 0x14180f030 sets m_78 = 1, m_7c = 0; dtor 0x14180f090; both in the
// ?\stringtable.cpp range). CEpicQuest (ctor 0x14180fda0) and CAllianceQuest (ctor 0x1416dba50) call its ctor.
class CStoryQuest : public CQuest
{
public:
    CStoryQuest();
    virtual ~CStoryQuest();
    void FUN_140d73960() override;                      // 0x14180f5c0
    void FUN_140d73950() override;                      // 0x14180fa50
    int FUN_140d73970() override;                       // 0x14180fa70
    void FUN_140d738e0() override;                      // 0x14180fbb0
    int FUN_140d738c0() override;                       // 0x14180fbe0
    int FUN_140d738d0() override;                       // 0x14180fc30
    int GetQuestType() override;                        // 0x141810970
    void DecodeStart(CInPacket& packet) override;       // 0x14180f0d0
    void DecodeProgress(CInPacket& packet) override;    // 0x14180f290
    void Complete(CInPacket& packet) override;          // 0x14180f2c0
    int FUN_14180fc80();                                // the quest can be dispatched/started here
    int m_78, m_7c;
};
MS2_CHECK_SIZE(CStoryQuest, 0x80);

class CEpicQuest : public CStoryQuest
{
public:
    CEpicQuest();
    virtual ~CEpicQuest();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CEpicQuest, 0x80);

class CWorldQuest : public CStoryQuest
{
public:
    CWorldQuest();
    virtual ~CWorldQuest();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CWorldQuest, 0x80);

class CEventQuest : public CStoryQuest
{
public:
    CEventQuest();
    virtual ~CEventQuest();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CEventQuest, 0x80);

class CGuildQuest : public CStoryQuest
{
public:
    CGuildQuest();
    virtual ~CGuildQuest();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CGuildQuest, 0x80);

class CFieldQuest : public CStoryQuest
{
public:
    CFieldQuest();
    virtual ~CFieldQuest();
    int GetQuestType() override;
    int GetTrackingState() override;                    // 0x141810070
    unsigned char GetFlag() override;                   // 0x1418100c0
    void Complete(CInPacket& packet) override;          // 0x141810140
    int FUN_140d738d0() override;                       // 0x1418101a0
};
MS2_CHECK_SIZE(CFieldQuest, 0x80);

// The inline members (ctor, GetQuestType, destructors) and the vftables are emitted by questmanager.cpp (the quest
// factory); the other overrides are out of line in the ?\stringtable.cpp range.
class CAllianceQuest : public CStoryQuest
{
public:
    CAllianceQuest();
    virtual ~CAllianceQuest() {}                        // 0x1416dc040 (resets the vfptrs: user-declared)
    unsigned char GetFlag() override;                   // 0x141810350
    int GetQuestType() override;
    void DecodeStart(CInPacket& packet) override;       // 0x141810210
    void Complete(CInPacket& packet) override;         // 0x1418102b0
};
MS2_CHECK_SIZE(CAllianceQuest, 0x80);

// The missions below are implemented in unit_140d72a60.cpp (ctors / dtors / ??_G pinned there).
class CDailyMission : public CQuest
{
public:
    CDailyMission();
    virtual ~CDailyMission();               // 0x140d72ab0 (resets the vfptrs: user-declared)
    int GetQuestType() override;
    void ShowProgress(int index) override;              // 0x140d72af0
    void PlayAcceptSound() override;                    // 0x140d72c20
    void PlayProgressSound() override;                  // 0x140d72c00
    void PlayRewardSound() override;                    // 0x140d72c10
    void Complete(CInPacket& packet) override;          // 0x140d72c70
    void ShowExpired() override;                        // 0x140d72c30
};
MS2_CHECK_SIZE(CDailyMission, 0x78);

class CFieldMission : public CQuest
{
public:
    CFieldMission();
    virtual ~CFieldMission();               // 0x140d72db0 (resets the vfptrs: user-declared)
    int GetQuestType() override;
    void Complete(CInPacket& packet) override;          // 0x140d72df0
};
MS2_CHECK_SIZE(CFieldMission, 0x78);

class CEventMission : public CQuest
{
public:
    CEventMission();
    virtual ~CEventMission();               // 0x140d730d0 (resets the vfptrs: user-declared)
    int GetQuestType() override;
    int Init(int id, int state) override;               // 0x140d73110
    void ShowProgress(int index) override;              // 0x140d73340
    void PlayAcceptSound() override;                    // 0x140d73420
    void PlayProgressSound() override;                  // 0x140d73400
    void PlayRewardSound() override;                    // 0x140d73410
    void Complete(CInPacket& packet) override;          // 0x140d73190
    void ShowExpired() override;                        // 0x140d73430
    int m_78;                                           // the data's +0x350 flag (1 = level package, 2 = stamp event)
};
MS2_CHECK_SIZE(CEventMission, 0x80);

class CMentoringMission : public CQuest
{
public:
    CMentoringMission();
    virtual ~CMentoringMission();           // 0x140d73490 (resets the vfptrs: user-declared)
    int GetQuestType() override;
    void ShowExpired() override;                        // 0x140d734d0
    int FUN_1407447c0() override;                       // 0x140d734e0 (CQuestCommon slot 8)
};
MS2_CHECK_SIZE(CMentoringMission, 0x78);

class CWeddingMission : public CQuest
{
public:
    CWeddingMission();
    virtual ~CWeddingMission();             // 0x140d735c0 (resets the vfptrs: user-declared)
    int GetQuestType() override;
    void ShowRewards(int reward) override;              // 0x140d73600
};
MS2_CHECK_SIZE(CWeddingMission, 0x78);
