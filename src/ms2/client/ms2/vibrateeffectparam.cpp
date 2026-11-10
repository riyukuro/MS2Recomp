// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See vibrateeffectparam.h.
// MS2-UNIT: ?\vibrateeffectparam.cpp
// MS2-RANGE: 0x141b72630-0x141b72f60 .text$mn
// MS2-PIN: ??1CVibrateEffectParam@@UEAA@XZ 0x141b72e80
// MS2-PIN: ??_GCVibrateEffect@@UEAAPEAXI@Z 0x141b72ea0
// MS2-PIN: ??_GCVibrateEffectParam@@UEAAPEAXI@Z 0x141b72f00
// MS2-PIN: ?GetRTTI@CVibrateEffect@@UEBAPEBVNiRTTI@@XZ 0x141b72f50
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\vibrateeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "vibrateeffectparam.h"
#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/client/ms2/camera.h"

// Game TinyXML element and its float attribute helper (commonfiles\tinyxmlhelper.cpp).
class TiXmlElement;
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360

// Game log (commonfiles singleton 0x140166440).
class CLogString;
template <class T> void Unk_AchieveLog(class CLogString*, int, int, const wchar_t*, const T&);   // C3: was V::FUN_14015eb90
class Unk_GameLog
{
public:
};
class CLogString* GetLogString();   // C3: was FUN_140166440

// Game clock (commonfiles singleton 0x14086d260): current time in seconds.

// Feature switches (commonfiles\featuremanager.cpp) and game options (gamepad vibration flag).
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
struct Unk_PadOption
{
    char m_unk_00[2];
    bool m_bVibration;              // +0x02
};
struct Unk_GpState* GetGamepadState(class Unk_GpSettings*);   // C3: the real function (0x140a58500, gameoptiongamepad.cpp)
MS2InputService* FUN_140a58540();

namespace Common { class Constants { public: template<class T> class Value { public: T* Get(); }; }; }   // C3: view of clientconstants.h; Value<float>::Get() is 0x140298f40
// A float table value of the client configuration (FUN_1401d3200).
class Unk_VibrateScale
{
public:
};
class Unk_ClientConfig
{
public:
    char m_pad_0000[0x90a0];
    Unk_VibrateScale m_90a0;
};
namespace Client { class Constants; } template<class T> class TSingleton; template<> class TSingleton<Client::Constants> { public: static Client::Constants* GetInstance(); }; class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance)

// @0x141b72630
CVibrateEffectParam::CVibrateEffectParam()
    : CEffectParam(0xc), m_fDamping(1.0f), m_fDampingTime(0.0f)
{
}

// @0x141b72690
void CVibrateEffectParam::vfunc_1(TiXmlElement* pNode)
{
    CEffectParam::vfunc_1(pNode);
    XmlGetAttr((class TiXmlElement*)(pNode), "freq", m_fFreq);
    XmlGetAttr((class TiXmlElement*)(pNode), "amp", m_fAmp);
    XmlGetAttr((class TiXmlElement*)(pNode), "damping", m_fDamping);
    XmlGetAttr((class TiXmlElement*)(pNode), "dampingTime", m_fDampingTime);
}
MS2_REPLACE_METHOD(0x141b72690, CVibrateEffectParam, vfunc_1, 150, 0xDF38CF1B);

// @0x141b72730
bool CVibrateEffectParam::vfunc_2()
{
    if (!CEffectParam::vfunc_2())
        return false;
    if (m_fDuration <= m_fDampingTime)
    {
        Unk_AchieveLog<CString>((class CLogString*)GetLogString(), 1, 0x13,
            L"Damping 시작 시간이 이펙트 종료 시간보다 큽니다[VibrateEffect - DampingStartTime] [{0}]", m_str20);
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x141b72730, CVibrateEffectParam, vfunc_2, 117, 0x4AFF308C);

// @0x141b727b0
// Not hooked: constructs CVibrateEffect with this unit's (DLL) constructor/vftable.
CEffectPtr CVibrateEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CVibrateEffect;
}

