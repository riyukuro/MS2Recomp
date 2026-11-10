// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Outline render-list pre-processor (NiShaderSortProcessor subclass).
// MS2-UNIT: ?\ms2outlinepreprocessor.cpp
// MS2-RANGE: 0x1414d3120-0x1414d4e20 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2outlinepreprocessor.h"
#include "ms2materialswapprocessor.h"
#include <atlcoll.h>
#include "ms2/placeholder/ms2color.h"
#include <NiRenderObject.h>
#include <NiMaterial.h>
#include <NiAVObject.h>
#include <efd/FixedString.h>
#include <efd/Color.h>
#include <NiColorExtraData.h>
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#include <NiNode.h>
#include <NiStringExtraData.h>
#include <NiPSParticleSystem.h>
#include "ms2/client/ms2/effectservice.h"   // C3: EffectNode::ms_RTTI
#include "ms2/client/ms2/postprocessing/postprocessingservice.h"   // C3: PostProcessingService::SetStepActive

#include "ms2/client/ms2/fielddatacli.h"   // Unk_Vec3Cli: the out-of-line colour ctor 0x140a56db0 (was a local Unk_Colc view)

// ---- out-of-unit callees ----
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
namespace egf { class Entity; }   // C3: FUN_141b6efc0 takes the real egf::Entity*
class GameObject { public: egf::Entity* GetEntity(); };   // C3: unit-local view
   NiAVObject* FUN_141b6efc0(egf::Entity* a);
class NiMaterialLibrary   // C3: member view for the former free stand-ins
{
public:
    static class NiMaterial* CreateMaterial(class NiFixedString const&);
};
unsigned int Unk_ColorValue(struct Unk_ConstColor const&);   // C3: was FUN_14056d500
bool UpdateGlobalShaderConstantFloats(class NiFixedString&, float const*, int);   // C3: was FUN_1409a5770
bool FUN_14098dfc0(class NiAVObject*);   // C3: was FUN_14098dfc0
bool FUN_141568c90(class NiRenderObject*);   // C3: was FUN_141568c90
unsigned int FUN_141568dc0(class NiAVObject*);   // C3: was FUN_141568dc0
void FUN_141568df0(class NiAVObject*);   // C3: was FUN_141568df0
class CMeshUVPicker   // C3: member view for the former free stand-ins
{
public:
    static void SetColorExtraData(class NiObjectNET*, class NiFixedString const&, class NiColorA const&);
};
class Unk_AeFeatureMgr   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};
void FUN_1410479a0(class NiObjectNET*, class NiFixedString const&, class NiColor const&);   // C3: was FUN_1410479a0
unsigned int FUN_140d96630(class NiAVObject*);   // C3: was FUN_140d96630
class Unk_NodeQueue   // C3: member view (alphaanimation.cpp's breadth-first node queue)
{
public:
    Unk_NodeQueue(NiAVObject* pRoot);                       // 0x14098cb80
    ~Unk_NodeQueue();                                       // 0x14098cf00
    void AddChildren(class NiNode*);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};
MS2_CHECK_SIZE(Unk_NodeQueue, 0x30);
typedef Unk_NodeQueue Unk_AeSceneIter;   // C3: was a local stand-in for Unk_NodeQueue
// 0x14098da10 = CAtlList<NiAVObject*>::FreeNode (alphaanimation.cpp), called by RemoveHead below
extern int DAT_143ae2b34; extern char DAT_143a09680;
extern NiFixedString DAT_143ae50e0, DAT_143ae50e8, DAT_143ae50f0, DAT_143ae51b8, DAT_143ae53c8, DAT_143ae5210;

typedef CAtlMap<NiAVObject*, NiAVObject*> OutlineMap;


void CollectOutlineTargets(OutlineMap& map);
// The walk's CAtlList<NiAVObject*> (head, tail, ...).
struct Unk_OlpNode { Unk_OlpNode* m_pNext; Unk_OlpNode* m_pPrev; void* m_element; };
struct Unk_OlpList { Unk_OlpNode* m_pHead; Unk_OlpNode* m_pTail; };
typedef ATL::CAtlList<NiAVObject*> Unk_OlpAtlList;   // the walk queue at +0 of Unk_NodeQueue
bool FUN_1414d4110(void* cfg, CAtlArray<COLORREF>& arr);

