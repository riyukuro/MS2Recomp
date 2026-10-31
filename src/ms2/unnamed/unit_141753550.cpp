// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Rendering glue: ShadowCullingProcess (NiTerrainCullingProcess subclass that culls shadow casters).
// MS2-UNIT: ?\shadowcullingprocess.cpp
// MS2-RANGE: 0x141753550-0x141753c90 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\shadowcullingprocess.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <new>

// ---- Gamebryo: the real engine headers (cmake/ms2-engine-flags.cmake) ------------------------------------------------
#include <NiTerrainCullingProcess.h>
#include <NiAVObject.h>
#include <NiBound.h>
#include <NiPlane.h>
class Unk_ShadowMgr { public: virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual int vfunc_18(const NiCamera* camera, NiAVObject* o); };       // slot 0x90

class ShadowCullingProcess : public NiTerrainCullingProcess {
public:
    ShadowCullingProcess();
    // ~ShadowCullingProcess() implicit (0x141753a70: no vftable store)
    virtual const NiRTTI* GetRTTI() const;
    virtual void Process(NiAVObject* obj);
};

// ---- unrecovered neighbours -----------------------------------------------------------------------------------------
extern char DAT_143ae5190;
class NiLODNode { public: static const NiRTTI ms_RTTI; };          // C3: was extern char DAT_143afb348
class NiRenderObject { public: static const NiRTTI ms_RTTI; };     // C3: was extern char DAT_143afa7d0
extern int DAT_143ae2b34;    extern int DAT_1439fc854;
void* FUN_1409478c0();                                  // singleton accessor
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    bool FUN_140aed0b0();
};
class NiAlphaProperty   // C3: member view for the former free stand-ins
{
public:
    bool GetAlphaBlending() const;
};
struct Unk_BoundView { NiPoint3 m_kCenter; float m_fRadius; };   // NiBound's layout (its members are protected)
int FUN_14098daf0(NiAVObject* o);                       // child count
class NiNode   // C3: member view for the former free stand-ins
{
public:
    static const NiRTTI ms_RTTI;
    class NiAVObject* GetAt(unsigned int) const;
};
int FUN_140ad02f0(int a, int b);                        // combine
unsigned int FUN_141568f60(class NiAVObject*);   // C3: was FUN_141568f60
efd::MemHint FUN_140876480(int cat);                    // memory category hint (returned through a hidden slot)
class NiMaterialProperty   // C3: member view for the former free stand-ins
{
public:
    float GetAlpha() const;
};
bool FUN_14028d470(float a, float b);                   // approx equal                                   // material has alpha test?

// @0x141753550
ShadowCullingProcess::ShadowCullingProcess() : NiTerrainCullingProcess(0, 0) {}

bool FUN_141753a00(NiAVObject* o);
int FUN_141753c20(const NiBound* b, const NiPlane& pl);
void FUN_141753c10(int v);
// Scene object that owns the shadow manager pointer at +0x138.
struct Unk_141753b80 {
    char m_0[0x138];
    void* m_138;
};
MS2_CHECK_OFFSET(Unk_141753b80, m_138, 0x138);
void* FUN_141753b80(char* o);

