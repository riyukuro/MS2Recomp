// itemcustomizecontroller_1.h - CItemCustomizeController (RTTI .?AVCItemCustomizeController@@, NiRefObject-based,
// 0xb8 bytes): abstract base of the item customize controllers that edit an equipped item in the dressing/customize
// UI: CItemMorphController (0xc0, ?\itemcustomizecontroller.cpp#3), CCapRotationController (0x140,
// ?\caprotationcontroller.cpp), CMakeupController (0xe0, ?\makeupcontroller.cpp), CPonyTailController (0x250,
// client\ms2\ponytailphysxhelper.cpp). Owning unit: ?\itemcustomizecontroller.cpp#1 (src/ms2/client/ms2/
// itemcustomizecontroller_1.cpp). Header name assumed; the ?\itemcustomizecontroller.cpp family header
// (itempickinghelper.h, CItemPickingHelper) belongs to #4.
//
// HOW TO USE THIS HEADER (for unit workers):
// - `class CXController : public CItemCustomizeController`; derived data starts at +0xb8. Copy the exact virtual
//   declarations below to override. vfunc_N = slot N of vftable 0x142f0f790 (42 slots). Slot 0 is _purecall in the
//   base table (pure virtual dtor; body 0x141410e60), slot 1 NiRefObject::DeleteThis, slot 2 GetRTTI (root NiRTTI
//   "CItemCustomizeController" at 0x143adac28; derived classes use NiDeclareRTTI + NiImplementRTTI(X,
//   CItemCustomizeController)).
// - Slots written inline below are header inlines: their COMDATs live in the FIRST unit that emitted them
//   (?\caprotationcontroller.cpp 0x140b02be0-0x140b02dc0, or #1 0x141412ed0-0x1414131b0). Do not redefine them.
// - The ctor (0x141410cd0) and dtor (0x141410e60) are out of line; derived ctors call them.
// - Member names are invented from their use; vfunc_N names are kept because the slot meanings are only partly known.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiRefObject.h>
#include <NiRTTI.h>
#include <NiSmartPointer.h>
#include <NiPoint2.h>
#include <NiPoint3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"     // MS2Ptr<T>

class CEquipItem;           // RTTI .?AVCEquipItem@@ (CPtred, 0xb0), ?\equipitem.cpp
class CItemPickingHelper;   // RTTI .?AVCItemPickingHelper@@ (NiRefObject, 0x68), itempickinghelper.h
class NiAVObject;
class CItemCustomizeController;

// The customize value range a controller edits (returned by vfunc_23/24). 0x28 bytes; default ctor 0x140544b10
// (commonfiles\itemdatastruct.cpp: m_fMax = 1.0f, m_fMin = 0, m_n08 = 0, m_10 constructed by 0x140182f00), dtor
// 0x140541080. Only the two floats are read by the controllers (vfunc_19 = min, vfunc_20 = max). Name invented.
struct Unk_CustomizeRange
{
    Unk_CustomizeRange();           // 0x140544b10
    ~Unk_CustomizeRange();          // 0x140541080
    float m_fMax;                   // +0x00
    float m_fMin;                   // +0x04
    int m_n08;                      // +0x08
    int m_n0c;
    void* m_unk_10;                 // +0x10 0x18-byte member (ctor 0x140182f00), opaque
    void* m_unk_18;
    void* m_unk_20;
};
MS2_CHECK_SIZE(Unk_CustomizeRange, 0x28);

// Listener at CItemCustomizeController +0xa0 (slot 0 called from vfunc_38 with vfunc_41's result). Name invented.
class Unk_ItemCustomizeListener
{
public:
    virtual void vfunc_0(CItemCustomizeController* pController, int nValue) = 0;
};

