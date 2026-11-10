// ridee.h - Ridee (efd RTTI "Ridee", class id 0x06200045): the mount actor a player rides. Derives PCBase; the rider
// (+0xd48) drives it: most of its PCBase slots forward to the rider. Its riding table row (+0xdd0) names the model,
// the mount effects and the PhysX box the mount pushes around. One of the objs inside the units.tsv range of
// client\ms2\scenestategame.cpp (unit client\ms2\ridee.cpp, name assumed). Header name assumed.
#pragma once
#include <efd/SmartPointer.h>
#include <NiNode.h>
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/cubecraft_1.h"     // StateLocalController
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/placeholder/crideedata.h"   // CRideeData (the riding row)

class NxActor;
class RideeInterpolator;    // ?\rideeinterpolator.cpp

// The actor state controller of a Ridee (+0xd60): queues the state records sent to the server. 0x50 bytes,
// vftable 0x142f5b728 (one slot). The record list and the current record belong to StateLocalController (its ctor
// 0x1417b73c0 builds them, its implicit dtor's exe copy 0x1410a6dc0 is in cubecraft.cpp), as do the methods below
// (state.cpp).
class StateRideeController : public StateLocalController
{
public:
    StateRideeController();                                 // 0x141708950
    // ~StateRideeController() is implicit: 0x1417089c0 only calls the base dtor 0x1410a6dc0
    virtual void vfunc_0() override;                        // 0 0x1417b7b70 (state.cpp): send the current record

    void FUN_1417b7430(PCBase* pOwner);                     // init with the owner
    void FUN_1417b7450();                                   // drop the records
    int FUN_1417b7490();                                    // a record is due
    MS2Ptr<StateSyncObject> FUN_1417b7620();                 // copy of the current record
    void FUN_1417b7670(StateSyncObject* pRec);               // set the current record
    void FUN_1417b76b0(float fTime);                        // advance with the game time
};
MS2_CHECK_SIZE(StateRideeController, 0x50);

// 0xe00 bytes. vftable 0x142f5b738 (PCBase's 124 slots), CallbackObject vftable 0x142f5bb20.
// efd: TypeCast 0x1417092d0/0x141709280, GetClassDesc 0x141708af0, ??_G 0x141708a30, ClassInfo 0x143ae6ac0.
class Ridee : public PCBase
{
    EE_DECLARE_CLASS1(Ridee, 0x06200045, PCBase);

public:
    Ridee();                                                // 0x141703a70
    virtual ~Ridee();                                       // 0x141704240

