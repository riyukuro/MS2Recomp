// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CAnimationManager: per-GameObject animation helper that
// plays named sequences on the owner's actor manager through the egmAnimation::AnimationService, plus the MS2
// modifications of that service / of NiActorManager::SetTargetAnimation / Reset first instantiated in this unit and
// the efd::map<utf8string, SequenceID> glue they use.
// MS2-UNIT: ?\animationmanager.cpp
// MS2-RANGE: 0x14099dbe0-0x1409a3360 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0V?$CustomAllocator@D@efd@@$$V@?$_Compressed_pair@V?$CustomAllocator@D@efd@@V?$_String_val@U?$_Simple_types@D@std@@@std@@$00@std@@QEAA@U_One_then_variadic_args_t@1@$$QEAV?$CustomAllocator@D@efd@@@Z 0x14099edc0 ; unique
// MS2-PIN: ??$addressof@$$CBU?$pair@$$CBIVutf8string@efd@@@std@@@std@@YAPEBU?$pair@$$CBIVutf8string@efd@@@0@AEBU10@@Z 0x1409a0a00 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@0@AEBV10@@Z 0x1409a0a10 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@0@AEAV10@@Z 0x1409a0c40 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@Vutf8string@efd@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBU?$less@Vutf8string@efd@@@2@XZ 0x1409a2880 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@Vutf8string@efd@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAU?$less@Vutf8string@efd@@@2@XZ 0x1409a2890 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@std@@QEAAAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@XZ 0x1409a28a0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@Vutf8string@efd@@@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@2@XZ 0x1409a28d0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@2@XZ 0x1409a28f0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBVutf8string@efd@@I@std@@@std@@SAPEAU?$pair@$$CBVutf8string@efd@@I@2@AEAU32@@Z 0x1409a32b0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEBU?$pair@$$CBIVutf8string@efd@@@std@@@std@@SAPEBU?$pair@$$CBIVutf8string@efd@@@2@AEBU32@@Z 0x1409a32d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?SetTargetAnimation@NiActorManager@@QEAA_NIM_N@Z 0x1409a20a0
// MS2-PIN: ??$_Construct1@PEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@AEAPEAU12@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@@std@@SAXU?$integral_constant@_N$00@1@AEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@1@AEAPEAU51@@Z 0x14099f030
// MS2-PIN: ??$_Destroy1@PEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@PEAPEAU?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@1@U?$integral_constant@_N$00@1@@Z 0x14099f130
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x1409a1100
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIVutf8string@efd@@@1@XZ 0x1409a1260
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBVutf8string@efd@@I@1@XZ 0x1409a1280
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVutf8string@efd@@I@std@@@std@@@std@@$00@std@@QEBAAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@XZ 0x1409a28b0
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@2@XZ 0x1409a2820
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIVutf8string@efd@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@1@@Z 0x1409a0d50
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@@2@AEBI@Z 0x1409a31a0
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@@std@@IEBAAEBIPEAU?$_Tree_node@U?$pair@$$CBIVutf8string@efd@@@std@@PEAX@2@@Z 0x1409a29a0
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1409a2960
// MS2-PIN: ?_Max_size1@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@@std@@SA_KAEBV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVutf8string@efd@@I@std@@PEAX@std@@@efd@@U?$integral_constant@_N$00@2@@Z 0x1409a2b10
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIVutf8string@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIVutf8string@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@$00@2@XZ 0x1409a28c0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIVutf8string@efd@@@std@@PEAX@std@@@efd@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@2@XZ 0x1409a28e0
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIVutf8string@efd@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVutf8string@efd@@@std@@@std@@@1@@Z 0x1409a0df0
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIVutf8string@efd@@@std@@PEAX@1@AEBI@Z 0x1409a05e0
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBIVutf8string@efd@@@2@@Z 0x1409a29d0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x1409a25c0
// MS2-PIN: ??$_Kfn@$$CBIVutf8string@efd@@@?$_Tmap_traits@IVutf8string@efd@@U?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIVutf8string@efd@@@std@@@2@$0A@@std@@SAAEBIAEBU?$pair@$$CBIVutf8string@efd@@@1@@Z 0x1409a05d0
// MS2-FUNCTIONAL: the _Compressed_pair<CustomAllocator<char>,_String_val> ctor COMDAT 0x14099edc0 (its _String_val ctor
// binds to the duplicate 0x141bf2e70 instead of 0x1401d25d0; NOTES.md "w18 (animationmanager)").
// NiActorManager / NiControllerManager are the engine headers with Nexon's changes (`// MS2:`): the MS2
// SetTargetAnimation (0x1409a20a0), Reset (0x1409a1cd0) and NiControllerManager::SetSequenceDataValue (0x1409a1f80)
// are their inlines, first instantiated here.
#include "ms2/placeholder/ms2stdafx.h"
#include "animationmanager.h"
#include "gameobject.h"
#include "ms2actormanager.h"
#include "ms2/placeholder/cmainsystem.h"
#include <egmAnimation/AnimationService.h>
#include <egf/EntityID.h>
#include <NiActorManager.h>
#include <NiAVObject.h>
#include <NiControllerManager.h>
#include <NiControllerSequence.h>
#include <NiKFMTool.h>
#include <NiSequenceData.h>
#include <NiTMap.h>
#include <efd/StdContainers.h>
#include <efd/utf8string.h>

