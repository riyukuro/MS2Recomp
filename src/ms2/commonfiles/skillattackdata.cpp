// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SkillAttackData: one <attack> of a skill motion and its
// XML blocks (arrow, damage, pause, chain): constructors, XML readers/writers and comparisons.
// MS2-UNIT: ?\skillattackdata.cpp
// MS2-RANGE: 0x1407dee30-0x1407e5b80 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "ms2/commonfiles/skillattackdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
int FUN_1408732e0(Unk_140165cf0* pElem, const char* pszName, __int64* pnOut);   // 64 bit int attribute
void FUN_140873e30(void* pElem, const char* pszName, float fValue);
void FUN_14086f970(void* pElem, const char* pszName, double fValue);       // SetDoubleAttribute
void FUN_140873bc0(void* pElem, const char* pszName, bool bValue);         // SetAttribute(name, bool)
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);          // SetAttribute(name, int)
void FUN_140873ce0(void* pElem, const char* pszName, unsigned nValue);     // SetAttribute(name, unsigned)
void FUN_140873eb0(void* pElem, const char* pszName, const __int64& nValue);   // SetAttribute(name, int64)
void FUN_140874050(void* pElem, const char* pszName, const CString& strValue); // SetAttribute(name, string)
void* FUN_14086e000(void* pParent, const void* pChild);                    // InsertEndChild
efd::Point3 FUN_14028f060(CString str);                                    // "x, y, z" -> point
CString FUN_14028ef00(efd::Point3 kPoint);                                 // point -> "x, y, z"
void FUN_140194470(efd::Point3* pDst, const efd::Point3& kSrc);            // efd::Point3 assignment
bool FUN_14028d470(float a, float b);                                      // nearly equal
bool FUN_1403744a0(int nState);
bool FUN_140374410(int nState);
bool IsSameStringArray(const ATL::CAtlArray<CString>& a, const ATL::CAtlArray<CString>& b);    // 0x1406cfe10
template <class T> bool IsSameVector(const std::vector<T>& a, const std::vector<T>& b)
{
    if (a.size() != b.size())
        return false;
    for (unsigned __int64 i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// Unit-local view of the game's TiXmlElement (0x90 bytes; the writers only build it and insert it).
class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
private:
    void* unknown00[18];
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);

// @0x1407dee30
SkillArrow::SkillArrow()
{
    m_nOverlap = 0;
    m_nExplosion = 0;
    m_eNonTarget = (SkillNonTarget)0;
    m_nBounceType = 0;
    m_nBounceCount = 0;
    m_fBounceRadius = 0;
    m_nBounceOverlap = 1;
    m_collision.x = 0;
    m_collision.y = 0;
    m_collision.z = 0;
    m_collisionAdd.x = 0;
    m_collisionAdd.y = 0;
    m_collisionAdd.z = 0;
    m_nRayType = 0;
    m_nRayPhysxTest = 0;
}

// @0x1407def80
bool SkillArrow::operator!=(const SkillArrow& o) const
{
    if (m_nOverlap != o.m_nOverlap) return true;
    if (m_nExplosion != o.m_nExplosion) return true;
    if (m_eNonTarget != o.m_eNonTarget) return true;
    if (m_nBounceType != o.m_nBounceType) return true;
    if (m_nBounceCount != o.m_nBounceCount) return true;
    if (m_fBounceRadius != o.m_fBounceRadius) return true;
    if (m_nBounceOverlap != o.m_nBounceOverlap) return true;
    if (m_nRayType != o.m_nRayType) return true;
    if (m_nRayPhysxTest != o.m_nRayPhysxTest) return true;
    if (m_collision != o.m_collision) return true;
    if (m_collisionAdd != o.m_collisionAdd) return true;
    if (m_strEffect != o.m_strEffect) return true;
    if (m_strEffectRemain != o.m_strEffectRemain) return true;
    if (m_strEffectDestroy != o.m_strEffectDestroy) return true;
    if (m_strTargetKeepEffect != o.m_strTargetKeepEffect) return true;
    if (m_strEffectInvoke != o.m_strEffectInvoke) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407DEF80, SkillArrow, operator!=, 515, 0xBEC66076);

// @0x1407df190
int SkillArrow::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pArrow = pElem->FUN_140165cf0("arrow");
    if (pArrow == 0)
        return 1;
    FUN_1408731e0(pArrow, "overlap", m_nOverlap);
    FUN_1408731e0(pArrow, "explosion", m_nExplosion);
    FUN_1408731e0(pArrow, "rayPhysxTest", m_nRayPhysxTest);
    XmlValue(pArrow, "nonTarget", m_eNonTarget);
    FUN_1408731e0(pArrow, "bounceType", m_nBounceType);
    FUN_1408731e0(pArrow, "bounceCount", m_nBounceCount);
    FUN_140873360(pArrow, "bounceRadius", m_fBounceRadius);
    FUN_1408731e0(pArrow, "bounceOverlap", m_nBounceOverlap);
    FUN_140194470(&m_collision, FUN_14028f060(FUN_14015f710(pArrow, "collision", CString(""))));
    FUN_140194470(&m_collisionAdd, FUN_14028f060(FUN_14015f710(pArrow, "collisionAdd", CString(""))));
    m_strEffect = FUN_14015f710(pArrow, "effect", CString(""));
    m_strEffectRemain = FUN_14015f710(pArrow, "effectRemain", CString(""));
    m_strEffectDestroy = FUN_14015f710(pArrow, "effectDestroy", CString(""));
    m_strTargetKeepEffect = FUN_14015f710(pArrow, "targetKeepEffect", CString(""));
    m_strEffectInvoke = FUN_14015f710(pArrow, "effectInvoke", CString(""));
    FUN_1408731e0(pArrow, "rayType", m_nRayType);
    return 1;
}
MS2_REPLACE_METHOD(0x1407DF190, SkillArrow, Load, 1351, 0x56FCF58F);

