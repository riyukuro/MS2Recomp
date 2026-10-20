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

class NxActor;
class RideeInterpolator;    // ?\rideeinterpolator.cpp

// A model entry of a riding row: the seat node of the rider and its offset/rotation on the mount.
class Unk_RideeModel
{
public:
    void* m_00;
    CString m_strNode;                                      // +0x08 seat node name
    float m_fX;                                             // +0x10 seat offset
    float m_fY;                                             // +0x14
    float m_fZ;                                             // +0x18
    float m_fRotX;                                          // +0x1c seat rotation (degrees)
    float m_fRotY;                                          // +0x20
    float m_fRotZ;                                          // +0x24
    CString m_str28;                                        // +0x28 seat animations (StateHold::vfunc_9 picks one)
    CString m_str30;                                        // +0x30
    CString m_str38;                                        // +0x38
    CString m_str40;                                        // +0x40
    CString m_str48;                                        // +0x48
    CString m_str50;                                        // +0x50
    CString m_str58;                                        // +0x58
    float m_f60;                                            // +0x60 (vfunc_89)
    float m_f64;                                            // +0x64
};
MS2_CHECK_OFFSET(Unk_RideeModel, m_fRotX, 0x1c);
MS2_CHECK_OFFSET(Unk_RideeModel, m_str28, 0x28);
MS2_CHECK_OFFSET(Unk_RideeModel, m_str58, 0x58);
MS2_CHECK_OFFSET(Unk_RideeModel, m_f60, 0x60);

// The seat (model entry) list of a riding row.
class Unk_RideeSeatList
{
public:
    int FUN_140784180();                                    // count
    char m_pad[0x18];
};

// The equip part list of a riding row.
class Unk_RideePartList
{
public:
    size_t FUN_14078cd60();                                 // count
    const CEffectDummy& FUN_140789540(size_t i);            // GetAt
    char m_pad[0x18];
};

// The riding row. Strings name the mount's effects; +0x108..+0x110 is the PhysX box (width, depth, height).
class Unk_RideeData
{
public:
    CString FUN_140784880(int nLevel);                      // animation (kfm) name for the rider's level
    CString FUN_140784920(int nLevel);                      // scene graph (nif) name for the rider's level
    MS2Ptr<Unk_RideeModel> FUN_140784970();                 // the default model entry
    MS2Ptr<Unk_RideeModel> FUN_1407849c0(int i);            // model entry i of the seat list

    char m_pad_00[0x30];
    int m_nNameId;                                          // +0x30
    char m_pad_34[4];
    int m_nType;                                            // +0x38 1/2: the rider is not slowed down
    char m_pad_3c[0x1c];
    float m_fScale;                                         // +0x58
    int m_n5c;                                              // +0x5c nonzero: the rider is hidden while riding
    char m_pad_60[4];
    int m_n64;                                              // +0x64 nonzero: the ridee can be left by a type 0xf ride off
    char m_pad_68[4];
    int m_nSeats;                                           // +0x6c (>1: the ridee carries passengers)
    int m_nSkillId;                                         // +0x70 the skill learned while riding
    char m_pad_74[4];
    float m_f78;                                            // +0x78
    float m_f7c;                                            // +0x7c run speed
    float m_f80;                                            // +0x80 walk speed
    float m_f84;                                            // +0x84
    int m_n88;                                              // +0x88 nonzero: the rider cannot get off by input
    char m_pad_8c[4];
    CString m_str90;                                        // +0x90 (vfunc_123 0x1e)
    CString m_str98;                                        // +0x98 (vfunc_123 0x1f)
    __int64 m_nA0;                                          // +0xa0 stamina needed to run (0: none)
    char m_pad_a8[4];
    int m_nAC;                                              // +0xac nonzero: the ride name replaces the rider's (PC::vfunc_77)
    char m_pad_b0[8];
    CString m_strB8;                                        // +0xb8 run start effect
    CString m_strC0;                                        // +0xc0 run start effect (stamina)
    char m_pad_c8[8];
    CString m_strD0;                                        // +0xd0 run loop effect
    CString m_strD8;                                        // +0xd8 run loop effect (stamina)
    CString m_strE0;                                        // +0xe0 idle loop effect
    CString m_strE8;                                        // +0xe8 ride-off effect (RideOffAction type 0x18)
    char m_pad_f0[0x18];
    float m_f108;                                           // +0x108 box width
    float m_f10c;                                           // +0x10c box depth
    float m_f110;                                           // +0x110 box height
    bool m_b114;                                            // +0x114 pushes props (PhysX box)
    char m_pad_115[0xb];
    float m_f120;                                           // +0x120 shadow size
    char m_pad_124[0x144];
    Unk_RideeSeatList m_seats;                              // +0x268
    Unk_RideePartList m_parts;                              // +0x280 equip parts
};
MS2_CHECK_OFFSET(Unk_RideeData, m_nNameId, 0x30);
MS2_CHECK_OFFSET(Unk_RideeData, m_fScale, 0x58);
MS2_CHECK_OFFSET(Unk_RideeData, m_nA0, 0xa0);
MS2_CHECK_OFFSET(Unk_RideeData, m_strE0, 0xe0);
MS2_CHECK_OFFSET(Unk_RideeData, m_f108, 0x108);
MS2_CHECK_OFFSET(Unk_RideeData, m_f120, 0x120);
MS2_CHECK_OFFSET(Unk_RideeData, m_seats, 0x268);
MS2_CHECK_OFFSET(Unk_RideeData, m_parts, 0x280);

