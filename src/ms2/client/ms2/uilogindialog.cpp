// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Login dialog (account / password input of the login scene).
// MS2-UNIT: ?\uilogindialog.cpp
// MS2-RANGE: 0x140115ee0-0x140116000 .text$di
// MS2-RANGE: 0x1419e0cb0-0x1419e3510 .text$mn
// MS2-RANGE: 0x142cbf250-0x142cbf2c0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUILoginDialog@@P80@EAAXAEAVCInPacket@@@Z@std@@YA_NAEBU?$pair@PEAVUILoginDialog@@P81@EAAXAEAVCInPacket@@@Z@0@0@Z 0x1419e2b50 ; prop
// MS2-PIN: ??$?8PEAVUILoginDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUILoginDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1419e2bc0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUILoginDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x1419e2e40 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUILoginDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419e3180 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUILoginDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419e31e0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUILoginDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419e3330 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUILoginDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419e3390 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uilogindialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uilogindialog.h"
#include "uiscenelogin.h"
#include "uimessagebox.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static CString s_pendingId;
static CString s_sortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local views of exe types ----

// The text input children ("m_inputID" / "m_inputPW").
class Unk_LoginInput : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                                   // the text
    void FUN_1422e1500(int n1, int n2);                         // set the selection
};

// The "m_chkLocaledName" check box.
class Unk_LoginCheck : public ASDisplayObject
{
public:
    void FUN_1422ce090(int bChecked);
    unsigned char FUN_1422ce0e0();
};

// The movie root (m_30) with the child lookups and the 4-argument invoke the dialog uses.
class Unk_LoginRoot : public AScript
{
public:
    template <class T> MS2Ptr<T> FUN_140c11f50(const CString& strName);
    template <class T> MS2Ptr<T> FUN_140bbe880(const CString& strName);
    Scaleform::GFx::Value FUN_1419e2c30(const char* szMethod, CString strId, bool bSaveId, bool bFlag, CString strRegion);
};

// The stored login options (FUN_1409a8b10 -> FUN_140cfd260).
class Unk_LoginOptions
{
public:
    void FUN_141260e00(bool bLocaledName);
    void* m_00; void* m_08; void* m_10;
    CString m_strSavedId;                                       // +0x18
    void* m_20; void* m_28;
    bool m_bSaveId;                                             // +0x30
    bool m_bLocaledName;                                        // +0x31
};
class Unk_LoginOptionsHolder { public: Unk_LoginOptions* FUN_140cfd260(); };
Unk_LoginOptionsHolder* FUN_1409a8b10();

void* FUN_14067c020(void* pId);                                 // zero-inits the 16-byte id
// The login request packet body (encoded by 0x1401f9020).
struct Unk_LoginMachineId
{
    Unk_LoginMachineId() { FUN_14067c020(this); }
    unsigned char m_data[16];
};
struct Unk_LoginRequest
{
    Unk_LoginRequest();                                         // 0x1419e2f80
    ~Unk_LoginRequest();                                        // 0x1419e3060
    unsigned m_nType;                                           // +0x00
    CString m_strId;                                            // +0x08
    CString m_strPassword;                                      // +0x10
    unsigned m_nLoginType;                                      // +0x18
    Unk_LoginMachineId m_machineId;                             // +0x1c
    int m_n2c;                                                  // +0x2c
    int m_n30;                                                  // +0x30
    CString m_strRegion;                                        // +0x38
};
MS2_CHECK_SIZE(Unk_LoginRequest, 0x40);
void FUN_1401f9020(Unk_LoginRequest* pRequest, COutPacket* pOut);
class Unk_LoginMachine
{
public:
    const Unk_LoginMachineId& FUN_140d4fdf0();
    int FUN_140d4fe10();
};
Unk_LoginMachine* FUN_140aadf70();
void FUN_14067c080(Unk_LoginMachineId* pDst, const Unk_LoginMachineId& src);