// @0x1414d3120
MS2OutlinePreProcessor::MS2OutlinePreProcessor()
    : NiShaderSortProcessor(0x20, 0x25, 0x200), m_spOutlineMaterial(0)
{
    m_spOutlineMaterial = (NiMaterial*)((void*)NiMaterialLibrary::CreateMaterial(DAT_143ae5210));
    int idx = 0;
    CAtlArray<COLORREF> arr;
    float col[10];
    FUN_1414d4110((char*)((void*)GetClientConstants()) + 0xb460, arr);
    for (unsigned i = 0; i < 3 && i < arr.GetCount(); ++i) {
        MS2Color c(Unk_ColorValue(*(struct Unk_ConstColor const*)(&arr[i])));
        col[idx++] = c.r;
        col[idx++] = c.g;
        col[idx++] = c.b;
    }
    float scale = reinterpret_cast<Common::Constants::Value<float>*>((char*)((void*)GetClientConstants()) + 0xb4d0)->Read();
    for (unsigned j = 0; j < 9; ++j)
        col[j] = col[j] * scale;
    UpdateGlobalShaderConstantFloats(DAT_143ae53c8, (float const*)(col), 9);
    m_nOutlined = 0;
}

// @0x1414d3360
void MS2OutlinePreProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (pkInput == 0) return;
    OutlineMap objSet(17, 0.75f, 0.25f, 2.25f, 10);
    CollectOutlineTargets(objSet);
    MaterialSwapSavedMap matMap;
    NiVisibleArray outArr;
    unsigned n = pkInput->GetCount();
    bool any = false;
    for (unsigned i = 0; i < n; ++i) {
        NiRenderObject* obj = &pkInput->GetAt(i);
        if (FUN_14098dfc0((class NiAVObject*)(obj)))
            continue;
        if (FUN_141568c90((class NiRenderObject*)(obj)))
            continue;
        int flag = 1;
        if (DAT_143ae2b34 != 0)
            flag = FUN_141568dc0((class NiAVObject*)(obj));
        NiAVObject* key = obj;
        bool found = objSet.Lookup(key) ? true : false;
        if (flag != 0 || found) {
            NiColorExtraData* ent = (NiColorExtraData*)((void*)NiObject::DynamicCast(&NiColorExtraData::ms_RTTI, (class NiObject const*)(((void*)((class NiObjectNET*)(void*)(obj))->GetExtraData(DAT_143ae50e0)))));
            if (ent != 0 || found) {
                matMap.SetAt(obj, obj->GetActiveMaterial());
                obj->ApplyAndSetActiveMaterial(m_spOutlineMaterial, 0xffffffff);
                ((class NiMaterialInstance*)(void*)(((void*)((class NiRenderObject*)(void*)(obj))->GetActiveMaterialInstance())))->ClearCachedShader();
                obj->SetMaterialNeedsUpdate(true);
                NiColorA packed = ent != 0 ? ent->GetValue() : efd::ColorA::BLACK;
                CMeshUVPicker::SetColorExtraData((class NiObjectNET*)(obj), DAT_143ae50f0, *(class NiColorA const*)(&packed));
                outArr.Add(*obj);
                if (ent != 0) any = true;
            }
        }
    }
    void* svc = ((void*)Unk_AeFeatureMgr::FUN_1409a8b20());
    reinterpret_cast<PostProcessingService*>(svc)->SetStepActive(0x11, any);
    if (any) {
        NiShaderSortProcessor::PreRenderProcessList(&outArr, kOutput, pvExtraData);
        m_nOutlined = outArr.GetCount();
    } else {
        m_nOutlined = 0;
    }
    NiTMapIterator pos = matMap.GetFirstPos();
    while (pos != 0) {
        NiRenderObject* k;
        const NiMaterial* v;
        matMap.GetNext(pos, k, v);
        k->SetActiveMaterial(v);
        ((class NiMaterialInstance*)(void*)(((void*)((class NiRenderObject*)(void*)(k))->GetActiveMaterialInstance())))->ClearCachedShader();
        k->SetMaterialNeedsUpdate(true);
    }
}

// @0x1414d3780
int FUN_1414d3780(MS2OutlinePreProcessor* p) { return p->m_nOutlined; }

// @0x1414d37a0
void FUN_1414d37a0(void* obj, int idx)
{
    if (idx < 0 || idx >= 3)
        return;
    static Unk_Vec3Cli axes[3] = { Unk_Vec3Cli(1.0f, 0.0f, 0.0f), Unk_Vec3Cli(0.0f, 1.0f, 0.0f), Unk_Vec3Cli(0.0f, 0.0f, 1.0f) };
    FUN_1410479a0((class NiObjectNET*)(obj), DAT_143ae50e0, *(class NiColor const*)(&axes[idx]));
    if (DAT_143ae2b34 != 0)
        FUN_141568df0((class NiAVObject*)(obj));
}

