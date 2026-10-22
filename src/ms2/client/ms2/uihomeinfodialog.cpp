// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeInfoDialog: the info panel of the player's home (address, notice, recommend, construction score, bank / doctor cooldowns, balance, visitors). Field/helper names are inferred.
// MS2-UNIT: ?\uihomeinfodialog.cpp
// MS2-RANGE: 0x1412c4cd0-0x1412c8bd0 .text$mn
// MS2-RANGE: 0x1400ed7a0-0x1400ed9c0 .text$di
// MS2-RANGE: 0x142caf320-0x142caf410 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$forward@AEBQ8UIHomeInfoDialog@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8UIHomeInfoDialog@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x1412c8780 ; unique
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIHomeInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA@XZ 0x1412c8890 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIHomeInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x1412c88d0 ; unique
// MS2-PIN: ??_GUIHomeInfoDialog@@UEAAPEAXI@Z 0x1412c8910 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIHomeInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1412c89d0 ; unique
// MS2-PIN: ??$Call@VUIHomeInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIHomeInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIHomeInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1412c8a10 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIHomeInfoDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1412c8970
// MS2-PIN: ??__Es_pointer1401cd100@@YAXXZ 0x1400ed920
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihomeinfodialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uihomeinfodialog.h"
#include <atlcoll.h>
#include <set>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "pcbase.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/unnamed/unit_140fa9eb0.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics (the exe runs them in this order: two names of the unit, the shared header group, the key controller) ----

static CString s_strCharName = "charName";
static CString s_strOnCooldownStart = "onCooldownStart";
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/uichatballoon_ptr.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local views of exe types ----

// An AS child that the panel hands out. The Invoke back ends below are inline COMDATs of this unit.
class Unk_HiScript : public ASDisplayObject
{
public:
    using ASDisplayObject::Invoke;
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, int a3);                      // 0x1412c8520
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2, CStringW a3, CStringW a4);   // 0x1412c85f0
    Scaleform::GFx::Value FUN_140e5bf20(const char* szMethod, float f1, float f2);                   // Invoke(name, float, float)
};
class ASDialog : public Unk_HiScript {};

// A button of the panel (slot 3 shows, slot 4 enables).
class Unk_HiButton : public Unk_HiScript
{
public:
    void FUN_1422c1fe0(unsigned int nEnabled);
};

// The list control of the convenient panel.
class Unk_HiList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                           // clear
    void FUN_1422dd230(const ASObj& row);                           // append a row
};
// The convenient panel (balance buttons and the visitors list).
class Unk_HiConv : public ASUIComponent
{
public:
    MS2Ptr<Unk_HiList> FUN_140bc7280(const CString& strName);
};
// The drop down of the channel.
class Unk_HiCombo : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);
    void FUN_1422dfc70(ASObj& obj);                                 // add an item
    void FUN_1422df690(int n);                                      // select
    void FUN_1422c1fe0(unsigned int nEnabled);
};
// The second panel type the visitors book button is looked up on.
class Unk_HiPanelB : public AScript
{
public:
};

// The entity application framework (global at 0x143b059e8) and the cube service (class id 0x06100017).
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;
extern __int64 DAT_143ab2898;                                       // wallet: meso
extern char DAT_143ab2d80[];

class Unk_HiSvc : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    bool FUN_1410c3600(int nRule);
    int FUN_1410c3650();
    int FUN_1410ce310();
    CStringW FUN_1410c3260();                                       // the notice text
    CStringW FUN_1410c31d0();                                       // the address text
    int FUN_1410c3000();
    int FUN_1410c3100();
    int FUN_1410c3140();
    int FUN_1410c3430();
    int FUN_1410c33f0();
    int FUN_1410c3470();
    int FUN_1410c34b0();
    __int64 FUN_1410d5730();                                        // meso balance
    __int64 FUN_1410d5780();                                        // merat balance
    void FUN_1410d5930(std::set<__int64>& ids);                     // the visitors
};
Unk_HiSvc* FUN_1401cd040(Unk_EntityAppFramework* framework);
Unk_HiSvc* FUN_1409670e0();

