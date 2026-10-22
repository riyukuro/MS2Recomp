// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The <basic> blocks of a skill: sensor, actionSkill,
// actionAdditional, glide, combo/push/autoTargeting/changeSkill/magicControl, one <level> (SkillLevelData) and one
// <motion> (SkillMotionData): constructors, XML readers/writers, comparisons and accessors.
// MS2-UNIT: unit_1408011f0
// MS2-RANGE: 0x1408011f0-0x1408092d0 .text$mn
// MS2-RANGE: 0x1400bcc10-0x1400bcdf0 .text$di
// MS2-RANGE: 0x142c9c110-0x142c9c200 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1SkillActionSkill@@UEAA@XZ 0x140802420 ; unique
// MS2-PIN: ??_GSkillActionAdditional@@UEAAPEAXI@Z 0x140802470 ; unique
// MS2-PIN: ??_GSkillActionSkill@@UEAAPEAXI@Z 0x1408024b0 ; unique
// MS2-PIN: ??1SkillGlideData@@UEAA@XZ 0x140802ae0 ; unique
// MS2-PIN: ??_GSkillGlideData@@UEAAPEAXI@Z 0x140802b70 ; unique
// MS2-PIN: ??$_Get_unwrapped_n@V?$MS2Ptr@VSkillActionAdditional@@@@_J$0A@@std@@YAPEAV?$MS2Ptr@VSkillActionAdditional@@@@QEAV1@_J@Z 0x140805770 ; unique
// MS2-PIN: ??$emplace_back@AEBV?$MS2Ptr@VSkillMotionData@@@@@?$vector@V?$MS2Ptr@VSkillMotionData@@@@V?$allocator@V?$MS2Ptr@VSkillMotionData@@@@@std@@@std@@QEAAXAEBV?$MS2Ptr@VSkillMotionData@@@@@Z 0x140805e30 ; prop
// MS2-PIN: ??$move@AEAV?$MS2Ptr@VSkillActionAdditional@@@@@std@@YA$$QEAV?$MS2Ptr@VSkillActionAdditional@@@@AEAV1@@Z 0x140805ff0 ; unique
// MS2-PIN: ?_Calculate_growth@?$vector@V?$MS2Ptr@VSkillActionAdditional@@@@V?$allocator@V?$MS2Ptr@VSkillActionAdditional@@@@@std@@@std@@AEBA_K_K@Z 0x140806640 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@V?$MS2Ptr@VSkillMotionData@@@@V?$allocator@V?$MS2Ptr@VSkillMotionData@@@@@std@@@std@@AEBA_NXZ 0x140806a80 ; prop
// MS2-PIN: ?_Umove@?$vector@V?$MS2Ptr@VSkillActionAdditional@@@@V?$allocator@V?$MS2Ptr@VSkillActionAdditional@@@@@std@@@std@@AEAAPEAV?$MS2Ptr@VSkillActionAdditional@@@@PEAV3@00@Z 0x140806cf0 ; prop
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$MS2Ptr@VSkillActionAdditional@@@@V?$allocator@V?$MS2Ptr@VSkillActionAdditional@@@@@std@@@std@@AEAAXPEAV?$MS2Ptr@VSkillActionAdditional@@@@00U?$integral_constant@_N$0A@@2@@Z 0x140806d70 ; prop
// MS2-PIN: ?allocate@?$allocator@V?$MS2Ptr@VSkillMotionData@@@@@std@@QEAAPEAV?$MS2Ptr@VSkillMotionData@@@@_K@Z 0x140806f30 ; prop
// MS2-PIN: ?max_size@?$vector@V?$MS2Ptr@VSkillActionAdditional@@@@V?$allocator@V?$MS2Ptr@VSkillActionAdditional@@@@@std@@@std@@QEBA_KXZ 0x140807100 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??$Combine@_J@Unk_HashKey@@QEAAXAEB_J@Z 0x140805f50
// MS2-PIN: ?Finish@Unk_HashKey@@QEAAXXZ 0x1408070d0
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include <algorithm>
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/commonfiles/skillactionskill.h"
#include "ms2/commonfiles/portaldata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "hook/ms2hook.h"

// Header statics (header_statics_a.h) followed by the motion prototype.
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static MS2Ptr<SkillMotionData> s_spMotion(new SkillMotionData);

