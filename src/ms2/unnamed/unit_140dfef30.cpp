// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client side of the UGC OX quiz event ("ugcox"):
// the server's event packet handler (opcode 0x90's reply, FUN_140dff600) and the message boxes / packets the quiz
// dialogs send (create, enter, leave, finish, the host's chat commands), plus the dialog finders and the text builders.
// MS2-FUNCTIONAL: the MS2Ptr<CMsgBoxData> / CStringW template glue is not pinned (tplpin) and the EH tables differ by one byte in the box builders
// MS2-UNIT: unit_140dfef30
// MS2-RANGE: 0x1400d6d00-0x1400d6db0 .text$di
// MS2-RANGE: 0x140dfef30-0x140e01f50 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <vector>

#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/triggerservice.h"
#include "ms2/client/ms2/uimassiveevent.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiprizemoneydialog.h"
#include "ms2/client/ms2/uiquizhostdialog.h"
#include "ms2/client/ms2/uiquizoxcreatedialog.h"
#include "ms2/client/ms2/uiquizoxwelcomedialog.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/unnamed/unit_140e3efd0.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

// The OX quiz dialog itself (UI type 0x4f7d) lives in another unit; only the cast target and its button lookup are needed.
class UIOxQuizDialog : public UIDialog
{
};

// A child of the movie (a button): handle at +8, the dtor sits at 0x140acd6e0.
class Unk_OxButton : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(int bEnabled);
    void FUN_1422c7cd0(const Scaleform::GFx::Value& tooltip);
};
class Unk_OxHandle
{
public:
    Unk_OxButton* FUN_140acd9c0();
    Unk_OxButton* FUN_140acd9e0();
    void FUN_140acd6e0();
};
class Unk_OxMovieEntity : public UIDialog
{
public:
    Unk_OxHandle FUN_140bb4b10(const CString& strName);         // child lookup
};

// The UI manager (singleton 0x1403ed2b0).
class Unk_OxUIMgr
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                    // dialog by UI type
    void FUN_141adc530(int nId);                                // open
    void FUN_141adc5d0(int nId);                                // close (if open)
};
Unk_OxUIMgr* FUN_1403ed2b0();

// The client config's blocked-action flag set.
struct Unk_OxBanFlags { int FUN_1402c4c90(int nFlag); };
struct Unk_OxConfig { char m_pad_00[8]; Unk_OxBanFlags m_8; };
Unk_OxConfig* FUN_14025e7b0();

// The key binds (singleton 0x1409331f0).
class Unk_OxKeyBinds
{
public:
    int FUN_14142e7a0();                                        // 0 = no game pad
    void FUN_14142ece0(ATL::CAtlArray<unsigned int>& aIds);     // the key setting ids to refresh
    void FUN_14142f700();
};
Unk_OxKeyBinds* FUN_1409331f0();

// The command arguments of a chat / AS command ("/ugcox camera 3").
class Unk_OxArgs
{
public:
    int FUN_1408d1f60(unsigned nIndex, int nDefault);
    CStringW FUN_1408d21c0(int nIndex, CStringW strDefault);
};

WorldService* FUN_1403ed2d0();
CTriggerService* FUN_140ad4b90();
void* FUN_1403b4750();
void FUN_1416fb300(void* p, const CStringW& str);                // remember the host's notice
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);     // str equals psz
CStringW FUN_140298ea0(CStringW strKey);                         // localized string
CStringW GetStringCommonByKey(const CStringW& strKey);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_140710590(COutPacket& packet);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
Delegate<bool(int, const CMsgBoxData&)> FUN_140b76b10(bool (*pfn)(int, const CMsgBoxData&));
CStringW FUN_140719630(int n);
CStringW FUN_140719a00(__int64 n);
CStringW FUN_1409404f0(__int64 n);
__int64 FUN_140718320(const CStringW& str);
CString FUN_140540050(const char* pszFormat, const CString& strArg);
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);
CStringW FUN_140560c00(const wchar_t* pszFormat, const unsigned& nArg);
void FUN_140e6e8b0(bool bOn);
void FUN_140e6e6c0(UIOxQuizDialog* pDialog, float fA, float fB);
void FUN_1402a9d70(void*, int, float, float, float, int);
void FUN_142ca6130();                                            // the exe's atexit destructor of the marker
extern __int64 DAT_143ab2820;                                    // the own account id
extern __int64 DAT_143ab2898;                                    // the money
struct Unk_OxMarker {};

