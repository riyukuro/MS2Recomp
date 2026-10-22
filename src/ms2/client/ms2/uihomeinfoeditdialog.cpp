// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHomeInfoEditDialog: edit the home name and notice.
// MS2-UNIT: ?\uihomeinfoeditdialog.cpp
// MS2-RANGE: 0x140c26440-0x140c27340 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIHomeInfoEditDialog@@UEAAHXZ 0x140c27100 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?get@?$MS2Ptr@VUnk_HmInput@@@@QEBAPEAVUnk_HmInput@@XZ 0x140c270a0
// MS2-PIN: ??C?$MS2Ptr@VUnk_HmInput@@@@QEBAPEAVUnk_HmInput@@XZ 0x140c270b0
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

// ---- unit-local declarations (names describe uses, not original class names) ----

class ASDialog : public ASDisplayObject
{
};

// The two text inputs (m_homeName / m_homeNotice); they share the input base.
class Unk_HmInput : public ASDisplayObject
{
public:
    Unk_HmInput(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1422e4570
    void FUN_1422e0d60(int nMaxChars);
    void FUN_1422e0ab0(const CStringW& strText);
    CStringW FUN_1422e0b00();
private:
    char m_pad_40[0x88 - sizeof(ASDisplayObject)];
};

// The handle the home name input is moved into (its get / -> / release live in the unit that owns the shared instance).
struct Unk_HmPtrView { void* m_0; void* m_8; };                    // the layout of an MS2Ptr
struct Unk_HmNameRef
{
    Unk_HmNameRef(MS2Ptr<Unk_HmInput>&& o)                          // 0x140c26dc0
    {
        m_8 = reinterpret_cast<Unk_HmPtrView&>(o).m_8;
        reinterpret_cast<Unk_HmPtrView&>(o).m_8 = 0;
    }
    void* m_0;
    void* m_8;
};
int FUN_140bc0500(Unk_HmNameRef* p);                                // not null
Unk_HmInput* FUN_140bc0550(Unk_HmNameRef* p);                       // operator->
void FUN_140bbfdd0(Unk_HmNameRef* p);                               // release

// ---- out-of-unit callees ----
UIHomeInfoDialog* FUN_140bbea00(int nId);                           // dialog by its ui id
CStringW GetStringCommon(int nStringId);
class Unk_HmHome { public: CStringW FUN_1410c31d0(); };             // the owner name
Unk_HmHome* FUN_1409670e0();
int FUN_1406516a0();                                                // the locale index
class CMsgBoxData : public CPtred
{
public:
    char m_pad[0x2a0 - sizeof(CPtred)];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;
Unk_MsgBoxPtr FUN_140d73d20(int nType, CStringW text, void* p, CStringW tag);
void FUN_14151f150(Unk_MsgBoxPtr box);
void FUN_140710590(COutPacket& packet);
CommonString* FUN_14025e7d0();                                      // the CommonString singleton

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
template <> MS2Ptr<Unk_HmInput> AScript::FUN_140accef0<Unk_HmInput>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_ASCreate<Unk_HmInput>(m_nMovieId, v);
    return MS2Ptr<Unk_HmInput>(0);
}

// @0x140c26f60
template <> MS2Ptr<Unk_HmInput> UISwfEntity::GetChild<Unk_HmInput>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<Unk_HmInput>(0);
    return m_30->FUN_140accef0<Unk_HmInput>(strName);
}

// @0x140c26850
CStringW UIHomeInfoEditDialog::FUN_140c26850()
{
    UIHomeInfoDialog* pDlg = FUN_140bbea00(0x4ed8);
    if (pDlg != 0)
        return pDlg->FUN_1412c7090();
    return GetStringCommon(0x574);
}
MS2_REPLACE_METHOD(0x140C26850, UIHomeInfoEditDialog, FUN_140c26850, 114, 0x4162ADBB);

