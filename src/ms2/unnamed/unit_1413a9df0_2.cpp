// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 2 of unit_1413a9df0: the methods of the guide-condition classes
// HasMoney .. ChatEmoticon (names, XML loaders, checks, descriptions, factories). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a9df0#2
// MS2-RANGE: 0x1413acea0-0x1413afcb0 .text$mn
// MS2-RANGE: 0x1413b43c0-0x1413b4400 .text$mn
// MS2-RANGE: 0x1413b4440-0x1413b4480 .text$mn
// MS2-RANGE: 0x1413b4580-0x1413b45c0 .text$mn
// MS2-RANGE: 0x1413b4740-0x1413b4780 .text$mn
// MS2-RANGE: 0x1413b4ac0-0x1413b4b00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/unnamed/unit_1413a9df0.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/statpointmanager.h"
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// ---- unit-local views and unrecovered callees ------------------------------------------------------------------------------

// StringFormat instances of this unit's neighbours, bound by address.
CStringW FUN_14016a730(const char* psz, int nCodePage);

extern __int64 DAT_143ab28b0;
extern __int64 DAT_143ab28b8;
extern __int64 DAT_143ab28c0;
extern __int64 DAT_143ab28c8;
extern __int64 DAT_143ab28d0;
extern __int64 DAT_143ab28d8;
extern __int64 DAT_143ab28e0;
__int64 FUN_140930240();                                // the merat

struct Unk_G9Holder { void* m_p0; void* m_p8; };
struct Unk_G9Rec { void* m_p[6]; unsigned __int64 m_nExpire; };
class MyPC   // C3: member view for the former free stand-ins
{
public:
    class UserUGCMapInfo* FUN_141523c50();
    static class PCBase* FUN_141530930();
    MS2Ptr<CStatPointManager> FUN_140c25130();          // the stat point manager
};
class PC { public: int FUN_141654700(); int FUN_141654730(); };   // C3: member views
class UIGameMenuDialog { public: int IsMenuExpanded(CStringA strMenu); };   // C3: was FUN_141938a00
class UIItemEnchantDialog { public: unsigned __int64 GetSelectedUid(); };
__int64 GetServerTime();
void Unk_SplitA(CStringA&, ATL::CAtlArray<CStringA>*, const char*);   // C3: the achievedata def at 0x14015f050
class UIGameMenuDialog* FUN_140938b90(int);   // C3: was FUN_140938b90
template<class T> T* GetUIDialog(int nId);                    // the mastery dialog
class UIMasteryDialog   // C3: member view for the former free stand-ins
{
public:
    int GetMainTabIndex();
    int GetSubTabIndex();
};
template<class T> T* Unk_ImGetDialog(int nId);                    // the play instrument dialog
class UIPlayInstrumentDialog   // C3: member view for the former free stand-ins
{
public:
    int GetSelectedTabIndex();
    bool HasAnyScore();
};
class PCBase   // C3: member view for the former free stand-ins
{
public:
    int GetCurStateId();
    int FUN_14166cc80();
    __int64 FUN_1416769f0();
};
class UGCCubePalette* GetUGCCubePalette();   // C3: was FUN_140ef0b20
class CubeHolderManager   // C3: member view for the former free stand-ins
{
public:
    int GetSelectedItemId();
};
template<class T> T* Unk_MMDialog(int nId);                    // the mentoring pane
class CMeratMarketMan   // C3: member view for the former free stand-ins
{
public:
    __int64 GetEarliestSaleEnd();
};
class UIDialog   // C3: member view for the former free stand-ins
{
public:
    int FUN_141924630();
};

