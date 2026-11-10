// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWatchAGameDialog: see uiwatchagamedialog.h.
// MS2-UNIT: ?\uiwatchagamedialog.cpp
// MS2-RANGE: 0x140fc07a0-0x140fc1e20 .text$mn
// MS2-RANGE: 0x1400e28a0-0x1400e29c0 .text$di
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiwatchagamedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiwatchagamedialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/triggerservice.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce240
#include "ms2/commonfiles/hideandseek.h"   // C3: HideAndSeek::Info

// The header statics of the including TU: the sort type names and the skill / stun marks.
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> WagClickDelegate;

// The action / fold button.
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
//
//
//
class ASDialog : public ASDisplayObjectContainer { public: virtual void vfunc_2(int, int, int); };   // vfunc_2: place the movie

// The hide and seek record of a player.
class Unk_HsInfo : public CPtred { };

// The trigger service: the camera steps.
class Unk_McEntityRules* GetTriggerService();   // C3: the definer's signature (0x140ad4b90, unit_140ad1860); the trigger service
static const unsigned s_nCameraModel = 0x65338ec3;           // the FlatModel the camera triggers show (0x142e91444)

template <class T> CString Unk_SocketFormat(const char* szFormat, const T& n);
CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
void* IntToUserData(int n);                                     // int -> delegate user data
int UserDataToInt(void* p);                                     // delegate user data -> int
void SetBoolean(Scaleform::GFx::Value* pValue, bool b);

// @0x140fc07a0
UIWatchAGameDialog::UIWatchAGameDialog()
    : m_bFolded(false), m_nValue(0), m_nCharId(0), m_bFlag(false), m_nCamera(-1), m_foldButton(0)
{
    SetFlag(1, 1);
    for (unsigned int i = 0; i < 4; i++)
    {
        m_buttons[i] = 0;
        m_clips[i] = 0;
    }
}

// @0x140fc0930
UIWatchAGameDialog::~UIWatchAGameDialog()
{
}

// @0x140fc09f0
CString UIWatchAGameDialog::GetTypeName()
{
    return "WatchAGameDialog";
}

// @0x140fc0a40
void UIWatchAGameDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_bFolded = false;
    m_nValue = 0;
    m_nCharId = 0;
    m_bFlag = false;
    m_nCamera = -1;
    m_foldButton = 0;
    for (unsigned int i = 0; i < 4; i++)
    {
        m_buttons[i] = 0;
        m_clips[i] = 0;
    }
}

// @0x140fc0b20
void UIWatchAGameDialog::SetValue(int nValue)
{
    m_nValue = nValue;
}

// @0x140fc0b40
void UIWatchAGameDialog::SetCharId(int nCharId)
{
    m_nCharId = nCharId;
}

// @0x140fc0b60
void UIWatchAGameDialog::FUN_140fc0b60(bool bFlag)
{
    m_bFlag = bFlag;
    if (m_30 == 0)
        return;
    m_30->Invoke("foldDialog", m_bFolded, m_bFlag);
}

// @0x140fc0bf0
void UIWatchAGameDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_bFolded = false;
    BindDragBar("m_dragBar");
    for (int i = 0; i < 4; i++)
    {
        int nIndex = i + 1;
        CString strName = Unk_SocketFormat<int>("m_actionButton{0}", nIndex);
        m_clips[i] = GetChild<ASMovieClip>(strName);
        if (m_clips[i] == 0)
            continue;
        m_buttons[i] = m_clips[i]->FUN_140acce30<ASButton>("m_button");
        if (m_buttons[i] == 0)
            continue;
        m_buttons[i]->AddClickHandler(WagClickDelegate(this, &UIWatchAGameDialog::OnActionButtonClick), IntToUserData(i));
    }
    m_foldButton = GetChild<ASButton>("m_foldButton");
    m_foldButton->AddClickHandler(WagClickDelegate(this, &UIWatchAGameDialog::FUN_140fc1440), 0);
    {
        CStringW strKey(L"s_watchagame_change_camera");
        CString strIcon("./Data/Resource/Image/skill/icon/ChangeCamera.png");
        SetActionButton(0, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_watchagame_reset_camera");
        CString strIcon("./Data/Resource/Image/skill/icon/MoveStage.png");
        SetActionButton(1, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_music_concert_emotion_shake");
        CString strIcon("./Data/Resource/Image/skill/icon/Lightstick.png");
        SetActionButton(2, strIcon, GetStringCommonByKey(strKey));
    }
    {
        CStringW strKey(L"s_music_concert_emotion_clap");
        CString strIcon("./Data/Resource/Image/skill/icon/Clap.png");
        SetActionButton(3, strIcon, GetStringCommonByKey(strKey));
    }
    ((CTriggerService*)GetTriggerService())->FindObjectsByModel(s_nCameraModel, m_cameras);
    FUN_140fc0b60(m_bFlag);
}

// @0x140fc1300
void UIWatchAGameDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(5, 0, 0x19);
}

