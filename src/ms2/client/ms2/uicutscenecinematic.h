// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicutscenecinematic.h (name assumed from
// the unit path; the .cpp's __FILE__ string is in the exe).
//
// UICutSceneCinematic ("CutSceneCinematic", UI type id 0x4e52, RTTI .?AVUICutSceneCinematic@@, 0x148 bytes): the
// cut-scene overlay driven by the cinematic packets (0x141908290). It shows the cinematic/opening/intro text, the skip
// button, the npc script lines (queued CinematicTalk), the speech balloons above actors (BalloonGroup per actor id) and
// the captions. Primary vftable 0x142f9dd90 (52 slots), IMessageListener-in-UICutSceneCinematic 0x142f9df38.
// Layout cross-checked with the v2525 snapshot (work/ext/v2525/x/ms2decomp/include/ms2/client/UICutSceneCinematic.h);
// BalloonGroup +0x1c (the hide tick) is from the exe. Names: virtuals are Ghidra's vfunc_<slot>; fields are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/cptred.h"

class ASMovieClip;
class CInPacket;
class CMsgBoxData;

class UICutSceneCinematic : public UIHeadUpDisplay
{
public:
    // A speech balloon line above an actor (vftable 0x142f9dd70).
    class BalloonTalk : public CPtred
    {
    public:
        // implicit ctor 0x14190bd10, dtor 0x14190c060 (??_G 0x14190c490): inline COMDATs
        int m_nActorId;                                             // +0x18
        CStringW m_strText;                                         // +0x20
        unsigned m_nStart;                                          // +0x28 show tick
        unsigned m_nEnd;                                            // +0x2c hide tick
        int m_30;                                                   // +0x30
        int m_34;                                                   // +0x34
        CString m_strSound;                                         // +0x38 voice played with the line
    };
    // A queued npc script line (vftable 0x142f9dd60).
    class CinematicTalk : public CPtred
    {
    public:
        // implicit ctor 0x14190be10, dtor 0x14190c100 (??_G 0x14190c550): inline COMDATs
        int m_nNpcId;                                               // +0x18 0: the local player
        CString m_strIllust;                                        // +0x20 portrait name
        CStringW m_strText;                                         // +0x28
        unsigned m_nDuration;                                       // +0x30 ms
        int m_nFlag;                                                // +0x34 the setScript mode
        CString m_strSound;                                         // +0x38
    };
    // The balloon lines of one actor (vftable 0x142f9dd80).
    class BalloonGroup : public CPtred
    {
    public:
        BalloonGroup();                                             // 0x141907570
        // implicit dtor 0x14190c030 (??_G 0x14190c450)
        bool m_bShown;                                              // +0x18 a line is on screen
        unsigned m_nHide;                                           // +0x1c tick the line goes away
        ATL::CAtlArray<MS2Ptr<BalloonTalk> > m_talks;               // +0x20
    };

    UICutSceneCinematic();                                          // 0x141906f30
    virtual ~UICutSceneCinematic();                                 //  0 0x1419072a0 (??_G 0x14190c5d0)
    virtual CString GetTypeName();                                      //  1 0x141907520 "CutSceneCinematic"
    virtual void vfunc_2();                                         //  2 0x1419075c0 show
    virtual void vfunc_3();                                         //  3 0x141907630 hide
    virtual int vfunc_13();                                         // 13 0x141907c80 keys: debug skip / skip prompt
    virtual void OnLoadComplete();                                  // 22 0x141907720 bind m_skip, restore the mode
    virtual void vfunc_26();                                        // 26 0x141907b20 unload
    virtual void vfunc_41(const Scaleform::GFx::Value& root);       // 41 0x14190b060 m_30 = new ASGameEntity
    virtual void vfunc_43();                                        // 43 0x141907b60 stage size
    virtual int vfunc_48() { return 0x4e52; }                       // 48 0x14190ce80 UI type id

