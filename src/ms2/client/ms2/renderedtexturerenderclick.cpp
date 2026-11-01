// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Offscreen "rendered texture" render click (NiViewRenderClick subclass).
// MS2-UNIT: ?\renderedtexturerenderclick.cpp
// MS2-RANGE: 0x1416f8f50-0x1416fa4b0 .text$mn
// MS2-PIN: ??_GRenderedTextureRenderClick@@UEAAPEAXI@Z 0x1416fa1a0
// MS2-PIN: ??0FormatPrefs@NiTexture@@QEAA@XZ 0x140984420
// MS2-PIN: ??0?$SmartPointer@VNiAVObject@@@efd@@QEAA@AEBV01@@Z 0x14097eb60
// MS2-PIN: ??1?$SmartPointer@VNiAVObject@@@efd@@QEAA@XZ 0x1405a85c0
// MS2-PIN: ??0?$SmartPointer@VNiDepthStencilBuffer@@@efd@@QEAA@PEAVNiDepthStencilBuffer@@@Z 0x1416ae2e0
// MS2-PIN: ??1?$SmartPointer@VNiDepthStencilBuffer@@@efd@@QEAA@XZ 0x1416aed20
// MS2-PIN: ??0NiColorA@@QEAA@MMMM@Z 0x14097f1d0
// MS2-PIN: ??0NiFixedString@@QEAA@PEBD@Z 0x140984450
// MS2-PIN: ??1NiFixedString@@QEAA@XZ 0x1409845a0
// MS2-PIN: ??0?$SmartPointer@VNi3DRenderView@@@efd@@QEAA@PEAVNi3DRenderView@@@Z 0x1409a73e0
// MS2-PIN: ??0?$SmartPointer@VNiRenderedTexture@@@efd@@QEAA@PEAVNiRenderedTexture@@@Z 0x14127c2a0
// MS2-PIN: ??1?$SmartPointer@VNiRenderedTexture@@@efd@@QEAA@XZ 0x14127c650
// MS2-PIN: ??0?$SmartPointer@VNiRenderTargetGroup@@@efd@@QEAA@PEAVNiRenderTargetGroup@@@Z 0x1414748a0
// MS2-PIN: ??1?$SmartPointer@VNiRenderTargetGroup@@@efd@@QEAA@XZ 0x141474d60
// MS2-PIN: ??2MemObject@efd@@SAPEAX_KVMemHint@1@@Z 0x14208a860
// MS2-PIN: ??3MemObject@efd@@SAXPEAXVMemHint@1@@Z 0x14097f700
// MS2-PIN: ??0Ni3DRenderView@@QEAA@PEAVNiCamera@@PEAVNiCullingProcess@@_N@Z 0x140d9de30
// MS2-PIN: ??0NiMeshCullingProcess@@QEAA@PEAVNiVisibleArray@@PEAVNiSPWorkflowManager@@@Z 0x141e2eaf0
// MS2-PIN: ??0?$SmartPointer@VNiRenderClick@@@efd@@QEAA@PEAVNiRenderClick@@@Z 0x1414747a0
// MS2-PIN: ??1?$SmartPointer@VNiRenderClick@@@efd@@QEAA@XZ 0x141474ca0
// MS2-PIN: ??0?$SmartPointer@VNi3DRenderView@@@efd@@QEAA@AEBV01@@Z 0x1416fa0e0
// MS2-PIN: ??1?$SmartPointer@VNi3DRenderView@@@efd@@QEAA@XZ 0x1409a7ad0
// MS2-PIN: ?GetValue_1416f9ae0@RenderedTextureRenderClick@@QEAA?AV?$SmartPointer@VNi3DRenderView@@@efd@@XZ 0x1416f9ae0
#include "ms2/placeholder/ms2stdafx.h"
#include "renderedtexturerenderclick.h"
#include <Ni3DRenderView.h>
#include <NiMeshCullingProcess.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderedTexture.h>
#include <NiRenderObject.h>
#include <NiNode.h>
#include <NiDefaultClickRenderStep.h>
#include <NiDX9Renderer.h>
#include <NiDX92DBufferData.h>
#include <ecr/RenderSurface.h>
#include <new>

