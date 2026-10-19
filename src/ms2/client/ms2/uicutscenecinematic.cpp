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

// ---- unit-local views of exe objects (Unk_ names and member names are invented) ----

class Unk_CscNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);    // listen
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);    // stop listening
    void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify);                        // post
};
Unk_CscNotices* FUN_140939a10();
struct Unk_CscRemoveNotice { void* m_00; void* m_08; void* m_10; int m_nObjectId; };   // NotifyRemoveGameObject (+0x18 the id)

// The balloon of an actor (PCBase slot 85: UIChatBalloon::Entity).
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // show
    virtual void vfunc_3();                                         // hide
    void FUN_1418fb730(const CStringW& strText);                    // set the text
    void FUN_1418fb6d0();                                           // m_a0 = 1
    void FUN_140f48da0();                                           // UIHudEntity::Entity: m_50 = 1
};
class Unk_CscWorld
{
public:
    MyPC* FUN_141bd0cc0();                                          // the local player
    PCBase* FUN_141bd1200(int nId);                                 // actor by id
};
Unk_CscWorld* FUN_1403ed2d0();
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                    // the scene root of an entity
bool FUN_14098dad0(NiAVObject* pObject);                            // culled
class Unk_CscActionKeys { public: void FUN_1409536d0(); };
Unk_CscActionKeys* FUN_140a7b810(MyPC* pPC);
int FUN_141654700(PCBase* pPC);                                   // job
int FUN_141658e60(PCBase* pPC);                                   // gender

class Unk_CscEffects
{
public:
    unsigned FUN_1411a5d80(const CString& strName);                 // play a voice
    void FUN_1411a6060(int nHandle);                                // stop it
};
Unk_CscEffects* FUN_1403ed280();
class Unk_CscVoiceProp : public CPtred { public: void FUN_141791400(int nGender, int nJob, CString& strEvent); };
class Unk_CscSoundProps { public: MS2Ptr<Unk_CscVoiceProp> FUN_141793110(const CString& strName); };
Unk_CscSoundProps* FUN_1411b1de0();
class Unk_CscSound { public: int FUN_1417b04d0(const CString& strName, size_t* pBank); };   // the length of a sound, -1 if absent
Unk_CscSound* FUN_140c9cb10();

class Unk_140a94350
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_140a94350* FUN_140a94350();
class Unk_CscKeyGroups { public: void FUN_1422b9fd0(int nGroup); int FUN_1422b9e00(); };
Unk_CscKeyGroups* FUN_1408e57f0();
class Unk_CscFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_CscFeatures* FUN_140166410();
CInputKeyHandler* FUN_14025e7c0();
UITalkManager* FUN_140967100();
class Unk_CscOption { public: unsigned char* FUN_140a58500(); };   // the gamepad state (first byte: a pad is in use)
Unk_CscOption* FUN_1409a8b10();
class Unk_CscKeyTable { public: CStringW FUN_14142d760(int nKey, int nKind); };   // the key name of a binding
Unk_CscKeyTable* FUN_1409331f0();
class Unk_CscUiScale { public: float FUN_1422afec0(int nUiId); };
Unk_CscUiScale* FUN_14025e7a0();
MS2Ptr<ASGameEntity> FUN_140ba77e0(int nUiId, const Scaleform::GFx::Value& root);   // new ASGameEntity(root, nUiId)

class Unk_CscTextKeys { public: CStringW FUN_14087ede0(const CStringW& str); };
class Unk_CscTexts { public: Unk_CscTextKeys* FUN_140a87690(); Unk_CscTextKeys* FUN_141747b40(); };
Unk_CscTexts* FUN_140a87680();
class Unk_CscReserved { public: void FUN_1416fb300(CStringW& str); };
Unk_CscReserved* FUN_1403b4750();
class CMsgBoxData : public CPtred {};                             // the message box (unit_1406125d0.h; only released here)
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW text);

unsigned FUN_140869420();                                           // the tick
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
    FUN_140939a10()->FUN_140da4e40(L"NotifyRemoveGameObject", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::FUN_1419085e0));
    FUN_140939a10()->FUN_140da4e40(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::FUN_141908620));
}

// @0x1419072a0
UICutSceneCinematic::~UICutSceneCinematic()
{
    FUN_140939a10()->FUN_140da4eb0(L"NotifyRemoveGameObject", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::FUN_1419085e0));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyFadeInComplete", Delegate<void(NotifyObject*)>(this, &UICutSceneCinematic::FUN_141908620));
}

