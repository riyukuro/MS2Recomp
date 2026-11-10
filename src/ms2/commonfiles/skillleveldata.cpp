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
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
CString Unk_ReadString(class Unk_XmlNode*, char const*, CString);   // C3: was FUN_14015f710
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned short&);   // C3: was FUN_1408731a0
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220
int XmlGetAttr(class TiXmlElement*, char const*, unsigned long&);   // C3: was FUN_1408732a0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420

// Header statics (header_statics_a.h) followed by the motion prototype.
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static MS2Ptr<SkillMotionData> s_spMotion(new SkillMotionData);

// Unrecovered helpers.
void XmlSetAttr(class TiXmlElement*, char const*, unsigned long);   // C3: was FUN_140873dc0
void XmlSetAttr(class TiXmlElement*, char const*, float);   // C3: was FUN_140873e30
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
void XmlSetAttr(class TiXmlElement*, char const*, unsigned int);   // C3: was FUN_140873ce0
void XmlSetAttr(class TiXmlElement*, char const*, unsigned short);   // C3: was FUN_140873c60
void XmlSetAttr(class TiXmlElement*, char const*, CStringW const&);   // C3: was FUN_1408740a0
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view
int FUN_140197350(TiXmlElement* pElem, const char* pszName, int nDefault);        // int attribute with a default
float FUN_1401973d0(TiXmlElement* pElem, const char* pszName, float fDefault);    // float attribute with a default
float FUN_14028d280(unsigned uMilliseconds);
int XmlQuery(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408736d0
void Unk_SplitImplA(CString& str, ATL::CAtlArray<CString>* pOut, const char* pszSep);  // split into strings (achievedata.cpp; C3: was FUN_14015f0b0)
class Unk_LaunchOptions
{
public:
    bool FUN_1406af020();
};
Unk_LaunchOptions* GetLaunchOptions();
float FromPercent(float fValue);
const float& FUN_140805fc0(const float&, const float&);                    // std::max
class CLogString* GetLogString();
template <class T> void Unk_AdditionalLog(class CLogString*, int, int, const wchar_t*, const T&);
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
// C3 #12: was a local TiXml view





MS2_CHECK_SIZE(Unk_TiXmlAttribute, 0x40);

// C3 #12: was a local TiXml view







// C3 #12: was a local TiXml view
















MS2_CHECK_SIZE(TiXmlElement, 0x90);

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
bool Unk_SkillSensor::IsDifferent(const Unk_SkillSensor& o)
{
    if (Unk_RangeShape(*this).IsDifferent(Unk_RangeShape(o))) return true;
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
void Unk_SkillSensor::LoadElement(TiXmlElement* pElem, CString strName)
{
    TiXmlElement* pSensor = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild(strName));
    if (pSensor == 0)
        return;
    Load(pSensor);
    XmlGetAttr((class TiXmlElement*)(pSensor), "sensorStartDelay", reinterpret_cast<unsigned long&>(m_nSensorStartDelay));
    XmlGetAttr((class TiXmlElement*)(pSensor), "sensorSplashStartDelay", reinterpret_cast<unsigned long&>(m_nSensorSplashStartDelay));
    XmlGetAttr((class TiXmlElement*)(pSensor), "sensorForceInvokeByInterval", reinterpret_cast<int&>(m_nSensorForceInvokeByInterval));
    XmlGetAttr((class TiXmlElement*)(pSensor), "targetHasBuffID", reinterpret_cast<unsigned int&>(m_nTargetHasBuffID));
    XmlGetAttr((class TiXmlElement*)(pSensor), "targetHasBuffOverlapCount", reinterpret_cast<unsigned int&>(m_nTargetHasBuffOverlapCount));
    XmlGetAttr((class TiXmlElement*)(pSensor), "targetHasNotBuffID", reinterpret_cast<unsigned int&>(m_nTargetHasNotBuffID));
    XmlGetAttr((class TiXmlElement*)(pSensor), "targetHasBuffOwner", reinterpret_cast<int&>(m_nTargetHasBuffOwner));
}

// @0x140801540
void Unk_SkillSensor::SaveElement(void* pParent, CString strName)
{
    static Unk_SkillSensor kDefault;
    TiXmlElement elem(strName);
    FUN_140800570(&elem);
    if (m_nSensorStartDelay != kDefault.m_nSensorStartDelay)
        XmlSetAttr((class TiXmlElement*)(&elem), "sensorStartDelay", (unsigned long)m_nSensorStartDelay);
    if (m_nSensorSplashStartDelay != kDefault.m_nSensorSplashStartDelay)
        XmlSetAttr((class TiXmlElement*)(&elem), "sensorSplashStartDelay", (unsigned long)m_nSensorSplashStartDelay);
    if (m_nSensorForceInvokeByInterval != kDefault.m_nSensorForceInvokeByInterval)
        XmlSetAttr((class TiXmlElement*)(&elem), "sensorForceInvokeByInterval", (int)m_nSensorForceInvokeByInterval);
    if (m_nTargetHasBuffID != kDefault.m_nTargetHasBuffID)
        XmlSetAttr((class TiXmlElement*)(&elem), "targetHasBuffID", (unsigned int)m_nTargetHasBuffID);
    if (m_nTargetHasBuffOverlapCount != kDefault.m_nTargetHasBuffOverlapCount)
        XmlSetAttr((class TiXmlElement*)(&elem), "targetHasBuffOverlapCount", (unsigned int)m_nTargetHasBuffOverlapCount);
    if (m_nTargetHasNotBuffID != kDefault.m_nTargetHasNotBuffID)
        XmlSetAttr((class TiXmlElement*)(&elem), "targetHasNotBuffID", (unsigned int)m_nTargetHasNotBuffID);
    if (m_nTargetHasBuffOwner != kDefault.m_nTargetHasBuffOwner)
        XmlSetAttr((class TiXmlElement*)(&elem), "targetHasBuffOwner", (int)m_nTargetHasBuffOwner);
    if (elem.HasAttributes())
        ((TiXmlNode*)(pParent))->InsertEndChild(*(const TiXmlNode*)&elem);
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
    int m_n40;
    float m_f44;
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
      m_n40(0), m_f44(0), m_b48(false), m_n4c(0), m_n50(0), m_n58(0), m_b60(false), m_n64(0), m_b70(false),
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
int SkillActionSkill::Load(TiXmlElement* pElem)
{
    XmlSplit(Unk_ReadString((class Unk_XmlNode*)(pElem), "level", CString("")), m_arrLevel, ",");
    XmlSplit(Unk_ReadString((class Unk_XmlNode*)(pElem), "skillID", CString("")), m_arrSkillID, ",");
    XmlSplit(Unk_ReadString((class Unk_XmlNode*)(pElem), "linkSkillID", CString("")), m_arrLinkSkillID, ",");
    XmlGetAttr((class TiXmlElement*)(pElem), "overlapCount", reinterpret_cast<unsigned int&>(m_nOverlapCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "delay", reinterpret_cast<unsigned long&>(m_nDelay));
    XmlGetAttr((class TiXmlElement*)(pElem), "removeDelay", reinterpret_cast<unsigned long&>(m_nRemoveDelay));
    XmlGetAttr((class TiXmlElement*)(pElem), "interval", reinterpret_cast<unsigned long&>(m_nInterval));
    XmlGetAttr((class TiXmlElement*)(pElem), "immediateActive", reinterpret_cast<int&>(m_nImmediateActive));
    XmlGetAttr((class TiXmlElement*)(pElem), "fireCount", reinterpret_cast<int&>(m_nFireCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "nonTargetActive", reinterpret_cast<int&>(m_nNonTargetActive));
    XmlGetAttr((class TiXmlElement*)(pElem), "useDirection", reinterpret_cast<int&>(m_nUseDirection));
    XmlGetAttr((class TiXmlElement*)(pElem), "onlySensingActive", reinterpret_cast<int&>(m_nOnlySensingActive));
    XmlGetAttr((class TiXmlElement*)(pElem), "dependOnCasterState", reinterpret_cast<int&>(m_nDependOnCasterState));
    XmlGetAttr((class TiXmlElement*)(pElem), "activeByIntervalTick", reinterpret_cast<int&>(m_nActiveByIntervalTick));
    XmlGetAttr((class TiXmlElement*)(pElem), "independent", reinterpret_cast<int&>(m_nIndependent));
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
int SkillActionAdditional::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "additionalID", reinterpret_cast<unsigned int&>(m_nAdditionalID));
    XmlGetAttr((class TiXmlElement*)(pElem), "level", reinterpret_cast<unsigned short&>(m_nLevel));
    XmlGetAttr((class TiXmlElement*)(pElem), "linkSkillID", reinterpret_cast<unsigned int&>(m_nLinkSkillID));
    XmlGetAttr((class TiXmlElement*)(pElem), "overlapCount", reinterpret_cast<unsigned int&>(m_nOverlapCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "skillTarget", reinterpret_cast<int&>(m_nSkillTarget));
    XmlGetAttr((class TiXmlElement*)(pElem), "skillOwner", reinterpret_cast<int&>(m_nSkillOwner));
    XmlGetAttr((class TiXmlElement*)(pElem), "dependOnDamageCount", reinterpret_cast<int&>(m_nDependOnDamageCount));
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
bool SkillGlideData::IsDifferent(const SkillGlideData& o)
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
    if (m_strEffectRun != o.m_strEffectRun) return 1;
    if (m_strEffectIdle != o.m_strEffectIdle) return 1;
    if (m_strAniIdle != o.m_strAniIdle) return 1;
    if (m_strAniRun != o.m_strAniRun) return 1;
    if (m_bOnGroundDisable != o.m_bOnGroundDisable)
        return 1;
    return 0;
}

// @0x140802830
void SkillGlideData::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "id", reinterpret_cast<unsigned int&>(m_nId));
    XmlGetAttr((class TiXmlElement*)(pElem), "gravity", reinterpret_cast<float&>(m_fGravity));
    XmlGetAttr((class TiXmlElement*)(pElem), "heightLimit", reinterpret_cast<float&>(m_fHeightLimit));
    XmlGetAttr((class TiXmlElement*)(pElem), "horizontalAccelerate", reinterpret_cast<float&>(m_fHorizontalAccelerate));
    XmlGetAttr((class TiXmlElement*)(pElem), "horizontalVelocity", reinterpret_cast<float&>(m_fHorizontalVelocity));
    XmlGetAttr((class TiXmlElement*)(pElem), "verticalAccelerate", reinterpret_cast<float&>(m_fVerticalAccelerate));
    XmlGetAttr((class TiXmlElement*)(pElem), "verticalVelocity", reinterpret_cast<float&>(m_fVerticalVelocity));
    XmlGetAttr((class TiXmlElement*)(pElem), "verticalVibrateAmplitude", reinterpret_cast<float&>(m_fVerticalVibrateAmplitude));
    XmlGetAttr((class TiXmlElement*)(pElem), "verticalVibrateFrequency", reinterpret_cast<float&>(m_fVerticalVibrateFrequency));
    XmlGetAttr((class TiXmlElement*)(pElem), "glideVerticalAccelerateLimit", reinterpret_cast<float&>(m_fGlideVerticalAccelerateLimit));
    XmlGetAttr((class TiXmlElement*)(pElem), "glideHorizontalAccelerateLimit", reinterpret_cast<float&>(m_fGlideHorizontalAccelerateLimit));
    XmlGetAttr((class TiXmlElement*)(pElem), "effectRun", m_strEffectRun);
    XmlGetAttr((class TiXmlElement*)(pElem), "effectIdle", m_strEffectIdle);
    XmlGetAttr((class TiXmlElement*)(pElem), "aniIdle", m_strAniIdle);
    XmlGetAttr((class TiXmlElement*)(pElem), "aniRun", m_strAniRun);
    XmlGetAttr((class TiXmlElement*)(pElem), "onGroundDisable", reinterpret_cast<bool&>(m_bOnGroundDisable));
    XmlGetAttr((class TiXmlElement*)(pElem), "nameTagOffset", reinterpret_cast<int&>(m_nNameTagOffset));
}

// @0x140802a40
int SkillGlideData::FUN_140802a40(TiXmlElement* pElem)
{
    TiXmlElement* pGlide = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("glideProperty"));
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
int SkillGlideData::GetId()
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
bool Unk_SkillBlock170::IsDifferent(const Unk_SkillBlock170& o)
{
    if (m_fUp != o.m_fUp) return true;
    if (m_fBack != o.m_fBack) return true;
    return false;
}

// @0x140802d50
int Unk_SkillBlock170::FUN_140802d50(TiXmlElement* pElem)
{
    TiXmlElement* pPush = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("push"));
    if (pPush != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pPush), "up", reinterpret_cast<float&>(m_fUp));
        XmlGetAttr((class TiXmlElement*)(pPush), "back", reinterpret_cast<float&>(m_fBack));
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
bool Unk_SkillBlockA4::IsDifferent(const Unk_SkillBlockA4& o)
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
int Unk_SkillBlockA4::Load(TiXmlElement* pElem)
{
    TiXmlElement* pCombo = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("combo"));
    if (pCombo != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pCombo), "inputSkill", reinterpret_cast<unsigned int&>(m_nInputSkill));
        XmlGetAttr((class TiXmlElement*)(pCombo), "outputSkill", reinterpret_cast<unsigned int&>(m_nOutputSkill));
        XmlGetAttr((class TiXmlElement*)(pCombo), "comboSkill", reinterpret_cast<bool&>(m_bComboSkill));
        XmlGetAttr((class TiXmlElement*)(pCombo), "chargingSkill", reinterpret_cast<bool&>(m_bChargingSkill));
        XmlGetAttr((class TiXmlElement*)(pCombo), "disableChargingAttackSkipFrame", reinterpret_cast<bool&>(m_bDisableChargingAttackSkipFrame));
    }
    return 1;
}

