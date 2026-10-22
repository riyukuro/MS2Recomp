// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The summon / go-home / recall family of the client state
// manager (StateSummon / StateGoToHome / StateRecall each show a casting bar and register as its listener), the four
// pet helper states and their poll-timer helpers. See statesummon.h. The MS2Ptr<StateSummonData> /
// MS2Ptr<StateRecallData> instantiations the exe keeps in this unit's tail come out of ms2ptr_impl.h.
// MS2-UNIT: ?\statesummon.cpp
// MS2-RANGE: 0x1417f7550-0x1417fa370 .text$mn
// MS2-RANGE: 0x140104390-0x140104530 .text$di
// MS2-PIN: ??_GStateGoToHome@@UEAAPEAXI@Z 0x1417f9ec0 ; order
// MS2-PIN: ??_GStateRecall@@UEAAPEAXI@Z 0x1417f9f00 ; order
// MS2-PIN: ??_GStateSummon@@UEAAPEAXI@Z 0x1417f9f40 ; order
// MS2-PIN: ??_GStateSummonExpire@@UEAAPEAXI@Z 0x1417f9f80 ; order
// MS2-PIN: ??_GStateSummonIdle@@UEAAPEAXI@Z 0x1417f9fc0 ; order
// MS2-PIN: ??_GStateSummonItemPick@@UEAAPEAXI@Z 0x1417fa000 ; order
// MS2-PIN: ??_GStateSummonPortal@@UEAAPEAXI@Z 0x1417fa040 ; order
// MS2-PIN: ??_GStateSummonRevive@@UEAAPEAXI@Z 0x1417fa080 ; order
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statesummon.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <float.h>
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <NiActorManager.h>

#include "statesummon.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// CItem::FUN_140527840's record (item.cpp owns the real one).
class Unk_ItemEquipData : public CItemData { };

// The item-data rows the summon packet path reads (ridee.cpp / item.cpp own the real MS2Ptr instances).
class Unk_RideeData : public CPtred { };
class Unk_PetRow : public CPtred { };
class Unk_PCBaseComp_aa8 : public CPtred { };

// The player inventory (global 0x143ab2a90): item lookup by uid and the item's name.
class Unk_LockInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid);                         // 0x140a5d680 the item with that uid
    int FUN_140a63880(CItem* pItem, const CStringW& strName);              // 0x140a63880 the item's name
};
extern Unk_LockInventory DAT_143ab2a90;

// The item-data tables.
MS2Ptr<Unk_RideeData> FUN_1407844b0(int nRideeId);                         // 0x1407844b0 the ridee row
Unk_RideeData* FUN_1407895d0(MS2Ptr<Unk_RideeData>& refRow);               // 0x1407895d0 the row
class Unk_SmPetTable { public: MS2Ptr<Unk_PetRow> FUN_1407290f0(int nPetId); };   // 0x1407290f0 that pet row (member)
Unk_SmPetTable* FUN_14052d210();                                           // 0x14052d210 the pet-data table

// The world service, its effect manager and the field objects it hands out.
void* FUN_1403ed2d0();                                                     // 0x1403ed2d0 the world
void* FUN_1403ed280();                                                     // 0x1403ed280 the effect manager
int FUN_141bd1a10(void* pWorld, void* pOwner);                             // 0x141bd1a10 the field the actor is in
void* FUN_141bd1a50(void* pWorld, void* pActor);                           // 0x141bd1a50 the field object
void FUN_1411a4a00(void* pEffects, const CStringA& strPath);               // 0x1411a4a00 preload an effect
void FUN_141191330(void* pField, int nId);                                 // 0x141191330
void FUN_141190900(void* pField, int nId);                                 // 0x141190900
void* FUN_140b12380(void* pField);                                         // 0x140b12380 the field's drop manager
int FUN_14123c580(void* pActor);                                           // 0x14123c580 the actor's object id
void FUN_140a53190(CStringA& strName, int nObjectId);                      // 0x140a53190 append the id's name

