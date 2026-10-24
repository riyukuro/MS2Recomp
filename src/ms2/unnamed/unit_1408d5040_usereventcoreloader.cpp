// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Tail of the user event data file: Unk_EventCore (the event/mail
// header of usereventcontext.h) loads itself from a <mail> xml element and sets / reads its end time. File name is
// invented (the range belongs to the end of ?\userconditioneventdata.cpp).
// MS2-UNIT: unit_1408d5040
// MS2-RANGE: 0x1408d5040-0x1408d5470 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/usereventcontext.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

Unk_EventTime FUN_140718950(const CString&);   // "YYYY-MM-DD hh:mm:ss" text -> time
__int64 FUN_140869440();                        // the current time
void AddDays(CMsTime& time, long days);         // 0x14086a7e0 (commonfiles/timeutil.cpp)

// Unk_EventTime is the 16-byte CMsTime (usereventcontext.h only needs its assignment and Get).
MS2_CHECK_SIZE(Unk_EventTime, 0x10);

// @0x1408d5040
bool Unk_EventCore::FUN_1408d5040(Unk_140165cf0* pNode)
{
    CStringA strTitle;
    CStringA strContent;
    CStringA strSender;
    int nMailCode = 0;
    int nDuration = 0;
    __int64 nMeso = 0;
    __int64 nMerat = 0;
    __int64 nMeratRed = 0;
    int nMailType = 0;
    if (FUN_1408733e0(pNode, "title", strTitle) == 0)
    {
        name = (const char*)strTitle;
    }
    if (FUN_1408733e0(pNode, "content", strContent) == 0)
    {
        text = (const char*)strContent;
    }
    if (FUN_1408733e0(pNode, "sender", strSender) == 0)
    {
        extra = (const char*)strSender;
    }
    if (FUN_1408731e0(pNode, "mailtype", nMailType) == 0)
    {
        type = nMailType;
    }
    if (FUN_1408731e0(pNode, "mailcode", nMailCode) == 0)
    {
        id = nMailCode;
    }
    if (FUN_1408731e0(pNode, "duration", nDuration) == 0)
    {
        FUN_1408d5390(nDuration);
    }
    if (FUN_1408732e0(pNode, "meso", nMeso) == 0)
    {
        a = nMeso;
    }
    if (FUN_1408732e0(pNode, "merat", nMerat) == 0)
    {
        b = nMerat;
    }
    if (FUN_1408732e0(pNode, "merat_red", nMeratRed) == 0)
    {
        c = nMeratRed;
    }
    CStringA strEndDate;
    if (FUN_1408733e0(pNode, "enddate", strEndDate) == 0)
    {
        if (strEndDate.GetLength() > 0)
        {
            Unk_EventTime endTime = FUN_140718950(strEndDate);
            FUN_1408d5320(endTime);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1408D5040, Unk_EventCore, FUN_1408d5040, 721, 0xB684B24F);

// @0x1408d5320
void Unk_EventCore::FUN_1408d5320(const Unk_EventTime& endTime)
{
    time = endTime;
    CMsTime zero(0);
    if (reinterpret_cast<CMsTime&>(time) != zero)
    {
        mode = 0;
    }
}
MS2_REPLACE_METHOD(0x1408D5320, Unk_EventCore, FUN_1408d5320, 94, 0xC7602ABC);

// @0x1408d5390
void Unk_EventCore::FUN_1408d5390(int nMode)
{
    const int nMax = 100;
    mode = nMode;
    if (mode != 0)
    {
        if (nMode > nMax)
        {
            nMode = nMax;
        }
        reinterpret_cast<CMsTime&>(time) = 0;
    }
}
MS2_REPLACE_METHOD(0x1408D5390, Unk_EventCore, FUN_1408d5390, 83, 0x4B16BFF8);

// @0x1408d53f0
CMsTime Unk_EventCore::FUN_1408d53f0() const
{
    if (mode != 0)
    {
        CMsTime now(FUN_140869440());
        AddDays(now, mode);
        return now;
    }
    return reinterpret_cast<const CMsTime&>(time);
}
MS2_REPLACE_METHOD(0x1408D53F0, Unk_EventCore, FUN_1408d53f0, 115, 0xD48E5C39);
