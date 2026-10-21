// soundeventmgr.h - sound events: the effect XML type 2 "SoundEvent" (param + runtime effect), the FMOD event wrapper
// CSoundEvent and the event manager CSoundEventMgr. Owning unit: client\ms2\soundeventmgr.cpp
// (0x141775810-0x14178fd20 .text$mn, 0x140101560-0x140101680 .text$di). Header name assumed from the unit path.
// Member names are invented from use. Replaces the local stubs in effectservice.cpp.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiRTTI.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/placeholder/fmodwrap.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/commonfiles/timer.h"
#include <efd/SmartPointer.h>
#include <egf/Entity.h>
#include <list>
#include <map>
#include <string>
#include <vector>

#include "ms2/placeholder/ctwocirclecollision.h"

// The playing FMOD event (0x38 bytes, CPtred based). Owns the 3D attenuation shape built from the event's
// 3DMinDistance / 3DMaxDistance properties.
class CSoundEvent : public CPtred
{
public:
    CSoundEvent(FMOD::Event* pEvent, CString strName);          // 0x14177a590
    virtual ~CSoundEvent();                                     // 0x14177a800

    bool FUN_14177a8d0();                                       // start
    void FUN_14177a920(int bFadeOut);                           // stop (0 = request stop, else reset)
    void FUN_14177a990(const Unk_StreamPoint& vPos);            // 3D position (+ attenuation shape)
    void FUN_14177aac0(const Unk_StreamPoint& vPos, const Unk_StreamPoint& vVel);   // 3D position + velocity
    int FUN_14177ab80();                                        // the event is playing
    // @0x1411b1ba0
    CTwoCircleCollision* FUN_1411b1ba0() { return m_pRange; }
    void FUN_14177abc0(FMOD_EVENT_CALLBACK pfnCallback, void* pUserData);
    bool FUN_14177ac00();                                       // getMute succeeded
    void FUN_14177ac50(unsigned bMute);
    int FUN_14177ac80();                                        // started or stopped
    CString FUN_14177aca0();                                    // the event name
    void FUN_14177acf0(float fVolume);

public:
    MS2_LAYOUT_FRIEND;
    CTwoCircleCollision* m_pRange;  // +0x18 attenuation shape (null when the event has no 3D distances)
    FMOD::Event* m_pEvent;          // +0x20
    int m_nStarted;                 // +0x28
    int m_nStopped;                 // +0x2c
    CString m_strName;              // +0x30
};
MS2_CHECK_SIZE(CSoundEvent, 0x38);
MS2_CHECK_OFFSET(CSoundEvent, m_pRange, 0x18);
MS2_CHECK_OFFSET(CSoundEvent, m_pEvent, 0x20);
MS2_CHECK_OFFSET(CSoundEvent, m_strName, 0x30);
typedef MS2Ptr<CSoundEvent> CSoundEventPtr;

// Effect XML type 2 <SoundEvent event= group= byJob= .../> (0x110 bytes). vftable 0x142f64130.
// The effect class of the music cue effect type; its other members live in another unit (only the RTTI static is here).
class CSoundMusicEffect : public CEffect
{
public:
    static const NiRTTI ms_RTTI;
};

// The job code of the per-job event / delay tables (an enum, so the ATL map keys are passed by reference).
enum Unk_SoundJobCode { Unk_SoundJobCode_None };

class CSoundEventEffectParam : public CEffectParam
{
public:
    CSoundEventEffectParam();                                   // 0x141775810
    virtual ~CSoundEventEffectParam();                          // 0x1417782b0
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141775af0
    virtual bool vfunc_2();                                     // 2 0x141775cb0 validate the event / group names
    virtual CEffectPtr vfunc_6();                               // 6 0x141775fc0 new CSoundEventEffect
    virtual bool vfunc_7(Unk_EffectTarget* pTarget);            // 7 0x141776060

