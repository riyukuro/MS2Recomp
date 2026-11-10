// ctaximanager.h - PLACEHOLDER for CTaxiManager (RTTI .?AVCTaxiManager@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<CTaxiManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Its one member is the cache of the shortest taxi route
// lengths between two stations (src/ms2/commonfiles/taximanager.cpp).
#pragma once

#include <map>
#include <utility>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CTaxiManager : public TSingleton<CTaxiManager>
{
public:
    CTaxiManager();                                         // 0x14085f650
    virtual ~CTaxiManager();                                // 0x14085f6a0

    bool FUN_14085f6e0(unsigned int nField);                // the field has a taxi (kind 1)
    bool FUN_14085f730(unsigned int nField);                // the field has a taxi stop (kind 1)
    long long GetTaxiFare(int nFrom, int nTo, short sOption); // the fare between two stations (breadth first search, cached)
    long long GetAirTaxiFare(short sOption);                 // the base fare
private:
    MS2_LAYOUT_FRIEND;
    std::map<std::pair<unsigned int, unsigned int>, int> m_mapRouteLength;  // +0x08 (lower station, higher station) -> hops
};
MS2_CHECK_SIZE(CTaxiManager, 0x18);
