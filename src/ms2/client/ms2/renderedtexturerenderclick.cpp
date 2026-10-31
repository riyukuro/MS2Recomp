// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Offscreen "rendered texture" render click (NiViewRenderClick subclass).
// MS2-UNIT: ?\renderedtexturerenderclick.cpp
// MS2-RANGE: 0x1416f8f50-0x1416fa4b0 .text$mn
// MS2-PIN: ??_GRenderedTextureRenderClick@@UEAAPEAXI@Z 0x1416fa1a0
// MS2-PIN: ??0Unk_RtFormatPrefs@@QEAA@XZ 0x140984420
// MS2-PIN: ??0Unk_RtObjPtr@@QEAA@PEAX@Z 0x14097eb60
// MS2-PIN: ??1Unk_RtObjPtr@@QEAA@XZ 0x1405a85c0
// MS2-PIN: ??0Unk_RtDepthPtr@@QEAA@PEAX@Z 0x1416ae2e0
// MS2-PIN: ??1Unk_RtDepthPtr@@QEAA@XZ 0x1416aed20
// MS2-PIN: ??0Unk_RtColor@@QEAA@MMMM@Z 0x14097f1d0
// MS2-PIN: ??0Unk_RtFixedStr@@QEAA@PEBD@Z 0x140984450
// MS2-PIN: ??1Unk_RtFixedStr@@QEAA@XZ 0x1409845a0
// MS2-PIN: ??0Unk_RtViewPtr@@QEAA@PEAX@Z 0x1409a73e0
// MS2-PIN: ??0Unk_RtTexturePtr@@QEAA@PEAX@Z 0x14127c2a0
// MS2-PIN: ??1Unk_RtTexturePtr@@QEAA@XZ 0x14127c650
// MS2-PIN: ??0Unk_RtTargetPtr@@QEAA@PEAX@Z 0x1414748a0
// MS2-PIN: ??1Unk_RtTargetPtr@@QEAA@XZ 0x141474d60
// MS2-PIN: ??2Unk_RtNiNew@@SAPEAX_KI@Z 0x14208a860
// MS2-PIN: ??3Unk_RtNiNew@@SAXPEAXI@Z 0x14097f700
// MS2-PIN: ??0Unk_Rt3DRenderView@@QEAA@PEAX0_N@Z 0x140d9de30
// MS2-PIN: ??0Unk_RtMeshCullingProcess@@QEAA@PEAX0@Z 0x141e2eaf0
// MS2-PIN: ??0Unk_RtClickPtr@@QEAA@PEAX@Z 0x1414747a0
// MS2-PIN: ??1Unk_RtClickPtr@@QEAA@XZ 0x141474ca0
// MS2-PIN: ??0Unk_RtViewPtr@@QEAA@AEBU0@@Z 0x1416fa0e0
// MS2-PIN: ??1Unk_RtViewPtr@@QEAA@XZ 0x1409a7ad0
// MS2-PIN: ?GetValue_1416f9ae0@RenderedTextureRenderClick@@QEAA?AUUnk_RtViewPtr@@XZ 0x1416f9ae0
#include "ms2/placeholder/ms2stdafx.h"
#include "renderedtexturerenderclick.h"
#include <Ni3DRenderView.h>
#include <NiMeshCullingProcess.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderedTexture.h>
#include <NiRenderObject.h>
#include <new>

typedef RenderedTextureRenderClick RTRC;
struct Unk_FixedStr { void* p; };   // NiFixedString
struct Unk_Color { float r, g, b, a; };

// ---- out-of-unit callees (bound to the exe by name) ----
  void FUN_141476070(void* click, int b);
