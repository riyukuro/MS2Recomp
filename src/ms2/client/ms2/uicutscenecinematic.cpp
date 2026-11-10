// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICutSceneCinematic: the cut-scene overlay (cinematic text,
// skip button, npc script lines, actor balloons, captions) driven by the cinematic packets.
// MS2-UNIT: client\ms2\uicutscenecinematic.cpp
// MS2-RANGE: 0x141906f30-0x14190eac0 .text$mn
// MS2-RANGE: 0x140111bf0-0x140111d60 .text$di
// MS2-RANGE: 0x142cbd5a0-0x142cbd625 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0VUICutSceneCinematic@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUICutSceneCinematic@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x14190b110 ; unique
// MS2-PIN: ??$?8PEAVUICutSceneCinematic@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUICutSceneCinematic@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x14190b340 ; prop
// MS2-PIN: ??$?8PEAVUICutSceneCinematic@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUICutSceneCinematic@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x14190b3b0 ; prop
// MS2-PIN: ??$?8PEAVUICutSceneCinematic@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUICutSceneCinematic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x14190b420 ; prop
// MS2-PIN: ?vfunc_48@UICutSceneCinematic@@UEAAHXZ 0x14190ce80 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x14190e720 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x14190e750 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x14190e780 ; unique
// MS2-PIN: ??$Call@VUICutSceneCinematic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUICutSceneCinematic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x14190e840 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14190e880 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14190e8e0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14190e940 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14190e660
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUICutSceneCinematic@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14190e6c0
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VBalloonGroup@UICutSceneCinematic@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VBalloonGroup@UICutSceneCinematic@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x14190cd20
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicutscenecinematic.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uicutscenecinematic.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/actionkeyobject.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/soundservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/cserverstring.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/client/ms2/soundproperty.h"
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail::FUN_1408e57f0 (the scene-service global)
#include "ms2/placeholder/ichromamanager.h"  // C3: ChromaSDK::GetChromaManager
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_141654700 / FUN_141658e60
#include "ms2/client/ms2/uichatballoon.h"  // C3: UIChatBalloon::Entity (the balloon text)
#include "ms2/client/ms2/uihudentity.h"  // C3: UIHudEntity::Entity::FUN_140f48da0
class Unk_RsScript { public: Scaleform::GFx::Value FUN_14129cce0(const char* szMethod, int a1, CStringW a2); };   // C3: unit-local view (def in unit_14129ba60); Invoke(int, string)

// ---- unit-local views of exe objects (Unk_ names and member names are invented) ----

struct Unk_CscRemoveNotice { void* m_00; void* m_08; void* m_10; int m_nObjectId; };   // NotifyRemoveGameObject (+0x18 the id)

// The balloon of an actor (PCBase slot 85: UIChatBalloon::Entity).
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // show
    virtual void vfunc_3();                                         // hide
};
class Unk_CscWorld
{
public:
    MyPC* FUN_141bd0cc0();                                          // the local player
};
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                    // the scene root of an entity
struct Unk_MiActionState* Unk_PlayerActionState(struct Unk_MiPlayer* pPlayer);   // C3: was FUN_140a7b810 (mouseinteract.cpp)

class Unk_CscEffects : public CEffectService
{
public:
};
   // the length of a sound, -1 if absent
CSoundService* FUN_140c9cb10();

class GFxSceneService { public: int FUN_1422b9fd0(int nSubSceneId); int GetSubSceneId(); };  // C3: member view (0x1422b9...)
struct Unk_GpState* GetGamepadState(class Unk_GpSettings*);   // C3: the real function (0x140a58500, gameoptiongamepad.cpp)
class CKeyTable { public: CStringW GetActionKeyName(int nAction, int nPriority); };   // ckeytable.h's key table: the key name of a binding
class Unk_SoundSink* FUN_1409331f0();   // C3: the key table (calls cast back)
class GFxManager { public: float FUN_1422afec0(int nUiId); };   // the GFx manager (UI scale)
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: the GFxManager (calls cast back)
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);   // new ASGameEntity(root, nUiId)