// Unrecovered helpers.
void FUN_140873dc0(void* pElem, const char* pszName, unsigned nTicks);     // SetAttribute(name, tick value)
void FUN_140873e30(void* pElem, const char* pszName, float fValue);
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);          // SetAttribute(name, int)
void FUN_140873ce0(void* pElem, const char* pszName, unsigned nValue);     // SetAttribute(name, unsigned)
void FUN_140873c60(void* pElem, const char* pszName, unsigned short nValue);   // SetAttribute(name, unsigned short)
void FUN_1408740a0(void* pElem, const char* pszName, const CStringW& strValue); // SetAttribute(name, wide string)
void* FUN_14086e000(void* pParent, const void* pChild);                    // InsertEndChild
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);        // int attribute with a default
float FUN_1401973d0(Unk_140165cf0* pElem, const char* pszName, float fDefault);    // float attribute with a default
bool FUN_1401647e0(const CString&, const CString&);                        // the strings differ
bool FUN_1401c0090(const CString&, const CString&);                        // the strings are the same
float FUN_14028d280(unsigned uMilliseconds);
int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
void FUN_14015f0b0(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);  // split into strings
class Unk_LaunchOptions
{
public:
    bool FUN_1406af020();
};
Unk_LaunchOptions* FUN_1406aeee0();
float FUN_14028d3a0(float fValue);
const float& FUN_140805fc0(const float&, const float&);                    // std::max
class Unk_ActionLog;
Unk_ActionLog* FUN_140166440();
void FUN_140177a80(Unk_ActionLog* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const unsigned* pArg);
// A running hash key: Combine is the boost-style hash_combine.
struct Unk_HashKey
{
    unsigned __int64 m_nHash;
    void Finish() {}
    template <class T> void Combine(const T& value)
    {
        m_nHash ^= value + 0x9e3779b9 + (m_nHash << 6) + (m_nHash >> 2);
        Finish();
    }
};
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (unsigned i = 0; i < a.GetCount(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
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

// Unit-local view of the game's TiXmlElement (0x90 bytes).
class Unk_TiXmlAttribute
{
public:
    void* unknown00[7];                         // TiXmlBase, document, name, value, prev
    Unk_TiXmlAttribute* next;                   // +0x38
};
MS2_CHECK_SIZE(Unk_TiXmlAttribute, 0x40);

class Unk_TiXmlAttributeSet
{
public:
    // @0x140552d70
    Unk_TiXmlAttribute* First() { return (sentinel.next == &sentinel) ? 0 : sentinel.next; }
    Unk_TiXmlAttribute sentinel;
};

class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
    // @0x140552e00
    bool HasAttributes() { return attributeSet.First() == 0 ? false : true; }
    // @0x140552e40
    bool HasChildren() { return firstChild == 0 ? false : true; }
    // @0x140552e70
    bool HasContent() { return HasAttributes() || HasChildren(); }
private:
    void* unknown00[5];                         // TiXmlBase, parent, type
    void* firstChild;                           // +0x28
    void* unknown30[4];                         // lastChild, value, prev, next
    Unk_TiXmlAttributeSet attributeSet;         // +0x50
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);

// @0x1408011f0
Unk_SkillSensor::Unk_SkillSensor()
{
    m_nSensorStartDelay = 0;
    m_nSensorSplashStartDelay = 0;
    m_nSensorForceInvokeByInterval = 0;
    m_nTargetHasBuffID = 0;
    m_nTargetHasBuffOverlapCount = 0;
    m_nTargetHasNotBuffID = 0;
    m_nTargetHasBuffOwner = 0;
}

// @0x140801270
bool Unk_SkillSensor::FUN_140801270(const Unk_SkillSensor& o)
{
    if (Unk_RangeShape(*this).FUN_1408002b0(Unk_RangeShape(o))) return true;
    if (m_nSensorStartDelay != o.m_nSensorStartDelay) return true;
    if (m_nSensorSplashStartDelay != o.m_nSensorSplashStartDelay) return true;
    if (m_nSensorForceInvokeByInterval != o.m_nSensorForceInvokeByInterval) return true;
    if (m_nTargetHasBuffID != o.m_nTargetHasBuffID) return true;
    if (m_nTargetHasBuffOverlapCount != o.m_nTargetHasBuffOverlapCount) return true;
    if (m_nTargetHasNotBuffID != o.m_nTargetHasNotBuffID) return true;
    if (m_nTargetHasBuffOwner != o.m_nTargetHasBuffOwner) return true;
    return false;
}

// @0x1408013f0
void Unk_SkillSensor::LoadElement(Unk_140165cf0* pElem, CString strName)
{
    Unk_140165cf0* pSensor = pElem->FUN_140165cf0(strName);
    if (pSensor == 0)
        return;
    Load(pSensor);
    FUN_1408732a0(pSensor, "sensorStartDelay", m_nSensorStartDelay);
    FUN_1408732a0(pSensor, "sensorSplashStartDelay", m_nSensorSplashStartDelay);
    FUN_1408731e0(pSensor, "sensorForceInvokeByInterval", m_nSensorForceInvokeByInterval);
    FUN_140873220(pSensor, "targetHasBuffID", m_nTargetHasBuffID);
    FUN_140873220(pSensor, "targetHasBuffOverlapCount", m_nTargetHasBuffOverlapCount);
    FUN_140873220(pSensor, "targetHasNotBuffID", m_nTargetHasNotBuffID);
    FUN_1408731e0(pSensor, "targetHasBuffOwner", m_nTargetHasBuffOwner);
}

// @0x140801540
void Unk_SkillSensor::SaveElement(void* pParent, CString strName)
{
    static Unk_SkillSensor kDefault;
    Unk_TiXmlElement elem(strName);
    FUN_140800570(&elem);
    if (m_nSensorStartDelay != kDefault.m_nSensorStartDelay)
        FUN_140873dc0(&elem, "sensorStartDelay", m_nSensorStartDelay);
    if (m_nSensorSplashStartDelay != kDefault.m_nSensorSplashStartDelay)
        FUN_140873dc0(&elem, "sensorSplashStartDelay", m_nSensorSplashStartDelay);
    if (m_nSensorForceInvokeByInterval != kDefault.m_nSensorForceInvokeByInterval)
        FUN_140873ca0(&elem, "sensorForceInvokeByInterval", m_nSensorForceInvokeByInterval);
    if (m_nTargetHasBuffID != kDefault.m_nTargetHasBuffID)
        FUN_140873ce0(&elem, "targetHasBuffID", m_nTargetHasBuffID);
    if (m_nTargetHasBuffOverlapCount != kDefault.m_nTargetHasBuffOverlapCount)
        FUN_140873ce0(&elem, "targetHasBuffOverlapCount", m_nTargetHasBuffOverlapCount);
    if (m_nTargetHasNotBuffID != kDefault.m_nTargetHasNotBuffID)
        FUN_140873ce0(&elem, "targetHasNotBuffID", m_nTargetHasNotBuffID);
    if (m_nTargetHasBuffOwner != kDefault.m_nTargetHasBuffOwner)
        FUN_140873ca0(&elem, "targetHasBuffOwner", m_nTargetHasBuffOwner);
    if (elem.HasAttributes())
        FUN_14086e000(pParent, &elem);
}

// 0x80-byte record constructed at 0x140801790 (no caller in the unit; two float triples and a trailing CString).
struct Unk_140801790
{
    Unk_140801790();                                        // 0x140801790
    __int64 m_n00;
    int m_n08, m_n0c, m_n10;
    short m_s14;
    int m_n18;
    Unk_PDVec3 m_v1c, m_v28, m_v34;
    int m_n40, m_n44;
    bool m_b48;
    int m_n4c, m_n50;
    __int64 m_n58;
    bool m_b60;
    int m_n64;
    CString m_str68;
    bool m_b70;
    __int64 m_n78;
};
MS2_CHECK_SIZE(Unk_140801790, 0x80);

// @0x140801790
Unk_140801790::Unk_140801790()
    : m_n00(0), m_n08(0), m_n0c(0), m_n10(0), m_s14(1), m_n18(0), m_v1c(0, 0, 0), m_v28(0, 0, 0), m_v34(0, 0, 0),
      m_n40(0), m_n44(0), m_b48(false), m_n4c(0), m_n50(0), m_n58(0), m_b60(false), m_n64(0), m_b70(false),
      m_n78(0)
{
}

// @0x1408018d0
SkillActionSkill::SkillActionSkill()
{
    m_nOverlapCount = 1;
    m_nDelay = 0;
    m_nInterval = 0;
    m_nRemoveDelay = 0;
    m_nImmediateActive = 0;
    m_nFireCount = 1;
    m_nNonTargetActive = 0;
    m_nUseDirection = 0;
    m_nOnlySensingActive = 0;
    m_nActiveByIntervalTick = 0;
    m_nDependOnCasterState = 0;
    m_nIndependent = 0;
    m_nChain = 0;
    m_fChainDistance = 150.0f;
}

// @0x140801a10
bool SkillActionSkill::operator!=(const SkillActionSkill& o)
{
    if (!IsSameArray(m_arrLevel, o.m_arrLevel)) return true;
    if (!IsSameArray(m_arrSkillID, o.m_arrSkillID)) return true;
    if (!IsSameArray(m_arrLinkSkillID, o.m_arrLinkSkillID)) return true;
    if (m_nOverlapCount != o.m_nOverlapCount) return true;
    if (m_nDelay != o.m_nDelay) return true;
    if (m_nInterval != o.m_nInterval) return true;
    if (m_nRemoveDelay != o.m_nRemoveDelay) return true;
    if (m_nImmediateActive != o.m_nImmediateActive) return true;
    if (m_nFireCount != o.m_nFireCount) return true;
    if (m_nNonTargetActive != o.m_nNonTargetActive) return true;
    if (m_nUseDirection != o.m_nUseDirection) return true;
    if (m_nOnlySensingActive != o.m_nOnlySensingActive) return true;
    if (m_nActiveByIntervalTick != o.m_nActiveByIntervalTick) return true;
    if (m_nDependOnCasterState != o.m_nDependOnCasterState) return true;
    if (m_nIndependent != o.m_nIndependent) return true;
    if (m_nChain != o.m_nChain) return true;
    if (m_fChainDistance != o.m_fChainDistance) return true;
    return false;
}

// @0x140801c40
int SkillActionSkill::Load(Unk_140165cf0* pElem)
{
    XmlSplit(FUN_14015f710(pElem, "level", CString("")), m_arrLevel, ",");
    XmlSplit(FUN_14015f710(pElem, "skillID", CString("")), m_arrSkillID, ",");
    XmlSplit(FUN_14015f710(pElem, "linkSkillID", CString("")), m_arrLinkSkillID, ",");
    FUN_140873220(pElem, "overlapCount", m_nOverlapCount);
    FUN_1408732a0(pElem, "delay", m_nDelay);
    FUN_1408732a0(pElem, "removeDelay", m_nRemoveDelay);
    FUN_1408732a0(pElem, "interval", m_nInterval);
    FUN_1408731e0(pElem, "immediateActive", m_nImmediateActive);
    FUN_1408731e0(pElem, "fireCount", m_nFireCount);
    FUN_1408731e0(pElem, "nonTargetActive", m_nNonTargetActive);
    FUN_1408731e0(pElem, "useDirection", m_nUseDirection);
    FUN_1408731e0(pElem, "onlySensingActive", m_nOnlySensingActive);
    FUN_1408731e0(pElem, "dependOnCasterState", m_nDependOnCasterState);
    FUN_1408731e0(pElem, "activeByIntervalTick", m_nActiveByIntervalTick);
    FUN_1408731e0(pElem, "independent", m_nIndependent);
    m_nChain = FUN_140197350(pElem, "chain", m_nChain);
    m_fChainDistance = FUN_1401973d0(pElem, "chainDistance", m_fChainDistance);
    return 1;
}

// @0x140802050
int SkillActionSkill::Save(void* pParent, CString strName)
{
    return 1;
}

// @0x140802090
SkillActionAdditional::SkillActionAdditional()
    : m_nLinkSkillID(0), m_nOverlapCount(1), m_nSkillTarget(0), m_nSkillOwner(1), m_nDependOnDamageCount(0)
{
}

// @0x140802120
bool SkillActionAdditional::operator!=(const SkillActionAdditional& o)
{
    if (m_nAdditionalID != o.m_nAdditionalID) return true;
    if (m_nLevel != o.m_nLevel) return true;
    if (m_nLinkSkillID != o.m_nLinkSkillID) return true;
    if (m_nOverlapCount != o.m_nOverlapCount) return true;
    if (m_nSkillTarget != o.m_nSkillTarget) return true;
    if (m_nSkillOwner != o.m_nSkillOwner) return true;
    if (m_nDependOnDamageCount != o.m_nDependOnDamageCount) return true;
    if (m_beginCondition != o.m_beginCondition) return true;
    return false;
}

// @0x140802210
int SkillActionAdditional::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "additionalID", m_nAdditionalID);
    FUN_1408731a0(pElem, "level", m_nLevel);
    FUN_140873220(pElem, "linkSkillID", m_nLinkSkillID);
    FUN_140873220(pElem, "overlapCount", m_nOverlapCount);
    FUN_1408731e0(pElem, "skillTarget", m_nSkillTarget);
    FUN_1408731e0(pElem, "skillOwner", m_nSkillOwner);
    FUN_1408731e0(pElem, "dependOnDamageCount", m_nDependOnDamageCount);
    if (m_beginCondition.Load(pElem) == 0)
        return 0;
    return 1;
}

