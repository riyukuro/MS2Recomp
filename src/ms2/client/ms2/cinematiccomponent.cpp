// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Talk cinematic components (NPC dialogue pages).
// MS2-UNIT: client\ms2\cinematiccomponent.cpp
// MS2-RANGE: 0x14107ce50-0x141083230 .text$mn
// MS2-RANGE: 0x1400e50a0-0x1400e53c0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cinematiccomponent.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cinematiccomponent.h"
static CString s_sortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/cinematiccomponent_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_nextKey = "cinematic_nextkey";          // @0x1400e5330
static CString s_getItem = "cinematic_getItem";          // @0x1400e5360
static CString s_deadPanelty = "PC_cure_deadPanelty";    // @0x1400e5390

// ---- unit-local declarations; Unk_ names and member names are invented ----

// The npc actor of the talk (PCBase slot 128 is the "has a display name" test).
class Unk_CinNpc : public PCBase
{
public:
    virtual void vfunc_124(); virtual void vfunc_125(); virtual void vfunc_126(); virtual void vfunc_127();
    virtual int vfunc_128();
    CStringW FUN_141093310();                                   // npc name
};
int FUN_141092fa0(Unk_CinNpc*);                                 // npc id

// The affinity record of the npc (found through FUN_141093800).
class Unk_CinAffinity { public: char m_pad_00[0x54]; int m_54; };   // the exe reads +0x54 (0x14107d760: add rax, 0x54)
MS2_CHECK_OFFSET(Unk_CinAffinity, m_54, 0x54);
class Unk_CinAffinityPtr
{
public:
    Unk_CinAffinityPtr(const Unk_CinAffinityPtr&);
    ~Unk_CinAffinityPtr();                                      // 0x14067e620
    Unk_CinAffinity* FUN_1409ee260() const;                     // get
    Unk_CinAffinity* FUN_14067e8c0() const;                     // operator->
private:
    void* m_0; Unk_CinAffinity* m_p;
};
struct Unk_CinNpcView { Unk_CinAffinityPtr FUN_141093800(); };   // npc member (this=rcx, hidden return=rdx)

// The reward block of the open talk (inside the talk manager).
class Unk_CinRewardItems
{
public:
    size_t FUN_140720ca0() const;                               // GetCount
    MS2Ptr<CItem>& FUN_140a69ee0(size_t i);                     // checked GetAt
private:
    void* m_data; size_t m_count; size_t m_max; size_t m_grow;
};
class Unk_CinReward
{
public:
    void FUN_141b1dbd0();                                       // clear
    void* m_0; void* m_8; void* m_10;
    Unk_CinRewardItems m_items;                                 // +0x18
    __int64 m_meso;                                             // +0x38
    __int64 m_exp;                                              // +0x40
    int m_mood;                                                 // +0x48
    int m_affinityExp;                                          // +0x4c
    int m_affinityBonus;                                        // +0x50
    int m_54;
};

// The talk manager (FUN_140967100): the state of the open dialogue.
class Unk_CinTalk
{
public:
    void FUN_141b1feb0();                                       // end the talk
    void FUN_141b20db0(int nSelect);                            // next page / select
    void FUN_141b20210();
    int FUN_141b213c0();
    int FUN_141b212f0();                                        // npc id
    int FUN_141b212c0();                                        // npc id (packets)
    Unk_CinNpc* FUN_141b21350();                                // npc actor
    int FUN_141b21860();                                        // quest count
    int FUN_141b21810(int i);                                   // quest id
    Unk_CinReward* FUN_141082d60() { return &m_reward; }        // @0x141082d60
    unsigned char FUN_141082ec0() { return m_flags; }           // @0x141082ec0
public:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48;
    unsigned char m_flags;                                      // +0x50
    char m_51; short m_52; int m_54; void* m_58;
    Unk_CinReward m_reward;                                     // +0x60
};
MS2_CHECK_OFFSET(Unk_CinTalk, m_reward, 0x60);
Unk_CinTalk* FUN_140967100();

class UITalkCinematic : public UIObject
{
public:
    void FUN_141b1bad0();
    void FUN_141b1bb80();
    void FUN_141b1bc30();
    void FUN_141b1beb0(CString key);
};
UITalkCinematic* FUN_140a7b2b0(int nId);

// The chat/name filter.
class Unk_CinNameFilter
{
public:
    void FUN_1416fb400(CStringW& name, Unk_CinNpc* npc);
    void FUN_1416fb340(CStringW& text);
};
Unk_CinNameFilter* FUN_1403b4750();

// The key name table and settings.
class Unk_CinKeyNames
{
public:
    CStringW FUN_14142d220(int nKey);
    CStringW FUN_14142d760(int nId, int nVariant);
};
Unk_CinKeyNames* FUN_1409331f0();
class Unk_CinSettings { public: };
Unk_CinSettings* FUN_1409a8b10();
unsigned char* FUN_140a58500(Unk_CinSettings*);

// Local player, world and ui manager.
class Unk_CinMapData { public: };
class Unk_CinMapPtr
{
public:
    ~Unk_CinMapPtr();                                           // 0x1408850f0
    Unk_CinMapData* FUN_140885340() const;
private:
    void* m_0; Unk_CinMapData* m_p;
};
int FUN_1403754f0(Unk_CinMapData*);
class Unk_CinWorld
{
public:
    MyPC* FUN_141bd0cc0();                                      // local player
    Unk_CinMapPtr FUN_141bd30a0();                              // current map
};
Unk_CinWorld* FUN_1403ed2d0();
class UIJobChangeDialog : public UIObject { public: };
class Unk_CinUiManager
{
public:
    void FUN_141adc5d0(int nId);                                // open
    void FUN_141adc750(int nId);
    int FUN_141adc9e0(int nId);                                 // is open
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                    // lookup
};
Unk_CinUiManager* FUN_1403ed2b0();
int FUN_1419dc530(UIJobChangeDialog*);
int FUN_14151f6e0();
void FUN_14151f200();
void FUN_14151f460(int);
int FUN_141661aa0(MyPC*);                                       // level
int FUN_141527e00(MyPC*);
int FUN_141529620(MyPC*);
__int64 FUN_141656ad0(MyPC*);
int FUN_141654700(MyPC*);                                       // job code
class Unk_CinPriceTable { public: int FUN_140675730(short nJob, int nLevel, int nMap); };
Unk_CinPriceTable* FUN_1401c0db0();
extern __int64 DAT_143ab2898;
class Unk_CinBgm { public: void FUN_1422b9fd0(int nId); };
Unk_CinBgm* FUN_1408e57f0();