// this unit's own state
// @0x143ac54f0
static bool s_bHost;
// @0x143ac54f4
static int s_nPromoteCount;
// @0x1439f5fb4
static int s_nCameraObject = -1;
// @0x1439f5fb8
static int s_nPromoteTotal = 3;
// @0x1439f5fbc
static unsigned s_nPromoteCooltime = 60000;

// ---- dynamic initializers (.text$di) ----

// @0x1400d6d00
static CString s_skill("skill");

// @0x1400d6d30
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x1400d6d60
static char s_marker[0x48];
static Unk_OxMarker s_initMarker = (FUN_1402a9d70(&s_marker, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142ca6130), Unk_OxMarker());
#endif

// forward declarations of this unit's handlers
void FUN_140e00250(CInPacket& packet);
void FUN_140e003b0(CInPacket& packet);
void FUN_140e005a0(CInPacket& packet);
void FUN_140e00690(CInPacket& packet);
void FUN_140e00b40(unsigned char nType, CInPacket& packet);
void FUN_140e00d90(unsigned char nType, int nSub);
void FUN_140e00f00(unsigned char nType, int nSub);
void FUN_140e00fd0();
void FUN_140e010c0(CInPacket& packet);
void FUN_140e011c0(CStringW& strOut, const CStringW& strName, __int64 nFee, int nMax, int nShareRate);
void FUN_140e013e0(CStringW& strOut, const CStringW& strName);
void FUN_140dfef30(CInPacket& packet);
bool FUN_140dff210(int nResult, const CMsgBoxData& box);
bool FUN_140dff700(int nResult, const CMsgBoxData& box);
bool FUN_140dff8d0(int nResult, const CMsgBoxData& box);
bool FUN_140dffad0(int nResult, const CMsgBoxData& box);
bool FUN_140dffdf0(int nResult, const CMsgBoxData& box);
void FUN_140e01480(int nPromoted, unsigned nCooltime, int nTotal, unsigned nCooltime2);
UIQuizOXCreateDialog* FUN_140e01b10(int nId);
UIQuizHostDialog* FUN_140e01a70(int nId);
UIPrizeMoneyDialog* FUN_140e019d0(int nId);
UIQuizOXWelcomeDialog* FUN_140e01bb0(int nId);
UIMassiveEvent* FUN_140e01890(int nId);
UIOxQuizDialog* FUN_140e01930(int nId);

// @0x140dfef30
void FUN_140dfef30(CInPacket& packet)
{
    MyPC* pMyPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pMyPC == 0)
        return;
    CStringW strName = packet.vfunc_o8_8();
    __int64 nFee = packet.vfunc_o8_4();
    int nMax = packet.vfunc_o8_3();
    int nShareRate = packet.vfunc_o8_3();
    CStringW strMsg;
    FUN_140e011c0(strMsg, strName, nFee, nMax, nShareRate);
    CStringW strTitle = FUN_140298ea0(CStringW(L"s_ugcox_create_confirm"));
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(0x27));
    spBox->SetMsg(strMsg);
    spBox->FUN_141a01800(1);
    spBox->SetTitle(strTitle);
    spBox->FUN_141a027c0(FUN_140b76b10(FUN_140dff210));
    FUN_140d73c60(spBox);
}

// @0x140dff210
bool FUN_140dff210(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(3);
    FUN_140710590(packet);
    FUN_140e6e8b0(false);
    FUN_1403ed2b0()->FUN_141adc5d0(0x4f7d);
    return true;
}

// @0x140dff2b0
void FUN_140dff2b0()
{
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x3d) == 1)
    {
        CStringW strMsg = FUN_140298ea0(CStringW(L"s_ugcox_create_fail_shutdown"));
        FUN_1412751f0(strMsg, 1, 1);
    }
    else
    {
        MyPC* pMyPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pMyPC == 0)
            return;
        COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
        packet.vfunc_o10_1(10);
        packet.vfunc_o10_1(1);
        FUN_140710590(packet);
    }
}