// @0x141907520
CString UICutSceneCinematic::vfunc_1()
{
    return "CutSceneCinematic";
}
MS2_REPLACE_METHOD(0x141907520, UICutSceneCinematic, vfunc_1, 61, 0x75C8B586);

// @0x141907570
UICutSceneCinematic::BalloonGroup::BalloonGroup()
    : m_bShown(false)
{
}

// @0x1419075c0
void UICutSceneCinematic::vfunc_2()
{
    FUN_1422dbf00(m_2c, 0, 0);
    FUN_140b632f0()->FUN_1422d4780(this, 4);
    FUN_140a94350()->vfunc_10(0xb);
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
    FUN_140b632f0()->FUN_1422d4840(this, 4);
    FUN_140a94350()->vfunc_10(0);
}
MS2_REPLACE_METHOD(0x141907630, UICutSceneCinematic, vfunc_3, 219, 0x828082D7);

// MS2-FUNCTIONAL: the exe's bind-and-throw keeps two more pointer temps (8 more bytes of frame); behaviour equivalent
// @0x141907720
void UICutSceneCinematic::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    do{m_30->FUN_140bc71c0("m_skip",m_spSkip);if(m_spSkip==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(90),__FUNCTION__));}while(0);
    m_spSkip->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UICutSceneCinematic::FUN_141909460), 0);
    if (m_nMode == 1)
        FUN_141909490();
    else if (m_nMode == 2)
        FUN_141909550();
    else if (m_nMode == 3)
        FUN_141909610();
    CStringW strKey(L"$s_cutscene_skip_key");
    if (*FUN_1409a8b10()->FUN_140a58500())
        strKey = FUN_1409331f0()->FUN_14142d760(0x49409, 2);
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
        float fScale = FUN_14025e7a0()->FUN_1422afec0(m_28);
        spEntity->FUN_14190b490("setStageSize", DAT_143af62d4, DAT_143af62d8, fScale);
    }
}
MS2_REPLACE_METHOD(0x141907B60, UICutSceneCinematic, vfunc_43, 272, 0x83EFB7E0);

// @0x141907c80
int UICutSceneCinematic::vfunc_13()
{
    if (UISwfEntity::vfunc_13())
        return 1;
    if (FUN_140166410()->FUN_14036d570(2) && FUN_14025e7c0()->FUN_14116d950(0x2a, 0, 0) && FUN_14025e7c0()->FUN_14116d950(1, 0, 0))
    {
        FUN_141909230();
        FUN_141908040(false);
        FUN_1419080b0();
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116d840())
    {
        FUN_141908fc0();
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
void UICutSceneCinematic::FUN_141907f80(int nId, CStringW strText)
{
    if (nId == 0)
        return;
    m_nMode = 1;
    m_nCinematicId = nId;
    m_strText = strText;
    FUN_1419092a0(m_strText);
    FUN_141909490();
    FUN_140a94350()->vfunc_10(0xb);
}
MS2_REPLACE_METHOD(0x141907F80, UICutSceneCinematic, FUN_141907f80, 174, 0x4D855AE2);

// @0x141908040
void UICutSceneCinematic::FUN_141908040(bool bOn)
{
    if (bOn)
    {
        if (FUN_140967100()->FUN_141b21220())
            FUN_140967100()->FUN_141b1feb0();
        FUN_1408e57f0()->FUN_1422b9fd0(0x6200041);
    }
    else
    {
        FUN_1408e57f0()->FUN_1422b9fd0(0x620001d);
    }
}
MS2_REPLACE_METHOD(0x141908040, UICutSceneCinematic, FUN_141908040, 95, 0x0200FE35);

// @0x1419080b0
void UICutSceneCinematic::FUN_1419080b0()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("hideScript");
    m_30->Invoke("hideDirect");
    FUN_140cffa50(FUN_1422dbb40(), "m_bgInstance", "_out");
    FUN_140cffa50(FUN_1422dbb40(), "m_document", "_out");
    FUN_140a94350()->vfunc_10(0);
}
MS2_REPLACE_METHOD(0x1419080B0, UICutSceneCinematic, FUN_1419080b0, 460, 0xB4DFB1FB);

// @0x141908290
void UICutSceneCinematic::FUN_141908290(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    switch (nType)
    {
    case 1: FUN_141909700(packet); break;
    case 2: FUN_141909750(packet); break;
    case 3: FUN_141909780(packet); break;
    case 6: FUN_141909880(packet); break;
    case 7: FUN_141909e80(packet); break;
    case 8: FUN_141909eb0(packet); break;
    case 9: FUN_14190a400(packet); break;
    case 4: FUN_14190a4c0(packet); break;
    case 10: FUN_14190a6e0(packet); break;
    case 11: FUN_14190ac70(packet); break;
    case 12: FUN_14190aee0(packet); break;
    case 5: FUN_14190afb0(packet); break;
    }
}
MS2_REPLACE_METHOD(0x141908290, UICutSceneCinematic, FUN_141908290, 327, 0x2227BCC9);

// @0x141908410
void UICutSceneCinematic::FUN_141908410()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("hideScript");
}
MS2_REPLACE_METHOD(0x141908410, UICutSceneCinematic, FUN_141908410, 89, 0x4D1B078C);

