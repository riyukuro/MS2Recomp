// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\soundservice.cpp
// MS2-RANGE: 0x1401017f0-0x140101890 .text$di
// MS2-RANGE: 0x1417ae520-0x1417b73c0 .text$mn
// MS2-PIN: ??_7CSoundService@@6B?$TSingleton@VCSoundService@@@@@ 0x142f6b990
// MS2-PIN: ??_7CSoundService@@6BISystemService@efd@@@ 0x142f6b9a0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@std@@@std@@@0@AEAV10@@Z 0x1417b3cd0 ; unique
// MS2-PIN: ??0?$allocator@PEAVSound@FMOD@@@std@@QEAA@XZ 0x1417b4100 ; unique
// MS2-PIN: ??0?$allocator@U?$_List_node@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEAX@std@@@std@@QEAA@XZ 0x1417b4110 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@PEAX@std@@@std@@QEAA@XZ 0x1417b4120 ; unique
// MS2-PIN: ?TypeCast@CSoundService@@UEBA_NIPEAPEAX@Z 0x1417b50b0 ; order
// MS2-PIN: ?TypeCast@CSoundService@@UEBA_NIPEAPEBX@Z 0x1417b5100 ; order
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@XZ 0x1417b5e80 ; unique
// MS2-PINS-END tplpin
// CSoundService: the FMOD Ex system service (see soundservice.h). The container glue of the exe (vector<Sound*>,
// map<CStringA, Unk_SoundTag>, list<CStringW> and the allocator helpers) comes from the real STL here.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\soundservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <efd/ServiceManager.h>
#include "soundservice.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- globals ----
extern int DAT_1439f86ac;                                           // nonzero: net streams are enabled
extern char DAT_143d6eb58;                                          // class descriptor handed to the lookup FUN_14098d8d0

// ---- helpers living in other units ----
CLogString* GetLogString();                                        // the log
void FUN_1403a1280(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const char* const& rArg);
void FUN_1401859c0(CLogString* pLog, int nLevel, int nCategory, const wchar_t* szFormat);
int FUN_1406516c0();                                                // client language (0 Korea, 1 jp, 2 en, 3 cn)
struct Unk_SoundCfg
{
    char m_pad_00[0x78];
    CStringA m_strTarget;                                           // +0x78
    CStringA m_strSource;                                           // +0x80
};
Unk_SoundCfg* FUN_1401d31f0();                                      // client configuration singleton
CSoundService* FUN_140c9cb10();                                     // the sound service
void* FUN_140d13c40();                                              // the channel volume manager
void* FUN_140d13c70(void* p);
void* FUN_1409a8b10();
void* FUN_14025e7a0();
void* FUN_1422b0230(void* p);
void* FUN_140aadf80();
void* FUN_14209c720(void* p);
void FUN_1422ec700(void* p, void* q);
void FUN_14177dbe0(void* pMgr, int nChannel, unsigned char bVolume);
void FUN_14177dc80(void* pMgr, int nValue);
void FUN_14177af40(void* pMgr, FMOD::EventSystem* pEvents, FMOD::System* pSystem);
void FUN_14177bf20(void* pMgr);
void FUN_14125fe20(void* p);
void FUN_1422afe50(void* p);
void FUN_1422afe90(void* p);
void FUN_14177bda0(void* pMgr);
void* FUN_1403ed280();                                              // the effect manager
void FUN_1411a6160(void* pMgr);
void FUN_14177ba30(void* pMgr);
void FUN_14177bb70(void* pMgr, float fDelta);
void* FUN_1411b1de0();
void FUN_141793450(void* p);
void* FUN_14086d260();                                              // the time source
float FUN_141473230(void* pTime);   // frame delta (s), cvtsd2ss xmm0
double FUN_141473260(void* pTime);
void* FUN_140994450();
void* FUN_14098d8d0(const char* pClass, void* p);
void FUN_1411d7c70(void* pObj, bool (*pfn)(char, void*), CSoundService* pOwner);
void FUN_1411d7c10(void* pObj, bool (*pfn)(void*), CSoundService* pOwner);
void FUN_1414fe370(void* pObj, bool (*pfn)(char, void*));
void FUN_1414fe240(void* pObj, bool (*pfn)(void*));
class WorldService;
WorldService* FUN_1403ed2d0();
void FUN_141bdac80(WorldService* pWorld, CStringA strMessage);
CStringA FUN_14016a600(const wchar_t* pszText, int nCodePage);
void FUN_1412751b0(const CStringW& rText, int nSeconds);
void FUN_141b6fc50(const CStringA& rText, const CStringA& rCaption, int nFlags);
CStringA FUN_14038f6d0(const CStringA& rDir, const char* pszName);
void FUN_140399620(CStringA strPattern, CStringA strDirectory, ATL::CAtlArray<CStringA>& rOut, CStringA strExclude, int nFlags);
void FUN_140165270(ATL::CAtlArray<CStringA>& rArray, const CStringA& rItem);
void FUN_140166420();
void* FUN_1409478c0();                                              // the camera manager
int FUN_140a18070(void* pCameras);
class Unk_AudioCam
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual void GetPosition(Unk_StreamPoint* pOut);                // slot 18
};
Unk_AudioCam* FUN_140a38d60(void* pCameras);
// the camera manager's vectors return by value (member: this, hidden return pointer; exe 0x1417b0b1d / 0x1417b0b47)
class Unk_SndCameras { public: Unk_StreamPoint FUN_140af0340(); Unk_StreamPoint FUN_140af0250(); };

