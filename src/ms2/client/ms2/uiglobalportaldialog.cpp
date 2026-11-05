// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGlobalPortalDialog: see uiglobalportaldialog.h.
// MS2-UNIT: ?\uiglobalportaldialog.cpp
// MS2-RANGE: 0x1412c2020-0x1412c3ac0 .text$mn
// MS2-RANGE: 0x1400ed3e0-0x1400ed4a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiglobalportaldialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiglobalportaldialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
class Unk_140acd6e0 : public ASButton {};   // C3: the button view of the definer's instantiation
class UICashAttendDialog { public: template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out); };   // C3: the child binder (0x140bc6d10, uicashattenddialog.cpp)

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> GpClickDelegate;

class Unk_GpButton : public ASButton
{
public:
    void FUN_1422ce240(const GpClickDelegate& onClick, int nFlags);     // click callback
};

class ASDialog : public ASDisplayObject
{
};

// The click event: the pressed button is read from +0x30.
struct Unk_GpParams { char m_pad[0x30]; void* m_pButton; };
int FUN_140bd09c0(void* pButton);                                       // which button

void FUN_140cfefe0(const Scaleform::GFx::Value& root, CString strName, CString strField, CStringW strText);   // set a text clip's text
CStringW GetStringCommonByKey(const CStringW& strKey);                         // the string table text
void FUN_1412751f0(const CStringW& text, int nA, int nB);               // the notice popup
CString FUN_14016a600(const wchar_t* pw, int n);                        // wide to narrow
int FUN_141276180(const CString& strName, const CString& strArg);      // play a system sound
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
int FUN_140768010(int, int);   // C3: was FUN_140768010
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
class CStateService;
template<> CStateService* TSingleton<CStateService>::GetInstance();   // statemanager.cpp defines s_instance
class CStateService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1417e2610();
};
int FUN_1418dd0d0();                                                    // the screen margin

// ---- statics (.text$di) ----

// @0x1400ed3e0
static CString s_aSortNames[7] = {CString("None"), CString("Buy"), CString("Like"), CString("PriceLow"),
                                  CString("PriceHigh"), CString("Create"), CString("EnumEnd")};

// @0x1412c2020
UIGlobalPortalDialog::UIGlobalPortalDialog()
{
    m_nShownEventId = 0;
    m_nShownParam = 0;
    FUN_141924170(1);
    FUN_141925e70(0, 1);
    FUN_141925e70(3, 1);
    m_nRetryTime = 0;
}

// @0x1412c2180
UIGlobalPortalDialog::~UIGlobalPortalDialog()
{
    m_enterButton1 = 0;
    m_enterButton2 = 0;
    m_enterButton3 = 0;
}

// @0x1412c22b0
CString UIGlobalPortalDialog::GetTypeName()
{
    return "GlobalPortalDialog";
}

// @0x1412c2300
void UIGlobalPortalDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    Unk_GpButton* pButton1 = reinterpret_cast<Unk_GpButton*>(reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<Unk_140acd6e0>("m_enterButton1", reinterpret_cast<MS2Ptr<Unk_140acd6e0>&>(m_enterButton1)).get());
    if (pButton1)
        ((class ASButton*)(m_enterButton1))->FUN_1422ce240(GpClickDelegate(this, &UIGlobalPortalDialog::SendGlobalPortal), (void *)(0));
    Unk_GpButton* pButton2 = reinterpret_cast<Unk_GpButton*>(reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<Unk_140acd6e0>("m_enterButton2", reinterpret_cast<MS2Ptr<Unk_140acd6e0>&>(m_enterButton2)).get());
    if (pButton2)
        ((class ASButton*)(m_enterButton2))->FUN_1422ce240(GpClickDelegate(this, &UIGlobalPortalDialog::SendGlobalPortal), (void *)(1));
    Unk_GpButton* pButton3 = reinterpret_cast<Unk_GpButton*>(reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<Unk_140acd6e0>("m_enterButton3", reinterpret_cast<MS2Ptr<Unk_140acd6e0>&>(m_enterButton3)).get());
    if (pButton3)
        ((class ASButton*)(m_enterButton3))->FUN_1422ce240(GpClickDelegate(this, &UIGlobalPortalDialog::SendGlobalPortal), (void *)(2));
    FUN_1412c2980();
}

// @0x1412c2730
void UIGlobalPortalDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        int nMargin = FUN_1418dd0d0() + 0x3c;
        pDialog->vfunc_2(8, 0, nMargin * -1);
    }
}

// @0x1412c27d0
void UIGlobalPortalDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_enterButton1 = 0;
    m_enterButton2 = 0;
    m_enterButton3 = 0;
    m_strCaption1 = m_strCaption2 = m_strCaption3 = L"";
}

