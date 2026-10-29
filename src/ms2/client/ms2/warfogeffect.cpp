// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See warfogeffect.h.
// MS2-UNIT: ?\warfogeffect.cpp
// MS2-RANGE: 0x141b732c0-0x141b745f0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\warfogeffect.cpp"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "ms2/placeholder/ms2stdafx.h"

#include "warfogeffect.h"

#include <NiAlphaProperty.h>
#include <NiColor.h>
#include <NiVertexColorProperty.h>
#include <NiZBufferProperty.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

NiNode* FUN_1411a6b10(void* pScene);
void* FUN_1403ed280();
void* FUN_1409f7ca0();                                                  // the physics scene
bool FUN_1416892f0(void* pScene, Unk_WarFogRay* pRay, int n);           // cast the ray; fills m_hit
unsigned FUN_140869420();                                               // tick count
float FUN_14029dba0(float f);                                           // sinf
float FUN_14029cc60(float f);                                           // cosf
float FUN_14029d220(float f);                                           // fabsf

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141b732c0
CWarFogEffect::CWarFogEffect() : m_spMesh(NULL)
{
    m_fRadius = -1.0f;
    m_bFlag24 = true;
    m_fAlpha = 0.45f;
    m_bFlag2c = false;
    m_fZ = 0.0f;
    m_nTick = 0;
}

// @0x141b73360
CWarFogEffect::~CWarFogEffect()
{
    FUN_141b733c0();
}

// @0x141b733c0
void CWarFogEffect::FUN_141b733c0()
{
    if (m_spMesh == NULL)
        return;
    NiMesh* pMesh = ((CMesh*)m_spMesh)->GetMesh();
    if (pMesh == NULL) {
        m_spMesh = NULL;
    } else {
        if (pMesh->GetParent() == NULL) {
            m_spMesh = NULL;
        } else {
            pMesh->GetParent()->DetachChild(pMesh);
            m_spMesh = NULL;
        }
    }
}
MS2_REPLACE_METHOD(0x141b733c0, CWarFogEffect, FUN_141b733c0, 213, 0xB5D547D5);

// @0x141b734a0
void CWarFogEffect::FUN_141b734a0(bool bVisible)
{
    if (m_spMesh == NULL)
        return;
    if (((CMesh*)m_spMesh)->GetMesh() == NULL)
        return;
    ((CMesh*)m_spMesh)->GetMesh()->SetAppCulled(!bVisible);
}
MS2_REPLACE_METHOD(0x141b734a0, CWarFogEffect, FUN_141b734a0, 137, 0xEF7188DD);

// @0x141b73530
void CWarFogEffect::FUN_141b73530(const Unk_WarFogParam* pParam, const efd::Point3& ptCenter)
{
    if (FUN_141b739e0(pParam)) {
        FUN_141b733c0();
        FUN_141b73ab0(pParam);
    }
    if (m_spMesh == NULL)
        return;
    efd::Point3 center = ptCenter;
    center.z += 75.0f;
    center.z = (center.z + m_fZ) * 0.5f;
    m_fZ = center.z;
    if (FUN_140869420() > m_nTick + 10U && m_bFlag2c) {
        float angle = 0.0f;
        for (int i = 0; i < 0x40; ++i) {
            angle = ((float)i / 63.0f) * 3.1415927f * 2.0f;
            NiPoint3 dir(FUN_14029cc60(angle), FUN_14029dba0(angle), 0.0f);
            NiPoint3 point(dir * m_fRadius + center);
            Unk_WarFogRay ray;
            ray.m_origin = center;
            ray.m_dir = dir;
            ray.m_distance = m_fRadius - 50.0f;
            ray.m_mask = 0x201;
            ray.m_pad_20 = 0;
            ray.m_pad_28 = 0;
            if (FUN_1416892f0(FUN_1409f7ca0(), &ray, 0)) {
                point = ray.m_hit + dir * 50.0f;
                ((CMesh*)m_spMesh)->SetPosition(i * 3, point - center);
                ((CMesh*)m_spMesh)->SetPosition(i * 3 + 1, point - center);
            } else {
                ((CMesh*)m_spMesh)->SetPosition(i * 3, (m_fRadius - 50.0f) * dir);
                ((CMesh*)m_spMesh)->SetPosition(i * 3 + 1, (m_fRadius + 50.0f) * dir);
            }
        }
        ((CMesh*)m_spMesh)->UpdateBound();
        m_nTick = FUN_140869420();
    }
    ((CMesh*)m_spMesh)->GetMesh()->SetTranslate(center);
}

