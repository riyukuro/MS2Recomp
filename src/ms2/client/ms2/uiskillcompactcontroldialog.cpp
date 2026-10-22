// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The compact skill control window ("SkillCompactControl", UI type
// 0x4ef6): up to three named tabs, each with the skills the player ticked and one hot key that triggers the whole set.
// The tabs come from the server (packet 0xd1) and go back on close (packet 0x7b); the skill system gets them as
// CSkillCompactControlConfig. See uiskillcompactcontroldialog.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\uiskillcompactcontroldialog.cpp
// MS2-RANGE: 0x1400e1660-0x1400e18a0 .text$di
// MS2-RANGE: 0x140f9e200-0x140fa3b10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?IsNull@?$MS2Ptr@VCSkillCompactControlConfig@@@@QEBA_NXZ 0x140fa3090 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCSkillCompactControlConfig@@@@QEBAPEAVCSkillCompactControlConfig@@XZ 0x140fa30c0 ; unique
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$MS2Ptr@VCSkillCompactControlConfig@@@@V?$CElementTraits@V?$MS2Ptr@VCSkillCompactControlConfig@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x140fa34b0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiskillcompactcontroldialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiskillcompactcontroldialog.h"

#include <algorithm>
#include <set>

#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/skillsystem.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/skillcompactcontroltable.h"
#include "ms2/commonfiles/skillconfig.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- header statics (dynamic initializers 0x1400e1660..0x1400e17d0; the same group as uiskillbookautodistributedialog.cpp) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#endif

// The key being captured while the player presses a key for a tab (the second press is the confirm).
static int DAT_143acbd08;

// ---- unit-local views of exe objects ----

typedef Delegate<bool(int, const CMsgBoxData&)> ScBoxDelegate;

// The local player and the world (FUN_1403ed2d0 -> FUN_141bd0cc0).
class Unk_ScWorld { public: MyPC* FUN_141bd0cc0(); };
Unk_ScWorld* FUN_1403ed2d0();

// The learned skills of the player: slot 2 is "the skill is learned".
class Unk_ScLearned : public CPtred { public: int FUN_140637e00(); };
class Unk_ScSkillBook
{
public:
    virtual void v0();
    virtual void v1();
    virtual bool vfunc_2(int nSkillId);
    MS2Ptr<Unk_ScLearned> FUN_1406394d0(int nSkillId);              // the learned record of a skill
};
class Unk_ScPc : public MyPC { public: Unk_ScSkillBook* FUN_1416546d0(); };
int FUN_141654700(MyPC* pPc);                                       // the player's job
int FUN_141654730(MyPC* pPc);                                       // the player's sub job
class Unk_ScJobTable { public: int FUN_140644b80(int nJobCode); };  // the job level
Unk_ScJobTable* FUN_1401d7a50();

// A skill row of the skill table (the icon path at +0x48). View only.
class Unk_ScSkillRow
{
public:
    unsigned char m_pad_00[0x48];
    CString m_strIcon;                                              // +0x48
};
MS2_CHECK_OFFSET(Unk_ScSkillRow, m_strIcon, 0x48);
void FUN_14063e5c0(void* p);
struct Unk_ScSkillRef
{
    ~Unk_ScSkillRef() { FUN_14063e5c0(this); }
    Unk_ScSkillRow* FUN_14063ed10() const;                          // operator->
    void* m_0; void* m_8;
};
class Unk_ScSkillTable { public: Unk_ScSkillRef FUN_1407ee1d0(int nSkillId); };
Unk_ScSkillTable* FUN_1401958b0();

// The key bindings.
class Unk_ScKeys
{
public:
    int FUN_14142e470(int n);                                       // the key that is pressed now
    int FUN_14142e340(int n);                                       // the key that was released
    int FUN_141430b90(int nKey);
    int FUN_141430cb0(int nKey);
    int FUN_1414319f0();                                            // the key set (2 = the second one)
    int FUN_14142cc40(int nKey);                                    // the key may be bound
    __int64 FUN_14142d190(int nKey);                                // the action bound to a key (0 = none)
    int FUN_14142cf10(unsigned __int64 nAction);
    int FUN_141430470(unsigned __int64 nAction);
    int FUN_14142c940(unsigned __int64 nAction, int nSet);          // the key of an action
    CStringW FUN_14142d220(int nKey);                               // the text of a key
    int FUN_14142b250(int nKey, int a, unsigned __int64 nAction, int b, int nSet);
    void FUN_14142a8b0(unsigned __int64 nAction);
};
Unk_ScKeys* FUN_1409331f0();

