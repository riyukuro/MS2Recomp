// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CObjectData: one interactive object row (Data/Xml/Object/
// %08d.xml: <FunctionCube> control type / ui / camera / spawner / fusioner / fitting doll / skill object / first-person
// animation / nurturing / pvp / openWeb / noticePopup and <ConfigurableCube>), the cache of loaded rows and the per-id
// queries over it. Names are invented from use.
// MS2-UNIT: ?\objectdata.cpp
// MS2-RANGE: 0x140704bd0-0x14070c3f0 .text$mn
// MS2-RANGE: 0x1400bbde0-0x1400bbe60 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetNode@?$CAtlMap@IV?$MS2SvrPtr@VCObjectData@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCObjectData@@@@@3@@ATL@@AEBAPEAVCNode@12@IAEAI0AEAPEAV312@@Z 0x140709be0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\objectdata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/objectdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
class Unk_140165cf0;
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420

// ---- unrecovered helpers ----

class CLogString* GetLogString();
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
CString FUN_140188f50(const char* psz, int n);
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
int FUN_140873420(Unk_140165cf0*, const char*, CStringW&);
void FUN_140177de0(const CString& str, ATL::CAtlArray<int>& rOut, const wchar_t* pszSep);          // split into numbers
void FUN_140177e10(const CString& str, ATL::CAtlArray<unsigned>& rOut, const wchar_t* pszSep);
void FUN_140177e40(const CString& str, ATL::CAtlArray<float>& rOut, const wchar_t* pszSep);
int FUN_140178670(Unk_140165cf0*, const char*, ATL::CAtlArray<unsigned>&);                      // list attribute
unsigned FUN_14028c0d0(const char* psz);                                // a colour value of a "#rrggbb" style string
void FUN_140194470(efd::Point3* pDst, const efd::Point3& kSrc);         // efd::Point3 assignment
unsigned char FUN_1401d1320(CCacheData* p);                             // file changed since load
class Unk_140165cf0;
extern int DAT_1439ed00c;                                               // row cache enabled

typedef ATL::CAtlMap<unsigned, CObjectDataPtr> CObjectDataMap;

static CObjectDataMap s_cache;                                          // 0x143ab0a50
static CLockCriticalSection s_lock;                                     // 0x143ab0a20

// @0x140704bd0
void CObjectData::Nurturing::operator=(const Nurturing& o)
{
    m_rewardByFeeding.m_nItemId = o.m_rewardByFeeding.m_nItemId;
    m_rewardByFeeding.m_nRarity = o.m_rewardByFeeding.m_nRarity;
    m_rewardByFeeding.m_nCount = o.m_rewardByFeeding.m_nCount;
    m_reward.m_nItemId = o.m_reward.m_nItemId;
    m_reward.m_nRarity = o.m_reward.m_nRarity;
    m_reward.m_nCount = o.m_reward.m_nCount;
    for (POSITION pos = o.m_requiredGrowth.GetStartPosition(); pos != 0; o.m_requiredGrowth.GetNext(pos))
        m_requiredGrowth.SetAt(o.m_requiredGrowth.GetKeyAt(pos), o.m_requiredGrowth.GetValueAt(pos));
    for (POSITION pos = o.m_pluralNpcIds.GetStartPosition(); pos != 0; o.m_pluralNpcIds.GetNext(pos))
        m_pluralNpcIds.SetAt(o.m_pluralNpcIds.GetKeyAt(pos), o.m_pluralNpcIds.GetValueAt(pos));
    for (POSITION pos = o.m_rewardByGrowth.GetStartPosition(); pos != 0; o.m_rewardByGrowth.GetNext(pos))
        m_rewardByGrowth.SetAt(o.m_rewardByGrowth.GetKeyAt(pos), o.m_rewardByGrowth.GetValueAt(pos));
    m_strQuestTag = o.m_strQuestTag;
}

// @0x140704df0
CObjectData::CObjectData()
{
    m_config.m_bEnabled = 0;
}

// @0x140704e60
CObjectData::~CObjectData()
{
}