// The actor registry the pet state queries by entity id.
void* FUN_141b6f910();                                                     // 0x141b6f910
int FUN_140b7f6a0(void* pRegistry, const egf::EntityID& kEntity);          // 0x140b7f6a0 the actor id at that key

// The client settings / skill services.
void* FUN_1409a8b10();                                                     // 0x1409a8b10 the client-settings service
void* FUN_140b123b0(void* pCfg);                                           // 0x140b123b0
void* FUN_14124ab20(void* pCfg);                                           // 0x14124ab20
void* FUN_140535320();                                                     // 0x140535320 the skill service
void* FUN_140c8b450(void* pSvc);                                           // 0x140c8b450
void* FUN_140c8b430(void* pSvc);                                           // 0x140c8b430
void FUN_140c892c0(void* pSvc, MS2Ptr<Unk_ItemEquipData>& refOut, int nSkillId);   // 0x140c892c0
bool FUN_1401c0050(MS2Ptr<Unk_ItemEquipData>& ref, int n);                 // 0x1401c0050 the reference is set
int FUN_1409a1a00(NiActorManager* pkManager);                              // 0x1409a1a00 the manager's sequence id

// The pet actor and its manager.
void* FUN_140b10360(PCBase* pPet);                                         // 0x140b10360 the pet's manager
int FUN_140b11e90(void* pList, void* pItem);                               // 0x140b11e90 index of the item
void* FUN_14165f100(PCBase* p);                                            // 0x14165f100 the playing emotion
void FUN_14165f170(PCBase* p);                                             // 0x14165f170 stop it
void FUN_140b11180(void* pPet);                                            // 0x140b11180 update
void FUN_140b114e0(PCBase* pPet, int nAnimId);                             // 0x140b114e0 play a pet animation
struct Unk_SmPet { MS2Ptr<Unk_PetRow> FUN_140b102b0(); };                // 0x140b102b0 CPet: the pet's row (by value)
int FUN_141661970(PCBase* pActor);                                         // 0x141661970 the actor is busy
int FUN_140f48d40(void* pComp);                                            // 0x140f48d40 the component's flag

// The client constants table and its Value<T> accessors.
void* FUN_1401d3200();                                                     // 0x1401d3200 the constants table
int FUN_140ad5c50(const void* pValue);                                     // 0x140ad5c50 Value<int>::Read
const unsigned* FUN_1401d7c10(const void* pValue);                         // 0x1401d7c10 Value<unsigned>::Get

// The casting bar (statehomeconvenient.cpp / statenurturing.cpp own the real dialog).
class UICastingBar : public UIObject
{
public:
    void FUN_1418e12f0(ICastingEventListener* pListener, const CStringW& strLabel, int nMs, bool bA, bool bB,
                       const CStringW& strExtra);                          // show
    void FUN_1418e1390();                                                  // cancel
};
UICastingBar* FUN_140ac2270(int nId);                                      // 0x140ac2270 the casting bar dialog
CStringW GetStringCommon(int nId);                                           // 0x14028de60 the string-table text of an id
void FUN_141276180(const CStringA& strCommand, const CStringA& strArg);    // 0x141276180 run a client command

// The pet's position buffer (statehomemade.cpp owns the real one).
class Unk_SmBuffMgr { public: Unk_StreamPoint FUN_141683290(); };
Unk_SmBuffMgr* FUN_14166d240(PCBase* p);                                   // 0x14166d240 &m_unk_6d8

// The ride-on action the summon packet carries (RideOnActionUseItem: ms2/commonfiles/rideonaction.h).

// The pet motion helpers of this unit.
void FUN_1417f9100(StateSummonIdle* pState, int nActorId);
void FUN_1417f9260(StateSummonIdle* pState, int nActorId);
void FUN_1417f92c0(StateSummonIdle* pState, int nActorId);
void FUN_1417f9320(StateSummonIdle* pState, int nActorId);
void FUN_1417f9380(StateSummonIdle* pState, int nActorId);
void FUN_1417f9440(StateSummonIdle* pState, int nActorId);
void FUN_1417f94a0(StateSummonIdle* pState, int nAnimId);

