// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSoundMusicEffectParam (effect XML type 3 "SoundMusic",
// 0x68) and its runtime effect CSoundMusicEffect (0x40): the param plays an FMOD music cue with an optional parameter,
// reverb string and volume; the effect records the music volume at the start and, on every update, fades the music
// volume from it towards param.volume over the effect's duration. Also holds this unit's log wrapper instantiation
// (Unk_SoundLog<int, CString>) and its unreferenced CRT memcpy_s copy.
// MS2-UNIT: ?\soundmusiceffectparam.cpp
// MS2-RANGE: 0x14178fd20-0x141790890 .text$mn
// MS2-PIN: ??_GCSoundMusicEffectParam@@UEAAPEAXI@Z 0x141790710
// MS2-PIN: ??_GCSoundMusicEffect@@UEAAPEAXI@Z 0x1417906b0
// MS2-PIN: ??1CEffectParam@@UEAA@XZ 0x140987960
// MS2-PIN: ??0?$SmartPointer@VCEffect@@@efd@@QEAA@PEAVCEffect@@@Z 0x1409878c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\soundmusiceffectparam.cpp"
// The exe's 16-byte fmt argument copies are plain rep movsb (no /Oi expansion); the pragma precedes the inline template.
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <new>
#include <string.h>
#include <efd/MemoryDefines.h>

#include "ms2/client/ms2/soundmusiceffectparam.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/fmodwrap.h"
#include "ms2/ms2recover.h"

// ---- callees outside this unit ----

// The log call (FMT_VARIADIC wrapper over CLogString::FUN_1406530d0): the exe emits one COMDAT per argument list, and
// this unit's copy is the (int, CString) one (0x141790380, 761 bytes).
template <class A, class B> inline void Unk_SoundLog(CLogString* log, int level, int category, const wchar_t* format,
                                                      const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b), args));
}

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp); they return 0 on success.
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);

CLogString* FUN_140166440();                                        // the logger
// The sound service (?\soundservice.cpp) and its FMOD event system.
class CSoundService { public: FMOD::EventSystem* GetEventSystem(); };
CSoundService* FUN_140c9cb10();
// The FMOD event manager (?\soundeventmgr.cpp): the music API.
class CSoundEventMgr
{
public:
    int FUN_14177c100(int nMusicId, float fParam, unsigned nPriority, int bForce);   // play a music cue
    int FUN_14177c420(int nParamId, float fValue, unsigned nPriority, int bForce);   // set a music parameter
    float FUN_14177c9e0();                                      // the music volume
    void FUN_14177ca30(float fVolume);                          // set the music volume
    int FUN_14177ddd0(void* pUnused, int nUnused1, int nUnused2);   // the reverb string attribute
};
CSoundEventMgr* FUN_140d13c40();
// The application object: the sound volume switch.
class Unk_SmApp { public: char* FUN_140d13c70(); };
Unk_SmApp* FUN_1409a8b10();
float FUN_141260110(void* pSwitch, int nChannel);                   // the volume of a channel
// The game clock (?\unit_14086d260.cpp).
class Unk_GameClock { public: double FUN_141473280(); };
Unk_GameClock* FUN_14086d260();

// The category allocator (efd::MemObject::operator new, expanded at the call site).
void* FUN_140876480(void* pkOut, int nCategory);            // returns the mem category
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);

// ---- CSoundMusicEffectParam ----

// @0x14178fd20
CSoundMusicEffectParam::CSoundMusicEffectParam()
    : CEffectParam(3), m_nCueID(-1), m_nPriority(0x80), m_nParamID(-1), m_fParamValue(0.0f), m_fVolume(-1.0f)
{
}

// @0x14178fdb0
void CSoundMusicEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408731e0(pNode, "cueID", m_nCueID);
    FUN_1408731e0(pNode, "paramID", m_nParamID);
    FUN_140873360(pNode, "paramValue", m_fParamValue);
    FUN_1408731e0(pNode, "priority", m_nPriority);
    FUN_140873360(pNode, "volume", m_fVolume);
    FUN_1408733e0(pNode, "reverb", m_strReverb);
}

// Loads the music cue of the param into the music system so that it can be prompted without a hitch. A cue that is
// missing is only logged (the effect still starts).
// @0x14178fe90
bool CSoundMusicEffectParam::vfunc_2()
{
    if (!CEffectParam::vfunc_2())
        return false;
    if (m_nCueID > 0)
    {
        FMOD::MusicSystem* pMusic;
        if (FUN_140c9cb10()->GetEventSystem()->getMusicSystem(&pMusic) == FMOD_OK)
        {
            FMOD::MusicPrompt* pPrompt;
            if (pMusic->prepareCue(m_nCueID, &pPrompt) != FMOD_OK)
            {
                Unk_SoundLog(FUN_140166440(), 1, 0x13, L"Music Cue을 찾을 수 없습니다[{0}] [{1}]", m_nCueID, m_str20);
                return false;
            }
        }
    }
    return true;
}

