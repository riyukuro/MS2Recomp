// jobsystemcli.h - JobSystemCli (RTTI .?AVJobSystemCli@@, 0xb8 bytes, base JobSystem): the client side of the job skill
// tree. It lets the local player's temporary skill sets and tier options override the learnt levels, forwards skill
// changes to the owning PC and sends the skill requests (packet 0x25: operation 7 = request, 8 = reset). Owning unit:
// ?\jobsystemcli.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/jobsystem.h"

class PCBase;

class JobSystemCli : public JobSystem
{
public:
    // The skill request (op 7) as written by FUN_1401fdb50.
    struct Request
    {
        Request();                                                  // 0x140a6e670
        int m_nJob;                                                 // +0x00
        __int64 m_nSerial;                                          // +0x08
        int m_nSkill;                                               // +0x10
        unsigned short m_nLevel;                                    // +0x14
    };

    JobSystemCli();                                                 // 0x140a6d890
    virtual ~JobSystemCli();                                        //  0 0x140a6e6b0 (??_G 0x140a6e6d0)
    virtual MS2Ptr<SkillLevelData> vfunc_1(unsigned nSkillId);      //  1 0x140a6d910 the level data with the temporary skill sets
    virtual bool vfunc_2(unsigned nSkillId);                        //  2 0x140a6da90 learnt, or granted by a temporary source
    virtual void vfunc_3(int nJobGroup, unsigned nSkillId, unsigned short nLevel);   //  3 0x140a6de30
    virtual void vfunc_4(unsigned short nLevel);                    //  4 0x140a6de80
    virtual unsigned short vfunc_5(unsigned nSkillId);              //  5 0x140a6dec0 bonus levels
    virtual void vfunc_7(CByteBuffer& buf);                         //  7 0x140a6e0a0

    void SetOwner(PCBase* pOwner);                             // set the owning PC
    void RequestReset();                                            // 0x140a6e0e0
    void RequestSkill(unsigned __int64 nSerial, int nSkill, unsigned short nLevel);     // 0x140a6e140
    void SendRequest(int nJob, unsigned __int64 nSerial, int nSkill, unsigned short nLevel);    // 0x140a6e190
    void Refresh();                                                 // 0x140a6e240 tell the PC every learnt skill
    void RefreshActiveStance();                                     // 0x140a6e360
    void NotifySkill(int nSkillId, unsigned short nLevel);          // 0x140a6e430 tell the PC one skill
    int ChangedMainSkills();                                        // 0x140a6e4d0 changed non-sub skills
    int FUN_140a6e640();                                            // the job group, 0 for group 1
    int FUN_140639340();                                            // (PC::FUN_141654700)
    int FUN_1406393f0();                                            // (PC::FUN_141654730)
    int FUN_1406394b0();                                            // (PC::FUN_141654760)

private:
    MS2_LAYOUT_FRIEND;
    PCBase* m_pOwner;                                               // +0xb0
};
MS2_CHECK_SIZE(JobSystemCli, 0xb8);
MS2_CHECK_OFFSET(JobSystemCli, m_pOwner, 0xb0);
