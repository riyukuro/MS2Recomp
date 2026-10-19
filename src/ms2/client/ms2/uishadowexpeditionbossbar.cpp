// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIShadowExpeditionBossBar, its gauge clip
// ASScoreBoardGauge and the packet listener FieldGameScoreBoardCli: see uishadowexpeditionbossbar.h.
// MS2-UNIT: client\ms2\uishadowexpeditionbossbar.cpp
// MS2-RANGE: 0x140f9c1e0-0x140f9e200 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVFieldGameScoreBoardCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140f9db60 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVFieldGameScoreBoardCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f9dfc0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVFieldGameScoreBoardCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140f9e020 ; unique
// MS2-PIN: ??$Call@VFieldGameScoreBoardCli@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVFieldGameScoreBoardCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVFieldGameScoreBoardCli@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x140f9e050 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVFieldGameScoreBoardCli@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f9e080 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1ASScoreBoardGauge@@UEAA@XZ 0x140f9dca0
// MS2-PIN: ??_GASScoreBoardGauge@@UEAAPEAXI@Z 0x140f9de20
// MS2-PIN: ??_GUIShadowExpeditionBossBar@@UEAAPEAXI@Z 0x140f9de60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uishadowexpeditionbossbar.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uishadowexpeditionbossbar.h"

#include "ms2/ms2format.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The incoming packet stream (a sub-object at +8 of CInPacket) is a virtual reader.
class Unk_CInStream
{
public:
    virtual void vfunc_0();
    virtual unsigned char ReadByte();                               // 1
    virtual void vfunc_2();
    virtual int ReadInt();                                          // 3
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual CStringW ReadString();                                  // 8
};
class CInPacket { public: void* m_pad_00; Unk_CInStream m_stream; };
// Calls go through `(&packet.m_stream)->`: clang-cl devirtualizes a call on the embedded member itself.

// The packet manager: handlers are registered per opcode.
class Unk_140bccd50
{
public:
    void FUN_140da5180(int nOpcode, Delegate<void(CInPacket&)> handler);       // add
    void FUN_140da51e0(int nOpcode, Delegate<void(CInPacket&)> handler);       // remove
};
Unk_140bccd50* FUN_140bccd50();

// The ui service: dialog lookup by id.
class Unk_UiService { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_UiService* FUN_1403ed2b0();

// A string translator (singleton chain 0x140a87680 -> 0x140a87690).
class Unk_140a87690 { public: CStringW FUN_14087ede0(const CStringW& str); };
class Unk_140a87680 { public: Unk_140a87690* FUN_140a87690(); };
Unk_140a87680* FUN_140a87680();

// The movie root as a display object container (m_90 of UIDialog): children are added/removed by value.
class ASDialog : public ASDisplayObjectContainer {};

int FUN_141924630(UIDialog* pDlg);                                  // the dialog is open
int FUN_140f1ffe0(const int& n, int nMin, int nMax);                // clamp
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& n);      // formats one number argument
CStringW FUN_14052bd00(int nId, const CStringW& str);               // localized text of an id and a string
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
class ASGameEntity : public ASDisplayObject { public: virtual void vfunc_2(int, int, int); };
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

// ---- FieldGameScoreBoardCli + ASScoreBoardGauge ---------------------------------------------------------------------

// @0x140f9c1e0
FieldGameScoreBoardCli::FieldGameScoreBoardCli()
{
    m_nMode = 0;
    m_pDlg = 0;
    FUN_140bccd50()->FUN_140da5180(0xe1, Delegate<void(CInPacket&)>(this, &FieldGameScoreBoardCli::FUN_140f9c300));
}

// @0x140f9c280
FieldGameScoreBoardCli::~FieldGameScoreBoardCli()
{
    FUN_140bccd50()->FUN_140da51e0(0xe1, Delegate<void(CInPacket&)>(this, &FieldGameScoreBoardCli::FUN_140f9c300));
}

