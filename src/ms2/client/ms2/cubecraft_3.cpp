// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\cubecraft.cpp#3
// MS2-RANGE: 0x1410af930-0x1410b2510 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$SmartPointer@VFittingDollPC@@@efd@@QEAA@PEAVFittingDollPC@@@Z 0x1410b1ed0 ; unique
// MS2-PIN: ??0?$SmartPointer@VFittingDollPC@@@efd@@QEAA@PEAVFittingDollPC@@@Z 0x1410b1ed0 ; prop
// MS2-PIN: ??0?$SmartPointer@VNiMaterialProperty@@@efd@@QEAA@PEAVNiMaterialProperty@@@Z 0x1410b1f20 ; unique
// MS2-PIN: ??0?$SmartPointer@VNiMaterialProperty@@@efd@@QEAA@PEAVNiMaterialProperty@@@Z 0x1410b1f20 ; prop
// MS2-PIN: ??1?$SmartPointer@VFittingDollPC@@@efd@@QEAA@XZ 0x1410b1f60 ; unique
// MS2-PIN: ??1?$SmartPointer@VFittingDollPC@@@efd@@QEAA@XZ 0x1410b1f60 ; prop
// MS2-PIN: ??1?$SmartPointer@VNiMaterialProperty@@@efd@@QEAA@XZ 0x1410b1fa0 ; unique
// MS2-PIN: ??1?$SmartPointer@VNiMaterialProperty@@@efd@@QEAA@XZ 0x1410b1fa0 ; prop
// MS2-PIN: ??4?$SmartPointer@VFittingDollPC@@@efd@@QEAAAEAV01@PEAVFittingDollPC@@@Z 0x1410b1fd0 ; prop
// MS2-PIN: ??4?$SmartPointer@VNiAlphaProperty@@@efd@@QEAAAEAV01@PEAVNiAlphaProperty@@@Z 0x1410b2050 ; unique
// MS2-PIN: ??4?$SmartPointer@VNiAlphaProperty@@@efd@@QEAAAEAV01@PEAVNiAlphaProperty@@@Z 0x1410b2050 ; prop
// MS2-PIN: ??4?$SmartPointer@VNiMaterialProperty@@@efd@@QEAAAEAV01@PEAVNiMaterialProperty@@@Z 0x1410b20c0 ; unique
// MS2-PIN: ??4?$SmartPointer@VNiMaterialProperty@@@efd@@QEAAAEAV01@PEAVNiMaterialProperty@@@Z 0x1410b20c0 ; prop
// MS2-PIN: ??4?$SmartPointer@VNiZBufferProperty@@@efd@@QEAAAEAV01@PEAVNiZBufferProperty@@@Z 0x1410b2130 ; unique
// MS2-PIN: ??4?$SmartPointer@VNiZBufferProperty@@@efd@@QEAAAEAV01@PEAVNiZBufferProperty@@@Z 0x1410b2130 ; prop
// MS2-PIN: ??8?$SmartPointer@VNiSourceTexture@@@efd@@QEBA_NPEAVNiSourceTexture@@@Z 0x1410b21a0 ; unique
// MS2-PIN: ??9?$SmartPointer@VFittingDollPC@@@efd@@QEBA_NPEAVFittingDollPC@@@Z 0x1410b21e0 ; unique
// MS2-PIN: ??9?$SmartPointer@VFittingDollPC@@@efd@@QEBA_NPEAVFittingDollPC@@@Z 0x1410b21e0 ; prop
// MS2-PIN: ??B?$SmartPointer@VFittingDollPC@@@efd@@QEBAPEAVFittingDollPC@@XZ 0x1410b2220 ; prop
// MS2-PIN: ??B?$SmartPointer@VNiMaterialProperty@@@efd@@QEBAPEAVNiMaterialProperty@@XZ 0x1410b2230 ; unique
// MS2-PIN: ??B?$SmartPointer@VNiMaterialProperty@@@efd@@QEBAPEAVNiMaterialProperty@@XZ 0x1410b2230 ; prop
// MS2-PIN: ??C?$SmartPointer@VFittingDollPC@@@efd@@QEBAPEAVFittingDollPC@@XZ 0x1410b2240 ; prop
// MS2-PIN: ??C?$SmartPointer@VNiMaterialProperty@@@efd@@QEBAPEAVNiMaterialProperty@@XZ 0x1410b2250 ; unique
// MS2-PIN: ??C?$SmartPointer@VNiMaterialProperty@@@efd@@QEBAPEAVNiMaterialProperty@@XZ 0x1410b2250 ; prop
// MS2-PIN: ??_GCCubeGuideWrapper@@UEAAPEAXI@Z 0x1410b2260 ; prop
// MS2-PIN: ??_GCFittingDollCubeGuide@@UEAAPEAXI@Z 0x1410b22a0 ; prop
// MS2-PIN: ??_GCKfmCubeGuide@@UEAAPEAXI@Z 0x1410b22e0 ; prop
// MS2-PIN: ??_GCNifCubeGuide@@UEAAPEAXI@Z 0x1410b2320 ; prop
// MS2-PIN: ?GetRotate@NiAVObject@@QEBAAEBVNiMatrix3@@XZ 0x1410b23c0 ; prop
// MS2-PINS-END tplpin

