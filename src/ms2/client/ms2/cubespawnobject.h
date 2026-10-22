// cubespawnobject.h - CubeSpawnObject (efd RTTI "CubeSpawnObject", class id 0x06200080): an NPC-model actor
// spawned on a housing cube (pets/plants that grow, are fed and talk). Derives PCBase. Owning unit:
// ?\cubespawnobject.cpp (0x140a4e690-0x140a50440). Header name assumed.
#pragma once
#include "ms2/client/ms2/pcbase.h"

class Unk_NpcData;          // npc table row (MS2Ptr<T>, the table is FUN_1406d6e90()); see cubespawnobject.cpp
class Unk_HpBarFx;          // housing-object gauge effect (lookup FUN_1419936d0(id), removal FUN_141993750(id))
class Unk_Entity;           // egf entity behind the spawn's entity handle

// 8-byte entity handle (intrusive). ctor(0) 0x1408b6680, dtor 0x1408a8720.
struct Unk_EntRef
{
    Unk_EntRef(int nNull);                          // 0x1408b6680
    Unk_EntRef(const Unk_EntRef& o);                // user copy ctor: passed by pointer like the exe
    ~Unk_EntRef();                                  // 0x1408a8720
    Unk_EntRef& operator=(int nNull);               // 0x1408b6ec0
    Unk_EntRef& operator=(const Unk_EntRef& o);     // 0x140964eb0
    Unk_Entity* FUN_1408a9090() const;              // get
    Unk_EntRef& FUN_1408b6ec0(Unk_Entity* p);       // assign a raw entity pointer (same body as operator=(int))
    bool FUN_1408b70b0(Unk_Entity* p) const;        // operator==
    Unk_Entity* FUN_1408a9280() const;              // operator->
    Unk_EntRef(Unk_Entity* p);                      // 0x1408b6680 (same body as the null ctor; ridee.cpp)
    bool operator!=(Unk_Entity* p) const;           // 0x140965490 (ridee.cpp)
    void* m_p;
};
MS2_CHECK_SIZE(Unk_EntRef, 8);

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
    virtual int vfunc_124(int nNpcId, Unk_EntRef ent, int nGaugeA, int nGaugeB, const CStringW& strOwner);  // 0x140a4ed00

    MS2Ptr<Unk_NpcData> GetNpc();                    // 0x140a4f1b0 copy of m_spNpc
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
    MS2Ptr<Unk_NpcData> m_spNpc;                            // +0xd98
    Unk_EntRef m_entity;                                    // +0xda8
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
