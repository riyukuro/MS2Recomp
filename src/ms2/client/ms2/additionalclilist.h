// additionalclilist.h - the actor's additional effect list (PCBase +0x748, 0x1a0 bytes; no RTTI): the AdditionalCli
// records of an actor keyed by their key, and the state the active records add up to (status, motion, consume, the
// special abilities, the shield record). Recovered with ?\additionalcli.cpp#2 (0x14096ee00-0x140978f40). Header and
// class names assumed (pcbase.h declares the same object as Unk_PCBaseBuffList; the exe's members are FUN_<va>).
// SAInvokeEffectStat (RTTI, 0x60): the invoke effect options one skill / effect gets from the active records.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/invokeeffectoption.h"
#include "ms2/client/ms2/additionalcli.h"

class PCBase;
class MyPC;
class CInPacket;
class CSpecialEffectCtx;
class SkillAttackData;

// the stat option type key of SAInvokeEffectStat (an enum in the exe: the key is passed by reference)
enum Unk_InvokeOptionType { INVOKE_OPTION_NONE };

class SAInvokeEffectStat : public CPtred
{
public:
    SAInvokeEffectStat();                                   // 0x1409755e0
    virtual ~SAInvokeEffectStat();                          // 0x140975870 (??_G 0x140975d00)

    ATL::CAtlMap<Unk_InvokeOptionType, MS2Ptr<InvokeEffectOption> > m_18;   // +0x18 stat option type -> option
};
MS2_CHECK_SIZE(SAInvokeEffectStat, 0x60);

class AdditionalCliList
{
public:
    typedef ATL::CRBMap<unsigned, MS2Ptr<AdditionalCli> > Map;
    typedef ATL::CAtlMap<unsigned, MS2Ptr<SAInvokeEffectStat> > StatMap;

    AdditionalCliList(PCBase* pOwner);                      // 0x14096ef20
    ~AdditionalCliList();                                   // 0x14096f000