// The 8-byte item-uid payloads the summon packets serialize.
struct Unk_SummonUid0 { Unk_SummonUid0(); __int64 m_nUid; };
struct Unk_SummonUid3 { Unk_SummonUid3(); __int64 m_nUid; };
MS2_CHECK_SIZE(Unk_SummonUid0, 8);
MS2_CHECK_SIZE(Unk_SummonUid3, 8);

extern Unk_StreamPoint DAT_143b01a60;                                      // the zero point

// ---- unit statics (.text$di): the shared sort-name / skill / stun / condition / command statics ----

static CString s_strSortTypeNames6[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill6 = "skill";
static CString s_strStun6 = "stun";
static Unk_1402a9d70 s_condition6(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strReturnHouse6 = "PC_ReturnHouse";

// ---- the item-uid payload ctors ---------------------------------------------------------------------------------------

// @0x1417f9c70
Unk_SummonUid0::Unk_SummonUid0() : m_nUid(0) {}

// @0x1417f9c90
Unk_SummonUid3::Unk_SummonUid3() : m_nUid(0) {}

// ---- StateSummon --------------------------------------------------------------------------------------------------------

// @0x1417f7550
StateSummon::StateSummon(PCBase* pOwner) : State(pOwner), m_n48(0) {}

// @0x1417f75e0
StateSummon::~StateSummon() {}

// @0x1417f7630
// MS2-FUNCTIONAL: the ridee / pet item inspection chain is written against the recovered CItem API
void StateSummon::vfunc_4(StateData* pData)
{
    m_n48 = 0;
    State::vfunc_4(pData);

    int nLabel = 0;
    int nDuration = FUN_140ad5c50(reinterpret_cast<const char*>(FUN_1401d3200()) + 0x33c0);

    m_spData.AssignRaw(static_cast<StateSummonData*>(pData));
    if (m_spData.get() != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(
            reinterpret_cast<__int64>(m_spData.get()->m_pSummon));
        if (spItem.get() != 0)
        {
            CItem* pItem = spItem.operator->();
            if (pItem->FUN_140525640() == 0)
            {
                Unk_ItemEquipData* pEquip = pItem->FUN_140527840();
                if (pEquip->FUN_14053cc80())
                {
                    MS2Ptr<Unk_RideeData> spRow = FUN_1407844b0(pEquip->FUN_14053dd80());
                    if (spRow.get() != 0)
                    {
                        nLabel = 0x650;
                        nDuration = static_cast<int>(
                            *reinterpret_cast<float*>(reinterpret_cast<char*>(FUN_1407895d0(spRow)) + 0x74));
                    }
                }
                m_n10 = 0x82;
            }
            else
            {
                MS2Ptr<Unk_PetRow> spRow = FUN_14052d210()->FUN_1407290f0(pItem->FUN_140527840()->FUN_14053dc60());
                if (spRow.get() != 0)
                {
                    nLabel = 0x64f;
                    nDuration = static_cast<int>(
                        *FUN_1401d7c10(reinterpret_cast<const char*>(FUN_1401d3200()) + 0x7d30));
                }
                m_n10 = 0x83;
            }
        }
    }

    if (m_n10 == 0x83)
    {
        bool bPreload = true;
        if (FUN_1417b8560() == 0)
        {
            if (*reinterpret_cast<char*>(static_cast<char*>(FUN_140b123b0(FUN_1409a8b10())) + 0x12) != 0)
                bPreload = false;
        }
        if (bPreload)
        {
            CStringA strPath;
            strPath = "CH/Common/Eff_PetOn.xml";
            FUN_140a53190(strPath, FUN_141bd1a10(FUN_1403ed2d0(), m_pOwner));
            FUN_1411a4a00(FUN_1403ed280(), strPath);
        }
    }

    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        if (FUN_14165f100(pRider) != 0)
            FUN_14165f170(pRider);
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
        {
            CStringW strExtra(L"");
            CStringW strLabel = GetStringCommon(nLabel);
            pBar->FUN_1418e12f0(static_cast<ICastingEventListener*>(this), strLabel, nDuration, false, true,
                                strExtra);
        }
    }
}

// @0x1417f7a70
void StateSummon::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Unk_StreamPoint kPos = DAT_143b01a60;
    m_pOwner->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kPos));
    m_pOwner->vfunc_68(&kPos, fTime, 0, 0, 0);
}

