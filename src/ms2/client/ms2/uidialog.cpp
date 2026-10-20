// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDialog, the base of every game dialog.
// MS2-UNIT: ?\uidialog.cpp
// MS2-RANGE: 0x1419231f0-0x141927f70 .text$mn
// MS2-RANGE: 0x140112990-0x140112b40 .text$di
// MS2-RANGE: 0x142cbdbd0-0x142cbdca0 .text$yd
// MS2-PIN: ??$StringFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV01@AEBH@Z 0x141926b20
// MS2-PIN: ??1?$MS2Ptr@VUnk_WebGuideEntry@@@@QEAA@XZ 0x1419271c0
// MS2-PIN: ??8?$MS2Ptr@VUnk_WebGuideEntry@@@@QEBA_NPEAVUnk_WebGuideEntry@@@Z 0x141927240
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x1419272c0
// MS2-PIN: ??_GUIDialog@@UEAAPEAXI@Z 0x141927340
// MS2-PIN: ??B?$MS2Ptr@VUnk_140acd6e0@@@@QEBAPEAVUnk_140acd6e0@@XZ 0x141927810
// MS2-PIN: ?AddRef@?$MS2Ptr@VUnk_WebGuideEntry@@@@AEBAXXZ 0x141927c10
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_WebGuideEntry@@@@CAXPEAVUnk_WebGuideEntry@@@Z 0x141927c40
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VUnk_WebGuideEntry@@@@AEBAXPEAX@Z 0x141927c60
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_WebGuideEntry@@@@AEAAXXZ 0x141927c90
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_WebGuideEntry@@@@AEAAXPEAX@Z 0x141927cd0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FreeNode@?$CAtlList@W4Unk_UIType@@V?$CElementTraits@W4Unk_UIType@@@ATL@@@ATL@@AEAAXPEAVCNode@12@@Z 0x1419274e0 ; unique
// MS2-PIN: ?GetFreeNode@?$CAtlList@W4Unk_UIType@@V?$CElementTraits@W4Unk_UIType@@@ATL@@@ATL@@AEAAXXZ 0x141927550 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$MS2Ptr@VUnk_WebGuideEntry@@@@V?$CStringElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VUnk_WebGuideEntry@@@@@2@@ATL@@QEBAIXZ 0x141927630 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlList@W4Unk_UIType@@V?$CElementTraits@W4Unk_UIType@@@ATL@@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141927b30 ; unique
// MS2-PINS-END tplpin
//
// units.tsv's ?\uidialog.cpp range (0x14191c7d0-) also holds the TU before it (UIBeautyShopDevDialog, 0x14191c7d0-
// 0x1419231f0 with its own .text$di/.text$yd); this file is only the UIDialog TU. The unit has no __FILE__ string of
// its own (the only assert is uiswfentity.inl's); its directory is assumed. Names are Ghidra's (vfunc_<slot> / FUN_<va>)
// unless the exe has one (RTTI: ASDialog, ASWindow, ASDisplayObjectContainer, ASUIComponent); s_openDialogs is
// invented. The COMDAT tail: the open-dialog list (CAtlList<int>), the web-guide table lookup (CAtlMap<CString,
// MS2Ptr<T>>), the Delegate<void(const Params&)> binding of UIDialog's button callbacks, StringFormat("{0}{1}"), the
// container child lookup (uiswfentity.inl) and the CRT memmove_s copy.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uidialog.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <atlcoll.h>
#include <algorithm>
#include <errno.h>
#include <string.h>

// The UI type ids (vfunc_48) of the open dialogs that asked for it (m_164), most recently opened/raised first. The
// element is an enum (CElementTraits<E> passes it by const&; the int specialization would pass it by value).
enum Unk_UIType {};
#ifdef MS2_HOOK_DLL
// The hooked open/close/raise paths must share the exe's list: unhooked exe code (0x14140d3e0) reads it too.
MS2_GLOBAL(0x143af2258, ATL::CAtlList<Unk_UIType>, g_openDialogs);
#define s_openDialogs (g_openDialogs.get())
#else
static ATL::CAtlList<Unk_UIType> s_openDialogs(10);                // 0x143af2258
#endif
// Header statics (the header_statics_a.h set without its condition object).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static CString s_strDialogClose = "dialog_close";                   // 0x143af2290 default close sound (m_d0)
static CString s_strDialogOpen = "dialog_open";                     // 0x143af2288 default open sound (m_c8)

// ---- unit-local stand-ins for the ActionScript wrappers (promote to src/ms2/placeholder/ when shared) ----

class ASDialog : public ASDisplayObjectContainer                    // RTTI .?AVASDialog@@
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);                                   // MS2: slot 24 (0xc0) apply the new size
    virtual void vfunc_25();                                        // MS2: slot 25 (0xc8) keep the dialog on screen

    void FUN_1422c00f0(float x, float y);                           // set the position
    void FUN_1422c0f60(float* pX, float* pY);                       // get the position
    float FUN_1422c10a0();                                          // x
    float FUN_1422c1110();                                          // y
    int FUN_1422c1500();                                            // screen width
    int FUN_1422c1530();                                            // screen height
    void FUN_1422c79e0(int nWidth, int nHeight);                    // resize
    void FUN_1422e5dd0();                                           // end of a drag
};
class ASWindow : public ASDisplayObjectContainer                    // RTTI .?AVASWindow@@
{
public:
    void FUN_1422e61f0(int n);
    void FUN_1422e6230(int n);
};
// A display object seen only through its position (vfunc_66).
class Unk_ASPosObject : public ASDisplayObject
{
public:
    void FUN_1422c0f60(float* pX, float* pY);
};
// The button wrapper of the bound children ("m_closeButton", "m_dragBar", "m_webGuideButton").
class Unk_140acd6e0 : public ASUIComponent
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUserData);
};
class Unk_ASChildFinder : public ASDisplayObjectContainer
{
public:
    template <class T> MS2Ptr<T> FUN_140d01c90(const CString& strName);    // recursive getChildByName
};
class ASUIComponentEx : public ASUIComponent
{
public:
    void FUN_1422c3940();                                           // drop the component's AS callbacks
};
MS2Ptr<ASDialog> FUN_140e43fe0(int nMovieId, const Scaleform::GFx::Value& v);    // new ASDialog(v, nMovieId)
bool FUN_1409b0350(const Scaleform::GFx::Value& v);