// @0x140802fc0
int Unk_SkillBlockA4::GetOutputSkill(int nSkill)
{
    if (nSkill == m_nInputSkill)
        return m_nOutputSkill;
    return nSkill;
}

// @0x140802ff0
int Unk_SkillBlockA4::IsOutputSkill(int nSkill)
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
bool Unk_SkillBlock160::IsDifferent(const Unk_SkillBlock160& o)
{
    if (m_fMaxDegree != o.m_fMaxDegree) return true;
    if (m_fMaxDistance != o.m_fMaxDistance) return true;
    if (m_fMaxHeight != o.m_fMaxHeight) return true;
    if (m_nUseMove != o.m_nUseMove) return true;
    return false;
}

// @0x140803140
int Unk_SkillBlock160::Load(TiXmlElement* pElem)
{
    TiXmlElement* pTargeting = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("autoTargeting"));
    if (pTargeting != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pTargeting), "autoTargetingMaxDegree", reinterpret_cast<float&>(m_fMaxDegree));
        XmlGetAttr((class TiXmlElement*)(pTargeting), "autoTargetingMaxDistance", reinterpret_cast<float&>(m_fMaxDistance));
        XmlGetAttr((class TiXmlElement*)(pTargeting), "autoTargetingMaxHeight", reinterpret_cast<float&>(m_fMaxHeight));
        XmlGetAttr((class TiXmlElement*)(pTargeting), "autoTargetUseMove", reinterpret_cast<int&>(m_nUseMove));
    }
    return 1;
}

