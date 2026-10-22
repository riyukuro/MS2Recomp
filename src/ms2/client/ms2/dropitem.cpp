// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See dropitem.h.
// MS2-UNIT: client\ms2\dropitem.cpp
// MS2-RANGE: 0x14118c730-0x141192960 .text$mn
// MS2-RANGE: 0x1400e7300-0x1400e74f0 .text$di
// MS2-PIN: ?GetClassDesc@CDropItem@@UEBAPEBVClassInfo@efd@@XZ 0x141192770
// MS2-PIN: ?TypeCast@CDropItem@@UEBA_NIPEAPEAX@Z 0x1411928c0
// MS2-PIN: ?TypeCast@CDropItem@@UEBA_NIPEAPEBX@Z 0x141192910
// MS2-PIN: ??_7CDropItem@@6BIBase@efd@@@ 0x142eb89c8
// MS2-PIN: ??0CDropItem@@QEAA@HH@Z 0x14118c730
// MS2-PIN: ??_7CDropItem@@6BCallbackObject@NiActorManager@@@ 0x142eb8b98
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\dropitem.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dropitem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <io.h>
#include <math.h>
#include <NxPhysics.h>
#include <NiTransform.h>
#include <NiTexturingProperty.h>
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/physxhelper.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/placeholder/cinteractobjectdata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/commonfiles/blockchecker.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/client/ms2/arccontroller.h"

// ---- unit-local views of exe objects and unrecovered callees ----

class Unk_WsC_GameObj : public GameObject
{
public:
    virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59(); virtual void vfunc_60(); virtual void vfunc_61();
    virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66();
    virtual void vfunc_67(Unk_StreamPoint* pForward, Unk_StreamPoint* pSide);   // 0x218
};

// The actor's ground shadow (unit_14160fb10 holds its methods; only the members this unit reads are named).
class CObjectShadow : public NiRefObject
{
public:
    CObjectShadow(GameObject* pOwner, int nLodHi, int nLodLo, float fSize, float fAlpha);   // 0x14160fc90
    void FUN_14160fe10(bool bValue);                                // 0x14160fe10
    void FUN_14160fe50(bool bNear);                                 // 0x14160fe50
    void FUN_14160feb0(int nActive, const efd::Point3& kPos, const efd::Point3& kDir, float fTime, bool bForce);
    void FUN_1416105c0();                                           // 0x1416105c0
    bool FUN_14109a720();                                           // 0x14109a720
private:
    char m_pad_10[0x30 - sizeof(NiRefObject)];
public:
    bool m_bEnabled;                                                // +0x30
    bool m_bFlag31;                                                 // +0x31
    bool m_bFlag32;                                                 // +0x32
    bool m_bDirty;                                                  // +0x33
private:
    char m_pad_34[0x58 - 0x34];
};
MS2_CHECK_SIZE(CObjectShadow, 0x58);

// The shadow quality settings (?\gameoption.cpp keeps the full view).
class Unk_DropShadowCfg
{
public:
    int FUN_141376880(int n);
    int FUN_1413769d0(int n);
};
Unk_DropShadowCfg* FUN_140ae1c00();

// The sound / effect service (FUN_1403ed280), see effectservice.h.
CEffectService* FUN_1403ed280();

// The notice and guide managers.
class Unk_DropGuideMgr
{
public:
    int FUN_14138c900(int nGuide);                                  // the guide was cleared
    void FUN_14138bf00(int nGuide, int nItemId, int nA);
};
Unk_DropGuideMgr* FUN_1409331e0();
void FUN_141275260(int nSound, int a, int b);
void FUN_141276180(const CString& strKey, const CString& strArg);   // system notice
void FUN_1412751b0(const CStringW& strText, int nSeconds);          // center notice

// The ui dialogs a pickup notifies.
class Unk_DropPickDlg
{
public:
    void FUN_141913060(GameObject* pActor, int nCount, CString strName);   // pickup notice of an item
    void FUN_141912a80(GameObject* pActor, int nAmount, int bMeso);        // pickup notice of meso
};
Unk_DropPickDlg* FUN_140b624b0(int nUiId);
class Unk_DropBagDlg { public: void FUN_141abfa10(MS2Ptr<CItem> spItem); };
Unk_DropBagDlg* FUN_140938cd0(int nUiId);
void FUN_14098c6e0(egf::Entity* pEntity, unsigned int uiPropId, const bool& b);   // set an entity bool property
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                           // the scene root of an entity
void FUN_141851f90(void* pRoot, unsigned int uValue);
void FUN_141852050(void* pRoot, unsigned int uValue);
void* FUN_14086d260();
double FUN_141473280(void* p);                                      // the frame time
void FUN_141545250(egf::EntityID& kId, bool b);
bool FUN_14087ddc0(const efd::ClassInfo* pInfo, unsigned int nId);  // is of the class id
unsigned int FUN_140869420();                                       // the tick count (ms)
CString FUN_140540050(const char* szFormat, const CString& strArg); // StringFormat<CString>
bool FUN_14053f8c0(unsigned nItemId);                               // the item id is meso
bool FUN_14053f900(unsigned nItemId);                               // the item id is a special item
void FUN_1401d3700(CString& str);
bool FUN_14109a9a0(const NiRTTI* pRtti, NiAVObject* pObj);          // is of the type
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);    // dynamic cast through an NiRTTI
extern char DAT_143afbbb0;                                          // NiMesh::ms_RTTI
extern char DAT_143afa4f0;                                          // NiTexturingProperty::ms_RTTI
NiTexturingProperty::Map* FUN_14109a6b0(NiTexturingProperty* pProp);   // the base map
void FUN_140981040(NiTexturingProperty::Map* pMap, NiTexture* pTex);   // Map::SetTexture
class Unk_DropTextures { public: NiTexturePtr FUN_141552f90(CString strPath, char nFlags); };
Unk_DropTextures* FUN_140a0afd0();
class Unk_DropPickTick                                              // 8-byte throttle (static of FUN_141190900)
{
public:
    Unk_DropPickTick();                                             // 0x140517b00
    int FUN_140268870(int nMs);                                     // 1 when nMs have passed since the last 1
private:
    __int64 m_tick;
};

// More unit-local views of exe objects (the drop source, the model attachment, the item data, the prop of a tree).
class Unk_WsB_Prop : public CInteractObject { };
class Unk_GoAttachment { public: char m_pad[0xb4]; Unk_StreamPoint m_pos; };   // +0xb4 the placement point
class Unk_ItemEquipData { public: int FUN_14053c5c0(); };                      // the item kind
class Unk_DropAnimSvc { public: NiActorManager* FUN_140999440(const egf::EntityID& kId); };
Unk_DropAnimSvc* FUN_141b6f910();
void FUN_1409fae00(NiActorManager* pMgr, bool b);
GameObject* FUN_14096e160(Unk_WsC_GameObj* pObj);                   // the object behind a world pointer
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
CString* FUN_140298f80(Common::Constants::Value<CString>* pValue);   // Value<CString>::Get as a free function
bool FUN_140184310(const CStringA& str, const char* psz);            // str == psz
class CBlockManager* FUN_140a6a830();
extern Unk_Inventory DAT_143ab2a90;
int FUN_140768010(unsigned nRange, unsigned nBase);                  // random in base..base+range-1
float FUN_140966f00(Unk_StreamPoint kA, Unk_StreamPoint kB);        // the horizontal distance
CPhysXHelper* FUN_1409f7ca0();
int FUN_14147a500(Unk_StreamPoint* pOut, const Unk_StreamPoint* pStart, const Unk_StreamPoint* pEnd, char bProbe, float fProbeLen, const NxGroupsMask* pMask);
extern Unk_StreamPoint DAT_143a08ce8;                               // NiPoint3::UNIT_Y
extern Unk_StreamPoint DAT_143a08cf8;                               // NiPoint3::UNIT_Z
extern Unk_StreamPoint DAT_143a08d08;                               // NiPoint3::ALL_ONES

