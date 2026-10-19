// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMinimapEditDialog: see uiminimapeditdialog.h. w422.
// MS2-UNIT: unit_141a51ec0
// MS2-RANGE: 0x141a51ec0-0x141a55270 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiminimapeditdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiminimapeditdialog.h"
#include <time.h>
#include <d3dx9.h>
#include <NiRect.h>
#include <NiRenderTargetGroup.h>
#include <egf/Entity.h>
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/hardwareinstancingservice.h"
#include "ms2/placeholder/applyeffect.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer {};

class Unk_MeSlider : public ASDisplayObject                         // a slider child
{
public:
    void FUN_1422ce750(float fMin);                                 // minimum
    void FUN_1422ce6a0(float fMax);                                 // maximum
    void FUN_1422ce5f0(float fValue);                               // value
    void FUN_1422c1fe0(int bEnabled);
};
class Unk_MeTextField                                               // the text of a label / input
{
public:
    void FUN_1422e4a00(const CString& strText);                     // label: set the text
    void FUN_1422e0a60(const CString& strText);                     // input: set the text
};
class Unk_MeLabel : public ASDisplayObject
{
public:
    Unk_MeTextField* FUN_140c461f0();                               // the text field
};
class Unk_MeInput : public ASDisplayObject
{
public:
    Unk_MeTextField* FUN_140bc0550();                               // the text field
};

class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char* pszName); };   // FirstChildElement
struct Unk_MeXmlElement { void* m_raw[0x90 / 8]; };                 // TiXmlElement (0x90)
struct Unk_MeXmlDecl { void* m_raw[0x70 / 8]; };                    // TiXmlDeclaration (0x70)
struct Unk_MeXmlComment { void* m_raw[0x50 / 8]; };                 // TiXmlComment (0x50)
void* FUN_14086f2f0(void* pElem, const char* pszName);              // TiXmlElement::TiXmlElement
void FUN_14086f450(void* pElem);                                    // TiXmlElement::~TiXmlElement
void* FUN_1408704d0(void* pDecl, const char* pszVersion, const char* pszEncoding, const char* pszStandalone);   // TiXmlDeclaration::TiXmlDeclaration
void FUN_14081ad20(void* pDecl);                                    // TiXmlDeclaration::~TiXmlDeclaration
void* FUN_1408700b0(void* pComment, const char* pszText);           // TiXmlComment::TiXmlComment
void FUN_1408724d0(void* pComment);                                 // TiXmlComment::~TiXmlComment
void* FUN_14086e000(void* pParent, void* pChild);                   // InsertEndChild
void* FUN_14086e090(void* pParent, void* pChild);                   // LinkEndChild
bool FUN_140870f90(TiXmlDocument* pDoc);                            // SaveFile
void FUN_140874e00(Unk_140165cf0* pElem, const char* pszName, Unk_Frustum* pOut);                          // read a frustum node
void FUN_140874f20(Unk_140165cf0* pElem, const char* pszName, Unk_Rect4* pOut);                            // read a rectangle node
void FUN_140874280(Unk_140165cf0* pElem, const char* pszNode, const char* pszAttr, CString* pOut);         // read a string attribute
void FUN_140874d90(Unk_140165cf0* pElem, const char* pszNode, const char* pszAttr, Unk_GVec3* pOut);       // read a vector attribute
void FUN_140874210(Unk_140165cf0* pElem, const char* pszNode, const char* pszAttr, float* pOut);           // read a float attribute
void FUN_140875180(Unk_140165cf0* pElem, const char* pszName, const Unk_Frustum* pIn, int bCreate);        // write a frustum node
void FUN_1408752d0(Unk_140165cf0* pElem, const char* pszName, const Unk_Rect4* pIn, int bCreate);          // write a rectangle node
void FUN_140874520(Unk_140165cf0* pElem, const char* pszNode, const char* pszAttr, const CString* pIn, int bCreate);   // write a string attribute
void FUN_140875110(Unk_140165cf0* pElem, const char* pszNode, const char* pszAttr, const Unk_GVec3* pIn, int bCreate);   // write a vector attribute
void FUN_1408744b0(Unk_140165cf0* pElem, const char* pszNode, const char* pszAttr, float fValue, int bCreate);   // write a float attribute
CString FUN_14016a5c0(const char* pszPath, int nFlags);             // path conversion
CString FUN_1409a2360(const char* psz, int n);                      // text conversion
CString FUN_140536a50(const char* pszFormat, const CString& strArg);   // StringFormat with one text argument
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);
CStringW FUN_1401d0080(const CStringW& strA, const CStringW& strB);   // concatenation
CStringA FUN_14016a600(const wchar_t* psz, int nCodePage);          // wide -> narrow
void FUN_140d73aa0(CStringW strText, int nType, void* pOwner, CStringW strTag);   // show a message box

