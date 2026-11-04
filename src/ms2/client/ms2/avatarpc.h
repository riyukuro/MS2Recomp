// avatarpc.h - AvatarPC (efd RTTI "AvatarPC", class id 0x06200044, size 0x1398), AvatarPet (0x0620006c, 0x1a8) and
// AvatarRidee (0x0620005e, 0x1c8): the avatar objects of the UI model views (character preview, pet / ridee shop
// preview). Owning unit: ?\avatarpc.cpp (0x1409f3370-0x1409faff0, plus 0x1400c2440-0x1400c28c0 .text$di). Header name
// assumed.
//
// AvatarPC : ClonePC (0x1340), IAvatarObjectEventListener (+0x1340, 5 slots: it listens to the preview objects it owns
// and re-applies their model to the model view). AvatarPet / AvatarRidee : CloneCube (0x1a0), their EE class chain skips
// CloneCube (ClassInfo parent GameObject, like AvatarCube).
// Heap-only. ClassInfo: AvatarPC 0x143ab4cb0 (setup 0x1409f7f60), AvatarPet 0x143ab5120 (0x1409f91d0), AvatarRidee
// 0x143ab55d0 (0x1409fae60). ctors: AvatarPC 0x1409f5890, AvatarPet 0x1409f8d30, AvatarRidee 0x1409fa1c0 / 0x1409fa300.
#pragma once
#include <efd/SmartPointer.h>
#include <NiNode.h>
#include <NiPoint3.h>
#include "ms2/client/ms2/clonepc.h"
#include "ms2/client/ms2/clonecube.h"
#include "ms2/placeholder/tcreatecharinfo.h"
#include "ms2/placeholder/crideedata.h"   // CRideeData (the riding row)

class CFishingGuideObject;   // cubecraft_1.h
class CSkillRecord;          // skillrecord.h
class StatePlayInstrumentData;
class Unk_PCActionTimer;

// ---- AvatarRidee --------------------------------------------------------------------------------------------------

class AvatarRidee : public CloneCube
{
    EE_DECLARE_CLASS1(AvatarRidee, 0x0620005e, GameObject);

public:
    AvatarRidee(MS2Ptr<CItemData> spData);                  // 0x1409fa1c0 (item model)
    AvatarRidee(MS2SvrPtr<CRideeData> spRow);               // 0x1409fa300 (ridee table row)
    virtual ~AvatarRidee();                                 // 0x1409f9530

    virtual void vfunc_9(void* p);                          // 9   0x1409f98b0
    virtual void vfunc_12();                                // 12  0x1409f98e0
    virtual void vfunc_13(void* a, efd::Category cat);      // 13  0x1409f9d50
    virtual void vfunc_53(float f);                         // 53  0x1409f9dc0
    virtual bool vfunc_57();                                // 57  0x1409f9e20
    virtual bool vfunc_58(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);   // 58 0x1409f9600
    virtual void vfunc_59(MS2Ptr<CItem> spItem);            // 59  0x1409fa4f0 requests the UGC ridee model

    void FUN_1409f9ea0(MS2SvrPtr<CRideeData> spRow);        // 0x1409f9ea0 applies a ridee row (model path, scale)
    void FUN_1409fa120(PCBase* pRider);                     // 0x1409fa120 sets the rider (+ its ride animation)
    MS2SvrPtr<CRideeData> GetRow();                  // 0x1409fa170 copy of m_spRow
    void FUN_1409fa7c0();                                   // 0x1409fa7c0 starts the rider's ride animation
    void FUN_1409fa940();                                   // 0x1409fa940 attaches the rider to the ridee
    bool FUN_1409faac0();                                   // 0x1409faac0 places the ridee in the preview (free id)

public:
    MS2_LAYOUT_FRIEND;
    int m_nEffect;                                          // +0x1a0 effect handle (1411a49c0 creates, 1411a6060 frees)
    MS2SvrPtr<CRideeData> m_spRow;                          // +0x1a8
    PCBase* m_pRider;                                       // +0x1b8 raw (no reference held)
    NiAVObjectPtr m_spAttach;                               // +0x1c0 the "seat" node of the model
};
MS2_CHECK_SIZE(AvatarRidee, 0x1c8);
MS2_CHECK_OFFSET(AvatarRidee, m_spRow, 0x1a8);
MS2_CHECK_OFFSET(AvatarRidee, m_pRider, 0x1b8);
MS2_CHECK_OFFSET(AvatarRidee, m_spAttach, 0x1c0);