// ---- game singletons and helpers ----
class Unk_140b632f0                                                 // the UI manager
{
public:
    void FUN_1422d4780(UISwfEntity* p, int nLayer);                 // open
    void FUN_1422d4840(UISwfEntity* p, int nLayer);                 // close
    void FUN_1422d48f0(UISwfEntity* p, int nLayer);                 // bring to the top
    void FUN_1422d4dd0(CString strKey);
};
Unk_140b632f0* FUN_140b632f0();
class Unk_14140ea40                                                 // dialog open/close listener
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int nUIType);                              // MS2: slot 1 (0x08) a dialog opened
    virtual void vfunc_2(int nUIType);                              // MS2: slot 2 (0x10) a dialog closed
};
Unk_14140ea40* FUN_14140ea40();
class Unk_1409331e0;
Unk_1409331e0* FUN_1409331e0();
void FUN_14138d7e0(Unk_1409331e0* p, int a1, int a2);
void FUN_141276180(const CString& strSound, const CString& strArg);   // play a system sound
class Unk_140166440 { public: void FUN_14015eb90(int a1, int a2, const wchar_t* szFormat, const CString& a3); };
Unk_140166440* FUN_140166440();                                     // debug log
int FUN_141383a70(CString strName);
class Unk_1403ed2d0 { public: bool FUN_141bcb0a0(); void* FUN_141bd0cc0(); };
Unk_1403ed2d0* FUN_1403ed2d0();
void FUN_140d73cd0();
void FUN_141275260(int nId, int a1, int a2);                        // system message by id
void FUN_141a8a730();
class Unk_14025e7a0 { public: void FUN_1422b0840(int nLayer, unsigned* pWidth, unsigned* pHeight); };
Unk_14025e7a0* FUN_14025e7a0();
class Unk_14025e7c0 { public: bool FUN_14116d840(); };
Unk_14025e7c0* FUN_14025e7c0();
class Unk_140166410 { public: bool FUN_14036d570(int nId); };
Unk_140166410* FUN_140166410();                                     // content options
void* FUN_140bb9630(int n);                                         // int -> delegate user data
int FUN_140bb9640(void* p);                                         // delegate user data -> int
void FUN_140d01960(CString strKey);                                 // open the web guide page
float FUN_141276490(float fWidth, float fHeight);                   // UI scale
struct Unk_Info140e09150 { __int64 m_pad_00; float m_fValue; };
void* FUN_1409a8b10();
Unk_Info140e09150* FUN_140e09150(void* p);
extern unsigned DAT_143af62d4;                                      // client area width
extern unsigned DAT_143af62d8;                                      // client area height
extern int DAT_143af62dc;                                           // dialogs blocked
// The web guide entries keyed by "<dialog name><n>".
class Unk_WebGuideEntry : public CPtred {};
class Unk_1414a5880
{
public:
    // MS2-FUNCTIONAL: temporary/frame layout of the inlined CAtlMap lookup differs (no source form found)
    // @0x141927640
    MS2Ptr<Unk_WebGuideEntry> FUN_141927640(CString strKey)
    {
        MS2Ptr<Unk_WebGuideEntry> sp;
        if (!m_map.Lookup(strKey, sp))
            return 0;
        return sp;
    }

private:
    char m_pad_00[0x38];
    ATL::CAtlMap<CString, MS2Ptr<Unk_WebGuideEntry>, ATL::CStringElementTraits<CString> > m_map;    // +0x38
};
Unk_1414a5880* FUN_1414a5880();

// ---- xml (game TinyXML) ----
class TiXmlElement
{
public:
    TiXmlElement(const char* szValue);                              // 0x14086f2f0
private:
    char m_pad[0x90];
};
void FUN_14086ddc0(TiXmlDocument* pDoc);                            // Clear
void* FUN_14081b310(TiXmlDocument* pDoc);                           // RootElement
void* FUN_14086e090(TiXmlDocument* pDoc, TiXmlElement* pChild);     // LinkEndChild
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szPath);        // SaveFile
void* FUN_140165cf0(TiXmlDocument* pDoc, const char* szName);       // FirstChildElement
void FUN_140874440(void* pCfg, const char* szGroup, const char* szName, int n, int bCreate);
void FUN_1408744b0(void* pCfg, const char* szGroup, const char* szName, float f, int bCreate);
void FUN_1408741a0(void* pCfg, const char* szGroup, const char* szName, int* pn);
void FUN_140874210(void* pCfg, const char* szGroup, const char* szName, float* pf);
CString FUN_14038f6d0(const CString& str, const char* szExt);       // str + ext
CString FUN_1412755f0();                                            // the UI settings directory
CString FUN_140cc2a00(const CString& strRoot, const CString& strPath);    // path join