// @0x141b72850
bool CVibrateEffectParam::vfunc_7(Unk_EffectTarget* p)
{
    if (CEffectParam::vfunc_7(p))
        return true;
    if (p->m_nKind == 3)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x141b72850, CVibrateEffectParam, vfunc_7, 62, 0xB3A58843);

// @0x141b728a0
CVibrateEffect::CVibrateEffect()
{
}

// @0x141b728e0
CVibrateEffect::~CVibrateEffect()
{
}

// @0x141b72910
CVibrateEffect* Unk_VibrateEffectFactory::CreateVibrateEffect(const CVibrateEffectParam* pParam)
{
    if (pParam != NULL)
    {
        CVibrateEffect* pEffect = new (efd::MemHint(efd::MemHint::NONE)) CVibrateEffect;
        pEffect->m_dStartTime = TSingleton<CMainSystem>::GetInstance()/*C3:TSingleton<CMainSystem>::GetInstance*/->GetGameTime() + pParam->m_fStartDelay;
        pEffect->m_fDuration = pParam->m_fDuration;
        pEffect->m_b2c = pParam->m_b30;
        if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070())
        {
            CVibrateCameraEffect* pCamera = new CVibrateCameraEffect(pEffect->m_dStartTime,
                pEffect->m_dStartTime + pEffect->m_fDuration, pParam->m_fFreq, pParam->m_fAmp, pParam->m_fDamping,
                pEffect->m_dStartTime + pParam->m_fDampingTime, 1);
            TSingleton<CameraMgr>::GetInstance()->AddEffect(MS2Ptr<CCameraEffect>(pCamera));
        }
        if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xc3))
        {
            if (reinterpret_cast<Unk_PadOption*>(GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance())))->m_bVibration && 0.0f < pEffect->m_fDuration)
                FUN_140a58540()->StartRumbleFor(pEffect->m_fDuration * *reinterpret_cast<Common::Constants::Value<float>*>(&((class Unk_ClientConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_90a0)->Get());
        }
        return pEffect;
    }
    return NULL;
}

// @0x141b72bd0
bool CVibrateEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!TSingleton<CameraMgr>::GetInstance()->FUN_140aed0f0())
        return false;
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CVibrateEffectParam* pVibrate = static_cast<const CVibrateEffectParam*>(pParam);
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140a18070())
    {
        CVibrateCameraEffect* pCamera = new CVibrateCameraEffect(m_dStartTime, m_dStartTime + m_fDuration,
            pVibrate->m_fFreq, pVibrate->m_fAmp, pVibrate->m_fDamping, m_dStartTime + pVibrate->m_fDampingTime, 1);
        TSingleton<CameraMgr>::GetInstance()->AddEffect(MS2Ptr<CCameraEffect>(pCamera));
    }
    if (((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xc3))
    {
        if (reinterpret_cast<Unk_PadOption*>(GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance())))->m_bVibration && 0.0f < m_fDuration)
            FUN_140a58540()->StartRumbleFor(m_fDuration * *reinterpret_cast<Common::Constants::Value<float>*>(&((class Unk_ClientConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_90a0)->Get());
    }
    return true;
}
MS2_REPLACE_METHOD(0x141b72bd0, CVibrateEffect, vfunc_3, 552, 0xB9466C18);

// @0x141b72e00
bool CVibrateEffect::vfunc_9()
{
    double dNow = TSingleton<CMainSystem>::GetInstance()/*C3:TSingleton<CMainSystem>::GetInstance*/->GetGameTime();
    return dNow < m_dStartTime + m_fDuration;
}
MS2_REPLACE_METHOD(0x141b72e00, CVibrateEffect, vfunc_9, 95, 0xF224C3B9);

// @0x141b72e70
void CVibrateEffect::vfunc_7()
{
}

// @0x141b72f40
int CVibrateEffect::vfunc_12()
{
    return 0xc;
}
