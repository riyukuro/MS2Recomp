// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxImageLoader, the Scaleform image creator of the GFx UI
// library, and its "img://" url Protocol.
// MS2-UNIT: ?\gfximageloader.cpp
// MS2-RANGE: 0x1422ed8c0-0x1422ef250 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The
// class is declared in src/ms2/placeholder/gfximageloader.h. The TU starts at the Protocol ctor 0x1422ece40: Protocol's
// ctor / Parse / Token (0x1422ece40-0x1422ed8c0) sit in the queue range of ?\gfxvideo.cpp but belong here.
#include "ms2/placeholder/ms2stdafx.h"

#include <stdlib.h>

#include "ms2/placeholder/gfximageloader.h"
#include "Kernel/SF_SysFile.h"
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/gfxui/uiswfentity.h"

#include "hook/ms2hook.h"

using Scaleform::File;
using Scaleform::MemoryFile;
using Scaleform::Ptr;
using Scaleform::String;
using Scaleform::GFx::ImageCreateInfo;
using Scaleform::Render::Image;
using Scaleform::Render::ImageCreateArgs;
using Scaleform::Render::ImageFileReader;
using Scaleform::Render::ImageSize;
using Scaleform::Render::ImageSource;
using Scaleform::Render::TextureManager;

// The GFx UI manager singleton (0x14025e7a0; its class lives in the library's first obj, 0x1422b0060-0x1422b7f20).
class Unk_GFxUIManager
{
public:
    void FUN_1422b0470(int nView, int* pWidth, int* pHeight);  // the size of a view (2: the screen shot)
    Ptr<File> FUN_1422b0d60(String strPath);                   // the cached memory file of a path (NULL if none)
    void FUN_1422b0e20(String strPath, Ptr<File> pFile);       // caches (or with NULL drops) the memory file of a path
};
Unk_GFxUIManager* FUN_14025e7a0();

// The image a UI movie receives in vfunc_25 (uiswfentity.h names the TPtr pointee Unk_UISwfEntity_25): a Scaleform
// render image.
class Unk_UISwfEntity_25 : public Image
{
};

// Scaleform::MemoryFile's private layout (SF_File.h), for the game's validity re-check below (not an SDK method).
class Unk_MemoryFileView : public File
{
public:
    // @0x1422ef1e0
    bool FUN_1422ef1e0()
    {
        m_nFileIndex = 0;
        m_bValid = (!m_strFilePath.IsEmpty() && m_pFileData && m_nFileSize > 0) ? true : false;
        return m_bValid;
    }

    String m_strFilePath;               // +0x10
    const Scaleform::UByte* m_pFileData;           // +0x18
    int m_nFileSize;                    // +0x20
    int m_nFileIndex;                   // +0x24
    bool m_bValid;                      // +0x28
};
MS2_CHECK_OFFSET(Unk_MemoryFileView, m_nFileIndex, 0x24);
MS2_CHECK_SIZE(Unk_MemoryFileView, sizeof(MemoryFile));

// ---- GFxImageLoader::Protocol -------------------------------------------------------------------------------------------

// @0x1422ece40
GFxImageLoader::Protocol::Protocol()
    : m_nWidth(0)
    , m_nHeight(0)
    , m_strPath("")
    , m_strHost("")
    , m_nType(1)
{
}

