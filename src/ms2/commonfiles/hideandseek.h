// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: commonfiles\hideandseek.h (name assumed from the
// unit path: the .cpp's __FILE__ string is not in the exe for this unit).
//
// The hide-and-seek mini game data: HideAndSeek::Info (RTTI .?AVInfo@HideAndSeek@@, 0x38 bytes: one player's round state,
// sent and received as a packet record) and HideAndSeek::ObjectData (RTTI .?AVObjectData@HideAndSeek@@, a CCacheData).
// The unit also owns the lazily loaded riding object table (Table/Server/hideAndSeek.xml: <field mapCode ridingObject="a,b,c"/>).
// Names: FUN_<va> are non-virtual members / free functions; fields are invented.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"

class COutputStream;
class CInPacket;

namespace HideAndSeek
{
    class Info : public CPtred
    {
    public:
        Info();                                                     // 0x14050a120
        virtual ~Info();                                            //  0 0x14050a1a0 (??_G 0x14050bfd0)

        void FUN_14050a1f0();                                       // reset the round state
        void FUN_14050a250(COutputStream& out);                     // write the record
        void FUN_14050a320(CInPacket& in);                          // read the record
        bool FUN_14050a490();                                       // m_18
        bool FUN_14050a4d0();                                       // m_19
        bool FUN_14050a510();                                       // m_1a
        void FUN_14050a530(__int64 nAdd, unsigned short nRule);     // m_20 += min(nAdd, the rule's limit)
        void FUN_14050a5a0(__int64 nValue, unsigned short nRule);   // m_20 = min(nValue, the rule's limit)
        __int64 FUN_14050a600();                                    // m_20
        void FUN_14050a620();                                       // ++m_28
        int FUN_14050a660();                                        // m_28
        int FUN_14050a6a0();                                        // m_2c
        int FUN_14050a6e0();                                        // m_30

    private:
        MS2_LAYOUT_FRIEND;
        bool m_18;                                                  // +0x18
        bool m_19;                                                  // +0x19
        bool m_1a;                                                  // +0x1a
        __int64 m_20;                                               // +0x20
        int m_28;                                                   // +0x28
        int m_2c;                                                   // +0x2c (1 = m_30 follows in the record)
        int m_30;                                                   // +0x30
    };
    MS2_CHECK_SIZE(Info, 0x38);

    class ObjectData : public CCacheData
    {
    public:
        ObjectData();                                               // 0x14050a700
        virtual ~ObjectData();                                      //  0 0x14050a740 (??_G 0x14050c010)
    };
    MS2_CHECK_SIZE(ObjectData, 0x28);

    void FUN_14050a770(unsigned nMapCode, std::vector<int>& out);        // the riding objects of a map (loads the table on first use)
    void FUN_14050a830();                                           // load Table/Server/hideAndSeek.xml
}
