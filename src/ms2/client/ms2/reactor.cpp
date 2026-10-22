// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See reactor.h.
// MS2-UNIT: client\ms2\reactor.cpp
// MS2-RANGE: 0x140b788d0-0x140b7edf0 .text$mn
// MS2-RANGE: 0x1400c8d80-0x1400c90a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$allocator@UUnk_Int3@@@std@@QEAA@XZ 0x140b7c690 ; prop
// MS2-PIN: ??C?$MS2Ptr@VReactorCondition@@@@QEBAPEAVReactorCondition@@XZ 0x140b7c970 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@V?$MS2Ptr@VReactorStateData@@@@V?$CElementTraits@V?$MS2Ptr@VReactorStateData@@@@@ATL@@@ATL@@QEBA_KXZ 0x140b7cc40 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@UUnk_Int3@@@std@@V?$_Vector_val@U?$_Simple_types@UUnk_Int3@@@std@@@2@$00@std@@QEAAAEAV?$allocator@UUnk_Int3@@@2@XZ 0x140b7e790 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@UUnk_Int3@@@std@@V?$_Vector_val@U?$_Simple_types@UUnk_Int3@@@std@@@2@$00@std@@QEBAAEBV?$allocator@UUnk_Int3@@@2@XZ 0x140b7e7a0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@UUnk_Int3@@V?$allocator@UUnk_Int3@@@std@@@std@@@std@@QEBAAEBV?$allocator@UUnk_Int3@@@2@XZ 0x140b7e7f0 ; unique
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@UUnk_Int3@@V?$allocator@UUnk_Int3@@@std@@@std@@@std@@QEBAAEBQEAUUnk_Int3@@XZ 0x140b7e880 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetClassDesc@CReactor@@UEBAPEBVClassInfo@efd@@XZ 0x140b7cc30
// MS2-PIN: ?TypeCast@CReactor@@UEBA_NIPEAPEAX@Z 0x140b7e4d0
// MS2-PIN: ?TypeCast@CReactor@@UEBA_NIPEAPEBX@Z 0x140b7e520
// MS2-PIN: ??_7CReactor@@6BIBase@efd@@@ 0x142de2ea0
// MS2-PIN: ??_7CReactor@@6BCallbackObject@NiActorManager@@@ 0x142de3070
// MS2-PIN: ??_ECReactor@@W7EAAPEAXI@Z 0x140b7c980
// MS2-PIN: ??_GCReactor@@UEAAPEAXI@Z 0x140b7c9d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\reactor.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "reactor.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/animationmanager.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <algorithm>
#include <vector>
#include <efd/Point3.h>

// The ClassInfo initializer is the first dynamic initializer of the object, ahead of the shared header statics.
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CReactor);

#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/reactor_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION

// The object holds two copies of the header's static data (the second without the extra handle).
namespace Unk_ReactorStatics {
static CString sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString skill = "skill";
static CString stun = "stun";
static Unk_1402a9d70 condition(17, 0.75f, 0.25f, 2.25f, 10);
}

// ---- unit-local placeholders and externals ----

// Effect play request (0x78 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0) and its transform; as in interactobject.cpp.
struct Unk_RxXform
{
    Unk_EfdMatrix3 m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_RxXform, 0x34);
void* FUN_140a332d0(Unk_RxXform* p);
void FUN_14097faa0(float* pDst, const Unk_NiPoint3* pSrc);
Unk_NiPoint3 FUN_14027dcf0(const Vector3& pt);          // NiPoint3(const efd::Point3&)
struct Unk_RxFxRequest
{
    CString m_strName;
    int m_nOwnerId;
    int m_pad_0c;
    void* m_pSlot10;
    Unk_RxXform* m_pXform;
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_RxFxRequest, 0x78);
class Unk_RxFxMgr
{
public:
    int FUN_1411a49c0(Unk_RxFxRequest* pRequest);               // plays the effect, returns its handle
    void FUN_1411a6060(int nHandle);                            // stops it
};
Unk_RxFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_RxFxRequest* p);
void FUN_1405a89e0(Unk_RxFxRequest* p);
#ifdef __clang__
CString FUN_140298360(const char* psz, const CString& str);             // psz + str (ATL operator+)
#endif

WorldService* FUN_1403ed2d0();
class Unk_WsB_Spawn { public: virtual void DeleteThis(); virtual void IncRefCount(); virtual void DecRefCount(); };   // spawn point (worldservice_1.cpp)

// Entity / animation service.
struct Unk_RxEntity;
class Unk_RxAnimSvc
{
public:
    efd::utf8string FUN_140b7cc50(const egf::EntityID& id);     // current animation name (in this unit's range)
};
Unk_RxAnimSvc* FUN_141b6f910();
const egf::EntityID* FUN_1408b76f0(const void* pEntity);
void FUN_141b71e70(egf::EntityID id, bool bFlag, int b, int c);
void FUN_14098c6e0(egf::Entity* pEntity, unsigned nHash, const bool& bValue);
const char* FUN_1408ac310(efd::utf8string* p);
void FUN_1409989e0(efd::utf8string* p, const char* psz);
void FUN_1408a8900(efd::utf8string* p);
CString FUN_1409a2360(const char* psz, int n);
bool FUN_140184310(const CString& str, const char* psz);        // string equals
CStringW GetStringCommonByKey(const CStringW& str);                    // string table lookup
void FUN_1412751f0(const CStringW& str, int a, int b);          // shows a notice
CString FUN_1402bb1c0(const char* szFormat, const int& n);      // StringFormat<int>