// @0x140704ec0
CObjectDataPtr FUN_140704ec0(unsigned nId)
{
    CObjectDataPtr spData(0);
    if (Unk_LockGuard guard = s_lock) {} else
    {
        if (DAT_1439ed00c != 0 && s_cache.Lookup(nId, spData) && !FUN_1401d1320(spData.get()))
            return spData;
    }
    spData = new CObjectData;
    spData->m_nId = nId;
    CString strFile;
    strFile.Format("%08d.xml", nId);
    CString strPath = FUN_14071a5b0("Object", strFile);
    TiXmlDocument doc;
    spData->FUN_1401d1160(strPath);
    if (GetFileSystem()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return CObjectDataPtr(0);
    Unk_140165cf0* pRoot = ((class Unk_140165cf0*)((class Unk_XmlNode*)(&doc))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_AchieveLog<CString>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return CObjectDataPtr(0);
    }
    Unk_140165cf0* pFunc = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("FunctionCube"));
    if (pFunc != 0)
    {
        spData->m_cube.m_bEnabled = 1;
        XmlGetAttr((class TiXmlElement*)(pFunc), "UseKfm", spData->m_cube.m_bUseKfm);
        XmlGetAttr((class TiXmlElement*)(pFunc), "DefaultState", spData->m_cube.m_nDefaultState);
        CString strType = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("ControlType"), 0);
        spData->m_cube.m_strControlType = strType;
        if ((strType == "Sensor"))
            spData->m_cube.m_nControlType = 2;
        else if ((strType == "Switch") || (strType == "FunctionUI") || (strType == "Ride") || (strType == "OpenWeb"))
            spData->m_cube.m_nControlType = 3;
        else if ((strType == "SpawnNPC"))
            spData->m_cube.m_nControlType = 4;
        else if ((strType == "InstallNPC"))
            spData->m_cube.m_nControlType = 0xb;
        else if ((strType == "Skill"))
            spData->m_cube.m_nControlType = 5;
        else if ((strType == "Portal"))
            spData->m_cube.m_nControlType = 6;
        else if ((strType == "Breeding"))
            spData->m_cube.m_nControlType = 7;
        else if ((strType == "Farming"))
            spData->m_cube.m_nControlType = 8;
        else if ((strType == "PVP"))
            spData->m_cube.m_nControlType = 9;
        else if ((strType == "SpawnPoint"))
            spData->m_cube.m_nControlType = 10;
        else if ((strType == "Notice"))
            spData->m_cube.m_nControlType = 0xc;
        else if ((strType == "Nurturing"))
            spData->m_cube.m_nControlType = 0xd;
        else
            spData->m_cube.m_nControlType = 1;
        CString strAction = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("StateChangeAction"), 0);
        if ((strAction == "ActionKey"))
            spData->m_cube.m_nStateChangeAction = 1;
        else if ((strAction == "Attack"))
            spData->m_cube.m_nStateChangeAction = 2;
        int nPermission = 0;
        XmlGetAttr((class TiXmlElement*)(pFunc), "StateChangeActionPermissionType", nPermission);
        spData->m_cube.m_nStateChangePermission = nPermission;
        CString strUi = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("UseUiFunction"), 0);
        if ((strType == "FunctionUI"))
        {
            if ((strUi == "TriggerTool"))
                spData->m_cube.m_nUiFunction = 1;
            else if ((strUi == "FittingDoll"))
                spData->m_cube.m_nUiFunction = 2;
            else if ((strUi == "itemFusion"))
                spData->m_cube.m_nUiFunction = 3;
            else if ((strUi == "bank"))
                spData->m_cube.m_nUiFunction = 4;
            else if ((strUi == "BeautyMirror"))
                spData->m_cube.m_nUiFunction = 5;
            else if ((strUi == "Password"))
                spData->m_cube.m_nUiFunction = 6;
            else if ((strUi == "Summon"))
                spData->m_cube.m_nUiFunction = 7;
        }
        spData->m_cube.m_sequences.SetCount(6, -1);
        spData->m_cube.m_sequences[0] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("ZeroSeq");
        spData->m_cube.m_sequences[3] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("ZeroIngSeq");
        spData->m_cube.m_sequences[1] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("FirstSeq");
        spData->m_cube.m_sequences[4] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("FirstIngSeq");
        spData->m_cube.m_sequences[2] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("SecondSeq");
        spData->m_cube.m_sequences[5] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("SecondIngSeq");
        spData->m_cube.m_effects.SetCount(6, -1);
        spData->m_cube.m_effects[0] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("ZeroEffect");
        spData->m_cube.m_effects[3] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("ZeroIngEffect");
        spData->m_cube.m_effects[1] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("FirstEffect");
        spData->m_cube.m_effects[4] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("FirstIngEffect");
        spData->m_cube.m_effects[2] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("SecondEffect");
        spData->m_cube.m_effects[5] = ((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("SecondIngEffect");
        XmlGetAttr((class TiXmlElement*)(pFunc), "ZeroPhysics", spData->m_cube.m_anPhysics[0]);
        XmlGetAttr((class TiXmlElement*)(pFunc), "FirstPhysics", spData->m_cube.m_anPhysics[1]);
        XmlGetAttr((class TiXmlElement*)(pFunc), "SecondPhysics", spData->m_cube.m_anPhysics[2]);
        ATL::CAtlArray<int> autoStates;
        CString strAuto = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFunc))->Attribute("AutoStateChange"), 0);
        FUN_140177de0(strAuto, autoStates, L"-");
        if (autoStates.GetCount() == 2)
        {
            spData->m_cube.m_autoState.m_nStateA = autoStates[0];
            spData->m_cube.m_autoState.m_nStateB = autoStates[1];
        }
        XmlGetAttr((class TiXmlElement*)(pFunc), "AutoStateChangeTime", spData->m_cube.m_autoState.m_nTime);
        XmlGetAttr((class TiXmlElement*)(pFunc), "enableTriggerControl", spData->m_cube.m_bEnableTriggerControl);
        XmlGetAttr((class TiXmlElement*)(pFunc), "receipeID", spData->m_cube.m_reactable.m_nRecipeId);
        XmlGetAttr((class TiXmlElement*)(pFunc), "reactableEffect", spData->m_cube.m_reactable.m_strEffect);
        Unk_140165cf0* pCamera = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("camera"));
        if (pCamera != 0)
        {
            CString strCamera = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pCamera))->Attribute("SetCamera"), 0);
            if ((strCamera == "TPSCamera"))
                spData->m_cube.m_nCamera = 1;
            else if ((strCamera == "FPSCamera"))
                spData->m_cube.m_nCamera = 2;
            else if ((strCamera == "2DCamera"))
                spData->m_cube.m_nCamera = 3;
            else if ((strCamera == "RPGCamera"))
                spData->m_cube.m_nCamera = 4;
            else if ((strCamera == "PVPCamera"))
                spData->m_cube.m_nCamera = 5;
            else if ((strCamera == "ConsoleCamera"))
                spData->m_cube.m_nCamera = 6;
        }
        Unk_140165cf0* pSpawner = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("spawner"));
        if (pSpawner != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pSpawner), "radius", spData->m_cube.m_spawner.m_fRadius);
            XmlGetAttr((class TiXmlElement*)(pSpawner), "npcCount", spData->m_cube.m_spawner.m_nNpcCount);
            XmlGetAttr((class TiXmlElement*)(pSpawner), "npcID", *(unsigned int*)&static_cast<int&>(spData->m_cube.m_spawner.m_nNpcId));
            XmlGetAttr((class TiXmlElement*)(pSpawner), "regenCheckTime", spData->m_cube.m_spawner.m_fRegenCheckTime);
        }
        Unk_140165cf0* pFusioner = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("fusioner"));
        if (pFusioner != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pFusioner), "temperature", spData->m_cube.m_fusioner.m_nTemperature);
            XmlGetAttr((class TiXmlElement*)(pFusioner), "sacrifice", spData->m_cube.m_fusioner.m_nSacrifice);
        }
        Unk_140165cf0* pDoll = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("fittingdoll"));
        if (pDoll != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pDoll), "fittingdollGender", spData->m_cube.m_fittingDoll.m_nGender);
            XmlGetAttr((class TiXmlElement*)(pDoll), "fittingdollType", spData->m_cube.m_fittingDoll.m_nType);
            CString strAsset;
            XmlGetAttr((class TiXmlElement*)(pDoll), "fittingdollAsset", strAsset);
            if (strAsset.GetLength() != 0)
                spData->m_cube.m_fittingDoll.m_strAsset = strAsset;
            else
            {
                if (spData->m_cube.m_fittingDoll.m_nGender == 1)
                    spData->m_cube.m_fittingDoll.m_strAsset = "FittingDoll_F_Default01";
                else
                    spData->m_cube.m_fittingDoll.m_strAsset = "FittingDoll_M_Default01";
            }
            CString strItems = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pDoll))->Attribute("fittingdollDefaultItem"), 0);
            FUN_140177e10(strItems, spData->m_cube.m_fittingDoll.m_defaultItems, L",");
            CString strColor;
            strColor = Unk_ReadString((class Unk_XmlNode*)(pDoll), "fittingdollSkinColor0", CString(""));
            spData->m_cube.m_fittingDoll.m_anSkinColor[0] = FUN_14028c0d0(strColor);
            strColor = Unk_ReadString((class Unk_XmlNode*)(pDoll), "fittingdollSkinColor1", CString(""));
            spData->m_cube.m_fittingDoll.m_anSkinColor[1] = FUN_14028c0d0(strColor);
            strColor = Unk_ReadString((class Unk_XmlNode*)(pDoll), "fittingdollSkinColor2", CString(""));
            spData->m_cube.m_fittingDoll.m_anSkinColor[2] = FUN_14028c0d0(strColor);
        }
        Unk_140165cf0* pSkill = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("skillobject"));
        if (pSkill != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pSkill), "skillID", *(unsigned int*)&static_cast<int&>(spData->m_cube.m_skill.m_nSkillId));
            XmlGetAttr((class TiXmlElement*)(pSkill), "skillLevel", *(unsigned short*)&static_cast<short&>(spData->m_cube.m_skill.m_nSkillLevel));
            XmlGetAttr((class TiXmlElement*)(pSkill), "friendly", spData->m_cube.m_skill.m_bFriendly);
        }
        Unk_140165cf0* pFirst = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("firstPCAnimation"));
        if (pFirst != 0)
        {
            spData->m_cube.m_firstAnimation.m_strAnimation = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFirst))->Attribute("firstAnimation"), 0);
            XmlGetAttr((class TiXmlElement*)(pFirst), "firstUsePCMove", spData->m_cube.m_firstAnimation.m_nUsePcMove);
            spData->m_cube.m_firstAnimation.m_strBone = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFirst))->Attribute("firstPCBone"), 0);
            CString strTranslation = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFirst))->Attribute("firstPCTranslation"), 0);
            ATL::CAtlArray<float> translation;
            FUN_140177e40(strTranslation, translation, L",");
            if (translation.GetCount() == 3)
                FUN_140194470(&spData->m_cube.m_firstAnimation.m_vTranslation, efd::Point3(translation[0], translation[1], translation[2]));
            CString strRotation = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pFirst))->Attribute("firstPCRotation"), 0);
            ATL::CAtlArray<float> rotation;
            FUN_140177e40(strRotation, rotation, L",");
            if (rotation.GetCount() == 3)
                FUN_140194470(&spData->m_cube.m_firstAnimation.m_vRotation, efd::Point3(rotation[0], rotation[1], rotation[2]));
            XmlGetAttr((class TiXmlElement*)(pFirst), "firstEmotionID", spData->m_cube.m_firstAnimation.m_strEmotionId);
            XmlGetAttr((class TiXmlElement*)(pFirst), "firstEffectStart", spData->m_cube.m_firstAnimation.m_strEffectStart);
            XmlGetAttr((class TiXmlElement*)(pFirst), "firstEffectEnd", spData->m_cube.m_firstAnimation.m_strEffectEnd);
        }
        Unk_140165cf0* pAdditional = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("firstAdditionalEffect"));
        if (pAdditional != 0)
        {
            spData->m_cube.m_firstEffect.m_bEnabled = 1;
            XmlGetAttr((class TiXmlElement*)(pAdditional), "firstAdditionalEffectID", *(unsigned int*)&static_cast<int&>(spData->m_cube.m_firstEffect.m_nEffectId));
            XmlGetAttr((class TiXmlElement*)(pAdditional), "firstAdditionalEffectLevel", *(unsigned short*)&static_cast<short&>(spData->m_cube.m_firstEffect.m_nLevel));
            XmlGetAttr((class TiXmlElement*)(pAdditional), "firstAdditionalTarget", spData->m_cube.m_firstEffect.m_nTarget);
            XmlGetAttr((class TiXmlElement*)(pAdditional), "firstAdditionalRange", spData->m_cube.m_firstEffect.m_fRange);
            XmlGetAttr((class TiXmlElement*)(pAdditional), "firstAdditionalPopup", spData->m_cube.m_firstEffect.m_bPopup);
        }
        Unk_140165cf0* pForbidden = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("forbidden"));
        if (pForbidden != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pForbidden), "forbidJump", spData->m_cube.m_bForbidJump);
            XmlGetAttr((class TiXmlElement*)(pForbidden), "forbidClimb", spData->m_cube.m_bForbidClimb);
            XmlGetAttr((class TiXmlElement*)(pForbidden), "forbidSkill", spData->m_cube.m_bForbidSkill);
            XmlGetAttr((class TiXmlElement*)(pForbidden), "forbidPlayInstrument", spData->m_cube.m_bForbidPlayInstrument);
            XmlGetAttr((class TiXmlElement*)(pForbidden), "forbidExceptOwner", spData->m_cube.m_bForbidExceptOwner);
        }
        Unk_140165cf0* pPvp = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("pvp"));
        if (pPvp != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pPvp), "enable", *(bool*)&static_cast<char&>(spData->m_cube.m_pvp.m_bEnabled));
            XmlGetAttr((class TiXmlElement*)(pPvp), "team", spData->m_cube.m_pvp.m_nTeam);
        }
        Unk_140165cf0* pWeb = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("openWeb"));
        if (pWeb != 0)
        {
            XmlGetAttr((class TiXmlElement*)(pWeb), "opentype", spData->m_cube.m_openWeb.m_nOpenType);
            XmlGetAttr((class TiXmlElement*)(pWeb), "target", spData->m_cube.m_openWeb.m_strTarget);
            XmlGetAttr((class TiXmlElement*)(pWeb), "webURL", spData->m_cube.m_openWeb.m_strUrl);
        }
        Unk_140165cf0* pNotice = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("noticePopup"));
        if (pNotice != 0)
            XmlGetAttr((class TiXmlElement*)(pNotice), "type", spData->m_cube.m_notice.m_strType);
        Unk_140165cf0* pNurturing = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pFunc))->FirstChild("nurturing"));
        if (pNurturing != 0)
        {
            ATL::CAtlArray<unsigned> list;
            if (FUN_140178670(pNurturing, "pluralNpcID", list) == 0)
            {
                for (unsigned i = 0; i < list.GetCount(); i++)
                {
                    short nKey = i + 1;
                    int nNpc = list[i];
                    spData->m_cube.m_nurturing.m_pluralNpcIds.SetAt(nKey, nNpc);
                }
                list.RemoveAll();
            }
            XmlGetAttr((class TiXmlElement*)(pNurturing), "nurturingQuestTag", spData->m_cube.m_nurturing.m_strQuestTag);
            if (FUN_140178670(pNurturing, "rewardItemByFeeding", list) == 0)
            {
                if (list.GetCount() == 3)
                {
                    spData->m_cube.m_nurturing.m_rewardByFeeding.m_nItemId = list[0];
                    spData->m_cube.m_nurturing.m_rewardByFeeding.m_nRarity = list[1];
                    spData->m_cube.m_nurturing.m_rewardByFeeding.m_nCount = list[2];
                }
                list.RemoveAll();
            }
            if (FUN_140178670(pNurturing, "rewardItem", list) == 0)
            {
                if (list.GetCount() == 3)
                {
                    spData->m_cube.m_nurturing.m_reward.m_nItemId = list[0];
                    spData->m_cube.m_nurturing.m_reward.m_nRarity = list[1];
                    spData->m_cube.m_nurturing.m_reward.m_nCount = list[2];
                }
                list.RemoveAll();
            }
            if (FUN_140178670(pNurturing, "requiredGrowth", list) == 0)
            {
                for (unsigned i = 0; i < list.GetCount(); i++)
                {
                    short nKey = i + 1;
                    unsigned __int64 nGrowth = list[i];
                    spData->m_cube.m_nurturing.m_requiredGrowth.SetAt(nKey, nGrowth);
                }
                list.RemoveAll();
            }
            if (FUN_140178670(pNurturing, "rewardItemByGrowth", list) == 0 && list.GetCount() >= 3)
            {
                short nStage = 1;
                for (unsigned i = 0; i < list.GetCount(); i += 3)
                {
                    CObjectData::RewardItem item;
                    item.m_nItemId = list[i];
                    item.m_nRarity = list[i + 1];
                    item.m_nCount = list[i + 2];
                    spData->m_cube.m_nurturing.m_rewardByGrowth.SetAt(nStage++, item);
                }
            }
        }
    }
    Unk_140165cf0* pConfig = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pRoot))->FirstChild("ConfigurableCube"));
    if (pConfig != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pConfig), "enable", spData->m_config.m_bEnabled);
        XmlGetAttr((class TiXmlElement*)(pConfig), "id", spData->m_config.m_strId);
    }
    else
        spData->m_config.m_bEnabled = 0;
    if (Unk_LockGuard guard = s_lock) {} else
        s_cache.SetAt(nId, spData);
    return spData;
}

