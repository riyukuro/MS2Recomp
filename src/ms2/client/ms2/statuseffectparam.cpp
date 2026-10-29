// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "StatusEffect" effect: param + runtime effect.
// MS2-UNIT: ?\statuseffectparam.cpp
// MS2-RANGE: 0x1401050e0-0x140105110 .text$di
// MS2-RANGE: 0x141801040-0x141803210 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAV?$SmartPointer@VNiNode@@@efd@@AEAH$0A@@?$pair@V?$SmartPointer@VNiNode@@@efd@@H@std@@QEAA@AEAV?$SmartPointer@VNiNode@@@efd@@AEAH@Z 0x141801c10 ; unique
// MS2-PIN: ??$make_pair@AEAV?$SmartPointer@VNiNode@@@efd@@AEAH@std@@YA?AU?$pair@V?$SmartPointer@VNiNode@@@efd@@H@0@AEAV?$SmartPointer@VNiNode@@@efd@@AEAH@Z 0x141802b30 ; unique
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statuseffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "statuseffectparam.h"
#include <map>
#include <new>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <atlcoll.h>
#include <efd/MemoryDefines.h>
#include <efd/StdContainers.h>
#include <NiAVObject.h>
#include <NiMesh.h>
#include <NiFixedString.h>
#include <NiFloatExtraData.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
bool FUN_14028d470(float a, float b);                               // nearly equal
unsigned FUN_140869420();                                           // millisecond clock
void* FUN_1409849b0(void* pHandle);                                 // handle -> node pointer
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
void FUN_1409f76f0(void* pSelf, void* pNew);                        // SmartPointer<NiNode>::Reset(pNew)
void* FUN_1409475f0(efd::SmartPointer<NiNode>* p);                  // const get
const void* FUN_140947900(void* pNode);                             // world translate
void FUN_140194470(void* pDst, const void* pSrc);                   // copy a point
const NiMaterial* FUN_140a17cd0(NiMesh* pMesh);                     // active material

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

// A material-table entry; only its state word (+0x540) is read here. Its exe accessor (0x1427542f0) lies in the
// statically linked runtime range that the hook DLL does not map, so it is expressed inline instead.
struct Unk_MaterialTable;                                           // DAT_143d69198
struct Unk_MaterialEntry
{
    char m_pad[0x540];
    unsigned m_nState;
    bool IsActive() const { return m_nState - 1 <= 2; }
};
extern Unk_MaterialTable DAT_143d69198;
Unk_MaterialEntry* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMaterial);   // table lookup, NULL-safe
extern NiFixedString DAT_143ae5130;                                 // extra-data keys
extern NiFixedString DAT_143ae5138;
extern unsigned DAT_1439f8244;                                      // blink interval (ms)

// The post-process service singleton (0x1409a8b20): two node -> value maps at +0x68 (status kind) and +0x78 (count).
typedef efd::map<efd::SmartPointer<NiNode>, int> Unk_NodeIntMap;
class Unk_PostProcessSvc
{
public:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
    void* m_pad_38; void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58; void* m_pad_60;
    Unk_NodeIntMap m_mapKind;       // +0x68
    Unk_NodeIntMap m_mapCount;      // +0x78
};
MS2_CHECK_OFFSET(Unk_PostProcessSvc, m_mapKind, 0x68);
MS2_CHECK_OFFSET(Unk_PostProcessSvc, m_mapCount, 0x78);
Unk_PostProcessSvc* FUN_1409a8b20();

// Effect target context: the owner's scene node handle sits at +0x10.
struct Unk_StatusTarget
{
    void* m_pad_00; void* m_pad_08;
    void* m_hNode;                  // +0x10
};
MS2_CHECK_OFFSET(Unk_StatusTarget, m_hNode, 0x10);

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entry).
const NiRTTI CStatusEffect::ms_RTTI("CStatusEffect", &CEffect::ms_RTTI);        // @0x1401050e0
#else
const NiRTTI CStatusEffect::ms_RTTI("CStatusEffect", &CEffect::ms_RTTI);
#endif

// @0x141801040
CStatusEffectParam::CStatusEffectParam()
    : CEffectParam(8), m_strCategory("")
{
}

// @0x1418010a0
void CStatusEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "category", m_strCategory);
}
MS2_REPLACE_METHOD(0x1418010a0, CStatusEffectParam, vfunc_1, 63, 0x33C924FF);

// @0x1418010f0
// Not hooked: constructs CStatusEffect with this unit's (DLL) constructor/vftable.
CEffectPtr CStatusEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CStatusEffect;
}

// @0x141801190
CStatusEffect::CStatusEffect()
    : m_spNode((NiNode*)0)
{
}

// @0x1418011e0
CStatusEffect::~CStatusEffect()
{
}

// @0x141801220
bool CStatusEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CStatusEffectParam* pStatus = static_cast<const CStatusEffectParam*>(pParam);
    m_dStartTime = (double)(unsigned)(FUN_140869420() + (int)(__int64)(pStatus->m_fStartDelay * 1000.0f));
    m_bSuper = false;
    m_bFlag = false;
    FUN_1409f76f0(&m_spNode, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&reinterpret_cast<Unk_StatusTarget*>(pTarget)->m_hNode)));
    if (pStatus->m_strCategory.CompareNoCase("ice") == 0)
        m_nKind = 0;
    else if (pStatus->m_strCategory.CompareNoCase("fire") == 0)
        m_nKind = 1;
    else if (pStatus->m_strCategory.CompareNoCase("poison") == 0)
        m_nKind = 2;
    else if (pStatus->m_strCategory.CompareNoCase("dark") == 0)
        m_nKind = 3;
    else if (pStatus->m_strCategory.CompareNoCase("super") == 0)
    {
        m_nKind = 4;
        m_bSuper = true;
    }
    else
        m_nKind = 7;
    if (FUN_14028d470(pStatus->m_fStartDelay, 0.0f))
        vfunc_4();
    return true;
}
MS2_REPLACE_METHOD(0x141801220, CStatusEffect, vfunc_3, 467, 0x8F155918);

