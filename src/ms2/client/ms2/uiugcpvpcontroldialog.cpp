// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUGCPVPControlDialog (UI type 0x4f64, "UGCPVPControlDialog"): the
// host's start panel of a user-made PvP map; six option flags that "OnStart" sends back. Class declared in this file
// (no known header).
// MS2-UNIT: ?\uiugcpvpcontroldialog.cpp
// MS2-RANGE: 0x140fb53d0-0x140fb5ca0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiugcpvpcontroldialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
int FUN_1409c1750(const Scaleform::GFx::Value& v);                      // Value -> bool
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);               // set an int

// The dialog's AS view: setData takes six flags.
class Unk_PvpAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140fb59b0(const char* szMethod, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4, unsigned char a5, unsigned char a6);
};

// UIUGCPVPControlDialog: RTTI .?AVUIUGCPVPControlDialog@@, vftables (primary) and +0x18 (IMessageListener).
class UIUGCPVPControlDialog : public UIDialog
{
public:
    UIUGCPVPControlDialog();                                                        // 0x140fb53d0
    virtual ~UIUGCPVPControlDialog();                                               //  0 0x140fb5460
    virtual CString GetTypeName();                                                      //  1 0x140fb54a0
    virtual void OnLoadComplete();                                                  // 22 0x140fb54f0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                    // 28 0x140fb5790
    virtual int vfunc_48() { return 0x4f64; }                                       // 48 (COMDAT 0x140fb5b70)

    unsigned char m_b178;                                                           // +0x178 the six option flags
    unsigned char m_b179;
    unsigned char m_b17a;
    unsigned char m_b17b;
    unsigned char m_b17c;
    unsigned char m_b17d;
};
MS2_CHECK_SIZE(UIUGCPVPControlDialog, 0x180);

// @0x140fb53d0
UIUGCPVPControlDialog::UIUGCPVPControlDialog()
{
    m_b178 = 0;
    m_b179 = 0;
    m_b17a = 0;
    m_b17b = 0;
    m_b17c = 0;
    m_b17d = 0;
}

// @0x140fb5460
UIUGCPVPControlDialog::~UIUGCPVPControlDialog()
{
}

// @0x140fb54a0
CString UIUGCPVPControlDialog::GetTypeName()
{
    return "UGCPVPControlDialog";
}
MS2_REPLACE_METHOD(0x140FB54A0, UIUGCPVPControlDialog, GetTypeName, 61, 0xC3897830);

// @0x140fb54f0
void UIUGCPVPControlDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_btnClose");
    if (m_30.get() != 0) {
        reinterpret_cast<Unk_PvpAS*>(m_30.operator->())->FUN_140fb59b0("setData", m_b178, m_b179, m_b17a, m_b17b, m_b17c, m_b17d);
    }
}
MS2_REPLACE_METHOD(0x140FB54F0, UIUGCPVPControlDialog, OnLoadComplete, 331, 0xB37C3AC3);

// The "start" panel arrives: the host's six option flags.
// @0x140fb5650
void FUN_140fb5650(UIUGCPVPControlDialog* pDialog, CInPacket* pPacket)
{
    pDialog->FUN_141924680();
    pDialog->m_b178 = pPacket->vfunc_o8_1();
    pDialog->m_b179 = pPacket->vfunc_o8_1();
    pDialog->m_b17a = pPacket->vfunc_o8_1();
    pDialog->m_b17b = pPacket->vfunc_o8_1();
    pDialog->m_b17c = pPacket->vfunc_o8_1();
    pDialog->m_b17d = pPacket->vfunc_o8_1();
}
MS2_REPLACE(0x140FB5650, FUN_140fb5650, 299, 0x336A81DA);

// @0x140fb5790
int UIUGCPVPControlDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnStart", szMethod) == 0) {
        if (nArgs >= 5) {
            int b0 = FUN_1409c1750(pArgs[0]);
            int b1 = FUN_1409c1750(pArgs[1]);
            int b2 = FUN_1409c1750(pArgs[2]);
            int b3 = FUN_1409c1750(pArgs[3]);
            int b4 = FUN_1409c1750(pArgs[4]);
            int b5 = FUN_1409c1750(pArgs[5]);
            COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
            packet.vfunc_o10_1(0xe);
            packet.vfunc_o10_1(1);
            packet.vfunc_o10_1(b0);
            packet.vfunc_o10_1(b1);
            packet.vfunc_o10_1(b2);
            packet.vfunc_o10_1(b3);
            packet.vfunc_o10_1(b4);
            packet.vfunc_o10_1(b5);
            FUN_140710590(packet);
        }
        vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140FB5790, UIUGCPVPControlDialog, vfunc_28, 535, 0x1CCC8F50);

// @0x140fb59b0
Scaleform::GFx::Value Unk_PvpAS::FUN_140fb59b0(const char* szMethod, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4, unsigned char a5, unsigned char a6)
{
    ASArgList args;
    args.FUN_1409b2800(6);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bccb0(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    FUN_1422bccb0(args.FUN_1409b1f70(5), a6);
    return FUN_1422bb8f0(szMethod, args);
}
MS2_REPLACE_METHOD(0x140FB59B0, Unk_PvpAS, FUN_140fb59b0, 369, 0x17A3D8C4);

// @0x140fb5b80
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