// ---- AvatarPet ----------------------------------------------------------------------------------------------------

class AvatarPet : public CloneCube
{
    EE_DECLARE_CLASS1(AvatarPet, 0x0620006c, GameObject);

public:
    AvatarPet(CItemData* pData);                            // 0x1409f8d30
    virtual ~AvatarPet();                                   // 0x1409f8680

    virtual void vfunc_12();                                // 12  0x1409f8c00
    virtual bool vfunc_57();                                // 57  0x1409f86e0
    virtual void vfunc_62(MS2Ptr<CItemData> spData);        // 62  0x1409f8760 (new slot) sets the pet item

    void FUN_1409f8e10();                                   // 0x1409f8e10 starts the pet's idle effect
    void FUN_1409f9010();                                   // 0x1409f9010 stops it

public:
    MS2_LAYOUT_FRIEND;
    int m_nEffect;                                          // +0x1a0 effect handle
};
MS2_CHECK_SIZE(AvatarPet, 0x1a8);
MS2_CHECK_OFFSET(AvatarPet, m_nEffect, 0x1a0);

// ---- AvatarPC -----------------------------------------------------------------------------------------------------

class AvatarPC : public ClonePC, public IAvatarObjectEventListener
{
    EE_DECLARE_CLASS1(AvatarPC, 0x06200044, ClonePC);

public:
    AvatarPC(PC* pSource);                                  // 0x1409f5890
    virtual ~AvatarPC();                                    // 0x1409f3370

    virtual int vfunc_10();                                 // 10  0x1409f59f0
    virtual void vfunc_12();                                // 12  0x1409f5b70
    virtual void vfunc_14();                                // 14  0x1409f5090
    virtual void vfunc_53(float f);                         // 53  0x1409f5c00
    virtual int vfunc_58();                                 // 58  0x1409f5540 return 1
    virtual void vfunc_59(int nState, StateData* pData, int nSub, int bForce);   // 59  0x1409f5210
    virtual float vfunc_95();                               // 95  0x1409f5510
    virtual bool vfunc_102(MS2Ptr<CSkillRecord> skill);     // 102 0x1409f5340 plays the skill's state
    virtual void vfunc_127(CItem* pItem, int n);            // 127 0x1409f5150
    virtual void vfunc_128(CItem* pItem, int n);            // 128 0x1409f51d0
    virtual void vfunc_142();                               // 142 0x1409f52e0
    virtual void vfunc_147(UIModelView* pView);             // 147 0x1409f4fa0

    // IAvatarObjectEventListener (+0x1340): the ridee / pet model reached the view
    virtual int vfunc_0(GameObject* pObj);                  // 0x1409f6610
    virtual int vfunc_1(GameObject* pObj);                  // 0x1409f65c0
    virtual int vfunc_3(GameObject* pObj);                  // 0x1409f6660
    virtual int vfunc_4(GameObject* pObj);                  // 0x1409f6750