// Fills an identity transform at kPos (the sound and effect placement of a drop).
static void MakeXform(NiTransform& kXform, const NiPoint3& kPos)
{
    kXform.m_fScale = 1.0f;
    kXform.m_Translate = kPos;
    kXform.m_Rotate = NiMatrix3::IDENTITY;
}

// ---- the unit's timer, class info and header statics (the .text$di order) ----
static Timer s_kPickTimer;                                          // @0x1400e7300
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CDropItem);                        // @0x1400e7330
#include "ms2/placeholder/header_statics_a.h"                       // @0x1400e7350..0x1400e7470
static CString s_strWarningBag("system_notice_error_warningBag");   // @0x1400e74c0

// ---- helpers ----


// The horizontal direction kTo - kFrom (z cleared on the copies), unit length when bUnitize.
// @0x141192780
Unk_StreamPoint FUN_141192780(Unk_StreamPoint kFrom, Unk_StreamPoint kTo, bool bUnitize)
{
    kFrom.z = 0.0f;
    kTo.z = 0.0f;
    if (bUnitize)
    {
        Unk_StreamPoint kDir = kTo.FUN_140965c40(kFrom);
        kDir.FUN_140968990();
        return kDir;
    }
    else
        return kTo.FUN_140965c40(kFrom);
}

// @0x141192820
bool FUN_141192820(CObjectShadow* pShadow) { return pShadow->m_bDirty; }

// @0x141192830
bool FUN_141192830(CObjectShadow* pShadow) { return pShadow->m_bEnabled; }

// ---- CDropItem ----

// @0x14118c730
CDropItem::CDropItem(int nType, int nRarity)
    : GameObject()
    , m_nAmount(0)
    , m_fElapsed(0.0f)
    , m_n64Meso(0)
    , m_owners(10)
    , m_n188(0)
    , m_nOwnerObjId(0)
    , m_nNpcType(0)
    , m_nEffectIdA(0)
    , m_nEffectIdB(0)
    , m_nState(6)
    , m_nOwnerType(nType)
    , m_nDropKind(nRarity)
    , m_nTick(0)
    , m_pfnState(0)
    , m_n278(0)
    , m_n28c(0)
    , m_nFadeTime(0)
    , m_n298(0)
{
    m_unk_b0 = 1;
    m_str88 = "";
    s_kPickTimer.FUN_140868750(10);
    m_f218 = Client::Constants::GetInstance()->DropItemTargetZPos.Read();
    m_f21c = Client::Constants::GetInstance()->DropItemMaxLength.Read();
    m_f220 = Client::Constants::GetInstance()->DropMoneyMaxLength.Read();
    m_f224 = Client::Constants::GetInstance()->DropItemPickUpVel.Read();
    m_f228 = Client::Constants::GetInstance()->DropItemPickUpGravity.Read();
    m_f22c = Client::Constants::GetInstance()->DropItemPickUpCompleteRotateTime.Read();
    m_f230 = Client::Constants::GetInstance()->DropItemPickUpCompleteRotateVel.Read();
    m_f27c = m_f21c;
    reinterpret_cast<NiPoint3&>(m_posOrigin) = vfunc_18();    // NiPoint3 move-assign (0x140194470) of the returned temp
    m_n294 = 0;
}

// @0x14118cac0
CDropItem::~CDropItem()
{
    FUN_1403ed280()->FUN_1411a6060(m_nEffectIdA);
    FUN_1403ed280()->FUN_1411a6060(m_nEffectIdB);
}

// Builds the item and the model of the drop; false when the item or its effect row does not exist.
// @0x14118cb90
// MS2-FUNCTIONAL: the exe passes a fifth (ignored) id to GetItemDropEffect that the typed declaration has no slot for
int CDropItem::FUN_14118cb90(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId)
{
    m_nOwnerObjId = nOwnerObjId;
    m_nAmount = nAmount;
    if (!FUN_1411905a0())
        return 0;
    m_spItem = MS2Ptr<CItem>(new CItem());
    if (!m_spItem->FUN_140523c40(nItemId, nRarity, 0))
        return 0;
    Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FUN_141bd1320(m_nOwnerObjId);
    if (pOwner)
    {
        MS2Ptr<CNpcData> spNpc = static_cast<CNpc*>(static_cast<GameObject*>(pOwner))->FUN_141093270();
        m_nNpcType = spNpc->GetId();
    }
    m_str88 = "DropItemNIF";
    FUN_14123c5a0(nObjectId);
    if (!FUN_14053f8c0(nItemId))
    {
        if (!FUN_14053f900(nItemId))
        {
            if (!FUN_14118ffb0())
            {
                m_spEffect = CItemDataTable::GetInstance()->GetDropEffect(1);
                if (m_spEffect == 0)
                    return 0;
                FUN_14123bb80(FUN_140540050("urn:gamebryo-scenegraph:{0}", CItemDataTable::GetInstance()->GetGradeNif((ItemGradeKey)nRarity)));
            }
            else
            {
                m_spEffect = CItemDataTable::GetInstance()->GetDropEffect(2);
                if (m_spEffect == 0)
                    return 0;
                FUN_14123bb80(FUN_140540050("urn:gamebryo-scenegraph:{0}", CItemDataTable::GetInstance()->GetGradePetNif((ItemGradeKey)nRarity)));
            }
        }
        else
        {
            m_spEffect = CItemDataTable::GetInstance()->GetItemDropEffect(nItemId, nAmount);
            if (m_spEffect == 0)
            {
                _wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\dropitem.cpp", 0xb1);
                return 0;
            }
            FUN_14123bb80(FUN_140540050("urn:gamebryo-scenegraph:{0}", m_spEffect->assetName));
            if (nItemId == 0x55d4a89 || nItemId == 0x55d4a8a)
                FUN_141191240();
        }
    }
    else
    {
        m_n64Meso = nAmount;
        m_spEffect = CItemDataTable::GetInstance()->GetItemDropEffect(0x55d4a81, nAmount);
        if (m_spEffect == 0)
            return 0;
        FUN_14123bb80(FUN_140540050("urn:gamebryo-scenegraph:{0}", m_spEffect->assetName));
    }
    return 1;
}

// @0x14118d1c0
int CDropItem::FUN_14118d1c0(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId, const ATL::CAtlList<__int64>& kOwners)
{
    m_owners.FUN_1407b7110(&kOwners);
    return FUN_14118cb90(nObjectId, nItemId, nAmount, nRarity, nOwnerObjId);
}

// @0x14118d230
int CDropItem::FUN_14118d230(int nObjectId, int nItemId, int nAmount, int nRarity, int nOwnerObjId, const ATL::CAtlList<__int64>* pOwners)
{
    if (pOwners)
        m_owners.FUN_1407b7090(pOwners);
    return FUN_14118cb90(nObjectId, nItemId, nAmount, nRarity, nOwnerObjId);
}

