// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxMovieBackground: the full-screen background movie. See gfxmoviebackground.h.
// MS2-UNIT: client\ms2\gfxmoviebackground.cpp
// MS2-RANGE: 0x1400ebd60-0x1400ebf20 .text$di
// MS2-RANGE: 0x141279710-0x14127d290 .text$mn
// MS2-RANGE: 0x142cae900-0x142cae990 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$SmartPointer@VNiRenderedTexture@@@efd@@QEAA@XZ 0x14127c650 ; order
// MS2-PIN: ??1?$SmartPointer@VStreamMetaDataObject@NiStream@@@efd@@QEAA@XZ 0x14127c680 ; order
// MS2-PIN: ??4?$SmartPointer@VMinimapViewport@@@efd@@QEAAAEAV01@PEAVMinimapViewport@@@Z 0x14127c710 ; unique
// MS2-PIN: ??4?$SmartPointer@VNiScreenFillingRenderView@@@efd@@QEAAAEAV01@PEAVNiScreenFillingRenderView@@@Z 0x14127c860 ; unique
// MS2-PIN: ??B?$SmartPointer@VNiProperty@@@efd@@QEBAPEAVNiProperty@@XZ 0x14127c930 ; order
// MS2-PIN: ??B?$SmartPointer@VNiZBufferProperty@@@efd@@QEBAPEAVNiZBufferProperty@@XZ 0x14127c950 ; order
// MS2-PIN: ??C?$Ptr@VMovie@GFx@Scaleform@@@Scaleform@@QEBAPEAVMovie@GFx@1@XZ 0x14127c960 ; unique
// MS2-PIN: ??C?$Ptr@VUnk_GFxHandleObj@@@Scaleform@@QEBAPEAVUnk_GFxHandleObj@@XZ 0x14127c980 ; order
// MS2-PIN: ??C?$SmartPointer@VNiScreenFillingRenderView@@@efd@@QEBAPEAVNiScreenFillingRenderView@@XZ 0x14127c9c0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$Ptr@VUnk_GFxHandleObj@@@Scaleform@@QEAA@XZ 0x14127c550
// MS2-PIN: ??1?$SmartPointer@VNiSPWorkflow@@@efd@@QEAA@XZ 0x14127c5c0
// MS2-PIN: ??1?$SmartPointer@VMinimapViewport@@@efd@@QEAA@XZ 0x14127c5f0
// MS2-PIN: ??4?$SmartPointer@VNiProperty@@@efd@@QEAAAEAV01@AEBV01@@Z 0x14127c780
// MS2-PIN: ??B?$SmartPointer@VNiScreenFillingRenderView@@@efd@@QEBAPEAVNiScreenFillingRenderView@@XZ 0x14127c940
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "gfxmoviebackground.h"
#include <NiAlphaProperty.h>
#include <NiMaterialProperty.h>
#include <NiVertexColorProperty.h>
#include <NiZBufferProperty.h>
#include <NiFogProperty.h>
#include <NiTexturingProperty.h>
#include <NiMeshScreenElements.h>
#include <NiViewRenderClick.h>
#include <NiDefaultClickRenderStep.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderer.h>
#include <NiMaterial.h>
#include <NiDX9TextureData.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include <efd/ServiceManager.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- file statics (.text$di) ----
#ifndef MS2_HOOK_DLL
const NiRTTI GFxMovieBackground::ms_RTTI("GFxMovieBackground", &GFxMovieEventHandler::ms_RTTI);     // @0x1400ebd60
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/gfxmoviebackground_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
#else
const NiRTTI GFxMovieBackground::ms_RTTI("GFxMovieBackground", &GFxMovieEventHandler::ms_RTTI);
#endif

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
class Unk_BgLog { public: void FUN_1401ce2f0(const char* szMessage); };
Unk_BgLog* FUN_140a44830();                                                 // the logger
extern char DAT_143b059e8;                                                  // efd::SmartPointer<efd::ServiceManager> cell
extern char DAT_143ae52e0;                                                  // material name of the screen quad
extern char DAT_143a08cd8;                                                  // the reference axis of the camera angle
ecr::RenderService* FUN_1411d15b0(efd::ServiceManager* pManager);
efd::ServiceManager* FUN_1401cd190(char* pCell);                            // SmartPointer<ServiceManager>::operator->

// The GFx renderer HAL: slot 67 wraps a D3D surface into a render target.
class Unk_BgHal
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
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual Unk_BgTarget* vfunc_67(IDirect3DSurface9* pSurface, int nFlags);
};
Unk_BgHal* FUN_1422cf060();

