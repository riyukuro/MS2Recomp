// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Outline render-list pre-processor (NiShaderSortProcessor subclass).
// MS2-UNIT: ?\ms2outlinepreprocessor.cpp
// MS2-RANGE: 0x1414d3120-0x1414d4e20 .text$mn
// MS2-FUNCTIONAL: the ctor differs only in stack slots (the exe keeps the zero-extended loop index at +0x40 and the
// colour return at +0x48; ours swaps them).
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2outlinepreprocessor.h"
#include "ms2materialswapprocessor.h"
#include <atlcoll.h>
#include <NiRenderObject.h>
#include <NiMaterial.h>
#include <NiAVObject.h>
#include <efd/FixedString.h>
#include <efd/Color.h>
#include <NiColorExtraData.h>

struct Unk_Colc { float x, y, z; Unk_Colc(float x, float y, float z); };   // ctor 0x140a56db0

// ---- out-of-unit callees ----
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
   void* FUN_14123c410(void* a);   void* FUN_141b6efc0(void* a);
class NiMaterialLibrary   // C3: member view for the former free stand-ins
{
public:
    static class NiMaterial* CreateMaterial(class NiFixedString const&);
};
unsigned int Unk_ColorValue(struct Unk_ConstColor const&);   // C3: was FUN_14056d500
   Unk_Colc FUN_1408a85e0(unsigned c);   float FUN_1402bac70(void* p);bool FUN_1409a5770(class NiFixedString&, float const*, int);   // C3: was FUN_1409a5770
bool FUN_1402b74f0(void* p);   void FUN_1402b7560(void* p, const char* s);   void FUN_1402c2870(void* arr);   void FUN_1402bf0f0(void* arr, void* src);
bool FUN_14098dfc0(class NiAVObject*);   // C3: was FUN_14098dfc0
bool FUN_141568c90(class NiRenderObject*);   // C3: was FUN_141568c90
unsigned int FUN_141568dc0(class NiAVObject*);   // C3: was FUN_141568dc0
void FUN_141568df0(class NiAVObject*);   // C3: was FUN_141568df0
class CMeshUVPicker   // C3: member view for the former free stand-ins
{
public:
    static void FUN_141480710(class NiObjectNET*, class NiFixedString const&, class NiColorA const&);
};
class Unk_AeFeatureMgr   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};
   void FUN_1416a3920(void* svc, int id, char b);
void FUN_1410479a0(class NiObjectNET*, class NiFixedString const&, class NiColor const&);   // C3: was FUN_1410479a0
unsigned int FUN_140d96630(class NiAVObject*);   // C3: was FUN_140d96630
class Unk_NodeQueue   // C3: member view for the former free stand-ins
{
public:
    void AddChildren(class NiNode*);
};
   void FUN_14098da10(void* wl, void* node);
void* FUN_142087e50(void* p);class NiStringExtraData   // C3: member view for the former free stand-ins
{
public:
    class NiFixedString const& GetValue() const;
};
void FUN_140159b70(long hr);
extern char DAT_143ae2b34, DAT_143ae50e0, DAT_143ae50e8, DAT_143ae50f0, DAT_143ae51b8, DAT_143ae53c8, DAT_143ae5210, DAT_143a09680;
extern char DAT_143afafd0, DAT_143afb000, DAT_143ad1588, DAT_143afbfb8, DAT_143afa7d0, DAT_143afa4d8;

typedef CAtlMap<NiAVObject*, NiAVObject*> OutlineMap;


void FUN_1414d39a0(OutlineMap& map);
// The walk's CAtlList<NiAVObject*> (head, tail, ...).
struct Unk_OlpNode { Unk_OlpNode* m_pNext; Unk_OlpNode* m_pPrev; void* m_element; };
struct Unk_OlpList { Unk_OlpNode* m_pHead; Unk_OlpNode* m_pTail; };
void* FUN_1414d4a50(Unk_OlpList* list);
bool FUN_1414d4110(void* cfg, CAtlArray<COLORREF>& arr);

