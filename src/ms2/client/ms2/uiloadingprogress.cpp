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

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
          // the input service: (un)lock the mouse for the loading screen
CInputKeyHandler* FUN_14025e7c0();
void* FUN_1408e57f0();                                              // the scene manager
int FUN_1422b9dc0(void* pSceneMgr);                                 // the current scene id
void FUN_1422ba110(void* pSceneMgr);
class Unk_LpPlayer { public: virtual void vfunc_0(); };             // the local player (slot 78 = the level)
class Unk_LpConstants;
Unk_LpConstants* FUN_1401d3200();                                   // the constants table
unsigned int* FUN_1401d7c10(void* pEntry);                          // &constant (throws "constants is not set")
CString FUN_141900b70();
UICutSceneMovie* FUN_14138fd50(int nId);
int FUN_14190f1d0(UICutSceneMovie* p, int n);
class Unk_LpMovie { public: Scaleform::GFx::Value FUN_1412c4930(const char* szMethod, CStringW a1, int a2, int a3); };
MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& v);
class Unk_LpTexture;
Unk_LpTexture* FUN_14127c9b0(Unk_PPSmartA* p);                      // smart pointer -> texture
void* FUN_140994450();                                              // NiRenderer::GetRenderer
NiRenderer* FUN_14098d8d0(void* pTable, void* pKey);
bool FUN_1416b1d20(NiRenderer* p);
bool FUN_141419be0(NiRenderer* p);
void* FUN_14184e5d0(int n);
void FUN_14272b7f0(void* pTarget, void* pTexture);
void* FUN_140980440(void* p);
void* FUN_140980360(void* p);
int FUN_141277f50();                                                // next UI layer
WorldService* FUN_1403ed2d0();
int FUN_1419e0b70(WorldService* pWorld);
extern int DAT_143af62d4, DAT_143af62d8, DAT_143ab2874;
extern char DAT_143d6eb58;

// @0x1419df870
UILoadingProgress::UILoadingProgress()
    : m_70(0), m_74(0), m_78(0)
{
    m_2c = 0x29;
    m_28 = FUN_141277f50();
    FUN_1403ed2d0()->FUN_141bbae40(static_cast<IWorldServiceCallback*>(this));
}

// @0x1419df960
UILoadingProgress::~UILoadingProgress()
{
    if (FUN_1403ed2d0() != 0)
    {
        FUN_1403ed2d0()->FUN_141bbae80(static_cast<IWorldServiceCallback*>(this));
    }
}

// @0x1419dfa10
CString UILoadingProgress::GetTypeName()
{
    return "LoadingProgress";
}
MS2_REPLACE_METHOD(0x1419DFA10, UILoadingProgress, GetTypeName, 61, 0xD91F5B27);

// @0x1419dfa60
void UILoadingProgress::FUN_1419dfa60(int nMap)
{
    m_74 = nMap;
    FUN_14025e7c0()->SetModifier1(1);
    int bShowGuide = 0;
    Unk_LpPlayer* pPlayer = reinterpret_cast<Unk_LpPlayer*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        bShowGuide = (unsigned int)(*reinterpret_cast<unsigned short (**)(void*)>(*reinterpret_cast<char**>(pPlayer) + 0x270))(pPlayer)
            < *FUN_1401d7c10((char*)FUN_1401d3200() + 0x6e28);   // level below the guide limit
    }
    if (m_30.get() != 0)
    {
        ASObj obj(FUN_1422db730());
        {
            CString strPath = FUN_1419e0710();
            obj.FUN_1407cba60("filePath", strPath);
            obj.FUN_1407cba60("maskPath", FUN_1419e0650());
            obj.FUN_1407cbb20("tip", TSingleton<CLoadingDescriptionTable>::GetInstance()->GetRandomTip());
            obj.FUN_1407cb9c0("useFadeOut", FUN_1419e0600());
            obj.FUN_1407cb9c0("showGuide", bShowGuide);
            obj.FUN_1407cba60("showGuideType", FUN_141900b70());
            obj.FUN_1407cb9c0("showMove", FUN_1419e0630());
            obj.FUN_1407cbbe0("showFrame", vfunc_52());
        }
        m_30->Invoke("startProgress", obj.FUN_1422bb870());
    }
}

// @0x1419dfd90
void UILoadingProgress::FUN_1419dfd90()
{
    FUN_14025e7c0()->SetModifier1(0);
    m_70 = FUN_1419e04f0();
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        pClip->Invoke("stopProgress", FUN_1419e0600());
}

// @0x1419dfe70
int UILoadingProgress::FUN_1419dfe70()
{
    if (TSingleton<CLoadingImageTable>::GetInstance()->HasImage(FUN_1419e04f0()) == 0)
        return 0;
    UICutSceneMovie* pCut = FUN_14138fd50(0x4e7e);
    if (pCut != 0 && FUN_14190f1d0(pCut, FUN_1419e04b0()) != 0)
        return 0;
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x620000d)
        return 1;
    int nMap = FUN_1419e04f0();
    int n = FUN_1419e04b0();
    return TSingleton<CLoadingImageTable>::GetInstance()->IsSameImages(nMap, n) == 0;
}

// @0x1419dff50
void UILoadingProgress::FUN_1419dff50(const CStringW& strMsg, int a, int b)
{
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        reinterpret_cast<Unk_LpMovie*>(pClip.operator->())->FUN_1412c4930("progress", CStringW(strMsg), a, b);
}
MS2_REPLACE_METHOD(0x1419DFF50, UILoadingProgress, FUN_1419dff50, 248, 0xF6585DC6);