// ---- exe data ----
extern int DAT_1439f4840;                       // default code page (localepath.cpp)

// ---- exe functions outside this unit ----
void FUN_140996bc0(Unk_AnimTable* pTable, void* p);
void FUN_1409975a0(Unk_AnimTable* pTable, void* p);
void FUN_140997070(Unk_AnimTable* pTable, GameObject* pOwner, CString str);
class Unk_GameClock;
void FUN_14028b2d0(void* pList, const CString& str);                    // list.push_back
Unk_AnimSvc* FUN_141b6f910();
void* FUN_1413f9b10();   // C3: was FUN_1413f9b10
NiActorManager* FUN_1413f9b70(const egf::EntityID& id);                 // actor manager of an entity (via the service)
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);
CStringW FUN_14016a730(const char* psz, int nCodePage);                 // multibyte -> wide
CString FUN_14016a600(const wchar_t* psz, int nCodePage);               // wide -> multibyte
CString FUN_140391100(const wchar_t* psz);
CStringW XmlWide(const char* pszUtf8);                                  // utf8 -> wide

// ---- unit-local views of exe objects ----
// The MS2 build of egmAnimation::AnimationService: SetTargetAnimation by name takes a blend time and a force flag and
// looks the id up with map::operator[].
class Unk_AnimSvc : public egmAnimation::AnimationService
{
public:
    bool FUN_1409a1fc0(const egf::EntityID& entityID, const efd::utf8string& sequenceName, float fBlend, bool bForce);   // 0x1409a1fc0
};

// The game-side actor (class id 0x6200003) a GameObject casts to; only slots 60 / 136 and FUN_141659790 are used here.
class Unk_AnimActor : public GameObject
{
public:
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual CString vfunc_60();                         // 0x1e0 model path of the actor
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void vfunc_86();
    virtual void vfunc_87();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_90();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void vfunc_93();
    virtual void vfunc_94();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_97();
    virtual void vfunc_98();
    virtual void vfunc_99();
    virtual void vfunc_100();
    virtual void vfunc_101();
    virtual void vfunc_102();
    virtual void vfunc_103();
    virtual void vfunc_104();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void vfunc_107();
    virtual void vfunc_108();
    virtual void vfunc_109();
    virtual void vfunc_110();
    virtual void vfunc_111();
    virtual void vfunc_112();
    virtual void vfunc_113();
    virtual void vfunc_114();
    virtual void vfunc_115();
    virtual void vfunc_116();
    virtual void vfunc_117();
    virtual void vfunc_118();
    virtual void vfunc_119();
    virtual void vfunc_120();
    virtual void vfunc_121();
    virtual void vfunc_122();
    virtual void vfunc_123();
    virtual void vfunc_124();
    virtual void vfunc_125();
    virtual void vfunc_126();
    virtual void vfunc_127();
    virtual void vfunc_128();
    virtual void vfunc_129();
    virtual void vfunc_130();
    virtual void vfunc_131();
    virtual void vfunc_132();
    virtual void vfunc_133();
    virtual void vfunc_134();
    virtual void vfunc_135();
    virtual void vfunc_136(const CString& strModel, const efd::utf8string& kAnim, float fScale);   // 0x440 play
    virtual void vfunc_137();
    virtual void vfunc_138();
    virtual void vfunc_139();
    void FUN_141659790(const CString& str);                 // 0x141659790
};

