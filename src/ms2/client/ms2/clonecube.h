// clonecube.h - CloneCube (efd RTTI "CloneCube", class id 0x06200060): a GameObject that shows one item model
// (a cube/furnishing or an equip preview) in a UI model view. Base of AvatarCube (?\avatarcube.cpp), AvatarPet and
// AvatarRidee (?\avatarpc.cpp). Owning unit: ?\clonecube.cpp (0x141084ad0-0x141086ae0). Header name assumed.
//
// Size 0x1a0 (??_G 0x1410864c0 frees 0x1a0). vftable 0x142ea7408 (62 slots: GameObject's 57 + 57..61),
// CallbackObject vftable 0x142ea7600 (dtor thunk 0x141086434, the rest inherited from GameObject).
// efd: TypeCast 0x1410867b0 / 0x141086760, GetClassDesc 0x1410866c0, ClassInfo 0x143acd710 (setup 0x141086700,
// registration 0x1400e53c0). Ctor 0x141085b00, dtor 0x141084ad0.
//
// IAvatarObjectEventListener (RTTI, vftable 0x142dc04c8, 5 slots, no dtor): the UI owner of an avatar object
// (UIAvatarCube, CUgcViewerCube, AvatarPC's secondary base at +0x1340). Every default body returns 1; the COMDATs
// (0x1409f7eb0-0x1409f7ef0) are in ?\avatarpc.cpp, the first unit that emits the interface's vftable.
#pragma once
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include <NiTexture.h>

class CItem;
class CItemData;
class CItemUgcMeshContainer;   // itemugcmesh.h
class UIModelView;             // UIRenderView (NiRefObject) subclass, ?\uimodelview.cpp (vftable 0x142e51298)

// Slot bodies are COMDATs emitted in ?\avatarpc.cpp (0x1409f7ee0, 0x1409f7ef0, 0x1409f7eb0, 0x1409f7ed0, 0x1409f7ec0 for
// slots 0..4); that unit tags or pins them.
class IAvatarObjectEventListener
{
public:
    virtual int vfunc_0(GameObject* pObj) { return 1; }    // model loaded (CloneCube::vfunc_10)
    virtual int vfunc_1(GameObject* pObj) { return 1; }    // CloneCube::vfunc_12
    virtual int vfunc_2(GameObject* pObj) { return 1; }    // model handed to the model view (CloneCube::FUN_1410852a0)
    virtual int vfunc_3(GameObject* pObj) { return 1; }    // model reload started (CloneCube::vfunc_58)
    virtual int vfunc_4(GameObject* pObj) { return 1; }    // reloaded model attached (CloneCube::vfunc_13)
};

class CloneCube : public GameObject
{
    EE_DECLARE_CLASS1(CloneCube, 0x06200060, GameObject);

public:
    // spData by value (the ctor destroys it); strModel is the model path used when the item has no install asset.
    CloneCube(MS2Ptr<CItemData> spData, const CString& strModel);   // 0x141085b00
    virtual ~CloneCube();                                   // 0x141084ad0

    virtual void vfunc_9(void* p);                          // 9  0x1410858d0 vfunc_57(), then GameObject's
    virtual int vfunc_10();                                 // 10 0x141085910
    virtual void vfunc_12();                                // 12 0x141085990
    virtual void vfunc_13(void* a, efd::Category cat);      // 13 0x1410859e0
    virtual void vfunc_49();                                // 49 0x141085c70 (empty)
    virtual void vfunc_53(float f);                         // 53 0x141085c80
    virtual bool vfunc_55(float a, float b);                // 55 0x141085d10 (false while hidden)
    virtual bool vfunc_56(float f);                         // 56 0x141085cd0 (false while hidden)
    // new virtuals (AvatarPet adds slot 62)
    virtual bool vfunc_57();                                // 57 0x141084be0 re-applies the current item (vfunc_58)
    // Sets the item and reloads the model when its path changed; false if nothing changed (vfunc_61). By value.
    virtual bool vfunc_58(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);   // 58 0x141084d80
    virtual void vfunc_59(MS2Ptr<CItem> spItem);            // 59 0x141085d60 (empty; AvatarCube applies the item)
    virtual void vfunc_60();                                // 60 0x141085d90 applies UGC meshes and the item
    virtual bool vfunc_61(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem);   // 61 0x141085e50 same item as now

    // non-virtual
    void SetItem(MS2Ptr<CItem> spItem);               // 0x141084cb0 m_spItem = spItem
    void FUN_141084d00(UIModelView* pView);                 // 0x141084d00 set the model view (marks dirty if loaded)
    UIModelView* GetModelView();                           // 0x141084d60
    void FUN_141085250();                                   // 0x141085250 re-applies the UGC textures
    void FUN_1410852a0();                                   // 0x1410852a0 hands the model to the model view
    void FUN_1410853e0(bool bVisible);                      // 0x1410853e0
    bool IsVisible();                                   // 0x141085420
    void FUN_141085440();                                   // 0x141085440 marks the model's meshes unlightable
    void FUN_141085530(MS2Ptr<CItem> spItem);               // 0x141085530 vfunc_59 once the model is loaded
    void FUN_1410855b0();                                   // 0x1410855b0 builds the UGC mesh list
    NiTexturePtr FUN_141085700();                           // 0x141085700 UGC texture (or null)
    MS2Ptr<CItemUgcMeshContainer> GetUgcMesh();          // 0x141085830 copy of m_spUgcMesh
    MS2Ptr<CItemData> GetItemData();                      // 0x141085880 copy of m_spItemData
    void SetListener(IAvatarObjectEventListener* p);      // 0x141085ab0
    IAvatarObjectEventListener* GetListener();            // 0x141085ae0

public:
    MS2_LAYOUT_FRIEND;
    UIModelView* m_pModelView;                              // +0x140 raw (no reference held)
    bool m_bDirty;                                          // +0x148 model must be handed to the view (vfunc_53)
    bool m_bVisible;                                        // +0x149 gates vfunc_55/56
    IAvatarObjectEventListener* m_pListener;                // +0x150
    MS2Ptr<CItem> m_spItem;                                 // +0x158
    MS2Ptr<CItemData> m_spItemData;                         // +0x168
    CString m_strModel;                                     // +0x178 ctor argument
    CString m_strModelFormat;                               // +0x180 "urn:gamebryo-scenegraph:%s"
    bool m_bReloading;                                      // +0x188 set while a changed model reloads
    MS2Ptr<CItemUgcMeshContainer> m_spUgcMesh;              // +0x190
};
MS2_CHECK_SIZE(CloneCube, 0x1a0);
MS2_CHECK_OFFSET(CloneCube, m_pModelView, 0x140);
MS2_CHECK_OFFSET(CloneCube, m_bDirty, 0x148);
MS2_CHECK_OFFSET(CloneCube, m_bVisible, 0x149);
MS2_CHECK_OFFSET(CloneCube, m_pListener, 0x150);
MS2_CHECK_OFFSET(CloneCube, m_spItem, 0x158);
MS2_CHECK_OFFSET(CloneCube, m_spItemData, 0x168);
MS2_CHECK_OFFSET(CloneCube, m_strModel, 0x178);
MS2_CHECK_OFFSET(CloneCube, m_strModelFormat, 0x180);
MS2_CHECK_OFFSET(CloneCube, m_bReloading, 0x188);
MS2_CHECK_OFFSET(CloneCube, m_spUgcMesh, 0x190);
