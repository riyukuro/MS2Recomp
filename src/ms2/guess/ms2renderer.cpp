// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Rendering glue: MS2Renderer (NiDX9Renderer subclass: mesh render hook, clear color, fragment shader factory).
// MS2-UNIT: ?\ms2renderer.cpp
// MS2-RANGE: 0x140d9d370-0x140d9dba0 .text$mn
// MS2-RANGE: 0x1400d3cd0-0x1400d3d00 .text$di
// MS2-PIN: ??_GMS2Renderer@@UEAAPEAXI@Z 0x140d9d5c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2renderer.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiDX9Renderer.h>
#include "ms2/client/ms2/ms2fragmentshader.h"

// ---- unit-local Gamebryo placeholders (NiDX9Renderer is unrecovered; engine headers are not on the include path) --------------
struct Unk_PtrArray {                                                    // NiTPrimitiveArray<void*>
    void** m_pBase; unsigned m_uiSize; unsigned m_uiMax; unsigned m_uiGrow;
    void FUN_141d54bb0(unsigned newMax);
    // @0x140d9d620
    void Add(void* p)
    {
        if (m_uiSize == m_uiMax) FUN_141d54bb0(m_uiMax + m_uiGrow);
        m_pBase[m_uiSize] = p;
        m_uiSize = m_uiSize + 1;
    }
    // @0x140d9d8d0
    void RemoveAll() { m_uiSize = 0; }
};
struct Unk_DevCaps {                                                     // object at MS2Renderer+0xba8 (render state block)
    char m_pad_00[0x98]; float m_f98; char m_pad_9c[0x68]; int m_i104;
    // @0x140d9d800
    bool IsEnabled() const { return m_i104 != 0 ? true : false; }
    // @0x140d9d850
    float GetValue98() const { return m_f98; }
    // @0x140d9dab0
    void SetEnabled(bool b) { int v; if (b) v = 1; else v = 0; m_i104 = v; }
    void FUN_1409a9bf0(float f);
};

class MS2Renderer : public NiDX9Renderer {
public:
    MS2Renderer();
    virtual ~MS2Renderer();
    virtual const NiRTTI* GetRTTI() const;
    virtual unsigned int GetFlags() const;
    virtual void SetDepthClear(const float fZClear);
    virtual float GetDepthClear() const;
    virtual void SetBackgroundColor(const NiColor& kColor);
    virtual void SetBackgroundColor(const NiColorA& kColor);
    virtual void GetBackgroundColor(NiColorA& kColor) const;
    virtual void SetStencilClear(unsigned int uiClear);
    virtual unsigned int GetStencilClear() const;
    virtual const NiRenderTargetGroup* GetCurrentRenderTargetGroup() const;
    virtual bool GetLeftRightSwap() const;
    virtual bool SetLeftRightSwap(bool bSwap);
    virtual float GetMaxFogValue() const;
    virtual void SetMaxFogValue(float fFogVal);
    virtual NiShader* GetErrorShader() const;
    virtual void SetErrorShader(NiShader* pkErrorShader);
    virtual bool PreloadTexture(NiTexture* pkTexture);
    virtual NiShader* GetFragmentShader(NiMaterialDescriptor* pkMaterialDescriptor);
    virtual void SetRenderShadowCasterBackfaces(bool bRenderBackfaces);
    virtual void Do_LockRenderer();
    virtual void Do_UnlockRenderer();
    virtual void Do_RenderMesh(NiMesh* pkMesh);
    static void operator delete(void*, size_t);                          // efd::MemObject::operator delete 0x14208a8f0
};

// ---- unrecovered neighbours -------------------------------------------------------------------------------------------------
extern char DAT_143a4b228;
extern Unk_PtrArray* DAT_143d6eab8;     // per-frame render object list

// MS2Renderer::ms_RTTI (parent NiDX9Renderer::ms_RTTI 0x143d6eb58). Its dynamic initializer is the exe's .text$di
// 0x1400d3cd0, so it runs from this unit's .CRT$XCU slot.
#ifndef MS2_HOOK_DLL   // the exe's object at 0x143ac3ce8, which other units reach as DAT_143ac3ce8 (the hook DLL binds it)
NiRTTI DAT_143ac3ce8("MS2Renderer", &NiDX9Renderer::ms_RTTI);
#else
extern NiRTTI DAT_143ac3ce8;
#endif

