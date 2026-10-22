// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGameOptionDialog: the options window. See uigameoptiondialog.h.
// MS2-UNIT: ?\uigameoptiondialog.cpp
// MS2-RANGE: 0x141941b80-0x141946030 .text$mn
// MS2-RANGE: 0x140113870-0x140113990 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigameoptiondialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uigameoptiondialog.h"
#include "gameoptioncamera.h"
#include "gameoptioninterface.h"
#include "gameoptionstatus.h"
#include "gameoptionbattle.h"
#include "gameoptioncommunity.h"
#include "gameoptiongraphicdefault.h"
#include "gameoptionsounddefault.h"
#include "gameoptiongamepad.h"
#include "gameoptioninputdefault.h"
#include "gameoptionlanguage.h"
#include "gameoptionaccount.h"
#include "gameoptionpersonalinfoagreement.h"
#include "networkservice.h"
#include "buddymanager.h"
#include "uimessagebox.h"
#include "uimessageboxdata.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/usermail.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

extern unsigned int DAT_143ab2914;                              // the client build level

// The "m_apply" button of the option swf.
class Unk_GoButton : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(unsigned int bEnabled);                  // set enabled
};

// The tooltip image paths (the hdr one at +0xe0, the shimmer one at +0xe8).
struct Unk_GoTipPaths
{
    char m_pad[0xe0];
    CString m_strHdr;                                           // +0xe0
    CString m_strShimmer;                                       // +0xe8
};
Unk_GoTipPaths* FUN_1401d31f0();

// The option settings object (FUN_1409a8b10).
class Unk_GoSettings
{
public:
    void FUN_1412432d0();                                       // write the settings out
};
Unk_GoSettings* FUN_1409a8b10();

// The tables the "pending" check walks (a quest-like list, FUN_1409331f0).
class Unk_GoPending
{
public:
    size_t FUN_14142cbb0();                                     // count
    __int64 FUN_14142cbe0(unsigned int nIndex);                 // id of the row
    int FUN_14142cb40(unsigned int nIndex, int n);              // the row is done
};
Unk_GoPending* FUN_1409331f0();

// The buff-like table of the simple (reduced) mode test.
class Unk_GoBuffs;
Unk_GoBuffs* FUN_1409331e0();
int FUN_14138c900(Unk_GoBuffs* p, int n);

CBuddyManager* FUN_14097a780();

CFeatureManager* FUN_140166410();
CInputKeyHandler* FUN_14025e7c0();
bool FUN_14116d840(CInputKeyHandler* p);
void* FUN_1408e57f0();
int FUN_1422b9dc0(void*);                                       // the class id of the current map
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
bool FUN_140184310(const CString& str, const char* psz);        // str == psz
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);    // str == psz
CString FUN_140651390();                                        // the language directory
void FUN_14151f200();
CStringW FUN_14028b8e0(const CStringW& str);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_140632a60(int nStringId, const CStringW& strA, const CStringW& strB);
CStringW FUN_141277dd0(const Scaleform::GFx::Value* pValue);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140d73bc0(int nStringId, int nType, IMessageListener* pListener, CStringW strTag);
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// ---- the Invoke wrappers this unit owns (inline COMDATs) ----

