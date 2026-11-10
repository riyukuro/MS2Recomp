// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITalkCinematic: the full-screen NPC talk window, and
// UITalkManager: the talk state machine behind it (the packets of the talk, the script/page walk, the reward block).
// MS2-UNIT: ?\uitalkcinematic.cpp
// MS2-RANGE: 0x141b19ea0-0x141b224f0 .text$mn
// MS2-RANGE: 0x14011de60-0x14011e260 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCCinematicContent@@@@QEAAAEAV1@PEAVCCinematicContent@@@Z 0x141b1d710 ; prop
// MS2-PIN: ?IsNull@?$MS2Ptr@VCCinematicContent@@@@QEBA_NXZ 0x141b1d780 ; unique
// MS2-PIN: ?vfunc_48@UITalkCinematic@@UEAAHXZ 0x141b1d840 ; unique
// MS2-PIN: memmove_s 0x141b1d960 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCTalkScript@@@@QEAAAEAV1@PEAVCTalkScript@@@Z 0x141b22220 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0?$MS2Ptr@VCCinematicContent@@@@QEAA@AEBV0@@Z 0x141b1d600 ; merge-bind
// MS2-PIN: ??0?$MS2Ptr@VUITalkCinematic@@@@QEAA@PEAVUITalkCinematic@@@Z 0x141b22100 ; merge-bind
// MS2-PIN: ??1?$MS2Ptr@VCScriptContent@@@@QEAA@XZ 0x141b22180 ; merge-bind
// MS2-PIN: ?AddRef@?$MS2Ptr@VUITalkCinematic@@@@AEBAXXZ 0x141b223e0 ; merge-bind
// MS2-PIN: ?Reference@?$MS2Ptr@VCCinematicContent@@@@CAXPEAVCCinematicContent@@@Z 0x141b22410 ; merge-bind
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCScriptContent@@@@AEBAXPEAX@Z 0x141b22430 ; merge-bind
// MS2-PIN: ?Release@?$MS2Ptr@VCScriptContent@@@@AEAAXXZ 0x141b22460 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCScriptContent@@@@AEAAXPEAX@Z 0x141b224a0 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitalkcinematic.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uitalkcinematic.h"
#include "cinematiccomponent.h"
#include "wireframemanager.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/placeholder/ctalkscript.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/unnamed/unit_140ad1860.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/client/ms2/npcdatacli.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<int>::Get
#include "ms2/placeholder/intervaltimer.h"  // C3: Unk_IntervalTimer::Init, Check
#include "ms2/commonfiles/npcdata.h"  // C3: CNpcData (FindNpcData)
#include "ms2/placeholder/cgameoption.h"  // C3: CGameOption::FUN_140b123b0
#include "ms2/placeholder/cnpc.h"  // C3: CNpc (Unk_TcNpc)
#include "ms2/client/ms2/ridee.h"  // C3: Ridee (efd::SmartPointer<Ridee>)
#include "ms2/client/ms2/uiemoticon.h"  // C3: UIEmoticon::Entity (Unk_PCBaseComp_a88)
#include "ms2/client/ms2/uichatballoon.h"  // C3: UIChatBalloon::Entity (Unk_PCBaseComp_aa8)

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics (init order: the shared header's four, the file's two, then a second shared header's) ----

static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_nextKey = "cinematic_nextkey";
static NiRTTI s_talkManagerRegistrar("UITalkManager", 0);
static CString s_strSortTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNamesLike2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe objects (Unk_ names and member names are invented) ----

class UINpcPreviewDialog : public UIObject
{
public:
    int GetNpcId() { return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x178); }   // 0x141b1d820 the npc id
};

class Unk_TcEntity : public ASGameEntity
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const CString& strCall);              // 13 the "hide" call
};

UINpcPreviewDialog* GetNpcPreviewDialog(unsigned nUiId);              // the open npc preview dialog
void CreateItemInfoSlot(const CString& strName, MS2Ptr<CItem> spItem, int a, int nIcon, int nFlags);


class Unk_TcWorld
{
public:
    MyPC* GetLocalPlayer();                                      // local player
};

class Unk_TcUi : public CUIService
{
public:
    void FUN_141adc530(int nId);                                // close
};

class CUserMail { public: static __int64 GetGFxSceneService(); };  // C3: member view (the scene-service global)
class GFxSceneService   // C3: member view (real class not in this TU)
{
public:
    UISceneEntity* FUN_1422b9e20(int);
    int SetSubScene(int nSubSceneId);
};
UISwfEntityManager* GetUISwfEntityManager();
#include "ms2/placeholder/ichromamanager.h"  // C3: ChromaSDK::GetChromaManager








// FUN_14025e7a0 (the GFxManager singleton, 0x14025e7a0) is declared in gfxmanager.h
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
UITalkCinematic* FindTalkCinematic(int nId);

class Unk_TcSettings { public: char m_pad[0xe0f8]; };
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool IsFeatureEnabled(int);
};

class Unk_TcOpt { public: char m_pad[6]; unsigned char m_6; };
class Unk_MyPCEquip;
class CEquipItem;
class PC   // C3: member view (the real class is not in this TU)
{
public:
    MS2Ptr<CEquipItem> FUN_141655e10(int nSlot);
    int GetJobGroupId();                                        // job code
    int GetGender();                                        // gender
    Unk_MyPCEquip* GetGemEquip();
};
template <class A, class B> CString Unk_SocketFormat(const char* szFmt, const A& a, const B& b);

   // the illust path of an npc
class Unk_NpcTableCli* GetNpcDataTableCli();   // C3: was GetNpcDataTableCli
CString FUN_140cc2c70(const CString& strPath);                  // the full path of an illust
unsigned FUN_141b70ea0(const CString& strPath);                 // the file exists

                                          // the effect service
#include "ms2/client/ms2/effectservice.h"
CStringW Unk_ArcWide(const wchar_t* psz, int n);                    // a wide string as a CString
int PlaySystemSound(const CString& strSound, const CString& strArg);
void DestroyItemInfoSlot(const CString& strImage);                        // release a reward image

// The npc actor of the talk.
class Unk_TcNpc : public CNpc {};

extern unsigned DAT_143af62d4, DAT_143af62d8;

// ---- UITalkCinematic ----

// @0x141b19ea0
UITalkCinematic::UITalkCinematic()
{
    m_nLoaded = 0;
    m_nTalkComplete = 1;
    m_spContent = 0;
    m_spComponent = 0;
    SetDefaultKeyGroup();
}

// @0x141b19f90
UITalkCinematic::~UITalkCinematic()
{
    m_spComponent = 0;
}

// @0x141b1a030
CString UITalkCinematic::GetTypeName() { return "TalkCinematic"; }

// @0x141b1a080
void UITalkCinematic::vfunc_2()
{
    LoadSwf(0x1c, 0, 0);
    GetUISwfEntityManager()->AddToLayer(this, 4);
    ChromaSDK::GetChromaManager()->SetState(2);
}

// @0x141b1a0e0
void UITalkCinematic::vfunc_3()
{
    m_nLoaded = 0;
    FUN_1422dc080();
    GetUISwfEntityManager()->RemoveFromLayer(this, 4);
    ChromaSDK::GetChromaManager()->SetState(0);
}

// @0x141b1a140
void UITalkCinematic::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    SetDefaultKeyGroup();
    if (TSingleton<UITalkManager>::GetInstance()->GetTalking() == 0)
    {
        ((GFxSceneService*)CUserMail::GetGFxSceneService())->SetSubScene(m_nKeyGroup);
    }
    else if (((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
    {
        MS2Ptr<CCinematicContent> spContent = TSingleton<UITalkManager>::GetInstance()->GetCurrentContent();
        if (spContent.IsNull())
            return;
        ASObj page(2);
        FUN_141b1bfe0(page, spContent.get());
        ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("init", page);
    }
}

// @0x141b1a280
void UITalkCinematic::vfunc_26() { UIObject::vfunc_26(); }

// @0x141b1a2a0
void UITalkCinematic::vfunc_43()
{
    MS2Ptr<ASMovieClip> spClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (spClip.get() != 0)
    {
        spClip->vfunc_2(5, 0, 0);
        float fScale = GetGFxManager()->GetMovieScale(m_28);
        spClip->FUN_14190b490("setStageSize", DAT_143af62d4, DAT_143af62d8, fScale);
    }
}

// @0x141b1a3b0
int UITalkCinematic::vfunc_13()
{
    if (IsNextKeyPressed())
        FUN_141b1bce0(0x493e2);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->IsActionKeyPressed(0x49409, 0, 0))
        FUN_141b1bce0(1);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->IsEscapePressed())
        FUN_141b1bce0(1);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->WasKeyPressed(0x79, 0, 0))
        FUN_141b1bce0(0x79);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->IsActionKeyPressed(0x30d41, 0, 0))
        FUN_141b1bce0(0x79);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->WasKeyPressed(0x7e, 0, 0))
        FUN_141b1bce0(0x7e);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->IsActionKeyPressed(0x30d42, 0, 0))
        FUN_141b1bce0(0x7e);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->WasKeyPressed(0x92, 0, 0))
        FUN_141b1bce0(0x79);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->WasKeyPressed(0x93, 0, 0))
        FUN_141b1bce0(0x7e);
    else
        return 0;
    return 1;
}