// @0x1407071e0
int FUN_1407071e0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0 && spData->m_cube.m_bEnabled != 0)
            return 1;
    }
    return 0;
}

// @0x140707260
int FUN_140707260(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0 && spData->m_cube.m_bUseKfm != 0)
            return 1;
    }
    return 0;
}

// @0x1407072e0
int FUN_1407072e0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nControlType == 3 && spData->m_cube.m_nUiFunction == 2)
                return 1;
        }
    }
    return 0;
}

// @0x1407073a0
int FUN_1407073a0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nControlType == 3 && spData->m_cube.m_nUiFunction == 3)
                return 1;
        }
    }
    return 0;
}

// @0x140707460
int FUN_140707460(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0 && spData->m_cube.m_bEnabled != 0 && spData->m_cube.m_nControlType == 5)
            return 1;
    }
    return 0;
}

// @0x1407074f0
int FUN_1407074f0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nUiFunction == 4)
                return 1;
        }
    }
    return 0;
}

// @0x1407075a0
int FUN_1407075a0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nControlType == 4 || spData->m_cube.m_nControlType == 0xb)
                return 1;
        }
    }
    return 0;
}

// @0x140707660
int FUN_140707660(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nUiFunction == 1)
                return 1;
        }
    }
    return 0;
}

// @0x140707710
int FUN_140707710(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_bEnableTriggerControl != 0)
                return 1;
        }
    }
    return 0;
}

