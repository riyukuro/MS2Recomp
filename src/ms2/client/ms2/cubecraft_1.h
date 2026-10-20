// cubecraft_1.h - the "guide object" actors of the cube/housing and fishing/magic systems (efd RTTI CGuideObject
// 0x06200065, CConstructionGuideObject 0x06200050, CFishingGuideObject 0x06200064, CSkillMagicControlGuide 0x06200081)
// and their state controller StatePcGuideObjectController. Owning unit: client\ms2\cubecraft.cpp#1
// (0x1410a0e80-0x1410a8550). Header name assumed. Layouts from the constructors / deleting destructors:
//   CGuideObject 0xda8, CConstructionGuideObject 0xe00, CFishingGuideObject 0xe98, CSkillMagicControlGuide 0xdd8.
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include <efd/SmartPointer.h>
#include <NiNode.h>

class Unk_GuideRecord;       // a placement/aim record of the controller (MS2Ptr, 0x1417b7620 returns the current one)
class CCubeGuideWrapper;     // cubeguide.h
class CubeItemInfo;          // cubeiteminfo.h
class CGodModeInfo;          // 0x30-byte floating "god mode" marker (ctor 0x141374xxx), unproven
class UIBirdHead;            // uibirdhead.h
class CMagicModel;           // 0x48-byte skill magic model
class Unk_SkillMagicInfo;    // skill-magic row held at CSkillMagicControlGuide + 0xda8
class Unk_MagicTarget;       // element of Unk_SkillMagicInfo's target list (+0x38)
class Unk_GuideEntity;       // the egf entity of a model (property setter 0x14098c6e0)

// The base of every actor state controller (vftable of one slot). Ctor 0x1417b73c0.
class StateLocalController
{
public:
    StateLocalController();                                 // 0x1417b73c0
    virtual void vfunc_0();                                 // 0 base body
};

// 0x58 bytes, vftable 0x142eaa1a8 (one slot: 0x1417b7a00). Created by CGuideObject at +0xd48.
class StatePcGuideObjectController : public StateLocalController
{
public:
    StatePcGuideObjectController();                         // 0x1410a6bb0
    ~StatePcGuideObjectController();                        // 0x1410a6df0 (member cleanup body 0x1410a6dc0)
    virtual void vfunc_0() override;                        // 0 0x1417b7a00

    void FUN_1417b7430(PCBase* pOwner);                     // init with the owning guide object
    int FUN_1417b7490();                                    // has a pending record
    MS2Ptr<Unk_GuideRecord> FUN_1417b7620();                // copy of the current record
    void FUN_1417b7670(Unk_GuideRecord* pRec);              // set the current record
    void FUN_1417b76b0(float fTime);                        // advance with the game time
    void FUN_1417b7b50(int nKind);                          // 0 construction, 1 fishing, 2 skill magic
    // w77 (state.cpp)
    void FUN_1417b7450();                                   // drop the current and queued records
    int FUN_1417b7540();                                    // total queued time (ms)
    void FUN_1417b7720();                                   // queue the current record

    void FUN_1410a6dc0();                                   // 0x1410a6dc0 member destruction body

    ATL::CAtlList<MS2Ptr<Unk_GuideRecord> > m_records;      // +0x08 (0x30)
    MS2Ptr<Unk_GuideRecord> m_spCurrent;                    // +0x38
    PCBase* m_pOwner;                                       // +0x48
    int m_nKind;                                            // +0x50 (3: never sent)
    int m_pad_54;
};
MS2_CHECK_SIZE(StatePcGuideObjectController, 0x58);
MS2_CHECK_OFFSET(StatePcGuideObjectController, m_records, 0x08);
MS2_CHECK_OFFSET(StatePcGuideObjectController, m_spCurrent, 0x38);

// 0xda8. vftable 0x142eaa1b8 (125 + 5 slots), CallbackObject vftable thunk 0x1410a7228.
class CGuideObject : public PCBase
{
    EE_DECLARE_CLASS1(CGuideObject, 0x06200065, PCBase);

public:
    CGuideObject();                                         // 0x1410a0e80
    virtual ~CGuideObject();                                // 0x1410a0fa0