class Unk_CinSvc { public: __int64 FUN_1410c8030(int nId, int nFlag); void FUN_1410ccc00(int nId, int, int); void vfunc_1(); };
class Unk_CinSvcPtr
{
public:
    Unk_CinSvcPtr(Unk_CinSvc* p);                               // 0x1401cd0b0
    ~Unk_CinSvcPtr();                                           // 0x1401cd150
    Unk_CinSvc* FUN_1401cd1a0() const;                          // operator->
private:
    Unk_CinSvc* m_p;
};
class Unk_CinFramework { public: void* m_0; };
extern Unk_CinFramework DAT_143b059e8;
Unk_CinSvc* FUN_1401cd040(Unk_CinFramework*);
int FUN_141bd3060(Unk_CinWorld*);
int FUN_1408a0890(int, int, int*);

// Quest helpers.
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
class Unk_CinQuestState { public: int FUN_140745630(int nQuestId); int FUN_140745590(int nQuestId); };
class Unk_CinQuestGlobal { public: void* m_0; void* m_8; Unk_CinQuestState m_state; };
Unk_CinQuestGlobal* FUN_140764020();
int FUN_14074b050(CQuestData*);
int FUN_14074b840(int nQuestId);
int FUN_14074b950(int nQuestId);
int FUN_140748050(CQuestData::QuestRewardItem*, int);
char FUN_1407640c0(CQuestData*);
__int64 FUN_140761ba0(int, int);
__int64 FUN_140761cc0(int, int);
__int64 FUN_140761d80(int, int);
__int64 FUN_140761de0(int, int);
__int64 FUN_140761c00(int, int);
__int64 FUN_140761d20(int, int);
int FUN_140761ea0(int, int);
int FUN_140761c60(int, int);
int FUN_14053feb0(int);

// Strings, packets and misc.
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1401aa6a0(int nId);
CStringW FUN_14028b8e0(const CStringW&);
CStringW FUN_1409404f0(__int64);
CStringW FUN_1408116a0(int nStringId, const int&);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW&, const CStringW&);
CStringW FUN_1416e4df0(int nQuestId);
int FUN_1416e6100(int nQuestId, int);
void FUN_141275260(int, int, int);
void FUN_1410819f0(const CString& key);
void FUN_141276180(const CString&, const CString&);
void FUN_140710590(COutPacket&);
void FUN_141415450(const CString&, MS2Ptr<CItem>, int, int, int);
void FUN_1401fdad0(int*, COutPacket&);
void FUN_140d73bc0(int, int, IMessageListener*, CStringW);
class Unk_CinSkin { public: CStringW FUN_141811980(int, int); };
Unk_CinSkin* FUN_1401a9d70();

class CMsgBoxData : public CPtred
{
public:
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);
    int FUN_141a02e90(int, unsigned) const;
    bool FUN_141a02e10(int, unsigned) const;
    void FUN_140534050(int);
    void FUN_140f73320(bool);
    unsigned char m_pad[0x2a0 - 0x18];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);

// Talk scripts (FUN_140856c50(npc id, 0)).
class Unk_CinScriptContent { public: virtual void vfunc_0(); virtual int vfunc_1(); };
struct Unk_CinScriptContentPtr
{
    Unk_CinScriptContent* FUN_14078f3d0() const;                // operator->
    void* m_0; void* m_p;
};
class Unk_CinScriptContentArray
{
public:
    size_t FUN_14078fae0() const;                               // GetCount
    const Unk_CinScriptContentPtr& FUN_14078f350(size_t i) const;   // GetAt
private:
    void* m_pData; size_t m_nSize;
};
class Unk_CinTalkScript
{
public:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58; void* m_60;
    Unk_CinScriptContentArray m_contents;                       // +0x68
};
MS2_CHECK_OFFSET(Unk_CinTalkScript, m_contents, 0x68);
struct Unk_CinTalkScriptPtr
{
    ~Unk_CinTalkScriptPtr();                                    // 0x14078f140
    Unk_CinTalkScript* FUN_14078f3a0() const;                   // get
    Unk_CinTalkScript* FUN_14085a610() const;                   // operator->
    void* m_0; void* m_p;
};
Unk_CinTalkScriptPtr FUN_140856c50(int nNpcId, int n);
CCinematicContent* FUN_14085a540(const Unk_CinScriptContentPtr&);   // cast to the cinematic content

// ---- the icon entry and its array ----
// @0x1410824b0
Unk_CinIcon::Unk_CinIcon(const Unk_CinIcon& o) : m_icon(o.m_icon), m_text(o.m_text) {}
// @0x141082510
Unk_CinIcon::Unk_CinIcon() {}
// @0x1410825d0
Unk_CinIcon::~Unk_CinIcon() {}
// @0x141082c00
void* FUN_141082c00(void* p, unsigned flags)
{
    static_cast<Unk_CinIcon*>(p)->Unk_CinIcon::~Unk_CinIcon();
    if (flags & 1)
        operator delete(p, sizeof(Unk_CinIcon));
    return p;
}
// @0x141082cf0
static void FUN_141082cf0(Unk_CinIcon* pData, size_t nCount) throw()
{
    for (size_t i = 0; i < nCount; i++)
        FUN_141082c00(&pData[i], 0);
}
// @0x141082390
Unk_CinIconArray::Unk_CinIconArray() : m_pData(0), m_nSize(0), m_nMaxSize(0), m_nGrowBy(0) {}
// @0x141082570
Unk_CinIconArray::~Unk_CinIconArray() throw()
{
    if (m_pData != 0) {
        FUN_141082cf0(m_pData, m_nSize);
        free(m_pData);
    }
}
__declspec(noreturn) void FUN_140159b70(long hr);                // AtlThrow
// @0x141083080
void FUN_141083080(void* pDst, void* pSrc, size_t n)
{
    ATL::Checked::memmove_s(pDst, n * sizeof(Unk_CinIcon), pSrc, n * sizeof(Unk_CinIcon));
}
// MS2-FUNCTIONAL: ternary temporaries of the allocation size land in different stack slots
// @0x141082ed0
bool Unk_CinIconArray::GrowBuffer(size_t nNewSize)
{
    if (nNewSize > m_nMaxSize) {
        if (m_pData == 0) {
            size_t nAlloc = (size_t)m_nGrowBy > nNewSize ? (size_t)m_nGrowBy : nNewSize;
            m_pData = static_cast<Unk_CinIcon*>(calloc(nAlloc, sizeof(Unk_CinIcon)));
            if (m_pData == 0)
                return false;
            m_nMaxSize = nAlloc;
        } else {
            size_t nGrow = (size_t)m_nGrowBy;
            if (nGrow == 0 && (nGrow = m_nMaxSize / 2, nNewSize - m_nMaxSize > nGrow))
                nGrow = nNewSize - m_nMaxSize;
            size_t nAlloc;
            nAlloc = nNewSize < m_nMaxSize + nGrow ? m_nMaxSize + nGrow : nNewSize;
            Unk_CinIcon* pNew = static_cast<Unk_CinIcon*>(calloc(nAlloc, sizeof(Unk_CinIcon)));
            if (pNew == 0)
                return false;
            FUN_141083080(pNew, m_pData, m_nSize);
            free(m_pData);
            m_pData = pNew;
            m_nMaxSize = nAlloc;
        }
    }
    return true;
}
// @0x141082c40
size_t Unk_CinIconArray::Add(const Unk_CinIcon& e)
{
    size_t iElement = m_nSize;
    if (iElement >= m_nMaxSize) {
        bool bOk = GrowBuffer(iElement + 1);
        if (!bOk)
            FUN_140159b70(0x8007000e);
    }
    new (m_pData + iElement) Unk_CinIcon(e);
    m_nSize++;
    return iElement;
}
// @0x141082d50
size_t Unk_CinIconArray::GetCount() const { return m_nSize; }
// @0x141082640
Unk_CinIcon& Unk_CinIconArray::GetAt(size_t i) const
{
    if (i >= m_nSize)
        FUN_140159b70(0x80070057);
    return m_pData[i];
}