    bool FUN_1417760d0() const;                                       // the cooltime is over (or none)
    CString FUN_141776120(int nJob) const;                            // the event name for the job
    const CString& FUN_141776260() const { return m_strGroup; }
    const CString& FUN_141776280() const { return m_strParentNode; }
    float FUN_1417762a0(int nJob) const;                              // the start delay for the job
    void FUN_141776330(Unk_140165cf0* pNode);                   // "jobEvent"  = job:event,...
    void FUN_1417764c0(Unk_140165cf0* pNode);                   // "byJobStartDelay" = job:delay,...

public:
    MS2_LAYOUT_FRIEND;
    bool m_bAttachToNode;           // +0x48 "attachToNode"
    bool m_bApplyNodeTransform;     // +0x49 "applyNodeTransform"
    bool m_bDoNotStop;              // +0x4a "doNotStop"
    float m_fVolume;                // +0x4c = 1
    float m_fViewDistance;          // +0x50 "forceHearDistance" (0 = use the table)
    CString m_strExtra;             // +0x58
    CString m_strEvent;             // +0x60 "event"
    CString m_strGroup;             // +0x68 "group"
    CString m_strParentNode;        // +0x70 "parentNode"
    bool m_bByJob;                  // +0x78 "byJob"
    bool m_bSkipMusicConcert;       // +0x79 "isSkipMusicConcert"
    unsigned m_nCooltimeId;         // +0x7c "cooltimeID"
    ATL::CAtlMap<Unk_SoundJobCode, CString> m_mapJobEvent;   // +0x80 job -> event
    ATL::CAtlMap<Unk_SoundJobCode, float> m_mapJobDelay;     // +0xc8 job -> start delay
};
MS2_CHECK_SIZE(CSoundEventEffectParam, 0x110);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_fViewDistance, 0x50);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_strParentNode, 0x70);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_mapJobEvent, 0x80);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_mapJobDelay, 0xc8);

// The runtime effect (CEffect::vfunc_12 == 2, 0x68 bytes). vftable 0x142f64178, RTTI "CSoundEventEffect" 0x143aea240.
class CSoundEventEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141778be0
public:
    CSoundEventEffect();                                        // 0x141776630
    virtual ~CSoundEventEffect();                               // 0x1417766e0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x141776760
    virtual void vfunc_4();                                     // 4 0x141777370 start
    virtual void vfunc_5();                                     // 5 0x141777520 stop
    virtual void vfunc_7();                                     // 7 0x141777670 detach
    virtual int vfunc_8(void* p);                               // 8 0x1417776b0 world position of the root
    virtual bool vfunc_9();                                     // 9 0x1417771a0 per-update
    virtual int vfunc_12();                                     // 12 0x141778980 effect type 2

    CString& FUN_141777700() { return m_strExtra; }
    MS2Ptr<CSoundEvent> FUN_141777720();                        // the playing sound
    void FUN_141777770() { m_b2d = true; }                      // finished

public:
    MS2_LAYOUT_FRIEND;
    Unk_NodePtr m_spRoot;           // +0x30 "Effect Root" node
    float m_fVolume;                // +0x38
    MS2Ptr<CSoundEvent> m_spSound;  // +0x40
    bool m_bDoNotStop;              // +0x50
    bool m_bStopRequested;          // +0x51
    double m_dStopTime;             // +0x58 stop requested: the sound is released at this time
    CString m_strExtra;             // +0x60 param m_strExtra
};
MS2_CHECK_SIZE(CSoundEventEffect, 0x68);
MS2_CHECK_OFFSET(CSoundEventEffect, m_spRoot, 0x30);
MS2_CHECK_OFFSET(CSoundEventEffect, m_spSound, 0x40);
MS2_CHECK_OFFSET(CSoundEventEffect, m_dStopTime, 0x58);
MS2_CHECK_OFFSET(CSoundEventEffect, m_strExtra, 0x60);

// FMOD event callback of the effect (0x1417775b0): 4 = event finished, 6 = sound def created.
FMOD_RESULT F_CALLBACK FUN_1417775b0(FMOD_EVENT* pEvent, FMOD_EVENT_CALLBACKTYPE eType, void* pParam1, void* pParam2,
                                     void* pUserData);

template <class T> class TSingleton;
class CSoundEventMgr;
template <> class TSingleton<CSoundEventMgr>
{
public:
    TSingleton();                                   // 0x141786300
    virtual ~TSingleton() { s_instance = 0; }
    static CSoundEventMgr* s_instance;              // 0x143ac1928
    static CSoundEventMgr* GetInstance();               // 0x140d13c40
};

