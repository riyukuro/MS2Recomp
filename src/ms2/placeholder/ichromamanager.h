// ichromamanager.h - PLACEHOLDER for ChromaSDK::IChromaManager (RTTI .?AVIChromaManager@ChromaSDK@@), the Razer Chroma
// keyboard/mouse lighting service interface. NOT an original header. Recovered by w512 with unit_140a93d00 (the
// client\ms2\razerchroma sources, assert path ...\client\ms2\razerchroma\chromaeffectplaying.h).
// vftable 0x142dcf828: 29 slots, all _purecall except the deleting dtor 0x140aa6cc0 (inline ctor 0x140aa6210, dtor
// 0x140aa63f0). Implementations: ChromaManagerImpl (secondary base at +8, vftable 0x142dcfa20) and ChromaManagerDummy
// (the default instance, vftable 0x142dd0398). Method names after the Razer Chroma SDK entry point each implementation
// forwards to (GetProcAddress names in ChromaManagerImpl::LoadSDK 0x140a9ebb0); the others are invented.
// Callers reach the service through GetChromaManager() (0x140a94350, ICF-shared by every caller that returns the
// pointer at 0x1439f4d68); SetChromaManager(0) selects the dummy.
#pragma once
#include <windows.h>
#include <afx.h>

#include "../../../third_party/razer/CSDK_SampleApp/Razer/RzChromaSDKDefines.h"
#include "../../../third_party/razer/CSDK_SampleApp/Razer/RzChromaSDKTypes.h"
#include "../../../third_party/razer/CSDK_SampleApp/Razer/RzErrors.h"

#include "ms2/ms2layout.h"

namespace ChromaSDK {

// the state ids SetState takes (index into ChromaManagerImpl::m_effects); names invented from the effect classes
enum
{
    STATE_PLAYING,
    STATE_LOADING,
    STATE_TALKING,
    STATE_LOGIN,
    STATE_LOGO,
    STATE_RIPPLE,
    STATE_CHARACTER,
    STATE_DEATH,
    STATE_RESURRECTION,
    STATE_DCLEAR,
    STATE_SURVIVE_WINNER,
    STATE_CINEMATIC,
    STATE_COUNT,
};

class IChromaManager
{
public:
    IChromaManager() {}                                                                     // 0x140aa6210
    virtual ~IChromaManager() {}                                                            //  0 0x140aa63f0 (??_G 0x140aa6cc0)
    virtual bool Initialize() = 0;                                                          //  1
    virtual void Finalize() = 0;                                                            //  2 (deletes the object)
    virtual int GetKeyboardKey(int nKey) = 0;                                               //  3 DirectInput key -> row << 8 | column, -1 = none
    virtual void DeleteReservedEffects() = 0;                                               //  4
    virtual void ReserveDeleteEffect(RZEFFECTID effectId) = 0;                              //  5
    virtual void OnKeyName(const CStringW& strName) = 0;                                    //  6
    virtual void OnKeySkill(int nSkill, bool bKeep) = 0;                                    //  7
    virtual void ResetKeys(bool bForce) = 0;                                                //  8
    virtual void RefreshKeys() = 0;                                                         //  9
    virtual void SetState(int nState) = 0;                                                  // 10
    virtual int GetState() = 0;                                                             // 11
    virtual void Pause() = 0;                                                               // 12
    virtual void Resume() = 0;                                                              // 13
    virtual void SetColorMode(int nMode) = 0;                                               // 14
    virtual COLORREF GetColor(int nIndex) = 0;                                              // 15
    virtual void SetCooldown(int nSlot, int a2, __int64 a3, float fTime) = 0;               // 16
    virtual void ResetCooldown(int nSlot) = 0;                                              // 17
    virtual RZRESULT CreateEffect(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) = 0;   // 18
    virtual RZRESULT CreateChromaLinkEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) = 0;        // 19
    virtual RZRESULT CreateHeadsetEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) = 0;           // 20
    virtual RZRESULT CreateKeyboardEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) = 0;          // 21
    virtual RZRESULT CreateKeypadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) = 0;            // 22
    virtual RZRESULT CreateMouseEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) = 0;             // 23
    virtual RZRESULT CreateMousepadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) = 0;          // 24
    virtual RZRESULT SetEffect(RZEFFECTID EffectId) = 0;                                    // 25
    virtual RZRESULT DeleteEffect(RZEFFECTID EffectId) = 0;                                 // 26
    virtual RZRESULT PlayEffect(RZEFFECTID EffectId) = 0;                                   // 27 (impl calls SetEffect)
    virtual RZRESULT RemoveEffect(RZEFFECTID EffectId) = 0;                                 // 28 (impl calls DeleteEffect)
};
MS2_CHECK_SIZE(IChromaManager, 8);

extern IChromaManager* g_pChromaManager;                    // 0x1439f4d68 (initially &the dummy 0x143ab89f8)

// @0x140a94370
inline IChromaManager* GetChromaManagerPtr() { return g_pChromaManager; }
// @0x140a94350
inline IChromaManager* GetChromaManager() { return GetChromaManagerPtr(); }

void SetChromaManager(IChromaManager* pManager);            // 0x140aaa6a0 (0 selects the dummy)

} // namespace ChromaSDK
