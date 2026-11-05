// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMinimapEditDialog: see uiminimapeditdialog.h. w422.
// MS2-UNIT: unit_141a51ec0
// MS2-RANGE: 0x141a51ec0-0x141a55270 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiminimapeditdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/ms2.h"   // C3: MS2::SetBackgroundColor
#include "uiminimapeditdialog.h"
#include <time.h>
#include <d3dx9.h>
#include <NiColor.h>
#include <NiRect.h>
#include <efd/Helpers.h>
#include <NiRenderTargetGroup.h>
#include <egf/Entity.h>
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include <ecr/RenderSurface.h>
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/hardwareinstancingservice.h"
#include "ms2/placeholder/applyeffect.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/aslabel.h"
#include "ms2/placeholder/asslider.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObjectContainer {};

class Unk_XmlNode { public: Unk_XmlNode* FirstChild(const char* pszName); };   // FirstChildElement, a separate copy from TiXmlNode::FirstChild

// TinyXML nodes (the game's tinyxml.h can't sit next to the TiXmlDocument placeholder of uidialog.h)
class TiXmlNode
{
public:
    virtual ~TiXmlNode();
    TiXmlNode* InsertEndChild(const TiXmlNode& node);
    TiXmlNode* LinkEndChild(TiXmlNode* pNode);
};
class TiXmlElement : public TiXmlNode
{
public:
    TiXmlElement(const char* pszName);
    virtual ~TiXmlElement();
private:
    void* m_raw[(0x90 - 8) / 8];
};
class TiXmlDeclaration : public TiXmlNode
{
public:
    TiXmlDeclaration(const char* pszVersion, const char* pszEncoding, const char* pszStandalone);
    virtual ~TiXmlDeclaration();
private:
    void* m_raw[(0x70 - 8) / 8];
};
class TiXmlComment : public TiXmlNode
{
public:
    TiXmlComment(const char* pszText);
    virtual ~TiXmlComment();
private:
    void* m_raw[(0x50 - 8) / 8];
};

int XmlGetChild(class TiXmlElement*, char const*, class NiFrustum&);   // C3: was FUN_140874e00
int XmlGetChild(class TiXmlElement*, char const*, NiRect<float>&);
int XmlGetChildAttr(class TiXmlElement*, char const*, char const*, CString&);
int XmlGetChildAttr(class TiXmlElement*, char const*, char const*, class NiPoint3&);   // C3: was FUN_140874d90
int XmlGetChildAttr(class TiXmlElement*, char const*, char const*, float&);   // C3: was FUN_140874210
void XmlSetChild(class TiXmlElement*, char const*, class NiFrustum const&, bool);   // C3: was FUN_140875180
void XmlSetChild(class TiXmlElement*, char const*, NiRect<float> const&, bool);
void XmlSetChildAttr(class TiXmlElement*, char const*, char const*, CString const&, bool);
void XmlSetChildAttr(class TiXmlElement*, char const*, char const*, efd::Point3 const&, bool);
void XmlSetChildAttr(class TiXmlElement*, char const*, char const*, float, bool);   // C3: was FUN_1408744b0
CString FUN_14016a5c0(const char* pszPath, int nFlags);             // path conversion
CString FUN_1409a2360(const char* psz, int n);                      // text conversion
CStringA FUN_14016a600(const wchar_t* psz, int nCodePage);          // wide -> narrow
void FUN_140d73aa0(CStringW strText, int nType, void* pOwner, CStringW strTag);   // show a message box

void* FUN_140aae430();   // C3: was FUN_140aae430

// camera manager members (exe functions of other objs)
float FUN_1409f2430(class CameraMgr*);   // C3: was FUN_1409f2430
void FUN_140ad4ff0(class CameraMgr*, float);
float FUN_141032e60(void*);   // C3: was FUN_141032e60
void FUN_141032ed0(void*, float);   // C3: was FUN_141032ed0
void FUN_141032f30(void*, float);   // C3: was FUN_141032f30
void FUN_140b6bd30(void*);   // C3: was FUN_140b6bd30
void CameraMgrMoveTo(CameraMgr* pCamera, Vector3 ptPos);    // set the camera position

// entity iteration, properties and the instancing service
void FUN_14098c6e0(class Unk_CachedEntity* pEntity, unsigned int nHash, const bool& bValue);   // write a bool property
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(char*)&egf::g_bapiContext)          // C3: was extern char DAT_143b059e8
class Unk_HwService* FUN_14098c5b0(struct Unk_EntityAppFramework*);   // C3: was FUN_14098c5b0