// @0x1408024f0
SkillGlideData::SkillGlideData()
    : m_nId(0), m_fGravity(0), m_fHeightLimit(0), m_fHorizontalAccelerate(0), m_fHorizontalVelocity(0),
      m_fVerticalAccelerate(0), m_fVerticalVelocity(0), m_fVerticalVibrateAmplitude(0),
      m_fVerticalVibrateFrequency(0), m_fGlideVerticalAccelerateLimit(0), m_fGlideHorizontalAccelerateLimit(0),
      m_bOnGroundDisable(false), m_nNameTagOffset(0)
{
}

// @0x140802640
bool SkillGlideData::FUN_140802640(const SkillGlideData& o)
{
    if (m_fGravity != o.m_fGravity) return 1;
    if (m_fHeightLimit != o.m_fHeightLimit) return 1;
    if (m_fHorizontalAccelerate != o.m_fHorizontalAccelerate) return 1;
    if (m_fHorizontalVelocity != o.m_fHorizontalVelocity) return 1;
    if (m_fVerticalAccelerate != o.m_fVerticalAccelerate) return 1;
    if (m_fVerticalVelocity != o.m_fVerticalVelocity) return 1;
    if (m_fVerticalVibrateAmplitude != o.m_fVerticalVibrateAmplitude) return 1;
    if (m_fVerticalVibrateFrequency != o.m_fVerticalVibrateFrequency) return 1;
    if (m_fGlideVerticalAccelerateLimit != o.m_fGlideVerticalAccelerateLimit) return 1;
    if (m_fGlideHorizontalAccelerateLimit != o.m_fGlideHorizontalAccelerateLimit) return 1;
    if (FUN_1401647e0(m_strEffectRun, o.m_strEffectRun)) return 1;
    if (FUN_1401647e0(m_strEffectIdle, o.m_strEffectIdle)) return 1;
    if (FUN_1401647e0(m_strAniIdle, o.m_strAniIdle)) return 1;
    if (FUN_1401647e0(m_strAniRun, o.m_strAniRun)) return 1;
    if (m_bOnGroundDisable != o.m_bOnGroundDisable)
        return 1;
    return 0;
}