// the map xml name of the current map (a CPtred with the xblock name at +0x30)
class Unk_MeMapInfo : public CPtred
{
public:
    char m_pad_18[0x30 - 0x18];
    CString m_strXBlock;                                            // +0x30
};

// the world manager singleton
class Unk_MeWorld
{
public:
    MS2Ptr<Unk_MeMapInfo> FUN_141bd30a0();                          // the current map info
    int FUN_141bd3060();                                            // current map id
    GameObject* FUN_141bd0fa0(egf::EntityID id);                    // the game object of an entity
    void FUN_141bd2db0(ATL::CAtlList<efd::SmartPointer<GameObject> >* pOut, int (*pfnFilter)(GameObject*));   // collect the game objects
    void FUN_141bd3cb0(bool b);                                     // m_914 = b
    void FUN_141bd3cf0(bool b);                                     // m_915 = b
};
Unk_MeWorld* FUN_1403ed2d0();
class Unk_MeUIMgr
{
public:
    void FUN_141ad9650();                                           // dialogs on
    void FUN_141ad9b30();                                           // dialogs off
};
Unk_MeUIMgr* FUN_1403ed2b0();

struct Unk_MeColor { float r, g, b, a; };                           // the clear colour (16 bytes)
class Unk_MeApp { public: void FUN_141489ff0(Unk_MeColor kColor); };
Unk_MeApp* FUN_140aae430();
Unk_MeColor FUN_14097f1d0(float r, float g, float b, float a);
Unk_MeColor FUN_140987930(const Unk_MeColor* pSrc);
extern Unk_MeColor DAT_143a09680;

ApplyEffect* FUN_1409a8b00();                                       // the ApplyEffect singleton

// camera manager members (exe functions of other objs)
float FUN_1409f2430(CameraMgr* pCamera);                            // the distance of the current mode
float FUN_141032e60(CameraMgr* pCamera);                            // the vertical angle of the current mode
void FUN_141032ed0(CameraMgr* pCamera, float f);
void FUN_141032f30(CameraMgr* pCamera, float f);
void FUN_140b6bd30(CameraMgr* pCamera);                             // apply the current mode setting
void FUN_1418df360(CameraMgr* pCamera, Unk_StreamPoint ptPos);      // set the camera position

// entity iteration, properties and the instancing service
struct Unk_MeEntIter { void* m_a; void* m_b; };
class Unk_MeEntMgr;
Unk_MeEntMgr* FUN_1409670f0();
void FUN_1411ce4c0(Unk_MeEntMgr* pMgr, Unk_MeEntIter* pIter);
bool FUN_1411ce510(Unk_MeEntMgr* pMgr, Unk_MeEntIter* pIter, egf::Entity** ppOut);
egf::Entity* FUN_1411cf440(Unk_MeEntMgr* pMgr, const egf::EntityID& id);
int FUN_1408a20a0(egf::Entity* pEntity, unsigned int nHash, bool* pbOut);   // read a bool property
void FUN_14098c6e0(egf::Entity* pEntity, unsigned int nHash, bool* pbValue);   // write a bool property
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);
extern char DAT_143b059e8;                                          // the application framework
HardwareInstancingService* FUN_14098c5b0(char* pFramework);

