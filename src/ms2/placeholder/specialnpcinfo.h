// specialnpcinfo.h - PLACEHOLDER for SpecialNPCInfo (real name from the RTTI of TPtredDummy<SpecialNPCInfo>), 0x20 bytes:
// a special (event) npc announced by the server. NOT an original header. Same layout as the unit-local copy in
// scenestategame.cpp (which keeps its own definition). Boxed in TPtredDummy<SpecialNPCInfo> behind Unk_BmBoxPtr.
#pragma once

#include "ms2/ms2layout.h"

class CInputStream;
class COutputStream;

struct SpecialNPCInfo
{
    SpecialNPCInfo();                                       // 0x14092c0a0
    void FUN_14092c0f0(COutputStream& out);                 // write (defined in unit_140920cf0, the TU after WinHttpClient)
    void FUN_14092c190(CInputStream& in);                   // read
    int m_nNpcId;                                           // +0x00
    unsigned m_nFieldId;                                    // +0x04
    int m_n08;                                              // +0x08 the level (sort key of the world map icons; read as
                                                            //       an int by worldmapmanager.cpp)
    __int64 m_n10;                                          // +0x10
    int m_n18;                                              // +0x18
};
MS2_CHECK_SIZE(SpecialNPCInfo, 0x20);
