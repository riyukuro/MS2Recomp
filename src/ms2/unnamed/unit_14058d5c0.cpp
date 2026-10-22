// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEnchantOption (RTTI name, 0x68 bytes: CPtred, a value at
// +0x18 and the option map at +0x20) decoding from a packet: the options one by one, and the header value plus options.
// MS2-UNIT: unit_14058d5c0
// MS2-RANGE: 0x14058d5c0-0x14058d770 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2recover.h"

// Members used here only (other units hold their own views of the class).
class CEnchantOption : public CPtred
{
public:
    void FUN_14058d5c0(CInPacket& packet);                  // the options
    void FUN_14058d710(CInPacket& packet);                  // the header value, then the options
    __int64 m_n18;                                          // +0x18
    Unk_EnchantMap m_options;                               // +0x20 option id -> option
};
MS2_CHECK_SIZE(CEnchantOption, 0x68);

// @0x14058d5c0
void CEnchantOption::FUN_14058d5c0(CInPacket& packet)
{
    int nCount = packet.ReadInt32();
    for (int i = 0; i < nCount; ++i) {
        Unk_EnchantPtr<BaseOption> spOption(new BaseOption);
        int nKey = (unsigned short)packet.ReadInt16();
        spOption->FUN_140266d60(reinterpret_cast<Unk_EnchantRead&>(static_cast<CInputStream&>(packet)));
        m_options.SetAt(nKey, spOption);
    }
}

// @0x14058d710
void CEnchantOption::FUN_14058d710(CInPacket& packet)
{
    m_n18 = packet.ReadInt64();
    FUN_14058d5c0(packet);
}
