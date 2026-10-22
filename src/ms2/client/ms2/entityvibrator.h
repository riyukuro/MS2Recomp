// entityvibrator.h - CEntityVibrator (RTTI .?AVCEntityVibrator@@, 0xd8 bytes, CPtred): shakes a world entity (a prop that
// is hit) for a while around its rest position, then either settles it or drops a physics box that falls and spins and
// is deleted again. Owning unit: client\ms2\entityvibrator.cpp (0x1411cb290-0x1411ce0f4). Header name assumed; member
// names invented from their use.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/cubespawnobject.h"     // Unk_EntRef, Unk_Entity (forward)

class NxActor;
class Unk_VibParams;

// 8-byte counted reference to the vibration parameters (a zone row); copy ctor 0x1409f71b0, dtor 0x140975740,
// operator-> 0x140975bd0 (members declared in the .cpp).
struct Unk_VibParamRef
{
    Unk_VibParamRef(const Unk_VibParamRef& o);              // 0x1409f71b0
    ~Unk_VibParamRef();                                     // 0x140975740
    Unk_VibParams* FUN_140975bd0() const;                   // operator->
    void* m_p;
};
MS2_CHECK_SIZE(Unk_VibParamRef, 8);

class CEntityVibrator : public CPtred
{
public:
    CEntityVibrator(Unk_Entity* pEntity);                                                       // 0x1411cb290
    CEntityVibrator(Unk_Entity* pEntity, Unk_VibParamRef params, CString strModel, unsigned char nMode);   // 0x1411cb390
    virtual ~CEntityVibrator();                                                                 // 0x1411cb9f0

    int FUN_1411cba60();                        // per-frame update: 1 while running, 0 when finished
    void MakePhysxActor(Unk_VibParamRef params);  // 0x1411cc570
    void FUN_1411cd040();                       // release the physics actor
    void FUN_1411cd0c0();                       // copy the actor's pose back to the entity
    void FUN_1411cd3b0();                       // stop: restore the rest pose and remove the actor
    int FUN_1411cd550();                        // physics mode flag
    void FUN_1411cd570(Unk_Entity* pEntity);    // read the entity's properties
    void FUN_1411cda60(Vector3 pos);    // set the entity position when it changed
    void FUN_1411cdb00(Vector3 rot);    // set the entity rotation when it changed
    void FUN_1411cdba0();                       // start the physics fall
    void FUN_1411cdd90();                       // cancel the fall
    void FUN_1411cddc0(CString strModel, unsigned char nMode);   // swap the model and set the mode

    Unk_EntRef m_entity;                        // +0x18
    float m_20;                                 // frequency
    float m_24;                                 // amplitude
    float m_28;                                 // amplitude floor (0..1)
    unsigned m_2c;                              // start time
    unsigned m_30;                              // spawn time
    unsigned m_34;                              // end time
    unsigned m_38;                              // fade start time
    Vector3 m_3c;                       // shake direction
    Vector3 m_48;                       // rest position
    Vector3 m_54;                       // rest rotation
    int m_60;                                   // sign of the last sample
    float m_64;                                 // phase
    NxActor* m_68;                              // physics actor
    Vector3 m_70;                       // impact point
    int m_7c;                                   // physics mode
    int m_80;
    int m_84;
    int m_88;
    unsigned m_8c;
    unsigned m_90;
    int m_94;
    Vector3 m_98;                       // box size
    float m_a4;                                 // scale
    bool m_a8;
    bool m_a9;
    bool m_aa;
    bool m_ab;
    Vector3 m_ac;                       // last position written
    Vector3 m_b8;                       // last rotation written
    int m_c4;
    CString m_c8;                               // model name
    unsigned char m_d0;                         // mode
};
MS2_CHECK_OFFSET(CEntityVibrator, m_entity, 0x18);
MS2_CHECK_OFFSET(CEntityVibrator, m_3c, 0x3c);
MS2_CHECK_OFFSET(CEntityVibrator, m_68, 0x68);
MS2_CHECK_OFFSET(CEntityVibrator, m_70, 0x70);
MS2_CHECK_OFFSET(CEntityVibrator, m_98, 0x98);
MS2_CHECK_OFFSET(CEntityVibrator, m_a4, 0xa4);
MS2_CHECK_OFFSET(CEntityVibrator, m_ac, 0xac);
MS2_CHECK_OFFSET(CEntityVibrator, m_c8, 0xc8);
MS2_CHECK_OFFSET(CEntityVibrator, m_d0, 0xd0);
MS2_CHECK_SIZE(CEntityVibrator, 0xd8);
