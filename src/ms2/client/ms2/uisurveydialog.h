// uisurveydialog.h - UISurveyDialog (RTTI .?AVUISurveyDialog@@, 0x1b8 bytes, UIDialog, UI id 0x4f1a, swf
// "SurveyDialog"): the player survey box. The server sends the survey (who started it, the title and the answer
// texts); "OnVote" sends the chosen answer back. The packet handlers FUN_140eda1b0 dispatch on the first byte and
// print the vote results to the chat. Owning unit: ?\uisurveydialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;

class UISurveyDialog : public UIDialog
{
public:
    UISurveyDialog();                                           // 0x140ed9b80
    virtual ~UISurveyDialog();                                  //  0 0x140ed9c10 (??_G 0x140edb200)
    virtual CString GetTypeName();                                  //  1 0x140ed9c80 "SurveyDialog"
    virtual void OnLoadComplete();                              // 22 0x140ed9cd0 title and answers
    virtual void vfunc_26();                                    // 26 0x140ed9fe0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140eda000 "OnVote" / "OnClose"
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140edb160 "Close" box answer
    virtual int vfunc_48() { return 0x4f1a; }                   // 48 0x140edb240

    void FUN_140eda1b0(CInPacket& packet);                      // packet dispatcher on the first byte
    void FUN_140eda2b0(int nAnswer);                  // send the vote
    void FUN_140eda360(CInPacket& packet);                      // case 0
    void FUN_140eda3c0(CInPacket& packet);                      // case 2
    void FUN_140eda530(CInPacket& packet);                      // case 1
    void FUN_140eda790(CInPacket& packet);                      // case 3
    void FUN_140eda980(CInPacket& packet);                      // case 4: the survey itself
    void FUN_140edacb0(CInPacket& packet);                      // case 5
    void FUN_140edad50(CInPacket& packet);                      // case 6

private:
    MS2_LAYOUT_FRIEND;
    __int64 m_178;                                              // +0x178 the survey id
    __int64 m_180;                                              // +0x180 the starter id
    bool m_188;                                                 // +0x188
    CStringW m_190;                                             // +0x190 the survey title
    ATL::CAtlArray<CStringW> m_198;                             // +0x198 the answer texts
};
MS2_CHECK_SIZE(UISurveyDialog, 0x1b8);
MS2_CHECK_OFFSET(UISurveyDialog, m_190, 0x190);
