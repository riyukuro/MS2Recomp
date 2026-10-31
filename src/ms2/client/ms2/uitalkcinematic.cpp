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

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics (init order: the shared header's four, the file's two, then a second shared header's) ----

static CString s_strSortTypeNamesLike[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_nextKey = "cinematic_nextkey";
static Unk_WireframeRegistrar s_talkManagerRegistrar("UITalkManager", 0);
static CString s_strSortTypeNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNamesLike2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of exe objects (Unk_ names and member names are invented) ----

class UINpcPreviewDialog : public UIObject
{
public:
    int FUN_141b1d820() { return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x178); }   // 0x141b1d820 the npc id
};

class Unk_TcEntity : public ASGameEntity
{
public:
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const CString& strCall);              // 13 the "hide" call
};

UINpcPreviewDialog* FUN_141b1d4f0(unsigned nUiId);              // the open npc preview dialog
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int a, int nIcon, int nFlags);


class Unk_TcWorld
{
public:
    MyPC* FUN_141bd0cc0();                                      // local player
    Unk_TcNpc* FUN_141bd1320(unsigned nActorId);                // actor by id
};

class Unk_TcUi : public CUIService
{
public:
    int FUN_141adc940(int nId);                                 // is open
    int FUN_141adc890(int nId);
    int FUN_141adc7f0(int nId);
    void FUN_141adc690(int nId);
    void FUN_141adc5d0(int nId);                                // open
    void FUN_141adc530(int nId);                                // close
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                    // lookup
};

class Unk_TcBgm { public: void FUN_1422b9fd0(int nGroup); UISwfEntity* FUN_1422b9e20(int nGroup); };
Unk_TcBgm* FUN_1408e57f0();
UISwfEntityManager* FUN_140b632f0();
class Unk_140a94350
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_140a94350* FUN_140a94350();
GFxManager* FUN_14025e7a0();
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
class Unk_AkoCutscene   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoCutscene* GetInstance();
};
UITalkCinematic* FUN_140a7b2b0(int nId);

class Unk_TcSettings { public: char m_pad[0xe0f8]; };
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
unsigned* FUN_1401d7c10(void* pOption);                         // the option value
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14036d570(int);
};
void* FUN_1409a8b10();
class Unk_TcOpt { public: char m_pad[6]; unsigned char m_6; };
class Unk_PetClientSettings   // C3: member view for the former free stand-ins
{
public:
    struct Unk_PetOptFlags* FUN_140b123b0();
};
unsigned FUN_141654700(MyPC* p);                                // job code
int FUN_141658e60(MyPC* p);                                     // gender
CString FUN_141492f60(const char* szFmt, const unsigned& nJob, const CString& strGender);

   // the illust path of an npc
class Unk_NpcTableCli* FUN_1406d6e90();   // C3: was FUN_1406d6e90
CString FUN_140cc2c70(const CString& strPath);                  // the full path of an illust
int FUN_141b70ea0(const CString& strPath);                      // the file exists
bool FUN_1401c0090(const CString& a, const CString& b);         // equal

void* FUN_1403ed280();                                          // the effect service
void FUN_1411a4f40(void* pEffects, CString strSound, const NiPoint3& kPos);
CStringW Unk_ArcWide(const wchar_t* psz, int n);                    // a wide string as a CString
void FUN_141276180(const CString& strSound, const CString& strArg);
void FUN_141415600(CString& strImage);                          // release a reward image

// The affinity record handle of an npc (16 bytes; destructor 0x14067e620).
void FUN_14067e620(void* p);
struct Unk_TcAff
{
    ~Unk_TcAff() { FUN_14067e620(this); }
    void* FUN_1409ee260() const;
    void* FUN_14067e8c0() const;
    void* m_0; void* m_8;
};
// The npc actor of the talk (PCBase slot 128 is the "has a display name" test).
class Unk_TcNpc : public PCBase
{
public:
    virtual void vfunc_124(); virtual void vfunc_125(); virtual void vfunc_126(); virtual void vfunc_127();
    virtual int vfunc_128();
    Unk_TcAff FUN_141093800();
    int FUN_141094170();
    unsigned FUN_141094200();
    void FUN_141093fa0();
    void FUN_141094050();
    void FUN_1410942c0();
    bool FUN_141094300();
    int FUN_1410937b0();
};

AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
AScript* FUN_140ba7c60(MS2Ptr<AScript>* p);
extern int DAT_143af62d4, DAT_143af62d8;

// ---- UITalkCinematic ----

// @0x141b19ea0
UITalkCinematic::UITalkCinematic()
{
    m_nLoaded = 0;
    m_nTalkComplete = 1;
    m_spContent = 0;
    m_spComponent = 0;
    FUN_141b1bfa0();
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
    FUN_1422dbf00(0x1c, 0, 0);
    FUN_140b632f0()->FUN_1422d4780(this, 4);
    FUN_140a94350()->vfunc_10(2);
}

// @0x141b1a0e0
void UITalkCinematic::vfunc_3()
{
    m_nLoaded = 0;
    FUN_1422dc080();
    FUN_140b632f0()->FUN_1422d4840(this, 4);
    FUN_140a94350()->vfunc_10(0);
}

