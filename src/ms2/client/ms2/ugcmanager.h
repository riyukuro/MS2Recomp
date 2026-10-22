// ugcmanager.h - types shared by the four client\ms2\ugcmanager.cpp translation units (#1..#4). NOT an original header.
// #1 ugcmanager_1.cpp: CUgcCompress (zlib .m2u packages), the D3DX image converter, the upload/thumbnail file helpers
//    and the CUgcDownloadLoad worker.
// #2 ugcmanager_2.cpp: the download controllers (one CUgcDownloadCtrl per URL, a subclass per content kind) and the
//    CUgcDownloadDown worker that runs them.
// #3 ugcmanager_3.cpp: UGCItemSlot.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/client/ms2/httpdownloadcallback.h"
#include "ms2/client/ms2/ms2dragslot.h"

namespace efd { class File; }
class NiTexture;
class ASObj;
class CItem;

// A local image file offered for upload (0x58, vftable 0x142f8dd48; ugcmanager.cpp#4). Name from RTTI.
class CUploadFile : public CPtred
{
public:
    CUploadFile();                                          // 0x14187e420
    void Set(const CStringW& strPath, const CStringW& strName, __int64 tWrite, __int64 tCreate, int bThumbnail);
    void SetInDir(const CStringW& strFile, const CStringW& strDir, __int64 tWrite, __int64 tCreate, int bThumbnail);
    void SplitPath(int bThumbnail);
    CStringW GetPath();
    CStringW GetName();
    __int64 GetCreateTime();
    __int64 GetWriteTime();
    void SetWriteTime(__int64 t);
    CStringW GetTitle();
    CStringW GetExt();
    CStringW GetThumbnailDir();
    CStringW GetThumbnailPath();
    int Refresh();                                          // re-read the write time; 1 if it changed
private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strName;                                     // +0x18 file name with extension
    CStringW m_strPath;                                     // +0x20 full path
    __int64 m_tWrite;                                       // +0x28
    __int64 m_tCreate;                                      // +0x30
    CStringW m_strTitle;                                    // +0x38 file name without extension
    CStringW m_strExt;                                      // +0x40 extension with the dot
    CStringW m_strThumbDir;                                 // +0x48
    CStringW m_strThumbPath;                                // +0x50
};
MS2_CHECK_SIZE(CUploadFile, 0x58);

// zlib packer for UGC files: Compress writes "<convert dir>\upload.m2u" from a file, Decompress inflates a downloaded
// .m2u into memory. Name from the log text "CUgcCompress::Decompress".
class CUgcCompress
{
public:
    CUgcCompress();                                         // 0x1418694d0
    ~CUgcCompress();                                        // 0x1418695a0
    int Compress(const CStringW& strOrgFile, void* pUnused);
    int Decompress(const CStringW& strZipFile, unsigned __int64 userData);
    CStringW GetOrgFile();
    CStringW GetZipFile();
    efd::File* CreateMemFile();
    BYTE* GetBuffer();
    int GetDataSize();
    void Close();
    int DoCompress();
    int DoDecompress();
private:
    MS2_LAYOUT_FRIEND;
    FILE* m_pOrgFile;                                       // +0x00
    FILE* m_pZipFile;                                       // +0x08
    int m_bCompress;                                        // +0x10
    CStringW m_strOrgFile;                                  // +0x18
    CStringW m_strZipFile;                                  // +0x20
    BYTE* m_pBuffer;                                        // +0x28 inflated data (efd allocator)
    int m_nBufferSize;                                      // +0x30
    int m_nDataSize;                                        // +0x34
};
MS2_CHECK_SIZE(CUgcCompress, 0x38);

// Loads an image through D3DX and re-saves it in the format/size an upload kind needs. The name is invented.
class CUgcImageConverter
{
public:
    CUgcImageConverter();                                   // 0x14186a430
    ~CUgcImageConverter();                                  // 0x14186a4a0
    CStringW GetSrcFile();
    CStringW GetDstFile();
    int GetState();
    int ConvertTexture(const CStringW& strSrc, int nSize, bool bPng);
    int ConvertIcon(const CStringW& strSrc);
    int ConvertThumbnail(const CStringW& strSrc);
    int ConvertMemory(const CStringW& strSrc, const void* pData, int nSize);
    int ConvertBanner(const CStringW& strSrc);
    void Clear();
    int LoadFile();
    int LoadMemory(const void* pData, int nSize);
    int Convert(D3DFORMAT eFormat, int nWidth, int nHeight, int nMipSize);
    int GetMipLevels(int nWidth, int nHeight);
    HRESULT CopySurfaces(int nUnused, IDirect3DTexture9* pDst);
    int Save(D3DXIMAGE_FILEFORMAT eFormat);
private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strSrcFile;                                  // +0x00
    CStringW m_strDstFile;                                  // +0x08
    int m_nState;                                           // +0x10 1 once a destination is chosen
    IDirect3DTexture9* m_pSrcTexture;                       // +0x18
    IDirect3DTexture9* m_pDstTexture;                       // +0x20
    int m_nWidth;                                           // +0x28
    int m_nHeight;                                          // +0x2c
    int m_nDepth;                                           // +0x30
    int m_nMipLevels;                                       // +0x34
};
MS2_CHECK_SIZE(CUgcImageConverter, 0x38);