// @0x1417f7af0
void StateSummon::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_14166e0a0();
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
            pBar->FUN_1418e1390();
    }
}

// @0x1417f7b60
// MS2-FUNCTIONAL: the ridee / pet item packet paths are written against the recovered CItem and packet APIs
void StateSummon::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;

    if (m_n48 == 0)
    {
        Unk_StreamPoint kPos = FUN_14166d240(pRider)->FUN_141683290();
        pRider->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kPos));
        if (pRider->FUN_1416749c0() == 0)
            FUN_1417b9460();
        else
            pRider->vfunc_59(2, 0, 0, 0);
        return;
    }

    StateSummonData* pSummon = m_spData;
    if (pSummon != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(
            reinterpret_cast<__int64>(pSummon->m_pSummon));
        if (spItem.get() != 0)
        {
            CItem* pItem = spItem.operator->();
            if (pItem->FUN_140525640() == 0)
            {
                Unk_ItemEquipData* pEquip = pItem->FUN_140527840();
                if (pEquip->FUN_14053cc80())
                {
                    int nItemId = pEquip->FUN_14053dd80();
                    // MS2Ptr<RideOnActionUseItem> local (ctor 0x141532400, operator-> 0x141533230, dtor 0x141532ba0)
                    MS2Ptr<RideOnActionUseItem> spAction(new RideOnActionUseItem());
                    *reinterpret_cast<int*>(reinterpret_cast<char*>(spAction.operator->()) + 0x1c) = nItemId;
                    __int64 nUid = pItem->FUN_140526a50();
                    *reinterpret_cast<__int64*>(reinterpret_cast<char*>(spAction.operator->()) + 0x38) = nUid;
                    char* pCfg = static_cast<char*>(FUN_14124ab20(FUN_1409a8b10()));
                    *(reinterpret_cast<char*>(spAction.operator->()) + 0x28) = pCfg[2];
                    COutPacket packet(static_cast<int>(SendOp::RequestRide), 0);
                    packet.Encode1(0);
                    spAction->vfunc_1(reinterpret_cast<COutputStream*>(&packet));
                    FUN_140710590(packet);
                }
            }
            else
            {
                MS2Ptr<Unk_PetRow> spRow = FUN_14052d210()->FUN_1407290f0(pItem->FUN_140527840()->FUN_14053dc60());
                if (spRow.get() != 0)
                {
                    if (pSummon->m_b18 == 0)
                    {
                        Unk_SummonUid0 uid;
                        uid.m_nUid = pItem->FUN_140526a50();
                        COutPacket packet(static_cast<int>(SendOp::RequestPet), 0);
                        packet.Encode1(0);
                        packet.vfunc_o10_9(&uid, 8);
                        FUN_140710590(packet);
                    }
                    else
                    {
                        Unk_SummonUid3 uid;
                        uid.m_nUid = pItem->FUN_140526a50();
                        COutPacket packet(static_cast<int>(SendOp::RequestPet), 0);
                        packet.Encode1(3);
                        packet.vfunc_o10_9(&uid, 8);
                        FUN_140710590(packet);
                    }
                }
            }
        }
    }
    m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417f8060