// the open-state strings of the voice streams: a vector<CStringA> of another unit, opaque here
struct Unk_StrVec { void* m_p0; void* m_p1; void* m_p2; };
Unk_StrVec* FUN_14027d6f0(Unk_StrVec* p);
void FUN_14027e450(Unk_StrVec* p);
void FUN_1403b0310(Unk_StrVec* p, const CStringA& rItem);
size_t FUN_14028b4c0(Unk_StrVec* p);
CStringA& FUN_14027f1c0(Unk_StrVec* p, size_t nIndex);

// ---- the log with two arguments (in this unit) ----
// @0x1417b1780
template<class T, class U> inline void Unk_SndLog2(CLogString* log, int level, int category, const wchar_t* format,
                                                  const T& first, const U& second) {
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// 0x20 byte load info of the event project (the exe's FMOD_EVENT_LOADINFO prefix)
struct Unk_EventLoadInfo
{
    Unk_EventLoadInfo();                                            // 0x1417b4210
    unsigned m_uSize;
    unsigned m_uPad;
    char* m_pKey;
    unsigned m_u10;
    unsigned m_u14;
    unsigned m_u18;
    unsigned m_u1c;
};
MS2_CHECK_SIZE(Unk_EventLoadInfo, 0x20);

// ---- unit statics ----
static int s_nReload;                                               // 0x143aea320: 0 idle, 1 device lost, 2 rebuild
static int s_nDeviceFlag;                                           // 0x143aea324

// ---- static initializers (.text$di, in this order) ----
// @0x1401017f0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSoundService);
#ifndef MS2_HOOK_DLL
// @0x140101810
static CString s_strSkill = "skill";
// @0x140101840
static CString s_strStun = "stun";
// @0x140101870
class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static Unk_1401cd100 s_pointer(NULL);
#endif

// @0x1417b3d20
inline TSingleton<CSoundService>::TSingleton() { s_instance = static_cast<CSoundService*>(this); }

// @0x1417b4210
Unk_EventLoadInfo::Unk_EventLoadInfo()
{
    m_uSize = 0;
    m_pKey = 0;
    m_u10 = 0;
    m_u14 = 0;
    m_u18 = 0;
    m_u1c = 0;
}

// @0x1417b4270
Unk_SoundTag::Unk_SoundTag() : m_nSubSound(0), m_uLength(0), m_nBank(0) {}

void FUN_1417b4a40(int nState);
#ifndef MS2_HOOK_DLL
// @0x1417b4a40
void FUN_1417b4a40(int nState)
{
    s_nReload = nState;
}
#endif

// @0x1417b4af0
FMOD_RESULT FUN_1417b4af0(FMOD::EventSystem** ppSystem)
{
    return FMOD_EventSystem_Create((FMOD_EVENTSYSTEM**)ppSystem);
}

// FMOD_RESULT to text (the SDK's FMOD_ErrorString)
// @0x1417b0e10
const char* FUN_1417b0e10(FMOD_RESULT nResult)
{
    const char* pszText;
    switch ((int)nResult)
    {
#include "soundservice_errors.inc"
    }
    return pszText;
}

// false (and a log line) when the FMOD call failed
// @0x1417b1430
bool FUN_1417b1430(FMOD_RESULT nResult)
{
    if (nResult == FMOD_OK)
        return true;
    if (GetLogString() != 0)
    {
        const char* pszText = FUN_1417b0e10(nResult);
        Unk_SndLog2(GetLogString(), 1, 0x12f, L"FMOD error! ({0}) {1}", nResult, pszText);
    }
    return false;
}

// FMOD_SYSTEM_CALLBACK_DEVICELISTCHANGED: remember that the device list changed
// @0x1417b14a0
FMOD_RESULT F_CALLBACK FUN_1417b14a0(FMOD_SYSTEM* pSystem, FMOD_SYSTEM_CALLBACKTYPE nType, void* pData1, void* pData2)
{
    if (nType == FMOD_SYSTEM_CALLBACKTYPE_DEVICELISTCHANGED)
    {
        int nDrivers = 0;
        FMOD_System_GetNumDrivers(pSystem, &nDrivers);
        if (nDrivers != 0)
            FUN_1417b4a40(1);
        if (GetLogString() != 0)
            FUN_1401859c0(GetLogString(), 0xc, 0x12f, L"FMOD_SYSTEM_CALLBACKTYPE_DEVICELISTCHANGED");
    }
    return FMOD_OK;
}

// @0x1417b1750
void FUN_1417b1750(efd::IDependencyRegistrar* pRegistrar, unsigned uFlags)
{
    pRegistrar->AddDependency(0x6100002, uFlags);
}

// the last message of the list (the exe's own *--end() helpers)
typedef std::list<CStringW>::iterator Unk_ListIt;
// @0x1417b4180
void** FUN_1417b4180(void** pThis, void* pNode)
{
    *pThis = pNode;
    return pThis;
}
// @0x1417b71d0
Unk_ListIt* FUN_1417b71d0(std::list<CStringW>* pList, Unk_ListIt* pOut)
{
    Unk_ListIt kEnd = pList->end();
    FUN_1417b4180((void**)pOut, *(void**)&kEnd);
    return pOut;
}
// @0x1417b4640
CStringW* FUN_1417b4640(Unk_ListIt* pIt)
{
    Unk_ListIt kPrev = *pIt;
    return &*--kPrev;
}

// strstr of the CRT
// @0x1417b7270
const char* FUN_1417b7270(const char* pszText, const char* pszFind)
{
    return strstr(pszText, pszFind);
}

// ---- CSoundService ----
// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1417ae520
CSoundService::CSoundService()
{
    m_pSystem = 0;
    m_pEventSystem = 0;
    m_bLoaded = false;
    m_fVolume = 1.0f;
    m_vecBanks.clear();
    m_mapTags.clear();
    m_pNetStream = 0;
    m_pNetSound = 0;
    m_fMessageTimer = 0;
}
#endif

// @0x1417ae650
CSoundService::~CSoundService()
{
}

// @0x1417ae6e0
const char* CSoundService::GetDisplayName() const
{
    return "SoundService";
}

// @0x1417ae700
FMOD::System* CSoundService::GetSystem()
{
    return m_pSystem;
}

// @0x1417ae720
FMOD::EventSystem* CSoundService::GetEventSystem()
{
    return m_pEventSystem;
}

// @0x1417ae740
FMOD::Sound* CSoundService::GetNetSound()
{
    return m_pNetSound;
}

// @0x1417b4b20
float CSoundService::GetVolume()
{
    return m_fVolume;
}

// @0x1417ae760
void CSoundService::FUN_1417ae760(float fVolume)
{
    m_fVolume = fVolume;
    if (DAT_1439f86ac != 0 && m_pSystem != 0 && m_pNetStream != 0)
        m_pNetStream->FUN_1417b4f40(fVolume);
}

// Log a failed FMOD call (nothing for FMOD_OK).
// @0x1417ae7c0
void FUN_1417ae7c0(FMOD_RESULT nResult)
{
    if (nResult != FMOD_OK)
    {
        CStringA strText(FUN_1417b0e10(nResult));
        const char* pszText = FUN_1417b0e10(nResult);
        FUN_1403a1280(GetLogString(), 1, 0x13, L"{0}", pszText);
    }
}

// Set the volume of the ui/effect channels (nFlag 0) or one channel (nFlag != 0).
// @0x1417ae840
void CSoundService::FUN_1417ae840(int nFlag)
{
    if (nFlag == 0)
    {
        unsigned char bVolume = *(unsigned char*)FUN_140d13c70(FUN_1409a8b10());
        FUN_14177dbe0(FUN_140d13c40(), 0, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 9, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 1, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 2, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 3, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 4, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 7, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 5, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 8, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 6, bVolume);
        FUN_14177dbe0(FUN_140d13c40(), 10, bVolume);
    }
    else
    {
        FUN_14177dc80(FUN_140d13c40(), 1);
    }
}

// @0x1417ae990
bool CSoundService::FUN_1417ae990()
{
    if (FUN_14025e7a0() != 0)
    {
        if (FUN_1422b0230(FUN_14025e7a0()) != 0)
        {
            void* pValue = FUN_14209c720(FUN_140aadf80());
            FUN_1422ec700(FUN_1422b0230(FUN_14025e7a0()), pValue);
        }
    }
    if (GetSystem() != 0)
        GetSystem()->setCallback(FUN_1417b14a0);
    int nOk = FUN_1417aea70();
    if (nOk != 0)
    {
        FMOD::System* pSystem = GetSystem();
        FMOD::EventSystem* pEvents = GetEventSystem();
        FUN_14177af40(FUN_140d13c40(), pEvents, pSystem);
    }
    return nOk != 0;
}

// @0x1417aea70
int CSoundService::FUN_1417aea70()
{
    if (FUN_1417aec60() == 0)
        return 0;
    const char* pszLanguage;
    int nLanguage = FUN_1406516c0();
    if (nLanguage == 1)
        pszLanguage = "jp";
    else if (nLanguage == 2)
        pszLanguage = "en";
    else if (nLanguage == 3)
        pszLanguage = "cn";
    else
        pszLanguage = "Korea";
    return FUN_1417aee20(FUN_1401d31f0()->m_strTarget, pszLanguage);
}

// @0x1417aeb40
int CSoundService::FUN_1417aeb40()
{
    if (FUN_1417b4af0(&m_pEventSystem) != FMOD_OK)
        return 0;
    FMOD_RESULT nResult = m_pEventSystem->getSystemObject(&m_pSystem);
    if (nResult != FMOD_OK)
    {
        m_pEventSystem->release();
        m_pEventSystem = 0;
        return 0;
    }
    unsigned uVersion;
    nResult = m_pSystem->getVersion(&uVersion);
    if (nResult != FMOD_OK)
    {
        m_pSystem->release();
        m_pSystem = 0;
        m_pEventSystem->release();
        m_pEventSystem = 0;
        return 0;
    }
    if (uVersion < FMOD_VERSION)
    {
        m_pSystem->release();
        m_pSystem = 0;
        m_pEventSystem->release();
        m_pEventSystem = 0;
        return 0;
    }
    return 1;
}

// @0x1417aec60
int CSoundService::FUN_1417aec60()
{
    FMOD_SPEAKERMODE nSpeakerMode = FMOD_SPEAKERMODE_RAW;
    unsigned uCaps = 0;
    char szDriver[0x100];
    memset(&nSpeakerMode, 0, 4);
    memset(&uCaps, 0, 4);
    if (m_pSystem != 0)
    {
        FMOD_RESULT nResult = m_pSystem->getDriverCaps(0, &uCaps, 0, &nSpeakerMode);
        if (nResult == FMOD_OK)
        {
            if (m_pSystem->setSpeakerMode(nSpeakerMode) != FMOD_OK)
                return 0;
        }
        else
        {
            if (m_pSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO) != FMOD_OK)
                return 0;
        }
        if ((uCaps & FMOD_CAPS_HARDWARE_EMULATED) != 0 && m_pSystem->setDSPBufferSize(0x400, 10) != FMOD_OK)
            return 0;
        nResult = m_pSystem->getDriverInfo(0, szDriver, 0x100, 0);
        if (nResult == FMOD_OK && FUN_1417b7270(szDriver, "SigmaTel") != 0 &&
            m_pSystem->setSoftwareFormat(48000, FMOD_SOUND_FORMAT_PCMFLOAT, 0, 0, FMOD_DSP_RESAMPLER_LINEAR) != FMOD_OK)
            return 0;
    }
    return 1;
}