// The packet handler table and the message boxes.
class Unk_LoginPackets { public: void FUN_140da5180(int, Delegate<void(CInPacket&)>); void FUN_140da51e0(int, Delegate<void(CInPacket&)>); };
Unk_LoginPackets* FUN_140bccd50();
class Unk_LoginMsgBox : public CPtred
{
public:
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>);
};
MS2Ptr<Unk_LoginMsgBox> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);   // create a message box
void FUN_140d73c60(MS2Ptr<Unk_LoginMsgBox> box);                // show it
MS2Ptr<Unk_LoginMsgBox> FUN_140d74390(CStringW strText, int nUnk, Delegate<bool(int, const CMsgBoxData&)> cb);
class Unk_LoginNotice { public: void FUN_140d73aa0(CStringW strText, int a, int b, CStringW strTag); };
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
void FUN_140d73aa0(CStringW strText, int a, void* b, CStringW strTag);
void FUN_140710590(COutPacket& packet);                         // send the packet

class Unk_LoginKeys { public: char FUN_14116d9c0(int nKey, int a, int b); };
Unk_LoginKeys* FUN_14025e7c0();

// The scene manager and the web page opener.
void* FUN_1408e57f0();
__int64 FUN_140869440();                                        // the server time
int FUN_1418fc810();
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
int FUN_1422b9dc0(void* pMgr);                                  // the current scene id
UISceneEntity* FUN_1422b9e80(void* pMgr);                       // the current scene
void* FUN_140aa6d30();
int FUN_1417e2610(void* pObj);
void FUN_141acfad0(UISceneLogin* pScene, const int& nUiId);     // UISceneLogin: hide the title and the dialogs
class Unk_LoginBrowser { public: void FUN_1415383a0(CString strUrl, int n, int a, int b, int c); };
Unk_LoginBrowser* FUN_140714f90();
int FUN_1406c34c0();                                            // the platform kind
IClientPlatform* FUN_140d86260();
int FUN_1406516a0();
int FUN_1406516b0();                                            // the language / region id
CString FUN_1406521f0(int nRegion);
CString FUN_1401d2b10(const CString& a, const CString& b);              // a + b
CString FUN_140652030(int n);
CString FUN_14016a600(const wchar_t* psz, int nCodePage);
class Unk_LoginUiMgr { public: int FUN_141adc890(int nUiId); };
Unk_LoginUiMgr* FUN_1403ed2b0();
class Unk_LoginMovie : public AScript
{
public:
    int FUN_1422b9620();
};
void FUN_140ba7c60();

extern CString DAT_143ae0928;                                   // the web page address
extern int DAT_143ae08f4;
extern CString DAT_143ab29d8;                                   // the last typed account id
extern CString DAT_143ab2a28;                                   // the last typed password
extern char DAT_143ab284b;
extern int DAT_143ab2858;
extern int DAT_143ab285c;
extern int DAT_143ab2860;
extern __int64 DAT_143ab2820;
extern char DAT_143ab2946;

// @0x1419e0cb0
UILoginDialog::UILoginDialog()
{
    m_80 = 0;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
    FUN_140bccd50()->FUN_140da5180(9, Delegate<void(CInPacket&)>(this, &UILoginDialog::FUN_1419e1160));
    FUN_140bccd50()->FUN_140da5180(0x134, Delegate<void(CInPacket&)>(this, &UILoginDialog::FUN_1419e1570));
}

// @0x1419e0e80
UILoginDialog::~UILoginDialog()
{
    FUN_140bccd50()->FUN_140da51e0(9, Delegate<void(CInPacket&)>(this, &UILoginDialog::FUN_1419e1160));
    FUN_140bccd50()->FUN_140da51e0(0x134, Delegate<void(CInPacket&)>(this, &UILoginDialog::FUN_1419e1570));
}

// @0x1419e0ff0
CString UILoginDialog::vfunc_1()
{
    return "LoginDialog";
}

// @0x1419e1040
void UILoginDialog::OnEndPopdown(char bFromPopdown)
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x6200009)
    {
        UISceneLogin* pScene = dynamic_cast<UISceneLogin*>(FUN_1422b9e80(FUN_1408e57f0()));
        if (pScene != 0 && pScene->FUN_141acfb40() && bFromPopdown)
            return;
    }
    CString strUrl = DAT_143ae0928;
    int nFlag = DAT_143ae08f4;
    FUN_140714f90()->FUN_1415383a0(strUrl, nFlag, 1, 1, 0);
}