// Network.
void FUN_140710590(COutPacket& pkt);                            // sends the packet

// The local player and the creation checks.
__int64 FUN_141656a80(PCBase* pPc);                             // character id
int FUN_14166c930(PCBase* pPc);                                 // action id
int FUN_141675ed0(PCBase* pPc);
void* FUN_1408e57f0();
int FUN_1422b9e00(void* p);
int FUN_1416769d0(PCBase* pPc);
bool FUN_140930b10();
bool FUN_140930b70();

// Inventory (0x143ab2a90) and the daily counters (0x143ab2fc0).
class Unk_Inventory { public: int FUN_140a5f180(int nItemId, int nRank); };
extern Unk_Inventory DAT_143ab2a90;
int FUN_14053feb0(int nItemId);                                 // default rank of an item
class Unk_AttendTable { public: int FUN_1409617d0(int a, int b, int* pOut); };
extern Unk_AttendTable g_attendTable;

// Game-event record of the event manager (0x1401c0d90 -> FUN_14047d230).
struct Unk_RxCond { bool FUN_1402a9ca0(int nValue); };
class Unk_RxEvtRec : public CPtred
{
public:
    int m_nEvtId;                                               // +0x18
    char m_pad_1c[0xc];
    int m_nNeed;                                                // +0x28
    char m_pad_2c[4];
    Unk_RxCond m_cond;                                          // +0x30
};
class Unk_RxEvtMgr { public: MS2Ptr<Unk_RxEvtRec> FUN_14047d230(); };
Unk_RxEvtMgr* FUN_1401c0d90();

// Placement check: field grid (service behind 0x143b059e8), map data of the world, actor helpers.
struct Unk_EntityAppFramework { char m_pad[8]; };
extern Unk_EntityAppFramework DAT_143b059e8;
class Unk_RxCellInfo
{
public:
    char m_pad_00[0x44];
    int m_nState;                                               // +0x44
    char m_pad_48[8];
    int m_nCount;                                               // +0x50
};
class Unk_RxGrid
{
public:
    void* FUN_1410b8b00(int nCellId);                           // occupied cell (null when free)
    Unk_RxCellInfo* FUN_1410b8ab0(Vector3 pt);          // cell info at a point
    Unk_RxCellInfo* FUN_1410b8a60(Unk_Int3 cell);               // cell info of a cell
};
class Unk_RxGridRef
{
public:
    Unk_RxGridRef(Unk_RxGrid* p) : m_p(p) {}                    // CComPtrBase<>(p)
    ~Unk_RxGridRef();                                           // 0x1401cd150
    void* FUN_140885310();                                      // the grid, tested for null
    Unk_RxGrid* FUN_1401cd1a0();                                // the grid
    Unk_RxGrid* m_p;
};
Unk_RxGrid* FUN_1401cd040(Unk_EntityAppFramework* p);
void FUN_1401cd150(Unk_RxGridRef* p);
Unk_RxGridRef::~Unk_RxGridRef() { FUN_1401cd150(this); }
class Unk_RxMapInfo : public CPtred
{
public:
    char m_pad_18[0xc4 - 0x18];
    int m_nKind;                                                // +0xc4
};
class Unk_RxPhys;
Unk_RxPhys* FUN_1409f7ca0();
int FUN_14168a450(Unk_RxPhys* p, Vector3* pPos, int* pOut, float fRange);
Unk_Int3 FUN_1408a14c0(Vector3 pt);                     // cell of a point
int FUN_1408a03c0(Unk_Int3 cell);                               // cell id
Unk_Int3 FUN_1408a0400(int nCellId);
Vector3 FUN_1408a15b0(Unk_Int3 cell, Vector3& ptCenter);   // fills the cell center
struct Unk_RxActorView { Vector3 FUN_1409673c0(); };     // actor position copy (member: this=rcx, hidden return=rdx)
class Unk_RxNpcData : public CPtred { public: int FUN_1406ccfc0(); };
class Unk_RxNpc : public CPtred { public: MS2Ptr<Unk_RxNpcData> FUN_141093270(); };
static const int DAT_142de2684 = -2060086266;   // rdata constant copied from 0x142de2684
static const int DAT_142de2698 = -939926171;   // rdata constant copied from 0x142de2698
static const int DAT_142de265c = 19716277;   // rdata constant copied from 0x142de265c
static const int DAT_142de2674 = 52914141;   // rdata constant copied from 0x142de2674
static const int DAT_142de269c = -743420155;   // rdata constant copied from 0x142de269c

// Reactor state information handed to the UI (0x30 bytes).
struct Unk_ReactorInfo
{
    int m_nReactTimeMSec;                                       // +0
    char m_pad_04[0x24];
    CStringW m_strAction;                                       // +0x28
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140b788d0
CReactor::CReactor()
    : m_nStateIdx(0), m_strName(""), m_n150(0), m_n158(0), m_listAnims(10), m_mapEffects(10)
{
}

// @0x140b789c0
CReactor::~CReactor()
{
    for (POSITION pos = m_mapEffects.GetHeadPosition(); pos != 0;)
    {
        int nHandle = m_mapEffects.GetValueAt(pos);
        FUN_1403ed280()->FUN_1411a6060(nHandle);
        m_mapEffects.GetNext(pos);
    }
    m_mapEffects.RemoveAll();
}

// @0x140b78af0
CString CReactor::GetName()
{
    return m_strName;
}

// @0x140b78b40
void CReactor::FUN_140b78b40(bool bFlag)
{
    if (m_unk_80 != 0)
        FUN_141b71e70(egf::EntityID(*FUN_1408b76f0(m_unk_80)), bFlag, 1, 0);
}

// @0x140b78bb0
int CReactor::FUN_140b78bb0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->m_nId;
}

