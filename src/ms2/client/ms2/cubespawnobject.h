// cubespawnobject.h - CubeSpawnObject (efd RTTI "CubeSpawnObject", class id 0x06200080): an NPC-model actor
// spawned on a housing cube (pets/plants that grow, are fed and talk). Derives PCBase. Owning unit:
// ?\cubespawnobject.cpp (0x140a4e690-0x140a50440). Header name assumed.
#pragma once
#include "ms2/client/ms2/pcbase.h"
#include <efd/SmartPointer.h>

class NpcDataCli;           // npc table row (npcdatacli.h; the table is FUN_1406d6e90())
class Unk_HpBarFx;          // housing-object gauge effect (lookup FUN_1419936d0(id), removal FUN_141993750(id))
class Unk_Entity;           // egf entity behind the spawn's entity handle
// egf/Entity.h is not included here: its ID statics would reorder the dependents' dynamic initializers.
namespace egf { class Entity; typedef efd::SmartPointer<Entity> EntityPtr; }

// The entity handles are egf::EntityPtr (efd::SmartPointer<egf::Entity>: ctor 0x1408b6680, dtor 0x1408a8720,
// operator=(T*) 0x1408b6ec0, operator= 0x140964eb0, data / operator T* 0x1408a9090, operator-> 0x1408a9280,
// operator==(T*) 0x1408b70b0, operator!=(T*) 0x140965490).

// 0xdd0 bytes. vftable 0x142dc7b40 (125 slots: PCBase's 124 + slot 124), CallbackObject vftable 0x142dc7f30.
// efd: TypeCast 0x140a50110/0x140a500c0, GetClassDesc 0x140a50000, ??_G 0x140a4ff50, ClassInfo 0x143ab69c0
// (setup 0x140a50060).
class CubeSpawnObject : public PCBase
{
    EE_DECLARE_CLASS1(CubeSpawnObject, 0x06200080, PCBase);

public:
    CubeSpawnObject();                                      // 0x140a4e690
    virtual ~CubeSpawnObject();                             // 0x140a4ebe0

    virtual void vfunc_9(void* p);                          // 9   0x140a4f710
    virtual int vfunc_11();                                 // 11  0x140a4fab0
    virtual void vfunc_12();                                // 12  0x140a4f9f0
    virtual void vfunc_53(float f);                         // 53  0x140a4faf0
    virtual int vfunc_69();                                 // 69  0x140a4eff0 (npc id)
    virtual Unk_PCBaseFxLib* vfunc_70();                    // 70  0x140a4f080
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85();          // 85  0x140a4f0b0 (lazy chat balloon)
    virtual int vfunc_116();                                // 116 0x140a4efd0 (return 1)
    // new slot 124: binds the npc row and the cube entity (ent is by value: the callee destroys it).
    virtual int vfunc_124(int nNpcId, egf::EntityPtr ent, int nGaugeA, int nGaugeB, const CStringW& strOwner);  // 0x140a4ed00

    MS2Ptr<NpcDataCli> GetNpc();                     // 0x140a4f1b0 copy of m_spNpc
    void FUN_140a4f200(void* p);                            // 0x140a4f200
    void FUN_140a4f230(int a, int b);                       // 0x140a4f230 gauge update
    void FUN_140a4f2b0(unsigned int nState);                // 0x140a4f2b0 play the state's animation
    void FUN_140a4f3f0(int n);                              // 0x140a4f3f0 say talk-script line n
    int FUN_140a4f690();                                    // 0x140a4f690 owned by someone else than "me" (BOOL)

public:
    MS2_LAYOUT_FRIEND;
    unsigned int m_nAnimState;                              // +0xd40
    void* m_pD48;                                           // +0xd48
    ATL::CAtlMap<unsigned int, CString> m_mapAnim;          // +0xd50 state -> animation name
    MS2Ptr<NpcDataCli> m_spNpc;                             // +0xd98
    egf::EntityPtr m_entity;                                 // +0xda8
    MS2Ptr<Unk_HpBarFx> m_spFx;                             // +0xdb0
    int m_nGaugeA;                                          // +0xdc0 = 300
    int m_nGaugeB;                                          // +0xdc4 = 500
    CStringW m_strOwner;                                    // +0xdc8
};
MS2_CHECK_SIZE(CubeSpawnObject, 0xdd0);
MS2_CHECK_OFFSET(CubeSpawnObject, m_nAnimState, 0xd40);
MS2_CHECK_OFFSET(CubeSpawnObject, m_mapAnim, 0xd50);
MS2_CHECK_OFFSET(CubeSpawnObject, m_spNpc, 0xd98);
MS2_CHECK_OFFSET(CubeSpawnObject, m_entity, 0xda8);
MS2_CHECK_OFFSET(CubeSpawnObject, m_spFx, 0xdb0);
MS2_CHECK_OFFSET(CubeSpawnObject, m_nGaugeA, 0xdc0);
MS2_CHECK_OFFSET(CubeSpawnObject, m_strOwner, 0xdc8);
