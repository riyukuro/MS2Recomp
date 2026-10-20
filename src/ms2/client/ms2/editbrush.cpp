// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). EditBrush / PaintBrush / NoiseBrush: the brushes of the deco
// editor. Each shows a circle (a 360-point line mesh) at the picked ground point; the paint brush stamps decoration
// instances at random points inside it, the noise brush re-rotates the instances already in it. See editbrush.h.
// Original source file name unknown (assumed from the class names).
// MS2-UNIT: ?\editbrush.cpp
// MS2-RANGE: 0x141197280-0x141198830 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\editbrush.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <math.h>
#include <atlcoll.h>
#include <NiMesh.h>
#include <NiVertexColorProperty.h>
#include <NiZBufferProperty.h>
#include <NiCommonSemantics.h>
#include <NiDataStreamElementLock.h>
#include "ms2/placeholder/editbrush.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/decoeditservice.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/postprocessing/outlinerenderstep.h"

CInputKeyHandler* FUN_14025e7c0();
CPhysXHelper* FUN_1409f7ca0();                                      // the physics helper singleton
int FUN_14109a9e0();                                                // rand()
const NiTransform& FUN_140a33f90(NiAVObject* pObject);              // GetLocalTransform
void FUN_140aacb60(NiAVObject* pObject, const NiTransform& xf);     // SetLocalTransform
NiNode* FUN_140a0b000(NiAVObject* pkObject);                        // parent of the object
void FUN_1405a85c0(void* pHandle);                                  // release the handle returned by a detach
void FUN_140adc7f0(NiMesh* pkMesh, int nType);                      // NiMesh::SetPrimitiveType
void FUN_140adc720(NiMesh* pkMesh);
void FUN_140adc810(NiMesh* pkMesh, int n);                          // NiMesh::SetSelectiveUpdate-like flag
float FUN_14028aed0(float f);                                       // floorf
Unk_StreamPoint FUN_141198410(Unk_StreamPoint ptCenter, float fRadius);

// The detach answered by the parent of an instance (slot 37 of the parent, as in cubecraft_2.cpp).
struct Unk_BrushHandle { void* m_pA; void* m_pB; };
class Unk_BrushParent { public: virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
    virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
    virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
    virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
    virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89();
    virtual void s90(); virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95(); virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99();
    virtual void s100(); virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105(); virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109();
    virtual void s110(); virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115(); virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119();
    virtual void s120(); virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125(); virtual void s126(); virtual void s127();
    virtual void s128(); virtual void s129(); virtual void s130(); virtual void s131(); virtual void s132(); virtual void s133(); virtual void s134(); virtual void s135(); virtual void s136(); virtual void s137(); virtual void s138(); virtual void s139(); virtual void s140(); virtual void s141(); virtual void s142(); virtual void s143(); virtual void s144(); virtual void s145(); virtual void s146(); virtual void s147(); virtual void s148(); virtual void s149();
};

// @0x141197280
EditBrush::EditBrush()
    : m_kColor(1.0f, 0.0f, 0.0f, 1.0f), m_ptPos(0.0f, 0.0f, 0.0f)
{
    m_vUnused.FUN_140a0a600(0.0f, 0.0f);
}

// @0x141197330
EditBrush::~EditBrush()
{
}

// @0x141198770
void EditBrush::vfunc_5() {}
// @0x141198780
void EditBrush::vfunc_4() {}
// @0x1411987b0
void EditBrush::vfunc_1() {}
// @0x1411987c0
void EditBrush::vfunc_3() {}
// @0x1411987d0
void EditBrush::vfunc_7(float) {}
// @0x1411987e0
void EditBrush::vfunc_6(float) {}
// @0x1411987f0
void EditBrush::vfunc_9(Unk_BrushVec2) {}
// @0x141198800
void EditBrush::vfunc_8(Unk_BrushVec2) {}

// @0x141197370
void EditBrush::vfunc_2()
{
    if (m_timer.FUN_140868ba0() == 0)
    {
        if (FUN_14025e7c0()->FUN_14116d950(0x2a, false, 0) && FUN_14025e7c0()->FUN_14116daa0(0, false, 0))
        {
            vfunc_4();
            m_timer.FUN_140868750(100);
            return;
        }
        if (FUN_14025e7c0()->FUN_14116d950(0x2a, false, 0) && FUN_14025e7c0()->FUN_14116daa0(1, false, 0))
        {
            vfunc_5();
            m_timer.FUN_140868750(100);
        }
    }
}

// @0x141197470
void EditBrush::FUN_141197470(const NiColorA& kColor)
{
    m_kColor = kColor;
}

// @0x1411974a0
void EditBrush::FUN_1411974a0(Unk_StreamPoint pt)
{
    m_ptPos = pt;
}