// The local player.
class Unk_HiPc
{
public:
    void FUN_14152a040();
    void FUN_14152f3c0();
    void FUN_14152feb0(int nMode, int nFlag);
    void FUN_141530200();
    void FUN_1415283c0(int n);
    void FUN_1415286a0();
    int FUN_1416595d0();
    __int64 FUN_141662830();                                        // time of the last bank use
    __int64 FUN_141662870();                                        // time of the last doctor use
};
class Unk_HiMapPtr
{
public:
    ~Unk_HiMapPtr();                                                // 0x1408850f0
    bool FUN_140965240(int n);
private:
    void* m_pad_00;
    void* m_p;
};
class Unk_HiWorld
{
public:
    Unk_HiMapPtr FUN_141bd30a0();                                   // current map data
};
Unk_HiWorld* FUN_1403ed2d0();
Unk_HiPc* FUN_141bd0cc0(Unk_HiWorld*);
PCBase* FUN_141bd1640(Unk_HiWorld*, __int64 nId);

// The constant table (cooldowns of the bank and the doctor).
struct Unk_HiConstUInt { char m_pad_00[0x58]; };
struct Unk_HiConstTable
{
    char m_pad_00[0x66d0];
    Unk_HiConstUInt m_bank;                                         // +0x66d0
    char m_pad_6728[0x67e0 - 0x66d0 - sizeof(Unk_HiConstUInt)];
    Unk_HiConstUInt m_doctor;                                       // +0x67e0
};
MS2_CHECK_OFFSET(Unk_HiConstTable, m_bank, 0x66d0);
MS2_CHECK_OFFSET(Unk_HiConstTable, m_doctor, 0x67e0);
Unk_HiConstTable* FUN_1401d3200();
unsigned int* FUN_1401d7c10(Unk_HiConstUInt* pSlot);

// The UI manager.
class Unk_HiUiMgr
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    void FUN_141adc530(int nId);                                    // show
    void FUN_141adc750(int nId);                                    // toggle
};
Unk_HiUiMgr* FUN_1403ed2b0();

class UISystemMenuDialog : public UIObject
{
public:
    void FUN_141b13b30();
};

class Unk_HiOptions;
Unk_HiOptions* FUN_140166410();
bool FUN_14036d570(Unk_HiOptions*, int nOption);
bool FUN_14036d710(Unk_HiOptions*, int nOption);

int FUN_1418fd130();
int FUN_1418fcee0();
int FUN_1418fd280();
int FUN_1418fd2f0();
int FUN_140930190();
bool FUN_140930c50();
__int64 FUN_140930240();
__int64 FUN_140930ae0();
unsigned int FUN_14092f640();
bool FUN_141902580(bool bMessage);
__int64 FUN_140869440();
void FUN_141275260(int nId, int a, int b);
void FUN_140710590(COutPacket& packet);
CString FUN_14016a600(const wchar_t* psz, int n);
CStringW GetStringCommon(int nId);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_140811740(int nId, const int& a, const int& b);
CStringW FUN_14062b4f0(CStringW strFormat, const int& n);
int FUN_14028cb70(const CStringW& str, CAtlArray<CStringW>& arr, const wchar_t* szDelim, int nMax);
__int64 FUN_140de2a80(void* p);
int FUN_1412772f0(__int64 nValue, int bGrouped);
UIHomeSaveSlotDialog* FUN_140c2b5c0(int nUiId);
int FUN_141527ed0(Unk_HiPc* pPc);
CStringW FUN_1409796e0(int a, int b, int c, CStringW strName);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

UISystemMenuDialog* FUN_1412c8470();
int FUN_1412c8960();

// @0x1412c4cd0
UIHomeInfoDialog::UIHomeInfoDialog()
{
    m_178 = 0;
    m_17c = 0;
    m_88 = 1;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
}

// @0x1412c4d70
CString UIHomeInfoDialog::GetTypeName()
{
    return CString("HomeInfoDialog");
}