// the render surface -> camera -> frustum
class Unk_MeFrustumCamera { public: Unk_Frustum* FUN_1409a8de0(); };
class Unk_MeSurface;
class Unk_MeRenderSvc { public: Unk_MeSurface* FUN_140af7da0(); };
class Unk_MeCameraSvc;
Unk_MeRenderSvc* FUN_1413f9890();
Unk_MeCameraSvc* FUN_1413f9910();
Unk_MeSurface* FUN_140af7da0(Unk_MeRenderSvc* pSvc);
void* FUN_14200aae0(Unk_MeCameraSvc* pSvc, Unk_MeSurface* pSurface);
Unk_MeFrustumCamera* FUN_142008b80(void* pCamera);
extern unsigned int DAT_143af62d4;                                         // the screen width
extern unsigned int DAT_143af62d8;                                         // the screen height

// screenshot helpers (?\textureutil.cpp)
void* FUN_14127bf80(char* pFramework);
void* FUN_140af7da0(void* pRegistry);
NiRenderTargetGroup* FUN_14127cca0(void* pScene);
int EnsureScreenshotDirectory(ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t, ATL::ChTraitsCRT<wchar_t> > >* pkDirectory);
int SaveRenderTargetToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiRenderTargetGroup* pkGroup,
    NiRect<unsigned int> kRect);
int SaveDefaultTargetToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nUnused,
    NiRect<unsigned int> kRect, float fScale);

float FUN_14028aed0(float f);                                        // round
void FUN_1422c0e80(ASMovieClip* pClip, float fWidth);               // set the width
void FUN_1422c0f20(ASMovieClip* pClip, float fHeight);              // set the height

// the CRT time wrappers
// @0x141a51ec0
struct tm* FUN_141a51ec0(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// @0x141a51ee0
__time64_t FUN_141a51ee0(__time64_t* pTime)
{
    return _time64(pTime);
}

// the camera mode inline members used by this dialog
// @0x141a551a0
void FUN_141a551a0(CameraMgr* pCamera, bool b)
{
    if (pCamera->FUN_140af2520())
        pCamera->FUN_140af2520()->vfunc_5(b);
}

// @0x141a55200
void FUN_141a55200(CameraMgr* pCamera, Unk_StreamPoint pt)
{
    if (pCamera->FUN_140af2520())
        pCamera->FUN_140af2520()->vfunc_4(pt);
}

// ---- UIMinimapEditDialog ----

// @0x141a51f00
UIMinimapEditDialog::UIMinimapEditDialog()
    : m_hidden(10), m_instanced(10)
{
    m_40 = 1;
    m_spMinimap.AssignRaw(new CMinimap());
}

// @0x141a54c20
UIMinimapEditDialog::~UIMinimapEditDialog()
{
}

// @0x141a52020
CString UIMinimapEditDialog::vfunc_1()
{
    return CString("MinimapEditDialog");
}

// @0x141a52070
int UIMinimapEditDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    if (CameraMgr::GetInstance()->FUN_140a18070() == 0)
        return 0;
    FUN_140aae430()->FUN_141489ff0(FUN_14097f1d0(0, 0, 0, 0));
    FUN_141a540f0(1);
    FUN_1409a8b00()->SetSoftParticlesOption(true, 0);
    FUN_1409a8b00()->ApplyFieldFogRange(false);
    CameraMgr::GetInstance()->FUN_140aed750(6, 1);
    FUN_141a551a0(CameraMgr::GetInstance(), true);
    FUN_1403ed2d0()->FUN_141bd3cb0(true);
    m_strImageName.Empty();
    m_strImageIcon.Empty();
    return 1;
}