class Unk_CscTextKeys : public CServerStringGroup { };
class Unk_PatchTextOwner { public: class Unk_PatchTextFilter* FUN_140a87690(); };   // C3: CServerString accessor view (onlinepatchmanagercli.cpp)
class Unk_SSGPatchMgr { public: class Unk_SSGTextFilter* FUN_141747b40(); };   // C3: CServerString accessor view (scenestategame.cpp)
class CMsgBoxData : public CPtred {};                             // the message box (unit_1406125d0.h; only released here)
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW text);

unsigned long GetTickCountMs2();   // C3: was FUN_140869420
CString FUN_14016a600(const wchar_t* psz, int nCodePage);           // to narrow
CStringW FUN_14016a730(const char* psz, int nCodePage);             // to wide
CStringW FUN_1401aa6a0(int nNpcId);                                 // npc name
CString FUN_140cc2c70(const CString& strName);                      // the full path of an illust
void FUN_140cffa50(const Scaleform::GFx::Value& root, CString strName, CString strLabel);   // gotoAndPlay a child
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
extern unsigned int DAT_143af62d4;                                  // client area width
extern unsigned int DAT_143af62d8;                                  // client area height

// @0x141906f30
UICutSceneCinematic::UICutSceneCinematic()
    : m_nMode(0), m_nCinematicId(0), m_bOpening(false), m_nTalkEnd(0), m_nVoice(0), m_talks(10),
      m_groups(17, 0.75f, 0.25f, 2.25f, 10), m_nSkipState(0), m_bSkipped(false)
{
    m_2c = 0x1c;
    TSingleton<NotifySystem>::GetInstance()->RegisterNotify(L"NotifyRemoveGameObject", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::RemoveBalloonGroup));
    TSingleton<NotifySystem>::GetInstance()->RegisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::ResetSkipState));
}

// @0x1419072a0
UICutSceneCinematic::~UICutSceneCinematic()
{
    TSingleton<NotifySystem>::GetInstance()->UnregisterNotify(L"NotifyRemoveGameObject", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::RemoveBalloonGroup));
    TSingleton<NotifySystem>::GetInstance()->UnregisterNotify(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::ResetSkipState));
}

// @0x141907520
CString UICutSceneCinematic::GetTypeName()
{
    return "CutSceneCinematic";
}
MS2_REPLACE_METHOD(0x141907520, UICutSceneCinematic, GetTypeName, 61, 0x75C8B586);

// @0x141907570
UICutSceneCinematic::BalloonGroup::BalloonGroup()
    : m_bShown(false)
{
}

// @0x1419075c0
void UICutSceneCinematic::vfunc_2()
{
    FUN_1422dbf00(m_2c, 0, 0);
    GetUISwfEntityManager()->AddToLayer(this, 4);
    ChromaSDK::GetChromaManager()->SetState(0xb);
}
MS2_REPLACE_METHOD(0x1419075C0, UICutSceneCinematic, vfunc_2, 93, 0x3990A77A);

// @0x141907630
void UICutSceneCinematic::vfunc_3()
{
    if (m_nSkipState != 1)
    {
        m_nSkipState = 0;
        m_strSkipKey.Empty();
        m_strSkipLabel.Empty();
        m_strSkipMsg.Empty();
    }
    m_nCinematicId = 0;
    m_bOpening = false;
    m_strText.Empty();
    m_bSkipped = false;
    FUN_1422dc080();
    GetUISwfEntityManager()->RemoveFromLayer(this, 4);
    ChromaSDK::GetChromaManager()->SetState(0);
}
MS2_REPLACE_METHOD(0x141907630, UICutSceneCinematic, vfunc_3, 219, 0x828082D7);

// @0x141907720
void UICutSceneCinematic::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    do{m_30->FUN_140bc71c0("m_skip",m_spSkip);if(m_spSkip==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(90),__FUNCTION__));}while(0);
    m_spSkip->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UICutSceneCinematic::FUN_141909460), (void*)0);
    switch (m_nMode)
    {
    case 1:
        InvokeSetCinematic();
        break;
    case 2:
        InvokeSetOpening();
        break;
    case 3:
        InvokeSetIntro();
        break;
    }
    CStringW strKey(L"$s_cutscene_skip_key");
    if (*reinterpret_cast<unsigned char*>(GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance()))))
        strKey = reinterpret_cast<CKeyTable*>(FUN_1409331f0())->GetActionKeyName(0x49409, 2);
    FUN_141907d60(m_nSkipState, CStringW(strKey), CStringW(m_strSkipLabel));
}