// The hot key label of the movie and the tab buttons.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422cdfb0(const CStringW& strLabel);                   // the button text
    void FUN_1422c7630(int n);                                      // focus
    MS2Ptr<ASDisplayObject> FUN_1422ce400();                        // the key cap child
};
class Unk_SkillButtonBar : public ASDisplayObject
{
public:
    void FUN_1422e3400();                                           // remove all tabs
};
class Unk_SkillScriptView : public AScript { public: MS2Ptr<Unk_SkillButtonBar> FUN_140be23c0(const CString& strName); };
class Unk_ScButtonView : public AScript { public: MS2Ptr<Unk_140acd6e0> FUN_140acce30(const CString& strName); };
void FUN_140d01340(const Scaleform::GFx::Value& root, int a, int b);

// The movie root of the dialog (RTTI .?AVASDialog@@).
class ASDialog : public ASDisplayObject {};

// The platform request (the "renameTab" / "AddTab" answers) and its value.
class Unk_ScRequest
{
public:
    Unk_ScRequest(int nId);                                         // 0x1401baa00
    Unk_ScRequest(const void* pSource);                             // 0x1401baaa0
    ~Unk_ScRequest();                                               // 0x1401baaf0
    void FUN_1401bac80(CString strName, CStringW strValue, int n);
    void FUN_1401badc0(bool bEnabled);
    unsigned char FUN_1401bab90(CString strName, void* pOut);
private:
    void* m_pad[5];                                                 // ctor 0x1401baa00 writes +0x18 / +0x1c / +0x20
};
struct Unk_ScReqValue
{
    Unk_ScReqValue();                                               // 0x1401ba840
    ~Unk_ScReqValue();                                              // 0x1401ba940
    void* m_pad_00;
    CStringW m_strText;                                             // +0x08
    void* m_pad_10;
    int m_code;                                                     // +0x18
    int m_pad_1c;
};
MS2_CHECK_SIZE(Unk_ScReqValue, 0x20);                               // ctor 0x1401ba840: strings at +0 / +8 / +0x10

IClientPlatform* FUN_140d86260();
CStringW FUN_1409eec40(int nStringId);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& strArg0, const CStringW& strArg1);
CStringW FUN_14028de60(int nId);
CStringTable* FUN_1401a9d70();
void FUN_140d73aa0(CStringW text, int nType, IMessageListener* pListener, CStringW tag);
void FUN_140d73bc0(int nStringId, int nType, int n, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nA, int nB, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
UIMessageBox* FUN_14151f890();
void FUN_14151f200();
void FUN_140710590(COutPacket& packet);
int FUN_1409e1b80(ASTooltip* p, int nId, int n);                    // the learned skill tooltip
void FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);    // pRetVal = v

// ---- the hot key state ----

Unk_ScHotKeyState::Unk_ScHotKeyState()
{
    Clear();
}

void Unk_ScHotKeyState::Clear()
{
    m_nKey = 0;
    m_nState = 0;
    m_strTab.Empty();
}

int Unk_ScHotKeyState::FUN_140fa35d0() const
{
    return !m_strTab.IsEmpty();
}

// ---- the dialog ----

// @0x140f9e200
UISkillCompactControlDialog::UISkillCompactControlDialog()
    : m_lstConfig(10)
{
    m_spButtonBar = 0;
    m_spAddButton = 0;
    m_bLoaded = 0;
    FUN_141924170(1);
}

// MS2-FUNCTIONAL: typed source, behaviour-equivalent; bytes not matched yet
// @0x140fa2f80
UISkillCompactControlDialog::~UISkillCompactControlDialog()
{
}

// @0x140f9e330
CString UISkillCompactControlDialog::vfunc_1()
{
    return CString("SkillCompactControl");
}

// MS2-FUNCTIONAL: typed source, behaviour-equivalent; bytes not matched yet
// @0x140f9e380
int UISkillCompactControlDialog::vfunc_65()
{
    int nResult = UIDialog::vfunc_65();
    if (nResult != 0)
        m_cur.Clear();
    return nResult != 0;
}