// @0x141908470
void UICutSceneCinematic::FUN_141908470(CStringW strName, CStringW strText, CStringW strIllust, int nFlag)
{
    if (m_30.get())
        m_30->Invoke("setScript", CStringW(strName), CStringW(strText), CStringW(strIllust), nFlag);
}
MS2_REPLACE_METHOD(0x141908470, UICutSceneCinematic, FUN_141908470, 361, 0x81464EF3);

// @0x1419085e0
void UICutSceneCinematic::FUN_1419085e0(NotifyObject* pNotice)
{
    Unk_CscRemoveNotice* pRemove = reinterpret_cast<Unk_CscRemoveNotice*>(pNotice);
    m_groups.RemoveKey(pRemove->m_nObjectId);
}
MS2_REPLACE_METHOD(0x1419085E0, UICutSceneCinematic, FUN_1419085e0, 56, 0x844E23E8);

// @0x141908620
void UICutSceneCinematic::FUN_141908620(NotifyObject* pNotice)
{
    m_nSkipState = 0;
    m_strSkipKey.Empty();
    m_strSkipLabel.Empty();
    m_strSkipMsg.Empty();
}
MS2_REPLACE_METHOD(0x141908620, UICutSceneCinematic, FUN_141908620, 94, 0x765E5887);

// @0x141908690
void UICutSceneCinematic::FUN_141908690()
{
    FUN_141908410();
    m_talks.RemoveAll();
    m_spTalk = 0;
    m_nTalkEnd = 0;
    if (m_nVoice != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nVoice);
        m_nVoice = 0;
    }
}
MS2_REPLACE_METHOD(0x141908690, UICutSceneCinematic, FUN_141908690, 132, 0x45B8DE86);

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
    unsigned nTick = FUN_140869420();
    if (m_spTalk.get())
    {
        if (nTick < m_nTalkEnd)
            return;
        FUN_141908410();
        m_spTalk = 0;
        if (m_nVoice != 0)
        {
            FUN_1403ed280()->FUN_1411a6060(m_nVoice);
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
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC)
            FUN_141908470(pPC->vfunc_77(), CStringW(m_spTalk->m_strText), CStringW(), 0);
    }
    else
    {
        FUN_141908470(FUN_1401aa6a0(m_spTalk->m_nNpcId), CStringW(m_spTalk->m_strText), FUN_14016a730(FUN_140cc2c70(m_spTalk->m_strIllust), 0), m_spTalk->m_nFlag);
    }
    if (!m_spTalk->m_strSound.IsEmpty())
        m_nVoice = FUN_1403ed280()->FUN_1411a5d80(m_spTalk->m_strSound);
}
MS2_REPLACE_METHOD(0x141908750, UICutSceneCinematic, FUN_141908750, 1186, 0xFFB16FB9);