struct Unk_RtColor { float r, g, b, a; Unk_RtColor(float r, float g, float b, float a); };   // NiColorA, ctor 0x14097f1d0
struct Unk_RtFixedStr {                          // NiFixedString
    void* m_p;
    Unk_RtFixedStr(const char* s);              // 0x140984450
    ~Unk_RtFixedStr();                          // 0x1409845a0
};
void FUN_141546340(void* sp, void* p);   void FUN_14127c7f0(void* sp, void* p);   void FUN_1414803f0(void* sp, void* p);
void* FUN_140876480(void* out, int cat);
struct Unk_RtNiNew {                            // NiNew: the engine's tracked allocator and its matching free
    static void* operator new(unsigned __int64 size, unsigned cat);   // 0x14208a860
    static void operator delete(void* p, unsigned cat);               // 0x14097f700
};
struct Unk_Rt3DRenderView : Unk_RtNiNew { char m_pad[0x70]; Unk_Rt3DRenderView(void* a, void* b, bool c); };   // ctor 0x140d9de30
struct Unk_RtMeshCullingProcess : Unk_RtNiNew { char m_pad[200]; Unk_RtMeshCullingProcess(void* a, void* b); }; // ctor 0x141e2eaf0   void* FUN_14208a860(unsigned __int64 size, unsigned cat);
void* FUN_1414dbb10(void* sp);   void* FUN_1414dbb20(void* sp);
void* FUN_1413f98d0();   void* FUN_141ff5ca0(void* a);
class NiRenderStep   // C3: static member view for the former free stand-ins
{
public:
    static class NiRenderStep* DynamicCast(class NiRTTI const*, class NiRenderStep const*);
};
class NiDefaultClickRenderStep   // C3: member view for the former free stand-ins
{
public:
    void AppendRenderClick(class NiRenderClick*);
    void RemoveRenderClick(class NiRenderClick*);
};
class NiDX9Renderer   // C3: member view for the former free stand-ins
{
public:
    bool RemoveResetNotificationFunc(unsigned int);
};
   int FUN_1411d7c70(void* o, void* cb, void* user);
void FUN_1409850b0(void* click, int a, int b);   void FUN_140985080(void* click, int a, int b);   void FUN_140985050(void* click, int a, int b);
   void* FUN_140d9e420(void* list, void* pos);
void FUN_14097eb60(void* out, void* p);   void* FUN_1409849b0(void* sp);   void FUN_1405a85c0(void* sp);
void FUN_141d1a4f0(void* obj);
void* FUN_14097fbe0(void* sp);   NiRenderTargetGroup* FUN_141480470(void* sp);   void FUN_1427e7520(void* p);
NiRenderedTexture* FUN_14127c9b0(void* sp);   void* FUN_1416af8d0(void* sp);
struct Unk_RtFormatPrefs { int a; int b; int c; Unk_RtFormatPrefs(); };   // NiTexture::FormatPrefs, ctor 0x140984420
void* FUN_1409a8ba0(void* click);   void* FUN_142087e50(void* p);
void* FUN_1409a8150(void* sp);   void* FUN_14127cc00(void* list, void* pos);   void* FUN_140c8f670(void* node);
int FUN_140d89680(void* arr);class Unk_PtrArray   // C3: member view for the former free stand-ins
{
public:
    void RemoveAll();
};
void FUN_140c8f680(void* sp);
   void FUN_141474f50(void* o, void* p);   void FUN_1414747a0(void* out, void* p);   void FUN_141474ca0(void* sp);
