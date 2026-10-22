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

// ---- unit-local stand-ins and unrecovered callees (names invented from use) ----------------------------------------------
// Gem tables (RTTI names). Only the polymorphic part is declared; the effect-name lookup is an out-of-line member.
class CGemDataBase { public: virtual ~CGemDataBase(); };
class CGemCharEffectData : public CGemDataBase { public: CString FUN_1405acc80(int nOwnerGem, int nPartnerGem); };
class Unk_GemDbPtr { public: ~Unk_GemDbPtr(); CGemDataBase* FUN_1405a9970() const; private: void* m_pad_00; CGemDataBase* m_p; };   // dtor 0x1405a8740
class Unk_GemEffPtr
{
public:
    Unk_GemEffPtr(CGemCharEffectData* p);               // 0x1405a80c0
    ~Unk_GemEffPtr();                                   // 0x1405a86b0
    bool FUN_1405a8d70(int n) const;                    // operator==
    CGemCharEffectData* FUN_1405a8ef0() const;          // operator->
private:
    void* m_pad_00;
    CGemCharEffectData* m_p;
};
class Unk_GemDb { public: Unk_GemDbPtr FUN_1405ac160(int nGemId); };
Unk_GemDb* FUN_1405a96f0();

// Map flags: the shared map data behind a counted pointer (the world service's copy of m_298).
class Unk_CeMapData { public: int FUN_140375660(unsigned nMask); };
class Unk_CeMapPtr
{
public:
    ~Unk_CeMapPtr();                                    // 0x1408850f0
    void* FUN_1409657a0() const;                        // operator T*
    Unk_CeMapData* FUN_140885340() const;               // operator->
private:
    void* m_pad_00;
    Unk_CeMapData* m_p;
};

// The effect manager singleton (0x1403ed280) and the request it takes (constructed/destroyed out of line).
struct Unk_CoupleRot { float m_af[9]; };
struct Unk_CoupleXform
{
    Unk_CoupleRot m_rotate;
    float m_afTranslate[3];
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_CoupleXform, 0x34);
struct Unk_CeRequest
{
    CString m_strName;                                  // +0
    int m_nOwnerId;                                     // +8
    int m_pad_0c;
    void* m_pSlot10;
    Unk_CoupleXform* m_pXform;                          // +0x18
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_CeRequest, 0x78);
class Unk_CeEffectMgr
{
public:
    int FUN_1411a49c0(Unk_CeRequest* pRequest);         // spawn, returns the handle
    void FUN_1411a6060(int nHandle);                    // release
};
Unk_CeEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_CeRequest* p);                   // construct
void FUN_1405a89e0(Unk_CeRequest* p);                   // destroy
void* FUN_140a332d0(Unk_CoupleXform* p);                // NiTransform default ctor
void FUN_14097fad0(float* pDst, const Unk_CoupleVec* pSrc);   // NiPoint3 assignment (translate)
void FUN_140a33240(Unk_CoupleRot* pDst, const Unk_EfdMatrix3* pSrc);             // NiMatrix3 from efd::Matrix3
extern Unk_EfdMatrix3 DAT_143a09600;                    // identity rotation

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
Unk_CeConstTable* FUN_1401d3200();
float* FUN_140298f40(Unk_CeConstFloat* p);
unsigned* FUN_140b0f480(Unk_CeConstUInt* pSlot);
extern Unk_StreamPoint DAT_143b01a60;              // checked value getter
void FUN_1402b7560(void* pSlot, const char* pszMessage);

// World service / players.
class Unk_CeWorld
{
public:
    PCBase* FUN_141bd1530(__int64 nId);                 // player by id
    Unk_CeMapPtr FUN_141bd30a0();                       // current map data
};
Unk_CeWorld* FUN_1403ed2d0();
void* FUN_1409613d0(PCBase* p);
__int64 FUN_141656a80(PCBase* p);
int FUN_141658e60(PCBase* p);
int FUN_141663940(PCBase* p);
__int64 FUN_141663990(PCBase* p);
int FUN_14123c580(PCBase* p);                           // object id
float FUN_140966f00(Unk_StreamPoint a, Unk_StreamPoint b);  // distance
int FUN_140268870(Unk_CoupleTick* p, unsigned nInterval);   // true once the interval elapsed (re-arms)
bool FUN_140164830(const CStringW& a, const CStringW& b);

