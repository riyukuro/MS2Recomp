// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SkillAttackData: one <attack> of a skill motion and its
// XML blocks (arrow, damage, pause, chain): constructors, XML readers/writers and comparisons.
// MS2-UNIT: ?\skillattackdata.cpp
// MS2-RANGE: 0x1407dee30-0x1407e5b80 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "ms2/commonfiles/skillattackdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/tinyxml.h"
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0

// Unrecovered helpers.
int XmlGetAttr(class TiXmlElement*, char const*, __int64&);   // C3: was FUN_1408732e0
void FUN_140873e30(void* pElem, const char* pszName, float fValue);
void XmlSetAttr(class TiXmlElement*, char const*, bool);   // C3: was FUN_140873bc0
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
void XmlSetAttr(class TiXmlElement*, char const*, unsigned int);   // C3: was FUN_140873ce0
void XmlSetAttr(class TiXmlElement*, char const*, __int64 const&);   // C3: was FUN_140873eb0
void XmlSetAttr(class TiXmlElement*, char const*, CStringA const&);   // C3: was FUN_140874050
efd::Point3 FUN_14028f060(CString str);                                    // "x, y, z" -> point
CString FUN_14028ef00(efd::Point3 kPoint);                                 // point -> "x, y, z"
bool FUN_14028d470(float a, float b);                                      // nearly equal
class CFieldData   // C3: member view for the former free stand-ins
{
public:
    static bool FUN_140374410(int);
    static bool FUN_1403744a0(int);
};
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
    Unk_140165cf0* pArrow = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("arrow"));
    if (pArrow == 0)
        return 1;
    XmlGetAttr((class TiXmlElement*)(pArrow), "overlap", reinterpret_cast<int&>(m_nOverlap));
    XmlGetAttr((class TiXmlElement*)(pArrow), "explosion", reinterpret_cast<int&>(m_nExplosion));
    XmlGetAttr((class TiXmlElement*)(pArrow), "rayPhysxTest", reinterpret_cast<int&>(m_nRayPhysxTest));
    XmlValue(pArrow, "nonTarget", m_eNonTarget);
    XmlGetAttr((class TiXmlElement*)(pArrow), "bounceType", reinterpret_cast<int&>(m_nBounceType));
    XmlGetAttr((class TiXmlElement*)(pArrow), "bounceCount", reinterpret_cast<int&>(m_nBounceCount));
    XmlGetAttr((class TiXmlElement*)(pArrow), "bounceRadius", reinterpret_cast<float&>(m_fBounceRadius));
    XmlGetAttr((class TiXmlElement*)(pArrow), "bounceOverlap", reinterpret_cast<int&>(m_nBounceOverlap));
    *reinterpret_cast<efd::Point3*>(&m_collision) = FUN_14028f060(Unk_ReadString((class Unk_XmlNode*)(pArrow), "collision", CString("")));
    *reinterpret_cast<efd::Point3*>(&m_collisionAdd) = FUN_14028f060(Unk_ReadString((class Unk_XmlNode*)(pArrow), "collisionAdd", CString("")));
    m_strEffect = Unk_ReadString((class Unk_XmlNode*)(pArrow), "effect", CString(""));
    m_strEffectRemain = Unk_ReadString((class Unk_XmlNode*)(pArrow), "effectRemain", CString(""));
    m_strEffectDestroy = Unk_ReadString((class Unk_XmlNode*)(pArrow), "effectDestroy", CString(""));
    m_strTargetKeepEffect = Unk_ReadString((class Unk_XmlNode*)(pArrow), "targetKeepEffect", CString(""));
    m_strEffectInvoke = Unk_ReadString((class Unk_XmlNode*)(pArrow), "effectInvoke", CString(""));
    XmlGetAttr((class TiXmlElement*)(pArrow), "rayType", reinterpret_cast<int&>(m_nRayType));
    return 1;
}
MS2_REPLACE_METHOD(0x1407DF190, SkillArrow, Load, 1351, 0x56FCF58F);

