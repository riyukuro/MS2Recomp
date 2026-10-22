// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIIndividualPvPDialog: see uiindividualpvpdialog.h.
// MS2-UNIT: ?\uiindividualpvpdialog.cpp
// MS2-RANGE: 0x1412c9e70-0x1412d1400 .text$mn
// MS2-RANGE: 0x1400edb60-0x1400edcd0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400edc20 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400edc50 ; probe
// MS2-PIN: ??$?0VUIIndividualPvPDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIIndividualPvPDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x1412cc160 ; unique
// MS2-PIN: ??0?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAA@XZ 0x1412ce320 ; unique
// MS2-PIN: ??1?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAA@XZ 0x1412ce710 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@CAXPEAU?$pair@HH@std@@_K@Z 0x1412cec60 ; unique
// MS2-PIN: ??A?$CAtlArray@U?$pair@HH@std@@V?$CElementTraits@U?$pair@HH@std@@@ATL@@@ATL@@QEAAAEAU?$pair@HH@std@@_K@Z 0x1412cf2b0 ; unique
// MS2-PIN: ?vfunc_48@UIIndividualPvPDialog@@UEAAHXZ 0x1412cf410 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIIndividualPvPDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1412d0d60 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIIndividualPvPDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1412d1140 ; unique
// MS2-PIN: ??$Call@VUIIndividualPvPDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIIndividualPvPDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIIndividualPvPDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1412d1170 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIIndividualPvPDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1412d11b0 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4IndividualArenaStringId@@@ATL@@SAHAEBW4IndividualArenaStringId@@0@Z 0x1412cecf0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiindividualpvpdialog.cpp"    // assumed
#ifndef _HAS_AUTO_PTR_ETC
#define _HAS_AUTO_PTR_ETC 1
#endif

#include "ms2/placeholder/ms2stdafx.h"
#include "uiindividualpvpdialog.h"
#include <atlcoll.h>
#include <memory>
#include "pcbase.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/stringmanager.h"
#include "ms2/placeholder/stringxmlproc.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

// An arena button.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422cdfb0(const CStringW& strText);                // set the label
    void FUN_1422ce090(int bSelected);
    void FUN_1422ce240(const ParamsDelegate& cb, void* pUser);  // click callback
    void FUN_1422c2a70(const ParamsDelegate& cb, void* pUser);  // click callback (event form)
    void FUN_1422c1fe0(unsigned int bEnabled);
    void FUN_1407cbb20(const char* szName, CStringW strText);   // set a string member
    void FUN_1409c0e60(const char* szName, const wchar_t* szText);
};

// A row of Table/individualarena.xml.
class Unk_ArenaData : public CPtred
{
public:
    int m_18;
    int m_nNameId;                                              // +0x1c string id of the name
    int m_nDetailId;                                            // +0x20 string id of the detail
    int m_24;
    CString m_strBanner;                                        // +0x28 banner file
    int m_30;
    int m_34;
    unsigned int m_nReward1;                                    // +0x38 reward item ids
    int m_3c;
    int m_40;
    unsigned int m_nReward2;                                    // +0x44
};
class Unk_ArenaTable { public: MS2Ptr<Unk_ArenaData> FUN_14051a980(int nArena); };
Unk_ArenaTable* FUN_1412818c0();

// The PvP manager.
class Unk_PvpMgr
{
public:
    int FUN_1412818a0();                                        // the state: 0 idle, 1 registered, 2 ready
    int FUN_1412818d0();                                        // the registered arena
    void FUN_141280d40();                                       // join
};
Unk_PvpMgr* FUN_140f97ef0();

class Unk_PCBaseBuffs { public: int FUN_140970020(int nBuffId, unsigned short nLevel, int nOwner, int nStacks); };