// @0x140b78c00
MS2Ptr<ReactorStateData> CReactor::FUN_140b78c00(int nIdx)
{
    if (m_spData.IsNull())
    {
        MS2_ASSERT_AT(0x7d, 0);
        return MS2Ptr<ReactorStateData>(0);
    }
    if (m_spData->m_states.IsEmpty())
    {
        MS2_ASSERT_AT(0x83, 0);
        return MS2Ptr<ReactorStateData>(0);
    }
    if (nIdx < 0 || nIdx > (int)m_spData->m_states.GetCount() - 1)
        return MS2Ptr<ReactorStateData>(0);
    return m_spData->m_states[nIdx];
}

// @0x140b78d90
void CReactor::FUN_140b78d90(Unk_ReactorInfo* pOut)
{
    if (m_spData.IsNull())
    {
        MS2_ASSERT_AT(0x1a7, 0);
        return;
    }
    MS2Ptr<ReactorStateData> spState = FUN_140966db0();
    if (spState == (ReactorStateData*)0)
        return;
    pOut->m_strAction = GetStringCommonByKey(spState->m_strActionStringKey);
    pOut->m_nReactTimeMSec = m_spData->m_nReactTimeMSec;
}

// @0x140b78ea0
void CReactor::FUN_140b78ea0(const CString& strAni)
{
    if (!strAni.IsEmpty())
        m_listAnims.AddTail(strAni);
}

// @0x140b78ef0
bool CReactor::FUN_140b78ef0(const CString& strEffect)
{
    if (m_mapEffects.Lookup(strEffect))
    {
        return true;
    }
    else
    {
        const NiPoint3& pos = vfunc_18();
        const NiPoint3& rot = vfunc_20();
        Unk_RxXform xf;
        FUN_140a332d0(&xf);
        Unk_NiPoint3 niTop = FUN_14027dcf0(reinterpret_cast<const Vector3&>(pos).FUN_14097fd50(Vector3(0.0f, 0.0f, 1.0f)));
        FUN_14097faa0(xf.m_afTranslate, &niTop);
        xf.m_rotate.FUN_142083d40((rot.x * 3.1415927f) / 180.0f, (rot.y * 3.1415927f) / 180.0f,
                                  (rot.z * 3.1415927f) / 180.0f);
        xf.m_fScale = 1.0f;
        Unk_RxFxRequest request;
        FUN_140a52ef0(&request);
        request.m_strName = strEffect;
        request.m_nOwnerId = 0;
        request.m_pXform = &xf;
        int nHandle = FUN_1403ed280()->FUN_1411a49c0(&request);
        m_mapEffects.SetAt(strEffect, nHandle);
        return true;
    }
}

// @0x140b79120
bool CReactor::FUN_140b79120(const CString& strEffect)
{
    int nHandle = 0;
    if (m_mapEffects.Lookup(strEffect, nHandle))
    {
        FUN_1403ed280()->FUN_1411a6060(nHandle);
        m_mapEffects.RemoveKey(strEffect);
    }
    return true;
}

// @0x140b791a0
void CReactor::FUN_140b791a0()
{
    if (m_unk_80 != 0)
    {
        MS2Ptr<CAnimationManager> spAnim = GetAnimMgr();
        if (!spAnim.IsNull())
        {
            if (FUN_141b6f910() != 0 && !m_listAnims.IsEmpty())
            {
                CString strTemp = FUN_1409a2360(m_listAnims.GetHead(), 0);
                efd::utf8string strAni;
                FUN_1409989e0(&strAni, strTemp);
                spAnim->FUN_14099e050(strAni, 1.0f, false);
                FUN_1408a8900(&strAni);
            }
        }
    }
}

// @0x140b79330
void CReactor::FUN_140b79330()
{
    WorldService* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return;
    PCBase* pPc = (PCBase*)pWorld->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    unsigned __int64 nId = FUN_141656a80(pPc);
    bool bFound = m_setPlayers.find(nId) != m_setPlayers.end();
    MS2Ptr<ReactorData> spData = GetData();
    if (spData.IsNull())
    {
        MS2_ASSERT_AT(0x142, 0);
        return;
    }
    if (bFound)
        FUN_140b78ef0(spData->m_strConnectedEffect);
    else
        FUN_140b79120(spData->m_strConnectedEffect);
}

// @0x140b79490
bool CReactor::FUN_140b79490(CInPacket* pPacket)
{
    int nObjId = pPacket->ReadInt32();
    CString strName = pPacket->ReadString();
    int nReactorId = pPacket->ReadInt32();
    Vector3 pos = pPacket->ReadVector3();
    Vector3 rot = pPacket->ReadVector3();
    m_nStateIdx = pPacket->ReadInt32();
    m_n150 = pPacket->ReadInt64();
    m_setPlayers.clear();
    int nCount = pPacket->ReadUInt8();
    for (int i = 0; i < nCount; ++i)
    {
        unsigned __int64 nPlayer = pPacket->ReadInt64();
        m_setPlayers.insert(nPlayer);
    }
    m_n158 = (unsigned __int64)(unsigned)pPacket->ReadInt32();
    m_spData = CReactorDataTable::GetInstance()->GetReactorData(nReactorId);
    if (!m_spData)
        return false;
    MS2Ptr<ReactorStateData> spState = FUN_140b78c00(m_nStateIdx);
    if (spState.IsNull())
        return false;
#ifdef __clang__
    // clang emits an unavailable MFC CopyChars import for operator+; bind the exe's copy.
    CString strAnim = FUN_140298360("urn:gamebryo-animation:", spState->m_strKfmName);
#else
    CString strAnim = "urn:gamebryo-animation:" + spState->m_strKfmName;
#endif
    m_str88 = "MS2Actor";
    m_strName = strName;
    FUN_14123c5a0(nObjId);
    FUN_14123bb80(CString(strAnim));
    vfunc_19(*(const efd::Point3*)&pos);   // the exe's locals are efd::Point3: trivial by-value copies
    vfunc_21(*(const efd::Point3*)&rot);
    m_listAnims.RemoveAll();
    FUN_140b78ea0(spState->m_strIdleAni);
    return true;
}