// @0x140f9c300
void FieldGameScoreBoardCli::FUN_140f9c300(CInPacket& packet)
{
    int nType = (&packet.m_stream)->ReadByte();
    switch (nType) {
    case 0:
        FUN_140f9c3a0(packet);
        break;
    case 1:
        FUN_140f9c520(packet);
        break;
    case 2:
        FUN_140f9c5b0(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x140F9C300, FieldGameScoreBoardCli, FUN_140f9c300, 140, 0xC9F8E29F);

// @0x140f9c3a0
void FieldGameScoreBoardCli::FUN_140f9c3a0(CInPacket& packet)
{
    m_nMode = (&packet.m_stream)->ReadByte();
    CStringW strTitle = (&packet.m_stream)->ReadString();
    strTitle = FUN_140a87680()->FUN_140a87690()->FUN_14087ede0(strTitle);
    int nCur = (&packet.m_stream)->ReadInt();
    int nMax = (&packet.m_stream)->ReadInt();
    FUN_140f9c610(strTitle, nCur, nMax);
}
MS2_REPLACE_METHOD(0x140F9C3A0, FieldGameScoreBoardCli, FUN_140f9c3a0, 369, 0xEFB6E87E);

// @0x140f9c520
void FieldGameScoreBoardCli::FUN_140f9c520(CInPacket& packet)
{
    int nCur = (&packet.m_stream)->ReadInt();
    if (m_pDlg == 0)
        return;
    m_pDlg->vfunc_84(nCur);
    m_pDlg->vfunc_85();
}
MS2_REPLACE_METHOD(0x140F9C520, FieldGameScoreBoardCli, FUN_140f9c520, 129, 0xDF4E6D51);

// @0x140f9c5b0
void FieldGameScoreBoardCli::FUN_140f9c5b0(CInPacket& packet)
{
    if (m_pDlg != 0) {
        if (FUN_141924630(m_pDlg) != 0) {
            m_pDlg->vfunc_67();
            m_pDlg = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x140F9C5B0, FieldGameScoreBoardCli, FUN_140f9c5b0, 89, 0x4027BBF2);

// The open dialog of an id, cast to its class (one copy per class).
// @0x140f9d8a0
UIDarkStreamScoreDialog* FUN_140f9d8a0(int nId)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIDarkStreamScoreDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140f9d940
UIShadowExpeditionBossBar* FUN_140f9d940(int nId)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIShadowExpeditionBossBar*>((UIObject*)p);
    }
    return 0;
}

// @0x140f9c610
void FieldGameScoreBoardCli::FUN_140f9c610(CStringW strTitle, int nCur, int nMax)
{
    switch (m_nMode) {
    case 1: {
        UIShadowExpeditionBossBar* pDlg = FUN_140f9d940(0x4f0e);
        if (pDlg != 0) {
            pDlg->FUN_140f9d1f0(nCur, nMax);
            pDlg->FUN_140f9d230(strTitle);
            m_pDlg = pDlg;
        }
        break;
    }
    case 2: {
        UIDarkStreamScoreDialog* pDlg = FUN_140f9d8a0(0x4ee4);
        if (pDlg != 0) {
            pDlg->vfunc_84(nCur);
            pDlg->FUN_140f35660(0);
            pDlg->FUN_140f356a0(1);
            m_pDlg = pDlg;
        }
        break;
    }
    case 3: {
        UIDarkStreamScoreDialog* pDlg = FUN_140f9d8a0(0x4ee4);
        if (pDlg != 0) {
            pDlg->vfunc_84(nCur);
            pDlg->FUN_140f35660(-80);
            pDlg->FUN_140f356a0(6);
            m_pDlg = pDlg;
        }
        break;
    }
    }
    if (m_pDlg == 0)
        return;
    if (FUN_141924630(m_pDlg) == 0)
        m_pDlg->FUN_141924680();
    else
        m_pDlg->vfunc_85();
}
MS2_REPLACE_METHOD(0x140F9C610, FieldGameScoreBoardCli, FUN_140f9c610, 479, 0x3368A4D1);

// @0x140f9c800
ASScoreBoardGauge::ASScoreBoardGauge(CString strLinkage)
    : ASMovieClip(strLinkage, 2)
{
}

// @0x140f9c890
void ASScoreBoardGauge::Init()
{
    do {
        FUN_140bc71c0("m_gauge", m_gauge);
        if (m_gauge == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                       MS2_THIS_FILE, MS2_LINE(128), __FUNCTION__));
    } while (0);
}
MS2_REPLACE_METHOD(0x140F9C890, ASScoreBoardGauge, Init, 366, 0x30FE2871);

// @0x140f9ca30
void ASScoreBoardGauge::FUN_140f9ca30(int nCur, int nMax, CStringW strTitle)
{
    int nPercent = (nCur * 100) / nMax;
    int nClamped = FUN_140f1ffe0(nPercent, 0, 100);
    if (m_gauge.get() != 0)
        m_gauge->Invoke("setValue", nCur, nMax, true);
    FUN_140cfee80(FUN_1422bb870(), "m_title", strTitle);
    FUN_140cfee80(FUN_1422bb870(), "m_progressText", FUN_14052bd00(0x98e, FUN_1401ceea0(L"{0}", nClamped)));
}
MS2_REPLACE_METHOD(0x140F9CA30, ASScoreBoardGauge, FUN_140f9ca30, 548, 0x79062904);

// ---- UIShadowExpeditionBossBar --------------------------------------------------------------------------------------

// @0x140f9cc60
UIShadowExpeditionBossBar::UIShadowExpeditionBossBar()
    : m_nCur(0), m_nMax(0)
{
    FUN_141924170(1);
    FUN_141925e70(1, 1);
}

// @0x140f9cd30
UIShadowExpeditionBossBar::~UIShadowExpeditionBossBar()
{
}

// @0x140f9cdb0
CString UIShadowExpeditionBossBar::vfunc_1()
{
    return "ShadowExpeditionBossBar";
}
MS2_REPLACE_METHOD(0x140F9CDB0, UIShadowExpeditionBossBar, vfunc_1, 61, 0x93704178);

// @0x140f9ce00
void UIShadowExpeditionBossBar::vfunc_43()
{
    UIDialog::vfunc_43();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->vfunc_2(1, 0, 0x8c);
}
MS2_REPLACE_METHOD(0x140F9CE00, UIShadowExpeditionBossBar, vfunc_43, 167, 0x5A3F8DCF);

// @0x140f9ceb0
void UIShadowExpeditionBossBar::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    CString strType(m_strTitle.IsEmpty() ? "UIScoreGaugeTypeB" : "UIScoreGaugeTypeA");
    if (m_pGauge.AssignRaw(new ASScoreBoardGauge(strType)).get() != 0) {
        m_pGauge->Init();
        m_90->FUN_1422c6900((*m_pGauge).FUN_1422bb890());
    }
    m_pGauge->FUN_140f9ca30(m_nCur, m_nMax, m_strTitle);
}
MS2_REPLACE_METHOD(0x140F9CEB0, UIShadowExpeditionBossBar, OnLoadComplete, 557, 0x161CA6FD);