typedef RenderedTextureRenderClick RTRC;

// ---- out-of-unit callees (bound to the exe by name) ----
ecr::RenderSurface* FUN_1413f98d0();
class Unk_PtrArray   // C3: member view for the former free stand-ins
{
public:
    void RemoveAll();
};
void* FUN_140c8f680(void*);   // C3: was FUN_140c8f680
void FUN_1416fa360(void* view, void* cp);
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

#define VSLOT(o, off) ((*(void***)(o))[(off) / 8])

// @0x1416f8f50
RenderedTextureRenderClick::RenderedTextureRenderClick()
    : m_uiWidth(0x80), m_uiHeight(0xa8), m_spView(0), m_spTexture(0), m_spTarget(0), m_iEventId(-1)
{
    ((class NiRenderClick*)(void*)(this))->SetClearAllBuffers(true);
    SetUseRendererBackgroundColor(false);
    ((class NiRenderClick*)(void*)(this))->SetBackgroundColor(NiColorA(0.0f, 0.0f, 0.0f, 0.0f));
    NiFixedString name("RenderedTextureRenderClick");
    ((class NiRenderClick*)(void*)(this))->SetName(name);
}

// @0x1416f9070
RenderedTextureRenderClick::~RenderedTextureRenderClick()
{
    m_spView = 0;
    m_spTexture = 0;
    m_spTarget = 0;
}

// @0x1416f9130
void RenderedTextureRenderClick::vfunc_8(unsigned w, unsigned h)
{
    m_uiWidth = w;
    m_uiHeight = h;
    FUN_1416f9b80(this, m_uiWidth, m_uiHeight);
    FUN_1416f9bf0(this, m_uiWidth, m_uiHeight);
    m_spView = new (efd::MemHint(efd::MemHint::NONE)) Ni3DRenderView(0, 0, true);
    {
        NiFixedString name("RenderTextureRenderView");
        m_spView->SetName(name);
    }
    NiMeshCullingProcess* pCull = new (efd::MemHint(efd::MemHint::NONE)) NiMeshCullingProcess(0, 0);
    FUN_1416fa360(m_spView.operator->(), pCull);
    ((class NiViewRenderClick*)(void*)(this))->AppendRenderView(m_spView);
}

// @0x1416f9340
void FUN_1416f9340(RTRC* p, unsigned w, unsigned h)
{
    p->m_uiWidth = w;
    p->m_uiHeight = h;
    FUN_1416f9b80(p, p->m_uiWidth, p->m_uiHeight);
    FUN_1416f9bf0(p, p->m_uiWidth, p->m_uiHeight);
    extern Ni3DRenderView* FUN_1413f9a70();
    p->m_spView = FUN_1413f9a70();
    ((class NiViewRenderClick*)(void*)(p))->AppendRenderView(p->m_spView);
}

// @0x1416f9400
void RenderedTextureRenderClick::vfunc_9()
{
    NiDefaultClickRenderStep* o = NiDynamicCast(NiDefaultClickRenderStep, FUN_1413f98d0()->GetRenderStep());
    if (o) {
        o->RemoveRenderClick((class NiRenderClick*)(this));
        extern void FUN_1416fa310(void*, void*);
        FUN_1416fa310(o, this);
    }
    NiDX9Renderer* r = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (r) {
        if (m_iEventId != -1) r->RemoveResetNotificationFunc(m_iEventId);
        m_iEventId = r->AddResetNotificationFunc((NiDX9Renderer::RESETNOTIFYFUNC)FUN_1416f9b30, this);
    }
}