// @0x14178ff60
CEffectPtr CSoundMusicEffectParam::vfunc_6()
{
    int catTmp;
    int* cat = (int*)FUN_140876480(&catTmp, 0);
    void* mem = FUN_14208a860(0x40, *cat);
    CSoundMusicEffect* pObj;
    // MS2-FUNCTIONAL: the exe's site is a bare `mov rcx,mem; call ??0CSoundMusicEffect`, i.e. its build inlined
    // efd::MemObject's in-place operator new (a `return p;`) away; cl 19.16 under the harness' /Ob0 keeps the
    // ??2@YAPEAX_KPEAX@Z call (151 vs 150 bytes). The exe also frames the CEffectPtr return with an unwind handler
    // (UNWIND_INFO.flags 2, EH state -2 at [rsp+0x48]) where this build emits none. Behaviour identical.
    if (mem == 0) pObj = 0; else pObj = ::new (mem) CSoundMusicEffect;
    return CEffectPtr(pObj);
}

// ---- CSoundMusicEffect ----

// @0x141790000
CSoundMusicEffect::CSoundMusicEffect() : m_f30(1.0f), m_f38(0.0f)
{
}

// Restores the music volume the effect faded away from. One expression: the value is a temporary, so /Od spills it
// (movss [rsp+0x20]) and reloads it through xmm0 before moving it into the argument register xmm1.
// @0x141790060
CSoundMusicEffect::~CSoundMusicEffect()
{
    FUN_140d13c40()->FUN_14177ca30(FUN_141260110(FUN_1409a8b10()->FUN_140d13c70(), 2));
}

// Starts the music: the cue, the parameter, the reverb string, then the volume fade plan (the music volume is read
// back and the target is the game volume times the param's volume).
// @0x1417900e0
bool CSoundMusicEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    float fDelta;
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CSoundMusicEffectParam* pMusic = (const CSoundMusicEffectParam*)pParam;
    if (m_unk_18 > 1)
        return false;
    if (pMusic->m_nCueID != -1)
        FUN_140d13c40()->FUN_14177c100(pMusic->m_nCueID, 0.0f, pMusic->m_nPriority, 0);
    if (pMusic->m_nParamID != -1)
        FUN_140d13c40()->FUN_14177c420(pMusic->m_nParamID, pMusic->m_fParamValue, pMusic->m_nPriority, 0);
    if (!pMusic->m_strReverb.IsEmpty())
        FUN_140d13c40()->FUN_14177ddd0((void*)(LPCSTR)pMusic->m_strReverb, pMusic->m_nPriority, 0x80);
    if (pMusic->m_fVolume <= 0.0f || pMusic->m_fDuration == 0.0f)
        return false;
    float fOld = FUN_140d13c40()->FUN_14177c9e0();
    float fNew = FUN_141260110(FUN_1409a8b10()->FUN_140d13c70(), 2) * pMusic->m_fVolume;
    fDelta = fNew - fOld;
    m_f38 = fDelta;
    m_f30 = fNew;
    m_f34 = FUN_140d13c40()->FUN_14177c9e0();
    return true;
}

// Per frame: fade the music volume linearly from m_f34 (the volume the effect started from) to m_f30 over the effect's
// duration. Once the duration is up the effect stops applying.
// @0x1417902b0
bool CSoundMusicEffect::vfunc_9()
{
    if (!m_b2d)
    {
        double dNow = FUN_14086d260()->FUN_141473280();
        if (dNow <= m_dStartTime + m_fDuration)
        {
            float fT = (float)(dNow - m_dStartTime) / m_fDuration;
            float fDelta = fT * m_f38;
            float fVolume = m_f34 + fDelta;
            FUN_140d13c40()->FUN_14177ca30(fVolume);
            return true;
        }
    }
    return false;
}

// @0x141790750
int CSoundMusicEffect::vfunc_12()
{
    return 3;
}

// @0x141790760
const NiRTTI* CSoundMusicEffect::GetRTTI() const
{
    return &ms_RTTI;
}

// @0x141790680
// MS2-FUNCTIONAL: the exe dtor omits the vftable store before calling ~CEffectParam (it is just the CString at +0x60
// then the base dtor); cl 19.16 always emits the store, so 28 bytes differ (same shape as fishcube.cpp).
CSoundMusicEffectParam::~CSoundMusicEffectParam()
{
}

// ---- this unit's log wrapper copy and the unreferenced CRT copy ----

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
#pragma function(memcpy, memset)
// @0x141790770
static __inline errno_t ms2_music_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMusicMemcpyS)(void*, size_t, const void*, size_t) = &ms2_music_memcpy_s;
#pragma intrinsic(memcpy, memset)
