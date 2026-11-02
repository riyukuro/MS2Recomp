// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Rendering glue: CObjectShadow (blob shadow quad under a character: mesh + properties + fade).
// MS2-UNIT: ?\objectshadow.cpp
// MS2-RANGE: 0x14160fb10-0x1416113d8 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\objectshadow.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <efd/SmartPointer.h>
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/equipmodel.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_1416561a0
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940
#include "ms2/client/ms2/equipment.h"
#include "ms2/commonfiles/os.h"   // C3: TSingleton
#include "ms2/placeholder/nipoint3.h"   // C3: Unk_NiPoint3 / Unk_NiMatrix3 (the basis temporaries)
#include <efd/MemoryDefines.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiFixedString.h>
#include <NiCommonSemantics.h>
#include <NiColor.h>
#include <NiPoint2.h>
#include <NiPoint3.h>
#include <NiBound.h>
#include <NiTransform.h>
#include <NiAlphaProperty.h>
#include <NiVertexColorProperty.h>
#include <NiFogProperty.h>
#include <NiZBufferProperty.h>
#include <NiTexturingProperty.h>
#include <NiMaterialProperty.h>

// return types of the getters this unit calls
class Unk_ResourceMgr;
class Unk_SingletonObj;

// ---- unit-local placeholders (names invented; layouts pinned) ------------------------------------------------------------
// Fake virtual-slot classes for the objects that are only called through their vftables here.
class Unk_ShadowOwner { public:                                    // m_pOwner (+0x40)
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual int vfunc_25(); };                                      // 0xc8
class Unk_ShadowModel { public:                                     // object reachable from a mesh element (+0x70)
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void* vfunc_14(); };                                    // 0x70
class Unk_ShadowIter { public:                                      // elements of the iterated container (slot 32 = +0x100)
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void vfunc_32(char flag); };                            // +0x100 (0x141610573 call [rax+0x100])

class CMesh {                                                       // base mesh, ctor 0x14147af80 / dtor 0x14147b330 (unrecovered)
public:
    CMesh(bool bNormals, bool bColors, unsigned int nUVSets, unsigned int nMaxVerts, unsigned int nMaxTris, unsigned char ucFlags);
    virtual ~CMesh();
    virtual void vfunc_1();                                         // 0x141d16bf0
    static void operator delete(void*, size_t);                     // efd::MemObject::operator delete 0x14208a8f0
    void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28;
public:
    class NiMesh* GetMesh() const;   // C3: was free FUN_140a0afe0
public:
    void SetVertexCount(unsigned int);   // C3: was free FUN_14147b8b0
public:
    void SetTriangleCount(unsigned int);   // C3: was free FUN_14147b9c0
    bool SetQuad(unsigned int i, unsigned short a, unsigned short b, unsigned short c, unsigned short d);   // C3: was free FUN_14147b6d0
    void* Lock(const NiFixedString& kSemantic, unsigned int uiIndex, unsigned char ucLockMask);         // C3: was free FUN_14147b7f0
    void Unlock(const NiFixedString& kSemantic, unsigned int uiIndex, unsigned char ucLockMask);        // C3: was free FUN_14147b850
};
MS2_CHECK_SIZE(CMesh, 0x30);

class CObjectShadow : public CMesh {
public:
    CObjectShadow(void* owner, int lodHi, int lodLo);
    CObjectShadow(void* owner, int lodHi, int lodLo, float radius);
    CObjectShadow(void* owner, int lodHi, int lodLo, float radius, float zOffset);
    virtual ~CObjectShadow();
    bool m_bEnabled;       // +0x30
    bool m_bFlag31;
    bool m_bFlag32;
    bool m_bDirty;         // +0x33
    bool m_bShown;         // +0x34
    bool m_bVisible;       // +0x35
    float m_fZOffset;      // +0x38
    Unk_ShadowOwner* m_pOwner;   // +0x40
    efd::SmartPointer<NiNode> m_node;    // +0x48
    int m_lodHi;           // +0x50
    int m_lodLo;           // +0x54
};
MS2_CHECK_SIZE(CObjectShadow, 0x58);
MS2_CHECK_OFFSET(CObjectShadow, m_pOwner, 0x40);
MS2_CHECK_OFFSET(CObjectShadow, m_node, 0x48);