// @0x1417aee20
int CSoundService::FUN_1417aee20(CStringA strMediaPath, const char* szLanguage)
{
    if (!m_bLoaded && m_pSystem != 0 && m_pEventSystem != 0)
    {
        FMOD_RESULT nResult = m_pSystem->set3DSettings(1.0f, 1.0f, 1.0f);
        if (nResult != FMOD_OK)
            return 0;
        nResult = m_pEventSystem->init(100, 0, 0, 0);
        if (nResult != FMOD_OK)
        {
            if (nResult == FMOD_ERR_OUTPUT_CREATEBUFFER)
            {
                nResult = m_pSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
                if (nResult != FMOD_OK)
                    return 0;
                nResult = m_pEventSystem->init(100, 0, 0, 0);
                if (nResult != FMOD_OK)
                    return 0;
            }
            else
            {
                m_pSystem->setOutput(FMOD_OUTPUTTYPE_NOSOUND);
                nResult = m_pEventSystem->init(100, 2, 0, 0);
                if (nResult != FMOD_OK)
                    return 0;
            }
        }
        const char* pszPath = strMediaPath;
        nResult = m_pEventSystem->setMediaPath(pszPath);
        if (nResult == FMOD_OK)
        {
            nResult = m_pEventSystem->setLanguage(szLanguage);
            if (nResult == FMOD_OK)
            {
                Unk_EventLoadInfo kInfo;
                memset(&kInfo, 0, 0x20);
                kInfo.m_uSize = 0x20;
                kInfo.m_pKey = 0;
                nResult = m_pEventSystem->load("MS2Sound.fev", (FMOD_EVENT_LOADINFO*)&kInfo, 0);
                if (nResult == FMOD_OK)
                {
                    m_bLoaded = true;
                    FUN_1417aff20(strMediaPath);
                    if (DAT_1439f86ac != 0)
                    {
                        nResult = m_pSystem->setStreamBufferSize(0x80000, FMOD_TIMEUNIT_RAWBYTES);
                        if (FUN_1417b1430(nResult) == 0)
                            DAT_1439f86ac = 0;
                    }
                    return 1;
                }
                const char* pszError = FUN_1417b0e10(nResult);
                FUN_141b6fc50(CStringA(pszError), CStringA("FMOD Error"), 0);
                return 0;
            }
            const char* pszError = FUN_1417b0e10(nResult);
            FUN_141b6fc50(CStringA(pszError), CStringA("FMOD Error"), 0);
            return 0;
        }
        const char* pszError = FUN_1417b0e10(nResult);
        FUN_141b6fc50(CStringA(pszError), CStringA("FMOD Error"), 0);
        return 0;
    }
    return 1;
}