// @0x1422eced0
int GFxImageLoader::Protocol::Parse(const String& strUrl)
{
    CString str(strUrl.ToCStr());
    m_strHost = Token(str, ":");
    if (m_strHost.IsEmpty())
        return 0;

    if (m_strHost == "ugc")
    {
        str.Replace("img://", "");
        m_strPath = str;
    }
    else if (m_strHost == "icon")
        m_strPath = str;
    else if (m_strHost == "keepMem")
        m_strPath = str;
    else if (m_strHost == "emoticon")
        m_strPath = str;
    else
        m_strPath = Token(str, "/");

    if (m_strPath.IsEmpty())
        return 0;

    if (m_strPath == "webBrowser")
    {
        m_nWidth = atoi(Token(str, "/"));
        m_nHeight = atoi(Token(str, "/"));
        m_nType = 0;
    }
    else if (m_strHost == "icon")
    {
        m_nWidth = 0;
        m_nHeight = 0;
        m_nType = 1;
    }
    else if (m_strHost == "keepMem")
    {
        m_nWidth = 0;
        m_nHeight = 0;
        m_nType = 4;
    }
    else if (m_strHost == "emoticon")
    {
        m_nWidth = 0;
        m_nHeight = 0;
        m_nType = 5;
    }
    else if (m_strPath == "faceView" || m_strPath == "cube")
    {
        m_nWidth = atoi(Token(str, "/"));
        m_nHeight = atoi(Token(str, "/"));
        m_nType = 2;
    }
    else if (m_strPath == "avatar")
    {
        m_nWidth = atoi(Token(str, "/"));
        m_nHeight = atoi(Token(str, "/"));
        m_strExtra = Token(str, "/");
        m_nType = 2;
    }
    else if (m_strPath == "screenShot")
    {
        int nWidth;
        int nHeight;
        FUN_14025e7a0()->FUN_1422b0470(2, &nWidth, &nHeight);
        m_nWidth = nWidth;
        m_nHeight = nHeight;
        m_nType = 3;
    }
    return 1;
}

// @0x1422ed7a0
CString GFxImageLoader::Protocol::Token(CString& str, CString strDelim)
{
    str.Replace("img://", "");
    int nPos = str.Find(strDelim, 0);
    if (nPos == -1)
        nPos = str.GetLength();
    CString strToken = str.Mid(0, nPos);
    str = str.Mid(nPos + 1);
    return strToken;
}

// ---- GFxImageLoader -----------------------------------------------------------------------------------------------------

// @0x1422ed8c0
GFxImageLoader::GFxImageLoader(TextureManager* pTextureManager)
    : Scaleform::GFx::ImageCreator(pTextureManager)
{
}