// ---- CCinematicComponent ----
// @0x14107ce50
CCinematicComponent::CCinematicComponent(UITalkCinematic* pOwner)
{
    m_pOwner = pOwner;
    m_nStarted = 0;
}
// @0x14107cec0
CCinematicComponent::~CCinematicComponent() {}
// @0x141083070
void CCinematicComponent::vfunc_1(int) {}
// @0x14107cf00
int CCinematicComponent::vfunc_2(int nMsg)
{
    if (nMsg == 0x493e2) {
        if (m_nStarted != 0)
            return 1;
        m_nStarted = 1;
    }
    if (nMsg == 1) {
        FUN_140967100()->FUN_141b1feb0();
        return 1;
    }
    else if (nMsg == 0x79)
        m_pOwner->FUN_141b1bad0();
    else if (nMsg == 0x7e)
        m_pOwner->FUN_141b1bb80();
    return 0;
}
// @0x141082d80
int CCinematicComponent::vfunc_3() { return 0; }
// @0x1410830c0
void CCinematicComponent::vfunc_4(MS2Ptr<CCinematicContent> spContent) { m_spContent = spContent; }
// @0x14107cf90
void CCinematicComponent::vfunc_5(ASObj& obj)
{
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc != 0) {
        CStringW name(m_spContent->m_name);
        int nNpcId = FUN_140967100()->FUN_141b212f0();
        CStringW text;
        if (m_spContent->m_speakerNpc != 0) {
            text = FUN_1401aa6a0(m_spContent->m_speakerNpc);
        } else if (m_spContent->m_myTalk != 0) {
            text = pc->vfunc_77();
        } else if (m_spContent->m_otherNpcTalk != 0) {
            text = FUN_1401aa6a0(m_spContent->m_otherNpcTalk);
        } else {
            Unk_CinNpc* pNpc = FUN_140967100()->FUN_141b21350();
            if (pNpc != 0 && pNpc->vfunc_128() != 0) {
                FUN_1403b4750()->FUN_1416fb400(name, pNpc);
                text = pNpc->FUN_141093310();
            } else {
                text = FUN_1401aa6a0(nNpcId);
            }
        }
        FUN_1403b4750()->FUN_1416fb340(name);
        obj.FUN_1407cbb20("npc", CStringW(text));
        obj.FUN_1407cbb20("script", CStringW(name));
        obj.FUN_1407cba60("movie", CString(m_spContent->m_movie));
        if (m_spContent->m_screenEffectMovie.GetLength() != 0) {
            ASObj effect(2);
            effect.FUN_1407cba60("movie", CString(m_spContent->m_screenEffectMovie));
            effect.FUN_1407cba60("action", CString(m_spContent->m_screenEffectAction));
            effect.FUN_1409c0d20("value", m_spContent->m_screenEffectValue);
            obj.FUN_1409eb270("screenEffect", effect);
        }
    }
}
// @0x14107d4b0
void CCinematicComponent::FUN_14107d4b0(const ATL::CAtlArray<CQuestData::QuestRewardItem>& rewards, ASObj& obj)
{
    for (size_t i = 0; i < rewards.GetCount(); i++) {
        int nItemId = rewards[i].m_itemId;
        int nRarity = rewards[i].m_count;      // the shared layout names +0x1c m_count; it is the rarity here
        int nCount = rewards[i].m_job;         // and +0x20 is the count
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_14052b130(nItemId, nRarity, 0) != 0) {
            spItem->FUN_140526c70(nCount);
            CString key;
            key.Format("%s_%d", (const char*)m_pOwner->vfunc_1(), i);
            FUN_141415450(key, spItem, 0, 0x11, 0x800);
            CString attr;
            attr.Format("reward%d", i + 1);
            FUN_1410819f0(key);
            obj.FUN_1407cba60(attr, CString(key));
        }
    }
}
// MS2-FUNCTIONAL: local slot layout / temp ordering of the reward-building branches differs from the exe
// @0x14107d760
unsigned CCinematicComponent::FUN_14107d760(ASObj& obj)
{
    unsigned nRet;
    if (m_spContent->m_openTalkReward == 0) {
        nRet = 0;
    } else {
        ASObj reward(2);
        reward.FUN_1407cbb20("title", FUN_14028de60(0x94b));
        Unk_CinReward* pReward = FUN_140967100()->FUN_141082d60();
        unsigned bAny = 0;
        if (pReward->m_exp != 0) {
            bAny = 1;
            reward.FUN_1407cbb20("exp", FUN_1409404f0(pReward->m_exp));
        }
        if (pReward->m_meso != 0) {
            bAny = 1;
            reward.FUN_1407cbb20("meso", FUN_1409404f0(pReward->m_meso));
        }
        if (pReward->m_mood != 0) {
            reward.FUN_1407cbb20("title", FUN_14028de60(0x7c1));
            bAny = 1;
            CStringW mood(L"");
            if (pReward->m_mood < 1) {
                if (pReward->m_mood < 0) {
                    int nAbs = abs(pReward->m_mood);
                    mood = FUN_1408116a0(0x7c5, nAbs);
                }
            } else {
                mood = FUN_1408116a0(0x7c4, pReward->m_mood);
            }
            reward.FUN_1407cbb20("mood", CStringW(mood));
        }
        if (pReward->m_affinityExp != 0) {
            reward.FUN_1407cbb20("title", FUN_14028de60(0x7c1));
            bAny = 1;
            CStringW affinity(L"");
            Unk_CinNpc* pNpc = FUN_140967100()->FUN_141b21350();
            if (pNpc != 0) {
                Unk_CinAffinity* pAffinity = reinterpret_cast<Unk_CinNpcView*>(pNpc)->FUN_141093800().FUN_1409ee260();
                if (pAffinity != 0) {
                    if (pReward->m_affinityBonus == 0) {
                        affinity = FUN_1408116a0(0x7c2, pReward->m_affinityExp);
                    } else {
                        affinity = FUN_140656190(L"{0} {1}", FUN_1408116a0(0x7c2, pReward->m_affinityExp),
                                                 FUN_1408116a0(0x7c3, reinterpret_cast<Unk_CinNpcView*>(pNpc)->FUN_141093800().FUN_14067e8c0()->m_54));
                    }
                }
            }
            reward.FUN_1407cbb20("affinityExp", CStringW(affinity));
        }
        for (size_t i = 0; i < pReward->m_items.FUN_140720ca0(); i++) {
            bAny = 1;
            MS2Ptr<CItem> spItem = pReward->m_items.FUN_140a69ee0(i);
            CString key;
            key.Format("%s_%d", (const char*)m_pOwner->vfunc_1(), i + 1);
            FUN_141415450(key, spItem, 0, 0x11, 0x800);
            CString attr;
            attr.Format("reward%d", i + 1);
            reward.FUN_1407cba60(attr, CString(key));
            FUN_1410819f0(key);
        }
        pReward->FUN_141b1dbd0();
        if (bAny != 0)
            obj.FUN_1409eb270("reward", reward);
        nRet = bAny;
    }
    return nRet;
}
// MS2-FUNCTIONAL: an extra int local (zero) and the ternary temp slots of the key-variant selection are not reproduced
// @0x14107dfa0
CStringW CCinematicComponent::FUN_14107dfa0(int nStringId)
{
    CStringW text = FUN_14028de60(nStringId);
    FUN_1403b4750()->FUN_1416fb340(text);
    CStringW keyConfirm = FUN_1409331f0()->FUN_14142d220(1);
    CStringW keyNext = FUN_1409331f0()->FUN_14142d220(0x39);
    int nVariant = *FUN_140a58500(FUN_1409a8b10()) != 0 ? 2 : 0;
    if (nVariant == 2)
        text.Replace(keyConfirm, FUN_1409331f0()->FUN_14142d760(0x49409, 2));
    text.Replace(keyNext, FUN_1409331f0()->FUN_14142d760(0x493e2, nVariant));
    return text;
}