// @0x141908c00
void UICutSceneCinematic::FUN_141908c00()
{
    unsigned nTick = FUN_140869420();
    for (POSITION pos = m_groups.GetStartPosition(); pos != 0; m_groups.GetNext(pos))
    {
        int nId = m_groups.GetKeyAt(pos);
        PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
        if (pActor == 0)
            continue;
        NiAVObject* pRoot = FUN_141b6efc0(pActor->FUN_14123c410());
        if (pRoot == 0 || FUN_14098dad0(pRoot))
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
                spBalloon->FUN_1418fb730(spTalk->m_strText);
                spBalloon->FUN_1418fb6d0();
                spBalloon->FUN_140f48da0();
                spBalloon->vfunc_2();
                spGroup->m_bShown = true;
                spGroup->m_nHide = spTalk->m_nEnd;
                spGroup->m_talks.RemoveAt(i, 1);
                if (!spTalk->m_strSound.IsEmpty())
                    FUN_1403ed280()->FUN_1411a5d80(spTalk->m_strSound);
                break;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141908C00, UICutSceneCinematic, FUN_141908c00, 954, 0x50B57242);

// @0x141908fc0
void UICutSceneCinematic::FUN_141908fc0()
{
    if (m_nSkipState == 0)
        return;
    if (m_bSkipped)
        return;
    if (m_strSkipMsg.GetLength() != 0)
        FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>(this, &UICutSceneCinematic::FUN_141909420), StringFormat(L"s_cutscene_skip_msg_{0}", m_strSkipMsg));
    else
        FUN_141909100();
}

// @0x141909100
void UICutSceneCinematic::FUN_141909100()
{
    FUN_141909230();
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC)
        FUN_140a7b810(pPC)->FUN_1409536d0();
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyCutSceneCinematicSkip));
    m_bSkipped = true;
    if (m_spSkip)
        m_spSkip->vfunc_4(false);
}

// @0x141909230
void UICutSceneCinematic::FUN_141909230()
{
    if (m_nSkipState == 2 || m_nSkipState == 1)
    {
        COutPacket packet(0x2f, 0);
        packet.Encode1(8);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x141909230, UICutSceneCinematic, FUN_141909230, 103, 0x1F36D64F);

// @0x1419092a0
void UICutSceneCinematic::FUN_1419092a0(CStringW& strText)
{
    strText = FUN_140a87680()->FUN_140a87690()->FUN_14087ede0(strText);
    strText.Replace(L"\\n", L"\n");
    FUN_1403b4750()->FUN_1416fb300(strText);
}
MS2_REPLACE_METHOD(0x1419092A0, UICutSceneCinematic, FUN_1419092a0, 145, 0x2D9D36A2);

// @0x141909340
void UICutSceneCinematic::FUN_141909340(int nActorId)
{
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nActorId);
    if (pActor == 0)
        return;
    NiAVObject* pRoot = FUN_141b6efc0(pActor->FUN_14123c410());
    if (pRoot == 0 || FUN_14098dad0(pRoot))
        return;
    MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = pActor->vfunc_85();
    if (spBalloon == 0)
        return;
    spBalloon->vfunc_3();
}
MS2_REPLACE_METHOD(0x141909340, UICutSceneCinematic, FUN_141909340, 210, 0x52979E7F);

// @0x141909420
bool UICutSceneCinematic::FUN_141909420(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    FUN_141909100();
    return true;
}
MS2_REPLACE_METHOD(0x141909420, UICutSceneCinematic, FUN_141909420, 46, 0xF76CB353);

// @0x141909460
void UICutSceneCinematic::FUN_141909460(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_141908fc0();
}
MS2_REPLACE_METHOD(0x141909460, UICutSceneCinematic, FUN_141909460, 29, 0xE9715B8A);

// @0x141909490
void UICutSceneCinematic::FUN_141909490()
{
    if (m_30 == 0)
        return;
    m_30->FUN_14129cce0("setCinematic", m_nCinematicId, CStringW(m_strText));
}
MS2_REPLACE_METHOD(0x141909490, UICutSceneCinematic, FUN_141909490, 184, 0x56FF538B);

// @0x141909550
void UICutSceneCinematic::FUN_141909550()
{
    if (m_30 == 0)
        return;
    m_30->FUN_140f5ff80("setOpening", CStringW(m_strText), m_bOpening);
}
MS2_REPLACE_METHOD(0x141909550, UICutSceneCinematic, FUN_141909550, 186, 0x5FB2857B);

// @0x141909610
void UICutSceneCinematic::FUN_141909610()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("setIntro", CStringW(m_strText));
}
MS2_REPLACE_METHOD(0x141909610, UICutSceneCinematic, FUN_141909610, 161, 0x0CC3B5AF);

