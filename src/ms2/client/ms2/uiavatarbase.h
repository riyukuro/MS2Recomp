// uiavatarbase.h - UIAvatarBase and its subclasses (RTTI .?AVUIAvatarBase@@ and friends): the UI-side owners of the
// avatar preview objects (an AvatarPC / AvatarCube / AvatarPet / AvatarRidee GameObject shown in a UIModelView), plus
// the equip package CAvatarPackageEquip that UIAvatarPC keeps per equip set. Unit `?\uiavatarbase.cpp`
// (.text$mn 0x1418b7a10-0x1418c34c0, .text$di 0x14010fe10-0x140110080); the header name is assumed and every member
// name except the RTTI class names and the vftable slots is invented from its use.
//
// UIAvatarBase (0xc0) = CPtred (0x18) + IAvatarObjectEventListener (+0x18, the secondary base that the avatar object
// calls back into; its slots 0 and 2..4 are overridden here, the listener bodies get this = +0x18) + the view state.
//   UIAvatarPC    0xf0  m_nKind 1  the character avatar (customize, equip package map)
//   UIAvatarCube  0xc8  m_nKind 2  a cube / furnishing item (raw CItemData*)
//   UIAvatarRidee 0xd8  m_nKind 3  a ridee (raw item data or a ridee table row)
//   UIAvatarPet   0xc8  m_nKind 4  a pet (raw CItemData*)
// Scalar deleting dtors: base 0x1418c1900, Cube 0x1418c1940, PC 0x1418c1980, Pet 0x1418c19c0, Ridee 0x1418c1a00.
#pragma once

#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/client/ms2/clonecube.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/uiskillpreviewdialog.h"

#include <efd/SmartPointer.h>
#include <atlcoll.h>

class UIRenderView;
class Customize;
class CAvatarPackageEquip;
class CItem;
class CItemData;
class AvatarCube;
class AvatarRidee;
class AvatarPet;
class Unk_UISwfEntity_25;
class ASObj;
enum Unk_InventoryEquipSlot : int;     // inventory.h
namespace ItemPreviewCommon { class CLimitCharRotate; }

// The key of the per-equip-set map in UIAvatarPC: (set kind, item uid). Ordered by kind, then uid (0x1418bfff0).
typedef std::pair<unsigned int, unsigned __int64> Unk_AvPackageKey;

// The equip package of one equip set: the equipped items by slot (0x60).
class CAvatarPackageEquip : public CPtred
{
public:
    CAvatarPackageEquip();                                          // 0x1418bf910
    virtual ~CAvatarPackageEquip();                                 // 0x1418c1410 (scalar deleting 0x1418c18c0)

    void FUN_1418bf980();                                           // 0x1418bf980 clears the slots
    void FUN_1418bf9b0(Unk_InventoryEquipSlot nSlot, MS2Ptr<CItem> spItem);   // 0x1418bf9b0 sets a slot
    bool FUN_1418bfa00(class UIAvatarPC* pOwner);                   // 0x1418bfa00 equips every item on the customize
    bool FUN_1418bfb00(class UIAvatarPC* pOwner);                   // 0x1418bfb00 equips every item on the avatar
    MS2Ptr<CItem> FUN_1418bfc00(Unk_InventoryEquipSlot nSlot);                // 0x1418bfc00 the item of a slot (null if none)
    bool FUN_1418bfcc0();                                           // 0x1418bfcc0 no slot is set

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<Unk_InventoryEquipSlot, MS2Ptr<CItem> > m_mapItems;          // +0x18
};
MS2_CHECK_SIZE(CAvatarPackageEquip, 0x60);

class UIAvatarBase : public CPtred, public IAvatarObjectEventListener
{
    MS2_LAYOUT_FRIEND;

public:
    UIAvatarBase();                                         // 0x1418b7a10
    virtual ~UIAvatarBase();                                // 0x1418b7c00 (scalar deleting 0x1418c1900)