// ---- CNextCinematicComponent ----
// @0x14107e190
CNextCinematicComponent::CNextCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x14107e1d0
CNextCinematicComponent::~CNextCinematicComponent() {}
// @0x14107e200
int CNextCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    if (nMsg == 0x493e2) {
        FUN_141276180(s_nextKey, "");
        if (m_nReward != 0)
            FUN_141276180(s_getItem, "");
        FUN_140967100()->FUN_141b20db0(0);
        return 1;
    }
    return 0;
}
// @0x141082de0
int CNextCinematicComponent::vfunc_3() { return 4; }
// @0x14107e2d0
void CNextCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    m_nReward = FUN_14107d760(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d5));
}

// ---- CCloseCinematicComponent ----
// @0x14107e350
CCloseCinematicComponent::CCloseCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x14107e390
CCloseCinematicComponent::~CCloseCinematicComponent() {}
// @0x14107e3c0
int CCloseCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    if (nMsg == 0x493e2) {
        if (m_nReward != 0)
            FUN_141276180(s_getItem, "");
        if (FUN_140967100()->FUN_141b213c0() != 0)
            FUN_140967100()->FUN_141b20210();
        else
            FUN_140967100()->FUN_141b20db0(0);
        return 1;
    }
    return 0;
}
// @0x141082d90
int CCloseCinematicComponent::vfunc_3() { return 3; }
// @0x14107e480
void CCloseCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    m_nReward = FUN_14107d760(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d6));
}

// ---- CDistractorCinematicComponent ----
// @0x14107e500
CDistractorCinematicComponent::CDistractorCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x14107e540
CDistractorCinematicComponent::~CDistractorCinematicComponent() {}
// @0x14107e570
int CDistractorCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    if (nMsg == 0x493e2) {
        FUN_141276180(s_nextKey, "");
        m_pOwner->FUN_141b1bc30();
    }
    else
        return 0;
    return 1;
}
// @0x141082db0
int CDistractorCinematicComponent::vfunc_3() { return 0; }
// @0x14107e600
void CDistractorCinematicComponent::vfunc_6(const Unk_CinIconArray& icons, ASObj& obj)
{
    ASArray distractors(2);
    for (size_t i = 0; i < icons.GetCount(); i++) {
        ASObj item(2);
        CStringW text(icons.GetAt(i).m_text);
        FUN_1403b4750()->FUN_1416fb400(text, FUN_140967100()->FUN_141b21350());
        FUN_1403b4750()->FUN_1416fb340(text);
        item.FUN_1407cba60("iconClass", CString(icons.GetAt(i).m_icon));
        item.FUN_1407cbb20("text", CStringW(text));
        distractors.FUN_1422bc050(item.FUN_1422bb870());
    }
    obj.FUN_1409eb1d0("distractor", distractors);
}

// ---- CQuestAcceptCinematicComponent ----
// @0x14107e7f0
CQuestAcceptCinematicComponent::CQuestAcceptCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x14107e830
CQuestAcceptCinematicComponent::~CQuestAcceptCinematicComponent() {}
// @0x14107e860
int CQuestAcceptCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    if (nMsg == 0x493e2) {
        if (FUN_140764020()->m_state.FUN_140745630(m_spContent->m_questId) != 0)
            return 1;
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(m_spContent->m_questId);
        if (bool(spQuest.get() != 0) && spQuest->m_require.m_unrequireGroup.GetCount() > 0) {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14028b8e0(L"s_alliance_quest_unreq_group_warn"), 0, L"");
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &CQuestAcceptCinematicComponent::FUN_14107ec40));
            spBox->FUN_140534050(m_spContent->m_questId);
            spBox->FUN_140f73320(m_spContent->m_redirect != 0);
            FUN_140d73c60(spBox);
            return 1;
        }
        FUN_14107ecc0(m_spContent->m_questId, m_spContent->m_redirect != 0);
        return 1;
    }
    return 0;
}
// @0x141082e00
int CQuestAcceptCinematicComponent::vfunc_3() { return 6; }
// @0x14107ebd0
void CQuestAcceptCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d3));
}
// @0x14107ec40
bool CQuestAcceptCinematicComponent::FUN_14107ec40(int nButton, const CMsgBoxData& data)
{
    if (nButton != 0) {
        FUN_140967100()->FUN_141b1feb0();
        return true;
    }
    {
        int nQuestId = data.FUN_141a02e90(0, 0);
        bool bRedirect = data.FUN_141a02e10(1, 0);
        FUN_14107ecc0(nQuestId, bRedirect);
    }
    return true;
}
// @0x14107ecc0
void CQuestAcceptCinematicComponent::FUN_14107ecc0(int nQuestId, bool bRedirect)
{
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc != 0) {
        COutPacket pkt(0x29, 0);
        pkt.Encode1(2);
        pkt.Encode4(nQuestId);
        pkt.Encode4(FUN_140967100()->FUN_141b212c0());
        FUN_140710590(pkt);
    }
    if (bRedirect && FUN_14074b840(nQuestId) != 0) {
        COutPacket pkt(0x22, 0);
        pkt.Encode1(7);
        pkt.Encode4(nQuestId);
        pkt.Encode2(2);
        FUN_140710590(pkt);
        return;
    }
    FUN_140967100()->FUN_141b20db0(0);
}