// @0x141801400
bool CStatusEffect::vfunc_9()
{
    unsigned nNow = FUN_140869420();
    if (m_b2d)
        return false;
    if ((double)nNow > m_dStartTime + (double)(m_fDuration * 1000.0f))
        return m_b2c;
    if ((double)nNow > m_dStartTime && !m_b2e)
        vfunc_4();
    if (m_bSuper && nNow - m_dwLastTick > DAT_1439f8244)
    {
        m_bFlag = m_bFlag ? 0 : 1;
        FUN_141801900(0);
        m_dwLastTick = nNow;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141801400, CStatusEffect, vfunc_9, 268, 0x7BD39F5E);

// @0x141801520
void CStatusEffect::vfunc_4()
{
    int nCount = 0;
    Unk_NodeIntMap::const_iterator it = FUN_1409a8b20()->m_mapCount.find(m_spNode);
    if (it != FUN_1409a8b20()->m_mapCount.end())
    {
        nCount = it->second;
        FUN_1409a8b20()->m_mapCount.erase(m_spNode);
        FUN_1409a8b20()->m_mapKind.erase(m_spNode);
    }
    nCount = nCount + 1;
    FUN_1409a8b20()->m_mapCount.insert(std::make_pair(m_spNode, nCount));
    FUN_1409a8b20()->m_mapKind.insert(std::make_pair(m_spNode, m_nKind));
    if (m_nKind == 4)
        FUN_141801900(0);
    m_b2e = true;
    m_bFlag = true;
}
MS2_REPLACE_METHOD(0x141801520, CStatusEffect, vfunc_4, 492, 0x9D8ABC3C);

// @0x141801720
void CStatusEffect::vfunc_7()
{
    int nCount = 0;
    Unk_NodeIntMap::const_iterator it = FUN_1409a8b20()->m_mapCount.find(m_spNode);
    if (it != FUN_1409a8b20()->m_mapCount.end())
    {
        nCount = it->second;
        FUN_1409a8b20()->m_mapCount.erase(m_spNode);
    }
    nCount = nCount - 1;
    FUN_1409a8b20()->m_mapCount.insert(std::make_pair(m_spNode, nCount));
    if (nCount <= 0)
    {
        FUN_1409a8b20()->m_mapCount.erase(m_spNode);
        FUN_1409a8b20()->m_mapKind.erase(m_spNode);
    }
    m_bFlag = false;
}
MS2_REPLACE_METHOD(0x141801720, CStatusEffect, vfunc_7, 392, 0x6DE30B28);

// @0x1418018b0
int CStatusEffect::vfunc_8(void* pOut)
{
    FUN_140194470(pOut, FUN_140947900(FUN_1409475f0(&m_spNode)));
    return 1;
}
MS2_REPLACE_METHOD(0x1418018b0, CStatusEffect, vfunc_8, 62, 0xCE06636C);

// @0x141801900
void CStatusEffect::FUN_141801900(void* pUnused)
{
    Unk_SceneWalker walker(m_spNode);
    NiAVObject* pObj;
    while ((pObj = walker.Next(true)) != 0)
    {
        NiMesh* pMesh = (NiMesh*)FUN_14098d8d0(&NiMesh::ms_RTTI, pObj);
        if (pMesh)
        {
            Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, FUN_140a17cd0(pMesh));
            if (pEntry && pEntry->IsActive())
            {
                float fB = m_bFlag ? 0.7f : 0.0f;
                float fA = m_bFlag ? 0.3f : 1.0f;
                if (m_bFlag)
                {
                    fB = 0.5f;
                    fA = 0.5f;
                }
                else
                {
                    fB = 0.0f;
                    fA = 1.0f;
                }
                NiFloatExtraData* pExtraA = NiDynamicCast(NiFloatExtraData, pMesh->GetExtraData(DAT_143ae5130));
                if (pExtraA)
                    pExtraA->SetValue(fA);
                else
                    pMesh->AddExtraData(DAT_143ae5130, NiNew NiFloatExtraData(fA));
                NiFloatExtraData* pExtraB = NiDynamicCast(NiFloatExtraData, pMesh->GetExtraData(DAT_143ae5138));
                if (pExtraB)
                    pExtraB->SetValue(fB);
                else
                    pMesh->AddExtraData(DAT_143ae5138, NiNew NiFloatExtraData(fB));
            }
        }
    }
}

// @0x141802db0
int CStatusEffect::vfunc_12()
{
    return 8;
}

// The UCRT's `static __inline memcpy_s` of this TU (the efd::map node copy's), compiled with memset/memcpy as calls.
#pragma function(memcpy, memset)
// @0x1418030a0
static __inline errno_t ms2_sep_memcpy_s(void* const d, rsize_t const dsz, void const* const s, rsize_t const ssz)
{
    if (ssz == 0)
    {
        return 0;
    }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnSepMemcpyS)(void*, rsize_t, const void*, rsize_t) = &ms2_sep_memcpy_s;
#pragma intrinsic(memcpy, memset)

void* FUN_1420b8410();                                              // default memory log handler factory

// @0x1418031f0
void FUN_1418031f0()
{
    FUN_1420b8410();
}