// @0x141b1a140
void UITalkCinematic::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_141b1bfa0();
    if (((class UITalkManager*)Unk_AkoCutscene::GetInstance())->GetTalking() == 0)
    {
        FUN_1408e57f0()->FUN_1422b9fd0(m_nKeyGroup);
    }
    else if (((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
    {
        MS2Ptr<CCinematicContent> spContent = ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b21030();
        if (spContent.IsNull())
            return;
        ASObj page(2);
        FUN_141b1bfe0(page, spContent.get());
        FUN_1409ee290(&m_30)->Invoke("init", page);
    }
}

// @0x141b1a280
void UITalkCinematic::vfunc_26() { UIObject::vfunc_26(); }

// @0x141b1a2a0
void UITalkCinematic::vfunc_43()
{
    MS2Ptr<ASMovieClip> spClip(dynamic_cast<ASMovieClip*>(FUN_140ba7c60(&m_30)));
    if (spClip.get() != 0)
    {
        spClip->vfunc_2(5, 0, 0);
        float fScale = FUN_14025e7a0()->FUN_1422afec0(m_28);
        spClip->FUN_14190b490("setStageSize", DAT_143af62d4, DAT_143af62d8, fScale);
    }
}

// @0x141b1a3b0
int UITalkCinematic::vfunc_13()
{
    if (FUN_141b1c530())
        FUN_141b1bce0(0x493e2);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x49409, 0, 0))
        FUN_141b1bce0(1);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d840())
        FUN_141b1bce0(1);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0x79, 0, 0))
        FUN_141b1bce0(0x79);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x30d41, 0, 0))
        FUN_141b1bce0(0x79);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0x7e, 0, 0))
        FUN_141b1bce0(0x7e);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x30d42, 0, 0))
        FUN_141b1bce0(0x7e);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0x92, 0, 0))
        FUN_141b1bce0(0x79);
    else if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116d9c0(0x93, 0, 0))
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
        ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b204d0();
        ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b21a30();
        return 1;
    }
    else if (_stricmp("OnCloseComplete", szMethod) == 0)
    {
        FUN_1422dc080();
        FUN_1408e57f0()->FUN_1422b9fd0(m_nKeyGroup);
        FUN_141b1bfa0();
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
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8b10();
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
int UITalkCinematic::FUN_141b1a8e0(const CStringW& strScript, const CString& strSound, const CString& strIllust)
{
    if (m_spContent.IsNull())
        return 0;
    if (m_nLoaded == 0)
        return 0;
    if (m_nTalkComplete == 0)
        return 0;
    {
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
        if (spEntity.get() != 0)
        {
            ASObj page(2);
            if (strIllust.GetLength() != 0)
            {
                ASObj illust(2);
                illust.FUN_1407cba60("lNpc", FUN_141b1c670(strIllust));
                illust.FUN_1407cb9c0("lNpcSpeak", 1);
                page.FUN_1409eb270("illust", illust);
            }
            else
            {
                FUN_141b1bfe0(page, ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b21030().get());
            }
            page.FUN_1407cbb20("script", Unk_ArcWide(strScript, 0));
            spEntity->Invoke("modifyScript", page);
            if (strSound.GetLength() != 0)
            {
                Unk_TcNpc* pNpc = ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b21350();
                if (pNpc != 0)
                    FUN_1411a4f40(FUN_1403ed280(), CString(strSound), pNpc->vfunc_18());
            }
            return 1;
        }
    }
    return 0;
}

// @0x141b1ac40
void UITalkCinematic::FUN_141b1ac40(Unk_TalkItemList& rItems, const CStringW& strTitle, unsigned nMeso, unsigned nExp, __int64 nMerat)
{
    if (m_spContent.IsNull())
        return;
    if (m_nLoaded == 0)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() != 0)
    {
        ASObj page(2);
        page.FUN_1407cbb20("title", CStringW(strTitle));
        page.FUN_1407cb9c0("meso", nMeso);
        page.FUN_1407cb9c0("exp", nExp);
        page.FUN_1409c1180("merat", nMerat);
        for (unsigned __int64 i = 0; i < rItems.FUN_140720ca0(); i++)
        {
            MS2Ptr<CItem> spItem = rItems.FUN_140a69ee0(i);
            CString strImage;
            strImage.Format("%s_%d", (const char*)GetTypeName(), i);
            FUN_141415450(strImage, MS2Ptr<CItem>(spItem), 0, 0x11, 0x800);
            CString strKey;
            strKey.Format("reward%d", i + 1);
            FUN_141b1beb0(strImage);
            page.FUN_1407cba60(strKey, strImage);
        }
        spEntity->Invoke("modifyReward", page);
    }
}

// @0x141b1b000
void UITalkCinematic::FUN_141b1b000(Unk_TalkItemList& rItems, const CStringW& strTitle, const CStringW& strMood, const CStringW& strAffinityExp, int nJackpot)
{
    if (m_spContent.IsNull())
        return;
    if (m_nLoaded == 0)
        return;
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    if (rItems.FUN_140720ca0() == 0)
        return;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() != 0)
    {
        ASObj page(2);
        page.FUN_1407cbb20("title", CStringW(strTitle));
        page.FUN_1407cbb20("mood", CStringW(strMood));
        page.FUN_1407cbb20("affinityExp", CStringW(strAffinityExp));
        page.FUN_1407cb9c0("maidJackpot", nJackpot);
        for (unsigned __int64 i = 0; i < rItems.FUN_140720ca0(); i++)
        {
            MS2Ptr<CItem> spItem = rItems.FUN_140a69ee0(i);
            CString strImage;
            strImage.Format("%s_%d", (const char*)GetTypeName(), i);
            FUN_141415450(strImage, MS2Ptr<CItem>(spItem), 0, 0x11, 0x800);
            CString strKey;
            strKey.Format("reward%d", i + 1);
            FUN_141b1beb0(strImage);
            page.FUN_1407cba60(strKey, strImage);
        }
        spEntity->Invoke("modifyReward", page);
    }
}

// @0x141b1b440
int UITalkCinematic::FUN_141b1b440(CCinematicContent* pContent, int bLast)
{
    if (pContent == 0)
        return 0;
    if (m_nLoaded == 0)
        return 0;
    if (m_nTalkComplete == 0)
        return 0;
    {
        FUN_141b1bf00();
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
        if (spEntity.get() != 0)
        {
            m_spContent.AssignRaw(pContent);
            m_nTalkComplete = 0;
            m_spComponent = FUN_141b1c960(((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b1d810());
            if (m_spComponent.get() != 0)
            {
                ASObj page(2);
                FUN_141b1bfe0(page, pContent);
                FUN_141b1c4c0(page, pContent);
                m_spComponent->vfunc_4(m_spContent);
                m_spComponent->vfunc_5(page);
                spEntity->Invoke("setScript", page);
                if (m_spContent->m_unk20.GetLength() != 0)
                {
                    if (((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b213c0() != 0)
                    {
                        MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
                        if (pPC != 0)
                            FUN_1411a4f40(FUN_1403ed280(), CString(m_spContent->m_unk20), pPC->vfunc_18());
                    }
                    else
                    {
                        Unk_TcNpc* pNpc = ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b21350();
                        if (pNpc != 0)
                            FUN_1411a4f40(FUN_1403ed280(), CString(m_spContent->m_unk20), pNpc->vfunc_18());
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
    FUN_141b1bf00();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() != 0)
    {
        reinterpret_cast<Unk_TcEntity*>(spEntity.operator->())->vfunc_13("hide");
    }
    else
    {
        FUN_1422dc080();
        FUN_1408e57f0()->FUN_1422b9fd0(m_nKeyGroup);
        FUN_141b1bfa0();
    }
}

// @0x141b1b9f0
void UITalkCinematic::FUN_141b1b9f0()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() != 0)
    {
        spEntity->Invoke("onSkip");
        FUN_141276180(s_nextKey, "");
    }
}

// @0x141b1bad0
void UITalkCinematic::FUN_141b1bad0()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() != 0)
        spEntity->Invoke("onFocusUp");
}

// @0x141b1bb80
void UITalkCinematic::FUN_141b1bb80()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() != 0)
        spEntity->Invoke("onFocusDown");
}

// @0x141b1bc30
void UITalkCinematic::FUN_141b1bc30()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
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
        FUN_141b1b9f0();
        return;
    }
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    bool bBusy = !((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(FUN_1409ee290(&m_30)->Invoke("canNext")))->GetBool();
    if (bBusy)
        return;
    if (m_spComponent.get() != 0)
        m_spComponent->vfunc_2(nMsg);
}

// @0x141b1be50
void UITalkCinematic::FUN_141b1be50()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    FUN_1409ee290(&m_30)->Invoke("onFireworkEffect");
}

// @0x141b1beb0
void UITalkCinematic::FUN_141b1beb0(CString strImage)
{
    m_images.FUN_140165270(strImage);
}

// @0x141b1bf00
void UITalkCinematic::FUN_141b1bf00()
{
    for (unsigned __int64 i = 0; i < m_images.FUN_1401662c0(); i++)
        FUN_141415600(m_images.FUN_140164930(i));
    m_images.FUN_1402c2890();
}

// @0x141b1bf80
void UITalkCinematic::SetKeyGroup(unsigned nKeyGroup) { m_nKeyGroup = nKeyGroup; }

// @0x141b1bfa0
void UITalkCinematic::FUN_141b1bfa0() { m_nKeyGroup = 0x620001d; }

// @0x141b1bfc0
int UITalkCinematic::GetLoaded() { return m_nLoaded; }

