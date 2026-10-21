// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\textureoverrideeffectparam.cpp
// MS2-RANGE: 0x14184b540-0x14184c790 .text$mn
// MS2-PIN: ??_GTextureOverrideEffect@@UEAAPEAXI@Z 0x14184c050
// MS2-PIN: ??_GTextureOverrideEffectParam@@UEAAPEAXI@Z 0x14184c0b0
// MS2-PIN: ??1TextureOverrideEffectParam@@UEAA@XZ 0x14184bf80
// MS2-PIN: ?GetRTTI@TextureOverrideEffect@@UEBAPEBVNiRTTI@@XZ 0x14184c2a0
// MS2-PIN: memcpy_s 0x14184c640
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\textureoverrideeffectparam.cpp"
// The exe's memcpy_s copy calls memset/memcpy (no /Oi expansion): the pragma must precede its inline definition.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include "textureoverrideeffectparam.h"
#include "ms2/client/ms2/gameobject.h"
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Resource manager (singleton 0x140a0afd0): texture load by path.
class Unk_ResourceMgr
{
public:
    Unk_PPSmartC FUN_141552f90(CString strPath, int nFlags);
};
Unk_ResourceMgr* FUN_140a0afd0();

// World TextureLayerManager (?\layer.cpp).
class Unk_TextureLayerMgr
{
public:
    void FUN_141443af0(TextureLayer* pLayer);                  // add
    void FUN_141443da0(TextureLayer* pLayer);                  // remove
};
class Unk_World
{
public:
    Unk_TextureLayerMgr* FUN_141bd3650();                      // WorldService::m_spTextureLayerManager
};
Unk_World* FUN_1403ed2d0();                                    // WorldService instance

// Depth-first walk over a node's subtree (0x30 bytes; ?\uichaoslightdialog.cpp COMDATs).
class Unk_NodeWalker
{
public:
    Unk_NodeWalker(NiAVObject* pRoot);                         // 0x141043760
    ~Unk_NodeWalker();                                         // 0x1410439e0
    NiAVObject* FUN_1410446c0(bool bChildren);                 // next node, NULL at the end
private:
    void* m_unk[6];
};

CString FUN_140cc2a00(const CString& strRoot, const CString& strPath);   // resource path join
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);   // TinyXML string attribute

// @0x14184b540
TextureOverrideEffectParam::TextureOverrideEffectParam()
    : CEffectParam(0xf)
{
}

// @0x14184b590
void TextureOverrideEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "texturepath", m_strTexturePath);
}
MS2_REPLACE_METHOD(0x14184b590, TextureOverrideEffectParam, vfunc_1, 63, 0x5AA431A8);

// @0x14184b5e0
bool TextureOverrideEffectParam::vfunc_5(int nFlags)
{
    if (FUN_140a0afd0())
        FUN_140a0afd0()->FUN_141552f90(FUN_140cc2a00("", m_strTexturePath), nFlags);
    return true;
}
MS2_REPLACE_METHOD(0x14184b5e0, TextureOverrideEffectParam, vfunc_5, 161, 0x73218F92);

// @0x14184b690
CEffectPtr TextureOverrideEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) TextureOverrideEffect;
}

// @0x14184b730
TextureOverrideEffect::TextureOverrideEffect()
    : m_spTexture(NULL)
{
}

// @0x14184b7b0
TextureOverrideEffect::~TextureOverrideEffect()
{
    if (m_arrLayers.GetCount() > 0)
        FUN_14184bd70();
}

// @0x14184b840
bool TextureOverrideEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    GameObject* pObject = pTarget->FUN_140a533b0();
    if (!pObject)
        return false;
    efd::list<NiAVObject*> listNodes;
    pObject->vfunc_44(&listNodes);
    m_vecNodes.clear();
    m_vecNodes.reserve(listNodes.size());
    for (efd::list<NiAVObject*>::iterator it = listNodes.begin(); it != listNodes.end(); ++it)
    {
        if (*it)
        {
            NiAVObjectPtr spNode(*it);
            m_vecNodes.push_back(spNode);
        }
    }
    const TextureOverrideEffectParam* pTexParam = static_cast<const TextureOverrideEffectParam*>(pParam);
    CString strPath = FUN_140cc2a00("", pTexParam->m_strTexturePath);
    m_spTexture = FUN_140a0afd0()->FUN_141552f90(strPath, 5);
    return true;
}
MS2_REPLACE_METHOD(0x14184b840, TextureOverrideEffect, vfunc_3, 592, 0xA3D89515);

// @0x14184baa0
void TextureOverrideEffect::vfunc_4()
{
    CEffect::vfunc_4();
    MS2_FOR_EACH(NiAVObjectPtr spNode, m_vecNodes)
        FUN_14184bbb0(spNode);
}
MS2_REPLACE_METHOD(0x14184baa0, TextureOverrideEffect, vfunc_4, 218, 0x83937FF4);

// @0x14184bb80
void TextureOverrideEffect::vfunc_7()
{
    CEffect::vfunc_7();
    FUN_14184bd70();
}

// @0x14184bbb0
void TextureOverrideEffect::FUN_14184bbb0(NiAVObjectPtr spNode)
{
    if (spNode == NULL)
        return;
    Unk_NodeWalker kWalker(spNode);
    NiAVObject* pChild;
    while ((pChild = kWalker.FUN_1410446c0(true)) != NULL)
    {
        NiProperty* pTexturing = pChild->GetProperty(NiProperty::TEXTURING);
        if (!pTexturing)
            continue;
        TextureLayer* pLayer = new (efd::MemHint(efd::MemHint::NONE))
            TextureLayer(2, pTexturing, m_spTexture.Get(), NULL);
        FUN_1403ed2d0()->FUN_141bd3650()->FUN_141443af0(pLayer);
        m_arrLayers.Add(pLayer);
    }
    spNode->UpdateProperties();
}
MS2_REPLACE_METHOD(0x14184bbb0, TextureOverrideEffect, FUN_14184bbb0, 433, 0x7C7675AE);

// @0x14184bd70
void TextureOverrideEffect::FUN_14184bd70()
{
    size_t nCount = m_arrLayers.GetCount();
    for (size_t i = 0; i < nCount; i++)
        FUN_1403ed2d0()->FUN_141bd3650()->FUN_141443da0(m_arrLayers[i]);
    MS2_FOR_EACH(NiAVObjectPtr spNode, m_vecNodes)
        spNode->UpdateProperties();
    m_arrLayers.RemoveAll();
}
MS2_REPLACE_METHOD(0x14184bd70, TextureOverrideEffect, FUN_14184bd70, 325, 0x1D5B6AD5);

// @0x14184c290
int TextureOverrideEffect::vfunc_12()
{
    return 0xf;
}


// Trailing unreferenced CRT memcpy_s COMDAT 0x14184c640.
__declspec(selectany) extern errno_t(__cdecl* const ms2_texOverrideMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x14010dd00-0x14010dd90 .text$di
// MS2-RANGE: 0x142cbbcc0-0x142cbbd00 .text$yd
#ifndef MS2_HOOK_DLL
const NiRTTI TextureOverrideEffect::ms_RTTI("TextureOverrideEffect", &CEffect::ms_RTTI);   // @0x14010dd00
#endif
static CString s_strSkill("skill");                                                    // @0x14010dd30
static CString s_strStun("stun");                                                      // @0x14010dd60

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x14184bb80, TextureOverrideEffect, vfunc_7, 34, 0x74E4BC82);
MS2_REPLACE_METHOD(0x14184c290, TextureOverrideEffect, vfunc_12, 11, 0x7688D63A);