// Drop the net stream, the banks and the FMOD objects.
// @0x1417af340
void CSoundService::FUN_1417af340()
{
    if (m_pNetStream != 0)
    {
        m_pNetStream->FUN_1417b5000(this);
        delete m_pNetStream;
        m_pNetStream = 0;
    }
    if (m_pNetSound != 0)
    {
        m_pNetSound->release();
        m_pNetSound = 0;
    }
    if (m_pEventSystem != 0)
        m_pEventSystem->unload();
    for (size_t i = 0; i < m_vecBanks.size(); i++)
    {
        if (m_vecBanks[i] != 0)
            m_vecBanks[i]->release();
    }
    m_vecBanks.clear();
    if (m_pEventSystem != 0)
    {
        m_pEventSystem->release();
        m_pEventSystem = 0;
    }
    if (m_pSystem != 0)
    {
        m_pSystem->close();
        m_pSystem->release();
        m_pSystem = 0;
    }
    m_bLoaded = false;
}

// @0x1417af4f0
void CSoundService::FUN_1417af4f0(CStringA strUrl)
{
    FUN_1417af600();
    if (DAT_1439f86ac != 0 && m_bLoaded)
    {
        if (!strUrl.IsEmpty())
        {
            const char* pszUrl = strUrl;
            FMOD_RESULT nResult = m_pSystem->createSound(pszUrl, 0x100a8, 0, &m_pNetSound);
            if (FUN_1417b1430(nResult) != 0)
                m_pNetStream = new CNetStreamSound;
        }
    }
}

// @0x1417af600
void CSoundService::FUN_1417af600()
{
    if (DAT_1439f86ac != 0 && m_bLoaded)
    {
        if (m_pNetStream != 0)
        {
            m_pNetStream->FUN_1417b5000(this);
            delete m_pNetStream;
            m_pNetStream = 0;
        }
        if (m_pNetSound != 0)
        {
            m_pNetSound->release();
            m_pNetSound = 0;
        }
        m_listMessages.clear();
    }
}