// @0x141b1a580
int UITalkCinematic::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    ASData data;
    if (_stricmp("OnLoadComplete", szMethod) == 0)
    {
        m_nLoaded = 1;
        TSingleton<UITalkManager>::GetInstance()->FUN_141b204d0();
        TSingleton<UITalkManager>::GetInstance()->OpenPendingDialogs();
        return 1;
    }
    else if (_stricmp("OnCloseComplete", szMethod) == 0)
    {
        FUN_1422dc080();
        ((GFxSceneService*)CUserMail::GetGFxSceneService())->SetSubScene(m_nKeyGroup);
        SetDefaultKeyGroup();
        return 1;
    }
    else if (_stricmp("OnTalkComplete", szMethod) == 0)
    {
        m_nTalkComplete = 1;
        return 1;
    }
    else if (_stricmp("OnEnd", szMethod) == 0)
    {
        FUN_141b1bce0(1);
        return 1;
    }
    else if (_stricmp("OnNext", szMethod) == 0)
    {
        FUN_141b1bce0(0x493e2);
        return 1;
    }
    else if (_stricmp("OnMovieComplete", szMethod) == 0)
    {
        m_nTalkComplete = 1;
        FUN_141b1bce0(0x493e2);
        return 1;
    }
    else if (_stricmp("OnSelect", szMethod) == 0)
    {
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            int nIndex = data.PopUInt();
            if (nIndex == -1)
                return 1;
            if (m_spComponent.get() != 0)
                m_spComponent->vfunc_1(nIndex);
        }
        return 1;
    }
    return 0;
}

// @0x141b1a8e0
int UITalkCinematic::ModifyScript(const CStringW& strScript, const CString& strSound, const CString& strIllust)
{
    if (m_spContent.IsNull())
        return 0;
    if (m_nLoaded == 0)
        return 0;
    if (m_nTalkComplete == 0)
        return 0;
    {
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (spEntity.get() != 0)
        {
            ASObj page(2);
            if (strIllust.GetLength() != 0)
            {
                ASObj illust(2);
                illust.SetStringMember("lNpc", GetIllustPath(strIllust));
                illust.SetIntMember("lNpcSpeak", 1);
                page.FUN_1409eb270("illust", illust);
            }
            else
            {
                FUN_141b1bfe0(page, TSingleton<UITalkManager>::GetInstance()->GetCurrentContent().get());
            }
            page.SetWStringMember("script", Unk_ArcWide(strScript, 0));
            spEntity->Invoke("modifyScript", page);
            if (strSound.GetLength() != 0)
            {
                Unk_TcNpc* pNpc = TSingleton<UITalkManager>::GetInstance()->GetTalkNpc();
                if (pNpc != 0)
                    TSingleton<CEffectService>::GetInstance()->PlayVoiceAt(CString(strSound), pNpc->vfunc_18());
            }
            return 1;
        }
    }
    return 0;
}

// @0x141b1ac40
void UITalkCinematic::ShowRewardPage(Unk_TalkItemList& rItems, const CStringW& strTitle, unsigned nMeso, unsigned nExp, __int64 nMerat)
{
    if (m_spContent.IsNull())
        return;
    if (m_nLoaded == 0)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
    {
        ASObj page(2);
        page.SetWStringMember("title", CStringW(strTitle));
        page.SetIntMember("meso", nMeso);
        page.SetIntMember("exp", nExp);
        page.FUN_1409c1180("merat", nMerat);
        for (unsigned __int64 i = 0; i < rItems.GetCount(); i++)
        {
            MS2Ptr<CItem> spItem = rItems[i];
            CString strImage;
            strImage.Format("%s_%d", (const char*)GetTypeName(), i);
            CreateItemInfoSlot(strImage, MS2Ptr<CItem>(spItem), 0, 0x11, 0x800);
            CString strKey;
            strKey.Format("reward%d", i + 1);
            AddImage(strImage);
            page.SetStringMember(strKey, strImage);
        }
        spEntity->Invoke("modifyReward", page);
    }
}

// @0x141b1b000
void UITalkCinematic::ShowMaidRewardPage(Unk_TalkItemList& rItems, const CStringW& strTitle, const CStringW& strMood, const CStringW& strAffinityExp, int nJackpot)
{
    if (m_spContent.IsNull())
        return;
    if (m_nLoaded == 0)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    if (rItems.GetCount() == 0)
        return;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
    {
        ASObj page(2);
        page.SetWStringMember("title", CStringW(strTitle));
        page.SetWStringMember("mood", CStringW(strMood));
        page.SetWStringMember("affinityExp", CStringW(strAffinityExp));
        page.SetIntMember("maidJackpot", nJackpot);
        for (unsigned __int64 i = 0; i < rItems.GetCount(); i++)
        {
            MS2Ptr<CItem> spItem = rItems[i];
            CString strImage;
            strImage.Format("%s_%d", (const char*)GetTypeName(), i);
            CreateItemInfoSlot(strImage, MS2Ptr<CItem>(spItem), 0, 0x11, 0x800);
            CString strKey;
            strKey.Format("reward%d", i + 1);
            AddImage(strImage);
            page.SetStringMember(strKey, strImage);
        }
        spEntity->Invoke("modifyReward", page);
    }
}

