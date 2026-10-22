// gameobject.h - GameObject (efd RTTI "GameObject", class id 0x06200002): root of the client's world actors
// (PCBase -> CNpc/PC/MyPC/Ridee/CubeSpawnObject ...). Owning unit: client\ms2\gameobject.cpp
// (0x14123b2b0-0x14123f2d0). Header path/name assumed from the unit path.
//
// HOW TO USE THIS HEADER (for unit workers):
// - Derive with `class X : public GameObject` (or from PCBase, see pcbase.h). Keep EE_DECLARE_CLASS1 /
//   refcount macros in sync with the exe: derived classes use EE_DECLARE_CLASS1(X, <id>, GameObject) and do NOT
//   redeclare the refcount (it lives here at +0x10).
// - Virtual names are vfunc_N = slot N of the primary vftable 0x142ec6070 (57 slots). Override by declaring the
//   same signature. Params typed void* are pointers whose type is not yet proven; replace them here (shared header,
//   keep the slot order) once you prove them, and tell the coordinator.
// - Functions returning NiPoint3 use the hidden return pointer (RDX), as in the exe.
// - vfunc_24/25/45 are inline here because their only COMDAT bodies live in another unit (0x1409f2xxx, avatarcube);
//   do not move them into a .cpp.
// - Members with unproven types are size-correct pointer-aligned stand-ins (m_unk_XX). GameObject is heap-only (never a local),
//   so array stand-ins do not disturb frame layout.
// - efd::IBase derives efd::MemObject, so plain `new X` needs EE_NEW / the efd allocator overloads (or ::new).
#pragma once
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <afx.h>
#include <efd/IBase.h>
#include <efd/RefCount.h>
#include <egf/EntityID.h>
#include <efd/Category.h>
#include <NiPoint3.h>
#include <NiActorManager.h>
#include <efd/SmartPointer.h>
#include <atlcoll.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>

class CAnimationManager;   // 0xa0 bytes, ctor(GameObject*); held at +0x48 (animationmanager.h)
class CObjectShadow;      // +0x58 (efd::SmartPointer)
class CMeshUpdateGate;    // +0x130 (unnamed/unit_14176f2a0.h)
class Unk_GoField;        // +0x60 the field object the position was last resolved in (gameobject.cpp)
class Unk_GoAnchorPtr;    // vfunc_27: 16-byte ref-counted anchor handle (gameobject.cpp)
class Unk_GoAttachment;   // vfunc_26: object placed at the actor each frame (gameobject.cpp)
namespace egf { class Entity; }

// 16-byte key that names a GameObject's model in the model cache (plain data; 0x14123c460 fills it). w17/effectobject.
struct Unk_GoModelKey
{
    void* m_pad_00;
    void* m_pad_08;
};

// 0x140 bytes. Bases: efd::IBase @0 (vftable 0x142ec6070, 57 slots), NiActorManager::CallbackObject @8
// (vftable 0x142ec6240: dtor thunk 0x14123ed80, AnimActivated 0x14123d5a0, AnimDeactivated 0x14123d5c0,
// AnimCompleted 0x14123d5e0, TextKeyEvent 0x14123d600, EndOfSequence 0x14123d620).
// Slots 0-7 = efd::IBase (DeleteThis 0x1409f2f00, IncRefCount 0x1409f2fe0, DecRefCount 0x1409f2ec0,
// GetRefCount 0x1409f2fc0, TypeCast 0x14123efa0/0x14123ef50, GetClassDesc 0x14123ee30, GetClassID 0x1409f2f80),
// slot 8 = ??_G 0x14123edd0. ClassInfo object 0x143ad4cb0.
class GameObject : public efd::IBase, public NiActorManager::CallbackObject
{
    EE_DECLARE_CLASS1(GameObject, 0x06200002, efd::IBase);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;   // +0x10

public:
    GameObject();                                           // 0x14123b2b0
    virtual ~GameObject();                                  // 0x14123b770

