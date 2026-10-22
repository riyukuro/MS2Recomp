// itempickinghelper.h - CItemPickingHelper (RTTI .?AVCItemPickingHelper@@, NiRefObject-based, 0x68 bytes): ray-picks
// the attach parts of the customized item against the cursor. Its out-of-line members are in
// ?\itemcustomizecontroller.cpp#4 (0x141418c00-0x141419df0); the inline accessors below were first emitted by #1
// (CItemCustomizeController, 0x141412e40-0x1414131c0). Header name assumed. Layout and member names follow w22's
// #4 analysis (itemcustomizecontroller.h); this is the single shared definition (itemcustomizecontroller.h was removed), used by #1, #3 and #4.
// Member names are invented.
#pragma once
#include <afx.h>
#include <set>
#include <NiAVObject.h>
#include <atlcoll.h>
#include <NiRefObject.h>
#include <NiRenderObject.h>
#include <NiPoint2.h>
#include <NiPoint3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"     // MS2Ptr<T>

class CItem;
class CEquipItem;
class NiAVObject;
class CMeshUVPicker;       // RTTI .?AVCMeshUVPicker@@ (NiRefObject, 0x98), unit ?\meshuvpicker.cpp

// Model facts of a pickable part: m_nKind 0 = ponytail hair, otherwise a morph hair (read by the controller factory).
struct Unk_PickPartInfo
{
    char m_pad_00[8];
    CString m_str08;            // +0x08 name of the part's attach node
    char m_pad_10[0x10];
    int m_n20;                  // +0x20 nonzero: the part's node lives in its loaded meshes only (unit_1411673f0)
    char m_pad_24[8];
    int m_nKind;
};

// One pickable attach part of the item model (CPtred-derived, held in MS2Ptr; methods in unit_1411673f0 /
// ?\equipmodel.cpp). Only the members recovered code calls are declared.
struct Unk_PickTarget : public CPtred
{
    MS2Ptr<CItem> FUN_141200940() const;                        // the item the slot shows
    void* FUN_141200850() const;                                // the slot's game object (owns the model)
    Unk_PickPartInfo* FUN_141200ab0() const;                    // the part's model facts
    MS2Ptr<CEquipItem> FUN_141200a40() const;                   // the equip item the part belongs to (caprotationcontroller.cpp)
    MS2Ptr<Unk_PickTarget> FUN_1411de2e0();                     // an MS2Ptr to this part (itemugcmesh.cpp)
    void FUN_1412014f0(Vector3 kOffset);                // stores the offset (itemugcmesh.cpp)
    void FUN_141201620(Vector3 kEuler);                 // stores the euler (itemugcmesh.cpp)
    void FUN_141201cb0(std::set<NiAVObjectPtr>& kOut);          // copies the node set of the part (itemugcmesh.cpp)
    std::set<NiAVObjectPtr>& FUN_141201c90() const;                // the part's node set (itemugcmesh.cpp)
    void FUN_141200160(Vector3 kOffset);                // sets the part's model offset
    void FUN_141200100(Vector3 kEuler);                 // sets the part's model rotation (euler degrees)
    NiAVObject* FUN_1411673f0(const CString* pName) const;      // the scene node named pName (unit_1411673f0)
    NiAVObject* FUN_1411676d0(const CString* pPartName) const;  // the model node of one attach part (w22: NiRenderObject**)
    // highlight: fScale/fMode from CItemCustomizeController::vfunc_39, pNode = the picked mesh or NULL
    void FUN_1411679d0(float fScale, float fMode, NiAVObject* pNode);
    // four points of the part's screen anchor (the first one is projected by CItemCustomizeController::BeginDrag)
    void FUN_141202480(efd::Point3* pP0, efd::Point3* pP1, efd::Point3* pP2, efd::Point3* pP3, void* pUnused);
};

// Smart pointer to a scene node (NiRefObject::IncRefCount 0x140980460 / DecRefCount 0x1405a93d0). 8 bytes.
struct Unk_PickMeshPtr
{
    Unk_PickMeshPtr(NiAVObject* p);                             // 0x1414197a0
    ~Unk_PickMeshPtr();                                         // 0x141419840
    Unk_PickMeshPtr& FUN_141418a00(NiAVObject* p);              // assignment (0x141418a00)
    NiAVObject* FUN_141412c90() const { return m_p; }           // get (inline COMDAT 0x141412c90, emitted by #1)
    NiAVObject* operator->() const { return m_p; }              // inline COMDAT 0x141477f60, first emitted by ?\makeupcontroller.cpp
    bool operator==(NiAVObject* p) const;                       // inline COMDAT 0x141849ec0 (textureanimationdata.cpp)
    NiAVObject* m_p;
};
MS2_CHECK_SIZE(Unk_PickMeshPtr, 8);

