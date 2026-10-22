// decoeditservice.h - DecoEditService (RTTI name): efd system service (class id 0x06100014) behind the housing "deco"
// editor (UIDecoEditDialog): the player paints decoration instances ("grass") onto the ground of a map. It owns the
// named layers (DecoLayer, each with the model asset and its DecoItem instance lists) and the two brushes (paint /
// noise). The layers are saved to / loaded from "./Data/Xml/Map/%08d_deco.xml". It is also an IWorldServiceCallback
// (slot 1 loads the layers, slot 4 drops them on a map change).
// DecoItem (RTTI name, class id 0x06200014) is the GameObject that shows one asset (a .nif scene graph or a .kfm
// animated model) and, for static models, turns every mesh into a hardware instanced mesh (one NiMeshHWInstance per
// stored transform). DecoLayer is a plain CPtred.
// Member and helper names are invented from their use.
// Owning unit: ?\decoeditservice.cpp (0x1411* .text$mn 0x14116f6a0-0x141177ee0, .text$di 0x1400e6d40-0x1400e7190).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <efd/ISystemService.h>
#include <efd/Category.h>
#include <efd/SmartPointer.h>
#include <NiTransform.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/editbrush.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/nipoint3.h"

class NiMesh;
class NiNode;
class NiAVObject;
namespace efd { class utf8string; }
class Unk_TiXmlElement;
class Unk_DecoXml;

// One batch of instances of the layer's asset. Virtual slots 9..14 / 53 hook the GameObject load / unload.
class DecoItem : public GameObject
{
    EE_DECLARE_CLASS1(DecoItem, 0x06200014, GameObject);

public:
    DecoItem();                                                     // 0x141173f00
    explicit DecoItem(const ATL::CAtlArray<NiTransform>& aXf);      // 0x141173f90 copies the instance transforms
    virtual ~DecoItem();                                            // 0x141174060

    virtual void vfunc_9(void* p);                                  // 9  0x141174d50 resets position and direction
    virtual int vfunc_10();                                         // 10 0x141174e40
    virtual int vfunc_11();                                         // 11 0x141174f10
    virtual void vfunc_12();                                        // 12 0x141175030
    virtual void vfunc_14();                                        // 14 0x141175050
    virtual void vfunc_53(float f);                                 // 53 0x141174550 builds the instanced meshes

    bool SaveXml(Unk_TiXmlElement* pParent);                            // 0x1411740b0 one "grass" child per instance
    void Refresh();                                                 // 0x141174280 update the scene and hand it to the world
    void SetCulled(int bVisible);                                   // 0x141174380 (0: hide) app-cull the meshes
    void SetModel(CString strModel);                                // 0x141174450 (by value: the callee destroys it)
    void ApplyInstancing();                                         // 0x1411744e0 enable instancing on every mesh
    bool LoadNif(CString strAsset);                                 // 0x141174800 (by value) start loading a .nif
    bool LoadKfm(CString strAsset);                                 // 0x141174930 (by value) start loading a .kfm
    bool AddTransform(const NiTransform& xf);                       // 0x141174a50 false when a transform at that spot exists
    void CollectNear(Vector3 pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut);   // 0x141174ab0
    void CollectTransforms(ATL::CAtlArray<NiTransform>& aOut);      // 0x141174bb0 the transform of every instance
    CString GetModel();                                             // 0x1411744a0 the model path
    void PlayAnim(int nSeq, float fSpeed, bool bLoop);              // 0x141174ce0
    void PlayAnim(const efd::utf8string& strName, float fSpeed, bool bLoop);   // 0x141174c70
    void SetAnimSpeed(int nSeq, float fSpeed, bool bLoop);          // 0x141174ce0
    bool IsEditable();                                              // 0x1411747f0
    static bool ContainsTransform(const NiTransform& xf, const ATL::CAtlArray<NiTransform>& aXf);   // 0x141175100
    static bool PrepareMesh(NiMesh* pMesh, bool bOverdraw);         // 0x141175190 picks the material of a mesh
    static void EnableInstancing(NiNode* pRoot, unsigned nCount, bool bOverdraw);    // 0x141175250
    static void UpdateEffects(NiNode* pRoot);                       // 0x141175340

    bool m_bKfm;                                                    // +0x140 the asset is a .kfm
    ATL::CAtlArray<NiTransform> m_aXf;                              // +0x148 the instance transforms
};
MS2_CHECK_SIZE(DecoItem, 0x168);
MS2_CHECK_OFFSET(DecoItem, m_bKfm, 0x140);
MS2_CHECK_OFFSET(DecoItem, m_aXf, 0x148);

// A named group of instances of one asset.
class DecoLayer : public CPtred
{
public:
    explicit DecoLayer(CString strName);                            // 0x141176960 (by value: the ctor destroys it)
    virtual ~DecoLayer();                                           // 0x1411769f0