// @0x1416f94c0
void RenderedTextureRenderClick::vfunc_10()
{
    NiDefaultClickRenderStep* o = NiDynamicCast(NiDefaultClickRenderStep, FUN_1413f98d0()->GetRenderStep());
    if (o) {
        o->RemoveRenderClick((class NiRenderClick*)(this));
        o->AppendRenderClick((class NiRenderClick*)(this));
    }
    NiDX9Renderer* r = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (r) {
        if (m_iEventId != -1) r->RemoveResetNotificationFunc(m_iEventId);
        m_iEventId = r->AddResetNotificationFunc((NiDX9Renderer::RESETNOTIFYFUNC)FUN_1416f9b30, this);
    }
}

// @0x1416f9580
void RenderedTextureRenderClick::vfunc_11()
{
    vfunc_14();
    NiDefaultClickRenderStep* o = NiDynamicCast(NiDefaultClickRenderStep, FUN_1413f98d0()->GetRenderStep());
    if (o) o->RemoveRenderClick((class NiRenderClick*)(this));
    NiDX9Renderer* r = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (r && m_iEventId != -1) r->RemoveResetNotificationFunc(m_iEventId);
    m_spView->SetCamera((class NiCamera*)(0));
    FUN_1416fa360(m_spView.operator->(), 0);
    ((class NiViewRenderClick*)(void*)(this))->RemoveRenderView(m_spView);
    ((class NiRenderClick*)(void*)(this))->SetRenderTargetGroup((class NiRenderTargetGroup*)(0));
    SetProcessor(0, 0);
    SetPreProcessingCallbackFunc(0, 0);
    SetPostProcessingCallbackFunc(0, 0);
    m_spTexture = 0;
}

// @0x1416f96d0
void RenderedTextureRenderClick::vfunc_12(void* a)
{
    if (m_spView) m_spView->AppendScene((NiAVObject*)a);
}

// @0x1416f9730
void RenderedTextureRenderClick::vfunc_13(void* a)
{
    if (m_spView) m_spView->RemoveScene((NiAVObject*)a);
}

// @0x1416f9790
void RenderedTextureRenderClick::vfunc_14()
{
    if (m_spView) {
        NiTPointerList<NiAVObjectPtr>* list = &m_spView->GetScenes();
        NiTListIterator pos = list->GetHeadPos();
        while (pos) {
            NiAVObjectPtr sp(list->GetNext(pos));
            if (sp) {
                NiNode* obj = NiDynamicCast(NiNode, sp);
                if (obj) {
                    obj->DetachAllEffects();
                    obj->UpdateEffects();
                }
            }
        }
        m_spView->RemoveAllScenes();
    }
}

// @0x1416f9890
void RenderedTextureRenderClick::vfunc_15(bool bFree)
{
    if (bFree) {
        if (m_spTarget) {
            Ni2DBuffer* b = m_spTarget->GetBuffer(0);
            if (b) {
                NiDX9Direct3DBufferData* d = (NiDX9Direct3DBufferData*)b->GetRendererData();
                if (d) d->PurgeBufferData();
            }
        }
        m_spTexture = 0;
        m_spTarget = 0;
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
    if (p->m_spView) p->m_spView->SetCamera((class NiCamera*)(a));
}

// @0x1416f9a30
void* FUN_1416f9a30(RTRC* p)
{
    if (p->m_spView) return p->m_spView->GetCamera();
    return 0;
}

// @0x1416f9a80
float FUN_1416f9a80(RTRC* p) { return (float)p->m_uiWidth / (float)p->m_uiHeight; }

// @0x1416f9ab0
void FUN_1416f9ab0(RTRC* p) { FUN_140c8f680(&p->m_spTexture); }

// @0x1416f9ae0
Ni3DRenderViewPtr RenderedTextureRenderClick::GetValue_1416f9ae0()
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
    NiTexture::FormatPrefs fmt;
    fmt.m_eAlphaFmt = NiTexture::FormatPrefs::SMOOTH;
    p->m_spTexture = NiRenderedTexture::Create(w, h, NiRenderer::GetRenderer(), fmt, (Ni2DBuffer::MultiSamplePreference)0x100);
}

