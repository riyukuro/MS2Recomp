// CQuest object recovered separately from the following CQuestManager object.
// Names other than RTTI class names are inferred.
#pragma once
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/cinpacket.h"

class PCBase;
// This array's element/traits spelling is not recovered. Both standard signed
// and unsigned CAtlArray instantiations bind to different exe helpers, so retain
// a declaration-only typed interface to this distinct instantiation. Its ctor,
// dtor, bounds checks and growth are in unit_1401b6d10, outside this object.
class Unk_QuestProgressArray
{
public:
    Unk_QuestProgressArray() noexcept;
    ~Unk_QuestProgressArray() noexcept;
    size_t FUN_1401b8910() const;
    const __int64& FUN_1401b88c0(size_t index) const;
    __int64& FUN_1401b7ff0(size_t index);
    size_t FUN_140280400(__int64 value);
private:
    __int64* m_values;
    size_t m_size, m_capacity;
    int m_growBy;
};
MS2_CHECK_SIZE(Unk_QuestProgressArray, 0x20);
class CQuestCommon
{
public:
    CQuestCommon();
    virtual MS2Ptr<CQuestData> GetData() = 0;
    virtual int IsComplete() const = 0;
    virtual int IsActive() = 0;
    virtual int IsRewarded() = 0;
    virtual __int64 GetStartTime() = 0;
    virtual int FUN_1407441f0(int field);
    virtual int FUN_1407443e0(int field);
    virtual int FUN_140744670(int field);
    virtual int FUN_1407447c0();
    virtual __int64 FUN_1407448a0();
    virtual int FUN_140744b90(int field);
    int FUN_140744cd0(int field);      // questdata.cpp: the quest's field exists
};
MS2_CHECK_SIZE(CQuestCommon, 8);

class CQuest : public CPtred, public CQuestCommon
{
public:
    CQuest();
    virtual ~CQuest();
    virtual int Init(int id, int state);
    virtual unsigned char GetFlag();
    virtual int GetTrackingState();
    virtual void FUN_140d73960();
    virtual void FUN_140d73950();
    virtual int FUN_140d73970();
    virtual void FUN_140d738e0();
    virtual int FUN_140d738c0();
    virtual int FUN_140d738d0();
    virtual void ShowProgress(int index);
    virtual void PlayAcceptSound();
    virtual void PlayProgressSound();
    virtual void PlayRewardSound();
    virtual void ShowRewards(int reward);
    virtual int GetQuestType() = 0;
    virtual void DecodeStart(CInPacket& packet);
    virtual void DecodeProgress(CInPacket& packet);
    virtual void Complete(CInPacket& packet);
    virtual void ShowExpired();

    MS2Ptr<CQuestData> GetData() override;
    int IsComplete() const override;
    int IsActive() override;
    int IsRewarded() override;
    __int64 GetStartTime() override;
    int FUN_1407443e0(int field) override;
    int FUN_140744670(int field) override;

    __int64 GetProgress(int index) const;
    void SetProgress(int index, __int64 count);
    int IsConditionComplete(int index);
    int CheckUserFind(PCBase* actor);
    int GetTrackedValue();
    void SetTrackingState(int state);
    void RequestTrackingState(int state);
    void SetTrackedValue(int value);
    int HasMultiUserRoom(int field);
    int GetState() const;
    int FUN_140bfc580();
    void SetState(int state) { m_state = state; }   // COMDAT 0x1416dee60
    void SetStartTime(__int64 time) { m_startTime = time; }         // COMDAT 0x1416ded20
    void SetCompleteTime(__int64 time) { m_completeTime = time; }   // COMDAT 0x1416dedd0
    void Set68(int value) { m_68 = value; }                         // COMDAT 0x1416dedb0

    int m_state;
    MS2Ptr<CQuestData> m_data;
    Unk_QuestProgressArray m_progress;
    __int64 m_startTime, m_completeTime;
    int m_68, m_trackingState, m_trackedValue;
};
MS2_CHECK_SIZE(CQuest, 0x78);
MS2_CHECK_OFFSET(CQuest, m_state, 0x20);
MS2_CHECK_OFFSET(CQuest, m_data, 0x28);
MS2_CHECK_OFFSET(CQuest, m_progress, 0x38);
MS2_CHECK_OFFSET(CQuest, m_startTime, 0x58);
MS2_CHECK_OFFSET(CQuest, m_trackedValue, 0x70);
