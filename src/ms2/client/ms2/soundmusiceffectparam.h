// soundmusiceffectparam.h - the sound effect XML type 3 "SoundMusic" (param + runtime effect): plays an FMOD music cue
// with a parameter, a reverb string and a volume, and fades the music volume to the effect's volume over the effect's
// duration. NOT an original header (the name is the owning unit's path); layout proven from the ctor 0x14178fd20 and
// the vfunc_1 attribute names.
//
// NOTE: ?\soundeventmgr.cpp (soundeventmgr.h) holds a *minimal* CSoundMusicEffect (only the RTTI static, no virtuals)
// because that unit emits the CSoundMusicEffect::ms_RTTI object. Never include both headers in one TU.
// Owning unit: ?\soundmusiceffectparam.cpp (0x14178fd20-0x141790890 .text$mn, client\ms2).
#pragma once
#include "ms2/client/ms2/effectparam.h"

// Effect XML type 3 <SoundMusic cueID= paramID= paramValue= priority= volume= reverb= .../>. 0x68 bytes, vftable
// 0x142f67b50 (8 slots, ??_G 0x141790710). Overrides slots 1, 2 and 6.
class CSoundMusicEffectParam : public CEffectParam
{
public:
    CSoundMusicEffectParam();                                   // 0x14178fd20
    // implicit: virtual ~CSoundMusicEffectParam();             // 0x141790680, ??_G 0x141790710
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x14178fdb0
    virtual bool vfunc_2();                                     // 2 0x14178fe90 validate the music cue
    virtual CEffectPtr vfunc_6();                               // 6 0x14178ff60 new CSoundMusicEffect

public:
    MS2_LAYOUT_FRIEND;
    int m_nCueID;                   // +0x48 "cueID" (-1)
    int m_nPriority;                // +0x4c "priority" (0x80)
    int m_nParamID;                 // +0x50 "paramID" (-1)
    float m_fParamValue;            // +0x54 "paramValue" (0)
    float m_fVolume;                // +0x58 "volume" (-1)
    CString m_strReverb;            // +0x60 "reverb"
};
MS2_CHECK_SIZE(CSoundMusicEffectParam, 0x68);
MS2_CHECK_OFFSET(CSoundMusicEffectParam, m_nCueID, 0x48);
MS2_CHECK_OFFSET(CSoundMusicEffectParam, m_nPriority, 0x4c);
MS2_CHECK_OFFSET(CSoundMusicEffectParam, m_nParamID, 0x50);
MS2_CHECK_OFFSET(CSoundMusicEffectParam, m_fParamValue, 0x54);
MS2_CHECK_OFFSET(CSoundMusicEffectParam, m_fVolume, 0x58);
MS2_CHECK_OFFSET(CSoundMusicEffectParam, m_strReverb, 0x60);

// The runtime effect (CEffect::vfunc_12 == 3, 0x40 bytes). vftable 0x142f67b98 (13 slots, ??_G 0x1417906b0), RTTI
// "CSoundMusicEffect" 0x143aea260 (emitted by ?\soundeventmgr.cpp). GetRTTI (slot 2) is out of line here.
class CSoundMusicEffect : public CEffect
{
public:
    CSoundMusicEffect();                                        // 0x141790000
    virtual ~CSoundMusicEffect();                               // 0x141790060, ??_G 0x1417906b0
    virtual const NiRTTI* GetRTTI() const;                      // 2 0x141790760 return &ms_RTTI
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x1417900e0 start the music
    virtual bool vfunc_9();                                     // 9 0x1417902b0 fade the music volume per frame
    virtual int vfunc_12();                                     // 12 0x141790750 effect type 3

    static void operator delete(void*, size_t);                 // efd::MemObject::operator delete 0x14208a8f0
    static const NiRTTI ms_RTTI;                                // 0x143aea260 (defined in ?\soundeventmgr.cpp)

public:
    MS2_LAYOUT_FRIEND;
    float m_f30;                    // +0x30 the target music volume at start (1)
    float m_f34;                    // +0x34 the music volume at start (not initialised by the ctor)
    float m_f38;                    // +0x38 the volume delta applied over the duration
};
MS2_CHECK_SIZE(CSoundMusicEffect, 0x40);
MS2_CHECK_OFFSET(CSoundMusicEffect, m_f30, 0x30);
MS2_CHECK_OFFSET(CSoundMusicEffect, m_f34, 0x34);
MS2_CHECK_OFFSET(CSoundMusicEffect, m_f38, 0x38);