// @0x1407077c0
int FUN_1407077c0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nStateChangePermission == 1)
                return 1;
        }
    }
    return 0;
}

// @0x140707870
int FUN_140707870(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nUiFunction == 6)
                return 1;
        }
    }
    return 0;
}

// @0x140707920
int FUN_140707920(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_bForbidClimb != 0 || spData->m_cube.m_bForbidJump != 0 || spData->m_cube.m_bForbidSkill != 0 || spData->m_cube.m_bForbidPlayInstrument != 0)
                return 1;
        }
    }
    return 0;
}

// @0x140707a00
int FUN_140707a00(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_bForbidExceptOwner == 0)
                return 0;
            return 1;
        }
    }
    return 0;
}

// @0x140707ac0
int FUN_140707ac0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0 && spData->m_cube.m_nControlType == 6)
            return 1;
    }
    return 0;
}

// @0x140707b40
int FUN_140707b40(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0 && spData->m_cube.m_nControlType == 0xc)
            return 1;
    }
    return 0;
}

// @0x140707bc0
int FUN_140707bc0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_config.m_bEnabled == 0)
                return 0;
            return 1;
        }
    }
    return 0;
}

// @0x140707c60
int FUN_140707c60(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nControlType == 7)
                return 1;
        }
    }
    return 0;
}