Unk_AnimActor* FUN_14099eef0(GameObject* pObj);
CString FUN_1409a2360(const char* psz, int nCodePage);
CString FUN_1409a2470(const char* psz, int nCodePage);

// ---- CAnimationManager ----
CAnimationManager::CAnimationManager(GameObject* pOwner)
    : m_pOwner(pOwner)
{
    m_fScale98 = 1.0f;
    m_pModelCache = FUN_141b6f910();
}

CAnimationManager::~CAnimationManager()
{
}

bool CAnimationManager::FUN_14099dcd0(const efd::utf8string& kName)
{
    if (m_pModelCache == 0)
        return false;
    efd::UInt64 qwId1;
    NiActorManager* pMgr = m_pModelCache->GetActorManager(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId1)));
    if (pMgr == 0)
        return false;
    efd::UInt64 qwId2;
    NiActorManager::SequenceID nSeq = m_pModelCache->GetAnimationIdFromName(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId2)), kName);
    if (nSeq == NiActorManager::INVALID_SEQUENCE_ID)
        return false;
    NiControllerSequence* pSeq = pMgr->GetActiveSequence(nSeq, true, true);
    if (pSeq == 0)
        return false;
    if (pSeq->GetState() == ANIMATING)
        return true;
    return false;
}

CString CAnimationManager::FUN_14099ddb0(const efd::utf8string& kName)
{
    efd::UInt64 qwId1;
    if (NiActorManager::INVALID_SEQUENCE_ID ==
        m_pModelCache->GetAnimationIdFromName(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId1)), kName))
    {
        return CString("");
    }
    efd::utf8string kResolved(kName);
    Unk_AnimActor* pActor = FUN_14099eef0(m_pOwner);
    if (pActor != 0)
    {
        efd::utf8string kPrefix((const char*)FUN_1409a2360((const char*)pActor->vfunc_60(), 0));
        if (!((efd::utf8string*)&(kPrefix))->empty())
        {
            kResolved = kPrefix + kName;
            efd::UInt64 qwId2;
            if (m_pModelCache->GetAnimationIdFromName(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId2)), kResolved) ==
                NiActorManager::INVALID_SEQUENCE_ID)
            {
                kResolved = kName;
            }
        }
        else
        {
            kResolved = kName;
        }
    }
    return FUN_1409a2470(kResolved.c_str(), 0);
}

