// soundproperty.h - the sound property tables: hitSound.xml (attack/defence material -> hit sound ids), systemSound.xml
// (SystemSoundProperty), pitchSound.xml (voice pitch per object id), EventSound.xml (event voices per gender/job) and
// TriggerVoice.xml (TriggerVoiceProperty), all kept by SoundPropertyMgr (RTTI names SoundPropertyMgr,
// SystemSoundProperty, TriggerVoiceProperty). Owning unit: client\ms2\soundproperty.cpp (0x141790890-0x1417ae520
// .text$mn, 0x140101680-0x1401017f0 .text$di). Header name assumed from the unit path; member names are invented
// from use. Replaces the local stubs of effectservice.cpp, soundservice.cpp, soundeventmgr.cpp and tableexporter.cpp.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

class Unk_140165cf0;    // game TinyXML element
class GameObject;

// <hitSound AttackMaterial= DefenceMeterial= soundID=/>: the key of the hit sound table, ordered by attack material
// first.
struct Unk_HitSoundKey
{
    Unk_HitSoundKey(int nAttack, int nDefence);                 // 0x141790890
    Unk_HitSoundKey(const Unk_HitSoundKey& o);                  // 0x1417908d0
    Unk_HitSoundKey& operator=(const Unk_HitSoundKey& o);       // 0x141790910
    bool operator<(const Unk_HitSoundKey& o) const;             // 0x141790950
    bool operator==(const Unk_HitSoundKey& o) const;            // 0x1417909d0

    int m_nAttack;
    int m_nDefence;
};
MS2_CHECK_SIZE(Unk_HitSoundKey, 8);

// The sound names of one job (boxed array shared by the job table of the properties).
typedef ATL::CAtlArray<CString> Unk_SoundNameArray;
typedef Unk_FieldPtr<Unk_SoundNameArray> Unk_SoundNameArrayPtr;
// The exe's map passes the job code by reference (ATL's default INARGTYPE): SetAt/Lookup take &key.
struct Unk_JobSoundKeyTraits : ATL::CElementTraits<int> { typedef const int& INARGTYPE; };
typedef ATL::CAtlMap<int, Unk_SoundNameArrayPtr, Unk_JobSoundKeyTraits> Unk_JobSoundMap;   // job code -> sound names (per gender)

// <systemSound key= soundID= group= byGender= byJob= cooltimeID= jobSoundID=/> (0x98 bytes, CPtred based).
class SystemSoundProperty : public CPtred
{
public:
    SystemSoundProperty();                                      // 0x141790a20
    // implicit dtor 0x1417a07b0

    void Load(Unk_140165cf0* pElem);                            // 0x141790ae0
    CString GetCategory(int nGender);                          // 0x141790e00 (FUN_ name kept: the callers bind it)
    CString GetSoundName(unsigned nGender, int nJob);           // 0x141790ed0
    unsigned GetCooltimeId() const;                             // 0x141791120

    int m_nUnk18;                                               // +0x18
    CString m_strGroup;                                         // +0x20 "group"
    bool m_bByGender;                                           // +0x28 "byGender"
    bool m_bByJob;                                              // +0x29 "byJob"
    unsigned m_nCooltimeId;                                     // +0x2c "cooltimeID"
    ATL::CAtlArray<CString> m_sounds;                           // +0x30 "soundID"
    Unk_JobSoundMap m_jobSounds;                                // +0x50 "jobSoundID"
};
MS2_CHECK_SIZE(SystemSoundProperty, 0x98);
MS2_CHECK_OFFSET(SystemSoundProperty, m_strGroup, 0x20);
MS2_CHECK_OFFSET(SystemSoundProperty, m_sounds, 0x30);
MS2_CHECK_OFFSET(SystemSoundProperty, m_jobSounds, 0x50);

// <voice key= byGender= byJob= defaultSound= Job10=.../> (0x88 bytes, CPtred based).
class TriggerVoiceProperty : public CPtred
{
public:
    TriggerVoiceProperty();                                     // 0x141791140
    // implicit dtor 0x1417a0800

    void Load(Unk_140165cf0* pElem);                            // 0x1417911e0
    bool GetVoice(unsigned nGender, int nJob, CString& strOut); // 0x141791400
    void CollectNames(std::set<CString>& rOut);                 // 0x141791620

    int m_bByGender;                                            // +0x18 "byGender"
    int m_bByJob;                                               // +0x1c "byJob"
    ATL::CAtlArray<CString> m_sounds;                           // +0x20 "defaultSound"
    Unk_JobSoundMap m_jobSounds;                                // +0x40 "Job<code>"
};
MS2_CHECK_SIZE(TriggerVoiceProperty, 0x88);
MS2_CHECK_OFFSET(TriggerVoiceProperty, m_sounds, 0x20);
MS2_CHECK_OFFSET(TriggerVoiceProperty, m_jobSounds, 0x40);