// @0x141b1bfe0
void UITalkCinematic::FUN_141b1bfe0(ASObj& rPage, const CCinematicContent* pContent)
{
    ASObj illust(2);
    if (((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b213c0() != 0)
    {
        if (reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc940(0x4e89) == 0)
        {
            UINpcPreviewDialog* pPreview = FUN_141b1d4f0(0x4e89);
            if (pPreview != 0)
            {
                illust.FUN_1407cba60("lNpc", FUN_141b1c670(((class NpcDataTableCli*)FUN_1406d6e90())->GetIllust(pPreview->FUN_141b1d820())));
                illust.FUN_1407cb9c0("lNpcSpeak", 1);
                rPage.FUN_1409eb270("illust", illust);
                return;
            }
        }
    }
    if (pContent == 0)
        return;
    if (pContent->m_leftIllust.GetLength() != 0 || pContent->m_rightIllust.GetLength() != 0)
    {
        illust.FUN_1407cba60("lNpc", FUN_141b1c670(pContent->m_leftIllust));
        illust.FUN_1407cbbe0("lNpcSpeak", FUN_1401c0090(pContent->m_leftIllust, pContent->m_speakerIllust));
        illust.FUN_1407cba60("rNpc", FUN_141b1c670(pContent->m_rightIllust));
        illust.FUN_1407cbbe0("rNpcSpeak", FUN_1401c0090(pContent->m_rightIllust, pContent->m_speakerIllust));
        FUN_141b1c720(illust, pContent->m_myTalk);
    }
    else if (pContent->m_myTalk != 0)
    {
        FUN_141b1c720(illust, pContent->m_myTalk);
    }
    else if (pContent->m_unk28.GetLength() != 0)
    {
        illust.FUN_1407cba60("lNpc", FUN_141b1c670(pContent->m_unk28));
        illust.FUN_1407cb9c0("lNpcSpeak", 1);
    }
    else if (pContent->m_otherNpcTalk != 0)
    {
        illust.FUN_1407cba60("rNpc", FUN_141b1c5e0(pContent->m_otherNpcTalk));
        illust.FUN_1407cb9c0("rNpcSpeak", 1);
    }
    else if (pContent->m_speakerNpc == 0 || pContent->m_speakerNpc == (int)((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b212f0())
    {
        illust.FUN_1407cba60("lNpc", FUN_141b1c5e0((unsigned)((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b212f0()));
        illust.FUN_1407cb9c0("lNpcSpeak", 1);
    }
    rPage.FUN_1409eb270("illust", illust);
}

// @0x141b1c4c0
void UITalkCinematic::FUN_141b1c4c0(ASObj& rPage, const CCinematicContent* pContent)
{
    if (pContent == 0)
        return;
    rPage.FUN_1407cba60("imagePlate", CString(pContent->m_imagePlate));
}

// @0x141b1c530
int UITalkCinematic::FUN_141b1c530()
{
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dd30(0x493e2, 0, 0))
        return 1;
    if (((class CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dcb0(0x493e2, 0, 0))
    {
        if (m_nextKeyTimer.FUN_140268870(*FUN_1401d7c10(reinterpret_cast<char*>(((class Unk_TcSettings*)FUN_1401d3200())) + 0xe0f8)))
            return 1;
    }
    else
        m_nextKeyTimer.FUN_140268840();
    return 0;
}

// @0x141b1c5e0
CString UITalkCinematic::FUN_141b1c5e0(unsigned nNpcId)
{
    return FUN_141b1c670(((class NpcDataTableCli*)FUN_1406d6e90())->GetIllust(nNpcId));
}

// @0x141b1c670
CString UITalkCinematic::FUN_141b1c670(const CString& strName)
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
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    CString strIllust;
    if (((class CFeatureManager*)(void*)(((void*)FUN_140166410())))->FUN_14036d570(0x96) && ((class Unk_TcOpt*)((class Unk_PetClientSettings*)(void*)(FUN_1409a8b10()))->FUN_140b123b0())->m_6 != 0)
    {
        unsigned nJob = FUN_141654700(pPC);
        CString strGender(FUN_141658e60(pPC) == 1 ? "f" : "m");
        strIllust = FUN_141b1c670(FUN_141492f60("{0}_{1}", nJob, strGender));
    }
    if (nNpcTalk == 2)
    {
        rPage.FUN_1407cba60("lNpc", CString(strIllust));
        rPage.FUN_1407cb9c0("lNpcSpeak", 1);
    }
    else
    {
        rPage.FUN_1407cba60("rNpc", CString(strIllust));
        rPage.FUN_1407cb9c0("rNpcSpeak", 1);
    }
}

// @0x141b1c960
MS2Ptr<CCinematicComponent> UITalkCinematic::FUN_141b1c960(int nButtonSet)
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
        ((class UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode0();
        return MS2Ptr<CCinematicComponent>(0);
    }
}

// @0x141b1d3d0
int UITalkCinematic::FUN_141b1d3d0()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return -1;
    return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(FUN_1409ee290(&m_30)->Invoke("getLowerCutGlobalY")))->GetUInt();
}

// @0x141b1d460
int UITalkCinematic::FUN_141b1d460()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return -1;
    return ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(FUN_1409ee290(&m_30)->Invoke("getIllustGlobalX")))->GetUInt();
}

// @0x141b1d4f0
UINpcPreviewDialog* FUN_141b1d4f0(unsigned nUiId)
{
    if (reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spDialog = reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adcea0(nUiId);
        if (spDialog.get())
            return dynamic_cast<UINpcPreviewDialog*>((UIObject*)spDialog);
    }
    return 0;
}

// ---- UITalkManager: packets and dialogs ----

CTalkScript* FUN_140854fa0(void* pThis, CInPacket& in);        // CTalkScript::CTalkScript(CInPacket&) (talkscript.cpp, not recovered)


// The UI message sent to the swf entity registered for an event id (same shape as functioncubeobject.cpp's).
struct Unk_FcUIMsg
{
    Unk_FcUIMsg();                                              // 0x1422e4490
    ~Unk_FcUIMsg();                                             // 0x140c30570
    void* m_pad[10];
};

// The emoticon-like component of the npc (PCBase slot 83): kind 2 shows the text.
class Unk_PCBaseComp_a88 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // show
    void FUN_14192f8b0(int nState);
    void FUN_14192f8d0(const CString& str);
    void FUN_14192f9f0(int n);
};
// The chat-balloon component (PCBase slot 85: UIChatBalloon::Entity).
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // show
    virtual void vfunc_3();                                         // hide
    void FUN_1418fb6d0();                                           // m_a0 = 1
};
void* FUN_1410947c0(PCBase* pNpc);

// The packet manager's request wrappers (the exe's int-encoding helper).
struct Unk_TcInt
{
    Unk_TcInt() : m_n(0) {}                                     // 0x141b22160
    void FUN_1401fcd50(COutPacket& packet);
    int m_n;
};
void FUN_140710590(COutPacket& packet);

// A 16-byte handle (job-change record); its destructor is FUN_14063e530.
void FUN_14063e530(void* p);
struct Unk_TcJobRef
{
    ~Unk_TcJobRef() { FUN_14063e530(this); }
    bool FUN_14063e990();
    void* m_p0; void* m_p8;
};
class Unk_TcJobMgr { public: Unk_TcJobRef FUN_140644880(int nJob); };