bool CAnimationManager::FUN_14099e050(Unk_AnimRef& kName, float fScale, bool bForce)
{
    efd::UInt64 qwId1;
    if (NiActorManager::INVALID_SEQUENCE_ID ==
        m_pModelCache->GetAnimationIdFromName(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId1)), kName))
    {
        return false;
    }
    m_fScale98 = fScale;
    m_78 = kName;
    efd::utf8string kResolved(kName);
    Unk_AnimActor* pActor = FUN_14099eef0(m_pOwner);
    if (pActor != 0)
    {
        efd::utf8string kPrefix((const char*)FUN_1409a2360((const char*)pActor->vfunc_60(), 0));
        if (!((efd::utf8string*)&(kPrefix))->empty())
        {
            kResolved = kPrefix + kName;
            efd::UInt64 qwId2;
            if (m_pModelCache->GetAnimationIdFromName(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId2)), kResolved) ==
                NiActorManager::INVALID_SEQUENCE_ID)
            {
                kResolved = kName;
            }
        }
        else
        {
            kResolved = kName;
        }
    }
    CString strAnim = FUN_1409a2470(kResolved.c_str(), 0);
    FUN_140997070(&m_table, m_pOwner, strAnim);
    float fHeight = ((struct Unk_AnimTable*)(struct Unk_AnimTable*)(&m_table))->FUN_140997650(strAnim);
    m_pOwner->vfunc_43(fHeight);
    efd::UInt64 qwId3;
    NiActorManager::SequenceID nSeq = m_pModelCache->GetAnimationIdFromName(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId3)), kResolved);
    if (nSeq == NiActorManager::INVALID_SEQUENCE_ID)
        return false;
    efd::UInt64 qwId4;
    NiActorManager* pMgr = m_pModelCache->GetActorManager(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId4)));
    if (pMgr != 0 && !bForce && pMgr->GetTargetAnimation() == nSeq)
        return false;
    efd::UInt64 qwId5;
    bool bOk = m_pModelCache->FUN_1409a1fc0(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId5)), kResolved, fScale, bForce);
    if (bForce)
    {
        efd::UInt64 qwId6;
        NiActorManager* pForced = m_pModelCache->GetActorManager(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId6)));
        if (pForced != 0)
            pForced->Update((float)((class CMainSystem*)(class Unk_GameClock*)(reinterpret_cast<Unk_GameClock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280());
        NiAVObject* pRoot = FUN_141b6efc0(((class GameObject*)(m_pOwner))->FUN_14123c410());
        if (pRoot != 0)
            pRoot->Update((float)((class CMainSystem*)(class Unk_GameClock*)(reinterpret_cast<Unk_GameClock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), true);
    }
    if (pActor != 0)
    {
        CString strModel = pActor->vfunc_60();
        pActor->FUN_141659790(strAnim);
        pActor->vfunc_136(strModel, kName, fScale);
    }
    return bOk;
}

void CAnimationManager::FUN_14099e640()
{
    FUN_14099e050(m_78, m_fScale98, false);
}

void CAnimationManager::FUN_14099e680()
{
    efd::UInt64 qwId;
    NiActorManager* pMgr = m_pModelCache->GetActorManager(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId)));
    if (pMgr == 0)
        return;
    pMgr->SetTargetAnimation(NiActorManager::INVALID_SEQUENCE_ID, 1.0f, false);
    if (pMgr->GetTransitionState() == NiActorManager::NO_TRANSITION)
        pMgr->Update(0.0f);
}

void CAnimationManager::FUN_14099e710(float fOffset)
{
    efd::UInt64 qwId;
    NiActorManager* pMgr = m_pModelCache->GetActorManager(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId)));
    if (pMgr != 0)
    {
        NiControllerSequence* pSeq = pMgr->GetActiveSequence(pMgr->GetCurAnimation(), true, true);
        if (pSeq != 0)
            pSeq->SetOffset(fOffset);
    }
}

void CAnimationManager::FUN_14099e7a0(void* p)
{
    FUN_140996bc0(&m_table, p);
}

void CAnimationManager::FUN_14099e7d0(void* p)
{
    FUN_1409975a0(&m_table, p);
}

void CAnimationManager::FUN_14099e800(void* pList)
{
    efd::UInt64 qwId1;
    NiActorManager* pMgr = m_pModelCache->GetActorManager(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId1)));
    if (pMgr == 0)
        return;
    NiKFMTool* pKFM = pMgr->GetKFMTool();
    if (pKFM == 0)
        return;
    unsigned int* pIDs = 0;
    unsigned int uiNum = 0;
    pKFM->GetSequenceIDs(pIDs, uiNum);
    for (size_t i = 0; i < uiNum; i++)
    {
        efd::UInt64 qwId2;
        efd::utf8string kName = m_pModelCache->GetAnimationNameFromId(m_pOwner->FUN_14123c460(reinterpret_cast<egf::EntityID&>(qwId2)), pIDs[i]);
        if (kName == efd::utf8string::NullString())
            continue;
        FUN_14028b2d0(pList, CString(kName.c_str()));
    }
    if (pIDs != 0)
        NiFree(pIDs);
}

