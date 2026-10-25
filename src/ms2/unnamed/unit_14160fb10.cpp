// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Rendering glue: CObjectShadow (blob shadow quad under a character: mesh + properties + fade).
// MS2-UNIT: ?\objectshadow.cpp
// MS2-RANGE: 0x14160fb10-0x1416113d8 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\objectshadow.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (names invented; layouts pinned) ------------------------------------------------------------
// Fake virtual-slot classes for the objects that are only called through their vftables here.
class Unk_ShadowOwner { public:                                    // m_pOwner (+0x40)
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual int vfunc_25(); };                                      // 0xc8
class Unk_ShadowNode { public:                                      // NiNode-like parent
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35();
    virtual void vfunc_36(void* child, int flag);                   // 0x120 AttachChild
    virtual void vfunc_37(void* out, void* child); };               // 0x128 DetachChild
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

struct Unk_NodePtr { Unk_NodePtr(void* p); ~Unk_NodePtr(); void* m_p; };   // ctor 0x1409f7170, dtor 0x1409f74b0 (smart pointer to the shadow NiNode)

class CMesh {                                                       // base mesh, ctor 0x14147af80 / dtor 0x14147b330 (unrecovered)
public:
    CMesh(void* a, void* b, int c, int d, int e, char f);
    virtual ~CMesh();
    virtual void vfunc_1();                                         // 0x141d16bf0
    static void operator delete(void*, size_t);                     // efd::MemObject::operator delete 0x14208a8f0
    void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28;
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
    Unk_NodePtr m_node;    // +0x48
    int m_lodHi;           // +0x50
    int m_lodLo;           // +0x54
};
MS2_CHECK_SIZE(CObjectShadow, 0x58);
MS2_CHECK_OFFSET(CObjectShadow, m_pOwner, 0x40);
MS2_CHECK_OFFSET(CObjectShadow, m_node, 0x48);

