// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uiloadingprogress.h.
// MS2-UNIT: ?\uiloadingprogress.cpp
// MS2-RANGE: 0x1419df870-0x1419e0cb0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiloadingprogress.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiloadingprogress.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/client/ms2/uicutscenemovie.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/fielddatacli.h"
#include <NiRenderer.h>
#include "ms2/client/ms2/postprocessing/outlinerenderstep.h"
#include "ms2/placeholder/cloadingdescriptiontable.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/client/ms2/loadingimagetable.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/scaleform/include/render/d3d9_texture.h"  // C3: Scaleform::Render::D3D9::Texture::Initialize
class CUserMail { public: static __int64 GetGFxSceneService(); };  // C3: member view (0x1408e57f0, the scene-service global)

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
          // the input service: (un)lock the mouse for the loading screen
void* FUN_14025e7c0();
class GFxSceneService   // C3: member view for the former free stand-ins
{
public:
    void FUN_1422ba110();
    int GetSceneId();
};
class Unk_LpPlayer { public: virtual void vfunc_0(); };             // the local player (slot 78 = the level)
class Unk_LpConstants;
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
CString GetInputDeviceName();
class UICutSceneMovie* FindCutSceneMovie(int);   // 0x14138fd50 the cut scene movie dialog (guideentity_1b)
class Unk_FtEntity { public: Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, int a2, int a3); };
MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& v);
class Unk_LpTexture;
// efd::SmartPointer<NiRenderedTexture>::operator-> 0x14127c9b0: smart pointer -> texture
class NiDX9Renderer   // C3: member view for the former free stand-ins
{
public:
    static const NiRTTI ms_RTTI;   // C3: was DAT_143d6eb58
    bool IsDeviceLost() const;
};
class Ni2DBuffer* GetScreenshotBuffer(int);   // C3: was FUN_14184e5d0
class NiDX9TextureData   // C3: member view for the former free stand-ins
{
public:
    struct IDirect3DBaseTexture9* GetD3DTexture() const;
};
int FUN_141277f50();                                                // next UI layer
int GetFadeOutFlag(WorldService* pWorld);
extern unsigned DAT_143af62d4, DAT_143af62d8; extern int DAT_143ab2874;

// @0x1419df870
UILoadingProgress::UILoadingProgress()
    : m_70(0), m_74(0), m_78(0)
{
    m_2c = 0x29;
    m_28 = FUN_141277f50();
    WorldService::GetInstance()->AddCallback(static_cast<IWorldServiceCallback*>(this));
}

// @0x1419df960
UILoadingProgress::~UILoadingProgress()
{
    if (WorldService::GetInstance() != 0)
    {
        WorldService::GetInstance()->RemoveCallback(static_cast<IWorldServiceCallback*>(this));
    }
}

// @0x1419dfa10
CString UILoadingProgress::GetTypeName()
{
    return "LoadingProgress";
}
MS2_REPLACE_METHOD(0x1419DFA10, UILoadingProgress, GetTypeName, 61, 0xD91F5B27);

// @0x1419dfa60
void UILoadingProgress::StartProgress(int nMap)
{
    m_74 = nMap;
    ((CInputKeyHandler*)FUN_14025e7c0())->SetModifier1(1);
    int bShowGuide = 0;
    Unk_LpPlayer* pPlayer = reinterpret_cast<Unk_LpPlayer*>(WorldService::GetInstance()->GetLocalPlayer());
    if (pPlayer != 0)
    {
        bShowGuide = (unsigned int)(*reinterpret_cast<unsigned short (**)(void*)>(*reinterpret_cast<char**>(pPlayer) + 0x270))(pPlayer)
            < *reinterpret_cast<Common::Constants::Value<unsigned int>*>((char*)((class Unk_LpConstants*)GetClientConstants()) + 0x6e28)->Get();   // level below the guide limit
    }
    if (m_30.get() != 0)
    {
        ASObj obj(FUN_1422db730());
        {
            CString strPath = GetLoadingImagePath();
            obj.SetStringMember("filePath", strPath);
            obj.SetStringMember("maskPath", GetMaskImagePath());
            obj.SetWStringMember("tip", TSingleton<CLoadingDescriptionTable>::GetInstance()->GetRandomTip());
            obj.SetIntMember("useFadeOut", FUN_1419e0600());
            obj.SetIntMember("showGuide", bShowGuide);
            obj.SetStringMember("showGuideType", GetInputDeviceName());
            obj.SetIntMember("showMove", FUN_1419e0630());
            obj.SetBoolMember("showFrame", vfunc_52());
        }
        m_30->Invoke("startProgress", obj.GetValue());
    }
}