// Release everything of the service (the singleton may be absent).
// @0x1417af6e0
void FUN_1417af6e0()
{
    if (FUN_140d13c40() != 0)
        FUN_14177bda0(FUN_140d13c40());
    if (FUN_1403ed280() != 0)
        FUN_1411a6160(FUN_1403ed280());
    if (FUN_140c9cb10() != 0)
        FUN_140c9cb10()->FUN_1417af340();
}

bool FUN_1417af740(char bFlag, void* pData);
#ifndef MS2_HOOK_DLL
// @0x1417af740
bool FUN_1417af740(char bFlag, void* pData)
{
    if (pData != 0 && bFlag == 0)
        s_nDeviceFlag = 0;
    return true;
}
#endif

bool FUN_1417af780(void* pData);
#ifndef MS2_HOOK_DLL
// @0x1417af780
bool FUN_1417af780(void* pData)
{
    s_nDeviceFlag = 1;
    return true;
}
#endif

// Copy the sound resources of the source folder over the target folder and reload (a debug command).
// @0x1417af7a0
int FUN_1417af7a0()
{
    FUN_1417af6e0();
    ATL::CAtlArray<CStringA> aSource;
    ATL::CAtlArray<CStringA> aTarget;
    FUN_140166420();
    FUN_140399620(CStringA("*.*"), CStringA(FUN_1401d31f0()->m_strSource), aSource, CStringA(""), 0);
    for (unsigned i = 0; i < aSource.GetCount(); i++)
    {
        CStringA strFile(aSource[i]);
        const char* pszTo = FUN_1401d31f0()->m_strTarget;
        const char* pszFrom = FUN_1401d31f0()->m_strSource;
        strFile.Replace(pszFrom, pszTo);
        aTarget.Add(strFile);
    }
    for (unsigned i = 0; i < aSource.GetCount(); i++)
    {
        const char* pszTarget = aTarget[i];
        if (CopyFileA(aSource[i], pszTarget, 0) == 0)
        {
            CStringA strMessage;
            strMessage.Format("Fail copy : %s", (const char*)aSource[i]);
            MessageBoxA(0, strMessage, "ReloadSoundResource", 0);
            return 0;
        }
    }
    FUN_1417b4a40(1);
    return 1;
}

// @0x1417afad0
void CSoundService::FUN_1417afad0(CStringW strMessage)
{
    m_listMessages.push_back(strMessage);
}

// @0x1417afb20
void FUN_1417afb20()
{
    FUN_1417af6e0();
    FUN_1417b4a40(1);
}

// Fill the tag table with the sub sounds of the opened voice banks.
// @0x1417afb50
void CSoundService::FUN_1417afb50()
{
    if (m_vecBanks.size() != 0)
    {
        m_mapTags.clear();
        for (size_t nBank = 0; nBank < m_vecBanks.size(); nBank++)
        {
            FMOD::Sound* pBank = m_vecBanks[nBank];
            if (pBank != 0)
            {
                FMOD_OPENSTATE nState;
                do
                {
                    pBank->getOpenState(&nState, 0, 0, 0);
                } while (nState != FMOD_OPENSTATE_READY);
                int nSubSounds;
                FMOD_RESULT nResult = pBank->getNumSubSounds(&nSubSounds);
                if (FUN_1417b1430(nResult) == 0)
                    return;
                CStringA strPrefix("");
                int nLanguage = FUN_1406516c0();
                if (nLanguage == 1)
                {
                    strPrefix = "jp_";
                    return;
                }
                if (nLanguage == 2)
                    strPrefix = "en_";
                else if (nLanguage == 3)
                    strPrefix = "cn_";
                for (int nSub = 0; nSub < nSubSounds; nSub++)
                {
                    FMOD::Sound* pSub = 0;
                    char szName[0x104] = {0};
                    pBank->getSubSound(nSub, &pSub);
                    do
                    {
                        pBank->getOpenState(&nState, 0, 0, 0);
                    } while (nState != FMOD_OPENSTATE_READY);
                    nResult = pSub->getName(szName, 0x104);
                    if (FUN_1417b1430(nResult) == 0)
                    {
                        m_mapTags.clear();
                        return;
                    }
                    unsigned uLength;
                    nResult = pSub->getLength(&uLength, FMOD_TIMEUNIT_MS);
                    if (FUN_1417b1430(nResult) == 0)
                    {
                        m_mapTags.clear();
                        return;
                    }
                    Unk_SoundTag kTag;
                    kTag.m_nSubSound = nSub;
                    kTag.m_uLength = uLength;
                    kTag.m_nBank = nBank;
                    CStringA strKey(szName);
                    if (!strPrefix.IsEmpty())
                    {
                        if (strKey.Find(strPrefix, 0) == 0)
                            strKey = strKey.Mid(strPrefix.GetLength());
                    }
                    m_mapTags[strKey] = kTag;
                }
            }
        }
    }
}