// @0x141907b20
void UICutSceneCinematic::vfunc_26()
{
    UIObject::vfunc_26();
    m_nMode = 0;
    m_spSkip = 0;
}
MS2_REPLACE_METHOD(0x141907B20, UICutSceneCinematic, vfunc_26, 57, 0x49A2FB0A);

// @0x141907b60
void UICutSceneCinematic::vfunc_43()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get())
    {
        spEntity->vfunc_2(5, 1, 1);
        float fScale = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->FUN_1422afec0(m_28);
        spEntity->FUN_14190b490("setStageSize", DAT_143af62d4, DAT_143af62d8, fScale);
    }
}
MS2_REPLACE_METHOD(0x141907B60, UICutSceneCinematic, vfunc_43, 272, 0x83EFB7E0);

// @0x141907c80
int UICutSceneCinematic::vfunc_13()
{
    if (UISwfEntity::vfunc_13())
        return 1;
    if (TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(2) && TSingleton<CInputKeyHandler>::GetInstance()->FUN_14116d950(0x2a, 0, 0) && TSingleton<CInputKeyHandler>::GetInstance()->FUN_14116d950(1, 0, 0))
    {
        SendTrigger();
        SetCinematicKeyMode(false);
        FUN_1419080b0();
        return 1;
    }
    if (TSingleton<CInputKeyHandler>::GetInstance()->FUN_14116d840())
    {
        RequestSkip();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141907C80, UICutSceneCinematic, vfunc_13, 203, 0xC5C48216);

// @0x141907d60
void UICutSceneCinematic::FUN_141907d60(int nState, CStringW strKey, CStringW strLabel)
{
    m_nSkipState = nState;
    m_strSkipKey = strKey;
    m_strSkipLabel = strLabel;
    m_bSkipped = false;
    bool bSkip = nState != 0;
    if (m_30.get())
    {
        if (m_spSkip && bSkip)
            m_spSkip->vfunc_4(true);
        m_30->FUN_14190b570("setSkip", bSkip, CStringW(m_strSkipKey), CStringW(m_strSkipLabel));
    }
}
MS2_REPLACE_METHOD(0x141907D60, UICutSceneCinematic, FUN_141907d60, 531, 0x897BCD1A);

// @0x141907f80
void UICutSceneCinematic::StartCinematic(int nId, CStringW strText)
{
    if (nId == 0)
        return;
    m_nMode = 1;
    m_nCinematicId = nId;
    m_strText = strText;
    TranslateScriptText(m_strText);
    InvokeSetCinematic();
    ChromaSDK::GetChromaManager()->SetState(0xb);
}
MS2_REPLACE_METHOD(0x141907F80, UICutSceneCinematic, StartCinematic, 174, 0x4D855AE2);

// @0x141908040
void UICutSceneCinematic::SetCinematicKeyMode(bool bOn)
{
    if (bOn)
    {
        if (TSingleton<UITalkManager>::GetInstance()->GetTalking())
            TSingleton<UITalkManager>::GetInstance()->SendNpcTalkMode0();
        ((GFxSceneService*)CUserMail::FUN_1408e57f0())->FUN_1422b9fd0(0x6200041);
    }
    else
    {
        ((GFxSceneService*)CUserMail::FUN_1408e57f0())->FUN_1422b9fd0(0x620001d);
    }
}
MS2_REPLACE_METHOD(0x141908040, UICutSceneCinematic, SetCinematicKeyMode, 95, 0x0200FE35);

// @0x1419080b0
void UICutSceneCinematic::FUN_1419080b0()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("hideScript");
    m_30->Invoke("hideDirect");
    FUN_140cffa50(FUN_1422dbb40(), "m_bgInstance", "_out");
    FUN_140cffa50(FUN_1422dbb40(), "m_document", "_out");
    ChromaSDK::GetChromaManager()->SetState(0);
}
MS2_REPLACE_METHOD(0x1419080B0, UICutSceneCinematic, FUN_1419080b0, 460, 0xB4DFB1FB);