// @0x1414d38b0
void AddOutlineColor(void* obj, void* color)
{
    int v = 0;
    if (DAT_143ae2b34 != 0)
        v = FUN_141568dc0((class NiAVObject*)(obj));
    if (v == 0) {
        if (((void*)((class NiObjectNET*)(void*)(obj))->GetExtraData(DAT_143ae50e0)) == 0) {
            CMeshUVPicker::SetColorExtraData((class NiObjectNET*)(obj), DAT_143ae50e0, *(class NiColorA const*)(color));
            if (DAT_143ae2b34 != 0)
                FUN_141568df0((class NiAVObject*)(obj));
        }
    }
}

// @0x1414d4c70
void FUN_1414d4c70(void* obj, unsigned v) { *(unsigned*)((char*)obj + 0xe0) = v; }

// @0x1414d3930
void RemoveOutline(void* obj)
{
    if (((void*)((class NiObjectNET*)(void*)(obj))->GetExtraData(DAT_143ae50e0)) != 0)
        ((class NiObjectNET*)(void*)(obj))->RemoveExtraData(DAT_143ae50e0);
    if (DAT_143ae2b34 != 0) {
        unsigned u = FUN_140d96630((class NiAVObject*)(obj)) & 0xfffffffb;
        FUN_1414d4c70(obj, u);
    }
}

// @0x1414d4a50
template NiAVObject* ATL::CAtlList<NiAVObject*, ATL::CElementTraits<NiAVObject*>>::RemoveHead();   // MS2-PIN at the end



















// @0x1414d3ff0
void* FUN_1414d3ff0(void* list) { return *(void**)((char*)list + 0x10); }

// The scene-graph walk (applyeffect.cpp / nifanimationcontroller.cpp declare the same view); its pending
// CAtlList<NiAVObject*> sits at +0.

// @0x1414d39a0
void CollectOutlineTargets(OutlineMap& map)
{
    void* sc = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
    if (sc == 0) return;
    Unk_AeSceneIter wl((NiAVObject*)FUN_141b6efc0(reinterpret_cast<GameObject*>(sc)->GetEntity()));
    while ((size_t)FUN_1414d3ff0(&wl) > 0) {
        NiAVObject* node = reinterpret_cast<Unk_OlpAtlList*>(&wl)->RemoveHead();
        if (node != 0) {
            void* c1 = ((void*)NiObject::DynamicCast(&NiStringExtraData::ms_RTTI, (class NiObject const*)(((void*)((class NiObjectNET*)(void*)(node))->GetExtraData(DAT_143ae51b8)))));
            if (c1 != 0) {
                if (((efd::FixedString*)((void*)&((class NiStringExtraData*)(void*)(c1))->GetValue()))->ContainsNoCase((const char*)DAT_143ae50e8))
                    continue;
            }
            if (((void*)NiObject::DynamicCast(&EffectNode::ms_RTTI, (class NiObject const*)(node))) != 0)
                continue;
            if (((void*)NiObject::DynamicCast(&NiPSParticleSystem::ms_RTTI, (class NiObject const*)(node))) != 0)
                continue;
            void* c2 = ((void*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(node)));
            if (c2 != 0)
                map.SetAt(node, node);
            void* c3 = ((void*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(node)));
            if (c3 != 0)
                ((class Unk_NodeQueue*)(void*)(&wl))->AddChildren((class NiNode*)(c3));
        }
    }
}

// @0x1414d3cc0 ~MS2OutlinePreProcessor is implicit (ms2outlinepreprocessor.h).

// The constants entry: a has-value flag at +0xa, the colour array at +0x50.
struct Unk_1414d4110 {
    char m_0[0xa];
    bool m_a;
};

// @0x1414d4110
bool FUN_1414d4110(void* cfg, CAtlArray<COLORREF>& arr)
{
    if (((Unk_1414d4110*)cfg)->m_a) {
        reinterpret_cast<CAtlArray<Unk_ConstColor>&>(arr).RemoveAll();
        reinterpret_cast<CAtlArray<Unk_ConstColor>&>(arr).Append(*(const CAtlArray<Unk_ConstColor>*)((char*)cfg + 0x50));
        return true;
    }
    if (!reinterpret_cast<Common::Constants::Object*>(cfg)->HasKey())
        reinterpret_cast<Common::Constants::Object*>(cfg)->Error("constants has no key");
    return false;
}
// MS2-PIN: ?RemoveHead@?$CAtlList@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEAAPEAVNiAVObject@@XZ 0x1414d4a50 ; unique