struct Unk_Colc { float r, g, b; };   // the colour parameter of FUN_1416113a0 (an NiColor at the call)
class Unk_WsC_GameObj : public GameObject {};   // WorldService's game object results
class CNifLoadingService   // C3: member view (was free FUN_141552f90)
{
public:
    efd::SmartPointer<NiTexture> GetTexture(CString strPath, int nClass);
};
// ---- unrecovered neighbours -------------------------------------------------------------------------------------------------
extern float DAT_1439f81fc; extern float DAT_1439f8200; extern float DAT_1439f81f4; extern float DAT_1439f81f8; extern float DAT_1439f8204;
extern int DAT_1439f8208;   extern int DAT_143ae2960;   extern char DAT_143a08cd8;
void FUN_1416106e0(CObjectShadow* self, void* owner, int lodHi, int lodLo, float radius, float zOffset);
void FUN_141610490();
void FUN_1416105c0(CObjectShadow* self);
void FUN_141611370(void* obj, bool flag);
void FUN_1416113a0(void* mat, const Unk_Colc& color);
int FUN_140ae1c10();                                  // current quality level
void* FUN_1413f9870();class MS2LightService   // C3: member view for the former free stand-ins
{
public:
    void UpdateLightShadows();
};
class CGraphicOptionTable   // C3: member view for the former free stand-ins
{
public:
    int GetShadowOption(int);
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void FUN_141bd2db0(ATL::CAtlList<efd::SmartPointer<class Unk_WsC_GameObj> >* out, int (*filter)(class Unk_WsC_GameObj*));
    static class WorldService* GetInstance();
    void FUN_141bd30f0(char);
};
class CEffectService
{
public:
    class NiNode* GetLeastLoadedRoot();
};
class Unk_ResourceMgr* FUN_140a0afd0();   // C3: was FUN_140a0afd0
void FUN_140a0b330(void* obj, bool b, short flags);
class CMainSystem   // C3: member view for the former free stand-ins
{
public:
    double FUN_141473280();
};
namespace egf { class Entity; }   // C3: FUN_141b6efc0 takes the real egf::Entity*
NiAVObject* FUN_141b6efc0(egf::Entity* p);void FUN_141567540(class NiAVObject*, bool);   // C3: was FUN_141567540
class CEquipItem   // C3: member view for the former free stand-ins
{
public:
    int FUN_1411dc0d0();
    void GetModels(CAtlArray<MS2Ptr<CEquipModel> >& arr);   // C3: was free FUN_1411dcc80
};
void* FUN_141200ab0(class CEquipModel*);   // C3: was FUN_141200ab0
class Unk_AvModeSvc* FUN_1409f7c90();   // C3: was FUN_1409f7c90
class Unk_FsOptimizer   // C3: member view for the former free stand-ins
{
public:
    int FUN_140ddcc90();
};
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

// @0x14160fb10
CObjectShadow::CObjectShadow(void* owner, int lodHi, int lodLo)
    : CMesh(false, false, 1, 4, 2, 0x12), m_node(0)
{
    FUN_1416106e0(this, owner, lodHi, lodLo, DAT_1439f81fc, DAT_1439f8200);
}

// @0x14160fbd0
CObjectShadow::CObjectShadow(void* owner, int lodHi, int lodLo, float radius)
    : CMesh(false, false, 1, 4, 2, 0x12), m_node(0)
{
    FUN_1416106e0(this, owner, lodHi, lodLo, radius, DAT_1439f8200);
}

// @0x14160fc90
CObjectShadow::CObjectShadow(void* owner, int lodHi, int lodLo, float radius, float zOffset)
    : CMesh(false, false, 1, 4, 2, 0x12), m_node(0)
{
    FUN_1416106e0(this, owner, lodHi, lodLo, radius, zOffset);
}