// @0x140802830
void SkillGlideData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_nId);
    FUN_140873360(pElem, "gravity", m_fGravity);
    FUN_140873360(pElem, "heightLimit", m_fHeightLimit);
    FUN_140873360(pElem, "horizontalAccelerate", m_fHorizontalAccelerate);
    FUN_140873360(pElem, "horizontalVelocity", m_fHorizontalVelocity);
    FUN_140873360(pElem, "verticalAccelerate", m_fVerticalAccelerate);
    FUN_140873360(pElem, "verticalVelocity", m_fVerticalVelocity);
    FUN_140873360(pElem, "verticalVibrateAmplitude", m_fVerticalVibrateAmplitude);
    FUN_140873360(pElem, "verticalVibrateFrequency", m_fVerticalVibrateFrequency);
    FUN_140873360(pElem, "glideVerticalAccelerateLimit", m_fGlideVerticalAccelerateLimit);
    FUN_140873360(pElem, "glideHorizontalAccelerateLimit", m_fGlideHorizontalAccelerateLimit);
    FUN_1408733e0(pElem, "effectRun", m_strEffectRun);
    FUN_1408733e0(pElem, "effectIdle", m_strEffectIdle);
    FUN_1408733e0(pElem, "aniIdle", m_strAniIdle);
    FUN_1408733e0(pElem, "aniRun", m_strAniRun);
    FUN_1408730a0(pElem, "onGroundDisable", m_bOnGroundDisable);
    FUN_1408731e0(pElem, "nameTagOffset", m_nNameTagOffset);
}

// @0x140802a40
int SkillGlideData::FUN_140802a40(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pGlide = pElem->FUN_140165cf0("glideProperty");
    if (pGlide != 0)
        Load(pGlide);
    return 1;
}

// @0x140802a90
int SkillGlideData::FUN_140802a90(void* pParent)
{
    return 1;
}

// @0x140802ab0
int SkillGlideData::FUN_140802ab0()
{
    return m_nId;
}

// @0x140802ad0
CStringW* SkillGlideData::FUN_140802ad0()
{
    return &m_str78;
}

// @0x140802cd0
Unk_SkillBlock170::Unk_SkillBlock170()
{
    m_fUp = 0;
    m_fBack = 0;
}

// @0x140802d00
bool Unk_SkillBlock170::FUN_140802d00(const Unk_SkillBlock170& o)
{
    if (m_fUp != o.m_fUp) return true;
    if (m_fBack != o.m_fBack) return true;
    return false;
}

// @0x140802d50
int Unk_SkillBlock170::FUN_140802d50(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pPush = pElem->FUN_140165cf0("push");
    if (pPush != 0)
    {
        FUN_140873360(pPush, "up", m_fUp);
        FUN_140873360(pPush, "back", m_fBack);
    }
    return 1;
}

// @0x140802dd0
int Unk_SkillBlock170::FUN_140802dd0(void* pParent)
{
    return 1;
}

// @0x140802df0
Unk_SkillBlockA4::Unk_SkillBlockA4()
{
    m_nInputSkill = 0;
    m_nOutputSkill = 0;
    m_bComboSkill = false;
    m_bChargingSkill = false;
    m_bDisableChargingAttackSkipFrame = false;
    m_b0b = false;
}

// @0x140802e40
bool Unk_SkillBlockA4::FUN_140802e40(const Unk_SkillBlockA4& o)
{
    if (m_nInputSkill != o.m_nInputSkill) return true;
    if (m_nOutputSkill != o.m_nOutputSkill) return true;
    if (m_bComboSkill != o.m_bComboSkill) return true;
    if (m_bChargingSkill != o.m_bChargingSkill) return true;
    if (m_bDisableChargingAttackSkipFrame != o.m_bDisableChargingAttackSkipFrame) return true;
    if (m_b0b != o.m_b0b) return true;
    return false;
}

// @0x140802ef0
int Unk_SkillBlockA4::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pCombo = pElem->FUN_140165cf0("combo");
    if (pCombo != 0)
    {
        FUN_140873220(pCombo, "inputSkill", m_nInputSkill);
        FUN_140873220(pCombo, "outputSkill", m_nOutputSkill);
        FUN_1408730a0(pCombo, "comboSkill", m_bComboSkill);
        FUN_1408730a0(pCombo, "chargingSkill", m_bChargingSkill);
        FUN_1408730a0(pCombo, "disableChargingAttackSkipFrame", m_bDisableChargingAttackSkipFrame);
    }
    return 1;
}

// @0x140802fc0
int Unk_SkillBlockA4::FUN_140802fc0(int nSkill)
{
    if (nSkill == m_nInputSkill)
        return m_nOutputSkill;
    return nSkill;
}

// @0x140802ff0
int Unk_SkillBlockA4::FUN_140802ff0(int nSkill)
{
    if (m_nInputSkill == 0)
        return 0;
    return m_nOutputSkill == nSkill;
}

// @0x140803040
int Unk_SkillBlockA4::FUN_140803040()
{
    if (m_nInputSkill == 0)
        return 0;
    return m_nOutputSkill;
}

// @0x140803070
Unk_SkillBlock160::Unk_SkillBlock160()
{
    m_fMaxDegree = 210.0f;
    m_fMaxDistance = 0;
    m_fMaxHeight = 0;
    m_nUseMove = 0;
}

// @0x1408030c0
bool Unk_SkillBlock160::FUN_1408030c0(const Unk_SkillBlock160& o)
{
    if (m_fMaxDegree != o.m_fMaxDegree) return true;
    if (m_fMaxDistance != o.m_fMaxDistance) return true;
    if (m_fMaxHeight != o.m_fMaxHeight) return true;
    if (m_nUseMove != o.m_nUseMove) return true;
    return false;
}

// @0x140803140
int Unk_SkillBlock160::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pTargeting = pElem->FUN_140165cf0("autoTargeting");
    if (pTargeting != 0)
    {
        FUN_140873360(pTargeting, "autoTargetingMaxDegree", m_fMaxDegree);
        FUN_140873360(pTargeting, "autoTargetingMaxDistance", m_fMaxDistance);
        FUN_140873360(pTargeting, "autoTargetingMaxHeight", m_fMaxHeight);
        FUN_1408731e0(pTargeting, "autoTargetUseMove", m_nUseMove);
    }
    return 1;
}

// @0x1408031f0
int Unk_SkillBlock160::FUN_1408031f0(void* pParent)
{
    return 1;
}