    virtual void vfunc_53(float f) override;                // 53  0x1410a1930
    virtual void vfunc_114(void* p) override;               // 114 0x1410a1720
    virtual float vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut) override;   // 115 0x1410a1240
    virtual int vfunc_116() override;                       // 116 0x1410a1190
    // new slots 124..129
    virtual int vfunc_124(int nOwnerId, efd::Point3 kPos, efd::Point3 kDir, PCBase* pOwner);   // 0x1410a0ff0
    virtual void vfunc_125(double fTime);                   // 125 0x1410a11e0
    virtual void vfunc_126();                               // 126 0x1410a1340
    virtual void vfunc_127();                               // 127 0x1410a1780
    virtual void vfunc_128();                               // 128 0x1410a17d0
    virtual void vfunc_129(void* pStream);                  // 129 0x1410a1830

    void FUN_1410a12e0(PCBase* pOwner);             // 0x1410a12e0 m_nOwnerId = owner object id
    PCBase* FUN_1410a1310();                        // 0x1410a1310 the owner (world lookup by id)

    int m_nOwnerId;                                         // +0xd40
    StatePcGuideObjectController m_ctrl;                    // +0xd48
    bool m_bBusy;                                           // +0xda0
    bool m_bLocal;                                          // +0xda1 this guide belongs to the local player
};
MS2_CHECK_SIZE(CGuideObject, 0xda8);
MS2_CHECK_OFFSET(CGuideObject, m_nOwnerId, 0xd40);
MS2_CHECK_OFFSET(CGuideObject, m_ctrl, 0xd48);
MS2_CHECK_OFFSET(CGuideObject, m_bLocal, 0xda1);

// 0xe00. Shows where a cube will be placed (wrapper model + item + floating markers).
class CConstructionGuideObject : public CGuideObject
{
    EE_DECLARE_CLASS1(CConstructionGuideObject, 0x06200050, CGuideObject);

public:
    CConstructionGuideObject();                             // 0x1410a1990
    virtual ~CConstructionGuideObject();                    // 0x1410a1d60

    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSequence, float fCurrentTime) override;   // 0x1410a3a40
    virtual void vfunc_9(void* p) override;                 // 9   0x1410a3a10
    virtual int vfunc_10() override;                        // 10  0x1410a3640
    virtual int vfunc_11() override;                        // 11  0x1410a36c0
    virtual void vfunc_12() override;                       // 12  0x1410a39f0
    virtual void vfunc_14() override;                       // 14  0x1410a2a30
    virtual void vfunc_23(int n) override;                  // 23  0x1410a3d70
    virtual void vfunc_53(float f) override;                // 53  0x1410a3e70
    virtual void vfunc_67(efd::Point3* pDir, efd::Point3* pSide) override;   // 67  0x1410a3a60
    virtual bool vfunc_68(void* a, double t, int b, unsigned c, int d) override;   // 68 0x1410a3b20
    virtual void vfunc_125(double fTime) override;          // 125 0x1410a23c0
    virtual void vfunc_127() override;                      // 127 0x1410a34f0
    virtual void vfunc_128() override;                      // 128 0x1410a3560

    int FUN_1410a1ee0(int nOwnerId, efd::Point3 kPos, efd::Point3 kDir, PCBase* pOwner, int nExtra);   // init
    void FUN_1410a2440();                                   // follow the owner's cube selection
    void FUN_1410a29c0();                                   // drop the wrapper model
    int FUN_1410a2a60(void* pCube);                         // build the wrapper for the selected cube
    void FUN_1410a3190();                           // orient the wrapper model


    MS2Ptr<CCubeGuideWrapper> m_spGuide;                    // +0xda8
    MS2Ptr<CubeItemInfo> m_spItem;                          // +0xdb8
    int m_nDc8;                                             // +0xdc8
    int m_nDcc;                                             // +0xdcc
    NiPointer<NiNode> m_spModel;                            // +0xdd0
    NiPointer<NiNode> m_spLiftNode;                         // +0xdd8
    MS2Ptr<CGodModeInfo> m_spGod;                           // +0xde0
    MS2Ptr<UIBirdHead> m_spBirdHead;                        // +0xdf0
};
MS2_CHECK_SIZE(CConstructionGuideObject, 0xe00);
MS2_CHECK_OFFSET(CConstructionGuideObject, m_spGuide, 0xda8);
MS2_CHECK_OFFSET(CConstructionGuideObject, m_spItem, 0xdb8);
MS2_CHECK_OFFSET(CConstructionGuideObject, m_spModel, 0xdd0);
MS2_CHECK_OFFSET(CConstructionGuideObject, m_spBirdHead, 0xdf0);

