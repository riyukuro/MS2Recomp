// uiquizdialog.h - UIQuizDialog (RTTI .?AVUIQuizDialog@@, 0x1d8 bytes, UIDialog, UI id 0x4ee1, swf "QuizDialog"): the
// OX quiz screen shown to the players - a question page (question, category, count-down) and an answer page
// (correct / incorrect mark, answer text). The server feeds it with a packet (FUN_14129a930). Owning unit:
// unit_14129a3c0. Header name assumed from the class name; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"

class CInPacket;

// The count-down clip (0x90 bytes, defined by ascountdowntimer.cpp).
class ASCountDownTimer : public ASMovieClip
{
public:
    ASCountDownTimer(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASCountDownTimer();
    void SetCount(unsigned n);                          // 0x1409b2940
    void SetRemain(unsigned n);                         // 0x1409b2990
    void Tick();                                        // 0x1409b2c80
private:
    unsigned m_nCount, m_nRemain;
    int m_nType;
    unsigned m_nDeadline;
};
MS2_CHECK_SIZE(ASCountDownTimer, 0x90);

class UIQuizDialog : public UIDialog
{
public:
    UIQuizDialog();                                             // 0x14129a3c0
    virtual ~UIQuizDialog();                                    //  0 0x14129a4d0 (??_G 0x14129b7e0)
    virtual CString GetTypeName();                                  //  1 0x14129a590 "QuizDialog"
    virtual void OnLoadComplete();                              // 22 0x14129a5e0
    virtual void vfunc_43();                                    // 43 0x14129a730
    virtual int vfunc_48() { return 0x4ee1; }                   // 48 0x14129b820
    virtual void vfunc_72();                                    // 72 0x14129a7b0 the per-frame count-down

    void FUN_14129a930(CInPacket& packet);                      // the quiz packet
    void FUN_14129ad50();                                       // show the current page
    MS2Ptr<ASCountDownTimer> FUN_14129b5f0(const CString& strName, MS2Ptr<ASCountDownTimer>& out);   // bind a child
    MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out);

    int m_nMode;                                                // +0x178 0 = question page, 1 = answer page
    CStringW m_strQuestion;                                     // +0x180
    CStringW m_strCategory;                                     // +0x188
    CStringW m_strAnswer;                                       // +0x190
    int m_nSeconds;                                             // +0x198
    unsigned m_nDeadline;                                       // +0x19c clock value (ms) the page is hidden at; 0 = none
    bool m_bCorrect;                                            // +0x1a0
    MS2Ptr<ASMovieClip> m_question;                             // +0x1a8
    MS2Ptr<ASMovieClip> m_answer;                               // +0x1b8
    MS2Ptr<ASCountDownTimer> m_countDown;                       // +0x1c8
};
MS2_CHECK_SIZE(UIQuizDialog, 0x1d8);
MS2_CHECK_OFFSET(UIQuizDialog, m_nSeconds, 0x198);
MS2_CHECK_OFFSET(UIQuizDialog, m_countDown, 0x1c8);