// @0x141b1b440
int UITalkCinematic::ShowPage(CCinematicContent* pContent, int bLast)
{
    if (pContent == 0)
        return 0;
    if (m_nLoaded == 0)
        return 0;
    if (m_nTalkComplete == 0)
        return 0;
    {
        ClearImages();
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (spEntity.get() != 0)
        {
            m_spContent.AssignRaw(pContent);
            m_nTalkComplete = 0;
            m_spComponent = CreateComponent(TSingleton<UITalkManager>::GetInstance()->GetSound());
            if (m_spComponent.get() != 0)
            {
                ASObj page(2);
                FUN_141b1bfe0(page, pContent);
                SetImagePlate(page, pContent);
                m_spComponent->vfunc_4(m_spContent);
                m_spComponent->vfunc_5(page);
                spEntity->Invoke("setScript", page);
                if (m_spContent->m_unk20.GetLength() != 0)
                {
                    if (TSingleton<UITalkManager>::GetInstance()->FUN_141b213c0() != 0)
                    {
                        MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
                        if (pPC != 0)
                            TSingleton<CEffectService>::GetInstance()->PlayVoiceAt(CString(m_spContent->m_unk20), pPC->vfunc_18());
                    }
                    else
                    {
                        Unk_TcNpc* pNpc = TSingleton<UITalkManager>::GetInstance()->GetTalkNpc();
                        if (pNpc != 0)
                            TSingleton<CEffectService>::GetInstance()->PlayVoiceAt(CString(m_spContent->m_unk20), pNpc->vfunc_18());
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

// @0x141b1b8b0
void UITalkCinematic::FUN_141b1b8b0()
{
    m_spContent = 0;
    m_nTalkComplete = 1;
    m_nLoaded = 0;
    m_spComponent = 0;
    ClearImages();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
    {
        reinterpret_cast<Unk_TcEntity*>(spEntity.operator->())->vfunc_13("hide");
    }
    else
    {
        FUN_1422dc080();
        ((GFxSceneService*)CUserMail::GetGFxSceneService())->SetSubScene(m_nKeyGroup);
        SetDefaultKeyGroup();
    }
}

// @0x141b1b9f0
void UITalkCinematic::SkipTalk()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
    {
        spEntity->Invoke("onSkip");
        PlaySystemSound(s_nextKey, "");
    }
}

// @0x141b1bad0
void UITalkCinematic::FocusUp()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->Invoke("onFocusUp");
}

// @0x141b1bb80
void UITalkCinematic::FocusDown()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->Invoke("onFocusDown");
}

// @0x141b1bc30
void UITalkCinematic::SelectOption()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (spEntity.get() != 0)
        spEntity->Invoke("onSelect");
}

// @0x141b1bce0
void UITalkCinematic::FUN_141b1bce0(int nMsg)
{
    if (m_nLoaded == 0)
        return;
    if (m_spContent.IsNull())
        return;
    if (m_nTalkComplete == 0 && nMsg == 0x493e2)
    {
        SkipTalk();
        return;
    }
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    bool bBusy = !((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("canNext")))->GetBool();
    if (bBusy)
        return;
    if (m_spComponent.get() != 0)
        m_spComponent->vfunc_2(nMsg);
}

// @0x141b1be50
void UITalkCinematic::PlayFireworkEffect()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    ((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("onFireworkEffect");
}

// @0x141b1beb0
void UITalkCinematic::AddImage(CString strImage)
{
    m_images.Add(strImage);
}

// @0x141b1bf00
void UITalkCinematic::ClearImages()
{
    for (unsigned __int64 i = 0; i < m_images.GetCount(); i++)
        DestroyItemInfoSlot(m_images[i]);
    m_images.RemoveAll();
}

// @0x141b1bf80
void UITalkCinematic::SetKeyGroup(unsigned nKeyGroup) { m_nKeyGroup = nKeyGroup; }

// @0x141b1bfa0
void UITalkCinematic::SetDefaultKeyGroup() { m_nKeyGroup = 0x620001d; }

// @0x141b1bfc0
int UITalkCinematic::GetLoaded() { return m_nLoaded; }

// @0x141b1bfe0
void UITalkCinematic::FUN_141b1bfe0(ASObj& rPage, const CCinematicContent* pContent)
{
    ASObj illust(2);
    if (TSingleton<UITalkManager>::GetInstance()->FUN_141b213c0() != 0)
    {
        if (TSingleton<CUIService>::GetInstance()->IsDialogClosed((eUIClassID)0x4e89) == 0)
        {
            UINpcPreviewDialog* pPreview = GetNpcPreviewDialog(0x4e89);
            if (pPreview != 0)
            {
                illust.SetStringMember("lNpc", GetIllustPath(((class NpcDataTableCli*)GetNpcDataTableCli())->GetIllust(pPreview->GetNpcId())));
                illust.SetIntMember("lNpcSpeak", 1);
                rPage.FUN_1409eb270("illust", illust);
                return;
            }
        }
    }
    if (pContent == 0)
        return;
    if (pContent->m_leftIllust.GetLength() != 0 || pContent->m_rightIllust.GetLength() != 0)
    {
        illust.SetStringMember("lNpc", GetIllustPath(pContent->m_leftIllust));
        illust.SetBoolMember("lNpcSpeak", pContent->m_leftIllust == pContent->m_speakerIllust);
        illust.SetStringMember("rNpc", GetIllustPath(pContent->m_rightIllust));
        illust.SetBoolMember("rNpcSpeak", pContent->m_rightIllust == pContent->m_speakerIllust);
        FUN_141b1c720(illust, pContent->m_myTalk);
    }
    else if (pContent->m_myTalk != 0)
    {
        FUN_141b1c720(illust, pContent->m_myTalk);
    }
    else if (pContent->m_unk28.GetLength() != 0)
    {
        illust.SetStringMember("lNpc", GetIllustPath(pContent->m_unk28));
        illust.SetIntMember("lNpcSpeak", 1);
    }
    else if (pContent->m_otherNpcTalk != 0)
    {
        illust.SetStringMember("rNpc", GetNpcIllustPath(pContent->m_otherNpcTalk));
        illust.SetIntMember("rNpcSpeak", 1);
    }
    else if (pContent->m_speakerNpc == 0 || pContent->m_speakerNpc == (int)TSingleton<UITalkManager>::GetInstance()->GetTalkNpcId())
    {
        illust.SetStringMember("lNpc", GetNpcIllustPath((unsigned)TSingleton<UITalkManager>::GetInstance()->GetTalkNpcId()));
        illust.SetIntMember("lNpcSpeak", 1);
    }
    rPage.FUN_1409eb270("illust", illust);
}

// @0x141b1c4c0
void UITalkCinematic::SetImagePlate(ASObj& rPage, const CCinematicContent* pContent)
{
    if (pContent == 0)
        return;
    rPage.SetStringMember("imagePlate", CString(pContent->m_imagePlate));
}

// @0x141b1c530
int UITalkCinematic::IsNextKeyPressed()
{
    if (((class CInputKeyHandler*)FUN_14025e7c0())->IsActionKeyPressed(0x493e2, 0, 0))
        return 1;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->IsActionKeyDown(0x493e2, 0, 0))
    {
        if (m_nextKeyTimer.Check(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(reinterpret_cast<char*>(((class Unk_TcSettings*)GetClientConstants())) + 0xe0f8)->Get()))
            return 1;
    }
    else
        m_nextKeyTimer.Init();
    return 0;
}

// @0x141b1c5e0
CString UITalkCinematic::GetNpcIllustPath(unsigned nNpcId)
{
    return GetIllustPath(((class NpcDataTableCli*)GetNpcDataTableCli())->GetIllust(nNpcId));
}

// @0x141b1c670
CString UITalkCinematic::GetIllustPath(const CString& strName)
{
    CString strPath = FUN_140cc2c70(strName);
    if (FUN_141b70ea0(strPath) == 0)
        return "empty";
    return strPath;
}

// @0x141b1c720
void UITalkCinematic::FUN_141b1c720(ASObj& rPage, int nNpcTalk)
{
    if (nNpcTalk == 0)
        return;
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return;
    CString strIllust;
    if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->IsFeatureEnabled(0x96) && ((class Unk_TcOpt*)reinterpret_cast<CGameOption*>((TSingleton<CGameOption>::GetInstance()))->GetStatus())->m_6 != 0)
    {
        int nJob = ((PC*)pPC)->GetJobGroupId();
        CString strGender(((PC*)pPC)->GetGender() == 1 ? "f" : "m");
        strIllust = GetIllustPath(Unk_SocketFormat<int, CString>("{0}_{1}", nJob, strGender));
    }
    if (nNpcTalk == 2)
    {
        rPage.SetStringMember("lNpc", CString(strIllust));
        rPage.SetIntMember("lNpcSpeak", 1);
    }
    else
    {
        rPage.SetStringMember("rNpc", CString(strIllust));
        rPage.SetIntMember("rNpcSpeak", 1);
    }
}

// @0x141b1c960
MS2Ptr<CCinematicComponent> UITalkCinematic::CreateComponent(int nButtonSet)
{
    switch (nButtonSet)
    {
    case 6: return MS2Ptr<CCinematicComponent>(new CQuestAcceptCinematicComponent(this));
    case 7: return MS2Ptr<CCinematicComponent>(new CQuestCompleteCinematicComponent(this));
    case 8: return MS2Ptr<CCinematicComponent>(new CQuestProgressCinematicComponent(this));
    case 4: return MS2Ptr<CCinematicComponent>(new CNextCinematicComponent(this));
    case 3: return MS2Ptr<CCinematicComponent>(new CCloseCinematicComponent(this));
    case 9: return MS2Ptr<CCinematicComponent>(new CSelectableDistractorCinematicComponent(this));
    case 19: return MS2Ptr<CCinematicComponent>(new CCustomSelectableDistractorCinematicComponent(this));
    case 5: return MS2Ptr<CCinematicComponent>(new CSelectableTalkCinematicComponent(this));
    case 11: return MS2Ptr<CCinematicComponent>(new CChangeJobComponent(this));
    case 10: return MS2Ptr<CCinematicComponent>(new CSelectableBeautyCinematicComponent(this));
    case 12: return MS2Ptr<CCinematicComponent>(new CUgcSignCinematicComponent(this));
    case 13: return MS2Ptr<CCinematicComponent>(new CPaneltyResolveCinematicComponent(this));
    case 18: return MS2Ptr<CCinematicComponent>(new CHomeDoctorCinematicComponent(this));
    case 14: return MS2Ptr<CCinematicComponent>(new CTakeBoatCinematicComponent(this));
    case 15: return MS2Ptr<CCinematicComponent>(new CSellUGCMapCinematicComponent(this));
    case 16: return MS2Ptr<CCinematicComponent>(new CRouletteCinematicComponent(this));
    case 17: return MS2Ptr<CCinematicComponent>(new CRouletteSkipCinematicComponent(this));
    case 1: return MS2Ptr<CCinematicComponent>(new CEmptyCinematicComponent(this));
    case 2: return MS2Ptr<CCinematicComponent>(new CStopCinematicComponent(this));
    default:
        TSingleton<UITalkManager>::GetInstance()->SendNpcTalkMode0();
        return MS2Ptr<CCinematicComponent>(0);
    }
}

// @0x141b1d3d0
int UITalkCinematic::GetLowerCutGlobalY()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return -1;
    return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("getLowerCutGlobalY")))->GetUInt();
}

// @0x141b1d460
int UITalkCinematic::GetIllustGlobalX()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return -1;
    return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(((MS2Ptr<AScript>*)(&m_30))->operator->()->Invoke("getIllustGlobalX")))->GetUInt();
}

// @0x141b1d4f0
UINpcPreviewDialog* GetNpcPreviewDialog(unsigned nUiId)
{
    if (reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spDialog = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spDialog.get())
            return dynamic_cast<UINpcPreviewDialog*>((UIObject*)spDialog);
    }
    return 0;
}

// ---- UITalkManager: packets and dialogs ----

CTalkScript* FUN_140854fa0(void* pThis, CInPacket& in);        // CTalkScript::CTalkScript(CInPacket&) (talkscript.cpp, not recovered)


// The UI message sent to the swf entity registered for an event id (same shape as functioncubeobject.cpp's).
#include "ms2/gfxui/uimsg.h"  // C3: UIMsg