// @0x1408031f0
int Unk_SkillBlock160::FUN_1408031f0(void* pParent)
{
    return 1;
}

// @0x140803210
__int64 Unk_SkillBlock160::GetKey()
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
bool Unk_SkillBlockB0::IsDifferent(const Unk_SkillBlockB0& o)
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
int Unk_SkillBlockB0::Load(TiXmlElement* pElem)
{
    TiXmlElement* pChange = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("changeSkill"));
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
bool Unk_SkillBlock150::IsDifferent(const Unk_SkillBlock150& o)
{
    if (m_eEnable != o.m_eEnable) return true;
    if (m_fMoveSpeed != o.m_fMoveSpeed) return true;
    if (m_fDuration != o.m_fDuration) return true;
    if (m_fMaxDistance != o.m_fMaxDistance) return true;
    return false;
}

// @0x140803860
int Unk_SkillBlock150::Load(TiXmlElement* pElem)
{
    TiXmlElement* pMagic = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("magicControl"));
    if (pMagic != 0)
    {
        XmlValue(pMagic, "enable", m_eEnable);
        XmlGetAttr((class TiXmlElement*)(pMagic), "moveSpeed", reinterpret_cast<float&>(m_fMoveSpeed));
        m_fMoveSpeed = FromPercent(m_fMoveSpeed);
        XmlGetAttr((class TiXmlElement*)(pMagic), "duration", reinterpret_cast<float&>(m_fDuration));
        XmlGetAttr((class TiXmlElement*)(pMagic), "maxDistance", reinterpret_cast<float&>(m_fMaxDistance));
    }
    return 1;
}