// @0x140f9e3c0
void UISkillCompactControlDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        pPlayer->FUN_141523bc0()->FUN_141767df0(0);
    FUN_140fa1400();
    SendSkillMacroMode1();
    m_bLoaded = 0;
}

// @0x140f9e430
int UISkillCompactControlDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0 && pSender == dynamic_cast<UIMessageBox*>(pSender))
    {
        int nResult = pMsg->FUN_1422b8a10();
        FUN_14151f200();
        if (nResult == 0)
        {
            __int64 nId = FUN_140fa2520(CStringW(m_cur.m_strTab));
            FUN_140fa23f0(m_cur.m_nKey, nId);
            FUN_140fa2180(CStringW(m_cur.m_strTab));
        }
        else
        {
            __int64 nId = FUN_140fa2520(CStringW(m_prev.m_strTab));
            FUN_140fa23f0(m_prev.m_nKey, nId);
            FUN_140fa2180(CStringW(m_cur.m_strTab));
        }
        m_cur.Clear();
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
            pPlayer->FUN_141523bc0()->FUN_141767df0(0);
    }
    return 1;
}

// @0x140f9e690
void UISkillCompactControlDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
}

// @0x140f9e6b0
void UISkillCompactControlDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spButtonBar = 0;
    m_spAddButton = 0;
}

// The key capture: the pressed key is shown for the tab, a bound key asks first.
// MS2-FUNCTIONAL: typed source, behaviour-equivalent; bytes not matched yet
// @0x140f9e700
int UISkillCompactControlDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    if (m_cur.m_nState != 0)
        return 0;
    if (m_cur.FUN_140fa35d0())
    {
        bool bGot = false;
        int nKey;
        int nPressed = FUN_1409331f0()->FUN_14142e470(0);
        if (nPressed == 0)
        {
            nKey = FUN_1409331f0()->FUN_14142e340(0);
            if (nKey == 0)
            {
                if (DAT_143acbd08 != 0)
                {
                    if (FUN_1409331f0()->FUN_141430b90(DAT_143acbd08) != 0)
                    {
                        DAT_143acbd08 = 0;
                        return 0;
                    }
                    nKey = DAT_143acbd08;
                    DAT_143acbd08 = 0;
                    bGot = true;
                }
            }
            else
            {
                DAT_143acbd08 = 0;
                bGot = true;
            }
        }
        else
        {
            nKey = FUN_1409331f0()->FUN_14142e340(0);
            if (nPressed == nKey)
            {
                if (nPressed != DAT_143acbd08)
                    DAT_143acbd08 = nPressed;
                return 0;
            }
            if (FUN_1409331f0()->FUN_141430cb0(nKey) != 0)
            {
                DAT_143acbd08 = 0;
                return 0;
            }
            if (nKey == 0)
            {
                if (nPressed != DAT_143acbd08)
                    DAT_143acbd08 = nPressed;
                return 0;
            }
            DAT_143acbd08 = 0;
            bGot = true;
        }
        if (bGot && nKey != 0)
        {
            int nSet = FUN_1409331f0()->FUN_1414319f0();
            if (nSet == 2)
            {
                if (nKey < 0x91)
                {
                    FUN_140d73aa0(FUN_1409eec40(0x855), 0, static_cast<IMessageListener*>(this), CStringW(L""));
                    return 0;
                }
            }
            else if (0x91 < nKey)
            {
                FUN_140d73aa0(FUN_1409eec40(0x854), 0, static_cast<IMessageListener*>(this), CStringW(L""));
                return 0;
            }
            if (FUN_1409331f0()->FUN_14142cc40(nKey) == 0)
            {
                m_cur.Clear();
                FUN_140d73bc0(0x84c, 0, 0, CStringW(L""));
            }
            else if (FUN_140fa23a0(nKey) == 0)
            {
                m_cur.m_nState = 1;
                m_cur.m_nKey = nKey;
                unsigned __int64 nAction = FUN_1409331f0()->FUN_14142d190(nKey);
                CStringW strName;
                if (FUN_1409331f0()->FUN_14142cf10(nAction) == 0)
                    strName = FUN_1401a9d70()->FUN_1418125b0((unsigned)nAction);
                else
                    strName = FUN_140656190(L"{0}[{1}]", FUN_1401a9d70()->FUN_1418125b0((unsigned)nAction),
                                            FUN_1409331f0()->FUN_14142d220(nKey));
                if (FUN_1409331f0()->FUN_141430470(nAction) == 0)
                {
                    FUN_140d73aa0(FUN_14052bd00(0x84f, strName), 1, static_cast<IMessageListener*>(this), CStringW(L""));
                }
                else
                {
                    if (FUN_140fa23f0(nKey, FUN_140fa2520(CStringW(m_cur.m_strTab))) != 0)
                    {
                        FUN_140fa2180(CStringW(m_cur.m_strTab));
                        m_cur.Clear();
                    }
                    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
                    if (pPlayer != 0)
                        pPlayer->FUN_141523bc0()->FUN_141767df0(0);
                }
            }
            else
            {
                if (FUN_140fa23f0(nKey, FUN_140fa2520(CStringW(m_cur.m_strTab))) != 0)
                {
                    FUN_140fa2180(CStringW(m_cur.m_strTab));
                    m_cur.Clear();
                }
            }
            return 1;
        }
    }
    return UIDialog::vfunc_13();
}