// The emoticon-like component of the npc (PCBase slot 83): kind 2 shows the text.
class Unk_PCBaseComp_a88 : public UIEmoticon::Entity {};
// The chat-balloon component (PCBase slot 85: UIChatBalloon::Entity).
class Unk_PCBaseComp_aa8 : public UIChatBalloon::Entity {};

// The packet manager's request wrappers (the exe's int-encoding helper).
void FUN_1401fcd50(unsigned char* p, COutputStream& stream);
struct Unk_TcInt
{
    Unk_TcInt() : m_n(0) {}                                     // 0x141b22160
    int m_n;
};
void FUN_140710590(COutPacket& packet);

// The dialogs the talk opens (opaque views; the members are bound by VA).
class UIJobChangeDialog* FindJobChangeDialog(int);   // C3: was FindJobChangeDialog
class UIJobChangeDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419dc510(int);
};
class CUserMaidManager   // C3: member view for the former free stand-ins
{
public:
    static class UIMaidDialog* GetMaidDialog(int);
};
class UIMaidDialog { public: void SetMaid(int nMaidId, unsigned __int64 nMaidUid); };
class CManufactureManager   // C3: member view for the former free stand-ins
{
public:
    static class UIManufactureDialog* GetManufactureDialog(int);
};
class UIManufactureDialog { public: void SetNpcAndManufactureId(int nNpcId, unsigned __int64 nManufactureId); };
void* GetItemEnchantDialog(unsigned int);   // C3: was FUN_1413b1bc0
class UIItemEnchantDialog { public: void SetModeByName(CString name); };
class UIAttendGiftDialog;
template <class T> T* FindDTDialog(int nId);
class UIAttendGiftDialog   // C3: member view for the former free stand-ins
{
public:
    bool SelectRequestedEvent(int);
};
unsigned ParseUInt(const CString& str);
class UIItemTreasureMapDialog : public UIObject { public: void FUN_140c55b50(const CString& strArg); };
UIItemTreasureMapDialog* FindItemTreasureMapDialog(unsigned nUiId);
class UIWeddingHallReservationDialog* GetWeddingHallReservationDialog(int);   // C3: was GetWeddingHallReservationDialog
class UIWeddingHallReservationDialog   // C3: member view for the former free stand-ins
{
public:
    void SetPackage(int);
    void SetMode(const CString& strMode);
};
class Unk_TcWedding { public: char m_pad[0x18]; unsigned m_18; };
void FUN_140901e60(void* p);
class Unk_ThHallRef   // C3: member view (real class not in this TU)
{
public:
    void* FUN_141847330() const;
};
class UIRewardNotify* FindRewardNotify(int);   // C3: was FindRewardNotify
class UIRewardNotify
{
public:
    void FUN_141abfa10(MS2Ptr<CItem> pItem);
    void FUN_141abf230(__int64 nExp, __int64 nBonus);
    void FUN_141abf450(__int64 nMoney, __int64 nBonus);
};

// More views for the talk functions.
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980

class CMaid : public CPtred   // C3: member view for the former free stand-ins
{
public:
    int IsExpired();
};
class CEquipItem : public CPtred   // C3: member view for the former free stand-ins
{
public:
    struct Unk_EquipItemData* GetItemData();
};
class CItemData   // C3: member view
{
public:
    struct ItemModelHead* FUN_14053ec70();
};
struct ItemModelHead   // C3: member view for the former free stand-ins
{
public:
    bool FUN_1405471d0();
};
class PCGemEquip   // C3: member view for the former free stand-ins
{
public:
    int IsSlotHidden(int);
};
void FUN_141275260(int nMsg, int a, int b);
void ShowSystemNotice(const CStringW& strMsg, int a, int b);
CStringW GetStringByKey(CStringW strKey);

class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
class UIBeautyShopDialog;
template <class T> T* Unk_SSGGetDialog(int nId);
class UIBeautyShopDialog   // C3: member view for the former free stand-ins
{
public:
    void SetPalette(int);
};
class UICutSceneMovie* FindCutSceneMovie(int);   // 0x14138fd50 the cut scene movie dialog (guideentity_1b)
class UICutSceneMovie { public: void PlayScene(int nSceneId, CString strPath); };
CString FUN_14016a600(const wchar_t* pw, int n);
void Unk_SplitA(CString& str, ATL::CAtlArray<CString>* pOut, const char* szSep);

MS2Ptr<CNpcData> FindNpcData(int nNpcId);

// Talk script lookups (by npc and kind): the handle is returned by value.

CCinematicContent* GetCinematicContent(MS2Ptr<CScriptContent> spContent);
unsigned __int64 GetDialogIdByKind(const CString& strKind, const CString& strMode);
unsigned __int64 GetDialogType(int nDialog, const CString& strMode, const CString& strKind);
Unk_ScriptPtr<CTalkScript> FUN_140856fa0(int nNpcId, int nKind);
Unk_ScriptPtr<CTalkScript> GetNpcPickTalk(int nNpcId, int nFlag);
Unk_ScriptPtr<CTalkScript> FUN_140856820(int nNpcId, int nParam);
Unk_ScriptPtr<CTalkScript> FindQuestTalk(int nId, int nParam);
int FUN_140855cd0(unsigned char nFlags);
int GetTalkButtonSet(Unk_ScriptPtr<CTalkScript> spScript, int nFlags, int nNpc, int nPage);
#include "ms2/commonfiles/scriptptr.h"
template <class T> T* Unk_GaGetUIByName(const CString& strDialog);   // the dialog of a name

// @0x141b1da80
Unk_TalkIdState::Unk_TalkIdState()
{
    Reset();
}

// @0x141b22200
Unk_TalkIdState::~Unk_TalkIdState()
{
}

// @0x141b1dac0
void Unk_TalkIdState::Reset()
{
    m_ids.RemoveAll();
    m_nPos = 0;
}

// @0x141b1daf0
unsigned Unk_TalkIdState::GetCurrentId()
{
    if (m_nPos >= (int)m_ids.GetCount())
        return 0;
    return m_ids[m_nPos];
}

// @0x141b1db40
UITalkManager::CTalkRewardData::CTalkRewardData()
{
    m_nMeso = 0;
    m_nMerat = 0;
    m_nExp = 0;
    m_nAffinity = 0;
    m_nJackpot = 0;
}

// The CTalkRewardData dtor (0x141b221d0) is implicit: the exe one has no vftable store.

// @0x141b1dbd0
void UITalkManager::CTalkRewardData::FUN_141b1dbd0()
{
    m_items.RemoveAll();
    m_nMerat = 0;
    m_nMeso = 0;
    m_nExp = 0;
    m_nAffinity = 0;
    m_nJackpot = 0;
}

// @0x141b1dc40
UITalkManager::UITalkManager()
    : m_nTalking(0), m_nNpcId(0), m_spScript(0), m_48(0), m_nLastTick(0), m_nSound(0),
      m_nSpecialNpc(0), m_nPending(0), m_nSubMode(0)
{
}

// @0x141b1dd30
UITalkManager::~UITalkManager()
{
    m_spScript = 0;
}

// @0x141b223d0
const void* UITalkManager::vfunc_1()
{
    return &s_talkManagerRegistrar;
}

