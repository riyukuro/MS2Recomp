// instrumentmanager.h - CInstrumentManager (RTTI .?AVCInstrumentManager@@, 0x6c0 bytes): the instrument play mode
// (packet 0x74). It plays the local keyboard notes and the scores (MML text, solo / ensemble / remote performers)
// through a CMidiOutput, maps performers to the 16 MIDI channels (channel 0 = the local player, 9 = the remote
// performers' shared drum channel), sets their volume by distance and schedules the score's tempo / motion events.
// Owning unit: ?\instrumentmanager.cpp (0x140d05a90-0x140d1ae30). Member names are invented from use (the v2525
// snapshot's layout, checked against our ctor). NOT an original header (name assumed).
// Bases: IWorldServiceCallback at +0x0, UIBuddyEventListener at +0x8, TSingleton<CInstrumentManager> at +0x10.
#pragma once
#include <afx.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/midimessage.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/uibuddyeventlistener.h"
#include "ms2/placeholder/nipoint3.h"

class CInPacket;
class CItem;

// nullable<int> (commonfiles/nullable.h): flag + value. The instance of this unit (ctor 0x140d11940, HasValue
// 0x140d1a9d0, Value 0x140d1acd0) is the program override of the scores.
struct Unk_ImNullableInt
{
    Unk_ImNullableInt();                                    // 0x140d11940
    bool HasValue() const;                                  // 0x140d1a9d0
    int& Value();                                           // 0x140d1acd0 asserts m_isValueSet (nullable.h line 0x41)
    bool m_isValueSet;                                      // +0x00
    int m_value;                                            // +0x04
};
MS2_CHECK_SIZE(Unk_ImNullableInt, 0x8);

// The score's non-MIDI events: tick -> (kind, value); kind 0 = tempo (motion speed value / 120), 1 = motion level.
typedef std::multimap<unsigned int, std::pair<int, int> > Unk_ImScoreEvents;

class CInstrumentManager : public IWorldServiceCallback, public UIBuddyEventListener, public TSingleton<CInstrumentManager>
{
public:
    // One performer on a MIDI channel (0x1c bytes). Slot::operator= (0x140d12980) is implicit.
    struct Voice
    {
        Voice();                                            // 0x140d12420 Reset()
        void Reset();                                       // 0x140d05a90
        void Assign(const Voice& o);                        // 0x140d05af0
        bool IsRemote() const;                              // 0x140d13c90 m_percussion != 0 (a drum part)
        int m_channel;                                      // +0x00 the performer slot key (0 = the local player)
        int m_owner;                                        // +0x04 the actor id
        Unk_StreamPoint m_position;                         // +0x08
        int m_program;                                      // +0x14 GM program
        int m_percussion;                                   // +0x18 the drum note (0 = melodic)
    };
    // A remote (drum channel) performer (0x20 bytes).
    struct RemoteVoice : Voice
    {
        RemoteVoice();                                      // 0x140d123f0 Init()
        void Init();                                        // 0x140d05b70
        bool m_active;                                      // +0x1c heard (in range, not blocked)
    };
    // One of the 16 channels (0x24 bytes).
    struct Slot : Voice
    {
        Slot();                                             // 0x140d12450 Init()
        void Init();                                        // 0x140d05ba0
        bool m_used;                                        // +0x1c
        int m_volume;                                       // +0x20 the last volume sent (-1 = none)
    };

    CInstrumentManager();                                   // 0x140d05be0
    virtual ~CInstrumentManager();                          // 0x140d05e50
    // IWorldServiceCallback
    virtual void vfunc_1(int nMap);                         // 0x140d05f70 field entered: base time, reopen the device
    virtual void vfunc_4(int nMap);                         // 0x140d05fe0 field left: stop everything
    // UIBuddyEventListener
    virtual void vfunc_buddy_4(__int64 nId, int n);         // 0x140d06030 a buddy changed (block list)
    virtual void vfunc_buddy_7(__int64 nId);                // 0x140d06130

