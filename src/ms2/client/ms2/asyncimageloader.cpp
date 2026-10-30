// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CAsyncImageLoader: the worker thread that reads the image files of
// the UI (Scaleform images backed by Gamebryo textures), with the request classes ImageLoaderParam / GfxImageLoaderParam.
// MS2-UNIT: client\ms2\asyncimageloader.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x140a58820-0x140a5bb10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$SmartPointer@VNiPixelData@@@efd@@QEAA@AEBV01@@Z 0x140a5a4c0 ; unique
// MS2-PIN: ??0?$TSingleton@VCAsyncImageLoader@@@@QEAA@XZ 0x140a5a5e0 ; unique
// MS2-PIN: ??1?$SmartPointer@VNiPixelData@@@efd@@QEAA@XZ 0x140a5a900 ; prop
// MS2-PIN: ??4?$SmartPointer@VNiTexture@@@efd@@QEAAAEAV01@AEBV01@@Z 0x140a5ab40 ; unique
// MS2-PIN: ??B?$SmartPointer@VNiPixelData@@@efd@@QEBAPEAVNiPixelData@@XZ 0x140a5ac70 ; prop
// MS2-PIN: ??B?$SmartPointer@VNiTexture@@@efd@@QEBAPEAVNiTexture@@XZ 0x140a5ac80 ; order
// MS2-PIN: ??C?$SmartPointer@VNiSourceTexture@@@efd@@QEBAPEAVNiSourceTexture@@XZ 0x140a5aca0 ; prop
// MS2-PIN: ??C?$SmartPointer@VNiTexture@@@efd@@QEBAPEAVNiTexture@@XZ 0x140a5acb0 ; order
// MS2-PIN: ??_G?$TSingleton@VCAsyncImageLoader@@@@UEAAPEAXI@Z 0x140a5adf0 ; unique
// MS2-PIN: ?vfunc_1@GfxImageLoaderParam@@UEAAHXZ 0x140a5af90 ; unique
// MS2-PIN: ?vfunc_1@ImageLoaderParam@@UEAAHXZ 0x140a5afa0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CAsyncImageLoader@@6B?$TSingleton@VCAsyncImageLoader@@@@@ 0x142dc9c08
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\asyncimageloader.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <list>
#include <stdlib.h>
#include <d3dx9.h>
#include <NiDX9Renderer.h>
#include <NiDX9TextureData.h>
#include <NiRect.h>
#include <NiSourceTexture.h>
#include <NiPixelData.h>
#include <NiImageConverter.h>
#include <NiDevImageConverter.h>
#include <efd/utf8string.h>
#include "ms2/placeholder/casyncimageloader.h"
#include "ms2/commonfiles/chatemoticontable.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cthread_startup.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees and data (bound to the exe by their FUN_<va> / DAT_<va> names) ----
extern const NiPixelFormat DAT_1439fb040;                         // RGBA32
extern NiTexture::FormatPrefs DAT_1439fc800;                // the format preferences of the placeholder image
int FUN_140659080(Unk_140659080* pStart, int hr);           // report the failed start to the creator of the thread
unsigned int FUN_140869420();                               // a random seed
NiImageConverter* FUN_141851720();                          // the calling thread's NiImageConverter
CString FUN_14016a5c0(const char* sz, int n);               // the normalized asset path
CString FUN_1409a2360(const char* sz, int n);               // a copy of the string
int FUN_1407181d0(const CString& str);                      // atoi of the string (the emoticon id)

// The texture cache of the loading service (singleton 0x140a0afd0).
class Unk_TexCache
{
public:
    efd::SmartPointer<NiTexture> FUN_141553eb0(CString strPath, int nFlags);                       // find a loaded texture
    efd::SmartPointer<NiTexture> FUN_1415534d0(CString strPath, NiPointer<NiPixelData> spPixels, int nClass);   // register one from pixels
};
Unk_TexCache* FUN_140a0afd0();