// Result of the file helpers (also used by UIItemBlueprintCreateDialog as Unk_BpImageResult). The name is invented.
struct Unk_UgcFileResult
{
    Unk_UgcFileResult() { Reset(); }                        // 0x14186e3a0
    void Reset()                                            // 0x14186e790
    {
        m_nResult = 1;
        m_strName = L"";
        m_strPath = L"";
        m_bTemporary = 0;
    }
    int m_nResult;                                          // +0x00 0 = success, else an error code
    CStringW m_strName;                                     // +0x08
    CStringW m_strPath;                                     // +0x10
    int m_bTemporary;                                       // +0x18
};
MS2_CHECK_SIZE(Unk_UgcFileResult, 0x20);

Unk_UgcFileResult ChangeFormat(int nType, MS2Ptr<CUploadFile> pUploadFile, int nSize, bool bPng);
efd::SmartPointer<NiTexture> LoadUgcTexture(const CStringW& strPath, int nSize, bool bPng);
efd::SmartPointer<NiTexture> LoadCachedTexture(const CStringW& strPath);
int ConvertIconFile(const CStringW& strPath);

// 0xa0 bytes. vftable 0x142f8b450 (27 slots, ??_G 0x14187dfa0 sized delete 0xa0), ITooltip @+0x78 0x142f8b530.
// A drag slot showing one item of a UGC (design shop) list.
class UGCItemSlot : public MS2DragSlot
{
public:
    UGCItemSlot(const CString& strName, MS2Ptr<CItem> spItem);   // 0x14187d7e0
    virtual ~UGCItemSlot() = default;               // 0x14187df70 (implicit: the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x14187e000, TypeCast 0x14187e070 / 0x14187e0c0; ms_ClassInfo 0x143af0880,
    // SetupClassInfo 0x14187e010 (parent MS2DragSlot, id 0x620003e).
    EE_DECLARE_CLASS1(UGCItemSlot, 0x0620003E, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                   // 8  0x14187dd50 build the item slot into p
    virtual int vfunc_11();                         // 11 0x14187d960 drop the item
    virtual MS2Ptr<CItem> vfunc_25();               // 25 0x14187d910 the item in the slot
    virtual int vfunc_26(ASObj& obj);               // 26 0x14187d9a0 fill the AS slot data
    virtual int vfunc_0(void* p);                   // ITooltip 0x14187dc70 build the item tooltip into p

    int FUN_14187d870();                            // item template id, 0 if empty
    void SetItem(MS2Ptr<CItem> spItem);       // m_spItem = spItem

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                         // +0x90
};
MS2_CHECK_SIZE(UGCItemSlot, 0xa0);
MS2_CHECK_OFFSET(UGCItemSlot, m_spItem, 0x90);

void FUN_14187de00(const CString& strName, MS2Ptr<CItem> spItem);   // create a UGCItemSlot and bind it by name
void FUN_14187dee0(const CString& strName);                         // unbind the named UGCItemSlot

// ---- ugcmanager.cpp#2: downloads ----------------------------------------------------------------------------------

// What to download (vftable 0x142f8aa88, 0xa8 bytes): the content kind, its owner and uploaded file, and the URL.
class CUgcDownloadParam : public CPtred
{
public:
    CUgcDownloadParam();                                    // 0x14186ef00
    virtual ~CUgcDownloadParam();                           // 0x14186ef80
    void Clear();                                           // 0x14186eff0
    void CopyFrom(const CUgcDownloadParam* pOther);         // 0x14186f080

    int m_nType;                                            // +0x18 the content kind (1 equip, 2 cube, 3 banner, ...)
    CUgcUserProxy m_user;                                   // +0x20
    CUgcUploadProxy m_upload;                               // +0x60
    CString m_strUrl;                                       // +0x98
    int m_bLocal;                                           // +0xa0 the file is already on disk: load it, no download
};
MS2_CHECK_SIZE(CUgcDownloadParam, 0xa8);

// One download (vftables 0x142f8aa98 / CPtred 0x142f8ab00, 0x100 bytes): a URLMON thread fetches m_strUrl into
// m_strPath; the subclass keeps the proxies that wait for the file and updates them in ProcessResult.
class CUgcDownloadCtrl : public XBindStatusCallback, public CPtred
{
public:
    CUgcDownloadCtrl(CString strUrl);                       // 0x14186f150
    virtual ~CUgcDownloadCtrl();                            // 0x14186f290