// The tab of the mentoring pane (only the name getter) and the dialog of a name (only the busy flag).
class UIMentoringPage
{
public:
    virtual void Unk_Slot0();
    virtual void Unk_Slot1();
    virtual void Unk_Slot2();
    virtual void Unk_Slot3();
    virtual void Unk_Slot4();
    virtual void Unk_Slot5();
    virtual CStringA vfunc_6();
};
class Unk_G9Dlg
{
public:
    virtual void Unk_Slot0();
    virtual void Unk_Slot1();
    virtual void Unk_Slot2();
    virtual void Unk_Slot3();
    virtual void Unk_Slot4();
    virtual void Unk_Slot5();
    virtual void Unk_Slot6();
    virtual void Unk_Slot7();
    virtual void Unk_Slot8();
    virtual void Unk_Slot9();
    virtual void Unk_Slot10();
    virtual void Unk_Slot11();
    virtual void Unk_Slot12();
    virtual void Unk_Slot13();
    virtual void Unk_Slot14();
    virtual void Unk_Slot15();
    virtual void Unk_Slot16();
    virtual void Unk_Slot17();
    virtual void Unk_Slot18();
    virtual void Unk_Slot19();
    virtual void Unk_Slot20();
    virtual void Unk_Slot21();
    virtual void Unk_Slot22();
    virtual void Unk_Slot23();
    virtual void Unk_Slot24();
    virtual void Unk_Slot25();
    virtual void Unk_Slot26();
    virtual void Unk_Slot27();
    virtual void Unk_Slot28();
    virtual void Unk_Slot29();
    virtual void Unk_Slot30();
    virtual void Unk_Slot31();
    virtual void Unk_Slot32();
    virtual void Unk_Slot33();
    virtual void Unk_Slot34();
    virtual void Unk_Slot35();
    virtual void Unk_Slot36();
    virtual void Unk_Slot37();
    virtual void Unk_Slot38();
    virtual void Unk_Slot39();
    virtual void Unk_Slot40();
    virtual void Unk_Slot41();
    virtual void Unk_Slot42();
    virtual void Unk_Slot43();
    virtual void Unk_Slot44();
    virtual void Unk_Slot45();
    virtual void Unk_Slot46();
    virtual void Unk_Slot47();
    virtual void Unk_Slot48();
    virtual void Unk_Slot49();
    virtual void Unk_Slot50();
    virtual void Unk_Slot51();
    virtual void Unk_Slot52();
    virtual void Unk_Slot53();
    virtual void Unk_Slot54();
    virtual int vfunc_55();
};
// The page smart pointer of the mentoring pane (dtor 0x140e60460 releases it).
template<class T> class Unk_MentorPtr
{
public:
    ~Unk_MentorPtr();
    bool IsNull() const;
    T* operator->() const;
    void* m_p0;
    T* m_p;
};
class UIMentoringDialog
{
public:
    Unk_MentorPtr<UIMentoringPage> GetPage();           // the current page
};

template<class T> T* Unk_GaGetUIByName(const CStringA& strName);         // the dialog of a name
class UIDialog* FUN_140c300a0(int);   // C3: was FUN_140c300a0
struct Unk_G9Span { int m_n[7]; int m_nDays; };
struct tm* FUN_1413a52a0(__int64 const*);   // C3: was FUN_1413a52a0
class CubeMapInformationService   // C3: member view for the former free stand-ins
{
public:
    int FUN_1410c3650();
};
class CMyCharacter* FUN_140931510();   // C3: was FUN_140931510
class CMyCharacter   // C3: member view for the former free stand-ins
{
public:
    unsigned int GetDungeonEnterState(unsigned long);
};
bool Unk_GcNoPoint(char*);   // C3: was FUN_1413b57d0


// @0x1413acea0
CStringW CGuideConditionHasMoney::GetTypeName()
{
    return L"CGuideConditionHasMoney";
}

// @0x1413acef0
void CGuideConditionHasMoney::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nMoneyType = 0;
    CStringA strType;
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "moneyType", strType);
    if (strType == "meso")
        m_nMoneyType = 0;
    else if (strType == "merat")
        m_nMoneyType = 1;
    else if (strType == "karma")
        m_nMoneyType = 2;
    else if (strType == "honor")
        m_nMoneyType = 3;
    else if (strType == "lu")
        m_nMoneyType = 4;
}