// @0x141944620
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, int a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141944710
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, bool a2, bool a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141941b80
UIGameOptionDialog::UIGameOptionDialog()
    : m_nTab(1), m_bSimple(false), m_nF1cc(0), m_bF1d0(false)
{
    FUN_141924170(1);
    int nOrder = 1;
    m_mapPages.SetAt(1, MS2Ptr<CBaseOption>(new CGameOptionCamera(1, nOrder++)));
    m_mapPages.SetAt(2, MS2Ptr<CBaseOption>(new CGameOptionInterface(2, nOrder++)));
    m_mapPages.SetAt(3, MS2Ptr<CBaseOption>(new CGameOptionStatus(3, nOrder++)));
    m_mapPages.SetAt(4, MS2Ptr<CBaseOption>(new CGameOptionBattle(4, nOrder++)));
    m_mapPages.SetAt(5, MS2Ptr<CBaseOption>(new CGameOptionCommunity(5, nOrder++)));
    m_mapPages.SetAt(6, MS2Ptr<CBaseOption>(new CGameOptionGraphicDefault(6, nOrder++)));
    m_mapPages.SetAt(7, MS2Ptr<CBaseOption>(new CGameOptionSoundDefault(7, nOrder++)));
    if (FUN_140166410()->FUN_14036d570(0xb5) == 1)
        m_mapPages.SetAt(8, MS2Ptr<CBaseOption>(new CGameOptionGamePad(8, nOrder++)));
    m_mapPages.SetAt(9, MS2Ptr<CBaseOption>(new CGameOptionInputDefault(9, nOrder++)));
    m_mapPages.SetAt(10, MS2Ptr<CBaseOption>(new CGameOptionInputDefault(10, nOrder++)));
    m_mapPages.SetAt(11, MS2Ptr<CBaseOption>(new CGameOptionInputDefault(11, nOrder++)));
    if (FUN_140166410()->FUN_14036d570(0xb5) == 1)
        m_mapPages.SetAt(12, MS2Ptr<CBaseOption>(new CGameOptionInputDefault(12, nOrder++)));
    m_mapPages.SetAt(13, MS2Ptr<CBaseOption>(new CGameOptionInputDefault(13, nOrder++)));
    m_mapPages.SetAt(14, MS2Ptr<CBaseOption>(new CGameOptionLanguage(14, nOrder++)));
    m_mapPages.SetAt(16, MS2Ptr<CBaseOption>(new CGameOptionAccount(16, nOrder++)));
    if (FUN_140166410()->FUN_14036d570(0x117) == 1)
        m_mapPages.SetAt(15, MS2Ptr<CBaseOption>(new CGameOptionPersonalInfoAgreement(15, nOrder++)));
}

// @0x141942810
UIGameOptionDialog::~UIGameOptionDialog()
{
    FUN_141943a00();
}

// @0x141942880
CString UIGameOptionDialog::GetTypeName()
{
    return CString("GameOptionDialog");
}

// @0x1419428d0
void UIGameOptionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    int bNewBuild = (int)DAT_143ab2914 >= 0x32;
    int bGamePad = FUN_140166410()->FUN_14036d570(0xb5);
    FUN_141944590(bNewBuild);
    FUN_1409ee290(&m_30)->Invoke("initData", FUN_140651390(), bNewBuild, bGamePad);
    FUN_141943480();
    FUN_1419436e0(m_nTab);
}

// @0x141942a10
void UIGameOptionDialog::vfunc_67()
{
    for (POSITION pos = m_mapPages.GetStartPosition(); pos != 0; m_mapPages.GetNext(pos))
    {
        MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
        if (sp == 0)
            continue;
        sp->vfunc_4(0);
    }
    UIDialog::vfunc_67();
    m_bSimple = false;
    m_nTab = 1;
}

// @0x141942b10
int UIGameOptionDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    {
        MS2Ptr<CBaseOption> sp = FUN_141944460(m_nTab);
        if (sp.get() != 0 && sp->vfunc_8() != 0)
            return 1;
    }
    if (FUN_14116d840(FUN_14025e7c0()))
    {
        OnCloseDialog();
        return 1;
    }
    return 0;
}

// @0x141942bf0
void UIGameOptionDialog::vfunc_15()
{
    if (vfunc_55() == 0)
    {
        POSITION pos = m_mapPages.GetStartPosition();
        while (pos != 0)
        {
            MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
            sp->vfunc_13();
            m_mapPages.GetNext(pos);
        }
    }
}