// the render surface -> camera -> frustum
namespace ecr
{
class CameraData { public: NiCamera* GetCamera() const; };
class CameraService { public: CameraData* GetActiveCamera(RenderSurface* pSurface); };
}
ecr::RenderService* FUN_1413f9890();
ecr::CameraService* FUN_1413f9910();
extern unsigned int DAT_143af62d4;                                         // the screen width
extern unsigned int DAT_143af62d8;                                         // the screen height

// screenshot helpers (?\textureutil.cpp)
ecr::RenderService* Unk_GetRenderService(char* pFramework);
int EnsureScreenshotDirectory(ATL::CStringT<wchar_t, StrTraitMFC_DLL<wchar_t, ATL::ChTraitsCRT<wchar_t> > >* pkDirectory);
int SaveRenderTargetToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiRenderTargetGroup* pkGroup,
    NiRect<unsigned int> kRect);
int SaveDefaultTargetToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nUnused,
    NiRect<unsigned int> kRect, float fScale);

float FUN_14028aed0(float f);                                        // round

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
    if (pCamera->m_spMode.get())
        pCamera->m_spMode->vfunc_5(b);
}

// @0x141a55200
void FUN_141a55200(CameraMgr* pCamera, Vector3 pt)
{
    if (pCamera->m_spMode.get())
        pCamera->m_spMode->vfunc_4(pt);
}

// ---- UIMinimapEditDialog ----

// @0x141a51f00
UIMinimapEditDialog::UIMinimapEditDialog()
    : m_hidden(10), m_instanced(10)
{
    m_40 = 1;
    m_spMinimap.AssignRaw(new CMinimap());
}

// @0x141a52020
CString UIMinimapEditDialog::GetTypeName()
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
    static_cast<MS2*>(FUN_140aae430())->SetBackgroundColor(NiColorA(0, 0, 0, 0));
    FUN_141a540f0(1);
    TSingleton<ApplyEffect>::GetInstance()->SetSoftParticlesOption(true, 0);
    TSingleton<ApplyEffect>::GetInstance()->ApplyFieldFogRange(false);
    CameraMgr::GetInstance()->FUN_140aed750(6, 1);
    FUN_141a551a0(CameraMgr::GetInstance(), true);
    WorldService::GetInstance()->FUN_141bd3cb0(true);
    m_strImageName.Empty();
    m_strImageIcon.Empty();
    return 1;
}

// @0x141a52190
void UIMinimapEditDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    static_cast<MS2*>(FUN_140aae430())->SetBackgroundColor(efd::ColorA::BLACK);
    FUN_141a540f0(0);
    TSingleton<ApplyEffect>::GetInstance()->ApplySoftParticleOption();
    TSingleton<ApplyEffect>::GetInstance()->ApplyFieldFog();
    CameraMgr::GetInstance()->FUN_140aec8a0(false);
    FUN_141a551a0(CameraMgr::GetInstance(), false);
    CameraMgr::GetInstance()->FUN_140aed750(2, 1);
    FUN_140b6bd30((void*)(CameraMgr::GetInstance()));
    WorldService::GetInstance()->FUN_141bd3cb0(false);
    m_strImageName.Empty();
    m_strImageIcon.Empty();
}