// MS2-FUNCTIONAL: Deactivate shift-count temp; factory EH state; ~Shadow vptr store (exe omits it)
// @0x141753590
void ShadowCullingProcess::Process(NiAVObject* obj)
{
    unsigned saved;
    unsigned i;
    int k;
    void* node;
    if (((class CameraMgr*)(void*)(FUN_1409478c0()))->FUN_140aed0b0() && obj != 0) {
        node = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiNode::ms_RTTI), (class NiObject const*)(((void*)((class NiAVObject*)(class NiAVObject*)(obj))->GetParent()))));
        while (node != 0) {
            NiProperty* p = ((class NiAVObject*)(class NiAVObject*)((NiAVObject*)node))->GetProperty(0);
            if (p != 0 && ((class NiAlphaProperty*)(class NiProperty*)(p))->GetAlphaBlending() && !FUN_141753a00((NiAVObject*)node))
                return;
            node = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiNode::ms_RTTI), (class NiObject const*)(((void*)((class NiAVObject*)(class NiAVObject*)((NiAVObject*)node))->GetParent()))));
        }
    }
    if (!m_kPlanes.IsAnyPlaneActive()) {
        obj->OnVisible(*this);
        return;
    }
    saved = m_kPlanes.GetActivePlaneState();
    for (i = 0; i < 6; ++i) {
        if (m_kPlanes.IsPlaneActive(i)) {
            int r = FUN_141753c20((const NiBound*)((void*)&((class NiAVObject*)(class NiAVObject*)(obj))->GetWorldBound()), m_kPlanes.GetPlane(i));
            if (r == 2) break;
            if (r == 1) m_kPlanes.DisablePlane(i);
        }
    }
    if (i == 6) {
        NiProperty* p = ((class NiAVObject*)(class NiAVObject*)(obj))->GetProperty(0);
        if (p == 0 || !((class NiAlphaProperty*)(class NiProperty*)(p))->GetAlphaBlending() || FUN_141753a00(obj)) {
            if (NiObject::IsExactKindOf((class NiRTTI const*)(&NiLODNode::ms_RTTI), (class NiObject const*)(obj))) {
                NiAVObject* o2 = obj;
                for (k = 0; k < FUN_14098daf0(o2); ++k) {
                    void* c = ((void*)((class NiNode*)(class NiAVObject*)(o2))->GetAt(k));
                    if (c != 0 && !((class NiAVObject*)(void*)(c))->IsNode()) break;
                }
                Unk_ShadowMgr* mgr = (Unk_ShadowMgr*)FUN_141753b80((char*)o2);
                int v = mgr->vfunc_18(GetLODCamera(), o2);
                k = FUN_140ad02f0(k, v);
                FUN_141753c10(k);
                obj->OnVisible(*this);
                FUN_141753c10(-1);
            } else {
                obj->OnVisible(*this);
            }
        } else if (DAT_143ae2b34 != 0) {
            void* x = ((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiRenderObject::ms_RTTI), (class NiObject const*)(obj)));
            if (x != 0 && FUN_141568f60((class NiAVObject*)(x)) != 0)
                obj->OnVisible(*this);
        } else {
            if (((void*)((class NiObjectNET*)(class NiAVObject*)(obj))->GetExtraData(*(class NiFixedString const*)(&DAT_143ae5190))) != 0)
                obj->OnVisible(*this);
        }
    }
    m_kPlanes.SetActivePlaneState(saved);
}

// @0x141753990   factory: EE_NEW(category) ShadowCullingProcess
ShadowCullingProcess* FUN_141753990()
{
    return new (FUN_140876480(0)) ShadowCullingProcess();
}

// @0x141753a00
bool FUN_141753a00(NiAVObject* o)
{
    NiProperty* p = ((class NiAVObject*)(class NiAVObject*)(o))->GetProperty(3);
    if (p != 0) {
        if (FUN_14028d470(((class NiMaterialProperty*)(class NiProperty*)(p))->GetAlpha(), 1.0f)) return true;
    }
    return false;
}

// @0x141753a50   exe's ~NiTerrainCullingProcess body: only forwards to the mesh base dtor
void FUN_141753a50(NiMeshCullingProcess* p) { p->NiMeshCullingProcess::~NiMeshCullingProcess(); }

// MS2-PIN: ??1ShadowCullingProcess@@UEAA@XZ 0x141753a70 ; implicit dtor (no vftable store)

// @0x141753a90
void* FUN_141753a90(void** p) { return *p; }

// @0x141753b80
void* FUN_141753b80(char* o) { return FUN_141753a90(&((Unk_141753b80*)o)->m_138); }

// @0x141753bb0
const NiRTTI* ShadowCullingProcess::GetRTTI() const { return (const NiRTTI*)&NiTerrainCullingProcess::ms_RTTI; }

// @0x141753c10
void FUN_141753c10(int v) { DAT_1439fc854 = v; }

// @0x141753c20
int FUN_141753c20(const NiBound* b, const NiPlane& pl)
{
    float d = ((class NiPlane*)(class NiPlane const*)(&pl))->Distance(*(class NiPoint3 const*)(&((const Unk_BoundView*)b)->m_kCenter));
    if (d <= -*(const float*)((const char*)b + 0xc)) { return 2; }
    else if (d >= *(const float*)((const char*)b + 0xc)) { return 1; }
    else { return 0; }
}