// The UI entity that owns the movie (looked up by the id of the local player); slots 60/61 take the movie's AS object.
class Unk_BgOwner
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
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60(MS2Ptr<AScript> spScript);
    virtual void vfunc_61(MS2Ptr<AScript> spScript, const Scaleform::GFx::Value* pArgs, unsigned nArgs);
};
Unk_BgOwner* FUN_1422b9e50(void* pId);
void* FUN_1408e57f0();
MS2Ptr<AScript> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);

// The camera manager (FUN_1409478c0): the direction the camera looks along.
class Unk_BgCamera
{
public:
    int FUN_140a18070();
    Unk_StreamPoint FUN_140af0340();
};
Unk_BgCamera* FUN_1409478c0();
float FUN_140b02b90(float f);                                               // angle of the dot product

// The minimap viewport: projects a world position to the background (returns false when it is off screen).
class MinimapViewport : public NiRefObject
{
public:
    MinimapViewport();                                                      // 0x1414856d0
    unsigned FUN_141485770(int n);
    bool FUN_141486450(const NiPoint3& kPos, NiPoint2& kOut, float fScale);
private:
    char m_pad[0x90 - sizeof(NiRefObject)];
};
MS2_CHECK_SIZE(MinimapViewport, 0x90);

// The ref-counted handle objects of vfunc_9 (Scaleform render handles): AddRef/Release are out-of-line library functions.
class Unk_BgDispHandle;
class Unk_GFxHandleObj
{
public:
    void AddRef();                                                          // 0x14257dc30
    void Release();                                                         // 0x14257dcb0
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
    virtual Unk_BgTarget* vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(Unk_BgTarget* pTarget, int nFlags);
    void* FUN_142582270();
    void FUN_142582230(void* p);
    void Assign(Unk_BgDispHandle& kHandle);                                 // 0x14127cb10
};
// The display handle copy of the movie (vfunc_9): a ref-counted pointer, wrapped twice (0x14127c160 <- 0x14127c3d0 <- 0x14127c130).
class Unk_BgHandleRef
{
public:
    Unk_BgHandleRef(const Unk_BgHandleRef& r);                              // 0x14127c160
    Unk_GFxHandleObj* m_p;
};
class Unk_BgDispBase : public Unk_BgHandleRef
{
public:
    Unk_BgDispBase(const Unk_BgDispBase& r);                                // 0x14127c3d0
};
class Unk_BgDispHandle : public Unk_BgDispBase
{
public:
    Unk_BgDispHandle(const Unk_BgDispHandle& r);                            // 0x14127c130
    ~Unk_BgDispHandle();                                                    // 0x14127c530
    int FUN_1425805a0(void* p);
    void* FUN_142580250();
    void* GetObj();                                                         // 0x14127cc80
};
void FUN_14257ec50(Unk_BgDispHandle* p);
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
class Unk_BgWorldMgr { public: void* FUN_141bd0cc0(); NiPoint3 FUN_141bd3dc0(); };   // 3dc0 returns by value (hidden pointer, worldservice.h)
Unk_BgWorldMgr* FUN_1403ed2d0();
bool* FUN_1422dad70(void* pThis, void* pOut, char n);   // pOut: caller temp (key-state flags), returned
NiMaterial* FUN_141d284a0(char* szName);
void FUN_14116d500(void* pMat, const NiColor& kColor);
void FUN_140980f20(void* p, int v);
void FUN_140980e60(void* p, int v);
void FUN_1409807b0(void* p, int v);
void FUN_1409805c0(void* p, int v);
void FUN_1409806e0(void* p, int v);
void FUN_140980880(void* p, int v);
CString FUN_140188f50(const char* sz, int n);
CString FUN_140cc2ad0(const CString& strPrefix, const CString& strName);

// ---- display handle glue ----
// @0x14127c160
Unk_BgHandleRef::Unk_BgHandleRef(const Unk_BgHandleRef& r)
{
    if (r.m_p != 0)
        r.m_p->AddRef();
    m_p = r.m_p;
}
// MS2-FUNCTIONAL: wrapper of the display handle copy; frame slot order differs
// @0x14127c3d0
Unk_BgDispBase::Unk_BgDispBase(const Unk_BgDispBase& r) : Unk_BgHandleRef(r) {}
// @0x14127c130
Unk_BgDispHandle::Unk_BgDispHandle(const Unk_BgDispHandle& r) : Unk_BgDispBase(r) {}
// MS2-FUNCTIONAL: dtor wrapper; frame slot order differs
// @0x14127c530
Unk_BgDispHandle::~Unk_BgDispHandle() { FUN_14257ec50(this); }
// @0x14127cc80
void* Unk_BgDispHandle::GetObj() { return FUN_142580250(); }
// @0x14127cb10
void Unk_GFxHandleObj::Assign(Unk_BgDispHandle& kHandle) { FUN_142582230(kHandle.GetObj()); }

