// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Texture utilities: D3D surface/texture helpers, pixel-data blits and
// resampling, screenshot capture (D3DX save, JPEG/PNG), thread-local NiImageConverter.
// MS2-UNIT: client\ms2\textureutil.cpp
// MS2-RANGE: 0x14010dd90-0x14010ddc0 .text$di
// MS2-RANGE: 0x14184c790-0x1418519c0 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\textureutil.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <time.h>
#include <shlobj.h>
#include <comdef.h>
#include <d3dx9.h>
#include <NiDX9Renderer.h>
#include <NiDX9TextureData.h>
#include <NiDX92DBufferData.h>
#include <NiSourceTexture.h>
#include <NiPixelData.h>
#include <NiRect.h>
#include <NiImageConverter.h>
#include <NiDevImageConverter.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderer.h>
#include <efd/ILogger.h>
#include <efd/LoggerMacros.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/uimessagebox.h"
#include <string>
#include "hook/ms2hook.h"

// ---- out-of-unit callees and data (bound to the exe by their FUN_<va> / DAT_<va> names) ----
extern char DAT_143d6eb58;
void* FUN_140aadf80();                                      // the application window object
HWND FUN_14209c720(void* pkWindow);                         // its HWND
class Unk_14025e7a0;
Unk_14025e7a0* FUN_14025e7a0();                             // UI service singleton
Ni2DBuffer* FUN_1422afcf0(Unk_14025e7a0* pkService);        // its scene capture buffer
// The exe's RGBA32 (symbols.tsv maps ?RGBA32@NiPixelFormat to a different static).
extern const NiPixelFormat DAT_1439fb040;                                  // MS2Renderer::ms_RTTI
void FUN_140a34190(void* pDst, const void* pSrc, size_t n);   // bounded memcpy helper
int FUN_1416b0b80(unsigned int uiFBMode);                   // frame-buffer mode -> D3DMULTISAMPLE_TYPE
unsigned int FUN_1416b0b60(unsigned int uiFBMode);          // frame-buffer mode -> multisample quality

// screenshot plumbing from other units
extern char DAT_143b059e8;                                  // render-target registry singleton holder
void* FUN_14127bf80(void* pkHolder);                        // registry singleton
void* FUN_140af7da0(void* pkRegistry);                      // its current scene
NiRenderTargetGroup* FUN_14127cca0(void* pkScene);          // the scene's render-target group
class Unk_1409a8b20 { public: NiPointer<NiRenderTargetGroup> FUN_1416a3fb0(); };   // the renderer wrapper
Unk_1409a8b20* FUN_1409a8b20();
CStringW FUN_1401d0080(const CStringW& kA, const CStringW& kB);   // CStringW concatenation
CStringW FUN_14052bd00(int nStringId, const CStringW& kArg);      // localized string with one argument
CStringW FUN_1401e8510(const wchar_t* pwcFormat, const CStringW& kArg);   // StringFormat(const wchar_t*, const CStringW&)
void FUN_1412751b0(const CStringW& kText, int nSeconds);    // on-screen notice
Unk_MessageBoxPtr FUN_14151f820();                          // the message box currently shown
void* FUN_140534fc0(const Unk_MessageBoxPtr& kBox);
void* FUN_140534fe0(const Unk_MessageBoxPtr& kBox);
const CStringW& FUN_141a02ce0(void* pkBoxData);             // message box name
void FUN_14151f200();                                       // close the current message box
void FUN_140d73aa0(CStringW kText, int nType, void* pkOwner, CStringW kTag);   // show a message box
void* FUN_140d8ee90();                                      // quest/achievement event sink (may be null)
void FUN_140a1f970(void* pkSink, const CStringA& kName, const CStringA& kArg);
int FUN_1414a5a40(CStringW kPath);                          // create a directory (-1 on failure)
std::string FUN_14083fa60(const char* pcData, unsigned int uiLength);   // encode a byte string
void* FUN_1403ed2b0();                                      // display settings
float FUN_141adbe70(void* pkSettings);                      // UI scale
void FUN_141d38fa0();
void* FUN_14208a860(unsigned __int64 ullSize, unsigned int uiCategory);   // tracked allocation
void* FUN_140876480(void* pkOut, int nCategory);            // memory category helper, returns unsigned int*
NiDevImageConverter* FUN_141d34210(void* pkMemory);         // NiDevImageConverter constructor
NiImageReader* FUN_140d9aba0(void* pkMemory);               // MS2PNGReader constructor

// A thread-local storage slot (the TLS index lives in the object).
class Unk_TlsSlot
{
public:
    // @0x1418518c0
    Unk_TlsSlot() : m_dwIndex(TlsAlloc()) {}
    // @0x1418518e0
    ~Unk_TlsSlot()
    {
        if (IsValid())
        {
            TlsFree(m_dwIndex);
        }
    }
    // @0x141851920
    Unk_TlsSlot& Set(NiDevImageConverter* const& pkValue)
    {
        LPVOID pvValue = pkValue;
        TlsSetValue(m_dwIndex, pvValue);
        return *this;
    }
    // @0x141851960
    void* Get()
    {
        LPVOID pvValue = TlsGetValue(m_dwIndex);
        return pvValue;
    }
    // @0x141851990
    bool IsValid() { return m_dwIndex != 0xffffffff; }

    DWORD m_dwIndex;
};
MS2_CHECK_SIZE(Unk_TlsSlot, 4);

static int s_iScreenshotCounter;          // 0x143aef498: screenshots taken this run (numbers the file names)
static Unk_TlsSlot s_kConverterSlot;      // 0x143aef49c: the per-thread image converter

// the 4-byte RGBA pixel value (base constructor lives in another unit)
struct Unk_Pixel32 {
    unsigned char m_c[4];
    Unk_Pixel32(unsigned char r, unsigned char g, unsigned char b, unsigned char a);   // 0x141047040
};
struct Unk_TexColor : public Unk_Pixel32 {
    // @0x141851480
    Unk_TexColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : Unk_Pixel32(r, g, b, a) {}
};
MS2_CHECK_SIZE(Unk_TexColor, 4);

// @0x14184c790
// @0x14184c7b0
// (CRT time.h inline wrappers: localtime / time)

