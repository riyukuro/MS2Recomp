// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBannerUrlGetter (name from the Delegate template argument): fetches the
// file behind an ad banner's url through the UGC download manager and signals when the downloaded path is ready; plus its
// Delegate<void(NotifyObject*)> glue and the CRT memmove_s copy.
// MS2-UNIT: unit_1409faff0
// MS2-RANGE: 0x1409faff0-0x1409fbb80 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/cadbannermanagercli.h"
#include "ms2/client/ms2/ugcmanager.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the class (members from the ctor 0x1409faf60 in ?\avatarpc.cpp, where it is built as Unk_UgcDownloadInfo) ----
class CBannerUrlGetter
{
public:
    CBannerUrlGetter(int nKind);                            // 0x1409faf60 (avatarpc.cpp)
    ~CBannerUrlGetter();                                    // 0x1409faff0
    void LoadBanner();                                      // 0x1409fb100
    bool TakeReady();                                       // 0x1409fb210
    CString GetPath() const;                                // 0x1409fb240
    bool OpenLink();                                        // 0x1409fb290
    void OnNotify(NotifyObject* pNotify);                   // 0x1409fb300
    void RequestFile();                                     // 0x1409fb430

    int m_nKind;                                            // +0x00 UGC download kind (0xcd)
    CString m_str08;
    CString m_strUrl;                                       // +0x10 banner url (the download key)
    CString m_strLinkType;                                  // +0x18 compared with "link"
    CString m_strLink;                                      // +0x20 the link to open
    bool m_bReady;                                          // +0x28 the file is downloaded
    CString m_strPath;                                      // +0x30 the downloaded file
};
MS2_CHECK_SIZE(CBannerUrlGetter, 0x38);

// ---- callees ----
extern CAdBannerManagerCli* DAT_143ab3920;
NotifySystem* FUN_140939a10();
CAdBannerManagerCli* GetAdBannerManagerCli();
AdBannerData* FUN_14016e5a0(Unk_AdBannerPtr* pPtr);
CString FUN_14016a600(const wchar_t* psz, int n);           // wide -> narrow
CString FUN_141029ed0(int nKind, const CString& strUrl);    // the cached file of a url
CUgcManager* FUN_14052d220();
void FUN_1418fe1c0(const CString& strLink);

// @0x1409faff0
CBannerUrlGetter::~CBannerUrlGetter()
{
    FUN_140939a10()->UnregisterNotify(L"NotifyUgcDownloadComplete", Delegate<void(NotifyObject*)>(this, &CBannerUrlGetter::OnNotify));
}

// @0x1409fb100
void CBannerUrlGetter::LoadBanner()
{
    Unk_AdBannerPtr spBanner = GetAdBannerManagerCli()->FUN_14096b3e0(m_nKind);
    if (spBanner.get() != 0)
    {
        m_strUrl = FUN_14016a600((const wchar_t*)FUN_14016e5a0(&spBanner)->m_str40, 0);
        m_strLinkType = (const wchar_t*)FUN_14016e5a0(&spBanner)->m_str30;
        m_strLink = (const wchar_t*)FUN_14016e5a0(&spBanner)->m_str38;
        RequestFile();
    }
}

// @0x1409fb210
bool CBannerUrlGetter::TakeReady()
{
    if (m_bReady == 0)
        return false;
    m_bReady = false;
    return true;
}

// @0x1409fb240
CString CBannerUrlGetter::GetPath() const
{
    return m_strPath;
}

// @0x1409fb290
bool CBannerUrlGetter::OpenLink()
{
    if (m_strLinkType == "link" && !m_strLink.IsEmpty())
    {
        FUN_1418fe1c0(m_strLink);
        return true;
    }
    return false;
}

// @0x1409fb300
void CBannerUrlGetter::OnNotify(NotifyObject* pNotify)
{
    NotifyUgcDownloadComplete* pDone = static_cast<NotifyUgcDownloadComplete*>(pNotify);
    if (pDone->m_nType == 0xcd)
    {
        if (pDone->m_strUrl == m_strUrl)
        {
            m_strPath = pDone->m_strPath;
            m_bReady = true;
            FUN_140939a10()->UnregisterNotify(L"NotifyUgcDownloadComplete", Delegate<void(NotifyObject*)>(this, &CBannerUrlGetter::OnNotify));
        }
    }
}

// @0x1409fb430
void CBannerUrlGetter::RequestFile()
{
    CString strCached = FUN_141029ed0(0xcd, m_strUrl);
    if (!strCached.IsEmpty())
    {
        m_strPath = strCached;
        m_bReady = true;
        return;
    }
    if (FUN_14052d220() != 0)
    {
        FUN_140939a10()->RegisterNotify(L"NotifyUgcDownloadComplete", Delegate<void(NotifyObject*)>(this, &CBannerUrlGetter::OnNotify));
        FUN_14052d220()->FUN_141885670(0xcd, m_strUrl);
    }
}

// ---- Delegate<void(NotifyObject*)> glue (the pair / forward / DelegateImpl COMDATs pair automatically) ----

// @0x1409fb800
template<> Delegate<void(NotifyObject*)>::~Delegate() { if (m_pImpl) delete m_pImpl; }

// @0x1409fb7e0
template<> Delegate<void(NotifyObject*)>::DelegateImplBase::DelegateImplBase() {}
// @0x1409fb880
template<> Delegate<void(NotifyObject*)>::DelegateImplBase::~DelegateImplBase() {}

// @0x1409fb8a0
AdBannerData* Unk_AdBannerPtr::get() const { return m_p; }

// @0x1409fb930
CAdBannerManagerCli* GetAdBannerManagerCli() { return DAT_143ab3920; }

MS2_EMIT_CRT_MEMMOVE_S();
