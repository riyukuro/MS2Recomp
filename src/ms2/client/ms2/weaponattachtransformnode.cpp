// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WeaponAttachTransformNode: see weaponattachtransformnode.h.
// MS2-UNIT: ?\weaponattachtransformnode.cpp
// MS2-RANGE: 0x141b76a90-0x141b77250 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\weaponattachtransformnode.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "weaponattachtransformnode.h"
#include <NiCollisionObject.h>
#include <NiTransform.h>
#include "ms2/client/ms2/orbmovement.h"
#include "ms2/placeholder/cmainsystem.h"
#include "hook/ms2hook.h"

CMainSystem* FUN_14086d260();                               // TSingleton<CMainSystem>::GetInstance (out of line in the exe)

// @0x141b76a90
NiObject* WeaponAttachTransformNode::CreateClone(NiCloningProcess& kCloning)
{
    WeaponAttachTransformNode* pkClone = new (efd::MemHint(efd::MemHint::NONE)) WeaponAttachTransformNode;
    CopyMembers(pkClone, kCloning);
    return pkClone;
}
MS2_REPLACE_METHOD(0x141B76A90, WeaponAttachTransformNode, CreateClone, 146, 0xE576541C);

// @0x141b76b30
void WeaponAttachTransformNode::CopyMembers(WeaponAttachTransformNode* pkDest, NiCloningProcess& kCloning)
{
    if (pkDest != 0)
    {
        LightUnaffectedNode::CopyMembers(pkDest, kCloning);
        if (m_spMovement.get())
            pkDest->SetMovement(m_spMovement->vfunc_1());
        pkDest->SetFollowNode(m_pFollow);
        pkDest->SetMode(m_nMode);
        pkDest->SetUseMovement(m_bUseMovement);
        pkDest->SetBasePosition(m_kBasePos);
        pkDest->SetBaseRotate(m_kBaseRotate);
    }
}
MS2_REPLACE_METHOD(0x141B76B30, WeaponAttachTransformNode, CopyMembers, 245, 0x3252F5ED);

// @0x141b76c30
WeaponAttachTransformNode::WeaponAttachTransformNode()
    : LightUnaffectedNode(true, true), m_pFollow(0), m_spMovement(0), m_nMode(0), m_bUseMovement(0)
{
    m_spMovement.AssignRaw(new COrbMovement);
    m_kBaseRotate.MakeIdentity();
}

// @0x141b76d50
WeaponAttachTransformNode::~WeaponAttachTransformNode()
{
    m_spMovement = 0;
}

// @0x141b76dc0
void WeaponAttachTransformNode::UpdateWorldData()
{
    if (m_pkParent != 0)
    {
        if (m_nMode != 0)
        {
            NiPoint3 kHeight(0.0f, 0.0f, m_kBasePos.z);
            NiPoint3 kOffset(m_kBasePos.x, m_kBasePos.y, 0.0f);
            NiMatrix3 kInverse;
            m_pkParent->GetWorldRotate().Inverse(kInverse);
            m_kLocal.m_Translate = kInverse * kHeight;
            m_kWorld = m_pkParent->GetWorldTransform() * m_kLocal;
            m_kWorld.m_Rotate = m_kBaseRotate;
            if (m_pFollow != 0)
            {
                NiMatrix3 kRotate(m_pFollow->GetWorldRotate() * m_kWorld.m_Rotate);
                m_kWorld.m_Rotate = kRotate;
            }
            // MS2-NOTE: the exe reads m_pFollow's rotation here without the null test above.
            NiPoint3 kTurned(m_pFollow->GetWorldRotate() * kOffset);
            m_kWorld.m_Translate.x += kTurned.x;
            m_kWorld.m_Translate.y += kTurned.y;
        }
        else
        {
            m_kWorld = m_pkParent->GetWorldTransform() * m_kLocal;
        }
    }
    else
    {
        m_kWorld = m_kLocal;
    }
    if (m_bUseMovement)
    {
        double dTime = FUN_14086d260()->GetDeltaTime();
        m_kWorld = m_spMovement->FUN_141625430(dTime, m_kWorld);
    }
    if (m_spCollisionObject)
        m_spCollisionObject->UpdateWorldData();
}
MS2_REPLACE_METHOD(0x141B76DC0, WeaponAttachTransformNode, UpdateWorldData, 990, 0xE527B00F);

// @0x141b771b0
void WeaponAttachTransformNode::SetMovement(INodeMovement* pMovement)
{
    m_spMovement.AssignRaw(pMovement);
}
MS2_REPLACE_METHOD(0x141B771B0, WeaponAttachTransformNode, SetMovement, 43, 0x6B77641A);

// @0x141b77240
const NiRTTI* WeaponAttachTransformNode::GetRTTI() const
{
    return &ms_RTTI;
}
