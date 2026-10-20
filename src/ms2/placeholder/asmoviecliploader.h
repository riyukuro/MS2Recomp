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
    void FUN_1422d0070(const CString& strPath, const CString& strName, unsigned int nDepth, int nFlags);   // loadSwf
    void FUN_1422d0150(const CString& strName);                     // unloadSwf
    void FUN_1422d01b0(const CString& strName, int n);              // unloadSwf(name, n)
    void FUN_1422d0230();                                           // unloadCache
    void FUN_1422d0270(const CString& strName, int nLayer);         // swapDepthLayer
    void FUN_1422d02f0();                                           // onLostRenderDevice
    bool FUN_1422d0330();                                           // onRestoreRenderDevice (always true)
    void FUN_1422d0370(const CString& strPath, const CString& strName, unsigned int nDepth);   // preloadSwf
    void FUN_1422d0440(const CString& strPath, const CString& strName, unsigned int nDepth);   // preloadSwfShow
    void FUN_1422d0510(const CString& strName, int n);              // preloadSwfHide
    void FUN_1422d0590();                                           // removePreloadSwf
    void FUN_1422d05d0();                                           // reportAll
    void FUN_1422d0610();                                           // reportMemoryLeak
    void FUN_1422d0650();                                           // reportForceGarbargeCollect (sic)
    void FUN_1422d0690();                                           // shutdown

    // Invoke helpers (inline COMDATs of this unit; probably AScript's variadic Invoke template, declared here because
    // only this unit instantiates them). All arguments by value: the callee destroys the strings.
    Scaleform::GFx::Value FUN_1422d06c0(const char* szMethod, CStringW a1, CString a2, unsigned int a3);
    Scaleform::GFx::Value FUN_1422d07e0(const char* szMethod, CStringW a1, CString a2, unsigned int a3, int a4);
};
MS2_CHECK_SIZE(ASMovieClipLoader, 0x80);