// @0x1413ad020
int CGuideConditionHasMoney::vfunc_3()
{
    switch (m_nMoneyType) {
    case 0:
        return FUN_1413a5600(DAT_143ab2898 > m_n20);
    case 1:
        return FUN_1413a5600(FUN_140930240() > m_n20);
    case 2:
        return FUN_1413a5600(DAT_143ab28b8 > m_n20);
    case 3:
        return FUN_1413a5600(DAT_143ab28b0 > m_n20);
    case 4:
        return FUN_1413a5600(DAT_143ab28c0 > m_n20);
    case 5:
        return FUN_1413a5600(DAT_143ab28c8 > m_n20);
    case 6:
        return FUN_1413a5600(DAT_143ab28d0 > m_n20);
    case 7:
        return FUN_1413a5600(DAT_143ab28d8 > m_n20);
    case 8:
        return FUN_1413a5600(DAT_143ab28e0 > m_n20);
    default:
        return 0;
    }
}

// @0x1413ad250
CStringW CGuideConditionHasMoney::vfunc_7()
{
    CStringW strType;
    switch (m_nMoneyType)
    {
    case 0:
        strType = L"meso";
        break;
    case 1:
        strType = L"merat";
        break;
    case 2:
        strType = L"karma";
        break;
    case 3:
        strType = L"honor";
        break;
    case 4:
        strType = L"lu";
        break;
    }
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"moneyType({0}), value({1})", strType, m_n20));
    return str;
}

// @0x1413ad3b0
ClassObject* CGuideConditionGuildPvpPeriod::CreateObject()
{
    return new CGuideConditionGuildPvpPeriod;
}

// @0x1413ad410
CStringW CGuideConditionGuildPvpPeriod::GetTypeName()
{
    return L"CGuideConditionGuildPvpPeriod";
}

// @0x1413ad460
int CGuideConditionGuildPvpPeriod::vfunc_3()
{
    return FUN_1413a55a0(((class Unk_GuildSeason*)(void*)(((void*)((class CGuildInfo*)(void*)(&reinterpret_cast<Unk_G9Holder*>(TSingleton<CGuildManager>::GetInstance())->m_p8))->FUN_1404d3180())))->FUN_1404c6160() ? 1 : 0);
}

// @0x1413ad4c0
ClassObject* CGuideConditionRealEstateExpireDays::CreateObject()
{
    return new CGuideConditionRealEstateExpireDays;
}

// @0x1413ad520
CStringW CGuideConditionRealEstateExpireDays::GetTypeName()
{
    return L"CGuideConditionRealEstateExpireDays";
}

// @0x1413ad570
int CGuideConditionRealEstateExpireDays::vfunc_3()
{
    Unk_G9Player* pPlayer = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    Unk_G9Rec* pRec = ((struct Unk_G9Rec*)((class MyPC*)(class Unk_G9Player*)(pPlayer))->FUN_141523c50());
    if (!pRec)
        return 0;
    CMsTime now(GetServerTime());
    CMsTime expire(pRec->m_nExpire);
    if (now >= expire)
        return 0;
    ATL::CTimeSpan span = expire - now;
    __int64 nDays = span.GetDays();
    return FUN_1413a5600(nDays < m_n20);
}

// @0x1413ad660
ClassObject* CGuideConditionUgcProductExpireDays::CreateObject()
{
    return new CGuideConditionUgcProductExpireDays;
}

// @0x1413ad6c0
CStringW CGuideConditionUgcProductExpireDays::GetTypeName()
{
    return L"CGuideConditionUgcProductExpireDays";
}

