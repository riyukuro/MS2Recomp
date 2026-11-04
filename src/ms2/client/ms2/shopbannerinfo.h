// shopbannerinfo.h - ShopBannerInfo (RTTI .?AVShopBannerInfo@@, base CPtred; 0x40 bytes): one banner of the merat market
// (the limited-time offer dialog and the shop banner list). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13);
// header name assumed, member names invented. Ctor 0x141347b10, dtor 0x141347bb0 (deleting dtor 0x14134b040), vftable
// slot 1 = 0x141347dd0 (writes "imgpath" and a name into an AS object). The definitions live in the exe; only the
// layout is declared here so other units can use the type (it is the pointee of MS2Ptr<ShopBannerInfo>).
//
// FUN_141347c30 (unit_141347b10) fills the entry from a running ad banner (Unk_AdbPtr, adbannerdata.h): it
// copies the banner's wide strings into +0x30/+0x20/+0x28, stores the banner type, asks the image resolver
// (0x14102a0b0) for the image path and keeps it in +0x18 when it is not empty.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cadbannermanager.h"

class AScript;

class ShopBannerInfo : public CPtred
{
public:
    ShopBannerInfo();                                               // 0x141347b10
    virtual ~ShopBannerInfo();                                      //  0 0x141347bb0 (??_G 0x14134b040)
    virtual void vfunc_1(AScript* pObj);                            //  1 0x141347dd0 set "imgpath" (+0x18) and the name (+0x30)

    void FUN_141347c30(const Unk_AdbPtr& spBanner, int nType, CStringA strKey);   // 0x141347c30 fill from a banner (the callee destroys the key)

    CStringA m_strImgPath;                                          // +0x18 image path (empty: the banner has no image yet)
    CStringA m_strName2;                                            // +0x20
    CStringA m_strName3;                                            // +0x28
    CStringA m_strName;                                             // +0x30
    int m_nType;                                                    // +0x38
    int m_nKind;                                                    // +0x3c
};
MS2_CHECK_SIZE(ShopBannerInfo, 0x40);
MS2_CHECK_OFFSET(ShopBannerInfo, m_strImgPath, 0x18);
MS2_CHECK_OFFSET(ShopBannerInfo, m_strName2, 0x20);
MS2_CHECK_OFFSET(ShopBannerInfo, m_strName3, 0x28);
MS2_CHECK_OFFSET(ShopBannerInfo, m_strName, 0x30);
MS2_CHECK_OFFSET(ShopBannerInfo, m_nType, 0x38);
MS2_CHECK_OFFSET(ShopBannerInfo, m_nKind, 0x3c);