// Creates an A8R8G8B8 render-target surface of the given size, using the multisample mode the renderer was created with.
// @0x14184c7d0
IDirect3DSurface9* CreateRenderTargetSurface(unsigned int uiWidth, unsigned int uiHeight)
{
    NiDX9Renderer* pkRenderer = (NiDX9Renderer*)NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer != NULL)
    {
        D3DFORMAT eFormat = D3DFMT_A8R8G8B8;
        unsigned int uiCreateWidth;
        unsigned int uiCreateHeight;
        unsigned int uiUseFlags;
        NiWindowRef kWndDevice;
        NiWindowRef kWndFocus;
        unsigned int uiAdapter;
        NiDX9Renderer::DeviceDesc eDesc;
        NiDX9Renderer::FrameBufferFormat eFBFormat;
        NiDX9Renderer::DepthStencilFormat eDSFormat;
        NiDX9Renderer::PresentationInterval ePresentationInterval;
        NiDX9Renderer::SwapEffect eSwapEffect;
        unsigned int uiFBMode;
        unsigned int uiBackBufferCount;
        unsigned int uiRefreshRate;
        pkRenderer->GetCreationParameters(uiCreateWidth, uiCreateHeight, uiUseFlags, kWndDevice, kWndFocus, uiAdapter, eDesc,
            eFBFormat, eDSFormat, ePresentationInterval, eSwapEffect, uiFBMode, uiBackBufferCount, uiRefreshRate);
        D3DMULTISAMPLE_TYPE eMultiSample = (D3DMULTISAMPLE_TYPE)FUN_1416b0b80(uiFBMode);
        DWORD uiQuality = FUN_1416b0b60(uiFBMode);
        LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
        if (pkDevice != NULL)
        {
            IDirect3DSurface9* pkSurface = NULL;
            HRESULT hr = E_FAIL;
            hr = pkDevice->CreateRenderTarget(uiWidth, uiHeight, eFormat, eMultiSample, uiQuality, FALSE, &pkSurface, NULL);
            if (SUCCEEDED(hr))
            {
                return pkSurface;
            }
        }
    }
    return NULL;
}

// ---- unit-local thread-local image converter (accessors defined later in the file) ----
NiImageConverter* FUN_141851720();      // get (creating on first use) the calling thread's NiImageConverter
int CountMipLevels(int iWidth, int iHeight);   // defined below
void FUN_141851840(NiDevImageConverter* pkConverter);   // defined below
int SaveBufferToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nTarget,
    NiRect<unsigned int> kRect, int bLogErrors);
int SaveSurfaceToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, IDirect3DSurface9* pkSurface,
    NiRect<unsigned int> kRect, int bLogErrors, float fScale);
int SaveBufferToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nTarget,
    NiRect<unsigned int> kRect, int bLogErrors);
int SaveSurfaceToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, IDirect3DSurface9* pkSurface,
    NiRect<unsigned int> kRect, int bLogErrors, float fScale);

// Copies a source texture through D3DX into a fresh RGBA32 texture, reads the pixels back and converts them to the
// source texture's own pixel format.
// @0x14184c9c0
NiSourceTexture* CopyTexturePixels(NiTexture* pkTexture, bool bMipmap, bool bStatic)
{
    if (pkTexture == NULL)
    {
        return NULL;
    }

    IDirect3DSurface9* pkSurfaceSrc = NULL;
    IDirect3DTexture9* pkD3DTexture = NULL;
    IDirect3DSurface9* pkSurfaceDest = NULL;

    const NiPixelFormat* pkFormat = pkTexture->GetPixelFormat();
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = NiTexture::FormatPrefs::TRUE_COLOR_32;
    kPrefs.m_eMipMapped = NiTexture::FormatPrefs::NO;

    NiTexture::RendererData* pkRendererData = pkTexture->GetRendererData();
    pkD3DTexture = (IDirect3DTexture9*)((NiDX9TextureData*)pkRendererData)->GetD3DTexture();
    D3DSURFACE_DESC kDesc;
    pkD3DTexture->GetLevelDesc(0, &kDesc);
    pkD3DTexture->GetSurfaceLevel(0, &pkSurfaceSrc);

    NiPixelData* pkScratch = NiNew NiPixelData(kDesc.Width, kDesc.Height, DAT_1439fb040, 1, 1);
    NiPointer<NiSourceTexture> spScratch = NiSourceTexture::Create(pkScratch, kPrefs, true);
    NiTexture::RendererData* pkScratchData = spScratch->GetRendererData();
    IDirect3DTexture9* pkScratchTexture = (IDirect3DTexture9*)((NiDX9TextureData*)pkScratchData)->GetD3DTexture();
    pkScratchTexture->GetSurfaceLevel(0, &pkSurfaceDest);

    HRESULT hr = D3DXLoadSurfaceFromSurface(pkSurfaceDest, NULL, NULL, pkSurfaceSrc, NULL, NULL, D3DX_FILTER_NONE, 0);
    if (hr != 0)
    {
        EE_LOG_AT(1, 1, ("Error 0x%08x: %s", hr, _com_error(hr).ErrorMessage()), MS2_THIS_FILE, 0x65);
    }
    pkSurfaceSrc->Release();

    D3DLOCKED_RECT kLocked;
    if (pkSurfaceDest->LockRect(&kLocked, NULL, D3DLOCK_READONLY) < 0)
    {
        return NULL;
    }

    NiPointer<NiPixelData> spPixels(NiNew NiPixelData(kDesc.Width, kDesc.Height, *pkFormat, 1, 1));
    if (spPixels == NULL)
    {
        pkSurfaceDest->UnlockRect();
        return NULL;
    }

    unsigned int uiRowBytes = spPixels->GetWidth(0, 0) * spPixels->GetPixelStride();
    unsigned char* pucDst = spPixels->GetPixels(0, 0);
    unsigned char* pucSrc = (unsigned char*)kLocked.pBits;
    for (unsigned int uiRow = 0; uiRow < kDesc.Height; uiRow++)
    {
        FUN_140a34190(pucDst, pucSrc, uiRowBytes);
        pucDst += uiRowBytes;
        pucSrc += kLocked.Pitch;
    }
    pkSurfaceDest->UnlockRect();
    pkSurfaceDest->Release();

    NiImageConverter* pkConverter = NiDynamicCast(NiImageConverter, FUN_141851720());
    NiPointer<NiPixelData> spConverted = pkConverter->ConvertPixelData(*spPixels, DAT_1439fb040, NULL, bMipmap);
    kPrefs.m_eMipMapped = NiTexture::FormatPrefs::YES;
    NiSourceTexture* pkResult = NiSourceTexture::Create(spConverted, kPrefs, bStatic);
    return pkResult;
}