// @0x1419dfd90
void UILoadingProgress::StopProgress()
{
    ((CInputKeyHandler*)FUN_14025e7c0())->SetModifier1(0);
    m_70 = GetTargetMapId();
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        pClip->Invoke("stopProgress", FUN_1419e0600());
}

// @0x1419dfe70
int UILoadingProgress::FUN_1419dfe70()
{
    if (TSingleton<CLoadingImageTable>::GetInstance()->HasImage(GetTargetMapId()) == 0)
        return 0;
    UICutSceneMovie* pCut = ((class UICutSceneMovie*)FindCutSceneMovie(0x4e7e));
    if (pCut != 0 && ((class UICutSceneMovie*)(class UICutSceneMovie*)(pCut))->HasSceneVideo(GetMapId()) != 0)
        return 0;
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->GetSceneId() == 0x620000d)
        return 1;
    int nMap = GetTargetMapId();
    int n = GetMapId();
    return TSingleton<CLoadingImageTable>::GetInstance()->IsSameImages(nMap, n) == 0;
}

// @0x1419dff50
void UILoadingProgress::SetProgress(const CStringW& strMsg, int a, int b)
{
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        reinterpret_cast<Unk_FtEntity*>(pClip.operator->())->Invoke("progress", CStringW(strMsg), a, b);
}
MS2_REPLACE_METHOD(0x1419DFF50, UILoadingProgress, SetProgress, 248, 0xF6585DC6);

// @0x1419e0050
void UILoadingProgress::SetMoveChannelMessage(const CStringW& strMsg)
{
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        pClip->Invoke("setMoveChannelMessage", CStringW(strMsg));
}
MS2_REPLACE_METHOD(0x1419E0050, UILoadingProgress, SetMoveChannelMessage, 216, 0xBC69F5B9);

// @0x1419e0130
void UILoadingProgress::vfunc_2()
{
    LoadSwf(GetLayer(), 0, 0);
}

// @0x1419e0160
void UILoadingProgress::vfunc_3()
{
    FUN_1422dc080();
}

// @0x1419e0180
void UILoadingProgress::vfunc_2(int nMap, CString strMessage)
{
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        pClip->Invoke("loadFail", CString(strMessage));
}

// @0x1419e0280
void UILoadingProgress::vfunc_16()
{
    m_78 = 0;
}
MS2_REPLACE_METHOD(0x1419E0280, UILoadingProgress, vfunc_16, 33, 0xBC0CEDA6);

// @0x1419e02b0
bool UILoadingProgress::vfunc_17()
{
    CreateBackgroundTexture(DAT_143af62d4, DAT_143af62d8);
    return true;
}
MS2_REPLACE_METHOD(0x1419E02B0, UILoadingProgress, vfunc_17, 39, 0xBC145410);

// @0x1419e02e0
void UILoadingProgress::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    CreateBackgroundTexture(DAT_143af62d4, DAT_143af62d8);
}
MS2_REPLACE_METHOD(0x1419E02E0, UILoadingProgress, OnLoadComplete, 47, 0x69214F2A);

// @0x1419e0320
int UILoadingProgress::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnFadeInComplete", szMethod) == 0)
    {
        ((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->FUN_1422ba110();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419E0320, UILoadingProgress, vfunc_28, 108, 0x1B935AA6);

// @0x1419e03a0
void UILoadingProgress::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (p2.get() == 0)
        return;
    if (p3 == 0)
        return;
    if ((NiRenderedTexture*)m_78 == 0)
        return;
    Unk_UISwfEntity_25* pTarget = p2.operator->();
    void* pChild = (*reinterpret_cast<void* (**)(void*, void*)>(*reinterpret_cast<char**>(pTarget) + 0xc0))(pTarget, p3);
    if (pChild != 0)
    {
        FUN_1419e07a0();
        void* pTex = ((void*)((class NiTexture*)(void*)(m_78.operator->()))->GetRendererData());
        if (pTex != 0)
            reinterpret_cast<Scaleform::Render::D3D9::Texture*>(pChild)->Initialize(reinterpret_cast<IDirect3DTexture9 *>(((class NiDX9TextureData*)(void*)(pTex))->GetD3DTexture()));
    }
}

// @0x1419e04b0
int UILoadingProgress::GetMapId()
{
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->GetSceneId() == 0x620000d)
        return 0;
    return m_70;
}
MS2_REPLACE_METHOD(0x1419E04B0, UILoadingProgress, GetMapId, 46, 0x6FE3E137);