void StateSummon::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    if (m_n10 == 0x82)
    {
        m_pOwner->FUN_14166dd20(efd::utf8string("Object_React_A"), m_pOwner->FUN_1416713c0(), false, false);
    }
    else if (m_n10 == 0x83)
    {
        m_pOwner->FUN_14166dd20(efd::utf8string("Emotion_Pet_A"), m_pOwner->FUN_1416713c0(), false, false);
    }
}

// @0x1417f8190
void StateSummon::vfunc_6()
{
    if (FUN_1417b8560() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417f81e0
void StateSummon::OnCastingFinished()
{
    m_n48 = 1;
}

// ---- StateGoToHome ------------------------------------------------------------------------------------------------------

// @0x1417f8200
StateGoToHome::StateGoToHome(PCBase* pOwner) : State(pOwner), m_n48(0) {}

// @0x1417f8270
StateGoToHome::~StateGoToHome() {}

// @0x1417f82b0
// MS2-FUNCTIONAL: the command dispatch call shape differs
void StateGoToHome::vfunc_4(StateData* pData)
{
    m_n48 = 0;
    State::vfunc_4(pData);

    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        if (FUN_14165f100(pRider) != 0)
            FUN_14165f170(pRider);
    }

    m_pOwner->FUN_14166dd20(efd::utf8string("Object_React_A"), 1.0f, false, false);
    int nDuration = FUN_140ad5c50(reinterpret_cast<const char*>(FUN_1401d3200()) + 0x35d0);

    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
        {
            CStringW strExtra(L"");
            CStringW strLabel = GetStringCommon(0x651);
            pBar->FUN_1418e12f0(static_cast<ICastingEventListener*>(this), strLabel, nDuration, false, true,
                                strExtra);
        }
        CStringA strArg("");
        FUN_141276180(s_strReturnHouse6, strArg);
    }
}

// @0x1417f84c0
void StateGoToHome::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
            pBar->FUN_1418e1390();
    }
}

// @0x1417f8520
void StateGoToHome::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
}

// @0x1417f8550
void StateGoToHome::vfunc_6()
{
    if (FUN_1417b8560() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417f85a0
void StateGoToHome::OnCastingFinished()
{
    m_n48 = 1;
}

// ---- StateRecall --------------------------------------------------------------------------------------------------------

// @0x1417f85c0
StateRecall::StateRecall(PCBase* pOwner) : State(pOwner), m_n48(0) {}

// @0x1417f8650
StateRecall::~StateRecall() {}

// @0x1417f86a0
// MS2-FUNCTIONAL: the casting-bar label and the constants access differ in argument setup
void StateRecall::vfunc_4(StateData* pData)
{
    m_n48 = 0;
    State::vfunc_4(pData);

    m_spData.AssignRaw(static_cast<StateRecallData*>(pData));

    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        if (FUN_14165f100(pRider) != 0)
            FUN_14165f170(pRider);
    }

    m_pOwner->FUN_14166dd20(efd::utf8string("Object_React_A"), 1.0f, false, false);
    int nDuration = FUN_140ad5c50(reinterpret_cast<const char*>(FUN_1401d3200()) + 0x3628);

    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
        {
            CStringW strExtra(L"");
            CStringW strLabel = GetStringCommon(0x657);
            pBar->FUN_1418e12f0(static_cast<ICastingEventListener*>(this), strLabel, nDuration, false, true,
                                strExtra);
        }
    }
}

// @0x1417f88b0
void StateRecall::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->FUN_14166e0a0();
    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
            pBar->FUN_1418e1390();
    }
}