// @0x1412c4dc0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (FUN_1412c72d0())
    {
        MS2Ptr<Unk_HiCombo> spChannel = FUN_140c28560(CString("m_channel"));
        if (spChannel.get() != 0)
        {
            CStringW strLabel;
            unsigned int nChannel = FUN_14092f640();
            strLabel.Format(L"%s %d", (LPCWSTR)GetStringCommon(0x579), (unsigned __int64)nChannel);
            ASObj obj(2);
            obj.FUN_1407cbb20("label", strLabel);
            spChannel->FUN_1422dfc70(obj);
            spChannel->vfunc_24(1);
            spChannel->FUN_1422df690(0);
            spChannel->FUN_1422c1fe0(0);
        }
    }
}

// @0x1412c4fc0
void UIHomeInfoDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
        pDialog->vfunc_2(6, 0, 0);
}

// @0x1412c5030
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
int UIHomeInfoDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("OnTogglePanel", szMethod) == 0)
    {
        OnTogglePanel();
        return 1;
    }
    if (_stricmp("OnNoticeModify", szMethod) == 0)
    {
        OnNoticeModify();
        return 1;
    }
    if (_stricmp("OnVisitorsBook", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4ed9);
        return 1;
    }
    if (_stricmp("OnHomeLeave", szMethod) == 0)
    {
        FUN_1412c7600();
        return 1;
    }
    if (_stricmp("OnRecommend", szMethod) == 0)
        return FUN_1418fd130();
    if (_stricmp("OnReport", szMethod) == 0)
        return FUN_1418fcee0();
    if (_stricmp("OnConstruct", szMethod) == 0)
    {
        OnConstruct();
        return 1;
    }
    if (_stricmp("OnBank", szMethod) == 0)
    {
        OnBank();
        return 1;
    }
    if (_stricmp("OnDoctor", szMethod) == 0)
    {
        OnDoctor();
        return 1;
    }
    if (_stricmp("OnBalance", szMethod) == 0)
    {
        OnBalance();
        return 1;
    }
    if (_stricmp("OnRemoveUser", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            SendRequestCubeMode58(data.FUN_1422b8f40());
        return 1;
    }
    return 0;
}

// @0x1412c5330
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c5330(unsigned int nRemainMs)
{
    MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
    if (spPanel.get() != 0)
    {
        MS2Ptr<Unk_HiButton> spBank = spPanel->FUN_140acce30<Unk_HiButton>(CString("m_bank"));
        if (spBank.get() != 0)
        {
            unsigned int nTotal = *FUN_1401d7c10(&FUN_1401d3200()->m_bank);
            spBank->FUN_140e5bf20((LPCSTR)s_strOnCooldownStart, (float)nRemainMs * 0.001f, (float)nTotal * 0.001f);
        }
    }
}

// @0x1412c54e0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c54e0(unsigned int nRemainMs)
{
    MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
    if (spPanel.get() != 0)
    {
        MS2Ptr<Unk_HiButton> spDoctor = spPanel->FUN_140acce30<Unk_HiButton>(CString("m_doctor"));
        if (spDoctor.get() != 0)
        {
            unsigned int nTotal = *FUN_1401d7c10(&FUN_1401d3200()->m_doctor);
            spDoctor->FUN_140e5bf20((LPCSTR)s_strOnCooldownStart, (float)nRemainMs * 0.001f, (float)nTotal * 0.001f);
        }
    }
}

// @0x1412c5690
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c5690()
{
    if (FUN_1418fd280() == 0)
        return;
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    Unk_HiMapPtr spMap = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spMap.FUN_140965240(0) != 0)
        return;
    {
        MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
        if (spPanel.get() != 0)
        {
            MS2Ptr<Unk_HiButton> spBank = spPanel->FUN_140acce30<Unk_HiButton>(CString("m_bank"));
            if (spBank.get() != 0)
            {
                spBank->Invoke("setTimeString", GetStringCommon(0x5ce), GetStringCommon(0x5cc), GetStringCommon(0x5ca), GetStringCommon(0x5cb));
                int nRemain = FUN_1412c81d0();
                if (nRemain != 0)
                    FUN_1412c5330(nRemain);
            }
        }
    }
    {
        MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
        if (spPanel.get() != 0)
        {
            MS2Ptr<Unk_HiButton> spDoctor = spPanel->FUN_140acce30<Unk_HiButton>(CString("m_doctor"));
            if (spDoctor.get() != 0)
            {
                spDoctor->Invoke("setTimeString", GetStringCommon(0x5ce), GetStringCommon(0x5cc), GetStringCommon(0x5ca), GetStringCommon(0x5cb));
                int nRemain = FUN_1412c8280();
                if (nRemain != 0)
                    FUN_1412c54e0(nRemain);
            }
        }
    }
}