// @0x14160fd50
CObjectShadow::~CObjectShadow()
{
    NiNode* node = m_node->GetParent();
    if (node != 0) {
        node->DetachChild(m_node);
    }
}

// @0x14160fe10
void FUN_14160fe10(CObjectShadow* self, bool v)
{
    if (self->m_bEnabled != v) { self->m_bEnabled = v; self->m_bDirty = true; }
}

// @0x14160fe50
void FUN_14160fe50(CObjectShadow* self, bool v) { self->m_bFlag31 = v; }

// @0x14160fe70
void FUN_14160fe70(CObjectShadow* self, bool v)
{
    if (self->m_bFlag32 != v) { self->m_bFlag32 = v; self->m_bDirty = true; }
}

// @0x14160feb0   per-frame update: position/orient the shadow under the character, fade by distance, push LOD visibility to the owner's models
void FUN_14160feb0(CObjectShadow* self, int active, const void* pos, const void* dir, float dt, bool force)
{
    FUN_1416105c0(self);
    if (self->m_bVisible != 0 && active != 0) {
        float one = 1.0f;
        float fade;
        NiTransform xf;
        xf.m_Translate = *(const efd::Point3*)pos;
        xf.m_Translate.z = xf.m_Translate.z + self->m_fZOffset;
        Unk_NiPoint3 p110(*(const Vector3*)&DAT_143a08cd8);
        Unk_NiPoint3 p148(((const Vector3*)dir)->FUN_140a00e10(*(const Vector3*)&p110));
        ((Vector3*)&p148)->FUN_140968990();
        Unk_NiPoint3 p130(((const Vector3*)&p148)->FUN_140a00e10(*(const Vector3*)dir));
        ((Vector3*)&p130)->FUN_140968990();
        Unk_NiPoint3 p100(*(const Vector3*)dir);
        *(Unk_NiMatrix3*)&xf.m_Rotate = Unk_NiMatrix3(p130, p148, p100);
        if (DAT_1439f81f4 < 0.001f) {
            fade = DAT_1439f81f8;
        } else {
            fade = one - efd::Clamp(dt / DAT_1439f81f4, 0.0f, 1.0f) * (one - DAT_1439f81f8);
        }
        float scale = fade;
        xf.m_fScale = scale;
        self->m_node->SetLocalFromWorldTransform(xf);
        self->m_node->Update((float)TSingleton<CMainSystem>::GetInstance()->FUN_141473280(), true);
        NiMaterialProperty* prop = (NiMaterialProperty*)NiObject::DynamicCast(&NiMaterialProperty::ms_RTTI, self->GetMesh()->GetProperty(3));
        if (prop != 0) {
            float alpha = DAT_1439f8204 * scale;
            prop->SetAlpha(alpha);
            self->GetMesh()->UpdateProperties();
        }
        self->m_node->SetAppCulled(false);
    } else {
        self->m_node->SetAppCulled(true);
    }
    if (force || self->m_bDirty != 0) {
        void* h = FUN_141b6efc0(reinterpret_cast<GameObject*>(self->m_pOwner)->FUN_14123c410());
        if (h != 0) {
            FUN_141567540((class NiAVObject*)(h), self->m_bShown);
            self->m_bDirty = false;
        }
        void* o = efd::DynamicCast<PC, GameObject>(reinterpret_cast<GameObject*>(self->m_pOwner));
        if (o != 0) {
            POSITION pos2;
            ATL::CAtlList<MS2Ptr<CEquipItem> > list(10);
            reinterpret_cast<CEquipment*>(reinterpret_cast<PC*>(o)->FUN_1416561a0())->CollectShownItems(list);
            for (pos2 = list.GetHeadPosition(); pos2 != 0; list.GetNext(pos2)) {
                MS2Ptr<CEquipItem>& elem = list.GetAt(pos2);
                if (elem->FUN_1411dc0d0() != 0) {
                    CAtlArray<MS2Ptr<CEquipModel> > arr;
                    elem->GetModels(arr);
                    unsigned i;
                    for (i = 0; i < arr.GetCount(); ++i) {
                        MS2Ptr<CEquipModel>& e = arr[i];
                        if (*(int*)((char*)FUN_141200ab0(e.operator->()) + 0x20) == 0) {
                            Unk_ShadowModel* model = (Unk_ShadowModel*)e.operator->();
                            FUN_141567540((class NiAVObject*)(model->vfunc_14()), self->m_bShown);
                        }
                    }
                } else {
                    self->m_bDirty = true;
                }
            }
        }
    }
}