// @0x1414d3120
MS2OutlinePreProcessor::MS2OutlinePreProcessor()
    : NiShaderSortProcessor(0x20, 0x25, 0x200), m_spOutlineMaterial(0)
{
    m_spOutlineMaterial = (NiMaterial*)((void*)NiMaterialLibrary::CreateMaterial(*(class NiFixedString const*)(&DAT_143ae5210)));
    int idx = 0;
    CAtlArray<COLORREF> arr;
    float col[10];
    FUN_1414d4110((char*)((void*)FUN_1401d3200()) + 0xb460, arr);
    for (unsigned i = 0; i < 3 && i < arr.GetCount(); ++i) {
        Unk_Colc c = FUN_1408a85e0(Unk_ColorValue(*(struct Unk_ConstColor const*)(&arr[i])));
        col[idx++] = c.x;
        col[idx++] = c.y;
        col[idx++] = c.z;
    }
    float scale = FUN_1402bac70((char*)((void*)FUN_1401d3200()) + 0xb4d0);
    for (unsigned j = 0; j < 9; ++j)
        col[j] = col[j] * scale;
    FUN_1409a5770(*(class NiFixedString*)(&DAT_143ae53c8), (float const*)(col), 9);
    m_nOutlined = 0;
}

// @0x1414d3360
void MS2OutlinePreProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (pkInput == 0) return;
    OutlineMap objSet(17, 0.75f, 0.25f, 2.25f, 10);
    FUN_1414d39a0(objSet);
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
        if (*(int*)&DAT_143ae2b34 != 0)
            flag = FUN_141568dc0((class NiAVObject*)(obj));
        NiAVObject* key = obj;
        bool found = objSet.Lookup(key) ? true : false;
        if (flag != 0 || found) {
            NiColorExtraData* ent = (NiColorExtraData*)((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afafd0), (class NiObject const*)(((void*)((class NiObjectNET*)(void*)(obj))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae50e0))))));
            if (ent != 0 || found) {
                matMap.SetAt(obj, obj->GetActiveMaterial());
                obj->ApplyAndSetActiveMaterial(m_spOutlineMaterial, 0xffffffff);
                ((class NiMaterialInstance*)(void*)(((void*)((class NiRenderObject*)(void*)(obj))->GetActiveMaterialInstance())))->ClearCachedShader();
                obj->SetMaterialNeedsUpdate(true);
                NiColorA packed = ent != 0 ? ent->GetValue() : efd::ColorA::BLACK;
                CMeshUVPicker::FUN_141480710((class NiObjectNET*)(obj), *(class NiFixedString const*)(&DAT_143ae50f0), *(class NiColorA const*)(&packed));
                outArr.Add(*obj);
                if (ent != 0) any = true;
            }
        }
    }
    void* svc = ((void*)Unk_AeFeatureMgr::FUN_1409a8b20());
    FUN_1416a3920(svc, 0x11, any);
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
    static Unk_Colc axes[3] = { Unk_Colc(1.0f, 0.0f, 0.0f), Unk_Colc(0.0f, 1.0f, 0.0f), Unk_Colc(0.0f, 0.0f, 1.0f) };
    FUN_1410479a0((class NiObjectNET*)(obj), *(class NiFixedString const*)(&DAT_143ae50e0), *(class NiColor const*)(&axes[idx]));
    if (*(int*)&DAT_143ae2b34 != 0)
        FUN_141568df0((class NiAVObject*)(obj));
}

// @0x1414d38b0
void FUN_1414d38b0(void* obj, void* color)
{
    int v = 0;
    if (*(int*)&DAT_143ae2b34 != 0)
        v = FUN_141568dc0((class NiAVObject*)(obj));
    if (v == 0) {
        if (((void*)((class NiObjectNET*)(void*)(obj))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae50e0))) == 0) {
            CMeshUVPicker::FUN_141480710((class NiObjectNET*)(obj), *(class NiFixedString const*)(&DAT_143ae50e0), *(class NiColorA const*)(color));
            if (*(int*)&DAT_143ae2b34 != 0)
                FUN_141568df0((class NiAVObject*)(obj));
        }
    }
}