// @0x1412c5c30
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c5c30()
{
    if (vfunc_55() == 0)
    {
        MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
        if (spPanel.get() != 0)
        {
            MS2Ptr<ASTextField> spText = spPanel->FUN_1409b4620(CString("m_notice"));
            if (spText.get() != 0)
                spText->FUN_1422c4cd0(FUN_1412c7090());
        }
    }
}

// @0x1412c5da0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c5da0()
{
    if (vfunc_55() == 0)
    {
        MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
        if (spPanel.get() != 0)
        {
            MS2Ptr<Unk_HiButton> spButton = spPanel->FUN_140acce30<Unk_HiButton>(CString("m_recommend"));
            if (spButton.get() != 0)
            {
                int nVoted = FUN_140930190();
                spButton->FUN_1422c1fe0(nVoted == 0);
            }
        }
    }
}

// @0x1412c5f00
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c5f00()
{
    if (vfunc_55() == 0)
    {
        MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
        if (spPanel.get() != 0)
        {
            MS2Ptr<ASTextField> spText = spPanel->FUN_1409b4620(CString("m_address"));
            if (spText.get() != 0)
                spText->FUN_1422c4cd0(FUN_1412c7140());
        }
    }
}

// @0x1412c6070
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c6070()
{
    if (vfunc_55() == 0)
    {
        FUN_1412c5da0();
        MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
        if (spPanel.get() != 0)
        {
            MS2Ptr<ASTextField> spText = spPanel->FUN_1409b4620(CString("m_constructScore"));
            if (spText.get() != 0)
            {
                int nMax = FUN_1409670e0()->FUN_1410c3430();
                int nCur = FUN_1409670e0()->FUN_1410c33f0();
                spText->FUN_1422c4cd0(FUN_140811740(0x25, nCur, nMax));
            }
        }
    }
}

// @0x1412c6220
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c6220()
{
    if (vfunc_55() == 0)
    {
        efd::SmartPointer<Unk_HiSvc> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService != 0)
        {
            MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
            if (spPanel.get() != 0)
            {
                MS2Ptr<Unk_HiConv> spConv = spPanel->FUN_140accfb0<Unk_HiConv>(CString("m_homeConvenientPanel"));
                if (spConv.get() != 0)
                {
                    spConv->Invoke("setMeratIcon", FUN_14036d710(FUN_140166410(), 0x61));
                    MS2Ptr<Unk_HiButton> spBalance = spConv->FUN_140acce30<Unk_HiButton>(CString("m_balance"));
                    if (spBalance.get() != 0)
                    {
                        int nOwner = FUN_1418fd280();
                        spBalance->FUN_1422c1fe0(nOwner != 0);
                        spBalance->vfunc_4(nOwner != 0);
                    }
                    MS2Ptr<ASTextField> spMeso = spConv->FUN_1409b4620(CString("m_balanceMeso"));
                    if (spMeso.get() != 0)
                        spMeso->FUN_1422c4f00(FUN_1409404f0(spService->FUN_1410d5730()));
                    MS2Ptr<ASTextField> spMerat = spConv->FUN_1409b4620(CString("m_balanceMerat"));
                    if (spMerat.get() != 0)
                        spMerat->FUN_1422c4f00(FUN_1409404f0(spService->FUN_1410d5780()));
                }
            }
        }
    }
}