// ---- CQuestProgressCinematicComponent ----
// @0x14107edf0
CQuestProgressCinematicComponent::CQuestProgressCinematicComponent(UITalkCinematic* pOwner) : CCloseCinematicComponent(pOwner) {}
// @0x14107ee30
CQuestProgressCinematicComponent::~CQuestProgressCinematicComponent() {}
// @0x14107ee60
int CQuestProgressCinematicComponent::vfunc_2(int nMsg)
{
    if (m_nStarted != 0)
        return 0;
    if (nMsg == 0x493e2) {
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(m_spContent->m_questId);
        if (bool(spQuest.get() != 0) && spQuest->m_318.m_0 != 0) {
            COutPacket pkt(0x29, 0);
            pkt.Encode1(0x12);
            pkt.Encode4(m_spContent->m_questId);
            FUN_140710590(pkt);
        }
        FUN_140967100()->FUN_141b20db0(0);
        return 1;
    }
    return 0;
}
// @0x141082e20
int CQuestProgressCinematicComponent::vfunc_3() { return 8; }

// ---- CQuestCompleteCinematicComponent ----
// @0x14107ef90
CQuestCompleteCinematicComponent::CQuestCompleteCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x14107efd0
CQuestCompleteCinematicComponent::~CQuestCompleteCinematicComponent() {}
// @0x14107f000
int CQuestCompleteCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    if (nMsg == 0x493e2) {
        int nQuestId = m_spContent->m_questId;
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
        if (!spQuest)
            return 1;
        if (FUN_140764020()->m_state.FUN_140745590(m_spContent->m_questId) != 0)
            return 1;
        int nChoice = 0;
        COutPacket pktComplete(0x29, 0);
        pktComplete.Encode1(4);
        pktComplete.Encode4(nQuestId);
        pktComplete.Encode4(FUN_140967100()->FUN_141b212c0());
        pktComplete.Encode4(nChoice);
        FUN_140710590(pktComplete);
        if (m_spContent->m_redirect != 0 && FUN_14074b950(nQuestId) != 0) {
            COutPacket pktNext(0x22, 0);
            pktNext.Encode1(7);
            pktNext.Encode4(spQuest->m_require.m_followingQuests[0]);
            pktNext.Encode2(0);
            FUN_140710590(pktNext);
            return 1;
        }
        FUN_140967100()->FUN_141b20db0(0);
        return 1;
    }
    return 0;
}
// @0x141082e10
int CQuestCompleteCinematicComponent::vfunc_3() { return 7; }
// @0x14107f270
void CQuestCompleteCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return;
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(m_spContent->m_questId);
    if (!spQuest)
        return;
    ASObj reward(2);
    reward.FUN_1407cbb20("title", FUN_14028de60(0x5d7));
    __int64 nExp = FUN_140761ba0(m_spContent->m_questId, 1);
    if (nExp != 0)
        reward.FUN_1407cbb20("exp", FUN_1409404f0(nExp));
    __int64 nMeso = FUN_140761cc0(m_spContent->m_questId, 1);
    if (nMeso != 0)
        reward.FUN_1407cbb20("meso", FUN_1409404f0(nMeso));
    __int64 nKarma = FUN_140761d80(m_spContent->m_questId, 1);
    if (nKarma != 0)
        reward.FUN_1409c1180("karma", nKarma);
    __int64 nLu = FUN_140761de0(m_spContent->m_questId, 1);
    if (nLu != 0)
        reward.FUN_1409c1180("lu", nLu);
    __int64 nGuildExp = FUN_140761c00(m_spContent->m_questId, 1);
    if (nGuildExp != 0)
        reward.FUN_1409c1180("guildExp", nGuildExp);
    __int64 nGuildFund = FUN_140761d20(m_spContent->m_questId, 1);
    if (nGuildFund != 0)
        reward.FUN_1409c1180("guildFund", nGuildFund);
    int nFame = FUN_140761ea0(m_spContent->m_questId, 1);
    if (nFame != 0)
        reward.FUN_1407cb9c0("famePoint", nFame);
    ATL::CAtlArray<CQuestData::QuestRewardItem> items;
    for (size_t i = 0; i < spQuest->m_complete.m_choiceRewards.GetCount(); i++) {
        CQuestData::QuestRewardItem& item = spQuest->m_complete.m_choiceRewards[i];
        if (item.m_itemId != 0 && FUN_140748050(&item, FUN_141654700(pc)) != 0)
            items.Add(spQuest->m_complete.m_choiceRewards[i]);
    }
    int nSpecial = FUN_140761c60(m_spContent->m_questId, 1);
    if (nSpecial != 0) {
        CQuestData::QuestRewardItem special;
        special.m_itemId = 0x1c9c6dd;
        special.m_job = nSpecial;
        special.m_count = FUN_14053feb0(0x1c9c6dd);
        items.Add(special);
    }
    FUN_14107d4b0(items, reward);
    obj.FUN_1409eb270("reward", reward);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d4));
}

// ---- CSelectableDistractorCinematicComponent ----
// @0x14107f7b0
CSelectableDistractorCinematicComponent::CSelectableDistractorCinematicComponent(UITalkCinematic* pOwner) : CDistractorCinematicComponent(pOwner) {}
// @0x14107f7f0
CSelectableDistractorCinematicComponent::~CSelectableDistractorCinematicComponent() {}
// @0x14107f820
void CSelectableDistractorCinematicComponent::vfunc_1(int nSelect) { FUN_140967100()->FUN_141b20db0(nSelect); }
// @0x141082e60
int CSelectableDistractorCinematicComponent::vfunc_3() { return 9; }
// @0x14107f850
void CSelectableDistractorCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    int bAnyScript = 0;
    Unk_CinIconArray icons;
    if (m_spContent->m_distractors.FUN_14078f390() != 0) {
        for (size_t i = 0; i < m_spContent->m_distractors.FUN_14078f3b0()->m_texts.FUN_14078fad0(); i++) {
            Unk_CinIcon icon;
            icon.m_icon = "talk_icon_distractor";
            icon.m_text = m_spContent->m_distractors.FUN_14078f3b0()->m_texts.FUN_14078f310(i).m_text;
            bAnyScript = bAnyScript | (m_spContent->m_distractors.FUN_14078f3b0()->m_texts.FUN_14078f310(i).m_script.GetLength() > 0);
            icons.Add(icon);
        }
    }
    vfunc_6(icons, obj);
    if (bAnyScript)
        obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d5));
    else
        obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d6));
}