// @0x1414d4c70
void FUN_1414d4c70(void* obj, unsigned v) { *(unsigned*)((char*)obj + 0xe0) = v; }

// @0x1414d3930
void FUN_1414d3930(void* obj)
{
    if (((void*)((class NiObjectNET*)(void*)(obj))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae50e0))) != 0)
        ((class NiObjectNET*)(void*)(obj))->RemoveExtraData(*(class NiFixedString const*)(&DAT_143ae50e0));
    if (*(int*)&DAT_143ae2b34 != 0) {
        unsigned u = FUN_140d96630((class NiAVObject*)(obj)) & 0xfffffffb;
        FUN_1414d4c70(obj, u);
    }
}

// @0x1414d4a50
void* FUN_1414d4a50(Unk_OlpList* list)
{
    // CAtlList::RemoveHead: ATLENSURE(m_pHead != NULL) spelled out.
    do {
        int bOk = !!(list->m_pHead != 0);
        do {} while (0);
        if (!bOk)
            FUN_140159b70(0x80004005);
    } while (0);
    Unk_OlpNode* pn = list->m_pHead;
    void* r = pn->m_element;
    list->m_pHead = pn->m_pNext;
    if (list->m_pHead != 0)
        list->m_pHead->m_pPrev = 0;
    else
        list->m_pTail = 0;
    FUN_14098da10(list, pn);
    return r;
}

// @0x1414d3ff0
void* FUN_1414d3ff0(void* list) { return *(void**)((char*)list + 0x10); }

// The scene-graph walk (applyeffect.cpp / nifanimationcontroller.cpp declare the same view); its pending
// CAtlList<NiAVObject*> sits at +0.
class Unk_AeSceneIter
{
public:
    Unk_AeSceneIter(NiAVObject* pRoot);                     // 0x14098cb80
    ~Unk_AeSceneIter();                                     // 0x14098cf00
    NiAVObject* FUN_14098e0d0(bool bEnterChildren);
    void* m_p0; void* m_p1; void* m_p2; void* m_p3; void* m_p4; void* m_p5;
};
MS2_CHECK_SIZE(Unk_AeSceneIter, 0x30);

// @0x1414d39a0
void FUN_1414d39a0(OutlineMap& map)
{
    void* sc = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0();
    if (sc == 0) return;
    Unk_AeSceneIter wl((NiAVObject*)FUN_141b6efc0(FUN_14123c410(sc)));
    while ((size_t)FUN_1414d3ff0(&wl) > 0) {
        NiAVObject* node = (NiAVObject*)FUN_1414d4a50((Unk_OlpList*)&wl);
        if (node != 0) {
            void* c1 = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afb000), (class NiObject const*)(((void*)((class NiObjectNET*)(void*)(node))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae51b8))))));
            if (c1 != 0) {
                if (((efd::FixedString*)((void*)&((class NiStringExtraData*)(void*)(c1))->GetValue()))->ContainsNoCase((const char*)FUN_142087e50(&DAT_143ae50e8)))
                    continue;
            }
            if (((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143ad1588), (class NiObject const*)(node))) != 0)
                continue;
            if (((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afbfb8), (class NiObject const*)(node))) != 0)
                continue;
            void* c2 = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afa7d0), (class NiObject const*)(node)));
            if (c2 != 0)
                map.SetAt(node, node);
            void* c3 = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afa4d8), (class NiObject const*)(node)));
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
        FUN_1402c2870(&arr);
        FUN_1402bf0f0(&arr, (char*)cfg + 0x50);
        return true;
    }
    if (!FUN_1402b74f0(cfg))
        FUN_1402b7560(cfg, "constants has no key");
    return false;
}
