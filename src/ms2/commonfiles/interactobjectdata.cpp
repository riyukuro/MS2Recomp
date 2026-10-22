// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CInteractObjectData, the interact object table
// (Table/InteractObject.xml + Table/InteractObject_mastery.xml): the <interact> row loader, the id map with its lock and
// init flag, and the CAtlMap / CAtlArray / std::vector / MS2Ptr / fmt log glue they instantiate. The layout is in
// ms2/placeholder/cinteractobjectdata.h.
// MS2-UNIT: ?\interactobjectdata.cpp
// MS2-RANGE: 0x1400b9150-0x1400b9290 .text$di
// MS2-RANGE: 0x14051c920-0x140523790 .text$mn
// MS2-RANGE: 0x142c9aaa0-0x142c9ab10 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$XmlValue@W4Unk_InteractObjectType@@@@YAHPEAVUnk_140165cf0@@PEBDAEAW4Unk_InteractObjectType@@@Z 0x14051fc90 ; unique
// MS2-PIN: ??$XmlValue@W4Unk_InteractMasteryType@@@@YAHPEAVUnk_140165cf0@@PEBDAEAW4Unk_InteractMasteryType@@@Z 0x14051fd20 ; prop
// MS2-PIN: ??A?$vector@GV?$allocator@G@std@@@std@@QEAAAEAG_K@Z 0x1405212b0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCInteractObjectData@@@@AEBAXPEAX@Z 0x140522e20 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\interactobjectdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <stdlib.h>
#include <typeinfo>
#include <utility>
#include <vector>
#include "ms2/placeholder/cinteractobjectdata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- helpers of other units ----
int FUN_14015f500(Unk_140165cf0* pElem, const char* pszName, int* pnRank);   // item rank attribute
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);
unsigned int FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned int nDefault);
float FUN_1401973d0(Unk_140165cf0* pElem, const char* pszName, float fDefault);
bool FUN_14028f710(Unk_140165cf0* pElem);                               // the element is usable
void FUN_14028c2d0(CString strText, Unk_PDVec3* pOut);                  // "x,y,z" -> point
int FUN_140764310(const CStringA& strQuests, const CStringA& strStates, QuestMask* pMask);   // questmasktable.cpp
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);  // data file path
CString FUN_14016a5c0(const char* psz, int n);
CLogString* GetLogString();
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);                      // the item data of an id
// The one-argument log of additionalactionadditional.cpp (an FMT_VARIADIC instance it emitted first).
void FUN_140177a80(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const unsigned& nArg);

// QuestMask's entry array (+0x20; the shared placeholder keeps the mask opaque, unit_140266860.cpp has the class).
enum Unk_MaskEntry { Unk_MaskEntry_Unset = 0 };
struct Unk_QuestMaskView
{
    void* m_pad_00[4];
    ATL::CAtlArray<Unk_MaskEntry> m_aMask;  // +0x20
};
MS2_CHECK_SIZE(Unk_QuestMaskView, 0x40);

