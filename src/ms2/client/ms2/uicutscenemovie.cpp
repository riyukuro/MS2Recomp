// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uicutscenemovie.h.
// MS2-UNIT: client\ms2\uicutscenemovie.cpp
// MS2-RANGE: 0x14190eac0-0x141910480 .text$mn
// MS2-RANGE: 0x140111d60-0x140111ef1 .text$di
// MS2-RANGE: 0x142cbd630-0x142cbd6d5 .text$yd
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicutscenemovie.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uicutscenemovie.h"

#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/uimessagebox.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static UICommon::CMyPCKeyInputController s_keyInputController;     // header static (origin unknown), 0x143af1e60

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----

class Unk_14025e7a0 { public: void FUN_1422ae920(int n); void FUN_1422afdd0(float fVolume); };
Unk_14025e7a0* FUN_14025e7a0();
class Unk_14025e7c0 { public: bool FUN_14116d840(); };
Unk_14025e7c0* FUN_14025e7c0();
class Unk_140b632f0 { public: void FUN_1422d4780(UISwfEntity* p, int n); void FUN_1422d4840(UISwfEntity* p, int n); };
Unk_140b632f0* FUN_140b632f0();
class Unk_140a94350
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_140a94350* FUN_140a94350();
class Unk_141529a50 { public: void FUN_141529a50(bool b); };
class Unk_1403ed2d0 { public: Unk_141529a50* FUN_141bd0cc0(); int FUN_141bd3060(); };
Unk_1403ed2d0* FUN_1403ed2d0();
class Unk_1403ed2b0 { public: void FUN_141adb7b0(int n); int FUN_141add860(); };
Unk_1403ed2b0* FUN_1403ed2b0();
void FUN_14151f200();
int FUN_14151f6e0();
void FUN_141901390(int a1, int nUIType);
class Unk_1412787a0 { public: void FUN_1409f1e20(); void FUN_1409f1e40(); };
Unk_1412787a0* FUN_1412787a0();
class Unk_140d13c70 { public: bool m_bMute; void FUN_14125fe20(); float FUN_1412602e0(); };
class Unk_1409a8b10 { public: Unk_140d13c70* FUN_140d13c70(); const bool& FUN_140a58500(); };
Unk_1409a8b10* FUN_1409a8b10();
class Unk_140d13c40 { public: void FUN_14177dea0(int n, int nTime); void FUN_14177ddf0(int n, int nTime); };
Unk_140d13c40* FUN_140d13c40();
class Unk_1414a5700 { public: CString FUN_140d44f90(int n1, int n2); };
Unk_1414a5700* FUN_1414a5700();
void FUN_140d73bc0(int nId, int n, IMessageListener* pListener, CStringW str);
class Unk_140298f40 { public: const float& FUN_140298f40(); };
class Unk_1401d3200 { public: char m_pad[0x3c00]; Unk_140298f40 m_3c00; };
Unk_1401d3200* FUN_1401d3200();
class Unk_140d8ee90 { public: void FUN_140a1f970(const CString& strEvent, const CString& strArg); };
Unk_140d8ee90* FUN_140d8ee90();
class Unk_1409331f0 { public: CStringW FUN_14142d760(int nId, int n); };
Unk_1409331f0* FUN_1409331f0();
class Unk_1419e04b0 { public: int FUN_1419e04b0(); };
Unk_1419e04b0* FUN_141540270(int n);
// "GfxError:{0} {1}({2}) function:{3}"-style formatter (probably a variadic template taking const T&...).
CString FUN_140c05020(const char* szFormat, const char* a1, const char* a2, const int& a3, const char* a4);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14190eac0
UICutSceneMovie::UICutSceneMovie()
    : m_bIntroStory(false), m_bPlayPending(0), m_bSoundFaded(false), m_nCutSceneId(0), m_nSceneId(0)
{
    m_50 = 0;
    m_2c = 0x21;
}

// @0x14190eb90
UICutSceneMovie::~UICutSceneMovie()
{
}

// @0x14190ec00
int UICutSceneMovie::vfunc_52(const CString& strPath, float fVolume)
{
    m_strPath = strPath;
    m_68 = fVolume;
    m_bIntroStory = m_strPath == "Common/MS2IntroStory.usm";
    if (m_strPath.IsEmpty())
        return 0;
    RemoveTween();
    SetSoundFade(true);
    FUN_14025e7a0()->FUN_1422ae920(1);
    FUN_140b632f0()->FUN_1422d4780(this, 2);
    FUN_140a94350()->vfunc_10(11);
    if (m_4c != 0) {
        if (FUN_1403ed2d0()->FUN_141bd0cc0()) {
            Play();
            return 1;
        } else {
            m_bPlayPending = 1;
            return 1;
        }
    } else {
        FUN_1422dbf00(m_2c, 0, 0);
        return 1;
    }
}
MS2_REPLACE_METHOD(0x14190EC00, UICutSceneMovie, vfunc_52, 317, 0x6D3CA15C);

