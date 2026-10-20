// unit_140a93d00.h - the Razer Chroma lighting classes of client\ms2\razerchroma (names from RTTI, namespace ChromaSDK;
// assert path e:\build\kr\22_04\ms2code\client\ms2\razerchroma\chromaeffectplaying.h). Recovered by w512; layouts
// cross-checked with the third-party v2525 snapshot. Member and method names are invented from use unless RTTI or an
// SDK name gives them; the sample helpers of ChromaManagerImpl follow the Razer ChromaSDKPlugin (UE4 plugin) code they
// were copied from (third_party/razer/CChromaEditor/CChromaEditorLibrary/ChromaSDKPlugin.cpp).
#pragma once
#include <vector>
#include <set>
#include <map>

#include "ms2/placeholder/ichromamanager.h"
// the sample helper types (FChromaSDKGuid, FChromaSDKEffectResult, FChromaSDKColors, the device enums): the Razer header
#include "../../../third_party/razer/CSDK_SampleApp/Razer/ChromaSDKPluginTypes.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/chromacolortable.h"

namespace ChromaSDK {

// ---- ChromaEffectBase (vftable 0x142dce890, 6 slots, slot 4 _purecall; 0x30 bytes) ----
class ChromaEffectBase
{
public:
    ChromaEffectBase();                                     // 0x140a93d00
    virtual ~ChromaEffectBase();                            //  0 0x140a93d50 (??_G 0x140a94310)
    virtual DWORD GetInterval();                            //  1 0x140a94360 (100 ms)
    virtual void OnEnter(int nPrevState);                   //  2 0x140a93e00
    virtual void Clear();                                   //  3 0x140a93e20 deletes every created effect
    virtual void Create() = 0;                              //  4
    virtual void Play();                                    //  5 0x140a93ee0 shows the next frame
    void Update();                                          // 0x140a93da0 Play() once the interval elapsed

    std::vector<RZEFFECTID> m_effects;                      // +0x08
    size_t m_nFrame;                                        // +0x20
    DWORD m_dwNextTick;                                     // +0x28
};
MS2_CHECK_SIZE(ChromaEffectBase, 0x30);

// ---- ChromaEffectCharacter (0x38): character select / creation ----
class ChromaEffectCharacter : public ChromaEffectBase
{
public:
    ChromaEffectCharacter();                                // 0x140a94850
    virtual ~ChromaEffectCharacter();                       // 0x140a948a0 (??_G 0x140a953e0)
    virtual DWORD GetInterval();                            // 0x140a95420
    virtual void Create();                                  // 0x140a948d0
    virtual void Play();                                    // 0x140a94b30
    void UpdateMouse();                                     // 0x140a94c00 (ChromaManagerImpl::ThreadProc)

    COLORREF m_color;                                       // +0x30
};
MS2_CHECK_SIZE(ChromaEffectCharacter, 0x38);

// ---- ChromaEffectCinematic (0x30) ----
class ChromaEffectCinematic : public ChromaEffectBase
{
public:
    ChromaEffectCinematic();                                // 0x140a95830
    virtual ~ChromaEffectCinematic();                       // 0x140a95870 (??_G 0x140a95a00)
    virtual DWORD GetInterval();                            // 0x140a95a40
    virtual void Create();                                  // 0x140a958a0
};
MS2_CHECK_SIZE(ChromaEffectCinematic, 0x30);

// ---- ChromaEffectDClear (0x38): dungeon clear ripple ----
class ChromaEffectDClear : public ChromaEffectBase
{
public:
    ChromaEffectDClear();                                   // 0x140a95a50
    virtual ~ChromaEffectDClear();                          // 0x140a95ab0 (??_G 0x140a95e30)
    virtual void OnEnter(int nPrevState);                   // 0x140a95ae0
    virtual void Create();                                  // 0x140a95b20
    virtual void Play();                                    // 0x140a95da0

    int m_nCenter;                                          // +0x30 row << 8 | column
    int m_nRepeat;                                          // +0x34
};
MS2_CHECK_SIZE(ChromaEffectDClear, 0x38);

// ---- ChromaEffectDeath (0x40) ----
class ChromaEffectDeath : public ChromaEffectBase
{
public:
    ChromaEffectDeath();                                    // 0x140a95e70
    virtual ~ChromaEffectDeath();                           // 0x140a95ed0 (??_G 0x140a962b0)
    virtual void OnEnter(int nPrevState);                   // 0x140a95f00
    virtual void Create();                                  // 0x140a95f40
    virtual void Play();                                    // 0x140a96210