// @0x1417f8920
// MS2-FUNCTIONAL: the recall item name lookup is written against the recovered inventory API
void StateRecall::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pRider = FUN_1417b84b0();
    if (pRider == 0)
        return;

    if (m_n48 == 1)
    {
        if (m_spData.get() != 0)
        {
            StateRecallData* pRecall = m_spData;
            if (pRecall->m_p18 == reinterpret_cast<void*>(-1))
            {
                COutPacket packet(static_cast<int>(SendOp::Party), 0);
                packet.Encode1(0x1d);
                FUN_140710590(packet);
            }
            else
            {
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(
                    reinterpret_cast<__int64>(pRecall->m_p18));
                if (spItem.get() != 0)
                {
                    CStringW strName(L"");
                    DAT_143ab2a90.FUN_140a63880(spItem.operator->(), strName);
                }
            }
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }

    Unk_StreamPoint kPos = FUN_14166d240(pRider)->FUN_141683290();
    pRider->vfunc_22(*reinterpret_cast<const efd::Point3*>(&kPos));
    if (pRider->FUN_1416749c0() == 0)
        FUN_1417b9460();
    else
        pRider->vfunc_59(2, 0, 0, 0);
}

// @0x1417f8b60
void StateRecall::vfunc_6()
{
    if (FUN_1417b8560() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417f8bb0
void StateRecall::OnCastingFinished()
{
    m_n48 = 1;
}

// ---- StateSummonIdle ----------------------------------------------------------------------------------------------------

// @0x1417f8bd0
StateSummonIdle::StateSummonIdle(PCBase* pOwner) : State(pOwner), m_n40(0), m_n44(0) {}

// @0x1417f8c60
StateSummonIdle::~StateSummonIdle() {}

// @0x1417f8c90
void StateSummonIdle::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    if (m_n44 == 0)
    {
        m_t48.FUN_140268840();
        m_n44 = 1;
    }
}

// @0x1417f8ce0
void StateSummonIdle::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pPet = FUN_1417b83a0();
    if (pPet != 0 && FUN_140b10360(pPet) != 0)
        FUN_140b11180(pPet);
}

// @0x1417f8d50
void StateSummonIdle::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_n10 = 1;
}

// @0x1417f8d90
// MS2-FUNCTIONAL: the pet-motion dispatch is written against the recovered pet-actor API
void StateSummonIdle::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;

    if (pPet->FUN_14166ce30() != 0 && FUN_141661970(pPet) != 0)
    {
        m_pOwner->FUN_14166dd20(efd::utf8string("Tired_A"), m_pOwner->FUN_1416713c0(), false, false);
        return;
    }

    egf::EntityID kEntity;
    m_pOwner->FUN_14123c460(kEntity);
    int nActorId = FUN_140b7f6a0(FUN_141b6f910(), kEntity);
    switch (m_n10 - 1)
    {
    case 0:
        FUN_1417f9100(this, nActorId);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        FUN_1417f9260(this, nActorId);
        break;
    case 0xe:
        FUN_1417f92c0(this, nActorId);
        break;
    case 0xf:
        FUN_1417f9320(this, nActorId);
        break;
    case 0x10:
        FUN_1417f9380(this, nActorId);
        break;
    case 0x12:
        FUN_1417f9440(this, nActorId);
        break;
    }
}

// @0x1417f8fc0
// MS2-FUNCTIONAL: the sequence-id argument homing differs
void StateSummonIdle::EndOfSequence(NiActorManager* pkManager, unsigned int nSequenceID,
                                    NiControllerSequence* pkSeq, float fEventTime)
{
    (void)pkSeq;
    (void)fEventTime;
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;

    MS2Ptr<Unk_PCBaseComp_aa8> spComp = pPet->vfunc_85();
    if (spComp.get() != 0 && FUN_140f48d40(spComp.operator->()) == 0)
    {
        if (m_n40 != 0)
            m_n10 = 1;
        m_n40 = 0;
    }

    if (m_pOwner->FUN_14166de90(0x27, nSequenceID))
    {
        m_n10 = 1;
        FUN_1417f9100(this, FUN_1409a1a00(pkManager));
    }
    else if (m_pOwner->FUN_14166de90(0x44, nSequenceID))
    {
        m_n10 = 1;
    }
}