// @0x141908290
void UICutSceneCinematic::OnPacket(CInPacket& packet)
{
    int nType = packet.ReadUInt8();
    switch (nType)
    {
    case 1: OnPacketKeyMode(packet); break;
    case 2: FUN_141909750(packet); break;
    case 3: OnPacketStartCinematic(packet); break;
    case 6: FUN_141909880(packet); break;
    case 7: FUN_141909e80(packet); break;
    case 8: FUN_141909eb0(packet); break;
    case 9: OnPacketClearBalloonGroup(packet); break;
    case 4: FUN_14190a4c0(packet); break;
    case 10: FUN_14190a6e0(packet); break;
    case 11: FUN_14190ac70(packet); break;
    case 12: OnPacketSetIntro(packet); break;
    case 5: OnPacketResetSkip(packet); break;
    }
}
MS2_REPLACE_METHOD(0x141908290, UICutSceneCinematic, OnPacket, 327, 0x2227BCC9);

// @0x141908410
void UICutSceneCinematic::HideScript()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("hideScript");
}
MS2_REPLACE_METHOD(0x141908410, UICutSceneCinematic, HideScript, 89, 0x4D1B078C);

// @0x141908470
void UICutSceneCinematic::SetScript(CStringW strName, CStringW strText, CStringW strIllust, int nFlag)
{
    if (m_30.get())
        m_30->Invoke("setScript", CStringW(strName), CStringW(strText), CStringW(strIllust), nFlag);
}
MS2_REPLACE_METHOD(0x141908470, UICutSceneCinematic, SetScript, 361, 0x81464EF3);

// @0x1419085e0
void UICutSceneCinematic::RemoveBalloonGroup(NotifyObject* pNotice)
{
    Unk_CscRemoveNotice* pRemove = reinterpret_cast<Unk_CscRemoveNotice*>(pNotice);
    m_groups.RemoveKey(pRemove->m_nObjectId);
}
MS2_REPLACE_METHOD(0x1419085E0, UICutSceneCinematic, RemoveBalloonGroup, 56, 0x844E23E8);

// @0x141908620
void UICutSceneCinematic::ResetSkipState(NotifyObject* pNotice)
{
    m_nSkipState = 0;
    m_strSkipKey.Empty();
    m_strSkipLabel.Empty();
    m_strSkipMsg.Empty();
}
MS2_REPLACE_METHOD(0x141908620, UICutSceneCinematic, ResetSkipState, 94, 0x765E5887);

// @0x141908690
void UICutSceneCinematic::ClearTalks()
{
    HideScript();
    m_talks.RemoveAll();
    m_spTalk = 0;
    m_nTalkEnd = 0;
    if (m_nVoice != 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nVoice);
        m_nVoice = 0;
    }
}
MS2_REPLACE_METHOD(0x141908690, UICutSceneCinematic, ClearTalks, 132, 0x45B8DE86);

// @0x141908720
void UICutSceneCinematic::FUN_141908720(float fDelta)
{
    FUN_141908750();
    FUN_141908c00();
}
MS2_REPLACE_METHOD(0x141908720, UICutSceneCinematic, FUN_141908720, 40, 0xDE476A42);

// @0x141908750
void UICutSceneCinematic::FUN_141908750()
{
    if (m_30 == 0)
        return;
    unsigned nTick = GetTickCountMs2();
    if (m_spTalk.get())
    {
        if (nTick < m_nTalkEnd)
            return;
        HideScript();
        m_spTalk = 0;
        if (m_nVoice != 0)
        {
            TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nVoice);
            m_nVoice = 0;
        }
    }
    if (m_talks.IsEmpty())
        return;
    m_spTalk = m_talks.RemoveHead();
    if (m_spTalk == 0)
        return;
    m_nTalkEnd = nTick + m_spTalk->m_nDuration;
    if (m_spTalk->m_nNpcId == 0)
    {
        MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPC)
            SetScript(pPC->vfunc_77(), CStringW(m_spTalk->m_strText), CStringW(), 0);
    }
    else
    {
        SetScript(FUN_1401aa6a0(m_spTalk->m_nNpcId), CStringW(m_spTalk->m_strText), FUN_14016a730(FUN_140cc2c70(m_spTalk->m_strIllust), 0), m_spTalk->m_nFlag);
    }
    if (!m_spTalk->m_strSound.IsEmpty())
        m_nVoice = reinterpret_cast<Unk_CscEffects*>(TSingleton<CEffectService>::GetInstance())->PlayTriggerVoice(m_spTalk->m_strSound);
}
MS2_REPLACE_METHOD(0x141908750, UICutSceneCinematic, FUN_141908750, 1186, 0xFFB16FB9);