// @0x14118d2a0
int CDropItem::vfunc_10()
{
    if (!GameObject::vfunc_10())
        return 0;
    if (!FUN_14118fea0())
    {
        NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
        if (pRoot)
            FUN_14118d720(pRoot);
    }
    if (FUN_14118ffb0())
    {
        bool bValue = false;
        FUN_14098c6e0(FUN_14123c410(), 0x2a7fd9f4, bValue);
        FUN_141851f90(FUN_141b6efc0(FUN_14123c410()), 0);
        float fFrame = (float)FUN_141473280(FUN_14086d260());
        FUN_141b6efc0(FUN_14123c410())->Update(fFrame, true);
        FUN_141852050(FUN_141b6efc0(FUN_14123c410()), 0);
        egf::EntityID kId;
        FUN_141545250(FUN_14123c460(kId), true);
    }
    return 1;
}

// @0x14118d3e0
int CDropItem::vfunc_11()
{
    GameObject::vfunc_11();
    return 1;
}

// @0x14118d410
void CDropItem::vfunc_12()
{
    GameObject::vfunc_12();
}

// @0x14118d430
void CDropItem::vfunc_9(void* p)
{
    GameObject::vfunc_9(p);
    vfunc_21(efd::Point3(0.0f, 0.0f, 0.0f));
    if (m_spEffect.get())
        FUN_14123c300(m_spEffect->scale);
}

// @0x14118d4e0
void CDropItem::vfunc_32(bool bForce)
{
    if (m_spShadow)
    {
        float fDistance = FUN_140f4a450();
        m_spShadow->FUN_14160fe50(fDistance < 200000.0f);
        m_spShadow->FUN_1416105c0();
        bool bMoved = m_spShadow->FUN_14109a720();
        bool bDirty = FUN_141192820(m_spShadow);
        if (bMoved || bForce || bDirty)
        {
            Unk_RayCastInfo kInfo;
            Unk_StreamPoint kNormal(0.0f, 0.0f, 1.0f);
            Unk_StreamPoint kHit(0.0f, 0.0f, 0.0f);
            int nHit = 0;
            if (bMoved)
            {
                if (FUN_141192830(m_spShadow))
                {
                    NiPoint3 kPos = vfunc_18();
                    nHit = FUN_1409f7ca0()->FUN_14168a310(reinterpret_cast<Unk_StreamPoint&>(kPos), kHit, &kInfo, 0.0f, &kNormal, 0);
                }
            }
            m_spShadow->FUN_14160feb0(nHit, reinterpret_cast<efd::Point3&>(kHit), reinterpret_cast<efd::Point3&>(kNormal), kInfo.m_hitDist, bForce);
        }
    }
}

// @0x14118d700
void CDropItem::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
}

// Puts the icon of the dropped item on the "Item_Icon:0" mesh of the model.
// @0x14118d720
void CDropItem::FUN_14118d720(NiAVObject* pRoot)
{
    NiAVObject* pIcon = pRoot->GetObjectByName("Item_Icon:0");
    if (pIcon)
    {
        if (FUN_14109a9a0(reinterpret_cast<const NiRTTI*>(&DAT_143afbbb0), pIcon))
        {
            NiProperty* pProp = pIcon->GetProperty(8);
            NiTexturingProperty* pTexturing = static_cast<NiTexturingProperty*>(FUN_14098d8d0(reinterpret_cast<const NiRTTI*>(&DAT_143afa4f0), pProp));
            if (pTexturing)
            {
                NiTexturingProperty::Map* pMap = FUN_14109a6b0(pTexturing);
                if (pMap)
                {
                    CString strPath = m_spItem->FUN_140528590();
                    if (m_spItem->FUN_140525f10())
                    {
                        if (m_spItem->FUN_140525f60())
                        {
                            if (_access(strPath, 0) != 0)
                                strPath = reinterpret_cast<CItemData*>(m_spItem->FUN_140527840())->FUN_14053fdd0();
                        }
                    }
                    FUN_1401d3700(strPath);
                    if (!strPath.IsEmpty())
                    {
                        NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141552f90(CString(strPath), 5);
                        FUN_140981040(pMap, spTexture);
                    }
                }
            }
        }
    }
}