// The unit's log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0).
template <class A>
inline void Unk_InteractLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const A& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    pLog->FUN_1406530d0(nLevel, nCategory, pszFormat, fmt::ArgList(fmt::internal::make_type(first), args));
}
template <class A, class B>
inline void Unk_InteractLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const A& first,
                            const B& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    pLog->FUN_1406530d0(nLevel, nCategory, pszFormat, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// ---- statics (.text$di 0x1400b9150 / 0x1400b91a0 / 0x1400b91d0) ----
#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's table, lock and flag (symbols-manual.tsv)
ATL::CAtlMap<int, MS2Ptr<CInteractObjectData> > CInteractObjectData::s_table;
CLockCriticalSection CInteractObjectData::s_lock;
bool CInteractObjectData::s_bInit;
#endif
// A header table of the black market sort names (unused here).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x14051c920
void CInteractObjectData::ExpInfo::Load(Unk_140165cf0* pElem, const char* pszType, const char* pszRate)
{
    FUN_140873360(pElem, pszRate, m_fRate);
    CString strType = FUN_14015f710(pElem, pszType, CString(""));
    if (strType == "telescope")
        m_eType = Unk_InteractExpType_Telescope;
    else if (strType == "rareChestFirst")
        m_eType = Unk_InteractExpType_RareChestFirst;
    else if (strType == "rareChest")
        m_eType = Unk_InteractExpType_RareChest;
    else if (strType == "normalChest")
        m_eType = Unk_InteractExpType_NormalChest;
    else if (strType == "dungeonBoss")
        m_eType = Unk_InteractExpType_DungeonBoss;
}
MS2_REPLACE_METHOD(0x14051C920, CInteractObjectData::ExpInfo, Load, 311, 0x8BFF1EDF);

// @0x14051ca60
int CInteractObjectData::ExpInfo::IsValid()
{
    return m_eType == Unk_InteractExpType_None || m_fRate <= 0 ? FALSE : TRUE;
}
MS2_REPLACE_METHOD(0x14051CA60, CInteractObjectData::ExpInfo, IsValid, 57, 0x581EE53D);

// @0x14051caa0
CInteractObjectData::CInteractObjectData()
    : m_nId(0), m_eType(Unk_InteractObjectType_None), m_nCollection(0), m_nReactCount(0), m_nResetTime(0),
      m_nReactTime(0), m_nHideTime(0)
{
}

// @0x14051cd40
CInteractObjectData::~CInteractObjectData()
{
}

// @0x14051ce70
// MS2-FUNCTIONAL: 9 KB loader; EH-state/temp-CString layout not byte-reproduced (precedent reactordata.cpp), behaviour follows the decompile branch by branch
bool CInteractObjectData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_nId);
    XmlValue(pElem, "type", m_eType);
    FUN_1408731e0(pElem, "collection", m_nCollection);
    FUN_140873220(pElem, "reactCount", m_nReactCount);
    if (m_eType == Unk_InteractObjectType_None)
        return false;

    if (Unk_140165cf0* pMesh = pElem->FUN_140165cf0("mesh"))
    {
        FUN_1408731e0(pMesh, "normalCollision", m_mesh.m_nNormalCollision);
        FUN_1408731e0(pMesh, "reactableCollision", m_mesh.m_nReactableCollision);
        FUN_1408733e0(pMesh, "reactObjectAni", m_mesh.m_strReactObjectAni);
        CString strShape = FUN_14015f710(pMesh, "shapeDimension", CString(""));
        FUN_14028c2d0(strShape, &m_mesh.m_shapeDimension);
    }
    if (Unk_140165cf0* pUi = pElem->FUN_140165cf0("ui"))
    {
        m_ui.m_strSwf = FUN_14015f710(pUi, "swf", CString(""));
        m_ui.m_strValue = FUN_14015f710(pUi, "value", CString(""));
    }
    if (Unk_140165cf0* pGathering = pElem->FUN_140165cf0("gathering"))
        FUN_1408731e0(pGathering, "receipeID", m_gathering.m_nReceipeId);
    if (Unk_140165cf0* pValidate = pElem->FUN_140165cf0("validate"))
    {
        m_validate.m_nFieldId = FUN_140197350(pValidate, "fieldID", 0);
        m_validate.m_fInteractionDistance = FUN_1401973d0(pValidate, "interactionDistance", 0);
    }
    if (Unk_140165cf0* pQuest = pElem->FUN_140165cf0("quest"))
    {
        CString strQuests = FUN_14015f710(pQuest, "maskQuestID", CString(""));
        CString strStates = FUN_14015f710(pQuest, "maskQuestState", CString(""));
        FUN_140764310(strQuests, strStates, &m_maskUse);
    }
    if (Unk_140165cf0* pItem = pElem->FUN_140165cf0("item"))
    {
        FUN_140873220(pItem, "code", m_item.m_nCode);
        FUN_14015f500(pItem, "rank", &m_item.m_nRank);
        FUN_140873220(pItem, "consume", m_item.m_nConsume);
        FUN_1408731e0(pItem, "checkCount", m_item.m_nCheckCount);
        MS2Ptr<CItemData> spItem = FUN_14053f870(m_item.m_nCode);
        if (spItem)
        {
            if (spItem->FUN_14053cbc0() && m_item.m_nConsume > 1)
            {
                FUN_140177a80(GetLogString(), 1, 0x13, L"InteractObjectData : consume item error {0}", m_item.m_nCode);
                return false;
            }
        }
    }
    if (Unk_140165cf0* pCondition = pElem->FUN_140165cf0("conditionAdditionalEffect"))
    {
        CString strId;
        FUN_1408733e0(pCondition, "id", strId);
        if (!strId.IsEmpty() && strId != "0")
        {
            std::vector<unsigned> aId;
            std::vector<unsigned short> aLevel;
            XmlTokenList(pCondition, "id", aId);
            XmlTokenList(pCondition, "level", aLevel);
            if (aId.size() != aLevel.size())
            {
                FUN_140177a80(GetLogString(), 1, 0x13, L"InteractObjectData : conditionEffect id,level not pair",
                              m_item.m_nCode);
                return false;
            }
            m_aReqItem.m_aItem.reserve(aId.size());
            for (size_t i = 0; i < aId.size(); i++)
            {
                Unk_InteractReqItem item(aId[i], aLevel[i]);
                m_aReqItem.m_aItem.push_back(item);
            }
        }
    }
    if (Unk_140165cf0* pTime = pElem->FUN_140165cf0("time"))
    {
        FUN_1408732a0(pTime, "resetTime", m_nResetTime);
        FUN_1408732a0(pTime, "reactTime", m_nReactTime);
        FUN_1408732a0(pTime, "hideTime", m_nHideTime);
    }
    if (Unk_140165cf0* pUser = pElem->FUN_140165cf0("user"))
    {
        XmlTokenList(pUser, "reactAni", m_user.m_aReactAni);
        FUN_1408733e0(pUser, "successAni", m_user.m_strSuccessAni);
        FUN_1408733e0(pUser, "failAni", m_user.m_strFailAni);
    }
    if (Unk_140165cf0* pReward = pElem->FUN_140165cf0("reward"))
    {
        FUN_1408732e0(pReward, "exp", m_reward.m_nExp);
        m_reward.m_firstExp.Load(pReward, "firstExpType", "firstRelativeExpRate");
        m_reward.m_exp.Load(pReward, "expType", "relativeExpRate");
    }
    if (Unk_140165cf0* pDrop = pElem->FUN_140165cf0("drop"))
    {
        XmlTokenList(pDrop, "globalDropBoxId", m_drop.m_aGlobalDropBoxId);
        XmlTokenList(pDrop, "individualDropBoxId", m_drop.m_aIndividualDropBoxId);
        CString strLevel = FUN_14015f710(pDrop, "objectLevel", CString(""));
        if (strLevel.CompareNoCase("mapLevel") == 0)
            m_drop.m_nObjectLevel = -1;
        else
            m_drop.m_nObjectLevel = atoi(strLevel);
        FUN_1408731e0(pDrop, "objectDropRank", m_drop.m_nObjectDropRank);
        FUN_1408731e0(pDrop, "dropHeight", m_drop.m_nDropHeight);
        FUN_1408731e0(pDrop, "dropDistance", m_drop.m_nDropDistance);
    }
    if (Unk_140165cf0* pSpawn = pElem->FUN_140165cf0("spawn"))
    {
        CString strCode = FUN_14015f710(pSpawn, "code", CString(""));
        CString strCount = FUN_14015f710(pSpawn, "count", CString(""));
        CString strRadius = FUN_14015f710(pSpawn, "radius", CString(""));
        CString strProp = FUN_14015f710(pSpawn, "prop", CString(""));
        CString strLifeTime = FUN_14015f710(pSpawn, "lifeTime", CString(""));
        ATL::CAtlArray<int> aCode;
        ATL::CAtlArray<int> aCount;
        ATL::CAtlArray<int> aRadius;
        ATL::CAtlArray<int> aProp;
        ATL::CAtlArray<int> aLifeTime;
        XmlSplit(strCode, aCode, ",");
        XmlSplit(strCount, aCount, ",");
        XmlSplit(strRadius, aRadius, ",");
        XmlSplit(strProp, aProp, ",");
        XmlSplit(strLifeTime, aLifeTime, ",");
        if (aCode.GetCount() != aCount.GetCount())
            return false;
        if (aCount.GetCount() != aRadius.GetCount())
            return false;
        if (aRadius.GetCount() != aProp.GetCount())
            return false;
        if (aProp.GetCount() != aLifeTime.GetCount())
            return false;
        for (size_t i = 0; i < aCount.GetCount(); i++)
        {
            Spawn spawn;
            spawn.m_nCode = aCode[i];
            spawn.m_nCount = aCount[i];
            spawn.m_nProp = aProp[i];
            spawn.m_nRadius = aRadius[i];
            spawn.m_nLifeTime = aLifeTime[i];
            m_aSpawn.Add(spawn);
        }
    }
    if (Unk_140165cf0* pSkill = pElem->FUN_140165cf0("skill"))
    {
        FUN_140873220(pSkill, "code", m_skill.m_nCode);
        FUN_1408731a0(pSkill, "level", m_skill.m_nLevel);
        FUN_1408731e0(pSkill, "friendly", m_skill.m_nFriendly);
        FUN_1408731e0(pSkill, "count", m_skill.m_nCount);
        FUN_1408732a0(pSkill, "interval", m_skill.m_nInterval);
        FUN_140873220(pSkill, "prop", m_skill.m_nProp);
    }
    if (Unk_140165cf0* pAdditional = pElem->FUN_140165cf0("additionalEffect"))
    {
        if (Unk_140165cf0* pModify = pAdditional->FUN_140165cf0("modify"))
        {
            FUN_140873220(pModify, "code", m_modify.m_nCode);
            FUN_1408731e0(pModify, "modifyTime", m_modify.m_nModifyTime);
        }
        if (Unk_140165cf0* pInvoke = pAdditional->FUN_140165cf0("invoke"))
        {
            CString strCode;
            CString strLevel;
            CString strProp;
            ATL::CAtlArray<int> aCode;
            ATL::CAtlArray<int> aLevel;
            ATL::CAtlArray<int> aProp;
            FUN_1408733e0(pInvoke, "code", strCode);
            FUN_1408733e0(pInvoke, "level", strLevel);
            FUN_1408733e0(pInvoke, "prop", strProp);
            XmlSplit(strCode, aCode, "[], ");
            XmlSplit(strLevel, aLevel, "[], ");
            XmlSplit(strProp, aProp, "[], ");
            bool bPaired = aCode.GetCount() == aLevel.GetCount() && aCode.GetCount() == aProp.GetCount();
            if (!bPaired)
            {
                Unk_InteractLog(GetLogString(), 1, 0x13,
                                L"xml 형식이 잘못 되었습니다[<ms2> {0}] invokeBuff data error. interactID: {1}",
                                "InteractObject.xml", m_nId);
                return false;
            }
            int nCount = (int)aCode.GetCount();
            for (int i = 0; i < nCount; i++)
            {
                if (aCode[i] > 0)
                {
                    AdditionalEffect effect;
                    effect.m_nCode = aCode[i];
                    effect.m_nLevel = (unsigned short)aLevel[i];
                    effect.m_nProp = aProp[i];
                    m_aInvoke.Add(effect);
                }
            }
        }
    }
    if (Unk_140165cf0* pEffect = pElem->FUN_140165cf0("effect"))
    {
        m_effect.m_strNormal = FUN_14015f710(pEffect, "normal", CString(""));
        m_effect.m_strReactable = FUN_14015f710(pEffect, "reactable", CString(""));
        m_effect.m_strSuccess = FUN_14015f710(pEffect, "success", CString(""));
        m_effect.m_strInteraction = FUN_14015f710(pEffect, "interaction", CString(""));
        if (Unk_140165cf0* pMask = pEffect->FUN_140165cf0("maskNormal"))
        {
            CString strQuests = FUN_14015f710(pMask, "maskQuestID", CString(""));
            CString strStates = FUN_14015f710(pMask, "maskQuestState", CString(""));
            FUN_140764310(strQuests, strStates, &m_effect.m_maskNormal);
        }
        if (Unk_140165cf0* pMask = pEffect->FUN_140165cf0("maskReactable"))
        {
            CString strQuests = FUN_14015f710(pMask, "maskQuestID", CString(""));
            CString strStates = FUN_14015f710(pMask, "maskQuestState", CString(""));
            FUN_140764310(strQuests, strStates, &m_effect.m_maskReactable);
        }
        if (Unk_140165cf0* pMask = pEffect->FUN_140165cf0("maskInteraction"))
        {
            CString strQuests = FUN_14015f710(pMask, "maskQuestID", CString(""));
            CString strStates = FUN_14015f710(pMask, "maskQuestState", CString(""));
            FUN_140764310(strQuests, strStates, &m_effect.m_maskInteraction);
        }
    }
    if (Unk_140165cf0* pRoom = pElem->FUN_140165cf0("room"))
    {
        FUN_1408731e0(pRoom, "privateRoomID", m_room.m_nPrivateRoomId);
        FUN_1408732a0(pRoom, "portalLifeTime", m_room.m_nPortalLifeTime);
        FUN_1408731e0(pRoom, "partyPortal", m_room.m_nPartyPortal);
        FUN_140873220(pRoom, "bossNpcID", m_room.m_nBossNpcId);
        FUN_1408731e0(pRoom, "hideBossName", m_room.m_nHideBossName);
    }
    if (Unk_140165cf0* pHome = pElem->FUN_140165cf0("homePrivilege"))
        FUN_1408731e0(pHome, "check", m_homePrivilege.m_nCheck);
    if (Unk_140165cf0* pWeb = pElem->FUN_140165cf0("webOpen"))
    {
        FUN_1408731e0(pWeb, "type", m_webOpen.m_nType);
        m_webOpen.m_strUrl = FUN_14015f710(pWeb, "url", CString(""));
    }
    if (Unk_140165cf0* pUrl = pElem->FUN_140165cf0("displayURL"))
    {
        m_displayUrl.m_strIndirectUrl = FUN_14015f710(pUrl, "indirectURL", CString(""));
        m_displayUrl.m_nType = FUN_140197350(pUrl, "type", 0);
    }
    if (Unk_140165cf0* pDisplay = pElem->FUN_140165cf0("display"))
    {
        m_display.m_strMinimapIcon = FUN_14015f710(pDisplay, "minimapIcon", CString(""));
        m_display.m_nNotice = FUN_140197350(pDisplay, "notice", 0);
    }
    if (Unk_140165cf0* pArena = pElem->FUN_140165cf0("arena"))
        m_arena.m_nCanInteractTeamId = FUN_140197350(pArena, "canInteractTeamId", 0);
    if (Unk_140165cf0* pPortal = pElem->FUN_140165cf0("portal"))
        m_portal.m_nTargetPortalId = FUN_140197350(pPortal, "targetPortalId", 0);
    if (Unk_140165cf0* pGuild = pElem->FUN_140165cf0("guild"))
        m_guild.m_nHousePosterId = FUN_140197350(pGuild, "housePosterId", 0);
    if (Unk_140165cf0* pWeapon = pElem->FUN_140165cf0("weapon"))
        m_weapon.m_nWeaponItemId = FUN_140197390(pWeapon, "weaponItemId", 0);
    if (Unk_140165cf0* pMastery = pElem->FUN_140165cf0("mastery"))
    {
        XmlValue(pMastery, "type", m_mastery.m_eType);
        FUN_1408731e0(pMastery, "value", m_mastery.m_nValue);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14051CE70, CInteractObjectData, Load, 9198, 0xA6BDC3CC);

