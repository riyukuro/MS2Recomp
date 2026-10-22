// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateSyncObject: the queued state request record and
// its packet coders, the per-state subclasses and the factory.
// MS2-UNIT: ?\statesyncobject.cpp
// MS2-RANGE: 0x140835210-0x140837660 .text$mn
// MS2-PIN: ??_7Unk_StateArg22@@6B@ 0x142d97a28
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GUnk_StateArg22@@UEAAPEAXI@Z 0x1408372b0 ; unique
// MS2-PIN: ??_GStateSyncObjectCoupleEmotion@@UEAAPEAXI@Z 0x1408372f0 ; unique
// MS2-PIN: ??_GStateSyncObjectMicroGameCoupleDance@@UEAAPEAXI@Z 0x140837330 ; prop
// MS2-PIN: ??_GStateSyncObjectMicroGameRps@@UEAAPEAXI@Z 0x140837370 ; unique
// MS2-PIN: ??_GStateSyncObjectWeddingEmotion@@UEAAPEAXI@Z 0x1408373b0 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_StateArg22@@@@AEAAXXZ 0x140837470 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/statesyncobject.h"
#include "ms2/commonfiles/constraints.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/exception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"

// The bitset stream helpers (commonfiles\bitset.inl; COMDATs owned by commonfiles\dungeonrecord.cpp).
// 0x14031c1f0
inline void ReadBits(Unk_PartyBits& bits, CInputStream& in)
{
    for (int i = 0; i < 1; i++)
        bits.m_bits[i] = in.ReadUInt8();
}
// 0x14031c240
inline void WriteBits(Unk_PartyBits& bits, COutputStream& out)
{
    for (int i = 0; i < 1; i++)
        out.WriteUInt8(bits.m_bits[i]);
}

// Inclusive range constraint (commonfiles\constraints.h; instantiated elsewhere).
template <class T> struct Unk_140203550 {
    T minimum, maximum;
    Unk_140203550(T constraintMin, T constraintMax);  // 0x140203550 for T = unsigned char
    bool Check(T value) const;                       // 0x1402041a0 for T = unsigned char
};

// Constrained byte read: throws Exception(13) when the value fails the constraint.
template <class Constraint> unsigned char Unk_Read8(void* packet, Constraint constraint);  // 0x140202740 (range)
// @0x140837040
template <> unsigned char Unk_Read8<Unk_1402c44b0>(void* packet, Unk_1402c44b0 constraint)
{
    unsigned char value = static_cast<CInPacket*>(packet)->ReadUInt8();
    if (!constraint.Check(value))
        throw Exception(13);
    return value;
}

// @0x140835210
Unk_StateArg22::Unk_StateArg22(int nState)
    : m_nState(nState), m_nSub(0), m_pos20(0, 0, 0), m_dir2c(0, 0, 0), m_nDirFlags(0), m_vel3c(0, 0, 0),
      m_pos48(0, 0, 0), m_n54(2), m_f58(0.0f), m_fTime(0.0f), m_n64(0), m_n68(0), m_n6c(0), m_pos78(0, 0, 0), m_n90(0),
      m_nA0(0x7fffffff), m_fA4(0.0f), m_nA8(0), m_nAC(0)
{
}

// @0x1408353e0
Unk_StateArg22::~Unk_StateArg22()
{
}

// @0x140835450
MS2Ptr<Unk_StateArg22> FUN_140835450(int nState)
{
    MS2Ptr<Unk_StateArg22> spState;
    switch (nState) {
    case 0x3a:
        spState.AssignRaw(new StateSyncObjectCoupleEmotion(nState));
        break;
    case 0x3c:
        spState.AssignRaw(new StateSyncObjectMicroGameRps(nState));
        break;
    case 0x45:
        spState.AssignRaw(new StateSyncObjectMicroGameCoupleDance(nState));
        break;
    case 0x47:
        spState.AssignRaw(new StateSyncObjectWeddingEmotion(nState));
        break;
    default:
        spState.AssignRaw(new Unk_StateArg22(nState));
        break;
    }
    return spState;
}