// @0x1416f9bf0
void FUN_1416f9bf0(RTRC* p, unsigned, unsigned)
{
    if (FUN_1416fa160(&p->m_spTexture, 0)) return;
    Ni2DBuffer* buf = p->m_spTexture->GetBuffer();
    if (!buf) return;
    NiDepthStencilBufferPtr sp(NiDepthStencilBuffer::CreateCompatible(buf, NiRenderer::GetRenderer()));
    if (FUN_1416fa120(&sp, 0)) return;
    p->m_spTarget = NiRenderTargetGroup::Create(buf, NiRenderer::GetRenderer(), sp);
    if (p->m_spTarget) p->SetRenderTargetGroup(p->m_spTarget);
}

// @0x1416f9d40
void RenderedTextureRenderClick::PerformRendering(unsigned int uiFrameID)
{
    for (;;) {
        if (NiRenderer::GetRenderer()) NiRenderer::GetRenderer()->PushProfileMarkerVA("ViewRC(%s)", (const char*)GetName());
        break;
    }
    if (!FUN_1416fa2e0(&m_kRenderViews)) return;
    NiRenderer* renderer = (NiRenderer*)((void*)NiRenderer::GetRenderer());
    NiRenderListProcessor* proc = m_spProcessor;
    if (proc == 0) proc = ms_spDefaultProcessor;
    m_uiNumObjectsDrawn = 0;
    m_fRenderTime = 0.0f;
    m_fCullTime = 0.0f;
    NiTListIterator pos = m_kRenderViews.GetHeadPos();
    while (pos) {
        NiRenderView* view = m_kRenderViews.GetNext(pos);
        view->SetCameraData(m_kViewport);
        float t0 = FUN_1416fa2f0();
        NiVisibleArray* pv = (NiVisibleArray*)((void*)&((class NiRenderView*)(void*)(view))->GetPVGeometry(uiFrameID));
        m_fCullTime = m_fCullTime + (FUN_1416fa2f0() - t0);
        m_uiNumObjectsDrawn = ((class NiVisibleArray*)(void*)(pv))->GetCount() + m_uiNumObjectsDrawn;
        if (FUN_1416fa2d0(&m_kProcessedGeometry) < (unsigned)((class NiVisibleArray*)(void*)(pv))->GetCount())
            ((class NiVisibleArray*)(void*)(&m_kProcessedGeometry))->SetAllocatedSize(((class NiVisibleArray*)(void*)(pv))->GetCount());
        t0 = FUN_1416fa2f0();
        proc->PreRenderProcessList(pv, m_kProcessedGeometry, m_pvProcessorData);
        unsigned n = ((class NiVisibleArray*)(void*)(&m_kProcessedGeometry))->GetCount();
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

// @0x1416fa120
bool FUN_1416fa120(void* sp, void* p) { return *(void**)sp == p; }

// @0x1416fa160
bool FUN_1416fa160(void* sp, void* p) { return *(void**)sp == p; }

// @0x1416fa200
void FUN_1416fa200(Unk_RtClickList* l, void* p)
{
    Unk_RtClickNode* node = l->vfunc_1();
    *(NiRenderClickPtr*)((char*)node + 0x10) = *(const NiRenderClickPtr*)p;
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
    NiRenderClickPtr tmp((NiRenderClick*)click);
    FUN_1416fa200((Unk_RtClickList*)((char*)o + 0x50), &tmp);
}

// @0x1416fa360
void FUN_1416fa360(void* view, void* cp) { *(NiCullingProcessPtr*)((char*)view + 0x40) = (NiCullingProcess*)cp; }

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
    static_cast<Ni3DRenderViewPtr* (*)(Ni3DRenderViewPtr*, const Ni3DRenderViewPtr*)>(
        [](Ni3DRenderViewPtr* self, const Ni3DRenderViewPtr* o) -> Ni3DRenderViewPtr* { return ::new (static_cast<void*>(self)) Ni3DRenderViewPtr(*o); }),
    "efd::SmartPointer<Ni3DRenderView>::SmartPointer", 64, 0xEABE6B59);
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