// @0x1413ad710
int CGuideConditionUgcProductExpireDays::vfunc_3()
{
    if (!FUN_140939a00())
        return 0;
    __int64 nExpire = ((class CMeratMarketMan*)(void*)(FUN_140939a00()))->GetEarliestSaleEnd();
    if (!nExpire)
        return 0;
    CMsTime now(GetServerTime());
    CMsTime expire(nExpire);
    if (now >= expire)
        return 0;
    ATL::CTimeSpan span = expire - now;
    __int64 nDays = span.GetDays();
    return FUN_1413a5600(nDays < m_n20);
}

// @0x1413ad7e0
ClassObject* CGuideConditionJobCode::CreateObject()
{
    return new CGuideConditionJobCode;
}

// @0x1413ad840
CStringW CGuideConditionJobCode::GetTypeName()
{
    return L"CGuideConditionJobCode";
}

// @0x1413ad890
void CGuideConditionJobCode::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 5;
}

// @0x1413ad8d0
int CGuideConditionJobCode::vfunc_3()
{
    Unk_G9Player* pPlayer = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    return FUN_1413a5600(reinterpret_cast<PC*>(pPlayer)->FUN_141654700() == m_n20);
}

// @0x1413ad940
int CGuideConditionJobCode::vfunc_8()
{
    return 0;
}

// @0x1413ad950
ClassObject* FUN_1413ad950()
{
    return new CGuideConditionSubJobCode;
}

// @0x1413ad9b0
CStringW CGuideConditionSubJobCode::GetTypeName()
{
    return L"CGuideConditionSubJobCode";
}

// @0x1413ada00
void CGuideConditionSubJobCode::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    XmlTokenList(pElem, "subJobCodes", m_subJobCodes);
}

// @0x1413ada50
int CGuideConditionSubJobCode::vfunc_3()
{
    Unk_G9Player* pPlayer = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    for (size_t i = 0; i < m_subJobCodes.GetCount(); ++i) {
        int nCode = m_subJobCodes[i];
        if (reinterpret_cast<PC*>(pPlayer)->FUN_141654730() == nCode)
            return FUN_1413a55a0(1);
    }
    return FUN_1413a55a0(0);
}

// @0x1413adb00
ClassObject* CGuideConditionBattleState::CreateObject()
{
    return new CGuideConditionBattleState;
}

// @0x1413adb60
CStringW CGuideConditionBattleState::GetTypeName()
{
    return L"CGuideConditionBattleState";
}

// @0x1413adbb0
void CGuideConditionBattleState::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 0xe;
}

// @0x1413adbf0
int CGuideConditionBattleState::vfunc_3()
{
    Unk_G9Player* pPlayer = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    return FUN_1413a55a0(pPlayer->vfunc_65());
}

// @0x1413adc50
int CGuideConditionBattleState::vfunc_8()
{
    return 0;
}

// @0x1413adc60
ClassObject* CGuideConditionSummonPet::CreateObject()
{
    return new CGuideConditionSummonPet;
}

// @0x1413adcc0
CStringW CGuideConditionSummonPet::GetTypeName()
{
    return L"CGuideConditionSummonPet";
}

// @0x1413add10
int CGuideConditionSummonPet::vfunc_3()
{
    Unk_G9Player* pPlayer = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    return FUN_1413a5600(reinterpret_cast<PCBase*>(pPlayer)->FUN_1416769f0() != 0);
}

// @0x1413add70
ClassObject* CGuideConditionJoinGuild::CreateObject()
{
    return new CGuideConditionJoinGuild;
}

// @0x1413addd0
CStringW CGuideConditionJoinGuild::GetTypeName()
{
    return L"CGuideConditionJoinGuild";
}

// @0x1413ade20
int CGuideConditionJoinGuild::vfunc_3()
{
    return FUN_1413a55a0(((class CGuildManager*)(struct Unk_G9Holder*)(reinterpret_cast<Unk_G9Holder*>(TSingleton<CGuildManager>::GetInstance())))->FUN_1413b6160());
}

// @0x1413ade50
ClassObject* FUN_1413ade50()
{
    return new CGuideConditionMenuExpand;
}