void* FUN_1422cf0f0();                                      // the UI renderer context
void* FUN_14257a340(int n3, int n1, Unk_ImgSize* pSize, int nFormat, void* pHeap, void* pTexMan, void* pSync);   // Image::Create(format, mips, size, use, heap, texman, sync)
NiPointer<NiSourceTexture> FUN_141d33530(NiPixelData* pPixels, const NiTexture::FormatPrefs& kPrefs, bool bStatic);   // NiSourceTexture::Create_ThreadSafe (smart pointer: hidden return in rcx)
void FUN_14184d520(const unsigned char* pucPixel, NiPixelData* pkDest, const NiRect<unsigned int>& kRect);   // fill a rectangle
void FUN_14272b7f0(void* pTarget, IDirect3DBaseTexture9* pD3DTexture);       // bind the D3D texture to the image
void* FUN_14208a860(unsigned __int64 nSize, int nHint);     // MemObject operator new
void* FUN_140876480(void* pOut, int n);                     // efd::MemHint(NONE)

// The request of the queues: the file and the loaded texture (the image is in the derived class).
class ImageLoaderParam : public CPtred
{
public:
    ImageLoaderParam();                                     // 0x140a5a850
    virtual ~ImageLoaderParam();                            // 0x140a5aa70
    virtual int vfunc_1() { return 0; }                     // 0x140a5afc0 the kind of request

    CString m_18;                                           // +0x18 the file
    efd::SmartPointer<NiTexture> m_20;                      // +0x20 the loaded texture
};
MS2_CHECK_SIZE(ImageLoaderParam, 0x28);

class GfxImageLoaderParam : public ImageLoaderParam
{
public:
    GfxImageLoaderParam();
    virtual ~GfxImageLoaderParam();
    virtual int vfunc_1() { return 1; }

    Unk_GfxRef m_28;                                        // +0x28 the Scaleform image that shows the texture
};
MS2_CHECK_SIZE(GfxImageLoaderParam, 0x30);

// @0x140a5a850
ImageLoaderParam::ImageLoaderParam()
    : m_18("")
    , m_20(0)
{
}

// @0x140a5aa70
ImageLoaderParam::~ImageLoaderParam()
{
}

// @0x140a5a800
GfxImageLoaderParam::GfxImageLoaderParam()
    : m_28(0)
{
}

// @0x140a5aa30
GfxImageLoaderParam::~GfxImageLoaderParam()
{
}

// @0x140a58820
CAsyncImageLoader::CAsyncImageLoader()
{
    m_28 = 0;
    m_20 = 0;
    m_30 = CreateSemaphoreA(0, 0, 0x7fffffff, 0);
}

// @0x140a58900
CAsyncImageLoader::~CAsyncImageLoader()
{
    if (m_30 != 0)
        CloseHandle(m_30);
    if (m_28 != 0)
        CloseHandle(m_28);
}

// @0x140a589d0
void CAsyncImageLoader::FUN_140a589d0(const CString& strFile, Unk_GfxRef spImage)
{
    GfxImageLoaderParam* pParam = new GfxImageLoaderParam;
    pParam->m_18 = strFile;
    pParam->m_20 = 0;
    pParam->m_28 = spImage;
    {
        Unk_LockGuard guard(m_38);
        if (guard != 0)
        {
        }
        else
        {
            m_68.push_back(pParam);
        }
    }
    ReleaseSemaphore(m_30, 1, 0);
}

// @0x140a58b10
void CAsyncImageLoader::FUN_140a58b10()
{
    if (m_28 != 0)
        SetEvent(m_28);
    if (m_30 != 0)
    {
        m_20 = 1;
        ReleaseSemaphore(m_30, 1, 0);
        FUN_1401d3510(0xffffffff);
    }
    FUN_140a597a0();
}

// @0x140a58b90
void CAsyncImageLoader::FUN_140a58b90()
{
    {
        Unk_LockGuard guard(m_38);
        if (guard != 0)
        {
        }
        else
            m_88.splice(m_88.end(), m_78);
    }
    ParamList::iterator it = m_88.begin();
    while (it != m_88.end())
    {
        ParamPtr spParam = *it;
        if (!spParam)
        {
            MS2_ASSERT_AT(0x48, 0);
            continue;
        }
        if (FUN_140a59540(ParamPtr(spParam)))
            it = m_88.erase(it);
        else
            ++it;
    }
}

