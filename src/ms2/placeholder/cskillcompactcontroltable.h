// cskillcompactcontroltable.h - PLACEHOLDER for CSkillCompactControlTable (RTTI .?AVCSkillCompactControlTable@@, 0x10 bytes). NOT an original header.
// Bases: TSingleton<CSkillCompactControlTable> at +0x0, CValidData<CSkillCompactControlTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CSkillCompactControlTable : public TSingleton<CSkillCompactControlTable>,
                                  public CValidData<CSkillCompactControlTable>
{
public:
    CSkillCompactControlTable();                            // 0x140dca750
    virtual ~CSkillCompactControlTable();
    static int Load();                                      // 0x140dca800
};
MS2_CHECK_SIZE(CSkillCompactControlTable, 0x10);