// ---- Unk_BgComPtr<T> ----
// @0x14127c1a0
template <class T> Unk_BgComPtr<T>::Unk_BgComPtr(T* p)
{
    if (p != 0)
        p->vfunc_1();
    m_p = p;
}
// @0x14127c580
template <class T> Unk_BgComPtr<T>::~Unk_BgComPtr()
{
    if (m_p != 0)
        m_p->vfunc_2();
}
// @0x14127c6b0
template <class T> Unk_BgComPtr<T>& Unk_BgComPtr<T>::operator=(T* p)
{
    if (p != 0)
        p->vfunc_1();
    if (m_p != 0)
        m_p->vfunc_2();
    m_p = p;
    return *this;
}
// @0x14127c920
template <class T> Unk_BgComPtr<T>::operator T*() const { return m_p; }
// @0x14127c970
template <class T> T* Unk_BgComPtr<T>::operator->() const { return m_p; }

// ---- AScript::Invoke overloads of this unit ----
// @0x14127bfb0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, float a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    return FUN_1422bb8f0(szMethod, args);
}
// @0x14127c050
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, float a1, float a2, float a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// The render service through the service manager cell.
// MS2-FUNCTIONAL: argument evaluation order of the nested call differs
// @0x14127bf80
static ecr::RenderService* Unk_GetRenderService(char* pCell)
{
    return FUN_1411d15b0(FUN_1401cd190(pCell));
}