    virtual int vfunc_10();                                 // 10  0x141704750
    virtual void vfunc_12();                                // 12  0x141704c80
    virtual void vfunc_21(efd::Point3 kDir);                // 21  0x1417053a0
    virtual void vfunc_24(int n);                           // 24  0x141705270
    virtual void vfunc_49();                                // 49  0x141706320
    virtual void vfunc_53(float f);                         // 53  0x1417079f0
    virtual int vfunc_57();                                 // 57  0x141705560
    virtual int vfunc_58();                                 // 58  0x141705220
    virtual void vfunc_67(efd::Point3* pDir, efd::Point3* pSide);   // 67  0x141706180
    virtual int vfunc_69();                                 // 69  0x141707070
    virtual Unk_PCBaseFxLib* vfunc_70();                    // 70  0x141705880
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80();          // 80  0x1417077a0
    virtual float vfunc_89();                               // 89  0x1417078d0
    virtual bool vfunc_102(MS2Ptr<CSkillRecord> skill);     // 102 0x141706260
    virtual MS2Ptr<Unk_PCBaseComp_b18> vfunc_103();         // 103 0x141707010
    virtual MS2Ptr<CSkillRecord> vfunc_104(bool a, bool b, bool c);  // 104 0x1417061e0
    virtual void vfunc_105(efd::Point3 kPos, void* b, void* c, int d);   // 105 0x141705430
    virtual int vfunc_108();                                // 108 0x141706fd0
    virtual void vfunc_110();                               // 110 0x141705620
    virtual void vfunc_114(void* p);                        // 114 0x1417065f0
    virtual float vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut);  // 115 0x141706490
    virtual int vfunc_116();                                // 116 0x1417062e0
    virtual void vfunc_119();                               // 119 0x141705640
    virtual int vfunc_122(void* p);                         // 122 0x141705500
    virtual const char* vfunc_123(int n);                   // 123 0x141705580

    int FUN_1417043a0(int nRideeId, int nObjectId, PCBase* pRider);  // bind the riding row
    void FUN_1417058b0();                                   // detach the seat nodes from the rider
    void FUN_141705ac0(double fTime);                       // per-frame update of the run effects
    void FUN_141705b60(double fTime);                       // run / stamina effects
    bool FUN_1417060d0();                                   // the rider has the stamina to run
    void SetRider(PCBase* pRider);                     // set the rider
    PCBase* GetRider();                                // the rider
    NiNode* FUN_141706560();                                // 0x141706560
    void FUN_141706590();                                   // flush the state controller
    void FUN_141706650(bool bForce);                        // send the state record when it changed
    float GetRideSpeed();                                  // speed with the rider's bonus
    float FUN_1417071d0();                                  // run speed with the rider's bonus
    void FUN_141707270();                                   // reset the state controller
    void FUN_1417072b0();                                   // load the rider's ugc ridee texture
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141707440();             // the rider's ugc ridee item
    void FUN_1417074c0();                                   // seat the rider
    int FUN_1417075e0();                                   // the rider may ride now
    MS2SvrPtr<CRideeData> GetData();                         // copy of m_spData
    float FUN_141707960();                                  // +0x64 of the default model entry
    void MakeNxBoxController();                             // 0x141707e60
    void FUN_1417082c0();                                   // release the PhysX box
    static void FUN_1417083a0(PCBase* pRider, efd::SmartPointer<NiAVObject> spSeat, Unk_RiderPtr spModel);

public:
    MS2_LAYOUT_FRIEND;
    unsigned int m_nD40;                                    // +0xd40 tick of the last stamina check
    unsigned int m_nD44;                                    // +0xd44 tick of the last "no stamina" notice
    PCBase* m_pRider;                                       // +0xd48
    efd::SmartPointer<NiNode> m_spD50;                      // +0xd50
    efd::SmartPointer<NiNode> m_spD58;                      // +0xd58
    StateRideeController m_controller;                      // +0xd60
    int m_nRunFx;                                           // +0xdb0 effect handle
    int m_nRunFx2;                                          // +0xdb4 effect handle (stamina run)
    int m_nIdleFx;                                          // +0xdb8 effect handle
    RideeInterpolator* m_pDC0;                              // +0xdc0 interpolator driving the seat node
    efd::SmartPointer<NiAVObject> m_spSeat;                 // +0xdc8 the rider's seat node
    MS2SvrPtr<CRideeData> m_spData;                         // +0xdd0
    int m_nDE0;                                             // +0xde0 the rider is above the water line
    NxActor* m_pBox;                                        // +0xde8 kinematic PhysX box
    Unk_IntervalTimer m_timerDF0;                           // +0xdf0
    bool m_bDF8;                                            // +0xdf8 force the next state record
};
MS2_CHECK_SIZE(Ridee, 0xe00);
MS2_CHECK_OFFSET(Ridee, m_pRider, 0xd48);
MS2_CHECK_OFFSET(Ridee, m_controller, 0xd60);
MS2_CHECK_OFFSET(Ridee, m_nRunFx, 0xdb0);
MS2_CHECK_OFFSET(Ridee, m_spData, 0xdd0);
MS2_CHECK_OFFSET(Ridee, m_pBox, 0xde8);
MS2_CHECK_OFFSET(Ridee, m_bDF8, 0xdf8);
