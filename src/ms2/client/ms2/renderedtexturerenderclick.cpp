// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Offscreen "rendered texture" render click (NiViewRenderClick subclass).
// MS2-UNIT: ?\renderedtexturerenderclick.cpp
// MS2-RANGE: 0x1416f8f50-0x1416fa4b0 .text$mn
// MS2-PIN: ??_GRenderedTextureRenderClick@@UEAAPEAXI@Z 0x1416fa1a0
#include "ms2/placeholder/ms2stdafx.h"
#include "renderedtexturerenderclick.h"
#include <Ni3DRenderView.h>
#include <NiMeshCullingProcess.h>
#include <new>

typedef RenderedTextureRenderClick RTRC;
struct Unk_FixedStr { void* p; };   // NiFixedString
struct Unk_Color { float r, g, b, a; };

// ---- out-of-unit callees (bound to the exe by name) ----
void FUN_1409a73e0(void* sp, void* p);   void FUN_14127c2a0(void* sp, void* p);   void FUN_1414748a0(void* sp, void* p);
void FUN_141476010(void* click, int b);  void FUN_141476070(void* click, int b);
void* FUN_14097f1d0(void* out, float r, float g, float b, float a);   void FUN_1414a6200(void* click, void* color);
void FUN_140984450(void* out, const char* s);   void FUN_140985020(void* click, void* name);   void FUN_1409845a0(void* s);
void FUN_141546340(void* sp, void* p);   void FUN_14127c7f0(void* sp, void* p);   void FUN_1414803f0(void* sp, void* p);
void FUN_141474d60(void* sp);   void FUN_14127c650(void* sp);   void FUN_1409a7ad0(void* sp);
void* FUN_140876480(void* out, int cat);   void* FUN_14208a860(unsigned __int64 size, unsigned cat);
void* FUN_1414dbb10(void* sp);   void* FUN_1414dbb20(void* sp);
void FUN_141548150(void* view, void* name);   void FUN_1416b06b0(void* click, void* rtg);
void* FUN_1413f98d0();   void* FUN_141ff5ca0(void* a);   void* FUN_1409a8880(void* tbl, void* key);
void FUN_14169fbf0(void* o, void* click);   void FUN_1414756e0(void* o, void* click);
void* FUN_140994450();   void* FUN_14098d8d0(void* tbl, void* key);
void FUN_141480ab0(void* o, int id);   int FUN_1411d7c70(void* o, void* cb, void* user);
void FUN_1414dbdd0(void* view, void* x);   void FUN_14127d0c0(void* click, void* x);   void FUN_1416b2590(void* click, void* rtg);
void FUN_1409850b0(void* click, int a, int b);   void FUN_140985080(void* click, int a, int b);   void FUN_140985050(void* click, int a, int b);
void FUN_14150a840(void* view, void* a);   void FUN_141547e90(void* view, void* a);
void* FUN_14150ab60(void* view);   void* FUN_140d9e410(void* list);   void* FUN_140d9e420(void* list, void* pos);
void FUN_14097eb60(void* out, void* p);   void* FUN_1409849b0(void* sp);   void FUN_1405a85c0(void* sp);
void FUN_141d1a4f0(void* obj);   void FUN_141d16210(void* obj);   void FUN_1416b20e0(void* view);
void* FUN_14097fbe0(void* sp);   void* FUN_141480470(void* sp);   void* FUN_140980420(void* p);   void FUN_1427e7520(void* p);
void* FUN_14127c9b0(void* sp);   void* FUN_1416ae2e0(void* out, void* p);   void* FUN_1416af8d0(void* sp);   void FUN_1416aed20(void* sp);
void* FUN_141d64910(void* buf, void* renderer);   void* FUN_141d64ee0(void* buf, void* renderer, void* ds);
void* FUN_141d61a80(unsigned w, unsigned h, void* renderer, void* fmt, int flags);   void FUN_140984420(void* out);
void* FUN_1409a8ba0(void* click);   void* FUN_142087e50(void* p);
void* FUN_1409a8150(void* sp);   void* FUN_14127cbb0(void* list);   void* FUN_14127cc00(void* list, void* pos);   void* FUN_140c8f670(void* node);
void FUN_141d54f70(void* view, unsigned frame);
int FUN_140d89680(void* arr);   void* FUN_140d89530(void* arr, unsigned i);   void FUN_141d54bb0(void* arr, unsigned n);   void FUN_140d9d8d0(void* arr);
void FUN_140c8f680(void* sp);
void FUN_140980460(void* p);   void FUN_141474f50(void* o, void* p);   void FUN_1414747a0(void* out, void* p);   void FUN_141474ca0(void* sp);
void FUN_1414978d0(void* p, void* q);   void FUN_1416fa360(void* view, void* cp);
void FUN_14015b310(void* p, unsigned __int64 n);
extern char DAT_143afa7a8, DAT_143afa4d8, DAT_143d6eb58, DAT_143afa7c8;
void FUN_1416f9340(RTRC* p, unsigned w, unsigned h);
void FUN_1416f9b80(RTRC* p, unsigned w, unsigned h);   void FUN_1416f9bf0(RTRC* p, unsigned w = 0, unsigned h = 0);
unsigned FUN_1416fa2d0(void* arr);   int FUN_1416fa2e0(void* list);   float FUN_1416fa2f0();
bool FUN_1416fa120(void* sp, void* p);   bool FUN_1416fa160(void* sp, void* p);   void FUN_1416fa250(void* list, void* node);
int FUN_1416f9b30(char c, void* obj);