// MS2-FUNCTIONAL: typed source, behaviour-equivalent; bytes not matched yet
// @0x140f9ef80
int UISkillCompactControlDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (m_bLoaded == 0)
        return 0;
    if (_stricmp(szMethod, "onChangeTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_strTab = data.FUN_1422b8f40();
            FUN_140fa16f0(CStringW(m_strTab));
            FUN_140fa2180(CStringW(m_strTab));
        }
    }
    else if (_stricmp(szMethod, "onClickCompactControlCheckbox") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned nSkillId = data.FUN_1422b8a10();
            bool bOn = data.FUN_1422b8a90();
            MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_strTab));
            if (spConfig.get() != 0)
            {
                if (bOn)
                    spConfig->m_skills.insert(nSkillId);
                else
                    spConfig->m_skills.erase(nSkillId);
            }
        }
        FUN_140fa1400();
    }
    else if (_stricmp(szMethod, "onRemoveTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strName = data.FUN_1422b8f40();
            __int64 nId = FUN_140fa2520(CStringW(strName));
            int nKey = FUN_1409331f0()->FUN_14142c940(nId, 0);
            FUN_140fa23f0(nKey, 0);
            FUN_140fa29f0(CStringW(strName));
        }
        FUN_140fa1400();
    }
    else if (_stricmp(szMethod, "onHotKeyFocusIn") == 0)
    {
        m_cur.Clear();
        m_cur.m_strTab = m_strTab;
        int nSet = FUN_1409331f0()->FUN_1414319f0();
        int nKey = FUN_1409331f0()->FUN_14142c940(FUN_140fa2520(CStringW(m_strTab)), nSet);
        m_prev.Clear();
        m_prev.m_nKey = nKey;
        m_prev.m_strTab = m_strTab;
        FUN_140fa23f0(nKey, 0);
        MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer != 0)
            pPlayer->FUN_141523bc0()->FUN_141767df0(1);
    }
    else if (_stricmp(szMethod, "onHotKeyFocusOut") == 0)
    {
        if (m_cur.m_nState == 0)
        {
            m_cur.Clear();
            MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pPlayer != 0)
                pPlayer->FUN_141523bc0()->FUN_141767df0(0);
        }
    }
    else if (_stricmp(szMethod, "onRenameTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strName = data.FUN_1422b8f40();
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(10, 0xc37, 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                m_strRename = strName;
                spBox->FUN_141a01d30(0, strName, 5, 0, 0);
                spBox->FUN_141a027c0(ScBoxDelegate(this, &UISkillCompactControlDialog::FUN_140fa0820));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp(szMethod, "onAddTab") == 0)
    {
        if (m_lstConfig.GetCount() < 3)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(10, 0xc36, 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_141a01d30(0, CStringW(), 5, 0, 0);
                spBox->FUN_141a027c0(ScBoxDelegate(this, &UISkillCompactControlDialog::FUN_140fa0d80));
                FUN_140d73c60(spBox);
            }
        }
    }
    else if (_stricmp(szMethod, "onResetHotKey") == 0)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_strTab));
        if (spConfig.get() != 0)
        {
            spConfig->m_skills.clear();
            FUN_140fa16f0(CStringW(m_strTab));
        }
        m_cur.Clear();
        m_cur.m_strTab = m_strTab;
        int nKey = FUN_1409331f0()->FUN_14142c940(FUN_140fa2520(CStringW(m_strTab)), 0);
        FUN_140fa23f0(nKey, 0);
        FUN_140fa2180(CStringW(m_strTab));
        FUN_140fa1400();
    }
    else if (_stricmp(szMethod, "OnSelectAll") == 0)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_strTab));
        if (spConfig.get() != 0)
        {
            spConfig->m_skills.clear();
            ATL::CAtlList<unsigned> lstSkills(10);
            FUN_140fa1460(&lstSkills);
            POSITION pos = lstSkills.GetHeadPosition();
            while (pos != 0)
            {
                unsigned nSkillId = lstSkills.GetAt(pos);
                spConfig->m_skills.insert(nSkillId);
                lstSkills.GetNext(pos);
            }
            FUN_140fa16f0(CStringW(m_strTab));
        }
        FUN_140fa1400();
    }
    return 0;
}