    void OnPacket(CInPacket& packet);                       // 0x140d061b0
    void Update();                                          // 0x140d07080
    void Stop();                                            // 0x140d070b0
    void SetInstrument(int nInstrument, __int64 nItemUid);  // 0x140d07130
    int CanPlayEnsemble();                                  // 0x140d071b0
    bool SetPcState(int nState);                            // 0x140d07200
    void SetEnsemble(bool bEnsemble);                       // 0x140d07260
    bool IsEnsemble();                                      // 0x140d07330
    bool IsPerforming();                                    // 0x140d07350
    bool IsRemote();                                        // 0x140d07370
    int GetRefs();                                          // 0x140d07390
    void NoteOn(int nNote);                                 // 0x140d073b0
    void NoteOff(int nNote);                                // 0x140d07840
    bool PlayScore(__int64 nScoreUid);                      // 0x140d07960
    bool PlayEnsemble(__int64 nScoreUid);                   // 0x140d07f00
    bool StopEnsemble();                                    // 0x140d085a0
    void StopPerform();                                     // 0x140d08600
    unsigned ParseLine(int nChannel, int nProgram, int nPercussion, Unk_MidiTrack* pTrack, Unk_ImScoreEvents* pEvents,
                       unsigned nTime, unsigned nNow, const CString& strMml, bool bFirst);   // 0x140d08660
    int PlayScoreFile(const CString& strName, int nTime, int nProgram, int nPercussion, int nChannel, int nKey,
                      unsigned nOwner);                         // 0x140d08d10
    int PlayScoreText(const CString& strText, int nTime, int nProgram, int nPercussion, int nChannel, int nKey,
                      unsigned nOwner);                         // 0x140d092c0
    void OnPerformStart(int nOwner, int nStart, int nEnd, bool bRemote);   // 0x140d09710
    void OnPerformEnd(int nOwner);                          // 0x140d098a0
    bool PreviewScore(const CString& strText, int nCategory, int nOffset, int* pnDuration);   // 0x140d099c0
    void StopPreview();                                     // 0x140d09bc0
    void SendCompose(void* pScore);                         // 0x140d09c10
    void SendScoreText(__int64 nItemUid);                   // 0x140d09c80
    void AddFlags(unsigned nFlags);                         // 0x140d09cf0
    void RemoveFlags(unsigned nFlags);                      // 0x140d09d40
    bool HasOtherFlags(unsigned nFlags);                    // 0x140d09d90
    bool IsBlocked(int nOwner);                             // 0x140d09dd0
    void Clear();                                           // 0x140d09eb0
    void ResetChannel(int nSlot, int nKey);                 // 0x140d0a030
    int FindSlot(unsigned nKey);                            // 0x140d0a080
    int GetSlot(unsigned nKey, Voice& voice);                 // 0x140d0a100
    int AllocSlot(int nKey, Voice& voice);                  // 0x140d0a1a0
    int AddRemote(int nKey, RemoteVoice& voice);            // 0x140d0a310
    void MapSlot(int nKey, int nSlot);                      // 0x140d0a380
    void RemoveSlot(unsigned nKey);                           // 0x140d0a3e0
    void Mute();                                            // 0x140d0a510
    void Unmute();                                          // 0x140d0a560
    void UpdateVolume(bool bForce);                         // 0x140d0a5b0
    int ScaleVolume(int nVolume, int nProgram);             // 0x140d0ac40
    void PlayEvents();                                      // 0x140d0ac80
    void AddRef();                                          // 0x140d0af00
    void Release();                                         // 0x140d0af70
    void CheckPlayState();                                  // 0x140d0b030
    int GetVolume();                                        // 0x140d0b0c0
    void SetVolume(int nVolume);                            // 0x140d0b0e0

public:
    MS2_LAYOUT_FRIEND;
    unsigned m_flags;                                       // +0x18 who keeps the music fade (AddFlags)
    int m_instrument;                                       // +0x1c
    __int64 m_instrumentUid;                                // +0x20 the instrument item
    __int64 m_scoreUid;                                     // +0x28 the score item being played
    bool m_ensemble;                                        // +0x30
    bool m_playing;                                         // +0x31 keyboard play announced
    bool m_performing;                                      // +0x32 a score is playing
    int m_refs;                                             // +0x34 performers heard (music fade)
    bool m_remote;                                          // +0x38 the local performance is remote controlled
    std::map<int, std::pair<int, int> > m_40;               // +0x40 (unused by this unit)
    int m_baseTime;                                         // +0x50 the field's tick base (0x7fffffff = unset)
    CMidiOutput m_midi;                                     // +0x58
    std::map<unsigned, int> m_slotIndex;                    // +0x440 performer key -> channel (unsigned less<>)
    Slot m_slots[16];                                       // +0x450
    std::map<unsigned, RemoteVoice> m_remoteVoices;         // +0x690 (unsigned less<>)
    std::map<unsigned, Unk_ImScoreEvents> m_events;         // +0x6a0 performer owner -> score events
    bool m_muted;                                           // +0x6b0
    int m_volume;                                           // +0x6b4 the auto play volume
    Unk_ImNullableInt m_programOverride;                    // +0x6b8
};
MS2_CHECK_SIZE(CInstrumentManager::Voice, 0x1c);
MS2_CHECK_SIZE(CInstrumentManager::RemoteVoice, 0x20);
MS2_CHECK_SIZE(CInstrumentManager::Slot, 0x24);
MS2_CHECK_SIZE(CInstrumentManager, 0x6c0);
MS2_CHECK_OFFSET(CInstrumentManager, m_flags, 0x18);
MS2_CHECK_OFFSET(CInstrumentManager, m_remote, 0x38);
MS2_CHECK_OFFSET(CInstrumentManager, m_40, 0x40);
MS2_CHECK_OFFSET(CInstrumentManager, m_baseTime, 0x50);
MS2_CHECK_OFFSET(CInstrumentManager, m_midi, 0x58);
MS2_CHECK_OFFSET(CInstrumentManager, m_slotIndex, 0x440);
MS2_CHECK_OFFSET(CInstrumentManager, m_slots, 0x450);
MS2_CHECK_OFFSET(CInstrumentManager, m_remoteVoices, 0x690);
MS2_CHECK_OFFSET(CInstrumentManager, m_events, 0x6a0);
MS2_CHECK_OFFSET(CInstrumentManager, m_muted, 0x6b0);
MS2_CHECK_OFFSET(CInstrumentManager, m_programOverride, 0x6b8);