// @0x140dff3a0
void FUN_140dff3a0(__int64 nId, const CStringW& strName, __int64 nFee, int nMax, int nShareRate)
{
    CStringW strMsg;
    FUN_140e011c0(strMsg, strName, nFee, nMax, nShareRate);
    CStringW strTitle;
    FUN_140e013e0(strTitle, strName);
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(0x27));
    spBox->SetMsg(strMsg);
    spBox->FUN_141a01800(1);
    spBox->SetTitle(strTitle);
    spBox->FUN_141a027c0(FUN_140b76b10(FUN_140dff8d0));
    spBox->FUN_1405340b0(nId);
    FUN_140d73c60(spBox);
}

// @0x140dff580
void FUN_140dff580(int nA, int nB)
{
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(5);
    packet.vfunc_o10_3(nA);
    packet.vfunc_o10_3(nB);
    FUN_140710590(packet);
}

// The server's quiz event packet: the sub type picks the handler.
// @0x140dff600
void FUN_140dff600(CInPacket& packet)
{
    unsigned char nSub = packet.vfunc_o8_1();
    switch (nSub)
    {
    case 0:
        FUN_140e00250(packet);
        break;
    case 4:
        FUN_140e003b0(packet);
        break;
    case 1:
        FUN_140e005a0(packet);
        break;
    case 2:
        FUN_140dfef30(packet);
        break;
    case 5:
        FUN_140e00690(packet);
        break;
    case 0xd:
    case 0xe:
    case 0xf:
        FUN_140e00b40(nSub, packet);
        break;
    case 0xc:
        FUN_140e010c0(packet);
        break;
    }
}

// The enter confirmation's result.
// @0x140dff700
bool FUN_140dff700(int nResult, const CMsgBoxData& box)
{
    MyPC* pMyPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pMyPC == 0)
        return true;
    if (nResult == 0)
    {
        int nMapId = 0;
        int nPortalId = 0;
        __int64 nFee = 0;
        box.FUN_140961900(0, nMapId);
        box.FUN_140961900(1, nPortalId);
        box.FUN_140e01c50(2, nFee);
        if (DAT_143ab2898 < nFee)
        {
            CStringW strMsg = FUN_140298ea0(L"s_ugcox_enter_fail_entry_fee_lack");
            FUN_1412751f0(strMsg, 1, 1);
            return true;
        }
        pMyPC->SendRequestMoveFieldMode0(nMapId, nPortalId, 0, 0, L"", L"");
    }
    return true;
}

// @0x140dff8d0
bool FUN_140dff8d0(int nResult, const CMsgBoxData& box)
{
    MyPC* pMyPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pMyPC == 0)
        return true;
    if (nResult == 0)
    {
        __int64 nMoney = 0;
        box.FUN_140b19130(0, nMoney);
        pMyPC->SendRequestMoveFieldMode2(0, 0, 0, nMoney, CStringW(L""));
    }
    return true;
}

// The host's finish confirmation (called by the host dialog's "OnFinishEvent").
// @0x140dff970
void FUN_140dff970()
{
    CStringW strMsg = FUN_140298ea0(L"s_ugcox_finish_warning_host");
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(1));
    spBox->SetMsg(strMsg);
    spBox->FUN_141a01800(1);
    spBox->FUN_141a027c0(FUN_140b76b10(FUN_140dffad0));
    FUN_140d73c60(spBox);
}

// @0x140dffad0
bool FUN_140dffad0(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(8);
    FUN_140710590(packet);
    return true;
}

// @0x140dffb50
void FUN_140dffb50(void* pListener)
{
    CStringW strMsg;
    if (s_bHost)
    {
        strMsg = FUN_140298ea0(L"s_ugcox_leave_warning_host");
        FUN_1416fb300(FUN_1403b4750(), strMsg);
    }
    else
    {
        strMsg = FUN_140298ea0(L"s_ugcox_leave_warning_entry");
    }
    MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(1));
    spBox->SetMsg(strMsg);
    spBox->FUN_141a01800(1);
    spBox->FUN_141a027c0(FUN_140b76b10(FUN_140dffdf0));
    spBox->FUN_141a02860(pListener);
    spBox->SetExtra(L"leaveInField");
    FUN_140d73c60(spBox);
}

// @0x140dffdf0
bool FUN_140dffdf0(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    if (s_bHost)
    {
        COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
        packet.vfunc_o10_1(10);
        packet.vfunc_o10_1(9);
        FUN_140710590(packet);
    }
    COutPacket packet(static_cast<int>(SendOp::RequestMoveField), 0);
    packet.vfunc_o10_1(1);
    FUN_140710590(packet);
    return true;
}