// @0x140707d10
int FUN_140707d10(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nControlType == 8)
                return 1;
        }
    }
    return 0;
}

// @0x140707dc0
int FUN_140707dc0(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nControlType == 0xd)
                return 1;
        }
    }
    return 0;
}

// @0x140707e70
int FUN_140707e70(int nId)
{
    if (nId == 0)
        return 0;
    {
        CObjectDataPtr spData = FUN_140704ec0(nId);
        if (spData != 0)
        {
            if (spData->m_cube.m_bEnabled == 0)
                return 0;
            if (spData->m_cube.m_nControlType == 0xb)
                return 1;
        }
    }
    return 0;
}

// ---- sub-struct constructors (declaration order of the exe)

// @0x140708280
CObjectData::AdditionalEffect::AdditionalEffect()
    : m_nEffectId(0), m_nLevel(1), m_nTarget(0), m_fRange(0), m_bEnabled(0), m_bPopup(0)
{
}

// @0x1407082e0
CObjectData::AutoState::AutoState()
    : m_nStateA(-1), m_nStateB(-1), m_nTime(0)
{
}

// @0x1407084a0
CObjectData::FittingDoll::FittingDoll()
    : m_n00(0), m_nType(0), m_nGender(3)
{
}

// @0x140708470
CObjectData::ConfigurableCube::ConfigurableCube() throw()
{
}