// @0x140b799a0
void CReactor::SendStateReact()
{
    COutPacket pkt(static_cast<int>(SendOp::StateReact), 0);
    pkt.WriteUInt8(2);
    pkt.WriteInt32(FUN_14123c580());
    FUN_140710590(pkt);
}

// @0x140b79a10
void CReactor::FUN_140b79a10(CInPacket* pPacket)
{
    m_nStateIdx = pPacket->ReadInt32();
    m_n150 = pPacket->ReadInt64();
    m_setPlayers.clear();
    int nCount = pPacket->ReadUInt8();
    for (int i = 0; i < nCount; ++i)
    {
        unsigned __int64 nPlayer = pPacket->ReadInt64();
        m_setPlayers.insert(nPlayer);
    }
    m_n158 = (unsigned __int64)(unsigned)pPacket->ReadInt32();
    MS2Ptr<ReactorStateData> spState = FUN_140b78c00(m_nStateIdx);
    if (spState.IsNull())
        return;
    m_listAnims.RemoveAll();
    FUN_140b78ea0(spState->m_strStartAni);
    FUN_140b78ea0(spState->m_strIdleAni);
}

// @0x140b79c30
bool CReactor::FUN_140b79c30()
{
    WorldService* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return false;
    PCBase* pPc = (PCBase*)pWorld->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    if (FUN_140b7a5e0(pPc) != 0)
        return false;
    if (FUN_140b79cc0(pPc) != 0)
        return false;
    if (FUN_140b79ee0(pPc) != 0)
        return false;
    return true;
}

// @0x140b79cc0
int CReactor::FUN_140b79cc0(PCBase* pPc)
{
    if (pPc == 0)
    {
        MS2_ASSERT_AT(0xa7, 0);
        return 1;
    }
    MS2Ptr<ReactorStateData> spState = FUN_140b78c00(m_nStateIdx);
    if (spState.IsNull())
        return 1;
    int nType = spState->m_nType;
    if (nType == 1)
    {
        if (m_setPlayers.find(FUN_141656a80(pPc)) != m_setPlayers.end())
            return 1;
    }
    else
    {
        if (nType == 2)
            return 1;
        if (nType == 3)
        {
            if (m_setPlayers.find(FUN_141656a80(pPc)) == m_setPlayers.end())
                return 1;
        }
    }
    return 0;
}

// @0x140b79ee0
int CReactor::FUN_140b79ee0(PCBase* pPc)
{
    if (pPc == 0)
    {
        MS2_ASSERT_AT(0xc6, 0);
        return 1;
    }
    MS2Ptr<ReactorStateData> spState = FUN_140b78c00(m_nStateIdx);
    if (spState.IsNull())
        return 1;
    ReactorStateData::ConditionList& conds = spState->m_conditions;
    for (POSITION pos = conds.GetHeadPosition(); pos != 0; conds.GetNext(pos))
    {
        MS2Ptr<ReactorCondition> spCond = conds.GetAt(pos);
        if (spCond.IsNull())
            continue;
        if (spCond->m_nType == 0)
        {
            ReactorConditionItem* pItem = static_cast<ReactorConditionItem*>(spCond.get());
            if (pItem != 0)
            {
                int nCode = pItem->m_nCode;
                int nConsume = pItem->m_nConsume;
                int nCheck = pItem->m_nCheckCount;
                int nRank = pItem->m_nRank;
                int nNeed = (std::max)(nCheck, nConsume);
                if (nCode != 0 && nNeed != 0)
                {
                    if (nRank == 0)
                        nRank = FUN_14053feb0(nCode);
                    if (DAT_143ab2a90.FUN_140a5f180(nCode, nRank) < nNeed)
                        return 1;
                }
            }
        }
    }
    return 0;
}

// @0x140b7a120
void CReactor::vfunc_53(float f)
{
    GameObject::vfunc_53(f);
    FUN_140b791a0();
    FUN_140b79330();
}

// @0x140b7a160
void CReactor::vfunc_9(void* p)
{
    GameObject::vfunc_9(p);
    bool bValue = false;
    FUN_14098c6e0((egf::Entity*)p, 0x2a7fd9f4, bValue);
}

// @0x140b7a1b0
void CReactor::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    GameObject::EndOfSequence(pkManager, eSequenceID, pkSeq, fEventTime);
    if (m_unk_80 != 0 && !m_listAnims.IsEmpty() && FUN_141b6f910() != 0)
    {
        efd::utf8string strCur = FUN_141b6f910()->FUN_140b7cc50(*FUN_1408b76f0(m_unk_80));
        bool bSame = FUN_140184310(m_listAnims.GetHead(), FUN_1408ac310(&strCur));
        FUN_1408a8900(&strCur);
        if (bSame)
            m_listAnims.RemoveHead();
    }
}