    // state / appearance helpers
    void FUN_1409f41d0(const Unk_CharEquip& kEquip0, const Unk_CharEquip& kEquip1);   // 0x1409f41d0 sets the two equip colours
    void FUN_1409f42a0(MS2Ptr<CItemData> spData);           // 0x1409f42a0 glide state of a glider item
    void FUN_1409f43d0(int nSkillId, short nLevel);         // 0x1409f43d0 plays a skill state
    void FUN_1409f45a0(MS2Ptr<CItemData> spData);           // 0x1409f45a0 play-instrument state
    void FUN_1409f4750(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);   // 0x1409f4750 shows / updates the ridee
    void FUN_1409f4ce0();                                   // 0x1409f4ce0 (empty)
    void FUN_1409f4cf0(unsigned a, unsigned b);             // 0x1409f4cf0 resets the state and calls 0x141663e20
    void FUN_1409f4d80(MS2Ptr<CItem> spItem);               // 0x1409f4d80 equips an item, per item kind
    bool FUN_1409f4f20();                                   // 0x1409f4f20 riding and the ridee model is loaded
    void SetListener(IAvatarObjectEventListener* p);      // 0x1409f5040 m_pListener = p
    IAvatarObjectEventListener* GetListener();            // 0x1409f5070
    void FUN_1409f5560(NiNodePtr spNode);                   // 0x1409f5560 adds a node under "UI External Root"
    void FUN_1409f5750(NiNodePtr spNode);                   // 0x1409f5750 removes it
    void FUN_1409f5830();                                   // 0x1409f5830 culls the external root
    void FUN_1409f5d20();                                   // 0x1409f5d20 hands the nodes of this avatar to the model view
    void SetType(int n);                              // 0x1409f6280 m_nType = n
    int GetType();                                    // 0x1409f62a0
    NiNode* FUN_1409f62c0();                                // 0x1409f62c0 the "UI Effect Root" (created on demand)
    int FUN_1409f6450();                                    // 0x1409f6450 object id of the ridee, or 0
    void FUN_1409f64a0();                                   // 0x1409f64a0 m_bDirty = true
    void FUN_1409f64c0(MS2Ptr<CItem> spItem);               // 0x1409f64c0 marks dirty when the item has a model
    void SetEnabled(bool b);                             // 0x1409f6540 m_bEnabled = b
    bool IsEnabled();                                   // 0x1409f6560
    bool IsFishing();                                   // 0x1409f65a0
    bool FUN_1409f67a0(NiNodePtr spNode);                   // 0x1409f67a0 attaches a UI node to the model root
    void FUN_1409f68e0(MS2Ptr<CItem> spItem);               // 0x1409f68e0 equip (kind 5)
    void FUN_1409f6950(MS2Ptr<CItem> spItem);               // 0x1409f6950 equip (kind 8: fishing rod)
    void FUN_1409f6db0(MS2Ptr<CItem> spItem);               // 0x1409f6db0 equip (kind 6)
    void FUN_1409f6e30();                                   // 0x1409f6e30 stops the timer and the fishing guide

public:
    MS2_LAYOUT_FRIEND;
    IAvatarObjectEventListener* m_pListener;                // +0x1348 the UI owner
    int m_nType;                                            // +0x1350
    NiNodePtr m_spExternalRoot;                             // +0x1358 "UI External Root"
    NiNodePtr m_spEffectRoot;                               // +0x1360 "UI Effect Root"
    efd::SmartPointer<AvatarRidee> m_spRidee;               // +0x1368
    efd::Point3 m_kPos;                                     // +0x1370
    efd::Point3 m_kDir;                                     // +0x137c
    bool m_bDirty;                                          // +0x1388 view must be rebuilt (vfunc_53)
    bool m_bEnabled;                                        // +0x1389 = 1
    bool m_bFishing;                                        // +0x138a
    int m_nTimer;                                           // +0x138c timer handle
    efd::SmartPointer<CFishingGuideObject> m_spFishing;     // +0x1390
};
MS2_CHECK_SIZE(AvatarPC, 0x1398);
MS2_CHECK_OFFSET(AvatarPC, m_pListener, 0x1348);
MS2_CHECK_OFFSET(AvatarPC, m_spExternalRoot, 0x1358);
MS2_CHECK_OFFSET(AvatarPC, m_spRidee, 0x1368);
MS2_CHECK_OFFSET(AvatarPC, m_kPos, 0x1370);
MS2_CHECK_OFFSET(AvatarPC, m_kDir, 0x137c);
MS2_CHECK_OFFSET(AvatarPC, m_bDirty, 0x1388);
MS2_CHECK_OFFSET(AvatarPC, m_nTimer, 0x138c);
MS2_CHECK_OFFSET(AvatarPC, m_spFishing, 0x1390);

// ---- free functions of the unit -------------------------------------------------------------------------------------

AvatarPC* FUN_1409f3410(PC* pSource);                       // 0x1409f3410 avatar mirroring pSource
AvatarPC* FUN_1409f3570(unsigned nType);                    // 0x1409f3570 empty avatar for a character type
AvatarPC* FUN_1409f3650(int nGender, int nPreset);          // 0x1409f3650 preview avatar with the default outfit
AvatarPC* FUN_1409f3fd0(MS2Ptr<Unk_PCArg125> spSrc);        // 0x1409f3fd0 avatar mirroring a pc record
unsigned int FUN_1409f6ee0();                               // 0x1409f6ee0 free avatar object id (0x3fb..0x40e)
AvatarPet* FUN_1409f8510(CItemData* pData);                //  0x1409f8510 pet preview object
unsigned int FUN_1409f9060();                               // 0x1409f9060 free pet preview id (0x426..0x42f)
AvatarRidee* FUN_1409f92d0(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);   // 0x1409f92d0 ridee preview (item)
AvatarRidee* FUN_1409f9430(MS2SvrPtr<CRideeData> spRow);    // 0x1409f9430 ridee preview (table row)
unsigned int FUN_1409faa70();                               // 0x1409faa70 free ridee preview id (0x41b..0x424)