// @0x140708500
CObjectData::FunctionCube::FunctionCube()
    : m_bEnabled(0), m_bUseKfm(0), m_nDefaultState(0), m_nControlType(1), m_nUiFunction(0), m_nCamera(0),
      m_bForbidJump(0), m_bForbidClimb(0), m_bForbidSkill(0), m_bForbidPlayInstrument(0), m_bForbidExceptOwner(0),
      m_bEnableTriggerControl(0), m_nStateChangePermission(0)
{
}

// @0x1407086e0
CObjectData::FirstPcAnimation::FirstPcAnimation()
    : m_nUsePcMove(0), m_vTranslation(0, 0, 0), m_vRotation(0, 0, 0)
{
}

// @0x1407087a0
CObjectData::Fusioner::Fusioner()
    : m_n00(0), m_nTemperature(0), m_nSacrifice(0)
{
}

// @0x1407087d0
CObjectData::Reactable::Reactable()
    : m_nRecipeId(0), m_strEffect("")
{
}

// @0x140708810
CObjectData::NoticePopup::NoticePopup()
    : m_strType("normal")
{
}

// @0x140708840
CObjectData::Nurturing::Nurturing()
    : m_strQuestTag(L"")
{
}

// @0x140708950
CObjectData::OpenWeb::OpenWeb()
    : m_strUrl(""), m_strTarget(""), m_nOpenType(0)
{
}