// Blits a source texture's pixels into a destination pixel buffer at the given rectangle origin, scaling the RGB channels by
// fAlpha when it is not fully opaque.
// @0x14184d0a0
// MS2-FUNCTIONAL: the exe keeps the texture's vtable pointer in extra locals around the width/height virtual calls (+0x10 frame).
void BlitTexturePixels(NiSourceTexture* pkSource, NiPixelData* pkDest, const NiRect<unsigned int>& kRect, float fAlpha)
{
    if (pkSource == NULL || pkDest == NULL)
    {
        return;
    }

    fAlpha += 0.0019607844f;    // half a unit of 1/255 so the truncating conversions below round
    NiPointer<NiPixelData> spSrcPixels = pkSource->GetSourcePixelData();
    if (spSrcPixels == NULL)
    {
        pkSource->LoadPixelDataFromFile();
        spSrcPixels = pkSource->GetSourcePixelData();
    }
    if (spSrcPixels == NULL)
    {
        return;
    }

    NiImageConverter* pkConverter = NiDynamicCast(NiImageConverter, FUN_141851720());
    spSrcPixels = pkConverter->ConvertPixelData(*spSrcPixels, DAT_1439fb040, NULL, false);

    unsigned int uiStride = pkDest->GetPixelStride();
    int iDestWidth = pkDest->GetWidth(0, 0);
    unsigned char* pucDestBase = pkDest->GetPixels(0, 0);
    unsigned char* pucSrcBase = spSrcPixels->GetPixels(0, 0);

    if ((int)(fAlpha * 255.0f) == 0xff)
    {
        for (unsigned int uiRow = 0; uiRow < pkSource->GetHeight(); uiRow++)
        {
            unsigned long long ullBytes = (unsigned int)(pkSource->GetWidth() * uiStride);
            FUN_140a34190(pucDestBase + (kRect.m_left + (uiRow + kRect.m_top) * iDestWidth) * uiStride,
                pucSrcBase + (unsigned int)(uiRow * (pkSource->GetWidth() * uiStride)), ullBytes);
        }
    }
    else
    {
        for (unsigned int uiRow = 0; uiRow < pkSource->GetHeight(); uiRow++)
        {
            for (unsigned int uiCol = 0; uiCol < pkSource->GetWidth(); uiCol++)
            {
                unsigned char* pucDst = pucDestBase + (uiCol + kRect.m_left + (uiRow + kRect.m_top) * iDestWidth) * uiStride;
                unsigned char* pucSrc = pucSrcBase + (uiCol + uiRow * pkSource->GetWidth()) * uiStride;
                for (unsigned int uiChannel = 0; uiChannel < 3; uiChannel++)
                {
                    float fValue = *pucSrc * fAlpha;
                    unsigned int uiValue;
                    if (fValue > 255.0f)
                    {
                        uiValue = 0xff;
                    }
                    else
                    {
                        uiValue = (unsigned char)(int)fValue;
                    }
                    *pucDst = (unsigned char)uiValue;
                    pucDst++;
                    pucSrc++;
                }
                *pucDst = *pucSrc;
                pucDst++;
                pucSrc++;
            }
        }
    }
}

// Fills a rectangle of a pixel buffer with a single pixel value.
// @0x14184d520
void FillPixelRect(const unsigned char* pucPixel, NiPixelData* pkDest, const NiRect<unsigned int>& kRect)
{
    if (pucPixel == NULL || pkDest == NULL)
    {
        return;
    }

    unsigned int uiStride = pkDest->GetPixelStride();
    int iWidth = pkDest->GetWidth(0, 0);
    unsigned char* pucBase = pkDest->GetPixels(0, 0);
    for (unsigned int uiRow = kRect.m_top; uiRow < kRect.m_bottom; uiRow++)
    {
        for (unsigned int uiCol = kRect.m_left; uiCol < kRect.m_right; uiCol++)
        {
            FUN_140a34190(pucBase + (uiCol + uiRow * iWidth) * uiStride, pucPixel, uiStride);
        }
    }
}

// Returns a new pixel buffer holding every uiStep-th pixel of the source (a point-sampled downscale).
// @0x14184d610
// MS2-FUNCTIONAL: local slot order / hoisted divisions differ from the exe
NiPixelData* DownsamplePixels(NiPixelData* pkSource, unsigned int uiStep)
{
    if (pkSource == NULL)
    {
        return NiNew NiPixelData(1, 1, DAT_1439fb040, 1, 1);
    }

    unsigned int uiStride = pkSource->GetPixelStride();
    unsigned int uiWidth = pkSource->GetWidth(0, 0);
    unsigned int uiHeight = pkSource->GetHeight(0, 0);
    unsigned int uiDestWidth = uiWidth / uiStep;
    unsigned int uiDestHeight = uiHeight / uiStep;
    NiPixelData* pkResult = NiNew NiPixelData(uiDestWidth, uiDestHeight, DAT_1439fb040, 1, 1);

    unsigned char* pucSrc = pkSource->GetPixels(0, 0);
    unsigned char* pucDst = pkResult->GetPixels(0, 0);
    for (unsigned int uiRow = 0; uiRow < uiHeight / uiStep; uiRow++)
    {
        for (unsigned int uiCol = 0; uiCol < uiWidth / uiStep; uiCol++)
        {
            FUN_140a34190(pucDst, pucSrc, uiStride);
            pucDst += uiStride;
            pucSrc += uiStride * uiStep;
        }
        pucSrc += uiStride * uiWidth * (uiStep - 1);
    }
    return pkResult;
}

// Converts pixel data to the exe's RGBA32 layout unless it is already in that format.
// @0x14184d8c0
NiPixelData* ConvertToRGBA32(NiPixelData* pkPixels, unsigned int /*uiUnused1*/, unsigned int /*uiUnused2*/)
{
    if (pkPixels == NULL)
    {
        return NULL;
    }

    if (pkPixels->GetPixelFormat() != DAT_1439fb040)
    {
        NiImageConverter* pkConverter = NiDynamicCast(NiImageConverter, FUN_141851720());
        pkPixels = pkConverter->ConvertPixelData(*pkPixels, DAT_1439fb040, NULL, false);
    }
    return pkPixels;
}

// Copies a rectangle from one pixel buffer to the same-format destination at another rectangle origin.
// @0x14184d950
void CopyPixelRect(NiPixelData* pkSource, const NiRect<unsigned int>& kSrcRect, NiPixelData* pkDest,
    const NiRect<unsigned int>& kDestRect)
{
    unsigned char* pucSrc = pkSource->GetPixels(0, 0);
    int iSrcWidth = pkSource->GetWidth(0, 0);
    unsigned int uiStride = pkSource->GetPixelStride();
    unsigned char* pucDst = pkDest->GetPixels(0, 0);
    int iDstWidth = pkDest->GetWidth(0, 0);
    for (unsigned int uiRow = 0; uiRow < kSrcRect.GetHeight(); uiRow++)
    {
        for (unsigned int uiCol = 0; uiCol < kSrcRect.GetWidth(); uiCol++)
        {
            FUN_140a34190(pucDst + (uiCol + kDestRect.m_left + (uiRow + kDestRect.m_top) * iDstWidth) * uiStride,
                pucSrc + (uiCol + kSrcRect.m_left + (uiRow + kSrcRect.m_top) * iSrcWidth) * uiStride, uiStride);
        }
    }
}