// @0x141908c00
void UICutSceneCinematic::FUN_141908c00()
{
    unsigned nTick = GetTickCountMs2();
    for (POSITION pos = m_groups.GetStartPosition(); pos != 0; m_groups.GetNext(pos))
    {
        int nId = m_groups.GetKeyAt(pos);
        PCBase* pActor = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1200(nId));
        if (pActor == 0)
            continue;
        NiAVObject* pRoot = FUN_141b6efc0(pActor->GetEntity());
        if (pRoot == 0 || ((class NiAVObject*)(class NiAVObject*)(pRoot))->GetAppCulled())
            continue;
        MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = pActor->vfunc_85();
        if (spBalloon == 0)
            continue;
        MS2Ptr<BalloonGroup> spGroup = m_groups.GetValueAt(pos);
        if (spGroup->m_bShown)
        {
            if (nTick >= spGroup->m_nHide)
            {
                spBalloon->vfunc_3();
                spGroup->m_bShown = false;
            }
            else
                continue;
        }
        for (unsigned i = 0; i < spGroup->m_talks.GetCount(); i++)
        {
            MS2Ptr<BalloonTalk> spTalk = spGroup->m_talks.GetAt(i);
            if (spTalk->m_nStart < nTick)
            {
                reinterpret_cast<UIChatBalloon::Entity*>(spBalloon.operator->())->FUN_1418fb730(spTalk->m_strText);
                reinterpret_cast<UIChatBalloon::Entity*>(spBalloon.operator->())->FUN_1418fb6d0();
                reinterpret_cast<UIHudEntity::Entity*>(spBalloon.operator->())->FUN_140f48da0();
                spBalloon->vfunc_2();
                spGroup->m_bShown = true;
                spGroup->m_nHide = spTalk->m_nEnd;
                spGroup->m_talks.RemoveAt(i, 1);
                if (!spTalk->m_strSound.IsEmpty())
                    reinterpret_cast<Unk_CscEffects*>(TSingleton<CEffectService>::GetInstance())->PlayTriggerVoice(spTalk->m_strSound);
                break;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141908C00, UICutSceneCinematic, FUN_141908c00, 954, 0x50B57242);

// @0x141908fc0
void UICutSceneCinematic::RequestSkip()
{
    if (m_nSkipState == 0)
        return;
    if (m_bSkipped)
        return;
    if (m_strSkipMsg.GetLength() != 0)
        FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>(this, &UICutSceneCinematic::OnSkipMsgBox), StringFormat(L"s_cutscene_skip_msg_{0}", m_strSkipMsg));
    else
        SkipCinematic();
}

// @0x141909100
void UICutSceneCinematic::SkipCinematic()
{
    SendTrigger();
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pPC)
        reinterpret_cast<Unk_ActionKeyManager*>(Unk_PlayerActionState(reinterpret_cast<Unk_MiPlayer*>(pPC)))->FUN_1409536d0();
    TSingleton<NotifySystem>::GetInstance()->Post(MS2Ptr<NotifyObject>(new NotifyCutSceneCinematicSkip));
    m_bSkipped = true;
    if (m_spSkip)
        m_spSkip->vfunc_4(false);
}

// @0x141909230
void UICutSceneCinematic::SendTrigger()
{
    if (m_nSkipState == 2 || m_nSkipState == 1)
    {
        COutPacket packet(static_cast<int>(SendOp::Trigger), 0);
        packet.Encode1(8);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x141909230, UICutSceneCinematic, SendTrigger, 103, 0x1F36D64F);

// @0x1419092a0
void UICutSceneCinematic::TranslateScriptText(CStringW& strText)
{
    strText = reinterpret_cast<Unk_CscTextKeys*>(reinterpret_cast<Unk_PatchTextOwner*>(TSingleton<CServerString>::GetInstance())->FUN_140a87690())->GetString(strText);
    strText.Replace(L"\\n", L"\n");
    TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectAndValueWords(strText);
}
MS2_REPLACE_METHOD(0x1419092A0, UICutSceneCinematic, TranslateScriptText, 145, 0x2D9D36A2);

// @0x141909340
void UICutSceneCinematic::FUN_141909340(int nActorId)
{
    PCBase* pActor = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1200(nActorId));
    if (pActor == 0)
        return;
    NiAVObject* pRoot = FUN_141b6efc0(pActor->GetEntity());
    if (pRoot == 0 || ((class NiAVObject*)(class NiAVObject*)(pRoot))->GetAppCulled())
        return;
    MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = pActor->vfunc_85();
    if (spBalloon == 0)
        return;
    spBalloon->vfunc_3();
}
MS2_REPLACE_METHOD(0x141909340, UICutSceneCinematic, FUN_141909340, 210, 0x52979E7F);

