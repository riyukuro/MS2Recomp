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
#include <efd/Matrix3.h>

class SkillLevelData;        // commonfiles/skilloverlapcompare.h (+0xd70)
class CRandomTargetEffect;   // randomtargeteffect.h (+0xf28; MS2Ptr(int) 0x140aac100, dtor 0x140aac190)

// +0xe18 (0x28): the hit-shake record (ctor 0x14108e1e0, dtor 0x14108e250). FUN_14108e2a0 arms it, FUN_14108e300(time,
// target) shakes the model while active.
class CNpcVibrate : public CPtred
{
public:
    CNpcVibrate();                                          // 0x14108e1e0
    virtual ~CNpcVibrate();                                 // 0x14108e250
    int FUN_14108e280();                                    // armed flag (+0x24)
    void FUN_14108e2a0(int nAmp, int nDuration, int nScale); // +0x18/+0x1c/+0x20, armed
    void FUN_14108e300(float fTime, efd::Point3& kPos);     // shakes kPos while armed (disarms after m_nDuration)
    int m_nAmp;                                             // +0x18
    int m_nDuration;                                        // +0x1c
    int m_nScale;                                           // +0x20
    int m_bActive;                                          // +0x24
};
MS2_CHECK_SIZE(CNpcVibrate, 0x28);

// +0xdb0 (0x30): the npc's marker (two end points, a width/length pair and a label); the same declaration as in
// unit_14160a7f0 (which owns the ctor 0x14160bd70 and the Set overloads). The implicit dtor 0x141099fc0 is this unit's.
struct Unk_NpcBeam
{
    Unk_NpcBeam();                                                                  // 0x14160bd70
    void Set(const efd::Point3& a, const efd::Point3& b, const char* pszLabel);     // 0x14160bde0
    void Set(const efd::Point3& a, const efd::Point3& b, float fWidth, float fScale, const char* pszLabel);     // 0x14160beb0

    bool m_bActive;             // +0x00
    efd::Point3 m_a;            // +0x04
    efd::Point3 m_b;            // +0x10
    float m_f1c;                // +0x1c
    float m_fWidth;             // +0x20
    float m_fLength;            // +0x24
    CStringA m_strLabel;        // +0x28
};
MS2_CHECK_SIZE(Unk_NpcBeam, 0x30);

// +0xdf0 (0x1c): the value block cproxygameobject.h calls Unk_ProxyValue88 (ctor 0x140964630, dtor 0x140964e40; that
// header can't be included here: worldservice_4.cpp defines its own CProxyGameObject). Bound by symbols-manual rows.
class Unk_CNpcDF0
{
public:
    Unk_CNpcDF0();                                          // 0x140964630
    ~Unk_CNpcDF0();                                         // 0x140964e40
private:
    int m_pad[7];
};
MS2_CHECK_SIZE(Unk_CNpcDF0, 0x1c);

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
    virtual void vfunc_27(ATL::CAtlArray<Unk_GoAnchorPtr>& kArr) override;   // 0x14108fc70
    virtual void vfunc_28(void* p) override;                // 0x14108fcb0
    virtual void vfunc_32(bool b) override;                 // 0x141090cd0
    virtual void vfunc_33(void* a, void* b) override;      // 0x141097c40
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
    virtual int vfunc_78() override;                        // 0x14108fdc0
    virtual void vfunc_79() override;                       // 0x14108fe10
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80() override; // 0x14108fe90
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82() override; // 0x141090030
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83() override; // 0x1410903b0
    virtual MS2Ptr<Unk_PCBaseComp_a98> vfunc_84() override; // 0x1410902f0
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85() override; // 0x1410904c0
    virtual void vfunc_90(void* p) override;                // 0x1410909a0
    virtual float vfunc_98(float f) override;               // 0x141090950
    virtual void vfunc_111(void* p, int a, int b, void* q) override;   // 0x141090620
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
    virtual bool vfunc_128();                               // 0x141091760

    // non-virtual members called from other units
    MS2Ptr<NpcDataCli> FUN_141093270();                     // copy of the npc row (+0xd50)
    void FUN_1410932c0(int n);                              // forwarded to the object's UI entity
    int FUN_141092fa0();                                    // npc id of the row (0: no row)
    void FUN_141094f20(int nOwnerId);                       // m_nOwnerId = nOwnerId
    int FUN_141094f40();                                    // m_nOwnerId
    PCBase* FUN_141094f60();                                // the owner actor looked up by m_nOwnerId (world FindPC; null: none)
    int FUN_1410930a0();                                    // 0x1410930a0 (basecollision: a dead npc that still counts as a target)
    unsigned char FUN_1410934c0();                                  // 0x1410934c0 the npc kind (bit index of a kind mask)
    void FUN_141095140();                                   // release the owner effect handle (+0xec4)

    // unit_14108e1e0 internals
    CStringW FUN_141093310();                               // display name from the npc table
    void FUN_1410979a0();
    void FUN_141099ab0();

    efd::Point3 m_posD40;                                   // +0xd40 (copied from the ZERO constant 0x143b01a60)
    MS2Ptr<NpcDataCli> m_spNpcData;                         // +0xd50 the npc table row
    void* m_pD60;                                           // +0xd60 = 0
    void* m_pD68;                                           // +0xd68 = 0
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
    Unk_CNpcDF0 m_unkDF0;                                   // +0xdf0
    int m_padE0C;
    int m_nE10;                                             // +0xe10
    int m_nE14;                                             // +0xe14
    CNpcVibrate m_vibrate;                                  // +0xe18
    char m_cE40;                                            // +0xe40
    __int64 m_nE48;                                         // +0xe48
    char m_cE50;                                            // +0xe50
    int m_nE54;                                             // +0xe54 effect handle (released by the dtor)
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
    int m_nEC4;                                             // +0xec4 effect handle (FUN_141095140)
    CString m_strEC8;                                       // +0xec8
    CString m_strED0;                                       // +0xed0
    CString m_strED8;                                       // +0xed8
    __int64 m_nEE0;                                         // +0xee0
    Timer m_timerEE8;                                       // +0xee8
    int m_nF20;                                             // +0xf20
    MS2Ptr<CRandomTargetEffect> m_spF28;                    // +0xf28
    char m_cF38;                                            // +0xf38
};
MS2_CHECK_SIZE(CNpc, 0xf40);
MS2_CHECK_OFFSET(CNpc, m_spNpcData, 0xd50);
MS2_CHECK_OFFSET(CNpc, m_spSkillRow, 0xd70);
MS2_CHECK_OFFSET(CNpc, m_unkD88, 0xd88);
MS2_CHECK_OFFSET(CNpc, m_unkDB0, 0xdb0);
MS2_CHECK_OFFSET(CNpc, m_unkDF0, 0xdf0);
MS2_CHECK_OFFSET(CNpc, m_vibrate, 0xe18);
MS2_CHECK_OFFSET(CNpc, m_nE54, 0xe54);
MS2_CHECK_OFFSET(CNpc, m_arrE68, 0xe68);
MS2_CHECK_OFFSET(CNpc, m_arrE88, 0xe88);
MS2_CHECK_OFFSET(CNpc, m_nOwnerId, 0xebc);
MS2_CHECK_OFFSET(CNpc, m_strEC8, 0xec8);
MS2_CHECK_OFFSET(CNpc, m_timerEE8, 0xee8);
MS2_CHECK_OFFSET(CNpc, m_spF28, 0xf28);
MS2_CHECK_OFFSET(CNpc, m_cF38, 0xf38);
