// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Alpha components of the entity layer (see alphacomponent.h).
// MS2-UNIT: ?\alphacomponent.cpp
// MS2-RANGE: 0x14098eb30-0x140996b20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetObjectA@AlphaObject@@QEBAPEAVNiAVObject@@XZ 0x14098ebe0 ; unique
// MS2-PIN: ??$_Adl_verify_range1@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@VAlphaObject@@@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@VAlphaObject@@@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x14098f9e0 ; unique
// MS2-PIN: ??2@YAPEAX_KPEAX@Z 0x140993c70 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$_Construct1@PEAU?$_Tree_node@U?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@std@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@std@@PEAX@1@AEAPEAU51@@Z 0x14098fb30 ; near 1.00
// MS2-PIN: ??$_Construct1@U?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBQEAVNiAlphaProperty@@@2@V?$tuple@$$V@2@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@std@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@U?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@std@@PEAX@std@@@efd@@PEAU?$pair@QEAVNiAlphaProperty@@UUnk_BlendState@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBQEAVNiAlphaProperty@@@1@$$QEAV?$tuple@$$V@1@@Z 0x14098fc00 ; near 1.00
// MS2-PIN: ?construct@?$CustomAllocator@PEAVNiRenderObject@@@efd@@QEAAXPEAPEAVNiRenderObject@@AEBQEAV3@@Z 0x1409961a0 ; near 1.00
// MS2-PIN: ?construct@?$CustomAllocator@VAlphaObject@@@efd@@QEAAXPEAVAlphaObject@@AEBV3@@Z 0x1409961e0 ; near 0.84
// MS2-FUNCTIONAL: _Construct1/construct COMDATs differ from exe (null-check, placement-new variant)
// MS2-PIN: ?MS2HasAnyFlag@NiAVObject@@QEBA_NG@Z 0x14098dba0
// MS2-PIN: ?IsLessAlpha@AlphaShellComposite@@SA_NAEBVAlphaObject@@0@Z 0x14098f650
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\alphacomponent.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "alphacomponent.h"
#include <algorithm>
#include <map>
#include <NiAlphaProperty.h>
#include <NiZBufferProperty.h>
#include <NiPropertyState.h>
#include <NiIntegerExtraData.h>
#include <NiBound.h>
#include <NiNode.h>
#include <NiRenderObject.h>
#include <NiRenderer.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

// Breadth-first queue of scene-graph nodes (0x30 bytes, ?\alphaanimation.cpp).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);
    ~Unk_NodeQueue();
    NiAVObject* Next(bool bAddChildren);

private:
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_p4;
    void* m_p5;
};

// The blend state of an alpha property that the shells overwrite and restore.
struct Unk_BlendState
{
    Unk_BlendState() : m_nSrc(0), m_nDest(0) {}
    int m_nSrc;
    int m_nDest;
};

extern NiFixedString DAT_143ae51d0;             // extra data keys of the shell kinds
extern NiFixedString DAT_143ae5190;
extern NiFixedString DAT_143ae50a8;             // extra data key of the mark
// The saved blend states of the alpha properties, keyed by property.
struct Unk_AlphaLess
{
    bool operator()(NiAlphaProperty* pLeft, NiAlphaProperty* pRight) const
    {
        return pLeft < pRight;
    }
};

typedef efd::map<NiAlphaProperty*, Unk_BlendState, Unk_AlphaLess> Unk_BlendMap;

extern NiRenderer* DAT_143afa648;               // NiRenderer::ms_pkRenderer
extern int DAT_143ae2b34;                       // 1: the kinds are tested by the shell flags instead of the extra data
extern int DAT_1439f4a8c;                       // counter of the marking passes
//                       // counter of the marking passes
int FUN_1415690c0(NiAVObject* pShell);
int FUN_141568f60(NiAVObject* pShell);
float FUN_141b71c50();

// ---- small inlines of the engine headers ----

