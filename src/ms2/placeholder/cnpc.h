// cnpc.h - shared declaration of CNpc (efd RTTI "CNpc", class id 0x06200028; derives PCBase; 0xf40 bytes): the client
// npc actor. NOT an original header. Constructor 0x14108e420, destructor 0x14108ef30, deleting dtor 0x14109a400 (both
// delete paths pass 0xf40). The definitions live in unit_14108e1e0 (owned by that unit); only declarations here. CPet
// (placeholder/cpet.h) derives it.
//
// Members were read from the ctor/dtor stores; types that no unit has recovered yet are opaque Unk_CNpc* blocks of the
// proven size (their ctor/dtor run inside the out-of-line CNpc ctor/dtor, so nobody in this tree constructs them).
#pragma once

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/timer.h"
#include "ms2/client/ms2/npcdatacli.h"          // NpcDataCli (+0xd50, the npc table row)
#include "ms2/client/ms2/questmanager_2.h"       // Unk_QmNpcQuestState (+0xdf0)
#include <efd/Matrix3.h>

class SkillLevelData;
class NxActor;
class CMaid;                 // commonfiles/maid.h
class CByteBuffer;       // commonfiles/stream.h (ApplySyncBlock)
class CInPacket;        // commonfiles/skilloverlapcompare.h (+0xd70)
class CRandomTargetEffect;   // randomtargeteffect.h (+0xf28; MS2Ptr(int) 0x140aac100, dtor 0x140aac190)

// +0xe18 (0x28): the hit-shake record (ctor 0x14108e1e0, dtor 0x14108e250). Start arms it, Update(time,
// target) shakes the model while active.
class CNpcVibrate : public CPtred
{
public:
    CNpcVibrate();                                          // 0x14108e1e0
    virtual ~CNpcVibrate();                                 // 0x14108e250
    int IsActive();                                    // armed flag (+0x24)
    void Start(float fStart, float fEnd, float fAmp); // +0x18/+0x1c/+0x20, armed
    void Update(float fTime, efd::Point3& kPos, class CNpc* pOwner); // shakes kPos while armed (disarms at m_fEnd; owner unused)
    float m_fStart;                                         // +0x18
    float m_fEnd;                                           // +0x1c
    float m_fAmp;                                           // +0x20
    int m_bActive;                                          // +0x24
};
MS2_CHECK_SIZE(CNpcVibrate, 0x28);

// +0xdb0 (0x30): the npc's marker (two end points, a width/length pair and a label); the same declaration as in
// unit_14160a7f0 (which owns the ctor 0x14160bd70 and the Set overloads). The implicit dtor 0x141099fc0 is this unit's.
struct Unk_NpcBeam
{
    Unk_NpcBeam();                                                                  // 0x14160bd70
    void Set(const efd::Point3& a, const efd::Point3& b, const CStringA& strLabel);     // 0x14160bde0
    void Set(const efd::Point3& a, const efd::Point3& b, float fWidth, float fScale, const CStringA& strLabel);     // 0x14160beb0

    bool m_bActive;             // +0x00
    efd::Point3 m_a;            // +0x04
    efd::Point3 m_b;            // +0x10
    float m_f1c;                // +0x1c
    float m_fWidth;             // +0x20
    float m_fLength;            // +0x24
    CStringA m_strLabel;        // +0x28
};
MS2_CHECK_SIZE(Unk_NpcBeam, 0x30);


class CNpc : public PCBase
{
    EE_DECLARE_CLASS1(CNpc, 0x06200028, PCBase);

public:
    CNpc();                                                 // 0x14108e420
    virtual ~CNpc();                                        // 0x14108ef30