// @0x141610410
void FUN_141610410(int v)
{
    int before = FUN_140ae1c10();
    DAT_1439f8208 = v;
    int after = FUN_140ae1c10();
    if (before != after) FUN_141610490();
}

// @0x141610450
void FUN_141610450(int v)
{
    int before = FUN_140ae1c10();
    DAT_143ae2960 = v;
    int after = FUN_140ae1c10();
    if (before != after) FUN_141610490();
}

// @0x141610490   re-apply shadow quality: enable the global shadow manager when the quality level allows, and refresh all registered shadows
void FUN_141610490()
{
    int need;
    int level;
    POSITION pos;
    level = FUN_140ae1c10();
    ((class MS2LightService*)(void*)(FUN_1413f9870()))->UpdateLightShadows();
    need = TSingleton<CGraphicOptionTable>::GetInstance()->GetShadowOption(5);
    WorldService::GetInstance()->FUN_141bd30f0(level >= need);
    ATL::CAtlList<efd::SmartPointer<Unk_WsC_GameObj> > list(10);
    WorldService::GetInstance()->FUN_141bd2db0(&list, 0);
    for (pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos)) {
        efd::SmartPointer<Unk_WsC_GameObj>& entry = list.GetAt(pos);
        Unk_ShadowIter* it = (Unk_ShadowIter*)entry.operator->();
        it->vfunc_32(1);
    }
}

// @0x1416105a0
void FUN_1416105a0(float v) { DAT_1439f8204 = v; }

// @0x1416105c0   decide shown/visible by LOD level and owner state
void FUN_1416105c0(CObjectShadow* self)
{
    bool shown = false;
    bool visible = false;
    int lod = FUN_140ae1c10();
    if (lod >= self->m_lodHi) {
        if (self->m_bEnabled != 0 && self->m_bFlag31 != 0)
            shown = true;
        if (shown != self->m_bShown)
            self->m_bDirty = true;
    } else {
        if (self->m_lodLo <= lod && lod < self->m_lodHi) {
            if (self->m_bEnabled != 0 && self->m_bFlag32 == 0 && self->m_bFlag31 != 0)
                visible = true;
            if (self->m_pOwner != 0 && self->m_pOwner->vfunc_25() != 0) {
                if (((class Unk_FsOptimizer*)(void*)(((void*)FUN_1409f7c90())))->FUN_140ddcc90() == 0)
                    visible = false;
            }
        }
    }
    self->m_bShown = shown;
    self->m_bVisible = visible;
}

