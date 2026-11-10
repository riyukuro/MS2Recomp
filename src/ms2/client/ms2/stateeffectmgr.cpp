// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateEffectMgr: Table/StateEffectPC.xml, the effects an avatar
// plays for a state (std::map<int, std::list<StateEffectData>> plus its template glue).
// MS2-UNIT: ?\stateeffectmgr.cpp
// MS2-RANGE: 0x1400cf5f0-0x1400cf710 .text$di
// MS2-RANGE: 0x140c9f7a0-0x140ca4360 .text$mn
// MS2-RANGE: 0x142ca3a70-0x142ca3ae0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140c9ffc0 ; unique
// MS2-PIN: ??$?0AEBH@?$_Tuple_val@AEBH@std@@QEAA@AEBH@Z 0x140ca00b0 ; unique
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBH$$V$0A@@?$tuple@AEBH@std@@QEAA@U_Exact_args_t@1@AEBH@Z 0x140ca00e0 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140ca0190 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ca0200 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@1@@Z 0x140ca0840 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@1@@Z 0x140ca1480 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140ca1940 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ca1b90 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140ca1cf0 ; unique
// MS2-PIN: ??$forward@AEBU?$less@H@std@@@std@@YAAEBU?$less@H@0@AEBU10@@Z 0x140ca1dd0 ; prop
// MS2-PIN: ??$forward@V?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x140ca1e10 ; prop
// MS2-PIN: ??$forward_as_tuple@AEBH@std@@YA?AV?$tuple@AEBH@0@AEBH@Z 0x140ca1e20 ; unique
// MS2-PIN: ??$get@$0A@AEBH@std@@YAAEBH$$QEAV?$tuple@AEBH@0@@Z 0x140ca1e50 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x140ca1e70 ; prop
// MS2-PIN: ??0?$tuple@AEBH@std@@QEAA@$$QEAV01@@Z 0x140ca22a0 ; unique
// MS2-PIN: ??R?$less@H@std@@QEBA_NAEBH0@Z 0x140ca2910 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x140ca2cd0 ; unique
// MS2-PIN: ??$forward@PEBD@std@@YA$$QEAPEBDAEAPEBD@Z 0x140ca1df0 ; manual
// MS2-PIN: ??$forward@PEAV?$map@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@@std@@@std@@YA$$QEAPEAV?$map@HV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$list@UStateEffectData@@V?$allocator@UStateEffectData@@@std@@@std@@@std@@@2@@0@AEAPEAV10@@Z 0x140ca1df0 ; manual
// MS2-PIN: ??$forward@PEAVGameObject@@@std@@YA$$QEAPEAVGameObject@@AEAPEAV1@@Z 0x140ca1df0 ; manual
// MS2-PINS-END tplpin
// Caller-pinned: the exe callers of these 11-byte identity functions reference these names in our obj. Unpinned, the
// names stayed bound to a byte-identical copy elsewhere and a hook helper with the same bytes was paired here.
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x140ca1df0
// MS2-PIN: ??$?0AEBH$0A@@?$tuple@AEBH@std@@QEAA@AEBH@Z 0x140ca0060 ; cf7: own byte-identical copy (table binds 0x1401e7be0 / 0x1401d97a0)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateeffectmgr.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "stateeffectmgr.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC (efd::DynamicCast<PC, PCBase>)
class TiXmlElement;
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view




class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};