// @0x140c268d0
CStringW UIHomeInfoEditDialog::FUN_140c268d0()
{
    return FUN_1409670e0()->FUN_1410c31d0();
}
MS2_REPLACE_METHOD(0x140C268D0, UIHomeInfoEditDialog, FUN_140c268d0, 61, 0xA1A1AAFA);

// MS2-FUNCTIONAL: FUN_140c26920: 2 bytes shorter than the exe (range-check branch layout)
// @0x140c26920
int UIHomeInfoEditDialog::FUN_140c26920()
{
    int n = FUN_1406516a0();
    if (n >= 0)
    {
        if (n <= 1)
            return 8;
        if (n > 1)
        {
            if (n <= 7)
                return 0x10;
        }
    }
    return 0x10;
}
MS2_REPLACE_METHOD(0x140C26920, UIHomeInfoEditDialog, FUN_140c26920, 72, 0xC1F6E1C8);

// @0x140c26440
UIHomeInfoEditDialog::UIHomeInfoEditDialog()
{
    m_80 = 0;
    FUN_141924170(1);
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

// MS2-FUNCTIONAL: OnLoadComplete: the exe keeps extra pointer temps around each GetChild result (stack frame +0x30, extra stores)
// @0x140c26540
void UIHomeInfoEditDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    {
        Unk_HmNameRef spName = Unk_HmNameRef(GetChild<Unk_HmInput>("m_homeName"));
        if (FUN_140bc0500(&spName) != 0)
        {
            FUN_140bc0550(&spName)->FUN_1422e0d60(FUN_140c26920());
            FUN_140bc0550(&spName)->FUN_1422e0ab0(FUN_140c268d0());
        }
        FUN_140bbfdd0(&spName);
    }
    MS2Ptr<Unk_HmInput> spNotice = GetChild<Unk_HmInput>("m_homeNotice");
    if (spNotice.get() != 0)
    {
        spNotice.operator->()->FUN_1422e0d60(100);
        spNotice.operator->()->FUN_1422e0ab0(FUN_140c26850());
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

// MS2-FUNCTIONAL: OnConfirm: the exe keeps extra pointer temps around each GetChild result (stack frame +0x50)
// @0x140c26970
void UIHomeInfoEditDialog::OnConfirm()
{
    if (FUN_140bbea00(0x4ed8) != 0)
    {
        {
            Unk_HmNameRef spName = Unk_HmNameRef(GetChild<Unk_HmInput>("m_homeName"));
            if (FUN_140bc0500(&spName) != 0)
            {
                CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
                if (pChecker != 0)
                {
                    CStringW strMessage;
                    CStringW strName = FUN_140bc0550(&spName)->FUN_1422e0b00();
                    strName.Trim(L",");
                    if (pChecker->FUN_1402252f0(strName, strMessage) != 0)
                    {
                        Unk_MsgBoxPtr box = FUN_140d73d20(0, CStringW(strMessage), 0, CStringW(L""));
                        if (box.get() != 0)
                            FUN_14151f150(box);
                        FUN_140bbfdd0(&spName);
                        return;
                    }
                    COutPacket packet(0x37, 0);
                    packet.vfunc_o10_1(0x15);
                    packet.vfunc_o10_8(strName);
                    FUN_140710590(packet);
                }
            }
            FUN_140bbfdd0(&spName);
        }
        MS2Ptr<Unk_HmInput> spNotice = GetChild<Unk_HmInput>("m_homeNotice");
        if (spNotice.get() != 0)
        {
            COutPacket packet(0x37, 0);
            packet.vfunc_o10_1(0x1d);
            packet.vfunc_o10_8(spNotice.operator->()->FUN_1422e0b00());
            FUN_140710590(packet);
        }
    }
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140C26970, UIHomeInfoEditDialog, OnConfirm, 1102, 0x88F80B42);

MS2_EMIT_CRT_MEMMOVE_S();
