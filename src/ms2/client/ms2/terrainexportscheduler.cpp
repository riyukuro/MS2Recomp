// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\terrainexportscheduler.cpp
// MS2-RANGE: 0x14183e270-0x14183e640 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\terrainexportscheduler.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "terrainexportscheduler.h"
#include "hook/ms2hook.h"

// @0x14183e270
TerrainExportScheduler::TerrainExportScheduler() { m_cur = 0x7fffffff; }

// @0x14183e2c0
void TerrainExportScheduler::FUN_14183e2c0(unsigned char select)
{
    FUN_1403ed2d0()->FUN_141bbae40(this);
    m_maps.FUN_1402c2830();
    m_cur = 0;
    Unk_TESMapList list;
    list.FUN_140374090();
    int curId = FUN_1403ed2d0()->FUN_141bd3060();
    int index = 0;
    Unk_TESMapList* range = &list;
    Unk_TESMapRecord* it = range->FUN_140704520();
    Unk_TESMapRecord* end = range->FUN_140704540();
    for (; it != end; ++it) {
        Unk_TESMapRecord& rec = *it;
        int id = FUN_140300710(&rec)->id;
        m_maps.FUN_1401855a0(id);
        if (select != 0 && curId == id)
            m_cur = index;
        index = index + 1;
    }
    int* p = m_maps.FUN_140184510(m_cur);
    FUN_1403ed2d0()->FUN_141bbbe40(*p, 1, 0);
}

MS2_REPLACE_METHOD(0x14183E2C0, TerrainExportScheduler, FUN_14183e2c0, 383, 0xBF38375E);

// @0x14183e450
unsigned char TerrainExportScheduler::FUN_14183e450() { return 0; }

// @0x14183e460
void TerrainExportScheduler::vfunc_1(int)
{
    FUN_14183e450();
    Unk_TESWorldMgr* mgr = FUN_1403ed2d0();
    unsigned __int64 next = m_cur + 1;
    m_cur = next;
    if (next < m_maps.FUN_140186270()) {
        mgr->FUN_141bbbe40(*m_maps.FUN_140184510(m_cur), 1, 0);
    } else {
        mgr->FUN_141bbae80(this);
        MessageBoxA(0, "Export Complete!", "Yeah", 0);
    }
}

MS2_REPLACE_METHOD(0x14183E460, TerrainExportScheduler, vfunc_1, 182, 0xFFEAFFC5);

// @0x14183e520 (the UCRT header-inline memmove_s from corecrt_memcpy_s.h, emitted here as an ordinary function)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode)                                                           \
    {                                                                                                          \
        int _Expr_val = !!(expr);                                                                              \
        if (!(_Expr_val)) {                                                                                    \
            errno = errorcode;                                                                                 \
            _invalid_parameter_noinfo();                                                                       \
            return errorcode;                                                                                  \
        }                                                                                                      \
    }
errno_t FUN_14183e520(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0)
        return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x14183e450, TerrainExportScheduler, FUN_14183e450, 8, 0x41132FCD);