// @0x1407df6e0
void SkillArrow::Save(void* pParent)
{
    static SkillArrow kDefault;
    if (*this != kDefault)
    {
        Unk_TiXmlElement elem("arrowProperty");
        if (m_nOverlap != kDefault.m_nOverlap)
            FUN_140873ca0(&elem, "overlap", m_nOverlap);
        if (m_nExplosion != kDefault.m_nExplosion)
            FUN_140873ca0(&elem, "explosion", m_nExplosion);
        if (m_nRayPhysxTest != kDefault.m_nRayPhysxTest)
            FUN_140873ca0(&elem, "rayPhysxTest", m_nRayPhysxTest);
        if (m_eNonTarget != kDefault.m_eNonTarget)
            FUN_140873ca0(&elem, "nonTarget", m_eNonTarget);
        if (m_nBounceType != kDefault.m_nBounceType)
            FUN_140873ca0(&elem, "bounceType", m_nBounceType);
        if (m_nBounceCount != kDefault.m_nBounceCount)
            FUN_140873ca0(&elem, "bounceCount", m_nBounceCount);
        if (kDefault.m_fBounceRadius != m_fBounceRadius)
            FUN_14086f970(&elem, "bounceRadius", m_fBounceRadius);
        if (m_nBounceOverlap != kDefault.m_nBounceOverlap)
            FUN_140873ca0(&elem, "bounceOverlap", m_nBounceOverlap);
        if (m_collision != kDefault.m_collision)
            FUN_140874050(&elem, "collision", FUN_14028ef00(m_collision));
        if (m_collisionAdd != kDefault.m_collisionAdd)
            FUN_140874050(&elem, "collisionAdd", FUN_14028ef00(m_collisionAdd));
        if (m_strEffect != kDefault.m_strEffect)
            FUN_140874050(&elem, "effect", m_strEffect);
        if (m_strEffectRemain != kDefault.m_strEffectRemain)
            FUN_140874050(&elem, "effectRemain", m_strEffectRemain);
        if (m_strEffectDestroy != kDefault.m_strEffectDestroy)
            FUN_140874050(&elem, "effectDestroy", m_strEffectDestroy);
        if (m_strTargetKeepEffect != kDefault.m_strTargetKeepEffect)
            FUN_140874050(&elem, "targetKeepEffect", m_strTargetKeepEffect);
        if (m_nRayType != kDefault.m_nRayType)
            FUN_140873ca0(&elem, "rayType", m_nRayType);
        if (!m_strEffectInvoke.IsEmpty())
            FUN_140874050(&elem, "effectInvoke", m_strEffectInvoke);
        FUN_14086e000(pParent, &elem);
    }
}

// @0x1407dfbb0
int SkillArrow::IsNonTargetOne() const
{
    return m_eNonTarget == 1;
}
MS2_REPLACE_METHOD(0x1407DFBB0, SkillArrow, IsNonTargetOne, 44, 0xACFACF76);