    int m_nCenter;                                          // +0x30 row << 8 | column
    int m_n34;                                              // +0x34
    short m_n38;                                            // +0x38
};
MS2_CHECK_SIZE(ChromaEffectDeath, 0x40);

// ---- ChromaEffectLoading (0x38) ----
class ChromaEffectLoading : public ChromaEffectBase
{
public:
    ChromaEffectLoading();                                  // 0x140a962f0
    virtual ~ChromaEffectLoading();                         // 0x140a96330 (??_G 0x140a96980)
    virtual DWORD GetInterval();                            // 0x140a96710
    virtual void Create();                                  // 0x140a96360
    virtual void Play();                                    // 0x140a96680
    COLORREF GetPatternColor(int x, int y, COLORREF back, COLORREF fore);  // 0x140a96740

    int m_nPattern;                                         // +0x30
};
MS2_CHECK_SIZE(ChromaEffectLoading, 0x38);

// ---- ChromaEffectLogo (0x30) ----
class ChromaEffectLogo : public ChromaEffectBase
{
public:
    ChromaEffectLogo();                                     // 0x140a969e0
    virtual ~ChromaEffectLogo();                            // 0x140a96a20 (??_G 0x140a96c90)
    virtual DWORD GetInterval();                            // 0x140a96cd0
    virtual void Create();                                  // 0x140a96a50
    virtual void Play();                                    // 0x140a96c30
};
MS2_CHECK_SIZE(ChromaEffectLogo, 0x30);

// ---- ChromaEffectPlaying (0x1e0): the in-field key/hp/sp display ----
class ChromaEffectPlaying : public ChromaEffectBase
{
public:
    // skill cooldown timer, 8 bytes (ctor 0x140a98180); asserts at chromaeffectplaying.h lines 35 / 46
    class Cooldown
    {
    public:
        Cooldown() { Reset(); }                             // 0x140a98180
        void Reset() { m_dwDuration = 0; m_fStartTime = 0; }   // 0x140a985f0
        bool IsActive() { return m_dwDuration > 0.0f; }        // 0x140a98610
        bool IsExpired();                                   // 0x140a98650
        float GetProgress();                                // 0x140a986d0
        void Start(float fSecond);                          // 0x140a98750

        DWORD m_dwDuration;                                 // +0x0
        DWORD m_fStartTime;                                 // +0x4 (the assert text names it m_fStartTime)
    };

    enum { KEY_COUNT = 0x91, COOLDOWN_COUNT = 25 };

    ChromaEffectPlaying();                                  // 0x140a96ce0
    virtual ~ChromaEffectPlaying();                         // 0x140a96de0 (??_G 0x140a985a0)
    virtual DWORD GetInterval();                            // 0x140a985e0
    virtual void Create();                                  // 0x140a97300
    virtual void Play();                                    // 0x140a979f0

    void SetHp(unsigned nHp, unsigned nMaxHp);              // 0x140a96eb0
    void SetSp(unsigned nSp, unsigned nMaxSp);              // 0x140a96f60
    void StartCooldown(int nSlot, int a2, __int64 a3, float fTime);    // 0x140a96f90
    void ResetCooldown(int nSlot);                          // 0x140a97000
    void PressSkill(int nSkill);                            // 0x140a97050
    void PressKey(const CStringW& strName);                 // 0x140a970d0
    void ResetKeys();                                       // 0x140a97160
    COLORREF GetSkillColor(int nSkill);                     // 0x140a97190