// @0x1413adeb0
CStringW CGuideConditionMenuExpand::GetTypeName()
{
    return L"CGuideConditionMenuExpand";
}

// @0x1413adf00
void CGuideConditionMenuExpand::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "menuName", m_strMenuName);
}

// @0x1413adf50
int CGuideConditionMenuExpand::vfunc_3()
{
    void* pMenu = ((void*)FUN_140938b90(0x4e28));
    if (pMenu != 0)
    {
        int nExpanded = reinterpret_cast<UIGameMenuDialog*>(pMenu)->IsMenuExpanded(m_strMenuName);
        return FUN_1413a55a0(nExpanded);
    }
    return 0;
}

// @0x1413adfd0
CStringW CGuideConditionMenuExpand::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat<CStringW>(L"menuName({0})", FUN_14016a730(m_strMenuName, 0)));
    return str;
}

// @0x1413ae0c0
ClassObject* CGuideConditionSelectItemEnchant::CreateObject()
{
    return new CGuideConditionSelectItemEnchant;
}

// @0x1413ae120
CStringW CGuideConditionSelectItemEnchant::GetTypeName()
{
    return L"CGuideConditionSelectItemEnchant";
}

// @0x1413ae170
int CGuideConditionSelectItemEnchant::vfunc_3()
{
    void* pDlg = FUN_1413b1bc0(0x4e92);
    if (pDlg)
        return FUN_1413a5600(reinterpret_cast<UIItemEnchantDialog*>(pDlg)->GetSelectedUid() != 0);
    return 0;
}

// @0x1413ae1d0
ClassObject* CGuideConditionMasteryMainTabIndex::CreateObject()
{
    return new CGuideConditionMasteryMainTabIndex;
}

// @0x1413ae230
CStringW CGuideConditionMasteryMainTabIndex::GetTypeName()
{
    return L"CGuideConditionMasteryMainTabIndex";
}

// @0x1413ae280
int CGuideConditionMasteryMainTabIndex::vfunc_3()
{
    void* pDlg = GetUIDialog<UIMasteryDialog>(0x4f1e);
    if (pDlg)
        return FUN_1413a5600(((class UIMasteryDialog*)(void*)(pDlg))->GetMainTabIndex() == m_n20);
    return 0;
}

// @0x1413ae2e0
ClassObject* CGuideConditionMasterySubTabIndex::CreateObject()
{
    return new CGuideConditionMasterySubTabIndex;
}

// @0x1413ae340
CStringW CGuideConditionMasterySubTabIndex::GetTypeName()
{
    return L"CGuideConditionMasterySubTabIndex";
}

// @0x1413ae390
int CGuideConditionMasterySubTabIndex::vfunc_3()
{
    void* pDlg = GetUIDialog<UIMasteryDialog>(0x4f1e);
    if (pDlg)
        return FUN_1413a5600(((class UIMasteryDialog*)(void*)(pDlg))->GetSubTabIndex() == m_n20);
    return 0;
}

// @0x1413ae3f0
ClassObject* CGuideConditionPlayInstrumentTabIndex::CreateObject()
{
    return new CGuideConditionPlayInstrumentTabIndex;
}

// @0x1413ae450
CStringW CGuideConditionPlayInstrumentTabIndex::GetTypeName()
{
    return L"CGuideConditionPlayInstrumentTabIndex";
}

// @0x1413ae4a0
int CGuideConditionPlayInstrumentTabIndex::vfunc_3()
{
    void* pDlg = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
    if (pDlg)
        return FUN_1413a5600(((class UIPlayInstrumentDialog*)(void*)(pDlg))->GetSelectedTabIndex() == m_n20);
    return 0;
}

// @0x1413ae500
ClassObject* CGuideConditionPlayInstrumentHasSelectItem::CreateObject()
{
    return new CGuideConditionPlayInstrumentHasSelectItem;
}