// @0x1407dfbf0
SkillDamage::SkillDamage()
{
    m_nCount = 1;
    m_nHand = 0;
    m_fRate = 0;
    m_nValue = 0;
    m_nAttackMaterial = 0;
    m_fDamageByTargetMaxHP = 0;
    m_nConstDamageByTargetHP = 0;
    m_nConstDamageByTargetSP = 0;
    m_nIsConstDamageValue = 0;
    m_nNameIndex = 0;
    m_ePush = (SkillPushType)0;
    m_fPushDistance = 0;
    m_fPushDuration = 0;
    m_fPushProb = 1.0f;
    m_ePushEaseType = (SkillPushEaseType)0;
    m_ePushApplyField = (SkillPushApplyField)0;
    m_fPushUpDistance = 0;
    m_nPushDown = 0;
    m_nPushFall = 0;
    m_nPushPriority = 0;
    m_nPushPriorityHitImmune = 0;
    m_fHitSpeedRate = 1.0f;
    m_fHitPauseTime = 0;
    m_fDamagedVibrateRatio = 1.0f;
    m_eStateHitIgnore = (SkillStateHit)0;
    m_eStateHitOnly = (SkillStateHit)0;
    m_nSuperArmorBreak = 0;
    m_bIgnoreOptimalHideDamageHitEffect = false;
    m_bIgnoreOptimalHideDamageRemainEffect = false;
    m_nInvokeEffectDisable = 0;
    m_nDamageEventDisable = 0;
}

// @0x1407dfdf0
bool SkillDamage::operator!=(const SkillDamage& o) const
{
    if (m_nCount != o.m_nCount) return true;
    if (m_nHand != o.m_nHand) return true;
    if (m_fRate != o.m_fRate) return true;
    if (m_nValue != o.m_nValue) return true;
    if (m_strEffectHit != o.m_strEffectHit) return true;
    if (m_strEffectRemain != o.m_strEffectRemain) return true;
    if (m_nIsConstDamageValue != o.m_nIsConstDamageValue) return true;
    if (m_bIgnoreOptimalHideDamageHitEffect != o.m_bIgnoreOptimalHideDamageHitEffect) return true;
    if (m_bIgnoreOptimalHideDamageRemainEffect != o.m_bIgnoreOptimalHideDamageRemainEffect) return true;
    if (m_nAttackMaterial != o.m_nAttackMaterial) return true;
    if (m_fHitSpeedRate != o.m_fHitSpeedRate) return true;
    if (m_fHitPauseTime != o.m_fHitPauseTime) return true;
    if (m_fDamagedVibrateRatio != o.m_fDamagedVibrateRatio) return true;
    if (m_fDamageByTargetMaxHP != o.m_fDamageByTargetMaxHP) return true;
    if (m_nConstDamageByTargetHP != o.m_nConstDamageByTargetHP) return true;
    if (m_nConstDamageByTargetSP != o.m_nConstDamageByTargetSP) return true;
    if (m_ePush != o.m_ePush) return true;
    if (m_fPushDistance != o.m_fPushDistance) return true;
    if (m_fPushDuration != o.m_fPushDuration) return true;
    if (m_fPushProb != o.m_fPushProb) return true;
    if (m_ePushEaseType != o.m_ePushEaseType) return true;
    if (m_ePushApplyField != o.m_ePushApplyField) return true;
    if (m_fPushUpDistance != o.m_fPushUpDistance) return true;
    if (m_nPushDown != o.m_nPushDown) return true;
    if (m_nPushFall != o.m_nPushFall) return true;
    if (m_nPushPriority != o.m_nPushPriority) return true;
    if (m_nPushPriorityHitImmune != o.m_nPushPriorityHitImmune) return true;
    if (m_strPushAnimation != o.m_strPushAnimation) return true;
    if (m_eStateHitIgnore != o.m_eStateHitIgnore) return true;
    if (m_eStateHitOnly != o.m_eStateHitOnly) return true;
    if (m_nSuperArmorBreak != o.m_nSuperArmorBreak) return true;
    if (m_nInvokeEffectDisable != o.m_nInvokeEffectDisable) return true;
    if (m_nDamageEventDisable != o.m_nDamageEventDisable) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407DFDF0, SkillDamage, operator!=, 968, 0xB3EF0FD2);

