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

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
class Unk_LpInput { public: void FUN_14116d760(int n); };          // the input service: (un)lock the mouse for the loading screen
Unk_LpInput* FUN_14025e7c0();
void* FUN_1408e57f0();                                              // the scene manager
int FUN_1422b9dc0(void* pSceneMgr);                                 // the current scene id
void FUN_1422ba110(void* pSceneMgr);
class Unk_LpPlayer { public: virtual void vfunc_0(); };             // the local player (slot 78 = the level)
class Unk_LpConstants;
Unk_LpConstants* FUN_1401d3200();                                   // the constants table
unsigned int* FUN_1401d7c10(void* pEntry);                          // &constant (throws "constants is not set")
class Unk_LpSingleton
{
public:
    int FUN_140d44bd0(int nMap);
    int FUN_140d44c50(int nMap, int n);
    CString FUN_140d44e80(int nMap, int a, int b);
};
Unk_LpSingleton* FUN_1414a5700();
class Unk_LpGuide { public: CStringW FUN_14144e640(); };
Unk_LpGuide* FUN_1414a56f0();
CString FUN_141900b70();
UICutSceneMovie* FUN_14138fd50(int nId);
int FUN_14190f1d0(UICutSceneMovie* p, int n);
class Unk_LpMovie { public: Scaleform::GFx::Value FUN_1412c4930(const char* szMethod, CStringW a1, int a2, int a3); };
MS2Ptr<ASMovieClip> FUN_1409b40c0(int nMovieId, const Scaleform::GFx::Value& v);
class Unk_LpTexture;
Unk_LpTexture* FUN_14127c9b0(Unk_PPSmartA* p);                      // smart pointer -> texture
void* FUN_140994450();                                              // NiRenderer::GetRenderer
NiRenderer* FUN_14098d8d0(void* pTable, void* pKey);
char FUN_1416b1d20(NiRenderer* p);
char FUN_141419be0(NiRenderer* p);
void* FUN_14184e5d0(int n);
void* FUN_141d61a80(int nWidth, int nHeight, void* pRenderer, void* pFormat, int nFlags);
void FUN_140984420(void* pFormat);
void FUN_14272b7f0(void* pTarget, void* pTexture);
void* FUN_140980440(void* p);
void* FUN_140980360(void* p);
int FUN_141277f50();                                                // next UI layer
WorldService* FUN_1403ed2d0();
int FUN_1419e0b70(WorldService* pWorld);
int FUN_1419e0600();
extern int DAT_143af62d4, DAT_143af62d8, DAT_143ab2874;
extern char DAT_143d6eb58;

// MS2-FUNCTIONAL: frame layout: the exe constructor keeps a smaller frame and no EH state for the texture member
// @0x1419df870
UILoadingProgress::UILoadingProgress()
    : m_70(0), m_74(0), m_78(0)
{
    m_2c = 0x29;
    m_28 = FUN_141277f50();
    IWorldServiceCallback* pCallback = this ? static_cast<IWorldServiceCallback*>(this) : 0;
    FUN_1403ed2d0()->FUN_141bbae40(pCallback);
}

// MS2-FUNCTIONAL: frame layout: the exe destructor keeps a smaller frame (see the constructor)
// @0x1419df960
UILoadingProgress::~UILoadingProgress()
{
    if (FUN_1403ed2d0() != 0)
    {
        IWorldServiceCallback* pCallback = this ? static_cast<IWorldServiceCallback*>(this) : 0;
        FUN_1403ed2d0()->FUN_141bbae80(pCallback);
    }
}

// @0x1419dfa10
CString UILoadingProgress::vfunc_1()
{
    return "LoadingProgress";
}
MS2_REPLACE_METHOD(0x1419DFA10, UILoadingProgress, vfunc_1, 61, 0xD91F5B27);

// MS2-FUNCTIONAL: AS object setter order / temporaries of the string getters differ
// @0x1419dfa60
void UILoadingProgress::FUN_1419dfa60(int nMap)
{
    m_74 = nMap;
    FUN_14025e7c0()->FUN_14116d760(1);
    bool bShowGuide = false;
    Unk_LpPlayer* pPlayer = reinterpret_cast<Unk_LpPlayer*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        unsigned short nLevel = (*reinterpret_cast<unsigned short (***)(void*)>(pPlayer))[78](pPlayer);
        bShowGuide = (unsigned int)nLevel < *FUN_1401d7c10((char*)FUN_1401d3200() + 0x6e28);
    }
    if (m_30.get() != 0)
    {
        ASObj obj(FUN_1422db730());
        obj.FUN_1407cba60("filePath", FUN_1419e0710());
        obj.FUN_1407cba60("maskPath", FUN_1419e0650());
        obj.FUN_1407cbb20("tip", FUN_1414a56f0()->FUN_14144e640());
        obj.FUN_1407cb9c0("useFadeOut", FUN_1419e0600());
        obj.FUN_1407cb9c0("showGuide", bShowGuide);
        obj.FUN_1407cba60("showGuideType", FUN_141900b70());
        obj.FUN_1407cb9c0("showMove", FUN_1419e0630());
        obj.FUN_1407cbbe0("showFrame", vfunc_52());
        m_30->Invoke("startProgress", obj.FUN_1422bb870());
    }
}