// Samples an RGBA32 pixel buffer at a normalised UV coordinate (wrapped into [0,1]), either nearest or bilinear filtered.
// Returns false when the buffer is missing or not RGBA32.
// @0x14184dad0
// MS2-FUNCTIONAL: local slot layout / statement order of the bilinear block differs from the exe
int SamplePixelData(NiPixelData* pkPixels, NiPoint2 kUV, Unk_TexColor* pkOut, bool bBilinear)
{
    if (pkPixels == NULL)
    {
        return 0;
    }
    if (pkPixels->GetPixelFormat() != DAT_1439fb040)
    {
        return 0;
    }
    {
        if (kUV.x > 1.0f || kUV.x < 0.0f)
        {
            kUV.x = kUV.x - (float)(int)kUV.x;
        }
        if (kUV.y > 1.0f || kUV.y < 0.0f)
        {
            kUV.y = kUV.y - (float)(int)kUV.y;
        }

        unsigned char* pucPixels = pkPixels->GetPixels(0, 0);
        int iStride = pkPixels->GetPixelStride();
        int iWidth = pkPixels->GetWidth(0, 0);
        int iHeight = pkPixels->GetHeight(0, 0);
        NiPoint2 kPos(kUV.x * (float)iWidth - 0.5f, kUV.y * (float)iHeight - 0.5f);

        if (bBilinear)
        {
            int iX = (kPos.x >= 0.0f) ? (int)kPos.x : -1;
            int iY = (kPos.y >= 0.0f) ? (int)kPos.y : -1;
            kPos.x = kPos.x - (float)iX;
            kPos.y = kPos.y - (float)iY;

            int iX0 = (iX < 0) ? 0 : iX;
            int iX1 = (iX + 1 == iWidth) ? iX : iX + 1;
            int iY0 = (iY < 0) ? 0 : iY;
            int iY1 = (iY + 1 == iHeight) ? iY : iY + 1;

            unsigned char* pucP00 = pucPixels + (iX0 + iY0 * iWidth) * iStride;
            unsigned char* pucP10 = pucPixels + (iX1 + iY0 * iWidth) * iStride;
            unsigned char* pucP01 = pucPixels + (iX0 + iY1 * iWidth) * iStride;
            unsigned char* pucP11 = pucPixels + (iX1 + iY1 * iWidth) * iStride;

            float fR = pucP00[0] * kPos.x * kPos.y + pucP10[0] * kPos.x * (1.0f - kPos.y)
                + pucP01[0] * (1.0f - kPos.x) * kPos.y + pucP11[0] * (1.0f - kPos.x) * (1.0f - kPos.y);
            float fG = pucP00[1] * kPos.x * kPos.y + pucP10[1] * kPos.x * (1.0f - kPos.y)
                + pucP01[1] * (1.0f - kPos.x) * kPos.y + pucP11[1] * (1.0f - kPos.x) * (1.0f - kPos.y);
            float fB = pucP00[2] * kPos.x * kPos.y + pucP10[2] * kPos.x * (1.0f - kPos.y)
                + pucP01[2] * (1.0f - kPos.x) * kPos.y + pucP11[2] * (1.0f - kPos.x) * (1.0f - kPos.y);
            float fA = pucP00[3] * kPos.x * kPos.y + pucP10[3] * kPos.x * (1.0f - kPos.y)
                + pucP01[3] * (1.0f - kPos.x) * kPos.y + pucP11[3] * (1.0f - kPos.x) * (1.0f - kPos.y);
            *pkOut = Unk_TexColor((int)fR, (int)fG, (int)fB, (int)fA);
        }
        else
        {
            int iX = (int)kPos.x;
            int iY = (int)kPos.y;
            unsigned char* pucPixel = pucPixels + (iX + iY * iWidth) * iStride;
            *pkOut = Unk_TexColor(pucPixel[0], pucPixel[1], pucPixel[2], pucPixel[3]);
        }
    }
    return 1;
}

// Snapshots the current device state into a new state block.
// @0x14184e230
void CaptureDeviceState(IDirect3DStateBlock9** ppkBlock)
{
    NiDX9Renderer* pkRenderer = (NiDX9Renderer*)NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
    pkDevice->CreateStateBlock(D3DSBT_ALL, ppkBlock);
    (*ppkBlock)->Capture();
}

// Re-applies a captured state block and releases it.
// @0x14184e2a0
void RestoreDeviceState(IDirect3DStateBlock9* pkBlock)
{
    if (pkBlock != NULL)
    {
        pkBlock->Apply();
        pkBlock->Release();
    }
}

// Makes every pixel of the surface that matches the colour key fully transparent (copying through a system-memory texture).
// @0x14184e2e0
int ApplyColorKeyToSurface(IDirect3DSurface9* pkSurface, const NiColorA* pkKey)
{
    NiDX9Renderer* pkRenderer = (NiDX9Renderer*)NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    D3DSURFACE_DESC kDesc;
    pkSurface->GetDesc(&kDesc);

    LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
    IDirect3DTexture9* pkTexture;
    HRESULT hr = pkDevice->CreateTexture(kDesc.Width, kDesc.Height, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_SYSTEMMEM, &pkTexture,
        NULL);
    if (hr >= 0)
    {
        IDirect3DSurface9* pkCopy;
        pkTexture->GetSurfaceLevel(0, &pkCopy);
        pkTexture->Release();
        hr = D3DXLoadSurfaceFromSurface(pkCopy, NULL, NULL, pkSurface, NULL, NULL, D3DX_FILTER_NONE, 0);
        if (hr >= 0)
        {
            D3DLOCKED_RECT kLocked;
            if (pkCopy->LockRect(&kLocked, NULL, 0) >= 0)
            {
                unsigned char* pucRow = (unsigned char*)kLocked.pBits;
                for (unsigned int uiRow = 0; uiRow < kDesc.Height; uiRow++)
                {
                    for (unsigned int uiCol = 0; uiCol < kDesc.Width; uiCol += 4)
                    {
                        unsigned int* puiPixel = (unsigned int*)(pucRow + uiCol);
                        if (*puiPixel == ((((unsigned int)(long long)(pkKey->a * 255.0f) & 0xff) << 24) | (((unsigned int)(long long)(pkKey->r * 255.0f) & 0xff) << 16)
                            | (((unsigned int)(long long)(pkKey->g * 255.0f) & 0xff) << 8) | ((unsigned int)(long long)(pkKey->b * 255.0f) & 0xff)))
                        {
                            *puiPixel = *puiPixel & 0xffffff;
                        }
                    }
                    pucRow += kLocked.Pitch;
                }
                pkCopy->UnlockRect();
            }
            pkCopy->Release();
        }
    }
    return 1;
}

// Returns the buffer a screenshot is taken from: the default back buffer when nTarget is 0, otherwise the UI service's
// capture buffer.
// @0x14184e5d0
Ni2DBuffer* GetScreenshotBuffer(int nTarget)
{
    if (nTarget != 0)
    {
        return FUN_1422afcf0(FUN_14025e7a0());
    }
    else
    {
        NiRenderer* pkRenderer = NiRenderer::GetRenderer();
        NiRenderTargetGroup* pkGroup = pkRenderer->GetDefaultRenderTargetGroup();
        if (pkGroup == NULL)
        {
            return NULL;
        }
        return pkGroup->GetBuffer(0);
    }
}