// @0x1419e1160
void UILoginDialog::FUN_1419e1160(CInPacket&)
{
    if (FUN_1417e2610(FUN_140aa6d30()) == 0x6200009)
    {
        if (m_30.get() != 0)
        {
            MS2Ptr<Unk_LoginCheck> spLocale = static_cast<Unk_LoginRoot*>(m_30.operator->())->FUN_140c11f50<Unk_LoginCheck>("m_chkLocaledName");
            if (spLocale)
            {
                bool bChecked = spLocale->FUN_1422ce0e0() == 1;
                FUN_1409a8b10()->FUN_140cfd260()->FUN_141260e00(bChecked);
            }
        }
        int nLoginType = 0;
        if (FUN_1406c34c0() == 0)
        {
            if (DAT_143ab29d8.IsEmpty() || DAT_143ab284b == 0)
            {
                DAT_143ab29d8 = FUN_1419e2370();
                DAT_143ab2a28 = FUN_1419e2450();
            }
            Unk_LoginRequest request;
            request.m_nType = 1;
            request.m_strId = DAT_143ab29d8;
            request.m_strPassword = DAT_143ab2a28;
            request.m_nLoginType = nLoginType;
            FUN_14067c080(&request.m_machineId, FUN_140aadf70()->FUN_140d4fdf0());
            request.m_n2c = FUN_140aadf70()->FUN_140d4fe10();
            request.m_n30 = DAT_143ab2858;
            request.m_strRegion = FUN_140652030(FUN_1406516a0());
            if (FUN_1409a8b10()->FUN_140cfd260()->m_bLocaledName == 1)
                request.m_strId = FUN_1401d2b10(DAT_143ab29d8, FUN_1406521f0(FUN_1406516b0()));
            COutPacket packet(3, 0);
            FUN_1401f9020(&request, &packet);
            FUN_140710590(packet);
        }
        else
        {
            FUN_140d86260()->vfunc_20(nLoginType, 1);
        }
        FUN_140d86260()->vfunc_33(DAT_143ab2820);
    }
}

// @0x1419e1570
void UILoginDialog::FUN_1419e1570(CInPacket& iPacket)
{
    int nResult = static_cast<CInputStream&>(iPacket).vfunc_o8_3();
    DAT_143ab2946 = nResult == 0;
    if (nResult != 0)
        FUN_140d73aa0(CStringW(L"s_delete_account_cancel_login_fail"), 0, 0, CStringW(L""));
}

// @0x1419e1670
void UILoginDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x1419e1690
void UILoginDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    CString strId = s_pendingId;
    if (strId.IsEmpty())
        strId = FUN_1409a8b10()->FUN_140cfd260()->m_strSavedId;
    bool bEmpty = strId.IsEmpty();
    FUN_1409a8b10()->FUN_140cfd260();
    FUN_1409a8b10()->FUN_140cfd260()->m_bSaveId = !bEmpty;
    static_cast<Unk_LoginRoot*>(m_30.operator->())->FUN_1419e2c30("initData", strId, !bEmpty, true, FUN_1406521f0(FUN_1406516b0()));
    if (!s_pendingId.IsEmpty())
    {
        OnConnect();
        s_pendingId = L"";
    }
}

// @0x1419e1860
int UILoginDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0)
    {
        if (dynamic_cast<UIMessageBox*>(pSender) != 0)
        {
            if (pMsg->FUN_1422b8a10() == 0)
            {
                if (FUN_1406c34c0() == 1)
                {
                    FUN_140d86260()->vfunc_72();
                }
                else
                {
                    MS2Ptr<Unk_LoginInput> spInput = FUN_1419e2530();
                    if (spInput.get() != 0)
                    {
                        CStringW strText = spInput->FUN_1422e0b00();
                        spInput->FUN_1422e1500(0, strText.GetLength());
                    }
                }
            }
        }
    }
    return 0;
}

// @0x1419e19e0
int UILoginDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_1419e2900() == 0)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
    {
        static_cast<Unk_LoginRoot*>(m_30.operator->())->Invoke("onEnterKey");
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
    {
        static_cast<Unk_LoginRoot*>(m_30.operator->())->Invoke("onTabKey");
        return 1;
    }
    return 0;
}