#define UIDIALOG_INL_ASSERT_0()                                                                                   \
    (void)((!!(0)) || (_wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\uiswfentity.inl", 23), 0))

// @0x1419231f0
UIDialog::UIDialog()
    : m_68(1), m_6c(0), m_70(0), m_74(0), m_78(0), m_7c(1), m_80(1), m_84(0), m_88(0), m_8c(1), m_c0(2), m_c4(0),
      m_d8(efd::Point2::ZERO), m_e0(4), m_158(0), m_15c(0), m_160(0), m_164(0), m_168(true)
{
    m_2c = 0x19;
    m_c8 = s_strDialogOpen;
    m_d0 = s_strDialogClose;
}

// @0x141923420
UIDialog::~UIDialog()
{
}

// @0x1419234e0
CString UIDialog::vfunc_1()
{
    return "Dialog";
}
MS2_REPLACE_METHOD(0x1419234e0, UIDialog, vfunc_1, 61, 0xEB719311);

// @0x141923530
int UIDialog::vfunc_52()
{
    return GetChild<Unk_140acd6e0>("m_dragBar").get() != 0;
}
MS2_REPLACE_METHOD(0x141923530, UIDialog, vfunc_52, 144, 0x6143FF76);

// @0x1419235d0
void UIDialog::FUN_1419235d0()
{
    MS2Ptr<ASWindow> spWindow(dynamic_cast<ASWindow*>((AScript*)m_30));
    if (spWindow.get())
        spWindow->Invoke("setTopMostLayer");
}
MS2_REPLACE_METHOD(0x1419235d0, UIDialog, FUN_1419235d0, 155, 0x6033B6CC);

// @0x141923680
void UIDialog::FUN_141923680(int n)
{
    MS2Ptr<ASWindow> spWindow(dynamic_cast<ASWindow*>((AScript*)m_30));
    if (spWindow.get())
        spWindow->FUN_1422e61f0(n);
}
MS2_REPLACE_METHOD(0x141923680, UIDialog, FUN_141923680, 138, 0x74DC9C10);

// @0x141923710
void UIDialog::FUN_141923710(int n)
{
    MS2Ptr<ASWindow> spWindow(dynamic_cast<ASWindow*>((AScript*)m_30));
    if (spWindow.get())
        spWindow->FUN_1422e6230(n);
}
MS2_REPLACE_METHOD(0x141923710, UIDialog, FUN_141923710, 138, 0x693CF38F);

// @0x1419237a0
int UIDialog::vfunc_6()
{
    return m_74;
}
MS2_REPLACE_METHOD(0x1419237a0, UIDialog, vfunc_6, 14, 0x99EEE733);

// @0x1419237c0
int UIDialog::vfunc_4()
{
    if (!m_80)
        return 0;
    if (!m_4c)
        return 1;
    FUN_14086ddc0(&m_e8);
    if (!FUN_14081b310(&m_e8))
        FUN_14086e090(&m_e8, new TiXmlElement(vfunc_1()));
    void* pRoot = FUN_14081b310(&m_e8);
    if (!pRoot)
        return 0;
    vfunc_53(pRoot);
    return FUN_1408710c0(&m_e8, FUN_140cc2a00(FUN_1412755f0(), FUN_14038f6d0(vfunc_1(), ".xml")));
}
MS2_REPLACE_METHOD(0x1419237c0, UIDialog, vfunc_4, 673, 0x49894032);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141923a70
int UIDialog::vfunc_5()
{
    if (!m_80)
        return 0;
    FUN_14086ddc0(&m_e8);
    vfunc_83();
    if (!m_e8.FUN_140870fc0(FUN_140cc2a00(FUN_1412755f0(), FUN_14038f6d0(vfunc_1(), ".xml")), 0))
        return 0;
    void* pNode = FUN_140165cf0(&m_e8, vfunc_1());
    if (!pNode)
        return 0;
    return m_78 = vfunc_54(pNode);
}
MS2_REPLACE_METHOD(0x141923a70, UIDialog, vfunc_5, 534, 0x31472310);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141923c90
int UIDialog::vfunc_53(void* pCfg)
{
    if (m_80) {
        if (vfunc_52())
            FUN_140874440(pCfg, "transform", "editAlign", m_74, 1);
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog) {
            float x = 0.0f;
            float y = 0.0f;
            pDialog->FUN_1422c0f60(&x, &y);
            FUN_1408744b0(pCfg, "transform", "x", x, 1);
            FUN_1408744b0(pCfg, "transform", "y", y, 1);
            if (!m_7c) {
                FUN_140874440(pCfg, "transform", "width", pDialog->FUN_1422c1340(), 1);
                FUN_140874440(pCfg, "transform", "height", pDialog->FUN_1422c13b0(), 1);
            }
            if (vfunc_52()) {
                float fScale = FUN_141276490((float)DAT_143af62d4, FUN_140e09150(FUN_1409a8b10())->m_fValue);
                FUN_1408744b0(pCfg, "transform", "rateX", x / ((float)DAT_143af62d4 * fScale), 1);
                FUN_1408744b0(pCfg, "transform", "rateY", y / ((float)DAT_143af62d8 * fScale), 1);
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141923c90, UIDialog, vfunc_53, 563, 0x7028CE92);

// @0x141923ed0
int UIDialog::vfunc_54(void* pCfg)
{
    if (m_80) {
        if (vfunc_52()) {
            FUN_1408741a0(pCfg, "transform", "editAlign", &m_74);
            int nWidth = 0;
            int nHeight = 0;
            float x = 0.0f;
            float y = 0.0f;
            FUN_140874210(pCfg, "transform", "x", &x);
            FUN_140874210(pCfg, "transform", "y", &y);
            FUN_1408741a0(pCfg, "transform", "width", &nWidth);
            FUN_1408741a0(pCfg, "transform", "height", &nHeight);
            ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDialog) {
                float fRateX = -1.0f;
                float fRateY = -1.0f;
                FUN_140874210(pCfg, "transform", "rateX", &fRateX);
                FUN_140874210(pCfg, "transform", "rateY", &fRateY);
                if (fRateX >= 0.0f || fRateY >= 0.0f) {
                    float fScale = FUN_141276490((float)DAT_143af62d4, FUN_140e09150(FUN_1409a8b10())->m_fValue);
                    float fWidth = (float)DAT_143af62d4 * fScale;
                    float fHeight = (float)DAT_143af62d8 * fScale;
                    x = fRateX * fWidth;
                    y = fRateY * fHeight;
                }
                if (fRateX > 1.0f || fRateY > 1.0f)
                    m_60 = 1;
                pDialog->FUN_1422c00f0(x, y);
                if (!m_7c)
                    vfunc_62(nWidth, nHeight);
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141923ed0, UIDialog, vfunc_54, 662, 0xC475BD6F);

// @0x141924170
void UIDialog::FUN_141924170(int n)
{
    m_c4 = n;
}
MS2_REPLACE_METHOD(0x141924170, UIDialog, FUN_141924170, 25, 0xD8FD4C23);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141924190
void UIDialog::FUN_141924190()
{
    if (!m_68) {
        m_78 = 0;
        FUN_14086ddc0(&m_e8);
        FUN_141926890();
        vfunc_77();
        FUN_140b632f0()->FUN_1422d4840(this, m_e0);
        FUN_14140ea40()->vfunc_2(vfunc_48());
        if (FUN_1409331e0())
            FUN_14138d7e0(FUN_1409331e0(), 3, 0);
        if (!vfunc_56() && m_8c)
            FUN_141276180(m_d0, "");
        if (m_164) {
            POSITION pos = s_openDialogs.Find((Unk_UIType)vfunc_48());
            if (pos)
                s_openDialogs.RemoveAt(pos);
        }
    }
}
// Reads s_openDialogs (the exe list in the hook DLL).

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141924330
void UIDialog::FUN_141924330(int n)
{
    if (m_158)
        m_160 = 0;
    if (!m_30.get() || !m_c4) {
        FUN_1422dc080();
        m_c0 = 2;
    } else {
        m_30->Invoke("stopTweens");
        if (!m_68)
            vfunc_4();
        m_c0 = 1;
        m_30->Invoke("startClose");
    }
}
MS2_REPLACE_METHOD(0x141924330, UIDialog, FUN_141924330, 311, 0xBB6B5898);

// @0x141924470
int UIDialog::FUN_141924470()
{
    return m_158 && m_160;
}
MS2_REPLACE_METHOD(0x141924470, UIDialog, FUN_141924470, 61, 0x59070A67);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x1419244c0
int UIDialog::FUN_1419244c0(int nBit)
{
    return m_a0.test(nBit);
}
MS2_REPLACE_METHOD(0x1419244c0, UIDialog, FUN_1419244c0, 72, 0x6C241F1A);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141924510
void UIDialog::FUN_141924510()
{
    if (!(m_90 == 0) && m_c4 && m_c0 == 0) {
        if (!FUN_1409b0350(m_90->FUN_1422baa20("m_openTween")))
            m_30->Invoke("stopOpenTweens");
    }
}
MS2_REPLACE_METHOD(0x141924510, UIDialog, FUN_141924510, 273, 0x7D56EA94);

// @0x141924630
int UIDialog::FUN_141924630()
{
    return vfunc_55() == 0;
}
MS2_REPLACE_METHOD(0x141924630, UIDialog, FUN_141924630, 59, 0x1ABB11BB);

// @0x141924680
void UIDialog::FUN_141924680()
{
    if (vfunc_58() && !FUN_1403ed2d0()->FUN_141bd0cc0())
        return;
    FUN_141a8a730();
    if (vfunc_65())
        vfunc_8(1);
}
MS2_REPLACE_METHOD(0x141924680, UIDialog, FUN_141924680, 106, 0xD91882AE);

// @0x1419246f0
void UIDialog::FUN_1419246f0()
{
    if (vfunc_55())
        FUN_141924680();
    else
        vfunc_67();
}
MS2_REPLACE_METHOD(0x1419246f0, UIDialog, FUN_1419246f0, 68, 0x28E32DDD);

// @0x141924740
int UIDialog::FUN_141924740()
{
    return !m_68 && !m_c0;
}
MS2_REPLACE_METHOD(0x141924740, UIDialog, FUN_141924740, 58, 0x3352225D);

// @0x141924780
void UIDialog::vfunc_8(int nVisible)
{
    UISwfEntity::vfunc_8(nVisible);
}
MS2_REPLACE_METHOD(0x141924780, UIDialog, vfunc_8, 32, 0x6CF5AC06);

// @0x1419247b0
int UIDialog::vfunc_9()
{
    return UISwfEntity::vfunc_9();
}
MS2_REPLACE_METHOD(0x1419247b0, UIDialog, vfunc_9, 24, 0x802B8F6A);

// @0x1419247d0
int UIDialog::vfunc_55()
{
    return m_68 && m_c0 == 2;
}
MS2_REPLACE_METHOD(0x1419247d0, UIDialog, vfunc_55, 58, 0x0D2345C6);

// @0x141924810
int UIDialog::vfunc_56()
{
    return FUN_1419244c0(0);
}
MS2_REPLACE_METHOD(0x141924810, UIDialog, vfunc_56, 26, 0x73B4958C);

// @0x141924830
int UIDialog::vfunc_57()
{
    return m_84;
}
MS2_REPLACE_METHOD(0x141924830, UIDialog, vfunc_57, 17, 0xA49D819F);

// @0x141924850
int UIDialog::vfunc_58()
{
    return m_88;
}
MS2_REPLACE_METHOD(0x141924850, UIDialog, vfunc_58, 17, 0x3F39D72B);

// @0x141924870
int UIDialog::vfunc_59()
{
    return m_158;
}
MS2_REPLACE_METHOD(0x141924870, UIDialog, vfunc_59, 17, 0xF95067D2);

// @0x141924890
int UIDialog::vfunc_60()
{
    return m_158 && m_15c;
}
MS2_REPLACE_METHOD(0x141924890, UIDialog, vfunc_60, 61, 0xC58ABBC3);

// @0x1419248e0
void UIDialog::vfunc_61(int n)
{
    m_8c = n;
}
MS2_REPLACE_METHOD(0x1419248e0, UIDialog, vfunc_61, 25, 0xE467F5FB);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141924900
void UIDialog::vfunc_62(int nWidth, int nHeight)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog) {
        int nCurHeight = pDialog->FUN_1422c13b0();
        int nCurWidth = pDialog->FUN_1422c1340();
        pDialog->FUN_1422c79e0((std::max)(nCurWidth, nWidth), (std::max)(nHeight, nCurHeight));
        pDialog->vfunc_24(1);
    }
}
MS2_REPLACE_METHOD(0x141924900, UIDialog, vfunc_62, 189, 0x2714202B);

// @0x1419249d0
void UIDialog::vfunc_63(int n)
{
    m_6c = n;
}
MS2_REPLACE_METHOD(0x1419249d0, UIDialog, vfunc_63, 22, 0x0E4CDE77);

// @0x1419249f0
int UIDialog::vfunc_64()
{
    return m_6c;
}
MS2_REPLACE_METHOD(0x1419249f0, UIDialog, vfunc_64, 14, 0x69D980EB);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
#ifndef MS2_HOOK_DLL
// @0x141924a10
int UIDialog::vfunc_65()
{
    if (!vfunc_55())
        return 0;
    if (!vfunc_73())
        return 0;
    m_68 = 0;
    if (!m_158) {
        FUN_1422dbf00(m_2c, 0, 0);
    } else if (!m_15c) {
        FUN_1422dbd70(m_2c, 0);
        FUN_141924170(0);
    } else {
        m_160 = 1;
        FUN_1422dbf00(m_2c, 0, 0);
    }
    FUN_140b632f0()->FUN_1422d4780(this, m_e0);
    FUN_140b632f0()->FUN_1422d4dd0(m_20);
    FUN_14140ea40()->vfunc_1(vfunc_48());
    if (FUN_1409331e0())
        FUN_14138d7e0(FUN_1409331e0(), 3, 0);
    if (m_58 && !vfunc_56() && m_8c)
        FUN_141276180(m_c8, "");
    if (m_164)
        s_openDialogs.AddHead((Unk_UIType)vfunc_48());
    return 1;
}
#endif
// Writes s_openDialogs (the exe list in the hook DLL).

// @0x141924cb0
void UIDialog::vfunc_66()
{
    MS2Ptr<ASDisplayObject> spObject(dynamic_cast<ASDisplayObject*>((AScript*)m_30));
    if (spObject.get())
        static_cast<Unk_ASPosObject*>(spObject.operator->())->FUN_1422c0f60(&m_d8.x, &m_d8.y);
}
MS2_REPLACE_METHOD(0x141924cb0, UIDialog, vfunc_66, 179, 0x90F5B11C);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
#ifndef MS2_HOOK_DLL
// @0x141924d70
void UIDialog::vfunc_67()
{
    FUN_141924190();
    FUN_141924330(m_c4);
    m_68 = 1;
    m_d8 = NiPoint2(efd::Point2::ZERO);
    m_170.Empty();
}
#endif
// Not hooked: FUN_141924190 reads s_openDialogs.

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141924df0
void UIDialog::vfunc_68()
{
    bool bClose = !m_68 || (m_68 && m_c4 && m_c0 != 2);
    if (bClose) {
        if (m_c4 && m_30.get())
            m_30->Invoke("stopTweens");
        int nTween = m_c4;
        m_c4 = 0;
        vfunc_67();
        m_c4 = nTween;
    }
    if (FUN_140166440())
        FUN_140166440()->FUN_14015eb90(0xb, 0x131, L"Close Dialog [{0}]", vfunc_1());
}
MS2_REPLACE_METHOD(0x141924df0, UIDialog, vfunc_68, 425, 0x36D99C6E);

// @0x141924fa0
void UIDialog::vfunc_69()
{
    if (!vfunc_71())
        vfunc_67();
}
MS2_REPLACE_METHOD(0x141924fa0, UIDialog, vfunc_69, 56, 0x24FD4832);

// @0x141924fe0
void UIDialog::vfunc_70()
{
    if (!vfunc_71())
        vfunc_67();
}
MS2_REPLACE_METHOD(0x141924fe0, UIDialog, vfunc_70, 56, 0x24FD4832);

// @0x141925020
int UIDialog::vfunc_71()
{
    return 0;
}
MS2_REPLACE_METHOD(0x141925020, UIDialog, vfunc_71, 8, 0x7F371472);

// @0x141925030
void UIDialog::vfunc_72()
{
}
MS2_REPLACE_METHOD(0x141925030, UIDialog, vfunc_72, 6, 0xA9AF6E37);

// @0x141925040
int UIDialog::vfunc_73()
{
    if (FUN_141383a70(vfunc_1()) || (FUN_1403ed2d0()->FUN_141bcb0a0() && !FUN_141926960())) {
        FUN_141275260(0x88b, 1, 1);
        return 0;
    }
    if (DAT_143af62dc)
        return 0;
    if (!vfunc_75()) {
        FUN_140d73cd0();
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141925040, UIDialog, vfunc_73, 179, 0xFDFA49E8);

// @0x141925100
int UIDialog::vfunc_74(int a1, void* p2, void* p3)
{
    return 0;
}
MS2_REPLACE_METHOD(0x141925100, UIDialog, vfunc_74, 22, 0x1F52ADBD);

// @0x141925120
bool UIDialog::vfunc_75()
{
    return true;
}
MS2_REPLACE_METHOD(0x141925120, UIDialog, vfunc_75, 8, 0x71679366);

// @0x141925130
void UIDialog::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_141926880();
    vfunc_66();
    m_c0 = 0;
    if (m_c4 && m_30.get())
        m_30->Invoke("startOpen");
    if (m_158 && !m_15c) {
        m_15c = 1;
        vfunc_81();
        vfunc_67();
        FUN_141924170(1);
        vfunc_61(1);
    }
}
MS2_REPLACE_METHOD(0x141925130, UIDialog, OnLoadComplete, 271, 0xDAF2DA54);

// @0x141925250
void UIDialog::vfunc_26()
{
    UIObject::vfunc_26();
    for (unsigned i = 0; i < m_a8.size(); i++)
        static_cast<ASUIComponentEx*>(m_a8[i].operator->())->FUN_1422c3940();
    m_a8.clear();
}
MS2_REPLACE_METHOD(0x141925250, UIDialog, vfunc_26, 140, 0xE1973F25);

// @0x1419252f0
void UIDialog::vfunc_27()
{
    UISwfEntity::vfunc_27();
    m_90 = 0;
}
MS2_REPLACE_METHOD(0x1419252f0, UIDialog, vfunc_27, 45, 0x794570A6);

// @0x141925330
void UIDialog::vfunc_18()
{
    if (vfunc_52() && !vfunc_55()) {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog) {
            int bOpening = FUN_1422dc430();
            if (bOpening)
                FUN_141924510();
            float x = 0.0f;
            float y = 0.0f;
            pDialog->FUN_1422c0f60(&x, &y);
            unsigned nWidth = 0;
            unsigned nHeight = 0;
            FUN_14025e7a0()->FUN_1422b0840(m_28, &nWidth, &nHeight);
            float fRateX = x / (float)nWidth;
            float fRateY = y / (float)nHeight;
            float fX = (float)pDialog->FUN_1422c1500() * fRateX;
            float fY = (float)pDialog->FUN_1422c1530() * fRateY;
            pDialog->FUN_1422c00f0(fX, fY);
            if (bOpening) {
                m_d8.x = fX;
                m_d8.y = fY;
            }
        }
    }
    UISwfEntity::vfunc_18();
}
MS2_REPLACE_METHOD(0x141925330, UIDialog, vfunc_18, 435, 0x7B1FCAAF);

// @0x1419254f0
bool UIDialog::vfunc_17()
{
    if (!UISwfEntity::vfunc_17())
        return false;
    if (vfunc_52() && !vfunc_55()) {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog) {
            float x = 0.0f;
            float y = 0.0f;
            pDialog->FUN_1422c0f60(&x, &y);
            unsigned nWidth = 0;
            unsigned nHeight = 0;
            FUN_14025e7a0()->FUN_1422b0840(m_28, &nWidth, &nHeight);
            float fRateX = x / (float)nWidth;
            float fRateY = y / (float)nHeight;
            pDialog->FUN_1422c00f0((float)pDialog->FUN_1422c1500() * fRateX, (float)pDialog->FUN_1422c1530() * fRateY);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1419254f0, UIDialog, vfunc_17, 369, 0x935ED93D);

// @0x141925670
void UIDialog::vfunc_76()
{
    m_70 = 1;
}
MS2_REPLACE_METHOD(0x141925670, UIDialog, vfunc_76, 18, 0x54BA0358);

// @0x141925690
void UIDialog::vfunc_77()
{
    if (m_70) {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog)
            pDialog->FUN_1422e5dd0();
        m_70 = 0;
        m_74 = 1;
        vfunc_4();
    }
}
MS2_REPLACE_METHOD(0x141925690, UIDialog, vfunc_77, 137, 0xF21573C6);

#ifndef MS2_HOOK_DLL
// @0x141925720
void UIDialog::vfunc_78()
{
    FUN_140b632f0()->FUN_1422d48f0(this, m_e0);
    if (m_164) {
        POSITION pos = s_openDialogs.Find((Unk_UIType)vfunc_48());
        if (pos)
            s_openDialogs.MoveToHead(pos);
    }
}
#endif
// Reads s_openDialogs (the exe list in the hook DLL).

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x1419257b0
void UIDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog) {
        bool bCheck = !m_60 && m_78 && vfunc_52();
        if (bCheck) {
            if ((float)pDialog->FUN_1422c1500() >= pDialog->FUN_1422c10a0() &&
                (float)pDialog->FUN_1422c1530() >= pDialog->FUN_1422c1110() && pDialog->FUN_1422c10a0() >= 0.0f &&
                pDialog->FUN_1422c1110() >= 0.0f)
                return;
            pDialog->vfunc_25();
        } else {
            pDialog->vfunc_25();
        }
    }
}
MS2_REPLACE_METHOD(0x1419257b0, UIDialog, vfunc_43, 322, 0xD6ACCEC5);

// @0x141925900
int UIDialog::vfunc_13()
{
    if (UISwfEntity::vfunc_13())
        return 1;
    if (vfunc_55())
        return 0;
    if (vfunc_56())
        return 0;
    if (FUN_14025e7c0()->FUN_14116d840() && !vfunc_64() && !FUN_1419244c0(1)) {
        vfunc_69();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141925900, UIDialog, vfunc_13, 182, 0x06C38AEC);

// @0x1419259c0
void UIDialog::vfunc_79(void* p)
{
}
MS2_REPLACE_METHOD(0x1419259c0, UIDialog, vfunc_79, 11, 0x02239C70);

// @0x1419259e0
void UIDialog::vfunc_80(void* p)
{
}
MS2_REPLACE_METHOD(0x1419259e0, UIDialog, vfunc_80, 11, 0x02239C70);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141925a00
int UIDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    return UISwfEntity::OnMessage(pSender, pMsg) != 0;
}
MS2_REPLACE_METHOD_VIA(0x141925a00, UIDialog, IMessageListener, OnMessage, 60, 0x19B0248A);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141925a50
int UIDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnCloseDialog", szMethod) == 0) {
        vfunc_70();
        return 1;
    }
    if (_stricmp("OnStartDrag", szMethod) == 0) {
        vfunc_76();
        return 1;
    }
    if (_stricmp("OnStopDrag", szMethod) == 0) {
        vfunc_77();
        return 1;
    }
    if (_stricmp("OnTopMostLayer", szMethod) == 0) {
        vfunc_78();
        return 1;
    }
    if (_stricmp("OnEndClose", szMethod) == 0) {
        if (m_c0 != 2) {
            m_c0 = 2;
            if (FUN_1409331e0())
                FUN_14138d7e0(FUN_1409331e0(), 3, 0);
            FUN_1422dc0b0();
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141925a50, UIDialog, vfunc_28, 365, 0x73540F46);

// @0x141925be0
void UIDialog::vfunc_81()
{
}
MS2_REPLACE_METHOD(0x141925be0, UIDialog, vfunc_81, 6, 0xA9AF6E37);

// @0x141925bf0
int UIDialog::vfunc_82()
{
    return -1;
}
MS2_REPLACE_METHOD(0x141925bf0, UIDialog, vfunc_82, 11, 0xC99FA0C7);

// @0x141925c10
void UIDialog::vfunc_32(void* p, float x, float y)
{
    UISwfEntity::vfunc_32(p, x, y);
}
MS2_REPLACE_METHOD(0x141925c10, UIDialog, vfunc_32, 58, 0x2E88B7AD);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141925c50
void UIDialog::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140e43fe0(m_28, root);
    if (!m_30.get())
        m_90 = 0;
    else
        m_90 = FUN_140e43fe0(m_28, m_30->FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x141925c50, UIDialog, vfunc_41, 264, 0xD6367043);

// @0x141925d60
void UIDialog::vfunc_42(GfxException* pException)
{
    if (pException)
        MessageBoxA(NULL, pException->what(), "Exception", 0);
    vfunc_67();
}
MS2_REPLACE_METHOD(0x141925d60, UIDialog, vfunc_42, 83, 0x709A9474);

// @0x141925dc0
void UIDialog::vfunc_83()
{
    m_74 = 0;
}
MS2_REPLACE_METHOD(0x141925dc0, UIDialog, vfunc_83, 18, 0x9EBBA857);

// @0x141925de0
void UIDialog::FUN_141925de0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_70();
}
MS2_REPLACE_METHOD(0x141925de0, UIDialog, FUN_141925de0, 38, 0xFDF30234);