    bool SaveXml(Unk_TiXmlElement* pParent);                            // 0x141176b10
    void Refresh();                                                 // 0x141176d30
    void SetCulled(int bVisible);                                   // 0x141176dc0
    CString GetName();                                              // 0x141176e60
    CString GetAsset();                                             // 0x141176eb0
    bool IsKfm(CString strAsset);                                   // 0x141176f00 the path contains ".kfm" (a member: rcx = this)
    bool SetAsset(CString strAsset);                                // 0x141176f70 first asset of the layer
    bool ChangeAsset(CString strAsset);                             // 0x1411770b0 rebuild every item for another asset
    DecoItem* AddItem();                                            // 0x1411773c0
    DecoItem* AddItem(const ATL::CAtlArray<NiTransform>& aXf);      // 0x141177470
    bool AddTransform(const NiTransform& xf);                       // 0x141177530
    void CollectNear(Vector3 pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut);   // 0x141177580
    DecoItem* GetEditableItem();                                    // 0x141177640

private:
    MS2_LAYOUT_FRIEND;
    CString m_strName;                                              // +0x18
    CString m_strAsset;                                             // +0x20
    ATL::CAtlArray<efd::SmartPointer<DecoItem> > m_aItems;          // +0x28
};
MS2_CHECK_SIZE(DecoLayer, 0x48);
MS2_CHECK_OFFSET(DecoLayer, m_strName, 0x18);
MS2_CHECK_OFFSET(DecoLayer, m_aItems, 0x28);

// the exe's map passes the int key by const reference
struct Unk_BrushKeyTraits : ATL::CElementTraits<int> { typedef const int& INARGTYPE; };

class DecoEditService;
template <class T> class TSingleton;
template <> class TSingleton<DecoEditService>
{
public:
    TSingleton();                                   // 0x141170c60 (inline, below)
    virtual ~TSingleton() { s_instance = 0; }       // 0x141170ed0
    static DecoEditService* s_instance;             // 0x143ad08c8
};

class DecoEditService : public efd::ISystemService, public IWorldServiceCallback, public TSingleton<DecoEditService>
{
    EE_DECLARE_CLASS1(DecoEditService, 0x06100014, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    DecoEditService();                              // 0x14116f6a0
    virtual ~DecoEditService();                     // 0x14116f7b0
    virtual const char* GetDisplayName() const;     // 0x14116f850
    virtual void vfunc_1(int nMap);                 // 0x141170970 (IWorldServiceCallback slot 1: load the layers)
    virtual void vfunc_4(int nMap);                 // 0x1411709a0 (slot 4: drop the layers)
    virtual efd::AsyncResult OnInit();              // 0x141170590
    virtual efd::AsyncResult OnTick();              // 0x141170730
    virtual efd::AsyncResult OnShutdown();          // 0x141170930

    EditBrush* GetBrush();                          // 0x14116f870 the selected brush (0 if none)
    void SetBrush(int nBrush);                      // 0x14116f900 deselects the previous one
    CString GetXmlPath();                           // 0x14116f990 "./Data/Xml/Map/%08d_deco.xml"
    DecoLayer* GetLayer();                          // 0x14116fa50 the selected layer
    bool AddLayer(CString strName);                 // 0x14116fa80 (by value) create and select
    bool RemoveLayer(CString strName);              // 0x14116fc10 (by value)
    bool SelectLayer(CString strName);              // 0x14116fcd0 (by value)
    void SaveXml();                                 // 0x14116fd50
    void LoadXml();                                 // 0x14116fef0
    void RefreshLayers();                           // 0x1411702f0
    void SetLayersCulled(int bVisible);             // 0x141170420
    void CollectLayers(ATL::CAtlArray<MS2Ptr<DecoLayer> >& aOut);                                   // 0x141170240
    void ApplyBrush();                              // 0x1411703a0 slot 3 of the selected brush
    bool AddTransform(const NiTransform& xf);       // 0x1411704d0
    void CollectNear(Vector3 pt, float fRadius, ATL::CAtlArray<NiMeshHWInstance*>& aOut);   // 0x141170520

    int m_nBrush;                                                   // +0x2c selected brush (0 paint, 1 noise)
    MS2Ptr<DecoLayer> m_spLayer;                                    // +0x30 selected layer
    ATL::CRBMap<CString, MS2Ptr<DecoLayer> > m_mapLayers;           // +0x40 name -> layer
    ATL::CAtlMap<int, MS2Ptr<EditBrush>, Unk_BrushKeyTraits> m_mapBrushes;             // +0x70 brush id -> brush
};
MS2_CHECK_SIZE(DecoEditService, 0xb8);
MS2_CHECK_OFFSET(DecoEditService, m_nBrush, 0x2c);
MS2_CHECK_OFFSET(DecoEditService, m_spLayer, 0x30);
MS2_CHECK_OFFSET(DecoEditService, m_mapLayers, 0x40);
MS2_CHECK_OFFSET(DecoEditService, m_mapBrushes, 0x70);
