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
#include <efd/Point3.h>

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
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/placeholder/cgameoption.h"  // C3: CGameOption::FUN_140b123b0
#include "ms2/client/ms2/uihudentity.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/placeholder/ccpetinfopacket.h"
#include "ms2/placeholder/crideedata.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// CItem::FUN_140527840's record (item.cpp owns the real one).
class Unk_ItemEquipData : public CItemData { };

// The item-data rows the summon packet path reads (item.cpp owns the real MS2Ptr instances).
class Unk_PCBaseComp_aa8 : public CPtred { };

// The player inventory (global 0x143ab2a90): item lookup by uid and the item's name.
extern Unk_Inventory g_143ab2a90;

// The world service, its effect manager and the field objects it hands out.
class WorldService   // C3: member view for the former free stand-ins
{
public:
    int FUN_141bd1a10(class Unk_WsC_GameObj*);
    class Unk_WsC_GameObj* FUN_141bd1a50(class Unk_WsC_GameObj*);
    static class WorldService* GetInstance();
};
class CEffectService;
class CEffectService   // C3: member view for the former free stand-ins
{
public:
    unsigned int InsertEffect(class Unk_EffectTarget&);
};
class CDropItem   // C3: member view for the former free stand-ins
{
public:
    void FUN_141190900(int);
    void FUN_141191330(int);
    class CItem* FUN_140b12380();                // the dropped item
};

// The actor registry the pet state queries by entity id.
namespace egmAnimation { class AnimationService; }
egmAnimation::AnimationService* FUN_141b6f910();                                                     // 0x141b6f910
int FUN_140b7f6a0(void* pRegistry, const egf::EntityID& kEntity);          // 0x140b7f6a0 the actor id at that key

// The client settings / skill services.
class CGameOption;
class Unk_BreakSelected* FUN_140535320();   // C3: was FUN_140535320
class CPetManager   // C3: member view for the former free stand-ins
{
public:
    class Unk_PetManagerEmpty* FUN_140c8b430();
    MS2Ptr<CItem> FindItemById(int nItemId);                // 0x140c892c0
    CCPetInfoPacket::Info* GetInfo();                       // &m_info
};

// The pet actor and its manager.
class CPet   // C3: member view for the former free stand-ins
{
public:
    class PCBase* FUN_140b10360();
    int FUN_140b11180();
    void FUN_140b114e0(int);
    MS2Ptr<CPetData> GetRow();                                           // the pet's row (by value)
    PCBase* FUN_140b10320();                                               // the owner
};
int FUN_140b11e90(struct Unk_PetFoodBook*, class PCBase*);   // C3: was FUN_140b11e90

// The client constants table and its Value<T> accessors.
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
class Unk_SSGConstValue   // C3: member view for the former free stand-ins
{
public:
    int FUN_140ad5c50();
};

// The casting bar (statehomeconvenient.cpp / statenurturing.cpp own the real dialog).
class UICastingBar : public UIObject
{
public:
    void StartCastingText(class ICastingEventListener* pListener, const CStringW& strLabel, int nMs, bool bA, bool bB,
                       const CStringW& strExtra);                          // show
    void FUN_1418e1390();                                                  // cancel
};
UICastingBar* FUN_140ac2270(int nId);                                      // 0x140ac2270 the casting bar dialog
CStringW GetStringCommon(int nId);                                           // 0x14028de60 the string-table text of an id
int FUN_141276180(const CStringA& strCommand, const CStringA& strArg);    // 0x141276180 run a client command

// The pet's position buffer (statehomemade.cpp owns the real one).
class Unk_PCMove { public: Vector3 FUN_141683290(); };   // C3: view of the real class (unit_141682f80)
class Unk_SmBuffMgr { public: };
// PCBase vtable view: slot 22 takes the position by value (the exe copies it to a 16-aligned temp)
class Unk_SmPointSlots
{
public:
#define MS2_SM_SLOTS(a, b, c, d, e) virtual void vfunc_##a(); virtual void vfunc_##b(); virtual void vfunc_##c(); \
    virtual void vfunc_##d(); virtual void vfunc_##e();
    MS2_SM_SLOTS(0, 1, 2, 3, 4) MS2_SM_SLOTS(5, 6, 7, 8, 9) MS2_SM_SLOTS(10, 11, 12, 13, 14) MS2_SM_SLOTS(15, 16, 17, 18, 19)
#undef MS2_SM_SLOTS
    virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(efd::Point3 kPos);                                // 22
};

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
void FUN_1401fea90(unsigned char* payload, COutputStream& stream);         // 0x1401fea90 writes the uid (subtype 0)
void FUN_1401febb0(unsigned char* payload, COutputStream& stream);         // 0x1401febb0 writes the uid (subtype 3)

