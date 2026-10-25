// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Outline render-list pre-processor (NiShaderSortProcessor subclass).
// MS2-UNIT: ?\ms2outlinepreprocessor.cpp
// MS2-RANGE: 0x1414d3120-0x1414d4e20 .text$mn
// MS2-FUNCTIONAL: extern-heavy; the object sets are real ATL CAtlMap<void*,void*>; the NiTPointerMap<NiRenderObject*,
// const NiMaterial*> and NiVisibleArray helpers live in ms2materialswapprocessor.cpp (0x1414d1xxx) and are bound by FUN_ name.
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2outlinepreprocessor.h"
#include <atlcoll.h>
#include <NiRenderObject.h>
#include <NiMaterial.h>
#include <NiAVObject.h>
#include <efd/FixedString.h>

struct Unk_Colc { float x, y, z; Unk_Colc(float x, float y, float z); };   // ctor 0x140a56db0
struct Unk_C16 { char b[16]; };

// ---- out-of-unit callees ----
void* FUN_1401d3200();   void* FUN_1403ed2d0();   void* FUN_141bd0cc0(void* a);   void* FUN_14123c410(void* a);   void* FUN_141b6efc0(void* a);
void FUN_1409a7460(void* sp, int n);   void* FUN_141d284a0(void* tbl);   void FUN_1414802a0(void* sp, void* p);   void FUN_1409a7b00(void* sp);
void* FUN_1409a8120(void* sp);
unsigned FUN_14056d500(const COLORREF* p);   Unk_Colc FUN_1408a85e0(unsigned c);   float FUN_1402bac70(void* p);   void FUN_1409a5770(void* dst, void* src, int n);
char FUN_1402b74f0(void* p);   void FUN_1402b7560(void* p, const char* s);   void FUN_1402c2870(void* arr);   void FUN_1402bf0f0(void* arr, void* src);
void FUN_1414d1170(void* map, unsigned bins);   void FUN_1414d13d0(void* map);   void FUN_1414d1320(void* arr);
unsigned FUN_140d89680(const void* arr);   void* FUN_1414d1830(const void* arr, unsigned i);   void FUN_140d9d620(void* arr, void* obj);   void FUN_140d9e140(void* arr);
void FUN_1414d1b00(void* map, void* key, void* val);   void* FUN_1414d1850(void* map);   void FUN_1414d18b0(void* map, void** pos, void** key, void** val);
char FUN_14098dfc0(void* o);   char FUN_141568c90(void* o);   int FUN_141568dc0(void* o);   void FUN_141568df0(void* o);
void* FUN_141d17b40(void* o, void* key);   void* FUN_14098d8d0(void* tbl, void* key);   void* FUN_140a17cd0(void* o);
void* FUN_140d89420(void* o);   void FUN_141047900(void* p);   void* FUN_14106bfd0(void* a, void* out);   void FUN_140987930(void* out, void* in);
void FUN_141480710(void* o, void* key, void* val);   void* FUN_1409a8b20();   void FUN_1416a3920(void* svc, int id, char b);
void FUN_1410479a0(void* o, void* key, void* val);   void FUN_141d18870(void* o, void* key);   unsigned FUN_140d96630(void* o);
void FUN_14098cb80(void* wl, void* root);   void FUN_14098cf00(void* wl);   void FUN_14098d6d0(void* wl, void* node);   void FUN_14098da10(void* wl, void* node);
void* FUN_142087e50(void* p);   void* FUN_141168130(void* p);
void FUN_140159b70(long hr);
extern char DAT_143ae2b34, DAT_143ae50e0, DAT_143ae50e8, DAT_143ae50f0, DAT_143ae51b8, DAT_143ae53c8, DAT_143ae5210, DAT_143a09680;
extern char DAT_143afafd0, DAT_143afb000, DAT_143ad1588, DAT_143afbfb8, DAT_143afa7d0, DAT_143afa4d8;

typedef CAtlMap<NiAVObject*, NiAVObject*> OutlineMap;


void FUN_1414d39a0(OutlineMap& map);
void* FUN_1414d4a50(void** list);
bool FUN_1414d4110(void* cfg, CAtlArray<COLORREF>& arr);