// @0x1412c66c0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c66c0()
{
    if (vfunc_55() == 0)
    {
        efd::SmartPointer<Unk_HiSvc> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService != 0)
        {
            MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
            if (spPanel.get() != 0)
            {
                MS2Ptr<Unk_HiConv> spConv = spPanel->FUN_140accfb0<Unk_HiConv>(CString("m_homeConvenientPanel"));
                if (spConv.get() != 0)
                {
                    std::set<__int64> ids;
                    spService->FUN_1410d5930(ids);
                    MS2Ptr<Unk_HiList> spList = spConv->FUN_140bc7280(CString("m_scrollingList"));
                    if (spList.get() != 0)
                    {
                        spList->FUN_1422dd1d0();
                        if (!ids.empty())
                        {
                            spConv->vfunc_3(1);
                            for (std::set<__int64>::iterator it = ids.begin(); it != ids.end(); ++it)
                            {
                                PCBase* pPlayer = FUN_141bd1640(FUN_1403ed2d0(), *it);
                                if (pPlayer != 0)
                                {
                                    ASObj obj(2);
                                    obj.FUN_1407cbb20((LPCSTR)s_strCharName, pPlayer->vfunc_77());
                                    obj.FUN_1407cbbe0("myHome", FUN_1418fd280() != 0);
                                    spList->FUN_1422dd230(obj);
                                }
                            }
                            spList->vfunc_24(true);
                        }
                        else
                        {
                            spConv->vfunc_4(FUN_140930c50());
                            spList->vfunc_24(true);
                        }
                    }
                }
            }
        }
    }
}

// @0x1412c6b50
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c6b50()
{
    if (vfunc_55() == 0 && FUN_141902580(false))
    {
        if (FUN_1409670e0()->FUN_1410c3600(2))
        {
            MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
            if (spPanel.get() != 0)
            {
                MS2Ptr<ASTextField> spArea = spPanel->FUN_1409b4620(CString("m_extensionArea"));
                if (spArea.get() != 0)
                {
                    int nArea = FUN_1409670e0()->FUN_1410c3470();
                    spArea->FUN_1422c4cd0(FUN_14062b4f0(CStringW(L"s_home_info_title_area"), nArea));
                }
                MS2Ptr<ASTextField> spHeight = spPanel->FUN_1409b4620(CString("m_extensionHeight"));
                if (spHeight.get() != 0)
                {
                    int nHeight = FUN_1409670e0()->FUN_1410c34b0();
                    spHeight->FUN_1422c4cd0(FUN_14062b4f0(CStringW(L"s_home_info_title_height"), nHeight));
                }
            }
        }
    }
}

// @0x1412c6e70
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::FUN_1412c6e70(const CStringW& strItemName, const CStringW& strCreator)
{
    if (vfunc_55() == 0 && FUN_141902580(false))
    {
        if (FUN_1409670e0()->FUN_1410c3600(2))
        {
            MS2Ptr<ASUIComponent> spPanel = GetChild<ASUIComponent>(CString("m_homeInfoPanel"));
            if (spPanel.get() != 0)
            {
                MS2Ptr<ASTextField> spName = spPanel->FUN_1409b4620(CString("m_itemName"));
                if (spName.get() != 0)
                    spName->FUN_1422c4cd0(strItemName);
                MS2Ptr<ASTextField> spCreator = spPanel->FUN_1409b4620(CString("m_creator"));
                if (spCreator.get() != 0)
                    spCreator->FUN_1422c4cd0(strCreator);
            }
            FUN_1412c6b50();
        }
    }
}

// @0x1412c7090
CStringW UIHomeInfoDialog::FUN_1412c7090()
{
    CStringW strNotice = FUN_1409670e0()->FUN_1410c3260();
    if (!strNotice.IsEmpty())
        return strNotice;
    return GetStringCommon(0x574);
}

// @0x1412c7140
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
CStringW UIHomeInfoDialog::FUN_1412c7140()
{
    CStringW strAddress = FUN_1409670e0()->FUN_1410c31d0();
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return strAddress;
    if (FUN_141527ed0(pPc) == 0)
        return strAddress;
    int nA = FUN_1409670e0()->FUN_1410c3140();
    int nB = FUN_1409670e0()->FUN_1410c3100();
    int nC = FUN_1409670e0()->FUN_1410c3000();
    return FUN_1409796e0(nA, nB, nC, FUN_1409670e0()->FUN_1410c31d0());
}

