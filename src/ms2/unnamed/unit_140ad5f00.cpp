// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TermTagManagerCli: the term tag packet (0x137) handler of
// the client and the lookup of a tag's end time, plus the std::unordered_map glue of its four maps (see
// ms2/placeholder/termtagmanagercli.h). File and method names are invented (no assert path, no strings).
// MS2-UNIT: unit_140ad5f00
// MS2-RANGE: 0x140ad5f00-0x140ada4c0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\termtagmanagercli.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/termtagmanagercli.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140ad5f00
void TermTagManagerCli::OnPacket(CInPacket& packet)
{
    int nMode = packet.ReadUInt8();
    switch (nMode) {
    case 0:
        OnLoad(packet);
        break;
    case 1:
        OnStart(packet);
        break;
    case 2:
        OnEnd(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x140AD5F00, TermTagManagerCli, OnPacket, 140, 0x2CD37C08);

// @0x140ad5fa0
void TermTagManagerCli::OnLoad(CInPacket& packet)
{
    size_t nFinished = (unsigned)packet.ReadInt32();
    size_t nRunning = (unsigned)packet.ReadInt32();
    for (size_t i = 0; i < nFinished; ++i) {
        MS2Ptr<TermTagContext> spContext(new TermTagContext());
        spContext->FUN_140866900(packet);
        m_finishedById.insert(std::make_pair(spContext->FUN_140866670(), spContext));
        m_finishedByName.insert(std::make_pair(spContext->FUN_140866690(), spContext));
    }
    for (size_t i = 0; i < nRunning; ++i) {
        MS2Ptr<TermTagContext> spContext(new TermTagContext());
        spContext->FUN_140866900(packet);
        spContext->FUN_140866780();
        m_runningById.insert(std::make_pair(spContext->FUN_140866670(), spContext));
        m_runningByName.insert(std::make_pair(spContext->FUN_140866690(), spContext));
    }
}
MS2_REPLACE_METHOD(0x140AD5FA0, TermTagManagerCli, OnLoad, 1065, 0x44BD2D9D);

// @0x140ad63d0
void TermTagManagerCli::OnStart(CInPacket& packet)
{
    size_t nCount = (unsigned)packet.ReadInt32();
    for (size_t i = 0; i < nCount; ++i) {
        MS2Ptr<TermTagContext> spContext(new TermTagContext());
        spContext->FUN_140866900(packet);
        spContext->FUN_140866780();
        m_runningById.insert(std::make_pair(spContext->FUN_140866670(), spContext));
        m_runningByName.insert(std::make_pair(spContext->FUN_140866690(), spContext));
    }
}
MS2_REPLACE_METHOD(0x140AD63D0, TermTagManagerCli, OnStart, 527, 0xE13B2D98);

// @0x140ad65f0
void TermTagManagerCli::OnEnd(CInPacket& packet)
{
    size_t nCount = (unsigned)packet.ReadInt32();
    for (size_t i = 0; i < nCount; ++i) {
        MS2Ptr<TermTagContext> spContext(new TermTagContext());
        spContext->FUN_140866900(packet);
        spContext->FUN_1408667e0();
        m_runningById.erase(spContext->FUN_140866670());
        m_runningByName.erase(spContext->FUN_140866690());
        m_finishedById.insert(std::make_pair(spContext->FUN_140866670(), spContext));
        m_finishedByName.insert(std::make_pair(spContext->FUN_140866690(), spContext));
    }
}
MS2_REPLACE_METHOD(0x140AD65F0, TermTagManagerCli, OnEnd, 669, 0xF9E7EEFF);

// @0x140ad68a0
void TermTagManagerCli::Clear()
{
    for (std::unordered_map<unsigned long, MS2Ptr<TermTagContext> >::iterator it = m_runningById.begin(); it != m_runningById.end(); ++it)
        it->second->FUN_1408667e0();
    m_runningById.clear();
    m_finishedById.clear();
    m_runningByName.clear();
    m_finishedByName.clear();
}
MS2_REPLACE_METHOD(0x140AD68A0, TermTagManagerCli, Clear, 194, 0xBACFD598);

// @0x140ad6970
CMsTime TermTagManagerCli::GetEndTime(CStringW name)
{
    std::unordered_map<CStringW, MS2Ptr<TermTagContext> >::iterator it = m_runningByName.find(name);
    if (it != m_runningByName.end())
        return it->second->FUN_140866720();
    std::unordered_map<CStringW, MS2Ptr<TermTagContext> >::iterator itFinished = m_finishedByName.find(name);
    if (itFinished != m_finishedByName.end())
        return itFinished->second->FUN_140866720();
    return CMsTime(0);
}
MS2_REPLACE_METHOD(0x140AD6970, TermTagManagerCli, GetEndTime, 319, 0xA2DAF944);