// The host dialog's chat command from the movie ("camera", "next", "answer", "remove_wall", "resurrect").
// @0x140dffeb0
int FUN_140dffeb0(Unk_OxArgs* pArgs)
{
    CStringW strCmd = pArgs->FUN_1408d21c0(1, L"");
    if (FUN_1403b3c40(strCmd, L"camera"))
    {
        int nObject = pArgs->FUN_1408d1f60(2, 0);
        if (0 < nObject)
        {
            FUN_140ad4b90()->FUN_1418631c0();
            if (s_nCameraObject != nObject)
            {
                s_nCameraObject = nObject;
                FUN_140ad4b90()->FUN_1418631f0(nObject, 1);
            }
            else
            {
                s_nCameraObject = -1;
                FUN_140ad4b90()->FUN_1418631f0(nObject, 0);
            }
        }
    }
    else if (FUN_1403b3c40(strCmd, L"next"))
    {
        COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
        packet.vfunc_o10_1(10);
        packet.vfunc_o10_1(0x10);
        FUN_140710590(packet);
    }
    else if (FUN_1403b3c40(strCmd, L"answer"))
    {
        CStringW strAnswer = pArgs->FUN_1408d21c0(2, L"");
        if (FUN_1403b3c40(strAnswer, L"o"))
        {
            COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
            packet.vfunc_o10_1(10);
            packet.vfunc_o10_1(0xb);
            packet.vfunc_o10_1(1);
            FUN_140710590(packet);
        }
        else if (FUN_1403b3c40(strAnswer, L"x"))
        {
            COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
            packet.vfunc_o10_1(10);
            packet.vfunc_o10_1(0xb);
            packet.vfunc_o10_1(0);
            FUN_140710590(packet);
        }
    }
    else if (FUN_1403b3c40(strCmd, L"remove_wall"))
    {
        COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
        packet.vfunc_o10_1(10);
        packet.vfunc_o10_1(0x11);
        FUN_140710590(packet);
    }
    else if (FUN_1403b3c40(strCmd, L"resurrect"))
    {
        COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
        packet.vfunc_o10_1(10);
        packet.vfunc_o10_1(0x12);
        FUN_140710590(packet);
    }
    return 1;
}

// Sub 0: the allowed entry fees for the create dialog.
// @0x140e00250
void FUN_140e00250(CInPacket& packet)
{
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x3d) == 1)
    {
        CStringW strMsg = FUN_140298ea0(CStringW(L"s_ugcox_create_fail_shutdown"));
        FUN_1412751f0(strMsg, 1, 1);
    }
    else
    {
        std::vector<int> fees;
        int nCount = packet.vfunc_o8_1();
        for (int i = 0; i < nCount; i++)
        {
            fees.push_back(packet.vfunc_o8_3());
        }
        UIQuizOXCreateDialog* pDialog = FUN_140e01b10(0x4f47);
        if (pDialog != 0)
            pDialog->SetFees(fees);
    }
}

// Sub 4: the event was created.
// @0x140e003b0
void FUN_140e003b0(CInPacket& packet)
{
    FUN_140e6e8b0(true);
    FUN_1403ed2b0()->FUN_141adc530(0x4f7d);
    FUN_1403ed2b0()->FUN_141adc5d0(0x4f47);
    __int64 nFee = packet.vfunc_o8_4();
    int nPromoted = packet.vfunc_o8_3();
    unsigned nCooltime = packet.vfunc_o8_3();
    int nTotal = packet.vfunc_o8_3();
    unsigned nCooltime2 = packet.vfunc_o8_3();
    CStringW strMsg = GetStringCommonByKey(L"s_ugcox_create_complete");
    strMsg.Replace(L"{eventFee}", (LPCWSTR)FUN_1409404f0(nFee));
    FUN_1412751f0(strMsg, 3, 1);
    FUN_140e01480(nPromoted, nCooltime, nTotal, nCooltime2);
}

