// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uidebugguidedialog.h (name assumed: the
// .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIDebugGuideDialog ("DebugGuideDialog"): the GM command helper. Two lists (command groups on the left, the commands of
// the selected group on the right), an explanation text, an execute button (prints the command to the chat), a
// multi-execute button (sends it to the server, packet 0x50 mode 7) and an input box for the argument. The commands come
// from ./Data/XmlDebug/DebugCommand[_<locale>].xml and DebugCommandCustom.xml. Function keys F1-F10 (keys 0x3b..0x44)
// run the first ten commands of the selected group. Packet 0x87 (a list of command + description strings) is printed to
// the chat and the banner.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; the others are invented from use.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;
class Unk_140165cf0;
class Unk_DebugGuideList;
class Unk_DebugGuideButton;
class Unk_DebugGuideInput;
class ASMovieClip;

// <v cmd="" useArg=""/> (or the "cmd" attribute of a <CommandSet>): one argument-taking invocation.
struct Unk_DebugGuideArg
{
    Unk_DebugGuideArg(Unk_140165cf0* pElem);                    // 0x141286410
    Unk_DebugGuideArg(CStringW strCmd, bool bUseArg);           // 0x141286460
    ~Unk_DebugGuideArg();                                       // 0x14128c740
    Unk_DebugGuideArg(Unk_DebugGuideArg&&) = default;
    Unk_DebugGuideArg(const Unk_DebugGuideArg&) = default;
    void Read(Unk_140165cf0* pElem);                            // 0x1412864c0
    CStringW m_strCmd;                                          // +0x00 "cmd"
    bool m_bUseArg;                                             // +0x08 "useArg": the input box text is appended
};
MS2_CHECK_SIZE(Unk_DebugGuideArg, 0x10);

// <CommandSet name="" desc="">: one entry of the right list.
struct Unk_DebugGuideCommand
{
    Unk_DebugGuideCommand();                                    // 0x14128c480
    ~Unk_DebugGuideCommand();                                   // 0x14128c760
    Unk_DebugGuideCommand(Unk_DebugGuideCommand&&) = default;
    Unk_DebugGuideCommand(const Unk_DebugGuideCommand&) = default;
    void Read(Unk_140165cf0* pElem);                            // 0x141286520
    void AddArg(const Unk_DebugGuideArg& rArg);                    // 0x1412866e0
    CStringW m_strName;                                         // +0x00 "name"
    CStringW m_strDesc;                                         // +0x08 "desc"
    std::vector<Unk_DebugGuideArg> m_args;                      // +0x10
};
MS2_CHECK_SIZE(Unk_DebugGuideCommand, 0x28);

// <Group name="" charOnlyName="">: one entry of the left list.
struct Unk_DebugGuideGroup
{
    Unk_DebugGuideGroup(Unk_140165cf0* pElem);                  // 0x141286710
    ~Unk_DebugGuideGroup();                                     // 0x14128c7a0
    Unk_DebugGuideGroup(Unk_DebugGuideGroup&&) = default;
    Unk_DebugGuideGroup(const Unk_DebugGuideGroup&) = default;
    void Read(Unk_140165cf0* pElem);                            // 0x141286780
    CStringW m_strName;                                         // +0x00 "name"
    CStringW m_strCharOnly;                                     // +0x08 "charOnlyName": shown only to this character
    std::vector<Unk_DebugGuideCommand> m_commands;              // +0x10
};
MS2_CHECK_SIZE(Unk_DebugGuideGroup, 0x28);

class UIDebugGuideDialog : public UIDialog
{
public:
    UIDebugGuideDialog();                                       // 0x141286850
    virtual ~UIDebugGuideDialog();                              //  0 0x141286a10 (??_G 0x14128c9d0)
    virtual CString GetTypeName();                                  //  1 0x141286ba0
    virtual void OnLoadInit();                                  // 20 0x141286bf0
    virtual void vfunc_26();                                    // 26 0x141287b50
    virtual int vfunc_13();                                     // 13 0x141287bf0 function keys
    virtual int vfunc_48() { return 0x4ea3; }                   // 48 (COMDAT 0x14128c9f0)

    void OnPacket(CInPacket& iPacket);                          // 0x141287c80
    void OnSelectGroup(const Scaleform::GFx::FunctionHandler::Params& rParams);     // 0x141287ed0
    void OnSelectCommand(const Scaleform::GFx::FunctionHandler::Params& rParams);   // 0x141287f00
    void OnExecute(const Scaleform::GFx::FunctionHandler::Params& rParams);         // 0x141287f30
    void OnMultiExecute(const Scaleform::GFx::FunctionHandler::Params& rParams);    // 0x141287f60
    void OnDoubleClick(const Scaleform::GFx::FunctionHandler::Params& rParams);     // 0x141287f90
    void LoadXml(CString strPath);                              // 0x141287fc0
    void FillGroups();                                          // 0x141288200
    void FillCommands();                                        // 0x141288320
    void ShowExplain();                                         // 0x141288570
    bool PrintCommand(int nIndex);                               // 0x141288770 -1 = the selected command
    bool SendCommand(int nIndex);                                // 0x141288a70
    void PrintLine(CStringW strName, CStringW strArg);          // 0x141288d00

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_DebugGuideList> m_leftList;                      // +0x178 "m_leftList"
    MS2Ptr<Unk_DebugGuideList> m_rightList;                     // +0x188 "m_rightList"
    MS2Ptr<ASMovieClip> m_movie;                                // +0x198 (double click)
    MS2Ptr<Unk_DebugGuideButton> m_unused;                      // +0x1a8
    MS2Ptr<Unk_DebugGuideButton> m_executeButton;               // +0x1b8 "m_executeButton"
    MS2Ptr<Unk_DebugGuideButton> m_multiExecuteButton;          // +0x1c8 "m_multiExecuteButton"
    MS2Ptr<Unk_DebugGuideInput> m_input;                        // +0x1d8 "m_input"
    std::vector<Unk_DebugGuideGroup> m_groups;                  // +0x1e8
};
MS2_CHECK_SIZE(UIDebugGuideDialog, 0x200);
MS2_CHECK_OFFSET(UIDebugGuideDialog, m_leftList, 0x178);
MS2_CHECK_OFFSET(UIDebugGuideDialog, m_input, 0x1d8);
MS2_CHECK_OFFSET(UIDebugGuideDialog, m_groups, 0x1e8);
