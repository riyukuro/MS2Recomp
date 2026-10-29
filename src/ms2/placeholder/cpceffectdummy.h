// cpceffectdummy.h - PLACEHOLDER for CPCEffectDummy (RTTI .?AVCPCEffectDummy@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<CPCEffectDummy> at +0x0. The player-character effect-dummy table (Table/pcEffectDummy.xml): the
// <dummy> rows (CEffectDummy: attach node + transform) grouped by the gender attribute. Created by CGameApp::InitInstance
// (?\ms2.cpp); owning unit ?\pceffectdummy.cpp (0x1416841a0-0x1416889f0).
#pragma once

#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/effectdummy.h"

class CPCEffectDummy : public TSingleton<CPCEffectDummy>
{
public:
    CPCEffectDummy();                                       // 0x1416841a0
    virtual ~CPCEffectDummy();                              // 0x141686ff0 (sdd 0x1416875a0)

    bool Load();                                            // 0x1416841f0 Table/pcEffectDummy.xml
    bool LoadFile(const char* pszPath);                     // 0x141684290
    int Find(const char* pszName, CEffectDummy& kOut);      // 0x141684460 first row of that name, any gender
    size_t GetCount(int nGender);                           // 0x141684580
    int Get(int nGender, unsigned nIndex, CEffectDummy& kOut);    // 0x1416845c0
    void SetRows(int nGender, const std::vector<CEffectDummy>& rows);   // 0x141684660
    int Save(const char* pszPath);                          // 0x1416846a0

private:
    MS2_LAYOUT_FRIEND;
    std::map<int, std::vector<CEffectDummy> > m_dummies;    // +0x8 rows by gender
};
MS2_CHECK_SIZE(CPCEffectDummy, 0x18);
