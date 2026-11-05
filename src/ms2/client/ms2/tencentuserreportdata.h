// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Tencent user report record (0xe8 bytes). The
// packet payload serializers (unit_1401f9eb0) define its ctor/reset/copy, the Tencent platform its destructor and
// assignment, and the report dialog keeps one as m_data. Field names are inferred.
#pragma once

// The 16-byte tagged value at +0x38 (a kind and an id).
struct Unk_PayloadValue {
    // @0x1402038a0
    Unk_PayloadValue(){Reset();}
    // @0x140204340
    void Copy(const Unk_PayloadValue& other){Reset();type=other.type;value=other.value;}
    // @0x140207730
    void Reset(){type=0;value=0;}
    int type;__int64 value;
};
MS2_CHECK_SIZE(Unk_PayloadValue,16);

namespace TencentUserReport {
struct Unk_ReportData {
    Unk_ReportData();
    ~Unk_ReportData();
    void FUN_140200f80();
    void FUN_140201790(const Unk_ReportData& other);
    int type; int reason;
    CStringW name; CStringW target; CStringW itemName;
    __int64 m_20; int m_28; int m_2c; CStringW content;
    Unk_PayloadValue m_38;
    __int64 itemId; __int64 guildId;
    int guildNumber; int m_5c; CString m_60;
    CStringW comment; CStringW title; CString path;
    int itemKind; int m_84; __int64 m_88; __int64 m_90;
    CStringW m_98; CStringW reportTitle; __int64 reportId;
    CString reportPath; CStringW reportComment;
    __int64 m_c0; __int64 m_c8; CString m_d0;
    int m_d8; int m_dc; __int64 m_e0;
};
MS2_CHECK_SIZE(Unk_ReportData, 0xe8);
}
MS2_CHECK_OFFSET(TencentUserReport::Unk_ReportData, m_38, 0x38);
MS2_CHECK_OFFSET(TencentUserReport::Unk_ReportData, m_98, 0x98);