// @0x140b0e5f0
CoupleEffectSystem::CoupleEffectSystem(PCBase* pOwner, __int64 nPartnerId, int nCoupleType, int bLinked, CStringW strName,
                                       int nGemId)
    : m_bInRange(0), m_bActive(0), m_bRequested(0), m_nEffectId(0), m_posEffect(DAT_143b01a60), m_pOwner(pOwner),
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
// MS2-FUNCTIONAL: transliterated from the decompile; point copies and frame layout differ
void CoupleEffectSystem::FUN_140b0e7a0()
{
    if (m_bActive == 0 || m_bLinked == 0 || FUN_1409613d0(m_pOwner) == 0 || !FUN_140b0ef20() ||
        FUN_140268870(&m_tick, 1000) == 0)
        return;
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(m_nPartnerId);
    if (pPartner == 0 || m_nCoupleType == 0 || m_nCoupleType != FUN_141663940(pPartner))
        return;
    if (FUN_141656a80(m_pOwner) != FUN_141663990(pPartner))
        return;
    NiPoint3 ptPartner = pPartner->vfunc_18();
    NiPoint3 ptOwner = m_pOwner->vfunc_18();
    float fDistance = FUN_140966f00(reinterpret_cast<Unk_StreamPoint&>(ptOwner), reinterpret_cast<Unk_StreamPoint&>(ptPartner));
    float fMaxDistance = *FUN_140298f40(&FUN_1401d3200()->m_maxDistance);
    if (fDistance > fMaxDistance)
    {
        m_bInRange = 0;
        if (m_nEffectId != 0)
            FUN_140b0f3a0(1);
    }
    else if (m_bInRange == 0)
    {
        m_bInRange = 1;
        if (m_nEffectId == 0)
            FUN_140b0f3a0(0);
    }
    else
    {
        if (m_timer.FUN_140868c00() != 0)
        {
            Unk_CoupleVec ptMid = FUN_140b0f160();
            float fMove = FUN_140966f00(reinterpret_cast<Unk_StreamPoint&>(m_posEffect), reinterpret_cast<Unk_StreamPoint&>(ptMid));
            if (50.0f < fMove && m_nEffectId != 0)
                FUN_140b0f3a0(1);
        }
    }
}

// @0x140b0ead0
void CoupleEffectSystem::FUN_140b0ead0(__int64 nValue)
{
    FUN_140b0ecd0();
    void* pObj = FUN_1409613d0(m_pOwner);
    if (pObj == 0)
        return;
    if (m_bLinked != 0 && m_nEffectId > 0)
    {
        COutPacket packet(static_cast<int>(SendOp::BuddyBadge), 0);
        packet.COutPacket::vfunc_o10_1(2);
        packet.COutPacket::vfunc_o10_4(FUN_140b0ec80());
        packet.COutPacket::vfunc_o10_4(nValue);
        FUN_140710590(packet);
    }
}

// @0x140b0eba0
void CoupleEffectSystem::FUN_140b0eba0(int nObjectId)
{
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(m_nPartnerId);
    if (pPartner == 0 || FUN_14123c580(pPartner) == nObjectId)
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
        return FUN_141656a80(m_pOwner);
    return m_nPartnerId;
}

// @0x140b0ecd0
void CoupleEffectSystem::FUN_140b0ecd0()
{
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(m_nPartnerId);
    if (pPartner != 0)
    {
        m_bInRange = 0;
        m_bActive = 1;
        FUN_140b0f260();
    }
}