// @0x1407e01c0
int SkillDamage::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pDamage = pElem->FUN_140165cf0("damage");
    if (pDamage == 0)
        return 1;
    FUN_1408731e0(pDamage, "count", m_nCount);
    FUN_1408731e0(pDamage, "hand", m_nHand);
    FUN_140873360(pDamage, "rate", m_fRate);
    FUN_140873360(pDamage, "hitSpeedRate", m_fHitSpeedRate);
    FUN_140873360(pDamage, "hitPauseTime", m_fHitPauseTime);
    FUN_140873360(pDamage, "damagedVibrateRatio", m_fDamagedVibrateRatio);
    FUN_1408732e0(pDamage, "value", &m_nValue);
    m_strEffectRemain = FUN_14015f710(pDamage, "effectRemain", CString(""));
    m_strEffectHit = FUN_14015f710(pDamage, "effectHit", CString(""));
    FUN_1408730a0(pDamage, "IgnoreOptimalHideDamageHitEffect", m_bIgnoreOptimalHideDamageHitEffect);
    FUN_1408730a0(pDamage, "IgnoreOptimalHideDamageRemainEffect", m_bIgnoreOptimalHideDamageRemainEffect);
    FUN_140873360(pDamage, "damageByTargetMaxHP", m_fDamageByTargetMaxHP);
    FUN_1408731e0(pDamage, "isConstDamageValue", m_nIsConstDamageValue);
    FUN_1408732e0(pDamage, "constDamageByTargetHP", &m_nConstDamageByTargetHP);
    FUN_1408732e0(pDamage, "constDamageByTargetSP", &m_nConstDamageByTargetSP);
    XmlValue(pDamage, "push", m_ePush);
    FUN_140873360(pDamage, "pushdistance", m_fPushDistance);
    FUN_140873360(pDamage, "pushduration", m_fPushDuration);
    FUN_140873360(pDamage, "pushprob", m_fPushProb);
    XmlValue(pDamage, "pushEaseType", m_ePushEaseType);
    if (m_ePushEaseType < 0 || m_ePushEaseType > 2)
        m_ePushEaseType = (SkillPushEaseType)0;
    XmlValue(pDamage, "pushApplyField", m_ePushApplyField);
    FUN_140873360(pDamage, "pushUpDistance", m_fPushUpDistance);
    FUN_1408731e0(pDamage, "pushDown", m_nPushDown);
    FUN_1408731e0(pDamage, "pushFall", m_nPushFall);
    FUN_1408731e0(pDamage, "pushPriority", m_nPushPriority);
    FUN_1408731e0(pDamage, "pushPriorityHitImmune", m_nPushPriorityHitImmune);
    FUN_1408733e0(pDamage, "pushAnimation", m_strPushAnimation);
    FUN_1408731e0(pDamage, "attackMaterial", m_nAttackMaterial);
    XmlValue(pDamage, "stateHitIgnore", m_eStateHitIgnore);
    XmlValue(pDamage, "stateHitOnly", m_eStateHitOnly);
    FUN_1408731e0(pDamage, "superArmorBreak", m_nSuperArmorBreak);
    FUN_1408731e0(pDamage, "invokeEffectDisable", m_nInvokeEffectDisable);
    FUN_1408731e0(pDamage, "damageEventDisable", m_nDamageEventDisable);
    return 1;
}
MS2_REPLACE_METHOD(0x1407E01C0, SkillDamage, Load, 1363, 0x702F5867);