// Enters a state of the drop: 1 flies out of the source, 0 waits, 2 / 3 / 4 fly to the owner and vanish, 5 grows back.
// @0x14118d9a0
// MS2-FUNCTIONAL: the Point3 temporaries and the Matrix3 chain are laid out differently from the exe
void CDropItem::FUN_14118d9a0(int nState)
{
    if (m_nState == nState)
        return;
    if (m_spEffect == 0)
        return;
    m_fElapsed = 0.0f;
    m_fSpawnTime = 0.0f;
    m_nState = nState;
    if (nState != 1)
    {
        if (nState == 2)
        {
            if (m_nEffectIdA != 0)
                FUN_1403ed280()->FUN_1411a6060(m_nEffectIdA);
            if (m_nEffectIdB != 0)
                FUN_1403ed280()->FUN_1411a6060(m_nEffectIdB);
            Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FUN_141bd1180(m_n278);
            if (!pOwner)
                pOwner = WorldService::GetInstance()->FUN_141bd1180(m_n188);
            if (pOwner)
            {
                NiPoint3 kOwnerPos = pOwner->vfunc_18();
                m_posGround = kOwnerPos;
                NiPoint3 kGoalPos = pOwner->vfunc_18();
                Unk_StreamPoint kGoal(reinterpret_cast<Unk_StreamPoint&>(kGoalPos));
                kGoal.z += m_f218;
                unsigned nHalf = (unsigned)(__int64)m_f224 >> 1;
                int nRandom = FUN_140768010(nHalf, 0);
                m_f224 = (float)(nRandom + nHalf);
                Unk_StreamPoint kGoalCopy(kGoal);
                NiPoint3 kStartPos = pOwner == 0 ? NiPoint3() : vfunc_18();
                Unk_StreamPoint kStart(reinterpret_cast<Unk_StreamPoint&>(kStartPos));
                m_arc.FUN_141479ed0(kStart, kGoalCopy, m_f224, m_f228);
            }
            m_pfnState = &CDropItem::FUN_141191d10;
        }
        else if (nState == 3)
        {
            NiPoint3 kPos = vfunc_18();
            m_arc.m_origin = reinterpret_cast<Unk_StreamPoint&>(kPos);
            egf::EntityID kKey;
            if (FUN_141b6f910()->FUN_140999440(FUN_14123c460(kKey)))
            {
                egf::EntityID kKey2;
                FUN_1409fae00(FUN_141b6f910()->FUN_140999440(FUN_14123c460(kKey2)), true);
            }
            if (!FUN_14118fea0())
            {
                if (reinterpret_cast<Unk_ItemEquipData*>(m_spItem->FUN_140527840())->FUN_14053c5c0() == 3)
                {
                    Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FUN_141bd1180(m_n188);
                    const efd::ClassInfo* pInfo = pOwner ? pOwner->GetClassDesc() : 0;
                    if (FUN_14087ddc0(pInfo, 0x6200004))
                    {
                        Unk_DropPickDlg* pDlg = FUN_140b624b0(0x4e32);
                        if (pDlg)
                            pDlg->FUN_141913060(pOwner, m_spItem->FUN_140526c50(), m_spItem->FUN_140528590());
                    }
                }
            }
            else
            {
                Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FUN_141bd1180(m_n188);
                const efd::ClassInfo* pInfo = pOwner ? pOwner->GetClassDesc() : 0;
                if (FUN_14087ddc0(pInfo, 0x6200004))
                {
                    Unk_DropPickDlg* pDlg = FUN_140b624b0(0x4e32);
                    if (pDlg)
                        pDlg->FUN_141912a80(pOwner, (int)m_n64Meso, 1);
                }
            }
            m_pfnState = &CDropItem::FUN_1411920b0;
        }
        else if (nState == 4)
        {
            m_pfnState = &CDropItem::FUN_141192200;
        }
        else if (nState == 0)
        {
            m_n188 = 0;
            m_pfnState = &CDropItem::FUN_141191a10;
            NiTransform kXform;
            NiPoint3 kPos = vfunc_18();
            MakeXform(kXform, kPos);
            Unk_EffectTarget kTarget;
            kTarget.m_strName = CItemDataTable::GetInstance()->GetGradeEffect((ItemGradeKey)m_spItem->FUN_140526bd0());
            kTarget.m_nKind = 0;
            kTarget.m_pXform = &kXform;
            m_nEffectIdA = FUN_1403ed280()->FUN_1411a49c0(kTarget);
            if (m_spEffect->beEffect.GetLength() != 0)
            {
                Unk_EffectTarget kTargetB;
                kTargetB.m_strName = m_spEffect->beEffect;
                kTargetB.m_nKind = 0;
                kTargetB.m_pXform = &kXform;
                m_nEffectIdB = FUN_1403ed280()->FUN_1411a49c0(kTargetB);
            }
        }
        else if (nState == 5)
        {
            m_fGrow = 0.0f;
            NiPoint3 kPos = vfunc_18();
            m_posGrow = reinterpret_cast<Unk_StreamPoint&>(kPos);
            m_pfnState = &CDropItem::FUN_1411923a0;
        }
    }
    else
    {
        float fDropHeight = 0.0f;
        float fDropSpeed = 100.0f;
        float fDropBase = 50.0f;
        unsigned nDropRange = 100;
        int nMapId = WorldService::GetInstance()->FUN_141bd3060();
        if (nMapId == 0x4c4b404 || WorldService::GetInstance()->FUN_141bd3060() == 0x4c4b407)
        {
            fDropHeight = Client::Constants::GetInstance()->moneyTreeDropHeight.Read();
            fDropBase = Client::Constants::GetInstance()->moneyTreeDropBase.Read();
            nDropRange = *Client::Constants::GetInstance()->moneyTreeDropRandom.Get();
        }
        if (m_nNpcType == 0)
        {
            if (m_nDropKind == 0x21)
            {
                NiPoint3 kSelfPos = vfunc_18();
                MS2Ptr<Unk_WsB_Prop> spProp = WorldService::GetInstance()->FUN_141bc6090(reinterpret_cast<Unk_StreamPoint&>(kSelfPos), 0);
                Unk_WsB_Prop* pProp = spProp.get();
                bool bProp = false;
                if (pProp)
                    bProp = pProp->FUN_140966e00().get() != 0;
                if (bProp)
                {
                    if (pProp->FUN_140966e00()->m_drop.m_nDropHeight != 0)
                        fDropHeight = (float)pProp->FUN_140966e00()->m_drop.m_nDropHeight;
                    if (pProp->FUN_140966e00()->m_drop.m_nDropDistance != 0)
                        fDropBase = (float)pProp->FUN_140966e00()->m_drop.m_nDropDistance;
                }
            }
        }
        else
        {
            MS2Ptr<CNpcData> spNpc = FUN_1406cd330(m_nNpcType);
            fDropHeight = spNpc->m_drop.m_fDropHeight;
            if (spNpc->m_drop.m_fDropDistanceBase != 0.0f)
                fDropBase = spNpc->m_drop.m_fDropDistanceBase;
            if (spNpc->m_drop.m_nDropDistanceRandom != 0)
                nDropRange = spNpc->m_drop.m_nDropDistanceRandom;
            fDropSpeed = spNpc->m_drop.m_fFireVelocity;
        }
        NiPoint3 kSelfPos = vfunc_18();
        Unk_StreamPoint kSelf(reinterpret_cast<Unk_StreamPoint&>(kSelfPos));
        m_posOrigin = kSelf.FUN_140965c40(Unk_StreamPoint(0.0f, 0.0f, 70.0f));
        kSelf.z += fDropHeight;
        if (FUN_14118ffb0())
        {
            kSelf = m_posOrigin;
            if (m_n298 != 0)
            {
                Unk_EffectTarget kTarget;
                kTarget.m_strName = *FUN_140298f80(&Client::Constants::GetInstance()->PetTrapDropItemEffect);
                kTarget.m_nKind = 0;
                kTarget.FUN_140a53190(FUN_14123c580());
                FUN_1403ed280()->FUN_1411a4a00(kTarget);
                int nNow = FUN_140869420();
                m_nFadeTime = nNow + *Client::Constants::GetInstance()->PetTrapDropVisibleDelay.Get();
                vfunc_23(1);
            }
        }
        if (m_nFadeTime == 0 && m_spShadow)
        {
            m_spShadow->FUN_14160fe10(true);
            vfunc_32(true);
        }
        vfunc_19(reinterpret_cast<efd::Point3&>(kSelf));
        NiPoint3 kBasePos = vfunc_18();
        Unk_StreamPoint kBase(reinterpret_cast<Unk_StreamPoint&>(kBasePos));
        kBase.z += 85.0f;
        int nObjectId = FUN_14123c580();
        Unk_Random kRand(nObjectId, nObjectId + 0x7fff, nObjectId * 0x7fff);
        NiPoint3 kTargetPos;
        Unk_WsC_GameObj* pSource = WorldService::GetInstance()->FUN_141bd1290(m_nOwnerObjId);
        Unk_WsC_GameObj* pNpcObj = WorldService::GetInstance()->FUN_141bd1320(m_nOwnerObjId);
        if (m_n28c == 0)
        {
            if (!pSource || !FUN_14118fea0())
            {
                if (!pNpcObj || !FUN_14118ff60())
                {
                    efd::Matrix3 kRot;
                    kRot.MakeZRotation(((float)(kRand.FUN_1407684c0() % 0x168) * 3.1415927f) / 180.0f);
                    efd::Point3 kDirection = efd::Point3::UNIT_Y * kRot;
                    Unk_StreamPoint kDir(reinterpret_cast<Unk_StreamPoint&>(kDirection));
                    float fDistance = fDropBase + (float)(kRand.FUN_1407684c0() % nDropRange);
                    Unk_StreamPoint kTarget = kBase.FUN_14097fd50(kDir.FUN_14097fc90(fDistance));
                    kTargetPos = reinterpret_cast<NiPoint3&>(kTarget);
                    m_f27c = FUN_140966f00(m_posOrigin, reinterpret_cast<Unk_StreamPoint&>(kTargetPos));
                }
                else
                {
                    unsigned __int64 nOwnerUid = FUN_1411910e0();
                    Unk_WsC_GameObj* pOwnerPc = WorldService::GetInstance()->FUN_141bd1530(nOwnerUid);
                    Unk_GoAttachment* pAttach = pNpcObj->vfunc_26();
                    bool bBox = false;
                    if (pAttach)
                    {
                        MS2Ptr<CNpcData> spNpc = static_cast<CNpc*>(static_cast<GameObject*>(pNpcObj))->FUN_141093270();
                        if (FUN_140184310(spNpc->m_collision.m_strShape, "box") && pOwnerPc)
                            bBox = true;
                    }
                    if (bBox)
                    {
                        kBase = pAttach->m_pos;
                        vfunc_19(reinterpret_cast<efd::Point3&>(kBase));
                        float fDistance = fDropBase + (float)(kRand.FUN_1407684c0() % nDropRange);
                        m_f27c = FUN_140966f00(m_posOrigin, reinterpret_cast<Unk_StreamPoint&>(kTargetPos));
                        NiPoint3 kOwnerPos = pOwnerPc->vfunc_18();
                        Unk_StreamPoint kDir = FUN_141192780(kBase, reinterpret_cast<Unk_StreamPoint&>(kOwnerPos), true);
                        if (kDir.FUN_140552690(DAT_143b01a60))
                        {
                            kDir.y = ((float)(kRand.FUN_1407684c0() % 0x168) * 3.1415927f) / 180.0f + 1.0f;
                            kDir.FUN_140968990();
                        }
                        Unk_StreamPoint kTarget = kBase.FUN_14097fd50(kDir.FUN_14097fc90(fDistance));
                        kTargetPos = reinterpret_cast<NiPoint3&>(kTarget);
                    }
                }
            }
            else
            {
                Unk_StreamPoint kForward, kSide;
                pSource->vfunc_67(&kForward, &kSide);
                kForward.z = 0.0f;
                Unk_StreamPoint kTarget = kBase.FUN_140965c40(kForward.FUN_14097fc90(50.0f));
                kTargetPos = reinterpret_cast<NiPoint3&>(kTarget);
            }
        }
        else
        {
            NiPoint3 kSelfNow = vfunc_18();
            Unk_StreamPoint kTarget = reinterpret_cast<Unk_StreamPoint&>(kSelfNow).FUN_14097fd50(DAT_143a08d08);
            kTargetPos = reinterpret_cast<NiPoint3&>(kTarget);
        }
        NxGroupsMask kMask;
        kMask.bits0 = 0xffffffff;
        kMask.bits1 = 0;
        kMask.bits2 = 0;
        kMask.bits3 = 0;
        NiPoint3 kHit;
        float fGravity = -15.0f - (float)(kRand.FUN_1407684c0() % 0x19);
        float fProbe = fDropHeight + 85.0f + 100.0f;
        if (!FUN_14147a500(&reinterpret_cast<Unk_StreamPoint&>(kHit), &kBase, &reinterpret_cast<Unk_StreamPoint&>(kTargetPos), 1, fProbe, &kMask))
        {
            Unk_RayCastInfo kInfo;
            kInfo.m_origin = kBase;
            kInfo.m_dir = DAT_143a08cf8.FUN_1409f7960();
            kInfo.m_maxDist = 0.0f;
            kInfo.m_groups = 0x389;
            if (!FUN_1409f7ca0()->CastRay(&kInfo, &kMask))
            {
                int nFound = 0;
                float aSideX[4] = { 1.0f, -1.0f, -1.0f, 1.0f };
                float aSideY[4] = { 1.0f, 1.0f, -1.0f, -1.0f };
                for (int i = 0; i < 4; ++i)
                {
                    Unk_StreamPoint kSide;
                    kSide.x = aSideX[i];
                    kSide.y = aSideY[i];
                    kSide.FUN_140968990();
                    NxGroupsMask kMaskSide;
                    kMaskSide.bits0 = 0xffffffff;
                    kMaskSide.bits1 = 0;
                    kMaskSide.bits2 = 0;
                    kMaskSide.bits3 = 0;
                    Unk_RayCastInfo kInfoSide;
                    Unk_StreamPoint kOffset = kSide.FUN_14097fc90(150.0f).FUN_14097fc90(0.5f);
                    NiPoint3 kHere = vfunc_18();
                    kInfoSide.m_origin = reinterpret_cast<Unk_StreamPoint&>(kHere).FUN_14097fd50(kOffset);
                    kInfoSide.m_dir = DAT_143a08cf8.FUN_1409f7960();
                    kInfoSide.m_maxDist = 0.0f;
                    kInfoSide.m_groups = 0x389;
                    if (!FUN_1409f7ca0()->CastRay(&kInfoSide, &kMaskSide))
                        continue;
                    reinterpret_cast<Unk_StreamPoint&>(kHit) = kInfoSide.m_hitPoint;
                    kHit.z += m_spEffect->unknown1c;
                    NiPoint3 kStartPos = vfunc_18();
                    m_arc.FUN_141479ed0(reinterpret_cast<Unk_StreamPoint&>(kStartPos), reinterpret_cast<Unk_StreamPoint&>(kHit), fDropSpeed, fGravity);
                    nFound = 1;
                    break;
                }
                if (nFound == 0)
                {
                    NiPoint3 kHere = vfunc_18();
                    m_arc.m_origin = reinterpret_cast<Unk_StreamPoint&>(kHere);
                    m_arc.m_direction = DAT_143b01a60;
                    NiPoint3 kHere2 = vfunc_18();
                    m_arc.m_target = reinterpret_cast<Unk_StreamPoint&>(kHere2);
                    m_arc.m_gravity = -9.8f;
                    m_arc.m_flightScale = 0.0f;
                    m_arc.m_angle.m_cos = 0.0f;
                    m_arc.m_angle.m_sin = 0.0f;
                    m_arc.m_speed = fDropSpeed;
                    m_pfnState = &CDropItem::FUN_141191a10;
                    m_nState = 0;
                    return;
                }
            }
            else
            {
                reinterpret_cast<Unk_StreamPoint&>(kHit) = kInfo.m_hitPoint;
                kHit.z += m_spEffect->unknown1c;
                NiPoint3 kHere = vfunc_18();
                m_arc.m_origin = reinterpret_cast<Unk_StreamPoint&>(kHere);
                m_arc.m_direction = DAT_143b01a60;
                m_arc.m_target = reinterpret_cast<Unk_StreamPoint&>(kHit);
                m_arc.m_gravity = -9.8f;
                m_arc.m_flightScale = 5.0f;
                m_arc.m_angle.m_cos = 0.0f;
                m_arc.m_angle.m_sin = 0.0f;
                m_arc.m_speed = fDropSpeed;
            }
        }
        else
        {
            kHit.z += m_spEffect->unknown1c;
            NiPoint3 kStartPos = vfunc_18();
            m_arc.FUN_141479ed0(reinterpret_cast<Unk_StreamPoint&>(kStartPos), reinterpret_cast<Unk_StreamPoint&>(kHit), fDropSpeed, fGravity);
        }
        if (250.0f < m_arc.m_target.z - m_posOrigin.z)
        {
            m_arc.m_target = m_posOrigin;
            m_arc.m_target.z += 85.0f;
        }
        if (m_spItem.get())
        {
            NiTransform kXform;
            NiPoint3 kPos = vfunc_18();
            MakeXform(kXform, kPos);
            int nKind = WorldService::GetInstance()->FUN_141bd19d0(m_nOwnerObjId);
            CString strSound = m_spEffect->dropSoundID;
            if (!strSound.IsEmpty())
                FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), CString(strSound), CString(""), nKind, &kXform, 1.0f, 0);
        }
        m_pfnState = &CDropItem::FUN_141191780;
    }
    if (!FUN_1411905a0())
    {
        static float s_fAlpha = Client::Constants::GetInstance()->DefaultDropItemAlpha.Read();
        vfunc_42(s_fAlpha, false);
    }
}

