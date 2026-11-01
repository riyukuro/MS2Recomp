// TerrainExportScheduler (RTTI name): walks the list of map ids and asks the world manager to export each in turn.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/iworldservicecallback.h"

// Unrecovered vector of 0x10-byte map descriptors (24 bytes) with a fill helper.
struct Unk_TESMapRecord { void* pad0; void* pad8; };
MS2_CHECK_SIZE(Unk_TESMapRecord, 0x10);
struct Unk_TESMapInfo { void* pad0; void* pad8; void* pad10; int id; };
Unk_TESMapInfo* FUN_140300710(Unk_TESMapRecord* r);
class Unk_TESMapList {
public:
    Unk_TESMapList();                                       // 0x1406feea0
    ~Unk_TESMapList();                                      // 0x1406ff2b0
    void FUN_140374090();                                   // fill
    Unk_TESMapRecord* FUN_140704520();                     // begin
    Unk_TESMapRecord* FUN_140704540();                     // end
    void* pad[3];
};
MS2_CHECK_SIZE(Unk_TESMapList, 0x18);

class TerrainExportScheduler : public IWorldServiceCallback {
public:
    TerrainExportScheduler();                               // 0x14183e270
    void FUN_14183e2c0(unsigned char select);
    unsigned char FUN_14183e450();
    virtual void vfunc_1(int);                              // 0x14183e460
    ATL::CAtlArray<unsigned> m_maps;                        // +0x08
    unsigned __int64 m_cur;                                          // +0x28
};
MS2_CHECK_SIZE(TerrainExportScheduler, 0x30);
errno_t FUN_14183e520(void* dst, rsize_t dstSize, const void* src, rsize_t count);