// @0x140803930
int Unk_SkillBlock150::Save(void* pParent)
{
    if (m_eEnable == 0)
        return 1;
    TiXmlElement elem("magicControl");
    XmlSetAttr((class TiXmlElement*)(&elem), "enable", (int)m_eEnable);
    XmlSetAttr((class TiXmlElement*)(&elem), "moveSpeed", m_fMoveSpeed);
    XmlSetAttr((class TiXmlElement*)(&elem), "duration", m_fDuration);
    if (m_fMaxDistance != 0.0f)
        XmlSetAttr((class TiXmlElement*)(&elem), "maxDistance", m_fMaxDistance);
    ((TiXmlNode*)(pParent))->InsertEndChild(*(const TiXmlNode*)&elem);
    return 1;
}

// @0x140803a30
SkillLevelData::SkillLevelData(SkillData* pSkill)
    : m_nSp(0), m_nEp(0), m_nMeso(0), m_nCooldown(0), m_fHpRate(0), m_nStanceDamageRate(0), m_pSkill(pSkill),
      m_nLevel(0)
{
}

// @0x140803b30
bool SkillLevelData::IsDifferent(const SkillLevelData& o)
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
        if (m_vMotion[i]->IsDifferent(*o.m_vMotion[i])) return 1;
    }
    if (m_vAdditional.size() != o.m_vAdditional.size()) return 1;
    for (unsigned __int64 i = 0; i < m_vAdditional.size(); i++)
    {
        if (*m_vAdditional[i] != *o.m_vAdditional[i]) return 1;
    }
    if (m_detect.IsDifferent(o.m_detect)) return 1;
    return 0;
}

