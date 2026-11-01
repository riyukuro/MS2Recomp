// talkscript.h - CTalkScript (RTTI .?AVCTalkScript@@, 0x90 bytes, bases CPtred and CValidData<CTalkScript>): one talk of
// an NPC or quest, loaded from Script/Npc and Script/Quest xml or read from a packet. NOT an original header; member
// names come from the xml attribute names (the loaders 0x140857f20 / 0x140858440). Typed over commonfiles/scriptcontent.h; the
// read-only view src/ms2/placeholder/ctalkscript.h serves the talk UI units and is the same 0x90 layout.
#pragma once

// hk1 2026-10-20: storage class of talkscript.cpp's file statics that stand for exe globals (the `// 0x...` ones). The hook DLL
// declares them extern and progress/symbols-manual.tsv binds them to the exe objects, so hooked and exe code share them.
#ifdef MS2_HOOK_DLL
#define MS2_TALKSCRIPT_STATIC extern
#else
#define MS2_TALKSCRIPT_STATIC static
#endif
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/scriptcontent.h"

class CInPacket;

class CTalkScript : public CPtred, public CValidData<CTalkScript>
{
public:
    CTalkScript();                                          // 0x140854ea0
    CTalkScript(CInPacket& in);                             // 0x140854fa0
    virtual ~CTalkScript();                                 // 0x140855050
    void Serialize(COutputStream* out);                     // 0x1408550e0
    void Deserialize(CInPacket& in);                        // 0x140855210
    bool Is88() const;                                      // 0x140855520

    int m_id;                                               // +0x20 "id"
    int m_npcId;                                            // +0x24
    int m_questId;                                          // +0x28
    int m_jobCondition;                                     // +0x2c "jobCondition"
    CStringW m_tag;                                         // +0x30 "tag"
    int m_popupState;                                       // +0x38
    int m_popupProp;                                        // +0x3c
    ATL::CAtlArray<int> m_gotoConditionTalkIds;             // +0x40 "gotoConditionTalkID"
    int m_randomPick;                                       // +0x60 "randomPick"
    int m_pad64;
    ATL::CAtlArray<Unk_TalkContentPtr<CScriptContent> > m_contents;  // +0x68
    bool m_88;                                              // +0x88 read from a packet
};
MS2_CHECK_OFFSET(CTalkScript, m_npcId, 0x24);
MS2_CHECK_OFFSET(CTalkScript, m_tag, 0x30);
MS2_CHECK_OFFSET(CTalkScript, m_gotoConditionTalkIds, 0x40);
MS2_CHECK_OFFSET(CTalkScript, m_contents, 0x68);
MS2_CHECK_SIZE(CTalkScript, 0x90);
