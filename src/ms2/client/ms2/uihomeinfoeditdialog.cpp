// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeInfoEditDialog: edit the home name and notice.
// MS2-UNIT: ?\uihomeinfoeditdialog.cpp
// MS2-RANGE: 0x140c26440-0x140c27340 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIHomeInfoEditDialog@@UEAAHXZ 0x140c27100 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??B?$MS2Ptr@VASTextArea@@@@QEBAPEAVASTextArea@@XZ 0x140c270a0
// MS2-PIN: ??C?$MS2Ptr@VASTextArea@@@@QEBAPEAVASTextArea@@XZ 0x140c270b0
// MS2-PIN: ??$?0VASTextArea@@@?$MS2Ptr@VASTextInput@@@@QEAA@$$QEAV?$MS2Ptr@VASTextArea@@@@@Z 0x140c26dc0 ; hand: converting move (MS2_PTR_MOVE_CONVERT)
#define MS2_PTR_MOVE_CONVERT
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihomeinfoeditdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uihomeinfoeditdialog.h"
#include "uihomeinfodialog.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/placeholder/astextarea.h"

// ---- unit-local declarations (names describe uses, not original class names) ----

class ASDialog : public ASDisplayObject
{
};

// The two text inputs (m_homeName / m_homeNotice) are ASTextArea children (MS2Ptr<ASTextArea> COMDATs 0x140c270a0 /
// 0x140c270b0). The home name is moved into an MS2Ptr<ASTextInput> by the converting move 0x140c26dc0.

// ---- out-of-unit callees ----
UIHomeInfoDialog* GetHomeInfoDialog(int nId);                           // dialog by its ui id
CStringW GetStringCommon(int nStringId);
class Unk_AkoHouseSvc   // C3: member view for the former free stand-in
{
public:
    static Unk_AkoHouseSvc* GetInstance();                              // the cube service singleton
};
int FUN_1406516a0();                                                // the locale index
class CMsgBoxData : public CPtred
{
public:
    char m_pad[0x2a0 - sizeof(CPtred)];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;
Unk_MsgBoxPtr CreateMessageBox(int nType, CStringW text, void* p, CStringW tag);
void FUN_14151f150(Unk_MsgBoxPtr box);
void FUN_140710590(COutPacket& packet);

extern template class MS2Ptr<CMsgBoxData>;                          // instances owned by other units
#ifndef MS2_HOOK_DLL
extern template class MS2Ptr<CBanTextChecker>;
#endif

// @0x140c26df0
template <class T> inline MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x140c26ea0
template <> MS2Ptr<ASTextArea> AScript::FUN_140accef0<ASTextArea>(const CString& strName)
{
    Scaleform::GFx::Value v = GetMember(strName);
    if (v.IsObject())
        return Unk_ASCreate<ASTextArea>(m_nMovieId, v);
    return MS2Ptr<ASTextArea>(0);
}

// @0x140c26f60
template <> MS2Ptr<ASTextArea> UISwfEntity::GetChild<ASTextArea>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<ASTextArea>(0);
    return m_30->FUN_140accef0<ASTextArea>(strName);
}

// @0x140c26850
CStringW UIHomeInfoEditDialog::FUN_140c26850()
{
    UIHomeInfoDialog* pDlg = GetHomeInfoDialog(0x4ed8);
    if (pDlg != 0)
        return pDlg->FUN_1412c7090();
    return GetStringCommon(0x574);
}
MS2_REPLACE_METHOD(0x140C26850, UIHomeInfoEditDialog, FUN_140c26850, 114, 0x4162ADBB);

// @0x140c268d0
CStringW UIHomeInfoEditDialog::GetHomeName()
{
    return ((CubeMapInformationService*)Unk_AkoHouseSvc::GetInstance())->FUN_1410c31d0();
}
MS2_REPLACE_METHOD(0x140C268D0, UIHomeInfoEditDialog, GetHomeName, 61, 0xA1A1AAFA);

// @0x140c26920
int UIHomeInfoEditDialog::FUN_140c26920()
{
    switch (FUN_1406516a0())
    {
    case 0:
    case 1:
        return 8;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        return 0x10;
    }
    return 0x10;
}
MS2_REPLACE_METHOD(0x140C26920, UIHomeInfoEditDialog, FUN_140c26920, 72, 0xC1F6E1C8);

// @0x140c26440
UIHomeInfoEditDialog::UIHomeInfoEditDialog()
{
    m_80 = 0;
    SetTweenEnabled(1);
}

// @0x140c264b0
UIHomeInfoEditDialog::~UIHomeInfoEditDialog()
{
}

// @0x140c264f0
CString UIHomeInfoEditDialog::GetTypeName()
{
    return "HomeInfoEditDialog";
}
MS2_REPLACE_METHOD(0x140C264F0, UIHomeInfoEditDialog, GetTypeName, 61, 0x94107E3F);

// @0x140c26540
void UIHomeInfoEditDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    if (MS2Ptr<ASTextInput> spName = GetChild<ASTextArea>("m_homeName"))
    {
        spName->SetMaxChars(FUN_140c26920());
        spName->SetTextW(GetHomeName());
    }
    if (MS2Ptr<ASTextArea> spNotice = GetChild<ASTextArea>("m_homeNotice"))
    {
        spNotice->SetMaxChars(100);
        spNotice->SetTextW(FUN_140c26850());
    }
}
MS2_REPLACE_METHOD(0x140C26540, UIHomeInfoEditDialog, OnLoadComplete, 548, 0x8AF667C3);

// @0x140c26770
void UIHomeInfoEditDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
        pDialog->vfunc_2(0, 0, 0);
}
MS2_REPLACE_METHOD(0x140C26770, UIHomeInfoEditDialog, vfunc_43, 100, 0x8C8D42B7);

// @0x140c267e0
int UIHomeInfoEditDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    UIDialog::vfunc_28(szMethod, pArgs, nArgs);
    if (_stricmp("OnConfirm", szMethod) == 0)
    {
        OnConfirm();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C267E0, UIHomeInfoEditDialog, vfunc_28, 94, 0xE55289F9);

// @0x140c26970
void UIHomeInfoEditDialog::OnConfirm()
{
    if (UIHomeInfoDialog* pInfo = GetHomeInfoDialog(0x4ed8))
    {
        if (MS2Ptr<ASTextInput> spName = GetChild<ASTextArea>("m_homeName"))
        {
            if (CBanTextChecker* pChecker = TSingleton<CommonString>::GetInstance()->GetChecker().get())
            {
                CStringW strMessage;
                CStringW strName = spName->GetText();
                strName.Trim(L",");
                if (pChecker->CheckHomeName(strName, strMessage) == 0)
                {
                    COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
                    packet.WriteUInt8(0x15);
                    packet.WriteUnicodeString(strName);
                    FUN_140710590(packet);
                }
                else
                {
                    Unk_MsgBoxPtr box = CreateMessageBox(0, CStringW(strMessage), 0, CStringW(L""));
                    if (box.get() != 0)
                        FUN_14151f150(box);
                    return;
                }
            }
        }
        if (MS2Ptr<ASTextArea> spNotice = GetChild<ASTextArea>("m_homeNotice"))
        {
            COutPacket packet(static_cast<int>(SendOp::RequestCube), 0);
            packet.WriteUInt8(0x1d);
            packet.WriteUnicodeString(spNotice->GetText());
            FUN_140710590(packet);
        }
    }
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140C26970, UIHomeInfoEditDialog, OnConfirm, 1102, 0x88F80B42);

MS2_EMIT_CRT_MEMMOVE_S();