// @0x14051f270
int CInteractObjectData::FUN_14051f270()
{
    return reinterpret_cast<Unk_QuestMaskView*>(&m_maskUse)->m_aMask.GetCount() > 0 ? TRUE : FALSE;
}
MS2_REPLACE_METHOD(0x14051F270, CInteractObjectData, FUN_14051f270, 58, 0xC01AAFE8);

// LoadAll and Get construct rows (DLL-local vftables in the hook DLL): not hooked.
// @0x14051f2b0
void CInteractObjectData::LoadAll()
{
    ATL::CAtlArray<CString> aFile;
    aFile.Add("InteractObject.xml");
    aFile.Add("InteractObject_mastery.xml");
    for (size_t i = 0; i < aFile.GetCount(); i++)
    {
        TiXmlDocument doc;
        CString strPath = FUN_14071a5b0("Table", aFile[i]);
        if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
            return;
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            Unk_InteractLog(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", "InteractObject.xml");
            return;
        }
        for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("interact"); pNode != 0;
             pNode = pNode->FUN_140168650("interact"))
        {
            if (!FUN_14028f710(pNode))
                continue;
            MS2Ptr<CInteractObjectData> spData(new CInteractObjectData);
            spData->FUN_1401d1160(CString(strPath));
            if (!spData->Load(pNode))
                continue;
            if (Unk_LockGuard guard = s_lock)
            {
            }
            else
                s_table.SetAt(spData->m_nId, spData);
        }
    }
    SetInit(true);
}

