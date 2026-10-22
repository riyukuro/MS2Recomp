// soundservice.h - CSoundService (RTTI .?AVCSoundService@@): efd system service (class id 0x0610000e) that owns the FMOD
// Ex system and event system, loads the MS2Sound.fev project and the voice FSB streams, answers sound-name lookups from
// the tag table of the loaded FSB banks and plays net streams (CNetStreamSound). Names are invented from use.
// Recovered from MapleStory2.exe KMS2_DEV x64; owning unit `?\soundservice.cpp` (0x1417ae520-0x1417b73c0, .text$di
// 0x1401017f0-0x140101890; dir client\ms2).
//
// Proven facts: bases are TSingleton<CSoundService> at +0 (vftable 0x142f?, only the deleting dtor) and
// efd::ISystemService at +8 (the 16-slot vftable; the deleting dtor thunk 0x1417b4908 adjusts by -8). sizeof 0x98.
#pragma once
#include <afx.h>
#include <atlstr.h>
#include <list>
#include <map>
#include <vector>
#include <efd/ISystemService.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/fmodwrap.h"

namespace efd { class IDependencyRegistrar; }

class CSoundService;
template <class T> class TSingleton;
template <> class TSingleton<CSoundService>
{
public:
    TSingleton();                                   // 0x1417b3d20 (inline, in the .cpp)
    virtual ~TSingleton() { s_instance = 0; }       // 0x1417b42a0
    static CSoundService* s_instance;               // 0x143abf890
};

// One entry of the tag table: the sub sound of a loaded FSB bank that carries the name.
struct Unk_SoundTag
{
    Unk_SoundTag();                                 // 0x1417b4270 (inline, in the .cpp)
    int m_nSubSound;                                // sub sound index in the bank
    unsigned m_uLength;                             // length in ms
    size_t m_nBank;                                 // index into the bank vector
};
MS2_CHECK_SIZE(Unk_SoundTag, 0x10);

// An int that starts at zero (member at +0x20, ctor 0x140ae79e0).
struct Unk_ZeroInt
{
    Unk_ZeroInt() : m_n(0) {}
    int m_n;
};

// The net stream (a streamed FMOD sound played on its own channel); the owner's FUN_1417b4b70 pumps it.
class CNetStreamSound
{
public:
    CNetStreamSound();                                          // 0x1417b41d0
    virtual ~CNetStreamSound();                                 // 0x1417b4410, ??_G 0x1417b49a0
    virtual int vfunc_1(CSoundService* pService);               // 0x1417b4b70, pumps the stream: 0 ok, -1 finished
    void FUN_1417b4f40(float fVolume);                          // set the channel volume
    void FUN_1417b5000(CSoundService* pService);                // stop and wait for the stream to close

    FMOD::Channel* m_pChannel;                                  // +0x08
    unsigned m_uBuffered;                                       // +0x10 last reported buffer percent
    int m_nState;                                               // +0x14 0 new, 1 playing, 2 buffering, 3 stopped
};
MS2_CHECK_SIZE(CNetStreamSound, 0x18);

class CSoundService : public TSingleton<CSoundService>, public efd::ISystemService
{
    EE_DECLARE_CLASS1(CSoundService, 0x0610000e, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CSoundService();                                            // 0x1417ae520
    virtual ~CSoundService();                                   // 0x1417ae650, ??_G 0x1417b49e0
    virtual const char* GetDisplayName() const;                 // 0x1417ae6e0
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x1417b0650
    virtual efd::AsyncResult OnInit();                          // 0x1417b06b0
    virtual efd::AsyncResult OnTick();                          // 0x1417b0730
    virtual efd::AsyncResult OnShutdown();                      // 0x1417b0d70

    FMOD::System* GetSystem();                              // m_pSystem
    FMOD::EventSystem* GetEventSystem();                         // m_pEventSystem
    FMOD::Sound* GetNetSound();                               // m_pNetSound
    void FUN_1417ae760(float fVolume);                          // set the volume (also of the net stream)
    bool FUN_1417ae990();                                       // (re)acquire the system objects after a device change
    int FUN_1417aea70();                                       // init the event system for the client language
    int FUN_1417aeb40();                                       // create the event system and check the version
    int FUN_1417aec60();                                       // speaker mode, DSP buffer size, software format
    int FUN_1417aee20(CStringA strMediaPath, const char* szLanguage);   // FMOD init, load MS2Sound.fev
    void FUN_1417af340();                                       // unload everything
    void FUN_1417af4f0(CStringA strUrl);                        // create the net stream sound
    void FUN_1417af600();                                       // drop the net stream sound
    void FUN_1417afad0(CStringW strMessage);                    // queue a net stream status message
    void FUN_1417afb50();                                       // build the tag table of the loaded banks
    void FUN_1417aff20(CStringA strMediaPath);                  // open the voice streams of the language
    bool FUN_1417b03d0(const CStringA& strName);                // is the name in the tag table
    int FUN_1417b0440(const CStringA& strName, size_t* pBank);  // sub sound index of the name, -1 if absent
    int FUN_1417b04d0(const CStringA& strName, size_t* pBank);  // length of the name, -1 if absent
    void FUN_1417b0560(const CStringA& strName, FMOD::Sound** ppSound);   // the sub sound of the name
    void FUN_1417ae840(int nFlag);                              // set the channel volumes
    float GetVolume();                                      // m_fVolume

    FMOD::System* m_pSystem;                                    // +0x28
    FMOD::EventSystem* m_pEventSystem;                          // +0x30
    bool m_bLoaded;                                             // +0x38
    std::vector<FMOD::Sound*> m_vecBanks;                       // +0x40 the opened voice FSB streams
    std::map<CStringA, Unk_SoundTag> m_mapTags;                 // +0x58 sub sound name -> tag
    float m_fVolume;                                            // +0x68
    FMOD::Sound* m_pNetSound;                                   // +0x70
    CNetStreamSound* m_pNetStream;                              // +0x78
    std::list<CStringW> m_listMessages;                         // +0x80 net stream status messages
    float m_fMessageTimer;                                      // +0x90
};
MS2_CHECK_SIZE(CSoundService, 0x98);
MS2_CHECK_OFFSET(CSoundService, m_vecBanks, 0x40);
MS2_CHECK_OFFSET(CSoundService, m_mapTags, 0x58);
MS2_CHECK_OFFSET(CSoundService, m_listMessages, 0x80);
MS2_CHECK_OFFSET(CSoundService, m_fMessageTimer, 0x90);