// @0x141909420
bool UICutSceneCinematic::OnSkipMsgBox(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    SkipCinematic();
    return true;
}
MS2_REPLACE_METHOD(0x141909420, UICutSceneCinematic, OnSkipMsgBox, 46, 0xF76CB353);

// @0x141909460
void UICutSceneCinematic::FUN_141909460(const Scaleform::GFx::FunctionHandler::Params& params)
{
    RequestSkip();
}
MS2_REPLACE_METHOD(0x141909460, UICutSceneCinematic, FUN_141909460, 29, 0xE9715B8A);

// @0x141909490
void UICutSceneCinematic::InvokeSetCinematic()
{
    if (m_30 == 0)
        return;
    reinterpret_cast<Unk_RsScript*>(m_30.operator->())->FUN_14129cce0("setCinematic", m_nCinematicId, CStringW(m_strText));
}
MS2_REPLACE_METHOD(0x141909490, UICutSceneCinematic, InvokeSetCinematic, 184, 0x56FF538B);

// @0x141909550
void UICutSceneCinematic::InvokeSetOpening()
{
    if (m_30 == 0)
        return;
    m_30->FUN_140f5ff80("setOpening", CStringW(m_strText), m_bOpening);
}
MS2_REPLACE_METHOD(0x141909550, UICutSceneCinematic, InvokeSetOpening, 186, 0x5FB2857B);

// @0x141909610
void UICutSceneCinematic::InvokeSetIntro()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("setIntro", CStringW(m_strText));
}
MS2_REPLACE_METHOD(0x141909610, UICutSceneCinematic, InvokeSetIntro, 161, 0x0CC3B5AF);

// @0x1419096c0
bool UICutSceneCinematic::IsCinematicKeyGroupActive()
{
    return ((GFxSceneService*)CUserMail::FUN_1408e57f0())->GetSubSceneId() == 0x6200041;
}
MS2_REPLACE_METHOD(0x1419096C0, UICutSceneCinematic, IsCinematicKeyGroupActive, 57, 0x1B8A4E6C);

// @0x141909700
void UICutSceneCinematic::OnPacketKeyMode(CInPacket& packet)
{
    bool bOn = packet.ReadBool();
    SetCinematicKeyMode(bOn);
}
MS2_REPLACE_METHOD(0x141909700, UICutSceneCinematic, OnPacketKeyMode, 71, 0x9EF82459);

// @0x141909750
void UICutSceneCinematic::FUN_141909750(CInPacket& packet)
{
    FUN_1419080b0();
}
MS2_REPLACE_METHOD(0x141909750, UICutSceneCinematic, FUN_141909750, 29, 0x72FB9950);

// @0x141909780
void UICutSceneCinematic::OnPacketStartCinematic(CInPacket& packet)
{
    int nId = packet.ReadInt32();
    CStringW strText = packet.ReadUnicodeString();
    CStringW strUnused = packet.ReadUnicodeString();
    StartCinematic(nId, CStringW(strText));
}
MS2_REPLACE_METHOD(0x141909780, UICutSceneCinematic, OnPacketStartCinematic, 241, 0x184D9336);