// ---- CCustomSelectableDistractorCinematicComponent ----
// @0x14107fac0
CCustomSelectableDistractorCinematicComponent::CCustomSelectableDistractorCinematicComponent(UITalkCinematic* pOwner) : CSelectableDistractorCinematicComponent(pOwner) {}
// @0x14107fb00
CCustomSelectableDistractorCinematicComponent::~CCustomSelectableDistractorCinematicComponent() {}
// @0x14107fb30
void CCustomSelectableDistractorCinematicComponent::vfunc_1(int nSelect)
{
    COutPacket pkt(0x22, 0);
    pkt.Encode1(0xb);
    pkt.Encode4(FUN_140967100()->FUN_141b212c0());
    pkt.Encode4(nSelect);
    FUN_140710590(pkt);
}
// @0x141082da0
int CCustomSelectableDistractorCinematicComponent::vfunc_3() { return 0x13; }

// ---- CSelectableBeautyCinematicComponent ----
// @0x14107fbb0
CSelectableBeautyCinematicComponent::CSelectableBeautyCinematicComponent(UITalkCinematic* pOwner) : CSelectableDistractorCinematicComponent(pOwner) {}
// @0x14107fbf0
CSelectableBeautyCinematicComponent::~CSelectableBeautyCinematicComponent() {}
// @0x14107fc20
void CSelectableBeautyCinematicComponent::vfunc_1(int nSelect) { CSelectableDistractorCinematicComponent::vfunc_1(nSelect); }
// @0x141082e50
int CSelectableBeautyCinematicComponent::vfunc_3() { return 0xa; }
// @0x14107fc50
void CSelectableBeautyCinematicComponent::vfunc_5(ASObj& obj) { CSelectableDistractorCinematicComponent::vfunc_5(obj); }

// ---- CSelectableTalkCinematicComponent ----
// @0x14107fc80
CSelectableTalkCinematicComponent::CSelectableTalkCinematicComponent(UITalkCinematic* pOwner) : CDistractorCinematicComponent(pOwner) {}
// @0x14107fcc0
CSelectableTalkCinematicComponent::~CSelectableTalkCinematicComponent() {}
// @0x14107fcf0
void CSelectableTalkCinematicComponent::vfunc_1(int nSelect) { FUN_140967100()->FUN_141b20db0(nSelect); }
// @0x141082e70
int CSelectableTalkCinematicComponent::vfunc_3() { return 5; }

// ---- helpers used by the talk components ----
class Unk_CinNpcData : public CPtred { public: int FUN_1406cd020(); };          // npc table row: npc type
// @0x141081a50
int FUN_141081a50(MS2Ptr<Unk_CinNpcData> spNpc, int bFlag)
{
    int nType = spNpc->FUN_1406cd020();
    switch (nType) {
    case 0x1e:
        return 1;
    case 0x1f:
        return 2;
    case 0x20:
    case 0x22:
        return 3;
    case 0x21: {
        int nRet;
        if (bFlag == 0)
            nRet = 1;
        else
            nRet = 3;
        return nRet;
    }
    }
    return 0;
}
// MS2-FUNCTIONAL: the exe frame holds one more 8-byte local (unidentified temp) than the switch-on-kind body produces
// @0x141082150
CStringA FUN_141082150(MS2Ptr<CQuestData> spQuest, const CStringA& sNormal, const CStringA& sDefault, const CStringA& sAlt, const CStringA& sEpic)
{
    if (spQuest.get() != 0) {
        int nKind = FUN_14074b050(spQuest.operator->());
        switch (nKind) {
        case 0:
            return sNormal;
        case 1:
        case 6: {
            const CStringA* p = &sDefault;
            if (FUN_1407640c0(spQuest.operator->()) != 0)
                p = &sAlt;
            return *p;
        }
        case 2:
            return sEpic;
        case 8:
        case 9:
            return sDefault;
        }
    }
    return sDefault;
}
// @0x141082090
CStringA FUN_141082090(int nQuestId, const CStringA& sNormal, const CStringA& sDefault, const CStringA& sAlt, const CStringA& sEpic)
{
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
    return FUN_141082150(spQuest, sNormal, sDefault, sAlt, sEpic);
}

// formatting of the quest-name line (FUN_14028dfa0 is the localized formatter; FUN_141081c60 is its <CStringW, CStringW, int> instance)
CStringW FUN_14028dfa0(const CStringW& sFormat, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

// @0x141082490
struct Unk_CinNpcId
{
    Unk_CinNpcId() : m_n(0) {}
    int m_n;
};

// ---- CSelectableTalkCinematicComponent::vfunc_5 ----
// MS2-FUNCTIONAL: one unidentified 8-byte stack local below the script pointers shifts every later slot by 8
// @0x14107fd20
void CSelectableTalkCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return;
    Unk_CinNpc* pNpc = FUN_140967100()->FUN_141b21350();
    if (pNpc == 0)
        return;
    {
        {
            int nFlags = FUN_140967100()->FUN_141082ec0();
            Unk_CinIconArray icons;
            if ((nFlags & 0x20) != 0) {
                Unk_CinTalkScriptPtr spScript = FUN_140856c50(FUN_141092fa0(pNpc), 0);
                if (bool(spScript.FUN_14078f3a0() != 0)) {
                    if (spScript.FUN_14085a610()->m_contents.FUN_14078fae0() > 0) {
                        Unk_CinScriptContent* pEntry = spScript.FUN_14085a610()->m_contents.FUN_14078f350(0).FUN_14078f3d0();
                        if (pEntry->vfunc_1() == 0) {
                            CCinematicContent* pContent = FUN_14085a540(spScript.FUN_14085a610()->m_contents.FUN_14078f350(0));
                            if (pContent != 0 && bool(pContent->m_distractors.FUN_14078f390() != 0)) {
                                for (size_t i = 0; i < pContent->m_distractors.FUN_14078f3b0()->m_texts.FUN_14078fad0(); i++) {
                                    CCinematicDistractor* pText = &pContent->m_distractors.FUN_14078f3b0()->m_texts.FUN_14078f310(i);
                                    Unk_CinIcon icon;
                                    icon.m_icon = "talk_icon_distractor";
                                    icon.m_text = pText->m_text;
                                    icons.Add(icon);
                                }
                            }
                        }
                    }
                }
            }
            if ((nFlags & 4) != 0) {
                Unk_CinTalk* pTalk = FUN_140967100();
                for (size_t j = 0; j < (size_t)(__int64)pTalk->FUN_141b21860(); j++) {
                    Unk_CinIcon icon;
                    int nQuestId = pTalk->FUN_141b21810((unsigned)j);
                    int nState = FUN_1416e6100(nQuestId, 1);
                    if (nState == 0x5dc)
                        nState = 0x5d9;
                    if (nState == 0x5d9)
                        icon.m_icon = "talk_icon_quest_accept";
                    else if (nState == 0x5da)
                        icon.m_icon = "talk_icon_quest_progress";
                    else if (nState == 0x5db)
                        icon.m_icon = "talk_icon_quest_complete";
                    else
                        icon.m_icon = "talk_icon_quest_progress";
                    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
                    if (spQuest.get() != 0) {
                        icon.m_icon += FUN_141082090(nQuestId, "_epic", "", "_repeat", "_event");
                        icon.m_text = FUN_14028dfa0(L"s_quest_distactor_quest_name", FUN_1416e4df0(nQuestId), FUN_14028de60(nState), spQuest->m_level);
                        icons.Add(icon);
                    }
                }
            }
            if ((nFlags & 1) != 0) {
                Unk_CinIcon icon;
                CStringW sJob = FUN_1401a9d70()->FUN_141811980(0xe, FUN_141092fa0(pNpc));
                if (sJob.GetLength() == 0)
                    sJob = FUN_14028de60(0x62d);
                icon.m_icon = "talk_icon_job";
                icon.m_text = sJob;
                icons.Add(icon);
            }
            if ((nFlags & 2) != 0) {
                Unk_CinIcon icon;
                icon.m_icon = "talk_icon_distractor";
                icon.m_text = FUN_14028de60(0x62e);
                icons.Add(icon);
            }
            vfunc_6(icons, obj);
            obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d5));
        }
    }
}