int FUN_14099e9c0(const egf::EntityID& kId, CString strName)
{
    Unk_AnimSvc* pSvc = ((class Unk_AnimSvc*)FUN_1413f9b10());
    NiActorManager* pMgr = FUN_1413f9b70(kId);
    if (pMgr == 0)
        return 0;
    NiActorManager::SequenceID nSeq = pSvc->GetAnimationIdFromName(kId, (const char*)strName);
    if (nSeq == NiActorManager::INVALID_SEQUENCE_ID)
        return 0;
    NiSequenceData* pSeqData = pMgr->GetSequenceData(nSeq);
    if (pSeqData == 0)
        return 0;
    return pSeqData->GetCycleType() == NiTimeController::LOOP;
}

float FUN_14099eb30(const egf::EntityID& kId, CString strName)
{
    Unk_AnimSvc* pSvc = ((class Unk_AnimSvc*)FUN_1413f9b10());
    NiActorManager::SequenceID nSeq = pSvc->GetAnimationIdFromName(kId, (const char*)strName);
    if (nSeq == NiActorManager::INVALID_SEQUENCE_ID)
        return 0.0f;
    float fDuration = 0.0f;
    pSvc->GetSequenceDurationById(kId, nSeq, fDuration);
    return fDuration;
}

Unk_AnimActor* FUN_14099eef0(GameObject* pObj)
{
    void* pActor = 0;
    if (pObj != 0 && pObj->TypeCast(0x6200003, &pActor))
        return (Unk_AnimActor*)pActor;
    else
        return 0;
}

// ---- MS2 AnimationService / NiActorManager modifications ----
bool Unk_AnimSvc::FUN_1409a1fc0(const egf::EntityID& entityID, const efd::utf8string& sequenceName, float fBlend,
    bool bForce)
{
    ActorEntry* pEntry;
    if (!ContainsEntity(entityID, pEntry))
        return false;
    AssetData* pAssetData = pEntry->m_spAssetData;
    if (!pAssetData)
        return false;
    NiActorManager::SequenceID sequenceID = pAssetData->m_sequenceIDs[sequenceName];
    if (sequenceID == NiActorManager::INVALID_SEQUENCE_ID)
        return false;
    pEntry->m_currentSequenceID = sequenceID;
    NiActorManager* pActorManager = pEntry->m_spActorManager;
    if (!pActorManager)
        return false;
    return pActorManager->SetTargetAnimation(sequenceID, fBlend, bForce);
}

// ---- string conversions (code page 0 = the default one) ----
CString FUN_1409a1620(const char* psz, int nCodePage)
{
    int cp = (nCodePage == 0) ? DAT_1439f4840 : nCodePage;
    CStringW str = FUN_14016a730(psz, cp);
    return FUN_140391100((const wchar_t*)str);
}

CString FUN_1409a2360(const char* psz, int nCodePage)
{
    int cp = (nCodePage == 0) ? DAT_1439f4840 : nCodePage;
    return FUN_1409a1620(psz, cp);
}

CString FUN_1409a23d0(const char* pszUtf8, int nCodePage)
{
    int cp = (nCodePage == 0) ? DAT_1439f4840 : nCodePage;
    CStringW str = XmlWide(pszUtf8);
    return FUN_14016a600((const wchar_t*)str, cp);
}

CString FUN_1409a2470(const char* pszUtf8, int nCodePage)
{
    int cp = (nCodePage == 0) ? DAT_1439f4840 : nCodePage;
    return FUN_1409a23d0(pszUtf8, cp);
}
