// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMusicConcertDialog: see uimusicconcertdialog.h.
// MS2-UNIT: ?\uimusicconcertdialog.cpp
// MS2-RANGE: 0x1400d93c0-0x1400d94e0 .text$di
// MS2-RANGE: 0x140e694a0-0x140e6b7b0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??_GUIMusicConcertDialog@@UEAAPEAXI@Z 0x140e6b4f0
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimusicconcertdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uimusicconcertdialog.h"
#include "uimessageboxdata.h"
#include "camera.h"
#include "localtargetcameramode.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The header statics of the including TU: the sort type names and the skill / stun marks.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> McClickDelegate;
typedef Delegate<bool(int, const CMsgBoxData&)> McBoxDelegate;

// The action / fold button.
class Unk_MusicButton : public ASDisplayObject
{
public:
    void FUN_1422ce240(const McClickDelegate& onClick, void* pUserData);
};
class ASDialog : public ASDisplayObjectContainer { public: virtual void vfunc_2(int, int, int); };   // vfunc_2: place the movie

WorldService* FUN_1403ed2d0();
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
CString FUN_1402bad60(const char* szFormat, const int* pn);     // format one int
void* FUN_140bb9630(int n);                                     // int -> delegate user data
int FUN_140bb9640(void* p);                                     // delegate user data -> int
unsigned FUN_141472bc0();                                       // the tick count
CStringW FUN_1409e8970(CStringW strFormat, const unsigned& a, const unsigned& b);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int nType);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
bool FUN_1407105c0(COutPacket* packet, int key, int delay);
CameraMgr* FUN_1409478c0();
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// @0x140e694a0
UIMusicConcertDialog::UIMusicConcertDialog()
    : m_clips(), m_buttons(), m_foldButton(), m_topText()
{
    FUN_141925e70(1, 1);
    m_bFolded = false;
}

// @0x140e695a0
UIMusicConcertDialog::~UIMusicConcertDialog()
{
}

// @0x140e69660
void UIMusicConcertDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}

// @0x140e69680
void UIMusicConcertDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    for (int i = 0; i < 6; i++)
    {
        m_clips[i] = 0;
        m_buttons[i] = 0;
    }
    m_foldButton = 0;
    m_topText = 0;
}

// @0x140e69730
void UIMusicConcertDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    FUN_140e6a290();
}

// @0x140e69760
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_bFolded = false;
    FUN_141925fa0("m_dragBar");
    for (int i = 0; i < 6; i++)
    {
        int nIndex = i + 1;
        CString strName = FUN_1402bad60("m_actionButton{0}", &nIndex);
        m_clips[i] = FUN_140ba7930(strName);
        if (!(m_clips[i] == 0))
        {
            m_buttons[i] = m_clips[i]->FUN_140acce30<Unk_MusicButton>("m_button");
            if (!(m_buttons[i] == 0))
                m_buttons[i]->FUN_1422ce240(McClickDelegate(this, &UIMusicConcertDialog::FUN_140e6a0d0), FUN_140bb9630(i));
        }
    }
    m_foldButton = FUN_140bb4b10("m_foldButton");
    m_foldButton->FUN_1422ce240(McClickDelegate(this, &UIMusicConcertDialog::FUN_140e6a1b0), 0);
    m_topText = FUN_140bb4cf0("m_topText");
    {
        CStringW strKey(L"s_music_concert_can_play");
        CString strIcon("./Data/Resource/Image/skill/icon/Ensemble.png");
        FUN_140e6a5d0(0, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_music_concert_move_stage");
        CString strIcon("./Data/Resource/Image/skill/icon/MoveStage.png");
        FUN_140e6a5d0(1, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_music_concert_change_camera");
        CString strIcon("./Data/Resource/Image/skill/icon/ChangeCamera.png");
        FUN_140e6a5d0(2, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_music_concert_firework");
        CString strIcon("./Data/Resource/Image/skill/icon/Firework.png");
        FUN_140e6a5d0(3, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_music_concert_emotion_shake");
        CString strIcon("./Data/Resource/Image/skill/icon/Lightstick.png");
        FUN_140e6a5d0(4, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_music_concert_emotion_clap");
        CString strIcon("./Data/Resource/Image/skill/icon/Clap.png");
        FUN_140e6a5d0(5, strIcon, GetStringCommonByKey(strKey));
    }
    FUN_140e6a290();
}

// @0x140e6a000
CString UIMusicConcertDialog::GetTypeName()
{
    return "MusicConcertDialog";
}

// @0x140e6a050
void UIMusicConcertDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(5, 0, 0x19);
}

// @0x140e6a0d0
void UIMusicConcertDialog::FUN_140e6a0d0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    int nIndex = FUN_140bb9640(params.pUserData);
    if (nIndex >= 6 || nIndex < 0)
        return;
    if (nIndex == 0)
        FUN_140e6a780();
    else if (nIndex == 1)
        SendPlayInstrumentMode13();
    else if (nIndex == 2)
        FUN_140e6ab90();
    else if (nIndex == 3)
        SendPlayInstrumentMode14();
    else if (nIndex == 4)
        SendPlayInstrumentMode15(0x5607ed2);
    else if (nIndex == 5)
        SendPlayInstrumentMode15(0x5607ed1);
}

// @0x140e6a1b0
void UIMusicConcertDialog::FUN_140e6a1b0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    if (m_bFolded == true)
    {
        m_bFolded = false;
        m_30->Invoke("foldDialog", m_bFolded);
    }
    else
    {
        m_bFolded = true;
        m_30->Invoke("foldDialog", m_bFolded);
    }
}

// @0x140e6a290
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::FUN_140e6a290()
{
    if (m_topText == 0)
        return;
    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    CStringW strAction = GetStringCommonByKey(CStringW(L"s_music_concert_can_play"));
    unsigned nStart = FUN_1403ed2d0()->FUN_141bcaf60();
    unsigned nNow = FUN_141472bc0();
    if (nStart < nNow)
    {
        m_topText->FUN_1422c4cd0(GetStringCommonByKey(CStringW(L"s_music_concert_can_register_text")));
    }
    else
    {
        unsigned nSec = (nStart - nNow) / 1000;
        unsigned nMin = nSec / 0x3c;
        nSec = nSec % 0x3c;
        m_topText->FUN_1422c4cd0(FUN_1409e8970(CStringW(L"s_music_concert_playing_text"), nMin, nSec));
        __int64 nOwner = (__int64)FUN_1403ed2d0()->FUN_141bcaf80();
        if (pPC->FUN_141656a80() == nOwner)
            strAction = GetStringCommonByKey(CStringW(L"s_music_concert_abort_play"));
    }
    MS2Ptr<ASTextField> spName = m_clips[0]->FUN_1409b4620("m_actionName");
    if (spName.get() != 0)
        spName->FUN_1422c4cd0(strAction);
}

// @0x140e6a5d0
void UIMusicConcertDialog::FUN_140e6a5d0(int nIndex, const CString& strIcon, const CStringW& strTooltip)
{
    if (m_30 == 0)
        return;
    if (nIndex >= 6 || nIndex < 0)
        return;
    if (m_clips[nIndex] == 0)
        return;
    m_30->FUN_140e6b140("setImage", nIndex + 1, strIcon);
    MS2Ptr<ASTextField> spName = m_clips[nIndex]->FUN_1409b4620("m_actionName");
    if (spName.get() != 0)
        spName->FUN_1422c4cd0(strTooltip);
}

// @0x140e6a780
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::FUN_140e6a780()
{
    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    unsigned nStart = FUN_1403ed2d0()->FUN_141bcaf60();
    unsigned nNow = FUN_141472bc0();
    if (nStart < nNow)
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d73f20(GetStringCommonByKey(CStringW(L"s_music_concert_msg_confirm_register")), 1);
        box->FUN_141a027c0(McBoxDelegate(this, &UIMusicConcertDialog::SendPlayInstrumentMode11));
        FUN_140d73c60(box);
    }
    else
    {
        __int64 nOwner = (__int64)FUN_1403ed2d0()->FUN_141bcaf80();
        if (nOwner == pPC->FUN_141656a80())
            FUN_140e6a9d0();
        else
            FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_music_concert_msg_cant_register")), 1, 1);
    }
}

