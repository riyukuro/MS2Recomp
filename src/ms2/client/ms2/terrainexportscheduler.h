// TerrainExportScheduler (RTTI name): walks the list of map ids and asks the world manager to export each in turn.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/iworldservicecallback.h"

// World manager singleton (FUN_1403ed2d0 returns it). Names inferred.
class Unk_TESWorldMgr {
public:
    void FUN_141bbae40(IWorldServiceCallback* cb);          // register callback
    void FUN_141bbae80(IWorldServiceCallback* cb);          // unregister callback
    void FUN_141bbbe40(int mapId, int a, int b);            // move/export request
};
Unk_TESWorldMgr* FUN_1403ed2d0();

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

// The exe's array of map ids; the accessors are out-of-line instantiations elsewhere (bound by FUN_<va> name).
class Unk_TESArray : public ATL::CAtlArray<void*> {
public:
    void FUN_1402c2830();                                   // RemoveAll
    void FUN_1401855a0(int id);                             // Add
    int* FUN_140184510(unsigned __int64 index);                      // GetAt
    unsigned __int64 FUN_140186270();                                // GetCount
};

class TerrainExportScheduler : public IWorldServiceCallback {
public:
    TerrainExportScheduler();                               // 0x14183e270
    void FUN_14183e2c0(unsigned char select);
    unsigned char FUN_14183e450();
    virtual void vfunc_1(int);                              // 0x14183e460
    Unk_TESArray m_maps;                                    // +0x08
    unsigned __int64 m_cur;                                          // +0x28
};
MS2_CHECK_SIZE(TerrainExportScheduler, 0x30);
errno_t FUN_14183e520(void* dst, rsize_t dstSize, const void* src, rsize_t count);