// @0x140fa35c0
int UISkillCompactControlDialog::vfunc_48()
{
    return 0x4ef6;
}

// The tooltip of a skill row.
// @0x140f9fdb0
void UISkillCompactControlDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CString strName = pArgs->FUN_1422b8d30();
    if (strName.Find("compactSkill", 0) != -1)
    {
        int nSkillId = pArgs->FUN_1422b8a10();
        ASTooltip tip(pPlayer, 0x10, 2);
        if (FUN_1409e1b80(&tip, nSkillId, 0) != 0)
        {
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
            return;
        }
    }
}

// The tabs from the server.
// MS2-FUNCTIONAL: typed source, behaviour-equivalent; bytes not matched yet
// @0x140f9fee0
void UISkillCompactControlDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    CInPacket& packet = *static_cast<CInPacket*>(pPacket);
    if (packet.FUN_14070fe80() != 0xd1)
        return;
    if (packet.vfunc_o8_1() != 0)
        return;
    m_lstConfig.RemoveAll();
    CStringW strFirst;
    unsigned nTabs = packet.vfunc_o8_3();
    for (unsigned i = 0; i < nTabs; i++)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig(new CSkillCompactControlConfig());
        spConfig->m_strName = packet.vfunc_o8_8();
        spConfig->m_30 = packet.vfunc_o8_4();
        unsigned nSkills = packet.vfunc_o8_3();
        for (unsigned j = 0; j < nSkills; j++)
        {
            unsigned nSkillId = packet.vfunc_o8_3();
            spConfig->m_skills.insert(nSkillId);
        }
        m_lstConfig.AddTail(spConfig);
        if (strFirst.IsEmpty())
            strFirst = spConfig->m_strName;
    }
    if (m_lstConfig.IsEmpty())
    {
        strFirst = FUN_14028de60(0xc39);
        FUN_140fa2720(CStringW(strFirst));
    }
    FUN_140fa1ff0();
    m_strTab = strFirst;
    if (m_30.get() != 0)
        m_30->Invoke("selectTab", CStringW(m_strTab));
    FUN_140fa16f0(CStringW(strFirst));
    FUN_140fa2180(CStringW(strFirst));
    m_bLoaded = 1;
}

// The platform answers of the web side tab requests.
// @0x140fa0420
void UISkillCompactControlDialog::vfunc_80(void* pRequest)
{
    Unk_ScRequest req(pRequest);
    Unk_ScReqValue val;
    if (req.FUN_1401bab90(CString("renameTab"), &val) == 1)
    {
        if (val.m_code == 0)
            FUN_140fa0a20(CStringW(val.m_strText));
        else
            FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
    }
    else if (req.FUN_1401bab90(CString("AddTab"), &val) == 1)
    {
        if (val.m_code == 0)
            FUN_140fa0fa0(CStringW(val.m_strText));
        else
            FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
    }
}

// @0x140fa06a0
void UISkillCompactControlDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0)
    {
        m_spButtonBar = static_cast<Unk_SkillScriptView*>(m_30.operator->())->FUN_140be23c0("m_buttonBar");
        m_spAddButton = static_cast<Unk_ScButtonView*>(m_30.operator->())->FUN_140acce30("m_addButton");
    }
    COutPacket packet(0x7b, 0);
    packet.Encode1(0);
    FUN_140710590(packet);
}