// Saves the whole client area of the selected buffer to an image file.
// @0x14184e640
void SaveClientAreaToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nTarget)
{
    RECT kClient = { 0, 0, 0, 0 };
    GetClientRect(FUN_14209c720(FUN_140aadf80()), &kClient);
    SaveBufferToFileW(pkPath, eFormat, nTarget, NiRect<unsigned int>(0, kClient.right, kClient.top, kClient.bottom), 0);
}

// Saves a rectangle of the selected buffer to an image file.
// @0x14184e720
int SaveBufferToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nTarget,
    NiRect<unsigned int> kRect, int bLogErrors)
{
    Ni2DBuffer* pkBuffer = GetScreenshotBuffer(nTarget);
    if (pkBuffer == NULL)
    {
        return 0;
    }
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return 0;
    }
    if (SaveSurfaceToFileW(pkPath, eFormat, pkData->GetSurface(), kRect, bLogErrors, 1.0f) != 0)
    {
        return 1;
    }
    return 0;
}

// Saves an NiTexture's D3D texture to an image file.
// @0x14184e7f0
int SaveTextureToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiTexture* pkTexture)
{
    NiTexture::RendererData* pkRendererData = pkTexture->GetRendererData();
    if (pkRendererData == NULL)
    {
        return 0;
    }
    IDirect3DBaseTexture9* pkD3DTexture = ((NiDX9TextureData*)pkRendererData)->GetD3DTexture();
    HRESULT hr = D3DXSaveTextureToFileW((const wchar_t*)(*pkPath), eFormat, pkD3DTexture, NULL);
    if (hr < 0)
    {
        EE_LOG_AT(1, 1, ("Error 0x%08x: %s", hr, _com_error(hr).ErrorMessage()), MS2_THIS_FILE, 0x223);
        return 0;
    }
    return 1;
}

// Saves pixel data to an image file by wrapping it in a temporary 32-bit source texture.
// @0x14184e9a0
void SavePixelDataToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiPixelData* pkPixels)
{
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = NiTexture::FormatPrefs::TRUE_COLOR_32;
    kPrefs.m_eMipMapped = NiTexture::FormatPrefs::NO;
    SaveTextureToFileW(pkPath, eFormat, NiSourceTexture::Create(pkPixels, kPrefs, true));
}

// Saves a rectangle of a D3D surface to an image file, optionally scaled (through a system-memory DXT5 texture, with
// mipmaps for DDS output).
// @0x14184ea00
// MS2-FUNCTIONAL: stack slot order of the texture/level pointers (and a mov edx/r8d hop) differs from the exe
int SaveSurfaceToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, IDirect3DSurface9* pkSurface,
    NiRect<unsigned int> kRect, int bLogErrors, float fScale)
{
    RECT kSrcRect;
    kSrcRect.left = kRect.m_left;
    kSrcRect.top = kRect.m_top;
    kSrcRect.right = kRect.m_right;
    kSrcRect.bottom = kRect.m_bottom;
    unsigned int uiError = E_FAIL;

    if (fScale == 1.0f)
    {
        uiError = D3DXSaveSurfaceToFileW((const wchar_t*)(*pkPath), eFormat, pkSurface, NULL, &kSrcRect);
        if ((int)uiError >= 0)
        {
            return 1;
        }
    }
    else
    {
        NiDX9Renderer* pkRenderer = (NiDX9Renderer*)NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
        int iWidth = (int)(kRect.GetWidth() * fScale);
        int iHeight = (int)(kRect.GetHeight() * fScale);
        int iLevels = 1;
        if (eFormat == D3DXIFF_DDS)
        {
            iLevels = CountMipLevels(iWidth, iHeight);
        }
        LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
        int iCreateHeight = (int)(long long)(kRect.GetHeight() * fScale);
        IDirect3DTexture9* pkTexture;
        IDirect3DSurface9* pkLevel;
        int hr = pkDevice->CreateTexture((int)(long long)(kRect.GetWidth() * fScale), iCreateHeight, iLevels, 0, D3DFMT_DXT5,
            D3DPOOL_SYSTEMMEM, &pkTexture, NULL);
        if (hr >= 0)
        {
            pkLevel = NULL;
            for (int iLevel = 0; iLevel < iLevels; iLevel++)
            {
                pkTexture->GetSurfaceLevel(iLevel, &pkLevel);
                hr = D3DXLoadSurfaceFromSurface(pkLevel, NULL, NULL, pkSurface, NULL, &kSrcRect, D3DX_FILTER_BOX, 0);
                if (hr < 0)
                {
                    return 0;
                }
            }
            if (iLevels == 1)
            {
                hr = D3DXSaveSurfaceToFileW((const wchar_t*)(*pkPath), eFormat, pkLevel, NULL, &kSrcRect);
                if (hr >= 0)
                {
                    pkLevel->Release();
                    return 1;
                }
            }
            else
            {
                hr = D3DXSaveTextureToFileW((const wchar_t*)(*pkPath), eFormat, pkTexture, NULL);
                if (hr >= 0)
                {
                    pkTexture->Release();
                    return 1;
                }
            }
        }
    }

    if (bLogErrors != 0)
    {
        EE_LOG_AT(1, 1, ("Error 0x%08x: %s", uiError, _com_error(uiError).ErrorMessage()), MS2_THIS_FILE, 0x279);
    }
    return 0;
}

// Saves the first buffer of a render target group (a rectangle of it) to an image file.
// @0x14184eed0
int SaveRenderTargetToFileW(ATL::CSimpleStringT<wchar_t, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiRenderTargetGroup* pkGroup,
    NiRect<unsigned int> kRect)
{
    if (pkGroup == NULL)
    {
        return 0;
    }
    Ni2DBuffer* pkBuffer = pkGroup->GetBuffer(0);
    if (pkBuffer == NULL)
    {
        return 0;
    }
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return 0;
    }
    if (SaveSurfaceToFileW(pkPath, eFormat, pkData->GetSurface(), kRect, 0, 1.0f) != 0)
    {
        return 1;
    }
    return 0;
}

// Saves the whole client area of the selected buffer to an image file (narrow-string twin).
// @0x14184efc0
void SaveClientAreaToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nTarget)
{
    RECT kClient = { 0, 0, 0, 0 };
    GetClientRect(FUN_14209c720(FUN_140aadf80()), &kClient);
    SaveBufferToFileA(pkPath, eFormat, nTarget, NiRect<unsigned int>(0, kClient.right, kClient.top, kClient.bottom), 0);
}

// Saves a rectangle of the selected buffer to an image file.
// @0x14184f0a0
int SaveBufferToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int nTarget,
    NiRect<unsigned int> kRect, int bLogErrors)
{
    Ni2DBuffer* pkBuffer = GetScreenshotBuffer(nTarget);
    if (pkBuffer == NULL)
    {
        return 0;
    }
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return 0;
    }
    if (SaveSurfaceToFileA(pkPath, eFormat, pkData->GetSurface(), kRect, bLogErrors, 1.0f) != 0)
    {
        return 1;
    }
    return 0;
}