// @0x141909880
void UICutSceneCinematic::FUN_141909880(CInPacket& packet)
{
    int nNpcId = packet.ReadInt32();
    CString strIllust = packet.ReadString();
    CStringW strText = packet.ReadUnicodeString();
    unsigned nDuration = packet.ReadInt32();
    unsigned nFlag = packet.ReadUInt8();
    CString strSound = FUN_14016a600(strText, 0);
    if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
        strSound.Remove('$');
    TranslateScriptText(strText);
    if (strText.IsEmpty())
        return;
    unsigned nSound = 0;
    MS2Ptr<TriggerVoiceProperty> spVoice = TSingleton<SoundPropertyMgr>::GetInstance()->FindTriggerVoice(strSound);
    if (spVoice.get())
    {
        MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pPC)
        {
            CString strEvent;
            spVoice->GetVoice(reinterpret_cast<PC*>(pPC)->GetGender(), reinterpret_cast<PC*>(pPC)->GetJobGroupId(), strEvent);
            if (!strEvent.IsEmpty())
            {
                size_t nBank = 0;
                int nLength = FUN_140c9cb10()->FUN_1417b04d0(strEvent, &nBank);
                if (nLength != -1)
                    nSound = nLength;
            }
        }
    }
    MS2Ptr<CinematicTalk> spTalk(new CinematicTalk);
    spTalk->m_nNpcId = nNpcId;
    spTalk->m_strIllust = strIllust;
    spTalk->m_strText = strText;
    spTalk->m_nDuration = nSound > nDuration ? nSound : nDuration;
    spTalk->m_nFlag = nFlag;
    spTalk->m_strSound = nSound != 0 ? CString(strSound) : CString("");
    m_talks.AddTail(spTalk);
}

// @0x141909e80
void UICutSceneCinematic::FUN_141909e80(CInPacket& packet)
{
    ClearTalks();
}
MS2_REPLACE_METHOD(0x141909E80, UICutSceneCinematic, FUN_141909e80, 29, 0xE78F1D46);

// @0x141909eb0
void UICutSceneCinematic::FUN_141909eb0(CInPacket& packet)
{
    unsigned bRaw = packet.ReadUInt8();
    int nId = packet.ReadInt32();
    CStringW strText = packet.ReadUnicodeString();
    unsigned nDuration = packet.ReadInt32();
    unsigned nDelay = packet.ReadInt32();
    CString strSound("");
    if (bRaw == 0)
    {
        strSound = FUN_14016a600(strText, 0);
        if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
            strSound.Remove('$');
        TranslateScriptText(strText);
    }
    else
    {
        strText = reinterpret_cast<Unk_CscTextKeys*>(reinterpret_cast<Unk_SSGPatchMgr*>(TSingleton<CServerString>::GetInstance())->FUN_141747b40())->GetString(strText);
    }
    if (strText.IsEmpty())
        return;
    MS2Ptr<BalloonGroup> spGroup;
    if (!m_groups.Lookup(nId, spGroup))
    {
        spGroup.AssignRaw(new BalloonGroup);
        spGroup->m_bShown = false;
        m_groups.SetAt(nId, spGroup);
    }
    MS2Ptr<BalloonTalk> spTalk(new BalloonTalk);
    spTalk->m_nActorId = nId;
    spTalk->m_strText = strText;
    spTalk->m_nStart = GetTickCountMs2() + nDelay;
    spTalk->m_nEnd = spTalk->m_nStart + nDuration;
    spTalk->m_strSound = strSound;
    spGroup->m_talks.Add(spTalk);
}

// @0x14190a400
void UICutSceneCinematic::OnPacketClearBalloonGroup(CInPacket& packet)
{
    int nId = packet.ReadInt32();
    MS2Ptr<BalloonGroup> spGroup;
    if (m_groups.Lookup(nId, spGroup))
    {
        if (spGroup->m_bShown)
            FUN_141909340(nId);
        spGroup->m_talks.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x14190A400, UICutSceneCinematic, OnPacketClearBalloonGroup, 177, 0xE46A55A7);

// @0x14190a4c0
void UICutSceneCinematic::FUN_14190a4c0(CInPacket& packet)
{
    int nType = packet.ReadUInt8();
    CStringW strLabel;
    switch (nType)
    {
    case 2: strLabel = "$s_cutscene_skip_state"; break;
    case 1: strLabel = "$s_cutscene_skip_scene"; break;
    }
    m_strSkipMsg = packet.ReadString();
    CStringW strKey(L"$s_cutscene_skip_key");
    if (*reinterpret_cast<unsigned char*>(GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance()))))
        strKey = reinterpret_cast<CKeyTable*>(FUN_1409331f0())->GetActionKeyName(0x49409, 2);
    FUN_141907d60(nType, CStringW(strKey), CStringW(strLabel));
}
MS2_REPLACE_METHOD(0x14190A4C0, UICutSceneCinematic, FUN_14190a4c0, 523, 0xECC7A13D);