class CItemCustomizeController : public NiRefObject
{
public:
    CItemCustomizeController();                                     // 0x141410cd0
    virtual ~CItemCustomizeController() = 0;                        // 0  0x141410e60 (_purecall in the base table)
    // 1  NiRefObject::DeleteThis
    NiDeclareRootRTTI(CItemCustomizeController);                    // 2  GetRTTI 0x141412ed0 (root: the IsKindOf /
                                                                    //    DynamicCast inlines 0x140cd6050 0x140cd5580 0x140cd55d0 are customize.cpp's)
    virtual int vfunc_3();                                          // 3  0x1414111d0
    virtual void vfunc_4();                                         // 4  0x1414111f0 caches m_nPartCount
    virtual void vfunc_5() {}                                       // 5  0x140b02d50
    virtual void vfunc_6() {}                                       // 6  0x141413140
    virtual void vfunc_7(float fValue);                             // 7  0x141411340
    virtual void vfunc_8(int nIndex, float fValue);                 // 8  0x1414113c0
    virtual void vfunc_9(int nIndex) {}                             // 9  0x140b02dc0
    virtual void vfunc_10(float fValue) {}                          // 10 0x140b02db0
    virtual void vfunc_11();                                        // 11 0x141411450
    virtual int vfunc_12();                                         // 12 0x1414114c0 re-reads the equip item
    virtual void vfunc_13(MS2Ptr<CEquipItem> spOld);                // 13 0x141411580 (by value: callee destroys)
    virtual void vfunc_14(float fValue) {}                          // 14 0x140b02d70
    virtual void vfunc_15(int nIndex, float fValue) { vfunc_14(fValue); }   // 15 0x140b02d80
    virtual void vfunc_16() {}                                      // 16 0x140b02d60
    virtual int vfunc_17() { return -1; }                           // 17 0x140b02c20
    virtual float vfunc_18() { return 0.0f; }                       // 18 0x140b02bf0
    virtual float vfunc_19() { return 0.0f; }                       // 19 0x140b02cd0 range min (derived: vfunc_23()->m_fMin)
    virtual float vfunc_20() { return 1.0f; }                       // 20 0x140b02cc0 range max (derived: vfunc_23()->m_fMax)
    virtual float vfunc_21() { return m_afValue[m_nCurIndex]; }     // 21 0x140b02c40
    virtual float vfunc_22(int nIndex)                              // 22 0x140b02c60
    {
        return (nIndex >= 0 && nIndex < 2) ? m_afValue[nIndex] : vfunc_21();
    }
    virtual const Unk_CustomizeRange* vfunc_23();                   // 23 0x1414115f0 (function static default)
    virtual const Unk_CustomizeRange* vfunc_24(int nIndex);         // 24 0x141411680 -> vfunc_23()
    virtual void vfunc_25(float* pfMin, float* pfMax) { *pfMin = 0.0f; *pfMax = 1.0f; }   // 25 0x140b02ce0
    virtual void vfunc_26(int nIndex, float* pfMin, float* pfMax) { vfunc_25(pfMin, pfMax); }   // 26 0x140b02d10
    virtual int vfunc_27() { return 1; }                            // 27 0x140b02c00
    virtual void vfunc_28() {}                                      // 28 0x141413080
    virtual int vfunc_29() { return 1; }                            // 29 0x1414131b0
    virtual void vfunc_30(const NiPoint3& kPos) {}                  // 30 0x141413120 drag (mode 1) begin
    virtual void vfunc_31() {}                                      // 31 0x141413110 drag (mode 1) no hit
    virtual void vfunc_32(const NiPoint3& kHit, const NiPoint3& kNormal, const NiPoint2& kUV, float fValue) {}
                                                                    // 32 0x1414130f0 drag (mode 1) hit
    virtual void vfunc_33() {}                                      // 33 0x1414130c0 drag (mode 1) end
    virtual void vfunc_34(const NiPoint3& kPos) {}                  // 34 0x141413130 drag (mode 2) begin
    virtual void vfunc_35() {}                                      // 35 0x1414130e0 drag (mode 2) update
    virtual void vfunc_36() {}                                      // 36 0x1414130d0 drag (mode 2) end
    virtual void vfunc_37() {}                                      // 37 0x140b02be0
    virtual int vfunc_38(int bActive, const efd::Point3& kPos);     // 38 0x141411b20 per-frame update
    virtual void vfunc_39(int bActive);                             // 39 0x141412500 highlight the parts
    virtual float vfunc_40() { return 0.1f; }                       // 40 0x140b02c10
    virtual int vfunc_41();                                         // 41 0x1414126d0 input axis value