// @0x1407089b0
CObjectData::Pvp::Pvp()
    : m_bEnabled(0), m_nTeam(0)
{
}

// @0x1407089d0
CObjectData::RewardItem::RewardItem()
    : m_nItemId(0), m_nRarity(1), m_nCount(1)
{
}

// @0x140708a00
CObjectData::SkillObject::SkillObject()
    : m_n00(0), m_nSkillId(0), m_nSkillLevel(1), m_bFriendly(0)
{
}

// @0x140708a40
CObjectData::Spawner::Spawner()
    : m_fRadius(150.0f), m_nNpcCount(1), m_nNpcId(0), m_fRegenCheckTime(10.0f)
{
}


// ---- hooks ----
MS2_REPLACE_METHOD(0x140704BD0, CObjectData::Nurturing, operator=, 527, 0x51C01FF1);
MS2_REPLACE(0x140704EC0, FUN_140704ec0, 8980, 0x4441568F);
MS2_REPLACE(0x1407071E0, FUN_1407071e0, 115, 0x9A2DF719);
MS2_REPLACE(0x140707260, FUN_140707260, 115, 0x18689035);
MS2_REPLACE(0x1407072E0, FUN_1407072e0, 174, 0xC0FE9B3C);
MS2_REPLACE(0x1407073A0, FUN_1407073a0, 174, 0xA4CD1EF6);
MS2_REPLACE(0x140707460, FUN_140707460, 131, 0x415FBB0C);
MS2_REPLACE(0x1407074F0, FUN_1407074f0, 155, 0x6BAC4142);
MS2_REPLACE(0x1407075A0, FUN_1407075a0, 174, 0x4ECF54E2);
MS2_REPLACE(0x140707660, FUN_140707660, 155, 0xCE468427);
MS2_REPLACE(0x140707710, FUN_140707710, 155, 0xAB229F07);
MS2_REPLACE(0x1407077C0, FUN_1407077c0, 155, 0x4B81F463);
MS2_REPLACE(0x140707870, FUN_140707870, 155, 0xC4B3D53C);
MS2_REPLACE(0x140707920, FUN_140707920, 210, 0x4FDA165B);
MS2_REPLACE(0x140707A00, FUN_140707a00, 182, 0x503F0140);
MS2_REPLACE(0x140707AC0, FUN_140707ac0, 115, 0x73234A76);
MS2_REPLACE(0x140707B40, FUN_140707b40, 115, 0x6EA7692F);
MS2_REPLACE(0x140707BC0, FUN_140707bc0, 142, 0xF64C398E);
MS2_REPLACE(0x140707C60, FUN_140707c60, 155, 0x217BA0B3);
MS2_REPLACE(0x140707D10, FUN_140707d10, 155, 0x3DA52A8A);
MS2_REPLACE(0x140707DC0, FUN_140707dc0, 155, 0x765EB799);
MS2_REPLACE(0x140707E70, FUN_140707e70, 155, 0xB43B85B3);

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9ba80-0x142c9bac0 .text$yd