// MS2-FUNCTIONAL: FUN_1419e0600 call sequence differs (frame/spill)
// @0x1419dfd90
void UILoadingProgress::FUN_1419dfd90()
{
    FUN_14025e7c0()->FUN_14116d760(0);
    m_70 = FUN_1419e04f0();
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
        pClip->Invoke("stopProgress", FUN_1419e0600());
}

// MS2-FUNCTIONAL: callee symbol pairing of the map helpers (unit-local FUN_1419e04b0/04f0 spills)
// @0x1419dfe70
bool UILoadingProgress::FUN_1419dfe70()
{
    int nMap = FUN_1419e04f0();
    if (FUN_1414a5700()->FUN_140d44bd0(nMap) == 0)
        return false;
    UICutSceneMovie* pCut = FUN_14138fd50(0x4e7e);
    if (pCut != 0 && FUN_14190f1d0(pCut, FUN_1419e04b0()) != 0)
        return false;
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x620000d)
        return true;
    return FUN_1414a5700()->FUN_140d44c50(FUN_1419e04f0(), FUN_1419e04b0()) == 0;
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

// MS2-FUNCTIONAL: TPtr<> get/operator-> split differs (0x140a5ac60 vs 0x140a5ac90)
// @0x1419e03a0
void UILoadingProgress::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (p2.get() == 0)
        return;
    if (p3 == 0)
        return;
    if (FUN_140c8f680(&m_78) == 0)
        return;
    void* pTarget = p2.get();
    void* pChild = (*reinterpret_cast<void* (***)(void*, void*)>(pTarget))[0xc0 / 8](pTarget, p3);
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

// MS2-FUNCTIONAL: branch layout of the scene-id test
// @0x1419e05c0
int UILoadingProgress::vfunc_52()
{
    int nScene = FUN_1422b9dc0(FUN_1408e57f0());
    if (nScene == 0x6200009 || nScene == 0x6200085)
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: exe keeps the world pointer in a spill slot
// @0x1419e0600
int FUN_1419e0600()
{
    return FUN_1419e0b70(FUN_1403ed2d0());
}

// MS2-FUNCTIONAL: leaf function in the exe (no frame): the member is likely compiled differently
// @0x1419e0630
bool UILoadingProgress::FUN_1419e0630()
{
    return m_74 != 0;
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

// MS2-FUNCTIONAL: callee pairing of the string getters
// @0x1419e0710
CString UILoadingProgress::FUN_1419e0710()
{
    int nFlag = 0;
    if (FUN_1419dfe70() == 0)
        return "";
    return FUN_1414a5700()->FUN_140d44e80(FUN_1419e04f0(), 1, nFlag);
}

// MS2-FUNCTIONAL: renderer smart-pointer lookup / vtable call shape
// @0x1419e07a0
void UILoadingProgress::FUN_1419e07a0()
{
    if (FUN_1403ed2d0()->FUN_141bcfc10() != 0 && FUN_140c8f680(&m_78) != 0)
    {
        NiRenderer* pRenderer = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
        if (pRenderer != 0)
        {
            if (FUN_1416b1d20(pRenderer) != 0)
                pRenderer->EndUsingRenderTargetGroup();
            void* pBack = FUN_14184e5d0(1);
            if (FUN_141419be0(pRenderer) == 0 && pBack != 0)
            {
                void* pTex = (*reinterpret_cast<void* (***)(void*)>(FUN_14127c9b0(&m_78)))[0xa0 / 8](FUN_14127c9b0(&m_78));
                (*reinterpret_cast<void (***)(NiRenderer*, void*, void*, int, int, int)>(pRenderer))[0x1b](pRenderer, pBack, pTex, 0, 0, 2);
            }
        }
    }
}

// MS2-FUNCTIONAL: format struct local layout
// @0x1419e08b0
void UILoadingProgress::FUN_1419e08b0(int nWidth, int nHeight)
{
    char fmt[12];                                                   // FUN_140984420 fills three ints (12 bytes)
    FUN_140984420(fmt);
    *(int*)(fmt + 4) = 3;
    m_78.Assign(FUN_141d61a80(nWidth, nHeight, FUN_140994450(), fmt, 0x100));
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
CString UILoadingProgressLobby::vfunc_1()
{
    return "LoadingProgressLobby";
}
MS2_REPLACE_METHOD(0x1419E09E0, UILoadingProgressLobby, vfunc_1, 61, 0xD8B8332F);

// @0x1419e0a30
CString UILoadingProgressLobby::vfunc_7()
{
    return "LoadingProgress";
}
MS2_REPLACE_METHOD(0x1419E0A30, UILoadingProgressLobby, vfunc_7, 61, 0x02971948);

// MS2-FUNCTIONAL: return type: the exe returns a byte
// @0x1419e0a80
int UILoadingProgressLobby::vfunc_52()
{
    return 0;
}

// @0x1419e0b70
int FUN_1419e0b70(WorldService* pWorld)
{
    return *(int*)((char*)pWorld + 0x2a8);
}

MS2_EMIT_CRT_MEMMOVE_S();
