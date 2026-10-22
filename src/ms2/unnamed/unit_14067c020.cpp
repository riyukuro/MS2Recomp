// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The 16-byte machine id (CMachineIDManager::m_id): zero init, copy,
// compare, wire (de)serialisation, copy to/from a byte buffer and the dashed hex text, plus this TU's UCRT memmove_s copy.
// Class and member names are invented (the range is unnamed in the exe).
// MS2-UNIT: unit_14067c020
// MS2-RANGE: 0x14067c020-0x14067c600 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

unsigned char& FUN_140203bf0(CByteBuffer* pBuf, unsigned __int64 nIndex);   // CByteBuffer::operator[] (the exe's copy in unit_1401f9eb0)

class Unk_MachineId
{
public:
    Unk_MachineId();                                                // 0x14067c020, zero-inits
    Unk_MachineId* FUN_14067c050(const Unk_MachineId* pOther);      // copy
    Unk_MachineId* FUN_14067c080(const Unk_MachineId* pOther);      // assignment
    Unk_MachineId* FUN_14067c0c0(const CByteBuffer& buf);           // from a buffer of up to 16 bytes
    bool FUN_14067c130(const Unk_MachineId* pOther) const;          // equal
    bool FUN_14067c180(const Unk_MachineId* pOther) const;          // not equal
    bool FUN_14067c260(const Unk_MachineId* pOther) const;          // bytes 6..9 equal
    void FUN_14067c2c0(COutputStream* pOut) const;
    void FUN_14067c310(CInputStream* pIn);
    void FUN_14067c360(CByteBuffer& buf) const;
    void FUN_14067c3d0();                                           // clear
    CStringW FUN_14067c400() const;                                 // "AA-BB-..." hex text

    unsigned char m_data[16];
};
MS2_CHECK_SIZE(Unk_MachineId, 0x10);

// @0x14067c020
Unk_MachineId::Unk_MachineId()
{
    FUN_14067c3d0();
}
MS2_REPLACE_CTOR(0x14067C020, Unk_MachineId, 29, 0xAC794091);

// @0x14067c050
Unk_MachineId* Unk_MachineId::FUN_14067c050(const Unk_MachineId* pOther)
{
    memcpy(m_data, pOther->m_data, 16);
    return this;
}
MS2_REPLACE_METHOD(0x14067C050, Unk_MachineId, FUN_14067c050, 37, 0x65761C45);

// @0x14067c080
Unk_MachineId* Unk_MachineId::FUN_14067c080(const Unk_MachineId* pOther)
{
    if (this != pOther)
        memcpy(m_data, pOther->m_data, 16);
    return this;
}
MS2_REPLACE_METHOD(0x14067C080, Unk_MachineId, FUN_14067c080, 49, 0xD3408B84);

// MS2-FUNCTIONAL: the exe's length temp goes through rax before rcx
// @0x14067c0c0
Unk_MachineId* Unk_MachineId::FUN_14067c0c0(const CByteBuffer& buf)
{
    if (!(buf.GetLength() > 0x10))
    {
        unsigned __int64 nLen = buf.GetLength();
        memcpy(m_data, buf.FUN_14067c4c0(), nLen);
    }
    return this;
}
MS2_REPLACE_METHOD(0x14067C0C0, Unk_MachineId, FUN_14067c0c0, 93, 0x9EA9E230);

// @0x14067c130
bool Unk_MachineId::FUN_14067c130(const Unk_MachineId* pOther) const
{
    return memcmp(m_data, pOther->m_data, 16) == 0;
}
MS2_REPLACE_METHOD(0x14067C130, Unk_MachineId, FUN_14067c130, 70, 0xA068BA25);

// @0x14067c180
bool Unk_MachineId::FUN_14067c180(const Unk_MachineId* pOther) const
{
    return !FUN_14067c130(pOther);
}
MS2_REPLACE_METHOD(0x14067C180, Unk_MachineId, FUN_14067c180, 64, 0xAA03750C);

// @0x14067c1d0
void FUN_14067c1d0(const Unk_MachineId* pId)
{
    static Unk_MachineId s_zero;
    pId->FUN_14067c130(&s_zero);
}
MS2_REPLACE(0x14067C1D0, FUN_14067c1d0, 123, 0xDDF60160);

// @0x14067c260
bool Unk_MachineId::FUN_14067c260(const Unk_MachineId* pOther) const
{
    for (int i = 6; i < 10; i++)
    {
        if ((char)m_data[i] != (char)pOther->m_data[i])
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14067C260, Unk_MachineId, FUN_14067c260, 80, 0x7B8B5145);

// @0x14067c2c0
void Unk_MachineId::FUN_14067c2c0(COutputStream* pOut) const
{
    pOut->vfunc_o10_9((void*)m_data, 16);
}
MS2_REPLACE_METHOD(0x14067C2C0, Unk_MachineId, FUN_14067c2c0, 59, 0x9FBAB988);

// @0x14067c310
void Unk_MachineId::FUN_14067c310(CInputStream* pIn)
{
    pIn->vfunc_o8_9(m_data, 16);
}
MS2_REPLACE_METHOD(0x14067C310, Unk_MachineId, FUN_14067c310, 59, 0x9FBAB988);

// @0x14067c360
void Unk_MachineId::FUN_14067c360(CByteBuffer& buf) const
{
    for (int i = 0; i < 16; i++)
        FUN_140203bf0(&buf, i) = m_data[i];
}
MS2_REPLACE_METHOD(0x14067C360, Unk_MachineId, FUN_14067c360, 92, 0xFCBAB457);

// @0x14067c3d0
void Unk_MachineId::FUN_14067c3d0()
{
    memset(m_data, 0, 16);
}
MS2_REPLACE_METHOD(0x14067C3D0, Unk_MachineId, FUN_14067c3d0, 27, 0xD024C07A);

// @0x14067c400
CStringW Unk_MachineId::FUN_14067c400() const
{
    CStringW str;
    for (unsigned i = 0; i < 16; i++)
    {
        str.AppendFormat(L"%02X", (unsigned __int64)m_data[i]);
        if (i < 15)
            str.Append(L"-");
    }
    return str;
}
MS2_REPLACE_METHOD(0x14067C400, Unk_MachineId, FUN_14067c400, 179, 0xD390DB2E);

// @0x14067c4c0
const unsigned char* CByteBuffer::FUN_14067c4c0() const
{
    return &m_aByteBuff[0];
}
MS2_REPLACE_METHOD(0x14067C4C0, CByteBuffer, FUN_14067c4c0, 33, 0x8714DA35);

// @0x14067c4f0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