// Owning pointer to the UV picker.
struct Unk_UVPickerPtr
{
    Unk_UVPickerPtr(CMeshUVPicker* p);                         // 0x141286170
    ~Unk_UVPickerPtr();                                         // 0x1412861b0
    Unk_UVPickerPtr& FUN_1412861e0(CMeshUVPicker* p);           // reset
    CMeshUVPicker* FUN_141286290() const;                       // get
    bool FUN_141286250(CMeshUVPicker* p) const;                 // m_p == p (0x141286250)
    CMeshUVPicker* FUN_141412c80() const { return m_p; }        // get (inline COMDAT 0x141412c80, emitted by #1)
    CMeshUVPicker* m_p;
};
MS2_CHECK_SIZE(Unk_UVPickerPtr, 8);

class CItemPickingHelper : public NiRefObject
{
public:
    CItemPickingHelper();                                       // 0x141418c00
    virtual ~CItemPickingHelper();                              // 0x141418cd0, ??_G 0x141419870

    int CreatePicker();                                         // 0x141418d60 (CItemCustomizeController::Initialize tests eax)
    void ClearTargets();                                        // 0x141418e00
    void AddTarget(Unk_PickTarget* pTarget);                    // 0x141418e30
    Unk_PickTarget* GetPickedTarget();                          // 0x141418e90
    int GetPickedIndex() const;                                 // 0x141418ef0
    // pHit; parts = CItemCustomizeController::m_aPartNames (CAtlArray<CString>, see itemcustomizecontroller_1.h)
    int Pick(efd::Point3* pHit, CAtlArray<CString>& parts);     // 0x141418f10
    void Reset();                                               // 0x141419210
    // unit-internal (#4): ray-pick one target's part / one mesh; skins = the FA_Skin/FA_EA render objects
    int PickTarget(Unk_PickTarget* pTarget, const CString* pPartName, NiPoint3* pHit);    // 0x141419250
    int PickMesh(NiAVObject* pMesh, CAtlArray<NiRenderObject*>& skins, NiPoint3* pHit);    // 0x1414194b0

    // inline accessors (COMDATs first emitted by ?\itemcustomizecontroller.cpp#1)
    CMeshUVPicker* GetUVPicker() { return m_spPicker.FUN_141412c80(); }                 // 0x141412e40
    CAtlArray<MS2Ptr<Unk_PickTarget> >& GetTargets() { return m_targets; }              // 0x141412e60
    int GetMode() { return m_nMode; }                                                   // 0x141412e70
    void SetMode(int nMode) { m_nMode = nMode; }                                        // 0x1414131c0
    void SetPrevMesh(NiAVObject* pMesh) { m_spLast.FUN_141418a00(pMesh); }              // 0x141478060 (first emitted by ?\makeupcontroller.cpp)

    Unk_PickMeshPtr m_spMesh;                                   // +0x10 mesh hit by the last successful pick
    int m_nMode;                                                // +0x18 (w22: m_nUnk18) 0 = idle, 1 = dragging
    Unk_UVPickerPtr m_spPicker;                                 // +0x20
    CAtlArray<MS2Ptr<Unk_PickTarget> > m_targets;               // +0x28
    int m_nPicked;                                              // +0x48 index into m_targets, -1 = none
    efd::Point2 m_kUv0;                                         // +0x4c
    efd::Point2 m_kUv1;                                         // +0x54
    Unk_PickMeshPtr m_spLast;                                   // +0x60
};
MS2_CHECK_SIZE(CItemPickingHelper, 0x68);
MS2_CHECK_OFFSET(CItemPickingHelper, m_nMode, 0x18);
MS2_CHECK_OFFSET(CItemPickingHelper, m_spPicker, 0x20);
MS2_CHECK_OFFSET(CItemPickingHelper, m_targets, 0x28);
MS2_CHECK_OFFSET(CItemPickingHelper, m_nPicked, 0x48);
MS2_CHECK_OFFSET(CItemPickingHelper, m_spLast, 0x60);
