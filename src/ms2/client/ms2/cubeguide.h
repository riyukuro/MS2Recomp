// cubeguide.h - cube placement guide wrappers (RTTI CCubeGuideWrapper, CNifCubeGuide, CKfmCubeGuide,
// CFittingDollCubeGuide). Shared by client\ms2\cubecraft.cpp#3 (the wrapper TU 0x1410af930..0x1410b2510, which
// defines their methods) and cubecraft.cpp#2-core (which constructs them: 0x1410a92c0 new CNifCubeGuide (0x40),
// 0x1410a9630 all variants). Header name assumed. Moved verbatim from cubecraft_3.h.
#pragma once
#include <afx.h>
#include <NiNode.h>
#include <NiTransform.h>
#include <egf/Entity.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/fittingdollpc.h"

extern const NiPoint3 g_kCubeGuideZero;  // 0x143b01a60, the zero vector as a NiPoint3 (trivial 12-byte copy); own name: DAT_143b01a60 has other types in includers

class CubeItemInfo;

// The four wrapper layouts are proved by constructors and deleting destructors.
class CCubeGuideWrapper : public CPtred {
public:
    CCubeGuideWrapper();
    virtual ~CCubeGuideWrapper();
    // @0x1410b2400
    virtual void vfunc_1() {}
    // @0x1410b2480
    virtual void vfunc_2(const NiPoint3&) {}
    // @0x1410b23d0
    virtual NiPoint3 vfunc_3() { return g_kCubeGuideZero; }
    // @0x1410b2430
    virtual void vfunc_4(const NiMatrix3&) {}
    // @0x1410b2390
    virtual NiMatrix3 vfunc_5() { return NiMatrix3::IDENTITY; }
    // @0x1410b2420
    virtual void vfunc_6(int) {}
    // @0x1410b2380
    virtual int vfunc_7() { return false; }
    // @0x1410b2410
    virtual void vfunc_8(float) {}
    // @0x1410b2440
    virtual void vfunc_9(float) {}
    // @0x1410b2360
    virtual void vfunc_10(NiNode*, int) {}
    // @0x1410b2370
    virtual void vfunc_11() {}
    // @0x1410b24a0
    virtual void vfunc_12() {}
    virtual NiTransform vfunc_13();
    virtual void vfunc_14(const NiTransform&);
    // @0x1410b2490
    virtual void vfunc_15(const CubeItemInfo*) {}
};
MS2_CHECK_SIZE(CCubeGuideWrapper, 0x18);

class CNifCubeGuide : public CCubeGuideWrapper {
public:
    CNifCubeGuide();
    virtual ~CNifCubeGuide();
    void vfunc_1() override;
    bool FUN_1410afc10(CString assetName);
    void vfunc_2(const NiPoint3&) override;
    NiPoint3 vfunc_3() override;
    void vfunc_4(const NiMatrix3&) override;
    NiMatrix3 vfunc_5() override;
    void vfunc_8(float) override;
    void vfunc_6(int) override;
    int vfunc_7() override;
    void vfunc_9(float) override;
    void vfunc_10(NiNode*, int) override;
    void vfunc_11() override;
    void vfunc_12() override;
    NiTransform vfunc_13() override;
    void vfunc_14(const NiTransform&) override;
    void vfunc_15(const CubeItemInfo*) override;
    int FUN_1410b0680();
    NiPointer<NiNode> node;
    MS2Ptr<CubeItemInfo> item;
    int pendingTexture;
    CString asset;
};
MS2_CHECK_SIZE(CNifCubeGuide, 0x40);
MS2_CHECK_OFFSET(CNifCubeGuide, item, 0x20);
MS2_CHECK_OFFSET(CNifCubeGuide, asset, 0x38);

class CFittingDollCubeGuide : public CCubeGuideWrapper {
public:
    CFittingDollCubeGuide();
    virtual ~CFittingDollCubeGuide();
    int FUN_1410b0ba0(int type, int index, int itemId);
    void vfunc_2(const NiPoint3&) override;
    NiPoint3 vfunc_3() override;
    void vfunc_4(const NiMatrix3&) override;
    NiMatrix3 vfunc_5() override;
    void vfunc_8(float) override;
    void vfunc_6(int) override;
    int vfunc_7() override;
    void vfunc_9(float) override;
    void vfunc_10(NiNode*, int) override;
    void vfunc_11() override;
    // FittingDollPC uses the GameObject interface at offset zero.
    efd::SmartPointer<FittingDollPC> doll;
};
MS2_CHECK_SIZE(CFittingDollCubeGuide, 0x20);

class CKfmCubeGuide : public CCubeGuideWrapper {
public:
    CKfmCubeGuide();
    virtual ~CKfmCubeGuide();
    int FUN_1410b1120(CString assetName);
    void vfunc_1() override;
    void vfunc_2(const NiPoint3&) override;
    NiPoint3 vfunc_3() override;
    void vfunc_4(const NiMatrix3&) override;
    NiMatrix3 vfunc_5() override;
    void vfunc_8(float) override;
    void vfunc_6(int) override;
    int vfunc_7() override;
    void vfunc_9(float) override;
    void vfunc_10(NiNode*, int) override;
    void vfunc_11() override;
    efd::SmartPointer<egf::Entity> entity;
    NiNode* parent;
    int pendingAlpha;
    float alpha;
    int rootReady;
};
MS2_CHECK_SIZE(CKfmCubeGuide, 0x38);
MS2_CHECK_OFFSET(CKfmCubeGuide, parent, 0x20);