// ---- the pet motion helpers ---------------------------------------------------------------------------------------------

// @0x1417f9100
// MS2-FUNCTIONAL: the skill-selection chain is written against the recovered skill-service API
void FUN_1417f9100(StateSummonIdle* pState, int nActorId)
{
    PCBase* pPet = pState->FUN_1417b83a0();
    if (pPet == 0)
        return;
    void* pManager = FUN_140b10360(pPet);
    if (pManager == 0)
        return;

    if (pState->m_t48.FUN_140268870(*FUN_1401d7c10(
            reinterpret_cast<const char*>(FUN_1401d3200()) + 0x7de0)) != 0)
        FUN_1417f94a0(pState, 0x5a);

    if (pState->m_t50.FUN_140268870(*FUN_1401d7c10(
            reinterpret_cast<const char*>(FUN_1401d3200()) + 0x7e90)) != 0)
    {
        void* pList = FUN_140c8b450(FUN_140535320());
        int nIndex = FUN_140b11e90(reinterpret_cast<char*>(pList) + 0x68, pManager);
        if (nIndex != 0)
        {
            MS2Ptr<Unk_ItemEquipData> refSkill;
            FUN_140c892c0(FUN_140c8b430(FUN_140535320()), refSkill, nIndex);
            if (FUN_1401c0050(refSkill, 0))
                FUN_1417f94a0(pState, 0x5f);
        }
    }

    if (pState->m_pOwner->FUN_14166de90(0, nActorId) == 0)
        pState->m_pOwner->FUN_14166dda0(0);
}

// @0x1417f9260
void FUN_1417f9260(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x27, nActorId) == 0)
        pState->m_pOwner->FUN_14166dda0(0x27);
    FUN_1417f94a0(pState, 0x5c);
}

// @0x1417f92c0
void FUN_1417f92c0(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x42, nActorId) == 0)
        pState->m_pOwner->FUN_14166dda0(0x42);
    FUN_1417f94a0(pState, 0x5d);
}

// @0x1417f9320
void FUN_1417f9320(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x43, nActorId) == 0)
        pState->m_pOwner->FUN_14166dda0(0x43);
    FUN_1417f94a0(pState, 0x5e);
}

// @0x1417f9380
void FUN_1417f9380(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x44, nActorId) == 0)
        pState->m_pOwner->FUN_14166dd20(efd::utf8string("Revive_A"), pState->m_pOwner->FUN_1416713c0(), false,
                                        false);
    FUN_1417f94a0(pState, 0x60);
}

// @0x1417f9440
void FUN_1417f9440(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x45, nActorId) == 0)
        pState->m_pOwner->FUN_14166dda0(0x45);
    FUN_1417f94a0(pState, 0x61);
}

// @0x1417f94a0
void FUN_1417f94a0(StateSummonIdle* pState, int nAnimId)
{
    PCBase* pPet = pState->FUN_1417b83a0();
    if (pPet != 0 && pState->m_n40 == 0)
    {
        FUN_140b114e0(pPet, nAnimId);
        pState->m_n40 = 1;
    }
}

// ---- StateSummonRevive --------------------------------------------------------------------------------------------------

// @0x1417f9500
StateSummonRevive::StateSummonRevive(PCBase* pOwner) : State(pOwner), m_n40(3000) {}

// @0x1417f9570
void StateSummonRevive::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_timer.FUN_140868750(m_n40);
}

// @0x1417f95c0
void StateSummonRevive::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pPet = FUN_1417b83d0();
    if (pPet != 0 && m_timer.FUN_140868ba0() != 0)
    {
        m_timer.FUN_1408687f0();
        if (pPet->FUN_14166ce30() != 0 && FUN_141661970(pPet) == 0)
        {
            COutPacket packet(static_cast<int>(SendOp::Revival), 0);
            packet.Encode1(3);
            packet.Encode4(FUN_14123c580(m_pOwner));
            FUN_140710590(packet);
        }
    }
}

