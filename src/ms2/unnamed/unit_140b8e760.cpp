// unit_140b8e760 - the client's date/time text helpers (weekday names, "month/day" texts from the string table, the
// day-of-week list of a bitset, the Korean digit-group number text, "mm:ss" spans, the am/pm clock text). Source file
// name unknown (no assert or __FILE__ in the range); every function name is invented. The range also holds the
// COMDATs first instantiated here: the FUN_14028dfa0 string-key wrappers for <int,int,int>, <int,int,int,int> and
// <long,long>, std::wstringstream and its operator<<(const wchar_t*), CAtlArray<CStringW>::SetAt, the Unk_PartyBits
// any()/none()/size() members and memmove_s.
//
// MS2-UNIT: unit_140b8e760
// MS2-RANGE: 0x140b8e760-0x140b914f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/placeholder/ms2stdafx.h"
#include <atltime.h>
#include <atlcoll.h>
#include <sstream>
#include <algorithm>
#include "ms2/ms2format.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/partybits.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/commonutil.h"
#include "ms2/commonfiles/timer.h"
#define MS2_THIS_FILE ""
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CStringW FUN_14028de60(int nStringId);                                  // a common string by id
CStringW FormatStringId(int nId, const fmt::ArgList& args);             // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)
CStringTable* FUN_1401a9d70();                                          // the string table singleton
int FUN_1406516a0();                                                    // client language
int FUN_1406516b0();                                                    // the language / region id
int FUN_1406516d0(int nLanguage);                                       // the digit-group size of a language
__int64 FUN_140718320(const CStringW& str);                             // the number of a digit string
CStringW FUN_1409404f0(__int64 nValue);                                 // a number with separators
CStringW FUN_14083cb20(const CStringW& strNumber);                      // digits grouped with commas
CStringW FUN_1409eaa20(CStringW strKey, const CStringW& a1, const CStringW& a2, const CStringW& a3);   // FUN_14028dfa0<CStringW x3>

CStringW FUN_140b8ee70(int nDayOfWeek);
CStringW FUN_140b8f000(const CMsTime& time);
CStringW FUN_140b8f230(int nDayOfWeek);

// The weekday name of a 0-based day (0 = Sunday).
// @0x140b8e760
CStringW FUN_140b8e760(int nDayOfWeek)
{
    return FUN_140b8f230(nDayOfWeek + 1);
}
MS2_REPLACE(0x140B8E760, FUN_140b8e760, 60, 0x3F791677);

// "yyyy/mm/dd" text.
// @0x140b8e7b0
CStringW FUN_140b8e7b0(const CMsTime& time)
{
    return FUN_14028dfa0(L"s_common_year_month_day", time.GetYear(), time.GetMonth(), time.GetDay());
}
MS2_REPLACE(0x140B8E7B0, FUN_140b8e7b0, 153, 0xF4DC5D66);

// "yyyy/mm/dd hh" text.
// @0x140b8e850
CStringW FUN_140b8e850(const CMsTime& time)
{
    return FUN_14028dfa0(L"s_common_year_month_day_hour", time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour());
}
MS2_REPLACE(0x140B8E850, FUN_140b8e850, 177, 0xB3A40AE2);

// "mm/dd" text.
// @0x140b8e910
CStringW FUN_140b8e910(const CMsTime& time)
{
    return FUN_14028dfa0(L"s_common_month_day", time.GetMonth(), time.GetDay());
}
MS2_REPLACE(0x140B8E910, FUN_140b8e910, 129, 0x27596ECF);

// "mm/dd (weekday)" text.
// @0x140b8e9a0
CStringW FUN_140b8e9a0(const CMsTime& time)
{
    return FormatStringId(0x981, time.GetMonth(), time.GetDay(), FUN_140b8f000(time));
}
MS2_REPLACE(0x140B8E9A0, FUN_140b8e9a0, 156, 0x8D4DAA75);

// "start ~ end" text of a time range.
// @0x140b8ea50
CStringW FUN_140b8ea50(TimeRange& range)
{
    return StringFormat(L"{0} ~ {1}", FUN_140b8e9a0(CMsTime(range.FUN_140868f20())), FUN_140b8e9a0(CMsTime(range.FUN_140868f40())));
}
MS2_REPLACE(0x140B8EA50, FUN_140b8ea50, 222, 0x18744034);