// The answer of the rename box: the new name travels to the platform first.
// @0x140fa0820
bool UISkillCompactControlDialog::FUN_140fa0820(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        CStringW strText = data.FUN_141a02d50();
        strText = strText.Mid(strText.Find(L',', 0) + 1);
        if (strText.IsEmpty())
            return 0;
        Unk_ScRequest req(0x4ef6);
        req.FUN_1401bac80(CString("renameTab"), CStringW(strText), 0);
        req.FUN_1401badc0(1);
        if (FUN_140d86260()->vfunc_37(&req) == 1)
            return FUN_140fa0a20(CStringW(strText));
    }
    return 1;
}

// @0x140fa0a20
bool UISkillCompactControlDialog::FUN_140fa0a20(CStringW strName)
{
    if (strName.IsEmpty())
        return 0;
    MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strName));
    if (spConfig.get() != 0)
    {
        UIMessageBox* pBox = FUN_14151f890();
        if (pBox != 0)
            pBox->FUN_1419f82b0(FUN_14028de60(0xc38));
        return 0;
    }
    FUN_14151f200();
    spConfig = FUN_140fa28b0(CStringW(m_strRename));
    if (spConfig.IsNull())
        return 0;
    spConfig->m_strName = strName;
    if (m_30.get() != 0)
        m_30->Invoke("renameTab", CStringW(m_strRename), CStringW(strName));
    FUN_140fa16f0(CStringW(strName));
    return 1;
}

// The answer of the add tab box.
// @0x140fa0d80
bool UISkillCompactControlDialog::FUN_140fa0d80(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        if (m_lstConfig.GetCount() >= 3)
            return 0;
        CStringW strText = data.FUN_141a02d50();
        strText = strText.Mid(strText.Find(L',', 0) + 1);
        if (strText.IsEmpty())
            return 0;
        Unk_ScRequest req(0x4ef6);
        req.FUN_1401bac80(CString("AddTab"), CStringW(strText), 0);
        req.FUN_1401badc0(1);
        if (FUN_140d86260()->vfunc_37(&req) == 1)
            return FUN_140fa0fa0(CStringW(strText));
    }
    return 1;
}

// @0x140fa0fa0
bool UISkillCompactControlDialog::FUN_140fa0fa0(CStringW strName)
{
    if (strName.IsEmpty())
        return 0;
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strName));
        if (spConfig.get() != 0)
        {
            UIMessageBox* pBox = FUN_14151f890();
            if (pBox != 0)
                pBox->FUN_1419f82b0(FUN_14028de60(0xc38));
            return 0;
        }
    }
    FUN_14151f200();
    m_strTab = strName;
    FUN_140fa2720(CStringW(strName));
    FUN_140fa16f0(CStringW(strName));
    if (m_30.get() != 0)
        m_30->Invoke("AddTab", CStringW(strName), 1);
    return 1;
}

// The tabs back to the server.
// @0x140fa1240
void UISkillCompactControlDialog::SendSkillMacroMode1()
{
    COutPacket packet(0x7b, 0);
    packet.Encode1(1);
    packet.Encode4(m_lstConfig.GetCount());
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        packet.vfunc_o10_8(spConfig->m_strName);
        packet.Encode8(spConfig->m_30);
        packet.Encode4(spConfig->m_skills.size());
        for (std::set<unsigned>::iterator it = spConfig->m_skills.begin(); it != spConfig->m_skills.end(); ++it)
            packet.Encode4(*it);
    }
    FUN_140710590(packet);
}

// @0x140fa1400
void UISkillCompactControlDialog::FUN_140fa1400()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        pPlayer->FUN_141523bc0()->FUN_141767d90(&m_lstConfig);
}

// The exe's out-of-line IsNull COMDAT of the list pointer (0x140fa3060, shared by ICF).
static __declspec(noinline) bool Unk_CcSkillListIsNull(const Unk_CcSkillListPtr& sp)
{
    return sp.get() == 0;
}