// @0x1413ae560
CStringW CGuideConditionPlayInstrumentHasSelectItem::GetTypeName()
{
    return L"CGuideConditionPlayInstrumentHasSelectItem";
}

// @0x1413ae5b0
int CGuideConditionPlayInstrumentHasSelectItem::vfunc_3()
{
    void* pDlg = Unk_ImGetDialog<UIPlayInstrumentDialog>(0x4eec);
    if (pDlg)
        return FUN_1413a5600(((class UIPlayInstrumentDialog*)(void*)(pDlg))->HasAnyScore());
    return 0;
}

// @0x1413ae600
ClassObject* CGuideConditionPlayingInstrument::CreateObject()
{
    return new CGuideConditionPlayingInstrument;
}

// @0x1413ae660
CStringW CGuideConditionPlayingInstrument::GetTypeName()
{
    return L"CGuideConditionPlayingInstrument";
}

// @0x1413ae6b0
int CGuideConditionPlayingInstrument::vfunc_3()
{
    Unk_G9Player* pPlayer = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (((class PCBase*)(class Unk_G9Player*)(pPlayer))->GetCurStateId() != 0x2f)
        return FUN_1413a55a0(0);
    return FUN_1413a5600(((class PCBase*)(class Unk_G9Player*)(pPlayer))->FUN_14166cc80() == 0x7f);
}

// @0x1413ae730
ClassObject* CGuideConditionCubeHolderSelectItem::CreateObject()
{
    return new CGuideConditionCubeHolderSelectItem;
}

// @0x1413ae790
CStringW CGuideConditionCubeHolderSelectItem::GetTypeName()
{
    return L"CGuideConditionCubeHolderSelectItem";
}

// @0x1413ae7e0
int CGuideConditionCubeHolderSelectItem::vfunc_3()
{
    if (!((void*)GetUGCCubePalette()))
        return 0;
    return FUN_1413a5600(((class CubeHolderManager*)(void*)(((void*)GetUGCCubePalette())))->GetSelectedItemId() == m_n20);
}

// @0x1413ae840
ClassObject* CGuideConditionHasStatPoint::CreateObject()
{
    return new CGuideConditionHasStatPoint;
}

// @0x1413ae8a0
CStringW CGuideConditionHasStatPoint::GetTypeName()
{
    return L"CGuideConditionHasStatPoint";
}

// @0x1413ae8f0
int CGuideConditionHasStatPoint::vfunc_3()
{
    void* pStat = MyPC::FUN_141530930();
    if (!pStat)
        return 0;
    return FUN_1413a5600(static_cast<unsigned>(static_cast<MyPC*>(pStat)->FUN_140c25130()->GetRemaining()) > 0);
}

// @0x1413ae990
ClassObject* FUN_1413ae990()
{
    return new CGuideConditionMentoringPage;
}

// @0x1413ae9f0
CStringW CGuideConditionMentoringPage::GetTypeName()
{
    return L"CGuideConditionMentoringPage";
}

// @0x1413aea40
void CGuideConditionMentoringPage::vfunc_2(TiXmlElement* pElem)
{
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "pageName", m_strPageName);
}

// @0x1413aea80
int CGuideConditionMentoringPage::vfunc_3()
{
    void* pPane = Unk_MMDialog<UIMentoringDialog>(0x4f4b);
    if (pPane)
    {
        if (((class UIDialog*)(void*)(pPane))->FUN_141924630() == 0)
            return 0;
        Unk_MentorPtr<UIMentoringPage> it = static_cast<UIMentoringDialog*>(pPane)->GetPage();
        if (it.IsNull())
            return 0;
        UIMentoringPage* pNamed = it.operator->();
        bool bDiffer = pNamed->vfunc_6() != m_strPageName;
        if (bDiffer)
            return 0;
        return 1;
    }
    return 0;
}