// @0x1419e0050
void UILoadingProgress::FUN_1419e0050(const CStringW& strMsg)
{
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        pClip->Invoke("setMoveChannelMessage", CStringW(strMsg));
}
MS2_REPLACE_METHOD(0x1419E0050, UILoadingProgress, FUN_1419e0050, 216, 0xBC69F5B9);

// @0x1419e0130
void UILoadingProgress::vfunc_2()
{
    FUN_1422dbf00(FUN_1422db750(), 0, 0);
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
    m_78.Assign(0);
}
MS2_REPLACE_METHOD(0x1419E0280, UILoadingProgress, vfunc_16, 33, 0xBC0CEDA6);

// @0x1419e02b0
bool UILoadingProgress::vfunc_17()
{
    FUN_1419e08b0(DAT_143af62d4, DAT_143af62d8);
    return true;
}
MS2_REPLACE_METHOD(0x1419E02B0, UILoadingProgress, vfunc_17, 39, 0xBC145410);

// @0x1419e02e0
void UILoadingProgress::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_1419e08b0(DAT_143af62d4, DAT_143af62d8);
}
MS2_REPLACE_METHOD(0x1419E02E0, UILoadingProgress, OnLoadComplete, 47, 0x69214F2A);

// @0x1419e0320
int UILoadingProgress::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnFadeInComplete", szMethod) == 0)
    {
        FUN_1422ba110(FUN_1408e57f0());
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
    if (FUN_140c8f680(&m_78) == 0)
        return;
    Unk_UISwfEntity_25* pTarget = p2.operator->();
    void* pChild = (*reinterpret_cast<void* (**)(void*, void*)>(*reinterpret_cast<char**>(pTarget) + 0xc0))(pTarget, p3);
    if (pChild != 0)
    {
        FUN_1419e07a0();
        void* pTex = FUN_140980440(FUN_14127c9b0(&m_78));
        if (pTex != 0)
            FUN_14272b7f0(pChild, FUN_140980360(pTex));
    }
}

// @0x1419e04b0
int UILoadingProgress::FUN_1419e04b0()
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x620000d)
        return 0;
    return m_70;
}
MS2_REPLACE_METHOD(0x1419E04B0, UILoadingProgress, FUN_1419e04b0, 46, 0x6FE3E137);

// @0x1419e04f0
int UILoadingProgress::FUN_1419e04f0()
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x620000d)
        return DAT_143ab2874;
    if (m_74 != 0)
    {
        return m_74;
    }
    return FUN_1403ed2d0()->FUN_141bd3060();
}

// @0x1419e0550
void UILoadingProgress::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_1409b40c0(m_28, root);
}

// @0x1419e05c0
bool UILoadingProgress::vfunc_52()
{
    int nScene = FUN_1422b9dc0(FUN_1408e57f0());
    if (nScene == 0x6200009 || nScene == 0x6200085)
        return false;
    return true;
}

// @0x1419e0600
int UILoadingProgress::FUN_1419e0600()
{
    return FUN_1419e0b70(FUN_1403ed2d0());
}

// @0x1419e0630
int UILoadingProgress::FUN_1419e0630()
{
    if (m_74 == 0)
        return 0;
    return 1;
}

// @0x1419e0650
CString UILoadingProgress::FUN_1419e0650()
{
    MS2Ptr<CFieldDataCli> spField = CFieldDataCli::Find(FUN_1419e04b0());
    if (spField.get() != 0)
    {
        return CString(spField->m_strBgMask);
    }
    return "";
}

// @0x1419e0710
CString UILoadingProgress::FUN_1419e0710()
{
    if (FUN_1419dfe70() == 0)
        return "";
    return TSingleton<CLoadingImageTable>::GetInstance()->GetImageFile(FUN_1419e04f0(), 1);
}

// @0x1419e07a0
void UILoadingProgress::FUN_1419e07a0()
{
    if (FUN_1403ed2d0()->FUN_141bcfc10() == 0)
        return;
    if (FUN_140c8f680(&m_78) == 0)
        return;
    NiRenderer* pRenderer = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (pRenderer == 0)
        return;
    if (FUN_1416b1d20(pRenderer))
        pRenderer->EndUsingRenderTargetGroup();
    if (!FUN_141419be0(pRenderer))
    {
        void* pBack = FUN_14184e5d0(1);
        if (pBack != 0)
        {
            Unk_LpTexture* pSrc = FUN_14127c9b0(&m_78);
            // Copy(src, dest, srcRect, destRect, filter)
            (*reinterpret_cast<bool (**)(NiRenderer*, void*, void*, void*, void*, int)>(*reinterpret_cast<char**>(pRenderer) + 0x1b0))(
                pRenderer, pBack, (*reinterpret_cast<void* (**)(void*)>(*reinterpret_cast<char**>(pSrc) + 0xa0))(pSrc), 0, 0, 2);
        }
    }
}

// @0x1419e08b0
void UILoadingProgress::FUN_1419e08b0(int nWidth, int nHeight)
{
    Unk_PPFmt fmt;
    fmt.b = 3;
    m_78.Assign(FUN_141d61a80(nWidth, nHeight, static_cast<NiRenderer*>(FUN_140994450()), &fmt, 0x100));
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
int FUN_1419e0b70(WorldService* pWorld)
{
    return *(int*)((char*)pWorld + 0x2a8);
}

MS2_EMIT_CRT_MEMMOVE_S();
