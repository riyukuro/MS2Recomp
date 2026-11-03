// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unk_SeparateNode: a NiNode whose UpdateWorldData drops the
// parent's world transform and then re-applies only the components selected in its 1-byte bitset. See separatenode.h.
// MS2-UNIT: ?\separatenode.cpp
// MS2-RANGE: 0x140100860-0x140100890 .text$di
// MS2-RANGE: 0x141751290-0x1417516d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\separatenode.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "separatenode.h"

// The class RTTI name ("SeparateNode") and the vftable are unit-local; pin the vftable to the exe address.
// MS2-PIN: ??_7Unk_SeparateNode@@6B@ 0x142f60d20
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140100860
const NiRTTI Unk_SeparateNode::ms_RTTI("SeparateNode", &NiNode::ms_RTTI);

// @0x141751290
NiObject* Unk_SeparateNode::CreateClone(NiCloningProcess& kCloning)
{
    Unk_SeparateNode* pkClone = new (efd::MemHint(efd::MemHint::NONE)) Unk_SeparateNode(m_kBits);
    CopyMembers(pkClone, kCloning);
    return pkClone;
}
MS2_REPLACE_METHOD(0x141751290, Unk_SeparateNode, CreateClone, 158, 0x4F2D30E1);

// @0x141751340
void Unk_SeparateNode::CopyMembers(NiNode* pkDest, NiCloningProcess& kCloning)
{
    if (pkDest != 0) {
        NiNode::CopyMembers(pkDest, kCloning);
    }
}
MS2_REPLACE_METHOD(0x141751340, Unk_SeparateNode, CopyMembers, 52, 0x3A51085E);

// @0x141751380
Unk_SeparateNode::Unk_SeparateNode(bool b0, bool b1, bool b2) : NiNode(0)
{
    m_kBits[0] = b0;
    m_kBits[1] = b1;
    m_kBits[2] = b2;
}

// @0x141751470
Unk_SeparateNode::Unk_SeparateNode(Unk_LightUpdateBits kBits) : NiNode(0), m_kBits(kBits)
{
}

// @0x1417514c0
Unk_SeparateNode::~Unk_SeparateNode()
{
}

// @0x1417514f0
void Unk_SeparateNode::UpdateWorldData()
{
    m_kWorld.MakeIdentity();
    if (m_pkParent != 0) {
        NiTransform kParent = m_pkParent->GetWorldTransform();
        if (m_kBits[0]) {
            FUN_14097fad0(&m_kWorld.m_Translate.x, &kParent.m_Translate.x);
        }
        if (m_kBits[1]) {
            m_kWorld.m_Rotate = kParent.m_Rotate;
        }
        if (m_kBits[2]) {
            m_kWorld.m_fScale = kParent.m_fScale;
        }
    }
}
MS2_REPLACE_METHOD(0x1417514F0, Unk_SeparateNode, UpdateWorldData, 357, 0x59534F7E);

// @0x1417516c0
const NiRTTI* Unk_SeparateNode::GetRTTI() const
{
    return &ms_RTTI;
}