// @0x1412c72d0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
int UIHomeInfoDialog::FUN_1412c72d0()
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return 0;
    if (FUN_1418fd2f0() == 0)
    {
        vfunc_8(0);
        return 0;
    }
    int nCraft = pPc->FUN_1416595d0();
    int nMode = FUN_1409670e0()->FUN_1410c3650();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
        pDialog->Invoke("setMyHome", FUN_1418fd280(), nCraft, nMode);
    if (nCraft == 0)
    {
        FUN_1412c5c30();
        FUN_1412c5da0();
        FUN_1412c5f00();
        FUN_1412c6070();
        bool bBook = FUN_14036d570(FUN_140166410(), 0x3e);
        MS2Ptr<Unk_HiPanelB> spPanel = FUN_140ede180(CString("m_homeInfoPanel"));
        if (spPanel.get() != 0)
        {
            MS2Ptr<Unk_HiButton> spBook = spPanel->FUN_140acce30<Unk_HiButton>(CString("m_visitorsBook"));
            if (spBook.get() != 0)
            {
                spBook->FUN_1422c1fe0(bBook);
                spBook->vfunc_4(bBook);
            }
        }
    }
    FUN_1412c6220();
    FUN_1412c66c0();
    FUN_1412c6e70(CStringW(L""), CStringW(L""));
    if (FUN_1418fd280() != 0)
        FUN_1412c5690();
    return 1;
}

// @0x1412c7600
void UIHomeInfoDialog::FUN_1412c7600()
{
    UISystemMenuDialog* pMenu = FUN_1412c8470();
    if (pMenu != 0)
        pMenu->FUN_141b13b30();
}

// @0x1412c7630
void UIHomeInfoDialog::OnTogglePanel()
{
    m_178 = m_178 == 0;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
        pDialog->Invoke("setMinimize", m_178);
}

// @0x1412c76e0
void UIHomeInfoDialog::OnNoticeModify()
{
    FUN_1403ed2b0()->FUN_141adc530(0x4f79);
}

// @0x1412c7710
void UIHomeInfoDialog::OnConstruct()
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    if (pPc->FUN_1416595d0() == 0)
        pPc->FUN_14152feb0(1, 0);
    else
        pPc->FUN_141530200();
}

// @0x1412c7770
void UIHomeInfoDialog::OnBank()
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    if (FUN_1412c81d0() > 0)
        return;
    pPc->FUN_1415283c0(1);
}

// @0x1412c77c0
void UIHomeInfoDialog::OnDoctor()
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return;
    if (FUN_1412c8280() > 0)
        return;
    pPc->FUN_1415286a0();
}

// @0x1412c7810
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::OnBalance()
{
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(8, 0xbb9, 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        unsigned int nMax = FUN_1412772f0(FUN_140de2a80(DAT_143ab2d80), 1);
        spBox->FUN_141a01d30(1, CStringW(L""), nMax, 0, 0);
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeInfoDialog::FUN_1412c7ff0));
        FUN_140d73c60(spBox);
    }
}

// @0x1412c79e0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UIHomeInfoDialog::SendRequestCubeMode58(CStringW strName)
{
    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
    packet.vfunc_o10_1(0x3a);
    packet.vfunc_o10_6(FUN_14016a600(strName.GetString(), 0));
    FUN_140710590(packet);
}

// @0x1412c7aa0
bool UIHomeInfoDialog::FUN_1412c7aa0(int nResult, const CMsgBoxData& data)
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    if (nResult == 0)
        pPc->FUN_14152a040();
    return true;
}

// @0x1412c7af0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
bool UIHomeInfoDialog::FUN_1412c7af0(int nSlot)
{
    UIHomeSaveSlotDialog* pDialog = FUN_140c2b5c0(0x4f27);
    if (nSlot == 0)
    {
        if (FUN_1409670e0()->FUN_1410ce310() == 0)
            pDialog->FUN_140faa6d0();
        else
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommon(0xbb1), static_cast<IMessageListener*>(this), CStringW(L"OnHousingSave"));
            if (spBox == 0)
                return false;
            spBox->FUN_141a024a0(0);
            FUN_140d73c60(spBox);
        }
    }
    else if (nSlot == 1)
        pDialog->FUN_140faa750();
    else if (nSlot == 2)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x1f, 0x6e2, 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01800(2);
            spBox->FUN_141a024e0(GetStringCommon(0x9d1), 0);
            spBox->SetAgreement(0);
            spBox->FUN_141a02770(0x1c0, 400);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIHomeInfoDialog::SendRequestCubeMode31));
            FUN_140d73c60(spBox);
        }
    }
    return true;
}