    COLORREF m_keyColor;                                    // +0x30
    COLORREF m_blinkColor;                                  // +0x34
    COLORREF m_backColor;                                   // +0x38
    bool m_bFlash;                                          // +0x3c
    unsigned m_nHp;                                         // +0x40
    unsigned m_nMaxHp;                                      // +0x44
    unsigned m_nSp;                                         // +0x48
    unsigned m_nMaxSp;                                      // +0x4c
    bool m_bPressed[KEY_COUNT];                             // +0x50
    Cooldown m_cooldowns[COOLDOWN_COUNT];                   // +0xe4
    RZEFFECTID m_effectId;                                  // +0x1ac
    std::set<unsigned> m_set1c0;                            // +0x1c0 unused (0x20-byte nodes, allocate 0x140a99d50)
    std::map<unsigned, unsigned __int64> m_map1d0;          // +0x1d0 unused (0x30-byte nodes, allocate 0x140a99d20)
};
MS2_CHECK_OFFSET(ChromaEffectPlaying, m_bPressed, 0x50);
MS2_CHECK_OFFSET(ChromaEffectPlaying, m_cooldowns, 0xe4);
MS2_CHECK_OFFSET(ChromaEffectPlaying, m_effectId, 0x1ac);
MS2_CHECK_OFFSET(ChromaEffectPlaying, m_set1c0, 0x1c0);
MS2_CHECK_SIZE(ChromaEffectPlaying, 0x1e0);

// ---- ChromaEffectResurrection (0x38) ----
class ChromaEffectResurrection : public ChromaEffectBase
{
public:
    ChromaEffectResurrection();                             // 0x140a9a4b0
    virtual ~ChromaEffectResurrection();                    // 0x140a9a510 (??_G 0x140a9a890)
    virtual void OnEnter(int nPrevState);                   // 0x140a9a540
    virtual void Create();                                  // 0x140a9a580
    virtual void Play();                                    // 0x140a9a800

    int m_nCenter;                                          // +0x30 row << 8 | column
    short m_n34;                                            // +0x34
};
MS2_CHECK_SIZE(ChromaEffectResurrection, 0x38);

// ---- ChromaEffectRipple (0x40): field change ----
class ChromaEffectRipple : public ChromaEffectBase
{
public:
    ChromaEffectRipple();                                   // 0x140a9a8d0
    virtual ~ChromaEffectRipple();                          // 0x140a9a940 (??_G 0x140a9ada0)
    virtual void OnEnter(int nPrevState);                   // 0x140a9a970
    virtual void Create();                                  // 0x140a9a9c0
    virtual void Play();                                    // 0x140a9ad10
    void OnFieldChanged(unsigned short nFieldType);         // 0x140a9ac20
    void SetReturnState(int nState) { m_nReturnState = nState; }  // 0x140a9acf0

    int m_nReturnState;                                     // +0x30
    unsigned short m_nFieldType;                            // +0x34
    int m_nRepeat;                                          // +0x38
};
MS2_CHECK_SIZE(ChromaEffectRipple, 0x40);

// ---- ChromaEffectSurviveWinner (0x30) ----
class ChromaEffectSurviveWinner : public ChromaEffectBase
{
public:
    ChromaEffectSurviveWinner();                            // 0x140a9ade0
    virtual ~ChromaEffectSurviveWinner();                   // 0x140a9ae20 (??_G 0x140a9b040)
    virtual DWORD GetInterval();                            // 0x140a9b080
    virtual void OnEnter(int nPrevState);                   // 0x140a9ae50
    virtual void Create();                                  // 0x140a9ae90
    virtual void Play();                                    // 0x140a9af40
};
MS2_CHECK_SIZE(ChromaEffectSurviveWinner, 0x30);

// ---- ChromaEffectTalking (0x30) ----
class ChromaEffectTalking : public ChromaEffectBase
{
public:
    ChromaEffectTalking();                                  // 0x140a9b090
    virtual ~ChromaEffectTalking();                         // 0x140a9b0d0 (??_G 0x140a9b3d0)
    virtual DWORD GetInterval();                            // 0x140a9b410
    virtual void Create();                                  // 0x140a9b100
};
MS2_CHECK_SIZE(ChromaEffectTalking, 0x30);

// ---- ChromaLinkEffect (0x1c, not polymorphic): the ChromaLink (5 LED) effect of ChromaManagerImpl ----
class ChromaLinkEffect
{
public:
    enum { FLAG_LOW_HP = 2, FLAG_HIT = 4, FLAG_RAINBOW = 8 };

    ChromaLinkEffect();                                     // 0x140a9b420
    ~ChromaLinkEffect();                                    // 0x140a9b470
    void Update();                                          // 0x140a9b4a0
    void Delete();                                          // 0x140a9b550
    void AddFlag(unsigned nFlag);                           // 0x140a9b5d0
    void RemoveFlag(unsigned nFlag);                        // 0x140a9b660
    void Create();                                          // 0x140a9b690
    void CreateRainbow();                                   // 0x140a9b860
    DWORD GetInterval();                                    // 0x140a9b9e0

