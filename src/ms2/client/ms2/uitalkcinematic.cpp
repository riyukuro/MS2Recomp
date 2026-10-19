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
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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

struct Unk_TcPos { float m_v[3]; };
typedef Unk_TcPos (*Unk_TcPosFn)(void*);
__forceinline Unk_TcPos Unk_TcActorPos(void* pActor) { return reinterpret_cast<Unk_TcPosFn>((*reinterpret_cast<void***>(pActor))[18])(pActor); }

class Unk_TcWorld
{
public:
    MyPC* FUN_141bd0cc0();                                      // local player
    Unk_TcNpc* FUN_141bd1320(unsigned nActorId);                // actor by id
};
Unk_TcWorld* FUN_1403ed2d0();

class Unk_TcUi
{
public:
    int FUN_141adc940(int nId);                                 // is open
    int FUN_141adc890(int nId);
    int FUN_141adc7f0(int nId);
    void FUN_141adc690(int nId);
    void FUN_141adc170();
    void FUN_141adc2c0();
    void FUN_141adc5d0(int nId);                                // open
    void FUN_141adc530(int nId);                                // close
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                    // lookup
};
Unk_TcUi* FUN_1403ed2b0();

class Unk_TcBgm { public: void FUN_1422b9fd0(int nGroup); UISwfEntity* FUN_1422b9e20(int nGroup); };
Unk_TcBgm* FUN_1408e57f0();
class Unk_TcSwfMgr { public: void FUN_1422d4780(UISwfEntity* p, int n); void FUN_1422d4840(UISwfEntity* p, int n); };
Unk_TcSwfMgr* FUN_140b632f0();
class Unk_140a94350
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_140a94350* FUN_140a94350();
class Unk_TcUiScale { public: float FUN_1422afec0(int nUiId); };
Unk_TcUiScale* FUN_14025e7a0();
CInputKeyHandler* FUN_14025e7c0();
UITalkManager* FUN_140967100();
UITalkCinematic* FUN_140a7b2b0(int nId);

class Unk_TcSettings { public: char m_pad[0xe0f8]; };
Unk_TcSettings* FUN_1401d3200();
unsigned* FUN_1401d7c10(void* pOption);                         // the option value
void* FUN_140166410();
bool FUN_14036d570(void* pOption, int nIndex);
void* FUN_1409a8b10();
class Unk_TcOpt { public: char m_pad[6]; char m_6; };
Unk_TcOpt* FUN_140b123b0(void* p);
unsigned FUN_141654700(MyPC* p);                                // job code
int FUN_141658e60(MyPC* p);                                     // gender
CString FUN_141492f60(const char* szFmt, const unsigned& nJob, CString strGender);

class Unk_TcNpcTable { public: CString FUN_140a7d1a0(unsigned nNpcId); };   // the illust path of an npc
Unk_TcNpcTable* FUN_1406d6e90();
CString FUN_140cc2c70(const CString& strPath);                  // the full path of an illust
int FUN_141b70ea0(const CString& strPath);                      // the file exists
bool FUN_1401c0090(const CString& a, const CString& b);         // equal

void* FUN_1403ed280();                                          // the effect service
void FUN_1411a4f40(void* pEffects, CString strSound, const Unk_TcPos& kPos);
void FUN_141276180(const CString& strSound, const CString& strArg);
void FUN_141415600(CString& strImage);                          // release a reward image

AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
AScript* FUN_1409ee240(MS2Ptr<AScript>* p);
AScript* FUN_140ba7c60(MS2Ptr<AScript>* p);
bool FUN_140a467d0(MS2Ptr<AScript>* p);                         // the AS object is gone
bool FUN_1409c1720(const Scaleform::GFx::Value& v);
int FUN_1409c17e0(const Scaleform::GFx::Value& v);
Scaleform::GFx::Value FUN_14190b490(AScript* pDlg, const char* szMethod, unsigned nW, unsigned nH, float fScale);
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
CString UITalkCinematic::vfunc_1() { return "TalkCinematic"; }

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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1a140
void UITalkCinematic::OnLoadComplete()
{
    UIObject::OnLoadComplete();
    FUN_141b1bfa0();
    if (FUN_140967100()->FUN_141b21220() == 0)
    {
        FUN_1408e57f0()->FUN_1422b9fd0(m_nKeyGroup);
    }
    else if (FUN_1409ee240(&m_30) != 0)
    {
        MS2Ptr<CCinematicContent> spContent = FUN_140967100()->FUN_141b21030();
        if (!spContent.IsNull())
        {
            ASObj page(2);
            FUN_141b1bfe0(page, spContent.get());
            FUN_1409ee290(&m_30)->Invoke("init", page);
        }
    }
}

// @0x141b1a280
void UITalkCinematic::vfunc_26() { UIObject::vfunc_26(); }

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1a2a0
void UITalkCinematic::vfunc_43()
{
    MS2Ptr<ASMovieClip> spClip(dynamic_cast<ASMovieClip*>(FUN_140ba7c60(&m_30)));
    if (spClip.get() != 0)
    {
        spClip->vfunc_2(5, 0, 0);
        float fScale = FUN_14025e7a0()->FUN_1422afec0(m_28);
        FUN_14190b490(spClip.operator->(), "setStageSize", DAT_143af62d4, DAT_143af62d8, fScale);
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1a3b0
int UITalkCinematic::vfunc_13()
{
    if (FUN_141b1c530())
    {
        FUN_141b1bce0(0x493e2);
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116dd30(0x49409, 0, 0))
        FUN_141b1bce0(1);
    else if (FUN_14025e7c0()->FUN_14116d840())
        FUN_141b1bce0(1);
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x79, 0, 0))
        FUN_141b1bce0(0x79);
    else if (FUN_14025e7c0()->FUN_14116dd30(0x30d41, 0, 0))
        FUN_141b1bce0(0x79);
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x7e, 0, 0))
        FUN_141b1bce0(0x7e);
    else if (FUN_14025e7c0()->FUN_14116dd30(0x30d42, 0, 0))
        FUN_141b1bce0(0x7e);
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x92, 0, 0))
        FUN_141b1bce0(0x79);
    else if (FUN_14025e7c0()->FUN_14116d9c0(0x93, 0, 0))
        FUN_141b1bce0(0x7e);
    else
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1a580
int UITalkCinematic::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    ASData data;
    if (_stricmp("OnLoadComplete", szMethod) == 0)
    {
        m_nLoaded = 1;
        FUN_140967100()->FUN_141b204d0();
        FUN_140967100()->FUN_141b21a30();
        return 1;
    }
    if (_stricmp("OnCloseComplete", szMethod) == 0)
    {
        FUN_1422dc080();
        FUN_1408e57f0()->FUN_1422b9fd0(m_nKeyGroup);
        FUN_141b1bfa0();
        return 1;
    }
    if (_stricmp("OnTalkComplete", szMethod) == 0)
    {
        m_nTalkComplete = 1;
        return 1;
    }
    if (_stricmp("OnEnd", szMethod) == 0)
    {
        FUN_141b1bce0(1);
        return 1;
    }
    if (_stricmp("OnNext", szMethod) == 0)
    {
        FUN_141b1bce0(0x493e2);
        return 1;
    }
    if (_stricmp("OnMovieComplete", szMethod) == 0)
    {
        m_nTalkComplete = 1;
        FUN_141b1bce0(0x493e2);
        return 1;
    }
    if (_stricmp("OnSelect", szMethod) == 0)
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1a8e0
bool UITalkCinematic::FUN_141b1a8e0(const CStringW& strScript, const CString& strSound, const CString& strIllust)
{
    if (!m_spContent.IsNull())
        return false;
    if (m_nLoaded == 0)
        return false;
    if (m_nTalkComplete == 0)
        return false;
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() == 0)
        return false;
    ASObj page(2);
    if (strIllust.GetLength() == 0)
    {
        MS2Ptr<CCinematicContent> spContent = FUN_140967100()->FUN_141b21030();
        FUN_141b1bfe0(page, spContent.get());
    }
    else
    {
        ASObj illust(2);
        illust.FUN_1407cba60("lNpc", FUN_141b1c670(strIllust));
        illust.FUN_1407cb9c0("lNpcSpeak", 1);
        page.FUN_1409eb270("illust", illust);
    }
    page.FUN_1407cbb20("script", CStringW((const wchar_t*)strScript));
    spEntity->Invoke("modifyScript", page);
    if (strSound.GetLength() != 0)
    {
        Unk_TcNpc* pNpc = FUN_140967100()->FUN_141b21350();
        if (pNpc != 0)
            FUN_1411a4f40(FUN_1403ed280(), CString(strSound), Unk_TcActorPos(pNpc));
    }
    return true;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1ac40
