// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASMovieClipLoader, the AS swf loader of a GFx movie.
// MS2-UNIT: ?\asmoviecliploader.cpp
// MS2-RANGE: 0x1422cfff0-0x1422d0960 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asmoviecliploader.h"

#include "ms2/placeholder/asdata.h"

#include "hook/ms2hook.h"

// Scaleform::GFx::Value setters of the GFx UI library (asarray.cpp range).
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);               // Int
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);      // UInt
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);      // string
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);  // wide string
CStringW FUN_14016a730(const char* sz, int nCodePage);                  // widen (as commonfiles/packet.h)

// @0x1422cfff0
ASMovieClipLoader::ASMovieClipLoader(const Scaleform::GFx::Value& v, int nMovieId)
    : ASEventDispatcher(v, nMovieId)
{
}

// @0x1422d0040
ASMovieClipLoader::~ASMovieClipLoader()
{
}

// @0x1422d0070
void ASMovieClipLoader::FUN_1422d0070(const CString& strPath, const CString& strName, unsigned int nDepth, int nFlags)
{
    FUN_1422d07e0("loadSwf", FUN_14016a730(strPath, 0), strName, nDepth, nFlags);
}
MS2_REPLACE_METHOD(0x1422D0070, ASMovieClipLoader, FUN_1422d0070, 211, 0xF1BFBA1B);

// @0x1422d0150
void ASMovieClipLoader::FUN_1422d0150(const CString& strName)
{
    Invoke("unloadSwf", strName);
}
MS2_REPLACE_METHOD(0x1422D0150, ASMovieClipLoader, FUN_1422d0150, 87, 0x6F4CD396);

// @0x1422d01b0
void ASMovieClipLoader::FUN_1422d01b0(const CString& strName, int n)
{
    FUN_141312710("unloadSwf", strName, n);
}
MS2_REPLACE_METHOD(0x1422D01B0, ASMovieClipLoader, FUN_1422d01b0, 109, 0xD4040846);

// @0x1422d0230
void ASMovieClipLoader::FUN_1422d0230()
{
    Invoke("unloadCache");
}
MS2_REPLACE_METHOD(0x1422D0230, ASMovieClipLoader, FUN_1422d0230, 46, 0xF15A9A6C);

// @0x1422d0270
void ASMovieClipLoader::FUN_1422d0270(const CString& strName, int nLayer)
{
    FUN_141312710("swapDepthLayer", strName, nLayer);
}
MS2_REPLACE_METHOD(0x1422D0270, ASMovieClipLoader, FUN_1422d0270, 109, 0x7724665F);

// @0x1422d02f0
void ASMovieClipLoader::FUN_1422d02f0()
{
    Invoke("onLostRenderDevice");
}
MS2_REPLACE_METHOD(0x1422D02F0, ASMovieClipLoader, FUN_1422d02f0, 46, 0xD1CB9608);

// @0x1422d0330
bool ASMovieClipLoader::FUN_1422d0330()
{
    Invoke("onRestoreRenderDevice");
    return true;
}
MS2_REPLACE_METHOD(0x1422D0330, ASMovieClipLoader, FUN_1422d0330, 48, 0x7143CC8A);

// @0x1422d0370
void ASMovieClipLoader::FUN_1422d0370(const CString& strPath, const CString& strName, unsigned int nDepth)
{
    FUN_1422d06c0("preloadSwf", FUN_14016a730(strPath, 0), strName, nDepth);
}
MS2_REPLACE_METHOD(0x1422D0370, ASMovieClipLoader, FUN_1422d0370, 194, 0xF976056B);

// @0x1422d0440
void ASMovieClipLoader::FUN_1422d0440(const CString& strPath, const CString& strName, unsigned int nDepth)
{
    FUN_1422d06c0("preloadSwfShow", FUN_14016a730(strPath, 0), strName, nDepth);
}
MS2_REPLACE_METHOD(0x1422D0440, ASMovieClipLoader, FUN_1422d0440, 194, 0xD443684C);

// @0x1422d0510
void ASMovieClipLoader::FUN_1422d0510(const CString& strName, int n)
{
    FUN_141312710("preloadSwfHide", strName, n);
}
MS2_REPLACE_METHOD(0x1422D0510, ASMovieClipLoader, FUN_1422d0510, 109, 0x5AA7F243);

// @0x1422d0590
void ASMovieClipLoader::FUN_1422d0590()
{
    Invoke("removePreloadSwf");
}
MS2_REPLACE_METHOD(0x1422D0590, ASMovieClipLoader, FUN_1422d0590, 46, 0x9D7A5055);

// @0x1422d05d0
void ASMovieClipLoader::FUN_1422d05d0()
{
    Invoke("reportAll");
}
MS2_REPLACE_METHOD(0x1422D05D0, ASMovieClipLoader, FUN_1422d05d0, 46, 0x49F9AEBD);

// @0x1422d0610
void ASMovieClipLoader::FUN_1422d0610()
{
    Invoke("reportMemoryLeak");
}
MS2_REPLACE_METHOD(0x1422D0610, ASMovieClipLoader, FUN_1422d0610, 46, 0x3888FEE2);

// @0x1422d0650
void ASMovieClipLoader::FUN_1422d0650()
{
    Invoke("reportForceGarbargeCollect");
}
MS2_REPLACE_METHOD(0x1422D0650, ASMovieClipLoader, FUN_1422d0650, 46, 0xD2EA3DE7);

// @0x1422d0690
void ASMovieClipLoader::FUN_1422d0690()
{
    Invoke("shutdown");
}
MS2_REPLACE_METHOD(0x1422D0690, ASMovieClipLoader, FUN_1422d0690, 46, 0x81601D87);

// @0x1422d06c0
inline Scaleform::GFx::Value ASMovieClipLoader::FUN_1422d06c0(const char* szMethod, CStringW a1, CString a2, unsigned int a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd10(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1422d07e0
inline Scaleform::GFx::Value ASMovieClipLoader::FUN_1422d07e0(const char* szMethod, CStringW a1, CString a2, unsigned int a3, int a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bce70(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd10(args.FUN_1409b1f70(2), a3);
    FUN_1422bccb0(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// MS2-PIN: ??_GASMovieClipLoader@@UEAAPEAXI@Z 0x1422d0920