    virtual void vfunc_1(IUIAvatarEventListener* pListener);                    // 1  0x1418b7cd0
    virtual void vfunc_2();                                 // 2  0x1418b7d00 (empty)
    virtual void vfunc_3();                                 // 3  0x1418b7d10 (empty)
    virtual void vfunc_4(__int64 nItemUid);                 // 4  0x1418b7d20 (empty)
    virtual void vfunc_5();                                 // 5  0x1418b7d40 zoom in
    virtual void vfunc_6();                                 // 6  0x1418b7db0 zoom out
    virtual void vfunc_7(float f);                            // 7  0x1418b7e20
    virtual void vfunc_8(float f);                            // 8  0x1418b7e90
    virtual void vfunc_9(float x, float y, float z, int bUpdate);               // 9  0x1418b9140 sets the translation
    virtual void vfunc_10(int dx, int dy, int dz, int bUpdate);                 // 10 0x1418b7f00 drags the object
    virtual void vfunc_11(int dx, int dy, int dz, int bUpdate);                 // 11 0x1418b8300 drags the camera
    virtual void vfunc_12(const Unk_StreamPoint& kDelta, Unk_StreamPoint& kRot);    // 12 0x1418b84c0 limits the rotation
    virtual void vfunc_13(float rx, float ry, float rz, const Unk_StreamPoint* pPivot,
                          const Unk_StreamPoint* pPos, int bUpdate);            // 13 0x1418b8750 rotates about a pivot
    virtual void vfunc_14(int dx, int dy, int dz, int bUpdate);                 // 14 0x1418b8560 rotates the object
    virtual void vfunc_15(float rx, float ry, float rz, int bUpdate);           // 15 0x1418b89f0
    virtual void vfunc_16(int n, int bUpdate);              // 16 0x1418b8b00
    virtual void vfunc_17(float f, int bUpdate);            // 17 0x1418b8c20
    virtual void vfunc_18(int n, int bUpdate);              // 18 0x1418b8d00
    virtual void vfunc_19(float f, int bUpdate);            // 19 0x1418b8e20
    virtual void vfunc_20(float x, float y, float z, int bUpdate);              // 20 0x1418b8f00 sets the rotation
    virtual void vfunc_21(UIRenderView* pView);             // 21 0x1418b9200 sets the model view
    virtual void vfunc_22();                                // 22 0x1418b9290 (empty)
    virtual GameObject* vfunc_23();                         // 23 0x1418b92a0 the object (vfunc_24)
    virtual GameObject* vfunc_24();                         // 24 0x1418b92d0 world lookup of m_nObjectId
    virtual int vfunc_25();                                 // 25 0x1418b9310 m_nObjectId
    virtual Unk_GoModelKey* vfunc_26(Unk_GoModelKey* pKey);                     // 26 0x1418b9330
    virtual int vfunc_27(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 27 0x1418b9390
    virtual void vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg);   // 28 0x1418b9730
    virtual void vfunc_29(int n);                           // 29 0x1418b9b20 m_nState = n

    // IAvatarObjectEventListener overrides (the secondary vftable; the bodies get this = +0x18)
    virtual int vfunc_0(GameObject* pObj);                  // o18 slot 0 0x1418b9880 model loaded
    virtual int vfunc_2(GameObject* pObj);                  // o18 slot 2 0x1418b9970
    virtual int vfunc_3(GameObject* pObj);                  // o18 slot 3 0x1418b9a00
    virtual int vfunc_4(GameObject* pObj);                  // o18 slot 4 0x1418b9a60

