// Recovered UITriggerEditorDialog (UI type 0x4e6b, movie "TriggerEditorDialog"): the user cube-trigger script editor of a
// house (states / actions / conditions edited in the movie, validated and sent to the server, loaded from or saved to
// ./Data/Xml/Trigger/). RTTI .?AVUITriggerEditorDialog@@ (0x143a84778): vftable 0x142feafa8, IMessageListener +0x18
// 0x142feb250; 0x1d8 bytes (sized delete in 0x141b32420). Member and helper names are invented (the v2525 snapshot's
// guesses where they fit); the slot overrides keep Ghidra's vfunc_<slot> names like every UIDialog subclass.
#pragma once
#include <vector>
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/triggercli.h"

class ASButton;
class CMsgBoxData;

class UITriggerEditorDialog : public UIDialog
{
public:
    // One line of the validation report (0x141b31f90 builds it, dtor 0x141b32110; 0x18 bytes).
    struct Message
    {
        Message(CStringW strCategory, CStringW strText, int nKind)    // 0x141b31f90
        {
            m_strCategory = strCategory;
            m_strText = strText;
            m_nKind = nKind;
        }
        CStringW m_strCategory;                                         // +0x00 "SystemError", ...
        CStringW m_strText;                                             // +0x08
        int m_nKind;                                                    // +0x10
        CStringW FUN_1408f4c40();                                       // 0x1408f4c40 the report line (userproxy.cpp's Unk_UserProxyTriggerText, same shape)
    };

    UITriggerEditorDialog();                                            // 0x141b29f20
    // implicit virtual destructor                                   //  0 0x141b32140 (??_G 0x141b32420; no vptr re-store)
    virtual CString vfunc_1();                                          //  1 0x141b2a0a0 "TriggerEditorDialog"
    virtual int vfunc_13();                                             // 13 0x141b2b3d0 per-frame keys (escape asks to close, Tab folds)
    virtual void OnLoadComplete();                                      // 22 0x141b2aa10
    virtual void vfunc_26();                                            // 26 0x141b2a180 unload: drop the buttons
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b2a1e0
    virtual void vfunc_43();                                            // 43 0x141b2b3a0
    virtual int vfunc_48() { return 0x4e6b; }                           // 48 (COMDAT 0x141b32480)
    virtual void vfunc_67();                                            // 67 0x141b2a0f0 close: tell the server (0x2e/7)

    MS2Ptr<ASButton> FUN_140bc6d10(const CString& strName, MS2Ptr<ASButton>& out);   // 0x140bc6d10 bind a button child
    bool FUN_141b2b140(int nResult, const CMsgBoxData& data);          // 0x141b2b140 close answer
    bool FUN_141b2b180(int nResult, const CMsgBoxData& data);          // 0x141b2b180 reset answer
    bool FUN_141b2b200(int nResult, const CMsgBoxData& data);          // 0x141b2b200 apply answer
    bool SendTriggerMode22(int nResult, const CMsgBoxData& data);          // 0x141b2b230 delete answer (0x2f/0x16)
    bool FUN_141b2b2b0(int nResult, const CMsgBoxData& data);          // 0x141b2b2b0 remove state answer
    void FUN_141b2b600();                                               // 0x141b2b600 "FoldDialog"
    void FUN_141b2b6e0();                                               // 0x141b2b6e0 "UnfoldDialog"
    int FUN_141b2b7e0(CFileSystem::BufferPtr spBuffer);                 // 0x141b2b7e0 the script downloaded
    void FUN_141b2b930();                                               // 0x141b2b930 refresh the install list
    void FUN_141b2b9a0(CString strCube, int nCubeId);                  // 0x141b2b9a0
    void FUN_141b2ba00(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b2ba00 reset
    void FUN_141b2ba30(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b2ba30 ask to delete
    void FUN_141b2bb10(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141b2bb10 ask to reset
    int OpenTriggerFile();                                                // 0x141b2bbf0 load a script file
    void FUN_141b2be80(Scaleform::GFx::Value& state);                   // 0x141b2be80 one state of the movie
    int SaveTriggerFile();                                                // 0x141b2d0d0 save the script file
    void SendTriggerMode13();                                               // 0x141b2d340 send the script (0x2f/0xd)
    void FUN_141b2d570();                                               // 0x141b2d570 verify, then send
    void FUN_141b2d870();                                               // 0x141b2d870 the install list
    void FUN_141b2dd80();                                               // 0x141b2dd80 the states of the script
    POINT FUN_141b2f430(int nX, int nY);                                // 0x141b2f430 keep a state inside the canvas
    void FUN_141b2f140(const std::vector<Message>& messages);          // 0x141b2f140 the report
    void FUN_141b2f510();                                               // 0x141b2f510 new script

    MS2_LAYOUT_FRIEND;
    CString m_strFileName;                                              // +0x178 file name (no directory)
    MS2Ptr<TriggerCli> m_spTrigger;                                     // +0x180
    CString m_strCube;                                                  // +0x190
    int m_nCubeId;                                                      // +0x198
    int m_bFolded;                                                      // +0x19c
    unsigned int m_nLastSend;                                           // +0x1a0 tick of the last send
    MS2Ptr<ASButton> m_spButton1;                                       // +0x1a8
    MS2Ptr<ASButton> m_spButton2;                                       // +0x1b8
    MS2Ptr<ASButton> m_spButton3;                                       // +0x1c8
};
MS2_CHECK_SIZE(UITriggerEditorDialog::Message, 0x18);
MS2_CHECK_SIZE(UITriggerEditorDialog, 0x1d8);
MS2_CHECK_OFFSET(UITriggerEditorDialog, m_strFileName, 0x178);
MS2_CHECK_OFFSET(UITriggerEditorDialog, m_spTrigger, 0x180);
MS2_CHECK_OFFSET(UITriggerEditorDialog, m_nCubeId, 0x198);
MS2_CHECK_OFFSET(UITriggerEditorDialog, m_spButton1, 0x1a8);
MS2_CHECK_OFFSET(UITriggerEditorDialog, m_spButton3, 0x1c8);
