// cpopupprofileimageman.h - PLACEHOLDER for CPopupProfileImageMan (RTTI .?AVCPopupProfileImageMan@@, 0x98 bytes) and
// CPopupProfileImageData (RTTI .?AVCPopupProfileImageData@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<CPopupProfileImageMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It keeps the characters whose profile image popup is
// shown: m_pending (+0x38) and m_shown (+0x68) map a character id to a CPopupProfileImageData (the id and the tick it
// was shown); entries expire after a configured time. Methods recovered in ?\popupprofileimagedata.cpp.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"

class CPopupProfileImageData : public CPtred
{
public:
    CPopupProfileImageData();                               // 0x141697140
    virtual ~CPopupProfileImageData() = default;            //  0 0x141697eb0 (??_G 0x141698080)
    void FUN_141697180(unsigned __int64 nId);               // set the character id
    unsigned __int64 FUN_1416971a0();                       // the character id
    void SetTime(int nTime);                          // set the tick it was shown
    int GetTime();                                    // the tick it was shown
    int FUN_141697200(int nNow);                            // shown long enough ago to be dropped
    int FUN_141697260(int nNow, void* pA, void* pB);       // same, with the extra delay of the character's state
private:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_nId;                                 // +0x18
    int m_nTime;                                            // +0x20
    int m_pad_24;
};
MS2_CHECK_SIZE(CPopupProfileImageData, 0x28);

class CPopupProfileImageMan : public TSingleton<CPopupProfileImageMan>
{
public:
    typedef MS2Ptr<CPopupProfileImageData> DataPtr;
    typedef ATL::CRBMap<unsigned __int64, DataPtr> DataMap;

    CPopupProfileImageMan();                                // 0x141697320
    virtual ~CPopupProfileImageMan();                       //  0 0x1416973a0 (??_G 0x1416980c0)
    void FUN_141697430();                                   // drop the entries that are shown long enough
    int FUN_141697760(unsigned __int64 nId);                // register a character; 0 when it is not accepted
    void FUN_1416979e0(unsigned __int64 nId);               // forget a character and hide its popup
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x08
    DataMap m_pending;                                      // +0x38
    DataMap m_shown;                                        // +0x68
};
MS2_CHECK_SIZE(CPopupProfileImageMan, 0x98);
MS2_CHECK_OFFSET(CPopupProfileImageMan, m_pending, 0x38);
MS2_CHECK_OFFSET(CPopupProfileImageMan, m_shown, 0x68);