void FUN_1414978d0(void* p, void* q);   void FUN_1416fa360(void* view, void* cp);
void FUN_14015b310(void* p, unsigned __int64 n);
extern char DAT_143afa7a8, DAT_143afa4d8, DAT_143d6eb58, DAT_143afa7c8;
void FUN_1416f9340(RTRC* p, unsigned w, unsigned h);
void FUN_1416f9b80(RTRC* p, unsigned w, unsigned h);   void FUN_1416f9bf0(RTRC* p, unsigned w = 0, unsigned h = 0);
unsigned FUN_1416fa2d0(void* arr);   int FUN_1416fa2e0(void* list);   float FUN_1416fa2f0();
bool FUN_1416fa120(void* sp, void* p);   bool FUN_1416fa160(void* sp, void* p);   void FUN_1416fa250(struct Unk_RtClickList* l, struct Unk_RtClickNode* n);
bool FUN_1416f9b30(char c, void* obj);
struct Unk_RtEventTarget {                      // the event-callback user object (the click's owner); slot 15 is the notify
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(char c);
};
struct Unk_RtClickNode { Unk_RtClickNode* next; Unk_RtClickNode* prev; };
struct Unk_RtClickList {                        // NiTPointerList<NiRenderClickPtr>: slot 1 allocates a node
    virtual void vfunc_0(); virtual Unk_RtClickNode* vfunc_1();
    Unk_RtClickNode* head; Unk_RtClickNode* tail; int count;
};
struct Unk_RtObjPtr {                           // NiPointer<NiAVObject> temp
    void* m_p;
    Unk_RtObjPtr(void* p);                      // 0x14097eb60
    ~Unk_RtObjPtr();                            // 0x1405a85c0
};
struct Unk_RtDepthPtr {                         // NiPointer<NiDepthStencilBuffer> temp
    void* m_p;
    Unk_RtDepthPtr(void* p);                    // 0x1416ae2e0
    ~Unk_RtDepthPtr();                          // 0x1416aed20
};
struct Unk_RtClickPtr {                         // NiPointer<NiRenderClick> temp
    void* m_p;
    Unk_RtClickPtr(void* p);                    // 0x1414747a0
    ~Unk_RtClickPtr();                          // 0x141474ca0
};

#define VSLOT(o, off) ((*(void***)(o))[(off) / 8])

// MS2-FUNCTIONAL: m_spView/m_spTexture/m_spTarget are opaque void* here; the exe constructs them as NiPointer members
//   (ctors 0x1409a73e0/0x14127c2a0/0x1414748a0 with EH states 1..3), passes bool (dl) to 0x141476010 and keeps the
//   NiColorA / NiFixedString locals as real objects (no GS buffer) -> needs the member types recovered across the unit
// @0x1416f8f50
RenderedTextureRenderClick::RenderedTextureRenderClick()
    : m_uiWidth(0x80), m_uiHeight(0xa8), m_spView(0), m_spTexture(0), m_spTarget(0), m_iEventId(-1)
{
    ((class NiRenderClick*)(void*)(this))->SetClearAllBuffers(true);
    FUN_141476070(this, 0);
    ((class NiRenderClick*)(void*)(this))->SetBackgroundColor(reinterpret_cast<class NiColorA const&>(static_cast<const Unk_RtColor&>(Unk_RtColor(0.0f, 0.0f, 0.0f, 0.0f))));
    Unk_RtFixedStr name("RenderedTextureRenderClick");
    ((class NiRenderClick*)(void*)(this))->SetName(*(class NiFixedString const*)&(name));
}

// @0x1416f9070
RenderedTextureRenderClick::~RenderedTextureRenderClick()
{
    FUN_141546340(&m_spView, 0);
    FUN_14127c7f0(&m_spTexture, 0);
    FUN_1414803f0(&m_spTarget, 0);
}

// @0x1416f9130
void RenderedTextureRenderClick::vfunc_8(unsigned w, unsigned h)
{
    m_uiWidth = w;
    m_uiHeight = h;
    FUN_1416f9b80(this, m_uiWidth, m_uiHeight);
    FUN_1416f9bf0(this, m_uiWidth, m_uiHeight);
    unsigned t0;
    unsigned* cat = (unsigned*)FUN_140876480(&t0, 0);
    FUN_141546340(&m_spView, new (*cat) Unk_Rt3DRenderView(0, 0, true));
    {
        Unk_RtFixedStr name("RenderTextureRenderView");
        ((class NiRenderView*)(void*)(FUN_1414dbb20(&m_spView)))->SetName(*(class NiFixedString const*)&(name));
    }
    unsigned t1;
    unsigned* cat1 = (unsigned*)FUN_140876480(&t1, 0);
    Unk_RtMeshCullingProcess* pCull = new (*cat1) Unk_RtMeshCullingProcess(0, 0);
    FUN_1416fa360(FUN_1414dbb20(&m_spView), pCull);
    ((class NiViewRenderClick*)(void*)(this))->AppendRenderView((class NiRenderView*)(FUN_1414dbb10(&m_spView)));
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
    ((class NiViewRenderClick*)(void*)(p))->AppendRenderView((class NiRenderView*)(FUN_1414dbb10(&p->m_spView)));
}

