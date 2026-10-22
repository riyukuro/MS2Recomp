// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). First translation unit of the client UGC download/upload
// code (the queue entry client\ms2\ugcmanager.cpp spans four TUs; see ugcmanager.h): CUgcCompress (zlib .m2u
// packages), a D3DX image converter, the upload/thumbnail file helpers and the CUgcDownloadLoad worker thread.
// MS2-UNIT: client\ms2\ugcmanager.cpp#1
// MS2-RANGE: 0x1418694d0-0x14186ef00 .text$mn
// MS2-RANGE: 0x14010eca0-0x14010eee0 .text$di
// MS2-RANGE: 0x142cbc260-0x142cbc320 .text$yd
// MS2-PIN: ??_7CUgcDownloadLoad@@6B?$TSingleton@VCUgcDownloadLoad@@@@@ 0x142f893a0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"

static CString s_strChartSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal",
                                        "EnumEnd"};

#include <time.h>
#include <io.h>
#include <d3dx9.h>
#include <NiDDSReader.h>
#include <NiImageConverter.h>
#include <NiPixelData.h>
#include <NiRect.h>
#include <NiRenderTargetGroup.h>
#include <NiSourceTexture.h>
#include <efd/utf8string.h>

#include "ugcmanager.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/cugcdownloaddown.h"
#include "ms2/placeholder/cugcdownloadload.h"
#include "ms2/placeholder/exception.h"
#include "ms2/placeholder/ms2memfile.h"
#include "ms2/placeholder/zlib125.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- other units --------------------------------------------------------------------------------------------------

CLogString* GetLogString();                                // the log singleton
// The scene-graph texture cache (CNifLoadingService-like; scenegraph units call it Unk_SgNifLoader).
class Unk_UgcTextureCache
{
public:
    NiTexturePtr FUN_141553eb0(CString strPath, NiTexture* pkSelf);
    NiTexturePtr FUN_141553910(CString strKey, CString strPath, int nPriority);
    NiTexturePtr FUN_1415534d0(CString strKey, NiPixelDataPtr spPixelData, int nPriority);
};
Unk_UgcTextureCache* FUN_140a0afd0();
NiImageConverter* FUN_141851720();
extern NiTexture::FormatPrefs DAT_1439fc800;                // NiSourceTexture's default format preferences
// The world service and its local player (MyPC).
class Unk_UgcWorld { public: void* FUN_141bd0cc0(); };
Unk_UgcWorld* FUN_1403ed2d0();
// A client config singleton; +0xd8 is the capture file path.
class Unk_UgcClientPaths
{
public:
    void* m_pad[0xd8 / 8];
    CString m_strCaptureFile;                               // +0xd8
};
Unk_UgcClientPaths* FUN_1401d31f0();
CUgcDownloadDown* FUN_1414a57f0();
LPDIRECT3DDEVICE9 FUN_1422cf0d0();                          // the renderer's D3D device

// Upload/convert paths (all under ".\Custom\Convert").
CStringW FUN_14102a420(const CStringW& strSrc);            // upload.dds
CStringW FUN_14102a4d0();                                   // the icon file
CStringW FUN_14102a5d0(const CStringW& strSrc);
CStringW FUN_14102a720(const CStringW& strSrc);            // the banner file
CStringW FUN_14102aa70(const CStringW& strSrc);
CStringW FUN_14102a870(const CStringW& strOrgFile);        // upload.m2u
CStringW FUN_14102a920(const CStringW& strZipFile);        // <name>.dds for a downloaded package
int FUN_14102ac40(const CStringW& strPath, CAtlArray<CStringW>& parts);   // drive/dir/name/ext of an existing file
CStringW FUN_141026920(int nKind);                          // a UGC directory
bool FUN_141027420(CString strName);
CString FUN_141027200(CString strName);
void FUN_140841420(CStringW& str);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);
CString FUN_14016a5c0(const char* psz, int nCodePage);
CString FUN_14016a600(const wchar_t* psz, int nCodePage);
CStringW FUN_14016a730(const char* psz, int nCodePage);
CString FUN_140390ea0(const wchar_t* psz, int nCodePage);
int FUN_14028e900(CString strPath);                         // deletes a file
int SaveBufferToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nTarget,
                      NiRect<unsigned int> kRect, int bLogErrors);
int SaveTextureToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiTexture* pkTexture);
int SaveTextureToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiTexture* pkTexture);
int SaveRenderTargetToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat,
                            NiRenderTargetGroup* pkGroup, NiRect<unsigned int> kRect);

// The start handshake of CThread::vfunc_1.
class Unk_140659080
{
public:
    void FUN_1401d42d0();                                   // the thread is running
    int FUN_140659080(int nResult);                         // the thread failed to start
};

// The unit's log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0).
template <class T> inline void Unk_UgcLog(CLogString* log, int level, int category, const wchar_t* format,
                                          const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}
template <class T1, class T2> inline void Unk_UgcLog(CLogString* log, int level, int category,
                                                     const wchar_t* format, const T1& first, const T2& second)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(second)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second), args));
}

// ---- CUgcCompress -------------------------------------------------------------------------------------------------

// @0x1418694d0
CUgcCompress::CUgcCompress()
{
    m_pOrgFile = NULL;
    m_pZipFile = NULL;
    m_bCompress = 1;
    m_pBuffer = NULL;
    m_nBufferSize = 0;
    m_nDataSize = 0;
    m_strOrgFile = L"";
    m_strZipFile = L"";
}

// @0x1418695a0
CUgcCompress::~CUgcCompress()
{
    Close();
    if (m_pBuffer)
    {
        EE_FREE(m_pBuffer);
        m_pBuffer = NULL;
    }
}

