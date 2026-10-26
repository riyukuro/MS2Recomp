// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Date helpers used by the UGC reservation code: the packed
// date+hour key, the broken-down time record (Unk_DateParts, 0x30 bytes) with its builders, an item-data category
// classifier (two variants) and a proportional remainder. Names are invented.
// MS2-UNIT: unit_14088dbf0
// MS2-RANGE: 0x14088dbf0-0x14088e340 .text$mn
#define MS2_THIS_FILE ""
#include <afx.h>
#include "ms2/placeholder/ms2stdafx.h"
#include <atltime.h>
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

CStringW FormatStringId(int nId, const fmt::ArgList& args);     // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)

// The broken-down time record built by FUN_14088e170 from a __time64_t.
struct Unk_DateParts
{
    void* m_nPacked;        // +0x00 date and hour packed as "%08d%05d" (a pointer-sized field: keeps /GS off the locals)
    int m_nDate;            // +0x08 YYYYMMDD
    int m_nHour;            // +0x0c
    void* m_time;           // +0x10 the __time64_t
    int m_nYear;            // +0x18
    int m_nMonth;           // +0x1c
    int m_nDay;             // +0x20
    int m_nDayOfWeek;       // +0x24 0 = Sunday
    int m_nHour2;           // +0x28
    int m_nMinute;          // +0x2c

    CStringW FUN_14088e040();
};
MS2_CHECK_SIZE(Unk_DateParts, 0x30);

CStringW FUN_140b8e760(int nDayOfWeek);     // the weekday name
__int64 FUN_140869440();                    // current time
unsigned __int64 FUN_14088dbf0(int nDate, int nHour);
Unk_DateParts* FUN_14088dfa0(Unk_DateParts* pOut, __int64 t, int nHourOffset);
void FUN_14088e170(Unk_DateParts* pOut, __int64 t);

// @0x14088dbf0
unsigned __int64 FUN_14088dbf0(int nDate, int nHour)
{
    CString str;
    str.Format("%08d%05d", nDate, nHour);
    __int64 n = _atoi64(str);
    return n;
}

// @0x14088dcc0
__int64 FUN_14088dcc0()
{
    Unk_DateParts now;
    FUN_14088dfa0(&now, FUN_140869440(), 0);
    return (__int64)now.m_nPacked;
}

// @0x14088dcf0
int FUN_14088dcf0(MS2Ptr<CItemData> spItemData)
{
    if (spItemData->FUN_14053cbc0())
        return 1;
    else if (spItemData->FUN_14053cb80())
        return 2;
    else if (spItemData->FUN_14053cc80())
        return 7;
    else if (spItemData->FUN_14053d900())
        return 9;
    return 0;
}

// @0x14088de00
int FUN_14088de00(MS2Ptr<CItemData> spItemData)
{
    if (spItemData.get() != 0)
    {
        if (spItemData->FUN_14053cbc0())
            return 1;
        else if (spItemData->FUN_14053cb80())
            return 2;
        else if (spItemData->FUN_14053cc80())
            return 3;
        else if (spItemData->FUN_14053d900())
            return 2;
    }
    return 0;
}

// @0x14088df20
// MS2-FUNCTIONAL: exe keeps extra 64-bit temps/frame around the (nTotal-nElapsed) product; no source form found
__int64 FUN_14088df20(unsigned nElapsed, unsigned nTotal, __int64 nValue)
{
    if (nElapsed == 0)
        return nValue;
    if (nElapsed == nTotal)
        return 0;
    nValue *= (unsigned long long)(nTotal - nElapsed);
    __int64 nDiv = nTotal;
    nValue /= nDiv;   // signed: the exe divides with cqo/idiv
    return nValue;
}

// @0x14088dfa0
Unk_DateParts* FUN_14088dfa0(Unk_DateParts* pOut, __int64 t, int nHourOffset)
{
    __int64 tOut = t + nHourOffset * 3600;
    FUN_14088e170(pOut, tOut);
    return pOut;
}

// @0x14088dff0
Unk_DateParts* FUN_14088dff0(Unk_DateParts* pOut, const Unk_DateParts* pBase, int nHourOffset)
{
    __int64 tOut = nHourOffset * 3600 + (__int64)pBase->m_time;
    FUN_14088e170(pOut, tOut);
    return pOut;
}

// @0x14088e040
CStringW Unk_DateParts::FUN_14088e040()
{
    CStringW strDay = FUN_140b8e760(m_nDayOfWeek);
    CStringW strRet = FormatStringId(0x56a, m_nMonth, m_nDay, strDay);
    return strRet;
}

void FUN_14088e140(Unk_DateParts* pOut, __int64 t);
// @0x14088e0f0
void FUN_14088e0f0(Unk_DateParts* pOut, const Unk_DateParts* pBase, int nHourOffset)
{
    __int64 tOut = nHourOffset * 3600 + (__int64)pBase->m_time;
    FUN_14088e140(pOut, tOut);
}

// @0x14088e140
void FUN_14088e140(Unk_DateParts* pOut, __int64 t)
{
    FUN_14088e170(pOut, t);
}

// @0x14088e170
void FUN_14088e170(Unk_DateParts* p, __int64 t)
{
    p->m_time = (void*)t;
    if (t == 0)
    {
        p->m_nPacked = 0;
        p->m_nDate = 0;
        p->m_nHour = 0;
        p->m_time = 0;
        p->m_nYear = 0;
        p->m_nMonth = 0;
        p->m_nDay = 0;
        p->m_nDayOfWeek = 0;
        p->m_nHour2 = 0;
        p->m_nMinute = 0;
    }
    else
    {
        CMsTime tm((__int64)p->m_time);
        p->m_nYear = tm.GetYear();
        p->m_nMonth = tm.GetMonth();
        p->m_nDay = tm.GetDay();
        p->m_nDayOfWeek = tm.GetDayOfWeek() - 1;
        p->m_nHour2 = tm.GetHour();
        p->m_nMinute = tm.GetMinute();
        CString str;
        str.Format("%04d%02d%02d", p->m_nYear, p->m_nMonth, p->m_nDay);
        p->m_nDate = atoi(str);
        p->m_nHour = p->m_nHour2;
        p->m_nPacked = (void*)FUN_14088dbf0(p->m_nDate, p->m_nHour);
    }
}
