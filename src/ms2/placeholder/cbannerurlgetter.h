// cbannerurlgetter.h - PLACEHOLDER for CBannerUrlGetter (the name comes from its Delegate template argument), 0x38 bytes.
// NOT an original header. Fetches the file behind an ad banner's url through the UGC download manager and signals when
// the downloaded path is ready. The members are recovered in unnamed\unit_1409faff0.cpp (which still carries a
// unit-local copy of this declaration); the ctor 0x1409faf60 is in ?\avatarpc.cpp's range. Embedded by value in
// UIPcBangDialog (+0x220, kind 3).
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"

class NotifyObject;

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