// @0x141a52190
void UIMinimapEditDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140aae430()->FUN_141489ff0(FUN_140987930(&DAT_143a09680));
    FUN_141a540f0(0);
    FUN_1409a8b00()->ApplySoftParticleOption();
    FUN_1409a8b00()->ApplyFieldFog();
    CameraMgr::GetInstance()->FUN_140aec8a0(false);
    FUN_141a551a0(CameraMgr::GetInstance(), false);
    CameraMgr::GetInstance()->FUN_140aed750(2, 1);
    FUN_140b6bd30(CameraMgr::GetInstance());
    FUN_1403ed2d0()->FUN_141bd3cb0(false);
    m_strImageName.Empty();
    m_strImageIcon.Empty();
}

// @0x141a522a0
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
void UIMinimapEditDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141a53100();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != NULL)
        pDialog->FUN_1422c00f0(0, 0);

    MS2Ptr<Unk_MeSlider> spFov = FUN_140faff90("m_sliderFov");
    if (spFov.get())
    {
        spFov->FUN_1422ce750(0);
        spFov->FUN_1422ce6a0(90.0f);
        spFov->FUN_1422ce5f0(CameraMgr::GetInstance()->FUN_140ad4b40());
        spFov->FUN_1422c1fe0(0);
    }
    MS2Ptr<Unk_MeSlider> spDistance = FUN_140faff90("m_sliderDistance");
    if (spDistance.get())
    {
        spDistance->FUN_1422ce750(10.0f);
        spDistance->FUN_1422ce6a0(20000.0f);
        spDistance->FUN_1422ce5f0(FUN_1409f2430(CameraMgr::GetInstance()));
        spDistance->FUN_1422c1fe0(0);
    }
    MS2Ptr<Unk_MeSlider> spVAngle = FUN_140faff90("m_sliderVAngle");
    if (spVAngle.get())
    {
        spVAngle->FUN_1422ce750(0);
        spVAngle->FUN_1422ce6a0(90.0f);
        spVAngle->FUN_1422ce5f0(FUN_141032e60(CameraMgr::GetInstance()));
        spVAngle->FUN_1422c1fe0(0);
    }

    MS2Ptr<Unk_MeLabel> spLabelFov = FUN_140e6d820("m_labelFov");
    if (spLabelFov.get())
    {
        CString strText;
        strText.Format("Camera Fov [%f]", (double)CameraMgr::GetInstance()->FUN_140ad4b40());
        spLabelFov->FUN_140c461f0()->FUN_1422e4a00(strText);
    }
    MS2Ptr<Unk_MeLabel> spLabelDistance = FUN_140e6d820("m_labelDistance");
    if (spLabelDistance.get())
    {
        CString strText;
        strText.Format("Camera Distance [%f]", (double)FUN_1409f2430(CameraMgr::GetInstance()));
        spLabelDistance->FUN_140c461f0()->FUN_1422e4a00(strText);
    }
    MS2Ptr<Unk_MeLabel> spLabelVAngle = FUN_140e6d820("m_labelVAngle");
    if (spLabelVAngle.get())
    {
        CString strText;
        strText.Format("Camera VAngle [%f]", (double)FUN_141032e60(CameraMgr::GetInstance()));
        spLabelVAngle->FUN_140c461f0()->FUN_1422e4a00(strText);
    }

    MS2Ptr<Unk_MeInput> spEmblem = FUN_140e35bd0("m_emblem");
    if (spEmblem.get())
        spEmblem->FUN_140bc0550()->FUN_1422e0a60(m_strImageIcon);
    MS2Ptr<Unk_MeInput> spFileName = FUN_140e35bd0("m_fileName");
    if (spFileName.get())
    {
        if (m_strImageName.GetLength() < 1)
            m_strImageName = FUN_141a549c0();
        spFileName->FUN_140bc0550()->FUN_1422e0a60(m_strImageName);
    }

    MS2Ptr<ASMovieClip> spArea = FUN_140ba7930("m_rectarea");
    if (spArea.get())
    {
        float fLeft = m_spMinimap->m_rcImage.l >= 0.0f ? m_spMinimap->m_rcImage.l : 0.0f;
        float fTop = m_spMinimap->m_rcImage.t >= 0.0f ? m_spMinimap->m_rcImage.t : 0.0f;
        float fWidth = m_spMinimap->m_rcImage.r - m_spMinimap->m_rcImage.l;
        float fHeight = m_spMinimap->m_rcImage.b - m_spMinimap->m_rcImage.t;
        spArea->FUN_1422c00f0(fLeft, fTop);
        FUN_1422c0e80(spArea.get(), fWidth);
        FUN_1422c0f20(spArea.get(), fHeight);
    }
    if (m_30.get())
        m_30->Invoke("OnSetting");
}