// @0x14118fe60
void CDropItem::FUN_14118fe60(int nValue) { m_n28c = nValue; }

// @0x14118fe80
void CDropItem::FUN_14118fe80(int nValue) { m_n298 = nValue; }

// @0x14118fea0
int CDropItem::FUN_14118fea0() { return 0 < m_n64Meso; }

// @0x14118fee0
int CDropItem::FUN_14118fee0() { return m_spItem->FUN_140525920(); }

// @0x14118ff10
int CDropItem::FUN_14118ff10() { return m_spItem->FUN_1405276c0() == 0x55d4a8a; }

// @0x14118ff60
int CDropItem::FUN_14118ff60() { return m_spItem->FUN_1405276c0() == 0x55d4a83; }

// @0x14118ffb0
int CDropItem::FUN_14118ffb0()
{
    return (m_spItem.get() ? true : false) && m_spItem->FUN_140525640();
}

// @0x141190030
int CDropItem::FUN_141190030()
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer)
    {
        unsigned __int64 nUid = static_cast<PCBase*>(pPlayer)->FUN_141656a80();
        return FUN_141190080(nUid);
    }
    return 0;
}

// @0x141190080
int CDropItem::FUN_141190080(unsigned __int64 nUid)
{
    if (m_owners.FUN_1407b72d0(nUid, 0))
        return 1;
    return 0;
}