// ---- GFxMovieBackground ----
// @0x141279710
GFxMovieBackground::GFxMovieBackground(const CString& strBg, unsigned nCameraFlag, unsigned nPosFlag)
    : m_nCameraFlag(nCameraFlag), m_nPosFlag(nPosFlag), m_n98(0), m_strBg(strBg), m_bLoaded(0),
      m_spViewport(0), m_spScript(0), m_spRenderTexture(0), m_pOverlay(0), m_spRenderView(0), m_spRenderTarget(0)
{
    m_18 = 4;
}
// MS2-FUNCTIONAL: dtor: smart-pointer release sequence and temporaries differ from the exe
// @0x141279840
GFxMovieBackground::~GFxMovieBackground()
{
    if (m_spScript.get() != 0)
        m_spScript->Invoke("clearLoader");
    m_spViewport = 0;
    m_spScript = 0;
    if (m_spRenderView != 0)
    {
        FUN_14127b290();
        m_spRenderView = 0;
    }
    if (m_spRenderTarget != 0)
    {
        m_spRenderTarget->vfunc_2();
        m_spRenderTarget = 0;
    }
    if (m_pOverlay != 0)
    {
        m_pOverlay->vfunc_2();
        m_pOverlay = 0;
    }
    if (m_spRenderTexture != 0)
        m_spRenderTexture = 0;
}
// @0x14127cc60
void* GFxMovieBackground::vfunc_2() { return (void*)&ms_RTTI; }
// MS2-FUNCTIONAL: Value/ASArgList temporaries and string compares differ in order from the exe
// @0x141279a70
void GFxMovieBackground::vfunc_4(void* pUnused, const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (_stricmp("initializeClass", szEvent) == 0)
    {
        if (nArgs != 0)
        {
            Scaleform::GFx::Value vArg(*pArgs);
            m_spScript = FUN_140acca70(m_18, vArg);
            if (m_spScript.get() != 0)
                m_spScript->Invoke("loadBG", FUN_14127be10(), m_nCameraFlag);
            m_spViewport = NiNew MinimapViewport;
            m_n98 = m_spViewport->FUN_141485770(0);
        }
    }
    else if (_stricmp("loadComplete", szEvent) == 0)
    {
        m_bLoaded = 1;
        Unk_BgOwner* pOwner = FUN_1422b9e50(FUN_1408e57f0());
        if (pOwner != 0)
            pOwner->vfunc_60(m_spScript);
    }
    else if (_stricmp("dispatchEvent", szEvent) == 0)
    {
        Unk_BgOwner* pOwner = FUN_1422b9e50(FUN_1408e57f0());
        if (pOwner != 0)
            pOwner->vfunc_61(m_spScript, pArgs, nArgs);
    }
}
// @0x141279de0
void GFxMovieBackground::vfunc_5(bool b)
{
}
// MS2-FUNCTIONAL: by-value CString/loader argument temps differ
// @0x141279df0
int GFxMovieBackground::vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags)
{
    if (GFxMovie::vfunc_6(pLoader, strPath, nLoadFlags) == 0)
        return 0;
    if (FUN_14127b3d0() == 0)
        return 0;
    if (FUN_14127bb50() == 0)
        return 0;
    if (FUN_14127b9e0() == 0)
        return 0;
    if (FUN_14127b100() == 0)
        return 0;
    if (FUN_14127bcb0(m_spRenderTexture) == 0)
        return 0;
    return 1;
}
// MS2-FUNCTIONAL: GFx event temp layout differs
// @0x141279f90
int GFxMovieBackground::vfunc_7(int x, int y)
{
    m_60->SetBackgroundAlpha(0.0f);
    m_60->SetViewport(x, y, 0, 0, x, y, 2);
    Scaleform::GFx::Event kEvent(Scaleform::GFx::Event::MouseMove);
    m_60->HandleEvent(kEvent);
    return 1;
}
// MS2-FUNCTIONAL: float/NiPoint3 temporaries and branch layout differ
// @0x14127a070
void GFxMovieBackground::vfunc_8(float fTime)
{
    GFxMovie::vfunc_8(fTime);
    Unk_BgCamera* pCamera = FUN_1409478c0();
    if (pCamera->FUN_140a18070() != 0 && !m_spScript.IsNull() && m_n98 != 0)
    {
        Unk_StreamPoint kDir = pCamera->FUN_140af0340();
        kDir.FUN_140968990();
        float fDot = kDir.FUN_140a00f20(*(const Unk_StreamPoint*)&DAT_143a08cd8);
        if (m_nCameraFlag != 0)
        {
            float fAngle = FUN_140b02b90(fDot);
            m_spScript->Invoke("setCameraDistance", 1.0471976f, 1.5707964f, fAngle);
        }
        if (m_nPosFlag != 0)
        {
            PCBase* pPC = static_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
            NiPoint2 kScreen;
            if (pPC == 0)
            {
                if (m_spViewport != 0)
                {
                    NiPoint3 kPos(FUN_1403ed2d0()->FUN_141bd3dc0());
                    if (m_spViewport->FUN_141486450(kPos, kScreen, 1.0f))
                        m_spScript->Invoke("updatePos", kScreen.x);
                }
            }
            else
            {
                if (m_spViewport != 0)
                {
                    NiPoint3 kPos(pPC->vfunc_18());
                    if (m_spViewport->FUN_141486450(kPos, kScreen, 1.0f))
                        m_spScript->Invoke("updatePos", kScreen.x);
                }
            }
        }
    }
}
// MS2-FUNCTIONAL: by-value Ptr arguments and display handle temps differ
// @0x14127a3a0
void GFxMovieBackground::vfunc_9(MS2_GFX_PTR(Unk_GFxHandleObj) spObj, MS2_GFX_PTR(Unk_GFxHandleObj) spHandle)
{
    if (m_spRenderTarget == 0)
        return;
    Unk_BgComPtr<Unk_BgTarget> spTarget(spObj->vfunc_14());
    if (spTarget != 0)
    {
        spObj->vfunc_17(m_spRenderTarget, 1);
        Unk_BgDispHandle kHandle(reinterpret_cast<const Unk_BgDispHandle&>(m_60->GetDisplayHandle()));
        if (kHandle.FUN_1425805a0(spHandle->FUN_142582270()))
            spHandle->Assign(kHandle);
        spObj->vfunc_17(spTarget, 1);
    }
}
// MS2-FUNCTIONAL: smart-pointer release sequence differs
// @0x14127a580
void GFxMovieBackground::vfunc_11()
{
    m_spViewport = 0;
    m_spScript = 0;
    if (m_spRenderView != 0)
    {
        FUN_14127b290();
        m_spRenderView = 0;
    }
    if (m_spRenderTarget != 0)
    {
        m_spRenderTarget->vfunc_2();
        m_spRenderTarget = 0;
    }
    if (m_pOverlay != 0)
    {
        m_pOverlay->vfunc_2();
        m_pOverlay = 0;
    }
    if (m_spRenderTexture != 0)
        m_spRenderTexture = 0;
    GFxMovieEventHandler::vfunc_11();
}
// MS2-FUNCTIONAL: smart-pointer release sequence differs
// @0x14127a6c0
void GFxMovieBackground::vfunc_12()
{
    GFxMovie::vfunc_12();
    if (m_spRenderView != 0)
    {
        FUN_14127b290();
        m_spRenderView = 0;
    }
    if (m_spRenderTarget != 0)
    {
        m_spRenderTarget->vfunc_2();
        m_spRenderTarget = 0;
    }
    if (m_pOverlay != 0)
    {
        m_pOverlay->vfunc_2();
        m_pOverlay = 0;
    }
    if (m_spRenderTexture != 0)
        m_spRenderTexture = 0;
}
// @0x14127a7e0
bool GFxMovieBackground::vfunc_13()
{
    if (!GFxMovie::vfunc_13())
        return false;
    if (FUN_14127b3d0() == 0)
        return false;
    if (FUN_14127bb50() == 0)
        return false;
    if (FUN_14127b9e0() == 0)
        return false;
    if (FUN_14127b100() == 0)
        return false;
    if (FUN_14127bcb0(m_spRenderTexture) == 0)
        return false;
    vfunc_16();
    return true;
}
// MS2-FUNCTIONAL: WM_ switch branch layout differs
// @0x14127a8a0
int GFxMovieBackground::vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam)
{
    if (msg < 0x103)
    {
        if (msg == 0x102)
        {
            char aTmp[16];
            vfunc_39(0, 0, (unsigned)wParam, 1, *FUN_1422dad70(this, aTmp, 0));
            return 0;
        }
        if (msg == 5)
        {
            vfunc_16();
            return 1;
        }
        if (msg < 0x100)
            return 0;
        if (msg > 0x101)
            return 0;
    }
    else
    {
        if (msg < 0x104)
            return 0;
        if (msg > 0x105)
        {
            if (msg != 0x20a)
                return 0;
            float fX = (float)(int)(short)lParam;
            float fY = (float)(int)(short)(lParam >> 16);
            float fDelta = (float)(int)(short)(wParam >> 16);
            POINT kOrigin;
            kOrigin.x = 0;
            kOrigin.y = 0;
            ClientToScreen((HWND)hwnd, &kOrigin);
            float fDir = fDelta <= 0.0f ? -1.0f : 1.0f;
            vfunc_30(hwnd, fX - kOrigin.x, fY - kOrigin.y, (int)fDir);
            return 1;
        }
    }
    if (vfunc_38(hwnd, msg, wParam, lParam) == 0)
        return 0;
    return 1;
}
// @0x14127aaf0
MS2Ptr<AScript> GFxMovieBackground::FUN_14127aaf0() { return m_spScript; }
// @0x14127ab40
int GFxMovieBackground::FUN_14127ab40() { return m_bLoaded; }
// MS2-FUNCTIONAL: CString/ASArgList temporaries differ
// @0x14127ab60
bool GFxMovieBackground::FUN_14127ab60(CString strLabel)
{
    if (m_bLoaded == 0 || m_spScript.get() == 0)
        return false;
    m_spScript->Invoke("bgGotoAndPlay", strLabel);
    return true;
}
// MS2-FUNCTIONAL: CString/ASArgList temporaries differ
// @0x14127ac70
bool GFxMovieBackground::FUN_14127ac70(CString strLabel)
{
    if (m_bLoaded == 0 || m_spScript.get() == 0)
        return false;
    m_spScript->Invoke("bgGotoAndStop", strLabel);
    return true;
}
// MS2-FUNCTIONAL: Invoke result temp handling differs
// @0x14127ad80
bool GFxMovieBackground::FUN_14127ad80()
{
    if (m_bLoaded == 0 || m_spScript.get() == 0)
        return false;
    m_spScript->Invoke("bgPlay");
    return true;
}
// MS2-FUNCTIONAL: Invoke result temp handling differs
// @0x14127ae10
bool GFxMovieBackground::FUN_14127ae10()
{
    if (m_bLoaded == 0 || m_spScript.get() == 0)
        return false;
    m_spScript->Invoke("bgStop");
    return true;
}
// MS2-FUNCTIONAL: Invoke argument temps differ
// @0x14127aea0
void GFxMovieBackground::FUN_14127aea0(int bShow)
{
    if (m_bLoaded != 0 && m_spScript.get() != 0)
        m_spScript->Invoke("showBackgroundColor", bShow != 0);
}
// MS2-FUNCTIONAL: Invoke argument temps differ
// @0x14127af40
void GFxMovieBackground::FUN_14127af40(unsigned long nColor)
{
    if (m_bLoaded != 0 && m_spScript.get() != 0)
        m_spScript->Invoke("setBackgroundColor", nColor);
}
// @0x14127afd0
void GFxMovieBackground::vfunc_16()
{
    GFxMovieEventHandler::vfunc_16();
    if (m_spScript.get() != 0)
        m_spScript->Invoke("onResize");
}
// MS2-FUNCTIONAL: GFx event temp layout differs
// @0x14127b040
void GFxMovieBackground::vfunc_39(int a, int b, int c, bool d, bool e)
{
    if (m_60)
    {
        if (b == 0 && c != 0)
        {
            Scaleform::GFx::CharEvent kEvent(c, 0);
            m_60->HandleEvent(kEvent);
        }
        GFxMovieEventHandler::vfunc_39(a, b, c, d, e);
    }
}
// MS2-FUNCTIONAL: click list iteration temporaries differ
// @0x14127b100
int GFxMovieBackground::FUN_14127b100()
{
    if (m_spRenderView == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::AppendScene Failed m_renderView == NULL");
        return 0;
    }
    ecr::RenderService* pRender = Unk_GetRenderService(&DAT_143b059e8);
    if (pRender == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::AppendScene Failed ecr::RenderService == NULL");
        return 0;
    }
    NiRenderStep* pStep = pRender->GetActiveRenderSurface()->GetRenderStep();
    NiDefaultClickRenderStep* pClickStep = NiDynamicCast(NiDefaultClickRenderStep, pStep);
    if (pClickStep == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::AppendScene Failed NiDefaultClickRenderStep == NULL");
        return 0;
    }
    NiTPointerList<NiRenderClickPtr>& kClicks = pClickStep->GetRenderClickList();
    NiTListIterator pos = kClicks.GetHeadPos();
    NiViewRenderClick* pClick;
    do
    {
        do
        {
            if (pos == 0)
            {
                FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::AppendScene Failed SceneGraphClick No Search");
                return 0;
            }
            pClick = NiDynamicCast(NiViewRenderClick, kClicks.GetNext(pos));
        } while (pClick == 0);
    } while (!(pClick->GetName() == "SceneGraphClick"));
    pClick->PrependRenderView(m_spRenderView);
    return 1;
}
// MS2-FUNCTIONAL: click list iteration temporaries differ
// @0x14127b290
int GFxMovieBackground::FUN_14127b290()
{
    if (m_spRenderView == 0)
        return 0;
    ecr::RenderService* pRender = Unk_GetRenderService(&DAT_143b059e8);
    if (pRender == 0)
        return 0;
    NiRenderStep* pStep = pRender->GetActiveRenderSurface()->GetRenderStep();
    NiDefaultClickRenderStep* pClickStep = NiDynamicCast(NiDefaultClickRenderStep, pStep);
    if (pClickStep == 0)
        return 0;
    NiTPointerList<NiRenderClickPtr>& kClicks = pClickStep->GetRenderClickList();
    NiTListIterator pos = kClicks.GetHeadPos();
    NiViewRenderClick* pClick;
    do
    {
        do
        {
            if (pos == 0)
                return 0;
            pClick = NiDynamicCast(NiViewRenderClick, kClicks.GetNext(pos));
        } while (pClick == 0);
    } while (!(pClick->GetName() == "SceneGraphClick"));
    pClick->RemoveRenderView(m_spRenderView);
    return 1;
}
// MS2-FUNCTIONAL: property creation temporaries and smart-pointer sequences differ (1.5 KB)
// @0x14127b3d0
int GFxMovieBackground::FUN_14127b3d0()
{
    m_spRenderView = NiDynamicCast(NiScreenFillingRenderView, NiScreenFillingRenderView::Create());
    NiMeshScreenElements* pQuad = NiDynamicCast(NiMeshScreenElements, &m_spRenderView->GetScreenFillingQuad());
    if (pQuad == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderView Failed");
        return 0;
    }
    NiMaterial* pMaterial = FUN_141d284a0(&DAT_143ae52e0);
    pQuad->ApplyAndSetActiveMaterial(pMaterial, 0xffffffff);
    NiAlphaProperty* pAlpha = NiNew NiAlphaProperty;
    if (pAlpha != 0)
    {
        pAlpha->SetAlphaBlending(true);
        pAlpha->SetAlphaTesting(true);
        pQuad->AttachProperty(pAlpha);
    }
    NiMaterialPropertyPtr spMaterial = NiNew NiMaterialProperty;
    if (spMaterial != 0)
    {
        NiColor kWhite(1.0f, 1.0f, 1.0f);
        FUN_14116d500(spMaterial, kWhite);
        spMaterial->SetAlpha(1.0f);
        pQuad->AttachProperty(spMaterial);
    }
    NiVertexColorProperty* pVertexColor = NiNew NiVertexColorProperty;
    if (pVertexColor != 0)
    {
        FUN_140980f20(pVertexColor, 1);
        FUN_140980e60(pVertexColor, 0);
        pQuad->AttachProperty(pVertexColor);
    }
    NiZBufferPropertyPtr spZBuffer = NiNew NiZBufferProperty;
    if (spZBuffer != 0)
    {
        spZBuffer->SetZBufferTest(false);
        spZBuffer->SetZBufferWrite(false);
        pQuad->AttachProperty(spZBuffer);
    }
    NiFogPropertyPtr spFog = NiNew NiFogProperty;
    if (spFog != 0)
    {
        spFog->SetFog(false);
        pQuad->AttachProperty(spFog);
    }
    NiTexturingPropertyPtr spTexturing = NiNew NiTexturingProperty;
    if (spTexturing != 0)
    {
        FUN_1409807b0(spTexturing, 0);
        FUN_1409805c0(spTexturing, 0);
        FUN_1409806e0(spTexturing, 0);
        FUN_140980880(spTexturing, 0);
        pQuad->AttachProperty(spTexturing);
    }
    pQuad->Update(0.0f, true);
    pQuad->UpdateEffects();
    pQuad->UpdateProperties();
    return 1;
}
// MS2-FUNCTIONAL: COM surface temporaries differ
// @0x14127b9e0
int GFxMovieBackground::FUN_14127b9e0()
{
    if (m_spRenderTexture == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderTarget Failed m_renderTexture == NULL");
        return 0;
    }
    NiDX9TextureData* pData = (NiDX9TextureData*)m_spRenderTexture->GetRendererData();
    if (pData == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderTarget Failed renderData == NULL");
        return 0;
    }
    IDirect3DTexture9* pTexture = (IDirect3DTexture9*)pData->GetD3DTexture();
    if (pTexture == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderTarget Failed IDirect3DTexture9 == NULL");
        return 0;
    }
    IDirect3DSurface9* pSurface = 0;
    pTexture->GetSurfaceLevel(0, &pSurface);
    m_spRenderTarget = FUN_1422cf060()->vfunc_67(pSurface, 0);
    if (pSurface != 0)
        pSurface->Release();
    if (m_spRenderTarget != 0)
        return 1;
    FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderTarget Failed m_renderTarget == NULL");
    return 0;
}
// MS2-FUNCTIONAL: FormatPrefs/render texture temporaries differ
// @0x14127bb50
int GFxMovieBackground::FUN_14127bb50()
{
    ecr::RenderService* pRender = Unk_GetRenderService(&DAT_143b059e8);
    if (pRender == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderTexture Failed ecr::RenderService == NULL");
        return 0;
    }
    NiRenderTargetGroup* pGroup = pRender->GetActiveRenderSurface()->GetRenderTargetGroup();
    if (pGroup == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderTexture Failed NiRenderTargetGroup == NULL");
        return 0;
    }
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_eAlphaFmt = NiTexture::FormatPrefs::ALPHA_DEFAULT;
    m_spRenderTexture = NiRenderedTexture::Create(pGroup->GetWidth(0), pGroup->GetHeight(0), NiRenderer::GetRenderer(), kPrefs, Ni2DBuffer::MULTISAMPLE_NONE);
    if (m_spRenderTexture != 0)
        return 1;
    FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::CreateRenderTexture Failed m_renderTexture == NULL");
    return 0;
}
// MS2-FUNCTIONAL: property list iteration temporaries differ
// @0x14127bcb0
int GFxMovieBackground::FUN_14127bcb0(NiRenderedTexture* pTexture)
{
    if (m_spRenderView == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::SetBaseTexture Failed m_renderView == NULL");
        return 0;
    }
    NiMeshScreenElements* pQuad = NiDynamicCast(NiMeshScreenElements, &m_spRenderView->GetScreenFillingQuad());
    if (pQuad == 0)
    {
        FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::SetBaseTexture Failed NiMeshScreenElements == NULL");
        return 0;
    }
    NiTListIterator pos = pQuad->GetPropertyList().GetHeadPos();
    while (pos != 0)
    {
        NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pQuad->GetPropertyList().GetNext(pos));
        if (pTexturing != 0)
        {
            pTexturing->SetBaseTexture(pTexture);
            pQuad->Update(0.0f, true);
            pQuad->UpdateEffects();
            pQuad->UpdateProperties();
            return 1;
        }
    }
    FUN_140a44830()->FUN_1401ce2f0("GFxMovieBackground::SetBaseTexture Failed NiTexturingProperty No Search");
    return 0;
}
// MS2-FUNCTIONAL: CString return temporaries differ
// @0x14127be10
CString GFxMovieBackground::FUN_14127be10()
{
    if (m_strBg.Find(".png", 0) == -1 && m_strBg.Find(".dds", 0) == -1)
        return m_strBg;
    CString strPrefix("BG");
    return FUN_140cc2ad0(strPrefix, FUN_140188f50((const char*)m_strBg, 0));
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x141279a70, GFxMovieBackground, vfunc_4, 867, 0x92EB49D0);
MS2_REPLACE_METHOD(0x141279df0, GFxMovieBackground, vfunc_6, 403, 0x0B550B3D);
MS2_REPLACE_METHOD(0x141279f90, GFxMovieBackground, vfunc_7, 208, 0xB81D68B0);
// MS2-HOOK-DISABLED (fx1, 2026-10-16): this per-frame hook alone leaves the hooked client stuck at 0% on the field loading screen with the
// blank error box (found by ddmin over the HEAD DLL, field entry smoke); the divergence from the exe body is not found yet.
// MS2_REPLACE_METHOD(0x14127a070, GFxMovieBackground, vfunc_8, 801, 0x5D425703);
MS2_REPLACE_METHOD(0x14127a3a0, GFxMovieBackground, vfunc_9, 472, 0x3C2A21F4);
MS2_REPLACE_METHOD(0x14127a580, GFxMovieBackground, vfunc_11, 312, 0xAC06DE3B);
MS2_REPLACE_METHOD(0x14127a6c0, GFxMovieBackground, vfunc_12, 270, 0x426155A0);
MS2_REPLACE_METHOD(0x14127a7e0, GFxMovieBackground, vfunc_13, 171, 0x8D5B6885);
MS2_REPLACE_METHOD(0x14127a8a0, GFxMovieBackground, vfunc_14, 566, 0x3E1E7EBA);
MS2_REPLACE_METHOD(0x14127aaf0, GFxMovieBackground, FUN_14127aaf0, 67, 0xCFE02519);
MS2_REPLACE_METHOD(0x14127ab40, GFxMovieBackground, FUN_14127ab40, 17, 0xEA51A84B);
MS2_REPLACE_METHOD(0x14127ab60, GFxMovieBackground, FUN_14127ab60, 263, 0xE2541036);
MS2_REPLACE_METHOD(0x14127ac70, GFxMovieBackground, FUN_14127ac70, 263, 0xBD3016D1);
MS2_REPLACE_METHOD(0x14127ad80, GFxMovieBackground, FUN_14127ad80, 131, 0xE80F1320);
MS2_REPLACE_METHOD(0x14127ae10, GFxMovieBackground, FUN_14127ae10, 131, 0x1B9AEB70);
MS2_REPLACE_METHOD(0x14127aea0, GFxMovieBackground, FUN_14127aea0, 151, 0xDE7E9855);
MS2_REPLACE_METHOD(0x14127af40, GFxMovieBackground, FUN_14127af40, 131, 0x58558EDF);
MS2_REPLACE_METHOD(0x14127afd0, GFxMovieBackground, vfunc_16, 97, 0xEC527B97);
MS2_REPLACE_METHOD(0x14127b040, GFxMovieBackground, vfunc_39, 177, 0xEF74DFFF);
MS2_REPLACE_METHOD(0x14127b100, GFxMovieBackground, FUN_14127b100, 386, 0x54963695);
MS2_REPLACE_METHOD(0x14127b290, GFxMovieBackground, FUN_14127b290, 306, 0x7DBF2654);
MS2_REPLACE_METHOD(0x14127b3d0, GFxMovieBackground, FUN_14127b3d0, 1535, 0xFDE6D0CF);
MS2_REPLACE_METHOD(0x14127b9e0, GFxMovieBackground, FUN_14127b9e0, 349, 0xC4EC9E42);
MS2_REPLACE_METHOD(0x14127bb50, GFxMovieBackground, FUN_14127bb50, 330, 0x31F3B57A);
MS2_REPLACE_METHOD(0x14127bcb0, GFxMovieBackground, FUN_14127bcb0, 336, 0x893CF012);
MS2_REPLACE_METHOD(0x14127be10, GFxMovieBackground, FUN_14127be10, 360, 0xFCB863E7);