// @0x14051f670
MS2Ptr<CInteractObjectData> CInteractObjectData::Get(int nId)
{
    CheckInit();
    MS2Ptr<CInteractObjectData> spData(0);
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        if (!GetFileSystem()->FUN_140398190() && s_table.Lookup(nId, spData))
        {
            if (FUN_1401d1320(spData.operator->()))
            {
                s_table.RemoveAll();
                LoadAll();
                s_table.Lookup(nId, spData);
            }
            return spData;
        }
        if (s_table.Lookup(nId, spData))
            return spData;
    }
    return MS2Ptr<CInteractObjectData>(0);
}

// @0x14051f800
void CInteractObjectData::GetAll(ATL::CAtlArray<MS2Ptr<CInteractObjectData> >& aOut)
{
    CheckInit();
    if (Unk_LockGuard guard = s_lock)
    {
    }
    else
    {
        for (POSITION pos = s_table.GetStartPosition(); pos != 0; s_table.GetNext(pos))
        {
            aOut.Add(s_table.GetValueAt(pos));
        }
    }
}
MS2_REPLACE(0x14051F800, CInteractObjectData::GetAll, 148, 0x99417458);

// @0x140521650
inline void CInteractObjectData::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CInteractObjectData).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140522ce0
inline void CInteractObjectData::SetInit(bool bInit)
{
    s_bInit = bInit;
}

// MS2-PIN: ??_7CInteractObjectData@@6B?$CValidData@VCInteractObjectData@@@@@ 0x142d568b0