// @0x1422ed950
Image* GFxImageLoader::LoadProtocolImage(const ImageCreateInfo& info, const String& url)
{
    Protocol kProtocol;
    if (kProtocol.Parse(url) == 0)
        return 0;

    if (kProtocol.m_nType == 4)
    {
        String strPath(kProtocol.m_strPath);
        Image* pImage = FUN_1422edd80(info, strPath);
        if (pImage != NULL)
            return pImage;
    }
    else if (kProtocol.m_nType == 1)
    {
        String strPath(kProtocol.m_strPath);
        Image* pImage = LoadImageFile(info, strPath);
        if (pImage != NULL)
            return pImage;
    }
    else if (kProtocol.m_nType == 5)
    {
        if (m_fnCallback.IsNull())
            return 0;
        Image* pImage = m_fnCallback(kProtocol, GetTextureManager());
        if (pImage == NULL)
            return 0;
        return pImage;
    }
    else if (kProtocol.m_nType == 0 || kProtocol.m_nType == 2 || kProtocol.m_nType == 3)
    {
        MS2Ptr<UISwfEntity> spEntity = FUN_140b632f0()->FUN_1422d41b0(kProtocol.m_strHost);
        if (spEntity.get() != NULL)
        {
            unsigned nUse = Scaleform::Render::ImageUse_Update | Scaleform::Render::ImageUse_Wrap;
            ImageSize kSize(kProtocol.m_nWidth, kProtocol.m_nHeight);
            Scaleform::Render::ImageFormat eFormat = Scaleform::Render::Image_R8G8B8;
            Image* pImage = Image::Create(eFormat, 1, kSize, nUse, 0, GetTextureManager(), 0);
            if (pImage != NULL)
            {
                spEntity->vfunc_25(&kProtocol.m_strPath, TPtr<Unk_UISwfEntity_25>(static_cast<Unk_UISwfEntity_25*>(pImage)),
                    GetTextureManager(), &kProtocol.m_strExtra);
                return pImage;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422ED950, GFxImageLoader, LoadProtocolImage, 1057, 0x42FE56D9);

// @0x1422edd80
// MS2-FUNCTIONAL: Scaleform's ImageCreator::pTextureManager is private; read through GetTextureManager()
Image* GFxImageLoader::FUN_1422edd80(const ImageCreateInfo& info, const String& url)
{
    Scaleform::GFx::ImageFileHandlerRegistry* pRegistry = info.GetImageFileHandlerRegistry();
    if (pRegistry == NULL || info.GetFileOpener() == NULL)
        return 0;

    String strPath(url);
    Scaleform::FileStat kStat;
    if (!url.HasExtension())
    {
        if (GetTextureManager() != NULL)
        {
            unsigned nFormats = GetTextureManager()->GetTextureFormatSupport();
            if (nFormats & Scaleform::Render::ImageFormats_DXT)
            {
                strPath = url + ".dds";
                if (Scaleform::SysFile::GetFileStat(&kStat, strPath))
                    goto found;
            }
            else if ((nFormats & Scaleform::Render::ImageFormats_PVR) || (nFormats & Scaleform::Render::ImageFormats_ETC))
            {
                strPath = url + ".pvr";
                if (Scaleform::SysFile::GetFileStat(&kStat, strPath))
                    goto found;
            }
        }
        strPath = url + ".tga";
    }
found:
    strPath.ToLower();

    Ptr<File> pFile(NULL);
    MemoryFile* pMemFile = NULL;
    bool bCached = false;
    bool bOpened = false;
    if (FUN_14025e7a0() != NULL)
    {
        pFile = FUN_14025e7a0()->FUN_1422b0d60(String(strPath));
        if (pFile)
            pMemFile = dynamic_cast<MemoryFile*>(pFile.GetPtr());
        if (pMemFile != NULL)
            bCached = true;
    }
    if (!pFile)
    {
        pFile = info.GetFileOpener()->OpenFile(strPath.ToCStr(),
            Scaleform::FileConstants::Open_Read | Scaleform::FileConstants::Open_Buffered,
            Scaleform::FileConstants::Mode_ReadWrite);
        if (pFile)
            pMemFile = dynamic_cast<MemoryFile*>(pFile.GetPtr());
        if (pMemFile != NULL)
            bOpened = true;
        else
            return 0;
    }

    Scaleform::Lock kLock(0);
    if (bCached)
        kLock.DoLock();

    ImageFileReader* pReader;
    ImageCreateArgs kArgs;
    if (pRegistry->DetectFormat(&pReader, pFile, 0) != Scaleform::Render::ImageFile_Unknown)
    {
        kArgs.pHeap = info.pHeap;
        kArgs.Use = info.Use;
        kArgs.pManager = GetTextureManager();
        if (info.RUse == Scaleform::GFx::Resource::Use_FontTexture)
            kArgs.Format = Scaleform::Render::Image_A8;
        Ptr<ImageSource> pSource = *pReader->ReadImageSource(pFile, kArgs);
        if (pSource)
        {
            Image* pImage = CreateImage(info, pSource);
            if (pMemFile != NULL)
            {
                if (!((Unk_MemoryFileView*)pMemFile)->FUN_1422ef1e0())
                {
                    if (FUN_14025e7a0() != NULL)
                        FUN_14025e7a0()->FUN_1422b0e20(String(strPath), Ptr<File>(NULL));
                }
                else if (bOpened && FUN_14025e7a0() != NULL)
                    FUN_14025e7a0()->FUN_1422b0e20(String(strPath), pFile);
                if (bCached)
                    kLock.Unlock();
            }
            return pImage;
        }
    }

    Image* pImage = pRegistry->ReadImage(pFile, kArgs);
    if (pMemFile != NULL)
    {
        if (!((Unk_MemoryFileView*)pMemFile)->FUN_1422ef1e0())
        {
            if (FUN_14025e7a0() != NULL)
                FUN_14025e7a0()->FUN_1422b0e20(String(strPath), Ptr<File>(NULL));
        }
        else if (bOpened && FUN_14025e7a0() != NULL)
            FUN_14025e7a0()->FUN_1422b0e20(String(strPath), pFile);
        if (bCached)
            kLock.Unlock();
    }
    return pImage;
}
MS2_REPLACE_METHOD(0x1422EDD80, GFxImageLoader, FUN_1422edd80, 2481, 0xDB9C442C);

// MS2-PIN: ??_GGFxImageLoader@@UEAAPEAXI@Z 0x1422eecb0