// The dialogs the talk opens (opaque views; the members are bound by VA).
class UIJobChangeDialog* FUN_141081ff0(int);   // C3: was FUN_141081ff0
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
   void FUN_1412d9640(void* pDlg, unsigned nNpc, void* pArg);   // maid
class CManufactureManager   // C3: member view for the former free stand-ins
{
public:
    static class UIManufactureDialog* GetManufactureDialog(int);
};
   void FUN_1412e3480(void* pDlg, unsigned nNpc, void* pArg);   // manufacture
void* FUN_1413b1bc0(unsigned int);   // C3: was FUN_1413b1bc0
   void FUN_1419c02e0(void* pDlg, CString strArg);              // item enchant
void* FUN_140c053e0(int nId);                                    // attend gift
__forceinline void Unk_TcVCall0(void* p, int nSlot) { reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(p))[nSlot])(p); }
class UIAttendGiftDialog   // C3: member view for the former free stand-ins
{
public:
    bool FUN_14102c7a0(int);
};
unsigned FUN_1407181d0(const CString& str);
class UIItemTreasureMapDialog : public UIObject { public: void FUN_140c55b50(const CString& strArg); };
UIItemTreasureMapDialog* FUN_141b22040(unsigned nUiId);
class UIWeddingHallReservationDialog* FUN_141296ab0(int);   // C3: was FUN_141296ab0
   void FUN_140fdcaa0(void* pDlg, const CString& strArg);class UIWeddingHallReservationDialog   // C3: member view for the former free stand-ins
{
public:
    void SetPackage(int);
};
class Unk_TcWedding { public: char m_pad[0x18]; unsigned m_18; };
void FUN_140901e60(void* p);
class Unk_TcWeddingRef
{
public:
    ~Unk_TcWeddingRef() { FUN_140901e60(this); }
    void* FUN_141847330();
    Unk_TcWedding* FUN_1409020f0();
    void* m_p0; void* m_p8;
};
class Unk_TcWeddingMgr { public: Unk_TcWeddingRef FUN_140908c50(unsigned nNpc); };
class UIRewardNotify* FUN_140938cd0(int);   // C3: was FUN_140938cd0
void FUN_141abf230(void* pHud, __int64 n, int a);
void FUN_141abf450(void* pHud, __int64 n, int a);

// More views for the talk functions.
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980

class CMaid   // C3: member view for the former free stand-ins
{
public:
    int IsExpired();
};
// The 8-byte handle of the npc's ride/vehicle record (destructor 0x1409648b0).
void FUN_1409648b0(void* p);
struct Unk_TcHandle8
{
    ~Unk_TcHandle8() { FUN_1409648b0(this); }
    void* FUN_140965790();
    void* FUN_140975bc0();
    void* m_0;
};
Unk_TcHandle8 FUN_140963df0(void* pSrc);
// The equipment handle of the player (destructor 0x1405a85f0).
void FUN_1405a85f0(void* p);
struct Unk_TcEquip
{
    ~Unk_TcEquip() { FUN_1405a85f0(this); }
    void* FUN_1405a8e70() const;
    void* FUN_1405a8ed0() const;
    void* m_0; void* m_8;
};
struct Unk_TcPCEquip { Unk_TcEquip FUN_141655e10(int nSlot); };
class CEquipItem   // C3: member view for the former free stand-ins
{
public:
    struct Unk_EquipItemData* FUN_1411dc7f0();
};
  void* FUN_14053ec70(void* p);class ItemModelHead   // C3: member view for the former free stand-ins
{
public:
    bool FUN_1405471d0();
};
void* FUN_14165f460(MyPC* pPC);class PCGemEquip   // C3: member view for the former free stand-ins
{
public:
    int FUN_1412706f0(int);
};
void FUN_141275260(int nMsg, int a, int b);
void FUN_1412751f0(const CStringW& strMsg, int a, int b);
CStringW FUN_140298ea0(CStringW strKey);

class CNpc   // C3: member view for the former free stand-ins
{
public:
    int FUN_141092fa0();
};

class Unk_Restrictions* FUN_1409331e0();   // C3: was FUN_1409331e0
void* FUN_141742770(int nId);class UIBeautyShopDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_1418c9cb0(int);
};
class Unk_GmMovie* FUN_14138fd50(unsigned int);   // C3: was FUN_14138fd50
  void FUN_14190f110(void* pDlg, unsigned nId, CString strMsg);
CString FUN_14016a600(const wchar_t* pw, int n);
void FUN_14015f050(const CString* s, void* out, const char* sep);
unsigned* FUN_1402056b0(void* pCfg);

// The npc record found by id (16 bytes; destructor 0x14035e5b0).
void FUN_14035e5b0(void* p);
struct Unk_TcNpcRec
{
    ~Unk_TcNpcRec() { FUN_14035e5b0(this); }
    void* FUN_140729ad0() const;
    void* m_0; void* m_8;
};
Unk_TcNpcRec FUN_1406cd330(unsigned nNpcId);

// Talk script lookups (by npc and kind): the handle is returned by value.
void FUN_141abfa10(void* pHud, MS2Ptr<CItem> spItem);
CCinematicContent* FUN_141b21de0(MS2Ptr<CScriptContent> spContent);
unsigned __int64 FUN_141b21e90(const CString& strKind, const CString& strMode);
unsigned __int64 FUN_141b21f70(int nDialog, const CString& strMode, const CString& strKind);
MS2Ptr<CTalkScript> FUN_140856fa0(unsigned nNpcId, int nKind);
MS2Ptr<CTalkScript> FUN_140856c50(unsigned nNpcId, int nFlag);
MS2Ptr<CTalkScript> FUN_140856820(unsigned nNpcId, int nParam);
MS2Ptr<CTalkScript> FUN_1408564b0(unsigned nId, int nParam);
int FUN_140855cd0(unsigned char nFlags);
unsigned FUN_140857990(MS2Ptr<CTalkScript> spScript, int nFlags, int nNpc, int nPage);
CCinematicContent* FUN_14085a540(MS2Ptr<CScriptContent>& sp);
UIDialog* FUN_141386950(const CString& strDialog);                 // the dialog of a name
class Unk_TcStrArray : public ATL::CAtlArray<CString>   // dtor 0x1401641d0 = ~CAtlArray<CString>
{
public:
    CString& FUN_1401c0cc0(unsigned __int64 nIndex);
    unsigned __int64 FUN_1401662c0();
};

// @0x141b1da80
Unk_TalkIdState::Unk_TalkIdState()
{
    FUN_141b1dac0();
}

// @0x141b22200
Unk_TalkIdState::~Unk_TalkIdState()
{
}

// @0x141b1dac0
void Unk_TalkIdState::FUN_141b1dac0()
{
    m_ids.FUN_1402c2830();
    m_nPos = 0;
}