// @0x1419e04f0
int UILoadingProgress::GetTargetMapId()
{
    if (((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->GetSceneId() == 0x620000d)
        return DAT_143ab2874;
    if (m_74 != 0)
    {
        return m_74;
    }
    return WorldService::GetInstance()->GetFieldId();
}

// @0x1419e0550
void UILoadingProgress::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_1409b40c0(m_28, root);
}

// @0x1419e05c0
bool UILoadingProgress::vfunc_52()
{
    int nScene = ((class GFxSceneService*)(void*)(((void*)CUserMail::GetGFxSceneService())))->GetSceneId();
    if (nScene == 0x6200009 || nScene == 0x6200085)
        return false;
    return true;
}

// @0x1419e0600
int UILoadingProgress::FUN_1419e0600()
{
    return GetFadeOutFlag(WorldService::GetInstance());
}

// @0x1419e0630
int UILoadingProgress::FUN_1419e0630()
{
    if (m_74 == 0)
        return 0;
    return 1;
}

// @0x1419e0650
CString UILoadingProgress::GetMaskImagePath()
{
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(GetMapId());
    if (spField.get() != 0)
    {
        return CString(spField->m_strBgMask);
    }
    return "";
}

// @0x1419e0710
CString UILoadingProgress::GetLoadingImagePath()
{
    if (FUN_1419dfe70() == 0)
        return "";
    return TSingleton<CLoadingImageTable>::GetInstance()->GetImageFile(GetTargetMapId(), 1);
}

// @0x1419e07a0
void UILoadingProgress::FUN_1419e07a0()
{
    if (WorldService::GetInstance()->FUN_141bcfc10() == 0)
        return;
    if ((NiRenderedTexture*)m_78 == 0)
        return;
    NiRenderer* pRenderer = ((class NiRenderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, (class NiObject const*)(((void*)NiRenderer::GetRenderer()))));
    if (pRenderer == 0)
        return;
    if (((class NiRenderer*)(class NiRenderer*)(pRenderer))->IsRenderTargetGroupActive())
        pRenderer->EndUsingRenderTargetGroup();
    if (!((class NiDX9Renderer*)(class NiRenderer*)(pRenderer))->IsDeviceLost())
    {
        void* pBack = ((void*)GetScreenshotBuffer(1));
        if (pBack != 0)
        {
            Unk_LpTexture* pSrc = (Unk_LpTexture*)m_78.operator->();
            // Copy(src, dest, srcRect, destRect, filter)
            (*reinterpret_cast<bool (**)(NiRenderer*, void*, void*, void*, void*, int)>(*reinterpret_cast<char**>(pRenderer) + 0x1b0))(
                pRenderer, pBack, (*reinterpret_cast<void* (**)(void*)>(*reinterpret_cast<char**>(pSrc) + 0xa0))(pSrc), 0, 0, 2);
        }
    }
}

// @0x1419e08b0
void UILoadingProgress::CreateBackgroundTexture(int nWidth, int nHeight)
{
    NiTexture::FormatPrefs fmt;   // 0x140984420
    fmt.m_eAlphaFmt = NiTexture::FormatPrefs::ALPHA_DEFAULT;
    m_78 = NiRenderedTexture::Create(nWidth, nHeight, static_cast<NiRenderer*>(((void*)NiRenderer::GetRenderer())), fmt, 0x100);
}

// @0x1419e0920
UILoadingProgressLobby::UILoadingProgressLobby()
{
    m_2c = 0x17;
    m_28 = 2;
}

// @0x1419e0990
UILoadingProgressLobby::~UILoadingProgressLobby()
{
}

// @0x1419e09e0
CString UILoadingProgressLobby::GetTypeName()
{
    return "LoadingProgressLobby";
}
MS2_REPLACE_METHOD(0x1419E09E0, UILoadingProgressLobby, GetTypeName, 61, 0xD8B8332F);

// @0x1419e0a30
CString UILoadingProgressLobby::vfunc_7()
{
    return "LoadingProgress";
}
MS2_REPLACE_METHOD(0x1419E0A30, UILoadingProgressLobby, vfunc_7, 61, 0x02971948);

// @0x1419e0a80
bool UILoadingProgressLobby::vfunc_52()
{
    return false;
}

// @0x1419e0b70
int GetFadeOutFlag(WorldService* pWorld)
{
    return *(int*)((char*)pWorld + 0x2a8);
}

MS2_EMIT_CRT_MEMMOVE_S();