    // non-virtual (names invented)
    int Initialize(int nSlot);                                      // 0x141410ff0
    void Close();                                                   // 0x141411110
    void Cancel();                                                  // 0x141411190
    int RefreshEquipItem();                                         // 0x141411270
    float GetWheelDelta();                                          // 0x1414116b0
    void ApplyValues();                                             // 0x1414117a0
    void ReadValues();                                              // 0x141411920
    int IsPickable(efd::Point3* pHit);                              // 0x141411a90
    void BeginDrag(const NiPoint3& kPos);                                  // 0x141411c70
    void UpdateDrag();                                              // 0x141411f50
    void EndDrag();                                                 // 0x141412320
    void BeginDrag2(const NiPoint3& kPos);                                 // 0x141412380
    void UpdateDrag2();                                             // 0x1414123d0
    void EndDrag2();                                                // 0x141412400
    MS2Ptr<CEquipItem> GetEquipItem();                              // 0x141412450
    int GetEquipItemValue();                                        // 0x1414124a0
    void OnMouseButton1(const efd::Point3& kPos);                   // 0x141412750 left button: drag mode 1
    void OnMouseButton2(int bActive, const efd::Point3& kPos);      // 0x141412870 right button: drag mode 2
    static float GetHighlightScale(NiAVObject* pNode);              // 0x141412990
    void SetDragging(int bDragging) { m_bDragging = bDragging; }    // 0x141413190 (inline COMDAT)
    // inline COMDATs first emitted by TU B (factory/registry, itemcustomizecontroller_1b.cpp)
    int IsEnabled() const { return m_bEnabled; }                    // 0x141478000 (inline COMDAT first emitted by ?\makeupcontroller.cpp)
    int GetSlot() const { return m_nSlot; }                         // 0x141414920
    int IsDragging1() const { return m_bDragging1; }                // 0x141414930
    int IsDragging2() const { return m_bDragging2; }                // 0x141414950
    void SetListener(Unk_ItemCustomizeListener* p) { m_pListener = p; }   // 0x141414c20
    int IsInteractive() const;                                      // 0x141414760 any of m_bUseButton1/m_bUseButton2/m_bEnabled
    int GetDragging();                                              // 0x140cd5fd0 (inline COMDAT first emitted by customize.cpp)

    int m_nSlot;                                    // +0x10 equip slot (Initialize; 6 = cap, 1 = hair)
    MS2Ptr<CEquipItem> m_spEquipItem;               // +0x18
    int m_bUseButton1;                              // +0x28 enables OnMouseButton1
    int m_bUseButton2;                              // +0x2c enables OnMouseButton2
    int m_bEnabled;                                 // +0x30
    int m_nCurIndex;                                // +0x34 index into m_afValue
    float m_afValue[2];                             // +0x38
    NiPointer<CItemPickingHelper> m_spPicker;       // +0x40
    CAtlArray<CString> m_aPartNames;                // +0x48 attach part names of the item (ctor 0x140163230, RemoveAll 0x1402c2890)
    CAtlArray<CString> m_aMeshNames;                // +0x68 picking mesh names
    efd::Point2 m_kCursorStart;                     // +0x88
    efd::Point2 m_kScreenStart;                     // +0x90
    int m_n98;                                      // +0x98 cleared at the end of vfunc_38
    Unk_ItemCustomizeListener* m_pListener;         // +0xa0
    int m_bDragging2;                               // +0xa8
    int m_bDragging1;                               // +0xac
    int m_bDragging;                                // +0xb0
    int m_nPartCount;                               // +0xb4
};
MS2_CHECK_SIZE(CItemCustomizeController, 0xb8);
MS2_CHECK_OFFSET(CItemCustomizeController, m_nSlot, 0x10);
MS2_CHECK_OFFSET(CItemCustomizeController, m_spEquipItem, 0x18);
MS2_CHECK_OFFSET(CItemCustomizeController, m_afValue, 0x38);
MS2_CHECK_OFFSET(CItemCustomizeController, m_spPicker, 0x40);
MS2_CHECK_OFFSET(CItemCustomizeController, m_aPartNames, 0x48);
MS2_CHECK_OFFSET(CItemCustomizeController, m_aMeshNames, 0x68);
MS2_CHECK_OFFSET(CItemCustomizeController, m_kCursorStart, 0x88);
MS2_CHECK_OFFSET(CItemCustomizeController, m_n98, 0x98);
MS2_CHECK_OFFSET(CItemCustomizeController, m_pListener, 0xa0);
MS2_CHECK_OFFSET(CItemCustomizeController, m_nPartCount, 0xb4);