    int GetState();                                    // 0x1418b9b40 m_nState
    void SetLoaded(int bLoaded);                        // 0x1418b9b60 m_bLoaded = n
    int IsLoaded();                                    // 0x1418b9b80 m_bLoaded
    int GetKind();                                    // 0x1418b9ba0 m_nKind
    efd::SmartPointer<UIRenderView> GetView();        // 0x1418b9bc0 copy of the view pointer
    void FUN_1418b9c10();                                   // 0x1418b9c10 remembers the current pose, tells the view
    void FUN_1418b9df0(bool bAngle, bool bPosition);        // 0x1418b9df0
    void FUN_1418b9e40();                                   // 0x1418b9e40 reads the object's pose and framing
    void SetMode(int nMode);                          // 0x1418ba120 m_nMode = n
    int GetMode();                                    // 0x1418ba140 m_nMode
    int FUN_1418ba160(int nButton);                         // 0x1418ba160 m_nMode = FUN_1418ba1a0(nButton)
    int FUN_1418ba1a0(int nButton);                         // 0x1418ba1a0 button -> drag mode
    void FUN_1418ba200(Unk_StreamPoint* pDst, float x, float y, float z);       // 0x1418ba200
    void FUN_1418ba250(Unk_StreamPoint* pDst, const Unk_StreamPoint* pSrc);     // 0x1418ba250
    void FUN_1418ba280(int bUpdate);                        // 0x1418ba280 back to the stored position
    void FUN_1418ba340(int bUpdate);                        // 0x1418ba340 back to the stored angle
    void SetLocked(int n);                              // 0x1418ba3f0 m_nLocked = n
    void FUN_1418ba410(Unk_StreamPoint* pOut);              // 0x1418ba410
    void FUN_1418ba4a0(Unk_NiMatrix3* pRot, const Unk_StreamPoint* pPos, Unk_StreamPoint* pOut);   // 0x1418ba4a0

public:
    int m_nKind;                                            // +0x20 1 PC, 2 cube, 3 ridee, 4 pet
    int m_bLoaded;                                          // +0x24 the object's model finished loading
    unsigned int m_nObjectId;                                      // +0x28 object id in the world (0 = none)
    int m_pad_2c;
    efd::SmartPointer<UIRenderView> m_spView;               // +0x30
    Unk_StreamPoint m_kAngle;                               // +0x38 current angle (degrees)
    Unk_StreamPoint m_kAngleBase;                           // +0x44 angle before the drag
    Unk_StreamPoint m_kPos;                                 // +0x50 current position
    Unk_StreamPoint m_kPosBase;                             // +0x5c position before the drag
    Unk_StreamPoint m_kPivotBase;                           // +0x68
    Unk_StreamPoint m_kPivot;                               // +0x74 framing pivot (centre offset)
    Unk_StreamPoint m_kScratch;                             // +0x80 (NiPoint3 default constructed)
    int m_nMode;                                            // +0x8c drag mode (0 none, 1 rotate, 2 move, 3 camera)
    float m_fMoveStep;                                      // +0x90 0.7
    float m_fRotStep;                                       // +0x94 0.2
    float m_fZoomStep;                                      // +0x98 30.0
    int m_nState;                                           // +0x9c set by vfunc_29 (view attached)
    int m_nLocked;                                          // +0xa0 SetLocked
    bool m_bWheelCamera;                                    // +0xa4
    IUIAvatarEventListener* m_pListener;                    // +0xa8
    MS2Ptr<ItemPreviewCommon::CLimitCharRotate> m_spRotLimit;   // +0xb0
};
MS2_CHECK_SIZE(UIAvatarBase, 0xc0);
MS2_CHECK_OFFSET(UIAvatarBase, m_nKind, 0x20);
MS2_CHECK_OFFSET(UIAvatarBase, m_spView, 0x30);
MS2_CHECK_OFFSET(UIAvatarBase, m_kAngle, 0x38);
MS2_CHECK_OFFSET(UIAvatarBase, m_kPivot, 0x74);
MS2_CHECK_OFFSET(UIAvatarBase, m_nMode, 0x8c);
MS2_CHECK_OFFSET(UIAvatarBase, m_pListener, 0xa8);
MS2_CHECK_OFFSET(UIAvatarBase, m_spRotLimit, 0xb0);

// ---- UIAvatarPC ---------------------------------------------------------------------------------------------------

class UIAvatarPC : public UIAvatarBase
{
public:
    UIAvatarPC(PC* pSource, bool bFlag);                    // 0x1418ba570 mirrors a PC
    UIAvatarPC(int nGender, bool bFlag);                    // 0x1418ba6b0 default outfit of a gender
    UIAvatarPC(MS2Ptr<Unk_PCArg125> spSrc, bool bFlag);     // 0x1418ba7f0 mirrors a pc record
    virtual ~UIAvatarPC();                                  // 0x1418ba950 (scalar deleting 0x1418c1980)