// @0x14190a6e0
void UICutSceneCinematic::FUN_14190a6e0(CInPacket& packet)
{
    if (!m_30)
        return;
    CStringW strType = packet.ReadUnicodeString();
    CStringW strText1 = packet.ReadUnicodeString();
    CStringW strText2 = packet.ReadUnicodeString();
    CStringW strAlign = packet.ReadUnicodeString();
    int nDuration = packet.ReadInt32();
    float fX = packet.ReadFloat();
    float fY = packet.ReadFloat();
    float fScale = packet.ReadFloat();
    TranslateScriptText(strText1);
    CString strSound = FUN_14016a600(strText2, 0);
    if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
        strSound.Remove('$');
    TranslateScriptText(strText2);
    ASObj obj(2);
    obj.FUN_1407cb9c0("captionID", 0);
    obj.FUN_1407cbb20("captionType", CStringW(strType));
    obj.FUN_1407cbb20("captionStr1", CStringW(strText1));
    obj.FUN_1407cbb20("captionStr2", CStringW(strText2));
    obj.FUN_1407cbb20("captionAlign", CStringW(strAlign));
    obj.SetMemberFloat("offsetRatioX", fX);
    obj.SetMemberFloat("offsetRatioY", fY);
    obj.FUN_1407cb9c0("captionDuration", nDuration);
    obj.SetMemberFloat("captionScale", fScale);
    m_30->Invoke("setCaption", obj);
    if (!strSound.IsEmpty())
        reinterpret_cast<Unk_CscEffects*>(TSingleton<CEffectService>::GetInstance())->PlayTriggerVoice(strSound);
}
MS2_REPLACE_METHOD(0x14190A6E0, UICutSceneCinematic, FUN_14190a6e0, 1408, 0x2065A4F5);

// @0x14190ac70
void UICutSceneCinematic::FUN_14190ac70(CInPacket& packet)
{
    m_strText = packet.ReadUnicodeString();
    m_bOpening = packet.ReadBool();
    m_nMode = 2;
    CString strSound = FUN_14016a600(m_strText, 0);
    if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
        strSound.Remove('$');
    TranslateScriptText(m_strText);
    InvokeSetOpening();
    if (!IsCinematicKeyGroupActive())
        SetCinematicKeyMode(true);
    if (!strSound.IsEmpty())
        reinterpret_cast<Unk_CscEffects*>(TSingleton<CEffectService>::GetInstance())->PlayTriggerVoice(strSound);
}
MS2_REPLACE_METHOD(0x14190AC70, UICutSceneCinematic, FUN_14190ac70, 617, 0xE5FDE549);

// @0x14190aee0
void UICutSceneCinematic::OnPacketSetIntro(CInPacket& packet)
{
    m_strText = packet.ReadUnicodeString();
    m_nMode = 3;
    TranslateScriptText(m_strText);
    InvokeSetIntro();
    if (!IsCinematicKeyGroupActive())
        SetCinematicKeyMode(true);
}
MS2_REPLACE_METHOD(0x14190AEE0, UICutSceneCinematic, OnPacketSetIntro, 190, 0xC358CCEE);

// @0x14190afb0
void UICutSceneCinematic::OnPacketResetSkip(CInPacket& packet)
{
    m_talks.RemoveAll();
    m_strSkipMsg.Empty();
    FUN_141907d60(0, CStringW(L""), CStringW(L""));
}
MS2_REPLACE_METHOD(0x14190AFB0, UICutSceneCinematic, OnPacketResetSkip, 165, 0x7F0B1D8B);

// @0x14190b060
void UICutSceneCinematic::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x14190B060, UICutSceneCinematic, vfunc_41, 99, 0x17B77628);

// @0x14190b490
inline Scaleform::GFx::Value AScript::FUN_14190b490(const char* szMethod, unsigned int a1, unsigned int a2, float a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bcd10(&args[0], a1);
    FUN_1422bcd10(&args[1], a2);
    FUN_1422bcd70(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14190b570
inline Scaleform::GFx::Value AScript::FUN_14190b570(const char* szMethod, bool a1, CStringW a2, CStringW a3)
{
    ASArgList args;
    args.resize(3);
    FUN_1422bcce0(&args[0], a1);
    FUN_1422bcea0(&args[1], a2);
    FUN_1422bcea0(&args[2], a3);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
