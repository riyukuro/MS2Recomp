// postprocesseffect.h - MS2's PostProcessEffect / ReloadablePostProcess render-step bases (the *RenderStep family under
// client\ms2\postprocessing), PLACEHOLDERS (not original headers). Their Gamebryo bases NiDefaultClickRenderStep, NiFixedString
// and NiString are the real engine classes (cmake/ms2-engine-flags.cmake; docs/RECOVERY.md section 3).
// Proven from the exe (KMS2_DEV x64):
//   NiDefaultClickRenderStep : NiRefObject, 0x70 bytes, vftable slots 0 dtor, 1 DeleteThis, 2 GetRTTI, 3..12 NiClickRenderStep /
//     NiRenderStep virtuals (ctor 0x141474910, dtor 0x141474dd0).
//   PostProcessEffect : NiDefaultClickRenderStep, 0xa0 bytes (ctor 0x1416a2880, dtor 0x1416a2910, pure virtual dtor), 23 slots;
//     virtuals 13..22 declared below (15 = PostProcessEffect::vfunc_15 0x1416a2990, 16 = 0x1416a2b50).
//   ReloadablePostProcess : PostProcessEffect, 0xb8 bytes (ctor 0x1416a2bb0, dtor 0x141626a00 in outlinerenderstep), overrides 13/14/21,
//     adds pure virtual slot 23 -> 24 slots.
// Members of unknown type are kept as raw pointers; the smart-pointer-like helpers are called through FUN_<va> free functions.
#pragma once

#include "ms2/ms2layout.h"
#include <NiDefaultClickRenderStep.h>
#include <NiFixedString.h>
#include <NiString.h>
#include <efd/SmartPointer.h>

class NiRenderedTexture;
class NiRenderTargetGroup;

#include "ms2/placeholder/nirefobject.h"
#include "ms2/placeholder/ninode.h"

MS2_CHECK_SIZE(NiFixedString, 8);
MS2_CHECK_SIZE(NiString, 8);

// Smart-pointer-like helper objects (8 bytes) used as render-step members; real template types unknown.
class Unk_PPSmartA {
public:
    Unk_PPSmartA(void* p);          // 0x14127c2a0
    ~Unk_PPSmartA();                // 0x14127c650
    void Assign(void* p);           // 0x14127c7f0
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_PPSmartA, 8);

class Unk_PPSmartC {
public:
    Unk_PPSmartC(void* p = 0);      // 0x14097ed60 (default argument: std::map<K, Unk_PPSmartC> value-initialises with 0)
    Unk_PPSmartC(const Unk_PPSmartC& rhs);   // declared only so MSVC passes it by invisible reference (the exe does); never called
    ~Unk_PPSmartC();                // 0x14097f4a0
    void Assign(void* p);           // 0x14097f9b0
    void* Get();                    // 0x14097fbf0
    Unk_PPSmartC& operator=(const Unk_PPSmartC& rhs);   // 0x140a5ab40
    bool operator!=(void* p) const;                     // 0x141849f40 (textureanimationdata.cpp)
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_PPSmartC, 8);

MS2_CHECK_SIZE(NiDefaultClickRenderStep, 0x70);     // exe: ctor 0x141474910, dtor 0x141474dd0; 13 vftable slots

class PostProcessEffect : public NiDefaultClickRenderStep {
public:
    PostProcessEffect(unsigned __int64 a, unsigned int b);     // 0x1416a2880
    virtual ~PostProcessEffect() = 0;                          // 0x1416a2910
    virtual const NiRTTI* GetRTTI() const;
    virtual bool vfunc_13();
    virtual bool vfunc_14();
    virtual bool vfunc_15(unsigned int a, void* b);            // 0x1416a2990
    virtual void vfunc_16();                                   // 0x1416a2b50
    virtual void* vfunc_17();
    virtual void* vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();

    bool FUN_1409a8f00();                                      // 0x1409a8f00: m_90 (output created)

    static const NiRTTI ms_RTTI;                               // 0x143ae4640 (0x143afa7a8 is NiDefaultClickRenderStep::ms_RTTI)

    unsigned __int64 m_70;
    void* m_78;
    efd::SmartPointer<NiRenderedTexture> m_80;      // the step's output texture (ctor 0x14127c2a0)
    efd::SmartPointer<NiRenderTargetGroup> m_88;    // its render target group (ctor 0x1414748a0)
    unsigned char m_90;     // vfunc_15 result (output created)
    void* m_98;             // vfunc_15 argument b (the service's shared targets)
};
MS2_CHECK_SIZE(PostProcessEffect, 0xa0);

class ReloadablePostProcess : public PostProcessEffect {
public:
    ReloadablePostProcess(unsigned __int64 a, const NiFixedString& name, unsigned char flag, unsigned int b);   // 0x1416a2bb0
    virtual ~ReloadablePostProcess();                          // 0x141626a00
    virtual const NiRTTI* GetRTTI() const;
    virtual bool vfunc_13();                                   // 0x141626ab0
    virtual bool vfunc_14();                                   // 0x141626aa0
    virtual void vfunc_21();                                   // 0x1416a2c60
    virtual bool vfunc_23() = 0;

    static const NiRTTI ms_RTTI;                               // 0x143ae4650

    NiFixedString m_a0;
    unsigned char m_a8;
    void* m_b0;
};
MS2_CHECK_SIZE(ReloadablePostProcess, 0xb8);

// Shared helpers (exe functions called by the *RenderStep family; real types unknown, pointers kept raw).
void FUN_140c8f950(NiDefaultClickRenderStep* step, const NiFixedString& name);                  // SetName
void* FUN_140c8f680(void* smartPtr);                                                      // smart pointer -> raw
void* FUN_1409a8d30(NiDefaultClickRenderStep* step, NiFixedString* name);
void FUN_14169fbf0(NiDefaultClickRenderStep* step, void* p);
// Result handle of the render-click factory FUN_1416b4990 (8 bytes, returned by value, dtor 0x1409a7b30).
class Unk_PPRes {
public:
    ~Unk_PPRes();                   // 0x1409a7b30
    friend void* FUN_140c8f690(const Unk_PPRes& res);   // the getter (COMDAT in postshimmerrenderstep.cpp)
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_PPRes, 8);
Unk_PPRes FUN_1416b4990(NiDefaultClickRenderStep* step, const char* name, void* cb, void* cbData, void* a, int b, int c, void* d, const char* tech, void* e, void* f, void* g);
void* FUN_140c8f690(const Unk_PPRes& res);
void* FUN_1401d31f0();
extern char DAT_1439fc800;
void* FUN_141d33230(NiFixedString* name, void* a, int b, int c, bool d);
void FUN_14169f6d0(void* smartPtrA, void* p);
