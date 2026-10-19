// creservedwordtable.h - PLACEHOLDER for CReservedWordTable (RTTI .?AVCReservedWordTable@@, 0x170 bytes). NOT an original header;
// the member names are invented, recovered in ?\reservedwordtable.cpp (which defines everything declared here).
// Bases: TSingleton<CReservedWordTable> at +0x0.
//
// The table expands "$word$" markers in game texts (string.xml / mail / chat / quest texts): "$MyPCName$", "$item:1000$",
// "$npcName:11000001$", "$male:..,female:..$" ... Every word maps to a formatter function (out, argument, whole text)
// taking the text after the ':' of the marker. m_mapValue holds the player/value words, m_mapObject the object words
// ($item, $map, $npc ...), m_mapBold the same words with the link markup, m_mapPlain the words without markup, and
// m_mapColor the "[y" / "[b" / "[g" colour tags (to <font color=..>).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CReservedWordTable : public TSingleton<CReservedWordTable>
{
public:
    // A word formatter: out receives the text, strArg is the marker's argument, strWhole the text being expanded.
    typedef void (*FnWord)(CStringW& strOut, CStringW strArg, CStringW& strWhole);
    typedef ATL::CAtlMap<CStringW, FnWord, ATL::CStringElementTraits<CStringW> > WordMap;
    typedef ATL::CAtlMap<CStringW, CStringW, ATL::CStringElementTraits<CStringW> > TextMap;

    CReservedWordTable();                                   // 0x1416fa4b0
    virtual ~CReservedWordTable();

    void FUN_1416fb300(CStringW& str);                      // expands the object words, then the value words
    void FUN_1416fb340(CStringW& str);                      // the value words only
    void FUN_1416fb380(CStringW& str);                      // the object words only
    int FUN_1416fb3c0(CStringW& str);                       // the colour tags "[y" ...
    void FUN_1416fb400(CStringW& str, void* pMaid);         // $OwnerName$ / $Maid..$ of a maid (housing) entry
    void FUN_1416fbc20(CStringW& str, class PC* pPc);       // $male..$/$female..$ markers by the gender of pPc (null: local player)
    void FUN_1416fbda0(CStringW& str, int nGender);         // the same by a gender id
    void FUN_1416fbf20(CStringW& str);                      // the bold object words
    void FUN_1416fbf60(CStringW& str, unsigned short nLevel);   // $level$
    CStringW FUN_1416fbfe0(unsigned int nMapId, CStringW strColor);   // a world map link of a map id
    CStringW FUN_1416fc180(CStringW str);                   // the part before ':' of a marker
    CStringW FUN_1416fc250(CStringW str);                   // the part after ':' of a marker
    void FUN_1416fc320(CStringW& str, WordMap& map);        // expands the "$word:arg$" markers of str by map
    void FUN_1416fc540(CStringW& str, TextMap& map);        // expands the "[tag ... ]" colour tags of str by map
    void FUN_1416fc6f0();
    void FUN_1416fc710(CStringW& str, int nCount);          // picks "singular:.." or "plural:.." of the first marker by nCount

private:
    MS2_LAYOUT_FRIEND;
    WordMap m_mapValue;                                     // +0x8
    WordMap m_mapObject;                                    // +0x50
    WordMap m_mapBold;                                      // +0x98
    WordMap m_mapPlain;                                     // +0xe0
    TextMap m_mapColor;                                     // +0x128
};
MS2_CHECK_SIZE(CReservedWordTable, 0x170);
