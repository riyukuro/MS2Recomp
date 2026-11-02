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
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/cquestmanagercommon.h"  // C3: CQuestManagerCommon (the quest-state calls)
#include "ms2/placeholder/uitalkmanager.h"  // C3: UITalkManager (the Unk_CinTalk calls)
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/formatstringid.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/commonfiles/maid.h"
#include "ms2/commonfiles/npcdata.h"
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<Unk_Service6100017>::operator->
class Unk_Service6100017;   // C3: efd::SmartPointer<Unk_Service6100017>::operator->
class CUserMail { public: static __int64 FUN_1408e57f0(); };  // C3: member view (0x1408e57f0, the scene-service global)
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
};

// The reward block of the open talk (inside the talk manager).
class Unk_CinReward : public UITalkManager::CTalkRewardData { };

// The talk manager (FUN_140967100): the state of the open dialogue.
class Unk_CinTalk
{
public:
    Unk_CinReward* FUN_141082d60() { return &m_reward; }        // @0x141082d60
    unsigned char FUN_141082ec0() { return m_flags; }           // @0x141082ec0
public:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38; void* m_40; void* m_48;
    unsigned char m_flags;                                      // +0x50
    char m_51; short m_52; int m_54; void* m_58;
    Unk_CinReward m_reward;                                     // +0x60
};
MS2_CHECK_OFFSET(Unk_CinTalk, m_reward, 0x60);
class Unk_AkoCutscene   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AkoCutscene* GetInstance();
};

class UITalkCinematic : public UIObject
{
public:
    void FocusUp();
    void FocusDown();
    void SelectOption();
    void AddImage(CString key);
};
UITalkCinematic* FUN_140a7b2b0(int nId);

// The chat/name filter.
class Unk_CinNameFilter : public CReservedWordTable
{
public:
};

// The key name table and settings.
CKeyTable* FUN_1409331f0();
struct Unk_GpState* FUN_140a58500(class Unk_GpSettings*);

// Local player, world and ui manager.
class Unk_CinWorld
{
public:
    MyPC* FUN_141bd0cc0();                                      // local player
};
class UIJobChangeDialog : public UIObject { public: public:
    int FUN_1419dc530();   // C3: was free FUN_1419dc530
};
int FUN_14151f6e0();
void FUN_14151f200();
void FUN_14151f460(int);
class PC { public: int FUN_141654700(); __int64 FUN_141656ad0(); int FUN_141661aa0(); };   // C3: unit-local view (fittingdollpc.h);                                       // level
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
extern __int64 DAT_143ab2898;
class GFxSceneService { public: int FUN_1422b9fd0(int nSubSceneId); };  // C3: member view (0x1422b9...)

class Unk_Service6100017 : public CubeMapInformationService { };
class Unk_CinSvc : public Unk_Service6100017 { public: void vfunc_1(); };
class Unk_CinFramework { public: void* m_0; };
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(Unk_CinFramework*)&egf::g_bapiContext)          // C3: was extern Unk_CinFramework DAT_143b059e8
class Unk_Service6100017* FUN_1401cd040(struct Unk_EntityAppFramework*);   // C3: was FUN_1401cd040
int FUN_1408a0890(int, int, int*);

// Quest helpers.
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
class Unk_CinQuestState { };
class Unk_CinQuestGlobal { public: void* m_0; void* m_8; Unk_CinQuestState m_state; };
void* FUN_140764020();   // C3: was FUN_140764020
int FUN_14074b050(CQuestData*);
int FUN_14074b840(int nQuestId);
int FUN_14074b950(int nQuestId);
int FUN_140748050(CQuestData::QuestRewardItem*, int);
bool FUN_1407640c0(CQuestData*);
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
CStringW GetStringCommon(int nStringId);
CStringW FUN_1401aa6a0(int nId);
CStringW GetStringCommonByKey(const CStringW&);
CStringW FUN_1409404f0(__int64);
CStringW FUN_1416e4df0(int nQuestId);
int FUN_1416e6100(int nQuestId, int);
void FUN_141275260(int, int, int);
void FUN_1410819f0(const CString& key);
int FUN_141276180(const CString&, const CString&);
void FUN_140710590(COutPacket&);
void FUN_141415450(const CString&, MS2Ptr<CItem>, int, int, int);
void FUN_1401fdad0(unsigned char*, class COutputStream&);   // C3: was FUN_1401fdad0
void FUN_140d73bc0(int, int, void*, CStringW);