// @0x1407e0720
void SkillDamage::Save(void* pParent)
{
    static SkillDamage kDefault;
    if (*this != kDefault)
    {
        Unk_TiXmlElement elem("damageProperty");
        if (m_nCount != kDefault.m_nCount)
            FUN_140873ca0(&elem, "count", m_nCount);
        if (m_nHand != kDefault.m_nHand)
            FUN_14086f970(&elem, "hand", m_nHand);
        if (kDefault.m_fRate != m_fRate)
            FUN_14086f970(&elem, "rate", m_fRate);
        if (kDefault.m_fHitSpeedRate != m_fHitSpeedRate)
            FUN_14086f970(&elem, "hitSpeedRate", m_fHitSpeedRate);
        if (kDefault.m_fHitPauseTime != m_fHitPauseTime)
            FUN_14086f970(&elem, "hitPauseTime", m_fHitPauseTime);
        if (kDefault.m_fDamagedVibrateRatio != m_fDamagedVibrateRatio)
            FUN_14086f970(&elem, "damagedVibrateRatio", m_fDamagedVibrateRatio);
        if (m_nValue != kDefault.m_nValue)
            FUN_140873eb0(&elem, "value", m_nValue);
        if (m_strEffectRemain != kDefault.m_strEffectRemain)
            FUN_140874050(&elem, "effectRemain", m_strEffectRemain);
        if (m_strEffectHit != kDefault.m_strEffectHit)
            FUN_140874050(&elem, "effectHit", m_strEffectHit);
        if (m_bIgnoreOptimalHideDamageHitEffect != kDefault.m_bIgnoreOptimalHideDamageHitEffect)
            FUN_140873bc0(&elem, "IgnoreOptimalHideDamageHitEffect", m_bIgnoreOptimalHideDamageHitEffect);
        if (m_bIgnoreOptimalHideDamageRemainEffect != kDefault.m_bIgnoreOptimalHideDamageRemainEffect)
            FUN_140873bc0(&elem, "IgnoreOptimalHideDamageRemainEffect", m_bIgnoreOptimalHideDamageRemainEffect);
        if (kDefault.m_fDamageByTargetMaxHP != m_fDamageByTargetMaxHP)
            FUN_14086f970(&elem, "damageByTargetMaxHP", m_fDamageByTargetMaxHP);
        if (m_nIsConstDamageValue != kDefault.m_nIsConstDamageValue)
            FUN_140873ca0(&elem, "isConstDamageValue", m_nIsConstDamageValue);
        if (0 < m_nConstDamageByTargetHP)
            FUN_140873eb0(&elem, "constDamageByTargetHP", m_nConstDamageByTargetHP);
        if (0 < m_nConstDamageByTargetSP)
            FUN_140873eb0(&elem, "constDamageByTargetSP", m_nConstDamageByTargetSP);
        if (m_ePush != kDefault.m_ePush)
            FUN_140873ca0(&elem, "push", m_ePush);
        if (kDefault.m_fPushDistance != m_fPushDistance)
            FUN_14086f970(&elem, "pushdistance", m_fPushDistance);
        if (kDefault.m_fPushDuration != m_fPushDuration)
            FUN_14086f970(&elem, "pushduration", m_fPushDuration);
        if (kDefault.m_fPushProb != m_fPushProb)
            FUN_14086f970(&elem, "pushprob", m_fPushProb);
        if (m_ePushEaseType != kDefault.m_ePushEaseType)
            FUN_140873ca0(&elem, "pushEaseType", m_ePushEaseType);
        if (m_ePushApplyField != kDefault.m_ePushApplyField)
            FUN_140873ca0(&elem, "pushApplyField", m_ePushApplyField);
        if (kDefault.m_fPushUpDistance != m_fPushUpDistance)
            FUN_14086f970(&elem, "pushUpDistance", m_fPushUpDistance);
        if (m_nPushDown != kDefault.m_nPushDown)
            FUN_140873ca0(&elem, "pushDown", m_nPushDown);
        if (m_nPushFall != kDefault.m_nPushFall)
            FUN_140873ca0(&elem, "pushFall", m_nPushFall);
        if (m_nPushPriority != kDefault.m_nPushPriority)
            FUN_140873ca0(&elem, "pushPriority", m_nPushPriority);
        if (m_nPushPriorityHitImmune != kDefault.m_nPushPriorityHitImmune)
            FUN_140873ca0(&elem, "pushPriorityHitImmune", m_nPushPriorityHitImmune);
        if (m_strPushAnimation != kDefault.m_strPushAnimation)
            FUN_140874050(&elem, "pushAnimation", m_strPushAnimation);
        if (m_nAttackMaterial != kDefault.m_nAttackMaterial)
            FUN_140873ca0(&elem, "attackMaterial", m_nAttackMaterial);
        if (m_eStateHitIgnore != kDefault.m_eStateHitIgnore)
            FUN_140873ca0(&elem, "stateHitIgnore", m_eStateHitIgnore);
        if (m_eStateHitOnly != kDefault.m_eStateHitOnly)
            FUN_140873ca0(&elem, "stateHitOnly", m_eStateHitOnly);
        if (m_nSuperArmorBreak != kDefault.m_nSuperArmorBreak)
            FUN_140873ca0(&elem, "superArmorBreak", m_nSuperArmorBreak);
        if (m_nInvokeEffectDisable != kDefault.m_nInvokeEffectDisable)
            FUN_140873ca0(&elem, "invokeEffectDisable", m_nInvokeEffectDisable);
        if (m_nDamageEventDisable != kDefault.m_nDamageEventDisable)
            FUN_140873ca0(&elem, "damageEventDisable", m_nDamageEventDisable);
        FUN_14086e000(pParent, &elem);
    }
}