// @0x141a522a0
void UIMinimapEditDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141a53100();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != NULL)
        pDialog->SetPositionFloat(0, 0);

    if (MS2Ptr<ASSlider> spFov = GetChild<ASSlider>("m_sliderFov"))
    {
        spFov->FUN_1422ce750(0);
        spFov->FUN_1422ce6a0(90.0f);
        spFov->FUN_1422ce5f0(CameraMgr::GetInstance()->FUN_140ad4b40());
        spFov->FUN_1422c1fe0(0);
    }
    if (MS2Ptr<ASSlider> spDistance = GetChild<ASSlider>("m_sliderDistance"))
    {
        spDistance->FUN_1422ce750(10.0f);
        spDistance->FUN_1422ce6a0(20000.0f);
        spDistance->FUN_1422ce5f0(FUN_1409f2430(CameraMgr::GetInstance()));
        spDistance->FUN_1422c1fe0(0);
    }
    if (MS2Ptr<ASSlider> spVAngle = GetChild<ASSlider>("m_sliderVAngle"))
    {
        spVAngle->FUN_1422ce750(0);
        spVAngle->FUN_1422ce6a0(90.0f);
        spVAngle->FUN_1422ce5f0(FUN_141032e60((void*)(CameraMgr::GetInstance())));
        spVAngle->FUN_1422c1fe0(0);
    }

    if (MS2Ptr<ASLabel> spLabelFov = GetChild<ASLabel>("m_labelFov"))
    {
        CString strText;
        strText.Format("Camera Fov [%f]", (double)CameraMgr::GetInstance()->FUN_140ad4b40());
        spLabelFov->FUN_1422e4a00(strText);
    }
    if (MS2Ptr<ASLabel> spLabelDistance = GetChild<ASLabel>("m_labelDistance"))
    {
        CString strText;
        strText.Format("Camera Distance [%f]", (double)FUN_1409f2430(CameraMgr::GetInstance()));
        spLabelDistance->FUN_1422e4a00(strText);
    }
    if (MS2Ptr<ASLabel> spLabelVAngle = GetChild<ASLabel>("m_labelVAngle"))
    {
        CString strText;
        strText.Format("Camera VAngle [%f]", (double)FUN_141032e60((void*)(CameraMgr::GetInstance())));
        spLabelVAngle->FUN_1422e4a00(strText);
    }

    if (MS2Ptr<ASTextInput> spEmblem = GetChild<ASTextInput>("m_emblem"))
        spEmblem->SetTextA(m_strImageIcon);
    if (MS2Ptr<ASTextInput> spFileName = GetChild<ASTextInput>("m_fileName"))
    {
        if (m_strImageName.GetLength() < 1)
            m_strImageName = FUN_141a549c0();
        spFileName->SetTextA(m_strImageName);
    }

    if (MS2Ptr<ASMovieClip> spArea = GetChild<ASMovieClip>("m_rectarea"))
    {
        float fLeft = 0.0f > m_spMinimap->m_rcImage.l ? 0.0f : m_spMinimap->m_rcImage.l;
        float fTop = 0.0f > m_spMinimap->m_rcImage.t ? 0.0f : m_spMinimap->m_rcImage.t;
        float fWidth = m_spMinimap->m_rcImage.r - m_spMinimap->m_rcImage.l;
        float fHeight = m_spMinimap->m_rcImage.b - m_spMinimap->m_rcImage.t;
        spArea->SetPositionFloat(fLeft, fTop);
        ((ASDisplayObject*)(spArea.get()))->SetWidthFloat(fWidth);
        ((ASDisplayObject*)(spArea.get()))->SetHeightFloat(fHeight);
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
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            m_strImageIcon = data.FUN_1422b8d30();
            m_strImageName = data.FUN_1422b8d30();
        }
        FUN_141a53750();
    }
    else if (_stricmp("OnFov", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
        {
            float fFov = data.PopFloat();
            FUN_140ad4ff0(CameraMgr::GetInstance(), fFov);
            FUN_140b6bd30((void*)(CameraMgr::GetInstance()));
        }
    }
    else if (_stricmp("OnDistance", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
        {
            float fDistance = data.PopFloat();
            FUN_141032ed0((void*)(CameraMgr::GetInstance()), fDistance);
            FUN_141032f30((void*)(CameraMgr::GetInstance()), fDistance);
            CameraMgr::GetInstance()->FUN_140af9b40(fDistance);
            FUN_140b6bd30((void*)(CameraMgr::GetInstance()));
        }
    }
    else if (_stricmp("OnVAngle", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
        {
            float fAngle = data.PopFloat();
            CameraMgr::GetInstance()->FUN_140af98d0(fAngle);
            FUN_140b6bd30((void*)(CameraMgr::GetInstance()));
        }
    }
    else if (_stricmp("OnRotation", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0 && CameraMgr::GetInstance()->FUN_140a18070() != 0)
        {
            bool bRotation = data.PopBool();
            WorldService::GetInstance()->FUN_141bd3cf0(bRotation);
        }
    }
    else if (_stricmp("OnScreenShot", szMethod) == 0)
    {
        OnScreenShot();
    }
    return 0;
}

// @0x141a53100
void UIMinimapEditDialog::FUN_141a53100()
{
    MS2Ptr<CFieldDataCli> spMap = WorldService::GetInstance()->FUN_141bd30a0();
    if (spMap == 0)
        return;
    TiXmlDocument doc;
    if (doc.LoadFile((const char*)FUN_14016a5c0((const char*)GetXBlockPath(CString(spMap->m_strXBlock)), 0), TIXML_ENCODING_UNKNOWN))
    {
        Unk_XmlNode* pRoot = reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2");
        if (pRoot == NULL)
            return;
        if (pRoot->FirstChild("minimap"))
        {
            XmlGetChild((class TiXmlElement*)(pRoot->FirstChild("minimap")), "frustum", m_spMinimap->m_frustum);
            XmlGetChild((class TiXmlElement*)(pRoot->FirstChild("minimap")), "screen", reinterpret_cast<NiRect<float>&>(m_spMinimap->m_rcScreen));
            XmlGetChild((class TiXmlElement*)(pRoot->FirstChild("minimap")), "image", reinterpret_cast<NiRect<float>&>(m_spMinimap->m_rcImage));
            XmlGetChildAttr((class TiXmlElement*)(pRoot->FirstChild("minimap")), "image", "name", m_spMinimap->m_strImageName);
            m_strImageName = m_spMinimap->m_strImageName;
            XmlGetChildAttr((class TiXmlElement*)(pRoot->FirstChild("minimap")), "image", "icon", m_strImageIcon);
            XmlGetChildAttr((class TiXmlElement*)(pRoot->FirstChild("minimap")), "camera", "position", *(class NiPoint3*)(&m_spMinimap->m_vecCamPos));
            XmlGetChildAttr((class TiXmlElement*)(pRoot->FirstChild("minimap")), "camera", "rotation", *(class NiPoint3*)(&m_spMinimap->m_vecCamRot));
            XmlGetChildAttr((class TiXmlElement*)(pRoot->FirstChild("minimap")), "edit", "zoomfactor", *(float*)(&m_spMinimap->m_fZoomFactor));
            m_spMinimap->m_rcImage.r = m_spMinimap->m_rcImage.l + 1024.0f;
            m_spMinimap->m_rcImage.b = m_spMinimap->m_rcImage.t + 1024.0f;
            CameraMgrMoveTo(CameraMgr::GetInstance(), Vector3(reinterpret_cast<const Vector3&>(m_spMinimap->m_vecCamPos)));
            FUN_141a55200(CameraMgr::GetInstance(), Vector3(reinterpret_cast<const Vector3&>(m_spMinimap->m_vecCamRot)));
            CameraMgr::GetInstance()->FUN_140af0170(m_spMinimap->m_fZoomFactor < 1.0f ? 1.0f : m_spMinimap->m_fZoomFactor, false);
            FUN_140b6bd30((void*)(CameraMgr::GetInstance()));
        }
        else
        {
            m_strImageName = "";
        }
    }
}

// @0x141a53750
void UIMinimapEditDialog::FUN_141a53750()
{
    MS2Ptr<CFieldDataCli> spMap = WorldService::GetInstance()->FUN_141bd30a0();
    if (spMap == 0)
        return;
    if (MS2Ptr<ASMovieClip> spArea = GetChild<ASMovieClip>("m_rectarea"))
    {
        ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
        if (pSurface != NULL)
        {
            ecr::CameraData* pCamera = FUN_1413f9910()->GetActiveCamera(pSurface);
            if (pCamera != NULL && CameraMgr::GetInstance()->FUN_140a18070() != 0)
            {
                reinterpret_cast<NiPoint3&>(m_spMinimap->m_vecCamPos) = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(CameraMgr::GetInstance()->FUN_140a17e10()));
                reinterpret_cast<NiPoint3&>(m_spMinimap->m_vecCamRot) = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(CameraMgr::GetInstance()->FUN_140af8290()));
                m_spMinimap->m_frustum = pCamera->GetCamera()->GetViewFrustum();
                m_spMinimap->m_fZoomFactor = CameraMgr::GetInstance()->FUN_140af0140();
                m_spMinimap->m_strImageName = m_strImageName;
                m_spMinimap->m_rcScreen = Unk_Rect4(0, (float)DAT_143af62d4, 0, (float)DAT_143af62d8);
                m_spMinimap->m_rcImage.l = spArea->FUN_1422c10a0();
                m_spMinimap->m_rcImage.r = m_spMinimap->m_rcImage.l + (float)spArea->FUN_1422c1340();
                m_spMinimap->m_rcImage.t = spArea->FUN_1422c1110();
                m_spMinimap->m_rcImage.b = m_spMinimap->m_rcImage.t + (float)spArea->GetHeightCeil();
            }
        }
    }
    if (spMap->m_strXBlock.IsEmpty())
        return;
    TiXmlDocument doc;
    if (!doc.LoadFile((const char*)FUN_14016a5c0((const char*)GetXBlockPath(CString(spMap->m_strXBlock)), 0), TIXML_ENCODING_UNKNOWN))
    {
        TiXmlDeclaration decl("1.0", "utf-8", "");
        reinterpret_cast<TiXmlNode*>(&doc)->InsertEndChild(decl);
        reinterpret_cast<TiXmlNode*>(&doc)->InsertEndChild(static_cast<const TiXmlNode&>(TiXmlComment(FUN_1409a2360(" \xc6\xc4\xbd\xcc\xc7\xd8\xbc\xad \xbb\xe7\xbf\xeb\xc7\xcf\xb4\xc2 \xb5\xa5\xc0\xcc\xc5\xcd\xc0\xcc\xb4\xcf \xc1\xf7\xc1\xa2 \xbc\xf6\xc1\xa4\xc7\xcf\xc1\xf6 \xb8\xb6\xbc\xbc\xbf\xe4 ", 0))));
        TiXmlElement root("ms2");
        reinterpret_cast<TiXmlNode*>(&doc)->InsertEndChild(root);
    }
    Unk_XmlNode* pRoot = reinterpret_cast<Unk_XmlNode*>(&doc)->FirstChild("ms2");
    if (pRoot != NULL)
    {
        if (pRoot->FirstChild("minimap") == NULL)
        {
            reinterpret_cast<TiXmlNode*>(pRoot)->LinkEndChild(new TiXmlElement("minimap"));
        }
        Unk_XmlNode* pMinimap = pRoot->FirstChild("minimap");
        XmlSetChild((class TiXmlElement*)(pMinimap), "frustum", m_spMinimap->m_frustum, 1);
        XmlSetChild((class TiXmlElement*)(pMinimap), "screen", reinterpret_cast<const NiRect<float>&>(m_spMinimap->m_rcScreen), 1);
        XmlSetChild((class TiXmlElement*)(pMinimap), "image", reinterpret_cast<const NiRect<float>&>(m_spMinimap->m_rcImage), 1);
        XmlSetChildAttr((class TiXmlElement*)(pMinimap), "image", "name", m_strImageName, 1);
        XmlSetChildAttr((class TiXmlElement*)(pMinimap), "image", "icon", m_strImageIcon, 1);
        XmlSetChildAttr((class TiXmlElement*)(pMinimap), "camera", "position", reinterpret_cast<const efd::Point3&>(m_spMinimap->m_vecCamPos), 1);
        XmlSetChildAttr((class TiXmlElement*)(pMinimap), "camera", "rotation", reinterpret_cast<const efd::Point3&>(m_spMinimap->m_vecCamRot), 1);
        XmlSetChildAttr((class TiXmlElement*)(pMinimap), "edit", "zoomfactor", m_spMinimap->m_fZoomFactor, 1);
        doc.SaveFile();
    }
    SaveDefaultTargetToFileA(&m_strImageName, D3DXIFF_DDS, 1, FUN_141a54a50(), 0.5f);
}