// @0x1411900d0
int CDropItem::FUN_1411900d0()
{
    return m_n188 != 0 && m_nState != 0;
}

// Whether the player at kPos may pick the drop up (in range, off the pickup throttle, owner rules).
// @0x141190120
int CDropItem::FUN_141190120(const efd::Point3& kPos, int nA, int nB)
{
    if (!s_kPickTimer.FUN_140868c00() && nA)
        return 0;
    if (!FUN_1411900d0() || !nA)
    {
        if (!m_nState || !nA)
        {
            if (!FUN_141191060())
                return 0;
            if (FUN_140869420() < m_n294)
                return 0;
            if (FUN_1409331e0()->FUN_14138c900(7))
                return 0;
            Unk_StreamPoint kPlayer(reinterpret_cast<const Unk_StreamPoint&>(kPos));
            NiPoint3 kSelf = vfunc_18();
            Unk_StreamPoint kDelta = kPlayer.FUN_140965c40(reinterpret_cast<Unk_StreamPoint&>(kSelf));
            float fDistance = kDelta.FUN_140967ac0();
            kPlayer.z += m_f218;
            float fRange = m_f21c;
            if (m_f27c > m_f21c)
                fRange = m_f27c;
            if (fDistance <= fRange)
            {
                if (!nB)
                {
                    bool bAllowed = false;
                    if (m_nOwnerType == 2)
                        bAllowed = true;
                    else if (m_nOwnerType == 0 || m_nOwnerType == 1)
                    {
                        if (FUN_141190030() == 1)
                            bAllowed = true;
                    }
                    if (!bAllowed)
                        return 0;
                }
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

// @0x141190320
int CDropItem::FUN_141190320(GameObject* pActor, int nA, int nB)
{
    return FUN_1411903c0(pActor, m_f21c, nA, nB);
}

// @0x141190370
int CDropItem::FUN_141190370(GameObject* pActor, int nA, int nB)
{
    return FUN_1411903c0(pActor, m_f220, nA, nB);
}

// @0x1411903c0
int CDropItem::FUN_1411903c0(GameObject* pActor, float fRange, int nA, int nB)
{
    if (!pActor)
        return 0;
    if (!s_kPickTimer.FUN_140868c00() && nA)
        return 0;
    if (!FUN_1411900d0() || !nA)
    {
        if (!m_nState || !nA)
        {
            if (!FUN_141191060())
                return 0;
            if (FUN_140869420() < m_n294)
                return 0;
            if (FUN_1409331e0()->FUN_14138c900(7))
                return 0;
            NiPoint3 kActor = pActor->vfunc_18();
            Unk_StreamPoint kPlayer(reinterpret_cast<Unk_StreamPoint&>(kActor));
            NiPoint3 kSelf = vfunc_18();
            Unk_StreamPoint kDelta = kPlayer.FUN_140965c40(reinterpret_cast<Unk_StreamPoint&>(kSelf));
            float fDistance = kDelta.FUN_140967ac0();
            kPlayer.z += m_f218;
            if (fDistance <= fRange)
            {
                if (!nB)
                {
                    bool bAllowed = false;
                    if (m_nOwnerType == 2)
                        bAllowed = true;
                    else if (m_nOwnerType == 0 || m_nOwnerType == 1)
                    {
                        if (FUN_141190030() == 1)
                            bAllowed = true;
                    }
                    if (!bAllowed)
                        return 0;
                }
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

// @0x1411905a0
int CDropItem::FUN_1411905a0()
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    int bAllowed = 0;
    if (m_nOwnerType == 2)
        bAllowed = 1;
    else if (m_nOwnerType == 0 || m_nOwnerType == 1)
    {
        if (FUN_141190030() == 1)
            bAllowed = 1;
    }
    if (bAllowed == 0)
        return 0;
    return 1;
}

// @0x141190640
int CDropItem::FUN_141190640(bool bForce)
{
    int bInBag = DAT_143ab2a90.FUN_140a615d0(0);
    if (bInBag == 0 && FUN_1411906a0() == 0 && bForce == 0)
        return 0;
    return 1;
}

// @0x1411906a0
int CDropItem::FUN_1411906a0()
{
    if (m_spItem->FUN_1405257f0())
    {
        ATL::CAtlList<MS2Ptr<CItem> > kHave(10);
        DAT_143ab2a90.FUN_140a5e8d0(m_spItem->FUN_1405276c0(), kHave, 1);
        POSITION pos = kHave.GetHeadPosition();
        while (pos)
        {
            MS2Ptr<CItem> spHave = kHave.GetNext(pos);
            if (spHave.get())
            {
                unsigned nMax = spHave->FUN_1405281e0();
                int nHave = spHave->FUN_140526c50();
                int nMine = m_spItem->FUN_140526c50();
                if ((unsigned)(nHave + nMine) <= nMax)
                    return 1;
            }
        }
    }
    return 0;
}

// @0x141190830
void CDropItem::FUN_141190830(int nPickerId)
{
    FUN_141192840(1);
    FUN_141191030();
    COutPacket kPacket(0x1c, 0);
    kPacket.Encode4(FUN_14123c580());
    kPacket.COutPacket::vfunc_o10_0(nPickerId != 0);
    if (nPickerId != 0)
        kPacket.Encode4(nPickerId);
    FUN_140710590(kPacket);
}

// Asks the server to pick the drop up, with the inventory and block checks first.
// @0x141190900
void CDropItem::FUN_141190900(int nPickerId)
{
    if (!FUN_1411900d0())
    {
        if (!m_spItem->FUN_140525980())
        {
            if (!FUN_14053f900(m_spItem->FUN_1405276c0()))
            {
                BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0x13);
                if (spBlock.get())
                {
                    static Unk_DropPickTick s_kNoticeTick;
                    if (s_kNoticeTick.FUN_140268870(5000) == 1)
                        FUN_1412751b0(FUN_1401ca400(spBlock, 0x20), 0x14);
                    FUN_1411911a0();
                    return;
                }
                if (DAT_143ab2a90.FUN_140a61430(DAT_143ab2a90.FUN_140a617f0(m_spItem)))
                {
                    FUN_141190830(nPickerId);
                    return;
                }
                if (!FUN_1411906a0())
                {
                    FUN_141275260(0x43, 1, 1);
                    FUN_141276180(s_strWarningBag, CString(""));
                    FUN_1411911a0();
                }
                FUN_141190830(nPickerId);
                return;
            }
        }
        FUN_141190830(nPickerId);
    }
}

// The drop was picked up by the actor nPickerId: sound, pickup notices, then the fly-to-owner state.
// @0x141190b70
void CDropItem::FUN_141190b70(int nPickerId)
{
    GameObject* pPicker = FUN_14096e160(WorldService::GetInstance()->FUN_141bd1200(nPickerId));
    if (pPicker)
    {
        bool bHasItem = m_spItem.get() != 0;
        if (bHasItem)
        {
            bool bHasEffect = m_spEffect.get() != 0;
            if (bHasEffect)
            {
                NiTransform kXform;
                NiPoint3 kPos = pPicker->vfunc_18();
                MakeXform(kXform, kPos);
                CString strSound = m_spEffect->getSoundID;
                if (!strSound.IsEmpty())
                    FUN_1403ed280()->FUN_1411a5110(CString("ms2sound/sound/item"), CString(strSound), CString(""), 1, &kXform, 1.0f, 0);
                if (0 < m_spItem->FUN_140526bd0())
                {
                    if (m_spItem->FUN_1405258f0() == 0)
                    {
                        if (m_spItem->FUN_140525950() == 0 && FUN_14118fee0() == 0)
                        {
                            Unk_DropBagDlg* pBag = FUN_140938cd0(0x4e5d);
                            if (pBag)
                                pBag->FUN_141abfa10(m_spItem);
                        }
                    }
                }
            }
        }
        if (m_spItem->FUN_140528980())
            FUN_1409331e0()->FUN_14138bf00(0xc, m_spItem->FUN_1405276c0(), 0);
    }
    if (m_nState == 6)
    {
        vfunc_23(0);
        if (m_spShadow)
        {
            m_spShadow->FUN_14160fe10(true);
            vfunc_32(true);
        }
    }
    if (m_nState == 0)
    {
        m_n188 = nPickerId;
        s_kPickTimer.FUN_140868750(0x96);
        FUN_14118d9a0(2);
    }
}

// @0x141191030
void CDropItem::FUN_141191030() { m_nTick = FUN_140869420(); }

// @0x141191060
bool CDropItem::FUN_141191060()
{
    unsigned int nNow = FUN_140869420();
    if (m_nTick + 1000 > nNow)
        return false;
    return true;
}

// @0x1411910a0
int CDropItem::FUN_1411910a0() { return m_nOwnerObjId; }

// @0x1411910c0
int CDropItem::FUN_1411910c0() { return m_nDropKind; }

// @0x1411910e0
unsigned __int64 CDropItem::FUN_1411910e0()
{
    if (!m_owners.FUN_1408f32a0())
        return 0;
    void* pPos = m_owners.FUN_1407b75d0();
    unsigned __int64 nUid = *m_owners.FUN_1408f31c0(pPos);
    return nUid;
}

// @0x141191150
int CDropItem::FUN_141191150()
{
    return m_nState == 1 || m_nState == 6;
}

// @0x1411911a0
void CDropItem::FUN_1411911a0() { FUN_14118d9a0(5); }

// @0x1411911d0
void CDropItem::vfunc_47(bool b) { m_bUnk138 = false; }

// @0x1411911f0
void CDropItem::FUN_1411911f0()
{
    if (!FUN_14118fea0())
    {
        NiAVObject* pRoot = FUN_141b6efc0(FUN_14123c410());
        if (pRoot)
            FUN_14118d720(pRoot);
    }
}

// The pet-ball (SPEP) drops use their own settings.
// @0x141191240
void CDropItem::FUN_141191240()
{
    m_f218 = Client::Constants::GetInstance()->DropSPEPBallTargetZPos.Read();
    m_f21c = Client::Constants::GetInstance()->DropSPEPBallMaxLength.Read();
    m_f224 = Client::Constants::GetInstance()->DropSPEPBallPickUpVel.Read();
    m_f228 = Client::Constants::GetInstance()->DropSPEPBallPickUpGravity.Read();
    m_f22c = Client::Constants::GetInstance()->DropSPEPBallPickUpCompleteRotateTime.Read();
    m_f230 = Client::Constants::GetInstance()->DropSPEPBallPickUpCompleteRotateVel.Read();
    m_f27c = m_f21c;
}

// @0x141191330
void CDropItem::FUN_141191330(int nValue) { m_n278 = nValue; }

// @0x141191350
void CDropItem::vfunc_49()
{
    float fScale = 100.0f;
    float fBias = 5.0f;
    if (m_spItem.get())
    {
        fScale = m_spEffect->shadowScale;
        fBias = m_spEffect->shadowBias;
    }
    Unk_DropShadowCfg* pCfg = FUN_140ae1c00();
    int nLodHi = pCfg->FUN_141376880(4);
    int nLodLo = pCfg->FUN_1413769d0(4);
    m_spShadow = NiNew CObjectShadow(this, nLodHi, nLodLo, fScale, fBias);
    m_spShadow->FUN_14160fe10(false);
}

// @0x1411914d0
void CDropItem::vfunc_53(float fTime)
{
    GameObject::vfunc_53(fTime);
    if (m_nFadeTime != 0 && m_nFadeTime < FUN_140869420())
    {
        vfunc_23(0);
        if (m_spShadow)
        {
            m_spShadow->FUN_14160fe10(true);
            vfunc_32(true);
        }
    }
    if (m_nDropKind == 0xc80 && !FUN_14118ffb0() && m_n298 != 0)
    {
        if (m_nFadeTime == 0)
        {
            unsigned int nNow = FUN_140869420();
            m_nFadeTime = nNow + *Client::Constants::GetInstance()->PetTrapDropVisibleDelay.Get();
            vfunc_23(1);
            return;
        }
        else if (m_nFadeTime > FUN_140869420())
            return;
    }
    if (m_nState == 6)
    {
        vfunc_23(0);
        FUN_14118d9a0(1);
    }
    Unk_WsC_GameObj* pOwner = WorldService::GetInstance()->FUN_141bd1180(m_n188);
    if (!FUN_1411900d0() || pOwner)
    {
        if (m_pfnState)
        {
            GameObject* pTarget = WorldService::GetInstance()->FUN_141bd1180(m_n278);
            if (!pTarget)
                pTarget = pOwner;
            m_fSpawnTime += fTime;
            (this->*m_pfnState)(fTime, pTarget);
        }
    }
    else
        WorldService::GetInstance()->FUN_141bbb7f0(this, 0);
}

// State 1: flies out of the source along the arc.
// @0x141191780
void CDropItem::FUN_141191780(double fTime, GameObject* pTarget)
{
    if (m_fElapsed <= m_arc.m_flightScale)
    {
        m_fElapsed += (float)fTime * 10.0f;
        Unk_StreamPoint kOffset = FUN_1409ab5c0(m_arc.m_speed * m_arc.m_angle.m_cos * m_fElapsed, m_arc.m_direction);
        kOffset.z = m_arc.m_gravity * 0.5f * m_fElapsed * m_fElapsed + m_arc.m_speed * m_arc.m_angle.m_sin * m_fElapsed;
        Unk_StreamPoint kPos = m_arc.m_origin.FUN_14097fd50(kOffset);
        vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
        if (m_spItem.get())
            FUN_1411925e0(m_spEffect->dropAni, m_spEffect->dropAniSpeed);
    }
    else
    {
        FUN_14118d9a0(0);
        Unk_StreamPoint kTarget = m_arc.m_target;
        vfunc_19(reinterpret_cast<efd::Point3&>(kTarget));
    }
}

// State 0: waits on the ground and bobs.
// @0x141191a10
void CDropItem::FUN_141191a10(double fTime, GameObject* pTarget)
{
    if (m_spItem.get())
    {
        if (m_spItem->FUN_140527840())
        {
            m_fElapsed += (float)fTime;
            if (0.0f < m_spEffect->bouncePeriod)
            {
                if (m_spEffect->bouncePeriod < m_fElapsed)
                    m_fElapsed = 0.0f;
                float fSin = sinf((m_fElapsed * 3.1415927f * 2.0f) / m_spEffect->bouncePeriod);
                Unk_StreamPoint kOffset(0.0f, 0.0f, m_spEffect->bounceHeight * fSin * -1.0f * 0.5f);
                Unk_StreamPoint kPos = m_arc.m_target.FUN_14097fd50(kOffset);
                vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
            }
            NiPoint3 kSelf = vfunc_18();
            Unk_StreamPoint kHere(reinterpret_cast<Unk_StreamPoint&>(kSelf));
            Unk_StreamPoint kOrigin(m_posOrigin);
            m_f27c = FUN_140966f00(kOrigin, kHere) + 10.0f;
        }
    }
    if (m_spItem.get())
        FUN_1411925e0(m_spEffect->beAni, m_spEffect->beAniSpeed);
}

// State 2: flies to the owner who picked it up.
// @0x141191d10
void CDropItem::FUN_141191d10(double fTime, GameObject* pTarget)
{
    NiPoint3 kTargetPos = pTarget->vfunc_18();
    Unk_StreamPoint kGoal(reinterpret_cast<Unk_StreamPoint&>(kTargetPos));
    kGoal.z += m_f218;
    if (m_fElapsed <= m_arc.m_flightScale)
    {
        m_fElapsed += (float)fTime * 10.0f;
        NiPoint3 kNow = pTarget->vfunc_18();
        Unk_StreamPoint kTo(reinterpret_cast<Unk_StreamPoint&>(kNow));
        Unk_StreamPoint kFrom(m_arc.m_origin);
        Unk_StreamPoint kDir = FUN_141192780(kFrom, kTo, true);
        Unk_StreamPoint kDirCopy(kDir);
        Unk_StreamPoint kOffset = FUN_1409ab5c0(m_arc.m_speed * m_arc.m_angle.m_cos * m_fElapsed, m_arc.m_direction);
        kOffset.z = m_arc.m_gravity * 0.5f * m_fElapsed * m_fElapsed + m_arc.m_speed * m_arc.m_angle.m_sin * m_fElapsed;
        NiPoint3 kPull = pTarget->vfunc_18();
        Unk_StreamPoint kDrift(reinterpret_cast<Unk_StreamPoint&>(kPull).FUN_140965c40(reinterpret_cast<Unk_StreamPoint&>(m_posGround)));
        kOffset.FUN_140a4e560(kDrift);
        Unk_StreamPoint kPos = m_arc.m_origin.FUN_14097fd50(kOffset);
        vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
        if (m_spItem.get())
            FUN_1411925e0(m_spEffect->getAni, m_spEffect->getAniSpeed);
    }
    else
        FUN_14118d9a0(3);
}

// State 3: hovers over the owner for the rotate time.
// @0x1411920b0
void CDropItem::FUN_1411920b0(double fTime, GameObject* pTarget)
{
    m_fElapsed += (float)fTime;
    if (m_fElapsed > m_f22c)
        FUN_14118d9a0(4);
    else
    {
        NiPoint3 kPos = pTarget->vfunc_18();
        kPos.z += m_f218;
        vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
        FUN_1411925e0(efd::Point3(0.0f, 0.0f, 1.0f), m_f230);
    }
}

// State 4: sinks away, then the drop is destroyed.
// @0x141192200
void CDropItem::FUN_141192200(double fTime, GameObject* pTarget)
{
    NiPoint3 kSelf = vfunc_18();
    NiPoint3 kTargetPos = pTarget->vfunc_18();
    Unk_StreamPoint kDelta = reinterpret_cast<Unk_StreamPoint&>(kTargetPos).FUN_140965c40(reinterpret_cast<Unk_StreamPoint&>(kSelf));
    if (100.0f <= kDelta.FUN_140967ac0() && kDelta.FUN_140967ac0() <= 300.0f)
    {
        NiPoint3 kAgain = pTarget->vfunc_18();
        Unk_StreamPoint kPos(reinterpret_cast<Unk_StreamPoint&>(kAgain));
        NiPoint3 kHere = vfunc_18();
        kPos.z = kHere.z - (float)fTime * 1000.0f;
        vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
        return;
    }
    WorldService::GetInstance()->FUN_141bbb7f0(this, 0);
}

// State 5: grows back in after a failed pickup.
// @0x1411923a0
void CDropItem::FUN_1411923a0(double fTime, GameObject* pTarget)
{
    m_fGrow = m_fGrow + fTime;
    static float s_fFailTime = Client::Constants::GetInstance()->DropItemPickFailTime.Read();
    static float s_fFailHeight = Client::Constants::GetInstance()->DropItemPickFailHeight.Read();
    float fRatio = m_fGrow / s_fFailTime;
    if (fRatio < 1.0f)
    {
        float fSin = sinf(fRatio * 3.1415927f);
        Unk_StreamPoint kOffset(0.0f, 0.0f, fSin * s_fFailHeight);
        Unk_StreamPoint kPos = m_posGrow.FUN_14097fd50(kOffset);
        vfunc_19(reinterpret_cast<efd::Point3&>(kPos));
    }
    else
    {
        m_fGrow = 0.0f;
        m_nState = 0;
        m_pfnState = &CDropItem::FUN_141191a10;
    }
}

// Spins the model by fDegrees around kAxis.
// @0x1411925e0
void CDropItem::FUN_1411925e0(efd::Point3 kAxis, float fDegrees)
{
    if (FUN_14118ffb0())
        return;
    Unk_StreamPoint kRot = reinterpret_cast<Unk_StreamPoint&>(kAxis).FUN_14097fc90(fDegrees).FUN_14097fc90(360.0f).FUN_14097fc90(m_fSpawnTime);
    vfunc_21(reinterpret_cast<efd::Point3&>(kRot));
}

// @0x141192840
void CDropItem::FUN_141192840(int nValue) { m_n294 = nValue; }
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caca70-0x142cacb40 .text$yd