// @0x141b1ddd0
void UITalkManager::OnTalkPacket(CInPacket& in)
{
    int nMode = in.ReadUInt8();
    if (nMode == 1)
    {
        int nNpcId = in.ReadInt32();
        m_nFlags = in.ReadUInt8();
        m_nParam = in.ReadInt32();
        m_nPage = in.ReadInt32();
        m_nSound = in.ReadInt32();
        FUN_141b1ff80(nNpcId);
    }
    else if (nMode == 8)
    {
        m_nFlags = in.ReadUInt8();
        int nId = in.ReadInt32();
        m_nParam = in.ReadInt32();
        m_nPage = in.ReadInt32();
        m_nSound = in.ReadInt32();
        FUN_141b217b0();
        FUN_141b217e0(nId);
        ReloadScript();
    }
    else if (nMode == 9)
    {
        m_nFlags = in.ReadUInt8();
        m_nParam = in.ReadInt32();
        m_nPage = in.ReadInt32();
        m_nSound = in.ReadInt32();
        FUN_141b217b0();
        ReloadScript();
    }
    else if (nMode == 2)
    {
        m_nFlags = in.ReadUInt8();
        int nId = in.ReadInt32();
        m_nParam = in.ReadInt32();
        m_nPage = in.ReadInt32();
        m_nSound = in.ReadInt32();
        FUN_141b217b0();
        FUN_141b217e0(nId);
        FUN_141b204d0();
    }
    else if (nMode == 3)
    {
        m_nSubMode = (unsigned char)in.ReadUInt8();
        switch (m_nSubMode)
        {
        case 1: SetNpcNameTag(in); break;
        case 3: FUN_141b1e8a0(in); break;
        case 4: FUN_141b1ea90(in); break;
        case 5: OnRewardItems(in); break;
        case 6: OnRewardMerat(in); break;
        case 7: OnRewardMeso(in); break;
        case 8: OnRewardExp(in); break;
        case 9: OnRewardAffinity(in); break;
        case 10: PlayCutSceneMovie(in); break;
        }
    }
    else if (nMode == 0)
    {
        m_nTalking = 0;
        ResetTalk();
    }
    else if (nMode == 4)
    {
        CStringW strScript = in.ReadUnicodeString();
        CString strSound = in.ReadUnicodeStringA();
        CString strIllust = in.ReadUnicodeStringA();
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(strScript);
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strScript);
        UITalkCinematic* pUi = FindTalkCinematic(0x4e40);
        if (pUi != 0)
            pUi->ModifyScript(strScript, strSound, strIllust);
    }
    else if (nMode == 10)
    {
        unsigned nNpcId = in.ReadInt32();
        int nSub = (unsigned short)in.ReadInt16();
        MS2Ptr<CTalkScript> spScript(new CTalkScript(in));
        if (nSub == 1)
        {
            if (spScript->m_contents.GetCount() == 0)
                return;
            Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(nNpcId));
            if (pNpc != 0)
            {
                MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = pNpc->vfunc_85();
                if (spBalloon.get() != 0)
                    spBalloon->FUN_1418fb6d0();
                pNpc->ShowChatBalloon(CStringW(reinterpret_cast<MS2Ptr<CScriptContent>&>(spScript->m_contents[0])->m_name));
            }
        }
        else
        {
            m_nFlags = 0x10;
            m_nParam = -1;
            m_nPage = 0;
            m_spScript = spScript;
            m_nSpecialNpc = spScript->m_npcId;
            m_nSound = FUN_141b21d70();
            if (GetTalking() == 0)
                FUN_141b200d0(nNpcId, m_spScript.get());
            else
                ShowCurrentPage();
        }
    }
}

// @0x141b1e8a0
void UITalkManager::FUN_141b1e8a0(CInPacket& in)
{
    int nValue = in.ReadInt32();
    UISwfEntity* pEntity = ((UISwfEntity*)((GFxSceneService*)CUserMail::GetGFxSceneService())->FUN_1422b9e20(0x620001f));
    if (pEntity != 0)
    {
        UIMsg kMsg;
        kMsg.AddString("moveMyPC");
        kMsg.AddInt(nValue);
        kMsg.AddUInt(TSingleton<UITalkManager>::GetInstance()->GetNpcId());
        pEntity->OnMessage(0, reinterpret_cast<UIMsg*>(&kMsg));
    }
}

// @0x141b1e990
void UITalkManager::SetNpcNameTag(CInPacket& in)
{
    CString strName = in.ReadUnicodeStringA();
    Unk_TcNpc* pNpc = GetTalkNpc();
    if (pNpc != 0)
    {
        MS2Ptr<Unk_PCBaseComp_a88> spTag = pNpc->vfunc_83();
        if (spTag.get() != 0)
        {
            spTag->FUN_14192f8b0(2);
            spTag->FUN_14192f8d0(strName);
            spTag->vfunc_2();
        }
    }
}

// @0x141b1ea90
void UITalkManager::FUN_141b1ea90(CInPacket& in)
{
    CString strDialog = in.ReadUnicodeStringA();
    CString strArg = in.ReadUnicodeStringA();
    FUN_141b1eb90(strDialog, strArg);
}

// @0x141b1eb90
void UITalkManager::FUN_141b1eb90(CString strDialog, CString strArg)
{
    if (strDialog.CompareNoCase("JobChangeDialog") == 0)
    {
        int nJob = atoi(strArg);
        if (((const MS2Ptr<JobData>&)TSingleton<JobTable>::GetInstance()->GetJobData(nJob)).IsNull())
            return;
        void* pDlg = ((void*)FindJobChangeDialog(0x4e7c));
        if (pDlg != 0)
            ((class UIJobChangeDialog*)(void*)(pDlg))->FUN_1419dc510(nJob);
        OpenOrQueueDialog(strDialog);
    }
    else if (strDialog.CompareNoCase("RouletteDialog") == 0)
    {
        Unk_TcInt kValue;
        kValue.m_n = atoi(strArg);
        COutPacket packet(static_cast<int>(SendOp::BonusGame), 0);
        packet.WriteUInt8(0);
        FUN_1401fcd50((unsigned char*)&kValue, packet);
        FUN_140710590(packet);
    }
    else if (strDialog.CompareNoCase("OpenGambleDialog") == 0)
    {
        OpenOrQueueDialog("GambleDialog");
    }
    else if (strDialog.CompareNoCase("StartGambleDialog") == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Gamble), 0);
        packet.WriteUInt8(0);
        FUN_140710590(packet);
    }
    else if (strDialog.CompareNoCase("CloseGambleDialog") == 0)
    {
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e98);
    }
    else if (strDialog.CompareNoCase("OpenMaidDialog") == 0)
    {
        Unk_TcNpc* pNpc = GetTalkNpc();
        if (pNpc != 0 && pNpc->vfunc_128() != 0)
        {
            OpenOrQueueDialog("MaidDialog");
            void* pDlg = ((void*)CUserMaidManager::GetMaidDialog(0x4e9d));
            if (pDlg != 0)
                ((UIMaidDialog*)pDlg)->SetMaid(((class GameObject*)(class PCBase*)(pNpc))->GetObjectId(), pNpc->GetMaidUid());
        }
    }
    else if (strDialog.CompareNoCase("CloseMaidDialog") == 0)
    {
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e9d);
    }
    else if (strDialog.CompareNoCase("OpenManufactureDialog") == 0)
    {
        Unk_TcNpc* pNpc = GetTalkNpc();
        if (pNpc != 0 && pNpc->vfunc_128() != 0)
        {
            OpenOrQueueDialog("ManufactureDialog");
            void* pDlg = ((void*)CManufactureManager::GetManufactureDialog(0x4ec0));
            if (pDlg != 0)
                ((UIManufactureDialog*)pDlg)->SetNpcAndManufactureId(((class GameObject*)(class PCBase*)(pNpc))->GetObjectId(), pNpc->GetMaidUid());
        }
    }
    else if (strDialog.CompareNoCase("CloseManufactureDialog") == 0)
    {
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4ec0);
    }
    else if (strDialog.CompareNoCase("BeautyShopDialog") == 0)
    {
        OpenBeautyShopDialog(strArg);
    }
    else if (strDialog.CompareNoCase("BeautyStyleDialog") == 0)
    {
        OpenBeautyStyleDialog(strArg);
    }
    else if (strDialog.CompareNoCase("ItemEnchantDialog") == 0)
    {
        void* pDlg = GetItemEnchantDialog(0x4e92);
        if (pDlg != 0)
            ((UIItemEnchantDialog*)pDlg)->SetModeByName(strArg);
        OpenOrQueueDialog(strDialog);
    }
    else if (strDialog.CompareNoCase("AttendGiftDialog") == 0)
    {
        void* pDlg = FindDTDialog<UIAttendGiftDialog>(0x4eb8);
        if (pDlg != 0)
        {
            if (((class UIDialog*)(void*)(pDlg))->FUN_141924630() != 0)
                ((class UIDialog*)(void*)(pDlg))->vfunc_68();
            if (!strArg.IsEmpty())
            {
                int nEvent = ParseUInt(strArg);
                if (((class UIAttendGiftDialog*)(void*)(pDlg))->SelectRequestedEvent(nEvent))
                    ((class UIDialog*)(void*)(pDlg))->FUN_141924680();
                else
                    SendNpcTalkMode0();
            }
            else
            {
                ((class UIDialog*)(void*)(pDlg))->FUN_141924680();
            }
        }
    }
    else if (strDialog.CompareNoCase("ItemTreasureMapDialog") == 0)
    {
        UIItemTreasureMapDialog* pDlg = FindItemTreasureMapDialog(0x4f5b);
        if (pDlg != 0)
            pDlg->FUN_140c55b50(strArg);
        OpenOrQueueDialog(strDialog);
    }
    else if (strDialog.CompareNoCase("WeddingHallReservationDialog") == 0)
    {
        void* pDlg = ((void*)GetWeddingHallReservationDialog(0x4f8d));
        if (pDlg != 0)
        {
            MS2Ptr<WeddingPackage> kRef = TSingleton<WeddingTable>::GetInstance()->FindPackageByPlanner(GetTalkNpcId());
            if (((Unk_ThHallRef*)&(kRef))->FUN_141847330() != 0)
            {
                ((class UIWeddingHallReservationDialog*)(void*)(pDlg))->SetMode(strArg);
                ((class UIWeddingHallReservationDialog*)(void*)(pDlg))->SetPackage(((Unk_TcWedding*)kRef.operator->())->m_18);
                OpenOrQueueDialog(strDialog);
            }
        }
    }
    else
    {
        OpenOrQueueDialog(strDialog);
    }
}

