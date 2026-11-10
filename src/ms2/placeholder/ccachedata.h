// ccachedata.h - PLACEHOLDER for CCacheData (RTTI .?AVCCacheData@@, 0x28 bytes, base CPtred, vftable 0x142ceee48,
// 1 slot). NOT an original header. Code owner: ?\cachedata.cpp (ctors 0x1401d1020 / 0x1401d1070 / 0x1401d2670,
// dtor 0x1401d1100, deleting dtor 0x1401d2d10). A CCacheData remembers the path of a loaded data file and its last-write
// time; FUN_1401d1320 reports whether the file changed on disk since it was loaded.
#pragma once

#include <afx.h>
#include <windows.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CCacheData : public CPtred
{
public:
    CCacheData();                       // 0x1401d1020
    CCacheData(CString strPath);        // 0x1401d1070
    CCacheData(const CCacheData& kOther);   // 0x1401d2670
    virtual ~CCacheData();              // 0x1401d1100

    CString* GetPath();           // address of the path string
    bool SetPath(CString strPath);    // records the loaded cache path and its file time, by value
    int FUN_1401d17f0(CString strPath, FILETIME* pTime);    // reads the last-write time of the file

    friend unsigned char FUN_1401d1320(CCacheData*);    // file changed since load
private:
    MS2_LAYOUT_FRIEND;
    FILETIME m_ftWrite;                 // +0x18 last-write time at load
    CString m_strPath;                  // +0x20
};
MS2_CHECK_SIZE(CCacheData, 0x28);
MS2_CHECK_OFFSET(CCacheData, m_ftWrite, 0x18);
MS2_CHECK_OFFSET(CCacheData, m_strPath, 0x20);