// @0x1419e1ad0
int UILoginDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnConnect", szMethod) == 0)
    {
        OnConnect();
        return 1;
    }
    if (_stricmp("OnSaveID", szMethod) == 0)
    {
        ASData arg;
        if (arg.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned char bSave = arg.FUN_1422b8a90();
            FUN_1409a8b10()->FUN_140cfd260()->m_bSaveId = bSave;
            return 1;
        }
    }
    else
    {
        if (_stricmp("OnEndPopdown", szMethod) == 0)
        {
            OnEndPopdown(1);
            return 1;
        }
        if (_stricmp("OnChkLocaleName", szMethod) == 0)
        {
            ASData arg;
            if (arg.FUN_1422b9620(pArgs, nArgs) != 0 && arg.FUN_1422b8a90() == 0)
            {
                CMsTime deadline(2019, 2, 6, 15, 0, 0);
                CMsTime now(FUN_140869440());
                if (!(now < deadline))
                {
                    CStringW strText(L"로케일 계정을 사용해야 합니다.");
                    MS2Ptr<Unk_LoginMsgBox> spBox = FUN_140d73d20(0, strText, 0, L"");
                    if (spBox.get() != 0)
                    {
                        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UILoginDialog::FUN_1419e2690));
                        FUN_140d73c60(spBox);
                    }
                }
                else
                {
                    CStringW strText(L"로케일 계정을 사용하지 않겠습니까? \n\n 2019년 2월7일부터는 로케일 계정만 사용 가능합니다.");
                    MS2Ptr<Unk_LoginMsgBox> spBox = FUN_140d73d20(1, strText, 0, L"");
                    if (spBox.get() != 0)
                    {
                        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UILoginDialog::FUN_1419e2730));
                        FUN_140d73c60(spBox);
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

// @0x1419e2100
void UILoginDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    if (FUN_1403ed2b0()->FUN_141adc890(0x4eef) == 0 && FUN_1406516b0() != 1)
        return;
    MS2Ptr<ASDisplayObject> spObj(dynamic_cast<ASDisplayObject*>((AScript*)m_30));
    if (spObj.get() != 0)
        spObj->vfunc_2(8, -50, -39);
}

// @0x1419e21e0
bool UILoginDialog::FUN_1419e21e0(CStringW strMessage)
{
    DAT_143ab284b = 1;
    MS2Ptr<Unk_LoginMsgBox> spBox = FUN_140d74390(strMessage, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UILoginDialog::FUN_1419e22e0));
    return true;
}

// @0x1419e22e0
bool UILoginDialog::FUN_1419e22e0(int nResult, const CMsgBoxData&)
{
    return FUN_1419e2310(nResult);
}

// @0x1419e2310
bool UILoginDialog::FUN_1419e2310(int nResult)
{
    DAT_143ab285c = 0;
    DAT_143ab2860 = 0;
    if (nResult == 0)
    {
        DAT_143ab285c = 1;
        OnEndPopdown(0);
    }
    else
    {
        DAT_143ab284b = 0;
    }
    return true;
}

// @0x1419e2370
CString UILoginDialog::FUN_1419e2370()
{
    MS2Ptr<Unk_LoginInput> spInput = FUN_1419e2530();
    if (spInput.get() == 0)
        return "";
    return FUN_14016a600(spInput->FUN_1422e0b00(), 0);
}

// @0x1419e2450
CString UILoginDialog::FUN_1419e2450()
{
    MS2Ptr<Unk_LoginInput> spInput = FUN_1419e25e0();
    if (spInput.get() == 0)
        return "";
    return FUN_14016a600(spInput->FUN_1422e0b00(), 0);
}

// @0x1419e2530
MS2Ptr<Unk_LoginInput> UILoginDialog::FUN_1419e2530()
{
    if (m_30.get() == 0)
        return MS2Ptr<Unk_LoginInput>(0);
    return static_cast<Unk_LoginRoot*>(m_30.operator->())->FUN_140bbe880<Unk_LoginInput>("m_inputID");
}

// @0x1419e25e0
MS2Ptr<Unk_LoginInput> UILoginDialog::FUN_1419e25e0()
{
    if (m_30.get() == 0)
        return MS2Ptr<Unk_LoginInput>(0);
    return static_cast<Unk_LoginRoot*>(m_30.operator->())->FUN_140bbe880<Unk_LoginInput>("m_inputPW");
}

// @0x1419e2690
bool UILoginDialog::FUN_1419e2690(int, const CMsgBoxData&)
{
    MS2Ptr<Unk_LoginCheck> spLocale;
    FUN_140bc6d10("m_chkLocaledName", spLocale);
    spLocale->FUN_1422ce090(1);
    return true;
}

