// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCCubeNoticeDialog: see uiugccubenoticedialog.h.
// MS2-UNIT: unit_140faf840
// MS2-RANGE: 0x140faf840-0x140fb0190 .text$mn
// MS2-PIN: ??_GUIUGCCubeNoticeDialog@@UEAAPEAXI@Z 0x140fb0020
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugccubenoticedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiugccubenoticedialog.h"

#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/packet.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The message input ("m_textMessage"); its handle is a 16-byte MS2Ptr whose get / -> / release live in the unit that owns
// the shared instance.
class Unk_NcInput : public ASDisplayObject
{
public:
    CStringW FUN_1422e0b00();                                       // the text
};
struct Unk_NcInputRef { void* m_0; void* m_8; };                    // the layout of an MS2Ptr
int FUN_140bc0500(Unk_NcInputRef* p);                               // not null
Unk_NcInput* FUN_140bc0550(Unk_NcInputRef* p);                      // operator->
void FUN_140bbfdd0(Unk_NcInputRef* p);                              // release

// The distance slider ("m_sliderDistance"; uiupperhuddialog.cpp's Unk_HudSlider - this unit owns its GetChild
// instance); the value is a float.
class Unk_HudSlider : public ASDisplayObject
{
public:
    float FUN_1422ce630();
};
MS2Ptr<Unk_HudSlider> FUN_140a57ea0(int nId, const Scaleform::GFx::Value& v);
extern template class MS2Ptr<Unk_HudSlider>;                         // instances owned by uiupperhuddialog.cpp

void FUN_140710590(COutPacket& packet);
CommonString* FUN_14025e7d0();                                      // the CommonString singleton
void FUN_1412751f0(const CStringW& strMsg, int a, int b);           // show a notice message

#ifndef MS2_HOOK_DLL
extern template class MS2Ptr<CBanTextChecker>;
#endif

// The child getters are defined below (0x140fafed0 / 0x140faff90); declared first so OnApply does not instantiate.
template <> MS2Ptr<Unk_HudSlider> AScript::FUN_140accef0<Unk_HudSlider>(const CString& strName);
template <> MS2Ptr<Unk_HudSlider> UISwfEntity::GetChild<Unk_HudSlider>(const CString& strName);

// @0x140faf840
UIUGCCubeNoticeDialog::UIUGCCubeNoticeDialog()
{
}

// @0x140faf8a0
UIUGCCubeNoticeDialog::~UIUGCCubeNoticeDialog()
{
}

// @0x140faf900
void UIUGCCubeNoticeDialog::FUN_140faf900(CInPacket& packet)
{
    m_nCubeId = packet.vfunc_o8_3();
    m_strMessage = packet.vfunc_o8_8();
    m_nDistance = packet.vfunc_o8_1();
    FUN_141924680();
}
MS2_REPLACE_METHOD(0x140FAF900, UIUGCCubeNoticeDialog, FUN_140faf900, 222, 0x604A204E);

// @0x140faf9f0
CString UIUGCCubeNoticeDialog::vfunc_1()
{
    return "UGCCubeNoticeDialog";
}
MS2_REPLACE_METHOD(0x140FAF9F0, UIUGCCubeNoticeDialog, vfunc_1, 61, 0x169FEFBC);

// @0x140fafa40
void UIUGCCubeNoticeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925fa0(CString("m_dragBar"));
    FUN_141925ec0(CString("m_btnClose"));
    m_30.operator->()->Invoke("setData", CStringW(m_strMessage), m_nDistance);
}
MS2_REPLACE_METHOD(0x140FAFA40, UIUGCCubeNoticeDialog, OnLoadComplete, 280, 0xC0C93711);

// @0x140fafb60
int UIUGCCubeNoticeDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnApply", szMethod) == 0)
    {
        OnApply();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FAFB60, UIUGCCubeNoticeDialog, vfunc_28, 105, 0xA27700CA);

// @0x140fafbd0
// MS2-FUNCTIONAL: the exe keeps extra pointer temps around each GetChild result (stack frame +0x10), as in uihomeinfoeditdialog.cpp
void UIUGCCubeNoticeDialog::OnApply()
{
    Unk_NcInputRef spText = FUN_140e35bd0(CString("m_textMessage"));
    if (FUN_140bc0500(&spText) != 0)
        m_strMessage = FUN_140bc0550(&spText)->FUN_1422e0b00();
    FUN_140bbfdd0(&spText);
    {
        MS2Ptr<Unk_HudSlider> spSlider(GetChild<Unk_HudSlider>(CString("m_sliderDistance")));
        if (static_cast<Unk_HudSlider*>(spSlider) != 0)
            m_nDistance = (int)spSlider.operator->()->FUN_1422ce630();
    }
    CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker().get();
    if (pChecker != 0)
    {
        CStringW strMessage;
        if (pChecker->FUN_1402266e0(m_strMessage, strMessage) != 0)
        {
            FUN_1412751f0(strMessage, 1, 1);
            return;
        }
    }
    COutPacket packet(0x90, 0);
    packet.vfunc_o10_1(0xc);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_3(m_nCubeId);
    packet.vfunc_o10_8(m_strMessage);
    packet.vfunc_o10_1((char)m_nDistance);
    FUN_140710590(packet);
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140FAFBD0, UIUGCCubeNoticeDialog, OnApply, 760, 0x571ABD56);

// @0x140fafed0
template <> MS2Ptr<Unk_HudSlider> AScript::FUN_140accef0<Unk_HudSlider>(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return FUN_140a57ea0(m_nMovieId, v);
    return MS2Ptr<Unk_HudSlider>(0);
}

// @0x140faff90
template <> MS2Ptr<Unk_HudSlider> UISwfEntity::GetChild<Unk_HudSlider>(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<Unk_HudSlider>(0);
    return m_30->FUN_140accef0<Unk_HudSlider>(strName);
}

// @0x140fb0060
int UIUGCCubeNoticeDialog::vfunc_48()
{
    return 0x4f51;
}
MS2_REPLACE_METHOD(0x140FB0060, UIUGCCubeNoticeDialog, vfunc_48, 11, 0xE0D30C73);

// @0x140fb0070
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