// @0x1416f9400
void RenderedTextureRenderClick::vfunc_9()
{
    void* o = ((void*)NiRenderStep::DynamicCast((class NiRTTI const*)(&DAT_143afa7a8), (class NiRenderStep const*)(FUN_141ff5ca0(FUN_1413f98d0()))));
    if (o) {
        ((class NiDefaultClickRenderStep*)(void*)(o))->RemoveRenderClick((class NiRenderClick*)(this));
        extern void FUN_1416fa310(void*, void*);
        FUN_1416fa310(o, this);
    }
    void* r = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143d6eb58), (class NiObject const*)(((void*)NiRenderer::GetRenderer()))));
    if (r) {
        if (m_iEventId != -1) ((class NiDX9Renderer*)(void*)(r))->RemoveResetNotificationFunc(m_iEventId);
        m_iEventId = FUN_1411d7c70(r, (void*)FUN_1416f9b30, this);
    }
}

// @0x1416f94c0
void RenderedTextureRenderClick::vfunc_10()
{
    void* o = ((void*)NiRenderStep::DynamicCast((class NiRTTI const*)(&DAT_143afa7a8), (class NiRenderStep const*)(FUN_141ff5ca0(FUN_1413f98d0()))));
    if (o) {
        ((class NiDefaultClickRenderStep*)(void*)(o))->RemoveRenderClick((class NiRenderClick*)(this));
        ((class NiDefaultClickRenderStep*)(void*)(o))->AppendRenderClick((class NiRenderClick*)(this));
    }
    void* r = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143d6eb58), (class NiObject const*)(((void*)NiRenderer::GetRenderer()))));
    if (r) {
        if (m_iEventId != -1) ((class NiDX9Renderer*)(void*)(r))->RemoveResetNotificationFunc(m_iEventId);
        m_iEventId = FUN_1411d7c70(r, (void*)FUN_1416f9b30, this);
    }
}

// @0x1416f9580
void RenderedTextureRenderClick::vfunc_11()
{
    vfunc_14();
    void* o = ((void*)NiRenderStep::DynamicCast((class NiRTTI const*)(&DAT_143afa7a8), (class NiRenderStep const*)(FUN_141ff5ca0(FUN_1413f98d0()))));
    if (o) ((class NiDefaultClickRenderStep*)(void*)(o))->RemoveRenderClick((class NiRenderClick*)(this));
    void* r = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143d6eb58), (class NiObject const*)(((void*)NiRenderer::GetRenderer()))));
    if (r && m_iEventId != -1) ((class NiDX9Renderer*)(void*)(r))->RemoveResetNotificationFunc(m_iEventId);
    ((class Ni3DRenderView*)(void*)(FUN_1414dbb20(&m_spView)))->SetCamera((class NiCamera*)(0));
    FUN_1416fa360(FUN_1414dbb20(&m_spView), 0);
    ((class NiViewRenderClick*)(void*)(this))->RemoveRenderView((class NiRenderView*)(FUN_1414dbb10(&m_spView)));
    ((class NiRenderClick*)(void*)(this))->SetRenderTargetGroup((class NiRenderTargetGroup*)(0));
    FUN_1409850b0(this, 0, 0);
    FUN_140985080(this, 0, 0);
    FUN_140985050(this, 0, 0);
    FUN_14127c7f0(&m_spTexture, 0);
}