// @0x140803210
__int64 Unk_SkillBlock160::FUN_140803210()
{
    __int64 nKey = 0;
    nKey += m_nUseMove;
    nKey += (unsigned __int64)m_fMaxHeight << 1;
    nKey += (unsigned __int64)m_fMaxDistance << 11;
    nKey += (unsigned __int64)m_fMaxDegree << 22;
    return nKey;
}

// @0x140803330
Unk_SkillBlockB0::Unk_SkillBlockB0()
{
    m_eAutoChange = SkillAutoChange_None;
}

// @0x1408033b0
bool Unk_SkillBlockB0::FUN_1408033b0(const Unk_SkillBlockB0& o)
{
    if (!IsSameArray(m_arrCheckEffectID, o.m_arrCheckEffectID)) return 1;
    if (!IsSameArray(m_arrCheckEffectLevel, o.m_arrCheckEffectLevel)) return 1;
    if (!IsSameArray(m_arrCheckEffectOverlapCount, o.m_arrCheckEffectOverlapCount)) return 1;
    if (!IsSameVector(m_vCheckEffectCompareFunc, o.m_vCheckEffectCompareFunc)) return 1;
    if (!IsSameArray(m_arrChangeSkillID, o.m_arrChangeSkillID)) return 1;
    if (m_eAutoChange != o.m_eAutoChange) return 1;
    return 0;
}

// @0x1408034a0
int Unk_SkillBlockB0::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pChange = pElem->FUN_140165cf0("changeSkill");
    if (pChange != 0)
    {
        XmlTokenList(pChange, "changeSkillCheckEffectID", m_arrCheckEffectID);
        XmlTokenList(pChange, "changeSkillCheckEffectLevel", m_arrCheckEffectLevel);
        XmlTokenList(pChange, "changeSkillCheckEffectOverlapCount", m_arrCheckEffectOverlapCount);
        XmlTokenList(pChange, "changeSkillID", m_arrChangeSkillID);
        XmlValue(pChange, "autoChange", m_eAutoChange);
        std::vector<int> vCompare;
        XmlTokenList(pChange, "changeSkillCheckEffectCompareFunc", vCompare);
        for (int nFunc : vCompare)
            m_vCheckEffectCompareFunc.push_back((SkillCompareSign)nFunc);
    }
    while (m_vCheckEffectCompareFunc.size() < m_arrCheckEffectID.GetCount())
        m_vCheckEffectCompareFunc.push_back(SkillCompareSign_Equals);
    int nResult = 0;
    if (m_arrCheckEffectID.GetCount() == m_arrCheckEffectLevel.GetCount() &&
        m_arrCheckEffectID.GetCount() == m_arrCheckEffectOverlapCount.GetCount() &&
        m_arrCheckEffectID.GetCount() == m_vCheckEffectCompareFunc.size())
        nResult = 1;
    if (nResult == 0)
    {
        m_arrCheckEffectID.RemoveAll();
        m_arrCheckEffectLevel.RemoveAll();
        m_arrCheckEffectOverlapCount.RemoveAll();
        m_vCheckEffectCompareFunc.clear();
        m_arrChangeSkillID.RemoveAll();
    }
    return nResult;
}

// @0x140803790
Unk_SkillBlock150::Unk_SkillBlock150()
{
    m_eEnable = SkillMagicControl_None;
    m_fMoveSpeed = 0;
    m_fDuration = 0;
    m_fMaxDistance = 0;
}

// @0x1408037e0
bool Unk_SkillBlock150::FUN_1408037e0(const Unk_SkillBlock150& o)
{
    if (m_eEnable != o.m_eEnable) return true;
    if (m_fMoveSpeed != o.m_fMoveSpeed) return true;
    if (m_fDuration != o.m_fDuration) return true;
    if (m_fMaxDistance != o.m_fMaxDistance) return true;
    return false;
}

// @0x140803860
int Unk_SkillBlock150::Load(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pMagic = pElem->FUN_140165cf0("magicControl");
    if (pMagic != 0)
    {
        XmlValue(pMagic, "enable", m_eEnable);
        FUN_140873360(pMagic, "moveSpeed", m_fMoveSpeed);
        m_fMoveSpeed = FUN_14028d3a0(m_fMoveSpeed);
        FUN_140873360(pMagic, "duration", m_fDuration);
        FUN_140873360(pMagic, "maxDistance", m_fMaxDistance);
    }
    return 1;
}

// @0x140803930
int Unk_SkillBlock150::Save(void* pParent)
{
    if (m_eEnable == 0)
        return 1;
    Unk_TiXmlElement elem("magicControl");
    FUN_140873ca0(&elem, "enable", m_eEnable);
    FUN_140873e30(&elem, "moveSpeed", m_fMoveSpeed);
    FUN_140873e30(&elem, "duration", m_fDuration);
    if (m_fMaxDistance != 0.0f)
        FUN_140873e30(&elem, "maxDistance", m_fMaxDistance);
    FUN_14086e000(pParent, &elem);
    return 1;
}

// @0x140803a30
SkillLevelData::SkillLevelData(SkillData* pSkill)
    : m_nSp(0), m_nEp(0), m_nMeso(0), m_nCooldown(0), m_fHpRate(0), m_nStanceDamageRate(0), m_pSkill(pSkill),
      m_nLevel(0)
{
}

// @0x140803b30
bool SkillLevelData::FUN_140803b30(const SkillLevelData& o)
{
    if (m_nLevel != o.m_nLevel) return 1;
    if (m_nMeso != o.m_nMeso) return 1;
    if (m_nSp != o.m_nSp) return 1;
    if (m_nEp != o.m_nEp) return 1;
    if (m_fHpRate != o.m_fHpRate) return 1;
    if (m_nStanceDamageRate != o.m_nStanceDamageRate) return 1;
    if (m_vMotion.size() != o.m_vMotion.size()) return 1;
    for (unsigned __int64 i = 0; i < m_vMotion.size(); i++)
    {
        if (m_vMotion[i]->FUN_140807620(*o.m_vMotion[i])) return 1;
    }
    if (m_vAdditional.size() != o.m_vAdditional.size()) return 1;
    for (unsigned __int64 i = 0; i < m_vAdditional.size(); i++)
    {
        if (*m_vAdditional[i] != *o.m_vAdditional[i]) return 1;
    }
    if (m_detect.FUN_1408002b0(o.m_detect)) return 1;
    return 0;
}

// @0x140803dc0
unsigned SkillLevelData::FUN_140803dc0()
{
    return m_pSkill->GetId();
}

// @0x140803df0
unsigned short SkillLevelData::GetLevel()
{
    return m_nLevel;
}

// @0x140803e10
SkillData* SkillLevelData::GetSkill()
{
    return m_pSkill;
}

