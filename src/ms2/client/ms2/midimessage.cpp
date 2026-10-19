// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMidiMessage and the MIDI output device wrappers.
// MS2-UNIT: ?\midimessage.cpp
// MS2-RANGE: 0x140d75430-0x140d7e5f0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBH_N@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x140d76b60 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBH_N@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140d76d60 ; unique
// MS2-PIN: ??$_Buynode@AEAU?$pair@$$CBII@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEAU?$pair@$$CBII@1@@Z 0x140d76df0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140d76f50 ; unique
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x140d77020 ; unique
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x140d772e0 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x140d77610 ; unique
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x140d776a0 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBH_N@std@@PEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@1@AEAU?$pair@$$CBH_N@1@1@Z 0x140d77d60 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBH_N@std@@PEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@1@AEAU?$pair@$$CBH_N@1@PEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@1@@Z 0x140d78d00 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBH_N@std@@PEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBH_N@1@PEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@1@@Z 0x140d79d50 ; unique
// MS2-PIN: ??$_Kfn@$$CBH_N@?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBH_N@1@@Z 0x140d7a170 ; prop
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@1@AEBH@Z 0x140d7a220 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140d7a450 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBII@std@@AEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAU?$pair@$$CBII@1@AEAU31@@Z 0x140d7a840 ; unique
// MS2-PIN: ??A?$map@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@@std@@QEAAAEA_NAEBH@Z 0x140d7b480 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBH_N@1@XZ 0x140d7b4e0 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBII@1@XZ 0x140d7b500 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBH_N@1@XZ 0x140d7b540 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBII@1@XZ 0x140d7b560 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBH_N@1@XZ 0x140d7b5a0 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x140d7bee0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@2@@Z 0x140d7c060 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x140d7ce00 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x140d7cfb0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140d7cfc0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@2@XZ 0x140d7cff0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@2@XZ 0x140d7d000 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@XZ 0x140d7d030 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@XZ 0x140d7d070 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140d7d1c0 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x140d7d1e0 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@2@@Z 0x140d7d230 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBH_N@2@@Z 0x140d7d280 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@2@AEBH@Z 0x140d7e390 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBII@std@@@std@@SAPEAU?$pair@$$CBII@2@AEAU32@@Z 0x140d7e490 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\midimessage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "midimessage.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#pragma comment(lib, "winmm.lib")

// @0x140d75430
CMidiMessage::~CMidiMessage()
{
}

// @0x140d75450
void CMidiMessage::NoteOn(unsigned int ch, unsigned int note, unsigned int vel)
{
    m_msg = ch | 0x90 | (note & 0xff) << 8 | (vel & 0xff) << 16;
}

// @0x140d754a0
void CMidiMessage::NoteOff(unsigned int ch, unsigned int note, unsigned int vel)
{
    m_msg = ch | 0x80 | (note & 0xff) << 8 | (vel & 0xff) << 16;
}

// @0x140d754f0
void CMidiMessage::ProgramChange(unsigned int ch, unsigned int prog)
{
    if (prog == 0x29)
        prog = 0x28;
    else if (prog == 0x2b)
        prog = 0x2a;
    else if (prog == 0x4c)
        prog = 0x4b;
    m_msg = ch | 0xc0 | (prog & 0xff) << 8;
}

// @0x140d75560
void CMidiMessage::ControlChange(unsigned int ch, unsigned int ctrl, unsigned int val)
{
    m_msg = ch | 0xb0 | (ctrl & 0xff) << 8 | (val & 0xff) << 16;
}

// @0x140d755b0
void CMidiMessage::PitchBend(unsigned int ch, unsigned int lsb, unsigned int msb)
{
    m_msg = ch | 0xe0 | (lsb & 0xff) << 8 | (msb & 0xff) << 16;
}

// @0x140d75600
void CMidiMessage::FUN_140d75600(unsigned int ch, unsigned int val)
{
    m_msg = ch | 0xb0 | 7 << 8 | (val & 0xff) << 16;
}

// @0x140d75640
void CMidiMessage::AllNotesOff(unsigned int ch)
{
    m_msg = ch | 0xb0 | 0x7b << 8;
}

// @0x140d75670
void CMidiMessage::ResetControllers(unsigned int ch)
{
    m_msg = ch | 0xb0 | 0x79 << 8;
}

// @0x140d756a0
void CMidiMessage::SetChannel(unsigned int ch)
{
    m_msg &= 0xfffffff0;
    m_msg |= ch;
}

// @0x140d756e0
bool CMidiMessage::IsNote() const
{
    unsigned int cmd = m_msg & 0xf0;
    if (cmd == 0x90 || cmd == 0x80)
        return true;
    return false;
}

// @0x140d75720
bool CMidiMessage::IsProgramChange() const
{
    unsigned int cmd = m_msg & 0xf0;
    if (cmd == 0xc0)
        return true;
    return false;
}

// @0x140d75cb0
bool Unk_MidiQueue::Empty() const
{
    return m_events.empty();
}

// @0x140d75d30
Unk_MidiEvent& Unk_MidiQueue::Front()
{
    return m_events.front();
}

// @0x140d75d50
void Unk_MidiQueue::PopFront()
{
    m_events.pop_front();
}

// @0x140d7b030
Unk_MidiQueue::Unk_MidiQueue()
{
}

