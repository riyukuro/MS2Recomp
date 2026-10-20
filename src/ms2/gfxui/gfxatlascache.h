// gfxatlascache.h - GFxAtlasCache (invented name: no RTTI, no vftable; 0x38 bytes): the GFx UI library's cache of texture
// atlas images, AtlasRecords by file name. A SingletonClass (instance pointer 0x143b0d780) created and destroyed by
// GFxService (new 0x1422ea54b, scalar deleting dtor 0x1422ea3f0, instance getter 0x1422eaa40 in ?\gfxservice.cpp).
// Code in unit_1422f77b0 (src/ms2/gfxui/gfxatlascache.cpp, 0x1422f77b0-0x1422f8c70). NOT an original header.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <efd/MemObject.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/singletonclass.h"
#include "ms2/gfxui/nigfxoverlayclick.h"
#include "GFx/GFx_ImageCreator.h"

class GFxAtlasCache : public efd::MemObject, public SingletonClass<GFxAtlasCache>
{
public:
    GFxAtlasCache();                                                    // 0x1422f77b0
    ~GFxAtlasCache();                                                   // 0x1422f77f0

    // The atlas record of strDir + strName: cached by strName, else the image is read through the info's image file
    // handler registry and cached (NULL if there is no registry; a failed read is not cached).
    AtlasRecord* FUN_1422f7840(const Scaleform::GFx::ImageCreateInfo& info, const CString& strDir,
        const CString& strName);                                        // 0x1422f7840

private:
    MS2_LAYOUT_FRIEND;
    CRBMap<CString, efd::SmartPointer<AtlasRecord> > m_records;         // +0x08 file name -> atlas record
};
MS2_CHECK_OFFSET(GFxAtlasCache, m_records, 0x08);
MS2_CHECK_SIZE(GFxAtlasCache, 0x38);