// @0x140803e30
SkillMotionData* SkillLevelData::FUN_140803e30(CString strSequence)
{
    for (std::vector<MS2Ptr<SkillMotionData> >::iterator it = m_vMotion.begin(); it != m_vMotion.end(); ++it)
    {
        SkillMotionData* pMotion = *it;
        if (FUN_1401c0090(pMotion->m_strSequenceName, strSequence))
            return pMotion;
    }
    return 0;
}

// @0x140803f00
SkillMotionData* SkillLevelData::FUN_140803f00(int nMotion)
{
    if (nMotion >= (int)m_vMotion.size())
        return 0;
    return m_vMotion[nMotion];
}

// @0x140803f60
SkillAttackData* SkillLevelData::FUN_140803f60(int nMotion, int nAttack)
{
    SkillMotionData* pMotion = FUN_140803f00(nMotion);
    if (pMotion == 0)
        return 0;
    return pMotion->FUN_140807e20(nAttack);
}

// @0x140803fb0
SkillAttackData* SkillLevelData::FUN_140803fb0(int nMotion, CString strName)
{
    SkillMotionData* pMotion = FUN_140803f00(nMotion);
    if (pMotion == 0)
        return 0;
    return pMotion->FUN_140807e80(strName);
}

// @0x140804030
SkillAttackData* SkillLevelData::FUN_140804030(const CString& strPoint) const
{
    for (const MS2Ptr<SkillMotionData>& pMotion : m_vMotion)
    {
        SkillAttackData* pAttack = pMotion->FUN_140807f20(strPoint);
        if (pAttack != 0)
            return pAttack;
    }
    return 0;
}

// @0x1408040d0
Unk_RangeProperty* SkillLevelData::FUN_1408040d0(int nMotion, int nAttack)
{
    SkillAttackData* pAttack = FUN_140803f60(nMotion, nAttack);
    if (pAttack != 0)
        return &pAttack->m_range;
    return 0;
}

// @0x140804120
Unk_RangeShape* SkillLevelData::FUN_140804120()
{
    if (m_detect.m_nType == 0)
        return 0;
    return &m_detect;
}

// @0x140804150
float SkillLevelData::FUN_140804150(int nMotion, int nAttack)
{
    SkillMotionData* pMotion = FUN_140803f00(nMotion);
    if (pMotion == 0)
        return 0;
    SkillAttackData* pAttack = pMotion->FUN_140807e20(nAttack);
    if (pAttack == 0)
        return 0;
    return pAttack->m_damage.m_fRate;
}

// @0x1408041d0
__int64 SkillLevelData::FUN_1408041d0(int nMotion, int nAttack)
{
    SkillMotionData* pMotion = FUN_140803f00(nMotion);
    if (pMotion == 0)
        return 0;
    SkillAttackData* pAttack = pMotion->FUN_140807e20(nAttack);
    if (pAttack == 0)
        return 0;
    return pAttack->m_damage.m_nValue;
}

// @0x140804250
int SkillLevelData::GetStanceDamageRate()
{
    return m_nStanceDamageRate;
}

// @0x140804270
int SkillLevelData::FUN_140804270()
{
    return (int)m_vMotion.size();
}

// @0x1408042a0
float SkillLevelData::FUN_1408042a0(int nMotion, int nAttack)
{
    Unk_RangeProperty* pRange = FUN_1408040d0(nMotion, nAttack);
    if (pRange == 0)
        return 0;
    if (pRange->m_nType == 4)
        return pRange->m_f1c;
    return pRange->m_f10;
}

// @0x140804310
float SkillLevelData::FUN_140804310()
{
    float fMax = 0;
    for (int nMotion = 0; nMotion < FUN_140804270(); nMotion++)
    {
        int nAttack = 0;
        while (true)
        {
            Unk_RangeProperty* pRange = FUN_1408040d0(nMotion, nAttack++);
            if (pRange == 0)
                break;
            if (pRange->m_nType == 4)
            {
                fMax = (std::max)(fMax, pRange->m_f1c);
                fMax = (std::max)(fMax, pRange->m_f10);
            }
        }
    }
    return fMax;
}

// @0x1408043f0
int SkillLevelData::FUN_1408043f0(int nMotion, int nAttack)
{
    SkillAttackData* pAttack = FUN_140803f60(nMotion, nAttack);
    if (pAttack != 0 && pAttack->GetAttackMethodType() == 1)
        return 1;
    return 0;
}

// @0x140804450
bool SkillLevelData::FUN_140804450()
{
    if (m_vMotion.empty())
        return false;
    for (SkillMotionData* pMotion : m_vMotion)
    {
        if (!pMotion->m_strSequenceName.IsEmpty())
            return true;
    }
    return false;
}

// @0x140804500
const CString& SkillLevelData::FUN_140804500(int nKind, int nMotion)
{
    static CString s_strEmpty;
    SkillMotionData* pMotion = FUN_140803f00(nMotion);
    if (pMotion == 0)
        return s_strEmpty;
    if (nKind == 2)
        return pMotion->m_strMotionEffect;
    if (nKind == 3)
        return pMotion->m_strLoopEffect;
    if (nKind == 4)
        return pMotion->m_strEndEffect;
    return s_strEmpty;
}

// @0x1408045f0
int SkillLevelData::FUN_1408045f0(int nMotion, int nAttack)
{
    SkillMotionData* pMotion = FUN_140803f00(nMotion);
    if (pMotion == 0)
        return 0;
    SkillAttackData* pAttack = pMotion->FUN_140807e20(nAttack);
    if (pAttack == 0)
        return 0;
    return pAttack->m_nMagicPathID;
}

// @0x140804660
float SkillLevelData::FUN_140804660()
{
    return FUN_14028d280(m_nCooldown);
}

// @0x140804690
int SkillLevelData::Load(Unk_140165cf0* pElem)
{
    FUN_1408731a0(pElem, "value", m_nLevel);
    FUN_1408731e0(pElem, "sp", m_nSp);
    FUN_1408731e0(pElem, "ep", m_nEp);
    FUN_1408731e0(pElem, "meso", m_nMeso);
    FUN_140873360(pElem, "hpRate", m_fHpRate);
    FUN_1408732a0(pElem, "cooldown", m_nCooldown);
    FUN_140873420(pElem, "stringParam", m_strStringParam);
    float fStanceDamageRate = 0;
    FUN_140873360(pElem, "stanceDamageRate", fStanceDamageRate);
    m_nStanceDamageRate = (int)(fStanceDamageRate * 1000.0f);
    if (m_nLevel == 0)
    {
        unsigned nSkillId = FUN_140803dc0();
        FUN_140177a80(FUN_140166440(), 1, 0x13, L"스킬 레벨이 잘못되었습니다.[Skill Level Data - [{0}]]", &nSkillId);
        return 0;
    }
    Unk_140165cf0* pDetect = pElem->FUN_140165cf0("detectProperty");
    if (pDetect != 0)
        m_detect.Load(pDetect);
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("actionAdditional"))
    {
        MS2Ptr<SkillActionAdditional> spAction(new SkillActionAdditional);
        if (!spAction->Load(pChild))
            return 0;
        m_vAdditional.push_back(spAction);
    }
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("motion"); pChild != 0; pChild = pChild->FUN_140168650("motion"))
    {
        MS2Ptr<SkillMotionData> spMotion(new SkillMotionData);
        if (!spMotion->FUN_1408080d0(pChild))
            return 0;
        m_vMotion.push_back(spMotion);
    }
    return 1;
}

