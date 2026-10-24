// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ChromaColorTable (Razer Chroma colour table) and the
// template glue of its std::map<int, std::pair<int, int>>. Names are invented from use.
// MS2-UNIT: unit_140a91030
// MS2-RANGE: 0x140a91030-0x140a93d00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0HH$0A@@?$pair@HH@std@@QEAA@$$QEAH0@Z 0x140a918e0 ; unique
// MS2-PIN: ??$?0HU?$pair@HH@std@@$0A@@?$pair@$$CBHU?$pair@HH@std@@@std@@QEAA@$$QEAH$$QEAU?$pair@HH@1@@Z 0x140a91980 ; unique
// MS2-PIN: ??$make_pair@HH@std@@YA?AU?$pair@HH@0@$$QEAH0@Z 0x140a924d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$forward@U?$pair@HH@std@@@std@@YA$$QEAU?$pair@HH@0@AEAU10@@Z 0x140a92460
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/chromacolortable.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140a91030
ChromaColorTable::ChromaColorTable()
{
    InitDefaults();
}

// @0x140a91070
ChromaColorTable::~ChromaColorTable()
{
}

typedef std::pair<const int, std::pair<int, int>> Level;

// @0x140a910a0
void ChromaColorTable::InitDefaults()
{
    m_levels.clear();
    m_levels.insert(Level(1, std::make_pair(0xffffff, 0x7f7f00)));
    m_levels.insert(Level(10, std::make_pair(0xd46737, 0xffacff)));
    m_levels.insert(Level(20, std::make_pair(0xf14ae, 0x127aff)));
    m_levels.insert(Level(30, std::make_pair(0xf18da8, 0xffe32f)));
    m_levels.insert(Level(40, std::make_pair(0xf0e181, 0x10cfff)));
    m_levels.insert(Level(50, std::make_pair(0x53ddd7, 0xa8685d)));
    m_levels.insert(Level(60, std::make_pair(0x172b82, 0x91ff2f)));
    m_levels.insert(Level(70, std::make_pair(0x356233, 0x3869ff)));
    m_levels.insert(Level(80, std::make_pair(0xa73058, 0xc0d75)));
    m_levels.insert(Level(90, std::make_pair(0xbb32d3, 0xf1273f)));
    m_levels.insert(Level(110, std::make_pair(0xffae75, 0xffffff)));
    m_levels.insert(Level(100, std::make_pair(0x1b7eff, 0xd24ff)));
    m_colors[0] = 0;
    m_colors[1] = 0xffffff;
    m_colors[2] = 0x7f7f00;
    m_colors[3] = 0x2c17f6;
    m_colors[4] = 0xf68017;
    m_colors[5] = 0x6d9ff;
    m_colors[6] = 0xffe32f;
    m_colors[7] = 0xffffff;
    m_colors[8] = 0x7f;
    m_colors[9] = 0xffb400;
    m_colors[10] = 0xf1273f;
    m_colors[11] = 0xffffff;
    m_colors[12] = 0x303f9;
    m_colors[13] = 0x6d9ff;
    m_colors[14] = 0xff;
}

// @0x140a91700
void ChromaColorTable::SetLevel(int level)
{
    if (m_levels.empty())
        return;
    std::map<int, std::pair<int, int>>::iterator it = m_levels.find(level);
    if (it == m_levels.end())
    {
        it = m_levels.find(1);
        if (it == m_levels.end())
            return;
    }
    m_colors[1] = it->second.first;
    m_colors[2] = it->second.second;
}