// The skills of the player's job: the learnable ones first, then the others.
// @0x140fa1460
void UISkillCompactControlDialog::FUN_140fa1460(ATL::CAtlList<unsigned>* pList)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    Unk_CcSkillListPtr spSkills = CSkillCompactControlTable::GetJobSkills((Unk_CcJob)FUN_141654700(pPlayer));
    if (Unk_CcSkillListIsNull(spSkills))
        return;
    std::set<unsigned> setLearned;
    std::set<unsigned> setOther;
    for (POSITION pos = spSkills->GetHeadPosition(); pos != 0; spSkills->GetNext(pos))
    {
        Unk_CcSkillPtr spSkill = spSkills->GetAt(pos);
        int bLearned = static_cast<Unk_ScPc*>(pPlayer)->FUN_1416546d0()->vfunc_2(spSkill->m_nSkillId);
        if (bLearned)
            setLearned.insert(spSkill->m_nSkillId);
        else
            setOther.insert(spSkill->m_nSkillId);
    }
    for (std::set<unsigned>::iterator it = setLearned.begin(); it != setLearned.end(); ++it)
        pList->AddTail(*it);
    for (std::set<unsigned>::iterator it = setOther.begin(); it != setOther.end(); ++it)
        pList->AddTail(*it);
}

// Rebuild the skill list of the movie for a tab.
// MS2-FUNCTIONAL: typed source, behaviour-equivalent; bytes not matched yet
// @0x140fa16f0
void UISkillCompactControlDialog::FUN_140fa16f0(CStringW strTab)
{
    MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strTab));
    if (spConfig.IsNull())
        spConfig = FUN_140fa2720(CStringW(strTab));
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    Unk_CcSkillListPtr spSkills = CSkillCompactControlTable::GetJobSkills((Unk_CcJob)FUN_141654700(pPlayer));
    if (!spSkills)
        return;
    ASArray arrSkills(2);
    std::set<unsigned> setLearned;
    std::set<unsigned> setOther;
    int nJobLevel = FUN_1401d7a50()->FUN_140644b80(FUN_141654730(pPlayer));
    POSITION pos = spSkills->GetHeadPosition();
    while (pos != 0)
    {
        Unk_CcSkillPtr spSkill = spSkills->GetAt(pos);
        MS2Ptr<Unk_ScLearned> spLearned = static_cast<Unk_ScPc*>(pPlayer)->FUN_1416546d0()->FUN_1406394d0(spSkill->m_nSkillId);
        if (spLearned.IsNull() == 0)
        {
            if (nJobLevel >= spLearned->FUN_140637e00())
            {
                if (static_cast<Unk_ScPc*>(pPlayer)->FUN_1416546d0()->vfunc_2(spSkill->m_nSkillId) == 0)
                    setOther.insert(spSkill->m_nSkillId);
                else
                    setLearned.insert(spSkill->m_nSkillId);
            }
        }
        spSkills->GetNext(pos);
    }
    for (std::set<unsigned>::iterator it = setLearned.begin(); it != setLearned.end(); ++it)
    {
        unsigned nSkillId = *it;
        Unk_ScSkillRef ref = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        Unk_ScSkillRow* pRow = ref.FUN_14063ed10();
        if (pRow != 0)
        {
            bool bSelected = spConfig->m_skills.find(nSkillId) != spConfig->m_skills.end();
            ASObj obj(2);
            obj.FUN_1407cb9c0("disable", 0);
            obj.FUN_1409c0d20("skillID", nSkillId);
            obj.FUN_1407cba60("iconPath", CString(pRow->m_strIcon));
            obj.FUN_1407cb9c0("selected", bSelected);
            arrSkills.FUN_1422bbf00(obj);
        }
    }
    for (std::set<unsigned>::iterator it = setOther.begin(); it != setOther.end(); ++it)
    {
        unsigned nSkillId = *it;
        Unk_ScSkillRef ref = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        Unk_ScSkillRow* pRow = ref.FUN_14063ed10();
        if (pRow != 0)
        {
            bool bSelected = spConfig->m_skills.find(nSkillId) != spConfig->m_skills.end();
            ASObj obj(2);
            obj.FUN_1407cb9c0("disable", 1);
            obj.FUN_1409c0d20("skillID", nSkillId);
            obj.FUN_1407cba60("iconPath", CString(pRow->m_strIcon));
            obj.FUN_1407cb9c0("selected", bSelected);
            arrSkills.FUN_1422bbf00(obj);
        }
    }
    pDialog->FUN_140bd2cb0("buildSkills", arrSkills);
    pDialog->Invoke("selectTab", CStringW(strTab));
}

// @0x140fa1ff0
void UISkillCompactControlDialog::FUN_140fa1ff0()
{
    if (m_lstConfig.IsEmpty())
        return;
    if (m_spButtonBar.IsNull())
        return;
    m_spButtonBar->FUN_1422e3400();
    int nIndex = 0;
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        m_30->Invoke("AddTab", CStringW(spConfig->m_strName), nIndex);
        if (nIndex == 0)
            nIndex = 1;
    }
}