    RZEFFECTID m_effectId;                                  // +0x00
    unsigned m_nFlags;                                      // +0x10
    DWORD m_dwNextTick;                                     // +0x14
    unsigned m_nFrame;                                      // +0x18
};
MS2_CHECK_SIZE(ChromaLinkEffect, 0x1c);

// ---- ChromaManagerImpl (0x3a8): UIStatusEventListener +0 (vftable 0x142dcf918), IChromaManager +8 (0x142dcfa20) ----
class ChromaManagerImpl : public UIStatusEventListener, public IChromaManager
{
public:
    enum { KEY_SKILL_COUNT = 0x91 };

    typedef RZRESULT (*INIT)(void);
    typedef RZRESULT (*UNINIT)(void);
    typedef RZRESULT (*CREATEEFFECT)(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);
    typedef RZRESULT (*CREATEDEVICEEFFECT)(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);
    typedef RZRESULT (*SETEFFECT)(RZEFFECTID EffectId);
    typedef RZRESULT (*DELETEEFFECT)(RZEFFECTID EffectId);
    typedef RZRESULT (*QUERYDEVICE)(RZDEVICEID DeviceId, ChromaSDK::DEVICE_INFO_TYPE& DeviceInfo);

    ChromaManagerImpl();                                    // 0x140a9c740
    virtual ~ChromaManagerImpl();                           // 0x140a9b9f0 (??_G 0x140aa6c40)

    // UIStatusEventListener
    virtual void vfunc_oa0_3(int nHp, int nMaxHp);          // 0x140a9bc10
    virtual void vfunc_oa0_4(int nSp, int nMaxSp);          // 0x140a9bc70
    virtual void vfunc_oa0_9(unsigned short nFieldType);    // 0x140a9bcd0