// @0x1407e0ee0
int SkillDamage::RollPush() const
{
    if (FUN_14028d470(m_fPushProb, 0.0f))
        return 0;
    if ((float)rand() / 32767.0f > m_fPushProb)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1407E0EE0, SkillDamage, RollPush, 81, 0xB1F402B8);

// @0x1407e0f40
int SkillDamage::HasDamage() const
{
    if (m_nValue > 0 || m_nConstDamageByTargetHP > 0 || m_fRate > 0.0f || m_fDamageByTargetMaxHP > 0.0f)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1407E0F40, SkillDamage, HasDamage, 67, 0x77822CDC);

// @0x1407e0f90
SkillPushType SkillDamage::GetPush(int nState) const
{
    int bGround = FUN_1403744a0(nState) || FUN_140374410(nState);
    if (bGround == 1 && m_ePushApplyField == 1)
        return (SkillPushType)0;
    else if (bGround == 0 && m_ePushApplyField == 2)
        return (SkillPushType)0;
    return m_ePush;
}
MS2_REPLACE_METHOD(0x1407E0F90, SkillDamage, GetPush, 128, 0x6FD0D1B0);

// @0x1407e1020
SkillPause::SkillPause()
{
    m_fDuration = 0;
    m_fShakeDuration = 0;
    m_fAmp = 0;
}

// @0x1407e1060
bool SkillPause::operator!=(const SkillPause& o) const
{
    if (m_fDuration != o.m_fDuration) return true;
    if (m_fShakeDuration != o.m_fShakeDuration) return true;
    if (m_fAmp != o.m_fAmp) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407E1060, SkillPause, operator!=, 86, 0x1A6E711F);

// @0x1407e10c0
int SkillPause::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pPause = pElem->FUN_140165cf0("pause");
    if (pPause)
    {
        FUN_140873360(pPause, "pauseDuration", m_fDuration);
        FUN_140873360(pPause, "pauseShakeDuration", m_fShakeDuration);
        FUN_140873360(pPause, "pauseAmp", m_fAmp);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1407E10C0, SkillPause, Load, 137, 0x804EC85A);

// @0x1407e1150
int SkillPause::Save(void*) const
{
    return 1;
}

// @0x1407e1170
float SkillPause::GetShakeRate() const
{
    if (0.0f < m_fShakeDuration)
        return 1.0f / m_fShakeDuration;
    return 1.0f;
}
MS2_REPLACE_METHOD(0x1407E1170, SkillPause, GetShakeRate, 48, 0x3CB21610);

// @0x1407e11b0
SkillChain::SkillChain()
{
}

// @0x1407e11e0
bool SkillChain::operator!=(const SkillChain& o) const
{
    if (m_strEffect != o.m_strEffect) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407E11E0, SkillChain, operator!=, 50, 0x3E310983);

// @0x1407e1220
int SkillChain::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pChain = pElem->FUN_140165cf0("chain");
    if (pChain)
        m_strEffect = FUN_14015f710(pChain, "effect", CString(""));
    return 1;
}
MS2_REPLACE_METHOD(0x1407E1220, SkillChain, Load, 169, 0x701C0A59);

// @0x1407e12d0
int SkillChain::Save(void*) const
{
    return 1;
}

// @0x1407e12f0
int SkillChain::HasEffect() const
{
    if (!m_strEffect.IsEmpty())
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1407E12F0, SkillChain, HasEffect, 44, 0xE24A25F2);

// @0x1407e1330
SkillAttackData::SkillAttackData()
    : m_eAttackType((SkillAttackType)0), m_eAttackMethodType((SkillAttackMethodType)0)
{
    m_nPointGroupID = 0;
    m_nTargetCount = 0;
    m_nDirection = 3;
    m_nMagicPathID = 0;
    m_nCubeMagicPathID = 0;
    m_nHitImmuneBreak = 0;
    m_nBrokenOffence = 0;
    m_fBrokenForce = 0;
    m_eUnrideOnHit = (SkillUnrideOnHit)0;
    m_nReleaseObjectWeaponOnHit = 1;
    m_eGrabTargetType = (SkillGrabTargetType)0;
}