// Saves an NiTexture's D3D texture to an image file.
// @0x14184f170
int SaveTextureToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiTexture* pkTexture)
{
    NiTexture::RendererData* pkRendererData = pkTexture->GetRendererData();
    if (pkRendererData == NULL)
    {
        return 0;
    }
    IDirect3DBaseTexture9* pkD3DTexture = ((NiDX9TextureData*)pkRendererData)->GetD3DTexture();
    HRESULT hr = D3DXSaveTextureToFileA((const char*)(*pkPath), eFormat, pkD3DTexture, NULL);
    if (hr < 0)
    {
        EE_LOG_AT(1, 1, ("Error 0x%08x: %s", hr, _com_error(hr).ErrorMessage()), MS2_THIS_FILE, 0x2c4);
        return 0;
    }
    return 1;
}

// Saves pixel data to an image file by wrapping it in a temporary 32-bit source texture.
// @0x14184f320
void SavePixelDataToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiPixelData* pkPixels)
{
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = NiTexture::FormatPrefs::TRUE_COLOR_32;
    kPrefs.m_eMipMapped = NiTexture::FormatPrefs::NO;
    SaveTextureToFileA(pkPath, eFormat, NiSourceTexture::Create(pkPixels, kPrefs, true));
}

// Saves a rectangle of a D3D surface to an image file, optionally scaled (through a system-memory DXT5 texture, with
// mipmaps for DDS output).
// @0x14184f380
// MS2-FUNCTIONAL: stack slot order of the texture/level pointers (and a mov edx/r8d hop) differs from the exe
int SaveSurfaceToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, IDirect3DSurface9* pkSurface,
    NiRect<unsigned int> kRect, int bLogErrors, float fScale)
{
    RECT kSrcRect;
    kSrcRect.left = kRect.m_left;
    kSrcRect.top = kRect.m_top;
    kSrcRect.right = kRect.m_right;
    kSrcRect.bottom = kRect.m_bottom;
    unsigned int uiError = E_FAIL;

    if (fScale == 1.0f)
    {
        uiError = D3DXSaveSurfaceToFileA((const char*)(*pkPath), eFormat, pkSurface, NULL, &kSrcRect);
        if ((int)uiError >= 0)
        {
            return 1;
        }
    }
    else
    {
        NiDX9Renderer* pkRenderer = (NiDX9Renderer*)NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
        int iWidth = (int)(kRect.GetWidth() * fScale);
        int iHeight = (int)(kRect.GetHeight() * fScale);
        int iLevels = 1;
        if (eFormat == D3DXIFF_DDS)
        {
            iLevels = CountMipLevels(iWidth, iHeight);
        }
        LPDIRECT3DDEVICE9 pkDevice = pkRenderer->GetD3DDevice();
        int iCreateHeight = (int)(long long)(kRect.GetHeight() * fScale);
        IDirect3DTexture9* pkTexture;
        IDirect3DSurface9* pkLevel;
        int hr = pkDevice->CreateTexture((int)(long long)(kRect.GetWidth() * fScale), iCreateHeight, iLevels, 0, D3DFMT_DXT5,
            D3DPOOL_SYSTEMMEM, &pkTexture, NULL);
        if (hr >= 0)
        {
            pkLevel = NULL;
            for (int iLevel = 0; iLevel < iLevels; iLevel++)
            {
                pkTexture->GetSurfaceLevel(iLevel, &pkLevel);
                hr = D3DXLoadSurfaceFromSurface(pkLevel, NULL, NULL, pkSurface, NULL, &kSrcRect, D3DX_FILTER_BOX, 0);
                if (hr < 0)
                {
                    return 0;
                }
            }
            if (iLevels == 1)
            {
                hr = D3DXSaveSurfaceToFileA((const char*)(*pkPath), eFormat, pkLevel, NULL, &kSrcRect);
                if (hr >= 0)
                {
                    pkLevel->Release();
                    return 1;
                }
            }
            else
            {
                hr = D3DXSaveTextureToFileA((const char*)(*pkPath), eFormat, pkTexture, NULL);
                if (hr >= 0)
                {
                    pkTexture->Release();
                    return 1;
                }
            }
        }
    }

    if (bLogErrors != 0)
    {
        EE_LOG_AT(1, 1, ("Error 0x%08x: %s", uiError, _com_error(uiError).ErrorMessage()), MS2_THIS_FILE, 0x31a);
    }
    return 0;
}

// Saves the first buffer of a render target group (a rectangle of it) to an image file.
// @0x14184f850
int SaveRenderTargetToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, NiRenderTargetGroup* pkGroup,
    NiRect<unsigned int> kRect)
{
    if (pkGroup == NULL)
    {
        return 0;
    }
    Ni2DBuffer* pkBuffer = pkGroup->GetBuffer(0);
    if (pkBuffer == NULL)
    {
        return 0;
    }
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return 0;
    }
    if (SaveSurfaceToFileA(pkPath, eFormat, pkData->GetSurface(), kRect, 0, 1.0f) != 0)
    {
        return 1;
    }
    return 0;
}

// Saves the default render target's first buffer (a rectangle of it) to an image file (narrow-string).
// @0x14184f940
int SaveDefaultTargetToFileA(ATL::CSimpleStringT<char, 1>* pkPath, D3DXIMAGE_FILEFORMAT eFormat, int /*nUnused*/,
    NiRect<unsigned int> kRect, float fScale)
{
    Ni2DBuffer* pkBuffer = FUN_1409a8b20()->FUN_1416a3fb0()->GetBuffer(0);
    if (pkBuffer == NULL)
    {
        return 0;
    }
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return 0;
    }
    if (SaveSurfaceToFileA(pkPath, eFormat, pkData->GetSurface(), kRect, 0, fScale) != 0)
    {
        return 1;
    }
    return 0;
}

// The file extension of an image format.
// @0x14184fa70
CStringW GetImageExtension(int eFormat)
{
    switch (eFormat)
    {
    case D3DXIFF_JPG:
        return CStringW(L".jpg");
    case D3DXIFF_PNG:
        return CStringW(L".png");
    default:
        return CStringW(L"");
    }
}

// Builds "\YYYYMMDD_HHMMSS_<counter><ext>" for a screenshot taken now.
// @0x14184fb20
CStringW GetTimestampFileName(int eFormat)
{
    time_t tNow = time(NULL);
    tm* pkLocal = localtime(&tNow);
    tm kTime;
    memset(&kTime, 0, sizeof(kTime));
    if (pkLocal != NULL)
    {
        kTime = *pkLocal;
    }
    CStringW kName;
    kName.Format(L"\\%d%02d%02d_%02d%02d%02d_%02d%s", kTime.tm_year + 1900, kTime.tm_mon + 1, kTime.tm_mday, kTime.tm_hour,
        kTime.tm_min, kTime.tm_sec, s_iScreenshotCounter, (LPCWSTR)GetImageExtension(eFormat));
    return kName;
}

