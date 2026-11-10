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
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/placeholder/asbutton.h"

// ---- unit-local views of exe types ----
class UICashAttendDialog { public: template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out); };   // C3: the child binder (0x140bc6d10, uicashattenddialog.cpp)
template <> MS2Ptr<ASTextInput> UISwfEntity::GetChild<ASTextInput>(const CString& strName);   // 0x140e35bd0, owned by uiinventorydialog

// Keyboard state (FUN_14025e7c0).
class Unk_SumKeys : public CInputKeyHandler {};
void* FUN_14025e7c0();

CStringW FUN_14016a730(const char* psz, int n);                 // narrow -> wide
void FUN_140710590(COutPacket& packet);                         // send the packet
void FUN_14151f200();
void FUN_141901390(int nRelease, int nUiType);
void BindCloseButton(UIDialog* pDialog, CString strName);

// @0x141299650
UIHomeSummonDialog::UIHomeSummonDialog()
{
    SetTweenEnabled(1);
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
    BindCloseButton("m_closeButton");
    reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_confirmButton", m_180);
    m_180->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIHomeSummonDialog::OnConfirmClick), (void*)0);
    FUN_14129a040("m_textInput", m_190);
    m_190.operator->()->SetEditable(1);
    m_190.operator->()->SetFocused(1);
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
    if (reinterpret_cast<Unk_SumKeys*>(FUN_14025e7c0())->IsEscapePressed() != 0)
    {
        vfunc_67();
        return 1;
    }
    else if (reinterpret_cast<Unk_SumKeys*>(FUN_14025e7c0())->WasKeyPressed(0x1c, 0, 0) != 0)
    {
        CStringW strText = m_190.operator->()->GetText();
        if (!strText.IsEmpty())
            Summon();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141299AF0, UIHomeSummonDialog, vfunc_13, 175, 0x2693CBDA);

// @0x141299bb0
void UIHomeSummonDialog::OnConfirmClick(const Scaleform::GFx::FunctionHandler::Params&)
{
    Summon();
}
MS2_REPLACE_METHOD(0x141299BB0, UIHomeSummonDialog, OnConfirmClick, 29, 0x39B85687);

// @0x141299be0
void UIHomeSummonDialog::Summon()
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0)
        return;
    if (m_190 == 0)
        return;
    CStringW strText = m_190.operator->()->GetText();
    if (strText.IsEmpty())
        return;
    if (strText.GetLength() < 2)
    {
        m_190.operator->()->SetTextW(L"");
        m_190.operator->()->FocusAndSetSelection(0, 0);
        return;
    }
    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
    packet.WriteUInt8(0x1e);
    packet.WriteUnicodeString(FUN_14016a730(m_178, 0));
    packet.WriteUnicodeString(strText);
    FUN_140710590(packet);
    vfunc_67();
}
MS2_REPLACE_METHOD(0x141299BE0, UIHomeSummonDialog, Summon, 488, 0x37D4682F);

// @0x141299dd0
int UIHomeSummonDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->PopInt();
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
MS2Ptr<ASTextInput> UIHomeSummonDialog::FUN_14129a040(const CString& strName, MS2Ptr<ASTextInput>& out)
{
    out = GetChild<ASTextInput>(strName);
    return out;
}