#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60

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
StateSummon::StateSummon(PCBase* pOwner) : State(pOwner)
{
    m_n48 = 0;
}

// @0x1417f75e0
StateSummon::~StateSummon() {}

// @0x1417f7630
// MS2-FUNCTIONAL: the ridee / pet item inspection chain is written against the recovered CItem API
void StateSummon::vfunc_4(StateData* pData)
{
    m_n48 = 0;
    State::vfunc_4(pData);

    int nDuration = ((class Unk_SSGConstValue*)(void const*)(reinterpret_cast<const char*>(((void*)GetClientConstants())) + 0x33c0))->FUN_140ad5c50();
    int nLabel = 0;

    m_spData.AssignRaw(dynamic_cast<StateSummonData*>(pData));
    if (m_spData)
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(
            reinterpret_cast<__int64>(m_spData.get()->m_pSummon));
        if (spItem.get() != 0)
        {
            if (spItem->IsPetItem() != 0)
            {
                int nPetId = spItem->FUN_140527840()->GetPetId();
                MS2Ptr<CPetData> spRow = TSingleton<CPetDataTable>::GetInstance()->Find(nPetId);
                if (spRow.get() != 0)
                {
                    nLabel = 0x64f;
                    nDuration = *reinterpret_cast<Common::Constants::Value<unsigned int>*>(reinterpret_cast<char*>(((void*)GetClientConstants())) + 0x7d30)->Get();
                }
                m_n10 = 0x83;
            }
            else if (spItem->FUN_140527840()->IsRideItem())
            {
                int nRideeId = spItem->FUN_140527840()->GetRideeId();
                MS2SvrPtr<CRideeData> spRow = FUN_1407844b0(nRideeId);
                if (spRow != 0)
                {
                    nLabel = 0x650;
                    nDuration = static_cast<unsigned int>(
                        spRow.get()->m_basic.m_fSummonCastTime);
                }
                m_n10 = 0x82;
            }
        }
    }

    if (m_n10 == 0x83)
    {
        BOOL bPreload = TRUE;
        if (FUN_1417b8560() == 0)
        {
            if (*reinterpret_cast<unsigned char*>(static_cast<char*>((void*)TSingleton<CGameOption>::GetInstance()->FUN_140b123b0()) + 0x12) != 0)
                bPreload = FALSE;
        }
        if (bPreload)
        {
            // A NoticeMessage (0x70 bytes): the field id goes to m_nObject, the owner's object id to SetActor.
            NoticeMessage msg;
            msg.m_strName = "CH/Common/Eff_PetOn.xml";
            msg.m_nObject = ((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd1a10((class Unk_WsC_GameObj*)(m_pOwner));
            msg.SetActor(reinterpret_cast<GameObject*>(m_pOwner)->GetObjectId());
            ((class CEffectService*)(void*)((void*)TSingleton<CEffectService>::GetInstance()))->InsertEffect(*(class Unk_EffectTarget*)&static_cast<class NoticeMessage&>(msg));
        }
    }

    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        if (((void*)(reinterpret_cast<PC*>(pRider)->GetHeldItem())) != 0)
            reinterpret_cast<PC*>(pRider)->SendRequestCube();
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
        {
            CStringW strExtra(L"");
            pBar->StartCastingText(static_cast<ICastingEventListener*>(this), GetStringCommon(nLabel), nDuration, false,
                                true, strExtra);
        }
    }
}

