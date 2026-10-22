// cadbannermanagercli.h - PLACEHOLDER for CAdBannerManagerCli (RTTI .?AVCAdBannerManagerCli@@, 0x70 bytes). NOT an original header.
// Bases: TSingleton<CAdBannerManagerCli> at +0x0 (the vftable), CAdBannerManager at +0x8 (constructed first).
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the banner lookups are in client\ms2\adbannermanagercli.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cadbannermanager.h"

class CInPacket;

class CAdBannerManagerCli : public CAdBannerManager, public TSingleton<CAdBannerManagerCli>
{
public:
    CAdBannerManagerCli();                                  // 0x14096b300
    virtual ~CAdBannerManagerCli();                         // 0x14096b350
    void FUN_14096b390();                                   // empty
    void OnBannerList(CInPacket& packet);                 // reads the banner list from the packet
    Unk_AdBannerPtr FUN_14096b3e0(int nType);                 // the running banner of the type (own slot, else any slot)
    int FUN_14096b540(int nType, Unk_AdBannerArray& out);    // all running banners of the type; true if any
    Unk_AdBannerPtr FUN_14096b5b0(int nType, const CStringW& strName);   // the running banner of the type with the name
    int FUN_14096b810(int nType, Unk_AdBannerArray& out, int nSlot);    // collects the banners of the slot; true if any
};
MS2_CHECK_SIZE(CAdBannerManagerCli, 0x70);
