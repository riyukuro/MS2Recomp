// mouseinteract.h - CMouseInteract, the "what is under the mouse cursor and how do I interact with it" strategy
// family. Each subclass knows how to pick a world object with the cursor ray (vfunc_1 / vfunc_2), whether the
// local player's current action still matches that object (vfunc_3), and which cursor / tooltip string to show.
// Owning unit: ?\mouseinteract.cpp (0x140a78f70-0x140a7bb20). Header name assumed from the unit path; class names
// are real (RTTI). Vftables: CMouseInteract 0x142dcc790, DynamicModel 0x142dcc7d0, Taxi 0x142dcc810,
// UgcBanner 0x142dcc850; Npc 0x142dd45f8, Portal 0x142dd4638, Object 0x142dd4678, TalkCancel 0x142dd46b8,
// WeaponObject 0x142dd46f8 (their ctors / vfunc_6 / scalar deleting dtors live in a later unit).
#pragma once
#include <atlstr.h>
#include "ms2/placeholder/cptred.h"

struct Unk_Vec3 { float x, y, z; };

// The ray the cursor casts plus the result slots the picker fills in (proven offsets only).
struct Unk_MouseRay
{
    Unk_Vec3 vOrigin;           // +0x00 ray start
    Unk_Vec3 vEnd;              // +0x0c ray end
    Unk_Vec3 vPick;             // +0x18 position of the picked object
    int m_pad_24;
    CStringW strCursor;         // +0x28 cursor / hint string id of the picked object
};

// +0x18 is the first member of every subclass; the base has none.
class CMouseInteract : public CPtred
{
public:
    CMouseInteract();                                   // 0x140a78f70
    virtual ~CMouseInteract();                          // 0x140a78fb0 (deleting 0x140a7b6b0)
    virtual int vfunc_1(Unk_MouseRay* pRay);           // 0x140a78fe0 pick + fill cursor string
    virtual int vfunc_2(Unk_MouseRay* pRay);           // 0x140a79000 pick only
    virtual int vfunc_3();                             // 0x140a79020 does the player's current action match
    virtual int vfunc_4();                             // 0x140a79030 cancel the current action
    virtual void vfunc_5();                             // 0x140a79080 reset the remembered target
    virtual int vfunc_6();                              // 0x140a7b8a0 cursor kind
};

class PCBase;
class CMouseInteractNpc : public CMouseInteract
{
public:
    virtual ~CMouseInteractNpc();
    virtual int vfunc_1(Unk_MouseRay* pRay);           // 0x140a79090
    virtual int vfunc_2(Unk_MouseRay* pRay);           // 0x140a79340
    virtual int vfunc_3();                             // 0x140a79400
    virtual void vfunc_5();                             // 0x140a79550
    virtual int vfunc_6();
    PCBase* FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd);   // 0x140a79580
    int m_nAction;                                      // +0x18 6 = hold, 0x14 = talk, 0x1e = none
    int m_nNpcId;                                       // +0x1c
};

class CMouseInteractPortal : public CMouseInteract
{
public:
    virtual ~CMouseInteractPortal();
    virtual int vfunc_1(Unk_MouseRay* pRay);           // 0x140a79a00
    virtual int vfunc_2(Unk_MouseRay* pRay);           // 0x140a79c00
    virtual int vfunc_3();                             // 0x140a79cd0
    virtual void vfunc_5();                             // 0x140a79d90
    virtual int vfunc_6();
    struct Unk_PortalHit* FindTarget(struct Unk_PortalHit* pOut, const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd);   // 0x140a79db0
    int m_nPortalId;                                    // +0x18
};

class CMouseInteractObject : public CMouseInteract
{
public:
    virtual ~CMouseInteractObject();
    virtual int vfunc_1(Unk_MouseRay* pRay);           // 0x140a7a0c0
    virtual int vfunc_2(Unk_MouseRay* pRay);           // 0x140a7a250
    virtual int vfunc_3();                             // 0x140a7a3d0
    virtual void vfunc_5();                             // 0x140a7a4a0
    virtual int vfunc_6();
    struct Unk_ObjectHit* FindTarget(struct Unk_ObjectHit* pOut, const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd);   // 0x140a7a4e0
    int m_nAction;                                      // +0x18
    CStringA m_strObjectId;                             // +0x20
};

// Taxi / UGC banner share the dynamic-model picker; they only differ in the three constants set by the ctor.
class CMouseInteractDynamicModel : public CMouseInteract
{
public:
    CMouseInteractDynamicModel();                       // 0x140a7b4b0
    virtual ~CMouseInteractDynamicModel() = default;    // 0x140a7b570 (deleting 0x140a7b6f0)
    virtual int vfunc_1(Unk_MouseRay* pRay);           // 0x140a7a780
    virtual int vfunc_2(Unk_MouseRay* pRay);           // 0x140a7a810
    virtual int vfunc_3();                             // 0x140a7a880
    virtual int vfunc_6();                              // 0x140a7b8b0
    void* FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd);   // 0x140a7a8e0
    unsigned m_dwModelKey;                              // +0x18
    float m_fPickSize;                                  // +0x1c
    int m_nAction;                                      // +0x20
    CStringW m_strCursor;                               // +0x28
};

class CMouseInteractTaxi : public CMouseInteractDynamicModel
{
public:
    CMouseInteractTaxi();                               // 0x140a7aad0
    virtual ~CMouseInteractTaxi() = default;            // 0x140a7b5a0 (deleting 0x140a7b730)
    virtual int vfunc_6();                              // 0x140a7b8c0
};

class CMouseInteractUgcBanner : public CMouseInteractDynamicModel
{
public:
    CMouseInteractUgcBanner();                          // 0x140a7ab50
    virtual ~CMouseInteractUgcBanner() = default;       // 0x140a7b5c0 (deleting 0x140a7b770)
    virtual int vfunc_6();                              // 0x140a7b8d0
};

class CMouseInteractTalkCancel : public CMouseInteract
{
public:
    virtual ~CMouseInteractTalkCancel();
    virtual int vfunc_1(Unk_MouseRay* pRay);           // 0x140a7abd0
    virtual int vfunc_2(Unk_MouseRay* pRay);           // 0x140a7ac80
    virtual int vfunc_3();                             // 0x140a7ad30
    virtual int vfunc_4();                             // 0x140a7ad50
    virtual int vfunc_6();
};

class CMouseInteractWeaponObject : public CMouseInteract
{
public:
    virtual ~CMouseInteractWeaponObject();
    virtual int vfunc_1(Unk_MouseRay* pRay);           // 0x140a7ad80
    virtual int vfunc_2(Unk_MouseRay* pRay);           // 0x140a7ae80
    virtual int vfunc_3();                             // 0x140a7af50
    virtual int vfunc_6();
    struct Unk_WeaponHit* FindTarget(struct Unk_WeaponHit* pOut, const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd);   // 0x140a7b040
    unsigned long long m_qwObjectId;                    // +0x18
};