// @0x1408356c0
void Unk_StateArg22::FUN_1408356c0(COutPacket& packet)
{
    FUN_140836250(packet);
}

// @0x1408356f0
void Unk_StateArg22::FUN_1408356f0(CInPacket& packet)
{
    FUN_1408365d0(packet);
}

// @0x140835720
void Unk_StateArg22::FUN_140835720(COutputStream& kOut)
{
    FUN_140836250(kOut);
}

// @0x140835750
void Unk_StateArg22::vfunc_1(COutputStream& kOut)
{
    kOut.WriteUInt8(m_nState);
    kOut.WriteUInt8(m_nSub);
    kOut.WriteVector3Short(reinterpret_cast<const Unk_StreamPoint&>(m_pos20));
    kOut.WriteShortDiv10(m_dir2c.z);
    kOut.WriteUInt8(m_nDirFlags);
    if ((m_nDirFlags & 0x80) == 0x80) {
        kOut.WriteFloat(m_vel3c.x);
        kOut.WriteFloat(m_vel3c.y);
    }
    kOut.WriteVector3Short(reinterpret_cast<const Unk_StreamPoint&>(m_pos48));
    kOut.WriteUInt8(m_n54);
    kOut.WriteShortDiv10(m_f58);
    kOut.WriteShortDivScaled(m_fTime, 1000);
    WriteBits(m_optional, kOut);
    if (m_optional[0])
        kOut.WriteInt32(m_n64);
    if (m_optional[1])
        kOut.WriteInt32(m_n68);
    if (m_optional[2])
        kOut.WriteInt16(m_n6c);
    if (m_optional[3])
        kOut.WriteUnicodeStringA(m_str70);
    if (m_optional[4]) {
        kOut.WriteVector3(reinterpret_cast<const Unk_StreamPoint&>(m_pos78));
        kOut.WriteUnicodeStringA(m_str88);
    }
    if (m_optional[5]) {
        kOut.WriteInt32(m_n90);
        kOut.WriteUnicodeStringA(m_str98);
    }
    kOut.WriteInt32(m_nA0);
}

// @0x140835bd0
void Unk_StateArg22::vfunc_2(CInPacket& kIn)
{
    m_nSub = Unk_Read8(&kIn, Unk_1402c44b0());
    reinterpret_cast<Unk_StreamPoint&>(m_pos20) = kIn.ReadVector3Short();
    m_dir2c.z = kIn.ReadShortDiv10();
    m_nDirFlags = kIn.ReadUInt8();
    if ((m_nDirFlags & 0x80) == 0x80) {
        m_vel3c.x = kIn.ReadFloat();
        m_vel3c.y = kIn.ReadFloat();
    }
    reinterpret_cast<Unk_StreamPoint&>(m_pos48) = kIn.ReadVector3Short();
    m_n54 = Unk_Read8(&kIn, Unk_140203550<unsigned char>(0, 0x13));
    m_f58 = kIn.ReadShortDiv10();
    m_fTime = kIn.ReadShortDivScaled(1000);
    ReadBits(m_optional, kIn);
    if (m_optional[0])
        m_n64 = kIn.ReadInt32();
    if (m_optional[1])
        m_n68 = kIn.ReadInt32();
    if (m_optional[2])
        m_n6c = kIn.ReadInt16();
    if (m_optional[3])
        m_str70 = kIn.ReadUnicodeStringA();
    if (m_optional[4]) {
        reinterpret_cast<Unk_StreamPoint&>(m_pos78) = kIn.ReadVector3();
        m_str88 = kIn.ReadUnicodeStringA();
    }
    if (m_optional[5]) {
        m_n90 = kIn.ReadInt32();
        m_str98 = kIn.ReadUnicodeStringA();
    }
    m_nA0 = kIn.ReadInt32();
}