// @0x140b7a330
bool FUN_140b7a330(PCBase* pPc, int nReactorId)
{
    if (pPc == 0)
        return false;
    int nError = FUN_140b7a3d0(pPc, nReactorId);
    if (nError != 0)
    {
        FUN_140b7b7a0(nError);
        return false;
    }
    if (FUN_140b7a5e0(pPc) != 0)
    {
        FUN_140b7b7a0(2);
        return false;
    }
    if (FUN_140b7a650(pPc) != 0)
    {
        FUN_140b7b7a0(3);
        return false;
    }
    return true;
}

// @0x140b7a3d0
int FUN_140b7a3d0(PCBase* pPc, int nReactorId)
{
    if (pPc == 0)
        return 1;
    MS2Ptr<ReactorData> spData = CReactorDataTable::GetInstance()->GetReactorData(nReactorId);
    if (spData.IsNull())
        return 1;
    int nEvent = spData->m_nGameEventId;
    if (nEvent == 0)
        return 0;
    MS2Ptr<Unk_RxEvtRec> spRec = FUN_1401c0d90()->FUN_14047d230();
    if (spRec.IsNull())
        return 4;
    if (spRec->m_nEvtId != nEvent)
        return 4;
    int nField = FUN_1403ed2d0()->FUN_141bd3060();
    if (!spRec->m_cond.FUN_1402a9ca0(nField))
        return 5;
    int nDummy = 0;
    int nCount = g_attendTable.FUN_1409617d0(0x76d, nEvent, &nDummy);
    if (nCount < spRec->m_nNeed)
        return 0;
    return 6;
}

// @0x140b7a5e0
int FUN_140b7a5e0(PCBase* pPc)
{
    if (pPc == 0)
        return 1;
    if (FUN_14166c930(pPc) == 1)
    {
        if (FUN_141675ed0(pPc) == 0)
        {
            if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d)
                return 0;
            return 1;
        }
        return 1;
    }
    return 1;
}

// @0x140b7a650
// MS2-FUNCTIONAL: opaque field-grid, actor and raycast helpers (stand-in classes); the statement order follows the exe.
int FUN_140b7a650(PCBase* pPc)
{
    if (pPc == 0)
        return 1;
    WorldService* pWorld = FUN_1403ed2d0();
    if (pWorld == 0)
        return 1;
    if (pWorld->FUN_141bd30a0() == (Unk_WsPtred298*)0)
        return 1;
    bool bBlocked = true;
    if (!FUN_140930b10() && FUN_140930b70())
    {
        MS2Ptr<Unk_WsPtred298> spInfo = pWorld->FUN_141bd30a0();
        if (reinterpret_cast<Unk_RxMapInfo*>(spInfo.get())->m_nKind != 1)
            bBlocked = false;
    }
    if (bBlocked)
        return 1;

    Unk_RxGridRef grid(FUN_1401cd040(&DAT_143b059e8));
    if (grid.FUN_140885310() == 0)
    {
        MS2_ASSERT_AT(0x21e, 0);
        return 1;
    }
    ATL::CAtlArray<MS2Ptr<Unk_WsPtred298> > arrNear;
    pWorld->FUN_141bc5f10(&arrNear);
    NiPoint3 posPc = ((GameObject*)pPc)->vfunc_18();
    Vector3 ptPc(posPc.x, posPc.y, posPc.z);
    Unk_Int3 cellOfPc = FUN_1408a14c0(ptPc);
    int nCellId = FUN_1408a03c0(cellOfPc);
    Unk_Int3 cell = FUN_1408a0400(nCellId);
    Vector3 ptCenter;
    FUN_1408a15b0(cell, ptCenter);

    for (size_t i = 0; i < arrNear.GetCount(); ++i)
    {
        MS2Ptr<Unk_WsPtred298> spObj = arrNear[i];
        if (!spObj.IsNull())
        {
            Vector3 pt = reinterpret_cast<Unk_RxActorView*>(spObj.get())->FUN_1409673c0();
            if (pt.FUN_140965c40(ptCenter).FUN_140967ac0() < 230.0f)
                return 1;
        }
    }

    CString strName = FUN_1402bb1c0("Reactor_{0}", nCellId);
    if (pWorld->FUN_141bc6eb0(strName).data() != 0)
        return 1;
    ATL::CAtlArray<MS2Ptr<Unk_WsPtred298> > arrField;
    pWorld->FUN_141bc2c90(ptCenter, &arrField);
    if (!arrField.IsEmpty())
        return 1;

    ATL::CRBMap<unsigned, Unk_WsV148>* pActors = pWorld->FUN_141bd36d0();
    for (POSITION pos = pActors->GetHeadPosition(); pos != 0; pActors->GetNext(pos))
    {
        MS2Ptr<Unk_RxNpc> spActor(*reinterpret_cast<MS2Ptr<Unk_RxNpc>*>(&pActors->GetValueAt(pos)));
        if (!spActor.IsNull())
        {
            if (FUN_14166c930((PCBase*)spActor.get()) == 2)
                continue;
            bool bNotNpcKind = spActor->FUN_141093270()->FUN_1406ccfc0() != 2;
            if (!bNotNpcKind)
            {
                if (FUN_1416769d0((PCBase*)spActor.get()) == 0)
                {
                    Vector3 pt;
                    NiPoint3 posActor = ((GameObject*)spActor.get())->vfunc_18();
                    Unk_Int3 cellOfActor = FUN_1408a14c0(Vector3(posActor.x, posActor.y, posActor.z));
                    int nActorCell = FUN_1408a03c0(cellOfActor);
                    FUN_1408a15b0(FUN_1408a0400(nActorCell), pt);
                    if (pt.FUN_140965c40(ptCenter).FUN_140967ac0() < 230.0f)
                        return 1;
                }
            }
        }
    }
    if (grid.FUN_1401cd1a0()->FUN_1410b8b00(nCellId) != 0)
        return 1;

    std::vector<efd::Point3> samples;   // the exe's glue is vector<efd::Point3> (itemdatastruct's _Umove_if_noexcept etc.)
    samples.push_back(efd::Point3(ptCenter.x, ptCenter.y, ptCenter.z));
    samples.push_back(efd::Point3(ptCenter.x + 75.0f, ptCenter.y, ptCenter.z));
    samples.push_back(efd::Point3(ptCenter.x - 75.0f, ptCenter.y, ptCenter.z));
    samples.push_back(efd::Point3(ptCenter.x, ptCenter.y + 75.0f, ptCenter.z));
    samples.push_back(efd::Point3(ptCenter.x, ptCenter.y - 75.0f, ptCenter.z));
    for (size_t i = 0; i < samples.size(); ++i)
    {
        efd::Point3* pSample = &samples[i];
        pSample->z = pSample->z + 10.0f;
        int nHit = 0;
        if (FUN_14168a450(FUN_1409f7ca0(), reinterpret_cast<Vector3*>(pSample), &nHit, 50.0f) == 0)
            return 1;
    }

    Vector3 ptLow = ptCenter;
    ptLow.z = ptLow.z - 150.0f;
    Unk_RxCellInfo* pInfo = grid.FUN_1401cd1a0()->FUN_1410b8ab0(ptLow);
    if (pInfo == 0)
        return 1;
    if (pInfo->m_nState != 1)
        return 1;

    std::vector<Unk_Int3> cells;
    cells.reserve(9);
    cells.push_back(Unk_Int3(cell.x, cell.y, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x, cell.y - 1, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x, cell.y + 1, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x - 1, cell.y, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x - 1, cell.y - 1, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x - 1, cell.y + 1, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x + 1, cell.y, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x + 1, cell.y - 1, cell.z - 1));
    cells.push_back(Unk_Int3(cell.x + 1, cell.y + 1, cell.z - 1));
    for (size_t i = 0; i < cells.size(); ++i)
    {
        Unk_RxCellInfo* pCell = grid.FUN_1401cd1a0()->FUN_1410b8a60(cells[i]);
        if (pCell != 0 && pCell->m_nCount != 0)
            return 1;
    }

    ATL::CAtlArray<int> arrIds;
    arrIds.Add(DAT_142de2684);
    arrIds.Add(DAT_142de2698);
    arrIds.Add(DAT_142de265c);
    arrIds.Add(DAT_142de2674);
    arrIds.Add(DAT_142de269c);
    for (size_t i = 0; i < arrIds.GetCount(); ++i)
    {
        if (pWorld->FUN_141bcfd30(arrIds[i], ptCenter, 230.0f, 0, 0) != 0)
            return 1;
    }
    return 0;
}

