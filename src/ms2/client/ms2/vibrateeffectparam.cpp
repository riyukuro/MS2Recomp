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

// Game TinyXML element and its float attribute helper (commonfiles\tinyxmlhelper.cpp).
class Unk_140165cf0;
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);

// Game log (commonfiles singleton 0x140166440).
class Unk_GameLog
{
public:
    void FUN_14015eb90(int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);
};
Unk_GameLog* FUN_140166440();

// Game clock (commonfiles singleton 0x14086d260): current time in seconds.
class Unk_GameClock
{
public:
    double FUN_141473280();
};
Unk_GameClock* FUN_14086d260();

// The camera shake of the camera service (camera.cpp): constructed here, started through the camera manager.
class CVibrateCameraEffect
{
public:
    CVibrateCameraEffect(double dStart, double dEnd, float fFreq, float fAmp, float fDamping, double dDampingStart,
                         int nFlag);                            // 0x140ae9450
    char m_unk[0x58];
};
MS2_CHECK_SIZE(CVibrateCameraEffect, 0x58);

// Reference holder handed to the camera manager (callee-destroyed; 0x1417f5820 sets it up from the effect).
struct Unk_CamEffectRef
{
    void* m_unk[4];
};
Unk_CamEffectRef FUN_1417f5820(CVibrateCameraEffect* pEffect);

// Camera manager (singleton 0x1409478c0).
class Unk_CameraManager
{
public:
    int FUN_140aed0f0();                                        // camera effects enabled
    int FUN_140a18070();                                        // camera ready
    void FUN_140af0de0(const Unk_CamEffectRef& kRef);                 // queue the camera effect (consumes pRef)
};
Unk_CameraManager* FUN_1409478c0();

// Feature switches (commonfiles\featuremanager.cpp) and game options (gamepad vibration flag).
class Unk_FeatureSet
{
public:
    bool FUN_14036d570(int nFeature);
};
Unk_FeatureSet* FUN_140166410();
struct Unk_PadOption
{
    char m_unk_00[2];
    bool m_bVibration;              // +0x02
};
class Unk_GameOption
{
public:
    Unk_PadOption* FUN_140a58500();
};
Unk_GameOption* FUN_1409a8b10();
class Unk_GamepadService
{
public:
    void FUN_140d8b3e0(double dSeconds);                        // rumble for the given time
};
Unk_GamepadService* FUN_140a58540();

// A float table value of the client configuration (FUN_1401d3200).
class Unk_VibrateScale
{
public:
    const float& FUN_140298f40();
};
class Unk_ClientConfig
{
public:
    char m_pad_0000[0x90a0];
    Unk_VibrateScale m_90a0;
};
Unk_ClientConfig* FUN_1401d3200();

// @0x141b72630
CVibrateEffectParam::CVibrateEffectParam()
    : CEffectParam(0xc), m_fDamping(1.0f), m_fDampingTime(0.0f)
{
}

// @0x141b72690
void CVibrateEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_140873360(pNode, "freq", m_fFreq);
    FUN_140873360(pNode, "amp", m_fAmp);
    FUN_140873360(pNode, "damping", m_fDamping);
    FUN_140873360(pNode, "dampingTime", m_fDampingTime);
}
MS2_REPLACE_METHOD(0x141b72690, CVibrateEffectParam, vfunc_1, 150, 0xDF38CF1B);

// @0x141b72730
bool CVibrateEffectParam::vfunc_2()
{
    if (!CEffectParam::vfunc_2())
        return false;
    if (m_fDuration <= m_fDampingTime)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13,
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
CVibrateEffect* Unk_VibrateEffectFactory::FUN_141b72910(const CVibrateEffectParam* pParam)
{
    if (pParam != NULL)
    {
        CVibrateEffect* pEffect = new (efd::MemHint(efd::MemHint::NONE)) CVibrateEffect;
        pEffect->m_dStartTime = FUN_14086d260()->FUN_141473280() + pParam->m_fStartDelay;
        pEffect->m_fDuration = pParam->m_fDuration;
        pEffect->m_b2c = pParam->m_b30;
        if (FUN_1409478c0()->FUN_140a18070())
        {
            CVibrateCameraEffect* pCamera = new CVibrateCameraEffect(pEffect->m_dStartTime,
                pEffect->m_dStartTime + pEffect->m_fDuration, pParam->m_fFreq, pParam->m_fAmp, pParam->m_fDamping,
                pEffect->m_dStartTime + pParam->m_fDampingTime, 1);
            FUN_1409478c0()->FUN_140af0de0(FUN_1417f5820(pCamera));
        }
        if (FUN_140166410()->FUN_14036d570(0xc3))
        {
            if (FUN_1409a8b10()->FUN_140a58500()->m_bVibration && 0.0f < pEffect->m_fDuration)
                FUN_140a58540()->FUN_140d8b3e0(pEffect->m_fDuration * FUN_1401d3200()->m_90a0.FUN_140298f40());
        }
        return pEffect;
    }
    return NULL;
}

// @0x141b72bd0
bool CVibrateEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!FUN_1409478c0()->FUN_140aed0f0())
        return false;
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CVibrateEffectParam* pVibrate = static_cast<const CVibrateEffectParam*>(pParam);
    if (FUN_1409478c0()->FUN_140a18070())
    {
        CVibrateCameraEffect* pCamera = new CVibrateCameraEffect(m_dStartTime, m_dStartTime + m_fDuration,
            pVibrate->m_fFreq, pVibrate->m_fAmp, pVibrate->m_fDamping, m_dStartTime + pVibrate->m_fDampingTime, 1);
        FUN_1409478c0()->FUN_140af0de0(FUN_1417f5820(pCamera));
    }
    if (FUN_140166410()->FUN_14036d570(0xc3))
    {
        if (FUN_1409a8b10()->FUN_140a58500()->m_bVibration && 0.0f < m_fDuration)
            FUN_140a58540()->FUN_140d8b3e0(m_fDuration * FUN_1401d3200()->m_90a0.FUN_140298f40());
    }
    return true;
}
MS2_REPLACE_METHOD(0x141b72bd0, CVibrateEffect, vfunc_3, 552, 0xB9466C18);

// @0x141b72e00
bool CVibrateEffect::vfunc_9()
{
    double dNow = FUN_14086d260()->FUN_141473280();
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