// @0x140f9d0f0
void UIShadowExpeditionBossBar::vfunc_26()
{
    UIDialog::vfunc_26();
    if (m_pGauge.get() != 0) {
        m_90->FUN_1422c6b70((*m_pGauge).FUN_1422bb890());
        m_pGauge = 0;
    }
    m_strTitle = L"";
}
MS2_REPLACE_METHOD(0x140F9D0F0, UIShadowExpeditionBossBar, vfunc_26, 246, 0xC85CF14F);

// @0x140f9d1f0
void UIShadowExpeditionBossBar::FUN_140f9d1f0(int nCur, int nMax)
{
    m_nCur = nCur;
    m_nMax = nMax;
}
MS2_REPLACE_METHOD(0x140F9D1F0, UIShadowExpeditionBossBar, FUN_140f9d1f0, 45, 0xB629382D);

// @0x140f9d230
void UIShadowExpeditionBossBar::FUN_140f9d230(CStringW strTitle)
{
    m_strTitle = strTitle;
}
MS2_REPLACE_METHOD(0x140F9D230, UIShadowExpeditionBossBar, FUN_140f9d230, 65, 0x444C32F9);

// @0x140f9d280
void UIShadowExpeditionBossBar::vfunc_84(int nCur)
{
    m_nCur = nCur;
}
MS2_REPLACE_METHOD(0x140F9D280, UIShadowExpeditionBossBar, vfunc_84, 25, 0x9BF64FA6);

// @0x140f9d2a0
void UIShadowExpeditionBossBar::vfunc_85()
{
    if (m_30 == 0)
        return;
    if (m_pGauge == 0)
        return;
    m_pGauge->FUN_140f9ca30(m_nCur, m_nMax, m_strTitle);
}
MS2_REPLACE_METHOD(0x140F9D2A0, UIShadowExpeditionBossBar, vfunc_85, 190, 0x7EE2D026);

// @0x140f9d9e0 Invoke(name, int, int, bool)
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, int a2, bool a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bccb0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f9dea0
int UIShadowExpeditionBossBar::vfunc_48()
{
    return 0x4f0e;
}
MS2_REPLACE_METHOD(0x140F9DEA0, UIShadowExpeditionBossBar, vfunc_48, 11, 0xD609E02E);

// @0x140f9e0e0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
