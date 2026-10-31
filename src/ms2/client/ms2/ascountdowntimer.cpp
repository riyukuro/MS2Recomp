// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASCountDownTimer: the Scaleform count-down label clip
// (a number that ticks down once a second and the tick sound that goes with it). Original file location unknown.
// MS2-UNIT: ?\ascountdowntimer.cpp
// MS2-RANGE: 0x1409b2880-0x1409b2d70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ascountdowntimer.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
CString FUN_140513200(const char* szFormat, const unsigned int& n); // "{0}" substitution
int FUN_141276180(const CString& strSound, const CString& strArg);  // play a sound
void FUN_140cffde0(const Scaleform::GFx::Value& root, CString strName, int nValue);  // set an int member of a clip

// The count-down clip (0x90 bytes: ASMovieClip plus the counter state).
class ASCountDownTimer : public ASMovieClip
{
public:
    ASCountDownTimer(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASCountDownTimer();
    void SetCount(unsigned n);                          // @0x1409b2940 the highest number it counts down from
    void SetType(int nType);                            // @0x1409b2970 which tick sounds to play
    void SetRemain(unsigned n);                         // @0x1409b2990 restart the count-down at n
    void Update();                                      // @0x1409b29f0 show the current number
    void PlaySound();                                   // @0x1409b2b30 play the tick sound of the current type
    void Tick();                                        // @0x1409b2c80 the per-frame count-down step
private:
    unsigned m_nCount;      // +0x80 (at most 9; the number the clip counts down from)
    unsigned m_nRemain;     // +0x84 (the number currently shown; 0 = already finished)
    int m_nType;            // +0x88 (1 or 2: which tick sounds PlaySound plays)
    unsigned m_nDeadline;   // +0x8c (clock value, ms, at which m_nRemain reaches 0)
};
MS2_CHECK_SIZE(ASCountDownTimer, 0x90);

// @0x1409b2880
ASCountDownTimer::ASCountDownTimer(const Scaleform::GFx::Value& v, int nMovieId)
    : ASMovieClip(v, nMovieId), m_nCount(9), m_nType(1)
{
}

// @0x1409b2910
ASCountDownTimer::~ASCountDownTimer()
{
}
MS2_REPLACE_DTOR(0x1409B2910, ASCountDownTimer, 39, 0xE6A8D6F1);

// @0x1409b2940
void ASCountDownTimer::SetCount(unsigned n)
{
    if (n > 9)
        return;
    m_nCount = n;
}
MS2_REPLACE_METHOD(0x1409B2940, ASCountDownTimer, SetCount, 34, 0x89D96401);

// @0x1409b2970
void ASCountDownTimer::SetType(int nType)
{
    m_nType = nType;
}
MS2_REPLACE_METHOD(0x1409B2970, ASCountDownTimer, SetType, 25, 0x7F044B87);

// @0x1409b2990
void ASCountDownTimer::SetRemain(unsigned n)
{
    m_nRemain = n;
    m_nDeadline = GetTickCountMs2() + m_nRemain * 1000;
    Update();
}
MS2_REPLACE_METHOD(0x1409B2990, ASCountDownTimer, SetRemain, 76, 0x82742935);

// @0x1409b29f0
void ASCountDownTimer::Update()
{
    if (m_nCount < m_nRemain)
        return;
    vfunc_3(1);                                     // SetVisible
    unsigned n = 9 - m_nRemain + 1;
    FUN_140cffde0(FUN_1422bb890(), CString("m_number"), n);
    FUN_140cffde0(FUN_1422bb890(), CString("m_numberOutline"), n);
    vfunc_12(1);
    PlaySound();
}
MS2_REPLACE_METHOD(0x1409B29F0, ASCountDownTimer, Update, 302, 0x2E39BF64);

// @0x1409b2b30
// The sound names are passed as bare literals: an explicit CString("...") temporary is copied through an extra
// pointer slot under /Od, while the implicit conversion for a `const CString&` parameter is built in place.
void ASCountDownTimer::PlaySound()
{
    switch (m_nType)
    {
    case 1:
        FUN_141276180(FUN_140513200("Count0{0}", m_nRemain), "");
        FUN_141276180("Count_NumEffect", "");
        break;
    case 2:
        FUN_141276180("Count_NumEffect", "");
        break;
    }
}
MS2_REPLACE_METHOD(0x1409B2B30, ASCountDownTimer, PlaySound, 327, 0xA6F9975B);

// @0x1409b2c80
void ASCountDownTimer::Tick()
{
    if (m_nRemain == 0)
        return;
    unsigned nNow = GetTickCountMs2();
    if (m_nDeadline <= nNow)
    {
        m_nRemain = 0;
        vfunc_3(0);                                 // SetVisible
    }
    else
    {
        unsigned n = (m_nDeadline - nNow) / 1000 + 1;
        if (m_nRemain != n)
        {
            m_nRemain = n;
            Update();
        }
    }
}
MS2_REPLACE_METHOD(0x1409B2C80, ASCountDownTimer, Tick, 168, 0x98D9F32E);
