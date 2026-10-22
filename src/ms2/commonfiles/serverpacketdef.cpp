// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Server packet payload (de)serialisers.
// MS2-UNIT: commonfiles\serverpacketdef.cpp
// MS2-RANGE: 0x1407a3380-0x1407a4f20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\serverpacketdef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "serverpacketdef.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1407a3380
Unk_SPDA::Unk_SPDA() : type(0), value(0) {}

// @0x1407a33e0
Unk_SPDA::Unk_SPDA(const Unk_SPD0& src) {
    type = src.type;
    value = src.value;
    s1 = src.s1;
    s2 = src.s2;
}

// @0x1407a3490
void Unk_SPDA::FUN_1407a3490(COutputStream* out) {
    out->WriteUInt8(type);
    switch (type) {
    case 2:
        out->WriteUnicodeString(s1);
        out->WriteUnicodeString(s2);
        break;
    case 3: case 4: case 6: case 7: case 0x11:
        out->WriteInt64(value);
        break;
    case 5: case 10:
        out->WriteInt64(value);
        out->WriteUnicodeString(s1);
        out->WriteUnicodeString(s2);
        break;
    case 0x10:
        out->WriteUnicodeString(s1);
        break;
    }
}
MS2_REPLACE_METHOD(0x1407A3490, Unk_SPDA, FUN_1407a3490, 355, 0x8BEDCA45);

// @0x1407a3640
void Unk_SPDA::FUN_1407a3640(Unk_SPDReader& in) {
    Unk_SPDByteRange range;
    type = in.FUN_140202740(*FUN_140203550(&range, 0, 0x14));
    switch (type) {
    case 2:
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 3: case 4: case 6: case 7: case 0x11:
        value = in.ReadInt64();
        break;
    case 5: case 10:
        value = in.ReadInt64();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 0x10:
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        break;
    }
}
MS2_REPLACE_METHOD(0x1407A3640, Unk_SPDA, FUN_1407a3640, 756, 0x43C6420F);

// @0x1407a3980
void Unk_SPDB::FUN_1407a3980(COutputStream* out) {
    out->WriteUInt8(type);
    switch (type) {
    case 2:
        out->WriteUInt8(flag);
        out->WriteUnicodeString(s1);
        out->WriteUnicodeString(s2);
        break;
    case 4: case 6: case 0x11:
        out->WriteUInt8(flag);
        out->WriteInt64(value);
        break;
    case 3: case 7:
        out->WriteUInt8(flag);
        out->WriteInt64(value);
        out->WriteInt64(extra);
        out->WriteInt64(id);
        out->WriteUnicodeString(s1);
        break;
    case 5: case 10:
        out->WriteUInt8(flag);
        out->WriteInt64(value);
        out->WriteUnicodeString(s1);
        out->WriteUnicodeString(s2);
        // no break: the exe falls through into case 0xe
    case 0xe:
        out->WriteUInt8(kind);
        out->WriteInt64(value);
        out->WriteUnicodeString(s1);
        break;
    case 0xb:
        out->WriteInt64(value);
        break;
    case 0xc:
        out->WriteUInt8(flag);
        out->WriteUnicodeString(s1);
        break;
    case 0xf:
        break;
    default:
        MS2_ASSERT_AT(0x86, 0);
    }
}
MS2_REPLACE_METHOD(0x1407A3980, Unk_SPDB, FUN_1407a3980, 752, 0xDE36C697);

