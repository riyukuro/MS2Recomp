// uishadowexpeditionbossbar.h - UIShadowExpeditionBossBar (RTTI .?AVUIShadowExpeditionBossBar@@, 0x1a8 bytes, UI type
// 0x4f0e): the boss hp gauge of the shadow expedition, a UIScoreDialog (src/ms2/client/ms2/uidarkstreamscoredialog.h)
// that shows a "UIScoreGaugeTypeA/B" movie clip (ASScoreBoardGauge) with a title and a "cur/max" percentage. The
// gauge is fed by FieldGameScoreBoardCli, a 0x10-byte packet listener (opcode 0xe1) that creates and updates the
// right score dialog for its game mode (1 = this one, 2/3 = the dark stream score dialog). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `client\ms2\uishadowexpeditionbossbar.cpp`
// (0x140f9c1e0-0x140f9e200 .text$mn). Header name assumed (the exe has no assert path for it).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members, named by VA where unsure.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidarkstreamscoredialog.h"
#include "ms2/placeholder/asdisplayobject.h"

class CInPacket;

// The gauge clip: a movie clip created from a linkage name ("UIScoreGaugeTypeA" / "UIScoreGaugeTypeB") with a "m_gauge"
// child (a clip that takes "setValue(cur, max, true)"), a "m_title" and a "m_progressText" text.
class ASScoreBoardGauge : public ASMovieClip
{
public:
    ASScoreBoardGauge(CString strLinkage);                          // 0x140f9c800
    void Init();                                                    // 0x140f9c890 bind "m_gauge"
    void FUN_140f9ca30(int nCur, int nMax, CStringW strTitle);      // 0x140f9ca30 set the bar, the title and "xx%"
    ~ASScoreBoardGauge() = default;                                        //  0 0x140f9dca0 (??_G 0x140f9de20)
private:
    MS2Ptr<ASMovieClip> m_gauge;                                    // +0x80 "m_gauge"
};
MS2_CHECK_SIZE(ASScoreBoardGauge, 0x90);

// The score board packet listener: registers for opcode 0xe1 (mode byte, then per mode: 0 = create/show the dialog with
// title/cur/max, 1 = update cur, 2 = close).
class FieldGameScoreBoardCli
{
public:
    FieldGameScoreBoardCli();                                       // 0x140f9c1e0
    ~FieldGameScoreBoardCli();                                      // 0x140f9c280
    void FUN_140f9c300(CInPacket& packet);                          // 0x140f9c300 dispatch on the packet's mode byte
    void FUN_140f9c3a0(CInPacket& packet);                          // 0x140f9c3a0 open: mode, title, cur, max
    void FUN_140f9c520(CInPacket& packet);                          // 0x140f9c520 update the value
    void FUN_140f9c5b0(CInPacket& packet);                          // 0x140f9c5b0 close
    void FUN_140f9c610(CStringW strTitle, int nCur, int nMax);      // 0x140f9c610 create the dialog of the mode
private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                                    // +0x00
    UIScoreDialog* m_pDlg;                                          // +0x08
};
MS2_CHECK_SIZE(FieldGameScoreBoardCli, 0x10);

class UIShadowExpeditionBossBar : public UIScoreDialog
{
public:
    UIShadowExpeditionBossBar();                                    // 0x140f9cc60
    virtual ~UIShadowExpeditionBossBar();                           //  0 0x140f9cd30 (??_G 0x140f9de60)
    virtual CString vfunc_1();                                      //  1 0x140f9cdb0 "ShadowExpeditionBossBar"
    virtual void OnLoadComplete();                                  // 22 0x140f9ceb0
    virtual void vfunc_26();                                        // 26 0x140f9d0f0
    virtual void vfunc_43();                                        // 43 0x140f9ce00
    virtual int vfunc_48();                                         // 48 0x140f9dea0 UI type id
    virtual void vfunc_84(int nCur);                                // 84 0x140f9d280
    virtual void vfunc_85();                                        // 85 0x140f9d2a0
    void FUN_140f9d1f0(int nCur, int nMax);                         // 0x140f9d1f0
    void SetTitle(CStringW strTitle);                          // 0x140f9d230 set the title
private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strTitle;                                            // +0x178
    int m_nCur;                                                     // +0x180
    int m_nMax;                                                     // +0x184
    MS2Ptr<ASScoreBoardGauge> m_pGauge;                             // +0x188
    FieldGameScoreBoardCli m_cli;                                   // +0x198 packet 0xe1 listener
};
MS2_CHECK_SIZE(UIShadowExpeditionBossBar, 0x1a8);
MS2_CHECK_OFFSET(UIShadowExpeditionBossBar, m_strTitle, 0x178);
MS2_CHECK_OFFSET(UIShadowExpeditionBossBar, m_pGauge, 0x188);
MS2_CHECK_OFFSET(UIShadowExpeditionBossBar, m_cli, 0x198);