// @0x141b1daf0
unsigned Unk_TalkIdState::FUN_141b1daf0()
{
    if (m_nPos >= (int)m_ids.FUN_140186270())
        return 0;
    return m_ids.FUN_1401c0c80(m_nPos);
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
    m_items.FUN_1408f3a80();
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
void UITalkManager::FUN_141b1ddd0(CInPacket& in)
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
        FUN_141b20700();
    }
    else if (nMode == 9)
    {
        m_nFlags = in.ReadUInt8();
        m_nParam = in.ReadInt32();
        m_nPage = in.ReadInt32();
        m_nSound = in.ReadInt32();
        FUN_141b217b0();
        FUN_141b20700();
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
        case 1: FUN_141b1e990(in); break;
        case 3: FUN_141b1e8a0(in); break;
        case 4: FUN_141b1ea90(in); break;
        case 5: FUN_141b1f350(in); break;
        case 6: FUN_141b1f620(in); break;
        case 7: FUN_141b1f6b0(in); break;
        case 8: FUN_141b1f740(in); break;
        case 9: FUN_141b1f7a0(in); break;
        case 10: FUN_141b1f840(in); break;
        }
    }
    else if (nMode == 0)
    {
        m_nTalking = 0;
        FUN_141b20210();
    }
    else if (nMode == 4)
    {
        CStringW strScript = in.ReadUnicodeString();
        CString strSound = in.ReadUnicodeStringA();
        CString strIllust = in.ReadUnicodeStringA();
        TSingleton<CReservedWordTable>::GetInstance()->FUN_1416fb380(strScript);
        TSingleton<CReservedWordTable>::GetInstance()->FUN_1416fb340(strScript);
        UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
        if (pUi != 0)
            pUi->FUN_141b1a8e0(strScript, strSound, strIllust);
    }
    else if (nMode == 10)
    {
        unsigned nNpcId = in.ReadInt32();
        int nSub = (unsigned short)in.ReadInt16();
        MS2Ptr<CTalkScript> spScript(new CTalkScript(in));
        if (nSub == 1)
        {
            if (spScript->m_contents.FUN_14078fae0() == 0)
                return;
            Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(nNpcId);
            if (pNpc != 0)
            {
                MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = pNpc->vfunc_85();
                if (spBalloon.get() != 0)
                    spBalloon->FUN_1418fb6d0();
                pNpc->FUN_14166fff0(CStringW(spScript->m_contents.FUN_14078f350(0)->m_name));
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
                FUN_141b20bb0();
        }
    }
}