// @0x1412c7ef0
bool UIHomeInfoDialog::FUN_1412c7ef0(int nResult, const CMsgBoxData& data)
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    if (nResult == 0)
        pPc->FUN_14152a040();
    return true;
}

// @0x1412c7f40
bool UIHomeInfoDialog::SendRequestCubeMode31(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        if (FUN_14036d570(FUN_140166410(), 0xd4))
        {
            Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pPc != 0)
                pPc->FUN_14152f3c0();
        }
        COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
        packet.vfunc_o10_1(0x1f);
        FUN_140710590(packet);
    }
    return true;
}

// @0x1412c7ff0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
bool UIHomeInfoDialog::FUN_1412c7ff0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    CStringW strInput = data.FUN_141a02d50();
    strInput.Replace(L",", L"");
    CAtlArray<CStringW> parts;
    if (FUN_14028cb70(strInput, parts, L":", 2) != 0)
    {
        __int64 nMeso = _wtoi64(parts[0]);
        __int64 nMerat = _wtoi64(parts[1]);
        if (nMeso <= DAT_143ab2898 && nMerat <= FUN_140930240() + FUN_140930ae0())
        {
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.vfunc_o10_1(0x38);
            packet.vfunc_o10_4(nMeso);
            packet.vfunc_o10_4(nMerat);
            FUN_140710590(packet);
            return true;
        }
        if (DAT_143ab2898 < nMeso)
            FUN_141275260(0xcb0, 1, 1);
        if (FUN_140930240() + FUN_140930ae0() < nMerat)
            FUN_141275260(0xcb1, 1, 1);
    }
    return true;
}

// @0x1412c81d0
unsigned int UIHomeInfoDialog::FUN_1412c81d0()
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return 0;
    if (pPc->FUN_141662830() == 0)
        return 0;
    __int64 nNow = FUN_140869440();
    int nLimit = *FUN_1401d7c10(&FUN_1401d3200()->m_bank) / 1000;
    int nElapsed = (int)(nNow - pPc->FUN_141662830());
    if (nElapsed > nLimit)
        return 0;
    return (nLimit - nElapsed) * 1000;
}

// @0x1412c8280
unsigned int UIHomeInfoDialog::FUN_1412c8280()
{
    Unk_HiPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return 0;
    if (pPc->FUN_141662870() == 0)
        return 0;
    __int64 nNow = FUN_140869440();
    int nLimit = *FUN_1401d7c10(&FUN_1401d3200()->m_doctor) / 1000;
    int nElapsed = (int)(nNow - pPc->FUN_141662870());
    if (nElapsed > nLimit)
        return 0;
    return (nLimit - nElapsed) * 1000;
}

// @0x1412c8470
UISystemMenuDialog* FUN_1412c8470()
{
    Unk_HiUiMgr* pMgr = FUN_1403ed2b0();
    if (pMgr == 0)
        return 0;
    MS2Ptr<UIObject> spMenu = pMgr->FUN_141adcea0(FUN_1412c8960());
    if (spMenu.IsNull())
        return 0;
    return dynamic_cast<UISystemMenuDialog*>((UIObject*)spMenu);
}

// @0x1412c8520
inline Scaleform::GFx::Value Unk_HiScript::Invoke(const char* szMethod, int a1, int a2, int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412c85f0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
inline Scaleform::GFx::Value Unk_HiScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, CStringW a3, CStringW a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1.GetString());
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2.GetString());
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3.GetString());
    FUN_1422bcea0(args.FUN_1409b1f70(3), a4.GetString());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1412c8950
// @0x1412c8960
int FUN_1412c8960()
{
    return 0x4e21;
}

// @0x1412c8950
int UIHomeInfoDialog::vfunc_48()
{
    return 0x4ed8;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x1412C4D70, UIHomeInfoDialog, GetTypeName, 61, 0xDB750399);