void UITalkCinematic::FUN_141b1ac40(Unk_TalkItemList& rItems, const CStringW& strTitle, unsigned nMeso, unsigned nExp, __int64 nMerat)
{
    if (m_spContent.IsNull() && m_nLoaded != 0 && !FUN_140a467d0(&m_30))
    {
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
                strImage.Format("%s_%d", (const char*)vfunc_1(), (int)i);
                FUN_141415450(strImage, MS2Ptr<CItem>(spItem), 0, 0x11, 0x800);
                CString strKey;
                strKey.Format("reward%d", (int)i + 1);
                FUN_141b1beb0(strImage);
                page.FUN_1407cba60(strKey, strImage);
            }
            spEntity->Invoke("modifyReward", page);
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1b000
void UITalkCinematic::FUN_141b1b000(Unk_TalkItemList& rItems, const CStringW& strTitle, const CStringW& strMood, const CStringW& strAffinityExp, int nJackpot)
{
    if (m_spContent.IsNull() && m_nLoaded != 0 && !FUN_140a467d0(&m_30) && rItems.FUN_140720ca0() != 0)
    {
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
                strImage.Format("%s_%d", (const char*)vfunc_1(), (int)i);
                FUN_141415450(strImage, MS2Ptr<CItem>(spItem), 0, 0x11, 0x800);
                CString strKey;
                strKey.Format("reward%d", (int)i + 1);
                FUN_141b1beb0(strImage);
                page.FUN_1407cba60(strKey, strImage);
            }
            spEntity->Invoke("modifyReward", page);
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1b440
int UITalkCinematic::FUN_141b1b440(CCinematicContent* pContent, bool bLast)
{
    if (pContent != 0 && m_nLoaded != 0 && m_nTalkComplete != 0)
    {
        FUN_141b1bf00();
        MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
        if (spEntity.get() != 0)
        {
            m_spContent.AssignRaw(pContent);
            m_nTalkComplete = 0;
            m_spComponent = FUN_141b1c960(FUN_140967100()->FUN_141b1d810());
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
                    if (FUN_140967100()->FUN_141b213c0() == 0)
                    {
                        Unk_TcNpc* pNpc = FUN_140967100()->FUN_141b21350();
                        if (pNpc != 0)
                            FUN_1411a4f40(FUN_1403ed280(), CString(m_spContent->m_unk20), Unk_TcActorPos(pNpc));
                    }
                    else
                    {
                        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
                        if (pPC != 0)
                            FUN_1411a4f40(FUN_1403ed280(), CString(m_spContent->m_unk20), Unk_TcActorPos(pPC));
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1b8b0
void UITalkCinematic::FUN_141b1b8b0()
{
    m_spContent = 0;
    m_nTalkComplete = 1;
    m_nLoaded = 0;
    m_spComponent = 0;
    FUN_141b1bf00();
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() == 0)
    {
        FUN_1422dc080();
        FUN_1408e57f0()->FUN_1422b9fd0(m_nKeyGroup);
        FUN_141b1bfa0();
    }
    else
    {
        reinterpret_cast<Unk_TcEntity*>(spEntity.operator->())->vfunc_13(CString("hide"));
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1b9f0
void UITalkCinematic::FUN_141b1b9f0()
{
    MS2Ptr<ASGameEntity> spEntity(dynamic_cast<ASGameEntity*>(FUN_140ba7c60(&m_30)));
    if (spEntity.get() != 0)
    {
        spEntity->Invoke("onSkip");
        FUN_141276180(s_nextKey, CString(""));
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1bce0
void UITalkCinematic::FUN_141b1bce0(int nMsg)
{
    if (m_nLoaded != 0 && !m_spContent.IsNull())
    {
        if (m_nTalkComplete == 0 && nMsg == 0x493e2)
        {
            FUN_141b1b9f0();
        }
        else if (!FUN_140a467d0(&m_30))
        {
            bool bCanNext = FUN_1409c1720(FUN_1409ee290(&m_30)->Invoke("canNext"));
            if (bCanNext && m_spComponent.get() != 0)
                m_spComponent->vfunc_2(nMsg);
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1be50
void UITalkCinematic::FUN_141b1be50()
{
    if (!FUN_140a467d0(&m_30))
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
void UITalkCinematic::FUN_141b1bf80(unsigned nKeyGroup) { m_nKeyGroup = nKeyGroup; }

// @0x141b1bfa0
void UITalkCinematic::FUN_141b1bfa0() { m_nKeyGroup = 0x620001d; }

// @0x141b1bfc0
int UITalkCinematic::FUN_141b1bfc0() { return m_nLoaded; }

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1bfe0
void UITalkCinematic::FUN_141b1bfe0(ASObj& rPage, const CCinematicContent* pContent)
{
    ASObj illust(2);
    if (FUN_140967100()->FUN_141b213c0() != 0)
    {
        if (FUN_1403ed2b0()->FUN_141adc940(0x4e89) == 0)
        {
            UINpcPreviewDialog* pPreview = FUN_141b1d4f0(0x4e89);
            if (pPreview != 0)
            {
                illust.FUN_1407cba60("lNpc", FUN_141b1c670(FUN_1406d6e90()->FUN_140a7d1a0(pPreview->FUN_141b1d820())));
                illust.FUN_1407cb9c0("lNpcSpeak", 1);
                rPage.FUN_1409eb270("illust", illust);
                return;
            }
        }
    }
    if (pContent == 0)
        return;
    if (pContent->m_leftIllust.GetLength() == 0 && pContent->m_rightIllust.GetLength() == 0)
    {
        if (pContent->m_myTalk == 0)
        {
            if (pContent->m_unk28.GetLength() == 0)
            {
                if (pContent->m_otherNpcTalk == 0)
                {
                    if (pContent->m_speakerNpc != 0 && pContent->m_speakerNpc != (int)FUN_140967100()->FUN_141b212f0())
                    {
                        rPage.FUN_1409eb270("illust", illust);
                        return;
                    }
                    illust.FUN_1407cba60("lNpc", FUN_141b1c5e0((unsigned)FUN_140967100()->FUN_141b212f0()));
                    illust.FUN_1407cb9c0("lNpcSpeak", 1);
                }
                else
                {
                    illust.FUN_1407cba60("rNpc", FUN_141b1c5e0(pContent->m_otherNpcTalk));
                    illust.FUN_1407cb9c0("rNpcSpeak", 1);
                }
            }
            else
            {
                illust.FUN_1407cba60("lNpc", FUN_141b1c670(pContent->m_unk28));
                illust.FUN_1407cb9c0("lNpcSpeak", 1);
            }
        }
        else
        {
            FUN_141b1c720(illust, pContent->m_myTalk);
        }
    }
    else
    {
        illust.FUN_1407cba60("lNpc", FUN_141b1c670(pContent->m_leftIllust));
        illust.FUN_1407cbbe0("lNpcSpeak", FUN_1401c0090(pContent->m_leftIllust, pContent->m_speakerIllust));
        illust.FUN_1407cba60("rNpc", FUN_141b1c670(pContent->m_rightIllust));
        illust.FUN_1407cbbe0("rNpcSpeak", FUN_1401c0090(pContent->m_rightIllust, pContent->m_speakerIllust));
        FUN_141b1c720(illust, pContent->m_myTalk);
    }
    rPage.FUN_1409eb270("illust", illust);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1c4c0
void UITalkCinematic::FUN_141b1c4c0(ASObj& rPage, const CCinematicContent* pContent)
{
    if (pContent != 0)
        rPage.FUN_1407cba60("imagePlate", CString(pContent->m_imagePlate));
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1c530
int UITalkCinematic::FUN_141b1c530()
{
    if (FUN_14025e7c0()->FUN_14116dd30(0x493e2, 0, 0))
        return 1;
    if (!FUN_14025e7c0()->FUN_14116dcb0(0x493e2, 0, 0))
        m_nextKeyTimer.FUN_140268840();
    else if (m_nextKeyTimer.FUN_140268870(*FUN_1401d7c10(reinterpret_cast<char*>(FUN_1401d3200()) + 0xe0f8)))
        return 1;
    return 0;
}

// @0x141b1c5e0
CString UITalkCinematic::FUN_141b1c5e0(unsigned nNpcId)
{
    return FUN_141b1c670(FUN_1406d6e90()->FUN_140a7d1a0(nNpcId));
}

// @0x141b1c670
CString UITalkCinematic::FUN_141b1c670(const CString& strName)
{
    CString strPath = FUN_140cc2c70(strName);
    if (FUN_141b70ea0(strPath) == 0)
        return "empty";
    return strPath;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1c720
void UITalkCinematic::FUN_141b1c720(ASObj& rPage, int nNpcTalk)
{
    if (nNpcTalk == 0)
        return;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return;
    CString strIllust;
    if (FUN_14036d570(FUN_140166410(), 0x96) && FUN_140b123b0(FUN_1409a8b10())->m_6 != 0)
    {
        unsigned nJob = FUN_141654700(pPC);
        const char* szGender = FUN_141658e60(pPC) == 1 ? "f" : "m";
        strIllust = FUN_141b1c670(FUN_141492f60("{0}_{1}", nJob, CString(szGender)));
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1c960
MS2Ptr<CCinematicComponent> UITalkCinematic::FUN_141b1c960(int nButtonSet)
{
    switch (nButtonSet)
    {
    case 1: return MS2Ptr<CCinematicComponent>(new CEmptyCinematicComponent(this));
    case 2: return MS2Ptr<CCinematicComponent>(new CStopCinematicComponent(this));
    case 3: return MS2Ptr<CCinematicComponent>(new CCloseCinematicComponent(this));
    case 4: return MS2Ptr<CCinematicComponent>(new CNextCinematicComponent(this));
    case 5: return MS2Ptr<CCinematicComponent>(new CSelectableTalkCinematicComponent(this));
    case 6: return MS2Ptr<CCinematicComponent>(new CQuestAcceptCinematicComponent(this));
    case 7: return MS2Ptr<CCinematicComponent>(new CQuestCompleteCinematicComponent(this));
    case 8: return MS2Ptr<CCinematicComponent>(new CQuestProgressCinematicComponent(this));
    case 9: return MS2Ptr<CCinematicComponent>(new CSelectableDistractorCinematicComponent(this));
    case 10: return MS2Ptr<CCinematicComponent>(new CSelectableBeautyCinematicComponent(this));
    case 11: return MS2Ptr<CCinematicComponent>(new CChangeJobComponent(this));
    case 12: return MS2Ptr<CCinematicComponent>(new CUgcSignCinematicComponent(this));
    case 13: return MS2Ptr<CCinematicComponent>(new CPaneltyResolveCinematicComponent(this));
    case 14: return MS2Ptr<CCinematicComponent>(new CTakeBoatCinematicComponent(this));
    case 15: return MS2Ptr<CCinematicComponent>(new CSellUGCMapCinematicComponent(this));
    case 16: return MS2Ptr<CCinematicComponent>(new CRouletteCinematicComponent(this));
    case 17: return MS2Ptr<CCinematicComponent>(new CRouletteSkipCinematicComponent(this));
    case 18: return MS2Ptr<CCinematicComponent>(new CHomeDoctorCinematicComponent(this));
    case 19: return MS2Ptr<CCinematicComponent>(new CCustomSelectableDistractorCinematicComponent(this));
    default:
        FUN_140967100()->FUN_141b1feb0();
        return MS2Ptr<CCinematicComponent>(0);
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1d3d0
int UITalkCinematic::FUN_141b1d3d0()
{
    if (!FUN_140a467d0(&m_30))
        return FUN_1409c17e0(FUN_1409ee290(&m_30)->Invoke("getLowerCutGlobalY"));
    return -1;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1d460
int UITalkCinematic::FUN_141b1d460()
{
    if (!FUN_140a467d0(&m_30))
        return FUN_1409c17e0(FUN_1409ee290(&m_30)->Invoke("getIllustGlobalX"));
    return -1;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1d4f0
UINpcPreviewDialog* FUN_141b1d4f0(unsigned nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spDialog = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (!spDialog.IsNull())
            return dynamic_cast<UINpcPreviewDialog*>(spDialog.get());
    }
    return 0;
}

// ---- UITalkManager: packets and dialogs ----

// The incoming packet: a CInputStream sub-object at +8.
class CInPacket
{
public:
    CInputStream& Stream() { return *reinterpret_cast<CInputStream*>(reinterpret_cast<char*>(this) + 8); }
    void* m_pad_00;
};

// The UI message sent to the swf entity registered for an event id (same shape as functioncubeobject.cpp's).
struct Unk_FcUIMsg
{
    ~Unk_FcUIMsg();                                             // 0x140c30570
    char m_pad[0x50];
};
void FUN_1422e4490(Unk_FcUIMsg* p);
void FUN_1422b82b0(Unk_FcUIMsg* p, const char* psz);
void FUN_1422b7f70(Unk_FcUIMsg* p, int n);
void FUN_1422b8030(Unk_FcUIMsg* p, unsigned n);

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
    char FUN_141094300();
    int FUN_1410937b0();
};
// The emoticon-like component of the npc (PCBase slot 83): kind 2 shows the text.
class Unk_PCBaseComp_a88 : public CPtred
{
public:
    void FUN_14192f8b0(int nState);
    void FUN_14192f8d0(const CString& str);
    void FUN_14192f9f0(int n);
};
// The chat-balloon component (PCBase slot 85).
class Unk_TcBalloon { public: void FUN_1418fb6d0(); };
class Unk_TcFilter { public: void FUN_1416fb380(CStringW& str); void FUN_1416fb340(CStringW& str); };
Unk_TcFilter* FUN_1403b4750();
unsigned FUN_14123c580(PCBase* pNpc);
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
Unk_TcJobMgr* FUN_1401d7a50();

// The dialogs the talk opens (opaque views; the members are bound by VA).
void* FUN_141081ff0(int nId);   void FUN_1419dc510(void* pDlg, int nJob);        // UIJobChangeDialog
void* FUN_14127f000(int nId);   void FUN_1412d9640(void* pDlg, unsigned nNpc, void* pArg);   // maid
void* FUN_140d51900(int nId);   void FUN_1412e3480(void* pDlg, unsigned nNpc, void* pArg);   // manufacture
void* FUN_1413b1bc0(int nId);   void FUN_1419c02e0(void* pDlg, CString strArg);              // item enchant
void* FUN_140c053e0(int nId);                                    // attend gift
int FUN_141924630(void* pDlg);                                   // the attend dialog is floating
__forceinline void Unk_TcVCall0(void* p, int nSlot) { reinterpret_cast<void (*)(void*)>((*reinterpret_cast<void***>(p))[nSlot])(p); }
bool FUN_14102c7a0(void* pDlg, unsigned nValue);
void FUN_141924680(void* pDlg);
unsigned FUN_1407181d0(const CString& str);
class UIItemTreasureMapDialog : public UIObject { public: void FUN_140c55b50(const CString& strArg); };
UIItemTreasureMapDialog* FUN_141b22040(unsigned nUiId);
void* FUN_141296ab0(int nId);   void FUN_140fdcaa0(void* pDlg, const CString& strArg); void FUN_140fdbf50(void* pDlg, unsigned n);   // wedding hall
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
Unk_TcWeddingMgr* FUN_1409023c0();
void* FUN_140938cd0(int nId);                                    // the reward HUD
void FUN_141abf230(void* pHud, __int64 n, int a);
void FUN_141abf450(void* pHud, __int64 n, int a);

// More views for the talk functions.
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::get() const;         // 0x1405a8eb0
template <> Unk_PCBaseComp_aa8* MS2Ptr<Unk_PCBaseComp_aa8>::operator->() const;  // 0x1405a8f40
template <> MS2Ptr<Unk_PCBaseComp_aa8>::~MS2Ptr();                               // 0x1405a8980

int FUN_14067dbc0(void* pAffinity);
// The 8-byte handle of the npc's ride/vehicle record (destructor 0x1409648b0).
void FUN_1409648b0(void* p);
struct Unk_TcHandle8
{
    ~Unk_TcHandle8() { FUN_1409648b0(this); }
    void* FUN_140965790();
    void* FUN_140975bc0();
    void* m_0;
};
void FUN_140963df0(Unk_TcHandle8* pOut, void* pSrc);
void* FUN_1416764a0(PCBase* pActor);
// The equipment handle of the player (destructor 0x1405a85f0).
void FUN_1405a85f0(void* p);
struct Unk_TcEquip
{
    ~Unk_TcEquip() { FUN_1405a85f0(this); }
    void* FUN_1405a8e70() const;
    void* FUN_1405a8ed0() const;
    void* m_0; void* m_8;
};
Unk_TcEquip FUN_141655e10(MyPC* pPC, int nSlot, int nUnused, int nZero);
void* FUN_1411dc7f0(void* p);  void* FUN_14053ec70(void* p);  char FUN_1405471d0(void* p);
void* FUN_14165f460(MyPC* pPC);  int FUN_1412706f0(void* p, int n);
void FUN_141275260(int nMsg, int a, int b);
void FUN_1412751f0(CStringW strMsg, int a, int b);
CStringW FUN_140298ea0(CStringW strKey);

unsigned FUN_141092fa0(PCBase* pNpc);

class Unk_TcAdMgr { public: int FUN_140ad21b0(); void FUN_140ad22d0(); };
Unk_TcAdMgr* FUN_140953f30();
class Unk_TcFlagMgr { public: int FUN_14138c900(int n); };
Unk_TcFlagMgr* FUN_1409331e0();
unsigned FUN_140869420();
void* FUN_141742770(int nId);  void FUN_1418c9cb0(void* pDlg, unsigned nNpc);
void* FUN_14138fd50(int nId);  void FUN_14190f110(void* pDlg, unsigned nId, CString strMsg);
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
unsigned FUN_140857990(MS2Ptr<CTalkScript> spScript, unsigned char nFlags, int nNpc, int nPage);
CCinematicContent* FUN_14085a540(MS2Ptr<CScriptContent>& sp);
void* FUN_141386950(const CString& strDialog);                    // the dialog class record
class Unk_TcStrArray : public ATL::CAtlArray<void*>
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1daf0
unsigned Unk_TalkIdState::FUN_141b1daf0()
{
    if (m_nPos < (int)m_ids.FUN_140186270())
        return m_ids.FUN_1401c0c80(m_nPos);
    return 0;
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b221d0
UITalkManager::CTalkRewardData::~CTalkRewardData()
{
}

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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1ddd0
void UITalkManager::FUN_141b1ddd0(CInPacket& in)
{
    char nMode = in.Stream().vfunc_o8_1();
    if (nMode == 1)
    {
        int nNpcId = in.Stream().vfunc_o8_3();
        m_nFlags = in.Stream().vfunc_o8_1();
        m_nParam = in.Stream().vfunc_o8_3();
        m_nPage = in.Stream().vfunc_o8_3();
        m_nSound = in.Stream().vfunc_o8_3();
        FUN_141b1ff80(nNpcId);
    }
    else if (nMode == 8)
    {
        m_nFlags = in.Stream().vfunc_o8_1();
        int nId = in.Stream().vfunc_o8_3();
        m_nParam = in.Stream().vfunc_o8_3();
        m_nPage = in.Stream().vfunc_o8_3();
        m_nSound = in.Stream().vfunc_o8_3();
        FUN_141b217b0();
        FUN_141b217e0(nId);
        FUN_141b20700();
    }
    else if (nMode == 9)
    {
        m_nFlags = in.Stream().vfunc_o8_1();
        m_nParam = in.Stream().vfunc_o8_3();
        m_nPage = in.Stream().vfunc_o8_3();
        m_nSound = in.Stream().vfunc_o8_3();
        FUN_141b217b0();
        FUN_141b20700();
    }
    else if (nMode == 2)
    {
        m_nFlags = in.Stream().vfunc_o8_1();
        int nId = in.Stream().vfunc_o8_3();
        m_nParam = in.Stream().vfunc_o8_3();
        m_nPage = in.Stream().vfunc_o8_3();
        m_nSound = in.Stream().vfunc_o8_3();
        FUN_141b217b0();
        FUN_141b217e0(nId);
        FUN_141b204d0();
    }
    else if (nMode == 3)
    {
        m_nSubMode = (unsigned char)in.Stream().vfunc_o8_1();
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
        CStringW strScript = in.Stream().vfunc_o8_8();
        CString strSound = in.Stream().vfunc_o8_6();
        CString strIllust = in.Stream().vfunc_o8_6();
        FUN_1403b4750()->FUN_1416fb380(strScript);
        FUN_1403b4750()->FUN_1416fb340(strScript);
        UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
        if (pUi != 0)
            pUi->FUN_141b1a8e0(strScript, strSound, strIllust);
    }
    else if (nMode == 10)
    {
        unsigned nNpcId = in.Stream().vfunc_o8_3();
        unsigned nSub = in.Stream().vfunc_o8_2();
        MS2Ptr<CTalkScript> spScript(new CTalkScript(in));
        if (nSub == 1)
        {
            if (spScript->m_contents.FUN_14078fae0() == 0)
                return;
            Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nNpcId);
            if (pNpc != 0)
            {
                MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = pNpc->vfunc_85();
                if (spBalloon.get() != 0)
                    ((Unk_TcBalloon*)(void*)spBalloon.operator->())->FUN_1418fb6d0();
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
            if (FUN_141b21220() == 0)
                FUN_141b200d0(nNpcId, m_spScript.get());
            else
                FUN_141b20bb0();
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1e8a0
void UITalkManager::FUN_141b1e8a0(CInPacket& in)
{
    int nValue = in.Stream().vfunc_o8_3();
    UISwfEntity* pEntity = FUN_1408e57f0()->FUN_1422b9e20(0x620001f);
    if (pEntity != 0)
    {
        Unk_FcUIMsg kMsg;
        FUN_1422e4490(&kMsg);
        FUN_1422b82b0(&kMsg, "moveMyPC");
        FUN_1422b7f70(&kMsg, nValue);
        FUN_1422b8030(&kMsg, FUN_140967100()->FUN_141b212c0());
        static_cast<IMessageListener*>(pEntity)->OnMessage(0, reinterpret_cast<UIMsg*>(&kMsg));
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1e990
void UITalkManager::FUN_141b1e990(CInPacket& in)
{
    CString strName = in.Stream().vfunc_o8_6();
    Unk_TcNpc* pNpc = FUN_141b21350();
    if (pNpc != 0)
    {
        MS2Ptr<Unk_PCBaseComp_a88> spTag = pNpc->vfunc_83();
        if (spTag.get() != 0)
        {
            spTag->FUN_14192f8b0(2);
            spTag->FUN_14192f8d0(strName);
            Unk_TcVCall0((void*)spTag.operator->(), 2);
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1ea90
void UITalkManager::FUN_141b1ea90(CInPacket& in)
{
    CString strDialog = in.Stream().vfunc_o8_6();
    CString strArg = in.Stream().vfunc_o8_6();
    FUN_141b1eb90(strDialog, strArg);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1eb90
void UITalkManager::FUN_141b1eb90(CString strDialog, CString strArg)
{
    if (strDialog.CompareNoCase("JobChangeDialog") == 0)
    {
        int nJob = atoi(strArg);
        Unk_TcJobRef kJob = FUN_1401d7a50()->FUN_140644880(nJob);
        if (kJob.FUN_14063e990())
            return;
        void* pDlg = FUN_141081ff0(0x4e7c);
        if (pDlg != 0)
            FUN_1419dc510(pDlg, nJob);
        FUN_141b21ae0(strDialog);
    }
    else if (strDialog.CompareNoCase("RouletteDialog") == 0)
    {
        Unk_TcInt kValue;
        kValue.m_n = atoi(strArg);
        COutPacket packet(0x43, 0);
        packet.vfunc_o10_1(0);
        kValue.FUN_1401fcd50(packet);
        FUN_140710590(packet);
    }
    else if (strDialog.CompareNoCase("OpenGambleDialog") == 0)
    {
        FUN_141b21ae0(CString("GambleDialog"));
    }
    else if (strDialog.CompareNoCase("StartGambleDialog") == 0)
    {
        COutPacket packet(0x60, 0);
        packet.vfunc_o10_1(0);
        FUN_140710590(packet);
    }
    else if (strDialog.CompareNoCase("CloseGambleDialog") == 0)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e98);
    }
    else if (strDialog.CompareNoCase("OpenMaidDialog") == 0)
    {
        Unk_TcNpc* pNpc = FUN_141b21350();
        if (pNpc != 0 && pNpc->vfunc_128() != 0)
        {
            FUN_141b21ae0(CString("MaidDialog"));
            void* pDlg = FUN_14127f000(0x4e9d);
            if (pDlg != 0)
                FUN_1412d9640(pDlg, FUN_14123c580(pNpc), FUN_1410947c0(pNpc));
        }
    }
    else if (strDialog.CompareNoCase("CloseMaidDialog") == 0)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e9d);
    }
    else if (strDialog.CompareNoCase("OpenManufactureDialog") == 0)
    {
        Unk_TcNpc* pNpc = FUN_141b21350();
        if (pNpc != 0 && pNpc->vfunc_128() != 0)
        {
            FUN_141b21ae0(CString("ManufactureDialog"));
            void* pDlg = FUN_140d51900(0x4ec0);
            if (pDlg != 0)
                FUN_1412e3480(pDlg, FUN_14123c580(pNpc), FUN_1410947c0(pNpc));
        }
    }
    else if (strDialog.CompareNoCase("CloseManufactureDialog") == 0)
    {
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ec0);
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
            if (FUN_141924630(pDlg) != 0)
                Unk_TcVCall0(pDlg, 0x44);
            if (strArg.IsEmpty())
            {
                FUN_141924680(pDlg);
            }
            else if (FUN_14102c7a0(pDlg, FUN_1407181d0(strArg)) == 0)
            {
                FUN_141b1feb0();
            }
            else
            {
                FUN_141924680(pDlg);
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
        void* pDlg = FUN_141296ab0(0x4f8d);
        if (pDlg != 0)
        {
            unsigned nNpc = (unsigned)FUN_141b212f0();
            Unk_TcWeddingRef kRef = FUN_1409023c0()->FUN_140908c50(nNpc);
            if (kRef.FUN_141847330() != 0)
            {
                FUN_140fdcaa0(pDlg, strArg);
                FUN_140fdbf50(pDlg, kRef.FUN_1409020f0()->m_18);
                FUN_141b21ae0(strDialog);
            }
        }
    }
    else
    {
        FUN_141b21ae0(strDialog);
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1f350
void UITalkManager::FUN_141b1f350(CInPacket& in)
{
    unsigned nCount = in.Stream().vfunc_o8_3();
    for (unsigned __int64 i = 0; i < nCount; i++)
    {
        int nItemId = in.Stream().vfunc_o8_3();
        unsigned nRarity = (unsigned char)in.Stream().vfunc_o8_1();
        int nAmount = in.Stream().vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140524eb0(in.Stream());
            spItem->FUN_14052b340(nAmount);
            if (FUN_1403ed2b0()->FUN_141adc890(0x4e98) == 0)
            {
                if (spItem->FUN_1405258f0() == 0)
                    m_reward.m_items.FUN_140720b80(spItem);
                else
                    m_reward.m_nMeso += nAmount;
            }
            else
            {
                m_reward.m_items.FUN_140720b80(spItem);
            }
            if (spItem->FUN_140525980() == 0)
            {
                void* pHud = FUN_140938cd0(0x4e5d);
                if (pHud != 0)
                    FUN_141abfa10(pHud, MS2Ptr<CItem>(spItem));
            }
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1f620
void UITalkManager::FUN_141b1f620(CInPacket& in)
{
    __int64 nValue = in.Stream().vfunc_o8_4();
    m_reward.m_nMerat += nValue;
    void* pHud = FUN_140938cd0(0x4e5d);
    if (pHud != 0)
        FUN_141abf230(pHud, nValue, 0);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1f6b0
void UITalkManager::FUN_141b1f6b0(CInPacket& in)
{
    __int64 nValue = in.Stream().vfunc_o8_4();
    m_reward.m_nMeso += nValue;
    void* pHud = FUN_140938cd0(0x4e5d);
    if (pHud != 0)
        FUN_141abf450(pHud, nValue, 0);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1f740
void UITalkManager::FUN_141b1f740(CInPacket& in)
{
    m_reward.m_nExp += in.Stream().vfunc_o8_3();
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1f7a0
void UITalkManager::FUN_141b1f7a0(CInPacket& in)
{
    int nValue = in.Stream().vfunc_o8_3();
    char bJackpot = in.Stream().vfunc_o8_1();
    m_reward.m_nAffinity += nValue;
    if (bJackpot != 0)
        m_reward.m_nJackpot = 1;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1f840
void UITalkManager::FUN_141b1f840(CInPacket& in)
{
    unsigned nValue = in.Stream().vfunc_o8_3();
    CStringW strText = in.Stream().vfunc_o8_8();
    void* pDlg = FUN_14138fd50(0x4e7e);
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1fa20
void UITalkManager::FUN_141b1fa20(const CString& strArgs)
{
    FUN_141b1faa0(4, 0x4f03);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1fa60
bool UITalkManager::FUN_141b1fa60()
{
    return FUN_1403ed2d0()->FUN_141bd0cc0() != 0;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1faa0
void UITalkManager::FUN_141b1faa0(int nMode, int nDialogId)
{
    MS2Ptr<UITalkCinematic> spUi(FUN_140a7b2b0(0x4e40));
    if (spUi == 0)
        return;
    unsigned nNpc = (unsigned)FUN_140967100()->FUN_141b212f0();
    spUi->FUN_141b1bfa0();
    if (nDialogId == 0x4e24 && !FUN_141b1fa60())
    {
        FUN_141b1feb0();
        return;
    }
    if (nDialogId == 0x4eee)
    {
        void* pDlg = FUN_141742770(0x4eee);
        if (pDlg != 0)
            FUN_1418c9cb0(pDlg, nNpc);
    }
    Unk_TcNpcRec kRec = FUN_1406cd330(nNpc);
    if (kRec.FUN_140729ad0() != 0)
    {
        UISwfEntity* pEntity = FUN_1408e57f0()->FUN_1422b9e20(0x620001f);
        if (pEntity != 0)
        {
            Unk_FcUIMsg kMsg;
            FUN_1422e4490(&kMsg);
            FUN_1422b82b0(&kMsg, "openDialog");
            FUN_1422b7f70(&kMsg, nDialogId);
            static_cast<IMessageListener*>(pEntity)->OnMessage(0, reinterpret_cast<UIMsg*>(&kMsg));
        }
        if (nMode != 0)
        {
            COutPacket packet(0x23, 0);
            packet.vfunc_o10_1(0);
            packet.vfunc_o10_3(nNpc);
            packet.vfunc_o10_1((unsigned char)nMode);
            FUN_140710590(packet);
        }
    }
    spUi->FUN_141b1bf80(0x620001f);
    FUN_141b1feb0();
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1fcf0
void UITalkManager::FUN_141b1fcf0(unsigned nNpcId)
{
    if (FUN_141b21220() == 0 && FUN_141b211d0())
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
        {
            int nState = pPC->FUN_14166c930();
            bool bAllowed = nState == 1 || nState == 0xb || nState == 0xf || nState == 0x21 || nState == 2;
            if (!bAllowed)
                return;
        }
        Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nNpcId);
        if (pNpc != 0)
        {
            int nUiId = pNpc->FUN_141094170();
            if (nUiId != 0)
            {
                if (FUN_1403ed2b0()->FUN_141adc7f0(nUiId) == 0)
                    return;
            }
            if (nUiId == 0x4e3b)
                FUN_1403ed2b0()->FUN_141adc690(0x4e3b);
            FUN_1403ed2b0()->FUN_141adc170();
            if (FUN_141b218b0(pNpc) == 0)
            {
                if (FUN_140953f30()->FUN_140ad21b0() != 0)
                    FUN_140953f30()->FUN_140ad22d0();
                COutPacket packet(0x22, 0);
                packet.vfunc_o10_1(1);
                packet.vfunc_o10_3(nNpcId);
                FUN_140710590(packet);
            }
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1feb0
void UITalkManager::FUN_141b1feb0()
{
    if (FUN_141b21220() != 0)
    {
        m_nTalking = 0;
        m_nPending = 0;
        if (FUN_141b213c0() == 0)
        {
            COutPacket packet(0x22, 0);
            packet.vfunc_o10_1(0);
            FUN_140710590(packet);
        }
        FUN_141b20210();
        FUN_140a94350()->vfunc_10(0);
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b1ff80
void UITalkManager::FUN_141b1ff80(unsigned nNpcId)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nNpcId);
    if (pPC != 0 && pNpc != 0)
    {
        m_nTalking = 1;
        m_nNpcId = nNpcId;
        pPC->vfunc_94(nNpcId);
        pNpc->vfunc_94(FUN_14123c580(pPC));
        m_spScript = FUN_141b21b90();
        if (m_spScript.get() == 0)
        {
            if (pNpc->FUN_141094170() != 0)
                m_48 = pNpc->FUN_141094200();
        }
        else
        {
            FUN_1408e57f0()->FUN_1422b9fd0(0x6200031);
        }
        pNpc->FUN_141093fa0();
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b200d0
void UITalkManager::FUN_141b200d0(unsigned nNpcId, CTalkScript* pScript)
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nNpcId);
    if (pPC != 0 && pNpc != 0)
    {
        m_nTalking = 1;
        m_nNpcId = nNpcId;
        pPC->vfunc_94(nNpcId);
        pNpc->vfunc_94(FUN_14123c580(pPC));
        m_spScript.AssignRaw(pScript);
        if (m_spScript.get() == 0)
        {
            if (pNpc->FUN_141094170() != 0)
                m_48 = pNpc->FUN_141094200();
        }
        else
        {
            FUN_1408e57f0()->FUN_1422b9fd0(0x6200031);
        }
        pNpc->FUN_141093fa0();
        FUN_140a94350()->vfunc_10(2);
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20210
void UITalkManager::FUN_141b20210()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        bool bBalloon = pPC->vfunc_85().get() != 0;
        if (bBalloon)
            Unk_TcVCall0((void*)pPC->vfunc_85().operator->(), 3);
        Unk_TcHandle8 kRide;
        FUN_140963df0(&kRide, FUN_1416764a0(pPC));
        if (kRide.FUN_140965790() == 0)
        {
            if (pPC->FUN_14166c930() == 0x16)
                pPC->vfunc_59(1, 0, 0, 0);
        }
        else
        {
            if (((PCBase*)kRide.FUN_140975bc0())->FUN_14166c930() != 0x16)
            {
                if (pPC->FUN_14166c930() == 0x16)
                    pPC->vfunc_59(1, 0, 0, 0);
            }
            else
            {
                pPC->vfunc_59(1, 0, 0, 0);
            }
        }
        m_ids.FUN_141b1dac0();
        UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
        if (pUi != 0)
            pUi->FUN_141b1b8b0();
    }
    Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc != 0)
    {
        pNpc->FUN_141094050();
        pNpc->FUN_1410942c0();
    }
    FUN_1403ed2b0()->FUN_141adc2c0();
    m_nTalking = 0;
    m_nNpcId = 0;
    m_spScript = 0;
    m_48 = 0;
    m_nSpecialNpc = 0;
    m_nLastTick = FUN_140869420();
    m_reward.FUN_141b1dbd0();
    FUN_140a94350()->vfunc_10(0);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b204d0
int UITalkManager::FUN_141b204d0()
{
    if (FUN_141b213c0() != 0)
    {
        FUN_141b215b0(1);
        return 1;
    }
    if (m_spScript.get() == 0 || !m_spScript->FUN_140855520())
        m_spScript = FUN_141b21b90();
    if (FUN_141b20bb0() == 0)
    {
        FUN_141b1feb0();
        return 0;
    }
    m_nPending = 0;
    Unk_TcNpc* pNpc = FUN_141b21350();
    bool bHasTag = pNpc != 0 && pNpc->vfunc_83().get() != 0;
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20790
void UITalkManager::FUN_141b20790(int nNpcId)
{
    if (m_nNpcId == nNpcId)
        return;
    Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nNpcId);
    if (pNpc == 0)
        return;
    int nKind = 9;
    if (pNpc->vfunc_128() != 0 && pNpc->FUN_141093800().FUN_1409ee260() != 0)
        nKind = FUN_14067dbc0(pNpc->FUN_141093800().FUN_14067e8c0()) == 0 ? 7 : 8;
    MS2Ptr<CTalkScript> spScript = FUN_140856fa0(FUN_141092fa0(pNpc), nKind);
    if (spScript.get() != 0 && spScript->m_contents.FUN_14078fae0() != 0)
    {
        pNpc->FUN_14166fff0(CStringW(spScript->m_contents.FUN_14078f350(0)->m_name));
        if (FUN_140967100()->FUN_141b21220() == 0 && spScript->m_contents.FUN_14078f350(0)->m_unk20.GetLength() != 0)
            FUN_1411a4f40(FUN_1403ed280(), CString(spScript->m_contents.FUN_14078f350(0)->m_unk20), Unk_TcActorPos(pNpc));
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20ac0
int UITalkManager::FUN_141b20ac0()
{
    FUN_141b21220();
    return 0;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20af0
void UITalkManager::FUN_141b20af0()
{
    if (FUN_141b213c0() == 0 && FUN_141b21220() != 0)
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
        if (pPC == 0 || pNpc == 0)
        {
            FUN_141b1feb0();
        }
        else if (pNpc->FUN_141094300() == 0)
        {
            FUN_141b1feb0();
        }
        else if (FUN_1409331e0()->FUN_14138c900(2) != 0)
        {
            FUN_141b1feb0();
        }
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20bb0
int UITalkManager::FUN_141b20bb0()
{
    Unk_TcNpc* pNpc = FUN_141b21350();
    if (pNpc == 0)
        return 0;
    UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
    if (pUi == 0)
        return 0;
    if (m_spScript.get() == 0)
    {
        if (pNpc->FUN_141094170() == 0)
            return 0;
        pNpc->FUN_141094200();
        pUi->FUN_141b1b8b0();
    }
    else if (m_nPage < m_spScript->m_contents.FUN_14078fae0())
    {
        MS2Ptr<CScriptContent> spContent = m_spScript->m_contents.FUN_14078f350(m_nPage);
        bool bLast = false;
        if (m_nPage == m_spScript->m_contents.FUN_14078fae0() - 1)
            bLast = m_spScript->m_gotoConditionTalkIds.FUN_140186260() == 0;
        return pUi->FUN_141b1b440(FUN_141b21de0(MS2Ptr<CScriptContent>(spContent)), bLast);
    }
    return 1;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20db0
void UITalkManager::FUN_141b20db0(unsigned nNpcId)
{
    if (FUN_141b213c0() == 0)
    {
        if (m_nPending == 0)
        {
            m_nPending = 1;
            m_nSubMode = 0;
            COutPacket packet(0x22, 0);
            packet.vfunc_o10_1(2);
            packet.vfunc_o10_3(nNpcId);
            FUN_140710590(packet);
        }
    }
    else
    {
        FUN_141b215b0(0);
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b20ed0
CStringW UITalkManager::FUN_141b20ed0()
{
    if (!m_spScript.IsNull())
    {
        if (m_nPage < m_spScript->m_contents.FUN_14078fae0())
            return CStringW(m_spScript->m_contents.FUN_14078f350(m_nPage)->m_name);
        return CStringW(L"");
    }
    return CStringW(L"");
}

// @0x141b20fe0
MS2Ptr<CTalkScript> UITalkManager::FUN_141b20fe0()
{
    return m_spScript;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21030
MS2Ptr<CCinematicContent> UITalkManager::FUN_141b21030()
{
    if (!m_spScript.IsNull())
    {
        if (m_nPage < m_spScript->m_contents.FUN_14078fae0())
        {
            MS2Ptr<CScriptContent> spContent = m_spScript->m_contents.FUN_14078f350(m_nPage);
            return MS2Ptr<CCinematicContent>(FUN_141b21de0(MS2Ptr<CScriptContent>(spContent)));
        }
        return MS2Ptr<CCinematicContent>(0);
    }
    return MS2Ptr<CCinematicContent>(0);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21190
void UITalkManager::FUN_141b21190(unsigned char nFlags, int nParam, int nPage)
{
    m_nFlags = nFlags;
    m_nParam = nParam;
    m_nPage = nPage;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b211d0
bool UITalkManager::FUN_141b211d0()
{
    unsigned nNow = FUN_140869420();
    int nLast = m_nLastTick;
    return *FUN_1402056b0(reinterpret_cast<char*>(FUN_1401d3200()) + 0x3730) <= (unsigned)(nNow - nLast);
}

// @0x141b21220
int UITalkManager::FUN_141b21220()
{
    return m_nTalking;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21240
bool UITalkManager::FUN_141b21240(int nNpcId)
{
    if (FUN_141b21220() == 0)
        return false;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return false;
    if (nNpcId == (int)FUN_14123c580(pPC))
        return true;
    return nNpcId == m_nNpcId;
}

// @0x141b212c0
unsigned UITalkManager::FUN_141b212c0()
{
    if (FUN_141b21220() == 0)
        return 0;
    return m_nNpcId;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b212f0
unsigned __int64 UITalkManager::FUN_141b212f0()
{
    Unk_TcNpc* pNpc = FUN_141b21350();
    if (pNpc == 0)
    {
        if (FUN_141b213c0() == 0)
            return 0;
        return (unsigned __int64)(unsigned)m_nSpecialNpc;
    }
    return FUN_141092fa0(pNpc);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21350
Unk_TcNpc* UITalkManager::FUN_141b21350()
{
    unsigned nId = FUN_141b212c0();
    return FUN_1403ed2d0()->FUN_141bd1320(nId);
}

// @0x141b21390
void UITalkManager::FUN_141b21390()
{
    m_nTalking = 0;
    m_nSpecialNpc = 0;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b213c0
unsigned char UITalkManager::FUN_141b213c0()
{
    if (m_nSpecialNpc == 0)
        return m_nFlags & 0x10;
    return 1;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b213f0
unsigned UITalkManager::FUN_141b213f0(MS2Ptr<CTalkScript> spScript, unsigned nSpecialNpc, unsigned nFlags, int nSound)
{
    if (FUN_141b21220() == 0)
    {
        if (!spScript.IsNull())
        {
            m_nTalking = 1;
            m_nSpecialNpc = nSpecialNpc;
            m_spScript = spScript;
            FUN_141b21190(nFlags | 0x10, spScript->m_id, 0);
            if (nSound == 0)
                m_nSound = FUN_141b21d70();
            else
                m_nSound = nSound;
            FUN_1408e57f0()->FUN_1422b9fd0(0x6200031);
            return 1;
        }
        return 0;
    }
    FUN_1412751f0(FUN_140298ea0(CStringW(L"s_error_talk_already_talking")), 1, 1);
    return 0;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b215b0
void UITalkManager::FUN_141b215b0(int bSamePage)
{
    UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
    if (pUi != 0)
    {
        if (bSamePage == 0)
        {
            m_nPage++;
            m_nSound = FUN_141b21d70();
        }
        if (m_spScript.get() != 0)
        {
            if (m_nPage < m_spScript->m_contents.FUN_14078fae0())
            {
                MS2Ptr<CScriptContent> spContent = m_spScript->m_contents.FUN_14078f350(m_nPage);
                bool bLast = false;
                if (m_nPage == m_spScript->m_contents.FUN_14078fae0() - 1)
                    bLast = m_spScript->m_gotoConditionTalkIds.FUN_140186260() == 0;
                pUi->FUN_141b1b440(FUN_141b21de0(MS2Ptr<CScriptContent>(spContent)), bLast);
            }
            else
            {
                FUN_141b1feb0();
            }
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21810
unsigned UITalkManager::FUN_141b21810(int nIndex)
{
    if ((unsigned __int64)(__int64)nIndex < m_ids.m_ids.FUN_140186270())
        return m_ids.m_ids.FUN_140184510(nIndex);
    return 0;
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b218b0
int UITalkManager::FUN_141b218b0(Unk_TcNpc* pNpc)
{
    if (pNpc == 0)
        return 0;
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    if (pNpc->FUN_1410937b0() != 0x23)
        return 0;
    int nNotice;
    Unk_TcEquip kEquip = FUN_141655e10(pPC, 6, 0, 0);
    if (kEquip.FUN_1405a8e70() == 0)
    {
        nNotice = 0x84;
    }
    else
    {
        if (FUN_1411dc7f0(kEquip.FUN_1405a8ed0()) != 0
            && FUN_1405471d0(FUN_14053ec70(FUN_1411dc7f0(kEquip.FUN_1405a8ed0()))) != 0)
            return 0;
        nNotice = FUN_1412706f0(FUN_14165f460(pPC), 0) == 0 ? 0x82 : 0x83;
    }
    if (nNotice != 0)
        FUN_141275260(nNotice, 1, 1);
    return 1;
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
            FUN_1403ed2b0()->FUN_141adc530(m_openedDialogs.FUN_140184510(i));
        m_openedDialogs.FUN_1402c2830();
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21ae0
void UITalkManager::FUN_141b21ae0(const CString& strDialog)
{
    void* pClass = FUN_141386950(strDialog);
    if (pClass != 0)
    {
        UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
        unsigned nId = reinterpret_cast<unsigned (*)(void*)>((*reinterpret_cast<void***>(pClass))[0x180 / 8])(pClass);
        if (pUi == 0 || pUi->FUN_141b1bfc0() == 0)
            m_openedDialogs.FUN_1401855a0(nId);
        else
            FUN_1403ed2b0()->FUN_141adc530(nId);
    }
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21b90
MS2Ptr<CTalkScript> UITalkManager::FUN_141b21b90()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return MS2Ptr<CTalkScript>(0);
    Unk_TcNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(m_nNpcId);
    if (pNpc == 0)
        return MS2Ptr<CTalkScript>(0);
    if ((m_nFlags & 8) != 0)
        return FUN_140856c50(FUN_141092fa0(pNpc), 0);
    if ((m_nFlags & 4) != 0)
        return FUN_1408564b0(m_ids.m_ids.FUN_140184510(0), m_nParam);
    if (FUN_140855cd0(m_nFlags) != 0)
        return FUN_140856820(FUN_141092fa0(pNpc), m_nParam);
    if ((m_nFlags & 1) != 0)
        return FUN_140856c50(FUN_141092fa0(pNpc), 1);
    return MS2Ptr<CTalkScript>(0);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21d70
unsigned UITalkManager::FUN_141b21d70()
{
    return FUN_140857990(FUN_141b20fe0(), m_nFlags, m_nSpecialNpc, m_nPage);
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21de0
CCinematicContent* FUN_141b21de0(MS2Ptr<CScriptContent> spContent)
{
    if (!spContent.IsNull())
    {
        if (spContent->vfunc_1() == 0)
            return FUN_14085a540(spContent);
        return 0;
    }
    return 0;
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

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b21f70
unsigned __int64 FUN_141b21f70(int nDialog, const CString& strMode, const CString& strKind)
{
    if (nDialog == 0x4e23)
        return 3;
    if (nDialog == 0x4eee || nDialog == 0x4f03)
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
    if (nDialog == 0x4e24)
        return 3;
    return 0;
}

// MS2-FUNCTIONAL: frame/temp layout and unit-local helper types differ from the exe; behaviour equivalent
// @0x141b22040
UIItemTreasureMapDialog* FUN_141b22040(unsigned nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spDialog = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (!spDialog.IsNull())
            return dynamic_cast<UIItemTreasureMapDialog*>(spDialog.get());
    }
    return 0;
}
