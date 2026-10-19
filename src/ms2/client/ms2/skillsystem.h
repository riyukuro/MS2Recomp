// skillsystem.h - CSkillSystem (RTTI .?AVCSkillSystem@@, 0x1f0 bytes, MyPC +0x13d8): the skill cooldown table, the
// learned emotions, the quick slot skill sets and the checks that decide whether a skill can be cast. Owning unit:
// ?\skillslot.cpp (ctor 0x1417646d0, dtor 0x141764900, deleting dtor 0x14176cfa0). Header name assumed; member
// names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class MyPC;
class CSkillRecord;
class CSkillCompactControlConfig;
class SkillData;
class SkillLevelData;
class Unk_MyPCSkillSet;
struct Unk_InventorySkillRequest;
class Unk_PCBaseComp_b18;

// One cooldown of the table at CSkillSystem +0x20 (0x28 bytes): the key is the cooldown key of the skill
// (group << 32 | id); times are the millisecond clock.
struct Unk_SkillCooltime
{
    Unk_SkillCooltime();                                    // 0x141764080
    Unk_SkillCooltime(unsigned nStart, float fDuration);    // 0x141764100
    float GetRemain();                                      // 0x1417641a0 the seconds left (0 once it is over)
    unsigned GetEnd();                                      // 0x1417641e0
    float GetTotal();                                       // 0x141764200 the seconds from start to end
    void Set(unsigned nStart, float fDuration);             // 0x141764230
    void SetEnd(unsigned nEnd);                             // 0x141764280
    void ClearEnd();                                        // 0x1417642a0
    int IsOver();                                           // 0x1417642c0 the end has passed
    int GetState();                                         // 0x141764300 1 once the end was announced
    void SetState(int nState);                              // 0x141764320

    unsigned __int64 m_nKey;                                // +0x00
    float m_fCombo;                                         // +0x08 the combo window (the key is kept)
    int m_bCombo;                                           // +0x0c started by a combo
    float m_f10;                                            // +0x10
    float m_f14;                                            // +0x14
    unsigned m_nStart;                                      // +0x18
    unsigned m_nEnd;                                        // +0x1c
    int m_nState;                                           // +0x20
};
MS2_CHECK_SIZE(Unk_SkillCooltime, 0x28);

// The skill system of the local player.
class CSkillSystem
{
public:
    // One learned emotion (RTTI CSkillSystem::stEmotion, 0x40). ctor 0x141764340, deleting dtor 0x14176cfe0.
    class stEmotion : public CPtred
    {
    public:
        stEmotion();                                        // 0x141764340
        bool FUN_1417643d0(const __int64* pNow);            // not expired at pNow
        int m_isNew;                                        // +0x18
        int m_id;                                           // +0x1c the emotion (item) id
        unsigned short m_level;                             // +0x20
        __int64 m_nExpire;                                  // +0x28 (0: never)
        __int64 m_n30;                                      // +0x30
        bool m_bPermanent;                                  // +0x38
        bool m_bFavorite;                                   // +0x39
    };

    CSkillSystem();                                         // 0x1417646d0
    virtual ~CSkillSystem();                                // 0x141764900
    bool FUN_141764a80(MyPC* pOwner);                       // init with the owner
    void FUN_141766af0(float fDelta);                       // per-frame update
    MS2Ptr<CSkillRecord> FUN_141765570(Unk_InventorySkillRequest& kReq);   // build the record of a request
    void FUN_141767f80(int nSkillId);                       // add a temporary skill
    void FUN_1417683d0();                                   // refresh the skill slots
    MS2Ptr<Unk_MyPCSkillSet> FUN_141768380();               // the temporary (ridee) skill set, if any
    void FUN_141768100(int nSkillId);                       // remove a temporary skill
    MS2Ptr<CSkillRecord> FUN_141764e30(Unk_InventorySkillRequest& kReq);   // cast a request
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141764e30(Unk_InventorySkillRequest* pReq);   // the same, the record as the casting skill (vfunc_104)
    int FUN_1417674a0(int n);                               // the pending skill id
    float FUN_141765fe0(int nSkillId, int n);              // the cooldown left of nSkillId
    int FUN_141768bd0(MS2Ptr<CSkillRecord> spRecord);       // the record may be cast during its cooldown
    void FUN_141766cc0(MS2Ptr<CSkillRecord> spRecord);
    void FUN_141767990(int nSkillId, unsigned short nLevel); // start the cooldown
    int FUN_141768fb0(unsigned int nSkillId, unsigned short nLevel);   // the emotion is learned
    void FUN_1417664e0(unsigned nStart, int nSkillId, float fCool, float fCombo, int bCombo);   // start a cooldown
    void FUN_141768900(MS2Ptr<CSkillRecord> spRecord);
    int FUN_141768770(class SkillData* pData);              // the skill's use-count condition
    int FUN_141766230(int nSkillId, float* pRemain, float* pTotal, int* pByItem, int nFlag);   // the cooldown of a skill
    int FUN_141765cf0(int n);                               // set m_18, return the old
    int FUN_141765d30(int n);                               // set m_88, return the old
    unsigned char FUN_141765a70(int nSkillId);              // the skill may be cast