// @0x1416f96d0
void RenderedTextureRenderClick::vfunc_12(void* a)
{
    if (FUN_1414dbb10(&m_spView)) ((class Ni3DRenderView*)(void*)(FUN_1414dbb20(&m_spView)))->AppendScene((class NiAVObject*)(a));
}

// @0x1416f9730
void RenderedTextureRenderClick::vfunc_13(void* a)
{
    if (FUN_1414dbb10(&m_spView)) ((class Ni3DRenderView*)(void*)(FUN_1414dbb20(&m_spView)))->RemoveScene((class NiAVObject*)(a));
}

// @0x1416f9790
void RenderedTextureRenderClick::vfunc_14()
{
    if (FUN_1414dbb10(&m_spView)) {
        void* list = ((void*)&((class Ni3DRenderView*)(void*)(FUN_1414dbb20(&m_spView)))->GetScenes());
        void* pos = ((NiTListBase<NiTPointerAllocator<unsigned __int64>, efd::SmartPointer<NiAVObject>>*)(void*)(list))->GetHeadPos();
        while (pos) {
            Unk_RtObjPtr sp(FUN_140d9e420(list, &pos));
            if (FUN_1409849b0(&sp)) {
                void* obj = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afa4d8), (class NiObject const*)(FUN_1409849b0(&sp))));
                if (obj) {
                    FUN_141d1a4f0(obj);
                    ((class NiAVObject*)(void*)(obj))->UpdateEffects();
                }
            }
        }
        ((class Ni3DRenderView*)(void*)(FUN_1414dbb20(&m_spView)))->RemoveAllScenes();
    }
}

// @0x1416f9890
void RenderedTextureRenderClick::vfunc_15(bool bFree)
{
    if (bFree) {
        if (FUN_14097fbe0(&m_spTarget)) {
            void* b = FUN_141480470(&m_spTarget)->GetBuffer(0);
            if (b) {
                void* d = ((void*)((class Ni2DBuffer*)(void*)(b))->GetRendererData());
                if (d) FUN_1427e7520(d);
            }
        }
        FUN_14127c7f0(&m_spTexture, 0);
        FUN_1414803f0(&m_spTarget, 0);
        ((class NiRenderClick*)(void*)(this))->SetRenderTargetGroup((class NiRenderTargetGroup*)(0));
    } else {
        FUN_1416f9b80(this, m_uiWidth, m_uiHeight);
        FUN_1416f9bf0(this, m_uiWidth, m_uiHeight);
    }
}

// @0x1416f99b0
void RenderedTextureRenderClick::vfunc_16(float, float) {}

// @0x1416f99d0
void FUN_1416f99d0(RTRC* p, void* a)
{
    if (FUN_1414dbb10(&p->m_spView)) ((class Ni3DRenderView*)(void*)(FUN_1414dbb20(&p->m_spView)))->SetCamera((class NiCamera*)(a));
}

// @0x1416f9a30
void* FUN_1416f9a30(RTRC* p)
{
    extern void* FUN_1409a8a60(void*);
    if (FUN_1414dbb10(&p->m_spView)) return FUN_1409a8a60(FUN_1414dbb20(&p->m_spView));
    return 0;
}

// @0x1416f9a80
float FUN_1416f9a80(RTRC* p) { return (float)p->m_uiWidth / (float)p->m_uiHeight; }

// @0x1416f9ab0
void FUN_1416f9ab0(RTRC* p) { FUN_140c8f680(&p->m_spTexture); }

// @0x1416f9ae0
Unk_RtViewPtr RenderedTextureRenderClick::GetValue_1416f9ae0()
{
    return m_spView;
}

// @0x1416f9b30
bool FUN_1416f9b30(char c, void* obj)
{
    Unk_RtEventTarget* p = (Unk_RtEventTarget*)obj;
    if (p) p->vfunc_15(c);
    return true;
}