// @0x1417f7a70
void StateSummon::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Vector3 kPos = DAT_143b01a60;
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

    if (m_n48 != 0)
    {
        if (m_spData)
        {
            MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(
                reinterpret_cast<__int64>(m_spData.get()->m_pSummon));
            if (spItem.get() != 0)
            {
                if (spItem->IsPetItem() != 0)
                {
                    int nPetId = spItem->FUN_140527840()->GetPetId();
                    MS2Ptr<CPetData> spRow = TSingleton<CPetDataTable>::GetInstance()->Find(nPetId);
                    if (spRow.get() != 0)
                    {
                        if (m_spData.get()->m_b18 != 0)
                        {
                            Unk_SummonUid3 uid;
                            uid.m_nUid = spItem->GetItemUid();
                            COutPacket packet(static_cast<int>(SendOp::RequestPet), 0);
                            packet.Encode1(3);
                            FUN_1401febb0(reinterpret_cast<unsigned char*>(&uid),
                                          *reinterpret_cast<COutputStream*>(&packet));
                            FUN_140710590(packet);
                        }
                        else
                        {
                            Unk_SummonUid0 uid;
                            uid.m_nUid = spItem->GetItemUid();
                            COutPacket packet(static_cast<int>(SendOp::RequestPet), 0);
                            packet.Encode1(0);
                            FUN_1401fea90(reinterpret_cast<unsigned char*>(&uid),
                                          *reinterpret_cast<COutputStream*>(&packet));
                            FUN_140710590(packet);
                        }
                    }
                }
                else if (spItem->FUN_140527840()->IsRideItem())
                {
                    int nItemId = spItem->FUN_140527840()->GetRideeId();
                    MS2SvrPtr<CRideeData> spRow = FUN_1407844b0(nItemId);
                    if (spRow != 0)
                    {
                        // MS2Ptr<RideOnActionUseItem> local (ctor 0x141532400, operator-> 0x141533230, dtor 0x141532ba0)
                        MS2Ptr<RideOnActionUseItem> spAction(new RideOnActionUseItem());
                        *reinterpret_cast<int*>(reinterpret_cast<char*>(spAction.operator->()) + 0x1c) = nItemId;
                        *reinterpret_cast<__int64*>(reinterpret_cast<char*>(spAction.operator->()) + 0x38) =
                            spItem->GetItemUid();
                        *(reinterpret_cast<char*>(spAction.operator->()) + 0x28) =
                            *(static_cast<char*>(((void*)((class CGameOption*)(void*)((void*)TSingleton<CGameOption>::GetInstance()))->FUN_14124ab20())) + 2);
                        COutPacket packet(static_cast<int>(SendOp::RequestRide), 0);
                        packet.Encode1(0);
                        spAction->vfunc_1(reinterpret_cast<COutputStream*>(&packet));
                        FUN_140710590(packet);
                    }
                }
            }
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }

    Unk_SmBuffMgr* pBuff = ((Unk_SmBuffMgr*)(reinterpret_cast<PCBase*>(pRider)->FUN_14166d240()));
    reinterpret_cast<Unk_SmPointSlots*>(pRider)->vfunc_22(
        reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Unk_PCMove*>(pBuff)->FUN_141683290())));
    if (m_pOwner->FUN_1416749c0())
        pRider->vfunc_59(2, 0, 0, 0);
    else
        FUN_1417b9460();
}

// @0x1417f8060
void StateSummon::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    switch (m_n10)
    {
    case 0x82:
        m_pOwner->PlayAnimation("Object_React_A", m_pOwner->FUN_1416713c0(), false, false);
        break;
    case 0x83:
        m_pOwner->PlayAnimation("Emotion_Pet_A", m_pOwner->FUN_1416713c0(), false, false);
        break;
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
StateGoToHome::StateGoToHome(PCBase* pOwner) : State(pOwner)
{
    m_n48 = 0;
}

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
        if (((void*)(reinterpret_cast<PC*>(pRider)->GetHeldItem())) != 0)
            reinterpret_cast<PC*>(pRider)->SendRequestCube();
    }

    int nDuration = ((class Unk_SSGConstValue*)(void const*)(reinterpret_cast<const char*>(((void*)GetClientConstants())) + 0x35d0))->FUN_140ad5c50();
    efd::utf8string strAnim("Object_React_A");
    m_pOwner->PlayAnimation(strAnim, 1.0f, false, false);

    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
        {
            CStringW strExtra(L"");
            pBar->StartCastingText(static_cast<ICastingEventListener*>(this), GetStringCommon(0x651), nDuration, false,
                                true, strExtra);
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
StateRecall::StateRecall(PCBase* pOwner) : State(pOwner)
{
    m_n48 = 0;
}

// @0x1417f8650
StateRecall::~StateRecall() {}

// @0x1417f86a0
// MS2-FUNCTIONAL: the casting-bar label and the constants access differ in argument setup
void StateRecall::vfunc_4(StateData* pData)
{
    m_n48 = 0;
    State::vfunc_4(pData);

    m_spData.AssignRaw(dynamic_cast<StateRecallData*>(pData));

    MyPC* pRider = FUN_1417b84b0();
    if (pRider != 0)
    {
        if (((void*)(reinterpret_cast<PC*>(pRider)->GetHeldItem())) != 0)
            reinterpret_cast<PC*>(pRider)->SendRequestCube();
    }

    int nDuration = ((class Unk_SSGConstValue*)(void const*)(reinterpret_cast<const char*>(((void*)GetClientConstants())) + 0x3628))->FUN_140ad5c50();
    efd::utf8string strAnim("Object_React_A");
    m_pOwner->PlayAnimation(strAnim, 1.0f, false, false);

    if (FUN_1417b8560() != 0)
    {
        UICastingBar* pBar = FUN_140ac2270(0x4e72);
        if (pBar != 0)
        {
            CStringW strExtra(L"");
            pBar->StartCastingText(static_cast<ICastingEventListener*>(this), GetStringCommon(0x657), nDuration, false,
                                true, strExtra);
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
        if (m_spData)
        {
            void* pSummon = m_spData.get()->m_p18;
            if (pSummon == reinterpret_cast<void*>(-1))
            {
                COutPacket packet(static_cast<int>(SendOp::Party), 0);
                packet.Encode1(0x1d);
                FUN_140710590(packet);
            }
            else
            {
                MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(
                    reinterpret_cast<__int64>(pSummon));
                if (spItem.get() != 0)
                {
                    CStringW strName(L"");
                    g_143ab2a90.FUN_140a63880(spItem.operator->(), strName);
                }
            }
        }
        m_pOwner->vfunc_59(1, 0, 0, 0);
        return;
    }

    Unk_SmBuffMgr* pBuff = ((Unk_SmBuffMgr*)(reinterpret_cast<PCBase*>(pRider)->FUN_14166d240()));
    reinterpret_cast<Unk_SmPointSlots*>(pRider)->vfunc_22(
        reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Unk_PCMove*>(pBuff)->FUN_141683290())));
    if (m_pOwner->FUN_1416749c0())
        pRider->vfunc_59(2, 0, 0, 0);
    else
        FUN_1417b9460();
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
        m_t48.Init();
        m_n44 = 1;
    }
}

