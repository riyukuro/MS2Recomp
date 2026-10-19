// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uinpccontroldialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UINpcControlDialog ("NpcControlDialog", UI type 0x4e81, RTTI .?AVUINpcControlDialog@@, 0x1b0 bytes): the debug "control
// an npc" panel. Packet 0x50 (sub-opcode 4 + npc object id + command) drives the server side; the server answers with
// packet 0x87 (see vfunc_79): kind 6 = the skill list of the npc (m_skills), kind 5 = the AI / stat dump shown in the
// movie ("SetAiText" / "SetStatText"), kind 7 = open the AI debug tool (AiDebugDialog), kind 8 = one AI trace line.
// The movie sends "OnGroupChange" (refill "m_items" with the commands of a group), "OnExecute" (a command with its text
// argument) and "OnStopSkill". Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <map>
#include <utility>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

// A skill of the npc: id and level.
struct Unk_CtlSkill
{
    unsigned nId;
    unsigned nLevel;
};
MS2_CHECK_SIZE(Unk_CtlSkill, 8);

class AiDebugDialog;
class ASObj;
class ASTextField;
class Unk_CtlList;
class Unk_CtlIntArray;

class UINpcControlDialog : public UIDialog
{
public:
    UINpcControlDialog();                               // 0x141a623e0
    virtual ~UINpcControlDialog();                      //  0 0x141a68340 (??_G 0x141a68800)
    virtual CString vfunc_1();                          //  1 0x141a624b0 "NpcControlDialog"
    virtual int vfunc_13();                             // 13 0x141a63390 enter / tab / escape keys
    virtual void OnLoadInit();                          // 20 0x141a63280
    virtual void OnLoadComplete();                      // 22 0x141a632b0 "initData"
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                        // 28 0x141a634d0
    virtual int vfunc_48() { return 0x4e81; }           // 48 0x141a68840 UI type id
    virtual void vfunc_79(void* p);                     // 79 0x141a62500 packet 0x87 from the server

    void FUN_141a63770();                               // "[name] [GameOID : id] [npcID : npc]" into "m_npcName"
    void FUN_141a638c0(int nNpcId);                     // select the controlled npc
    int FUN_141a638e0();                                // "GetLoopCount" of the movie (0 without a movie)
    void FUN_141a63970(unsigned char nCmd, __int64 nValue);     // packet 0x50 / 4 / id / cmd / value
    void FUN_141a63a10(int nCmd, const CStringW& strArgs);      // packet 0x50 / 4 / id / 8: skill list with loop count
    void FUN_141a63ce0(const CString& strGroup);        // refill "m_items" with the commands of a group
    void FUN_141a64ba0(int nCommand, const CStringW& strArg);   // run a command of the list
    void FUN_141a65000();                               // pick an AI xml file and send it (packet 0x50 / 4 / id / 0xd)
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // text field child lookup (a UIDialog member)
    MS2Ptr<Unk_CtlList> FUN_140c02900(const CString& strName);  // bind a list child of the movie

private:
    MS2_LAYOUT_FRIEND;
    std::map<int, Unk_CtlSkill> m_skills;                           // +0x178 key (1000 + n) -> (skill id, level)
    int m_nNpcId;                                       // +0x188 the controlled npc (object id); 0 = none
    CString m_strCurrent;                               // +0x190 the current AI node
    CString m_strPrev;                                  // +0x198 the previous AI node
    MS2Ptr<AiDebugDialog> m_spAi;                       // +0x1a0 the AI debug tool window
};
MS2_CHECK_SIZE(UINpcControlDialog, 0x1b0);