// One <eventSound>: the voice an event plays (copied out to the caller).
struct Unk_EventVoice
{
    // implicit ctor 0x1411af960 and dtor 0x1411b01c0 (instantiated in effectservice.cpp's range)
    Unk_EventVoice& operator=(const Unk_EventVoice& o);         // 0x1417a0900

    unsigned m_bOnlyCasterMyPC;                                 // +0x00 "onlyCasterMyPC"
    CString m_strGroup;                                         // +0x08 "group" (lower-cased)
    CString m_strSoundId;                                       // +0x10 "soundID"
    CString m_strRestoreSoundId;                                // +0x18 "restoreSoundID"
};
MS2_CHECK_SIZE(Unk_EventVoice, 0x20);

// The pitch record of a voice (pitch, FMOD pitch units).
struct Unk_SoundPitch
{
    Unk_SoundPitch() : m_fPitch(0.0f), m_nUnits(0) {}
    float m_fPitch;
    int m_nUnits;
};
MS2_CHECK_SIZE(Unk_SoundPitch, 8);

typedef ATL::CAtlMap<CString, MS2Ptr<SystemSoundProperty>, ATL::CStringElementTraitsI<CString> > Unk_SystemSoundMap;
typedef ATL::CAtlMap<CString, MS2Ptr<TriggerVoiceProperty>, ATL::CStringElementTraitsI<CString> > Unk_TriggerVoiceMap;
typedef std::map<CString, std::set<CString> > Unk_VoiceGroupMap;    // trigger voice -> every sound name
typedef std::map<int, Unk_EventVoice> Unk_EventByCaster;
typedef std::map<int, Unk_EventByCaster> Unk_EventByJob;
typedef std::map<int, Unk_EventByJob> Unk_EventByGender;
typedef std::map<int, Unk_EventByGender> Unk_EventMap;

// The manager (RTTI SoundPropertyMgr): TSingleton at +0 (vftable), CValidData at +8, the tables from +0x10.
class SoundPropertyMgr : public TSingleton<SoundPropertyMgr>, public CValidData<SoundPropertyMgr>
{
public:
    typedef MS2Ptr<SystemSoundProperty> SystemPtr;
    typedef MS2Ptr<TriggerVoiceProperty> VoicePtr;
    typedef MS2Ptr<CCacheData> CachePtr;

    SoundPropertyMgr();                                         // 0x141791810
    // implicit dtor 0x1417a0710

    unsigned Load();                                            // 0x141791940 (all five tables)
    unsigned FUN_141792d70(int nAttack, int nDefence);          // a random hit sound id of the materials
    int FUN_141792e00(int nEventId, GameObject* pActor, Unk_EventVoice* pOut);   // the event voice for the actor
    SystemPtr FUN_141792ee0(const CString& strName, const CString& strArg);       // system sound property
    VoicePtr FUN_141793110(const CString& strName);                               // trigger voice property
    void FUN_141793210(Unk_VoiceGroupMap& rOut);                // every trigger voice -> its sound names
    int FUN_141793340(int nObjectId, Unk_SoundPitch* pOut);    // the pitch of an object's voice
    void Reload();                                              // 0x1417933d0 (clear and Load)
    void FUN_141793450();                                       // reload when a table file changed

    static void CheckInit();                                    // 0x1417a3890
    static void SetInit(bool b);                                // 0x1417a6920
    static bool s_bInit;                                        // 0x143aea270

private:
    int LoadHitSound(const char* pszPath);                     // 0x141792180
    int LoadSystemSound(const char* pszPath);                  // 0x141792360
    int LoadPitchSound(const char* pszPath);                   // 0x141792570
    int LoadEventSound(const char* pszPath);                   // 0x141792740
    int LoadTriggerVoice(const char* pszPath);                 // 0x141792b60

    MS2_LAYOUT_FRIEND;
    std::map<Unk_HitSoundKey, std::vector<int> > m_hitSounds;    // +0x10
    Unk_SystemSoundMap m_systemSounds;                          // +0x20
    Unk_TriggerVoiceMap m_triggerVoices;                        // +0x68
    std::map<int, Unk_SoundPitch> m_pitches;                    // +0xb0
    Unk_EventMap m_events;                                      // +0xc0
    std::list<CachePtr> m_cacheFiles;                       // +0xd0
};
MS2_CHECK_OFFSET(SoundPropertyMgr, m_hitSounds, 0x10);
MS2_CHECK_OFFSET(SoundPropertyMgr, m_systemSounds, 0x20);
MS2_CHECK_OFFSET(SoundPropertyMgr, m_triggerVoices, 0x68);
MS2_CHECK_OFFSET(SoundPropertyMgr, m_pitches, 0xb0);
MS2_CHECK_OFFSET(SoundPropertyMgr, m_events, 0xc0);
MS2_CHECK_OFFSET(SoundPropertyMgr, m_cacheFiles, 0xd0);