// @0x1407df6e0
void SkillArrow::Save(void* pParent)
{
    static SkillArrow kDefault;
    if (*this != kDefault)
    {
        TiXmlElement elem("arrowProperty");
        if (m_nOverlap != kDefault.m_nOverlap)
            XmlSetAttr(&elem, "overlap", (int)m_nOverlap);
        if (m_nExplosion != kDefault.m_nExplosion)
            XmlSetAttr(&elem, "explosion", (int)m_nExplosion);
        if (m_nRayPhysxTest != kDefault.m_nRayPhysxTest)
            XmlSetAttr(&elem, "rayPhysxTest", (int)m_nRayPhysxTest);
        if (m_eNonTarget != kDefault.m_eNonTarget)
            XmlSetAttr(&elem, "nonTarget", (int)m_eNonTarget);
        if (m_nBounceType != kDefault.m_nBounceType)
            XmlSetAttr(&elem, "bounceType", (int)m_nBounceType);
        if (m_nBounceCount != kDefault.m_nBounceCount)
            XmlSetAttr(&elem, "bounceCount", (int)m_nBounceCount);
        if (kDefault.m_fBounceRadius != m_fBounceRadius)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("bounceRadius", m_fBounceRadius);
        if (m_nBounceOverlap != kDefault.m_nBounceOverlap)
            XmlSetAttr(&elem, "bounceOverlap", (int)m_nBounceOverlap);
        if (m_collision != kDefault.m_collision)
            XmlSetAttr((class TiXmlElement*)(&elem), "collision", FUN_14028ef00(m_collision));
        if (m_collisionAdd != kDefault.m_collisionAdd)
            XmlSetAttr((class TiXmlElement*)(&elem), "collisionAdd", FUN_14028ef00(m_collisionAdd));
        if (m_strEffect != kDefault.m_strEffect)
            XmlSetAttr((class TiXmlElement*)(&elem), "effect", m_strEffect);
        if (m_strEffectRemain != kDefault.m_strEffectRemain)
            XmlSetAttr((class TiXmlElement*)(&elem), "effectRemain", m_strEffectRemain);
        if (m_strEffectDestroy != kDefault.m_strEffectDestroy)
            XmlSetAttr((class TiXmlElement*)(&elem), "effectDestroy", m_strEffectDestroy);
        if (m_strTargetKeepEffect != kDefault.m_strTargetKeepEffect)
            XmlSetAttr((class TiXmlElement*)(&elem), "targetKeepEffect", m_strTargetKeepEffect);
        if (m_nRayType != kDefault.m_nRayType)
            XmlSetAttr(&elem, "rayType", (int)m_nRayType);
        if (!m_strEffectInvoke.IsEmpty())
            XmlSetAttr((class TiXmlElement*)(&elem), "effectInvoke", m_strEffectInvoke);
        static_cast<TiXmlNode*>(pParent)->InsertEndChild(elem);
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
    Unk_140165cf0* pDamage = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("damage"));
    if (pDamage == 0)
        return 1;
    XmlGetAttr((class TiXmlElement*)(pDamage), "count", reinterpret_cast<int&>(m_nCount));
    XmlGetAttr((class TiXmlElement*)(pDamage), "hand", reinterpret_cast<int&>(m_nHand));
    XmlGetAttr((class TiXmlElement*)(pDamage), "rate", reinterpret_cast<float&>(m_fRate));
    XmlGetAttr((class TiXmlElement*)(pDamage), "hitSpeedRate", reinterpret_cast<float&>(m_fHitSpeedRate));
    XmlGetAttr((class TiXmlElement*)(pDamage), "hitPauseTime", reinterpret_cast<float&>(m_fHitPauseTime));
    XmlGetAttr((class TiXmlElement*)(pDamage), "damagedVibrateRatio", reinterpret_cast<float&>(m_fDamagedVibrateRatio));
    XmlGetAttr((class TiXmlElement*)(pDamage), "value", *(__int64*)(&m_nValue));
    m_strEffectRemain = Unk_ReadString((class Unk_XmlNode*)(pDamage), "effectRemain", CString(""));
    m_strEffectHit = Unk_ReadString((class Unk_XmlNode*)(pDamage), "effectHit", CString(""));
    XmlGetAttr((class TiXmlElement*)(pDamage), "IgnoreOptimalHideDamageHitEffect", reinterpret_cast<bool&>(m_bIgnoreOptimalHideDamageHitEffect));
    XmlGetAttr((class TiXmlElement*)(pDamage), "IgnoreOptimalHideDamageRemainEffect", reinterpret_cast<bool&>(m_bIgnoreOptimalHideDamageRemainEffect));
    XmlGetAttr((class TiXmlElement*)(pDamage), "damageByTargetMaxHP", reinterpret_cast<float&>(m_fDamageByTargetMaxHP));
    XmlGetAttr((class TiXmlElement*)(pDamage), "isConstDamageValue", reinterpret_cast<int&>(m_nIsConstDamageValue));
    XmlGetAttr((class TiXmlElement*)(pDamage), "constDamageByTargetHP", *(__int64*)(&m_nConstDamageByTargetHP));
    XmlGetAttr((class TiXmlElement*)(pDamage), "constDamageByTargetSP", *(__int64*)(&m_nConstDamageByTargetSP));
    XmlValue(pDamage, "push", m_ePush);
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushdistance", reinterpret_cast<float&>(m_fPushDistance));
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushduration", reinterpret_cast<float&>(m_fPushDuration));
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushprob", reinterpret_cast<float&>(m_fPushProb));
    XmlValue(pDamage, "pushEaseType", m_ePushEaseType);
    if (m_ePushEaseType < 0 || m_ePushEaseType > 2)
        m_ePushEaseType = (SkillPushEaseType)0;
    XmlValue(pDamage, "pushApplyField", m_ePushApplyField);
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushUpDistance", reinterpret_cast<float&>(m_fPushUpDistance));
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushDown", reinterpret_cast<int&>(m_nPushDown));
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushFall", reinterpret_cast<int&>(m_nPushFall));
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushPriority", reinterpret_cast<int&>(m_nPushPriority));
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushPriorityHitImmune", reinterpret_cast<int&>(m_nPushPriorityHitImmune));
    XmlGetAttr((class TiXmlElement*)(pDamage), "pushAnimation", m_strPushAnimation);
    XmlGetAttr((class TiXmlElement*)(pDamage), "attackMaterial", reinterpret_cast<int&>(m_nAttackMaterial));
    XmlValue(pDamage, "stateHitIgnore", m_eStateHitIgnore);
    XmlValue(pDamage, "stateHitOnly", m_eStateHitOnly);
    XmlGetAttr((class TiXmlElement*)(pDamage), "superArmorBreak", reinterpret_cast<int&>(m_nSuperArmorBreak));
    XmlGetAttr((class TiXmlElement*)(pDamage), "invokeEffectDisable", reinterpret_cast<int&>(m_nInvokeEffectDisable));
    XmlGetAttr((class TiXmlElement*)(pDamage), "damageEventDisable", reinterpret_cast<int&>(m_nDamageEventDisable));
    return 1;
}
MS2_REPLACE_METHOD(0x1407E01C0, SkillDamage, Load, 1363, 0x702F5867);