// @0x140b7b7a0
void FUN_140b7b7a0(int nError)
{
    switch (nError)
    {
    case 1:
    {
        CStringW strKey(L"s_reactor_failed");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        break;
    }
    case 2:
    {
        CStringW strKey(L"s_reactor_create_failed_invalid_state");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        break;
    }
    case 3:
    {
        CStringW strKey(L"s_reactor_create_failed_invalid_position");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        break;
    }
    case 4:
    {
        CStringW strKey(L"s_reactor_create_failed_game_event_inactive");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        break;
    }
    case 5:
    {
        CStringW strKey(L"s_reactor_create_failed_invalid_field");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        break;
    }
    case 6:
    {
        CStringW strKey(L"s_reactor_create_failed_daily_reward_count");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        break;
    }
    }
}

// ---------------------------------------------------------------------------------------------------------------
// Standard-container glue inside this unit's range (std::vector<Unk_Int3>, std::set<__int64>, std::string pair).
// The exe instantiations are keyed to MSVC internals we do not instantiate byte-exactly; these are plain functional
// stand-ins for each exe function (never hooked: the real instantiations are reached through the std code above).
// ---------------------------------------------------------------------------------------------------------------
struct Unk_GlueVec { Unk_Int3* first; Unk_Int3* last; Unk_Int3* end; };    // std::vector<Unk_Int3> storage
struct Unk_GluePair { void* first; void* second; };
// CAtlRBTree CNode: key +0, value +8, color +0x10, left +0x18, right +0x20, parent +0x28 (nil node at tree +0x28,
// 0x140b7d0c0; 0x140b7d300 walks [node+0x18])
struct Unk_GlueNode { char m_pad_00[0x18]; Unk_GlueNode* left; Unk_GlueNode* right; Unk_GlueNode* parent; };