// @0x1416106e0   build the shadow quad mesh, its render properties and the scene node
void FUN_1416106e0(CObjectShadow* self, void* owner, int lodHi, int lodLo, float radius, float zOffset)
{
    self->m_pOwner = (Unk_ShadowOwner*)owner;
    self->m_lodHi = lodHi;
    self->m_lodLo = lodLo;
    self->m_bEnabled = true;
    self->m_bFlag32 = false;
    self->m_bShown = false;
    self->m_bVisible = false;
    self->m_fZOffset = zOffset;
    self->m_bFlag31 = true;
    float r = radius / 2.0f;

    NiPoint3* verts = (NiPoint3*)self->Lock(NiCommonSemantics::POSITION(), 0, 2);   // 4 x NiPoint3
    if (verts != 0) {
        verts[0] = NiPoint3(-r, -r, 0.0f);
        verts[1] = NiPoint3(r, -r, 0.0f);
        verts[2] = NiPoint3(r, r, 0.0f);
        verts[3] = NiPoint3(-r, r, 0.0f);
        self->Unlock(NiCommonSemantics::POSITION(), 0, 2);
    }
    NiPoint2* uv = (NiPoint2*)self->Lock(NiCommonSemantics::TEXCOORD(), 0, 2);   // 4 x NiPoint2
    if (uv != 0) {
        uv[0] = NiPoint2(0.0f, 0.0f);
        uv[1] = NiPoint2(0.0f, 1.0f);
        uv[2] = NiPoint2(1.0f, 1.0f);
        uv[3] = NiPoint2(1.0f, 0.0f);
        self->Unlock(NiCommonSemantics::TEXCOORD(), 0, 2);
    }
    self->SetQuad(0, 0, 1, 2, 3);

    {
        NiFixedString name("Character Shadow");
        self->GetMesh()->SetName(name);
    }

    efd::SmartPointer<NiTexture> tex = ((CNifLoadingService*)FUN_140a0afd0())->GetTexture(*(CString*)((char*)((void*)FUN_1401d31f0()) + 0xf0), 1);
    NiTexturingProperty* texProp = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty;
    texProp->SetBaseTexture(tex);
    self->GetMesh()->AttachProperty(texProp);

    efd::SmartPointer<NiAlphaProperty> alphaPtr = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaProperty;
    alphaPtr->SetAlphaBlending(true);
    self->GetMesh()->AttachProperty(alphaPtr);

    NiVertexColorProperty* vcol = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
    vcol->SetSourceMode(NiVertexColorProperty::SOURCE_IGNORE);
    vcol->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
    self->GetMesh()->AttachProperty(vcol);

    efd::SmartPointer<NiMaterialProperty> matPtr = new (efd::MemHint(efd::MemHint::NONE)) NiMaterialProperty;
    matPtr->SetDiffuseColor(NiColor(0.0f, 0.0f, 0.0f));
    matPtr->SetAmbientColor(NiColor(0.0f, 0.0f, 0.0f));
    FUN_1416113a0(matPtr.operator->(), (const Unk_Colc&)(const NiColor&)NiColor(0.0f, 0.0f, 0.0f));
    matPtr->SetEmittance(NiColor(1.0f, 1.0f, 1.0f));
    matPtr->SetAlpha(DAT_1439f8204);
    self->GetMesh()->AttachProperty(matPtr);

    NiFogProperty* fog = new (efd::MemHint(efd::MemHint::NONE)) NiFogProperty;
    fog->SetFog(false);
    self->GetMesh()->AttachProperty(fog);

    efd::SmartPointer<NiZBufferProperty> zPtr = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
    zPtr->SetZBufferWrite(false);
    self->GetMesh()->AttachProperty(zPtr);

    self->SetVertexCount(4);
    self->SetTriangleCount(6);
    NiBound bound;
    bound.SetCenterAndRadius(NiPoint3(0.0f, 0.0f, 0.0f), r);
    ((NiMesh*)self->GetMesh())->SetModelBound(bound);

    self->m_node = new (efd::MemHint(efd::MemHint::NONE)) NiNode(0);
    self->m_node->AttachChild(self->GetMesh(), false);
    self->m_node->SetAppCulled(true);
    self->m_bDirty = true;
    NiNode* scene = TSingleton<CEffectService>::GetInstance()->GetLeastLoadedRoot();
    scene->AttachChild(self->m_node, true);
    self->m_node->UpdateEffects();
    self->m_node->UpdateProperties();
    self->m_node->Update((float)TSingleton<CMainSystem>::GetInstance()->FUN_141473280(), true);
    FUN_141611370(((void*)self->GetMesh()), 0);
}

// @0x1416112d0 (scalar deleting destructor: emitted from the vftable)

// @0x141611330
void FUN_141611330(void* obj, bool flag) { FUN_140a0b330(obj, !flag, 0x40); }

// @0x141611370
void FUN_141611370(void* obj, bool flag) { FUN_141611330(obj, flag); }

// @0x1416113a0
void FUN_1416113a0(void* mat, const Unk_Colc& color)
{
    *(Unk_Colc*)((char*)mat + 0x4c) = color;
    ((NiMaterialProperty*)mat)->SetChanged(true);
}