// @0x141942cc0
int UIGameOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        OnCloseDialog();
        return 1;
    }
    else if (_stricmp("OnOpenTab", szMethod) == 0)
    {
        ASData kArgs;
        if (kArgs.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1419436e0(kArgs.FUN_1422b8b10());
    }
    else if (_stricmp("OnCloseTab", szMethod) == 0)
        OnCloseTab(m_nTab);
    else if (_stricmp("OnUndo", szMethod) == 0)
        return 1;
    else if (_stricmp("OnInit", szMethod) == 0)
    {
        FUN_141943a30();
        return 1;
    }
    else if (_stricmp("OnSave", szMethod) == 0)
    {
        OnSave();
        return 1;
    }
    else if (_stricmp("OnTabInit", szMethod) == 0)
    {
        ASData kArgs;
        if (kArgs.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nTab = kArgs.FUN_1422b8b10();
            MS2Ptr<CBaseOption> sp = FUN_141944460(nTab);
            if (sp.get() != 0)
                sp->vfunc_2();
        }
    }
    else if (_stricmp("OnSecondaryPassword", szMethod) == 0)
    {
        FUN_140d86260()->vfunc_24();
        return 1;
    }
    else
    {
        MS2Ptr<CBaseOption> sp = FUN_141944460(m_nTab);
        if (sp.get() != 0 && sp->vfunc_5(szMethod, const_cast<Scaleform::GFx::Value*>(pArgs), nArgs) != 0)
            return 1;
    }
    return UIDialog::vfunc_28(szMethod, pArgs, nArgs);
}

// @0x141943010
int UIGameOptionDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nAnswer = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (FUN_1403b3c40(strTag, L"OnSave"))
        {
            if (nAnswer == 0)
            {
                FUN_141943ec0();
                FUN_141943820(0);
            }
        }
        else if (FUN_1403b3c40(strTag, L"OnSaveAndCheck"))
        {
            if (nAnswer == 0)
            {
                FUN_141943ec0();
                vfunc_67();
            }
            else
            {
                FUN_141943d80();
                vfunc_67();
            }
        }
        else if (FUN_1403b3c40(strTag, L"OnClose"))
        {
            if (nAnswer == 0)
                vfunc_67();
        }
        else
        {
            if (nAnswer == 0)
                FUN_141944030(0);
            else if (nAnswer == 1)
                FUN_141944030(1);
            if (nAnswer != 2 && nAnswer != -1)
                FUN_141943820(1);
        }
    }
    return 1;
}

// @0x141943230
void UIGameOptionDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    CString strName = pArgs->FUN_1422b8d30();
    if (FUN_140184310(strName, "m_hdr"))
    {
        ASObj obj(2);
        obj.FUN_1409c0dc0("tooltip", "export_common_tooltip_tooltipImageOption");
        obj.FUN_1409c0dc0("optionDesc", "$s_gameoption_tooltip_hdr");
        obj.FUN_1409c0dc0("optionOn", "$s_gameoption_tooltip_hdr_on");
        obj.FUN_1409c0dc0("optionOff", "$s_gameoption_tooltip_hdr_off");
        obj.FUN_1407cba60("imgPath", FUN_1401d31f0()->m_strHdr);
        FUN_1409b4bc0(pRetVal, obj.FUN_1422bb870());
    }
    else if (FUN_140184310(strName, "m_shimmer"))
    {
        ASObj obj(2);
        obj.FUN_1409c0dc0("tooltip", "export_common_tooltip_tooltipImageOption");
        obj.FUN_1409c0dc0("optionDesc", "$s_gameoption_tooltip_shimmer");
        obj.FUN_1409c0dc0("optionOn", "$s_gameoption_tooltip_shimmer_on");
        obj.FUN_1409c0dc0("optionOff", "$s_gameoption_tooltip_shimmer_off");
        obj.FUN_1407cba60("imgPath", FUN_1401d31f0()->m_strShimmer);
        FUN_1409b4bc0(pRetVal, obj.FUN_1422bb870());
    }
}