__declspec(noreturn) void FUN_140159b70(unsigned int hr);
bool FUN_140b7d0c0(void* pTree, Unk_GlueNode* pNode);
Unk_GlueNode* FUN_140b7d300(void* pTree, Unk_GlueNode* pNode);
Unk_GlueNode* FUN_140b7e2a0(void* pTree, Unk_GlueNode* pNode);
void FUN_140b7bb00(void* a, void* b, void* c);
void* FUN_140b7e7d0(void* p);
void* FUN_140b7e770(void* p);
void* FUN_140b7e750(void* p);
void FUN_14016c7c0(void* p);
Unk_GlueNode** FUN_140b7e8a0(void* p);
Unk_GlueNode** FUN_140b7e8e0(void* p);
Unk_GlueNode** FUN_140b7e860(void* p);
void* FUN_140b7ec10(void* p);
void FUN_140b7c690(void* p);
void FUN_140b7c650(void* p);
void FUN_14016c7c0(void* p);
Unk_Int3* FUN_140b7c1d0(Unk_Int3* p);
void FUN_140b7c1e0(void* a, void* b);
void FUN_140b7c220(void* a, void* b);
void FUN_140b7c270(void* a, void* b);
Unk_Int3* FUN_140b7c370(Unk_Int3* f, Unk_Int3* l, Unk_Int3* d, void* alloc, char a, char b);
void FUN_14015fc80(void* p, __int64 nBytes);   // std::_Deallocate<16,0>

// @0x140b7bab0
// MS2-FUNCTIONAL: std::string allocator pair ctor glue, stand-in for the exe instantiation
void* FUN_140b7bab0(void* p) { FUN_140b7c690(p); FUN_140b7c650(p); return p; }

// @0x140b7c2a0
// MS2-FUNCTIONAL: std::vector<Unk_Int3> _Ucopy stand-in
Unk_Int3* FUN_140b7c2a0(Unk_Int3* pFirst, Unk_Int3* pLast, Unk_Int3* pDest, void* pAlloc)
{
    for (; pFirst != pLast; ++pFirst, ++pDest)
        *pDest = *pFirst;
    return pDest;
}

// @0x140b7c620
// MS2-FUNCTIONAL: empty-allocator _Compressed_pair ctor stand-in
void* FUN_140b7c620(void* p) { return p; }

// @0x140b7c6a0
// MS2-FUNCTIONAL: empty-allocator _Compressed_pair ctor stand-in
void* FUN_140b7c6a0(void* p) { return FUN_140b7c620(p); }

// @0x140b7c870
bool FUN_140b7c870(const Unk_GluePair* pIt, void* pOther) { return pIt->first == pOther; }

// @0x140b7c8b0
bool FUN_140b7c8b0(const Unk_GluePair* pIt, void* pOther) { return pIt->second == pOther; }

// @0x140b7c930
// MS2-FUNCTIONAL: vector element address stand-in
Unk_Int3* FUN_140b7c930(Unk_GlueVec* pVec, __int64 nIdx) { return pVec->first + nIdx; }

// @0x140b7c960
void* FUN_140b7c960(const Unk_GluePair* p) { return p->second; }

// Animation-service current-name lookup
struct Unk_RxAnimRec;
bool FUN_1409991a0(Unk_RxAnimSvc* pSvc, const egf::EntityID* pId, Unk_RxAnimRec** ppRec, int a, int b);
void* FUN_140998e80(Unk_RxAnimRec* p);
void* FUN_140998e90(Unk_RxAnimRec* p);
void* FUN_1409a1a90();
void FUN_1409a0f10(efd::utf8string* pOut, void* pDefault);
void* FUN_1409f7900(Unk_RxAnimRec* p);
int FUN_1409a1890(void* p);
void FUN_1409a1940(void* pName, efd::utf8string* pOut, int nIdx);
// @0x140b7cc50
// MS2-FUNCTIONAL: animation-service current-name lookup; callee prototypes unproven
efd::utf8string Unk_RxAnimSvc::FUN_140b7cc50(const egf::EntityID& id)
{
    efd::utf8string strOut;
    Unk_RxAnimRec* pRec = 0;
    if (!FUN_1409991a0(this, &id, &pRec, 0, 0))
    {
        FUN_1409a0f10(&strOut, FUN_1409a1a90());
        return strOut;
    }
    void* pName = FUN_140998e80(pRec);
    if (!pName)
    {
        FUN_1409a0f10(&strOut, FUN_1409a1a90());
        return strOut;
    }
    if (!FUN_140998e90(pRec))
    {
        FUN_1409a0f10(&strOut, FUN_1409a1a90());
        return strOut;
    }
    int nIdx = FUN_1409a1890(FUN_1409f7900(pRec));
    if (nIdx == -2)
        FUN_1409a0f10(&strOut, FUN_1409a1a90());
    else
        FUN_1409a1940(pName, &strOut, nIdx);
    return strOut;
}

// @0x140b7ce20
void FUN_140b7ce20(Unk_GlueNode** ppRoot) { FUN_140b7d300(ppRoot, *ppRoot); }

// @0x140b7cec0
Unk_GlueNode* FUN_140b7cec0(void* pTree, Unk_GlueNode** ppIt)
{
    Unk_GlueNode* pOld = *ppIt;
    *ppIt = FUN_140b7e2a0(pTree, pOld);
    return pOld;
}

// @0x140b7cf00
// MS2-FUNCTIONAL: std::set<__int64> node value accessor stand-in
void* FUN_140b7cf00(void* pTree, Unk_GlueNode* pNode)
{
    if (pNode)
        return reinterpret_cast<char*>(pNode) + 8;
    FUN_140159b70(0x80004005);
}

// @0x140b7d300
// MS2-FUNCTIONAL: std::set<__int64> tree walk stand-in
Unk_GlueNode* FUN_140b7d300(void* pTree, Unk_GlueNode* pNode)
{
    Unk_GlueNode* pCur;
    if (!pNode || (pCur = pNode, FUN_140b7d0c0(pTree, pNode)))
        return 0;
    while (!FUN_140b7d0c0(pTree, pCur->left))
        pCur = pCur->left;
    return pCur;
}

