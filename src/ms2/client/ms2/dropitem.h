// dropitem.h - CDropItem (efd RTTI "CDropItem", class id 0x06200011, 0x2a0 bytes, vftable 0x142eb89c8): the world object of an
// item or meso dropped on the field. It flies out of its source along an arc (state 1 / 0), waits to be picked up, bobs
// (state 0), and fades out (state 5); the current state is a pointer to a member function (+0x268) that vfunc_53 calls every
// frame. Owning unit: client\ms2\dropitem.cpp (0x14118c730-0x141192960 + .di 0x1400e7300-0x1400e74f0). Header name assumed
// from the unit path; member names are invented from their use.
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/arccontroller.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>

class CItem;
class ItemDropEffect;
class Unk_WsC_GameObj;

// The owner uid set of a drop (a hash set; ctor 0x1407b5060(p, 10), dtor 0x1407b5a30).
class Unk_DropOwners
{
public:
    Unk_DropOwners(int nBuckets);                                           // 0x1407b5060
    ~Unk_DropOwners();                                                      // 0x1407b5a30
    void FUN_1407b7110(const ATL::CAtlList<__int64>* pOwners);              // replace the content
    void FUN_1407b7090(const ATL::CAtlList<__int64>* pOwners);              // add to the content
    void* FUN_1407b72d0(unsigned __int64 nUid, void* pOut);                 // lookup (0 when absent)
    unsigned __int64 FUN_1408f32a0() const;                                 // count (GetCount)
    void* FUN_1407b75d0();                                                  // first position
    unsigned __int64* FUN_1408f31c0(void* pPos);                            // the uid at a position
private:
    unsigned char m_data[0x30];
};
MS2_CHECK_SIZE(Unk_DropOwners, 0x30);

// The item shown by a drop is created by name of its drop effect; MS2Ptr<ItemDropEffect> plus its +8 test helpers.
typedef MS2Ptr<ItemDropEffect> Unk_DropEffectPtr;

class CDropItem : public GameObject
{
    EE_DECLARE_CLASS1(CDropItem, 0x06200011, GameObject);

public:
    CDropItem(int nType, int nRarity);                                      // 0x14118c730
    virtual ~CDropItem();                                                   // 0x14118cac0, ??_G 0x141192710

    virtual void vfunc_9(void* p);                                          // 9  0x14118d430
    virtual int vfunc_10();                                                 // 10 0x14118d2a0
    virtual int vfunc_11();                                                 // 11 0x14118d3e0
    virtual void vfunc_12();                                                // 12 0x14118d410
    virtual void vfunc_32(bool b);                                          // 32 0x14118d4e0
    virtual void vfunc_47(bool b);                                          // 47 0x1411911d0
    virtual void vfunc_49();                                                // 49 0x141191350
    virtual void vfunc_53(float fTime);                                     // 53 0x1411914d0
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                     // 0x14118d700