#define VSLOT(o, off) ((*(void***)(o))[(off) / 8])

// MS2-FUNCTIONAL: m_spView/m_spTexture/m_spTarget are opaque void* here; the exe constructs them as NiPointer members
//   (ctors 0x1409a73e0/0x14127c2a0/0x1414748a0 with EH states 1..3), passes bool (dl) to 0x141476010 and keeps the
//   NiColorA / NiFixedString locals as real objects (no GS buffer) -> needs the member types recovered across the unit
// @0x1416f8f50
RenderedTextureRenderClick::RenderedTextureRenderClick()
{
    m_uiWidth = 0x80;
    m_uiHeight = 0xa8;
    FUN_1409a73e0(&m_spView, 0);
    FUN_14127c2a0(&m_spTexture, 0);
    FUN_1414748a0(&m_spTarget, 0);
    m_iEventId = -1;
    FUN_141476010(this, 1);
    FUN_141476070(this, 0);
    char col[24];
    void* c = FUN_14097f1d0(col, 0, 0, 0, 0);
    FUN_1414a6200(this, c);
    Unk_FixedStr name;
    FUN_140984450(&name, "RenderedTextureRenderClick");
    FUN_140985020(this, &name);
    FUN_1409845a0(&name);
}

// @0x1416f9070
RenderedTextureRenderClick::~RenderedTextureRenderClick()
{
    FUN_141546340(&m_spView, 0);
    FUN_14127c7f0(&m_spTexture, 0);
    FUN_1414803f0(&m_spTarget, 0);
    FUN_141474d60(&m_spTarget);
    FUN_14127c650(&m_spTexture);
    FUN_1409a7ad0(&m_spView);
}

// @0x1416f9130
void RenderedTextureRenderClick::vfunc_8(unsigned w, unsigned h)
{
    m_uiWidth = w;
    m_uiHeight = h;
    FUN_1416f9b80(this, m_uiWidth, m_uiHeight);
    FUN_1416f9bf0(this, m_uiWidth);
    char t0[8];
    unsigned* cat = (unsigned*)FUN_140876480(t0, 0);
    void* mem = FUN_14208a860(0x70, *cat);
    void* view;
    if (mem == 0) view = 0; else view = ::new (mem) Ni3DRenderView(0, 0, true);
    FUN_141546340(&m_spView, view);
    Unk_FixedStr name;
    FUN_140984450(&name, "RenderTextureRenderView");
    FUN_141548150(FUN_1414dbb20(&m_spView), &name);
    FUN_1409845a0(&name);
    char t1[8];
    FUN_140876480(t1, 0);
    void* cmem = FUN_14208a860(200, 0);
    void* cull;
    if (cmem == 0) cull = 0; else cull = ::new (cmem) NiMeshCullingProcess((NiVisibleArray*)0, (NiSPWorkflowManager*)0);
    FUN_1416fa360(FUN_1414dbb20(&m_spView), cull);
    FUN_1416b06b0(this, FUN_1414dbb10(&m_spView));
}