// @0x141943480
void UIGameOptionDialog::FUN_141943480()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    int nMapClass = FUN_1422b9dc0(FUN_1408e57f0());
    m_bSimple = nMapClass == 0x620000d || nMapClass == 0x6200009 || nMapClass == 0x6200085
        || FUN_14138c900(FUN_1409331e0(), 1) != 0;
    if (m_bSimple)
        m_nTab = 6;
    for (POSITION pos = m_mapPages.GetStartPosition(); pos != 0; m_mapPages.GetNext(pos))
    {
        MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
        bool bEnabled = true;
        if (m_bSimple)
        {
            int nType = sp->GetType();
            bEnabled = nType == 6 || nType == 7 || nType == 0xe;
        }
        sp->SetEnabled(bEnabled);
        sp->vfunc_3(0);
    }
    bool bUnused = false;   // the exe stores this byte and never reads it
    FUN_1409ee290(&m_30)->Invoke("setTabComponent", m_nTab, m_bSimple, false);
    FUN_141943940();
}

// @0x1419436e0
void UIGameOptionDialog::FUN_1419436e0(int nTab)
{
    m_nTab = nTab;
    if (vfunc_55() == 0)
    {
        MS2Ptr<CBaseOption> sp = FUN_141944460(m_nTab);
        if (sp.get() != 0)
            sp->vfunc_3(1);
    }
}

// @0x141943790
void UIGameOptionDialog::OnCloseTab(int nTab)
{
    if (vfunc_55() == 0)
    {
        MS2Ptr<CBaseOption> sp = FUN_141944460(nTab);
        if (sp.get() != 0)
            sp->vfunc_4(1);
    }
}

// @0x141943820
void UIGameOptionDialog::FUN_141943820(int n)
{
    if (MS2Ptr<Unk_GoButton> spApply = FUN_140bb4b10(CString("m_apply")))
        spApply->FUN_1422c1fe0(n);
}

// @0x1419438b0
void UIGameOptionDialog::FUN_1419438b0()
{
    if (vfunc_55() == 0)
        FUN_1419436e0(m_nTab);
}

// @0x141943900
void UIGameOptionDialog::FUN_141943900(bool b)
{
    m_bF1d0 = b;
    FUN_141943940();
}

// @0x141943940
void UIGameOptionDialog::FUN_141943940()
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        MS2Ptr<CBaseOption> sp(nullptr);
        if (m_mapPages.Lookup(0xf, sp))
            FUN_1409ee290(&m_30)->Invoke("enableAgreementTabButtonRedCircle", m_bF1d0);
    }
}

// @0x141943a00
void UIGameOptionDialog::FUN_141943a00()
{
    m_mapPages.RemoveAll();
}

// @0x141943a30
void UIGameOptionDialog::FUN_141943a30()
{
    IMessageListener* pListener = this;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x18, CStringW(L""), pListener, CStringW(L""));
    if (spBox.get() != 0)
    {
        Scaleform::GFx::Value vTab = FUN_1409ee290(&m_30)->Invoke("getCurrentTabName");
        Scaleform::GFx::Value vCategory = FUN_1409ee290(&m_30)->Invoke("getCurrentCategoryName");
        CStringW strTab = FUN_141277dd0(&vTab);
        CStringW strCategory = FUN_141277dd0(&vCategory);
        if (8 < m_nTab && m_nTab < 0xe)
            strCategory = FUN_14028b8e0(CStringW(L"s_gameoption_init_shoutcut"));
        spBox->FUN_141a01690(FUN_14028de60(0x848), FUN_140632a60(0x849, strTab, strCategory), FUN_14028de60(0x476));
        spBox->SetTitle(FUN_14028de60(0x847));
        FUN_140d73c60(spBox);
    }
}

// @0x141943d80
void UIGameOptionDialog::FUN_141943d80()
{
    POSITION pos = m_mapPages.GetStartPosition();
    while (pos != 0)
    {
        MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
        sp->vfunc_9();
        m_mapPages.GetNext(pos);
    }
}

