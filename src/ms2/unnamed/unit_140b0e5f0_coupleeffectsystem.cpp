// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CoupleEffectSystem: couple-gem effect between two players.
// MS2-UNIT: unit_140b0e5f0
// MS2-RANGE: 0x140b0e5f0-0x140b0f4c0 .text$mn
// MS2-PIN: ??_7CoupleEffectSystem@@6B@ 0x142dd93e8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\coupleeffectsystem.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_140b0e5f0.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/fielddatacli.h"   // C3: MS2Ptr<CFieldDataCli> (WorldService::FUN_141bd30a0)
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC::FUN_141654700 / FUN_141658e60
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants methods
#include <NiTransform.h>   // C3: NiTransform default ctor 0x140a332d0 (was FUN_140a332d0)

// ---- unit-local stand-ins and unrecovered callees (names invented from use) ----------------------------------------------

// Map flags: the shared map data behind a counted pointer (the world service's copy of m_298).

// The effect manager singleton (0x1403ed280) and the request it takes (constructed/destroyed out of line).
struct Unk_CoupleRot { float m_af[9]; };
struct Unk_CoupleXform
{
    Unk_CoupleRot m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_CoupleXform, 0x34);
class NoticeMessage   // the request, with its out-of-line ctor and dtor
{
public:
    NoticeMessage();
    ~NoticeMessage();
    CString m_strName;                                  // +0
    int m_nOwnerId;                                     // +8
    int m_pad_0c;
    void* m_pSlot10;
    Unk_CoupleXform* m_pXform;                          // +0x18
    char m_pad_20[0x50];
};
MS2_CHECK_SIZE(NoticeMessage, 0x70);
namespace efd { class Matrix3; }
extern const efd::Matrix3 DAT_143a09600;                    // identity rotation

// Game-wide constants table; the two entries used are 0x58-byte slots with a "set" flag at +8 and the value at +0x50.
struct Unk_CeConstUInt { void* m_pad_00; unsigned char m_bSet; char m_pad_09[0x47]; unsigned m_value; int m_pad_54; };
struct Unk_CeConstFloat { void* m_pad_00; unsigned char m_bSet; char m_pad_09[0x47]; float m_value; int m_pad_54; };
MS2_CHECK_SIZE(Unk_CeConstUInt, 0x58);
MS2_CHECK_SIZE(Unk_CeConstFloat, 0x58);
struct Unk_CeConstTable
{
    char m_pad_00[0xe1a8];
    Unk_CeConstUInt m_checkInterval;                    // +0xe1a8
    Unk_CeConstFloat m_maxDistance;                     // +0xe200
};
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
// C3: the former option-entry member view. 0x140298f40 is Common::Constants::Value<float>::Get()
// (clientconstants.h). Its body is the generic Value<T>::Get() instantiated in
// unit_1402ab440_constantsblocks.cpp, and the callers read the float through the
// pointer it returns.
//
unsigned* FUN_140b0f480(Unk_CeConstUInt* pSlot);

// World service / players.
class Unk_AkoMyPC;
template <> Unk_AkoMyPC* efd::DynamicCast<Unk_AkoMyPC, PCBase>(PCBase* Source);   // C3: was FUN_1409613d0
float FUN_140966f00(Vector3 a, Vector3 b);  // distance

// @0x140b0e5f0
CoupleEffectSystem::CoupleEffectSystem(PCBase* pOwner, __int64 nPartnerId, int nCoupleType, int bLinked, CStringW strName,
                                       int nGemId)
    : m_bInRange(0), m_bActive(0), m_bRequested(0), m_nEffectId(0), m_posEffect(efd::Point3::ZERO), m_pOwner(pOwner),
      m_bLinked(bLinked), m_nCoupleType(nCoupleType), m_nPartnerId(nPartnerId), m_strName(strName), m_nGemId(nGemId)
{
    FUN_140b0ecd0();
}

// @0x140b0e730
CoupleEffectSystem::~CoupleEffectSystem()
{
    FUN_140b0f3a0(1);
}