// @0x141925e10
void UIDialog::FUN_141925e10(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140d01960(FUN_1419268a0(FUN_140bb9640(params.pUserData)));
}
MS2_REPLACE_METHOD(0x141925e10, UIDialog, FUN_141925e10, 76, 0x60699A5B);

// @0x141925e70
void UIDialog::FUN_141925e70(int nBit, int bSet)
{
    m_a0.set(nBit, bSet != 0);
}
MS2_REPLACE_METHOD(0x141925e70, UIDialog, FUN_141925e70, 73, 0x0E440CF3);

#ifndef MS2_HOOK_DLL
// @0x141925ec0
void UIDialog::FUN_141925ec0(CString strName)
{
    FUN_1419264e0(strName, Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDialog::FUN_141925de0));
}
#endif
// Not hooked: builds a DelegateImpl with the DLL's vftable/RTTI and hands it to the exe (see section 9).

// @0x141925fa0
void UIDialog::FUN_141925fa0(CString strName)
{
    if (m_30 == 0)
        return;
    MS2Ptr<Unk_140acd6e0> spBar = FUN_141926e30<Unk_140acd6e0>(strName);
    if (spBar == 0)
        return;
    m_30->Invoke("setDragBar", Scaleform::GFx::Value(spBar->FUN_1422bb870()));
}
MS2_REPLACE_METHOD(0x141925fa0, UIDialog, FUN_141925fa0, 296, 0x1B3B0B70);