// The sound designer's tool history: an undo/redo style list with a cursor. Instantiated for MusicData, ReverbData
// and ParamVaule (sic: the exe's template argument spelling).
template <class T> class TToolHistory
{
public:
    TToolHistory();                                 // vfptr, empty list, cursor 0
    virtual ~TToolHistory();
    virtual int vfunc_1(void*) { return 0; }
    virtual int vfunc_2(void*) { return 0; }
    void Add(const T& rData);                       // drops everything after the cursor, appends, cursor = end
    int GetPos() const;                             // cursor - 1
    int Get(int nOffset, T* pOut);                  // moves the cursor by nOffset from the last entry, 1 = got it
    void Clear();

    std::list<T> m_list;            // +0x08
    unsigned m_nPos;                // +0x18
};

// One music cue / music parameter record: the value and the priority that may overwrite it (0x100 = lowest).
struct MusicData
{
    MusicData() : m_nId(0), m_nPriority(0x100) {}   // 0x141787180
    int m_nId;
    unsigned m_nPriority;
};
struct ParamVaule
{
    ParamVaule() : m_fValue(0.0f), m_nPriority(0x100) {}   // 0x1417871b0
    float m_fValue;
    unsigned m_nPriority;
};
struct ReverbData
{
    ReverbData();                                   // 0x1417871e0: priority 0x100, the properties zeroed
    unsigned m_nPriority;                           // +0x00
    FMOD_REVERB_PROPERTIES m_props;                 // +0x04
};
MS2_CHECK_SIZE(ReverbData, 0x54);

// The running volume fade of an event category (value of the CSoundEventMgr fade map).
struct Unk_SoundFade
{
    int m_nCategory;                // +0x00
    int m_nMode;                    // +0x04 1 = fade in, 2 = fade out
    float m_fVolume;                // +0x08 the volume at the start
    Timer m_timer;                  // +0x10
};
MS2_CHECK_SIZE(Unk_SoundFade, 0x48);

typedef efd::SmartPointer<egf::Entity> Unk_EntityPtr;

// The FMOD event manager singleton (m_bReady at +0x8c gates every call). Function names are the exe's.
class CSoundEventMgr : public TSingleton<CSoundEventMgr>
{
public:
    CSoundEventMgr();                                           // 0x14177ad20
    virtual ~CSoundEventMgr();                                  // 0x14177aea0

