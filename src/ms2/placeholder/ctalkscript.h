// ctalkscript.h - PLACEHOLDER for CTalkScript (RTTI .?AVCTalkScript@@, 0x90 bytes, bases CPtred and CValidData<CTalkScript>;
// ctors 0x140854ea0 (default) / 0x140854fa0 (from a CInPacket), dtor 0x140855050). NOT an original header; its unit is
// ?\talkscript.cpp (not recovered yet). Only the members the talk UI (?\uitalkcinematic.cpp) reads are named; the
// names of the other fields come from the XML loaders 0x140857f20 / 0x140858440.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cinematiccontent.h"

class CInPacket;

// The page list of a script (m_contents) is ATL::CAtlArray<Unk_TalkContentPtr<CScriptContent>>, an array of 16-byte
// handles to the page contents (GetCount 0x14078fae0, operator[] 0x14078f350).

// The condition talk ids (an int array: count 0x140186260).
class Unk_CtsIdList
{
public:
    __int64 FUN_140186260();                                // GetCount
private:
    void* m_0; void* m_8; void* m_10; void* m_18;
};
MS2_CHECK_SIZE(Unk_CtsIdList, 0x20);

class CTalkScript : public CPtred, public CValidData<CTalkScript>
{
public:
    CTalkScript(CInPacket& in);                             // 0x140854fa0
    virtual ~CTalkScript();                                 // 0x140855050
    bool Is88() const;                                      // 0x140855520

    int m_id;                                               // +0x20
    int m_npcId;                                            // +0x24
    int m_questId;                                          // +0x28
    int m_jobCondition;                                     // +0x2c
    CStringW m_tag;                                         // +0x30
    int m_popupState;                                       // +0x38
    int m_popupProp;                                        // +0x3c
    Unk_CtsIdList m_gotoConditionTalkIds;                   // +0x40
    int m_randomPick;                                       // +0x60
    int m_pad64;
    ATL::CAtlArray<Unk_TalkContentPtr<CScriptContent>> m_contents;   // +0x68
    bool m_88;                                              // +0x88
};
MS2_CHECK_OFFSET(CTalkScript, m_npcId, 0x24);
MS2_CHECK_OFFSET(CTalkScript, m_gotoConditionTalkIds, 0x40);
MS2_CHECK_OFFSET(CTalkScript, m_contents, 0x68);
MS2_CHECK_SIZE(CTalkScript, 0x90);