// @0x141b1f350
void UITalkManager::OnRewardItems(CInPacket& in)
{
    unsigned __int64 nCount = (unsigned)in.ReadInt32();
    for (unsigned __int64 i = 0; i < nCount; i++)
    {
        int nItemId = in.ReadInt32();
        unsigned nRarity = (unsigned char)in.ReadUInt8();
        int nAmount = in.ReadInt32();
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->ReadFromStream(in);
            spItem->SetCount(nAmount);
            if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->IsDialogOpen((eUIClassID)(0x4e98))) != 0)
                m_reward.m_items.Add(spItem);
            else if (spItem->IsMeso() != 0)
                m_reward.m_nMeso += nAmount;
            else
                m_reward.m_items.Add(spItem);
            if (spItem->IsCurrency() == 0)
            {
                void* pHud = ((void*)FindRewardNotify(0x4e5d));
                if (pHud != 0)
                    reinterpret_cast<UIRewardNotify*>(pHud)->FUN_141abfa10(MS2Ptr<CItem>(spItem));
            }
        }
    }
}

// @0x141b1f620
void UITalkManager::OnRewardMerat(CInPacket& in)
{
    __int64 nValue = in.ReadInt64();
    m_reward.m_nMerat += nValue;
    void* pHud = ((void*)FindRewardNotify(0x4e5d));
    if (pHud != 0)
        ((UIRewardNotify*)pHud)->FUN_141abf230(nValue, 0);
}

// @0x141b1f6b0
void UITalkManager::OnRewardMeso(CInPacket& in)
{
    __int64 nValue = in.ReadInt64();
    m_reward.m_nMeso += nValue;
    void* pHud = ((void*)FindRewardNotify(0x4e5d));
    if (pHud != 0)
        ((UIRewardNotify*)pHud)->FUN_141abf450(nValue, 0);
}

// @0x141b1f740
void UITalkManager::OnRewardExp(CInPacket& in)
{
    int nExp = in.ReadInt32();
    m_reward.m_nExp += nExp;
}

// @0x141b1f7a0
void UITalkManager::OnRewardAffinity(CInPacket& in)
{
    int nValue = in.ReadInt32();
    int bJackpot = in.ReadUInt8();
    m_reward.m_nAffinity += nValue;
    if (bJackpot != 0)
        m_reward.m_nJackpot = 1;
}

// @0x141b1f840
void UITalkManager::PlayCutSceneMovie(CInPacket& in)
{
    unsigned nValue = in.ReadInt32();
    CStringW strText = in.ReadUnicodeString();
    void* pDlg = ((void*)FindCutSceneMovie(0x4e7e));
    if (pDlg != 0)
        ((UICutSceneMovie*)pDlg)->PlayScene(nValue, FUN_14016a600(strText, 0));
}

// @0x141b1f920
void UITalkManager::OpenBeautyShopDialog(const CString& strArgs)
{
    ATL::CAtlArray<CString> kParts;
    Unk_SplitA(const_cast<CString&>(strArgs), &kParts, ",");
    CString strKind = kParts[0];
    CString strMode;
    if (kParts.GetCount() > 1)
        strMode = kParts[1];
    unsigned nDialog = (unsigned)GetDialogIdByKind(strKind, strMode);
    unsigned nType = (unsigned)GetDialogType(nDialog, strMode, strKind);
    OpenTalkDialog(nType, nDialog);
}

// @0x141b1fa20
void UITalkManager::OpenBeautyStyleDialog(const CString& strArgs)
{
    int nId = 0x4f03;
    int nType = 4;
    OpenTalkDialog(nType, nId);
}

// @0x141b1fa60
bool UITalkManager::HasLocalPlayer()
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return false;
    return true;
}

// @0x141b1faa0
void UITalkManager::OpenTalkDialog(int nMode, int nDialogId)
{
    MS2Ptr<UITalkCinematic> spUi(FindTalkCinematic(0x4e40));
    if (spUi == 0)
        return;
    unsigned nNpc = (unsigned)TSingleton<UITalkManager>::GetInstance()->GetTalkNpcId();
    spUi->SetDefaultKeyGroup();
    if (nDialogId == 0x4e24 && !HasLocalPlayer())
    {
        SendNpcTalkMode0();
        return;
    }
    if (nDialogId == 0x4eee)
    {
        void* pDlg = Unk_SSGGetDialog<UIBeautyShopDialog>(0x4eee);
        if (pDlg != 0)
            ((class UIBeautyShopDialog*)(void*)(pDlg))->SetPalette(nNpc);
    }
    {
        MS2Ptr<CNpcData> kRec = FindNpcData(nNpc);
        if (((void*)kRec.get()) != 0)
        {
            UISwfEntity* pEntity = ((UISwfEntity*)((GFxSceneService*)CUserMail::GetGFxSceneService())->FUN_1422b9e20(0x620001f));
            if (pEntity != 0)
            {
                UIMsg kMsg;
                    kMsg.AddString("openDialog");
                kMsg.AddInt(nDialogId);
                pEntity->OnMessage(0, reinterpret_cast<UIMsg*>(&kMsg));
            }
            if (nMode != 0)
            {
                COutPacket packet(static_cast<int>(SendOp::Beauty), 0);
                packet.WriteUInt8(0);
                packet.WriteInt32(nNpc);
                packet.WriteUInt8((unsigned char)nMode);
                FUN_140710590(packet);
            }
        }
    }
    spUi->SetKeyGroup(0x620001f);
    SendNpcTalkMode0();
}

// @0x141b1fcf0
void UITalkManager::FUN_141b1fcf0(unsigned nNpcId)
{
    if (GetTalking() != 0)
        return;
    if (IsTalkIntervalElapsed() == 0)
        return;
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC != 0)
    {
        int nState = pPC->GetCurStateId();
        if ((nState == 1 || nState == 0xb || nState == 0xf || nState == 0x21 || nState == 2) == 0)
            return;
    }
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(nNpcId));
    if (pNpc == 0)
        return;
    int nUiId = pNpc->GetTalkUiId();
    if (nUiId != 0)
    {
        if (TSingleton<CUIService>::GetInstance()->FUN_141adc7f0((eUIClassID)nUiId) == 0)
            return;
    }
    if (nUiId == 0x4e3b)
        TSingleton<CUIService>::GetInstance()->RequestCloseDialog((eUIClassID)0x4e3b);
    reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc170();
    if (FUN_141b218b0(pNpc) != 0)
        return;
    if (TSingleton<CMouseController>::GetInstance()->HasMode() != 0)
        TSingleton<CMouseController>::GetInstance()->ResetToIdle();
    COutPacket packet(static_cast<int>(SendOp::NpcTalk), 0);
    packet.WriteUInt8(1);
    packet.WriteInt32(nNpcId);
    FUN_140710590(packet);
}

// @0x141b1feb0
void UITalkManager::SendNpcTalkMode0()
{
    if (GetTalking() == 0)
        return;
    m_nTalking = 0;
    m_nPending = 0;
    if (FUN_141b213c0() == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::NpcTalk), 0);
        packet.WriteUInt8(0);
        FUN_140710590(packet);
    }
    ResetTalk();
    ChromaSDK::GetChromaManager()->SetState(0);
}

// @0x141b1ff80
void UITalkManager::FUN_141b1ff80(unsigned nNpcId)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(nNpcId));
    if (pPC != 0 && pNpc != 0)
    {
        m_nTalking = 1;
        m_nNpcId = nNpcId;
        pPC->vfunc_94(nNpcId);
        pNpc->vfunc_94(((class GameObject*)(class PCBase*)(pPC))->GetObjectId());
        reinterpret_cast<Unk_ScriptPtr<CTalkScript>&>(m_spScript) = FindTalkScript();
        if (m_spScript.get() != 0)
        {
            ((GFxSceneService*)CUserMail::GetGFxSceneService())->SetSubScene(0x6200031);
        }
        else
        {
            if (pNpc->GetTalkUiId() != 0)
                m_48 = pNpc->OpenTalkUi();
        }
        pNpc->PlayStartSound();
    }
}

// @0x141b200d0
void UITalkManager::FUN_141b200d0(unsigned nNpcId, CTalkScript* pScript)
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(nNpcId));
    if (pPC != 0 && pNpc != 0)
    {
        m_nTalking = 1;
        m_nNpcId = nNpcId;
        pPC->vfunc_94(nNpcId);
        pNpc->vfunc_94(((class GameObject*)(class PCBase*)(pPC))->GetObjectId());
        m_spScript.AssignRaw(pScript);
        if (m_spScript.get() != 0)
        {
            ((GFxSceneService*)CUserMail::GetGFxSceneService())->SetSubScene(0x6200031);
        }
        else
        {
            if (pNpc->GetTalkUiId() != 0)
                m_48 = pNpc->OpenTalkUi();
        }
        pNpc->PlayStartSound();
        ChromaSDK::GetChromaManager()->SetState(2);
    }
}

