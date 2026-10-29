// COutPacketBuffer: RTTI and clientreconnectionstructs.cpp layout; names inferred.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
class CGameSocket; class COutPacket;
class COutPacketBuffer : public CPtred {
public:
    COutPacketBuffer(); virtual ~COutPacketBuffer();
    void FUN_140208960(CGameSocket*,COutPacket&);
    void PushPendingPacket(COutPacket&);
    void FUN_140208d40(); void FUN_140209340(int); void FUN_140209450(int); void FUN_140209430();
private:
    void* p18;void* p20;void* p28;void* p30;
    CLockCriticalSection lock;
    void* p68;void* p70;void* p78;void* p80;void* p88;void* p90;
    void* p98;void* pa0;void* pa8;void* pb0;void* pb8;void* pc0;
    void* pc8;void* pd0;void* pd8;void* pe0;void* pe8;void* pf0;
};
MS2_CHECK_SIZE(COutPacketBuffer,0xf8);