bool FUN_140a467d0(const MS2Ptr<AScript>* p);
void* FUN_140bb9630(int n);                                     // int -> delegate user data
int FUN_140bb9640(void* p);                                     // delegate user data -> int
CString FUN_1402bb1c0(const char* szFormat, const int* pn);     // format one int
CStringW GetStringCommon(int nStringId);                          // string table text
CStringW FUN_1408116a0(int nStringId, const int& nArg);         // the same, one int argument
void FUN_140d73aa0(CStringW text, int nA, int nB, CStringW tag);   // notice
unsigned int FUN_14086bdb0(unsigned int nMilliSeconds);         // to minutes
void FUN_1408741a0(void* pCfg, const char* szSection, const char* szKey, int* pnValue);
void FUN_140874440(void* pCfg, const char* szSection, const char* szKey, int nValue, bool b);
void* FUN_1403ed2d0();                                          // the world
PCBase* FUN_141bd0cc0(void* pWorld);                            // the own player
CFeatureManager* FUN_140166410();
CGameRule* FUN_1401c0d90();
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags);
void FUN_141415600(const CString& strName);
void FUN_140710590(COutPacket&);
StringManager* GetStringManager();

// the string table loader of the arena strings
CLogString* GetLogString();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
class Unk_XmlFiles { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_XmlFiles* FUN_140166420();
CString FUN_14071ae20(const CString& strFile);
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszAttr, CStringW strDefault);

// @0x1412c9e70
UIIndividualPvPDialog::UIIndividualPvPDialog() : m_nLastPage(1), m_nSelected(0)
{
    m_strBannerDir = L"./Data/Resource/Image/Map/DungeonBanner/";
}

// @0x1412c9fa0
UIIndividualPvPDialog::~UIIndividualPvPDialog()
{
}

// @0x1412ca080
CString UIIndividualPvPDialog::GetTypeName()
{
    return CString("IndividualPvPDialog");
}

// @0x1412ca0d0
void UIIndividualPvPDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
}

// @0x1412ca0f0
// MS2-FUNCTIONAL: temp/spill layout of the child bindings differs (exe 2558 bytes, 0x2b8 frame)
void UIIndividualPvPDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    m_spRegister = FUN_140bb4b10("m_registPVP");
    m_spUnregister = FUN_140bb4b10("m_unregistPVP");
    m_spJoin = FUN_140bb4b10("m_joinPVP");
    m_spName = FUN_140bb4cf0("m_arenaName");
    m_spDetail = FUN_140bb4cf0("m_arenaDetail");
    m_spRegister->FUN_1422ce240(ParamsDelegate(this, &UIIndividualPvPDialog::FUN_1412cb4e0), 0);
    m_spUnregister->FUN_1422c2a70(ParamsDelegate(this, &UIIndividualPvPDialog::SendPVPMode10), 0);
    m_spJoin->FUN_1422ce240(ParamsDelegate(this, &UIIndividualPvPDialog::FUN_1412cb4b0), 0);
    m_arenas.clear();
    for (int i = 1; i < 4; i++)
    {
        CString strName = FUN_1402bb1c0("m_arena{0}", &i);
        MS2Ptr<Unk_140acd6e0> spArena = FUN_140bb4b10(strName);
        if (spArena.get())
        {
            m_arenas[i] = spArena;
            m_arenas[i]->FUN_1422c2a70(ParamsDelegate(this, &UIIndividualPvPDialog::FUN_1412cb7e0), FUN_140bb9630(i));
        }
    }
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator it = m_arenas.begin();
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator itEnd = m_arenas.end();
    for (; it != itEnd; ++it)
    {
        MS2Ptr<Unk_ArenaData> spData = FUN_1412818c0()->FUN_14051a980(it->first);
        if (spData == 0)
            return;
        CStringW strName = GetStringManager()->GetText(StringXmlCategory(4), IndividualArenaStringId(spData->m_nNameId));
        it->second->FUN_1422cdfb0(strName);
        it->second->FUN_1407cbb20("label2", GetStringCommon(0x425));
    }
    if (m_arenas.empty())
        return;
    if (m_nLastPage == 2)
        m_nLastPage = 1;
    if (m_nLastPage < 4 && 1 < m_nLastPage)
    {
        m_arenas[m_nLastPage]->FUN_1422ce090(1);
        FUN_1412cae10(m_nLastPage);
    }
    else
    {
        m_arenas.begin()->second->FUN_1422ce090(1);
        FUN_1412cae10(m_arenas.begin()->first);
    }
    FUN_1412cb240();
    m_arenas[2]->FUN_1422c1fe0(0);
    m_arenas[2]->FUN_1409c0e60("label2", L"");
}