// @0x1419e2730
bool UILoginDialog::FUN_1419e2730(int nResult, const CMsgBoxData&)
{
    if (nResult != 0)
    {
        MS2Ptr<Unk_LoginCheck> spLocale;
        FUN_140bc6d10("m_chkLocaledName", spLocale);
        spLocale->FUN_1422ce090(1);
    }
    return true;
}

// @0x1419e27d0
void UILoginDialog::FUN_1419e27d0()
{
    if (vfunc_55() == 0 && m_30.get() != 0)
    {
        static_cast<Unk_LoginRoot*>(m_30.operator->())->Invoke("failConnect");
        static_cast<Unk_LoginRoot*>(m_30.operator->())->Invoke("popup");
    }
}

// @0x1419e28a0
void UILoginDialog::FUN_1419e28a0()
{
    if (m_30.get() != 0)
        static_cast<Unk_LoginRoot*>(m_30.operator->())->Invoke("popdown");
}

// @0x1419e2900
int UILoginDialog::FUN_1419e2900()
{
    return FUN_1418fc810();
}

// @0x1419e2920
void UILoginDialog::OnConnect()
{
    if (FUN_1422b9dc0(FUN_1408e57f0()) == 0x6200009)
    {
        UISceneLogin* pScene = dynamic_cast<UISceneLogin*>(FUN_1422b9e80(FUN_1408e57f0()));
        if (pScene != 0)
        {
            int nUiId = vfunc_48();
            FUN_141acfad0(pScene, nUiId);
        }
    }
    else
    {
        FUN_1419e28a0();
    }
}

// @0x1419e2c30
Scaleform::GFx::Value Unk_LoginRoot::FUN_1419e2c30(const char* szMethod, CString strId, bool bSaveId, bool bFlag, CString strRegion)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)strId);
    FUN_1422bcce0(args.FUN_1409b1f70(1), bSaveId);
    FUN_1422bcce0(args.FUN_1409b1f70(2), bFlag);
    FUN_1422bce70(args.FUN_1409b1f70(3), (const char*)strRegion);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1419e2f80
Unk_LoginRequest::Unk_LoginRequest() : m_nType(0), m_nLoginType(0), m_n2c(0), m_n30(0)
{
}

// @0x1419e3060
Unk_LoginRequest::~Unk_LoginRequest()
{
}

// @0x1419e33f0
MS2_EMIT_CRT_MEMMOVE_S();

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x1419e1040, UILoginDialog, OnEndPopdown, 267, 0xF502B3E3);
MS2_REPLACE_METHOD(0x1419e1160, UILoginDialog, FUN_1419e1160, 1031, 0x1C1ACD5D);
MS2_REPLACE_METHOD(0x1419e1570, UILoginDialog, FUN_1419e1570, 245, 0xA57FD4A9);
MS2_REPLACE_METHOD(0x1419e1670, UILoginDialog, vfunc_67, 24, 0x2021848A);
MS2_REPLACE_METHOD_VIA(0x1419e1860, UILoginDialog, IMessageListener, OnMessage, 364, 0x8D08F749);
MS2_REPLACE_METHOD(0x1419e19e0, UILoginDialog, vfunc_13, 231, 0x3B6354A9);
MS2_REPLACE_METHOD(0x1419e2100, UILoginDialog, vfunc_43, 206, 0x4169F399);
MS2_REPLACE_METHOD(0x1419e22e0, UILoginDialog, FUN_1419e22e0, 37, 0xA61F27B3);
MS2_REPLACE_METHOD(0x1419e2310, UILoginDialog, FUN_1419e2310, 78, 0x6F0CEC7E);
MS2_REPLACE_METHOD(0x1419e2690, UILoginDialog, FUN_1419e2690, 152, 0xCA2EE2B3);
MS2_REPLACE_METHOD(0x1419e2730, UILoginDialog, FUN_1419e2730, 154, 0x085FA634);
MS2_REPLACE_METHOD(0x1419e27d0, UILoginDialog, FUN_1419e27d0, 193, 0xD82DE7AD);
MS2_REPLACE_METHOD(0x1419e28a0, UILoginDialog, FUN_1419e28a0, 83, 0xE3486D90);
MS2_REPLACE_METHOD(0x1419e2900, UILoginDialog, FUN_1419e2900, 19, 0x012679F4);
MS2_REPLACE_METHOD(0x1419e2920, UILoginDialog, OnConnect, 142, 0xAEE14BC1);