// @0x1419260d0
void UIDialog::FUN_1419260d0(CString strName, int n)
{
    FUN_141926180(m_30, strName, n);
}
MS2_REPLACE_METHOD(0x1419260d0, UIDialog, FUN_1419260d0, 163, 0x0D892337);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
#ifndef MS2_HOOK_DLL
// @0x141926180
void UIDialog::FUN_141926180(MS2Ptr<AScript> spRoot, CString strName, int n)
{
    if (spRoot == 0)
        return;
    MS2Ptr<Unk_140acd6e0> spButton = spRoot->FUN_140acce30<Unk_140acd6e0>(strName);
    if (spButton == 0)
        return;
    if (!FUN_140166410()->FUN_14036d570(0x5f)) {
        spButton->vfunc_4(false);
        return;
    }
    if (FUN_1414a5880()->FUN_141927640(FUN_1419268a0(n)) == 0) {
        spButton->vfunc_4(false);
        return;
    }
    spButton->vfunc_4(true);
    spButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIDialog::FUN_141925e10),
                            FUN_140bb9630(n));
    MS2Ptr<ASUIComponent> spComponent(spButton.get());
    m_a8.push_back(spComponent);
}
#endif
// Not hooked: builds a DelegateImpl with the DLL's vftable/RTTI and hands it to the exe (see section 9).