// @0x140803dc0
unsigned SkillLevelData::GetSkillId()
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
SkillMotionData* SkillLevelData::FindMotionBySequenceName(CString strSequence)
{
    for (SkillMotionData* pMotion : m_vMotion)
    {
        if (pMotion->m_strSequenceName == strSequence)
            return pMotion;
    }
    return 0;
}

// @0x140803f00
SkillMotionData* SkillLevelData::GetMotion(int nMotion)
{
    if (nMotion >= (int)m_vMotion.size())
        return 0;
    return m_vMotion[nMotion];
}

// @0x140803f60
SkillAttackData* SkillLevelData::GetAttack(int nMotion, int nAttack)
{
    SkillMotionData* pMotion = GetMotion(nMotion);
    if (pMotion == 0)
        return 0;
    return pMotion->GetAttack(nAttack);
}

// @0x140803fb0
SkillAttackData* SkillLevelData::FUN_140803fb0(int nMotion, CString strName)
{
    SkillMotionData* pMotion = GetMotion(nMotion);
    if (pMotion == 0)
        return 0;
    return pMotion->FindAttackByPoint(strName);
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
Unk_RangeProperty* SkillLevelData::GetAttackRange(int nMotion, int nAttack)
{
    SkillAttackData* pAttack = GetAttack(nMotion, nAttack);
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
    SkillMotionData* pMotion = GetMotion(nMotion);
    if (pMotion == 0)
        return 0;
    SkillAttackData* pAttack = pMotion->GetAttack(nAttack);
    if (pAttack == 0)
        return 0;
    const SkillDamage& damage = pAttack->m_damage;
    return damage.m_fRate;
}

// @0x1408041d0
__int64 SkillLevelData::FUN_1408041d0(int nMotion, int nAttack)
{
    SkillMotionData* pMotion = GetMotion(nMotion);
    if (pMotion == 0)
        return 0;
    SkillAttackData* pAttack = pMotion->GetAttack(nAttack);
    if (pAttack == 0)
        return 0;
    const SkillDamage& damage = pAttack->m_damage;
    return damage.m_nValue;
}

// @0x140804250
int SkillLevelData::GetStanceDamageRate()
{
    return m_nStanceDamageRate;
}

// @0x140804270
int SkillLevelData::GetMotionCount()
{
    return (int)m_vMotion.size();
}

// @0x1408042a0
float SkillLevelData::GetAttackRangeValue(int nMotion, int nAttack)
{
    Unk_RangeProperty* pRange = GetAttackRange(nMotion, nAttack);
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
    for (int nMotion = 0; nMotion < GetMotionCount(); nMotion++)
    {
        int nAttack = 0;
        while (Unk_RangeProperty* pRange = GetAttackRange(nMotion, nAttack++))
        {
            if (pRange->m_nType == 4)
                fMax = (std::max)(fMax, pRange->m_f1c);
            else
                fMax = (std::max)(fMax, pRange->m_f10);
        }
    }
    return fMax;
}

// @0x1408043f0
int SkillLevelData::FUN_1408043f0(int nMotion, int nAttack)
{
    SkillAttackData* pAttack = GetAttack(nMotion, nAttack);
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
    SkillMotionData* pMotion = GetMotion(nMotion);
    if (pMotion == 0)
        return s_strEmpty;
    switch (nKind)
    {
    case 2:
        return pMotion->m_strMotionEffect;
    case 3:
        return pMotion->m_strLoopEffect;
    case 4:
        return pMotion->m_strEndEffect;
    }
    return s_strEmpty;
}

// @0x1408045f0
int SkillLevelData::FUN_1408045f0(int nMotion, int nAttack)
{
    SkillMotionData* pMotion = GetMotion(nMotion);
    if (pMotion == 0)
        return 0;
    SkillAttackData* pAttack = pMotion->GetAttack(nAttack);
    if (pAttack == 0)
        return 0;
    return pAttack->m_nMagicPathID;
}

// @0x140804660
float SkillLevelData::GetCooldown()
{
    return FUN_14028d280(m_nCooldown);
}

// @0x140804690
int SkillLevelData::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "value", reinterpret_cast<unsigned short&>(m_nLevel));
    XmlGetAttr((class TiXmlElement*)(pElem), "sp", reinterpret_cast<int&>(m_nSp));
    XmlGetAttr((class TiXmlElement*)(pElem), "ep", reinterpret_cast<int&>(m_nEp));
    XmlGetAttr((class TiXmlElement*)(pElem), "meso", reinterpret_cast<int&>(m_nMeso));
    XmlGetAttr((class TiXmlElement*)(pElem), "hpRate", reinterpret_cast<float&>(m_fHpRate));
    XmlGetAttr((class TiXmlElement*)(pElem), "cooldown", reinterpret_cast<unsigned long&>(m_nCooldown));
    XmlGetAttr((class TiXmlElement*)(pElem), "stringParam", m_strStringParam);
    float fStanceDamageRate = 0;
    XmlGetAttr((class TiXmlElement*)(pElem), "stanceDamageRate", reinterpret_cast<float&>(fStanceDamageRate));
    m_nStanceDamageRate = (unsigned int)(fStanceDamageRate * 1000.0f);
    if (m_nLevel < 1)
    {
        unsigned nSkillId = GetSkillId();
        Unk_AdditionalLog<unsigned>(GetLogString(), 1, 0x13, L"스킬 레벨이 잘못되었습니다.[Skill Level Data - [{0}]]", nSkillId);
        return 0;
    }
    TiXmlElement* pDetect = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("detectProperty"));
    if (pDetect != 0)
        m_detect.Load(pDetect);
    for (TiXmlElement* pChild : ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("actionAdditional")))
    {
        MS2Ptr<SkillActionAdditional> spAction(new SkillActionAdditional);
        if (!spAction->Load(pChild))
            return 0;
        m_vAdditional.push_back(spAction);
    }
    for (TiXmlElement* pChild = ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("motion")); pChild != 0; pChild = ((class TiXmlElement*)((class Unk_XmlNode*)(pChild))->NextSibling("motion")))
    {
        MS2Ptr<SkillMotionData> spMotion(new SkillMotionData);
        if (!spMotion->FUN_1408080d0(pChild))
            return 0;
        m_vMotion.push_back(spMotion);
    }
    return 1;
}