// Marks which optional fields are set, packs the velocity direction into m_nDirFlags when it is axis-aligned, then
// writes the record and the tick.
// @0x140836250
void Unk_StateArg22::FUN_140836250(COutputStream& kOut)
{
    m_optional.FUN_140837500();
    if (m_n64 != 0)
        m_optional.Set(0, true);
    if (m_n68 != 0)
        m_optional.Set(1, true);
    if (m_n6c != 0)
        m_optional.Set(2, true);
    if (!m_str70.IsEmpty())
        m_optional.Set(3, true);
    if (m_str88.GetLength() > 1)
        m_optional.Set(4, true);
    if (m_n90 != 0)
        m_optional.Set(5, true);

    bool bAxisX = m_vel3c.x == -1.0f || m_vel3c.x == 0.0f || m_vel3c.x == 1.0f;
    bool bAxisY = m_vel3c.y == -1.0f || m_vel3c.y == 0.0f || m_vel3c.y == 1.0f;
    if (bAxisX && bAxisY) {
        m_nDirFlags = 0;
        if (m_vel3c.x == -1.0f)
            m_nDirFlags = 0;
        else if (m_vel3c.x == 0.0f)
            m_nDirFlags = 1;
        else if (m_vel3c.x == 1.0f)
            m_nDirFlags = 2;
        if (m_vel3c.y == -1.0f)
            m_nDirFlags += 4;
        else if (m_vel3c.y == 0.0f)
            m_nDirFlags += 8;
        else if (m_vel3c.y == 1.0f)
            m_nDirFlags += 0xc;
    } else {
        m_nDirFlags = 0x80;
    }
    vfunc_1(kOut);
    kOut.WriteInt32(m_nAC);
}

// @0x140836540
void Unk_StateArg22::FUN_140836540(CInPacket& kIn)
{
    vfunc_2(kIn);
    m_nAC = kIn.ReadInt32();
}

// @0x1408365a0
void Unk_StateArg22::FUN_1408365a0(COutputStream& kOut)
{
    vfunc_1(kOut);
}

// Reads the record, then unpacks the axis-aligned velocity direction.
// @0x1408365d0
void Unk_StateArg22::FUN_1408365d0(CInPacket& kIn)
{
    vfunc_2(kIn);
    if ((m_nDirFlags & 0x80) != 0x80) {
        unsigned char nX = m_nDirFlags & 3;
        unsigned char nY = m_nDirFlags & 0xc;
        if (nX == 0)
            m_vel3c.x = -1.0f;
        else if (nX == 1)
            m_vel3c.x = 0.0f;
        else if (nX == 2)
            m_vel3c.x = 1.0f;
        if (nY == 4)
            m_vel3c.y = -1.0f;
        else if (nY == 8)
            m_vel3c.y = 0.0f;
        else if (nY == 0xc)
            m_vel3c.y = 1.0f;
    }
}

// @0x1408366e0
StateSyncObjectMicroGameRps::StateSyncObjectMicroGameRps(int nState)
    : Unk_StateArg22(nState), m_nB8(0), m_nBC(-1), m_nC0(-1)
{
}

// @0x140836760
void StateSyncObjectMicroGameRps::vfunc_1(COutputStream& kOut)
{
    Unk_StateArg22::vfunc_1(kOut);
    kOut.WriteInt32(m_nB8);
    kOut.WriteUInt8(m_nBC);
    kOut.WriteUInt8(m_nC0);
    kOut.WriteUnicodeString(m_strC8);
}

// @0x140836810
void StateSyncObjectMicroGameRps::vfunc_2(CInPacket& kIn)
{
    Unk_StateArg22::vfunc_2(kIn);
    m_nB8 = kIn.ReadInt32();
    m_nBC = (char)kIn.ReadUInt8();
    m_nC0 = (char)kIn.ReadUInt8();
    m_strC8 = kIn.ReadUnicodeString();
}