    void FUN_141907d60(int nState, CStringW strKey, CStringW strLabel);   // set the skip button (by value: the callee destroys them)
    void FUN_141907f80(int nId, CStringW strText);                  // show a cinematic (mode 1)
    void FUN_141908040(bool bOn);                                   // the cinematic key group on/off
    void FUN_1419080b0();                                           // close everything
    void FUN_141908290(CInPacket& packet);                          // the cinematic packet
    void FUN_141908410();                                           // hideScript
    void FUN_141908470(CStringW strName, CStringW strText, CStringW strIllust, int nFlag);   // setScript (by value)
    void FUN_1419085e0(NotifyObject* pNotice);                      // NotifyRemoveGameObject
    void FUN_141908620(NotifyObject* pNotice);                      // NotifyFadeInComplete
    void FUN_141908690();                                           // drop the script lines
    void FUN_141908720(float fDelta);                               // update
    void FUN_141908750();                                           // update the script line
    void FUN_141908c00();                                           // update the balloons
    void FUN_141908fc0();                                           // skip pressed: confirm or skip
    void FUN_141909100();                                           // skip
    void SendTrigger();                                           // send the skip request
    void FUN_1419092a0(CStringW& strText);                          // resolve a text key
    void FUN_141909340(int nActorId);                               // hide the balloon of an actor
    bool FUN_141909420(int nResult, const CMsgBoxData& box);        // skip confirm answer
    void FUN_141909460(const Scaleform::GFx::FunctionHandler::Params& params);   // skip button click
    void FUN_141909490();                                           // setCinematic
    void FUN_141909550();                                           // setOpening
    void FUN_141909610();                                           // setIntro
    bool FUN_1419096c0();                                           // the cinematic key group is on
    void FUN_141909700(CInPacket& packet);                          // 1 key group
    void FUN_141909750(CInPacket& packet);                          // 2 close
    void FUN_141909780(CInPacket& packet);                          // 3 cinematic
    void FUN_141909880(CInPacket& packet);                          // 6 queue a script line
    void FUN_141909e80(CInPacket& packet);                          // 7 drop the script lines
    void FUN_141909eb0(CInPacket& packet);                          // 8 queue a balloon line
    void FUN_14190a400(CInPacket& packet);                          // 9 drop the balloon lines of an actor
    void FUN_14190a4c0(CInPacket& packet);                          // 4 skip button
    void FUN_14190a6e0(CInPacket& packet);                          // 10 caption
    void FUN_14190ac70(CInPacket& packet);                          // 11 opening
    void FUN_14190aee0(CInPacket& packet);                          // 12 intro
    void FUN_14190afb0(CInPacket& packet);                          // 5 reset the skip button

private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                                    // +0x70 1 cinematic, 2 opening, 3 intro
    int m_nCinematicId;                                             // +0x74
    CStringW m_strText;                                             // +0x78
    bool m_bOpening;                                                // +0x80
    CStringW m_strSkipKey;                                          // +0x88 the key name shown on the skip button
    CStringW m_strSkipLabel;                                        // +0x90
    MS2Ptr<CinematicTalk> m_spTalk;                                 // +0x98 the line on screen
    MS2Ptr<ASMovieClip> m_spSkip;                                   // +0xa8 m_skip
    unsigned m_nTalkEnd;                                            // +0xb8 tick the line goes away
    int m_nVoice;                                                   // +0xbc voice handle of the line
    ATL::CAtlList<MS2Ptr<CinematicTalk> > m_talks;                  // +0xc0
    ATL::CAtlMap<int, MS2Ptr<BalloonGroup> > m_groups;              // +0xf0 by actor id
    int m_nSkipState;                                               // +0x138 0 none, 1 scene, 2 state
    bool m_bSkipped;                                                // +0x13c
    CString m_strSkipMsg;                                           // +0x140 the confirm message suffix
};
MS2_CHECK_SIZE(UICutSceneCinematic::BalloonTalk, 0x40);
MS2_CHECK_OFFSET(UICutSceneCinematic::BalloonTalk, m_strSound, 0x38);
MS2_CHECK_SIZE(UICutSceneCinematic::CinematicTalk, 0x40);
MS2_CHECK_OFFSET(UICutSceneCinematic::CinematicTalk, m_nDuration, 0x30);
MS2_CHECK_SIZE(UICutSceneCinematic::BalloonGroup, 0x40);
MS2_CHECK_OFFSET(UICutSceneCinematic::BalloonGroup, m_talks, 0x20);
MS2_CHECK_SIZE(UICutSceneCinematic, 0x148);
MS2_CHECK_OFFSET(UICutSceneCinematic, m_spSkip, 0xa8);
MS2_CHECK_OFFSET(UICutSceneCinematic, m_talks, 0xc0);
MS2_CHECK_OFFSET(UICutSceneCinematic, m_groups, 0xf0);
MS2_CHECK_OFFSET(UICutSceneCinematic, m_strSkipMsg, 0x140);

// Posted when the player skips the cut scene (vftable 0x142f9df48; the name virtual 0x140db4490 is in another unit).
class NotifyCutSceneCinematicSkip : public NotifyObject
{
public:
    // implicit ctor 0x14190be80, dtor 0x14190c150 (??_G 0x14190c590): inline COMDATs
    virtual CStringW GetTypeName();                                     // 0x140db4490
};
MS2_CHECK_SIZE(NotifyCutSceneCinematicSkip, 0x18);