    // not called outside the unit
    int FUN_141764ad0(SkillData* pData);                    // the skill id to cast for a skill row
    int FUN_141764be0(int nSkillId);                        // the skill the equipped weapon swaps in
    MS2Ptr<SkillLevelData> FUN_141764c80(int nSkillId);     // the learned level of a skill
    bool FUN_141765b80(int nSkillId);                       // the skill may be cast (by a row of the table)
    int FUN_141765d70();                                    // m_88
    bool FUN_141765d90();                                   // the cooldown table is not empty
    void FUN_141765de0();                                   // end every cooldown
    void FUN_141765e70(int nSkillId);                       // clear the cooldown of a skill
    void FUN_141765f60(unsigned __int64 nKey);              // clear the cooldown of a key
    void FUN_141766900(unsigned __int64 nKey, unsigned nEnd);   // start a cooldown that ends at nEnd
    void FUN_1417669c0(int nStart, int nSkillId, float fDuration);   // start a cooldown of a duration
    void FUN_141766d70();                                   // watch the ground state of the owner
    void FUN_141766ec0(int bForce);                         // refresh the lapenshard and compact control skills
    void FUN_141767ae0(class CByteBuffer* pBuffer);           // read the compact control configs
    void FUN_141767d90(ATL::CAtlList<MS2Ptr<CSkillCompactControlConfig> >* pList);   // replace the compact control configs
    void FUN_141767df0(int bOn);                            // enable or disable the skill use
    CStringW FUN_141767e60(unsigned __int64 nKey);          // the name of the compact control config of a key
    void FUN_141768530(int nSkillId, int nUses, int);       // set the use count of a skill
    void FUN_1417685c0(SkillData* pData, int nUses);        // set the use count of a recharge id
    int FUN_141768610(int nSkillId);                        // the use count of a skill
    int FUN_141768680(SkillData* pData);                    // the use count of a recharge id
    int FUN_1417686e0(int nSkillId);                        // the uses left of a skill
    void FUN_1417687e0(Unk_SkillCooltime* pCool);           // an over cooldown restores a use
    void FUN_141768a50();                                   // restart the recharge of the skills with uses
    void FUN_141768d40(MS2Ptr<SkillData> spSkill, float);   // start the emotion cooldown
    int FUN_141768dd0(MS2Ptr<SkillData> spSkill);           // the recharge tick
    void FUN_141768e70(int nId, unsigned short nLevel, __int64 nStart, __int64 nEnd, bool bPermanent, bool bFavorite, int bNew);   // learn an emotion
    void FUN_1417691a0(ATL::CAtlArray<MS2Ptr<stEmotion> >& arrOut);   // the emotions that are valid now
    void FUN_141769250();                                   // forget the emotions
    void FUN_141769280();                                   // the emotions are not new
    void FUN_141769440(int nError);                         // tell why a skill cannot be cast
    int FUN_141769410(SkillData* pData);                    // the jump skill of a skill
    int FUN_141769b70(MS2Ptr<SkillLevelData> spLevel, Unk_InventorySkillRequest* pReq);   // why a skill cannot be cast (0: it can)
    int FUN_14176a380(MS2Ptr<SkillLevelData> spLevel, Unk_InventorySkillRequest* pReq);
    int FUN_14176a530(MS2Ptr<SkillLevelData> spLevel);      // the costs of the skill
    int FUN_14176a8c0(SkillData* pData, Unk_InventorySkillRequest* pReq);   // the conditions of the skill
    __int64 FUN_14176b960(int nSkillId, __int64 nBase);     // the cost after the reductions
    MS2Ptr<SkillLevelData> FUN_14176b7c0(int nSkillId, unsigned short nLevel);   // the highest learned level not above nLevel
    MS2Ptr<stEmotion> FUN_14176ba90(int nId);               // emotion by id

    MS2_LAYOUT_FRIEND;
    MyPC* m_pOwner;                                         // +0x08
    float m_fLastCastTime;                                  // +0x10
    int m_nLastCastSkill;                                   // +0x14
    int m_nShowError;                                       // +0x18 (1)
    ATL::CAtlMap<unsigned __int64, Unk_SkillCooltime> m_mapCooltime;   // +0x20 by the cooldown key
    std::vector<MS2Ptr<stEmotion> > m_vEmotions;            // +0x68
    int m_nGroundState;                                     // +0x80
    float m_fGroundDistance;                                // +0x84
    int m_nCastAllowed;                                     // +0x88
    ATL::CAtlList<unsigned> m_lstLapenSkills;               // +0x90
    ATL::CAtlList<unsigned> m_lstLapenChains;               // +0xc0
    int m_nLapenJob;                                        // +0xf0 (1)
    int m_nf4;                                              // +0xf4
    ATL::CAtlList<MS2Ptr<CSkillCompactControlConfig> > m_lstCompact;   // +0xf8
    MS2Ptr<CSkillCompactControlConfig> m_spCompact;         // +0x128
    unsigned m_nLapenTick;                                  // +0x138
    int m_nLapenDirty;                                      // +0x13c (1)
    MS2Ptr<Unk_MyPCSkillSet> m_spSkillSet;                  // +0x140
    std::list<int> m_lstSkillSets;                          // +0x150
    ATL::CAtlMap<unsigned, int> m_mapUses;                  // +0x160 uses by recharge id
    ATL::CAtlMap<unsigned, unsigned> m_mapRechargeTick;       // +0x1a8
};
MS2_CHECK_SIZE(CSkillSystem, 0x1f0);
MS2_CHECK_OFFSET(CSkillSystem, m_mapCooltime, 0x20);
MS2_CHECK_OFFSET(CSkillSystem, m_vEmotions, 0x68);
MS2_CHECK_OFFSET(CSkillSystem, m_lstLapenSkills, 0x90);
MS2_CHECK_OFFSET(CSkillSystem, m_lstCompact, 0xf8);
MS2_CHECK_OFFSET(CSkillSystem, m_spSkillSet, 0x140);
MS2_CHECK_OFFSET(CSkillSystem, m_lstSkillSets, 0x150);
MS2_CHECK_OFFSET(CSkillSystem, m_mapUses, 0x160);
MS2_CHECK_OFFSET(CSkillSystem, m_mapRechargeTick, 0x1a8);