// @0x1407e1500
bool SkillAttackData::operator!=(const SkillAttackData& o)
{
    if (m_eAttackType != o.m_eAttackType) return true;
    if (m_eAttackMethodType != o.m_eAttackMethodType) return true;
    if (m_strPoint != o.m_strPoint) return true;
    if (m_nPointGroupID != o.m_nPointGroupID) return true;
    if (m_nTargetCount != o.m_nTargetCount) return true;
    if (m_nMagicPathID != o.m_nMagicPathID) return true;
    if (m_nCubeMagicPathID != o.m_nCubeMagicPathID) return true;
    if (m_nDirection != o.m_nDirection) return true;
    if (m_nHitImmuneBreak != o.m_nHitImmuneBreak) return true;
    if (m_nBrokenOffence != o.m_nBrokenOffence) return true;
    if (m_fBrokenForce != o.m_fBrokenForce) return true;
    if (m_eGrabTargetType != o.m_eGrabTargetType) return true;
    if (!IsSameStringArray(m_arrGrabNodeCategory, o.m_arrGrabNodeCategory)) return true;
    if (m_strCompulsionType != o.m_strCompulsionType) return true;
    if (m_compulsionType != o.m_compulsionType) return true;
    if (m_eUnrideOnHit != o.m_eUnrideOnHit) return true;
    if (m_nReleaseObjectWeaponOnHit != o.m_nReleaseObjectWeaponOnHit) return true;
    if (m_range.FUN_140800920(o.m_range)) return true;
    if (m_arrow != o.m_arrow) return true;
    if (m_damage != o.m_damage) return true;
    if (m_vSkill.size() != o.m_vSkill.size()) return true;
    for (unsigned __int64 i = 0; i < m_vSkill.size(); i++)
    {
        if (*m_vSkill[i] != *o.m_vSkill[i]) return true;
    }
    if (m_vAdditional.size() != o.m_vAdditional.size()) return true;
    for (unsigned __int64 i = 0; i < m_vAdditional.size(); i++)
    {
        if (*m_vAdditional[i] != *o.m_vAdditional[i]) return true;
    }
    if (m_pause != o.m_pause) return true;
    if (!IsSameVector(m_vSplashActiveSkillID, o.m_vSplashActiveSkillID)) return true;
    if (m_chain != o.m_chain) return true;
    return false;
}
MS2_REPLACE_METHOD(0x1407E1500, SkillAttackData, operator!=, 1202, 0x22A7917B);

// @0x1407e19c0
unsigned char SkillAttackData::HasPause() const
{
    int nResult;
    if (!(0.0f < m_pause.m_fDuration) && !(0.0f < m_pause.m_fShakeDuration))
        nResult = 0;
    else
        nResult = 1;
    return nResult;
}
MS2_REPLACE_METHOD(0x1407E19C0, SkillAttackData, HasPause, 68, 0xECAB277E);

// @0x1407e1a10
SkillAttackMethodType SkillAttackData::GetAttackMethodType() const
{
    return m_eAttackMethodType;
}
MS2_REPLACE_METHOD(0x1407E1A10, SkillAttackData, GetAttackMethodType, 17, 0x35E2B565);

// @0x1407e1a30
const CString& SkillAttackData::GetArrowEffect() const
{
    return m_arrow.m_strEffect;
}
MS2_REPLACE_METHOD(0x1407E1A30, SkillAttackData, GetArrowEffect, 17, 0x05460BBA);

// @0x1407e1a50
int SkillAttackData::Load(Unk_140165cf0* pElem)
{
    FUN_1408733e0(pElem, "point", m_strPoint);
    FUN_140873220(pElem, "pointGroupID", m_nPointGroupID);
    FUN_1408731e0(pElem, "targetCount", m_nTargetCount);
    FUN_1408731e0(pElem, "magicPathID", m_nMagicPathID);
    FUN_1408731e0(pElem, "cubeMagicPathID", m_nCubeMagicPathID);
    FUN_1408731e0(pElem, "direction", m_nDirection);
    XmlValue(pElem, "attacktype", m_eAttackType);
    XmlValue(pElem, "attackMethodType", m_eAttackMethodType);
    FUN_1408731e0(pElem, "hitImmuneBreak", m_nHitImmuneBreak);
    FUN_1408731e0(pElem, "brokenOffence", m_nBrokenOffence);
    FUN_140873360(pElem, "brokenForce", m_fBrokenForce);
    XmlValue(pElem, "unrideOnHit", m_eUnrideOnHit);
    FUN_1408731e0(pElem, "releaseObjectWeaponOnHit", m_nReleaseObjectWeaponOnHit);
    ATL::CAtlArray<unsigned> arrCompulsion;
    XmlTokenList(pElem, "compulsionType", arrCompulsion);
    for (unsigned i = 0; i < arrCompulsion.GetCount(); i++)
    {
        unsigned nType = arrCompulsion[i];
        m_compulsionType.set(nType, true);
    }
    XmlValue(pElem, "grabTargetType", m_eGrabTargetType);
    XmlTokenList(pElem, "grabNodeCategory", m_arrGrabNodeCategory);
    XmlTokenList(pElem, "splashActiveSkillID", m_vSplashActiveSkillID);
    if (!m_pause.Load(pElem))
        return 0;
    m_range.LoadElement(pElem, CString("range"));
    if (!m_chain.Load(pElem))
        return 0;
    if (!m_arrow.Load(pElem))
        return 0;
    if (!m_damage.Load(pElem))
        return 0;
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("actionAdditional"))
    {
        MS2Ptr<SkillActionAdditional> spAction(new SkillActionAdditional);
        if (!spAction->Load(pChild))
            return 0;
        m_vAdditional.push_back(spAction);
    }
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("actionSkill"))
    {
        MS2Ptr<SkillActionSkill> spAction(new SkillActionSkill);
        if (!spAction->Load(pChild))
            return 0;
        m_vSkill.push_back(spAction);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1407E1A50, SkillAttackData, Load, 1824, 0x428107E3);