// The fishing line effect (0xa8 bytes at CFishingGuideObject + 0xda8): first member is the owning guide. External
// ctor/dtor/updates are called through FUN_ members.
class Unk_FishLine
{
public:
    void FUN_140cd7d80();                                   // ctor
    void FUN_140cd7e40();                                   // dtor
    void FUN_140cd7eb0(int nHandle, const efd::Point3& kPos);   // start
    void FUN_140cd8080();                                   // stop
    void FUN_140cd80d0();                                   // update
    void* m_pOwner;                                         // +0 (0x1410a77c0)
    char m_pad_08[0xa0];
};
MS2_CHECK_SIZE(Unk_FishLine, 0xa8);

// 0xe98. The fishing line / float guide of a fishing player.
class CFishingGuideObject : public CGuideObject
{
    EE_DECLARE_CLASS1(CFishingGuideObject, 0x06200064, CGuideObject);

public:
    CFishingGuideObject();                                  // 0x1410a4080
    virtual ~CFishingGuideObject();                         // 0x1410a42e0

    virtual int vfunc_10() override;                        // 10  0x1410a4bc0
    virtual int vfunc_11() override;                        // 11  0x1410a4a20
    virtual void vfunc_24(int n) override;                  // 24  0x1410a5120
    virtual void vfunc_53(float f) override;                // 53  0x1410a5330
    virtual int vfunc_124(int nOwnerId, efd::Point3 kPos, efd::Point3 kDir, PCBase* pOwner) override;   // 0x1410a4480
    virtual void vfunc_127() override;                      // 127 0x1410a4720
    virtual void vfunc_128() override;                      // 128 0x1410a48c0

    void FUN_1410a4cb0();                                   // hide the float model
    void FUN_1410a4d30(void* pCatch);                       // show the catch text
    void FUN_1410a5690();                                   // rebuild the line points
    void FUN_1410a59f0();                                   // fishing gem name effect

    Unk_FishLine m_fishLine;                                // +0xda8 line effect
    int m_nEffectA;                                         // +0xe50
    int m_nEffectB;                                         // +0xe54
    int m_nEffectC;                                         // +0xe58
    ATL::CAtlArray<efd::Point3> m_line;                     // +0xe60
    MS2Ptr<UIBirdHead> m_spBirdHead;                        // +0xe80
    int m_nShown;                                           // +0xe90
};
MS2_CHECK_SIZE(CFishingGuideObject, 0xe98);

// 0xdd8. The aim marker of a controlled skill magic.
class CSkillMagicControlGuide : public CGuideObject
{
    EE_DECLARE_CLASS1(CSkillMagicControlGuide, 0x06200081, CGuideObject);

public:
    CSkillMagicControlGuide();                              // 0x1410a5c50
    virtual ~CSkillMagicControlGuide();                     // 0x1410a5e50

    virtual int vfunc_11() override;                        // 11  0x1410a65c0
    virtual void vfunc_24(int n) override;                  // 24  0x1410a65e0
    virtual void vfunc_53(float f) override;                // 53  0x1410a6840
    virtual void vfunc_125(double fTime) override;          // 125 0x1410a64d0
    virtual void vfunc_127() override;                      // 127 0x1410a60e0
    virtual void vfunc_128() override;                      // 128 0x1410a63d0

    int FUN_1410a5ea0(int nOwnerId, efd::Point3 kPos, efd::Point3 kDir, PCBase* pOwner,
        MS2Ptr<Unk_SkillMagicInfo> spInfo);                 // init (the info is by value: the callee destroys it)
    void FUN_1410a6520();                                   // release the control
    bool FUN_1410a65f0(int nSkill);                         // true when the target is out of range
    bool FUN_1410a6730();                                   // +0xdd0 released
    efd::Point3 FUN_1410a6750();                            // 12 bytes at +0xdb8
    float FUN_1410a6790();                                  // +0xdc8 (0 once released)
    float FUN_1410a67d0();                                  // +0xdcc
    long long FUN_1410a67f0();

    MS2Ptr<Unk_SkillMagicInfo> m_spInfo;                    // +0xda8
    efd::Point3 m_kAim;                                     // +0xdb8 (assigned with Point3::operator= 0x140194470)
    bool m_bControl;                                        // +0xdc4
    float m_fDc8;                                           // +0xdc8
    float m_fDcc;                                           // +0xdcc
    bool m_bReleased;                                       // +0xdd0
};
MS2_CHECK_SIZE(CSkillMagicControlGuide, 0xdd8);