#ifdef __clang__
// The legacy Scaleform SDK uses register; it has no effect in this build.
#pragma clang diagnostic ignored "-Wregister"
#endif
#include "cubecraft_3.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <atlcoll.h>
#include <io.h>
#include <NiRenderObject.h>
#include <NiAlphaProperty.h>
#include <NiMaterialProperty.h>
#include <NiZBufferProperty.h>
#include <NiIntegerExtraData.h>
#include <NiSourceTexture.h>
#include <efd/AssetID.h>

// This scene traversal helper owns a 0x30-byte ATL list. Its constructor
// (14098cb80), traversal (14098e0d0), and destructor (14098cf00) are external.
class Unk_CubeSceneIterator {
public:
    Unk_CubeSceneIterator(NiAVObject*);
    ~Unk_CubeSceneIterator();
    NiAVObject* FUN_14098e0d0(bool descend);
private:
    ATL::CAtlList<NiAVObject*> pending;
};
MS2_CHECK_SIZE(Unk_CubeSceneIterator, 0x30);

class Unk_CubeResourceService {
public:
    NiPointer<NiAVObject> FUN_141551ea0(CString, int, int, int, int);
    NiPointer<NiSourceTexture> FUN_141553eb0(CString, const void*);
};
Unk_CubeResourceService* FUN_140a0afd0();
extern NiFixedString DAT_143ae50a0;
void FUN_140a0b300(NiAVObject*, bool);
bool FUN_14098dad0(NiAVObject*);
float FUN_140a38cd0(float);
void* FUN_140a44830();
void FUN_1401ce2f0(void*, const char*, const char*);
MS2Ptr<CItemData> FUN_14053f870(int);
CString FUN_1410280d0(int, CString);
NiPointer<NiAVObject> FUN_141423480(NiPointer<NiAVObject>, const CString&);
int FUN_1414232f0(NiPointer<NiAVObject>, NiPointer<NiSourceTexture>);
void* FUN_14052d220();
class Unk_CubeDownloadId {
public:
    Unk_CubeDownloadId(unsigned __int64);
    unsigned __int64 value;
};
MS2_CHECK_SIZE(Unk_CubeDownloadId, 8);
void FUN_1418845a0(void*, CubeItemInfo*, const Unk_CubeDownloadId&);
FittingDollPC* FUN_14121b590(int, int, int);
void FUN_140a0b1f0(const NiMatrix3&, NiPoint3&);
void FUN_140b86230(const NiPoint3&, NiMatrix3&);
int FUN_14123c660(GameObject*);
void FUN_14123c300(GameObject*, float);
void FUN_14121c170(GameObject*, NiFixedString);
void* FUN_1403ed2d0();
void FUN_141bbb7f0(void*, GameObject*, int);
void* FUN_1409670f0();
bool FUN_1411cf0b0(void*, efd::utf8string, efd::AssetID*, bool*);
class Unk_CubeEntityService {
public:
    efd::SmartPointer<egf::Entity> FUN_1411ce7c0(efd::utf8string, efd::utf8string,
                                              NiPoint3, NiPoint3, float, int, int);
};
NiAVObject* FUN_141b6efc0(egf::Entity*);
void FUN_140a38a50(egf::Entity*, unsigned, const NiPoint3&);
void FUN_1409618c0(egf::Entity*, unsigned, NiPoint3&);
void FUN_14098c6e0(egf::Entity*, unsigned, const bool&);
void FUN_1408a20a0(egf::Entity*, unsigned, bool&);
void FUN_1409457c0(egf::Entity*, unsigned, const float&);
void FUN_1411cf570(void*, egf::Entity*);