    virtual void vfunc_1(IUIAvatarEventListener* pListener);    // 1  0x1418ba9f0 creates the rotation limit
    virtual void vfunc_2();                                 // 2  0x1418baab0
    virtual void vfunc_3();                                 // 3  0x1418bc210
    virtual void vfunc_4(__int64 nItemUid);                 // 4  0x1418bc2e0 equips the item of an uid
    virtual void vfunc_21(UIRenderView* pView);             // 21 0x1418bab20
    virtual GameObject* vfunc_23();                         // 23 0x1418babb0 the ridee when riding
    virtual int vfunc_27(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 27 0x1418bac20

    virtual int vfunc_0(GameObject* pObj);                  // o18 slot 0 0x1418bae00 creates the customize

    void FUN_1418baef0(int nValue);                         // 0x1418baef0
    void FUN_1418baf40(CItem* pItem);                       // 0x1418baf40
    void FUN_1418bafa0(CItem* pItem, int nEffect);          // 0x1418bafa0
    bool FUN_1418bb0c0(CItem* pItem);                       // 0x1418bb0c0
    bool FUN_1418bb0f0(CItem* pItem, int nEffect);          // 0x1418bb0f0 equips a cube-type item set
    bool FUN_1418bb2a0(MS2Ptr<CItemData> spData, int nEffect, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems);   // 0x1418bb2a0
    bool FUN_1418bb3f0(Unk_AvPackageKey* pKey, int nEffect, ATL::CAtlArray<MS2Ptr<CItemData> >* pItems);     // 0x1418bb3f0
    void FUN_1418bbc20(int nValue);                         // 0x1418bbc20
    void FUN_1418bbc70(CItem* pItem);                       // 0x1418bbc70
    void FUN_1418bbcd0(CItem* pItem);                       // 0x1418bbcd0
    void FUN_1418bbd30(int nSlot);                          // 0x1418bbd30
    void FUN_1418bbe40();                                   // 0x1418bbe40
    bool FUN_1418bbea0(Unk_AvPackageKey* pKey);             // 0x1418bbea0 drops one equip set
    bool FUN_1418bbfe0();                                   // 0x1418bbfe0 drops every equip set
    void FUN_1418bc110(MS2Ptr<CItem> spItem);               // 0x1418bc110
    void FUN_1418bc280(int nValue);                         // 0x1418bc280
    void FUN_1418bc380(CItem* pItem);                       // 0x1418bc380
    void FUN_1418bc500(Unk_AvPackageKey* pKey);             // 0x1418bc500
    void FUN_1418bc630();                                   // 0x1418bc630
    int FUN_1418bc740();                                    // 0x1418bc740
    void FUN_1418bc790(int nState, int nParam);             // 0x1418bc790
    void FUN_1418bc860(int nParam);                         // 0x1418bc860
    void FUN_1418bc8c0(int nSkin);                          // 0x1418bc8c0
    void FUN_1418bca10(Unk_CharEquip kColor0, Unk_CharEquip kColor1);   // 0x1418bca10
    void FUN_1418bca60(int nState, int nParam);             // 0x1418bca60
    bool FUN_1418bcd20(int nPose);                          // 0x1418bcd20
    bool FUN_1418bcd80(int nPose);                          // 0x1418bcd80
    void FUN_1418bce80(int nValue);                         // 0x1418bce80
    void FUN_1418bced0(MS2Ptr<CItemData> spData);           // 0x1418bced0
    void FUN_1418bcf60(int nSkillId, short nLevel);         // 0x1418bcf60
    void FUN_1418bcfc0(MS2Ptr<CItemData> spData);           // 0x1418bcfc0
    void FUN_1418bd050(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);   // 0x1418bd050
    void FUN_1418bd150(unsigned int a, unsigned int b);     // 0x1418bd150
    AvatarPC* FUN_1418bd1d0();                              // 0x1418bd1d0 the avatar object
    MS2Ptr<CAvatarPackageEquip> FUN_1418bd200(Unk_AvPackageKey* pKey);   // 0x1418bd200 the equip set of a key
    bool FUN_1418bd300();                                   // 0x1418bd300 has equip sets
    bool FUN_1418bd350(Unk_AvPackageKey* pKeyOut, int nItemId);   // 0x1418bd350
    MS2Ptr<CItem> FUN_1418bd510(int nItemId);               // 0x1418bd510
    MS2Ptr<Customize> GetCustomize();                      // 0x1418bd710 copy of the customize
    int GetPose();                                    // 0x1418bd760 m_nPose
    void FUN_1418bd780(PC* pSource, AvatarPC* pAvatar);     // 0x1418bd780
    void FUN_1418bd7f0(bool bEnabled);                      // 0x1418bd7f0
    void FUN_1418bd830();                                   // 0x1418bd830 re-applies m_nPose
    void FUN_1418bd860(int nPose);                          // 0x1418bd860 sets the pose

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Customize> m_spCustomize;                        // +0xc0
    bool m_bFlag;                                           // +0xd0
    int m_nPose;                                            // +0xd4
    int m_nAction;                                          // +0xd8 (1)
    int m_nActionParam;                                     // +0xdc (10)
    std::map<Unk_AvPackageKey, MS2Ptr<CAvatarPackageEquip> > m_mapPackages;   // +0xe0
};
MS2_CHECK_SIZE(UIAvatarPC, 0xf0);

// ---- UIAvatarCube -------------------------------------------------------------------------------------------------

class UIAvatarCube : public UIAvatarBase
{
public:
    UIAvatarCube(CItemData* pData);                         // 0x1418bd8e0
    virtual ~UIAvatarCube();                                // 0x1418bd950 (scalar deleting 0x1418c1940)