// The actor state controller of a Ridee (+0xd60): queues the state records sent to the server. 0x50 bytes,
// vftable 0x142f5b728 (one slot). The record list and the current record belong to StateLocalController (its ctor
// 0x1417b73c0 builds them, its inline dtor's exe copy 0x1410a6dc0 is in cubecraft.cpp), as do the methods below
// (state.cpp); cubecraft_1.h declares StateLocalController without them.
class StateRideeController : public StateLocalController
{
public:
    StateRideeController();                                 // 0x141708950
    ~StateRideeController() { FUN_1410a6dc0(); }           // 0x1417089c0 (functional: the exe copy does not reset the vfptr)
    virtual void vfunc_0() override;                        // 0 0x1417b7b70 (state.cpp): send the current record

    void FUN_1410a6dc0();                                   // StateLocalController's member destruction

    void FUN_1417b7430(PCBase* pOwner);                     // init with the owner
    void FUN_1417b7450();                                   // drop the records
    int FUN_1417b7490();                                    // a record is due
    MS2Ptr<Unk_StateArg22> FUN_1417b7620();                 // copy of the current record
    void FUN_1417b7670(Unk_StateArg22* pRec);               // set the current record
    void FUN_1417b76b0(float fTime);                        // advance with the game time

    char m_pad_08[0x48];                                    // StateLocalController: records +0x08, current +0x38
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
    virtual MS2Ptr<Unk_PCBaseComp_b18> vfunc_104(bool a, bool b, bool c);  // 104 0x1417061e0
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
    void FUN_141706510(PCBase* pRider);                     // set the rider
    PCBase* FUN_141706540();                                // the rider
    NiNode* FUN_141706560();                                // 0x141706560
    void FUN_141706590();                                   // flush the state controller
    void FUN_141706650(bool bForce);                        // send the state record when it changed
    float FUN_1417070a0();                                  // speed with the rider's bonus
    float FUN_1417071d0();                                  // run speed with the rider's bonus
    void FUN_141707270();                                   // reset the state controller
    void FUN_1417072b0();                                   // load the rider's ugc ridee texture
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141707440();             // the rider's ugc ridee item
    void FUN_1417074c0();                                   // seat the rider
    int FUN_1417075e0();                                   // the rider may ride now
    MS2Ptr<Unk_RideeData> FUN_141707750();                 // copy of m_spData
    float FUN_141707960();                                  // +0x64 of the default model entry
    void MakeNxBoxController();                             // 0x141707e60
    void FUN_1417082c0();                                   // release the PhysX box
    static void FUN_1417083a0(PCBase* pRider, efd::SmartPointer<NiAVObject> spSeat, MS2Ptr<Unk_RideeModel> spModel);

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
    MS2Ptr<Unk_RideeData> m_spData;                         // +0xdd0
    int m_nDE0;                                             // +0xde0 the rider is above the water line
    NxActor* m_pBox;                                        // +0xde8 kinematic PhysX box
    Unk_140517b00 m_timerDF0;                               // +0xdf0
    bool m_bDF8;                                            // +0xdf8 force the next state record
};
MS2_CHECK_SIZE(Ridee, 0xe00);
MS2_CHECK_OFFSET(Ridee, m_pRider, 0xd48);
MS2_CHECK_OFFSET(Ridee, m_controller, 0xd60);
MS2_CHECK_OFFSET(Ridee, m_nRunFx, 0xdb0);
MS2_CHECK_OFFSET(Ridee, m_spData, 0xdd0);
MS2_CHECK_OFFSET(Ridee, m_pBox, 0xde8);
MS2_CHECK_OFFSET(Ridee, m_bDF8, 0xdf8);