    virtual HRESULT OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText);
    virtual void AddProxy(IUgcProxy* pProxy) = 0;           // 8
    virtual void MakePath() = 0;                            // 9  the local file of m_strUrl
    virtual void ProcessResult() = 0;                       // 10 hand the file to the proxies
    // @0x1418786e0
    virtual int OnDownloaded() { return 1; }                // 11 0: queued for loading (the loader reports back)

    CString GetUrl();                                       // 0x14186f320
    CString GetPath();                                      // 0x14186f370
    CString GetFileName();                                  // 0x14186f3c0 the name after ".s3."
    int IsComplete();                                       // 0x14186f510
    void SetResult(int nResult);                            // 0x14186f530
    int GetResult();                                        // 0x14186f550
    void Start();                                           // 0x14186f570
    void OnSuccess();                                       // 0x14186f5d0
    void OnFailure(HRESULT hr);                             // 0x14186f650
    static UINT Downloading(LPVOID pParam);                 // 0x14186f780 the download thread

    CUgcDownloadParam m_param;                              // +0x20
    CString m_strUrl;                                       // +0xc8
    CString m_strPath;                                      // +0xd0
    int m_bComplete;                                        // +0xd8 URLMON reported the end of the data
    int m_nResult;                                          // +0xdc 0 = ok (set by CUgcManager)
    HttpDownloadCallback m_callback;                        // +0xe0
    CWinThread* m_pThread;                                  // +0xf8
};
MS2_CHECK_SIZE(CUgcDownloadCtrl, 0x100);
MS2_CHECK_OFFSET(CUgcDownloadCtrl, m_param, 0x20);
MS2_CHECK_OFFSET(CUgcDownloadCtrl, m_pThread, 0xf8);

// CUgcDownloadCtrl reaches CPtred through its second base (+0x8): the pointer converts through it.
template <> inline void MS2Ptr<CUgcDownloadCtrl>::AddRef() const
{
    if (m_p)
        AddRefImpl(static_cast<CPtred*>(static_cast<CUgcDownloadCtrl*>(0)));
}
template <> inline void MS2Ptr<CUgcDownloadCtrl>::Release()
{
    if (m_p)
    {
        ReleaseImpl(static_cast<CPtred*>(static_cast<CUgcDownloadCtrl*>(0)));
        m_p = 0;
    }
}
template <> inline MS2Ptr<CUgcDownloadCtrl>::MS2Ptr(CUgcDownloadCtrl* p)
{
    m_p = static_cast<CUgcDownloadCtrl*>(static_cast<CPtred*>(p));
    AddRef();
}

// The subclasses (RTTI names). A list subclass keeps every proxy that asked for the URL.
class CUgcDownloadEquip : public CUgcDownloadCtrl            // 0x130, kind 1
{
public:
    CUgcDownloadEquip(CString strUrl);
    virtual ~CUgcDownloadEquip();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    virtual int OnDownloaded();
    CAtlList<MS2Ptr<CUgcItemPC> > m_list;                   // +0x100
};
MS2_CHECK_SIZE(CUgcDownloadEquip, 0x130);

class CUgcDownloadCube : public CUgcDownloadCtrl             // 0x130, kind 2
{
public:
    CUgcDownloadCube(CString strUrl);
    virtual ~CUgcDownloadCube();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    virtual int OnDownloaded();
    CAtlList<MS2Ptr<CUgcItemCube> > m_list;                 // +0x100
};

class CUgcDownloadItemIcon : public CUgcDownloadCtrl         // 0x130, kind 0xc9
{
public:
    CUgcDownloadItemIcon(CString strUrl);
    virtual ~CUgcDownloadItemIcon();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    CAtlList<MS2Ptr<CUgcItemIconPC> > m_list;               // +0x100
};

class CUgcDownloadBanner : public CUgcDownloadCtrl           // 0x110, kind 3
{
public:
    CUgcDownloadBanner(CString strUrl);
    virtual ~CUgcDownloadBanner();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    virtual int OnDownloaded();
    MS2Ptr<CUgcBannerPost> m_spPost;                        // +0x100
};
MS2_CHECK_SIZE(CUgcDownloadBanner, 0x110);

