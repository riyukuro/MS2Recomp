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
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, unsigned long&);   // C3: was FUN_1408732a0
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0

// ---- helpers of other units ----
int Unk_ReadRank(class Unk_XmlNode*, char const*, int*);   // C3: was FUN_14015f500
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);
unsigned int FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned int nDefault);
float FUN_1401973d0(Unk_140165cf0* pElem, const char* pszName, float fDefault);
bool FUN_14028f710(struct Unk_XmlElement*);   // C3: was FUN_14028f710
void FUN_14028c2d0(CString strText, Unk_PDVec3* pOut);                  // "x,y,z" -> point
int FUN_140764310(const CStringA& strQuests, const CStringA& strStates, QuestMask* pMask);   // questmasktable.cpp
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);  // data file path
CString FUN_14016a5c0(const char* psz, int n);
CLogString* GetLogString();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // the item data of an id
// The one-argument log of additionalactionadditional.cpp (an FMT_VARIADIC instance it emitted first).
template <class T> void Unk_AdditionalLog(class CLogString*, int, int, const wchar_t*, const T&);

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
    XmlGetAttr((class TiXmlElement*)(pElem), pszRate, reinterpret_cast<float&>(m_fRate));
    CString strType = Unk_ReadString((class Unk_XmlNode*)(pElem), pszType, CString(""));
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
    XmlGetAttr((class TiXmlElement*)(pElem), "id", reinterpret_cast<unsigned int&>(m_nId));
    XmlValue(pElem, "type", m_eType);
    XmlGetAttr((class TiXmlElement*)(pElem), "collection", reinterpret_cast<int&>(m_nCollection));
    XmlGetAttr((class TiXmlElement*)(pElem), "reactCount", reinterpret_cast<unsigned int&>(m_nReactCount));
    if (m_eType == Unk_InteractObjectType_None)
        return false;

    if (Unk_140165cf0* pMesh = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("mesh")))
    {
        XmlGetAttr((class TiXmlElement*)(pMesh), "normalCollision", reinterpret_cast<int&>(m_mesh.m_nNormalCollision));
        XmlGetAttr((class TiXmlElement*)(pMesh), "reactableCollision", reinterpret_cast<int&>(m_mesh.m_nReactableCollision));
        XmlGetAttr((class TiXmlElement*)(pMesh), "reactObjectAni", m_mesh.m_strReactObjectAni);
        CString strShape = Unk_ReadString((class Unk_XmlNode*)(pMesh), "shapeDimension", CString(""));
        FUN_14028c2d0(strShape, &m_mesh.m_shapeDimension);
    }
    if (Unk_140165cf0* pUi = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("ui")))
    {
        m_ui.m_strSwf = Unk_ReadString((class Unk_XmlNode*)(pUi), "swf", CString(""));
        m_ui.m_strValue = Unk_ReadString((class Unk_XmlNode*)(pUi), "value", CString(""));
    }
    if (Unk_140165cf0* pGathering = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("gathering")))
        XmlGetAttr((class TiXmlElement*)(pGathering), "receipeID", reinterpret_cast<int&>(m_gathering.m_nReceipeId));
    if (Unk_140165cf0* pValidate = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("validate")))
    {
        m_validate.m_nFieldId = FUN_140197350(pValidate, "fieldID", 0);
        m_validate.m_fInteractionDistance = FUN_1401973d0(pValidate, "interactionDistance", 0);
    }
    if (Unk_140165cf0* pQuest = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("quest")))
    {
        CString strQuests = Unk_ReadString((class Unk_XmlNode*)(pQuest), "maskQuestID", CString(""));
        CString strStates = Unk_ReadString((class Unk_XmlNode*)(pQuest), "maskQuestState", CString(""));
        FUN_140764310(strQuests, strStates, &m_maskUse);
    }
    if (Unk_140165cf0* pItem = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("item")))
    {
        XmlGetAttr((class TiXmlElement*)(pItem), "code", reinterpret_cast<unsigned int&>(m_item.m_nCode));
        Unk_ReadRank((class Unk_XmlNode*)(pItem), "rank", &m_item.m_nRank);
        XmlGetAttr((class TiXmlElement*)(pItem), "consume", reinterpret_cast<unsigned int&>(m_item.m_nConsume));
        XmlGetAttr((class TiXmlElement*)(pItem), "checkCount", reinterpret_cast<int&>(m_item.m_nCheckCount));
        MS2Ptr<CItemData> spItem = FUN_14053f870(m_item.m_nCode);
        if (spItem)
        {
            if (spItem->FUN_14053cbc0() && m_item.m_nConsume > 1)
            {
                Unk_AdditionalLog<unsigned>(GetLogString(), 1, 0x13, L"InteractObjectData : consume item error {0}", m_item.m_nCode);
                return false;
            }
        }
    }
    if (Unk_140165cf0* pCondition = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("conditionAdditionalEffect")))
    {
        CString strId;
        XmlGetAttr((class TiXmlElement*)(pCondition), "id", strId);
        if (!strId.IsEmpty() && strId != "0")
        {
            std::vector<unsigned> aId;
            std::vector<unsigned short> aLevel;
            XmlTokenList(pCondition, "id", aId);
            XmlTokenList(pCondition, "level", aLevel);
            if (aId.size() != aLevel.size())
            {
                Unk_AdditionalLog<unsigned>(GetLogString(), 1, 0x13, L"InteractObjectData : conditionEffect id,level not pair",
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
    if (Unk_140165cf0* pTime = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("time")))
    {
        XmlGetAttr((class TiXmlElement*)(pTime), "resetTime", reinterpret_cast<unsigned long&>(m_nResetTime));
        XmlGetAttr((class TiXmlElement*)(pTime), "reactTime", reinterpret_cast<unsigned long&>(m_nReactTime));
        XmlGetAttr((class TiXmlElement*)(pTime), "hideTime", reinterpret_cast<unsigned long&>(m_nHideTime));
    }
    if (Unk_140165cf0* pUser = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("user")))
    {
        XmlTokenList(pUser, "reactAni", m_user.m_aReactAni);
        XmlGetAttr((class TiXmlElement*)(pUser), "successAni", m_user.m_strSuccessAni);
        XmlGetAttr((class TiXmlElement*)(pUser), "failAni", m_user.m_strFailAni);
    }
    if (Unk_140165cf0* pReward = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("reward")))
    {
        XmlGetAttr((class TiXmlElement*)(pReward), "exp", reinterpret_cast<__int64&>(m_reward.m_nExp));
        m_reward.m_firstExp.Load(pReward, "firstExpType", "firstRelativeExpRate");
        m_reward.m_exp.Load(pReward, "expType", "relativeExpRate");
    }
    if (Unk_140165cf0* pDrop = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("drop")))
    {
        XmlTokenList(pDrop, "globalDropBoxId", m_drop.m_aGlobalDropBoxId);
        XmlTokenList(pDrop, "individualDropBoxId", m_drop.m_aIndividualDropBoxId);
        CString strLevel = Unk_ReadString((class Unk_XmlNode*)(pDrop), "objectLevel", CString(""));
        if (strLevel.CompareNoCase("mapLevel") == 0)
            m_drop.m_nObjectLevel = -1;
        else
            m_drop.m_nObjectLevel = atoi(strLevel);
        XmlGetAttr((class TiXmlElement*)(pDrop), "objectDropRank", reinterpret_cast<int&>(m_drop.m_nObjectDropRank));
        XmlGetAttr((class TiXmlElement*)(pDrop), "dropHeight", reinterpret_cast<int&>(m_drop.m_nDropHeight));
        XmlGetAttr((class TiXmlElement*)(pDrop), "dropDistance", reinterpret_cast<int&>(m_drop.m_nDropDistance));
    }
    if (Unk_140165cf0* pSpawn = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("spawn")))
    {
        CString strCode = Unk_ReadString((class Unk_XmlNode*)(pSpawn), "code", CString(""));
        CString strCount = Unk_ReadString((class Unk_XmlNode*)(pSpawn), "count", CString(""));
        CString strRadius = Unk_ReadString((class Unk_XmlNode*)(pSpawn), "radius", CString(""));
        CString strProp = Unk_ReadString((class Unk_XmlNode*)(pSpawn), "prop", CString(""));
        CString strLifeTime = Unk_ReadString((class Unk_XmlNode*)(pSpawn), "lifeTime", CString(""));
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
    if (Unk_140165cf0* pSkill = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("skill")))
    {
        XmlGetAttr((class TiXmlElement*)(pSkill), "code", reinterpret_cast<unsigned int&>(m_skill.m_nCode));
        XmlGetAttr((class TiXmlElement*)(pSkill), "level", reinterpret_cast<unsigned short&>(m_skill.m_nLevel));
        XmlGetAttr((class TiXmlElement*)(pSkill), "friendly", reinterpret_cast<int&>(m_skill.m_nFriendly));
        XmlGetAttr((class TiXmlElement*)(pSkill), "count", reinterpret_cast<int&>(m_skill.m_nCount));
        XmlGetAttr((class TiXmlElement*)(pSkill), "interval", reinterpret_cast<unsigned long&>(m_skill.m_nInterval));
        XmlGetAttr((class TiXmlElement*)(pSkill), "prop", reinterpret_cast<unsigned int&>(m_skill.m_nProp));
    }
    if (Unk_140165cf0* pAdditional = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("additionalEffect")))
    {
        if (Unk_140165cf0* pModify = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pAdditional))->FirstChild("modify")))
        {
            XmlGetAttr((class TiXmlElement*)(pModify), "code", reinterpret_cast<unsigned int&>(m_modify.m_nCode));
            XmlGetAttr((class TiXmlElement*)(pModify), "modifyTime", reinterpret_cast<int&>(m_modify.m_nModifyTime));
        }
        if (Unk_140165cf0* pInvoke = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pAdditional))->FirstChild("invoke")))
        {
            CString strCode;
            CString strLevel;
            CString strProp;
            ATL::CAtlArray<int> aCode;
            ATL::CAtlArray<int> aLevel;
            ATL::CAtlArray<int> aProp;
            XmlGetAttr((class TiXmlElement*)(pInvoke), "code", strCode);
            XmlGetAttr((class TiXmlElement*)(pInvoke), "level", strLevel);
            XmlGetAttr((class TiXmlElement*)(pInvoke), "prop", strProp);
            XmlSplit(strCode, aCode, "[], ");
            XmlSplit(strLevel, aLevel, "[], ");
            XmlSplit(strProp, aProp, "[], ");
            bool bPaired = aCode.GetCount() == aLevel.GetCount() && aCode.GetCount() == aProp.GetCount() ? true : false;
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
                if (aCode[i] <= 0)
                    continue;
                AdditionalEffect effect;
                effect.m_nCode = aCode[i];
                effect.m_nLevel = (unsigned short)aLevel[i];
                effect.m_nProp = aProp[i];
                m_aInvoke.Add(effect);
            }
        }
    }
    if (Unk_140165cf0* pEffect = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("effect")))
    {
        m_effect.m_strNormal = Unk_ReadString((class Unk_XmlNode*)(pEffect), "normal", CString(""));
        m_effect.m_strReactable = Unk_ReadString((class Unk_XmlNode*)(pEffect), "reactable", CString(""));
        m_effect.m_strSuccess = Unk_ReadString((class Unk_XmlNode*)(pEffect), "success", CString(""));
        m_effect.m_strInteraction = Unk_ReadString((class Unk_XmlNode*)(pEffect), "interaction", CString(""));
        if (Unk_140165cf0* pMask = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pEffect))->FirstChild("maskNormal")))
        {
            CString strQuests = Unk_ReadString((class Unk_XmlNode*)(pMask), "maskQuestID", CString(""));
            CString strStates = Unk_ReadString((class Unk_XmlNode*)(pMask), "maskQuestState", CString(""));
            FUN_140764310(strQuests, strStates, &m_effect.m_maskNormal);
        }
        if (Unk_140165cf0* pMask = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pEffect))->FirstChild("maskReactable")))
        {
            CString strQuests = Unk_ReadString((class Unk_XmlNode*)(pMask), "maskQuestID", CString(""));
            CString strStates = Unk_ReadString((class Unk_XmlNode*)(pMask), "maskQuestState", CString(""));
            FUN_140764310(strQuests, strStates, &m_effect.m_maskReactable);
        }
        if (Unk_140165cf0* pMask = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pEffect))->FirstChild("maskInteraction")))
        {
            CString strQuests = Unk_ReadString((class Unk_XmlNode*)(pMask), "maskQuestID", CString(""));
            CString strStates = Unk_ReadString((class Unk_XmlNode*)(pMask), "maskQuestState", CString(""));
            FUN_140764310(strQuests, strStates, &m_effect.m_maskInteraction);
        }
    }
    if (Unk_140165cf0* pRoom = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("room")))
    {
        XmlGetAttr((class TiXmlElement*)(pRoom), "privateRoomID", reinterpret_cast<int&>(m_room.m_nPrivateRoomId));
        XmlGetAttr((class TiXmlElement*)(pRoom), "portalLifeTime", reinterpret_cast<unsigned long&>(m_room.m_nPortalLifeTime));
        XmlGetAttr((class TiXmlElement*)(pRoom), "partyPortal", reinterpret_cast<int&>(m_room.m_nPartyPortal));
        XmlGetAttr((class TiXmlElement*)(pRoom), "bossNpcID", reinterpret_cast<unsigned int&>(m_room.m_nBossNpcId));
        XmlGetAttr((class TiXmlElement*)(pRoom), "hideBossName", reinterpret_cast<int&>(m_room.m_nHideBossName));
    }
    if (Unk_140165cf0* pHome = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("homePrivilege")))
        XmlGetAttr((class TiXmlElement*)(pHome), "check", reinterpret_cast<int&>(m_homePrivilege.m_nCheck));
    if (Unk_140165cf0* pWeb = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("webOpen")))
    {
        XmlGetAttr((class TiXmlElement*)(pWeb), "type", reinterpret_cast<int&>(m_webOpen.m_nType));
        m_webOpen.m_strUrl = Unk_ReadString((class Unk_XmlNode*)(pWeb), "url", CString(""));
    }
    if (Unk_140165cf0* pUrl = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("displayURL")))
    {
        m_displayUrl.m_strIndirectUrl = Unk_ReadString((class Unk_XmlNode*)(pUrl), "indirectURL", CString(""));
        m_displayUrl.m_nType = FUN_140197350(pUrl, "type", 0);
    }
    if (Unk_140165cf0* pDisplay = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("display")))
    {
        m_display.m_strMinimapIcon = Unk_ReadString((class Unk_XmlNode*)(pDisplay), "minimapIcon", CString(""));
        m_display.m_nNotice = FUN_140197350(pDisplay, "notice", 0);
    }
    if (Unk_140165cf0* pArena = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("arena")))
        m_arena.m_nCanInteractTeamId = FUN_140197350(pArena, "canInteractTeamId", 0);
    if (Unk_140165cf0* pPortal = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("portal")))
        m_portal.m_nTargetPortalId = FUN_140197350(pPortal, "targetPortalId", 0);
    if (Unk_140165cf0* pGuild = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("guild")))
        m_guild.m_nHousePosterId = FUN_140197350(pGuild, "housePosterId", 0);
    if (Unk_140165cf0* pWeapon = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("weapon")))
        m_weapon.m_nWeaponItemId = FUN_140197390(pWeapon, "weaponItemId", 0);
    if (Unk_140165cf0* pMastery = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("mastery")))
    {
        XmlValue(pMastery, "type", m_mastery.m_eType);
        XmlGetAttr((class TiXmlElement*)(pMastery), "value", reinterpret_cast<int&>(m_mastery.m_nValue));
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
        for (Unk_140165cf0* pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("interact")); pNode != 0;
             pNode = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->NextSibling("interact")))
        {
            if (!FUN_14028f710((struct Unk_XmlElement*)(pNode)))
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