// @0x141b20210
void UITalkManager::ResetTalk()
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC != 0)
    {
        if (pPC->vfunc_85().get())
            pPC->vfunc_85()->vfunc_3();
        efd::SmartPointer<Ridee> kRide((Ridee*)(void*)((class PCBase*)(class PCBase*)(pPC))->GetRidee());
        if (((Ridee*)kRide ? true : false) && ((PCBase*)kRide.operator->())->GetCurStateId() == 0x16)
            pPC->vfunc_59(1, 0, 0, 0);
        else if (pPC->GetCurStateId() == 0x16)
            pPC->vfunc_59(1, 0, 0, 0);
        m_ids.Reset();
        UITalkCinematic* pUi = FindTalkCinematic(0x4e40);
        if (pUi != 0)
            pUi->FUN_141b1b8b0();
    }
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(m_nNpcId));
    if (pNpc != 0)
    {
        pNpc->PlayEndSound();
        pNpc->CloseTalkUi();
    }
    reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc2c0();
    m_nTalking = 0;
    m_nNpcId = 0;
    m_spScript = 0;
    m_48 = 0;
    m_nSpecialNpc = 0;
    m_nLastTick = GetTickCountMs2();
    m_reward.FUN_141b1dbd0();
    ChromaSDK::GetChromaManager()->SetState(0);
}

// @0x141b204d0
int UITalkManager::FUN_141b204d0()
{
    if (FUN_141b213c0() != 0)
    {
        FUN_141b215b0(1);
        return 1;
    }
    if (m_spScript.get() != 0 && m_spScript->Is88())
    {
    }
    else
    {
        reinterpret_cast<Unk_ScriptPtr<CTalkScript>&>(m_spScript) = FindTalkScript();
    }
    if (ShowCurrentPage() == 0)
    {
        SendNpcTalkMode0();
        return 0;
    }
    m_nPending = 0;
    Unk_TcNpc* pNpc = GetTalkNpc();
    bool bHasTag = pNpc != 0 && static_cast<bool>(pNpc->vfunc_83().get());
    if (bHasTag)
        pNpc->vfunc_83()->FUN_14192f9f0(m_nSubMode);
    return 1;
}

// @0x141b20700
void UITalkManager::ReloadScript()
{
    reinterpret_cast<Unk_ScriptPtr<CTalkScript>&>(m_spScript) = FindTalkScript();
    if (m_spScript.get() != 0)
        ((GFxSceneService*)CUserMail::GetGFxSceneService())->SetSubScene(0x6200031);
}

// @0x141b20790
void UITalkManager::ShowNpcMonologue(int nNpcId, int nFriendly)
{
    if (m_nNpcId == nNpcId)
        return;
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(nNpcId));
    if (pNpc == 0)
        return;
    int nKind = 9;
    bool bAffinity = pNpc->vfunc_128() != 0 && (((void*)((const MS2Ptr<CMaid>&)(pNpc->GetMaid())).get()) ? true : false);
    if (bAffinity)
    {
        if (pNpc->GetMaid()->IsExpired())
            nKind = 8;
        else
            nKind = 7;
    }
    Unk_ScriptPtr<CTalkScript> spScript = FUN_140856fa0(((class CNpc*)(class PCBase*)(pNpc))->GetNpcId(), nKind);
    if ((spScript.get() ? true : false) && spScript->m_contents.GetCount() > 0)
    {
        pNpc->ShowChatBalloon(CStringW(reinterpret_cast<MS2Ptr<CScriptContent>&>(spScript->m_contents[0])->m_name));
        if (TSingleton<UITalkManager>::GetInstance()->GetTalking() == 0 && reinterpret_cast<MS2Ptr<CScriptContent>&>(spScript->m_contents[0])->m_unk20.GetLength() != 0)
            TSingleton<CEffectService>::GetInstance()->PlayVoiceAt(CString(reinterpret_cast<MS2Ptr<CScriptContent>&>(spScript->m_contents[0])->m_unk20), pNpc->vfunc_18());
    }
}

// @0x141b20ac0
int UITalkManager::FUN_141b20ac0()
{
    if (GetTalking() == 0)
        return 0;
    return 0;
}

// @0x141b20af0
void UITalkManager::EndTalkIfNpcGone()
{
    if (FUN_141b213c0() != 0)
        return;
    if (GetTalking() != 0)
    {
        MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
        Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(m_nNpcId));
        if (pPC == 0 || pNpc == 0)
        {
            SendNpcTalkMode0();
        }
        else if (pNpc->IsInTalkRange() == 0)
        {
            SendNpcTalkMode0();
        }
        else if (((class CGuideManager*)FUN_1409331e0())->IsRestricted(2) != 0)
        {
            SendNpcTalkMode0();
        }
    }
}

// @0x141b20bb0
int UITalkManager::ShowCurrentPage()
{
    Unk_TcNpc* pNpc = GetTalkNpc();
    if (pNpc == 0)
        return 0;
    UITalkCinematic* pUi = FindTalkCinematic(0x4e40);
    if (pUi == 0)
        return 0;
    if (m_spScript.get() != 0)
    {
        if (m_nPage < (int)m_spScript->m_contents.GetCount())
        {
            MS2Ptr<CScriptContent> spContent = reinterpret_cast<MS2Ptr<CScriptContent>&>(m_spScript->m_contents[m_nPage]);
            int bLast = m_nPage == (int)m_spScript->m_contents.GetCount() - 1;
            if (bLast)
                bLast = reinterpret_cast<ATL::CAtlArray<int>&>(m_spScript->m_gotoConditionTalkIds).GetCount() == 0;
            return pUi->ShowPage(GetCinematicContent(MS2Ptr<CScriptContent>(spContent)), bLast);
        }
    }
    else
    {
        if (pNpc->GetTalkUiId() == 0)
            return 0;
        pNpc->OpenTalkUi();
        pUi->FUN_141b1b8b0();
    }
    return 1;
}

// @0x141b20db0
void UITalkManager::SendNpcTalkMode2(unsigned nNpcId)
{
    if (FUN_141b213c0() != 0)
    {
        FUN_141b215b0(0);
    }
    else if (m_nPending == 0)
    {
        m_nPending = 1;
        m_nSubMode = 0;
        COutPacket packet(static_cast<int>(SendOp::NpcTalk), 0);
        packet.WriteUInt8(2);
        packet.WriteInt32(nNpcId);
        FUN_140710590(packet);
    }
}

// @0x141b20e60
void UITalkManager::OpenScript(MS2Ptr<CTalkScript> spScript, int nId, int nPage)
{
    m_spScript = spScript;
    m_nParam = nId;
    m_nPage = nPage;
    ShowCurrentPage();
}

// @0x141b20ed0
CStringW UITalkManager::GetCurrentPageName()
{
    if (m_spScript.IsNull())
        return CStringW(L"");
    if (m_nPage >= (int)m_spScript->m_contents.GetCount())
        return CStringW(L"");
    return CStringW(reinterpret_cast<MS2Ptr<CScriptContent>&>(m_spScript->m_contents[m_nPage])->m_name);
}

// @0x141b20fe0
Unk_ScriptPtr<CTalkScript> UITalkManager::GetScript()
{
    return reinterpret_cast<Unk_ScriptPtr<CTalkScript>&>(m_spScript);
}

// @0x141b21030
MS2Ptr<CCinematicContent> UITalkManager::GetCurrentContent()
{
    if (m_spScript.IsNull())
        return MS2Ptr<CCinematicContent>(0);
    if (m_nPage >= (int)m_spScript->m_contents.GetCount())
        return MS2Ptr<CCinematicContent>(0);
    MS2Ptr<CScriptContent> spContent = reinterpret_cast<MS2Ptr<CScriptContent>&>(m_spScript->m_contents[m_nPage]);
    return MS2Ptr<CCinematicContent>(GetCinematicContent(MS2Ptr<CScriptContent>(spContent)));
}

// @0x141b21190
void UITalkManager::SetTalkState(int nFlags, int nParam, int nPage)
{
    m_nFlags = (unsigned char)nFlags;
    m_nParam = nParam;
    m_nPage = nPage;
}

// @0x141b211d0
int UITalkManager::IsTalkIntervalElapsed()
{
    if (GetTickCountMs2() - m_nLastTick < *reinterpret_cast<unsigned*>(reinterpret_cast<Common::Constants::Value<int>*>(reinterpret_cast<char*>(((class Unk_TcSettings*)GetClientConstants())) + 0x3730)->Get()))
        return 0;
    return 1;
}

// @0x141b21220
int UITalkManager::GetTalking()
{
    return m_nTalking;
}

// @0x141b21240
int UITalkManager::IsTalkingWith(int nNpcId)
{
    if (GetTalking() == 0)
        return 0;
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return 0;
    if (nNpcId == (int)((class GameObject*)(class PCBase*)(pPC))->GetObjectId())
        return 1;
    if (nNpcId == m_nNpcId)
        return 1;
    return 0;
}