// @0x141b739e0
bool CWarFogEffect::FUN_141b739e0(const Unk_WarFogParam* pParam)
{
    if (m_spMesh == NULL)
        return true;
    if (pParam->FUN_1403812a0() != m_fRadius)
        return true;
    if (m_bFlag2c != pParam->FUN_140381370())
        return true;
    if (FUN_14029d220(m_fAlpha - pParam->FUN_140381340()) > 0.001f)
        return true;
    if (m_bFlag24 != pParam->FUN_140381320())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x141b739e0, CWarFogEffect, FUN_141b739e0, 200, 0xC4235DE6);

// @0x141b73ab0
void CWarFogEffect::FUN_141b73ab0(const Unk_WarFogParam* pParam)
{
    m_fRadius = pParam->FUN_1403812a0();
    m_bFlag2c = pParam->FUN_140381370();
    m_fAlpha = pParam->FUN_140381340();
    m_bFlag24 = pParam->FUN_140381320();
    m_spMesh = NiNew CMesh(false, true, 0, 0xc3, 0x100, 0x15);
    NiNode* pScene = FUN_1411a6b10(FUN_1403ed280());
    pScene->AttachChild(((CMesh*)m_spMesh)->GetMesh(), false);
    float angle = 0.0f;
    for (int i = 0; i < 0x40; ++i) {
        angle = ((float)i / 63.0f) * 3.1415927f * 2.0f;
        ((CMesh*)m_spMesh)->SetPosition(i * 3,
            NiPoint3(FUN_14029cc60(angle) * (m_fRadius - 50.0f), FUN_14029dba0(angle) * (m_fRadius - 50.0f), 0.0f));
        ((CMesh*)m_spMesh)->SetPosition(i * 3 + 1,
            NiPoint3(FUN_14029cc60(angle) * (m_fRadius + 50.0f), FUN_14029dba0(angle) * (m_fRadius + 50.0f), 0.0f));
        ((CMesh*)m_spMesh)->SetPosition(i * 3 + 2,
            NiPoint3(FUN_14029cc60(angle) * (m_fRadius + 2000.0f), FUN_14029dba0(angle) * (m_fRadius + 2000.0f), 0.0f));
        ((CMesh*)m_spMesh)->SetColor(i * 3, NiColorA(0.0f, 0.0f, 0.0f, 0.0f));
        ((CMesh*)m_spMesh)->SetColor(i * 3 + 1, NiColorA(0.0f, 0.0f, 0.0f, m_fAlpha));
        ((CMesh*)m_spMesh)->SetColor(i * 3 + 2, NiColorA(0.0f, 0.0f, 0.0f, m_fAlpha));
    }
    for (int i = 0; i < 0x3f; ++i) {
        ((CMesh*)m_spMesh)->SetQuad(i << 2, (unsigned short)(i * 3), (unsigned short)(i * 3 + 1),
            (unsigned short)(i * 3 + 4), (unsigned short)(i * 3 + 3));
        ((CMesh*)m_spMesh)->SetQuad(i * 4 + 2, (unsigned short)(i * 3 + 1), (unsigned short)(i * 3 + 2),
            (unsigned short)(i * 3 + 5), (unsigned short)(i * 3 + 4));
    }
    NiMesh* pMesh = ((CMesh*)m_spMesh)->GetMesh();
    NiVertexColorProperty* pColor = NiNew NiVertexColorProperty;
    pColor->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
    pColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
    pMesh->AttachProperty(pColor);
    if (!m_bFlag2c) {
        NiZBufferProperty* pDepth = NiNew NiZBufferProperty;
        pDepth->SetZBufferTest(false);
        pDepth->SetZBufferWrite(false);
        pMesh->AttachProperty(pDepth);
    }
    NiAlphaProperty* pAlpha = NiNew NiAlphaProperty;
    pAlpha->SetAlphaBlending(true);
    pAlpha->SetAlphaTesting(false);
    pMesh->AttachProperty(pAlpha);
    pMesh->Update(0.0f, true);
    pMesh->UpdateProperties();
    pMesh->UpdateEffects();
    pMesh->UpdateNodeBound();
    pMesh->SetSelectiveUpdate(true);
    ((CMesh*)m_spMesh)->SetVertexCount(0xc0);
    ((CMesh*)m_spMesh)->SetTriangleCount(0x2f4);
    ((CMesh*)m_spMesh)->UpdateBound();
    pScene->UpdateProperties();
    pScene->UpdateEffects();
    pScene->UpdateNodeBound();
    pScene->Update(0.0f, true);
    m_nTick = FUN_140869420();
}

// @0x141b744e0 (the UCRT header-inline memmove_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
errno_t FUN_141b744e0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