// @0x141a52d60
int UIMinimapEditDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnApplyCameraData", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_strImageIcon = data.FUN_1422b8d30();
            m_strImageName = data.FUN_1422b8d30();
        }
        FUN_141a53750();
    }
    else if (_stricmp("OnFov", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
        {
            CameraMgr::GetInstance()->FUN_140ad4ff0(data.FUN_1422b8c10());
            FUN_140b6bd30(CameraMgr::GetInstance());
        }
    }
    else if (_stricmp("OnDistance", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
        {
            float fDistance = data.FUN_1422b8c10();
            FUN_141032ed0(CameraMgr::GetInstance(), fDistance);
            FUN_141032f30(CameraMgr::GetInstance(), fDistance);
            CameraMgr::GetInstance()->FUN_140af9b40(fDistance);
            FUN_140b6bd30(CameraMgr::GetInstance());
        }
    }
    else if (_stricmp("OnVAngle", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
        {
            CameraMgr::GetInstance()->FUN_140af98d0(data.FUN_1422b8c10());
            FUN_140b6bd30(CameraMgr::GetInstance());
        }
    }
    else if (_stricmp("OnRotation", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
            FUN_1403ed2d0()->FUN_141bd3cf0(data.FUN_1422b8a90());
    }
    else if (_stricmp("OnScreenShot", szMethod) == 0)
    {
        FUN_141a545a0();
    }
    return 0;
}

// @0x141a53100
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
void UIMinimapEditDialog::FUN_141a53100()
{
    MS2Ptr<Unk_MeMapInfo> spMap = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spMap.IsNull())
        return;
    TiXmlDocument doc;
    if (!doc.FUN_140870fc0((const char*)FUN_14016a5c0((const char*)FUN_141a54940(CString(spMap->m_strXBlock)), 0), 0))
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == NULL)
        return;
    Unk_140165cf0* pMinimap = pRoot->FUN_140165cf0("minimap");
    if (pMinimap == NULL)
    {
        m_strImageName = "";
        return;
    }
    FUN_140874e00(pRoot->FUN_140165cf0("minimap"), "frustum", &m_spMinimap->m_frustum);
    FUN_140874f20(pRoot->FUN_140165cf0("minimap"), "screen", &m_spMinimap->m_rcScreen);
    FUN_140874f20(pRoot->FUN_140165cf0("minimap"), "image", &m_spMinimap->m_rcImage);
    FUN_140874280(pRoot->FUN_140165cf0("minimap"), "image", "name", &m_spMinimap->m_strImageName);
    m_strImageName = m_spMinimap->m_strImageName;
    FUN_140874280(pRoot->FUN_140165cf0("minimap"), "image", "icon", &m_strImageIcon);
    FUN_140874d90(pRoot->FUN_140165cf0("minimap"), "camera", "position", &m_spMinimap->m_vecCamPos);
    FUN_140874d90(pRoot->FUN_140165cf0("minimap"), "camera", "rotation", &m_spMinimap->m_vecCamRot);
    FUN_140874210(pRoot->FUN_140165cf0("minimap"), "edit", "zoomfactor", &m_spMinimap->m_fZoomFactor);
    m_spMinimap->m_rcImage.r = m_spMinimap->m_rcImage.l + 1024.0f;
    m_spMinimap->m_rcImage.b = m_spMinimap->m_rcImage.t + 1024.0f;
    FUN_1418df360(CameraMgr::GetInstance(), Unk_StreamPoint(m_spMinimap->m_vecCamPos.x, m_spMinimap->m_vecCamPos.y, m_spMinimap->m_vecCamPos.z));
    FUN_141a55200(CameraMgr::GetInstance(), Unk_StreamPoint(m_spMinimap->m_vecCamRot.x, m_spMinimap->m_vecCamRot.y, m_spMinimap->m_vecCamRot.z));
    float fZoom = m_spMinimap->m_fZoomFactor >= 1.0f ? m_spMinimap->m_fZoomFactor : 1.0f;
    CameraMgr::GetInstance()->FUN_140af0170(fZoom, false);
    FUN_140b6bd30(CameraMgr::GetInstance());
}

// @0x141a53750
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
void UIMinimapEditDialog::FUN_141a53750()
{
    MS2Ptr<Unk_MeMapInfo> spMap = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spMap.IsNull())
        return;
    MS2Ptr<ASMovieClip> spArea = FUN_140ba7930("m_rectarea");
    if (spArea.get())
    {
        Unk_MeSurface* pSurface = FUN_140af7da0(FUN_1413f9890());
        if (pSurface != NULL)
        {
            void* pCamera = FUN_14200aae0(FUN_1413f9910(), pSurface);
            if (pCamera != NULL && CameraMgr::GetInstance()->FUN_140a18070() != 0)
            {
                Unk_StreamPoint ptPos = CameraMgr::GetInstance()->FUN_140a17e10();
                m_spMinimap->m_vecCamPos = Unk_GVec3(ptPos.x, ptPos.y, ptPos.z);
                Unk_StreamPoint ptRot = CameraMgr::GetInstance()->FUN_140af8290();
                m_spMinimap->m_vecCamRot = Unk_GVec3(ptRot.x, ptRot.y, ptRot.z);
                m_spMinimap->m_frustum = *FUN_142008b80(pCamera)->FUN_1409a8de0();
                m_spMinimap->m_fZoomFactor = CameraMgr::GetInstance()->FUN_140af0140();
                m_spMinimap->m_strImageName = m_strImageName;
                m_spMinimap->m_rcScreen = Unk_Rect4(0, (float)DAT_143af62d4, 0, (float)DAT_143af62d8);
                m_spMinimap->m_rcImage.l = spArea->FUN_1422c10a0();
                m_spMinimap->m_rcImage.r = m_spMinimap->m_rcImage.l + (float)spArea->FUN_1422c1340();
                m_spMinimap->m_rcImage.t = spArea->FUN_1422c1110();
                m_spMinimap->m_rcImage.b = m_spMinimap->m_rcImage.t + (float)spArea->FUN_1422c13b0();
            }
        }
    }
    spArea = 0;
    if (spMap->m_strXBlock.IsEmpty())
        return;
    TiXmlDocument doc;
    if (!doc.FUN_140870fc0((const char*)FUN_14016a5c0((const char*)FUN_141a54940(CString(spMap->m_strXBlock)), 0), 0))
    {
        Unk_MeXmlDecl decl;
        FUN_1408704d0(&decl, "1.0", "utf-8", "");
        FUN_14086e000(&doc, &decl);
        {
            Unk_MeXmlComment comment;
            FUN_1408700b0(&comment, FUN_1409a2360(" \xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad \xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2 \xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf \xc1\xf7\xc1\xa2 \xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6 \xb8\xb6\xbc\xbc\xbf\xe4 ", 0));
            FUN_14086e000(&doc, &comment);
            FUN_1408724d0(&comment);
        }
        Unk_MeXmlElement root;
        FUN_14086f2f0(&root, "ms2");
        FUN_14086e000(&doc, &root);
        FUN_14086f450(&root);
        FUN_14081ad20(&decl);
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot != NULL)
    {
        if (pRoot->FUN_140165cf0("minimap") == NULL)
        {
            void* pNew = ::operator new(0x90);
            if (pNew != NULL)
                FUN_14086f2f0(pNew, "minimap");
            FUN_14086e090(pRoot, pNew);
        }
        Unk_140165cf0* pMinimap = pRoot->FUN_140165cf0("minimap");
        FUN_140875180(pMinimap, "frustum", &m_spMinimap->m_frustum, 1);
        FUN_1408752d0(pMinimap, "screen", &m_spMinimap->m_rcScreen, 1);
        FUN_1408752d0(pMinimap, "image", &m_spMinimap->m_rcImage, 1);
        FUN_140874520(pMinimap, "image", "name", &m_strImageName, 1);
        FUN_140874520(pMinimap, "image", "icon", &m_strImageIcon, 1);
        FUN_140875110(pMinimap, "camera", "position", &m_spMinimap->m_vecCamPos, 1);
        FUN_140875110(pMinimap, "camera", "rotation", &m_spMinimap->m_vecCamRot, 1);
        FUN_1408744b0(pMinimap, "edit", "zoomfactor", m_spMinimap->m_fZoomFactor, 1);
        FUN_140870f90(&doc);
    }
    SaveDefaultTargetToFileA(&m_strImageName, D3DXIFF_DDS, 1, FUN_141a54a50(), 0.5f);
}