// @0x141b212c0
unsigned UITalkManager::GetNpcId()
{
    if (GetTalking() == 0)
        return 0;
    return m_nNpcId;
}

// @0x141b212f0
int UITalkManager::GetTalkNpcId()
{
    Unk_TcNpc* pNpc = GetTalkNpc();
    if (pNpc != 0)
        return ((class CNpc*)(class PCBase*)(pNpc))->GetNpcId();
    if (FUN_141b213c0() != 0)
        return m_nSpecialNpc;
    return 0;
}

// @0x141b21350
Unk_TcNpc* UITalkManager::GetTalkNpc()
{
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(GetNpcId()));
    return pNpc;
}

// @0x141b21390
void UITalkManager::FUN_141b21390()
{
    m_nTalking = 0;
    m_nSpecialNpc = 0;
}

// @0x141b213c0
int UITalkManager::FUN_141b213c0()
{
    if ((unsigned)m_nSpecialNpc > 0)
        return 1;
    return m_nFlags & 0x10;
}

// @0x141b213f0
unsigned UITalkManager::BeginTalkWithoutNpc(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound)
{
    if (GetTalking() != 0)
    {
        ShowSystemNotice(GetStringByKey(CStringW(L"s_error_talk_already_talking")), 1, 1);
        return 0;
    }
    if (spScript.IsNull())
        return 0;
    m_nTalking = 1;
    m_nSpecialNpc = nSpecialNpc;
    m_spScript = spScript;
    SetTalkState(nFlags | 0x10, spScript->m_id, 0);
    if (nSound != 0)
        m_nSound = nSound;
    else
        m_nSound = FUN_141b21d70();
    ((GFxSceneService*)CUserMail::GetGFxSceneService())->SetSubScene(0x6200031);
    return 1;
}

// @0x141b215b0
void UITalkManager::FUN_141b215b0(int bSamePage)
{
    UITalkCinematic* pUi = FindTalkCinematic(0x4e40);
    if (pUi == 0)
        return;
    if (bSamePage == 0)
    {
        m_nPage++;
        m_nSound = FUN_141b21d70();
    }
    if (m_spScript.get() != 0)
    {
        if (m_nPage < (int)m_spScript->m_contents.GetCount())
        {
            MS2Ptr<CScriptContent> spContent = reinterpret_cast<MS2Ptr<CScriptContent>&>(m_spScript->m_contents[m_nPage]);
            int bLast = m_nPage == (int)m_spScript->m_contents.GetCount() - 1;
            if (bLast)
                bLast = reinterpret_cast<ATL::CAtlArray<int>&>(m_spScript->m_gotoConditionTalkIds).GetCount() == 0;
            pUi->ShowPage(GetCinematicContent(MS2Ptr<CScriptContent>(spContent)), bLast);
        }
        else
        {
            SendNpcTalkMode0();
        }
    }
}

// @0x141b217b0
void UITalkManager::FUN_141b217b0()
{
    m_ids.Reset();
}

// @0x141b217e0
void UITalkManager::FUN_141b217e0(unsigned nId)
{
    m_ids.m_ids.Add(nId);
}

// @0x141b21810
unsigned UITalkManager::GetIdAt(int nIndex)
{
    if (m_ids.m_ids.GetCount() <= (unsigned __int64)(__int64)nIndex)
        return 0;
    return m_ids.m_ids[nIndex];
}

// @0x141b21860
unsigned __int64 UITalkManager::FUN_141b21860()
{
    return m_ids.m_ids.GetCount();
}

// @0x141b21890
unsigned UITalkManager::FUN_141b21890()
{
    return m_48;
}

// @0x141b218b0
int UITalkManager::FUN_141b218b0(Unk_TcNpc* pNpc)
{
    if (pNpc == 0)
        return 0;
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return 0;
    if (pNpc->GetKind() == 0x23)
    {
        int nNotice = 0;
        {
            MS2Ptr<CEquipItem> kEquip = ((PC*)pPC)->FUN_141655e10(6);
            if ((CEquipItem*)kEquip != 0)
            {
                if (((void*)kEquip->GetItemData()) != 0
                    && ((class CItemData*)(void*)(kEquip->GetItemData()))->FUN_14053ec70()->FUN_1405471d0() != 0)
                    return 0;
                else if (((class PCGemEquip*)(void*)(((PC*)pPC)->GetGemEquip()))->IsSlotHidden(0) != 0)
                    nNotice = 0x83;
                else
                    nNotice = 0x82;
            }
            else
            {
                nNotice = 0x84;
            }
        }
        if (nNotice != 0)
            FUN_141275260(nNotice, 1, 1);
        return 1;
    }
    return 0;
}

// @0x141b21a10
Unk_TalkIdList* UITalkManager::GetOpenedDialogs()
{
    return &m_openedDialogs;
}

// @0x141b21a30
void UITalkManager::OpenPendingDialogs()
{
    if (m_openedDialogs.GetCount() != 0)
    {
        for (unsigned i = 0; i < m_openedDialogs.GetCount(); i++)
            (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(m_openedDialogs[i])));
        m_openedDialogs.RemoveAll();
    }
}

// @0x141b21ae0
void UITalkManager::OpenOrQueueDialog(const CString& strDialog)
{
    UIDialog* pDlg = Unk_GaGetUIByName<UIDialog>(strDialog);
    if (pDlg == 0)
        return;
    UITalkCinematic* pUi = FindTalkCinematic(0x4e40);
    if (pUi != 0 && pUi->GetLoaded() != 0)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(pDlg->vfunc_48())));
    else
        m_openedDialogs.Add(pDlg->vfunc_48());
}

// @0x141b21b90
Unk_ScriptPtr<CTalkScript> UITalkManager::FindTalkScript()
{
    MyPC* pPC = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (pPC == 0)
        return Unk_ScriptPtr<CTalkScript>(0);
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcNpc*>(WorldService::GetInstance()->FindNpcById(m_nNpcId));
    if (pNpc == 0)
        return Unk_ScriptPtr<CTalkScript>(0);
    if ((m_nFlags & 8) != 0)
        return GetNpcPickTalk(((class CNpc*)(class PCBase*)(pNpc))->GetNpcId(), 0);
    else if ((m_nFlags & 4) != 0)
        return FindQuestTalk(m_ids.m_ids[0], m_nParam);
    else if (FUN_140855cd0(m_nFlags) != 0)
        return FUN_140856820(((class CNpc*)(class PCBase*)(pNpc))->GetNpcId(), m_nParam);
    else if ((m_nFlags & 1) != 0)
        return GetNpcPickTalk(((class CNpc*)(class PCBase*)(pNpc))->GetNpcId(), 1);
    return Unk_ScriptPtr<CTalkScript>(0);
}

// @0x141b21d70
unsigned UITalkManager::FUN_141b21d70()
{
    return GetTalkButtonSet(GetScript(), m_nFlags, m_nSpecialNpc, m_nPage);
}

// @0x141b21de0
CCinematicContent* GetCinematicContent(MS2Ptr<CScriptContent> spContent)
{
    if (spContent.IsNull())
        return 0;
    if (spContent->vfunc_1() != 0)
        return 0;
    return reinterpret_cast<CCinematicContent*>(reinterpret_cast<Unk_TalkContentPtr<CScriptContent>*>(&spContent)->get());
}

// @0x141b21e90
unsigned __int64 GetDialogIdByKind(const CString& strKind, const CString& strMode)
{
    if (strKind.CompareNoCase("hair") == 0 || strKind.CompareNoCase("makeUp") == 0
        || strKind.CompareNoCase("face") == 0 || strKind.CompareNoCase("skin") == 0)
    {
        if (strMode.CompareNoCase("styleSave") == 0)
            return 0x4f03;
        return 0x4eee;
    }
    if (strKind.CompareNoCase("itemColor") == 0)
        return 0x4e23;
    if (strKind.CompareNoCase("mirror") == 0)
        return 0x4e24;
    return 0;
}

// @0x141b21f70
unsigned __int64 GetDialogType(int nDialog, const CString& strMode, const CString& strKind)
{
    if (nDialog == 0x4e23)
        return 3;
    else if (nDialog == 0x4eee || nDialog == 0x4f03)
    {
        if (strMode.IsEmpty())
        {
            if (strKind.CompareNoCase("skin") == 0)
                return 3;
        }
        else
        {
            if (strMode.CompareNoCase("random") == 0)
                return 2;
            if (strMode.CompareNoCase("styleSave") == 0)
                return 4;
        }
        return 1;
    }
    else if (nDialog == 0x4e24)
        return 3;
    return 0;
}

// @0x141b22040
UIItemTreasureMapDialog* FindItemTreasureMapDialog(unsigned nUiId)
{
    if (reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spDialog = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (spDialog.get() != 0)
            return dynamic_cast<UIItemTreasureMapDialog*>((UIObject*)spDialog);
    }
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc2bc0-0x142cc2d30 .text$yd