// @0x1419096c0
bool UICutSceneCinematic::FUN_1419096c0()
{
    return FUN_1408e57f0()->FUN_1422b9e00() == 0x6200041;
}
MS2_REPLACE_METHOD(0x1419096C0, UICutSceneCinematic, FUN_1419096c0, 57, 0x1B8A4E6C);

// @0x141909700
void UICutSceneCinematic::FUN_141909700(CInPacket& packet)
{
    bool bOn = packet.vfunc_o8_0();
    FUN_141908040(bOn);
}
MS2_REPLACE_METHOD(0x141909700, UICutSceneCinematic, FUN_141909700, 71, 0x9EF82459);

// @0x141909750
void UICutSceneCinematic::FUN_141909750(CInPacket& packet)
{
    FUN_1419080b0();
}
MS2_REPLACE_METHOD(0x141909750, UICutSceneCinematic, FUN_141909750, 29, 0x72FB9950);

// @0x141909780
void UICutSceneCinematic::FUN_141909780(CInPacket& packet)
{
    int nId = packet.vfunc_o8_3();
    CStringW strText = packet.vfunc_o8_8();
    CStringW strUnused = packet.vfunc_o8_8();
    FUN_141907f80(nId, CStringW(strText));
}
MS2_REPLACE_METHOD(0x141909780, UICutSceneCinematic, FUN_141909780, 241, 0x184D9336);

// MS2-FUNCTIONAL: the exe passes job/gender through ecx (mov ecx,[x]; mov r8d,ecx), the source type behind it is not recovered
// @0x141909880
void UICutSceneCinematic::FUN_141909880(CInPacket& packet)
{
    int nNpcId = packet.vfunc_o8_3();
    CString strIllust = packet.vfunc_o8_7();
    CStringW strText = packet.vfunc_o8_8();
    unsigned nDuration = packet.vfunc_o8_3();
    unsigned nFlag = packet.vfunc_o8_1();
    CString strSound = FUN_14016a600(strText, 0);
    if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
        strSound.Remove('$');
    FUN_1419092a0(strText);
    if (strText.IsEmpty())
        return;
    unsigned nSound = 0;
    MS2Ptr<Unk_CscVoiceProp> spVoice = FUN_1411b1de0()->FUN_141793110(strSound);
    if (spVoice.get())
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC)
        {
            CString strEvent;
            int nJob = FUN_141654700(pPC);
            int nGender = FUN_141658e60(pPC);
            spVoice->FUN_141791400(nGender, nJob, strEvent);
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
    spTalk->m_strSound = nSound == 0 ? CString("") : CString(strSound);
    m_talks.AddTail(spTalk);
}

// @0x141909e80
void UICutSceneCinematic::FUN_141909e80(CInPacket& packet)
{
    FUN_141908690();
}
MS2_REPLACE_METHOD(0x141909E80, UICutSceneCinematic, FUN_141909e80, 29, 0xE78F1D46);