// @0x140b7e710
void FUN_140b7e710(void* pVec, void* pFirst, void* pLast) { FUN_140b7bb00(pFirst, pLast, FUN_140b7e7d0(pVec)); }

// @0x140b7e8c0
void FUN_140b7e8c0(void* p) { FUN_140b7e770(p); }

// @0x140b7e900
void* FUN_140b7e900(void* p) { return static_cast<char*>(FUN_140b7e770(p)) + 8; }

// @0x140b7e920
void FUN_140b7e920(void* p) { FUN_14016c7c0(FUN_140b7e750(p)); }

// @0x140b7ea10
// MS2-FUNCTIONAL: std::vector<Unk_Int3> _Tidy stand-in
void FUN_140b7ea10(void* pVec)
{
    FUN_140b7e920(pVec);
    if (*FUN_140b7e8a0(pVec) != 0)
    {
        FUN_140b7e710(pVec, *FUN_140b7e8a0(pVec), *FUN_140b7e8e0(pVec));
        void* pCap = FUN_140b7ec10(pVec);
        FUN_14015fc80(*FUN_140b7e8a0(pVec), reinterpret_cast<__int64>(pCap) * 0xc);
        *FUN_140b7e8a0(pVec) = 0;
        *FUN_140b7e8e0(pVec) = 0;
        *FUN_140b7e860(pVec) = 0;
    }
}

// @0x140b7eb20
void FUN_140b7eb20(void* pVec, Unk_Int3* pFirst, Unk_Int3* pLast, Unk_Int3* pDest) { FUN_140b7c2a0(pFirst, pLast, pDest, FUN_140b7e7d0(pVec)); }

// @0x140b7ec60
void FUN_140b7ec60(void* pAlloc, void* pMem, __int64 nCount) { FUN_14015fc80(pMem, nCount * 0xc); }

// @0x140b7ec90
// MS2-FUNCTIONAL: std::allocator<Unk_Int3>::max_size stand-in
unsigned __int64 FUN_140b7ec90() { return 0x1555555555555555ull; }
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca1040-0x142ca1160 .text$yd

// fx24: samples is vector<efd::Point3> (tplpin --simulate pins, hand-applied); the two push_back(T&&) / emplace_back
// pairs are byte-identical look-alikes told apart by their exe callees: 0x140b7ed20 -> 0x140b7c4c0 -> the Point3
// _Emplace_reallocate 0x140b7bf80 (calls itemdatastruct's vector<Point3> glue); 0x140b7ecf0 -> 0x140b7c450 -> the
// in-range vector<Unk_Int3> helpers 0x140b7e810 / 0x140b7e8e0.
// MS2-PIN: ??$_Emplace_back@VPoint3@efd@@@?$_Uninitialized_backout_al@PEAVPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAAX$$QEAVPoint3@efd@@@Z 0x140b7bb50
// MS2-PIN: ??$_Uninitialized_move_al_unchecked@PEAVPoint3@efd@@PEAV12@V?$allocator@VPoint3@efd@@@std@@@std@@YAPEAVPoint3@efd@@PEAV12@QEAV12@1AEAV?$allocator@VPoint3@efd@@@0@U_General_ptr_iterator_tag@0@U_Unused_parameter@0@@Z 0x140b7c370
// MS2-PIN: ??0?$_Uninitialized_backout_al@PEAVPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAA@PEAVPoint3@efd@@AEAV?$allocator@VPoint3@efd@@@1@@Z 0x140b7c5e0
// MS2-PIN: ??1?$_Uninitialized_backout_al@PEAVPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAA@XZ 0x140b7c7c0
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAVPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAAPEAVPoint3@efd@@XZ 0x140b7e9f0
// MS2-PIN: ?RemoveAll@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x140b7de00
// MS2-PIN: ?SetAt@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAAPEAU__POSITION@@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@H@Z 0x140b7e170
// MS2-PIN: ??1?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x140b7c780
// MS2-PIN: ?Lookup@?$CRBMap@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@QEBA_NAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@AEAH@Z 0x140b7d240
// MS2-PIN: ?RBDelete@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HV?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@H@2@@ATL@@AEAA_NPEAVCNode@12@@Z 0x140b7d6a0
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400c8ee0
// MS2-PIN: ??__Econdition@Unk_ReactorStatics@@YAXXZ 0x1400c9050
// MS2-PIN: ?push_back@?$vector@VPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAAX$$QEAVPoint3@efd@@@Z 0x140b7ed20
// MS2-PIN: ?push_back@?$vector@UUnk_Int3@@V?$allocator@UUnk_Int3@@@std@@@std@@QEAAX$$QEAUUnk_Int3@@@Z 0x140b7ecf0
// MS2-PIN: ??$emplace_back@VPoint3@efd@@@?$vector@VPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAAX$$QEAVPoint3@efd@@@Z 0x140b7c4c0
// MS2-PIN: ??$emplace_back@UUnk_Int3@@@?$vector@UUnk_Int3@@V?$allocator@UUnk_Int3@@@std@@@std@@QEAAX$$QEAUUnk_Int3@@@Z 0x140b7c450
// MS2-PIN: ??$_Emplace_reallocate@VPoint3@efd@@@?$vector@VPoint3@efd@@V?$allocator@VPoint3@efd@@@std@@@std@@QEAAPEAVPoint3@efd@@QEAV23@$$QEAV23@@Z 0x140b7bf80