    // GameObject / PCBase overrides (vftable 0x142ea8b58; unit_14108e1e0)
    virtual int vfunc_10() override;                        // 0x14108f0a0
    virtual void vfunc_12() override;                       // 0x14108f710
    virtual void vfunc_14() override;                       // 0x14108fb00
    virtual void vfunc_27(ATL::CAtlArray<MS2Ptr<CBoxCollision> >& kArr) override;   // 0x14108fc70
    virtual void vfunc_28(void* p) override;                // 0x14108fcb0
    virtual void vfunc_32(bool b) override;                 // 0x141090cd0
    virtual void vfunc_33(void* a, efd::Point3 kHit) override;      // 0x141097c40
    virtual void vfunc_34(void* p) override;                // 0x141098390
    virtual void vfunc_35(void* p) override;                // 0x141098940
    virtual void vfunc_43(float f) override;                // 0x1410945c0
    virtual void vfunc_45(float f) override;                // 0x14108fbb0
    virtual float vfunc_46(const efd::Point3& kPos) override;   // 0x14108fbe0
    virtual void vfunc_47(bool b) override;                 // 0x14108fc10
    virtual void vfunc_49() override;                       // 0x1410965d0
    virtual void vfunc_50() override;                       // 0x141095bd0
    virtual void vfunc_51(efd::Point3* pOffset) override;   // 0x141096340
    virtual void vfunc_53(float f) override;                // 0x1410952f0
    virtual int vfunc_58() override;                        // 0x14108fcf0
    virtual int vfunc_64() override;                        // 0x14108fd90
    virtual void vfunc_66(int n) override;                  // 0x1410935b0
    virtual bool vfunc_68(void* a, double t, int b, unsigned c, int d) override;   // 0x141092d20
    virtual int vfunc_69() override;                        // 0x141094640
    virtual Unk_PCBaseFxLib* vfunc_70() override;           // 0x14108fd60
    virtual CStringW vfunc_77() override;                   // 0x141090bd0
    virtual unsigned short vfunc_78() override;             // 0x14108fdc0
    virtual unsigned short vfunc_79() override;             // 0x14108fe10
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80() override; // 0x14108fe90
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82() override; // 0x141090030
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83() override; // 0x1410903b0
    virtual MS2Ptr<Unk_PCBaseComp_a98> vfunc_84() override; // 0x1410902f0
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85() override; // 0x1410904c0
    virtual void vfunc_90(void* p) override;                // 0x1410909a0
    virtual float vfunc_98(float f) override;               // 0x141090950
    virtual void vfunc_111(void* p, int a, int b, efd::Point3 kPos) override;   // 0x141090620
    virtual void vfunc_112(void* p, int n) override;        // 0x141090740
    virtual void vfunc_113(void* p) override;               // 0x141090820
    virtual float vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut) override;   // 0x141090850
    virtual int vfunc_116() override;                       // 0x141090ba0
    virtual const char* vfunc_123(int n) override;          // 0x1410905c0

    // new virtuals
    virtual int vfunc_124(int nNpcId);                      // 0x141090d60 set up from the npc table row
    virtual void vfunc_125(int n);                          // 0x141091210
    virtual void vfunc_126(int a, int b);                   // 0x1410916a0
    virtual int vfunc_127();                                // 0x141091740
    virtual int vfunc_128();                               // 0x141091760

    // non-virtual members called from other units
    MS2Ptr<NpcDataCli> GetNpcData();                     // copy of the npc row (+0xd50)
    void FUN_1410932c0(bool b);                             // forwarded to the object's UI entity
    int GetNpcId();                                    // npc id of the row (0: no row)
    void SetOwnerId(int nOwnerId);                       // m_nOwnerId = nOwnerId
    int GetOwnerId();                                    // m_nOwnerId
    PCBase* GetOwner();                                // the owner actor looked up by m_nOwnerId (world FindPC; null: none)
    int FUN_1410930a0();                                    // 0x1410930a0 (basecollision: a dead npc that still counts as a target)
    int GetNpcClass();                                  // 0x1410934c0 the npc kind (bit index of a kind mask)
    void ReleaseOwnerEffect();                                   // release the owner effect handle (+0xec4)

    // unit_14108e1e0 internals
    void FUN_141092c50(CInPacket& packet);                  // +0xf20 update (mode byte)
    void FUN_141092d40(CString strAnim);                    // bore animation debug trace
    int IsBoss();                                   // the row is a boss
    int IsClass4Or6();                                    // class 4 or 6
    bool IsMinimap();                                   // shown on the minimap
    int IsKind2();                                    // kind 2
    int IsKind3();                                    // kind 3
    int IsShopKind();                                   // shop kind
    unsigned short FUN_141093510();                         // m_nDE8
    CStringA FUN_141093530();                               // the marker label (empty when inactive)
    int GetNpcType();                                    // npc type (0: no row)
    int GetKind();                                    // kind (0: no row)
    MS2Ptr<CMaid> GetMaid();                          // the maid behind the npc (+0xe48 uid)
    void FlushDamageText();                                   // flush the accumulated damage text (+0xe60)
    void FUN_141095240(__int64 n);
    unsigned int GetQuestId();                           // quest state: quest id
    int GetQuestIcon();                                    // quest state: icon
    int GetQuestState();                                    // quest state: state
    void RefreshQuestState();                                   // refresh the quest state
    void FUN_141093e90();                                   // m_nE10 = 1
    void FUN_141093eb0();                                   // face the owner's model
    void PlayStartSound();                                   // play the start sound
    void PlayEndSound();                                   // play the end sound
    int GetTalkUiId();                                    // the ui the npc type opens
    int OpenTalkUi();                                    // open it
    void CloseTalkUi();                                   // close it
    bool IsInTalkRange();                                    // in talk range
    void SendInteractNpc();                                   // send packet 0x32 (talk)
    void SetMaidUid(__int64 nUid);                       // m_nE48 (maid uid)
    __int64 GetMaidUid();
    void FUN_141094dc0(__int64 n);                          // m_nE60 (accumulated damage)
    void FUN_141094df0(__int64 n);                          // m_nE60 += n
    __int64 FUN_141094e20();
    void SetDebugMode(bool b);                             // m_cEAC
    void UpdateQuestVisibility();                                   // portal quest visibility
    void SetOwnerEffect(CString strEffect);                  // set the owner effect (by value)
    void SetOwnerEffectActor(int nActor);                         // set the owner effect's actor
    void AttachOwnerEffect();                                   // attach the owner effect
    void FUN_141095190(const CString& strKfm);              // m_strED8
    void FUN_1410951d0(const CString& strKfm);              // set and load the model
    __int64 FUN_141095270();                                // m_nEE0
    void FUN_141095290(int n);                              // m_nF20
    void FUN_1410952b0(bool b);                             // m_cF38
    bool FUN_1410952d0();
    void FUN_141097a30();                                   // follow the dead body's pose
    void FUN_141097b40(unsigned short nGroup);              // the dead body's collision group
    void FUN_141098fb0(int nKind);                          // dead (0) / damage (1) effect
    void TurnTowardTargetYaw(float fTime);                        // turn toward m_f934
    void UpdateMonologue(float fTime);                        // monologue timer
    void ResetMonologueTimer();                                   // restart the monologue timer
    void BuildCollision();                                   // build the npc's collision
    void MakeDeadPhysXActor();                              // 0x141096f00
    void NxTerrainPhsyx();                                  // 0x141099640 the terrain-only body actor
    void FUN_1410947e0();                                   // the reward item model above the npc (+0xea8)
    CStringW GetName();                               // display name from the npc table
    CStringW GetTitle();                               // display name (maid title / maid row / npc name)
    void ApplySyncBlock(CByteBuffer& buf);                   // apply a sync block (scenestategame)
    void ReleaseDeadPhysXActor();
    void FUN_141099ab0();

    efd::Point3 m_posD40;                                   // +0xd40 (copied from the ZERO constant 0x143b01a60)
    MS2Ptr<NpcDataCli> m_spNpcData;                         // +0xd50 the npc table row
    NxActor* m_pD60;                                        // +0xd60 = 0 the dead body's PhysX actor
    NxActor* m_pD68;                                        // +0xd68 = 0 the body's PhysX actor
    MS2Ptr<SkillLevelData> m_spSkillRow;                    // +0xd70
    int m_nD80;                                             // +0xd80 = 3
    unsigned short m_nD84;                                  // +0xd84 = 4
    efd::Matrix3 m_unkD88;                                  // +0xd88 (identity)
    int m_nDAC;                                             // +0xdac = 0
    Unk_NpcBeam m_unkDB0;                                   // +0xdb0
    int m_nDE0;                                             // +0xde0
    int m_nDE4;                                             // +0xde4
    unsigned short m_nDE8;                                  // +0xde8
    unsigned short m_padDEA;
    int m_padDEC;
    Unk_QmNpcQuestState m_questState;                       // +0xdf0 the quest icon state (RefreshQuestState)
    int m_nE10;                                             // +0xe10
    int m_nE14;                                             // +0xe14
    CNpcVibrate m_vibrate;                                  // +0xe18
    char m_cE40;                                            // +0xe40
    __int64 m_nE48;                                         // +0xe48
    char m_cE50;                                            // +0xe50
    unsigned m_nE54;                                          // +0xe54 effect handle (released by the dtor)
    int m_nE58;                                             // +0xe58
    __int64 m_nE60;                                         // +0xe60
    ATL::CAtlArray<MS2Ptr<CBoxCollision> > m_arrE68;        // +0xe68
    ATL::CAtlArray<MS2Ptr<CBoxCollision> > m_arrE88;        // +0xe88
    int m_nEA8;                                             // +0xea8
    char m_cEAC;                                            // +0xeac
    int m_nEB0;                                             // +0xeb0 = 1
    int m_nEB4;                                             // +0xeb4
    int m_nEB8;                                             // +0xeb8
    int m_nOwnerId;                                         // +0xebc object id of the owner actor (0: none)
    int m_nEC0;                                             // +0xec0
    int m_nEC4;                                             // +0xec4 effect handle (ReleaseOwnerEffect)
    CString m_strEC8;                                       // +0xec8
    CString m_strED0;                                       // +0xed0
    CString m_strED8;                                       // +0xed8
    __int64 m_nEE0;                                         // +0xee0
    Timer m_timerEE8;                                       // +0xee8
    int m_nF20;                                             // +0xf20
    MS2Ptr<CRandomTargetEffect> m_spF28;                    // +0xf28
    bool m_cF38;                                            // +0xf38
};
MS2_CHECK_SIZE(CNpc, 0xf40);
MS2_CHECK_OFFSET(CNpc, m_spNpcData, 0xd50);
MS2_CHECK_OFFSET(CNpc, m_spSkillRow, 0xd70);
MS2_CHECK_OFFSET(CNpc, m_unkD88, 0xd88);
MS2_CHECK_OFFSET(CNpc, m_unkDB0, 0xdb0);
MS2_CHECK_OFFSET(CNpc, m_questState, 0xdf0);
MS2_CHECK_OFFSET(CNpc, m_vibrate, 0xe18);
MS2_CHECK_OFFSET(CNpc, m_nE54, 0xe54);
MS2_CHECK_OFFSET(CNpc, m_arrE68, 0xe68);
MS2_CHECK_OFFSET(CNpc, m_arrE88, 0xe88);
MS2_CHECK_OFFSET(CNpc, m_nOwnerId, 0xebc);
MS2_CHECK_OFFSET(CNpc, m_strEC8, 0xec8);
MS2_CHECK_OFFSET(CNpc, m_timerEE8, 0xee8);
MS2_CHECK_OFFSET(CNpc, m_spF28, 0xf28);
MS2_CHECK_OFFSET(CNpc, m_cF38, 0xf38);