// @0x1417f8ce0
void StateSummonIdle::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;
    void* pManager = ((void*)((class CPet*)(class PCBase*)(pPet))->FUN_140b10360());
    if (pManager == 0)
        return;
    ((class CPet*)(void*)(pPet))->FUN_140b11180();
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
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;
    PCBase* pOwner = reinterpret_cast<CPet*>(pPet)->FUN_140b10320();
    if (pOwner == 0)
        return;

    if (pOwner->IsDead() != 0 && reinterpret_cast<PC*>(pOwner)->IsRevivalBlocked() != 0)
    {
        m_pOwner->PlayAnimation("Tired_A", m_pOwner->FUN_1416713c0(), false, false);
        return;
    }

    int nActorId = FUN_140b7f6a0(reinterpret_cast<void*>(FUN_141b6f910()), m_pOwner->GetEntityID());
    switch (m_n10)
    {
    case 1:
        FUN_1417f9100(this, nActorId);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        FUN_1417f9260(this, nActorId);
        break;
    case 0xf:
        FUN_1417f92c0(this, nActorId);
        break;
    case 0x10:
        FUN_1417f9320(this, nActorId);
        break;
    case 0x11:
        FUN_1417f9380(this, nActorId);
        break;
    case 0x13:
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
    if ((spComp.get() ? true : false) && reinterpret_cast<UIHudEntity::Entity*>(spComp.operator->())->FUN_140f48d40() == 0)
    {
        if (m_n40 != 0)
            m_n10 = 1;
        m_n40 = 0;
    }

    if (m_pOwner->FUN_14166de90(0x27, nSequenceID))
    {
        m_n10 = 1;
        int nMotion = static_cast<NiActorManager*>(pkManager)->GetTargetAnimation();
        FUN_1417f9100(this, nMotion);
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
    void* pManager = ((void*)((class CPet*)(class PCBase*)(pPet))->FUN_140b10360());
    if (pManager != 0)
    {
        if (pState->m_t48.Check(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(reinterpret_cast<char*>(((void*)GetClientConstants())) + 0x7de0)->Get()) != 0)
            FUN_1417f94a0(pState, 0x5a);

        if (pState->m_t50.Check(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(reinterpret_cast<char*>(((void*)GetClientConstants())) + 0x7e90)->Get()) != 0)
        {
            int nIndex = FUN_140b11e90((struct Unk_PetFoodBook*)(reinterpret_cast<char*>(reinterpret_cast<CPetManager*>(FUN_140535320())->GetInfo()) + 0x68), (class PCBase*)(pManager));
            if (nIndex != 0)
            {
                MS2Ptr<CItem> refSkill = reinterpret_cast<CPetManager*>(((class CPetManager*)(void*)(((void*)FUN_140535320())))->FUN_140c8b430())->FindItemById(nIndex);
                if (refSkill.operator==(0))
                    FUN_1417f94a0(pState, 0x5f);
            }
        }
    }

    if (pState->m_pOwner->FUN_14166de90(0, nActorId) == 0)
        pState->m_pOwner->PlayAnimationById(0);
}

// @0x1417f9260
void FUN_1417f9260(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x27, nActorId) == 0)
        pState->m_pOwner->PlayAnimationById(0x27);
    FUN_1417f94a0(pState, 0x5c);
}