// @0x1416f9b80
void FUN_1416f9b80(RTRC* p, unsigned w, unsigned h)
{
    Unk_RtFormatPrefs fmt;
    fmt.b = 2;
    FUN_14127c7f0(&p->m_spTexture, ((void*)NiRenderedTexture::Create(w, h, (class NiRenderer*)(((void*)NiRenderer::GetRenderer())), *(class NiTexture::FormatPrefs*)(&fmt), 0x100)));
}

// @0x1416f9bf0
void FUN_1416f9bf0(RTRC* p, unsigned, unsigned)
{
    if (FUN_1416fa160(&p->m_spTexture, 0)) return;
    Ni2DBuffer* buf = FUN_14127c9b0(&p->m_spTexture)->GetBuffer();
    if (!buf) return;
    Unk_RtDepthPtr sp(((void*)NiDepthStencilBuffer::CreateCompatible((class Ni2DBuffer*)(buf), (class NiRenderer*)(((void*)NiRenderer::GetRenderer())))));
    if (FUN_1416fa120(&sp, 0)) return;
    FUN_1414803f0(&p->m_spTarget, ((void*)NiRenderTargetGroup::Create((class Ni2DBuffer*)(buf), (class NiRenderer*)(((void*)NiRenderer::GetRenderer())), (class NiDepthStencilBuffer*)(FUN_1416af8d0(&sp)))));
    if (FUN_14097fbe0(&p->m_spTarget)) ((class NiRenderClick*)(void*)(p))->SetRenderTargetGroup((class NiRenderTargetGroup*)(FUN_14097fbe0(&p->m_spTarget)));
}

// @0x1416f9d40
void RenderedTextureRenderClick::PerformRendering(unsigned int uiFrameID)
{
    extern void FUN_141d27bf0(void*, const char*, ...);
    for (;;) {
        if (((void*)NiRenderer::GetRenderer())) FUN_141d27bf0(((void*)NiRenderer::GetRenderer()), "ViewRC(%s)", FUN_142087e50(FUN_1409a8ba0(this)));
        break;
    }
    if (!FUN_1416fa2e0(&m_kRenderViews)) return;
    NiRenderer* renderer = (NiRenderer*)((void*)NiRenderer::GetRenderer());
    NiRenderListProcessor* proc = (NiRenderListProcessor*)FUN_1409a8150(&m_spProcessor);
    if (proc == 0) proc = (NiRenderListProcessor*)FUN_1409a8150(&DAT_143afa7c8);
    m_uiNumObjectsDrawn = 0;
    m_fRenderTime = 0.0f;
    m_fCullTime = 0.0f;
    void* pos = ((NiTListBase<NiTPointerAllocator<unsigned __int64>, efd::SmartPointer<NiRenderView>>*)(void*)(&m_kRenderViews))->GetHeadPos();
    while (pos) {
        NiRenderView* view = (NiRenderView*)FUN_140c8f670(FUN_14127cc00(&m_kRenderViews, &pos));
        view->SetCameraData(m_kViewport);
        float t0 = FUN_1416fa2f0();
        NiVisibleArray* pv = (NiVisibleArray*)((void*)&((class NiRenderView*)(void*)(view))->GetPVGeometry(uiFrameID));
        m_fCullTime = m_fCullTime + (FUN_1416fa2f0() - t0);
        m_uiNumObjectsDrawn = FUN_140d89680(pv) + m_uiNumObjectsDrawn;
        if (FUN_1416fa2d0(&m_kProcessedGeometry) < (unsigned)FUN_140d89680(pv))
            ((class NiVisibleArray*)(void*)(&m_kProcessedGeometry))->SetAllocatedSize(FUN_140d89680(pv));
        t0 = FUN_1416fa2f0();
        proc->PreRenderProcessList(pv, m_kProcessedGeometry, m_pvProcessorData);
        unsigned n = FUN_140d89680(&m_kProcessedGeometry);
        for (unsigned i = 0; i < n; i++) {
            NiRenderObject* g = (NiRenderObject*)((void*)&((class NiVisibleArray*)(void*)(&m_kProcessedGeometry))->GetAt(i));
            g->RenderImmediate(renderer);
        }
        proc->PostRenderProcessList(m_kProcessedGeometry, m_pvProcessorData);
        m_fRenderTime = m_fRenderTime + (FUN_1416fa2f0() - t0);
        ((class Unk_PtrArray*)(void*)(&m_kProcessedGeometry))->RemoveAll();
    }
    for (;;) {
        if (((void*)NiRenderer::GetRenderer())) ((NiRenderer*)((void*)NiRenderer::GetRenderer()))->PopProfileMarker();
        break;
    }
}