// ---- misc helpers (the pointer to UITalkCinematic, the job-change dialog) ----
// An empty two-argument member (this, one pointer); nothing in the unit calls it.
class Unk_CinNullSink { public: void FUN_141080590(void* p); };
// @0x141080590
void Unk_CinNullSink::FUN_141080590(void*) {}
// @0x1410819f0
void FUN_1410819f0(const CString& key)
{
    UITalkCinematic* pTalk = FUN_140a7b2b0(0x4e40);
    if (pTalk != 0)
        pTalk->FUN_141b1beb0(key);
}
// @0x141081ff0
UIJobChangeDialog* FUN_141081ff0(int nId)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (spObj.get() != 0)
            return dynamic_cast<UIJobChangeDialog*>(spObj.operator->());
    }
    return 0;
}

// ---- CChangeJobComponent ----
// @0x1410805b0
CChangeJobComponent::CChangeJobComponent(UITalkCinematic* pOwner) : CDistractorCinematicComponent(pOwner) {}
// @0x141080610
CChangeJobComponent::~CChangeJobComponent()
{
    FUN_14151f460(1);
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e7c);
}
// @0x141080680
int CChangeJobComponent::vfunc_2(int nMsg)
{
    if (nMsg == 1) {
        FUN_140967100()->FUN_141b1feb0();
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e7c);
    } else if (nMsg == 0x493e2) {
        int nResult = 0;
        UIJobChangeDialog* pDlg = FUN_141081ff0(0x4e7c);
        if (pDlg != 0)
            nResult = FUN_1419dc530(pDlg);
        if (FUN_14151f6e0() != 0)
            FUN_140d73bc0(nResult != 0 ? 0x75 : 0x7cb, 1, this, "");
    }
    return 1;
}
// @0x141082d70
int CChangeJobComponent::vfunc_3() { return 0xb; }
// @0x141080780
int CChangeJobComponent::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0) {
        if (dynamic_cast<UIMessageBox*>(pSender) != 0) {
            FUN_14151f200();
            int nButton = pMsg->FUN_1422b8a10();
            if (nButton == 0) {
                Unk_CinNpcId npc;
                npc.m_n = FUN_140967100()->FUN_141b212c0();
                COutPacket pkt(0x25, 0);
                pkt.Encode1(2);
                FUN_1401fdad0(&npc.m_n, pkt);
                FUN_140710590(pkt);
                FUN_140967100()->FUN_141b1feb0();
                FUN_1403ed2b0()->FUN_141adc5d0(0x4e7c);
            }
        }
    }
    return 1;
}
// @0x141080890
void CChangeJobComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x668));
}

// ---- CUgcSignCinematicComponent ----
// @0x141080900
CUgcSignCinematicComponent::CUgcSignCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x141080940
CUgcSignCinematicComponent::~CUgcSignCinematicComponent() {}
// MS2-FUNCTIONAL: the exe passes the pc id through a register copy (mov ecx / mov edx,ecx) and keeps pc in a lower slot; not reproduced
// @0x141080970
int CUgcSignCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return 0;
    Unk_CinSvcPtr spSvc(FUN_1401cd040(&DAT_143b059e8));
    int nPcId = FUN_141529620(pc);
    spSvc.FUN_1401cd1a0()->FUN_1410ccc00(nPcId, 0, 0);
    if (nMsg == 0x493e2) {
        FUN_140967100()->FUN_141b20db0(0);
        int nOut = 0;
        int nPcId2 = FUN_141529620(pc);
        if (FUN_1408a0890(FUN_141bd3060(FUN_1403ed2d0()), nPcId2, &nOut) == 0)
            return 0;
        Unk_CinSvcPtr spSvc2(FUN_1401cd040(&DAT_143b059e8));
        int nPcId3 = FUN_141529620(pc);
        __int64 nOwner = spSvc2.FUN_1401cd1a0()->FUN_1410c8030(nPcId3, 0);
        if (nOwner == FUN_141656ad0(pc)) {
            COutPacket pkt(0x37, 0);
            pkt.Encode1(5);
            pkt.Encode4(FUN_141529620(pc));
            pkt.Encode4(0);
            FUN_140710590(pkt);
        } else {
            COutPacket pkt(0x37, 0);
            pkt.Encode1(2);
            pkt.Encode4(FUN_141529620(pc));
            int nRand = 0;
            if (FUN_141527e00(pc) != 0) {
                nRand = rand();
                nRand = nRand % 3;
            }
            pkt.Encode4(nRand);
            FUN_140710590(pkt);
        }
        return 1;
    }
    return 0;
}
// @0x141082eb0
int CUgcSignCinematicComponent::vfunc_3() { return 6; }
// @0x141080c20
void CUgcSignCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x5d3));
}