// @0x140a58d70
unsigned int CAsyncImageLoader::vfunc_1(void*, Unk_140659080& start)
{
    m_28 = CreateEventA(0, 0, 0, 0);
    if (m_28 == 0)
    {
        FUN_140659080(&start, E_FAIL);
        return -1;
    }
    start.FUN_1401d42d0();
    srand(FUN_140869420());
    while (0 != 1)
    {
        WaitForSingleObject(m_30, INFINITE);
        if (m_20)
            break;
        ParamList pending;
        {
            Unk_LockGuard guard(m_38);
            if (guard != 0)
            {
            }
            else
                pending.splice(pending.end(), m_68);
        }
        ParamList loaded;
        MS2_FOR_EACH(ParamPtr spParam, pending)
        {
            if (!FUN_140a59090(ParamPtr(spParam)))
                continue;
            loaded.push_back(spParam);
        }
        {
            Unk_LockGuard guard(m_38);
            if (guard != 0)
            {
            }
            else
                m_78.splice(m_78.end(), loaded);
        }
        DWORD dwWait = WaitForSingleObject(m_28, 10);
        if (dwWait == 0)
            break;
    }
    return 0;
}

// @0x140a59090
bool CAsyncImageLoader::FUN_140a59090(ParamPtr spParam)
{
    if (!spParam)
    {
        MS2_ASSERT_AT(0xbb, 0);
        return false;
    }
    CString strFile = FUN_14016a5c0(spParam->m_18, 0);
    efd::SmartPointer<NiTexture> spTexture = FUN_140a0afd0()->FUN_141553eb0(CString(strFile), 0);
    if (spTexture.operator NiTexture*() != 0)
    {
        spParam->m_20 = spTexture;
        return true;
    }
    efd::utf8string path(FUN_1409a2360(strFile, 0));
    NiImageConverter* pkConverter = NiDynamicCast(NiDevImageConverter, FUN_141851720());
    if (pkConverter == 0)
    {
        MS2_ASSERT_AT(0xcc, 0);
        return false;
    }
    NiPointer<NiPixelData> spPixels = pkConverter->ReadImageFile(path.c_str(), 0);
    if (spPixels.operator NiPixelData*() == 0)
    {
        MS2_ASSERT_AT(0xd3, 0);
        return false;
    }
    efd::SmartPointer<NiTexture> spCreated = FUN_140a0afd0()->FUN_1415534d0(CString(strFile), spPixels, 5);
    if (spCreated.operator NiTexture*() == 0)
    {
        MS2_ASSERT_AT(0xda, 0);
        return false;
    }
    spParam->m_20 = spCreated;
    return true;
}

// @0x140a59540
bool CAsyncImageLoader::FUN_140a59540(ParamPtr spParam)
{
    if (!spParam)
    {
        MS2_ASSERT_AT(0x5b, 0);
        return false;
    }
    void* pCtx = FUN_1422cf0f0();
    if (pCtx == 0)
    {
        MS2_ASSERT_AT(0x62, 0);
        return false;
    }
    if (spParam->m_20.operator NiTexture*() == 0)
    {
        MS2_ASSERT_AT(0x68, 0);
        return false;
    }
    NiTexture::RendererData* pRendererData = spParam->m_20->GetRendererData();
    if (pRendererData == 0)
        return false;
    switch (spParam->vfunc_1())
    {
    case 1:
    {
        GfxImageLoaderParam* pGfx = static_cast<GfxImageLoaderParam*>(spParam.get());
        void* pTarget = pGfx->m_28->vfunc_24(pCtx);
        if (pTarget == 0)
        {
            MS2_ASSERT_AT(0x78, 0);
            return false;
        }
        FUN_14272b7f0(pTarget, ((NiDX9TextureData*)pRendererData)->GetD3DTexture());
        break;
    }
    }
    return true;
}

// @0x140a597a0
void CAsyncImageLoader::FUN_140a597a0()
{
    Unk_LockGuard guard(m_38);
    if (guard != 0)
    {
    }
    else
    {
        m_68.clear();
        m_78.clear();
        m_88.clear();
    }
}

