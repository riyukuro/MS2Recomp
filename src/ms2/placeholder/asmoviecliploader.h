// asmoviecliploader.h - PLACEHOLDER for ASMovieClipLoader (RTTI .?AVASMovieClipLoader@@, 0x80 bytes, base ASEventDispatcher,
// vftable 0x143111c90, 1 slot: the dtor): the AS MovieClipLoader of a GFx movie (GFxMovie::m_40; GFxMovie::vfunc_11
// invokes "shutdown" on it). NOT an original header; the code is src/ms2/gfxui/asmoviecliploader.cpp
// (?\asmoviecliploader.cpp). Every member invokes the AS method of the same (commented) name; names are Ghidra's.
#pragma once

#include "ms2/placeholder/asdisplayobject.h"

class ASMovieClipLoader : public ASEventDispatcher
{
public:
    ASMovieClipLoader(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1422cfff0 (new 0x80 in gfxmoviedamage.cpp FUN_140b62350)
    virtual ~ASMovieClipLoader();                                   // 0 0x1422d0040 (scalar deleting 0x1422d0920)
    void LoadSwf(const CString& strPath, const CString& strName, unsigned int nDepth, int nFlags);   // loadSwf
    void UnloadSwf(const CString& strName);                     // unloadSwf
    void FUN_1422d01b0(const CString& strName, int n);              // unloadSwf(name, n)
    void UnloadCache();                                           // unloadCache
    void SwapDepthLayer(const CString& strName, int nLayer);         // swapDepthLayer
    void OnLostRenderDevice();                                           // onLostRenderDevice
    bool OnRestoreRenderDevice();                                           // onRestoreRenderDevice (always true)
    void PreloadSwf(const CString& strPath, const CString& strName, unsigned int nDepth);   // preloadSwf
    void PreloadSwfShow(const CString& strPath, const CString& strName, unsigned int nDepth);   // preloadSwfShow
    void PreloadSwfHide(const CString& strName, int n);              // preloadSwfHide
    void RemovePreloadSwf();                                           // removePreloadSwf
    void ReportAll();                                           // reportAll
    void ReportMemoryLeak();                                           // reportMemoryLeak
    void ReportForceGarbageCollect();                                           // reportForceGarbargeCollect (sic)
    void Shutdown();                                           // shutdown

    // Invoke helpers (inline COMDATs of this unit; probably AScript's variadic Invoke template, declared here because
    // only this unit instantiates them). All arguments by value: the callee destroys the strings.
    Scaleform::GFx::Value FUN_1422d06c0(const char* szMethod, CStringW a1, CString a2, unsigned int a3);
    Scaleform::GFx::Value FUN_1422d07e0(const char* szMethod, CStringW a1, CString a2, unsigned int a3, int a4);
};
MS2_CHECK_SIZE(ASMovieClipLoader, 0x80);