// Sub 1: the promote counters.
// @0x140e005a0
void FUN_140e005a0(CInPacket& packet)
{
    int nUnused = packet.vfunc_o8_1();
    int nPromoted = packet.vfunc_o8_3();
    unsigned nCooltime = packet.vfunc_o8_3();
    int nTotal = packet.vfunc_o8_3();
    unsigned nCooltime2 = packet.vfunc_o8_3();
    FUN_140e01480(nPromoted, nCooltime, nTotal, nCooltime2);
}

// Sub 5: somebody created an event (move there, or the host entering).
// @0x140e00690
void FUN_140e00690(CInPacket& packet)
{
    int nMapId = packet.vfunc_o8_3();
    int nPortalId = packet.vfunc_o8_3();
    __int64 nHostId = packet.vfunc_o8_4();
    CStringW strName = packet.vfunc_o8_8();
    __int64 nFee = packet.vfunc_o8_4();
    int nMax = packet.vfunc_o8_3();
    int nShareRate = packet.vfunc_o8_3();
    if (nHostId == DAT_143ab2820)
    {
        MyPC* pMyPC = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pMyPC != 0)
            pMyPC->SendRequestMoveFieldMode0(nMapId, nPortalId, 0, 0, CStringW(L""), CStringW(L""));
    }
    else
    {
        CStringW strMsg;
        FUN_140e011c0(strMsg, strName, nFee, nMax, nShareRate);
        MS2Ptr<CMsgBoxData> spBox(new CMsgBoxData(0x27));
        spBox->SetMsg(strMsg);
        spBox->FUN_141a01800(1);
        spBox->SetTitle(GetStringCommonByKey(CStringW(L"s_ugcox_move_eventmap_confirm")));
        spBox->FUN_141a027c0(FUN_140b76b10(FUN_140dff700));
        spBox->FUN_140534050(nMapId);
        spBox->FUN_140534050(nPortalId);
        spBox->FUN_140e01830(nFee);
        FUN_140d73c60(spBox);
    }
}

// Subs 0xd..0xf: the quiz state (0xd start, 0xe running, 0xf end).
// @0x140e00b40
void FUN_140e00b40(unsigned char nType, CInPacket& packet)
{
    __int64 nHostId = packet.vfunc_o8_4();
    int nStep = packet.vfunc_o8_1();
    int nRound = packet.vfunc_o8_1();
    __int64 nPrize1 = packet.vfunc_o8_4();
    __int64 nPrize2 = packet.vfunc_o8_4();
    UIPrizeMoneyDialog* pPrize = FUN_140e019d0(0x4f46);
    if (pPrize != 0)
    {
        if (pPrize->FUN_141924630() == 0)
            pPrize->FUN_141924680();
        FUN_140e78330(pPrize, nPrize1, nPrize2);
    }
    UIQuizHostDialog* pHost = FUN_140e01a70(0x4f44);
    if (pHost != 0)
        FUN_140e7df20(pHost, nRound);
    s_bHost = nHostId == DAT_143ab2820;
    if (!s_bHost)
    {
        UIMassiveEvent* pEvent = FUN_140e01890(0x4e4c);
        if (pEvent != 0)
            pEvent->FUN_1419f6df0(nRound, 10, 1, 0);
    }
    if (nType == 0xf)
    {
        if (s_bHost)
        {
            if (FUN_1409331f0()->FUN_14142e7a0() == 0)
                FUN_140e00fd0();
        }
    }
    else if (s_bHost)
    {
        FUN_140e00d90(nType, nStep);
    }
    else
    {
        FUN_140e00f00(nType, nStep);
    }
}

// The host's view of the state change.
// @0x140e00d90
void FUN_140e00d90(unsigned char nType, int nStep)
{
    if (nType == '\r')
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4f46);
        if (nStep == 10)
        {
            UIQuizOXWelcomeDialog* pWelcome = FUN_140e01bb0(0x4f48);
            if (pWelcome != 0)
            {
                pWelcome->FUN_141924680();
                FUN_140e7f110(pWelcome, true);
            }
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f44);
        }
        else if (nStep == 0xb)
        {
            FUN_140e00fd0();
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f48);
            UIQuizHostDialog* pHost = FUN_140e01a70(0x4f44);
            if (pHost != 0)
                pHost->FUN_141924680();
        }
        else
        {
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f48);
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f44);
            FUN_1409331f0()->FUN_14142f700();
        }
    }
    else if (nType == '\x0e')
    {
        if (nStep == 0xb)
        {
            FUN_140e00fd0();
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f48);
            UIQuizHostDialog* pHost = FUN_140e01a70(0x4f44);
            if (pHost != 0)
                pHost->FUN_141924680();
        }
        else
        {
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f48);
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f44);
            FUN_1409331f0()->FUN_14142f700();
        }
    }
}