// Shows a screenshot status text: on screen, or as a message box unless one named "notifyScreenShot" is already up.
#define MS2_SCREENSHOT_NOTIFY(bNotify, kText)                                                                           \
    if ((bNotify) != 0)                                                                                                 \
    {                                                                                                                   \
        CStringW kTag(L"notifyScreenShot");                                                                             \
        {                                                                                                               \
            Unk_MessageBoxPtr kCurrent = FUN_14151f820();                                                               \
            if (FUN_140534fc0(kCurrent) != 0)                                                                           \
            {                                                                                                           \
                if (kTag.CompareNoCase(FUN_141a02ce0(FUN_140534fe0(kCurrent))) == 0)                                    \
                {                                                                                                       \
                    FUN_14151f200();                                                                                    \
                }                                                                                                       \
            }                                                                                                           \
        }                                                                                                               \
        FUN_140d73aa0(CStringW(kText), 0, 0, CStringW(kTag));                                                           \
    }                                                                                                                   \
    else                                                                                                                \
    {                                                                                                                   \
        FUN_1412751b0(kText, 0x14);                                                                                     \
    }

// Makes sure <My Documents>\maplestory2\screenshot exists and returns its path.
// @0x14184fcb0
CStringW GetScreenshotDirectory(int bNotify, unsigned int* /*puiUnused*/);

// @0x14184fe60
int EnsureScreenshotDirectory(CStringW* pkDirectory);

// Reports whether a path names an existing directory.
// @0x141851630
int IsDirectory(CStringW kPath);

// @0x14184fcb0
CStringW GetScreenshotDirectory(int bNotify, unsigned int* /*puiUnused*/)
{
    CStringW kDirectory;
    int iResult = EnsureScreenshotDirectory(&kDirectory);
    if (iResult < 0)
    {
        CStringW kMessage;
        kMessage.Format(L"Error code [%d] - make directory", iResult);
        MS2_SCREENSHOT_NOTIFY(bNotify, kMessage)
    }
    return kDirectory;
}

// @0x14184fe60
int EnsureScreenshotDirectory(CStringW* pkDirectory)
{
    wchar_t awcBuffer[0x800];
    memset(awcBuffer, 0, sizeof(awcBuffer));
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, awcBuffer) == 0)
    {
        if (!IsDirectory(CStringW(awcBuffer)) && GetCurrentDirectoryW(0x800, awcBuffer) == 0)
        {
            return -1;
        }
    }
    else if (GetCurrentDirectoryW(0x800, awcBuffer) == 0)
    {
        return -2;
    }

    CStringW kBase = StringFormat(L"{0}\\maplestory2", awcBuffer);
    if (!IsDirectory(CStringW(kBase)) && FUN_1414a5a40(CStringW(kBase)) == -1)
    {
        return -5;
    }
    *pkDirectory = FUN_1401e8510(L"{0}\\screenshot", kBase);
    if (!IsDirectory(CStringW(*pkDirectory)) && FUN_1414a5a40(CStringW(*pkDirectory)) == -1)
    {
        return -6;
    }
    return 0;
}

// Takes a JPEG screenshot of the selected buffer's client area into the screenshot directory; returns the file path
// (empty on failure).
// @0x141850100
// MS2-FUNCTIONAL: stack slot order of the locals (0x10 smaller frame in the exe) differs; no source form found
CStringW TakeScreenshotJpg(int bNotify, int nTarget)
{
    unsigned int uiDirError = 0;
    CStringW kDirectory = GetScreenshotDirectory(bNotify, &uiDirError);
    if ((int)uiDirError < 0)
    {
        return CStringW(L"");
    }
    CStringW kPath = FUN_1401d0080(kDirectory, GetTimestampFileName(D3DXIFF_JPG));
    RECT kClient = { 0, 0, 0, 0 };
    GetClientRect(FUN_14209c720(FUN_140aadf80()), &kClient);
    Ni2DBuffer* pkBuffer = GetScreenshotBuffer(nTarget);
    if (pkBuffer == NULL)
    {
        return CStringW(L"");
    }
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return CStringW(L"");
    }
    HRESULT hr = E_FAIL;
    hr = D3DXSaveSurfaceToFileW((LPCWSTR)kPath, D3DXIFF_JPG, pkData->GetSurface(), NULL, &kClient);
    if (hr >= 0)
    {
        s_iScreenshotCounter = s_iScreenshotCounter + 1;
        CStringW kDone = FUN_14052bd00(0x577, kPath);
        MS2_SCREENSHOT_NOTIFY(bNotify, kDone)
        if (FUN_140d8ee90() != 0)
        {
            CStringA kArg("");
            CStringA kName("screenshot");
            FUN_140a1f970(FUN_140d8ee90(), kName, kArg);
        }
        return kPath;
    }
    else
    {
        CStringW kMessage;
        kMessage.Format(L"Error D3DERR_INVALIDCALL", uiDirError);
        MS2_SCREENSHOT_NOTIFY(bNotify, kMessage)
        return CStringW(L"");
    }
}

// Takes a PNG screenshot of the scene's render-target group into the screenshot directory.
// @0x141850710
void TakeSceneScreenshotPng(int bNotify)
{
    unsigned int uiDirError = 0;
    CStringW kDirectory = GetScreenshotDirectory(bNotify, &uiDirError);
    if ((int)uiDirError < 0)
    {
        return;
    }
    CStringW kPath = FUN_1401d0080(kDirectory, GetTimestampFileName(D3DXIFF_PNG));
    void* pkRegistry = FUN_14127bf80(&DAT_143b059e8);
    if (pkRegistry != NULL)
    {
        NiRenderTargetGroup* pkGroup = FUN_14127cca0(FUN_140af7da0(pkRegistry));
        if (pkGroup != NULL)
        {
            RECT kClient = { 0, 0, 0, 0 };
            GetClientRect(FUN_14209c720(FUN_140aadf80()), &kClient);
            NiRect<unsigned int> kRect(kClient.left, kClient.right, kClient.top, kClient.bottom);
            SaveRenderTargetToFileW((ATL::CSimpleStringT<wchar_t, 1>*)&kPath, D3DXIFF_PNG, pkGroup, kRect);
            s_iScreenshotCounter = s_iScreenshotCounter + 1;
        }
    }
}

