// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CManufacture and its packet writer / reader.
// MS2-UNIT: ?\manufacture.cpp
// MS2-RANGE: 0x140693e60-0x1406943b0 .text$mn
// MS2-PIN: ??_GCManufacture@@UEAAPEAXI@Z 0x1406941b0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "manufacture.h"
#include "stream.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// A (name, flag, value) triple the unit serializes (name unrecovered).
struct Unk_140694210
{
    Unk_140694210();                                        // 0x140694210
    ~Unk_140694210();                                       // 0x140694250
    CStringW m_00;
    unsigned m_08;
    int m_0c;
};

COutputStream& FUN_14070f960(COutputStream& out, long value);   // packet.cpp stream operators
CInputStream& FUN_14070f440(CInputStream& in, long& value);

// @0x140693e60
CManufacture::CManufacture()
    : m_18(0), m_20(0), m_28(0), m_30(0), m_38(0)
{
}

// @0x140693ee0
CManufacture::CManufacture(__int64 a, __int64 b, int c, __int64 d, int e, int f)
    : m_18(a), m_20(b), m_28(c), m_30(d), m_38(e), m_3c(f)
{
}

// @0x140693f70
CManufacture::~CManufacture()
{
}

// @0x140693fa0
void FUN_140693fa0(CManufacture& v, COutputStream& out)
{
    out.WriteInt64(v.m_18);
    out.WriteInt64(v.m_20);
    out.WriteInt32(v.m_28);
    out.WriteInt64(v.m_30);
    out.WriteInt32(v.m_38);
    out.WriteInt32(v.m_3c);
}

// @0x140694050
void FUN_140694050(CManufacture& v, CByteBuffer& in)
{
    v.m_18 = in.ReadInt64();
    v.m_20 = in.ReadInt64();
    v.m_28 = in.ReadInt32();
    v.m_30 = in.ReadInt64();
    v.m_38 = in.ReadInt32();
    v.m_3c = in.ReadInt32();
}

// @0x140694170
__int64 CManufacture::FUN_140694170()
{
    return FUN_1406941f0() + FUN_140694200();
}

// @0x1406941f0
__int64 CManufacture::FUN_1406941f0()
{
    return m_30;
}

// @0x140694200
int CManufacture::FUN_140694200()
{
    return m_38;
}

// @0x140694210
Unk_140694210::Unk_140694210()
    : m_08(0), m_0c(10)
{
}

// @0x140694250
Unk_140694210::~Unk_140694210()
{
}

// MS2-FUNCTIONAL: the exe passes the flag byte without bool normalisation (source spelling unknown)
// @0x140694280
void FUN_140694280(Unk_140694210& v, COutputStream& out)
{
    out.WriteUnicodeString(v.m_00);
    out.WriteBool((unsigned char)v.m_08);
    FUN_14070f960(out, v.m_0c);
}

// @0x1406942f0
void FUN_1406942f0(Unk_140694210& v, CByteBuffer& in)
{
    v.m_00 = in.ReadUnicodeString();
    v.m_08 = in.ReadUInt8();
    FUN_14070f440(in, (long&)v.m_0c);
}