    // IChromaManager
    virtual bool Initialize();                              // 0x140a9c8d0
    virtual void Finalize();                                // 0x140a9cee0
    virtual int GetKeyboardKey(int nKey);                   // 0x140a9bf30
    virtual void DeleteReservedEffects();                   // 0x140a9bfb0
    virtual void ReserveDeleteEffect(RZEFFECTID effectId);  // 0x140a9c070
    virtual void OnKeyName(const CStringW& strName);        // 0x140a9c140
    virtual void OnKeySkill(int nSkill, bool bKeep);        // 0x140a9c0b0
    virtual void ResetKeys(bool bForce);                    // 0x140a9c1a0
    virtual void RefreshKeys();                             // 0x140a9c210
    virtual void SetState(int nState);                      // 0x140a9ba90
    virtual int GetState() { return m_nState; }             // 0x140aa6d20
    virtual void Pause();                                   // 0x140a9bde0
    virtual void Resume();                                  // 0x140a9be00
    virtual void SetColorMode(int nMode);                   // 0x140a9c260
    virtual COLORREF GetColor(int nIndex);                  // 0x140a9c380
    virtual void SetCooldown(int nSlot, int a2, __int64 a3, float fTime);   // 0x140a9bd20
    virtual void ResetCooldown(int nSlot);                  // 0x140a9bd90
    virtual RZRESULT CreateEffect(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);  // 0x140a9c430
    virtual RZRESULT CreateChromaLinkEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);   // 0x140a9c4a0
    virtual RZRESULT CreateHeadsetEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);      // 0x140a9c4f0
    virtual RZRESULT CreateKeyboardEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);     // 0x140a9c540
    virtual RZRESULT CreateKeypadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);       // 0x140a9c590
    virtual RZRESULT CreateMouseEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);        // 0x140a9c5e0
    virtual RZRESULT CreateMousepadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId);     // 0x140a9c630
    virtual RZRESULT SetEffect(RZEFFECTID EffectId);        // 0x140a9c680
    virtual RZRESULT DeleteEffect(RZEFFECTID EffectId);     // 0x140a9c6e0
    virtual RZRESULT PlayEffect(RZEFFECTID EffectId);       // 0x140a9e9e0
    virtual RZRESULT RemoveEffect(RZEFFECTID EffectId);     // 0x140a9ea40

    void SetStateDirect(int nState);                        // 0x140a9bbe0
    int GetKeySkill(int nKey);                              // 0x140a9be40
    void RefreshKeySkills();                                // 0x140a9be80
    void AddLinkFlag(unsigned nFlag);                       // 0x140a9c320
    void RemoveLinkFlag(unsigned nFlag);                    // 0x140a9c350
    RZRESULT Init();                                        // 0x140a9c3b0
    RZRESULT UnInit();                                      // 0x140a9c3f0
    void SetModule(HMODULE hModule);                        // 0x140a9c890
    bool IsInitialized();                                   // 0x140a9c8b0
    int GetColorMode() { return m_nColorMode; }             // 0x140a969c0

    // the ChromaSDKPlugin sample helpers (no callers in the exe)
    int GetMaxLeds(const EChromaSDKDevice1DEnum& device);   // 0x140a9d090
    int GetMaxRow(const EChromaSDKDevice2DEnum& device);    // 0x140a9d0e0
    int GetMaxColumn(const EChromaSDKDevice2DEnum& device); // 0x140a9d130
    std::vector<COLORREF> CreateColors1D(const EChromaSDKDevice1DEnum& device);                // 0x140a9d180
    std::vector<FChromaSDKColors> CreateColors2D(const EChromaSDKDevice2DEnum& device);        // 0x140a9d230
    std::vector<COLORREF> CreateRandomColors1D(const EChromaSDKDevice1DEnum& device);          // 0x140a9d360
    std::vector<FChromaSDKColors> CreateRandomColors2D(const EChromaSDKDevice2DEnum& device);  // 0x140a9d480
    const std::vector<FChromaSDKColors>& SetMouseLEDColor(const EChromaSDKMouseLED& led, COLORREF color, std::vector<FChromaSDKColors>& colors);  // 0x140a9d640
    FChromaSDKEffectResult CreateEffect(RZDEVICEID deviceId, ChromaSDK::EFFECT_TYPE effect, const std::vector<FChromaSDKColors>& colors);  // 0x140a9d730
    FChromaSDKEffectResult CreateEffectNone1D(const EChromaSDKDevice1DEnum& device);          // 0x140a9d8e0
    FChromaSDKEffectResult CreateEffectNone2D(const EChromaSDKDevice2DEnum& device);          // 0x140a9da60
    FChromaSDKEffectResult CreateEffectStatic1D(const EChromaSDKDevice1DEnum& device, COLORREF color);   // 0x140a9dbe0
    FChromaSDKEffectResult CreateEffectStatic2D(const EChromaSDKDevice2DEnum& device, COLORREF color);   // 0x140a9ddd0
    FChromaSDKEffectResult CreateEffectCustom1D(const EChromaSDKDevice1DEnum& device, const std::vector<COLORREF>& colors);           // 0x140a9dfd0
    FChromaSDKEffectResult CreateEffectCustom2D(const EChromaSDKDevice2DEnum& device, const std::vector<FChromaSDKColors>& colors);   // 0x140a9e300
    FChromaSDKEffectResult CreateEffectKeyboardCustom2D(const std::vector<FChromaSDKColors>& colors);                                // 0x140a9e7f0

    static unsigned __stdcall ThreadProc(void* pParam);     // 0x140a9eaa0
    void Tick();                                            // 0x140a9eb40
    bool LoadSDK();                                         // 0x140a9ebb0
    void InitKeyMap();                                      // 0x140a9f080
    void UnloadSDK();                                       // 0x140aa0670

    bool m_bInitialized;                                    // +0x010
    HMODULE m_hModule;                                      // +0x018
    int m_nState;                                           // +0x020
    int m_nPrevState;                                       // +0x024
    INIT m_Init;                                            // +0x028
    UNINIT m_UnInit;                                        // +0x030
    CREATEEFFECT m_CreateEffect;                            // +0x038
    CREATEDEVICEEFFECT m_CreateChromaLinkEffect;            // +0x040
    CREATEDEVICEEFFECT m_CreateHeadsetEffect;               // +0x048
    CREATEDEVICEEFFECT m_CreateKeyboardEffect;              // +0x050
    CREATEDEVICEEFFECT m_CreateKeypadEffect;                // +0x058
    CREATEDEVICEEFFECT m_CreateMouseEffect;                 // +0x060
    CREATEDEVICEEFFECT m_CreateMousepadEffect;              // +0x068
    SETEFFECT m_SetEffect;                                  // +0x070
    DELETEEFFECT m_DeleteEffect;                            // +0x078
    QUERYDEVICE m_QueryDevice;                              // +0x080
    uintptr_t m_hThread;                                    // +0x088
    ChromaEffectBase* m_effects[STATE_COUNT];               // +0x090
    ChromaLinkEffect m_linkEffect;                          // +0x0f0
    std::vector<RZEFFECTID> m_reservedDeletes;              // +0x110
    int m_keySkills[KEY_SKILL_COUNT];                       // +0x128
    std::map<int, Keyboard::RZKEY> m_keyboardKeys;          // +0x370 DirectInput key -> key
    std::map<EChromaSDKMouseLED, Mouse::RZLED2> m_mouseLeds;   // +0x380
    bool m_bPaused;                                         // +0x390
    bool m_bKeyLock;                                        // +0x391
    ChromaColorTable* m_pColorTable;                        // +0x398
    int m_nColorMode;                                       // +0x3a0
};
MS2_CHECK_OFFSET(ChromaManagerImpl, m_effects, 0x90);
MS2_CHECK_OFFSET(ChromaManagerImpl, m_linkEffect, 0xf0);
MS2_CHECK_OFFSET(ChromaManagerImpl, m_reservedDeletes, 0x110);
MS2_CHECK_OFFSET(ChromaManagerImpl, m_keyboardKeys, 0x370);
MS2_CHECK_OFFSET(ChromaManagerImpl, m_bPaused, 0x390);
MS2_CHECK_SIZE(ChromaManagerImpl, 0x3a8);