// The hot key label of the tab.
// @0x140fa2180
void UISkillCompactControlDialog::FUN_140fa2180(CStringW strTab)
{
    int nKey = FUN_1409331f0()->FUN_14142c940(FUN_140fa2520(CStringW(strTab)), FUN_1409331f0()->FUN_1414319f0());
    MS2Ptr<Unk_140acd6e0> spHotKey = static_cast<Unk_ScButtonView*>(m_30.operator->())->FUN_140acce30("m_hotKey");
    if (spHotKey)
    {
        CStringW strKey = FUN_1409331f0()->FUN_14142d220(nKey);
        spHotKey->FUN_1422cdfb0(strKey);
        spHotKey->FUN_1422c7630(0);
        if (nKey > 0x91)
            FUN_140d01340(spHotKey->FUN_1422ce400()->FUN_1422bb890(), 1, 2);
        else
            FUN_140d01340(spHotKey->FUN_1422ce400()->FUN_1422bb890(), 2, 2);
    }
}

// The key is not bound to an action yet.
// @0x140fa23a0
int UISkillCompactControlDialog::FUN_140fa23a0(int nKey)
{
    return FUN_1409331f0()->FUN_14142d190(nKey) == 0;
}

// @0x140fa23f0
int UISkillCompactControlDialog::FUN_140fa23f0(int nKey, __int64 nId)
{
    int nSet = FUN_1409331f0()->FUN_1414319f0();
    if (FUN_1409331f0()->FUN_14142b250(nKey, 2, nId, 0, nSet) != 0)
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(m_cur.m_strTab));
        if (spConfig.IsNull() != 0)
            return 0;
        spConfig->m_30 = nId;
        FUN_1409331f0()->FUN_14142a8b0(nId);
        FUN_140fa1400();
        return 1;
    }
    return 0;
}

// The id of the tab's action: its own, else the first free one of the three.
// @0x140fa2520
__int64 UISkillCompactControlDialog::FUN_140fa2520(CStringW strTab)
{
    MS2Ptr<CSkillCompactControlConfig> spConfig = FUN_140fa28b0(CStringW(strTab));
    if (spConfig.IsNull() != 0)
        return 0;
    if (spConfig->m_30 != 0)
        return spConfig->m_30;
    for (unsigned nId = 0xaae61; nId <= 0xaae63; nId++)
    {
        BOOL bUsed = FALSE;
        for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
        {
            spConfig = m_lstConfig.GetAt(pos);
            if (spConfig->m_30 == nId)
            {
                bUsed = TRUE;
                break;
            }
        }
        if (!bUsed)
            return nId;
    }
    return 0;
}

// @0x140fa2720
MS2Ptr<CSkillCompactControlConfig> UISkillCompactControlDialog::FUN_140fa2720(CStringW strName)
{
    MS2Ptr<CSkillCompactControlConfig> spConfig(new CSkillCompactControlConfig());
    spConfig->m_strName = strName;
    {
        ATL::CAtlList<unsigned> lstSkills(10);
        FUN_140fa1460(&lstSkills);
        for (POSITION pos = lstSkills.GetHeadPosition(); pos != 0; lstSkills.GetNext(pos))
            spConfig->m_skills.insert(lstSkills.GetAt(pos));
    }
    m_lstConfig.AddTail(spConfig);
    return spConfig;
}

// @0x140fa28b0
MS2Ptr<CSkillCompactControlConfig> UISkillCompactControlDialog::FUN_140fa28b0(CStringW strName)
{
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        if (spConfig->m_strName.CompareNoCase(strName) == 0)
            return spConfig;
    }
    return MS2Ptr<CSkillCompactControlConfig>(0);
}

// @0x140fa29f0
void UISkillCompactControlDialog::FUN_140fa29f0(CStringW strName)
{
    for (POSITION pos = m_lstConfig.GetHeadPosition(); pos != 0; m_lstConfig.GetNext(pos))
    {
        MS2Ptr<CSkillCompactControlConfig> spConfig = m_lstConfig.GetAt(pos);
        if (spConfig->m_strName.CompareNoCase(strName) == 0)
        {
            m_lstConfig.RemoveAt(pos);
            return;
        }
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caa420-0x142caa4e0 .text$yd