// @0x141a540f0
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
void UIMinimapEditDialog::FUN_141a540f0(int bShow)
{
    efd::SmartPointer<HardwareInstancingService> spInstancing(FUN_14098c5b0(&DAT_143b059e8));
    if (bShow == 0)
    {
        if (spInstancing != NULL)
        {
            for (POSITION pos = m_instanced.GetHeadPosition(); pos != NULL; m_instanced.GetNext(pos))
                spInstancing->FUN_1413d6fc0(m_instanced.GetAt(pos));
        }
    }
    else
    {
        m_hidden.RemoveAll();
        m_instanced.RemoveAll();
        ATL::CAtlList<efd::SmartPointer<GameObject> > objects(10);
        FUN_1403ed2d0()->FUN_141bd2db0(&objects, 0);
        for (POSITION pos = objects.GetHeadPosition(); pos != NULL; objects.GetNext(pos))
        {
            efd::SmartPointer<GameObject> spObject = objects.GetAt(pos);
            if (spObject != NULL && spObject->FUN_14123c660() == 0)
                m_hidden.AddTail(spObject->FUN_14123c460());
        }
        egf::Entity* pEntity = NULL;
        Unk_MeEntIter iter;
        FUN_1411ce4c0(FUN_1409670f0(), &iter);
        while (FUN_1411ce510(FUN_1409670f0(), &iter, &pEntity))
        {
            bool bInstanced = false;
            bool bVisible = false;
            if (spInstancing != NULL)
                FUN_1408a20a0(pEntity, 0x23f9860e, &bInstanced);
            if (bInstanced || (FUN_1408a20a0(pEntity, 0xa0b6b179, &bVisible), bVisible))
            {
                bool bFlag = false;
                if (FUN_1408a20a0(pEntity, 0x4cc1298e, &bFlag) == 0 && bFlag)
                {
                    if (bInstanced)
                    {
                        m_instanced.AddTail(pEntity);
                        spInstancing->FUN_1413d6f40(pEntity);
                    }
                    bool bHide = false;
                    FUN_14098c6e0(pEntity, 0xa0b6b179, &bHide);
                    m_hidden.AddTail(*FUN_1408b76f0(pEntity));
                }
            }
        }
    }
    for (POSITION pos = m_hidden.GetHeadPosition(); pos != NULL; m_hidden.GetNext(pos))
    {
        egf::EntityID id = m_hidden.GetAt(pos);
        GameObject* pObject = FUN_1403ed2d0()->FUN_141bd0fa0(id);
        if (pObject != NULL)
            pObject->vfunc_23(bShow);
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_hidden.GetAt(pos));
        if (pEntity != NULL)
        {
            bool bVisible = (bShow == 0);
            FUN_14098c6e0(pEntity, 0xa0b6b179, &bVisible);
        }
    }
    if (bShow == 0)
        FUN_1403ed2b0()->FUN_141ad9650();
    else
        FUN_1403ed2b0()->FUN_141ad9b30();
}

