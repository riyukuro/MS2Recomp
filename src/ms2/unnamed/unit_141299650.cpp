// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeSummonDialog: see unit_141299650.h. w276.
// MS2-UNIT: unit_141299650
// MS2-RANGE: 0x141299650-0x14129a3c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIHomeSummonDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x14129a140 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIHomeSummonDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14129a290 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIHomeSummonDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14129a2f0 ; unique
// MS2-PIN: ??$Call@VUIHomeSummonDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIHomeSummonDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIHomeSummonDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14129a320 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIHomeSummonDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14129a360 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GUIHomeSummonDialog@@UEAAPEAXI@Z 0x14129a240
// MS2-PIN: ?vfunc_48@UIHomeSummonDialog@@UEAAHXZ 0x14129a280
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_141299650.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types ----

// The confirm button (click callback binding).
class Unk_SumButton : public ASDisplayObject
{
public:
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n);   // click callback
};

// The text input control.
class Unk_SumText : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                                   // the text
    void FUN_1422e0ab0(const CStringW& str);                    // set the text
    void FUN_1422e1500(int n1, int n2);                         // set the selection
    void FUN_1422e0e00(int n);                                  // max chars / mode
    void FUN_1422c7630(int n);                                  // focus
};

// Keyboard state (FUN_14025e7c0).
class Unk_SumKeys
{
public:
    bool FUN_14116d840();                                       // escape pressed
    bool FUN_14116d9c0(int nKey, int a, int b);                 // key pressed this frame
};
Unk_SumKeys* FUN_14025e7c0();

bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
CStringW FUN_14016a730(const char* psz, int n);                 // narrow -> wide
void FUN_140710590(COutPacket& packet);                         // send the packet
void FUN_14151f200();
void FUN_141901390(int nRelease, int nUiType);
void FUN_141925ec0(UIDialog* pDialog, CString strName);

// @0x141299650
UIHomeSummonDialog::UIHomeSummonDialog()
{
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x141299700
UIHomeSummonDialog::~UIHomeSummonDialog()
{
}

// @0x141299780
CString UIHomeSummonDialog::GetTypeName()
{
    return "HomeSummonDialog";
}
MS2_REPLACE_METHOD(0x141299780, UIHomeSummonDialog, GetTypeName, 61, 0x33952058);

// @0x1412997d0
void UIHomeSummonDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(0, 0, 0);
}
MS2_REPLACE_METHOD(0x1412997D0, UIHomeSummonDialog, vfunc_43, 161, 0xE18E81AB);

// @0x141299880
void UIHomeSummonDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.IsNull() != 0)
        return;
    FUN_141925ec0("m_closeButton");
    FUN_140bc6d10("m_confirmButton", m_180);
    m_180->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIHomeSummonDialog::OnConfirmClick), 0);
    FUN_14129a040("m_textInput", m_190);
    m_190->FUN_1422e0e00(1);
    m_190->FUN_1422c7630(1);
    FUN_141901390(0, vfunc_48());
}
MS2_REPLACE_METHOD(0x141299880, UIHomeSummonDialog, OnLoadComplete, 553, 0x9A682978);

// @0x141299ab0
void UIHomeSummonDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_141901390(1, vfunc_48());
}
MS2_REPLACE_METHOD(0x141299AB0, UIHomeSummonDialog, vfunc_26, 55, 0xB78B1840);

// @0x141299af0
// MS2-FUNCTIONAL: one byte (jmp distance) differs; else-branch jump layout
int UIHomeSummonDialog::vfunc_13()
{
    if (FUN_14025e7c0()->FUN_14116d840() != 0)
    {
        vfunc_67();
        return 1;
    }
    else
    {
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0) != 0)
        {
            CStringW strText = m_190->FUN_1422e0b00();
            if (!strText.IsEmpty())
                Summon();
        }
        return 0;
    }
}
MS2_REPLACE_METHOD(0x141299AF0, UIHomeSummonDialog, vfunc_13, 175, 0x2693CBDA);

// @0x141299bb0
void UIHomeSummonDialog::OnConfirmClick(const Scaleform::GFx::FunctionHandler::Params&)
{
    Summon();
}
MS2_REPLACE_METHOD(0x141299BB0, UIHomeSummonDialog, OnConfirmClick, 29, 0x39B85687);

// @0x141299be0
// MS2-FUNCTIONAL: the exe passes the typed text to the packet by value (extra CStringW copy)
void UIHomeSummonDialog::Summon()
{
    if (FUN_140ba28d0(&m_30, 0) != 0)
        return;
    if (m_190 == 0)
        return;
    CStringW strText = m_190->FUN_1422e0b00();
    if (strText.IsEmpty())
        return;
    if (strText.GetLength() < 2)
    {
        m_190->FUN_1422e0ab0(L"");
        m_190->FUN_1422e1500(0, 0);
    }
    else
    {
        COutPacket packet(0x37, 0);
        packet.vfunc_o10_1(0x1e);
        packet.vfunc_o10_8(FUN_14016a730(m_178, 0));
        packet.vfunc_o10_8(strText);
        FUN_140710590(packet);
        vfunc_67();
    }
}
MS2_REPLACE_METHOD(0x141299BE0, UIHomeSummonDialog, Summon, 488, 0x37D4682F);

// @0x141299dd0
int UIHomeSummonDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nResult == 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x141299DD0, UIHomeSummonDialog, IMessageListener, OnMessage, 203, 0x7FD5D781);

// @0x141299eb0
void UIHomeSummonDialog::SetName(CString strName)
{
    m_178 = strName;
}
MS2_REPLACE_METHOD(0x141299EB0, UIHomeSummonDialog, SetName, 65, 0x05FDD060);

// @0x14129a040
MS2Ptr<Unk_SumText> UIHomeSummonDialog::FUN_14129a040(const CString& strName, MS2Ptr<Unk_SumText>& out)
{
    out = FUN_140e35bd0(strName);
    return out;
}