// @0x140b0e7a0
void CoupleEffectSystem::FUN_140b0e7a0(float fDelta)
{
    if (m_bActive == 0)
        return;
    if (m_bLinked == 0)
        return;
    void* pObj = efd::DynamicCast<Unk_AkoMyPC, PCBase>(m_pOwner);
    if (pObj == 0)
        return;
    if (!FUN_140b0ef20())
        return;
    if (m_tick.Check(1000) != 0)
    {
        PCBase* pPartner = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(m_nPartnerId));
        if (pPartner == 0)
            return;
        if (m_nCoupleType == 0 || m_nCoupleType != reinterpret_cast<PC*>(pPartner)->GetCoupleType())
            return;
        if (((class PCBase*)(class PCBase*)(m_pOwner))->FUN_141656a80() != reinterpret_cast<PC*>(pPartner)->FUN_141663990())
            return;
        float fDistance = FUN_140966f00(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(m_pOwner->vfunc_18())), reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPartner->vfunc_18())));
        if (!(fDistance > *((Common::Constants::Value<float>*)(struct Unk_CeConstFloat*)(&((struct Unk_CeConstTable*)GetClientConstants())->m_maxDistance))->Get()))
        {
            if (m_bInRange != 0)
            {
                if (m_timer.FUN_140868c00() != 0)
                {
                    float fMove = FUN_140966f00(Vector3(reinterpret_cast<Vector3&>(m_posEffect)), Vector3(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(FUN_140b0f160()))));
                    if (fMove > 50.0f && m_nEffectId != 0)
                        FUN_140b0f3a0(1);
                }
            }
            else
            {
                m_bInRange = 1;
                if (m_nEffectId == 0)
                    FUN_140b0f3a0(0);
            }
        }
        else
        {
            m_bInRange = 0;
            if (m_nEffectId != 0)
                FUN_140b0f3a0(1);
        }
    }
}

// @0x140b0ead0
void CoupleEffectSystem::FUN_140b0ead0(__int64 nValue)
{
    FUN_140b0ecd0();
    void* pObj = efd::DynamicCast<Unk_AkoMyPC, PCBase>(m_pOwner);
    if (pObj == 0)
        return;
    if (m_bLinked != 0 && m_nEffectId > 0)
    {
        COutPacket packet(static_cast<int>(SendOp::BuddyBadge), 0);
        packet.COutPacket::WriteUInt8(2);
        packet.COutPacket::WriteInt64(FUN_140b0ec80());
        packet.COutPacket::WriteInt64(nValue);
        FUN_140710590(packet);
    }
}

// @0x140b0eba0
void CoupleEffectSystem::FUN_140b0eba0(int nObjectId)
{
    PCBase* pPartner = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(m_nPartnerId));
    if (pPartner == 0 || ((class GameObject*)(class PCBase*)(pPartner))->FUN_14123c580() == nObjectId)
    {
        FUN_140b0f3a0(1);
        m_bActive = 0;
    }
}

// @0x140b0ec10
int CoupleEffectSystem::GetCoupleType() const
{
    return m_nCoupleType;
}

// @0x140b0ec30
CStringW CoupleEffectSystem::GetName() const
{
    return m_strName;
}

// @0x140b0ec80
__int64 CoupleEffectSystem::FUN_140b0ec80()
{
    if (m_pOwner == 0)
        return 0;
    if (m_bLinked != 0)
        return ((class PCBase*)(class PCBase*)(m_pOwner))->FUN_141656a80();
    return m_nPartnerId;
}

// @0x140b0ecd0
void CoupleEffectSystem::FUN_140b0ecd0()
{
    PCBase* pPartner = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(m_nPartnerId));
    if (pPartner != 0)
    {
        m_bInRange = 0;
        m_bActive = 1;
        FUN_140b0f260();
    }
}