    void FUN_14177af40(FMOD::EventSystem* pSystem, void* pParam);   // attach the event system, fetch the categories
    MS2Ptr<CSoundEvent> FUN_14177b3d0(FMOD::EventGroup* pGroup, const char* pszName, float fPitch,
                                      FMOD_EVENT_PITCHUNITS eUnits);   // an event of the group with pitch
    MS2Ptr<CSoundEvent> FUN_14177b6a0(const char* pszName);     // the event by full name
    void FUN_14177b900();                                       // fade the environment sounds in
    void FUN_14177b940();                                       // fade them out, stop the environment sounds
    void FUN_14177ba30();                                       // shut down
    void FUN_14177bb70(float fDelta);                                     // per frame
    void FUN_14177bbc0();                                       // advance the volume fades
    void FUN_14177bda0();                                       // sound device lost
    void FUN_14177bf20();                                       // sound device restored
    int FUN_14177c100(int nMusicId, float fParam, unsigned nPriority, int bForce);   // play a music cue
    int FUN_14177c420(int nParamId, float fValue, unsigned nPriority, int bForce);   // set a music parameter
    int FUN_14177c710(int nParamId, float* pfValue);            // get a music parameter
    bool FUN_14177c7e0(bool bPaused);                           // pause the music
    void FUN_14177c850();                                       // reset the music system
    void FUN_14177c8a0();                                       // reset the music state
    void FUN_14177c980(unsigned bMute);                         // mute the music
    float FUN_14177c9e0();                                      // the music volume
    void FUN_14177ca30(float fVolume);                          // set the music volume
    int FUN_14177caa0();                                        // the current music cue id
    MS2Ptr<CSoundEvent> FUN_14177cbe0(Unk_EntityPtr spEntity, const char* pszEvent);   // the entity's environment sound
    void FUN_14177ce30(Unk_EntityPtr spEntity, int bOn);        // switch the entity's environment sound
    void FUN_14177d230();                                       // start the environment sounds
    void FUN_14177d380();                                       // stop and release the environment sounds
    void FUN_14177d450(Unk_EntityPtr spEntity);                 // remove an environment sound
    void FUN_14177d5e0();                                       // remove all environment sounds
    FMOD::EventGroup* FUN_14177d6e0(const char* pszName, int bLoad);   // the (cached) event group
    void FUN_14177d860(const char* pszName);                    // free an event group
    void FUN_14177d9b0(const char* pszGroup, std::vector<CString>& rNames);   // event names of a group
    void FUN_14177da80(int nCategory, float fVolume);           // category volume
    float FUN_14177db60(int nCategory);
    void FUN_14177dbe0(int nCategory, unsigned bMute);          // mute a category
    void FUN_14177dc80(unsigned bMute);                         // mute everything
    bool FUN_14177dd50(int nCategory);
    int FUN_14177ddd0(void* pUnused, int nUnused1, int nUnused2);   // 1
    void FUN_14177ddf0(int nCategory, int nMs);                 // start a fade in
    void FUN_14177dea0(int nCategory, int nMs);                 // start a fade out
    void FUN_14177df50(int nCategory, float fVolume);           // finish a fade
    CStringW FUN_14177e020();                                   // the music debug text
    void FUN_14177e1c0();                                       // draw the attenuation shapes
    void FUN_14177e2e0(int bFlag);

public:
    MS2_LAYOUT_FRIEND;
    FMOD::EventSystem* m_pEventSystem;  // +0x08
    void* m_p10;                        // +0x10
    FMOD::MusicSystem* m_pMusicSystem;  // +0x18
    float m_fMusicVolume;               // +0x20 = 1
    float m_fNowMusicVolume;            // +0x24 = 1
    int m_n28;                          // +0x28
    float m_f2c;                        // +0x2c = 1
    bool m_b30;                         // +0x30 = true
    TToolHistory<MusicData> m_histMusic;            // +0x38
    TToolHistory<ReverbData> m_histReverb;          // +0x58
    std::map<int, TToolHistory<ParamVaule> > m_mapParams;   // +0x78 music parameter histories by id
    int m_bMusicPlaying;                // +0x88
    int m_bReady;                       // +0x8c
    FMOD::EventCategory* m_apCategory[11];          // +0x90 effect, environment, ...
    std::map<Unk_EntityPtr, MS2Ptr<CSoundEvent> > m_mapEnvSounds;   // +0xe8
    std::map<std::string, FMOD::EventGroup*> m_mapGroups;          // +0xf8
    std::map<int, Unk_SoundFade> m_mapFades;       // +0x108
    int m_n118;                         // +0x118
};
MS2_CHECK_SIZE(CSoundEventMgr, 0x120);
MS2_CHECK_OFFSET(CSoundEventMgr, m_histMusic, 0x38);
MS2_CHECK_OFFSET(CSoundEventMgr, m_histReverb, 0x58);
MS2_CHECK_OFFSET(CSoundEventMgr, m_mapParams, 0x78);
MS2_CHECK_OFFSET(CSoundEventMgr, m_bReady, 0x8c);
MS2_CHECK_OFFSET(CSoundEventMgr, m_apCategory, 0x90);
MS2_CHECK_OFFSET(CSoundEventMgr, m_mapEnvSounds, 0xe8);
MS2_CHECK_OFFSET(CSoundEventMgr, m_mapGroups, 0xf8);
MS2_CHECK_OFFSET(CSoundEventMgr, m_mapFades, 0x108);

CSoundEventMgr* FUN_140d13c40();                                // TSingleton<CSoundEventMgr>::GetInstance

// 0x141775980 (called from effectservice.cpp): builds a param for a one-shot event.
MS2Ptr<CSoundEventEffectParam> FUN_141775980(CString strName, CString strCategory, float fVolume, CString strExtra);