// @0x1414d3120
MS2OutlinePreProcessor::MS2OutlinePreProcessor()
    : NiShaderSortProcessor(0x20, 0x25, 0x200)
{
    FUN_1409a7460(&m_spOutlineMaterial, 0);
    FUN_1414802a0(&m_spOutlineMaterial, FUN_141d284a0(&DAT_143ae5210));
    int idx = 0;
    CAtlArray<COLORREF> arr;
    float col[10];
    FUN_1414d4110((char*)FUN_1401d3200() + 0xb460, arr);
    for (unsigned i = 0; i < 3; ++i) {
        if (arr.GetCount() <= i) break;
        unsigned v = FUN_14056d500(&arr[i]);
        Unk_Colc c = FUN_1408a85e0(v);
        col[idx] = c.x;
        col[idx + 1] = c.y;
        col[idx + 2] = c.z;
        idx += 3;
    }
    float scale = FUN_1402bac70((char*)FUN_1401d3200() + 0xb4d0);
    for (unsigned j = 0; j < 9; ++j)
        col[j] = col[j] * scale;
    FUN_1409a5770(&DAT_143ae53c8, col, 9);
    m_nOutlined = 0;
}

// @0x1414d3360
void MS2OutlinePreProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (pkInput == 0) return;
    OutlineMap objSet(17, 0.75f, 0.25f, 2.25f, 10);
    FUN_1414d39a0(objSet);
    char matMap[32];
    FUN_1414d1170(matMap, 0x25);
    char outArr[24];
    FUN_1414d1320(outArr);
    unsigned n = FUN_140d89680(pkInput);
    char any = 0;
    for (unsigned i = 0; i < n; ++i) {
        NiRenderObject* obj = (NiRenderObject*)FUN_1414d1830(pkInput, i);
        if (FUN_14098dfc0(obj) == 0 && FUN_141568c90(obj) == 0) {
            int flag = 1;
            if (*(int*)&DAT_143ae2b34 != 0)
                flag = FUN_141568dc0(obj);
            void* key = obj;
            const void* found = objSet.Lookup((NiAVObject*)key);
            if (flag != 0 || found != 0) {
                void* c = FUN_141d17b40(obj, &DAT_143ae50e0);
                void* ent = FUN_14098d8d0(&DAT_143afafd0, c);
                if (ent != 0 || found != 0) {
                    FUN_1414d1b00(matMap, obj, FUN_140a17cd0(obj));
                    obj->ApplyAndSetActiveMaterial((NiMaterial*)FUN_1409a8120(&m_spOutlineMaterial), 0xffffffff);
                    FUN_141047900(FUN_140d89420(obj));
                    obj->SetMaterialNeedsUpdate(true);
                    Unk_C16 col;
                    if (ent == 0) {
                        col = *(Unk_C16*)&DAT_143a09680;
                    } else {
                        char tmp[16];
                        Unk_C16 a = *(Unk_C16*)FUN_14106bfd0(ent, tmp);
                        col = a;
                    }
                    char packed[16];
                    FUN_140987930(packed, &col);
                    FUN_141480710(obj, &DAT_143ae50f0, packed);
                    FUN_140d9d620(outArr, obj);
                    if (ent != 0) any = 1;
                }
            }
        }
    }
    FUN_1416a3920(FUN_1409a8b20(), 0x11, any);
    if (any == 0) {
        m_nOutlined = 0;
    } else {
        NiShaderSortProcessor::PreRenderProcessList((const NiVisibleArray*)outArr, kOutput, pvExtraData);
        m_nOutlined = FUN_140d89680(outArr);
    }
    void* pos = FUN_1414d1850(matMap);
    while (pos != 0) {
        void* k; void* v;
        FUN_1414d18b0(matMap, &pos, &k, &v);
        ((NiRenderObject*)k)->SetActiveMaterial((NiMaterial*)v);
        FUN_141047900(FUN_140d89420(k));
        ((NiRenderObject*)k)->SetMaterialNeedsUpdate(true);
    }
    FUN_140d9e140(outArr);
    FUN_1414d13d0(matMap);
}

// @0x1414d3780
int FUN_1414d3780(MS2OutlinePreProcessor* p) { return p->m_nOutlined; }

