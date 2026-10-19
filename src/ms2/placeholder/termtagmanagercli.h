// termtagmanagercli.h - PLACEHOLDER for TermTagManagerCli (RTTI .?AVTermTagManagerCli@@, 0x108 bytes). NOT an original header.
// Bases: TSingleton<TermTagManagerCli> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It keeps the term tags (TermTagContext) the server sends
// with packet 0x137 (unit_140ad5f00): the running ones by id and by name (registered in CGameRule) and the finished
// ones by id and by name. Member and method names are invented.
// Map types (w476, from unit_140ad5f00): the id maps insert make_pair(int, MS2Ptr<TermTagContext>) and hash 4 bytes,
// but their hash/equal_to COMDATs are separate copies from std::hash<int> (0x140645a70) and <unsigned> (0x1402f1e80), so
// the key is another 4-byte type: unsigned long assumed (long or an enum compile to the same bytes). The name maps
// are CGameRule::m_650's type (ctor/dtor 0x140499dd0/0x14049b630, find 0x1404bfc10, erase 0x1404be310, clear
// 0x1404bc830); the id-map ctor/dtor are 0x141495d30/0x141497320 (?\ms2.cpp).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <unordered_map>
#include "ms2/placeholder/termtagcontext.h"
#include "ms2/commonfiles/gamerule.h"          // std::hash<CStringW> of the name maps

class CInPacket;

class TermTagManagerCli : public TSingleton<TermTagManagerCli>
{
public:
    // @0x141496330
    TermTagManagerCli() {}
    // @0x1414976f0
    virtual ~TermTagManagerCli() {}

    void OnPacket(CInPacket& packet);                       // 0x140ad5f00: mode byte 0/1/2
    void OnLoad(CInPacket& packet);                         // 0x140ad5fa0: mode 0, the finished then the running tags
    void OnStart(CInPacket& packet);                        // 0x140ad63d0: mode 1, running tags
    void OnEnd(CInPacket& packet);                          // 0x140ad65f0: mode 2, running -> finished
    void Clear();                                           // 0x140ad68a0: unregisters the running tags
    CMsTime GetEndTime(CStringW name);                      // 0x140ad6970: CMsTime(0) for an unknown name

private:
    MS2_LAYOUT_FRIEND;
    std::unordered_map<unsigned long, MS2Ptr<TermTagContext> > m_runningById;          // +0x08
    std::unordered_map<unsigned long, MS2Ptr<TermTagContext> > m_finishedById;         // +0x48
    std::unordered_map<CStringW, MS2Ptr<TermTagContext> > m_runningByName;   // +0x88
    std::unordered_map<CStringW, MS2Ptr<TermTagContext> > m_finishedByName;  // +0xc8
};
MS2_CHECK_SIZE(TermTagManagerCli, 0x108);
MS2_CHECK_OFFSET(TermTagManagerCli, m_runningById, 0x08);
MS2_CHECK_OFFSET(TermTagManagerCli, m_finishedById, 0x48);
MS2_CHECK_OFFSET(TermTagManagerCli, m_runningByName, 0x88);
MS2_CHECK_OFFSET(TermTagManagerCli, m_finishedByName, 0xc8);