// @0x1419264e0
void UIDialog::FUN_1419264e0(CString strName, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb)
{
    MS2Ptr<Unk_140acd6e0> spButton = GetChild<Unk_140acd6e0>(strName);
    if (spButton == 0)
        return;
    spButton->FUN_1422ce240(cb, 0);
    MS2Ptr<ASUIComponent> spComponent(spButton.get());
    m_a8.push_back(spComponent);
}
MS2_REPLACE_METHOD(0x1419264e0, UIDialog, FUN_1419264e0, 205, 0xBB52F8BA);

// @0x1419265c0
NiPoint2* UIDialog::FUN_1419265c0()
{
    return &m_d8;
}
MS2_REPLACE_METHOD(0x1419265c0, UIDialog, FUN_1419265c0, 17, 0xAA3C736B);

// @0x1419265e0
void UIDialog::FUN_1419265e0(const CString& str)
{
    m_170 = str;
}
MS2_REPLACE_METHOD(0x1419265e0, UIDialog, FUN_1419265e0, 44, 0x54890FB2);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x141926620
void UIDialog::FUN_141926620(int* pnAlign, float* pX, float* pY)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog) {
        float x = pDialog->FUN_1422c10a0();
        float y = pDialog->FUN_1422c1110();
        int nWidth = pDialog->FUN_1422c1340();
        int nHeight = pDialog->FUN_1422c13b0();
        float fHalfWidth = (float)pDialog->FUN_1422c1500() * 0.5f;
        float fHalfHeight = (float)pDialog->FUN_1422c1530() * 0.5f;
        if (x <= fHalfWidth && y <= fHalfHeight) {
            *pnAlign = 5;
            *pX = x;
            *pY = y;
        } else if (x >= fHalfWidth && y <= fHalfHeight) {
            *pnAlign = 6;
            *pX = (x + (float)nWidth) - fHalfWidth * 2.0f;
            *pY = y;
        } else if (x <= fHalfWidth && y >= fHalfHeight) {
            *pnAlign = 7;
            *pX = x;
            *pY = (y + (float)nHeight) - fHalfHeight * 2.0f;
        } else if (x >= fHalfWidth && y >= fHalfHeight) {
            *pnAlign = 8;
            *pX = (x + (float)nWidth) - fHalfWidth * 2.0f;
            *pY = (y + (float)nHeight) - fHalfHeight * 2.0f;
        }
    }
}
MS2_REPLACE_METHOD(0x141926620, UIDialog, FUN_141926620, 599, 0xE5BE4D28);