class CUgcDownloadProfile : public CUgcDownloadCtrl          // 0x130, kind 5
{
public:
    CUgcDownloadProfile(CString strUrl);
    virtual ~CUgcDownloadProfile();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    CAtlList<MS2Ptr<CUgcUserProxy> > m_list;                // +0x100
};

class CUgcDownloadWeddingProfile : public CUgcDownloadCtrl   // 0x130, kind 10
{
public:
    CUgcDownloadWeddingProfile(CString strUrl);
    virtual ~CUgcDownloadWeddingProfile();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    CAtlList<MS2Ptr<CUgcUserProxy> > m_list;                // +0x100
};

class CUgcDownloadGuildMark : public CUgcDownloadCtrl        // 0x138, kind 6
{
public:
    CUgcDownloadGuildMark(CString strUrl);
    virtual ~CUgcDownloadGuildMark();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    CAtlList<MS2Ptr<CUgcGuildMarkProxy> > m_list;           // +0x100
    int m_130;                                              // +0x130 (only cleared)
};
MS2_CHECK_SIZE(CUgcDownloadGuildMark, 0x138);

class CUgcDownloadGuildPoster : public CUgcDownloadCtrl      // 0x110, kind 8
{
public:
    CUgcDownloadGuildPoster(CString strUrl);
    virtual ~CUgcDownloadGuildPoster();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    MS2Ptr<CUgcGuildPosterProxy> m_spPoster;                // +0x100
};

class CUgcDownloadRidee : public CUgcDownloadCtrl            // 0x130, kind 7
{
public:
    CUgcDownloadRidee(CString strUrl);
    virtual ~CUgcDownloadRidee();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    virtual int OnDownloaded();
    CAtlList<MS2Ptr<CUgcItemRidee> > m_list;                // +0x100
};

class CUgcDownloadBannerAdvertise : public CUgcDownloadCtrl  // 0x100, kind 0xca
{
public:
    CUgcDownloadBannerAdvertise(CString strUrl);
    virtual ~CUgcDownloadBannerAdvertise();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
};
MS2_CHECK_SIZE(CUgcDownloadBannerAdvertise, 0x100);

class CUgcDownloadShopBanner : public CUgcDownloadCtrl       // 0x130, kinds 0xcb 0xcc 0xcf 0xd2
{
public:
    CUgcDownloadShopBanner(CString strUrl);
    virtual ~CUgcDownloadShopBanner();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    CAtlList<MS2Ptr<CUgcShopBannerProxy> > m_list;          // +0x100
};

class CUgcDownloadAdBanner : public CUgcDownloadCtrl         // 0x100, kind 0xcd
{
public:
    CUgcDownloadAdBanner(CString strUrl);
    virtual ~CUgcDownloadAdBanner();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
};

class CUgcDownloadBannerRollingImage : public CUgcDownloadCtrl   // 0x110, kind 0xce
{
public:
    CUgcDownloadBannerRollingImage(CString strUrl);
    virtual ~CUgcDownloadBannerRollingImage();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    MS2Ptr<CUgcBannerRollingImageProxy> m_spProxy;          // +0x100
};

class CUgcDownloadBlueprintImage : public CUgcDownloadCtrl   // 0x130, kind 9
{
public:
    CUgcDownloadBlueprintImage(CString strUrl);
    virtual ~CUgcDownloadBlueprintImage();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    virtual int OnDownloaded();
    CAtlList<MS2Ptr<CUgcBlueprintImageProxy> > m_list;      // +0x100
};

class CUgcDownloadBlueprintIcon : public CUgcDownloadCtrl    // 0x130, kind 0xd1
{
public:
    CUgcDownloadBlueprintIcon(CString strUrl);
    virtual ~CUgcDownloadBlueprintIcon();
    virtual void AddProxy(IUgcProxy* pProxy);
    virtual void MakePath();
    virtual void ProcessResult();
    CAtlList<MS2Ptr<CUgcItemIconPC> > m_list;               // +0x100
};

// The notification that a downloaded file is ready (vftable 0x142f8b250, 0x38 bytes).
class NotifyUgcDownloadComplete : public NotifyObject
{
public:
    // @0x141877260
    NotifyUgcDownloadComplete(int nType, CString strUrl, CString strPath)
        : m_nType(nType), m_strUrl(strUrl), m_strPath(strPath)
    {
        m_uid = 0;
    }
    virtual CStringW GetTypeName();                             // 0x140db4250 L"NotifyUgcDownloadComplete" (unit_140da50e0)
    int m_nType;                                            // +0x18
    CString m_strUrl;                                       // +0x20
    CString m_strPath;                                      // +0x28
    __int64 m_uid;                                          // +0x30
};
MS2_CHECK_SIZE(NotifyUgcDownloadComplete, 0x38);