// Open the voice streams of the client language.
// @0x1417aff20
void CSoundService::FUN_1417aff20(CStringA strMediaPath)
{
    CStringA strDir(strMediaPath);
    Unk_StrVec aFiles;
    FUN_14027d6f0(&aFiles);
    CStringA strFile("");
    int nLanguage = FUN_1406516c0();
    if (nLanguage == 0)
    {
        strFile = FUN_14038f6d0(strDir, "MS2Sound_Voice8_Kor_def.fsb");
        FUN_1403b0310(&aFiles, strFile);
        strFile = FUN_14038f6d0(strDir, "MS2Sound_Voice9_Kor_def.fsb");
        FUN_1403b0310(&aFiles, strFile);
    }
    else
    {
        if (nLanguage == 1)
        {
            FUN_14027e450(&aFiles);
            return;
        }
        if (nLanguage == 2)
        {
            strFile = FUN_14038f6d0(strDir, "MS2Sound_Voice8_en.fsb");
            FUN_1403b0310(&aFiles, strFile);
            strFile = FUN_14038f6d0(strDir, "MS2Sound_Voice9_en.fsb");
            FUN_1403b0310(&aFiles, strFile);
        }
        else
        {
            if (nLanguage != 3)
            {
                FUN_14027e450(&aFiles);
                return;
            }
            strFile = FUN_14038f6d0(strDir, "MS2Sound_Voice8_cn.fsb");
            FUN_1403b0310(&aFiles, strFile);
            strFile = FUN_14038f6d0(strDir, "MS2Sound_Voice9_cn.fsb");
            FUN_1403b0310(&aFiles, strFile);
        }
    }
    for (size_t i = 0; i < FUN_14028b4c0(&aFiles); i++)
    {
        FMOD::Sound* pSound = 0;
        HANDLE hFile = CreateFileA(FUN_14027f1c0(&aFiles, i), GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            CloseHandle(hFile);
            FMOD_RESULT nResult = m_pSystem->createStream(FUN_14027f1c0(&aFiles, i), 0x10048, 0, &pSound);
            if (nResult == FMOD_OK)
            {
                FUN_1417b1430(nResult);
                m_vecBanks.push_back(pSound);
            }
        }
    }
    FUN_14027e450(&aFiles);
}

// @0x1417b03d0
bool CSoundService::FUN_1417b03d0(const CStringA& strName)
{
    std::map<CStringA, Unk_SoundTag>::iterator it = m_mapTags.find(strName);
    if (it == m_mapTags.end())
        return false;
    return true;
}

// @0x1417b0440
int CSoundService::FUN_1417b0440(const CStringA& strName, size_t* pBank)
{
    std::map<CStringA, Unk_SoundTag>::iterator it = m_mapTags.find(strName);
    if (it == m_mapTags.end())
        return -1;
    *pBank = it->second.m_nBank;
    return it->second.m_nSubSound;
}

// @0x1417b04d0
int CSoundService::FUN_1417b04d0(const CStringA& strName, size_t* pBank)
{
    std::map<CStringA, Unk_SoundTag>::iterator it = m_mapTags.find(strName);
    if (it == m_mapTags.end())
        return -1;
    *pBank = it->second.m_nBank;
    return it->second.m_uLength;
}

// @0x1417b0560
void CSoundService::FUN_1417b0560(const CStringA& strName, FMOD::Sound** ppSound)
{
    size_t nBank = 0;
    int nSub = FUN_1417b0440(strName, &nBank);
    if (nSub == -1)
    {
        *ppSound = 0;
    }
    else if (nBank < m_vecBanks.size())
    {
        FMOD::Sound* pBank = m_vecBanks[nBank];
        if (pBank == 0)
        {
            *ppSound = 0;
        }
        else
        {
            FMOD_RESULT nResult = pBank->getSubSound(nSub, ppSound);
            if (FUN_1417b1430(nResult) == 0)
                *ppSound = 0;
        }
    }
    else
    {
        *ppSound = 0;
    }
}

// @0x1417b0650
efd::SyncResult CSoundService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    FUN_1417b1750(pRegistrar, 1);
    FUN_1417aeb40();
    FUN_1417ae990();
    FUN_1417afb50();
    return efd::SyncResult_Success;
}

// @0x1417b06b0
efd::AsyncResult CSoundService::OnInit()
{
    void* pObj = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (pObj != 0)
    {
        FUN_1411d7c70(pObj, FUN_1417af740, this);
        FUN_1411d7c10(pObj, FUN_1417af780, this);
    }
    return efd::AsyncResult_Complete;
}