// Packs strOrgFile into the upload package. Returns 0 or an error code.
// @0x141869620
int CUgcCompress::Compress(const CStringW& strOrgFile, void* pUnused)
{
    int nResult = 1;
    try
    {
        CStringW strZipFile = FUN_14102a870(strOrgFile);
        if (strZipFile.GetLength() == 0)
            throw Exception("zip_file", 0x51);
        if (_waccess(strZipFile, 0) == 0)
            DeleteFileW(strZipFile);
        CStringW strRead(L"rb");
        CStringW strWrite(L"wb");
        m_pOrgFile = _wfopen(strOrgFile, strRead);
        if (m_pOrgFile == NULL)
            throw Exception("fopen_org", 0x53);
        m_pZipFile = _wfopen(strZipFile, strWrite);
        if (m_pZipFile == NULL)
            throw Exception("fopen_zip", 0x54);
        m_bCompress = 1;
        nResult = DoCompress();
        if (nResult != 0)
            throw Exception("do_compress", 0x55);
        nResult = 0;
        m_strOrgFile = strOrgFile;
        m_strZipFile = strZipFile;
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    catch (CFileException* e)
    {
        e->Delete();
        nResult = 0x33;
    }
    Close();
    return nResult;
}
MS2_REPLACE_METHOD(0x141869620, CUgcCompress, Compress, 838, 0x45F8FCD9);

// Inflates a downloaded package into the buffer. Returns 0 or an error code.
// @0x141869970
int CUgcCompress::Decompress(const CStringW& strZipFile, unsigned __int64 userData)
{
    int nResult = 1;
    try
    {
        CStringW strOrgFile = FUN_14102a920(strZipFile);
        if (strOrgFile.GetLength() == 0)
            throw Exception("org_file", 0x52);
        CStringW strRead(L"rb");
        m_pZipFile = _wfopen(strZipFile, strRead);
        if (m_pZipFile == NULL)
            throw Exception("fopen_zip", 0x54);
        m_bCompress = 0;
        nResult = DoDecompress();
        if (nResult != 0)
            throw Exception("do_decompress", 0x56);
        Unk_UgcLog(GetLogString(), 0xc, 0x13, L"CUgcCompress::Decompress : strOrgFile({0}), strZipFile({1})",
                   strOrgFile, strZipFile);
        nResult = 0;
        m_strOrgFile = strOrgFile;
        m_strZipFile = strZipFile;
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    catch (CFileException* e)
    {
        e->Delete();
        nResult = 0x33;
    }
    Close();
    return nResult;
}
MS2_REPLACE_METHOD(0x141869970, CUgcCompress, Decompress, 660, 0x1075C4E4);

// @0x141869c10
CStringW CUgcCompress::GetOrgFile()
{
    return m_strOrgFile;
}
MS2_REPLACE_METHOD(0x141869c10, CUgcCompress, GetOrgFile, 66, 0x867FA0DD);

// @0x141869c60
CStringW CUgcCompress::GetZipFile()
{
    return m_strZipFile;
}
MS2_REPLACE_METHOD(0x141869c60, CUgcCompress, GetZipFile, 66, 0x6D1FA115);

// A memory file over a copy of the inflated data (the caller deletes it).
// @0x141869cb0
efd::File* CUgcCompress::CreateMemFile()
{
    if (m_pBuffer == NULL)
        return NULL;
    if (m_nDataSize == 0)
        return NULL;
    BYTE* pData = EE_ALLOC(BYTE, m_nDataSize);
    memcpy(pData, m_pBuffer, m_nDataSize);
    efd::File* pFile = new (efd::MemHint(efd::MemHint::NONE)) MS2MemFile(pData, m_nDataSize);
    return pFile;
}
MS2_REPLACE_METHOD(0x141869cb0, CUgcCompress, CreateMemFile, 253, 0x75FE33B2);

// @0x141869dc0
BYTE* CUgcCompress::GetBuffer()
{
    if (m_pBuffer == NULL)
        return NULL;
    if (m_nDataSize == 0)
        return NULL;
    return m_pBuffer;
}
MS2_REPLACE_METHOD(0x141869dc0, CUgcCompress, GetBuffer, 46, 0x007E20CE);

// @0x141869e00
int CUgcCompress::GetDataSize()
{
    return m_nDataSize;
}
MS2_REPLACE_METHOD(0x141869e00, CUgcCompress, GetDataSize, 14, 0x9A8B24F3);

// @0x141869e20
void CUgcCompress::Close()
{
    if (m_pOrgFile)
    {
        fclose(m_pOrgFile);
        m_pOrgFile = NULL;
    }
    if (m_pZipFile)
    {
        fclose(m_pZipFile);
        m_pZipFile = NULL;
    }
}
MS2_REPLACE_METHOD(0x141869e20, CUgcCompress, Close, 91, 0xD98F1616);

// zlib's zpipe def(): org file -> zip file.
// @0x141869e90
int CUgcCompress::DoCompress()
{
    if (m_bCompress == 0)
        return 0x15;
    if (m_pOrgFile == NULL)
        return 0xb;
    if (m_pZipFile == NULL)
        return 0xc;
    int ret, flush;
    unsigned have;
    z_stream strm;
    unsigned char in[0x10000];
    unsigned char out[0x18000];
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK)
        return ret;
    do
    {
        strm.avail_in = (uInt)fread(in, 1, 0x10000, m_pOrgFile);
        if (ferror(m_pOrgFile))
        {
            (void)deflateEnd(&strm);
            return Z_ERRNO;
        }
        flush = feof(m_pOrgFile) ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = in;
        do
        {
            strm.avail_out = 0x18000;
            strm.next_out = out;
            ret = deflate(&strm, flush);
            if (ret == Z_STREAM_ERROR)
                return Z_STREAM_ERROR;
            have = 0x18000 - strm.avail_out;
            if (fwrite(out, 1, have, m_pZipFile) != have || ferror(m_pZipFile))
            {
                (void)deflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);
    } while (flush != Z_FINISH);
    (void)deflateEnd(&strm);
    return Z_OK;
}
MS2_REPLACE_METHOD(0x141869e90, CUgcCompress, DoCompress, 538, 0xCBB46787);

// zlib's zpipe inf(): zip file -> m_pBuffer (doubling from 1 MB).
// MS2-FUNCTIONAL: same zlib calls, buffer growth and results; locals are laid out differently.
// @0x14186a0b0
int CUgcCompress::DoDecompress()
{
    if (m_bCompress == 1)
        return 0x16;
    if (m_pZipFile == NULL)
        return 0xc;
    int ret;
    unsigned have;
    z_stream strm;
    unsigned char in[0x10000];
    unsigned char out[0x18000];
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit(&strm);
    if (ret != Z_OK)
        return ret;
    if (m_pBuffer)
    {
        EE_FREE(m_pBuffer);
        m_pBuffer = NULL;
    }
    m_nBufferSize = 0x100000;
    m_pBuffer = EE_ALLOC(BYTE, m_nBufferSize);
    int nTotal = 0;
    int status = 0;
    do
    {
        strm.avail_in = (uInt)fread(in, 1, 0x10000, m_pZipFile);
        if (ferror(m_pZipFile))
        {
            (void)inflateEnd(&strm);
            return Z_ERRNO;
        }
        if (strm.avail_in == 0)
            break;
        strm.next_in = in;
        do
        {
            strm.avail_out = 0x18000;
            strm.next_out = out;
            status = inflate(&strm, Z_NO_FLUSH);
            if (status == Z_STREAM_ERROR)
                return Z_STREAM_ERROR;
            switch (status)
            {
            case Z_NEED_DICT:
                status = Z_DATA_ERROR;
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                (void)inflateEnd(&strm);
                return status;
            }
            have = 0x18000 - strm.avail_out;
            if (m_nBufferSize <= (int)(nTotal + have))
            {
                m_nBufferSize <<= 1;
                BYTE* pBuffer = EE_ALLOC(BYTE, m_nBufferSize);
                memcpy(pBuffer, m_pBuffer, nTotal);
                EE_FREE(m_pBuffer);
                m_pBuffer = pBuffer;
            }
            memcpy(m_pBuffer + nTotal, out, have);
            nTotal += have;
        } while (strm.avail_out == 0);
    } while (status != Z_STREAM_END);
    (void)inflateEnd(&strm);
    if (status == Z_STREAM_END)
    {
        m_nDataSize = nTotal;
        return Z_OK;
    }
    return Z_DATA_ERROR;
}
MS2_REPLACE_METHOD(0x14186a0b0, CUgcCompress, DoDecompress, 849, 0x80556A4D);

// ---- CUgcImageConverter -------------------------------------------------------------------------------------------

// @0x14186a430
CUgcImageConverter::CUgcImageConverter()
{
    m_pSrcTexture = NULL;
    m_pDstTexture = NULL;
    Clear();
}

// @0x14186a4a0
CUgcImageConverter::~CUgcImageConverter()
{
    Clear();
}

// @0x14186a4f0
CStringW CUgcImageConverter::GetSrcFile()
{
    return m_strSrcFile;
}
MS2_REPLACE_METHOD(0x14186a4f0, CUgcImageConverter, GetSrcFile, 62, 0xC2D7E9DB);

// @0x14186a540
CStringW CUgcImageConverter::GetDstFile()
{
    return m_strDstFile;
}
MS2_REPLACE_METHOD(0x14186a540, CUgcImageConverter, GetDstFile, 66, 0x305A5B04);

// @0x14186a590
int CUgcImageConverter::GetState()
{
    return m_nState;
}
MS2_REPLACE_METHOD(0x14186a590, CUgcImageConverter, GetState, 14, 0xC2D0886F);

// An item texture: DXT5 .dds (or A8R8G8B8 .png), nSize square or the source size.
// @0x14186a5b0
int CUgcImageConverter::ConvertTexture(const CStringW& strSrc, int nSize, bool bPng)
{
    int nResult = 1;
    m_strSrcFile = strSrc;
    nResult = LoadFile();
    if (nResult != 0)
        return nResult;
    CStringW strDst = FUN_14102a420(strSrc);
    if (strDst.GetLength() == 0)
        return 0x4a;
    if (_waccess(strDst, 0) == 0)
        DeleteFileW(strDst);
    m_strDstFile = strDst;
    m_nState = 1;
    D3DFORMAT eFormat = D3DFMT_DXT5;
    D3DXIMAGE_FILEFORMAT eFileFormat = D3DXIFF_DDS;
    if (bPng)
    {
        eFormat = D3DFMT_A8R8G8B8;
        eFileFormat = D3DXIFF_PNG;
    }
    if (nSize == 0)
        nResult = Convert(eFormat, m_nWidth, m_nHeight, m_nMipLevels);
    else
        nResult = Convert(eFormat, nSize, nSize, nSize);
    if (nResult != 0)
        return nResult;
    nResult = Save(eFileFormat);
    if (nResult != 0)
        return nResult;
    return 0;
}
MS2_REPLACE_METHOD(0x14186a5b0, CUgcImageConverter, ConvertTexture, 489, 0x215C6204);

// A 48x48 icon png.
// @0x14186a7a0
int CUgcImageConverter::ConvertIcon(const CStringW& strSrc)
{
    int nResult = 1;
    m_strSrcFile = strSrc;
    nResult = LoadFile();
    if (nResult != 0)
        return nResult;
    CStringW strDst = FUN_14102a4d0();
    if (strDst.GetLength() == 0)
        return 0x4a;
    if (_waccess(strDst, 0) == 0)
        DeleteFileW(strDst);
    m_strDstFile = strDst;
    m_nState = 1;
    nResult = Convert(D3DFMT_A8R8G8B8, 0x30, 0x30, 0x30);
    if (nResult != 0)
        return nResult;
    nResult = Save(D3DXIFF_PNG);
    if (nResult != 0)
        return nResult;
    return 0;
}
MS2_REPLACE_METHOD(0x14186a7a0, CUgcImageConverter, ConvertIcon, 365, 0x41E5A3A4);

// A 107x107 thumbnail png.
// @0x14186a920
int CUgcImageConverter::ConvertThumbnail(const CStringW& strSrc)
{
    int nResult = 1;
    m_strSrcFile = strSrc;
    nResult = LoadFile();
    if (nResult != 0)
        return nResult;
    CStringW strDst = FUN_14102a5d0(strSrc);
    if (strDst.GetLength() == 0)
        return 0x4a;
    if (_waccess(strDst, 0) == 0)
        DeleteFileW(strDst);
    m_strDstFile = strDst;
    m_nState = 1;
    nResult = Convert(D3DFMT_A8R8G8B8, 0x6b, 0x6b, 0x6b);
    if (nResult != 0)
        return nResult;
    nResult = Save(D3DXIFF_PNG);
    if (nResult != 0)
        return nResult;
    return 0;
}
MS2_REPLACE_METHOD(0x14186a920, CUgcImageConverter, ConvertThumbnail, 370, 0xD4A339FA);

// An in-memory image (a downloaded package) to a DXT5 .dds.
// @0x14186aaa0
int CUgcImageConverter::ConvertMemory(const CStringW& strSrc, const void* pData, int nSize)
{
    int nResult = 1;
    m_strSrcFile = strSrc;
    nResult = LoadMemory(pData, nSize);
    if (nResult != 0)
        return nResult;
    CStringW strDst = FUN_14102aa70(strSrc);
    if (strDst.GetLength() == 0)
        return 0x4a;
    if (_waccess(strDst, 0) == 0)
        DeleteFileW(strDst);
    m_strDstFile = strDst;
    m_nState = 1;
    D3DFORMAT eFormat = D3DFMT_DXT5;
    D3DXIMAGE_FILEFORMAT eFileFormat = D3DXIFF_DDS;
    nResult = Convert(eFormat, m_nWidth, m_nHeight, m_nMipLevels);
    if (nResult != 0)
        return nResult;
    nResult = Save(eFileFormat);
    if (nResult != 0)
        return nResult;
    return 0;
}
MS2_REPLACE_METHOD(0x14186aaa0, CUgcImageConverter, ConvertMemory, 420, 0xEE2E9C1A);

// A banner png that fits in 384x240.
// MS2-FUNCTIONAL: same scale-to-384x240 maths, calls and results; one extra double temporary shifts the frame.
// @0x14186ac50
int CUgcImageConverter::ConvertBanner(const CStringW& strSrc)
{
    int nResult = 1;
    m_strSrcFile = strSrc;
    nResult = LoadFile();
    if (nResult != 0)
        return nResult;
    CStringW strDst = FUN_14102a720(strSrc);
    if (strDst.GetLength() == 0)
        return 0x4a;
    if (_waccess(strDst, 0) == 0)
        DeleteFileW(strDst);
    m_strDstFile = strDst;
    m_nState = 1;
    int nWidth = m_nWidth;
    int nHeight = m_nHeight;
    if (m_nWidth > 384 || m_nHeight > 240)
    {
        double dScale = 1.0;
        double dScaleX = 384.0 / m_nWidth;
        double dScaleY = 240.0 / m_nHeight;
        dScale = min(dScaleX, dScaleY);
        nWidth = (int)(m_nWidth * dScale);
        nHeight = (int)(m_nHeight * dScale);
    }
    int nConvert = Convert(D3DFMT_A8R8G8B8, min(nWidth, 384), min(nHeight, 240), 0);
    if (nConvert != 0)
        return nConvert;
    int nSave = Save(D3DXIFF_PNG);
    if (nSave != 0)
        return nSave;
    return 0;
}
MS2_REPLACE_METHOD(0x14186ac50, CUgcImageConverter, ConvertBanner, 729, 0xB46317E2);

// @0x14186af30
void CUgcImageConverter::Clear()
{
    if (m_pSrcTexture)
    {
        m_pSrcTexture->Release();
        m_pSrcTexture = NULL;
    }
    if (m_pDstTexture)
    {
        m_pDstTexture->Release();
        m_pDstTexture = NULL;
    }
    m_nWidth = 0;
    m_nHeight = 0;
    m_nDepth = 0;
    m_nMipLevels = 0;
    m_strSrcFile = "";
    m_strDstFile = "";
    m_nState = 0;
}
MS2_REPLACE_METHOD(0x14186af30, CUgcImageConverter, Clear, 218, 0xB0E746A7);

// Loads m_strSrcFile (must be a 2D texture) into m_pSrcTexture.
// @0x14186b010
int CUgcImageConverter::LoadFile()
{
    int nResult = 1;
    try
    {
        D3DXIMAGE_INFO kInfo;
        HRESULT hr = D3DXGetImageInfoFromFileW(m_strSrcFile, &kInfo);
        if (FAILED(hr))
            throw Exception(0x3d);
        if (kInfo.ResourceType != D3DRTYPE_TEXTURE)
            throw Exception(0x3e);
        D3DXIMAGE_INFO kLoaded;
        hr = D3DXCreateTextureFromFileExW(FUN_1422cf0d0(), m_strSrcFile, kInfo.Width, kInfo.Height, kInfo.MipLevels, 0,
                                          kInfo.Format, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0,
                                          &kLoaded, NULL, &m_pSrcTexture);
        if (FAILED(hr))
            throw Exception(0x3f);
        m_nWidth = kLoaded.Width;
        m_nHeight = kLoaded.Height;
        m_nDepth = 0;
        m_nMipLevels = kLoaded.MipLevels;
        nResult = 0;
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x14186b010, CUgcImageConverter, LoadFile, 506, 0x1B7B1CE7);

// @0x14186b210
int CUgcImageConverter::LoadMemory(const void* pData, int nSize)
{
    int nResult = 1;
    try
    {
        D3DXIMAGE_INFO kInfo;
        HRESULT hr = D3DXGetImageInfoFromFileInMemory(pData, nSize, &kInfo);
        if (FAILED(hr))
            throw Exception(0x3d);
        if (kInfo.ResourceType != D3DRTYPE_TEXTURE)
            throw Exception(0x3e);
        D3DXIMAGE_INFO kLoaded;
        hr = D3DXCreateTextureFromFileInMemoryEx(FUN_1422cf0d0(), pData, nSize, kInfo.Width, kInfo.Height,
                                                 kInfo.MipLevels, 0, kInfo.Format, D3DPOOL_MANAGED, D3DX_FILTER_NONE,
                                                 D3DX_FILTER_NONE, 0, &kLoaded, NULL, &m_pSrcTexture);
        if (FAILED(hr))
            throw Exception(0x3f);
        m_nWidth = kLoaded.Width;
        m_nHeight = kLoaded.Height;
        m_nDepth = 0;
        m_nMipLevels = kLoaded.MipLevels;
        nResult = 0;
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x14186b210, CUgcImageConverter, LoadMemory, 524, 0x14839640);

// Creates m_pDstTexture (eFormat, nWidth x nHeight) from the source texture.
// MS2-FUNCTIONAL: same D3D calls, checks and error codes; the device pointer goes through an extra temporary.
// @0x14186b430
int CUgcImageConverter::Convert(D3DFORMAT eFormat, int nWidth, int nHeight, int nMipSize)
{
    HRESULT hr;
    int nResult = 0;
    try
    {
        LPDIRECT3DDEVICE9 pDevice = FUN_1422cf0d0();
        IDirect3DTexture9* pSrc = m_pSrcTexture;
        IDirect3DTexture9* pDst = NULL;
        D3DSURFACE_DESC kDesc;
        pSrc->GetLevelDesc(0, &kDesc);
        D3DFORMAT eSrcFormat = kDesc.Format;
        if (eSrcFormat == D3DFMT_DXT2 || eSrcFormat == D3DFMT_DXT4)
        {
            if (eFormat == D3DFMT_DXT1)
                throw Exception(0x41);
            else if (eFormat != D3DFMT_DXT2 && eFormat != D3DFMT_DXT4)
                throw Exception(0x42);
        }
        if ((eFormat == D3DFMT_DXT1 || eFormat == D3DFMT_DXT2 || eFormat == D3DFMT_DXT3 || eFormat == D3DFMT_DXT4 ||
             eFormat == D3DFMT_DXT5) &&
            m_nWidth % 4 == 0 && m_nHeight % 4 == 0)
        {
            m_nMipLevels = GetMipLevels(nMipSize, nMipSize);
        }
        hr = pDevice->CreateTexture(nWidth, nHeight, m_nMipLevels, 0, eFormat, D3DPOOL_MANAGED, &pDst, NULL);
        if (FAILED(hr))
            throw Exception(0x40);
        hr = CopySurfaces(0x7fffffff, pDst);
        if (FAILED(hr))
            throw Exception(0x43);
        if (m_pDstTexture)
        {
            m_pDstTexture->Release();
            m_pDstTexture = NULL;
        }
        m_pDstTexture = pDst;
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x14186b430, CUgcImageConverter, Convert, 803, 0x11BB8AF3);

// @0x14186b760
int CUgcImageConverter::GetMipLevels(int nWidth, int nHeight)
{
    int nX = nWidth;
    int nY = nHeight;
    int nLevelsX = 0;
    int nLevelsY = 0;
    while (nX > 0)
    {
        nLevelsX++;
        nX /= 2;
    }
    while (nY > 0)
    {
        nLevelsY++;
        nY /= 2;
    }
    int nLevels = max(nLevelsX, nLevelsY);
    return nLevels;
}
MS2_REPLACE_METHOD(0x14186b760, CUgcImageConverter, GetMipLevels, 154, 0x244E00CE);

// @0x14186b800
HRESULT CUgcImageConverter::CopySurfaces(int nUnused, IDirect3DTexture9* pDst)
{
    IDirect3DTexture9* pSrc = m_pSrcTexture;
    IDirect3DSurface9* pSrcSurface = NULL;
    HRESULT hr = pSrc->GetSurfaceLevel(0, &pSrcSurface);
    for (int i = 0; i < m_nMipLevels; i++)
    {
        IDirect3DSurface9* pDstSurface = NULL;
        hr = pDst->GetSurfaceLevel(i, &pDstSurface);
        hr = D3DXLoadSurfaceFromSurface(pDstSurface, NULL, NULL, pSrcSurface, NULL, NULL, D3DX_FILTER_BOX, 0);
        if (pDstSurface)
        {
            pDstSurface->Release();
            pDstSurface = NULL;
        }
    }
    if (pSrcSurface)
    {
        pSrcSurface->Release();
        pSrcSurface = NULL;
    }
    return S_OK;
}
MS2_REPLACE_METHOD(0x14186b800, CUgcImageConverter, CopySurfaces, 292, 0xF13CEFB2);

// @0x14186b930
int CUgcImageConverter::Save(D3DXIMAGE_FILEFORMAT eFormat)
{
    if (m_pDstTexture == NULL)
        return 0x47;
    if (m_strDstFile.GetLength() == 0)
        return 0x48;
    HRESULT hr = D3DXSaveTextureToFileW(m_strDstFile, eFormat, m_pDstTexture, NULL);
    if (FAILED(hr))
        return 0x49;
    return 0;
}
MS2_REPLACE_METHOD(0x14186b930, CUgcImageConverter, Save, 128, 0x258C734C);

// ---- upload / thumbnail helpers ----------------------------------------------------------------------------------

// Converts an upload's local file for its UGC type; the result names the source and the converted file.
// @0x14186b9c0
Unk_UgcFileResult ChangeFormat(int nType, MS2Ptr<CUploadFile> pUploadFile, int nSize, bool bPng)
{
    Unk_UgcFileResult result;
    try
    {
        if (pUploadFile == NULL)
            throw Exception("pUploadFile", 0xb);
        CStringW strPath = pUploadFile->GetPath();
        int nResult = 1;
        CUgcImageConverter converter;
        if (nType == 1 || nType == 3 || nType == 2 || nType == 7)
            nResult = converter.ConvertTexture(strPath, nSize, bPng);
        else if (nType == 9)
            nResult = converter.ConvertBanner(strPath);
        else if (nType == 5 || nType == 6 || nType == 8 || nType == 0xca || nType == 0xa)
            ;
        else if (nType == 0xc9 || nType == 0xd1)
            nResult = converter.ConvertIcon(strPath);
        if (nResult != 0)
            throw Exception("ChangeFormat", nResult);
        result.m_strName = converter.GetSrcFile();
        result.m_strPath = converter.GetDstFile();
        result.m_bTemporary = converter.GetState();
        result.m_nResult = 0;
    }
    catch (Exception& e)
    {
        result.Reset();
        result.m_nResult = e.GetCode();
    }
    return result;
}
MS2_REPLACE(0x14186b9c0, ChangeFormat, 866, 0x95460236);

// A texture from an image file; a .jpg goes through the converter first.
// MS2-FUNCTIONAL: same cache lookups, conversions and texture creation; temporaries are ordered differently.
// @0x14186bd30
NiTexturePtr LoadUgcTexture(const CStringW& strPath, int nSize, bool bPng)
{
    CAtlArray<CStringW> parts;
    if (FUN_14102ac40(strPath, parts) != 0)
        return NULL;
    CStringW strExt = parts.GetAt(3);
    FUN_140841420(strExt);
    CStringW strConverted;
    bool bConverted = false;
    if (FUN_1403b3c40(strExt, L".jpg"))
    {
        CUgcImageConverter converter;
        if (converter.ConvertTexture(strPath, nSize, bPng) != 0)
            return NULL;
        bConverted = true;
        strConverted = converter.GetDstFile();
    }
    CStringW strFile = bConverted ? strConverted : strPath;
    NiImageConverter* pkConverter = NiDynamicCast(NiImageConverter, FUN_141851720());
    NiPixelDataPtr spPixelData = pkConverter->ReadImageFile((const wchar_t*)strFile, NULL);
    NiTexturePtr spTexture = NiSourceTexture::Create(spPixelData, DAT_1439fc800, true);
    if (bConverted)
        DeleteFileW(strConverted);
    return spTexture;
}
MS2_REPLACE(0x14186bd30, LoadUgcTexture, 810, 0x1C895533);

// A texture through the scene-graph cache (loaded and cached on a miss).
// @0x14186c060
NiTexturePtr LoadCachedTexture(const CStringW& strPath)
{
    CString strKey = FUN_14016a600(strPath, 0);
    NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141553eb0(strKey, NULL);
    if (spTexture != NULL)
        return spTexture;
    efd::utf8string strFile(FUN_140390ea0(strPath, 0));
    NiImageConverter* pkConverter = NiDynamicCast(NiImageConverter, FUN_141851720());
    NiPixelDataPtr spPixelData = pkConverter->ReadImageFile(strFile.c_str(), NULL);
    NiTexturePtr spLoaded = FUN_140a0afd0()->FUN_1415534d0(strKey, spPixelData, 5);
    return spLoaded;
}
MS2_REPLACE(0x14186c060, LoadCachedTexture, 707, 0x0965241C);

// Makes the thumbnail png of an image file. Returns 0 or an error code.
// @0x14186c330
int ConvertIconFile(const CStringW& strPath)
{
    if (strPath.GetLength() == 0)
        return 0x17;
    int nResult = 1;
    try
    {
        CStringW strFile(strPath);
        if (_waccess(strFile, 0) != 0)
            throw Exception(0x18);
        CUgcImageConverter converter;
        nResult = converter.ConvertThumbnail(strFile);
        if (nResult != 0)
            throw Exception(nResult);
        nResult = 0;
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    return nResult;
}
MS2_REPLACE(0x14186c330, ConvertIconFile, 264, 0x5A322CD9);

// Captures a screen rectangle as "cmr_<time>.png" and makes its thumbnail.
// @0x14186c440
Unk_UgcFileResult SaveUgcThumbnailImage(NiRect<unsigned int> kRect, int nTarget)
{
    Unk_UgcFileResult result;
    CStringW strName;
    CStringW strPath;
    try
    {
        void* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC == NULL)
            throw Exception("mypc", 0xc);
        __time64_t tNow;
        time(&tNow);
        strName.Format(L"cmr_%I64u.png", tNow);
        strPath.Format(L"%s\\%s", (const wchar_t*)FUN_141026920(5), (const wchar_t*)strName);
        if (SaveBufferToFileW(&strPath, D3DXIFF_PNG, nTarget, kRect, 0) == 0)
            throw Exception("WriteToFile", 0x16);
        int nResult = ConvertIconFile(strPath);
        if (nResult != 0)
            throw Exception("SaveUgcThumbnailImage", nResult);
        result.m_strName = strName;
        result.m_strPath = strPath;
        result.m_bTemporary = 1;
        result.m_nResult = 0;
    }
    catch (Exception& e)
    {
        result.Reset();
        result.m_nResult = e.GetCode();
    }
    return result;
}
MS2_REPLACE(0x14186c440, SaveUgcThumbnailImage, 800, 0xBFE05CC3);

// Saves a render target rectangle to the capture file.
// @0x14186c770
Unk_UgcFileResult SaveRenderTargetImage(NiRect<unsigned int> kRect, NiRenderTargetGroup* pkGroup)
{
    Unk_UgcFileResult result;
    CString strPath = "";
    try
    {
        void* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC == NULL)
            throw Exception("mypc", 0xc);
        __time64_t tNow;
        time(&tNow);
        strPath = FUN_1401d31f0()->m_strCaptureFile;
        if (_access(strPath, 0) == 0)
            FUN_14028e900(strPath);
        if (SaveRenderTargetToFileA(&strPath, D3DXIFF_PNG, pkGroup, kRect) == 0)
            throw Exception("WriteToFile", 0x16);
        result.m_strName = "";
        result.m_strPath = (const char*)strPath;
        result.m_bTemporary = 1;
        result.m_nResult = 0;
    }
    catch (Exception& e)
    {
        result.Reset();
        result.m_nResult = e.GetCode();
    }
    return result;
}
MS2_REPLACE(0x14186c770, SaveRenderTargetImage, 617, 0x1E31ADBF);

// Saves a texture to the capture file.
// @0x14186c9e0
Unk_UgcFileResult SaveTextureImage(NiTexture* pkTexture)
{
    Unk_UgcFileResult result;
    CString strPath = "";
    try
    {
        void* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC == NULL)
            throw Exception("mypc", 0xc);
        __time64_t tNow;
        time(&tNow);
        strPath = FUN_1401d31f0()->m_strCaptureFile;
        if (_access(strPath, 0) == 0)
            FUN_14028e900(strPath);
        if (SaveTextureToFileA(&strPath, D3DXIFF_PNG, pkTexture) == 0)
            throw Exception("WriteToFile", 0x16);
        result.m_strName = L"";
        result.m_strPath = (const char*)strPath;
        result.m_bTemporary = 1;
        result.m_nResult = 0;
    }
    catch (Exception& e)
    {
        result.Reset();
        result.m_nResult = e.GetCode();
    }
    return result;
}
MS2_REPLACE(0x14186c9e0, SaveTextureImage, 574, 0xB98EB11A);

// Saves a 48x48 texture of an image file (the blueprint icon) to the capture file.
// @0x14186cc30
Unk_UgcFileResult SaveIconImage(CStringW strFile)
{
    Unk_UgcFileResult result;
    CString strPath = "";
    try
    {
        void* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMyPC == NULL)
            throw Exception("mypc", 0xc);
        __time64_t tNow;
        time(&tNow);
        strPath = FUN_1401d31f0()->m_strCaptureFile;
        if (_access(strPath, 0) == 0)
            FUN_14028e900(strPath);
        NiTexturePtr spTexture = LoadUgcTexture(strFile, 0x30, true);
        if (SaveTextureToFileA(&strPath, D3DXIFF_PNG, spTexture) == 0)
            throw Exception("WriteToFile", 0x16);
        result.m_strName = "";
        result.m_strPath = (const char*)strPath;
        result.m_bTemporary = 1;
        result.m_nResult = 0;
    }
    catch (Exception& e)
    {
        result.Reset();
        result.m_nResult = e.GetCode();
    }
    return result;
}
MS2_REPLACE(0x14186cc30, SaveIconImage, 659, 0xE3EE6385);

// Saves a template texture as "template_<time>.png" in directory nKind and makes its thumbnail.
// @0x14186ced0
int SaveTextureTemplate(NiTexture* pkTexture, int nUnused, int nKind, CStringW& strName)
{
    int nResult = 1;
    CStringW strPath;
    try
    {
        __time64_t tNow;
        time(&tNow);
        strName.Format(L"template_%I64u.png", tNow);
        strPath.Format(L"%s\\%s", (const wchar_t*)FUN_141026920(nKind), (const wchar_t*)strName);
        if (SaveTextureToFileW(&strPath, D3DXIFF_PNG, pkTexture) == 0)
            throw Exception(0x16);
        nResult = ConvertIconFile(strPath);
        if (nResult != 0)
            throw Exception(nResult);
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
        Unk_UgcLog(GetLogString(), 1, 0x13, L"[E] SaveTextureTemplate : result = {0}", nResult);
    }
    return nResult;
}
MS2_REPLACE(0x14186ced0, SaveTextureTemplate, 365, 0xEC59FBC5);

// The banner variant (directory 3).
// @0x14186d050
int SaveTextureBannerTemplate(NiTexture* pkTexture, int nUnused, CStringW& strName)
{
    int nResult = 1;
    CStringW strPath;
    try
    {
        __time64_t tNow;
        time(&tNow);
        strName.Format(L"template_%I64u.png", tNow);
        strPath.Format(L"%s\\%s", (const wchar_t*)FUN_141026920(3), (const wchar_t*)strName);
        if (SaveTextureToFileW(&strPath, D3DXIFF_PNG, pkTexture) == 0)
            throw Exception(0x16);
        nResult = ConvertIconFile(strPath);
        if (nResult != 0)
            throw Exception(nResult);
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
        Unk_UgcLog(GetLogString(), 1, 0x13, L"[E] SaveTextureBannerTemplate : result = {0}", nResult);
    }
    return nResult;
}
MS2_REPLACE(0x14186d050, SaveTextureBannerTemplate, 358, 0xDEB8AECC);

// ---- CUgcDownloadLoad ---------------------------------------------------------------------------------------------

// @0x14186d1c0
CUgcDownloadLoad::CUgcDownloadLoad() : m_list(10)
{
    m_hEvent = NULL;
    m_bStop = 0;
    m_hSemaphore = CreateSemaphoreA(NULL, 0, 0x7fffffff, NULL);
}

// @0x14186d290
CUgcDownloadLoad::~CUgcDownloadLoad()
{
    if (m_hSemaphore)
        CloseHandle(m_hSemaphore);
    if (m_hEvent)
        CloseHandle(m_hEvent);
}

// The worker: takes up to 10 queued files at a time, turns each into a cached texture and reports the names back.
// MS2-FUNCTIONAL: same queue/batch logic, loaders and callbacks; the frame layout and some temporaries differ.
// @0x14186d350
unsigned int CUgcDownloadLoad::vfunc_1(void* pParam, Unk_140659080& start)
{
    m_hEvent = CreateEventA(NULL, FALSE, FALSE, NULL);
    if (m_hEvent == NULL)
    {
        start.FUN_140659080(E_FAIL);
        return -1;
    }
    start.FUN_1401d42d0();
    while (WaitForSingleObject(m_hSemaphore, INFINITE), m_bStop == 0)
    {
        CAtlList<MS2Ptr<CUgcLoadData> > batch(10);
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
        {
            if (m_list.GetCount() == 0)
                continue;
            int nCount = 0;
            POSITION pos = m_list.GetHeadPosition();
            do
            {
                if (pos == NULL)
                    break;
                POSITION posCur = pos;
                m_list.GetNext(pos);
                batch.AddTail(m_list.GetAt(posCur));
                m_list.RemoveAt(posCur);
                nCount++;
            } while (nCount < 10);
        }
        if (batch.GetCount() == 0)
            continue;
        CAtlList<CString> loaded(10);
        CAtlList<CString> failed(10);
        for (POSITION pos = batch.GetHeadPosition(); pos != NULL; batch.GetNext(pos))
        {
            MS2Ptr<CUgcLoadData> pData = batch.GetAt(pos);
            if (pData == NULL)
                continue;
            if (pData->m_bPackage == 0)
                continue;
            CUgcCompress compress;
            int nDecompress = compress.Decompress(FUN_14016a730(pData->m_strPath, 0), pData->m_userData);
            if (nDecompress != 0)
                continue;
            NiTexturePtr spTexture = 0;
            CStringW strOrgFile = compress.GetOrgFile();
            if (strOrgFile.GetLength() == 0)
                continue;
            efd::File* pFile = compress.CreateMemFile();
            NiDDSReader kReader;
            NiPixelDataPtr spPixelData = kReader.ReadFile(*pFile, NULL);
            if (spPixelData != NULL)
            {
                if (FUN_140a0afd0())
                    spTexture = FUN_140a0afd0()->FUN_1415534d0(FUN_14016a5c0(pData->m_strName, 0), spPixelData, 5);
            }
            else
            {
                CUgcImageConverter converter;
                int nConvert = 1;
                int nSize = compress.GetDataSize();
                BYTE* pBuffer = compress.GetBuffer();
                nConvert = converter.ConvertMemory(FUN_14016a730(pData->m_strName, 0), pBuffer, nSize);
                if (nConvert == 0)
                {
                    CStringW strDstFile = converter.GetDstFile();
                    if (FUN_140a0afd0())
                        spTexture = FUN_140a0afd0()->FUN_141553910(FUN_14016a5c0(pData->m_strName, 0),
                                                                   FUN_14016a600(strDstFile, 0), 5);
                    if (_waccess(strDstFile, 0) == 0)
                        DeleteFileW(strDstFile);
                }
            }
            if (spTexture != NULL)
                loaded.AddTail(pData->m_strName);
            else
                failed.AddTail(pData->m_strName);
            if (pFile)
                EE_DELETE pFile;
        }
        for (POSITION pos = loaded.GetHeadPosition(); pos != NULL; loaded.GetNext(pos))
        {
            CString strName = loaded.GetAt(pos);
            if (!FUN_141027420(strName))
                strName = FUN_141027200(strName);
            if (FUN_1414a57f0())
                FUN_1414a57f0()->Finish(strName, 0);
        }
        for (POSITION pos = failed.GetHeadPosition(); pos != NULL; failed.GetNext(pos))
        {
            CString strName = failed.GetAt(pos);
            if (!FUN_141027420(strName))
                strName = FUN_141027200(strName);
            if (FUN_1414a57f0())
                FUN_1414a57f0()->Finish(strName, 0x20);
        }
        batch.RemoveAll();
        loaded.RemoveAll();
        failed.RemoveAll();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14186d350, CUgcDownloadLoad, vfunc_1, 3105, 0x4192C150);

// @0x14186df80
void CUgcDownloadLoad::Stop()
{
    if (m_hEvent)
        SetEvent(m_hEvent);
    if (m_hSemaphore)
    {
        m_bStop = 1;
        ReleaseSemaphore(m_hSemaphore, 1, NULL);
        FUN_1401d3510(INFINITE);
    }
}
MS2_REPLACE_METHOD(0x14186df80, CUgcDownloadLoad, Stop, 118, 0x486B701B);

// Queues a downloaded file (ignored when it doesn't exist).
// @0x14186e000
void CUgcDownloadLoad::Push(CString strName, CString strPath, int nType, unsigned __int64 userData)
{
    if (_access(strPath, 0) != 0)
        return;
    BOOL bPackage = FALSE;
    if (strName.Find(".m2u") >= 0)
        bPackage = TRUE;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        MS2Ptr<CUgcLoadData> pData = new CUgcLoadData;
        pData->m_strName = strName;
        pData->m_strPath = strPath;
        pData->m_bPackage = bPackage;
        pData->m_userData = userData;
        m_list.AddTail(pData);
        ReleaseSemaphore(m_hSemaphore, 1, NULL);
    }
}
MS2_REPLACE_METHOD(0x14186e000, CUgcDownloadLoad, Push, 451, 0xF39258F8);

// @0x14186e3f0
CUgcDownloadLoad::CUgcLoadData::CUgcLoadData()
{
    m_strName = "";
    m_strPath = "";
    m_bPackage = 0;
    m_userData = 0;
}

// @0x14186ede0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