// @0x1407a3cc0
void Unk_SPDB::FUN_1407a3cc0(Unk_SPDReader& in) {
    Unk_SPDByteRange range;
    type = in.FUN_140202740(*FUN_140203550(&range, 0, 0x14));
    switch (type) {
    case 0xf:
        break;
    case 2:
        flag = in.ReadUInt8();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 4: case 6: case 0x11:
        flag = in.ReadUInt8();
        value = in.ReadInt64();
        break;
    case 3: case 7:
        flag = in.ReadUInt8();
        value = in.ReadInt64();
        extra = in.ReadInt64();
        id = in.ReadInt64();
        s1 = in.ReadUnicodeString();
        break;
    case 5: case 10:
        flag = in.ReadUInt8();
        value = in.ReadInt64();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 0xe:
        kind = in.ReadUInt8();
        value = in.ReadInt64();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        break;
    case 0xb:
        value = in.ReadInt64();
        break;
    case 0xc:
        flag = in.ReadUInt8();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        break;
    }
}
MS2_REPLACE_METHOD(0x1407A3CC0, Unk_SPDB, FUN_1407a3cc0, 1648, 0x14FFD8A2);

// @0x1407a4380
void Unk_SPDC::FUN_1407a4380(COutputStream* out) {
    out->WriteInt32(a);
    out->WriteInt32(b);
    out->WriteInt32(c);
    out->WriteInt32(d);
    out->WriteUInt8(e);
}
MS2_REPLACE_METHOD(0x1407A4380, Unk_SPDC, FUN_1407a4380, 139, 0x3A3B4B05);

// @0x1407a4420
void Unk_SPDC::FUN_1407a4420(CInputStream* in) {
    a = in->ReadInt32();
    b = in->ReadInt32();
    c = in->ReadInt32();
    d = in->ReadInt32();
    e = in->ReadUInt8();
}
MS2_REPLACE_METHOD(0x1407A4420, Unk_SPDC, FUN_1407a4420, 138, 0xE2ECB42C);

// @0x1407a44b0
void Unk_SPDE::FUN_1407a44b0(COutputStream* out) {
    out->WriteUInt8(kind);
    out->WriteUnicodeString(name);
}
MS2_REPLACE_METHOD(0x1407A44B0, Unk_SPDE, FUN_1407a44b0, 81, 0x55FD50B3);

// @0x1407a4510
void Unk_SPDE::FUN_1407a4510(CInputStream* in) {
    kind = in->ReadUInt8();
    name = in->ReadUnicodeString();
}
MS2_REPLACE_METHOD(0x1407A4510, Unk_SPDE, FUN_1407a4510, 125, 0xB200A850);

// @0x1407a45a0
void Unk_SPDF::FUN_1407a45a0(COutputStream* out) {
    out->WriteUInt8(a);
    out->WriteInt32(b);
    out->WriteUnicodeString(name);
    out->WriteInt64(c);
    out->WriteInt64(d);
    out->WriteInt32(e);
    out->WriteUInt8(f);
    out->WriteUInt8(g);
    out->WriteInt32(l);
    out->WriteInt64(m);
    if (g == 1) {
        out->WriteInt64(h);
    } else if (g == 2) {
        out->WriteInt64(i);
        out->WriteInt64(j);
    }
    out->WriteInt32(k);
}
MS2_REPLACE_METHOD(0x1407A45A0, Unk_SPDF, FUN_1407a45a0, 407, 0x8F5C5A48);

// @0x1407a4740
void Unk_SPDF::FUN_1407a4740(CInputStream* in) {
    a = in->ReadUInt8();
    b = in->ReadInt32();
    name = in->ReadUnicodeString();
    c = in->ReadInt64();
    d = in->ReadInt64();
    e = in->ReadInt32();
    f = in->ReadUInt8();
    g = in->ReadUInt8();
    l = in->ReadInt32();
    m = in->ReadInt64();
    if (g == 1) {
        h = in->ReadInt64();
    } else if (g == 2) {
        i = in->ReadInt64();
        j = in->ReadInt64();
    }
    k = in->ReadInt32();
}
MS2_REPLACE_METHOD(0x1407A4740, Unk_SPDF, FUN_1407a4740, 452, 0x5B028907);