// @0x1407e2180
int SkillAttackData::Save(void* pParent)
{
    static SkillAttackData kDefault;
    if (*this != kDefault)
    {
        Unk_TiXmlElement elem("attack");
        if (m_strPoint != kDefault.m_strPoint)
            FUN_140874050(&elem, "point", m_strPoint);
        if (m_nPointGroupID != kDefault.m_nPointGroupID)
            FUN_140873ce0(&elem, "pointGroupID", m_nPointGroupID);
        if (m_nTargetCount != kDefault.m_nTargetCount)
            FUN_140873ca0(&elem, "targetCount", m_nTargetCount);
        if (m_nMagicPathID != kDefault.m_nMagicPathID)
            FUN_140873ca0(&elem, "magicPathID", m_nMagicPathID);
        if (m_nCubeMagicPathID != kDefault.m_nCubeMagicPathID)
            FUN_140873ca0(&elem, "cubeMagicPathID", m_nCubeMagicPathID);
        if (m_nDirection != kDefault.m_nDirection)
            FUN_140873ca0(&elem, "direction", m_nDirection);
        if (m_eAttackType != kDefault.m_eAttackType)
            FUN_140873ca0(&elem, "attacktype", m_eAttackType);
        if (m_eAttackMethodType != kDefault.m_eAttackMethodType)
            FUN_140873ca0(&elem, "attackMethodType", m_eAttackMethodType);
        if (m_nHitImmuneBreak != kDefault.m_nHitImmuneBreak)
            FUN_140873ca0(&elem, "hitImmuneBreak", m_nHitImmuneBreak);
        if (m_nBrokenOffence != kDefault.m_nBrokenOffence)
            FUN_140873ca0(&elem, "brokenOffence", m_nBrokenOffence);
        if (kDefault.m_fBrokenForce != m_fBrokenForce)
            FUN_14086f970(&elem, "brokenForce", m_fBrokenForce);
        if (m_eUnrideOnHit != kDefault.m_eUnrideOnHit)
            FUN_140873ca0(&elem, "unrideOnHit", m_eUnrideOnHit);
        if (m_nReleaseObjectWeaponOnHit != kDefault.m_nReleaseObjectWeaponOnHit)
            FUN_140873ca0(&elem, "releaseObjectWeaponOnHit", m_nReleaseObjectWeaponOnHit);
        if (m_strCompulsionType != kDefault.m_strCompulsionType)
            FUN_140874050(&elem, "compulsionType", m_strCompulsionType);
        if (m_eGrabTargetType != kDefault.m_eGrabTargetType)
            FUN_140873ce0(&elem, "grabTargetType", m_eGrabTargetType);
        m_pause.Save(&elem);
        m_range.SaveElement(&elem, CString("rangeProperty"));
        m_chain.Save(&elem);
        m_arrow.Save(&elem);
        m_damage.Save(&elem);
        for (unsigned i = 0; i < m_vSkill.size(); i++)
        {
            SkillActionSkill* pSkill = m_vSkill[i].get();
            if (!pSkill->Save(&elem, CString("conditionSkill")))
                return 0;
        }
        FUN_14086e000(pParent, &elem);
    }
    return 1;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c030-0x142c9c090 .text$yd