// ---- ChromaManagerDummy (8 bytes, the default instance 0x143ab89f8): no-op service that creates the real one ----
class ChromaManagerDummy : public IChromaManager
{
public:
    ChromaManagerDummy();                                   // 0x140aaa6d0
    virtual ~ChromaManagerDummy();                          // 0x140aaa710 (??_G 0x140aaa8c0)
    virtual bool Initialize();                              // 0x140aaa740 loads RzChromaSDK64.dll and installs ChromaManagerImpl
    virtual void Finalize() {}                              // 0x140aaa8b0
    virtual int GetKeyboardKey(int nKey) { return -1; }     // 0x140aaaac0
    virtual void DeleteReservedEffects() {}                 // 0x140aaaa80
    virtual void ReserveDeleteEffect(RZEFFECTID effectId) {}        // 0x140aaab10
    virtual void OnKeyName(const CStringW& strName) {}      // 0x140aaa900
    virtual void OnKeySkill(int nSkill, bool bKeep) {}      // 0x140aaa910
    virtual void ResetKeys(bool bForce) {}                  // 0x140aaaa30
    virtual void RefreshKeys() {}                           // 0x140aaab00
    virtual void SetState(int nState) {}                    // 0x140aaa920
    virtual int GetState() { return -1; }                   // 0x140aaaab0
    virtual void Pause() {}                                 // 0x140aaaae0
    virtual void Resume() {}                                // 0x140aaab30
    virtual void SetColorMode(int nMode) {}                 // 0x140aaaaf0
    virtual COLORREF GetColor(int nIndex) { return 0; }     // 0x140aaaad0
    virtual void SetCooldown(int nSlot, int a2, __int64 a3, float fTime) {}    // 0x140aaaa50
    virtual void ResetCooldown(int nSlot) {}                // 0x140aaaa40
    virtual RZRESULT CreateEffect(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) { return -1; }  // 0x140aaa950
    virtual RZRESULT CreateChromaLinkEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) { return -1; }   // 0x140aaa930
    virtual RZRESULT CreateHeadsetEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) { return -1; }      // 0x140aaa970
    virtual RZRESULT CreateKeyboardEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) { return -1; }     // 0x140aaa990
    virtual RZRESULT CreateKeypadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) { return -1; }       // 0x140aaa9b0
    virtual RZRESULT CreateMouseEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) { return -1; }        // 0x140aaa9d0
    virtual RZRESULT CreateMousepadEffect(int Effect, PRZPARAM pParam, RZEFFECTID* pEffectId) { return -1; }     // 0x140aaa9f0
    virtual RZRESULT SetEffect(RZEFFECTID EffectId) { return -1; }          // 0x140aaaa20
    virtual RZRESULT DeleteEffect(RZEFFECTID EffectId) { return -1; }       // 0x140aaaa10
    virtual RZRESULT PlayEffect(RZEFFECTID EffectId) { return -1; }         // 0x140aaab20
    virtual RZRESULT RemoveEffect(RZEFFECTID EffectId) { return -1; }       // 0x140aaaa70
};
MS2_CHECK_SIZE(ChromaManagerDummy, 8);

} // namespace ChromaSDK
