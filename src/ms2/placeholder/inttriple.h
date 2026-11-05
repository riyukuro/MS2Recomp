#pragma once
// The 12-byte three-int value (trophy / achievement tallies, CBuddy+0xac, Unk_UserProxy+0xd4). It is defined in
// unit_140267ba0, unit_140267c10 and unit_140267e40. Moved here from guilddef_1.h so userproxy.h can share it.
#include "ms2/ms2layout.h"

class COutputStream;
class CInputStream;
struct Unk_IntArr;
class Unk_IntTriple {
public:
    Unk_IntTriple();                                        // 0x140267ba0
    void Clear();                                           // 0x140267bd0
    int Sum();                                              // 0x140267c10
    void Add(int nIndex, int nValue);                       // 0x140267c70
    void ReadArray(Unk_IntArr* pArr);                       // 0x140267d00
    int Get(int nIndex);                                    // 0x140267d70 (3: the sum)
    void WriteArray(Unk_IntArr* pArr);                      // 0x140267dc0
    void WriteTo(COutputStream& out);                       // 0x140267e40
    void ReadFrom(CInputStream& in);                        // 0x140267e70
    void Copy(const Unk_IntTriple& other);                  // 0x140267ea0
    int IsEqual(const Unk_IntTriple& other);                // 0x140267ef0
    void Write(COutputStream& out);                         // 0x140267f50
    void Read(CInputStream& in);                            // 0x140267fb0
    int m_v[3];
};
MS2_CHECK_SIZE(Unk_IntTriple,12);