class CMsgBoxData : public CPtred
{
public:
    void SetCallback(Delegate<bool(int, const CMsgBoxData&)> cb);
    unsigned int FUN_141a02e90(int, unsigned int) const;
    bool FUN_141a02e10(int, bool) const;
    template<class T> void Append(T);
    unsigned char m_pad[0x2a0 - 0x18];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
void FUN_140f73320(CMsgBoxData*, bool);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);

// Talk scripts (FUN_140856c50(npc id, 0)). ctalkscript.h is a view: its page list is this array.
Unk_ScriptPtr<CTalkScript> FUN_140856c50(int nNpcId, int n);
typedef ATL::CAtlArray<Unk_TalkContentPtr<CScriptContent> > Unk_CinContentArray;

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
// @0x141083080
void FUN_141083080(void* pDst, void* pSrc, size_t n)
{
    ATL::Checked::memmove_s(pDst, n * sizeof(Unk_CinIcon), pSrc, n * sizeof(Unk_CinIcon));
}
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
            if (nNewSize < m_nMaxSize + nGrow)
                nAlloc = m_nMaxSize + nGrow;
            else
                nAlloc = nNewSize;
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
            ATL::AtlThrowImpl(0x8007000e);
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
        ATL::AtlThrowImpl(0x80070057);
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
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode0();
        return 1;
    }
    else if (nMsg == 0x79)
        m_pOwner->FocusUp();
    else if (nMsg == 0x7e)
        m_pOwner->FocusDown();
    return 0;
}
// @0x141082d80
int CCinematicComponent::vfunc_3() { return 0; }
// @0x1410830c0
void CCinematicComponent::vfunc_4(MS2Ptr<CCinematicContent> spContent) { m_spContent = spContent; }
// @0x14107cf90
void CCinematicComponent::vfunc_5(ASObj& obj)
{
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc != 0) {
        CStringW name(m_spContent->m_name);
        int nNpcId = ((UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b212f0();
        CStringW text;
        if (m_spContent->m_speakerNpc != 0) {
            text = FUN_1401aa6a0(m_spContent->m_speakerNpc);
        } else if (m_spContent->m_myTalk != 0) {
            text = pc->vfunc_77();
        } else if (m_spContent->m_otherNpcTalk != 0) {
            text = FUN_1401aa6a0(m_spContent->m_otherNpcTalk);
        } else {
            Unk_CinNpc* pNpc = (Unk_CinNpc*)((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetTalkNpc();
            if (pNpc != 0 && pNpc->vfunc_128() != 0) {
                reinterpret_cast<Unk_CinNameFilter*>(TSingleton<CReservedWordTable>::GetInstance())->FUN_1416fb400(name, pNpc);
                text = reinterpret_cast<CNpc*>(pNpc)->FUN_141093310();
            } else {
                text = FUN_1401aa6a0(nNpcId);
            }
        }
        reinterpret_cast<Unk_CinNameFilter*>(TSingleton<CReservedWordTable>::GetInstance())->ReplaceValueWords(name);
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
            spItem->SetCountClamped(nCount);
            CString key;
            key.Format("%s_%d", (const char*)m_pOwner->GetTypeName(), i);
            FUN_141415450(key, spItem, 0, 0x11, 0x800);
            CString attr;
            attr.Format("reward%d", i + 1);
            FUN_1410819f0(key);
            obj.FUN_1407cba60(attr, CString(key));
        }
    }
}
// @0x14107d760
unsigned CCinematicComponent::FUN_14107d760(ASObj& obj)
{
    if (m_spContent->m_openTalkReward == 0)
        return 0;
    {
        unsigned bAny = 0;
        ASObj reward(2);
        reward.FUN_1407cbb20("title", GetStringCommon(0x94b));
        Unk_CinReward* pReward = ((class Unk_CinTalk*)Unk_AkoCutscene::GetInstance())->FUN_141082d60();
        if (pReward->m_nMerat != 0) {
            bAny = 1;
            reward.FUN_1407cbb20("exp", FUN_1409404f0(pReward->m_nMerat));
        }
        if (pReward->m_nMeso != 0) {
            bAny = 1;
            reward.FUN_1407cbb20("meso", FUN_1409404f0(pReward->m_nMeso));
        }
        if (pReward->m_nExp != 0) {
            reward.FUN_1407cbb20("title", GetStringCommon(0x7c1));
            bAny = 1;
            CStringW mood(L"");
            if (pReward->m_nExp > 0) {
                mood = FormatStringId<int>(0x7c4, pReward->m_nExp);
            } else if (pReward->m_nExp < 0) {
                int nAbs = abs(pReward->m_nExp);
                mood = FormatStringId<int>(0x7c5, nAbs);
            }
            reward.FUN_1407cbb20("mood", CStringW(mood));
        }
        if (pReward->m_nAffinity != 0) {
            reward.FUN_1407cbb20("title", GetStringCommon(0x7c1));
            bAny = 1;
            CStringW affinity(L"");
            Unk_CinNpc* pNpc = (Unk_CinNpc*)((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetTalkNpc();
            if (pNpc != 0) {
                CMaid* pAffinity = reinterpret_cast<CNpc*>(pNpc)->FUN_141093800().get();
                if (pAffinity != 0) {
                    if (pReward->m_nJackpot != 0) {
                        affinity = StringFormat<CStringW, CStringW>(L"{0} {1}", FormatStringId<int>(0x7c2, pReward->m_nAffinity),
                                                 FormatStringId<int>(0x7c3, reinterpret_cast<CNpc*>(pNpc)->FUN_141093800().operator->()->m_nOrder));
                    } else {
                        affinity = FormatStringId<int>(0x7c2, pReward->m_nAffinity);
                    }
                }
            }
            reward.FUN_1407cbb20("affinityExp", CStringW(affinity));
        }
        for (size_t i = 0; i < pReward->m_items.GetCount(); i++) {
            bAny = 1;
            MS2Ptr<CItem> spItem = pReward->m_items[i];
            CString key;
            key.Format("%s_%d", (const char*)m_pOwner->GetTypeName(), i + 1);
            FUN_141415450(key, spItem, 0, 0x11, 0x800);
            CString attr;
            attr.Format("reward%d", i + 1);
            reward.FUN_1407cba60(attr, CString(key));
            FUN_1410819f0(key);
        }
        pReward->FUN_141b1dbd0();
        if (bAny != 0)
            obj.FUN_1409eb270("reward", reward);
        return bAny;
    }
}
// @0x14107dfa0
CStringW CCinematicComponent::FUN_14107dfa0(int nStringId)
{
    CStringW text = GetStringCommon(nStringId);
    reinterpret_cast<Unk_CinNameFilter*>(TSingleton<CReservedWordTable>::GetInstance())->ReplaceValueWords(text);
    CStringW keyConfirm = FUN_1409331f0()->GetKeyName(1);
    CStringW keyNext = FUN_1409331f0()->GetKeyName(0x39);
    int nVariant = *reinterpret_cast<unsigned char*>(FUN_140a58500(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance()))) != 0 ? 2 : 0;
    if (nVariant == 2)
        text.Replace(keyConfirm, FUN_1409331f0()->GetActionKeyName(0x49409, nVariant));
    text.Replace(keyNext, FUN_1409331f0()->GetActionKeyName(0x493e2, nVariant));
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
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
        if (((UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b213c0() != 0)
            ((UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b20210();
        else
            ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
        m_pOwner->SelectOption();
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
        reinterpret_cast<Unk_CinNameFilter*>(TSingleton<CReservedWordTable>::GetInstance())->FUN_1416fb400(text, (Unk_CinNpc*)((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetTalkNpc());
        reinterpret_cast<Unk_CinNameFilter*>(TSingleton<CReservedWordTable>::GetInstance())->ReplaceValueWords(text);
        item.FUN_1407cba60("iconClass", CString(icons.GetAt(i).m_icon));
        item.FUN_1407cbb20("text", CStringW(text));
        distractors.PushValue(item.FUN_1422bb870());
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
        if (((CQuestManagerCommon*)&((class Unk_CinQuestGlobal*)FUN_140764020())->m_state)->IsQuestActive(m_spContent->m_questId) != 0)
            return 1;
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(m_spContent->m_questId);
        if (bool(spQuest.get() != 0) && spQuest->m_require.m_unrequireGroup.GetCount() > 0) {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, GetStringCommonByKey(L"s_alliance_quest_unreq_group_warn"), 0, L"");
            spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CQuestAcceptCinematicComponent::OnMsgBoxResult));
            spBox->Append<unsigned>(m_spContent->m_questId);
            FUN_140f73320(spBox.operator->(), m_spContent->m_redirect != 0);
            FUN_140d73c60(spBox);
            return 1;
        }
        SendQuestAccept(m_spContent->m_questId, m_spContent->m_redirect != 0);
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
bool CQuestAcceptCinematicComponent::OnMsgBoxResult(int nButton, const CMsgBoxData& data)
{
    if (nButton != 0) {
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode0();
        return true;
    }
    {
        int nQuestId = data.FUN_141a02e90(0, 0);
        bool bRedirect = data.FUN_141a02e10(1, 0);
        SendQuestAccept(nQuestId, bRedirect);
    }
    return true;
}
// @0x14107ecc0
void CQuestAcceptCinematicComponent::SendQuestAccept(int nQuestId, bool bRedirect)
{
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc != 0) {
        COutPacket pkt(static_cast<int>(SendOp::Quest), 0);
        pkt.Encode1(2);
        pkt.Encode4(nQuestId);
        pkt.Encode4(((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetNpcId());
        FUN_140710590(pkt);
    }
    if (bRedirect && FUN_14074b840(nQuestId) != 0) {
        COutPacket pkt(static_cast<int>(SendOp::NpcTalk), 0);
        pkt.Encode1(7);
        pkt.Encode4(nQuestId);
        pkt.Encode2(2);
        FUN_140710590(pkt);
        return;
    }
    ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
            COutPacket pkt(static_cast<int>(SendOp::Quest), 0);
            pkt.Encode1(0x12);
            pkt.Encode4(m_spContent->m_questId);
            FUN_140710590(pkt);
        }
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
        if (((CQuestManagerCommon*)&((class Unk_CinQuestGlobal*)FUN_140764020())->m_state)->FUN_140745590(m_spContent->m_questId) != 0)
            return 1;
        int nChoice = 0;
        COutPacket pktComplete(static_cast<int>(SendOp::Quest), 0);
        pktComplete.Encode1(4);
        pktComplete.Encode4(nQuestId);
        pktComplete.Encode4(((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetNpcId());
        pktComplete.Encode4(nChoice);
        FUN_140710590(pktComplete);
        if (m_spContent->m_redirect != 0 && FUN_14074b950(nQuestId) != 0) {
            COutPacket pktNext(static_cast<int>(SendOp::NpcTalk), 0);
            pktNext.Encode1(7);
            pktNext.Encode4(spQuest->m_require.m_followingQuests[0]);
            pktNext.Encode2(0);
            FUN_140710590(pktNext);
            return 1;
        }
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc == 0)
        return;
    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(m_spContent->m_questId);
    if (!spQuest)
        return;
    ASObj reward(2);
    reward.FUN_1407cbb20("title", GetStringCommon(0x5d7));
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
        if (item.m_itemId != 0 && FUN_140748050(&item, ((PC*)pc)->FUN_141654700()) != 0)
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
void CSelectableDistractorCinematicComponent::vfunc_1(int nSelect) { ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(nSelect); }
// @0x141082e60
int CSelectableDistractorCinematicComponent::vfunc_3() { return 9; }
// @0x14107f850
void CSelectableDistractorCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    int bAnyScript = 0;
    Unk_CinIconArray icons;
    if (m_spContent->m_distractors.get() != 0) {
        for (size_t i = 0; i < m_spContent->m_distractors->m_choices.GetCount(); i++) {
            Unk_CinIcon icon;
            icon.m_icon = "talk_icon_distractor";
            icon.m_text = m_spContent->m_distractors->m_choices.GetAt(i).m_text;
            bAnyScript = bAnyScript | (m_spContent->m_distractors->m_choices.GetAt(i).m_goto.GetLength() > 0);
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
    COutPacket pkt(static_cast<int>(SendOp::NpcTalk), 0);
    pkt.Encode1(0xb);
    pkt.Encode4(((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetNpcId());
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
void CSelectableTalkCinematicComponent::vfunc_1(int nSelect) { ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(nSelect); }
// @0x141082e70
int CSelectableTalkCinematicComponent::vfunc_3() { return 5; }

// ---- helpers used by the talk components ----
class Unk_CinNpcData : public CNpcData { };          // npc table row: npc type
// @0x141081a50
int FUN_141081a50(MS2Ptr<Unk_CinNpcData> spNpc, int bFlag)
{
    int nType = spNpc->GetKind();
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
// @0x141082150
CStringA FUN_141082150(MS2Ptr<CQuestData> spQuest, const CStringA& sNormal, const CStringA& sDefault, const CStringA& sAlt, const CStringA& sEpic)
{
    if (spQuest.get() != 0) {
        int nKind = FUN_14074b050(spQuest.operator->());
        switch (nKind) {
        case 0:
            return sNormal;
        case 2:
            return sEpic;
        case 8:
        case 9:
            return sDefault;
        case 1:
        case 6:
            return FUN_1407640c0(spQuest.operator->()) ? sAlt : sDefault;
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
// @0x14107fd20
void CSelectableTalkCinematicComponent::vfunc_5(ASObj& obj)
{
    CCinematicComponent::vfunc_5(obj);
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc == 0)
        return;
    Unk_CinNpc* pNpc = (Unk_CinNpc*)((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetTalkNpc();
    if (pNpc == 0)
        return;
    {
        {
            int nFlags = ((class Unk_CinTalk*)Unk_AkoCutscene::GetInstance())->FUN_141082ec0();
            Unk_CinIconArray icons;
            if ((nFlags & 0x20) != 0) {
                Unk_ScriptPtr<CTalkScript> spScript = FUN_140856c50(((class CNpc*)(class Unk_CinNpc*)(pNpc))->FUN_141092fa0(), 0);
                if (bool(spScript.get() != 0)) {
                    if (reinterpret_cast<Unk_CinContentArray&>(spScript->m_contents).GetCount() > 0) {
                        CScriptContent* pEntry = reinterpret_cast<Unk_CinContentArray&>(spScript->m_contents)[0].operator->();
                        if (pEntry->vfunc_1() == 0) {
                            CCinematicContent* pContent = (CCinematicContent*)reinterpret_cast<Unk_CinContentArray&>(spScript->m_contents)[0].get();
                            if (pContent != 0 && bool(pContent->m_distractors.get() != 0)) {
                                for (size_t i = 0; i < pContent->m_distractors->m_choices.GetCount(); i++) {
                                    Unk_ScriptChoice* pText = &pContent->m_distractors->m_choices.GetAt(i);
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
                Unk_CinTalk* pTalk = ((class Unk_CinTalk*)Unk_AkoCutscene::GetInstance());
                for (size_t j = 0; j < (size_t)(__int64)(int)((UITalkManager*)pTalk)->FUN_141b21860(); j++) {
                    Unk_CinIcon icon;
                    int nQuestId = ((UITalkManager*)pTalk)->GetIdAt((unsigned)j);
                    int nState = FUN_1416e6100(nQuestId, 1);
                    if (nState == 0x5dc)
                        nState = 0x5d9;
                    switch (nState) {
                    case 0x5db:
                        icon.m_icon = "talk_icon_quest_complete";
                        break;
                    case 0x5da:
                        icon.m_icon = "talk_icon_quest_progress";
                        break;
                    case 0x5d9:
                        icon.m_icon = "talk_icon_quest_accept";
                        break;
                    default:
                        icon.m_icon = "talk_icon_quest_progress";
                        break;
                    }
                    MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuestId);
                    if (spQuest.get() != 0) {
                        icon.m_icon += FUN_141082090(nQuestId, "_epic", "", "_repeat", "_event");
                        icon.m_text = FUN_14028dfa0(L"s_quest_distactor_quest_name", FUN_1416e4df0(nQuestId), GetStringCommon(nState), spQuest->m_level);
                        icons.Add(icon);
                    }
                }
            }
            if ((nFlags & 1) != 0) {
                Unk_CinIcon icon;
                CStringW sJob = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xe, ((class CNpc*)(class Unk_CinNpc*)(pNpc))->FUN_141092fa0());
                if (sJob.GetLength() == 0)
                    sJob = GetStringCommon(0x62d);
                icon.m_icon = "talk_icon_job";
                icon.m_text = sJob;
                icons.Add(icon);
            }
            if ((nFlags & 2) != 0) {
                Unk_CinIcon icon;
                icon.m_icon = "talk_icon_distractor";
                icon.m_text = GetStringCommon(0x62e);
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
        pTalk->AddImage(key);
}
// @0x141081ff0
UIJobChangeDialog* FUN_141081ff0(int nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0) {
        MS2Ptr<UIObject> spObj = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
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
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e7c);
}
// @0x141080680
int CChangeJobComponent::vfunc_2(int nMsg)
{
    if (nMsg == 1) {
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode0();
        TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e7c);
    } else if (nMsg == 0x493e2) {
        int nResult = 0;
        UIJobChangeDialog* pDlg = FUN_141081ff0(0x4e7c);
        if (pDlg != 0)
            nResult = ((class UIJobChangeDialog*)(pDlg))->FUN_1419dc530();
        if (FUN_14151f6e0() != 0)
            FUN_140d73bc0(nResult != 0 ? 0x75 : 0x7cb, 1, static_cast<IMessageListener*>(this), L"");
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
            int nButton = pMsg->PopInt();
            if (nButton == 0) {
                Unk_CinNpcId npc;
                npc.m_n = ((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetNpcId();
                COutPacket pkt(static_cast<int>(SendOp::Job), 0);
                pkt.Encode1(2);
                FUN_1401fdad0((unsigned char*)(&npc.m_n), *(class COutputStream*)&static_cast<class COutPacket&>(pkt));
                FUN_140710590(pkt);
                ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode0();
                TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4e7c);
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
// @0x141080970
int CUgcSignCinematicComponent::vfunc_2(int nMsg)
{
    if (CCinematicComponent::vfunc_2(nMsg) != 0)
        return 1;
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc == 0)
        return 0;
    efd::SmartPointer<Unk_Service6100017> spSvc(FUN_1401cd040((struct Unk_EntityAppFramework*)(&DAT_143b059e8)));
    reinterpret_cast<Unk_CinSvc*>(spSvc.operator->())->FUN_1410ccc00(pc->FUN_141529620(), 0, 0);
    if (nMsg == 0x493e2) {
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
        int nOut = 0;
        if (FUN_1408a0890(((class WorldService*)(class Unk_CinWorld*)(reinterpret_cast<Unk_CinWorld*>(WorldService::GetInstance())))->FUN_141bd3060(), pc->FUN_141529620(), &nOut) == 0)
            return 0;
        efd::SmartPointer<Unk_Service6100017> spSvc2(FUN_1401cd040((struct Unk_EntityAppFramework*)(&DAT_143b059e8)));
        if (reinterpret_cast<Unk_CinSvc*>(spSvc2.operator->())->GetOwnerId(pc->FUN_141529620(), 0) == ((PC*)pc)->FUN_141656ad0()) {
            COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
            pkt.Encode1(5);
            pkt.Encode4(pc->FUN_141529620());
            pkt.Encode4(0);
            FUN_140710590(pkt);
        } else {
            COutPacket pkt(static_cast<int>(SendOp::RequestCube), 0);
            pkt.Encode1(2);
            pkt.Encode4(pc->FUN_141529620());
            int nRand = 0;
            if (((class MyPC*)(pc))->HasNoHome() != 0) {
                nRand = rand() % 3;
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
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        if (((PC*)pc)->FUN_141661aa0() != 0) {
            bool bTooRich = DAT_143ab2898 < ((class CLua*)FUN_1401c0db0())->CalcResolvePaneltyPrice((unsigned short)pc->vfunc_78(), ((PC*)pc)->FUN_141661aa0(), ((class CFieldData*)(CFieldDataCli*)(WorldService::GetInstance()->FUN_141bd30a0().operator->()))->FUN_1403754f0());
            if (bTooRich) {
                FUN_141275260(0x34, 1, 1);
            } else {
                COutPacket pkt(static_cast<int>(SendOp::ResolvePenalty), 0);
                pkt.Encode4(((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetNpcId());
                FUN_140710590(pkt);
                FUN_141276180(s_deadPanelty, "");
            }
        } else {
            FUN_141275260(0x79, 1, 1);
        }
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        if (((PC*)pc)->FUN_141661aa0() != 0) {
            bool bTooRich = DAT_143ab2898 < ((class CLua*)FUN_1401c0db0())->CalcResolvePaneltyPrice((unsigned short)pc->vfunc_78(), ((PC*)pc)->FUN_141661aa0(), ((class CFieldData*)(CFieldDataCli*)(WorldService::GetInstance()->FUN_141bd30a0().operator->()))->FUN_1403754f0());
            if (bTooRich) {
                FUN_141275260(0x34, 1, 1);
            } else {
                COutPacket pkt(static_cast<int>(SendOp::RequestHomeDoctor), 0);
                FUN_140710590(pkt);
                FUN_141276180(s_deadPanelty, "");
            }
        } else {
            FUN_141275260(0x79, 1, 1);
        }
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->FUN_141b20210();
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
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        ((GFxSceneService*)CUserMail::FUN_1408e57f0())->FUN_1422b9fd0(0x620001d);
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
        COutPacket pkt(static_cast<int>(SendOp::TakeBoat), 0);
        pkt.Encode4(((UITalkManager*)Unk_AkoCutscene::GetInstance())->GetNpcId());
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
    MyPC* pc = ((MyPC*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pc == 0)
        return 0;
    if (nMsg == 0x493e2) {
        if (((class MyPC*)(pc))->HasNoHome() != 0)
            FUN_141275260(0x6bf, 1, 1);
        else
            (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(0x4e82)));
        ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
        if (TSingleton<CUIService>::GetInstance()->FUN_141adc9e0((eUIClassID)0x4e6d) != 0) {
            COutPacket pkt(static_cast<int>(SendOp::BonusGame), 0);
            pkt.Encode1(2);
            FUN_140710590(pkt);
            ((UITalkManager*)Unk_AkoCutscene::GetInstance())->SendNpcTalkMode2(0);
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