// @0x1412cab00
void UIIndividualPvPDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_spJoin = 0;
    m_spRegister = 0;
    m_spUnregister = 0;
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator it = m_arenas.begin();
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator itEnd = m_arenas.end();
    for (; it != itEnd; ++it)
        it->second = 0;
    m_arenas.clear();
    FUN_1412cbe90();
}

// @0x1412cabf0
int UIIndividualPvPDialog::vfunc_54(void* pCfg)
{
    UIDialog::vfunc_54(pCfg);
    FUN_1408741a0(pCfg, "Convenience", "lastPage", &m_nLastPage);
    return 1;
}

// @0x1412cac50
int UIIndividualPvPDialog::vfunc_53(void* pCfg)
{
    m_nLastPage = m_nSelected;
    UIDialog::vfunc_53(pCfg);
    FUN_140874440(pCfg, "Convenience", "lastPage", m_nLastPage, true);
    return 1;
}

// @0x1412cacc0
void UIIndividualPvPDialog::FUN_1412cacc0()
{
    if (FUN_140a467d0(&m_30))
        return;
    int nState = FUN_140f97ef0()->FUN_1412818a0();
    int nArena = FUN_140f97ef0()->FUN_1412818d0();
    FUN_1412cbf20();
    if (nArena != m_nSelected)
    {
        m_spRegister->vfunc_3(1);
    }
    else
    {
        if (nState == 0)
            m_spRegister->vfunc_3(1);
        else if (nState == 1)
            m_spUnregister->vfunc_3(1);
        else if (nState == 2)
            m_spJoin->vfunc_3(1);
    }
    FUN_1412cb8d0(false);
}

// @0x1412cae10
void UIIndividualPvPDialog::FUN_1412cae10(int nArena)
{
    if (FUN_140a467d0(&m_30))
        return;
    if (nArena == 2)
        return;
    MS2Ptr<Unk_ArenaData> spData = FUN_1412818c0()->FUN_14051a980(nArena);
    if (spData == 0)
        return;
    m_nSelected = nArena;
    m_spName->FUN_1422c4cd0(GetStringManager()->GetText(StringXmlCategory(4), IndividualArenaStringId(spData->m_nNameId)));
    m_spDetail->FUN_1422c4f00(GetStringManager()->GetText(StringXmlCategory(4), IndividualArenaStringId(spData->m_nDetailId)));
    FUN_1412cacc0();
    m_30->Invoke("setBanner", CStringW(m_strBannerDir), CString(spData->m_strBanner));
    ASObj rewards(2);
    ASObj first(2);
    ASObj second(2);
    first.FUN_1407cba60("binding", FUN_1412cbc20(spData->m_nReward1));
    rewards.FUN_1409eb270("reward1", first);
    second.FUN_1407cba60("binding", FUN_1412cbc20(spData->m_nReward2));
    rewards.FUN_1409eb270("reward2", second);
    m_30->Invoke("setRewardItem", rewards);
}

// @0x1412cb220
void UIIndividualPvPDialog::FUN_1412cb220()
{
    FUN_1412cb8d0(true);
}

// @0x1412cb240
void UIIndividualPvPDialog::FUN_1412cb240()
{
    if (FUN_140a467d0(&m_30))
        return;
    ATL::CAtlArray<std::pair<int, int> > counts;
    FUN_1401c0d90()->FUN_140477ab0(counts);
    for (unsigned int i = 0; i < counts.GetCount(); i++)
    {
        std::pair<int, int> count = counts[i];
        if (m_arenas.find(count.first) == m_arenas.end())
            continue;
        if (count.first == 2)
            continue;
        int nMinutes = FUN_14086bdb0(count.second);
        int nMax = 10;
        CStringW strText = FUN_1408116a0(0x426, nMinutes);
        if (count.second == 0)
            strText = GetStringCommon(0x425);
        else if (nMinutes > nMax)
            strText = GetStringCommon(0x427);
        m_arenas[count.first]->FUN_1407cbb20("label2", strText);
    }
}