    int FUN_14118cb90(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId);                 // build the item and its model
    int FUN_14118d1c0(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId, const ATL::CAtlList<__int64>& kOwners);   // set the owners, init
    int FUN_14118d230(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId, const ATL::CAtlList<__int64>* pOwners);   // add the owners, init
    void FUN_14118d720(NiAVObject* pRoot);                                      // the "Item_Icon:0" texture of the item
    void FUN_14118d9a0(int nState);                                         // enter a state
    void FUN_14118fe60(int nValue);                                         // 0x14118fe60 m_n28c
    void FUN_14118fe80(int nValue);                                         // 0x14118fe80 m_n298
    int FUN_14118fea0();                                                    // +0x150 > 0 (a meso drop)
    int FUN_14118fee0();                                                   // 0x14118fee0
    int FUN_14118ff10();                                                    // the item is type 0x55d4a8a
    int FUN_14118ff60();                                                    // the item is type 0x55d4a83
    int FUN_14118ffb0();                                                    // the item is a valid gem item
    int FUN_141190030();                                                    // the local player owns it
    int FUN_141190080(unsigned __int64 nUid);                               // nUid is an owner
    int FUN_1411900d0();                                                    // owner id and state both set
    int FUN_141190120(const efd::Point3& kPos, int nA, int nB);             // can pick up from kPos
    int FUN_141190320(GameObject* pActor, int nA, int nB);                 // can pick up with range m_f21c
    int FUN_141190370(GameObject* pActor, int nA, int nB);                 // can pick up with range m_f220
    int FUN_1411903c0(GameObject* pActor, float fRange, int nA, int nB);    // can pick up within fRange
    int FUN_1411905a0();                                                    // the local player may pick it up
    int FUN_141190640(bool bForce);                                         // the pickup setting allows it
    int FUN_1411906a0();                                                    // the inventory can take the item
    void SendRequestItemPickup(int nPickerId);                                      // send the pickup packet
    void FUN_141190900(int nPickerId);                                      // try to pick up
    void FUN_141190b70(int nPickerId);                                      // picked up by an actor
    void FUN_141191030();                                                   // m_nTick = now
    bool FUN_141191060();                                                   // 1000 ms since m_nTick
    int GetOwnerObjId();                                                    // m_nOwnerObjId
    int GetDropKind();                                                    // m_nDropKind
    unsigned __int64 FUN_1411910e0();                                       // the first owner uid
    int FUN_141191150();                                                    // state is 1 or 6
    void FUN_1411911a0();                                                   // enter state 5
    void FUN_1411911f0();                                                   // "Item_Icon:0" of the model
    void FUN_141191240();                                                   // read the drop settings
    void FUN_141191330(int nValue);                                         // 0x141191330 m_n278
    void FUN_141191780(double fTime, GameObject* pTarget);                  // state 1: fly out
    void FUN_141191a10(double fTime, GameObject* pTarget);                  // state 0: bob
    void FUN_141191d10(double fTime, GameObject* pTarget);                  // state 2: fly to the owner
    void FUN_1411920b0(double fTime, GameObject* pTarget);                  // state 3
    void FUN_141192200(double fTime, GameObject* pTarget);                  // state 4
    void FUN_1411923a0(double fTime, GameObject* pTarget);                  // state 5: grow in
    void FUN_1411925e0(efd::Point3 kAxis, float fDegrees);           // spin the model
    void FUN_141192840(int nValue);                                         // 0x141192840 m_n294

    CItem* FUN_140b12380();                                                 // the dropped item

public:
    MS2_LAYOUT_FRIEND;
    int m_nAmount;                      // +0x140
    float m_fElapsed;                   // +0x144 time in the state
    float m_fSpawnTime;                 // +0x148
    __int64 m_n64Meso;                  // +0x150 the meso amount of a meso drop
    Unk_DropOwners m_owners;            // +0x158
    int m_n188;                         // +0x188
    int m_nOwnerObjId;                  // +0x18c
    int m_nNpcType;                     // +0x190
    int m_nEffectIdA;                   // +0x194 the effect (sound) played while falling
    int m_nEffectIdB;                   // +0x198
    int m_nState;                       // +0x19c 6 = just created
    MS2Ptr<CItem> m_spItem;             // +0x1a0
    NiPoint3 m_posGround;               // +0x1b0
    Unk_ArcFlight m_arc;                // +0x1bc
    efd::utf8string m_strAnim;          // +0x1f8
    float m_f218;                       // +0x218 settings 0x5a18
    float m_f21c;                       // +0x21c pickup range
    float m_f220;                       // +0x220
    float m_f224;                       // +0x224
    float m_f228;                       // +0x228
    float m_f22c;                       // +0x22c
    float m_f230;                       // +0x230
    float m_fGrow;                      // +0x234
    Vector3 m_posGrow;          // +0x238
    int m_nOwnerType;                   // +0x244 0 / 1 = owners only, 2 = anyone
    int m_nDropKind;                    // +0x248
    int m_n24c;                         // +0x24c
    MS2Ptr<ItemDropEffect> m_spEffect;  // +0x250
    unsigned int m_nTick;               // +0x260
    int m_n264;                         // +0x264
    void (CDropItem::*m_pfnState)(double fTime, GameObject* pTarget);  // +0x268 the state update
    int m_n278;                         // +0x278
    float m_f27c;                       // +0x27c
    Vector3 m_posOrigin;        // +0x280
    int m_n28c;                         // +0x28c
    unsigned int m_nFadeTime;           // +0x290
    int m_n294;                         // +0x294
    int m_n298;                         // +0x298
    int m_n29c;                         // +0x29c
};
MS2_CHECK_SIZE(CDropItem, 0x2a0);