// The entrants' view of the state change.
// @0x140e00f00
void FUN_140e00f00(unsigned char nType, int nStep)
{
    if (nType == '\r')
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4f46);
        if (nStep == 10)
        {
            UIQuizOXWelcomeDialog* pWelcome = FUN_140e01bb0(0x4f48);
            if (pWelcome != 0)
            {
                pWelcome->FUN_141924680();
                FUN_140e7f110(pWelcome, false);
            }
        }
        else if (nStep == 0xb)
        {
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f48);
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f44);
        }
    }
    else if (nType == '\x0e')
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f48);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f44);
    }
}

// Refresh the key settings the quiz host dialog reacts to.
// @0x140e00fd0
void FUN_140e00fd0()
{
    ATL::CAtlArray<unsigned int> aIds;
    aIds.Add(0);
    aIds.Add(0);
    aIds.Add(0);
    aIds.Add(0);
    aIds.Add(0);
    aIds.Add(0);
    aIds.Add(0);
    aIds.Add(0);
    aIds.Add(0x1c9c703);
    aIds.Add(0x1c9c704);
    aIds.Add(0x1c9c705);
    aIds.Add(0x1c9c706);
    aIds.Add(0x1c9c707);
    FUN_1409331f0()->FUN_14142ece0(aIds);
}

// Sub 0xc: the host dialog's submit / finish buttons.
// @0x140e010c0
void FUN_140e010c0(CInPacket& packet)
{
    int nMode = packet.vfunc_o8_1();
    int nCount = packet.vfunc_o8_1();
    UIQuizHostDialog* pHost = FUN_140e01a70(0x4f44);
    if (pHost != 0)
    {
        if (nMode == 1)
        {
            FUN_140e7e030(pHost, true);
            FUN_140e7dfb0(pHost);
        }
        else
        {
            FUN_140e7e030(pHost, false);
        }
        FUN_140e7e0b0(pHost, nCount > 1);
    }
    if (nMode == 3)
        FUN_1403ed2b0()->FUN_141adc530(0x4f45);
    else
        FUN_1403ed2b0()->FUN_141adc5d0(0x4f45);
}

// The rule notice text.
// @0x140e011c0
void FUN_140e011c0(CStringW& strOut, const CStringW& strName, __int64 nFee, int nMax, int nShareRate)
{
    strOut = GetStringCommonByKey(L"s_ugcox_rule_notify");
    strOut.Replace(L"{name}", (LPCWSTR)strName);
    strOut.Replace(L"{entryFee}", (LPCWSTR)FUN_1409404f0(nFee));
    strOut.Replace(L"{entryMax}", (LPCWSTR)FUN_140719630(nMax));
    strOut.Replace(L"{shareRateHost}", (LPCWSTR)FUN_140719630(100 - nShareRate));
    strOut.Replace(L"{shareRateEntry}", (LPCWSTR)FUN_140719630(nShareRate));
}

// @0x140e013e0
void FUN_140e013e0(CStringW& strOut, const CStringW& strName)
{
    {
        CStringW strKey(L"s_ugcox_move_home_confirm");
        strOut = GetStringCommonByKey(strKey);
    }
    strOut.Replace(L"{name}", (LPCWSTR)strName);
}