// @0x1416f9340
void FUN_1416f9340(RTRC* p, unsigned w, unsigned h)
{
    p->m_uiWidth = w;
    p->m_uiHeight = h;
    FUN_1416f9b80(p, p->m_uiWidth, p->m_uiHeight);
    FUN_1416f9bf0(p, p->m_uiWidth, p->m_uiHeight);
    extern void* FUN_1413f9a70();
    FUN_141546340(&p->m_spView, FUN_1413f9a70());
    FUN_1416b06b0(p, FUN_1414dbb10(&p->m_spView));
}

// @0x1416f9400
void RenderedTextureRenderClick::vfunc_9()
{
    void* o = FUN_1409a8880(&DAT_143afa7a8, FUN_141ff5ca0(FUN_1413f98d0()));
    if (o) {
        FUN_14169fbf0(o, this);
        extern void FUN_1416fa310(void*, void*);
        FUN_1416fa310(o, this);
    }
    void* r = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (r) {
        if (m_iEventId != -1) FUN_141480ab0(r, m_iEventId);
        m_iEventId = FUN_1411d7c70(r, (void*)FUN_1416f9b30, this);
    }
}

// @0x1416f94c0
void RenderedTextureRenderClick::vfunc_10()
{
    void* o = FUN_1409a8880(&DAT_143afa7a8, FUN_141ff5ca0(FUN_1413f98d0()));
    if (o) {
        FUN_14169fbf0(o, this);
        FUN_1414756e0(o, this);
    }
    void* r = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (r) {
        if (m_iEventId != -1) FUN_141480ab0(r, m_iEventId);
        m_iEventId = FUN_1411d7c70(r, (void*)FUN_1416f9b30, this);
    }
}

// @0x1416f9580
void RenderedTextureRenderClick::vfunc_11()
{
    vfunc_14();
    void* o = FUN_1409a8880(&DAT_143afa7a8, FUN_141ff5ca0(FUN_1413f98d0()));
    if (o) FUN_14169fbf0(o, this);
    void* r = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (r && m_iEventId != -1) FUN_141480ab0(r, m_iEventId);
    FUN_1414dbdd0(FUN_1414dbb20(&m_spView), 0);
    FUN_1416fa360(FUN_1414dbb20(&m_spView), 0);
    FUN_14127d0c0(this, FUN_1414dbb10(&m_spView));
    FUN_1416b2590(this, 0);
    FUN_1409850b0(this, 0, 0);
    FUN_140985080(this, 0, 0);
    FUN_140985050(this, 0, 0);
    FUN_14127c7f0(&m_spTexture, 0);
}

// @0x1416f96d0
void RenderedTextureRenderClick::vfunc_12(void* a)
{
    if (FUN_1414dbb10(&m_spView)) FUN_14150a840(FUN_1414dbb20(&m_spView), a);
}

// @0x1416f9730
void RenderedTextureRenderClick::vfunc_13(void* a)
{
    if (FUN_1414dbb10(&m_spView)) FUN_141547e90(FUN_1414dbb20(&m_spView), a);
}

// @0x1416f9790
void RenderedTextureRenderClick::vfunc_14()
{
    if (FUN_1414dbb10(&m_spView)) {
        void* list = FUN_14150ab60(FUN_1414dbb20(&m_spView));
        void* pos = FUN_140d9e410(list);
        while (pos) {
            void* e = FUN_140d9e420(list, &pos);
            void* sp[1];
            FUN_14097eb60(sp, e);
            if (FUN_1409849b0(sp)) {
                void* obj = FUN_14098d8d0(&DAT_143afa4d8, FUN_1409849b0(sp));
                if (obj) {
                    FUN_141d1a4f0(obj);
                    FUN_141d16210(obj);
                }
            }
            FUN_1405a85c0(sp);
        }
        FUN_1416b20e0(FUN_1414dbb20(&m_spView));
    }
}

