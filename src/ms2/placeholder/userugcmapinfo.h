// userugcmapinfo.h - UserUGCMapInfo (RTTI UserUGCMapInfo, CPtred, 0x48 bytes): the house (UGC map) info of the local
// player (MyPC +0x1618). NOT an original header; the members are invented from use.
// Defined in client\ms2\scenestategame.cpp (ctor 0x1408b3f10, dtor 0x1408b3fe0).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/blackmarketitemoption.h"

class CInPacket;
class COutPacket;
class COutputStream;

// The house info (RTTI UserUGCMapInfo, CPtred, 0x48 bytes; ctor 0x1408b3f10, dtor 0x1408b3fe0).
class UserUGCMapInfo : public CPtred
{
public:
    UserUGCMapInfo();
    ~UserUGCMapInfo();
    void FUN_1408b4220(CInPacket& packet, int* pResult);    // decode
    void FUN_1408b40d0(Unk_BmPtr<UserUGCMapInfo> spOther);  // copy from another info
    void FUN_1408b4020(int n18, int n1c, int n20, int n24, CStringW str28, __int64 n30, __int64 n38, unsigned char n40);
    void FUN_1408b41c0(COutPacket& packet, int nFlag) const;   // encode the 0x69/0x14 packet
    void FUN_1408b4450(COutputStream& stream, int nFlag) const;   // write
    void FUN_1408b4560(CStringW str);                       // set m_str28
    int m_n18;                                              // +0x18 the owner's character id
    int m_n1c;
    int m_n20;
    int m_n24;
    CStringW m_str28;                                       // +0x28
    __int64 m_n30;                                          // +0x30 compared to detect a changed house
    __int64 m_n38;
    unsigned char m_n40;
};
MS2_CHECK_SIZE(UserUGCMapInfo, 0x48);