// Creates the Scaleform image for a file name (a plain path or an emoticon id), starts its asynchronous load and returns
// the image; a cached texture is bound at once.
struct Unk_ImgReq
{
    int m_pad_00[2];
    CString m_name;                                         // +0x08
    char m_pad_10[0x10];
    int m_kind;                                             // +0x20 5 = emoticon id
};

// Image::GetSize (slot 5) returns the size by value; the shared Unk_GfxImage declares it with an out pointer.
class Unk_GfxImageSizeView
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual Unk_ImgSize GetSize();
};
#define MS2_IMAGE_SIZE(p) (reinterpret_cast<Unk_GfxImageSizeView*>(p)->GetSize())

// @0x140a59830
Unk_GfxImage* FUN_140a59830(Unk_ImgReq* pReq, void* pCtx)
{
    CString strFile;
    switch (pReq->m_kind)
    {
    case 5:
        {
            int nId = FUN_1407181d0(pReq->m_name);
            ChatEmoticonDataPtr spData = CChatEmoticonTable::GetInstance()->FUN_1401e7120(nId);
            if (!spData)
                break;
            strFile = spData->m_strImagePath;
        }
        break;
    default:
        strFile = pReq->m_name;
    }
    NiImageConverter* pkConverter = NiDynamicCast(NiDevImageConverter, FUN_141851720());
    if (pkConverter == 0)
    {
        MS2_ASSERT_AT(0x108, 0);
        return 0;
    }
    NiPixelFormat kFormat;
    bool bMipmap;
    unsigned int uiWidth;
    unsigned int uiHeight;
    unsigned int uiFaces;
    if (!pkConverter->ReadImageFileInfo(strFile, kFormat, bMipmap, uiWidth, uiHeight, uiFaces))
        return 0;
    const int nUse = 0x11;
    Unk_ImgSize size(uiWidth, uiHeight);
    const int nFormat = 3;
    Unk_GfxImage* pImage = (Unk_GfxImage*)FUN_14257a340(nFormat, 1, &size, nUse, 0, pCtx, 0);
    if (pImage == 0)
        return 0;
    void* pTarget = pImage->vfunc_24(pCtx);
    if (pTarget == 0)
        return pImage;
    do
    {
        efd::SmartPointer<NiTexture> spTexture = FUN_140a0afd0()->FUN_141553eb0(CString(strFile), 0);
        if (spTexture.operator NiTexture*() == 0)
            break;
        NiTexture::RendererData* pRendererData = spTexture->GetRendererData();
        if (pRendererData == 0)
            break;
        FUN_14272b7f0(pTarget, ((NiDX9TextureData*)pRendererData)->GetD3DTexture());
        return pImage;
    } while (0);
    CAsyncImageLoader::GetInstance()->FUN_140a589d0(strFile, Unk_GfxRef(pImage));
    // The placeholder shown until the file is read: a half transparent fill of the image size.
    NiPointer<NiPixelData> spFill = NiNew NiPixelData(MS2_IMAGE_SIZE(pImage).m_w, MS2_IMAGE_SIZE(pImage).m_h,
                                                      DAT_1439fb040, 1, 1);
    if ((NiPixelData*)spFill == 0)
        return pImage;
    unsigned int uiPixel = 0x3f000000;     // r, g, b 0 and alpha 0x3f
    NiRect<unsigned int> kRect(0, MS2_IMAGE_SIZE(pImage).m_w, 0, MS2_IMAGE_SIZE(pImage).m_h);
    FUN_14184d520((const unsigned char*)&uiPixel, spFill, kRect);
    NiPointer<NiSourceTexture> spPlaceholder = FUN_141d33530(spFill, DAT_1439fc800, true);
    if ((NiSourceTexture*)spPlaceholder == 0)
        return pImage;
    NiTexture::RendererData* pData = spPlaceholder->GetRendererData();
    if (pData == 0)
        return pImage;
    FUN_14272b7f0(pTarget, ((NiDX9TextureData*)pData)->GetD3DTexture());
    return pImage;
}