struct Unk_Pt3c { float x, y, z; Unk_Pt3c(float, float, float); Unk_Pt3c& operator=(const Unk_Pt3c&); };   // NiPoint3(x,y,z) 0x14097f250, operator= 0x14097faa0
struct Unk_Pt2c { float u, v; Unk_Pt2c(float, float); };                                                    // NiPoint2(u,v) 0x140a0a4c0
struct Unk_Colc { float r, g, b; Unk_Colc(float, float, float); };                                         // NiColor(r,g,b) 0x140a56db0
struct Unk_NiPt3 { float x, y, z; Unk_NiPt3(const void* efdPoint); };                                      // NiPoint3(const efd::Point3&) 0x14027dcf0
// ---- unrecovered neighbours -------------------------------------------------------------------------------------------------
extern float DAT_1439f81fc; extern float DAT_1439f8200; extern float DAT_1439f81f4; extern float DAT_1439f81f8; extern float DAT_1439f8204;
extern int DAT_1439f8208;   extern int DAT_143ae2960;   extern char DAT_143a08cd8;   extern char DAT_143afa608;
void FUN_1416106e0(CObjectShadow* self, void* owner, int lodHi, int lodLo, float radius, float zOffset);
void FUN_141610490();
void FUN_1416105c0(CObjectShadow* self);
void FUN_141611370(void* obj, bool flag);
void FUN_1416113a0(void* mat, const Unk_Colc& color);
int FUN_140ae1c10();                                  // current quality level
void* FUN_1413f9870();   void FUN_1414c05d0(void* p);
void* FUN_140ae1c00();   int FUN_141376880(void* p, int k);
void* FUN_1403ed2d0();   void FUN_141bd30f0(void* p, bool b);   void FUN_141bd2db0(void* p, void* list, int k);
void* FUN_1403ed280();   void* FUN_1411a6b10(void* p);
void* FUN_140967000(void* list);   void* FUN_140a01110(void* list, void* pos);
void* FUN_1409658c0(void* elem);   void FUN_1409671f0(void* list, void** pos);
void* FUN_1409475f0(Unk_NodePtr* p);   void* FUN_1409475d0(Unk_NodePtr* p);   void FUN_1409f76f0(Unk_NodePtr* p, void* node);
void* FUN_140a0b000(void* p);   void FUN_1405a85c0(void* p);
void* FUN_140a0afe0(CObjectShadow* self);              // property owner (NiGeometry) of the mesh
void* FUN_140a0afd0();
void FUN_140a0b300(void* node, char b);               // set app-culled
void FUN_140a0b330(void* obj, bool b, short flags);
void* FUN_140a332d0(void* xform);   void* FUN_140a00e10(const void* a, void* out, const void* b);   void FUN_140968990(void* v);
void* FUN_140a0a480(void* out, const void* a, const void* b, const void* c);   // basis -> matrix
float FUN_140a17940(float v, float lo, float hi);
void FUN_140aacaa0(void* node, const void* xform);
void* FUN_14086d260();   double FUN_141473280(void* p);
void FUN_14098e840(void* p, float v);   void* FUN_14098d8d0(void* table, void* key);
void* FUN_14123c410(void* owner);   void* FUN_141b6efc0(void* p);   void FUN_141567540(void* p, bool b);
void* FUN_14099eef0(void* owner);
void* FUN_1416561a0(void* p);   void FUN_1411e1b80(void* src, void* list);
void* FUN_140885670(void* list);   void* FUN_140885600(void* list, void* pos);   void FUN_140885680(void* list, void** pos);
void* FUN_1405a8ed0(void* elem);   int FUN_1411dc0d0(void* p);   void FUN_1411dcc80(void* p, CAtlArray<void*>* arr);
unsigned __int64 FUN_141168120(CAtlArray<void*>* arr);   void* FUN_1411f9020(CAtlArray<void*>* arr, unsigned i);
void* FUN_140b02a50(void* p);   void* FUN_141200ab0(void* p);
void* FUN_1409f7c90();   int FUN_140ddcc90(void* p);
void* FUN_140a0b280();   void* FUN_140a0b6f0();                     // vertex stream semantic ids
void* FUN_14147b7f0(CObjectShadow* self, void* semantic, int a, char b);   // lock vertex stream, returns data
void FUN_14147b850(CObjectShadow* self, void* semantic, int a, char b);    // unlock
void FUN_14147b6d0(CObjectShadow* self, short a, short b, short c, short d, short e);   // set up index buffer
void FUN_14147b8b0(CObjectShadow* self, int k);   void FUN_14147b9c0(CObjectShadow* self, int k);
void FUN_140984450(void* name, const char* s);   void FUN_1409845a0(void* name);   // NiFixedString ctor / dtor
void FUN_141d18b90(void* obj, void* name);                          // NiObjectNET::SetName
void FUN_141552f90(void* mgr, void* outTex, CString path, char b); // load texture
void* FUN_14097fbf0(void* texPtr);   void FUN_14097f4a0(void* texPtr);
void FUN_140980880(void* tex, void* src);   void FUN_140980200(void* geom, void* prop);   // NiTexturingProperty::SetBaseTexture / AttachProperty
void* FUN_141d1d470(void* mem);                                     // NiTexturingProperty ctor
void* FUN_14097f0b0(void* mem);                                     // NiAlphaProperty ctor
void FUN_140a0a0d0(void* smart, void* p);   void* FUN_140a0abd0(void* smart);   void* FUN_140a0ab60(void* smart);   void FUN_140a0a6b0(void* smart);
void FUN_140980560(void* alpha, char b);
void* FUN_14097f2d0(void* mem);                                     // NiVertexColorProperty ctor
void FUN_140980f20(void* p, int v);   void FUN_140980e60(void* p, int v);
void* FUN_141d24d60(void* mem);                                     // NiMaterialProperty ctor
void FUN_1410b1f20(void* smart, void* p);   void* FUN_1410b2250(void* smart);   void* FUN_1410b2230(void* smart);   void FUN_1410b1fa0(void* smart);
void FUN_1415699c0(void* mat, const Unk_Colc& c);   void FUN_141569980(void* mat, const Unk_Colc& c);   void FUN_14116d500(void* mat, const Unk_Colc& c);
void* FUN_140a0a3d0(void* mem);   void FUN_1409a9b90(void* fog, char b);                  // NiFogProperty
void* FUN_14097f330(void* mem);   void FUN_14097eda0(void* smart, void* p);   void* FUN_14097fc50(void* smart);   void* FUN_14097fc00(void* smart);   void FUN_14097f4d0(void* smart);   void FUN_140981100(void* z, char b);   // NiZBufferProperty
void FUN_14097f1b0(void* bound);   void FUN_140980a70(void* bound, void* center, float radius);   void FUN_14106cea0(void* geom, void* bound);
void* FUN_141d19760(void* mem, int n);                              // NiNode ctor
void FUN_141d16210(void* node);   void FUN_141d16370(void* node);   void FUN_141d16040(void* node, float t, bool b);
void* FUN_1401d31f0();
void* FUN_140876480(void* out, int cat);   void* FUN_14208a860(unsigned __int64 size, unsigned cat);
void FUN_14098e930(void* mat, char b);
struct Unk_ShList { Unk_ShList(int blockSize); ~Unk_ShList(); void* m_a; void* m_b; void* m_c; void* m_d; void* m_e; void* m_f; void* m_g; };   // ctor 0x140963ae0, dtor 0x1409647c0 (0x38)
struct Unk_ShList2 { Unk_ShList2(int blockSize); ~Unk_ShList2(); void* m_a; void* m_b; void* m_c; void* m_d; void* m_e; void* m_f; };            // ctor 0x140884ed0, dtor 0x1408850d0 (0x30)
struct Unk_ShadowXform { float r0, r1, r2, r3, r4, r5, r6, r7, r8; float tx, ty, tz; float scale; };   // NiTransform (0x34)
struct Unk_ShadowMat3 { float r0, r1, r2, r3, r4, r5, r6, r7, r8; };

