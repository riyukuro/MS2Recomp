// Recovered upper HUD dialog (token pocket / maid / PC bang / keyboard-mouse mode / search buttons, clock, notice
// ticker), plus the smaller UI classes that share its unit: the visitors book, the visual effect dialog, the weapon
// dummy dialog and the web browser base. Unk_ names are local reconstruction names.
#pragma once
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/uidialogeventlistener.h"
#include "ms2/placeholder/intervaltimer.h"
#include <NiPoint3.h>

class NiFixedString;
class ASMovieClip;
class ASTextField;
class ASData;
class NotifyObject;
class Unk_HudButton;
class ASTextInput;
class ASTextField;
class CMsTime;
class UIPcBangDialog;
class Unk_UISwfEntity_25;

// A plain xyz (the global shader constant read in the glow handler).
struct Unk_HudXyz
{
    Unk_HudXyz();                   // declared only (an all-float aggregate would get a GS cookie)
    float x, y, z;
};

class UIUpperHudDialog : public UIHeadUpDisplay, public UIStatusEventListener
{
public:
    UIUpperHudDialog();
    virtual ~UIUpperHudDialog();
    virtual CString GetTypeName();
    virtual int vfunc_13();
    virtual void vfunc_15();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
    virtual int vfunc_46();
    virtual int vfunc_48();
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);
    virtual void vfunc_oa0_11(void* a1);        // UIStatusEventListener slot 11 (Ghidra vfunc_o70_11): the meso amount
    virtual void vfunc_oa0_14(void* a1, int a2);   // slot 14 (vfunc_o70_14): the marat amount and its change

    void OnTokenPocketClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnMaidStatusClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void SendPcBangBonus(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnFishingBookClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnKeyboardGuideClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnInputModeClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnGamePadOnClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnGamePadOffClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void OpenEventBrowser(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnSearchClick(const Scaleform::GFx::FunctionHandler::Params& params);
    void FUN_141357050(const Scaleform::GFx::FunctionHandler::Params& params);
    void OnPcBangNotify(NotifyObject* pObj);
    void OnTokenMoneyChanged(NotifyObject* pObj);
    void OnGameEventChanged(NotifyObject* pObj);
    void OnSkillSetMode(NotifyObject* pObj);
    void SetNoticeSpeed(float f);
    void SetNotice(CStringW strText);
    void SetGamePadMode(int nMode);
    void SetInputMode(int nMode);
    void SetVersionText(__int64 tTime, __int64 nBonus);
    bool ToggleVersionText();
    void OnSearchDungeonPacket(CInPacket& packet);
    void ResetClock();
    void UpdateClock();
    void UpdateMaidReadyCount(int nQuiet);
    void UpdateHotTime(bool bForce);
    void UpdateNoticeScroll();
    void RefreshPcBang();
    void UpdateSearchDungeon();
    void RefreshNotice();
    void FUN_1413586c0(Scaleform::GFx::Value* pRetVal);
    void GetHotTimeTooltip(Scaleform::GFx::Value* pRetVal);
    void GetMeratTooltip(Scaleform::GFx::Value* pRetVal);
    void ShowPendingNotice();
    void SetButtonBadge(MS2Ptr<Unk_HudButton> spButton, int nCount);
    void SetPcBangState(int nState);

    // C3: FUN_14129a040 (bind a text input) is UIHomeSummonDialog's (unit_141299650.h), called through a view in the .cpp

private:
    MS2_LAYOUT_FRIEND;
    int m_nHour;                                // +0x78 hour shown by the clock
    int m_nMinute;                              // +0x7c
    int m_nMaidReady;                           // +0x80 number of maids that finished
    MS2Ptr<Unk_HudButton> m_tokenPocket;        // +0x88 "m_tokenPocketButton"
    MS2Ptr<Unk_HudButton> m_maidStatus;         // +0x98 "m_maidStatusButton"
    MS2Ptr<Unk_HudButton> m_pcBang;             // +0xa8 "m_pcBangButton"
    MS2Ptr<Unk_HudButton> m_pcBangCn1;          // +0xb8 "m_pcBangButtonCn1"
    MS2Ptr<Unk_HudButton> m_pcBangCn2;          // +0xc8 "m_pcBangButtonCn2"
    MS2Ptr<Unk_HudButton> m_fishingBook;        // +0xd8 "m_fishingBookButton"
    MS2Ptr<Unk_HudButton> m_keyboardGuide;      // +0xe8 "m_keyboardGuideButton"
    MS2Ptr<Unk_HudButton> m_keyboardMode;       // +0xf8 "m_keyboardMode"
    MS2Ptr<Unk_HudButton> m_mouseMode;          // +0x108 "m_mouseMode"
    MS2Ptr<Unk_HudButton> m_gamePadOn;          // +0x118 "m_gamePadOn"
    MS2Ptr<Unk_HudButton> m_gamePadOff;         // +0x128 "m_gamePadOff"
    MS2Ptr<Unk_HudButton> m_search;             // +0x138 "m_searchButton"
    MS2Ptr<ASTextInput> m_searchInput;         // +0x148 "m_searchInput"
    MS2Ptr<ASMovieClip> m_searchDungeon;        // +0x158 "m_searchDungeon"
    MS2Ptr<ASMovieClip> m_eventText;            // +0x168 "m_eventText" (notice ticker clip)
    MS2Ptr<ASTextField> m_noticeText;           // +0x178 its "textField"
    Unk_IntervalTimer m_timer;                  // +0x188 clock poll
    int m_nHotTime;                             // +0x190 last hot time shown
    CStringW m_strNotice;                       // +0x198 ticker text
    bool m_bNoticeOnce;                         // +0x1a0 ticker text was set from outside
    float m_fNoticeSpeed;                       // +0x1a4 ticker pixels per frame unit (default 50)
    float m_fNoticePos;                         // +0x1a8 ticker scroll position
    int m_nNoticeY;                             // +0x1ac ticker text y
    int m_nNoticeWidth;                         // +0x1b0 width of one ticker text
};
MS2_CHECK_SIZE(UIUpperHudDialog, 0x1b8);
MS2_CHECK_OFFSET(UIUpperHudDialog, m_nHour, 0x78);
MS2_CHECK_OFFSET(UIUpperHudDialog, m_tokenPocket, 0x88);
MS2_CHECK_OFFSET(UIUpperHudDialog, m_searchInput, 0x148);
MS2_CHECK_OFFSET(UIUpperHudDialog, m_timer, 0x188);
MS2_CHECK_OFFSET(UIUpperHudDialog, m_strNotice, 0x198);
MS2_CHECK_OFFSET(UIUpperHudDialog, m_nNoticeWidth, 0x1b0);

// The web browser dialog base (browser id at +0x180; the browser pages live in the exe's browser manager).
class UIWebBrowserBase : public UIDialog, public UIDialogEventListener
{
public:
    UIWebBrowserBase(int nBrowserId);                                       // 0x14135eac0
    virtual ~UIWebBrowserBase();                                            //  0 0x14135eb80
    virtual void vfunc_15();                                                // 15 0x14135f1b0
    virtual void vfunc_16();                                                // 16 0x14135f3c0
    virtual bool vfunc_17();                                                // 17 0x14135f410
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x14135f0b0
    virtual void vfunc_26();                                                // 26 0x14135f040
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14135f1e0
    virtual void vfunc_67();                                                // 67 0x14135f080
    virtual int vfunc_73();                                                 // 73 0x14135f020
    virtual int vfunc_74(int a1, void* p2, void* p3);                       // 74 0x14135f480
    virtual void vfunc_84(bool bVisible);                                   // 84 0x14135ed30
    virtual void vfunc_85();                                                // 85 0x14135ee20 "loadRenderTarget"
    virtual void vfunc_86();                                                // 86 0x14135ee80 "unloadRenderTarget"
    virtual void vfunc_87(SIZE* pSize);                                      // 87 0x14135eee0 the view size
    virtual int vfunc_88();                                                 // 88 0x14135f010 returns 0
    virtual void vfunc_89(const CString& strUrl);                           // 89 0x14135f660 navigate
    virtual bool vfunc_90(POINT* pPos);                                       // 90 0x14135f840 hit test (window -> view coordinates)

    void Navigate(const CString& strUrl, bool bOnce);
    int IsVisible() const;
    void FUN_14135eda0(int nWidth, int nHeight);
    void CloseBrowser();

protected:
    MS2_LAYOUT_FRIEND;
    int m_nBrowserId;                           // +0x180
    SIZE m_size;                                // +0x184 view size
    bool m_bVisible;                            // +0x18c
    bool m_b18d;                                // +0x18d
    CString m_strUrl;                           // +0x190 url waiting for the render target
};
MS2_CHECK_SIZE(UIWebBrowserBase, 0x198);
MS2_CHECK_OFFSET(UIWebBrowserBase, m_nBrowserId, 0x180);
MS2_CHECK_OFFSET(UIWebBrowserBase, m_size, 0x184);
MS2_CHECK_OFFSET(UIWebBrowserBase, m_strUrl, 0x190);

class UIVisitorsBookDialog : public UIWebBrowserBase
{
public:
    UIVisitorsBookDialog();                                                 // 0x14135b540
    virtual CString GetTypeName();                                              //  1 0x14135b5c0
    virtual void OnLoadComplete();                                          // 22 0x14135b610
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14135b8d0
    virtual int vfunc_48();                                                 // 48 0x14135bc10
    virtual void vfunc_87(SIZE* pSize);                                      // 87 0x14135b920
    virtual bool vfunc_90(POINT* pPos);                                       // 90 0x14135b950
};
MS2_CHECK_SIZE(UIVisitorsBookDialog, 0x198);

class UIVisualEffectDialog : public UIDialog
{
public:
    UIVisualEffectDialog();                                                 // 0x14135bc20
    virtual ~UIVisualEffectDialog();                                        //  0 0x14135bc70
    virtual CString GetTypeName();                                              //  1 0x14135bcb0
    virtual void OnLoadComplete();                                          // 22 0x14135bd00
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14135c5f0
    virtual int vfunc_48();                                                 // 48 0x14135dea0

    void SetShaderFloat(const NiFixedString& kName, float fValue);
    void SetBlackAndWhiteEnabled(bool bOn);
    void OnSelectRadioMotionBlurAll();
    void OnSelectRadioMotionBlurCharacter();
    void SetRadialBlurEnabled(bool bOn);
    void SetScreenMaskEnabled(bool bOn);
    void FUN_14135d490(bool bOn);
    void SetGlowEnabled(bool bOn);
    void SetGlowColor(float fRed, float fGreen, float fBlue);
    void FUN_14135d630(bool bOn);
    void SetScreenRatio(float fValue);
    void SetNearFarRange(float fNear, float fFar);
    void FUN_14135d700(bool bOn);
    void FUN_14135d730(ASData& data);
    void SetSliderValue(const CString& strName, float fValue);
};
MS2_CHECK_SIZE(UIVisualEffectDialog, 0x178);

// The weapon dummy dialog: rotation / translation sliders for the weapon attach node.
class UIWeaponDummyDialog : public UIDialog
{
public:
    UIWeaponDummyDialog();                                                  // 0x14135e1c0
    virtual ~UIWeaponDummyDialog();                                         //  0 0x14135e250
    virtual CString GetTypeName();                                              //  1 0x14135e290
    virtual void OnLoadComplete();                                          // 22 0x14135e2e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14135e3f0
    virtual void vfunc_67();                                                // 67 0x14135e540
    virtual int vfunc_48();                                                 // 48 0x14135eab0

    CString GetTargetNode();
    void OnChangeSliderRotation(ASData& data);
    void OnChangeSliderTranslation(ASData& data);
    void FUN_14135e880(const CString& strNode, const NiPoint3& kRot, const NiPoint3& kTrans);

private:
    MS2_LAYOUT_FRIEND;
    NiPoint3 m_rotation;                            // +0x178
    NiPoint3 m_translation;                         // +0x184
};
MS2_CHECK_SIZE(UIWeaponDummyDialog, 0x190);