// @0x140e6a9d0
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::FUN_140e6a9d0()
{
    MS2Ptr<CMsgBoxData> box = FUN_140d73f20(GetStringCommonByKey(CStringW(L"s_music_concert_msg_confirm_unregister")), 1);
    box->FUN_141a027c0(McBoxDelegate(this, &UIMusicConcertDialog::SendPlayInstrumentMode12));
    FUN_140d73c60(box);
}

// @0x140e6ab10
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::SendPlayInstrumentMode13()
{
    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
        packet.vfunc_o10_1(0xd);
        FUN_1407105c0(&packet, 0xd, 1000);
    }
}

// @0x140e6ab90
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::FUN_140e6ab90()
{
    CCameraMode* pMode = FUN_1409478c0()->FUN_140af2520();
    if (pMode == 0 || pMode->vfunc_1() != 0x10)
    {
        FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_music_concert_msg_cant_change_camera")), 1, 1);
    }
    else
    {
        CLocalTargetCameraMode* pLocal = static_cast<CLocalTargetCameraMode*>(pMode);
        if (pLocal->FUN_140af7e10() != 0 && pLocal->FUN_140af8600())
            FUN_1409478c0()->FUN_140aeb950(pLocal);
    }
}

// @0x140e6ac80
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::SendPlayInstrumentMode14()
{
    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC != 0)
    {
        COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
        packet.vfunc_o10_1(0xe);
        FUN_1407105c0(&packet, 0xe, 2000);
    }
}

// @0x140e6ad00
// MS2-FUNCTIONAL: exe temporary / frame-slot order differs (source form for the call-result temps not found)
void UIMusicConcertDialog::SendPlayInstrumentMode15(int nEmotion)
{
    PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPC == 0)
        return;
    if (pPC->FUN_141675ed0() == 1)
        return;
    int nState = pPC->FUN_14166c930();
    if (!(nState == 1 || nState == 0xb || nState == 0xf))
        return;
    pPC->FUN_14166ed70(nEmotion);
    COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
    packet.vfunc_o10_1(0xf);
    packet.vfunc_o10_3(nEmotion);
    FUN_1407105c0(&packet, 0xf, 2000);
}

// @0x140e6adf0
bool UIMusicConcertDialog::SendPlayInstrumentMode11(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
        packet.vfunc_o10_1(0xb);
        FUN_140710590(packet);
    }
    return true;
}

// @0x140e6ae60
bool UIMusicConcertDialog::SendPlayInstrumentMode12(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::PlayInstrument), 0);
        packet.vfunc_o10_1(0xc);
        FUN_140710590(packet);
    }
    return true;
}

// @0x140e6b140
Scaleform::GFx::Value AScript::FUN_140e6b140(const char* szMethod, int a1, CString a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}

// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca70b0-0x142ca7120 .text$yd