// @0x1417b0730
efd::AsyncResult CSoundService::OnTick()
{
    FUN_141793450(FUN_1411b1de0());
    float fDelta = FUN_141473230(FUN_14086d260());
    if (s_nReload != 0)
    {
        if (s_nReload == 2)
        {
            FUN_1417aeb40();
            if (FUN_1417ae990() != 0)
            {
                FUN_14177bf20(FUN_140d13c40());
                FUN_14125fe20(FUN_140d13c70(FUN_1409a8b10()));
                FUN_1422afe50(FUN_14025e7a0());
            }
            s_nReload = 0;
        }
        else if (s_nReload == 1)
        {
            FUN_1422afe90(FUN_14025e7a0());
            FUN_1417af6e0();
            s_nReload = 2;
        }
    }
    if (DAT_1439f86ac != 0 && m_pNetStream != 0)
    {
        if (m_pNetStream->vfunc_1(this) == -1)
        {
            m_pNetStream->FUN_1417b5000(this);
            delete m_pNetStream;
            m_pNetStream = 0;
        }
        double dDelta = FUN_141473260(FUN_14086d260());
        m_fMessageTimer = m_fMessageTimer + (float)dDelta;
        if (1.0 < m_fMessageTimer)
        {
            m_fMessageTimer = 0;
            if (!m_listMessages.empty())
            {
                Unk_ListIt kEnd;
                CStringA strMessage = FUN_14016a600(*FUN_1417b4640(FUN_1417b71d0(&m_listMessages, &kEnd)), 0);
                FUN_141bdac80(FUN_1403ed2d0(), CStringA(strMessage));
            }
            for (std::list<CStringW>::iterator it = m_listMessages.begin(); it != m_listMessages.end(); ++it)
                FUN_1412751b0(*it, 0x14);
            m_listMessages.clear();
        }
    }
    if (FUN_140a18070(FUN_1409478c0()) != 0 && FUN_140a38d60(FUN_1409478c0()) != 0)
    {
        Unk_AudioCam* pCam = FUN_140a38d60(FUN_1409478c0());
        Unk_StreamPoint kPos;
        pCam->GetPosition(&kPos);
        Unk_StreamPoint kForward = static_cast<Unk_SndCameras*>(FUN_1409478c0())->FUN_140af0340();
        Unk_StreamPoint kUp = static_cast<Unk_SndCameras*>(FUN_1409478c0())->FUN_140af0250();
        if (GetEventSystem() != 0)
        {
            FMOD_VECTOR vPos = {kPos.x, kPos.z, kPos.y};
            FMOD_VECTOR vVel = {0, 0, 0};
            FMOD_VECTOR vUp = {kUp.x, kUp.z, kUp.y};
            FMOD_VECTOR vForward = {kForward.x, kForward.z, kForward.y};
            FMOD::EventSystem* pEvents = GetEventSystem();
            FMOD_RESULT nResult = pEvents->set3DListenerAttributes(0, &vPos, &vVel, &vUp, &vForward);
            FUN_1417ae7c0(nResult);
            pEvents = GetEventSystem();
            nResult = pEvents->update();
            FUN_1417ae7c0(nResult);
        }
        FUN_14177bb70(FUN_140d13c40(), fDelta);
    }
    else if (GetEventSystem() != 0)
    {
        FMOD::EventSystem* pEvents = GetEventSystem();
        FMOD_RESULT nResult = pEvents->update();
        FUN_1417ae7c0(nResult);
    }
    if (GetSystem() != 0)
    {
        FMOD::System* pSystem = GetSystem();
        pSystem->update();
    }
    return efd::AsyncResult_Pending;
}

// @0x1417b0d70
efd::AsyncResult CSoundService::OnShutdown()
{
    FUN_1417af600();
    void* pObj = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (pObj != 0)
    {
        FUN_1414fe370(pObj, FUN_1417af740);
        FUN_1414fe240(pObj, FUN_1417af780);
    }
    FUN_1411a6160(FUN_1403ed280());
    FUN_14177ba30(FUN_140d13c40());
    FUN_1417af340();
    return efd::AsyncResult_Complete;
}

// ---- CNetStreamSound ----
// @0x1417b41d0
CNetStreamSound::CNetStreamSound() : m_pChannel(0), m_uBuffered(0), m_nState(0)
{
}

// @0x1417b4410
CNetStreamSound::~CNetStreamSound()
{
}

// @0x1417b4b70
int CNetStreamSound::vfunc_1(CSoundService* pService)
{
    if (pService == 0)
        return -1;
    FMOD::System* pSystem = pService->GetSystem();
    FMOD::Sound* pSound = pService->GetNetSound();
    if (pSystem == 0 || pSound == 0)
        return -1;
    m_uBuffered = 0;
    unsigned uPosition = 0;
    unsigned uPercent = 0;
    bool bPlaying = false;
    bool bPaused = false;
    bool bStarving = false;
    FMOD_RESULT nResult;
    if (m_pChannel == 0 && (nResult = pSystem->playSound(FMOD_CHANNEL_FREE, pSound, false, &m_pChannel), m_pChannel != 0))
    {
        m_pChannel->setVolume(pService->GetVolume());
        m_nState = 1;
    }
    FMOD_TAG kTag;
    FMOD_RESULT nTag = pSound->getTag(0, -1, &kTag);
    if (nTag == FMOD_OK && kTag.datatype != FMOD_TAGDATATYPE_STRING && kTag.type == FMOD_TAGTYPE_FMOD)
    {
        if (strcmp(kTag.name, "Sample Rate Change") == 0)
            m_pChannel->setFrequency(*(float*)kTag.data);
    }
    FMOD_OPENSTATE nState;
    nResult = pSound->getOpenState(&nState, &uPercent, &bStarving, 0);
    FUN_1417b1430(nResult);
    if (m_pChannel != 0)
    {
        nResult = m_pChannel->getPaused(&bPaused);
        FUN_1417b1430(nResult);
        nResult = m_pChannel->isPlaying(&bPlaying);
        FUN_1417b1430(nResult);
        nResult = m_pChannel->getPosition(&uPosition, FMOD_TIMEUNIT_MS);
        FUN_1417b1430(nResult);
        nResult = m_pChannel->setMute(bStarving);
        FUN_1417b1430(nResult);
    }
    if (nState == FMOD_OPENSTATE_BUFFERING)
    {
        if (m_uBuffered != uPercent)
        {
            CStringW strMessage;
            strMessage.Format(L"Buffering... (%3d%%) ", uPercent);
            pService->FUN_1417afad0(CStringW(strMessage));
            m_uBuffered = uPercent;
        }
        m_nState = 2;
    }
    if (nState == FMOD_OPENSTATE_BUFFERING || nState == FMOD_OPENSTATE_CONNECTING || bPaused || bPlaying)
        return 0;
    CStringW strStopped;
    strStopped.Format(L"Stopped NetStream");
    pService->FUN_1417afad0(CStringW(strStopped));
    m_uBuffered = 0;
    m_nState = 3;
    return -1;
}

