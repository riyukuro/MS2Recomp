// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uinpcpreviewdialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UINpcPreviewDialog ("NpcPreviewDialog", UI type 0x4e89, RTTI .?AVUINpcPreviewDialog@@, 0x1d8 bytes): the debug "npc
// preview" panel. The movie shows a searchable list of all npc names (npcName.xml); selecting one lists everything the
// npc can say or do (location text, quests, talks, cinematic talks, monologues) in "m_list", and one row shows its
// scripts in "m_output". "onCreateNpc" spawns a client side preview CNpc at the local player; once its animation
// manager is ready (vfunc_15) the list is refilled with its animation names so "onTalk" can play one.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class ASTextField;
class CNpc;
class Unk_NpList;
class Unk_NpTab;

// One row of the script list (0x20): what the row is (m_kind), the shown text and the ids it needs.
//   1 = location header, 2 = quest (m_a quest id, m_b != 0 when this npc starts it), 3 = talk (m_c talk id),
//   4 = cinematic talk (m_c 0 = select talk, 1 = job talk), 5 = monologue (m_c talk id), 6 = animation name.
struct Unk_NpRow
{
    Unk_NpRow();                                        // 0x141a71990
    Unk_NpRow(const Unk_NpRow& o);                      // 0x141a71910
    ~Unk_NpRow();                                       // 0x141a71a20

    unsigned char m_kind;                               // +0x00
    CStringW m_text;                                    // +0x08
    int m_a;                                            // +0x10
    int m_b;                                            // +0x14
    int m_c;                                            // +0x18
};
MS2_CHECK_SIZE(Unk_NpRow, 0x20);

class UINpcPreviewDialog : public UIDialog
{
public:
    UINpcPreviewDialog();                               // 0x141a6e060
    virtual ~UINpcPreviewDialog();                      //  0 0x141a71a40 (??_G 0x141a71b00)
    virtual CString vfunc_1();                          //  1 0x141a6e100 "NpcPreviewDialog"
    virtual void vfunc_15();                            // 15 0x141a6e510 fill the animation names once the preview npc is ready
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                        // 28 0x141a6e190
    virtual void vfunc_67();                            // 67 0x141a6e150 close: drop the preview npc
    virtual int vfunc_48() { return 0x4e89; }           // 48 0x141a71e20 UI type id

    int FUN_141a6e7e0(CStringW strFilter);              // refill "m_npcList" with the names matching the text / id
    int FUN_141a6ec20();                                // load npcName.xml into m_names
    int FUN_141a6ee60(int nNpcId);                      // select an npc: build the rows
    int FUN_141a6fd90(int nRow);                        // show the scripts of a row in "m_output"
    int FUN_141a70b90(int nRow);                        // open the talk of a row in the talk window
    void FUN_141a71050(int nRow);                       // play the animation of a row
    bool FUN_141a711b0();                               // the button bar is on its first tab
    efd::SmartPointer<CNpc> FUN_141a71280();            // the npc of the selected npc id in the field (null = none)
    void FUN_141a713a0();                               // spawn the preview npc
    void FUN_141a717c0();                               // remove the preview npc
    int FUN_141a708e0(int nQuestId, int nTalkId, ATL::CAtlArray<int>& rOut);   // collect a quest talk and the talks it jumps to
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // text field child lookup (a UIDialog member)
    MS2Ptr<Unk_NpList> FUN_140c02900(const CString& strName);   // bind a list child of the movie
    MS2Ptr<Unk_NpTab> FUN_140c02870(const CString& strName);    // bind a tab strip child of the movie

private:
    MS2_LAYOUT_FRIEND;
    int m_nNpcId;                                       // +0x178 the selected npc
    int m_nActorOid;                                    // +0x17c object id of the preview npc (0 = none)
    ATL::CAtlArray<Unk_NpRow> m_rows;                   // +0x180
    ATL::CRBMap<unsigned int, CStringW> m_names;        // +0x1a0 npc id -> name
    int m_bPending;                                     // +0x1d0 the animation names still have to be listed
};
MS2_CHECK_SIZE(UINpcPreviewDialog, 0x1d8);