// @0x140b0ed30
// MS2-FUNCTIONAL: effect request/transform stand-ins; frame layout differs
void CoupleEffectSystem::FUN_140b0ed30()
{
    if (m_nEffectId != 0)
        return;
    m_posEffect.FUN_14097faa0(FUN_140b0f160());
    Unk_CoupleXform xf;
    FUN_140a332d0(&xf);
    xf.m_fScale = 1.0f;
    FUN_14097fad0(xf.m_afTranslate, &m_posEffect);
    Unk_CoupleRot rot;
    FUN_140a33240(&rot, &DAT_143a09600);
    xf.m_rotate = rot;
    Unk_CeRequest request;
    FUN_140a52ef0(&request);
    request.m_strName = FUN_140b0efb0();
    request.m_nOwnerId = 0;
    request.m_pXform = &xf;
    m_nEffectId = FUN_1403ed280()->FUN_1411a49c0(&request);
    m_timer.FUN_140868750(*FUN_140b0f480(&FUN_1401d3200()->m_checkInterval));
    FUN_1405a89e0(&request);
}

// @0x140b0eed0
void CoupleEffectSystem::FUN_140b0eed0()
{
    if (m_nEffectId == 0)
        return;
    FUN_1403ed280()->FUN_1411a6060(m_nEffectId);
    m_nEffectId = 0;
    m_bInRange = 0;
}

// @0x140b0ef20
bool CoupleEffectSystem::FUN_140b0ef20()
{
    Unk_CeMapPtr spMap = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spMap.FUN_1409657a0() != 0)
    {
        if (spMap.FUN_140885340()->FUN_140375660(0x400) != 0)
            return false;
    }
    return true;
}

// @0x140b0efb0
// MS2-FUNCTIONAL: NRVO return-flag shape of the exe not reproduced (CString returned from three paths)
CString CoupleEffectSystem::FUN_140b0efb0()
{
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(m_nPartnerId);
    if (pPartner == 0)
        return "";
    Unk_GemEffPtr spEffect(dynamic_cast<CGemCharEffectData*>(FUN_1405a96f0()->FUN_1405ac160(m_nGemId).FUN_1405a9970()));
    if (spEffect.FUN_1405a8d70(0) == 0)
    {
        return spEffect.FUN_1405a8ef0()->FUN_1405acc80(FUN_141658e60(m_pOwner), FUN_141658e60(pPartner));
    }
    else
    {
        return "";
    }
}

// @0x140b0f160
// MS2-FUNCTIONAL: point temporaries live in different frame slots than in the exe
Unk_CoupleVec CoupleEffectSystem::FUN_140b0f160()
{
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(m_nPartnerId);
    if (pPartner == 0)
        return Unk_CoupleVec(DAT_143b01a60);
    NiPoint3 ptPartner = pPartner->vfunc_18();
    NiPoint3 ptOwner = m_pOwner->vfunc_18();
    Unk_StreamPoint ptMid = reinterpret_cast<Unk_StreamPoint&>(ptOwner).FUN_14097fd50(reinterpret_cast<Unk_StreamPoint&>(ptPartner)).FUN_140ae9180(2.0f);
    return Unk_CoupleVec(ptMid);
}

// @0x140b0f260
// MS2-FUNCTIONAL: temporary reference slot order differs from the exe
void CoupleEffectSystem::FUN_140b0f260()
{
    if (m_bRequested != 0)
        return;
    void* pObj = FUN_1409613d0(m_pOwner);
    if (pObj == 0)
        return;
    PCBase* pPartner = FUN_1403ed2d0()->FUN_141bd1530(m_nPartnerId);
    if (pPartner == 0)
        return;
    const CStringW& strPartner = pPartner->vfunc_77();
    bool bSame = FUN_140164830(m_strName, strPartner);
    if (bSame)
    {
        COutPacket packet(static_cast<int>(SendOp::BuddyBadge), 0);
        packet.COutPacket::vfunc_o10_1(3);
        packet.COutPacket::vfunc_o10_4(m_nPartnerId);
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
    packet.COutPacket::vfunc_o10_1((unsigned char)nMode);
    packet.COutPacket::vfunc_o10_4(FUN_140b0ec80());
    FUN_140710590(packet);
}

// @0x140b0f480
unsigned* FUN_140b0f480(Unk_CeConstUInt* pSlot)
{
    if (pSlot->m_bSet == 0)
        FUN_1402b7560(pSlot, "constants is not set");
    return &pSlot->m_value;
}
