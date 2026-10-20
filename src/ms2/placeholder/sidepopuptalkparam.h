// sidepopuptalkparam.h - PLACEHOLDER for SidePopupTalkParam (RTTI .?AVSidePopupTalkParam@@, vftable 0x142e5b3a0,
// 0xd0 bytes, CPtred-derived): the parameter block of a side-popup talk balloon (NPC speech shown in the corner).
// Owning unit is ?\uisidepopuptalk.cpp#3 (ctor 0x140e90ce0, implicit dtor 0x140e910b0, ??_G 0x140e91870). The members
// are named after the AS object keys UISidePopupTalk::AddPopup (0x140e88010) builds from them (the older names given
// by the trigger service are kept; the key is in the comment). NOT an original header.
#pragma once

#include <vector>
#include <atlstr.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"

class SidePopupTalkParam : public CPtred
{
public:
    SidePopupTalkParam();                   // 0x140e90ce0 (the dtor is implicit: 0x140e910b0)

    int m_nKind;                            // +0x18 "type": the ui type (talk 0, movie 1, cutin 2, talkbottom 3)
    std::vector<unsigned> m_script;         // +0x20 string table 0x44 ids; one is picked at random as the text
    CStringW m_strText;                     // +0x38 "msg" (used when m_script is empty)
    CStringA m_strIcon;                     // +0x40 "illust"
    CStringA m_strName;                     // +0x48 "movie" (usm)
    unsigned m_nNpcId;                      // +0x50 "duration" (tick value)
    CStringA m_strSound;                    // +0x58 "voice"
    CStringA m_strScript;                   // +0x60 "sound"
    CStringA m_str68;                       // +0x68 "mapTile" image path (scenestategame 0x11f)
    CStringW m_str70;                       // +0x70 "mapName" display name
    CStringA m_str78;                       // +0x78 "expire"
    CStringW m_strUserValue;                // +0x80 "userValue"
    ATL::CAtlMap<CStringA, CStringW, ATL::CStringElementTraits<CStringA> > m_extra;   // +0x88 extra AS members (name -> value)
};
MS2_CHECK_SIZE(SidePopupTalkParam, 0xd0);
MS2_CHECK_OFFSET(SidePopupTalkParam, m_script, 0x20);
MS2_CHECK_OFFSET(SidePopupTalkParam, m_strText, 0x38);
MS2_CHECK_OFFSET(SidePopupTalkParam, m_nNpcId, 0x50);
MS2_CHECK_OFFSET(SidePopupTalkParam, m_strScript, 0x60);
MS2_CHECK_OFFSET(SidePopupTalkParam, m_extra, 0x88);