// @0x1417f96c0
void StateSummonRevive::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_timer.FUN_1408687f0();
}

// @0x1417f9700
// MS2-FUNCTIONAL: the pet-actor access chain is written against the recovered pet-actor API
void StateSummonRevive::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;

    if (pPet->FUN_14166ce30() != 0 && FUN_141661970(pPet) != 0)
    {
        m_pOwner->FUN_14166dd20(efd::utf8string("Tired_A"), m_pOwner->FUN_1416713c0(), false, false);
        return;
    }

    egf::EntityID kEntity;
    m_pOwner->FUN_14123c460(kEntity);
    int nActorId = FUN_140b7f6a0(FUN_141b6f910(), kEntity);
    if (m_pOwner->FUN_14166de90(0, nActorId) == 0)
        m_pOwner->FUN_14166dda0(0);
}

// ---- StateSummonExpire --------------------------------------------------------------------------------------------------

// @0x1417f9860
StateSummonExpire::StateSummonExpire(PCBase* pOwner) : State(pOwner) {}

// @0x1417f98c0
void StateSummonExpire::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    Unk_140517b00 tick;
    m_t40 = tick;
}

// @0x1417f9900
// MS2-FUNCTIONAL: the pet item lookup is written against the recovered item API
void StateSummonExpire::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;

    MS2Ptr<Unk_PetRow> spRow = reinterpret_cast<Unk_SmPet*>(pPet)->FUN_140b102b0();
    if (spRow == 0)
        return;
    if (m_t40.FUN_140268870(*FUN_1401d7c10(reinterpret_cast<const char*>(FUN_1401d3200()) + 0x7e38)) != 0)
        FUN_140b114e0(pPet, 0x5b);
}

// @0x1417f99c0
void StateSummonExpire::vfunc_5(int n)
{
    State::vfunc_5(n);
}

// ---- StateSummonItemPick ------------------------------------------------------------------------------------------------

// @0x1417f99f0
StateSummonItemPick::StateSummonItemPick(PCBase* pOwner) : State(pOwner) {}

// @0x1417f9a30
void StateSummonItemPick::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
}

// @0x1417f9a60
void StateSummonItemPick::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (FUN_1417b83d0() == 0)
        return;
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;
    void* pField = FUN_141bd1a50(FUN_1403ed2d0(), pPet);
    if (pField == 0 || FUN_140b12380(pField) == 0)
        return;
    int nId = FUN_14123c580(pPet);
    FUN_141191330(pField, nId);
    FUN_141190900(pField, nId);
}

// @0x1417f9b20
void StateSummonItemPick::vfunc_5(int n)
{
    State::vfunc_5(n);
}

// ---- StateSummonPortal --------------------------------------------------------------------------------------------------

// @0x1417f9b50
StateSummonPortal::StateSummonPortal(PCBase* pOwner) : State(pOwner) {}

// @0x1417f9b90
void StateSummonPortal::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_pOwner->FUN_14166dda0(0);
}

// ---- the constant state ids ---------------------------------------------------------------------------------------------

// @0x1417fa0c0
int StateGoToHome::vfunc_20() { return 1; }

// @0x1417fa0d0
int StateRecall::vfunc_20() { return 1; }

// @0x1417fa0e0
int StateSummon::vfunc_20() { return 1; }

// @0x1417fa0f0
int StateRecall::vfunc_1() { return 0x2c; }

// @0x1417fa100
int StateSummon::vfunc_1() { return 0x26; }

// @0x1417fa110
int StateSummonExpire::vfunc_1() { return 0x31; }

// @0x1417fa120
int StateSummonItemPick::vfunc_1() { return 0x32; }

// @0x1417fa130
int StateSummonPortal::vfunc_1() { return 0x38; }

// @0x1417fa140
int StateSummonRevive::vfunc_1() { return 0x30; }
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb7f90-0x142cb8040 .text$yd