    virtual void vfunc_1(IUIAvatarEventListener* pListener);    // 1  0x1418bd9a0
    virtual void vfunc_3();                                 // 3  0x1418bdce0
    virtual void vfunc_21(UIRenderView* pView);             // 21 0x1418bda50
    virtual void vfunc_22();                                // 22 0x1418bdbb0
    virtual void vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg);   // 28 0x1418bdd30

    void FUN_1418bdae0(void* pUnused);                                   // 0x1418bdae0
    void FUN_1418bdc00(CItemData* pData);                   // 0x1418bdc00
    AvatarCube* FUN_1418bde80();                            // 0x1418bde80

public:
    MS2_LAYOUT_FRIEND;
    CItemData* m_pItemData;                                 // +0xc0
};
MS2_CHECK_SIZE(UIAvatarCube, 0xc8);

// ---- UIAvatarRidee ------------------------------------------------------------------------------------------------

class UIAvatarRidee : public UIAvatarBase
{
public:
    UIAvatarRidee();                                                // 0x1418bdeb0 (m_nKind stays 0)
    UIAvatarRidee(MS2Ptr<CItemData> spData);                        // 0x1418bdf30
    UIAvatarRidee(Unk_RideePtr spRow);                              // 0x1418bdfd0 (m_nKind stays 0)
    virtual ~UIAvatarRidee();                               // 0x1418be060 (scalar deleting 0x1418c1a00)

    virtual void vfunc_1(IUIAvatarEventListener* pListener);    // 1  0x1418be0b0
    virtual void vfunc_3();                                 // 3  0x1418be640
    virtual void vfunc_21(UIRenderView* pView);             // 21 0x1418be2b0
    virtual void vfunc_22();                                // 22 0x1418be410
    virtual void vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg);   // 28 0x1418be690
    virtual int vfunc_4(GameObject* pObj);                  // o18 slot 4 0x1418be860

    void FUN_1418be340(void* pUnused);                                   // 0x1418be340
    void FUN_1418be460(CItemData* pData);                   // 0x1418be460
    void FUN_1418be580(Unk_RideePtr spRow);                 // 0x1418be580
    AvatarRidee* FUN_1418be7e0();                           // 0x1418be7e0
    Unk_RideePtr GetRow();                           // 0x1418be810 copy of the row

public:
    MS2_LAYOUT_FRIEND;
    CItemData* m_pItemData;                                 // +0xc0
    Unk_RideePtr m_spRow;                                   // +0xc8
};
MS2_CHECK_SIZE(UIAvatarRidee, 0xd8);

// ---- UIAvatarPet --------------------------------------------------------------------------------------------------

class UIAvatarPet : public UIAvatarBase
{
public:
    UIAvatarPet(CItemData* pData);                          // 0x1418be8f0
    virtual ~UIAvatarPet();                                 // 0x1418be960 (scalar deleting 0x1418c19c0)

    virtual void vfunc_1(IUIAvatarEventListener* pListener);    // 1  0x1418be9b0
    virtual void vfunc_3();                                 // 3  0x1418bec60
    virtual void vfunc_21(UIRenderView* pView);             // 21 0x1418bea60
    virtual void vfunc_22();                                // 22 0x1418beb80
    virtual void vfunc_28(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg);   // 28 0x1418becb0

    void FUN_1418beaf0(void* pUnused);                                   // 0x1418beaf0
    void FUN_1418bebd0(CItemData* pData);                   // 0x1418bebd0
    AvatarPet* FUN_1418bee00();                             // 0x1418bee00

public:
    MS2_LAYOUT_FRIEND;
    CItemData* m_pItemData;                                 // +0xc0
};
MS2_CHECK_SIZE(UIAvatarPet, 0xc8);

// ---- free functions of the unit -----------------------------------------------------------------------------------

void FUN_1418bee30(ASObj* pObj, int nSkinTable);           // 0x1418bee30 skinColors of the skin colour table
void FUN_1418bf1e0(Unk_StreamPoint* pAngles);               // 0x1418bf1e0 wraps the three angles (degrees)
void FUN_1418bf230(float* pX, float* pY, float* pZ);        // 0x1418bf230
void FUN_1418bf270(float* pAngle);                          // 0x1418bf270 wraps an angle into 0..360
void FUN_1418bf2e0(int* pAngle);                            // 0x1418bf2e0
void FUN_1418bf330(Unk_StreamPoint* pAngles);               // 0x1418bf330 wraps the three angles (radians)
void FUN_1418bf380(float* pX, float* pY, float* pZ);        // 0x1418bf380
void FUN_1418bf3c0(float* pAngle);                          // 0x1418bf3c0 wraps an angle into 0..2pi