// @0x1413aebb0
CStringW CGuideConditionMentoringPage::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat<CStringW>(L"pageName({0})", FUN_14016a730(m_strPageName, 0)));
    return str;
}

// @0x1413aeca0
ClassObject* FUN_1413aeca0()
{
    return new CGuideConditionButtonSelected;
}

// @0x1413aed00
CStringW CGuideConditionButtonSelected::GetTypeName()
{
    return L"CGuideConditionButtonSelected";
}

// @0x1413aed50
CGuideConditionButtonSelected::CGuideConditionButtonSelected()
{
}

// @0x1413aedb0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionButtonSelected::vfunc_3()
{
    Unk_G9Dlg* pDlg = 0;
    if (!pDlg)
        pDlg = (Unk_G9Dlg*)Unk_GaGetUIByName<UIDialog>(m_strDialog);
    if (!pDlg)
        return 0;
    if (pDlg->vfunc_55() != 0)
        return 0;
    if (m_children.GetCount() != 0) {
        MS2Ptr<ASDisplayObject> root = reinterpret_cast<UISwfEntity*>(pDlg)->FUN_1422dba50();
        if (root.get()) {
            for (size_t i = 0; i < m_children.GetCount(); ++i) {
                BOOL bLast = i == m_children.GetCount() - 1;
                if (bLast) {
                    MS2Ptr<ASButton> leaf = root->FUN_140acce30<ASButton>(m_children[i]);
                    if (leaf == 0)
                        return 0;
                    if (!leaf->GetVisible())
                        return 0;
                    return leaf->FUN_1422ce0e0();
                } else {
                    root = root->FUN_140e159f0<ASDisplayObject>(m_children[i]);
                    if (root == 0)
                        return 0;
                    if (!root->GetVisible())
                        return 0;
                }
            }
        }
    }
    return 0;
}

// @0x1413af0c0
void CGuideConditionButtonSelected::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    if (m_b1c)
        throw std::exception("ButtonSelected is Not Allow Keword 'not'");
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "dialogName", m_strDialog);
    CStringA strChild;
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "childName", strChild);
    Unk_SplitA(strChild, &m_children, ".");
}

// @0x1413af190
CStringW CGuideConditionButtonSelected::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat<CStringW>(L"dialogName({0})", FUN_14016a730(m_strDialog, 0)));
    return str;
}

// @0x1413af280
ClassObject* FUN_1413af280()
{
    return new CGuideConditionContract;
}

// @0x1413af2e0
CStringW CGuideConditionContract::GetTypeName()
{
    return L"CGuideConditionContract";
}

// @0x1413af330
CGuideConditionContract::CGuideConditionContract()
    : m_nDialogId(0), m_strChild(""), m_strDialog("")
{
}

// @0x1413af3b0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionContract::vfunc_3()
{
    Unk_G9Player* pPlayer = static_cast<Unk_G9Player*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    Unk_G9Rec* pRec = ((struct Unk_G9Rec*)((class MyPC*)(class Unk_G9Player*)(pPlayer))->FUN_141523c50());
    if (!pRec)
        return 0;
    void* pDlg = 0;
    if (m_nDialogId != 0)
        pDlg = ((void*)FUN_140c300a0(m_nDialogId));
    if (!pDlg)
        pDlg = Unk_GaGetUIByName<UIDialog>(m_strDialog);
    if (!pDlg)
        return 0;
    MS2Ptr<ASDisplayObject> val = static_cast<UISwfEntity*>(pDlg)->GetChild<ASDisplayObject>(m_strChild);
    if (val == 0)
        return 0;
    if (!val->GetVisible())
        return 0;
    const __int64& nLeft = pRec->m_nExpire - GetServerTime();
    Unk_G9Span* pInfo = ((struct Unk_G9Span*)FUN_1413a52a0(&nLeft));
    if (pInfo && pInfo->m_nDays <= 7)
        return 1;
    return 0;
}