// @0x141943e30
void UIGameOptionDialog::OnSave()
{
    if (FUN_141944250() == 0)
        FUN_140d73bc0(0x84a, 1, this, CStringW(L"OnSave"));
    else
        FUN_141943ec0();
}

// @0x141943ec0
void UIGameOptionDialog::FUN_141943ec0()
{
    for (POSITION pos = m_mapPages.GetStartPosition(); pos != 0; m_mapPages.GetNext(pos))
    {
        MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
        sp->vfunc_10();
    }
    FUN_1409a8b10()->FUN_1412432d0();
    for (POSITION pos = m_mapPages.GetStartPosition(); pos != 0; m_mapPages.GetNext(pos))
    {
        MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
        sp->vfunc_11();
    }
    FUN_14097a780()->SendBuddyMode20();
}

// @0x141944030
void UIGameOptionDialog::FUN_141944030(int n)
{
    m_nF1cc = n;
    if (n != 0)
    {
        MS2Ptr<CBaseOption> sp = FUN_141944460(m_nTab);
        if (sp.get() != 0)
            sp->vfunc_12();
    }
    else
    {
        for (POSITION pos = m_mapPages.GetStartPosition(); pos != 0; m_mapPages.GetNext(pos))
        {
            MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
            sp->vfunc_12();
        }
    }
}

// @0x141944150
void UIGameOptionDialog::OnCloseDialog()
{
    if (FUN_141944330() == 0)
        FUN_140d73bc0(0x84b, 1, this, CStringW(L"OnSaveAndCheck"));
    else if (FUN_141944250() == 0)
        FUN_140d73bc0(0x84a, 1, this, CStringW(L"OnSaveAndCheck"));
    else
        vfunc_67();
}

// @0x141944250
int UIGameOptionDialog::FUN_141944250()
{
    if (!m_bSimple)
    {
        for (size_t i = 0; i < FUN_1409331f0()->FUN_14142cbb0(); ++i)
        {
            if (FUN_1409331f0()->FUN_14142cbe0((unsigned)i) != 0x7a137 && FUN_1409331f0()->FUN_14142cbe0((unsigned)i) != 0x7a138
                && FUN_1409331f0()->FUN_14142cbe0((unsigned)i) != 0x7a139 && FUN_1409331f0()->FUN_14142cb40((unsigned)i, 0) == 0)
                return 0;
        }
    }
    return 1;
}

// @0x141944330
int UIGameOptionDialog::FUN_141944330()
{
    {
        MS2Ptr<CBaseOption> spCur = FUN_141944460(m_nTab);
        if (spCur.get() != 0)
            spCur->vfunc_7();
    }
    for (POSITION pos = m_mapPages.GetStartPosition(); pos != 0; m_mapPages.GetNext(pos))
    {
        MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
        if (sp->vfunc_14())
            return 0;
    }
    return 1;
}

// @0x141944460
MS2Ptr<CBaseOption> UIGameOptionDialog::FUN_141944460(int nIndex)
{
    MS2Ptr<CBaseOption> spNone(0);
    int i = 1;
    for (POSITION pos = m_mapPages.GetStartPosition(); pos != 0; m_mapPages.GetNext(pos))
    {
        if (nIndex == i++)
        {
            MS2Ptr<CBaseOption> sp = m_mapPages.GetValueAt(pos);
            return static_cast<MS2Ptr<CBaseOption>&&>(sp);
        }
    }
    return MS2Ptr<CBaseOption>(0);
}

// @0x141944590
void UIGameOptionDialog::FUN_141944590(int n)
{
    FUN_1419445c0(0x10, n);
}

// @0x1419445c0
void UIGameOptionDialog::FUN_1419445c0(int nKey, int n)
{
    if (n == 0)
    {
        if (m_mapPages.Lookup(nKey) != 0)
            m_mapPages.RemoveKey(nKey);
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbe180-0x142cbe1f0 .text$yd