// @0x1407e0720
void SkillDamage::Save(void* pParent)
{
    static SkillDamage kDefault;
    if (*this != kDefault)
    {
        TiXmlElement elem("damageProperty");
        if (m_nCount != kDefault.m_nCount)
            XmlSetAttr(&elem, "count", (int)m_nCount);
        if (m_nHand != kDefault.m_nHand)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("hand", m_nHand);
        if (kDefault.m_fRate != m_fRate)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("rate", m_fRate);
        if (kDefault.m_fHitSpeedRate != m_fHitSpeedRate)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("hitSpeedRate", m_fHitSpeedRate);
        if (kDefault.m_fHitPauseTime != m_fHitPauseTime)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("hitPauseTime", m_fHitPauseTime);
        if (kDefault.m_fDamagedVibrateRatio != m_fDamagedVibrateRatio)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("damagedVibrateRatio", m_fDamagedVibrateRatio);
        if (m_nValue != kDefault.m_nValue)
            XmlSetAttr(&elem, "value", m_nValue);
        if (m_strEffectRemain != kDefault.m_strEffectRemain)
            XmlSetAttr((class TiXmlElement*)(&elem), "effectRemain", m_strEffectRemain);
        if (m_strEffectHit != kDefault.m_strEffectHit)
            XmlSetAttr((class TiXmlElement*)(&elem), "effectHit", m_strEffectHit);
        if (m_bIgnoreOptimalHideDamageHitEffect != kDefault.m_bIgnoreOptimalHideDamageHitEffect)
            XmlSetAttr(&elem, "IgnoreOptimalHideDamageHitEffect", m_bIgnoreOptimalHideDamageHitEffect);
        if (m_bIgnoreOptimalHideDamageRemainEffect != kDefault.m_bIgnoreOptimalHideDamageRemainEffect)
            XmlSetAttr(&elem, "IgnoreOptimalHideDamageRemainEffect", m_bIgnoreOptimalHideDamageRemainEffect);
        if (kDefault.m_fDamageByTargetMaxHP != m_fDamageByTargetMaxHP)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("damageByTargetMaxHP", m_fDamageByTargetMaxHP);
        if (m_nIsConstDamageValue != kDefault.m_nIsConstDamageValue)
            XmlSetAttr(&elem, "isConstDamageValue", (int)m_nIsConstDamageValue);
        if (0 < m_nConstDamageByTargetHP)
            XmlSetAttr(&elem, "constDamageByTargetHP", m_nConstDamageByTargetHP);
        if (0 < m_nConstDamageByTargetSP)
            XmlSetAttr(&elem, "constDamageByTargetSP", m_nConstDamageByTargetSP);
        if (m_ePush != kDefault.m_ePush)
            XmlSetAttr(&elem, "push", (int)m_ePush);
        if (kDefault.m_fPushDistance != m_fPushDistance)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("pushdistance", m_fPushDistance);
        if (kDefault.m_fPushDuration != m_fPushDuration)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("pushduration", m_fPushDuration);
        if (kDefault.m_fPushProb != m_fPushProb)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("pushprob", m_fPushProb);
        if (m_ePushEaseType != kDefault.m_ePushEaseType)
            XmlSetAttr(&elem, "pushEaseType", (int)m_ePushEaseType);
        if (m_ePushApplyField != kDefault.m_ePushApplyField)
            XmlSetAttr(&elem, "pushApplyField", (int)m_ePushApplyField);
        if (kDefault.m_fPushUpDistance != m_fPushUpDistance)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("pushUpDistance", m_fPushUpDistance);
        if (m_nPushDown != kDefault.m_nPushDown)
            XmlSetAttr(&elem, "pushDown", (int)m_nPushDown);
        if (m_nPushFall != kDefault.m_nPushFall)
            XmlSetAttr(&elem, "pushFall", (int)m_nPushFall);
        if (m_nPushPriority != kDefault.m_nPushPriority)
            XmlSetAttr(&elem, "pushPriority", (int)m_nPushPriority);
        if (m_nPushPriorityHitImmune != kDefault.m_nPushPriorityHitImmune)
            XmlSetAttr(&elem, "pushPriorityHitImmune", (int)m_nPushPriorityHitImmune);
        if (m_strPushAnimation != kDefault.m_strPushAnimation)
            XmlSetAttr((class TiXmlElement*)(&elem), "pushAnimation", m_strPushAnimation);
        if (m_nAttackMaterial != kDefault.m_nAttackMaterial)
            XmlSetAttr(&elem, "attackMaterial", (int)m_nAttackMaterial);
        if (m_eStateHitIgnore != kDefault.m_eStateHitIgnore)
            XmlSetAttr(&elem, "stateHitIgnore", (int)m_eStateHitIgnore);
        if (m_eStateHitOnly != kDefault.m_eStateHitOnly)
            XmlSetAttr(&elem, "stateHitOnly", (int)m_eStateHitOnly);
        if (m_nSuperArmorBreak != kDefault.m_nSuperArmorBreak)
            XmlSetAttr(&elem, "superArmorBreak", (int)m_nSuperArmorBreak);
        if (m_nInvokeEffectDisable != kDefault.m_nInvokeEffectDisable)
            XmlSetAttr(&elem, "invokeEffectDisable", (int)m_nInvokeEffectDisable);
        if (m_nDamageEventDisable != kDefault.m_nDamageEventDisable)
            XmlSetAttr(&elem, "damageEventDisable", (int)m_nDamageEventDisable);
        static_cast<TiXmlNode*>(pParent)->InsertEndChild(elem);
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
    int bGround = CFieldData::FUN_1403744a0(nState) || CFieldData::FUN_140374410(nState);
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
    Unk_140165cf0* pPause = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("pause"));
    if (pPause)
    {
        XmlGetAttr((class TiXmlElement*)(pPause), "pauseDuration", reinterpret_cast<float&>(m_fDuration));
        XmlGetAttr((class TiXmlElement*)(pPause), "pauseShakeDuration", reinterpret_cast<float&>(m_fShakeDuration));
        XmlGetAttr((class TiXmlElement*)(pPause), "pauseAmp", reinterpret_cast<float&>(m_fAmp));
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
    Unk_140165cf0* pChain = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("chain"));
    if (pChain)
        m_strEffect = Unk_ReadString((class Unk_XmlNode*)(pChain), "effect", CString(""));
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
    XmlGetAttr((class TiXmlElement*)(pElem), "point", m_strPoint);
    XmlGetAttr((class TiXmlElement*)(pElem), "pointGroupID", reinterpret_cast<unsigned int&>(m_nPointGroupID));
    XmlGetAttr((class TiXmlElement*)(pElem), "targetCount", reinterpret_cast<int&>(m_nTargetCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "magicPathID", reinterpret_cast<int&>(m_nMagicPathID));
    XmlGetAttr((class TiXmlElement*)(pElem), "cubeMagicPathID", reinterpret_cast<int&>(m_nCubeMagicPathID));
    XmlGetAttr((class TiXmlElement*)(pElem), "direction", reinterpret_cast<int&>(m_nDirection));
    XmlValue(pElem, "attacktype", m_eAttackType);
    XmlValue(pElem, "attackMethodType", m_eAttackMethodType);
    XmlGetAttr((class TiXmlElement*)(pElem), "hitImmuneBreak", reinterpret_cast<int&>(m_nHitImmuneBreak));
    XmlGetAttr((class TiXmlElement*)(pElem), "brokenOffence", reinterpret_cast<int&>(m_nBrokenOffence));
    XmlGetAttr((class TiXmlElement*)(pElem), "brokenForce", reinterpret_cast<float&>(m_fBrokenForce));
    XmlValue(pElem, "unrideOnHit", m_eUnrideOnHit);
    XmlGetAttr((class TiXmlElement*)(pElem), "releaseObjectWeaponOnHit", reinterpret_cast<int&>(m_nReleaseObjectWeaponOnHit));
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
    for (Unk_140165cf0* pChild : ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("actionAdditional")))
    {
        MS2Ptr<SkillActionAdditional> spAction(new SkillActionAdditional);
        if (!spAction->Load(pChild))
            return 0;
        m_vAdditional.push_back(spAction);
    }
    for (Unk_140165cf0* pChild : ((class Unk_140165cf0*)((class Unk_XmlNode*)(pElem))->FirstChild("actionSkill")))
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
        TiXmlElement elem("attack");
        if (m_strPoint != kDefault.m_strPoint)
            XmlSetAttr((class TiXmlElement*)(&elem), "point", m_strPoint);
        if (m_nPointGroupID != kDefault.m_nPointGroupID)
            XmlSetAttr(&elem, "pointGroupID", (unsigned int)m_nPointGroupID);
        if (m_nTargetCount != kDefault.m_nTargetCount)
            XmlSetAttr(&elem, "targetCount", (int)m_nTargetCount);
        if (m_nMagicPathID != kDefault.m_nMagicPathID)
            XmlSetAttr(&elem, "magicPathID", (int)m_nMagicPathID);
        if (m_nCubeMagicPathID != kDefault.m_nCubeMagicPathID)
            XmlSetAttr(&elem, "cubeMagicPathID", (int)m_nCubeMagicPathID);
        if (m_nDirection != kDefault.m_nDirection)
            XmlSetAttr(&elem, "direction", (int)m_nDirection);
        if (m_eAttackType != kDefault.m_eAttackType)
            XmlSetAttr(&elem, "attacktype", (int)m_eAttackType);
        if (m_eAttackMethodType != kDefault.m_eAttackMethodType)
            XmlSetAttr(&elem, "attackMethodType", (int)m_eAttackMethodType);
        if (m_nHitImmuneBreak != kDefault.m_nHitImmuneBreak)
            XmlSetAttr(&elem, "hitImmuneBreak", (int)m_nHitImmuneBreak);
        if (m_nBrokenOffence != kDefault.m_nBrokenOffence)
            XmlSetAttr(&elem, "brokenOffence", (int)m_nBrokenOffence);
        if (kDefault.m_fBrokenForce != m_fBrokenForce)
            reinterpret_cast<TiXmlElement*>(&elem)->SetDoubleAttribute("brokenForce", m_fBrokenForce);
        if (m_eUnrideOnHit != kDefault.m_eUnrideOnHit)
            XmlSetAttr(&elem, "unrideOnHit", (int)m_eUnrideOnHit);
        if (m_nReleaseObjectWeaponOnHit != kDefault.m_nReleaseObjectWeaponOnHit)
            XmlSetAttr(&elem, "releaseObjectWeaponOnHit", (int)m_nReleaseObjectWeaponOnHit);
        if (m_strCompulsionType != kDefault.m_strCompulsionType)
            XmlSetAttr((class TiXmlElement*)(&elem), "compulsionType", m_strCompulsionType);
        if (m_eGrabTargetType != kDefault.m_eGrabTargetType)
            XmlSetAttr(&elem, "grabTargetType", (unsigned int)m_eGrabTargetType);
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
        static_cast<TiXmlNode*>(pParent)->InsertEndChild(elem);
    }
    return 1;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9c030-0x142c9c090 .text$yd