// @0x1416f9890
void RenderedTextureRenderClick::vfunc_15(char bFree)
{
    if (bFree == 0) {
        FUN_1416f9b80(this, m_uiWidth, m_uiHeight);
        FUN_1416f9bf0(this, m_uiWidth, m_uiHeight);
    } else {
        if (FUN_14097fbe0(&m_spTarget)) {
            void* g = FUN_141480470(&m_spTarget);
            typedef void* (*Fn)(void*, int);
            void* b = ((Fn)VSLOT(g, 0xd8))(g, 0);
            if (b) {
                void* d = FUN_140980420(b);
                if (d) FUN_1427e7520(d);
            }
        }
        FUN_14127c7f0(&m_spTexture, 0);
        FUN_1414803f0(&m_spTarget, 0);
        FUN_1416b2590(this, 0);
    }
}

// @0x1416f99b0
void RenderedTextureRenderClick::vfunc_16() {}

// @0x1416f99d0
void FUN_1416f99d0(RTRC* p, void* a)
{
    if (FUN_1414dbb10(&p->m_spView)) FUN_1414dbdd0(FUN_1414dbb20(&p->m_spView), a);
}

// @0x1416f9a30
void* FUN_1416f9a30(RTRC* p)
{
    void* r;
    if (FUN_1414dbb10(&p->m_spView) == 0) r = 0;
    else {
        extern void* FUN_1409a8a60(void*);
        r = FUN_1409a8a60(FUN_1414dbb20(&p->m_spView));
    }
    return r;
}

// @0x1416f9a80
float FUN_1416f9a80(RTRC* p) { return (float)p->m_uiWidth / (float)p->m_uiHeight; }

// @0x1416f9ab0
void FUN_1416f9ab0(RTRC* p) { FUN_140c8f680(&p->m_spTexture); }

// @0x1416f9ae0
void* GetValue_1416f9ae0(RTRC* p, void* out)
{
    extern void FUN_1416fa0e0(void*, void*);
    FUN_1416fa0e0(out, &p->m_spView);
    return out;
}

// @0x1416f9b30
int FUN_1416f9b30(char c, void* obj)
{
    if (obj) {
        typedef void (*Fn)(void*, char);
        ((Fn)VSLOT(obj, 0x78))(obj, c);
    }
    return 1;
}

// @0x1416f9b80
void FUN_1416f9b80(RTRC* p, unsigned w, unsigned h)
{
    struct { int a; int b; int c; } fmt;                            // FUN_140984420 fills three ints (12 bytes)
    FUN_140984420(&fmt);
    fmt.b = 2;
    void* tex = FUN_141d61a80(w, h, FUN_140994450(), &fmt, 0x100);
    FUN_14127c7f0(&p->m_spTexture, tex);
}

// @0x1416f9bf0
void FUN_1416f9bf0(RTRC* p, unsigned, unsigned)
{
    if (!FUN_1416fa160(&p->m_spTexture, 0)) {
        void* tex = FUN_14127c9b0(&p->m_spTexture);
        typedef void* (*Fn)(void*);
        void* buf = ((Fn)VSLOT(tex, 0xa0))(tex);
        if (buf) {
            void* ds = FUN_141d64910(buf, FUN_140994450());
            void* sp[1];
            FUN_1416ae2e0(sp, ds);
            if (!FUN_1416fa120(sp, 0)) {
                void* d = FUN_1416af8d0(sp);
                void* rtg = FUN_141d64ee0(buf, FUN_140994450(), d);
                FUN_1414803f0(&p->m_spTarget, rtg);
                if (FUN_14097fbe0(&p->m_spTarget)) FUN_1416b2590(p, FUN_14097fbe0(&p->m_spTarget));
                FUN_1416aed20(sp);
            } else {
                FUN_1416aed20(sp);
            }
        }
    }
}