#define MS2_SHADOW_NEW(dst, size, ctorcall) \
    { int catTmp; int* cat = (int*)FUN_140876480(&catTmp, 0); void* mem = FUN_14208a860(size, *cat); \
      if (mem == 0) dst = 0; else dst = ctorcall; }

// @0x14160fb10
CObjectShadow::CObjectShadow(void* owner, int lodHi, int lodLo)
    : CMesh(0, 0, 1, 4, 2, 0x12), m_node(0)
{
    FUN_1416106e0(this, owner, lodHi, lodLo, DAT_1439f81fc, DAT_1439f8200);
}

// @0x14160fbd0
CObjectShadow::CObjectShadow(void* owner, int lodHi, int lodLo, float radius)
    : CMesh(0, 0, 1, 4, 2, 0x12), m_node(0)
{
    FUN_1416106e0(this, owner, lodHi, lodLo, radius, DAT_1439f8200);
}

// @0x14160fc90
CObjectShadow::CObjectShadow(void* owner, int lodHi, int lodLo, float radius, float zOffset)
    : CMesh(0, 0, 1, 4, 2, 0x12), m_node(0)
{
    FUN_1416106e0(this, owner, lodHi, lodLo, radius, zOffset);
}

// @0x14160fd50
CObjectShadow::~CObjectShadow()
{
    Unk_ShadowNode* node = (Unk_ShadowNode*)FUN_140a0b000(FUN_1409475f0(&m_node));
    if (node != 0) {
        void* out;
        node->vfunc_37(&out, FUN_1409475d0(&m_node));
        FUN_1405a85c0(&out);
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
// MS2-FUNCTIONAL: transliterated from the decompile; locals, EH states and temp slots differ
void FUN_14160feb0(CObjectShadow* self, int active, const void* pos, const void* dir, float dt, bool force)
{
    FUN_1416105c0(self);
    if (self->m_bVisible == 0 || active == 0) {
        FUN_140a0b300(FUN_1409475f0(&self->m_node), 1);
    } else {
        float one = 1.0f;
        float fade;
        Unk_ShadowXform xf;
        Unk_ShadowMat3 t48;
        char t98[16], t8c[16];
        FUN_140a332d0(&xf);
        Unk_NiPt3 p120(pos);
        *(Unk_Pt3c*)&xf.tx = *(Unk_Pt3c*)&p120;
        xf.tz = xf.tz + self->m_fZOffset;
        Unk_NiPt3 p110(&DAT_143a08cd8);
        Unk_NiPt3 p148(FUN_140a00e10(dir, t98, &p110));
        FUN_140968990(&p148);
        Unk_NiPt3 p130(FUN_140a00e10(&p148, t8c, dir));
        FUN_140968990(&p130);
        Unk_NiPt3 p100(dir);
        *(Unk_ShadowMat3*)&xf = *(Unk_ShadowMat3*)FUN_140a0a480(&t48, &p130, &p148, &p100);
        if (0.001f <= DAT_1439f81f4) {
            float f = FUN_140a17940(dt / DAT_1439f81f4, 0.0f, 1.0f);
            fade = one - f * (one - DAT_1439f81f8);
        } else {
            fade = DAT_1439f81f8;
        }
        xf.scale = fade;
        FUN_140aacaa0(FUN_1409475f0(&self->m_node), &xf);
        float now = (float)FUN_141473280(FUN_14086d260());
        FUN_141d16040(FUN_1409475f0(&self->m_node), now, true);
        void* geom = FUN_140a0afe0(self);
        void* prop = FUN_14098d8d0(&DAT_143afa608, geom);
        if (prop != 0) {
            FUN_14098e840(prop, DAT_1439f8204 * fade);
            FUN_141d16370(FUN_140a0afe0(self));
        }
        FUN_140a0b300(FUN_1409475f0(&self->m_node), 0);
    }
    if (force || self->m_bDirty != 0) {
        void* h = FUN_141b6efc0(FUN_14123c410(self->m_pOwner));
        if (h != 0) {
            FUN_141567540(h, self->m_bShown);
            self->m_bDirty = false;
        }
        void* o = FUN_14099eef0(self->m_pOwner);
        if (o != 0) {
            void* pos2;
            Unk_ShList2 list(10);
            FUN_1411e1b80(FUN_1416561a0(o), &list);
            for (pos2 = FUN_140885670(&list); pos2 != 0; FUN_140885680(&list, &pos2)) {
                void* elem = FUN_140885600(&list, pos2);
                if (FUN_1411dc0d0(FUN_1405a8ed0(elem)) == 0) {
                    self->m_bDirty = true;
                } else {
                    CAtlArray<void*> arr;
                    FUN_1411dcc80(FUN_1405a8ed0(elem), &arr);
                    unsigned i;
                    for (i = 0; i < FUN_141168120(&arr); ++i) {
                        void* e = FUN_1411f9020(&arr, i);
                        void* m = FUN_140b02a50(e);
                        if (*(int*)((char*)FUN_141200ab0(m) + 0x20) == 0) {
                            Unk_ShadowModel* model = (Unk_ShadowModel*)FUN_140b02a50(e);
                            FUN_141567540(model->vfunc_14(), self->m_bShown);
                        }
                    }
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
    void* pos;
    level = FUN_140ae1c10();
    FUN_1414c05d0(FUN_1413f9870());
    need = FUN_141376880(FUN_140ae1c00(), 5);
    FUN_141bd30f0(FUN_1403ed2d0(), need <= level);
    Unk_ShList list(10);
    FUN_141bd2db0(FUN_1403ed2d0(), &list, 0);
    for (pos = FUN_140967000(&list); pos != 0; FUN_1409671f0(&list, &pos)) {
        Unk_ShadowIter* it = (Unk_ShadowIter*)FUN_1409658c0(FUN_140a01110(&list, pos));
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
                if (FUN_140ddcc90(FUN_1409f7c90()) == 0)
                    visible = false;
            }
        }
    }
    self->m_bShown = shown;
    self->m_bVisible = visible;
}

// @0x1416106e0   build the shadow quad mesh, its render properties and the scene node
// MS2-FUNCTIONAL: transliterated from the decompile; locals, EH states and temp slots differ
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
    radius = radius / 2.0f;

    Unk_Pt3c* verts = (Unk_Pt3c*)FUN_14147b7f0(self, FUN_140a0b280(), 0, 2);   // 4 x NiPoint3
    if (verts != 0) {
        verts[0] = Unk_Pt3c(-radius, -radius, 0.0f);
        verts[1] = Unk_Pt3c(radius, -radius, 0.0f);
        verts[2] = Unk_Pt3c(radius, radius, 0.0f);
        verts[3] = Unk_Pt3c(-radius, radius, 0.0f);
        FUN_14147b850(self, FUN_140a0b280(), 0, 2);
    }
    Unk_Pt2c* uv = (Unk_Pt2c*)FUN_14147b7f0(self, FUN_140a0b6f0(), 0, 2);   // 4 x NiPoint2
    if (uv != 0) {
        uv[0] = Unk_Pt2c(0.0f, 0.0f);
        uv[1] = Unk_Pt2c(0.0f, 1.0f);
        uv[2] = Unk_Pt2c(1.0f, 1.0f);
        uv[3] = Unk_Pt2c(1.0f, 0.0f);
        FUN_14147b850(self, FUN_140a0b6f0(), 0, 2);
    }
    FUN_14147b6d0(self, 0, 0, 1, 2, 3);

    char name[8];
    FUN_140984450(name, "Character Shadow");
    FUN_141d18b90(FUN_140a0afe0(self), name);
    FUN_1409845a0(name);

    CString path(*(CString*)((char*)FUN_1401d31f0() + 0xf0));
    char tex[8];
    FUN_141552f90(FUN_140a0afd0(), tex, path, 1);
    void* texProp;
    MS2_SHADOW_NEW(texProp, 0x58, FUN_141d1d470(mem));
    FUN_140980880(texProp, FUN_14097fbf0(tex));
    FUN_140980200(FUN_140a0afe0(self), texProp);

    void* alpha;
    char alphaPtr[8];
    MS2_SHADOW_NEW(alpha, 0x38, FUN_14097f0b0(mem));
    FUN_140a0a0d0(alphaPtr, alpha);
    FUN_140980560(FUN_140a0abd0(alphaPtr), 1);
    FUN_140980200(FUN_140a0afe0(self), FUN_140a0ab60(alphaPtr));

    void* vcol;
    MS2_SHADOW_NEW(vcol, 0x38, FUN_14097f2d0(mem));
    FUN_140980f20(vcol, 0);
    FUN_140980e60(vcol, 0);
    FUN_140980200(FUN_140a0afe0(self), vcol);

    void* mat;
    char matPtr[8];
    MS2_SHADOW_NEW(mat, 0x78, FUN_141d24d60(mem));
    FUN_1410b1f20(matPtr, mat);
    FUN_1415699c0(FUN_1410b2250(matPtr), Unk_Colc(0.0f, 0.0f, 0.0f));
    FUN_141569980(FUN_1410b2250(matPtr), Unk_Colc(0.0f, 0.0f, 0.0f));
    FUN_1416113a0(FUN_1410b2250(matPtr), Unk_Colc(0.0f, 0.0f, 0.0f));
    FUN_14116d500(FUN_1410b2250(matPtr), Unk_Colc(1.0f, 1.0f, 1.0f));
    FUN_14098e840(FUN_1410b2250(matPtr), DAT_1439f8204);
    FUN_140980200(FUN_140a0afe0(self), FUN_1410b2230(matPtr));

    void* fog;
    MS2_SHADOW_NEW(fog, 0x48, FUN_140a0a3d0(mem));
    FUN_1409a9b90(fog, 0);
    FUN_140980200(FUN_140a0afe0(self), fog);

    void* zbuf;
    char zPtr[8];
    MS2_SHADOW_NEW(zbuf, 0x38, FUN_14097f330(mem));
    FUN_14097eda0(zPtr, zbuf);
    FUN_140981100(FUN_14097fc50(zPtr), 0);
    FUN_140980200(FUN_140a0afe0(self), FUN_14097fc00(zPtr));

    FUN_14147b8b0(self, 4);
    FUN_14147b9c0(self, 6);
    char bound[16];
    FUN_14097f1b0(bound);
    Unk_Pt3c origin(0.0f, 0.0f, 0.0f);
    FUN_140980a70(bound, &origin, radius);
    FUN_14106cea0(FUN_140a0afe0(self), bound);

    void* node;
    MS2_SHADOW_NEW(node, 0x130, FUN_141d19760(mem, 0));
    FUN_1409f76f0(&self->m_node, node);
    Unk_ShadowNode* root = (Unk_ShadowNode*)FUN_1409475f0(&self->m_node);
    root->vfunc_36(FUN_140a0afe0(self), 0);
    FUN_140a0b300(FUN_1409475f0(&self->m_node), 1);
    self->m_bDirty = true;
    Unk_ShadowNode* scene = (Unk_ShadowNode*)FUN_1411a6b10(FUN_1403ed280());
    scene->vfunc_36(FUN_1409475d0(&self->m_node), 1);
    FUN_141d16210(FUN_1409475f0(&self->m_node));
    FUN_141d16370(FUN_1409475f0(&self->m_node));
    float now = (float)FUN_141473280(FUN_14086d260());
    FUN_141d16040(FUN_1409475f0(&self->m_node), now, true);
    FUN_141611370(FUN_140a0afe0(self), 0);
    FUN_14097f4d0(zPtr);
    FUN_1410b1fa0(matPtr);
    FUN_140a0a6b0(alphaPtr);
    FUN_14097f4a0(tex);
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
    FUN_14098e930(mat, 1);
}