// ---- CPaneltyResolveCinematicComponent ----
// @0x141080c90
CPaneltyResolveCinematicComponent::CPaneltyResolveCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x141080cd0
CPaneltyResolveCinematicComponent::~CPaneltyResolveCinematicComponent() {}
// MS2-FUNCTIONAL: the exe spills the 16-bit result of PCBase slot 78 (the shared header declares it int), which shifts every later slot
// @0x141080d00
int CPaneltyResolveCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        if (FUN_141661aa0(pc) != 0) {
            bool bTooRich = DAT_143ab2898 < FUN_1401c0db0()->FUN_140675730((short)pc->vfunc_78(), FUN_141661aa0(pc), FUN_1403754f0(FUN_1403ed2d0()->FUN_141bd30a0().FUN_140885340()));
            if (bTooRich) {
                FUN_141275260(0x34, 1, 1);
            } else {
                COutPacket pkt(0x44, 0);
                pkt.Encode4(FUN_140967100()->FUN_141b212c0());
                FUN_140710590(pkt);
                FUN_141276180(s_deadPanelty, "");
            }
        } else {
            FUN_141275260(0x79, 1, 1);
        }
        FUN_140967100()->FUN_141b20db0(0);
    }
    return 1;
}
// @0x141082df0
int CPaneltyResolveCinematicComponent::vfunc_3() { return 0xd; }
// @0x141080f10
void CPaneltyResolveCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x66a));
}

// ---- CHomeDoctorCinematicComponent ----
// @0x141080f80
CHomeDoctorCinematicComponent::CHomeDoctorCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x141080fc0
CHomeDoctorCinematicComponent::~CHomeDoctorCinematicComponent() {}
// MS2-FUNCTIONAL: the exe spills the 16-bit result of PCBase slot 78 (the shared header declares it int), which shifts every later slot
// @0x141080ff0
int CHomeDoctorCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        if (FUN_141661aa0(pc) != 0) {
            bool bTooRich = DAT_143ab2898 < FUN_1401c0db0()->FUN_140675730((short)pc->vfunc_78(), FUN_141661aa0(pc), FUN_1403754f0(FUN_1403ed2d0()->FUN_141bd30a0().FUN_140885340()));
            if (bTooRich) {
                FUN_141275260(0x34, 1, 1);
            } else {
                COutPacket pkt(0x4e, 0);
                FUN_140710590(pkt);
                FUN_141276180(s_deadPanelty, "");
            }
        } else {
            FUN_141275260(0x79, 1, 1);
        }
        FUN_140967100()->FUN_141b20210();
    }
    return 1;
}
// @0x141082dd0
int CHomeDoctorCinematicComponent::vfunc_3() { return 0x12; }
// @0x1410811e0
void CHomeDoctorCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x66a));
}

// ---- CTakeBoatCinematicComponent ----
// @0x141081250
CTakeBoatCinematicComponent::CTakeBoatCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x141081290
CTakeBoatCinematicComponent::~CTakeBoatCinematicComponent() {}
// @0x1410812c0
int CTakeBoatCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        FUN_1408e57f0()->FUN_1422b9fd0(0x620001d);
        FUN_140967100()->FUN_141b20db0(0);
        COutPacket pkt(0x45, 0);
        pkt.Encode4(FUN_140967100()->FUN_141b212c0());
        FUN_140710590(pkt);
    }
    return 1;
}
// @0x141082ea0
int CTakeBoatCinematicComponent::vfunc_3() { return 0xe; }
// @0x1410813a0
void CTakeBoatCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x669));
}

// ---- CSellUGCMapCinematicComponent ----
// @0x141081410
CSellUGCMapCinematicComponent::CSellUGCMapCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x141081450
CSellUGCMapCinematicComponent::~CSellUGCMapCinematicComponent() {}
// @0x141081480
int CSellUGCMapCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        if (FUN_141527e00(pc) != 0)
            FUN_141275260(0x6bf, 1, 1);
        else
            FUN_1403ed2b0()->FUN_141adc750(0x4e82);
        FUN_140967100()->FUN_141b20db0(0);
    }
    return 1;
}
// @0x141082e80
int CSellUGCMapCinematicComponent::vfunc_3() { return 0xf; }
// @0x141081530
void CSellUGCMapCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x66b));
}

// ---- CRouletteCinematicComponent ----
// @0x1410815a0
CRouletteCinematicComponent::CRouletteCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) { m_nSent = 0; }
// @0x1410815f0
CRouletteCinematicComponent::~CRouletteCinematicComponent() {}
// @0x141081620
int CRouletteCinematicComponent::vfunc_2(int nMsg)
{
    if (nMsg == 0x493e2 && m_nSent == 0) {
        if (FUN_1403ed2b0()->FUN_141adc9e0(0x4e6d) != 0) {
            COutPacket pkt(0x43, 0);
            pkt.Encode1(2);
            FUN_140710590(pkt);
            FUN_140967100()->FUN_141b20db0(0);
            m_nSent = 1;
        }
    }
    return 1;
}
// @0x141082e30
int CRouletteCinematicComponent::vfunc_3() { return 0x10; }
// @0x1410816c0
void CRouletteCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x66c));
}

// ---- CRouletteSkipCinematicComponent ----
// @0x141081730
CRouletteSkipCinematicComponent::CRouletteSkipCinematicComponent(UITalkCinematic* pOwner) : CCloseCinematicComponent(pOwner) {}
// @0x141081770
CRouletteSkipCinematicComponent::~CRouletteSkipCinematicComponent() {}
// @0x141082e40
int CRouletteSkipCinematicComponent::vfunc_3() { return 0x11; }
// @0x1410817a0
void CRouletteSkipCinematicComponent::vfunc_5(ASObj& obj)
{
    CCloseCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x66d));
}

// ---- CEmptyCinematicComponent ----
// @0x141081810
CEmptyCinematicComponent::CEmptyCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x141081850
CEmptyCinematicComponent::~CEmptyCinematicComponent() {}
// @0x141081880
int CEmptyCinematicComponent::vfunc_2(int) { return 1; }
// @0x141082dc0
int CEmptyCinematicComponent::vfunc_3() { return 1; }
// @0x1410818a0
void CEmptyCinematicComponent::vfunc_5(ASObj& obj) { CCinematicComponent::vfunc_5(obj); }

// ---- CStopCinematicComponent ----
// @0x1410818d0
CStopCinematicComponent::CStopCinematicComponent(UITalkCinematic* pOwner) : CCinematicComponent(pOwner) {}
// @0x141081910
CStopCinematicComponent::~CStopCinematicComponent() {}
// @0x141081940
int CStopCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    return 0;
}
// @0x141082e90
int CStopCinematicComponent::vfunc_3() { return 2; }
// @0x141081980
void CStopCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    obj.FUN_1407cbb20("button", FUN_14107dfa0(0x958));
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cabb20-0x142cabc60 .text$yd