// "mm/dd" text with " hh<hour>" appended when the hour is not 0.
// @0x140b8eb40
CStringW FUN_140b8eb40(const CMsTime& time)
{
    CStringW str = FUN_14028dfa0(L"s_common_month_date", time.GetMonth(), time.GetDay());
    if (time.GetHour() != 0) {
        CStringW strHour = StringFormat(L" {0}{1}", time.GetHour(), FUN_14028de60(0x5cd));
        str.Append(strHour);
    }
    return str;
}
MS2_REPLACE(0x140B8EB40, FUN_140b8eb40, 315, 0xD6B68D8C);

// "mm/dd hh:mm" text.
// @0x140b8ec90
CStringW FUN_140b8ec90(const CMsTime& time)
{
    CStringW str = FUN_14028dfa0(L"s_common_month_date_hour_min", time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute());
    return str;
}
MS2_REPLACE(0x140B8EC90, FUN_140b8ec90, 232, 0x9DE062DE);

// "mm/dd hh:mm:ss" text.
// @0x140b8ed80
CStringW FUN_140b8ed80(const CMsTime& time)
{
    return FUN_14028dfa0(L"s_common_month_date_hour_min_sec", time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
}
MS2_REPLACE(0x140B8ED80, FUN_140b8ed80, 222, 0x34EC45CA);

// The short weekday name of a 1-based day (1 = Sunday); empty for other values.
// @0x140b8ee70
CStringW FUN_140b8ee70(int nDayOfWeek)
{
    switch (nDayOfWeek) {
    case 1: return FUN_14028de60(0x563);
    case 2: return FUN_14028de60(0x564);
    case 3: return FUN_14028de60(0x565);
    case 4: return FUN_14028de60(0x566);
    case 5: return FUN_14028de60(0x567);
    case 6: return FUN_14028de60(0x568);
    case 7: return FUN_14028de60(0x569);
    default: return L"";
    }
}
MS2_REPLACE(0x140B8EE70, FUN_140b8ee70, 356, 0x98D151BA);

// The short weekday name of a time.
// @0x140b8f000
CStringW FUN_140b8f000(const CMsTime& time)
{
    return FUN_140b8ee70(time.GetDayOfWeek());
}
MS2_REPLACE(0x140B8F000, FUN_140b8f000, 65, 0x1CDF6789);

// The short weekday names of the set bits 1..7, joined with ", ".
// @0x140b8f050
CStringW FUN_140b8f050(Unk_PartyBits days)
{
    if (days.FUN_140b91330())
        return L"";
    std::wstringstream ss;
    bool bFirst = true;
    for (unsigned i = 1; i < days.FUN_140b91370(); ++i) {
        if (days[i]) {
            if (bFirst)
                bFirst = false;
            else
                ss << L", ";
            ss << (const wchar_t*)FUN_140b8ee70(i);
        }
    }
    return ss.str().c_str();
}
MS2_REPLACE(0x140B8F050, FUN_140b8f050, 463, 0x641DB190);

// The weekday name of a 1-based day (1 = Sunday); empty for other values.
// @0x140b8f230
CStringW FUN_140b8f230(int nDayOfWeek)
{
    CStringW str(L"");
    switch (nDayOfWeek) {
    case 1: str = FUN_14028de60(0x55c); break;
    case 2: str = FUN_14028de60(0x55d); break;
    case 3: str = FUN_14028de60(0x55e); break;
    case 4: str = FUN_14028de60(0x55f); break;
    case 5: str = FUN_14028de60(0x560); break;
    case 6: str = FUN_14028de60(0x561); break;
    case 7: str = FUN_14028de60(0x562); break;
    }
    return str;
}
MS2_REPLACE(0x140B8F230, FUN_140b8f230, 673, 0x654650BE);

// The weekday name of a time.
// @0x140b8f500
CStringW FUN_140b8f500(const CMsTime& time)
{
    return FUN_140b8f230(time.GetDayOfWeek());
}
MS2_REPLACE(0x140B8F500, FUN_140b8f500, 65, 0x5D0CDB01);

// The weekday names of the set bits 1..7, joined with ", ".
// @0x140b8f550
CStringW FUN_140b8f550(Unk_PartyBits days)
{
    if (days.FUN_140b91330())
        return L"";
    std::wstringstream ss;
    bool bFirst = true;
    for (unsigned i = 1; i < days.FUN_140b91370(); ++i) {
        if (days[i]) {
            if (bFirst)
                bFirst = false;
            else
                ss << L", ";
            ss << (const wchar_t*)FUN_140b8f230(i);
        }
    }
    return ss.str().c_str();
}
MS2_REPLACE(0x140B8F550, FUN_140b8f550, 463, 0xEE2BF939);

// "x, y, z" with one decimal.
// @0x140b8f730
CStringW FUN_140b8f730(const Unk_StreamPoint& pos)
{
    return StringFormat(L"{0:0.1f}, {1:0.1f}, {2:0.1f}", pos.x, pos.y, pos.z);
}
MS2_REPLACE(0x140B8F730, FUN_140b8f730, 94, 0x071B2F6A);

// A digit string split into digit groups of the client language (four digits for Korean: man / eok / jo) and
// formatted with the "s_number_string_<mask>" key, the mask having a bit per non-zero group. Short numbers get the
// plain comma grouping.
// @0x140b8f7a0
CStringW FUN_140b8f7a0(const CStringW& strNumber)
{
    int nGroup = FUN_1406516d0(FUN_1406516a0());
    int nLength = strNumber.GetLength();
    CStringW strRest(strNumber);
    if (nLength - nGroup <= 0)
        return FUN_14083cb20(strNumber);
    int nCount = (std::max)(4, nLength / nGroup);
    CStringW strGroup;
    strGroup.Preallocate(nGroup);
    CAtlArray<CStringW> groups;
    groups.SetCount(nCount);
    int i = 0;
    int nMask = 0;
    CStringW strUnused;
    while (i < nCount) {
        __int64 nValue = 0;
        if (i == nCount - 1)
            nValue = FUN_140718320(strRest);
        else
            nValue = FUN_140718320(strRest.Right(nGroup));
        if (nValue != 0)
            nMask |= 1 << i;
        groups.SetAt(i, FUN_1409404f0(nValue));
        strRest = strRest.Left(strRest.GetLength() - nGroup);
        ++i;
    }
    CStringW strKey(L"s_number_string_");
    strKey += StringFormat(L"{0:04b}", nMask);
    return FUN_1409eaa20(strKey, groups[0], groups[1], groups[2]);
}
MS2_REPLACE(0x140B8F7A0, FUN_140b8f7a0, 1041, 0xFF75188D);

// "mm:ss" text of a span.
// @0x140b8fbc0
CStringW FUN_140b8fbc0(const ATL::CTimeSpan& span)
{
    CStringW str = FUN_14028dfa0(L"s_common_min_sec_2", span.GetMinutes(), span.GetSeconds());
    return str;
}
MS2_REPLACE(0x140B8FBC0, FUN_140b8fbc0, 166, 0x3D4F38DE);

// The clock text of an hour and minute: "am/pm hh:mm" (12-hour) or the 24-hour string-table text.
// @0x140b8fc70
CStringW FUN_140b8fc70(int nHour, int nMinute, bool b24Hour)
{
    CStringW str(L"");
    if (!b24Hour) {
        bool bAm = nHour < 12;
        CStringW strAmPm = FUN_14028b8e0(bAm ? L"s_timestring_am" : L"s_timestring_pm");
        if (nHour == 0)
            nHour = 12;
        else if (nHour > 12)
            nHour -= 12;
        str = StringFormat(L"{0} {1:02d}:{2:02d}", strAmPm, nHour, nMinute);
        return str;
    }
    str = FUN_14028dfa0(L"s_common_hour_min", nHour, nMinute);
    return str;
}
MS2_REPLACE(0x140B8FC70, FUN_140b8fc70, 590, 0xCF168768);

// A string-table text of the region's table (table 0x3e for language 2, else table 1).
// @0x140b8fed0
CStringW FUN_140b8fed0(int nId)
{
    if (FUN_1406516b0() == 2)
        return FUN_1401a9d70()->FUN_141811980(0x3e, nId);
    return FUN_1401a9d70()->FUN_141811980(1, nId);
}
MS2_REPLACE(0x140B8FED0, FUN_140b8fed0, 128, 0x5835A829);

// Unk_PartyBits::any (bitset.inl; the word loop of a one-word set).
// @0x140b912f0
bool Unk_PartyBits::FUN_140b912f0()
{
    for (int i = 0; i >= 0; --i) {
        if (m_bits[i] != 0)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140B912F0, Unk_PartyBits, FUN_140b912f0, 62, 0x251F4393);

// Unk_PartyBits::none.
// @0x140b91330
bool Unk_PartyBits::FUN_140b91330()
{
    return !FUN_140b912f0();
}
MS2_REPLACE_METHOD(0x140B91330, Unk_PartyBits, FUN_140b91330, 54, 0x72A01054);

// Unk_PartyBits::size.
// @0x140b91370
unsigned Unk_PartyBits::FUN_140b91370()
{
    return 8;
}

MS2_EMIT_CRT_MEMMOVE_S();