    int FUN_14096f070(MS2Ptr<AdditionalCli> sp);            // add a record (0: invalid or the key is taken)
    void FUN_14096f500(int nKey, int nCaster);              // remove a record
    MS2Ptr<AdditionalCli> FUN_14096f820(const Unk_AdditionalOwner& owner, CInPacket& packet);   // modify packet
    void FUN_14096fb20(int nEvent);                         // drop the records of an invoke event
    void FUN_14096fc00(int nKey);                           // drop a record
    MS2Ptr<AdditionalCli> FUN_14096fc80(int nKey);          // a record by key
    MS2Ptr<AdditionalCli> FUN_14096fd30(int nType);         // the first active record of an event buff type
    MS2Ptr<AdditionalCli> FUN_14096fe60(unsigned nId, unsigned short nLevel, unsigned nCount, bool bAll, int nCompare);
    int FUN_140970020(unsigned nId, unsigned short nLevel, unsigned nCount, int nCompare);
    int FUN_1409700d0(int nType);                           // an active record of a main type
    int FUN_1409701d0(int nType);                           // an active record of an event buff type
    int FUN_1409702d0(int nGroup);                          // an active record of a group
    bool FUN_1409703d0(int nSlot);                          // the item slot is disabled
    void FUN_140970420(double dTime);                       // per-frame update
    void FUN_140970490();                                   // clear
    float FUN_1409705d0();                                  // scale
    float FUN_140970700();                                  // the applied alpha
    float FUN_140970720();                                  // the alpha the records ask for
    __int64 FUN_1409708a0();                                // shield total
    int FUN_140970990();                                    // hide
    unsigned FUN_1409709b0();                               // stun kind
    int FUN_1409709d0();                                    // stunned
    int FUN_140970a00();                                    // no fly
    bool FUN_140970a20();                                   // pvp on
    int FUN_140970a40();                                    // confusion move
    int FUN_140970a60(unsigned nSkillId);                   // the skill is disabled
    bool FUN_140970ad0();                                   // revival disabled here
    int FUN_140970af0();                                    // invincible
    int FUN_140970b10();                                    // force apply target
    unsigned FUN_140970b30();                               // super armor (the skill's when higher)
    unsigned FUN_140970bf0();                               // skill use disable mask
    int FUN_140970c10(SkillAttackData* pAttack, int nPush); // the super armor resists the attack
    bool FUN_140970d70();                                   // infinity sp
    unsigned FUN_140970d90(unsigned nId, unsigned short nLevel);   // overlap count of a record
    int FUN_140970eb0(float& fOut);                         // fixed z rotation
    __int64 FUN_140970f00(int nType, __int64 nValue);       // consume value scaled by the rates
    float FUN_140970fb0();                                  // sp consume -> hp rate
    float FUN_140970fd0();                                  // sp rate
    void FUN_140970ff0(CInPacket& packet);                  // the full list (field enter)
    void FUN_140971150();                                   // re-apply the alpha
    unsigned FUN_1409711c0();                               // ignored collision groups
    int FUN_140971260(int nId);                             // an active record of an id
    int FUN_140971300(int nId, int nCaster);                // an active record of an id by a caster
    void FUN_1409713b0();                                   // stun state
    CString FUN_1409716a0();                                // stun animation
    int FUN_1409716f0(SAType eType);                        // special ability value
    void FUN_140971720(StatMap& skills, StatMap& effects);  // invoke effect options per skill / effect
    void FUN_140972380(CSpecialEffectCtx* pCtx);            // run the special effects of a kind
    void FUN_1409725d0();                                   // dirty
    void FUN_1409725f0(ATL::CAtlList<MS2Ptr<AdditionalCli> >& list);   // all records
    MS2Ptr<AdditionalCli> FUN_140972690();                  // the shield record
    static int FUN_1409726e0(unsigned nSuperArmor, ApplyFieldType eField);
    void FUN_140972770();                                   // alpha
    void FUN_1409728b0();                                   // update the records, drop the finished ones
    void FUN_140972a00();                                   // sum the active records
    void FUN_1409733f0();                                   // sound pitch
    void FUN_140973450();                                   // skill use disable changed
    void FUN_1409734b0();                                   // infinity sp on the main player info
    void FUN_140973520();                                   // reset the sums
    bool FUN_1409735c0();                                   // the owner is the local player
    bool FUN_140973600();                                   // the owner is a PC
    bool FUN_140973640();                                   // the owner is a portrait
    bool FUN_140973680(MS2Ptr<AdditionalCli> sp);           // shown on the upper hp bar / duel dialog
    MyPC* FUN_140973920();                                  // the owner as the local player
    void FUN_140973950(MS2Ptr<AdditionalCli> sp);           // added: buff UIs, balloon, shield bar
    void FUN_140973cc0(MS2Ptr<AdditionalCli> sp);           // removed: buff UIs, balloon, shield bar
    void FUN_140973f40(MS2Ptr<AdditionalCli> sp);           // added: PC bang flags
    void FUN_140974090(MS2Ptr<AdditionalCli> sp);           // removed: PC bang flags
    void FUN_140974130(MS2Ptr<AdditionalCli> sp);           // removed: get off the ridee

    Map m_map;                                              // +0x00 key -> record (block size 10)
    PCBase* m_pOwner;                                       // +0x30
    float m_fAlpha;                                         // +0x38 (1.0)
    AdditionalLevelData::StatusProperty m_status;           // +0x40
    AdditionalLevelData::MotionProperty m_motion;           // +0xa0
    AdditionalLevelData::ConsumeProperty m_consume;         // +0x168
    int m_nInvincible;                                      // +0x174
    bool m_bPvpOnOff;                                       // +0x178
    bool m_bDisableRevivalHere;                             // +0x179
    unsigned m_nItemSlotDisable;                            // +0x17c
    int m_nForceApplyTarget;                                // +0x180
    bool m_bInfinitySP;                                     // +0x184
    unsigned m_nSkillUseDisable;                            // +0x188 the last notified mask
    int m_bDirty;                                           // +0x18c
    MS2Ptr<AdditionalCli> m_spShield;                       // +0x190
};
MS2_CHECK_SIZE(AdditionalCliList, 0x1a0);
MS2_CHECK_OFFSET(AdditionalCliList, m_status, 0x40);
MS2_CHECK_OFFSET(AdditionalCliList, m_motion, 0xa0);
MS2_CHECK_OFFSET(AdditionalCliList, m_consume, 0x168);
MS2_CHECK_OFFSET(AdditionalCliList, m_bDirty, 0x18c);
MS2_CHECK_OFFSET(AdditionalCliList, m_spShield, 0x190);