// @0x140d9d370
MS2Renderer::MS2Renderer() {}

// @0x140d9d3b0
MS2Renderer::~MS2Renderer() {}

// @0x140d9d3e0
void MS2Renderer::Do_RenderMesh(NiMesh* pkMesh)
{
    if (m_bDeviceLost != 0)
        return;
    NiDX9MeshMaterialBindingPtr spBinding(0);
    NiD3DShaderInterface* pkShader = GetShaderAndVertexDecl(pkMesh, spBinding);
    if (pkShader == 0 || spBinding == 0 || ((void*)((class NiDX9MeshMaterialBinding*)(class NiDX9MeshMaterialBinding*)((NiDX9MeshMaterialBinding*)spBinding))->GetD3DDeclaration()) == 0)
        return;
    DAT_143d6eab8->RemoveAll();
    DAT_143d6eab8->Add(pkMesh);
    ((class NiShader*)(void*)(pkShader))->RenderMeshes((class NiVisibleArray*)(DAT_143d6eab8));
}

// @0x140d9d4c0
NiShader* MS2Renderer::GetFragmentShader(NiMaterialDescriptor* pkMaterialDescriptor)
{
    return new (efd::MemHint(efd::MemHint::NONE)) MS2FragmentShader(pkMaterialDescriptor);
}

// @0x140d9d690
void MS2Renderer::Do_LockRenderer() {}

// @0x140d9d6a0
void MS2Renderer::Do_UnlockRenderer() {}

// @0x140d9d6b0
void MS2Renderer::GetBackgroundColor(NiColorA& kColor) const
{
    const float k = 0.003921569f;
    kColor.a = (float)((m_uiBackground >> 24) & 0xff) * k;
    kColor.r = (float)((m_uiBackground >> 16) & 0xff) * k;
    kColor.g = (float)((m_uiBackground >> 8) & 0xff) * k;
    kColor.b = (float)(m_uiBackground & 0xff) * k;
}

// @0x140d9d780
const NiRenderTargetGroup* MS2Renderer::GetCurrentRenderTargetGroup() const { return m_pkCurrRenderTargetGroup; }

// @0x140d9d7a0
float MS2Renderer::GetDepthClear() const { return m_fZClear; }

// @0x140d9d7c0
NiShader* MS2Renderer::GetErrorShader() const { return m_spErrorShader; }

// @0x140d9d7e0
unsigned int MS2Renderer::GetFlags() const { return m_uiRendFlags; }

// @0x140d9d830
bool MS2Renderer::GetLeftRightSwap() const { return ((Unk_DevCaps*)m_pkRenderState)->IsEnabled(); }

// @0x140d9d870
float MS2Renderer::GetMaxFogValue() const { return ((Unk_DevCaps*)m_pkRenderState)->GetValue98(); }

// @0x140d9d890
const NiRTTI* MS2Renderer::GetRTTI() const { return (const NiRTTI*)&DAT_143ac3ce8; }

// @0x140d9d8a0
unsigned int MS2Renderer::GetStencilClear() const { return m_uiStencilClear; }

// @0x140d9d8c0
bool MS2Renderer::PreloadTexture(NiTexture* pkTexture) { return true; }

// @0x140d9d8f0
void MS2Renderer::SetBackgroundColor(const NiColor& kColor)
{
    unsigned char r = (unsigned char)(int)(kColor.r * 255.0f);
    unsigned char g = (unsigned char)(int)(kColor.g * 255.0f);
    unsigned char b = (unsigned char)(int)(kColor.b * 255.0f);
    m_uiBackground = (r & 0xffU) << 16 | 0xff000000 | (g & 0xffU) << 8 | (b & 0xffU);
}

// @0x140d9d990
void MS2Renderer::SetBackgroundColor(const NiColorA& kColor)
{
    unsigned char r = (unsigned char)(int)(kColor.r * 255.0f);
    unsigned char g = (unsigned char)(int)(kColor.g * 255.0f);
    unsigned char b = (unsigned char)(int)(kColor.b * 255.0f);
    unsigned char a = (unsigned char)(int)(kColor.a * 255.0f);
    m_uiBackground = (a & 0xffU) << 24 | (r & 0xffU) << 16 | (g & 0xffU) << 8 | (b & 0xffU);
}