MS2_REPLACE_METHOD(0x1412C4DC0, UIHomeInfoDialog, OnLoadComplete, 491, 0xE377F024);
MS2_REPLACE_METHOD(0x1412C4FC0, UIHomeInfoDialog, vfunc_43, 103, 0xD19FE84D);
MS2_REPLACE_METHOD(0x1412C5030, UIHomeInfoDialog, vfunc_28, 702, 0xAD2CA2DB);
MS2_REPLACE_METHOD(0x1412C5690, UIHomeInfoDialog, FUN_1412c5690, 1425, 0x3B047595);
MS2_REPLACE_METHOD(0x1412C5C30, UIHomeInfoDialog, FUN_1412c5c30, 357, 0xBD0CFBD2);
MS2_REPLACE_METHOD(0x1412C5DA0, UIHomeInfoDialog, FUN_1412c5da0, 335, 0x28AE81DF);
MS2_REPLACE_METHOD(0x1412C5F00, UIHomeInfoDialog, FUN_1412c5f00, 357, 0xFC72C3EE);
MS2_REPLACE_METHOD(0x1412C6070, UIHomeInfoDialog, FUN_1412c6070, 423, 0x47F5A907);
MS2_REPLACE_METHOD(0x1412C6220, UIHomeInfoDialog, FUN_1412c6220, 1167, 0x031C2BDB);
MS2_REPLACE_METHOD(0x1412C6B50, UIHomeInfoDialog, FUN_1412c6b50, 788, 0xA95FEA93);
MS2_REPLACE_METHOD(0x1412C6E70, UIHomeInfoDialog, FUN_1412c6e70, 537, 0x8CBD6EEE);
MS2_REPLACE_METHOD(0x1412C7090, UIHomeInfoDialog, FUN_1412c7090, 160, 0x81FF7CA8);
MS2_REPLACE_METHOD(0x1412C7140, UIHomeInfoDialog, FUN_1412c7140, 390, 0x1D9E1367);
MS2_REPLACE_METHOD(0x1412C72D0, UIHomeInfoDialog, FUN_1412c72d0, 806, 0xB76F0C61);
MS2_REPLACE_METHOD(0x1412C7600, UIHomeInfoDialog, FUN_1412c7600, 42, 0x5E244372);
MS2_REPLACE_METHOD(0x1412C7630, UIHomeInfoDialog, OnTogglePanel, 167, 0x80DDFABF);
MS2_REPLACE_METHOD(0x1412C76E0, UIHomeInfoDialog, OnNoticeModify, 32, 0x87E480A0);
MS2_REPLACE_METHOD(0x1412C7710, UIHomeInfoDialog, OnConstruct, 86, 0xF80D1B0D);
MS2_REPLACE_METHOD(0x1412C7770, UIHomeInfoDialog, OnBank, 73, 0x23D732DD);
MS2_REPLACE_METHOD(0x1412C77C0, UIHomeInfoDialog, OnDoctor, 68, 0x6D992898);
MS2_REPLACE_METHOD(0x1412C7810, UIHomeInfoDialog, OnBalance, 444, 0xF76ACB35);
MS2_REPLACE_METHOD(0x1412C79E0, UIHomeInfoDialog, SendRequestCubeMode58, 173, 0xBF680A66);
MS2_REPLACE_METHOD(0x1412C7AA0, UIHomeInfoDialog, FUN_1412c7aa0, 72, 0xA734365C);
MS2_REPLACE_METHOD(0x1412C7AF0, UIHomeInfoDialog, FUN_1412c7af0, 1011, 0x70EEF58B);
MS2_REPLACE_METHOD(0x1412C7EF0, UIHomeInfoDialog, FUN_1412c7ef0, 72, 0x71DF7278);
MS2_REPLACE_METHOD(0x1412C7F40, UIHomeInfoDialog, SendRequestCubeMode31, 157, 0xC5195BF7);
MS2_REPLACE_METHOD(0x1412C7FF0, UIHomeInfoDialog, FUN_1412c7ff0, 461, 0xE69FF28C);
MS2_REPLACE_METHOD(0x1412C81D0, UIHomeInfoDialog, FUN_1412c81d0, 164, 0xB0D62B29);
MS2_REPLACE_METHOD(0x1412C8280, UIHomeInfoDialog, FUN_1412c8280, 164, 0x180D9578);
MS2_REPLACE_METHOD(0x1412C8950, UIHomeInfoDialog, vfunc_48, 11, 0x3523FE59);