// @0x141b1e8a0
void UITalkManager::FUN_141b1e8a0(CInPacket& in)
{
    int nValue = in.ReadInt32();
    UISwfEntity* pEntity = FUN_1408e57f0()->FUN_1422b9e20(0x620001f);
    if (pEntity != 0)
    {
        Unk_FcUIMsg kMsg;
        ((class ASData*)(struct Unk_FcUIMsg*)(&kMsg))->FUN_1422b82b0("moveMyPC");
        ((class ASData*)(struct Unk_FcUIMsg*)(&kMsg))->FUN_1422b7f70(nValue);
        ((class ASData*)(struct Unk_FcUIMsg*)(&kMsg))->FUN_1422b8030(((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b212c0());
        pEntity->OnMessage(0, reinterpret_cast<UIMsg*>(&kMsg));
    }
}

// @0x141b1e990
void UITalkManager::FUN_141b1e990(CInPacket& in)
{
    CString strName = in.ReadUnicodeStringA();
    Unk_TcNpc* pNpc = FUN_141b21350();
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1eb90
void UITalkManager::FUN_141b1eb90(CString strDialog, CString strArg)
{
    if (strDialog.CompareNoCase("JobChangeDialog") == 0)
    {
        int nJob = atoi(strArg);
        if (reinterpret_cast<Unk_TcJobMgr*>(TSingleton<JobTable>::GetInstance())->FUN_140644880(nJob).FUN_14063e990())
            return;
        void* pDlg = ((void*)FUN_141081ff0(0x4e7c));
        if (pDlg != 0)
            ((class UIJobChangeDialog*)(void*)(pDlg))->FUN_1419dc510(nJob);
        FUN_141b21ae0(strDialog);
    }
    else if (strDialog.CompareNoCase("RouletteDialog") == 0)
    {
        Unk_TcInt kValue;
        kValue.m_n = atoi(strArg);
        COutPacket packet(static_cast<int>(SendOp::BonusGame), 0);
        packet.WriteUInt8(0);
        kValue.FUN_1401fcd50(packet);
        FUN_140710590(packet);
    }
    else if (strDialog.CompareNoCase("OpenGambleDialog") == 0)
    {
        FUN_141b21ae0(CString("GambleDialog"));
    }
    else if (strDialog.CompareNoCase("StartGambleDialog") == 0)
    {
        COutPacket packet(static_cast<int>(SendOp::Gamble), 0);
        packet.WriteUInt8(0);
        FUN_140710590(packet);
    }
    else if (strDialog.CompareNoCase("CloseGambleDialog") == 0)
    {
        reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc5d0(0x4e98);
    }
    else if (strDialog.CompareNoCase("OpenMaidDialog") == 0)
    {
        Unk_TcNpc* pNpc = FUN_141b21350();
        if (pNpc != 0 && pNpc->vfunc_128() != 0)
        {
            FUN_141b21ae0(CString("MaidDialog"));
            void* pDlg = ((void*)CUserMaidManager::GetMaidDialog(0x4e9d));
            if (pDlg != 0)
                FUN_1412d9640(pDlg, ((class GameObject*)(class PCBase*)(pNpc))->FUN_14123c580(), FUN_1410947c0(pNpc));
        }
    }
    else if (strDialog.CompareNoCase("CloseMaidDialog") == 0)
    {
        reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc5d0(0x4e9d);
    }
    else if (strDialog.CompareNoCase("OpenManufactureDialog") == 0)
    {
        Unk_TcNpc* pNpc = FUN_141b21350();
        if (pNpc != 0 && pNpc->vfunc_128() != 0)
        {
            FUN_141b21ae0(CString("ManufactureDialog"));
            void* pDlg = ((void*)CManufactureManager::GetManufactureDialog(0x4ec0));
            if (pDlg != 0)
                FUN_1412e3480(pDlg, ((class GameObject*)(class PCBase*)(pNpc))->FUN_14123c580(), FUN_1410947c0(pNpc));
        }
    }
    else if (strDialog.CompareNoCase("CloseManufactureDialog") == 0)
    {
        reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc5d0(0x4ec0);
    }
    else if (strDialog.CompareNoCase("BeautyShopDialog") == 0)
    {
        FUN_141b1f920(strArg);
    }
    else if (strDialog.CompareNoCase("BeautyStyleDialog") == 0)
    {
        FUN_141b1fa20(strArg);
    }
    else if (strDialog.CompareNoCase("ItemEnchantDialog") == 0)
    {
        void* pDlg = FUN_1413b1bc0(0x4e92);
        if (pDlg != 0)
            FUN_1419c02e0(pDlg, strArg);
        FUN_141b21ae0(strDialog);
    }
    else if (strDialog.CompareNoCase("AttendGiftDialog") == 0)
    {
        void* pDlg = FUN_140c053e0(0x4eb8);
        if (pDlg != 0)
        {
            if (((class UIDialog*)(void*)(pDlg))->FUN_141924630() != 0)
                Unk_TcVCall0(pDlg, 0x44);
            if (strArg.IsEmpty())
            {
                ((class UIDialog*)(void*)(pDlg))->FUN_141924680();
            }
            else if (((class UIAttendGiftDialog*)(void*)(pDlg))->FUN_14102c7a0(FUN_1407181d0(strArg)) == 0)
            {
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
        UIItemTreasureMapDialog* pDlg = FUN_141b22040(0x4f5b);
        if (pDlg != 0)
            pDlg->FUN_140c55b50(strArg);
        FUN_141b21ae0(strDialog);
    }
    else if (strDialog.CompareNoCase("WeddingHallReservationDialog") == 0)
    {
        void* pDlg = ((void*)FUN_141296ab0(0x4f8d));
        if (pDlg != 0)
        {
            unsigned nNpc = (unsigned)FUN_141b212f0();
            Unk_TcWeddingRef kRef = reinterpret_cast<Unk_TcWeddingMgr*>(TSingleton<WeddingTable>::GetInstance())->FUN_140908c50(nNpc);
            if (kRef.FUN_141847330() != 0)
            {
                FUN_140fdcaa0(pDlg, strArg);
                ((class UIWeddingHallReservationDialog*)(void*)(pDlg))->SetPackage(kRef.FUN_1409020f0()->m_18);
                FUN_141b21ae0(strDialog);
            }
        }
    }
    else
    {
        FUN_141b21ae0(strDialog);
    }
}

// @0x141b1f350
void UITalkManager::FUN_141b1f350(CInPacket& in)
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
            spItem->FUN_140524eb0(in);
            spItem->FUN_14052b340(nAmount);
            if (reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc890(0x4e98) != 0)
                m_reward.m_items.FUN_140720b80(spItem);
            else if (spItem->FUN_1405258f0() != 0)
                m_reward.m_nMeso += nAmount;
            else
                m_reward.m_items.FUN_140720b80(spItem);
            if (spItem->FUN_140525980() == 0)
            {
                void* pHud = ((void*)FUN_140938cd0(0x4e5d));
                if (pHud != 0)
                    FUN_141abfa10(pHud, MS2Ptr<CItem>(spItem));
            }
        }
    }
}

// @0x141b1f620
void UITalkManager::FUN_141b1f620(CInPacket& in)
{
    __int64 nValue = in.ReadInt64();
    m_reward.m_nMerat += nValue;
    void* pHud = ((void*)FUN_140938cd0(0x4e5d));
    if (pHud != 0)
        FUN_141abf230(pHud, nValue, 0);
}

// @0x141b1f6b0
void UITalkManager::FUN_141b1f6b0(CInPacket& in)
{
    __int64 nValue = in.ReadInt64();
    m_reward.m_nMeso += nValue;
    void* pHud = ((void*)FUN_140938cd0(0x4e5d));
    if (pHud != 0)
        FUN_141abf450(pHud, nValue, 0);
}

// @0x141b1f740
void UITalkManager::FUN_141b1f740(CInPacket& in)
{
    int nExp = in.ReadInt32();
    m_reward.m_nExp += nExp;
}

// @0x141b1f7a0
void UITalkManager::FUN_141b1f7a0(CInPacket& in)
{
    int nValue = in.ReadInt32();
    int bJackpot = in.ReadUInt8();
    m_reward.m_nAffinity += nValue;
    if (bJackpot != 0)
        m_reward.m_nJackpot = 1;
}

// @0x141b1f840
void UITalkManager::FUN_141b1f840(CInPacket& in)
{
    unsigned nValue = in.ReadInt32();
    CStringW strText = in.ReadUnicodeString();
    void* pDlg = ((void*)FUN_14138fd50(0x4e7e));
    if (pDlg != 0)
        FUN_14190f110(pDlg, nValue, FUN_14016a600(strText, 0));
}

// @0x141b1f920
void UITalkManager::FUN_141b1f920(const CString& strArgs)
{
    Unk_TcStrArray kParts;
    FUN_14015f050(&strArgs, &kParts, ",");
    CString strKind = kParts.FUN_1401c0cc0(0);
    CString strMode;
    if (kParts.FUN_1401662c0() > 1)
        strMode = kParts.FUN_1401c0cc0(1);
    unsigned nDialog = (unsigned)FUN_141b21e90(strKind, strMode);
    unsigned nType = (unsigned)FUN_141b21f70(nDialog, strMode, strKind);
    FUN_141b1faa0(nType, nDialog);
}

// @0x141b1fa20
void UITalkManager::FUN_141b1fa20(const CString& strArgs)
{
    int nId = 0x4f03;
    int nType = 4;
    FUN_141b1faa0(nType, nId);
}

// @0x141b1fa60
bool UITalkManager::FUN_141b1fa60()
{
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return false;
    return true;
}

// @0x141b1faa0
void UITalkManager::FUN_141b1faa0(int nMode, int nDialogId)
{
    MS2Ptr<UITalkCinematic> spUi(FUN_140a7b2b0(0x4e40));
    if (spUi == 0)
        return;
    unsigned nNpc = (unsigned)((class UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b212f0();
    spUi->FUN_141b1bfa0();
    if (nDialogId == 0x4e24 && !FUN_141b1fa60())
    {
        SendNpcTalkMode0();
        return;
    }
    if (nDialogId == 0x4eee)
    {
        void* pDlg = FUN_141742770(0x4eee);
        if (pDlg != 0)
            ((class UIBeautyShopDialog*)(void*)(pDlg))->FUN_1418c9cb0(nNpc);
    }
    {
        Unk_TcNpcRec kRec = FUN_1406cd330(nNpc);
        if (kRec.FUN_140729ad0() != 0)
        {
            UISwfEntity* pEntity = FUN_1408e57f0()->FUN_1422b9e20(0x620001f);
            if (pEntity != 0)
            {
                Unk_FcUIMsg kMsg;
                    ((class ASData*)(struct Unk_FcUIMsg*)(&kMsg))->FUN_1422b82b0("openDialog");
                ((class ASData*)(struct Unk_FcUIMsg*)(&kMsg))->FUN_1422b7f70(nDialogId);
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
    if (FUN_141b211d0() == 0)
        return;
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC != 0)
    {
        int nState = pPC->FUN_14166c930();
        if ((nState == 1 || nState == 0xb || nState == 0xf || nState == 0x21 || nState == 2) == 0)
            return;
    }
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(nNpcId);
    if (pNpc == 0)
        return;
    int nUiId = pNpc->FUN_141094170();
    if (nUiId != 0)
    {
        if (reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc7f0(nUiId) == 0)
            return;
    }
    if (nUiId == 0x4e3b)
        reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc690(0x4e3b);
    reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc170();
    if (FUN_141b218b0(pNpc) != 0)
        return;
    if (TSingleton<CMouseController>::GetInstance()->HasMode() != 0)
        TSingleton<CMouseController>::GetInstance()->FUN_140ad22d0();
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
    FUN_141b20210();
    FUN_140a94350()->vfunc_10(0);
}

// @0x141b1ff80
void UITalkManager::FUN_141b1ff80(unsigned nNpcId)
{
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(nNpcId);
    if (pPC != 0 && pNpc != 0)
    {
        m_nTalking = 1;
        m_nNpcId = nNpcId;
        pPC->vfunc_94(nNpcId);
        pNpc->vfunc_94(((class GameObject*)(class PCBase*)(pPC))->FUN_14123c580());
        m_spScript = FUN_141b21b90();
        if (m_spScript.get() != 0)
        {
            FUN_1408e57f0()->FUN_1422b9fd0(0x6200031);
        }
        else
        {
            if (pNpc->FUN_141094170() != 0)
                m_48 = pNpc->FUN_141094200();
        }
        pNpc->FUN_141093fa0();
    }
}

// @0x141b200d0
void UITalkManager::FUN_141b200d0(unsigned nNpcId, CTalkScript* pScript)
{
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(nNpcId);
    if (pPC != 0 && pNpc != 0)
    {
        m_nTalking = 1;
        m_nNpcId = nNpcId;
        pPC->vfunc_94(nNpcId);
        pNpc->vfunc_94(((class GameObject*)(class PCBase*)(pPC))->FUN_14123c580());
        m_spScript.AssignRaw(pScript);
        if (m_spScript.get() != 0)
        {
            FUN_1408e57f0()->FUN_1422b9fd0(0x6200031);
        }
        else
        {
            if (pNpc->FUN_141094170() != 0)
                m_48 = pNpc->FUN_141094200();
        }
        pNpc->FUN_141093fa0();
        FUN_140a94350()->vfunc_10(2);
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20210
void UITalkManager::FUN_141b20210()
{
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC != 0)
    {
        if (pPC->vfunc_85().get())
            pPC->vfunc_85()->vfunc_3();
        Unk_TcHandle8 kRide = FUN_140963df0(((void*)((class PCBase*)(class PCBase*)(pPC))->FUN_1416764a0()));
        if ((kRide.FUN_140965790() ? true : false) && ((PCBase*)kRide.FUN_140975bc0())->FUN_14166c930() == 0x16)
            pPC->vfunc_59(1, 0, 0, 0);
        else if (pPC->FUN_14166c930() == 0x16)
            pPC->vfunc_59(1, 0, 0, 0);
        m_ids.FUN_141b1dac0();
        UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
        if (pUi != 0)
            pUi->FUN_141b1b8b0();
    }
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(m_nNpcId);
    if (pNpc != 0)
    {
        pNpc->FUN_141094050();
        pNpc->FUN_1410942c0();
    }
    reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc2c0();
    m_nTalking = 0;
    m_nNpcId = 0;
    m_spScript = 0;
    m_48 = 0;
    m_nSpecialNpc = 0;
    m_nLastTick = GetTickCountMs2();
    m_reward.FUN_141b1dbd0();
    FUN_140a94350()->vfunc_10(0);
}

// @0x141b204d0
int UITalkManager::FUN_141b204d0()
{
    if (FUN_141b213c0() != 0)
    {
        FUN_141b215b0(1);
        return 1;
    }
    if (m_spScript.get() != 0 && m_spScript->FUN_140855520())
    {
    }
    else
    {
        m_spScript = FUN_141b21b90();
    }
    if (FUN_141b20bb0() == 0)
    {
        SendNpcTalkMode0();
        return 0;
    }
    m_nPending = 0;
    Unk_TcNpc* pNpc = FUN_141b21350();
    bool bHasTag = pNpc != 0 && static_cast<bool>(pNpc->vfunc_83().get());
    if (bHasTag)
        pNpc->vfunc_83()->FUN_14192f9f0(m_nSubMode);
    return 1;
}

// @0x141b20700
void UITalkManager::FUN_141b20700()
{
    m_spScript = FUN_141b21b90();
    if (m_spScript.get() != 0)
        FUN_1408e57f0()->FUN_1422b9fd0(0x6200031);
}

// @0x141b20790
void UITalkManager::FUN_141b20790(int nNpcId, int nFriendly)
{
    if (m_nNpcId == nNpcId)
        return;
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(nNpcId);
    if (pNpc == 0)
        return;
    int nKind = 9;
    bool bAffinity = pNpc->vfunc_128() != 0 && (pNpc->FUN_141093800().FUN_1409ee260() ? true : false);
    if (bAffinity)
    {
        if (((class CMaid*)(void*)(pNpc->FUN_141093800().FUN_14067e8c0()))->IsExpired())
            nKind = 8;
        else
            nKind = 7;
    }
    MS2Ptr<CTalkScript> spScript = FUN_140856fa0(((class CNpc*)(class PCBase*)(pNpc))->FUN_141092fa0(), nKind);
    if ((spScript.get() ? true : false) && spScript->m_contents.FUN_14078fae0() > 0)
    {
        pNpc->FUN_14166fff0(CStringW(spScript->m_contents.FUN_14078f350(0)->m_name));
        if (((class UITalkManager*)Unk_AkoCutscene::GetInstance())->GetTalking() == 0 && spScript->m_contents.FUN_14078f350(0)->m_unk20.GetLength() != 0)
            FUN_1411a4f40(FUN_1403ed280(), CString(spScript->m_contents.FUN_14078f350(0)->m_unk20), pNpc->vfunc_18());
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
void UITalkManager::FUN_141b20af0()
{
    if (FUN_141b213c0() != 0)
        return;
    if (GetTalking() != 0)
    {
        MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
        Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(m_nNpcId);
        if (pPC == 0 || pNpc == 0)
        {
            SendNpcTalkMode0();
        }
        else if (pNpc->FUN_141094300() == 0)
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
int UITalkManager::FUN_141b20bb0()
{
    Unk_TcNpc* pNpc = FUN_141b21350();
    if (pNpc == 0)
        return 0;
    UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
    if (pUi == 0)
        return 0;
    if (m_spScript.get() != 0)
    {
        if (m_nPage < (int)m_spScript->m_contents.FUN_14078fae0())
        {
            MS2Ptr<CScriptContent> spContent = m_spScript->m_contents.FUN_14078f350(m_nPage);
            int bLast = m_nPage == (int)m_spScript->m_contents.FUN_14078fae0() - 1;
            if (bLast)
                bLast = m_spScript->m_gotoConditionTalkIds.FUN_140186260() == 0;
            return pUi->FUN_141b1b440(FUN_141b21de0(MS2Ptr<CScriptContent>(spContent)), bLast);
        }
    }
    else
    {
        if (pNpc->FUN_141094170() == 0)
            return 0;
        pNpc->FUN_141094200();
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
void UITalkManager::FUN_141b20e60(MS2Ptr<CTalkScript> spScript, int nId, int nPage)
{
    m_spScript = spScript;
    m_nParam = nId;
    m_nPage = nPage;
    FUN_141b20bb0();
}

// @0x141b20ed0
CStringW UITalkManager::FUN_141b20ed0()
{
    if (m_spScript.IsNull())
        return CStringW(L"");
    if (m_nPage >= (int)m_spScript->m_contents.FUN_14078fae0())
        return CStringW(L"");
    return CStringW(m_spScript->m_contents.FUN_14078f350(m_nPage)->m_name);
}

// @0x141b20fe0
MS2Ptr<CTalkScript> UITalkManager::GetScript()
{
    return m_spScript;
}

// @0x141b21030
MS2Ptr<CCinematicContent> UITalkManager::FUN_141b21030()
{
    if (m_spScript.IsNull())
        return MS2Ptr<CCinematicContent>(0);
    if (m_nPage >= (int)m_spScript->m_contents.FUN_14078fae0())
        return MS2Ptr<CCinematicContent>(0);
    MS2Ptr<CScriptContent> spContent = m_spScript->m_contents.FUN_14078f350(m_nPage);
    return MS2Ptr<CCinematicContent>(FUN_141b21de0(MS2Ptr<CScriptContent>(spContent)));
}

// @0x141b21190
void UITalkManager::FUN_141b21190(int nFlags, int nParam, int nPage)
{
    m_nFlags = (unsigned char)nFlags;
    m_nParam = nParam;
    m_nPage = nPage;
}

// @0x141b211d0
int UITalkManager::FUN_141b211d0()
{
    if (GetTickCountMs2() - m_nLastTick < *FUN_1402056b0(reinterpret_cast<char*>(((class Unk_TcSettings*)FUN_1401d3200())) + 0x3730))
        return 0;
    return 1;
}

// @0x141b21220
int UITalkManager::GetTalking()
{
    return m_nTalking;
}

// @0x141b21240
int UITalkManager::FUN_141b21240(int nNpcId)
{
    if (GetTalking() == 0)
        return 0;
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (nNpcId == (int)((class GameObject*)(class PCBase*)(pPC))->FUN_14123c580())
        return 1;
    if (nNpcId == m_nNpcId)
        return 1;
    return 0;
}

// @0x141b212c0
unsigned UITalkManager::FUN_141b212c0()
{
    if (GetTalking() == 0)
        return 0;
    return m_nNpcId;
}

// @0x141b212f0
int UITalkManager::FUN_141b212f0()
{
    Unk_TcNpc* pNpc = FUN_141b21350();
    if (pNpc != 0)
        return ((class CNpc*)(class PCBase*)(pNpc))->FUN_141092fa0();
    if (FUN_141b213c0() != 0)
        return m_nSpecialNpc;
    return 0;
}

// @0x141b21350
Unk_TcNpc* UITalkManager::FUN_141b21350()
{
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(FUN_141b212c0());
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
unsigned UITalkManager::FUN_141b213f0(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound)
{
    if (GetTalking() != 0)
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_error_talk_already_talking")), 1, 1);
        return 0;
    }
    if (spScript.IsNull())
        return 0;
    m_nTalking = 1;
    m_nSpecialNpc = nSpecialNpc;
    m_spScript = spScript;
    FUN_141b21190(nFlags | 0x10, spScript->m_id, 0);
    if (nSound != 0)
        m_nSound = nSound;
    else
        m_nSound = FUN_141b21d70();
    FUN_1408e57f0()->FUN_1422b9fd0(0x6200031);
    return 1;
}

// @0x141b215b0
void UITalkManager::FUN_141b215b0(int bSamePage)
{
    UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
    if (pUi == 0)
        return;
    if (bSamePage == 0)
    {
        m_nPage++;
        m_nSound = FUN_141b21d70();
    }
    if (m_spScript.get() != 0)
    {
        if (m_nPage < (int)m_spScript->m_contents.FUN_14078fae0())
        {
            MS2Ptr<CScriptContent> spContent = m_spScript->m_contents.FUN_14078f350(m_nPage);
            int bLast = m_nPage == (int)m_spScript->m_contents.FUN_14078fae0() - 1;
            if (bLast)
                bLast = m_spScript->m_gotoConditionTalkIds.FUN_140186260() == 0;
            pUi->FUN_141b1b440(FUN_141b21de0(MS2Ptr<CScriptContent>(spContent)), bLast);
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
    m_ids.FUN_141b1dac0();
}

// @0x141b217e0
void UITalkManager::FUN_141b217e0(unsigned nId)
{
    m_ids.m_ids.FUN_1401855a0(nId);
}

// @0x141b21810
unsigned UITalkManager::FUN_141b21810(int nIndex)
{
    if (m_ids.m_ids.FUN_140186270() <= (unsigned __int64)(__int64)nIndex)
        return 0;
    return m_ids.m_ids.FUN_140184510(nIndex);
}

// @0x141b21860
unsigned __int64 UITalkManager::FUN_141b21860()
{
    return m_ids.m_ids.FUN_140186270();
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
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (pNpc->FUN_1410937b0() == 0x23)
    {
        int nNotice = 0;
        {
            Unk_TcEquip kEquip = reinterpret_cast<Unk_TcPCEquip*>(pPC)->FUN_141655e10(6);
            if (kEquip.FUN_1405a8e70() != 0)
            {
                if (((void*)((class CEquipItem*)(void*)(kEquip.FUN_1405a8ed0()))->FUN_1411dc7f0()) != 0
                    && ((class ItemModelHead*)(void*)(FUN_14053ec70(((void*)((class CEquipItem*)(void*)(kEquip.FUN_1405a8ed0()))->FUN_1411dc7f0()))))->FUN_1405471d0() != 0)
                    return 0;
                else if (((class PCGemEquip*)(void*)(FUN_14165f460(pPC)))->FUN_1412706f0(0) != 0)
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
Unk_TalkIdList* UITalkManager::FUN_141b21a10()
{
    return &m_openedDialogs;
}

// @0x141b21a30
void UITalkManager::FUN_141b21a30()
{
    if (m_openedDialogs.FUN_140186270() != 0)
    {
        for (unsigned i = 0; i < m_openedDialogs.FUN_140186270(); i++)
            reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc530(m_openedDialogs.FUN_140184510(i));
        m_openedDialogs.FUN_1402c2830();
    }
}

// @0x141b21ae0
void UITalkManager::FUN_141b21ae0(const CString& strDialog)
{
    UIDialog* pDlg = FUN_141386950(strDialog);
    if (pDlg == 0)
        return;
    UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
    if (pUi != 0 && pUi->GetLoaded() != 0)
        reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adc530(pDlg->vfunc_48());
    else
        m_openedDialogs.FUN_1401855a0(pDlg->vfunc_48());
}

// @0x141b21b90
MS2Ptr<CTalkScript> UITalkManager::FUN_141b21b90()
{
    MyPC* pPC = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPC == 0)
        return MS2Ptr<CTalkScript>(0);
    Unk_TcNpc* pNpc = reinterpret_cast<Unk_TcWorld*>(WorldService::GetInstance())->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return MS2Ptr<CTalkScript>(0);
    if ((m_nFlags & 8) != 0)
        return FUN_140856c50(((class CNpc*)(class PCBase*)(pNpc))->FUN_141092fa0(), 0);
    else if ((m_nFlags & 4) != 0)
        return FUN_1408564b0(m_ids.m_ids.FUN_140184510(0), m_nParam);
    else if (FUN_140855cd0(m_nFlags) != 0)
        return FUN_140856820(((class CNpc*)(class PCBase*)(pNpc))->FUN_141092fa0(), m_nParam);
    else if ((m_nFlags & 1) != 0)
        return FUN_140856c50(((class CNpc*)(class PCBase*)(pNpc))->FUN_141092fa0(), 1);
    return MS2Ptr<CTalkScript>(0);
}

// @0x141b21d70
unsigned UITalkManager::FUN_141b21d70()
{
    return FUN_140857990(GetScript(), m_nFlags, m_nSpecialNpc, m_nPage);
}

// @0x141b21de0
CCinematicContent* FUN_141b21de0(MS2Ptr<CScriptContent> spContent)
{
    if (spContent.IsNull())
        return 0;
    if (spContent->vfunc_1() != 0)
        return 0;
    return FUN_14085a540(spContent);
}

// @0x141b21e90
unsigned __int64 FUN_141b21e90(const CString& strKind, const CString& strMode)
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
unsigned __int64 FUN_141b21f70(int nDialog, const CString& strMode, const CString& strKind)
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
UIItemTreasureMapDialog* FUN_141b22040(unsigned nUiId)
{
    if (reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spDialog = reinterpret_cast<Unk_TcUi*>(TSingleton<CUIService>::GetInstance())->FUN_141adcea0(nUiId);
        if (spDialog.get() != 0)
            return dynamic_cast<UIItemTreasureMapDialog*>((UIObject*)spDialog);
    }
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc2bc0-0x142cc2d30 .text$yd