// @0x141926880
void UIDialog::FUN_141926880()
{
}
MS2_REPLACE_METHOD(0x141926880, UIDialog, FUN_141926880, 6, 0xA9AF6E37);

// @0x141926890
void UIDialog::FUN_141926890()
{
}
MS2_REPLACE_METHOD(0x141926890, UIDialog, FUN_141926890, 6, 0xA9AF6E37);

// MS2-FUNCTIONAL: stack frame and temporary layout differ (extra/merged CString temporaries; no source form found within the time box)
// @0x1419268a0
CString UIDialog::FUN_1419268a0(int n)
{
    if (n == 0)
        return vfunc_1();
    return StringFormat("{0}{1}", vfunc_1(), n);
}
MS2_REPLACE_METHOD(0x1419268a0, UIDialog, FUN_1419268a0, 177, 0x6DE46A52);

// @0x141926960
bool UIDialog::FUN_141926960()
{
    return m_168;
}
MS2_REPLACE_METHOD(0x141926960, UIDialog, FUN_141926960, 18, 0x7970D0EC);

// @0x141926980
void UIDialog::FUN_141926980(bool b)
{
    m_168 = b;
}
MS2_REPLACE_METHOD(0x141926980, UIDialog, FUN_141926980, 26, 0x67EC19EC);

// @0x141926e30
template <class T> MS2Ptr<T> UIDialog::FUN_141926e30(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<T>(0);
    MS2Ptr<ASDisplayObjectContainer> spContainer(dynamic_cast<ASDisplayObjectContainer*>((AScript*)m_30));
    if (spContainer == 0) {
        UIDIALOG_INL_ASSERT_0();
        return MS2Ptr<T>(0);
    }
    return static_cast<Unk_ASChildFinder*>(spContainer.operator->())->FUN_140d01c90<T>(strName);
}

MS2_EMIT_CRT_MEMMOVE_S();  // memmove_s 0x141927e50