// Takes a PNG screenshot of the back buffer's client area into the screenshot directory.
// @0x1418508e0
void TakeScreenshotPng(int bNotify)
{
    unsigned int uiDirError = 0;
    CStringW kDirectory = GetScreenshotDirectory(bNotify, &uiDirError);
    if ((int)uiDirError < 0)
    {
        return;
    }
    CStringW kPath = FUN_1401d0080(kDirectory, GetTimestampFileName(D3DXIFF_PNG));
    RECT kClient = { 0, 0, 0, 0 };
    GetClientRect(FUN_14209c720(FUN_140aadf80()), &kClient);
    Ni2DBuffer* pkBuffer = GetScreenshotBuffer(0);
    if (pkBuffer == NULL)
    {
        return;
    }
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return;
    }
    HRESULT hr = E_FAIL;
    hr = D3DXSaveSurfaceToFileW((LPCWSTR)kPath, D3DXIFF_PNG, pkData->GetSurface(), NULL, &kClient);
    if (hr >= 0)
    {
        s_iScreenshotCounter = s_iScreenshotCounter + 1;
        CStringW kDone = FUN_14052bd00(0x577, kPath);
        MS2_SCREENSHOT_NOTIFY(bNotify, kDone)
        if (FUN_140d8ee90() != 0)
        {
            CStringA kArg("");
            CStringA kName("screenshot");
            FUN_140a1f970(FUN_140d8ee90(), kName, kArg);
        }
    }
    else
    {
        CStringW kMessage;
        kMessage.Format(L"Error D3DERR_INVALIDCALL", uiDirError);
        MS2_SCREENSHOT_NOTIFY(bNotify, kMessage)
    }
}

// Captures the UI buffer's client area as an in-memory JPEG and returns it encoded.
// @0x141850df0
std::string CaptureClientAreaJpg()
{
    Ni2DBuffer* pkBuffer = GetScreenshotBuffer(1);
    if (pkBuffer == NULL)
    {
        return std::string("");
    }
    RECT kClient = { 0, 0, 0, 0 };
    GetClientRect(FUN_14209c720(FUN_140aadf80()), &kClient);
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return std::string("");
    }
    LPD3DXBUFFER pkMemory;
    HRESULT hr = D3DXSaveSurfaceToFileInMemory(&pkMemory, D3DXIFF_JPG, pkData->GetSurface(), NULL, &kClient);
    if (hr >= 0)
    {
        std::string kRaw((const char*)pkMemory->GetBufferPointer(), pkMemory->GetBufferSize());
        std::string kEncoded = FUN_14083fa60(kRaw.c_str(), (unsigned int)kRaw.size());
        return kEncoded;
    }
    return std::string("");
}

// Captures a rectangle (given in UI units) of the back buffer as an in-memory JPEG and returns it encoded.
// @0x141851040
std::string CaptureRegionJpg(int iX, int iY, int iWidth, int iHeight)
{
    Ni2DBuffer* pkBuffer = GetScreenshotBuffer(0);
    if (pkBuffer == NULL)
    {
        return std::string("");
    }
    RECT kRegion;
    kRegion.left = iX;
    kRegion.top = iY;
    kRegion.right = iX + iWidth;
    kRegion.bottom = iY + iHeight;
    float fScale = 1.0f / FUN_141adbe70(FUN_1403ed2b0());
    kRegion.left = (int)((float)kRegion.left * fScale);
    kRegion.top = (int)((float)kRegion.top * fScale);
    kRegion.right = (int)((float)kRegion.right * fScale);
    kRegion.bottom = (int)((float)kRegion.bottom * fScale);
    NiDX92DBufferData* pkData = NiDynamicCast(NiDX92DBufferData, (NiDX92DBufferData*)pkBuffer->GetRendererData());
    if (pkData == NULL)
    {
        return std::string("");
    }
    LPD3DXBUFFER pkMemory;
    HRESULT hr = D3DXSaveSurfaceToFileInMemory(&pkMemory, D3DXIFF_JPG, pkData->GetSurface(), NULL, &kRegion);
    if (hr >= 0)
    {
        std::string kRaw((const char*)pkMemory->GetBufferPointer(), pkMemory->GetBufferSize());
        std::string kEncoded = FUN_14083fa60(kRaw.c_str(), (unsigned int)kRaw.size());
        return kEncoded;
    }
    return std::string("");
}

// The number of mip levels of a texture of the given size (the bit length of the larger dimension).
// @0x141851320
int CountMipLevels(int iWidth, int iHeight)
{
    int iW = iWidth;
    int iH = iHeight;
    int iWidthLevels = 0;
    int iHeightLevels = 0;
    while (iW > 0)
    {
        iWidthLevels = iWidthLevels + 1;
        iW = iW / 2;
    }
    while (iH > 0)
    {
        iHeightLevels = iHeightLevels + 1;
        iH = iH / 2;
    }
    int iLevels;
    if (iWidthLevels > iHeightLevels)
    {
        iLevels = iWidthLevels;
    }
    else
    {
        iLevels = iHeightLevels;
    }
    int iResult = iLevels;
    return iResult;
}

// @0x141851630
int IsDirectory(CStringW kPath)
{
    if (!kPath.IsEmpty())
    {
        DWORD dwAttributes = GetFileAttributesW((LPCWSTR)kPath);
        if (dwAttributes == INVALID_FILE_ATTRIBUTES)
        {
            return 0;
        }
        return (dwAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
    }
    return 0;
}

// Returns the calling thread's image converter, creating it (with the MS2 PNG reader added) on first use.
#ifndef MS2_HOOK_DLL
// @0x141851720
// MS2-FUNCTIONAL: the exe has an EH frame (state -2, 0x88 frame) from an unrecovered temporary of the allocation expression
NiImageConverter* FUN_141851720()
{
    if (s_kConverterSlot.Get() == NULL)
    {
        FUN_141d38fa0();
        int iCategoryTemp;
        unsigned int* puiCategory = (unsigned int*)FUN_140876480(&iCategoryTemp, 0);
        void* pkMemory = FUN_14208a860(0x858, *puiCategory);
        NiDevImageConverter* pkConverter;
        if (pkMemory == NULL)
        {
            pkConverter = NULL;
        }
        else
        {
            pkConverter = FUN_141d34210(pkMemory);
        }
        NiDevImageConverter* pkTarget = pkConverter;
        unsigned int* puiCategory2 = (unsigned int*)FUN_140876480(&iCategoryTemp, 0);
        void* pkReaderMemory = FUN_14208a860(0xe0, *puiCategory2);
        NiImageReader* pkReader;
        if (pkReaderMemory == NULL)
        {
            pkReader = NULL;
        }
        else
        {
            pkReader = FUN_140d9aba0(pkReaderMemory);
        }
        pkTarget->AddReader(pkReader);
        FUN_141851840(pkConverter);
    }
    return (NiImageConverter*)s_kConverterSlot.Get();
}
#endif

// Stores the converter in the thread's slot, destroying the one that was there.
#ifndef MS2_HOOK_DLL
// @0x141851840
void FUN_141851840(NiDevImageConverter* pkConverter)
{
    if (s_kConverterSlot.Get() != NULL)
    {
        delete (NiDevImageConverter*)s_kConverterSlot.Get();
    }
    s_kConverterSlot.Set(pkConverter);
}
#endif