// @0x1412cb4b0
void UIIndividualPvPDialog::FUN_1412cb4b0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140f97ef0()->FUN_141280d40();
}

// @0x1412cb4e0
void UIIndividualPvPDialog::FUN_1412cb4e0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nState = FUN_140f97ef0()->FUN_1412818a0();
    if (nState != 0)
    {
        FUN_140d73aa0(GetStringCommon(0x428), 0, 0, L"");
        return;
    }
    PCBase* pPC = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPC == 0)
        return;
    if (pPC->FUN_1416749a0()->FUN_140970020(0x5f5e107, 0, 0, 1) != 0)
    {
        FUN_140d73aa0(GetStringCommon(0x429), 0, 0, L"");
        return;
    }
    if ((unsigned short)pPC->vfunc_78() < (unsigned short)FUN_140166410()->FUN_14036dc20())
    {
        FUN_140d73aa0(GetStringCommon(0x42a), 0, 0, L"");
        return;
    }
    if (m_nSelected == 2)
        return;
    {
        COutPacket packet(0x61, 0);
        packet.Encode1(9);
        packet.Encode4(m_nSelected);
        FUN_140710590(packet);
    }
}

// @0x1412cb770
void UIIndividualPvPDialog::SendPVPMode10(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nState = FUN_140f97ef0()->FUN_1412818a0();
    if (nState != 1)
        return;
    COutPacket packet(0x61, 0);
    packet.Encode1(10);
    FUN_140710590(packet);
}

// @0x1412cb7e0
void UIIndividualPvPDialog::FUN_1412cb7e0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    int nArena = FUN_140bb9640(params.pUserData);
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator it = m_arenas.begin();
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator itEnd = m_arenas.end();
    for (; it != itEnd; ++it)
    {
        if (it->first == nArena)
            it->second->FUN_1422ce090(1);
        else
            it->second->FUN_1422ce090(0);
    }
    FUN_1412cae10(nArena);
}

// @0x1412cb8d0
void UIIndividualPvPDialog::FUN_1412cb8d0(bool bPlay)
{
    if (FUN_140a467d0(&m_30))
        return;
    int nState = FUN_140f97ef0()->FUN_1412818a0();
    int nArena = FUN_140f97ef0()->FUN_1412818d0();
    if (nArena >= 4)
        return;
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator it = m_arenas.begin();
    std::map<int, MS2Ptr<Unk_140acd6e0> >::iterator itEnd = m_arenas.end();
    for (; it != itEnd; ++it)
    {
        MS2Ptr<Unk_140acd6e0>& spButton = it->second;
        MS2Ptr<ASMovieClip> spEffect = spButton->FUN_1409b4560("m_effect");
        if (spEffect.get())
            spEffect->vfunc_15("hide");
    }
    if (nState == 1)
    {
        if (m_arenas.find(nArena) == m_arenas.end())
            return;
        MS2Ptr<Unk_140acd6e0> spArena = m_arenas[nArena];
        if (spArena.get())
        {
            MS2Ptr<ASMovieClip> spEffect = spArena->FUN_1409b4560("m_effect");
            if (spEffect.get())
            {
                if (bPlay)
                    spEffect->vfunc_13("play");
                else
                    spEffect->vfunc_15("show");
            }
        }
    }
}

// @0x1412cbc20
CString UIIndividualPvPDialog::FUN_1412cbc20(unsigned int nItemId)
{
    CString strKey;
    strKey.Format("%s_%d", (const char*)GetTypeName(), nItemId);
    if (m_icons.find(strKey) == m_icons.end())
    {
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, 1, 0))
            return CString("");
        FUN_141415450(strKey, spItem, 0, 0x401, 0);
        m_icons.insert(strKey);
    }
    return strKey;
}

// @0x1412cbe90
void UIIndividualPvPDialog::FUN_1412cbe90()
{
    std::set<CString>::iterator it = m_icons.begin();
    std::set<CString>::iterator itEnd = m_icons.end();
    for (; it != itEnd; ++it)
        FUN_141415600(*it);
    m_icons.clear();
}

