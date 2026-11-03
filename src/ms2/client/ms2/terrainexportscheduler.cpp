// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\terrainexportscheduler.cpp
// MS2-RANGE: 0x14183e270-0x14183e640 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\terrainexportscheduler.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "terrainexportscheduler.h"
#include "ms2/client/ms2/worldservice.h"  // C3: WorldService::FUN_141bd3060
#include "ms2/commonfiles/fielddata.h"  // CFieldData::FUN_140374090 (the field list)
#include "hook/ms2hook.h"

// @0x14183e270
TerrainExportScheduler::TerrainExportScheduler() { m_cur = 0x7fffffff; }

// @0x14183e2c0
void TerrainExportScheduler::FUN_14183e2c0(unsigned char select)
{
    WorldService::GetInstance()->FUN_141bbae40((IWorldServiceCallback*)this);
    m_maps.RemoveAll();
    m_cur = 0;
    std::vector<MS2Ptr<CFieldData> > list;
    CFieldData::FUN_140374090(list);
    int curId = WorldService::GetInstance()->FUN_141bd3060();
    int index = 0;
    std::vector<MS2Ptr<CFieldData> >* range = &list;
    MS2Ptr<CFieldData>* it = range->_Unchecked_begin();
    MS2Ptr<CFieldData>* end = range->_Unchecked_end();
    for (; it != end; ++it) {
        MS2Ptr<CFieldData>& rec = *it;
        int id = rec.operator->()->m_nFieldID;
        reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&m_maps)->Add((unsigned int)id);
        if (select != 0 && curId == id)
            m_cur = index;
        index = index + 1;
    }
    unsigned* p = &m_maps[m_cur];
    WorldService::GetInstance()->FUN_141bbbe40(*p, 1, 0);
}

MS2_REPLACE_METHOD(0x14183E2C0, TerrainExportScheduler, FUN_14183e2c0, 383, 0xBF38375E);

// @0x14183e450
unsigned char TerrainExportScheduler::FUN_14183e450() { return 0; }

// @0x14183e460
void TerrainExportScheduler::vfunc_1(int)
{
    FUN_14183e450();
    WorldService* mgr = WorldService::GetInstance();
    unsigned __int64 next = m_cur + 1;
    m_cur = next;
    if (next < m_maps.GetCount()) {
        mgr->FUN_141bbbe40(m_maps[m_cur], 1, 0);
    } else {
        mgr->FUN_141bbae80((IWorldServiceCallback*)this);
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

