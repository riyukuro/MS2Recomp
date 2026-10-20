// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxAtlasCache, the GFx UI library's atlas image cache. See
// gfxatlascache.h.
// MS2-UNIT: unit_1422f77b0
// MS2-RANGE: 0x1422f77b0-0x1422f8c70 .text$mn
//
// The unit, file and class names are invented (the GFx UI library has no __FILE__ strings and the class no RTTI). The
// tail is the CRBMap<CString, efd::SmartPointer<AtlasRecord>> and SmartPointer<AtlasRecord> members, the
// SingletonClass<GFxAtlasCache> ctor/dtor and Scaleform::SysFile's implicit dtors.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/gfxui/gfxatlascache.h"
#include "Kernel/SF_SysFile.h"
#include "hook/ms2hook.h"

CString FUN_1401d2b10(const CString& a, const CString& b);              // ATL operator+(CString, CString)

// @0x1422f77b0
GFxAtlasCache::GFxAtlasCache()
{
}

// @0x1422f77f0
GFxAtlasCache::~GFxAtlasCache()
{
    m_records.RemoveAll();
}

// @0x1422f7840
AtlasRecord* GFxAtlasCache::FUN_1422f7840(const Scaleform::GFx::ImageCreateInfo& info, const CString& strDir,
    const CString& strName)
{
    efd::SmartPointer<AtlasRecord> spRecord = NULL;
    if (!m_records.Lookup(strName, spRecord))
    {
        Scaleform::Render::ImageFileHandlerRegistry* pRegistry = info.GetImageFileHandlerRegistry();
        if (pRegistry == NULL)
            return NULL;
        Scaleform::String strPath(FUN_1401d2b10(strDir, strName));
        Scaleform::SysFile file(strPath);
        Scaleform::Render::Image* pImage = pRegistry->ReadImage(&file);
        if (pImage != NULL)
        {
            // AtlasRecord holds the image through the casyncimageloader.h stand-in of Render::Image.
            m_records.SetAt(strName, spRecord = EE_NEW AtlasRecord((Unk_GfxImage*)pImage));
        }
    }
    return spRecord;
}
MS2_REPLACE_METHOD(0x1422f7840, GFxAtlasCache, FUN_1422f7840, 631, 0xA374C755);

// The exe calls memset in CRBTree::NewNode (no /Oi expansion): templates are instantiated at the end of the TU.
#pragma function(memset)
