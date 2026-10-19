// midimessage.h - the MIDI output used by the instrument play mode: CMidiMessage (one short message, RTTI name), the raw
// device wrapper with 16 per-channel deques (Unk_MidiDevice, no RTTI: invented) and CMidiOutput (0x3e8, a name taken
// from the queue notes: the device plus a 20 ms multimedia timer that plays 16 time-sorted event multimaps and per-key
// channel queues). Owning unit: ?\midimessage.cpp (0x140d75430-0x140d7e5f0). CMidiMessage is constructed in an earlier unit.
#pragma once
#include <afx.h>
#include <mmsystem.h>
#include <deque>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"

// 0x10 bytes. vftable (1 slot, ??_G 0x140d13c00). The ctor 0x140d123b0 is an inline COMDAT of an earlier unit.
class CMidiMessage
{
public:
    CMidiMessage();                                         // 0x140d123b0 (out of line, earlier unit)
    virtual ~CMidiMessage();                                // 0x140d75430

    void NoteOn(unsigned int ch, unsigned int note, unsigned int vel);          // 0x140d75450
    void NoteOff(unsigned int ch, unsigned int note, unsigned int vel);         // 0x140d754a0
    void ProgramChange(unsigned int ch, unsigned int prog);                     // 0x140d754f0 remaps GM programs 0x29/0x2b/0x4c
    void ControlChange(unsigned int ch, unsigned int ctrl, unsigned int val);   // 0x140d75560
    void PitchBend(unsigned int ch, unsigned int lsb, unsigned int msb);        // 0x140d755b0
    void FUN_140d75600(unsigned int ch, unsigned int val);                      // 0x140d75600
    void AllNotesOff(unsigned int ch);                                          // 0x140d75640
    void ResetControllers(unsigned int ch);                                     // 0x140d75670
    void SetChannel(unsigned int ch);                                           // 0x140d756a0
    bool IsNote() const;                                                        // 0x140d756e0 note on / note off
    bool IsProgramChange() const;                                               // 0x140d75720

public:
    MS2_LAYOUT_FRIEND;
    int m_unk8;                                             // +0x08
    unsigned int m_msg;                                     // +0x0c the packed short message
};
MS2_CHECK_SIZE(CMidiMessage, 0x10);
MS2_CHECK_OFFSET(CMidiMessage, m_msg, 0xc);

// One queued short message: due tick and the packed message.
struct Unk_MidiEvent
{
    unsigned int m_time;
    unsigned int m_msg;
};

// 0x28 bytes. The per-channel event queue: a deque with thin out-of-line accessors (ctor 0x140d7b030, dtor 0x140d7b230).
class Unk_MidiQueue
{
public:
    Unk_MidiQueue();                                        // 0x140d7b030
    ~Unk_MidiQueue();                                       // 0x140d7b230
    bool Empty() const;                                     // 0x140d75cb0
    Unk_MidiEvent& Front();                                 // 0x140d75d30
    void PopFront();                                        // 0x140d75d50

public:
    MS2_LAYOUT_FRIEND;
    std::deque<Unk_MidiEvent> m_events;
};
MS2_CHECK_SIZE(Unk_MidiQueue, 0x28);

// 0x290 bytes. A midiOut handle and 16 per-channel queues of due events.
class Unk_MidiDevice
{
public:
    explicit Unk_MidiDevice(unsigned int uDeviceId) : m_uDeviceId(uDeviceId), m_hMidiOut(0) {}   // 0x140d7b050
    ~Unk_MidiDevice() {}                                    // 0x140d7b250
    void Update();                                          // 0x140d75750 sends the events that are due
    MMRESULT Open();                                        // 0x140d757f0
    MMRESULT Close();                                       // 0x140d75850
    void SendShort(unsigned int dwMsg);                     // 0x140d75890
    bool IsOpen() const;                                    // 0x140d758c0

public:
    MS2_LAYOUT_FRIEND;
    unsigned int m_uDeviceId;                               // +0x00
    HMIDIOUT m_hMidiOut;                                    // +0x08
    Unk_MidiQueue m_queues[16];                             // +0x10
};
MS2_CHECK_SIZE(Unk_MidiDevice, 0x290);

typedef std::multimap<unsigned int, unsigned int> Unk_MidiTrack;   // tick -> packed message

// 0x3e8 bytes.
class CMidiOutput
{
public:
    CMidiOutput();                                          // 0x140d75e70
    ~CMidiOutput();                                         // 0x140d75f20
    void OnTimer();                                         // 0x140d75fc0 plays the tracks whose events are due
    void StartTimer();                                      // 0x140d76360
    void StopTimer();                                       // 0x140d763d0
    MMRESULT Open();                                        // 0x140d76440
    void Close();                                           // 0x140d76480
    bool IsOpen() const;                                    // 0x140d764b0
    void SendMessage(unsigned int ch, unsigned int msg);    // 0x140d764e0
    void ClearChannel(int ch);                              // 0x140d76550
    void RemoveTrack(int key);                              // 0x140d76640
    void SetChannelTrack(int ch, const Unk_MidiTrack& track);   // 0x140d766c0
    void SetTrack(int key, const Unk_MidiTrack& track);     // 0x140d76760
    void SetTrackEnabled(int key, bool b);                  // 0x140d76800
    static void CALLBACK TimerProc(UINT, UINT, DWORD_PTR user, DWORD_PTR, DWORD_PTR);   // 0x140d76870

public:
    MS2_LAYOUT_FRIEND;
    Unk_MidiDevice m_device;                                // +0x00
    Unk_MidiTrack m_channelTracks[16];                      // +0x290
    std::map<int, Unk_MidiTrack> m_tracks;                  // +0x390
    std::map<int, bool> m_trackEnabled;                     // +0x3a0
    CLockCriticalSection m_lock;                            // +0x3b0
    UINT m_uTimerId;                                        // +0x3e0
};
MS2_CHECK_SIZE(CMidiOutput, 0x3e8);
MS2_CHECK_OFFSET(CMidiOutput, m_tracks, 0x390);
MS2_CHECK_OFFSET(CMidiOutput, m_lock, 0x3b0);