// @0x141a545a0
// MS2-FUNCTIONAL: temporaries/frame layout differ from the exe
void UIMinimapEditDialog::FUN_141a545a0()
{
    MS2Ptr<ASMovieClip> spArea = FUN_140ba7930("m_rectarea");
    if (spArea.get() == NULL)
        return;
    NiRect<unsigned int> kRect(0, 0, 0, 0);
    kRect.m_left = (int)(__int64)spArea->FUN_1422c10a0();
    kRect.m_right = kRect.m_left + spArea->FUN_1422c1340();
    kRect.m_top = (int)(__int64)spArea->FUN_1422c1110();
    kRect.m_bottom = kRect.m_top + spArea->FUN_1422c13b0();
    CStringW strDirectory;
    if (EnsureScreenshotDirectory(&strDirectory) < 0)
    {
        FUN_140d73aa0(CStringW(FUN_1401e8510(L"Could not create directory. path={0}", strDirectory)), 0, 0, CStringW(L""));
        return;
    }
    __time64_t tNow = FUN_141a51ee0(0);
    const struct tm* pTm = FUN_141a51ec0(&tNow);
    CStringW strName;
    strName.Format(L"\\%d%02d%02d_%02d%02d%02d.png", pTm->tm_year + 1900, pTm->tm_mon + 1, pTm->tm_mday, pTm->tm_hour, pTm->tm_min, pTm->tm_sec);
    CStringW strPath = FUN_1401d0080(strDirectory, strName);
    void* pRegistry = FUN_14127bf80(&DAT_143b059e8);
    if (pRegistry != NULL)
    {
        NiRenderTargetGroup* pGroup = FUN_14127cca0(FUN_140af7da0(pRegistry));
        if (pGroup != NULL)
        {
            CStringA strPathA = FUN_14016a600((const wchar_t*)strPath, 0);
            SaveRenderTargetToFileA(&strPathA, D3DXIFF_PNG, pGroup, kRect);
        }
    }
}

// @0x141a54940
CString UIMinimapEditDialog::FUN_141a54940(CString strXBlock)
{
    return FUN_140536a50("./data/xml/MapXblock/{0}.xml", strXBlock);
}

// @0x141a549c0
CString UIMinimapEditDialog::FUN_141a549c0()
{
    CString strPath;
    strPath.Format("./Data/Resource/Image/Map/Minimap/%08d.dds", FUN_1403ed2d0()->FUN_141bd3060());
    return strPath;
}

// @0x141a54a50
NiRect<unsigned int> UIMinimapEditDialog::FUN_141a54a50()
{
    NiRect<unsigned int> kRect(0, 0, 0, 0);
    kRect.m_left = (int)(__int64)FUN_14028aed0(m_spMinimap->m_rcImage.l);
    kRect.m_right = (int)(__int64)FUN_14028aed0(m_spMinimap->m_rcImage.r);
    kRect.m_top = (int)(__int64)FUN_14028aed0(m_spMinimap->m_rcImage.t);
    kRect.m_bottom = (int)(__int64)FUN_14028aed0(m_spMinimap->m_rcImage.b);
    return kRect;
}