// @0x1410af930
CCubeGuideWrapper::CCubeGuideWrapper() {}
// @0x1410af970
CCubeGuideWrapper::~CCubeGuideWrapper() {}
// @0x1410af9a0
NiTransform CCubeGuideWrapper::vfunc_13() {
    NiTransform transform;
    transform.MakeIdentity();
    return transform;
}
MS2_REPLACE_METHOD(0x1410af9a0, CCubeGuideWrapper, vfunc_13, 102, 0xFBEB5F75);
// @0x1410afa10
void CCubeGuideWrapper::vfunc_14(const NiTransform&) {}
MS2_REPLACE_METHOD(0x1410afa10, CCubeGuideWrapper, vfunc_14, 11, 0x02239C70);

// @0x1410afa30
CNifCubeGuide::CNifCubeGuide() : node(NULL) {
    node = NULL;
    item.AssignRaw(new CubeItemInfo);
    pendingTexture = 0;
}
// @0x1410afb20
CNifCubeGuide::~CNifCubeGuide() { node = NULL; item = 0; }
// @0x1410afbc0
void CNifCubeGuide::vfunc_1() {
    if ((NiNode*)node != NULL && pendingTexture != 0) pendingTexture = FUN_1410b0680();
}
MS2_REPLACE_METHOD(0x1410afbc0, CNifCubeGuide, vfunc_1, 65, 0x6D059F2B);
// MS2-FUNCTIONAL: resource temporary cleanup and CString argument copies differ; load flags remain 0,5,0,0.
// @0x1410afc10
bool CNifCubeGuide::FUN_1410afc10(CString assetName) {
    asset = assetName;
    node = NiDynamicCast(NiNode, (NiAVObject*)FUN_140a0afd0()->FUN_141551ea0(assetName, 0, 5, 0, 0));
    return node != NULL;
}
MS2_REPLACE_METHOD(0x1410afc10, CNifCubeGuide, FUN_1410afc10, 315, 0xC8D83785);
// MS2-FUNCTIONAL: engine Point3 copy constructor differs; all three position components are preserved.
// @0x1410afd60
void CNifCubeGuide::vfunc_2(const NiPoint3& position) { node->SetTranslate(NiPoint3(position)); }
MS2_REPLACE_METHOD(0x1410afd60, CNifCubeGuide, vfunc_2, 64, 0xDF1C7335);
// @0x1410afdb0
NiPoint3 CNifCubeGuide::vfunc_3() { return node->GetTranslate(); }
MS2_REPLACE_METHOD(0x1410afdb0, CNifCubeGuide, vfunc_3, 68, 0xEDB011B7);
// @0x1410afe00
void CNifCubeGuide::vfunc_4(const NiMatrix3& rotation) { node->SetRotate(rotation); }
MS2_REPLACE_METHOD(0x1410afe00, CNifCubeGuide, vfunc_4, 49, 0x985BE112);
// @0x1410afe40
NiMatrix3 CNifCubeGuide::vfunc_5() { return node->GetRotate(); }
MS2_REPLACE_METHOD(0x1410afe40, CNifCubeGuide, vfunc_5, 68, 0x708C3DEF);
// No hook: engine inline constructors produce DLL-local RTTI objects.
// @0x1410afe90
void CNifCubeGuide::vfunc_8(float alpha) {
    Unk_CubeSceneIterator iterator(node);
    while (NiAVObject* object = iterator.FUN_14098e0d0(true)) {
        NiRenderObject* mesh = NiDynamicCast(NiRenderObject, object);
        if (mesh != NULL) {
            NiPointer<NiAlphaProperty> blend = NiDynamicCast(NiAlphaProperty, mesh->GetProperty(0));
            if ((NiAlphaProperty*)blend == NULL) {
                blend = NiNew NiAlphaProperty;
                mesh->AttachProperty(blend);
            }
            blend->SetAlphaBlending(true);
            NiPointer<NiMaterialProperty> material = NiDynamicCast(NiMaterialProperty, mesh->GetProperty(3));
            if ((NiMaterialProperty*)material == NULL) {
                material = NiNew NiMaterialProperty;
                mesh->AttachProperty(material);
            }
            material->SetAlpha(alpha);
            NiPointer<NiZBufferProperty> depth = static_cast<NiZBufferProperty*>(mesh->GetProperty(11));
            if ((NiZBufferProperty*)depth == NULL) {
                depth = NiNew NiZBufferProperty;
                mesh->AttachProperty(depth);
            }
            depth->SetZBufferWrite(false);
        }
    }
    node->UpdateProperties();
}
// @0x1410b0200
void CNifCubeGuide::vfunc_6(int visible) { FUN_140a0b300(node.operator->(), visible != 0); }
MS2_REPLACE_METHOD(0x1410b0200, CNifCubeGuide, vfunc_6, 67, 0xFA29BA64);
// @0x1410b0250
int CNifCubeGuide::vfunc_7() { return FUN_14098dad0(node.operator->()); }
MS2_REPLACE_METHOD(0x1410b0250, CNifCubeGuide, vfunc_7, 42, 0xA9AF37C9);
// MS2-FUNCTIONAL: real engine SetScale applies the same absolute-value operation again.
// @0x1410b2450
inline void FUN_1410b2450(NiAVObject* object, float scale) { object->SetScale(FUN_140a38cd0(scale)); }
// @0x1410b0280
void CNifCubeGuide::vfunc_9(float scale) { FUN_1410b2450(node.operator->(), scale); }
MS2_REPLACE_METHOD(0x1410b0280, CNifCubeGuide, vfunc_9, 51, 0x7BBA15A8);
// No hook: NiIntegerExtraData has an inline constructor and DLL-local vftable.
// MS2-FUNCTIONAL: unused inherited attachment flag is retained in the ABI; integer extra data stays zero.
// @0x1410b02c0
void CNifCubeGuide::vfunc_10(NiNode* parent, int) {
    parent->AttachChild(node, true);
    Unk_CubeSceneIterator iterator(node);
    while (NiAVObject* object = iterator.FUN_14098e0d0(true)) {
        NiRenderObject* mesh = NiDynamicCast(NiRenderObject, object);
        if (mesh != NULL) {
            NiIntegerExtraData* data = NiDynamicCast(NiIntegerExtraData, mesh->GetExtraData(DAT_143ae50a0));
            if (data == NULL) mesh->AddExtraData(DAT_143ae50a0, NiNew NiIntegerExtraData(0));
        }
    }
    node->UpdateEffects();
}
// MS2-FUNCTIONAL: equivalent null comparison and logging argument evaluation.
// @0x1410b0460
void CNifCubeGuide::vfunc_11() {
    if (node != NULL) {
        NiNode* parent = node->GetParent();
        if (parent != NULL) parent->DetachChild(node);
    } else {
        FUN_1401ce2f0(FUN_140a44830(), "CNifCubeGuide NULL Node Error. Asset Name : %s", (const char*)asset);
    }
}
MS2_REPLACE_METHOD(0x1410b0460, CNifCubeGuide, vfunc_11, 195, 0xD6C61EF1);
// @0x1410b0530
void CNifCubeGuide::vfunc_12() { node->UpdateProperties(); node->UpdateEffects(); node->Update(0.0f, true); }
MS2_REPLACE_METHOD(0x1410b0530, CNifCubeGuide, vfunc_12, 95, 0x610F8674);
// @0x1410b05a0
NiTransform CNifCubeGuide::vfunc_13() { return node->GetLocalTransform(); }
MS2_REPLACE_METHOD(0x1410b05a0, CNifCubeGuide, vfunc_13, 68, 0x529AED5F);
// @0x1410b05f0
void CNifCubeGuide::vfunc_14(const NiTransform& transform) { node->SetLocalTransform(transform); }
MS2_REPLACE_METHOD(0x1410b05f0, CNifCubeGuide, vfunc_14, 49, 0x4E58C2F2);
// @0x1410b0630
void CNifCubeGuide::vfunc_15(const CubeItemInfo* info) { item->FUN_1408b3700(info); pendingTexture = 1; }
MS2_REPLACE_METHOD(0x1410b0630, CNifCubeGuide, vfunc_15, 61, 0xD5D7119D);
// @0x1410b0680
// MS2-FUNCTIONAL: equivalent early returns with typed RAII temporaries.
int CNifCubeGuide::FUN_1410b0680() {
    if (item == NULL) return 0;
    if (item->FUN_1408b3860() == 0) return 0;
    MS2Ptr<CItemData> data = FUN_14053f870(item->itemId);
    if (data == NULL) return 0;
    CString textureName(data->cubeTextureName.mesh);
    if (textureName.GetLength() == 0) return 0;
    CString path = FUN_1410280d0(2, item->look->m_strUrl);
    if (_access(path, 4) == 0) {
        NiPointer<NiSourceTexture> texture = FUN_140a0afd0()->FUN_141553eb0(path, NULL);
        if (!(texture == NULL)) {
            NiPointer<NiAVObject> target = FUN_141423480(NiDynamicCast(NiAVObject, (NiNode*)node), textureName);
            if (target != NULL) {
                if (FUN_1414232f0(target, texture) != 0) return 0;
            }
            return 1;
        } else {
            FUN_1418845a0(FUN_14052d220(), item.get(), Unk_CubeDownloadId(0));
            return 1;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1410b0680, CNifCubeGuide, FUN_1410b0680, 1090, 0x4CEF5C21);

// @0x1410b0ad0
CFittingDollCubeGuide::CFittingDollCubeGuide() : doll(NULL) { doll = NULL; }
// @0x1410b0b40
CFittingDollCubeGuide::~CFittingDollCubeGuide() { doll = NULL; }
// @0x1410b0ba0
int CFittingDollCubeGuide::FUN_1410b0ba0(int type, int index, int itemId) {
    doll = FUN_14121b590(type, index, itemId);
    return doll != NULL;
}
MS2_REPLACE_METHOD(0x1410b0ba0, CFittingDollCubeGuide, FUN_1410b0ba0, 85, 0x86AA16EF);
// MS2-FUNCTIONAL: copying NiPoint3 into the inherited efd::Point3 value parameter emits extra copy code.
// @0x1410b0c00
void CFittingDollCubeGuide::vfunc_2(const NiPoint3& position) { doll->vfunc_19(position); }
MS2_REPLACE_METHOD(0x1410b0c00, CFittingDollCubeGuide, vfunc_2, 89, 0x5A33550F);
// @0x1410b0c60
NiPoint3 CFittingDollCubeGuide::vfunc_3() { return doll->vfunc_18(); }
MS2_REPLACE_METHOD(0x1410b0c60, CFittingDollCubeGuide, vfunc_3, 70, 0xEEBA0580);
// MS2-FUNCTIONAL: NiPoint3-to-efd::Point3 argument copy differs; Euler conversion and virtual slot are preserved.
// @0x1410b0cb0
void CFittingDollCubeGuide::vfunc_4(const NiMatrix3& rotation) {
    NiPoint3 angles;
    FUN_140a0b1f0(rotation, angles);
    doll->vfunc_21(angles);
}
MS2_REPLACE_METHOD(0x1410b0cb0, CFittingDollCubeGuide, vfunc_4, 117, 0xCB7A88BE);
// @0x1410b0d30
NiMatrix3 CFittingDollCubeGuide::vfunc_5() {
    NiMatrix3 rotation;
    NiPoint3 angles = doll->vfunc_20();
    FUN_140b86230(angles, rotation);
    return rotation;
}
MS2_REPLACE_METHOD(0x1410b0d30, CFittingDollCubeGuide, vfunc_5, 156, 0xA46EFA4C);
// @0x1410b0de0
void CFittingDollCubeGuide::vfunc_8(float alpha) { doll->vfunc_42(alpha, false); }
MS2_REPLACE_METHOD(0x1410b0de0, CFittingDollCubeGuide, vfunc_8, 70, 0x20335C49);
// @0x1410b0e30
void CFittingDollCubeGuide::vfunc_6(int visible) { doll->vfunc_23(visible); }
MS2_REPLACE_METHOD(0x1410b0e30, CFittingDollCubeGuide, vfunc_6, 63, 0x47D49A16);
// @0x1410b0e80
int CFittingDollCubeGuide::vfunc_7() { return doll->FUN_14123c660(); }
MS2_REPLACE_METHOD(0x1410b0e80, CFittingDollCubeGuide, vfunc_7, 39, 0xADF60E57);
// @0x1410b0eb0
void CFittingDollCubeGuide::vfunc_9(float scale) { doll->FUN_14123c280(scale); doll->FUN_14123c300(scale); }
MS2_REPLACE_METHOD(0x1410b0eb0, CFittingDollCubeGuide, vfunc_9, 82, 0x9FE77C47);
// @0x1410b0f10
void CFittingDollCubeGuide::vfunc_10(NiNode* parent, int attachName) {
    if (attachName != 0) doll->FUN_14121c170(parent->GetName());
}
MS2_REPLACE_METHOD(0x1410b0f10, CFittingDollCubeGuide, vfunc_10, 119, 0x619129BF);
// @0x1410b0f90
void CFittingDollCubeGuide::vfunc_11() { doll->vfunc_23(1); FUN_141bbb7f0(FUN_1403ed2d0(), doll, 1); }
MS2_REPLACE_METHOD(0x1410b0f90, CFittingDollCubeGuide, vfunc_11, 109, 0xC273D985);

// @0x1410b1010
CKfmCubeGuide::CKfmCubeGuide() : entity(NULL) {
    entity = NULL; parent = NULL; pendingAlpha = 0; alpha = 1.0f; rootReady = 0;
}
// @0x1410b10b0
CKfmCubeGuide::~CKfmCubeGuide() { entity = NULL; parent = NULL; }
// MS2-FUNCTIONAL: real engine string/point constructors emit different temporaries; member hidden-return ABI is preserved.
// @0x1410b1120
int CKfmCubeGuide::FUN_1410b1120(CString assetName) {
    bool isActor = false;
    efd::AssetID id;
    if (!FUN_1411cf0b0(FUN_1409670f0(), efd::utf8string((const char*)assetName), &id, &isActor)) return 0;
    efd::utf8string model("MS2MeshNoPhysX");
    if (isActor) model = "MS2Actor";
    entity = static_cast<Unk_CubeEntityService*>(FUN_1409670f0())->FUN_1411ce7c0(
        model, id.GetURN(), NiPoint3::ZERO, NiPoint3::ZERO, 1.0f, 0, 1);
    if (entity != NULL) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1410b1120, CKfmCubeGuide, FUN_1410b1120, 762, 0xBCF2509E);
// No hook: NiIntegerExtraData has an inline constructor and DLL-local vftable.
// MS2-FUNCTIONAL: typed engine temporaries and raw-pointer getter differ; property IDs and initialization order are preserved.
// @0x1410b1420
void CKfmCubeGuide::vfunc_1() {
    if (entity != NULL && parent != NULL) {
        NiPoint3 position = parent->GetWorldTranslate();
        FUN_140a38a50(entity.operator->(), 0xfd95ca52, position);
        NiPoint3 direction;
        NiMatrix3 rotation = parent->GetWorldRotate();
        FUN_140a0b1f0(rotation, direction);
        FUN_140a38a50(entity.operator->(), 0x68c7c29d, direction);
    }
    if (rootReady == 0) {
        NiPointer<NiNode> root = NiDynamicCast(NiNode, FUN_141b6efc0(entity.data()));
        if (root != NULL) {
            rootReady = 1;
            if (pendingAlpha != 0) vfunc_8(alpha);
            Unk_CubeSceneIterator iterator(root);
            while (NiAVObject* object = iterator.FUN_14098e0d0(true)) {
                NiRenderObject* mesh = NiDynamicCast(NiRenderObject, object);
                if (mesh != NULL) {
                    NiIntegerExtraData* data = NiDynamicCast(NiIntegerExtraData, mesh->GetExtraData(DAT_143ae50a0));
                    if (data == NULL) {
                        data = NiNew NiIntegerExtraData(0);
                        mesh->AddExtraData(DAT_143ae50a0, data);
                    }
                }
            }
        }
    }
}
// @0x1410b1710
void CKfmCubeGuide::vfunc_2(const NiPoint3& position) { FUN_140a38a50(entity.operator->(), 0xfd95ca52, position); }
MS2_REPLACE_METHOD(0x1410b1710, CKfmCubeGuide, vfunc_2, 54, 0x5F732E7A);
// @0x1410b1750
NiPoint3 CKfmCubeGuide::vfunc_3() { NiPoint3 position; FUN_1409618c0(entity.operator->(), 0xfd95ca52, position); return position; }
MS2_REPLACE_METHOD(0x1410b1750, CKfmCubeGuide, vfunc_3, 93, 0xB16325BF);
// @0x1410b17c0
void CKfmCubeGuide::vfunc_4(const NiMatrix3& rotation) {
    NiPoint3 angles;
    FUN_140a0b1f0(rotation, angles);
    FUN_140a38a50(entity.operator->(), 0x68c7c29d, angles);
}
MS2_REPLACE_METHOD(0x1410b17c0, CKfmCubeGuide, vfunc_4, 79, 0x6E878803);
// @0x1410b1820
NiMatrix3 CKfmCubeGuide::vfunc_5() {
    NiPoint3 angles;
    FUN_1409618c0(entity.operator->(), 0x68c7c29d, angles);
    NiMatrix3 rotation;
    FUN_140b86230(angles, rotation);
    return rotation;
}
MS2_REPLACE_METHOD(0x1410b1820, CKfmCubeGuide, vfunc_5, 155, 0xFB41EE8F);
// No hook: engine inline constructors produce DLL-local RTTI objects.
// MS2-FUNCTIONAL: typed traversal temporaries differ; deferred alpha and all property flags are preserved.
// @0x1410b18d0
void CKfmCubeGuide::vfunc_8(float value) {
    NiPointer<NiNode> root = NiDynamicCast(NiNode, FUN_141b6efc0(entity.data()));
    if (root == NULL) { pendingAlpha = 1; alpha = value; }
    else {
        Unk_CubeSceneIterator iterator(root);
        while (NiAVObject* object = iterator.FUN_14098e0d0(true)) {
            NiRenderObject* mesh = NiDynamicCast(NiRenderObject, object);
            if (mesh != NULL) {
                if (mesh != NULL) {
                    NiPointer<NiAlphaProperty> blend = NiDynamicCast(NiAlphaProperty, mesh->GetProperty(0));
                    if ((NiAlphaProperty*)blend == NULL) { blend = NiNew NiAlphaProperty; mesh->AttachProperty(blend); }
                    blend->SetAlphaBlending(true);
                    NiPointer<NiMaterialProperty> material = NiDynamicCast(NiMaterialProperty, mesh->GetProperty(3));
                    if ((NiMaterialProperty*)material == NULL) { material = NiNew NiMaterialProperty; mesh->AttachProperty(material); }
                    material->SetAlpha(value);
                    NiPointer<NiZBufferProperty> depth = static_cast<NiZBufferProperty*>(mesh->GetProperty(11));
                    if ((NiZBufferProperty*)depth == NULL) { depth = NiNew NiZBufferProperty; mesh->AttachProperty(depth); }
                    depth->SetZBufferWrite(false);
                }
            }
        }
        root->UpdateProperties();
        pendingAlpha = 0;
        alpha = value;
    }
}
// MS2-FUNCTIONAL: bool temporary lowering differs; zero visibility still sets the hidden property.
// @0x1410b1ce0
void CKfmCubeGuide::vfunc_6(int visible) { bool hidden = visible == 0; FUN_14098c6e0(entity.operator->(), 0xa0b6b179, hidden); }
MS2_REPLACE_METHOD(0x1410b1ce0, CKfmCubeGuide, vfunc_6, 81, 0x4D8BA781);
// MS2-FUNCTIONAL: bool-to-int return lowering differs; the property output remains uninitialized before the engine call.
// @0x1410b1d40
int CKfmCubeGuide::vfunc_7() { bool hidden; FUN_1408a20a0(entity.operator->(), 0xa0b6b179, hidden); return !hidden; }
MS2_REPLACE_METHOD(0x1410b1d40, CKfmCubeGuide, vfunc_7, 75, 0xED65222D);
// @0x1410b1da0
void CKfmCubeGuide::vfunc_9(float scale) { FUN_1409457c0(entity.operator->(), 0x2d7cad2d, scale); }
MS2_REPLACE_METHOD(0x1410b1da0, CKfmCubeGuide, vfunc_9, 55, 0x6A503D0B);
// MS2-FUNCTIONAL: unused inherited attachment argument and equivalent engine smart-pointer tests differ.
// @0x1410b1de0
void CKfmCubeGuide::vfunc_10(NiNode* node, int) {
    parent = node;
    NiPointer<NiNode> root = NiDynamicCast(NiNode, FUN_141b6efc0(entity.data()));
    if (root != NULL) root->UpdateEffects();
}
MS2_REPLACE_METHOD(0x1410b1de0, CKfmCubeGuide, vfunc_10, 145, 0xBA55F349);
// MS2-FUNCTIONAL: named pointer temporary uses the bound engine getter before removal.
// @0x1410b1e80
void CKfmCubeGuide::vfunc_11() { egf::Entity* value = entity.data(); FUN_1411cf570(FUN_1409670f0(), value); parent = NULL; }
MS2_REPLACE_METHOD(0x1410b1e80, CKfmCubeGuide, vfunc_11, 70, 0x6286F1B9);

class Unk_CubeDisplayLookup {
public:
    int FUN_1410b24b0(unsigned, unsigned);
    bool FUN_1410b4ba0(const int&, int&);
};
int FUN_1410b2790(unsigned, unsigned);
// MS2-FUNCTIONAL: typed map lookup changes register scheduling; packed key and INT_MIN miss result are preserved.
// @0x1410b24b0
int Unk_CubeDisplayLookup::FUN_1410b24b0(unsigned a, unsigned b) {
    int value = INT_MIN;
    int key = FUN_1410b2790(a, b);
    FUN_1410b4ba0(key, value);
    return value;
}
MS2_REPLACE_METHOD(0x1410b24b0, Unk_CubeDisplayLookup, FUN_1410b24b0, 75, 0x218D804F);