// @0x140b0ed30
void CoupleEffectSystem::FUN_140b0ed30()
{
    if (m_nEffectId != 0)
        return;
    reinterpret_cast<NiPoint3&>(m_posEffect) = static_cast<NiPoint3&&>(*const_cast<NiPoint3*>(&static_cast<const NiPoint3&>(FUN_140b0f160())));   // NiPoint3::operator= (0x14097faa0)
    Unk_CoupleXform xf;
    reinterpret_cast<NiTransform*>(&xf)->NiTransform::NiTransform();
    xf.m_fScale = 1.0f;
    *reinterpret_cast<NiPoint3*>(xf.m_afTranslate) = *reinterpret_cast<const NiPoint3*>(&m_posEffect);
    Unk_CoupleRot rot;
    reinterpret_cast<Unk_NiMatrix3*>(&rot)->Unk_NiMatrix3::Unk_NiMatrix3(reinterpret_cast<const Unk_EfdMatrix3&>(DAT_143a09600));
    xf.m_rotate = rot;
    NoticeMessage request;
    request.m_strName = FUN_140b0efb0();
    request.m_nOwnerId = 0;
    request.m_pXform = &xf;
    m_nEffectId = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(reinterpret_cast<Unk_EffectTarget&>(request));
    m_timer.FUN_140868750(*FUN_140b0f480(&((struct Unk_CeConstTable*)GetClientConstants())->m_checkInterval));
}

// @0x140b0eed0
void CoupleEffectSystem::FUN_140b0eed0()
{
    if (m_nEffectId == 0)
        return;
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffectId);
    m_nEffectId = 0;
    m_bInRange = 0;
}

// @0x140b0ef20
bool CoupleEffectSystem::FUN_140b0ef20()
{
    MS2Ptr<CFieldDataCli> spMap = WorldService::GetInstance()->FUN_141bd30a0();
    if (reinterpret_cast<void*>(spMap.get()) != 0)
    {
        if (spMap->FUN_140375660(0x400) != 0)
            return false;
    }
    return true;
}

// @0x140b0efb0
CString CoupleEffectSystem::FUN_140b0efb0()
{
    PCBase* pPartner = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(m_nPartnerId));
    if (pPartner == 0)
        return "";
    MS2Ptr<CGemCharEffectData> spEffect(dynamic_cast<CGemCharEffectData*>(FUN_1405a96f0()->FUN_1405ac160(m_nGemId).get()));
    if (spEffect == 0)
        return "";
    return spEffect->GetCoupleEffect(reinterpret_cast<PC*>(m_pOwner)->FUN_141658e60(), reinterpret_cast<PC*>(pPartner)->FUN_141658e60());
}

// @0x140b0f160
NiPoint3 CoupleEffectSystem::FUN_140b0f160()
{
    PCBase* pPartner = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(m_nPartnerId));
    if (pPartner == 0)
        return NiPoint3(efd::Point3::ZERO);
#ifdef __clang__
    NiPoint3 ptPartner = pPartner->vfunc_18();
    NiPoint3 ptOwner = m_pOwner->vfunc_18();
    return NiPoint3(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(ptOwner))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(ptPartner))))) / 2.0f))));
#else
    return NiPoint3(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(m_pOwner->vfunc_18()))))
                             + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(pPartner->vfunc_18())))))) / 2.0f)
)));
#endif
}

// @0x140b0f260
void CoupleEffectSystem::FUN_140b0f260()
{
    if (m_bRequested != 0)
        return;
    void* pObj = efd::DynamicCast<Unk_AkoMyPC, PCBase>(m_pOwner);
    if (pObj == 0)
        return;
    PCBase* pPartner = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(m_nPartnerId));
    if (pPartner == 0)
        return;
    bool bDiffers = m_strName != pPartner->vfunc_77();
    if (bDiffers)
    {
        COutPacket packet(static_cast<int>(SendOp::BuddyBadge), 0);
        packet.COutPacket::WriteUInt8(3);
        packet.COutPacket::WriteInt64(m_nPartnerId);
        FUN_140710590(packet);
        m_bRequested = 1;
    }
}

// @0x140b0f3a0
void CoupleEffectSystem::FUN_140b0f3a0(int nMode)
{
    if (m_bLinked != 0)
    {
        if (nMode == 0)
            FUN_140b0ed30();
        else if (nMode == 1)
            FUN_140b0eed0();
    }
    COutPacket packet(static_cast<int>(SendOp::BuddyBadge), 0);
    packet.COutPacket::WriteUInt8((unsigned char)nMode);
    packet.COutPacket::WriteInt64(FUN_140b0ec80());
    FUN_140710590(packet);
}

// @0x140b0f480
unsigned* FUN_140b0f480(Unk_CeConstUInt* pSlot)
{
    if (pSlot->m_bSet == 0)
        reinterpret_cast<Common::Constants::Object*>(pSlot)->Error("constants is not set");
    return &pSlot->m_value;
}