// View of the game's NiAVObject vtable: PurgeRendererData sits at offset 0x120 (the SDK header puts it at 0x118).
class Unk_PurgeView
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void PurgeRendererData(NiRenderer* pRenderer);
};
#define PurgeRendererData(p, r) ((Unk_PurgeView*)(p))->PurgeRendererData(r)

// @0x140994450
NiRenderer* GetNiRenderer()
{
    return DAT_143afa648;
}

// @0x140993fe0
inline float FUN_140993fe0(const NiPoint3& a, const NiPoint3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// @0x140994320
inline float FUN_140994320(NiAVObject* pObj, const NiPoint3* pDir)
{
    return FUN_140993fe0(pObj->GetWorldBound().GetCenter(), *pDir);
}

// @0x1409943d0
inline bool FUN_1409943d0(NiAVObject* pObj)
{
    return pObj->MS2HasAnyFlag(0x20);
}

// ---- AlphaObject ----

// @0x14098eb80
void AlphaObject::Set(NiAVObject* pObject, float fAlpha)
{
    SetAlpha(fAlpha);
    m_pObject = pObject;
}
MS2_REPLACE_METHOD(0x14098EB80, AlphaObject, Set, 55, 0xAF50945A);

// @0x14098eb30
void AlphaObject::vfunc_0()
{
    PurgeRendererData(m_pObject, GetNiRenderer());
}
MS2_REPLACE_METHOD(0x14098EB30, AlphaObject, vfunc_0, 72, 0x294E735B);

// @0x14098ec00
void AlphaShellComposite::vfunc_0()
{
    NiRenderer* pRenderer = GetNiRenderer();
    Unk_BlendMap mapSaved;
    for (efd::vector<NiRenderObject*>::iterator it = m_aShells.begin(); it != m_aShells.end(); ++it)
    {
        NiRenderObject* pShell = *it;
        NiPropertyState* pState = pShell->GetPropertyState();
        NiAlphaProperty* pAlpha = pState->GetAlpha();
        NiZBufferProperty* pZ = pState->GetZBuffer();
        if (mapSaved.find(pAlpha) == mapSaved.end())
        {
            mapSaved[pAlpha].m_nSrc = pAlpha->GetSrcBlendMode();
            mapSaved[pAlpha].m_nDest = pAlpha->GetDestBlendMode();
            pAlpha->SetSrcBlendMode(NiAlphaProperty::ALPHA_ZERO);
            pAlpha->SetDestBlendMode(NiAlphaProperty::ALPHA_ONE);
        }
        pZ->SetTestFunction(NiZBufferProperty::TEST_LESSEQUAL);
        PurgeRendererData(pShell, pRenderer);
    }
    for (Unk_BlendMap::iterator it = mapSaved.begin(); it != mapSaved.end(); ++it)
    {
        it->first->SetSrcBlendMode((NiAlphaProperty::AlphaFunction)it->second.m_nSrc);
        it->first->SetDestBlendMode((NiAlphaProperty::AlphaFunction)it->second.m_nDest);
    }
    for (efd::vector<NiRenderObject*>::iterator it = m_aShells.begin(); it != m_aShells.end(); ++it)
    {
        NiRenderObject* pShell = *it;
        PurgeRendererData(pShell, pRenderer);
    }
    for (efd::vector<AlphaObject>::iterator it = m_aObjects.begin(); it != m_aObjects.end(); ++it)
    {
        it->vfunc_0();
    }
}

// @0x14098ef60
void AlphaShellComposite::Clear()
{
    m_aShells.clear();
    m_aObjects.clear();
}
MS2_REPLACE_METHOD(0x14098EF60, AlphaShellComposite, Clear, 48, 0x48F56FDE);

// @0x14098efa0
void AlphaShellComposite::AddShell(NiRenderObject* pShell)
{
    m_aShells.push_back(pShell);
}
MS2_REPLACE_METHOD(0x14098EFA0, AlphaShellComposite, AddShell, 41, 0xB40B8D3F);

// @0x14098efd0
void AlphaShellComposite::AddObject(NiAVObject* pObject)
{
    AlphaObject kObject;
    kObject.SetObject(pObject);
    m_aObjects.push_back(kObject);
}
MS2_REPLACE_METHOD(0x14098EFD0, AlphaShellComposite, AddObject, 66, 0x1DA41B7D);

// MS2-FUNCTIONAL: exe nests the A/B flag tests differently (cl branch layout not reproducible)
// @0x14098f020
void AlphaShellComposite::Update(const NiPoint3* pDir)
{
    float fAlpha = 0.0f;
    bool bHasA = false;
    bool bHasB = false;
    for (efd::vector<NiRenderObject*>::iterator it = m_aShells.begin(); it != m_aShells.end(); ++it)
    {
        NiRenderObject* pShell = *it;
        fAlpha = fAlpha + FUN_140994320(pShell, pDir);
        if (DAT_143ae2b34 == 0)
        {
            bHasA = bHasA || pShell->GetExtraData(DAT_143ae51d0) != 0;
            bHasB = bHasB || pShell->GetExtraData(DAT_143ae5190) != 0;
        }
        else
        {
            bHasA = bHasA || FUN_1415690c0(pShell) != 0;
            bHasB = bHasB || FUN_141568f60(pShell) != 0;
        }
    }
    for (efd::vector<AlphaObject>::iterator it = m_aObjects.begin(); it != m_aObjects.end(); ++it)
    {
        float fDepth = FUN_140994320(it->GetObject(), pDir);
        it->SetAlpha(fDepth);
        if (DAT_143ae2b34 == 0)
        {
            bHasA = bHasA || it->GetObject()->GetExtraData(DAT_143ae51d0) != 0;
            bHasB = bHasB || it->GetObject()->GetExtraData(DAT_143ae5190) != 0;
        }
        else
        {
            bHasA = bHasA || FUN_1415690c0(it->GetObject()) != 0;
            bHasB = bHasB || FUN_141568f60(it->GetObject()) != 0;
        }
    }
    std::sort(m_aObjects.begin(), m_aObjects.end(), IsLessAlpha);
    if (m_aShells.size() == 0 && m_aObjects.size() != 0)
        fAlpha = m_aObjects[0].GetAlpha();
    else
        fAlpha = fAlpha / (float)m_aShells.size();
    if (!bHasA)
    {
        if (bHasB)
            fAlpha = fAlpha - FUN_141b71c50();
    }
    else
    {
        fAlpha = fAlpha + FUN_141b71c50();
    }
    SetAlpha(fAlpha);
}

// @0x14098f4d0
void AlphaShellComposite::MarkScene(NiAVObject* pRoot, bool bForce)
{
    int nMark = DAT_1439f4a8c;
    if (bForce)
        nMark = 1;
    Unk_NodeQueue kQueue(pRoot);
    NiAVObject* pNode;
    while ((pNode = kQueue.Next(true)) != 0)
    {
        if (FUN_1409943d0(pNode))
        {
            NiIntegerExtraData* pData = NiDynamicCast(NiIntegerExtraData, pNode->GetExtraData(DAT_143ae50a8));
            if (pData == 0)
            {
                pData = NiNew NiIntegerExtraData(nMark);
                pNode->AddExtraData(DAT_143ae50a8, pData);
            }
            pData->SetValue(nMark);
        }
    }
    DAT_1439f4a8c--;
}

// @0x14098f630
void AlphaShellComposite::ResetMarkCounter()
{
    DAT_1439f4a8c = 0x7fffffff;
}


bool AlphaShellComposite::IsLessAlpha(const AlphaObject& a, const AlphaObject& b)
{
    return a.GetAlpha() > b.GetAlpha();
}

// @0x140996a00
MS2_EMIT_CRT_MEMMOVE_S();









// end of unit