// @0x14190ed50
int UICutSceneMovie::vfunc_53()
{
    FUN_140b632f0()->FUN_1422d4840(this, 2);
    FUN_1403ed2b0()->FUN_141adb7b0(1);
    FUN_140a94350()->vfunc_10(0);
    if (m_30.get())
        m_30->Invoke("hide");
    SetSoundFade(false);
    FUN_14151f200();
    Unk_141529a50* p = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (p) {
        FUN_141901390(1, vfunc_48());
        if (m_bIntroStory)
            p->FUN_141529a50(false);
    }
    FUN_14025e7a0()->FUN_1422ae920(0);
    FUN_1412787a0()->FUN_1409f1e40();
    m_nCutSceneId = 0;
    return 1;
}
MS2_REPLACE_METHOD(0x14190ED50, UICutSceneMovie, vfunc_53, 300, 0xD30979BD);

// @0x14190ee90
void UICutSceneMovie::OnLoadComplete()
{
    UIVideoContents::OnLoadComplete();
    do {
        m_30->FUN_140bbe640("m_exit", m_pExit);
        if (m_pExit == NULL)
            throw new GfxExceptionSwfLoad(FUN_140c05020("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                        MS2_THIS_FILE, MS2_LINE(118), __FUNCTION__));
    } while (0);
    if (!m_bIntroStory)
        ShowSkipButton();
}
MS2_REPLACE_METHOD(0x14190EE90, UICutSceneMovie, OnLoadComplete, 437, 0xD4C6BC61);

// @0x14190f070
void UICutSceneMovie::vfunc_26()
{
    UIObject::vfunc_26();
    RemoveTween();
    m_pExit = NULL;
}
MS2_REPLACE_METHOD(0x14190F070, UICutSceneMovie, vfunc_26, 55, 0x4AC82A1D);

// @0x14190f0b0
void UICutSceneMovie::SetCutSceneId(int nId)
{
    m_nCutSceneId = nId;
}
MS2_REPLACE_METHOD(0x14190F0B0, UICutSceneMovie, SetCutSceneId, 25, 0xAF2C24E3);

// @0x14190f0d0
void UICutSceneMovie::StopIfCutScene(int nId)
{
    if (m_nCutSceneId == nId)
        vfunc_53();
}
MS2_REPLACE_METHOD(0x14190F0D0, UICutSceneMovie, StopIfCutScene, 54, 0x478AE610);

// @0x14190f110
void UICutSceneMovie::PlayScene(int nSceneId, CString strPath)
{
    m_nSceneId = nSceneId;
    m_strScenePath = strPath;
    PlayPendingScene();
}
MS2_REPLACE_METHOD(0x14190F110, UICutSceneMovie, PlayScene, 94, 0xB5A60985);

// @0x14190f180
void UICutSceneMovie::PlayCurrentScene()
{
    if (!m_strScenePath.IsEmpty())
        PlayPendingScene();
    else
        PlayDefaultScene();
}
MS2_REPLACE_METHOD(0x14190F180, UICutSceneMovie, PlayCurrentScene, 63, 0xBB4E3591);

// @0x14190f1d0
int UICutSceneMovie::HasSceneVideo(int nScene)
{
    if (!m_strScenePath.IsEmpty())
        return 1;
    int nId = FUN_1403ed2d0()->FUN_141bd3060();
    CString strPath = FUN_1414a5700()->FUN_140d44f90(nId, nScene);
    return strPath.GetLength() != 0;
}
MS2_REPLACE_METHOD(0x14190F1D0, UICutSceneMovie, HasSceneVideo, 153, 0x29014FD9);

// @0x14190f270
void UICutSceneMovie::SetSoundFade(bool bFade)
{
    if (m_bSoundFaded == bFade)
        return;
    const int nFadeTime = 1000;
    if (bFade) {
        FUN_1409a8b10()->FUN_140d13c70()->FUN_14125fe20();
        FUN_140d13c40()->FUN_14177dea0(2, nFadeTime);
        FUN_140d13c40()->FUN_14177dea0(1, nFadeTime);
    } else {
        FUN_1409a8b10()->FUN_140d13c70()->FUN_14125fe20();
        FUN_140d13c40()->FUN_14177ddf0(2, nFadeTime);
        FUN_140d13c40()->FUN_14177ddf0(1, nFadeTime);
    }
    m_bSoundFaded = bFade;
}
MS2_REPLACE_METHOD(0x14190F270, UICutSceneMovie, SetSoundFade, 217, 0x21C5A8D0);

// @0x14190f350
void UICutSceneMovie::RemoveTween()
{
    if (m_30.get())
        m_30->Invoke("removeTween");
}
MS2_REPLACE_METHOD(0x14190F350, UICutSceneMovie, RemoveTween, 83, 0x765F020D);

// @0x14190f3b0
CString UICutSceneMovie::vfunc_1()
{
    return "CutSceneMovie";
}
MS2_REPLACE_METHOD(0x14190F3B0, UICutSceneMovie, vfunc_1, 61, 0x09248588);

// @0x14190f400
void UICutSceneMovie::OnLoadInit()
{
    UIObject::OnLoadInit();
    if (MS2Ptr<Unk_ASVideoPlayer> pPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer")) {
        int nWidth = pPlayer->FUN_1422c1500();
        int nHeight = pPlayer->FUN_1422c1530();
        m_30->Invoke("setStageSize", nWidth, nHeight);
    }
}
MS2_REPLACE_METHOD(0x14190F400, UICutSceneMovie, OnLoadInit, 253, 0x31B35ED8);

// @0x14190f510
int UICutSceneMovie::vfunc_13()
{
    if (FUN_14025e7c0()->FUN_14116d840() && (m_pExit.get() ? true : false) && m_pExit->FUN_1422bfca0() &&
        FUN_14151f6e0()) {
        FUN_140d73bc0(0x88c, 1, this, L"");
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14190F510, UICutSceneMovie, vfunc_13, 230, 0x0EE38872);

// @0x14190f600
void UICutSceneMovie::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    if (m_bIntroStory && (m_pExit.get() ? true : false) && !m_pExit->FUN_1422bfca0()) {
        if (MS2Ptr<Unk_ASVideoPlayer> pPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer")) {
            if (pPlayer->FUN_1422e9540() >= FUN_1401d3200()->m_3c00.FUN_140298f40())
                ShowSkipButton();
        }
    }
}
MS2_REPLACE_METHOD(0x14190F600, UICutSceneMovie, vfunc_15, 331, 0x20701029);

// @0x14190f760
void UICutSceneMovie::vfunc_30(const CString& a1, const CString& a2, const CString& a3)
{
    if (a3 == "error" && a1 == m_strPath)
        vfunc_53();
}
MS2_REPLACE_METHOD(0x14190F760, UICutSceneMovie, vfunc_30, 101, 0xE8716013);

// @0x14190f7d0
void UICutSceneMovie::vfunc_31(const CString& a1, float a2, const void* a3)
{
    UISwfEntity::vfunc_31(a1, a2, a3);
    if (a1 == "end")
        vfunc_53();
}
MS2_REPLACE_METHOD(0x14190F7D0, UICutSceneMovie, vfunc_31, 99, 0xE5CDB5F9);

// @0x14190f840
int UICutSceneMovie::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onHideComplete") == 0) {
        FUN_1422dc080();
        m_strPath.Empty();
        FUN_1409a8b10()->FUN_140d13c70()->FUN_14125fe20();
        return 1;
    } else if (_stricmp(szMethod, "onExit") == 0) {
        FUN_140d73bc0(0x88c, 1, this, L"");
        return 1;
    } else if (_stricmp(szMethod, "onSwfStop") == 0) {
        Exit();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14190F840, UICutSceneMovie, vfunc_28, 300, 0x92742928);

// @0x14190f980
int UICutSceneMovie::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UISwfEntity::OnMessage(pSender, pMsg))
        return 1;
    if (!pMsg->FUN_1422e4520()) {
        if (dynamic_cast<UIMessageBox*>(pSender)) {
            int nResult = pMsg->FUN_1422b8a10();
            if (nResult == 0) {
                Exit();
                if (m_pExit.get()) {
                    m_pExit->vfunc_3(1);
                    m_pExit->vfunc_13("hide");
                }
                FUN_140d8ee90()->FUN_140a1f970("cut_scene_stop", m_strPath);
            }
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x14190F980, UICutSceneMovie, IMessageListener, OnMessage, 430, 0x856FD75B);

// @0x14190fb40
void UICutSceneMovie::vfunc_11()
{
    UISwfEntity::vfunc_11();
    if (m_30.IsNull())
        return;
    if (!FUN_1419102c0())
        return;
    Unk_141529a50* p = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (p) {
        FUN_141901390(0, vfunc_48());
        if (m_bPlayPending) {
            Play();
            m_bPlayPending = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x14190FB40, UICutSceneMovie, vfunc_11, 153, 0x86F6B64B);

// @0x14190fbe0
bool UICutSceneMovie::vfunc_17()
{
    if (MS2Ptr<Unk_ASVideoPlayer> pPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer"))
        pPlayer->FUN_1422e9810(pPlayer->FUN_1422c1500(), pPlayer->FUN_1422c1530());
    return true;
}
MS2_REPLACE_METHOD(0x14190FBE0, UICutSceneMovie, vfunc_17, 201, 0x5B881BB7);

// @0x14190fcb0
void UICutSceneMovie::ShowSkipButton()
{
    if (m_pExit.get()) {
        m_pExit->vfunc_3(1);
        m_pExit->vfunc_13("show");
        if (m_30.get()) {
            CStringW strKey(L"$s_cutscene_skip_key");
            CStringW strText(L"$s_cutscene_skip");
            if (FUN_1409a8b10()->FUN_140a58500())
                strKey = FUN_1409331f0()->FUN_14142d760(0x49409, 2);
            m_30->Invoke("setSkipKey", strKey, strText);
        }
    }
}
MS2_REPLACE_METHOD(0x14190FCB0, UICutSceneMovie, ShowSkipButton, 558, 0xE28A3DA1);

// @0x14190fef0
bool UICutSceneMovie::Play()
{
    CString strExt = PathFindExtensionA(m_strPath);
    bool bResult = false;
    if (strExt == ".swf")
        bResult = PlaySwf();
    else if (strExt == ".usm")
        bResult = PlayUsm();
    if (bResult)
        FUN_1403ed2b0()->FUN_141adb7b0(0);
    return bResult;
}
MS2_REPLACE_METHOD(0x14190FEF0, UICutSceneMovie, Play, 197, 0x9AC68545);

// @0x14190ffc0
bool UICutSceneMovie::PlayUsm()
{
    if (MS2Ptr<Unk_ASVideoPlayer> pPlayer = GetChild<Unk_ASVideoPlayer>("m_videoPlayer")) {
        Unk_140d13c70* pSound = FUN_1409a8b10()->FUN_140d13c70();
        if (pSound)
            pPlayer->FUN_1422e9490(pSound->m_bMute ? 0.0f : pSound->FUN_1412602e0());
        pPlayer->FUN_1422e95b0(m_strPath);
        pPlayer->FUN_1422e9690(m_68);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14190FFC0, UICutSceneMovie, PlayUsm, 317, 0x92C42E11);

// @0x141910110
bool UICutSceneMovie::PlaySwf()
{
    if (m_30 == NULL)
        return false;
    Unk_140d13c70* pSound = FUN_1409a8b10()->FUN_140d13c70();
    if (pSound)
        FUN_14025e7a0()->FUN_1422afdd0(pSound->m_bMute ? 0.0f : pSound->FUN_1412602e0());
    m_30->Invoke("playSwfMovie", m_strPath);
    return true;
}
MS2_REPLACE_METHOD(0x141910110, UICutSceneMovie, PlaySwf, 258, 0xC7EC24CD);

// @0x141910220
void UICutSceneMovie::Exit()
{
    if (m_nCutSceneId == 0) {
        vfunc_53();
    } else {
        COutPacket packet(0x2f, 0);
        packet.Encode1(9);
        packet.Encode1(5);
        packet.Encode4(m_nCutSceneId);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x141910220, UICutSceneMovie, Exit, 143, 0x5F0400FE);

// @0x1419102c0
int UICutSceneMovie::FUN_1419102c0()
{
    return FUN_1422dc2d0();
}
MS2_REPLACE_METHOD(0x1419102C0, UICutSceneMovie, FUN_1419102c0, 24, 0x7AC102E0);

// @0x1419102e0
void UICutSceneMovie::PlayDefaultScene()
{
    int nId = FUN_1403ed2d0()->FUN_141bd3060();
    int nScene = 0;
    Unk_1419e04b0* p = FUN_141540270(FUN_1403ed2b0()->FUN_141add860());
    if (p)
        nScene = p->FUN_1419e04b0();
    CString strPath = FUN_1414a5700()->FUN_140d44f90(nId, nScene);
    if (strPath.GetLength()) {
        FUN_1412787a0()->FUN_1409f1e20();
        vfunc_52(strPath, 0.0f);
    }
}
MS2_REPLACE_METHOD(0x1419102E0, UICutSceneMovie, PlayDefaultScene, 191, 0x4FB651D0);

// @0x1419103b0
void UICutSceneMovie::PlayPendingScene()
{
    int nId = FUN_1403ed2d0()->FUN_141bd3060();
    if (m_nSceneId == nId) {
        vfunc_52(m_strScenePath, 0.0f);
        m_strScenePath.Empty();
    }
}
MS2_REPLACE_METHOD(0x1419103B0, UICutSceneMovie, PlayPendingScene, 114, 0x3EB382FC);