// @0x140804ae0
int SkillLevelData::FUN_140804ae0(void* pParent)
{
    Unk_TiXmlElement elem("level");
    FUN_140873c60(&elem, "value", m_nLevel);
    if (!m_strStringParam.IsEmpty())
        FUN_1408740a0(&elem, "value", m_strStringParam);
    {
        Unk_TiXmlElement detect("detectProperty");
        m_detect.FUN_140800570(&detect);
        if (detect.HasAttributes())
            FUN_14086e000(&elem, &detect);
    }
    for (std::vector<MS2Ptr<SkillMotionData> >::iterator it = m_vMotion.begin(); it != m_vMotion.end(); ++it)
    {
        if (!(*it)->FUN_140808240(&elem))
            return 0;
    }
    FUN_14086e000(pParent, &elem);
    return 1;
}

// @0x140804c90
__int64 SkillLevelData::FUN_140804c90(unsigned __int64 nMotion)
{
    if (m_pSkill == 0)
        return 0;
    if (nMotion >= m_vMotion.size())
        return 0;
    Unk_HashKey key;
    key.m_nHash = m_pSkill->FUN_1407ea030();
    SkillMotionData* pMotion = m_vMotion[nMotion];
    if (pMotion != 0)
    {
        __int64 nMotionKey = pMotion->FUN_140808040();
        key.Combine(nMotionKey);
    }
    return key.m_nHash;
}

// @0x140807280
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x1408073a0
SkillMotionData::SkillMotionData()
    : m_fSequenceSpeed(1.0f), m_mapTagEffects(10), m_bA0(false), m_fAC(0), m_eMoveType((SkillMoveType)0), m_fMoveAngle(0), m_fB8(0)
{
    m_nIgnoreCollisionGroups = 0;
    m_nHoldWeapon = 1;
    m_eMoveEaseType = (SkillPushEaseType)0;
    m_nLoopCount = 0;
    m_fPushCylinderVelH = 0;
    m_fPushCylinderVelV = 0;
    m_fPushCylinderOuter = 0;
    m_fPushCylinderInner = 0;
    m_fPushCylinderHeight = 0;
    m_bDoesPlayIdleOnSkillEnd = true;
    m_nFaceTarget = 1;
    m_nStartNoneBlendDelay = 0;
    m_bSplashCastEffectStartDelay = false;
    m_nSplashLifeTick = 0;
    m_nSplashInvokeCoolTick = 0;
    m_fAniSkipTime = 0;
}

// @0x140807620
bool SkillMotionData::FUN_140807620(const SkillMotionData& o)
{
    if (FUN_1401647e0(m_strSequenceName, o.m_strSequenceName)) return 1;
    if (m_fSequenceSpeed != o.m_fSequenceSpeed) return 1;
    if (FUN_1401647e0(m_strMotionEffect, o.m_strMotionEffect)) return 1;
    if (FUN_1401647e0(m_strSplashInvokeEffect, o.m_strSplashInvokeEffect)) return 1;
    if (FUN_1401647e0(m_strLoopEffect, o.m_strLoopEffect)) return 1;
    if (FUN_1401647e0(m_strEndEffect, o.m_strEndEffect)) return 1;
    if (FUN_1401647e0(m_strSplashEndEffect, o.m_strSplashEndEffect)) return 1;
    if (FUN_1401647e0(m_strWeaponSequenceName, o.m_strWeaponSequenceName)) return 1;
    if (m_mapTagEffects.GetCount() != o.m_mapTagEffects.GetCount()) return 1;
    POSITION pos = m_mapTagEffects.GetHeadPosition();
    while (pos != 0)
    {
        CString strKey = m_mapTagEffects.GetKeyAt(pos);
        CString strValue = m_mapTagEffects.GetValueAt(pos);
        CString strOther;
        if (!o.m_mapTagEffects.Lookup(strKey, strOther)) return 1;
        if (FUN_1401647e0(strValue, strOther)) return 1;
        m_mapTagEffects.GetNext(pos);
    }
    if (FUN_1401647e0(m_strLoopKeepEffect, o.m_strLoopKeepEffect)) return 1;
    if (FUN_1401647e0(m_strLoopEndEffect, o.m_strLoopEndEffect)) return 1;
    if (FUN_1401647e0(m_strSplashDurationCastEffect, o.m_strSplashDurationCastEffect)) return 1;
    if (m_bA0 != o.m_bA0) return 1;
    if (m_bSplashCastEffectStartDelay != o.m_bSplashCastEffectStartDelay) return 1;
    if (m_nSplashLifeTick != o.m_nSplashLifeTick) return 1;
    if (m_nSplashInvokeCoolTick != o.m_nSplashInvokeCoolTick) return 1;
    if (m_fAC != o.m_fAC) return 1;
    if (m_eMoveType != o.m_eMoveType) return 1;
    if (m_fMoveAngle != o.m_fMoveAngle) return 1;
    if (m_fB8 != o.m_fB8) return 1;
    if (m_eMoveEaseType != o.m_eMoveEaseType) return 1;
    if (m_nIgnoreCollisionGroups != o.m_nIgnoreCollisionGroups) return 1;
    if (m_nHoldWeapon != o.m_nHoldWeapon) return 1;
    if (m_nLoopCount != o.m_nLoopCount) return 1;
    if (m_fPushCylinderVelH != o.m_fPushCylinderVelH) return 1;
    if (m_fPushCylinderVelV != o.m_fPushCylinderVelV) return 1;
    if (m_fPushCylinderOuter != o.m_fPushCylinderOuter) return 1;
    if (m_fPushCylinderInner != o.m_fPushCylinderInner) return 1;
    if (m_fPushCylinderHeight != o.m_fPushCylinderHeight) return 1;
    if (FUN_1401647e0(m_strSelfInputCombo, o.m_strSelfInputCombo)) return 1;
    if (m_bDoesPlayIdleOnSkillEnd != o.m_bDoesPlayIdleOnSkillEnd) return 1;
    if (m_nFaceTarget != o.m_nFaceTarget) return 1;
    if (m_nStartNoneBlendDelay != o.m_nStartNoneBlendDelay) return 1;
    if (m_fAniSkipTime != o.m_fAniSkipTime) return 1;
    if (m_vAttack.size() != o.m_vAttack.size()) return 1;
    for (unsigned __int64 i = 0; i < m_vAttack.size(); i++)
    {
        if (m_vAttack[i]->operator!=(*o.m_vAttack[i])) return 1;
    }
    return 0;
}

