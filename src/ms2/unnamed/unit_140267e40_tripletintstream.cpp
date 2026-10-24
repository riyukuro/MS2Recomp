// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The 12-byte three-int value (see unit_140267ba0.cpp): its
// stream wrappers, copy, comparison and the stream writer / reader they forward to.
// MS2-UNIT: unit_140267e40
// MS2-RANGE: 0x140267e40-0x140268010 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140267e40.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"
#include "hook/ms2hook.h"

// Name invented; same value as unit_140267ba0.cpp's Unk_IntTriple.
class Unk_IntTriple
{
public:
    void WriteTo(COutputStream& out);
    void ReadFrom(CInputStream& in);
    void Copy(const Unk_IntTriple& other);
    int IsEqual(const Unk_IntTriple& other);
    void Write(COutputStream& out);
    void Read(CInputStream& in);
    int m_v[3];
};
MS2_CHECK_SIZE(Unk_IntTriple, 0xc);

// @0x140267e40
void Unk_IntTriple::WriteTo(COutputStream& out)
{
    Write(out);
}

// @0x140267e70
void Unk_IntTriple::ReadFrom(CInputStream& in)
{
    Read(in);
}

// @0x140267ea0
void Unk_IntTriple::Copy(const Unk_IntTriple& other)
{
    for (int i = 0; i < 3; ++i) {
        m_v[i] = other.m_v[i];
    }
}

// @0x140267ef0
int Unk_IntTriple::IsEqual(const Unk_IntTriple& other)
{
    for (int i = 0; i < 3; ++i) {
        if (m_v[i] != other.m_v[i])
            return 0;
    }
    return 1;
}

// @0x140267f50
void Unk_IntTriple::Write(COutputStream& out)
{
    for (int i = 0; i < 3; ++i) {
        out.WriteInt32(m_v[i]);
    }
}

// @0x140267fb0
void Unk_IntTriple::Read(CInputStream& in)
{
    for (int i = 0; i < 3; ++i) {
        m_v[i] = in.ReadInt32();
    }
}