// @0x1417b4f40
void CNetStreamSound::FUN_1417b4f40(float fVolume)
{
    if (m_pChannel != 0)
        m_pChannel->setVolume(fVolume);
}

// @0x1417b5000
void CNetStreamSound::FUN_1417b5000(CSoundService* pService)
{
    if (m_pChannel != 0)
    {
        FMOD_RESULT nResult = m_pChannel->stop();
        FUN_1417b1430(nResult);
    }
    if (1 < m_nState)
    {
        while (true)
        {
            FMOD::Sound* pSound = pService->GetNetSound();
            FMOD_OPENSTATE nState;
            FMOD_RESULT nResult = pSound->getOpenState(&nState, 0, 0, 0);
            int nOk = FUN_1417b1430(nResult);
            if (nOk == 0 || nState == FMOD_OPENSTATE_READY)
                break;
            Sleep(10);
        }
    }
    m_nState = 1;
}

// ---- hooks ----
MS2_REPLACE_METHOD_VIA(0x1417AE6E0, CSoundService, efd::ISystemService, GetDisplayName, 13, 0x8CCE6CD6);
MS2_REPLACE_METHOD(0x1417AE700, CSoundService, GetSystem, 15, 0x9BD8F6D9);
MS2_REPLACE_METHOD(0x1417AE720, CSoundService, GetEventSystem, 15, 0xAC153A31);
MS2_REPLACE_METHOD(0x1417AE740, CSoundService, GetNetSound, 15, 0xAB75D671);
MS2_REPLACE_METHOD(0x1417AE760, CSoundService, FUN_1417ae760, 89, 0x76C22EF4);
MS2_REPLACE_METHOD(0x1417AE840, CSoundService, FUN_1417ae840, 318, 0x243083BB);
MS2_REPLACE_METHOD(0x1417AEA70, CSoundService, FUN_1417aea70, 192, 0x18644FC3);
MS2_REPLACE_METHOD(0x1417AEB40, CSoundService, FUN_1417aeb40, 281, 0x6A4BB7A2);
MS2_REPLACE_METHOD(0x1417AEC60, CSoundService, FUN_1417aec60, 442, 0xD849C694);
MS2_REPLACE_METHOD(0x1417AEE20, CSoundService, FUN_1417aee20, 1301, 0x7589DEB7);
MS2_REPLACE_METHOD(0x1417AF340, CSoundService, FUN_1417af340, 416, 0xC91B5A09);
MS2_REPLACE_METHOD(0x1417AF600, CSoundService, FUN_1417af600, 214, 0xA5FE5615);
MS2_REPLACE_METHOD(0x1417AFAD0, CSoundService, FUN_1417afad0, 64, 0x8FC7AFB4);
MS2_REPLACE_METHOD(0x1417AFB50, CSoundService, FUN_1417afb50, 964, 0x3C3484B2);
MS2_REPLACE_METHOD(0x1417AFF20, CSoundService, FUN_1417aff20, 1184, 0xAE11DED1);
MS2_REPLACE_METHOD(0x1417B03D0, CSoundService, FUN_1417b03d0, 94, 0xB5146B94);
MS2_REPLACE_METHOD(0x1417B0440, CSoundService, FUN_1417b0440, 135, 0x078AD050);
MS2_REPLACE_METHOD(0x1417B04D0, CSoundService, FUN_1417b04d0, 135, 0x0B935D37);
MS2_REPLACE_METHOD(0x1417B0560, CSoundService, FUN_1417b0560, 219, 0x360C5E76);
MS2_REPLACE_METHOD(0x1417B4B20, CSoundService, GetVolume, 16, 0x1BE201AE);
// ISystemService subobject is at +8 (TSingleton is the primary base): the exe override receives that pointer.
MS2_REPLACE_METHOD_VIA(0x1417B0650, CSoundService, efd::ISystemService, OnPreInit, 90, 0xF1E3BB61);
MS2_REPLACE_METHOD_VIA(0x1417B0D70, CSoundService, efd::ISystemService, OnShutdown, 146, 0xC52007DA);
MS2_REPLACE_METHOD(0x1417B4B70, CNetStreamSound, vfunc_1, 976, 0xF2F6A5E7);
MS2_REPLACE_METHOD(0x1417B4F40, CNetStreamSound, FUN_1417b4f40, 52, 0xC846719B);
MS2_REPLACE_METHOD(0x1417B5000, CNetStreamSound, FUN_1417b5000, 172, 0xD6E81C53);
MS2_REPLACE(0x1417AE7C0, FUN_1417ae7c0, 120, 0x18D2293F);
MS2_REPLACE(0x1417B0E10, FUN_1417b0e10, 1170, 0xA6EF09CD);
MS2_REPLACE(0x1417B1430, FUN_1417b1430, 104, 0xDDD2EC2D);
MS2_REPLACE(0x1417AF6E0, FUN_1417af6e0, 78, 0x813B7838);
MS2_REPLACE(0x1417B1750, FUN_1417b1750, 43, 0x80F9CB23);
MS2_REPLACE(0x1417B7270, FUN_1417b7270, 34, 0x1E249CF5);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6e80-0x142cb6ec0 .text$yd