// @0x140fc1380
void UIWatchAGameDialog::OnActionButtonClick(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    int nIndex = UserDataToInt(params.pUserData);
    if (nIndex >= 4 || nIndex < 0)
        return;
    switch (nIndex)
    {
    case 0:
        NextCamera();
        break;
    case 1:
        ResetCamera();
        break;
    case 2:
        PlayEmotion(0x5607ed2);
        break;
    case 3:
        PlayEmotion(0x5607ed1);
        break;
    }
}

// @0x140fc1440
void UIWatchAGameDialog::FUN_140fc1440(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    if (m_bFolded == true)
    {
        m_bFolded = false;
        m_30->Invoke("foldDialog", m_bFolded, m_bFlag);
    }
    else
    {
        m_bFolded = true;
        m_30->Invoke("foldDialog", m_bFolded, m_bFlag);
    }
}

// @0x140fc1560
void UIWatchAGameDialog::SetActionButton(int nIndex, const CString& strIcon, const CStringW& strTooltip)
{
    if (m_30 == 0)
        return;
    if (nIndex >= 4 || nIndex < 0)
        return;
    if (m_clips[nIndex] == 0)
        return;
    m_30->FUN_140e6b140("setImage", nIndex + 1, strIcon);
    MS2Ptr<ASTextField> spName = m_clips[nIndex]->FUN_1409b4620("m_actionName");
    if (spName.get() != 0)
        spName->SetTextW(strTooltip);
}

// @0x140fc1710
void UIWatchAGameDialog::NextCamera()
{
    if (m_cameras.empty())
        return;
    int nNext = m_nCamera + 1;
    m_nCamera = nNext;
    if (nNext >= (int)m_cameras.size())
        m_nCamera = 0;
    int nObject = m_cameras[m_nCamera];
    ((CTriggerService*)GetTriggerService())->QueueCameraStep(nObject, 1);
}

// @0x140fc17d0
void UIWatchAGameDialog::ResetCamera()
{
    if (m_nCamera < 0 || m_nCamera >= (int)m_cameras.size())
        return;
    int nObject = m_cameras[m_nCamera];
    ((CTriggerService*)GetTriggerService())->QueueCameraStep(nObject, 0);
}

// @0x140fc1850
void UIWatchAGameDialog::PlayEmotion(int nEmotion)
{
    PC* pPC = static_cast<PC*>(WorldService::GetInstance()->GetLocalPlayer());
    if (pPC == 0)
        return;
    if (pPC->FUN_141675ed0() == 1)
        return;
    switch (pPC->GetCurStateId())
    {
    case 1:
        break;
    case 0xb:
        break;
    case 0xf:
        break;
    default:
        return;
    }
    MS2Ptr<Unk_HsInfo> spInfo = pPC->GetHideAndSeekInfo();
    if (spInfo == 0)
        return;
    if (reinterpret_cast<HideAndSeek::Info*>(spInfo.operator->())->FUN_14050a4d0())
        pPC->FUN_14166ed70(nEmotion);
}

// @0x140fc1a70
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, bool a1, bool a2)
{
    ASArgList args;
    args.resize(2);
    SetBoolean(&args[0], a1);
    SetBoolean(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- hooks ----
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caab60-0x142caabd0 .text$yd