// @0x1416f9d40
void RenderedTextureRenderClick::PerformRendering(unsigned int uiFrameID)
{
    if (FUN_140994450()) {
        void* name = FUN_142087e50(FUN_1409a8ba0(this));
        extern void FUN_141d27bf0(void*, const char*, ...);
        FUN_141d27bf0(FUN_140994450(), "ViewRC(%s)", name);
    }
    if (FUN_1416fa2e0(&m_kRenderViews)) {
        void* renderer = FUN_140994450();
        void* proc = FUN_1409a8150(&m_spProcessor);
        if (proc == 0) proc = FUN_1409a8150(&DAT_143afa7c8);
        m_uiNumObjectsDrawn = 0;
        m_fRenderTime = 0.0f;
        m_fCullTime = 0.0f;
        void* pos = FUN_14127cbb0(&m_kRenderViews);
        while (pos) {
            void* node = FUN_14127cc00(&m_kRenderViews, &pos);
            void* view = FUN_140c8f670(node);
            typedef void (*SetCam)(void*, void*);
            ((SetCam)VSLOT(view, 0x18))(view, &m_kViewport);
            float t0 = FUN_1416fa2f0();
            void* pv = (void*)&((NiRenderView*)view)->GetPVGeometry(uiFrameID);
            float t1 = FUN_1416fa2f0();
            m_fCullTime = m_fCullTime + (t1 - t0);
            m_uiNumObjectsDrawn = FUN_140d89680(pv) + m_uiNumObjectsDrawn;
            if (FUN_1416fa2d0(&m_kProcessedGeometry) < (unsigned)FUN_140d89680(pv))
                FUN_141d54bb0(&m_kProcessedGeometry, FUN_140d89680(pv));
            t0 = FUN_1416fa2f0();
            typedef void (*Pre)(void*, void*, void*, void*);
            ((Pre)VSLOT(proc, 0x18))(proc, pv, &m_kProcessedGeometry, m_pvProcessorData);
            unsigned n = FUN_140d89680(&m_kProcessedGeometry);
            for (unsigned i = 0; i < n; i = i + 1) {
                void* g = FUN_140d89530(&m_kProcessedGeometry, i);
                typedef void (*Fn)(void*, void*);
                ((Fn)VSLOT(g, 0x120))(g, renderer);
            }
            typedef void (*Post)(void*, void*, void*);
            ((Post)VSLOT(proc, 0x20))(proc, &m_kProcessedGeometry, m_pvProcessorData);
            t1 = FUN_1416fa2f0();
            m_fRenderTime = m_fRenderTime + (t1 - t0);
            FUN_140d9d8d0(&m_kProcessedGeometry);
        }
        if (FUN_140994450()) {
            void* r = FUN_140994450();
            typedef void (*Fn)(void*);
            ((Fn)VSLOT(r, 0x200))(r);
        }
    }
}

// @0x1416fa0e0
void FUN_1416fa0e0(void* dst, void* src)
{
    void** d = (void**)dst;
    *d = *(void**)src;
    if (*d) FUN_140980460(*d);
}

// @0x1416fa120
bool FUN_1416fa120(void* sp, void* p) { return *(void**)sp == p; }

// @0x1416fa160
bool FUN_1416fa160(void* sp, void* p) { return *(void**)sp == p; }

// @0x1416fa200
void FUN_1416fa200(void* list, void* p)
{
    typedef void* (*Fn)(void*);
    void* node = ((Fn)VSLOT(list, 8))(list);
    FUN_141474f50((char*)node + 0x10, p);
    FUN_1416fa250(list, node);
}

// @0x1416fa250
void FUN_1416fa250(void* list, void* node)
{
    struct N { N* next; N* prev; };
    struct L { char pad[8]; N* head; N* tail; int count; };
    L* l = (L*)list;
    N* n = (N*)node;
    n->prev = 0;
    n->next = l->head;
    if (l->head == 0) l->tail = n; else l->head->prev = n;
    l->head = n;
    l->count = l->count + 1;
}

// @0x1416fa2d0
unsigned FUN_1416fa2d0(void* arr) { return *(unsigned*)((char*)arr + 0xc); }

// @0x1416fa2e0
int FUN_1416fa2e0(void* list) { return *(int*)((char*)list + 0x18); }

// @0x1416fa2f0
float FUN_1416fa2f0() { return (float)efd::GetCurrentTimeInSec(); }