// @0x1411974d0
Unk_StreamPoint EditBrush::FUN_1411974d0()
{
    return m_ptPos;
}

// @0x141197500
PaintBrush::PaintBrush()
    : m_fRadius(100.0f), m_fDensity(10.0f), m_spMesh(0)
{
}

// @0x141197580
PaintBrush::~PaintBrush()
{
}

// @0x1411975c0
void PaintBrush::vfunc_1()
{
    NiColorA kColor = m_kColor;
    extern NiMesh* FUN_141197f80(float fRadius, NiColorA kColor);
    m_spMesh = FUN_141197f80(1.0f, kColor);
}

// @0x141197620
void PaintBrush::vfunc_2()
{
    EditBrush::vfunc_2();
    if (m_spMesh)
    {
        m_spMesh->SetScale(m_fRadius);
        m_spMesh->SetTranslate(reinterpret_cast<const efd::Point3&>(m_ptPos));    // NiPoint3(const efd::Point3&) temp
        m_spMesh->Update(0.0f, true);
    }
}

// @0x1411976e0
void PaintBrush::vfunc_3()
{
    if (m_spMesh)
        m_spMesh->RenderImmediate(FUN_140994450());
}

// The service the stamps go to.
static DecoEditService* BrushService()
{
    return TSingleton<DecoEditService>::s_instance;
}

// @0x141197750
// MS2-FUNCTIONAL: random stamp loop; temporaries of the transform differ vs exe
void PaintBrush::vfunc_4()
{
    for (int i = 0; (float)i < FUN_14028aed0(m_fDensity); ++i)
    {
        NiTransform xf;
        xf.MakeIdentity();
        xf.m_fScale = 1.0f;
        Unk_StreamPoint ptHit = FUN_141198410(m_ptPos, m_fRadius);
        xf.m_Translate = *(NiPoint3*)&ptHit;
        if (ptHit.FUN_140552700(Unk_StreamPoint(0.0f, 0.0f, 0.0f)))
            BrushService()->AddTransform(xf);
    }
    BrushService()->RefreshLayers();
}

// @0x1411978a0
// MS2-FUNCTIONAL: detach loop; the handle temporaries differ vs exe
void PaintBrush::vfunc_5()
{
    ATL::CAtlArray<NiMeshHWInstance*> aInstances;
    BrushService()->CollectNear(m_ptPos, m_fRadius, aInstances);
    for (unsigned i = 0; i < aInstances.GetCount(); ++i)
    {
        NiMeshHWInstance* pInstance = aInstances[i];
        if (pInstance != 0)
        {
            Unk_BrushParent* pParent = (Unk_BrushParent*)FUN_140a0b000((NiAVObject*)pInstance);
            if (pParent != 0)
            {
                Unk_BrushHandle hOut;
                ((void (*)(Unk_BrushParent*, Unk_BrushHandle*, NiMeshHWInstance*))(*(void***)pParent)[37])(pParent, &hOut, pInstance);
                FUN_1405a85c0(&hOut);
            }
        }
    }
    BrushService()->RefreshLayers();
}

// @0x1411979e0
void PaintBrush::vfunc_6(float fRadius)
{
    m_fRadius = fRadius;
    vfunc_1();
}

// @0x141197a20
void PaintBrush::vfunc_7(float fDensity)
{
    m_fDensity = fDensity;
}

// @0x141197a50
NoiseBrush::NoiseBrush()
    : m_fRadius(100.0f), m_spMesh(0)
{
    m_vScale.FUN_140a0a600(1.0f, 1.0f);
    m_vRotation.FUN_140a0a600(0.0f, 360.0f);
}

// @0x141197b00
NoiseBrush::~NoiseBrush()
{
}

// @0x141197b40
void NoiseBrush::vfunc_1()
{
    NiColorA kColor = m_kColor;
    extern NiMesh* FUN_141197f80(float fRadius, NiColorA kColor);
    m_spMesh = FUN_141197f80(1.0f, kColor);
}

// @0x141197ba0
void NoiseBrush::vfunc_2()
{
    EditBrush::vfunc_2();
    if (m_spMesh)
    {
        m_spMesh->SetScale(m_fRadius);
        m_spMesh->SetTranslate(reinterpret_cast<const efd::Point3&>(m_ptPos));    // NiPoint3(const efd::Point3&) temp
        m_spMesh->Update(0.0f, true);
    }
}

// @0x141197c60
void NoiseBrush::vfunc_3()
{
    if (m_spMesh)
        m_spMesh->RenderImmediate(FUN_140994450());
}

// A random value in [fMin, fMax] (rand() / 32767).
float FUN_141198810()
{
    return (float)FUN_14109a9e0() / 32767.0f;
}

// @0x141198570
float FUN_141198570(float fMin, float fMax)
{
    return fMin + FUN_141198810() * (fMax - fMin);
}