// @0x140836930
StateSyncObjectCoupleEmotion::StateSyncObjectCoupleEmotion(int nState)
    : Unk_StateArg22(nState), m_nB8(0), m_nBC(0), m_nC0(0), m_posC4(0, 0, 0), m_posD0(0, 0, 0)
{
}

// @0x1408369e0
void StateSyncObjectCoupleEmotion::vfunc_1(COutputStream& kOut)
{
    Unk_StateArg22::vfunc_1(kOut);
    kOut.WriteInt32(m_nB8);
    kOut.WriteInt32(m_nBC);
    kOut.WriteUInt8(m_nC0);
    kOut.WriteVector3(reinterpret_cast<const Unk_StreamPoint&>(m_posC4));
    kOut.WriteVector3(reinterpret_cast<const Unk_StreamPoint&>(m_posD0));
}

// @0x140836ab0
void StateSyncObjectCoupleEmotion::vfunc_2(CInPacket& kIn)
{
    Unk_StateArg22::vfunc_2(kIn);
    m_nB8 = kIn.ReadInt32();
    m_nBC = kIn.ReadInt32();
    m_nC0 = kIn.ReadUInt8();
    reinterpret_cast<Unk_StreamPoint&>(m_posC4) = kIn.ReadVector3();
    reinterpret_cast<Unk_StreamPoint&>(m_posD0) = kIn.ReadVector3();
}

// @0x140836be0
StateSyncObjectMicroGameCoupleDance::StateSyncObjectMicroGameCoupleDance(int nState)
    : Unk_StateArg22(nState), m_nB8(0), m_bBC(false)
{
}

// @0x140836c50
void StateSyncObjectMicroGameCoupleDance::vfunc_1(COutputStream& kOut)
{
    Unk_StateArg22::vfunc_1(kOut);
    kOut.WriteInt32(m_nB8);
    kOut.WriteBool(m_bBC);
    kOut.WriteUnicodeStringA(m_strC0);
}

// @0x140836ce0
void StateSyncObjectMicroGameCoupleDance::vfunc_2(CInPacket& kIn)
{
    Unk_StateArg22::vfunc_2(kIn);
    m_nB8 = kIn.ReadInt32();
    m_bBC = kIn.ReadBool();
    m_strC0 = kIn.ReadUnicodeStringA();
}

// @0x140836dd0
StateSyncObjectWeddingEmotion::StateSyncObjectWeddingEmotion(int nState)
    : Unk_StateArg22(nState), m_bB8(false), m_bB9(false), m_nBC(0), m_nC0(0), m_bC4(false)
{
}

// @0x140836e50
void StateSyncObjectWeddingEmotion::vfunc_1(COutputStream& kOut)
{
    Unk_StateArg22::vfunc_1(kOut);
    kOut.WriteBool(m_bB8);
    kOut.WriteBool(m_bB9);
    if (m_bB9)
        kOut.WriteInt32(m_nBC);
    if (m_bB8) {
        kOut.WriteInt32(m_nC0);
        kOut.WriteBool(m_bC4);
    }
}

// @0x140836f20
void StateSyncObjectWeddingEmotion::vfunc_2(CInPacket& kIn)
{
    Unk_StateArg22::vfunc_2(kIn);
    m_bB8 = kIn.ReadBool();
    m_bB9 = kIn.ReadBool();
    if (m_bB9)
        m_nBC = kIn.ReadInt32();
    if (m_bB8) {
        m_nC0 = kIn.ReadInt32();
        m_bC4 = kIn.ReadBool();
    }
}

// @0x140837280
Unk_PartyBitRef::operator bool() const
{
    return m_pBits->Test(m_nPos);
}

// @0x140837500
Unk_PartyBits& Unk_PartyBits::FUN_140837500()
{
    Fill(false);
    return *this;
}

MS2_EMIT_CRT_MEMMOVE_S();