// Unrecovered helpers (the same xml loader helpers the other table units use).
// C3 #12: was a local TiXml view
class Unk_140166420 : public CFileSystem { };
class CLogString* GetLogString();   // C3: was FUN_140166440
template <class T> void Unk_FileLog(class CLogString*, int, int, const wchar_t*, const T&);   // 0x1403a1280 for T = const char*
CString GetXmlPath(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
unsigned char FUN_1401d1320(CCacheData*);
int FUN_1417b90f0(CString strName);                                      // state name -> state type

// The avatar's character info (gender) and the effect lookup key, both unrecovered.
class Unk_StateActorInfo;
class WorldService   // C3: member view for the former free stand-ins
{
public:
    int GetObjectKind(class Unk_WsC_GameObj*);
    static class WorldService* GetInstance();
};

// State name table (the strings the stateType attribute is matched against) and two single names.
static CString s_strStateNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
static CString s_strSkill("skill");
static CString s_strStun("stun");

// @0x140c9f7a0
StateEffectData::StateEffectData()
    : m_nStateType(0), m_nEmotionSkillId(0), m_nSetId(0), m_nSkillId(0), m_nPad1c(0), m_nGender(2)
{
}

// @0x140c9f820
StateEffectData::~StateEffectData()
{
}

// @0x140c9f840
StateEffectMgr::StateEffectMgr()
{
}

// @0x140c9f8a0
StateEffectMgr::~StateEffectMgr()
{
}

// @0x140c9f8f0
bool StateEffectMgr::Load()
{
    CString strPath = GetXmlPath("Table", "StateEffectPC.xml");
    m_cache.SetPath(CString(strPath));
    m_effects.clear();
    return LoadXml(strPath, &m_effects);
}
#ifndef MS2_HOOK_DLL
MS2_REPLACE_METHOD(0x140C9F8F0, StateEffectMgr, Load, 253, 0x7EC8B773);
#endif

// @0x140c9fa00
void StateEffectMgr::GetEffects(GameObject* pObject, int nStateType, Unk_StateEffectIdList* pOut)
{
    if (FUN_1401d1320(&m_cache) != 0)
        Load();
    if (!IsPlayerObject(pObject))
        return;
    EffectList& list = m_effects[nStateType];
    for (EffectList::iterator it = list.begin(); it != list.end(); ++it)
    {
        Unk_StateActorInfo* pInfo;
        if (it->m_nGender != 2 && (pInfo = reinterpret_cast<Unk_StateActorInfo*>(efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(pObject)))) != 0)
        {
            if (reinterpret_cast<PC*>(pInfo)->GetGender() != it->m_nGender)
                continue;
        }
        if (it->m_nEmotionSkillId != 0)
        {
            if (!(nStateType == 0xb || nStateType == 0xf || nStateType == 0x3a))
                continue;
            else if (reinterpret_cast<PCBase*>(pObject)->FUN_14166f6d0() != it->m_nEmotionSkillId)
                continue;
        }
        Unk_EffectQuery query;
        query.m_strName = it->m_strEffect;
        query.m_nObject = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->GetObjectKind((class Unk_WsC_GameObj*)(pObject));
        query.SetActor(reinterpret_cast<GameObject*>(pObject)->GetObjectId());
        int nEffectId = reinterpret_cast<CEffectService*>(((void*)TSingleton<CEffectService>::GetInstance()))->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(static_cast<NoticeMessage*>(&query)));
        if (nEffectId != 0)
            pOut->push_back(reinterpret_cast<const unsigned&>(nEffectId));
    }
}
#ifndef MS2_HOOK_DLL
MS2_REPLACE_METHOD(0x140C9FA00, StateEffectMgr, GetEffects, 537, 0x416A3AC9);
#endif

// @0x140c9fc30
bool StateEffectMgr::IsPlayerObject(GameObject* pObject)
{
    unsigned id = pObject->GetClassID();
    switch (id)
    {
    case 0x6200003:
    case 0x6200004:
    case 0x6200044:
        return true;
    }
    return false;
}
#ifndef MS2_HOOK_DLL
MS2_REPLACE_METHOD(0x140C9FC30, StateEffectMgr, IsPlayerObject, 85, 0xEDD991A6);
#endif

// @0x140c9fc90
bool StateEffectMgr::LoadXml(const char* pszPath, EffectMap* pMap)
{
    TiXmlDocument doc;
    if (((class CFileSystem*)(((class Unk_140166420*)GetFileSystem())))->LoadXmlFile(&doc, pszPath, 0, true, false) == 0)
        return false;
    TiXmlElement* pRoot = ((class TiXmlElement*)((class Unk_XmlNode*)(reinterpret_cast<TiXmlElement*>(&doc)))->FirstChild("ms2"));
    if (pRoot == 0)
    {
        Unk_FileLog<const char*>(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", pszPath);
        return false;
    }
    for (TiXmlElement* pNode = ((class TiXmlElement*)((class Unk_XmlNode*)(pRoot))->FirstChild("StateEffect")); pNode != 0; pNode = pNode->NextSiblingElement())
    {
        const char* pszType = ((class TiXmlElement*)(class TiXmlElement*)(pNode))->Attribute("stateType");
        int nStateType = FUN_1417b90f0(pszType);
        if (nStateType != 0)
        {
            StateEffectData data;
            const char* pszEffect = ((class TiXmlElement*)(class TiXmlElement*)(pNode))->Attribute("effect");
            if (pszEffect != 0)
            {
                data.m_nStateType = nStateType;
                data.m_strEffect = pszEffect;
                TiXmlElement* pInfo = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("Info"));
                if (pInfo != 0)
                {
                    XmlGetAttr((class TiXmlElement*)(pInfo), "emotionSkillID", *(unsigned int*)&static_cast<int&>(data.m_nEmotionSkillId));
                    XmlGetAttr((class TiXmlElement*)(pInfo), "setID", *(unsigned int*)&static_cast<int&>(data.m_nSetId));
                    XmlGetAttr((class TiXmlElement*)(pInfo), "skillID", *(unsigned int*)&static_cast<int&>(data.m_nSkillId));
                    XmlGetAttr((class TiXmlElement*)(pInfo), "gender", *(unsigned int*)&static_cast<int&>(data.m_nGender));
                    (*pMap)[nStateType].push_back(data);
                }
            }
        }
    }
    return true;
}
#ifndef MS2_HOOK_DLL
MS2_REPLACE_METHOD(0x140C9FC90, StateEffectMgr, LoadXml, 640, 0xFFBF770E);
#endif
MS2_EMIT_CRT_MEMMOVE_S();
