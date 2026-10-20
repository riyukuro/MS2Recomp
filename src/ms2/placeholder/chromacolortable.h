// ChromaColorTable (Razer Chroma colour table owned by ChromaManagerImpl at +0x398; operator new 0x50). Names invented
// from use. Layout proven by unit_140a91030 (ctor 0x140a91030, dtor 0x140a91070).
#pragma once
#include <map>
#include <utility>
#include "ms2/ms2layout.h"

class ChromaColorTable
{
public:
    ChromaColorTable();
    ~ChromaColorTable();
    void InitDefaults();                                // fills m_colors and the level table
    void SetLevel(int level);                           // copies the level's colour pair into m_colors[1..2]
    unsigned GetColor(int nIndex) { return m_colors[nIndex]; }  // 0x140aa6d00 (first emitted by unit_140a93d00)

    unsigned m_colors[16];                              // +0x00
    std::map<int, std::pair<int, int>> m_levels;        // +0x40 (level -> colour pair)
};
MS2_CHECK_SIZE(ChromaColorTable, 0x50);
