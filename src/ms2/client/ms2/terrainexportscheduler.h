// TerrainExportScheduler (RTTI name): walks the list of map ids and asks the world manager to export each in turn.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/iworldservicecallback.h"


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