// @0x1417f92c0
void FUN_1417f92c0(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x42, nActorId) == 0)
        pState->m_pOwner->PlayAnimationById(0x42);
    FUN_1417f94a0(pState, 0x5d);
}

// @0x1417f9320
void FUN_1417f9320(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x43, nActorId) == 0)
        pState->m_pOwner->PlayAnimationById(0x43);
    FUN_1417f94a0(pState, 0x5e);
}

// @0x1417f9380
void FUN_1417f9380(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x44, nActorId) == 0)
        pState->m_pOwner->PlayAnimation("Revive_A", pState->m_pOwner->FUN_1416713c0(), false,
                                        false);
    FUN_1417f94a0(pState, 0x60);
}

// @0x1417f9440
void FUN_1417f9440(StateSummonIdle* pState, int nActorId)
{
    if (pState->m_pOwner->FUN_14166de90(0x45, nActorId) == 0)
        pState->m_pOwner->PlayAnimationById(0x45);
    FUN_1417f94a0(pState, 0x61);
}

// @0x1417f94a0
void FUN_1417f94a0(StateSummonIdle* pState, int nAnimId)
{
    PCBase* pPet = pState->FUN_1417b83a0();
    if (pPet == 0)
        return;
    if (pState->m_n40 != 0)
        return;
    ((class CPet*)(class PCBase*)(pPet))->FUN_140b114e0(nAnimId);
    pState->m_n40 = 1;
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
    if (pPet == 0)
        return;
    if (m_timer.FUN_140868c00() != 0)    // expired (0x140868c00), not still running
    {
        m_timer.FUN_1408687f0();
        if (pPet->IsDead() != 0 && reinterpret_cast<PC*>(pPet)->IsRevivalBlocked() == 0)
        {
            COutPacket packet(static_cast<int>(SendOp::Revival), 0);
            packet.Encode1(3);
            packet.Encode4(reinterpret_cast<GameObject*>(m_pOwner)->GetObjectId());
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
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;
    PCBase* pOwner = reinterpret_cast<CPet*>(pPet)->FUN_140b10320();
    if (pOwner == 0)
        return;

    if (pOwner->IsDead() != 0 && reinterpret_cast<PC*>(pOwner)->IsRevivalBlocked() != 0)
    {
        m_pOwner->PlayAnimation("Tired_A", m_pOwner->FUN_1416713c0(), false, false);
        return;
    }

    int nActorId = FUN_140b7f6a0(reinterpret_cast<void*>(FUN_141b6f910()), m_pOwner->GetEntityID());
    if (m_pOwner->FUN_14166de90(0, nActorId) == 0)
        m_pOwner->PlayAnimationById(0);
}

// ---- StateSummonExpire --------------------------------------------------------------------------------------------------

// @0x1417f9860
StateSummonExpire::StateSummonExpire(PCBase* pOwner) : State(pOwner) {}

// @0x1417f98c0
void StateSummonExpire::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_t40 = Unk_IntervalTimer();
}

// @0x1417f9900
// MS2-FUNCTIONAL: the pet item lookup is written against the recovered item API
void StateSummonExpire::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    PCBase* pPet = FUN_1417b83a0();
    if (pPet == 0)
        return;

    MS2Ptr<CPetData> spRow = reinterpret_cast<CPet*>(pPet)->GetRow();
    if (spRow == 0)
        return;
    if (m_t40.Check(*reinterpret_cast<Common::Constants::Value<unsigned int>*>(reinterpret_cast<char*>(((void*)GetClientConstants())) + 0x7e38)->Get()) != 0)
        ((class CPet*)(class PCBase*)(pPet))->FUN_140b114e0(0x5b);
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
    if (pPet != 0)
    {
        void* pField = ((void*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd1a50((class Unk_WsC_GameObj*)(pPet)));
        if (pField == 0)
            return;
        void* pDrop = ((class CDropItem*)(void*)(pField))->FUN_140b12380();
        if (pDrop == 0)
            return;
        ((class CDropItem*)(void*)(pField))->FUN_141191330(reinterpret_cast<GameObject*>(pPet)->GetObjectId());
        ((class CDropItem*)(void*)(pField))->FUN_141190900(reinterpret_cast<GameObject*>(pPet)->GetObjectId());
    }
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
    m_pOwner->PlayAnimationById(0);
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