// @0x140807e20
SkillAttackData* SkillMotionData::FUN_140807e20(int nAttack)
{
    if (nAttack >= (int)m_vAttack.size())
        return 0;
    return m_vAttack[nAttack];
}

// @0x140807e80
SkillAttackData* SkillMotionData::FUN_140807e80(const CString& strPoint)
{
    for (MS2Ptr<SkillAttackData>& spAttack : m_vAttack)
    {
        SkillAttackData* pAttack = spAttack;
        if (FUN_1401c0090(pAttack->m_strPoint, strPoint))
            return pAttack;
    }
    return 0;
}

// @0x140807f20
SkillAttackData* SkillMotionData::FUN_140807f20(const CString& strPoint)
{
    for (MS2Ptr<SkillAttackData>& spAttack : m_vAttack)
    {
        SkillAttackData* pAttack = spAttack;
        if (pAttack->HasPause() && FUN_1401c0090(pAttack->m_strPoint, strPoint))
            return pAttack;
    }
    return 0;
}

// @0x140807fd0
int SkillMotionData::FUN_140807fd0()
{
    return (int)m_vAttack.size();
}

// @0x140808000
bool SkillMotionData::FUN_140808000()
{
    return m_eMoveType == 3;
}

// @0x140808040
__int64 SkillMotionData::FUN_140808040()
{
    __int64 nKey = (unsigned __int64)((float)(unsigned __int64)((__int64)m_eMoveType << 10) + m_fSequenceSpeed * 100.0f);
    return nKey;
}

// @0x1408080d0
int SkillMotionData::FUN_1408080d0(Unk_140165cf0* pElem)
{
    Load(pElem);
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("attack"))
    {
        MS2Ptr<SkillAttackData> spAttack(new SkillAttackData);
        if (!spAttack->Load(pChild))
            return 0;
        m_vAttack.push_back(spAttack);
    }
    return 1;
}

// @0x140808240
int SkillMotionData::FUN_140808240(void* pParent)
{
    Unk_TiXmlElement elem("motion");
    for (std::vector<MS2Ptr<SkillAttackData> >::iterator it = m_vAttack.begin(); it != m_vAttack.end(); ++it)
    {
        if (!(*it)->Save(&elem))
            return 0;
    }
    if (elem.HasAttributes() || elem.HasChildren())
        FUN_14086e000(pParent, &elem);
    return 1;
}

// @0x140808350
void SkillMotionData::Load(Unk_140165cf0* pElem)
{
    FUN_1408733e0(pElem, "sequenceName", m_strSequenceName);
    FUN_140873360(pElem, "sequenceSpeed", m_fSequenceSpeed);
    if (FUN_1406aeee0()->FUN_1406af020())
    {
        FUN_1408733e0(pElem, "selfInputCombo", m_strSelfInputCombo);
        FUN_1408733e0(pElem, "motionEffect", m_strMotionEffect);
        FUN_1408733e0(pElem, "loopEffect", m_strLoopEffect);
        FUN_1408733e0(pElem, "endEffect", m_strEndEffect);
        FUN_1408733e0(pElem, "splashInvokeEffect", m_strSplashInvokeEffect);
        FUN_1408733e0(pElem, "splashEndEffect", m_strSplashEndEffect);
        FUN_1408733e0(pElem, "loopKeepEffect", m_strLoopKeepEffect);
        FUN_1408733e0(pElem, "loopEndEffect", m_strLoopEndEffect);
        FUN_1408733e0(pElem, "splashDurationCastEffect", m_strSplashDurationCastEffect);
        FUN_1408736d0(pElem, "IgnoreOptimalHideCastEffect", m_bA0);
        FUN_1408736d0(pElem, "splashCastEffectStartDelay", m_bSplashCastEffectStartDelay);
    }
    FUN_1408732a0(pElem, "splashLifeTick", m_nSplashLifeTick);
    FUN_1408732a0(pElem, "splashInvokeCoolTick", m_nSplashInvokeCoolTick);
    FUN_1408733e0(pElem, "weaponSequenceName", m_strWeaponSequenceName);
    ATL::CAtlArray<CString> arrTags;
    XmlTokenList(pElem, "strTagEffects", arrTags);
    for (unsigned i = 0; i < arrTags.GetCount(); i++)
    {
        ATL::CAtlArray<CString> arrPair;
        FUN_14015f0b0(arrTags[i], arrPair, "=");
        if (arrPair.GetCount() == 2)
            m_mapTagEffects.SetAt(arrPair[0], arrPair[1]);
    }
    FUN_140873360(pElem, "keyMove", m_fAC);
    XmlValue(pElem, "movetype", m_eMoveType);
    FUN_140873360(pElem, "moveangle", m_fMoveAngle);
    FUN_140873360(pElem, "movedistance", m_fB8);
    XmlValue(pElem, "moveEaseType", m_eMoveEaseType);
    FUN_140873220(pElem, "ignoreCollisionGroups", m_nIgnoreCollisionGroups);
    FUN_1408731e0(pElem, "holdWeapon", m_nHoldWeapon);
    FUN_1408731e0(pElem, "loopCount", m_nLoopCount);
    FUN_140873360(pElem, "pushCylinderVelH", m_fPushCylinderVelH);
    FUN_140873360(pElem, "pushCylinderVelV", m_fPushCylinderVelV);
    FUN_140873360(pElem, "pushCylinderOuter", m_fPushCylinderOuter);
    FUN_140873360(pElem, "pushCylinderInner", m_fPushCylinderInner);
    FUN_140873360(pElem, "pushCylinderHeight", m_fPushCylinderHeight);
    FUN_1408731e0(pElem, "faceTarget", m_nFaceTarget);
    FUN_1408736d0(pElem, "doesPlayIdleOnSkillEnd", m_bDoesPlayIdleOnSkillEnd);
    FUN_1408731e0(pElem, "startNoneBlendDelay", m_nStartNoneBlendDelay);
    FUN_140873360(pElem, "aniSkipTime", m_fAniSkipTime);
}

