// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). RemakeOptionContext: CPtred-derived context of an item
// option remake (class name from RTTI, vftable 0x142d15a38; ??_G in another unit). Layout from the ctor 0x140267390,
// copy ctor 0x140267460 and dtor 0x1402675b0 (hint: work/ext/v2525 RemakeOptionContext.h). Member names invented.
// MS2-UNIT: unit_140267390
// MS2-RANGE: 0x140267390-0x140267670 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/probability.h"

// The item option pointers (MS2Ptr<CItemOption>; the members are the exe's out-of-line copies in commonstruct_2.cpp).
class CItemOption;

// The +0x50 member is the remake packets' option list, std::vector<Unk_RemakeLockOpt> (ctor 0x14027d690, dtor
// 0x14027e3f0, operator= 0x14027eb30). C3 #13: was the Unk_RemakeOptionList50 view.
#include "ms2/placeholder/citemremakeoptionpacket.h"   // Unk_RemakeLockOpt
//
//
//
//
//

// The +0x68 member is a std::vector<MS2Ptr<Probability::LogContext> > (ctor 0x14027d750, dtor 0x14027e4b0, operator=
// 0x14027ebb0, clear 0x14028a690). C3 #13: the Unk_RemakeOptionList68 view that carried the last two is gone.
//
//
//
//
//
//
//
//

class RemakeOptionContext : public CPtred
{
public:
    RemakeOptionContext();
    RemakeOptionContext(const RemakeOptionContext& other);
    virtual ~RemakeOptionContext();

    int m_value18;                      // +0x18
    int m_value1c;                      // +0x1c
    __int64 m_value20;                  // +0x20
    MS2Ptr<CItemOption> m_option28;     // +0x28
    MS2Ptr<CItemOption> m_option38;     // +0x38
    int m_value48;                      // +0x48
    int m_value4c;                      // +0x4c
    std::vector<Unk_RemakeLockOpt> m_list50;    // +0x50 (C3 #13: was Unk_RemakeOptionList50)
    std::vector<MS2Ptr<Probability::LogContext> > m_list68;    // +0x68 (C3: was Unk_RemakeOptionList68)
};
MS2_CHECK_SIZE(RemakeOptionContext, 0x80);
MS2_CHECK_OFFSET(RemakeOptionContext, m_option28, 0x28);
MS2_CHECK_OFFSET(RemakeOptionContext, m_list68, 0x68);

// @0x140267390
RemakeOptionContext::RemakeOptionContext()
    : m_value18(0), m_value1c(0), m_value20(0), m_option28(0), m_option38(0), m_value48(1), m_value4c(1)
{
}

// @0x140267460
RemakeOptionContext::RemakeOptionContext(const RemakeOptionContext& other)
{
    m_value18 = other.m_value18;
    m_value1c = other.m_value1c;
    m_value20 = other.m_value20;
    m_option28 = other.m_option28;
    m_option38 = other.m_option38;
    m_value48 = other.m_value48;
    m_value4c = other.m_value4c;
    m_list50 = other.m_list50;
    m_list68 = other.m_list68;
}

// @0x1402675b0
RemakeOptionContext::~RemakeOptionContext()
{
    m_option28 = 0;
    m_option38 = 0;
    m_list68.clear();
}