// @0x140d7b230
Unk_MidiQueue::~Unk_MidiQueue()
{
}

// @0x140d75750
void Unk_MidiDevice::Update()
{
    DWORD now = GetTickCountMs2();
    for (size_t i = 0; i < 16; ++i)
    {
        Unk_MidiQueue& q = m_queues[i];
        if (q.Empty())
            continue;
        while (q.Front().m_time <= now)
        {
            SendShort(q.Front().m_msg);
            q.PopFront();
        }
    }
}

// @0x140d757f0
MMRESULT Unk_MidiDevice::Open()
{
    MMRESULT r = midiOutOpen(&m_hMidiOut, m_uDeviceId, 0, 0, 0);
    if (r != 0)
        m_hMidiOut = 0;
    return r;
}

// @0x140d75850
MMRESULT Unk_MidiDevice::Close()
{
    MMRESULT r = 0;
    if (m_hMidiOut != 0)
        r = midiOutClose(m_hMidiOut);
    return r;
}

// @0x140d75890
void Unk_MidiDevice::SendShort(unsigned int dwMsg)
{
    midiOutShortMsg(m_hMidiOut, dwMsg);
}

// @0x140d758c0
bool Unk_MidiDevice::IsOpen() const
{
    if (m_hMidiOut == 0)
        return false;
    return true;
}

// @0x140d75e70
CMidiOutput::CMidiOutput()
    : m_device(0)
{
    m_uTimerId = 0;
}

// @0x140d75f20
CMidiOutput::~CMidiOutput()
{
    StopTimer();
}

// @0x140d75fc0
void CMidiOutput::OnTimer()
{
    DWORD now = GetTickCountMs2();
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (int i = 0; i < 16; ++i)
    {
        if (m_channelTracks[i].empty())
            continue;
        Unk_MidiTrack::iterator it = m_channelTracks[i].begin();
        Unk_MidiTrack::iterator last = m_channelTracks[i].end();
        for (; it != last; ++it)
        {
            if (it->first > now)
                break;
            m_device.SendShort(it->second);
        }
        if (it != m_channelTracks[i].begin())
            m_channelTracks[i].erase(m_channelTracks[i].begin(), it);
    }
    std::map<int, Unk_MidiTrack>::iterator mi = m_tracks.begin();
    std::map<int, Unk_MidiTrack>::iterator miLast = m_tracks.end();
    for (; mi != miLast; ++mi)
    {
        Unk_MidiTrack::iterator it = mi->second.begin();
        Unk_MidiTrack::iterator last = mi->second.end();
        for (; it != last; ++it)
        {
            if (it->first > now)
                break;
            if (!m_trackEnabled[mi->first])
                continue;
            m_device.SendShort(it->second);
        }
        if (it != mi->second.begin())
            mi->second.erase(mi->second.begin(), it);
    }
}

// @0x140d76360
void CMidiOutput::StartTimer()
{
    if (!IsOpen())
        return;
    if (m_uTimerId != 0)
        return;
    m_uTimerId = timeSetEvent(0x14, 0x14, TimerProc, (DWORD_PTR)this, 1);
}

// @0x140d763d0
void CMidiOutput::StopTimer()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_uTimerId != 0)
    {
        timeKillEvent(m_uTimerId);
        m_uTimerId = 0;
    }
}

// @0x140d76440
MMRESULT CMidiOutput::Open()
{
    if (!IsOpen())
        return m_device.Open();
    return 0;
}

// @0x140d76480
void CMidiOutput::Close()
{
    StopTimer();
    m_device.Close();
}

// @0x140d764b0
bool CMidiOutput::IsOpen() const
{
    return m_device.IsOpen();
}

// @0x140d764e0
void CMidiOutput::SendMessage(unsigned int ch, unsigned int msg)
{
    CMidiMessage m;
    m.m_msg = msg;
    m.SetChannel(ch);
    m_device.SendShort(m.m_msg);
}

// @0x140d76550
void CMidiOutput::ClearChannel(int ch)
{
    if (ch > 0x10 || ch < 0)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    CMidiMessage off;
    off.AllNotesOff(ch);
    m_device.SendShort(off.m_msg);
    CMidiMessage reset;
    reset.ResetControllers(ch);
    m_device.SendShort(reset.m_msg);
    m_channelTracks[ch].clear();
}

// @0x140d76640
void CMidiOutput::RemoveTrack(int key)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_tracks.erase(key);
    m_trackEnabled.erase(key);
}

// @0x140d766c0
void CMidiOutput::SetChannelTrack(int ch, const Unk_MidiTrack& track)
{
    if (ch > 0x10 || ch < 0)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    ClearChannel(ch);
    m_channelTracks[ch] = track;
}

// @0x140d76760
void CMidiOutput::SetTrack(int key, const Unk_MidiTrack& track)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    RemoveTrack(key);
    m_tracks[key] = track;
    m_trackEnabled[key] = true;
}

// @0x140d76800
void CMidiOutput::SetTrackEnabled(int key, bool b)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_trackEnabled[key] = b;
}

// @0x140d76870
void CALLBACK CMidiOutput::TimerProc(UINT, UINT, DWORD_PTR user, DWORD_PTR, DWORD_PTR)
{
    CMidiOutput* pThis = (CMidiOutput*)user;
    pThis->OnTimer();
}