// @0x1414d37a0
void FUN_1414d37a0(void* obj, int idx)
{
    if (-1 < idx && idx < 3) {
        static Unk_Colc axes[3] = { Unk_Colc(1.0f, 0.0f, 0.0f), Unk_Colc(0.0f, 1.0f, 0.0f), Unk_Colc(0.0f, 0.0f, 1.0f) };
        FUN_1410479a0(obj, &DAT_143ae50e0, &axes[idx]);
        if (*(int*)&DAT_143ae2b34 != 0)
            FUN_141568df0(obj);
    }
}

// @0x1414d38b0
void FUN_1414d38b0(void* obj, void* color)
{
    int v = 0;
    if (*(int*)&DAT_143ae2b34 != 0)
        v = FUN_141568dc0(obj);
    if (v == 0) {
        if (FUN_141d17b40(obj, &DAT_143ae50e0) == 0) {
            FUN_141480710(obj, &DAT_143ae50e0, color);
            if (*(int*)&DAT_143ae2b34 != 0)
                FUN_141568df0(obj);
        }
    }
}

// @0x1414d4c70
void FUN_1414d4c70(void* obj, unsigned v) { *(unsigned*)((char*)obj + 0xe0) = v; }

// @0x1414d3930
void FUN_1414d3930(void* obj)
{
    if (FUN_141d17b40(obj, &DAT_143ae50e0) != 0)
        FUN_141d18870(obj, &DAT_143ae50e0);
    if (*(int*)&DAT_143ae2b34 != 0) {
        unsigned u = FUN_140d96630(obj);
        FUN_1414d4c70(obj, u & 0xfffffffb);
    }
}

// @0x1414d4a50
void* FUN_1414d4a50(void** list)
{
    if (list[0] != 0) {
        void** pn = (void**)list[0];
        void* r = pn[2];
        list[0] = pn[0];
        if (list[0] == 0)
            list[1] = 0;
        else
            ((void**)list[0])[1] = 0;
        FUN_14098da10(list, pn);
        return r;
    }
    FUN_140159b70(0x80004005);
    return 0;
}

// @0x1414d3ff0
void* FUN_1414d3ff0(void* list) { return *(void**)((char*)list + 0x10); }

// @0x1414d39a0
void FUN_1414d39a0(OutlineMap& map)
{
    void* sc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (sc == 0) return;
    void* root = FUN_141b6efc0(FUN_14123c410(sc));
    char wl[64];
    FUN_14098cb80(wl, root);
    for (;;) {
        if (FUN_1414d3ff0(wl) == 0) {
            FUN_14098cf00(wl);
            return;
        }
        void* node = FUN_1414d4a50((void**)wl);
        if (node == 0) continue;
        void* v = FUN_141d17b40(node, &DAT_143ae51b8);
        void* c1 = FUN_14098d8d0(&DAT_143afb000, v);
        if (c1 != 0) {
            const char* s = (const char*)FUN_142087e50(&DAT_143ae50e8);
            if (((efd::FixedString*)FUN_141168130(c1))->ContainsNoCase(s))
                continue;
        }
        if (FUN_14098d8d0(&DAT_143ad1588, node) == 0 && FUN_14098d8d0(&DAT_143afbfb8, node) == 0) {
            if (FUN_14098d8d0(&DAT_143afa7d0, node) != 0)
                map.SetAt((NiAVObject*)node, (NiAVObject*)node);
            void* c3 = FUN_14098d8d0(&DAT_143afa4d8, node);
            if (c3 != 0)
                FUN_14098d6d0(wl, c3);
        }
    }
}

// @0x1414d3cc0
MS2OutlinePreProcessor::~MS2OutlinePreProcessor()
{
    FUN_1409a7b00(&m_spOutlineMaterial);
}

// @0x1414d4110
bool FUN_1414d4110(void* cfg, CAtlArray<COLORREF>& arr)
{
    if (*((char*)cfg + 10) == 0) {
        if (FUN_1402b74f0(cfg) == 0)
            FUN_1402b7560(cfg, "constants has no key");
        return false;
    }
    FUN_1402c2870(&arr);
    FUN_1402bf0f0(&arr, (char*)cfg + 0x50);
    return true;
}