// @0x141197f00
static float NoiseScale(NoiseBrush* pBrush)
{
    return FUN_141198570(pBrush->m_vScale.m_x, pBrush->m_vScale.m_y);
}

// @0x141197f30
static float NoiseAngle(NoiseBrush* pBrush)
{
    return FUN_141198570(pBrush->m_vRotation.m_x, pBrush->m_vRotation.m_y) * 3.1415927f / 180.0f;
}

// @0x141197cd0
// MS2-FUNCTIONAL: randomises rotation and scale of every instance in the circle
void NoiseBrush::vfunc_4()
{
    ATL::CAtlArray<NiMeshHWInstance*> aInstances;
    BrushService()->CollectNear(m_ptPos, m_fRadius, aInstances);
    for (unsigned i = 0; i < aInstances.GetCount(); ++i)
    {
        NiMeshHWInstance* pInstance = aInstances[i];
        if (pInstance != 0)
        {
            NiTransform xf = FUN_140a33f90((NiAVObject*)pInstance);
            xf.m_Rotate.MakeZRotation(NoiseAngle(this));
            xf.m_fScale = NoiseScale(this);
            FUN_140aacb60((NiAVObject*)pInstance, xf);
        }
    }
    BrushService()->RefreshLayers();
}

// @0x141197e60
void NoiseBrush::vfunc_5()
{
}

// @0x141197e70
void NoiseBrush::vfunc_6(float fRadius)
{
    m_fRadius = fRadius;
    vfunc_1();
}

// @0x141197eb0
void NoiseBrush::vfunc_8(Unk_BrushVec2 v)
{
    m_vScale = v;
}

// @0x141197ed0
void NoiseBrush::vfunc_9(Unk_BrushVec2 v)
{
    m_vRotation = v;
}

// @0x141197f80
// MS2-FUNCTIONAL: Gamebryo circle-mesh builder; the exe's inline stream/lock temporaries are laid out differently
NiMesh* FUN_141197f80(float fRadius, NiColorA kColor)
{
    NiPoint3 aPoints[360];
    for (int i = 0; i < 360; ++i)
    {
        float fSin = sinf((float)i * 3.1415927f / 180.0f);
        float fCos = cosf((float)i * 3.1415927f / 180.0f);
        aPoints[i] = NiPoint3(fCos * fRadius, fSin * fRadius, 0.0f);
    }
    NiVertexColorProperty* pkVC = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
    pkVC->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
    pkVC->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
    NiMesh* pkMesh = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
    pkMesh->AttachProperty(pkVC);
    FUN_140adc7f0(pkMesh, 3);
    FUN_140adc720(pkMesh);
    pkMesh->AddStream(NiCommonSemantics::POSITION(), 0, NiDataStreamElement::F_FLOAT32_3, 360, 0x13,
        NiDataStream::USAGE_VERTEX, aPoints, false, true);
    NiDataStreamElementLock kColors = pkMesh->AddStreamGetLock(NiCommonSemantics::COLOR(), 0,
        NiDataStreamElement::F_FLOAT32_4, 360, 0x12, NiDataStream::USAGE_VERTEX, false, true);
    NiTStridedRandomAccessIterator<NiColorA> it = kColors.begin<NiColorA>(0);
    for (int i = 0; i < 360; ++i)
        it[i] = kColor;
    kColors.Unlock();
    NiZBufferProperty* pkZ = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
    pkZ->SetZBufferTest(false);
    pkZ->SetZBufferWrite(true);
    pkMesh->AttachProperty(pkZ);
    pkMesh->Update(0.0f, true);
    pkMesh->UpdateProperties();
    pkMesh->UpdateEffects();
    pkMesh->UpdateNodeBound();
    FUN_140adc810(pkMesh, 1);
    return pkMesh;
}

// @0x141198410
// MS2-FUNCTIONAL: a random point inside the circle dropped onto the ground
Unk_StreamPoint FUN_141198410(Unk_StreamPoint ptCenter, float fRadius)
{
    int nAngle = FUN_14109a9e0();
    int nDist = FUN_14109a9e0();
    float fSin = sinf((float)(nAngle % 360) * 3.1415927f / 180.0f);
    float fCos = cosf((float)(nAngle % 360) * 3.1415927f / 180.0f);
    Unk_StreamPoint ptOff(fCos * (float)(nDist % (int)fRadius), fSin * (float)(nDist % (int)fRadius), 100.0f);
    Unk_RayCastInfo info;
    Unk_StreamPoint ptHit(0.0f, 0.0f, 0.0f);
    Unk_StreamPoint ptFrom = ptCenter.FUN_14097fd50(ptOff);
    FUN_1409f7ca0()->FUN_14168a310(ptFrom, ptHit, &info, 800.0f, 0, 0x201);
    return ptHit;
}