// The promote button of the OX quiz dialog: tooltip and enabled state.
// @0x140e01480
void FUN_140e01480(int nPromoted, unsigned nCooltime, int nTotal, unsigned nCooltime2)
{
    s_nPromoteTotal = nTotal;
    s_nPromoteCooltime = nCooltime2;
    s_nPromoteCount = nPromoted;
    int nTotalCount = nTotal;
    unsigned nCooltimeMs = nCooltime2;
    UIOxQuizDialog* pQuiz = FUN_140e01930(0x4f7d);
    if (pQuiz != 0)
    {
        Unk_OxHandle hButton = static_cast<Unk_OxMovieEntity*>(static_cast<UIDialog*>(pQuiz))->FUN_140bb4b10("m_quiz_promote");
        if (hButton.FUN_140acd9c0() != 0)
        {
            CStringW strTip = GetStringCommonByKey(CStringW(L"s_ugcox_btn_quiz_promote_tooltip"));
            strTip.Replace(L"{totalPromoteCount}", (LPCWSTR)FUN_1401ceea0(L"{0}", nTotalCount));
            int nLeft = nTotalCount - nPromoted;
            strTip.Replace(L"{promoteCount}", (LPCWSTR)FUN_1401ceea0(L"{0}", nLeft));
            unsigned nSeconds = nCooltimeMs / 1000;
            strTip.Replace(L"{promoteCooltime}", (LPCWSTR)FUN_140560c00(L"{0}", nSeconds));
            ASTooltip tip(2);
            tip.FUN_1409c6d70("export_common_tooltip_tooltipText");
            tip.FUN_1409c6cb0(strTip);
            tip.FUN_1409c6e00(300);
            tip.FUN_1409c6e30(5000);
            tip.FUN_1409c6dc0(5);
            hButton.FUN_140acd9e0()->FUN_1422c7cd0(tip.FUN_1422bb890());
            bool bEnabled = nPromoted < nTotalCount;
            hButton.FUN_140acd9e0()->FUN_1422c1fe0(bEnabled);
            if (nPromoted < nTotalCount)
                FUN_140e6e6c0(pQuiz, (float)nCooltime / 1000.0f, (float)s_nPromoteCooltime / 1000.0f);
        }
        hButton.FUN_140acd6e0();
    }
}

// @0x140e01830
void CMsgBoxData::FUN_140e01830(__int64 n)
{
    m_args.Add(FUN_140719a00(n));
}

// @0x140e01890
UIMassiveEvent* FUN_140e01890(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIMassiveEvent*>((UIObject*)p);
    }
    return 0;
}

// @0x140e01930
UIOxQuizDialog* FUN_140e01930(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIOxQuizDialog*>((UIObject*)p);
    }
    return 0;
}

// The dialog finders: the UI manager's dialog of a UI type, cast to its class.
// @0x140e019d0
UIPrizeMoneyDialog* FUN_140e019d0(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIPrizeMoneyDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140e01a70
UIQuizHostDialog* FUN_140e01a70(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIQuizHostDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140e01b10
UIQuizOXCreateDialog* FUN_140e01b10(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIQuizOXCreateDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140e01bb0
UIQuizOXWelcomeDialog* FUN_140e01bb0(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIQuizOXWelcomeDialog*>((UIObject*)p);
    }
    return 0;
}

// The i-th message box argument as an __int64 (the entry fee).
// @0x140e01c50
bool CMsgBoxData::FUN_140e01c50(unsigned int nIndex, __int64& nOut) const
{
    if (nIndex >= m_args.GetCount())
        return false;
    nOut = FUN_140718320(m_args[nIndex]);
    return true;
}

// @0x140e01cc0
MS2_EMIT_CRT_MEMMOVE_S();

// "limited_<serial>": the market item's key in the limited offers table.
// @0x140e01de0
CString FUN_140e01de0(MS2Ptr<Unk_AdMarketItem> item)
{
    if (item.get() != 0)
        return FUN_140540050("limited_{0}", CString(item->m_id.FUN_1409b0470()));
    return CString("");
}

// @0x140e01ef0
bool FUN_140e01ef0(Unk_140165cf0* pElem)
{
    if (pElem == 0)
        return false;
    return true;
}

// @0x140e01f10
bool FUN_140e01f10(Unk_140165cf0* pElem)
{
    if (pElem == 0)
        return true;
    bool bMinimize = false;
    FUN_1408730a0(pElem, "minimize", bMinimize);
    return bMinimize;
}

// MS2-RANGE: 0x140dfee10-0x140dfef30 .text$mn
// @0x140dfee10
void FUN_140dfee10(__int64 quizId, int first, int second)
{
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_4(quizId);
    packet.vfunc_o10_3(first);
    packet.vfunc_o10_3(second);
    FUN_140710590(packet);
}

// @0x140dfeeb0
void FUN_140dfeeb0()
{
    MyPC* player = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (player == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::HomeAction), 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(2);
    FUN_140710590(packet);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca60f0-0x142ca6150 .text$yd