// @0x140804ae0
int SkillLevelData::Save(void* pParent)
{
    TiXmlElement elem("level");
    XmlSetAttr((class TiXmlElement*)(&elem), "value", m_nLevel);
    if (!m_strStringParam.IsEmpty())
        XmlSetAttr((class TiXmlElement*)(&elem), "value", m_strStringParam);
    {
        TiXmlElement detect("detectProperty");
        m_detect.FUN_140800570(&detect);
        if (detect.HasAttributes())
            ((TiXmlNode*)(&elem))->InsertEndChild(*(const TiXmlNode*)&detect);
    }
    for (SkillMotionData* pMotion : m_vMotion)
    {
        if (!pMotion->Save(&elem))
            return 0;
    }
    ((TiXmlNode*)(pParent))->InsertEndChild(*(const TiXmlNode*)&elem);
    return 1;
}

// @0x140804c90
__int64 SkillLevelData::GetMotionKey(unsigned __int64 nMotion)
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
bool SkillMotionData::IsDifferent(const SkillMotionData& o)
{
    if (m_strSequenceName != o.m_strSequenceName) return 1;
    if (m_fSequenceSpeed != o.m_fSequenceSpeed) return 1;
    if (m_strMotionEffect != o.m_strMotionEffect) return 1;
    if (m_strSplashInvokeEffect != o.m_strSplashInvokeEffect) return 1;
    if (m_strLoopEffect != o.m_strLoopEffect) return 1;
    if (m_strEndEffect != o.m_strEndEffect) return 1;
    if (m_strSplashEndEffect != o.m_strSplashEndEffect) return 1;
    if (m_strWeaponSequenceName != o.m_strWeaponSequenceName) return 1;
    if (m_mapTagEffects.GetCount() != o.m_mapTagEffects.GetCount()) return 1;
    for (POSITION pos = m_mapTagEffects.GetHeadPosition(); pos != 0; m_mapTagEffects.GetNext(pos))
    {
        CString strKey = m_mapTagEffects.GetKeyAt(pos);
        CString strValue = m_mapTagEffects.GetValueAt(pos);
        CString strOther;
        if (!o.m_mapTagEffects.Lookup(strKey, strOther)) return 1;
        if (strValue != strOther) return 1;
    }
    if (m_strLoopKeepEffect != o.m_strLoopKeepEffect) return 1;
    if (m_strLoopEndEffect != o.m_strLoopEndEffect) return 1;
    if (m_strSplashDurationCastEffect != o.m_strSplashDurationCastEffect) return 1;
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
    if (m_strSelfInputCombo != o.m_strSelfInputCombo) return 1;
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
SkillAttackData* SkillMotionData::GetAttack(int nAttack)
{
    if (nAttack >= (int)m_vAttack.size())
        return 0;
    return m_vAttack[nAttack];
}

// @0x140807e80
SkillAttackData* SkillMotionData::FindAttackByPoint(const CString& strPoint)
{
    for (SkillAttackData* pAttack : m_vAttack)
    {
        if (pAttack->m_strPoint == strPoint)
            return pAttack;
    }
    return 0;
}

// @0x140807f20
SkillAttackData* SkillMotionData::FUN_140807f20(const CString& strPoint)
{
    for (SkillAttackData* pAttack : m_vAttack)
    {
        if (!pAttack->HasPause())
            continue;
        if (pAttack->m_strPoint == strPoint)
            return pAttack;
    }
    return 0;
}

// @0x140807fd0
int SkillMotionData::GetAttackCount()
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
int SkillMotionData::FUN_1408080d0(TiXmlElement* pElem)
{
    Load(pElem);
    for (TiXmlElement* pChild : ((class TiXmlElement*)((class Unk_XmlNode*)(pElem))->FirstChild("attack")))
    {
        MS2Ptr<SkillAttackData> spAttack(new SkillAttackData);
        if (!spAttack->Load(pChild))
            return 0;
        m_vAttack.push_back(spAttack);
    }
    return 1;
}

// @0x140808240
int SkillMotionData::Save(void* pParent)
{
    TiXmlElement elem("motion");
    for (SkillAttackData* pAttack : m_vAttack)
    {
        if (!pAttack->Save(&elem))
            return 0;
    }
    if (elem.HasAttributes() || elem.HasContent())
        ((TiXmlNode*)(pParent))->InsertEndChild(*(const TiXmlNode*)&elem);
    return 1;
}

// @0x140808350
void SkillMotionData::Load(TiXmlElement* pElem)
{
    XmlGetAttr((class TiXmlElement*)(pElem), "sequenceName", m_strSequenceName);
    XmlGetAttr((class TiXmlElement*)(pElem), "sequenceSpeed", reinterpret_cast<float&>(m_fSequenceSpeed));
    if (GetLaunchOptions()->FUN_1406af020())
    {
        XmlGetAttr((class TiXmlElement*)(pElem), "selfInputCombo", m_strSelfInputCombo);
        XmlGetAttr((class TiXmlElement*)(pElem), "motionEffect", m_strMotionEffect);
        XmlGetAttr((class TiXmlElement*)(pElem), "loopEffect", m_strLoopEffect);
        XmlGetAttr((class TiXmlElement*)(pElem), "endEffect", m_strEndEffect);
        XmlGetAttr((class TiXmlElement*)(pElem), "splashInvokeEffect", m_strSplashInvokeEffect);
        XmlGetAttr((class TiXmlElement*)(pElem), "splashEndEffect", m_strSplashEndEffect);
        XmlGetAttr((class TiXmlElement*)(pElem), "loopKeepEffect", m_strLoopKeepEffect);
        XmlGetAttr((class TiXmlElement*)(pElem), "loopEndEffect", m_strLoopEndEffect);
        XmlGetAttr((class TiXmlElement*)(pElem), "splashDurationCastEffect", m_strSplashDurationCastEffect);
        XmlQuery((class TiXmlElement*)(pElem), "IgnoreOptimalHideCastEffect", m_bA0);
        XmlQuery((class TiXmlElement*)(pElem), "splashCastEffectStartDelay", m_bSplashCastEffectStartDelay);
    }
    XmlGetAttr((class TiXmlElement*)(pElem), "splashLifeTick", reinterpret_cast<unsigned long&>(m_nSplashLifeTick));
    XmlGetAttr((class TiXmlElement*)(pElem), "splashInvokeCoolTick", reinterpret_cast<unsigned long&>(m_nSplashInvokeCoolTick));
    XmlGetAttr((class TiXmlElement*)(pElem), "weaponSequenceName", m_strWeaponSequenceName);
    ATL::CAtlArray<CString> arrTags;
    XmlTokenList(pElem, "strTagEffects", arrTags);
    for (unsigned i = 0; i < arrTags.GetCount(); i++)
    {
        ATL::CAtlArray<CString> arrPair;
        Unk_SplitImplA(arrTags[i], &arrPair, "=");
        if (arrPair.GetCount() == 2)
            m_mapTagEffects.SetAt(arrPair[0], arrPair[1]);
    }
    XmlGetAttr((class TiXmlElement*)(pElem), "keyMove", reinterpret_cast<float&>(m_fAC));
    XmlValue(pElem, "movetype", m_eMoveType);
    XmlGetAttr((class TiXmlElement*)(pElem), "moveangle", reinterpret_cast<float&>(m_fMoveAngle));
    XmlGetAttr((class TiXmlElement*)(pElem), "movedistance", reinterpret_cast<float&>(m_fB8));
    XmlValue(pElem, "moveEaseType", m_eMoveEaseType);
    XmlGetAttr((class TiXmlElement*)(pElem), "ignoreCollisionGroups", reinterpret_cast<unsigned int&>(m_nIgnoreCollisionGroups));
    XmlGetAttr((class TiXmlElement*)(pElem), "holdWeapon", reinterpret_cast<int&>(m_nHoldWeapon));
    XmlGetAttr((class TiXmlElement*)(pElem), "loopCount", reinterpret_cast<int&>(m_nLoopCount));
    XmlGetAttr((class TiXmlElement*)(pElem), "pushCylinderVelH", reinterpret_cast<float&>(m_fPushCylinderVelH));
    XmlGetAttr((class TiXmlElement*)(pElem), "pushCylinderVelV", reinterpret_cast<float&>(m_fPushCylinderVelV));
    XmlGetAttr((class TiXmlElement*)(pElem), "pushCylinderOuter", reinterpret_cast<float&>(m_fPushCylinderOuter));
    XmlGetAttr((class TiXmlElement*)(pElem), "pushCylinderInner", reinterpret_cast<float&>(m_fPushCylinderInner));
    XmlGetAttr((class TiXmlElement*)(pElem), "pushCylinderHeight", reinterpret_cast<float&>(m_fPushCylinderHeight));
    XmlGetAttr((class TiXmlElement*)(pElem), "faceTarget", reinterpret_cast<int&>(m_nFaceTarget));
    XmlQuery((class TiXmlElement*)(pElem), "doesPlayIdleOnSkillEnd", m_bDoesPlayIdleOnSkillEnd);
    XmlGetAttr((class TiXmlElement*)(pElem), "startNoneBlendDelay", reinterpret_cast<int&>(m_nStartNoneBlendDelay));
    XmlGetAttr((class TiXmlElement*)(pElem), "aniSkipTime", reinterpret_cast<float&>(m_fAniSkipTime));
}