// @0x1413af560
void CGuideConditionContract::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    XmlGetAttr((class TiXmlElement*)(pElem), "dialogID", m_nDialogId);
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "childName", m_strChild);
    XmlGetAttr(reinterpret_cast<TiXmlElement*>(pElem), "dialogName", m_strDialog);
}

// @0x1413af5e0
CStringW CGuideConditionContract::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"dialogName({0}), dialogName({1}), dialogName({2})", m_nDialogId, FUN_14016a730(m_strChild, 0), FUN_14016a730(m_strDialog, 0)));
    return str;
}

// @0x1413af740
ClassObject* FUN_1413af740()
{
    return new CGuideConditionHomeMode;
}

// @0x1413af7a0
CStringW CGuideConditionHomeMode::GetTypeName()
{
    return L"CGuideConditionHomeMode";
}

// @0x1413af7f0
CGuideConditionHomeMode::CGuideConditionHomeMode()
    : m_nMode(0)
{
}

// @0x1413af830
int CGuideConditionHomeMode::vfunc_3()
{
    return FUN_1413a5600(((class CubeMapInformationService*)(class Unk_G9Home*)(Unk_AkoHouseSvc::GetInstance()))->FUN_1410c3650() == m_nMode);
}

// @0x1413af880
void CGuideConditionHomeMode::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1f30(pElem, "mode", m_nMode);
}

// @0x1413af8d0
CStringW CGuideConditionHomeMode::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"mode({0})", reinterpret_cast<const Unk_GcModeId&>(m_nMode)));
    return str;
}

// @0x1413af980
ClassObject* CGuideConditionEnterDungeon::CreateObject()
{
    return new CGuideConditionEnterDungeon;
}

// @0x1413af9e0
CStringW CGuideConditionEnterDungeon::GetTypeName()
{
    return L"CGuideConditionEnterDungeon";
}

// @0x1413afa30
CGuideConditionEnterDungeon::CGuideConditionEnterDungeon()
{
}

// @0x1413afa70
void CGuideConditionEnterDungeon::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 10;
}

// @0x1413afab0
int CGuideConditionEnterDungeon::vfunc_3()
{
    int nState = ((class CMyCharacter*)(void*)(((void*)FUN_140931510())))->GetDungeonEnterState(m_n20);
    return FUN_1413a5600(nState == 0 || nState == 1);
}

// @0x1413afb10
int CGuideConditionEnterDungeon::vfunc_8()
{
    return 0;
}

// @0x1413afb20
ClassObject* CGuideConditionChatEmoticon::CreateObject()
{
    return new CGuideConditionChatEmoticon;
}

// @0x1413afb80
CStringW CGuideConditionChatEmoticon::GetTypeName()
{
    return L"CGuideConditionChatEmoticon";
}

// @0x1413afbd0
CGuideConditionChatEmoticon::CGuideConditionChatEmoticon()
{
}

// @0x1413afc10
void CGuideConditionChatEmoticon::vfunc_2(TiXmlElement* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 9;
}

// @0x1413afc50
int CGuideConditionChatEmoticon::vfunc_3()
{
    void* pDlg = FUN_1413b1b20(0x4f80);
    if (pDlg)
        return FUN_1413a5600(Unk_GcNoPoint((char*)(pDlg)));
    return 0;
}

// @0x1413afca0
int CGuideConditionChatEmoticon::vfunc_8()
{
    return 0;
}
// MS2-PIN: ??0CMsTime@@QEAA@_J@Z 0x1406c47a0
// MS2-PIN: ??GCMsTime@@QEBA?AVCTimeSpan@ATL@@AEBV0@@Z 0x1406c4a20
// MS2-PIN: ??1?$Unk_MentorPtr@VUIMentoringPage@@@@QEAA@XZ 0x140e60460
// MS2-PIN: ?GetPage@UIMentoringDialog@@QEAA?AV?$Unk_MentorPtr@VUIMentoringPage@@@@XZ 0x140e5e890