    // NiActorManager::CallbackObject
    virtual void AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14123d5a0
    virtual void AnimDeactivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14123d5c0
    virtual void AnimCompleted(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14123d5e0
    virtual void TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14123d600
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                                                // 0x14123d620

    // primary vftable, slots 9..56
    virtual void vfunc_9(void* p);                          // 9  0x14123b8d0
    virtual int vfunc_10();                                 // 10 0x14123b970
    virtual int vfunc_11();                                 // 11 0x14123b9b0
    virtual void vfunc_12();                                // 12 0x14123b9d0
    virtual void vfunc_13(void* a, efd::Category cat);      // 13 0x14123b9f0 (cat by value: copy 0x1409fabb0, dtor 0x1409fabe0; sb4)
    virtual void vfunc_14();                                // 14 0x14123ba60
    virtual void vfunc_15();                                // 15 0x14123bb10
    virtual void vfunc_16();                                // 16 0x14123bb20
    virtual NiPoint3 vfunc_17();                            // 17 0x14123bec0
    virtual NiPoint3 vfunc_18();                            // 18 0x14123c120 returns m_pos28
    virtual void vfunc_19(efd::Point3 kPos);                // 19 0x14123c150 (by value)
    virtual NiPoint3 vfunc_20();                            // 20 0x14123c1c0 returns m_pos34
    virtual void vfunc_21(efd::Point3 kDir);                // 21 0x14123c1f0 (by value)
    virtual void vfunc_22(const efd::Point3& kPos);         // 22 0x14123c3a0 m_pos98 = kPos
    virtual void vfunc_23(int n);                           // 23 0x14123c5c0
    virtual void vfunc_24(int) {}                           // 24 0x1409f3020 (inline, COMDAT in avatarcube)
    virtual int vfunc_25() { return m_unk_40; }             // 25 0x1409f2fb0 (inline)
    virtual Unk_GoAttachment* vfunc_26();                   // 26 0x14123c740 (0 here)
    virtual void vfunc_27(ATL::CAtlArray<Unk_GoAnchorPtr>& kArr);     // 27 0x14123c750 (collect anchor handles; empty here)
    virtual void vfunc_28(void* p);                         // 28 0x14123c770
    virtual int vfunc_29(GameObject* pTarget, efd::Point3* pOut);   // 29 0x14123c790 anchor nearest to pTarget
    virtual NiPoint3 vfunc_30(GameObject* pTarget);         // 30 0x14123c9f0
    virtual void vfunc_31(bool b);                          // 31 0x14123cad0
    virtual void vfunc_32(bool b);                          // 32 0x14123cb90
    virtual void vfunc_33(void* a, void* b);                // 33 0x14123cf10
    virtual void vfunc_34(void* p);                         // 34 0x14123cfb0
    virtual void vfunc_35(void* p);                         // 35 0x14123d040
    virtual int vfunc_36(void* pStr, void* b);              // 36 0x14123d0e0 (a = CString*)
    virtual NiPoint3 vfunc_37();                            // 37 0x14123d220
    virtual NiPoint3 vfunc_38(const efd::Point3& kDir, const efd::Point3& kPos, float fRange);   // 38 0x14123d250 pick
    virtual void vfunc_39();                                // 39 0x14123d640
    virtual void vfunc_40(float a, float b, float c, float d);   // 40 0x14123d650 (4th float on the stack)
    virtual void vfunc_41(NiAVObject* pNode, float f, bool b);   // 41 0x14123d750
    virtual void vfunc_42(float f, bool b);                 // 42 0x14123d6f0
    virtual void vfunc_43(float f);                         // 43 0x14123d9c0
    virtual void vfunc_44(void* p);                         // 44 0x14123d9f0
    virtual void vfunc_45(float f) { m_unk_c4 = f; }        // 45 0x1409f3000 (inline)
    virtual float vfunc_46(const efd::Point3& kPos);        // 46 0x14123da30 m_unk_c4 = distance to kPos
    virtual void vfunc_47(bool b);                          // 47 0x14123db10
    virtual int vfunc_48();                                 // 48 0x14123dc10
    virtual void vfunc_49();                                // 49 0x14123dd00
    virtual void vfunc_50();                                // 50 0x14123dd10
    virtual void vfunc_51(efd::Point3* pOffset);            // 51 0x14123de70 (0, 0, m_unk_108)
    virtual void vfunc_52(double fTime);                    // 52 0x14123dec0 (update)
    virtual void vfunc_53(float f);                         // 53 0x14123e1a0
    virtual void vfunc_54(float f);                         // 54 0x14123e220
    virtual bool vfunc_55(float a, float b);                // 55 0x14123e450
    virtual bool vfunc_56(float f);                         // 56 0x14123e3f0

    // non-virtual
    void FUN_14123bb80(CString str);                        // 0x14123bb80 m_str90 = str (model path, by value)
    void FUN_14123c280(float f);                            // 0x14123c280 m_fScaleA4 = f (+ entity scale prop)
    int FUN_14123c580();                                    // 0x14123c580 return m_unk_70 (object id)
    int FUN_14123dbd0();                                    // 0x14123dbd0 return m_unk_c8
    void SetScaleAC(float f);                            // scale B (+0xa8)
    int FUN_14123c660();                                    // visibility (+0xb0)
    void FUN_14123c5a0(int nId);                            // 0x14123c5a0 m_unk_70 = nId (w17)
    Unk_GoModelKey& FUN_14123c460(Unk_GoModelKey& kOut);    // 0x14123c460 fills kOut, returns it (w17)
    egf::EntityID FUN_14123c460();                          // 0x14123c460 (definition; same ABI as the two out-param views)
    egf::EntityID& FUN_14123c460(egf::EntityID& kOut);      // same function: the key is the entity id (w18, animationmanager)
    MS2Ptr<CAnimationManager> GetAnimMgr();              // 0x14123c6f0 copy of m_spAnimMgr (w17)
    CString FUN_14123bbd0();                                // 0x14123bbd0 copy of m_str90 (model path; sb4)
    void FUN_14123bc20(CString str);                        // 0x14123bc20 reload the model from str (by value; sb4)
    int FUN_14123bea0();                                    // 0x14123bea0 return m_unk_b4 (model loaded; sb4)
    egf::Entity* FUN_14123c410();                           // 0x14123c410 return m_unk_80 (the entity; sb4)
    void FUN_14123bb30(float f);                            // 0x14123bb30 if loaded: vfunc_53(f)
    CString FUN_14123be50();                                // 0x14123be50 copy of m_str88
    float FUN_14123c260();                                  // 0x14123c260 m_fScaleA4
    float GetScaleAC();                                  // 0x14123c2e0 m_fScaleAC
    void FUN_14123c330(float f);                            // 0x14123c330 m_fScaleA8 = f
    NiPoint3 FUN_14123c360();                               // 0x14123c360 m_pos98
    void SetKEntityID(const egf::EntityID& kId);           // 0x14123c3e0 m_kEntityID = kId
    void FUN_14123c430(void* pEntity);                      // 0x14123c430 m_unk_80 = pEntity
    unsigned __int64 FUN_14123c500();                       // 0x14123c500 entity id value
    void FUN_14123c680(bool b);                             // 0x14123c680 join/leave the update list
    void FUN_14123cb20(bool b);                             // 0x14123cb20 shadow
    efd::Point3 FUN_14123cc20();                             // 0x14123cc20 facing direction of vfunc_20()
    static efd::Point3 FUN_14123cc80(NiPoint3 kRot);         // 0x14123cc80 rotation (degrees) -> direction
    static float FUN_14123cd50(efd::Point3 kDir);           // 0x14123cd50 direction -> z angle (degrees)
    static float FUN_14123ce70(efd::Point3 kDir);           // 0x14123ce70 direction -> -radians
    unsigned __int64 FUN_14123cec0();                       // 0x14123cec0 (m_unk_70 << 32) | serial
    void FUN_14123d7a0(CString strKey, int nValue);         // 0x14123d7a0
    int FUN_14123d870();                                    // 0x14123d870 first non-zero value of m_mapD8
    void FUN_14123d900();                                   // 0x14123d900
    float FUN_14123daa0(const efd::Point3& kPos);           // 0x14123daa0 m_unk_bc = distance
    float FUN_14123db60(const efd::Point3& kPos);           // 0x14123db60 m_unk_c0 = distance
    int FUN_14123dbf0();                                    // 0x14123dbf0 m_unk_cc
    int FUN_14123dc30(unsigned int nKey);                   // 0x14123dc30 m_map120 lookup (0 when absent)
    void FUN_14123dcb0(unsigned int nKey, int nValue);      // 0x14123dcb0
    void FUN_14123e020(NiAVObject* pNode);                  // 0x14123e020 tag meshes with the alpha extra data
    float FUN_140a17da0();                                  // 0x140a17da0 m_fUnk110 (header inline; body in ?\bgtransparencymgr.cpp)
    float FUN_140a17dc0();                                  // 0x140a17dc0 m_fUnk114 (header inline; body in ?\bgtransparencymgr.cpp)
    void FUN_14123e350();                                   // 0x14123e350 push m_pos28 to the entity
    void FUN_14123e3a0();                                   // 0x14123e3a0 push m_pos34 to the entity
    float FUN_14123ee40() { return m_unk_c4; }              // 0x14123ee40 (COMDAT)
    float FUN_140f4a450();                                  // 0x140f4a450 (another unit)

public:
    MS2_LAYOUT_FRIEND;
    // +0x10 m_RefCount (macro above), +0x14 pad
    double m_unk_18;                    // +0x18 creation time (worldservice_1.cpp)
    double m_dUnk20;                    // +0x20 = 0.5
    efd::Point3 m_pos28;                // +0x28 = (FLT_MAX x3), returned by vfunc_18
    efd::Point3 m_pos34;                // +0x34 = (FLT_MAX x3), returned by vfunc_20
    int m_unk_40;                       // +0x40 returned by vfunc_25
    MS2Ptr<CAnimationManager> m_spAnimMgr;   // +0x48 (init 0x14123eb30, assign 0x14123ec40)
    efd::SmartPointer<CObjectShadow> m_spShadow;   // +0x58 (init 0x14123ea80(p,0), dtor 0x14123ebb0)
    MS2Ptr<Unk_GoField> m_spField;      // +0x60 (init 0x14123eb50, dtor 0x14123ebe0)
    int m_unk_70;                       // +0x70
    union
    {
        egf::EntityID m_kEntityID;      // +0x78 = kENTITY_INVALID (0x143ad4c70)
        void* m_unk_78;                 // raw view (worldservice_1.cpp)
    };
    void* m_unk_80;                     // +0x80
    CString m_str88;                    // +0x88
    CString m_str90;                    // +0x90
    NiPoint3 m_pos98;                   // +0x98 = NiPoint3::ZERO (0x143b01a60)
    float m_fScaleA4;                   // +0xa4 = 1.0
    float m_fScaleA8;                   // +0xa8 = 1.0
    float m_fScaleAC;                   // +0xac = 1.0
    int m_unk_b0;                       // +0xb0
    int m_unk_b4;                       // +0xb4
    bool m_bUnkB8;                      // +0xb8 = 1
    float m_unk_bc;                     // +0xbc (FUN_14123daa0)
    float m_unk_c0;                     // +0xc0 (FUN_14123db60)
    float m_unk_c4;                     // +0xc4 set by vfunc_45
    int m_unk_c8;                       // +0xc8
    int m_unk_cc;                       // +0xcc
    int m_unk_d0;                       // +0xd0
    ATL::CRBMap<CString, int> m_mapD8;  // +0xd8 (ctor 0x141205140(p,10), dtor 0x141205470)
    float m_unk_108;                    // +0x108
    bool m_bUnk10C;                     // +0x10c
    float m_fUnk110;                    // +0x110 = 20.0
    float m_fUnk114;                    // +0x114 = 100.0
    int m_unk_118;                      // +0x118
    int m_unk_11c;                      // +0x11c
    std::map<unsigned int, int> m_map120;   // +0x120 (ctor 0x140a41e00, dtor 0x140a41ed0)
    CMeshUpdateGate* m_pUnk130;         // +0x130 new 0x18 (ctor 0x14176f2a0), deleted via 0x14123ed90(p,1)
    bool m_bUnk138;                     // +0x138 = 1 (tested by vfunc_55)
};
MS2_CHECK_SIZE(GameObject, 0x140);
MS2_CHECK_OFFSET(GameObject, m_unk_18, 0x18);
MS2_CHECK_OFFSET(GameObject, m_pos28, 0x28);
MS2_CHECK_OFFSET(GameObject, m_unk_40, 0x40);
MS2_CHECK_OFFSET(GameObject, m_spAnimMgr, 0x48);
MS2_CHECK_OFFSET(GameObject, m_unk_80, 0x80);
MS2_CHECK_OFFSET(GameObject, m_str88, 0x88);
MS2_CHECK_OFFSET(GameObject, m_pos98, 0x98);
MS2_CHECK_OFFSET(GameObject, m_unk_c4, 0xc4);
MS2_CHECK_OFFSET(GameObject, m_mapD8, 0xd8);
MS2_CHECK_OFFSET(GameObject, m_kEntityID, 0x78);
MS2_CHECK_OFFSET(GameObject, m_unk_108, 0x108);
MS2_CHECK_OFFSET(GameObject, m_map120, 0x120);
MS2_CHECK_OFFSET(GameObject, m_pUnk130, 0x130);
MS2_CHECK_OFFSET(GameObject, m_bUnk138, 0x138);