// @0x1416fa310
void FUN_1416fa310(void* o, void* click)
{
    char tmp[8];
    FUN_1414747a0(tmp, click);
    FUN_1416fa200((char*)o + 0x50, tmp);
    FUN_141474ca0(tmp);
}

// @0x1416fa360
void FUN_1416fa360(void* view, void* cp) { FUN_1414978d0((char*)view + 0x40, cp); }

// the UCRT header-inline memmove_s, emitted here as an ordinary function
#include <errno.h>
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)   \
    {                                                  \
        int _Expr_val = !!(expr);                      \
        if (!(_Expr_val)) {                            \
            errno = errorcode;                         \
            _invalid_parameter_noinfo();               \
            return errorcode;                          \
        }                                              \
    }
// @0x1416fa390
errno_t FUN_1416fa390(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
#include "hook/ms2hook.h"
MS2_REPLACE(0x1416f9340, FUN_1416f9340, 176, 0xAAF40A58);
MS2_REPLACE_METHOD(0x1416f9400, RenderedTextureRenderClick, vfunc_9, 186, 0xA0BFFCA6);
MS2_REPLACE_METHOD(0x1416f94c0, RenderedTextureRenderClick, vfunc_10, 186, 0x085730A0);
MS2_REPLACE_METHOD(0x1416f9580, RenderedTextureRenderClick, vfunc_11, 322, 0xBEFA002A);
MS2_REPLACE_METHOD(0x1416f96d0, RenderedTextureRenderClick, vfunc_12, 75, 0x490DABBE);
MS2_REPLACE_METHOD(0x1416f9730, RenderedTextureRenderClick, vfunc_13, 75, 0xAFAEFC13);
MS2_REPLACE_METHOD(0x1416f9790, RenderedTextureRenderClick, vfunc_14, 248, 0x22CA9050);
MS2_REPLACE_METHOD(0x1416f9890, RenderedTextureRenderClick, vfunc_15, 268, 0x3C8AFFDE);
MS2_REPLACE_METHOD(0x1416f99b0, RenderedTextureRenderClick, vfunc_16, 18, 0x23F7B45B);
MS2_REPLACE(0x1416f99d0, FUN_1416f99d0, 75, 0xC7F7E72D);
MS2_REPLACE(0x1416f9a30, FUN_1416f9a30, 69, 0xD991FF44);
MS2_REPLACE(0x1416f9a80, FUN_1416f9a80, 42, 0xE184552A);
MS2_REPLACE(0x1416f9ab0, FUN_1416f9ab0, 33, 0xFE4E70E9);
MS2_REPLACE(0x1416f9ae0, GetValue_1416f9ae0, 67, 0x6AB96D37);
MS2_REPLACE(0x1416f9b30, FUN_1416f9b30, 59, 0xBD7A40FD);
MS2_REPLACE(0x1416f9b80, FUN_1416f9b80, 94, 0xA3074616);
MS2_REPLACE(0x1416f9bf0, FUN_1416f9bf0, 320, 0x1B964556);
MS2_REPLACE(0x1416fa0e0, FUN_1416fa0e0, 64, 0xEABE6B59);
MS2_REPLACE(0x1416fa120, FUN_1416fa120, 54, 0xCED6F715);
MS2_REPLACE(0x1416fa160, FUN_1416fa160, 54, 0xCED6F715);
MS2_REPLACE(0x1416fa200, FUN_1416fa200, 77, 0x0CBCD6FF);
MS2_REPLACE(0x1416fa250, FUN_1416fa250, 119, 0x1B86029C);
MS2_REPLACE(0x1416fa2d0, FUN_1416fa2d0, 14, 0xAAC7684B);
MS2_REPLACE(0x1416fa2e0, FUN_1416fa2e0, 14, 0x72E52537);
MS2_REPLACE(0x1416fa2f0, FUN_1416fa2f0, 18, 0x7B3D87A5);
MS2_REPLACE(0x1416fa310, FUN_1416fa310, 77, 0xE6808211);
MS2_REPLACE(0x1416fa360, FUN_1416fa360, 41, 0x28FD4F05);