// @0x1412cbf20
void UIIndividualPvPDialog::FUN_1412cbf20()
{
    m_spJoin->vfunc_3(0);
    m_spRegister->vfunc_3(0);
    m_spUnregister->vfunc_3(0);
}

// ---- StringXmlProc<IndividualArenaStringId>: the table behind GetStringManager()->GetText(4, id) ----

// @0x1412cc350
template <class T> CStringW StringManager::GetText(StringXmlCategory category, T id)
{
    ATL::CRBMap<StringXmlCategory, MS2Ptr<StringXmlProcBase> >::CPair* pPair = m_tables.Lookup(category);
    if (pPair == 0)
        return CStringW(L"");
    StringXmlProc<T>* pProc = dynamic_cast<StringXmlProc<T>*>(pPair->m_value.get());
    if (pProc == 0)
        return CStringW(L"");
    return pProc->GetText(id);
}

template <class T> typename StringXmlProc<T>::ValueMap* StringXmlProc<T>::LoadData()
{
    Unk_140165cf0* pRoot = 0;
    ValueMap* pMap;
    TiXmlDocument doc;
    do
    {
        if (m_path18.IsEmpty())
            break;
        CString strPath = FUN_14071ae20(m_path18);
        if (strPath.IsEmpty())
            break;
        if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
            break;
        pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    } while (0);
    if (pRoot == 0)
    {
        FUN_14015eb90(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", m_path18);
        return 0;
    }
    pMap = new ValueMap(10);
    std::auto_ptr<KeyMap> names = m_factory30();
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("key"); pElem != 0; pElem = pElem->FUN_140168650("key"))
    {
        CStringW strName = FUN_1401bf530(pElem, m_keyAttribute20, CStringW(L""));
        CStringW strText = FUN_1401bf530(pElem, m_valueAttribute28, CStringW(L""));
        typename KeyMap::CPair* pPair = names->Lookup(strName);
        if (pPair == 0)
        {
            FUN_14015eb90(GetLogString(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", m_path18);
            delete pMap;
            pMap = 0;
            return 0;
        }
        pMap->SetAt(pPair->m_value, strText);
    }
    return pMap;
}

template <class T> CStringW StringXmlProc<T>::GetText(T id)
{
    ValueMap* pMap = GetData();
    if (pMap == 0)
        return CStringW(L"");
    typename ValueMap::CPair* pPair = pMap->Lookup(id);
    if (pPair == 0)
        return CStringW(L"");
    return CStringW(pPair->m_value);
}

template <class T> typename StringXmlProc<T>::ValueMap* StringXmlProc<T>::GetData()
{
    if (m_cached38 == 0)
        m_cached38 = LoadData();
    return m_cached38;
}

template CStringW StringManager::GetText<IndividualArenaStringId>(StringXmlCategory, IndividualArenaStringId);
template CStringW StringXmlProc<IndividualArenaStringId>::GetText(IndividualArenaStringId);
template StringXmlProc<IndividualArenaStringId>::ValueMap* StringXmlProc<IndividualArenaStringId>::GetData();
template StringXmlProc<IndividualArenaStringId>::ValueMap* StringXmlProc<IndividualArenaStringId>::LoadData();

// Comparator of the (unreferenced) ordered tables keyed by IndividualArenaStringId.
// @0x1412cecf0
__declspec(selectany) extern int(__cdecl* const ms2_pfnPvpCompare)(const IndividualArenaStringId&, const IndividualArenaStringId&) = &ATL::CDefaultCompareTraits<IndividualArenaStringId>::CompareElementsOrdered;

void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);

// @0x1412cc450
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CString a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1.GetString());
    FUN_1422bce70(args.FUN_1409b1f70(1), a2.GetString());
    return FUN_1422bb8f0(szMethod, args);
}   // MS2-FUNCTIONAL: not byte-matched (call order/EH state layout)

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
// @0x1412d12e0
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: source spelling differs
static __inline errno_t ms2_pvp_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnPvpMemcpyS)(void*, size_t, const void*, size_t) = &ms2_pvp_memcpy_s;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caf4c0-0x142caf550 .text$yd