// @0x141a540f0
void UIMinimapEditDialog::FUN_141a540f0(int bShow)
{
    efd::SmartPointer<HardwareInstancingService> spInstancing(((class HardwareInstancingService*)FUN_14098c5b0((struct Unk_EntityAppFramework*)(&DAT_143b059e8))));
    if (bShow != 0)
    {
        m_hidden.RemoveAll();
        m_instanced.RemoveAll();
        ATL::CAtlList<efd::SmartPointer<GameObject> > objects(10);
        WorldService::GetInstance()->FUN_141bd2db0(reinterpret_cast<ATL::CAtlList<efd::SmartPointer<Unk_WsC_GameObj> >*>(&objects), 0);
        for (POSITION pos = objects.GetHeadPosition(); pos != NULL; objects.GetNext(pos))
        {
            efd::SmartPointer<GameObject> spObject = objects.GetAt(pos);
            if (spObject)
            {
                if (spObject->FUN_14123c660() == 0)
                    m_hidden.AddTail(spObject->FUN_14123c460());
            }
        }
        egf::Entity* pEntity = NULL;
        Unk_WorldEntityMap::iterator iter = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411ce4c0();
        while (TSingleton<EntityWorldManager>::GetInstance()->FUN_1411ce510(iter, pEntity))
        {
            bool bVisible = false;
            bool bInstanced = false;
            if (spInstancing)
                pEntity->GetPropertyValue(0x23f9860e, bInstanced);
            if (!bInstanced)
            {
                pEntity->GetPropertyValue(0xa0b6b179, bVisible);
                if (!bVisible)
                    continue;
            }
            bool bFlag = false;
            if (pEntity->GetPropertyValue(0x4cc1298e, bFlag) == 0 && bFlag)
            {
                if (bInstanced)
                {
                    m_instanced.AddTail(pEntity);
                    spInstancing->FUN_1413d6f40(pEntity);
                }
                bool bHide = false;
                FUN_14098c6e0((Unk_CachedEntity*)(pEntity), 0xa0b6b179, bHide);
                m_hidden.AddTail(pEntity->GetEntityID());
            }
        }
    }
    else
    {
        if (spInstancing)
        {
            for (POSITION pos = m_instanced.GetHeadPosition(); pos != NULL; m_instanced.GetNext(pos))
                spInstancing->FUN_1413d6fc0(m_instanced.GetAt(pos));
        }
    }
    for (POSITION pos = m_hidden.GetHeadPosition(); pos != NULL; m_hidden.GetNext(pos))
    {
        GameObject* pObject = reinterpret_cast<GameObject*>(WorldService::GetInstance()->FindObjectByEntityId(m_hidden.GetAt(pos)));
        if (pObject != NULL)
            pObject->vfunc_23(bShow);
        egf::Entity* pEntity = TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(m_hidden.GetAt(pos));
        if (pEntity != NULL)
        {
            bool bVisible = bShow == 0 ? true : false;
            FUN_14098c6e0((Unk_CachedEntity*)(pEntity), 0xa0b6b179, bVisible);
        }
    }
    if (bShow != 0)
        TSingleton<CUIService>::GetInstance()->FUN_141ad9b30();
    else
        TSingleton<CUIService>::GetInstance()->FUN_141ad9650();
}