// @0x1412c2880
void UIGlobalPortalDialog::vfunc_72()
{
    if (m_nRetryTime == 0)
        return;
    if (GetTickCountMs2() < m_nRetryTime)
        return;
    PC* pPlayer = static_cast<PC*>(((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    unsigned short nLimit = *reinterpret_cast<unsigned short*>(reinterpret_cast<Common::Constants::Value<unsigned int>*>(((char*)FUN_1401d3200()) + 0xe150)->Get());
    if (nLimit != 0 && (unsigned short)pPlayer->vfunc_78() < nLimit)
    {
        m_nRetryTime = 0;
        return;
    }
    m_nRetryTime = 0;
    if (((class CStateService*)(void*)(TSingleton<CStateService>::GetInstance()))->FUN_1417e2610() != 0x620000c)
        return;
    if (FUN_141924630() == 0)
        FUN_141924680();
    else
        FUN_1412c2980();
}

// @0x1412c2980
void UIGlobalPortalDialog::FUN_1412c2980()
{
    if (FUN_1422dc430() == 0)
        return;
    FUN_140cfefe0(FUN_1422dbc00(), "m_text", "textField", m_strText);
    if (m_strCaption1.IsEmpty() && m_strCaption2.IsEmpty() && m_strCaption3.IsEmpty())
    {
        vfunc_67();
    }
    else
    {
        if (m_enterButton1.get() != 0)
        {
            if (!m_strCaption1.IsEmpty())
            {
                m_enterButton1->vfunc_3(1);
                m_enterButton1->FUN_1422cdfb0(FUN_14028dfa0<CStringW>(L"s_massive_event_enter_button", GetStringCommonByKey(m_strCaption1)));
            }
            else
                m_enterButton1->vfunc_3(0);
        }
        if (m_enterButton2.get() != 0)
        {
            if (!m_strCaption2.IsEmpty())
            {
                m_enterButton2->vfunc_3(1);
                m_enterButton2->FUN_1422cdfb0(FUN_14028dfa0<CStringW>(L"s_massive_event_enter_button", GetStringCommonByKey(m_strCaption2)));
            }
            else
                m_enterButton2->vfunc_3(0);
        }
        if (m_enterButton3.get() != 0)
        {
            if (!m_strCaption3.IsEmpty())
            {
                m_enterButton3->vfunc_3(1);
                m_enterButton3->FUN_1422cdfb0(FUN_14028dfa0<CStringW>(L"s_massive_event_enter_button", GetStringCommonByKey(m_strCaption3)));
            }
            else
                m_enterButton3->vfunc_3(0);
        }
        if (!m_strSound.IsEmpty())
        {
            CString strArg("");
            FUN_141276180(FUN_14016a600(m_strSound, 0), strArg);
        }
    }
}

// @0x1412c3020
void UIGlobalPortalDialog::FUN_1412c3020(CInPacket& packet)
{
    int nType = packet.ReadUInt8();
    switch (nType)
    {
    case 0:
        FUN_1412c32a0(packet);
        break;
    case 1:
        FUN_1412c3640(packet);
        break;
    case 3:
        FUN_1412751f0(GetStringCommonByKey(L"s_massive_event_error_cant_enter_dead"), 1, 1);
        break;
    case 4:
        FUN_1412751f0(GetStringCommonByKey(L"s_massive_event_error_cant_enter_level_limit"), 1, 1);
        break;
    }
}

// @0x1412c31a0
void UIGlobalPortalDialog::SendGlobalPortal(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nButton = FUN_140bd09c0(((Unk_GpParams*)&params)->m_pButton);
    COutPacket packet(static_cast<int>(SendOp::GlobalPortal), 0);
    packet.WriteUInt8(2);
    packet.WriteInt32(m_nEventId);
    packet.WriteInt32(nButton);
    FUN_140710590(packet);
}

// @0x1412c3240
void UIGlobalPortalDialog::FUN_1412c3240(CInPacket& packet)
{
    m_nShownEventId = m_nEventId;
    m_nShownParam = m_nParam;
    vfunc_67();
}

// @0x1412c32a0
void UIGlobalPortalDialog::FUN_1412c32a0(CInPacket& packet)
{
    m_nEventId = packet.ReadInt32();
    m_nParam = packet.ReadInt32();
    m_strText = GetStringCommonByKey(packet.ReadUnicodeString());
    m_strSound = packet.ReadUnicodeString();
    m_strCaption1 = packet.ReadUnicodeString();
    m_strCaption2 = packet.ReadUnicodeString();
    m_strCaption3 = packet.ReadUnicodeString();
    if (m_nEventId == m_nShownEventId && m_nParam == m_nShownParam)
        return;
    m_nShownEventId = 0;
    m_nShownParam = 0;
    m_nRetryTime = GetTickCountMs2() + FUN_140768010(10000, 0);
}

// @0x1412c3640
void UIGlobalPortalDialog::FUN_1412c3640(CInPacket& packet)
{
    m_nEventId = 0;
    if (FUN_141924630() != 0)
        vfunc_67();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf1d0-0x142caf200 .text$yd