// @0x140d9da50
void MS2Renderer::SetDepthClear(const float fZClear) { m_fZClear = fZClear; }

// @0x140d9da70
void MS2Renderer::SetErrorShader(NiShader* pkErrorShader)
{
    if (pkErrorShader != 0) m_spErrorShader = pkErrorShader;
}

// @0x140d9daf0
bool MS2Renderer::SetLeftRightSwap(bool bSwap)
{
    ((Unk_DevCaps*)m_pkRenderState)->SetEnabled(bSwap);
    return true;
}

// @0x140d9db20
void MS2Renderer::SetMaxFogValue(float fFogVal) { ((Unk_DevCaps*)m_pkRenderState)->FUN_1409a9bf0(fFogVal); }

// @0x140d9db50
void FUN_140d9db50(bool b) { DAT_143a4b228 = b; }

// @0x140d9db60
void MS2Renderer::SetRenderShadowCasterBackfaces(bool bRenderBackfaces) { FUN_140d9db50(bRenderBackfaces); }

// @0x140d9db80
void MS2Renderer::SetStencilClear(unsigned int uiClear) { m_uiStencilClear = uiClear; }

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x140d9d3e0, MS2Renderer, Do_RenderMesh, 206, 0x7B72FAC8);
MS2_REPLACE_METHOD(0x140d9d4c0, MS2Renderer, GetFragmentShader, 121, 0xD9701CE9);
MS2_REPLACE_METHOD(0x140d9d690, MS2Renderer, Do_LockRenderer, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140d9d6a0, MS2Renderer, Do_UnlockRenderer, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140d9d6b0, MS2Renderer, GetBackgroundColor, 204, 0xEA89A596);
MS2_REPLACE_METHOD(0x140d9d780, MS2Renderer, GetCurrentRenderTargetGroup, 18, 0xE9DD51AE);
MS2_REPLACE_METHOD(0x140d9d7a0, MS2Renderer, GetDepthClear, 19, 0xD07FE45F);
MS2_REPLACE_METHOD(0x140d9d7c0, MS2Renderer, GetErrorShader, 31, 0x610C7DB9);
MS2_REPLACE_METHOD(0x140d9d7e0, MS2Renderer, GetFlags, 17, 0x9099A0EC);
MS2_REPLACE_METHOD(0x140d9d830, MS2Renderer, GetLeftRightSwap, 31, 0x1C42EEA9);
MS2_REPLACE_METHOD(0x140d9d870, MS2Renderer, GetMaxFogValue, 31, 0xCF9C8C39);
MS2_REPLACE_METHOD(0x140d9d890, MS2Renderer, GetRTTI, 13, 0x6771C7E5);
MS2_REPLACE_METHOD(0x140d9d8a0, MS2Renderer, GetStencilClear, 17, 0xF498F658);
MS2_REPLACE_METHOD(0x140d9d8c0, MS2Renderer, PreloadTexture, 13, 0xC078F4D1);
MS2_REPLACE_METHOD(0x140d9da50, MS2Renderer, SetDepthClear, 31, 0x59D81CDB);
MS2_REPLACE_METHOD(0x140d9da70, MS2Renderer, SetErrorShader, 49, 0xFE5B089D);
MS2_REPLACE_METHOD(0x140d9daf0, MS2Renderer, SetLeftRightSwap, 42, 0x76F7D3A0);
MS2_REPLACE_METHOD(0x140d9db20, MS2Renderer, SetMaxFogValue, 43, 0x243EBFB8);
MS2_REPLACE(0x140d9db50, FUN_140d9db50, 16, 0x3A4B02C9);
MS2_REPLACE_METHOD(0x140d9db60, MS2Renderer, SetRenderShadowCasterBackfaces, 28, 0x00A045DA);
MS2_REPLACE_METHOD(0x140d9db80, MS2Renderer, SetStencilClear, 25, 0x0E7C0D3C);