// @0x1407a4910
void Unk_SPDG::FUN_1407a4910(COutputStream* out) {
    out->WriteInt32(a);
    out->WriteInt64(b);
    out->WriteInt64(c);
    out->WriteUnicodeString(d);
}
MS2_REPLACE_METHOD(0x1407A4910, Unk_SPDG, FUN_1407a4910, 130, 0x4DAF50D7);

// @0x1407a49a0
void Unk_SPDG::FUN_1407a49a0(CInputStream* in) {
    a = in->ReadInt32();
    b = in->ReadInt64();
    c = in->ReadInt64();
    d = in->ReadUnicodeString();
}
MS2_REPLACE_METHOD(0x1407A49A0, Unk_SPDG, FUN_1407a49a0, 172, 0x17B43280);

// @0x1407a4a60
void Unk_SPDH::FUN_1407a4a60(COutputStream* out) {
    out->WriteInt64(a);
    out->WriteUnicodeString(b);
}
MS2_REPLACE_METHOD(0x1407A4A60, Unk_SPDH, FUN_1407a4a60, 81, 0xC84F2203);

// @0x1407a4ac0
void Unk_SPDH::FUN_1407a4ac0(CInputStream* in) {
    a = in->ReadInt64();
    b = in->ReadUnicodeString();
}
MS2_REPLACE_METHOD(0x1407A4AC0, Unk_SPDH, FUN_1407a4ac0, 123, 0x1D80FD34);

// @0x1407a4b50
void Unk_SPDI::FUN_1407a4b50(COutputStream* out) {
    out->WriteUInt8(kind);
    if (kind == 0) {
        out->WriteInt32(a);
        out->WriteInt16(b);
        out->WriteInt32(c);
        out->WriteInt32(d);
        out->WriteInt32(e);
    } else {
        out->WriteUnicodeString(s);
    }
    if (kind == '1') {
        out->WriteInt64(x);
    }
}
MS2_REPLACE_METHOD(0x1407A4B50, Unk_SPDI, FUN_1407a4b50, 254, 0x578809F0);

// @0x1407a4c60
void Unk_SPDI::FUN_1407a4c60(CInputStream* in) {
    kind = in->ReadUInt8();
    if (kind == 0) {
        a = in->ReadInt32();
        b = in->ReadInt16();
        c = in->ReadInt32();
        d = in->ReadInt32();
        e = in->ReadInt32();
    } else {
        s = in->ReadUnicodeString();
    }
    if (kind == '1') {
        x = in->ReadInt64();
    }
}
MS2_REPLACE_METHOD(0x1407A4C60, Unk_SPDI, FUN_1407a4c60, 295, 0x1CFF92C3);

// @0x1407a4d90
void Unk_SPDJ::FUN_1407a4d90(COutputStream* out) {
    out->WriteInt32(a);
}
MS2_REPLACE_METHOD(0x1407A4D90, Unk_SPDJ, FUN_1407a4d90, 42, 0x198D3D0B);

// @0x1407a4dc0
void Unk_SPDJ::FUN_1407a4dc0(Unk_SPDReader& in) {
    a = in.ReadInt32();
}
MS2_REPLACE_METHOD(0x1407A4DC0, Unk_SPDJ, FUN_1407a4dc0, 60, 0x21DC48C6);

// @0x1407a4e10
void Unk_SPDK::FUN_1407a4e10(COutputStream* out) {
    out->WriteUInt8(b);
    out->WriteInt64(a);
    out->WriteInt32(c);
}
MS2_REPLACE_METHOD(0x1407A4E10, Unk_SPDK, FUN_1407a4e10, 92, 0x43E21C6F);

// @0x1407a4e80
void Unk_SPDK::FUN_1407a4e80(Unk_SPDReader& in) {
    b = in.ReadUInt8();
    a = in.ReadInt64();
    c = in.ReadInt32();
}
MS2_REPLACE_METHOD(0x1407A4E80, Unk_SPDK, FUN_1407a4e80, 148, 0xEF4965A1);