// @0x141a545a0
void UIMinimapEditDialog::OnScreenShot()
{
    if (MS2Ptr<ASMovieClip> spArea = GetChild<ASMovieClip>("m_rectarea"))
    {
        NiRect<unsigned int> kRect(0, 0, 0, 0);
        kRect.m_left = (int)(__int64)spArea->FUN_1422c10a0();
        kRect.m_right = kRect.m_left + spArea->FUN_1422c1340();
        kRect.m_top = (int)(__int64)spArea->FUN_1422c1110();
        kRect.m_bottom = kRect.m_top + spArea->GetHeightCeil();
        CStringW strDirectory;
        if (EnsureScreenshotDirectory(&strDirectory) < 0)
        {
            CStringW strMessage = StringFormat(L"Could not create directory. path={0}", strDirectory);
            FUN_140d73aa0(strMessage, 0, 0, CStringW(L""));
            return;
        }
        __time64_t tNow = FUN_141a51ee0(0);
        const struct tm* pTm = FUN_141a51ec0(&tNow);
        CStringW strName;
        strName.Format(L"\\%d%02d%02d_%02d%02d%02d.png", pTm->tm_year + 1900, pTm->tm_mon + 1, pTm->tm_mday, pTm->tm_hour, pTm->tm_min, pTm->tm_sec);
        CStringW strPath = strDirectory + strName;
        ecr::RenderService* pRegistry = Unk_GetRenderService(&DAT_143b059e8);
        if (pRegistry != NULL)
        {
            NiRenderTargetGroup* pGroup = pRegistry->GetActiveRenderSurface()->GetRenderTargetGroup();
            if (pGroup != NULL)
            {
                CStringA strPathA = FUN_14016a600((const wchar_t*)strPath, 0);
                SaveRenderTargetToFileA(&strPathA, D3DXIFF_PNG, pGroup, kRect);
            }
        }
    }
}

// @0x141a54940
CString UIMinimapEditDialog::GetXBlockPath(CString strXBlock)
{
    CString strPath = Unk_SocketFormat("./data/xml/MapXblock/{0}.xml", strXBlock);
    return strPath;
}

// @0x141a549c0
CString UIMinimapEditDialog::FUN_141a549c0()
{
    CString strPath;
    strPath.Format("./Data/Resource/Image/Map/Minimap/%08d.dds", WorldService::GetInstance()->FUN_141bd3060());
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
