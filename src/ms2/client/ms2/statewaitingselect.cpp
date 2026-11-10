// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateWaitingSelect, the actor state of a player in the
// equipment select screen: plays the "Equip_Change_<part>_A" animation of the part being changed. See statewaitingselect.h.
// MS2-UNIT: ?\statewaitingselect.cpp
// MS2-RANGE: 0x1417fea70-0x1417ff730 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statewaitingselect.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "statewaitingselect.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/weaponactiontable.h"   // C3: CWeaponAction (PC::GetWeaponAction)
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------



// The skill request a CSkillRecord is built from (same view as pcbase.cpp).
struct Unk_InventorySkillRequest
{
    Unk_InventorySkillRequest(int, unsigned short);                 // 0x141763fa0
    int skill;
    unsigned short level;
    unsigned __int64 tick;
    unsigned serial, unknown14;
    efd::Point3 origin;                                             // +0x18
    efd::Point3 direction;                                          // +0x24
    float fValue;                                                   // +0x30
    unsigned unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};
MS2_CHECK_SIZE(Unk_InventorySkillRequest, 0x48);
class CSkillRecord : public CPtred                                  // RTTI, 0x1c0 (?\skillrecord.cpp)
{
public:
    CSkillRecord();                                                 // 0x141759260
    bool Init(Unk_InventorySkillRequest& kReq);
    char m_pad_18[0x1c0 - 0x18];
};
MS2_CHECK_SIZE(CSkillRecord, 0x1c0);

// @0x1417fea70
StateWaitingSelect::StateWaitingSelect(PCBase* pOwner) : State(pOwner)
{
}

// @0x1417feab0
StateWaitingSelect::~StateWaitingSelect()
{
}

// @0x1417feae0
void StateWaitingSelect::vfunc_2(int n)
{
    PCBase* pPC = FUN_1417b8370();
    if (pPC == 0)
        return;
    switch (n)
    {
    case 0x4d:
        m_n10 = n;
        m_pOwner->SetEmotion(0);
        m_pOwner->PlayAnimation("Equip_Change_Idle_A", 1.0f, false, false);
        m_pOwner->FUN_14166f8f0(0, 1);
        break;
    case 0x4c:
        if (m_n10 != n)
        {
            CString strModel = m_pOwner->FUN_14166dc50();
            m_n10 = n;
            pPC->SetEmotion(0);
            bool bSame = (strModel == "Equip_Change_Cap_A");
            pPC->PlayAnimation("Equip_Change_Cap_A", 1.0f, bSame, false);
        }
        break;
    case 0x4e:
        if (m_n10 != n)
        {
            CString strModel = m_pOwner->FUN_14166dc50();
            m_n10 = n;
            pPC->SetEmotion(0);
            bool bSame = (strModel == "Equip_Change_Body_A");
            pPC->PlayAnimation("Equip_Change_Body_A", 1.0f, bSame, false);
        }
        break;
    case 0x4f:
        if (m_n10 != n)
        {
            CString strModel = m_pOwner->FUN_14166dc50();
            m_n10 = n;
            pPC->SetEmotion(0);
            bool bSame = (strModel == "Equip_Change_Head_A");
            pPC->PlayAnimation("Equip_Change_Head_A", 1.0f, bSame, false);
        }
        break;
    case 0x50:
        FUN_1417ff590(&n, "Equip_Change_Hair_A");
        break;
    case 0x54:
        m_n10 = n;
        pPC->SetEmotion(1);
        reinterpret_cast<PC*>(pPC)->UpdateWeaponAction();
        {
            MS2Ptr<CWeaponAction> spEquip = reinterpret_cast<PC*>(pPC)->GetWeaponAction();
            if (spEquip.get() != 0)
            {
                Unk_InventorySkillRequest kReq(spEquip->m_nNormalAttack, 1);
                kReq.origin = pPC->vfunc_18();
                kReq.fValue = pPC->vfunc_20().z;
                MS2Ptr<CSkillRecord> spSkill(new CSkillRecord);
                if (spSkill->Init(kReq))
                    pPC->vfunc_102(spSkill);
            }
        }
        break;
    case 0x55:
        m_n10 = n;
        pPC->SetEmotion(1);
        reinterpret_cast<PC*>(pPC)->UpdateWeaponAction();
        pPC->PlayAnimationById(1);
        break;
    case 0x51:
        if (m_n10 != n)
        {
            CString strModel = m_pOwner->FUN_14166dc50();
            m_n10 = n;
            pPC->SetEmotion(0);
            bool bSame = (strModel == "Equip_Change_Glove_A");
            pPC->PlayAnimation("Equip_Change_Glove_A", 1.0f, bSame, false);
        }
        break;
    case 0x52:
        if (m_n10 != n)
        {
            CString strModel = m_pOwner->FUN_14166dc50();
            m_n10 = n;
            pPC->SetEmotion(0);
            bool bSame = (strModel == "Equip_Change_Mantle_A");
            pPC->PlayAnimation("Equip_Change_Mantle_A", 1.0f, bSame, false);
        }
        break;
    case 0x53:
        if (m_n10 != n)
        {
            CString strModel = m_pOwner->FUN_14166dc50();
            m_n10 = n;
            pPC->SetEmotion(0);
            bool bSame = (strModel == "Equip_Change_Shoes_A");
            pPC->PlayAnimation("Equip_Change_Shoes_A", 1.0f, bSame, false);
        }
        break;
    }
}

// @0x1417ff2e0
void StateWaitingSelect::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_pOwner->AddStateFlags(0x10);
    m_pOwner->vfunc_22(efd::Point3::ZERO);
    vfunc_2(0x4d);
}

// @0x1417ff370
void StateWaitingSelect::vfunc_5(int n)
{
    State::vfunc_5(n);
    m_pOwner->RemoveStateFlags(0x10);
    m_pOwner->vfunc_22(efd::Point3::ZERO);
}

// @0x1417ff3f0
void StateWaitingSelect::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kMove = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417ff470
void StateWaitingSelect::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_n10 == 0x4c)
        vfunc_2(0x4d);
    else if (m_n10 == 0x4e)
        vfunc_2(0x4d);
    else if (m_n10 == 0x4f)
        vfunc_2(0x4d);
    else if (m_n10 == 0x50)
        vfunc_2(0x4d);
    else if (m_n10 == 0x51)
        vfunc_2(0x4d);
    else if (m_n10 == 0x52)
        vfunc_2(0x4d);
    else if (m_n10 == 0x53)
        vfunc_2(0x4d);
}

// @0x1417ff590
void StateWaitingSelect::FUN_1417ff590(int* pnSub, const CString& strAnim)
{
    if (m_n10 != *pnSub)
    {
        PCBase* pPC = FUN_1417b8370();
        if (pPC == 0)
            return;
        CString strModel = m_pOwner->FUN_14166dc50();
        m_n10 = *pnSub;
        pPC->SetEmotion(0);
        bool bSame = strModel == strAnim;
        pPC->PlayAnimation(strAnim.GetString(), 1.0f, bSame, false);
    }
}

// @0x1417ff6c0
int StateWaitingSelect::vfunc_15()
{
    if (m_n10 != 0x55)
        return 0;
    return 1;
}

// @0x1417ff720
int StateWaitingSelect::vfunc_1()
{
    return 0xe;
}