// @0x1416fa0e0
Unk_RtViewPtr::Unk_RtViewPtr(const Unk_RtViewPtr& o)
{
    m_p = o.m_p;
    if (m_p) ((class NiRefObject*)(void*)(m_p))->IncRefCount();
}

// @0x1416fa120
bool FUN_1416fa120(void* sp, void* p) { return *(void**)sp == p; }

// @0x1416fa160
bool FUN_1416fa160(void* sp, void* p) { return *(void**)sp == p; }

// @0x1416fa200
void FUN_1416fa200(Unk_RtClickList* l, void* p)
{
    Unk_RtClickNode* node = l->vfunc_1();
    FUN_141474f50((char*)node + 0x10, p);
    FUN_1416fa250(l, node);
}

// @0x1416fa250
void FUN_1416fa250(Unk_RtClickList* l, Unk_RtClickNode* n)
{
    n->prev = 0;
    n->next = l->head;
    if (l->head) l->head->prev = n; else l->tail = n;
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
    Unk_RtClickPtr tmp(click);
    FUN_1416fa200((Unk_RtClickList*)((char*)o + 0x50), &tmp);
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
MS2_REPLACE_METHOD(0x1416f9ae0, RenderedTextureRenderClick, GetValue_1416f9ae0, 67, 0x6AB96D37);
MS2_REPLACE(0x1416f9b30, FUN_1416f9b30, 59, 0xBD7A40FD);
MS2_REPLACE(0x1416f9b80, FUN_1416f9b80, 94, 0xA3074616);
MS2_REPLACE(0x1416f9bf0, FUN_1416f9bf0, 320, 0x1B964556);
#ifndef MS2_STANDALONE
MS2_REPLACE_IMPL(0x1416fa0e0,
    static_cast<Unk_RtViewPtr* (*)(Unk_RtViewPtr*, const Unk_RtViewPtr*)>(
        [](Unk_RtViewPtr* self, const Unk_RtViewPtr* o) -> Unk_RtViewPtr* { return ::new (static_cast<void*>(self)) Unk_RtViewPtr(*o); }),
    "Unk_RtViewPtr::Unk_RtViewPtr", 64, 0xEABE6B59);
#endif
MS2_REPLACE(0x1416fa120, FUN_1416fa120, 54, 0xCED6F715);
MS2_REPLACE(0x1416fa160, FUN_1416fa160, 54, 0xCED6F715);
MS2_REPLACE(0x1416fa200, FUN_1416fa200, 77, 0x0CBCD6FF);
MS2_REPLACE(0x1416fa250, FUN_1416fa250, 119, 0x1B86029C);
MS2_REPLACE(0x1416fa2d0, FUN_1416fa2d0, 14, 0xAAC7684B);
MS2_REPLACE(0x1416fa2e0, FUN_1416fa2e0, 14, 0x72E52537);
MS2_REPLACE(0x1416fa2f0, FUN_1416fa2f0, 18, 0x7B3D87A5);
MS2_REPLACE(0x1416fa310, FUN_1416fa310, 77, 0xE6808211);
MS2_REPLACE(0x1416fa360, FUN_1416fa360, 41, 0x28FD4F05);