// @0x141909eb0
void UICutSceneCinematic::FUN_141909eb0(CInPacket& packet)
{
    unsigned bRaw = packet.vfunc_o8_1();
    int nId = packet.vfunc_o8_3();
    CStringW strText = packet.vfunc_o8_8();
    unsigned nDuration = packet.vfunc_o8_3();
    unsigned nDelay = packet.vfunc_o8_3();
    CString strSound("");
    if (bRaw == 0)
    {
        strSound = FUN_14016a600(strText, 0);
        if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
            strSound.Remove('$');
        FUN_1419092a0(strText);
    }
    else
    {
        strText = FUN_140a87680()->FUN_141747b40()->FUN_14087ede0(strText);
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
    spTalk->m_nStart = FUN_140869420() + nDelay;
    spTalk->m_nEnd = spTalk->m_nStart + nDuration;
    spTalk->m_strSound = strSound;
    spGroup->m_talks.Add(spTalk);
}

// @0x14190a400
void UICutSceneCinematic::FUN_14190a400(CInPacket& packet)
{
    int nId = packet.vfunc_o8_3();
    MS2Ptr<BalloonGroup> spGroup;
    if (m_groups.Lookup(nId, spGroup))
    {
        if (spGroup->m_bShown)
            FUN_141909340(nId);
        spGroup->m_talks.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x14190A400, UICutSceneCinematic, FUN_14190a400, 177, 0xE46A55A7);

// @0x14190a4c0
void UICutSceneCinematic::FUN_14190a4c0(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    CStringW strLabel;
    switch (nType)
    {
    case 2: strLabel = "$s_cutscene_skip_state"; break;
    case 1: strLabel = "$s_cutscene_skip_scene"; break;
    }
    m_strSkipMsg = packet.vfunc_o8_7();
    CStringW strKey(L"$s_cutscene_skip_key");
    if (*FUN_1409a8b10()->FUN_140a58500())
        strKey = FUN_1409331f0()->FUN_14142d760(0x49409, 2);
    FUN_141907d60(nType, CStringW(strKey), CStringW(strLabel));
}
MS2_REPLACE_METHOD(0x14190A4C0, UICutSceneCinematic, FUN_14190a4c0, 523, 0xECC7A13D);

// @0x14190a6e0
void UICutSceneCinematic::FUN_14190a6e0(CInPacket& packet)
{
    if (!m_30)
        return;
    CStringW strType = packet.vfunc_o8_8();
    CStringW strText1 = packet.vfunc_o8_8();
    CStringW strText2 = packet.vfunc_o8_8();
    CStringW strAlign = packet.vfunc_o8_8();
    int nDuration = packet.vfunc_o8_3();
    float fX = packet.vfunc_o8_5();
    float fY = packet.vfunc_o8_5();
    float fScale = packet.vfunc_o8_5();
    FUN_1419092a0(strText1);
    CString strSound = FUN_14016a600(strText2, 0);
    if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
        strSound.Remove('$');
    FUN_1419092a0(strText2);
    ASObj obj(2);
    obj.FUN_1407cb9c0("captionID", 0);
    obj.FUN_1407cbb20("captionType", CStringW(strType));
    obj.FUN_1407cbb20("captionStr1", CStringW(strText1));
    obj.FUN_1407cbb20("captionStr2", CStringW(strText2));
    obj.FUN_1407cbb20("captionAlign", CStringW(strAlign));
    obj.FUN_1409c4a30("offsetRatioX", fX);
    obj.FUN_1409c4a30("offsetRatioY", fY);
    obj.FUN_1407cb9c0("captionDuration", nDuration);
    obj.FUN_1409c4a30("captionScale", fScale);
    m_30->Invoke("setCaption", obj);
    if (!strSound.IsEmpty())
        FUN_1403ed280()->FUN_1411a5d80(strSound);
}
MS2_REPLACE_METHOD(0x14190A6E0, UICutSceneCinematic, FUN_14190a6e0, 1408, 0x2065A4F5);

// @0x14190ac70
void UICutSceneCinematic::FUN_14190ac70(CInPacket& packet)
{
    m_strText = packet.vfunc_o8_8();
    m_bOpening = packet.vfunc_o8_0();
    m_nMode = 2;
    CString strSound = FUN_14016a600(m_strText, 0);
    if (strSound.Left(1) == "$" && strSound.Right(1) == "$")
        strSound.Remove('$');
    FUN_1419092a0(m_strText);
    FUN_141909550();
    if (!FUN_1419096c0())
        FUN_141908040(true);
    if (!strSound.IsEmpty())
        FUN_1403ed280()->FUN_1411a5d80(strSound);
}
MS2_REPLACE_METHOD(0x14190AC70, UICutSceneCinematic, FUN_14190ac70, 617, 0xE5FDE549);

// @0x14190aee0
void UICutSceneCinematic::FUN_14190aee0(CInPacket& packet)
{
    m_strText = packet.vfunc_o8_8();
    m_nMode = 3;
    FUN_1419092a0(m_strText);
    FUN_141909610();
    if (!FUN_1419096c0())
        FUN_141908040(true);
}
MS2_REPLACE_METHOD(0x14190AEE0, UICutSceneCinematic, FUN_14190aee0, 190, 0xC358CCEE);

// @0x14190afb0
void UICutSceneCinematic::FUN_14190afb0(CInPacket& packet)
{
    m_talks.RemoveAll();
    m_strSkipMsg.Empty();
    FUN_141907d60(0, CStringW(L""), CStringW(L""));
}
MS2_REPLACE_METHOD(0x14190AFB0, UICutSceneCinematic, FUN_14190afb0, 165, 0x7F0B1D8B);

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
    args.FUN_1409b2800(3);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14190b570
inline Scaleform::GFx::Value AScript::FUN_14190b570(const char* szMethod, bool a1, CStringW a2, CStringW a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcce0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

MS2_EMIT_CRT_MEMMOVE_S();
